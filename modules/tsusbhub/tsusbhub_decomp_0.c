
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



===== operator_delete @ 140001040 =====

/* void __cdecl operator delete(void * __ptr64) */

void __cdecl operator_delete(void *param_1)

{
  if (param_1 != (void *)0x0) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== ~CUsbHub @ 140001064 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl CUsbHub::~CUsbHub(void) __ptr64 */

void __thiscall CUsbHub::~CUsbHub(CUsbHub *this)

{
  int iVar1;
  
  if (*(longlong *)(this + 0x10) != 0) {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
    if (iVar1 != -0x3ffffee0) {
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,*(undefined8 *)(this + 0x10));
      *(undefined8 *)(this + 0x10) = 0;
    }
  }
  McGenEventUnregister_EtwUnregister();
  return;
}



===== CreateInstance @ 1400010d0 =====

/* public: static long __cdecl CUsbHub::CreateInstance(struct WDFDEVICE__ * __ptr64,void *
   __ptr64,class CUsbHub * __ptr64 * __ptr64) */

long __cdecl CUsbHub::CreateInstance(WDFDEVICE__ *param_1,void *param_2,CUsbHub **param_3)

{
  long lVar1;
  
  if (param_2 == (void *)0x0) {
    lVar1 = -0x3fffffe9;
  }
  else {
    *(undefined8 *)param_2 = 0;
    *(undefined8 *)((longlong)param_2 + 8) = 0;
    *(undefined8 *)((longlong)param_2 + 0x10) = 0;
    *(undefined8 *)((longlong)param_2 + 0x18) = 0;
    lVar1 = Initialize(param_2,param_1);
    if (lVar1 < 0) {
      ~CUsbHub(param_2);
    }
    else {
      *param_3 = param_2;
      lVar1 = 0;
    }
  }
  return lVar1;
}



===== DevicePlugIn @ 140001148 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl CUsbHub::DevicePlugIn(struct WDFCHILDLIST__ * __ptr64,unsigned short *
   __ptr64,unsigned __int64,unsigned short * __ptr64,unsigned __int64,unsigned short *
   __ptr64,unsigned __int64,unsigned long,unsigned long,struct _GUID const & __ptr64,struct
   _USB_DEVICE_CAPABILITIES * __ptr64,struct ITsUsbDevice * __ptr64) __ptr64 */

long __thiscall
CUsbHub::DevicePlugIn
          (CUsbHub *this,WDFCHILDLIST__ *param_1,ushort *param_2,__uint64 param_3,ushort *param_4,
          __uint64 param_5,ushort *param_6,__uint64 param_7,ulong param_8,ulong param_9,
          _GUID *param_10,_USB_DEVICE_CAPABILITIES *param_11,ITsUsbDevice *param_12)

{
  int iVar1;
  long lVar2;
  undefined1 auStack_108 [48];
  undefined8 local_d8;
  WDFCHILDLIST__ *local_d0;
  undefined4 local_c8;
  ulong local_c4;
  ulong local_c0;
  ITsUsbDevice *local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined8 local_90;
  undefined4 local_88;
  __uint64 local_80;
  ushort *local_78;
  __uint64 local_70;
  ushort *local_68;
  __uint64 local_60;
  ushort *local_58;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_108;
  local_d0 = param_1;
  local_d8 = (**(code **)(WdfFunctions_01015 + 8))(WdfDriverGlobals);
  memset(&local_c8,0,0x78);
  local_b0 = *(undefined8 *)param_10;
  uStack_a8 = *(undefined8 *)(param_10 + 8);
  local_90 = *(undefined8 *)(param_11 + 0x10);
  local_70 = param_5;
  local_60 = param_7;
  local_88 = *(undefined4 *)(param_11 + 0x18);
  local_c4 = param_8;
  local_c0 = param_9;
  local_a0 = *(undefined4 *)param_11;
  uStack_9c = *(undefined4 *)(param_11 + 4);
  uStack_98 = *(undefined4 *)(param_11 + 8);
  uStack_94 = *(undefined4 *)(param_11 + 0xc);
  local_c8 = 0x78;
  local_b8 = param_12;
  local_68 = param_4;
  local_58 = param_6;
  local_80 = param_3;
  local_78 = param_2;
  (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,local_d8);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x48))(WdfDriverGlobals,local_d0,&local_c8,0);
  (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,local_d8);
  lVar2 = -0x3ffffff3;
  if (iVar1 != 0x40000000) {
    lVar2 = 0;
  }
  return lVar2;
}



===== DeviceUnplug @ 1400012cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl CUsbHub::DeviceUnplug(struct WDFCHILDLIST__ * __ptr64,struct ITsUsbDevice *
   __ptr64) __ptr64 */

long __thiscall CUsbHub::DeviceUnplug(CUsbHub *this,WDFCHILDLIST__ *param_1,ITsUsbDevice *param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined1 auStack_b8 [32];
  undefined4 local_98 [4];
  ITsUsbDevice *local_88;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  uVar3 = (**(code **)(WdfFunctions_01015 + 8))(WdfDriverGlobals);
  memset(local_98,0,0x78);
  local_98[0] = 0x78;
  local_88 = param_2;
  (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,uVar3);
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x50))(WdfDriverGlobals,param_1,local_98);
  (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,uVar3);
  lVar2 = -0x3ffffff3;
  if (iVar1 != -0x3ffffff2) {
    lVar2 = 0;
  }
  return lVar2;
}



===== EvtDeviceFileCreate @ 1400013c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CUsbHub::EvtDeviceFileCreate(struct WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall CUsbHub::EvtDeviceFileCreate(CUsbHub *this,WDFREQUEST__ *param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = IsCallerUsbRedirectionService();
  uVar2 = 0;
  if (iVar1 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_9a47c07e199d34a8426cfa10808df3ca_Traceguids);
    }
    uVar2 = 0xc0000022;
  }
  else if (*(int *)(this + 0x1c) == 0) {
    *(undefined4 *)(this + 0x1c) = 1;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_9a47c07e199d34a8426cfa10808df3ca_Traceguids);
    }
    uVar2 = 0x80000011;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,uVar2);
  return;
}



===== EvtFileCleanup @ 140001488 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CUsbHub::EvtFileCleanup(void) __ptr64 */

void __thiscall CUsbHub::EvtFileCleanup(CUsbHub *this)

{
  uint uVar1;
  undefined8 uVar2;
  CSession *this_00;
  ulonglong uVar3;
  
  *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)this);
  if (uVar1 != 0) {
    uVar3 = (ulonglong)uVar1;
    do {
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x98))(WdfDriverGlobals,*(undefined8 *)this);
      (**(code **)(WdfFunctions_01015 + 0x80))(WdfDriverGlobals,*(undefined8 *)this,uVar2);
      this_00 = (CSession *)
                (**(code **)(WdfFunctions_01015 + 0x650))
                          (WdfDriverGlobals,uVar2,PTR__WDF_CSession_TYPE_INFO_14001d018);
      CSession::CloseChannel(this_00);
      (**(code **)(*(longlong *)this_00 + 0x10))(this_00);
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return;
}



===== EvtIoDeviceControl @ 140001560 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CUsbHub::EvtIoDeviceControl(struct WDFREQUEST__ * __ptr64,unsigned long)
   __ptr64 */

void __thiscall CUsbHub::EvtIoDeviceControl(CUsbHub *this,WDFREQUEST__ *param_1,ulong param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  CSession *this_00;
  undefined2 uVar4;
  uint uVar5;
  ulonglong local_res20;
  ulong *local_28 [2];
  
  local_res20 = 0;
  if (param_2 == 0x86000400) {
    local_28[0] = (ulong *)0x0;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))
                      (WdfDriverGlobals,param_1,0xc,local_28,&local_res20);
    if ((iVar2 < 0) || (0xffffffff < local_res20)) {
      iVar2 = -0x3ffffff3;
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000184b;
      uVar4 = 0xf;
      iVar2 = -0x3ffffff3;
    }
    else {
      iVar2 = EvtIoDeviceControl_SessionConnected(this,local_28[0][1],*local_28[0],local_28[0][2]);
      if (((-1 < iVar2) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000184b;
      uVar4 = 0x10;
    }
  }
  else if (param_2 == 0x86000404) {
    local_28[0] = (ulong *)0x0;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))
                      (WdfDriverGlobals,param_1,8,local_28,&local_res20);
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000184b;
      uVar4 = 0x11;
    }
    else {
      iVar2 = EvtIoDeviceControl_SessionDisconnected(this,local_28[0][1],*local_28[0]);
      if (((-1 < iVar2) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000184b;
      uVar4 = 0x12;
    }
  }
  else {
    if (param_2 != 0x86000408) {
      if (param_2 == 0x8600040c) {
        EvtIoDeviceControl_GetRequest(this,param_1);
        return;
      }
      iVar2 = -0x3ffffff3;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_9a47c07e199d34a8426cfa10808df3ca_Traceguids,param_2);
      }
      goto LAB_14000184b;
    }
    local_28[0] = (ulong *)0x0;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))
                      (WdfDriverGlobals,param_1,0x10,local_28,&local_res20);
    if (-1 < iVar2) {
      uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)this);
      for (uVar5 = 0; uVar5 < uVar1; uVar5 = uVar5 + 1) {
        uVar3 = (**(code **)(WdfFunctions_01015 + 0x90))(WdfDriverGlobals,*(undefined8 *)this,uVar5)
        ;
        this_00 = (CSession *)
                  (**(code **)(WdfFunctions_01015 + 0x650))
                            (WdfDriverGlobals,uVar3,PTR__WDF_CSession_TYPE_INFO_14001d018);
        if ((*(ulong *)(this_00 + 0x1c) == local_28[0][1]) &&
           (*(ulong *)(this_00 + 0x20) == *local_28[0])) {
          CSession::EvtIoDeviceControl_NewDynamicVC(this_00,*(void **)(local_28[0] + 2));
          break;
        }
      }
      iVar2 = 0;
      goto LAB_14000184b;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000184b;
    uVar4 = 0x13;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_9a47c07e199d34a8426cfa10808df3ca_Traceguids,iVar2);
LAB_14000184b:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,iVar2);
  return;
}



===== EvtIoStop @ 140001888 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CUsbHub::EvtIoStop(struct WDFREQUEST__ * __ptr64,unsigned long) __ptr64 */

void __thiscall CUsbHub::EvtIoStop(CUsbHub *this,WDFREQUEST__ *param_1,ulong param_2)

{
  int iVar1;
  
  if (((param_2 >> 0x1c & 1) == 0) ||
     (iVar1 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals), iVar1 != -0x3ffffee0)) {
    if ((param_2 & 1) == 0) {
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc0000120);
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0x8e0))(WdfDriverGlobals,param_1,1);
    }
  }
  if (*(WDFREQUEST__ **)(this + 0x10) == param_1) {
    *(undefined8 *)(this + 0x10) = 0;
  }
  return;
}



===== Initialize @ 14000192c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl CUsbHub::Initialize(struct WDFDEVICE__ * __ptr64) __ptr64 */

long __thiscall CUsbHub::Initialize(CUsbHub *this,WDFDEVICE__ *param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 auStack_108 [32];
  undefined8 *local_e8;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  WDFDEVICE__ *local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined1 local_8b;
  code *local_70;
  code *local_60;
  undefined4 local_48;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_108;
  local_d8 = 0;
  McGenEventRegister_EtwRegister();
  *(WDFDEVICE__ **)(this + 8) = param_1;
  memset(&local_98,0,0x60);
  local_48 = 0xffffffff;
  local_60 = BdEvtIoStop;
  local_e8 = &local_d8;
  local_98 = 0x60;
  local_70 = BdEvtIoDeviceControl;
  local_90 = 2;
  local_8b = 1;
  local_94 = 2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,param_1,&local_98,0);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar1;
    }
    uVar2 = 10;
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x268))
                      (WdfDriverGlobals,param_1,&GUID_DEVINTERFACE_TSUSBHUB,0);
    if (iVar1 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return iVar1;
      }
      uVar2 = 0xb;
    }
    else {
      local_c0 = 0;
      local_a0 = 0;
      uStack_c8 = 0;
      local_d0 = 0x38;
      uStack_a8 = 0;
      uStack_b8 = 0x100000001;
      local_b0 = param_1;
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,&local_d0,this);
      if (-1 < iVar1) {
        local_24 = 0;
        local_38 = 0x9d7debbc;
        uStack_34 = 0x11d1c85d;
        uStack_30 = 0x6000b49e;
        uStack_2c = 0x9aa1c308;
        local_28 = 0xf;
        (**(code **)(WdfFunctions_01015 + 0x2a8))(WdfDriverGlobals,param_1,&local_38);
        return 0;
      }
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return iVar1;
      }
      uVar2 = 0xc;
    }
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_9a47c07e199d34a8426cfa10808df3ca_Traceguids,iVar1);
  return iVar1;
}



===== ReferenceSession @ 140001b44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void * __ptr64 __cdecl CUsbHub::ReferenceSession(unsigned long) __ptr64 */

void * __thiscall CUsbHub::ReferenceSession(CUsbHub *this,ulong param_1)

{
  uint uVar1;
  void *pvVar2;
  longlong *plVar3;
  uint uVar4;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)this);
  uVar4 = 0;
  while( true ) {
    if (uVar1 <= uVar4) {
      return (void *)0x0;
    }
    pvVar2 = (void *)(**(code **)(WdfFunctions_01015 + 0x90))
                               (WdfDriverGlobals,*(undefined8 *)this,uVar4);
    plVar3 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,pvVar2,PTR__WDF_CSession_TYPE_INFO_14001d018);
    if (*(ulong *)((longlong)plVar3 + 0x1c) == param_1) break;
    uVar4 = uVar4 + 1;
  }
  (**(code **)(*plVar3 + 8))(plVar3);
  return pvVar2;
}



===== RequestUpcall @ 140001c0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CUsbHub::RequestUpcall(unsigned char) __ptr64 */

void __thiscall CUsbHub::RequestUpcall(CUsbHub *this,uchar param_1)

{
  WDFREQUEST__ *pWVar1;
  int iVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
            &WPP_9a47c07e199d34a8426cfa10808df3ca_Traceguids);
  }
  if (param_1 == '\0') {
    (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,*(undefined8 *)(this + 8));
  }
  if (*(longlong *)(this + 0x10) != 0) {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
    if (iVar2 != -0x3ffffee0) {
      pWVar1 = *(WDFREQUEST__ **)(this + 0x10);
      *(undefined8 *)(this + 0x10) = 0;
      EvtIoDeviceControl_GetRequest(this,pWVar1);
    }
  }
  if (param_1 == '\0') {
    (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,*(undefined8 *)(this + 8));
  }
  return;
}



===== McGenControlCallbackV2 @ 140001ce0 =====

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



===== McGenEventRegister_EtwRegister @ 140001df0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (USB_Redirector_Event_Provider_Context == 0) {
    EtwRegister(&USB_Redirector_Event_Provider,McGenControlCallbackV2,
                &USB_Redirector_Event_Provider_Context,&USB_Redirector_Event_Provider_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140001e30 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (USB_Redirector_Event_Provider_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    USB_Redirector_Event_Provider_Context = 0;
  }
  return uVar1;
}



===== WPP_SF_ @ 140001e64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 140001e90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== CompleteGetRequest_NewDynamicVC @ 140001ed4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl CUsbHub::CompleteGetRequest_NewDynamicVC(struct WDFREQUEST__ *
   __ptr64,unsigned long,unsigned long) __ptr64 */

void __thiscall
CUsbHub::CompleteGetRequest_NewDynamicVC
          (CUsbHub *this,WDFREQUEST__ *param_1,ulong param_2,ulong param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 *local_res8;
  undefined8 local_28 [2];
  
  local_res8 = (undefined4 *)0x0;
  local_28[0] = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_748d4183247b3ea7b14cdef3a04e2be8_Traceguids);
  }
  uVar2 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_1,0xc,&local_res8,local_28);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_748d4183247b3ea7b14cdef3a04e2be8_Traceguids,iVar1);
    }
  }
  else {
    *local_res8 = 0;
    uVar2 = 0xc;
    iVar1 = 0;
    local_res8[1] = param_2;
    local_res8[2] = param_3;
  }
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,iVar1,uVar2);
  return;
}



===== EvtIoDeviceControl_GetRequest @ 140001ff8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl CUsbHub::EvtIoDeviceControl_GetRequest(struct WDFREQUEST__ * __ptr64)
   __ptr64 */

void __thiscall CUsbHub::EvtIoDeviceControl_GetRequest(CUsbHub *this,WDFREQUEST__ *param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_748d4183247b3ea7b14cdef3a04e2be8_Traceguids);
  }
  bVar3 = false;
  uVar4 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals);
  uVar7 = 0;
  do {
    if (uVar4 <= uVar7) {
LAB_1400020e8:
      *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
      if (!bVar3) {
        if (*(longlong *)(this + 0x10) == 0) {
          *(WDFREQUEST__ **)(this + 0x10) = param_1;
          (**(code **)(WdfFunctions_01015 + 0x7f8))
                    (WdfDriverGlobals,param_1,BdEvtRequestCancel_GetRequest);
        }
        else {
          (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,0xc0000184,0);
        }
      }
      return;
    }
    uVar1 = *(uint *)(this + 0x18) % uVar4 + uVar7;
    uVar2 = uVar1 - uVar4;
    if (uVar1 < uVar4) {
      uVar2 = uVar1;
    }
    uVar5 = (**(code **)(WdfFunctions_01015 + 0x90))(WdfDriverGlobals,*(undefined8 *)this,uVar2);
    lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,uVar5,PTR__WDF_CSession_TYPE_INFO_14001d018);
    if (*(uint *)(lVar6 + 0x48) < *(uint *)(lVar6 + 0x40)) {
      LOCK();
      *(int *)(lVar6 + 0x44) = *(int *)(lVar6 + 0x44) + 1;
      UNLOCK();
      CompleteGetRequest_NewDynamicVC
                ((CUsbHub *)(ulonglong)*(uint *)(lVar6 + 0x48),param_1,*(ulong *)(lVar6 + 0x1c),
                 *(ulong *)(lVar6 + 0x20));
      bVar3 = true;
      goto LAB_1400020e8;
    }
    uVar7 = uVar7 + 1;
  } while( true );
}



===== EvtIoDeviceControl_SessionConnected @ 140002168 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CUsbHub::EvtIoDeviceControl_SessionConnected(unsigned long,unsigned
   long,unsigned long) __ptr64 */

long __thiscall
CUsbHub::EvtIoDeviceControl_SessionConnected
          (CUsbHub *this,ulong param_1,ulong param_2,ulong param_3)

{
  uint uVar1;
  long lVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  void *pvVar6;
  void *local_res8;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (4 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_748d4183247b3ea7b14cdef3a04e2be8_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_748d4183247b3ea7b14cdef3a04e2be8_Traceguids,param_1,(char)param_2);
    }
  }
  local_res8 = (void *)0x0;
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)this);
  uVar5 = 0;
  if (uVar1 != 0) {
    do {
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x90))(WdfDriverGlobals,*(undefined8 *)this,uVar5);
      lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,lVar3,PTR__WDF_CSession_TYPE_INFO_14001d018);
      if (*(ulong *)(lVar4 + 0x1c) == param_1) break;
      lVar3 = 0;
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
    if (lVar3 != 0) {
      return 0;
    }
  }
  lVar2 = CSession::CreateInstance(*(WDFDEVICE__ **)(this + 8),param_1,param_2,param_3,&local_res8);
  pvVar6 = local_res8;
  if (lVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
               &WPP_748d4183247b3ea7b14cdef3a04e2be8_Traceguids,lVar2);
    }
    pvVar6 = local_res8;
  }
  else {
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x78))
                      (WdfDriverGlobals,*(undefined8 *)this,local_res8);
    if (lVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_748d4183247b3ea7b14cdef3a04e2be8_Traceguids,lVar2);
      }
    }
    else {
      RequestUpcall(this,'\x01');
      pvVar6 = (void *)0x0;
      lVar2 = 0;
    }
  }
  if (pvVar6 != (void *)0x0) {
    operator_delete(pvVar6);
  }
  return lVar2;
}



===== EvtIoDeviceControl_SessionDisconnected @ 140002360 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CUsbHub::EvtIoDeviceControl_SessionDisconnected(unsigned long,unsigned
   long) __ptr64 */

long __thiscall
CUsbHub::EvtIoDeviceControl_SessionDisconnected(CUsbHub *this,ulong param_1,ulong param_2)

{
  void *pvVar1;
  longlong *plVar2;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (4 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_748d4183247b3ea7b14cdef3a04e2be8_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_748d4183247b3ea7b14cdef3a04e2be8_Traceguids,param_1,(char)param_2);
    }
  }
  pvVar1 = ReferenceSession(this,param_1);
  if (pvVar1 != (void *)0x0) {
    plVar2 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,pvVar1,PTR__WDF_CSession_TYPE_INFO_14001d018);
    (**(code **)(WdfFunctions_01015 + 0x80))(WdfDriverGlobals,*(undefined8 *)this,pvVar1);
    (**(code **)(*plVar2 + 0x10))(plVar2);
    (**(code **)(*plVar2 + 0x10))(plVar2);
  }
  return 0;
}



===== EvtRequestCancel_GetRequest @ 140002470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CUsbHub::EvtRequestCancel_GetRequest(struct WDFREQUEST__ * __ptr64) __ptr64
    */

void __thiscall CUsbHub::EvtRequestCancel_GetRequest(CUsbHub *this,WDFREQUEST__ *param_1)

{
  if (*(longlong *)(this + 0x10) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))
              (WdfDriverGlobals,*(longlong *)(this + 0x10),0xc0000120);
    *(undefined8 *)(this + 0x10) = 0;
  }
  return;
}



===== WPP_SF_DD @ 1400024b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== ~CDeviceSink @ 140002504 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl CDeviceSink::~CDeviceSink(void) __ptr64 */

void __thiscall CDeviceSink::~CDeviceSink(CDeviceSink *this)

{
  *(undefined ***)this = &_vftable__for__ITsUsbDeviceSink__;
  *(undefined ***)(this + 8) = &_vftable__for__ITsChannelNotification__;
  *(undefined ***)(this + 0x10) = &_vftable__for__IRIMChannelCallback__;
  if (*(longlong **)(this + 0x30) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(this + 0x30) + 0x10))();
    *(undefined8 *)(this + 0x30) = 0;
  }
  if (*(longlong **)(this + 0x38) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(this + 0x38) + 0x10))();
    *(undefined8 *)(this + 0x38) = 0;
  }
  if (*(longlong **)(this + 0x28) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(this + 0x28) + 0x10))();
  }
  return;
}



===== ~CSession @ 140002584 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl CSession::~CSession(void) __ptr64 */

void __thiscall CSession::~CSession(CSession *this)

{
  *(undefined ***)this = &_vftable__for__ITsUsbDeviceSink__;
  *(undefined ***)(this + 8) = &_vftable__for__ITsChannelNotification__;
  *(undefined ***)(this + 0x10) = &_vftable__for__IRIMChannelCallback__;
  if (((*(uint *)(this + 0x40) < *(uint *)(this + 0x4c)) &&
      ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,*(uint *)(this + 0x4c),
              (char)*(uint *)(this + 0x40));
  }
  if (*(longlong **)(this + 0x28) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(this + 0x28) + 0x10))();
    *(undefined8 *)(this + 0x28) = 0;
  }
  return;
}



===== AddDevice @ 140002620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual long __cdecl CDeviceSink::AddDevice(struct ITsUsbDevice * __ptr64,unsigned
   long,unsigned short * __ptr64,unsigned long,unsigned short * __ptr64,unsigned long,unsigned short
   * __ptr64,unsigned long,unsigned short * __ptr64,struct _USB_DEVICE_CAPABILITIES * __ptr64)
   __ptr64 */

long __thiscall
CDeviceSink::AddDevice
          (CDeviceSink *this,ITsUsbDevice *param_1,ulong param_2,ushort *param_3,ulong param_4,
          ushort *param_5,ulong param_6,ushort *param_7,ulong param_8,ushort *param_9,
          _USB_DEVICE_CAPABILITIES *param_10)

{
  ushort *puVar1;
  ushort *puVar2;
  wchar_t *pwVar3;
  uchar uVar4;
  long lVar5;
  undefined2 uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 auStackY_298 [32];
  ushort ***in_stack_fffffffffffffd88;
  ulong local_240 [2];
  ushort *local_238;
  __uint64 local_230;
  ushort *local_228;
  __uint64 local_220;
  wchar_t *local_218;
  _USB_DEVICE_CAPABILITIES *local_210;
  ulonglong local_208;
  ulonglong local_200;
  undefined8 local_1f8;
  undefined8 uStack_1f0;
  undefined8 local_1e8;
  undefined8 uStack_1e0;
  wchar_t local_1d8 [200];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_298;
  uVar8 = (ulonglong)param_6;
  local_240[0] = param_4;
  local_238 = param_5;
  local_228 = param_7;
  local_210 = param_10;
  local_1f8 = 0;
  uStack_1f0 = 0;
  local_240[1] = 0;
  local_1e8 = 0;
  uStack_1e0 = 0;
  local_230 = 0;
  local_220 = 0;
  local_218 = (wchar_t *)param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
            &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids);
  }
  uVar7 = *(uint *)param_10;
  if (uVar7 == 0x1c) {
    uVar7 = *(uint *)(param_10 + 0x18);
    if ((8 < uVar7 - 1) && (uVar7 < 0x201)) {
      if (this[0x40] == (CDeviceSink)0x0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002c36;
        uVar6 = 0x2f;
      }
      else {
        if (param_1 != (ITsUsbDevice *)0x0) {
          local_200 = (ulonglong)local_240[0];
          if (local_200 * 2 < 0x100000000) {
            local_208 = uVar8;
            if (0xffffffff < uVar8 * 2) {
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002c36;
              uVar6 = 0x32;
              goto LAB_140002be6;
            }
            lVar5 = ValidateMultiStrings
                              (local_238,local_200 * 2 & 0xffffffff,local_240 + 1,&local_230,
                               in_stack_fffffffffffffd88);
            if (lVar5 < 0) {
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002c36;
              uVar6 = 0x33;
            }
            else {
              local_238[local_240[0] - 1] = 0;
              lVar5 = ValidateMultiStrings
                                (local_228,uVar8 * 2 & 0xffffffff,local_240 + 1,&local_230,
                                 in_stack_fffffffffffffd88);
              pwVar3 = local_218;
              puVar2 = local_228;
              if (-1 < lVar5) {
                local_228[param_6 - 1] = 0;
                if (param_2 == 0) {
                  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002c36;
                  uVar6 = 0x35;
                }
                else if (local_218[param_2 - 1] == L'\0') {
                  if (param_8 == 0) {
                    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002c36;
                    uVar6 = 0x37;
                  }
                  else {
                    if (param_9[param_8 - 1] == 0) {
                      param_9[param_8 - 1] = 0;
                      RtlInitUnicodeString(&local_1f8,param_9);
                      lVar5 = RtlGUIDFromString(&local_1f8,&local_1e8);
                      if (-1 < lVar5) {
                        local_240[0] = 0;
                        uVar4 = IsAnyStringInMultiSzOnStringTable
                                          (puVar2,(ushort **)
                                                  &CUsbDeviceDisallowList::m_UsbDeviceDisallowList,3
                                           ,local_240);
                        puVar1 = local_238;
                        if (uVar4 == '\0') {
                          uVar4 = IsAnyStringInMultiSzOnStringTable
                                            (local_238,
                                             (ushort **)
                                             &CUsbDeviceDisallowList::m_UsbDeviceDisallowList,3,
                                             local_240);
                          if (uVar4 == '\0') {
                            LOCK();
                            *(int *)(*(longlong *)(this + 0x28) + 0x58) =
                                 *(int *)(*(longlong *)(this + 0x28) + 0x58) + 1;
                            UNLOCK();
                            lVar5 = RtlStringCchPrintfW((ushort *)local_1d8,200,
                                                        (ushort *)L"tsusb-session%u-%u&%u&%s",
                                                        (ulonglong)
                                                        *(uint *)(*(longlong *)(this + 0x28) + 0x20)
                                                       );
                            if ((lVar5 < 0) ||
                               (lVar5 = RtlStringCchLengthW((ushort *)local_1d8,200,&local_220),
                               lVar5 < 0)) {
                              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                                WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3d,
                                         &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,pwVar3);
                              }
                              lVar5 = -0x3ffffff0;
                            }
                            else {
                              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                                 (4 < (byte)WPP_GLOBAL_Control[0x29])) {
                                WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                                         &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,local_1d8)
                                ;
                              }
                              lVar5 = CSession::DevicePlugIn
                                                (*(CSession **)(this + 0x28),(ushort *)local_1d8,
                                                 (ulonglong)((int)local_220 + 1),puVar1,local_200,
                                                 puVar2,local_208,(_GUID *)&local_1e8,local_210,
                                                 param_1);
                              if (-1 < lVar5) {
                                *(ITsUsbDevice **)(this + 0x30) = param_1;
                                (**(code **)(*(longlong *)param_1 + 8))(param_1);
                                return 0x10000000;
                              }
                            }
                            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,
                                       &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,lVar5);
                            }
                            goto LAB_140002c36;
                          }
                          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                             ((byte)WPP_GLOBAL_Control[0x29] < 5)) goto LAB_140002c36;
                          uVar6 = 0x3b;
                        }
                        else {
                          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                             ((byte)WPP_GLOBAL_Control[0x29] < 5)) goto LAB_140002c36;
                          uVar6 = 0x3a;
                        }
                        WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                                 &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,
                                 (wchar_t *)
                                 (&CUsbDeviceDisallowList::m_UsbDeviceDisallowList)[local_240[0]]);
                        goto LAB_140002c36;
                      }
                      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002c36;
                      uVar6 = 0x39;
                      goto LAB_140002815;
                    }
                    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002c36;
                    uVar6 = 0x38;
                  }
                }
                else {
                  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002c36;
                  uVar6 = 0x36;
                }
                goto LAB_140002773;
              }
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002c36;
              uVar6 = 0x34;
            }
          }
          else {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002c36;
            uVar6 = 0x31;
LAB_140002be6:
            lVar5 = -0x3fffff6b;
          }
LAB_140002815:
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                   &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,lVar5);
          goto LAB_140002c36;
        }
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002c36;
        uVar6 = 0x30;
      }
LAB_140002773:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
              &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids);
      goto LAB_140002c36;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002c36;
    uVar6 = 0x2e;
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002c36;
    uVar6 = 0x2d;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
           &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,uVar7);
LAB_140002c36:
  (**(code **)(**(longlong **)(this + 0x38) + 0x20))();
  return 0;
}



===== Initialize @ 140002c80 =====

/* public: virtual long __cdecl CRIMStream::Initialize(void) __ptr64 */

long __thiscall CRIMStream::Initialize(CRIMStream *this)

{
  return 0;
}



===== AddNewVirtualChannel @ 140002c90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CSession::AddNewVirtualChannel(void) __ptr64 */

long __thiscall CSession::AddNewVirtualChannel(CSession *this)

{
  undefined8 uVar1;
  CUsbHub *this_00;
  long lVar2;
  
  lVar2 = 0;
  if (this[0x30] == (CSession)0x0) {
    lVar2 = -0x7ff8ffa9;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
              &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids);
    }
  }
  else {
    uVar1 = (**(code **)(WdfFunctions_01015 + 8))(WdfDriverGlobals,*(undefined8 *)(this + 0x60));
    this_00 = (CUsbHub *)
              (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,uVar1,PTR__WDF_CUsbHub_TYPE_INFO_14001d068);
    LOCK();
    *(int *)(this + 0x40) = *(int *)(this + 0x40) + 1;
    UNLOCK();
    CUsbHub::RequestUpcall(this_00,'\0');
  }
  return lVar2;
}



===== AddRef @ 140002d40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual unsigned long __cdecl CDeviceSink::AddRef(void) __ptr64 */

ulong __thiscall CDeviceSink::AddRef(CDeviceSink *this)

{
  CDeviceSink *pCVar1;
  int iVar2;
  
  LOCK();
  pCVar1 = this + 0x18;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + 1;
  UNLOCK();
  if (iVar2 + 1U == 1) {
    (**(code **)(WdfFunctions_01015 + 0x668))
              (WdfDriverGlobals,*(undefined8 *)(this + 0x20),0,0x140,
               "clientcore\\termsrv\\devices\\urbdr\\busdriver\\CSession.h");
  }
  return iVar2 + 1U;
}



===== AddRef`adjustor{8}' @ 140002da0 =====

/* [thunk]:public: virtual unsigned long __cdecl CDeviceSink::AddRef`adjustor{8}' (void) __ptr64 */

ulong __thiscall CDeviceSink::AddRef_adjustor_8__(CDeviceSink *this)

{
  ulong uVar1;
  
  uVar1 = AddRef(this + -8);
  return uVar1;
}



===== AddRef`adjustor{16}' @ 140002db0 =====

/* [thunk]:public: virtual unsigned long __cdecl CDeviceSink::AddRef`adjustor{16}' (void) __ptr64 */

ulong __thiscall CDeviceSink::AddRef_adjustor_16__(CDeviceSink *this)

{
  ulong uVar1;
  
  uVar1 = AddRef(this + -0x10);
  return uVar1;
}



===== AddRef @ 140002dc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual unsigned long __cdecl CSession::AddRef(void) __ptr64 */

ulong __thiscall CSession::AddRef(CSession *this)

{
  CSession *pCVar1;
  int iVar2;
  ulong uVar3;
  
  LOCK();
  pCVar1 = this + 0x18;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + 1;
  UNLOCK();
  uVar3 = iVar2 + 1;
  if (uVar3 == 1) {
    (**(code **)(WdfFunctions_01015 + 0x668))
              (WdfDriverGlobals,*(undefined8 *)(this + 0x38),0,iVar2 + 0x1d,
               "clientcore\\termsrv\\devices\\urbdr\\busdriver\\CSession.h");
  }
  return uVar3;
}



===== AddRef`adjustor{8}' @ 140002e20 =====

/* [thunk]:public: virtual unsigned long __cdecl CSession::AddRef`adjustor{8}' (void) __ptr64 */

ulong __thiscall CSession::AddRef_adjustor_8__(CSession *this)

{
  ulong uVar1;
  
  uVar1 = AddRef(this + -8);
  return uVar1;
}



===== AddRef`adjustor{16}' @ 140002e30 =====

/* [thunk]:public: virtual unsigned long __cdecl CSession::AddRef`adjustor{16}' (void) __ptr64 */

ulong __thiscall CSession::AddRef_adjustor_16__(CSession *this)

{
  ulong uVar1;
  
  uVar1 = AddRef(this + -0x10);
  return uVar1;
}



===== ChannelCreated @ 140002e40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CDeviceSink::ChannelCreated(struct _URBDR_VERSION * __ptr64) __ptr64
    */

long __thiscall CDeviceSink::ChannelCreated(CDeviceSink *this,_URBDR_VERSION *param_1)

{
  longlong lVar1;
  undefined2 uVar2;
  long lVar3;
  undefined *in_R8;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_R8 = &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
            &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids);
  }
  if (this[0x39] == (CDeviceSink)0x0) {
    lVar3 = -0x7ff8ffeb;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar2 = 0x2a;
LAB_140002ee5:
      in_R8 = &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
              &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids);
    }
  }
  else {
    in_R8 = (undefined *)0xc;
    lVar1 = RtlCompareMemory(param_1,&g_UrbDrVersion);
    if (lVar1 == 0xc) {
      lVar3 = 0;
      this[0x38] = (CDeviceSink)0x1;
      goto LAB_140002f12;
    }
    lVar3 = -0x7ff8fae6;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar2 = 0x2b;
      goto LAB_140002ee5;
    }
  }
  param_1 = *(_URBDR_VERSION **)(this + 0x30);
  if (param_1 != (_URBDR_VERSION *)0x0) {
    (**(code **)(*(longlong *)param_1 + 0x20))();
  }
LAB_140002f12:
  if ((Microsoft_Windows_TerminalServices_ServerUSBDevicesEnableBits & 0x20) != 0) {
    McTemplateK0pd_EtwWriteTransfer(param_1,&EVENT_NOTIFY_DVC_CONNECTED,in_R8,this + -8,(char)lVar3)
    ;
  }
  return lVar3;
}



===== ChannelCreated @ 140002f50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CSession::ChannelCreated(struct _URBDR_VERSION * __ptr64) __ptr64 */

long __thiscall CSession::ChannelCreated(CSession *this,_URBDR_VERSION *param_1)

{
  longlong lVar1;
  undefined2 uVar2;
  long lVar3;
  undefined *in_R8;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_R8 = &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
            &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids);
  }
  if (this[0x29] == (CSession)0x0) {
    lVar3 = -0x7ff8ffeb;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar2 = 0x1c;
LAB_140002ff5:
      in_R8 = &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
              &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids);
    }
  }
  else {
    in_R8 = (undefined *)0xc;
    lVar1 = RtlCompareMemory(param_1,&g_UrbDrVersion);
    if (lVar1 == 0xc) {
      lVar3 = 0;
      this[0x28] = (CSession)0x1;
      goto LAB_140003022;
    }
    lVar3 = -0x7ff8fae6;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar2 = 0x1d;
      goto LAB_140002ff5;
    }
  }
  param_1 = *(_URBDR_VERSION **)(this + 0x20);
  if (param_1 != (_URBDR_VERSION *)0x0) {
    (**(code **)(*(longlong *)param_1 + 0x20))();
  }
LAB_140003022:
  if ((Microsoft_Windows_TerminalServices_ServerUSBDevicesEnableBits & 0x20) != 0) {
    McTemplateK0pd_EtwWriteTransfer(param_1,&EVENT_NOTIFY_DVC_CONNECTED,in_R8,this + -8,(char)lVar3)
    ;
  }
  return lVar3;
}



===== CloseChannel @ 140003058 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CSession::CloseChannel(void) __ptr64 */

void __thiscall CSession::CloseChannel(CSession *this)

{
  uint uVar1;
  undefined8 uVar2;
  longlong *plVar3;
  ulonglong uVar4;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x70))(WdfDriverGlobals,*(undefined8 *)(this + 0x70));
  if (uVar1 != 0) {
    uVar4 = (ulonglong)uVar1;
    do {
      uVar2 = (**(code **)(WdfFunctions_01015 + 0x98))
                        (WdfDriverGlobals,*(undefined8 *)(this + 0x70));
      (**(code **)(WdfFunctions_01015 + 0x80))(WdfDriverGlobals,*(undefined8 *)(this + 0x70),uVar2);
      plVar3 = (longlong *)
               (**(code **)(WdfFunctions_01015 + 0x650))
                         (WdfDriverGlobals,uVar2,PTR__WDF_CDeviceSink_TYPE_INFO_14001d040);
      if ((longlong *)plVar3[7] != (longlong *)0x0) {
        (**(code **)(*(longlong *)plVar3[7] + 0x20))();
      }
      (**(code **)(*plVar3 + 0x10))(plVar3);
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  if (*(longlong **)(this + 0x28) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(this + 0x28) + 0x20))();
  }
  return;
}



===== ConnectToDynamicVC @ 140003154 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl CSession::ConnectToDynamicVC(void * __ptr64,struct ITsChannelNotification *
   __ptr64,struct ITsUsbDeviceSink * __ptr64,struct IWTSVirtualChannel * __ptr64 * __ptr64,struct
   ITsChannelNotification * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CSession::ConnectToDynamicVC
          (CSession *this,void *param_1,ITsChannelNotification *param_2,ITsUsbDeviceSink *param_3,
          IWTSVirtualChannel **param_4,ITsChannelNotification **param_5)

{
  IRIMObjManager *pIVar1;
  long lVar2;
  long lVar3;
  undefined2 uVar4;
  ulong uVar5;
  IWTSVirtualChannel *pIVar6;
  TCommonVCThreading in_stack_ffffffffffffffa8;
  IWTSVirtualChannel *local_48;
  ITsChannelNotification *local_40;
  IWTSVirtualChannelCallback *local_38;
  IRIMObjManager *local_30;
  
  local_30 = (IRIMObjManager *)0x0;
  local_48 = (IWTSVirtualChannel *)0x0;
  local_38 = (IWTSVirtualChannelCallback *)0x0;
  local_40 = (ITsChannelNotification *)0x0;
  lVar2 = GetInstanceOfObjectManager
                    ((_func_long__GUID_ptr_IRIMStream_ptr_IUnknown_ptr_ptr *)this,param_1,&local_30,
                     (ulong)param_3,in_stack_ffffffffffffffa8);
  pIVar1 = local_30;
  if (lVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar4 = 0x11;
LAB_1400031c2:
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
               &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,lVar2);
    }
  }
  else {
    (**(code **)(*(longlong *)local_30 + 0x40))(local_30,30000);
    uVar5 = (ulong)&local_38;
    lVar2 = (**(code **)(*(longlong *)pIVar1 + 0x18))(pIVar1);
    if (-1 < lVar2) {
      lVar2 = CKDynamicVC::CreateInstance
                        (*(ulong *)(this + 0x20),uVar5,param_1,local_38,in_stack_ffffffffffffffa8,
                         &local_48);
      pIVar6 = local_48;
      if (lVar2 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                   &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,lVar2);
        }
        pIVar6 = local_48;
        goto LAB_1400033d9;
      }
      lVar2 = (**(code **)(*(longlong *)pIVar1 + 0x20))(pIVar1,local_48);
      if (lVar2 < 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400033d9;
        uVar4 = 0x14;
      }
      else {
        lVar2 = (**(code **)(*(longlong *)pIVar1 + 0x28))(pIVar1,param_3,&IID_ITsUsbDeviceSink,1);
        if (lVar2 < 0) {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400033d9;
          uVar4 = 0x15;
        }
        else {
          lVar2 = (**(code **)(*(longlong *)pIVar1 + 0x28))
                            (pIVar1,param_2,&IID_ITsChannelNotification,3);
          if (lVar2 < 0) {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400033d9;
            uVar4 = 0x16;
          }
          else {
            lVar2 = (**(code **)(*(longlong *)pIVar1 + 0x30))
                              (pIVar1,&IID_ITsChannelNotification,2,&local_40);
            if (-1 < lVar2) {
              lVar2 = 0;
              *param_4 = pIVar6;
              pIVar6 = (IWTSVirtualChannel *)0x0;
              *param_5 = local_40;
              local_40 = (ITsChannelNotification *)0x0;
              goto LAB_1400033d9;
            }
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1400033d9;
            uVar4 = 0x17;
          }
        }
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
               &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,lVar2);
      goto LAB_1400033d9;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar4 = 0x12;
      goto LAB_1400031c2;
    }
  }
  pIVar6 = (IWTSVirtualChannel *)0x0;
LAB_1400033d9:
  if (pIVar1 != (IRIMObjManager *)0x0) {
    (**(code **)(*(longlong *)pIVar1 + 0x10))(pIVar1);
  }
  if (pIVar6 != (IWTSVirtualChannel *)0x0) {
    (**(code **)(*(longlong *)pIVar6 + 0x10))(pIVar6);
  }
  if (local_38 != (IWTSVirtualChannelCallback *)0x0) {
    (**(code **)(*(longlong *)local_38 + 0x10))();
  }
  if (local_40 != (ITsChannelNotification *)0x0) {
    (**(code **)(*(longlong *)local_40 + 0x10))();
  }
  lVar3 = -0x3fffffff;
  if (-1 < lVar2) {
    lVar3 = 0;
  }
  return lVar3;
}



===== CreateInstance @ 14000345c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl CDeviceSink::CreateInstance(class CSession * __ptr64,void *
   __ptr64,void * __ptr64 * __ptr64) */

long __cdecl CDeviceSink::CreateInstance(CSession *param_1,void *param_2,void **param_3)

{
  int iVar1;
  void *pvVar2;
  undefined2 uVar3;
  void *local_res10 [2];
  CDeviceSink *local_res20;
  undefined4 local_58;
  undefined4 local_54;
  code *local_50;
  undefined8 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  void *local_38;
  undefined8 local_30;
  undefined *local_28;
  
  local_res10[0] = (void *)0x0;
  local_54 = 0;
  local_48 = 0;
  local_30 = 0;
  local_res20 = (CDeviceSink *)0x0;
  local_40 = 1;
  local_3c = 1;
  local_28 = PTR__WDF_CDeviceSink_TYPE_INFO_14001d040;
  local_50 = BdEvtDeviceSinkCleanup;
  local_58 = 0x38;
  local_38 = param_2;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_58,local_res10);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000356c;
    uVar3 = 0x27;
  }
  else {
    pvVar2 = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                               (WdfDriverGlobals,local_res10[0],
                                PTR__WDF_CDeviceSink_TYPE_INFO_14001d040);
    iVar1 = CreateInstance(pvVar2,local_res10[0],param_1,&local_res20);
    if (-1 < iVar1) {
      *param_3 = local_res10[0];
      return 0;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000356c;
    uVar3 = 0x28;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,iVar1);
LAB_14000356c:
  if (local_res10[0] != (void *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar1;
}



===== CreateInstance @ 1400035b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl CDeviceSink::CreateInstance(void * __ptr64,void * __ptr64,class
   CSession * __ptr64,class CDeviceSink * __ptr64 * __ptr64) */

long __cdecl
CDeviceSink::CreateInstance(void *param_1,void *param_2,CSession *param_3,CDeviceSink **param_4)

{
  long lVar1;
  
  lVar1 = 0;
  if (param_1 == (void *)0x0) {
    lVar1 = -0x3fffffe9;
  }
  else {
    *(undefined8 *)((longlong)param_1 + 0x28) = 0;
    *(undefined ***)param_1 = &_vftable__for__ITsUsbDeviceSink__;
    *(undefined ***)((longlong)param_1 + 8) = &_vftable__for__ITsChannelNotification__;
    *(undefined ***)((longlong)param_1 + 0x10) = &_vftable__for__IRIMChannelCallback__;
    *(undefined8 *)((longlong)param_1 + 0x30) = 0;
    *(undefined8 *)((longlong)param_1 + 0x38) = 0;
    *(undefined2 *)((longlong)param_1 + 0x40) = 0;
    *(undefined1 *)((longlong)param_1 + 0x42) = 0;
    *(undefined4 *)((longlong)param_1 + 0x18) = 0;
    *(void **)((longlong)param_1 + 0x20) = param_2;
    (**(code **)(*(longlong *)param_1 + 8))();
    *(CSession **)((longlong)param_1 + 0x28) = param_3;
    (**(code **)(*(longlong *)param_3 + 8))(param_3);
    *param_4 = param_1;
  }
  return lVar1;
}



===== CreateInstance @ 14000365c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl CSession::CreateInstance(struct WDFDEVICE__ * __ptr64,unsigned
   long,unsigned long,unsigned long,void * __ptr64 * __ptr64) */

long __cdecl
CSession::CreateInstance
          (WDFDEVICE__ *param_1,ulong param_2,ulong param_3,ulong param_4,void **param_5)

{
  int iVar1;
  void *pvVar2;
  undefined2 uVar3;
  void *local_res8;
  CSession *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  code *local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  WDFDEVICE__ *local_30;
  undefined8 local_28;
  undefined *local_20;
  
  local_res8 = (void *)0x0;
  local_4c = 0;
  local_40 = 0;
  local_28 = 0;
  local_58 = (CSession *)0x0;
  local_38 = 1;
  local_34 = 1;
  local_20 = PTR__WDF_CSession_TYPE_INFO_14001d018;
  local_48 = BdEvtSessionCleanup;
  local_50 = 0x38;
  local_30 = param_1;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x678))(WdfDriverGlobals,&local_50,&local_res8);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000379a;
    uVar3 = 10;
  }
  else {
    pvVar2 = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                               (WdfDriverGlobals,local_res8,PTR__WDF_CSession_TYPE_INFO_14001d018);
    iVar1 = CreateInstance(pvVar2,param_1,local_res8,param_2,param_3,param_4,&local_58);
    if (-1 < iVar1) {
      *param_5 = local_res8;
      return 0;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000379a;
    uVar3 = 0xb;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,iVar1);
LAB_14000379a:
  if (local_res8 != (void *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar1;
}



===== CreateInstance @ 1400037f4 =====

/* public: static long __cdecl CSession::CreateInstance(void * __ptr64,struct WDFDEVICE__ *
   __ptr64,void * __ptr64,unsigned long,unsigned long,unsigned long,class CSession * __ptr64 *
   __ptr64) */

long __cdecl
CSession::CreateInstance
          (void *param_1,WDFDEVICE__ *param_2,void *param_3,ulong param_4,ulong param_5,
          ulong param_6,CSession **param_7)

{
  long lVar1;
  
  if (param_1 == (void *)0x0) {
    lVar1 = -0x3fffffe9;
  }
  else {
    *(undefined4 *)((longlong)param_1 + 0x24) = 0xff;
    *(undefined ***)param_1 = &_vftable__for__ITsUsbDeviceSink__;
    *(undefined ***)((longlong)param_1 + 8) = &_vftable__for__ITsChannelNotification__;
    *(undefined ***)((longlong)param_1 + 0x10) = &_vftable__for__IRIMChannelCallback__;
    *(undefined4 *)((longlong)param_1 + 0x1c) = 0xffffffff;
    *(undefined4 *)((longlong)param_1 + 0x20) = 0xffffffff;
    *(undefined8 *)((longlong)param_1 + 0x28) = 0;
    *(undefined2 *)((longlong)param_1 + 0x30) = 0;
    *(undefined8 *)((longlong)param_1 + 0x40) = 0;
    *(undefined8 *)((longlong)param_1 + 0x48) = 0;
    *(undefined8 *)((longlong)param_1 + 0x50) = 0;
    *(undefined4 *)((longlong)param_1 + 0x58) = 0;
    *(undefined8 *)((longlong)param_1 + 0x60) = 0;
    *(undefined8 *)((longlong)param_1 + 0x70) = 0;
    *(undefined1 *)((longlong)param_1 + 0x78) = 0;
    *(undefined4 *)((longlong)param_1 + 0x18) = 0;
    lVar1 = Initialize(param_1,param_2,param_3,param_4,param_5,param_6);
    if (lVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                 &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,lVar1);
      }
      ~CSession(param_1);
    }
    else {
      lVar1 = 0;
      *param_7 = param_1;
    }
  }
  return lVar1;
}



===== CreateSessionChildList @ 1400038e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CSession::CreateSessionChildList(struct WDFDEVICE__ * __ptr64,struct
   WDFCHILDLIST__ * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CSession::CreateSessionChildList(CSession *this,WDFDEVICE__ *param_1,WDFCHILDLIST__ **param_2)

{
  uint uVar1;
  undefined4 local_68;
  undefined4 local_64;
  code *local_58;
  code *local_40;
  code *local_38;
  code *local_30;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
            &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids);
  }
  *param_2 = (WDFCHILDLIST__ *)0x0;
  memset(&local_68,0,0x60);
  local_58 = PdEvtChildListCreateDevice;
  local_68 = 0x60;
  local_40 = Bus_EvtChildListIdentificationDescriptionDuplicate;
  local_64 = 0x78;
  local_30 = Bus_EvtChildListIdentificationDescriptionCompare;
  local_38 = Bus_EvtChildListIdentificationDescriptionCleanup;
  uVar1 = (*(code *)*WdfFunctions_01015)(WdfDriverGlobals,param_1,&local_68,0,param_2);
  if ((((int)(uVar1 | 0x10000000) < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control))
     && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
             &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,uVar1);
  }
  return uVar1 | 0x10000000;
}



===== DevicePlugIn @ 1400039fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl CSession::DevicePlugIn(unsigned short * __ptr64,unsigned __int64,unsigned
   short * __ptr64,unsigned __int64,unsigned short * __ptr64,unsigned __int64,struct _GUID const &
   __ptr64,struct _USB_DEVICE_CAPABILITIES * __ptr64,struct ITsUsbDevice * __ptr64) __ptr64 */

long __thiscall
CSession::DevicePlugIn
          (CSession *this,ushort *param_1,__uint64 param_2,ushort *param_3,__uint64 param_4,
          ushort *param_5,__uint64 param_6,_GUID *param_7,_USB_DEVICE_CAPABILITIES *param_8,
          ITsUsbDevice *param_9)

{
  CSession *pCVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  CUsbHub *this_00;
  ushort *puVar5;
  
  uVar4 = (**(code **)(WdfFunctions_01015 + 8))(WdfDriverGlobals,*(undefined8 *)(this + 0x60));
  this_00 = WdfDriverGlobals;
  puVar5 = (ushort *)PTR__WDF_CUsbHub_TYPE_INFO_14001d068;
  (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar4);
  LOCK();
  pCVar1 = this + 0x54;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + 1;
  UNLOCK();
  if (*(uint *)(this + 0x24) < iVar2 + 1U) {
    lVar3 = -0x3ffffff0;
    param_1 = puVar5;
  }
  else {
    lVar3 = CUsbHub::DevicePlugIn
                      (this_00,*(WDFCHILDLIST__ **)(this + 0x60),param_1,param_2,param_3,param_4,
                       param_5,param_6,*(ulong *)(this + 0x1c),*(ulong *)(this + 0x20),param_7,
                       param_8,param_9);
    if (-1 < lVar3) goto LAB_140003af5;
  }
  LOCK();
  *(int *)(this + 0x54) = *(int *)(this + 0x54) + -1;
  UNLOCK();
LAB_140003af5:
  if ((Microsoft_Windows_TerminalServices_ServerUSBDevicesEnableBits & 0x20) != 0) {
    McTemplateK0pd_EtwWriteTransfer
              (this_00,&EVENT_NOTIFY_CLIENT_DEVICE_REPORTED,param_1,param_9,(char)lVar3);
  }
  return lVar3;
}



===== DeviceUnplug @ 140003b38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CSession::DeviceUnplug(struct ITsUsbDevice * __ptr64) __ptr64 */

void __thiscall CSession::DeviceUnplug(CSession *this,ITsUsbDevice *param_1)

{
  long lVar1;
  undefined8 uVar2;
  CUsbHub *this_00;
  ITsUsbDevice *pIVar3;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 8))(WdfDriverGlobals,*(undefined8 *)(this + 0x60));
  this_00 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,uVar2,PTR__WDF_CUsbHub_TYPE_INFO_14001d068);
  pIVar3 = param_1;
  lVar1 = CUsbHub::DeviceUnplug(this_00,*(WDFCHILDLIST__ **)(this + 0x60),param_1);
  LOCK();
  *(int *)(this + 0x54) = *(int *)(this + 0x54) + -1;
  UNLOCK();
  if ((Microsoft_Windows_TerminalServices_ServerUSBDevicesEnableBits & 0x20) != 0) {
    McTemplateK0pd_EtwWriteTransfer
              (this_00,&EVENT_NOTIFY_CLIENT_DEVICE_REMOVED,pIVar3,param_1,(char)lVar1);
  }
  return;
}



===== EvtIoDeviceControl_NewDynamicVC @ 140003bc8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CSession::EvtIoDeviceControl_NewDynamicVC(void * __ptr64) __ptr64 */

void __thiscall CSession::EvtIoDeviceControl_NewDynamicVC(CSession *this,void *param_1)

{
  bool bVar1;
  void *pvVar2;
  int iVar3;
  long lVar4;
  ITsUsbDeviceSink *pIVar5;
  undefined2 uVar6;
  ITsChannelNotification *local_res8;
  IWTSVirtualChannel *local_res10;
  void *local_res18;
  longlong local_res20;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (4 < (byte)WPP_GLOBAL_Control[0x29]) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
              &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                 &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,*(undefined4 *)(this + 0x1c),
                 (char)*(undefined4 *)(this + 0x20),(char)param_1);
    }
  }
  local_res20 = 0;
  local_res10 = (IWTSVirtualChannel *)0x0;
  local_res18 = (void *)0x0;
  local_res8 = (ITsChannelNotification *)0x0;
  bVar1 = false;
  LOCK();
  *(int *)(this + 0x48) = *(int *)(this + 0x48) + 1;
  UNLOCK();
  if (param_1 == (void *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
              &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids);
    }
    goto LAB_140003f82;
  }
  iVar3 = ObReferenceObjectByHandle
                    (param_1,0,*(undefined8 *)IoFileObjectType_exref,1,&local_res20,0);
  if (iVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
               &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,iVar3);
    }
    goto LAB_140003f82;
  }
  LOCK();
  *(int *)(this + 0x4c) = *(int *)(this + 0x4c) + 1;
  UNLOCK();
  if ((*(int *)(this + 0x40) == 1) && (*(int *)(this + 0x4c) == 1)) {
    lVar4 = ConnectToDynamicVC(this,param_1,
                               (ITsChannelNotification *)
                               (-(ulonglong)(this != (CSession *)0x0) & (ulonglong)(this + 8)),
                               (ITsUsbDeviceSink *)this,(IWTSVirtualChannel **)(this + 0x28),
                               &local_res8);
    if (lVar4 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                 &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,lVar4);
      }
    }
    else {
      this[0x31] = (CSession)0x1;
      iVar3 = (**(code **)(*(longlong *)local_res8 + 0x18))(local_res8,&g_UrbDrVersion);
      if (iVar3 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                  &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids);
        }
        (**(code **)(*(longlong *)*(IWTSVirtualChannel **)(this + 0x28) + 0x20))();
      }
LAB_140003f69:
      LOCK();
      *(int *)(this + 0x50) = *(int *)(this + 0x50) + 1;
      UNLOCK();
    }
  }
  else {
    lVar4 = CDeviceSink::CreateInstance(this,*(void **)(this + 0x38),&local_res18);
    pvVar2 = local_res18;
    if (lVar4 < 0) goto LAB_140003f82;
    pIVar5 = (ITsUsbDeviceSink *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,local_res18,PTR__WDF_CDeviceSink_TYPE_INFO_14001d040);
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x78))(WdfDriverGlobals,*(undefined8 *)(this + 0x70));
    if (iVar3 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar6 = 0x24;
        bVar1 = false;
LAB_140003eac:
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                 &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,iVar3);
      }
    }
    else {
      bVar1 = true;
      iVar3 = ConnectToDynamicVC(this,param_1,
                                 (ITsChannelNotification *)
                                 (-(ulonglong)(pIVar5 != (ITsUsbDeviceSink *)0x0) &
                                 (ulonglong)(pIVar5 + 8)),pIVar5,&local_res10,&local_res8);
      if (-1 < iVar3) {
        *(IWTSVirtualChannel **)(pIVar5 + 0x38) = local_res10;
        pIVar5[0x41] = (ITsUsbDeviceSink)0x1;
        iVar3 = (**(code **)(*(longlong *)local_res8 + 0x18))(local_res8,&g_UrbDrVersion);
        if (iVar3 < 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,
                    &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids);
          }
          (**(code **)(**(longlong **)(pIVar5 + 0x38) + 0x20))();
        }
        local_res10 = (IWTSVirtualChannel *)0x0;
        goto LAB_140003f69;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar6 = 0x25;
        bVar1 = true;
        goto LAB_140003eac;
      }
    }
    if (pIVar5 != (ITsUsbDeviceSink *)0x0) {
      if (bVar1) {
        (**(code **)(WdfFunctions_01015 + 0x80))
                  (WdfDriverGlobals,*(undefined8 *)(this + 0x70),pvVar2);
      }
      (**(code **)(*(longlong *)pIVar5 + 0x10))(pIVar5);
    }
  }
  if (local_res8 != (ITsChannelNotification *)0x0) {
    (**(code **)(*(longlong *)local_res8 + 0x10))();
  }
LAB_140003f82:
  if (local_res20 != 0) {
    ObfDereferenceObject();
  }
  if (local_res10 != (IWTSVirtualChannel *)0x0) {
    (**(code **)(*(longlong *)local_res10 + 0x10))();
  }
  return;
}



===== Initialize @ 140003fc4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CSession::Initialize(struct WDFDEVICE__ * __ptr64,void * __ptr64,unsigned
   long,unsigned long,unsigned long) __ptr64 */

long __thiscall
CSession::Initialize
          (CSession *this,WDFDEVICE__ *param_1,void *param_2,ulong param_3,ulong param_4,
          ulong param_5)

{
  long lVar1;
  CSession *this_00;
  undefined2 uVar2;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  *(ulong *)(this + 0x20) = param_4;
  *(ulong *)(this + 0x1c) = param_3;
  *(void **)(this + 0x38) = param_2;
  this_00 = this;
  (**(code **)(*(longlong *)this + 8))();
  if (0xfe < param_5 - 1) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return -0x3ffffff3;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return -0x3ffffff3;
    }
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,param_5);
    return -0x3ffffff3;
  }
  *(ulong *)(this + 0x24) = param_5;
  lVar1 = CreateSessionChildList(this_00,param_1,(WDFCHILDLIST__ **)(this + 0x60));
  if (lVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return lVar1;
    }
    uVar2 = 0xf;
  }
  else {
    local_18 = 0;
    local_28 = *(undefined8 *)(this + 0x38);
    local_38 = 0;
    uStack_20 = 0;
    uStack_40 = 0;
    local_48 = 0x38;
    uStack_30 = 0x100000001;
    lVar1 = (**(code **)(WdfFunctions_01015 + 0x68))(WdfDriverGlobals,&local_48,this + 0x70);
    if (-1 < lVar1) {
      *(undefined4 *)(this + 0x40) = 1;
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return lVar1;
    }
    uVar2 = 0x10;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids,lVar1);
  return lVar1;
}



===== OnChannelClose @ 140004140 =====

/* public: virtual long __cdecl CDeviceSink::OnChannelClose(void) __ptr64 */

long __thiscall CDeviceSink::OnChannelClose(CDeviceSink *this)

{
  CSession *this_00;
  undefined8 in_R8;
  
  if (this[0x32] == (CDeviceSink)0x0) {
    this[0x32] = (CDeviceSink)0x1;
    this[0x30] = (CDeviceSink)0x0;
    this_00 = (CSession *)this;
    if (*(ITsUsbDevice **)(this + 0x20) != (ITsUsbDevice *)0x0) {
      this_00 = *(CSession **)(this + 0x18);
      CSession::DeviceUnplug(this_00,*(ITsUsbDevice **)(this + 0x20));
    }
    if ((Microsoft_Windows_TerminalServices_ServerUSBDevicesEnableBits & 0x20) != 0) {
      McTemplateK0pd_EtwWriteTransfer(this_00,&EVENT_NOTIFY_DVC_DISCONNECTED,in_R8,this + -0x10,0);
    }
  }
  return 0;
}



===== OnChannelClose @ 1400041a0 =====

/* public: virtual long __cdecl CSession::OnChannelClose(void) __ptr64 */

long __thiscall CSession::OnChannelClose(CSession *this)

{
  undefined *in_R8;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_R8 = &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
            &WPP_fa5c402fc484364afca3fc4c24f277c9_Traceguids);
  }
  if (this[0x68] == (CSession)0x0) {
    this[0x68] = (CSession)0x1;
    this[0x20] = (CSession)0x0;
    if ((Microsoft_Windows_TerminalServices_ServerUSBDevicesEnableBits & 0x20) != 0) {
      McTemplateK0pd_EtwWriteTransfer(0,&EVENT_NOTIFY_DVC_DISCONNECTED,in_R8,this + -0x10,0);
    }
  }
  return 0;
}



===== QueryInterface @ 140004220 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CSession::QueryInterface(struct _GUID const & __ptr64,void * __ptr64
   * __ptr64) __ptr64 */

long __thiscall CSession::QueryInterface(CSession *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  CSession *pCVar2;
  long lVar3;
  
  *param_2 = (void *)0x0;
  lVar1 = *(longlong *)param_1;
  lVar3 = -0x7fffbffe;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)(param_1 + 8) + -0x46000000000000c0;
  }
  if (lVar1 != 0) {
    lVar1 = *(longlong *)param_1 + -0x45c343f5cec617f6;
    if (lVar1 == 0) {
      lVar1 = *(longlong *)(param_1 + 8) + 0x2b83ee15f9ece169;
    }
    if (lVar1 != 0) {
      lVar1 = *(longlong *)param_1 + -0x420da29527c1b69e;
      if (lVar1 == 0) {
        lVar1 = *(longlong *)(param_1 + 8) + -0x7699c11ebc7e2a82;
      }
      if (lVar1 != 0) {
        return -0x7fffbffe;
      }
      pCVar2 = (CSession *)(-(ulonglong)(this != (CSession *)0x0) & (ulonglong)(this + 0x10));
      goto LAB_14000429a;
    }
  }
  pCVar2 = this;
LAB_14000429a:
  *param_2 = pCVar2;
  if (pCVar2 != (CSession *)0x0) {
    (**(code **)(*(longlong *)this + 8))(this);
    lVar3 = 0;
  }
  return lVar3;
}



===== QueryInterface`adjustor{8}' @ 1400042d0 =====

/* [thunk]:public: virtual long __cdecl CDeviceSink::QueryInterface`adjustor{8}' (struct _GUID const
   & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CDeviceSink::QueryInterface_adjustor_8__(CDeviceSink *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = CSession::QueryInterface((CSession *)(this + -8),param_1,param_2);
  return lVar1;
}



===== QueryInterface`adjustor{16}' @ 1400042e0 =====

/* [thunk]:public: virtual long __cdecl CDeviceSink::QueryInterface`adjustor{16}' (struct _GUID
   const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CDeviceSink::QueryInterface_adjustor_16__(CDeviceSink *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = CSession::QueryInterface((CSession *)(this + -0x10),param_1,param_2);
  return lVar1;
}



===== Release @ 1400042f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual unsigned long __cdecl CDeviceSink::Release(void) __ptr64 */

ulong __thiscall CDeviceSink::Release(CDeviceSink *this)

{
  CDeviceSink *pCVar1;
  int iVar2;
  
  LOCK();
  pCVar1 = this + 0x18;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  if (iVar2 - 1U == 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(this + 0x20));
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,*(undefined8 *)(this + 0x20),0,0x14f,
               "clientcore\\termsrv\\devices\\urbdr\\busdriver\\CSession.h");
  }
  return iVar2 - 1U;
}



===== Release`adjustor{8}' @ 140004370 =====

/* [thunk]:public: virtual unsigned long __cdecl CDeviceSink::Release`adjustor{8}' (void) __ptr64 */

ulong __thiscall CDeviceSink::Release_adjustor_8__(CDeviceSink *this)

{
  ulong uVar1;
  
  uVar1 = Release(this + -8);
  return uVar1;
}



===== Release`adjustor{16}' @ 140004380 =====

/* [thunk]:public: virtual unsigned long __cdecl CDeviceSink::Release`adjustor{16}' (void) __ptr64
    */

ulong __thiscall CDeviceSink::Release_adjustor_16__(CDeviceSink *this)

{
  ulong uVar1;
  
  uVar1 = Release(this + -0x10);
  return uVar1;
}



===== Release @ 140004390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual unsigned long __cdecl CSession::Release(void) __ptr64 */

ulong __thiscall CSession::Release(CSession *this)

{
  CSession *pCVar1;
  int iVar2;
  ulong uVar3;
  
  LOCK();
  pCVar1 = this + 0x18;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  uVar3 = iVar2 - 1;
  if (uVar3 == 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,*(undefined8 *)(this + 0x38));
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,*(undefined8 *)(this + 0x38),0,iVar2 + 0x2b,
               "clientcore\\termsrv\\devices\\urbdr\\busdriver\\CSession.h");
  }
  return uVar3;
}



===== Release`adjustor{8}' @ 140004410 =====

/* [thunk]:public: virtual unsigned long __cdecl CSession::Release`adjustor{8}' (void) __ptr64 */

ulong __thiscall CSession::Release_adjustor_8__(CSession *this)

{
  ulong uVar1;
  
  uVar1 = Release(this + -8);
  return uVar1;
}



===== Release`adjustor{16}' @ 140004420 =====

/* [thunk]:public: virtual unsigned long __cdecl CSession::Release`adjustor{16}' (void) __ptr64 */

ulong __thiscall CSession::Release_adjustor_16__(CSession *this)

{
  ulong uVar1;
  
  uVar1 = Release(this + -0x10);
  return uVar1;
}



===== RtlStringCchLengthW @ 140004430 =====

/* long __cdecl RtlStringCchLengthW(unsigned short const * __ptr64,unsigned __int64,unsigned __int64
   * __ptr64) */

long __cdecl RtlStringCchLengthW(ushort *param_1,__uint64 param_2,__uint64 *param_3)

{
  __uint64 _Var1;
  uint uVar2;
  
  if ((param_1 == (ushort *)0x0) || (_Var1 = param_2, 0x7fffffff < param_2)) {
    uVar2 = 0xc000000d;
  }
  else {
    for (; (_Var1 != 0 && (*param_1 != 0)); param_1 = param_1 + 1) {
      _Var1 = _Var1 - 1;
    }
    uVar2 = ~-(uint)(_Var1 != 0) & 0xc000000d;
    if (param_3 != (__uint64 *)0x0) {
      if (_Var1 == 0) {
        *param_3 = 0;
      }
      else {
        *param_3 = param_2 - _Var1;
      }
    }
    if (_Var1 != 0) {
      return uVar2;
    }
  }
  if (param_3 != (__uint64 *)0x0) {
    *param_3 = 0;
  }
  return uVar2;
}



===== RtlStringCchPrintfW @ 14000449c =====

/* long __cdecl RtlStringCchPrintfW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64,...) */

long __cdecl RtlStringCchPrintfW(ushort *param_1,__uint64 param_2,ushort *param_3,...)

{
  ulonglong _Count;
  int iVar1;
  long lVar2;
  undefined8 in_R9;
  undefined8 local_res20;
  
  if (param_2 - 1 < 0x7fffffff) {
    _Count = param_2 - 1;
    lVar2 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnwprintf((wchar_t *)param_1,_Count,(wchar_t *)param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      lVar2 = -0x7ffffffb;
    }
    else if ((longlong)iVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = 0;
  }
  else {
    lVar2 = -0x3ffffff3;
    if (param_2 != 0) {
      *param_1 = 0;
    }
  }
  return lVar2;
}



===== McGenEventWrite_EtwWriteTransfer @ 140004518 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14001d088;
  uVar2 = 0;
  if (DAT_14001d088 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14001d088;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(USB_Redirector_Event_Provider_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateK0pd_EtwWriteTransfer @ 14000457c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined8 local_res20;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined8 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = &local_res20;
  local_28 = &param_5;
  local_2c = 0;
  local_30 = 8;
  local_1c = 0;
  local_20 = 4;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,3,local_48);
  return;
}



===== WPP_SF_DDq @ 1400045ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,8,0);
  return;
}



===== WPP_SF_S @ 14000464c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_S(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  
  if (param_4 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,lVar1,0);
  return;
}



===== RtlUnicodeStringPrintf @ 1400046b8 =====

/* long __cdecl RtlUnicodeStringPrintf(struct _UNICODE_STRING * __ptr64,unsigned short const *
   __ptr64,...) */

long __cdecl RtlUnicodeStringPrintf(_UNICODE_STRING *param_1,ushort *param_2,...)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  long lVar5;
  ulonglong _Count;
  undefined8 in_R8;
  undefined8 in_R9;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar1 = *(ushort *)param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = *(ushort *)(param_1 + 2), (uVar2 & 1) == 0)) &&
       (uVar1 <= uVar2)) && (uVar2 != 0xffff)) &&
     ((lVar5 = 0, *(longlong *)(param_1 + 8) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    _Count = (ulonglong)(*(ushort *)(param_1 + 2) >> 1);
    local_res18 = in_R8;
    local_res20 = in_R9;
    iVar3 = _vsnwprintf(*(wchar_t **)(param_1 + 8),_Count,(wchar_t *)param_2,(va_list)&local_res18);
    if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
      lVar5 = -0x7ffffffb;
      uVar4 = _Count;
    }
    *(short *)param_1 = (short)uVar4 * 2;
  }
  else {
    lVar5 = -0x3ffffff3;
  }
  return lVar5;
}



===== Feature_1741656378__private_IsEnabledDeviceUsageNoInline @ 140004758 =====

ulonglong Feature_1741656378__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_1741656378__private_featureState;
  if ((Feature_1741656378__private_featureState & 0x10) == 0) {
    uVar1 = Feature_1741656378__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_1741656378__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_1741656378__private_IsEnabledFallback @ 140004790 =====

void Feature_1741656378__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== McTemplateK0p_EtwWriteTransfer @ 1400047a8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0p_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = &local_res20;
  local_1c = 0;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,2,local_38);
  return;
}



===== PdEvtIsochFrameTimerFunc @ 140004810 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdEvtIsochFrameTimerFunc(undefined8 param_1)

{
  undefined8 uVar1;
  CUsbHubPdo *this;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  this = (CUsbHubPdo *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,uVar1,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
  CUsbHubPdo::EvtIsochFrameTimer(this);
  return;
}



===== PdEvtRequestContextCleanup @ 140004870 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdEvtRequestContextCleanup(undefined8 param_1)

{
  CUsbHubPdoRequest *this;
  
  this = (CUsbHubPdoRequest *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CUsbHubPdoRequest_TYPE_INFO_14001d108);
  if (this != (CUsbHubPdoRequest *)0x0) {
    CUsbHubPdoRequest::~CUsbHubPdoRequest(this);
  }
  return;
}



===== PdEvtTimerFunc @ 1400048c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdEvtTimerFunc(undefined8 param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  uVar2 = (**(code **)(WdfFunctions_01015 + 0xa08))(WdfDriverGlobals,param_1);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar2);
  lVar4 = *(longlong *)(lVar3 + 0x98);
  LOCK();
  lVar1 = *(longlong *)(lVar3 + 0x98);
  if (lVar4 == lVar1) {
    *(longlong *)(lVar3 + 0x98) = 0;
  }
  else {
    lVar4 = lVar1;
  }
  UNLOCK();
  if (lVar4 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
              &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids);
    }
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,lVar4);
  }
  return;
}



===== WPP_SF_q @ 140004978 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_a7e2db3185263fa4450192ae3326bec7_Traceguids,param_2,&local_res20,8,0)
  ;
  return;
}



===== WppClassicProviderCallback @ 1400049c0 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 1400049f4 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14001cea7 < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140004a1c =====

void wil_details_FeatureReporting_IncrementOpportunityInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *param_1;
  do {
    uVar1 = uVar2;
    param_4[1] = 0;
    uVar2 = uVar1 | 1;
    if ((uVar1 >> 0x16 & 1) != (uint)(param_2 == 5)) {
      uVar4 = uVar1 >> 0xf & 0x7f;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        uVar4 = 5;
        if (param_2 != 1) {
          uVar4 = 1;
        }
        uVar2 = uVar1 & 0xffc07fff | 1;
        param_4[2] = uVar4;
      }
      uVar4 = 0;
      if (param_2 == 5) {
        uVar4 = 0x400000;
      }
      uVar2 = uVar4 | uVar2 & 0xffbfffff;
    }
    uVar3 = uVar2 >> 0xf & 0x7f;
    uVar4 = uVar3 + 1;
    if ((0x7f < uVar4) || (uVar4 < uVar3)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar3;
    }
    LOCK();
    uVar3 = *param_1;
    if (uVar1 == uVar3) {
      *param_1 = uVar2 ^ (uVar4 << 0xf ^ uVar2) & 0x3f8000;
      uVar2 = uVar1;
    }
    else {
      uVar2 = uVar3;
    }
    UNLOCK();
  } while (uVar1 != uVar3);
  param_4[4] = 0;
  *param_4 = ~uVar1 & 1;
  return;
}



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140004b00 =====

void wil_details_FeatureReporting_IncrementUsageInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *param_1;
  do {
    uVar1 = uVar2;
    param_4[1] = 0;
    uVar2 = uVar1 | 1;
    if ((uVar1 >> 0xe & 1) != (uint)(param_2 == 4)) {
      uVar4 = uVar1 >> 5 & 0x1ff;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        param_4[2] = ~-(uint)(param_2 != 0) & 4;
        uVar2 = uVar1 & 0xffffc01f | 1;
      }
      uVar4 = 0;
      if (param_2 == 4) {
        uVar4 = 0x4000;
      }
      uVar2 = uVar4 | uVar2 & 0xffffbfff;
    }
    uVar3 = uVar2 >> 5 & 0x1ff;
    uVar4 = uVar3 + 1;
    if ((0x1ff < uVar4) || (uVar4 < uVar3)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar3;
    }
    LOCK();
    uVar3 = *param_1;
    if (uVar1 == uVar3) {
      *param_1 = uVar2 ^ (uVar4 << 5 ^ uVar2) & 0x3fe0;
      uVar2 = uVar1;
    }
    else {
      uVar2 = uVar3;
    }
    UNLOCK();
  } while (uVar1 != uVar3);
  param_4[4] = 0;
  *param_4 = ~uVar1 & 1;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140004bf0 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  uVar5 = (uint)param_3;
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (uVar5 == 0) {
LAB_140004d4c:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140004d3c:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140004d4c;
      if (uVar5 == 5) goto LAB_140004d3c;
      if ((uVar5 != 6) && (uVar5 != 7)) {
        uVar6 = uVar5 - 0x140;
        if ((int)uVar6 < 0x40) {
          uVar2 = param_2[1];
          do {
            if (((uVar2 & 0x10) == 0) || ((uVar2 >> 5 & 0x3f) != uVar6)) {
              uVar4 = 0;
            }
            else {
              uVar4 = 1;
            }
            param_1[4] = uVar4;
            LOCK();
            uVar4 = param_2[1];
            bVar7 = uVar2 == uVar4;
            if (bVar7) {
              param_2[1] = (uVar6 * 0x20 ^ uVar2) & 0x7e0 ^ uVar2 | 0x10;
            }
            else {
              uVar2 = uVar4;
            }
            UNLOCK();
          } while (!bVar7);
          if (param_1[4] != 0) {
            return param_1;
          }
        }
        param_1[2] = uVar5;
        param_1[1] = 1;
        param_1[3] = param_4;
        return param_1;
      }
    }
    uVar6 = 0;
    if (uVar5 == 2) {
      uVar6 = 2;
    }
    else if (uVar5 == 3) {
      uVar6 = 8;
    }
    else if (uVar5 == 6) {
      uVar6 = 4;
    }
    else if (uVar5 == 7) {
      uVar6 = 0x10;
    }
    uVar2 = 1;
    uVar5 = *param_2;
    do {
      uVar3 = uVar5;
      uVar5 = uVar6 | uVar3;
      param_1[4] = (uint)(uVar5 == uVar3);
      uVar4 = uVar5 | 1;
      if (uVar5 == uVar3) {
        uVar4 = uVar5;
      }
      LOCK();
      uVar1 = *param_2;
      if (uVar3 == uVar1) {
        *param_2 = uVar4;
        uVar5 = uVar3;
      }
      else {
        uVar5 = uVar1;
      }
      UNLOCK();
    } while (uVar3 != uVar1);
    if (((uVar4 & 1) == 0) || ((uVar3 & 1) != 0)) {
      uVar2 = 0;
    }
    *param_1 = uVar2;
  }
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 140004d74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,undefined8 param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  ulonglong uVar3;
  uint uVar4;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar4);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3b8adc7,&Feature_1741656378_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140004df0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStack_88 [32];
  uint *local_68;
  undefined8 local_58;
  uint local_50 [6];
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined8 local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_88;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_50,(uint *)&Feature_1741656378__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x3b8adc7,param_3 & 0xffffffff,1,&Feature_1741656378__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x3b8adc7);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140004edc =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140004fec =====

void wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  if (param_2 == 3) {
    uVar2 = 0x10;
  }
  else {
    if (param_2 != 4) {
      return;
    }
    uVar2 = 0x20;
  }
  if ((Feature_1741656378__private_featureState & 2) != 0) {
    uVar1 = Feature_1741656378__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_1741656378__private_featureState;
      if (bVar3) {
        Feature_1741656378__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_1741656378__private_featureState;
      }
      UNLOCK();
      if (bVar3) {
        return;
      }
      if ((uVar1 & 2) == 0) {
        return;
      }
    }
  }
  return;
}



===== wil_details_GetCurrentFeatureEnabledState @ 140005040 =====

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
  ulonglong local_res10;
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
        uVar7 = *(uint *)*puVar3;
        local_res10 = (ulonglong)uVar7;
        if ((uVar7 & 2) == 0) {
          uVar6 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            ((uint *)*puVar3,local_res10,(longlong)puVar3);
          uVar7 = (uint)uVar6;
        }
        uVar4 = local_res8 & 0xfffffffe;
        local_res8 = (uint)((uVar7 & local_res8 & 1) != 0);
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



===== wil_details_IsEnabledFallback @ 1400051a0 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_1741656378__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_1741656378__private_featureState,(ulonglong)param_1,
                             0x14001ce70);
    param_1 = puVar1;
    puVar1 = (undefined4 *)(local_res18 & 0xffffffff);
  }
  else {
    puVar1 = param_1;
  }
  if (param_2 != 0) {
    wil_details_FeatureReporting_ReportUsageToService(param_1,local_res18,param_2);
    if (param_2 - 3 < 2) {
      wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res18,param_2);
    }
  }
  return (uint)puVar1 & 1;
}



===== wil_details_MapReportingKind @ 140005230 =====

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



===== wil_details_RecordCachedUsage @ 1400052d0 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140005420 =====

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



===== ~CUsbHubPdo @ 1400054a4 =====

/* public: __cdecl CUsbHubPdo::~CUsbHubPdo(void) __ptr64 */

void __thiscall CUsbHubPdo::~CUsbHubPdo(CUsbHubPdo *this)

{
  ulong uVar1;
  void *pvVar2;
  long lVar3;
  uint in_EDX;
  ulong uVar4;
  ulong *puVar5;
  CSimpleHash *this_00;
  uint uVar6;
  ulong local_res8 [2];
  void *local_res10;
  
  local_res10 = (void *)0x0;
  if (*(CSimpleHash **)(this + 0x10) != (CSimpleHash *)0x0) {
    CSimpleHash::_scalar_deleting_destructor_(*(CSimpleHash **)(this + 0x10),in_EDX);
  }
  *(undefined8 *)(this + 0x10) = 0;
  uVar6 = 0;
LAB_1400054d4:
  do {
    if (uVar6 == 0) {
      this_00 = *(CSimpleHash **)(this + 0x20);
    }
    else {
      this_00 = *(CSimpleHash **)(this + 0x28);
    }
    if (this_00 != (CSimpleHash *)0x0) {
      local_res8[0] = 0;
      while( true ) {
        puVar5 = local_res8;
        lVar3 = CSimpleHash::FindNextItem(this_00,puVar5,&local_res10);
        uVar1 = local_res8[0];
        uVar4 = (ulong)puVar5;
        if (lVar3 < 0) break;
        uVar4 = local_res8[0];
        lVar3 = CSimpleHash::RemoveItemByIndex(this_00,local_res8[0],(void **)0x0);
        pvVar2 = local_res10;
        if (lVar3 < 0) break;
        if (*(void **)((longlong)local_res10 + 0x18) != (void *)0x0) {
          operator_delete(*(void **)((longlong)local_res10 + 0x18));
        }
        operator_delete(pvVar2);
        local_res8[0] = uVar1 + 1;
      }
      CSimpleHash::_scalar_deleting_destructor_(this_00,uVar4);
      if (uVar6 == 0) {
        *(undefined8 *)(this + 0x20) = 0;
        uVar6 = 1;
        goto LAB_1400054d4;
      }
      *(undefined8 *)(this + 0x28) = 0;
    }
    uVar6 = uVar6 + 1;
    if (1 < uVar6) {
      operator_delete(*(void **)(this + 0x58));
      *(undefined8 *)(this + 0x58) = 0;
      operator_delete(*(void **)(this + 0xb0));
      *(undefined8 *)(this + 0xb0) = 0;
      return;
    }
  } while( true );
}



===== ~CUsbHubPdoRequest @ 14000559c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl CUsbHubPdoRequest::~CUsbHubPdoRequest(void) __ptr64 */

void __thiscall CUsbHubPdoRequest::~CUsbHubPdoRequest(CUsbHubPdoRequest *this)

{
  *(undefined ***)this = &_vftable_;
  if ((*(longlong *)(this + 0x10) == 0) && (*(undefined8 **)(this + 0x80) != (undefined8 *)0x0)) {
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,**(undefined8 **)(this + 0x80),0,0x8b0,
               "clientcore\\termsrv\\devices\\urbdr\\busdriver\\buspdo.cpp");
  }
  return;
}



===== `scalar_deleting_destructor' @ 1400055fc =====

/* public: void * __ptr64 __cdecl CSimpleHash::`scalar deleting destructor'(unsigned int) __ptr64 */

void * __thiscall CSimpleHash::_scalar_deleting_destructor_(CSimpleHash *this,uint param_1)

{
  operator_delete(*(void **)(this + 8));
  operator_delete(this);
  return this;
}



===== `scalar_deleting_destructor' @ 140005628 =====

/* public: void * __ptr64 __cdecl CUsbHubPdoRequest_QueryBusFrame::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CUsbHubPdoRequest_QueryBusFrame::_scalar_deleting_destructor_
          (CUsbHubPdoRequest_QueryBusFrame *this,uint param_1)

{
  CUsbHubPdoRequest::~CUsbHubPdoRequest((CUsbHubPdoRequest *)this);
  ExFreePoolWithTag(this,0);
  return this;
}



===== CompleteRequest @ 140005658 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CUsbHubOrderRequestCompletion::CompleteRequest(struct WDFREQUEST__ *
   __ptr64,unsigned long,long,unsigned __int64) __ptr64 */

void __thiscall
CUsbHubOrderRequestCompletion::CompleteRequest
          (CUsbHubOrderRequestCompletion *this,WDFREQUEST__ *param_1,ulong param_2,long param_3,
          __uint64 param_4)

{
  int iVar1;
  CUsbHubOrderRequestCompletion *pCVar2;
  longlong *plVar3;
  code *pcVar4;
  CUsbHubOrderRequestCompletion *pCVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 *puVar8;
  WDFREQUEST__ *pWVar9;
  undefined **ppuVar10;
  undefined4 in_register_00000084;
  ulonglong uVar11;
  
  if (param_2 < *(uint *)(this + 0x10)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,
               &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,param_2);
    }
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,param_3,param_4);
  }
  else if (param_2 == *(uint *)(this + 0x10)) {
    uVar11 = (ulonglong)(uint)param_3;
    (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,uVar11,param_4);
    ppuVar10 = &WPP_GLOBAL_Control;
    pCVar5 = *(CUsbHubOrderRequestCompletion **)this;
    while( true ) {
      *(int *)(this + 0x10) = *(int *)(this + 0x10) + 1;
      if (pCVar5 == this) break;
      iVar1 = *(int *)(pCVar5 + -8);
      pCVar2 = *(CUsbHubOrderRequestCompletion **)pCVar5;
      if (*(int *)(this + 0x10) != iVar1) {
        return;
      }
      if ((*(CUsbHubOrderRequestCompletion **)(pCVar2 + 8) != pCVar5) ||
         (plVar3 = *(longlong **)(pCVar5 + 8), (CUsbHubOrderRequestCompletion *)*plVar3 != pCVar5))
      goto LAB_14000584f;
      *plVar3 = (longlong)pCVar2;
      *(longlong **)(pCVar2 + 8) = plVar3;
      param_1 = *(WDFREQUEST__ **)(pCVar5 + -0x10);
      pWVar9 = param_1;
      lVar6 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_qDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pWVar9,uVar11,param_1,(char)iVar1,
                   (char)param_2);
      }
      uVar11 = (ulonglong)*(uint *)(lVar6 + 0x30);
      (**(code **)(WdfFunctions_01015 + 0x848))
                (WdfDriverGlobals,param_1,uVar11,*(undefined8 *)(lVar6 + 0x38));
      pCVar5 = pCVar2;
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_1,
                 CONCAT44(in_register_00000084,param_2),param_1,(char)param_2,(char)param_3);
    }
    for (ppuVar10 = *(undefined ***)this;
        ((CUsbHubOrderRequestCompletion *)ppuVar10 != this &&
        (*(uint *)((longlong)ppuVar10 + -8) <= param_2)); ppuVar10 = (undefined **)*ppuVar10) {
    }
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_1);
    lVar6 = *(longlong *)(lVar7 + 0xb8);
    *(WDFREQUEST__ **)(lVar6 + 8) = param_1;
    *(ulonglong *)(lVar6 + 0x10) = (ulonglong)param_2;
    param_1 = (WDFREQUEST__ *)(lVar6 + 0x18);
    *(long *)(lVar7 + 0x30) = param_3;
    *(__uint64 *)(lVar7 + 0x38) = param_4;
    puVar8 = *(undefined8 **)((longlong)ppuVar10 + 8);
    if ((CUsbHubOrderRequestCompletion *)*puVar8 != (CUsbHubOrderRequestCompletion *)ppuVar10) {
LAB_14000584f:
      pcVar4 = (code *)swi(0x29);
      puVar8 = (undefined8 *)(*pcVar4)(3);
    }
    *(undefined ***)param_1 = ppuVar10;
    *(undefined8 **)(param_1 + 8) = puVar8;
    *puVar8 = param_1;
    *(WDFREQUEST__ **)((longlong)ppuVar10 + 8) = param_1;
  }
  return;
}



===== CompleteRequestIoControl @ 140005890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl CUsbHubPdoRequest::CompleteRequestIoControl(long,unsigned long,char
   * __ptr64,unsigned long) __ptr64 */

void __thiscall
CUsbHubPdoRequest::CompleteRequestIoControl
          (CUsbHubPdoRequest *this,long param_1,ulong param_2,char *param_3,ulong param_4)

{
  int iVar1;
  ulonglong uVar2;
  int iVar3;
  
  uVar2 = (ulonglong)param_2;
  if (*(longlong *)(this + 0x10) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
  }
  if (param_1 < 0) {
    iVar3 = -0x3fffffff;
    if ((param_1 & 0xffffU) == 0x7a) {
      iVar3 = -0x3fffffdd;
    }
  }
  else {
    iVar3 = 0;
  }
  if ((((*(void **)(this + 0x20) != (void *)0x0) && (param_3 != (char *)0x0)) && (param_4 != 0)) &&
     (((iVar3 + 0x80000000U & 0x80000000) != 0 || (iVar3 == -0x3fffffdd)))) {
    if (*(uint *)(this + 0x28) < param_4) {
      param_4 = *(uint *)(this + 0x28);
    }
    memmove(*(void **)(this + 0x20),param_3,(ulonglong)param_4);
    if (param_2 < param_4) {
      uVar2 = (ulonglong)param_4;
    }
  }
  if ((iVar1 == -0x3ffffee0) && (this[0x49] == (CUsbHubPdoRequest)0x0)) {
    *(ulonglong *)(this + 0x40) = uVar2;
    this[0x48] = (CUsbHubPdoRequest)0x1;
    *(int *)(this + 0x38) = iVar3;
  }
  else if (*(longlong *)(this + 0x10) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x848))
              (WdfDriverGlobals,*(longlong *)(this + 0x10),iVar3,uVar2);
  }
  return;
}



===== CompleteRequestIoControl @ 1400059b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl
   CUsbHubPdoRequest_QueryBusFrame::CompleteRequestIoControl(long,unsigned long,char *
   __ptr64,unsigned long) __ptr64 */

void __thiscall
CUsbHubPdoRequest_QueryBusFrame::CompleteRequestIoControl
          (CUsbHubPdoRequest_QueryBusFrame *this,long param_1,ulong param_2,char *param_3,
          ulong param_4)

{
  uint uVar1;
  
  uVar1 = param_1;
  CUsbHubPdoRequest::CompleteRequestIoControl
            ((CUsbHubPdoRequest *)this,param_1,param_2,param_3,param_4);
  if ((-1 < param_1) && (param_4 == 4)) {
    (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,**(undefined8 **)(this + 0x80));
    CUsbHubPdo::UpdateBusFrame(*(CUsbHubPdo **)(this + 0x80),*(ulong *)(this + 0x88),'\x01');
    uVar1 = (uint)**(undefined8 **)(this + 0x80);
    (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals);
  }
  if (this != (CUsbHubPdoRequest_QueryBusFrame *)0x0) {
    _scalar_deleting_destructor_(this,uVar1);
  }
  return;
}



===== CompleteRequestUrb @ 140005a5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CUsbHubPdoRequest::CompleteRequestUrb(unsigned char * __ptr64,unsigned
   long,long,char * __ptr64,unsigned long) __ptr64 */

void __thiscall
CUsbHubPdoRequest::CompleteRequestUrb
          (CUsbHubPdoRequest *this,uchar *param_1,ulong param_2,long param_3,char *param_4,
          ulong param_5)

{
  byte bVar1;
  int iVar2;
  longlong lVar3;
  CSimpleHash *this_00;
  CUsbHubOrderRequestCompletion *this_01;
  undefined8 uVar4;
  uchar uVar5;
  undefined1 uVar6;
  ushort uVar7;
  int iVar8;
  long lVar9;
  uint uVar10;
  bool bVar11;
  undefined8 in_stack_ffffffffffffff98;
  undefined4 uVar12;
  ulong local_48;
  int local_44;
  void *local_40;
  
  uVar12 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);
  if (*(longlong *)(this + 0x10) == 0) {
    iVar8 = 0;
  }
  else {
    iVar8 = (**(code **)(WdfFunctions_01015 + 0x800))(WdfDriverGlobals);
  }
  lVar3 = *(longlong *)(this + 0x80);
  local_44 = iVar8;
  (**(code **)(*(longlong *)(this + 0x50) + 0x10))
            (this + 0x50,param_1,param_2,param_4,CONCAT44(uVar12,param_5),
             *(undefined8 *)(lVar3 + 0x20),*(undefined8 *)(lVar3 + 0x28));
  lVar3 = *(longlong *)(this + 0x20);
  if ((-1 < *(int *)(lVar3 + 4)) && (*(short *)(lVar3 + 2) == 10)) {
    CUsbHubPdo::UpdateBusFrame(*(CUsbHubPdo **)(this + 0x80),*(ulong *)(lVar3 + 0x80),'\0');
  }
  lVar3 = *(longlong *)(this + 0x20);
  if (((-1 < *(int *)(lVar3 + 4)) && (*(short *)(lVar3 + 2) == 0)) || (*(short *)(lVar3 + 2) == 1))
  {
    local_40 = (void *)0x0;
    local_48 = 0;
    this_00 = *(CSimpleHash **)(*(longlong *)(this + 0x80) + 0x28);
    iVar2 = *(int *)(*(longlong *)(this + 0x80) + 0x50);
    lVar9 = CSimpleHash::FindNextItem(this_00,&local_48,&local_40);
    if (-1 < lVar9) {
      do {
        *(bool *)((longlong)local_40 + 0x24) = iVar2 != 0;
        if (*(int *)((longlong)local_40 + 4) == 1) {
          if (iVar2 == 0) {
            bVar1 = *(byte *)((longlong)local_40 + 3);
            if ((byte)(bVar1 - 2) < 2) {
              uVar7 = 2;
            }
            else if ((byte)(bVar1 - 4) < 4) {
              uVar7 = 4;
            }
            else if ((byte)(bVar1 - 8) < 8) {
              uVar7 = 8;
            }
            else {
              if (0xf < (byte)(bVar1 - 0x10)) {
                bVar11 = bVar1 < 0x20;
                goto LAB_140005c09;
              }
              uVar7 = 0x10;
            }
          }
          else {
            bVar1 = *(byte *)((longlong)local_40 + 3);
            if ((byte)(bVar1 - 1) < 6) {
              uVar7 = bVar1 - 1 ^ 2;
            }
            else {
              bVar11 = bVar1 < 7;
LAB_140005c09:
              uVar7 = 0x20;
              if (bVar11) {
                uVar7 = 1;
              }
            }
          }
          *(ushort *)((longlong)local_40 + 0x22) = uVar7;
        }
        if (*(char *)((longlong)local_40 + 0x20) == '\x01') {
          *(undefined1 *)((longlong)local_40 + 0x25) = 1;
        }
        local_48 = local_48 + 1;
        lVar9 = CSimpleHash::FindNextItem(this_00,&local_48,&local_40);
      } while (-1 < lVar9);
      iVar8 = local_44;
    }
  }
  uVar6 = 2;
  uVar10 = param_3 >> 0x1f & 0xc0000001;
  if ((iVar8 == -0x3ffffee0) && (this[0x49] == (CUsbHubPdoRequest)0x0)) {
    this[0x48] = (CUsbHubPdoRequest)0x1;
    *(uint *)(this + 0x38) = uVar10;
    *(undefined8 *)(this + 0x40) = 0;
  }
  else if (*(longlong *)(this + 0x10) != 0) {
    uVar5 = RequestIsIsochUrb(this);
    if (uVar5 == '\0') {
      uVar6 = KfRaiseIrql(uVar6);
      (**(code **)(WdfFunctions_01015 + 0x848))
                (WdfDriverGlobals,*(undefined8 *)(this + 0x10),uVar10,0);
      KeLowerIrql(uVar6);
    }
    else {
      this_01 = *(CUsbHubOrderRequestCompletion **)(*(longlong *)(this + 0x30) + 0x18);
      uVar4 = **(undefined8 **)(this + 0x80);
      (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,uVar4);
      uVar6 = KfRaiseIrql(2);
      CUsbHubOrderRequestCompletion::CompleteRequest
                (this_01,*(WDFREQUEST__ **)(this + 0x10),*(ulong *)(this + 0x28),uVar10,0);
      KeLowerIrql(uVar6);
      (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,uVar4);
    }
  }
  return;
}



===== CreateInstance @ 140005d8c =====

/* public: static long __cdecl CUsbHubPdo::CreateInstance(void * __ptr64,class CUsbHub *
   __ptr64,struct WDFDEVICE__ * __ptr64,struct ITsUsbDevice * __ptr64,unsigned long,unsigned
   long,struct _USB_DEVICE_CAPABILITIES * __ptr64,class CUsbHubPdo * __ptr64 * __ptr64) */

long __cdecl
CUsbHubPdo::CreateInstance
          (void *param_1,CUsbHub *param_2,WDFDEVICE__ *param_3,ITsUsbDevice *param_4,ulong param_5,
          ulong param_6,_USB_DEVICE_CAPABILITIES *param_7,CUsbHubPdo **param_8)

{
  long lVar1;
  
  if (param_1 == (void *)0x0) {
    lVar1 = -0x3fffffe9;
  }
  else {
    *(undefined8 *)param_1 = 0;
    *(undefined8 *)((longlong)param_1 + 8) = 0;
    *(undefined8 *)((longlong)param_1 + 0x10) = 0;
    *(undefined8 *)((longlong)param_1 + 0x18) = 0;
    *(undefined8 *)((longlong)param_1 + 0x20) = 0;
    *(undefined8 *)((longlong)param_1 + 0x28) = 0;
    *(undefined8 *)((longlong)param_1 + 0x30) = 0;
    *(undefined1 *)((longlong)param_1 + 0x38) = 0;
    *(undefined8 *)((longlong)param_1 + 0x58) = 0;
    *(undefined4 *)((longlong)param_1 + 0x60) = 0;
    *(undefined1 *)((longlong)param_1 + 0x68) = 0;
    *(undefined4 *)((longlong)param_1 + 0x78) = 0;
    *(undefined8 *)((longlong)param_1 + 0x80) = 0;
    *(undefined4 *)((longlong)param_1 + 0x88) = 0;
    *(undefined8 *)((longlong)param_1 + 0x90) = 0;
    *(undefined8 *)((longlong)param_1 + 0x98) = 0;
    *(undefined8 *)((longlong)param_1 + 0xa0) = 0;
    *(undefined8 *)((longlong)param_1 + 0xa8) = 0;
    *(undefined8 *)((longlong)param_1 + 0xb0) = 0;
    *(undefined4 *)((longlong)param_1 + 0xb8) = 0;
    *(undefined8 *)((longlong)param_1 + 0x70) = 0;
    *(undefined8 *)((longlong)param_1 + 0x3c) = 0;
    *(undefined8 *)((longlong)param_1 + 0x44) = 0;
    *(undefined8 *)((longlong)param_1 + 0x4c) = 0;
    *(undefined4 *)((longlong)param_1 + 0x54) = 0;
    lVar1 = Initialize(param_1,param_2,param_3,param_4,param_7,param_5,param_6);
    if (lVar1 < 0) {
      ~CUsbHubPdo(param_1);
    }
    else {
      *param_8 = param_1;
      lVar1 = 0;
    }
  }
  return lVar1;
}



===== CreateInstance @ 140005e80 =====

/* public: static long __cdecl CUsbHubPdoRequest::CreateInstance(void * __ptr64,struct WDFREQUEST__
   * __ptr64,class CUsbHubPdo * __ptr64,void * __ptr64,unsigned long,class CUsbHubPdoRequest *
   __ptr64 * __ptr64) */

long __cdecl
CUsbHubPdoRequest::CreateInstance
          (void *param_1,WDFREQUEST__ *param_2,CUsbHubPdo *param_3,void *param_4,ulong param_5,
          CUsbHubPdoRequest **param_6)

{
  long lVar1;
  
  if (param_1 == (void *)0x0) {
    lVar1 = -0x3fffffe9;
  }
  else {
    *(undefined4 *)((longlong)param_1 + 8) = 0;
    *(undefined8 *)((longlong)param_1 + 0x10) = 0;
    *(undefined4 *)((longlong)param_1 + 0x18) = 0xffffffff;
    *(undefined2 *)((longlong)param_1 + 0x48) = 0;
    *(undefined ***)param_1 = &_vftable_;
    *(undefined ***)((longlong)param_1 + 0x50) = &CTsUrb::_vftable_;
    *(undefined8 *)((longlong)param_1 + 0x80) = 0;
    lVar1 = Initialize(param_1,param_2,param_3,param_4,param_5);
    if (lVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,
                 &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,lVar1);
      }
      ~CUsbHubPdoRequest(param_1);
    }
    else {
      lVar1 = 0;
      *param_6 = param_1;
    }
  }
  return lVar1;
}



===== CreateInstance @ 140005f38 =====

/* public: static long __cdecl CUsbHubPdoRequest::CreateInstance(void * __ptr64,struct WDFREQUEST__
   * __ptr64,class CUsbHubPdo * __ptr64,struct _URB * __ptr64,class CUsbHubPdoRequest * __ptr64 *
   __ptr64) */

long __cdecl
CUsbHubPdoRequest::CreateInstance
          (void *param_1,WDFREQUEST__ *param_2,CUsbHubPdo *param_3,_URB *param_4,
          CUsbHubPdoRequest **param_5)

{
  long lVar1;
  
  if (param_1 == (void *)0x0) {
    lVar1 = -0x3fffffe9;
  }
  else {
    *(undefined4 *)((longlong)param_1 + 8) = 0;
    *(undefined8 *)((longlong)param_1 + 0x10) = 0;
    *(undefined4 *)((longlong)param_1 + 0x18) = 0xffffffff;
    *(undefined2 *)((longlong)param_1 + 0x48) = 0;
    *(undefined ***)param_1 = &_vftable_;
    *(undefined ***)((longlong)param_1 + 0x50) = &CTsUrb::_vftable_;
    *(undefined8 *)((longlong)param_1 + 0x80) = 0;
    lVar1 = Initialize(param_1,param_2,param_3,param_4);
    if (lVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,
                 &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,lVar1);
      }
      ~CUsbHubPdoRequest(param_1);
    }
    else {
      lVar1 = 0;
      *param_5 = param_1;
    }
  }
  return lVar1;
}



===== CreateInstance @ 140005fe8 =====

/* public: static long __cdecl CUsbHubPdoRequest_QueryBusFrame::CreateInstance(class CUsbHubPdo *
   __ptr64,class CUsbHubPdoRequest_QueryBusFrame * __ptr64 * __ptr64) */

long __cdecl
CUsbHubPdoRequest_QueryBusFrame::CreateInstance
          (CUsbHubPdo *param_1,CUsbHubPdoRequest_QueryBusFrame **param_2)

{
  long lVar1;
  CUsbHubPdoRequest *this;
  uint uVar2;
  
  this = (CUsbHubPdoRequest *)ExAllocatePool2(0x40,0x90,0x30555354);
  if (this == (CUsbHubPdoRequest *)0x0) {
    lVar1 = -0x3fffffe9;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x36,
               &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,0xc0000017);
    }
  }
  else {
    *(undefined4 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x10) = 0;
    *(undefined4 *)(this + 0x18) = 0xffffffff;
    uVar2 = 0;
    *(undefined2 *)(this + 0x48) = 0;
    *(undefined ***)(this + 0x50) = &CTsUrb::_vftable_;
    *(undefined8 *)(this + 0x80) = 0;
    *(undefined4 *)(this + 0x88) = 0;
    *(undefined ***)this = &_vftable_;
    lVar1 = CUsbHubPdoRequest::Initialize(this,(WDFREQUEST__ *)0x0,param_1,this + 0x88,4);
    if (lVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar2 = 0x37;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
                 &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,lVar1);
      }
      _scalar_deleting_destructor_((CUsbHubPdoRequest_QueryBusFrame *)this,uVar2);
    }
    else {
      lVar1 = 0;
      *param_2 = (CUsbHubPdoRequest_QueryBusFrame *)this;
    }
  }
  return lVar1;
}



===== EvtDeviceContextCleanup @ 14000610c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CUsbHubPdo::EvtDeviceContextCleanup(void) __ptr64 */

void __thiscall CUsbHubPdo::EvtDeviceContextCleanup(CUsbHubPdo *this)

{
  longlong *plVar1;
  
  if (*(longlong **)(this + 0x30) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(this + 0x30) + 0x10))();
    *(undefined8 *)(this + 0x30) = 0;
  }
  if (*(longlong **)(this + 8) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(this + 8) + 0x10))();
    *(undefined8 *)(this + 8) = 0;
  }
  if (*(longlong *)(this + 0x18) != 0) {
    plVar1 = (longlong *)
             (**(code **)(WdfFunctions_01015 + 0x650))
                       (WdfDriverGlobals,*(longlong *)(this + 0x18),
                        PTR__WDF_CSession_TYPE_INFO_14001d018);
    (**(code **)(*plVar1 + 0x10))(plVar1);
    *(undefined8 *)(this + 0x18) = 0;
  }
  if (*(longlong *)(this + 0x90) != 0) {
    (**(code **)(WdfFunctions_01015 + 0xa00))(WdfDriverGlobals,*(longlong *)(this + 0x90),0);
  }
  return;
}



===== EvtDevicePrepareHardware @ 1400061c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl CUsbHubPdo::EvtDevicePrepareHardware(void) __ptr64 */

long __thiscall CUsbHubPdo::EvtDevicePrepareHardware(CUsbHubPdo *this)

{
  int iVar1;
  undefined8 uVar2;
  CUsbHubPdo *pCVar3;
  undefined2 uVar4;
  undefined *puVar5;
  undefined1 auStack_c8 [32];
  wchar_t local_78 [38];
  undefined2 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_c8;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,*(undefined8 *)this);
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,*(undefined8 *)(this + 0x18),PTR__WDF_CSession_TYPE_INFO_14001d018);
  puVar5 = (undefined *)0x4e;
  iVar1 = IoGetDeviceProperty(uVar2,6,0x4e,local_78);
  if (iVar1 < 0) {
    pCVar3 = (CUsbHubPdo *)WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000639c;
    uVar4 = 0x21;
LAB_140006288:
    pCVar3 = *(CUsbHubPdo **)(WPP_GLOBAL_Control + 0x18);
    puVar5 = &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids;
    WPP_SF_D(pCVar3,uVar4,&WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,iVar1);
  }
  else {
    local_2c = 0;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar5 = &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids;
      WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
               &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,local_78);
    }
    iVar1 = (**(code **)(**(longlong **)(this + 8) + 0x20))
                      (*(longlong **)(this + 8),*(undefined8 *)(this + 0x30));
    if (iVar1 < 0) {
      pCVar3 = (CUsbHubPdo *)WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        pCVar3 = *(CUsbHubPdo **)(WPP_GLOBAL_Control + 0x18);
        puVar5 = &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids;
        WPP_SF_D(pCVar3,0x23,&WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,iVar1);
      }
      iVar1 = -0x3fffffff;
      goto LAB_14000639c;
    }
    this[0x38] = (CUsbHubPdo)0x1;
    if (*(longlong *)(this + 0xb0) != 0) {
      puVar5 = (undefined *)0x0;
      iVar1 = IoSetDevicePropertyData(uVar2,&DEVPKEY_Device_Text_Description,0,1);
      if (iVar1 < 0) {
        pCVar3 = (CUsbHubPdo *)WPP_GLOBAL_Control;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000639c;
        uVar4 = 0x24;
        goto LAB_140006288;
      }
    }
    pCVar3 = this;
    PostQueryBusTimeWorkItem(this);
    iVar1 = 0;
    this[0x62] = (CUsbHubPdo)0x1;
  }
LAB_14000639c:
  if ((Microsoft_Windows_TerminalServices_ServerUSBDevicesEnableBits & 0x20) != 0) {
    McTemplateK0pd_EtwWriteTransfer
              (pCVar3,&EVENT_NOTIFY_DEVICE_STARTING,puVar5,*(undefined8 *)(this + 8),(char)iVar1);
  }
  return iVar1;
}



===== EvtDeviceReleaseHardware @ 1400063f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl CUsbHubPdo::EvtDeviceReleaseHardware(void) __ptr64 */

long __thiscall CUsbHubPdo::EvtDeviceReleaseHardware(CUsbHubPdo *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (this[0x38] != (CUsbHubPdo)0x0) {
    (**(code **)(**(longlong **)(this + 8) + 0x20))(*(longlong **)(this + 8),0);
    this[0x38] = (CUsbHubPdo)0x0;
  }
  uVar2 = 10000000;
  this[0x62] = (CUsbHubPdo)0x0;
  uVar1 = WdfDriverGlobals;
  (**(code **)(WdfFunctions_01015 + 0x9f8))(WdfDriverGlobals,*(undefined8 *)(this + 0x90));
  if ((Microsoft_Windows_TerminalServices_ServerUSBDevicesEnableBits & 0x20) != 0) {
    McTemplateK0pd_EtwWriteTransfer
              (uVar1,&EVENT_NOTIFY_DEVICE_STOPPING,uVar2,*(undefined8 *)(this + 8),0);
  }
  return 0;
}



===== EvtDeviceResourcesQuery @ 140006478 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl CUsbHubPdo::EvtDeviceResourcesQuery(void) __ptr64 */

long __thiscall CUsbHubPdo::EvtDeviceResourcesQuery(CUsbHubPdo *this)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined4 local_res8 [2];
  
  lVar2 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,*(undefined8 *)(this + 0x18),
                     PTR__WDF_CSession_TYPE_INFO_14001d018);
  local_res8[0] = *(undefined4 *)(lVar2 + 0x20);
  uVar3 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,*(undefined8 *)this);
  iVar1 = IoSetDevicePropertyData(uVar3,&DEVPKEY_Device_SessionId,0,1,7,4,local_res8);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
               &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,iVar1);
    }
  }
  else {
    iVar1 = MimicUsbHub(this);
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



===== EvtDeviceSurpriseRemoval @ 140006570 =====

/* public: void __cdecl CUsbHubPdo::EvtDeviceSurpriseRemoval(void) __ptr64 */

void __thiscall CUsbHubPdo::EvtDeviceSurpriseRemoval(CUsbHubPdo *this)

{
  this[99] = (CUsbHubPdo)0x1;
  return;
}



===== EvtIoInternalDeviceControl @ 14000657c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CUsbHubPdo::EvtIoInternalDeviceControl(struct WDFREQUEST__ *
   __ptr64,unsigned __int64,unsigned __int64,unsigned long) __ptr64 */

void __thiscall
CUsbHubPdo::EvtIoInternalDeviceControl
          (CUsbHubPdo *this,WDFREQUEST__ *param_1,__uint64 param_2,__uint64 param_3,ulong param_4)

{
  _URB *p_Var1;
  longlong lVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong in_stack_ffffffffffffffd8;
  
  if (((this[0x62] == (CUsbHubPdo)0x0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control))
     && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
            &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids);
  }
  if (param_4 < 0x220028) {
    if (param_4 == 0x220027) {
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc000000d);
      return;
    }
    if (param_4 == 0x220003) {
      lVar2 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_1);
      p_Var1 = *(_URB **)(*(longlong *)(lVar2 + 0xb8) + 8);
      if (p_Var1 != (_URB *)0x0) {
        EvtIoInternalDeviceControl_Urb(this,param_1,p_Var1);
        return;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids);
      }
      uVar4 = 0xc000000d;
      goto LAB_1400066d2;
    }
    if (param_4 == 0x220007) {
      uVar3 = 0x220007;
LAB_14000664d:
      EvtIoInternalDeviceControl_UsbIoControl
                (this,param_1,uVar3,(void *)(ulonglong)param_4,in_stack_ffffffffffffffd8,(void *)0x0
                 ,0);
      return;
    }
    if (param_4 == 0x220013) {
      EvtIoInternalDeviceControl_GetPortStatus(this,param_1);
      return;
    }
    if (param_4 != 0x220017) {
      if (param_4 == 0x22001b) {
        EvtIoInternalDeviceControl_GetHubCount(this,param_1);
        return;
      }
      if (param_4 == 0x22001f) {
        uVar3 = 0x22001f;
        goto LAB_14000664d;
      }
      if (param_4 == 0x220020) {
        EvtIoInternalDeviceControl_GetHubName(this,param_1);
        return;
      }
    }
  }
  else {
    if (param_4 == 0x220420) {
      EvtIoInternalDeviceControl_GetBusInfo(this,param_1);
      return;
    }
    if (param_4 == 0x220424) {
      EvtIoInternalDeviceControl_GetControllerName(this,param_1);
      return;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
             &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,param_4);
  }
  uVar4 = 0xc00000bb;
LAB_1400066d2:
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,uVar4,0);
  return;
}



===== EvtIsochFrameTimer @ 14000679c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CUsbHubPdo::EvtIsochFrameTimer(void) __ptr64 */

void __thiscall CUsbHubPdo::EvtIsochFrameTimer(CUsbHubPdo *this)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint local_res10 [2];
  ulong local_res18 [2];
  undefined8 local_res20;
  
  local_res20 = 0;
  iVar3 = 0;
  local_res18[0] = 0;
  local_res10[0] = 0;
  while( true ) {
    (**(code **)(WdfFunctions_01015 + 0x4c8))
              (WdfDriverGlobals,*(undefined8 *)(this + 0xa8),local_res10,0);
    if (local_res10[0] == 0) {
      return;
    }
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x4f0))
                      (WdfDriverGlobals,*(undefined8 *)(this + 0xa8),&local_res20);
    if (iVar2 < 0) {
      return;
    }
    lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,local_res20,PTR__WDF_CUsbHubPdoRequest_TYPE_INFO_14001d108);
    iVar2 = *(int *)(lVar1 + 0x2c);
    QueryBusTime(this,local_res18);
    if (local_res10[0] < 2) {
      iVar2 = (iVar2 - local_res18[0]) + -2;
    }
    else {
      iVar2 = (iVar2 - *(int *)(this + 0x54)) - local_res18[0];
    }
    if (0 < iVar2) break;
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_res20,0);
    iVar3 = iVar3 + 1;
  }
  (**(code **)(WdfFunctions_01015 + 0x8d8))(WdfDriverGlobals,local_res20);
  (**(code **)(WdfFunctions_01015 + 0x9f8))
            (WdfDriverGlobals,*(undefined8 *)(this + 0xa0),(longlong)iVar2 * -10000);
  if (iVar3 != 0) {
    return;
  }
  if (iVar2 < 0xf) {
    return;
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return;
  }
  if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
    return;
  }
  WPP_SF_DDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x42,
             &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,local_res10[0],(char)iVar2,
             (char)local_res20);
  return;
}



===== EvtRequestCancel @ 140006920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl CUsbHubPdoRequest::EvtRequestCancel(void) __ptr64 */

void __thiscall CUsbHubPdoRequest::EvtRequestCancel(CUsbHubPdoRequest *this)

{
  CUsbHubOrderRequestCompletion *this_00;
  uchar uVar1;
  undefined1 uVar2;
  
  this[0x49] = (CUsbHubPdoRequest)0x1;
  if (*(int *)(this + 0x18) != -1) {
    (**(code **)(**(longlong **)(*(longlong *)(this + 0x80) + 8) + 0x18))();
  }
  if ((this[0x48] != (CUsbHubPdoRequest)0x0) && (*(longlong *)(this + 0x10) != 0)) {
    uVar1 = RequestIsIsochUrb(this);
    if (uVar1 == '\0') {
      uVar2 = KfRaiseIrql(2);
      (**(code **)(WdfFunctions_01015 + 0x848))
                (WdfDriverGlobals,*(undefined8 *)(this + 0x10),*(undefined4 *)(this + 0x38),
                 *(undefined8 *)(this + 0x40));
    }
    else {
      this_00 = *(CUsbHubOrderRequestCompletion **)(*(longlong *)(this + 0x30) + 0x18);
      uVar2 = KfRaiseIrql();
      CUsbHubOrderRequestCompletion::CompleteRequest
                (this_00,*(WDFREQUEST__ **)(this + 0x10),*(ulong *)(this + 0x28),
                 *(long *)(this + 0x38),*(__uint64 *)(this + 0x40));
    }
    KeLowerIrql(uVar2);
  }
  return;
}



===== EvtTimerWorkItem @ 140006a08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CUsbHubPdo::EvtTimerWorkItem(struct WDFWORKITEM__ * __ptr64) __ptr64 */

void __thiscall CUsbHubPdo::EvtTimerWorkItem(CUsbHubPdo *this,WDFWORKITEM__ *param_1)

{
  bool bVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int local_res8 [2];
  uint local_res10;
  int local_res18 [2];
  int local_res20 [2];
  undefined4 uVar6;
  undefined4 local_48 [6];
  
  local_res10 = 0;
  local_48[0] = 0;
  local_res8[0] = 0;
  local_res18[0] = 0;
  local_res20[0] = 0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0xf8))(WdfDriverGlobals,*(undefined8 *)this);
  bVar1 = false;
  if (this[99] == (CUsbHubPdo)0x0) {
    *(int *)(this + 0x88) = *(int *)(this + 0x88) + 1;
    uVar6 = (undefined4)((ulonglong)local_48 >> 0x20);
    uVar5 = 4;
    uVar4 = uVar3;
    iVar2 = IoGetDeviceProperty();
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,
                 &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,iVar2);
      }
      goto LAB_140006c85;
    }
    if ((local_res10 & 0xfffffffd) != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
                 &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,local_res10);
      }
      goto LAB_140006c85;
    }
    if (this[0x62] == (CUsbHubPdo)0x0) {
      if (299 < *(uint *)(this + 0x88)) {
        if ((Microsoft_Windows_TerminalServices_ServerUSBDevicesEnableBits & 4) != 0) {
          McTemplateK0p_EtwWriteTransfer
                    (uVar4,&EVENT_NOTIFY_DRIVER_LOAD_TIMEOUT,uVar5,*(undefined8 *)(this + 8));
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
                  &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids);
        }
        goto LAB_140006b6d;
      }
    }
    else {
LAB_140006b6d:
      bVar1 = true;
    }
    iVar2 = IoGetDevicePropertyData
                      (uVar3,&DEVPKEY_Device_InstallError,0,0,CONCAT44(uVar6,4),local_res8,
                       local_res18,local_res20);
    if (((iVar2 < 0) || (local_res18[0] != 4)) || (local_res20[0] != 0x17)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x30,
                 &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,iVar2);
      }
      if (!bVar1) goto LAB_140006c85;
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                 &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,local_res8[0]);
      }
      if (local_res8[0] + 0x1ffffdb8U < 2) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x32,
                  &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids);
        }
        (**(code **)(**(longlong **)(this + 8) + 0x50))(*(longlong **)(this + 8),0);
      }
    }
  }
  (**(code **)(WdfFunctions_01015 + 0xa00))(WdfDriverGlobals,*(undefined8 *)(this + 0x90),0);
LAB_140006c85:
  *(WDFWORKITEM__ **)(this + 0x98) = param_1;
  return;
}



===== EvtWdmIrpPreprocessCallback @ 140006ca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl CUsbHubPdo::EvtWdmIrpPreprocessCallback(struct _IRP * __ptr64) __ptr64 */

long __thiscall CUsbHubPdo::EvtWdmIrpPreprocessCallback(CUsbHubPdo *this,_IRP *param_1)

{
  char cVar1;
  long lVar2;
  
  cVar1 = *(char *)(*(longlong *)(param_1 + 0xb8) + 1);
  if (cVar1 == '\b') {
    lVar2 = EvtWdmIrpPreprocessCallback_QueryInterface(this,param_1);
  }
  else if (cVar1 == '\f') {
    lVar2 = EvtWdmIrpPreprocessCallback_QueryDeviceText(this,param_1);
  }
  else {
    param_1[0x43] = (_IRP)((char)param_1[0x43] + '\x01');
    *(longlong *)(param_1 + 0xb8) = *(longlong *)(param_1 + 0xb8) + 0x48;
    lVar2 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,*(undefined8 *)this);
  }
  return lVar2;
}



===== EvtWdmIrpPreprocessCallback_QueryDeviceText @ 140006d08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CUsbHubPdo::EvtWdmIrpPreprocessCallback_QueryDeviceText(struct _IRP *
   __ptr64) __ptr64 */

long __thiscall
CUsbHubPdo::EvtWdmIrpPreprocessCallback_QueryDeviceText(CUsbHubPdo *this,_IRP *param_1)

{
  int iVar1;
  undefined1 auVar2 [16];
  ulonglong uVar3;
  int iVar4;
  void *_Dst;
  undefined8 uVar5;
  void *_Dst_00;
  long lVar6;
  ulonglong _Size;
  uint local_res8 [2];
  void *local_res10;
  
  lVar6 = *(long *)(param_1 + 0x30);
  local_res8[0] = 0;
  local_res10 = (void *)0x0;
  iVar1 = *(int *)(*(longlong *)(param_1 + 0xb8) + 8);
  iVar4 = (**(code **)(**(longlong **)(this + 8) + 0x38))
                    (*(longlong **)(this + 8),iVar1,
                     *(undefined4 *)(*(longlong *)(param_1 + 0xb8) + 0x10),&local_res10,local_res8);
  if (-1 < iVar4) {
    if (local_res10 == (void *)0x0) goto LAB_140006e91;
    if ((local_res8[0] != 0) &&
       (*(short *)((longlong)local_res10 + (ulonglong)(local_res8[0] - 1) * 2) == 0)) {
      *(undefined2 *)((longlong)local_res10 + (ulonglong)(local_res8[0] - 1) * 2) = 0;
      uVar3 = (ulonglong)local_res8[0] * 2;
      if (uVar3 < 0x100000000) {
        if ((uint)uVar3 < 0x10000) {
          _Size = uVar3 & 0xffffffff;
          _Dst = (void *)ExAllocatePool2(0x100,uVar3 & 0xffffffff,0x30555354);
          if (_Dst == (void *)0x0) {
            lVar6 = -0x3fffffe9;
          }
          else {
            memmove(_Dst,local_res10,_Size);
            if (*(longlong *)(this + 0xb0) == 0) {
              auVar2._8_8_ = 0;
              auVar2._0_8_ = _Size >> 1;
              uVar5 = SUB168(ZEXT816(2) * auVar2,0);
              if (SUB168(ZEXT816(2) * auVar2,8) != 0) {
                uVar5 = 0xffffffffffffffff;
              }
              _Dst_00 = (void *)ExAllocatePoolWithTag(0x200,uVar5,0x72447244);
              *(void **)(this + 0xb0) = _Dst_00;
              if (_Dst_00 != (void *)0x0) {
                *(uint *)(this + 0xb8) = (uint)uVar3;
                memmove(_Dst_00,local_res10,_Size);
              }
            }
            *(void **)(param_1 + 0x38) = _Dst;
            lVar6 = 0;
            if ((iVar1 == 0) &&
               ((Microsoft_Windows_TerminalServices_ServerUSBDevicesEnableBits & 0x20) != 0)) {
              McTemplateK0pz_EtwWriteTransfer();
            }
          }
        }
        else {
          lVar6 = -0x3fffffff;
        }
      }
      else {
        lVar6 = -0x3fffff6b;
      }
    }
  }
  if (local_res10 != (void *)0x0) {
    RIM_USER_FREE(local_res10);
  }
LAB_140006e91:
  *(long *)(param_1 + 0x30) = lVar6;
  IofCompleteRequest(param_1,0);
  return lVar6;
}



===== EvtWdmIrpPreprocessCallback_QueryInterface @ 140006ec8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CUsbHubPdo::EvtWdmIrpPreprocessCallback_QueryInterface(struct _IRP *
   __ptr64) __ptr64 */

long __thiscall
CUsbHubPdo::EvtWdmIrpPreprocessCallback_QueryInterface(CUsbHubPdo *this,_IRP *param_1)

{
  longlong lVar1;
  undefined2 *_Dst;
  undefined4 *puVar2;
  long lVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_1 + 0xb8);
  lVar3 = -0x3fffff45;
  lVar4 = **(longlong **)(lVar1 + 8) + -0x45743de0b1a96a13;
  if (lVar4 == 0) {
    lVar4 = (*(longlong **)(lVar1 + 8))[1] + 0x29e74c15703ffe65;
  }
  if (lVar4 == 0) {
    if (0x3f < *(ushort *)(lVar1 + 0x10)) {
      _Dst = *(undefined2 **)(lVar1 + 0x18);
      memset(_Dst,0,0x40);
      *_Dst = 0x40;
      *(undefined8 *)(_Dst + 4) = *(undefined8 *)this;
      *(code **)(_Dst + 0x14) = PdUsbdQueryBusTime;
      *(code **)(_Dst + 0x18) = PdUsbdBusQueryBusInformation;
      *(code **)(_Dst + 0x1c) = PdUsbdBusQueryBusInformation;
      *(code **)(_Dst + 8) = CTsUrb::TsUrbCompletion;
      *(code **)(_Dst + 0xc) = CTsUrb::TsUrbCompletion;
      *(code **)(_Dst + 0x10) = PdUsbdGetUSBDIVersion;
      lVar3 = 0;
    }
    if (((*(int *)(this + 0x40) != 0) && (0x47 < *(ushort *)(lVar1 + 0x10))) &&
       (*(short *)(lVar1 + 0x12) != 0)) {
      puVar2 = *(undefined4 **)(lVar1 + 0x18);
      memset(puVar2,0,0x48);
      *puVar2 = 0x10048;
      *(undefined8 *)(puVar2 + 2) = *(undefined8 *)this;
      *(code **)(puVar2 + 8) = PdUsbdGetUSBDIVersion;
      *(code **)(puVar2 + 10) = PdUsbdQueryBusTime;
      *(code **)(puVar2 + 0xc) = PdUsbdBusQueryBusInformation;
      *(code **)(puVar2 + 0xe) = PdUsbdBusQueryBusInformation;
      *(code **)(puVar2 + 0x10) = PdUsbdIsDeviceHighSpeed;
      *(code **)(puVar2 + 4) = CTsUrb::TsUrbCompletion;
      *(code **)(puVar2 + 6) = CTsUrb::TsUrbCompletion;
      lVar3 = 0;
    }
    if (((1 < *(uint *)(this + 0x40)) && (0x4f < *(ushort *)(lVar1 + 0x10))) &&
       (1 < *(ushort *)(lVar1 + 0x12))) {
      puVar2 = *(undefined4 **)(lVar1 + 0x18);
      memset(puVar2,0,0x50);
      *puVar2 = 0x20050;
      *(undefined8 *)(puVar2 + 2) = *(undefined8 *)this;
      *(code **)(puVar2 + 8) = PdUsbdGetUSBDIVersion;
      *(code **)(puVar2 + 10) = PdUsbdQueryBusTime;
      *(code **)(puVar2 + 0xc) = PdUsbdBusQueryBusInformation;
      *(code **)(puVar2 + 0xe) = PdUsbdBusQueryBusInformation;
      *(code **)(puVar2 + 0x10) = PdUsbdIsDeviceHighSpeed;
      *(code **)(puVar2 + 0x12) = CRIMStream::Initialize;
      *(code **)(puVar2 + 4) = CTsUrb::TsUrbCompletion;
      *(code **)(puVar2 + 6) = CTsUrb::TsUrbCompletion;
      lVar3 = 0;
    }
    *(undefined8 *)(param_1 + 0x38) = 0;
    *(long *)(param_1 + 0x30) = lVar3;
    IofCompleteRequest(param_1,0);
  }
  else {
    param_1[0x43] = (_IRP)((char)param_1[0x43] + '\x01');
    *(longlong *)(param_1 + 0xb8) = lVar1 + 0x48;
    lVar3 = (**(code **)(WdfFunctions_01015 + 0x110))(WdfDriverGlobals,*(undefined8 *)this,param_1);
  }
  return lVar3;
}



===== GetTsUrb @ 1400070fc =====

/* public: union _TS_URB * __ptr64 __cdecl CUsbHubPdo::GetTsUrb(unsigned short) __ptr64 */

_TS_URB * __thiscall CUsbHubPdo::GetTsUrb(CUsbHubPdo *this,ushort param_1)

{
  longlong lVar1;
  
  if (*(ushort *)(this + 0x60) < param_1) {
    operator_delete(*(void **)(this + 0x58));
    *(undefined2 *)(this + 0x60) = 0;
    lVar1 = ExAllocatePoolWithTag(0x200,param_1,0x72447244);
    *(longlong *)(this + 0x58) = lVar1;
    if (lVar1 != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                 &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,(uint)param_1);
      }
      *(ushort *)(this + 0x60) = param_1;
    }
  }
  return *(_TS_URB **)(this + 0x58);
}



===== Initialize @ 1400071a0 =====

/* public: virtual long __cdecl CTsUrb::Initialize(struct _URB * __ptr64,class CSimpleHash *
   __ptr64,class CSimpleHash * __ptr64) __ptr64 */

long __thiscall
CTsUrb::Initialize(CTsUrb *this,_URB *param_1,CSimpleHash *param_2,CSimpleHash *param_3)

{
  return -0x3ffffff3;
}



===== Initialize @ 1400071b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl CUsbHubPdo::Initialize(class CUsbHub * __ptr64,struct WDFDEVICE__ *
   __ptr64,struct ITsUsbDevice * __ptr64,struct _USB_DEVICE_CAPABILITIES * __ptr64,unsigned
   long,unsigned long) __ptr64 */

long __thiscall
CUsbHubPdo::Initialize
          (CUsbHubPdo *this,CUsbHub *param_1,WDFDEVICE__ *param_2,ITsUsbDevice *param_3,
          _USB_DEVICE_CAPABILITIES *param_4,ulong param_5,ulong param_6)

{
  long lVar1;
  undefined8 uVar2;
  void *pvVar3;
  undefined2 uVar4;
  CTsRequestCompletion *pCVar5;
  undefined1 auStack_1e8 [32];
  CUsbHubPdo *local_1c8;
  CTsRequestCompletion *local_1b8;
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 local_178;
  code *pcStack_170;
  undefined8 local_168;
  ulonglong uStack_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  code *pcStack_140;
  undefined8 local_138;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined1 local_11b;
  code *local_f8;
  undefined4 local_d8;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1e8;
  local_1b8 = (CTsRequestCompletion *)0x0;
  local_158 = 0;
  local_180 = 0;
  local_138 = 0;
  local_178 = 0;
  pcStack_170 = (code *)0x0;
  local_168 = 0;
  uStack_160 = 0;
  local_1b0 = 0;
  uStack_1a8 = 0;
  local_1a0 = 0;
  uStack_198 = 0;
  local_190 = 0;
  uStack_188 = 0;
  local_148 = 0;
  pcStack_140 = (code *)0x0;
  uVar2 = (**(code **)(WdfFunctions_01015 + 0x6e8))(WdfDriverGlobals,param_2);
  *(WDFDEVICE__ **)this = param_2;
  (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,uVar2);
  pvVar3 = CUsbHub::ReferenceSession(param_1,param_5);
  if (pvVar3 == (void *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,param_5);
    }
    return -0x3ffffff3;
  }
  (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,uVar2);
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,pvVar3,PTR__WDF_CSession_TYPE_INFO_14001d018);
  *(void **)(this + 0x18) = pvVar3;
  *(ITsUsbDevice **)(this + 8) = param_3;
  (**(code **)(*(longlong *)param_3 + 8))(param_3);
  lVar1 = CSimpleHash::CreateInstance(0x10,(CSimpleHash **)(this + 0x10));
  if (lVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return lVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return lVar1;
    }
    uVar4 = 0x14;
  }
  else {
    local_b4 = 0;
    local_c8 = 0x30;
    local_c4 = 2;
    local_bc = 1;
    local_c0 = 1;
    local_ac = 1;
    local_b8 = 2;
    local_b0 = 2;
    local_a8 = 2;
    local_a4 = 2;
    local_a0 = 0xffffffff;
    local_9c = 0xffffffff;
    (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals,*(undefined8 *)this,&local_c8);
    memset(&local_98,0,0x50);
    local_7c = 5;
    uStack_68 = 4;
    local_64 = 4;
    local_98 = 0x50;
    local_90 = 2;
    local_8c = 2;
    local_80 = 2;
    local_5c = 7;
    local_58 = 0xffffffff;
    local_54 = 0xffffffff;
    local_50 = 0xffffffff;
    local_4c = 5;
    local_94 = 1;
    local_88 = 1;
    local_84 = 1;
    local_60 = 3;
    uStack_78 = 2;
    uStack_74 = 2;
    uStack_70 = 3;
    local_6c = 3;
    (**(code **)(WdfFunctions_01015 + 0x2a0))(WdfDriverGlobals,*(undefined8 *)this,&local_98);
    lVar1 = CSimpleHash::CreateInstance(10,(CSimpleHash **)(this + 0x20));
    if (lVar1 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return lVar1;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return lVar1;
      }
      uVar4 = 0x15;
    }
    else {
      lVar1 = CSimpleHash::CreateInstance(10,(CSimpleHash **)(this + 0x28));
      if (lVar1 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return lVar1;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return lVar1;
        }
        uVar4 = 0x16;
      }
      else {
        local_150 = 0;
        memset(&local_128,0,0x60);
        local_f8 = PdEvtIoInternalDeviceControl;
        local_1c8 = (CUsbHubPdo *)&local_150;
        local_128 = 0x60;
        local_120 = 2;
        local_11b = 1;
        local_124 = 2;
        local_d8 = 0xffffffff;
        lVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                          (WdfDriverGlobals,*(undefined8 *)this,&local_128,0);
        if (lVar1 < 0) {
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return lVar1;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
            return lVar1;
          }
          uVar4 = 0x19;
        }
        else {
          lVar1 = CTsRequestCompletion::CreateInstance(*(WDFDEVICE__ **)this,&local_1b8);
          if (lVar1 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                       &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,lVar1);
            }
            pCVar5 = local_1b8;
LAB_140007928:
            if (pCVar5 == (CTsRequestCompletion *)0x0) {
              return lVar1;
            }
            (**(code **)(*(longlong *)pCVar5 + 0x10))(pCVar5);
            return lVar1;
          }
          *(CTsRequestCompletion **)(this + 0x30) = local_1b8;
          pCVar5 = (CTsRequestCompletion *)0x0;
          local_178 = CONCAT44(local_178._4_4_,0x28);
          uStack_160 = uStack_160 & 0xffffffff00000000;
          uVar2 = *(undefined8 *)(param_4 + 8);
          local_168 = CONCAT35(local_168._5_3_,1000);
          local_1b0 = CONCAT44(local_1b0._4_4_,0x38);
          *(undefined8 *)(this + 0x3c) = *(undefined8 *)param_4;
          *(undefined8 *)(this + 0x44) = uVar2;
          *(undefined8 *)(this + 0x4c) = *(undefined8 *)(param_4 + 0x10);
          *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_4 + 0x18);
          pcStack_170 = PdEvtTimerFunc;
          local_190 = *(undefined8 *)this;
          uStack_198 = 0x100000001;
          lVar1 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                            (WdfDriverGlobals,&local_178,&local_1b0,this + 0x90);
          if (lVar1 < 0) {
            if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
              return lVar1;
            }
            if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
              return lVar1;
            }
            uVar4 = 0x1b;
          }
          else {
            local_148 = CONCAT44(local_148._4_4_,0x18);
            local_180 = 0;
            local_190 = *(undefined8 *)this;
            local_138 = CONCAT71(local_138._1_7_,1);
            local_1a0 = 0;
            uStack_188 = 0;
            pcStack_140 = PdEvtTimerWorkItem;
            uStack_1a8 = 0;
            local_1b0 = 0x38;
            uStack_198 = 0x100000001;
            lVar1 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                              (WdfDriverGlobals,&local_148,&local_1b0,this + 0x98);
            if (lVar1 < 0) {
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return lVar1;
              }
              if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
                return lVar1;
              }
              uVar4 = 0x1c;
            }
            else {
              if (*(int *)(this + 0x54) != 0) {
                local_158 = 0;
                uStack_160 = 0;
                pcStack_170 = PdEvtIsochFrameTimerFunc;
                local_180 = 0;
                local_190 = *(undefined8 *)this;
                local_1a0 = 0;
                local_178 = 0x28;
                uStack_188 = 0;
                uStack_1a8 = 0;
                local_168 = 0;
                local_1b0 = 0x38;
                uStack_198 = 0x400000003;
                lVar1 = (**(code **)(WdfFunctions_01015 + 0x9f0))
                                  (WdfDriverGlobals,&local_178,&local_1b0,this + 0xa0);
                if (lVar1 < 0) {
                  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                    return lVar1;
                  }
                  if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
                    return lVar1;
                  }
                  uVar4 = 0x1d;
                  goto LAB_140007348;
                }
                memset(&local_128,0,0x60);
                local_1c8 = this + 0xa8;
                local_128 = 0x60;
                local_120 = 2;
                local_124 = 3;
                local_11b = 0;
                lVar1 = (**(code **)(WdfFunctions_01015 + 0x4c0))
                                  (WdfDriverGlobals,*(undefined8 *)this,&local_128,0);
                if (lVar1 < 0) {
                  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                    return lVar1;
                  }
                  if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
                    return lVar1;
                  }
                  uVar4 = 0x1e;
                  goto LAB_140007348;
                }
              }
              lVar1 = (**(code **)(WdfFunctions_01015 + 0x268))
                                (WdfDriverGlobals,*(undefined8 *)this,
                                 &GUID_DEVINTERFACE_TSUSBHUBCHILD,0);
              if (-1 < lVar1) {
                (**(code **)(WdfFunctions_01015 + 0x9f8))
                          (WdfDriverGlobals,*(undefined8 *)(this + 0x90),10000000);
                lVar1 = 0;
                if (*(int *)(this + 0x54) == 0) {
                  return 0;
                }
                if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                  return 0;
                }
                if ((byte)WPP_GLOBAL_Control[0x29] < 5) {
                  return 0;
                }
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                         &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,*(int *)(this + 0x54));
                goto LAB_140007928;
              }
              if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
                return lVar1;
              }
              if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
                return lVar1;
              }
              uVar4 = 0x1f;
            }
          }
        }
      }
    }
  }
LAB_140007348:
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,lVar1);
  return lVar1;
}



===== Initialize @ 140007968 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: long __cdecl CUsbHubPdoRequest::Initialize(struct WDFREQUEST__ * __ptr64,class
   CUsbHubPdo * __ptr64,struct _URB * __ptr64) __ptr64 */

long __thiscall
CUsbHubPdoRequest::Initialize
          (CUsbHubPdoRequest *this,WDFREQUEST__ *param_1,CUsbHubPdo *param_2,_URB *param_3)

{
  long lVar1;
  CTsUrb *local_res8;
  
  *(undefined4 *)(this + 8) = 0x12345678;
  *(CUsbHubPdo **)(this + 0x80) = param_2;
  *(_URB **)(this + 0x20) = param_3;
  *(WDFREQUEST__ **)(this + 0x10) = param_1;
  if (param_1 == (WDFREQUEST__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x668))
              (WdfDriverGlobals,*(undefined8 *)param_2,0,0x8ee,
               "clientcore\\termsrv\\devices\\urbdr\\busdriver\\buspdo.cpp");
  }
  local_res8 = (CTsUrb *)0x0;
  lVar1 = CTsUrb::CreateInstance
                    (this + 0x50,param_3,*(CSimpleHash **)(*(longlong *)(this + 0x80) + 0x20),
                     *(CSimpleHash **)(*(longlong *)(this + 0x80) + 0x28),&local_res8);
  if (lVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,
               &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,lVar1);
    }
  }
  else {
    lVar1 = 0;
  }
  return lVar1;
}



===== Initialize @ 140007a44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* protected: long __cdecl CUsbHubPdoRequest::Initialize(struct WDFREQUEST__ * __ptr64,class
   CUsbHubPdo * __ptr64,void * __ptr64,unsigned long) __ptr64 */

long __thiscall
CUsbHubPdoRequest::Initialize
          (CUsbHubPdoRequest *this,WDFREQUEST__ *param_1,CUsbHubPdo *param_2,void *param_3,
          ulong param_4)

{
  *(ulong *)(this + 0x28) = param_4;
  *(undefined4 *)(this + 8) = 0x12345679;
  *(CUsbHubPdo **)(this + 0x80) = param_2;
  *(void **)(this + 0x20) = param_3;
  *(WDFREQUEST__ **)(this + 0x10) = param_1;
  if (param_1 == (WDFREQUEST__ *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x668))
              (WdfDriverGlobals,*(undefined8 *)param_2,0,0x944,
               "clientcore\\termsrv\\devices\\urbdr\\busdriver\\buspdo.cpp");
  }
  return 0;
}



===== MimicUsbHub @ 140007ab0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CUsbHubPdo::MimicUsbHub(void) __ptr64 */

long __thiscall CUsbHubPdo::MimicUsbHub(CUsbHubPdo *this)

{
  int iVar1;
  undefined2 uVar2;
  longlong local_res8;
  longlong local_res10;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10 = 0;
  local_res8 = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"SymbolicName");
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x268))
                    (WdfDriverGlobals,*(undefined8 *)this,&GUID_DEVINTERFACE_USB_DEVICE,0);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140007cbc;
    uVar2 = 0x3d;
  }
  else {
    iVar1 = (**(code **)(WdfFunctions_01015 + 0x9a0))(WdfDriverGlobals,0,0,&local_res8);
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140007cbc;
      uVar2 = 0x3e;
    }
    else {
      iVar1 = (**(code **)(WdfFunctions_01015 + 0x278))
                        (WdfDriverGlobals,*(undefined8 *)this,&GUID_DEVINTERFACE_USB_DEVICE,0,
                         local_res8);
      if (iVar1 < 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140007cbc;
        uVar2 = 0x3f;
      }
      else {
        iVar1 = (**(code **)(WdfFunctions_01015 + 0x180))
                          (WdfDriverGlobals,*(undefined8 *)this,1,0x1f0000,0,&local_res10);
        if (iVar1 < 0) {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140007cbc;
          uVar2 = 0x40;
        }
        else {
          iVar1 = (**(code **)(WdfFunctions_01015 + 0x7a8))
                            (WdfDriverGlobals,local_res10,&local_18,local_res8);
          if (-1 < iVar1) {
            iVar1 = 0;
            goto LAB_140007cbc;
          }
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140007cbc;
          uVar2 = 0x41;
        }
      }
    }
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,iVar1);
LAB_140007cbc:
  if (local_res10 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x738))(WdfDriverGlobals);
  }
  if (local_res8 != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar1;
}



===== QueryPerformanceCounterInMilliSec @ 140007d1c =====

/* private: unsigned long __cdecl CUsbHubPdo::QueryPerformanceCounterInMilliSec(void) __ptr64 */

ulong __thiscall CUsbHubPdo::QueryPerformanceCounterInMilliSec(CUsbHubPdo *this)

{
  longlong lVar1;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  lVar1 = KeQueryPerformanceCounter(local_res8);
  return (ulong)((lVar1 * 1000) / local_res8[0]);
}



===== RIM_USER_ALLOC @ 140007d58 =====

/* long __cdecl RIM_USER_ALLOC(void * __ptr64 * __ptr64,unsigned long) */

long __cdecl RIM_USER_ALLOC(void **param_1,ulong param_2)

{
  void *_Dst;
  long lVar1;
  
  if (param_2 == 0) {
    *param_1 = (void *)0x0;
    lVar1 = 0;
  }
  else {
    _Dst = (void *)ExAllocatePoolWithTag(0x200,param_2,0x72447244);
    *param_1 = _Dst;
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,(ulonglong)param_2);
    }
    lVar1 = 0;
    if (*param_1 == (void *)0x0) {
      lVar1 = -0x7ff8fff2;
    }
  }
  return lVar1;
}



===== RIM_USER_FREE @ 140007dcc =====

/* void __cdecl RIM_USER_FREE(void * __ptr64) */

void __cdecl RIM_USER_FREE(void *param_1)

{
  if (param_1 != (void *)0x0) {
    operator_delete(param_1);
  }
  return;
}



===== RequestIsIsochUrb @ 140007de8 =====

/* public: unsigned char __cdecl CUsbHubPdoRequest::RequestIsIsochUrb(void) __ptr64 */

uchar __thiscall CUsbHubPdoRequest::RequestIsIsochUrb(CUsbHubPdoRequest *this)

{
  if ((*(int *)(this + 8) == 0x12345678) && (*(short *)(*(longlong *)(this + 0x20) + 2) == 10)) {
    return '\x01';
  }
  return '\0';
}



===== RtlULongLongMult @ 140007e0c =====

/* long __cdecl RtlULongLongMult(unsigned __int64,unsigned __int64,unsigned __int64 * __ptr64) */

long __cdecl RtlULongLongMult(__uint64 param_1,__uint64 param_2,__uint64 *param_3)

{
  undefined1 auVar1 [16];
  long lVar2;
  
  lVar2 = 0;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_1;
  if (SUB168(ZEXT816(2) * auVar1,8) == 0) {
    *param_3 = SUB168(ZEXT816(2) * auVar1,0);
  }
  else {
    *param_3 = 0xffffffffffffffff;
    lVar2 = -0x3fffff6b;
  }
  return lVar2;
}



===== TsUrbCompletion @ 140007e40 =====

/* public: virtual void __cdecl CTsUrb::TsUrbCompletion(unsigned char * __ptr64,unsigned long,void *
   __ptr64,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64) __ptr64 */

void __thiscall
CTsUrb::TsUrbCompletion
          (CTsUrb *this,uchar *param_1,ulong param_2,void *param_3,ulong param_4,
          CSimpleHash *param_5,CSimpleHash *param_6)

{
  return;
}



===== UpdateBusFrame @ 140007e4c =====

/* public: void __cdecl CUsbHubPdo::UpdateBusFrame(unsigned long,unsigned char) __ptr64 */

void __thiscall CUsbHubPdo::UpdateBusFrame(CUsbHubPdo *this,ulong param_1,uchar param_2)

{
  ulong uVar1;
  
  uVar1 = QueryPerformanceCounterInMilliSec(this);
  LOCK();
  *(ulonglong *)(this + 0x70) = CONCAT44(param_1,uVar1);
  UNLOCK();
  this[0x68] = (CUsbHubPdo)0x1;
  if (param_2 != '\0') {
    *(undefined4 *)(this + 0x78) = 0;
  }
  return;
}



===== Bus_EvtChildListIdentificationDescriptionCleanup @ 140007ea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void Bus_EvtChildListIdentificationDescriptionCleanup(undefined8 param_1,longlong param_2)

{
  if (*(void **)(param_2 + 0x50) != (void *)0x0) {
    RIM_USER_FREE(*(void **)(param_2 + 0x50));
    *(undefined8 *)(param_2 + 0x50) = 0;
  }
  if (*(void **)(param_2 + 0x60) != (void *)0x0) {
    RIM_USER_FREE(*(void **)(param_2 + 0x60));
    *(undefined8 *)(param_2 + 0x60) = 0;
  }
  if (*(void **)(param_2 + 0x70) != (void *)0x0) {
    RIM_USER_FREE(*(void **)(param_2 + 0x70));
    *(undefined8 *)(param_2 + 0x70) = 0;
  }
  if (*(longlong **)(param_2 + 0x10) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(param_2 + 0x10) + 0x10))();
    *(undefined8 *)(param_2 + 0x10) = 0;
  }
  return;
}



===== Bus_EvtChildListIdentificationDescriptionCompare @ 140007f10 =====

undefined8
Bus_EvtChildListIdentificationDescriptionCompare
          (undefined8 param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  undefined4 extraout_var;
  longlong lVar2;
  undefined4 extraout_var_00;
  undefined1 uVar3;
  
  lVar2 = *(longlong *)(param_3 + 0x10);
  uVar3 = 1;
  if (*(longlong *)(param_2 + 0x10) != lVar2) {
    if (*(longlong *)(param_2 + 0x48) == *(longlong *)(param_3 + 0x48)) {
      iVar1 = memcmp(*(void **)(param_2 + 0x50),*(void **)(param_3 + 0x50),
                     *(longlong *)(param_2 + 0x48) * 2);
      lVar2 = CONCAT44(extraout_var,iVar1);
      if ((iVar1 == 0) && (*(longlong *)(param_2 + 0x58) == *(longlong *)(param_3 + 0x58))) {
        iVar1 = memcmp(*(void **)(param_2 + 0x60),*(void **)(param_3 + 0x60),
                       *(longlong *)(param_2 + 0x58) * 2);
        lVar2 = CONCAT44(extraout_var_00,iVar1);
        if (iVar1 == 0) goto LAB_140007f71;
      }
    }
    uVar3 = 0;
  }
LAB_140007f71:
  return CONCAT71((int7)((ulonglong)lVar2 >> 8),uVar3);
}



===== Bus_EvtChildListIdentificationDescriptionDuplicate @ 140007f90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

long Bus_EvtChildListIdentificationDescriptionDuplicate
               (undefined8 param_1,longlong param_2,void *param_3)

{
  __uint64 _Var1;
  undefined8 uVar2;
  long lVar3;
  undefined2 uVar4;
  __uint64 _Var5;
  void *pvVar6;
  __uint64 local_res10;
  
  local_res10 = 0;
  _Var5 = 0;
  memset(param_3,0,0x78);
  *(undefined4 *)((longlong)param_3 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)((longlong)param_3 + 8) = *(undefined4 *)(param_2 + 8);
  (**(code **)(**(longlong **)(param_2 + 0x10) + 8))();
  *(undefined8 *)((longlong)param_3 + 0x10) = *(undefined8 *)(param_2 + 0x10);
  _Var1 = *(__uint64 *)(param_2 + 0x48);
  *(__uint64 *)((longlong)param_3 + 0x48) = _Var1;
  lVar3 = RtlULongLongMult(_Var1,_Var5,&local_res10);
  _Var1 = local_res10;
  if (lVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140008249;
    uVar4 = 10;
LAB_14000801f:
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
             &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,lVar3);
  }
  else {
    if (0xffffffff < local_res10) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar4 = 0xb;
LAB_140008065:
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids);
      }
LAB_140008075:
      lVar3 = -0x3ffffff3;
      goto LAB_140008249;
    }
    lVar3 = RIM_USER_ALLOC((void **)((longlong)param_3 + 0x50),(ulong)local_res10);
    if (lVar3 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar4 = 0xc;
        goto LAB_140008234;
      }
    }
    else {
      pvVar6 = *(void **)(param_2 + 0x50);
      memmove(*(void **)((longlong)param_3 + 0x50),pvVar6,_Var1);
      _Var1 = *(__uint64 *)(param_2 + 0x58);
      *(__uint64 *)((longlong)param_3 + 0x58) = _Var1;
      lVar3 = RtlULongLongMult(_Var1,(__uint64)pvVar6,&local_res10);
      _Var1 = local_res10;
      if (lVar3 < 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140008249;
        uVar4 = 0xd;
        goto LAB_14000801f;
      }
      if (0xffffffff < local_res10) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar4 = 0xe;
          goto LAB_140008065;
        }
        goto LAB_140008075;
      }
      lVar3 = RIM_USER_ALLOC((void **)((longlong)param_3 + 0x60),(ulong)local_res10);
      if (lVar3 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar4 = 0xf;
LAB_140008234:
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
                  &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids);
        }
      }
      else {
        pvVar6 = *(void **)(param_2 + 0x60);
        memmove(*(void **)((longlong)param_3 + 0x60),pvVar6,_Var1);
        _Var1 = *(__uint64 *)(param_2 + 0x68);
        *(__uint64 *)((longlong)param_3 + 0x68) = _Var1;
        lVar3 = RtlULongLongMult(_Var1,(__uint64)pvVar6,&local_res10);
        _Var1 = local_res10;
        if (lVar3 < 0) {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140008249;
          uVar4 = 0x10;
          goto LAB_14000801f;
        }
        if (0xffffffff < local_res10) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar4 = 0x11;
            goto LAB_140008065;
          }
          goto LAB_140008075;
        }
        lVar3 = RIM_USER_ALLOC((void **)((longlong)param_3 + 0x70),(ulong)local_res10);
        if (-1 < lVar3) {
          memmove(*(void **)((longlong)param_3 + 0x70),*(void **)(param_2 + 0x70),_Var1);
          uVar2 = *(undefined8 *)(param_2 + 0x20);
          *(undefined8 *)((longlong)param_3 + 0x18) = *(undefined8 *)(param_2 + 0x18);
          *(undefined8 *)((longlong)param_3 + 0x20) = uVar2;
          uVar2 = *(undefined8 *)(param_2 + 0x30);
          *(undefined8 *)((longlong)param_3 + 0x28) = *(undefined8 *)(param_2 + 0x28);
          *(undefined8 *)((longlong)param_3 + 0x30) = uVar2;
          *(undefined8 *)((longlong)param_3 + 0x38) = *(undefined8 *)(param_2 + 0x38);
          *(undefined4 *)((longlong)param_3 + 0x40) = *(undefined4 *)(param_2 + 0x40);
          return 0;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar4 = 0x12;
          goto LAB_140008234;
        }
      }
    }
    lVar3 = -0x3fffffe9;
  }
LAB_140008249:
  if (*(longlong **)((longlong)param_3 + 0x10) != (longlong *)0x0) {
    (**(code **)(**(longlong **)((longlong)param_3 + 0x10) + 0x10))();
    *(undefined8 *)((longlong)param_3 + 0x10) = 0;
  }
  if (*(void **)((longlong)param_3 + 0x50) != (void *)0x0) {
    RIM_USER_FREE(*(void **)((longlong)param_3 + 0x50));
    *(undefined8 *)((longlong)param_3 + 0x50) = 0;
  }
  if (*(void **)((longlong)param_3 + 0x60) != (void *)0x0) {
    RIM_USER_FREE(*(void **)((longlong)param_3 + 0x60));
    *(undefined8 *)((longlong)param_3 + 0x60) = 0;
  }
  if (*(void **)((longlong)param_3 + 0x70) != (void *)0x0) {
    RIM_USER_FREE(*(void **)((longlong)param_3 + 0x70));
    *(undefined8 *)((longlong)param_3 + 0x70) = 0;
  }
  return lVar3;
}



===== McTemplateK0pz_EtwWriteTransfer @ 1400082f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0pz_EtwWriteTransfer(void)

{
  longlong lVar1;
  undefined1 local_res20 [8];
  wchar_t *in_stack_00000028;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined1 *local_38;
  undefined8 local_30;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = local_res20;
  local_30 = 8;
  if (in_stack_00000028 == (wchar_t *)0x0) {
    local_20 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000028[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  local_1c = 0;
  if (in_stack_00000028 == (wchar_t *)0x0) {
    in_stack_00000028 = L"NULL";
  }
  local_28 = in_stack_00000028;
  McGenEventWrite_EtwWriteTransfer(in_stack_00000028,&EVENT_NOTIFY_DEVICE_NAME,0,3,local_48);
  return;
}



===== WPP_SF_qDD @ 140008398 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,0x3a,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qDd @ 140008400 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,0x3b,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== CancelNoAckIsochRequests @ 140008468 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl CUsbHubPdo::CancelNoAckIsochRequests(unsigned long) __ptr64 */

void __thiscall CUsbHubPdo::CancelNoAckIsochRequests(CUsbHubPdo *this,ulong param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong local_res8;
  undefined8 local_res18;
  
  local_res8 = 0;
  lVar6 = 0;
  local_res18 = 0;
  (**(code **)(WdfFunctions_01015 + 0xa00))(WdfDriverGlobals,*(undefined8 *)(this + 0xa0),1);
  lVar5 = 0;
  while( true ) {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x500))
                      (WdfDriverGlobals,*(undefined8 *)(this + 0xa8),lVar6,0,0,&local_res8);
    if (lVar5 != 0) {
      iVar3 = (**(code **)(WdfFunctions_01015 + 0x508))
                        (WdfDriverGlobals,*(undefined8 *)(this + 0xa8),lVar5,&local_res18);
      (**(code **)(WdfFunctions_01015 + 0x670))
                (WdfDriverGlobals,lVar5,0,0x5ae,
                 "clientcore\\termsrv\\devices\\urbdr\\busdriver\\pdousb.cpp");
      lVar5 = 0;
      if (-1 < iVar3) {
        (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,local_res18,0xc0000120);
      }
    }
    if (lVar6 != 0) {
      (**(code **)(WdfFunctions_01015 + 0x670))
                (WdfDriverGlobals,lVar6,0,0x5b7,
                 "clientcore\\termsrv\\devices\\urbdr\\busdriver\\pdousb.cpp");
    }
    lVar6 = local_res8;
    if (iVar2 < 0) break;
    lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                      (WdfDriverGlobals,local_res8,PTR__WDF_CUsbHubPdoRequest_TYPE_INFO_14001d108);
    lVar1 = local_res8;
    if (*(ulong *)(lVar4 + 0x70) == param_1) {
      (**(code **)(WdfFunctions_01015 + 0x668))
                (WdfDriverGlobals,local_res8,0,0x5cc,
                 "clientcore\\termsrv\\devices\\urbdr\\busdriver\\pdousb.cpp");
      lVar5 = lVar1;
    }
  }
  EvtIsochFrameTimer(this);
  return;
}



===== EvtIoInternalDeviceControl_GetBusInfo @ 14000864c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl CUsbHubPdo::EvtIoInternalDeviceControl_GetBusInfo(struct WDFREQUEST__ *
   __ptr64) __ptr64 */

void __thiscall
CUsbHubPdo::EvtIoInternalDeviceControl_GetBusInfo(CUsbHubPdo *this,WDFREQUEST__ *param_1)

{
  void *in_R9;
  undefined1 auStackY_78 [32];
  ulong in_stack_ffffffffffffffa8;
  undefined8 local_38;
  void *pvStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  local_18 = 0;
  pvStack_30 = (void *)0x0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_1,&local_38);
  if (pvStack_30 == (void *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc000000d);
  }
  else {
    EvtIoInternalDeviceControl_UsbIoControl
              (this,param_1,0x220420,in_R9,in_stack_ffffffffffffffa8,pvStack_30,0x10);
  }
  return;
}



===== EvtIoInternalDeviceControl_GetControllerName @ 140008714 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl CUsbHubPdo::EvtIoInternalDeviceControl_GetControllerName(struct
   WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall
CUsbHubPdo::EvtIoInternalDeviceControl_GetControllerName(CUsbHubPdo *this,WDFREQUEST__ *param_1)

{
  void *in_R9;
  undefined1 auStackY_78 [32];
  ulong in_stack_ffffffffffffffa8;
  undefined8 local_38;
  void *pvStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  local_18 = 0;
  pvStack_30 = (void *)0x0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_1,&local_38);
  if (pvStack_30 == (void *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc000000d);
  }
  else {
    EvtIoInternalDeviceControl_UsbIoControl
              (this,param_1,0x220424,in_R9,in_stack_ffffffffffffffa8,pvStack_30,(ulong)local_28);
  }
  return;
}



===== EvtIoInternalDeviceControl_GetHubCount @ 1400087e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl CUsbHubPdo::EvtIoInternalDeviceControl_GetHubCount(struct WDFREQUEST__ *
   __ptr64) __ptr64 */

void __thiscall
CUsbHubPdo::EvtIoInternalDeviceControl_GetHubCount(CUsbHubPdo *this,WDFREQUEST__ *param_1)

{
  void *in_R9;
  undefined1 auStackY_78 [32];
  ulong in_stack_ffffffffffffffa8;
  undefined8 local_38;
  void *pvStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  local_18 = 0;
  pvStack_30 = (void *)0x0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_1,&local_38);
  if (pvStack_30 == (void *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc000000d);
  }
  else {
    EvtIoInternalDeviceControl_UsbIoControl
              (this,param_1,0x22001b,in_R9,in_stack_ffffffffffffffa8,pvStack_30,4);
  }
  return;
}



===== EvtIoInternalDeviceControl_GetHubName @ 1400088a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl CUsbHubPdo::EvtIoInternalDeviceControl_GetHubName(struct WDFREQUEST__ *
   __ptr64) __ptr64 */

void __thiscall
CUsbHubPdo::EvtIoInternalDeviceControl_GetHubName(CUsbHubPdo *this,WDFREQUEST__ *param_1)

{
  int iVar1;
  void **ppvVar2;
  undefined1 auStackY_88 [32];
  ulong uVar3;
  ulonglong local_48;
  void *local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_88;
  local_40 = (void *)0x0;
  local_48 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  local_38 = 0x28;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_1,&local_38);
  uVar3 = (ulong)&local_48;
  ppvVar2 = &local_40;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_1,0);
  if (-1 < iVar1) {
    if (local_48 < 0xffffffff) {
      EvtIoInternalDeviceControl_UsbIoControl
                (this,param_1,0x220020,ppvVar2,uVar3,local_40,(ulong)local_48);
      return;
    }
    iVar1 = -0x3ffffff3;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,iVar1);
  return;
}



===== EvtIoInternalDeviceControl_GetPortStatus @ 1400089c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl CUsbHubPdo::EvtIoInternalDeviceControl_GetPortStatus(struct WDFREQUEST__ *
   __ptr64) __ptr64 */

void __thiscall
CUsbHubPdo::EvtIoInternalDeviceControl_GetPortStatus(CUsbHubPdo *this,WDFREQUEST__ *param_1)

{
  void *in_R9;
  undefined1 auStackY_78 [32];
  ulong in_stack_ffffffffffffffa8;
  undefined8 local_38;
  void *pvStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  local_18 = 0;
  pvStack_30 = (void *)0x0;
  local_38 = 0x28;
  local_28 = 0;
  uStack_20 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_1,&local_38);
  if (pvStack_30 == (void *)0x0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,0xc000000d);
  }
  else {
    EvtIoInternalDeviceControl_UsbIoControl
              (this,param_1,0x220013,in_R9,in_stack_ffffffffffffffa8,pvStack_30,4);
  }
  return;
}



===== EvtIoInternalDeviceControl_Urb @ 140008a88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl CUsbHubPdo::EvtIoInternalDeviceControl_Urb(struct WDFREQUEST__ *
   __ptr64,struct _URB * __ptr64) __ptr64 */

void __thiscall
CUsbHubPdo::EvtIoInternalDeviceControl_Urb(CUsbHubPdo *this,WDFREQUEST__ *param_1,_URB *param_2)

{
  ushort uVar1;
  longlong *plVar2;
  CUsbHubPdoRequest *pCVar3;
  long lVar4;
  int iVar5;
  void *pvVar6;
  _TS_URB *p_Var7;
  _TS_PIPE_INFORMATION *p_Var8;
  longlong lVar9;
  CSimpleHash *pCVar10;
  ulong uVar11;
  _TS_PIPE_INFORMATION local_res20;
  ulong local_58;
  undefined4 local_54;
  longlong local_50;
  CUsbHubPdoRequest *local_48 [2];
  
  uVar1 = *(ushort *)(param_2 + 2);
  uVar11 = 0xffffffff;
  local_50 = 0;
  p_Var8 = (_TS_PIPE_INFORMATION *)0x0;
  local_54 = 0;
  local_48[0] = (CUsbHubPdoRequest *)0x0;
  local_58 = 0xffffffff;
  local_res20 = (_TS_PIPE_INFORMATION)0x0;
  pvVar6 = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,param_1,
                              PTR__WDF_CUsbHubPdoRequest_TYPE_INFO_14001d108);
  lVar4 = CUsbHubPdoRequest::CreateInstance(pvVar6,param_1,this,param_2,local_48);
  pCVar3 = local_48[0];
  if (lVar4 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_0e688d79522a3fa5eb4f62bbf1bebee6_Traceguids,lVar4);
    }
  }
  else {
    lVar4 = CSimpleHash::AddItemNoDuplicate(*(CSimpleHash **)(this + 0x10),local_48[0],&local_58);
    uVar11 = local_58;
    if (lVar4 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_0e688d79522a3fa5eb4f62bbf1bebee6_Traceguids,lVar4);
      }
      uVar11 = local_58;
    }
    else {
      *(ulong *)(pCVar3 + 0x18) = local_58;
      local_58 = CONCAT22(local_58._2_2_,*(ushort *)(pCVar3 + 0x60));
      p_Var7 = GetTsUrb(this,*(ushort *)(pCVar3 + 0x60));
      if (p_Var7 == (_TS_URB *)0x0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                  &WPP_0e688d79522a3fa5eb4f62bbf1bebee6_Traceguids);
        }
      }
      else {
        (**(code **)(*(longlong *)(pCVar3 + 0x50) + 8))
                  (pCVar3 + 0x50,uVar11,p_Var7,(undefined2)local_58,&local_50,&local_54);
        if ((((*(int *)(this + 0x54) != 0) && (uVar1 < 0x32)) &&
            ((0x3000040000004U >> ((ulonglong)uVar1 & 0x3f) & 1) != 0)) &&
           ((p_Var8 = CTsUrb::FindTsPipeInfoInPipeHandleTable
                                (*(CSimpleHash **)(this + 0x28),*(void **)(param_2 + 0x18)),
            p_Var8 != (_TS_PIPE_INFORMATION *)0x0 && (p_Var8[0x25] != (_TS_PIPE_INFORMATION)0x0))))
        {
          CancelNoAckIsochRequests(this,*(ulong *)(pCVar3 + 0x70));
        }
        if (uVar1 == 10) {
          if (local_50 == 0) {
            pCVar10 = *(CSimpleHash **)(this + 0x20);
          }
          else {
            pCVar10 = *(CSimpleHash **)(this + 0x28);
          }
          p_Var8 = CTsUrb::FindTsPipeInfoInPipeHandleTable(pCVar10,*(void **)(param_2 + 0x18));
          if (p_Var8 == (_TS_PIPE_INFORMATION *)0x0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                      &WPP_0e688d79522a3fa5eb4f62bbf1bebee6_Traceguids);
            }
            goto LAB_140008e13;
          }
          if (*(longlong *)(p_Var8 + 0x18) == 0) {
            lVar9 = ExAllocatePoolWithTag(0x200,0x18,0x72447244);
            if (lVar9 == 0) {
              *(undefined8 *)(p_Var8 + 0x18) = 0;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                        &WPP_0e688d79522a3fa5eb4f62bbf1bebee6_Traceguids);
              }
              goto LAB_140008e13;
            }
            *(undefined4 *)(lVar9 + 0x10) = 0;
            *(longlong *)(lVar9 + 8) = lVar9;
            *(longlong *)lVar9 = lVar9;
            *(longlong *)(p_Var8 + 0x18) = lVar9;
          }
        }
        if ((*(int *)(this + 0x54) == 0) || (uVar1 != 10)) {
          local_res20 = (_TS_PIPE_INFORMATION)0x0;
          if (uVar1 == 10) goto LAB_140008dc7;
          local_res20 = (_TS_PIPE_INFORMATION)0x0;
        }
        else {
          if (local_50 != 0) {
            local_res20 = p_Var8[0x25];
          }
LAB_140008dc7:
          *(undefined4 *)(pCVar3 + 0x28) = *(undefined4 *)(p_Var8 + 0x14);
          *(_TS_PIPE_INFORMATION **)(pCVar3 + 0x30) = p_Var8;
        }
        *(uint *)(p_Var7 + 4) =
             -(uint)(local_res20 != (_TS_PIPE_INFORMATION)0x0) & 0x80000000 |
             *(uint *)(p_Var7 + 4) & 0x7fffffff;
        plVar2 = *(longlong **)(this + 8);
        if (local_50 == 0) {
          iVar5 = (**(code **)(*plVar2 + 0x40))(plVar2,p_Var7,*(undefined2 *)p_Var7,local_54);
        }
        else {
          iVar5 = (**(code **)(*plVar2 + 0x48))
                            (plVar2,p_Var7,*(undefined2 *)p_Var7,local_50,local_54);
        }
        if (-1 < iVar5) {
          if (uVar1 == 10) {
            *(int *)(p_Var8 + 0x14) = *(int *)(p_Var8 + 0x14) + 1;
          }
          if (local_res20 == (_TS_PIPE_INFORMATION)0x0) {
            (**(code **)(WdfFunctions_01015 + 0x7f8))(WdfDriverGlobals);
            uVar11 = 0xffffffff;
            goto LAB_140008e5b;
          }
          lVar4 = PostNoAckRequest(this,param_1,param_2,p_Var8);
          if (-1 < lVar4) goto LAB_140008e5b;
        }
      }
    }
  }
LAB_140008e13:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1);
LAB_140008e5b:
  if (uVar11 != 0xffffffff) {
    CSimpleHash::RemoveItemByIndex(*(CSimpleHash **)(this + 0x10),uVar11,(void **)0x0);
  }
  return;
}



===== EvtIoInternalDeviceControl_UsbIoControl @ 140008e90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl CUsbHubPdo::EvtIoInternalDeviceControl_UsbIoControl(struct WDFREQUEST__ *
   __ptr64,unsigned long,void * __ptr64,unsigned long,void * __ptr64,unsigned long) __ptr64 */

void __thiscall
CUsbHubPdo::EvtIoInternalDeviceControl_UsbIoControl
          (CUsbHubPdo *this,WDFREQUEST__ *param_1,ulong param_2,void *param_3,ulong param_4,
          void *param_5,ulong param_6)

{
  CUsbHubPdoRequest *pCVar1;
  ulong uVar2;
  long lVar3;
  int iVar4;
  void *pvVar5;
  ulong uVar6;
  CUsbHubPdoRequest *local_res20;
  
  local_res20 = (CUsbHubPdoRequest *)0x0;
  uVar6 = 0xffffffff;
  param_4 = 0xffffffff;
  pvVar5 = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                             (WdfDriverGlobals,param_1,
                              PTR__WDF_CUsbHubPdoRequest_TYPE_INFO_14001d108);
  uVar2 = param_6;
  lVar3 = CUsbHubPdoRequest::CreateInstance(pvVar5,param_1,this,param_5,param_6,&local_res20);
  pCVar1 = local_res20;
  if (lVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_0e688d79522a3fa5eb4f62bbf1bebee6_Traceguids,lVar3);
    }
  }
  else {
    lVar3 = CSimpleHash::AddItemNoDuplicate(*(CSimpleHash **)(this + 0x10),local_res20,&param_4);
    uVar6 = param_4;
    if (lVar3 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                 &WPP_0e688d79522a3fa5eb4f62bbf1bebee6_Traceguids,lVar3);
      }
      uVar6 = param_4;
    }
    else {
      *(ulong *)(pCVar1 + 0x18) = param_4;
      iVar4 = (**(code **)(**(longlong **)(this + 8) + 0x28))
                        (*(longlong **)(this + 8),param_2,0,0,uVar2,param_4);
      if (-1 < iVar4) {
        (**(code **)(WdfFunctions_01015 + 0x7f8))(WdfDriverGlobals,param_1);
        uVar6 = 0xffffffff;
        goto LAB_14000902e;
      }
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1);
LAB_14000902e:
  if (uVar6 != 0xffffffff) {
    CSimpleHash::RemoveItemByIndex(*(CSimpleHash **)(this + 0x10),uVar6,(void **)0x0);
  }
  return;
}



===== EvtQueryBusTimeWorker @ 140009060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CUsbHubPdo::EvtQueryBusTimeWorker(void) __ptr64 */

void __thiscall CUsbHubPdo::EvtQueryBusTimeWorker(CUsbHubPdo *this)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  CUsbHubPdoRequest_QueryBusFrame **ppCVar4;
  CUsbHubPdoRequest_QueryBusFrame *pCVar5;
  CUsbHubPdoRequest_QueryBusFrame *this_00;
  ulong uVar6;
  ulong local_res10 [2];
  CUsbHubPdoRequest_QueryBusFrame *local_res18;
  
  local_res18 = (CUsbHubPdoRequest_QueryBusFrame *)0x0;
  ppCVar4 = &local_res18;
  uVar6 = 0xffffffff;
  local_res10[0] = 0xffffffff;
  lVar1 = CUsbHubPdoRequest_QueryBusFrame::CreateInstance(this,ppCVar4);
  this_00 = local_res18;
  uVar3 = (ulong)ppCVar4;
  if (lVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar3 = 0x11;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_0e688d79522a3fa5eb4f62bbf1bebee6_Traceguids,lVar1);
    }
  }
  else {
    pCVar5 = local_res18;
    lVar1 = CSimpleHash::AddItemNoDuplicate(*(CSimpleHash **)(this + 0x10),local_res18,local_res10);
    uVar6 = local_res10[0];
    uVar3 = (ulong)pCVar5;
    if (lVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar3 = 0x12;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                 &WPP_0e688d79522a3fa5eb4f62bbf1bebee6_Traceguids,lVar1);
      }
      uVar6 = local_res10[0];
    }
    else {
      *(ulong *)(this_00 + 0x18) = local_res10[0];
      uVar3 = 0x224000;
      iVar2 = (**(code **)(**(longlong **)(this + 8) + 0x30))();
      if (-1 < iVar2) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar3 = 0x14;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                  &WPP_0e688d79522a3fa5eb4f62bbf1bebee6_Traceguids);
        }
        this_00 = (CUsbHubPdoRequest_QueryBusFrame *)0x0;
        uVar6 = 0xffffffff;
        goto LAB_1400091ee;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar3 = 0x38;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
                 &WPP_3a8eb695d5d4382a1e2bbe997e67d17a_Traceguids,iVar2);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar3 = 0x13;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                 &WPP_0e688d79522a3fa5eb4f62bbf1bebee6_Traceguids,0xc000009a);
      }
    }
  }
  *(undefined4 *)(this + 0x78) = 0;
LAB_1400091ee:
  if (uVar6 != 0xffffffff) {
    uVar3 = uVar6;
    CSimpleHash::RemoveItemByIndex(*(CSimpleHash **)(this + 0x10),uVar6,(void **)0x0);
  }
  if (this_00 != (CUsbHubPdoRequest_QueryBusFrame *)0x0) {
    CUsbHubPdoRequest_QueryBusFrame::_scalar_deleting_destructor_(this_00,uVar3);
  }
  return;
}



===== PostNoAckRequest @ 140009228 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CUsbHubPdo::PostNoAckRequest(struct WDFREQUEST__ * __ptr64,struct _URB *
   __ptr64,struct _TS_PIPE_INFORMATION * __ptr64) __ptr64 */

long __thiscall
CUsbHubPdo::PostNoAckRequest
          (CUsbHubPdo *this,WDFREQUEST__ *param_1,_URB *param_2,_TS_PIPE_INFORMATION *param_3)

{
  ulonglong uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  longlong lVar5;
  int iVar6;
  ulonglong uVar7;
  ulong local_res18 [2];
  
  local_res18[0] = 0;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CUsbHubPdoRequest_TYPE_INFO_14001d108);
  if (*(ushort *)param_2 < 0x8c) {
    lVar3 = -0x7ffffd00;
  }
  else {
    lVar3 = QueryBusTime(this,local_res18);
    if (-1 < lVar3) {
      uVar1 = (ulonglong)local_res18[0] * 8;
      uVar2 = (uint)*(ushort *)(param_3 + 0x22) * *(int *)(param_2 + 0x84) * 8;
      if (param_3[0x24] != (_TS_PIPE_INFORMATION)0x0) {
        uVar2 = (uint)*(ushort *)(param_3 + 0x22) * *(int *)(param_2 + 0x84);
      }
      if ((*(uint *)(param_2 + 0x20) & 4) == 0) {
        iVar6 = local_res18[0] - *(int *)(param_2 + 0x80);
        iVar4 = -iVar6;
        if (iVar4 < 0) {
          iVar4 = iVar6;
        }
        if (0x400 < iVar4) {
          *(undefined4 *)(param_2 + 4) = 0xc0000a00;
          return -0x3ffffff3;
        }
        *(ulonglong *)(this + 0x80) =
             (ulonglong)(uint)(*(int *)(param_2 + 0x80) * 8) + (ulonglong)uVar2;
      }
      else {
        uVar7 = *(ulonglong *)(this + 0x80);
        if (uVar7 < uVar1) {
          if (((7 < uVar1 - uVar7) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_II(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,(ulonglong)local_res18[0],
                      uVar7 + 7 >> 3,(char)local_res18[0]);
          }
          *(ulonglong *)(this + 0x80) = uVar1;
          uVar7 = uVar1;
        }
        *(int *)(param_2 + 0x80) = (int)(uVar7 + 7 >> 3);
        *(ulonglong *)(this + 0x80) = *(longlong *)(this + 0x80) + (ulonglong)uVar2;
      }
      *(undefined4 *)(param_2 + 0x88) = 0;
      *(undefined4 *)(param_2 + 4) = 0;
      *(int *)(lVar5 + 0x2c) = (int)(*(longlong *)(this + 0x80) + 7U >> 3);
      (**(code **)(WdfFunctions_01015 + 0xa00))(WdfDriverGlobals,*(undefined8 *)(this + 0xa0),1);
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x8c8))
                        (WdfDriverGlobals,param_1,*(undefined8 *)(this + 0xa8));
      EvtIsochFrameTimer(this);
      if (-1 < lVar3) {
        *(undefined4 *)(param_2 + 4) = 0;
        return 0;
      }
    }
    *(undefined4 *)(param_2 + 4) = 0x80000300;
  }
  return lVar3;
}



===== PostQueryBusTimeWorkItem @ 14000941c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl CUsbHubPdo::PostQueryBusTimeWorkItem(void) __ptr64 */

void __thiscall CUsbHubPdo::PostQueryBusTimeWorkItem(CUsbHubPdo *this)

{
  int iVar1;
  bool bVar2;
  undefined8 local_res10 [3];
  undefined8 local_58;
  code *pcStack_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  
  local_res10[0] = 0;
  LOCK();
  bVar2 = *(int *)(this + 0x78) == 0;
  if (bVar2) {
    *(int *)(this + 0x78) = 1;
  }
  UNLOCK();
  if (bVar2) {
    local_10 = 0;
    local_20 = *(undefined8 *)this;
    local_58 = 0x18;
    local_30 = 0;
    uStack_18 = 0;
    pcStack_50 = PdEvtQueryBusTimeWorker;
    uStack_38 = 0;
    uStack_28 = 0x100000001;
    local_48 = 1;
    local_40 = 0x38;
    iVar1 = (**(code **)(WdfFunctions_01015 + 0xbd8))
                      (WdfDriverGlobals,&local_58,&local_40,local_res10);
    if (iVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                 &WPP_0e688d79522a3fa5eb4f62bbf1bebee6_Traceguids,iVar1);
      }
    }
    else {
      (**(code **)(WdfFunctions_01015 + 0xbe0))(WdfDriverGlobals,local_res10[0]);
    }
  }
  return;
}



===== QueryBusTime @ 140009514 =====

/* public: long __cdecl CUsbHubPdo::QueryBusTime(unsigned long * __ptr64) __ptr64 */

long __thiscall CUsbHubPdo::QueryBusTime(CUsbHubPdo *this,ulong *param_1)

{
  longlong lVar1;
  ulong uVar2;
  longlong lVar3;
  uint uVar4;
  long lVar5;
  bool bVar6;
  
  lVar5 = 0;
  if (this[0x68] == (CUsbHubPdo)0x0) {
    lVar5 = -0x7fffffef;
  }
  else {
    uVar2 = QueryPerformanceCounterInMilliSec(this);
    lVar3 = *(longlong *)(this + 0x70);
    do {
      LOCK();
      lVar1 = *(longlong *)(this + 0x70);
      bVar6 = lVar3 == lVar1;
      if (bVar6) {
        *(longlong *)(this + 0x70) = lVar3;
      }
      else {
        lVar3 = lVar1;
      }
      UNLOCK();
    } while (!bVar6);
    uVar4 = uVar2 - (int)lVar3;
    *param_1 = (int)((ulonglong)lVar3 >> 0x20) + uVar4;
    if (5000 < uVar4) {
      PostQueryBusTimeWorkItem(this);
    }
  }
  return lVar5;
}



===== PdUsbdBusQueryBusInformation @ 140009590 =====

undefined8 PdUsbdBusQueryBusInformation(void)

{
  return 0xc00000bb;
}



===== PdUsbdGetUSBDIVersion @ 1400095a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdUsbdGetUSBDIVersion(undefined8 param_1,undefined8 *param_2,undefined4 *param_3)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = *(undefined8 *)(lVar1 + 0x44);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(lVar1 + 0x4c);
  }
  return;
}



===== PdUsbdIsDeviceHighSpeed @ 140009610 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool PdUsbdIsDeviceHighSpeed(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
  return *(int *)(lVar1 + 0x50) != 0;
}



===== PdUsbdQueryBusTime @ 140009650 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdUsbdQueryBusTime(undefined8 param_1,ulong *param_2)

{
  CUsbHubPdo *this;
  
  this = (CUsbHubPdo *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
  CUsbHubPdo::QueryBusTime(this,param_2);
  return;
}



===== WPP_SF_II @ 140009698 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_II(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0e688d79522a3fa5eb4f62bbf1bebee6_Traceguids,0x16,&local_res20,8,
             &param_5,8,0);
  return;
}



===== CTsRequestCompletion @ 1400096f0 =====

/* private: __cdecl CTsRequestCompletion::CTsRequestCompletion(void) __ptr64 */

CTsRequestCompletion * __thiscall
CTsRequestCompletion::CTsRequestCompletion(CTsRequestCompletion *this)

{
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined ***)this = &_vftable__for__ITsRequestCompletion__;
  *(undefined ***)(this + 8) = &_vftable__for__IRIMChannelCallback__;
  return this;
}



===== ~CTsRequestCompletion @ 14000971c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: __cdecl CTsRequestCompletion::~CTsRequestCompletion(void) __ptr64 */

void __thiscall CTsRequestCompletion::~CTsRequestCompletion(CTsRequestCompletion *this)

{
  *(undefined ***)this = &_vftable__for__ITsRequestCompletion__;
  *(undefined ***)(this + 8) = &_vftable__for__IRIMChannelCallback__;
  if (*(longlong *)(this + 0x18) != 0) {
    (**(code **)(WdfFunctions_01015 + 0x670))
              (WdfDriverGlobals,*(longlong *)(this + 0x18),0,0xb4,
               "clientcore\\termsrv\\devices\\urbdr\\busdriver\\requestcallback.cpp");
    *(undefined8 *)(this + 0x18) = 0;
  }
  return;
}



===== AddRef @ 140009790 =====

/* public: virtual unsigned long __cdecl CTsRequestCompletion::AddRef(void) __ptr64 */

ulong __thiscall CTsRequestCompletion::AddRef(CTsRequestCompletion *this)

{
  CTsRequestCompletion *pCVar1;
  int iVar2;
  
  LOCK();
  pCVar1 = this + 0x10;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + 1;
  UNLOCK();
  return iVar2 + 1;
}



===== AddRef`adjustor{8}' @ 1400097b0 =====

/* [thunk]:public: virtual unsigned long __cdecl CTsRequestCompletion::AddRef`adjustor{8}' (void)
   __ptr64 */

ulong __thiscall CTsRequestCompletion::AddRef_adjustor_8__(CTsRequestCompletion *this)

{
  ulong uVar1;
  
  uVar1 = AddRef(this + -8);
  return uVar1;
}



===== CreateInstance @ 1400097c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl CTsRequestCompletion::CreateInstance(struct WDFDEVICE__ *
   __ptr64,class CTsRequestCompletion * __ptr64 * __ptr64) */

long __cdecl
CTsRequestCompletion::CreateInstance(WDFDEVICE__ *param_1,CTsRequestCompletion **param_2)

{
  CTsRequestCompletion *pCVar1;
  
  *param_2 = (CTsRequestCompletion *)0x0;
  pCVar1 = (CTsRequestCompletion *)ExAllocatePoolWithTag(0x200,0x20,0x6c6d6952);
  if ((pCVar1 != (CTsRequestCompletion *)0x0) &&
     (pCVar1 = (CTsRequestCompletion *)CTsRequestCompletion(pCVar1),
     pCVar1 != (CTsRequestCompletion *)0x0)) {
    (**(code **)(*(longlong *)pCVar1 + 8))(pCVar1);
    *(WDFDEVICE__ **)(pCVar1 + 0x18) = param_1;
    (**(code **)(WdfFunctions_01015 + 0x668))
              (WdfDriverGlobals,param_1,0,0x9a,
               "clientcore\\termsrv\\devices\\urbdr\\busdriver\\requestcallback.cpp");
    *param_2 = pCVar1;
    return 0;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_7d6a713878383e546ef1a1b98ce80b28_Traceguids);
  }
  return -0x3fffffe9;
}



===== IoControlCompleteRequest @ 1400098b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CTsRequestCompletion::IoControlCompleteRequest(unsigned
   long,long,unsigned long,char * __ptr64,unsigned long) __ptr64 */

long __thiscall
CTsRequestCompletion::IoControlCompleteRequest
          (CTsRequestCompletion *this,ulong param_1,long param_2,ulong param_3,char *param_4,
          ulong param_5)

{
  undefined8 uVar1;
  CSimpleHash *this_00;
  longlong *plVar2;
  long lVar3;
  longlong lVar4;
  longlong **pplVar5;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  uVar1 = *(undefined8 *)(this + 0x18);
  lVar4 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
  this_00 = *(CSimpleHash **)(lVar4 + 0x10);
  (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,uVar1);
  pplVar5 = &local_res8;
  lVar3 = CSimpleHash::RemoveItemByIndex(this_00,param_1,pplVar5);
  plVar2 = local_res8;
  if (-1 < lVar3) {
    *(undefined4 *)(local_res8 + 3) = 0xffffffff;
  }
  (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,uVar1);
  if (lVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,pplVar5,param_1,(char)lVar3);
    }
  }
  else if ((int)plVar2[1] == 0x12345679) {
    (**(code **)(*plVar2 + 8))(plVar2,param_2,param_3,param_4,param_5);
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_7d6a713878383e546ef1a1b98ce80b28_Traceguids);
  }
  return 0;
}



===== OnChannelClose @ 140009a10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CTsRequestCompletion::OnChannelClose(void) __ptr64 */

long __thiscall CTsRequestCompletion::OnChannelClose(CTsRequestCompletion *this)

{
  CTsRequestCompletion *pCVar1;
  undefined8 uVar2;
  CSimpleHash *this_00;
  ulong uVar3;
  long lVar4;
  longlong lVar5;
  ulong local_res8 [2];
  undefined8 local_res10;
  void *local_res18;
  undefined8 in_stack_ffffffffffffffb8;
  undefined4 uVar6;
  
  uVar2 = *(undefined8 *)(this + 0x10);
  local_res10 = 0;
  local_res18 = (void *)0x0;
  lVar5 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar2,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
  local_res8[0] = 0;
  this_00 = *(CSimpleHash **)(lVar5 + 0x10);
  this_00[0x18] = (CSimpleHash)0x1;
  while( true ) {
    uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffb8 >> 0x20);
    (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,uVar2);
    lVar4 = CSimpleHash::FindNextItem(this_00,local_res8,&local_res18);
    (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,uVar2);
    uVar3 = local_res8[0];
    if (lVar4 < 0) break;
    pCVar1 = this + -8;
    if (*(int *)((longlong)local_res18 + 8) == 0x12345679) {
      in_stack_ffffffffffffffb8 = 0;
      (**(code **)(*(longlong *)pCVar1 + 0x18))(pCVar1,local_res8[0],0x800704c7,0,0);
    }
    else {
      local_res10 = CONCAT62(local_res10._2_6_,8);
      local_res10 = CONCAT44(0xc0010000,(undefined4)local_res10);
      in_stack_ffffffffffffffb8 = CONCAT44(uVar6,0x800704c7);
      (**(code **)(*(longlong *)pCVar1 + 0x28))
                (pCVar1,local_res8[0],&local_res10,8,in_stack_ffffffffffffffb8,0);
    }
    local_res8[0] = uVar3 + 1;
  }
  return 0;
}



===== QueryInterface @ 140009b40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CTsRequestCompletion::QueryInterface(struct _GUID const &
   __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CTsRequestCompletion::QueryInterface(CTsRequestCompletion *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  CTsRequestCompletion *pCVar2;
  long lVar3;
  
  *param_2 = (void *)0x0;
  lVar1 = *(longlong *)param_1;
  lVar3 = -0x7fffbffe;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)(param_1 + 8) + -0x46000000000000c0;
  }
  if (lVar1 != 0) {
    lVar1 = *(longlong *)param_1 + -0x469129aa0493a1ca;
    if (lVar1 == 0) {
      lVar1 = *(longlong *)(param_1 + 8) + -0x12fa1cf6fb0ac889;
    }
    if (lVar1 != 0) {
      lVar1 = *(longlong *)param_1 + -0x420da29527c1b69e;
      if (lVar1 == 0) {
        lVar1 = *(longlong *)(param_1 + 8) + -0x7699c11ebc7e2a82;
      }
      if (lVar1 != 0) {
        return -0x7fffbffe;
      }
      pCVar2 = (CTsRequestCompletion *)
               (-(ulonglong)(this != (CTsRequestCompletion *)0x0) & (ulonglong)(this + 8));
      goto LAB_140009bba;
    }
  }
  pCVar2 = this;
LAB_140009bba:
  *param_2 = pCVar2;
  if (pCVar2 != (CTsRequestCompletion *)0x0) {
    (**(code **)(*(longlong *)this + 8))(this);
    lVar3 = 0;
  }
  return lVar3;
}



===== QueryInterface`adjustor{8}' @ 140009bf0 =====

/* [thunk]:public: virtual long __cdecl CTsRequestCompletion::QueryInterface`adjustor{8}' (struct
   _GUID const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CTsRequestCompletion::QueryInterface_adjustor_8__
          (CTsRequestCompletion *this,_GUID *param_1,void **param_2)

{
  long lVar1;
  
  lVar1 = QueryInterface(this + -8,param_1,param_2);
  return lVar1;
}



===== Release @ 140009c00 =====

/* public: virtual unsigned long __cdecl CTsRequestCompletion::Release(void) __ptr64 */

ulong __thiscall CTsRequestCompletion::Release(CTsRequestCompletion *this)

{
  CTsRequestCompletion *pCVar1;
  int iVar2;
  
  LOCK();
  pCVar1 = this + 0x10;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  if ((iVar2 - 1U == 0) && (this != (CTsRequestCompletion *)0x0)) {
    ~CTsRequestCompletion(this);
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return iVar2 - 1U;
}



===== Release`adjustor{8}' @ 140009c50 =====

/* [thunk]:public: virtual unsigned long __cdecl CTsRequestCompletion::Release`adjustor{8}' (void)
   __ptr64 */

ulong __thiscall CTsRequestCompletion::Release_adjustor_8__(CTsRequestCompletion *this)

{
  ulong uVar1;
  
  uVar1 = Release(this + -8);
  return uVar1;
}



===== UrbCompletion @ 140009c60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CTsRequestCompletion::UrbCompletion(unsigned long,char *
   __ptr64,unsigned long,long,char * __ptr64,unsigned long) __ptr64 */

long __thiscall
CTsRequestCompletion::UrbCompletion
          (CTsRequestCompletion *this,ulong param_1,char *param_2,ulong param_3,long param_4,
          char *param_5,ulong param_6)

{
  undefined8 uVar1;
  CSimpleHash *this_00;
  CUsbHubPdoRequest *this_01;
  long lVar2;
  longlong lVar3;
  CUsbHubPdoRequest **ppCVar4;
  CUsbHubPdoRequest *local_res8;
  
  local_res8 = (CUsbHubPdoRequest *)0x0;
  uVar1 = *(undefined8 *)(this + 0x18);
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,uVar1,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
  this_00 = *(CSimpleHash **)(lVar3 + 0x10);
  (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,uVar1);
  ppCVar4 = &local_res8;
  lVar2 = CSimpleHash::RemoveItemByIndex(this_00,param_1,ppCVar4);
  this_01 = local_res8;
  if (-1 < lVar2) {
    *(undefined4 *)(local_res8 + 0x18) = 0xffffffff;
  }
  (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,uVar1);
  if (lVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,ppCVar4,param_1,(char)lVar2);
    }
  }
  else if (*(int *)(this_01 + 8) == 0x12345678) {
    CUsbHubPdoRequest::CompleteRequestUrb(this_01,(uchar *)param_2,param_3,param_4,param_5,param_6);
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_7d6a713878383e546ef1a1b98ce80b28_Traceguids);
  }
  return 0;
}



===== UrbCompletionNoData @ 140009dc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CTsRequestCompletion::UrbCompletionNoData(unsigned long,char *
   __ptr64,unsigned long,long,unsigned long) __ptr64 */

long __thiscall
CTsRequestCompletion::UrbCompletionNoData
          (CTsRequestCompletion *this,ulong param_1,char *param_2,ulong param_3,long param_4,
          ulong param_5)

{
  long lVar1;
  
  lVar1 = (**(code **)(*(longlong *)this + 0x20))();
  return lVar1;
}



===== WPP_SF_Dd @ 140009df8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_7d6a713878383e546ef1a1b98ce80b28_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== FxStubDriverUnloadCommon @ 140009e50 =====

/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  _WDF_BIND_INFO *in_RCX;
  
  FxStubUnbindClasses(in_RCX);
  WdfVersionUnbind(&DAT_14001d330,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 140009e90 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 140009ec4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FxDriverEntryWorker(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  _WDF_BIND_INFO *p_Var3;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  if (param_1 == (_WDF_BIND_INFO *)0x0) {
    iVar1 = DriverEntry(0,param_2);
  }
  else {
    _DAT_14001d330 = 0x2080000;
    _DAT_14001d338 = &DAT_14001d350;
    RtlCopyUnicodeString(&DAT_14001d330);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_14001d330,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_14001d558 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_14001d330);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14001d218 != &__KMDF_CLASS_BIND_START) {
          local_1c = 0;
          uStack_18 = 0;
          local_28 = &GUID_WDF_LOADER_INTERFACE_DRIVER_ENTRY_FAILURE;
          local_14 = 0;
          local_20 = 0x18;
          iVar2 = WdfLdrQueryInterface(&local_28);
          if (-1 < iVar2) {
            (*(code *)CONCAT44(local_14,uStack_18))(&WdfBindInfo,WdfDriverGlobals);
          }
        }
      }
      FxStubDriverUnloadCommon();
    }
  }
  return iVar1;
}



===== FxStubDriverUnload @ 14000a050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_14001d558 != (code *)0x0) && (DAT_14001d558 != FxStubDriverUnload)) {
    (*DAT_14001d558)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 14000a084 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000a0a9) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  uint *puVar2;
  void **ppvVar3;
  
  iVar1 = 0;
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    puVar2 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar3,(longlong *)&__KMDF_CLASS_BIND_END);
    if (puVar2 == (uint *)0x0) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    if ((uint *)0x14001d20f < puVar2) break;
    PTR___KMDF_CLASS_BIND_START_14001d218 = (undefined *)puVar2;
    if (*(code **)(puVar2 + 0xe) == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (**(code **)(puVar2 + 0xe))
                        (WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,*(undefined8 *)(puVar2 + 0xe),puVar2,*(undefined8 *)(puVar2 + 2),iVar1);
        return iVar1;
      }
    }
    ppvVar3 = (void **)((longlong)puVar2 + (ulonglong)*puVar2);
  }
  return iVar1;
}



===== FxStubUnbindClasses @ 14000a1e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubUnbindClasses(struct _WDF_BIND_INFO * __ptr64) */

void __cdecl FxStubUnbindClasses(_WDF_BIND_INFO *param_1)

{
  uint *puVar1;
  uint *puVar2;
  void **ppvVar3;
  
  ppvVar3 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14001d218 != &__KMDF_CLASS_BIND_START) {
    puVar1 = (uint *)(PTR___KMDF_CLASS_BIND_START_14001d218 + 0x50);
    while (puVar2 = (uint *)FxGetNextClassBindInfo((longlong *)ppvVar3,(longlong *)puVar1),
          puVar2 != (uint *)0x0) {
      if (puVar1 <= puVar2) {
        return;
      }
      if (*(code **)(puVar2 + 0x10) == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,puVar2);
      }
      else {
        (**(code **)(puVar2 + 0x10))
                  (WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,puVar2);
      }
      ppvVar3 = (void **)((longlong)puVar2 + (ulonglong)*puVar2);
    }
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
  return;
}



===== FxGetNextClassBindInfo @ 14000a2a0 =====

longlong * FxGetNextClassBindInfo(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  
  plVar1 = param_1 + 1;
  for (; (plVar1 <= param_2 && (*param_1 == 0)); param_1 = param_1 + 1) {
    plVar1 = param_1 + 2;
  }
  if (param_2 <= param_1) {
    return param_2;
  }
  if (param_2 < param_1 + 10) {
    return (longlong *)0x0;
  }
  plVar1 = (longlong *)0x0;
  if ((int)*param_1 == 0x50) {
    plVar1 = param_1;
  }
  return plVar1;
}



===== FxStubInitTypes @ 14000a2e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000a305) */
/* long __cdecl FxStubInitTypes(void) */

long __cdecl FxStubInitTypes(void)

{
  void *pvVar1;
  void **ppvVar2;
  
  ppvVar2 = &__KMDF_TYPE_INIT_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_TYPE_INIT_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x14001d22f < ppvVar2) break;
    if (((&__KMDF_TYPE_INIT_END < ppvVar2 + 5) || (*(uint *)ppvVar2 != 0x28)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextObjectContextTypeInfo failed\n");
      return -0x3fffff85;
    }
    if (ppvVar2[4] != (code *)0x0) {
      pvVar1 = (void *)(*ppvVar2[4])();
      ppvVar2[3] = pvVar1;
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return 0;
}



===== KernelResource @ 14000a3b0 =====

/* public: __cdecl KernelResource::KernelResource(char const * __ptr64) __ptr64 */

KernelResource * __thiscall KernelResource::KernelResource(KernelResource *this,char *param_1)

{
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined ***)this = &_vftable_;
  this[8] = (KernelResource)0x1;
  *(char **)(this + 0x78) = param_1;
  ExInitializeResourceLite(this + 0x10);
  return this;
}



===== NPagedLookasideList @ 14000a3f0 =====

/* public: __cdecl NPagedLookasideList::NPagedLookasideList(unsigned long,unsigned long) __ptr64 */

NPagedLookasideList * __thiscall
NPagedLookasideList::NPagedLookasideList(NPagedLookasideList *this,ulong param_1,ulong param_2)

{
  code *pcVar1;
  code *pcVar2;
  
  this[8] = (NPagedLookasideList)0x1;
  *(undefined ***)this = &_vftable_;
  pcVar2 = ExAllocatePoolWithTag_exref;
  pcVar1 = ExFreePool_exref;
  *(undefined4 *)(this + 0xc) = 0;
  ExInitializeNPagedLookasideList(this + 0x40,pcVar2,pcVar1,0x200,param_1,param_2,0);
  return this;
}



===== ~KernelResource @ 14000a454 =====

/* public: virtual __cdecl KernelResource::~KernelResource(void) __ptr64 */

void __thiscall KernelResource::~KernelResource(KernelResource *this)

{
  *(undefined ***)this = &_vftable_;
  ExDeleteResourceLite(this + 0x10);
  *(undefined ***)this = &TopObj::_vftable_;
  return;
}



===== ~NPagedLookasideList @ 14000a490 =====

/* public: virtual __cdecl NPagedLookasideList::~NPagedLookasideList(void) __ptr64 */

void __thiscall NPagedLookasideList::~NPagedLookasideList(NPagedLookasideList *this)

{
  *(undefined ***)this = &_vftable_;
  ExDeleteNPagedLookasideList(this + 0x40);
  *(undefined ***)this = &TopObj::_vftable_;
  return;
}



===== operator_delete @ 14000a4cc =====

/* public: static void __cdecl TopObj::operator delete(void * __ptr64) */

void __cdecl TopObj::operator_delete(void *param_1)

{
  if (param_1 != (void *)0x0) {
    ExFreePool();
  }
  return;
}



===== `vector_deleting_destructor' @ 14000a4f0 =====

/* public: virtual void * __ptr64 __cdecl KernelResource::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall KernelResource::_vector_deleting_destructor_(KernelResource *this,uint param_1)

{
  ~KernelResource(this);
  if ((param_1 & 1) != 0) {
    TopObj::operator_delete(this);
  }
  return this;
}



===== `vector_deleting_destructor' @ 14000a530 =====

/* public: virtual void * __ptr64 __cdecl NPagedLookasideList::`vector deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall
NPagedLookasideList::_vector_deleting_destructor_(NPagedLookasideList *this,uint param_1)

{
  ~NPagedLookasideList(this);
  if ((param_1 & 1) != 0) {
    ExFreePool(this);
  }
  return this;
}



===== `vector_deleting_destructor' @ 14000a570 =====

/* public: virtual void * __ptr64 __cdecl KMutex::`vector deleting destructor'(unsigned int) __ptr64
    */

void * __thiscall KMutex::_vector_deleting_destructor_(KMutex *this,uint param_1)

{
  *(undefined ***)this = &TopObj::_vftable_;
  if ((param_1 & 1) != 0) {
    TopObj::operator_delete(this);
  }
  return this;
}



===== AcquireResourceExclusive @ 14000a5a0 =====

/* public: virtual void __cdecl KernelResource::AcquireResourceExclusive(void) __ptr64 */

void __thiscall KernelResource::AcquireResourceExclusive(KernelResource *this)

{
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(this + 0x10,1);
  return;
}



===== InitializeKernelUtilities @ 14000a5d4 =====

/* int __cdecl InitializeKernelUtilities(void) */

int __cdecl InitializeKernelUtilities(void)

{
  NPagedLookasideList *pNVar1;
  int iVar2;
  
  pNVar1 = (NPagedLookasideList *)ExAllocatePoolWithTag(0x200,0xc0,0x4c4c504e);
  if (pNVar1 == (NPagedLookasideList *)0x0) {
    ListEntry::_Lookaside = (NPagedLookasideList *)0x0;
LAB_14000a62d:
    iVar2 = 0;
  }
  else {
    ListEntry::_Lookaside =
         (NPagedLookasideList *)NPagedLookasideList::NPagedLookasideList(pNVar1,0x18,0x7473694c);
    if (ListEntry::_Lookaside == (NPagedLookasideList *)0x0) goto LAB_14000a62d;
    iVar2 = 1;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_1252723375ad3a52ef6b82803de1bd48_Traceguids,iVar2);
  }
  if (iVar2 == 0) goto LAB_14000a715;
  pNVar1 = (NPagedLookasideList *)ExAllocatePoolWithTag(0x200,0xc0,0x4c4c504e);
  if (pNVar1 == (NPagedLookasideList *)0x0) {
    KernelEvent::_Lookaside = (NPagedLookasideList *)0x0;
LAB_14000a6b7:
    iVar2 = 0;
  }
  else {
    KernelEvent::_Lookaside =
         (NPagedLookasideList *)NPagedLookasideList::NPagedLookasideList(pNVar1,0x28,0x746e7645);
    if (KernelEvent::_Lookaside == (NPagedLookasideList *)0x0) goto LAB_14000a6b7;
    iVar2 = 1;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_1252723375ad3a52ef6b82803de1bd48_Traceguids,iVar2);
  }
  if (iVar2 != 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_1252723375ad3a52ef6b82803de1bd48_Traceguids);
    }
    return 1;
  }
LAB_14000a715:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
            &WPP_1252723375ad3a52ef6b82803de1bd48_Traceguids);
  }
  UninitializeKernelUtilities();
  return 0;
}



===== IsValid @ 14000a760 =====

/* public: virtual unsigned char __cdecl TopObj::IsValid(void) __ptr64 */

uchar __thiscall TopObj::IsValid(TopObj *this)

{
  return (uchar)this[8];
}



===== ReleaseResource @ 14000a770 =====

/* public: virtual void __cdecl KernelResource::ReleaseResource(void) __ptr64 */

void __thiscall KernelResource::ReleaseResource(KernelResource *this)

{
  ExReleaseResourceLite(this + 0x10);
  KeLeaveCriticalRegion();
  return;
}



===== SetValid @ 14000a7a0 =====

/* protected: virtual void __cdecl TopObj::SetValid(unsigned char) __ptr64 */

void __thiscall TopObj::SetValid(TopObj *this,uchar param_1)

{
  this[8] = (TopObj)param_1;
  return;
}



===== UninitializeKernelUtilities @ 14000a7ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl UninitializeKernelUtilities(void) */

void __cdecl UninitializeKernelUtilities(void)

{
  if (KernelEvent::_Lookaside != (NPagedLookasideList *)0x0) {
    (**(code **)(*(longlong *)KernelEvent::_Lookaside + 0x10))(KernelEvent::_Lookaside,1);
    KernelEvent::_Lookaside = (NPagedLookasideList *)0x0;
  }
  if (ListEntry::_Lookaside != (NPagedLookasideList *)0x0) {
    (**(code **)(*(longlong *)ListEntry::_Lookaside + 0x10))(ListEntry::_Lookaside,1);
    ListEntry::_Lookaside = (NPagedLookasideList *)0x0;
  }
  return;
}



===== CKDynamicVC @ 14000a808 =====

/* public: __cdecl CKDynamicVC::CKDynamicVC(void) __ptr64 */

CKDynamicVC * __thiscall CKDynamicVC::CKDynamicVC(CKDynamicVC *this)

{
  *(undefined4 *)(this + 8) = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  KMutex::KMutex((KMutex *)(this + 0x28));
  *(undefined8 *)(this + 0x78) = 0;
  *(undefined8 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined8 *)(this + 0x90) = 0;
  *(undefined8 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xa4) = 2;
  KMutex::KMutex((KMutex *)(this + 0xa8));
  this[0x118] = (CKDynamicVC)0x0;
  *(undefined8 *)(this + 0x138) = 0;
  *(undefined4 *)(this + 8) = 0;
  return this;
}



===== ExclusiveLock @ 14000a89c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl ExclusiveLock::ExclusiveLock(class GenericLock & __ptr64) __ptr64 */

ExclusiveLock * __thiscall ExclusiveLock::ExclusiveLock(ExclusiveLock *this,GenericLock *param_1)

{
  *(GenericLock **)this = param_1;
  (**(code **)(*(longlong *)param_1 + 0x18))(param_1);
  return this;
}



===== KMutex @ 14000a8c8 =====

/* public: __cdecl KMutex::KMutex(void) __ptr64 */

KMutex * __thiscall KMutex::KMutex(KMutex *this)

{
  *(undefined4 *)(this + 0xc) = 0;
  this[8] = (KMutex)0x1;
  *(KMutex **)(this + 0x10) = this + 0x18;
  *(undefined ***)this = &_vftable_;
  KeInitializeMutex(this + 0x18,0);
  return this;
}



===== ~CKDynamicVC @ 14000a90c =====

/* public: __cdecl CKDynamicVC::~CKDynamicVC(void) __ptr64 */

void __thiscall CKDynamicVC::~CKDynamicVC(CKDynamicVC *this)

{
  *(undefined ***)this = &_vftable_;
  Clean(this);
  *(undefined ***)(this + 0xa8) = &TopObj::_vftable_;
  *(undefined ***)(this + 0x28) = &TopObj::_vftable_;
  return;
}



===== ~ExclusiveLock @ 14000a944 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl ExclusiveLock::~ExclusiveLock(void) __ptr64 */

void __thiscall ExclusiveLock::~ExclusiveLock(ExclusiveLock *this)

{
  (**(code **)(**(longlong **)this + 0x20))();
  return;
}



===== AcquireResourceExclusive @ 14000a970 =====

/* public: virtual void __cdecl SimpleMutex::AcquireResourceExclusive(void) __ptr64 */

void __thiscall SimpleMutex::AcquireResourceExclusive(SimpleMutex *this)

{
  KeWaitForSingleObject(*(undefined8 *)(this + 0x10),0,0,0,0);
  return;
}



===== AddRef @ 14000a9a0 =====

/* private: virtual unsigned long __cdecl CKDynamicVC::AddRef(void) __ptr64 */

ulong __thiscall CKDynamicVC::AddRef(CKDynamicVC *this)

{
  CKDynamicVC *pCVar1;
  int iVar2;
  
  LOCK();
  pCVar1 = this + 8;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + 1;
  UNLOCK();
  return iVar2 + 1;
}



===== Clean @ 14000a9b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl CKDynamicVC::Clean(void) __ptr64 */

void __thiscall CKDynamicVC::Clean(CKDynamicVC *this)

{
  if (*(longlong *)(this + 0x80) != 0) {
    ExFreePoolWithTag(*(longlong *)(this + 0x80),0x6376644b);
    *(undefined8 *)(this + 0x80) = 0;
    *(undefined4 *)(this + 0x88) = 0;
  }
  if (*(longlong **)(this + 0x20) != (longlong *)0x0) {
    (**(code **)(**(longlong **)(this + 0x20) + 0x10))();
    *(undefined8 *)(this + 0x20) = 0;
  }
  if (*(longlong *)(this + 0x10) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(this + 0x10) = 0;
    *(undefined8 *)(this + 0x18) = 0;
  }
  operator_delete(*(void **)(this + 0x138));
  *(undefined8 *)(this + 0x138) = 0;
  operator_delete(*(void **)(this + 0x90));
  return;
}



===== Close @ 14000aa50 =====

/* private: virtual long __cdecl CKDynamicVC::Close(void) __ptr64 */

long __thiscall CKDynamicVC::Close(CKDynamicVC *this)

{
  ExclusiveLock local_res8 [32];
  
  ExclusiveLock::ExclusiveLock(local_res8,(GenericLock *)(this + 0x28));
  *(undefined4 *)(this + 0xa0) = 3;
  if (*(longlong *)(this + 0x78) != 0) {
    IoCancelIrp();
  }
  ExclusiveLock::~ExclusiveLock(local_res8);
  return 0;
}



===== CreateInstance @ 14000aaa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl CKDynamicVC::CreateInstance(unsigned long,unsigned long,void *
   __ptr64,struct IWTSVirtualChannelCallback * __ptr64,enum TCommonVCThreading,struct
   IWTSVirtualChannel * __ptr64 * __ptr64) */

long __cdecl
CKDynamicVC::CreateInstance
          (ulong param_1,ulong param_2,void *param_3,IWTSVirtualChannelCallback *param_4,
          TCommonVCThreading param_5,IWTSVirtualChannel **param_6)

{
  long lVar1;
  CKDynamicVC *pCVar2;
  ulong uVar3;
  IWTSVirtualChannelCallback *pIVar4;
  TCommonVCThreading in_stack_ffffffffffffffe8;
  
  if (((param_3 == (void *)0x0) || (param_4 == (IWTSVirtualChannelCallback *)0x0)) ||
     (param_6 == (IWTSVirtualChannel **)0x0)) {
    lVar1 = -0x7fffbffd;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_33c76d18363830779b81325d89363eda_Traceguids,0x80004003);
    }
  }
  else {
    *param_6 = (IWTSVirtualChannel *)0x0;
    uVar3 = 0x6c6d6952;
    pIVar4 = param_4;
    pCVar2 = (CKDynamicVC *)ExAllocatePoolWithTag(0x200,0x140);
    if ((pCVar2 != (CKDynamicVC *)0x0) &&
       (pCVar2 = (CKDynamicVC *)CKDynamicVC(pCVar2), pCVar2 != (CKDynamicVC *)0x0)) {
      (**(code **)(*(longlong *)pCVar2 + 8))(pCVar2);
      lVar1 = Initialize(pCVar2,param_1,uVar3,(ushort *)pIVar4,param_3,param_4,
                         in_stack_ffffffffffffffe8);
      if (-1 < lVar1) {
        *param_6 = (IWTSVirtualChannel *)pCVar2;
        return lVar1;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                 &WPP_33c76d18363830779b81325d89363eda_Traceguids,lVar1);
      }
      (**(code **)(*(longlong *)pCVar2 + 0x10))(pCVar2);
      return lVar1;
    }
    lVar1 = -0x7ff8fff2;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_33c76d18363830779b81325d89363eda_Traceguids);
    }
  }
  return lVar1;
}



===== GetObjectsFromHandle @ 14000ac1c =====

/* private: long __cdecl CKDynamicVC::GetObjectsFromHandle(void * __ptr64) __ptr64 */

long __thiscall CKDynamicVC::GetObjectsFromHandle(CKDynamicVC *this,void *param_1)

{
  CKDynamicVC *pCVar1;
  uint uVar2;
  undefined8 uVar3;
  
  pCVar1 = this + 0x10;
  uVar2 = ObReferenceObjectByHandle(param_1,0,0,0,pCVar1,0);
  if ((int)(uVar2 | 0x10000000) < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
               &WPP_33c76d18363830779b81325d89363eda_Traceguids,uVar2);
    }
    if (*(longlong *)pCVar1 != 0) {
      ObfDereferenceObject();
      *(longlong *)pCVar1 = 0;
      *(undefined8 *)(this + 0x18) = 0;
    }
  }
  else {
    uVar3 = IoGetRelatedDeviceObject(*(longlong *)pCVar1);
    *(undefined8 *)(this + 0x18) = uVar3;
  }
  return uVar2 | 0x10000000;
}



===== Initialize @ 14000acdc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CKDynamicVC::Initialize(unsigned long,unsigned long,unsigned short *
   __ptr64,void * __ptr64,struct IWTSVirtualChannelCallback * __ptr64,enum TCommonVCThreading)
   __ptr64 */

long __thiscall
CKDynamicVC::Initialize
          (CKDynamicVC *this,ulong param_1,ulong param_2,ushort *param_3,void *param_4,
          IWTSVirtualChannelCallback *param_5,TCommonVCThreading param_6)

{
  CKDynamicVC *pCVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  undefined2 uVar6;
  undefined1 auStack_508 [32];
  ulonglong local_4e8;
  undefined8 local_4e0;
  undefined4 local_4d8;
  undefined4 local_4d0;
  undefined4 local_4c8;
  undefined8 local_4c0;
  undefined4 local_4b8;
  int local_4a8 [2];
  void *local_4a0;
  undefined8 local_498;
  undefined8 uStack_490;
  undefined8 local_488;
  undefined8 local_480;
  undefined8 *local_478;
  undefined8 local_470;
  undefined8 local_468;
  undefined8 uStack_460;
  undefined8 local_458;
  undefined8 uStack_450;
  ushort local_448 [520];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_508;
  *(undefined4 *)(this + 0xa4) = 1;
  local_4a0 = (void *)0x0;
  bVar2 = false;
  local_498 = 0;
  uStack_490 = 0;
  lVar5 = ExAllocatePoolWithTag(0x200,0x48,0x72447244);
  *(longlong *)(this + 0x138) = lVar5;
  if (lVar5 == 0) {
    uVar3 = 0x8007000e;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000b011;
    uVar6 = 0x11;
LAB_14000ad92:
    uVar3 = 0x8007000e;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
            &WPP_33c76d18363830779b81325d89363eda_Traceguids);
  }
  else {
    pCVar1 = this + 0x120;
    *(CKDynamicVC **)(this + 0x128) = pCVar1;
    *(CKDynamicVC **)pCVar1 = pCVar1;
    *(code **)(this + 0x108) = static_SingleThreadPostReadCompletion;
    *(CKDynamicVC **)(this + 0x110) = this;
    *(undefined8 *)(this + 0xf8) = 0;
    if (param_4 == (void *)0x0) {
      local_4e0 = 0;
      local_4e8 = local_4e8 & 0xffffffff00000000;
      uVar3 = RtlStringCchPrintfW(local_448,0x201,(ushort *)L"\\Device\\DrDynVc\\%d\\%d\\%s",
                                  (ulonglong)param_1);
      if ((int)uVar3 < 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000b011;
        uVar6 = 0x12;
LAB_14000affe:
        uVar4 = uVar3;
      }
      else {
        RtlInitUnicodeString(&local_498,local_448);
        local_4b8 = 0;
        local_478 = &local_498;
        local_4c0 = 0;
        local_4c8 = 4;
        local_4d0 = 1;
        local_4d8 = 0;
        local_4e0 = CONCAT44(local_4e0._4_4_,0x80);
        local_4e8 = 0;
        local_488 = 0x30;
        local_470 = 0x240;
        local_480 = 0;
        local_468 = 0;
        uStack_460 = 0;
        local_458 = 0;
        uStack_450 = 0;
        uVar4 = ZwCreateFile(&local_4a0,3,&local_488,&local_458);
        uVar3 = uVar4 | 0x10000000;
        if (-1 < (int)uVar3) {
          bVar2 = true;
          goto LAB_14000aefe;
        }
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000b011;
        uVar6 = 0x13;
      }
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
               &WPP_33c76d18363830779b81325d89363eda_Traceguids,uVar4);
    }
    else {
      local_4a0 = param_4;
LAB_14000aefe:
      uVar3 = GetObjectsFromHandle(this,local_4a0);
      if ((int)uVar3 < 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar6 = 0x14;
          goto LAB_14000affe;
        }
      }
      else {
        (**(code **)(*(longlong *)param_5 + 8))(param_5);
        *(IWTSVirtualChannelCallback **)(this + 0x20) = param_5;
        *(undefined4 *)(this + 0x88) = 0x648;
        lVar5 = ExAllocatePool2(0x40,0x648,0x6376644b);
        *(longlong *)(this + 0x80) = lVar5;
        if (lVar5 == 0) {
          uVar3 = 0x8007000e;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar6 = 0x15;
            goto LAB_14000ad92;
          }
        }
        else {
          (**(code **)(*(longlong *)this + 8))(this);
          local_4a8[0] = 0;
          uVar3 = IssueAsyncReadIrp(this,local_4a8);
          if (-1 < (int)uVar3) {
            *(undefined4 *)(this + 0xa0) = 1;
            goto LAB_14000b032;
          }
          if (local_4a8[0] == 0) {
            (**(code **)(*(longlong *)this + 0x10))(this);
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar6 = 0x16;
            goto LAB_14000affe;
          }
        }
      }
    }
  }
LAB_14000b011:
  if (*(longlong *)(this + 0x78) != 0) {
    IoCancelIrp();
  }
LAB_14000b032:
  if ((local_4a0 != (void *)0x0) && (bVar2)) {
    ZwClose();
  }
  return uVar3;
}



===== IssueAsyncReadIrp @ 14000b080 =====

/* private: long __cdecl CKDynamicVC::IssueAsyncReadIrp(int * __ptr64) __ptr64 */

long __thiscall CKDynamicVC::IssueAsyncReadIrp(CKDynamicVC *this,int *param_1)

{
  undefined8 uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  
  *param_1 = 0;
  lVar3 = IoBuildAsynchronousFsdRequest
                    (3,*(undefined8 *)(this + 0x18),*(undefined8 *)(this + 0x80),
                     *(undefined4 *)(this + 0x88),0,0);
  *(longlong *)(this + 0x78) = lVar3;
  if (lVar3 == 0) {
    uVar4 = 0x8007000e;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
              &WPP_33c76d18363830779b81325d89363eda_Traceguids);
    }
  }
  else {
    lVar3 = *(longlong *)(lVar3 + 0xb8);
    uVar1 = *(undefined8 *)(this + 0x10);
    *param_1 = 1;
    *(undefined8 *)(lVar3 + -0x18) = uVar1;
    lVar3 = *(longlong *)(*(longlong *)(this + 0x78) + 0xb8);
    *(code **)(lVar3 + -0x10) = static_ReadCompletion;
    *(CKDynamicVC **)(lVar3 + -8) = this;
    *(undefined1 *)(lVar3 + -0x45) = 0xe0;
    uVar2 = IofCallDriver(*(undefined8 *)(this + 0x18),*(undefined8 *)(this + 0x78));
    uVar4 = uVar2 | 0x10000000;
    if (-1 < (int)uVar4) {
      return uVar4;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_33c76d18363830779b81325d89363eda_Traceguids,uVar2);
    }
  }
  static_FreeIrp(*(_IRP **)(this + 0x78));
  *(undefined8 *)(this + 0x78) = 0;
  return uVar4;
}



===== IssueSyncWriteIrp @ 14000b1b0 =====

/* private: long __cdecl CKDynamicVC::IssueSyncWriteIrp(unsigned long,void * __ptr64) __ptr64 */

long __thiscall CKDynamicVC::IssueSyncWriteIrp(CKDynamicVC *this,ulong param_1,void *param_2)

{
  longlong lVar1;
  uint uVar2;
  _IRP *p_Var3;
  uint uVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeInitializeEvent(&local_28,0,0);
  p_Var3 = (_IRP *)IoBuildAsynchronousFsdRequest(4,*(undefined8 *)(this + 0x18),param_2,param_1,0,0)
  ;
  if (p_Var3 == (_IRP *)0x0) {
    uVar4 = 0x8007000e;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_33c76d18363830779b81325d89363eda_Traceguids);
    }
  }
  else {
    *(undefined8 *)(*(longlong *)(p_Var3 + 0xb8) + -0x18) = *(undefined8 *)(this + 0x10);
    lVar1 = *(longlong *)(p_Var3 + 0xb8);
    *(code **)(lVar1 + -0x10) = static_WriteCompletion;
    *(undefined8 **)(lVar1 + -8) = &local_28;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    uVar2 = IofCallDriver(*(undefined8 *)(this + 0x18),p_Var3);
    if (uVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      uVar2 = *(uint *)(p_Var3 + 0x30);
    }
    uVar4 = uVar2 | 0x10000000;
    if ((((int)uVar4 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_33c76d18363830779b81325d89363eda_Traceguids,uVar2);
    }
    static_FreeIrp(p_Var3);
  }
  return uVar4;
}



===== QueryInterface @ 14000b320 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CKDynamicVC::QueryInterface(struct _GUID const & __ptr64,void *
   __ptr64 * __ptr64) __ptr64 */

long __thiscall CKDynamicVC::QueryInterface(CKDynamicVC *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  long lVar2;
  
  *param_2 = (void *)0x0;
  lVar2 = -0x7fffbffe;
  lVar1 = *(longlong *)param_1;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)(param_1 + 8) + -0x46000000000000c0;
  }
  if (lVar1 != 0) {
    lVar1 = *(longlong *)param_1 + -0x11d8d6a7a1230207;
    if (lVar1 == 0) {
      lVar1 = *(longlong *)(param_1 + 8) + 0x670e2e24f4ff0247;
    }
    if (lVar1 != 0) {
      return -0x7fffbffe;
    }
  }
  *param_2 = this;
  if (this != (CKDynamicVC *)0x0) {
    (**(code **)(*(longlong *)this + 8))();
    lVar2 = 0;
  }
  return lVar2;
}



===== QueueCompletionContext @ 14000b390 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl CKDynamicVC::QueueCompletionContext(struct _POST_READ_CONTEXT * __ptr64)
   __ptr64 */

void __thiscall CKDynamicVC::QueueCompletionContext(CKDynamicVC *this,_POST_READ_CONTEXT *param_1)

{
  _POST_READ_CONTEXT *p_Var1;
  code *pcVar2;
  CKDynamicVC *pCVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  ExclusiveLock local_res8 [8];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  p_Var1 = param_1 + 0x20;
  if (*(int *)(this + 0xa4) == 1) {
    ExclusiveLock::ExclusiveLock(local_res8,(GenericLock *)(this + 0xa8));
    puVar5 = auStack_28;
    pCVar3 = this + 0x120;
    plVar4 = *(longlong **)(this + 0x128);
    if ((CKDynamicVC *)*plVar4 != pCVar3) {
      plVar4 = (longlong *)0x3;
      pcVar2 = (code *)swi(0x29);
      pCVar3 = (CKDynamicVC *)(*pcVar2)();
      puVar5 = auStack_20;
    }
    *(CKDynamicVC **)p_Var1 = pCVar3;
    *(longlong **)(param_1 + 0x28) = plVar4;
    *plVar4 = (longlong)p_Var1;
    *(_POST_READ_CONTEXT **)(pCVar3 + 8) = p_Var1;
    if (this[0x118] == (CKDynamicVC)0x0) {
      *(undefined8 *)(puVar5 + -8) = 0x14000b3f9;
      ExQueueWorkItem(this + 0xf8,0);
      this[0x118] = (CKDynamicVC)0x1;
      pcVar2 = *(code **)(*(longlong *)this + 8);
      *(undefined8 *)(puVar5 + -8) = 0x14000b414;
      (*pcVar2)(this);
    }
    *(undefined8 *)(puVar5 + -8) = 0x14000b41e;
    ExclusiveLock::~ExclusiveLock((ExclusiveLock *)(puVar5 + 0x30));
  }
  else {
    *(longlong *)p_Var1 = 0;
    *(_POST_READ_CONTEXT **)(param_1 + 0x38) = param_1;
    *(code **)(param_1 + 0x30) = static_MultiThreadPostReadCompletion;
    ExQueueWorkItem(p_Var1,0);
  }
  return;
}



===== QueuePostReadCompletion @ 14000b458 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CKDynamicVC::QueuePostReadCompletion(unsigned char * __ptr64,unsigned
   long,int) __ptr64 */

long __thiscall
CKDynamicVC::QueuePostReadCompletion(CKDynamicVC *this,uchar *param_1,ulong param_2,int param_3)

{
  _POST_READ_CONTEXT *p_Var1;
  int iVar2;
  long lVar3;
  
  lVar3 = 0;
  iVar2 = param_2 + 0x48;
  if (param_3 == 0) {
    iVar2 = 0x48;
  }
  p_Var1 = (_POST_READ_CONTEXT *)ExAllocatePoolWithTag(0x200,iVar2,0x72447244);
  if (p_Var1 == (_POST_READ_CONTEXT *)0x0) {
    lVar3 = -0x7ff8fff2;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
              &WPP_33c76d18363830779b81325d89363eda_Traceguids);
    }
    operator_delete((void *)0x0);
  }
  else {
    if (param_3 != 0) {
      memmove(p_Var1 + 0x44,param_1,(ulonglong)param_2);
      param_1 = (uchar *)(p_Var1 + 0x44);
    }
    (**(code **)(**(longlong **)(this + 0x20) + 8))();
    *(undefined8 *)(p_Var1 + 8) = *(undefined8 *)(this + 0x20);
    *(ulong *)(p_Var1 + 0x18) = param_2;
    *(uchar **)(p_Var1 + 0x10) = param_1;
    *(CKDynamicVC **)p_Var1 = this;
    (**(code **)(*(longlong *)this + 8))(this);
    *(undefined4 *)(p_Var1 + 0x40) = 0;
    QueueCompletionContext(this,p_Var1);
  }
  return lVar3;
}



===== ReadCompletion @ 14000b564 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl CKDynamicVC::ReadCompletion(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64) __ptr64 */

void __thiscall CKDynamicVC::ReadCompletion(CKDynamicVC *this,_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  int iVar1;
  int iVar2;
  _POST_READ_CONTEXT *p_Var3;
  long lVar4;
  longlong lVar5;
  undefined2 uVar6;
  undefined4 *puVar7;
  ulong uVar8;
  uchar *_Src;
  ulonglong local_res10;
  ExclusiveLock local_res18 [8];
  
  iVar1 = *(int *)(param_2 + 0x30);
  lVar5 = *(longlong *)(param_2 + 0x38);
  local_res10 = (ulonglong)param_1 & 0xffffffff00000000;
  lVar4 = 0;
  if (iVar1 < 0) goto LAB_14000b7db;
  if (0xfffffff7 < lVar5 - 8U) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Pd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar5,param_2,lVar5,0xff);
    }
    goto LAB_14000b945;
  }
  if ((*(uint *)(param_2 + 0x10) & 0x10) == 0) {
    puVar7 = *(undefined4 **)(this + 0x80);
  }
  else {
    puVar7 = *(undefined4 **)(param_2 + 0x18);
  }
  uVar8 = (int)lVar5 - 8;
  _Src = (uchar *)(-(ulonglong)(uVar8 != 0) & (ulonglong)(puVar7 + 2));
  if (((byte)puVar7[1] & 3) == 3) {
    lVar4 = QueuePostReadCompletion(this,_Src,uVar8,1);
    if (-1 < lVar4) goto LAB_14000b7db;
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000b945;
    uVar6 = 0x1e;
  }
  else {
    if ((puVar7[1] & 1) == 0) {
LAB_14000b723:
      if (*(uint *)(this + 0x9c) + uVar8 <= *(uint *)(this + 0x98)) {
        memmove((void *)((ulonglong)*(uint *)(this + 0x9c) + *(longlong *)(this + 0x90)),_Src,
                (ulonglong)uVar8);
        iVar2 = *(int *)(this + 0x9c);
        *(ulong *)(this + 0x9c) = iVar2 + uVar8;
        if ((puVar7[1] & 2) != 0) {
          lVar4 = QueuePostReadCompletion(this,*(uchar **)(this + 0x90),iVar2 + uVar8,0);
          *(undefined8 *)(this + 0x90) = 0;
          *(undefined8 *)(this + 0x98) = 0;
          if (lVar4 < 0) {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000b945;
            uVar6 = 0x22;
            goto LAB_14000b69f;
          }
        }
LAB_14000b7db:
        ExclusiveLock::ExclusiveLock(local_res18,(GenericLock *)(this + 0x28));
        static_FreeIrp(*(_IRP **)(this + 0x78));
        *(undefined8 *)(this + 0x78) = 0;
        if (*(int *)(this + 0xa0) == 3) {
          lVar4 = 1;
LAB_14000b932:
          ExclusiveLock::~ExclusiveLock(local_res18);
          if ((-1 < lVar4) && (lVar4 != 1)) {
            return;
          }
        }
        else {
          if (iVar1 < 0) {
            if (iVar1 == -0x3fffffdd) {
              if (*(longlong *)(this + 0x80) != 0) {
                ExFreePoolWithTag(*(longlong *)(this + 0x80),0x6376644b);
                *(undefined8 *)(this + 0x80) = 0;
              }
              iVar1 = *(int *)(this + 0x88);
              *(int *)(this + 0x88) = iVar1 * 2;
              lVar5 = ExAllocatePool2(0x40,iVar1 * 2,0x6376644b);
              *(longlong *)(this + 0x80) = lVar5;
              if (lVar5 != 0) goto LAB_14000b8d4;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                        &WPP_33c76d18363830779b81325d89363eda_Traceguids);
              }
            }
            else {
              *(undefined4 *)(this + 0xa0) = 2;
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar6 = 0x25;
                lVar4 = -0x7fff0001;
                goto LAB_14000b911;
              }
            }
          }
          else {
LAB_14000b8d4:
            if ((*(longlong *)(this + 0x80) == 0) ||
               (lVar4 = IssueAsyncReadIrp(this,(int *)&local_res10), -1 < lVar4))
            goto LAB_14000b932;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar6 = 0x24;
LAB_14000b911:
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                       &WPP_33c76d18363830779b81325d89363eda_Traceguids,lVar4);
            }
          }
          ExclusiveLock::~ExclusiveLock(local_res18);
        }
        goto LAB_14000b945;
      }
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000b945;
      uVar6 = 0x21;
    }
    else {
      if (*(longlong *)(this + 0x90) == 0) {
        lVar5 = ExAllocatePoolWithTag(0x200,*puVar7,0x72447244);
        *(longlong *)(this + 0x90) = lVar5;
        if (lVar5 == 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                    &WPP_33c76d18363830779b81325d89363eda_Traceguids);
          }
          goto LAB_14000b945;
        }
        *(undefined4 *)(this + 0x98) = *puVar7;
        *(undefined4 *)(this + 0x9c) = 0;
        goto LAB_14000b723;
      }
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000b945;
      uVar6 = 0x1f;
    }
    lVar4 = -0x7fff0001;
  }
LAB_14000b69f:
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
           &WPP_33c76d18363830779b81325d89363eda_Traceguids,lVar4);
LAB_14000b945:
  p_Var3 = *(_POST_READ_CONTEXT **)(this + 0x138);
  *(undefined8 *)(this + 0x138) = 0;
  (**(code **)(**(longlong **)(this + 0x20) + 8))();
  *(undefined8 *)(p_Var3 + 8) = *(undefined8 *)(this + 0x20);
  *(undefined4 *)(p_Var3 + 0x18) = 0;
  *(undefined8 *)(p_Var3 + 0x10) = 0;
  *(CKDynamicVC **)p_Var3 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  *(undefined4 *)(p_Var3 + 0x40) = 1;
  QueueCompletionContext(this,p_Var3);
  if ((int)local_res10 == 0) {
    (**(code **)(*(longlong *)this + 0x10))(this);
  }
  return;
}



===== Release @ 14000b9d0 =====

/* private: virtual unsigned long __cdecl CKDynamicVC::Release(void) __ptr64 */

ulong __thiscall CKDynamicVC::Release(CKDynamicVC *this)

{
  CKDynamicVC *pCVar1;
  int iVar2;
  
  LOCK();
  pCVar1 = this + 8;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  if ((iVar2 - 1U == 0) && (this != (CKDynamicVC *)0x0)) {
    ~CKDynamicVC(this);
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return iVar2 - 1U;
}



===== ReleaseResource @ 14000ba20 =====

/* public: virtual void __cdecl SimpleMutex::ReleaseResource(void) __ptr64 */

void __thiscall SimpleMutex::ReleaseResource(SimpleMutex *this)

{
  KeReleaseMutex(*(undefined8 *)(this + 0x10),0);
  return;
}



===== SingleThreadPostReadCompletion @ 14000ba44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl CKDynamicVC::SingleThreadPostReadCompletion(void) __ptr64 */

void __thiscall CKDynamicVC::SingleThreadPostReadCompletion(CKDynamicVC *this)

{
  CKDynamicVC *pCVar1;
  CKDynamicVC *pCVar2;
  CKDynamicVC *pCVar3;
  longlong lVar4;
  code *pcVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  pCVar1 = this + 0xa8;
  (**(code **)(*(longlong *)pCVar1 + 0x18))(pCVar1);
  puVar6 = auStack_28;
  pCVar2 = this + 0x120;
  do {
    pCVar3 = *(CKDynamicVC **)pCVar2;
    if (pCVar3 == pCVar2) {
LAB_14000bac7:
      this[0x118] = (CKDynamicVC)0x0;
      pcVar5 = *(code **)(*(longlong *)pCVar1 + 0x20);
      *(undefined8 *)(puVar6 + -8) = 0x14000bade;
      (*pcVar5)(pCVar1);
      pcVar5 = *(code **)(*(longlong *)this + 0x10);
      *(undefined8 *)(puVar6 + -8) = 0x14000baed;
      (*pcVar5)(this);
      return;
    }
    if ((*(CKDynamicVC **)(pCVar3 + 8) != pCVar2) ||
       (lVar4 = *(longlong *)pCVar3, *(CKDynamicVC **)(lVar4 + 8) != pCVar3)) {
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      puVar6 = auStack_20;
      goto LAB_14000bac7;
    }
    *(longlong *)pCVar2 = lVar4;
    *(CKDynamicVC **)(lVar4 + 8) = pCVar2;
    (**(code **)(*(longlong *)pCVar1 + 0x20))(pCVar1);
    static_MultiThreadPostReadCompletion(pCVar3 + -0x20);
    (**(code **)(*(longlong *)pCVar1 + 0x18))(pCVar1);
  } while( true );
}



===== Write @ 14000bb10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: virtual long __cdecl CKDynamicVC::Write(unsigned long,unsigned char * __ptr64,struct
   IUnknown * __ptr64) __ptr64 */

long __thiscall CKDynamicVC::Write(CKDynamicVC *this,ulong param_1,uchar *param_2,IUnknown *param_3)

{
  long lVar1;
  longlong *local_18 [2];
  
  lVar1 = IssueSyncWriteIrp(this,param_1,param_2);
  if (lVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_33c76d18363830779b81325d89363eda_Traceguids,lVar1);
    }
  }
  else if (param_3 != (IUnknown *)0x0) {
    local_18[0] = (longlong *)0x0;
    lVar1 = (*(code *)**(undefined8 **)param_3)(param_3,&IID_IWTSWriteCallback,local_18);
    if (-1 < lVar1) {
      (**(code **)(*local_18[0] + 0x18))(local_18[0],0);
      (**(code **)(*local_18[0] + 0x10))();
    }
  }
  return lVar1;
}



===== static_FreeIrp @ 14000bbc0 =====

/* private: static void __cdecl CKDynamicVC::static_FreeIrp(struct _IRP * __ptr64) */

void __cdecl CKDynamicVC::static_FreeIrp(_IRP *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  if (param_1 != (_IRP *)0x0) {
    puVar1 = *(undefined8 **)(param_1 + 8);
    *(undefined8 *)(param_1 + 8) = 0;
    while (puVar1 != (undefined8 *)0x0) {
      puVar2 = (undefined8 *)*puVar1;
      if ((*(byte *)((longlong)puVar1 + 10) & 2) != 0) {
        MmUnlockPages(puVar1);
      }
      IoFreeMdl(puVar1);
      puVar1 = puVar2;
    }
    if ((*(uint *)(param_1 + 0x10) & 0x20) != 0) {
      ExFreePool(*(undefined8 *)(param_1 + 0x18));
    }
    IoFreeIrp(param_1);
  }
  return;
}



===== static_MultiThreadPostReadCompletion @ 14000bc60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: static void __cdecl CKDynamicVC::static_MultiThreadPostReadCompletion(void * __ptr64) */

void __cdecl CKDynamicVC::static_MultiThreadPostReadCompletion(void *param_1)

{
  longlong lVar1;
  
  lVar1 = **(longlong **)((longlong)param_1 + 8);
  if (*(int *)((longlong)param_1 + 0x40) == 0) {
    (**(code **)(lVar1 + 0x18))
              (*(longlong **)((longlong)param_1 + 8),*(undefined4 *)((longlong)param_1 + 0x18),
               *(undefined8 *)((longlong)param_1 + 0x10));
  }
  else {
    (**(code **)(lVar1 + 0x20))();
  }
  if (*(void **)((longlong)param_1 + 0x10) != (void *)((longlong)param_1 + 0x44)) {
    operator_delete(*(void **)((longlong)param_1 + 0x10));
  }
  (**(code **)(**(longlong **)param_1 + 0x10))();
  (**(code **)(**(longlong **)((longlong)param_1 + 8) + 0x10))();
  operator_delete(param_1);
  return;
}



===== static_ReadCompletion @ 14000bce0 =====

/* private: static long __cdecl CKDynamicVC::static_ReadCompletion(struct _DEVICE_OBJECT *
   __ptr64,struct _IRP * __ptr64,void * __ptr64) */

long __cdecl CKDynamicVC::static_ReadCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  ReadCompletion(param_3,(_DEVICE_OBJECT *)param_2,param_2);
  return -0x3fffffea;
}



===== static_SingleThreadPostReadCompletion @ 14000bd00 =====

/* private: static void __cdecl CKDynamicVC::static_SingleThreadPostReadCompletion(void * __ptr64)
    */

void __cdecl CKDynamicVC::static_SingleThreadPostReadCompletion(void *param_1)

{
  SingleThreadPostReadCompletion(param_1);
  return;
}



===== static_WriteCompletion @ 14000bd20 =====

/* private: static long __cdecl CKDynamicVC::static_WriteCompletion(struct _DEVICE_OBJECT *
   __ptr64,struct _IRP * __ptr64,void * __ptr64) */

long __cdecl
CKDynamicVC::static_WriteCompletion(_DEVICE_OBJECT *param_1,_IRP *param_2,void *param_3)

{
  KeSetEvent(param_3,0,0);
  return -0x3fffffea;
}



===== WPP_SF_Pd @ 14000bd4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Pd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_33c76d18363830779b81325d89363eda_Traceguids,0x1d,&local_res20,8,
             &param_5,4,0);
  return;
}



===== CImplIUnknown<IRIMCapabilitiesNegotiator> @ 14000bda8 =====

/* public: __cdecl CImplIUnknown<struct IRIMCapabilitiesNegotiator>::CImplIUnknown<struct
   IRIMCapabilitiesNegotiator>(void) __ptr64 */

CImplIUnknown<IRIMCapabilitiesNegotiator> * __thiscall
CImplIUnknown<IRIMCapabilitiesNegotiator>::CImplIUnknown<IRIMCapabilitiesNegotiator>
          (CImplIUnknown<IRIMCapabilitiesNegotiator> *this)

{
  *(undefined4 *)(this + 8) = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0xc001d00d;
  return this;
}



===== CImplIUnknown<IRIMStub> @ 14000bdd0 =====

/* public: __cdecl CImplIUnknown<struct IRIMStub>::CImplIUnknown<struct IRIMStub>(void) __ptr64 */

CImplIUnknown<IRIMStub> * __thiscall
CImplIUnknown<IRIMStub>::CImplIUnknown<IRIMStub>(CImplIUnknown<IRIMStub> *this)

{
  *(undefined4 *)(this + 8) = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0xc001d00d;
  return this;
}



===== CImplIUnknown<ITsChannelNotification> @ 14000bdf8 =====

/* public: __cdecl CImplIUnknown<struct ITsChannelNotification>::CImplIUnknown<struct
   ITsChannelNotification>(void) __ptr64 */

CImplIUnknown<ITsChannelNotification> * __thiscall
CImplIUnknown<ITsChannelNotification>::CImplIUnknown<ITsChannelNotification>
          (CImplIUnknown<ITsChannelNotification> *this)

{
  *(undefined4 *)(this + 8) = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0xc001d00d;
  return this;
}



===== CImplIUnknown<ITsRequestCompletion> @ 14000be20 =====

/* public: __cdecl CImplIUnknown<struct ITsRequestCompletion>::CImplIUnknown<struct
   ITsRequestCompletion>(void) __ptr64 */

CImplIUnknown<ITsRequestCompletion> * __thiscall
CImplIUnknown<ITsRequestCompletion>::CImplIUnknown<ITsRequestCompletion>
          (CImplIUnknown<ITsRequestCompletion> *this)

{
  *(undefined4 *)(this + 8) = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0xc001d00d;
  return this;
}



===== CImplIUnknown<ITsUsbDevice> @ 14000be48 =====

/* public: __cdecl CImplIUnknown<struct ITsUsbDevice>::CImplIUnknown<struct ITsUsbDevice>(void)
   __ptr64 */

CImplIUnknown<ITsUsbDevice> * __thiscall
CImplIUnknown<ITsUsbDevice>::CImplIUnknown<ITsUsbDevice>(CImplIUnknown<ITsUsbDevice> *this)

{
  *(undefined4 *)(this + 8) = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0xc001d00d;
  return this;
}



===== CImplIUnknown<ITsUsbDeviceSink> @ 14000be70 =====

/* public: __cdecl CImplIUnknown<struct ITsUsbDeviceSink>::CImplIUnknown<struct
   ITsUsbDeviceSink>(void) __ptr64 */

CImplIUnknown<ITsUsbDeviceSink> * __thiscall
CImplIUnknown<ITsUsbDeviceSink>::CImplIUnknown<ITsUsbDeviceSink>
          (CImplIUnknown<ITsUsbDeviceSink> *this)

{
  *(undefined4 *)(this + 8) = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0xc001d00d;
  return this;
}



===== SmartPtr<IRIMStub> @ 14000be98 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl SmartPtr<struct IRIMStub>::SmartPtr<struct IRIMStub>(struct IRIMStub * __ptr64)
   __ptr64 */

SmartPtr<IRIMStub> * __thiscall
SmartPtr<IRIMStub>::SmartPtr<IRIMStub>(SmartPtr<IRIMStub> *this,IRIMStream *param_1)

{
  *(IRIMStream **)this = param_1;
  if (param_1 != (IRIMStream *)0x0) {
    (**(code **)(*(longlong *)param_1 + 8))(param_1);
  }
  return this;
}



===== ~CProxyIUnknown<IRIMCapabilitiesNegotiator> @ 14000bec8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual __cdecl CProxyIUnknown<struct IRIMCapabilitiesNegotiator>::~CProxyIUnknown<struct
   IRIMCapabilitiesNegotiator>(void) __ptr64 */

void __thiscall
CProxyIUnknown<IRIMCapabilitiesNegotiator>::~CProxyIUnknown<IRIMCapabilitiesNegotiator>
          (CProxyIUnknown<IRIMCapabilitiesNegotiator> *this)

{
  SmartPtr<CRIMStreamStub> *this_00;
  int iVar1;
  undefined4 local_res8 [2];
  longlong *local_res10;
  
  local_res10 = (longlong *)0x0;
  *(undefined ***)this = &_vftable_;
  this_00 = (SmartPtr<CRIMStreamStub> *)(this + 0x18);
  iVar1 = (**(code **)(**(longlong **)this_00 + 0x18))(*(longlong **)this_00,&local_res10);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res10 + 0x40))(local_res10,1);
    if (-1 < iVar1) {
      local_res8[0] = 0;
      (**(code **)(**(longlong **)this_00 + 0x20))(*(longlong **)this_00,local_res8);
      iVar1 = (**(code **)(*local_res10 + 0x188))(local_res10,local_res8[0],0);
      if (-1 < iVar1) {
        (**(code **)(*local_res10 + 0x20))();
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res10);
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>(this_00);
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &CImplIUnknown<IRIMCapabilitiesNegotiator>::_vftable_;
  return;
}



===== ~CProxyIUnknown<ITsChannelNotification> @ 14000bf9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual __cdecl CProxyIUnknown<struct ITsChannelNotification>::~CProxyIUnknown<struct
   ITsChannelNotification>(void) __ptr64 */

void __thiscall
CProxyIUnknown<ITsChannelNotification>::~CProxyIUnknown<ITsChannelNotification>
          (CProxyIUnknown<ITsChannelNotification> *this)

{
  SmartPtr<CRIMStreamStub> *this_00;
  int iVar1;
  undefined4 local_res8 [2];
  longlong *local_res10;
  
  local_res10 = (longlong *)0x0;
  *(undefined ***)this = &_vftable_;
  this_00 = (SmartPtr<CRIMStreamStub> *)(this + 0x18);
  iVar1 = (**(code **)(**(longlong **)this_00 + 0x18))(*(longlong **)this_00,&local_res10);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res10 + 0x40))(local_res10,1);
    if (-1 < iVar1) {
      local_res8[0] = 0;
      (**(code **)(**(longlong **)this_00 + 0x20))(*(longlong **)this_00,local_res8);
      iVar1 = (**(code **)(*local_res10 + 0x188))(local_res10,local_res8[0],0);
      if (-1 < iVar1) {
        (**(code **)(*local_res10 + 0x20))();
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res10);
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>(this_00);
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &CImplIUnknown<ITsChannelNotification>::_vftable_;
  return;
}



===== ~CProxyIUnknown<ITsRequestCompletion> @ 14000c070 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual __cdecl CProxyIUnknown<struct ITsRequestCompletion>::~CProxyIUnknown<struct
   ITsRequestCompletion>(void) __ptr64 */

void __thiscall
CProxyIUnknown<ITsRequestCompletion>::~CProxyIUnknown<ITsRequestCompletion>
          (CProxyIUnknown<ITsRequestCompletion> *this)

{
  SmartPtr<CRIMStreamStub> *this_00;
  int iVar1;
  undefined4 local_res8 [2];
  longlong *local_res10;
  
  local_res10 = (longlong *)0x0;
  *(undefined ***)this = &_vftable_;
  this_00 = (SmartPtr<CRIMStreamStub> *)(this + 0x18);
  iVar1 = (**(code **)(**(longlong **)this_00 + 0x18))(*(longlong **)this_00,&local_res10);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res10 + 0x40))(local_res10,1);
    if (-1 < iVar1) {
      local_res8[0] = 0;
      (**(code **)(**(longlong **)this_00 + 0x20))(*(longlong **)this_00,local_res8);
      iVar1 = (**(code **)(*local_res10 + 0x188))(local_res10,local_res8[0],0);
      if (-1 < iVar1) {
        (**(code **)(*local_res10 + 0x20))();
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res10);
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>(this_00);
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &CImplIUnknown<ITsRequestCompletion>::_vftable_;
  return;
}



===== ~CProxyIUnknown<ITsUsbDevice> @ 14000c144 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual __cdecl CProxyIUnknown<struct ITsUsbDevice>::~CProxyIUnknown<struct
   ITsUsbDevice>(void) __ptr64 */

void __thiscall
CProxyIUnknown<ITsUsbDevice>::~CProxyIUnknown<ITsUsbDevice>(CProxyIUnknown<ITsUsbDevice> *this)

{
  SmartPtr<CRIMStreamStub> *this_00;
  int iVar1;
  undefined4 local_res8 [2];
  longlong *local_res10;
  
  local_res10 = (longlong *)0x0;
  *(undefined ***)this = &_vftable_;
  this_00 = (SmartPtr<CRIMStreamStub> *)(this + 0x18);
  iVar1 = (**(code **)(**(longlong **)this_00 + 0x18))(*(longlong **)this_00,&local_res10);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res10 + 0x40))(local_res10,1);
    if (-1 < iVar1) {
      local_res8[0] = 0;
      (**(code **)(**(longlong **)this_00 + 0x20))(*(longlong **)this_00,local_res8);
      iVar1 = (**(code **)(*local_res10 + 0x188))(local_res10,local_res8[0],0);
      if (-1 < iVar1) {
        (**(code **)(*local_res10 + 0x20))();
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res10);
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>(this_00);
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &CImplIUnknown<ITsUsbDevice>::_vftable_;
  return;
}



===== ~CProxyIUnknown<ITsUsbDeviceSink> @ 14000c218 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual __cdecl CProxyIUnknown<struct ITsUsbDeviceSink>::~CProxyIUnknown<struct
   ITsUsbDeviceSink>(void) __ptr64 */

void __thiscall
CProxyIUnknown<ITsUsbDeviceSink>::~CProxyIUnknown<ITsUsbDeviceSink>
          (CProxyIUnknown<ITsUsbDeviceSink> *this)

{
  SmartPtr<CRIMStreamStub> *this_00;
  int iVar1;
  undefined4 local_res8 [2];
  longlong *local_res10;
  
  local_res10 = (longlong *)0x0;
  *(undefined ***)this = &_vftable_;
  this_00 = (SmartPtr<CRIMStreamStub> *)(this + 0x18);
  iVar1 = (**(code **)(**(longlong **)this_00 + 0x18))(*(longlong **)this_00,&local_res10);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res10 + 0x40))(local_res10,1);
    if (-1 < iVar1) {
      local_res8[0] = 0;
      (**(code **)(**(longlong **)this_00 + 0x20))(*(longlong **)this_00,local_res8);
      iVar1 = (**(code **)(*local_res10 + 0x188))(local_res10,local_res8[0],0);
      if (-1 < iVar1) {
        (**(code **)(*local_res10 + 0x20))();
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res10);
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>(this_00);
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &CImplIUnknown<ITsUsbDeviceSink>::_vftable_;
  return;
}



===== ~CStub<ITsRequestCompletion> @ 14000c2ec =====

/* public: virtual __cdecl CStub<struct ITsRequestCompletion>::~CStub<struct
   ITsRequestCompletion>(void) __ptr64 */

void __thiscall
CStub<ITsRequestCompletion>::~CStub<ITsRequestCompletion>(CStub<ITsRequestCompletion> *this)

{
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)(this + 0x18));
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &CImplIUnknown<IRIMStub>::_vftable_;
  return;
}



===== ~SmartPtr<CRIMStreamStub> @ 14000c31c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl SmartPtr<class CRIMStreamStub>::~SmartPtr<class CRIMStreamStub>(void) __ptr64 */

void __thiscall SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>(SmartPtr<CRIMStreamStub> *this)

{
  if (*(longlong **)this != (longlong *)0x0) {
    (**(code **)(**(longlong **)this + 0x10))();
  }
  return;
}



===== `vector_deleting_destructor' @ 14000c340 =====

/* public: virtual void * __ptr64 __cdecl CImplIUnknown<struct IRIMCapabilitiesNegotiator>::`vector
   deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
CImplIUnknown<IRIMCapabilitiesNegotiator>::_vector_deleting_destructor_
          (CImplIUnknown<IRIMCapabilitiesNegotiator> *this,uint param_1)

{
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 14000c380 =====

/* public: virtual void * __ptr64 __cdecl CImplIUnknown<struct IRIMStub>::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CImplIUnknown<IRIMStub>::_scalar_deleting_destructor_(CImplIUnknown<IRIMStub> *this,uint param_1)

{
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `vector_deleting_destructor' @ 14000c3c0 =====

/* public: virtual void * __ptr64 __cdecl CImplIUnknown<struct ITsChannelNotification>::`vector
   deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
CImplIUnknown<ITsChannelNotification>::_vector_deleting_destructor_
          (CImplIUnknown<ITsChannelNotification> *this,uint param_1)

{
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `vector_deleting_destructor' @ 14000c400 =====

/* public: virtual void * __ptr64 __cdecl CImplIUnknown<struct ITsRequestCompletion>::`vector
   deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
CImplIUnknown<ITsRequestCompletion>::_vector_deleting_destructor_
          (CImplIUnknown<ITsRequestCompletion> *this,uint param_1)

{
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 14000c440 =====

/* public: virtual void * __ptr64 __cdecl CImplIUnknown<struct ITsUsbDevice>::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CImplIUnknown<ITsUsbDevice>::_scalar_deleting_destructor_
          (CImplIUnknown<ITsUsbDevice> *this,uint param_1)

{
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 14000c480 =====

/* public: virtual void * __ptr64 __cdecl CImplIUnknown<struct ITsUsbDeviceSink>::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CImplIUnknown<ITsUsbDeviceSink>::_scalar_deleting_destructor_
          (CImplIUnknown<ITsUsbDeviceSink> *this,uint param_1)

{
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 14000c4c0 =====

/* public: virtual void * __ptr64 __cdecl CProxyIUnknown<struct IRIMCapabilitiesNegotiator>::`scalar
   deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
CProxyIUnknown<IRIMCapabilitiesNegotiator>::_scalar_deleting_destructor_
          (CProxyIUnknown<IRIMCapabilitiesNegotiator> *this,uint param_1)

{
  ~CProxyIUnknown<IRIMCapabilitiesNegotiator>(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `vector_deleting_destructor' @ 14000c510 =====

/* public: virtual void * __ptr64 __cdecl CProxyITsChannelNotification<struct
   ITsChannelNotification>::`vector deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
CProxyITsChannelNotification<ITsChannelNotification>::_vector_deleting_destructor_
          (CProxyITsChannelNotification<ITsChannelNotification> *this,uint param_1)

{
  CProxyIUnknown<ITsChannelNotification>::~CProxyIUnknown<ITsChannelNotification>
            ((CProxyIUnknown<ITsChannelNotification> *)this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `vector_deleting_destructor' @ 14000c560 =====

/* public: virtual void * __ptr64 __cdecl CProxyITsRequestCompletion<struct
   ITsRequestCompletion>::`vector deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
CProxyITsRequestCompletion<ITsRequestCompletion>::_vector_deleting_destructor_
          (CProxyITsRequestCompletion<ITsRequestCompletion> *this,uint param_1)

{
  CProxyIUnknown<ITsRequestCompletion>::~CProxyIUnknown<ITsRequestCompletion>
            ((CProxyIUnknown<ITsRequestCompletion> *)this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 14000c5b0 =====

/* public: virtual void * __ptr64 __cdecl CProxyIUnknown<struct ITsUsbDevice>::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CProxyIUnknown<ITsUsbDevice>::_scalar_deleting_destructor_
          (CProxyIUnknown<ITsUsbDevice> *this,uint param_1)

{
  ~CProxyIUnknown<ITsUsbDevice>(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 14000c600 =====

/* public: virtual void * __ptr64 __cdecl CProxyIUnknown<struct ITsUsbDeviceSink>::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CProxyIUnknown<ITsUsbDeviceSink>::_scalar_deleting_destructor_
          (CProxyIUnknown<ITsUsbDeviceSink> *this,uint param_1)

{
  ~CProxyIUnknown<ITsUsbDeviceSink>(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `vector_deleting_destructor' @ 14000c650 =====

/* public: virtual void * __ptr64 __cdecl CStubIRIMCapabilitiesNegotiator<struct
   IRIMCapabilitiesNegotiator>::`vector deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
CStubIRIMCapabilitiesNegotiator<IRIMCapabilitiesNegotiator>::_vector_deleting_destructor_
          (CStubIRIMCapabilitiesNegotiator<IRIMCapabilitiesNegotiator> *this,uint param_1)

{
  CStub<ITsRequestCompletion>::~CStub<ITsRequestCompletion>((CStub<ITsRequestCompletion> *)this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== AddDevice @ 14000c6a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyITsUsbDeviceSink<struct ITsUsbDeviceSink>::AddDevice(struct
   ITsUsbDevice * __ptr64,unsigned long,unsigned short * __ptr64,unsigned long,unsigned short *
   __ptr64,unsigned long,unsigned short * __ptr64,unsigned long,unsigned short * __ptr64,struct
   _USB_DEVICE_CAPABILITIES * __ptr64) __ptr64 */

long __thiscall
CProxyITsUsbDeviceSink<ITsUsbDeviceSink>::AddDevice
          (CProxyITsUsbDeviceSink<ITsUsbDeviceSink> *this,ITsUsbDevice *param_1,ulong param_2,
          ushort *param_3,ulong param_4,ushort *param_5,ulong param_6,ushort *param_7,ulong param_8,
          ushort *param_9,_USB_DEVICE_CAPABILITIES *param_10)

{
  int iVar1;
  ulong uVar2;
  IMessage *local_res8;
  ITsUsbDevice *local_res10;
  ulong local_res18 [2];
  
  local_res8 = (IMessage *)0x0;
  local_res10 = param_1;
  local_res18[0] = param_2;
  iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                    (*(longlong **)(this + 0x18),&local_res8);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*(longlong *)local_res8 + 0x40))(local_res8,0x101);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*(longlong *)local_res8 + 0xd0))
                        (local_res8,&local_res10,&_GUID_46c9f566_3412_42e9_a43e_4d9926956afe,1);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*(longlong *)local_res8 + 0x98))(local_res8,local_res18,1);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*(longlong *)local_res8 + 0x88))(local_res8,param_3,local_res18[0]);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*(longlong *)local_res8 + 0x98))(local_res8,&param_4,1);
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*(longlong *)local_res8 + 0x88))(local_res8,param_5,param_4);
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*(longlong *)local_res8 + 0x98))(local_res8,&param_6,1);
                if (-1 < iVar1) {
                  iVar1 = (**(code **)(*(longlong *)local_res8 + 0x88))(local_res8,param_7,param_6);
                  if (-1 < iVar1) {
                    iVar1 = (**(code **)(*(longlong *)local_res8 + 0x98))(local_res8,&param_8,1);
                    if (-1 < iVar1) {
                      uVar2 = param_8;
                      iVar1 = (**(code **)(*(longlong *)local_res8 + 0x88))(local_res8,param_9);
                      if (-1 < iVar1) {
                        iVar1 = CProxyWrite_USB_DEVICE_CAPABILITIES(local_res8,param_10,uVar2);
                        if (-1 < iVar1) {
                          iVar1 = (**(code **)(*(longlong *)local_res8 + 0x20))();
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res8);
  return iVar1;
}



===== AddNewVirtualChannel @ 14000c890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyITsUsbDeviceSink<struct
   ITsUsbDeviceSink>::AddNewVirtualChannel(void) __ptr64 */

long __thiscall
CProxyITsUsbDeviceSink<ITsUsbDeviceSink>::AddNewVirtualChannel
          (CProxyITsUsbDeviceSink<ITsUsbDeviceSink> *this)

{
  int iVar1;
  longlong *local_res8 [4];
  
  local_res8[0] = (longlong *)0x0;
  iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))(*(longlong **)(this + 0x18),local_res8)
  ;
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res8[0] + 0x40))(local_res8[0],0x100);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res8[0] + 0x20))();
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)local_res8);
  return iVar1;
}



===== AddRef @ 14000c900 =====

/* public: virtual unsigned long __cdecl CImplIUnknown<struct ITsChannelNotification>::AddRef(void)
   __ptr64 */

ulong __thiscall
CImplIUnknown<ITsChannelNotification>::AddRef(CImplIUnknown<ITsChannelNotification> *this)

{
  CImplIUnknown<ITsChannelNotification> *pCVar1;
  int iVar2;
  
  LOCK();
  pCVar1 = this + 0xc;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + 1;
  UNLOCK();
  return iVar2 + 1;
}



===== CProxyReceive_URBDR_VERSION @ 14000c914 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl CProxyReceive_URBDR_VERSION(struct IMessage * __ptr64,struct _URBDR_VERSION *
   __ptr64,unsigned long) */

long __cdecl CProxyReceive_URBDR_VERSION(IMessage *param_1,_URBDR_VERSION *param_2,ulong param_3)

{
  int iVar1;
  _URBDR_VERSION *p_Var2;
  int iVar3;
  
  p_Var2 = param_2 + 8;
  iVar3 = 1;
  do {
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,p_Var2 + -8,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,p_Var2 + -4,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,p_Var2,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    p_Var2 = p_Var2 + 0xc;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar1;
}



===== CProxyReceive_USB_DEVICE_CAPABILITIES @ 14000c9b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl CProxyReceive_USB_DEVICE_CAPABILITIES(struct IMessage * __ptr64,struct
   _USB_DEVICE_CAPABILITIES * __ptr64,unsigned long) */

long __cdecl
CProxyReceive_USB_DEVICE_CAPABILITIES
          (IMessage *param_1,_USB_DEVICE_CAPABILITIES *param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  _USB_DEVICE_CAPABILITIES *p_Var3;
  
  p_Var3 = param_2 + 8;
  iVar2 = 1;
  do {
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,p_Var3 + -8,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,p_Var3 + -4,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,p_Var3,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,p_Var3 + 4,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,p_Var3 + 8,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,p_Var3 + 0xc,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,p_Var3 + 0x10,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    p_Var3 = p_Var3 + 0x1c;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return iVar1;
}



===== CProxyWrite_URBDR_VERSION @ 14000cad4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl CProxyWrite_URBDR_VERSION(struct IMessage * __ptr64,struct _URBDR_VERSION *
   __ptr64,unsigned long) */

long __cdecl CProxyWrite_URBDR_VERSION(IMessage *param_1,_URBDR_VERSION *param_2,ulong param_3)

{
  int iVar1;
  _URBDR_VERSION *p_Var2;
  int iVar3;
  
  p_Var2 = param_2 + 8;
  iVar3 = 1;
  do {
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x98))(param_1,p_Var2 + -8,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x98))(param_1,p_Var2 + -4,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x98))(param_1,p_Var2,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    p_Var2 = p_Var2 + 0xc;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar1;
}



===== CProxyWrite_USB_DEVICE_CAPABILITIES @ 14000cb70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl CProxyWrite_USB_DEVICE_CAPABILITIES(struct IMessage * __ptr64,struct
   _USB_DEVICE_CAPABILITIES * __ptr64,unsigned long) */

long __cdecl
CProxyWrite_USB_DEVICE_CAPABILITIES
          (IMessage *param_1,_USB_DEVICE_CAPABILITIES *param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  _USB_DEVICE_CAPABILITIES *p_Var3;
  
  p_Var3 = param_2 + 8;
  iVar2 = 1;
  do {
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x98))(param_1,p_Var3 + -8,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x98))(param_1,p_Var3 + -4,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x98))(param_1,p_Var3,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x98))(param_1,p_Var3 + 4,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x98))(param_1,p_Var3 + 8,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x98))(param_1,p_Var3 + 0xc,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x98))(param_1,p_Var3 + 0x10,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    p_Var3 = p_Var3 + 0x1c;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return iVar1;
}



===== CancelRequest @ 14000cca0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyITsUsbDevice<struct ITsUsbDevice>::CancelRequest(unsigned
   long) __ptr64 */

long __thiscall
CProxyITsUsbDevice<ITsUsbDevice>::CancelRequest
          (CProxyITsUsbDevice<ITsUsbDevice> *this,ulong param_1)

{
  int iVar1;
  longlong *local_res8;
  ulong local_res10 [6];
  
  local_res8 = (longlong *)0x0;
  local_res10[0] = param_1;
  iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                    (*(longlong **)(this + 0x18),&local_res8);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res8 + 0x40))(local_res8,0x100);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,local_res10,1);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_res8 + 0x20))();
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res8);
  return iVar1;
}



===== ChannelCreated @ 14000cd40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyITsChannelNotification<struct
   ITsChannelNotification>::ChannelCreated(struct _URBDR_VERSION * __ptr64) __ptr64 */

long __thiscall
CProxyITsChannelNotification<ITsChannelNotification>::ChannelCreated
          (CProxyITsChannelNotification<ITsChannelNotification> *this,_URBDR_VERSION *param_1)

{
  int iVar1;
  ulong in_R8D;
  IMessage *local_res8;
  
  local_res8 = (IMessage *)0x0;
  iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                    (*(longlong **)(this + 0x18),&local_res8);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*(longlong *)local_res8 + 0x40))(local_res8,0x100);
    if (-1 < iVar1) {
      iVar1 = CProxyWrite_URBDR_VERSION(local_res8,param_1,in_R8D);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*(longlong *)local_res8 + 0x20))();
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res8);
  return iVar1;
}



===== Dispatch_Invoke @ 14000cdd0 =====

/* public: virtual long __cdecl CStub<struct ITsUsbDevice>::Dispatch_Invoke(struct IMessage *
   __ptr64,unsigned long,int * __ptr64) __ptr64 */

long __thiscall
CStub<ITsUsbDevice>::Dispatch_Invoke
          (CStub<ITsUsbDevice> *this,IMessage *param_1,ulong param_2,int *param_3)

{
  *param_3 = 1;
  return -0x7fffbfff;
}



===== Dispatch_Invoke @ 14000cdf0 =====

/* public: virtual long __cdecl CStubIRIMCapabilitiesNegotiator<struct
   IRIMCapabilitiesNegotiator>::Dispatch_Invoke(struct IMessage * __ptr64,unsigned long,int *
   __ptr64) __ptr64 */

long __thiscall
CStubIRIMCapabilitiesNegotiator<IRIMCapabilitiesNegotiator>::Dispatch_Invoke
          (CStubIRIMCapabilitiesNegotiator<IRIMCapabilitiesNegotiator> *this,IMessage *param_1,
          ulong param_2,int *param_3)

{
  long lVar1;
  
  if (param_2 == 0x100) {
    lVar1 = Invoke_ExchangeCapabilities(this,param_1);
  }
  else {
    lVar1 = 0;
    *param_3 = 1;
  }
  return lVar1;
}



===== Dispatch_Invoke @ 14000ce20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CStubITsChannelNotification<struct
   ITsChannelNotification>::Dispatch_Invoke(struct IMessage * __ptr64,unsigned long,int * __ptr64)
   __ptr64 */

long __thiscall
CStubITsChannelNotification<ITsChannelNotification>::Dispatch_Invoke
          (CStubITsChannelNotification<ITsChannelNotification> *this,IMessage *param_1,ulong param_2
          ,int *param_3)

{
  long lVar1;
  _URBDR_VERSION *p_Var2;
  ulong uVar3;
  
  if (param_2 == 0x100) {
    uVar3 = 0x72447244;
    p_Var2 = (_URBDR_VERSION *)ExAllocatePoolWithTag(0x200,0xc);
    if (p_Var2 == (_URBDR_VERSION *)0x0) {
      lVar1 = -0x7ff8fff2;
    }
    else {
      *(undefined8 *)p_Var2 = 0;
      *(undefined4 *)(p_Var2 + 8) = 0;
      lVar1 = CProxyReceive_URBDR_VERSION(param_1,p_Var2,uVar3);
      if (-1 < lVar1) {
        (**(code **)(**(longlong **)(this + 0x18) + 0x18))(*(longlong **)(this + 0x18),p_Var2);
      }
    }
    RIM_USER_FREE(p_Var2);
  }
  else {
    lVar1 = 0;
    *param_3 = 1;
  }
  return lVar1;
}



===== Dispatch_Invoke @ 14000ced0 =====

/* public: virtual long __cdecl CStubITsRequestCompletion<struct
   ITsRequestCompletion>::Dispatch_Invoke(struct IMessage * __ptr64,unsigned long,int * __ptr64)
   __ptr64 */

long __thiscall
CStubITsRequestCompletion<ITsRequestCompletion>::Dispatch_Invoke
          (CStubITsRequestCompletion<ITsRequestCompletion> *this,IMessage *param_1,ulong param_2,
          int *param_3)

{
  long lVar1;
  
  if (param_2 == 0x100) {
    lVar1 = Invoke_IoControlCompleteRequest(this,param_1);
  }
  else if (param_2 == 0x101) {
    lVar1 = Invoke_UrbCompletion(this,param_1);
  }
  else if (param_2 == 0x102) {
    lVar1 = Invoke_UrbCompletionNoData(this,param_1);
  }
  else {
    lVar1 = 0;
    *param_3 = 1;
  }
  return lVar1;
}



===== Dispatch_Invoke @ 14000cf20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CStubITsUsbDevice<struct ITsUsbDevice>::Dispatch_Invoke(struct
   IMessage * __ptr64,unsigned long,int * __ptr64) __ptr64 */

long __thiscall
CStubITsUsbDevice<ITsUsbDevice>::Dispatch_Invoke
          (CStubITsUsbDevice<ITsUsbDevice> *this,IMessage *param_1,ulong param_2,int *param_3)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  longlong *plVar4;
  undefined4 local_res18 [4];
  longlong *local_18 [2];
  
  if (param_2 == 0x100) {
    local_res18[0] = 0;
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res18,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    plVar4 = *(longlong **)(this + 0x18);
    pcVar3 = *(code **)(*plVar4 + 0x18);
  }
  else {
    if (param_2 == 0x101) {
      local_18[0] = (longlong *)0x0;
      iVar1 = (**(code **)(*(longlong *)param_1 + 0x180))
                        (param_1,local_18,&_GUID_0493a1ca_29aa_4691_89c8_0afbf61cfa12,1);
      if (-1 < iVar1) {
        (**(code **)(**(longlong **)(this + 0x18) + 0x20))(*(longlong **)(this + 0x18),local_18[0]);
      }
      if (local_18[0] == (longlong *)0x0) {
        return iVar1;
      }
      (**(code **)(*local_18[0] + 0x10))();
      return iVar1;
    }
    if (param_2 == 0x102) {
      lVar2 = Invoke_UsbIoControl(this,param_1);
      return lVar2;
    }
    if (param_2 == 0x103) {
      lVar2 = Invoke_UsbInternalIoControl(this,param_1);
      return lVar2;
    }
    if (param_2 == 0x104) {
      lVar2 = Invoke_PnpQueryDeviceTextDescription(this,param_1);
      return lVar2;
    }
    if (param_2 == 0x105) {
      lVar2 = Invoke_UrbTransferInRequest(this,param_1);
      return lVar2;
    }
    if (param_2 == 0x106) {
      lVar2 = Invoke_UrbTransferOutRequest(this,param_1);
      return lVar2;
    }
    if (param_2 != 0x107) {
      *param_3 = 1;
      return 0;
    }
    local_res18[0] = 0;
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res18,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    plVar4 = *(longlong **)(this + 0x18);
    pcVar3 = *(code **)(*plVar4 + 0x50);
  }
  (*pcVar3)(plVar4,local_res18[0]);
  return iVar1;
}



===== Dispatch_Invoke @ 14000d0a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CStubITsUsbDeviceSink<struct
   ITsUsbDeviceSink>::Dispatch_Invoke(struct IMessage * __ptr64,unsigned long,int * __ptr64) __ptr64
    */

long __thiscall
CStubITsUsbDeviceSink<ITsUsbDeviceSink>::Dispatch_Invoke
          (CStubITsUsbDeviceSink<ITsUsbDeviceSink> *this,IMessage *param_1,ulong param_2,
          int *param_3)

{
  long lVar1;
  
  if (param_2 == 0x100) {
    (**(code **)(**(longlong **)(this + 0x18) + 0x18))();
  }
  else {
    if (param_2 == 0x101) {
      lVar1 = Invoke_AddDevice(this,param_1);
      return lVar1;
    }
    *param_3 = 1;
  }
  return 0;
}



===== ExchangeCapabilities @ 14000d0f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyIRIMCapabilitiesNegotiator<struct
   IRIMCapabilitiesNegotiator>::ExchangeCapabilities(unsigned long,unsigned long * __ptr64) __ptr64
    */

long __thiscall
CProxyIRIMCapabilitiesNegotiator<IRIMCapabilitiesNegotiator>::ExchangeCapabilities
          (CProxyIRIMCapabilitiesNegotiator<IRIMCapabilitiesNegotiator> *this,ulong param_1,
          ulong *param_2)

{
  int iVar1;
  int local_res8 [2];
  ulong local_res10 [4];
  longlong *local_res20;
  
  local_res20 = (longlong *)0x0;
  local_res8[0] = -0x7fffbfff;
  local_res10[0] = param_1;
  iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                    (*(longlong **)(this + 0x18),&local_res20);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res20 + 0x40))(local_res20,0x100);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res20 + 0x98))(local_res20,local_res10,1);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_res20 + 0x20))();
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_res20 + 0xd8))();
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_res20 + 0x148))(local_res20,param_2,1);
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*local_res20 + 0xe8))(local_res20,local_res8);
              if (-1 < iVar1) {
                iVar1 = local_res8[0];
              }
            }
          }
        }
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res20);
  return iVar1;
}



===== GetInstanceOfProxy @ 14000d200 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GetInstanceOfProxy(longlong *param_1,IRIMStream *param_2,undefined8 *param_3)

{
  CImplIUnknown<IRIMCapabilitiesNegotiator> *this;
  undefined **ppuVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar2 = *param_1;
  lVar3 = 0x4ce0e9c117accf68 - lVar2;
  if (lVar3 == 0) {
    lVar3 = 0xfb346c80db91cfa6 - param_1[1];
  }
  if (lVar3 == 0) {
    this = (CImplIUnknown<IRIMCapabilitiesNegotiator> *)ExAllocatePoolWithTag(0x200,0x20,0x6c6d6952)
    ;
    if (this == (CImplIUnknown<IRIMCapabilitiesNegotiator> *)0x0) goto LAB_14000d44a;
    CImplIUnknown<IRIMCapabilitiesNegotiator>::CImplIUnknown<IRIMCapabilitiesNegotiator>(this);
    *(undefined ***)this = &CProxyIUnknown<IRIMCapabilitiesNegotiator>::_vftable_;
    SmartPtr<IRIMStub>::SmartPtr<IRIMStub>((SmartPtr<IRIMStub> *)(this + 0x18),param_2);
    ppuVar1 = &CProxyIRIMCapabilitiesNegotiator<IRIMCapabilitiesNegotiator>::_vftable_;
  }
  else {
    lVar3 = 0x46bb20efeb9d428c - lVar2;
    if (lVar3 == 0) {
      lVar3 = 0xf065bf1c22b6b7b2 - param_1[1];
    }
    if (lVar3 == 0) {
      this = (CImplIUnknown<IRIMCapabilitiesNegotiator> *)
             ExAllocatePoolWithTag(0x200,0x20,0x6c6d6952);
      if (this == (CImplIUnknown<IRIMCapabilitiesNegotiator> *)0x0) goto LAB_14000d44a;
      CImplIUnknown<ITsChannelNotification>::CImplIUnknown<ITsChannelNotification>
                ((CImplIUnknown<ITsChannelNotification> *)this);
      *(undefined ***)this = &CProxyIUnknown<ITsChannelNotification>::_vftable_;
      SmartPtr<IRIMStub>::SmartPtr<IRIMStub>((SmartPtr<IRIMStub> *)(this + 0x18),param_2);
      ppuVar1 = &CProxyITsChannelNotification<ITsChannelNotification>::_vftable_;
    }
    else {
      lVar3 = 0x469129aa0493a1ca - lVar2;
      if (lVar3 == 0) {
        lVar3 = 0x12fa1cf6fb0ac889 - param_1[1];
      }
      if (lVar3 == 0) {
        this = (CImplIUnknown<IRIMCapabilitiesNegotiator> *)
               ExAllocatePoolWithTag(0x200,0x20,0x6c6d6952);
        if (this == (CImplIUnknown<IRIMCapabilitiesNegotiator> *)0x0) goto LAB_14000d44a;
        CImplIUnknown<ITsRequestCompletion>::CImplIUnknown<ITsRequestCompletion>
                  ((CImplIUnknown<ITsRequestCompletion> *)this);
        *(undefined ***)this = &CProxyIUnknown<ITsRequestCompletion>::_vftable_;
        SmartPtr<IRIMStub>::SmartPtr<IRIMStub>((SmartPtr<IRIMStub> *)(this + 0x18),param_2);
        ppuVar1 = &CProxyITsRequestCompletion<ITsRequestCompletion>::_vftable_;
      }
      else {
        lVar3 = 0x42e9341246c9f566 - lVar2;
        if (lVar3 == 0) {
          lVar3 = 0xfe6a9526994d3ea4 - param_1[1];
        }
        if (lVar3 == 0) {
          this = (CImplIUnknown<IRIMCapabilitiesNegotiator> *)
                 ExAllocatePoolWithTag(0x200,0x20,0x6c6d6952);
          if (this == (CImplIUnknown<IRIMCapabilitiesNegotiator> *)0x0) {
LAB_14000d44a:
            *param_3 = 0;
            return 0x8007000e;
          }
          CImplIUnknown<ITsUsbDevice>::CImplIUnknown<ITsUsbDevice>
                    ((CImplIUnknown<ITsUsbDevice> *)this);
          *(undefined ***)this = &CProxyIUnknown<ITsUsbDevice>::_vftable_;
          SmartPtr<IRIMStub>::SmartPtr<IRIMStub>((SmartPtr<IRIMStub> *)(this + 0x18),param_2);
          ppuVar1 = &CProxyITsUsbDevice<ITsUsbDevice>::_vftable_;
        }
        else {
          lVar2 = 0x45c343f5cec617f6 - lVar2;
          if (lVar2 == 0) {
            lVar2 = 0xd47c11ea06131e97 - param_1[1];
          }
          if (lVar2 != 0) {
            return 0x80004002;
          }
          this = (CImplIUnknown<IRIMCapabilitiesNegotiator> *)
                 ExAllocatePoolWithTag(0x200,0x20,0x6c6d6952);
          if (this == (CImplIUnknown<IRIMCapabilitiesNegotiator> *)0x0) goto LAB_14000d44a;
          CImplIUnknown<ITsUsbDeviceSink>::CImplIUnknown<ITsUsbDeviceSink>
                    ((CImplIUnknown<ITsUsbDeviceSink> *)this);
          *(undefined ***)this = &CProxyIUnknown<ITsUsbDeviceSink>::_vftable_;
          SmartPtr<IRIMStub>::SmartPtr<IRIMStub>((SmartPtr<IRIMStub> *)(this + 0x18),param_2);
          ppuVar1 = &CProxyITsUsbDeviceSink<ITsUsbDeviceSink>::_vftable_;
        }
      }
    }
  }
  *(undefined ***)this = ppuVar1;
  *param_3 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== GetInstanceOfStub @ 14000d480 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GetInstanceOfStub(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  CImplIUnknown<IRIMStub> *this;
  undefined **ppuVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar3 = *param_1;
  lVar2 = 0x4ce0e9c117accf68 - lVar3;
  if (lVar2 == 0) {
    lVar2 = 0xfb346c80db91cfa6 - param_1[1];
  }
  if (lVar2 == 0) {
    this = (CImplIUnknown<IRIMStub> *)ExAllocatePoolWithTag(0x200,0x28,0x6c6d6952);
    if (this == (CImplIUnknown<IRIMStub> *)0x0) goto LAB_14000d70b;
    CImplIUnknown<IRIMStub>::CImplIUnknown<IRIMStub>(this);
    *(undefined ***)this = &CStub<ITsRequestCompletion>::_vftable_;
    *(longlong **)(this + 0x18) = param_2;
    if (param_2 != (longlong *)0x0) {
      (**(code **)(*param_2 + 8))(param_2);
    }
    ppuVar1 = &CStubIRIMCapabilitiesNegotiator<IRIMCapabilitiesNegotiator>::_vftable_;
  }
  else {
    lVar2 = 0x46bb20efeb9d428c - lVar3;
    if (lVar2 == 0) {
      lVar2 = 0xf065bf1c22b6b7b2 - param_1[1];
    }
    if (lVar2 == 0) {
      this = (CImplIUnknown<IRIMStub> *)ExAllocatePoolWithTag(0x200,0x28,0x6c6d6952);
      if (this == (CImplIUnknown<IRIMStub> *)0x0) goto LAB_14000d70b;
      CImplIUnknown<IRIMStub>::CImplIUnknown<IRIMStub>(this);
      *(undefined ***)this = &CStub<ITsRequestCompletion>::_vftable_;
      *(longlong **)(this + 0x18) = param_2;
      if (param_2 != (longlong *)0x0) {
        (**(code **)(*param_2 + 8))(param_2);
      }
      ppuVar1 = &CStubITsChannelNotification<ITsChannelNotification>::_vftable_;
    }
    else {
      lVar2 = 0x469129aa0493a1ca - lVar3;
      if (lVar2 == 0) {
        lVar2 = 0x12fa1cf6fb0ac889 - param_1[1];
      }
      if (lVar2 == 0) {
        this = (CImplIUnknown<IRIMStub> *)ExAllocatePoolWithTag(0x200,0x28,0x6c6d6952);
        if (this == (CImplIUnknown<IRIMStub> *)0x0) goto LAB_14000d70b;
        CImplIUnknown<IRIMStub>::CImplIUnknown<IRIMStub>(this);
        *(undefined ***)this = &CStub<ITsRequestCompletion>::_vftable_;
        *(longlong **)(this + 0x18) = param_2;
        if (param_2 != (longlong *)0x0) {
          (**(code **)(*param_2 + 8))(param_2);
        }
        ppuVar1 = &CStubITsRequestCompletion<ITsRequestCompletion>::_vftable_;
      }
      else {
        lVar2 = 0x42e9341246c9f566 - lVar3;
        if (lVar2 == 0) {
          lVar2 = 0xfe6a9526994d3ea4 - param_1[1];
        }
        if (lVar2 == 0) {
          this = (CImplIUnknown<IRIMStub> *)ExAllocatePoolWithTag(0x200,0x28,0x6c6d6952);
          if (this == (CImplIUnknown<IRIMStub> *)0x0) {
LAB_14000d70b:
            *param_3 = 0;
            return 0x8007000e;
          }
          CImplIUnknown<IRIMStub>::CImplIUnknown<IRIMStub>(this);
          *(undefined ***)this = &CStub<ITsRequestCompletion>::_vftable_;
          *(longlong **)(this + 0x18) = param_2;
          if (param_2 != (longlong *)0x0) {
            (**(code **)(*param_2 + 8))(param_2);
          }
          ppuVar1 = &CStubITsUsbDevice<ITsUsbDevice>::_vftable_;
        }
        else {
          lVar3 = 0x45c343f5cec617f6 - lVar3;
          if (lVar3 == 0) {
            lVar3 = 0xd47c11ea06131e97 - param_1[1];
          }
          if (lVar3 != 0) {
            return 0x80004002;
          }
          this = (CImplIUnknown<IRIMStub> *)ExAllocatePoolWithTag(0x200,0x28,0x6c6d6952);
          if (this == (CImplIUnknown<IRIMStub> *)0x0) goto LAB_14000d70b;
          CImplIUnknown<IRIMStub>::CImplIUnknown<IRIMStub>(this);
          *(undefined ***)this = &CStub<ITsRequestCompletion>::_vftable_;
          *(longlong **)(this + 0x18) = param_2;
          if (param_2 != (longlong *)0x0) {
            (**(code **)(*param_2 + 8))(param_2);
          }
          ppuVar1 = &CStubITsUsbDeviceSink<ITsUsbDeviceSink>::_vftable_;
        }
      }
    }
  }
  *(undefined4 *)(this + 0x20) = 0xffffffff;
  *(undefined ***)this = ppuVar1;
  *param_3 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== Invoke @ 14000d740 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual long __cdecl CStub<struct ITsChannelNotification>::Invoke(struct IMessage *
   __ptr64) __ptr64 */

long __thiscall
CStub<ITsChannelNotification>::Invoke(CStub<ITsChannelNotification> *this,IMessage *param_1)

{
  int iVar1;
  long lVar2;
  undefined4 uVar3;
  undefined1 auStack_78 [48];
  undefined8 local_48;
  int local_40;
  int local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  local_40 = 0;
  iVar1 = (**(code **)(*(longlong *)param_1 + 0xf0))(param_1,&local_40);
  if (iVar1 < 0) {
    return iVar1;
  }
  if (local_40 == 1) {
    lVar2 = (**(code **)(*(longlong *)param_1 + 0x188))(param_1,*(undefined4 *)(this + 0x20),1);
  }
  else {
    if (local_40 == 2) {
      local_48 = 0;
      local_38 = 0;
      uStack_30 = 0;
      iVar1 = (**(code **)(*(longlong *)param_1 + 0xf8))(param_1,&local_38);
      if (-1 < iVar1) {
        uVar3 = (**(code **)**(undefined8 **)(this + 0x18))
                          (*(undefined8 **)(this + 0x18),&local_38,&local_48);
        (**(code **)(*(longlong *)param_1 + 0x18))(param_1);
        iVar1 = (**(code **)(*(longlong *)param_1 + 0xd0))(param_1,&local_48,&local_38,1);
        if ((-1 < iVar1) &&
           (iVar1 = (**(code **)(*(longlong *)param_1 + 0x38))(param_1,uVar3), -1 < iVar1)) {
          iVar1 = (**(code **)(*(longlong *)param_1 + 0x20))(param_1);
        }
      }
      SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_48);
      return iVar1;
    }
    local_3c = 0;
    lVar2 = (**(code **)(*(longlong *)this + 0x38))(this,param_1,local_40,&local_3c);
    if (local_3c == 0) {
      return lVar2;
    }
    (**(code **)(*(longlong *)param_1 + 0x18))(param_1);
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x28))(param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
    lVar2 = (**(code **)(*(longlong *)param_1 + 0x20))(param_1);
  }
  return lVar2;
}



===== Invoke_AddDevice @ 14000d8f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CStubITsUsbDeviceSink<struct ITsUsbDeviceSink>::Invoke_AddDevice(struct
   IMessage * __ptr64) __ptr64 */

long __thiscall
CStubITsUsbDeviceSink<ITsUsbDeviceSink>::Invoke_AddDevice
          (CStubITsUsbDeviceSink<ITsUsbDeviceSink> *this,IMessage *param_1)

{
  int iVar1;
  _USB_DEVICE_CAPABILITIES *p_Var2;
  ulong uVar3;
  void *pvVar4;
  void *pvVar5;
  void *pvVar6;
  void *pvVar7;
  ulong local_res10 [2];
  ulong local_res18 [2];
  ulong local_res20 [2];
  ulong local_78 [2];
  void *local_70;
  void *local_68;
  void *local_60;
  void *local_58;
  longlong *local_50 [2];
  
  p_Var2 = (_USB_DEVICE_CAPABILITIES *)0x0;
  local_50[0] = (longlong *)0x0;
  local_78[0] = 0;
  pvVar7 = (void *)0x0;
  local_58 = (void *)0x0;
  pvVar4 = (void *)0x0;
  local_res20[0] = 0;
  pvVar5 = (void *)0x0;
  local_60 = (void *)0x0;
  local_res18[0] = 0;
  pvVar6 = (void *)0x0;
  local_68 = (void *)0x0;
  local_res10[0] = 0;
  local_70 = (void *)0x0;
  iVar1 = (**(code **)(*(longlong *)param_1 + 0x180))
                    (param_1,local_50,&_GUID_46c9f566_3412_42e9_a43e_4d9926956afe,1);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_78,1);
    if (-1 < iVar1) {
      iVar1 = RIM_USER_ALLOC_C(&local_58,2,local_78[0]);
      pvVar7 = local_58;
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*(longlong *)param_1 + 0x138))(param_1,local_58,local_78[0]);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res20,1);
          if (-1 < iVar1) {
            iVar1 = RIM_USER_ALLOC_C(&local_60,2,local_res20[0]);
            pvVar4 = local_60;
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*(longlong *)param_1 + 0x138))(param_1,local_60,local_res20[0]);
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res18,1);
                if (-1 < iVar1) {
                  iVar1 = RIM_USER_ALLOC_C(&local_68,2,local_res18[0]);
                  pvVar5 = local_68;
                  if (-1 < iVar1) {
                    iVar1 = (**(code **)(*(longlong *)param_1 + 0x138))
                                      (param_1,local_68,local_res18[0]);
                    if (-1 < iVar1) {
                      iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res10,1);
                      if (-1 < iVar1) {
                        iVar1 = RIM_USER_ALLOC_C(&local_70,2,local_res10[0]);
                        pvVar6 = local_70;
                        if (-1 < iVar1) {
                          iVar1 = (**(code **)(*(longlong *)param_1 + 0x138))
                                            (param_1,local_70,local_res10[0]);
                          if (-1 < iVar1) {
                            uVar3 = 0x72447244;
                            p_Var2 = (_USB_DEVICE_CAPABILITIES *)ExAllocatePoolWithTag(0x200,0x1c);
                            if (p_Var2 == (_USB_DEVICE_CAPABILITIES *)0x0) {
                              iVar1 = -0x7ff8fff2;
                            }
                            else {
                              *(undefined8 *)p_Var2 = 0;
                              *(undefined8 *)(p_Var2 + 8) = 0;
                              *(undefined8 *)(p_Var2 + 0x10) = 0;
                              *(undefined4 *)(p_Var2 + 0x18) = 0;
                              iVar1 = CProxyReceive_USB_DEVICE_CAPABILITIES(param_1,p_Var2,uVar3);
                              if (-1 < iVar1) {
                                (**(code **)(**(longlong **)(this + 0x18) + 0x20))
                                          (*(longlong **)(this + 0x18),local_50[0],local_78[0],
                                           pvVar7,local_res20[0],pvVar4,local_res18[0],pvVar5,
                                           local_res10[0],pvVar6,p_Var2);
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (local_50[0] != (longlong *)0x0) {
    (**(code **)(*local_50[0] + 0x10))();
  }
  RIM_USER_FREE(pvVar7);
  RIM_USER_FREE(pvVar4);
  RIM_USER_FREE(pvVar5);
  RIM_USER_FREE(pvVar6);
  RIM_USER_FREE(p_Var2);
  return iVar1;
}



===== Invoke_ExchangeCapabilities @ 14000dbf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CStubIRIMCapabilitiesNegotiator<struct
   IRIMCapabilitiesNegotiator>::Invoke_ExchangeCapabilities(struct IMessage * __ptr64) __ptr64 */

long __thiscall
CStubIRIMCapabilitiesNegotiator<IRIMCapabilitiesNegotiator>::Invoke_ExchangeCapabilities
          (CStubIRIMCapabilitiesNegotiator<IRIMCapabilitiesNegotiator> *this,IMessage *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_res10 [2];
  undefined4 local_res18 [4];
  
  local_res10[0] = 0;
  local_res18[0] = 0;
  iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res10,1);
  if (-1 < iVar1) {
    uVar2 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                      (*(longlong **)(this + 0x18),local_res10[0],local_res18);
    (**(code **)(*(longlong *)param_1 + 0x18))(param_1);
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x98))(param_1,local_res18,1);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*(longlong *)param_1 + 0x38))(param_1,uVar2);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*(longlong *)param_1 + 0x20))(param_1);
      }
    }
  }
  return iVar1;
}



===== Invoke_IoControlCompleteRequest @ 14000dcac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CStubITsRequestCompletion<struct
   ITsRequestCompletion>::Invoke_IoControlCompleteRequest(struct IMessage * __ptr64) __ptr64 */

long __thiscall
CStubITsRequestCompletion<ITsRequestCompletion>::Invoke_IoControlCompleteRequest
          (CStubITsRequestCompletion<ITsRequestCompletion> *this,IMessage *param_1)

{
  int iVar1;
  void *pvVar2;
  ulong local_res10 [2];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 local_38 [2];
  void *local_30;
  
  pvVar2 = (void *)0x0;
  local_38[0] = 0;
  local_res20[0] = 0;
  local_res18[0] = 0;
  local_res10[0] = 0;
  local_30 = (void *)0x0;
  iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_38,1);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x120))(param_1,local_res20,1);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res18,1);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res10,1);
        if (-1 < iVar1) {
          iVar1 = RIM_USER_ALLOC_C(&local_30,1,local_res10[0]);
          pvVar2 = local_30;
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*(longlong *)param_1 + 0x108))(param_1,local_30,local_res10[0]);
            if (-1 < iVar1) {
              (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                        (*(longlong **)(this + 0x18),local_38[0],local_res20[0],local_res18[0],
                         pvVar2,local_res10[0]);
            }
          }
        }
      }
    }
  }
  RIM_USER_FREE(pvVar2);
  return iVar1;
}



===== Invoke_PnpQueryDeviceTextDescription @ 14000dde8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CStubITsUsbDevice<struct
   ITsUsbDevice>::Invoke_PnpQueryDeviceTextDescription(struct IMessage * __ptr64) __ptr64 */

long __thiscall
CStubITsUsbDevice<ITsUsbDevice>::Invoke_PnpQueryDeviceTextDescription
          (CStubITsUsbDevice<ITsUsbDevice> *this,IMessage *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  void *local_28 [2];
  
  local_res20[0] = 0;
  local_res18[0] = 0;
  local_28[0] = (void *)0x0;
  local_res10[0] = 0;
  iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res20,1);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res18,1);
    if (-1 < iVar1) {
      uVar2 = (**(code **)(**(longlong **)(this + 0x18) + 0x38))
                        (*(longlong **)(this + 0x18),local_res20[0],local_res18[0],local_28,
                         local_res10);
      (**(code **)(*(longlong *)param_1 + 0x18))(param_1);
      iVar1 = (**(code **)(*(longlong *)param_1 + 0x98))(param_1,local_res10,1);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*(longlong *)param_1 + 0x88))(param_1,local_28[0],local_res10[0]);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*(longlong *)param_1 + 0x38))(param_1,uVar2);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*(longlong *)param_1 + 0x20))(param_1);
          }
        }
      }
    }
  }
  RIM_USER_FREE(local_28[0]);
  return iVar1;
}



===== Invoke_UrbCompletion @ 14000df18 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CStubITsRequestCompletion<struct
   ITsRequestCompletion>::Invoke_UrbCompletion(struct IMessage * __ptr64) __ptr64 */

long __thiscall
CStubITsRequestCompletion<ITsRequestCompletion>::Invoke_UrbCompletion
          (CStubITsRequestCompletion<ITsRequestCompletion> *this,IMessage *param_1)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  ulong local_res10 [2];
  ulong local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 local_58 [2];
  void *local_50;
  void *local_48 [2];
  
  pvVar3 = (void *)0x0;
  local_58[0] = 0;
  local_res18[0] = 0;
  local_res20[0] = 0;
  pvVar2 = (void *)0x0;
  local_48[0] = (void *)0x0;
  local_res10[0] = 0;
  local_50 = (void *)0x0;
  iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_58,1);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res18,1);
    if (-1 < iVar1) {
      iVar1 = RIM_USER_ALLOC_C(local_48,1,local_res18[0]);
      pvVar3 = local_48[0];
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*(longlong *)param_1 + 0x108))(param_1,local_48[0],local_res18[0]);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*(longlong *)param_1 + 0x120))(param_1,local_res20,1);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res10,1);
            if (-1 < iVar1) {
              iVar1 = RIM_USER_ALLOC_C(&local_50,1,local_res10[0]);
              pvVar2 = local_50;
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*(longlong *)param_1 + 0x108))(param_1,local_50,local_res10[0])
                ;
                if (-1 < iVar1) {
                  (**(code **)(**(longlong **)(this + 0x18) + 0x20))
                            (*(longlong **)(this + 0x18),local_58[0],pvVar3,local_res18[0],
                             local_res20[0],pvVar2,local_res10[0]);
                }
              }
            }
          }
        }
      }
    }
  }
  RIM_USER_FREE(pvVar3);
  RIM_USER_FREE(pvVar2);
  return iVar1;
}



===== Invoke_UrbCompletionNoData @ 14000e0a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CStubITsRequestCompletion<struct
   ITsRequestCompletion>::Invoke_UrbCompletionNoData(struct IMessage * __ptr64) __ptr64 */

long __thiscall
CStubITsRequestCompletion<ITsRequestCompletion>::Invoke_UrbCompletionNoData
          (CStubITsRequestCompletion<ITsRequestCompletion> *this,IMessage *param_1)

{
  int iVar1;
  void *pvVar2;
  ulong local_res10 [2];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 local_38 [2];
  void *local_30;
  
  pvVar2 = (void *)0x0;
  local_38[0] = 0;
  local_res10[0] = 0;
  local_res20[0] = 0;
  local_res18[0] = 0;
  local_30 = (void *)0x0;
  iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_38,1);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res10,1);
    if (-1 < iVar1) {
      iVar1 = RIM_USER_ALLOC_C(&local_30,1,local_res10[0]);
      pvVar2 = local_30;
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*(longlong *)param_1 + 0x108))(param_1,local_30,local_res10[0]);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*(longlong *)param_1 + 0x120))(param_1,local_res20,1);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res18,1);
            if (-1 < iVar1) {
              (**(code **)(**(longlong **)(this + 0x18) + 0x28))
                        (*(longlong **)(this + 0x18),local_38[0],pvVar2,local_res10[0],
                         local_res20[0],local_res18[0]);
            }
          }
        }
      }
    }
  }
  RIM_USER_FREE(pvVar2);
  return iVar1;
}



===== Invoke_UrbTransferInRequest @ 14000e1e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CStubITsUsbDevice<struct ITsUsbDevice>::Invoke_UrbTransferInRequest(struct
   IMessage * __ptr64) __ptr64 */

long __thiscall
CStubITsUsbDevice<ITsUsbDevice>::Invoke_UrbTransferInRequest
          (CStubITsUsbDevice<ITsUsbDevice> *this,IMessage *param_1)

{
  int iVar1;
  void *pvVar2;
  ulong local_res10 [2];
  undefined4 local_res18 [2];
  void *local_res20;
  
  pvVar2 = (void *)0x0;
  local_res10[0] = 0;
  local_res18[0] = 0;
  local_res20 = (void *)0x0;
  iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res10,1);
  if (-1 < iVar1) {
    iVar1 = RIM_USER_ALLOC_C(&local_res20,1,local_res10[0]);
    pvVar2 = local_res20;
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*(longlong *)param_1 + 0x108))(param_1,local_res20,local_res10[0]);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res18,1);
        if (-1 < iVar1) {
          (**(code **)(**(longlong **)(this + 0x18) + 0x40))
                    (*(longlong **)(this + 0x18),pvVar2,local_res10[0],local_res18[0]);
        }
      }
    }
  }
  RIM_USER_FREE(pvVar2);
  return iVar1;
}



===== Invoke_UrbTransferOutRequest @ 14000e2bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CStubITsUsbDevice<struct ITsUsbDevice>::Invoke_UrbTransferOutRequest(struct
   IMessage * __ptr64) __ptr64 */

long __thiscall
CStubITsUsbDevice<ITsUsbDevice>::Invoke_UrbTransferOutRequest
          (CStubITsUsbDevice<ITsUsbDevice> *this,IMessage *param_1)

{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  ulong local_res10 [2];
  ulong local_res18 [2];
  void *local_res20;
  void *local_38 [2];
  
  pvVar2 = (void *)0x0;
  local_res18[0] = 0;
  local_res10[0] = 0;
  local_38[0] = (void *)0x0;
  pvVar3 = (void *)0x0;
  local_res20 = (void *)0x0;
  iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res18,1);
  if (-1 < iVar1) {
    iVar1 = RIM_USER_ALLOC_C(local_38,1,local_res18[0]);
    pvVar2 = local_38[0];
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*(longlong *)param_1 + 0x108))(param_1,local_38[0],local_res18[0]);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res10,1);
        if (-1 < iVar1) {
          iVar1 = RIM_USER_ALLOC_C(&local_res20,1,local_res10[0]);
          pvVar3 = local_res20;
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*(longlong *)param_1 + 0x108))(param_1,local_res20,local_res10[0]);
            if (-1 < iVar1) {
              (**(code **)(**(longlong **)(this + 0x18) + 0x48))
                        (*(longlong **)(this + 0x18),pvVar2,local_res18[0],pvVar3,local_res10[0]);
            }
          }
        }
      }
    }
  }
  RIM_USER_FREE(pvVar2);
  RIM_USER_FREE(pvVar3);
  return iVar1;
}



===== Invoke_UsbInternalIoControl @ 14000e3ec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CStubITsUsbDevice<struct ITsUsbDevice>::Invoke_UsbInternalIoControl(struct
   IMessage * __ptr64) __ptr64 */

long __thiscall
CStubITsUsbDevice<ITsUsbDevice>::Invoke_UsbInternalIoControl
          (CStubITsUsbDevice<ITsUsbDevice> *this,IMessage *param_1)

{
  int iVar1;
  void *pvVar2;
  ulong local_res10 [2];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 local_38 [2];
  void *local_30;
  
  pvVar2 = (void *)0x0;
  local_38[0] = 0;
  local_res10[0] = 0;
  local_res20[0] = 0;
  local_res18[0] = 0;
  local_30 = (void *)0x0;
  iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_38,1);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res10,1);
    if (-1 < iVar1) {
      iVar1 = RIM_USER_ALLOC_C(&local_30,1,local_res10[0]);
      pvVar2 = local_30;
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*(longlong *)param_1 + 0x108))(param_1,local_30,local_res10[0]);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res20,1);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res18,1);
            if (-1 < iVar1) {
              (**(code **)(**(longlong **)(this + 0x18) + 0x30))
                        (*(longlong **)(this + 0x18),local_38[0],pvVar2,local_res10[0],
                         local_res20[0],local_res18[0]);
            }
          }
        }
      }
    }
  }
  RIM_USER_FREE(pvVar2);
  return iVar1;
}



===== Invoke_UsbIoControl @ 14000e52c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CStubITsUsbDevice<struct ITsUsbDevice>::Invoke_UsbIoControl(struct IMessage
   * __ptr64) __ptr64 */

long __thiscall
CStubITsUsbDevice<ITsUsbDevice>::Invoke_UsbIoControl
          (CStubITsUsbDevice<ITsUsbDevice> *this,IMessage *param_1)

{
  int iVar1;
  void *pvVar2;
  ulong local_res10 [2];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 local_38 [2];
  void *local_30;
  
  pvVar2 = (void *)0x0;
  local_38[0] = 0;
  local_res10[0] = 0;
  local_res20[0] = 0;
  local_res18[0] = 0;
  local_30 = (void *)0x0;
  iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_38,1);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res10,1);
    if (-1 < iVar1) {
      iVar1 = RIM_USER_ALLOC_C(&local_30,1,local_res10[0]);
      pvVar2 = local_30;
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*(longlong *)param_1 + 0x108))(param_1,local_30,local_res10[0]);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res20,1);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*(longlong *)param_1 + 0x148))(param_1,local_res18,1);
            if (-1 < iVar1) {
              (**(code **)(**(longlong **)(this + 0x18) + 0x28))
                        (*(longlong **)(this + 0x18),local_38[0],pvVar2,local_res10[0],
                         local_res20[0],local_res18[0]);
            }
          }
        }
      }
    }
  }
  RIM_USER_FREE(pvVar2);
  return iVar1;
}



===== IoControlCompleteRequest @ 14000e670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyITsRequestCompletion<struct
   ITsRequestCompletion>::IoControlCompleteRequest(unsigned long,long,unsigned long,char *
   __ptr64,unsigned long) __ptr64 */

long __thiscall
CProxyITsRequestCompletion<ITsRequestCompletion>::IoControlCompleteRequest
          (CProxyITsRequestCompletion<ITsRequestCompletion> *this,ulong param_1,long param_2,
          ulong param_3,char *param_4,ulong param_5)

{
  int iVar1;
  longlong *local_res8;
  ulong local_res10 [2];
  long local_res18 [2];
  ulong local_res20 [2];
  
  local_res8 = (longlong *)0x0;
  local_res10[0] = param_1;
  local_res18[0] = param_2;
  local_res20[0] = param_3;
  iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                    (*(longlong **)(this + 0x18),&local_res8);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res8 + 0x40))(local_res8,0x100);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,local_res10,1);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_res8 + 0x70))(local_res8,local_res18,1);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,local_res20,1);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,&param_5,1);
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*local_res8 + 0x58))(local_res8,param_4,param_5);
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*local_res8 + 0x20))();
              }
            }
          }
        }
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res8);
  return iVar1;
}



===== OnChannelClose @ 14000e7a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CStub<struct IUnknown>::OnChannelClose(void) __ptr64 */

long __thiscall CStub<IUnknown>::OnChannelClose(CStub<IUnknown> *this)

{
  undefined8 *puVar1;
  int iVar2;
  longlong *local_res8 [4];
  
  puVar1 = *(undefined8 **)(this + 0x18);
  iVar2 = 0;
  if (puVar1 != (undefined8 *)0x0) {
    local_res8[0] = (longlong *)0x0;
    iVar2 = (**(code **)*puVar1)(puVar1,&IID_IRIMChannelCallback,local_res8);
    if (-1 < iVar2) {
      iVar2 = (**(code **)(*local_res8[0] + 0x18))();
    }
    SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)local_res8);
  }
  return iVar2;
}



===== PnpQueryDeviceTextDescription @ 14000e800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyITsUsbDevice<struct
   ITsUsbDevice>::PnpQueryDeviceTextDescription(unsigned long,unsigned long,unsigned short * __ptr64
   * __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
CProxyITsUsbDevice<ITsUsbDevice>::PnpQueryDeviceTextDescription
          (CProxyITsUsbDevice<ITsUsbDevice> *this,ulong param_1,ulong param_2,ushort **param_3,
          ulong *param_4)

{
  int iVar1;
  int local_res8 [2];
  ulong local_res10 [2];
  ulong local_res18 [2];
  longlong *local_28 [2];
  
  local_28[0] = (longlong *)0x0;
  local_res8[0] = -0x7fffbfff;
  local_res10[0] = param_1;
  local_res18[0] = param_2;
  iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))(*(longlong **)(this + 0x18),local_28);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_28[0] + 0x40))(local_28[0],0x104);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_28[0] + 0x98))(local_28[0],local_res10,1);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_28[0] + 0x98))(local_28[0],local_res18,1);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_28[0] + 0x20))();
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_28[0] + 0xd8))();
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*local_28[0] + 0x148))(local_28[0],param_4,1);
              if (-1 < iVar1) {
                iVar1 = RIM_USER_ALLOC_C(param_3,2,*param_4);
                if (-1 < iVar1) {
                  iVar1 = (**(code **)(*local_28[0] + 0x138))(local_28[0],*param_3,*param_4);
                  if (-1 < iVar1) {
                    iVar1 = (**(code **)(*local_28[0] + 0xe8))(local_28[0],local_res8);
                    if (-1 < iVar1) {
                      iVar1 = local_res8[0];
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)local_28);
  return iVar1;
}



===== QueryInterface @ 14000e980 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CImplIUnknown<struct
   IRIMCapabilitiesNegotiator>::QueryInterface(struct _GUID const & __ptr64,void * __ptr64 *
   __ptr64) __ptr64 */

long __thiscall
CImplIUnknown<IRIMCapabilitiesNegotiator>::QueryInterface
          (CImplIUnknown<IRIMCapabilitiesNegotiator> *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  lVar1 = -*(longlong *)param_1;
  if (lVar1 == 0) {
    lVar1 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar1 != 0) {
    lVar1 = 0x4ce0e9c117accf68 - *(longlong *)param_1;
    if (lVar1 == 0) {
      lVar1 = 0xfb346c80db91cfa6 - *(longlong *)(param_1 + 8);
    }
    if (lVar1 != 0) {
      return -0x7fffbffe;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== QueryInterface @ 14000e9f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CImplIUnknown<struct IRIMStub>::QueryInterface(struct _GUID const &
   __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CImplIUnknown<IRIMStub>::QueryInterface(CImplIUnknown<IRIMStub> *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  lVar1 = -*(longlong *)param_1;
  if (lVar1 == 0) {
    lVar1 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar1 != 0) {
    lVar1 = 0x4580870aac311787 - *(longlong *)param_1;
    if (lVar1 == 0) {
      lVar1 = 0xf76db6b758ea07bb - *(longlong *)(param_1 + 8);
    }
    if (lVar1 != 0) {
      return -0x7fffbffe;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== QueryInterface @ 14000ea60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CImplIUnknown<struct ITsChannelNotification>::QueryInterface(struct
   _GUID const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CImplIUnknown<ITsChannelNotification>::QueryInterface
          (CImplIUnknown<ITsChannelNotification> *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  lVar1 = -*(longlong *)param_1;
  if (lVar1 == 0) {
    lVar1 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar1 != 0) {
    lVar1 = 0x46bb20efeb9d428c - *(longlong *)param_1;
    if (lVar1 == 0) {
      lVar1 = 0xf065bf1c22b6b7b2 - *(longlong *)(param_1 + 8);
    }
    if (lVar1 != 0) {
      return -0x7fffbffe;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== QueryInterface @ 14000ead0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CImplIUnknown<struct ITsRequestCompletion>::QueryInterface(struct
   _GUID const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CImplIUnknown<ITsRequestCompletion>::QueryInterface
          (CImplIUnknown<ITsRequestCompletion> *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  lVar1 = -*(longlong *)param_1;
  if (lVar1 == 0) {
    lVar1 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar1 != 0) {
    lVar1 = 0x469129aa0493a1ca - *(longlong *)param_1;
    if (lVar1 == 0) {
      lVar1 = 0x12fa1cf6fb0ac889 - *(longlong *)(param_1 + 8);
    }
    if (lVar1 != 0) {
      return -0x7fffbffe;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== QueryInterface @ 14000eb40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CImplIUnknown<struct ITsUsbDevice>::QueryInterface(struct _GUID
   const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CImplIUnknown<ITsUsbDevice>::QueryInterface
          (CImplIUnknown<ITsUsbDevice> *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  lVar1 = -*(longlong *)param_1;
  if (lVar1 == 0) {
    lVar1 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar1 != 0) {
    lVar1 = 0x42e9341246c9f566 - *(longlong *)param_1;
    if (lVar1 == 0) {
      lVar1 = 0xfe6a9526994d3ea4 - *(longlong *)(param_1 + 8);
    }
    if (lVar1 != 0) {
      return -0x7fffbffe;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== QueryInterface @ 14000ebb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CImplIUnknown<struct ITsUsbDeviceSink>::QueryInterface(struct _GUID
   const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CImplIUnknown<ITsUsbDeviceSink>::QueryInterface
          (CImplIUnknown<ITsUsbDeviceSink> *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  lVar1 = -*(longlong *)param_1;
  if (lVar1 == 0) {
    lVar1 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar1 != 0) {
    lVar1 = 0x45c343f5cec617f6 - *(longlong *)param_1;
    if (lVar1 == 0) {
      lVar1 = 0xd47c11ea06131e97 - *(longlong *)(param_1 + 8);
    }
    if (lVar1 != 0) {
      return -0x7fffbffe;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== QueryInterface @ 14000ec20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyIUnknown<struct
   IRIMCapabilitiesNegotiator>::QueryInterface(struct _GUID const & __ptr64,void * __ptr64 *
   __ptr64) __ptr64 */

long __thiscall
CProxyIUnknown<IRIMCapabilitiesNegotiator>::QueryInterface
          (CProxyIUnknown<IRIMCapabilitiesNegotiator> *this,_GUID *param_1,void **param_2)

{
  int iVar1;
  longlong lVar2;
  int local_res20 [2];
  longlong *local_18 [2];
  
  local_18[0] = (longlong *)0x0;
  lVar2 = -*(longlong *)param_1;
  if (lVar2 == 0) {
    lVar2 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar2 != 0) {
    lVar2 = 0x4ce0e9c117accf68 - *(longlong *)param_1;
    if (lVar2 == 0) {
      lVar2 = 0xfb346c80db91cfa6 - *(longlong *)(param_1 + 8);
    }
    if (lVar2 != 0) {
      iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                        (*(longlong **)(this + 0x18),local_18);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_18[0] + 0x40))(local_18[0],2);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_18[0] + 0x48))(local_18[0],param_1);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_18[0] + 0x20))();
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*local_18[0] + 0xd8))();
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*local_18[0] + 0x180))(local_18[0],param_2,param_1,1);
                if (-1 < iVar1) {
                  local_res20[0] = 0;
                  iVar1 = (**(code **)(*local_18[0] + 0xe8))(local_18[0],local_res20);
                  if (-1 < iVar1) {
                    iVar1 = local_res20[0];
                  }
                }
              }
            }
          }
        }
      }
      goto LAB_14000ed70;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  iVar1 = 0;
LAB_14000ed70:
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)local_18);
  return iVar1;
}



===== QueryInterface @ 14000eda0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyIUnknown<struct ITsChannelNotification>::QueryInterface(struct
   _GUID const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CProxyIUnknown<ITsChannelNotification>::QueryInterface
          (CProxyIUnknown<ITsChannelNotification> *this,_GUID *param_1,void **param_2)

{
  int iVar1;
  longlong lVar2;
  int local_res20 [2];
  longlong *local_18 [2];
  
  local_18[0] = (longlong *)0x0;
  lVar2 = -*(longlong *)param_1;
  if (lVar2 == 0) {
    lVar2 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar2 != 0) {
    lVar2 = 0x46bb20efeb9d428c - *(longlong *)param_1;
    if (lVar2 == 0) {
      lVar2 = 0xf065bf1c22b6b7b2 - *(longlong *)(param_1 + 8);
    }
    if (lVar2 != 0) {
      iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                        (*(longlong **)(this + 0x18),local_18);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_18[0] + 0x40))(local_18[0],2);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_18[0] + 0x48))(local_18[0],param_1);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_18[0] + 0x20))();
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*local_18[0] + 0xd8))();
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*local_18[0] + 0x180))(local_18[0],param_2,param_1,1);
                if (-1 < iVar1) {
                  local_res20[0] = 0;
                  iVar1 = (**(code **)(*local_18[0] + 0xe8))(local_18[0],local_res20);
                  if (-1 < iVar1) {
                    iVar1 = local_res20[0];
                  }
                }
              }
            }
          }
        }
      }
      goto LAB_14000eef0;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  iVar1 = 0;
LAB_14000eef0:
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)local_18);
  return iVar1;
}



===== QueryInterface @ 14000ef20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyIUnknown<struct ITsRequestCompletion>::QueryInterface(struct
   _GUID const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CProxyIUnknown<ITsRequestCompletion>::QueryInterface
          (CProxyIUnknown<ITsRequestCompletion> *this,_GUID *param_1,void **param_2)

{
  int iVar1;
  longlong lVar2;
  int local_res20 [2];
  longlong *local_18 [2];
  
  local_18[0] = (longlong *)0x0;
  lVar2 = -*(longlong *)param_1;
  if (lVar2 == 0) {
    lVar2 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar2 != 0) {
    lVar2 = 0x469129aa0493a1ca - *(longlong *)param_1;
    if (lVar2 == 0) {
      lVar2 = 0x12fa1cf6fb0ac889 - *(longlong *)(param_1 + 8);
    }
    if (lVar2 != 0) {
      iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                        (*(longlong **)(this + 0x18),local_18);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_18[0] + 0x40))(local_18[0],2);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_18[0] + 0x48))(local_18[0],param_1);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_18[0] + 0x20))();
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*local_18[0] + 0xd8))();
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*local_18[0] + 0x180))(local_18[0],param_2,param_1,1);
                if (-1 < iVar1) {
                  local_res20[0] = 0;
                  iVar1 = (**(code **)(*local_18[0] + 0xe8))(local_18[0],local_res20);
                  if (-1 < iVar1) {
                    iVar1 = local_res20[0];
                  }
                }
              }
            }
          }
        }
      }
      goto LAB_14000f070;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  iVar1 = 0;
LAB_14000f070:
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)local_18);
  return iVar1;
}



===== QueryInterface @ 14000f0a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyIUnknown<struct ITsUsbDevice>::QueryInterface(struct _GUID
   const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CProxyIUnknown<ITsUsbDevice>::QueryInterface
          (CProxyIUnknown<ITsUsbDevice> *this,_GUID *param_1,void **param_2)

{
  int iVar1;
  longlong lVar2;
  int local_res20 [2];
  longlong *local_18 [2];
  
  local_18[0] = (longlong *)0x0;
  lVar2 = -*(longlong *)param_1;
  if (lVar2 == 0) {
    lVar2 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar2 != 0) {
    lVar2 = 0x42e9341246c9f566 - *(longlong *)param_1;
    if (lVar2 == 0) {
      lVar2 = 0xfe6a9526994d3ea4 - *(longlong *)(param_1 + 8);
    }
    if (lVar2 != 0) {
      iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                        (*(longlong **)(this + 0x18),local_18);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_18[0] + 0x40))(local_18[0],2);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_18[0] + 0x48))(local_18[0],param_1);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_18[0] + 0x20))();
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*local_18[0] + 0xd8))();
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*local_18[0] + 0x180))(local_18[0],param_2,param_1,1);
                if (-1 < iVar1) {
                  local_res20[0] = 0;
                  iVar1 = (**(code **)(*local_18[0] + 0xe8))(local_18[0],local_res20);
                  if (-1 < iVar1) {
                    iVar1 = local_res20[0];
                  }
                }
              }
            }
          }
        }
      }
      goto LAB_14000f1f0;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  iVar1 = 0;
LAB_14000f1f0:
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)local_18);
  return iVar1;
}



===== QueryInterface @ 14000f220 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyIUnknown<struct ITsUsbDeviceSink>::QueryInterface(struct _GUID
   const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CProxyIUnknown<ITsUsbDeviceSink>::QueryInterface
          (CProxyIUnknown<ITsUsbDeviceSink> *this,_GUID *param_1,void **param_2)

{
  int iVar1;
  longlong lVar2;
  int local_res20 [2];
  longlong *local_18 [2];
  
  local_18[0] = (longlong *)0x0;
  lVar2 = -*(longlong *)param_1;
  if (lVar2 == 0) {
    lVar2 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar2 != 0) {
    lVar2 = 0x45c343f5cec617f6 - *(longlong *)param_1;
    if (lVar2 == 0) {
      lVar2 = 0xd47c11ea06131e97 - *(longlong *)(param_1 + 8);
    }
    if (lVar2 != 0) {
      iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                        (*(longlong **)(this + 0x18),local_18);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_18[0] + 0x40))(local_18[0],2);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_18[0] + 0x48))(local_18[0],param_1);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_18[0] + 0x20))();
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*local_18[0] + 0xd8))();
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*local_18[0] + 0x180))(local_18[0],param_2,param_1,1);
                if (-1 < iVar1) {
                  local_res20[0] = 0;
                  iVar1 = (**(code **)(*local_18[0] + 0xe8))(local_18[0],local_res20);
                  if (-1 < iVar1) {
                    iVar1 = local_res20[0];
                  }
                }
              }
            }
          }
        }
      }
      goto LAB_14000f370;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  iVar1 = 0;
LAB_14000f370:
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)local_18);
  return iVar1;
}



===== RIM_USER_ALLOC_C @ 14000f398 =====

/* long __cdecl RIM_USER_ALLOC_C(void * __ptr64 * __ptr64,unsigned long,unsigned long) */

long __cdecl RIM_USER_ALLOC_C(void **param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  
  if ((ulonglong)param_2 * (ulonglong)param_3 < 0x100000000) {
    lVar1 = RIM_USER_ALLOC(param_1,(ulong)((ulonglong)param_2 * (ulonglong)param_3));
  }
  else {
    lVar1 = -0x7ff8fdea;
  }
  return lVar1;
}



===== RegisterRequestCallback @ 14000f3d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyITsUsbDevice<struct
   ITsUsbDevice>::RegisterRequestCallback(struct ITsRequestCompletion * __ptr64) __ptr64 */

long __thiscall
CProxyITsUsbDevice<ITsUsbDevice>::RegisterRequestCallback
          (CProxyITsUsbDevice<ITsUsbDevice> *this,ITsRequestCompletion *param_1)

{
  int iVar1;
  longlong *local_res8;
  ITsRequestCompletion *local_res10 [3];
  
  local_res8 = (longlong *)0x0;
  local_res10[0] = param_1;
  iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                    (*(longlong **)(this + 0x18),&local_res8);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res8 + 0x40))(local_res8,0x101);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res8 + 0xd0))
                        (local_res8,local_res10,&_GUID_0493a1ca_29aa_4691_89c8_0afbf61cfa12,1);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_res8 + 0x20))();
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res8);
  return iVar1;
}



===== Release @ 14000f470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual unsigned long __cdecl CImplIUnknown<struct IWTSWriteCallback>::Release(void)
   __ptr64 */

ulong __thiscall CImplIUnknown<IWTSWriteCallback>::Release(CImplIUnknown<IWTSWriteCallback> *this)

{
  CImplIUnknown<IWTSWriteCallback> *pCVar1;
  int iVar2;
  ulong uVar3;
  
  LOCK();
  pCVar1 = this + 0xc;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  uVar3 = iVar2 - 1;
  if ((uVar3 == 0) && (this != (CImplIUnknown<IWTSWriteCallback> *)0x0)) {
    (**(code **)(*(longlong *)this + 0x20))(this,iVar2);
  }
  return uVar3;
}



===== Release @ 14000f4b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual unsigned long __cdecl CImplIUnknown<struct ITsRequestCompletion>::Release(void)
   __ptr64 */

ulong __thiscall
CImplIUnknown<ITsRequestCompletion>::Release(CImplIUnknown<ITsRequestCompletion> *this)

{
  CImplIUnknown<ITsRequestCompletion> *pCVar1;
  int iVar2;
  ulong uVar3;
  
  LOCK();
  pCVar1 = this + 0xc;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  uVar3 = iVar2 - 1;
  if ((uVar3 == 0) && (this != (CImplIUnknown<ITsRequestCompletion> *)0x0)) {
    (**(code **)(*(longlong *)this + 0x30))(this,iVar2);
  }
  return uVar3;
}



===== Release @ 14000f4f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual unsigned long __cdecl CImplIUnknown<struct ITsUsbDevice>::Release(void) __ptr64
    */

ulong __thiscall CImplIUnknown<ITsUsbDevice>::Release(CImplIUnknown<ITsUsbDevice> *this)

{
  CImplIUnknown<ITsUsbDevice> *pCVar1;
  int iVar2;
  ulong uVar3;
  
  LOCK();
  pCVar1 = this + 0xc;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  uVar3 = iVar2 - 1;
  if ((uVar3 == 0) && (this != (CImplIUnknown<ITsUsbDevice> *)0x0)) {
    (**(code **)(*(longlong *)this + 0x58))(this,iVar2);
  }
  return uVar3;
}



===== Release @ 14000f530 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual unsigned long __cdecl CImplIUnknown<struct
   IWTSVirtualChannelCallback>::Release(void) __ptr64 */

ulong __thiscall
CImplIUnknown<IWTSVirtualChannelCallback>::Release(CImplIUnknown<IWTSVirtualChannelCallback> *this)

{
  CImplIUnknown<IWTSVirtualChannelCallback> *pCVar1;
  int iVar2;
  ulong uVar3;
  
  LOCK();
  pCVar1 = this + 0xc;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  uVar3 = iVar2 - 1;
  if ((uVar3 == 0) && (this != (CImplIUnknown<IWTSVirtualChannelCallback> *)0x0)) {
    (**(code **)(*(longlong *)this + 0x28))(this,iVar2);
  }
  return uVar3;
}



===== RetractDevice @ 14000f570 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyITsUsbDevice<struct ITsUsbDevice>::RetractDevice(unsigned
   long) __ptr64 */

long __thiscall
CProxyITsUsbDevice<ITsUsbDevice>::RetractDevice
          (CProxyITsUsbDevice<ITsUsbDevice> *this,ulong param_1)

{
  int iVar1;
  longlong *local_res8;
  ulong local_res10 [6];
  
  local_res8 = (longlong *)0x0;
  local_res10[0] = param_1;
  iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                    (*(longlong **)(this + 0x18),&local_res8);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res8 + 0x40))(local_res8,0x107);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,local_res10,1);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_res8 + 0x20))();
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res8);
  return iVar1;
}



===== SetNetworkId @ 14000f610 =====

/* public: virtual long __cdecl CStub<struct ITsChannelNotification>::SetNetworkId(unsigned long)
   __ptr64 */

long __thiscall
CStub<ITsChannelNotification>::SetNetworkId(CStub<ITsChannelNotification> *this,ulong param_1)

{
  *(ulong *)(this + 0x20) = param_1;
  return 0;
}



===== UrbCompletion @ 14000f620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyITsRequestCompletion<struct
   ITsRequestCompletion>::UrbCompletion(unsigned long,char * __ptr64,unsigned long,long,char *
   __ptr64,unsigned long) __ptr64 */

long __thiscall
CProxyITsRequestCompletion<ITsRequestCompletion>::UrbCompletion
          (CProxyITsRequestCompletion<ITsRequestCompletion> *this,ulong param_1,char *param_2,
          ulong param_3,long param_4,char *param_5,ulong param_6)

{
  int iVar1;
  longlong *local_res8;
  ulong local_res10 [4];
  ulong local_res20 [2];
  
  local_res8 = (longlong *)0x0;
  local_res10[0] = param_1;
  local_res20[0] = param_3;
  iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                    (*(longlong **)(this + 0x18),&local_res8);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res8 + 0x40))(local_res8,0x101);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,local_res10,1);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,local_res20,1);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_res8 + 0x58))(local_res8,param_2,local_res20[0]);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_res8 + 0x70))(local_res8,&param_4,1);
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,&param_6,1);
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*local_res8 + 0x58))(local_res8,param_5,param_6);
                if (-1 < iVar1) {
                  iVar1 = (**(code **)(*local_res8 + 0x20))();
                }
              }
            }
          }
        }
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res8);
  return iVar1;
}



===== UrbCompletionNoData @ 14000f770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyITsRequestCompletion<struct
   ITsRequestCompletion>::UrbCompletionNoData(unsigned long,char * __ptr64,unsigned
   long,long,unsigned long) __ptr64 */

long __thiscall
CProxyITsRequestCompletion<ITsRequestCompletion>::UrbCompletionNoData
          (CProxyITsRequestCompletion<ITsRequestCompletion> *this,ulong param_1,char *param_2,
          ulong param_3,long param_4,ulong param_5)

{
  int iVar1;
  longlong *local_res8;
  ulong local_res10 [4];
  ulong local_res20 [2];
  
  local_res8 = (longlong *)0x0;
  local_res10[0] = param_1;
  local_res20[0] = param_3;
  iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                    (*(longlong **)(this + 0x18),&local_res8);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res8 + 0x40))(local_res8,0x102);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,local_res10,1);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,local_res20,1);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_res8 + 0x58))(local_res8,param_2,local_res20[0]);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_res8 + 0x70))(local_res8,&param_4,1);
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,&param_5,1);
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*local_res8 + 0x20))();
              }
            }
          }
        }
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res8);
  return iVar1;
}



===== UrbTransferInRequest @ 14000f8a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyITsUsbDevice<struct ITsUsbDevice>::UrbTransferInRequest(char *
   __ptr64,unsigned long,unsigned long) __ptr64 */

long __thiscall
CProxyITsUsbDevice<ITsUsbDevice>::UrbTransferInRequest
          (CProxyITsUsbDevice<ITsUsbDevice> *this,char *param_1,ulong param_2,ulong param_3)

{
  int iVar1;
  longlong *local_res8 [2];
  ulong local_res18 [2];
  ulong local_res20 [2];
  
  local_res8[0] = (longlong *)0x0;
  local_res18[0] = param_2;
  local_res20[0] = param_3;
  iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))(*(longlong **)(this + 0x18),local_res8)
  ;
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res8[0] + 0x40))(local_res8[0],0x105);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res8[0] + 0x98))(local_res8[0],local_res18,1);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_res8[0] + 0x58))(local_res8[0],param_1,local_res18[0]);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_res8[0] + 0x98))(local_res8[0],local_res20,1);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_res8[0] + 0x20))();
          }
        }
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)local_res8);
  return iVar1;
}



===== UrbTransferOutRequest @ 14000f990 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyITsUsbDevice<struct ITsUsbDevice>::UrbTransferOutRequest(char
   * __ptr64,unsigned long,char * __ptr64,unsigned long) __ptr64 */

long __thiscall
CProxyITsUsbDevice<ITsUsbDevice>::UrbTransferOutRequest
          (CProxyITsUsbDevice<ITsUsbDevice> *this,char *param_1,ulong param_2,char *param_3,
          ulong param_4)

{
  int iVar1;
  longlong *local_res8;
  ulong local_res18 [4];
  
  local_res8 = (longlong *)0x0;
  local_res18[0] = param_2;
  iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                    (*(longlong **)(this + 0x18),&local_res8);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res8 + 0x40))(local_res8,0x106);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,local_res18,1);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_res8 + 0x58))(local_res8,param_1,local_res18[0]);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,&param_4,1);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_res8 + 0x58))(local_res8,param_3,param_4);
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*local_res8 + 0x20))();
            }
          }
        }
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res8);
  return iVar1;
}



===== UsbInternalIoControl @ 14000faa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyITsUsbDevice<struct
   ITsUsbDevice>::UsbInternalIoControl(unsigned long,char * __ptr64,unsigned long,unsigned
   long,unsigned long) __ptr64 */

long __thiscall
CProxyITsUsbDevice<ITsUsbDevice>::UsbInternalIoControl
          (CProxyITsUsbDevice<ITsUsbDevice> *this,ulong param_1,char *param_2,ulong param_3,
          ulong param_4,ulong param_5)

{
  int iVar1;
  longlong *local_res8;
  ulong local_res10 [4];
  ulong local_res20 [2];
  
  local_res8 = (longlong *)0x0;
  local_res10[0] = param_1;
  local_res20[0] = param_3;
  iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                    (*(longlong **)(this + 0x18),&local_res8);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res8 + 0x40))(local_res8,0x103);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,local_res10,1);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,local_res20,1);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_res8 + 0x58))(local_res8,param_2,local_res20[0]);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,&param_4,1);
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,&param_5,1);
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*local_res8 + 0x20))();
              }
            }
          }
        }
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res8);
  return iVar1;
}



===== UsbIoControl @ 14000fbe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyITsUsbDevice<struct ITsUsbDevice>::UsbIoControl(unsigned
   long,char * __ptr64,unsigned long,unsigned long,unsigned long) __ptr64 */

long __thiscall
CProxyITsUsbDevice<ITsUsbDevice>::UsbIoControl
          (CProxyITsUsbDevice<ITsUsbDevice> *this,ulong param_1,char *param_2,ulong param_3,
          ulong param_4,ulong param_5)

{
  int iVar1;
  longlong *local_res8;
  ulong local_res10 [4];
  ulong local_res20 [2];
  
  local_res8 = (longlong *)0x0;
  local_res10[0] = param_1;
  local_res20[0] = param_3;
  iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                    (*(longlong **)(this + 0x18),&local_res8);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res8 + 0x40))(local_res8,0x102);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,local_res10,1);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,local_res20,1);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_res8 + 0x58))(local_res8,param_2,local_res20[0]);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,&param_4,1);
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*local_res8 + 0x98))(local_res8,&param_5,1);
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*local_res8 + 0x20))();
              }
            }
          }
        }
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res8);
  return iVar1;
}



===== IsAnyStringInMultiSzOnStringTable @ 14000fd14 =====

/* unsigned char __cdecl IsAnyStringInMultiSzOnStringTable(unsigned short const * __ptr64,unsigned
   short const * __ptr64 * __ptr64 const,unsigned long,unsigned long * __ptr64) */

uchar __cdecl
IsAnyStringInMultiSzOnStringTable(ushort *param_1,ushort **param_2,ulong param_3,ulong *param_4)

{
  wchar_t wVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  uchar uVar5;
  __uint64 local_res8;
  
  local_res8 = 0;
  uVar5 = '\0';
  wVar1 = *param_1;
  while( true ) {
    if (wVar1 == L'\0') {
      return uVar5;
    }
    for (uVar4 = 0; uVar4 < param_3; uVar4 = uVar4 + 1) {
      iVar2 = _wcsicmp((wchar_t *)param_1,(wchar_t *)param_2[uVar4]);
      if (iVar2 == 0) {
        if (param_4 != (ulong *)0x0) {
          *param_4 = uVar4;
        }
        return '\x01';
      }
    }
    uVar5 = '\0';
    lVar3 = RtlStringCchLengthW(param_1,0xffff,&local_res8);
    if (lVar3 < 0) break;
    param_1 = param_1 + local_res8 + 1;
    wVar1 = *param_1;
  }
  return uVar5;
}



===== ValidateMultiStrings @ 14000fdc4 =====

/* long __cdecl ValidateMultiStrings(unsigned short const * __ptr64,unsigned __int64,unsigned long *
   __ptr64,unsigned __int64 * __ptr64,unsigned short const * __ptr64 * __ptr64 * __ptr64) */

long __cdecl
ValidateMultiStrings
          (ushort *param_1,__uint64 param_2,ulong *param_3,__uint64 *param_4,ushort ***param_5)

{
  ulonglong uVar1;
  ushort *puVar2;
  ulonglong uVar3;
  long lVar4;
  __uint64 _Var5;
  ulong uVar6;
  __uint64 _Var7;
  
  _Var7 = 0;
  if (1 < param_2) {
    uVar6 = 0;
    _Var5 = param_2;
    for (; *param_1 != 0; param_1 = param_1 + (uVar3 - uVar1) + 1) {
      uVar3 = _Var5 >> 1;
      uVar1 = uVar3;
      puVar2 = param_1;
      if (0x7fffffff < uVar3) goto LAB_14000fe81;
      for (; (uVar1 != 0 && (*puVar2 != 0)); puVar2 = puVar2 + 1) {
        uVar1 = uVar1 - 1;
      }
      if (uVar1 == 0) goto LAB_14000fe81;
      uVar6 = uVar6 + 1;
      _Var5 = _Var5 + (uVar3 - uVar1) * -2 + -2;
    }
    if (uVar6 != 0) {
      lVar4 = 0;
      _Var7 = param_2 - (_Var5 - 2);
      goto LAB_14000fe8f;
    }
  }
LAB_14000fe81:
  lVar4 = -0x3ffffff3;
  uVar6 = 0;
LAB_14000fe8f:
  *param_3 = uVar6;
  *param_4 = _Var7;
  operator_delete((void *)0x0);
  return lVar4;
}



===== AddItemNoDuplicate @ 14000fec0 =====

/* public: long __cdecl CSimpleHash::AddItemNoDuplicate(void * __ptr64,unsigned long * __ptr64)
   __ptr64 */

long __thiscall CSimpleHash::AddItemNoDuplicate(CSimpleHash *this,void *param_1,ulong *param_2)

{
  long lVar1;
  ulong local_res8 [2];
  
  local_res8[0] = 0;
  if (this[0x18] == (CSimpleHash)0x0) {
    lVar1 = FindEmptySlot(this,local_res8);
    if (-1 < lVar1) {
      *(void **)(*(longlong *)(this + 8) + (ulonglong)local_res8[0] * 8) = param_1;
      if (param_2 != (ulong *)0x0) {
        *param_2 = local_res8[0];
      }
      lVar1 = 0;
    }
  }
  else {
    lVar1 = -0x3fffffff;
  }
  return lVar1;
}



===== CreateInstance @ 14000ff24 =====

/* public: static long __cdecl CSimpleHash::CreateInstance(unsigned long,class CSimpleHash * __ptr64
   * __ptr64) */

long __cdecl CSimpleHash::CreateInstance(ulong param_1,CSimpleHash **param_2)

{
  long lVar1;
  CSimpleHash *this;
  
  this = (CSimpleHash *)ExAllocatePoolWithTag(0x200,0x20,0x72447244);
  if (this == (CSimpleHash *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_cf9536f321c83b2982054c1fb1ce0b49_Traceguids);
    }
    lVar1 = -0x3fffffe9;
  }
  else {
    *(undefined4 *)this = 0;
    *(undefined8 *)(this + 8) = 0;
    *(undefined8 *)(this + 0x10) = 0;
    this[0x18] = (CSimpleHash)0x0;
    lVar1 = Initialize(this,param_1);
    if (lVar1 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        param_1 = 0xb;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_cf9536f321c83b2982054c1fb1ce0b49_Traceguids);
      }
      _scalar_deleting_destructor_(this,param_1);
    }
    else {
      *param_2 = this;
      lVar1 = 0;
    }
  }
  return lVar1;
}



===== FindEmptySlot @ 140010008 =====

/* private: long __cdecl CSimpleHash::FindEmptySlot(unsigned long * __ptr64) __ptr64 */

long __thiscall CSimpleHash::FindEmptySlot(CSimpleHash *this,ulong *param_1)

{
  uint uVar1;
  undefined8 uVar2;
  void *pvVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  undefined8 *puVar6;
  long lVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar10 = *(uint *)this;
  lVar7 = 0;
  pvVar3 = (void *)0x0;
  uVar8 = 0xffffffff;
  for (uVar9 = 0; uVar9 < uVar10; uVar9 = uVar9 + 1) {
    if (*(longlong *)(*(longlong *)(this + 8) + (ulonglong)uVar9 * 8) == *(longlong *)(this + 0x10))
    {
      uVar8 = uVar9;
      goto LAB_140010152;
    }
  }
  uVar1 = (uVar10 >> 2) + uVar10;
  uVar9 = uVar1 + 1;
  if (uVar10 >> 2 != 0) {
    uVar9 = uVar1;
  }
  if (uVar9 == 0xffffffff) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar5 = 0xe;
LAB_14001008b:
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
              &WPP_cf9536f321c83b2982054c1fb1ce0b49_Traceguids);
    }
  }
  else {
    uVar2 = SUB168(ZEXT816(8) * ZEXT416(uVar9),0);
    if (SUB168(ZEXT816(8) * ZEXT416(uVar9),8) != 0) {
      uVar2 = 0xffffffffffffffff;
    }
    pvVar3 = (void *)ExAllocatePoolWithTag(0x200,uVar2,0x72447244);
    if (*(longlong *)(this + 8) != 0) {
      uVar10 = *(uint *)this;
      if (uVar10 < uVar9) {
        puVar6 = (undefined8 *)((longlong)pvVar3 + (ulonglong)uVar10 * 8);
        uVar4 = (ulonglong)(uVar9 - uVar10);
        do {
          *puVar6 = *(undefined8 *)(this + 0x10);
          puVar6 = puVar6 + 1;
          uVar4 = uVar4 - 1;
        } while (uVar4 != 0);
      }
      uVar8 = 0;
      uVar4 = 0;
      if (*(int *)this != 0) {
        do {
          uVar10 = (int)uVar4 + 1;
          *(undefined8 *)((longlong)pvVar3 + uVar4 * 8) =
               *(undefined8 *)(*(longlong *)(this + 8) + uVar4 * 8);
          uVar8 = *(uint *)this;
          uVar4 = (ulonglong)uVar10;
        } while (uVar10 < uVar8);
      }
      operator_delete(*(void **)(this + 8));
      *(void **)(this + 8) = pvVar3;
      pvVar3 = (void *)0x0;
      *(uint *)this = uVar9;
      goto LAB_140010152;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar5 = 0xf;
      goto LAB_14001008b;
    }
  }
  lVar7 = -0x3fffffe9;
LAB_140010152:
  *param_1 = uVar8;
  operator_delete(pvVar3);
  return lVar7;
}



===== FindItem @ 140010180 =====

/* public: long __cdecl CSimpleHash::FindItem(void * __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall CSimpleHash::FindItem(CSimpleHash *this,void *param_1,ulong *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (*(uint *)this <= uVar1) {
      return -0x3ffffddb;
    }
    if (*(void **)(*(longlong *)(this + 8) + (ulonglong)uVar1 * 8) == param_1) break;
    uVar1 = uVar1 + 1;
  }
  return 0;
}



===== FindNextItem @ 1400101b4 =====

/* public: long __cdecl CSimpleHash::FindNextItem(unsigned long * __ptr64,void * __ptr64 * __ptr64)
   __ptr64 */

long __thiscall CSimpleHash::FindNextItem(CSimpleHash *this,ulong *param_1,void **param_2)

{
  void *pvVar1;
  long lVar2;
  uint uVar3;
  
  uVar3 = *param_1;
  if (uVar3 < *(uint *)this) {
    do {
      pvVar1 = *(void **)(*(longlong *)(this + 8) + (ulonglong)uVar3 * 8);
      if (pvVar1 != *(void **)(this + 0x10)) {
        if (uVar3 != 0xffffffff) {
          *param_2 = pvVar1;
          *param_1 = uVar3;
          return 0;
        }
        break;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)this);
    lVar2 = -0x3ffffddb;
  }
  else {
    lVar2 = -0x3ffffff3;
  }
  return lVar2;
}



===== Initialize @ 140010210 =====

/* private: long __cdecl CSimpleHash::Initialize(unsigned long) __ptr64 */

long __thiscall CSimpleHash::Initialize(CSimpleHash *this,ulong param_1)

{
  uint uVar1;
  undefined8 uVar2;
  longlong lVar3;
  long lVar4;
  ulonglong uVar5;
  
  *(ulong *)this = param_1;
  lVar4 = 0;
  *(undefined8 *)(this + 0x10) = 0;
  uVar2 = SUB168(ZEXT816(8) * ZEXT416(param_1),0);
  if (SUB168(ZEXT816(8) * ZEXT416(param_1),8) != 0) {
    uVar2 = 0xffffffffffffffff;
  }
  lVar3 = ExAllocatePoolWithTag(0x200,uVar2,0x72447244);
  *(longlong *)(this + 8) = lVar3;
  if (lVar3 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_cf9536f321c83b2982054c1fb1ce0b49_Traceguids);
    }
    lVar4 = -0x3fffffe9;
  }
  else {
    uVar1 = 0;
    if (*(int *)this != 0) {
      do {
        uVar5 = (ulonglong)uVar1;
        uVar1 = uVar1 + 1;
        *(undefined8 *)(*(longlong *)(this + 8) + uVar5 * 8) = *(undefined8 *)(this + 0x10);
      } while (uVar1 < *(uint *)this);
    }
  }
  return lVar4;
}



===== RemoveItemByIndex @ 1400102bc =====

/* public: long __cdecl CSimpleHash::RemoveItemByIndex(unsigned long,void * __ptr64 * __ptr64)
   __ptr64 */

long __thiscall CSimpleHash::RemoveItemByIndex(CSimpleHash *this,ulong param_1,void **param_2)

{
  void *pvVar1;
  
  if (param_1 < *(uint *)this) {
    pvVar1 = *(void **)(*(longlong *)(this + 8) + (ulonglong)param_1 * 8);
    if (pvVar1 != *(void **)(this + 0x10)) {
      *(undefined8 *)(*(longlong *)(this + 8) + (ulonglong)param_1 * 8) =
           *(undefined8 *)(this + 0x10);
      if (param_2 != (void **)0x0) {
        *param_2 = pvVar1;
      }
      return 0;
    }
  }
  return -0x3ffffff3;
}



===== CreateInstance @ 1400102f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl CTsUrb::CreateInstance(void * __ptr64,struct _URB * __ptr64,class
   CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class CTsUrb * __ptr64 * __ptr64) */

long __cdecl
CTsUrb::CreateInstance
          (void *param_1,_URB *param_2,CSimpleHash *param_3,CSimpleHash *param_4,CTsUrb **param_5)

{
  longlong lVar1;
  ushort uVar2;
  undefined **ppuVar3;
  uint uVar4;
  int iVar5;
  
  uVar2 = *(ushort *)(param_2 + 2);
  uVar4 = (uint)uVar2;
  if (uVar2 < 0x1b) {
    if (uVar2 == 0x1a) {
LAB_14001047e:
      if (param_1 == (void *)0x0) {
        return -0x3fffff45;
      }
      ppuVar3 = &CTsUrbClassRequest::_vftable_;
    }
    else {
      if (uVar4 < 0xe) {
        if (uVar4 != 0xd) {
          if (uVar4 < 7) {
            if (uVar4 == 6) {
              return -0x3fffff45;
            }
            if (uVar4 == 0) {
              if (param_1 == (void *)0x0) {
                return -0x3fffff45;
              }
              ppuVar3 = &CTsUrbSelectConfig::_vftable_;
            }
            else {
              if (uVar4 != 1) {
                if (uVar4 != 2) {
                  return -0x3fffff45;
                }
                goto joined_r0x000140010584;
              }
              if (param_1 == (void *)0x0) {
                return -0x3fffff45;
              }
              ppuVar3 = &CTsUrbSelectInterface::_vftable_;
            }
            *(undefined ***)param_1 = ppuVar3;
            lVar1 = (longlong)param_1 + 0x18;
            *(longlong *)((longlong)param_1 + 0x20) = lVar1;
            *(longlong *)lVar1 = lVar1;
            goto LAB_1400105a2;
          }
          if (uVar4 == 7) {
            if (param_1 == (void *)0x0) {
              return -0x3fffff45;
            }
            ppuVar3 = &CTsUrbCurrentFrame::_vftable_;
          }
          else if (uVar4 == 8) {
            if (param_1 == (void *)0x0) {
              return -0x3fffff45;
            }
            ppuVar3 = &CTsUrbControlTransfer::_vftable_;
          }
          else if (uVar4 == 9) {
            if (param_1 == (void *)0x0) {
              return -0x3fffff45;
            }
            ppuVar3 = &CTsUrbBulkTransfer::_vftable_;
          }
          else {
            if (uVar4 != 10) {
              if ((uVar4 != 0xb) && (uVar4 != 0xc)) {
                return -0x3fffff45;
              }
              goto LAB_1400103a9;
            }
            if (param_1 == (void *)0x0) {
              return -0x3fffff45;
            }
            ppuVar3 = &CTsUrbIsochTransfer::_vftable_;
          }
          goto LAB_140010591;
        }
LAB_140010448:
        if (param_1 == (void *)0x0) {
          return -0x3fffff45;
        }
        ppuVar3 = &CTsUrbControlFeature::_vftable_;
        goto LAB_140010591;
      }
      if (uVar4 < 0x15) {
        if (uVar4 != 0x14) {
          if ((((uVar4 == 0xe) || (uVar4 == 0xf)) || (uVar4 == 0x10)) ||
             ((uVar4 == 0x11 || (uVar4 == 0x12)))) goto LAB_140010448;
          if (uVar4 != 0x13) {
            return -0x3fffff45;
          }
        }
      }
      else if (uVar4 != 0x15) {
        if (uVar4 == 0x16) {
          return -0x3fffff45;
        }
        iVar5 = uVar4 - 0x17;
        if (iVar5 != 0) {
LAB_140010470:
          if ((iVar5 != 1) && (iVar5 != 2)) {
            return -0x3fffff45;
          }
        }
        goto LAB_14001047e;
      }
LAB_140010433:
      if (param_1 == (void *)0x0) {
        return -0x3fffff45;
      }
      ppuVar3 = &CTsUrbGetInterfaceRequest::_vftable_;
    }
  }
  else if (uVar2 < 0x29) {
    if (uVar2 != 0x28) {
      if (uVar4 < 0x22) {
        if (uVar4 == 0x21) goto LAB_140010433;
        if ((uVar4 == 0x1b) || (uVar4 == 0x1c)) goto LAB_14001047e;
        if (uVar4 == 0x1d) {
          return -0x3fffff45;
        }
        iVar5 = uVar4 - 0x1e;
        if (iVar5 != 0) goto LAB_140010470;
        goto joined_r0x000140010584;
      }
      if ((uVar4 == 0x22) || (uVar4 == 0x23)) goto LAB_140010448;
      if ((uVar4 != 0x24) && (uVar4 != 0x25)) {
        if (uVar4 == 0x26) {
          if (param_1 == (void *)0x0) {
            return -0x3fffff45;
          }
          ppuVar3 = &CTsUrbGetConfigRequest::_vftable_;
        }
        else {
          if (uVar4 != 0x27) {
            return -0x3fffff45;
          }
          if (param_1 == (void *)0x0) {
            return -0x3fffff45;
          }
          ppuVar3 = &CTsUrbGetInterfaceRequest::_vftable_;
        }
        goto LAB_140010591;
      }
    }
LAB_1400103a9:
    if (param_1 == (void *)0x0) {
      return -0x3fffff45;
    }
    ppuVar3 = &CTsUrbControlDescriptor::_vftable_;
  }
  else if (uVar4 < 0x30) {
    if (uVar4 == 0x2f) {
      return -0x3fffff45;
    }
    if (uVar4 == 0x29) goto LAB_1400103a9;
    if (uVar4 != 0x2a) {
      return -0x3fffff45;
    }
    if (param_1 == (void *)0x0) {
      return -0x3fffff45;
    }
    ppuVar3 = &CTsUrbOsFeatureDescriptor::_vftable_;
  }
  else if ((uVar4 == 0x30) || (uVar4 == 0x31)) {
joined_r0x000140010584:
    if (param_1 == (void *)0x0) {
      return -0x3fffff45;
    }
    ppuVar3 = &CTsUrbPipeRequest::_vftable_;
  }
  else {
    if (uVar4 != 0x32) {
      return -0x3fffff45;
    }
    if (param_1 == (void *)0x0) {
      return -0x3fffff45;
    }
    ppuVar3 = &CTsUrbControlTransferEx::_vftable_;
  }
LAB_140010591:
  *(undefined8 *)param_1 = 0;
  *(undefined8 *)((longlong)param_1 + 8) = 0;
  *(undefined8 *)((longlong)param_1 + 0x10) = 0;
  *(undefined8 *)((longlong)param_1 + 0x18) = 0;
  *(undefined8 *)((longlong)param_1 + 0x20) = 0;
  *(undefined8 *)((longlong)param_1 + 0x28) = 0;
  *(undefined ***)param_1 = ppuVar3;
LAB_1400105a2:
  iVar5 = (*(code *)**(undefined8 **)param_1)(param_1);
  if (iVar5 < 0) {
    return iVar5;
  }
  *param_5 = param_1;
  return 0;
}



===== FindTsPipeInfoInPipeHandleTable @ 1400105d0 =====

/* public: static struct _TS_PIPE_INFORMATION * __ptr64 __cdecl
   CTsUrb::FindTsPipeInfoInPipeHandleTable(class CSimpleHash * __ptr64,void * __ptr64) */

_TS_PIPE_INFORMATION * __cdecl
CTsUrb::FindTsPipeInfoInPipeHandleTable(CSimpleHash *param_1,void *param_2)

{
  long lVar1;
  ulong local_res10 [2];
  _TS_PIPE_INFORMATION *local_res18 [2];
  
  local_res10[0] = 0;
  while( true ) {
    local_res18[0] = (_TS_PIPE_INFORMATION *)0x0;
    lVar1 = CSimpleHash::FindNextItem(param_1,local_res10,local_res18);
    if ((lVar1 < 0) || (local_res18[0] == param_2)) break;
    local_res10[0] = local_res10[0] + 1;
  }
  return local_res18[0];
}



===== GetRealPipeHandle @ 140010624 =====

/* public: static unsigned long __cdecl CTsUrb::GetRealPipeHandle(class CSimpleHash * __ptr64,class
   CSimpleHash * __ptr64,void * __ptr64) */

ulong __cdecl CTsUrb::GetRealPipeHandle(CSimpleHash *param_1,CSimpleHash *param_2,void *param_3)

{
  _TS_PIPE_INFORMATION *p_Var1;
  
  p_Var1 = FindTsPipeInfoInPipeHandleTable(param_1,param_3);
  if (p_Var1 == (_TS_PIPE_INFORMATION *)0x0) {
    if (param_2 == (CSimpleHash *)0x0) {
      return 0;
    }
    p_Var1 = FindTsPipeInfoInPipeHandleTable(param_2,param_3);
    if (p_Var1 == (_TS_PIPE_INFORMATION *)0x0) {
      return 0;
    }
  }
  return *(ulong *)(p_Var1 + 8);
}



===== Initialize @ 140010680 =====

/* private: virtual long __cdecl CTsUrbBulkTransfer::Initialize(struct _URB * __ptr64,class
   CSimpleHash * __ptr64,class CSimpleHash * __ptr64) __ptr64 */

long __thiscall
CTsUrbBulkTransfer::Initialize
          (CTsUrbBulkTransfer *this,_URB *param_1,CSimpleHash *param_2,CSimpleHash *param_3)

{
  ulong uVar1;
  longlong lVar2;
  
  CTsUrb::UrbFixupTransferFlags
            (*(void **)(param_1 + 0x18),param_2,param_3,(ulong *)(param_1 + 0x20));
  if (*(int *)(param_1 + 0x24) == 0) {
    lVar2 = 0;
  }
  else {
    lVar2 = *(longlong *)(param_1 + 0x30);
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(param_1 + 0x28);
    }
    else if ((*(byte *)(lVar2 + 10) & 5) == 0) {
      lVar2 = MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000010);
    }
    else {
      lVar2 = *(longlong *)(lVar2 + 0x18);
    }
    if (lVar2 == 0) {
      return -0x3fffff66;
    }
  }
  uVar1 = CTsUrb::GetRealPipeHandle(param_2,param_3,*(void **)(param_1 + 0x18));
  *(ulong *)(this + 0x20) = uVar1;
  if (uVar1 == 0) {
    *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x18);
  }
  *(_URB **)(this + 8) = param_1;
  *(undefined2 *)(this + 0x10) = 0x10;
  *(longlong *)(this + 0x18) = lVar2;
  return 0;
}



===== Initialize @ 140010760 =====

/* private: virtual long __cdecl CTsUrbClassRequest::Initialize(struct _URB * __ptr64,class
   CSimpleHash * __ptr64,class CSimpleHash * __ptr64) __ptr64 */

long __thiscall
CTsUrbClassRequest::Initialize
          (CTsUrbClassRequest *this,_URB *param_1,CSimpleHash *param_2,CSimpleHash *param_3)

{
  longlong lVar1;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    lVar1 = 0;
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x30);
    if (lVar1 == 0) {
      lVar1 = *(longlong *)(param_1 + 0x28);
    }
    else if ((*(byte *)(lVar1 + 10) & 5) == 0) {
      lVar1 = MmMapLockedPagesSpecifyCache(lVar1,0,1,0,0,0x40000010);
    }
    else {
      lVar1 = *(longlong *)(lVar1 + 0x18);
    }
    if (lVar1 == 0) {
      return -0x3fffff66;
    }
  }
  *(_URB **)(this + 8) = param_1;
  *(undefined2 *)(this + 0x10) = 0x14;
  *(longlong *)(this + 0x18) = lVar1;
  return 0;
}



===== Initialize @ 1400107f0 =====

/* private: virtual long __cdecl CTsUrbControlDescriptor::Initialize(struct _URB * __ptr64,class
   CSimpleHash * __ptr64,class CSimpleHash * __ptr64) __ptr64 */

long __thiscall
CTsUrbControlDescriptor::Initialize
          (CTsUrbControlDescriptor *this,_URB *param_1,CSimpleHash *param_2,CSimpleHash *param_3)

{
  longlong lVar1;
  long lVar2;
  CTsUrbControlDescriptor CVar3;
  
  lVar2 = 0;
  lVar1 = *(longlong *)(param_1 + 0x30);
  CVar3 = (CTsUrbControlDescriptor)0x1;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)(param_1 + 0x28);
  }
  else if ((*(byte *)(lVar1 + 10) & 5) == 0) {
    lVar1 = MmMapLockedPagesSpecifyCache(lVar1,0,1,0,0,0x40000010);
  }
  else {
    lVar1 = *(longlong *)(lVar1 + 0x18);
  }
  if (lVar1 == 0) {
    lVar2 = -0x3fffff66;
  }
  else {
    if ((0x28 < *(ushort *)(param_1 + 2)) ||
       ((0x11000000800U >> ((ulonglong)*(ushort *)(param_1 + 2) & 0x3f) & 1) == 0)) {
      CVar3 = (CTsUrbControlDescriptor)0x0;
    }
    this[0x20] = CVar3;
    *(_URB **)(this + 8) = param_1;
    *(undefined2 *)(this + 0x10) = 0xc;
    *(longlong *)(this + 0x18) = lVar1;
  }
  return lVar2;
}



===== Initialize @ 1400108b0 =====

/* private: virtual long __cdecl CTsUrbControlFeature::Initialize(struct _URB * __ptr64,class
   CSimpleHash * __ptr64,class CSimpleHash * __ptr64) __ptr64 */

long __thiscall
CTsUrbControlFeature::Initialize
          (CTsUrbControlFeature *this,_URB *param_1,CSimpleHash *param_2,CSimpleHash *param_3)

{
  *(_URB **)(this + 8) = param_1;
  *(undefined2 *)(this + 0x10) = 0xc;
  return 0;
}



===== Initialize @ 1400108d0 =====

/* private: virtual long __cdecl CTsUrbControlTransfer::Initialize(struct _URB * __ptr64,class
   CSimpleHash * __ptr64,class CSimpleHash * __ptr64) __ptr64 */

long __thiscall
CTsUrbControlTransfer::Initialize
          (CTsUrbControlTransfer *this,_URB *param_1,CSimpleHash *param_2,CSimpleHash *param_3)

{
  ulong uVar1;
  longlong lVar2;
  
  if ((*(uint *)(param_1 + 0x20) & 8) == 0) {
    CTsUrb::UrbFixupTransferFlags
              (*(void **)(param_1 + 0x18),param_2,param_3,(ulong *)(param_1 + 0x20));
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    lVar2 = 0;
  }
  else {
    lVar2 = *(longlong *)(param_1 + 0x30);
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(param_1 + 0x28);
    }
    else if ((*(byte *)(lVar2 + 10) & 5) == 0) {
      lVar2 = MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000010);
    }
    else {
      lVar2 = *(longlong *)(lVar2 + 0x18);
    }
    if (lVar2 == 0) {
      return -0x3fffff66;
    }
  }
  uVar1 = CTsUrb::GetRealPipeHandle(param_2,param_3,*(void **)(param_1 + 0x18));
  *(ulong *)(this + 0x20) = uVar1;
  if (uVar1 == 0) {
    *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x18);
  }
  *(_URB **)(this + 8) = param_1;
  *(undefined2 *)(this + 0x10) = 0x18;
  *(longlong *)(this + 0x18) = lVar2;
  return 0;
}



===== Initialize @ 1400109b0 =====

/* private: virtual long __cdecl CTsUrbControlTransferEx::Initialize(struct _URB * __ptr64,class
   CSimpleHash * __ptr64,class CSimpleHash * __ptr64) __ptr64 */

long __thiscall
CTsUrbControlTransferEx::Initialize
          (CTsUrbControlTransferEx *this,_URB *param_1,CSimpleHash *param_2,CSimpleHash *param_3)

{
  ulong uVar1;
  longlong lVar2;
  
  if ((*(uint *)(param_1 + 0x20) & 8) == 0) {
    CTsUrb::UrbFixupTransferFlags
              (*(void **)(param_1 + 0x18),param_2,param_3,(ulong *)(param_1 + 0x20));
  }
  if (*(int *)(param_1 + 0x24) == 0) {
    lVar2 = 0;
  }
  else {
    lVar2 = *(longlong *)(param_1 + 0x30);
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(param_1 + 0x28);
    }
    else if ((*(byte *)(lVar2 + 10) & 5) == 0) {
      lVar2 = MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000010);
    }
    else {
      lVar2 = *(longlong *)(lVar2 + 0x18);
    }
    if (lVar2 == 0) {
      return -0x3fffff66;
    }
  }
  uVar1 = CTsUrb::GetRealPipeHandle(param_2,param_3,*(void **)(param_1 + 0x18));
  *(ulong *)(this + 0x20) = uVar1;
  if (uVar1 == 0) {
    *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x18);
  }
  *(_URB **)(this + 8) = param_1;
  *(undefined2 *)(this + 0x10) = 0x1c;
  *(longlong *)(this + 0x18) = lVar2;
  return 0;
}



===== Initialize @ 140010a90 =====

/* private: virtual long __cdecl CTsUrbCurrentFrame::Initialize(struct _URB * __ptr64,class
   CSimpleHash * __ptr64,class CSimpleHash * __ptr64) __ptr64 */

long __thiscall
CTsUrbCurrentFrame::Initialize
          (CTsUrbCurrentFrame *this,_URB *param_1,CSimpleHash *param_2,CSimpleHash *param_3)

{
  *(_URB **)(this + 8) = param_1;
  *(undefined2 *)(this + 0x10) = 8;
  return 0;
}



===== Initialize @ 140010ab0 =====

/* private: virtual long __cdecl CTsUrbGetConfigRequest::Initialize(struct _URB * __ptr64,class
   CSimpleHash * __ptr64,class CSimpleHash * __ptr64) __ptr64 */

long __thiscall
CTsUrbGetConfigRequest::Initialize
          (CTsUrbGetConfigRequest *this,_URB *param_1,CSimpleHash *param_2,CSimpleHash *param_3)

{
  longlong lVar1;
  long lVar2;
  
  lVar2 = 0;
  lVar1 = *(longlong *)(param_1 + 0x30);
  if (lVar1 == 0) {
    lVar1 = *(longlong *)(param_1 + 0x28);
  }
  else if ((*(byte *)(lVar1 + 10) & 5) == 0) {
    lVar1 = MmMapLockedPagesSpecifyCache(lVar1,0,1,0,0,0x40000010);
  }
  else {
    lVar1 = *(longlong *)(lVar1 + 0x18);
  }
  if (lVar1 == 0) {
    lVar2 = -0x3fffff66;
  }
  else {
    *(_URB **)(this + 8) = param_1;
    *(undefined2 *)(this + 0x10) = 8;
    *(longlong *)(this + 0x18) = lVar1;
  }
  return lVar2;
}



===== Initialize @ 140010b40 =====

/* private: virtual long __cdecl CTsUrbGetStatus::Initialize(struct _URB * __ptr64,class CSimpleHash
   * __ptr64,class CSimpleHash * __ptr64) __ptr64 */

long __thiscall
CTsUrbGetStatus::Initialize
          (CTsUrbGetStatus *this,_URB *param_1,CSimpleHash *param_2,CSimpleHash *param_3)

{
  longlong lVar1;
  long lVar2;
  
  lVar2 = 0;
  lVar1 = *(longlong *)(param_1 + 0x30);
  if (lVar1 == 0) {
    lVar1 = *(longlong *)(param_1 + 0x28);
  }
  else if ((*(byte *)(lVar1 + 10) & 5) == 0) {
    lVar1 = MmMapLockedPagesSpecifyCache(lVar1,0,1,0,0,0x40000010);
  }
  else {
    lVar1 = *(longlong *)(lVar1 + 0x18);
  }
  if (lVar1 == 0) {
    lVar2 = -0x3fffff66;
  }
  else {
    *(_URB **)(this + 8) = param_1;
    *(undefined2 *)(this + 0x10) = 0xc;
    *(longlong *)(this + 0x18) = lVar1;
  }
  return lVar2;
}



===== Initialize @ 140010bd0 =====

/* private: virtual long __cdecl CTsUrbIsochTransfer::Initialize(struct _URB * __ptr64,class
   CSimpleHash * __ptr64,class CSimpleHash * __ptr64) __ptr64 */

long __thiscall
CTsUrbIsochTransfer::Initialize
          (CTsUrbIsochTransfer *this,_URB *param_1,CSimpleHash *param_2,CSimpleHash *param_3)

{
  int iVar1;
  ulong uVar2;
  longlong lVar3;
  uint uVar4;
  long lVar5;
  
  if ((*(uint *)(param_1 + 0x20) & 0xfffffff8) == 0) {
    CTsUrb::UrbFixupTransferFlags
              (*(void **)(param_1 + 0x18),param_2,param_3,(ulong *)(param_1 + 0x20));
    lVar3 = *(longlong *)(param_1 + 0x30);
    lVar5 = 0;
    if (lVar3 == 0) {
      lVar3 = *(longlong *)(param_1 + 0x28);
    }
    else if ((*(byte *)(lVar3 + 10) & 5) == 0) {
      lVar3 = MmMapLockedPagesSpecifyCache(lVar3,0,1,0,0,0x40000010);
    }
    else {
      lVar3 = *(longlong *)(lVar3 + 0x18);
    }
    if (lVar3 == 0) {
      lVar5 = -0x3fffff66;
    }
    else if (((ulonglong)*(uint *)(param_1 + 0x84) * 0xc < 0x100000000) &&
            (iVar1 = (int)((ulonglong)*(uint *)(param_1 + 0x84) * 0xc), uVar4 = iVar1 + 0x8c,
            0x8b < uVar4)) {
      if (((*(ushort *)param_1 < uVar4) || (uVar4 = iVar1 + 0x1c, uVar4 < 0x1c)) || (0xffff < uVar4)
         ) {
        lVar5 = -0x3ffffff3;
      }
      else {
        uVar2 = CTsUrb::GetRealPipeHandle(param_2,param_3,*(void **)(param_1 + 0x18));
        *(ulong *)(this + 0x20) = uVar2;
        if (uVar2 == 0) {
          *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x18);
        }
        *(_URB **)(this + 8) = param_1;
        *(short *)(this + 0x10) = (short)uVar4;
        *(longlong *)(this + 0x18) = lVar3;
      }
    }
    else {
      lVar5 = -0x3fffff6b;
    }
  }
  else {
    lVar5 = -0x3ffffff3;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_b5b5be9865513811c37e2aadb7c40617_Traceguids,*(uint *)(param_1 + 0x20));
    }
  }
  return lVar5;
}



===== Initialize @ 140010d50 =====

/* private: virtual long __cdecl CTsUrbOsFeatureDescriptor::Initialize(struct _URB * __ptr64,class
   CSimpleHash * __ptr64,class CSimpleHash * __ptr64) __ptr64 */

long __thiscall
CTsUrbOsFeatureDescriptor::Initialize
          (CTsUrbOsFeatureDescriptor *this,_URB *param_1,CSimpleHash *param_2,CSimpleHash *param_3)

{
  longlong lVar1;
  long lVar2;
  
  lVar2 = 0;
  lVar1 = *(longlong *)(param_1 + 0x30);
  if (lVar1 == 0) {
    lVar1 = *(longlong *)(param_1 + 0x28);
  }
  else if ((*(byte *)(lVar1 + 10) & 5) == 0) {
    lVar1 = MmMapLockedPagesSpecifyCache(lVar1,0,1,0,0,0x40000010);
  }
  else {
    lVar1 = *(longlong *)(lVar1 + 0x18);
  }
  if (lVar1 == 0) {
    lVar2 = -0x3fffff66;
  }
  else {
    *(_URB **)(this + 8) = param_1;
    *(undefined2 *)(this + 0x10) = 0x10;
    *(longlong *)(this + 0x18) = lVar1;
  }
  return lVar2;
}



===== Initialize @ 140010de0 =====

/* private: virtual long __cdecl CTsUrbPipeRequest::Initialize(struct _URB * __ptr64,class
   CSimpleHash * __ptr64,class CSimpleHash * __ptr64) __ptr64 */

long __thiscall
CTsUrbPipeRequest::Initialize
          (CTsUrbPipeRequest *this,_URB *param_1,CSimpleHash *param_2,CSimpleHash *param_3)

{
  ulong uVar1;
  
  uVar1 = CTsUrb::GetRealPipeHandle(param_2,param_3,*(void **)(param_1 + 0x18));
  *(ulong *)(this + 0x20) = uVar1;
  if (uVar1 == 0) {
    *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x18);
  }
  *(_URB **)(this + 8) = param_1;
  *(undefined2 *)(this + 0x10) = 0xc;
  return 0;
}



===== Initialize @ 140010e30 =====

/* private: virtual long __cdecl CTsUrbSelectConfig::Initialize(struct _URB * __ptr64,class
   CSimpleHash * __ptr64,class CSimpleHash * __ptr64) __ptr64 */

long __thiscall
CTsUrbSelectConfig::Initialize
          (CTsUrbSelectConfig *this,_URB *param_1,CSimpleHash *param_2,CSimpleHash *param_3)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  uint uVar7;
  ushort uVar8;
  uint uVar9;
  _URB *p_Var10;
  byte *pbVar11;
  CTsUrbSelectConfig CVar12;
  uint uVar13;
  
  uVar9 = 0;
  pbVar11 = *(byte **)(param_1 + 0x18);
  CVar12 = (CTsUrbSelectConfig)0x0;
  if (0x28 < *(ushort *)param_1) {
    uVar8 = *(ushort *)param_1 - 0x28;
    if (pbVar11 != (byte *)0x0) {
      if (*pbVar11 != 9) {
        return -0x3ffffff3;
      }
      CVar12 = *(CTsUrbSelectConfig *)(pbVar11 + 4);
    }
    p_Var10 = param_1 + 0x28;
    uVar4 = 0;
    for (uVar13 = 0; uVar13 < (byte)CVar12; uVar13 = uVar13 + 1) {
      lVar3 = CTsUrb::UrbVerifyInterfaceInformation((uchar *)p_Var10,(uint)uVar8);
      if (lVar3 < 0) {
        return lVar3;
      }
      uVar7 = *(uint *)(p_Var10 + 0x10) + uVar4;
      if (uVar7 < uVar4) {
        return -0x3fffff6b;
      }
      uVar5 = (ulonglong)*(uint *)(p_Var10 + 0x10) * 0xc;
      if (0xffffffff < uVar5) {
        return -0x3fffff6b;
      }
      uVar4 = (int)uVar5 + 0xc;
      if (uVar4 < 0xc) {
        return -0x3fffff6b;
      }
      uVar9 = uVar9 + uVar4;
      if (uVar9 < uVar4) {
        return -0x3ffffff3;
      }
      if (0xffff < uVar9) {
        return -0x3ffffff3;
      }
      uVar8 = uVar8 - *(ushort *)p_Var10;
      p_Var10 = p_Var10 + *(ushort *)p_Var10;
      uVar4 = uVar7;
    }
    uVar9 = uVar9 + 0x10;
    if (uVar9 < 0x10) {
      return -0x3fffff6b;
    }
    if (pbVar11 != (byte *)0x0) {
      if (*pbVar11 < 9) {
        return -0x3ffffff3;
      }
      uVar8 = *(ushort *)(pbVar11 + 2);
      if (uVar8 < *pbVar11) {
        return -0x3ffffff3;
      }
      uVar9 = uVar9 + uVar8;
      if (uVar9 < uVar8) {
        return -0x3fffff6b;
      }
    }
    if (uVar9 < 0x10000) {
      uVar13 = 0;
      while( true ) {
        if (uVar4 <= uVar13) {
          *(_URB **)(this + 8) = param_1;
          this[0x28] = CVar12;
          *(short *)(this + 0x10) = (short)uVar9;
          return 0;
        }
        plVar6 = (longlong *)ExAllocatePoolWithTag(0x200,0x28,0x72447244);
        if (plVar6 == (longlong *)0x0) break;
        plVar1 = *(longlong **)(this + 0x20);
        if ((CTsUrbSelectConfig *)*plVar1 != this + 0x18) {
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)(3);
          return -0x3fffffe9;
        }
        *plVar6 = (longlong)(this + 0x18);
        uVar13 = uVar13 + 1;
        plVar6[1] = (longlong)plVar1;
        *plVar1 = (longlong)plVar6;
        *(longlong **)(this + 0x20) = plVar6;
      }
      return -0x3fffffe9;
    }
  }
  return -0x3ffffff3;
}



===== Initialize @ 140010fd0 =====

/* private: virtual long __cdecl CTsUrbSelectInterface::Initialize(struct _URB * __ptr64,class
   CSimpleHash * __ptr64,class CSimpleHash * __ptr64) __ptr64 */

long __thiscall
CTsUrbSelectInterface::Initialize
          (CTsUrbSelectInterface *this,_URB *param_1,CSimpleHash *param_2,CSimpleHash *param_3)

{
  longlong *plVar1;
  code *pcVar2;
  long lVar3;
  int iVar5;
  uint uVar4;
  longlong *plVar6;
  ushort uVar7;
  uint uVar8;
  
  uVar7 = *(ushort *)param_1;
  if (((uVar7 == 0) &&
      (uVar7 = *(short *)(param_1 + 0x30) * 0x18 + 0x38,
      (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_b5b5be9865513811c37e2aadb7c40617_Traceguids,0);
  }
  if (uVar7 < 0x21) {
    return -0x3ffffff3;
  }
  lVar3 = CTsUrb::UrbVerifyInterfaceInformation
                    ((uchar *)(param_1 + 0x20),(uint)(ushort)(uVar7 - 0x20));
  if (lVar3 < 0) {
    return lVar3;
  }
  uVar7 = *(ushort *)(param_1 + 0x20);
  if ((ulonglong)*(uint *)(param_1 + 0x30) * 0xc < 0x100000000) {
    iVar5 = (int)((ulonglong)*(uint *)(param_1 + 0x30) * 0xc);
    uVar4 = iVar5 + 0xc;
    if (0xb < uVar4) {
      if (uVar4 < 0x10000) {
        uVar4 = iVar5 + 0x18;
        if (uVar4 < 0xc) {
          return -0x3fffff6b;
        }
        if (uVar4 < 0x10000) {
          uVar8 = 0;
          while( true ) {
            if ((uint)(((ulonglong)uVar7 - 0x18) / 0x18) <= uVar8) {
              *(_URB **)(this + 8) = param_1;
              *(short *)(this + 0x10) = (short)uVar4;
              return 0;
            }
            plVar6 = (longlong *)ExAllocatePoolWithTag(0x200,0x28,0x72447244);
            if (plVar6 == (longlong *)0x0) break;
            plVar1 = *(longlong **)(this + 0x20);
            if ((CTsUrbSelectInterface *)*plVar1 != this + 0x18) {
              pcVar2 = (code *)swi(0x29);
              (*pcVar2)(3);
              return -0x3fffffe9;
            }
            *plVar6 = (longlong)(this + 0x18);
            uVar8 = uVar8 + 1;
            plVar6[1] = (longlong)plVar1;
            *plVar1 = (longlong)plVar6;
            *(longlong **)(this + 0x20) = plVar6;
          }
          return -0x3fffffe9;
        }
      }
      return -0x3ffffff3;
    }
  }
  return -0x3fffff6b;
}



===== TsUrbCompletion @ 140011150 =====

/* private: virtual void __cdecl CTsUrbBulkTransfer::TsUrbCompletion(unsigned char *
   __ptr64,unsigned long,void * __ptr64,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash
   * __ptr64) __ptr64 */

void __thiscall
CTsUrbBulkTransfer::TsUrbCompletion
          (CTsUrbBulkTransfer *this,uchar *param_1,ulong param_2,void *param_3,ulong param_4,
          CSimpleHash *param_5,CSimpleHash *param_6)

{
  longlong lVar1;
  long lVar2;
  
  lVar2 = UrbCompletion_JustStatus(*(_URB **)(this + 8),param_1,param_2,(ulong)param_3);
  if (-1 < lVar2) {
    lVar1 = *(longlong *)(this + 8);
    if (*(uint *)(lVar1 + 0x24) < param_4) {
      *(undefined4 *)(lVar1 + 4) = 0x80000300;
    }
    else {
      *(ulong *)(lVar1 + 0x24) = param_4;
      if (((*(uint *)(lVar1 + 0x20) & 1) != 0) && (param_3 != (void *)0x0)) {
        memmove(*(void **)(this + 0x18),param_3,(ulonglong)param_4);
      }
    }
  }
  return;
}



===== TsUrbCompletion @ 1400111b0 =====

/* private: virtual void __cdecl CTsUrbControlDescriptor::TsUrbCompletion(unsigned char *
   __ptr64,unsigned long,void * __ptr64,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash
   * __ptr64) __ptr64 */

void __thiscall
CTsUrbControlDescriptor::TsUrbCompletion
          (CTsUrbControlDescriptor *this,uchar *param_1,ulong param_2,void *param_3,ulong param_4,
          CSimpleHash *param_5,CSimpleHash *param_6)

{
  longlong lVar1;
  long lVar2;
  
  lVar2 = UrbCompletion_JustStatus(*(_URB **)(this + 8),param_1,param_2,(ulong)param_3);
  if (-1 < lVar2) {
    lVar1 = *(longlong *)(this + 8);
    if (*(uint *)(lVar1 + 0x24) < param_4) {
      *(undefined4 *)(lVar1 + 4) = 0x80000300;
    }
    else {
      *(ulong *)(lVar1 + 0x24) = param_4;
      if ((this[0x20] != (CTsUrbControlDescriptor)0x0) && (param_3 != (void *)0x0)) {
        memmove(*(void **)(this + 0x18),param_3,(ulonglong)param_4);
      }
    }
  }
  return;
}



===== TsUrbCompletion @ 140011210 =====

/* private: virtual void __cdecl CTsUrbControlFeature::TsUrbCompletion(unsigned char *
   __ptr64,unsigned long,void * __ptr64,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash
   * __ptr64) __ptr64 */

void __thiscall
CTsUrbControlFeature::TsUrbCompletion
          (CTsUrbControlFeature *this,uchar *param_1,ulong param_2,void *param_3,ulong param_4,
          CSimpleHash *param_5,CSimpleHash *param_6)

{
  UrbCompletion_JustStatus(*(_URB **)(this + 8),param_1,param_2,(ulong)param_3);
  return;
}



===== TsUrbCompletion @ 140011230 =====

/* private: virtual void __cdecl CTsUrbControlTransfer::TsUrbCompletion(unsigned char *
   __ptr64,unsigned long,void * __ptr64,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash
   * __ptr64) __ptr64 */

void __thiscall
CTsUrbControlTransfer::TsUrbCompletion
          (CTsUrbControlTransfer *this,uchar *param_1,ulong param_2,void *param_3,ulong param_4,
          CSimpleHash *param_5,CSimpleHash *param_6)

{
  longlong lVar1;
  long lVar2;
  
  lVar2 = UrbCompletion_JustStatus(*(_URB **)(this + 8),param_1,param_2,(ulong)param_3);
  if (-1 < lVar2) {
    lVar1 = *(longlong *)(this + 8);
    if (*(uint *)(lVar1 + 0x24) < param_4) {
      *(undefined4 *)(lVar1 + 4) = 0x80000300;
    }
    else {
      *(ulong *)(lVar1 + 0x24) = param_4;
      if (((*(uint *)(lVar1 + 0x20) & 1) != 0) && (param_4 != 0)) {
        memmove(*(void **)(this + 0x18),param_3,(ulonglong)param_4);
      }
    }
  }
  return;
}



===== TsUrbCompletion @ 140011290 =====

/* private: virtual void __cdecl CTsUrbCurrentFrame::TsUrbCompletion(unsigned char *
   __ptr64,unsigned long,void * __ptr64,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash
   * __ptr64) __ptr64 */

void __thiscall
CTsUrbCurrentFrame::TsUrbCompletion
          (CTsUrbCurrentFrame *this,uchar *param_1,ulong param_2,void *param_3,ulong param_4,
          CSimpleHash *param_5,CSimpleHash *param_6)

{
  longlong lVar1;
  
  UrbCompletion_JustStatus(*(_URB **)(this + 8),param_1,param_2,(ulong)param_3);
  lVar1 = *(longlong *)(this + 8);
  if (-1 < *(int *)(lVar1 + 4)) {
    if ((param_2 < 0xc) || (*(short *)param_1 != 0xc)) {
      *(undefined4 *)(lVar1 + 4) = 0x80000300;
    }
    else {
      *(undefined4 *)(lVar1 + 0x18) = *(undefined4 *)(param_1 + 8);
    }
  }
  return;
}



===== TsUrbCompletion @ 1400112e0 =====

/* private: virtual void __cdecl CTsUrbOsFeatureDescriptor::TsUrbCompletion(unsigned char *
   __ptr64,unsigned long,void * __ptr64,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash
   * __ptr64) __ptr64 */

void __thiscall
CTsUrbOsFeatureDescriptor::TsUrbCompletion
          (CTsUrbOsFeatureDescriptor *this,uchar *param_1,ulong param_2,void *param_3,ulong param_4,
          CSimpleHash *param_5,CSimpleHash *param_6)

{
  longlong lVar1;
  long lVar2;
  
  lVar2 = UrbCompletion_JustStatus(*(_URB **)(this + 8),param_1,param_2,(ulong)param_3);
  if (-1 < lVar2) {
    lVar1 = *(longlong *)(this + 8);
    if (*(uint *)(lVar1 + 0x24) < param_4) {
      *(undefined4 *)(lVar1 + 4) = 0x80000300;
    }
    else {
      *(ulong *)(lVar1 + 0x24) = param_4;
      if (param_3 != (void *)0x0) {
        memmove(*(void **)(this + 0x18),param_3,(ulonglong)param_4);
      }
    }
  }
  return;
}



===== TsUrbCompletion @ 140011330 =====

/* private: virtual void __cdecl CTsUrbIsochTransfer::TsUrbCompletion(unsigned char *
   __ptr64,unsigned long,void * __ptr64,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash
   * __ptr64) __ptr64 */

void __thiscall
CTsUrbIsochTransfer::TsUrbCompletion
          (CTsUrbIsochTransfer *this,uchar *param_1,ulong param_2,void *param_3,ulong param_4,
          CSimpleHash *param_5,CSimpleHash *param_6)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  ulong uVar5;
  
  UrbCompletion_JustStatus(*(_URB **)(this + 8),param_1,param_2,(ulong)param_3);
  lVar2 = *(longlong *)(this + 8);
  if (-1 < *(int *)(lVar2 + 4)) {
    if (0x13 < param_2) {
      uVar4 = (ulonglong)*(uint *)(param_1 + 0xc) * 0xc;
      if ((((uVar4 < 0x100000000) && (uVar3 = (int)uVar4 + 0x14, 0x13 < uVar3)) &&
          (uVar3 == *(ushort *)param_1)) && (uVar3 == param_2)) {
        if (*(uint *)(param_1 + 0xc) != *(uint *)(lVar2 + 0x84)) {
          return;
        }
        if (*(uint *)(lVar2 + 0x24) < param_4) {
          return;
        }
        *(undefined4 *)(lVar2 + 0x80) = *(undefined4 *)(param_1 + 8);
        *(undefined4 *)(lVar2 + 0x88) = *(undefined4 *)(param_1 + 0x10);
        memmove((void *)(lVar2 + 0x8c),param_1 + 0x14,(ulonglong)*(uint *)(param_1 + 0xc) * 0xc);
        if (((*(uint *)(lVar2 + 0x20) & 1) != 0) && (param_3 != (void *)0x0)) {
          uVar5 = param_4;
          for (uVar4 = 0; (uint)uVar4 < *(uint *)(lVar2 + 0x84);
              uVar4 = (ulonglong)((uint)uVar4 + 1)) {
            if ((-1 < *(int *)(param_1 + uVar4 * 0xc + 0x1c)) &&
               (uVar3 = *(uint *)(param_1 + uVar4 * 0xc + 0x18), uVar3 != 0)) {
              if (uVar5 < uVar3) {
                return;
              }
              uVar1 = *(uint *)(param_1 + uVar4 * 0xc + 0x14);
              if (*(uint *)(lVar2 + 0x24) < uVar1) {
                return;
              }
              if (uVar3 + uVar1 < uVar1) {
                *(undefined4 *)(*(longlong *)(this + 8) + 4) = 0x80000300;
                return;
              }
              if (*(uint *)(lVar2 + 0x24) < uVar3 + uVar1) {
                return;
              }
              memmove((void *)((ulonglong)uVar1 + *(longlong *)(this + 0x18)),param_3,
                      (ulonglong)uVar3);
              param_3 = (void *)((longlong)param_3 +
                                (ulonglong)*(uint *)(param_1 + uVar4 * 0xc + 0x18));
              uVar5 = uVar5 - *(uint *)(param_1 + uVar4 * 0xc + 0x18);
            }
          }
        }
        *(ulong *)(lVar2 + 0x24) = param_4;
        return;
      }
    }
    *(undefined4 *)(lVar2 + 4) = 0x80000300;
  }
  return;
}



===== TsUrbCompletion @ 1400114a0 =====

/* private: virtual void __cdecl CTsUrbSelectConfig::TsUrbCompletion(unsigned char *
   __ptr64,unsigned long,void * __ptr64,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash
   * __ptr64) __ptr64 */

void __thiscall
CTsUrbSelectConfig::TsUrbCompletion
          (CTsUrbSelectConfig *this,uchar *param_1,ulong param_2,void *param_3,ulong param_4,
          CSimpleHash *param_5,CSimpleHash *param_6)

{
  longlong lVar1;
  CTsUrbSelectConfig *pCVar2;
  int iVar3;
  longlong lVar4;
  CTsUrbSelectConfig *pCVar5;
  longlong lVar6;
  code *pcVar7;
  ushort uVar8;
  CSimpleHash *this_00;
  _TS_PIPE_INFORMATION *p_Var9;
  ulonglong uVar10;
  ushort *puVar11;
  ushort *puVar12;
  uint uVar13;
  uint uVar14;
  uint local_res8;
  uint local_48;
  
  UrbCompletion_JustStatus(*(_URB **)(this + 8),param_1,param_2,(ulong)param_3);
  lVar4 = *(longlong *)(this + 8);
  if (-1 < *(int *)(lVar4 + 4)) {
    if (0xf < param_2) {
      if (*(uint *)(param_1 + 0xc) == (uint)(byte)this[0x28]) {
        local_res8 = 0;
        puVar12 = (ushort *)(lVar4 + 0x28);
        puVar11 = (ushort *)(param_1 + 0x10);
        local_48 = param_2 - 0x10;
        if ((byte)this[0x28] == 0) {
          return;
        }
        do {
          uVar10 = 0;
          uVar14 = (uint)(((ulonglong)*puVar12 - 0x18) / 0x18);
          uVar13 = uVar14 * 0x14 + 0x10;
          if ((((local_48 < uVar13) || (*puVar11 != uVar13)) ||
              ((char)puVar12[1] != (char)puVar11[1])) ||
             ((*(char *)((longlong)puVar12 + 3) != *(char *)((longlong)puVar11 + 3) ||
              (uVar14 < *(uint *)(puVar11 + 6))))) {
LAB_140011709:
            *(undefined4 *)(*(longlong *)(this + 8) + 4) = 0x80000300;
            return;
          }
          *(ulonglong *)(lVar4 + 0x20) = (ulonglong)*(uint *)(param_1 + 8);
          *(ulonglong *)(puVar12 + 4) = (ulonglong)*(uint *)(puVar11 + 4);
          *(char *)(puVar12 + 2) = (char)puVar11[2];
          *(undefined1 *)((longlong)puVar12 + 5) = *(undefined1 *)((longlong)puVar11 + 5);
          *(char *)(puVar12 + 3) = (char)puVar11[3];
          iVar3 = *(int *)(puVar11 + 6);
          *(int *)(puVar12 + 8) = iVar3;
          if (iVar3 != 0) {
            do {
              lVar1 = uVar10 + 1;
              puVar12[lVar1 * 0xc] = puVar11[uVar10 * 10 + 8];
              uVar8 = puVar11[uVar10 * 10 + 9];
              *(char *)(puVar12 + lVar1 * 0xc + 1) = (char)uVar8;
              *(undefined1 *)((longlong)puVar12 + lVar1 * 0x18 + 3) =
                   *(undefined1 *)((longlong)puVar11 + uVar10 * 0x14 + 0x13);
              *(undefined4 *)(puVar12 + lVar1 * 0xc + 2) =
                   *(undefined4 *)(puVar11 + uVar10 * 10 + 10);
              uVar14 = *(uint *)(puVar11 + uVar10 * 10 + 0xc);
              *(void **)(puVar12 + lVar1 * 0xc + 4) = (void *)(ulonglong)uVar14;
              *(undefined4 *)(puVar12 + lVar1 * 0xc + 8) =
                   *(undefined4 *)(puVar11 + uVar10 * 10 + 0xe);
              *(undefined4 *)(puVar12 + lVar1 * 0xc + 10) =
                   *(undefined4 *)(puVar11 + uVar10 * 10 + 0x10);
              this_00 = param_5;
              if (-1 < (char)uVar8) {
                this_00 = param_6;
              }
              p_Var9 = CTsUrb::FindTsPipeInfoInPipeHandleTable(this_00,(void *)(ulonglong)uVar14);
              if (p_Var9 == (_TS_PIPE_INFORMATION *)0x0) {
                pCVar2 = this + 0x18;
                pCVar5 = *(CTsUrbSelectConfig **)pCVar2;
                if (pCVar5 == pCVar2) goto LAB_140011709;
                if ((*(CTsUrbSelectConfig **)(pCVar5 + 8) != pCVar2) ||
                   (lVar6 = *(longlong *)pCVar5, *(CTsUrbSelectConfig **)(lVar6 + 8) != pCVar5)) {
                  pcVar7 = (code *)swi(0x29);
                  (*pcVar7)(3);
                  goto LAB_140011709;
                }
                *(longlong *)pCVar2 = lVar6;
                *(CTsUrbSelectConfig **)(lVar6 + 8) = pCVar2;
                *(longlong *)pCVar5 = 0;
                *(longlong *)(pCVar5 + 8) = 0;
                *(longlong *)(pCVar5 + 0x10) = 0;
                *(longlong *)(pCVar5 + 0x18) = 0;
                *(longlong *)(pCVar5 + 0x20) = 0;
                pCVar5[0x20] = *(CTsUrbSelectConfig *)(puVar12 + 2);
                pCVar5[0x21] = *(CTsUrbSelectConfig *)((longlong)puVar12 + 5);
                lVar6 = *(longlong *)(puVar11 + uVar10 * 10 + 8 + 4);
                *(longlong *)pCVar5 = *(longlong *)(puVar11 + uVar10 * 10 + 8);
                *(longlong *)(pCVar5 + 8) = lVar6;
                *(undefined4 *)(pCVar5 + 0x10) = *(undefined4 *)(puVar11 + uVar10 * 10 + 0x10);
                pCVar5[0x25] = (CTsUrbSelectConfig)0x0;
                *(undefined2 *)(pCVar5 + 0x22) = 0;
                CSimpleHash::AddItemNoDuplicate(this_00,pCVar5,(ulong *)0x0);
                *(CTsUrbSelectConfig **)(puVar12 + lVar1 * 0xc + 4) = pCVar5;
              }
              uVar14 = (int)uVar10 + 1;
              uVar10 = (ulonglong)uVar14;
            } while (uVar14 < *(uint *)(puVar12 + 8));
          }
          puVar12 = (ushort *)((longlong)puVar12 + (ulonglong)*puVar12);
          puVar11 = (ushort *)((longlong)puVar11 + (ulonglong)uVar13);
          uVar10 = Feature_1741656378__private_IsEnabledDeviceUsageNoInline();
          local_res8 = local_res8 + 1;
          uVar13 = local_48 - uVar13;
          if ((int)uVar10 == 0) {
            uVar13 = local_48;
          }
          local_48 = uVar13;
          if ((byte)this[0x28] <= local_res8) {
            return;
          }
        } while( true );
      }
    }
    *(undefined4 *)(lVar4 + 4) = 0x80000300;
  }
  return;
}



===== TsUrbCompletion @ 140011750 =====

/* private: virtual void __cdecl CTsUrbSelectInterface::TsUrbCompletion(unsigned char *
   __ptr64,unsigned long,void * __ptr64,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash
   * __ptr64) __ptr64 */

void __thiscall
CTsUrbSelectInterface::TsUrbCompletion
          (CTsUrbSelectInterface *this,uchar *param_1,ulong param_2,void *param_3,ulong param_4,
          CSimpleHash *param_5,CSimpleHash *param_6)

{
  CTsUrbSelectInterface *pCVar1;
  uchar uVar2;
  uint uVar3;
  longlong lVar4;
  CTsUrbSelectInterface *pCVar5;
  longlong lVar6;
  code *pcVar7;
  ulonglong uVar8;
  _TS_PIPE_INFORMATION *p_Var9;
  CSimpleHash *this_00;
  uint uVar10;
  
  UrbCompletion_JustStatus(*(_URB **)(this + 8),param_1,param_2,(ulong)param_3);
  lVar4 = *(longlong *)(this + 8);
  if (-1 < *(int *)(lVar4 + 4)) {
    if (7 < param_2) {
      uVar3 = (uint)(((ulonglong)*(ushort *)(lVar4 + 0x20) - 0x18) / 0x18);
      uVar10 = uVar3 * 0x14 + 0x10;
      if ((((uVar10 <= param_2 - 8) && (*(ushort *)(param_1 + 8) == uVar10)) &&
          (*(uchar *)(lVar4 + 0x22) == param_1[10])) &&
         ((*(uchar *)(lVar4 + 0x23) == param_1[0xb] && (*(uint *)(param_1 + 0x14) <= uVar3)))) {
        uVar10 = 0;
        *(ulonglong *)(lVar4 + 0x28) = (ulonglong)*(uint *)(param_1 + 0x10);
        *(uchar *)(lVar4 + 0x24) = param_1[0xc];
        *(uchar *)(lVar4 + 0x25) = param_1[0xd];
        *(uchar *)(lVar4 + 0x26) = param_1[0xe];
        *(undefined4 *)(lVar4 + 0x30) = *(undefined4 *)(param_1 + 0x14);
        do {
          if (*(uint *)(lVar4 + 0x30) <= uVar10) {
            return;
          }
          uVar8 = (ulonglong)uVar10;
          *(undefined2 *)(lVar4 + 0x38 + uVar8 * 0x18) =
               *(undefined2 *)(param_1 + uVar8 * 0x14 + 0x18);
          uVar2 = param_1[uVar8 * 0x14 + 0x1a];
          *(uchar *)(lVar4 + 0x3a + uVar8 * 0x18) = uVar2;
          this_00 = param_5;
          if (-1 < (char)uVar2) {
            this_00 = param_6;
          }
          *(uchar *)(lVar4 + 0x3b + uVar8 * 0x18) = param_1[uVar8 * 0x14 + 0x1b];
          *(undefined4 *)(lVar4 + 0x3c + uVar8 * 0x18) =
               *(undefined4 *)(param_1 + uVar8 * 0x14 + 0x1c);
          uVar3 = *(uint *)(param_1 + uVar8 * 0x14 + 0x20);
          *(void **)(lVar4 + 0x40 + uVar8 * 0x18) = (void *)(ulonglong)uVar3;
          *(undefined4 *)(lVar4 + 0x48 + uVar8 * 0x18) =
               *(undefined4 *)(param_1 + uVar8 * 0x14 + 0x24);
          *(undefined4 *)(lVar4 + 0x4c + uVar8 * 0x18) =
               *(undefined4 *)(param_1 + uVar8 * 0x14 + 0x28);
          p_Var9 = CTsUrb::FindTsPipeInfoInPipeHandleTable(this_00,(void *)(ulonglong)uVar3);
          if (p_Var9 == (_TS_PIPE_INFORMATION *)0x0) {
            pCVar1 = this + 0x18;
            pCVar5 = *(CTsUrbSelectInterface **)pCVar1;
            if (pCVar5 == pCVar1) {
LAB_1400118ff:
              *(undefined4 *)(*(longlong *)(this + 8) + 4) = 0x80000300;
              return;
            }
            if ((*(CTsUrbSelectInterface **)(pCVar5 + 8) != pCVar1) ||
               (lVar6 = *(longlong *)pCVar5, *(CTsUrbSelectInterface **)(lVar6 + 8) != pCVar5)) {
              pcVar7 = (code *)swi(0x29);
              (*pcVar7)(3);
              goto LAB_1400118ff;
            }
            *(longlong *)pCVar1 = lVar6;
            *(CTsUrbSelectInterface **)(lVar6 + 8) = pCVar1;
            *(longlong *)pCVar5 = 0;
            *(longlong *)(pCVar5 + 8) = 0;
            *(longlong *)(pCVar5 + 0x10) = 0;
            *(longlong *)(pCVar5 + 0x18) = 0;
            *(longlong *)(pCVar5 + 0x20) = 0;
            pCVar5[0x20] = *(CTsUrbSelectInterface *)(lVar4 + 0x24);
            pCVar5[0x21] = *(CTsUrbSelectInterface *)(lVar4 + 0x25);
            lVar6 = *(longlong *)((longlong)(param_1 + uVar8 * 0x14 + 0x18) + 8);
            *(longlong *)pCVar5 = *(longlong *)(param_1 + uVar8 * 0x14 + 0x18);
            *(longlong *)(pCVar5 + 8) = lVar6;
            *(undefined4 *)(pCVar5 + 0x10) = *(undefined4 *)(param_1 + uVar8 * 0x14 + 0x28);
            pCVar5[0x25] = (CTsUrbSelectInterface)0x0;
            *(undefined2 *)(pCVar5 + 0x22) = 0;
            CSimpleHash::AddItemNoDuplicate(this_00,pCVar5,(ulong *)0x0);
            *(CTsUrbSelectInterface **)(lVar4 + 0x40 + uVar8 * 0x18) = pCVar5;
          }
          uVar10 = uVar10 + 1;
        } while( true );
      }
    }
    *(undefined4 *)(lVar4 + 4) = 0x80000300;
  }
  return;
}



===== TsUrbInitialize @ 140011930 =====

/* private: virtual void __cdecl CTsUrbBulkTransfer::TsUrbInitialize(unsigned long,unsigned char *
   __ptr64,unsigned short,void * __ptr64 * __ptr64,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbBulkTransfer::TsUrbInitialize
          (CTsUrbBulkTransfer *this,ulong param_1,uchar *param_2,ushort param_3,void **param_4,
          ulong *param_5)

{
  longlong lVar1;
  void *pvVar2;
  
  lVar1 = *(longlong *)(this + 8);
  if (0xf < param_3) {
    param_2[0] = '\x10';
    param_2[1] = '\0';
    *(uint *)(param_2 + 4) =
         (*(uint *)(param_2 + 4) ^ param_1) & 0x7fffffff ^ *(uint *)(param_2 + 4);
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(lVar1 + 2);
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(this + 0x20);
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(lVar1 + 0x20);
    if ((*(uint *)(lVar1 + 0x20) & 1) == 0) {
      pvVar2 = *(void **)(this + 0x18);
    }
    else {
      pvVar2 = (void *)0x0;
    }
    *param_4 = pvVar2;
    *param_5 = *(ulong *)(lVar1 + 0x24);
  }
  return;
}



===== TsUrbInitialize @ 1400119a0 =====

/* private: virtual void __cdecl CTsUrbClassRequest::TsUrbInitialize(unsigned long,unsigned char *
   __ptr64,unsigned short,void * __ptr64 * __ptr64,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbClassRequest::TsUrbInitialize
          (CTsUrbClassRequest *this,ulong param_1,uchar *param_2,ushort param_3,void **param_4,
          ulong *param_5)

{
  longlong lVar1;
  void *pvVar2;
  
  lVar1 = *(longlong *)(this + 8);
  if (0x13 < param_3) {
    param_2[0] = '\x14';
    param_2[1] = '\0';
    *(uint *)(param_2 + 4) =
         (*(uint *)(param_2 + 4) ^ param_1) & 0x7fffffff ^ *(uint *)(param_2 + 4);
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(lVar1 + 2);
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(lVar1 + 0x20);
    param_2[0xc] = *(uchar *)(lVar1 + 0x80);
    param_2[0xd] = *(uchar *)(lVar1 + 0x81);
    *(undefined2 *)(param_2 + 0xe) = *(undefined2 *)(lVar1 + 0x82);
    *(undefined2 *)(param_2 + 0x10) = *(undefined2 *)(lVar1 + 0x84);
    if ((*(uint *)(lVar1 + 0x20) & 1) == 0) {
      pvVar2 = *(void **)(this + 0x18);
    }
    else {
      pvVar2 = (void *)0x0;
    }
    *param_4 = pvVar2;
    *param_5 = *(ulong *)(lVar1 + 0x24);
  }
  return;
}



===== TsUrbInitialize @ 140011a40 =====

/* private: virtual void __cdecl CTsUrbControlDescriptor::TsUrbInitialize(unsigned long,unsigned
   char * __ptr64,unsigned short,void * __ptr64 * __ptr64,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbControlDescriptor::TsUrbInitialize
          (CTsUrbControlDescriptor *this,ulong param_1,uchar *param_2,ushort param_3,void **param_4,
          ulong *param_5)

{
  longlong lVar1;
  void *pvVar2;
  
  lVar1 = *(longlong *)(this + 8);
  if (0xb < param_3) {
    param_2[0] = '\f';
    param_2[1] = '\0';
    pvVar2 = (void *)0x0;
    *(uint *)(param_2 + 4) =
         (*(uint *)(param_2 + 4) ^ param_1) & 0x7fffffff ^ *(uint *)(param_2 + 4);
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(lVar1 + 2);
    param_2[8] = *(uchar *)(lVar1 + 0x82);
    param_2[9] = *(uchar *)(lVar1 + 0x83);
    *(undefined2 *)(param_2 + 10) = *(undefined2 *)(lVar1 + 0x84);
    if (this[0x20] == (CTsUrbControlDescriptor)0x0) {
      pvVar2 = *(void **)(this + 0x18);
    }
    *param_4 = pvVar2;
    *param_5 = *(ulong *)(lVar1 + 0x24);
  }
  return;
}



===== TsUrbInitialize @ 140011ac0 =====

/* private: virtual void __cdecl CTsUrbControlFeature::TsUrbInitialize(unsigned long,unsigned char *
   __ptr64,unsigned short,void * __ptr64 * __ptr64,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbControlFeature::TsUrbInitialize
          (CTsUrbControlFeature *this,ulong param_1,uchar *param_2,ushort param_3,void **param_4,
          ulong *param_5)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(this + 8);
  if (0xb < param_3) {
    param_2[0] = '\f';
    param_2[1] = '\0';
    *(uint *)(param_2 + 4) =
         (*(uint *)(param_2 + 4) ^ param_1) & 0x7fffffff ^ *(uint *)(param_2 + 4);
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(lVar1 + 2);
    *(undefined2 *)(param_2 + 8) = *(undefined2 *)(lVar1 + 0x82);
    *(undefined2 *)(param_2 + 10) = *(undefined2 *)(lVar1 + 0x84);
    *param_4 = (void *)0x0;
    *param_5 = 0;
  }
  return;
}



===== TsUrbInitialize @ 140011b30 =====

/* private: virtual void __cdecl CTsUrbControlTransfer::TsUrbInitialize(unsigned long,unsigned char
   * __ptr64,unsigned short,void * __ptr64 * __ptr64,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbControlTransfer::TsUrbInitialize
          (CTsUrbControlTransfer *this,ulong param_1,uchar *param_2,ushort param_3,void **param_4,
          ulong *param_5)

{
  longlong lVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  lVar1 = *(longlong *)(this + 8);
  if (0x17 < param_3) {
    param_2[0] = '\x18';
    param_2[1] = '\0';
    uVar2 = 0;
    pvVar3 = (void *)0x0;
    *(uint *)(param_2 + 4) =
         (*(uint *)(param_2 + 4) ^ param_1) & 0x7fffffff ^ *(uint *)(param_2 + 4);
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(lVar1 + 2);
    if ((*(uint *)(lVar1 + 0x20) & 8) == 0) {
      uVar2 = *(undefined4 *)(this + 0x20);
    }
    *(undefined4 *)(param_2 + 8) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(lVar1 + 0x20);
    *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(lVar1 + 0x80);
    if ((*(uint *)(lVar1 + 0x20) & 1) == 0) {
      pvVar3 = *(void **)(this + 0x18);
    }
    *param_4 = pvVar3;
    *param_5 = *(ulong *)(lVar1 + 0x24);
  }
  return;
}



===== TsUrbInitialize @ 140011bc0 =====

/* private: virtual void __cdecl CTsUrbControlTransferEx::TsUrbInitialize(unsigned long,unsigned
   char * __ptr64,unsigned short,void * __ptr64 * __ptr64,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbControlTransferEx::TsUrbInitialize
          (CTsUrbControlTransferEx *this,ulong param_1,uchar *param_2,ushort param_3,void **param_4,
          ulong *param_5)

{
  longlong lVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  lVar1 = *(longlong *)(this + 8);
  if (0x1b < param_3) {
    param_2[0] = '\x1c';
    param_2[1] = '\0';
    uVar2 = 0;
    pvVar3 = (void *)0x0;
    *(uint *)(param_2 + 4) =
         (*(uint *)(param_2 + 4) ^ param_1) & 0x7fffffff ^ *(uint *)(param_2 + 4);
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(lVar1 + 2);
    if ((*(uint *)(lVar1 + 0x20) & 8) == 0) {
      uVar2 = *(undefined4 *)(this + 0x20);
    }
    *(undefined4 *)(param_2 + 8) = uVar2;
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(lVar1 + 0x20);
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(lVar1 + 0x38);
    *(undefined8 *)(param_2 + 0x14) = *(undefined8 *)(lVar1 + 0x80);
    if ((*(uint *)(lVar1 + 0x20) & 1) == 0) {
      pvVar3 = *(void **)(this + 0x18);
    }
    *param_4 = pvVar3;
    *param_5 = *(ulong *)(lVar1 + 0x24);
  }
  return;
}



===== TsUrbInitialize @ 140011c50 =====

/* private: virtual void __cdecl CTsUrbCurrentFrame::TsUrbInitialize(unsigned long,unsigned char *
   __ptr64,unsigned short,void * __ptr64 * __ptr64,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbCurrentFrame::TsUrbInitialize
          (CTsUrbCurrentFrame *this,ulong param_1,uchar *param_2,ushort param_3,void **param_4,
          ulong *param_5)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(this + 8);
  if (7 < param_3) {
    param_2[0] = '\b';
    param_2[1] = '\0';
    *(uint *)(param_2 + 4) =
         (*(uint *)(param_2 + 4) ^ param_1) & 0x7fffffff ^ *(uint *)(param_2 + 4);
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(lVar1 + 2);
    *param_4 = (void *)0x0;
    *param_5 = 0;
  }
  return;
}



===== TsUrbInitialize @ 140011ca0 =====

/* private: virtual void __cdecl CTsUrbGetConfigRequest::TsUrbInitialize(unsigned long,unsigned char
   * __ptr64,unsigned short,void * __ptr64 * __ptr64,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbGetConfigRequest::TsUrbInitialize
          (CTsUrbGetConfigRequest *this,ulong param_1,uchar *param_2,ushort param_3,void **param_4,
          ulong *param_5)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(this + 8);
  if (7 < param_3) {
    param_2[0] = '\b';
    param_2[1] = '\0';
    *(uint *)(param_2 + 4) =
         (*(uint *)(param_2 + 4) ^ param_1) & 0x7fffffff ^ *(uint *)(param_2 + 4);
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(lVar1 + 2);
    *param_4 = (void *)0x0;
    *param_5 = *(ulong *)(lVar1 + 0x24);
  }
  return;
}



===== TsUrbInitialize @ 140011cf0 =====

/* private: virtual void __cdecl CTsUrbGetStatus::TsUrbInitialize(unsigned long,unsigned char *
   __ptr64,unsigned short,void * __ptr64 * __ptr64,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbGetStatus::TsUrbInitialize
          (CTsUrbGetStatus *this,ulong param_1,uchar *param_2,ushort param_3,void **param_4,
          ulong *param_5)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(this + 8);
  if (0xb < param_3) {
    param_2[0] = '\f';
    param_2[1] = '\0';
    *(uint *)(param_2 + 4) =
         (*(uint *)(param_2 + 4) ^ param_1) & 0x7fffffff ^ *(uint *)(param_2 + 4);
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(lVar1 + 2);
    *(undefined2 *)(param_2 + 8) = *(undefined2 *)(lVar1 + 0x84);
    *param_4 = (void *)0x0;
    *param_5 = *(ulong *)(lVar1 + 0x24);
  }
  return;
}



===== TsUrbInitialize @ 140011d50 =====

/* private: virtual void __cdecl CTsUrbIsochTransfer::TsUrbInitialize(unsigned long,unsigned char *
   __ptr64,unsigned short,void * __ptr64 * __ptr64,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbIsochTransfer::TsUrbInitialize
          (CTsUrbIsochTransfer *this,ulong param_1,uchar *param_2,ushort param_3,void **param_4,
          ulong *param_5)

{
  longlong lVar1;
  void *pvVar2;
  
  lVar1 = *(longlong *)(this + 8);
  if (*(int *)(lVar1 + 0x84) * 0xc + 0x1cU <= (uint)param_3) {
    *(undefined2 *)param_2 = *(undefined2 *)(this + 0x10);
    *(uint *)(param_2 + 4) =
         (*(uint *)(param_2 + 4) ^ param_1) & 0x7fffffff ^ *(uint *)(param_2 + 4);
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(lVar1 + 2);
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(lVar1 + 0x20);
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(lVar1 + 0x80);
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(this + 0x20);
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(lVar1 + 0x84);
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(lVar1 + 0x88);
    memmove(param_2 + 0x1c,(void *)(lVar1 + 0x8c),(ulonglong)*(uint *)(lVar1 + 0x84) * 0xc);
    if ((*(uint *)(lVar1 + 0x20) & 1) == 0) {
      pvVar2 = *(void **)(this + 0x18);
    }
    else {
      pvVar2 = (void *)0x0;
    }
    *param_4 = pvVar2;
    *param_5 = *(ulong *)(lVar1 + 0x24);
  }
  return;
}



===== TsUrbInitialize @ 140011e30 =====

/* private: virtual void __cdecl CTsUrbOsFeatureDescriptor::TsUrbInitialize(unsigned long,unsigned
   char * __ptr64,unsigned short,void * __ptr64 * __ptr64,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbOsFeatureDescriptor::TsUrbInitialize
          (CTsUrbOsFeatureDescriptor *this,ulong param_1,uchar *param_2,ushort param_3,
          void **param_4,ulong *param_5)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(this + 8);
  if (0xf < param_3) {
    param_2[0] = '\x10';
    param_2[1] = '\0';
    *(uint *)(param_2 + 4) =
         (*(uint *)(param_2 + 4) ^ param_1) & 0x7fffffff ^ *(uint *)(param_2 + 4);
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(lVar1 + 2);
    param_2[8] = (param_2[8] ^ *(byte *)(lVar1 + 0x80)) & 0x1f ^ param_2[8];
    param_2[9] = *(uchar *)(lVar1 + 0x82);
    param_2[10] = *(uchar *)(lVar1 + 0x83);
    *(undefined2 *)(param_2 + 0xc) = *(undefined2 *)(lVar1 + 0x84);
    *param_4 = (void *)0x0;
    *param_5 = *(ulong *)(lVar1 + 0x24);
  }
  return;
}



===== TsUrbInitialize @ 140011ec0 =====

/* private: virtual void __cdecl CTsUrbPipeRequest::TsUrbInitialize(unsigned long,unsigned char *
   __ptr64,unsigned short,void * __ptr64 * __ptr64,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbPipeRequest::TsUrbInitialize
          (CTsUrbPipeRequest *this,ulong param_1,uchar *param_2,ushort param_3,void **param_4,
          ulong *param_5)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(this + 8);
  if (0xb < param_3) {
    param_2[0] = '\f';
    param_2[1] = '\0';
    *(uint *)(param_2 + 4) =
         (*(uint *)(param_2 + 4) ^ param_1) & 0x7fffffff ^ *(uint *)(param_2 + 4);
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(lVar1 + 2);
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(this + 0x20);
    *param_4 = (void *)0x0;
    *param_5 = 0;
  }
  return;
}



===== TsUrbInitialize @ 140011f20 =====

/* private: virtual void __cdecl CTsUrbSelectConfig::TsUrbInitialize(unsigned long,unsigned char *
   __ptr64,unsigned short,void * __ptr64 * __ptr64,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbSelectConfig::TsUrbInitialize
          (CTsUrbSelectConfig *this,ulong param_1,uchar *param_2,ushort param_3,void **param_4,
          ulong *param_5)

{
  longlong lVar1;
  void *_Src;
  uint uVar2;
  uchar uVar3;
  uint uVar4;
  ushort *puVar5;
  ushort *_Dst;
  ulonglong uVar6;
  
  if (0xf < param_3) {
    lVar1 = *(longlong *)(this + 8);
    *(undefined2 *)param_2 = *(undefined2 *)(this + 0x10);
    _Dst = (ushort *)(param_2 + 0x10);
    *(uint *)(param_2 + 4) =
         (*(uint *)(param_2 + 4) ^ param_1) & 0x7fffffff ^ *(uint *)(param_2 + 4);
    puVar5 = (ushort *)(lVar1 + 0x28);
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(lVar1 + 2);
    *(uint *)(param_2 + 0xc) = (uint)(byte)this[0x28];
    uVar3 = '\x01';
    for (uVar4 = 0; uVar4 < (byte)this[0x28]; uVar4 = uVar4 + 1) {
      uVar2 = (*(int *)(puVar5 + 8) + 1) * 0xc;
      if (param_2 + param_3 < (uchar *)((ulonglong)uVar2 + (longlong)_Dst)) {
        return;
      }
      *_Dst = (ushort)uVar2;
      _Dst[1] = (ushort)(((ulonglong)*puVar5 - 0x18) / 0x18);
      *(char *)(_Dst + 2) = (char)puVar5[1];
      *(undefined1 *)((longlong)_Dst + 5) = *(undefined1 *)((longlong)puVar5 + 3);
      *(undefined4 *)(_Dst + 4) = *(undefined4 *)(puVar5 + 8);
      uVar6 = 0;
      if (*(int *)(puVar5 + 8) != 0) {
        do {
          _Dst[uVar6 * 6 + 6] = puVar5[uVar6 * 0xc + 0xc];
          uVar2 = (int)uVar6 + 1;
          *(undefined4 *)(_Dst + uVar6 * 6 + 8) = *(undefined4 *)(puVar5 + uVar6 * 0xc + 0x14);
          *(undefined4 *)(_Dst + uVar6 * 6 + 10) = *(undefined4 *)(puVar5 + uVar6 * 0xc + 0x16);
          uVar6 = (ulonglong)uVar2;
        } while (uVar2 < *(uint *)(puVar5 + 8));
      }
      puVar5 = (ushort *)((longlong)puVar5 + (ulonglong)*puVar5);
      _Dst = (ushort *)((longlong)_Dst + (ulonglong)*_Dst);
    }
    _Src = *(void **)(lVar1 + 0x18);
    if (_Src == (void *)0x0) {
      uVar3 = '\0';
    }
    else {
      if (param_2 + param_3 < (uchar *)((ulonglong)*(ushort *)((longlong)_Src + 2) + (longlong)_Dst)
         ) {
        return;
      }
      memmove(_Dst,_Src,(ulonglong)*(ushort *)((longlong)_Src + 2));
    }
    param_2[8] = uVar3;
    *param_4 = (void *)0x0;
    *param_5 = 0;
  }
  return;
}



===== TsUrbInitialize @ 1400120a0 =====

/* private: virtual void __cdecl CTsUrbSelectInterface::TsUrbInitialize(unsigned long,unsigned char
   * __ptr64,unsigned short,void * __ptr64 * __ptr64,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbSelectInterface::TsUrbInitialize
          (CTsUrbSelectInterface *this,ulong param_1,uchar *param_2,ushort param_3,void **param_4,
          ulong *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  longlong lVar3;
  uchar *puVar4;
  undefined4 *puVar5;
  ulonglong uVar6;
  
  lVar3 = *(longlong *)(this + 8);
  uVar1 = *(uint *)(lVar3 + 0x30);
  if ((uVar1 + 2) * 0xc <= (uint)param_3) {
    *(undefined2 *)param_2 = *(undefined2 *)(this + 0x10);
    *(uint *)(param_2 + 4) =
         (*(uint *)(param_2 + 4) ^ param_1) & 0x7fffffff ^ *(uint *)(param_2 + 4);
    *(undefined2 *)(param_2 + 2) = *(undefined2 *)(lVar3 + 2);
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(lVar3 + 0x18);
    *(short *)(param_2 + 0xc) = (*(short *)(lVar3 + 0x30) + 1) * 0xc;
    *(short *)(param_2 + 0xe) = (short)(((ulonglong)*(ushort *)(lVar3 + 0x20) - 0x18) / 0x18);
    param_2[0x10] = *(uchar *)(lVar3 + 0x22);
    param_2[0x11] = *(uchar *)(lVar3 + 0x23);
    *(uint *)(param_2 + 0x14) = uVar1;
    if (uVar1 != 0) {
      puVar4 = param_2 + 0x20;
      uVar6 = (ulonglong)uVar1;
      puVar5 = (undefined4 *)(lVar3 + 0x4c);
      do {
        *(undefined2 *)(puVar4 + -8) = *(undefined2 *)(puVar5 + -5);
        *(undefined4 *)(puVar4 + -4) = puVar5[-1];
        uVar2 = *puVar5;
        puVar5 = puVar5 + 6;
        *(undefined4 *)puVar4 = uVar2;
        puVar4 = puVar4 + 0xc;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    *param_4 = (void *)0x0;
    *param_5 = 0;
  }
  return;
}



===== UrbCompletion_JustStatus @ 140012194 =====

/* long __cdecl UrbCompletion_JustStatus(struct _URB * __ptr64,unsigned char * __ptr64,unsigned
   long,unsigned long) */

long __cdecl UrbCompletion_JustStatus(_URB *param_1,uchar *param_2,ulong param_3,ulong param_4)

{
  long lVar1;
  undefined4 uVar2;
  
  if ((param_3 < 8) || (param_3 != *(ushort *)param_2)) {
    lVar1 = -0x3ffffff3;
    uVar2 = 0x80000300;
  }
  else {
    lVar1 = 0;
    uVar2 = *(undefined4 *)(param_2 + 4);
  }
  *(undefined4 *)(param_1 + 4) = uVar2;
  return lVar1;
}



===== UrbFixupTransferFlags @ 1400121c8 =====

/* public: static void __cdecl CTsUrb::UrbFixupTransferFlags(void * __ptr64,class CSimpleHash *
   __ptr64,class CSimpleHash * __ptr64,unsigned long * __ptr64) */

void __cdecl
CTsUrb::UrbFixupTransferFlags
          (void *param_1,CSimpleHash *param_2,CSimpleHash *param_3,ulong *param_4)

{
  long lVar1;
  CSimpleHash *pCVar2;
  
  pCVar2 = param_3;
  lVar1 = CSimpleHash::FindItem(param_2,param_1,(ulong *)param_3);
  if (lVar1 < 0) {
    lVar1 = CSimpleHash::FindItem(param_3,param_1,(ulong *)pCVar2);
    if (-1 < lVar1) {
      *param_4 = *param_4 & 0xfffffffe;
    }
  }
  else {
    *param_4 = *param_4 | 1;
  }
  return;
}



===== UrbVerifyInterfaceInformation @ 140012210 =====

/* public: static long __cdecl CTsUrb::UrbVerifyInterfaceInformation(unsigned char *
   __ptr64,unsigned long) */

long __cdecl CTsUrb::UrbVerifyInterfaceInformation(uchar *param_1,ulong param_2)

{
  ushort uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  
  if (0x17 < param_2) {
    uVar1 = *(ushort *)param_1;
    if (uVar1 <= param_2) {
      uVar4 = ((ulonglong)uVar1 - 0x18) / 0x18;
      uVar3 = (ulonglong)*(uint *)(param_1 + 0x10);
      if (*(uint *)(param_1 + 0x10) <= (uint)uVar4) {
        uVar3 = uVar4 & 0xffffffff;
      }
      if ((0xffffffff < uVar3 * 0x18) || (uVar2 = (int)(uVar3 * 0x18) + 0x18, uVar2 < 0x18)) {
        return -0x3fffff6b;
      }
      if (uVar2 == uVar1) {
        return -(uint)(param_2 < uVar2) & 0xc000000d;
      }
      return -0x3ffffff3;
    }
  }
  return -0x3ffffff3;
}



===== DrCheckCurrentProcessForServiceSid @ 140012288 =====

/* int __cdecl DrCheckCurrentProcessForServiceSid(void * __ptr64) */

int __cdecl DrCheckCurrentProcessForServiceSid(void *param_1)

{
  int iVar1;
  uint uVar2;
  char local_res10 [24];
  
  local_res10[0] = '\0';
  iVar1 = RtlCheckTokenMembership(0,param_1,local_res10);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (uint)(local_res10[0] == '\x01');
  }
  return uVar2;
}



===== InitializeServiceSid @ 1400122cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl InitializeServiceSid(void * __ptr64,unsigned long * __ptr64 const) */

void __cdecl InitializeServiceSid(void *param_1,ulong *param_2)

{
  ulong uVar1;
  undefined4 *puVar2;
  ulong *puVar3;
  undefined1 auStack_38 [32];
  undefined4 local_18;
  undefined2 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_38;
  local_14 = 0x500;
  local_18 = 0;
  RtlInitializeSid(param_1,&local_18,6);
  puVar2 = (undefined4 *)RtlSubAuthoritySid(param_1,0);
  *puVar2 = 0x50;
  uVar1 = *param_2;
  puVar3 = (ulong *)RtlSubAuthoritySid(param_1,1);
  *puVar3 = uVar1;
  uVar1 = param_2[1];
  puVar3 = (ulong *)RtlSubAuthoritySid(param_1,2);
  *puVar3 = uVar1;
  uVar1 = param_2[2];
  puVar3 = (ulong *)RtlSubAuthoritySid(param_1,3);
  *puVar3 = uVar1;
  uVar1 = param_2[3];
  puVar3 = (ulong *)RtlSubAuthoritySid(param_1,4);
  *puVar3 = uVar1;
  uVar1 = param_2[4];
  puVar3 = (ulong *)RtlSubAuthoritySid(param_1,5);
  *puVar3 = uVar1;
  return;
}



===== IsCallerUsbRedirectionService @ 1400123c8 =====

/* int __cdecl IsCallerUsbRedirectionService(void) */

int __cdecl IsCallerUsbRedirectionService(void)

{
  undefined4 uVar1;
  int iVar2;
  void *pvVar3;
  ulong local_28 [8];
  
  local_28[0] = 0x7814c1fa;
  local_28[1] = 0x62bffacd;
  local_28[2] = 0xe553e9d8;
  local_28[3] = 0x36c5ce3f;
  local_28[4] = 0x932f1d58;
  uVar1 = RtlLengthRequiredSid(6);
  pvVar3 = (void *)ExAllocatePoolWithTag(0x200,uVar1,0x72447244);
  iVar2 = 0;
  if (pvVar3 != (void *)0x0) {
    InitializeServiceSid(pvVar3,local_28);
    iVar2 = DrCheckCurrentProcessForServiceSid(pvVar3);
    operator_delete(pvVar3);
  }
  return iVar2;
}



===== CImplIUnknown<IMessage> @ 14001245c =====

/* public: __cdecl CImplIUnknown<struct IMessage>::CImplIUnknown<struct IMessage>(void) __ptr64 */

CImplIUnknown<IMessage> * __thiscall
CImplIUnknown<IMessage>::CImplIUnknown<IMessage>(CImplIUnknown<IMessage> *this)

{
  *(undefined4 *)(this + 8) = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0xc001d00d;
  return this;
}



===== CImplIUnknown<IRIMObjManager> @ 140012484 =====

/* public: __cdecl CImplIUnknown<struct IRIMObjManager>::CImplIUnknown<struct IRIMObjManager>(void)
   __ptr64 */

CImplIUnknown<IRIMObjManager> * __thiscall
CImplIUnknown<IRIMObjManager>::CImplIUnknown<IRIMObjManager>(CImplIUnknown<IRIMObjManager> *this)

{
  *(undefined4 *)(this + 8) = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0xc001d00d;
  return this;
}



===== CImplIUnknown<IWTSVirtualChannelCallback> @ 1400124ac =====

/* public: __cdecl CImplIUnknown<struct IWTSVirtualChannelCallback>::CImplIUnknown<struct
   IWTSVirtualChannelCallback>(void) __ptr64 */

CImplIUnknown<IWTSVirtualChannelCallback> * __thiscall
CImplIUnknown<IWTSVirtualChannelCallback>::CImplIUnknown<IWTSVirtualChannelCallback>
          (CImplIUnknown<IWTSVirtualChannelCallback> *this)

{
  *(undefined4 *)(this + 8) = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0xc001d00d;
  return this;
}



===== CImplIUnknown<IWTSWriteCallback> @ 1400124d4 =====

/* public: __cdecl CImplIUnknown<struct IWTSWriteCallback>::CImplIUnknown<struct
   IWTSWriteCallback>(void) __ptr64 */

CImplIUnknown<IWTSWriteCallback> * __thiscall
CImplIUnknown<IWTSWriteCallback>::CImplIUnknown<IWTSWriteCallback>
          (CImplIUnknown<IWTSWriteCallback> *this)

{
  *(undefined4 *)(this + 8) = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0xc001d00d;
  return this;
}



===== CImplIUnknownPool<IMessage> @ 1400124fc =====

/* public: __cdecl CImplIUnknownPool<struct IMessage>::CImplIUnknownPool<struct IMessage>(void)
   __ptr64 */

CImplIUnknownPool<IMessage> * __thiscall
CImplIUnknownPool<IMessage>::CImplIUnknownPool<IMessage>(CImplIUnknownPool<IMessage> *this)

{
  CImplIUnknown<IMessage>::CImplIUnknown<IMessage>((CImplIUnknown<IMessage> *)this);
  *(undefined ***)(this + 0x18) = &_vftable__for__CRIMPooledUnknown__;
  *(undefined ***)this = &_vftable__for__CImplIUnknown<IMessage>__;
  *(undefined8 *)(this + 0x38) = 0;
  return this;
}



===== CImplIUnknownPool<IWTSWriteCallback> @ 140012530 =====

/* public: __cdecl CImplIUnknownPool<struct IWTSWriteCallback>::CImplIUnknownPool<struct
   IWTSWriteCallback>(void) __ptr64 */

CImplIUnknownPool<IWTSWriteCallback> * __thiscall
CImplIUnknownPool<IWTSWriteCallback>::CImplIUnknownPool<IWTSWriteCallback>
          (CImplIUnknownPool<IWTSWriteCallback> *this)

{
  CImplIUnknown<IWTSWriteCallback>::CImplIUnknown<IWTSWriteCallback>
            ((CImplIUnknown<IWTSWriteCallback> *)this);
  *(undefined ***)(this + 0x18) = &_vftable__for__CRIMPooledUnknown__;
  *(undefined ***)this = &_vftable__for__CImplIUnknown<IWTSWriteCallback>__;
  *(undefined8 *)(this + 0x38) = 0;
  return this;
}



===== SmartPtr<CRIMObjectPoolBase> @ 140012564 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: __cdecl SmartPtr<class CRIMObjectPoolBase>::SmartPtr<class CRIMObjectPoolBase>(class
   SmartPtr<class CRIMObjectPoolBase> & __ptr64) __ptr64 */

SmartPtr<CRIMObjectPoolBase> * __thiscall
SmartPtr<CRIMObjectPoolBase>::SmartPtr<CRIMObjectPoolBase>
          (SmartPtr<CRIMObjectPoolBase> *this,
          SmartPtr<class_CRIMObjectPool<class_CMessage>_> *param_1)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)param_1;
  *(longlong **)this = plVar1;
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 8))();
  }
  return this;
}



===== CMessage @ 140012594 =====

/* public: __cdecl CMessage::CMessage(class CRIMObjectPoolBase * __ptr64) __ptr64 */

CMessage * __thiscall CMessage::CMessage(CMessage *this,CRIMObjectPoolBase *param_1)

{
  CImplIUnknownPool<IMessage>::CImplIUnknownPool<IMessage>((CImplIUnknownPool<IMessage> *)this);
  *(undefined ***)(this + 0x18) = &_vftable__for__CRIMPooledUnknown__;
  *(undefined ***)this = &_vftable__for__CImplIUnknown<IMessage>__;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  *(undefined8 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x60) = 0xffffffff;
  *(undefined8 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 100) = 0;
  return this;
}



===== CRIMObjManager @ 1400125dc =====

/* public: __cdecl CRIMObjManager::CRIMObjManager(long (__cdecl*)(struct _GUID const &
   __ptr64,struct IRIMStream * __ptr64,struct IUnknown * __ptr64 * __ptr64),long (__cdecl*)(struct
   _GUID const & __ptr64,struct IUnknown * __ptr64,struct IRIMStub * __ptr64 * __ptr64),unsigned
   long,unsigned long) __ptr64 */

CRIMObjManager * __thiscall
CRIMObjManager::CRIMObjManager
          (CRIMObjManager *this,_func_long__GUID_ptr_IRIMStream_ptr_IUnknown_ptr_ptr *param_1,
          _func_long__GUID_ptr_IUnknown_ptr_IRIMStub_ptr_ptr *param_2,ulong param_3,ulong param_4)

{
  CImplIUnknown<IRIMObjManager>::CImplIUnknown<IRIMObjManager>
            ((CImplIUnknown<IRIMObjManager> *)this);
  *(undefined ***)this = &_vftable_;
  *(undefined8 *)(this + 0x18) = 0;
  *(undefined8 *)(this + 0x20) = 0;
  *(undefined8 *)(this + 0x28) = 0;
  *(undefined8 *)(this + 0x30) = 0;
  *(undefined8 *)(this + 0x38) = 0;
  *(undefined8 *)(this + 0x40) = 0;
  KernelResource::KernelResource((KernelResource *)(this + 0x48),"CRIMObjManager");
  *(undefined4 *)(this + 0xd8) = 0;
  *(code **)(this + 200) = GetInstanceOfStub;
  *(undefined8 *)(this + 0xdc) = 4;
  *(code **)(this + 0xd0) = GetInstanceOfProxy;
  CImplIUnknown<IWTSVirtualChannelCallback>::CImplIUnknown<IWTSVirtualChannelCallback>
            ((CImplIUnknown<IWTSVirtualChannelCallback> *)(this + 0xe8));
  *(undefined ***)(this + 0xe8) = &CRimChannel::_vftable_;
  *(undefined8 *)(this + 0x100) = 0;
  *(undefined8 *)(this + 0x108) = 0;
  KernelResource::KernelResource((KernelResource *)(this + 0x110),"RimChannel.Lock");
  *(undefined8 *)(this + 400) = 0;
  *(undefined8 *)(this + 0x198) = 0;
  *(undefined8 *)(this + 0x1a0) = 0;
  *(undefined4 *)(this + 0x1a8) = 0xffffffff;
  return this;
}



===== CRimWriteCallback @ 1400126bc =====

/* public: __cdecl CRimWriteCallback::CRimWriteCallback(class CRIMObjectPoolBase * __ptr64) __ptr64
    */

CRimWriteCallback * __thiscall
CRimWriteCallback::CRimWriteCallback(CRimWriteCallback *this,CRIMObjectPoolBase *param_1)

{
  CImplIUnknownPool<IWTSWriteCallback>::CImplIUnknownPool<IWTSWriteCallback>
            ((CImplIUnknownPool<IWTSWriteCallback> *)this);
  *(undefined ***)(this + 0x18) = &_vftable__for__CRIMPooledUnknown__;
  *(undefined ***)this = &_vftable__for__CImplIUnknown<IWTSWriteCallback>__;
  *(undefined8 *)(this + 0x40) = 0;
  *(undefined8 *)(this + 0x48) = 0;
  return this;
}



===== ~CImplIUnknownPool<IMessage> @ 1400126f4 =====

/* public: virtual __cdecl CImplIUnknownPool<struct IMessage>::~CImplIUnknownPool<struct
   IMessage>(void) __ptr64 */

void __thiscall
CImplIUnknownPool<IMessage>::~CImplIUnknownPool<IMessage>(CImplIUnknownPool<IMessage> *this)

{
  *(undefined ***)this = &_vftable__for__CImplIUnknown<IMessage>__;
  *(undefined ***)(this + 0x18) = &_vftable__for__CRIMPooledUnknown__;
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)(this + 0x38));
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)(this + 0x18) = &CRIMPooledUnknown::_vftable_;
  *(undefined ***)this = &CImplIUnknown<IMessage>::_vftable_;
  return;
}



===== ~CImplIUnknownPool<IUnknown> @ 140012744 =====

/* public: virtual __cdecl CImplIUnknownPool<struct IUnknown>::~CImplIUnknownPool<struct
   IUnknown>(void) __ptr64 */

void __thiscall
CImplIUnknownPool<IUnknown>::~CImplIUnknownPool<IUnknown>(CImplIUnknownPool<IUnknown> *this)

{
  *(undefined ***)this = &_vftable__for__CImplIUnknown<IUnknown>__;
  *(undefined ***)(this + 0x18) = &_vftable__for__CRIMPooledUnknown__;
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)(this + 0x38));
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)(this + 0x18) = &CRIMPooledUnknown::_vftable_;
  *(undefined ***)this = &CImplIUnknown<IUnknown>::_vftable_;
  return;
}



===== ~CImplIUnknownPool<IWTSWriteCallback> @ 140012794 =====

/* public: virtual __cdecl CImplIUnknownPool<struct IWTSWriteCallback>::~CImplIUnknownPool<struct
   IWTSWriteCallback>(void) __ptr64 */

void __thiscall
CImplIUnknownPool<IWTSWriteCallback>::~CImplIUnknownPool<IWTSWriteCallback>
          (CImplIUnknownPool<IWTSWriteCallback> *this)

{
  *(undefined ***)this = &_vftable__for__CImplIUnknown<IWTSWriteCallback>__;
  *(undefined ***)(this + 0x18) = &_vftable__for__CRIMPooledUnknown__;
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)(this + 0x38));
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)(this + 0x18) = &CRIMPooledUnknown::_vftable_;
  *(undefined ***)this = &CImplIUnknown<IWTSWriteCallback>::_vftable_;
  return;
}



===== ~CRIMObjectPool<CMemory> @ 1400127e4 =====

/* protected: virtual __cdecl CRIMObjectPool<class CMemory>::~CRIMObjectPool<class CMemory>(void)
   __ptr64 */

void __thiscall CRIMObjectPool<CMemory>::~CRIMObjectPool<CMemory>(CRIMObjectPool<CMemory> *this)

{
  *(undefined ***)this = &_vftable_;
  Terminate(this);
  KernelResource::~KernelResource((KernelResource *)(this + 0x48));
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &CImplIUnknown<IUnknown>::_vftable_;
  return;
}



===== ~CRIMObjectPool<CMessage> @ 140012824 =====

/* protected: virtual __cdecl CRIMObjectPool<class CMessage>::~CRIMObjectPool<class CMessage>(void)
   __ptr64 */

void __thiscall CRIMObjectPool<CMessage>::~CRIMObjectPool<CMessage>(CRIMObjectPool<CMessage> *this)

{
  *(undefined ***)this = &_vftable_;
  Terminate(this);
  KernelResource::~KernelResource((KernelResource *)(this + 0x48));
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &CImplIUnknown<IUnknown>::_vftable_;
  return;
}



===== ~CRIMObjectPool<CRimWriteCallback> @ 140012864 =====

/* protected: virtual __cdecl CRIMObjectPool<class CRimWriteCallback>::~CRIMObjectPool<class
   CRimWriteCallback>(void) __ptr64 */

void __thiscall
CRIMObjectPool<CRimWriteCallback>::~CRIMObjectPool<CRimWriteCallback>
          (CRIMObjectPool<CRimWriteCallback> *this)

{
  *(undefined ***)this = &_vftable_;
  Terminate(this);
  KernelResource::~KernelResource((KernelResource *)(this + 0x48));
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &CImplIUnknown<IUnknown>::_vftable_;
  return;
}



===== ~DynArray<CRIMObjManager::CObjectEntry,unsigned_long> @ 1400128a4 =====

/* public: __cdecl DynArray<class CRIMObjManager::CObjectEntry,unsigned long>::~DynArray<class
   CRIMObjManager::CObjectEntry,unsigned long>(void) __ptr64 */

void __thiscall
DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::
~DynArray<CRIMObjManager::CObjectEntry,unsigned_long>
          (DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *this)

{
  uint in_EDX;
  
  if (*(CObjectEntry **)(this + 8) != (CObjectEntry *)0x0) {
    CRIMObjManager::CObjectEntry::_vector_deleting_destructor_(*(CObjectEntry **)(this + 8),in_EDX);
  }
  return;
}



===== ~SmartPtr<CMessage> @ 1400128c4 =====

/* public: __cdecl SmartPtr<class CMessage>::~SmartPtr<class CMessage>(void) __ptr64 */

void __thiscall SmartPtr<CMessage>::~SmartPtr<CMessage>(SmartPtr<CMessage> *this)

{
  if (*(CImplIUnknownPool<IMessage> **)this != (CImplIUnknownPool<IMessage> *)0x0) {
    CImplIUnknownPool<IMessage>::Release(*(CImplIUnknownPool<IMessage> **)this);
  }
  return;
}



===== ~SmartPtr<CRIMObjManager> @ 1400128e4 =====

/* public: __cdecl SmartPtr<class CRIMObjManager>::~SmartPtr<class CRIMObjManager>(void) __ptr64 */

void __thiscall SmartPtr<CRIMObjManager>::~SmartPtr<CRIMObjManager>(SmartPtr<CRIMObjManager> *this)

{
  if (*(CImplIUnknown<IRIMObjManager> **)this != (CImplIUnknown<IRIMObjManager> *)0x0) {
    CImplIUnknown<IRIMObjManager>::Release(*(CImplIUnknown<IRIMObjManager> **)this);
  }
  return;
}



===== ~SmartPtr<CRimChannel> @ 140012904 =====

/* public: __cdecl SmartPtr<class CRimChannel>::~SmartPtr<class CRimChannel>(void) __ptr64 */

void __thiscall SmartPtr<CRimChannel>::~SmartPtr<CRimChannel>(SmartPtr<CRimChannel> *this)

{
  if (*(longlong *)this != 0) {
    CImplIUnknown<IRIMObjManager>::Release
              (*(CImplIUnknown<IRIMObjManager> **)(*(longlong *)this + 0x20));
  }
  return;
}



===== ~CMemory @ 140012928 =====

/* public: virtual __cdecl CMemory::~CMemory(void) __ptr64 */

void __thiscall CMemory::~CMemory(CMemory *this)

{
  *(undefined ***)this = &_vftable__for__CImplIUnknown<IUnknown>__;
  *(undefined ***)(this + 0x18) = &_vftable__for__CRIMPooledUnknown__;
  operator_delete(*(void **)(this + 0x50));
  CImplIUnknownPool<IUnknown>::~CImplIUnknownPool<IUnknown>((CImplIUnknownPool<IUnknown> *)this);
  return;
}



===== ~CObjectEntry @ 140012964 =====

/* public: __cdecl CRIMObjManager::CObjectEntry::~CObjectEntry(void) __ptr64 */

void __thiscall CRIMObjManager::CObjectEntry::~CObjectEntry(CObjectEntry *this)

{
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)(this + 0x10));
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)(this + 8));
  return;
}



===== ~CRIMObjManager @ 14001298c =====

/* public: virtual __cdecl CRIMObjManager::~CRIMObjManager(void) __ptr64 */

void __thiscall CRIMObjManager::~CRIMObjManager(CRIMObjManager *this)

{
  CRIMObjectPool<CMemory> *this_00;
  CRIMObjectPool<CMessage> *this_01;
  
  *(undefined ***)this = &_vftable_;
  this_00 = *(CRIMObjectPool<CMemory> **)(this + 0x198);
  if (this_00 != (CRIMObjectPool<CMemory> *)0x0) {
    CRIMObjectPool<CMemory>::Terminate(this_00);
  }
  this_01 = *(CRIMObjectPool<CMessage> **)(this + 0x1a0);
  if (this_01 != (CRIMObjectPool<CMessage> *)0x0) {
    CRIMObjectPool<CMessage>::Terminate(this_01);
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)(this + 0x1a0));
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)(this + 0x198));
  CRimChannel::~CRimChannel((CRimChannel *)(this + 0xe8));
  KernelResource::~KernelResource((KernelResource *)(this + 0x48));
  DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::
  ~DynArray<CRIMObjManager::CObjectEntry,unsigned_long>
            ((DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *)(this + 0x38));
  DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::
  ~DynArray<CRIMObjManager::CObjectEntry,unsigned_long>
            ((DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *)(this + 0x28));
  DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::
  ~DynArray<CRIMObjManager::CObjectEntry,unsigned_long>
            ((DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *)(this + 0x18));
  *(undefined ***)this = &CImplIUnknown<IRIMObjManager>::_vftable_;
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  return;
}



===== ~CRimChannel @ 140012a38 =====

/* public: virtual __cdecl CRimChannel::~CRimChannel(void) __ptr64 */

void __thiscall CRimChannel::~CRimChannel(CRimChannel *this)

{
  CRIMObjectPool<CRimWriteCallback> *this_00;
  
  *(undefined ***)this = &_vftable_;
  this_00 = *(CRIMObjectPool<CRimWriteCallback> **)(this + 0xa8);
  if (this_00 != (CRIMObjectPool<CRimWriteCallback> *)0x0) {
    CRIMObjectPool<CRimWriteCallback>::Terminate(this_00);
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)(this + 0xa8));
  KernelResource::~KernelResource((KernelResource *)(this + 0x28));
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)(this + 0x18));
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &CImplIUnknown<IWTSVirtualChannelCallback>::_vftable_;
  return;
}



===== ~CRimWriteCallback @ 140012aa0 =====

/* public: virtual __cdecl CRimWriteCallback::~CRimWriteCallback(void) __ptr64 */

void __thiscall CRimWriteCallback::~CRimWriteCallback(CRimWriteCallback *this)

{
  SmartPtr<CRimChannel>::~SmartPtr<CRimChannel>((SmartPtr<CRimChannel> *)(this + 0x48));
  SmartPtr<CMessage>::~SmartPtr<CMessage>((SmartPtr<CMessage> *)(this + 0x40));
  CImplIUnknownPool<IWTSWriteCallback>::~CImplIUnknownPool<IWTSWriteCallback>
            ((CImplIUnknownPool<IWTSWriteCallback> *)this);
  return;
}



===== operator= @ 140012ad0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: class SmartPtr<struct IWTSVirtualChannel> & __ptr64 __cdecl SmartPtr<struct
   IWTSVirtualChannel>::operator=(struct IWTSVirtualChannel * __ptr64) __ptr64 */

SmartPtr<struct_IWTSVirtualChannel> * __thiscall
SmartPtr<IWTSVirtualChannel>::operator=
          (SmartPtr<IWTSVirtualChannel> *this,IWTSVirtualChannel *param_1)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)this;
  *(IWTSVirtualChannel **)this = param_1;
  if (param_1 != (IWTSVirtualChannel *)0x0) {
    (**(code **)(*(longlong *)param_1 + 8))(param_1);
  }
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x10))(plVar1);
  }
  return (SmartPtr<struct_IWTSVirtualChannel> *)this;
}



===== operator= @ 140012b20 =====

/* public: class SmartPtr<class CMemory> & __ptr64 __cdecl SmartPtr<class CMemory>::operator=(class
   CMemory * __ptr64) __ptr64 */

SmartPtr<class_CMemory> * __thiscall
SmartPtr<CMemory>::operator=(SmartPtr<CMemory> *this,CMemory *param_1)

{
  CImplIUnknownPool<IMessage> *this_00;
  
  this_00 = *(CImplIUnknownPool<IMessage> **)this;
  *(CMemory **)this = param_1;
  if (param_1 != (CMemory *)0x0) {
    LOCK();
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    UNLOCK();
  }
  if (this_00 != (CImplIUnknownPool<IMessage> *)0x0) {
    CImplIUnknownPool<IMessage>::Release(this_00);
  }
  return (SmartPtr<class_CMemory> *)this;
}



===== operator= @ 140012b54 =====

/* public: class SmartPtr<class CRimChannel> & __ptr64 __cdecl SmartPtr<class
   CRimChannel>::operator=(class CRimChannel * __ptr64) __ptr64 */

SmartPtr<class_CRimChannel> * __thiscall
SmartPtr<CRimChannel>::operator=(SmartPtr<CRimChannel> *this,CRimChannel *param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)this;
  *(CRimChannel **)this = param_1;
  if (param_1 != (CRimChannel *)0x0) {
    LOCK();
    *(int *)(*(longlong *)(param_1 + 0x20) + 0xc) =
         *(int *)(*(longlong *)(param_1 + 0x20) + 0xc) + 1;
    UNLOCK();
  }
  if (lVar1 != 0) {
    CImplIUnknown<IRIMObjManager>::Release(*(CImplIUnknown<IRIMObjManager> **)(lVar1 + 0x20));
  }
  return (SmartPtr<class_CRimChannel> *)this;
}



===== `vector_deleting_destructor'`adjustor{24}' @ 140012b90 =====

/* [thunk]:public: virtual void * __ptr64 __cdecl CImplIUnknownPool<struct IMessage>::`vector
   deleting destructor'`adjustor{24}' (unsigned int) __ptr64 */

void * __thiscall
CImplIUnknownPool<IMessage>::_vector_deleting_destructor__adjustor_24__
          (CImplIUnknownPool<IMessage> *this,uint param_1)

{
  void *pvVar1;
  
  pvVar1 = _vector_deleting_destructor_(this + -0x18,param_1);
  return pvVar1;
}



===== `vector_deleting_destructor'`adjustor{24}' @ 140012ba0 =====

/* [thunk]:public: virtual void * __ptr64 __cdecl CImplIUnknownPool<struct IUnknown>::`vector
   deleting destructor'`adjustor{24}' (unsigned int) __ptr64 */

void * __thiscall
CImplIUnknownPool<IUnknown>::_vector_deleting_destructor__adjustor_24__
          (CImplIUnknownPool<IUnknown> *this,uint param_1)

{
  void *pvVar1;
  
  pvVar1 = _vector_deleting_destructor_(this + -0x18,param_1);
  return pvVar1;
}



===== `vector_deleting_destructor'`adjustor{24}' @ 140012bb0 =====

/* [thunk]:public: virtual void * __ptr64 __cdecl CImplIUnknownPool<struct
   IWTSWriteCallback>::`vector deleting destructor'`adjustor{24}' (unsigned int) __ptr64 */

void * __thiscall
CImplIUnknownPool<IWTSWriteCallback>::_vector_deleting_destructor__adjustor_24__
          (CImplIUnknownPool<IWTSWriteCallback> *this,uint param_1)

{
  void *pvVar1;
  
  pvVar1 = _vector_deleting_destructor_(this + -0x18,param_1);
  return pvVar1;
}



===== `vector_deleting_destructor'`adjustor{24}' @ 140012bc0 =====

/* [thunk]:public: virtual void * __ptr64 __cdecl CMemory::`vector deleting
   destructor'`adjustor{24}' (unsigned int) __ptr64 */

void * __thiscall CMemory::_vector_deleting_destructor__adjustor_24__(CMemory *this,uint param_1)

{
  void *pvVar1;
  
  pvVar1 = _vector_deleting_destructor_(this + -0x18,param_1);
  return pvVar1;
}



===== `vector_deleting_destructor'`adjustor{24}' @ 140012bd0 =====

/* [thunk]:public: virtual void * __ptr64 __cdecl CMessage::`vector deleting
   destructor'`adjustor{24}' (unsigned int) __ptr64 */

void * __thiscall CMessage::_vector_deleting_destructor__adjustor_24__(CMessage *this,uint param_1)

{
  void *pvVar1;
  
  pvVar1 = _vector_deleting_destructor_(this + -0x18,param_1);
  return pvVar1;
}



===== `vector_deleting_destructor' @ 140012be0 =====

/* public: void * __ptr64 __cdecl CRIMObjManager::CObjectEntry::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CRIMObjManager::CObjectEntry::_vector_deleting_destructor_(CObjectEntry *this,uint param_1)

{
  CObjectEntry *pCVar1;
  longlong lVar2;
  CObjectEntry *this_00;
  
  pCVar1 = this + -8;
  lVar2 = *(longlong *)pCVar1;
  this_00 = this + lVar2 * 0x28;
  for (; lVar2 != 0; lVar2 = lVar2 + -1) {
    this_00 = this_00 + -0x28;
    ~CObjectEntry(this_00);
  }
  operator_delete(pCVar1);
  return pCVar1;
}



===== `vector_deleting_destructor'`adjustor{24}' @ 140012c40 =====

/* [thunk]:public: virtual void * __ptr64 __cdecl CRimWriteCallback::`vector deleting
   destructor'`adjustor{24}' (unsigned int) __ptr64 */

void * __thiscall
CRimWriteCallback::_vector_deleting_destructor__adjustor_24__(CRimWriteCallback *this,uint param_1)

{
  void *pvVar1;
  
  pvVar1 = _scalar_deleting_destructor_(this + -0x18,param_1);
  return pvVar1;
}



===== `scalar_deleting_destructor' @ 140012c50 =====

/* public: virtual void * __ptr64 __cdecl CImplIUnknown<struct IMessage>::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CImplIUnknown<IMessage>::_scalar_deleting_destructor_(CImplIUnknown<IMessage> *this,uint param_1)

{
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `vector_deleting_destructor' @ 140012c90 =====

/* public: virtual void * __ptr64 __cdecl CImplIUnknown<struct IRIMObjManager>::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CImplIUnknown<IRIMObjManager>::_vector_deleting_destructor_
          (CImplIUnknown<IRIMObjManager> *this,uint param_1)

{
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `vector_deleting_destructor' @ 140012cd0 =====

/* public: virtual void * __ptr64 __cdecl CImplIUnknown<struct IUnknown>::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CImplIUnknown<IUnknown>::_vector_deleting_destructor_(CImplIUnknown<IUnknown> *this,uint param_1)

{
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `vector_deleting_destructor' @ 140012d10 =====

/* public: virtual void * __ptr64 __cdecl CImplIUnknown<struct IWTSVirtualChannelCallback>::`vector
   deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
CImplIUnknown<IWTSVirtualChannelCallback>::_vector_deleting_destructor_
          (CImplIUnknown<IWTSVirtualChannelCallback> *this,uint param_1)

{
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140012d50 =====

/* public: virtual void * __ptr64 __cdecl CImplIUnknown<struct IWTSWriteCallback>::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CImplIUnknown<IWTSWriteCallback>::_scalar_deleting_destructor_
          (CImplIUnknown<IWTSWriteCallback> *this,uint param_1)

{
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `vector_deleting_destructor' @ 140012d90 =====

/* public: virtual void * __ptr64 __cdecl CImplIUnknownPool<struct IMessage>::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CImplIUnknownPool<IMessage>::_vector_deleting_destructor_
          (CImplIUnknownPool<IMessage> *this,uint param_1)

{
  ~CImplIUnknownPool<IMessage>(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `vector_deleting_destructor' @ 140012de0 =====

/* public: virtual void * __ptr64 __cdecl CImplIUnknownPool<struct IUnknown>::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CImplIUnknownPool<IUnknown>::_vector_deleting_destructor_
          (CImplIUnknownPool<IUnknown> *this,uint param_1)

{
  ~CImplIUnknownPool<IUnknown>(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `vector_deleting_destructor' @ 140012e30 =====

/* public: virtual void * __ptr64 __cdecl CImplIUnknownPool<struct IWTSWriteCallback>::`vector
   deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
CImplIUnknownPool<IWTSWriteCallback>::_vector_deleting_destructor_
          (CImplIUnknownPool<IWTSWriteCallback> *this,uint param_1)

{
  ~CImplIUnknownPool<IWTSWriteCallback>(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `vector_deleting_destructor' @ 140012e80 =====

/* protected: virtual void * __ptr64 __cdecl CRIMObjectPool<class CMemory>::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CRIMObjectPool<CMemory>::_vector_deleting_destructor_(CRIMObjectPool<CMemory> *this,uint param_1)

{
  ~CRIMObjectPool<CMemory>(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140012ed0 =====

/* protected: virtual void * __ptr64 __cdecl CRIMObjectPool<class CMessage>::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CRIMObjectPool<CMessage>::_scalar_deleting_destructor_(CRIMObjectPool<CMessage> *this,uint param_1)

{
  ~CRIMObjectPool<CMessage>(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140012f20 =====

/* protected: virtual void * __ptr64 __cdecl CRIMObjectPool<class CRimWriteCallback>::`scalar
   deleting destructor'(unsigned int) __ptr64 */

void * __thiscall
CRIMObjectPool<CRimWriteCallback>::_scalar_deleting_destructor_
          (CRIMObjectPool<CRimWriteCallback> *this,uint param_1)

{
  ~CRIMObjectPool<CRimWriteCallback>(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `vector_deleting_destructor' @ 140012f70 =====

/* public: virtual void * __ptr64 __cdecl CMemory::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall CMemory::_vector_deleting_destructor_(CMemory *this,uint param_1)

{
  ~CMemory(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `vector_deleting_destructor' @ 140012fc0 =====

/* public: virtual void * __ptr64 __cdecl CMessage::`vector deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall CMessage::_vector_deleting_destructor_(CMessage *this,uint param_1)

{
  ~CMessage(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140013010 =====

/* public: virtual void * __ptr64 __cdecl CRIMObjManager::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall CRIMObjManager::_scalar_deleting_destructor_(CRIMObjManager *this,uint param_1)

{
  ~CRIMObjManager(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140013060 =====

/* public: virtual void * __ptr64 __cdecl CRIMPooledUnknown::`scalar deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall
CRIMPooledUnknown::_scalar_deleting_destructor_(CRIMPooledUnknown *this,uint param_1)

{
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140013090 =====

/* public: virtual void * __ptr64 __cdecl CRimChannel::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall CRimChannel::_scalar_deleting_destructor_(CRimChannel *this,uint param_1)

{
  ~CRimChannel(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 1400130e0 =====

/* public: virtual void * __ptr64 __cdecl CRimWriteCallback::`scalar deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall
CRimWriteCallback::_scalar_deleting_destructor_(CRimWriteCallback *this,uint param_1)

{
  ~CRimWriteCallback(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== AddRef @ 140013130 =====

/* public: virtual unsigned long __cdecl CRimChannel::AddRef(void) __ptr64 */

ulong __thiscall CRimChannel::AddRef(CRimChannel *this)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(*(longlong *)(this + 0x20) + 0xc);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  return iVar2 + 1;
}



===== CreateInstance @ 140013148 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl CRIMObjectPool<class CMemory>::CreateInstance(unsigned int,class
   CRIMObjectPool<class CMemory> * __ptr64 * __ptr64) */

long __cdecl
CRIMObjectPool<CMemory>::CreateInstance(uint param_1,CRIMObjectPool<class_CMemory> **param_2)

{
  CRIMObjectPool<CMemory> *pCVar1;
  long lVar2;
  CRIMObjectPool<CMemory> *this;
  CRIMObjectPool<CMemory> *local_res18 [2];
  
  this = (CRIMObjectPool<CMemory> *)ExAllocatePoolWithTag(0x200,200,0x6c6d6952);
  if (this == (CRIMObjectPool<CMemory> *)0x0) {
    local_res18[0] = (CRIMObjectPool<CMemory> *)0x0;
    lVar2 = -0x7ff8fff2;
  }
  else {
    *(undefined4 *)(this + 8) = 0;
    *(undefined4 *)(this + 0x1c) = 0;
    *(undefined ***)this = &CImplIUnknown<IUnknown>::_vftable_;
    *(undefined4 *)(this + 0xc) = 0;
    *(undefined ***)this = &_vftable_;
    *(undefined4 *)(this + 0x18) = 0x10;
    *(undefined4 *)(this + 0x20) = 0x10;
    *(undefined4 *)(this + 0x10) = 0xc001d00d;
    KernelResource::KernelResource((KernelResource *)(this + 0x48),"CRIMObjectPool");
    pCVar1 = this + 0x28;
    *(CRIMObjectPool<CMemory> **)(this + 0x30) = pCVar1;
    *(CRIMObjectPool<CMemory> **)pCVar1 = pCVar1;
    pCVar1 = this + 0x38;
    *(CRIMObjectPool<CMemory> **)(this + 0x40) = pCVar1;
    *(CRIMObjectPool<CMemory> **)pCVar1 = pCVar1;
    local_res18[0] = this;
    (**(code **)(*(longlong *)this + 8))(this);
    lVar2 = Initialize(this);
    if (-1 < lVar2) {
      *param_2 = (CRIMObjectPool<class_CMemory> *)this;
      (**(code **)(*(longlong *)this + 8))(this);
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)local_res18);
  return lVar2;
}



===== CreateInstance @ 140013244 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl CRIMObjectPool<class CMessage>::CreateInstance(unsigned int,class
   CRIMObjectPool<class CMessage> * __ptr64 * __ptr64) */

long __cdecl
CRIMObjectPool<CMessage>::CreateInstance(uint param_1,CRIMObjectPool<class_CMessage> **param_2)

{
  CRIMObjectPool<CMessage> *pCVar1;
  long lVar2;
  CRIMObjectPool<CMessage> *this;
  CRIMObjectPool<CMessage> *local_res18 [2];
  
  this = (CRIMObjectPool<CMessage> *)ExAllocatePoolWithTag(0x200,200,0x6c6d6952);
  if (this == (CRIMObjectPool<CMessage> *)0x0) {
    local_res18[0] = (CRIMObjectPool<CMessage> *)0x0;
    lVar2 = -0x7ff8fff2;
  }
  else {
    *(undefined4 *)(this + 8) = 0;
    *(undefined4 *)(this + 0x1c) = 0;
    *(undefined ***)this = &CImplIUnknown<IUnknown>::_vftable_;
    *(undefined4 *)(this + 0xc) = 0;
    *(undefined ***)this = &_vftable_;
    *(undefined4 *)(this + 0x18) = 0x10;
    *(undefined4 *)(this + 0x20) = 0x10;
    *(undefined4 *)(this + 0x10) = 0xc001d00d;
    KernelResource::KernelResource((KernelResource *)(this + 0x48),"CRIMObjectPool");
    pCVar1 = this + 0x28;
    *(CRIMObjectPool<CMessage> **)(this + 0x30) = pCVar1;
    *(CRIMObjectPool<CMessage> **)pCVar1 = pCVar1;
    pCVar1 = this + 0x38;
    *(CRIMObjectPool<CMessage> **)(this + 0x40) = pCVar1;
    *(CRIMObjectPool<CMessage> **)pCVar1 = pCVar1;
    local_res18[0] = this;
    (**(code **)(*(longlong *)this + 8))(this);
    lVar2 = Initialize(this);
    if (-1 < lVar2) {
      *param_2 = (CRIMObjectPool<class_CMessage> *)this;
      (**(code **)(*(longlong *)this + 8))(this);
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)local_res18);
  return lVar2;
}



===== CreateInstance @ 140013340 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl CRIMObjectPool<class CRimWriteCallback>::CreateInstance(unsigned
   int,class CRIMObjectPool<class CRimWriteCallback> * __ptr64 * __ptr64) */

long __cdecl
CRIMObjectPool<CRimWriteCallback>::CreateInstance
          (uint param_1,CRIMObjectPool<class_CRimWriteCallback> **param_2)

{
  CRIMObjectPool<CRimWriteCallback> *pCVar1;
  long lVar2;
  CRIMObjectPool<CRimWriteCallback> *this;
  CRIMObjectPool<CRimWriteCallback> *local_res18 [2];
  
  this = (CRIMObjectPool<CRimWriteCallback> *)ExAllocatePoolWithTag(0x200,200,0x6c6d6952);
  if (this == (CRIMObjectPool<CRimWriteCallback> *)0x0) {
    local_res18[0] = (CRIMObjectPool<CRimWriteCallback> *)0x0;
    lVar2 = -0x7ff8fff2;
  }
  else {
    *(undefined4 *)(this + 8) = 0;
    *(undefined4 *)(this + 0x1c) = 0;
    *(undefined ***)this = &CImplIUnknown<IUnknown>::_vftable_;
    *(undefined4 *)(this + 0xc) = 0;
    *(undefined ***)this = &_vftable_;
    *(undefined4 *)(this + 0x18) = 0x10;
    *(undefined4 *)(this + 0x20) = 0x10;
    *(undefined4 *)(this + 0x10) = 0xc001d00d;
    KernelResource::KernelResource((KernelResource *)(this + 0x48),"CRIMObjectPool");
    pCVar1 = this + 0x28;
    *(CRIMObjectPool<CRimWriteCallback> **)(this + 0x30) = pCVar1;
    *(CRIMObjectPool<CRimWriteCallback> **)pCVar1 = pCVar1;
    pCVar1 = this + 0x38;
    *(CRIMObjectPool<CRimWriteCallback> **)(this + 0x40) = pCVar1;
    *(CRIMObjectPool<CRimWriteCallback> **)pCVar1 = pCVar1;
    local_res18[0] = this;
    (**(code **)(*(longlong *)this + 8))(this);
    lVar2 = Initialize(this);
    if (-1 < lVar2) {
      *param_2 = (CRIMObjectPool<class_CRimWriteCallback> *)this;
      (**(code **)(*(longlong *)this + 8))(this);
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)local_res18);
  return lVar2;
}



===== GetChannelCallback @ 140013440 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CRIMObjManager::GetChannelCallback(struct IWTSVirtualChannelCallback
   * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CRIMObjManager::GetChannelCallback(CRIMObjManager *this,IWTSVirtualChannelCallback **param_1)

{
  *param_1 = (IWTSVirtualChannelCallback *)(this + 0xe8);
  (**(code **)(*(longlong *)(this + 0xe8) + 8))();
  return 0;
}



===== GetInstanceOfObjectManager @ 140013468 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl GetInstanceOfObjectManager(long (__cdecl*)(struct _GUID const & __ptr64,struct
   IRIMStream * __ptr64,struct IUnknown * __ptr64 * __ptr64),long (__cdecl*)(struct _GUID const &
   __ptr64,struct IUnknown * __ptr64,struct IRIMStub * __ptr64 * __ptr64),struct IRIMObjManager *
   __ptr64 * __ptr64,unsigned long,unsigned long) */

long __cdecl
GetInstanceOfObjectManager
          (_func_long__GUID_ptr_IRIMStream_ptr_IUnknown_ptr_ptr *param_1,
          _func_long__GUID_ptr_IUnknown_ptr_IRIMStub_ptr_ptr *param_2,IRIMObjManager **param_3,
          ulong param_4,ulong param_5)

{
  longlong lVar1;
  long lVar2;
  int iVar3;
  CRIMObjManager *this;
  CRIMObjManager *this_00;
  uint uVar4;
  _func_long__GUID_ptr_IRIMStream_ptr_IUnknown_ptr_ptr *p_Var5;
  _func_long__GUID_ptr_IUnknown_ptr_IRIMStub_ptr_ptr *p_Var6;
  CRIMObjManager *local_res10;
  ulong in_stack_ffffffffffffffe8;
  
  p_Var5 = (_func_long__GUID_ptr_IRIMStream_ptr_IUnknown_ptr_ptr *)0x1b0;
  p_Var6 = (_func_long__GUID_ptr_IUnknown_ptr_IRIMStub_ptr_ptr *)0x6c6d6952;
  local_res10 = (CRIMObjManager *)param_2;
  this = (CRIMObjManager *)ExAllocatePoolWithTag(0x200);
  if (this == (CRIMObjManager *)0x0) {
    local_res10 = (CRIMObjManager *)0x0;
  }
  else {
    this_00 = (CRIMObjManager *)
              CRIMObjManager::CRIMObjManager(this,p_Var5,p_Var6,param_4,in_stack_ffffffffffffffe8);
    uVar4 = (uint)this;
    local_res10 = this_00;
    if (this_00 != (CRIMObjManager *)0x0) {
      LOCK();
      *(int *)(this_00 + 0xc) = *(int *)(this_00 + 0xc) + 1;
      UNLOCK();
      *(CRIMObjManager **)(this_00 + 0x108) = this_00;
      lVar2 = CRIMObjectPool<CRimWriteCallback>::CreateInstance
                        (uVar4,(CRIMObjectPool<class_CRimWriteCallback> **)(this_00 + 400));
      iVar3 = 0;
      if (lVar2 < 0) {
        iVar3 = lVar2;
      }
      if (-1 < iVar3) {
        iVar3 = CRIMObjectPool<CMemory>::CreateInstance
                          (uVar4,(CRIMObjectPool<class_CMemory> **)(this_00 + 0x198));
        if (-1 < iVar3) {
          iVar3 = CRIMObjectPool<CMessage>::CreateInstance
                            (uVar4,(CRIMObjectPool<class_CMessage> **)(this_00 + 0x1a0));
          if ((-1 < iVar3) && (*(int *)(this_00 + 0xdc) == 2)) {
            iVar3 = CRIMObjManager::RegisterCapabilities(this_00,*(ulong *)(this_00 + 0xe0));
          }
        }
        if (-1 < iVar3) {
          lVar1 = *(longlong *)this_00;
          *param_3 = (IRIMObjManager *)this_00;
          (**(code **)(lVar1 + 8))(this_00);
        }
      }
      goto LAB_140013539;
    }
  }
  iVar3 = -0x7ff8fff2;
LAB_140013539:
  SmartPtr<CRIMObjManager>::~SmartPtr<CRIMObjManager>((SmartPtr<CRIMObjManager> *)&local_res10);
  return iVar3;
}



===== GetPooledObject @ 14001355c =====

/* public: long __cdecl CRIMObjectPool<class CRimWriteCallback>::GetPooledObject(class
   CRimWriteCallback * __ptr64 * __ptr64,int) __ptr64 */

long __thiscall
CRIMObjectPool<CRimWriteCallback>::GetPooledObject
          (CRIMObjectPool<CRimWriteCallback> *this,CRimWriteCallback **param_1,int param_2)

{
  CRIMObjectPool<CRimWriteCallback> *pCVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  long lVar5;
  CRimWriteCallback *pCVar6;
  CRimWriteCallback *pCVar7;
  CRIMObjectPoolBase *pCVar8;
  ExclusiveLock local_res8 [8];
  
  lVar5 = 0;
  *param_1 = (CRimWriteCallback *)0x0;
  ExclusiveLock::ExclusiveLock(local_res8,(GenericLock *)(this + 0x48));
  pCVar1 = *(CRIMObjectPool<CRimWriteCallback> **)(this + 0x28);
  if (pCVar1 != this + 0x28) {
    *param_1 = (CRimWriteCallback *)(pCVar1 + -0x20);
    lVar2 = *(longlong *)pCVar1;
    if ((*(CRIMObjectPool<CRimWriteCallback> **)(lVar2 + 8) != pCVar1) ||
       (plVar3 = *(longlong **)(pCVar1 + 8), (CRIMObjectPool<CRimWriteCallback> *)*plVar3 != pCVar1)
       ) goto LAB_1400136b9;
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    plVar3 = *(longlong **)(this + 0x40);
    pCVar6 = *param_1;
    pCVar7 = pCVar6 + 0x20;
    if ((CRIMObjectPool<CRimWriteCallback> *)*plVar3 != this + 0x38) goto LAB_1400136b9;
    *(CRIMObjectPool<CRimWriteCallback> **)pCVar7 = this + 0x38;
    *(longlong **)(pCVar6 + 0x28) = plVar3;
    *plVar3 = (longlong)pCVar7;
    *(CRimWriteCallback **)(this + 0x40) = pCVar7;
    *(int *)(this + 0x18) = *(int *)(this + 0x18) + -1;
    *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
    *(undefined4 *)(*param_1 + 0x30) = 1;
    LOCK();
    *(int *)(*param_1 + 0xc) = *(int *)(*param_1 + 0xc) + 1;
    UNLOCK();
    SmartPtr<IWTSVirtualChannel>::operator=
              ((SmartPtr<IWTSVirtualChannel> *)(*param_1 + 0x38),(IWTSVirtualChannel *)this);
  }
  if (*param_1 == (CRimWriteCallback *)0x0) {
    pCVar8 = (CRIMObjectPoolBase *)0x50;
    pCVar6 = (CRimWriteCallback *)ExAllocatePoolWithTag(0x200,0x50,0x6c6d6952);
    if (pCVar6 == (CRimWriteCallback *)0x0) {
      *param_1 = (CRimWriteCallback *)0x0;
    }
    else {
      pCVar6 = (CRimWriteCallback *)CRimWriteCallback::CRimWriteCallback(pCVar6,pCVar8);
      *param_1 = pCVar6;
      if (pCVar6 != (CRimWriteCallback *)0x0) {
        LOCK();
        *(int *)(pCVar6 + 0xc) = *(int *)(pCVar6 + 0xc) + 1;
        UNLOCK();
        *(undefined4 *)(*param_1 + 0x30) = 1;
        SmartPtr<IWTSVirtualChannel>::operator=
                  ((SmartPtr<IWTSVirtualChannel> *)(*param_1 + 0x38),(IWTSVirtualChannel *)this);
        LOCK();
        *(int *)(*param_1 + 0xc) = *(int *)(*param_1 + 0xc) + 1;
        UNLOCK();
        plVar3 = *(longlong **)(this + 0x40);
        pCVar6 = *param_1;
        pCVar7 = pCVar6 + 0x20;
        if ((CRIMObjectPool<CRimWriteCallback> *)*plVar3 != this + 0x38) {
LAB_1400136b9:
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          pcVar4 = (code *)swi(3);
          lVar5 = (*pcVar4)();
          return lVar5;
        }
        *(CRIMObjectPool<CRimWriteCallback> **)pCVar7 = this + 0x38;
        *(longlong **)(pCVar6 + 0x28) = plVar3;
        *plVar3 = (longlong)pCVar7;
        *(CRimWriteCallback **)(this + 0x40) = pCVar7;
        *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
        goto LAB_140013697;
      }
    }
    lVar5 = -0x7ff8fff2;
  }
LAB_140013697:
  ExclusiveLock::~ExclusiveLock(local_res8);
  return lVar5;
}



===== Initialize @ 1400136c8 =====

/* public: long __cdecl CRIMObjectPool<class CMemory>::Initialize(void) __ptr64 */

long __thiscall CRIMObjectPool<CMemory>::Initialize(CRIMObjectPool<CMemory> *this)

{
  longlong *plVar1;
  code *pcVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar5 = auStack_28;
  uVar6 = 0;
  while( true ) {
    if (*(uint *)(this + 0x18) <= uVar6) {
      return 0;
    }
    puVar3 = (undefined8 *)ExAllocatePoolWithTag(0x200,0x78,0x6c6d6952);
    if (puVar3 == (undefined8 *)0x0) break;
    *(undefined4 *)(puVar3 + 1) = 0;
    *puVar3 = &CImplIUnknown<IUnknown>::_vftable_;
    *(undefined4 *)((longlong)puVar3 + 0xc) = 0;
    *(undefined4 *)(puVar3 + 2) = 0xc001d00d;
    puVar3[7] = 0;
    *puVar3 = &CMemory::_vftable__for__CImplIUnknown<IUnknown>__;
    puVar3[3] = &CMemory::_vftable__for__CRIMPooledUnknown__;
    puVar3[10] = 0;
    *(undefined4 *)(puVar3 + 0xb) = 0;
    puVar3[0xc] = 0;
    puVar3[0xd] = 0;
    *(undefined4 *)(puVar3 + 0xe) = 0;
    LOCK();
    *(int *)((longlong)puVar3 + 0xc) = *(int *)((longlong)puVar3 + 0xc) + 1;
    UNLOCK();
    *(undefined4 *)(puVar3 + 6) = 0;
    plVar1 = *(longlong **)(this + 0x30);
    plVar4 = puVar3 + 4;
    if ((CRIMObjectPool<CMemory> *)*plVar1 != this + 0x28) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      puVar5 = auStack_20;
      break;
    }
    *plVar4 = (longlong)(this + 0x28);
    uVar6 = uVar6 + 1;
    puVar3[5] = plVar1;
    *plVar1 = (longlong)plVar4;
    *(longlong **)(this + 0x30) = plVar4;
  }
  *(undefined8 *)(puVar5 + -8) = 0x14001378b;
  Terminate(this);
  return -0x7ff8fff2;
}



===== Initialize @ 1400137a4 =====

/* public: long __cdecl CRIMObjectPool<class CMessage>::Initialize(void) __ptr64 */

long __thiscall CRIMObjectPool<CMessage>::Initialize(CRIMObjectPool<CMessage> *this)

{
  longlong *plVar1;
  code *pcVar2;
  CMessage *this_00;
  longlong lVar3;
  longlong *plVar4;
  CRIMObjectPoolBase *pCVar5;
  undefined1 *puVar6;
  uint uVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar7 = 0;
  while( true ) {
    if (*(uint *)(this + 0x18) <= uVar7) {
      return 0;
    }
    pCVar5 = (CRIMObjectPoolBase *)0x68;
    this_00 = (CMessage *)ExAllocatePoolWithTag(0x200,0x68,0x6c6d6952);
    puVar6 = auStack_28;
    if ((this_00 == (CMessage *)0x0) ||
       (lVar3 = CMessage::CMessage(this_00,pCVar5), puVar6 = auStack_28, lVar3 == 0)) break;
    LOCK();
    *(int *)(lVar3 + 0xc) = *(int *)(lVar3 + 0xc) + 1;
    UNLOCK();
    *(undefined4 *)(lVar3 + 0x30) = 0;
    plVar1 = *(longlong **)(this + 0x30);
    plVar4 = (longlong *)(lVar3 + 0x20);
    if ((CRIMObjectPool<CMessage> *)*plVar1 != this + 0x28) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      puVar6 = auStack_20;
      break;
    }
    *plVar4 = (longlong)(this + 0x28);
    uVar7 = uVar7 + 1;
    *(longlong **)(lVar3 + 0x28) = plVar1;
    *plVar1 = (longlong)plVar4;
    *(longlong **)(this + 0x30) = plVar4;
  }
  *(undefined8 *)(puVar6 + -8) = 0x14001382b;
  Terminate(this);
  return -0x7ff8fff2;
}



===== Initialize @ 140013844 =====

/* public: long __cdecl CRIMObjectPool<class CRimWriteCallback>::Initialize(void) __ptr64 */

long __thiscall
CRIMObjectPool<CRimWriteCallback>::Initialize(CRIMObjectPool<CRimWriteCallback> *this)

{
  longlong *plVar1;
  code *pcVar2;
  CRimWriteCallback *this_00;
  longlong lVar3;
  longlong *plVar4;
  CRIMObjectPoolBase *pCVar5;
  undefined1 *puVar6;
  uint uVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar7 = 0;
  while( true ) {
    if (*(uint *)(this + 0x18) <= uVar7) {
      return 0;
    }
    pCVar5 = (CRIMObjectPoolBase *)0x50;
    this_00 = (CRimWriteCallback *)ExAllocatePoolWithTag(0x200,0x50,0x6c6d6952);
    puVar6 = auStack_28;
    if ((this_00 == (CRimWriteCallback *)0x0) ||
       (lVar3 = CRimWriteCallback::CRimWriteCallback(this_00,pCVar5), puVar6 = auStack_28,
       lVar3 == 0)) break;
    LOCK();
    *(int *)(lVar3 + 0xc) = *(int *)(lVar3 + 0xc) + 1;
    UNLOCK();
    *(undefined4 *)(lVar3 + 0x30) = 0;
    plVar1 = *(longlong **)(this + 0x30);
    plVar4 = (longlong *)(lVar3 + 0x20);
    if ((CRIMObjectPool<CRimWriteCallback> *)*plVar1 != this + 0x28) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      puVar6 = auStack_20;
      break;
    }
    *plVar4 = (longlong)(this + 0x28);
    uVar7 = uVar7 + 1;
    *(longlong **)(lVar3 + 0x28) = plVar1;
    *plVar1 = (longlong)plVar4;
    *(longlong **)(this + 0x30) = plVar4;
  }
  *(undefined8 *)(puVar6 + -8) = 0x1400138cb;
  Terminate(this);
  return -0x7ff8fff2;
}



===== OnClose @ 1400138f0 =====

/* public: virtual long __cdecl CRimChannel::OnClose(void) __ptr64 */

long __thiscall CRimChannel::OnClose(CRimChannel *this)

{
  long lVar1;
  ExclusiveLock local_res8 [32];
  
  ExclusiveLock::ExclusiveLock(local_res8,(GenericLock *)(this + 0x28));
  SmartPtr<IWTSVirtualChannel>::operator=
            ((SmartPtr<IWTSVirtualChannel> *)(this + 0x18),(IWTSVirtualChannel *)0x0);
  ExclusiveLock::~ExclusiveLock(local_res8);
  lVar1 = CRIMObjManager::CloseChannel(*(CRIMObjManager **)(this + 0x20));
  return lVar1;
}



===== OnDataReceived @ 140013940 =====

/* public: virtual long __cdecl CRimChannel::OnDataReceived(unsigned long,unsigned char * __ptr64)
   __ptr64 */

long __thiscall CRimChannel::OnDataReceived(CRimChannel *this,ulong param_1,uchar *param_2)

{
  long lVar1;
  
  lVar1 = CRIMObjManager::OnDataReceived(*(CRIMObjManager **)(this + 0x20),param_2,param_1);
  return lVar1;
}



===== OnReturnToPool @ 140013970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual void __cdecl CRIMPooledUnknown::OnReturnToPool(void) __ptr64 */

void __thiscall CRIMPooledUnknown::OnReturnToPool(CRIMPooledUnknown *this)

{
  (**(code **)(*(longlong *)this + 8))();
  return;
}



===== QueryInterface @ 140013990 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CImplIUnknown<struct IMessage>::QueryInterface(struct _GUID const &
   __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CImplIUnknown<IMessage>::QueryInterface(CImplIUnknown<IMessage> *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  lVar1 = -*(longlong *)param_1;
  if (lVar1 == 0) {
    lVar1 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar1 != 0) {
    lVar1 = 0x49ae032f3f845961 - *(longlong *)param_1;
    if (lVar1 == 0) {
      lVar1 = 0xe4a62b9533b9bab4 - *(longlong *)(param_1 + 8);
    }
    if (lVar1 != 0) {
      return -0x7fffbffe;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== QueryInterface @ 140013a00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CImplIUnknown<struct IRIMObjManager>::QueryInterface(struct _GUID
   const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CImplIUnknown<IRIMObjManager>::QueryInterface
          (CImplIUnknown<IRIMObjManager> *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  lVar1 = -*(longlong *)param_1;
  if (lVar1 == 0) {
    lVar1 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar1 != 0) {
    lVar1 = 0x497655af34f6a387 - *(longlong *)param_1;
    if (lVar1 == 0) {
      lVar1 = 0xca0c460499c0dfb9 - *(longlong *)(param_1 + 8);
    }
    if (lVar1 != 0) {
      return -0x7fffbffe;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== QueryInterface @ 140013a70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CImplIUnknown<struct IUnknown>::QueryInterface(struct _GUID const &
   __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CImplIUnknown<IUnknown>::QueryInterface(CImplIUnknown<IUnknown> *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  lVar1 = -*(longlong *)param_1;
  if (lVar1 == 0) {
    lVar1 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar1 != 0) {
    lVar1 = -*(longlong *)param_1;
    if (lVar1 == 0) {
      lVar1 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
    }
    if (lVar1 != 0) {
      return -0x7fffbffe;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== QueryInterface @ 140013ae0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CImplIUnknown<struct
   IWTSVirtualChannelCallback>::QueryInterface(struct _GUID const & __ptr64,void * __ptr64 *
   __ptr64) __ptr64 */

long __thiscall
CImplIUnknown<IWTSVirtualChannelCallback>::QueryInterface
          (CImplIUnknown<IWTSVirtualChannelCallback> *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  lVar1 = -*(longlong *)param_1;
  if (lVar1 == 0) {
    lVar1 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar1 != 0) {
    lVar1 = 0x11d8d6a7a1230204 - *(longlong *)param_1;
    if (lVar1 == 0) {
      lVar1 = 0x98f1d1db0b00fdb9 - *(longlong *)(param_1 + 8);
    }
    if (lVar1 != 0) {
      return -0x7fffbffe;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== QueryInterface @ 140013b50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CImplIUnknown<struct IWTSWriteCallback>::QueryInterface(struct _GUID
   const & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CImplIUnknown<IWTSWriteCallback>::QueryInterface
          (CImplIUnknown<IWTSWriteCallback> *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  lVar1 = -*(longlong *)param_1;
  if (lVar1 == 0) {
    lVar1 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar1 != 0) {
    lVar1 = 0x11d8d6a7a1230208 - *(longlong *)param_1;
    if (lVar1 == 0) {
      lVar1 = 0x98f1d1db0b00fdb9 - *(longlong *)(param_1 + 8);
    }
    if (lVar1 != 0) {
      return -0x7fffbffe;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== QueryInterface @ 140013bc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CRimChannel::QueryInterface(struct _GUID const & __ptr64,void *
   __ptr64 * __ptr64) __ptr64 */

long __thiscall CRimChannel::QueryInterface(CRimChannel *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  lVar1 = 0x11d8d6a7a1230204 - *(longlong *)param_1;
  if (lVar1 == 0) {
    lVar1 = 0x98f1d1db0b00fdb9 - *(longlong *)(param_1 + 8);
  }
  if (lVar1 != 0) {
    lVar1 = -*(longlong *)param_1;
    if (lVar1 == 0) {
      lVar1 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
    }
    if (lVar1 != 0) {
      return -0x7fffbffe;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== ReceiveUINT8 @ 140013c30 =====

/* public: virtual long __cdecl CMessage::ReceiveUINT8(unsigned char * __ptr64,unsigned long)
   __ptr64 */

long __thiscall CMessage::ReceiveUINT8(CMessage *this,uchar *param_1,ulong param_2)

{
  long lVar1;
  
  lVar1 = ReceiveMemory(this,param_1,param_2,param_2);
  return lVar1;
}



===== ReceiveINT32 @ 140013c50 =====

/* public: virtual long __cdecl CMessage::ReceiveINT32(int * __ptr64,unsigned long) __ptr64 */

long __thiscall CMessage::ReceiveINT32(CMessage *this,int *param_1,ulong param_2)

{
  long lVar1;
  
  lVar1 = ReceiveMemory(this,param_1,param_2 << 2,param_2 << 2);
  return lVar1;
}



===== ReceiveINT64 @ 140013c70 =====

/* public: virtual long __cdecl CMessage::ReceiveINT64(__int64 * __ptr64,unsigned long) __ptr64 */

long __thiscall CMessage::ReceiveINT64(CMessage *this,__int64 *param_1,ulong param_2)

{
  long lVar1;
  
  lVar1 = ReceiveMemory(this,param_1,param_2 << 3,param_2 << 3);
  return lVar1;
}



===== ReceiveFunction @ 140013c90 =====

/* public: virtual long __cdecl CMessage::ReceiveFunction(unsigned long * __ptr64) __ptr64 */

long __thiscall CMessage::ReceiveFunction(CMessage *this,ulong *param_1)

{
  long lVar1;
  
  lVar1 = ReceiveMemory(this,param_1,4,4);
  return lVar1;
}



===== ReceiveIID @ 140013cb0 =====

/* public: virtual long __cdecl CMessage::ReceiveIID(struct _GUID const & __ptr64) __ptr64 */

long __thiscall CMessage::ReceiveIID(CMessage *this,_GUID *param_1)

{
  long lVar1;
  
  lVar1 = ReceiveMemory(this,param_1,0x10,0x10);
  return lVar1;
}



===== ReceiveUINT16 @ 140013cd0 =====

/* public: virtual long __cdecl CMessage::ReceiveUINT16(unsigned short * __ptr64,unsigned long)
   __ptr64 */

long __thiscall CMessage::ReceiveUINT16(CMessage *this,ushort *param_1,ulong param_2)

{
  long lVar1;
  
  lVar1 = ReceiveMemory(this,param_1,param_2 * 2,param_2 * 2);
  return lVar1;
}



===== ReceiveNULLMark @ 140013cf0 =====

/* public: virtual long __cdecl CMessage::ReceiveNULLMark(int * __ptr64) __ptr64 */

long __thiscall CMessage::ReceiveNULLMark(CMessage *this,int *param_1)

{
  long lVar1;
  byte local_res10 [24];
  
  local_res10[0] = 0;
  lVar1 = ReceiveMemory(this,local_res10,1,1);
  *param_1 = (uint)local_res10[0];
  return lVar1;
}



===== Release @ 140013d30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual unsigned long __cdecl CImplIUnknown<struct IMessage>::Release(void) __ptr64 */

ulong __thiscall CImplIUnknown<IMessage>::Release(CImplIUnknown<IMessage> *this)

{
  CImplIUnknown<IMessage> *pCVar1;
  int iVar2;
  ulong uVar3;
  
  LOCK();
  pCVar1 = this + 0xc;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  uVar3 = iVar2 - 1;
  if ((uVar3 == 0) && (this != (CImplIUnknown<IMessage> *)0x0)) {
    (**(code **)(*(longlong *)this + 400))(this,iVar2);
  }
  return uVar3;
}



===== Release @ 140013d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual unsigned long __cdecl CImplIUnknown<struct IRIMObjManager>::Release(void) __ptr64
    */

ulong __thiscall CImplIUnknown<IRIMObjManager>::Release(CImplIUnknown<IRIMObjManager> *this)

{
  CImplIUnknown<IRIMObjManager> *pCVar1;
  int iVar2;
  ulong uVar3;
  
  LOCK();
  pCVar1 = this + 0xc;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  uVar3 = iVar2 - 1;
  if ((uVar3 == 0) && (this != (CImplIUnknown<IRIMObjManager> *)0x0)) {
    (**(code **)(*(longlong *)this + 0x50))(this,iVar2);
  }
  return uVar3;
}



===== Release @ 140013db0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual unsigned long __cdecl CImplIUnknown<struct IUnknown>::Release(void) __ptr64 */

ulong __thiscall CImplIUnknown<IUnknown>::Release(CImplIUnknown<IUnknown> *this)

{
  CImplIUnknown<IUnknown> *pCVar1;
  int iVar2;
  ulong uVar3;
  
  LOCK();
  pCVar1 = this + 0xc;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  uVar3 = iVar2 - 1;
  if ((uVar3 == 0) && (this != (CImplIUnknown<IUnknown> *)0x0)) {
    (**(code **)(*(longlong *)this + 0x18))(this,iVar2);
  }
  return uVar3;
}



===== Release @ 140013df0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual unsigned long __cdecl CImplIUnknownPool<struct IMessage>::Release(void) __ptr64
    */

ulong __thiscall CImplIUnknownPool<IMessage>::Release(CImplIUnknownPool<IMessage> *this)

{
  CImplIUnknownPool<IMessage> *pCVar1;
  int iVar2;
  longlong *local_res8;
  
  LOCK();
  pCVar1 = this + 0xc;
  iVar2 = *(int *)pCVar1;
  *(int *)pCVar1 = *(int *)pCVar1 + -1;
  UNLOCK();
  if (iVar2 - 1U == 1) {
    SmartPtr<CRIMObjectPoolBase>::SmartPtr<CRIMObjectPoolBase>
              ((SmartPtr<CRIMObjectPoolBase> *)&local_res8,
               (SmartPtr<class_CRIMObjectPool<class_CMessage>_> *)(this + 0x38));
    SmartPtr<IWTSVirtualChannel>::operator=
              ((SmartPtr<IWTSVirtualChannel> *)(this + 0x38),(IWTSVirtualChannel *)0x0);
    if (local_res8 != (longlong *)0x0) {
      (**(code **)(*local_res8 + 0x20))
                (local_res8,
                 -(ulonglong)(this != (CImplIUnknownPool<IMessage> *)0x0) & (ulonglong)(this + 0x18)
                );
    }
    SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res8);
  }
  return iVar2 - 1U;
}



===== Release @ 140013e70 =====

/* public: virtual unsigned long __cdecl CRimChannel::Release(void) __ptr64 */

ulong __thiscall CRimChannel::Release(CRimChannel *this)

{
  ulong uVar1;
  
  uVar1 = CImplIUnknown<IRIMObjManager>::Release(*(CImplIUnknown<IRIMObjManager> **)(this + 0x20));
  return uVar1;
}



===== ReleaseResources @ 140013e90 =====

/* public: virtual void __cdecl CMemory::[CRIMPooledUnknown]::ReleaseResources(void) __ptr64 */

void __thiscall CMemory::[CRIMPooledUnknown]::ReleaseResources(_CRIMPooledUnknown_ *this)

{
  if (0x2000 < *(uint *)(this + 0x58)) {
    operator_delete(*(void **)(this + 0x38));
    *(undefined8 *)(this + 0x38) = 0;
    *(undefined4 *)(this + 0x40) = 0;
    *(undefined8 *)(this + 0x48) = 0;
    *(undefined8 *)(this + 0x50) = 0;
    *(undefined4 *)(this + 0x58) = 0;
  }
  return;
}



===== ReleaseResources @ 140013ed0 =====

/* public: virtual void __cdecl CRimWriteCallback::[CRIMPooledUnknown]::ReleaseResources(void)
   __ptr64 */

void __thiscall CRimWriteCallback::[CRIMPooledUnknown]::ReleaseResources(_CRIMPooledUnknown_ *this)

{
  CImplIUnknownPool<IMessage> *this_00;
  longlong lVar1;
  
  this_00 = *(CImplIUnknownPool<IMessage> **)(this + 0x28);
  *(undefined8 *)(this + 0x28) = 0;
  if (this_00 != (CImplIUnknownPool<IMessage> *)0x0) {
    CImplIUnknownPool<IMessage>::Release(this_00);
  }
  lVar1 = *(longlong *)(this + 0x30);
  *(undefined8 *)(this + 0x30) = 0;
  if (lVar1 != 0) {
    CImplIUnknown<IRIMObjManager>::Release(*(CImplIUnknown<IRIMObjManager> **)(lVar1 + 0x20));
  }
  return;
}



===== Reset @ 140013f10 =====

/* public: virtual long __cdecl CMessage::Reset(void) __ptr64 */

long __thiscall CMessage::Reset(CMessage *this)

{
  CImplIUnknownPool<IMessage> *this_00;
  
  this_00 = *(CImplIUnknownPool<IMessage> **)(this + 0x48);
  *(undefined8 *)(this + 0x48) = 0;
  if (this_00 != (CImplIUnknownPool<IMessage> *)0x0) {
    CImplIUnknownPool<IMessage>::Release(this_00);
  }
  *(undefined4 *)(this + 0x58) = 0;
  return 0;
}



===== ReturnPooledObject @ 140013f40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CRIMObjectPool<class CMessage>::ReturnPooledObject(class
   CRIMPooledUnknown * __ptr64) __ptr64 */

long __thiscall
CRIMObjectPool<CMessage>::ReturnPooledObject
          (CRIMObjectPool<CMessage> *this,CRIMPooledUnknown *param_1)

{
  CRIMPooledUnknown *pCVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  long lVar5;
  ExclusiveLock local_res8 [8];
  
  (**(code **)(*(longlong *)param_1 + 0x10))(param_1);
  ExclusiveLock::ExclusiveLock(local_res8,(GenericLock *)(this + 0x48));
  *(undefined4 *)(param_1 + 0x18) = 0;
  pCVar1 = param_1 + 8;
  lVar2 = *(longlong *)pCVar1;
  if ((*(CRIMPooledUnknown **)(lVar2 + 8) != pCVar1) ||
     (plVar3 = *(longlong **)(param_1 + 0x10), (CRIMPooledUnknown *)*plVar3 != pCVar1)) {
LAB_140013fe4:
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    lVar5 = (*pcVar4)();
    return lVar5;
  }
  *plVar3 = lVar2;
  *(longlong **)(lVar2 + 8) = plVar3;
  if (*(uint *)(this + 0x18) < *(uint *)(this + 0x20)) {
    plVar3 = *(longlong **)(this + 0x30);
    if ((CRIMObjectPool<CMessage> *)*plVar3 != this + 0x28) goto LAB_140013fe4;
    *(CRIMObjectPool<CMessage> **)pCVar1 = this + 0x28;
    *(longlong **)(param_1 + 0x10) = plVar3;
    *plVar3 = (longlong)pCVar1;
    *(CRIMPooledUnknown **)(this + 0x30) = pCVar1;
    *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
  }
  else {
    (*(code *)**(undefined8 **)param_1)(param_1,1);
  }
  *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
  ExclusiveLock::~ExclusiveLock(local_res8);
  return 0;
}



===== Terminate @ 140013ff4 =====

/* public: long __cdecl CRIMObjectPool<class CMemory>::Terminate(void) __ptr64 */

long __thiscall CRIMObjectPool<CMemory>::Terminate(CRIMObjectPool<CMemory> *this)

{
  CRIMObjectPool<CMemory> *pCVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  long lVar6;
  uint uVar7;
  ExclusiveLock local_res8 [8];
  
  ExclusiveLock::ExclusiveLock(local_res8,(GenericLock *)(this + 0x48));
  pCVar1 = this + 0x28;
  if (*(CRIMObjectPool<CMemory> **)pCVar1 != pCVar1) {
    uVar7 = 0;
    if (*(int *)(this + 0x18) != 0) {
      do {
        plVar2 = *(longlong **)pCVar1;
        lVar3 = *plVar2;
        if ((*(longlong **)(lVar3 + 8) != plVar2) ||
           (plVar4 = (longlong *)plVar2[1], (longlong *)*plVar4 != plVar2)) {
          pcVar5 = (code *)swi(0x29);
          (*pcVar5)(3);
          pcVar5 = (code *)swi(3);
          lVar6 = (*pcVar5)();
          return lVar6;
        }
        *plVar4 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar4;
        if ((CMemory *)(plVar2 + -4) != (CMemory *)0x0) {
          CMemory::_vector_deleting_destructor_((CMemory *)(plVar2 + -4),1);
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint *)(this + 0x18));
    }
    *(undefined4 *)(this + 0x18) = 0;
  }
  ExclusiveLock::~ExclusiveLock(local_res8);
  return 0;
}



===== Terminate @ 140014088 =====

/* public: long __cdecl CRIMObjectPool<class CMessage>::Terminate(void) __ptr64 */

long __thiscall CRIMObjectPool<CMessage>::Terminate(CRIMObjectPool<CMessage> *this)

{
  CRIMObjectPool<CMessage> *pCVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  long lVar6;
  uint uVar7;
  ExclusiveLock local_res8 [8];
  
  ExclusiveLock::ExclusiveLock(local_res8,(GenericLock *)(this + 0x48));
  pCVar1 = this + 0x28;
  if (*(CRIMObjectPool<CMessage> **)pCVar1 != pCVar1) {
    uVar7 = 0;
    if (*(int *)(this + 0x18) != 0) {
      do {
        plVar2 = *(longlong **)pCVar1;
        lVar3 = *plVar2;
        if ((*(longlong **)(lVar3 + 8) != plVar2) ||
           (plVar4 = (longlong *)plVar2[1], (longlong *)*plVar4 != plVar2)) {
          pcVar5 = (code *)swi(0x29);
          (*pcVar5)(3);
          pcVar5 = (code *)swi(3);
          lVar6 = (*pcVar5)();
          return lVar6;
        }
        *plVar4 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar4;
        if ((CMessage *)(plVar2 + -4) != (CMessage *)0x0) {
          CMessage::_vector_deleting_destructor_((CMessage *)(plVar2 + -4),1);
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint *)(this + 0x18));
    }
    *(undefined4 *)(this + 0x18) = 0;
  }
  ExclusiveLock::~ExclusiveLock(local_res8);
  return 0;
}



===== Terminate @ 14001411c =====

/* public: long __cdecl CRIMObjectPool<class CRimWriteCallback>::Terminate(void) __ptr64 */

long __thiscall
CRIMObjectPool<CRimWriteCallback>::Terminate(CRIMObjectPool<CRimWriteCallback> *this)

{
  CRIMObjectPool<CRimWriteCallback> *pCVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  long lVar6;
  uint uVar7;
  ExclusiveLock local_res8 [8];
  
  ExclusiveLock::ExclusiveLock(local_res8,(GenericLock *)(this + 0x48));
  pCVar1 = this + 0x28;
  if (*(CRIMObjectPool<CRimWriteCallback> **)pCVar1 != pCVar1) {
    uVar7 = 0;
    if (*(int *)(this + 0x18) != 0) {
      do {
        plVar2 = *(longlong **)pCVar1;
        lVar3 = *plVar2;
        if ((*(longlong **)(lVar3 + 8) != plVar2) ||
           (plVar4 = (longlong *)plVar2[1], (longlong *)*plVar4 != plVar2)) {
          pcVar5 = (code *)swi(0x29);
          (*pcVar5)(3);
          pcVar5 = (code *)swi(3);
          lVar6 = (*pcVar5)();
          return lVar6;
        }
        *plVar4 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar4;
        if ((CRimWriteCallback *)(plVar2 + -4) != (CRimWriteCallback *)0x0) {
          CRimWriteCallback::_scalar_deleting_destructor_((CRimWriteCallback *)(plVar2 + -4),1);
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < *(uint *)(this + 0x18));
    }
    *(undefined4 *)(this + 0x18) = 0;
  }
  ExclusiveLock::~ExclusiveLock(local_res8);
  return 0;
}



===== Terminate @ 1400141b0 =====

/* public: virtual long __cdecl CRIMObjManager::Terminate(void) __ptr64 */

long __thiscall CRIMObjManager::Terminate(CRIMObjManager *this)

{
  long lVar1;
  
  lVar1 = CloseChannel(this);
  return lVar1;
}



===== Write @ 1400141c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl CRimChannel::Write(class CMemory * __ptr64) __ptr64 */

long __thiscall CRimChannel::Write(CRimChannel *this,CMemory *param_1)

{
  longlong *plVar1;
  CRimWriteCallback *pCVar2;
  long lVar3;
  int in_R8D;
  longlong *local_res8 [2];
  CRimWriteCallback *local_res18;
  CRimWriteCallback *local_res20;
  ExclusiveLock local_38 [16];
  
  local_res20 = (CRimWriteCallback *)0x0;
  local_res18 = (CRimWriteCallback *)0x0;
  local_res8[0] = (longlong *)0x0;
  ExclusiveLock::ExclusiveLock(local_38,(GenericLock *)(this + 0x28));
  SmartPtr<IWTSVirtualChannel>::operator=
            ((SmartPtr<IWTSVirtualChannel> *)local_res8,*(IWTSVirtualChannel **)(this + 0x18));
  ExclusiveLock::~ExclusiveLock(local_38);
  plVar1 = local_res8[0];
  if (local_res8[0] == (longlong *)0x0) {
    lVar3 = -0x7ff8f736;
  }
  else {
    CRIMObjectPool<CRimWriteCallback>::GetPooledObject
              (*(CRIMObjectPool<CRimWriteCallback> **)(this + 0xa8),&local_res18,in_R8D);
    pCVar2 = local_res18;
    local_res20 = local_res18;
    if (local_res18 == (CRimWriteCallback *)0x0) {
      lVar3 = -0x7ff8fff2;
    }
    else {
      (**(code **)(*(longlong *)local_res18 + 8))(local_res18);
      SmartPtr<CMemory>::operator=((SmartPtr<CMemory> *)(pCVar2 + 0x40),param_1);
      SmartPtr<CRimChannel>::operator=((SmartPtr<CRimChannel> *)(pCVar2 + 0x48),this);
      lVar3 = (**(code **)(*plVar1 + 0x18))
                        (plVar1,*(undefined4 *)(param_1 + 0x6c),*(undefined8 *)(param_1 + 0x60),
                         pCVar2);
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)local_res8);
  SmartPtr<CMessage>::~SmartPtr<CMessage>((SmartPtr<CMessage> *)&local_res18);
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res20);
  return lVar3;
}



===== WriteINT8 @ 1400142c0 =====

/* public: virtual long __cdecl CMessage::WriteINT8(char * __ptr64,unsigned long) __ptr64 */

long __thiscall CMessage::WriteINT8(CMessage *this,char *param_1,ulong param_2)

{
  long lVar1;
  
  lVar1 = WriteMemory(this,param_1,param_2);
  return lVar1;
}



===== WriteCompleted @ 1400142e0 =====

/* public: virtual long __cdecl CRimWriteCallback::WriteCompleted(int) __ptr64 */

long __thiscall CRimWriteCallback::WriteCompleted(CRimWriteCallback *this,int param_1)

{
  CImplIUnknownPool<IMessage> *this_00;
  longlong lVar1;
  
  this_00 = *(CImplIUnknownPool<IMessage> **)(this + 0x40);
  *(undefined8 *)(this + 0x40) = 0;
  if (this_00 != (CImplIUnknownPool<IMessage> *)0x0) {
    CImplIUnknownPool<IMessage>::Release(this_00);
  }
  lVar1 = *(longlong *)(this + 0x48);
  *(undefined8 *)(this + 0x48) = 0;
  if (lVar1 != 0) {
    CImplIUnknown<IRIMObjManager>::Release(*(CImplIUnknown<IRIMObjManager> **)(lVar1 + 0x20));
  }
  return 0;
}



===== WriteUINT32 @ 140014330 =====

/* public: virtual long __cdecl CMessage::WriteUINT32(unsigned int * __ptr64,unsigned long) __ptr64
    */

long __thiscall CMessage::WriteUINT32(CMessage *this,uint *param_1,ulong param_2)

{
  long lVar1;
  
  lVar1 = WriteMemory(this,param_1,param_2 << 2);
  return lVar1;
}



===== WriteUINT64 @ 140014350 =====

/* public: virtual long __cdecl CMessage::WriteUINT64(unsigned __int64 * __ptr64,unsigned long)
   __ptr64 */

long __thiscall CMessage::WriteUINT64(CMessage *this,__uint64 *param_1,ulong param_2)

{
  long lVar1;
  
  lVar1 = WriteMemory(this,param_1,param_2 << 3);
  return lVar1;
}



===== WriteFunction @ 140014370 =====

/* public: virtual long __cdecl CMessage::WriteFunction(unsigned long) __ptr64 */

long __thiscall CMessage::WriteFunction(CMessage *this,ulong param_1)

{
  long lVar1;
  ulong local_res10 [6];
  
  local_res10[0] = param_1;
  lVar1 = WriteMemory(this,local_res10,4);
  return lVar1;
}



===== WriteIID @ 1400143a0 =====

/* public: virtual long __cdecl CMessage::WriteIID(struct _GUID const & __ptr64) __ptr64 */

long __thiscall CMessage::WriteIID(CMessage *this,_GUID *param_1)

{
  long lVar1;
  
  lVar1 = WriteMemory(this,param_1,0x10);
  return lVar1;
}



===== WriteINT16 @ 1400143c0 =====

/* public: virtual long __cdecl CMessage::WriteINT16(short * __ptr64,unsigned long) __ptr64 */

long __thiscall CMessage::WriteINT16(CMessage *this,short *param_1,ulong param_2)

{
  long lVar1;
  
  lVar1 = WriteMemory(this,param_1,param_2 * 2);
  return lVar1;
}



===== WriteNULL @ 1400143e0 =====

/* public: virtual long __cdecl CMessage::WriteNULL(void) __ptr64 */

long __thiscall CMessage::WriteNULL(CMessage *this)

{
  long lVar1;
  
  lVar1 = WriteMemory(this,(void *)0x0,0);
  return lVar1;
}



===== WriteNULLMark @ 140014400 =====

/* public: virtual long __cdecl CMessage::WriteNULLMark(int) __ptr64 */

long __thiscall CMessage::WriteNULLMark(CMessage *this,int param_1)

{
  long lVar1;
  undefined1 local_res10 [24];
  
  local_res10[0] = (undefined1)param_1;
  lVar1 = WriteMemory(this,local_res10,1);
  return lVar1;
}



===== ~CMessage @ 140014424 =====

/* public: virtual __cdecl CMessage::~CMessage(void) __ptr64 */

void __thiscall CMessage::~CMessage(CMessage *this)

{
  *(undefined ***)this = &_vftable__for__CImplIUnknown<IMessage>__;
  *(undefined ***)(this + 0x18) = &_vftable__for__CRIMPooledUnknown__;
  if (*(CRIMObjectPool<CMemory> **)(this + 0x50) != (CRIMObjectPool<CMemory> *)0x0) {
    CRIMObjectPool<CMemory>::Terminate(*(CRIMObjectPool<CMemory> **)(this + 0x50));
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)(this + 0x50));
  SmartPtr<CMessage>::~SmartPtr<CMessage>((SmartPtr<CMessage> *)(this + 0x48));
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)(this + 0x40));
  CImplIUnknownPool<IMessage>::~CImplIUnknownPool<IMessage>((CImplIUnknownPool<IMessage> *)this);
  return;
}



===== CommitReceive @ 140014490 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CMessage::CommitReceive(void) __ptr64 */

long __thiscall CMessage::CommitReceive(CMessage *this)

{
  long lVar1;
  
  lVar1 = (**(code **)(**(longlong **)(this + 0x40) + 0x38))
                    (*(longlong **)(this + 0x40),*(undefined4 *)(this + 0x60),this + 0x48);
  return lVar1;
}



===== CommitWrite @ 1400144c0 =====

/* public: virtual long __cdecl CMessage::CommitWrite(void) __ptr64 */

long __thiscall CMessage::CommitWrite(CMessage *this)

{
  CImplIUnknownPool<IMessage> *this_00;
  long lVar1;
  
  if (*(CMemory **)(this + 0x48) == (CMemory *)0x0) {
    lVar1 = -0x7fffbffd;
  }
  else {
    lVar1 = CRIMStream::WriteMessage
                      (*(CRIMStream **)(this + 0x40),*(ulong *)(this + 0x60),
                       *(CMemory **)(this + 0x48),*(ulong *)(this + 0x58));
    this_00 = *(CImplIUnknownPool<IMessage> **)(this + 0x48);
    *(undefined8 *)(this + 0x48) = 0;
    if (this_00 != (CImplIUnknownPool<IMessage> *)0x0) {
      CImplIUnknownPool<IMessage>::Release(this_00);
    }
    *(undefined4 *)(this + 0x58) = 0;
  }
  return lVar1;
}



===== GetPooledObject @ 14001451c =====

/* public: long __cdecl CRIMObjectPool<class CMemory>::GetPooledObject(class CMemory * __ptr64 *
   __ptr64,int) __ptr64 */

long __thiscall
CRIMObjectPool<CMemory>::GetPooledObject
          (CRIMObjectPool<CMemory> *this,CMemory **param_1,int param_2)

{
  CRIMObjectPool<CMemory> *pCVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  long lVar5;
  CMemory *pCVar6;
  CMemory *pCVar7;
  ExclusiveLock local_res8 [8];
  
  lVar5 = 0;
  *param_1 = (CMemory *)0x0;
  ExclusiveLock::ExclusiveLock(local_res8,(GenericLock *)(this + 0x48));
  pCVar1 = *(CRIMObjectPool<CMemory> **)(this + 0x28);
  if (pCVar1 != this + 0x28) {
    *param_1 = (CMemory *)(pCVar1 + -0x20);
    lVar2 = *(longlong *)pCVar1;
    if ((*(CRIMObjectPool<CMemory> **)(lVar2 + 8) != pCVar1) ||
       (plVar3 = *(longlong **)(pCVar1 + 8), (CRIMObjectPool<CMemory> *)*plVar3 != pCVar1))
    goto LAB_1400146b2;
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    plVar3 = *(longlong **)(this + 0x40);
    pCVar6 = *param_1;
    pCVar7 = pCVar6 + 0x20;
    if ((CRIMObjectPool<CMemory> *)*plVar3 != this + 0x38) goto LAB_1400146b2;
    *(CRIMObjectPool<CMemory> **)pCVar7 = this + 0x38;
    *(longlong **)(pCVar6 + 0x28) = plVar3;
    *plVar3 = (longlong)pCVar7;
    *(CMemory **)(this + 0x40) = pCVar7;
    *(int *)(this + 0x18) = *(int *)(this + 0x18) + -1;
    *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
    *(undefined4 *)(*param_1 + 0x30) = 1;
    LOCK();
    *(int *)(*param_1 + 0xc) = *(int *)(*param_1 + 0xc) + 1;
    UNLOCK();
    SmartPtr<IWTSVirtualChannel>::operator=
              ((SmartPtr<IWTSVirtualChannel> *)(*param_1 + 0x38),(IWTSVirtualChannel *)this);
  }
  if (*param_1 == (CMemory *)0x0) {
    pCVar6 = (CMemory *)ExAllocatePoolWithTag(0x200,0x78,0x6c6d6952);
    if (pCVar6 == (CMemory *)0x0) {
      *param_1 = (CMemory *)0x0;
      lVar5 = -0x7ff8fff2;
    }
    else {
      *(undefined4 *)(pCVar6 + 8) = 0;
      *(undefined ***)pCVar6 = &CImplIUnknown<IUnknown>::_vftable_;
      *(undefined4 *)(pCVar6 + 0xc) = 0;
      *(undefined4 *)(pCVar6 + 0x10) = 0xc001d00d;
      *(undefined8 *)(pCVar6 + 0x38) = 0;
      *(undefined ***)pCVar6 = &CMemory::_vftable__for__CImplIUnknown<IUnknown>__;
      *(undefined ***)(pCVar6 + 0x18) = &CMemory::_vftable__for__CRIMPooledUnknown__;
      *(undefined8 *)(pCVar6 + 0x50) = 0;
      *(undefined4 *)(pCVar6 + 0x58) = 0;
      *(undefined8 *)(pCVar6 + 0x60) = 0;
      *(undefined8 *)(pCVar6 + 0x68) = 0;
      *(undefined4 *)(pCVar6 + 0x70) = 0;
      *param_1 = pCVar6;
      LOCK();
      *(int *)(pCVar6 + 0xc) = *(int *)(pCVar6 + 0xc) + 1;
      UNLOCK();
      *(undefined4 *)(*param_1 + 0x30) = 1;
      SmartPtr<IWTSVirtualChannel>::operator=
                ((SmartPtr<IWTSVirtualChannel> *)(*param_1 + 0x38),(IWTSVirtualChannel *)this);
      LOCK();
      *(int *)(*param_1 + 0xc) = *(int *)(*param_1 + 0xc) + 1;
      UNLOCK();
      plVar3 = *(longlong **)(this + 0x40);
      pCVar6 = *param_1;
      pCVar7 = pCVar6 + 0x20;
      if ((CRIMObjectPool<CMemory> *)*plVar3 != this + 0x38) {
LAB_1400146b2:
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        lVar5 = (*pcVar4)();
        return lVar5;
      }
      *(CRIMObjectPool<CMemory> **)pCVar7 = this + 0x38;
      *(longlong **)(pCVar6 + 0x28) = plVar3;
      *plVar3 = (longlong)pCVar7;
      *(CMemory **)(this + 0x40) = pCVar7;
      *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
    }
  }
  ExclusiveLock::~ExclusiveLock(local_res8);
  return lVar5;
}



===== Grow @ 1400146c0 =====

/* public: long __cdecl CMemory::Grow(unsigned long) __ptr64 */

long __thiscall CMemory::Grow(CMemory *this,ulong param_1)

{
  int iVar1;
  long lVar2;
  void *_Dst;
  
  iVar1 = *(int *)(this + 0x70);
  _Dst = (void *)ExAllocatePoolWithTag(0x200,iVar1 + param_1,0x72447244);
  if (_Dst == (void *)0x0) {
    lVar2 = -0x7ff8fff2;
  }
  else {
    *(ulong *)(this + 0x70) = iVar1 + param_1;
    if (*(void **)(this + 0x50) != (void *)0x0) {
      memmove(_Dst,*(void **)(this + 0x50),
              (ulonglong)(uint)(*(int *)(this + 0x68) + *(int *)(this + 0x58)));
      operator_delete(*(void **)(this + 0x50));
    }
    *(ulong *)(this + 0x68) = *(int *)(this + 0x68) + param_1;
    *(longlong *)(this + 0x60) = (longlong)*(int *)(this + 0x58) + (longlong)_Dst;
    lVar2 = 0;
    *(void **)(this + 0x50) = _Dst;
  }
  return lVar2;
}



===== Initialize @ 140014768 =====

/* public: long __cdecl CMessage::Initialize(class CRIMStream * __ptr64,unsigned long,unsigned
   long,class CMemory * __ptr64) __ptr64 */

long __thiscall
CMessage::Initialize
          (CMessage *this,CRIMStream *param_1,ulong param_2,ulong param_3,CMemory *param_4)

{
  long lVar1;
  
  if ((*(CRIMObjectPool<class_CMemory> **)(this + 0x50) == (CRIMObjectPool<class_CMemory> *)0x0) &&
     (lVar1 = CRIMObjectPool<CMemory>::CreateInstance
                        ((uint)this,(CRIMObjectPool<class_CMemory> **)(this + 0x50)), lVar1 < 0)) {
    return lVar1;
  }
  SmartPtr<IWTSVirtualChannel>::operator=
            ((SmartPtr<IWTSVirtualChannel> *)(this + 0x40),(IWTSVirtualChannel *)param_1);
  *(undefined4 *)(this + 0x58) = 0;
  *(ulong *)(this + 0x60) = param_3;
  *(undefined4 *)(this + 0x5c) = 4;
  SmartPtr<CMemory>::operator=((SmartPtr<CMemory> *)(this + 0x48),param_4);
  *(uint *)(this + 100) = (uint)(param_4 != (CMemory *)0x0);
  return 0;
}



===== ReceiveMessage @ 1400147f0 =====

/* public: virtual long __cdecl CRIMStreamStub::ReceiveMessage(unsigned long,class CMemory * __ptr64
   * __ptr64) __ptr64 */

long __thiscall CRIMStreamStub::ReceiveMessage(CRIMStreamStub *this,ulong param_1,CMemory **param_2)

{
  return -0x7fffbfff;
}



===== ReceiveIUnknown @ 140014800 =====

/* public: virtual long __cdecl CMessage::ReceiveIUnknown(struct IUnknown * __ptr64 * __ptr64,struct
   _GUID const & __ptr64,unsigned long) __ptr64 */

long __thiscall
CMessage::ReceiveIUnknown(CMessage *this,IUnknown **param_1,_GUID *param_2,ulong param_3)

{
  undefined1 auVar1 [16];
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  void *pvVar5;
  ulonglong uVar6;
  uint uVar7;
  char local_res20 [8];
  uint local_38 [4];
  
  uVar7 = 0;
  uVar6 = (ulonglong)param_3;
  local_38[0] = 0;
  if (param_3 == 0xffffffff) {
    local_res20[0] = '\0';
    lVar3 = ReceiveMemory(this,local_res20,1,1);
    if (lVar3 < 0) {
      return lVar3;
    }
    if (local_res20[0] != '\0') {
      *param_1 = (IUnknown *)0x0;
      return lVar3;
    }
    uVar6 = 1;
  }
  auVar1._8_8_ = 0;
  auVar1._0_8_ = uVar6;
  uVar4 = SUB168(ZEXT816(4) * auVar1,0);
  if (SUB168(ZEXT816(4) * auVar1,8) != 0) {
    uVar4 = 0xffffffffffffffff;
  }
  pvVar5 = (void *)ExAllocatePoolWithTag(0x200,uVar4,0x72447244);
  if (pvVar5 == (void *)0x0) {
    lVar3 = -0x7ff8fff2;
  }
  else {
    lVar3 = ReceiveMemory(this,local_38,4,4);
    uVar2 = local_38[0];
    if (((-1 < lVar3) &&
        (lVar3 = ReceiveMemory(this,pvVar5,(uint)uVar6 * 4,local_38[0] * 4), -1 < lVar3)) &&
       (uVar2 != 0)) {
      do {
        if (((uint)uVar6 <= uVar7) ||
           (lVar3 = CRIMObjManager::GetObjectFromId
                              (*(CRIMObjManager **)(*(longlong *)(this + 0x40) + 0xc0),
                               *(ulong *)((longlong)pvVar5 + (ulonglong)uVar7 * 4),param_2,
                               param_1 + uVar7), lVar3 < 0)) break;
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar2);
    }
    operator_delete(pvVar5);
  }
  return lVar3;
}



===== ReceiveLPSTR @ 140014940 =====

/* public: virtual long __cdecl CMessage::ReceiveLPSTR(char * __ptr64 * __ptr64,unsigned long)
   __ptr64 */

long __thiscall CMessage::ReceiveLPSTR(CMessage *this,char **param_1,ulong param_2)

{
  ulong uVar1;
  char *_Src;
  uint uVar2;
  long lVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  char **ppcVar9;
  uint local_res18 [2];
  longlong local_res20;
  
  uVar7 = (ulonglong)param_2;
  if (param_2 == 0xffffffff) {
    local_res18[0] = local_res18[0] & 0xffffff00;
    lVar3 = ReceiveMemory(this,local_res18,1,1);
    if (lVar3 < 0) {
      return lVar3;
    }
    if ((char)local_res18[0] != '\0') {
      *param_1 = (char *)0x0;
      return lVar3;
    }
    uVar7 = 1;
  }
  uVar6 = (uint)uVar7;
  memset(param_1,0,uVar7 << 3);
  lVar3 = 0;
  uVar8 = 0;
  local_res20 = *(longlong *)(*(longlong *)(this + 0x48) + 0x60);
  local_res18[0] = *(uint *)(*(longlong *)(this + 0x48) + 0x68);
  ppcVar9 = param_1;
  while( true ) {
    if (uVar6 <= uVar8) {
      return lVar3;
    }
    uVar2 = *(uint *)(this + 0x58);
    if (local_res18[0] == uVar2) break;
    _Src = (char *)(local_res20 + (ulonglong)uVar2);
    uVar4 = 0;
    if (local_res18[0] != uVar2) {
      pcVar5 = _Src;
      do {
        if (*pcVar5 == '\0') break;
        uVar4 = uVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (uVar4 < local_res18[0] - uVar2);
      if (uVar4 == local_res18[0] - uVar2) break;
    }
    uVar1 = uVar4 + 1;
    lVar3 = RIM_USER_ALLOC(ppcVar9,uVar1);
    if (lVar3 < 0) goto LAB_140014a35;
    memmove(*ppcVar9,_Src,(ulonglong)uVar1);
    *(ulong *)(this + 0x58) = *(int *)(this + 0x58) + uVar1;
    uVar8 = uVar8 + 1;
    ppcVar9 = ppcVar9 + 1;
  }
  lVar3 = -0x7fff0001;
LAB_140014a35:
  if (uVar6 == 0xffffffff) {
    return lVar3;
  }
  if (uVar6 == 0) {
    return lVar3;
  }
  do {
    if (*param_1 != (char *)0x0) {
      RIM_USER_FREE(*param_1);
      *param_1 = (char *)0x0;
    }
    param_1 = param_1 + 1;
    uVar7 = uVar7 - 1;
  } while (uVar7 != 0);
  return lVar3;
}



===== ReceiveLPWSTR @ 140014a80 =====

/* public: virtual long __cdecl CMessage::ReceiveLPWSTR(unsigned short * __ptr64 * __ptr64,unsigned
   long) __ptr64 */

long __thiscall CMessage::ReceiveLPWSTR(CMessage *this,ushort **param_1,ulong param_2)

{
  short *_Src;
  long lVar1;
  uint uVar2;
  uint uVar3;
  short *psVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  ushort **ppuVar8;
  ulong uVar9;
  uint local_res18 [2];
  longlong local_res20;
  
  uVar6 = (ulonglong)param_2;
  if (param_2 == 0xffffffff) {
    local_res18[0] = local_res18[0] & 0xffffff00;
    lVar1 = ReceiveMemory(this,local_res18,1,1);
    if (lVar1 < 0) {
      return lVar1;
    }
    if ((char)local_res18[0] != '\0') {
      *param_1 = (ushort *)0x0;
      return lVar1;
    }
    uVar6 = 1;
  }
  uVar5 = (uint)uVar6;
  memset(param_1,0,uVar6 << 3);
  lVar1 = 0;
  uVar7 = 0;
  local_res20 = *(longlong *)(*(longlong *)(this + 0x48) + 0x60);
  local_res18[0] = *(uint *)(*(longlong *)(this + 0x48) + 0x68);
  ppuVar8 = param_1;
  while( true ) {
    uVar3 = 0;
    if (uVar5 <= uVar7) {
      return lVar1;
    }
    uVar2 = local_res18[0] - *(uint *)(this + 0x58) >> 1;
    if (uVar2 == 0) break;
    _Src = (short *)(local_res20 + (ulonglong)*(uint *)(this + 0x58));
    if (uVar2 != 0) {
      psVar4 = _Src;
      do {
        if (*psVar4 == 0) break;
        uVar3 = uVar3 + 1;
        psVar4 = psVar4 + 1;
      } while (uVar3 < uVar2);
      if (uVar3 == uVar2) break;
    }
    uVar9 = uVar3 * 2 + 2;
    lVar1 = RIM_USER_ALLOC(ppuVar8,uVar9);
    if (lVar1 < 0) goto LAB_140014b87;
    memmove(*ppuVar8,_Src,(ulonglong)uVar9);
    *(ulong *)(this + 0x58) = *(int *)(this + 0x58) + uVar9;
    uVar7 = uVar7 + 1;
    ppuVar8 = ppuVar8 + 1;
  }
  lVar1 = -0x7fff0001;
LAB_140014b87:
  if (uVar5 == 0xffffffff) {
    return lVar1;
  }
  if (uVar5 == 0) {
    return lVar1;
  }
  do {
    if (*param_1 != (ushort *)0x0) {
      RIM_USER_FREE(*param_1);
      *param_1 = (ushort *)0x0;
    }
    param_1 = param_1 + 1;
    uVar6 = uVar6 - 1;
  } while (uVar6 != 0);
  return lVar1;
}



===== ReceiveMemory @ 140014bc8 =====

/* private: long __cdecl CMessage::ReceiveMemory(void * __ptr64,unsigned long,unsigned long) __ptr64
    */

long __thiscall CMessage::ReceiveMemory(CMessage *this,void *param_1,ulong param_2,ulong param_3)

{
  uint uVar1;
  long lVar2;
  
  uVar1 = *(uint *)(this + 0x58);
  lVar2 = 0;
  if (uVar1 + param_3 < uVar1) {
    lVar2 = -0x7ff8fdea;
  }
  else if ((*(uint *)(*(longlong *)(this + 0x48) + 0x68) < uVar1 + param_3) || (param_2 < param_3))
  {
    lVar2 = -0x7fff0001;
  }
  else {
    memmove(param_1,(void *)((ulonglong)uVar1 + *(longlong *)(*(longlong *)(this + 0x48) + 0x60)),
            (ulonglong)param_3);
    *(ulong *)(this + 0x58) = *(int *)(this + 0x58) + param_3;
  }
  return lVar2;
}



===== ReleaseResources @ 140014c40 =====

/* public: virtual void __cdecl CMessage::ReleaseResources(void) __ptr64 */

void __thiscall CMessage::ReleaseResources(CMessage *this)

{
  CImplIUnknownPool<IMessage> *this_00;
  
  if ((*(CRIMStream **)(this + 0x28) != (CRIMStream *)0x0) && (*(int *)(this + 0x4c) == 0)) {
    CRIMStream::ReleaseMessageId(*(CRIMStream **)(this + 0x28),*(ulong *)(this + 0x48));
  }
  this_00 = *(CImplIUnknownPool<IMessage> **)(this + 0x30);
  *(undefined8 *)(this + 0x30) = 0;
  if (this_00 != (CImplIUnknownPool<IMessage> *)0x0) {
    CImplIUnknownPool<IMessage>::Release(this_00);
  }
  SmartPtr<IWTSVirtualChannel>::operator=
            ((SmartPtr<IWTSVirtualChannel> *)(this + 0x28),(IWTSVirtualChannel *)0x0);
  return;
}



===== RemoveIUnknown @ 140014ca0 =====

/* public: virtual long __cdecl CMessage::RemoveIUnknown(unsigned long,int) __ptr64 */

long __thiscall CMessage::RemoveIUnknown(CMessage *this,ulong param_1,int param_2)

{
  long lVar1;
  
  lVar1 = CRIMObjManager::RemoveObject
                    (*(CRIMObjManager **)(*(longlong *)(this + 0x40) + 0xc0),param_1,param_2);
  return lVar1;
}



===== WriteIUnknown @ 140014cc0 =====

/* public: virtual long __cdecl CMessage::WriteIUnknown(struct IUnknown * __ptr64 * __ptr64,struct
   _GUID const & __ptr64,unsigned long) __ptr64 */

long __thiscall
CMessage::WriteIUnknown(CMessage *this,IUnknown **param_1,_GUID *param_2,ulong param_3)

{
  ulong uVar1;
  long lVar2;
  undefined8 uVar3;
  void *pvVar4;
  ulonglong uVar5;
  ulong local_res20 [2];
  
  pvVar4 = (void *)0x0;
  local_res20[0] = param_3;
  if (param_3 == 0xffffffff) {
    local_res20[0] = CONCAT31(0xffffff,*param_1 == (IUnknown *)0x0);
    lVar2 = WriteMemory(this,local_res20,1);
    if (lVar2 < 0) {
      return lVar2;
    }
    if (*param_1 == (IUnknown *)0x0) {
      return lVar2;
    }
    local_res20[0] = 1;
  }
  if (param_1 == (IUnknown **)0x0) {
    local_res20[0] = 0;
    goto LAB_140014d1f;
  }
  if (local_res20[0] == 1) {
    if (*param_1 == (IUnknown *)0x0) {
      local_res20[0] = 0;
      goto LAB_140014d89;
    }
  }
  else {
LAB_140014d89:
    if (local_res20[0] == 0) goto LAB_140014d1f;
  }
  uVar1 = local_res20[0];
  uVar3 = SUB168(ZEXT816(4) * ZEXT416(local_res20[0]),0);
  if (SUB168(ZEXT816(4) * ZEXT416(local_res20[0]),8) != 0) {
    uVar3 = 0xffffffffffffffff;
  }
  pvVar4 = (void *)ExAllocatePoolWithTag(0x200,uVar3,0x72447244);
  if (pvVar4 == (void *)0x0) {
    return -0x7ff8fff2;
  }
  for (uVar5 = 0; (uint)uVar5 < uVar1; uVar5 = (ulonglong)((uint)uVar5 + 1)) {
    lVar2 = CRIMObjManager::GetIdFromObject
                      (*(CRIMObjManager **)(*(longlong *)(this + 0x40) + 0xc0),param_1[uVar5],
                       param_2,(ulong *)((longlong)pvVar4 + uVar5 * 4));
    if (lVar2 < 0) goto LAB_140014d58;
  }
LAB_140014d1f:
  lVar2 = WriteMemory(this,local_res20,4);
  if ((-1 < lVar2) && (local_res20[0] != 0)) {
    lVar2 = WriteMemory(this,pvVar4,local_res20[0] << 2);
  }
  if (pvVar4 != (void *)0x0) {
LAB_140014d58:
    operator_delete(pvVar4);
  }
  return lVar2;
}



===== WriteLPSTR @ 140014e10 =====

/* public: virtual long __cdecl CMessage::WriteLPSTR(char * __ptr64 * __ptr64,unsigned long) __ptr64
    */

long __thiscall CMessage::WriteLPSTR(CMessage *this,char **param_1,ulong param_2)

{
  long lVar1;
  uint uVar2;
  longlong lVar3;
  undefined1 local_res18 [8];
  
  if (param_2 == 0xffffffff) {
    local_res18[0] = *param_1 == (char *)0x0;
    lVar1 = WriteMemory(this,local_res18,1);
    if (lVar1 < 0) {
      return lVar1;
    }
    if (*param_1 == (char *)0x0) {
      return lVar1;
    }
    param_2 = 1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    if (param_2 == 0) {
      return 0;
    }
  }
  while( true ) {
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while ((*param_1)[lVar3] != '\0');
    lVar1 = WriteMemory(this,*param_1,(int)lVar3 + 1);
    if (lVar1 < 0) break;
    uVar2 = uVar2 + 1;
    param_1 = param_1 + 1;
    if (param_2 <= uVar2) {
      return lVar1;
    }
  }
  return lVar1;
}



===== WriteLPWSTR @ 140014eb0 =====

/* public: virtual long __cdecl CMessage::WriteLPWSTR(unsigned short * __ptr64 * __ptr64,unsigned
   long) __ptr64 */

long __thiscall CMessage::WriteLPWSTR(CMessage *this,ushort **param_1,ulong param_2)

{
  long lVar1;
  uint uVar2;
  longlong lVar3;
  undefined1 local_res18 [16];
  
  if (param_2 == 0xffffffff) {
    local_res18[0] = *param_1 == (ushort *)0x0;
    lVar1 = WriteMemory(this,local_res18,1);
    if (lVar1 < 0) {
      return lVar1;
    }
    if (*param_1 == (ushort *)0x0) {
      return lVar1;
    }
    param_2 = 1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    if (param_2 == 0) {
      return 0;
    }
  }
  while( true ) {
    lVar3 = -1;
    do {
      lVar3 = lVar3 + 1;
    } while ((*param_1)[lVar3] != 0);
    lVar1 = WriteMemory(this,*param_1,(int)lVar3 * 2 + 2);
    if (lVar1 < 0) break;
    uVar2 = uVar2 + 1;
    param_1 = param_1 + 1;
    if (param_2 <= uVar2) {
      return lVar1;
    }
  }
  return lVar1;
}



===== WriteMemory @ 140014f4c =====

/* private: long __cdecl CMessage::WriteMemory(void * __ptr64,unsigned long) __ptr64 */

long __thiscall CMessage::WriteMemory(CMessage *this,void *param_1,ulong param_2)

{
  CMessage *pCVar1;
  CMemory *pCVar2;
  long lVar3;
  uint uVar4;
  longlong lVar5;
  
  pCVar1 = this + 0x48;
  if (*(CMemory **)pCVar1 == (CMemory *)0x0) {
    CRIMObjectPool<CMemory>::GetPooledObject
              (*(CRIMObjectPool<CMemory> **)(this + 0x50),(CMemory **)pCVar1,param_2);
    pCVar2 = *(CMemory **)pCVar1;
    if (pCVar2 == (CMemory *)0x0) {
      return -0x7ff8fff2;
    }
    uVar4 = *(int *)(this + 0x5c) + 4;
    if ((*(uint *)(pCVar2 + 0x70) < *(int *)(this + 0x5c) + 0x104U) &&
       (lVar3 = CMemory::Grow(pCVar2,(uVar4 - *(uint *)(pCVar2 + 0x70)) + 0x100), lVar3 < 0)) {
      return lVar3;
    }
    *(ulonglong *)(pCVar2 + 0x60) = (ulonglong)uVar4 + *(longlong *)(pCVar2 + 0x50);
    *(uint *)(pCVar2 + 0x58) = uVar4;
    *(undefined4 *)(pCVar2 + 0x68) = 0x100;
  }
  pCVar2 = *(CMemory **)pCVar1;
  lVar5 = *(longlong *)(pCVar2 + 0x60);
  if (*(uint *)(pCVar2 + 0x68) < *(int *)(this + 0x58) + param_2) {
    lVar3 = CMemory::Grow(pCVar2,(param_2 & 0xfffff000) + 0x1000);
    if (lVar3 < 0) {
      return lVar3;
    }
    lVar5 = *(longlong *)(*(longlong *)(this + 0x48) + 0x60);
  }
  memmove((void *)((ulonglong)*(uint *)(this + 0x58) + lVar5),param_1,(ulonglong)param_2);
  *(ulong *)(this + 0x58) = *(int *)(this + 0x58) + param_2;
  return 0;
}



===== CObjectEntry @ 140015054 =====

/* public: __cdecl CRIMObjManager::CObjectEntry::CObjectEntry(struct IUnknown * __ptr64,class
   CRIMStream * __ptr64,struct _GUID const & __ptr64,struct IRIMStub * __ptr64) __ptr64 */

CObjectEntry * __thiscall
CRIMObjManager::CObjectEntry::CObjectEntry
          (CObjectEntry *this,IUnknown *param_1,CRIMStream *param_2,_GUID *param_3,IRIMStub *param_4
          )

{
  undefined8 uVar1;
  
  *(IUnknown **)this = param_1;
  SmartPtr<IRIMStub>::SmartPtr<IRIMStub>((SmartPtr<IRIMStub> *)(this + 8),(IRIMStream *)param_2);
  SmartPtr<IRIMStub>::SmartPtr<IRIMStub>((SmartPtr<IRIMStub> *)(this + 0x10),(IRIMStream *)param_4);
  uVar1 = *(undefined8 *)(param_3 + 8);
  *(undefined8 *)(this + 0x18) = *(undefined8 *)param_3;
  *(undefined8 *)(this + 0x20) = uVar1;
  return this;
}



===== CObjectEntry @ 1400150a0 =====

/* public: __cdecl CRIMObjManager::CObjectEntry::CObjectEntry(void) __ptr64 */

CObjectEntry * __thiscall CRIMObjManager::CObjectEntry::CObjectEntry(CObjectEntry *this)

{
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  return this;
}



===== CRIMStreamProxy @ 1400150b8 =====

/* public: __cdecl CRIMStreamProxy::CRIMStreamProxy(class CRIMObjManager * __ptr64,unsigned
   long,class SmartPtr<class CRIMObjectPool<class CMessage> >) __ptr64 */

CRIMStreamProxy * __thiscall
CRIMStreamProxy::CRIMStreamProxy
          (CRIMStreamProxy *this,undefined8 param_1,undefined4 param_2,
          SmartPtr<class_CRIMObjectPool<class_CMessage>_> *param_4)

{
  CRIMStreamProxy *pCVar1;
  undefined8 uVar2;
  SmartPtr<CRIMObjectPoolBase> local_res8 [8];
  
  uVar2 = SmartPtr<CRIMObjectPoolBase>::SmartPtr<CRIMObjectPoolBase>(local_res8,param_4);
  CRIMStream::CRIMStream((CRIMStream *)this,param_1,param_2,uVar2);
  *(undefined ***)this = &_vftable_;
  KernelResource::KernelResource((KernelResource *)(this + 200),"CRIMStreamProxy");
  *(undefined4 *)(this + 0x168) = 1;
  pCVar1 = this + 0x148;
  *(CRIMStreamProxy **)(this + 0x150) = pCVar1;
  *(CRIMStreamProxy **)pCVar1 = pCVar1;
  pCVar1 = this + 0x158;
  *(CRIMStreamProxy **)(this + 0x160) = pCVar1;
  *(CRIMStreamProxy **)pCVar1 = pCVar1;
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)param_4);
  return this;
}



===== CRIMStreamStub @ 140015160 =====

/* public: __cdecl CRIMStreamStub::CRIMStreamStub(class CRIMObjManager * __ptr64,struct IRIMStub *
   __ptr64,unsigned long,class SmartPtr<class CRIMObjectPool<class CMessage> >) __ptr64 */

CRIMStreamStub * __thiscall
CRIMStreamStub::CRIMStreamStub
          (CRIMStreamStub *this,undefined8 param_1,IRIMStream *param_2,undefined4 param_3,
          SmartPtr<class_CRIMObjectPool<class_CMessage>_> *param_5)

{
  undefined8 uVar1;
  SmartPtr<CRIMObjectPoolBase> local_res8 [8];
  
  uVar1 = SmartPtr<CRIMObjectPoolBase>::SmartPtr<CRIMObjectPoolBase>(local_res8,param_5);
  CRIMStream::CRIMStream((CRIMStream *)this,param_1,param_3,uVar1);
  *(undefined ***)this = &_vftable_;
  SmartPtr<IRIMStub>::SmartPtr<IRIMStub>((SmartPtr<IRIMStub> *)(this + 200),param_2);
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)param_5);
  return this;
}



===== ~CProxyIUnknown<IUnknown> @ 1400151e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual __cdecl CProxyIUnknown<struct IUnknown>::~CProxyIUnknown<struct IUnknown>(void)
   __ptr64 */

void __thiscall CProxyIUnknown<IUnknown>::~CProxyIUnknown<IUnknown>(CProxyIUnknown<IUnknown> *this)

{
  SmartPtr<CRIMStreamStub> *this_00;
  int iVar1;
  undefined4 local_res8 [2];
  longlong *local_res10;
  
  local_res10 = (longlong *)0x0;
  *(undefined ***)this = &_vftable_;
  this_00 = (SmartPtr<CRIMStreamStub> *)(this + 0x18);
  iVar1 = (**(code **)(**(longlong **)this_00 + 0x18))(*(longlong **)this_00,&local_res10);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_res10 + 0x40))(local_res10,1);
    if (-1 < iVar1) {
      local_res8[0] = 0;
      (**(code **)(**(longlong **)this_00 + 0x20))(*(longlong **)this_00,local_res8);
      iVar1 = (**(code **)(*local_res10 + 0x188))(local_res10,local_res8[0],0);
      if (-1 < iVar1) {
        (**(code **)(*local_res10 + 0x20))();
      }
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res10);
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>(this_00);
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &CImplIUnknown<IUnknown>::_vftable_;
  return;
}



===== ~CCapabilitiesNegotiator @ 1400152b8 =====

/* public: virtual __cdecl CRIMObjManager::CCapabilitiesNegotiator::~CCapabilitiesNegotiator(void)
   __ptr64 */

void __thiscall
CRIMObjManager::CCapabilitiesNegotiator::~CCapabilitiesNegotiator(CCapabilitiesNegotiator *this)

{
  SmartPtr<CRIMObjManager>::~SmartPtr<CRIMObjManager>((SmartPtr<CRIMObjManager> *)(this + 0x18));
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &CImplIUnknown<IRIMCapabilitiesNegotiator>::_vftable_;
  return;
}



===== ~CRIMStreamProxy @ 1400152e8 =====

/* public: virtual __cdecl CRIMStreamProxy::~CRIMStreamProxy(void) __ptr64 */

void __thiscall CRIMStreamProxy::~CRIMStreamProxy(CRIMStreamProxy *this)

{
  *(undefined ***)this = &_vftable_;
  KernelResource::~KernelResource((KernelResource *)(this + 200));
  CRIMStream::~CRIMStream((CRIMStream *)this);
  return;
}



===== ~CRIMStreamStub @ 14001531c =====

/* public: virtual __cdecl CRIMStreamStub::~CRIMStreamStub(void) __ptr64 */

void __thiscall CRIMStreamStub::~CRIMStreamStub(CRIMStreamStub *this)

{
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)(this + 200));
  CRIMStream::~CRIMStream((CRIMStream *)this);
  return;
}



===== operator= @ 140015348 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: class CRIMObjManager::CObjectEntry & __ptr64 __cdecl
   CRIMObjManager::CObjectEntry::operator=(class CRIMObjManager::CObjectEntry & __ptr64) __ptr64 */

CObjectEntry * __thiscall
CRIMObjManager::CObjectEntry::operator=(CObjectEntry *this,CObjectEntry *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 uVar3;
  
  *(undefined8 *)this = *(undefined8 *)param_1;
  SmartPtr<IWTSVirtualChannel>::operator=
            ((SmartPtr<IWTSVirtualChannel> *)(this + 8),*(IWTSVirtualChannel **)(param_1 + 8));
  plVar1 = *(longlong **)(param_1 + 0x10);
  plVar2 = *(longlong **)(this + 0x10);
  *(longlong **)(this + 0x10) = plVar1;
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 8))();
  }
  if (plVar2 != (longlong *)0x0) {
    (**(code **)(*plVar2 + 0x10))(plVar2);
  }
  uVar3 = *(undefined8 *)(param_1 + 0x20);
  *(undefined8 *)(this + 0x18) = *(undefined8 *)(param_1 + 0x18);
  *(undefined8 *)(this + 0x20) = uVar3;
  return this;
}



===== `scalar_deleting_destructor' @ 1400153d0 =====

/* public: virtual void * __ptr64 __cdecl CProxyIUnknown<struct IUnknown>::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CProxyIUnknown<IUnknown>::_scalar_deleting_destructor_(CProxyIUnknown<IUnknown> *this,uint param_1)

{
  ~CProxyIUnknown<IUnknown>(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `vector_deleting_destructor' @ 140015420 =====

/* public: virtual void * __ptr64 __cdecl CRIMObjManager::CCapabilitiesNegotiator::`vector deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CRIMObjManager::CCapabilitiesNegotiator::_vector_deleting_destructor_
          (CCapabilitiesNegotiator *this,uint param_1)

{
  ~CCapabilitiesNegotiator(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140015470 =====

/* public: virtual void * __ptr64 __cdecl CRIMStreamProxy::`scalar deleting destructor'(unsigned
   int) __ptr64 */

void * __thiscall CRIMStreamProxy::_scalar_deleting_destructor_(CRIMStreamProxy *this,uint param_1)

{
  ~CRIMStreamProxy(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 1400154c0 =====

/* public: virtual void * __ptr64 __cdecl CRIMStreamStub::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall CRIMStreamStub::_scalar_deleting_destructor_(CRIMStreamStub *this,uint param_1)

{
  ~CRIMStreamStub(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== AddAt @ 140015504 =====

/* public: int __cdecl DynArray<class CRIMObjManager::CObjectEntry,unsigned long>::AddAt(unsigned
   long,class CRIMObjManager::CObjectEntry & __ptr64) __ptr64 */

int __thiscall
DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::AddAt
          (DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *this,ulong param_1,
          CObjectEntry *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = Grow(this,param_1);
  iVar2 = 0;
  if (iVar1 != 0) {
    if (*(uint *)(this + 4) <= param_1) {
      *(ulong *)(this + 4) = param_1 + 1;
    }
    CRIMObjManager::CObjectEntry::operator=
              ((CObjectEntry *)(*(longlong *)(this + 8) + (ulonglong)param_1 * 0x28),param_2);
    iVar2 = 1;
  }
  return iVar2;
}



===== AddObject @ 140015560 =====

/* public: virtual long __cdecl CRIMObjManager::AddObject(struct IUnknown * __ptr64,struct _GUID
   const & __ptr64,unsigned long) __ptr64 */

long __thiscall
CRIMObjManager::AddObject(CRIMObjManager *this,IUnknown *param_1,_GUID *param_2,ulong param_3)

{
  long lVar1;
  
  lVar1 = AddObjectInternal(this,*(_func_long__GUID_ptr_IUnknown_ptr_IRIMStub_ptr_ptr **)
                                  (this + 200),param_1,param_2,param_3);
  return lVar1;
}



===== AddObjectInternal @ 140015588 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl CRIMObjManager::AddObjectInternal(long (__cdecl*)(struct _GUID const &
   __ptr64,struct IUnknown * __ptr64,struct IRIMStub * __ptr64 * __ptr64),struct IUnknown *
   __ptr64,struct _GUID const & __ptr64,unsigned long) __ptr64 */

long __thiscall
CRIMObjManager::AddObjectInternal
          (CRIMObjManager *this,_func_long__GUID_ptr_IUnknown_ptr_IRIMStub_ptr_ptr *param_1,
          IUnknown *param_2,_GUID *param_3,ulong param_4)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  CRIMStreamStub *pCVar4;
  CRIMStream *pCVar5;
  uint uVar6;
  undefined1 auStackY_c8 [32];
  IRIMStub *local_98;
  SmartPtr<CRIMObjectPoolBase> local_90 [8];
  CRIMStream *local_88;
  CObjectEntry local_80 [40];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_c8;
  uVar1 = *(uint *)(this + 0xd8);
  local_88 = (CRIMStream *)0x0;
  local_98 = (IRIMStub *)0x0;
  uVar6 = uVar1 << 0x1f | param_4;
  lVar2 = CreateStubObject(this,param_1,param_2,param_3,uVar6,&local_98);
  if (-1 < lVar2) {
    pCVar4 = (CRIMStreamStub *)ExAllocatePoolWithTag(0x200,0xd0,0x6c6d6952);
    if (pCVar4 != (CRIMStreamStub *)0x0) {
      SmartPtr<CRIMObjectPoolBase>::SmartPtr<CRIMObjectPoolBase>
                (local_90,(SmartPtr<class_CRIMObjectPool<class_CMessage>_> *)(this + 0x1a0));
      pCVar5 = (CRIMStream *)CRIMStreamStub::CRIMStreamStub(pCVar4,this,local_98,uVar6);
      local_88 = pCVar5;
      if (pCVar5 != (CRIMStream *)0x0) {
        (**(code **)(*(longlong *)pCVar5 + 8))(pCVar5);
        lVar2 = (**(code **)(*(longlong *)pCVar5 + 0x30))(pCVar5);
        if (-1 < lVar2) {
          CObjectEntry::CObjectEntry(local_80,param_2,pCVar5,param_3,local_98);
          ExclusiveLock::ExclusiveLock((ExclusiveLock *)local_90,(GenericLock *)(this + 0x48));
          iVar3 = DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::AddAt
                            ((DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *)
                             (this + (ulonglong)(uVar1 & 1) * 0x10 + 0x18),param_4,local_80);
          if (iVar3 == 0) {
            lVar2 = -0x7ff8fb70;
          }
          else {
            lVar2 = 0;
          }
          ExclusiveLock::~ExclusiveLock((ExclusiveLock *)local_90);
          CObjectEntry::~CObjectEntry(local_80);
        }
        goto LAB_1400156de;
      }
    }
    lVar2 = -0x7ff8fff2;
  }
LAB_1400156de:
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_98);
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_88);
  return lVar2;
}



===== CloseChannel @ 14001571c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl CRIMObjManager::CloseChannel(void) __ptr64 */

long __thiscall CRIMObjManager::CloseChannel(CRIMObjManager *this)

{
  uint uVar1;
  DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *this_00;
  int iVar2;
  long lVar3;
  uint uVar4;
  ulong uVar5;
  CRIMObjManager **ppCVar6;
  undefined1 auStack_c8 [32];
  longlong *local_a8;
  ExclusiveLock local_a0 [8];
  undefined8 local_98;
  longlong *plStack_90;
  longlong *local_88;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  CRIMObjManager *local_48 [3];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_c8;
  local_60 = 0;
  local_48[0] = this + 0x18;
  ppCVar6 = local_48;
  local_48[1] = this + 0x28;
  local_48[2] = this + 0x38;
  uVar4 = 0;
  local_70 = 0;
  uStack_68 = 0;
  do {
    ExclusiveLock::ExclusiveLock((ExclusiveLock *)&local_a8,(GenericLock *)(this + 0x48));
    this_00 = (DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *)*ppCVar6;
    uVar5 = 0;
    local_88 = (longlong *)0x0;
    local_98 = 0;
    plStack_90 = (longlong *)0x0;
    uVar1 = *(uint *)(this_00 + 4);
    if (uVar1 != 0) {
      do {
        iVar2 = DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::GetAt
                          (this_00,uVar5,(CObjectEntry *)&local_98);
        if (iVar2 != 0) {
          if (plStack_90 != (longlong *)0x0) {
            (**(code **)(*plStack_90 + 0x48))();
          }
          if (local_88 != (longlong *)0x0) {
            (**(code **)(*local_88 + 0x28))();
          }
        }
        DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::AddAt
                  (this_00,uVar5,(CObjectEntry *)&local_70);
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar1);
    }
    CObjectEntry::~CObjectEntry((CObjectEntry *)&local_98);
    ExclusiveLock::~ExclusiveLock((ExclusiveLock *)&local_a8);
    uVar4 = uVar4 + 1;
    ppCVar6 = ppCVar6 + 1;
  } while (uVar4 < 3);
  local_a8 = (longlong *)0x0;
  ExclusiveLock::ExclusiveLock(local_a0,(GenericLock *)(this + 0x110));
  SmartPtr<IWTSVirtualChannel>::operator=
            ((SmartPtr<IWTSVirtualChannel> *)&local_a8,*(IWTSVirtualChannel **)(this + 0x100));
  ExclusiveLock::~ExclusiveLock(local_a0);
  if (local_a8 == (longlong *)0x0) {
    lVar3 = -0x7ff8f736;
  }
  else {
    lVar3 = (**(code **)(*local_a8 + 0x20))();
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_a8);
  CObjectEntry::~CObjectEntry((CObjectEntry *)&local_70);
  return lVar3;
}



===== CreateProxyObject @ 1400158ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CRIMObjManager::CreateProxyObject(long (__cdecl*)(struct _GUID const &
   __ptr64,struct IRIMStream * __ptr64,struct IUnknown * __ptr64 * __ptr64),struct _GUID const &
   __ptr64,unsigned long,class CRIMStream * __ptr64 * __ptr64,struct IUnknown * __ptr64 * __ptr64)
   __ptr64 */

long __thiscall
CRIMObjManager::CreateProxyObject
          (CRIMObjManager *this,_func_long__GUID_ptr_IRIMStream_ptr_IUnknown_ptr_ptr *param_1,
          _GUID *param_2,ulong param_3,CRIMStream **param_4,IUnknown **param_5)

{
  IRIMStream *pIVar1;
  int iVar2;
  CRIMStreamProxy *pCVar3;
  undefined8 uVar4;
  IWTSVirtualChannel *pIVar5;
  longlong lVar6;
  IUnknown *pIVar7;
  IRIMStream *local_28;
  SmartPtr<CRIMObjectPoolBase> local_20 [8];
  
  local_28 = (IRIMStream *)0x0;
  pCVar3 = (CRIMStreamProxy *)ExAllocatePoolWithTag(0x200,0x170,0x6c6d6952);
  pIVar5 = (IWTSVirtualChannel *)0x0;
  if (pCVar3 != (CRIMStreamProxy *)0x0) {
    uVar4 = SmartPtr<CRIMObjectPoolBase>::SmartPtr<CRIMObjectPoolBase>
                      (local_20,(SmartPtr<class_CRIMObjectPool<class_CMessage>_> *)(this + 0x1a0));
    pIVar5 = (IWTSVirtualChannel *)CRIMStreamProxy::CRIMStreamProxy(pCVar3,this,param_3,uVar4);
  }
  SmartPtr<IWTSVirtualChannel>::operator=((SmartPtr<IWTSVirtualChannel> *)&local_28,pIVar5);
  pIVar1 = local_28;
  if (local_28 == (IRIMStream *)0x0) {
LAB_140015937:
    iVar2 = -0x7ff8fff2;
  }
  else {
    iVar2 = (**(code **)(*(longlong *)local_28 + 0x30))(local_28);
    if (iVar2 < 0) goto LAB_140015a15;
    lVar6 = -*(longlong *)param_2;
    if (lVar6 == 0) {
      lVar6 = 0x46000000000000c0 - *(longlong *)(param_2 + 8);
    }
    if (lVar6 == 0) {
      pIVar7 = (IUnknown *)ExAllocatePoolWithTag(0x200,0x20,0x6c6d6952);
      if (pIVar7 == (IUnknown *)0x0) {
        *param_5 = (IUnknown *)0x0;
        goto LAB_140015937;
      }
      *(undefined4 *)(pIVar7 + 8) = 0;
      *(undefined4 *)(pIVar7 + 0x10) = 0xc001d00d;
      *(undefined ***)pIVar7 = &CImplIUnknown<IUnknown>::_vftable_;
      *(undefined4 *)(pIVar7 + 0xc) = 0;
      *(undefined ***)pIVar7 = &CProxyIUnknown<IUnknown>::_vftable_;
      SmartPtr<IRIMStub>::SmartPtr<IRIMStub>((SmartPtr<IRIMStub> *)(pIVar7 + 0x18),pIVar1);
      *param_5 = pIVar7;
      (**(code **)(*(longlong *)pIVar7 + 8))(pIVar7);
    }
    else {
      iVar2 = (*param_1)(param_2,pIVar1,param_5);
      if (iVar2 < 0) goto LAB_140015a15;
    }
    *param_4 = (CRIMStream *)pIVar1;
    (**(code **)(*(longlong *)pIVar1 + 8))(pIVar1);
  }
LAB_140015a15:
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_28);
  return iVar2;
}



===== CreateStubObject @ 140015a44 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CRIMObjManager::CreateStubObject(long (__cdecl*)(struct _GUID const &
   __ptr64,struct IUnknown * __ptr64,struct IRIMStub * __ptr64 * __ptr64),struct IUnknown *
   __ptr64,struct _GUID const & __ptr64,unsigned long,struct IRIMStub * __ptr64 * __ptr64) __ptr64
    */

long __thiscall
CRIMObjManager::CreateStubObject
          (CRIMObjManager *this,_func_long__GUID_ptr_IUnknown_ptr_IRIMStub_ptr_ptr *param_1,
          IUnknown *param_2,_GUID *param_3,ulong param_4,IRIMStub **param_5)

{
  long lVar1;
  CImplIUnknown<IRIMStub> *this_00;
  longlong lVar2;
  
  lVar2 = -*(longlong *)param_3;
  if (lVar2 == 0) {
    lVar2 = 0x46000000000000c0 - *(longlong *)(param_3 + 8);
  }
  if (lVar2 == 0) {
    this_00 = (CImplIUnknown<IRIMStub> *)ExAllocatePoolWithTag(0x200,0x28,0x6c6d6952);
    if (this_00 == (CImplIUnknown<IRIMStub> *)0x0) {
      *param_5 = (IRIMStub *)0x0;
      lVar1 = -0x7ff8fff2;
    }
    else {
      CImplIUnknown<IRIMStub>::CImplIUnknown<IRIMStub>(this_00);
      *(undefined ***)this_00 = &CStub<ITsRequestCompletion>::_vftable_;
      *(IUnknown **)(this_00 + 0x18) = param_2;
      if (param_2 != (IUnknown *)0x0) {
        (**(code **)(*(longlong *)param_2 + 8))(param_2);
      }
      *(undefined4 *)(this_00 + 0x20) = 0xffffffff;
      *param_5 = (IRIMStub *)this_00;
      (**(code **)(*(longlong *)this_00 + 0x20))(this_00,param_4);
      (**(code **)(*(longlong *)*param_5 + 8))();
      lVar1 = 0;
    }
  }
  else {
    lVar1 = (*param_1)(param_3,param_2,param_5);
    if (-1 < lVar1) {
      (**(code **)(*(longlong *)*param_5 + 0x20))(*param_5,param_4);
    }
  }
  return lVar1;
}



===== ExchangeCapabilities @ 140015b50 =====

/* public: virtual long __cdecl
   CRIMObjManager::CCapabilitiesNegotiator::ExchangeCapabilities(unsigned long,unsigned long *
   __ptr64) __ptr64 */

long __thiscall
CRIMObjManager::CCapabilitiesNegotiator::ExchangeCapabilities
          (CCapabilitiesNegotiator *this,ulong param_1,ulong *param_2)

{
  long lVar1;
  
  lVar1 = CRIMObjManager::ExchangeCapabilities(*(CRIMObjManager **)(this + 0x18),param_1,param_2);
  return lVar1;
}



===== ExchangeCapabilities @ 140015b70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CRIMObjManager::ExchangeCapabilities(unsigned long,unsigned long *
   __ptr64) __ptr64 */

long __thiscall
CRIMObjManager::ExchangeCapabilities(CRIMObjManager *this,ulong param_1,ulong *param_2)

{
  int iVar1;
  long lVar2;
  longlong lVar3;
  ulong uVar4;
  undefined1 auStack_a8 [32];
  undefined8 local_88;
  longlong lStack_80;
  longlong *local_78;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  if (param_2 == (ulong *)0x0) {
    lVar2 = -0x7fffbffd;
  }
  else {
    *param_2 = 1;
    *(ulong *)(this + 0xd8) = param_1 & 1;
    lVar2 = 0;
    if (((param_1 & 1) != 0) && (uVar4 = 0, *(int *)(this + 0x1c) != 0)) {
      do {
        local_78 = (longlong *)0x0;
        local_88 = 0;
        lStack_80 = 0;
        if ((uVar4 != *(ulong *)(this + 0xe0)) &&
           (iVar1 = DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::GetAt
                              ((DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *)(this + 0x18)
                               ,uVar4,(CObjectEntry *)&local_88), iVar1 != 0)) {
          local_50 = 0;
          local_60 = 0;
          uStack_58 = 0;
          if (local_78 == (longlong *)0x0) {
            *(uint *)(lStack_80 + 0xb4) = *(uint *)(lStack_80 + 0xb4) | 0x40000000;
            lVar3 = 0x38;
          }
          else {
            (**(code **)(*local_78 + 0x20))(local_78,uVar4 | 0x80000000);
            *(uint *)(lStack_80 + 0xb4) = *(uint *)(lStack_80 + 0xb4) | 0x80000000;
            lVar3 = 0x28;
          }
          iVar1 = DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::AddAt
                            ((DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *)(this + lVar3),
                             uVar4,(CObjectEntry *)&local_88);
          DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::AddAt
                    ((DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *)(this + 0x18),uVar4,
                     (CObjectEntry *)&local_60);
          if (iVar1 == 0) {
            lVar2 = -0x7ff8fff2;
          }
          CObjectEntry::~CObjectEntry((CObjectEntry *)&local_60);
        }
        CObjectEntry::~CObjectEntry((CObjectEntry *)&local_88);
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(this + 0x1c));
    }
  }
  return lVar2;
}



===== FindEmptySlotForObject @ 140015cc0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl CRIMObjManager::FindEmptySlotForObject(unsigned long * __ptr64) __ptr64 */

long __thiscall CRIMObjManager::FindEmptySlotForObject(CRIMObjManager *this,ulong *param_1)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  undefined1 auStack_68 [32];
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_68;
  uVar1 = *(uint *)(this + 0xd8);
  uVar2 = 0;
  do {
    uVar3 = 0xffffffff;
    if (*(uint *)(this + (ulonglong)(uVar1 & 1) * 0x10 + 0x1c) <= uVar2) {
LAB_140015d35:
      *param_1 = uVar3;
      return 0;
    }
    local_38 = 0;
    local_48 = 0;
    lStack_40 = 0;
    DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::GetAt
              ((DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *)
               (this + (ulonglong)(uVar1 & 1) * 0x10 + 0x18),uVar2,(CObjectEntry *)&local_48);
    if (lStack_40 == 0) {
      CObjectEntry::~CObjectEntry((CObjectEntry *)&local_48);
      uVar3 = uVar2;
      goto LAB_140015d35;
    }
    CObjectEntry::~CObjectEntry((CObjectEntry *)&local_48);
    uVar2 = uVar2 + 1;
  } while( true );
}



===== GetAt @ 140015d60 =====

/* public: int __cdecl DynArray<class CRIMObjManager::CObjectEntry,unsigned long>::GetAt(unsigned
   long,class CRIMObjManager::CObjectEntry * __ptr64) __ptr64 */

int __thiscall
DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::GetAt
          (DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *this,ulong param_1,
          CObjectEntry *param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 4);
  if (param_1 < uVar1) {
    CRIMObjManager::CObjectEntry::operator=
              (param_2,(CObjectEntry *)(*(longlong *)(this + 8) + (ulonglong)param_1 * 0x28));
  }
  return (int)(param_1 < uVar1);
}



===== GetIdFromObject @ 140015d94 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl CRIMObjManager::GetIdFromObject(struct IUnknown * __ptr64,struct _GUID const
   & __ptr64,unsigned long * __ptr64) __ptr64 */

long __thiscall
CRIMObjManager::GetIdFromObject
          (CRIMObjManager *this,IUnknown *param_1,_GUID *param_2,ulong *param_3)

{
  CRIMObjManager *pCVar1;
  uint uVar2;
  CRIMStream *pCVar3;
  uint uVar4;
  long lVar5;
  int iVar6;
  CRIMStreamStub *pCVar7;
  IWTSVirtualChannel *pIVar8;
  CObjectEntry *this_00;
  ulong uVar9;
  uint uVar10;
  undefined1 auStackY_d8 [32];
  IRIMStub *local_a8;
  ulong local_a0 [2];
  CRIMStream *local_98;
  _GUID *local_90;
  uint *local_88;
  ExclusiveLock local_80 [8];
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_d8;
  uVar10 = *(uint *)(this + 0xd8);
  local_a8 = (IRIMStub *)0x0;
  uVar4 = uVar10 & 1;
  local_90 = param_2;
  local_88 = param_3;
  ExclusiveLock::ExclusiveLock(local_80,(GenericLock *)(this + 0x48));
  local_a0[0] = 0xffffffff;
  local_98 = (CRIMStream *)0x0;
  lVar5 = FindEmptySlotForObject(this,local_a0);
  pCVar1 = this + (ulonglong)uVar4 * 0x10 + 0x1c;
  this_00 = (CObjectEntry *)0xffffffff;
  if (local_a0[0] == 0xffffffff) {
    uVar9 = *(ulong *)pCVar1;
  }
  else {
    uVar9 = local_a0[0];
  }
  if ((uVar9 & 0xc0000000) == 0) {
    if (-1 < lVar5) {
      uVar9 = local_a0[0];
      if (local_a0[0] == 0xffffffff) {
        local_68 = 0;
        local_78 = 0;
        uStack_70 = 0;
        iVar6 = DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::Grow
                          ((DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *)
                           (this + (ulonglong)uVar4 * 0x10 + 0x18),*(ulong *)pCVar1);
        if (iVar6 == 0) {
          lVar5 = -0x7ff8fb70;
          CObjectEntry::~CObjectEntry((CObjectEntry *)&local_78);
          goto LAB_140015f79;
        }
        uVar2 = *(uint *)pCVar1;
        *(uint *)pCVar1 = uVar2 + 1;
        CObjectEntry::operator=
                  ((CObjectEntry *)
                   (*(longlong *)(this + (ulonglong)uVar4 * 0x10 + 0x20) + (ulonglong)uVar2 * 0x28),
                   (CObjectEntry *)&local_78);
        this_00 = (CObjectEntry *)&local_78;
        uVar9 = *(ulong *)pCVar1 - 1;
        CObjectEntry::~CObjectEntry(this_00);
      }
      uVar10 = uVar10 << 0x1f | uVar9;
      lVar5 = CreateStubObject((CRIMObjManager *)this_00,
                               *(_func_long__GUID_ptr_IUnknown_ptr_IRIMStub_ptr_ptr **)(this + 200),
                               param_1,local_90,uVar10,&local_a8);
      if (-1 < lVar5) {
        pCVar7 = (CRIMStreamStub *)ExAllocatePoolWithTag(0x200,0xd0,0x6c6d6952);
        pIVar8 = (IWTSVirtualChannel *)0x0;
        if (pCVar7 != (CRIMStreamStub *)0x0) {
          SmartPtr<CRIMObjectPoolBase>::SmartPtr<CRIMObjectPoolBase>
                    ((SmartPtr<CRIMObjectPoolBase> *)local_a0,
                     (SmartPtr<class_CRIMObjectPool<class_CMessage>_> *)(this + 0x1a0));
          pIVar8 = (IWTSVirtualChannel *)CRIMStreamStub::CRIMStreamStub(pCVar7,this,local_a8,uVar10)
          ;
        }
        SmartPtr<IWTSVirtualChannel>::operator=((SmartPtr<IWTSVirtualChannel> *)&local_98,pIVar8);
        pCVar3 = local_98;
        if (local_98 == (CRIMStream *)0x0) {
          lVar5 = -0x7ff8fff2;
        }
        else {
          lVar5 = (**(code **)(*(longlong *)local_98 + 0x30))(local_98);
          if (-1 < lVar5) {
            CObjectEntry::CObjectEntry((CObjectEntry *)&local_78,param_1,pCVar3,local_90,local_a8);
            DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::AddAt
                      ((DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *)
                       (this + (ulonglong)uVar4 * 0x10 + 0x18),uVar9,(CObjectEntry *)&local_78);
            CObjectEntry::~CObjectEntry((CObjectEntry *)&local_78);
            *local_88 = uVar9;
          }
        }
      }
    }
  }
  else {
    lVar5 = -0x7fff0001;
  }
LAB_140015f79:
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_98);
  ExclusiveLock::~ExclusiveLock(local_80);
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_a8);
  return lVar5;
}



===== GetObjectFromId @ 140015fc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl CRIMObjManager::GetObjectFromId(unsigned long,struct _GUID const &
   __ptr64,struct IUnknown * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CRIMObjManager::GetObjectFromId
          (CRIMObjManager *this,ulong param_1,_GUID *param_2,IUnknown **param_3)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  undefined1 auStackY_d8 [32];
  IUnknown *local_a8;
  CRIMStream *local_a0;
  ExclusiveLock local_98 [8];
  CObjectEntry local_90 [40];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_d8;
  uVar1 = *(uint *)(this + 0xd8);
  local_58 = 0;
  local_a0 = (CRIMStream *)0x0;
  local_a8 = (IUnknown *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  ExclusiveLock::ExclusiveLock(local_98,(GenericLock *)(this + 0x48));
  lVar2 = CreateProxyObject(this,*(_func_long__GUID_ptr_IRIMStream_ptr_IUnknown_ptr_ptr **)
                                  (this + 0xd0),param_2,(uVar1 & 1) << 0x1e | param_1,&local_a0,
                            &local_a8);
  if (-1 < lVar2) {
    CObjectEntry::CObjectEntry(local_90,local_a8,local_a0,param_2,(IRIMStub *)0x0);
    iVar3 = DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::AddAt
                      ((DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *)
                       (this + (ulonglong)(uVar1 & 1) * 0x20 + 0x18),param_1,local_90);
    if (iVar3 == 0) {
      lVar2 = -0x7ff8fb70;
      CObjectEntry::~CObjectEntry(local_90);
    }
    else {
      lVar2 = 0;
      CObjectEntry::~CObjectEntry(local_90);
      *param_3 = local_a8;
      (**(code **)(*(longlong *)local_a8 + 8))();
    }
  }
  ExclusiveLock::~ExclusiveLock(local_98);
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_a8);
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_a0);
  CObjectEntry::~CObjectEntry((CObjectEntry *)&local_68);
  return lVar2;
}



===== GetPrefix @ 140016100 =====

/* public: long __cdecl CMemory::GetPrefix(unsigned char * __ptr64 * __ptr64,unsigned long) __ptr64
    */

long __thiscall CMemory::GetPrefix(CMemory *this,uchar **param_1,ulong param_2)

{
  if ((uint)(*(int *)(this + 0x68) + *(int *)(this + 0x58)) < param_2) {
    return -0x7fff0001;
  }
  *param_1 = *(uchar **)(this + 0x50);
  return 0;
}



===== GetProxy @ 140016130 =====

/* public: virtual long __cdecl CRIMObjManager::GetProxy(struct _GUID const & __ptr64,unsigned
   long,struct IUnknown * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CRIMObjManager::GetProxy(CRIMObjManager *this,_GUID *param_1,ulong param_2,IUnknown **param_3)

{
  long lVar1;
  
  lVar1 = GetProxyInternal(this,*(_func_long__GUID_ptr_IRIMStream_ptr_IUnknown_ptr_ptr **)
                                 (this + 0xd0),param_1,param_2,param_3);
  return lVar1;
}



===== GetProxyInternal @ 140016158 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl CRIMObjManager::GetProxyInternal(long (__cdecl*)(struct _GUID const &
   __ptr64,struct IRIMStream * __ptr64,struct IUnknown * __ptr64 * __ptr64),struct _GUID const &
   __ptr64,unsigned long,struct IUnknown * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CRIMObjManager::GetProxyInternal
          (CRIMObjManager *this,_func_long__GUID_ptr_IRIMStream_ptr_IUnknown_ptr_ptr *param_1,
          _GUID *param_2,ulong param_3,IUnknown **param_4)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  undefined1 auStackY_b8 [32];
  IUnknown *local_88;
  CRIMStream *local_80;
  ExclusiveLock local_78 [8];
  CObjectEntry local_70 [40];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar1 = *(uint *)(this + 0xd8);
  local_80 = (CRIMStream *)0x0;
  local_88 = (IUnknown *)0x0;
  lVar2 = CreateProxyObject(this,param_1,param_2,(uVar1 & 1) << 0x1e | param_3,&local_80,&local_88);
  if (-1 < lVar2) {
    CObjectEntry::CObjectEntry(local_70,local_88,local_80,param_2,(IRIMStub *)0x0);
    ExclusiveLock::ExclusiveLock(local_78,(GenericLock *)(this + 0x48));
    iVar3 = DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::AddAt
                      ((DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *)
                       (this + (ulonglong)(uVar1 & 1) * 0x20 + 0x18),param_3,local_70);
    if (iVar3 == 0) {
      lVar2 = -0x7ff8fb70;
      ExclusiveLock::~ExclusiveLock(local_78);
      CObjectEntry::~CObjectEntry(local_70);
    }
    else {
      lVar2 = 0;
      ExclusiveLock::~ExclusiveLock(local_78);
      CObjectEntry::~CObjectEntry(local_70);
      *param_4 = local_88;
      (**(code **)(*(longlong *)local_88 + 8))();
    }
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_88);
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_80);
  return lVar2;
}



===== Grow @ 140016280 =====

/* private: int __cdecl DynArray<class CRIMObjManager::CObjectEntry,unsigned long>::Grow(unsigned
   long) __ptr64 */

int __thiscall
DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::Grow
          (DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *this,ulong param_1)

{
  CObjectEntry *pCVar1;
  undefined1 auVar2 [16];
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong *puVar6;
  uint uVar7;
  CObjectEntry *pCVar8;
  uint uVar9;
  ulonglong uVar10;
  uint uVar11;
  
  if (param_1 < *(uint *)this) {
LAB_1400162a0:
    iVar3 = 1;
  }
  else {
    uVar11 = param_1 + 0x20;
    if (param_1 <= uVar11) {
      uVar10 = CONCAT44(0,uVar11);
      auVar2._8_8_ = 0;
      auVar2._0_8_ = uVar10;
      uVar4 = SUB168(ZEXT816(0x28) * auVar2,0);
      if (SUB168(ZEXT816(0x28) * auVar2,8) != 0) {
        uVar4 = 0xffffffffffffffff;
      }
      lVar5 = uVar4 + 8;
      if (0xfffffffffffffff7 < uVar4) {
        lVar5 = -1;
      }
      puVar6 = (ulonglong *)ExAllocatePoolWithTag(0x200,lVar5,0x72447244);
      uVar7 = (uint)lVar5;
      if (puVar6 != (ulonglong *)0x0) {
        *puVar6 = uVar10;
        pCVar1 = (CObjectEntry *)(puVar6 + 1);
        pCVar8 = pCVar1;
        if (uVar11 != 0) {
          do {
            CRIMObjManager::CObjectEntry::CObjectEntry(pCVar8);
            uVar7 = (uint)lVar5;
            pCVar8 = pCVar8 + 0x28;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
        }
        if (pCVar1 != (CObjectEntry *)0x0) {
          uVar4 = 0;
          if (*(int *)this != 0) {
            do {
              pCVar8 = (CObjectEntry *)(*(longlong *)(this + 8) + uVar4 * 0x28);
              CRIMObjManager::CObjectEntry::operator=(pCVar1 + uVar4 * 0x28,pCVar8);
              uVar7 = (uint)pCVar8;
              uVar9 = (int)uVar4 + 1;
              uVar4 = (ulonglong)uVar9;
            } while (uVar9 < *(uint *)this);
          }
          if (*(CObjectEntry **)(this + 8) != (CObjectEntry *)0x0) {
            CRIMObjManager::CObjectEntry::_vector_deleting_destructor_
                      (*(CObjectEntry **)(this + 8),uVar7);
          }
          *(CObjectEntry **)(this + 8) = pCVar1;
          *(uint *)this = uVar11;
          goto LAB_1400162a0;
        }
      }
    }
    iVar3 = 0;
  }
  return iVar3;
}



===== IsConnected @ 140016380 =====

/* public: virtual long __cdecl CRIMObjManager::IsConnected(int * __ptr64) __ptr64 */

long __thiscall CRIMObjManager::IsConnected(CRIMObjManager *this,int *param_1)

{
  *param_1 = (uint)(*(longlong *)(this + 0x100) != 0);
  return 0;
}



===== OnDataReceived @ 140016398 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: long __cdecl CRIMObjManager::OnDataReceived(unsigned char * __ptr64,unsigned long)
   __ptr64 */

long __thiscall CRIMObjManager::OnDataReceived(CRIMObjManager *this,uchar *param_1,ulong param_2)

{
  CMemory *this_00;
  long lVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  CRIMObjManager *this_01;
  undefined1 auStack_88 [32];
  uint *local_68;
  CMemory *local_60;
  undefined8 local_58;
  longlong *plStack_50;
  undefined8 local_48;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_88;
  local_48 = 0;
  local_60 = (CMemory *)0x0;
  local_58 = 0;
  plStack_50 = (longlong *)0x0;
  lVar1 = CRIMObjectPool<CMemory>::GetPooledObject
                    (*(CRIMObjectPool<CMemory> **)(this + 0x198),&local_60,param_2);
  this_00 = local_60;
  if (local_60 == (CMemory *)0x0) {
    lVar1 = -0x7ff8fff2;
  }
  else if (param_2 < 4) {
LAB_1400164ec:
    if (-1 < lVar1) goto LAB_1400164f8;
  }
  else {
    if (*(uint *)(local_60 + 0x70) < param_2) {
      lVar1 = CMemory::Grow(local_60,param_2 - *(uint *)(local_60 + 0x70));
      if (lVar1 < 0) goto LAB_1400164f0;
    }
    memmove(*(void **)(this_00 + 0x50),param_1,(ulonglong)param_2);
    *(undefined4 *)(this_00 + 0x58) = 0;
    lVar4 = 4;
    local_68 = (uint *)0x0;
    *(undefined8 *)(this_00 + 0x60) = *(undefined8 *)(this_00 + 0x50);
    *(ulong *)(this_00 + 0x68) = param_2;
    lVar1 = CMemory::GetPrefix(this_00,(uchar **)&local_68,4);
    if (-1 < lVar1) {
      this_01 = this + 0x18;
      uVar3 = *local_68;
      *(int *)(this_00 + 0x58) = *(int *)(this_00 + 0x58) + (int)lVar4;
      *(longlong *)(this_00 + 0x60) = *(longlong *)(this_00 + 0x60) + lVar4;
      *(int *)(this_00 + 0x68) = *(int *)(this_00 + 0x68) + -4;
      if ((*(uint *)(this + 0xd8) & 1) != 0) {
        if ((int)uVar3 < 0) {
          this_01 = this + 0x38;
          uVar3 = uVar3 & 0x7fffffff;
        }
        else if ((uVar3 >> 0x1e & 1) != 0) {
          this_01 = this + 0x28;
          uVar3 = uVar3 & 0xbfffffff;
        }
      }
      ExclusiveLock::ExclusiveLock((ExclusiveLock *)&local_68,(GenericLock *)(this + 0x48));
      iVar2 = DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::GetAt
                        ((DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *)this_01,uVar3,
                         (CObjectEntry *)&local_58);
      if (iVar2 == 0) {
        lVar1 = -0x7ff8fb70;
        ExclusiveLock::~ExclusiveLock((ExclusiveLock *)&local_68);
      }
      else {
        ExclusiveLock::~ExclusiveLock((ExclusiveLock *)&local_68);
        if (plStack_50 != (longlong *)0x0) {
          lVar1 = (**(code **)(*plStack_50 + 0x40))(plStack_50,this_00);
          goto LAB_1400164ec;
        }
        lVar1 = -0x7fff0001;
      }
    }
  }
LAB_1400164f0:
  CloseChannel(this);
LAB_1400164f8:
  SmartPtr<CMessage>::~SmartPtr<CMessage>((SmartPtr<CMessage> *)&local_60);
  CObjectEntry::~CObjectEntry((CObjectEntry *)&local_58);
  return lVar1;
}



===== QueryInterface @ 140016540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CImplIUnknown<struct IRIMStream>::QueryInterface(struct _GUID const
   & __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CImplIUnknown<IRIMStream>::QueryInterface
          (CImplIUnknown<IRIMStream> *this,_GUID *param_1,void **param_2)

{
  longlong lVar1;
  
  lVar1 = -*(longlong *)param_1;
  if (lVar1 == 0) {
    lVar1 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar1 != 0) {
    lVar1 = 0x43df32cfc0da5db2 - *(longlong *)param_1;
    if (lVar1 == 0) {
      lVar1 = 0x19c67f1fece5248b - *(longlong *)(param_1 + 8);
    }
    if (lVar1 != 0) {
      return -0x7fffbffe;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  return 0;
}



===== QueryInterface @ 1400165b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CProxyIUnknown<struct IUnknown>::QueryInterface(struct _GUID const &
   __ptr64,void * __ptr64 * __ptr64) __ptr64 */

long __thiscall
CProxyIUnknown<IUnknown>::QueryInterface
          (CProxyIUnknown<IUnknown> *this,_GUID *param_1,void **param_2)

{
  int iVar1;
  longlong lVar2;
  int local_res20 [2];
  longlong *local_18 [2];
  
  local_18[0] = (longlong *)0x0;
  lVar2 = -*(longlong *)param_1;
  if (lVar2 == 0) {
    lVar2 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
  }
  if (lVar2 != 0) {
    lVar2 = -*(longlong *)param_1;
    if (lVar2 == 0) {
      lVar2 = 0x46000000000000c0 - *(longlong *)(param_1 + 8);
    }
    if (lVar2 != 0) {
      iVar1 = (**(code **)(**(longlong **)(this + 0x18) + 0x18))
                        (*(longlong **)(this + 0x18),local_18);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_18[0] + 0x40))(local_18[0],2);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_18[0] + 0x48))(local_18[0],param_1);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_18[0] + 0x20))();
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*local_18[0] + 0xd8))();
              if (-1 < iVar1) {
                iVar1 = (**(code **)(*local_18[0] + 0x180))(local_18[0],param_2,param_1,1);
                if (-1 < iVar1) {
                  local_res20[0] = 0;
                  iVar1 = (**(code **)(*local_18[0] + 0xe8))(local_18[0],local_res20);
                  if (-1 < iVar1) {
                    iVar1 = local_res20[0];
                  }
                }
              }
            }
          }
        }
      }
      goto LAB_140016700;
    }
  }
  *param_2 = this;
  (**(code **)(*(longlong *)this + 8))(this);
  iVar1 = 0;
LAB_140016700:
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)local_18);
  return iVar1;
}



===== RegisterCapabilities @ 140016728 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CRIMObjManager::RegisterCapabilities(unsigned long) __ptr64 */

long __thiscall CRIMObjManager::RegisterCapabilities(CRIMObjManager *this,ulong param_1)

{
  long lVar1;
  CImplIUnknown<IRIMCapabilitiesNegotiator> *this_00;
  CImplIUnknown<IRIMCapabilitiesNegotiator> *local_res18 [2];
  
  this_00 = (CImplIUnknown<IRIMCapabilitiesNegotiator> *)
            ExAllocatePoolWithTag(0x200,0x20,0x6c6d6952);
  if (this_00 == (CImplIUnknown<IRIMCapabilitiesNegotiator> *)0x0) {
    local_res18[0] = (CImplIUnknown<IRIMCapabilitiesNegotiator> *)0x0;
    lVar1 = -0x7ff8fff2;
  }
  else {
    CImplIUnknown<IRIMCapabilitiesNegotiator>::CImplIUnknown<IRIMCapabilitiesNegotiator>(this_00);
    *(undefined ***)this_00 = &CCapabilitiesNegotiator::_vftable_;
    *(CRIMObjManager **)(this_00 + 0x18) = this;
    if (this != (CRIMObjManager *)0x0) {
      LOCK();
      *(int *)(this + 0xc) = *(int *)(this + 0xc) + 1;
      UNLOCK();
    }
    local_res18[0] = this_00;
    (**(code **)(*(longlong *)this_00 + 8))(this_00);
    lVar1 = AddObjectInternal(this,GetInstanceOfStub,(IUnknown *)this_00,
                              (_GUID *)&IID_IRIMCapabilitiesNegotiator,param_1);
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)local_res18);
  return lVar1;
}



===== RemoveObject @ 1400167e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: long __cdecl CRIMObjManager::RemoveObject(unsigned long,int) __ptr64 */

long __thiscall CRIMObjManager::RemoveObject(CRIMObjManager *this,ulong param_1,int param_2)

{
  int iVar1;
  CRIMObjManager *this_00;
  long lVar2;
  undefined1 auStack_a8 [32];
  ExclusiveLock local_88 [8];
  undefined8 local_80;
  undefined8 uStack_78;
  longlong *local_70;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar2 = 0;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_70 = (longlong *)0x0;
  local_80 = 0;
  uStack_78 = 0;
  ExclusiveLock::ExclusiveLock(local_88,(GenericLock *)(this + 0x48));
  this_00 = this + 0x18;
  if (((byte)this[0xd8] & 1) != 0 && (param_1 & 0xc0000000) != 0) {
    param_1 = param_1 & 0x3fffffff;
    this_00 = this + (-(ulonglong)(param_2 != 0) & 0xfffffffffffffff0) + 0x38;
  }
  DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::GetAt
            ((DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *)this_00,param_1,
             (CObjectEntry *)&local_80);
  iVar1 = DynArray<CRIMObjManager::CObjectEntry,unsigned_long>::AddAt
                    ((DynArray<CRIMObjManager::CObjectEntry,unsigned_long> *)this_00,param_1,
                     (CObjectEntry *)&local_58);
  if (iVar1 == 0) {
    lVar2 = -0x7ff8fb70;
    ExclusiveLock::~ExclusiveLock(local_88);
  }
  else {
    ExclusiveLock::~ExclusiveLock(local_88);
    if (local_70 != (longlong *)0x0) {
      (**(code **)(*local_70 + 0x28))();
    }
  }
  CObjectEntry::~CObjectEntry((CObjectEntry *)&local_80);
  CObjectEntry::~CObjectEntry((CObjectEntry *)&local_58);
  return lVar2;
}



===== SetChannel @ 1400168f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CRIMObjManager::SetChannel(struct IWTSVirtualChannel * __ptr64)
   __ptr64 */

long __thiscall CRIMObjManager::SetChannel(CRIMObjManager *this,IWTSVirtualChannel *param_1)

{
  long lVar1;
  uint local_res8 [2];
  IUnknown *local_res18;
  
  lVar1 = 0;
  ExclusiveLock::ExclusiveLock((ExclusiveLock *)local_res8,(GenericLock *)(this + 0x110));
  SmartPtr<IWTSVirtualChannel>::operator=((SmartPtr<IWTSVirtualChannel> *)(this + 0x100),param_1);
  ExclusiveLock::~ExclusiveLock((ExclusiveLock *)local_res8);
  if (*(int *)(this + 0xdc) == 4) {
    local_res18 = (IUnknown *)0x0;
    lVar1 = GetProxyInternal(this,GetInstanceOfProxy,(_GUID *)&IID_IRIMCapabilitiesNegotiator,
                             *(ulong *)(this + 0xe0),&local_res18);
    if (-1 < lVar1) {
      local_res8[0] = 0;
      lVar1 = (**(code **)(*(longlong *)local_res18 + 0x18))(local_res18,1,local_res8);
      if (-1 < lVar1) {
        *(uint *)(this + 0xd8) = local_res8[0] & 1;
      }
    }
    SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)&local_res18);
  }
  return lVar1;
}



===== SetWaitTimeout @ 1400169d0 =====

/* public: virtual long __cdecl CRIMObjManager::SetWaitTimeout(unsigned long) __ptr64 */

long __thiscall CRIMObjManager::SetWaitTimeout(CRIMObjManager *this,ulong param_1)

{
  *(ulong *)(this + 0x1a8) = param_1;
  return 0;
}



===== CImplIUnknown<IRIMStream> @ 1400169e0 =====

/* public: __cdecl CImplIUnknown<struct IRIMStream>::CImplIUnknown<struct IRIMStream>(void) __ptr64
    */

CImplIUnknown<IRIMStream> * __thiscall
CImplIUnknown<IRIMStream>::CImplIUnknown<IRIMStream>(CImplIUnknown<IRIMStream> *this)

{
  *(undefined4 *)(this + 8) = 0;
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0xc001d00d;
  return this;
}



===== CRIMStream @ 140016a08 =====

/* public: __cdecl CRIMStream::CRIMStream(class CRIMObjManager * __ptr64,unsigned long,class
   SmartPtr<class CRIMObjectPool<class CMessage> >) __ptr64 */

CRIMStream * __thiscall
CRIMStream::CRIMStream
          (CRIMStream *this,longlong param_1,undefined4 param_2,
          SmartPtr<class_CRIMObjectPool<class_CMessage>_> *param_4)

{
  CImplIUnknown<IRIMStream>::CImplIUnknown<IRIMStream>((CImplIUnknown<IRIMStream> *)this);
  *(undefined ***)this = &_vftable_;
  *(undefined4 *)(this + 0x28) = 0;
  RtlInitializeBitMap(this + 0x18,0,0);
  KernelResource::KernelResource((KernelResource *)(this + 0x30),"CRIMStream");
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 0xb4) = param_2;
  SmartPtr<CRIMObjectPoolBase>::SmartPtr<CRIMObjectPoolBase>
            ((SmartPtr<CRIMObjectPoolBase> *)(this + 0xb8),param_4);
  *(longlong *)(this + 0xc0) = param_1;
  if (param_1 != 0) {
    LOCK();
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    UNLOCK();
  }
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)param_4);
  return this;
}



===== ~CRIMStream @ 140016ab4 =====

/* public: virtual __cdecl CRIMStream::~CRIMStream(void) __ptr64 */

void __thiscall CRIMStream::~CRIMStream(CRIMStream *this)

{
  *(undefined ***)this = &_vftable_;
  SmartPtr<CRIMObjManager>::~SmartPtr<CRIMObjManager>((SmartPtr<CRIMObjManager> *)(this + 0xc0));
  SmartPtr<CRIMStreamStub>::~SmartPtr<CRIMStreamStub>((SmartPtr<CRIMStreamStub> *)(this + 0xb8));
  KernelResource::~KernelResource((KernelResource *)(this + 0x30));
  CUniqueIdMap::~CUniqueIdMap((CUniqueIdMap *)(this + 0x18));
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &CImplIUnknown<IRIMStream>::_vftable_;
  return;
}



===== ~CUniqueIdMap @ 140016b10 =====

/* public: __cdecl CUniqueIdMap::~CUniqueIdMap(void) __ptr64 */

void __thiscall CUniqueIdMap::~CUniqueIdMap(CUniqueIdMap *this)

{
  if (*(void **)(this + 8) != (void *)0x0) {
    operator_delete(*(void **)(this + 8));
  }
  return;
}



===== `scalar_deleting_destructor' @ 140016b30 =====

/* public: virtual void * __ptr64 __cdecl CImplIUnknown<struct IRIMStream>::`scalar deleting
   destructor'(unsigned int) __ptr64 */

void * __thiscall
CImplIUnknown<IRIMStream>::_scalar_deleting_destructor_
          (CImplIUnknown<IRIMStream> *this,uint param_1)

{
  *(undefined4 *)(this + 0x10) = 0xbaadf00d;
  *(undefined ***)this = &_vftable_;
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== `scalar_deleting_destructor' @ 140016b70 =====

/* public: virtual void * __ptr64 __cdecl CRIMStream::`scalar deleting destructor'(unsigned int)
   __ptr64 */

void * __thiscall CRIMStream::_scalar_deleting_destructor_(CRIMStream *this,uint param_1)

{
  ~CRIMStream(this);
  if ((param_1 & 1) != 0) {
    ExFreePoolWithTag(this,0x6c6d6952);
  }
  return this;
}



===== GetMessageInstance @ 140016bc0 =====

/* public: virtual long __cdecl CRIMStream::GetMessageInstance(struct IMessage * __ptr64 * __ptr64)
   __ptr64 */

long __thiscall CRIMStream::GetMessageInstance(CRIMStream *this,IMessage **param_1)

{
  CUniqueIdMap *this_00;
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  ExclusiveLock local_res8 [8];
  
  ExclusiveLock::ExclusiveLock(local_res8,(GenericLock *)(this + 0x30));
  this_00 = (CUniqueIdMap *)(this + 0x18);
  if ((*(int *)(this + 0x28) == *(int *)this_00) &&
     (lVar1 = CUniqueIdMap::Resize(this_00), lVar1 < 0)) {
    ExclusiveLock::~ExclusiveLock(local_res8);
    return lVar1;
  }
  uVar3 = 0;
  uVar2 = RtlFindClearBitsAndSet(this_00,1);
  *(int *)(this + 0x28) = *(int *)(this + 0x28) + 1;
  ExclusiveLock::~ExclusiveLock(local_res8);
  CRIMObjectPool<CMessage>::GetPooledObject
            (*(CRIMObjectPool<CMessage> **)(this + 0xb8),(CMessage **)param_1,uVar3);
  if ((CMessage *)*param_1 == (CMessage *)0x0) {
    lVar1 = -0x7ff8fff2;
  }
  else {
    lVar1 = CMessage::Initialize((CMessage *)*param_1,this,uVar3,uVar2,(CMemory *)0x0);
    if (-1 < lVar1) {
      return lVar1;
    }
  }
  ReleaseMessageId(this,uVar2);
  return lVar1;
}



===== GetNetworkId @ 140016c90 =====

/* public: virtual long __cdecl CRIMStream::GetNetworkId(unsigned long * __ptr64) __ptr64 */

long __thiscall CRIMStream::GetNetworkId(CRIMStream *this,ulong *param_1)

{
  *param_1 = *(ulong *)(this + 0xb4);
  return 0;
}



===== GetPooledObject @ 140016ca4 =====

/* public: long __cdecl CRIMObjectPool<class CMessage>::GetPooledObject(class CMessage * __ptr64 *
   __ptr64,int) __ptr64 */

long __thiscall
CRIMObjectPool<CMessage>::GetPooledObject
          (CRIMObjectPool<CMessage> *this,CMessage **param_1,int param_2)

{
  CRIMObjectPool<CMessage> *pCVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  long lVar5;
  CMessage *pCVar6;
  CMessage *pCVar7;
  CRIMObjectPoolBase *pCVar8;
  ExclusiveLock local_res8 [8];
  
  lVar5 = 0;
  *param_1 = (CMessage *)0x0;
  ExclusiveLock::ExclusiveLock(local_res8,(GenericLock *)(this + 0x48));
  pCVar1 = *(CRIMObjectPool<CMessage> **)(this + 0x28);
  if (pCVar1 != this + 0x28) {
    *param_1 = (CMessage *)(pCVar1 + -0x20);
    lVar2 = *(longlong *)pCVar1;
    if ((*(CRIMObjectPool<CMessage> **)(lVar2 + 8) != pCVar1) ||
       (plVar3 = *(longlong **)(pCVar1 + 8), (CRIMObjectPool<CMessage> *)*plVar3 != pCVar1))
    goto LAB_140016e01;
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    plVar3 = *(longlong **)(this + 0x40);
    pCVar6 = *param_1;
    pCVar7 = pCVar6 + 0x20;
    if ((CRIMObjectPool<CMessage> *)*plVar3 != this + 0x38) goto LAB_140016e01;
    *(CRIMObjectPool<CMessage> **)pCVar7 = this + 0x38;
    *(longlong **)(pCVar6 + 0x28) = plVar3;
    *plVar3 = (longlong)pCVar7;
    *(CMessage **)(this + 0x40) = pCVar7;
    *(int *)(this + 0x18) = *(int *)(this + 0x18) + -1;
    *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
    *(undefined4 *)(*param_1 + 0x30) = 1;
    LOCK();
    *(int *)(*param_1 + 0xc) = *(int *)(*param_1 + 0xc) + 1;
    UNLOCK();
    SmartPtr<IWTSVirtualChannel>::operator=
              ((SmartPtr<IWTSVirtualChannel> *)(*param_1 + 0x38),(IWTSVirtualChannel *)this);
  }
  if (*param_1 == (CMessage *)0x0) {
    pCVar8 = (CRIMObjectPoolBase *)0x68;
    pCVar6 = (CMessage *)ExAllocatePoolWithTag(0x200,0x68,0x6c6d6952);
    if (pCVar6 == (CMessage *)0x0) {
      *param_1 = (CMessage *)0x0;
    }
    else {
      pCVar6 = (CMessage *)CMessage::CMessage(pCVar6,pCVar8);
      *param_1 = pCVar6;
      if (pCVar6 != (CMessage *)0x0) {
        LOCK();
        *(int *)(pCVar6 + 0xc) = *(int *)(pCVar6 + 0xc) + 1;
        UNLOCK();
        *(undefined4 *)(*param_1 + 0x30) = 1;
        SmartPtr<IWTSVirtualChannel>::operator=
                  ((SmartPtr<IWTSVirtualChannel> *)(*param_1 + 0x38),(IWTSVirtualChannel *)this);
        LOCK();
        *(int *)(*param_1 + 0xc) = *(int *)(*param_1 + 0xc) + 1;
        UNLOCK();
        plVar3 = *(longlong **)(this + 0x40);
        pCVar6 = *param_1;
        pCVar7 = pCVar6 + 0x20;
        if ((CRIMObjectPool<CMessage> *)*plVar3 != this + 0x38) {
LAB_140016e01:
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          pcVar4 = (code *)swi(3);
          lVar5 = (*pcVar4)();
          return lVar5;
        }
        *(CRIMObjectPool<CMessage> **)pCVar7 = this + 0x38;
        *(longlong **)(pCVar6 + 0x28) = plVar3;
        *plVar3 = (longlong)pCVar7;
        *(CMessage **)(this + 0x40) = pCVar7;
        *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
        goto LAB_140016ddf;
      }
    }
    lVar5 = -0x7ff8fff2;
  }
LAB_140016ddf:
  ExclusiveLock::~ExclusiveLock(local_res8);
  return lVar5;
}



===== OnDataReceived @ 140016e10 =====

/* public: virtual long __cdecl CRIMStreamProxy::OnDataReceived(class CMemory * __ptr64) __ptr64 */

long __thiscall CRIMStreamProxy::OnDataReceived(CRIMStreamProxy *this,CMemory *param_1)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  CRIMStreamProxy *pCVar4;
  CMessageEntry *this_00;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  uchar *local_res18;
  ExclusiveLock local_res20 [8];
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  local_res18 = (uchar *)0x0;
  lVar3 = CMemory::GetPrefix(param_1,&local_res18,8);
  if (-1 < lVar3) {
    lVar3 = 0;
    iVar1 = *(int *)(local_res18 + 4);
    *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 4;
    *(longlong *)(param_1 + 0x60) = *(longlong *)(param_1 + 0x60) + 4;
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + -4;
    ExclusiveLock::ExclusiveLock(local_res20,(GenericLock *)(this + 200));
    puVar7 = auStack_38;
    for (this_00 = *(CMessageEntry **)(this + 0x158); this_00 != (CMessageEntry *)(this + 0x158);
        this_00 = *(CMessageEntry **)this_00) {
      if (*(int *)(this_00 + 0x30) == iVar1) {
        CMessageEntry::SetWaitEvent(this_00,param_1);
        puVar7 = auStack_38;
        goto LAB_140016ec9;
      }
    }
    pCVar4 = this + 0x148;
    plVar6 = (longlong *)(-(ulonglong)(param_1 != (CMemory *)0x0) & (ulonglong)(param_1 + 0x40));
    plVar5 = *(longlong **)(this + 0x150);
    if ((CRIMStreamProxy *)*plVar5 != pCVar4) {
      plVar5 = (longlong *)0x3;
      pcVar2 = (code *)swi(0x29);
      pCVar4 = (CRIMStreamProxy *)(*pcVar2)();
      puVar7 = auStack_30;
    }
    *plVar6 = (longlong)pCVar4;
    plVar6[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar6;
    *(longlong **)(pCVar4 + 8) = plVar6;
    LOCK();
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    UNLOCK();
LAB_140016ec9:
    *(undefined8 *)(puVar7 + -8) = 0x140016ed3;
    ExclusiveLock::~ExclusiveLock((ExclusiveLock *)(puVar7 + 0x58));
  }
  return lVar3;
}



===== OnDataReceived @ 140016ef0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: virtual long __cdecl CRIMStreamStub::OnDataReceived(class CMemory * __ptr64) __ptr64 */

long __thiscall CRIMStreamStub::OnDataReceived(CRIMStreamStub *this,CMemory *param_1)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  CMessage *local_res18;
  uchar *local_res20;
  
  local_res18 = (CMessage *)0x0;
  local_res20 = (uchar *)0x0;
  uVar3 = 8;
  lVar2 = CMemory::GetPrefix(param_1,&local_res20,8);
  if (-1 < lVar2) {
    uVar1 = *(ulong *)(local_res20 + 4);
    *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 4;
    *(longlong *)(param_1 + 0x60) = *(longlong *)(param_1 + 0x60) + 4;
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + -4;
    CRIMObjectPool<CMessage>::GetPooledObject
              (*(CRIMObjectPool<CMessage> **)(this + 0xb8),&local_res18,uVar3);
    if (local_res18 == (CMessage *)0x0) {
      lVar2 = -0x7ff8fff2;
    }
    else {
      lVar2 = CMessage::Initialize(local_res18,(CRIMStream *)this,uVar3,uVar1,param_1);
      if (-1 < lVar2) {
        lVar2 = (**(code **)(**(longlong **)(this + 200) + 0x18))
                          (*(longlong **)(this + 200),local_res18);
      }
    }
  }
  SmartPtr<CMessage>::~SmartPtr<CMessage>((SmartPtr<CMessage> *)&local_res18);
  return lVar2;
}



===== OnDisconnect @ 140016fc0 =====

/* public: virtual long __cdecl CRIMStreamProxy::OnDisconnect(void) __ptr64 */

long __thiscall CRIMStreamProxy::OnDisconnect(CRIMStreamProxy *this)

{
  CMessageEntry *pCVar1;
  CMessageEntry *this_00;
  ExclusiveLock local_res8 [8];
  
  ExclusiveLock::ExclusiveLock(local_res8,(GenericLock *)(this + 200));
  this_00 = *(CMessageEntry **)(this + 0x158);
  while (this_00 != (CMessageEntry *)(this + 0x158)) {
    pCVar1 = *(CMessageEntry **)this_00;
    CMessageEntry::SetWaitEvent(this_00,(CMemory *)0x0);
    this_00 = pCVar1;
  }
  *(undefined4 *)(this + 0x168) = 0;
  ExclusiveLock::~ExclusiveLock(local_res8);
  return 0;
}



===== ReceiveMessage @ 140017030 =====

/* public: virtual long __cdecl CRIMStreamProxy::ReceiveMessage(unsigned long,class CMemory *
   __ptr64 * __ptr64) __ptr64 */

long __thiscall
CRIMStreamProxy::ReceiveMessage(CRIMStreamProxy *this,ulong param_1,CMemory **param_2)

{
  CMemory *pCVar1;
  GenericLock *pGVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  long lVar7;
  CRIMStreamProxy *pCVar8;
  CMemory *this_00;
  CRIMStreamProxy *pCVar9;
  ExclusiveLock local_res8 [8];
  uchar *local_res18;
  CRIMStreamProxy *local_68;
  longlong *local_60;
  undefined1 local_58 [24];
  undefined8 local_40;
  ulong local_38;
  
  pGVar2 = (GenericLock *)(this + 200);
  *param_2 = (CMemory *)0x0;
  local_40 = 0;
  local_38 = param_1;
  ExclusiveLock::ExclusiveLock(local_res8,pGVar2);
  pCVar9 = this + 0x148;
  for (pCVar8 = *(CRIMStreamProxy **)pCVar9; pCVar8 != pCVar9; pCVar8 = *(CRIMStreamProxy **)pCVar8)
  {
    local_res18 = (uchar *)0x0;
    this_00 = (CMemory *)
              (-(ulonglong)(pCVar8 != (CRIMStreamProxy *)0x0) & (ulonglong)(pCVar8 + -0x40));
    lVar7 = CMemory::GetPrefix(this_00,&local_res18,8);
    if (lVar7 < 0) {
LAB_1400170ec:
      ExclusiveLock::~ExclusiveLock(local_res8);
      goto LAB_1400171fd;
    }
    if (param_1 == *(ulong *)(local_res18 + 4)) {
      if (this_00 != (CMemory *)0x0) {
        pCVar1 = this_00 + 0x40;
        lVar4 = *(longlong *)pCVar1;
        if ((*(CMemory **)(lVar4 + 8) == pCVar1) &&
           (plVar5 = *(longlong **)(this_00 + 0x48), (CMemory *)*plVar5 == pCVar1)) {
          *plVar5 = lVar4;
          lVar7 = 0;
          *(longlong **)(lVar4 + 8) = plVar5;
          *param_2 = this_00;
          goto LAB_1400170ec;
        }
        goto LAB_140017222;
      }
      break;
    }
  }
  KeInitializeEvent(local_58,0,0);
  plVar5 = *(longlong **)(this + 0x160);
  if ((CRIMStreamProxy *)*plVar5 == this + 0x158) {
    *plVar5 = (longlong)&local_68;
    *(CRIMStreamProxy ***)(this + 0x160) = &local_68;
    iVar3 = *(int *)(this + 0x168);
    local_68 = this + 0x158;
    local_60 = plVar5;
    ExclusiveLock::~ExclusiveLock(local_res8);
    if (iVar3 != 0) {
      lVar7 = CMessageEntry::Wait((CMessageEntry *)&local_68,param_2,
                                  *(ulong *)(*(longlong *)(this + 0xc0) + 0x1a8));
      if (lVar7 < 0) {
        ExclusiveLock::ExclusiveLock(local_res8,pGVar2);
        if ((*(CRIMStreamProxy ***)(local_68 + 8) != &local_68) ||
           ((CRIMStreamProxy **)*local_60 != &local_68)) goto LAB_140017222;
        *local_60 = (longlong)local_68;
        *(longlong **)(local_68 + 8) = local_60;
        ExclusiveLock::~ExclusiveLock(local_res8);
        CRIMObjManager::CloseChannel(*(CRIMObjManager **)(this + 0xc0));
        goto LAB_1400171fd;
      }
    }
    ExclusiveLock::ExclusiveLock(local_res8,pGVar2);
    if ((*(CRIMStreamProxy ***)(local_68 + 8) == &local_68) &&
       ((CRIMStreamProxy **)*local_60 == &local_68)) {
      *local_60 = (longlong)local_68;
      *(longlong **)(local_68 + 8) = local_60;
      ExclusiveLock::~ExclusiveLock(local_res8);
      lVar7 = -0x7ff8ff10;
      if (*param_2 != (CMemory *)0x0) {
        lVar7 = 0;
      }
LAB_1400171fd:
      SmartPtr<CMessage>::~SmartPtr<CMessage>((SmartPtr<CMessage> *)&local_40);
      return lVar7;
    }
  }
LAB_140017222:
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  pcVar6 = (code *)swi(3);
  lVar7 = (*pcVar6)();
  return lVar7;
}



===== ReleaseMessageId @ 140017230 =====

/* public: long __cdecl CRIMStream::ReleaseMessageId(unsigned long) __ptr64 */

long __thiscall CRIMStream::ReleaseMessageId(CRIMStream *this,ulong param_1)

{
  CRIMStream *pCVar1;
  char cVar2;
  long lVar3;
  ExclusiveLock local_res8 [8];
  
  pCVar1 = this + 0x18;
  ExclusiveLock::ExclusiveLock(local_res8,(GenericLock *)(this + 0x30));
  if (param_1 < *(uint *)pCVar1) {
    cVar2 = RtlAreBitsSet(pCVar1,param_1,1);
    lVar3 = 0;
    if (cVar2 != '\0') {
      RtlClearBits(pCVar1,param_1,1);
      *(int *)(this + 0x28) = *(int *)(this + 0x28) + -1;
      goto LAB_140017293;
    }
  }
  lVar3 = -0x7fffbffb;
LAB_140017293:
  ExclusiveLock::~ExclusiveLock(local_res8);
  return lVar3;
}



===== Resize @ 1400172b8 =====

/* private: long __cdecl CUniqueIdMap::Resize(void) __ptr64 */

long __thiscall CUniqueIdMap::Resize(CUniqueIdMap *this)

{
  uint uVar1;
  uint uVar2;
  void *_Src;
  long lVar3;
  undefined8 uVar4;
  void *_Dst;
  
  uVar2 = *(uint *)this;
  uVar1 = (uVar2 >> 5) + 0x10;
  uVar4 = SUB168(ZEXT816(4) * ZEXT416(uVar1),0);
  if (SUB168(ZEXT816(4) * ZEXT416(uVar1),8) != 0) {
    uVar4 = 0xffffffffffffffff;
  }
  _Dst = (void *)ExAllocatePoolWithTag(0x200,uVar4,0x72447244);
  if (_Dst == (void *)0x0) {
    lVar3 = -0x7ff8fff2;
  }
  else {
    _Src = *(void **)(this + 8);
    memset(_Dst,0,(ulonglong)uVar1 * 4);
    memmove(_Dst,_Src,(ulonglong)(uVar2 >> 5) << 2);
    if (_Src != (void *)0x0) {
      operator_delete(_Src);
    }
    RtlInitializeBitMap(this,_Dst,uVar1 * 0x20);
    lVar3 = 0;
  }
  return lVar3;
}



===== SetWaitEvent @ 14001738c =====

/* public: void __cdecl CRIMStreamProxy::CMessageEntry::SetWaitEvent(class CMemory * __ptr64)
   __ptr64 */

void __thiscall CRIMStreamProxy::CMessageEntry::SetWaitEvent(CMessageEntry *this,CMemory *param_1)

{
  SmartPtr<CMemory>::operator=((SmartPtr<CMemory> *)(this + 0x28),param_1);
  KeSetEvent(this + 0x10,0,0);
  return;
}



===== Wait @ 1400173c0 =====

/* public: long __cdecl CRIMStreamProxy::CMessageEntry::Wait(class CMemory * __ptr64 *
   __ptr64,unsigned long) __ptr64 */

long __thiscall
CRIMStreamProxy::CMessageEntry::Wait(CMessageEntry *this,CMemory **param_1,ulong param_2)

{
  CMemory *pCVar1;
  CImplIUnknownPool<IMessage> *this_00;
  uint uVar2;
  longlong *plVar3;
  longlong local_res8;
  
  local_res8 = 0;
  if (param_2 == 0xffffffff) {
    plVar3 = (longlong *)0x0;
  }
  else {
    local_res8 = (longlong)(int)param_2 * -10000;
    plVar3 = &local_res8;
  }
  uVar2 = KeWaitForSingleObject(this + 0x10,0,0,0,plVar3);
  if (uVar2 == 0x102) {
    uVar2 = 0xd0000210;
  }
  else {
    uVar2 = uVar2 | 0x10000000;
  }
  pCVar1 = *(CMemory **)(this + 0x28);
  *param_1 = pCVar1;
  if (pCVar1 != (CMemory *)0x0) {
    LOCK();
    *(int *)(pCVar1 + 0xc) = *(int *)(pCVar1 + 0xc) + 1;
    UNLOCK();
  }
  this_00 = *(CImplIUnknownPool<IMessage> **)(this + 0x28);
  *(undefined8 *)(this + 0x28) = 0;
  if (this_00 != (CImplIUnknownPool<IMessage> *)0x0) {
    CImplIUnknownPool<IMessage>::Release(this_00);
  }
  return uVar2;
}



===== WriteMessage @ 140017468 =====

/* public: long __cdecl CRIMStream::WriteMessage(unsigned long,class CMemory * __ptr64,unsigned
   long) __ptr64 */

long __thiscall
CRIMStream::WriteMessage(CRIMStream *this,ulong param_1,CMemory *param_2,ulong param_3)

{
  longlong lVar1;
  uchar *puVar2;
  long lVar3;
  int iVar4;
  CMemory *pCVar5;
  uchar *local_18 [2];
  
  local_18[0] = (uchar *)0x0;
  pCVar5 = param_2;
  lVar3 = CMemory::GetPrefix(param_2,local_18,8);
  puVar2 = local_18[0];
  if (-1 < lVar3) {
    local_18[0] = (uchar *)0x0;
    iVar4 = 4;
    *(ulong *)(puVar2 + 4) = param_1;
    *(int *)(pCVar5 + 0x58) = *(int *)(pCVar5 + 0x58) + -4;
    *(longlong *)(pCVar5 + 0x60) = *(longlong *)(pCVar5 + 0x60) + -4;
    *(int *)(pCVar5 + 0x68) = *(int *)(pCVar5 + 0x68) + 4;
    lVar1 = *(longlong *)(this + 0xc0);
    lVar3 = CMemory::GetPrefix(param_2,local_18,4);
    if (-1 < lVar3) {
      *(undefined4 *)local_18[0] = *(undefined4 *)(this + 0xb4);
      *(int *)(pCVar5 + 0x58) = *(int *)(pCVar5 + 0x58) + -4;
      *(longlong *)(pCVar5 + 0x60) = *(longlong *)(pCVar5 + 0x60) + -4;
      *(int *)(pCVar5 + 0x68) = *(int *)(pCVar5 + 0x68) + iVar4;
      *(ulong *)(pCVar5 + 0x6c) = param_3 + 8;
      lVar3 = CRimChannel::Write((CRimChannel *)(lVar1 + 0xe8),pCVar5);
    }
  }
  return lVar3;
}



===== GetInstanceOfProxy @ 140017510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GetInstanceOfProxy(longlong *param_1,IRIMStream *param_2,undefined8 *param_3)

{
  CImplIUnknown<IRIMCapabilitiesNegotiator> *this;
  undefined8 uVar1;
  longlong lVar2;
  
  lVar2 = 0x4ce0e9c117accf68 - *param_1;
  if (lVar2 == 0) {
    lVar2 = 0xfb346c80db91cfa6 - param_1[1];
  }
  if (lVar2 == 0) {
    this = (CImplIUnknown<IRIMCapabilitiesNegotiator> *)ExAllocatePoolWithTag(0x200,0x20,0x6c6d6952)
    ;
    if (this == (CImplIUnknown<IRIMCapabilitiesNegotiator> *)0x0) {
      *param_3 = 0;
      uVar1 = 0x8007000e;
    }
    else {
      CImplIUnknown<IRIMCapabilitiesNegotiator>::CImplIUnknown<IRIMCapabilitiesNegotiator>(this);
      *(undefined ***)this = &CProxyIUnknown<IRIMCapabilitiesNegotiator>::_vftable_;
      SmartPtr<IRIMStub>::SmartPtr<IRIMStub>((SmartPtr<IRIMStub> *)(this + 0x18),param_2);
      *(undefined ***)this =
           &CProxyIRIMCapabilitiesNegotiator<IRIMCapabilitiesNegotiator>::_vftable_;
      *param_3 = this;
      (**(code **)(*(longlong *)this + 8))(this);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x80004002;
  }
  return uVar1;
}



===== GetInstanceOfStub @ 1400175d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 GetInstanceOfStub(longlong *param_1,longlong *param_2,undefined8 *param_3)

{
  CImplIUnknown<IRIMStub> *this;
  undefined8 uVar1;
  longlong lVar2;
  
  lVar2 = 0x4ce0e9c117accf68 - *param_1;
  if (lVar2 == 0) {
    lVar2 = 0xfb346c80db91cfa6 - param_1[1];
  }
  if (lVar2 == 0) {
    this = (CImplIUnknown<IRIMStub> *)ExAllocatePoolWithTag(0x200,0x28,0x6c6d6952);
    if (this == (CImplIUnknown<IRIMStub> *)0x0) {
      *param_3 = 0;
      uVar1 = 0x8007000e;
    }
    else {
      CImplIUnknown<IRIMStub>::CImplIUnknown<IRIMStub>(this);
      *(undefined ***)this = &CStub<ITsRequestCompletion>::_vftable_;
      *(longlong **)(this + 0x18) = param_2;
      if (param_2 != (longlong *)0x0) {
        (**(code **)(*param_2 + 8))(param_2);
      }
      *(undefined4 *)(this + 0x20) = 0xffffffff;
      *(undefined ***)this = &CStubIRIMCapabilitiesNegotiator<IRIMCapabilitiesNegotiator>::_vftable_
      ;
      *param_3 = this;
      (**(code **)(*(longlong *)this + 8))(this);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x80004002;
  }
  return uVar1;
}



===== __GSHandlerCheck @ 1400176a8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400176cc =====

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



===== __cpu_features_init @ 140017740 =====

/* WARNING: Removing unreachable block (ram,0x0001400177aa) */
/* WARNING: Removing unreachable block (ram,0x000140017759) */
/* WARNING: Removing unreachable block (ram,0x00014001774a) */

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



===== __security_check_cookie @ 140017810 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140017850 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140017880 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140017880. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400178b0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 1400178e0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140017923;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140017994;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140017990:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140017994;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_14001798c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140017990;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_14001798c;
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
LAB_140017994:
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
LAB_140017923:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140017a00 =====

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



===== memset @ 140017d00 =====

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



===== __memset_repmovs @ 140017e40 =====

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



===== __memset_query @ 140017ec0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140017f40 =====

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



===== __memset_spec_ermsb_repmovsb @ 140018080 =====

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



===== __memset_spec_plain @ 140018100 =====

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



===== BdEvtDeviceAdd @ 140021010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int BdEvtDeviceAdd(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  void *pvVar2;
  undefined2 uVar3;
  undefined8 local_res10;
  WDFDEVICE__ *local_res18;
  CUsbHub *local_res20;
  undefined4 local_b8;
  undefined4 local_b4;
  code *local_b0;
  undefined8 local_a8;
  code *local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  code *local_88;
  undefined8 local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_b4 = 0;
  local_res18 = (WDFDEVICE__ *)0x0;
  local_res20 = (CUsbHub *)0x0;
  local_res10 = param_2;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,param_3,param_1);
  }
  if (DAT_14001d2b0 != (WDFDEVICE__ *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,param_3,DAT_14001d2b0);
    }
    return -0x3fffffff;
  }
  (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,local_res10,0x2a);
  (**(code **)(WdfFunctions_01015 + 0x1f0))(WdfDriverGlobals,local_res10,1);
  local_8c = 0;
  local_80 = 0;
  local_a8 = 0;
  local_60 = PTR__WDF_CUsbHub_TYPE_INFO_14001d068;
  local_88 = BdEvtDeviceContextCleanup;
  local_28 = 0;
  local_b0 = BdEvtDeviceFileCreate;
  local_48 = 0;
  local_a0 = BdEvtFileCleanup;
  uStack_50 = 0;
  local_90 = 0x38;
  local_58 = 0x38;
  local_70 = 0;
  uStack_68 = 0;
  local_78 = 2;
  local_74 = 2;
  local_38 = 0;
  uStack_30 = 0;
  uStack_40 = 0x100000001;
  local_b8 = 0x28;
  local_94 = 4;
  local_98 = 2;
  (**(code **)(WdfFunctions_01015 + 0x238))(WdfDriverGlobals,local_res10,&local_b8,&local_58);
  iVar1 = (**(code **)(WdfFunctions_01015 + 600))
                    (WdfDriverGlobals,&local_res10,&local_90,&local_res18);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar1;
    }
    uVar3 = 0xf;
  }
  else {
    pvVar2 = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                               (WdfDriverGlobals,local_res18,PTR__WDF_CUsbHub_TYPE_INFO_14001d068);
    iVar1 = CUsbHub::CreateInstance(local_res18,pvVar2,&local_res20);
    if (-1 < iVar1) {
      DAT_14001d2b0 = local_res18;
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar1;
    }
    uVar3 = 0x10;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_a7e2db3185263fa4450192ae3326bec7_Traceguids,iVar1);
  return iVar1;
}



===== BdEvtDeviceContextCleanup @ 140021260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BdEvtDeviceContextCleanup(undefined8 param_1)

{
  CUsbHub *this;
  
  this = (CUsbHub *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CUsbHub_TYPE_INFO_14001d068);
  if (this != (CUsbHub *)0x0) {
    CUsbHub::~CUsbHub(this);
  }
  return;
}



===== BdEvtDeviceFileCreate @ 1400212b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BdEvtDeviceFileCreate(undefined8 param_1,WDFREQUEST__ *param_2)

{
  CUsbHub *this;
  
  this = (CUsbHub *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CUsbHub_TYPE_INFO_14001d068);
  CUsbHub::EvtDeviceFileCreate(this,param_2);
  return;
}



===== BdEvtDeviceSinkCleanup @ 140021300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BdEvtDeviceSinkCleanup(undefined8 param_1)

{
  CDeviceSink *this;
  
  this = (CDeviceSink *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CDeviceSink_TYPE_INFO_14001d040);
  if (this != (CDeviceSink *)0x0) {
    CDeviceSink::~CDeviceSink(this);
  }
  return;
}



===== BdEvtDriverContextCleanup @ 140021350 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BdEvtDriverContextCleanup(undefined8 param_1)

{
  undefined *puVar1;
  
  (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  UninitializeKernelUtilities();
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
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  wil_UninitializeFeatureStaging();
  return;
}



===== BdEvtFileCleanup @ 140021400 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BdEvtFileCleanup(undefined8 param_1)

{
  undefined8 uVar1;
  CUsbHub *this;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x458))(WdfDriverGlobals,param_1);
  this = (CUsbHub *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,uVar1,PTR__WDF_CUsbHub_TYPE_INFO_14001d068);
  CUsbHub::EvtFileCleanup(this);
  return;
}



===== BdEvtIoDeviceControl @ 140021460 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BdEvtIoDeviceControl
               (undefined8 param_1,WDFREQUEST__ *param_2,undefined8 param_3,undefined8 param_4,
               ulong param_5)

{
  undefined8 uVar1;
  CUsbHub *this;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  this = (CUsbHub *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,uVar1,PTR__WDF_CUsbHub_TYPE_INFO_14001d068);
  CUsbHub::EvtIoDeviceControl(this,param_2,param_5);
  return;
}



===== BdEvtIoStop @ 1400214d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BdEvtIoStop(undefined8 param_1,WDFREQUEST__ *param_2,ulong param_3)

{
  undefined8 uVar1;
  CUsbHub *this;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  this = (CUsbHub *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,uVar1,PTR__WDF_CUsbHub_TYPE_INFO_14001d068);
  CUsbHub::EvtIoStop(this,param_2,param_3);
  return;
}



===== BdEvtRequestCancel_GetRequest @ 140021550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BdEvtRequestCancel_GetRequest(undefined8 param_1)

{
  undefined8 uVar1;
  WDFREQUEST__ *pWVar2;
  CUsbHub *this;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x8d0))(WdfDriverGlobals,param_1);
  pWVar2 = (WDFREQUEST__ *)(**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,uVar1);
  this = (CUsbHub *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,pWVar2,PTR__WDF_CUsbHub_TYPE_INFO_14001d068);
  CUsbHub::EvtRequestCancel_GetRequest(this,pWVar2);
  return;
}



===== BdEvtSessionCleanup @ 1400215d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void BdEvtSessionCleanup(undefined8 param_1)

{
  CSession *this;
  
  this = (CSession *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CSession_TYPE_INFO_14001d018);
  if (this != (CSession *)0x0) {
    CSession::~CSession(this);
  }
  return;
}



===== PdEvtChildListCreateDevice @ 140021620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

long PdEvtChildListCreateDevice(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  uint uVar1;
  ITsUsbDevice *pIVar2;
  short sVar3;
  int iVar4;
  undefined8 uVar5;
  code *pcVar6;
  void *pvVar7;
  uint uVar8;
  undefined *puVar9;
  undefined2 uVar10;
  wchar_t *pwVar11;
  uint uVar12;
  __uint64 _Var13;
  longlong lVar14;
  code *pcVar15;
  WDFDEVICE__ *pWVar16;
  CUsbHubPdo *this;
  uint uVar17;
  int iVar18;
  undefined1 auStackY_3b8 [32];
  undefined8 local_370;
  undefined2 local_368;
  uint local_364;
  uint local_360;
  ushort local_358;
  undefined1 auStack_356 [6];
  wchar_t *local_350;
  ulong local_348;
  ulong local_344;
  ulonglong local_340;
  wchar_t *local_338;
  wchar_t *local_330;
  WDFDEVICE__ *local_328;
  CUsbHubPdo *local_320;
  longlong local_318;
  WDFDEVICE__ *local_310;
  undefined8 local_308;
  undefined1 *local_300;
  CUsbHub *local_2f8;
  undefined8 local_2f0;
  code *pcStack_2e8;
  code *local_2e0;
  undefined8 uStack_2d8;
  undefined8 local_2d0;
  undefined8 uStack_2c8;
  undefined *local_2c0;
  undefined8 local_2b8;
  undefined8 uStack_2b0;
  undefined8 local_2a8;
  code *local_2a0;
  undefined8 local_298;
  undefined4 local_290;
  undefined4 local_28c;
  undefined8 local_288;
  undefined8 uStack_280;
  undefined *local_278;
  undefined4 local_268 [2];
  code *local_260;
  undefined4 local_228 [10];
  code *local_200;
  code *local_1f8;
  code *local_1c8;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined1 local_188 [160];
  wchar_t local_e8 [80];
  ulonglong local_48;
  
  pWVar16 = (WDFDEVICE__ *)&local_2b8;
  local_48 = __security_cookie ^ (ulonglong)auStackY_3b8;
  local_308 = 0xa00000;
  local_2c0 = (undefined *)0x0;
  this = (CUsbHubPdo *)0x0;
  local_300 = local_188;
  local_328 = (WDFDEVICE__ *)0x0;
  local_350 = local_e8;
  _local_358 = 0xa00000;
  local_318 = 0;
  local_198 = 0;
  uStack_190 = 0;
  local_2f0 = 0;
  pcStack_2e8 = (code *)0x0;
  local_2e0 = (code *)0x0;
  uStack_2d8 = 0;
  local_2d0 = 0;
  uStack_2c8 = 0;
  local_370 = param_3;
  memset(local_268,0,0x40);
  memset(local_228,0,0x90);
  local_2b8 = 0;
  uStack_2b0 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_a7e2db3185263fa4450192ae3326bec7_Traceguids);
  }
  local_344 = *(ulong *)(param_2 + 4);
  local_364 = *(uint *)(param_2 + 0x58);
  local_198 = *(undefined8 *)(param_2 + 0x18);
  uStack_190 = *(undefined8 *)(param_2 + 0x20);
  pwVar11 = *(wchar_t **)(param_2 + 0x60);
  uVar12 = *(uint *)(param_2 + 0x68);
  uVar1 = *(uint *)(param_2 + 0x48);
  local_348 = *(ulong *)(param_2 + 8);
  local_330 = *(wchar_t **)(param_2 + 0x70);
  local_310 = *(WDFDEVICE__ **)(param_2 + 0x50);
  pIVar2 = *(ITsUsbDevice **)(param_2 + 0x10);
  local_360 = uVar12;
  local_338 = pwVar11;
  uVar5 = (**(code **)(WdfFunctions_01015 + 8))(WdfDriverGlobals,param_1);
  local_2f8 = (CUsbHub *)
              (**(code **)(WdfFunctions_01015 + 0x650))
                        (WdfDriverGlobals,uVar5,PTR__WDF_CUsbHub_TYPE_INFO_14001d068);
  pcVar15 = (code *)0x22;
  local_320 = (CUsbHubPdo *)0x0;
  (**(code **)(WdfFunctions_01015 + 0x210))(WdfDriverGlobals,local_370);
  for (uVar17 = 0; uVar17 < 2; uVar17 = uVar17 + 1) {
    uVar8 = local_364;
    if (uVar17 != 0) {
      uVar8 = uVar12;
      pwVar11 = local_330;
    }
    _Var13 = (__uint64)uVar8;
    local_340 = 0;
    for (; (_Var13 != 0 && (*pwVar11 != L'\0')); pwVar11 = pwVar11 + local_340 + 1) {
      pcVar15 = (code *)&local_340;
      iVar4 = RtlStringCchLengthW((ushort *)pwVar11,_Var13,(__uint64 *)pcVar15);
      if (iVar4 < 0) {
        puVar9 = WPP_GLOBAL_Control;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14002201d;
        uVar10 = 0x12;
        goto LAB_14002200d;
      }
      uVar5 = PdValidatePnpId((longlong)pwVar11,local_340);
      iVar4 = (int)uVar5;
      if (iVar4 < 0) {
        puVar9 = WPP_GLOBAL_Control;
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14002201d;
        uVar10 = 0x13;
        goto LAB_1400218da;
      }
      pcVar15 = (code *)0x4;
      iVar4 = wcsncmp(pwVar11,L"USB\\",4);
      if (iVar4 != 0) {
        iVar4 = -0x3ffffff3;
        puVar9 = WPP_GLOBAL_Control;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          puVar9 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
          pcVar15 = (code *)&WPP_a7e2db3185263fa4450192ae3326bec7_Traceguids;
          WPP_SF_S(puVar9,0x14,&WPP_a7e2db3185263fa4450192ae3326bec7_Traceguids,pwVar11);
        }
        goto LAB_14002201d;
      }
      _Var13 = _Var13 + (-1 - local_340);
    }
    pwVar11 = local_338;
    uVar12 = local_360;
  }
  if (uVar1 == 0) {
    iVar4 = -0x3ffffff3;
    puVar9 = WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar10 = 0x15;
LAB_14002200d:
      puVar9 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      pcVar15 = (code *)&WPP_a7e2db3185263fa4450192ae3326bec7_Traceguids;
      WPP_SF_(puVar9,uVar10,&WPP_a7e2db3185263fa4450192ae3326bec7_Traceguids);
    }
LAB_14002201d:
  }
  else {
    uVar5 = PdValidatePnpId((longlong)local_310,(ulonglong)uVar1);
    uVar17 = local_364;
    iVar4 = (int)uVar5;
    puVar9 = WPP_GLOBAL_Control;
    if (iVar4 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar10 = 0x16;
LAB_1400218da:
        puVar9 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        pcVar15 = (code *)&WPP_a7e2db3185263fa4450192ae3326bec7_Traceguids;
        WPP_SF_D(puVar9,uVar10,&WPP_a7e2db3185263fa4450192ae3326bec7_Traceguids,iVar4);
      }
      goto LAB_14002201d;
    }
    if (local_364 == 0) {
      if (uVar12 == 0) {
        iVar4 = -0x3ffffff3;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar10 = 0x17;
          goto LAB_14002200d;
        }
        goto LAB_14002201d;
      }
      pwVar11 = local_330;
    }
    else {
      pwVar11 = local_338;
    }
    RtlInitUnicodeString(&local_358,pwVar11);
    pcVar15 = (code *)&local_358;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x6a0))(WdfDriverGlobals,local_370);
    iVar18 = 0;
    puVar9 = WPP_GLOBAL_Control;
    if (iVar4 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar10 = 0x18;
        goto LAB_1400218da;
      }
      goto LAB_14002201d;
    }
    uVar8 = (local_358 >> 1) + uVar1;
    if (uVar8 < uVar1) {
      iVar4 = -0x3fffff6b;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar10 = 0x19;
        goto LAB_1400218da;
      }
      goto LAB_14002201d;
    }
    if (0xab < uVar8) {
      iVar4 = -0x3ffffff3;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar10 = 0x1a;
        goto LAB_14002200d;
      }
      goto LAB_14002201d;
    }
    iVar4 = RtlStringFromGUID(&local_198,pWVar16);
    if (iVar4 < 0) {
      puVar9 = WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar10 = 0x1b;
        goto LAB_1400218da;
      }
      goto LAB_14002201d;
    }
    iVar4 = (**(code **)(WdfFunctions_01015 + 0xc38))(WdfDriverGlobals,local_370);
    if (iVar4 < 0) {
      puVar9 = WPP_GLOBAL_Control;
      pcVar15 = (code *)pWVar16;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar10 = 0x1c;
        goto LAB_1400218da;
      }
      goto LAB_14002201d;
    }
    for (; iVar18 < 2; iVar18 = iVar18 + 1) {
      if (iVar18 == 0) {
        if (uVar17 != 0) {
          pwVar11 = local_338;
LAB_140021b2d:
          _Var13 = (__uint64)uVar17;
          while ((_Var13 != 0 && (*pwVar11 != L'\0'))) {
            pcVar15 = (code *)&local_318;
            iVar4 = RtlStringCchLengthW((ushort *)pwVar11,_Var13,(__uint64 *)pcVar15);
            lVar14 = local_318;
            if (iVar4 < 0) {
              puVar9 = WPP_GLOBAL_Control;
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14002201d;
              uVar10 = 0x1d;
              goto LAB_1400218da;
            }
            pcVar15 = (code *)&local_358;
            sVar3 = (short)local_318 * 2;
            _local_358 = CONCAT62(CONCAT42(auStack_356._2_4_,sVar3),sVar3);
            if (iVar18 == 0) {
              pcVar6 = *(code **)(WdfFunctions_01015 + 0x6b0);
            }
            else {
              pcVar6 = *(code **)(WdfFunctions_01015 + 0x6b8);
            }
            local_350 = pwVar11;
            iVar4 = (*pcVar6)(WdfDriverGlobals,local_370);
            if (iVar4 < 0) {
              puVar9 = WPP_GLOBAL_Control;
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14002201d;
              uVar10 = 0x1e;
              goto LAB_1400218da;
            }
            pwVar11 = pwVar11 + lVar14 + 1;
            lVar14 = _Var13 - lVar14;
            _Var13 = lVar14 - 1;
            if (lVar14 == 0) {
              _Var13 = 0;
            }
          }
          uVar12 = local_360;
          uVar17 = local_364;
        }
      }
      else if (uVar12 != 0) {
        pwVar11 = local_330;
        uVar17 = local_360;
        goto LAB_140021b2d;
      }
    }
    pcVar15 = (code *)local_310;
    iVar4 = RtlUnicodeStringPrintf((_UNICODE_STRING *)&local_308,(ushort *)L"%s");
    if (iVar4 < 0) {
      puVar9 = WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar10 = 0x1f;
        goto LAB_1400218da;
      }
      goto LAB_14002201d;
    }
    pcVar15 = (code *)&local_308;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x6a8))(WdfDriverGlobals,local_370);
    if (iVar4 < 0) {
      puVar9 = WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar10 = 0x20;
        goto LAB_1400218da;
      }
      goto LAB_14002201d;
    }
    (**(code **)(WdfFunctions_01015 + 0x6c8))(WdfDriverGlobals,local_370,0x409);
    local_2c0 = PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0;
    pcStack_2e8 = PdEvtDeviceContextCleanup;
    local_2e0 = PdEvtDeviceContextDestroy;
    local_290 = 1;
    local_28c = 1;
    local_278 = PTR__WDF_CUsbHubPdoRequest_TYPE_INFO_14001d108;
    local_2a0 = PdEvtRequestContextCleanup;
    local_2f0 = 0x38;
    local_2d0 = 0;
    uStack_2c8 = 0;
    uStack_2d8 = 0x200000002;
    local_2a8 = 0x38;
    local_298 = 0;
    local_288 = 0;
    uStack_280 = 0;
    (**(code **)(WdfFunctions_01015 + 0x240))(WdfDriverGlobals,local_370,&local_2a8);
    memset(local_268,0,0x40);
    local_260 = PdEvtDeviceResourcesQuery;
    local_268[0] = 0x40;
    (**(code **)(WdfFunctions_01015 + 0x698))(WdfDriverGlobals,local_370,local_268);
    memset(local_228,0,0x90);
    local_200 = PdEvtDevicePrepareHardware;
    local_1f8 = PdEvtDeviceReleaseHardware;
    local_1c8 = PdEvtDeviceSurpriseRemoval;
    local_228[0] = 0x90;
    (**(code **)(WdfFunctions_01015 + 0x1b8))(WdfDriverGlobals,local_370,local_228);
    (**(code **)(WdfFunctions_01015 + 0x1e8))(WdfDriverGlobals,local_370,2);
    pcVar15 = PdEvtWdmIrpPreprocessCallback;
    local_368 = 0xc08;
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x248))
                      (WdfDriverGlobals,local_370,PdEvtWdmIrpPreprocessCallback,0x1b);
    if (iVar4 < 0) {
      puVar9 = WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar10 = 0x21;
        goto LAB_1400218da;
      }
      goto LAB_14002201d;
    }
    pcVar15 = (code *)&local_2f0;
    iVar4 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_370,pcVar15,&local_328);
    if (iVar4 < 0) {
      puVar9 = WPP_GLOBAL_Control;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar10 = 0x22;
        goto LAB_1400218da;
      }
      goto LAB_14002201d;
    }
    pvVar7 = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                               (WdfDriverGlobals,local_328,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
    pcVar15 = (code *)local_328;
    iVar4 = CUsbHubPdo::CreateInstance
                      (pvVar7,local_2f8,local_328,pIVar2,local_344,local_348,
                       (_USB_DEVICE_CAPABILITIES *)(param_2 + 0x28),&local_320);
    if (-1 < iVar4) {
      iVar4 = 0;
      goto LAB_14002203a;
    }
    puVar9 = WPP_GLOBAL_Control;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar9 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      pcVar15 = (code *)&WPP_a7e2db3185263fa4450192ae3326bec7_Traceguids;
      WPP_SF_D(puVar9,0x23,&WPP_a7e2db3185263fa4450192ae3326bec7_Traceguids,iVar4);
    }
    this = local_320;
  }
  if ((Microsoft_Windows_TerminalServices_ServerUSBDevicesEnableBits & 4) != 0) {
    McTemplateK0p_EtwWriteTransfer(puVar9,&EVENT_NOTIFY_CREATE_PDO_FAILED,pcVar15,pIVar2);
  }
LAB_14002203a:
  if (this != (CUsbHubPdo *)0x0) {
    CUsbHubPdo::~CUsbHubPdo(this);
  }
  return iVar4;
}



===== PdEvtDeviceContextCleanup @ 140022080 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdEvtDeviceContextCleanup(undefined8 param_1)

{
  CUsbHubPdo *this;
  
  this = (CUsbHubPdo *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
  CUsbHubPdo::EvtDeviceContextCleanup(this);
  return;
}



===== PdEvtDeviceContextDestroy @ 1400220c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdEvtDeviceContextDestroy(undefined8 param_1)

{
  CUsbHubPdo *this;
  
  this = (CUsbHubPdo *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
  if (this != (CUsbHubPdo *)0x0) {
    CUsbHubPdo::~CUsbHubPdo(this);
  }
  return;
}



===== PdEvtDevicePrepareHardware @ 140022110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdEvtDevicePrepareHardware(undefined8 param_1)

{
  CUsbHubPdo *this;
  
  this = (CUsbHubPdo *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
  CUsbHubPdo::EvtDevicePrepareHardware(this);
  return;
}



===== PdEvtDeviceReleaseHardware @ 140022150 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdEvtDeviceReleaseHardware(undefined8 param_1)

{
  CUsbHubPdo *this;
  
  this = (CUsbHubPdo *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
  CUsbHubPdo::EvtDeviceReleaseHardware(this);
  return;
}



===== PdEvtDeviceResourcesQuery @ 140022190 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdEvtDeviceResourcesQuery(undefined8 param_1)

{
  CUsbHubPdo *this;
  
  this = (CUsbHubPdo *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
  CUsbHubPdo::EvtDeviceResourcesQuery(this);
  return;
}



===== PdEvtDeviceSurpriseRemoval @ 1400221d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdEvtDeviceSurpriseRemoval(undefined8 param_1)

{
  CUsbHubPdo *this;
  
  this = (CUsbHubPdo *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
  CUsbHubPdo::EvtDeviceSurpriseRemoval(this);
  return;
}



===== PdEvtIoInternalDeviceControl @ 140022210 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdEvtIoInternalDeviceControl
               (undefined8 param_1,WDFREQUEST__ *param_2,undefined8 param_3,__uint64 param_4,
               ulong param_5)

{
  undefined8 uVar1;
  CUsbHubPdo *this;
  undefined *puVar2;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  puVar2 = PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0;
  this = (CUsbHubPdo *)(**(code **)(WdfFunctions_01015 + 0x650))(WdfDriverGlobals,uVar1);
  CUsbHubPdo::EvtIoInternalDeviceControl(this,param_2,(__uint64)puVar2,param_4,param_5);
  return;
}



===== PdEvtQueryBusTimeWorker @ 140022280 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdEvtQueryBusTimeWorker(undefined8 param_1)

{
  undefined8 uVar1;
  CUsbHubPdo *this;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  this = (CUsbHubPdo *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,uVar1,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
  CUsbHubPdo::EvtQueryBusTimeWorker(this);
  (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals,param_1);
  return;
}



===== PdEvtRequestCancel @ 140022300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdEvtRequestCancel(undefined8 param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_CUsbHubPdoRequest_TYPE_INFO_14001d108);
  (**(code **)*puVar1)(puVar1);
  return;
}



===== PdEvtTimerWorkItem @ 140022350 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdEvtTimerWorkItem(WDFWORKITEM__ *param_1)

{
  undefined8 uVar1;
  CUsbHubPdo *this;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0xbe8))(WdfDriverGlobals,param_1);
  this = (CUsbHubPdo *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,uVar1,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
  CUsbHubPdo::EvtTimerWorkItem(this,param_1);
  return;
}



===== PdEvtWdmIrpPreprocessCallback @ 1400223c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void PdEvtWdmIrpPreprocessCallback(undefined8 param_1,_IRP *param_2)

{
  CUsbHubPdo *this;
  
  this = (CUsbHubPdo *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CUsbHubPdo_TYPE_INFO_14001d0e0);
  CUsbHubPdo::EvtWdmIrpPreprocessCallback(this,param_2);
  return;
}



===== PdValidatePnpId @ 140022408 =====

undefined8 PdValidatePnpId(longlong param_1,ulonglong param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  if (param_2 < 0xc9) {
    uVar2 = 0;
    for (uVar3 = 0; (uVar3 < param_2 && (uVar1 = *(ushort *)(param_1 + uVar3 * 2), uVar1 != 0));
        uVar3 = uVar3 + 1) {
      if ((uVar1 < 0x20) || ((0x7f < uVar1 || (uVar1 == 0x2c)))) goto LAB_140022441;
    }
  }
  else {
LAB_140022441:
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== WppInitKm @ 140022450 =====

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



===== WppLoadTracingSupport @ 1400224e0 =====

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



===== WppTraceCallback @ 140022630 =====

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
        memmove((ushort *)((ulonglong)uVar11 + (longlong)param_4) + 1,*(void **)(puVar3 + 4),
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



===== wil_RtlStagingConfig_QueryFeatureState @ 1400228b8 =====

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



===== wil_UninitializeFeatureStaging @ 140022984 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1400229dc =====

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
      goto LAB_140022a39;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_140022a39;
    }
  }
  uVar1 = 0x206;
LAB_140022a39:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140022a44 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 140022afc =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140022b34 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_140022bb6;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_140022bb6;
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
LAB_140022bb6:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140022c00 =====

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



===== wil_details_RecordFeatureUsageCallback @ 140022c54 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140022c70 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 140022c8c =====

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



===== __security_init_cookie @ 140023008 =====

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



===== DriverEntry @ 14002303c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 local_res18;
  undefined8 local_68;
  code *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  code *pcStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res18 = 0;
  wil_InitializeFeatureStaging();
  Feature_1741656378__private_IsEnabledDeviceUsageNoInline();
  local_68 = 0x20;
  local_48 = 0x38;
  local_60 = BdEvtDeviceAdd;
  local_18 = 0;
  local_38 = 0;
  pcStack_40 = BdEvtDriverContextCleanup;
  local_58 = 0;
  uStack_50 = 0;
  uStack_30 = 0x100000001;
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,&local_48,&local_68,&local_res18);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_a7e2db3185263fa4450192ae3326bec7_Traceguids,iVar1);
    }
  }
  else {
    _WPP_MAIN_CB = 0;
    DAT_14001d2f8 = &WPP_ThisDir_CTLGUID_CtlGuid;
    DAT_14001d300 = 0;
    _DAT_14001d310 = 0;
    _DAT_14001d318 = 1;
    WppLoadTracingSupport();
    _DAT_14001d310 = 0;
    WppInitKm();
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
              &WPP_a7e2db3185263fa4450192ae3326bec7_Traceguids);
    }
    iVar1 = InitializeKernelUtilities();
    if (iVar1 != 0) {
      return 0;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_a7e2db3185263fa4450192ae3326bec7_Traceguids);
    }
    iVar1 = -0x3fffff66;
  }
  wil_UninitializeFeatureStaging();
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 140023200 =====

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
          g_wil_details_featureChangeNotification = 0;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1400232f0 =====

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


