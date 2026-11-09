
===== __report_gsfailure @ 140001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0xf7,_StackCookie,__security_cookie,__security_cookie_complement,0);
}



===== __GSHandlerCheck @ 140001044 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140001068 =====

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



===== __cpu_features_init @ 1400010e0 =====

/* WARNING: Removing unreachable block (ram,0x00014000114a) */
/* WARNING: Removing unreachable block (ram,0x0001400010f9) */
/* WARNING: Removing unreachable block (ram,0x0001400010ea) */

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



===== __C_specific_handler @ 1400011a6 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400011a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== ~CGenericUSB @ 1400011b8 =====

/* public: __cdecl CGenericUSB::~CGenericUSB(void) __ptr64 */

void __thiscall CGenericUSB::~CGenericUSB(CGenericUSB *this)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(this + 0x28);
  if (lVar1 != 0) {
    if (*(longlong *)(lVar1 + 8) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar1 + 8),0);
    }
    ExFreePoolWithTag(lVar1,0);
  }
  *(undefined8 *)(this + 0x28) = 0;
  lVar1 = *(longlong *)(this + 0x30);
  if (lVar1 != 0) {
    if (*(longlong *)(lVar1 + 8) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar1 + 8),0);
    }
    ExFreePoolWithTag(lVar1,0);
  }
  *(undefined8 *)(this + 0x30) = 0;
  lVar1 = *(longlong *)(this + 0x38);
  if (lVar1 != 0) {
    if (*(longlong *)(lVar1 + 8) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar1 + 8),0);
    }
    ExFreePoolWithTag(lVar1,0);
  }
  *(undefined8 *)(this + 0x38) = 0;
  if (*(longlong *)(this + 0x18) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(this + 0x18) = 0;
  }
  return;
}



===== CreateInstance @ 140001294 =====

/* public: static long __cdecl CGenericUSB::CreateInstance(struct WDFDEVICE__ * __ptr64,void *
   __ptr64,class CGenericUSB * __ptr64 * __ptr64) */

long __cdecl CGenericUSB::CreateInstance(WDFDEVICE__ *param_1,void *param_2,CGenericUSB **param_3)

{
  longlong lVar1;
  long lVar2;
  
  if (param_2 == (void *)0x0) {
    lVar2 = -0x3fffffe9;
  }
  else {
    lVar1 = (longlong)param_2 + 0x40;
    *(undefined8 *)((longlong)param_2 + 0x18) = 0;
    *(undefined8 *)((longlong)param_2 + 0x20) = 0;
    *(undefined8 *)((longlong)param_2 + 0x28) = 0;
    *(undefined8 *)((longlong)param_2 + 0x30) = 0;
    *(undefined8 *)((longlong)param_2 + 0x38) = 0;
    *(undefined8 *)((longlong)param_2 + 0x50) = 0;
    *(longlong *)((longlong)param_2 + 0x48) = lVar1;
    *(longlong *)lVar1 = lVar1;
    lVar2 = Initialize(param_2,param_1);
    if (lVar2 < 0) {
      ~CGenericUSB(param_2);
    }
    else {
      *param_3 = param_2;
      lVar2 = 0;
    }
  }
  return lVar2;
}



===== EvtDeviceFileCreate @ 140001320 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: void __cdecl CGenericUSB::EvtDeviceFileCreate(struct WDFREQUEST__ * __ptr64,struct
   WDFFILEOBJECT__ * __ptr64) __ptr64 */

void __thiscall
CGenericUSB::EvtDeviceFileCreate(CGenericUSB *this,WDFREQUEST__ *param_1,WDFFILEOBJECT__ *param_2)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  ushort *puVar4;
  WDFFILEOBJECT__ *pWVar5;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_38 = 0;
  lStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  pWVar5 = param_2;
  lVar3 = IoGetCurrentProcess();
  if (lVar3 == *(longlong *)(this + 0x18)) {
    puVar4 = (ushort *)(**(code **)(WdfFunctions_01015 + 0x448))(WdfDriverGlobals,param_2);
    if (((puVar4 != (ushort *)0x0) && (1 < *puVar4)) && (**(short **)(puVar4 + 4) == 0x5c)) {
      local_38._0_4_ = CONCAT22(puVar4[1] - 2,*puVar4 - 2);
      lStack_30 = *(longlong *)(puVar4 + 4) + 2;
      uVar1 = RtlGUIDFromString(&local_38,&local_28);
      if (-1 < (int)uVar1) {
        iVar2 = memcmp(&local_28,this + 8,0x10);
        uVar1 = -(uint)(iVar2 != 0) & 0xc000000d;
      }
      goto LAB_14000143b;
    }
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),2,pWVar5,lVar3);
  }
  uVar1 = 0xc000000d;
LAB_14000143b:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,uVar1);
  return;
}



===== Initialize @ 14000147c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: long __cdecl CGenericUSB::Initialize(struct WDFDEVICE__ * __ptr64) __ptr64 */

long __thiscall CGenericUSB::Initialize(CGenericUSB *this,WDFDEVICE__ *param_1)

{
  CGenericUSB *pCVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined2 uVar5;
  undefined1 auStack_168 [32];
  undefined8 *local_148;
  longlong *local_140;
  undefined8 local_138;
  undefined8 local_130;
  longlong local_118 [2];
  undefined8 *puStack_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  WDFDEVICE__ *local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined1 local_9b;
  code *local_80;
  code *local_70;
  undefined4 local_58;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_168;
  memset(&local_a8,0,0x60);
  *(WDFDEVICE__ **)this = param_1;
  local_b8 = 0;
  local_100 = 0;
  local_f0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_f8 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_118[0] = 0;
  local_c8 = (WDFDEVICE__ *)0x0;
  uStack_c0 = 0;
  local_118[1] = 0;
  puStack_108 = (undefined8 *)0x0;
  local_48 = 0;
  uStack_40 = 0;
  uVar3 = (**(code **)(WdfFunctions_01015 + 0x150))(WdfDriverGlobals,param_1);
  *(undefined8 *)(this + 0x20) = uVar3;
  pCVar1 = this + 0x40;
  *(CGenericUSB **)(this + 0x48) = pCVar1;
  *(CGenericUSB **)pCVar1 = pCVar1;
  uVar3 = WdfDriverGlobals;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x9d8))(WdfDriverGlobals,0,this + 0x50);
  uVar4 = (ulong)uVar3;
  if (iVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000193a;
    uVar5 = 10;
  }
  else {
    iVar2 = CSimpleHash::CreateInstance(uVar4,(CSimpleHash **)(this + 0x28));
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000193a;
      uVar5 = 0xb;
    }
    else {
      iVar2 = CSimpleHash::CreateInstance(uVar4,(CSimpleHash **)(this + 0x30));
      if (iVar2 < 0) {
        if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000193a;
        uVar5 = 0xc;
      }
      else {
        iVar2 = CSimpleHash::CreateInstance(uVar4,(CSimpleHash **)(this + 0x38));
        if (iVar2 < 0) {
          if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000193a;
          uVar5 = 0xd;
        }
        else {
          local_58 = 0xffffffff;
          local_80 = GdEvtIoDeviceControl;
          local_148 = &local_f0;
          local_a8 = 0x60;
          local_70 = GdEvtIoStop;
          local_a0 = 2;
          local_9b = 1;
          local_a4 = 2;
          iVar2 = (**(code **)(WdfFunctions_01015 + 0x4c0))(WdfDriverGlobals,param_1,&local_a8,0);
          if (iVar2 < 0) {
            if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000193a;
            uVar5 = 0xe;
          }
          else {
            local_e8 = CONCAT44(local_e8._4_4_,0x38);
            uStack_d0 = 0x100000001;
            local_c8 = param_1;
            iVar2 = (**(code **)(WdfFunctions_01015 + 0x7b8))
                              (WdfDriverGlobals,&local_e8,*(undefined8 *)(this + 0x20),local_118);
            if (iVar2 < 0) {
              if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                 ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000193a;
              uVar5 = 0xf;
            }
            else {
              puStack_108 = &local_48;
              local_140 = local_118 + 1;
              local_130 = 0;
              local_138 = 0;
              local_118[1] = 1;
              local_100 = 0x10;
              local_148 = (undefined8 *)0x0;
              iVar2 = (**(code **)(WdfFunctions_01015 + 0x5e0))
                                (WdfDriverGlobals,*(undefined8 *)(this + 0x20),local_118[0],0x224403
                                );
              if (iVar2 < 0) {
                if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                   ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000193a;
                uVar5 = 0x10;
              }
              else {
                puStack_108 = &local_f8;
                local_140 = local_118 + 1;
                *(undefined4 *)(this + 8) = (undefined4)local_48;
                *(undefined4 *)(this + 0xc) = local_48._4_4_;
                *(undefined4 *)(this + 0x10) = (undefined4)uStack_40;
                *(undefined4 *)(this + 0x14) = uStack_40._4_4_;
                local_130 = 0;
                local_138 = 0;
                local_118[1] = 1;
                local_100 = 8;
                local_148 = (undefined8 *)0x0;
                iVar2 = (**(code **)(WdfFunctions_01015 + 0x5e0))
                                  (WdfDriverGlobals,*(undefined8 *)(this + 0x20),local_118[0],
                                   0x224407);
                if (iVar2 < 0) {
                  if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000193a;
                  uVar5 = 0x11;
                }
                else {
                  *(undefined8 *)(this + 0x18) = local_f8;
                  iVar2 = (**(code **)(WdfFunctions_01015 + 0x268))
                                    (WdfDriverGlobals,param_1,this + 8,0);
                  if (iVar2 < 0) {
                    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000193a;
                    uVar5 = 0x12;
                  }
                  else {
                    iVar2 = (**(code **)(WdfFunctions_01015 + 0x268))
                                      (WdfDriverGlobals,param_1,&GUID_DEVINTERFACE_TSUSBGD,0);
                    if (iVar2 < 0) {
                      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000193a;
                      uVar5 = 0x13;
                    }
                    else {
                      iVar2 = InitializeInterface(this);
                      if (-1 < iVar2) {
                        iVar2 = 0;
                        goto LAB_14000193a;
                      }
                      if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                         ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14000193a;
                      uVar5 = 0x14;
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
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_e22684400aa030ec2c531d4dcef4cab4_Traceguids,iVar2);
LAB_14000193a:
  if (local_118[0] != 0) {
    (**(code **)(WdfFunctions_01015 + 0x680))(WdfDriverGlobals);
  }
  return iVar2;
}



===== InitializeInterface @ 14000198c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: long __cdecl CGenericUSB::InitializeInterface(void) __ptr64 */

long __thiscall CGenericUSB::InitializeInterface(CGenericUSB *this)

{
  CGenericUSB *pCVar1;
  int iVar2;
  
  pCVar1 = this + 0x58;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x588))
                    (WdfDriverGlobals,*(undefined8 *)(this + 0x20),&USB_BUS_INTERFACE_USBDI_GUID,
                     pCVar1,0x50,2,0);
  if (iVar2 < 0) {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x588))
                      (WdfDriverGlobals,*(undefined8 *)(this + 0x20),&USB_BUS_INTERFACE_USBDI_GUID,
                       pCVar1,0x48,1,0);
    if (iVar2 < 0) {
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x588))
                        (WdfDriverGlobals,*(undefined8 *)(this + 0x20),&USB_BUS_INTERFACE_USBDI_GUID
                         ,pCVar1,0x40,0,0);
      if (((iVar2 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                 &WPP_e22684400aa030ec2c531d4dcef4cab4_Traceguids,iVar2);
      }
    }
  }
  return iVar2;
}



===== WPP_SF_D @ 140001ac8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_q @ 140001b0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e22684400aa030ec2c531d4dcef4cab4_Traceguids,0x16,&local_res20,8,0);
  return;
}



===== IoCtlCompletionQueryDeviceText @ 140001b58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CGenericUSB::IoCtlCompletionQueryDeviceText(struct WDFREQUEST__ *
   __ptr64,struct _WDF_REQUEST_COMPLETION_PARAMS * __ptr64) __ptr64 */

void __thiscall
CGenericUSB::IoCtlCompletionQueryDeviceText
          (CGenericUSB *this,WDFREQUEST__ *param_1,_WDF_REQUEST_COMPLETION_PARAMS *param_2)

{
  longlong lVar1;
  ulonglong _Size;
  short *_Src;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined2 *local_res8 [2];
  longlong local_res18;
  undefined8 local_res20;
  
  iVar3 = *(int *)(param_2 + 8);
  lVar4 = 0;
  local_res20 = 0;
  local_res8[0] = (undefined2 *)0x0;
  if (iVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar3);
    }
    goto LAB_140001cd6;
  }
  _Src = *(short **)(param_2 + 0x10);
  local_res18 = 0;
  if (_Src == (short *)0x0) {
LAB_140001cbb:
    iVar3 = -0x3ffffff0;
    if (_Src == (short *)0x0) goto LAB_140001cd6;
  }
  else {
    uVar2 = RtlStringLengthWorkerW(_Src,param_1,&local_res18);
    if ((int)uVar2 < 0) goto LAB_140001cbb;
    _Size = local_res18 * 2 + 2;
    lVar1 = local_res18 * 2 + 4;
    lVar5 = lVar1;
    iVar3 = (**(code **)(WdfFunctions_01015 + 0x870))
                      (WdfDriverGlobals,param_1,lVar1,local_res8,&local_res20);
    if (iVar3 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,lVar5,local_res20);
      }
      iVar3 = -0x3fffffdd;
LAB_140001c56:
      lVar4 = lVar1;
    }
    else {
      if (_Size < 0x10000) {
        *local_res8[0] = (short)(_Size >> 1);
        memmove(local_res8[0] + 1,_Src,_Size);
        iVar3 = 0;
        goto LAB_140001c56;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,lVar5,_Size);
      }
      iVar3 = -0x3fffff1b;
    }
  }
  ExFreePoolWithTag(_Src,0);
LAB_140001cd6:
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,iVar3,lVar4);
  return;
}



===== IoCtlCompletionSubmitUrb @ 140001d0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: void __cdecl CGenericUSB::IoCtlCompletionSubmitUrb(struct WDFREQUEST__ * __ptr64,struct
   _WDF_REQUEST_COMPLETION_PARAMS * __ptr64) __ptr64 */

void __thiscall
CGenericUSB::IoCtlCompletionSubmitUrb
          (CGenericUSB *this,WDFREQUEST__ *param_1,_WDF_REQUEST_COMPLETION_PARAMS *param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  longlong *plVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  undefined8 *puVar11;
  undefined4 local_res8 [2];
  undefined8 local_res20;
  
  uVar10 = 0;
  local_res8[0] = 0;
  local_res20 = 0;
  plVar6 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_REQUEST_EXTENSION_TYPE_INFO_14000b018);
  puVar11 = &local_res20;
  puVar7 = (undefined2 *)(**(code **)(WdfFunctions_01015 + 0x610))(WdfDriverGlobals,plVar6[0xdd]);
  lVar2 = plVar6[0xd9];
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(this + 0x50));
  lVar3 = *plVar6;
  if ((*(longlong **)(lVar3 + 8) != plVar6) ||
     (plVar4 = (longlong *)plVar6[1], (longlong *)*plVar4 != plVar6)) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(3);
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  *plVar4 = lVar3;
  *(longlong **)(lVar3 + 8) = plVar4;
  uVar9 = *(undefined8 *)(this + 0x50);
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals);
  iVar1 = *(int *)(param_2 + 8);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_Dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,puVar11,
                (uint)*(ushort *)(plVar6[0xd9] + 2),(char)iVar1);
    }
    *puVar7 = 8;
    iVar8 = -0x3fff7000;
    if (*(int *)(lVar2 + 4) < 0) {
      iVar8 = *(int *)(lVar2 + 4);
    }
    *(int *)(puVar7 + 2) = iVar8;
  }
  else {
    if (((*(ushort *)(lVar2 + 2) != puVar7[1]) &&
        ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
                &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,(uint)(ushort)puVar7[1],
                (char)*(undefined2 *)(plVar6[0xd9] + 2));
    }
    if (((*(int *)(lVar2 + 4) < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,(uint)*(ushort *)(lVar2 + 2),
                (char)*(int *)(lVar2 + 4));
    }
    (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,*(undefined8 *)this);
    (**(code **)(plVar6[5] + 8))
              (plVar6 + 5,*(undefined8 *)(this + 0x38),*(undefined8 *)(this + 0x28),
               *(undefined8 *)(this + 0x30),puVar7,(undefined4)local_res20,local_res8);
    (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,*(undefined8 *)this);
    uVar10 = local_res8[0];
  }
  (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,iVar1,uVar10);
  return;
}



===== IoCtlControlSubmitUrb @ 140001f84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl CGenericUSB::IoCtlControlSubmitUrb(struct WDFREQUEST__ * __ptr64) __ptr64
    */

void __thiscall CGenericUSB::IoCtlControlSubmitUrb(CGenericUSB *this,WDFREQUEST__ *param_1)

{
  longlong *plVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong lVar7;
  undefined1 auStack_98 [48];
  undefined2 local_68 [4];
  longlong local_60;
  undefined4 local_50;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_98;
  plVar5 = (longlong *)
           (**(code **)(WdfFunctions_01015 + 0x650))
                     (WdfDriverGlobals,param_1,PTR__WDF_REQUEST_EXTENSION_TYPE_INFO_14000b018);
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x8a8))(WdfDriverGlobals,param_1);
  lVar7 = 0;
  if (lVar6 != 0) {
    lVar7 = (**(code **)(WdfFunctions_01015 + 0x460))(WdfDriverGlobals,lVar6);
  }
  plVar5[2] = (longlong)param_1;
  plVar5[3] = lVar7;
  (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(this + 0x50));
  plVar1 = *(longlong **)(this + 0x48);
  if ((CGenericUSB *)*plVar1 != this + 0x40) {
LAB_1400021fb:
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(3);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  *plVar5 = (longlong)(this + 0x40);
  plVar5[1] = (longlong)plVar1;
  *plVar1 = (longlong)plVar5;
  *(longlong **)(this + 0x48) = plVar5;
  (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals);
  memset(local_68,0,0x48);
  local_68[0] = 0xf;
  local_50 = 0x220003;
  local_60 = plVar5[0xd9];
  (**(code **)(WdfFunctions_01015 + 0x7e0))(WdfDriverGlobals,param_1,local_68);
  (**(code **)(WdfFunctions_01015 + 0x820))
            (WdfDriverGlobals,param_1,GdEvtIoCompletionSubmitUrb,this);
  cVar3 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                    (WdfDriverGlobals,param_1,*(undefined8 *)(this + 0x20),0);
  if (cVar3 == '\0') {
    iVar4 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
               &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar4);
    }
    if (iVar4 < 0) {
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(this + 0x50));
      lVar7 = *plVar5;
      if ((*(longlong **)(lVar7 + 8) != plVar5) ||
         (plVar1 = (longlong *)plVar5[1], (longlong *)*plVar1 != plVar5)) goto LAB_1400021fb;
      *plVar1 = lVar7;
      *(longlong **)(lVar7 + 8) = plVar1;
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(this + 0x50));
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,iVar4,0);
    }
  }
  return;
}



===== IoCtlGenericForwardAndForget @ 140002208 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl CGenericUSB::IoCtlGenericForwardAndForget(struct WDFREQUEST__ * __ptr64)
   __ptr64 */

void __thiscall CGenericUSB::IoCtlGenericForwardAndForget(CGenericUSB *this,WDFREQUEST__ *param_1)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_58 [48];
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_20 = 0;
  local_28 = 0x10;
  local_24 = 8;
  cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                    (WdfDriverGlobals,param_1,*(undefined8 *)(this + 0x20),&local_28);
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar2);
    }
    if (iVar2 < 0) {
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,iVar2);
    }
  }
  return;
}



===== IoCtlGenericForwardUSB @ 1400022f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl CGenericUSB::IoCtlGenericForwardUSB(struct WDFREQUEST__ * __ptr64,unsigned
   long,unsigned __int64) __ptr64 */

void __thiscall
CGenericUSB::IoCtlGenericForwardUSB
          (CGenericUSB *this,WDFREQUEST__ *param_1,ulong param_2,__uint64 param_3)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStack_f8 [32];
  __uint64 *local_d8;
  __uint64 local_c8;
  undefined8 local_c0;
  undefined2 local_b8 [4];
  undefined8 local_b0;
  ulong local_a0;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_f8;
  memset(local_b8,0,0x48);
  local_c8 = 0;
  local_c0 = 0;
  local_50 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_REQUEST_EXTENSION_TYPE_INFO_14000b018);
  if (param_3 != 0) {
    local_d8 = &local_c8;
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_1,param_3,&local_c0);
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                 &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar2);
      }
      goto LAB_140002536;
    }
    if (local_c8 != param_3) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,local_c8,local_c8);
      }
      iVar2 = -0x3ffffff3;
      goto LAB_140002536;
    }
  }
  *(__uint64 *)(lVar3 + 0x6e8) = local_c8;
  local_70 = CONCAT62(local_70._2_6_,0x28);
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_1,&local_70);
  local_b0 = local_c0;
  local_b8[0] = 0xf;
  local_a0 = param_2;
  (**(code **)(WdfFunctions_01015 + 0x7e0))(WdfDriverGlobals,param_1,local_b8);
  (**(code **)(WdfFunctions_01015 + 0x820))(WdfDriverGlobals,param_1,GdEvtIoCompletionGeneric,this);
  cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                    (WdfDriverGlobals,param_1,*(undefined8 *)(this + 0x20),0);
  if (cVar1 != '\0') {
    return;
  }
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar2);
  }
  if (-1 < iVar2) {
    return;
  }
LAB_140002536:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,iVar2);
  return;
}



===== IoCtlGetControllerName @ 14000257c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl CGenericUSB::IoCtlGetControllerName(struct WDFREQUEST__ * __ptr64) __ptr64
    */

void __thiscall CGenericUSB::IoCtlGetControllerName(CGenericUSB *this,WDFREQUEST__ *param_1)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_d8 [32];
  undefined8 *local_b8;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined2 local_98 [4];
  undefined8 local_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_d8;
  memset(local_98,0,0x48);
  local_b8 = &local_a0;
  local_a0 = 0;
  local_a8 = 0;
  local_30 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))(WdfDriverGlobals,param_1,4,&local_a8);
  if (iVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
               &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar2);
    }
  }
  else {
    local_50 = CONCAT62(local_50._2_6_,0x28);
    (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_1,&local_50);
    local_90 = local_a8;
    local_88 = local_a0;
    local_98[0] = 0xf;
    local_80 = 0x220424;
    (**(code **)(WdfFunctions_01015 + 0x7e0))(WdfDriverGlobals,param_1,local_98);
    (**(code **)(WdfFunctions_01015 + 0x820))
              (WdfDriverGlobals,param_1,GdEvtIoCompletionGetControllerName,this);
    cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                      (WdfDriverGlobals,param_1,*(undefined8 *)(this + 0x20),0);
    if (cVar1 != '\0') {
      return;
    }
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
               &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar2);
    }
    if (-1 < iVar2) {
      return;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,iVar2);
  return;
}



===== IoCtlGetHubName @ 140002794 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl CGenericUSB::IoCtlGetHubName(struct WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall CGenericUSB::IoCtlGetHubName(CGenericUSB *this,WDFREQUEST__ *param_1)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_c8 [48];
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined2 local_60 [4];
  undefined4 local_58;
  undefined4 local_50;
  undefined4 local_48;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  memset(local_60,0,0x48);
  local_90 = 0;
  local_68 = 0;
  uStack_80 = 0;
  local_88 = 0x28;
  local_78 = 0;
  uStack_70 = 0;
  (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_1,&local_88);
  local_50 = (undefined4)local_78;
  local_58 = (undefined4)uStack_80;
  local_60[0] = 0xf;
  local_48 = 0x220020;
  (**(code **)(WdfFunctions_01015 + 0x7e0))(WdfDriverGlobals,param_1,local_60);
  local_90 = 0;
  local_98 = 0x10;
  local_94 = 8;
  cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                    (WdfDriverGlobals,param_1,*(undefined8 *)(this + 0x20),&local_98);
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
               &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar2);
    }
    if (iVar2 < 0) {
      (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,iVar2);
    }
  }
  return;
}



===== IoCtlInCallerCancelRequest @ 140002920 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl CGenericUSB::IoCtlInCallerCancelRequest(struct WDFREQUEST__ * __ptr64)
   __ptr64 */

void __thiscall CGenericUSB::IoCtlInCallerCancelRequest(CGenericUSB *this,WDFREQUEST__ *param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined2 uVar4;
  CGenericUSB *pCVar5;
  longlong lVar6;
  undefined8 *local_res18;
  longlong local_res20;
  undefined8 local_38 [2];
  
  local_38[0] = 0;
  local_res18 = (undefined8 *)0x0;
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,param_1,PTR__WDF_REQUEST_EXTENSION_TYPE_INFO_14000b018);
  local_res20 = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))
                    (WdfDriverGlobals,param_1,0x10,&local_res18,local_38);
  if (iVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002b98;
    uVar4 = 0x11;
  }
  else {
    iVar2 = ObReferenceObjectByHandle
                      (*local_res18,0,*(undefined8 *)IoFileObjectType_exref,1,&local_res20,0);
    if (-1 < iVar2) {
      lVar6 = 0;
      lVar1 = local_res18[1];
      (**(code **)(WdfFunctions_01015 + 0x9e0))(WdfDriverGlobals,*(undefined8 *)(this + 0x50));
      for (pCVar5 = *(CGenericUSB **)(this + 0x40); pCVar5 != this + 0x40;
          pCVar5 = *(CGenericUSB **)pCVar5) {
        if ((*(longlong *)(pCVar5 + 0x18) == local_res20) &&
           (lVar3 = (**(code **)(WdfFunctions_01015 + 0x8e8))
                              (WdfDriverGlobals,*(undefined8 *)(pCVar5 + 0x10)),
           *(longlong *)(lVar3 + 0x48) == lVar1)) {
          lVar6 = *(longlong *)(pCVar5 + 0x10);
          (**(code **)(WdfFunctions_01015 + 0x668))
                    (WdfDriverGlobals,lVar6,0,0x1d9,
                     "termsrv\\devices\\urbdr\\genericusbdriver\\ioctl.cpp");
          break;
        }
      }
      (**(code **)(WdfFunctions_01015 + 0x9e8))(WdfDriverGlobals,*(undefined8 *)(this + 0x50));
      if (lVar6 == 0) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                  &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids);
        }
        iVar2 = -0x3ffffddb;
      }
      else {
        (**(code **)(WdfFunctions_01015 + 0x810))(WdfDriverGlobals,lVar6);
        (**(code **)(WdfFunctions_01015 + 0x670))
                  (WdfDriverGlobals,lVar6,0,0x1f7,
                   "termsrv\\devices\\urbdr\\genericusbdriver\\ioctl.cpp");
        iVar2 = 0;
      }
      goto LAB_140002b98;
    }
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_140002b98;
    uVar4 = 0x12;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar2);
LAB_140002b98:
  if (local_res20 != 0) {
    ObfDereferenceObject();
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,iVar2);
  return;
}



===== IoCtlInCallerSubmitUrb @ 140002bf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl CGenericUSB::IoCtlInCallerSubmitUrb(struct WDFDEVICE__ * __ptr64,struct
   WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall
CGenericUSB::IoCtlInCallerSubmitUrb(CGenericUSB *this,WDFDEVICE__ *param_1,WDFREQUEST__ *param_2)

{
  ulonglong uVar1;
  bool bVar2;
  ulonglong uVar3;
  bool bVar4;
  int iVar5;
  longlong lVar6;
  ulonglong *puVar7;
  ulonglong *puVar8;
  _MDL *p_Var9;
  undefined8 uVar10;
  ushort uVar11;
  longlong lVar12;
  ulonglong local_res20;
  ulonglong local_68;
  longlong local_60;
  longlong local_58 [3];
  CTsUrbResult *local_40;
  
  local_res20 = 0;
  local_68 = 0;
  local_58[0] = 0;
  local_60 = 0;
  local_40 = (CTsUrbResult *)0x0;
  local_58[1] = 0;
  lVar6 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_2,PTR__WDF_REQUEST_EXTENSION_TYPE_INFO_14000b018);
  p_Var9 = (_MDL *)0x0;
  bVar2 = false;
  *(undefined1 *)(lVar6 + 0x20) = 1;
  local_58[2] = lVar6;
  iVar5 = (**(code **)(WdfFunctions_01015 + 0x888))
                    (WdfDriverGlobals,param_2,8,local_58,&local_res20);
  if (((iVar5 < 0) || (local_58[0] == 0)) || (local_res20 == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar5);
    }
  }
  else {
    lVar12 = local_58[0];
    iVar5 = (**(code **)(WdfFunctions_01015 + 0x8b8))
                      (WdfDriverGlobals,param_2,local_58[0],local_res20,
                       (undefined8 *)(lVar6 + 0x6e8));
    uVar3 = local_res20;
    if (iVar5 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar5);
      }
      goto LAB_14000302f;
    }
    if (0xffff < local_res20) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,lVar12,local_res20);
      }
      iVar5 = -0x3ffffff3;
      goto LAB_14000302f;
    }
    uVar11 = (ushort)local_res20;
    puVar7 = (ulonglong *)ExAllocatePoolWithTag(0x200,local_res20 & 0xffff,0x47555354);
    if (puVar7 == (ulonglong *)0x0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,(uint)uVar3 & 0xffff);
      }
      iVar5 = -0x3fffffe9;
      goto LAB_14000302f;
    }
    puVar8 = (ulonglong *)
             (**(code **)(WdfFunctions_01015 + 0x610))
                       (WdfDriverGlobals,*(undefined8 *)(lVar6 + 0x6e8),local_58 + 1);
    uVar1 = *puVar8;
    *puVar7 = uVar1;
    if (((ushort)uVar1 < 8) || (uVar11 < (ushort)uVar1)) {
LAB_140002e05:
      iVar5 = -0x3ffffff3;
    }
    else {
      memmove(puVar7 + 1,puVar8 + 1,(uVar1 & 0xffff) - 8);
      iVar5 = (**(code **)(WdfFunctions_01015 + 0x890))
                        (WdfDriverGlobals,param_2,0,&local_60,&local_68);
      bVar4 = false;
      if (iVar5 < 0) {
        local_60 = 0;
        local_68 = 0;
LAB_140002edc:
        bVar2 = bVar4;
        (**(code **)(WdfFunctions_01015 + 0x9b0))(WdfDriverGlobals,*(undefined8 *)this);
        iVar5 = CTsUrbResult::CreateInstance
                          ((void *)(local_58[2] + 0x28),(uchar *)puVar7,(uint)(ushort)*puVar7,
                           (uint)uVar3 & 0xffff,*(CSimpleHash **)(this + 0x38),
                           *(CSimpleHash **)(this + 0x28),*(CSimpleHash **)(this + 0x30),p_Var9,
                           &local_40);
        (**(code **)(WdfFunctions_01015 + 0x9b8))(WdfDriverGlobals,*(undefined8 *)this);
        if (-1 < iVar5) {
          p_Var9 = (_MDL *)0x0;
          bVar2 = false;
          iVar5 = (**(code **)(WdfFunctions_01015 + 0x2d8))(WdfDriverGlobals,param_1,param_2);
          if (iVar5 < 0) {
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                       &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar5);
            }
          }
          else {
            iVar5 = 0;
          }
        }
      }
      else {
        if (0xffffffff < local_68) goto LAB_140002e05;
        if (local_60 == 0) goto LAB_140002edc;
        p_Var9 = (_MDL *)IoAllocateMdl(local_60,local_68,0,1,0);
        if (p_Var9 == (_MDL *)0x0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                    &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids);
          }
          iVar5 = -0x3fffff66;
        }
        else {
          uVar10 = FxProbeAndLockForWrite(p_Var9);
          iVar5 = (int)uVar10;
          if (-1 < iVar5) {
            bVar4 = true;
            goto LAB_140002edc;
          }
        }
      }
    }
    ExFreePoolWithTag(puVar7,0);
    if (p_Var9 != (_MDL *)0x0) {
      if (bVar2) {
        MmUnlockPages(p_Var9);
      }
      IoFreeMdl(p_Var9);
    }
  }
  if (-1 < iVar5) {
    return;
  }
LAB_14000302f:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids);
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar5);
  return;
}



===== IoCtlQueryDeviceText @ 140003098 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl CGenericUSB::IoCtlQueryDeviceText(struct WDFREQUEST__ * __ptr64,unsigned
   __int64) __ptr64 */

void __thiscall
CGenericUSB::IoCtlQueryDeviceText(CGenericUSB *this,WDFREQUEST__ *param_1,__uint64 param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 auStack_d8 [32];
  __uint64 *local_b8;
  __uint64 local_a8;
  undefined4 *local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined2 local_70 [4];
  undefined4 local_68;
  undefined4 local_60;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_d8;
  memset(local_70,0,0x48);
  local_b8 = &local_a8;
  local_a8 = 0;
  local_a0 = (undefined4 *)0x0;
  local_78 = 0;
  uVar4 = 8;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_1,8,&local_a0);
  if (-1 < iVar2) {
    if (local_a8 == param_2) {
      local_98 = CONCAT62(local_98._2_6_,0x28);
      (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_1,&local_98);
      lVar3 = (**(code **)(WdfFunctions_01015 + 0x8e8))(WdfDriverGlobals,param_1);
      *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
      local_70[0] = 0xc1b;
      local_68 = *local_a0;
      local_60 = local_a0[1];
      (**(code **)(WdfFunctions_01015 + 0x7e0))(WdfDriverGlobals,param_1,local_70);
      (**(code **)(WdfFunctions_01015 + 0x820))
                (WdfDriverGlobals,param_1,GdEvtIoCompletionQueryDeviceText,this);
      cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                        (WdfDriverGlobals,param_1,*(undefined8 *)(this + 0x20),0);
      if (cVar1 != '\0') {
        return;
      }
      iVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                 &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar2);
      }
      if (-1 < iVar2) {
        return;
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_I(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,uVar4,local_a8);
      }
      iVar2 = -0x3ffffff3;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,iVar2);
  return;
}



===== IoCtlRecordFailure @ 1400032d8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* private: void __cdecl CGenericUSB::IoCtlRecordFailure(struct WDFREQUEST__ * __ptr64) __ptr64 */

void __thiscall CGenericUSB::IoCtlRecordFailure(CGenericUSB *this,WDFREQUEST__ *param_1)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStack_d8 [32];
  ulonglong *local_b8;
  uint *local_a8;
  ulonglong local_a0;
  undefined2 local_98 [4];
  uint *local_90;
  undefined4 local_80;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_d8;
  memset(local_98,0,0x48);
  local_a0 = 0;
  local_a8 = (uint *)0x0;
  local_30 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  lVar3 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_REQUEST_EXTENSION_TYPE_INFO_14000b018);
  local_b8 = &local_a0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x868))(WdfDriverGlobals,param_1,0x14,&local_a8);
  if (iVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
               &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar2);
    }
  }
  else if (*local_a8 == local_a0) {
    local_50 = CONCAT62(local_50._2_6_,0x28);
    (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_1,&local_50);
    local_90 = local_a8;
    local_98[0] = 0xf;
    local_80 = 0x22002b;
    (**(code **)(WdfFunctions_01015 + 0x7e0))(WdfDriverGlobals,param_1,local_98);
    *(undefined8 *)(lVar3 + 0x6e8) = 0;
    (**(code **)(WdfFunctions_01015 + 0x820))(WdfDriverGlobals,param_1,GdEvtIoCompletionGeneric,0);
    cVar1 = (**(code **)(WdfFunctions_01015 + 0x7e8))
                      (WdfDriverGlobals,param_1,*(undefined8 *)(this + 0x20),0);
    if (cVar1 != '\0') {
      return;
    }
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x7f0))(WdfDriverGlobals,param_1);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
               &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar2);
    }
    if (-1 < iVar2) {
      return;
    }
  }
  else {
    iVar2 = -0x3ffffff3;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
               &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,*local_a8);
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,iVar2);
  return;
}



===== IoCtlUsbdiGetVersionAndSpeed @ 14000356c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl CGenericUSB::IoCtlUsbdiGetVersionAndSpeed(struct WDFREQUEST__ * __ptr64)
   __ptr64 */

void __thiscall CGenericUSB::IoCtlUsbdiGetVersionAndSpeed(CGenericUSB *this,WDFREQUEST__ *param_1)

{
  short sVar1;
  undefined1 uVar2;
  int iVar3;
  uint local_res18 [2];
  undefined8 local_res20;
  uint *local_28;
  longlong local_20;
  
  local_20 = 0;
  local_28 = (uint *)0x0;
  local_res20 = 0;
  local_res18[0] = 0;
  iVar3 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_1,0x14,&local_28,&local_20);
  if (iVar3 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
               &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar3);
    }
  }
  else {
    if (local_20 == 0x14) {
      sVar1 = *(short *)(this + 0x5a);
      if ((sVar1 == 2) || (sVar1 == 1)) {
        (**(code **)(this + 0x78))(*(undefined8 *)(this + 0x60),&local_res20,local_res18);
        uVar2 = (**(code **)(this + 0x98))(*(undefined8 *)(this + 0x60));
      }
      else {
        if (sVar1 != 0) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                    &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids);
          }
          iVar3 = -0x3fffffff;
          goto LAB_1400036f1;
        }
        (**(code **)(this + 0x78))(*(undefined8 *)(this + 0x60),&local_res20,local_res18);
        uVar2 = 0;
      }
      *local_28 = (uint)*(ushort *)(this + 0x5a);
      *(undefined8 *)(local_28 + 1) = local_res20;
      local_28[3] = local_res18[0];
      *(undefined1 *)(local_28 + 4) = uVar2;
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,0,0x14);
      return;
    }
    iVar3 = -0x3ffffff3;
  }
LAB_1400036f1:
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,iVar3);
  return;
}



===== IoCtlUsbdiQueryBusTime @ 14000372c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* private: void __cdecl CGenericUSB::IoCtlUsbdiQueryBusTime(struct WDFREQUEST__ * __ptr64) __ptr64
    */

void __thiscall CGenericUSB::IoCtlUsbdiQueryBusTime(CGenericUSB *this,WDFREQUEST__ *param_1)

{
  short sVar1;
  int iVar2;
  undefined4 local_res18 [2];
  longlong local_res20;
  undefined4 *local_28 [2];
  
  local_28[0] = (undefined4 *)0x0;
  local_res20 = 0;
  local_res18[0] = 0;
  iVar2 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_1,4,local_28,&local_res20);
  if (iVar2 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
               &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,iVar2);
    }
  }
  else if (local_res20 == 4) {
    sVar1 = *(short *)(this + 0x5a);
    if (((sVar1 == 2) || (sVar1 == 1)) || (sVar1 == 0)) {
      (**(code **)(this + 0x80))(*(undefined8 *)(this + 0x60),local_res18);
      *local_28[0] = local_res18[0];
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,0,4);
      return;
    }
    iVar2 = -0x3fffffff;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
              &WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids);
    }
  }
  else {
    iVar2 = -0x3ffffff3;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,iVar2);
  return;
}



===== WPP_SF_ @ 140003890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_DD @ 1400038bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_Dd @ 14000390c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,0x2a,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_I @ 140003964 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_I(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_ca57f73ceebe3acc2e782e1f2e089c12_Traceguids,param_2,&local_res20,8,0)
  ;
  return;
}



===== GdEvtIoCompletionGeneric @ 1400039b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GdEvtIoCompletionGeneric(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_REQUEST_EXTENSION_TYPE_INFO_14000b018);
  if (*(int *)(param_3 + 8) < 0) {
    (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1);
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x848))
              (WdfDriverGlobals,param_1,*(int *)(param_3 + 8),*(undefined8 *)(lVar1 + 0x6e8));
  }
  return;
}



===== GdEvtIoCompletionGetControllerName @ 140003a50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GdEvtIoCompletionGetControllerName(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  undefined8 local_res20;
  undefined8 local_18 [2];
  
  local_res20 = 0;
  local_18[0] = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x870))
                    (WdfDriverGlobals,param_1,4,local_18,&local_res20);
  if (-1 < iVar1) {
    iVar1 = *(int *)(param_3 + 8);
    if (iVar1 == -0x3fffffdd) {
      iVar1 = -0x7ffffffb;
    }
    else if (-1 < iVar1) {
      (**(code **)(WdfFunctions_01015 + 0x848))(WdfDriverGlobals,param_1,iVar1,local_res20);
      return;
    }
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_1,iVar1);
  return;
}



===== GdEvtIoCompletionQueryDeviceText @ 140003b20 =====

void GdEvtIoCompletionQueryDeviceText
               (CGenericUSB *param_1,undefined8 param_2,_WDF_REQUEST_COMPLETION_PARAMS *param_3)

{
  CGenericUSB::IoCtlCompletionQueryDeviceText(param_1,(WDFREQUEST__ *)param_1,param_3);
  return;
}



===== GdEvtIoCompletionSubmitUrb @ 140003b40 =====

void GdEvtIoCompletionSubmitUrb
               (WDFREQUEST__ *param_1,undefined8 param_2,_WDF_REQUEST_COMPLETION_PARAMS *param_3,
               CGenericUSB *param_4)

{
  CGenericUSB::IoCtlCompletionSubmitUrb(param_4,param_1,param_3);
  return;
}



===== GdEvtIoDeviceControl @ 140003b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GdEvtIoDeviceControl
               (undefined8 param_1,WDFREQUEST__ *param_2,undefined8 param_3,__uint64 param_4,
               uint param_5)

{
  undefined8 uVar1;
  CGenericUSB *this;
  ulong uVar2;
  __uint64 _Var3;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  this = (CGenericUSB *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,uVar1,PTR__WDF_CGenericUSB_TYPE_INFO_14000b040);
  if (param_5 < 0x22442d) {
    if (param_5 == 0x22442c) {
      CGenericUSB::IoCtlGetControllerName(this,param_2);
      return;
    }
    if (param_5 == 0x224000) {
      CGenericUSB::IoCtlUsbdiQueryBusTime(this,param_2);
      return;
    }
    if (param_5 != 0x224404) {
      if (param_5 == 0x22440c) {
        CGenericUSB::IoCtlQueryDeviceText(this,param_2,param_4);
        return;
      }
      if (param_5 == 0x224410) {
        _Var3 = 4;
        uVar2 = 0x220013;
      }
      else {
        if (param_5 == 0x224414) {
          CGenericUSB::IoCtlUsbdiGetVersionAndSpeed(this,param_2);
          return;
        }
        if (param_5 == 0x22441c) {
          _Var3 = 4;
          uVar2 = 0x22001b;
        }
        else if (param_5 == 0x224420) {
          _Var3 = 0;
          uVar2 = 0x22001f;
        }
        else {
          if (param_5 == 0x224424) {
            CGenericUSB::IoCtlGetHubName(this,param_2);
            return;
          }
          if (param_5 != 0x224428) {
LAB_140003cde:
            (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,0xc0000010);
            return;
          }
          _Var3 = 0x10;
          uVar2 = 0x220420;
        }
      }
      goto LAB_140003d4a;
    }
LAB_140003d31:
    CGenericUSB::IoCtlGenericForwardAndForget(this,param_2);
  }
  else {
    if (param_5 == 0x224430) {
      uVar2 = 0x220433;
LAB_140003d44:
      _Var3 = 8;
    }
    else {
      if (param_5 == 0x224434) goto LAB_140003d31;
      if (param_5 == 0x224800) {
        _Var3 = 0x20;
        uVar2 = 0x22043f;
      }
      else {
        if (param_5 == 0x224804) {
          CGenericUSB::IoCtlRecordFailure(this,param_2);
          return;
        }
        if (param_5 == 0x224808) {
          uVar2 = 0x220437;
          goto LAB_140003d44;
        }
        if (param_5 != 0x228418) {
          if ((param_5 != 0x22c400) && (param_5 == 0x22c40b)) {
            CGenericUSB::IoCtlControlSubmitUrb(this,param_2);
            return;
          }
          goto LAB_140003cde;
        }
        _Var3 = 0;
        uVar2 = 0x220007;
      }
    }
LAB_140003d4a:
    CGenericUSB::IoCtlGenericForwardUSB(this,param_2,uVar2,_Var3);
  }
  return;
}



===== GdEvtIoDeviceControlInCaller @ 140003d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void GdEvtIoDeviceControlInCaller(WDFDEVICE__ *param_1,WDFREQUEST__ *param_2)

{
  byte bVar1;
  int iVar2;
  CGenericUSB *this;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  this = (CGenericUSB *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CGenericUSB_TYPE_INFO_14000b040);
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 2) {
    local_38 = CONCAT62(local_38._2_6_,0x28);
    (**(code **)(WdfFunctions_01015 + 0x850))(WdfDriverGlobals,param_2,&local_38);
    if (local_38._4_4_ == 0xe) {
      if ((int)uStack_20 == 0x22c400) {
        CGenericUSB::IoCtlInCallerCancelRequest(this,param_2);
        return;
      }
      if ((int)uStack_20 == 0x22c40b) {
        CGenericUSB::IoCtlInCallerSubmitUrb(this,param_1,param_2);
        return;
      }
    }
    iVar2 = (**(code **)(WdfFunctions_01015 + 0x2d8))(WdfDriverGlobals,param_1,param_2);
    if (-1 < iVar2) {
      return;
    }
  }
  else {
    iVar2 = -0x3ffffff0;
  }
  (**(code **)(WdfFunctions_01015 + 0x838))(WdfDriverGlobals,param_2,iVar2);
  return;
}



===== GdEvtIoStop @ 140003ec0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GdEvtIoStop(undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  undefined8 uVar1;
  
  uVar1 = (**(code **)(WdfFunctions_01015 + 0x4e8))(WdfDriverGlobals,param_1);
  (**(code **)(WdfFunctions_01015 + 0x650))
            (WdfDriverGlobals,uVar1,PTR__WDF_CGenericUSB_TYPE_INFO_14000b040);
  if ((param_3 & 1) == 0) {
    if ((param_3 & 2) != 0) {
      (**(code **)(WdfFunctions_01015 + 0x810))(WdfDriverGlobals,param_2);
    }
  }
  else {
    (**(code **)(WdfFunctions_01015 + 0x8e0))(WdfDriverGlobals,param_2,0);
  }
  return;
}



===== GdEvtRequestContextCleanup @ 140003f80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GdEvtRequestContextCleanup(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(WdfFunctions_01015 + 0x650))
                    (WdfDriverGlobals,param_1,PTR__WDF_REQUEST_EXTENSION_TYPE_INFO_14000b018);
  if ((*(char *)(lVar1 + 0x20) != '\0') && ((CTsUrbResult *)(lVar1 + 0x28) != (CTsUrbResult *)0x0))
  {
    CTsUrbResult::~CTsUrbResult((CTsUrbResult *)(lVar1 + 0x28));
  }
  return;
}



===== WppClassicProviderCallback @ 140003fd0 =====

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



===== wil_details_RecordCachedUsage @ 140004004 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140004150 =====

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



===== RtlStringLengthWorkerW @ 1400041d4 =====

uint RtlStringLengthWorkerW(short *param_1,undefined8 param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = 0x7fff;
  do {
    if (*param_1 == 0) break;
    param_1 = param_1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  uVar1 = ~-(uint)(lVar2 != 0) & 0xc000000d;
  if (param_3 != (longlong *)0x0) {
    if (lVar2 != 0) {
      *param_3 = 0x7fff - lVar2;
      return uVar1;
    }
    *param_3 = 0;
  }
  return uVar1;
}



===== FxStubDriverUnloadCommon @ 14000421c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl FxStubDriverUnloadCommon(void) */

void __cdecl FxStubDriverUnloadCommon(void)

{
  void **ppvVar1;
  void **ppvVar2;
  
  ppvVar1 = &__KMDF_CLASS_BIND_END;
  if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000b158 != &__KMDF_CLASS_BIND_START) {
    ppvVar2 = (void **)(PTR___KMDF_CLASS_BIND_START_14000b158 + 0x50);
    while( true ) {
      for (; (ppvVar1 + 1 <= ppvVar2 && (*ppvVar1 == (void *)0x0)); ppvVar1 = ppvVar1 + 1) {
      }
      if (ppvVar1 < ppvVar2) break;
      ppvVar1 = ppvVar2;
LAB_140004275:
      if (ppvVar1 == (void **)0x0) goto LAB_1400042cb;
      if (ppvVar2 <= ppvVar1) goto LAB_1400042e3;
      if (ppvVar1[8] == (code *)0x0) {
        WdfVersionUnbindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      else {
        (*ppvVar1[8])(WdfVersionUnbindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar1);
      }
      ppvVar1 = (void **)((longlong)ppvVar1 + (ulonglong)*(uint *)ppvVar1);
    }
    if ((ppvVar1 + 10 <= ppvVar2) && (*(uint *)ppvVar1 == 0x50)) goto LAB_140004275;
LAB_1400042cb:
    DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
  }
LAB_1400042e3:
  WdfVersionUnbind(&DAT_14000b230,&WdfBindInfo,WdfDriverGlobals);
  return;
}



===== entry @ 140004320 =====

void entry(_WDF_BIND_INFO *param_1,undefined8 param_2)

{
  __security_init_cookie();
  FxDriverEntryWorker(param_1,param_2);
  return;
}



===== FxDriverEntryWorker @ 140004354 =====

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
    _DAT_14000b230 = 0x2080000;
    _DAT_14000b238 = &DAT_14000b250;
    RtlCopyUnicodeString(&DAT_14000b230);
    p_Var3 = param_1;
    iVar1 = WdfVersionBind(param_1,&DAT_14000b230,&WdfBindInfo,&WdfDriverGlobals);
    if (-1 < iVar1) {
      iVar1 = FxStubBindClasses(p_Var3);
      if ((-1 < iVar1) && (iVar1 = FxStubInitTypes(), -1 < iVar1)) {
        iVar1 = DriverEntry(param_1,param_2);
        if (-1 < iVar1) {
          if (*(char *)(WdfDriverGlobals + 0x30) != '\0') {
            if (*(longlong *)(param_1 + 0x68) != 0) {
              DAT_14000b458 = *(longlong *)(param_1 + 0x68);
            }
            *(code **)(param_1 + 0x68) = FxStubDriverUnload;
          }
          return 0;
        }
        DbgPrintEx(0x4d,0,"DriverEntry failed 0x%x for driver %wZ\n",iVar1,&DAT_14000b230);
        if ((_MARKER_TYPE *)PTR___KMDF_CLASS_BIND_START_14000b158 != &__KMDF_CLASS_BIND_START) {
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



===== FxStubDriverUnload @ 1400044e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FxStubDriverUnload(void)

{
  if ((DAT_14000b458 != (code *)0x0) && (DAT_14000b458 != FxStubDriverUnload)) {
    (*DAT_14000b458)();
  }
  FxStubDriverUnloadCommon();
  return;
}



===== FxStubBindClasses @ 140004514 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x000140004539) */
/* long __cdecl FxStubBindClasses(struct _WDF_BIND_INFO * __ptr64) */

long __cdecl FxStubBindClasses(_WDF_BIND_INFO *param_1)

{
  int iVar1;
  void **ppvVar2;
  
  iVar1 = 0;
  ppvVar2 = &__KMDF_CLASS_BIND_END;
  while( true ) {
    for (; (ppvVar2 + 1 < (void **)((longlong)&__KMDF_CLASS_BIND_END + 1) &&
           (*ppvVar2 == (void *)0x0)); ppvVar2 = ppvVar2 + 1) {
    }
    if ((void **)0x14000b14f < ppvVar2) break;
    if (((&__KMDF_CLASS_BIND_END < ppvVar2 + 10) || (*(uint *)ppvVar2 != 0x50)) ||
       (ppvVar2 == (void **)0x0)) {
      DbgPrintEx(0x4d,0,"FxGetNextClassBindInfo failed\n");
      return -0x3fffff85;
    }
    PTR___KMDF_CLASS_BIND_START_14000b158 = (undefined *)ppvVar2;
    if (ppvVar2[7] == (code *)0x0) {
      iVar1 = WdfVersionBindClass(&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: VersionBindClass WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    else {
      iVar1 = (*ppvVar2[7])(WdfVersionBindClass_exref,&WdfBindInfo,WdfDriverGlobals,ppvVar2);
      if (iVar1 < 0) {
        DbgPrintEx(0x4d,0,
                   "FxStubBindClasses: ClientBindClass %p, WDF_CLASS_BIND_INFO 0x%p, class %S, returned status 0x%x\n"
                   ,ppvVar2[7],ppvVar2,ppvVar2[1],iVar1);
        return iVar1;
      }
    }
    ppvVar2 = (void **)((ulonglong)*(uint *)ppvVar2 + (longlong)ppvVar2);
  }
  return iVar1;
}



===== FxStubInitTypes @ 14000469c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001400046b9) */
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
    if ((void **)0x14000b16f < ppvVar2) break;
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



===== AddItemDuplicateOk @ 140004764 =====

/* public: long __cdecl CSimpleHash::AddItemDuplicateOk(void * __ptr64,unsigned long * __ptr64)
   __ptr64 */

long __thiscall CSimpleHash::AddItemDuplicateOk(CSimpleHash *this,void *param_1,ulong *param_2)

{
  long lVar1;
  uint uVar2;
  ulonglong uVar3;
  ulong local_res8 [2];
  
  uVar3 = 0;
  if (*(uint *)this != 0) {
    do {
      if (*(void **)(*(longlong *)(this + 8) + uVar3 * 8) == param_1) {
        if (param_2 == (ulong *)0x0) {
          return 0;
        }
        *param_2 = (ulong)uVar3;
        return 0;
      }
      uVar2 = (ulong)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(uint *)this);
  }
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



===== CreateInstance @ 140004804 =====

/* public: static long __cdecl CSimpleHash::CreateInstance(unsigned long,class CSimpleHash * __ptr64
   * __ptr64) */

long __cdecl CSimpleHash::CreateInstance(ulong param_1,CSimpleHash **param_2)

{
  CSimpleHash *pCVar1;
  longlong lVar2;
  long lVar3;
  uint uVar4;
  ulonglong uVar5;
  
  pCVar1 = (CSimpleHash *)ExAllocatePoolWithTag(0x200,0x20,0x72447244);
  if (pCVar1 == (CSimpleHash *)0x0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_cf9536f321c83b2982054c1fb1ce0b49_Traceguids);
    }
    lVar3 = -0x3fffffe9;
  }
  else {
    *(undefined8 *)(pCVar1 + 8) = 0;
    *(undefined8 *)(pCVar1 + 0x10) = 0;
    pCVar1[0x18] = (CSimpleHash)0x0;
    *(undefined8 *)(pCVar1 + 0x10) = 0;
    *(uint *)pCVar1 = 10;
    lVar2 = ExAllocatePoolWithTag(0x200,0x50);
    *(longlong *)(pCVar1 + 8) = lVar2;
    if (lVar2 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                &WPP_cf9536f321c83b2982054c1fb1ce0b49_Traceguids);
      }
      lVar3 = -0x3fffffe9;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_cf9536f321c83b2982054c1fb1ce0b49_Traceguids);
      }
      if (*(longlong *)(pCVar1 + 8) != 0) {
        ExFreePoolWithTag(*(longlong *)(pCVar1 + 8),0);
      }
      ExFreePoolWithTag(pCVar1,0);
    }
    else {
      uVar5 = 0;
      if (*(uint *)pCVar1 != 0) {
        do {
          *(undefined8 *)(*(longlong *)(pCVar1 + 8) + uVar5 * 8) = *(undefined8 *)(pCVar1 + 0x10);
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < *(uint *)pCVar1);
      }
      *param_2 = pCVar1;
      lVar3 = 0;
    }
  }
  return lVar3;
}



===== FindEmptySlot @ 140004974 =====

/* private: long __cdecl CSimpleHash::FindEmptySlot(unsigned long * __ptr64) __ptr64 */

long __thiscall CSimpleHash::FindEmptySlot(CSimpleHash *this,ulong *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  long lVar8;
  uint uVar9;
  
  uVar6 = 0;
  uVar5 = *(uint *)this;
  if (uVar5 != 0) {
    do {
      if (*(longlong *)(*(longlong *)(this + 8) + uVar6 * 8) == *(longlong *)(this + 0x10)) {
        *param_1 = (ulong)uVar6;
        goto LAB_140004af5;
      }
      uVar4 = (ulong)uVar6 + 1;
      uVar6 = (ulonglong)uVar4;
    } while (uVar4 < uVar5);
  }
  uVar4 = (uVar5 >> 2) + uVar5;
  uVar9 = uVar4 + 1;
  if (uVar5 >> 2 != 0) {
    uVar9 = uVar4;
  }
  if (uVar9 == 0xffffffff) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_cf9536f321c83b2982054c1fb1ce0b49_Traceguids);
    }
    lVar8 = -0x3fffffe9;
    *param_1 = 0xffffffff;
  }
  else {
    uVar2 = SUB168(ZEXT816(8) * ZEXT416(uVar9),0);
    if (SUB168(ZEXT816(8) * ZEXT416(uVar9),8) != 0) {
      uVar2 = 0xffffffffffffffff;
    }
    lVar3 = ExAllocatePoolWithTag(0x200,uVar2);
    if (*(longlong *)(this + 8) == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_cf9536f321c83b2982054c1fb1ce0b49_Traceguids);
      }
      *param_1 = 0xffffffff;
      lVar8 = -0x3fffffe9;
      if (lVar3 != 0) {
        ExFreePoolWithTag(lVar3,0);
      }
    }
    else {
      uVar6 = (ulonglong)*(uint *)this;
      if (*(uint *)this < uVar9) {
        puVar7 = (undefined8 *)(lVar3 + uVar6 * 8);
        do {
          uVar5 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar5;
          *puVar7 = *(undefined8 *)(this + 0x10);
          puVar7 = puVar7 + 1;
        } while (uVar5 < uVar9);
      }
      uVar6 = 0;
      uVar5 = 0;
      if (*(int *)this != 0) {
        do {
          *(undefined8 *)(lVar3 + uVar6 * 8) = *(undefined8 *)(*(longlong *)(this + 8) + uVar6 * 8);
          uVar4 = (int)uVar6 + 1;
          uVar6 = (ulonglong)uVar4;
          uVar5 = *(uint *)this;
        } while (uVar4 < uVar5);
      }
      lVar1 = *(longlong *)(this + 8);
      if (lVar1 != 0) {
        ExFreePoolWithTag(lVar1,0);
      }
      *(longlong *)(this + 8) = lVar3;
      *(uint *)this = uVar9;
      *param_1 = uVar5;
LAB_140004af5:
      lVar8 = 0;
    }
  }
  return lVar8;
}



===== ~CTsUrbResult @ 140004b1c =====

/* public: __cdecl CTsUrbResult::~CTsUrbResult(void) __ptr64 */

void __thiscall CTsUrbResult::~CTsUrbResult(CTsUrbResult *this)

{
  *(undefined ***)this = &_vftable_;
  if ((*(CTsUrbResult **)(this + 0x6a0) != (CTsUrbResult *)0x0) &&
     (*(CTsUrbResult **)(this + 0x6a0) != this + 8)) {
    ExFreePool();
    *(undefined8 *)(this + 0x6a0) = 0;
  }
  if (*(longlong *)(this + 0x6b0) != 0) {
    MmUnlockPages();
    IoFreeMdl(*(undefined8 *)(this + 0x6b0));
    *(undefined8 *)(this + 0x6b0) = 0;
  }
  return;
}



===== AllocateUrb @ 140004b98 =====

/* protected: struct _URB * __ptr64 __cdecl CTsUrbResult::AllocateUrb(unsigned long) __ptr64 */

_URB * __thiscall CTsUrbResult::AllocateUrb(CTsUrbResult *this,ulong param_1)

{
  _URB *p_Var1;
  
  p_Var1 = (_URB *)0x0;
  if (param_1 < 0x10000) {
    if (param_1 < 0x699) {
      p_Var1 = (_URB *)(this + 8);
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_90671cf8bc7431750ea4075ddc471495_Traceguids,param_1);
      }
      p_Var1 = (_URB *)ExAllocatePoolWithTag(0x200,param_1,0x46555354);
      if (p_Var1 == (_URB *)0x0) {
        return (_URB *)0x0;
      }
    }
    *(_URB **)(this + 0x6a0) = p_Var1;
  }
  return p_Var1;
}



===== CreateInstance @ 140004c28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* public: static long __cdecl CTsUrbResult::CreateInstance(void * __ptr64,unsigned char *
   __ptr64,unsigned long,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class
   CSimpleHash * __ptr64,struct _MDL * __ptr64,class CTsUrbResult * __ptr64 * __ptr64) */

long __cdecl
CTsUrbResult::CreateInstance
          (void *param_1,uchar *param_2,ulong param_3,ulong param_4,CSimpleHash *param_5,
          CSimpleHash *param_6,CSimpleHash *param_7,_MDL *param_8,CTsUrbResult **param_9)

{
  ushort uVar1;
  undefined **ppuVar2;
  uint uVar3;
  int iVar4;
  
  if (param_3 < 8) {
    return -0x3ffffff3;
  }
  uVar1 = *(ushort *)(param_2 + 2);
  uVar3 = (uint)uVar1;
  if (uVar1 < 0x1b) {
    if (uVar1 == 0x1a) {
LAB_140004e6c:
      if (param_1 == (void *)0x0) {
        return -0x3fffff45;
      }
      memset(param_1,0,0x6c0);
      ppuVar2 = &CTsUrbResultClassRequest::_vftable_;
    }
    else {
      if (uVar3 < 0xe) {
        if (uVar3 != 0xd) {
          if (uVar3 < 7) {
            if (uVar3 == 6) {
              return -0x3fffff45;
            }
            if (uVar3 == 0) {
              if (param_1 == (void *)0x0) {
                return -0x3fffff45;
              }
              memset(param_1,0,0x6c0);
              ppuVar2 = &CTsUrbResultSelectConfig::_vftable_;
              goto LAB_140005013;
            }
            if (uVar3 == 1) {
              if (param_1 == (void *)0x0) {
                return -0x3fffff45;
              }
              memset(param_1,0,0x6c0);
              ppuVar2 = &CTsUrbResultSelectInterface::_vftable_;
              goto LAB_140005013;
            }
            if (uVar3 != 2) {
              return -0x3fffff45;
            }
            goto joined_r0x000140004ff6;
          }
          if (uVar3 == 7) {
            if (param_1 == (void *)0x0) {
              return -0x3fffff45;
            }
            memset(param_1,0,0x6c0);
            ppuVar2 = &CTsUrbResultCurrentFrame::_vftable_;
            goto LAB_140005013;
          }
          if (uVar3 == 8) {
            if (param_1 == (void *)0x0) {
              return -0x3fffff45;
            }
            memset(param_1,0,0x6c0);
            ppuVar2 = &CTsUrbResultControlTransfer::_vftable_;
            goto LAB_140005013;
          }
          if (uVar3 == 9) {
            if (param_1 == (void *)0x0) {
              return -0x3fffff45;
            }
            memset(param_1,0,0x6c0);
            ppuVar2 = &CTsUrbResultBulkTransfer::_vftable_;
            goto LAB_140005013;
          }
          if (uVar3 == 10) {
            if (param_1 == (void *)0x0) {
              return -0x3fffff45;
            }
            memset(param_1,0,0x6c0);
            ppuVar2 = &CTsUrbResultIsochTransfer::_vftable_;
            goto LAB_140005013;
          }
          if ((uVar3 != 0xb) && (uVar3 != 0xc)) {
            return -0x3fffff45;
          }
          goto LAB_140004d1c;
        }
LAB_140004e2e:
        if (param_1 == (void *)0x0) {
          return -0x3fffff45;
        }
        memset(param_1,0,0x6c0);
        ppuVar2 = &CTsUrbResultControlFeature::_vftable_;
        goto LAB_140005013;
      }
      if (uVar3 < 0x15) {
        if (uVar3 != 0x14) {
          if ((((uVar3 == 0xe) || (uVar3 == 0xf)) || (uVar3 == 0x10)) ||
             ((uVar3 == 0x11 || (uVar3 == 0x12)))) goto LAB_140004e2e;
          if (uVar3 != 0x13) {
            return -0x3fffff45;
          }
        }
      }
      else if (uVar3 != 0x15) {
        if (uVar3 == 0x16) {
          return -0x3fffff45;
        }
        iVar4 = uVar3 - 0x17;
        if (iVar4 != 0) {
LAB_140004e62:
          if ((iVar4 != 1) && (iVar4 != 2)) {
            return -0x3fffff45;
          }
        }
        goto LAB_140004e6c;
      }
LAB_140004e91:
      if (param_1 == (void *)0x0) {
        return -0x3fffff45;
      }
      memset(param_1,0,0x6c0);
      ppuVar2 = &CTsUrbResultGetStatus::_vftable_;
    }
    goto LAB_140005013;
  }
  if (uVar1 < 0x29) {
    if (uVar1 != 0x28) {
      if (uVar3 < 0x22) {
        if (uVar3 == 0x21) goto LAB_140004e91;
        if ((uVar3 == 0x1b) || (uVar3 == 0x1c)) goto LAB_140004e6c;
        if (uVar3 == 0x1d) {
          return -0x3fffff45;
        }
        iVar4 = uVar3 - 0x1e;
        if (iVar4 != 0) goto LAB_140004e62;
        goto joined_r0x000140004ff6;
      }
      if ((uVar3 == 0x22) || (uVar3 == 0x23)) goto LAB_140004e2e;
      if ((uVar3 != 0x24) && (uVar3 != 0x25)) {
        if (uVar3 == 0x26) {
          if (param_1 == (void *)0x0) {
            return -0x3fffff45;
          }
          memset(param_1,0,0x6c0);
          ppuVar2 = &CTsUrbResultGetConfigRequest::_vftable_;
        }
        else {
          if (uVar3 != 0x27) {
            return -0x3fffff45;
          }
          if (param_1 == (void *)0x0) {
            return -0x3fffff45;
          }
          memset(param_1,0,0x6c0);
          ppuVar2 = &CTsUrbResultGetStatus::_vftable_;
        }
        goto LAB_140005013;
      }
    }
  }
  else {
    if (0x2f < uVar3) {
      if ((uVar3 != 0x30) && (uVar3 != 0x31)) {
        if (uVar3 != 0x32) {
          return -0x3fffff45;
        }
        if (param_1 == (void *)0x0) {
          return -0x3fffff45;
        }
        memset(param_1,0,0x6c0);
        ppuVar2 = &CTsUrbResultControlTransferEx::_vftable_;
        goto LAB_140005013;
      }
joined_r0x000140004ff6:
      if (param_1 == (void *)0x0) {
        return -0x3fffff45;
      }
      memset(param_1,0,0x6c0);
      ppuVar2 = &CTsUrbResultPipeRequest::_vftable_;
      goto LAB_140005013;
    }
    if (uVar3 == 0x2f) {
      return -0x3fffff45;
    }
    if (uVar3 != 0x29) {
      if (uVar3 != 0x2a) {
        return -0x3fffff45;
      }
      if (param_1 == (void *)0x0) {
        return -0x3fffff45;
      }
      memset(param_1,0,0x6c0);
      ppuVar2 = &CTsUrbResultOsFeatureDescriptor::_vftable_;
      goto LAB_140005013;
    }
  }
LAB_140004d1c:
  if (param_1 == (void *)0x0) {
    return -0x3fffff45;
  }
  memset(param_1,0,0x6c0);
  ppuVar2 = &CTsUrbResultControlDescriptor::_vftable_;
LAB_140005013:
  *(undefined ***)param_1 = ppuVar2;
  iVar4 = (*(code *)**(undefined8 **)param_1)
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if (iVar4 < 0) {
    ~CTsUrbResult(param_1);
    return iVar4;
  }
  *param_9 = param_1;
  return 0;
}



===== Initialize @ 140005090 =====

/* public: virtual long __cdecl CTsUrbResult::Initialize(unsigned char * __ptr64,unsigned
   long,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class CSimpleHash *
   __ptr64,struct _MDL * __ptr64) __ptr64 */

long __thiscall
CTsUrbResult::Initialize
          (CTsUrbResult *this,uchar *param_1,ulong param_2,ulong param_3,CSimpleHash *param_4,
          CSimpleHash *param_5,CSimpleHash *param_6,_MDL *param_7)

{
  return -0x3ffffff3;
}



===== Initialize @ 1400050a0 =====

/* private: virtual long __cdecl CTsUrbResultBulkTransfer::Initialize(unsigned char *
   __ptr64,unsigned long,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class
   CSimpleHash * __ptr64,struct _MDL * __ptr64) __ptr64 */

long __thiscall
CTsUrbResultBulkTransfer::Initialize
          (CTsUrbResultBulkTransfer *this,uchar *param_1,ulong param_2,ulong param_3,
          CSimpleHash *param_4,CSimpleHash *param_5,CSimpleHash *param_6,_MDL *param_7)

{
  longlong lVar1;
  undefined4 uVar2;
  _URB *p_Var3;
  
  if (((param_2 == 0x10) && (*(short *)param_1 == 0x10)) && (7 < param_3)) {
    p_Var3 = CTsUrbResult::AllocateUrb((CTsUrbResult *)this,0x80);
    if (p_Var3 == (_URB *)0x0) {
      return -0x3fffffe9;
    }
    memset(p_Var3 + 2,0,0x7e);
    *(undefined2 *)p_Var3 = 0x80;
    *(undefined2 *)(p_Var3 + 2) = *(undefined2 *)(param_1 + 2);
    *(undefined4 *)(p_Var3 + 0x20) = *(undefined4 *)(param_1 + 0xc);
    *(_MDL **)(p_Var3 + 0x30) = param_7;
    if (param_7 == (_MDL *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_7 + 0x28);
    }
    *(undefined4 *)(p_Var3 + 0x24) = uVar2;
    if (((*(uint *)(param_1 + 8) & 0xffff) < *(uint *)param_6) &&
       (lVar1 = *(longlong *)
                 (*(longlong *)(param_6 + 8) + (ulonglong)(*(uint *)(param_1 + 8) & 0xffff) * 8),
       lVar1 != *(longlong *)(param_6 + 0x10))) {
      *(longlong *)(p_Var3 + 0x18) = lVar1;
      *(_MDL **)(this + 0x6b0) = param_7;
      *(undefined2 *)(this + 0x6aa) = 8;
      return 0;
    }
  }
  return -0x3ffffff3;
}



===== Initialize @ 140005190 =====

/* private: virtual long __cdecl CTsUrbResultClassRequest::Initialize(unsigned char *
   __ptr64,unsigned long,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class
   CSimpleHash * __ptr64,struct _MDL * __ptr64) __ptr64 */

long __thiscall
CTsUrbResultClassRequest::Initialize
          (CTsUrbResultClassRequest *this,uchar *param_1,ulong param_2,ulong param_3,
          CSimpleHash *param_4,CSimpleHash *param_5,CSimpleHash *param_6,_MDL *param_7)

{
  undefined4 uVar1;
  _URB *p_Var2;
  long lVar3;
  
  if (((param_2 == 0x14) && (*(short *)param_1 == 0x14)) && (7 < param_3)) {
    p_Var2 = CTsUrbResult::AllocateUrb((CTsUrbResult *)this,0x88);
    lVar3 = 0;
    if (p_Var2 == (_URB *)0x0) {
      lVar3 = -0x3fffffe9;
    }
    else {
      memset(p_Var2 + 2,0,0x86);
      *(undefined2 *)p_Var2 = 0x88;
      *(undefined2 *)(p_Var2 + 2) = *(undefined2 *)(param_1 + 2);
      *(undefined4 *)(p_Var2 + 0x20) = *(undefined4 *)(param_1 + 8);
      p_Var2[0x80] = *(_URB *)(param_1 + 0xc);
      p_Var2[0x81] = *(_URB *)(param_1 + 0xd);
      *(undefined2 *)(p_Var2 + 0x82) = *(undefined2 *)(param_1 + 0xe);
      *(undefined2 *)(p_Var2 + 0x84) = *(undefined2 *)(param_1 + 0x10);
      *(_MDL **)(p_Var2 + 0x30) = param_7;
      if (param_7 == (_MDL *)0x0) {
        uVar1 = 0;
      }
      else {
        uVar1 = *(undefined4 *)(param_7 + 0x28);
      }
      *(undefined4 *)(p_Var2 + 0x24) = uVar1;
      *(_MDL **)(this + 0x6b0) = param_7;
      *(undefined2 *)(this + 0x6aa) = 8;
    }
  }
  else {
    lVar3 = -0x3ffffff3;
  }
  return lVar3;
}



===== Initialize @ 140005290 =====

/* private: virtual long __cdecl CTsUrbResultControlDescriptor::Initialize(unsigned char *
   __ptr64,unsigned long,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class
   CSimpleHash * __ptr64,struct _MDL * __ptr64) __ptr64 */

long __thiscall
CTsUrbResultControlDescriptor::Initialize
          (CTsUrbResultControlDescriptor *this,uchar *param_1,ulong param_2,ulong param_3,
          CSimpleHash *param_4,CSimpleHash *param_5,CSimpleHash *param_6,_MDL *param_7)

{
  _URB *p_Var1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = 0;
  if ((((param_7 == (_MDL *)0x0) || (param_2 != 0xc)) || (*(short *)param_1 != 0xc)) ||
     (param_3 < 8)) {
    lVar3 = -0x3ffffff3;
  }
  else {
    p_Var1 = CTsUrbResult::AllocateUrb((CTsUrbResult *)this,0x88);
    if (p_Var1 == (_URB *)0x0) {
      lVar3 = -0x3fffffe9;
    }
    else {
      if (((byte)param_7[10] & 5) == 0) {
        uVar2 = MmMapLockedPagesSpecifyCache(param_7,0,1,0,0,0x40000010);
      }
      else {
        uVar2 = *(undefined8 *)(param_7 + 0x18);
      }
      memset(p_Var1 + 2,0,0x86);
      *(undefined2 *)p_Var1 = 0x88;
      *(undefined2 *)(p_Var1 + 2) = *(undefined2 *)(param_1 + 2);
      p_Var1[0x82] = *(_URB *)(param_1 + 8);
      p_Var1[0x83] = *(_URB *)(param_1 + 9);
      *(undefined2 *)(p_Var1 + 0x84) = *(undefined2 *)(param_1 + 10);
      *(undefined4 *)(p_Var1 + 0x24) = *(undefined4 *)(param_7 + 0x28);
      *(undefined8 *)(p_Var1 + 0x28) = uVar2;
      *(_MDL **)(this + 0x6b0) = param_7;
      *(undefined2 *)(this + 0x6aa) = 8;
    }
  }
  return lVar3;
}



===== Initialize @ 1400053b0 =====

/* private: virtual long __cdecl CTsUrbResultControlFeature::Initialize(unsigned char *
   __ptr64,unsigned long,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class
   CSimpleHash * __ptr64,struct _MDL * __ptr64) __ptr64 */

long __thiscall
CTsUrbResultControlFeature::Initialize
          (CTsUrbResultControlFeature *this,uchar *param_1,ulong param_2,ulong param_3,
          CSimpleHash *param_4,CSimpleHash *param_5,CSimpleHash *param_6,_MDL *param_7)

{
  _URB *p_Var1;
  long lVar2;
  
  lVar2 = 0;
  if ((((param_7 == (_MDL *)0x0) && (param_2 == 0xc)) && (*(short *)param_1 == 0xc)) &&
     (7 < param_3)) {
    p_Var1 = CTsUrbResult::AllocateUrb((CTsUrbResult *)this,0x88);
    if (p_Var1 == (_URB *)0x0) {
      lVar2 = -0x3fffffe9;
    }
    else {
      memset(p_Var1 + 2,0,0x86);
      *(undefined2 *)p_Var1 = 0x88;
      *(undefined2 *)(p_Var1 + 2) = *(undefined2 *)(param_1 + 2);
      *(undefined2 *)(p_Var1 + 0x82) = *(undefined2 *)(param_1 + 8);
      *(undefined2 *)(p_Var1 + 0x84) = *(undefined2 *)(param_1 + 10);
      *(undefined2 *)(this + 0x6aa) = 8;
    }
  }
  else {
    lVar2 = -0x3ffffff3;
  }
  return lVar2;
}



===== Initialize @ 140005470 =====

/* private: virtual long __cdecl CTsUrbResultControlTransfer::Initialize(unsigned char *
   __ptr64,unsigned long,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class
   CSimpleHash * __ptr64,struct _MDL * __ptr64) __ptr64 */

long __thiscall
CTsUrbResultControlTransfer::Initialize
          (CTsUrbResultControlTransfer *this,uchar *param_1,ulong param_2,ulong param_3,
          CSimpleHash *param_4,CSimpleHash *param_5,CSimpleHash *param_6,_MDL *param_7)

{
  longlong lVar1;
  undefined4 uVar2;
  _URB *p_Var3;
  long lVar4;
  
  if (((param_2 == 0x18) && (*(short *)param_1 == 0x18)) && (7 < param_3)) {
    p_Var3 = CTsUrbResult::AllocateUrb((CTsUrbResult *)this,0x88);
    lVar4 = 0;
    if (p_Var3 == (_URB *)0x0) {
      return -0x3fffffe9;
    }
    memset(p_Var3 + 2,0,0x86);
    *(undefined2 *)p_Var3 = 0x88;
    *(undefined2 *)(p_Var3 + 2) = *(undefined2 *)(param_1 + 2);
    *(undefined4 *)(p_Var3 + 0x20) = *(undefined4 *)(param_1 + 0xc);
    *(_MDL **)(p_Var3 + 0x30) = param_7;
    if (param_7 == (_MDL *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_7 + 0x28);
    }
    *(undefined4 *)(p_Var3 + 0x24) = uVar2;
    *(undefined8 *)(p_Var3 + 0x80) = *(undefined8 *)(param_1 + 0x10);
    if ((*(uint *)(param_1 + 0xc) & 8) == 0) {
      if ((*(uint *)param_6 <= (*(uint *)(param_1 + 8) & 0xffff)) ||
         (lVar1 = *(longlong *)
                   (*(longlong *)(param_6 + 8) + (ulonglong)(*(uint *)(param_1 + 8) & 0xffff) * 8),
         lVar1 == *(longlong *)(param_6 + 0x10))) goto LAB_140005498;
      *(longlong *)(p_Var3 + 0x18) = lVar1;
    }
    *(_MDL **)(this + 0x6b0) = param_7;
    *(undefined2 *)(this + 0x6aa) = 8;
  }
  else {
LAB_140005498:
    lVar4 = -0x3ffffff3;
  }
  return lVar4;
}



===== Initialize @ 140005580 =====

/* private: virtual long __cdecl CTsUrbResultControlTransferEx::Initialize(unsigned char *
   __ptr64,unsigned long,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class
   CSimpleHash * __ptr64,struct _MDL * __ptr64) __ptr64 */

long __thiscall
CTsUrbResultControlTransferEx::Initialize
          (CTsUrbResultControlTransferEx *this,uchar *param_1,ulong param_2,ulong param_3,
          CSimpleHash *param_4,CSimpleHash *param_5,CSimpleHash *param_6,_MDL *param_7)

{
  longlong lVar1;
  undefined4 uVar2;
  _URB *p_Var3;
  long lVar4;
  
  if (((param_2 == 0x1c) && (*(short *)param_1 == 0x1c)) && (7 < param_3)) {
    p_Var3 = CTsUrbResult::AllocateUrb((CTsUrbResult *)this,0x88);
    lVar4 = 0;
    if (p_Var3 == (_URB *)0x0) {
      return -0x3fffffe9;
    }
    memset(p_Var3 + 2,0,0x86);
    *(undefined2 *)p_Var3 = 0x88;
    *(undefined2 *)(p_Var3 + 2) = *(undefined2 *)(param_1 + 2);
    *(undefined4 *)(p_Var3 + 0x20) = *(undefined4 *)(param_1 + 0xc);
    *(_MDL **)(p_Var3 + 0x30) = param_7;
    if (param_7 == (_MDL *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_7 + 0x28);
    }
    *(undefined4 *)(p_Var3 + 0x24) = uVar2;
    *(undefined4 *)(p_Var3 + 0x38) = *(undefined4 *)(param_1 + 0x10);
    *(undefined8 *)(p_Var3 + 0x80) = *(undefined8 *)(param_1 + 0x14);
    if ((*(uint *)(param_1 + 0xc) & 8) == 0) {
      if ((*(uint *)param_6 <= (*(uint *)(param_1 + 8) & 0xffff)) ||
         (lVar1 = *(longlong *)
                   (*(longlong *)(param_6 + 8) + (ulonglong)(*(uint *)(param_1 + 8) & 0xffff) * 8),
         lVar1 == *(longlong *)(param_6 + 0x10))) goto LAB_1400055a8;
      *(longlong *)(p_Var3 + 0x18) = lVar1;
    }
    *(_MDL **)(this + 0x6b0) = param_7;
    *(undefined2 *)(this + 0x6aa) = 8;
  }
  else {
LAB_1400055a8:
    lVar4 = -0x3ffffff3;
  }
  return lVar4;
}



===== Initialize @ 1400056a0 =====

/* private: virtual long __cdecl CTsUrbResultCurrentFrame::Initialize(unsigned char *
   __ptr64,unsigned long,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class
   CSimpleHash * __ptr64,struct _MDL * __ptr64) __ptr64 */

long __thiscall
CTsUrbResultCurrentFrame::Initialize
          (CTsUrbResultCurrentFrame *this,uchar *param_1,ulong param_2,ulong param_3,
          CSimpleHash *param_4,CSimpleHash *param_5,CSimpleHash *param_6,_MDL *param_7)

{
  _URB *p_Var1;
  long lVar2;
  
  lVar2 = 0;
  if ((((param_7 == (_MDL *)0x0) && (param_2 == 8)) && (*(short *)param_1 == 8)) && (0xb < param_3))
  {
    p_Var1 = CTsUrbResult::AllocateUrb((CTsUrbResult *)this,0x20);
    if (p_Var1 == (_URB *)0x0) {
      lVar2 = -0x3fffffe9;
    }
    else {
      *(undefined8 *)p_Var1 = 0;
      *(undefined8 *)(p_Var1 + 8) = 0;
      *(undefined8 *)(p_Var1 + 0x10) = 0;
      *(undefined8 *)(p_Var1 + 0x18) = 0;
      *(undefined2 *)p_Var1 = 0x20;
      *(undefined2 *)(p_Var1 + 2) = *(undefined2 *)(param_1 + 2);
      *(undefined2 *)(this + 0x6aa) = 0xc;
    }
  }
  else {
    lVar2 = -0x3ffffff3;
  }
  return lVar2;
}



===== Initialize @ 140005740 =====

/* private: virtual long __cdecl CTsUrbResultGetConfigRequest::Initialize(unsigned char *
   __ptr64,unsigned long,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class
   CSimpleHash * __ptr64,struct _MDL * __ptr64) __ptr64 */

long __thiscall
CTsUrbResultGetConfigRequest::Initialize
          (CTsUrbResultGetConfigRequest *this,uchar *param_1,ulong param_2,ulong param_3,
          CSimpleHash *param_4,CSimpleHash *param_5,CSimpleHash *param_6,_MDL *param_7)

{
  _URB *p_Var1;
  long lVar2;
  
  lVar2 = 0;
  if ((((param_7 == (_MDL *)0x0) || (param_2 != 8)) || (*(short *)param_1 != 8)) || (param_3 < 8)) {
    lVar2 = -0x3ffffff3;
  }
  else {
    p_Var1 = CTsUrbResult::AllocateUrb((CTsUrbResult *)this,0x88);
    if (p_Var1 == (_URB *)0x0) {
      lVar2 = -0x3fffffe9;
    }
    else {
      memset(p_Var1 + 2,0,0x86);
      *(undefined2 *)p_Var1 = 0x88;
      *(undefined2 *)(p_Var1 + 2) = *(undefined2 *)(param_1 + 2);
      *(_MDL **)(p_Var1 + 0x30) = param_7;
      *(undefined4 *)(p_Var1 + 0x24) = *(undefined4 *)(param_7 + 0x28);
      *(_MDL **)(this + 0x6b0) = param_7;
      *(undefined2 *)(this + 0x6aa) = 8;
    }
  }
  return lVar2;
}



===== Initialize @ 140005810 =====

/* private: virtual long __cdecl CTsUrbResultGetStatus::Initialize(unsigned char * __ptr64,unsigned
   long,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class CSimpleHash *
   __ptr64,struct _MDL * __ptr64) __ptr64 */

long __thiscall
CTsUrbResultGetStatus::Initialize
          (CTsUrbResultGetStatus *this,uchar *param_1,ulong param_2,ulong param_3,
          CSimpleHash *param_4,CSimpleHash *param_5,CSimpleHash *param_6,_MDL *param_7)

{
  _URB *p_Var1;
  long lVar2;
  
  lVar2 = 0;
  if ((((param_7 == (_MDL *)0x0) || (param_2 != 0xc)) || (*(short *)param_1 != 0xc)) ||
     (param_3 < 8)) {
    lVar2 = -0x3ffffff3;
  }
  else {
    p_Var1 = CTsUrbResult::AllocateUrb((CTsUrbResult *)this,0x88);
    if (p_Var1 == (_URB *)0x0) {
      lVar2 = -0x3fffffe9;
    }
    else {
      memset(p_Var1 + 2,0,0x86);
      *(undefined2 *)p_Var1 = 0x88;
      *(undefined2 *)(p_Var1 + 2) = *(undefined2 *)(param_1 + 2);
      *(undefined2 *)(p_Var1 + 0x84) = *(undefined2 *)(param_1 + 8);
      *(_MDL **)(p_Var1 + 0x30) = param_7;
      *(undefined4 *)(p_Var1 + 0x24) = *(undefined4 *)(param_7 + 0x28);
      *(_MDL **)(this + 0x6b0) = param_7;
      *(undefined2 *)(this + 0x6aa) = 8;
    }
  }
  return lVar2;
}



===== Initialize @ 1400058f0 =====

/* private: virtual long __cdecl CTsUrbResultIsochTransfer::Initialize(unsigned char *
   __ptr64,unsigned long,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class
   CSimpleHash * __ptr64,struct _MDL * __ptr64) __ptr64 */

long __thiscall
CTsUrbResultIsochTransfer::Initialize
          (CTsUrbResultIsochTransfer *this,uchar *param_1,ulong param_2,ulong param_3,
          CSimpleHash *param_4,CSimpleHash *param_5,CSimpleHash *param_6,_MDL *param_7)

{
  longlong lVar1;
  _URB *p_Var2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  uint uVar6;
  
  if (((param_7 != (_MDL *)0x0) && (0x1b < param_2)) && (*(ushort *)param_1 == param_2)) {
    uVar5 = (ulonglong)*(uint *)(param_1 + 0x14) * 0xc;
    if (0xffffffff < uVar5) {
      return -0x3fffff6b;
    }
    iVar4 = (int)uVar5;
    if (((iVar4 == param_2 - 0x1c) && (uVar6 = iVar4 + 0x8c, 0x8b < uVar6)) &&
       ((uVar6 < 0x10000 && ((uVar3 = iVar4 + 0x14, 0x13 < uVar3 && (uVar3 < 0x10000)))))) {
      if (param_3 < uVar3) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                    &WPP_90671cf8bc7431750ea4075ddc471495_Traceguids,param_3,(char)uVar3);
        }
      }
      else {
        p_Var2 = CTsUrbResult::AllocateUrb((CTsUrbResult *)this,uVar6);
        if (p_Var2 == (_URB *)0x0) {
          return -0x3fffffe9;
        }
        memset(p_Var2 + 2,0,0x8a);
        *(short *)p_Var2 = (short)uVar6;
        *(undefined2 *)(p_Var2 + 2) = *(undefined2 *)(param_1 + 2);
        *(undefined4 *)(p_Var2 + 0x20) = *(undefined4 *)(param_1 + 0xc);
        *(_MDL **)(p_Var2 + 0x30) = param_7;
        *(undefined4 *)(p_Var2 + 0x24) = *(undefined4 *)(param_7 + 0x28);
        *(undefined4 *)(p_Var2 + 0x80) = *(undefined4 *)(param_1 + 0x10);
        *(undefined4 *)(p_Var2 + 0x84) = *(undefined4 *)(param_1 + 0x14);
        *(undefined4 *)(p_Var2 + 0x88) = *(undefined4 *)(param_1 + 0x18);
        if (((*(uint *)(param_1 + 8) & 0xffff) < *(uint *)param_6) &&
           (lVar1 = *(longlong *)
                     (*(longlong *)(param_6 + 8) + (ulonglong)(*(uint *)(param_1 + 8) & 0xffff) * 8)
           , lVar1 != *(longlong *)(param_6 + 0x10))) {
          *(longlong *)(p_Var2 + 0x18) = lVar1;
          memmove(p_Var2 + 0x8c,param_1 + 0x1c,uVar5 & 0xffffffff);
          *(_MDL **)(this + 0x6b0) = param_7;
          *(short *)(this + 0x6aa) = (short)uVar3;
          return 0;
        }
      }
    }
  }
  return -0x3ffffff3;
}



===== Initialize @ 140005ab0 =====

/* private: virtual long __cdecl CTsUrbResultOsFeatureDescriptor::Initialize(unsigned char *
   __ptr64,unsigned long,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class
   CSimpleHash * __ptr64,struct _MDL * __ptr64) __ptr64 */

long __thiscall
CTsUrbResultOsFeatureDescriptor::Initialize
          (CTsUrbResultOsFeatureDescriptor *this,uchar *param_1,ulong param_2,ulong param_3,
          CSimpleHash *param_4,CSimpleHash *param_5,CSimpleHash *param_6,_MDL *param_7)

{
  _URB *p_Var1;
  long lVar2;
  
  lVar2 = 0;
  if ((((param_7 == (_MDL *)0x0) || (param_2 != 0x10)) || (*(short *)param_1 != 0x10)) ||
     (param_3 < 8)) {
    lVar2 = -0x3ffffff3;
  }
  else {
    p_Var1 = CTsUrbResult::AllocateUrb((CTsUrbResult *)this,0x88);
    if (p_Var1 == (_URB *)0x0) {
      lVar2 = -0x3fffffe9;
    }
    else {
      memset(p_Var1 + 2,0,0x86);
      *(undefined2 *)p_Var1 = 0x88;
      *(undefined2 *)(p_Var1 + 2) = *(undefined2 *)(param_1 + 2);
      p_Var1[0x80] = (_URB)(((byte)p_Var1[0x80] ^ param_1[8]) & 0x1f ^ (byte)p_Var1[0x80]);
      p_Var1[0x82] = *(_URB *)(param_1 + 9);
      p_Var1[0x83] = *(_URB *)(param_1 + 10);
      *(undefined2 *)(p_Var1 + 0x84) = *(undefined2 *)(param_1 + 0xc);
      *(_MDL **)(p_Var1 + 0x30) = param_7;
      *(undefined4 *)(p_Var1 + 0x24) = *(undefined4 *)(param_7 + 0x28);
      *(_MDL **)(this + 0x6b0) = param_7;
      *(undefined2 *)(this + 0x6aa) = 8;
    }
  }
  return lVar2;
}



===== Initialize @ 140005bb0 =====

/* private: virtual long __cdecl CTsUrbResultPipeRequest::Initialize(unsigned char *
   __ptr64,unsigned long,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class
   CSimpleHash * __ptr64,struct _MDL * __ptr64) __ptr64 */

long __thiscall
CTsUrbResultPipeRequest::Initialize
          (CTsUrbResultPipeRequest *this,uchar *param_1,ulong param_2,ulong param_3,
          CSimpleHash *param_4,CSimpleHash *param_5,CSimpleHash *param_6,_MDL *param_7)

{
  longlong lVar1;
  _URB *p_Var2;
  
  if ((((param_7 == (_MDL *)0x0) && (param_2 == 0xc)) && (*(short *)param_1 == 0xc)) &&
     (7 < param_3)) {
    p_Var2 = CTsUrbResult::AllocateUrb((CTsUrbResult *)this,0x28);
    if (p_Var2 == (_URB *)0x0) {
      return -0x3fffffe9;
    }
    *(undefined8 *)p_Var2 = 0;
    *(undefined8 *)(p_Var2 + 8) = 0;
    *(undefined8 *)(p_Var2 + 0x10) = 0;
    *(undefined8 *)(p_Var2 + 0x18) = 0;
    *(undefined8 *)(p_Var2 + 0x20) = 0;
    *(undefined2 *)p_Var2 = 0x28;
    *(undefined2 *)(p_Var2 + 2) = *(undefined2 *)(param_1 + 2);
    if (((*(uint *)(param_1 + 8) & 0xffff) < *(uint *)param_6) &&
       (lVar1 = *(longlong *)
                 (*(longlong *)(param_6 + 8) + (ulonglong)(*(uint *)(param_1 + 8) & 0xffff) * 8),
       lVar1 != *(longlong *)(param_6 + 0x10))) {
      *(longlong *)(p_Var2 + 0x18) = lVar1;
      *(undefined2 *)(this + 0x6aa) = 8;
      return 0;
    }
  }
  return -0x3ffffff3;
}



===== Initialize @ 140005c80 =====

/* private: virtual long __cdecl CTsUrbResultSelectConfig::Initialize(unsigned char *
   __ptr64,unsigned long,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class
   CSimpleHash * __ptr64,struct _MDL * __ptr64) __ptr64 */

long __thiscall
CTsUrbResultSelectConfig::Initialize
          (CTsUrbResultSelectConfig *this,uchar *param_1,ulong param_2,ulong param_3,
          CSimpleHash *param_4,CSimpleHash *param_5,CSimpleHash *param_6,_MDL *param_7)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  _URB *p_Var4;
  ushort *puVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  _URB *_Dst;
  ushort *puVar13;
  uint local_38;
  ushort *local_30;
  
  local_30 = (ushort *)0x0;
  local_38 = 0;
  if ((param_7 == (_MDL *)0x0) && (0xf < param_2)) {
    puVar13 = (ushort *)(param_1 + 0x10);
    uVar10 = param_2 - 0x10;
    if ((*(ushort *)param_1 == param_2) && (uVar9 = *(uint *)(param_1 + 0xc), uVar9 != 0)) {
      uVar12 = 0;
      puVar5 = puVar13;
      uVar8 = 0x28;
      uVar11 = 0x10;
      do {
        if (uVar10 < 0xc) {
          return -0x3ffffff3;
        }
        uVar1 = puVar5[1];
        if ((uint)uVar1 < *(uint *)(puVar5 + 4)) {
          return -0x3ffffff3;
        }
        uVar7 = (ulonglong)*(uint *)(puVar5 + 4) * 0xc;
        if (0xffffffff < uVar7) {
          return -0x3fffff6b;
        }
        uVar6 = (int)uVar7 + 0xc;
        if (uVar6 < 0xc) {
          return -0x3fffff6b;
        }
        if (*puVar5 != uVar6) {
          return -0x3ffffff3;
        }
        if (uVar10 < uVar6) {
          return -0x3ffffff3;
        }
        uVar2 = (uint)uVar1 * 0x18 + 0x18;
        if (uVar2 < 0x18) {
          return -0x3fffff6b;
        }
        uVar2 = uVar2 + uVar8;
        if (uVar2 < uVar8) {
          return -0x3fffff6b;
        }
        uVar3 = (uint)uVar1 * 0x14 + 0x10;
        if (uVar3 < 0x10) {
          return -0x3fffff6b;
        }
        uVar3 = uVar3 + uVar11;
        if (uVar3 < uVar11) {
          return -0x3fffff6b;
        }
        uVar10 = uVar10 - uVar6;
        puVar5 = (ushort *)((longlong)puVar5 + (ulonglong)*puVar5);
        uVar12 = uVar12 + 1;
        uVar8 = uVar2;
        uVar11 = uVar3;
      } while (uVar12 < uVar9);
      if (param_1[8] != '\0') {
        if (uVar10 < 9) {
          return -0x3ffffff3;
        }
        if ((char)*puVar5 != '\t') {
          return -0x3ffffff3;
        }
        if ((byte)puVar5[2] != uVar9) {
          return -0x3ffffff3;
        }
        local_38 = (uint)puVar5[1];
        if (local_38 != uVar10) {
          return -0x3ffffff3;
        }
        uVar10 = 0;
        uVar8 = local_38 + uVar2;
        local_30 = puVar5;
        if (local_38 + uVar2 < uVar2) {
          return -0x3fffff6b;
        }
      }
      if (((uVar8 < 0x10000) && (uVar10 == 0)) && (uVar3 < 0x10000)) {
        if (uVar3 <= param_3) {
          p_Var4 = CTsUrbResult::AllocateUrb((CTsUrbResult *)this,uVar8);
          if (p_Var4 == (_URB *)0x0) {
            return -0x3fffffe9;
          }
          _Dst = p_Var4 + 0x28;
          uVar10 = 0;
          *(undefined8 *)p_Var4 = 0;
          *(undefined8 *)(p_Var4 + 8) = 0;
          *(undefined8 *)(p_Var4 + 0x10) = 0;
          *(undefined8 *)(p_Var4 + 0x18) = 0;
          *(undefined8 *)(p_Var4 + 0x20) = 0;
          *(short *)p_Var4 = (short)uVar2;
          *(undefined2 *)(p_Var4 + 2) = *(undefined2 *)(param_1 + 2);
          if (*(int *)(param_1 + 0xc) != 0) {
            do {
              uVar9 = (puVar13[1] + 1) * 0x18;
              memset(_Dst,0,(ulonglong)uVar9);
              *(ushort *)_Dst = (ushort)uVar9;
              _Dst[2] = *(_URB *)(puVar13 + 2);
              _Dst[3] = *(_URB *)((longlong)puVar13 + 5);
              *(undefined4 *)(_Dst + 0x10) = *(undefined4 *)(puVar13 + 4);
              uVar7 = 0;
              if (*(int *)(puVar13 + 4) != 0) {
                do {
                  uVar9 = (int)uVar7 + 1;
                  *(ushort *)(_Dst + uVar7 * 0x18 + 0x18) = puVar13[uVar7 * 6 + 6];
                  *(undefined4 *)(_Dst + uVar7 * 0x18 + 0x28) =
                       *(undefined4 *)(puVar13 + uVar7 * 6 + 8);
                  *(undefined4 *)(_Dst + uVar7 * 0x18 + 0x2c) =
                       *(undefined4 *)(puVar13 + uVar7 * 6 + 10);
                  uVar7 = (ulonglong)uVar9;
                } while (uVar9 < *(uint *)(puVar13 + 4));
              }
              uVar10 = uVar10 + 1;
              _Dst = _Dst + *(ushort *)_Dst;
              puVar13 = (ushort *)((longlong)puVar13 + (ulonglong)*puVar13);
            } while (uVar10 < *(uint *)(param_1 + 0xc));
          }
          if (local_30 != (ushort *)0x0) {
            *(_URB **)(p_Var4 + 0x18) = p_Var4 + *(ushort *)p_Var4;
            memmove(p_Var4 + *(ushort *)p_Var4,local_30,(ulonglong)local_38);
          }
          *(short *)(this + 0x6aa) = (short)uVar3;
          this[0x6b8] = *(CTsUrbResultSelectConfig *)(param_1 + 0xc);
          return 0;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                    &WPP_90671cf8bc7431750ea4075ddc471495_Traceguids,param_3,(char)uVar3);
        }
      }
    }
  }
  return -0x3ffffff3;
}



===== Initialize @ 140005f80 =====

/* private: virtual long __cdecl CTsUrbResultSelectInterface::Initialize(unsigned char *
   __ptr64,unsigned long,unsigned long,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class
   CSimpleHash * __ptr64,struct _MDL * __ptr64) __ptr64 */

long __thiscall
CTsUrbResultSelectInterface::Initialize
          (CTsUrbResultSelectInterface *this,uchar *param_1,ulong param_2,ulong param_3,
          CSimpleHash *param_4,CSimpleHash *param_5,CSimpleHash *param_6,_MDL *param_7)

{
  longlong lVar1;
  ulonglong uVar2;
  _URB *p_Var3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  if (((((param_7 == (_MDL *)0x0) && (0xb < param_2)) &&
       (uVar5 = param_2 - 0xc, *(ushort *)param_1 == param_2)) && (0xb < uVar5)) &&
     ((uVar2 = Feature_3771360570__private_IsEnabledDeviceUsageNoInline(), (int)uVar2 == 0 ||
      (*(uint *)(param_1 + 0x14) <= (uint)*(ushort *)(param_1 + 0xe))))) {
    if ((0xffffffff < (ulonglong)*(uint *)(param_1 + 0x14) * 0xc) ||
       (uVar4 = (int)((ulonglong)*(uint *)(param_1 + 0x14) * 0xc) + 0xc, uVar4 < 0xc)) {
      return -0x3fffff6b;
    }
    if ((*(ushort *)(param_1 + 0xc) == uVar4) && (uVar4 <= uVar5)) {
      iVar7 = (uint)*(ushort *)(param_1 + 0xe) * 0x18;
      if (iVar7 + 0x18U < 0x18) {
        return -0x3fffff6b;
      }
      uVar8 = iVar7 + 0x38;
      if (uVar8 < 0x20) {
        return -0x3fffff6b;
      }
      iVar7 = (uint)*(ushort *)(param_1 + 0xe) * 0x14;
      if (iVar7 + 0x10U < 0x10) {
        return -0x3fffff6b;
      }
      uVar6 = iVar7 + 0x18;
      if (uVar6 < 8) {
        return -0x3fffff6b;
      }
      if ((uVar5 == uVar4) && (uVar6 < 0x10000)) {
        if (param_3 < uVar6) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                      &WPP_90671cf8bc7431750ea4075ddc471495_Traceguids,param_3,(char)uVar6);
          }
        }
        else {
          p_Var3 = CTsUrbResult::AllocateUrb((CTsUrbResult *)this,uVar8);
          if (p_Var3 == (_URB *)0x0) {
            return -0x3fffffe9;
          }
          *(undefined8 *)p_Var3 = 0;
          *(undefined8 *)(p_Var3 + 8) = 0;
          *(undefined8 *)(p_Var3 + 0x10) = 0;
          *(undefined8 *)(p_Var3 + 0x18) = 0;
          *(short *)p_Var3 = (short)uVar8;
          *(undefined2 *)(p_Var3 + 2) = *(undefined2 *)(param_1 + 2);
          if (((*(uint *)(param_1 + 8) & 0xffff) < *(uint *)param_4) &&
             (lVar1 = *(longlong *)
                       (*(longlong *)(param_4 + 8) +
                       (ulonglong)(*(uint *)(param_1 + 8) & 0xffff) * 8),
             lVar1 != *(longlong *)(param_4 + 0x10))) {
            *(longlong *)(p_Var3 + 0x18) = lVar1;
            uVar5 = (*(ushort *)(param_1 + 0xe) + 1) * 0x18;
            memset(p_Var3 + 0x20,0,(ulonglong)uVar5);
            *(short *)(p_Var3 + 0x20) = (short)uVar5;
            p_Var3[0x22] = *(_URB *)(param_1 + 0x10);
            p_Var3[0x23] = *(_URB *)(param_1 + 0x11);
            *(undefined4 *)(p_Var3 + 0x30) = *(undefined4 *)(param_1 + 0x14);
            uVar2 = 0;
            if (*(int *)(param_1 + 0x14) != 0) {
              do {
                uVar5 = (int)uVar2 + 1;
                *(undefined2 *)(p_Var3 + uVar2 * 0x18 + 0x38) =
                     *(undefined2 *)(param_1 + uVar2 * 0xc + 0x18);
                *(undefined4 *)(p_Var3 + uVar2 * 0x18 + 0x48) =
                     *(undefined4 *)(param_1 + uVar2 * 0xc + 0x1c);
                *(undefined4 *)(p_Var3 + uVar2 * 0x18 + 0x4c) =
                     *(undefined4 *)(param_1 + uVar2 * 0xc + 0x20);
                uVar2 = (ulonglong)uVar5;
              } while (uVar5 < *(uint *)(param_1 + 0x14));
            }
            *(short *)(this + 0x6aa) = (short)uVar6;
            return 0;
          }
        }
      }
    }
  }
  return -0x3ffffff3;
}



===== TsUrbResultInitialize @ 1400061c0 =====

/* public: virtual void __cdecl CTsUrbResult::TsUrbResultInitialize(class CSimpleHash *
   __ptr64,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,union _TS_URB_RESULT *
   __ptr64,unsigned long,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbResult::TsUrbResultInitialize
          (CTsUrbResult *this,CSimpleHash *param_1,CSimpleHash *param_2,CSimpleHash *param_3,
          _TS_URB_RESULT *param_4,ulong param_5,ulong *param_6)

{
  return;
}



===== TsUrbResultInitialize @ 1400061d0 =====

/* private: virtual void __cdecl CTsUrbResultControlTransferEx::TsUrbResultInitialize(class
   CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,union
   _TS_URB_RESULT * __ptr64,unsigned long,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbResultControlTransferEx::TsUrbResultInitialize
          (CTsUrbResultControlTransferEx *this,CSimpleHash *param_1,CSimpleHash *param_2,
          CSimpleHash *param_3,_TS_URB_RESULT *param_4,ulong param_5,ulong *param_6)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(this + 0x6a0);
  if (7 < param_5) {
    *(undefined2 *)param_4 = 8;
    *(undefined4 *)(param_4 + 4) = *(undefined4 *)(lVar1 + 4);
    *param_6 = 0;
    *param_6 = *(ulong *)(lVar1 + 0x24);
  }
  return;
}



===== TsUrbResultInitialize @ 140006210 =====

/* private: virtual void __cdecl CTsUrbResultControlFeature::TsUrbResultInitialize(class CSimpleHash
   * __ptr64,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,union _TS_URB_RESULT *
   __ptr64,unsigned long,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbResultControlFeature::TsUrbResultInitialize
          (CTsUrbResultControlFeature *this,CSimpleHash *param_1,CSimpleHash *param_2,
          CSimpleHash *param_3,_TS_URB_RESULT *param_4,ulong param_5,ulong *param_6)

{
  longlong lVar1;
  
  if (7 < param_5) {
    lVar1 = *(longlong *)(this + 0x6a0);
    *(undefined2 *)param_4 = 8;
    *(undefined4 *)(param_4 + 4) = *(undefined4 *)(lVar1 + 4);
    *param_6 = 0;
  }
  return;
}



===== TsUrbResultInitialize @ 140006240 =====

/* private: virtual void __cdecl CTsUrbResultCurrentFrame::TsUrbResultInitialize(class CSimpleHash *
   __ptr64,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,union _TS_URB_RESULT *
   __ptr64,unsigned long,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbResultCurrentFrame::TsUrbResultInitialize
          (CTsUrbResultCurrentFrame *this,CSimpleHash *param_1,CSimpleHash *param_2,
          CSimpleHash *param_3,_TS_URB_RESULT *param_4,ulong param_5,ulong *param_6)

{
  int iVar1;
  longlong lVar2;
  
  if (0xb < param_5) {
    lVar2 = *(longlong *)(this + 0x6a0);
    iVar1 = *(int *)(lVar2 + 4);
    *(int *)(param_4 + 4) = iVar1;
    if (iVar1 < 0) {
      *(undefined2 *)param_4 = 8;
    }
    else {
      *(undefined2 *)param_4 = 0xc;
      *(undefined4 *)(param_4 + 8) = *(undefined4 *)(lVar2 + 0x18);
    }
    *param_6 = 0;
  }
  return;
}



===== TsUrbResultInitialize @ 140006290 =====

/* private: virtual void __cdecl CTsUrbResultIsochTransfer::TsUrbResultInitialize(class CSimpleHash
   * __ptr64,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,union _TS_URB_RESULT *
   __ptr64,unsigned long,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbResultIsochTransfer::TsUrbResultInitialize
          (CTsUrbResultIsochTransfer *this,CSimpleHash *param_1,CSimpleHash *param_2,
          CSimpleHash *param_3,_TS_URB_RESULT *param_4,ulong param_5,ulong *param_6)

{
  int iVar1;
  longlong lVar2;
  ushort uVar3;
  
  lVar2 = *(longlong *)(this + 0x6a0);
  uVar3 = *(short *)(lVar2 + 0x84) * 0xc;
  if (uVar3 + 0x14 <= param_5) {
    iVar1 = *(int *)(lVar2 + 4);
    *(int *)(param_4 + 4) = iVar1;
    if (iVar1 < 0) {
      *(undefined2 *)param_4 = 8;
    }
    else {
      *(ushort *)param_4 = uVar3 + 0x14;
      *(undefined4 *)(param_4 + 8) = *(undefined4 *)(lVar2 + 0x80);
      *(undefined4 *)(param_4 + 0xc) = *(undefined4 *)(lVar2 + 0x84);
      *(undefined4 *)(param_4 + 0x10) = *(undefined4 *)(lVar2 + 0x88);
      memmove(param_4 + 0x14,(void *)(lVar2 + 0x8c),(ulonglong)uVar3);
      *param_6 = *(ulong *)(lVar2 + 0x24);
    }
  }
  return;
}



===== TsUrbResultInitialize @ 140006330 =====

/* private: virtual void __cdecl CTsUrbResultSelectConfig::TsUrbResultInitialize(class CSimpleHash *
   __ptr64,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,union _TS_URB_RESULT *
   __ptr64,unsigned long,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbResultSelectConfig::TsUrbResultInitialize
          (CTsUrbResultSelectConfig *this,CSimpleHash *param_1,CSimpleHash *param_2,
          CSimpleHash *param_3,_TS_URB_RESULT *param_4,ulong param_5,ulong *param_6)

{
  CTsUrbResultSelectConfig CVar1;
  longlong lVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  ulonglong uVar7;
  _TS_URB_RESULT *p_Var8;
  ulong local_res8 [2];
  
  local_res8[0] = 0;
  *param_6 = 0;
  lVar2 = *(longlong *)(this + 0x6a0);
  if (param_5 < 0x10) {
    return;
  }
  *(undefined2 *)param_4 = *(undefined2 *)(this + 0x6aa);
  *(undefined4 *)(param_4 + 4) = *(undefined4 *)(lVar2 + 4);
  lVar3 = CSimpleHash::AddItemDuplicateOk(param_1,*(void **)(lVar2 + 0x20),local_res8);
  if (-1 < lVar3) {
    if (local_res8[0] < 0x10000) {
      uVar4 = local_res8[0] | 0xffff0000;
    }
    else {
      uVar4 = 0;
    }
    *(uint *)(param_4 + 8) = uVar4;
    if (uVar4 != 0) {
      CVar1 = this[0x6b8];
      if (*(longlong *)(lVar2 + 0x18) == 0) {
        if (CVar1 != (CTsUrbResultSelectConfig)0x1) goto LAB_1400063dd;
      }
      else if (CVar1 != *(CTsUrbResultSelectConfig *)(*(longlong *)(lVar2 + 0x18) + 4))
      goto LAB_1400063dd;
      puVar6 = (ushort *)(lVar2 + 0x28);
      *(uint *)(param_4 + 0xc) = (uint)(byte)CVar1;
      uVar4 = 0;
      p_Var8 = param_4 + 0x10;
      if ((byte)CVar1 == 0) {
        return;
      }
      while (((((ulonglong)*(uint *)(puVar6 + 8) * 0x14 < 0x100000000 &&
               (uVar5 = (int)((ulonglong)*(uint *)(puVar6 + 8) * 0x14) + 0x10, 0xf < uVar5)) &&
              (uVar5 < 0x10000)) && (p_Var8 + uVar5 <= param_4 + param_5))) {
        *(ushort *)p_Var8 = (ushort)uVar5;
        p_Var8[2] = *(_TS_URB_RESULT *)(puVar6 + 1);
        p_Var8[3] = *(_TS_URB_RESULT *)((longlong)puVar6 + 3);
        *(undefined4 *)(p_Var8 + 0xc) = *(undefined4 *)(puVar6 + 8);
        p_Var8[4] = *(_TS_URB_RESULT *)(puVar6 + 2);
        p_Var8[5] = *(_TS_URB_RESULT *)((longlong)puVar6 + 5);
        p_Var8[6] = *(_TS_URB_RESULT *)(puVar6 + 3);
        *(undefined4 *)(p_Var8 + 0xc) = *(undefined4 *)(puVar6 + 8);
        lVar3 = CSimpleHash::AddItemDuplicateOk(param_2,*(void **)(puVar6 + 4),local_res8);
        if (lVar3 < 0) break;
        if (local_res8[0] < 0x10000) {
          uVar5 = local_res8[0] | 0xffff0000;
        }
        else {
          uVar5 = 0;
        }
        *(uint *)(p_Var8 + 8) = uVar5;
        if (uVar5 == 0) break;
        uVar7 = 0;
        if (*(int *)(puVar6 + 8) != 0) {
          do {
            *(ushort *)(p_Var8 + uVar7 * 0x14 + 0x10) = puVar6[uVar7 * 0xc + 0xc];
            p_Var8[uVar7 * 0x14 + 0x12] = *(_TS_URB_RESULT *)(puVar6 + uVar7 * 0xc + 0xd);
            p_Var8[uVar7 * 0x14 + 0x13] =
                 *(_TS_URB_RESULT *)((longlong)puVar6 + uVar7 * 0x18 + 0x1b);
            *(undefined4 *)(p_Var8 + uVar7 * 0x14 + 0x14) =
                 *(undefined4 *)(puVar6 + uVar7 * 0xc + 0xe);
            *(undefined4 *)(p_Var8 + uVar7 * 0x14 + 0x1c) =
                 *(undefined4 *)(puVar6 + uVar7 * 0xc + 0x14);
            *(undefined4 *)(p_Var8 + uVar7 * 0x14 + 0x20) =
                 *(undefined4 *)(puVar6 + uVar7 * 0xc + 0x16);
            lVar3 = CSimpleHash::AddItemDuplicateOk
                              (param_3,*(void **)(puVar6 + uVar7 * 0xc + 0x10),local_res8);
            if (lVar3 < 0) goto LAB_1400063dd;
            if (local_res8[0] < 0x10000) {
              uVar5 = local_res8[0] | 0xffff0000;
            }
            else {
              uVar5 = 0;
            }
            *(uint *)(p_Var8 + uVar7 * 0x14 + 0x18) = uVar5;
            if (uVar5 == 0) goto LAB_1400063dd;
            uVar5 = (int)uVar7 + 1;
            uVar7 = (ulonglong)uVar5;
          } while (uVar5 < *(uint *)(puVar6 + 8));
        }
        uVar4 = uVar4 + 1;
        puVar6 = (ushort *)((longlong)puVar6 + (ulonglong)*puVar6);
        p_Var8 = p_Var8 + *(ushort *)p_Var8;
        if (*(uint *)(param_4 + 0xc) <= uVar4) {
          return;
        }
      }
    }
  }
LAB_1400063dd:
  *(undefined2 *)param_4 = 8;
  *(undefined4 *)(param_4 + 4) = 0x80000300;
  return;
}



===== TsUrbResultInitialize @ 140006570 =====

/* private: virtual void __cdecl CTsUrbResultSelectInterface::TsUrbResultInitialize(class
   CSimpleHash * __ptr64,class CSimpleHash * __ptr64,class CSimpleHash * __ptr64,union
   _TS_URB_RESULT * __ptr64,unsigned long,unsigned long * __ptr64) __ptr64 */

void __thiscall
CTsUrbResultSelectInterface::TsUrbResultInitialize
          (CTsUrbResultSelectInterface *this,CSimpleHash *param_1,CSimpleHash *param_2,
          CSimpleHash *param_3,_TS_URB_RESULT *param_4,ulong param_5,ulong *param_6)

{
  longlong lVar1;
  long lVar2;
  int iVar4;
  uint uVar3;
  ulonglong uVar5;
  ulong local_res8 [2];
  
  local_res8[0] = 0;
  *param_6 = 0;
  lVar1 = *(longlong *)(this + 0x6a0);
  if (7 < param_5) {
    *(undefined2 *)param_4 = *(undefined2 *)(this + 0x6aa);
    *(undefined4 *)(param_4 + 4) = *(undefined4 *)(lVar1 + 4);
    uVar5 = (ulonglong)*(uint *)(lVar1 + 0x30) * 0x14;
    if (uVar5 < 0x100000000) {
      iVar4 = (int)uVar5;
      uVar3 = iVar4 + 0x10;
      if (((0xf < uVar3) && (uVar3 < 0x10000)) && (iVar4 + 0x18U <= param_5)) {
        *(short *)(param_4 + 8) = (short)uVar3;
        param_4[10] = *(_TS_URB_RESULT *)(lVar1 + 0x22);
        param_4[0xb] = *(_TS_URB_RESULT *)(lVar1 + 0x23);
        *(undefined4 *)(param_4 + 0x14) = *(undefined4 *)(lVar1 + 0x30);
        param_4[0xc] = *(_TS_URB_RESULT *)(lVar1 + 0x24);
        param_4[0xd] = *(_TS_URB_RESULT *)(lVar1 + 0x25);
        param_4[0xe] = *(_TS_URB_RESULT *)(lVar1 + 0x26);
        *(undefined4 *)(param_4 + 0x14) = *(undefined4 *)(lVar1 + 0x30);
        lVar2 = CSimpleHash::AddItemDuplicateOk(param_2,*(void **)(lVar1 + 0x28),local_res8);
        if (-1 < lVar2) {
          if (local_res8[0] < 0x10000) {
            uVar3 = local_res8[0] | 0xffff0000;
          }
          else {
            uVar3 = 0;
          }
          *(uint *)(param_4 + 0x10) = uVar3;
          if (uVar3 != 0) {
            uVar5 = 0;
            if (*(int *)(lVar1 + 0x30) == 0) {
              return;
            }
            while( true ) {
              *(undefined2 *)(param_4 + uVar5 * 0x14 + 0x18) =
                   *(undefined2 *)(lVar1 + 0x38 + uVar5 * 0x18);
              param_4[uVar5 * 0x14 + 0x1a] = *(_TS_URB_RESULT *)(lVar1 + 0x3a + uVar5 * 0x18);
              param_4[uVar5 * 0x14 + 0x1b] = *(_TS_URB_RESULT *)(lVar1 + 0x3b + uVar5 * 0x18);
              *(undefined4 *)(param_4 + uVar5 * 0x14 + 0x1c) =
                   *(undefined4 *)(lVar1 + 0x3c + uVar5 * 0x18);
              *(undefined4 *)(param_4 + uVar5 * 0x14 + 0x24) =
                   *(undefined4 *)(lVar1 + 0x48 + uVar5 * 0x18);
              *(undefined4 *)(param_4 + uVar5 * 0x14 + 0x28) =
                   *(undefined4 *)(lVar1 + 0x4c + uVar5 * 0x18);
              lVar2 = CSimpleHash::AddItemDuplicateOk
                                (param_3,*(void **)(lVar1 + 0x40 + uVar5 * 0x18),local_res8);
              if (lVar2 < 0) break;
              if (local_res8[0] < 0x10000) {
                uVar3 = local_res8[0] | 0xffff0000;
              }
              else {
                uVar3 = 0;
              }
              *(uint *)(param_4 + uVar5 * 0x14 + 0x20) = uVar3;
              if (uVar3 == 0) break;
              uVar3 = (int)uVar5 + 1;
              uVar5 = (ulonglong)uVar3;
              if (*(uint *)(lVar1 + 0x30) <= uVar3) {
                return;
              }
            }
          }
        }
      }
    }
    *(undefined2 *)param_4 = 8;
    *(undefined4 *)(param_4 + 4) = 0x80000300;
  }
  return;
}



===== Feature_3771360570__private_IsEnabledDeviceUsageNoInline @ 14000670c =====

ulonglong Feature_3771360570__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_3771360570__private_featureState;
  if ((Feature_3771360570__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3771360570__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3771360570__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3771360570__private_IsEnabledFallback @ 140006744 =====

void Feature_3771360570__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 14000675c =====

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
LAB_14000695f:
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
LAB_140006837:
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
      if (param_3 == 4) goto LAB_14000695f;
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
        goto LAB_140006837;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140006a48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (undefined8 param_1,ulonglong param_2,uint param_3)

{
  bool bVar1;
  undefined7 extraout_var;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  byte bVar5;
  uint local_res18 [4];
  
  uVar4 = (uint)param_2 & 1;
  uVar3 = (ulonglong)param_3;
  if (param_3 != 0) {
    if (param_3 == 1) {
      uVar2 = (uVar4 ^ 1) << 2;
      uVar3 = 0;
      goto LAB_140006b0b;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_140006b0b;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_140006b0b;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_140006b0b;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_140006b0b;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_140006b0b;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_140006b0b;
    }
  }
  uVar2 = 0xff;
LAB_140006b0b:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3c56ce6,&Feature_3771360570_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140006b64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (undefined8 param_1,undefined8 param_2,uint param_3)

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
                     (local_50,&Feature_3771360570__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)(0x3c56ce6,param_3,1,&Feature_3771360570__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x3c56ce6);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 140006c50 =====

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
LAB_140006d03:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_140006d31;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140006d03;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_140006d31:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140006ebc =====

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
  if ((Feature_3771360570__private_featureState & 2) != 0) {
    uVar1 = Feature_3771360570__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_3771360570__private_featureState;
      if (bVar3) {
        Feature_3771360570__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_3771360570__private_featureState;
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



===== wil_details_IsEnabledFallback @ 140006f10 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_3771360570__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_3771360570__private_featureState,(ulonglong)param_1,
                             0x14000a080);
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



===== FxProbeAndLockForWrite @ 140006fa0 =====

undefined8 FxProbeAndLockForWrite(undefined8 param_1)

{
  MmProbeAndLockPages(param_1,1);
  return 0;
}



===== __security_check_cookie @ 140006fe0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140007020 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140007050 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140007050. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140007080 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memset @ 140007100 =====

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



===== __memset_repmovs @ 140007240 =====

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



===== __memset_query @ 1400072c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140007340 =====

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



===== __memset_spec_ermsb_repmovsb @ 140007480 =====

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



===== __memset_spec_plain @ 140007500 =====

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



===== memcmp @ 140007620 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140007663;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1400076d4;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1400076d0:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400076d4;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1400076cc:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400076d0;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400076cc;
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
LAB_1400076d4:
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
LAB_140007663:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140007740 =====

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



===== GdEvtDeviceAdd @ 14000e010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int GdEvtDeviceAdd(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  void *pvVar2;
  undefined2 uVar3;
  undefined1 auStack_128 [48];
  WDFDEVICE__ *local_f8;
  undefined8 local_f0;
  CGenericUSB *local_e8;
  ulonglong local_e0;
  code *local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined *local_b0;
  ulonglong local_a8;
  code *local_a0;
  undefined8 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined *local_78;
  undefined8 local_70;
  code *local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined8 local_44;
  undefined8 uStack_3c;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_128;
  local_68 = GdEvtDeviceFileCreate;
  local_e0 = (ulonglong)(uint)local_e0;
  local_d0 = 0;
  local_50 = 2;
  local_c0 = 0;
  uStack_b8 = 0;
  local_a8 = (ulonglong)(uint)local_a8;
  local_98 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_f8 = (WDFDEVICE__ *)0x0;
  local_70 = 0x28;
  local_60 = 0;
  local_58 = 0;
  local_4c = 4;
  local_e8 = (CGenericUSB *)0x0;
  local_f0 = param_2;
  (**(code **)(WdfFunctions_01015 + 0x238))(WdfDriverGlobals,param_2,&local_70,0);
  local_b0 = PTR__WDF_REQUEST_EXTENSION_TYPE_INFO_14000b018;
  local_d8 = GdEvtRequestContextCleanup;
  local_e0 = 0x38;
  local_d0 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_c8 = 1;
  local_c4 = 1;
  (**(code **)(WdfFunctions_01015 + 0x240))(WdfDriverGlobals,local_f0,&local_e0);
  local_78 = PTR__WDF_CGenericUSB_TYPE_INFO_14000b040;
  local_a0 = GdEvtDeviceContextCleanup;
  local_a8 = 0x38;
  local_98 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 3;
  local_8c = 4;
  (**(code **)(WdfFunctions_01015 + 0x250))(WdfDriverGlobals,local_f0,GdEvtIoDeviceControlInCaller);
  iVar1 = (**(code **)(WdfFunctions_01015 + 600))(WdfDriverGlobals,&local_f0,&local_a8,&local_f8);
  if (iVar1 < 0) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar1;
    }
    uVar3 = 0xc;
  }
  else {
    local_20 = 0xffffffff;
    local_1c = 0xffffffff;
    local_48 = 0x30;
    local_44 = 0x200000002;
    uStack_3c = 0x200000002;
    local_34 = 2;
    local_30 = 2;
    local_28 = 2;
    local_24 = 2;
    local_2c = 1;
    (**(code **)(WdfFunctions_01015 + 0x298))(WdfDriverGlobals,local_f8,&local_48);
    pvVar2 = (void *)(**(code **)(WdfFunctions_01015 + 0x650))
                               (WdfDriverGlobals,local_f8,PTR__WDF_CGenericUSB_TYPE_INFO_14000b040);
    iVar1 = CGenericUSB::CreateInstance(local_f8,pvVar2,&local_e8);
    if (-1 < iVar1) {
      return 0;
    }
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar1;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return iVar1;
    }
    uVar3 = 0xd;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_a05d6c7ad1f73f7679f73b096cc83d7c_Traceguids,iVar1);
  return iVar1;
}



===== GdEvtDeviceContextCleanup @ 14000e2d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GdEvtDeviceContextCleanup(undefined8 param_1)

{
  CGenericUSB *this;
  
  this = (CGenericUSB *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CGenericUSB_TYPE_INFO_14000b040);
  if (this != (CGenericUSB *)0x0) {
    CGenericUSB::~CGenericUSB(this);
  }
  return;
}



===== GdEvtDeviceFileCreate @ 14000e320 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GdEvtDeviceFileCreate(undefined8 param_1,WDFREQUEST__ *param_2,WDFFILEOBJECT__ *param_3)

{
  CGenericUSB *this;
  
  this = (CGenericUSB *)
         (**(code **)(WdfFunctions_01015 + 0x650))
                   (WdfDriverGlobals,param_1,PTR__WDF_CGenericUSB_TYPE_INFO_14000b040);
  CGenericUSB::EvtDeviceFileCreate(this,param_2,param_3);
  return;
}



===== GdEvtDriverUnload @ 14000e380 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void GdEvtDriverUnload(undefined8 param_1)

{
  undefined *puVar1;
  
  (**(code **)(WdfFunctions_01015 + 0x3b0))(WdfDriverGlobals,param_1);
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  g_wil_details_isFeatureStagingInitialized = 0;
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
  return;
}



===== WppInitKm @ 14000e464 =====

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



===== WppLoadTracingSupport @ 14000e4f4 =====

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



===== WppTraceCallback @ 14000e640 =====

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



===== wil_details_EvaluateFeatureDependencies @ 14000e8c8 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &wil_details_featureDescriptors_a;
  ppuVar2 = &wil_details_featureDescriptors_a;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x00014000e903;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_14000e97d:
  while( true ) {
    if (&UNK_14000a0b7 < ppuVar3) {
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
      if (&UNK_14000a0b7 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x00014000e903:
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
      if (&UNK_14000a0b7 < ppuVar2) goto LAB_14000e97d;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_14000e97d;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14000e9b8 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_14000ea54;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_14000ea54;
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
LAB_14000ea54:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14000eac0 =====

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
      for (ppuVar2 = &wil_details_featureDescriptors_a; ppuVar2 < &wil_details_featureDescriptors_z;
          ppuVar2 = ppuVar2 + 1) {
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
              if (&UNK_14000a0b7 < ppuVar2) {
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



===== wil_details_RecordFeatureUsageCallback @ 14000eb40 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14000eb60 =====

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
  for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
      ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_14000ec5d;
  }
LAB_14000ec66:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_14000ec5d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000ec66;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_14000ec2e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_14000ec2e;
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
    if (&UNK_14000a0b7 < ppuVar3) goto LAB_14000ec66;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000ec5d;
}



===== __security_init_cookie @ 14000f008 =====

void __cdecl __security_init_cookie(void)

{
  ulonglong uVar1;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    uVar1 = rdtsc();
    __security_cookie =
         ((CONCAT44((int)(__security_cookie >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000) ^
         0x14000b0c0) & 0xffffffffffff;
    if (__security_cookie == 0) {
      __security_cookie = 0x2b992ddfa232;
    }
  }
  __security_cookie_complement = ~__security_cookie;
  return;
}



===== DriverEntry @ 14000f070 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 local_res18;
  undefined8 local_28;
  code *local_20;
  code *local_18;
  undefined8 local_10;
  
  local_res18 = 0;
  wil_InitializeFeatureStaging();
  _WPP_MAIN_CB = 0;
  DAT_14000b1f8 = &WPP_ThisDir_CTLGUID_CtlGuid;
  DAT_14000b200 = 0;
  _DAT_14000b210 = 0;
  _DAT_14000b218 = 1;
  WppLoadTracingSupport();
  _DAT_14000b210 = 0;
  WppInitKm();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_a05d6c7ad1f73f7679f73b096cc83d7c_Traceguids);
  }
  local_28 = 0x20;
  local_20 = GdEvtDeviceAdd;
  local_18 = GdEvtDriverUnload;
  local_10 = 0;
  iVar1 = (**(code **)(WdfFunctions_01015 + 0x3a0))
                    (WdfDriverGlobals,param_1,param_2,0,&local_28,&local_res18);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_a05d6c7ad1f73f7679f73b096cc83d7c_Traceguids,iVar1);
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
  }
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 14000f1f4 =====

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
    for (ppuVar3 = &wil_details_featureDescriptors_a; ppuVar3 < &wil_details_featureDescriptors_z;
        ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_14000f27b;
    }
LAB_14000f2b5:
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
LAB_14000f27b:
  if (ppuVar3 == (undefined **)0x0) goto LAB_14000f2b5;
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
    goto LAB_14000f2b5;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000a0b7 < ppuVar3) goto LAB_14000f2b5;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_14000f27b;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14000f308 =====

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
  ppuVar4 = &wil_details_featureDescriptors_a;
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
            if (&UNK_14000a0b7 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14000f3f2;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14000f3f2;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14000f3f2:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14000a0b7 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


