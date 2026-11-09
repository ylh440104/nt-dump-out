
===== Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<4>_> @ 1c0001008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByRef<16>,struct _tlgWrapperByVal<4> >(struct _tlgProvider_t
   const * __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const *
   __ptr64,struct _tlgWrapperByRef<16> const & __ptr64,struct _tlgWrapperByVal<4> const & __ptr64)
    */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<4>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByRef<16> *param_5,_tlgWrapperByVal<4> *param_6)

{
  long lVar1;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [4];
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  _tlgWrapperByVal<4> *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_28 = param_6;
  local_20 = 4;
  local_1c = 0;
  local_38 = *(undefined8 *)param_5;
  local_2c = 0;
  local_30 = 0x10;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x1c001b0a0,param_2,0,0,4,local_58);
  return lVar1;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 1c0001094 =====

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



===== __report_gsfailure @ 1c0001150 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== implatAllocateNonPagedPoolWithTagPriority @ 1c0001160 =====

/* void * __ptr64 __cdecl implatAllocateNonPagedPoolWithTagPriority(unsigned __int64,unsigned
   long,enum _EX_POOL_PRIORITY) */

void * __cdecl
implatAllocateNonPagedPoolWithTagPriority(__uint64 param_1,ulong param_2,_EX_POOL_PRIORITY param_3)

{
  void *pvVar1;
  undefined8 local_18;
  ulonglong uStack_10;
  
  uStack_10 = (ulonglong)param_3;
  local_18 = 1;
  pvVar1 = (void *)ExAllocatePool3(0x40,param_1,0x6c506d49,&local_18,1);
  return pvVar1;
}



===== implatDecreaseGlobalPendingOperationsCount @ 1c00011a8 =====

/* void __cdecl implatDecreaseGlobalPendingOperationsCount(void) */

void __cdecl implatDecreaseGlobalPendingOperationsCount(void)

{
  implatWaitForMutex((_KMUTANT *)&DAT_1c001b1f0);
  DAT_1c001b228 = DAT_1c001b228 + -1;
  if (DAT_1c001b228 == 0) {
    KeSetEvent(&DAT_1c001b230,0,0);
  }
  KeReleaseMutex(&DAT_1c001b1f0,0);
  return;
}



===== implatDriverUnload @ 1c0001200 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl implatDriverUnload(struct _DRIVER_OBJECT * __ptr64) */

void __cdecl implatDriverUnload(_DRIVER_OBJECT *param_1)

{
  undefined8 uVar1;
  
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_186dd776e650347706de1e499c297719_Traceguids);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
              &WPP_9c22457c062d38ca085282eeaee3817b_Traceguids);
    }
  }
  if (DAT_1c001b288 != 0) {
    NdisDeregisterDeviceEx();
    DAT_1c001b288 = 0;
    _DAT_1c001b280 = 0;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
            &WPP_9c22457c062d38ca085282eeaee3817b_Traceguids);
  }
  if (_Global != 0) {
    NdisDeregisterProtocolDriver();
    _Global = 0;
  }
  if (DAT_1c001b1d8 != 0) {
    NdisMDeregisterMiniportDriver();
    DAT_1c001b1d8 = 0;
  }
  if (DAT_1c001b1e0 != 0) {
    NdisIfDeregisterProvider();
    DAT_1c001b1e0 = 0;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
            &WPP_186dd776e650347706de1e499c297719_Traceguids);
  }
  WppCleanupKm();
  uVar1 = DAT_1c001b0c0;
  DAT_1c001b0c0 = 0;
  DAT_1c001b0a0 = 0;
  EtwUnregister(uVar1);
  if ((DAT_1c001b290 & 4) != 0) {
    EtwUnregister(Microsoft_Windows_Networking_CorrelationHandle);
    Microsoft_Windows_Networking_CorrelationHandle = 0;
  }
  if ((DAT_1c001b290 & 2) != 0) {
    McGenEventUnregister_EtwUnregister((longlong *)&NdisImPlatformSysEvtProvider_Context);
  }
  if ((DAT_1c001b290 & 1) != 0) {
    McGenEventUnregister_EtwUnregister(&NdisImPlatformEventProvider_Context);
  }
  return;
}



===== implatIncreaseGlobalPendingOperationsCount @ 1c00013d4 =====

/* void __cdecl implatIncreaseGlobalPendingOperationsCount(void) */

void __cdecl implatIncreaseGlobalPendingOperationsCount(void)

{
  implatWaitForMutex((_KMUTANT *)&DAT_1c001b1f0);
  DAT_1c001b228 = DAT_1c001b228 + 1;
  KeClearEvent(&DAT_1c001b230);
  KeReleaseMutex(&DAT_1c001b1f0,0);
  return;
}



===== implatWaitForGlobalMutexAndPendingOperationsCount @ 1c0001420 =====

/* void __cdecl implatWaitForGlobalMutexAndPendingOperationsCount(void) */

void __cdecl implatWaitForGlobalMutexAndPendingOperationsCount(void)

{
  while( true ) {
    implatWaitForMutex((_KMUTANT *)&DAT_1c001b1f0);
    if (DAT_1c001b228 == 0) break;
    KeReleaseMutex(&DAT_1c001b1f0,0);
    KeWaitForSingleObject(&DAT_1c001b230,0,0,0,0);
  }
  return;
}



===== implatWaitForMutex @ 1c0001480 =====

/* void __cdecl implatWaitForMutex(struct _KMUTANT * __ptr64) */

void __cdecl implatWaitForMutex(_KMUTANT *param_1)

{
  KeWaitForSingleObject(param_1,0,0,0,0);
  return;
}



===== McGenControlCallbackV2 @ 1c00014b0 =====

void McGenControlCallbackV2
               (undefined8 param_1,int param_2,undefined1 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,longlong param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  if (param_7 != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(param_7 + 0x24) = 0;
      *(undefined1 *)(param_7 + 0x28) = 0;
      *(undefined8 *)(param_7 + 0x10) = 0;
      *(undefined8 *)(param_7 + 0x18) = 0;
      if (*(ushort *)(param_7 + 0x2a) != 0) {
        iVar4 = *(ushort *)(param_7 + 0x2a) - 1;
        memset(*(void **)(param_7 + 0x30),0,
               (longlong)(((int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5) + 1) << 2);
      }
    }
    else if (param_2 == 1) {
      *(undefined1 *)(param_7 + 0x28) = param_3;
      uVar7 = 0;
      *(undefined8 *)(param_7 + 0x18) = param_5;
      *(undefined8 *)(param_7 + 0x10) = param_4;
      *(undefined4 *)(param_7 + 0x24) = 1;
      if (*(short *)(param_7 + 0x2a) != 0) {
        do {
          uVar2 = *(ulonglong *)(*(longlong *)(param_7 + 0x38) + uVar7 * 8);
          if (((*(byte *)(param_7 + 0x28) < *(byte *)(uVar7 + *(longlong *)(param_7 + 0x40))) &&
              (*(byte *)(param_7 + 0x28) != 0)) ||
             ((uVar2 != 0 &&
              (((*(ulonglong *)(param_7 + 0x10) & uVar2) == 0 ||
               ((*(ulonglong *)(param_7 + 0x18) & uVar2) != *(ulonglong *)(param_7 + 0x18))))))) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          uVar5 = 1 << ((byte)uVar7 & 0x1f);
          puVar1 = (uint *)(*(longlong *)(param_7 + 0x30) + (uVar7 >> 5) * 4);
          uVar6 = *puVar1;
          if (bVar3) {
            uVar5 = uVar5 | uVar6;
          }
          else {
            uVar5 = ~uVar5 & uVar6;
          }
          *puVar1 = uVar5;
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
        } while (uVar6 < *(ushort *)(param_7 + 0x2a));
      }
    }
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 1c00015c0 =====

void McGenEventRegister_EtwRegister
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  if (*param_4 == 0) {
    EtwRegister(param_1,McGenControlCallbackV2);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 1c00015ec =====

undefined8 McGenEventUnregister_EtwUnregister(longlong *param_1)

{
  undefined8 uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    *param_1 = 0;
  }
  return uVar1;
}



===== WPP_SF_ @ 1c0001620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 1c000164c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c0001690 =====

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



===== _tlgDefineProvider_annotation__Tlgg_hTraceLogNdisImPlatSysProviderProv @ 1c00016c4 =====

void _tlgDefineProvider_annotation__Tlgg_hTraceLogNdisImPlatSysProviderProv(void)

{
  return;
}



===== implatControlDeviceIOCTLDispatch @ 1c00016d0 =====

/* long __cdecl implatControlDeviceIOCTLDispatch(struct _DEVICE_OBJECT * __ptr64,struct _IRP *
   __ptr64) */

long __cdecl implatControlDeviceIOCTLDispatch(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  bool bVar4;
  long lVar5;
  int iVar6;
  _IMPLAT_TEAM *p_Var7;
  _GUID *p_Var8;
  uint uVar9;
  undefined *in_R8;
  uint uVar10;
  uchar *puVar11;
  ulong uVar12;
  ulong local_res10 [2];
  ulong local_res18 [4];
  
  uVar9 = 0;
  lVar5 = 0;
  local_res10[0] = 0;
  uVar10 = 0;
  local_res18[0] = 0;
  bVar4 = false;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    in_R8 = &WPP_9c22457c062d38ca085282eeaee3817b_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_9c22457c062d38ca085282eeaee3817b_Traceguids,param_2);
  }
  lVar3 = *(longlong *)(param_2 + 0xb8);
  p_Var8 = *(_GUID **)(param_2 + 0x18);
  uVar1 = *(uint *)(lVar3 + 0x10);
  uVar2 = *(uint *)(lVar3 + 8);
  if (*(int *)(lVar3 + 0x18) == 0x125c04) {
    if ((p_Var8 != (_GUID *)0x0) && (0xf < uVar1)) {
      implatWaitForMutex((_KMUTANT *)&DAT_1c001b1f0);
      in_R8 = (undefined *)0x0;
      p_Var7 = implatFindTeamByGuid(p_Var8,'\0','\0');
      if (p_Var7 == (_IMPLAT_TEAM *)0x0) {
        KeReleaseMutex(&DAT_1c001b1f0,0);
        lVar5 = -0x3ffffddb;
      }
      else {
        in_R8 = (undefined *)(ulonglong)uVar2;
        iVar6 = implatHandleQueryTeamState
                          (p_Var7,(_IMPLAT_TEAM_CURRENT_STATE *)p_Var8,uVar2,local_res10,local_res18
                          );
        lVar5 = NdisConvertNdisStatusToNtStatus(iVar6);
        KeReleaseMutex(&DAT_1c001b1f0,0);
        uVar9 = local_res10[0];
        uVar10 = local_res18[0];
      }
      goto LAB_1c00018d0;
    }
  }
  else {
    if (*(int *)(lVar3 + 0x18) != 0x12dc00) {
      lVar5 = -0x3fffff45;
      goto LAB_1c00018d0;
    }
    if ((p_Var8 != (_GUID *)0x0) && (0x27 < uVar1)) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        in_R8 = &WPP_9c22457c062d38ca085282eeaee3817b_Traceguids;
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                 &WPP_9c22457c062d38ca085282eeaee3817b_Traceguids,param_2);
      }
      implatWaitForGlobalMutexAndPendingOperationsCount();
      puVar11 = p_Var8->Data4 + ((ulonglong)uVar1 - 8);
      if (p_Var8[2].Data4 <= puVar11) {
        do {
          uVar12 = (int)puVar11 - (int)p_Var8;
          lVar5 = implatControlDeviceProcessConfigurationChange
                            ((_IMPLAT_CONFIGURATION_CHANGE *)p_Var8,uVar12);
          if (lVar5 == -0x3ffffddb) {
            bVar4 = true;
            lVar5 = 0;
          }
          else if (lVar5 < 0) goto LAB_1c0001811;
          uVar1._0_2_ = p_Var8->Data2;
          uVar1._2_2_ = p_Var8->Data3;
          if (uVar12 <= uVar1) {
            lVar5 = -0x3fdcffec;
            goto LAB_1c0001811;
          }
        } while ((uVar1 != 0) &&
                (p_Var8 = (_GUID *)(p_Var8->Data4 + ((ulonglong)uVar1 - 8)),
                p_Var8[2].Data4 <= puVar11));
        if (bVar4) {
          lVar5 = -0x3ffffddb;
        }
      }
LAB_1c0001811:
      KeReleaseMutex(&DAT_1c001b1f0,0);
      goto LAB_1c00018d0;
    }
  }
  lVar5 = -0x3fdcffec;
LAB_1c00018d0:
  *(long *)(param_2 + 0x30) = lVar5;
  if (lVar5 != -0x3fffffdd) {
    uVar10 = uVar9;
  }
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar10;
  IofCompleteRequest(param_2,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,in_R8,param_2,(char)lVar5);
  }
  return lVar5;
}



===== implatControlDeviceProcessConfigurationChange @ 1c000194c =====

/* long __cdecl implatControlDeviceProcessConfigurationChange(struct _IMPLAT_CONFIGURATION_CHANGE *
   __ptr64,unsigned long) */

long __cdecl
implatControlDeviceProcessConfigurationChange(_IMPLAT_CONFIGURATION_CHANGE *param_1,ulong param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  _IMPLAT_VIRTMINI *p_Var5;
  _IMPLAT_ADAPTER *p_Var6;
  undefined2 uVar7;
  undefined4 in_register_00000014;
  uint uVar8;
  undefined *in_R8;
  ushort local_18 [4];
  _IMPLAT_CONFIGURATION_CHANGE *p_Stack_10;
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  p_Stack_10 = (_IMPLAT_CONFIGURATION_CHANGE *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),CONCAT44(in_register_00000014,param_2),
               in_R8,param_1,(char)*(undefined4 *)(param_1 + 8),
               (char)*(undefined4 *)(param_1 + 0x1c));
  }
  if (((*param_1 != (_IMPLAT_CONFIGURATION_CHANGE)0x80) ||
      (param_1[1] != (_IMPLAT_CONFIGURATION_CHANGE)0x1)) || (*(short *)(param_1 + 2) != 0x28)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_9c22457c062d38ca085282eeaee3817b_Traceguids,param_1);
    }
    return -0x3ffffff3;
  }
  if (*(int *)(param_1 + 8) == 2) {
    for (p_Var6 = DAT_1c001b248; p_Var6 != (_IMPLAT_ADAPTER *)&DAT_1c001b248;
        p_Var6 = *(_IMPLAT_ADAPTER **)p_Var6) {
      if ((*(longlong *)(p_Var6 + 0xb4) == *(longlong *)(param_1 + 0xc)) &&
         (*(longlong *)(p_Var6 + 0xbc) == *(longlong *)(param_1 + 0x14))) {
        if (p_Var6 != (_IMPLAT_ADAPTER *)0x0) {
          if (*(int *)(param_1 + 0x1c) != 0) {
            if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) == 0)) ||
               ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c0001a0e;
            uVar7 = 0x14;
            goto LAB_1c00019fb;
          }
          uVar2 = *(uint *)(param_1 + 0x20);
          uVar1 = *(ushort *)(param_1 + 0x24);
          uVar8 = uVar1 + uVar2;
          in_R8 = (undefined *)(ulonglong)uVar8;
          if (((uVar8 < uVar2) || (param_2 < uVar8)) || ((uVar1 & 1) != 0)) goto LAB_1c0001af1;
          p_Stack_10 = param_1 + uVar2;
          local_18[1] = uVar1;
          local_18[0] = uVar1;
          iVar3 = implatCheckAdapterInternalBindings(p_Var6,(_UNICODE_STRING *)local_18);
          lVar4 = NdisConvertNdisStatusToNtStatus(iVar3);
          goto LAB_1c0001b60;
        }
        break;
      }
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar7 = 0x13;
LAB_1c0001b48:
      in_R8 = &WPP_9c22457c062d38ca085282eeaee3817b_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
               &WPP_9c22457c062d38ca085282eeaee3817b_Traceguids,param_1);
    }
  }
  else {
    if (*(int *)(param_1 + 8) != 3) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar7 = 0x17;
LAB_1c00019fb:
        in_R8 = &WPP_9c22457c062d38ca085282eeaee3817b_Traceguids;
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
                 &WPP_9c22457c062d38ca085282eeaee3817b_Traceguids,param_1);
      }
LAB_1c0001a0e:
      lVar4 = -0x3fffff45;
      goto LAB_1c0001b60;
    }
    uVar2 = *(uint *)(param_1 + 0xc);
    uVar1 = *(ushort *)(param_1 + 0x10);
    if (((uVar1 + uVar2 < uVar2) || (param_2 < uVar1 + uVar2)) || ((uVar1 & 1) != 0)) {
LAB_1c0001af1:
      lVar4 = -0x3fdcffec;
      goto LAB_1c0001b60;
    }
    p_Stack_10 = param_1 + uVar2;
    local_18[1] = uVar1;
    local_18[0] = uVar1;
    in_R8 = (undefined *)0x0;
    p_Var5 = implatFindVirtMiniByName
                       ((_LIST_ENTRY *)&DAT_1c001b258,(_UNICODE_STRING *)local_18,'\0',
                        (_IMPLAT_TEAM *)0x0);
    lVar4 = 0;
    if (p_Var5 != (_IMPLAT_VIRTMINI *)0x0) {
      if (*(int *)(param_1 + 0x1c) == 1) {
        *(undefined4 *)(p_Var5 + 0x78) = *(undefined4 *)(param_1 + 0x20);
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          in_R8 = &WPP_9c22457c062d38ca085282eeaee3817b_Traceguids;
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                   &WPP_9c22457c062d38ca085282eeaee3817b_Traceguids,param_1);
        }
        lVar4 = -0x3fffff45;
      }
      implatDereferenceVirtualMiniport
                (p_Var5,(ushort *)L"ProcessConfigurationChange reverting find");
      goto LAB_1c0001b60;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar7 = 0x15;
      goto LAB_1c0001b48;
    }
  }
  lVar4 = -0x3ffffddb;
LAB_1c0001b60:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xb & 1) != 0)) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,in_R8,param_1,(char)lVar4);
  }
  return lVar4;
}



===== implatControlDeviceRegister @ 1c0001c80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* int __cdecl implatControlDeviceRegister(void) */

int __cdecl implatControlDeviceRegister(void)

{
  int iVar1;
  undefined1 auStack_188 [32];
  ulonglong local_168;
  undefined8 *local_160;
  undefined8 *local_158;
  code **local_150;
  ulonglong local_148;
  undefined8 *local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  code *local_f8 [2];
  code *local_e8;
  code *local_88;
  code *local_68;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_188;
  local_168 = (ulonglong)(uint)local_168;
  local_148 = (ulonglong)(uint)local_148;
  local_130 = 0;
  uStack_128 = 0;
  local_120 = 0;
  uStack_118 = 0;
  local_110 = 0;
  uStack_108 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_9c22457c062d38ca085282eeaee3817b_Traceguids);
  }
  memset(local_f8,0,0xe0);
  local_f8[0] = implatDummyIrpHandler;
  local_e8 = implatDummyIrpHandler;
  local_68 = implatDummyIrpHandler;
  local_88 = implatControlDeviceIOCTLDispatch;
  RtlInitUnicodeString(&local_130,L"\\Device\\NdisImPlatformControl");
  RtlInitUnicodeString(&local_120,L"\\DosDevices\\Global\\NdisImPlatformControl");
  RtlInitUnicodeString(&local_110,L"D:P(A;;GA;;;SY)(A;;GA;;;NS)(A;;GA;;;BA)(A;;GR;;;WD)");
  local_160 = &local_130;
  local_158 = &local_120;
  local_168 = 0x380185;
  local_150 = local_f8;
  local_148 = 0;
  local_140 = &local_110;
  local_138 = 0;
  iVar1 = NdisRegisterDeviceEx(DAT_1c001b1d8,&local_168,&DAT_1c001b280,&DAT_1c001b288);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x800) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
     ) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_9c22457c062d38ca085282eeaee3817b_Traceguids,iVar1);
  }
  return iVar1;
}



===== implatDummyIrpHandler @ 1c0001e30 =====

/* long __cdecl implatDummyIrpHandler(struct _DEVICE_OBJECT * __ptr64,struct _IRP * __ptr64) */

long __cdecl implatDummyIrpHandler(_DEVICE_OBJECT *param_1,_IRP *param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== WPP_SF_q @ 1c0001e58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== WPP_SF_qD @ 1c0001e9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9c22457c062d38ca085282eeaee3817b_Traceguids,param_2,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_qLL @ 1c0001ef4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9c22457c062d38ca085282eeaee3817b_Traceguids,0x11,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== implatAddAdapterToTeam @ 1c0001f5c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* int __cdecl implatAddAdapterToTeam(struct _IMPLAT_TEAM * __ptr64,struct _IMPLAT_ADAPTER *
   __ptr64) */

int __cdecl implatAddAdapterToTeam(_IMPLAT_TEAM *param_1,_IMPLAT_ADAPTER *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  wchar_t *pwVar3;
  code *pcVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 *puVar7;
  _IMPLAT_TEAM *p_Var8;
  longlong lVar9;
  uint uVar10;
  ulonglong uVar11;
  _IMPLAT_ADAPTER *p_Var12;
  undefined1 *puVar13;
  undefined *puVar14;
  undefined1 auStackY_b8 [8];
  undefined1 auStackY_b0 [24];
  undefined2 local_88;
  undefined1 uStack_86;
  undefined4 auStack_84 [3];
  undefined1 local_78 [32];
  _IMPLAT_TEAM *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  _IMPLAT_ADAPTER *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  puVar13 = auStackY_b8;
  local_28 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_88 = 0;
  uStack_86 = 0;
  if (*(longlong *)(param_2 + 0x28) == 0) {
    IPsecLbfoOffloadMapWaitForIdleAndAcquireExclusiveTeamLock((longlong)param_1,&local_88);
    lVar9 = *(longlong *)(param_1 + 0x438);
    if ((lVar9 != 0) && (uVar11 = 0, *(int *)(lVar9 + 0x10) != 0)) {
      do {
        if (*(char *)(uVar11 * 0x610 + *(longlong *)(lVar9 + 0x18)) != '\0') {
          *(undefined1 *)(uVar11 * 0x610 + 1 + *(longlong *)(lVar9 + 0x18)) = 1;
        }
        uVar10 = (int)uVar11 + 1;
        uVar11 = (ulonglong)uVar10;
      } while (uVar10 < *(uint *)(lVar9 + 0x10));
    }
    LOCK();
    p_Var8 = param_1 + 0x80;
    iVar5 = *(int *)p_Var8;
    *(int *)p_Var8 = *(int *)p_Var8 + 1;
    UNLOCK();
    puVar14 = (undefined *)(ulonglong)(iVar5 + 1U);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar14 = &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids;
      WPP_SF_qdS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                 &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids,param_1,(char)(iVar5 + 1U),
                 L"AddAdapterToTeam");
    }
    puVar13 = auStackY_b8;
    p_Var8 = param_1 + 0xf0;
    if (*(_IMPLAT_TEAM **)p_Var8 == p_Var8) {
      *(undefined4 *)(param_1 + 0xe9) = *(undefined4 *)(param_2 + 0x60);
      *(undefined2 *)(param_1 + 0xed) = *(undefined2 *)(param_2 + 100);
    }
    *(_IMPLAT_TEAM **)(param_2 + 0x28) = param_1;
    p_Var12 = param_2 + 0x10;
    *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + 1;
    puVar7 = *(undefined8 **)(param_1 + 0xf8);
    if ((_IMPLAT_TEAM *)*puVar7 != p_Var8) {
      p_Var8 = (_IMPLAT_TEAM *)0x3;
      pcVar4 = (code *)swi(0x29);
      puVar7 = (undefined8 *)(*pcVar4)();
      puVar13 = auStackY_b0;
    }
    *(_IMPLAT_TEAM **)p_Var12 = p_Var8;
    *(undefined8 **)(p_Var12 + 8) = puVar7;
    *puVar7 = p_Var12;
    *(_IMPLAT_ADAPTER **)(p_Var8 + 8) = p_Var12;
    uVar2 = *(undefined8 *)(param_1 + 0x88);
    *(undefined8 *)(puVar13 + -8) = 0x1c0002099;
    NdisReleaseRWLock(uVar2,&local_88);
    uVar6 = *(undefined4 *)(param_2 + 0xa0);
    uVar1 = *(undefined4 *)(param_1 + 200);
    *(undefined8 *)(puVar13 + -8) = 0x1c00020b1;
    uVar6 = NdisIfAddIfStackEntry(uVar1,uVar6);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0)) &&
       (3 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      puVar14 = &WPP_4c7e1387f9ea3c086637b58d47ad9570_Traceguids;
      *(undefined8 *)(puVar13 + -8) = 0x1c00020eb;
      WPP_SF_q(uVar2,0x13,&WPP_4c7e1387f9ea3c086637b58d47ad9570_Traceguids,param_2);
    }
    lVar9 = *(longlong *)(param_2 + 0x28);
    if (*(longlong *)(lVar9 + 0x438) != 0) {
      *(undefined8 *)(puVar13 + -8) = 0x1c00020fe;
      IPsecLbfopSignalUploadOfExistingSAs(lVar9);
    }
    if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
      uVar2 = *(undefined8 *)(param_2 + 0x58);
      pwVar3 = *(wchar_t **)(param_1 + 0x28);
      *(undefined4 *)(puVar13 + 0x28) = uVar6;
      *(undefined8 *)(puVar13 + 0x20) = uVar2;
      *(undefined8 *)(puVar13 + -8) = 0x1c0002124;
      McTemplateK0zzd_EtwWriteTransfer
                (lVar9,&AddedMemberInfo,puVar14,pwVar3,*(wchar_t **)(puVar13 + 0x20),puVar13[0x28]);
    }
    if (5 < DAT_1c001b0a0) {
      local_2c = 0;
      local_48 = param_2 + 0xb4;
      local_3c = 0;
      local_58 = param_1 + 0x10;
      local_4c = 0;
      local_38 = auStack_84;
      local_40 = 0x10;
      local_50 = 0x10;
      *(undefined1 **)(puVar13 + 0x28) = local_78;
      *(undefined4 *)(puVar13 + 0x20) = 5;
      auStack_84[0] = uVar6;
      local_30 = 4;
      *(undefined8 *)(puVar13 + -8) = 0x1c0002193;
      _tlgWriteTransfer_EtwWriteTransfer
                (0x1c001b0a0,&DAT_1c00190d3,0,0,*(undefined4 *)(puVar13 + 0x20),
                 *(undefined8 **)(puVar13 + 0x28));
    }
    iVar5 = 0;
  }
  else {
    iVar5 = -0x3fffffff;
  }
  *(undefined8 *)(puVar13 + -8) = 0x1c00021a1;
  return iVar5;
}



===== implatAddVirtMiniToTeam @ 1c00021c0 =====

/* int __cdecl implatAddVirtMiniToTeam(struct _IMPLAT_TEAM * __ptr64,struct _IMPLAT_VIRTMINI *
   __ptr64) */

int __cdecl implatAddVirtMiniToTeam(_IMPLAT_TEAM *param_1,_IMPLAT_VIRTMINI *param_2)

{
  undefined1 *puVar1;
  undefined8 uVar2;
  wchar_t *pwVar3;
  code *pcVar4;
  int iVar5;
  _IMPLAT_VIRTMINI *p_Var6;
  _IMPLAT_TEAM *p_Var7;
  undefined8 uVar8;
  longlong *plVar9;
  undefined1 *puVar10;
  undefined *puVar11;
  undefined2 local_res10;
  undefined1 local_res12;
  undefined1 auStackY_38 [8];
  undefined1 auStackY_30 [24];
  
  local_res10 = 0;
  local_res12 = 0;
  if (*(longlong *)(param_2 + 0x48) == 0) {
    IPsecLbfoOffloadMapWaitForIdleAndAcquireExclusiveTeamLock((longlong)param_1,&local_res10);
    LOCK();
    p_Var7 = param_1 + 0x80;
    iVar5 = *(int *)p_Var7;
    *(int *)p_Var7 = *(int *)p_Var7 + 1;
    UNLOCK();
    puVar11 = (undefined *)(ulonglong)(iVar5 + 1U);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      puVar11 = &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids;
      WPP_SF_qdS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                 &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids,param_1,(char)(iVar5 + 1U),
                 L"AddVirtMiniToTeam");
    }
    puVar10 = auStackY_38;
    p_Var7 = param_1 + 0x100;
    *(_IMPLAT_TEAM **)(param_2 + 0x48) = param_1;
    plVar9 = *(longlong **)(param_1 + 0x108);
    p_Var6 = param_2 + 0x10;
    if ((_IMPLAT_TEAM *)*plVar9 != p_Var7) {
      p_Var7 = (_IMPLAT_TEAM *)0x3;
      pcVar4 = (code *)swi(0x29);
      p_Var6 = (_IMPLAT_VIRTMINI *)(*pcVar4)();
      puVar10 = auStackY_30;
    }
    *(_IMPLAT_TEAM **)p_Var6 = p_Var7;
    *(longlong **)(p_Var6 + 8) = plVar9;
    *plVar9 = (longlong)p_Var6;
    *(_IMPLAT_VIRTMINI **)(p_Var7 + 8) = p_Var6;
    *(int *)(param_1 + 0x114) = *(int *)(param_1 + 0x114) + 1;
    if (*(int *)(param_1 + 0x114) == 2) {
      puVar1 = *(undefined1 **)(param_1 + 0x438);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
        puVar11 = &WPP_4c7e1387f9ea3c086637b58d47ad9570_Traceguids;
        *(undefined8 *)(puVar10 + -8) = 0x1c00022d1;
        WPP_SF_q(uVar8,10,&WPP_4c7e1387f9ea3c086637b58d47ad9570_Traceguids,param_1);
      }
      if (puVar1 != (undefined1 *)0x0) {
        *puVar1 = 0;
        uVar8 = *(undefined8 *)(param_1 + 0x88);
        *(undefined8 *)(puVar10 + -8) = 0x1c00022ec;
        NdisReleaseRWLock(uVar8,puVar10 + 0x48);
        *(undefined8 *)(puVar10 + -8) = 0x1c00022f9;
        IPsecLbfopDisableTOv2((longlong)param_1);
        uVar8 = *(undefined8 *)(param_1 + 0x88);
        puVar11 = (undefined *)0x0;
        *(undefined8 *)(puVar10 + -8) = 0x1c000230f;
        NdisAcquireRWLockWrite(uVar8,puVar10 + 0x48);
      }
    }
    uVar8 = *(undefined8 *)(param_1 + 0x88);
    *(undefined8 *)(puVar10 + -8) = 0x1c0002327;
    NdisReleaseRWLock(uVar8,puVar10 + 0x48);
    if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
      uVar2 = *(undefined8 *)(param_2 + 0x30);
      *(undefined4 *)(puVar10 + 0x28) = 0;
      pwVar3 = *(wchar_t **)(param_1 + 0x28);
      *(undefined8 *)(puVar10 + 0x20) = uVar2;
      *(undefined8 *)(puVar10 + -8) = 0x1c0002353;
      McTemplateK0zzd_EtwWriteTransfer
                (uVar8,&AddedTeamNicInfo,puVar11,pwVar3,*(wchar_t **)(puVar10 + 0x20),puVar10[0x28])
      ;
    }
    iVar5 = 0;
  }
  else {
    iVar5 = -0x3fffffff;
  }
  return iVar5;
}



===== implatCreateTeam @ 1c0002374 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* int __cdecl implatCreateTeam(struct _IMPLAT_TEAM * __ptr64 * __ptr64,struct _GUID * __ptr64) */

int __cdecl implatCreateTeam(_IMPLAT_TEAM **param_1,_GUID *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  _IMPLAT_TEAM *p_Var6;
  undefined8 uVar7;
  _GUID *p_Var8;
  _IMPLAT_TEAM *p_Var9;
  _tlgProvider_t *p_Var10;
  undefined2 uVar11;
  ulong uVar12;
  undefined8 *puVar13;
  uchar auVar14 [8];
  undefined1 *puVar15;
  _GUID *p_Var16;
  uchar in_R9 [8];
  undefined1 auStackY_388 [8];
  undefined1 auStackY_380 [24];
  uint local_358 [2];
  longlong local_350;
  _GUID *local_348;
  undefined8 local_340;
  undefined8 local_338;
  _GUID local_330;
  undefined8 local_318;
  undefined8 uStack_310;
  undefined8 local_308;
  _GUID local_300;
  undefined8 local_2f0;
  wchar_t *local_2e8;
  undefined8 local_2e0;
  wchar_t *local_2d8;
  undefined8 local_2d0;
  wchar_t *local_2c8;
  ulonglong local_2c0;
  void *pvStack_2b8;
  _GUID *local_2b0;
  undefined8 local_2a8;
  undefined8 local_2a0;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_290;
  undefined8 local_28c;
  undefined4 local_284;
  undefined1 local_280;
  undefined4 local_27e;
  undefined2 local_27a;
  undefined2 local_278;
  undefined2 local_276;
  undefined4 local_274;
  undefined4 uStack_270;
  ulong uStack_26c;
  undefined4 uStack_268;
  undefined8 local_254;
  undefined4 local_24c;
  undefined1 local_248 [528];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_388;
  local_2f0 = 0xa0008;
  local_308 = 0;
  local_358[0] = 0;
  local_338 = 0;
  local_350 = 0;
  local_2e0 = 0x140012;
  local_2e8 = L"Name";
  local_2d0 = 0xe000c;
  local_2d8 = L"IfNetLuid";
  local_300.Data1 = 0xc000a;
  local_300.Data2 = 0;
  local_300.Data3 = 0;
  local_2c8 = L"IfGuid";
  local_340 = 0;
  p_Var16 = (_GUID *)0x268;
  local_300.Data4 = (uchar  [8])0x1c0018750;
  local_318 = 0;
  uStack_310 = 0;
  local_348 = (_GUID *)0x0;
  memset(&local_2a8,0,0x268);
  local_2c0 = 0;
  pvStack_2b8 = (void *)0x0;
  local_330.Data1 = 0;
  local_330.Data2 = 0;
  local_330.Data3 = 0;
  local_330.Data4[0] = '\0';
  local_330.Data4[1] = '\0';
  local_330.Data4[2] = '\0';
  local_330.Data4[3] = '\0';
  local_330.Data4[4] = '\0';
  local_330.Data4[5] = '\0';
  local_330.Data4[6] = '\0';
  local_330.Data4[7] = '\0';
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    in_R9 = (uchar  [8])param_2;
    WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,p_Var16,param_2);
  }
  uVar12 = (ulong)&local_330;
  *param_1 = (_IMPLAT_TEAM *)0x0;
  p_Var8 = param_2;
  uVar5 = RtlStringFromGUID();
  if ((int)uVar5 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      p_Var16 = (_GUID *)&WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids;
      in_R9[4] = '\0';
      in_R9[5] = '\0';
      in_R9[6] = '\0';
      in_R9[7] = '\0';
      in_R9[0] = (char)uVar5;
      in_R9[1] = (char)(uVar5 >> 8);
      in_R9[2] = (char)(uVar5 >> 0x10);
      in_R9[3] = (char)(uVar5 >> 0x18);
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids,uVar5);
    }
    local_358[0] = 0xc0000001;
    puVar15 = auStackY_388;
    goto LAB_1c0002b87;
  }
  if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
    uVar12 = 0xc00181d8;
    in_R9 = local_330.Data4;
    McTemplateK0zq_EtwWriteTransfer
              (p_Var8,&CreatingTeamInfo,p_Var16,(wchar_t *)local_330.Data4,(char)local_358[0]);
  }
  p_Var16 = (_GUID *)0x10;
  p_Var6 = implatAllocateNonPagedPoolWithTagPriority(0x578,uVar12,0x10);
  *param_1 = p_Var6;
  if (p_Var6 == (_IMPLAT_TEAM *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      uVar11 = 0xc;
LAB_1c0002629:
      p_Var16 = (_GUID *)&WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
              &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids);
    }
LAB_1c0002639:
    local_358[0] = 0xc000009a;
    puVar15 = auStackY_388;
  }
  else {
    p_Var16 = (_GUID *)0x578;
    memset(p_Var6,0,0x578);
    p_Var6 = *param_1;
    uVar2 = *(undefined4 *)&param_2->Data2;
    uVar3 = *(undefined4 *)param_2->Data4;
    uVar4 = *(undefined4 *)(param_2->Data4 + 4);
    *(ulong *)(p_Var6 + 0x10) = param_2->Data1;
    *(undefined4 *)(p_Var6 + 0x14) = uVar2;
    *(undefined4 *)(p_Var6 + 0x18) = uVar3;
    *(undefined4 *)(p_Var6 + 0x1c) = uVar4;
    *(_IMPLAT_TEAM **)(*param_1 + 0x28) = *param_1 + 0x30;
    *(undefined2 *)(*param_1 + 0x22) = 0x4e;
    RtlCopyUnicodeString(*param_1 + 0x20,&local_330);
    p_Var6 = *param_1 + 0xf0;
    *(_IMPLAT_TEAM **)(*param_1 + 0xf8) = p_Var6;
    *(_IMPLAT_TEAM **)p_Var6 = p_Var6;
    p_Var6 = *param_1 + 0x100;
    *(_IMPLAT_TEAM **)(*param_1 + 0x108) = p_Var6;
    *(_IMPLAT_TEAM **)p_Var6 = p_Var6;
    p_Var6 = *param_1 + 0x4a8;
    *(_IMPLAT_TEAM **)(*param_1 + 0x4b0) = p_Var6;
    *(_IMPLAT_TEAM **)p_Var6 = p_Var6;
    p_Var6 = *param_1 + 0x498;
    *(_IMPLAT_TEAM **)(*param_1 + 0x4a0) = p_Var6;
    *(_IMPLAT_TEAM **)p_Var6 = p_Var6;
    (*param_1)[0x550] = (_IMPLAT_TEAM)0x80;
    (*param_1)[0x551] = (_IMPLAT_TEAM)0x1;
    *(undefined2 *)(*param_1 + 0x552) = 0x28;
    uVar7 = NdisAllocateRWLock(_Global);
    *(undefined8 *)(*param_1 + 0x88) = uVar7;
    if (*(longlong *)(*param_1 + 0x88) == 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar11 = 0xd;
        goto LAB_1c0002629;
      }
      goto LAB_1c0002639;
    }
    KeInitializeMutex(*param_1 + 0x118,0xffff);
    KeInitializeMutex(*param_1 + 0x90,0xffff);
    uStack_310 = _Global;
    local_318 = 0x1401a9;
    local_308 = 0;
    local_358[0] = NdisOpenConfigurationEx(&local_318,&local_338);
    in_R9[4] = '\0';
    in_R9[5] = '\0';
    in_R9[6] = '\0';
    in_R9[7] = '\0';
    in_R9[0] = (char)local_358[0];
    in_R9[1] = (char)(local_358[0] >> 8);
    in_R9[2] = (char)(local_358[0] >> 0x10);
    in_R9[3] = (char)(local_358[0] >> 0x18);
    if (local_358[0] == 0) {
      p_Var16 = &local_300;
      NdisOpenConfigurationKeyByName(local_358,local_338,p_Var16,&local_340);
      in_R9[4] = '\0';
      in_R9[5] = '\0';
      in_R9[6] = '\0';
      in_R9[7] = '\0';
      in_R9[0] = (undefined1)local_358[0];
      in_R9[1] = local_358[0]._1_1_;
      in_R9[2] = local_358[0]._2_1_;
      in_R9[3] = local_358[0]._3_1_;
      if (local_358[0] == 0) {
        p_Var16 = &local_330;
        NdisOpenConfigurationKeyByName(local_358,local_340,p_Var16,&local_348);
        in_R9[4] = '\0';
        in_R9[5] = '\0';
        in_R9[6] = '\0';
        in_R9[7] = '\0';
        in_R9[0] = (undefined1)local_358[0];
        in_R9[1] = local_358[0]._1_1_;
        in_R9[2] = local_358[0]._2_1_;
        in_R9[3] = local_358[0]._3_1_;
        if (local_358[0] == 0) {
          p_Var16 = local_348;
          NdisReadConfiguration(local_358,&local_350,local_348,&local_2f0);
          in_R9[4] = '\0';
          in_R9[5] = '\0';
          in_R9[6] = '\0';
          in_R9[7] = '\0';
          in_R9[0] = (undefined1)local_358[0];
          in_R9[1] = local_358[0]._1_1_;
          in_R9[2] = local_358[0]._2_1_;
          in_R9[3] = local_358[0]._3_1_;
          if (local_358[0] == 0) {
            RtlInitUnicodeString(&local_2c0,*(undefined8 *)(local_350 + 0x10));
            if ((ushort)local_2c0 < 0x201) {
              p_Var16 = local_348;
              NdisReadConfiguration(local_358,&local_350,local_348,&local_2e0);
              in_R9[4] = '\0';
              in_R9[5] = '\0';
              in_R9[6] = '\0';
              in_R9[7] = '\0';
              in_R9[0] = (undefined1)local_358[0];
              in_R9[1] = local_358[0]._1_1_;
              in_R9[2] = local_358[0]._2_1_;
              in_R9[3] = local_358[0]._3_1_;
              if (local_358[0] == 0) {
                if (*(ushort *)(local_350 + 8) < 8) {
                  local_358[0] = 0xc000000d;
                  puVar15 = auStackY_388;
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      (puVar15 = auStackY_388, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0))
                     && (puVar15 = auStackY_388, 1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    uVar11 = 0x14;
                    goto LAB_1c000285d;
                  }
                }
                else {
                  *(undefined8 *)(*param_1 + 0xd0) = **(undefined8 **)(local_350 + 0x10);
                  p_Var16 = local_348;
                  NdisReadConfiguration(local_358,&local_350,local_348,&local_2d0);
                  in_R9[4] = '\0';
                  in_R9[5] = '\0';
                  in_R9[6] = '\0';
                  in_R9[7] = '\0';
                  in_R9[0] = (undefined1)local_358[0];
                  in_R9[1] = local_358[0]._1_1_;
                  in_R9[2] = local_358[0]._2_1_;
                  in_R9[3] = local_358[0]._3_1_;
                  if (local_358[0] == 0) {
                    if (*(ushort *)(local_350 + 8) < 0x10) {
                      local_358[0] = 0xc000000d;
                      puVar15 = auStackY_388;
                      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                          (puVar15 = auStackY_388,
                          (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
                         (puVar15 = auStackY_388, 1 < (byte)WPP_GLOBAL_Control[0x29])) {
                        uVar11 = 0x16;
                        goto LAB_1c000285d;
                      }
                    }
                    else {
                      p_Var6 = *param_1;
                      uVar7 = (*(undefined8 **)(local_350 + 0x10))[1];
                      *(undefined8 *)(p_Var6 + 0xd8) = **(undefined8 **)(local_350 + 0x10);
                      *(undefined8 *)(p_Var6 + 0xe0) = uVar7;
                      uVar11 = (ushort)local_2c0;
                      memcpy(local_248,pvStack_2b8,local_2c0 & 0xffff);
                      p_Var16 = (_GUID *)*param_1;
                      local_294 = 0xffffffff;
                      local_276 = 0x60;
                      local_27a = 0x260;
                      local_2a8 = 0x600180;
                      local_2a0 = 0;
                      local_298 = 0;
                      local_290 = 0;
                      local_28c = 2;
                      local_284 = 1;
                      local_280 = 0;
                      local_27e = 0x2600006;
                      local_278 = uVar11;
                      local_274 = *(undefined4 *)p_Var16[0xd].Data4;
                      uStack_270 = *(undefined4 *)(p_Var16[0xd].Data4 + 4);
                      uStack_26c = p_Var16[0xe].Data1;
                      uStack_268._0_2_ = p_Var16[0xe].Data2;
                      uStack_268._2_2_ = p_Var16[0xe].Data3;
                      local_254 = 0x3f87ff;
                      local_24c = 0xe;
                      uVar7._0_4_ = p_Var16[0xd].Data1;
                      uVar7._4_2_ = p_Var16[0xd].Data2;
                      uVar7._6_2_ = p_Var16[0xd].Data3;
                      local_358[0] = NdisIfRegisterInterface(DAT_1c001b1e0,uVar7,p_Var16,&local_2a8)
                      ;
                      in_R9[4] = '\0';
                      in_R9[5] = '\0';
                      in_R9[6] = '\0';
                      in_R9[7] = '\0';
                      in_R9[0] = (char)local_358[0];
                      in_R9[1] = (char)(local_358[0] >> 8);
                      in_R9[2] = (char)(local_358[0] >> 0x10);
                      in_R9[3] = (char)(local_358[0] >> 0x18);
                      if (local_358[0] == 0) {
                        in_R9 = (uchar  [8])*param_1;
                        LOCK();
                        p_Var16 = (_GUID *)((longlong)in_R9 + 0x80);
                        uVar12 = p_Var16->Data1;
                        p_Var16->Data1 = p_Var16->Data1 + 1;
                        UNLOCK();
                        uVar5 = uVar12 + 1;
                        p_Var16 = (_GUID *)(ulonglong)uVar5;
                        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
                           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
                          p_Var16 = (_GUID *)&WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids;
                          WPP_SF_qdS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                                     &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids,in_R9,
                                     (char)uVar5,L"CreateTeam");
                        }
                        puVar15 = auStackY_388;
                        puVar13 = &DAT_1c001b268;
                        p_Var6 = *param_1;
                        p_Var9 = DAT_1c001b270;
                        if (*(undefined8 **)DAT_1c001b270 != &DAT_1c001b268) {
                          p_Var9 = (_IMPLAT_TEAM *)0x3;
                          pcVar1 = (code *)swi(0x29);
                          p_Var6 = (_IMPLAT_TEAM *)(*pcVar1)();
                          puVar15 = auStackY_380;
                        }
                        *(_IMPLAT_TEAM **)(p_Var6 + 8) = p_Var9;
                        *(undefined8 **)p_Var6 = puVar13;
                        *(_IMPLAT_TEAM **)p_Var9 = p_Var6;
                        p_Var9 = *param_1;
                        *(undefined8 *)(puVar15 + -8) = 0x1c0002b66;
                        DAT_1c001b270 = p_Var6;
                        implatInitAllStandardizedKeywords
                                  ((_IMPLAT_STANDARDIZED_KEYWORD *)(p_Var9 + 0x178));
                        (*param_1)[0x158] = (_IMPLAT_TEAM)0xa8;
                        *(undefined2 *)(*param_1 + 0x15a) = 0x1c;
                        (*param_1)[0x159] = (_IMPLAT_TEAM)0x1;
                      }
                      else {
                        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
                           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                          p_Var16 = (_GUID *)&WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids;
                          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                                   &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids,local_358[0]);
                        }
                        puVar15 = auStackY_388;
                        *(undefined4 *)(*param_1 + 200) = 0;
                      }
                    }
                  }
                  else {
                    puVar15 = auStackY_388;
                    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        (puVar15 = auStackY_388, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)
                        ) && (puVar15 = auStackY_388, 1 < (byte)WPP_GLOBAL_Control[0x29])) {
                      uVar11 = 0x15;
                      goto LAB_1c00026e0;
                    }
                  }
                }
              }
              else {
                puVar15 = auStackY_388;
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    (puVar15 = auStackY_388, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
                   (puVar15 = auStackY_388, 1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  uVar11 = 0x13;
                  goto LAB_1c00026e0;
                }
              }
            }
            else {
              local_358[0] = 0xc000000d;
              puVar15 = auStackY_388;
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  (puVar15 = auStackY_388, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
                 (puVar15 = auStackY_388, 1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar11 = 0x12;
LAB_1c000285d:
                local_358[0] = 0xc000000d;
                p_Var16 = (_GUID *)&WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids;
                WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
                        &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids);
                puVar15 = auStackY_388;
              }
            }
          }
          else {
            puVar15 = auStackY_388;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (puVar15 = auStackY_388, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
               (puVar15 = auStackY_388, 1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar11 = 0x11;
              goto LAB_1c00026e0;
            }
          }
        }
        else {
          puVar15 = auStackY_388;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (puVar15 = auStackY_388, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
             (puVar15 = auStackY_388, 1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar11 = 0x10;
            goto LAB_1c00026e0;
          }
        }
      }
      else {
        puVar15 = auStackY_388;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (puVar15 = auStackY_388, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
           (puVar15 = auStackY_388, 1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar11 = 0xf;
          goto LAB_1c00026e0;
        }
      }
    }
    else {
      puVar15 = auStackY_388;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (puVar15 = auStackY_388, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (puVar15 = auStackY_388, 1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar11 = 0xe;
LAB_1c00026e0:
        p_Var16 = (_GUID *)&WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
                 &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids,in_R9._0_4_);
        puVar15 = auStackY_388;
      }
    }
  }
LAB_1c0002b87:
  if (*(longlong *)(puVar15 + 0x40) != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x1c0002b98;
    NdisCloseConfiguration();
    *(undefined8 *)(puVar15 + 0x40) = 0;
  }
  if (*(longlong *)(puVar15 + 0x48) != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x1c0002bb3;
    NdisCloseConfiguration();
    *(undefined8 *)(puVar15 + 0x48) = 0;
  }
  p_Var6 = *(_IMPLAT_TEAM **)(puVar15 + 0x50);
  if (p_Var6 != (_IMPLAT_TEAM *)0x0) {
    *(undefined8 *)(puVar15 + -8) = 0x1c0002bce;
    NdisCloseConfiguration();
    *(undefined8 *)(puVar15 + 0x50) = 0;
  }
  if (*(int *)(puVar15 + 0x30) != 0) {
    if (*param_1 != (_IMPLAT_TEAM *)0x0) {
      if (*(int *)(*param_1 + 200) != 0) {
        *(undefined8 *)(puVar15 + -8) = 0x1c0002bfc;
        NdisIfDeregisterInterface();
        *(undefined4 *)(*param_1 + 200) = 0;
      }
      if (*(longlong *)(*param_1 + 0x88) != 0) {
        *(undefined8 *)(puVar15 + -8) = 0x1c0002c21;
        NdisFreeRWLock();
        *(undefined8 *)(*param_1 + 0x88) = 0;
      }
      p_Var6 = *param_1;
      *(undefined8 *)(puVar15 + -8) = 0x1c0002c3f;
      ExFreePoolWithTag(p_Var6,0x6c506d49);
      *param_1 = (_IMPLAT_TEAM *)0x0;
    }
    auVar14 = *(uchar (*) [8])(puVar15 + 0x60);
    if (auVar14 == (uchar  [8])0x0) goto LAB_1c0002c9d;
    if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 4) != 0) {
      *(undefined4 *)(puVar15 + 0x20) = *(undefined4 *)(puVar15 + 0x30);
      *(undefined8 *)(puVar15 + -8) = 0x1c0002c71;
      in_R9 = auVar14;
      McTemplateK0zq_EtwWriteTransfer
                (p_Var6,&CreatingTeamFailedErr,p_Var16,(wchar_t *)auVar14,puVar15[0x20]);
      auVar14 = *(uchar (*) [8])(puVar15 + 0x60);
    }
    p_Var16 = (_GUID *)(ulonglong)*(uint *)(puVar15 + 0x30);
    *(undefined8 *)(puVar15 + -8) = 0x1c0002c85;
    SysEventWriteStrStatus(-0x7fffbd9f,(ushort *)auVar14,*(uint *)(puVar15 + 0x30));
  }
  if (*(longlong *)(puVar15 + 0x60) != 0) {
    *(undefined8 *)(puVar15 + -8) = 0x1c0002c98;
    RtlFreeUnicodeString(puVar15 + 0x58);
  }
LAB_1c0002c9d:
  p_Var10 = (_tlgProvider_t *)WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    p_Var10 = *(_tlgProvider_t **)(WPP_GLOBAL_Control + 0x18);
    *(_GUID **)(puVar15 + 0x20) = param_2;
    *(undefined8 *)(puVar15 + -8) = 0x1c0002ccd;
    WPP_SF_q_guid_(p_Var10,0x18,p_Var16,param_1,*(undefined8 *)(puVar15 + 0x20));
    in_R9 = (uchar  [8])param_1;
  }
  if (5 < DAT_1c001b0a0) {
    *(undefined4 *)(puVar15 + 0x68) = *(undefined4 *)(puVar15 + 0x30);
    *(undefined1 **)(puVar15 + 0x28) = puVar15 + 0x68;
    *(_GUID ***)(puVar15 + 0x20) = &local_2b0;
    *(undefined8 *)(puVar15 + -8) = 0x1c0002d01;
    local_2b0 = param_2;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<4>_>
              (p_Var10,&DAT_1c001904b,p_Var16,(_GUID *)in_R9,
               *(_tlgWrapperByRef<16> **)(puVar15 + 0x20),*(_tlgWrapperByVal<4> **)(puVar15 + 0x28))
    ;
  }
  *(undefined8 *)(puVar15 + -8) = 0x1c0002d14;
  return *(int *)(puVar15 + 0x30);
}



===== implatFindTeamByGuid @ 1c0002d38 =====

/* struct _IMPLAT_TEAM * __ptr64 __cdecl implatFindTeamByGuid(struct _GUID * __ptr64,unsigned
   char,unsigned char) */

_IMPLAT_TEAM * __cdecl implatFindTeamByGuid(_GUID *param_1,uchar param_2,uchar param_3)

{
  _IMPLAT_TEAM *p_Var1;
  longlong lVar2;
  int iVar3;
  _IMPLAT_TEAM *p_Var4;
  _IMPLAT_TEAM *p_Var5;
  undefined **ppuVar6;
  _IMPLAT_TEAM *local_res20;
  
  local_res20 = (_IMPLAT_TEAM *)0x0;
  p_Var5 = (_IMPLAT_TEAM *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF__guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,&WPP_GLOBAL_Control,param_1);
  }
  p_Var4 = DAT_1c001b268;
  do {
    if (p_Var4 == (_IMPLAT_TEAM *)&DAT_1c001b268) {
LAB_1c0002e44:
      ppuVar6 = &WPP_GLOBAL_Control;
      if ((param_2 != '\0') && (iVar3 = implatCreateTeam(&local_res20,param_1), iVar3 == 0)) {
        p_Var5 = local_res20;
      }
LAB_1c0002e5e:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_q_guid_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,ppuVar6,p_Var5,param_1);
      }
      return p_Var5;
    }
    lVar2._0_4_ = param_1->Data1;
    lVar2._4_2_ = param_1->Data2;
    lVar2._6_2_ = param_1->Data3;
    local_res20 = p_Var4;
    if ((lVar2 == *(longlong *)(p_Var4 + 0x10)) &&
       (*(longlong *)param_1->Data4 == *(longlong *)(p_Var4 + 0x18))) {
      if (param_3 != '\0') {
        LOCK();
        p_Var1 = p_Var4 + 0x80;
        iVar3 = *(int *)p_Var1;
        *(int *)p_Var1 = *(int *)p_Var1 + 1;
        UNLOCK();
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qdS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
                     &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids,p_Var4,(char)(iVar3 + 1),
                     L"FindTeamByGuid");
        }
        if (iVar3 + 1 == 1) goto LAB_1c0002e29;
      }
      ppuVar6 = &WPP_GLOBAL_Control;
      p_Var5 = local_res20;
      if (local_res20 != (_IMPLAT_TEAM *)0x0) goto LAB_1c0002e5e;
      goto LAB_1c0002e44;
    }
LAB_1c0002e29:
    p_Var4 = *(_IMPLAT_TEAM **)p_Var4;
  } while( true );
}



===== implatRecalculateTeamOffloadCapabilities @ 1c0002eb8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* int __cdecl implatRecalculateTeamOffloadCapabilities(struct _IMPLAT_TEAM * __ptr64,struct
   _LOCK_STATE_EX * __ptr64) */

int __cdecl implatRecalculateTeamOffloadCapabilities(_IMPLAT_TEAM *param_1,_LOCK_STATE_EX *param_2)

{
  _IMPLAT_TEAM _Var1;
  bool bVar2;
  int iVar3;
  _IMPLAT_TEAM *p_Var4;
  _IMPLAT_TEAM *p_Var5;
  uint *puVar6;
  byte bVar7;
  _IMPLAT_TEAM *p_Var8;
  longlong lVar9;
  longlong lVar10;
  int iVar11;
  _IMPLAT_TEAM a_Stack_480 [320];
  undefined8 uStack_340;
  undefined1 auStack_338 [32];
  _LOCK_STATE_EX *local_318;
  undefined4 local_308;
  wchar_t *local_300;
  undefined4 local_2f8;
  undefined4 local_2f4;
  uint local_2f0 [4];
  wchar_t *local_2e0;
  undefined4 local_2d8;
  undefined4 local_2d4;
  undefined4 local_2d0;
  undefined4 local_2c8;
  wchar_t *local_2c0;
  undefined4 local_2b8;
  undefined4 local_2b4;
  undefined4 local_2b0;
  undefined4 local_2a8;
  wchar_t *local_2a0;
  undefined4 local_298;
  undefined4 local_294;
  undefined4 local_290;
  undefined4 local_288;
  wchar_t *local_280;
  undefined4 local_278;
  undefined4 local_274;
  undefined4 local_270;
  undefined4 local_268;
  wchar_t *local_260;
  undefined4 local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined4 local_248;
  wchar_t *local_240;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_228;
  wchar_t *local_220;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_208;
  wchar_t *local_200;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1e8;
  wchar_t *local_1e0;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1c8;
  wchar_t *local_1c0;
  undefined4 local_1b8;
  undefined4 local_1b4;
  int local_1b0;
  undefined4 local_1a8;
  wchar_t *local_1a0;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_188;
  wchar_t *local_180;
  undefined4 local_178;
  undefined8 local_174;
  undefined4 local_168;
  wchar_t *local_160;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_148;
  wchar_t *local_140;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_128;
  wchar_t *local_120;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_108;
  wchar_t *local_100;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_e8;
  wchar_t *local_e0;
  undefined4 local_d8;
  undefined8 local_d4;
  undefined4 local_c8;
  wchar_t *local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_a8;
  wchar_t *local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_88;
  wchar_t *local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_68;
  wchar_t *local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_338;
  local_318 = param_2;
  local_308 = 0x2e002c;
  local_300 = L"*IPChecksumOffloadIPv4";
  local_2f8 = 0;
  local_2e0 = L"*TCPChecksumOffloadIPv4";
  local_2f4 = 3;
  local_2f0[0] = 3;
  local_2c0 = L"*TCPChecksumOffloadIPv6";
  lVar9 = 0xc;
  local_2f0[2] = 0x30002e;
  local_2a0 = L"*UDPChecksumOffloadIPv4";
  local_2d8 = 0;
  local_280 = L"*UDPChecksumOffloadIPv6";
  local_260 = L"*LsoV2IPv4";
  local_240 = L"*LsoV2IPv6";
  local_220 = L"*IPsecOffloadV2";
  local_200 = L"*RscIPv4";
  local_1e0 = L"*RscIPv6";
  local_1c0 = L"*EncapsulatedPacketTaskOffload";
  local_1a0 = L"*HeaderDataSplit";
  local_2d4 = 3;
  local_2d0 = 3;
  local_2c8 = 0x30002e;
  local_2b8 = 0;
  local_2b4 = 3;
  local_2b0 = 3;
  local_2a8 = 0x30002e;
  local_298 = 0;
  local_294 = 3;
  local_290 = 3;
  local_288 = 0x30002e;
  local_278 = 0;
  local_274 = 3;
  local_270 = 3;
  local_268 = 0x160014;
  local_258 = 0;
  local_254 = 1;
  local_250 = 1;
  local_248 = 0x160014;
  local_238 = 0;
  local_234 = 1;
  local_230 = 1;
  local_228 = 0x20001e;
  local_218 = 0;
  local_214 = 3;
  local_210 = 3;
  local_208 = 0x120010;
  local_1f8 = 0;
  local_1f4 = 1;
  local_1f0 = 1;
  local_1e8 = 0x120010;
  local_1d8 = 0;
  local_1d4 = 1;
  local_1d0 = 1;
  local_1c8 = 0x3e003c;
  local_1b8 = 0;
  local_1b4 = 1;
  local_1b0 = 1;
  local_1a8 = 0x220020;
  local_198 = 0;
  local_194 = 1;
  local_190 = 1;
  local_188 = 0xe000c;
  local_180 = L"VlanID";
  p_Var4 = *(_IMPLAT_TEAM **)(param_1 + 0x100);
  local_160 = L"*VMQ";
  local_140 = L"*VMQLookaheadSplit";
  local_120 = L"*VMQVlanFiltering";
  local_100 = L"*RSS";
  local_e0 = L"DefaultNicInTeam";
  local_c0 = L"*WakeOnPattern";
  local_a0 = L"*WakeOnMagicPacket";
  local_80 = L"*ARPOffload";
  local_154 = 1;
  bVar7 = 0;
  local_150 = 1;
  bVar2 = false;
  local_134 = 1;
  local_130 = 1;
  local_114 = 1;
  local_110 = 1;
  local_f4 = 1;
  local_f0 = 1;
  local_d4 = 1;
  local_b4 = 1;
  local_b0 = 1;
  local_94 = 1;
  local_90 = 1;
  local_74 = 1;
  local_70 = 1;
  local_54 = 1;
  local_50 = 1;
  iVar3 = 0;
  local_60 = L"*NSOffload";
  local_178 = 0;
  local_174 = 0xffe;
  local_168 = 0xa0008;
  local_158 = 0;
  local_148 = 0x260024;
  local_138 = 0;
  local_128 = 0x240022;
  local_118 = 0;
  local_108 = 0xa0008;
  local_f8 = 0;
  local_e8 = 0x220020;
  local_d8 = 0;
  local_c8 = 0x1e001c;
  local_b8 = 0;
  local_a8 = 0x260024;
  local_98 = 0;
  local_88 = 0x180016;
  local_78 = 0;
  local_68 = 0x160014;
  local_58 = 0;
  if (p_Var4 != param_1 + 0x100) {
    do {
      if (1 < *(int *)(p_Var4 + 0xb8)) {
        lVar10 = 0xc;
        puVar6 = local_2f0;
        do {
          *puVar6 = *puVar6 & *(uint *)(p_Var4 + (0x458 - (longlong)local_2f0) + (longlong)puVar6);
          puVar6 = puVar6 + 8;
          lVar10 = lVar10 + -1;
        } while (lVar10 != 0);
        bVar7 = bVar7 | (byte)p_Var4[0x8e4] & 1;
      }
      p_Var4 = *(_IMPLAT_TEAM **)p_Var4;
    } while (p_Var4 != param_1 + 0x100);
    bVar7 = bVar7 & -(local_1b0 != 0);
  }
  p_Var4 = param_1 + 400;
  do {
    if (*(int *)(p_Var4 + (longlong)(a_Stack_480 + -(longlong)param_1)) != *(int *)p_Var4) {
      bVar2 = true;
      *(int *)p_Var4 = *(int *)(p_Var4 + (longlong)(a_Stack_480 + -(longlong)param_1));
    }
    p_Var4 = p_Var4 + 0x20;
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  _Var1 = param_1[0xe8];
  if (bVar7 == ((byte)_Var1 & 1)) {
    if (!bVar2) {
      return 0;
    }
  }
  else {
    param_1[0xe8] = (_IMPLAT_TEAM)(((byte)_Var1 ^ bVar7) & 1 ^ (byte)_Var1);
  }
  p_Var4 = param_1 + 0xf0;
  bVar2 = false;
  p_Var8 = *(_IMPLAT_TEAM **)p_Var4;
  iVar11 = iVar3;
  if (p_Var8 != p_Var4) {
    do {
      uStack_340 = 0x1c0003338;
      NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x88),local_318);
      uStack_340 = 0x1c0003346;
      iVar3 = implatCheckAdapterOffloadParameters((_IMPLAT_ADAPTER *)(p_Var8 + -0x10));
      uStack_340 = 0x1c000335f;
      NdisAcquireRWLockWrite(*(undefined8 *)(param_1 + 0x88),local_318,0);
      if (iVar3 == 0) {
        if (!bVar2) {
          for (p_Var5 = *(_IMPLAT_TEAM **)p_Var4; p_Var5 != p_Var4;
              p_Var5 = *(_IMPLAT_TEAM **)p_Var5) {
            if (p_Var5[0xe9] != (_IMPLAT_TEAM)0x0) {
              uStack_340 = 0x1c0003387;
              NdisUnbindAdapter(*(longlong *)(p_Var5 + 0x10));
            }
          }
        }
        bVar2 = true;
      }
      else if (bVar2) {
        uStack_340 = 0x1c00033b1;
        NdisUnbindAdapter(*(longlong *)(p_Var8 + 0x10));
        iVar3 = iVar11;
      }
      else {
        p_Var8[0xe9] = (_IMPLAT_TEAM)0x1;
      }
      p_Var8 = *(_IMPLAT_TEAM **)p_Var8;
      iVar11 = iVar3;
    } while (p_Var8 != p_Var4);
    if (bVar2) goto LAB_1c00033ff;
  }
  for (p_Var4 = *(_IMPLAT_TEAM **)(param_1 + 0xf0); p_Var4 != param_1 + 0xf0;
      p_Var4 = *(_IMPLAT_TEAM **)p_Var4) {
    p_Var4[0xe9] = (_IMPLAT_TEAM)0x0;
  }
LAB_1c00033ff:
  for (p_Var4 = *(_IMPLAT_TEAM **)(param_1 + 0x100); p_Var4 != param_1 + 0x100;
      p_Var4 = *(_IMPLAT_TEAM **)p_Var4) {
    uStack_340 = 0x1c0003418;
    implatTaskOffloadRecalculateAndIndicateChange((_IMPLAT_VIRTMINI *)(p_Var4 + -0x10));
  }
  return iVar3;
}



===== implatRemoveAdapterFromTeam @ 1c0003454 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl implatRemoveAdapterFromTeam(struct _IMPLAT_ADAPTER * __ptr64) */

void __cdecl implatRemoveAdapterFromTeam(_IMPLAT_ADAPTER *param_1)

{
  _IMPLAT_TEAM *p_Var1;
  int iVar2;
  _IMPLAT_TEAM *p_Var3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  _IMPLAT_ADAPTER *p_Var7;
  undefined8 in_R8;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [4];
  longlong local_38;
  undefined4 local_30;
  undefined4 local_2c;
  _IMPLAT_ADAPTER *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  p_Var3 = *(_IMPLAT_TEAM **)(param_1 + 0x28);
  if (p_Var3 != (_IMPLAT_TEAM *)0x0) {
    p_Var7 = param_1;
    if (*(longlong *)(param_1 + 0x20) != 0) {
      implatUpdateTeamRscStatsDelta(param_1);
    }
    if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
      McTemplateK0zzd_EtwWriteTransfer
                (p_Var7,&RemovedMemberInfo,in_R8,*(wchar_t **)(*(longlong *)(param_1 + 0x28) + 0x28)
                 ,*(wchar_t **)(param_1 + 0x58),0);
    }
    if (5 < DAT_1c001b0a0) {
      local_28 = param_1 + 0xb4;
      local_1c = 0;
      local_2c = 0;
      local_38 = *(longlong *)(param_1 + 0x28) + 0x10;
      local_20 = 0x10;
      local_30 = 0x10;
      _tlgWriteTransfer_EtwWriteTransfer(0x1c001b0a0,&DAT_1c0019085,0,0,4,local_58);
    }
    NdisIfDeleteIfStackEntry(*(undefined4 *)(p_Var3 + 200),*(undefined4 *)(param_1 + 0xa0));
    *(undefined8 *)(param_1 + 0x28) = 0;
    p_Var7 = param_1 + 0x10;
    *(int *)(p_Var3 + 0x110) = *(int *)(p_Var3 + 0x110) + -1;
    lVar4 = *(longlong *)p_Var7;
    if ((*(_IMPLAT_ADAPTER **)(lVar4 + 8) != p_Var7) ||
       (plVar5 = *(longlong **)(param_1 + 0x18), (_IMPLAT_ADAPTER *)*plVar5 != p_Var7)) {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    *plVar5 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar5;
    LOCK();
    p_Var1 = p_Var3 + 0x80;
    iVar2 = *(int *)p_Var1;
    *(int *)p_Var1 = *(int *)p_Var1 + -1;
    UNLOCK();
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qdS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                 &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids,p_Var3,(char)(iVar2 + -1),
                 L"RemoveAdapterFromTeam");
    }
    if (iVar2 + -1 == 0) {
      implatRemoveTeam(p_Var3);
    }
  }
  return;
}



===== implatRemoveTeam @ 1c00035f4 =====

/* void __cdecl implatRemoveTeam(struct _IMPLAT_TEAM * __ptr64) */

void __cdecl implatRemoveTeam(_IMPLAT_TEAM *param_1)

{
  longlong lVar1;
  code *pcVar2;
  _tlgProvider_t *p_Var3;
  longlong lVar4;
  longlong *plVar5;
  _GUID *in_R8;
  _GUID *in_R9;
  undefined4 local_res8 [2];
  _IMPLAT_TEAM *local_res10;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    in_R8 = (_GUID *)&WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids;
    in_R9 = (_GUID *)param_1;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
             &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids,param_1);
  }
  lVar1 = *(longlong *)param_1;
  plVar5 = *(longlong **)(param_1 + 8);
  if ((*(_IMPLAT_TEAM **)(lVar1 + 8) != param_1) || ((_IMPLAT_TEAM *)*plVar5 != param_1)) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(3);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  *plVar5 = lVar1;
  *(longlong **)(lVar1 + 8) = plVar5;
  lVar1 = *(longlong *)(param_1 + 0x438);
  if (lVar1 != 0) {
    ExFreePoolWithTag(*(undefined8 *)(lVar1 + 0x18),0);
    plVar5 = (longlong *)(lVar1 + 0x28);
    lVar4 = 0x40;
    do {
      if (*plVar5 != 0) {
        ExFreePoolWithTag(*plVar5,0);
      }
      plVar5 = plVar5 + 7;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    ExFreePoolWithTag(lVar1,0);
    *(undefined8 *)(param_1 + 0x438) = 0;
  }
  if (*(int *)(param_1 + 200) != 0) {
    NdisIfDeregisterInterface();
    *(undefined4 *)(param_1 + 200) = 0;
  }
  p_Var3 = *(_tlgProvider_t **)(param_1 + 0x88);
  if (p_Var3 != (_tlgProvider_t *)0x0) {
    NdisFreeRWLock();
    *(undefined8 *)(param_1 + 0x88) = 0;
  }
  if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
    in_R9 = *(_GUID **)(param_1 + 0x28);
    McTemplateK0zq_EtwWriteTransfer(p_Var3,&RemovedTeamInfo,in_R8,(wchar_t *)in_R9,0);
  }
  if (5 < DAT_1c001b0a0) {
    local_res8[0] = 0;
    local_res10 = param_1 + 0x10;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<4>_>
              (p_Var3,&DAT_1c0019011,in_R8,in_R9,(_tlgWrapperByRef<16> *)&local_res10,
               (_tlgWrapperByVal<4> *)local_res8);
  }
  NdisFreeMemory(param_1,*(ushort *)(param_1 + 0x22) + 0x57a,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
            &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids);
  }
  return;
}



===== implatRemoveVirtMiniFromTeam @ 1c00037c0 =====

/* void __cdecl implatRemoveVirtMiniFromTeam(struct _IMPLAT_VIRTMINI * __ptr64) */

void __cdecl implatRemoveVirtMiniFromTeam(_IMPLAT_VIRTMINI *param_1)

{
  _IMPLAT_VIRTMINI *p_Var1;
  _IMPLAT_TEAM *p_Var2;
  int iVar3;
  _IMPLAT_TEAM *p_Var4;
  longlong lVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  code *pcVar8;
  undefined8 in_R8;
  undefined2 local_res8;
  undefined1 local_resa;
  
  p_Var4 = *(_IMPLAT_TEAM **)(param_1 + 0x48);
  local_res8 = 0;
  local_resa = 0;
  if (p_Var4 != (_IMPLAT_TEAM *)0x0) {
    if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
      McTemplateK0zzd_EtwWriteTransfer
                (param_1,&RemovedTeamNicInfo,in_R8,*(wchar_t **)(p_Var4 + 0x28),
                 *(wchar_t **)(param_1 + 0x30),0);
    }
    IPsecLbfoOffloadMapWaitForIdleAndAcquireExclusiveTeamLock((longlong)p_Var4,&local_res8);
    *(undefined8 *)(param_1 + 0x48) = 0;
    p_Var1 = param_1 + 0x10;
    lVar5 = *(longlong *)p_Var1;
    if ((*(_IMPLAT_VIRTMINI **)(lVar5 + 8) != p_Var1) ||
       (plVar6 = *(longlong **)(param_1 + 0x18), (_IMPLAT_VIRTMINI *)*plVar6 != p_Var1)) {
      pcVar8 = (code *)swi(0x29);
      (*pcVar8)(3);
      pcVar8 = (code *)swi(3);
      (*pcVar8)();
      return;
    }
    *plVar6 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar6;
    *(int *)(p_Var4 + 0x114) = *(int *)(p_Var4 + 0x114) + -1;
    if (*(int *)(p_Var4 + 0x114) == 1) {
      puVar7 = *(undefined1 **)(p_Var4 + 0x438);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0)) &&
         (3 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_4c7e1387f9ea3c086637b58d47ad9570_Traceguids,p_Var4);
      }
      if (puVar7 != (undefined1 *)0x0) {
        *puVar7 = 1;
        NdisReleaseRWLock(*(undefined8 *)(p_Var4 + 0x88),&local_res8);
        IPsecLbfopEnableTOv2((longlong)p_Var4);
        NdisAcquireRWLockWrite(*(undefined8 *)(p_Var4 + 0x88),&local_res8,0);
      }
    }
    NdisReleaseRWLock(*(undefined8 *)(p_Var4 + 0x88),&local_res8);
    LOCK();
    p_Var2 = p_Var4 + 0x80;
    iVar3 = *(int *)p_Var2;
    *(int *)p_Var2 = *(int *)p_Var2 + -1;
    UNLOCK();
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qdS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                 &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids,p_Var4,(char)(iVar3 + -1),
                 L"RemoveVirtMiniFromTeam");
    }
    if (iVar3 + -1 == 0) {
      implatRemoveTeam(p_Var4);
    }
  }
  return;
}



===== implatTeamQueryObject @ 1c0003970 =====

/* int __cdecl implatTeamQueryObject(void * __ptr64,unsigned int,unsigned long * __ptr64,void *
   __ptr64) */

int __cdecl implatTeamQueryObject(void *param_1,uint param_2,ulong *param_3,void *param_4)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong *plVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined2 local_res10;
  undefined1 local_res12;
  
  if (param_2 == 0x10287) {
    local_res10 = 0;
    local_res12 = 0;
    if (*param_3 < 0xd8) {
LAB_1c0003b85:
      *param_3 = 0;
      return -0x3ffeffea;
    }
    NdisAcquireRWLockRead(*(undefined8 *)((longlong)param_1 + 0x88),&local_res10,0);
    *param_3 = 0xd8;
    *(undefined4 *)((longlong)param_4 + 0xd4) = 0x3f87ff;
    *(undefined4 *)((longlong)param_4 + 0xd0) = 0;
    *(undefined8 *)((longlong)param_4 + 8) = 0;
    *(undefined8 *)((longlong)param_4 + 0x30) = 0;
    *(undefined8 *)((longlong)param_4 + 0x28) = 0;
    *(undefined8 *)((longlong)param_4 + 0x38) = 0;
    *(undefined2 *)((longlong)param_4 + 0x14) = 0;
    *(undefined8 *)((longlong)param_4 + 0x18) = 0;
    *(undefined8 *)((longlong)param_4 + 0x20) = 0;
    *(undefined4 *)((longlong)param_4 + 0x10) = 0;
    *(undefined8 *)param_4 = 4;
    *(undefined8 *)((longlong)param_4 + 0x40) = *(undefined8 *)((longlong)param_1 + 0x4c0);
    *(undefined8 *)((longlong)param_4 + 0x48) = *(undefined8 *)((longlong)param_1 + 0x4c8);
    *(undefined8 *)((longlong)param_4 + 0x50) = *(undefined8 *)((longlong)param_1 + 0x4d0);
    *(undefined8 *)((longlong)param_4 + 0x58) = *(undefined8 *)((longlong)param_1 + 0x4d8);
    *(undefined8 *)((longlong)param_4 + 0x60) = *(undefined8 *)((longlong)param_1 + 0x4e0);
    *(undefined8 *)((longlong)param_4 + 0x68) = *(undefined8 *)((longlong)param_1 + 0x4e8);
    *(undefined8 *)((longlong)param_4 + 0x70) = *(undefined8 *)((longlong)param_1 + 0x4f0);
    *(undefined8 *)((longlong)param_4 + 0x78) = *(undefined8 *)((longlong)param_1 + 0x4f8);
    *(undefined8 *)((longlong)param_4 + 0x80) = *(undefined8 *)((longlong)param_1 + 0x500);
    *(undefined8 *)((longlong)param_4 + 0x88) = *(undefined8 *)((longlong)param_1 + 0x508);
    *(undefined8 *)((longlong)param_4 + 0x90) = *(undefined8 *)((longlong)param_1 + 0x510);
    *(undefined8 *)((longlong)param_4 + 0x98) = *(undefined8 *)((longlong)param_1 + 0x518);
    *(undefined8 *)((longlong)param_4 + 0xa0) = *(undefined8 *)((longlong)param_1 + 0x520);
    *(undefined8 *)((longlong)param_4 + 0xa8) = *(undefined8 *)((longlong)param_1 + 0x528);
    *(undefined8 *)((longlong)param_4 + 0xb0) = *(undefined8 *)((longlong)param_1 + 0x530);
    *(undefined8 *)((longlong)param_4 + 0xb8) = *(undefined8 *)((longlong)param_1 + 0x538);
    *(undefined8 *)((longlong)param_4 + 0xc0) = *(undefined8 *)((longlong)param_1 + 0x540);
    *(undefined8 *)((longlong)param_4 + 200) = *(undefined8 *)((longlong)param_1 + 0x548);
    for (puVar1 = *(undefined8 **)((longlong)param_1 + 0x100);
        puVar1 != (undefined8 *)((longlong)param_1 + 0x100); puVar1 = (undefined8 *)*puVar1) {
      if ((2 < *(int *)(puVar1 + 0x17)) && (uVar5 = 0, DAT_1c001b278 != 0)) {
        do {
          plVar3 = (longlong *)((longlong)param_4 + 0x40);
          lVar2 = 0x12;
          do {
            *plVar3 = *plVar3 + *(longlong *)
                                 ((longlong)plVar3 +
                                 puVar1[0x1c] + (uVar5 * 0xc0 - (longlong)param_4) + -0x30);
            plVar3 = plVar3 + 1;
            lVar2 = lVar2 + -1;
          } while (lVar2 != 0);
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < DAT_1c001b278);
      }
    }
    NdisReleaseRWLock(*(undefined8 *)((longlong)param_1 + 0x88),&local_res10);
  }
  else {
    if (param_2 != 0x10288) {
      return -0x3fffff45;
    }
    if (*param_3 < 4) goto LAB_1c0003b85;
    *param_3 = 4;
    *(undefined4 *)param_4 = 1;
  }
  return 0;
}



===== implatTeamSetObject @ 1c0003bd0 =====

/* int __cdecl implatTeamSetObject(void * __ptr64,unsigned int,unsigned long,void * __ptr64) */

int __cdecl implatTeamSetObject(void *param_1,uint param_2,ulong param_3,void *param_4)

{
  return -0x3fffff45;
}



===== implatUpdateTeamRscStatsDelta @ 1c0003be0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl implatUpdateTeamRscStatsDelta(struct _IMPLAT_ADAPTER * __ptr64) */

void __cdecl implatUpdateTeamRscStatsDelta(_IMPLAT_ADAPTER *param_1)

{
  longlong lVar1;
  int iVar2;
  undefined1 auStackY_78 [32];
  undefined1 local_38;
  undefined7 local_37;
  undefined1 uStack_30;
  undefined7 uStack_2f;
  undefined1 uStack_28;
  undefined7 uStack_27;
  undefined1 uStack_20;
  undefined7 uStack_1f;
  undefined1 uStack_18;
  undefined4 local_17;
  undefined2 local_13;
  undefined1 local_11;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar1 = *(longlong *)(param_1 + 0x28);
  local_38 = 0;
  local_37 = 0;
  uStack_30 = 0;
  uStack_2f = 0;
  uStack_28 = 0;
  local_17 = 0;
  uStack_27 = 0;
  uStack_20 = 0;
  uStack_1f = 0;
  uStack_18 = 0;
  local_13 = 0;
  local_11 = 0;
  iVar2 = implatDoOidRequestOnAdapter
                    (param_1,0,0x2021d,&local_38,0x28,(_NDIS_OID_REQUEST *)0x0,
                     (_IMPLAT_VIRTMINI *)0x0);
  if (iVar2 == 0) {
    *(longlong *)(lVar1 + 0x570) =
         *(longlong *)(lVar1 + 0x570) +
         CONCAT17(local_11,CONCAT25(local_13,CONCAT41(local_17,uStack_18)));
    *(longlong *)(lVar1 + 0x560) = *(longlong *)(lVar1 + 0x560) + CONCAT71(uStack_27,uStack_28);
    *(longlong *)(lVar1 + 0x558) = *(longlong *)(lVar1 + 0x558) + CONCAT71(uStack_2f,uStack_30);
    *(longlong *)(lVar1 + 0x568) = *(longlong *)(lVar1 + 0x568) + CONCAT71(uStack_1f,uStack_20);
  }
  return;
}



===== implatWaitForPendingAdapterUnbinds @ 1c0003c90 =====

/* void __cdecl implatWaitForPendingAdapterUnbinds(struct _IMPLAT_TEAM * __ptr64) */

void __cdecl implatWaitForPendingAdapterUnbinds(_IMPLAT_TEAM *param_1)

{
  _IMPLAT_TEAM *p_Var1;
  
  for (p_Var1 = *(_IMPLAT_TEAM **)(param_1 + 0xf0); p_Var1 != param_1 + 0xf0;
      p_Var1 = *(_IMPLAT_TEAM **)p_Var1) {
    if (p_Var1[0xe9] != (_IMPLAT_TEAM)0x0) {
      KeWaitForSingleObject(p_Var1 + 0xf0,0,0,0,0);
    }
  }
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 1c0003cf0 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_1c001b058;
  uVar2 = 0;
  if (DAT_1c001b058 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_1c001b058;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(NdisImPlatformEventProvider_Context,param_2,param_3,0,param_4,param_5);
  return;
}



===== McTemplateK0zq_EtwWriteTransfer @ 1c0003d54 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5)

{
  longlong lVar1;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  if (param_4 == (wchar_t *)0x0) {
    local_30 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    local_30 = (int)lVar1 * 2 + 2;
  }
  local_2c = 0;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  local_20 = 4;
  local_28 = &param_5;
  local_38 = param_4;
  McGenEventWrite_EtwWriteTransfer(L"NULL",param_2,0,3,local_48);
  return;
}



===== McTemplateK0zzd_EtwWriteTransfer @ 1c0003dec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zzd_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               wchar_t *param_5,undefined1 param_6)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  wchar_t *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar1 = -1;
  local_30 = 10;
  if (param_4 == (wchar_t *)0x0) {
    uVar3 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_4[lVar2] != L'\0');
    uVar3 = (ulonglong)((int)lVar2 * 2 + 2);
  }
  local_40 = (undefined4)uVar3;
  local_3c = 0;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  if (param_5 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    local_30 = (int)lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_28 = &param_6;
  local_2c = 0;
  local_20 = 4;
  local_48 = param_4;
  local_38 = param_5;
  McGenEventWrite_EtwWriteTransfer(uVar3,param_2,0,4,local_58);
  return;
}



===== WPP_SF__guid_ @ 1c0003ed0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids,param_2,param_4,0x10,0);
  return;
}



===== WPP_SF_q_guid_ @ 1c0003f10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q_guid_(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                   undefined8 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids,param_2,&local_res20,8,
             param_5,0x10,0);
  return;
}



===== WPP_SF_qdS @ 1c0003f6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdS(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,wchar_t *param_6)

{
  longlong lVar1;
  wchar_t *pwVar2;
  undefined8 local_res20;
  
  if (param_6 == (wchar_t *)0x0) {
    lVar1 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_6[lVar1] != L'\0');
    lVar1 = lVar1 * 2 + 2;
  }
  pwVar2 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar2 = L"NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,pwVar2,lVar1,0);
  return;
}



===== implatBindAdapterEx @ 1c0004010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* int __cdecl implatBindAdapterEx(void * __ptr64,void * __ptr64,struct _NDIS_BIND_PARAMETERS *
   __ptr64) */

int __cdecl implatBindAdapterEx(void *param_1,void *param_2,_NDIS_BIND_PARAMETERS *param_3)

{
  uchar *puVar1;
  _IMPLAT_TEAM *p_Var2;
  ushort uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined8 uVar7;
  longlong lVar8;
  code *pcVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  char cVar20;
  uint uVar21;
  int iVar22;
  _GUID *_Dst;
  _IMPLAT_TEAM *p_Var23;
  undefined *puVar24;
  undefined8 *puVar25;
  _GUID *p_Var26;
  _tlgProvider_t *p_Var27;
  undefined2 uVar28;
  ushort *InterfaceGuid;
  undefined1 *puVar29;
  _GUID *p_Var30;
  _GUID *in_R9;
  undefined1 auStackY_178 [8];
  undefined1 auStackY_170 [24];
  uint local_138;
  undefined2 local_134;
  undefined1 local_132;
  _GUID *local_130;
  undefined4 local_128;
  undefined4 local_124 [3];
  undefined8 local_118;
  _NDIS_BIND_PARAMETERS *p_Stack_110;
  undefined8 local_108;
  longlong local_100 [2];
  wchar_t *local_f0;
  longlong local_e8;
  wchar_t *local_e0;
  longlong local_d8;
  wchar_t *local_d0;
  _GUID local_c8;
  undefined4 *local_b8;
  undefined8 uStack_b0;
  undefined4 *local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  ulonglong local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 *local_68;
  uchar auStack_60 [8];
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_178;
  local_100[1] = 0xa0008;
  local_128 = 0;
  local_98 = 0;
  local_134 = 0;
  local_132 = 0;
  local_108 = 0;
  _Dst = (_GUID *)0x0;
  local_80 = 0;
  local_f0 = L"Team";
  local_e0 = L"MtuSize";
  local_d0 = L"MacOptions";
  local_c8.Data1 = 0;
  local_c8.Data2 = 0;
  local_c8.Data3 = 0;
  local_c8.Data4[0] = '\0';
  local_c8.Data4[1] = '\0';
  local_c8.Data4[2] = '\0';
  local_c8.Data4[3] = '\0';
  local_c8.Data4[4] = '\0';
  local_c8.Data4[5] = '\0';
  local_c8.Data4[6] = '\0';
  local_c8.Data4[7] = '\0';
  local_124[0] = 0;
  local_b8 = (undefined4 *)0x0;
  uStack_b0 = 0;
  local_130 = (_GUID *)0x0;
  local_a8 = (undefined4 *)0x0;
  uStack_a0 = 0;
  local_100[0] = 0;
  local_118 = 0;
  p_Stack_110 = (_NDIS_BIND_PARAMETERS *)0x0;
  local_e8 = 0x10000e;
  local_90 = 0;
  uStack_88 = 0;
  local_d8 = 0x160014;
  local_78 = 0;
  uStack_70 = 0;
  puVar24 = WPP_GLOBAL_Control;
  InterfaceGuid = param_2;
  p_Var30 = (_GUID *)param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    in_R9 = *(_GUID **)(param_3 + 8);
    puVar24 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    WPP_SF_Z(puVar24,param_2,param_3,(wchar_t *)in_R9);
  }
  if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
    InterfaceGuid = (ushort *)&BindingToMemberInfo;
    p_Var30 = (_GUID *)0x0;
    in_R9 = *(_GUID **)(*(longlong *)(param_3 + 8) + 8);
    McTemplateK0z_EtwWriteTransfer(puVar24,&BindingToMemberInfo,0,(wchar_t *)in_R9);
  }
  local_58 = 0;
  uStack_50 = 0;
  if (((*param_3 == (_NDIS_BIND_PARAMETERS)0x86) && (3 < (byte)param_3[1])) &&
     (0x137 < *(ushort *)(param_3 + 2))) {
    if (*(int *)(param_3 + 0x20) != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        InterfaceGuid = (ushort *)0xc;
        goto LAB_1c0004ced;
      }
      goto LAB_1c0004cfd;
    }
    p_Var30 = (_GUID *)0x0;
    uVar3 = *(ushort *)(*(longlong *)(param_3 + 8) + 2);
    InterfaceGuid = (ushort *)(ulonglong)uVar3;
    uVar21 = DAT_1c001b278 * 0xc0 + 0x1cba + (uint)uVar3;
    _Dst = implatAllocateNonPagedPoolWithTagPriority((ulonglong)uVar21,(uint)uVar3,0);
    if (_Dst == (_GUID *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (InterfaceGuid = (ushort *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
          (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        InterfaceGuid = (ushort *)0xd;
        p_Var30 = (_GUID *)&WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids);
      }
      local_138 = 0xc000009a;
      puVar29 = auStackY_178;
      goto LAB_1c0004d05;
    }
    memset(_Dst,0,(ulonglong)uVar21);
    *(uchar **)_Dst[5].Data4 = _Dst[0x1cb].Data4;
    *(short *)((longlong)&_Dst[5].Data1 + 2) = *(short *)(*(longlong *)(param_3 + 8) + 2) + 2;
    *(undefined2 *)&_Dst[5].Data1 = 0;
    RtlCopyUnicodeString(_Dst + 5,*(undefined8 *)(param_3 + 8));
    uVar3 = *(ushort *)(*(longlong *)(param_3 + 8) + 2);
    _Dst[0xf].Data4[0] = '\0';
    *(uchar **)_Dst[0x25].Data4 = _Dst[0x1cb].Data4 + (ulonglong)uVar3 + 2;
    _Dst[0xf].Data1 = 1;
    _Dst[0xf].Data2 = 1;
    _Dst[0xf].Data3 = 0;
    KeInitializeEvent(_Dst + 0x10,0);
    KeInitializeEvent(_Dst[0x11].Data4,0);
    p_Var30 = (_GUID *)0x0;
    KeInitializeEvent(_Dst + 0x13,0);
    _Dst[6].Data1 = *(ulong *)(param_3 + 0x6a);
    InterfaceGuid = &_Dst[0xb].Data2;
    _Dst[6].Data2 = *(ushort *)(param_3 + 0x6e);
    *(undefined4 *)_Dst[6].Data4 = *(undefined4 *)(param_3 + 0x24);
    uVar5 = *(undefined8 *)(param_3 + 0x28);
    _Dst[7].Data1 = (int)uVar5;
    _Dst[7].Data2 = (short)((ulonglong)uVar5 >> 0x20);
    _Dst[7].Data3 = (short)((ulonglong)uVar5 >> 0x30);
    *(undefined8 *)_Dst[7].Data4 = *(undefined8 *)(param_3 + 0x38);
    _Dst[8].Data1 = *(ulong *)(param_3 + 0x60);
    uVar4 = *(undefined4 *)(param_3 + 100);
    _Dst[8].Data2 = (short)uVar4;
    _Dst[8].Data3 = (short)((uint)uVar4 >> 0x10);
    *(undefined4 *)_Dst[8].Data4 = *(undefined4 *)(param_3 + 0xd0);
    *(undefined4 *)(_Dst[8].Data4 + 4) = *(undefined4 *)(param_3 + 0xd4);
    _Dst[9].Data1 = *(ulong *)(param_3 + 0xd8);
    *(undefined8 *)_Dst[9].Data4 = *(undefined8 *)(param_3 + 0x98);
    _Dst[10].Data1 = *(ulong *)(param_3 + 0xa0);
    *(undefined8 *)_Dst[10].Data4 = *(undefined8 *)(param_3 + 0xa8);
    _Dst[0xb].Data1 = *(ulong *)(param_3 + 0xb0);
    uVar21 = ConvertInterfaceLuidToGuid((NET_LUID *)_Dst[10].Data4,(GUID *)InterfaceGuid);
    if ((int)uVar21 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (p_Var30 = (_GUID *)(ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
          (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        p_Var30 = (_GUID *)&WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids;
        InterfaceGuid = (ushort *)0xe;
        in_R9 = (_GUID *)(ulonglong)uVar21;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                 &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,uVar21);
      }
      local_138 = NdisConvertNtStatusToNdisStatus((_GUID *)(ulonglong)uVar21);
      puVar29 = auStackY_178;
      goto LAB_1c0004d05;
    }
    local_58._0_2_ = _Dst[0xb].Data2;
    local_58._2_2_ = _Dst[0xb].Data3;
    local_58._4_1_ = _Dst[0xb].Data4[0];
    local_58._5_1_ = _Dst[0xb].Data4[1];
    local_58._6_1_ = _Dst[0xb].Data4[2];
    local_58._7_1_ = _Dst[0xb].Data4[3];
    uStack_50 = *(undefined8 *)(_Dst[0xb].Data4 + 4);
    _Dst[0xc].Data4[0] = 0x80;
    _Dst[0xc].Data4[1] = '\x01';
    _Dst[0xc].Data4[2] = '(';
    _Dst[0xc].Data4[3] = '\0';
    *(undefined4 *)(_Dst[0xc].Data4 + 4) = *(undefined4 *)(param_3 + 0x48);
    _Dst[0xd].Data1 = *(ulong *)(param_3 + 0x4c);
    *(undefined8 *)_Dst[0xd].Data4 = *(undefined8 *)(param_3 + 0x30);
    uVar5 = *(undefined8 *)(param_3 + 0x40);
    _Dst[0xe].Data1 = (int)uVar5;
    _Dst[0xe].Data2 = (short)((ulonglong)uVar5 >> 0x20);
    _Dst[0xe].Data3 = (short)((ulonglong)uVar5 >> 0x30);
    p_Var30 = _Dst + 0x1ae;
    *(_GUID **)_Dst[0x1ae].Data4 = p_Var30;
    *(_GUID **)p_Var30 = p_Var30;
    p_Var30 = _Dst + 0x1ad;
    *(_GUID **)_Dst[0x1ad].Data4 = p_Var30;
    *(_GUID **)p_Var30 = p_Var30;
    _Dst[0xe].Data4[0] = '\x04';
    _Dst[0xe].Data4[1] = '\0';
    _Dst[0xe].Data4[2] = '\0';
    _Dst[0xe].Data4[3] = '\0';
    _Dst[0xe].Data4[4] = '\0';
    _Dst[0xe].Data4[5] = '\0';
    _Dst[0xe].Data4[6] = '\0';
    _Dst[0xe].Data4[7] = '\0';
    *(undefined4 *)_Dst[0x26].Data4 = *(undefined4 *)(param_3 + 0x50);
    _Dst[0x26].Data4[4] = '\0';
    _Dst[0x26].Data4[5] = '\0';
    _Dst[0x26].Data4[6] = '\0';
    _Dst[0x26].Data4[7] = '\0';
    pcVar6 = *(char **)(param_3 + 0xe0);
    if ((pcVar6 != (char *)0x0) && (*pcVar6 == -0x59)) {
      uVar21 = (uint)*(ushort *)(pcVar6 + 2);
      if (0xb3 < *(ushort *)(pcVar6 + 2)) {
        uVar21 = 0xb4;
      }
      memcpy(_Dst[0x28].Data4 + 4,pcVar6,(ulonglong)uVar21);
      *(short *)(_Dst[0x28].Data4 + 6) = (short)uVar21;
    }
    pcVar6 = *(char **)(param_3 + 0xf8);
    if ((pcVar6 != (char *)0x0) && (*pcVar6 == -0x80)) {
      uVar21 = 0x1c;
      if (*(ushort *)(pcVar6 + 2) < 0x1c) {
        uVar21 = (uint)*(ushort *)(pcVar6 + 2);
      }
      memcpy(_Dst + 0x27,pcVar6,(ulonglong)uVar21);
      *(short *)((longlong)&_Dst[0x27].Data1 + 2) = (short)uVar21;
    }
    pcVar6 = *(char **)(param_3 + 0x100);
    if ((pcVar6 != (char *)0x0) && (*pcVar6 == -0x80)) {
      uVar21 = 0x54;
      if (*(ushort *)(pcVar6 + 2) < 0x54) {
        uVar21 = (uint)*(ushort *)(pcVar6 + 2);
      }
      memcpy(_Dst + 0x1b0,pcVar6,(ulonglong)uVar21);
      *(short *)((longlong)&_Dst[0x1b0].Data1 + 2) = (short)uVar21;
    }
    pcVar6 = *(char **)(param_3 + 0x110);
    if ((pcVar6 != (char *)0x0) && (*pcVar6 == -0x80)) {
      uVar21 = 0x74;
      if (*(ushort *)(pcVar6 + 2) < 0x74) {
        uVar21 = (uint)*(ushort *)(pcVar6 + 2);
      }
      memcpy(&_Dst[0x1b5].Data2,pcVar6,(ulonglong)uVar21);
      _Dst[0x1b5].Data3 = (ushort)uVar21;
    }
    pcVar6 = *(char **)(param_3 + 0x108);
    if ((pcVar6 != (char *)0x0) && (*pcVar6 == -0x80)) {
      uVar21 = 0x3c;
      if (*(ushort *)(pcVar6 + 2) < 0x3c) {
        uVar21 = (uint)*(ushort *)(pcVar6 + 2);
      }
      memcpy(_Dst[0x1f].Data4 + 4,pcVar6,(ulonglong)uVar21);
      *(short *)(_Dst[0x1f].Data4 + 6) = (short)uVar21;
    }
    puVar1 = _Dst[0x23].Data4;
    p_Var30 = (_GUID *)0x0;
    *(uchar **)(_Dst + 0x24) = puVar1;
    InterfaceGuid = (ushort *)0x0;
    *(uchar **)puVar1 = puVar1;
    cVar20 = RtlCreateHashTable(_Dst[0x24].Data4);
    if (cVar20 == '\0') {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        InterfaceGuid = (ushort *)0xf;
        p_Var30 = (_GUID *)&WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids);
      }
      local_138 = 0xc0000001;
      puVar29 = auStackY_178;
      goto LAB_1c0004d05;
    }
    implatWaitForGlobalMutexAndPendingOperationsCount();
    local_118 = 0x1401a9;
    local_108 = 0;
    p_Stack_110 = param_3;
    local_138 = NdisOpenConfigurationEx(&local_118,&local_130);
    in_R9 = (_GUID *)(ulonglong)local_138;
    if (local_138 == 0) {
      p_Var30 = local_130;
      NdisReadConfiguration(&local_138,local_100,local_130,local_100 + 1);
      in_R9 = (_GUID *)(ulonglong)local_138;
      if (local_138 == 0) {
        RtlInitUnicodeString(&local_78,*(undefined8 *)(local_100[0] + 0x10));
        local_68 = (undefined8 *)0x0;
        auStack_60[0] = '\0';
        auStack_60[1] = '\0';
        auStack_60[2] = '\0';
        auStack_60[3] = '\0';
        auStack_60[4] = '\0';
        auStack_60[5] = '\0';
        auStack_60[6] = '\0';
        auStack_60[7] = '\0';
        uVar21 = RtlGUIDFromString(&local_78);
        if ((int)uVar21 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            in_R9 = (_GUID *)(ulonglong)uVar21;
            p_Var30 = (_GUID *)&WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids;
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                     &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids,uVar21);
          }
        }
        else {
          p_Var30 = (_GUID *)CONCAT71((int7)((ulonglong)p_Var30 >> 8),1);
          p_Var23 = implatFindTeamByGuid((_GUID *)&local_68,'\x01','\x01');
          if (p_Var23 != (_IMPLAT_TEAM *)0x0) {
            local_138 = implatAddAdapterToTeam(p_Var23,(_IMPLAT_ADAPTER *)_Dst);
            LOCK();
            p_Var2 = p_Var23 + 0x80;
            iVar22 = *(int *)p_Var2;
            *(int *)p_Var2 = *(int *)p_Var2 + -1;
            UNLOCK();
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x40) != 0)) &&
               (4 < (byte)WPP_GLOBAL_Control[0x29])) {
              p_Var30 = (_GUID *)&WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids;
              WPP_SF_qdS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                         &WPP_e9d94c884259399b8c1d1f035f7c06fe_Traceguids,p_Var23,
                         (char)(iVar22 + -1),L"implatBindAdapterEx reverting find or create");
            }
            if (iVar22 + -1 == 0) {
              implatRemoveTeam(p_Var23);
            }
            in_R9 = (_GUID *)(ulonglong)local_138;
            if (local_138 == 0) {
              uStack_88._0_4_ = *(undefined4 *)_Dst[6].Data4;
              NdisWriteConfiguration(&local_138,local_130,local_100 + 3,&local_90);
              local_90 = local_90 & 0xffffffff00000000;
              uStack_88 = CONCAT44(uStack_88._4_4_,_Dst[9].Data1);
              NdisWriteConfiguration(&local_138,local_130,local_100 + 5,&local_90);
              local_c8.Data4 = *(uchar (*) [8])(param_3 + 0x10);
              local_b8 = &local_128;
              local_138 = 0;
              local_a8 = local_124;
              local_c8.Data1 = 0x340187;
              local_c8.Data2 = 0;
              local_c8.Data3 = 0;
              uStack_b0 = 1;
              local_98 = 0;
              uStack_a0 = 0;
              KeInitializeEvent(_Dst + 3,0,0);
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                 (4 < (byte)WPP_GLOBAL_Control[0x29])) {
                WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                         &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,_Dst);
              }
              p_Var30 = &local_c8;
              local_138 = NdisOpenAdapterEx(_Global,_Dst,p_Var30,param_2);
              if (local_138 == 0x103) {
                p_Var30 = (_GUID *)0x0;
                KeWaitForSingleObject(_Dst + 3,0,0,0);
                local_138 = *(uint *)_Dst[4].Data4;
              }
              in_R9 = (_GUID *)(ulonglong)local_138;
              if (local_138 == 0) {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                   (4 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                           &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,_Dst);
                }
                p_Var30 = (_GUID *)0xfc01020d;
                local_138 = implatDoOidRequestOnAdapter
                                      ((_IMPLAT_ADAPTER *)_Dst,0,0xfc01020d,_Dst[0x14].Data4,0xb4,
                                       (_NDIS_OID_REQUEST *)0x0,(_IMPLAT_VIRTMINI *)0x0);
                in_R9 = (_GUID *)(ulonglong)local_138;
                if (local_138 != 0) {
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                     (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    p_Var30 = (_GUID *)&WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids;
                    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                             &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,local_138);
                  }
                  uVar5._0_2_ = _Dst[0x29].Data2;
                  uVar5._2_2_ = _Dst[0x29].Data3;
                  uVar5._4_1_ = _Dst[0x29].Data4[0];
                  uVar5._5_1_ = _Dst[0x29].Data4[1];
                  uVar5._6_1_ = _Dst[0x29].Data4[2];
                  uVar5._7_1_ = _Dst[0x29].Data4[3];
                  uVar10 = *(undefined8 *)(_Dst[0x29].Data4 + 4);
                  uVar11._0_2_ = _Dst[0x2a].Data2;
                  uVar11._2_2_ = _Dst[0x2a].Data3;
                  uVar11._4_1_ = _Dst[0x2a].Data4[0];
                  uVar11._5_1_ = _Dst[0x2a].Data4[1];
                  uVar11._6_1_ = _Dst[0x2a].Data4[2];
                  uVar11._7_1_ = _Dst[0x2a].Data4[3];
                  *(undefined8 *)_Dst[0x14].Data4 = *(undefined8 *)(_Dst[0x28].Data4 + 4);
                  _Dst[0x15].Data1 = (int)uVar5;
                  _Dst[0x15].Data2 = (short)((ulonglong)uVar5 >> 0x20);
                  _Dst[0x15].Data3 = (short)((ulonglong)uVar5 >> 0x30);
                  uVar5 = *(undefined8 *)(_Dst[0x2a].Data4 + 4);
                  uVar12._0_2_ = _Dst[0x2b].Data2;
                  uVar12._2_2_ = _Dst[0x2b].Data3;
                  uVar12._4_1_ = _Dst[0x2b].Data4[0];
                  uVar12._5_1_ = _Dst[0x2b].Data4[1];
                  uVar12._6_1_ = _Dst[0x2b].Data4[2];
                  uVar12._7_1_ = _Dst[0x2b].Data4[3];
                  *(undefined8 *)_Dst[0x15].Data4 = uVar10;
                  _Dst[0x16].Data1 = (int)uVar11;
                  _Dst[0x16].Data2 = (short)((ulonglong)uVar11 >> 0x20);
                  _Dst[0x16].Data3 = (short)((ulonglong)uVar11 >> 0x30);
                  uVar10 = *(undefined8 *)(_Dst[0x2b].Data4 + 4);
                  uVar13._0_2_ = _Dst[0x2c].Data2;
                  uVar13._2_2_ = _Dst[0x2c].Data3;
                  uVar13._4_1_ = _Dst[0x2c].Data4[0];
                  uVar13._5_1_ = _Dst[0x2c].Data4[1];
                  uVar13._6_1_ = _Dst[0x2c].Data4[2];
                  uVar13._7_1_ = _Dst[0x2c].Data4[3];
                  *(undefined8 *)_Dst[0x16].Data4 = uVar5;
                  _Dst[0x17].Data1 = (int)uVar12;
                  _Dst[0x17].Data2 = (short)((ulonglong)uVar12 >> 0x20);
                  _Dst[0x17].Data3 = (short)((ulonglong)uVar12 >> 0x30);
                  uVar5 = *(undefined8 *)(_Dst[0x2c].Data4 + 4);
                  uVar14._0_2_ = _Dst[0x2d].Data2;
                  uVar14._2_2_ = _Dst[0x2d].Data3;
                  uVar14._4_1_ = _Dst[0x2d].Data4[0];
                  uVar14._5_1_ = _Dst[0x2d].Data4[1];
                  uVar14._6_1_ = _Dst[0x2d].Data4[2];
                  uVar14._7_1_ = _Dst[0x2d].Data4[3];
                  *(undefined8 *)_Dst[0x17].Data4 = uVar10;
                  _Dst[0x18].Data1 = (int)uVar13;
                  _Dst[0x18].Data2 = (short)((ulonglong)uVar13 >> 0x20);
                  _Dst[0x18].Data3 = (short)((ulonglong)uVar13 >> 0x30);
                  uVar10 = *(undefined8 *)(_Dst[0x2d].Data4 + 4);
                  uVar15._0_2_ = _Dst[0x2e].Data2;
                  uVar15._2_2_ = _Dst[0x2e].Data3;
                  uVar15._4_1_ = _Dst[0x2e].Data4[0];
                  uVar15._5_1_ = _Dst[0x2e].Data4[1];
                  uVar15._6_1_ = _Dst[0x2e].Data4[2];
                  uVar15._7_1_ = _Dst[0x2e].Data4[3];
                  *(undefined8 *)_Dst[0x18].Data4 = uVar5;
                  _Dst[0x19].Data1 = (int)uVar14;
                  _Dst[0x19].Data2 = (short)((ulonglong)uVar14 >> 0x20);
                  _Dst[0x19].Data3 = (short)((ulonglong)uVar14 >> 0x30);
                  uVar5 = *(undefined8 *)(_Dst[0x2e].Data4 + 4);
                  uVar16._0_2_ = _Dst[0x2f].Data2;
                  uVar16._2_2_ = _Dst[0x2f].Data3;
                  uVar16._4_1_ = _Dst[0x2f].Data4[0];
                  uVar16._5_1_ = _Dst[0x2f].Data4[1];
                  uVar16._6_1_ = _Dst[0x2f].Data4[2];
                  uVar16._7_1_ = _Dst[0x2f].Data4[3];
                  *(undefined8 *)_Dst[0x19].Data4 = uVar10;
                  _Dst[0x1a].Data1 = (int)uVar15;
                  _Dst[0x1a].Data2 = (short)((ulonglong)uVar15 >> 0x20);
                  _Dst[0x1a].Data3 = (short)((ulonglong)uVar15 >> 0x30);
                  uVar10 = *(undefined8 *)(_Dst[0x2f].Data4 + 4);
                  uVar17._0_2_ = _Dst[0x30].Data2;
                  uVar17._2_2_ = _Dst[0x30].Data3;
                  uVar17._4_1_ = _Dst[0x30].Data4[0];
                  uVar17._5_1_ = _Dst[0x30].Data4[1];
                  uVar17._6_1_ = _Dst[0x30].Data4[2];
                  uVar17._7_1_ = _Dst[0x30].Data4[3];
                  *(undefined8 *)_Dst[0x1a].Data4 = uVar5;
                  _Dst[0x1b].Data1 = (int)uVar16;
                  _Dst[0x1b].Data2 = (short)((ulonglong)uVar16 >> 0x20);
                  _Dst[0x1b].Data3 = (short)((ulonglong)uVar16 >> 0x30);
                  *(undefined8 *)_Dst[0x1b].Data4 = uVar10;
                  _Dst[0x1c].Data1 = (int)uVar17;
                  _Dst[0x1c].Data2 = (short)((ulonglong)uVar17 >> 0x20);
                  _Dst[0x1c].Data3 = (short)((ulonglong)uVar17 >> 0x30);
                  uVar10._0_2_ = _Dst[0x31].Data2;
                  uVar10._2_2_ = _Dst[0x31].Data3;
                  uVar10._4_1_ = _Dst[0x31].Data4[0];
                  uVar10._5_1_ = _Dst[0x31].Data4[1];
                  uVar10._6_1_ = _Dst[0x31].Data4[2];
                  uVar10._7_1_ = _Dst[0x31].Data4[3];
                  uVar5 = *(undefined8 *)(_Dst[0x31].Data4 + 4);
                  uVar18._0_2_ = _Dst[0x32].Data2;
                  uVar18._2_2_ = _Dst[0x32].Data3;
                  uVar18._4_1_ = _Dst[0x32].Data4[0];
                  uVar18._5_1_ = _Dst[0x32].Data4[1];
                  uVar18._6_1_ = _Dst[0x32].Data4[2];
                  uVar18._7_1_ = _Dst[0x32].Data4[3];
                  *(undefined8 *)_Dst[0x1c].Data4 = *(undefined8 *)(_Dst[0x30].Data4 + 4);
                  _Dst[0x1d].Data1 = (int)uVar10;
                  _Dst[0x1d].Data2 = (short)((ulonglong)uVar10 >> 0x20);
                  _Dst[0x1d].Data3 = (short)((ulonglong)uVar10 >> 0x30);
                  uVar10 = *(undefined8 *)(_Dst[0x32].Data4 + 4);
                  uVar19._0_2_ = _Dst[0x33].Data2;
                  uVar19._2_2_ = _Dst[0x33].Data3;
                  uVar19._4_1_ = _Dst[0x33].Data4[0];
                  uVar19._5_1_ = _Dst[0x33].Data4[1];
                  uVar19._6_1_ = _Dst[0x33].Data4[2];
                  uVar19._7_1_ = _Dst[0x33].Data4[3];
                  uVar4 = *(undefined4 *)(_Dst[0x33].Data4 + 4);
                  *(undefined8 *)_Dst[0x1d].Data4 = uVar5;
                  _Dst[0x1e].Data1 = (int)uVar18;
                  _Dst[0x1e].Data2 = (short)((ulonglong)uVar18 >> 0x20);
                  _Dst[0x1e].Data3 = (short)((ulonglong)uVar18 >> 0x30);
                  *(undefined8 *)_Dst[0x1e].Data4 = uVar10;
                  _Dst[0x1f].Data1 = (int)uVar19;
                  _Dst[0x1f].Data2 = (short)((ulonglong)uVar19 >> 0x20);
                  _Dst[0x1f].Data3 = (short)((ulonglong)uVar19 >> 0x30);
                  *(undefined4 *)_Dst[0x1f].Data4 = uVar4;
                  local_138 = 0;
                }
                uVar7._0_4_ = _Dst[2].Data1;
                uVar7._4_2_ = _Dst[2].Data2;
                uVar7._6_2_ = _Dst[2].Data3;
                vmqInitMNicState((undefined8 *)_Dst[0x1af].Data4,uVar7);
                local_138 = implatCheckAdapterInternalBindings
                                      ((_IMPLAT_ADAPTER *)_Dst,(_UNICODE_STRING *)0x0);
                if (local_138 == 0) {
                  NdisAcquireRWLockWrite
                            (*(undefined8 *)(*(longlong *)_Dst[2].Data4 + 0x88),&local_134);
                  lVar8 = *(longlong *)_Dst[2].Data4;
                  _Dst[0xf].Data1 = 3;
                  NdisReleaseRWLock(*(undefined8 *)(lVar8 + 0x88));
                  puVar29 = auStackY_178;
                  puVar25 = &DAT_1c001b248;
                  if (*(undefined8 **)DAT_1c001b250 != &DAT_1c001b248) {
                    puVar25 = (undefined8 *)0x3;
                    pcVar9 = (code *)swi(0x29);
                    DAT_1c001b250 = (_GUID *)(*pcVar9)();
                    puVar29 = auStackY_170;
                  }
                  *(undefined8 **)_Dst = puVar25;
                  *(_GUID **)_Dst->Data4 = DAT_1c001b250;
                  *(_GUID **)DAT_1c001b250 = _Dst;
                  *(undefined8 *)(puVar29 + -8) = 0x1c0004c09;
                  DAT_1c001b250 = _Dst;
                  KeReleaseMutex(&DAT_1c001b1f0);
                  *(undefined8 *)(puVar29 + -8) = 0x1c0004c13;
                  implatIncreaseGlobalPendingOperationsCount();
                  lVar8 = *(longlong *)_Dst[2].Data4;
                  in_R9 = (_GUID *)0x0;
                  *(undefined8 *)(puVar29 + 0x20) = 0;
                  p_Var30 = (_GUID *)0x0;
                  *(undefined8 *)(puVar29 + -8) = 0x1c0004c32;
                  KeWaitForSingleObject(lVar8 + 0x118);
                  for (puVar25 = *(undefined8 **)_Dst[0x23].Data4; (uchar *)puVar25 != puVar1;
                      puVar25 = (undefined8 *)*puVar25) {
                    if (*(char *)(puVar25[-1] + 0x98) == '\0') {
                      *(undefined8 *)(puVar29 + -8) = 0x1c0004c55;
                      iVar22 = implatAllocatePort((_IMPLAT_INTERNAL_BINDING *)(puVar25 + -2));
                      *(int *)(puVar29 + 0x40) = iVar22;
                      if (iVar22 != 0) {
                        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                          uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
                          p_Var30 = (_GUID *)&WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids;
                          *(int *)(puVar29 + 0x20) = iVar22;
                          *(undefined8 *)(puVar29 + -8) = 0x1c0004c93;
                          in_R9 = _Dst;
                          WPP_SF_qd(uVar5,0x19,&WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,_Dst
                                    ,puVar29[0x20]);
                        }
                        *(undefined4 *)(puVar29 + 0x40) = 0;
                      }
                    }
                  }
                  lVar8 = *(longlong *)_Dst[2].Data4;
                  InterfaceGuid = (ushort *)0x0;
                  *(undefined8 *)(puVar29 + -8) = 0x1c0004cb9;
                  KeReleaseMutex(lVar8 + 0x118);
                  *(undefined8 *)(puVar29 + -8) = 0x1c0004cc3;
                  implatDecreaseGlobalPendingOperationsCount();
                }
                else {
                  InterfaceGuid = (ushort *)0x0;
                  KeReleaseMutex(&DAT_1c001b1f0);
                  puVar29 = auStackY_178;
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      (puVar29 = auStackY_178, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                     (puVar29 = auStackY_178, 1 < (byte)WPP_GLOBAL_Control[0x29])) {
                    in_R9 = (_GUID *)(ulonglong)local_138;
                    InterfaceGuid = (ushort *)0x18;
                    p_Var30 = (_GUID *)&WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids;
                    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                             &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,local_138);
                    puVar29 = auStackY_178;
                  }
                }
                goto LAB_1c0004d05;
              }
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                p_Var30 = (_GUID *)&WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids;
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                         &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,local_138);
              }
              _Dst[2].Data1 = 0;
              _Dst[2].Data2 = 0;
              _Dst[2].Data3 = 0;
            }
            else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                    (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar28 = 0x13;
              goto LAB_1c00046a9;
            }
            goto LAB_1c00046b9;
          }
        }
        InterfaceGuid = (ushort *)0x0;
        local_138 = 0xc0000001;
        KeReleaseMutex(&DAT_1c001b1f0);
        puVar29 = auStackY_178;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (puVar29 = auStackY_178, (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (puVar29 = auStackY_178, 1 < (byte)WPP_GLOBAL_Control[0x29])) {
          p_Var30 = (_GUID *)&WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids;
          InterfaceGuid = (ushort *)0x12;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                  &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids);
          puVar29 = auStackY_178;
        }
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar28 = 0x11;
LAB_1c00046a9:
          p_Var30 = (_GUID *)&WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar28,
                   &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,(int)in_R9);
        }
LAB_1c00046b9:
        InterfaceGuid = (ushort *)0x0;
        KeReleaseMutex(&DAT_1c001b1f0);
        puVar29 = auStackY_178;
      }
      goto LAB_1c0004d05;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      p_Var30 = (_GUID *)&WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,local_138);
    }
    KeReleaseMutex(&DAT_1c001b1f0,0);
    puVar29 = auStackY_178;
    local_130 = (_GUID *)0x0;
    local_138 = 0xc0010007;
LAB_1c0004d2b:
    p_Var26 = _Dst;
    p_Var26[0xf].Data1 = 2;
    lVar8._0_4_ = p_Var26[2].Data1;
    lVar8._4_2_ = p_Var26[2].Data2;
    lVar8._6_2_ = p_Var26[2].Data3;
    if (lVar8 != 0) {
      *(undefined8 *)(puVar29 + -8) = 0x1c0004d40;
      implatCloseAdapter((_IMPLAT_ADAPTER *)p_Var26);
    }
    if (*(longlong *)p_Var26[2].Data4 != 0) {
      *(undefined8 *)(puVar29 + -8) = 0x1c0004d4e;
      implatWaitForMutex((_KMUTANT *)&DAT_1c001b1f0);
      *(undefined8 *)(puVar29 + -8) = 0x1c0004d56;
      implatRemoveAdapterFromTeam((_IMPLAT_ADAPTER *)p_Var26);
      *(undefined8 *)(puVar29 + -8) = 0x1c0004d62;
      KeReleaseMutex(&DAT_1c001b1f0,0);
    }
    if (*(longlong *)p_Var26[0x24].Data4 != 0) {
      *(undefined8 *)(puVar29 + -8) = 0x1c0004d7a;
      RtlDeleteHashTable();
      p_Var26[0x24].Data4[0] = '\0';
      p_Var26[0x24].Data4[1] = '\0';
      p_Var26[0x24].Data4[2] = '\0';
      p_Var26[0x24].Data4[3] = '\0';
      p_Var26[0x24].Data4[4] = '\0';
      p_Var26[0x24].Data4[5] = '\0';
      p_Var26[0x24].Data4[6] = '\0';
      p_Var26[0x24].Data4[7] = '\0';
    }
    p_Var26[0xf].Data1 = 0;
    *(undefined8 *)(puVar29 + -8) = 0x1c0004d9c;
    ExFreePoolWithTag(p_Var26,0x6c506d49);
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      InterfaceGuid = (ushort *)&DAT_0000000b;
LAB_1c0004ced:
      p_Var30 = (_GUID *)&WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(short)InterfaceGuid,
              &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids);
    }
LAB_1c0004cfd:
    local_138 = 0xc000000d;
    puVar29 = auStackY_178;
LAB_1c0004d05:
    p_Var26 = *(_GUID **)(puVar29 + 0x48);
    if (p_Var26 != (_GUID *)0x0) {
      *(undefined8 *)(puVar29 + -8) = 0x1c0004d16;
      NdisCloseConfiguration();
    }
    if (*(int *)(puVar29 + 0x40) == 0) goto LAB_1c0004ddd;
    if (_Dst != (_GUID *)0x0) goto LAB_1c0004d2b;
  }
  if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 4) != 0) {
    lVar8 = *(longlong *)(param_3 + 8);
    *(undefined4 *)(puVar29 + 0x20) = *(undefined4 *)(puVar29 + 0x40);
    in_R9 = *(_GUID **)(lVar8 + 8);
    *(undefined8 *)(puVar29 + -8) = 0x1c0004dc6;
    McTemplateK0zq_EtwWriteTransfer
              (p_Var26,&BindingToMemberFailedErr,p_Var30,(wchar_t *)in_R9,puVar29[0x20]);
  }
  p_Var30 = (_GUID *)(ulonglong)*(uint *)(puVar29 + 0x40);
  InterfaceGuid = *(ushort **)(*(longlong *)(param_3 + 8) + 8);
  *(undefined8 *)(puVar29 + -8) = 0x1c0004ddd;
  SysEventWriteStrStatus(-0x7fffbd9e,InterfaceGuid,*(uint *)(puVar29 + 0x40));
LAB_1c0004ddd:
  p_Var27 = (_tlgProvider_t *)WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    lVar8 = *(longlong *)(param_3 + 8);
    p_Var27 = *(_tlgProvider_t **)(WPP_GLOBAL_Control + 0x18);
    *(undefined4 *)(puVar29 + 0x20) = *(undefined4 *)(puVar29 + 0x40);
    in_R9 = *(_GUID **)(lVar8 + 8);
    *(undefined8 *)(puVar29 + -8) = 0x1c0004e10;
    WPP_SF_Sd(p_Var27,InterfaceGuid,p_Var30,(wchar_t *)in_R9,puVar29[0x20]);
  }
  if (5 < DAT_1c001b0a0) {
    *(undefined4 *)(puVar29 + 0x58) = *(undefined4 *)(puVar29 + 0x40);
    local_68 = &local_58;
    *(undefined1 **)(puVar29 + 0x28) = puVar29 + 0x58;
    *(_GUID **)(puVar29 + 0x20) = (_GUID *)&local_68;
    *(undefined8 *)(puVar29 + -8) = 0x1c0004e48;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<4>_>
              (p_Var27,&DAT_1c001916a,p_Var30,in_R9,*(_tlgWrapperByRef<16> **)(puVar29 + 0x20),
               *(_tlgWrapperByVal<4> **)(puVar29 + 0x28));
  }
  *(undefined8 *)(puVar29 + -8) = 0x1c0004e58;
  return *(int *)(puVar29 + 0x40);
}



===== implatCheckAdapterInternalBindings @ 1c0004e7c =====

/* int __cdecl implatCheckAdapterInternalBindings(struct _IMPLAT_ADAPTER * __ptr64,struct
   _UNICODE_STRING * __ptr64) */

int __cdecl implatCheckAdapterInternalBindings(_IMPLAT_ADAPTER *param_1,_UNICODE_STRING *param_2)

{
  short *psVar1;
  bool bVar2;
  ulonglong uVar3;
  short sVar4;
  int iVar5;
  _IMPLAT_VIRTMINI *p_Var6;
  _IMPLAT_ADAPTER *p_Var7;
  short *psVar8;
  short *psVar9;
  _IMPLAT_ADAPTER *p_Var10;
  ushort uVar11;
  undefined2 local_res10;
  undefined1 local_res12;
  int local_res18 [2];
  longlong local_res20;
  longlong local_78;
  undefined8 local_70;
  short *psStack_68;
  undefined8 local_60;
  wchar_t *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  
  local_60 = 0x1c001a;
  local_res18[0] = 0;
  local_40 = 0;
  local_res20 = 0;
  local_58 = L"UpperBindings";
  local_78 = 0;
  local_res10 = 0;
  local_res12 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_70 = 0;
  psStack_68 = (short *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
             &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,param_1);
  }
  if (param_2 == (_UNICODE_STRING *)0x0) {
    uStack_48 = *(undefined8 *)(param_1 + 0x20);
    local_50 = 0x1401a9;
    local_40 = 0;
    local_res18[0] = NdisOpenConfigurationEx(&local_50,&local_res20);
    if (local_res18[0] != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                 &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,local_res18[0]);
      }
      local_res20 = 0;
      local_res18[0] = -0x3ffefff9;
      goto LAB_1c000528e;
    }
    NdisReadConfiguration(local_res18,&local_78,local_res20,&local_60,3);
    if (local_res18[0] == 0) {
      param_2 = (_UNICODE_STRING *)(local_78 + 8);
      goto LAB_1c0004ffc;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
               &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,local_res18[0]);
    }
  }
  else {
LAB_1c0004ffc:
    p_Var7 = *(_IMPLAT_ADAPTER **)(param_1 + 0x238);
    psVar1 = (short *)(*(longlong *)(param_2 + 8) + (ulonglong)(*(ushort *)param_2 >> 1) * 2);
    if (p_Var7 != param_1 + 0x238) {
      do {
        if (p_Var7[0x55] == (_IMPLAT_ADAPTER)0x0) {
          for (psVar9 = *(short **)(param_2 + 8); (uVar11 = 0, psVar9 < psVar1 && (*psVar9 != 0));
              psVar9 = (short *)((longlong)psVar9 + (ulonglong)uVar11 + 2)) {
            local_70 = local_70 & 0xffffffffffff0000;
            uVar3 = local_70;
            for (psVar8 = psVar9; (psVar8 < psVar1 && (*psVar8 != 0)); psVar8 = psVar8 + 1) {
              uVar11 = uVar11 + 2;
              local_70._2_6_ = (undefined6)(uVar3 >> 0x10);
              local_70 = CONCAT62(local_70._2_6_,uVar11);
              uVar3 = local_70;
            }
            local_70._4_4_ = (undefined4)(uVar3 >> 0x20);
            local_70._0_4_ = CONCAT22(uVar11,(short)uVar3);
            psStack_68 = psVar9;
            if ((*(ushort *)(*(longlong *)(p_Var7 + -8) + 0x28) == uVar11) &&
               (iVar5 = memcmp(*(void **)(*(longlong *)(p_Var7 + -8) + 0x30),psVar9,
                               (ulonglong)uVar11), iVar5 == 0)) {
              p_Var10 = *(_IMPLAT_ADAPTER **)p_Var7;
              goto LAB_1c00050c8;
            }
          }
          p_Var10 = *(_IMPLAT_ADAPTER **)p_Var7;
          if (*(int *)(p_Var7 + 0x50) == 0) goto LAB_1c00050ba;
          p_Var7[0x55] = (_IMPLAT_ADAPTER)0x1;
        }
        else {
          p_Var10 = *(_IMPLAT_ADAPTER **)p_Var7;
          if (*(int *)(p_Var7 + 0x50) == 0) {
LAB_1c00050ba:
            implatRemoveInternalBinding((_IMPLAT_INTERNAL_BINDING *)(p_Var7 + -0x10));
          }
        }
LAB_1c00050c8:
        p_Var7 = p_Var10;
      } while (p_Var10 != param_1 + 0x238);
    }
    for (psVar9 = *(short **)(param_2 + 8); (psVar9 < psVar1 && (sVar4 = 0, *psVar9 != 0));
        psVar9 = (short *)((longlong)psVar9 + (local_70 & 0xffff) + 2)) {
      psVar8 = psVar9;
      while( true ) {
        uVar3 = local_70;
        local_70 = CONCAT62(local_70._2_6_,sVar4);
        if ((psVar1 <= psVar8) || (*psVar8 == 0)) break;
        sVar4 = sVar4 + 2;
        psVar8 = psVar8 + 1;
      }
      local_70._4_4_ = SUB84(uVar3,4);
      local_70._0_4_ = CONCAT22(sVar4,sVar4);
      psStack_68 = psVar9;
      p_Var6 = implatFindVirtMiniByName
                         ((_LIST_ENTRY *)(*(_IMPLAT_TEAM **)(param_1 + 0x28) + 0x100),
                          (_UNICODE_STRING *)&local_70,'\x01',*(_IMPLAT_TEAM **)(param_1 + 0x28));
      if (p_Var6 == (_IMPLAT_VIRTMINI *)0x0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                  &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids);
        }
      }
      else {
        NdisAcquireRWLockRead(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res10);
        for (p_Var7 = *(_IMPLAT_ADAPTER **)(param_1 + 0x238); p_Var7 != param_1 + 0x238;
            p_Var7 = *(_IMPLAT_ADAPTER **)p_Var7) {
          p_Var10 = p_Var7 + -0x10;
          if (*(_IMPLAT_VIRTMINI **)(p_Var7 + -8) == p_Var6) {
            bVar2 = true;
            goto LAB_1c00051bc;
          }
        }
        p_Var10 = (_IMPLAT_ADAPTER *)0x0;
        bVar2 = false;
LAB_1c00051bc:
        NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res10);
        if (bVar2) {
          if (p_Var10[0x65] != (_IMPLAT_ADAPTER)0x0) {
            p_Var10[0x65] = (_IMPLAT_ADAPTER)0x0;
          }
        }
        else {
          iVar5 = implatCreateInternalBinding(param_1,p_Var6,(_IMPLAT_INTERNAL_BINDING **)0x0);
          if ((((iVar5 != 0) &&
               (local_res18[0] = iVar5, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
                     &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,iVar5);
          }
        }
        implatDereferenceVirtualMiniport
                  (p_Var6,(ushort *)L"CheckAdapterInternalBindings reverting find or create");
      }
    }
  }
  if (local_res20 != 0) {
    NdisCloseConfiguration();
  }
LAB_1c000528e:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
              &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,param_1,(char)local_res18[0]);
  }
  return local_res18[0];
}



===== implatCheckAdapterOffloadParameters @ 1c00052ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* int __cdecl implatCheckAdapterOffloadParameters(struct _IMPLAT_ADAPTER * __ptr64) */

int __cdecl implatCheckAdapterOffloadParameters(_IMPLAT_ADAPTER *param_1)

{
  _IMPLAT_ADAPTER _Var1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  undefined1 auStackY_a8 [32];
  undefined2 local_68;
  undefined1 local_66;
  undefined4 local_60;
  uint uStack_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar2 = *(longlong *)(param_1 + 0x28);
  local_68 = 0;
  local_66 = 0;
  iVar6 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  KeWaitForSingleObject(lVar2 + 0x90,0,0,0);
  NdisAcquireRWLockWrite(*(undefined8 *)(lVar2 + 0x88),&local_68,0);
  uVar3 = local_48;
  if (((uint)(byte)param_1[0x31c] == *(uint *)(lVar2 + 0x290)) ||
     (param_1[0x1d8] == (_IMPLAT_ADAPTER)0x0)) {
    _Var1 = param_1[0x31d];
    if (((uint)(byte)_Var1 == *(uint *)(lVar2 + 0x2b0)) || (param_1[0x1d9] == (_IMPLAT_ADAPTER)0x0))
    goto LAB_1c00054ac;
  }
  else {
    _Var1 = param_1[0x31d];
  }
  local_58 = CONCAT44(local_58._4_4_,0x1a0380);
  local_48 = CONCAT44(local_48._4_4_,1);
  uVar4 = local_48;
  if (((uint)(byte)param_1[0x31c] != *(uint *)(lVar2 + 0x290)) &&
     (param_1[0x1d8] != (_IMPLAT_ADAPTER)0x0)) {
    local_48._7_1_ = SUB81(uVar3,7);
    local_48._0_7_ = CONCAT16((*(uint *)(lVar2 + 0x290) != 0) + '\x01',(int6)uVar4);
  }
  if (((uint)(byte)_Var1 != *(uint *)(lVar2 + 0x2b0)) && (param_1[0x1d9] != (_IMPLAT_ADAPTER)0x0)) {
    local_48 = CONCAT17((*(uint *)(lVar2 + 0x2b0) != 0) + '\x01',(undefined7)local_48);
  }
  NdisReleaseRWLock(*(undefined8 *)(lVar2 + 0x88),&local_68);
  iVar6 = implatDoOidRequestOnAdapter
                    (param_1,1,0xfc01020c,&local_58,0x20,(_NDIS_OID_REQUEST *)0x0,
                     (_IMPLAT_VIRTMINI *)0x0);
  if (iVar6 != 0) {
    if ((local_48._6_1_ == '\x01') || (local_48._7_1_ == '\x01')) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0 &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
                  &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,param_1,(char)iVar6);
      }
    }
    else {
      iVar6 = 0;
    }
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(lVar2 + 0x88),&local_68,0);
LAB_1c00054ac:
  if ((*(uint *)(param_1 + 0x27c) & 1) != 0) {
    bVar5 = ~(byte)param_1[0x280];
    if ((bVar5 & 1) != *(uint *)(lVar2 + 0x2f0)) {
      local_60 = 0x80180;
      uStack_5c = (uint)((bVar5 & 1) == 0);
      NdisReleaseRWLock(*(undefined8 *)(lVar2 + 0x88),&local_68);
      iVar7 = implatDoOidRequestOnAdapter
                        (param_1,1,0x1021e,&local_60,8,(_NDIS_OID_REQUEST *)0x0,
                         (_IMPLAT_VIRTMINI *)0x0);
      if (iVar7 != 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
                     &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,param_1,(char)iVar7,bVar5 & 1)
          ;
        }
        if ((bVar5 & 1) != 0) {
          iVar6 = iVar7;
        }
      }
      NdisAcquireRWLockWrite(*(undefined8 *)(lVar2 + 0x88),&local_68,0);
    }
  }
  if ((*(longlong *)(param_1 + 0x1dc) != 0) &&
     (((uint)(*(longlong *)(param_1 + 800) != 0) != *(uint *)(lVar2 + 0x2d0) ||
      ((((byte)param_1[0x1af0] ^ *(byte *)(lVar2 + 0xe8)) & 1) != 0)))) {
    uStack_50 = 0;
    local_58 = 0x1a0380;
    local_48 = 1;
    if ((*(byte *)(lVar2 + 0xe8) & 1) == 0) {
      uStack_40 = 2;
    }
    else {
      uStack_40 = 0x101;
    }
    NdisReleaseRWLock(*(undefined8 *)(lVar2 + 0x88),&local_68);
    iVar7 = implatDoOidRequestOnAdapter
                      (param_1,1,0xfc01020c,&local_58,0x20,(_NDIS_OID_REQUEST *)0x0,
                       (_IMPLAT_VIRTMINI *)0x0);
    if (iVar7 == 0) {
      param_1[0x1af0] = (_IMPLAT_ADAPTER)((byte)param_1[0x1af0] & 0xfe | (char)uStack_40 == '\x01');
    }
    else {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
                  &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,param_1,(char)iVar7);
      }
      iVar6 = iVar7;
    }
    NdisAcquireRWLockWrite(*(undefined8 *)(lVar2 + 0x88),&local_68,0);
  }
  NdisReleaseRWLock(*(undefined8 *)(lVar2 + 0x88),&local_68);
  KeReleaseMutex(lVar2 + 0x90,0);
  return iVar6;
}



===== implatCloseAdapter @ 1c0005714 =====

/* void __cdecl implatCloseAdapter(struct _IMPLAT_ADAPTER * __ptr64) */

void __cdecl implatCloseAdapter(_IMPLAT_ADAPTER *param_1)

{
  int iVar1;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
             &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,param_1);
  }
  implatWaitForOutstandingRequestsOnAdapter(param_1,'\x01','\x01');
  KeClearEvent(param_1 + 0x30);
  iVar1 = NdisCloseAdapterEx(*(undefined8 *)(param_1 + 0x20));
  if (iVar1 == 0x103) {
    KeWaitForSingleObject(param_1 + 0x30,0,0,0,0);
  }
  *(undefined8 *)(param_1 + 0x20) = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
             &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,param_1);
  }
  return;
}



===== implatCloseAdapterCompleteEx @ 1c0005800 =====

/* void __cdecl implatCloseAdapterCompleteEx(void * __ptr64) */

void __cdecl implatCloseAdapterCompleteEx(void *param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
             &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,param_1);
  }
  KeSetEvent((longlong)param_1 + 0x30,0,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
             &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,param_1);
  }
  return;
}



===== implatOpenAdapterCompleteEx @ 1c00058a0 =====

/* void __cdecl implatOpenAdapterCompleteEx(void * __ptr64,int) */

void __cdecl implatOpenAdapterCompleteEx(void *param_1,int param_2)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
              &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,param_1,(char)param_2);
  }
  *(int *)((longlong)param_1 + 0x48) = param_2;
  KeSetEvent((longlong)param_1 + 0x30,0,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
              &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,param_1,(char)param_2);
  }
  return;
}



===== implatUnbindAdapterEx @ 1c0005960 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* int __cdecl implatUnbindAdapterEx(void * __ptr64,void * __ptr64) */

int __cdecl implatUnbindAdapterEx(void *param_1,void *param_2)

{
  int *piVar1;
  longlong *plVar2;
  code *pcVar3;
  int iVar4;
  undefined8 *puVar5;
  _tlgProvider_t *p_Var6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  char *pcVar10;
  _GUID *p_Var11;
  ulonglong uVar12;
  _GUID *p_Var13;
  undefined1 auStackY_88 [32];
  undefined2 local_58;
  undefined1 local_56;
  undefined4 local_54;
  undefined4 *local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  local_38 = *(undefined4 *)((longlong)param_2 + 0xb4);
  uStack_34 = *(undefined4 *)((longlong)param_2 + 0xb8);
  uStack_30 = *(undefined4 *)((longlong)param_2 + 0xbc);
  uStack_2c = *(undefined4 *)((longlong)param_2 + 0xc0);
  local_56 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
             &WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,param_2);
  }
  KeSetEvent((longlong)param_2 + 0x100,0);
  IPsecLbfoOffloadMapWaitForIdleAndAcquireExclusiveTeamLock
            (*(longlong *)((longlong)param_2 + 0x28),&local_58);
  lVar9 = *(longlong *)(*(longlong *)((longlong)param_2 + 0x28) + 0x438);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) != 0)) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
             &WPP_4c7e1387f9ea3c086637b58d47ad9570_Traceguids,param_2);
  }
  if (lVar9 != 0) {
    for (puVar5 = *(undefined8 **)((longlong)param_2 + 0x220); (void *)puVar5[-2] != param_2;
        puVar5 = (undefined8 *)*puVar5) {
    }
    uVar12 = (ulonglong)*(uint *)(puVar5 + 10);
    uVar8 = 0;
    if (*(int *)(lVar9 + 0x10) != 0) {
      do {
        pcVar10 = (char *)(uVar8 * 0x610 + *(longlong *)(lVar9 + 0x18));
        if ((*pcVar10 != '\0') &&
           (pcVar10[1] = '\x01', *(longlong *)(pcVar10 + uVar12 * 0x18 + 0x18) != 0)) {
          pcVar10[uVar12 * 0x18 + 0x10] = '\x01';
          *(undefined4 *)(uVar12 * 0x38 + 0x50 + lVar9) = *(undefined4 *)(lVar9 + 8);
        }
        uVar7 = (int)uVar8 + 1;
        uVar8 = (ulonglong)uVar7;
      } while (uVar7 < *(uint *)(lVar9 + 0x10));
    }
  }
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_2 + 0x28) + 0x88),&local_58);
  lVar9 = *(longlong *)(*(longlong *)((longlong)param_2 + 0x28) + 0x438);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0xc & 1) != 0)) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_4c7e1387f9ea3c086637b58d47ad9570_Traceguids,param_2);
  }
  if (lVar9 != 0) {
    for (puVar5 = *(undefined8 **)((longlong)param_2 + 0x220); (void *)puVar5[-2] != param_2;
        puVar5 = (undefined8 *)*puVar5) {
    }
    lVar9 = lVar9 + (ulonglong)*(uint *)(puVar5 + 10) * 0x38;
    KeClearEvent(lVar9 + 0x38);
    while (0 < *(int *)(lVar9 + 0x50)) {
      *(undefined4 *)(lVar9 + 0x58) = 1;
      IPsecLbfopAdapterRemove((longlong)param_2,*(uint *)(puVar5 + 10),(longlong *)(lVar9 + 0x28));
      LOCK();
      piVar1 = (int *)(lVar9 + 0x58);
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      if (iVar4 == 1) {
        *(int *)(lVar9 + 0x50) = *(int *)(lVar9 + 0x50) - *(int *)(lVar9 + 0x54);
      }
      else {
        KeWaitForSingleObject(lVar9 + 0x38,0);
      }
    }
    if (*(longlong *)(lVar9 + 0x28) != 0) {
      ExFreePoolWithTag(*(longlong *)(lVar9 + 0x28),0);
    }
    *(undefined8 *)(lVar9 + 0x28) = 0;
    *(undefined8 *)(lVar9 + 0x30) = 0;
    *(undefined8 *)(lVar9 + 0x38) = 0;
    *(undefined8 *)(lVar9 + 0x40) = 0;
    *(undefined8 *)(lVar9 + 0x48) = 0;
    *(undefined8 *)(lVar9 + 0x50) = 0;
    *(undefined8 *)(lVar9 + 0x58) = 0;
    IPsecLbfopSignalUploadOfExistingSAs(*(longlong *)((longlong)param_2 + 0x28));
  }
  implatIncreaseGlobalPendingOperationsCount();
  p_Var13 = (_GUID *)0x0;
  KeWaitForSingleObject(*(longlong *)((longlong)param_2 + 0x28) + 0x118,0);
  *(undefined1 *)((longlong)param_2 + 0x250) = 1;
  for (puVar5 = *(undefined8 **)((longlong)param_2 + 0x238);
      puVar5 != (undefined8 *)((longlong)param_2 + 0x238); puVar5 = (undefined8 *)*puVar5) {
    implatFreePort((_IMPLAT_INTERNAL_BINDING *)(puVar5 + -2));
  }
  KeReleaseMutex(*(longlong *)((longlong)param_2 + 0x28) + 0x118,0);
  implatDecreaseGlobalPendingOperationsCount();
  implatWaitForGlobalMutexAndPendingOperationsCount();
  RtlInitUnicodeString(&local_48,L"");
  implatCheckAdapterInternalBindings(param_2,(_UNICODE_STRING *)&local_48);
  lVar9 = *(longlong *)param_2;
  plVar2 = *(longlong **)((longlong)param_2 + 8);
  if ((*(void **)(lVar9 + 8) != param_2) || ((void *)*plVar2 != param_2)) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    iVar4 = (*pcVar3)();
    return iVar4;
  }
  *plVar2 = lVar9;
  *(longlong **)(lVar9 + 8) = plVar2;
  NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)((longlong)param_2 + 0x28) + 0x88),&local_58);
  *(undefined4 *)((longlong)param_2 + 0xf0) = 2;
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_2 + 0x28) + 0x88),&local_58);
  KeReleaseMutex(&DAT_1c001b1f0,0);
  implatCloseAdapter(param_2);
  p_Var11 = (_GUID *)0x0;
  NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)((longlong)param_2 + 0x28) + 0x88),&local_58);
  *(undefined4 *)((longlong)param_2 + 0xf0) = 0;
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_2 + 0x28) + 0x88),&local_58);
  implatWaitForMutex((_KMUTANT *)&DAT_1c001b1f0);
  if (*(longlong *)((longlong)param_2 + 0x28) != 0) {
    implatRemoveAdapterFromTeam(param_2);
  }
  KeReleaseMutex(&DAT_1c001b1f0,0);
  if (*(longlong *)((longlong)param_2 + 0x248) != 0) {
    RtlDeleteHashTable();
    *(undefined8 *)((longlong)param_2 + 0x248) = 0;
  }
  lVar9 = *(longlong *)((longlong)param_2 + 0x1c98);
  if (lVar9 != 0) {
    ExFreePoolWithTag(lVar9,0x5156544e);
  }
  if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
    p_Var13 = *(_GUID **)((longlong)param_2 + 0x58);
    p_Var11 = (_GUID *)0x0;
    McTemplateK0z_EtwWriteTransfer(lVar9,&UnbindingFromMemberInfo,0,(wchar_t *)p_Var13);
  }
  ExFreePoolWithTag(param_2,0x6c506d49);
  p_Var6 = (_tlgProvider_t *)WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    p_Var6 = *(_tlgProvider_t **)(WPP_GLOBAL_Control + 0x18);
    p_Var11 = (_GUID *)&WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids;
    p_Var13 = (_GUID *)0x0;
    WPP_SF_D(p_Var6,0x1e,&WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,0);
  }
  if (5 < DAT_1c001b0a0) {
    local_54 = 0;
    local_50 = &local_38;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<4>_>
              (p_Var6,&DAT_1c0019129,p_Var11,p_Var13,(_tlgWrapperByRef<16> *)&local_50,
               (_tlgWrapperByVal<4> *)&local_54);
  }
  return 0;
}



===== implatWaitForOutstandingRequestsOnAdapter @ 1c0005e48 =====

/* void __cdecl implatWaitForOutstandingRequestsOnAdapter(struct _IMPLAT_ADAPTER * __ptr64,unsigned
   char,unsigned char) */

void __cdecl
implatWaitForOutstandingRequestsOnAdapter(_IMPLAT_ADAPTER *param_1,uchar param_2,uchar param_3)

{
  int iVar1;
  int *piVar2;
  ulonglong uVar3;
  
  KeFlushQueuedDpcs();
  do {
    uVar3 = (ulonglong)DAT_1c001b278;
    iVar1 = 0;
    if (DAT_1c001b278 == 0) {
LAB_1c0005e97:
      if (((param_2 == '\0') || (*(int *)(param_1 + 0x260) == 0)) &&
         ((param_3 == '\0' || (*(int *)(param_1 + 0x264) == 0)))) {
        return;
      }
    }
    else {
      piVar2 = *(int **)(param_1 + 600);
      do {
        iVar1 = iVar1 + *piVar2;
        piVar2 = piVar2 + 0x30;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
      if (iVar1 == 0) goto LAB_1c0005e97;
    }
    NdisMSleep(0x32);
  } while( true );
}



===== McTemplateK0z_EtwWriteTransfer @ 1c0005ee0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0z_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4)

{
  longlong lVar1;
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  if (param_4 == (wchar_t *)0x0) {
    local_20 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  local_1c = 0;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  local_28 = param_4;
  McGenEventWrite_EtwWriteTransfer(L"NULL",param_2,param_3,2,local_38);
  return;
}



===== WPP_SF_Sd @ 1c0005f64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Sd(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

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
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,0x1a,param_4,lVar1,
             &param_5,4,0);
  return;
}



===== WPP_SF_Z @ 1c0005ff0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Z(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_4;
    if (*param_4 != L'\0') {
      pwVar2 = *(wchar_t **)(param_4 + 4);
      goto LAB_1c000601f;
    }
  }
  pwVar2 = L"NULL";
LAB_1c000601f:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_2aed13cf02be3050cc68199ecfb64f81_Traceguids,10,param_4,2,pwVar2,wVar1
             ,0);
  return;
}



===== WPP_SF_qd @ 1c0006074 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== WPP_SF_qdd @ 1c00060c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,&param_6,4,0);
  return;
}



===== vmqcIssueOidRequest @ 1c0006128 =====

int vmqcIssueOidRequest(longlong param_1,ulong param_2,_NDIS_REQUEST_TYPE param_3,void *param_4,
                       uint param_5)

{
  int iVar1;
  
  if ((param_2 - 0x1022d & 0xfffffffd) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = implatDoOidRequestOnAdapter
                      ((_IMPLAT_ADAPTER *)(param_1 + -0x1af8),param_3,param_2,param_4,param_5,
                       (_NDIS_OID_REQUEST *)0x0,(_IMPLAT_VIRTMINI *)0x0);
  }
  return iVar1;
}



===== implatCalculateVirtMiniCapabilities @ 1c0006174 =====

/* int __cdecl implatCalculateVirtMiniCapabilities(struct _IMPLAT_VIRTMINI * __ptr64) */

int __cdecl implatCalculateVirtMiniCapabilities(_IMPLAT_VIRTMINI *param_1)

{
  _IMPLAT_VIRTMINI *p_Var1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  uint uVar4;
  _IMPLAT_TEAM *p_Var5;
  longlong lVar6;
  undefined8 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  longlong lVar14;
  _IMPLAT_VIRTMINI *p_Var15;
  longlong lVar16;
  longlong lVar17;
  uint uVar18;
  uint uVar19;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88),&local_res8,0);
  lVar17 = 0;
  param_1[0x710] = (_IMPLAT_VIRTMINI)0x1;
  uVar9 = 0x5ea;
  *(undefined8 *)(param_1 + 0x728) = 0;
  uVar10 = 0x24c;
  *(undefined4 *)(param_1 + 0x720) = 0x5ea;
  uVar13 = 1000;
  *(undefined8 *)(param_1 + 0x730) = 0;
  uVar19 = 0x2f;
  *(undefined4 *)(param_1 + 0x738) = 0x24c;
  *(undefined4 *)(param_1 + 0x73c) = 0x2f;
  *(undefined8 *)(param_1 + 0x740) = 1000;
  *(undefined4 *)(param_1 + 0x748) = 0;
  *(undefined4 *)(param_1 + 0x8f8) = 0x1c0180;
  if (*(int *)(param_1 + 0x5c8) != 0) {
    *(undefined4 *)(param_1 + 0x8fc) = 0xf;
    *(undefined4 *)(param_1 + 0x900) = 0xf;
  }
  p_Var5 = *(_IMPLAT_TEAM **)(param_1 + 0x48);
  p_Var1 = param_1 + 0x60;
  p_Var15 = *(_IMPLAT_VIRTMINI **)p_Var1;
  *(undefined4 *)(param_1 + 0x768) = 0x5ea;
  *(undefined4 *)(param_1 + 0x711) = *(undefined4 *)(p_Var5 + 0xe9);
  *(undefined2 *)(param_1 + 0x715) = *(undefined2 *)(p_Var5 + 0xed);
  if (p_Var15 != p_Var1) {
    uVar12 = 0;
    uVar11 = 0;
    uVar18 = 0x5ea;
    lVar16 = 0;
    do {
      lVar14 = *(longlong *)(p_Var15 + -0x20);
      uVar4 = *(uint *)(lVar14 + 0x68);
      if ((uVar4 < uVar9) || (p_Var15 == *(_IMPLAT_VIRTMINI **)p_Var1)) {
        *(uint *)(param_1 + 0x720) = uVar4;
        uVar9 = uVar4;
      }
      uVar4 = *(uint *)(lVar14 + 0x84);
      if (uVar4 < uVar13) {
        *(uint *)(param_1 + 0x740) = uVar4;
        uVar13 = uVar4;
      }
      uVar4 = *(uint *)(lVar14 + 0x88);
      if (uVar12 < uVar4) {
        *(uint *)(param_1 + 0x744) = uVar4;
        uVar12 = uVar4;
      }
      uVar4 = *(uint *)(lVar14 + 0x8c);
      if (uVar11 < uVar4) {
        *(uint *)(param_1 + 0x748) = uVar4;
        uVar11 = uVar4;
      }
      uVar4 = *(uint *)(lVar14 + 0x268);
      if (uVar4 < uVar18) {
        *(uint *)(param_1 + 0x768) = uVar4;
        uVar18 = uVar4;
      }
      lVar16 = lVar16 + *(longlong *)(lVar14 + 0x70);
      *(longlong *)(param_1 + 0x728) = lVar16;
      lVar17 = lVar17 + *(longlong *)(lVar14 + 0x78);
      *(longlong *)(param_1 + 0x730) = lVar17;
      uVar10 = uVar10 & *(uint *)(lVar14 + 0x90);
      *(uint *)(param_1 + 0x738) = uVar10;
      uVar19 = uVar19 & *(uint *)(lVar14 + 0x80);
      *(uint *)(param_1 + 0x73c) = uVar19;
      p_Var15 = *(_IMPLAT_VIRTMINI **)p_Var15;
    } while (p_Var15 != p_Var1);
  }
  *(uint *)(param_1 + 0x738) = uVar10 | 0xc;
  iVar8 = implatRecalculateTeamOffloadCapabilities(p_Var5,(_LOCK_STATE_EX *)&local_res8);
  if (iVar8 == 0) {
    implatTaskOffloadRecalculateAndIndicateChange(param_1);
    param_1[0x424] = param_1[0x608];
    param_1[0x426] = param_1[0x648];
    implatCalculateVmqCaps(param_1,'\0');
    if ((param_1[0x444] != (_IMPLAT_VIRTMINI)0x0) && (*(int *)(param_1 + 0x440) == 0)) {
      lVar17 = *(longlong *)(param_1 + 0x48);
      lVar14 = 4;
      lVar16 = 0x240;
      do {
        lVar6 = *(longlong *)(lVar17 + 0x150);
        puVar2 = (undefined8 *)(lVar16 + 0x450 + lVar6);
        uVar7 = puVar2[1];
        puVar3 = (undefined8 *)(lVar16 + 0x178 + lVar17);
        *puVar3 = *puVar2;
        puVar3[1] = uVar7;
        puVar2 = (undefined8 *)(lVar16 + 0x460 + lVar6);
        uVar7 = puVar2[1];
        puVar3 = (undefined8 *)(lVar16 + 0x188 + lVar17);
        *puVar3 = *puVar2;
        puVar3[1] = uVar7;
        lVar14 = lVar14 + -1;
        lVar16 = lVar16 + 0x20;
      } while (lVar14 != 0);
      implatRecalculatePMCapabilities(*(_IMPLAT_TEAM **)(param_1 + 0x48));
    }
  }
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88),&local_res8);
  implatWaitForPendingAdapterUnbinds(*(_IMPLAT_TEAM **)(param_1 + 0x48));
  return iVar8;
}



===== implatCalculateVirtMiniLinkState @ 1c0006404 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl implatCalculateVirtMiniLinkState(struct _IMPLAT_VIRTMINI * __ptr64) */

void __cdecl implatCalculateVirtMiniLinkState(_IMPLAT_VIRTMINI *param_1)

{
  _IMPLAT_VIRTMINI *p_Var1;
  longlong lVar2;
  longlong lVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong lVar9;
  uint uVar10;
  longlong lVar11;
  undefined *puVar12;
  int iVar13;
  uint uVar14;
  _IMPLAT_VIRTMINI *p_Var15;
  undefined1 auStackY_d8 [32];
  undefined4 local_a8 [2];
  undefined8 local_a0;
  undefined4 local_98;
  undefined8 local_94;
  undefined8 local_88;
  undefined8 uStack_80;
  _IMPLAT_VIRTMINI *local_78;
  undefined4 local_70;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_d8;
  p_Var1 = param_1 + 0x60;
  p_Var15 = *(_IMPLAT_VIRTMINI **)p_Var1;
  uVar14 = 2;
  iVar13 = 0;
  lVar11 = 0;
  lVar9 = 0;
  uVar10 = 0;
  bVar6 = false;
  bVar5 = false;
  bVar4 = false;
  if (p_Var15 != p_Var1) {
    do {
      lVar2 = *(longlong *)(p_Var15 + -0x20);
      if (*(int *)(lVar2 + 0xcc) == 1) {
        lVar3 = *(longlong *)(lVar2 + 0xe0);
        uVar14 = 1;
        bVar4 = bVar5;
        if (lVar3 == -1) {
          bVar4 = true;
        }
        lVar7 = lVar3 + lVar11;
        if (lVar3 == -1) {
          lVar7 = lVar11;
        }
        lVar11 = lVar7;
        bVar5 = bVar4;
        if (*(longlong *)(lVar2 + 0xd8) == -1) {
          bVar6 = true;
        }
        else {
          lVar9 = lVar9 + *(longlong *)(lVar2 + 0xd8);
        }
      }
      else if (uVar14 != 1) {
        uVar14 = uVar14 & -(uint)(*(int *)(lVar2 + 0xcc) != 0);
      }
      if (*(int *)(lVar2 + 0xd0) == 2) {
        iVar13 = 2;
      }
      else if ((*(int *)(lVar2 + 0xd0) == 1) && (iVar13 != 2)) {
        iVar13 = 1;
      }
      uVar10 = uVar10 | *(uint *)(lVar2 + 0xec);
      p_Var15 = *(_IMPLAT_VIRTMINI **)p_Var15;
    } while (p_Var15 != p_Var1);
    if (uVar14 == 1) {
      if ((lVar11 == 0) && (bVar4)) {
        lVar11 = -1;
      }
      if ((lVar9 == 0) && (bVar6)) {
        lVar9 = -1;
      }
    }
  }
  if ((((uVar14 != *(uint *)(param_1 + 0xa4)) || (iVar13 != *(int *)(param_1 + 0xa8))) ||
      (lVar11 != *(longlong *)(param_1 + 0xb8))) ||
     ((lVar9 != *(longlong *)(param_1 + 0xb0) || (uVar10 != *(uint *)(param_1 + 0xc4))))) {
    *(uint *)(param_1 + 0xa4) = uVar14;
    *(int *)(param_1 + 0xa8) = iVar13;
    *(longlong *)(param_1 + 0xb8) = lVar11;
    *(longlong *)(param_1 + 0xb0) = lVar9;
    *(uint *)(param_1 + 0xc4) = uVar10;
    param_1[0xe8] = (_IMPLAT_VIRTMINI)0x0;
  }
  if ((param_1[0xe8] == (_IMPLAT_VIRTMINI)0x0) && (2 < *(int *)(param_1 + 200))) {
    puVar12 = (undefined *)0x70;
    memset(local_a8,0,0x70);
    local_a0 = *(undefined8 *)(param_1 + 0x20);
    local_78 = param_1 + 0xa0;
    local_a8[0] = 0x700198;
    local_98 = 0;
    local_94 = 0x40010017;
    local_70 = 0x28;
    local_88 = 0;
    uStack_80 = 0;
    param_1[0xe8] = (_IMPLAT_VIRTMINI)0x1;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0 && (4 < (byte)WPP_GLOBAL_Control[0x29]))
       )) {
      puVar12 = &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids;
      WPP_SF_DL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,*(undefined4 *)(param_1 + 0x74c),
                (char)*(undefined4 *)(param_1 + 0xa4));
    }
    uVar8 = *(undefined8 *)(param_1 + 0x20);
    NdisMIndicateStatusEx(uVar8,local_a8);
    if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
      McTemplateK0zqbr1_EtwWriteTransfer
                (uVar8,&TNicLinkStateChangeInfo,puVar12,*(wchar_t **)(param_1 + 0x30),local_70,
                 local_78);
    }
  }
  return;
}



===== implatCalculateVmqCaps @ 1c0006688 =====

/* void __cdecl implatCalculateVmqCaps(struct _IMPLAT_VIRTMINI * __ptr64,unsigned char) */

void __cdecl implatCalculateVmqCaps(_IMPLAT_VIRTMINI *param_1,uchar param_2)

{
  _IMPLAT_VIRTMINI *p_Var1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  _IMPLAT_VIRTMINI *p_Var6;
  undefined8 local_1a8;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined8 local_180;
  undefined4 local_178;
  undefined4 local_174;
  undefined8 local_150;
  uint local_148;
  uint local_144;
  uint local_140;
  undefined8 local_13c;
  undefined1 local_e0 [4];
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 local_88;
  uint local_80;
  uint local_7c;
  uint local_78;
  undefined8 local_74;
  
  memset(&local_1a8,0,400);
  if (param_1[0x444] != (_IMPLAT_VIRTMINI)0x0) {
    vmqClearCapabilities((undefined4 *)&local_1a8);
    p_Var1 = param_1 + 0x60;
    p_Var6 = *(_IMPLAT_VIRTMINI **)p_Var1;
    if (p_Var6 != p_Var1) {
      local_dc = 0;
      local_ac = 0xffffffff;
      local_d8 = 1;
      local_d4 = 1;
      local_c4 = 1;
      local_c8 = 3;
      local_c0 = 0x1f;
      local_cc = 0x7f;
      local_bc = 0xffffffff;
      local_d0 = 0xffffffff;
      local_7c = 0xffffffff;
      local_78 = 0xffffffff;
      local_80 = 0xffffffff;
      local_1a0 = 1;
      local_19c = 1;
      local_18c = 1;
      local_190 = 3;
      local_188 = 0x1f;
      local_174 = 0xffffffff;
      local_194 = 0x7f;
      local_184 = 0xffffffff;
      local_198 = 0xffffffff;
      local_144 = 0xffffffff;
      local_140 = 0xffffffff;
      local_148 = 0xffffffff;
      local_b8 = 0;
      local_b0 = 0;
      local_88 = 0;
      local_74 = 0;
      local_1a8._4_4_ = 0;
      local_180 = 0;
      local_178 = 0;
      local_150 = 0;
      local_13c = 0;
      do {
        lVar2 = *(longlong *)(p_Var6 + -0x20);
        vmqUpdateRcvFilterCaps((longlong)local_e0,lVar2 + 0x1bc8);
        uVar3 = *(uint *)(lVar2 + 0x1c28);
        if (local_80 < *(uint *)(lVar2 + 0x1c28)) {
          uVar3 = local_80;
        }
        uVar4 = *(uint *)(lVar2 + 0x1c2c);
        if (local_7c < *(uint *)(lVar2 + 0x1c2c)) {
          uVar4 = local_7c;
        }
        uVar5 = *(uint *)(lVar2 + 0x1c30);
        if (local_78 < *(uint *)(lVar2 + 0x1c30)) {
          uVar5 = local_78;
        }
        local_80 = uVar3;
        local_7c = uVar4;
        local_78 = uVar5;
        vmqUpdateRcvFilterCaps((longlong)&local_1a8,lVar2 + 0x1b00);
        p_Var6 = *(_IMPLAT_VIRTMINI **)p_Var6;
        uVar3 = *(uint *)(lVar2 + 0x1b60);
        if (local_148 < *(uint *)(lVar2 + 0x1b60)) {
          uVar3 = local_148;
        }
        uVar4 = *(uint *)(lVar2 + 0x1b64);
        if (local_144 < *(uint *)(lVar2 + 0x1b64)) {
          uVar4 = local_144;
        }
        uVar5 = *(uint *)(lVar2 + 0x1b68);
        if (local_140 < *(uint *)(lVar2 + 0x1b68)) {
          uVar5 = local_140;
        }
        local_148 = uVar3;
        local_144 = uVar4;
        local_140 = uVar5;
      } while (p_Var6 != p_Var1);
    }
    vmqSetNewCapabilities((longlong)(param_1 + 0xf8),&local_1a8,param_2,param_2);
  }
  return;
}



===== implatCreateVirtualMiniport @ 1c000684c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* int __cdecl implatCreateVirtualMiniport(struct _IMPLAT_VIRTMINI * __ptr64 * __ptr64,struct
   _UNICODE_STRING * __ptr64,struct _IMPLAT_TEAM * __ptr64) */

int __cdecl
implatCreateVirtualMiniport
          (_IMPLAT_VIRTMINI **param_1,_UNICODE_STRING *param_2,_IMPLAT_TEAM *param_3)

{
  _IMPLAT_VIRTMINI *p_Var1;
  wchar_t *pwVar2;
  ushort *puVar3;
  code *pcVar4;
  char cVar5;
  int iVar6;
  _IMPLAT_VIRTMINI *p_Var7;
  _IMPLAT_VIRTMINI *p_Var8;
  _tlgProvider_t *p_Var9;
  ulong uVar10;
  undefined *puVar11;
  undefined1 *puVar12;
  ulonglong _Size;
  uint uVar13;
  _IMPLAT_TEAM *p_Var14;
  _GUID *p_Var15;
  _GUID *p_Var16;
  undefined1 auStackY_e8 [8];
  undefined1 auStackY_e0 [24];
  uint local_b8;
  uint local_b4;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  longlong local_80 [2];
  wchar_t *local_70;
  longlong local_68;
  wchar_t *local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_68 = 0x220020;
  local_a0 = 0;
  local_88 = 0;
  local_80[0] = 0;
  local_60 = L"NumberOfAdapters";
  local_80[1] = 0x220020;
  local_70 = L"VirtualMiniports";
  local_b8 = 0;
  local_a8 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_b0 = 0;
  local_50 = 0;
  uStack_48 = 0;
  puVar11 = WPP_GLOBAL_Control;
  p_Var14 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar11 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    p_Var14 = (_IMPLAT_TEAM *)&WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids;
    WPP_SF_(puVar11,10,&WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids);
  }
  if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
    McTemplateK0zzd_EtwWriteTransfer
              (puVar11,&CreatingTeamNicInfo,p_Var14,*(wchar_t **)(param_3 + 0x28),
               *(wchar_t **)(param_2 + 8),(char)local_b8);
  }
  uVar10 = (ulong)&local_50;
  iVar6 = RtlGUIDFromString(param_2);
  if (iVar6 < 0) {
    local_50 = 0;
    uStack_48 = 0;
  }
  p_Var15 = (_GUID *)0x0;
  _Size = (ulonglong)((uint)*(ushort *)(param_2 + 2) + DAT_1c001b278 * 0xc0 + 0x20c9) & 0xffffffc0;
  p_Var7 = implatAllocateNonPagedPoolWithTagPriority(_Size,uVar10,0);
  *param_1 = p_Var7;
  if (p_Var7 == (_IMPLAT_VIRTMINI *)0x0) {
    p_Var8 = (_IMPLAT_VIRTMINI *)WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      p_Var8 = *(_IMPLAT_VIRTMINI **)(WPP_GLOBAL_Control + 0x18);
      p_Var15 = (_GUID *)&WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids;
      WPP_SF_(p_Var8,0xb,&WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids);
    }
    puVar12 = auStackY_e8;
    local_b8 = 0xc000009a;
  }
  else {
    memset(p_Var7,0,_Size);
    *(undefined4 *)(*param_1 + 200) = 0;
    (*param_1)[0xa0] = (_IMPLAT_VIRTMINI)0x80;
    *(undefined2 *)(*param_1 + 0xa2) = 0x28;
    (*param_1)[0xa1] = (_IMPLAT_VIRTMINI)0x1;
    *(undefined4 *)(*param_1 + 0xa4) = 0;
    *(undefined4 *)(*param_1 + 0xa8) = 0;
    *(undefined8 *)(*param_1 + 0xb0) = 0;
    *(undefined8 *)(*param_1 + 0xb8) = 0;
    *(undefined4 *)(*param_1 + 0xc0) = 0;
    *(undefined4 *)(*param_1 + 0xc4) = 0;
    *(_IMPLAT_VIRTMINI **)(*param_1 + 0x30) = *param_1 + 0x2088;
    *(undefined2 *)(*param_1 + 0x28) = *(undefined2 *)param_2;
    *(undefined2 *)(*param_1 + 0x2a) = *(undefined2 *)(param_2 + 2);
    memcpy(*(void **)(*param_1 + 0x30),*(void **)(param_2 + 8),(ulonglong)*(ushort *)param_2);
    *(undefined2 *)(*(longlong *)(*param_1 + 0x30) + (ulonglong)(*(ushort *)param_2 >> 1) * 2) = 0;
    p_Var7 = *param_1;
    *(undefined4 *)(p_Var7 + 0x38) = (undefined4)local_50;
    *(undefined4 *)(p_Var7 + 0x3c) = local_50._4_4_;
    *(undefined4 *)(p_Var7 + 0x40) = (undefined4)uStack_48;
    *(undefined4 *)(p_Var7 + 0x44) = uStack_48._4_4_;
    *(ulonglong *)(*param_1 + 0xf0) =
         (ulonglong)(*param_1 + (ulonglong)*(ushort *)(param_2 + 2) + 0x20c9) & 0xffffffffffffffc0;
    KeInitializeEvent(*param_1 + 0xd0,0);
    KeInitializeEvent(*param_1 + 0x80,0);
    uStack_90 = _Global;
    local_98 = 0x1401a9;
    local_88 = 0;
    local_b8 = NdisOpenConfigurationEx(&local_98,&local_a0);
    if (local_b8 == 0) {
      NdisOpenConfigurationKeyByName(&local_b8,local_a0,local_80 + 1,&local_a8);
      if (local_b8 == 0) {
        NdisOpenConfigurationKeyByName(&local_b8,local_a8,param_2,&local_b0);
        if (local_b8 == 0) {
          NdisReadConfiguration(&local_b8,local_80,local_b0,local_80 + 3);
          if (local_b8 == 0) {
            *(undefined4 *)(*param_1 + 0x78) = *(undefined4 *)(local_80[0] + 8);
          }
          NdisCloseConfiguration(local_b0);
        }
        NdisCloseConfiguration(local_a8);
      }
      NdisCloseConfiguration(local_a0);
    }
    if (((*(int *)(*param_1 + 0x78) == 0) &&
        ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids);
    }
    p_Var15 = (_GUID *)0x0;
    p_Var7 = *param_1 + 0x60;
    local_b8 = 0;
    *(_IMPLAT_VIRTMINI **)(*param_1 + 0x68) = p_Var7;
    *(_IMPLAT_VIRTMINI **)p_Var7 = p_Var7;
    cVar5 = RtlCreateHashTable(*param_1 + 0x70,0);
    if (cVar5 == '\0') {
      p_Var8 = (_IMPLAT_VIRTMINI *)WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        p_Var8 = *(_IMPLAT_VIRTMINI **)(WPP_GLOBAL_Control + 0x18);
        p_Var15 = (_GUID *)&WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids;
        WPP_SF_(p_Var8,0xd,&WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids);
      }
      puVar12 = auStackY_e8;
      local_b8 = 0xc0000001;
    }
    else {
      p_Var16 = (_GUID *)*param_1;
      LOCK();
      p_Var15 = p_Var16 + 5;
      uVar10 = p_Var15->Data1;
      p_Var15->Data1 = p_Var15->Data1 + 1;
      UNLOCK();
      uVar13 = uVar10 + 1;
      p_Var15 = (_GUID *)(ulonglong)uVar13;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        p_Var15 = (_GUID *)&WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids;
        WPP_SF_qdS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                   &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,p_Var16,(char)uVar13,
                   L"CreateVirtualMiniport");
      }
      puVar12 = auStackY_e8;
      puVar11 = &DAT_1c001b258;
      p_Var7 = *param_1;
      p_Var8 = DAT_1c001b260;
      if (*(undefined **)DAT_1c001b260 != &DAT_1c001b258) {
        p_Var8 = (_IMPLAT_VIRTMINI *)0x3;
        pcVar4 = (code *)swi(0x29);
        p_Var7 = (_IMPLAT_VIRTMINI *)(*pcVar4)();
        puVar12 = auStackY_e0;
      }
      *(_IMPLAT_VIRTMINI **)(p_Var7 + 8) = p_Var8;
      *(undefined **)p_Var7 = puVar11;
      *(_IMPLAT_VIRTMINI **)p_Var8 = p_Var7;
      p_Var1 = *param_1;
      *(undefined8 *)(puVar12 + -8) = 0x1c0006ccf;
      p_Var8 = (_IMPLAT_VIRTMINI *)param_3;
      DAT_1c001b260 = p_Var7;
      implatAddVirtMiniToTeam(param_3,p_Var1);
      if (local_b8 == 0) goto LAB_1c0006d4f;
    }
  }
  if (*param_1 != (_IMPLAT_VIRTMINI *)0x0) {
    if (*(longlong *)(*param_1 + 0x70) != 0) {
      *(undefined8 *)(puVar12 + -8) = 0x1c0006ced;
      RtlDeleteHashTable();
      *(undefined8 *)(*param_1 + 0x70) = 0;
    }
    p_Var8 = *param_1;
    *(undefined8 *)(puVar12 + -8) = 0x1c0006d08;
    ExFreePoolWithTag(p_Var8,0x6c506d49);
    *param_1 = (_IMPLAT_VIRTMINI *)0x0;
  }
  if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 4) != 0) {
    pwVar2 = *(wchar_t **)(param_3 + 0x28);
    *(uint *)(puVar12 + 0x28) = local_b8;
    *(undefined8 *)(puVar12 + 0x20) = *(undefined8 *)(param_2 + 8);
    *(undefined8 *)(puVar12 + -8) = 0x1c0006d39;
    McTemplateK0zzd_EtwWriteTransfer
              (p_Var8,&CreatingTeamNicErr,p_Var15,pwVar2,*(wchar_t **)(puVar12 + 0x20),puVar12[0x28]
              );
  }
  p_Var16 = (_GUID *)(ulonglong)local_b8;
  p_Var15 = *(_GUID **)(param_3 + 0x28);
  puVar3 = *(ushort **)(param_2 + 8);
  *(undefined8 *)(puVar12 + -8) = 0x1c0006d4f;
  SysEventWriteStrStrStatus(-0x7fffbd9c,puVar3,(ushort *)p_Var15,local_b8);
LAB_1c0006d4f:
  p_Var9 = (_tlgProvider_t *)WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    p_Var9 = *(_tlgProvider_t **)(WPP_GLOBAL_Control + 0x18);
    p_Var15 = (_GUID *)&WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids;
    *(undefined8 *)(puVar12 + -8) = 0x1c0006d7c;
    WPP_SF_q(p_Var9,0xe,&WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,param_1);
    p_Var16 = (_GUID *)param_1;
  }
  if (5 < DAT_1c001b0a0) {
    local_b4 = local_b8;
    local_58 = &local_50;
    *(uint **)(puVar12 + 0x28) = &local_b4;
    *(undefined8 ***)(puVar12 + 0x20) = &local_58;
    *(undefined8 *)(puVar12 + -8) = 0x1c0006db1;
    _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
    ::Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<4>_>
              (p_Var9,&DAT_1c0019301,p_Var15,p_Var16,*(_tlgWrapperByRef<16> **)(puVar12 + 0x20),
               *(_tlgWrapperByVal<4> **)(puVar12 + 0x28));
  }
  *(undefined8 *)(puVar12 + -8) = 0x1c0006dc0;
  return local_b8;
}



===== implatDereferenceVirtualMiniport @ 1c0006de4 =====

/* void __cdecl implatDereferenceVirtualMiniport(struct _IMPLAT_VIRTMINI * __ptr64,unsigned short *
   __ptr64) */

void __cdecl implatDereferenceVirtualMiniport(_IMPLAT_VIRTMINI *param_1,ushort *param_2)

{
  _IMPLAT_VIRTMINI *p_Var1;
  int iVar2;
  
  LOCK();
  p_Var1 = param_1 + 0x50;
  iVar2 = *(int *)p_Var1;
  *(int *)p_Var1 = *(int *)p_Var1 + -1;
  UNLOCK();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qdS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,param_1,(char)(iVar2 + -1),
               (wchar_t *)param_2);
  }
  if (iVar2 + -1 == 0) {
    implatRemoveVirtualMiniport(param_1);
  }
  return;
}



===== implatFindVirtMiniByName @ 1c0006e60 =====

/* struct _IMPLAT_VIRTMINI * __ptr64 __cdecl implatFindVirtMiniByName(struct _LIST_ENTRY *
   __ptr64,struct _UNICODE_STRING * __ptr64,unsigned char,struct _IMPLAT_TEAM * __ptr64) */

_IMPLAT_VIRTMINI * __cdecl
implatFindVirtMiniByName
          (_LIST_ENTRY *param_1,_UNICODE_STRING *param_2,uchar param_3,_IMPLAT_TEAM *param_4)

{
  _IMPLAT_VIRTMINI *p_Var1;
  int iVar2;
  _IMPLAT_VIRTMINI *p_Var3;
  _IMPLAT_VIRTMINI *p_Var4;
  _IMPLAT_VIRTMINI *p_Var5;
  undefined7 in_register_00000081;
  _IMPLAT_TEAM *_Size;
  _IMPLAT_VIRTMINI *local_res8;
  
  _Size = (_IMPLAT_TEAM *)CONCAT71(in_register_00000081,param_3);
  local_res8 = (_IMPLAT_VIRTMINI *)0x0;
  p_Var3 = (_IMPLAT_VIRTMINI *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,_Size,*(wchar_t **)(param_2 + 8));
  }
  p_Var5 = *(_IMPLAT_VIRTMINI **)param_1;
  do {
    if (p_Var5 == (_IMPLAT_VIRTMINI *)param_1) {
LAB_1c0006f6b:
      if ((param_3 != '\0') &&
         (iVar2 = implatCreateVirtualMiniport(&local_res8,param_2,param_4), _Size = param_4,
         iVar2 == 0)) {
        p_Var3 = local_res8;
      }
LAB_1c0006f88:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),*(undefined8 *)(param_2 + 8),_Size,
                  p_Var3,(wchar_t *)*(undefined8 *)(param_2 + 8));
      }
      return p_Var3;
    }
    p_Var4 = p_Var5;
    if (param_1 != (_LIST_ENTRY *)&DAT_1c001b258) {
      p_Var4 = p_Var5 + -0x10;
    }
    local_res8 = p_Var4;
    if (*(ushort *)(p_Var4 + 0x28) == *(ushort *)param_2) {
      _Size = (_IMPLAT_TEAM *)(ulonglong)*(ushort *)param_2;
      iVar2 = memcmp(*(void **)(p_Var4 + 0x30),*(void **)(param_2 + 8),(size_t)_Size);
      if (iVar2 == 0) {
        LOCK();
        p_Var1 = p_Var4 + 0x50;
        iVar2 = *(int *)p_Var1;
        *(int *)p_Var1 = *(int *)p_Var1 + 1;
        UNLOCK();
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          _Size = (_IMPLAT_TEAM *)&WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids;
          WPP_SF_qdS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                     &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,p_Var4,(char)(iVar2 + 1),
                     L"FindVirtMiniByName");
        }
        if (iVar2 + 1 != 1) {
          p_Var3 = local_res8;
          if (local_res8 != (_IMPLAT_VIRTMINI *)0x0) goto LAB_1c0006f88;
          goto LAB_1c0006f6b;
        }
      }
    }
    p_Var5 = *(_IMPLAT_VIRTMINI **)p_Var5;
  } while( true );
}



===== implatHaltEx @ 1c0006ff0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl implatHaltEx(void * __ptr64,enum _NDIS_HALT_ACTION) */

void __cdecl implatHaltEx(void *param_1,_NDIS_HALT_ACTION param_2)

{
  undefined8 *puVar1;
  _IMPLAT_INTERNAL_BINDING *p_Var2;
  char *pcVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  uint uVar8;
  longlong lVar9;
  undefined1 auStackY_108 [32];
  undefined2 local_d8;
  undefined1 local_d6;
  _NDIS_HALT_ACTION local_d4;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_98 [4];
  undefined8 *local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  _NDIS_HALT_ACTION *local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_108;
  local_d8 = 0;
  local_d6 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
             &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,param_1);
  }
  local_d0 = *(undefined8 *)((longlong)param_1 + 0x750);
  uStack_c8 = *(undefined8 *)((longlong)param_1 + 0x758);
  local_b0 = *(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x10);
  uStack_a8 = *(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x18);
  local_c0 = *(undefined8 *)((longlong)param_1 + 0x38);
  uStack_b8 = *(undefined8 *)((longlong)param_1 + 0x40);
  if (*(longlong *)((longlong)param_1 + 0x430) != 0) {
    ExFreePoolWithTag(*(longlong *)((longlong)param_1 + 0x430),0x5156544e);
    *(undefined8 *)((longlong)param_1 + 0x430) = 0;
  }
  NdisIfDeleteIfStackEntry
            (*(undefined4 *)((longlong)param_1 + 0x74c),
             *(undefined4 *)(*(longlong *)((longlong)param_1 + 0x48) + 200));
  implatIncreaseGlobalPendingOperationsCount();
  KeWaitForSingleObject(*(longlong *)((longlong)param_1 + 0x48) + 0x118,0);
  puVar1 = (undefined8 *)((longlong)param_1 + 0x60);
  *(undefined1 *)((longlong)param_1 + 0x98) = 1;
  for (puVar6 = (undefined8 *)*puVar1; puVar6 != puVar1; puVar6 = (undefined8 *)*puVar6) {
    implatFreePort((_IMPLAT_INTERNAL_BINDING *)(puVar6 + -4));
  }
  KeReleaseMutex(*(longlong *)((longlong)param_1 + 0x48) + 0x118,0);
  implatDecreaseGlobalPendingOperationsCount();
  implatWaitForMutex((_KMUTANT *)&DAT_1c001b1f0);
  puVar6 = (undefined8 *)*puVar1;
  while (puVar6 != puVar1) {
    p_Var2 = (_IMPLAT_INTERNAL_BINDING *)(puVar6 + -4);
    puVar5 = (undefined8 *)*puVar6;
    pcVar3 = (char *)((longlong)puVar6 + 0x45);
    puVar6 = puVar5;
    if (*pcVar3 != '\0') {
      implatRemoveInternalBinding(p_Var2);
    }
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_d8);
  *(undefined4 *)((longlong)param_1 + 200) = 0;
  if (*(char *)((longlong)param_1 + 0x444) != '\0') {
    *(undefined1 *)((longlong)param_1 + 0x444) = 0;
    *(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x150) = 0;
  }
  uVar8 = 0;
  if (DAT_1c001b278 != 0) {
    do {
      lVar9 = 0x4c0;
      do {
        plVar4 = (longlong *)(lVar9 + *(longlong *)((longlong)param_1 + 0x48));
        *plVar4 = *plVar4 + *(longlong *)
                             (*(longlong *)((longlong)param_1 + 0xf0) +
                              (ulonglong)uVar8 * 0xc0 + -0x4b0 + lVar9);
        lVar9 = lVar9 + 8;
      } while (lVar9 < 0x550);
      uVar8 = uVar8 + 1;
    } while (uVar8 < DAT_1c001b278);
  }
  implatRecalculateTeamOffloadCapabilities
            (*(_IMPLAT_TEAM **)((longlong)param_1 + 0x48),(_LOCK_STATE_EX *)&local_d8);
  *(undefined1 *)((longlong)param_1 + 0x710) = 0;
  *(undefined8 *)((longlong)param_1 + 0x20) = 0;
  uVar7 = *(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88);
  NdisReleaseRWLock(uVar7,&local_d8);
  if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
    McTemplateK0z_EtwWriteTransfer(uVar7,&TNicHaltedInfo,0,*(wchar_t **)((longlong)param_1 + 0x30));
  }
  implatDereferenceVirtualMiniport(param_1,(ushort *)L"HaltEx");
  KeReleaseMutex(&DAT_1c001b1f0,0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
             &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,param_1);
  }
  if (5 < DAT_1c001b0a0) {
    local_48 = &local_d4;
    local_58 = &local_d0;
    local_40 = 4;
    local_68 = &local_c0;
    local_50 = 0x10;
    local_78 = &local_b0;
    local_60 = 0x10;
    local_70 = 0x10;
    local_d4 = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c001b0a0,&DAT_1c00191ea,0,0,6,local_98);
  }
  return;
}



===== implatInitAllStandardizedKeywords @ 1c0007348 =====

/* void __cdecl implatInitAllStandardizedKeywords(struct _IMPLAT_STANDARDIZED_KEYWORD * __ptr64) */

void __cdecl implatInitAllStandardizedKeywords(_IMPLAT_STANDARDIZED_KEYWORD *param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  _IMPLAT_STANDARDIZED_KEYWORD *p_Var7;
  longlong lVar8;
  undefined4 local_2d8 [2];
  wchar_t *pwStack_2d0;
  undefined4 local_2c8;
  undefined4 uStack_2c4;
  undefined4 uStack_2c0;
  undefined4 local_2b8;
  wchar_t *pwStack_2b0;
  undefined4 local_2a8;
  undefined4 uStack_2a4;
  undefined4 uStack_2a0;
  undefined4 local_298;
  wchar_t *pwStack_290;
  undefined4 local_288;
  undefined4 uStack_284;
  undefined4 uStack_280;
  undefined4 local_278;
  wchar_t *pwStack_270;
  undefined4 local_268;
  undefined4 uStack_264;
  undefined4 uStack_260;
  undefined4 local_258;
  wchar_t *pwStack_250;
  undefined4 local_248;
  undefined4 uStack_244;
  undefined4 uStack_240;
  undefined4 local_238;
  wchar_t *pwStack_230;
  undefined4 local_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 local_218;
  wchar_t *local_210;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1f8;
  wchar_t *local_1f0;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1d8;
  wchar_t *local_1d0;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1b8;
  wchar_t *local_1b0;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_198;
  wchar_t *local_190;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_178;
  wchar_t *local_170;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_158;
  wchar_t *local_150;
  undefined4 local_148;
  undefined8 local_144;
  undefined4 local_138;
  wchar_t *local_130;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_118;
  wchar_t *local_110;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_f8;
  wchar_t *local_f0;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_d8;
  wchar_t *local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_b8;
  wchar_t *local_b0;
  undefined4 local_a8;
  undefined8 local_a4;
  undefined4 local_98;
  wchar_t *local_90;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_78;
  wchar_t *local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_58;
  wchar_t *local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_38;
  wchar_t *local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_2d8[0] = 0x2e002c;
  local_2c8 = 0;
  pwStack_2d0 = L"*IPChecksumOffloadIPv4";
  pwStack_2b0 = L"*TCPChecksumOffloadIPv4";
  pwStack_290 = L"*TCPChecksumOffloadIPv6";
  uStack_2c4 = 3;
  uStack_2c0 = 3;
  pwStack_270 = L"*UDPChecksumOffloadIPv4";
  pwStack_250 = L"*UDPChecksumOffloadIPv6";
  pwStack_230 = L"*LsoV2IPv4";
  local_210 = L"*LsoV2IPv6";
  local_1f0 = L"*IPsecOffloadV2";
  local_1d0 = L"*RscIPv4";
  local_1b0 = L"*RscIPv6";
  local_190 = L"*EncapsulatedPacketTaskOffload";
  local_170 = L"*HeaderDataSplit";
  local_150 = L"VlanID";
  local_2b8 = 0x30002e;
  local_2a8 = 0;
  uStack_2a4 = 3;
  uStack_2a0 = 3;
  local_298 = 0x30002e;
  local_288 = 0;
  uStack_284 = 3;
  uStack_280 = 3;
  local_278 = 0x30002e;
  local_268 = 0;
  uStack_264 = 3;
  uStack_260 = 3;
  local_258 = 0x30002e;
  local_248 = 0;
  uStack_244 = 3;
  uStack_240 = 3;
  local_238 = 0x160014;
  local_228 = 0;
  uStack_224 = 1;
  uStack_220 = 1;
  local_218 = 0x160014;
  local_208 = 0;
  local_204 = 1;
  local_200 = 1;
  local_1f8 = 0x20001e;
  local_1e8 = 0;
  local_1e4 = 3;
  local_1e0 = 3;
  local_1d8 = 0x120010;
  local_1c8 = 0;
  local_1c4 = 1;
  local_1c0 = 1;
  local_1b8 = 0x120010;
  local_1a8 = 0;
  local_1a4 = 1;
  local_1a0 = 1;
  local_198 = 0x3e003c;
  local_188 = 0;
  local_184 = 1;
  local_180 = 1;
  local_178 = 0x220020;
  local_168 = 0;
  local_164 = 1;
  local_160 = 1;
  local_158 = 0xe000c;
  local_148 = 0;
  local_144 = 0xffe;
  local_138 = 0xa0008;
  local_128 = 0;
  local_130 = L"*VMQ";
  lVar8 = 5;
  local_124 = 1;
  local_110 = L"*VMQLookaheadSplit";
  local_120 = 1;
  local_f0 = L"*VMQVlanFiltering";
  local_d0 = L"*RSS";
  local_b0 = L"DefaultNicInTeam";
  local_90 = L"*WakeOnPattern";
  local_70 = L"*WakeOnMagicPacket";
  local_50 = L"*ARPOffload";
  local_30 = L"*NSOffload";
  local_118 = 0x260024;
  local_108 = 0;
  local_104 = 1;
  local_100 = 1;
  local_f8 = 0x240022;
  local_e8 = 0;
  local_e4 = 1;
  local_e0 = 1;
  local_d8 = 0xa0008;
  local_c8 = 0;
  local_c4 = 1;
  local_c0 = 1;
  local_b8 = 0x220020;
  local_a8 = 0;
  local_a4 = 1;
  local_98 = 0x1e001c;
  local_88 = 0;
  local_84 = 1;
  local_80 = 1;
  local_78 = 0x260024;
  local_68 = 0;
  local_64 = 1;
  local_60 = 1;
  local_58 = 0x180016;
  local_48 = 0;
  local_44 = 1;
  local_40 = 1;
  local_38 = 0x160014;
  local_28 = 0;
  local_24 = 1;
  local_20 = 1;
  puVar5 = (undefined8 *)local_2d8;
  do {
    p_Var7 = param_1;
    puVar6 = puVar5;
    uVar1 = puVar6[1];
    uVar2 = puVar6[2];
    uVar3 = puVar6[3];
    *(undefined8 *)p_Var7 = *puVar6;
    *(undefined8 *)(p_Var7 + 8) = uVar1;
    uVar1 = puVar6[4];
    uVar4 = puVar6[5];
    *(undefined8 *)(p_Var7 + 0x10) = uVar2;
    *(undefined8 *)(p_Var7 + 0x18) = uVar3;
    uVar2 = puVar6[6];
    uVar3 = puVar6[7];
    *(undefined8 *)(p_Var7 + 0x20) = uVar1;
    *(undefined8 *)(p_Var7 + 0x28) = uVar4;
    uVar1 = puVar6[8];
    uVar4 = puVar6[9];
    *(undefined8 *)(p_Var7 + 0x30) = uVar2;
    *(undefined8 *)(p_Var7 + 0x38) = uVar3;
    uVar2 = puVar6[10];
    uVar3 = puVar6[0xb];
    *(undefined8 *)(p_Var7 + 0x40) = uVar1;
    *(undefined8 *)(p_Var7 + 0x48) = uVar4;
    uVar1 = puVar6[0xc];
    uVar4 = puVar6[0xd];
    *(undefined8 *)(p_Var7 + 0x50) = uVar2;
    *(undefined8 *)(p_Var7 + 0x58) = uVar3;
    uVar2 = puVar6[0xe];
    uVar3 = puVar6[0xf];
    *(undefined8 *)(p_Var7 + 0x60) = uVar1;
    *(undefined8 *)(p_Var7 + 0x68) = uVar4;
    *(undefined8 *)(p_Var7 + 0x70) = uVar2;
    *(undefined8 *)(p_Var7 + 0x78) = uVar3;
    lVar8 = lVar8 + -1;
    puVar5 = puVar6 + 0x10;
    param_1 = p_Var7 + 0x80;
  } while (lVar8 != 0);
  uVar1 = puVar6[0x11];
  uVar2 = puVar6[0x12];
  uVar3 = puVar6[0x13];
  *(undefined8 *)(p_Var7 + 0x80) = puVar6[0x10];
  *(undefined8 *)(p_Var7 + 0x88) = uVar1;
  uVar1 = puVar6[0x14];
  uVar4 = puVar6[0x15];
  *(undefined8 *)(p_Var7 + 0x90) = uVar2;
  *(undefined8 *)(p_Var7 + 0x98) = uVar3;
  uVar2 = puVar6[0x16];
  uVar3 = puVar6[0x17];
  *(undefined8 *)(p_Var7 + 0xa0) = uVar1;
  *(undefined8 *)(p_Var7 + 0xa8) = uVar4;
  *(undefined8 *)(p_Var7 + 0xb0) = uVar2;
  *(undefined8 *)(p_Var7 + 0xb8) = uVar3;
  return;
}



===== implatInitializeEx @ 1c0007730 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* int __cdecl implatInitializeEx(void * __ptr64,void * __ptr64,struct
   _NDIS_MINIPORT_INIT_PARAMETERS * __ptr64) */

int __cdecl implatInitializeEx(void *param_1,void *param_2,_NDIS_MINIPORT_INIT_PARAMETERS *param_3)

{
  _IMPLAT_INTERNAL_BINDING *p_Var1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  _IMPLAT_VIRTMINI *p_Var5;
  _IMPLAT_VIRTMINI *p_Var6;
  undefined2 uVar7;
  undefined8 uVar8;
  _IMPLAT_VIRTMINI *p_Var9;
  undefined8 uVar10;
  longlong lVar11;
  undefined1 auStackY_3f8 [32];
  int local_3c8;
  undefined2 local_3c4;
  undefined1 local_3c2;
  _IMPLAT_VIRTMINI local_3c0 [4];
  int local_3bc;
  int local_3b8 [2];
  longlong local_3b0;
  int local_3a8;
  ulonglong local_3a0;
  void *local_398;
  ulonglong local_390;
  undefined8 local_388;
  longlong local_380;
  byte *local_378;
  int *local_370;
  undefined8 local_368;
  _IMPLAT_VIRTMINI *p_Stack_360;
  undefined8 local_358;
  undefined8 uStack_350;
  short local_348 [4];
  wchar_t *local_340;
  undefined8 local_338;
  wchar_t *local_330;
  undefined8 local_328;
  _IMPLAT_VIRTMINI *p_Stack_320;
  _IMPLAT_VIRTMINI *local_318;
  undefined8 uStack_310;
  undefined8 local_308;
  undefined8 local_300;
  undefined4 local_2f8 [2];
  undefined8 *local_2f0;
  _IMPLAT_VIRTMINI *local_2e8;
  _IMPLAT_VIRTMINI *local_2e0;
  _IMPLAT_VIRTMINI *local_2d8;
  _IMPLAT_VIRTMINI *local_2d0;
  undefined8 local_298;
  undefined4 local_290;
  undefined4 local_28c;
  ulong local_288;
  undefined8 local_280;
  undefined8 local_278;
  undefined8 local_270;
  undefined8 local_268;
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined8 local_250;
  ulong local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined2 local_23c;
  undefined4 local_23a;
  undefined2 local_236;
  undefined4 local_21a;
  undefined2 local_216;
  undefined4 *local_1f8;
  undefined8 local_1f0;
  undefined4 local_1e8;
  undefined2 local_1e4;
  undefined1 local_1e2;
  undefined8 local_1e0;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 *local_1d0;
  undefined4 local_1c8;
  undefined4 local_1c4;
  longlong local_1c0;
  undefined8 local_1b8;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined8 local_1a8;
  undefined4 local_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 uStack_194;
  undefined4 local_190;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined8 local_108 [4];
  longlong local_e8;
  undefined8 local_e0;
  _IMPLAT_VIRTMINI *local_d8;
  undefined8 local_d0;
  _IMPLAT_VIRTMINI *local_c8;
  undefined8 local_c0;
  int *local_b8;
  undefined8 local_b0;
  _IMPLAT_VIRTMINI *local_a8;
  undefined8 local_a0;
  int *local_98;
  undefined8 local_90;
  wchar_t local_88 [40];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_3f8;
  local_388 = 0;
  local_3a8 = 0;
  local_348[2] = 0;
  local_348[3] = 0;
  local_3a0 = (ulonglong)(uint)local_3a0;
  local_390 = (ulonglong)(uint)local_390;
  local_3b0 = 0;
  local_380 = 0;
  local_368 = 0;
  p_Stack_360 = (_IMPLAT_VIRTMINI *)0x0;
  local_298 = local_298 & 0xffffffffffffff00;
  local_358 = 0;
  uStack_350 = 0;
  memset((void *)((longlong)&local_298 + 1),0,0xdf);
  local_308 = 0;
  local_328 = 0;
  p_Stack_320 = (_IMPLAT_VIRTMINI *)0x0;
  local_318 = (_IMPLAT_VIRTMINI *)0x0;
  uStack_310 = 0;
  memset(local_2f8,0,0x60);
  local_188 = 0xfd010101;
  local_1a8 = 0;
  local_190 = 0;
  local_180 = 0x10111;
  local_184 = 0x10209;
  local_148 = 0x10209;
  local_3c4 = 0;
  local_3c2 = 0;
  local_1b8 = 0;
  uStack_1b0 = 0;
  uStack_1ac = 0;
  local_17c = 0x1010b;
  local_1a0 = 0;
  uStack_19c = 0;
  uStack_198 = 0;
  uStack_194 = 0;
  local_178 = 0x10109;
  local_174 = 0x1010a;
  local_170 = 0x10108;
  local_16c = 0x1010d;
  local_168 = 0x10116;
  local_164 = 0x1010c;
  local_160 = 0x20106;
  local_15c = 0x20102;
  local_158 = 0x20101;
  local_154 = 0x1021c;
  local_150 = 0x1010f;
  local_14c = 0x1010e;
  local_144 = 0x10208;
  local_140 = 0xfa010101;
  local_13c = 0xfa010102;
  local_138 = 0xfa010103;
  local_134 = 0x101010a;
  local_130 = 0xfc01020c;
  local_12c = 0x1021e;
  local_128 = 0xfc030205;
  local_124 = 0xfc030203;
  local_120 = 0x1010103;
  local_11c = 0xfa010202;
  local_118 = 0xfa010204;
  lVar11 = 0x16;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,param_1);
  }
  NdisMGetDeviceProperty(param_1,&local_388,0,0);
  iVar4 = IoGetDeviceProperty(local_388,10,0x4e,local_88);
  if ((iVar4 < 0) || (local_3a8 == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
               &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,iVar4);
    }
    return -0x3fffffff;
  }
  local_348[1] = 0x4e;
  local_348[0] = (short)local_3a8 + -2;
  local_340 = local_88;
  if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
    McTemplateK0z_EtwWriteTransfer
              ((ulonglong)CONCAT22((short)((uint)local_3a8 >> 0x10),local_348[0]),
               &TNicBeingInitializedInfo,0,local_88);
  }
  implatWaitForMutex((_KMUTANT *)&DAT_1c001b1f0);
  p_Var5 = implatFindVirtMiniByName
                     ((_LIST_ENTRY *)&DAT_1c001b258,(_UNICODE_STRING *)local_348,'\0',
                      (_IMPLAT_TEAM *)0x0);
  KeReleaseMutex(&DAT_1c001b1f0,0);
  if (p_Var5 == (_IMPLAT_VIRTMINI *)0x0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids);
    }
    return 0x10003;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,param_1,(char)p_Var5);
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(p_Var5 + 0x48) + 0x88),&local_3c4,0);
  p_Var6 = p_Var5 + 0x440;
  *(undefined4 *)(p_Var5 + 200) = 2;
  memset(p_Var6,0,0x1c48);
  memset(*(void **)(p_Var5 + 0xf0),0,(ulonglong)DAT_1c001b278 * 0xc0);
  KeClearEvent(p_Var5 + 0xd0);
  *(undefined4 *)(p_Var5 + 0x76c) = 0;
  *(undefined4 *)(p_Var5 + 0xcc) = 1;
  *(undefined4 *)(p_Var5 + 0x74c) = *(undefined4 *)(param_3 + 0x20);
  implatInitAllStandardizedKeywords((_IMPLAT_STANDARDIZED_KEYWORD *)(p_Var5 + 0x450));
  memset(p_Var5 + 0x100,0,0x340);
  vmqClearCapabilities((undefined4 *)(p_Var5 + 0x100));
  *(void **)(p_Var5 + 0xf8) = param_1;
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(p_Var5 + 0x48) + 0x88),&local_3c4);
  ConvertInterfaceIndexToLuid(*(NET_IFINDEX *)(p_Var5 + 0x74c),(PNET_LUID)(p_Var5 + 0x760));
  ConvertInterfaceLuidToGuid((PNET_LUID)(p_Var5 + 0x760),(GUID *)(p_Var5 + 0x750));
  local_300 = 0xfffffffffe363c80;
  KeWaitForSingleObject(p_Var5 + 0x80,0,0,0);
  local_3a0 = 0x1401a9;
  local_390 = 0;
  local_398 = param_1;
  local_3c8 = NdisOpenConfigurationEx(&local_3a0,&local_3b0);
  if (local_3c8 == 0) {
    p_Var9 = p_Var5 + 0x464;
    local_3c8 = 0;
    do {
      NdisReadConfiguration(&local_3c8,&local_380);
      if (((local_3c8 == 0) && (uVar2 = *(uint *)(local_380 + 8), *(uint *)(p_Var9 + -4) <= uVar2))
         && (uVar2 <= *(uint *)p_Var9)) {
        *(uint *)(p_Var9 + 4) = uVar2;
      }
      p_Var9 = p_Var9 + 0x20;
      lVar11 = lVar11 + -1;
    } while (lVar11 != 0);
    NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(p_Var5 + 0x48) + 0x88),&local_3c4);
    *(int *)p_Var6 = *(int *)(p_Var5 + 0x5e8);
    if ((*(int *)(p_Var5 + 0x688) != 0) &&
       (*(longlong *)(*(longlong *)(p_Var5 + 0x48) + 0x150) == 0)) {
      p_Var5[0x444] = (_IMPLAT_VIRTMINI)0x1;
      *(_IMPLAT_VIRTMINI **)(*(longlong *)(p_Var5 + 0x48) + 0x150) = p_Var5;
    }
    NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(p_Var5 + 0x48) + 0x88),&local_3c4);
    local_3c8 = implatCalculateVirtMiniCapabilities(p_Var5);
    lVar11 = local_3b0;
    if (local_3c8 == 0) {
      local_3bc = 0;
      local_378 = (byte *)0x0;
      local_3b8[0] = 0;
      local_370 = (int *)0x0;
      local_338 = 0x30002e;
      local_330 = L"MSImPlatOutgoingMacAddr";
      NdisReadNetworkAddress(&local_3bc,&local_378,local_3b8,local_3b0);
      if ((((local_3bc == 0) && (local_3b8[0] == 6)) && ((*local_378 & 1) == 0)) &&
         ((((*local_378 != 0xff || (local_378[1] != 0xff)) ||
           ((local_378[2] != 0xff || ((local_378[3] != 0xff || (local_378[4] != 0xff)))))) ||
          (local_378[5] != 0xff)))) {
        *(undefined4 *)(p_Var5 + 0x711) = *(undefined4 *)local_378;
        *(undefined2 *)(p_Var5 + 0x715) = *(undefined2 *)(local_378 + 4);
      }
      NdisReadConfiguration(&local_3bc,&local_370,lVar11,&local_338);
      if (((local_3bc == 0) && (*local_370 == 4)) && ((short)local_370[2] == 6)) {
        pbVar3 = *(byte **)(local_370 + 4);
        if (((*pbVar3 & 1) != 0) ||
           (((*pbVar3 == 0xff && (pbVar3[1] == 0xff)) &&
            (((pbVar3[2] == 0xff && ((pbVar3[3] == 0xff && (pbVar3[4] == 0xff)))) &&
             (pbVar3[5] == 0xff)))))) goto LAB_1c0007e47;
        *(undefined4 *)(p_Var5 + 0x717) = *(undefined4 *)pbVar3;
        uVar7 = *(undefined2 *)(*(longlong *)(local_370 + 4) + 4);
      }
      else {
LAB_1c0007e47:
        uVar7 = *(undefined2 *)(p_Var5 + 0x715);
        *(undefined4 *)(p_Var5 + 0x717) = *(undefined4 *)(p_Var5 + 0x711);
      }
      *(undefined2 *)(p_Var5 + 0x71b) = uVar7;
      implatTeamMinimumCapabilitiesFromRegistry
                (p_Var5,(ulong *)(p_Var5 + 0x720),(ulong *)(p_Var5 + 0x738));
      local_368 = 0x1c019e;
      uStack_350 = 0;
      local_358 = 0x4000000220;
      p_Stack_360 = p_Var5;
      local_3c8 = NdisMSetMiniportAttributes(param_1,&local_368);
      if (local_3c8 == 0) {
        NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(p_Var5 + 0x48) + 0x88),&local_3c4);
        implatCalculateVirtMiniLinkState(p_Var5);
        local_278 = *(undefined8 *)(p_Var5 + 0xb0);
        local_268 = *(undefined8 *)(p_Var5 + 0xb8);
        local_260 = *(undefined4 *)(p_Var5 + 0xa4);
        local_25c = *(undefined4 *)(p_Var5 + 0xa8);
        local_1c4 = *(undefined4 *)(p_Var5 + 0xc4);
        NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(p_Var5 + 0x48) + 0x88),&local_3c4);
        local_298 = 0xe0029f;
        local_290 = 0;
        local_28c = 0xe;
        local_288 = *(ulong *)(p_Var5 + 0x720);
        local_280 = *(undefined8 *)(p_Var5 + 0x728);
        local_270 = *(undefined8 *)(p_Var5 + 0x730);
        local_258 = *(undefined4 *)(p_Var5 + 0x768);
        local_250 = 0;
        local_248 = *(ulong *)(p_Var5 + 0x738);
        local_244 = *(undefined4 *)(p_Var5 + 0x73c);
        local_240 = *(undefined4 *)(p_Var5 + 0x740);
        local_23c = 6;
        local_23a = *(undefined4 *)(p_Var5 + 0x711);
        local_236 = *(undefined2 *)(p_Var5 + 0x715);
        local_1f8 = &local_1a0;
        local_1f0 = 2;
        local_1e8 = 1;
        local_1e4 = 6;
        local_1e2 = 0;
        local_1e0 = 0x3f87ff;
        local_1d8 = *(undefined4 *)(p_Var5 + 0x744);
        local_1d4 = *(undefined4 *)(p_Var5 + 0x748);
        local_1d0 = &local_188;
        local_1c8 = 0x74;
        if ((p_Var5[0x444] != (_IMPLAT_VIRTMINI)0x0) && (*(int *)p_Var6 == 0)) {
          local_1c0 = *(longlong *)(p_Var5 + 0x48) + 0x444;
        }
        local_1a0 = 0x120288;
        uStack_198 = 0;
        uStack_194 = 0;
        local_190 = 0;
        uStack_19c = 0;
        if (*(int *)(p_Var5 + 0x668) != 0) {
          uStack_19c = 0x10000000;
        }
        local_21a = local_23a;
        local_216 = local_236;
        local_3c8 = NdisMSetMiniportAttributes(param_1,&local_298);
        if (local_3c8 == 0) {
          p_Stack_320 = p_Var5 + 0x770;
          local_328 = 0x2801a0;
          local_318 = p_Var5 + 0x824;
          uStack_310 = 0;
          local_308 = 0;
          local_3c8 = NdisMSetMiniportAttributes(param_1,&local_328);
          if (local_3c8 == 0) {
            local_2f8[0] = 0x3002af;
            local_2f0 = &local_1b8;
            local_2e0 = p_Var5 + 0x100;
            local_2e8 = p_Var5 + 0x1c8;
            local_2d0 = p_Var5 + 0x154;
            local_2d8 = p_Var5 + 0x21c;
            local_1b8 = CONCAT44(*(undefined4 *)(p_Var5 + 0x8fc),0x1801ab);
            uStack_1b0 = *(undefined4 *)(p_Var5 + 0x900);
            local_3c8 = NdisMSetMiniportAttributes(param_1,local_2f8);
            if (local_3c8 == 0) {
              *(undefined4 *)(p_Var5 + 0x904) = uStack_1ac;
              *(undefined4 *)(p_Var5 + 0x90c) = (undefined4)local_1a8;
              *(undefined4 *)(p_Var5 + 0x910) = local_1a8._4_4_;
              *(undefined4 *)(p_Var5 + 0x908) = 0;
              implatWaitForMutex((_KMUTANT *)&DAT_1c001b1f0);
              NdisAcquireRWLockWrite
                        (*(undefined8 *)(*(longlong *)(p_Var5 + 0x48) + 0x88),&local_3c4);
              if ((*(uint *)(p_Var5 + 0x904) & 1) == 0) {
                *(undefined4 *)(p_Var5 + 0x5c8) = 0;
              }
              local_3c8 = implatRecalculateTeamOffloadCapabilities
                                    (*(_IMPLAT_TEAM **)(p_Var5 + 0x48),(_LOCK_STATE_EX *)&local_3c4)
              ;
              if (local_3c8 == 0) {
                *(void **)(p_Var5 + 0x20) = param_1;
                *(undefined4 *)(p_Var5 + 200) = 3;
                implatTaskOffloadRecalculateAndIndicateChange(p_Var5);
                implatCalculateVirtMiniLinkState(p_Var5);
                implatRecalculatePMCapabilities(*(_IMPLAT_TEAM **)(p_Var5 + 0x48));
                NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(p_Var5 + 0x48) + 0x88),&local_3c4);
                implatCalculateVmqCaps(p_Var5,'\x01');
                KeReleaseMutex(&DAT_1c001b1f0,0);
                implatIncreaseGlobalPendingOperationsCount();
                KeWaitForSingleObject(*(longlong *)(p_Var5 + 0x48) + 0x118,0);
                p_Var5[0x98] = (_IMPLAT_VIRTMINI)0x0;
                for (p_Var6 = *(_IMPLAT_VIRTMINI **)(p_Var5 + 0x60);
                    p_Var1 = (_IMPLAT_INTERNAL_BINDING *)(p_Var6 + -0x20), p_Var6 != p_Var5 + 0x60;
                    p_Var6 = *(_IMPLAT_VIRTMINI **)p_Var6) {
                  if ((*(char *)(*(longlong *)p_Var1 + 0x250) == '\0') &&
                     (local_3c8 = implatAllocatePort(p_Var1), local_3c8 != 0)) {
                    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 &&
                        (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
                      WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                                 &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,p_Var5,
                                 (char)p_Var1,(char)local_3c8);
                    }
                    local_3c8 = 0;
                  }
                }
                KeReleaseMutex(*(longlong *)(p_Var5 + 0x48) + 0x118,0);
                implatDecreaseGlobalPendingOperationsCount();
                NdisIfAddIfStackEntry
                          (*(undefined4 *)(p_Var5 + 0x74c),
                           *(undefined4 *)(*(longlong *)(p_Var5 + 0x48) + 200));
                local_3c8 = 0;
              }
              else {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                   (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                           &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,local_3c8);
                }
                NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(p_Var5 + 0x48) + 0x88),&local_3c4);
                KeReleaseMutex(&DAT_1c001b1f0,0);
              }
              goto LAB_1c0008487;
            }
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar7 = 0x1e;
              goto LAB_1c0008231;
            }
          }
          else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                  (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar7 = 0x1d;
            goto LAB_1c0008231;
          }
        }
        else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar7 = 0x1c;
          goto LAB_1c0008231;
        }
      }
      else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar7 = 0x1b;
LAB_1c0008231:
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,
                 &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,local_3c8);
      }
      local_3c8 = -0x3fffffff;
    }
LAB_1c0008487:
    if (local_3b0 != 0) {
      NdisCloseConfiguration();
      local_3b0 = 0;
    }
    if (local_3c8 == 0) goto LAB_1c000851f;
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
               &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,local_3c8);
    }
    local_3c8 = -0x3fffffff;
    local_3b0 = 0;
  }
  uVar10 = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(p_Var5 + 0x48) + 0x88),&local_3c4);
  *(undefined4 *)(p_Var5 + 200) = 0;
  uVar8 = *(undefined8 *)(*(longlong *)(p_Var5 + 0x48) + 0x88);
  NdisReleaseRWLock(uVar8,&local_3c4);
  if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 4) != 0) {
    McTemplateK0zq_EtwWriteTransfer
              (uVar8,&TNicInitializatoinFaliedErr,uVar10,*(wchar_t **)(p_Var5 + 0x30),
               (char)local_3c8);
  }
  SysEventWriteStrStatus(-0x7fffbd9d,*(ushort **)(p_Var5 + 0x30),local_3c8);
LAB_1c000851f:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
             &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,param_1);
  }
  if (5 < DAT_1c001b0a0) {
    local_98 = local_3b8;
    local_3b8[0] = local_3c8;
    local_d8 = p_Var5 + 0x38;
    local_3c0[0] = p_Var5[0x444];
    local_3bc = *(int *)(p_Var5 + 0x440);
    local_a8 = local_3c0;
    local_e8 = *(longlong *)(p_Var5 + 0x48) + 0x10;
    local_b8 = &local_3bc;
    local_c8 = p_Var5 + 0x750;
    local_c0 = 0x10;
    local_d0 = 0x10;
    local_e0 = 0x10;
    local_90 = 4;
    local_a0 = 1;
    local_b0 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c001b0a0,&DAT_1c0019267,0,0,8,local_108);
  }
  return local_3c8;
}



===== implatPause @ 1c00086a0 =====

/* int __cdecl implatPause(void * __ptr64,struct _NDIS_MINIPORT_PAUSE_PARAMETERS * __ptr64) */

int __cdecl implatPause(void *param_1,_NDIS_MINIPORT_PAUSE_PARAMETERS *param_2)

{
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
             &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,param_1);
  }
  NdisAcquireRWLockWrite
            (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_res8,0);
  *(undefined4 *)((longlong)param_1 + 200) = 6;
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_res8);
  implatWaitForOutstandingIndicationsOnVirtMini(param_1);
  NdisAcquireRWLockWrite
            (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_res8,0);
  *(undefined4 *)((longlong)param_1 + 200) = 3;
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_res8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
             &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,param_1);
  }
  return 0;
}



===== implatRemoveVirtualMiniport @ 1c00087c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl implatRemoveVirtualMiniport(struct _IMPLAT_VIRTMINI * __ptr64) */

void __cdecl implatRemoveVirtualMiniport(_IMPLAT_VIRTMINI *param_1)

{
  longlong *plVar1;
  code *pcVar2;
  _IMPLAT_VIRTMINI *p_Var3;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [4];
  _IMPLAT_VIRTMINI *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,param_1);
  }
  p_Var3 = *(_IMPLAT_VIRTMINI **)param_1;
  if ((*(_IMPLAT_VIRTMINI **)(p_Var3 + 8) != param_1) ||
     (plVar1 = *(longlong **)(param_1 + 8), (_IMPLAT_VIRTMINI *)*plVar1 != param_1)) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(3);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  *plVar1 = (longlong)p_Var3;
  *(longlong **)(p_Var3 + 8) = plVar1;
  if (*(longlong *)(param_1 + 0x48) != 0) {
    p_Var3 = param_1;
    implatRemoveVirtMiniFromTeam(param_1);
  }
  if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
    McTemplateK0z_EtwWriteTransfer
              (p_Var3,&RemovedTeamNicFromGlobalInfo,0,*(wchar_t **)(param_1 + 0x30));
  }
  if (5 < DAT_1c001b0a0) {
    local_1c = 0;
    local_28 = param_1 + 0x38;
    local_20 = 0x10;
    _tlgWriteTransfer_EtwWriteTransfer(0x1c001b0a0,&DAT_1c00191a9,0,0,3,local_48);
  }
  RtlDeleteHashTable(*(undefined8 *)(param_1 + 0x70));
  *(undefined8 *)(param_1 + 0x70) = 0;
  ExFreePoolWithTag(param_1,0x6c506d49);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
            &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids);
  }
  return;
}



===== implatRestart @ 1c0008940 =====

/* int __cdecl implatRestart(void * __ptr64,struct _NDIS_MINIPORT_RESTART_PARAMETERS * __ptr64) */

int __cdecl implatRestart(void *param_1,_NDIS_MINIPORT_RESTART_PARAMETERS *param_2)

{
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
             &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,param_1);
  }
  NdisAcquireRWLockWrite
            (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_res8,0);
  *(undefined4 *)((longlong)param_1 + 200) = 4;
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_res8);
  NdisAcquireRWLockWrite
            (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_res8,0);
  *(undefined4 *)((longlong)param_1 + 200) = 5;
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_res8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
             &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,param_1);
  }
  return 0;
}



===== implatShutdownEx @ 1c0008a60 =====

/* void __cdecl implatShutdownEx(void * __ptr64,enum _NDIS_SHUTDOWN_ACTION) */

void __cdecl implatShutdownEx(void *param_1,_NDIS_SHUTDOWN_ACTION param_2)

{
  undefined2 local_res10;
  undefined1 local_res12;
  
  local_res10 = 0;
  local_res12 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
             &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,param_1);
  }
  if (param_2 == 0) {
    NdisAcquireRWLockWrite
              (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_res10,0);
    *(undefined4 *)((longlong)param_1 + 200) = 1;
    NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_res10);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
             &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,param_1);
  }
  return;
}



===== implatTaskOffloadFinal @ 1c0008b48 =====

/* void __cdecl implatTaskOffloadFinal(struct _NDIS_OFFLOAD * __ptr64) */

void __cdecl implatTaskOffloadFinal(_NDIS_OFFLOAD *param_1)

{
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined8 *)(param_1 + 4) = 0;
  }
  if (*(int *)(param_1 + 0xc) == 0) {
    *(undefined8 *)(param_1 + 0xc) = 0;
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined8 *)(param_1 + 0x14) = 0;
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    *(undefined8 *)(param_1 + 0x1c) = 0;
  }
  if (*(int *)(param_1 + 0x50) == 0) {
    *(undefined8 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  if (*(int *)(param_1 + 0x5c) == 0) {
    *(undefined8 *)(param_1 + 0x5c) = 0;
    *(undefined8 *)(param_1 + 100) = 0;
  }
  if (*(int *)(param_1 + 0x70) == 0) {
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined8 *)(param_1 + 0x78) = 0;
    *(undefined8 *)(param_1 + 0x80) = 0;
    *(undefined8 *)(param_1 + 0x88) = 0;
  }
  return;
}



===== implatTaskOffloadInit @ 1c0008bac =====

/* void __cdecl implatTaskOffloadInit(struct _NDIS_OFFLOAD * __ptr64,struct
   _IMPLAT_STANDARDIZED_KEYWORD * __ptr64 const,unsigned char) */

void __cdecl
implatTaskOffloadInit(_NDIS_OFFLOAD *param_1,_IMPLAT_STANDARDIZED_KEYWORD *param_2,uchar param_3)

{
  _IMPLAT_STANDARDIZED_KEYWORD _Var1;
  uint uVar2;
  uint uVar3;
  _NDIS_OFFLOAD _Var4;
  uint uVar5;
  uint uVar6;
  
  memset(param_1,0,0xb4);
  uVar2 = *(uint *)(param_1 + 8);
  *(undefined4 *)param_1 = 0x9c03a7;
  *(undefined4 *)(param_1 + 0x6c) = 6;
  *(uint *)(param_1 + 8) = uVar2 & 0xfffffff5 | 5;
  *(undefined4 *)(param_1 + 4) = 0x1f;
  uVar6 = (*(uint *)(param_2 + 0x38) & 1) << 4;
  *(uint *)(param_1 + 8) = uVar6 | uVar2 & 0xffffffc5 | 5;
  uVar5 = (*(uint *)(param_2 + 0x78) & 1) << 6;
  *(uint *)(param_1 + 8) = uVar5 | uVar6 | uVar2 & 0xffffff05 | 5;
  uVar3 = *(uint *)(param_2 + 0x18);
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffc00;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(uint *)(param_1 + 8) = (uVar3 & 1) << 8 | uVar5 | uVar6 | uVar2 & 0xfffffc05 | 5;
  uVar2 = *(uint *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x14) = 0x1f;
  *(uint *)(param_1 + 0x18) = uVar2 & 0xfffffff5 | 5;
  uVar5 = (*(uint *)(param_2 + 0x58) & 1) << 4;
  *(uint *)(param_1 + 0x18) = uVar5 | uVar2 & 0xffffffc5 | 5;
  uVar3 = *(uint *)(param_2 + 0x98);
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffff00;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(uint *)(param_1 + 0x18) = (uVar3 & 1) << 6 | uVar5 | uVar2 & 0xffffff05 | 5;
  if (*(int *)(param_2 + 0xb8) != 0) {
    *(undefined4 *)(param_1 + 0x50) = 0x1f;
    *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x58) = 1;
  }
  if (*(int *)(param_2 + 0xd8) != 0) {
    *(undefined4 *)(param_1 + 0x5c) = 0x1f;
    *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
    *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & 0xfffffff5 | 5;
    *(undefined4 *)(param_1 + 100) = 1;
  }
  if (*(int *)(param_2 + 0xf8) != 0) {
    *(undefined4 *)(param_1 + 0x70) = 0x1f;
    *(undefined2 *)(param_1 + 0x74) = 0x101;
    param_1[0x76] = (_NDIS_OFFLOAD)0x1;
    _Var1 = param_2[0xf8];
    param_1[0x77] = (_NDIS_OFFLOAD)((byte)_Var1 & 1);
    uVar2 = *(uint *)(param_2 + 0xf8);
    param_1[0x78] = (_NDIS_OFFLOAD)((uVar2 & 2) != 0);
    if (((_NDIS_OFFLOAD)((byte)_Var1 & 1) == (_NDIS_OFFLOAD)0x0) ||
       (_Var4 = (_NDIS_OFFLOAD)0x1, (uVar2 & 2) == 0)) {
      _Var4 = (_NDIS_OFFLOAD)0x0;
    }
    param_1[0x79] = _Var4;
    *(undefined4 *)(param_1 + 0x7a) = 0x1010101;
    param_1[0x7e] = (_NDIS_OFFLOAD)0x1;
    *(undefined4 *)(param_1 + 0x80) = 0xf;
    *(undefined4 *)(param_1 + 0x84) = 0x3f;
    *(undefined4 *)(param_1 + 0x88) = 0x1ff;
    *(undefined4 *)(param_1 + 0x8c) = 0xffffffff;
  }
  *(undefined2 *)(param_1 + 0x90) = 0;
  if (*(int *)(param_2 + 0x158) != 0) {
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 0xfffff;
    *(undefined4 *)(param_1 + 0x98) = 0xffffffff;
  }
  return;
}



===== implatTaskOffloadLowestCommonDenominator @ 1c0008d68 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl implatTaskOffloadLowestCommonDenominator(struct _NDIS_OFFLOAD * __ptr64,struct
   _NDIS_OFFLOAD * __ptr64) */

void __cdecl implatTaskOffloadLowestCommonDenominator(_NDIS_OFFLOAD *param_1,_NDIS_OFFLOAD *param_2)

{
  byte bVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  undefined1 local_148 [36];
  uint uStack_124;
  uint uStack_120;
  uint uStack_11c;
  uint local_f8;
  uint uStack_f4;
  uint uStack_f0;
  uint uStack_ec;
  uint local_e8;
  uint uStack_e4;
  uint uStack_dc;
  uint local_d8;
  byte bStack_d4;
  byte bStack_d3;
  byte bStack_d2;
  byte bStack_d1;
  byte bStack_d0;
  byte bStack_cf;
  byte bStack_ce;
  byte bStack_cd;
  byte bStack_cc;
  byte bStack_cb;
  byte bStack_ca;
  uint local_c8;
  uint uStack_c4;
  uint uStack_c0;
  uint uStack_bc;
  byte local_b8;
  byte bStack_b7;
  uint uStack_b4;
  uint uStack_b0;
  uint local_88 [10];
  uint local_60 [10];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)local_148;
  uVar2 = *(ulonglong *)(param_2 + 0x10);
  uVar3 = *(ulonglong *)(param_2 + 0x18);
  local_60[4] = 1;
  local_88[1] = 1;
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  uVar17 = 0;
  uVar4 = *(undefined8 *)param_2;
  uVar5 = *(ulonglong *)(param_2 + 8);
  local_60[5] = 2;
  local_60[6] = 0;
  local_60[7] = 2;
  local_60[8] = 2;
  uVar6 = *(ulonglong *)(param_2 + 0x20);
  local_88[2] = 2;
  local_88[6] = 2;
  local_88[8] = 2;
  local_88[0] = 0;
  local_88[3] = 1;
  local_88[4] = 1;
  uVar7 = *(undefined8 *)(param_2 + 0x58);
  local_88[5] = 1;
  local_88[7] = 1;
  uVar8 = *(undefined8 *)(param_2 + 0x60);
  uVar9 = *(ulonglong *)(param_2 + 0x68);
  uVar10 = *(undefined8 *)(param_2 + 0x70);
  uVar11 = *(undefined8 *)(param_2 + 0x78);
  uVar12 = *(undefined8 *)(param_2 + 0x80);
  uVar13 = *(undefined8 *)(param_2 + 0x88);
  uVar14 = *(undefined8 *)(param_2 + 0x90);
  uVar15 = *(undefined8 *)(param_2 + 0x98);
  local_f8 = (uint)*(undefined8 *)(param_2 + 0x50);
  if ((((local_f8 == 0) && (uStack_124 = (uint)(uVar6 >> 0x20), uStack_124 != 0)) &&
      (((byte)*(undefined8 *)(param_2 + 0x30) & 3) == 1)) &&
     (((byte)*(undefined8 *)(param_2 + 0x30) & 0xc) == 4)) {
    uStack_120 = (uint)*(undefined8 *)(param_2 + 0x28);
    uStack_11c = (uint)((ulonglong)*(undefined8 *)(param_2 + 0x28) >> 0x20);
  }
  else {
    uStack_f0 = (uint)uVar7;
    uStack_f4 = (uint)((ulonglong)*(undefined8 *)(param_2 + 0x50) >> 0x20);
    uStack_124 = local_f8;
    uStack_120 = uStack_f4;
    uStack_11c = uStack_f0;
  }
  uStack_dc = (uint)(uVar9 >> 0x20);
  *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x6c) & uStack_dc;
  uVar16 = *(uint *)(param_1 + 8);
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & (uint)((ulonglong)uVar4 >> 0x20);
  bVar1 = (byte)uVar5;
  if ((((byte)uVar16 & 3) < 3) && ((bVar1 & 3) < 3)) {
    uVar18 = local_60[((ulonglong)uVar16 & 3) * 3 + (uVar5 & 3)];
  }
  else {
    uVar18 = 0;
  }
  uVar19 = uVar16 ^ (uVar18 ^ uVar16) & 3;
  if ((((byte)uVar18 & 3) < 3) && ((bVar1 & 3) < 3)) {
    uVar18 = local_60[((ulonglong)uVar19 & 3) * 3 + (uVar5 & 3)];
  }
  else {
    uVar18 = 0;
  }
  uVar19 = (uVar19 ^ uVar18) & 3 ^ uVar19;
  if ((((byte)uVar19 & 0xc) < 0xc) && ((bVar1 & 0xc) < 0xc)) {
    uVar18 = local_60[((ulonglong)(uVar16 >> 2) & 3) * 3 + (uVar5 >> 2 & 3)];
  }
  else {
    uVar18 = 0;
  }
  uVar19 = (uVar18 << 2 ^ uVar19) & 0xc ^ uVar19;
  if ((((byte)uVar19 & 0x30) < 0x30) && ((bVar1 & 0x30) < 0x30)) {
    uVar18 = local_60[((ulonglong)(uVar16 >> 4) & 3) * 3 + (uVar5 >> 4 & 3)];
  }
  else {
    uVar18 = 0;
  }
  uVar19 = (uVar18 << 4 ^ uVar19) & 0x30 ^ uVar19;
  if (((uVar19 & 0xc0) < 0xc0) && (((uint)uVar5 & 0xc0) < 0xc0)) {
    uVar18 = local_60[((ulonglong)(uVar16 >> 6) & 3) * 3 + (uVar5 >> 6 & 3)];
  }
  else {
    uVar18 = 0;
  }
  uVar19 = (uVar18 << 6 ^ uVar19) & 0xc0 ^ uVar19;
  if (((uVar19 & 0x300) < 0x300) && (((uint)uVar5 & 0x300) < 0x300)) {
    uVar16 = local_60[((ulonglong)(uVar16 >> 8) & 3) * 3 + (uVar5 >> 8 & 3)];
  }
  else {
    uVar16 = 0;
  }
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | (uint)(uVar5 >> 0x20);
  uVar18 = *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 8) = (uVar16 << 8 ^ uVar19) & 0x300 ^ uVar19;
  bVar1 = (byte)uVar2;
  if ((((byte)uVar18 & 3) < 3) && ((bVar1 & 3) < 3)) {
    uVar16 = local_88[((ulonglong)uVar18 & 3) * 3 + (uVar2 & 3)];
  }
  else {
    uVar16 = 0;
  }
  uVar16 = (uVar16 ^ uVar18) & 3 ^ uVar18;
  if ((((byte)uVar16 & 0xc) < 0xc) && ((bVar1 & 0xc) < 0xc)) {
    uVar19 = local_88[((ulonglong)(uVar18 >> 2) & 3) * 3 + (uVar2 >> 2 & 3)];
  }
  else {
    uVar19 = 0;
  }
  uVar16 = (uVar19 << 2 ^ uVar16) & 0xc ^ uVar16;
  if ((((byte)uVar16 & 0x30) < 0x30) && ((bVar1 & 0x30) < 0x30)) {
    uVar19 = local_88[((ulonglong)(uVar18 >> 4) & 3) * 3 + (uVar2 >> 4 & 3)];
  }
  else {
    uVar19 = 0;
  }
  uVar16 = (uVar19 << 4 ^ uVar16) & 0x30 ^ uVar16;
  if (((uVar16 & 0xc0) < 0xc0) && (((uint)uVar2 & 0xc0) < 0xc0)) {
    uVar19 = local_88[((ulonglong)(uVar18 >> 6) & 3) * 3 + (uVar2 >> 6 & 3)];
  }
  else {
    uVar19 = 0;
  }
  uVar16 = (uVar19 << 6 ^ uVar16) & 0xc0 ^ uVar16;
  if (((uVar16 & 0x300) < 0x300) && (((uint)uVar2 & 0x300) < 0x300)) {
    uVar18 = local_88[((ulonglong)(uVar18 >> 8) & 3) * 3 + (uVar2 >> 8 & 3)];
  }
  else {
    uVar18 = 0;
  }
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & (uint)(uVar2 >> 0x20);
  uVar19 = *(uint *)(param_1 + 0x18);
  *(uint *)(param_1 + 0x10) = (uVar18 << 8 ^ uVar16) & 0x300 ^ uVar16;
  bVar1 = (byte)uVar3;
  if ((((byte)uVar19 & 3) < 3) && ((bVar1 & 3) < 3)) {
    uVar16 = local_60[((ulonglong)uVar19 & 3) * 3 + (uVar3 & 3)];
  }
  else {
    uVar16 = 0;
  }
  uVar16 = (uVar16 ^ uVar19) & 3 ^ uVar19;
  if ((((byte)uVar16 & 0xc) < 0xc) && ((bVar1 & 0xc) < 0xc)) {
    uVar18 = local_60[((ulonglong)(uVar19 >> 2) & 3) * 3 + (uVar3 >> 2 & 3)];
  }
  else {
    uVar18 = 0;
  }
  uVar16 = (uVar18 << 2 ^ uVar16) & 0xc ^ uVar16;
  if ((((byte)uVar16 & 0x30) < 0x30) && ((bVar1 & 0x30) < 0x30)) {
    uVar18 = local_60[((ulonglong)(uVar19 >> 4) & 3) * 3 + (uVar3 >> 4 & 3)];
  }
  else {
    uVar18 = 0;
  }
  uVar16 = (uVar18 << 4 ^ uVar16) & 0x30 ^ uVar16;
  if (((uVar16 & 0xc0) < 0xc0) && (((uint)uVar3 & 0xc0) < 0xc0)) {
    uVar18 = local_60[((ulonglong)(uVar19 >> 6) & 3) * 3 + (uVar3 >> 6 & 3)];
  }
  else {
    uVar18 = 0;
  }
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | (uint)(uVar3 >> 0x20);
  uVar19 = *(uint *)(param_1 + 0x20);
  *(uint *)(param_1 + 0x18) = (uVar18 << 6 ^ uVar16) & 0xc0 ^ uVar16;
  bVar1 = (byte)uVar6;
  if ((((byte)uVar19 & 3) < 3) && ((bVar1 & 3) < 3)) {
    uVar16 = local_88[((ulonglong)uVar19 & 3) * 3 + (uVar6 & 3)];
  }
  else {
    uVar16 = 0;
  }
  uVar16 = (uVar16 ^ uVar19) & 3 ^ uVar19;
  if ((((byte)uVar16 & 0xc) < 0xc) && ((bVar1 & 0xc) < 0xc)) {
    uVar18 = local_88[((ulonglong)(uVar19 >> 2) & 3) * 3 + (uVar6 >> 2 & 3)];
  }
  else {
    uVar18 = 0;
  }
  uVar16 = (uVar18 << 2 ^ uVar16) & 0xc ^ uVar16;
  if ((((byte)uVar16 & 0x30) < 0x30) && ((bVar1 & 0x30) < 0x30)) {
    uVar18 = local_88[((ulonglong)(uVar19 >> 4) & 3) * 3 + (uVar6 >> 4 & 3)];
  }
  else {
    uVar18 = 0;
  }
  uVar16 = (uVar18 << 4 ^ uVar16) & 0x30 ^ uVar16;
  if (((uVar16 & 0xc0) < 0xc0) && (((uint)uVar6 & 0xc0) < 0xc0)) {
    uVar18 = local_88[((ulonglong)(uVar19 >> 6) & 3) * 3 + (uVar6 >> 6 & 3)];
  }
  else {
    uVar18 = 0;
  }
  *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) & uStack_124;
  local_e8 = (uint)uVar8;
  uVar19 = *(uint *)(param_1 + 0x68);
  *(uint *)(param_1 + 0x20) = (uVar18 << 6 ^ uVar16) & 0xc0 ^ uVar16;
  if (*(uint *)(param_1 + 0x54) < uStack_120) {
    uStack_120 = *(uint *)(param_1 + 0x54);
  }
  *(uint *)(param_1 + 0x54) = uStack_120;
  if (uStack_11c < *(uint *)(param_1 + 0x58)) {
    uStack_11c = *(uint *)(param_1 + 0x58);
  }
  uStack_ec = (uint)((ulonglong)uVar7 >> 0x20);
  *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) & uStack_ec;
  *(uint *)(param_1 + 0x58) = uStack_11c;
  if (*(uint *)(param_1 + 0x60) < local_e8) {
    local_e8 = *(uint *)(param_1 + 0x60);
  }
  *(uint *)(param_1 + 0x60) = local_e8;
  uStack_e4 = (uint)((ulonglong)uVar8 >> 0x20);
  if (uStack_e4 < *(uint *)(param_1 + 100)) {
    uStack_e4 = *(uint *)(param_1 + 100);
  }
  *(uint *)(param_1 + 100) = uStack_e4;
  if ((((byte)uVar19 & 3) < 3) && (((byte)uVar9 & 3) < 3)) {
    uVar16 = local_60[((ulonglong)uVar19 & 3) * 3 + (uVar9 & 3)];
  }
  else {
    uVar16 = 0;
  }
  uVar16 = (uVar16 ^ uVar19) & 3 ^ uVar19;
  if ((((byte)uVar16 & 0xc) < 0xc) && (((byte)uVar9 & 0xc) < 0xc)) {
    uVar17 = local_60[((ulonglong)(uVar19 >> 2) & 3) * 3 + (uVar9 >> 2 & 3)];
  }
  uStack_bc = (uint)((ulonglong)uVar13 >> 0x20);
  *(uint *)(param_1 + 0x68) = (uVar17 * 4 ^ uVar16) & 0xc ^ uVar16;
  local_d8 = (uint)uVar10;
  *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) & local_d8;
  bStack_d4 = (byte)((ulonglong)uVar10 >> 0x20);
  param_1[0x74] = (_NDIS_OFFLOAD)((byte)param_1[0x74] & bStack_d4);
  bStack_d3 = (byte)((ulonglong)uVar10 >> 0x28);
  param_1[0x75] = (_NDIS_OFFLOAD)((byte)param_1[0x75] & bStack_d3);
  bStack_d2 = (byte)((ulonglong)uVar10 >> 0x30);
  param_1[0x76] = (_NDIS_OFFLOAD)((byte)param_1[0x76] & bStack_d2);
  bStack_d1 = (byte)((ulonglong)uVar10 >> 0x38);
  param_1[0x77] = (_NDIS_OFFLOAD)((byte)param_1[0x77] & bStack_d1);
  bStack_d0 = (byte)uVar11;
  param_1[0x78] = (_NDIS_OFFLOAD)((byte)param_1[0x78] & bStack_d0);
  bStack_cf = (byte)((ulonglong)uVar11 >> 8);
  param_1[0x79] = (_NDIS_OFFLOAD)((byte)param_1[0x79] & bStack_cf);
  bStack_ce = (byte)((ulonglong)uVar11 >> 0x10);
  param_1[0x7a] = (_NDIS_OFFLOAD)((byte)param_1[0x7a] & bStack_ce);
  bStack_cd = (byte)((ulonglong)uVar11 >> 0x18);
  param_1[0x7b] = (_NDIS_OFFLOAD)((byte)param_1[0x7b] & bStack_cd);
  bStack_cc = (byte)((ulonglong)uVar11 >> 0x20);
  param_1[0x7c] = (_NDIS_OFFLOAD)((byte)param_1[0x7c] & bStack_cc);
  bStack_cb = (byte)((ulonglong)uVar11 >> 0x28);
  param_1[0x7d] = (_NDIS_OFFLOAD)((byte)param_1[0x7d] & bStack_cb);
  bStack_ca = (byte)((ulonglong)uVar11 >> 0x30);
  param_1[0x7e] = (_NDIS_OFFLOAD)((byte)param_1[0x7e] & bStack_ca);
  local_c8 = (uint)uVar12;
  *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) & local_c8;
  uStack_c4 = (uint)((ulonglong)uVar12 >> 0x20);
  *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & uStack_c4;
  uStack_c0 = (uint)uVar13;
  *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & uStack_c0;
  if (*(uint *)(param_1 + 0x8c) < uStack_bc) {
    uStack_bc = *(uint *)(param_1 + 0x8c);
  }
  local_b8 = (byte)uVar14;
  param_1[0x90] = (_NDIS_OFFLOAD)((byte)param_1[0x90] | local_b8);
  bStack_b7 = (byte)((ulonglong)uVar14 >> 8);
  param_1[0x91] = (_NDIS_OFFLOAD)((byte)param_1[0x91] | bStack_b7);
  uStack_b4 = (uint)((ulonglong)uVar14 >> 0x20);
  *(uint *)(param_1 + 0x8c) = uStack_bc;
  *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) & (uStack_b4 | 0xfff00000);
  uStack_b0 = (uint)uVar15;
  if (*(uint *)(param_1 + 0x98) < uStack_b0) {
    uStack_b0 = *(uint *)(param_1 + 0x98);
  }
  *(uint *)(param_1 + 0x98) = uStack_b0;
  return;
}



===== implatTaskOffloadRecalculateAndIndicateChange @ 1c00095bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl implatTaskOffloadRecalculateAndIndicateChange(struct _IMPLAT_VIRTMINI * __ptr64) */

void __cdecl implatTaskOffloadRecalculateAndIndicateChange(_IMPLAT_VIRTMINI *param_1)

{
  _IMPLAT_STANDARDIZED_KEYWORD *p_Var1;
  _IMPLAT_VIRTMINI *_Buf1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  _IMPLAT_VIRTMINI _Var8;
  _IMPLAT_VIRTMINI *p_Var9;
  uchar uVar10;
  undefined8 uVar11;
  byte bVar12;
  undefined1 auStackY_258 [32];
  undefined4 local_228 [2];
  undefined8 local_220;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined8 local_208;
  undefined8 uStack_200;
  _IMPLAT_VIRTMINI *local_1f8;
  undefined4 local_1f0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined8 local_178;
  undefined8 uStack_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined4 local_108;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined4 local_48;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_258;
  memset(&local_f8,0,0xb4);
  memset(&local_1b8,0,0xb4);
  uVar10 = '\x01';
  bVar3 = false;
  bVar2 = false;
  if (*(int *)(param_1 + 0x8dc) == 1) {
    lVar5 = *(longlong *)(param_1 + 0x8dc) - *(longlong *)(*(longlong *)(param_1 + 0x48) + 0x15c);
    if (lVar5 == 0) {
      lVar5 = (ulonglong)*(uint *)(param_1 + 0x8e4) -
              (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x48) + 0x164);
    }
    bVar3 = false;
    bVar2 = false;
    if (lVar5 != 0) {
      bVar3 = true;
      bVar2 = true;
    }
  }
  if (*(int *)(param_1 + 0x8e8) == 1) {
    lVar5 = *(longlong *)(param_1 + 0x8e8) - *(longlong *)(*(longlong *)(param_1 + 0x48) + 0x168);
    if (lVar5 == 0) {
      lVar5 = (ulonglong)*(uint *)(param_1 + 0x8f0) -
              (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x48) + 0x170);
    }
    if (lVar5 != 0) {
      bVar3 = true;
      bVar2 = true;
    }
  }
  lVar5 = *(longlong *)(param_1 + 0x48);
  p_Var1 = (_IMPLAT_STANDARDIZED_KEYWORD *)(lVar5 + 0x178);
  implatTaskOffloadInit((_NDIS_OFFLOAD *)&local_f8,p_Var1,'\x01');
  implatTaskOffloadInit((_NDIS_OFFLOAD *)&local_1b8,p_Var1,uVar10);
  bVar12 = *(byte *)(lVar5 + 0xe8);
  for (p_Var9 = *(_IMPLAT_VIRTMINI **)(param_1 + 0x60); p_Var9 != param_1 + 0x60;
      p_Var9 = *(_IMPLAT_VIRTMINI **)p_Var9) {
    lVar5 = *(longlong *)(p_Var9 + -0x20);
    implatTaskOffloadLowestCommonDenominator
              ((_NDIS_OFFLOAD *)&local_f8,(_NDIS_OFFLOAD *)(lVar5 + 0x148));
    implatTaskOffloadLowestCommonDenominator
              ((_NDIS_OFFLOAD *)&local_1b8,(_NDIS_OFFLOAD *)(lVar5 + 0x28c));
    bVar12 = bVar12 & *(byte *)(lVar5 + 0x1af0);
    if (*(int *)(param_1 + 0x8dc) == 1) {
      lVar6 = *(longlong *)(param_1 + 0x8dc) - *(longlong *)(lVar5 + 0x344);
      if (lVar6 == 0) {
        lVar6 = (ulonglong)*(uint *)(param_1 + 0x8e4) - (ulonglong)*(uint *)(lVar5 + 0x34c);
      }
      bVar2 = bVar3;
      if (lVar6 != 0) {
        bVar2 = true;
        bVar3 = true;
      }
    }
    if (*(int *)(param_1 + 0x8e8) == 1) {
      lVar6 = *(longlong *)(param_1 + 0x8e8) - *(longlong *)(lVar5 + 0x350);
      if (lVar6 == 0) {
        lVar6 = (ulonglong)*(uint *)(param_1 + 0x8f0) - (ulonglong)*(uint *)(lVar5 + 0x358);
      }
      bVar3 = bVar2;
      if (lVar6 != 0) {
        bVar3 = true;
        bVar2 = true;
      }
    }
  }
  implatTaskOffloadFinal((_NDIS_OFFLOAD *)&local_f8);
  implatTaskOffloadFinal((_NDIS_OFFLOAD *)&local_1b8);
  if (bVar2) {
    memset((void *)((longlong)&local_1b8 + 4),0,0xb0);
    bVar12 = 0;
  }
  p_Var9 = param_1 + 0x824;
  iVar4 = memcmp(p_Var9,&local_f8,0xb4);
  if (iVar4 != 0) {
    param_1[0x8f4] = (_IMPLAT_VIRTMINI)((byte)param_1[0x8f4] & 0xfb);
  }
  _Var8 = param_1[0x8f4];
  _Buf1 = param_1 + 0x770;
  iVar4 = memcmp(_Buf1,&local_1b8,0xb4);
  if (iVar4 != 0) {
    _Var8 = (_IMPLAT_VIRTMINI)((byte)_Var8 & 0xfd);
  }
  *(undefined8 *)p_Var9 = local_f8;
  *(undefined8 *)(param_1 + 0x82c) = uStack_f0;
  *(undefined8 *)(param_1 + 0x834) = local_e8;
  *(undefined8 *)(param_1 + 0x83c) = uStack_e0;
  _Var8 = (_IMPLAT_VIRTMINI)(((byte)_Var8 ^ bVar12) & 1 ^ (byte)_Var8);
  param_1[0x8f4] = _Var8;
  *(undefined8 *)(param_1 + 0x844) = local_d8;
  *(undefined8 *)(param_1 + 0x84c) = uStack_d0;
  *(undefined8 *)(param_1 + 0x854) = local_c8;
  *(undefined8 *)(param_1 + 0x85c) = uStack_c0;
  *(undefined8 *)(param_1 + 0x864) = local_b8;
  *(undefined8 *)(param_1 + 0x86c) = uStack_b0;
  *(undefined8 *)(param_1 + 0x874) = local_a8;
  *(undefined8 *)(param_1 + 0x87c) = uStack_a0;
  *(undefined8 *)(param_1 + 0x884) = local_98;
  *(undefined8 *)(param_1 + 0x88c) = uStack_90;
  *(undefined8 *)(param_1 + 0x894) = local_88;
  *(undefined8 *)(param_1 + 0x89c) = uStack_80;
  *(undefined8 *)(param_1 + 0x8a4) = local_78;
  *(undefined8 *)(param_1 + 0x8ac) = uStack_70;
  *(undefined8 *)(param_1 + 0x8b4) = local_68;
  *(undefined8 *)(param_1 + 0x8bc) = uStack_60;
  *(undefined8 *)(param_1 + 0x8c4) = local_58;
  *(undefined8 *)(param_1 + 0x8cc) = uStack_50;
  *(undefined4 *)(param_1 + 0x8d4) = local_48;
  *(undefined8 *)_Buf1 = local_1b8;
  *(undefined8 *)(param_1 + 0x778) = uStack_1b0;
  *(undefined8 *)(param_1 + 0x780) = local_1a8;
  *(undefined8 *)(param_1 + 0x788) = uStack_1a0;
  *(undefined8 *)(param_1 + 0x790) = local_198;
  *(undefined8 *)(param_1 + 0x798) = uStack_190;
  *(undefined8 *)(param_1 + 0x7a0) = local_188;
  *(undefined8 *)(param_1 + 0x7a8) = uStack_180;
  *(undefined8 *)(param_1 + 0x7b0) = local_178;
  *(undefined8 *)(param_1 + 0x7b8) = uStack_170;
  *(undefined8 *)(param_1 + 0x7c0) = local_168;
  *(undefined8 *)(param_1 + 0x7c8) = uStack_160;
  *(undefined8 *)(param_1 + 2000) = local_158;
  *(undefined8 *)(param_1 + 0x7d8) = uStack_150;
  *(undefined8 *)(param_1 + 0x7e0) = local_148;
  *(undefined8 *)(param_1 + 0x7e8) = uStack_140;
  *(undefined8 *)(param_1 + 0x7f0) = local_138;
  *(undefined8 *)(param_1 + 0x7f8) = uStack_130;
  *(undefined8 *)(param_1 + 0x800) = local_128;
  *(undefined8 *)(param_1 + 0x808) = uStack_120;
  *(undefined8 *)(param_1 + 0x810) = local_118;
  *(undefined8 *)(param_1 + 0x818) = uStack_110;
  *(undefined4 *)(param_1 + 0x820) = local_108;
  if (2 < *(int *)(param_1 + 200)) {
    if (((byte)_Var8 & 4) == 0) {
      uVar11 = 0x70;
      memset(local_228,0,0x70);
      uVar7 = *(undefined8 *)(param_1 + 0x20);
      local_218 = 0;
      local_210 = 0;
      local_208 = 0;
      uStack_200 = 0;
      local_228[0] = 0x700198;
      local_214 = 0x40020007;
      local_1f0 = 0xb4;
      param_1[0x8f4] = (_IMPLAT_VIRTMINI)((byte)_Var8 | 4);
      local_220 = uVar7;
      local_1f8 = p_Var9;
      NdisMIndicateStatusEx();
      if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
        McTemplateK0zqbr1_EtwWriteTransfer
                  (uVar7,&TNicTaskOffloadHwCapsInfo,uVar11,*(wchar_t **)(param_1 + 0x30),local_1f0,
                   local_1f8);
      }
    }
    _Var8 = param_1[0x8f4];
    if (((byte)_Var8 & 2) == 0) {
      uVar11 = 0x70;
      memset(local_228,0,0x70);
      uVar7 = *(undefined8 *)(param_1 + 0x20);
      local_218 = 0;
      local_210 = 0;
      local_208 = 0;
      uStack_200 = 0;
      local_228[0] = 0x700198;
      local_214 = 0x40020006;
      local_1f0 = 0xb4;
      param_1[0x8f4] = (_IMPLAT_VIRTMINI)((byte)_Var8 | 2);
      local_220 = uVar7;
      local_1f8 = _Buf1;
      NdisMIndicateStatusEx(uVar7,local_228);
      if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
        McTemplateK0zqbr1_EtwWriteTransfer
                  (uVar7,&TNicTaskOffloadCurCfgInfo,uVar11,*(wchar_t **)(param_1 + 0x30),local_1f0,
                   local_1f8);
      }
    }
  }
  return;
}



===== implatTeamMinimumCapabilitiesFromRegistry @ 1c0009a48 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl implatTeamMinimumCapabilitiesFromRegistry(struct _IMPLAT_VIRTMINI * __ptr64,unsigned
   long * __ptr64,unsigned long * __ptr64) */

void __cdecl
implatTeamMinimumCapabilitiesFromRegistry(_IMPLAT_VIRTMINI *param_1,ulong *param_2,ulong *param_3)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  int local_res8 [2];
  longlong local_res18;
  longlong local_res20;
  ulonglong uVar6;
  undefined8 *puVar7;
  longlong local_d8;
  undefined8 local_d0;
  longlong local_c8;
  longlong local_c0;
  longlong local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  wchar_t *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  wchar_t *local_78;
  undefined8 local_70;
  wchar_t *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  lVar2 = *(longlong *)(param_1 + 0x48);
  local_a0 = L"Adapters";
  local_res18 = 0;
  local_78 = L"Teams";
  local_d8 = 0;
  local_68 = L"MacOptions";
  local_b8 = 0;
  local_58 = L"MtuSize";
  local_90 = _Global;
  local_c0 = 0;
  local_c8 = 0;
  local_res20 = 0;
  local_b0 = 0;
  local_d0 = 0;
  local_a8 = 0x120010;
  local_80 = 0xc000a;
  local_70 = 0x160014;
  local_60 = 0x10000e;
  local_50 = 0;
  uStack_48 = 0;
  local_98 = 0x1401a9;
  local_88 = 0;
  local_res8[0] = NdisOpenConfigurationEx(&local_98,&local_d8);
  if (local_res8[0] == 0) {
    NdisOpenConfigurationKeyByName(local_res8,local_d8,&local_a8,&local_b8);
    if (local_res8[0] == 0) {
      NdisOpenConfigurationKeyByName(local_res8,local_d8,&local_80,&local_c0);
      if (local_res8[0] == 0) {
        NdisOpenConfigurationKeyByName(local_res8,local_c0,lVar2 + 0x20,&local_c8);
        if (local_res8[0] == 0) {
          NdisOpenConfigurationKeyByName(local_res8,local_c8,&local_a8,&local_res20);
          if (local_res8[0] == 0) {
            iVar4 = 0;
            while( true ) {
              puVar7 = &local_b0;
              NdisOpenConfigurationKeyByIndex(local_res8,local_res20,iVar4,&local_50,puVar7);
              if (local_res8[0] != 0) break;
              NdisOpenConfigurationKeyByName(local_res8,local_b8,&local_50,&local_d0);
              if (local_res8[0] == 0) {
                uVar6 = (ulonglong)puVar7 & 0xffffffff00000000;
                uVar5 = local_d0;
                NdisReadConfiguration(local_res8,&local_res18,local_d0,&local_70,uVar6);
                if (local_res8[0] == 0) {
                  uVar1 = *param_3;
                  uVar3 = *(uint *)(local_res18 + 8) & uVar1;
                  if (uVar1 != uVar3) {
                    if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
                      uVar6 = CONCAT44((int)(uVar6 >> 0x20),uVar1);
                      McTemplateK0zqq_EtwWriteTransfer
                                ((ulonglong)uVar1,&TNicMacOptionsReducedInfo,uVar5,
                                 *(wchar_t **)(param_1 + 0x30),(char)uVar1,(char)uVar3);
                    }
                    *param_3 = uVar3;
                  }
                }
                NdisReadConfiguration
                          (local_res8,&local_res18,local_d0,&local_60,uVar6 & 0xffffffff00000000);
                if (local_res8[0] == 0) {
                  uVar1 = *param_2;
                  if (*(uint *)(local_res18 + 8) < uVar1) {
                    if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
                      McTemplateK0zqq_EtwWriteTransfer
                                (local_res18,&TNicMtuSizeReducedInfo,(ulonglong)uVar1,
                                 *(wchar_t **)(param_1 + 0x30),(char)uVar1,
                                 (char)*(uint *)(local_res18 + 8));
                    }
                    *param_2 = *(ulong *)(local_res18 + 8);
                  }
                }
                NdisCloseConfiguration(local_d0);
              }
              NdisCloseConfiguration(local_b0);
              iVar4 = iVar4 + 1;
            }
            local_res8[0] = 0;
          }
          else {
            local_res20 = 0;
          }
        }
        else {
          local_c8 = 0;
        }
      }
      else {
        local_c0 = 0;
      }
    }
    else {
      local_b8 = 0;
    }
  }
  else {
    local_d8 = 0;
  }
  *param_3 = *param_3 | 0xc;
  if (local_res20 != 0) {
    NdisCloseConfiguration();
  }
  if (local_c8 != 0) {
    NdisCloseConfiguration();
  }
  if (local_c0 != 0) {
    NdisCloseConfiguration();
  }
  if (local_b8 != 0) {
    NdisCloseConfiguration();
  }
  if (local_d8 != 0) {
    NdisCloseConfiguration();
  }
  return;
}



===== implatWaitForOutstandingIndicationsOnVirtMini @ 1c0009da4 =====

/* void __cdecl implatWaitForOutstandingIndicationsOnVirtMini(struct _IMPLAT_VIRTMINI * __ptr64) */

void __cdecl implatWaitForOutstandingIndicationsOnVirtMini(_IMPLAT_VIRTMINI *param_1)

{
  int *piVar1;
  ulonglong uVar2;
  int iVar3;
  
  KeFlushQueuedDpcs();
  while( true ) {
    uVar2 = (ulonglong)DAT_1c001b278;
    iVar3 = 0;
    if (DAT_1c001b278 == 0) {
      return;
    }
    piVar1 = (int *)(*(longlong *)(param_1 + 0xf0) + 4);
    do {
      iVar3 = iVar3 + *piVar1;
      piVar1 = piVar1 + 0x30;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
    if (iVar3 == 0) break;
    NdisMSleep(0x32);
  }
  return;
}



===== McTemplateK0zqbr1_EtwWriteTransfer @ 1c0009e08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zqbr1_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               undefined4 param_5,undefined8 param_6)

{
  longlong lVar1;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  if (param_4 == (wchar_t *)0x0) {
    local_40 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    local_40 = (int)lVar1 * 2 + 2;
  }
  local_3c = 0;
  local_38 = &param_5;
  local_1c = 0;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  local_28 = param_6;
  local_20 = param_5;
  local_30 = 4;
  local_48 = param_4;
  McGenEventWrite_EtwWriteTransfer(L"NULL",param_2,0,4,local_58);
  return;
}



===== McTemplateK0zqq_EtwWriteTransfer @ 1c0009eb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zqq_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6)

{
  longlong lVar1;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  if (param_4 == (wchar_t *)0x0) {
    local_40 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_4[lVar1] != L'\0');
    local_40 = (int)lVar1 * 2 + 2;
  }
  local_3c = 0;
  local_38 = &param_5;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  local_28 = &param_6;
  local_30 = 4;
  local_20 = 4;
  local_48 = param_4;
  McGenEventWrite_EtwWriteTransfer(L"NULL",param_2,0,4,local_58);
  return;
}



===== WPP_SF_DL @ 1c0009f50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,0);
  return;
}



===== WPP_SF_S @ 1c0009fa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_S(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4)

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
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,0xf,param_4,lVar1,0);
  return;
}



===== WPP_SF_qS @ 1c000a014 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qS(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              wchar_t *param_5)

{
  longlong lVar1;
  undefined8 local_res20;
  
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
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,0x10,&local_res20,8,
             param_5,lVar1,0);
  return;
}



===== WPP_SF_qq @ 1c000a0ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== WPP_SF_qqd @ 1c000a0fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,&param_6,4,0);
  return;
}



===== vmqcGenerateStatusIndication @ 1c000a15c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void vmqcGenerateStatusIndication
               (longlong param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined4 local_94;
  undefined8 local_78;
  undefined4 local_70;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  local_a4 = 0;
  memset((void *)((longlong)&local_a8 + 1),0,0x6f);
  local_a0 = *(undefined8 *)(param_1 + -0xd8);
  local_a8 = 0x700198;
  if (2 < *(int *)(param_1 + -0x30)) {
    local_94 = param_2;
    local_78 = param_3;
    local_70 = param_4;
    NdisMIndicateStatusEx(local_a0,&local_a8);
  }
  return;
}



===== vmqcGetNextMNic @ 1c000a1f8 =====

void vmqcGetNextMNic(longlong param_1,longlong *param_2,int *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  int iVar5;
  
  for (puVar4 = *(undefined8 **)(param_1 + -0x98); plVar2 = puVar4 + -4,
      *plVar2 != *param_2 + -0x1af8; puVar4 = (undefined8 *)*puVar4) {
  }
  puVar4 = (undefined8 *)*puVar4;
  lVar3 = 0;
  do {
    if (puVar4 == (undefined8 *)(param_1 + -0x98)) {
      iVar5 = 0;
LAB_1c000a249:
      *param_2 = lVar3;
      *param_3 = iVar5;
      return;
    }
    plVar1 = plVar2 + 4;
    plVar2 = (longlong *)(*plVar1 + -0x20);
    iVar5 = *(int *)(*plVar1 + 0x40);
    if (iVar5 != 0) {
      lVar3 = *plVar2 + 0x1af8;
      goto LAB_1c000a249;
    }
    puVar4 = (undefined8 *)*puVar4;
  } while( true );
}



===== RtlUnicodeStringPrintf @ 1c000a264 =====

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



===== implatAllocatePort @ 1c000a304 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* int __cdecl implatAllocatePort(struct _IMPLAT_INTERNAL_BINDING * __ptr64) */

int __cdecl implatAllocatePort(_IMPLAT_INTERNAL_BINDING *param_1)

{
  longlong lVar1;
  int iVar2;
  _IMPLAT_INTERNAL_BINDING *p_Var3;
  undefined *puVar4;
  undefined1 auStackY_1a8 [32];
  undefined2 local_178;
  undefined1 local_176;
  undefined1 local_168 [32];
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined4 local_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined4 local_100;
  undefined1 *local_f8;
  undefined4 local_f0;
  undefined4 local_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_1a8;
  iStack_54 = 0;
  uStack_44 = 0;
  uStack_1c = 0;
  iVar2 = 0;
  memset(&local_108,0,0xb0);
  memset(local_168,0,0x60);
  local_178 = 0;
  local_176 = 0;
  if ((*(longlong *)(*(longlong *)(param_1 + 8) + 0x20) != 0) && (*(int *)(param_1 + 0x60) == 0)) {
    puVar4 = (undefined *)0x0;
    NdisAcquireRWLockWrite
              (*(undefined8 *)(*(longlong *)(*(longlong *)param_1 + 0x28) + 0x88),&local_178);
    lVar1 = *(longlong *)param_1;
    iStack_54 = 0;
    uStack_50 = 0;
    uStack_44 = 0;
    uStack_1c = 0;
    local_58 = 0x3c0180;
    uStack_4c = 4;
    local_48 = *(undefined4 *)(lVar1 + 0xcc);
    uStack_40 = *(undefined8 *)(lVar1 + 0xd8);
    local_38 = *(undefined8 *)(lVar1 + 0xe0);
    uStack_2c = 2;
    local_28 = 2;
    uStack_30 = 0;
    uStack_20 = 0;
    iVar2 = NdisMAllocatePort(*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x20),&local_58);
    if (iVar2 == 0) {
      *(int *)(param_1 + 0x60) = iStack_54;
      *(undefined4 *)(param_1 + 0x68) = 0;
      RtlInsertEntryHashTable
                (*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x70),param_1 + 0x48,iStack_54 + 1,0);
      puVar4 = (undefined *)(ulonglong)(*(int *)(*(longlong *)(param_1 + 8) + 0x440) + 1);
      RtlInsertEntryHashTable(*(undefined8 *)(*(longlong *)param_1 + 0x248),param_1 + 0x30,puVar4,0)
      ;
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(*(longlong *)param_1 + 0x28) + 0x88),
                        &local_178);
      local_148 = CONCAT44(iStack_54,local_58);
      uStack_140 = CONCAT44(uStack_4c,uStack_50);
      local_f8 = local_168;
      local_138 = CONCAT44(uStack_44,local_48);
      uStack_130 = uStack_40;
      uStack_110 = CONCAT44(uStack_1c,uStack_20);
      local_128 = (undefined4)local_38;
      uStack_124 = local_38._4_4_;
      uStack_120 = uStack_30;
      uStack_11c = uStack_2c;
      local_118 = local_28;
      local_108 = 0xa40180;
      local_100 = 10;
      local_f0 = 0x60;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        puVar4 = &WPP_8057de2231843b45df4bd7d91c3cd38a_Traceguids;
        WPP_SF_DDL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                   &WPP_8057de2231843b45df4bd7d91c3cd38a_Traceguids,
                   *(undefined4 *)(*(longlong *)param_1 + 0xb0),(char)iStack_54,(char)local_48);
      }
      iVar2 = NdisMNetPnPEvent(*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x20),&local_108);
      if (iVar2 == 0) {
        param_1[100] = (_IMPLAT_INTERNAL_BINDING)0x1;
        return 0;
      }
      p_Var3 = param_1;
      implatFreePort(param_1);
    }
    else {
      p_Var3 = *(_IMPLAT_INTERNAL_BINDING **)(*(longlong *)(*(longlong *)param_1 + 0x28) + 0x88);
      NdisReleaseRWLock(p_Var3,&local_178);
    }
    if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 4) != 0) {
      McTemplateK0zzd_EtwWriteTransfer
                (p_Var3,&MemberPortAllocationFailedErr,puVar4,
                 *(wchar_t **)(*(longlong *)(param_1 + 8) + 0x30),
                 *(wchar_t **)(*(longlong *)param_1 + 0x58),(char)iVar2);
    }
    SysEventWriteStrStrStatus
              (-0x7fffbd9b,*(ushort **)(*(longlong *)(param_1 + 8) + 0x30),
               *(ushort **)(*(longlong *)param_1 + 0x58),iVar2);
  }
  return iVar2;
}



===== implatCreateInternalBinding @ 1c000a5ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* int __cdecl implatCreateInternalBinding(struct _IMPLAT_ADAPTER * __ptr64,struct _IMPLAT_VIRTMINI
   * __ptr64,struct _IMPLAT_INTERNAL_BINDING * __ptr64 * __ptr64) */

int __cdecl
implatCreateInternalBinding
          (_IMPLAT_ADAPTER *param_1,_IMPLAT_VIRTMINI *param_2,_IMPLAT_INTERNAL_BINDING **param_3)

{
  longlong *plVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  _IMPLAT_INTERNAL_BINDING *p_Var9;
  undefined8 *puVar10;
  _IMPLAT_INTERNAL_BINDING *p_Var11;
  longlong lVar12;
  undefined2 uVar13;
  _IMPLAT_VIRTMINI *p_Var14;
  undefined8 *puVar15;
  uint uVar16;
  undefined8 uVar17;
  undefined *puVar18;
  undefined1 auStackY_d8 [32];
  undefined2 local_98;
  undefined1 local_96;
  undefined8 local_90;
  undefined4 local_88;
  undefined5 uStack_84;
  undefined7 uStack_7f;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined1 uStack_70;
  undefined4 uStack_6f;
  undefined2 uStack_6b;
  undefined1 local_69;
  undefined1 uStack_68;
  undefined8 local_67;
  undefined8 uStack_5f;
  undefined8 local_57;
  undefined2 local_4f;
  undefined1 local_4d;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_98 = 0;
  local_96 = 0;
  bVar7 = false;
  local_90 = 0;
  p_Var14 = param_2;
  if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
    p_Var14 = (_IMPLAT_VIRTMINI *)&CreatingInternalBindingInfo;
    McTemplateK0zz_EtwWriteTransfer
              (param_1,&CreatingInternalBindingInfo,param_3,*(wchar_t **)(param_2 + 0x30),
               *(wchar_t **)(param_1 + 0x58));
  }
  puVar18 = (undefined *)0x0;
  p_Var11 = (_IMPLAT_INTERNAL_BINDING *)0x70;
  p_Var9 = implatAllocateNonPagedPoolWithTagPriority(0x70,(ulong)p_Var14,0);
  if (p_Var9 == (_IMPLAT_INTERNAL_BINDING *)0x0) {
    iVar8 = -0x3fffff66;
    p_Var9 = p_Var11;
    goto LAB_1c000a77c;
  }
  uVar17 = 0x60;
  memset(p_Var9 + 0x10,0,0x60);
  *(_IMPLAT_ADAPTER **)p_Var9 = param_1;
  *(_IMPLAT_VIRTMINI **)(p_Var9 + 8) = param_2;
  IPsecLbfoOffloadMapWaitForIdleAndAcquireExclusiveTeamLock(*(longlong *)(param_2 + 0x48),&local_98)
  ;
  if (param_2[0x710] == (_IMPLAT_VIRTMINI)0x0) {
LAB_1c000a7e1:
    NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_2 + 0x48) + 0x88),&local_98);
    KeWaitForSingleObject(*(longlong *)(param_1 + 0x28) + 0x90,0,0,0);
    IPsecLbfoOffloadMapWaitForIdleAndAcquireExclusiveTeamLock
              (*(longlong *)(param_2 + 0x48),&local_98);
    if ((*(longlong *)(param_1 + 800) == 0) ||
       ((*(byte *)(*(longlong *)(param_1 + 0x28) + 0xe8) & 1) == 0)) {
LAB_1c000a8d8:
      if ((*(int *)(*(longlong *)(param_1 + 0x28) + 0x15c) != 0) ||
         (*(int *)(*(longlong *)(param_1 + 0x28) + 0x168) != 0)) {
        NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_2 + 0x48) + 0x88),&local_98);
        iVar8 = implatDoOidRequestOnAdapter
                          (param_1,1,0x101010a,(void *)(*(longlong *)(param_1 + 0x28) + 0x158),0x1c,
                           (_NDIS_OID_REQUEST *)0x0,(_IMPLAT_VIRTMINI *)0x0);
        IPsecLbfoOffloadMapWaitForIdleAndAcquireExclusiveTeamLock
                  (*(longlong *)(param_2 + 0x48),&local_98);
        if (iVar8 == 0) {
          lVar12 = *(longlong *)(param_1 + 0x28);
          uVar3 = *(undefined4 *)(lVar12 + 0x15c);
          uVar4 = *(undefined4 *)(lVar12 + 0x160);
          uVar5 = *(undefined4 *)(lVar12 + 0x164);
          *(undefined4 *)(param_1 + 0x340) = *(undefined4 *)(lVar12 + 0x158);
          *(undefined4 *)(param_1 + 0x344) = uVar3;
          *(undefined4 *)(param_1 + 0x348) = uVar4;
          *(undefined4 *)(param_1 + 0x34c) = uVar5;
          *(undefined8 *)(param_1 + 0x350) = *(undefined8 *)(lVar12 + 0x168);
          *(undefined4 *)(param_1 + 0x358) = *(undefined4 *)(lVar12 + 0x170);
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar13 = 0xe;
            goto LAB_1c000a98a;
          }
        }
        else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar13 = 0xd;
LAB_1c000a98a:
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar13,
                   &WPP_8057de2231843b45df4bd7d91c3cd38a_Traceguids,param_1);
        }
      }
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_2 + 0x48) + 0x88),&local_98);
      KeReleaseMutex(*(longlong *)(param_1 + 0x28) + 0x90,0);
      IPsecLbfoOffloadMapWaitForIdleAndAcquireExclusiveTeamLock
                (*(longlong *)(param_2 + 0x48),&local_98);
      plVar1 = *(longlong **)(param_1 + 0x240);
      p_Var11 = p_Var9 + 0x10;
      if ((_IMPLAT_ADAPTER *)*plVar1 != param_1 + 0x238) {
LAB_1c000ae19:
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        pcVar2 = (code *)swi(3);
        iVar8 = (*pcVar2)();
        return iVar8;
      }
      *(_IMPLAT_ADAPTER **)p_Var11 = param_1 + 0x238;
      *(longlong **)(p_Var9 + 0x18) = plVar1;
      *plVar1 = (longlong)p_Var11;
      *(_IMPLAT_INTERNAL_BINDING **)(param_1 + 0x240) = p_Var11;
      plVar1 = *(longlong **)(param_2 + 0x68);
      p_Var11 = p_Var9 + 0x20;
      if ((_IMPLAT_VIRTMINI *)*plVar1 != param_2 + 0x60) goto LAB_1c000ae19;
      *(_IMPLAT_VIRTMINI **)p_Var11 = param_2 + 0x60;
      *(longlong **)(p_Var9 + 0x28) = plVar1;
      *plVar1 = (longlong)p_Var11;
      *(_IMPLAT_INTERNAL_BINDING **)(param_2 + 0x68) = p_Var11;
      *(int *)(param_2 + 0x58) = *(int *)(param_2 + 0x58) + 1;
      if (*(uint *)(param_2 + 0x78) <= *(uint *)(param_2 + 0x58)) {
        KeSetEvent(param_2 + 0x80,0,0);
      }
      LOCK();
      p_Var14 = param_2 + 0x50;
      iVar8 = *(int *)p_Var14;
      *(int *)p_Var14 = *(int *)p_Var14 + 1;
      UNLOCK();
      puVar18 = (undefined *)(ulonglong)(iVar8 + 1U);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        puVar18 = &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids;
        WPP_SF_qdS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                   &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,param_2,(char)(iVar8 + 1U),
                   L"CreateInternalBinding");
      }
      bVar7 = true;
      implatTaskOffloadRecalculateAndIndicateChange(param_2);
      implatCalculateVirtMiniLinkState(param_2);
      implatRecalculatePMCapabilities(*(_IMPLAT_TEAM **)(param_2 + 0x48));
      if (2 < *(int *)(param_2 + 200)) {
        implatCalculateVmqCaps(param_2,'\x01');
      }
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_2 + 0x48) + 0x88),&local_98);
      iVar8 = implatCheckAdapterOffloadParameters(param_1);
      if (iVar8 == 0) {
        iVar8 = implatRecalculateAdapterPacketFilters(param_1);
        if (iVar8 == 0) {
          if ((param_2[0x444] != (_IMPLAT_VIRTMINI)0x0) && (*(int *)(param_2 + 0x440) == 0)) {
            puVar18 = (undefined *)0xfd010109;
            iVar8 = implatDoOidRequestOnAdapter
                              (param_1,1,0xfd010109,(void *)(*(longlong *)(param_1 + 0x28) + 0x480),
                               0x14,(_NDIS_OID_REQUEST *)0x0,(_IMPLAT_VIRTMINI *)0x0);
            if (iVar8 == 0) {
              lVar12 = *(longlong *)(param_1 + 0x28);
              puVar10 = (undefined8 *)(lVar12 + 0x498);
              for (puVar15 = (undefined8 *)*puVar10; puVar15 != puVar10;
                  puVar15 = (undefined8 *)*puVar15) {
                puVar18 = (undefined *)(ulonglong)*(uint *)(puVar15 + 2);
                iVar8 = implatAddWolPatternOnAdapter
                                  (param_1,(_NDIS_PM_WOL_PATTERN *)(puVar15 + 3),
                                   *(uint *)(puVar15 + 2));
                if (iVar8 != 0) {
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000ad85;
                  uVar13 = 0xb;
                  goto LAB_1c000ad72;
                }
                lVar12 = *(longlong *)(param_1 + 0x28);
                puVar10 = (undefined8 *)(lVar12 + 0x498);
              }
              puVar10 = (undefined8 *)(lVar12 + 0x4a8);
              for (puVar15 = (undefined8 *)*puVar10; puVar15 != puVar10;
                  puVar15 = (undefined8 *)*puVar15) {
                iVar8 = implatAddPMOffloadOnAdapter
                                  (param_1,(_NDIS_PM_PROTOCOL_OFFLOAD *)(puVar15 + 3));
                if (iVar8 != 0) {
                  if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
                      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) ||
                     ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000ad85;
                  uVar13 = 0xc;
                  goto LAB_1c000ad72;
                }
                puVar10 = (undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x4a8);
              }
            }
            else {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar13 = 10;
LAB_1c000ad72:
                puVar18 = &WPP_5e95b5ed910d35ca391433f1176714fe_Traceguids;
                WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar13,
                         &WPP_5e95b5ed910d35ca391433f1176714fe_Traceguids,param_1);
              }
LAB_1c000ad85:
              uStack_84 = 0;
              uStack_7f = 0;
              local_88 = 0x3c0280;
              uStack_78 = 0;
              uStack_74 = 0;
              uStack_70 = 0;
              uStack_6f = 0;
              uStack_6b = 0;
              local_69 = 0;
              uStack_68 = 0;
              local_57 = 0;
              local_67 = 0;
              uStack_5f = 0;
              local_4f = 0;
              local_4d = 0;
              implatSetAdapterPMCaps(param_1,(_NDIS_PM_CAPABILITIES *)&local_88);
            }
          }
          iVar8 = implatUpdateVirtMiniDeviceCharacteristics(param_2);
          if (iVar8 == 0) {
            return 0;
          }
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            puVar18 = &WPP_8057de2231843b45df4bd7d91c3cd38a_Traceguids;
            WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                       &WPP_8057de2231843b45df4bd7d91c3cd38a_Traceguids,param_1,(char)param_2,
                       (char)iVar8);
          }
        }
        else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar13 = 0x10;
          goto LAB_1c000abf2;
        }
      }
      else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar13 = 0xf;
LAB_1c000abf2:
        goto LAB_1c000a9f0;
      }
    }
    else {
      uStack_84 = 0;
      uStack_7f = 0;
      uStack_74 = 0;
      uStack_6b = 0;
      local_69 = 0;
      local_88 = 0x1a0380;
      uStack_78 = 1;
      uStack_70 = 1;
      uStack_6f = 1;
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_2 + 0x48) + 0x88),&local_98);
      puVar18 = (undefined *)0xfc01020c;
      iVar8 = implatDoOidRequestOnAdapter
                        (param_1,1,0xfc01020c,&local_88,0x20,(_NDIS_OID_REQUEST *)0x0,
                         (_IMPLAT_VIRTMINI *)0x0);
      if (iVar8 == 0) {
        IPsecLbfoOffloadMapWaitForIdleAndAcquireExclusiveTeamLock
                  (*(longlong *)(param_2 + 0x48),&local_98);
        param_1[0x1af0] = (_IMPLAT_ADAPTER)((byte)param_1[0x1af0] | 1);
        goto LAB_1c000a8d8;
      }
      KeReleaseMutex(*(longlong *)(param_1 + 0x28) + 0x90,0);
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c000ae03;
      uVar13 = 0xc;
      bVar7 = false;
LAB_1c000a9f0:
      puVar18 = &WPP_8057de2231843b45df4bd7d91c3cd38a_Traceguids;
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar13,
                &WPP_8057de2231843b45df4bd7d91c3cd38a_Traceguids,param_1,(char)iVar8);
    }
LAB_1c000ae03:
    if (bVar7) {
      implatRemoveInternalBinding(p_Var9);
      goto LAB_1c000a77c;
    }
  }
  else {
    bVar6 = true;
    uVar16 = *(uint *)(param_2 + 0x720);
    if ((((*(uint *)(param_1 + 0x68) < uVar16) &&
         (bVar6 = false, (undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_dd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar16,uVar17,
                *(uint *)(param_1 + 0x68),(char)uVar16);
    }
    uVar16 = *(uint *)(param_2 + 0x738) & 0x240;
    if ((*(uint *)(param_1 + 0x90) & uVar16) == uVar16) {
      if (bVar6) goto LAB_1c000a7e1;
    }
    else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,(ulonglong)uVar16,
                *(uint *)(param_1 + 0x90),(byte)*(uint *)(param_2 + 0x738) & 0x40);
    }
    iVar8 = -0x3fffffff;
    NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_2 + 0x48) + 0x88),&local_98);
  }
  puVar18 = (undefined *)0x0;
  NdisFreeMemory(p_Var9,0x70);
LAB_1c000a77c:
  if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 4) != 0) {
    McTemplateK0zzd_EtwWriteTransfer
              (p_Var9,&CreatingInternalBindingFailedErr,puVar18,*(wchar_t **)(param_2 + 0x30),
               *(wchar_t **)(param_1 + 0x58),(char)iVar8);
  }
  SysEventWriteStrStrStatus
            (-0x7fffbd9a,*(ushort **)(param_2 + 0x30),*(ushort **)(param_1 + 0x58),iVar8);
  return iVar8;
}



===== implatFindAdapterByPortNumber @ 1c000ae28 =====

/* struct _IMPLAT_ADAPTER * __ptr64 __cdecl implatFindAdapterByPortNumber(struct _IMPLAT_VIRTMINI *
   __ptr64,unsigned long,struct _IMPLAT_INTERNAL_BINDING * __ptr64 * __ptr64) */

_IMPLAT_ADAPTER * __cdecl
implatFindAdapterByPortNumber
          (_IMPLAT_VIRTMINI *param_1,ulong param_2,_IMPLAT_INTERNAL_BINDING **param_3)

{
  longlong lVar1;
  
  if (param_3 != (_IMPLAT_INTERNAL_BINDING **)0x0) {
    *param_3 = (_IMPLAT_INTERNAL_BINDING *)0x0;
  }
  if ((param_2 == 0) ||
     (lVar1 = RtlLookupEntryHashTable(*(undefined8 *)(param_1 + 0x70),param_2 + 1,0), lVar1 == 0)) {
    return (_IMPLAT_ADAPTER *)0x0;
  }
  if (param_3 != (_IMPLAT_INTERNAL_BINDING **)0x0) {
    *param_3 = (_IMPLAT_INTERNAL_BINDING *)(lVar1 + -0x48);
  }
  return *(_IMPLAT_ADAPTER **)(lVar1 + -0x48);
}



===== implatFreePort @ 1c000ae78 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* int __cdecl implatFreePort(struct _IMPLAT_INTERNAL_BINDING * __ptr64) */

int __cdecl implatFreePort(_IMPLAT_INTERNAL_BINDING *param_1)

{
  _IMPLAT_INTERNAL_BINDING *p_Var1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_108 [32];
  undefined2 local_d8;
  undefined1 local_d6;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  _IMPLAT_INTERNAL_BINDING *local_b8;
  undefined4 local_b0;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_108;
  iVar3 = 0;
  memset(&local_c8,0,0xb0);
  local_d8 = 0;
  local_d6 = 0;
  p_Var1 = param_1 + 0x60;
  uVar2 = *(uint *)p_Var1;
  if (uVar2 != 0) {
    if (param_1[100] != (_IMPLAT_INTERNAL_BINDING)0x0) {
      local_c4 = 0;
      local_c8 = 0xa40180;
      local_b0 = 4;
      local_c0 = 0xb;
      local_b8 = p_Var1;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,(ulonglong)uVar2,
                  *(undefined4 *)(*(longlong *)param_1 + 0xb0),(char)uVar2);
      }
      NdisMNetPnPEvent(*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x20),&local_c8);
      param_1[100] = (_IMPLAT_INTERNAL_BINDING)0x0;
    }
    NdisAcquireRWLockWrite
              (*(undefined8 *)(*(longlong *)(*(longlong *)param_1 + 0x28) + 0x88),&local_d8,0);
    RtlRemoveEntryHashTable(*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x70),param_1 + 0x48,0);
    RtlRemoveEntryHashTable(*(undefined8 *)(*(longlong *)param_1 + 0x248),param_1 + 0x30,0);
    iVar3 = NdisMFreePort(*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x20),
                          *(undefined4 *)(param_1 + 0x60));
    *(undefined4 *)(param_1 + 0x60) = 0;
    *(undefined4 *)(param_1 + 0x68) = 0;
    NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(*(longlong *)param_1 + 0x28) + 0x88),&local_d8);
  }
  return iVar3;
}



===== implatRemoveInternalBinding @ 1c000b008 =====

/* void __cdecl implatRemoveInternalBinding(struct _IMPLAT_INTERNAL_BINDING * __ptr64) */

void __cdecl implatRemoveInternalBinding(_IMPLAT_INTERNAL_BINDING *param_1)

{
  _IMPLAT_INTERNAL_BINDING *p_Var1;
  _IMPLAT_ADAPTER *p_Var2;
  _IMPLAT_VIRTMINI *p_Var3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  int iVar7;
  _IMPLAT_VIRTMINI *p_Var8;
  undefined *puVar9;
  undefined2 local_res8;
  undefined1 local_resa;
  
  p_Var2 = *(_IMPLAT_ADAPTER **)param_1;
  p_Var3 = *(_IMPLAT_VIRTMINI **)(param_1 + 8);
  local_res8 = 0;
  local_resa = 0;
  LOCK();
  p_Var8 = p_Var3 + 0x50;
  iVar7 = *(int *)p_Var8;
  *(int *)p_Var8 = *(int *)p_Var8 + 1;
  UNLOCK();
  puVar9 = (undefined *)(ulonglong)(iVar7 + 1U);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    puVar9 = &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids;
    WPP_SF_qdS(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_7ab2982e56f839dca9aa21be06121d61_Traceguids,p_Var3,(char)(iVar7 + 1U),
               L"RemoveInternalBinding temp");
  }
  if ((p_Var3[0x444] != (_IMPLAT_VIRTMINI)0x0) && (*(int *)(p_Var3 + 0x440) == 0)) {
    implatClearPMParamsOnAdapter(p_Var2);
  }
  IPsecLbfoOffloadMapWaitForIdleAndAcquireExclusiveTeamLock
            (*(longlong *)(p_Var3 + 0x48),&local_res8);
  p_Var1 = param_1 + 0x10;
  lVar4 = *(longlong *)p_Var1;
  if ((*(_IMPLAT_INTERNAL_BINDING **)(lVar4 + 8) == p_Var1) &&
     (plVar5 = *(longlong **)(param_1 + 0x18), (_IMPLAT_INTERNAL_BINDING *)*plVar5 == p_Var1)) {
    *plVar5 = lVar4;
    p_Var1 = param_1 + 0x20;
    *(longlong **)(lVar4 + 8) = plVar5;
    lVar4 = *(longlong *)p_Var1;
    if ((*(_IMPLAT_INTERNAL_BINDING **)(lVar4 + 8) == p_Var1) &&
       (plVar5 = *(longlong **)(param_1 + 0x28), (_IMPLAT_INTERNAL_BINDING *)*plVar5 == p_Var1)) {
      *plVar5 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar5;
      *(int *)(p_Var3 + 0x58) = *(int *)(p_Var3 + 0x58) + -1;
      if (*(uint *)(p_Var3 + 0x58) < *(uint *)(p_Var3 + 0x78)) {
        KeClearEvent(p_Var3 + 0x80);
      }
      if (2 < *(int *)(p_Var3 + 200)) {
        implatCalculateVmqCaps(p_Var3,'\x01');
      }
      implatTaskOffloadRecalculateAndIndicateChange(p_Var3);
      implatCalculateVirtMiniLinkState(p_Var3);
      implatRecalculatePMCapabilities(*(_IMPLAT_TEAM **)(p_Var3 + 0x48));
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(p_Var3 + 0x48) + 0x88),&local_res8);
      iVar7 = implatRecalculateAdapterPacketFilters(p_Var2);
      if ((((iVar7 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        puVar9 = &WPP_8057de2231843b45df4bd7d91c3cd38a_Traceguids;
        WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
                  &WPP_8057de2231843b45df4bd7d91c3cd38a_Traceguids,p_Var2,(char)iVar7);
      }
      iVar7 = implatUpdateVirtMiniDeviceCharacteristics(p_Var3);
      if (((iVar7 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29])))
         ) {
        puVar9 = &WPP_8057de2231843b45df4bd7d91c3cd38a_Traceguids;
        WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                   &WPP_8057de2231843b45df4bd7d91c3cd38a_Traceguids,p_Var2,(char)p_Var3,(char)iVar7)
        ;
      }
      p_Var8 = p_Var3;
      implatDereferenceVirtualMiniport(p_Var3,(ushort *)L"RemoveInternalBinding");
      if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
        McTemplateK0zz_EtwWriteTransfer
                  (p_Var8,&RemovedInternalBindingInfo,puVar9,*(wchar_t **)(p_Var3 + 0x30),
                   *(wchar_t **)(p_Var2 + 0x58));
      }
      NdisFreeMemory(param_1,0x70);
      implatDereferenceVirtualMiniport(p_Var3,(ushort *)L"RemoveInternalBinding temp");
      return;
    }
  }
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  pcVar6 = (code *)swi(3);
  (*pcVar6)();
  return;
}



===== implatUpdateVirtMiniDeviceCharacteristics @ 1c000b25c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* int __cdecl implatUpdateVirtMiniDeviceCharacteristics(struct _IMPLAT_VIRTMINI * __ptr64) */

int __cdecl implatUpdateVirtMiniDeviceCharacteristics(_IMPLAT_VIRTMINI *param_1)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  undefined1 auStack_128 [32];
  undefined4 local_108;
  undefined4 local_104;
  undefined8 local_100;
  wchar_t *local_f8;
  undefined4 local_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  _UNICODE_STRING local_c0 [2];
  undefined2 local_be;
  undefined1 *local_b8;
  undefined1 local_a8 [112];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_128;
  uVar1 = *(uint *)(param_1 + 0x58);
  lVar2 = 0;
  if (1 < uVar1) {
    return 0;
  }
  memset(&local_108,0,0x58);
  local_104 = 0;
  local_108 = 0x580280;
  local_100 = 0x340032;
  local_f8 = L"COMPOSITEBUS\\MS_IMPLAT_MP";
  local_f0 = *(undefined4 *)(param_1 + 0x28);
  uStack_ec = *(undefined4 *)(param_1 + 0x2c);
  uStack_e8 = *(undefined4 *)(param_1 + 0x30);
  uStack_e4 = *(undefined4 *)(param_1 + 0x34);
  if (uVar1 == 1) {
    local_b8 = local_a8;
    local_be = 0x66;
    lVar2 = RtlUnicodeStringPrintf(local_c0,(ushort *)L"NDISIMPLAT(%wZ)");
    if (-1 < lVar2) {
      lVar2 = NdisIMVBusDeviceAdd(DAT_1c001b1d8,&local_108);
    }
  }
  else if (uVar1 == 0) {
    lVar2 = NdisIMVBusDeviceRemove(DAT_1c001b1d8,&local_108);
  }
  iVar3 = NdisConvertNtStatusToNdisStatus(lVar2);
  return iVar3;
}



===== McTemplateK0zz_EtwWriteTransfer @ 1c000b384 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zz_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
               wchar_t *param_5)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  wchar_t *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  wchar_t *local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar1 = -1;
  local_20 = 10;
  if (param_4 == (wchar_t *)0x0) {
    uVar3 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_4[lVar2] != L'\0');
    uVar3 = (ulonglong)((int)lVar2 * 2 + 2);
  }
  local_30 = (undefined4)uVar3;
  local_2c = 0;
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"NULL";
  }
  if (param_5 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    local_20 = (int)lVar1 * 2 + 2;
  }
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_1c = 0;
  local_38 = param_4;
  local_28 = param_5;
  McGenEventWrite_EtwWriteTransfer(uVar3,param_2,0,3,local_48);
  return;
}



===== WPP_SF_DD @ 1c000b450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8057de2231843b45df4bd7d91c3cd38a_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== WPP_SF_DDL @ 1c000b4a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,&param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_dd @ 1c000b504 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_8057de2231843b45df4bd7d91c3cd38a_Traceguids,10,local_res20,4,&param_5
             ,4,0);
  return;
}



===== implatCalculateRscStats @ 1c000b55c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* int __cdecl implatCalculateRscStats(struct _IMPLAT_VIRTMINI * __ptr64,struct
   _NDIS_RSC_STATISTICS_INFO * __ptr64) */

int __cdecl implatCalculateRscStats(_IMPLAT_VIRTMINI *param_1,_NDIS_RSC_STATISTICS_INFO *param_2)

{
  longlong lVar1;
  _IMPLAT_VIRTMINI *p_Var2;
  undefined8 uVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined1 auStackY_a8 [32];
  undefined1 local_68;
  undefined7 local_67;
  undefined1 uStack_60;
  undefined7 uStack_5f;
  undefined1 uStack_58;
  undefined7 uStack_57;
  undefined1 uStack_50;
  undefined7 uStack_4f;
  undefined1 uStack_48;
  undefined4 local_47;
  undefined2 local_43;
  undefined1 local_41;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar1 = *(longlong *)(param_1 + 0x48);
  iVar5 = 0;
  bVar4 = false;
  uVar3 = *(undefined8 *)(lVar1 + 0x558);
  *(undefined8 *)param_2 = *(undefined8 *)(lVar1 + 0x550);
  *(undefined8 *)(param_2 + 8) = uVar3;
  uVar3 = *(undefined8 *)(lVar1 + 0x568);
  *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(lVar1 + 0x560);
  *(undefined8 *)(param_2 + 0x18) = uVar3;
  *(undefined8 *)(param_2 + 0x20) = *(undefined8 *)(lVar1 + 0x570);
  for (p_Var2 = *(_IMPLAT_VIRTMINI **)(param_1 + 0x60); p_Var2 != param_1 + 0x60;
      p_Var2 = *(_IMPLAT_VIRTMINI **)p_Var2) {
    if (*(int *)(p_Var2 + 0x40) != 0) {
      local_68 = 0;
      local_47 = 0;
      local_43 = 0;
      local_41 = 0;
      local_67 = 0;
      uStack_60 = 0;
      uStack_5f = 0;
      uStack_58 = 0;
      uStack_57 = 0;
      uStack_50 = 0;
      uStack_4f = 0;
      uStack_48 = 0;
      KeWaitForSingleObject(*(longlong *)(param_1 + 0x48) + 0x90,0,0,0);
      iVar5 = implatDoOidRequestOnAdapter
                        (*(_IMPLAT_ADAPTER **)(p_Var2 + -0x20),0,0x2021d,&local_68,0x28,
                         (_NDIS_OID_REQUEST *)0x0,(_IMPLAT_VIRTMINI *)0x0);
      KeReleaseMutex(*(longlong *)(param_1 + 0x48) + 0x90);
      if (iVar5 == 0) {
        bVar4 = true;
        *(longlong *)(param_2 + 0x20) =
             *(longlong *)(param_2 + 0x20) +
             CONCAT17(local_41,CONCAT25(local_43,CONCAT41(local_47,uStack_48)));
        *(longlong *)(param_2 + 0x10) =
             *(longlong *)(param_2 + 0x10) + CONCAT71(uStack_57,uStack_58);
        *(longlong *)(param_2 + 8) = *(longlong *)(param_2 + 8) + CONCAT71(uStack_5f,uStack_60);
        *(longlong *)(param_2 + 0x18) =
             *(longlong *)(param_2 + 0x18) + CONCAT71(uStack_4f,uStack_50);
      }
    }
  }
  iVar6 = 0;
  if (!bVar4) {
    iVar6 = iVar5;
  }
  return iVar6;
}



===== implatCancelOidRequest @ 1c000b6c0 =====

/* void __cdecl implatCancelOidRequest(void * __ptr64,void * __ptr64) */

void __cdecl implatCancelOidRequest(void *param_1,void *param_2)

{
  return;
}



===== implatCheckAdapterOffloadParametersWorkItem @ 1c000b6d0 =====

/* void __cdecl implatCheckAdapterOffloadParametersWorkItem(void * __ptr64,void * __ptr64) */

void __cdecl implatCheckAdapterOffloadParametersWorkItem(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = implatCheckAdapterOffloadParameters(param_1);
  if (iVar1 != 0) {
    NdisUnbindAdapter(*(undefined8 *)((longlong)param_1 + 0x20));
  }
  LOCK();
  *(int *)((longlong)param_1 + 0x264) = *(int *)((longlong)param_1 + 0x264) + -1;
  UNLOCK();
  NdisFreeIoWorkItem(param_2);
  return;
}



===== implatDirectOidRequest @ 1c000b730 =====

/* int __cdecl implatDirectOidRequest(void * __ptr64,struct _NDIS_OID_REQUEST * __ptr64) */

int __cdecl implatDirectOidRequest(void *param_1,_NDIS_OID_REQUEST *param_2)

{
  uint uVar1;
  char *pcVar2;
  longlong lVar3;
  int iVar4;
  undefined8 uVar5;
  undefined2 local_res8;
  undefined1 local_resa;
  
  iVar4 = 0;
  local_res8 = 0;
  local_resa = 0;
  if (*(int *)(param_2 + 4) == 1) {
    uVar1 = *(uint *)(param_2 + 0x30);
    pcVar2 = *(char **)(param_2 + 0x28);
    *(undefined4 *)(param_2 + 0x38) = 0;
    *(uint *)(param_2 + 0x34) = uVar1;
    if (*(int *)(param_2 + 0x20) == -0x3fcfdfd) {
      *(undefined4 *)(param_2 + 0x38) = 0x18;
      if (uVar1 < 0x18) {
        return -0x3ffeffec;
      }
      if (((*pcVar2 != -0x80) || (*(ushort *)(pcVar2 + 2) < 0x18)) || (pcVar2[1] == '\0')) {
        return -0x3ffeffeb;
      }
      iVar4 = IPsecLbfoTeamSaDelete((longlong)param_1,(longlong)param_2);
      goto LAB_1c000b87a;
    }
    if (*(int *)(param_2 + 0x20) == -0x3fcfdfb) {
      *(undefined4 *)(param_2 + 0x38) = 0xaa;
      if (uVar1 < 0xaa) {
        return -0x3ffeffec;
      }
      if (*pcVar2 != -0x80) {
        return -0x3ffeffeb;
      }
      if (*(ushort *)(pcVar2 + 2) < 0xaa) {
        return -0x3ffeffeb;
      }
      if (pcVar2[1] == '\0') {
        return -0x3ffeffeb;
      }
      NdisAcquireRWLockWrite
                (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_res8,0);
      lVar3 = *(longlong *)((longlong)param_1 + 0x48);
      if (*(longlong *)(lVar3 + 0x438) == 0) {
        if (*(int *)((longlong)param_1 + 0x7fc) == 0) {
          iVar4 = 0x40020005;
        }
        else {
          uVar5 = IPsecLbfoOffloadMapAlloc(lVar3,(undefined8 *)((longlong)param_1 + 0x770));
          iVar4 = (int)uVar5;
        }
      }
      else if (*(int *)(*(longlong *)(lVar3 + 0x438) + 4) != *(int *)((longlong)param_1 + 0x7fc)) {
        uVar5 = IPsecLbfoOffloadMapReAlloc(lVar3,(undefined8 *)((longlong)param_1 + 0x770));
        iVar4 = (int)uVar5;
      }
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_res8)
      ;
      if (iVar4 != 0) {
        return iVar4;
      }
      iVar4 = IPsecLbfoTeamSaAdd((longlong)param_1,(longlong)param_2);
      goto LAB_1c000b87a;
    }
  }
  iVar4 = -0x3ffeffe9;
LAB_1c000b87a:
  return iVar4;
}



===== implatDirectOidRequestComplete @ 1c000b8a0 =====

/* void __cdecl implatDirectOidRequestComplete(void * __ptr64,struct _NDIS_OID_REQUEST *
   __ptr64,int) */

void __cdecl implatDirectOidRequestComplete(void *param_1,_NDIS_OID_REQUEST *param_2,int param_3)

{
  undefined4 in_register_00000084;
  
  if (*(int *)(param_2 + 4) == 1) {
    if (*(int *)(param_2 + 0x20) == -0x3fcfdfd) {
      if (param_2[0xe0] == (_NDIS_OID_REQUEST)0x0) {
        IPsecLbfoAdapterSaUploadComplete((longlong)param_1,(longlong)param_2);
      }
      else {
        IPsecLbfoAdapterSaDeleteComplete((longlong)param_1,(longlong)param_2);
      }
    }
    else if (*(int *)(param_2 + 0x20) == -0x3fcfdfb) {
      IPsecLbfoAdapterSaAddComplete
                ((longlong)param_1,(longlong)param_2,CONCAT44(in_register_00000084,param_3));
    }
  }
  return;
}



===== implatDoOidRequestOnAdapter @ 1c000b8e4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* int __cdecl implatDoOidRequestOnAdapter(struct _IMPLAT_ADAPTER * __ptr64,enum
   _NDIS_REQUEST_TYPE,unsigned long,void * __ptr64,unsigned int,struct _NDIS_OID_REQUEST *
   __ptr64,struct _IMPLAT_VIRTMINI * __ptr64) */

int __cdecl
implatDoOidRequestOnAdapter
          (_IMPLAT_ADAPTER *param_1,_NDIS_REQUEST_TYPE param_2,ulong param_3,void *param_4,
          uint param_5,_NDIS_OID_REQUEST *param_6,_IMPLAT_VIRTMINI *param_7)

{
  undefined8 uVar1;
  bool bVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *_Dst;
  ulong uVar8;
  undefined4 in_register_00000014;
  undefined4 in_register_00000084;
  undefined8 uVar9;
  undefined2 local_res8;
  undefined1 local_resa;
  _NDIS_REQUEST_TYPE local_res10;
  ulong local_res18;
  undefined8 local_48;
  undefined8 local_40;
  
  bVar2 = false;
  local_48 = 0;
  local_res8 = 0;
  local_resa = 0;
  local_res10 = param_2;
  local_res18 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),CONCAT44(in_register_00000014,param_2),
               CONCAT44(in_register_00000084,param_3),param_1,(char)param_2,(char)param_3);
  }
  do {
    uVar9 = 0;
    NdisAcquireRWLockRead(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res8);
    if ((*(int *)(param_1 + 0xf0) == 2) || (*(int *)(param_1 + 0xf0) == 0)) {
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res8);
      iVar5 = -0x3ffefffe;
      goto LAB_1c000ba20;
    }
    uVar8 = (ulong)&local_res8;
    if (*(int *)(param_1 + 0xf4) == 1) {
      LOCK();
      *(int *)(param_1 + 0x260) = *(int *)(param_1 + 0x260) + 1;
      UNLOCK();
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88));
      uVar9 = 0;
      _Dst = implatAllocateNonPagedPoolWithTagPriority(0x128,uVar8,0);
      if (_Dst == (undefined4 *)0x0) {
        LOCK();
        *(int *)(param_1 + 0x260) = *(int *)(param_1 + 0x260) + -1;
        UNLOCK();
        iVar5 = -0x3fffff66;
        goto LAB_1c000ba20;
      }
      memset(_Dst,0,0x128);
      uVar9 = 0;
      KeInitializeEvent(_Dst + 0x3e,0);
      _Dst[2] = 0;
      _Dst[3] = 0;
      *(undefined8 *)(_Dst + 4) = 0;
      *(undefined8 *)(_Dst + 6) = 0;
      *(_IMPLAT_VIRTMINI **)(_Dst + 0x48) = param_7;
      *(_NDIS_OID_REQUEST **)(_Dst + 0x46) = param_6;
      *_Dst = 0xec0196;
      _Dst[1] = param_2;
      if (((param_2 == 0) || (param_2 == 1)) || (param_2 == 2)) {
LAB_1c000bb44:
        _Dst[0xc] = param_5;
        *(void **)(_Dst + 10) = param_4;
        _Dst[8] = param_3;
      }
      else if (param_2 == 0xc) {
        _Dst[0xd] = param_5;
        goto LAB_1c000bb44;
      }
      lVar3 = _DAT_fffff78000000320;
      if (param_6 != (_NDIS_OID_REQUEST *)0x0) {
        _Dst[3] = *(undefined4 *)(param_6 + 0xc);
        *(undefined8 *)(_Dst + 4) = *(undefined8 *)(param_6 + 0x10);
        *(undefined8 *)(_Dst + 6) = *(undefined8 *)(param_6 + 0x18);
        uVar1 = *(undefined8 *)(param_6 + 0x28);
        *(undefined8 *)(_Dst + 8) = *(undefined8 *)(param_6 + 0x20);
        *(undefined8 *)(_Dst + 10) = uVar1;
        uVar1 = *(undefined8 *)(param_6 + 0x38);
        *(undefined8 *)(_Dst + 0xc) = *(undefined8 *)(param_6 + 0x30);
        *(undefined8 *)(_Dst + 0xe) = uVar1;
        *(undefined8 *)(_Dst + 0x10) = *(undefined8 *)(param_6 + 0x40);
        lVar3 = _DAT_fffff78000000320;
      }
      goto LAB_1c000bb96;
    }
    NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88));
    if (bVar2) break;
    local_48 = 0xfffffffffa0a1f00;
    uVar9 = 0;
    bVar2 = true;
    iVar5 = KeWaitForSingleObject(param_1 + 0x118,0,0,0,&local_48);
  } while (iVar5 == 0);
  iVar5 = -0x3ffeffef;
  goto LAB_1c000ba20;
  while( true ) {
    local_40 = 0;
    uVar6 = KeQueryTimeIncrement();
    if (9999999 < (ulonglong)uVar6 * (lVar4 - lVar3)) break;
    local_40 = 0xffffffffff676980;
    uVar9 = 0;
    iVar7 = KeWaitForSingleObject(param_1 + 0x130,0,0,0,&local_40);
    if (iVar7 != 0) break;
LAB_1c000bb96:
    iVar5 = NdisOidRequest(*(undefined8 *)(param_1 + 0x20),_Dst);
    if (iVar5 == 0x103) {
      uVar9 = 0;
      KeWaitForSingleObject(_Dst + 0x3e,0,0,0,0);
      iVar5 = _Dst[0x44];
    }
    lVar4 = _DAT_fffff78000000320;
    if (iVar5 != -0x3ffefff3) break;
  }
  param_3 = local_res18;
  LOCK();
  *(int *)(param_1 + 0x260) = *(int *)(param_1 + 0x260) + -1;
  UNLOCK();
  if (param_6 != (_NDIS_OID_REQUEST *)0x0) {
    uVar1 = *(undefined8 *)(_Dst + 10);
    *(undefined8 *)(param_6 + 0x20) = *(undefined8 *)(_Dst + 8);
    *(undefined8 *)(param_6 + 0x28) = uVar1;
    uVar1 = *(undefined8 *)(_Dst + 0xe);
    *(undefined8 *)(param_6 + 0x30) = *(undefined8 *)(_Dst + 0xc);
    *(undefined8 *)(param_6 + 0x38) = uVar1;
    *(undefined8 *)(param_6 + 0x40) = *(undefined8 *)(_Dst + 0x10);
  }
  ExFreePoolWithTag(_Dst,0x6c506d49);
LAB_1c000ba20:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qdDd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),uVar9,param_1,(char)local_res10,
                (char)param_3,(char)iVar5);
  }
  return iVar5;
}



===== implatHandleQueryTeamState @ 1c000bc8c =====

/* int __cdecl implatHandleQueryTeamState(struct _IMPLAT_TEAM * __ptr64,struct
   _IMPLAT_TEAM_CURRENT_STATE * __ptr64,unsigned long,unsigned long * __ptr64,unsigned long *
   __ptr64) */

int __cdecl
implatHandleQueryTeamState
          (_IMPLAT_TEAM *param_1,_IMPLAT_TEAM_CURRENT_STATE *param_2,ulong param_3,ulong *param_4,
          ulong *param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  _IMPLAT_TEAM *p_Var7;
  uint uVar8;
  _IMPLAT_TEAM_CURRENT_STATE *p_Var9;
  _IMPLAT_TEAM_CURRENT_STATE *p_Var10;
  int iVar11;
  _IMPLAT_TEAM_CURRENT_STATE *p_Var12;
  uint uVar13;
  undefined2 local_res18;
  undefined1 local_res1a;
  
  local_res18 = 0;
  local_res1a = 0;
  iVar11 = 0;
  NdisAcquireRWLockRead(*(undefined8 *)(param_1 + 0x88),&local_res18,0);
  uVar6 = *(int *)(param_1 + 0x110) * 0x38 + 0x24 + *(int *)(param_1 + 0x114) * 0x28;
  if (param_3 < uVar6) {
    iVar11 = -0x3ffeffea;
    uVar13 = 0;
  }
  else {
    memset(param_2,0,(ulonglong)uVar6);
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    uVar3 = *(undefined4 *)(param_1 + 0x14);
    uVar4 = *(undefined4 *)(param_1 + 0x18);
    uVar5 = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(param_2 + 0x1c) = 0x24;
    *(undefined4 *)param_2 = uVar2;
    *(undefined4 *)(param_2 + 4) = uVar3;
    *(undefined4 *)(param_2 + 8) = uVar4;
    *(undefined4 *)(param_2 + 0xc) = uVar5;
    iVar1 = *(int *)(param_1 + 0x114);
    *(undefined4 *)(param_2 + 0x10) = 3;
    *(undefined4 *)(param_2 + 0x14) = 6;
    *(int *)(param_2 + 0x20) = iVar1 * 0x28 + 0x24;
    p_Var12 = param_2 + 0x24;
    p_Var10 = p_Var12;
    for (p_Var7 = *(_IMPLAT_TEAM **)(param_1 + 0x100); p_Var7 != param_1 + 0x100;
        p_Var7 = *(_IMPLAT_TEAM **)p_Var7) {
      p_Var9 = p_Var10;
      if (*(int *)(p_Var7 + 0x48) != 0) {
        uVar2 = *(undefined4 *)(p_Var7 + 0x740);
        uVar3 = *(undefined4 *)(p_Var7 + 0x744);
        uVar4 = *(undefined4 *)(p_Var7 + 0x748);
        uVar5 = *(undefined4 *)(p_Var7 + 0x74c);
        *(undefined4 *)(p_Var10 + 0x10) = 0x28;
        *(undefined4 *)p_Var10 = uVar2;
        *(undefined4 *)(p_Var10 + 4) = uVar3;
        *(undefined4 *)(p_Var10 + 8) = uVar4;
        *(undefined4 *)(p_Var10 + 0xc) = uVar5;
        if (2 < *(int *)(p_Var7 + 0xb8)) {
          *(undefined8 *)(p_Var10 + 0x18) = *(undefined8 *)(p_Var7 + 0xa0);
          *(undefined8 *)(p_Var10 + 0x20) = *(undefined8 *)(p_Var7 + 0xa8);
        }
        p_Var9 = p_Var10 + 0x28;
        p_Var12 = p_Var10;
      }
      p_Var10 = p_Var9;
    }
    *(undefined4 *)(p_Var12 + 0x10) = 0;
    uVar13 = uVar6;
    if (*(int *)(param_1 + 0x110) != 0) {
      p_Var12 = param_2 + *(uint *)(param_2 + 0x20);
      p_Var10 = param_2 + *(uint *)(param_2 + 0x20);
      for (p_Var7 = *(_IMPLAT_TEAM **)(param_1 + 0xf0); p_Var9 = p_Var12, p_Var7 != param_1 + 0xf0;
          p_Var7 = *(_IMPLAT_TEAM **)p_Var7) {
        uVar2 = *(undefined4 *)(p_Var7 + 0xa4);
        uVar3 = *(undefined4 *)(p_Var7 + 0xa8);
        uVar4 = *(undefined4 *)(p_Var7 + 0xac);
        uVar5 = *(undefined4 *)(p_Var7 + 0xb0);
        *(undefined4 *)(p_Var9 + 0x10) = 0x38;
        *(undefined4 *)(p_Var9 + 0x2c) = 0x1000;
        *(undefined4 *)p_Var9 = uVar2;
        *(undefined4 *)(p_Var9 + 4) = uVar3;
        *(undefined4 *)(p_Var9 + 8) = uVar4;
        *(undefined4 *)(p_Var9 + 0xc) = uVar5;
        *(undefined4 *)(p_Var9 + 0x30) = 6;
        *(undefined4 *)(p_Var9 + 0x34) = 1;
        if (2 < *(int *)(p_Var7 + 0xe0)) {
          *(undefined8 *)(p_Var9 + 0x18) = *(undefined8 *)(p_Var7 + 200);
          *(undefined8 *)(p_Var9 + 0x20) = *(undefined8 *)(p_Var7 + 0xd0);
        }
        p_Var12 = p_Var9 + 0x38;
        p_Var10 = p_Var9;
      }
      *(undefined4 *)(p_Var10 + 0x10) = 0;
    }
  }
  NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x88),&local_res18);
  uVar8 = 0;
  if (iVar11 == 0) {
    uVar8 = uVar13;
  }
  *param_4 = uVar8;
  uVar13 = 0;
  if (iVar11 == -0x3ffeffea) {
    uVar13 = uVar6;
  }
  *param_5 = uVar13;
  return iVar11;
}



===== implatNetPnPEvent @ 1c000be90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* int __cdecl implatNetPnPEvent(void * __ptr64,struct _NET_PNP_EVENT_NOTIFICATION * __ptr64) */

int __cdecl implatNetPnPEvent(void *param_1,_NET_PNP_EVENT_NOTIFICATION *param_2)

{
  int iVar1;
  longlong lVar2;
  void *pvVar3;
  undefined2 uVar4;
  ulong uVar5;
  undefined8 *puVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined1 auStack_1f8 [32];
  undefined2 local_1b8;
  undefined1 local_1b6;
  undefined8 local_1b0;
  undefined4 local_1a8 [2];
  undefined8 local_1a0;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined8 local_188;
  undefined8 uStack_180;
  _NET_PNP_EVENT_NOTIFICATION *local_178;
  undefined4 local_170;
  longlong local_138 [32];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1f8;
  local_1b8 = 0;
  local_1b6 = 0;
  memset(local_1a8,0,0x70);
  local_1b0 = 0;
  memset(local_138,0,0x100);
  pvVar3 = (void *)0x0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1,
              (char)*(undefined4 *)(param_2 + 8));
  }
  if ((param_1 != (void *)0x0) &&
     ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0)) {
    McTemplateK0qz_EtwWriteTransfer();
  }
  iVar1 = *(int *)(param_2 + 8);
  if (iVar1 < 7) {
    if (iVar1 != 6) {
      if (iVar1 == 0) {
        iVar1 = **(int **)(param_2 + 0x10);
        if (iVar1 < 2) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                     &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1);
          }
          NdisAcquireRWLockWrite
                    (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_1b8);
          *(int *)((longlong)param_1 + 0xf4) = iVar1;
          uVar9 = 0;
          KeSetEvent((longlong)param_1 + 0x118,0);
          pvVar3 = *(void **)(*(longlong *)((longlong)param_1 + 0x28) + 0x88);
          NdisReleaseRWLock(pvVar3,&local_1b8);
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
             (4 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                     &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1);
          }
          uVar8 = 0;
          NdisAcquireRWLockRead
                    (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_1b8,0);
          for (puVar6 = *(undefined8 **)((longlong)param_1 + 0x238); uVar7 = (uint)uVar8,
              puVar6 != (undefined8 *)((longlong)param_1 + 0x238); puVar6 = (undefined8 *)*puVar6) {
            lVar2 = puVar6[-1];
            if (((2 < *(int *)(lVar2 + 200)) && (*(int *)(puVar6 + 10) != 0)) &&
               (*(int *)(lVar2 + 0xcc) < 2)) {
              local_138[uVar8] = lVar2 + 0xd0;
              uVar8 = (ulonglong)(uVar7 + 1);
            }
          }
          uVar5 = (ulong)&local_1b8;
          NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88));
          if ((uVar7 != 0) &&
             (((local_1b0 = 0xffffffffffff15a0, uVar7 < 4 ||
               (pvVar3 = implatAllocateNonPagedPoolWithTagPriority(uVar8 * 0x30,uVar5,0x10),
               pvVar3 != (void *)0x0)) &&
              (KeWaitForMultipleObjects(uVar8,local_138,0,0), pvVar3 != (void *)0x0)))) {
            ExFreePoolWithTag(pvVar3,0x6c506d49);
          }
          NdisAcquireRWLockWrite
                    (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_1b8);
          *(int *)((longlong)param_1 + 0xf4) = iVar1;
          KeClearEvent((longlong)param_1 + 0x118);
          NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),
                            &local_1b8);
          uVar9 = 0;
          pvVar3 = param_1;
          implatWaitForOutstandingRequestsOnAdapter(param_1,'\x01','\0');
        }
        if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
          McTemplateK0zq_EtwWriteTransfer
                    (pvVar3,&NicPowerStateTransitionInfo,uVar9,
                     *(wchar_t **)((longlong)param_1 + 0x58),
                     (char)*(undefined4 *)((longlong)param_1 + 0xf4));
        }
        goto LAB_1c000c23e;
      }
      if (((iVar1 != 1) && (iVar1 != 2)) && (iVar1 != 3)) {
        if (iVar1 == 4) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 5)) goto LAB_1c000c23e;
          uVar4 = 0x10;
        }
        else {
          if (iVar1 == 5) goto LAB_1c000bf91;
LAB_1c000c3bd:
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 5)) goto LAB_1c000c23e;
          uVar4 = 0x13;
        }
        goto LAB_1c000c3e7;
      }
    }
LAB_1c000bf91:
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5))
    goto LAB_1c000c23e;
    uVar4 = 0x12;
  }
  else {
    if (iVar1 != 7) {
      if (iVar1 == 8) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                   &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1);
        }
        NdisAcquireRWLockWrite
                  (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_1b8);
        *(undefined4 *)((longlong)param_1 + 0xf0) = 6;
        NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88));
        implatWaitForOutstandingRequestsOnAdapter(param_1,'\0','\0');
        NdisAcquireRWLockWrite
                  (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_1b8,0);
        *(undefined4 *)((longlong)param_1 + 0xf0) = 3;
      }
      else {
        if (iVar1 != 9) {
          if ((iVar1 == 10) || (iVar1 == 0xb)) goto LAB_1c000bf91;
          if (iVar1 != 0xc) goto LAB_1c000c3bd;
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 5)) goto LAB_1c000c23e;
          uVar4 = 0x11;
          goto LAB_1c000c3e7;
        }
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                   &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1);
        }
        NdisAcquireRWLockWrite
                  (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_1b8,0);
        *(undefined4 *)((longlong)param_1 + 0xf0) = 4;
        NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_1b8
                         );
        NdisAcquireRWLockWrite
                  (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_1b8,0);
        *(undefined4 *)((longlong)param_1 + 0xf0) = 5;
      }
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_1b8);
      goto LAB_1c000c23e;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 5))
    goto LAB_1c000c23e;
    uVar4 = 0xf;
  }
LAB_1c000c3e7:
  WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,
           &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1);
LAB_1c000c23e:
  if (param_1 != (void *)0x0) {
    NdisAcquireRWLockRead
              (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_1b8,0);
    for (puVar6 = *(undefined8 **)((longlong)param_1 + 0x238);
        puVar6 != (undefined8 *)((longlong)param_1 + 0x238); puVar6 = (undefined8 *)*puVar6) {
      if ((2 < *(int *)(puVar6[-1] + 200)) && (*(int *)(puVar6 + 10) != 0)) {
        memset(local_1a8,0,0x70);
        local_1a8[0] = 0x700198;
        local_1a0 = *(undefined8 *)(puVar6[-1] + 0x20);
        local_198 = *(undefined4 *)(puVar6 + 10);
        local_190 = 0;
        local_194 = 0x40050002;
        local_170 = 0xb0;
        local_188 = 0;
        uStack_180 = 0;
        local_178 = param_2;
        NdisMIndicateStatusEx(*(undefined8 *)(puVar6[-1] + 0x20));
      }
    }
    NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_1b8);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
              &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1,
              (char)*(undefined4 *)(param_2 + 8));
  }
  return 0;
}



===== implatOidRequest @ 1c000c5d0 =====

/* int __cdecl implatOidRequest(void * __ptr64,struct _NDIS_OID_REQUEST * __ptr64) */

int __cdecl implatOidRequest(void *param_1,_NDIS_OID_REQUEST *param_2)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = NdisAllocateIoWorkItem(*(undefined8 *)((longlong)param_1 + 0x20));
  if (lVar2 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    *(_NDIS_OID_REQUEST **)((longlong)param_1 + 0x448) = param_2;
    NdisQueueIoWorkItem(lVar2,implatOidRequestWorkItem,param_1);
    iVar1 = 0x103;
  }
  return iVar1;
}



===== implatOidRequestComplete @ 1c000c640 =====

/* void __cdecl implatOidRequestComplete(void * __ptr64,struct _NDIS_OID_REQUEST * __ptr64,int) */

void __cdecl implatOidRequestComplete(void *param_1,_NDIS_OID_REQUEST *param_2,int param_3)

{
  *(int *)(param_2 + 0x110) = param_3;
  KeSetEvent(param_2 + 0xf8,0,0);
  return;
}



===== implatOidRequestInternal @ 1c000c670 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* int __cdecl implatOidRequestInternal(void * __ptr64,struct _NDIS_OID_REQUEST * __ptr64) */

int __cdecl implatOidRequestInternal(void *param_1,_NDIS_OID_REQUEST *param_2)

{
  _NDIS_OID_REQUEST *p_Var1;
  _NDIS_REQUEST_TYPE _Var2;
  uint *_Src;
  longlong lVar3;
  void *pvVar4;
  int iVar5;
  _IMPLAT_ADAPTER *p_Var6;
  undefined8 *puVar7;
  _IMPLAT_INTERNAL_BINDING *p_Var8;
  code *pcVar9;
  byte bVar10;
  uint uVar11;
  undefined *puVar12;
  _IMPLAT_TEAM *p_Var13;
  _IMPLAT_TEAM *p_Var14;
  undefined2 uVar15;
  _IMPLAT_TEAM_CURRENT_STATE *p_Var16;
  undefined8 *puVar17;
  undefined8 uVar18;
  undefined *puVar19;
  _IMPLAT_INTERNAL_BINDING *p_Var20;
  _IMPLAT_INTERNAL_BINDING *_Size;
  ulonglong uVar21;
  ushort uVar22;
  longlong *plVar23;
  _NDIS_OID_REQUEST *p_Var24;
  uint uVar25;
  undefined4 uVar26;
  uint uVar27;
  ulong uVar28;
  longlong *plVar29;
  longlong lVar30;
  undefined1 auStackY_1c8 [32];
  uchar uVar31;
  undefined2 local_188;
  undefined1 local_186;
  int local_184;
  int local_180 [2];
  ulonglong local_178;
  uint local_170;
  uint local_16c;
  longlong local_168;
  _NDIS_REQUEST_TYPE local_160;
  ulonglong local_158;
  ulonglong local_150;
  void *local_148;
  _NDIS_OID_REQUEST *local_140;
  _IMPLAT_TEAM_CURRENT_STATE *local_138;
  undefined4 local_128;
  undefined4 local_124;
  longlong local_120;
  longlong local_118;
  undefined2 local_110;
  byte bStack_10e;
  undefined4 uStack_10d;
  undefined1 uStack_109;
  undefined1 uStack_108;
  undefined7 uStack_107;
  longlong local_100;
  longlong local_f8;
  undefined8 local_f0;
  ulonglong local_e8;
  longlong local_e0;
  longlong local_d8;
  longlong local_d0;
  longlong local_c8;
  undefined8 local_c0;
  longlong local_b8;
  longlong local_b0;
  longlong local_a8;
  _IMPLAT_INTERNAL_BINDING *local_a0;
  longlong local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined8 local_80;
  undefined4 local_78;
  undefined8 local_74;
  undefined8 uStack_6c;
  undefined8 local_58;
  undefined2 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1c8;
  _Var2 = *(_NDIS_REQUEST_TYPE *)(param_2 + 4);
  uVar25 = *(uint *)(param_2 + 0x20);
  uVar18 = 200;
  local_50 = 0x74;
  local_188 = 0;
  local_186 = 0;
  local_178 = 0;
  local_184 = 0;
  local_158 = 0;
  local_16c = 0;
  local_168 = 0;
  local_180[0] = 0;
  local_58 = 0x666f736f7263694d;
  local_170 = uVar25;
  local_160 = _Var2;
  local_148 = param_1;
  local_140 = param_2;
  memset(&local_128,0,200);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,uVar18,param_1,(char)param_2,
                (char)_Var2,(char)uVar25);
  }
  implatIncreaseGlobalPendingOperationsCount();
  uVar26 = 1;
  if (((*(int *)(param_2 + 8) != 0) && (1 < uVar25 + 0x5fefeff)) && (uVar25 != 0x1010e)) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
                &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_2,(char)*(int *)(param_2 + 8)
               );
    }
    NdisAcquireRWLockRead
              (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_188);
    puVar19 = (undefined *)0x0;
    p_Var6 = implatFindAdapterByPortNumber
                       (param_1,*(ulong *)(param_2 + 8),(_IMPLAT_INTERNAL_BINDING **)0x0);
    if (p_Var6 == (_IMPLAT_ADAPTER *)0x0) {
      NdisReleaseRWLock();
      puVar12 = WPP_GLOBAL_Control;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
        puVar12 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
        puVar19 = &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids;
        WPP_SF_q(puVar12,0x27,&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_2);
      }
      if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 2) != 0) {
        McTemplateK0qzqbr2d_EtwWriteTransfer
                  (puVar12,&TeamNicOidFailureWarn,puVar19,uVar25,
                   *(wchar_t **)((longlong)param_1 + 0x30),*(undefined4 *)(param_2 + 0x30),
                   *(undefined8 *)(param_2 + 0x28),0x2d);
      }
      implatDecreaseGlobalPendingOperationsCount();
      return -0x3fdcffd3;
    }
    NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_188);
    _Size = (_IMPLAT_INTERNAL_BINDING *)(ulonglong)uVar25;
    iVar5 = implatDoOidRequestOnAdapter
                      (p_Var6,_Var2,uVar25,*(void **)(param_2 + 0x28),*(uint *)(param_2 + 0x30),
                       param_2,param_1);
    if ((iVar5 != 0) && ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 2) != 0)) {
      McTemplateK0qzzd_EtwWriteTransfer();
    }
    goto LAB_1c000deaa;
  }
  uVar18 = vmqInterceptOidRequest((longlong)param_1 + 0xf8,(longlong)param_2,&local_184);
  _Size = (_IMPLAT_INTERNAL_BINDING *)0x0;
  iVar5 = local_184;
  if ((char)uVar18 != '\0') goto LAB_1c000deaa;
  p_Var13 = (_IMPLAT_TEAM *)(ulonglong)_Var2;
  if (_Var2 == 0) {
LAB_1c000d80e:
    p_Var1 = param_2 + 0x34;
    p_Var16 = *(_IMPLAT_TEAM_CURRENT_STATE **)(param_2 + 0x28);
    p_Var24 = param_2 + 0x38;
    local_178 = CONCAT44(local_178._4_4_,*(undefined4 *)(param_2 + 0x30));
    *(ulong *)p_Var1 = 0;
    *(ulong *)p_Var24 = 0;
    local_138 = p_Var16;
    if (uVar25 < 0x1020a) {
      if (uVar25 != 0x10209) {
        if ((uVar25 == 0x10108) || (uVar25 == 0x10109)) {
          local_180[0] = 350000;
        }
        else {
          if ((uVar25 == 0x1010a) || (uVar25 == 0x1010b)) {
            local_180[0] = *(int *)((longlong)param_1 + 0x720) + 0x16;
            goto LAB_1c000de02;
          }
          if (uVar25 != 0x1010c) {
            if (uVar25 == 0x1010d) {
              p_Var16 = (_IMPLAT_TEAM_CURRENT_STATE *)&local_58;
              *(ulong *)p_Var24 = 10;
              goto LAB_1c000de17;
            }
            if (uVar25 == 0x10111) {
              local_180[0] = *(int *)((longlong)param_1 + 0x720) + 0xe;
              *(ulong *)p_Var24 = 4;
            }
            else {
              if (uVar25 != 0x10116) {
LAB_1c000d94a:
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                   (4 < (byte)WPP_GLOBAL_Control[0x29])) {
                  uVar15 = 0x28;
                  goto LAB_1c000d96f;
                }
                goto LAB_1c000d982;
              }
              local_180[0] = 0x10001;
              *(ulong *)p_Var24 = 4;
            }
            goto LAB_1c000de0e;
          }
          local_180[0] = 0xffffff;
        }
        *(ulong *)p_Var24 = 4;
        goto LAB_1c000de0e;
      }
      iVar5 = -0x3fffff45;
    }
    else {
      if (uVar25 == 0x1021c) {
        local_180[0] = *(int *)((longlong)param_1 + 0x440);
LAB_1c000de02:
        *(ulong *)p_Var24 = 4;
LAB_1c000de0e:
        p_Var16 = (_IMPLAT_TEAM_CURRENT_STATE *)local_180;
        goto LAB_1c000de17;
      }
      if (uVar25 == 0x20101) {
        if (DAT_1c001b278 != 0) {
          local_168 = 0;
          p_Var13 = (_IMPLAT_TEAM *)(*(longlong *)((longlong)param_1 + 0xf0) + 0xa0);
          uVar21 = (ulonglong)DAT_1c001b278;
          do {
            local_168 = local_168 + *(longlong *)p_Var13;
            p_Var13 = p_Var13 + 0xc0;
            uVar21 = uVar21 - 1;
          } while (uVar21 != 0);
        }
LAB_1c000ddbe:
        _Size = (_IMPLAT_INTERNAL_BINDING *)0x0;
        p_Var16 = (_IMPLAT_TEAM_CURRENT_STATE *)&local_168;
        *(ulong *)p_Var24 = 8;
LAB_1c000de17:
        uVar28 = (ulong)local_178;
      }
      else {
        if (uVar25 == 0x20102) {
          if (DAT_1c001b278 != 0) {
            local_168 = 0;
            p_Var13 = (_IMPLAT_TEAM *)(*(longlong *)((longlong)param_1 + 0xf0) + 0xa8);
            uVar21 = (ulonglong)DAT_1c001b278;
            do {
              local_168 = local_168 + *(longlong *)p_Var13;
              p_Var13 = p_Var13 + 0xc0;
              uVar21 = uVar21 - 1;
            } while (uVar21 != 0);
          }
          goto LAB_1c000ddbe;
        }
        if (uVar25 == 0x20106) {
          local_128 = 0x980180;
          local_124 = 0x3f87ff;
          if (DAT_1c001b278 != 0) {
            p_Var14 = (_IMPLAT_TEAM *)(*(longlong *)((longlong)param_1 + 0xf0) + 0x18);
            local_150 = (ulonglong)DAT_1c001b278;
            do {
              local_120 = local_120 + *(longlong *)(p_Var14 + -8);
              local_118 = local_118 + *(longlong *)p_Var14;
              local_e8 = local_e8 + *(longlong *)(p_Var14 + 0x30);
              local_e0 = local_e0 + *(longlong *)(p_Var14 + 0x38);
              local_d8 = local_d8 + *(longlong *)(p_Var14 + 0x40);
              local_d0 = local_d0 + *(longlong *)(p_Var14 + 0x48);
              local_c8 = local_c8 + *(longlong *)(p_Var14 + 0x50);
              local_c0 = local_c0 + *(longlong *)(p_Var14 + 0x58);
              local_b8 = local_b8 + *(longlong *)(p_Var14 + 0x60);
              local_b0 = local_b0 + *(longlong *)(p_Var14 + 0x68);
              local_a8 = local_a8 + *(longlong *)(p_Var14 + 0x70);
              local_a0 = local_a0 + *(longlong *)(p_Var14 + 0x78);
              local_98 = local_98 + *(longlong *)(p_Var14 + 0x80);
              p_Var13 = p_Var14 + 0xc0;
              lVar30 = CONCAT17(uStack_109,CONCAT43(uStack_10d,CONCAT12(bStack_10e,local_110))) +
                       *(longlong *)(p_Var14 + 8);
              local_110 = (undefined2)lVar30;
              bStack_10e = (byte)((ulonglong)lVar30 >> 0x10);
              uStack_10d = (undefined4)((ulonglong)lVar30 >> 0x18);
              uStack_109 = (undefined1)((ulonglong)lVar30 >> 0x38);
              lVar30 = CONCAT71(uStack_107,uStack_108) + *(longlong *)(p_Var14 + 0x10);
              uStack_108 = (undefined1)lVar30;
              uStack_107 = (undefined7)((ulonglong)lVar30 >> 8);
              local_100 = local_100 + *(longlong *)(p_Var14 + 0x18);
              local_f8 = local_f8 + *(longlong *)(p_Var14 + 0x20);
              local_f0 = local_f0 + *(longlong *)(p_Var14 + 0x28);
              local_150 = local_150 - 1;
              p_Var14 = p_Var13;
            } while (local_150 != 0);
            p_Var24 = local_140 + 0x38;
            local_150 = 0;
            param_2 = local_140;
            param_1 = local_148;
            _Size = local_a0;
            uVar25 = local_170;
          }
          p_Var16 = (_IMPLAT_TEAM_CURRENT_STATE *)&local_128;
          *(ulong *)p_Var24 = 0x98;
          goto LAB_1c000de17;
        }
        if (uVar25 == 0x2021d) {
          p_Var13 = param_1;
          iVar5 = implatCalculateRscStats(param_1,(_NDIS_RSC_STATISTICS_INFO *)&local_128);
          *(ulong *)p_Var24 = 0x28;
          p_Var16 = (_IMPLAT_TEAM_CURRENT_STATE *)&local_128;
          goto LAB_1c000de17;
        }
        if (uVar25 == 0xfa010101) {
          local_128 = 0xc80180;
          NdisAcquireRWLockRead(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88));
          _Size = (_IMPLAT_INTERNAL_BINDING *)((longlong)param_1 + 0x60);
          uVar21 = 0;
          local_f0._0_6_ = CONCAT24(6,(undefined4)local_f0);
          local_e8 = 0;
          local_120 = CONCAT44(local_120._4_4_,
                               *(undefined4 *)(*(longlong *)((longlong)param_1 + 0x48) + 200));
          local_118 = *(longlong *)(*(longlong *)((longlong)param_1 + 0x48) + 0xd0);
          local_110 = *(undefined2 *)((longlong)param_1 + 0x440);
          bStack_10e = (((*(byte *)((longlong)param_1 + 0x425) & 1) * '\x02' |
                        *(byte *)((longlong)param_1 + 0x426) & 1) * '\x02' |
                       *(byte *)((longlong)param_1 + 0x424) & 1) * '\x02' |
                       *(byte *)((longlong)param_1 + 0x444) & 1 | bStack_10e & 0xf0;
          uStack_10d = *(undefined4 *)((longlong)param_1 + 0x717);
          p_Var20 = *(_IMPLAT_INTERNAL_BINDING **)_Size;
          uStack_109 = (undefined1)*(undefined2 *)((longlong)param_1 + 0x71b);
          uStack_108 = (undefined1)((ushort)*(undefined2 *)((longlong)param_1 + 0x71b) >> 8);
          if (p_Var20 != _Size) {
            do {
              if ((*(int *)(p_Var20 + 0x40) != 0) &&
                 ((uVar21 == 0 || (*(ulonglong *)(*(longlong *)(p_Var20 + -0x20) + 0x70) < uVar21)))
                 ) {
                uVar21 = *(ulonglong *)(*(longlong *)(p_Var20 + -0x20) + 0x70);
              }
              p_Var20 = *(_IMPLAT_INTERNAL_BINDING **)p_Var20;
            } while (p_Var20 != _Size);
            local_e8 = uVar21;
          }
          if (*(ulong *)(param_2 + 8) == 0) {
LAB_1c000dbf0:
            iVar5 = local_184;
          }
          else {
            _Size = (_IMPLAT_INTERNAL_BINDING *)0x0;
            p_Var6 = implatFindAdapterByPortNumber
                               (param_1,*(ulong *)(param_2 + 8),(_IMPLAT_INTERNAL_BINDING **)0x0);
            if (p_Var6 != (_IMPLAT_ADAPTER *)0x0) {
              local_74 = *(undefined8 *)(p_Var6 + 0xb4);
              uStack_6c = *(undefined8 *)(p_Var6 + 0xbc);
              local_c0 = CONCAT44(*(undefined4 *)(p_Var6 + 0x68),(undefined4)local_c0);
              local_b8 = *(longlong *)(p_Var6 + 0x70);
              local_b0 = *(longlong *)(p_Var6 + 0x78);
              local_a8 = *(longlong *)(p_Var6 + 0x80);
              local_a0 = *(_IMPLAT_INTERNAL_BINDING **)(p_Var6 + 0x88);
              local_98 = CONCAT44(local_98._4_4_,*(undefined4 *)(p_Var6 + 0x90));
              local_90 = *(undefined8 *)(p_Var6 + 0x98);
              local_88 = *(undefined4 *)(p_Var6 + 0xa0);
              local_80 = *(undefined8 *)(p_Var6 + 0xa8);
              local_78 = *(undefined4 *)(p_Var6 + 0xb0);
              local_e0 = CONCAT26(local_e0._6_2_,*(undefined6 *)(p_Var6 + 0x60));
              local_c0 = CONCAT62(local_c0._2_6_,6);
              goto LAB_1c000dbf0;
            }
            iVar5 = -0x3fdcffd3;
          }
          p_Var13 = *(_IMPLAT_TEAM **)(*(longlong *)((longlong)param_1 + 0x48) + 0x88);
          NdisReleaseRWLock(p_Var13,&local_188);
          p_Var16 = (_IMPLAT_TEAM_CURRENT_STATE *)&local_128;
          *(ulong *)p_Var24 = 200;
          goto LAB_1c000de17;
        }
        if (uVar25 == 0xfa010102) {
          NdisAcquireRWLockRead
                    (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_188);
          _Size = (_IMPLAT_INTERNAL_BINDING *)0x0;
          p_Var6 = implatFindAdapterByPortNumber
                             (param_1,*(ulong *)(param_2 + 8),(_IMPLAT_INTERNAL_BINDING **)0x0);
          if (p_Var6 == (_IMPLAT_ADAPTER *)0x0) {
            iVar5 = -0x3fdcffd3;
          }
          else {
            local_158 = (ulonglong)*(uint *)(param_2 + 0x30);
            _Size = (_IMPLAT_INTERNAL_BINDING *)&local_158;
            iVar5 = NdisGetRssProcessorInformation
                              (*(undefined8 *)(p_Var6 + 0x20),*(undefined8 *)(param_2 + 0x28));
            *(ulong *)p_Var24 = (ulong)local_158;
            if (iVar5 == 0) {
              *(ulong *)p_Var1 = (ulong)local_158;
            }
          }
          p_Var13 = *(_IMPLAT_TEAM **)(*(longlong *)((longlong)param_1 + 0x48) + 0x88);
          NdisReleaseRWLock();
          p_Var16 = (_IMPLAT_TEAM_CURRENT_STATE *)0x0;
          goto LAB_1c000de17;
        }
        if (uVar25 != 0xfa010103) goto LAB_1c000d94a;
        implatWaitForMutex((_KMUTANT *)&DAT_1c001b1f0);
        uVar28 = (ulong)local_178;
        _Size = (_IMPLAT_INTERNAL_BINDING *)(local_178 & 0xffffffff);
        iVar5 = implatHandleQueryTeamState
                          (*(_IMPLAT_TEAM **)((longlong)param_1 + 0x48),p_Var16,(ulong)local_178,
                           (ulong *)p_Var1,(ulong *)p_Var24);
        p_Var13 = (_IMPLAT_TEAM *)&DAT_1c001b1f0;
        KeReleaseMutex();
        p_Var16 = (_IMPLAT_TEAM_CURRENT_STATE *)0x0;
      }
      if (iVar5 == 0) {
        if (p_Var16 == (_IMPLAT_TEAM_CURRENT_STATE *)0x0) goto LAB_1c000deaa;
        uVar11 = *(uint *)p_Var24;
        if (uVar11 <= uVar28) {
          *(uint *)(param_2 + 0x34) = uVar11;
          if ((uVar11 != 0) && (p_Var16 != local_138)) {
            _Size = (_IMPLAT_INTERNAL_BINDING *)(ulonglong)uVar11;
            memcpy(local_138,p_Var16,(size_t)_Size);
          }
          goto LAB_1c000deaa;
        }
        iVar5 = -0x3ffeffea;
        p_Var13 = (_IMPLAT_TEAM *)WPP_GLOBAL_Control;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 5)) goto LAB_1c000de91;
        p_Var13 = *(_IMPLAT_TEAM **)(WPP_GLOBAL_Control + 0x18);
        _Size = (_IMPLAT_INTERNAL_BINDING *)&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids;
        WPP_SF_q(p_Var13,0x29,&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_2);
      }
      if (iVar5 == -0x3ffeffe9) goto LAB_1c000deaa;
    }
LAB_1c000de91:
    if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 2) == 0) goto LAB_1c000deaa;
    puVar19 = &TeamNicOidQueryWarn;
  }
  else {
    uVar11 = _Var2 - 1;
    p_Var13 = (_IMPLAT_TEAM *)(ulonglong)uVar11;
    if (uVar11 != 0) {
      if (uVar11 == 1) goto LAB_1c000d80e;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        uVar15 = 0x33;
LAB_1c000d96f:
        _Size = (_IMPLAT_INTERNAL_BINDING *)&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids;
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar15,
                 &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_2);
      }
LAB_1c000d982:
      iVar5 = -0x3ffeffe9;
      goto LAB_1c000deaa;
    }
    uVar11 = *(uint *)(param_2 + 0x30);
    p_Var20 = (_IMPLAT_INTERNAL_BINDING *)(ulonglong)uVar11;
    _Src = *(uint **)(param_2 + 0x28);
    *(undefined4 *)(param_2 + 0x38) = 0;
    *(uint *)(param_2 + 0x34) = uVar11;
    if (uVar25 < 0x101020a) {
      if (uVar25 == 0x1010209) {
LAB_1c000d415:
        iVar5 = -0x3fffff45;
      }
      else {
        if (uVar25 == 0x1010e) {
          *(undefined4 *)(param_2 + 0x38) = 4;
          if (3 < uVar11) {
            uVar11 = *_Src;
            NdisAcquireRWLockWrite
                      (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_188);
            _Size = (_IMPLAT_INTERNAL_BINDING *)&local_178;
            p_Var6 = implatFindAdapterByPortNumber
                               (param_1,*(ulong *)(param_2 + 8),(_IMPLAT_INTERNAL_BINDING **)_Size);
            iVar5 = 0;
            if (p_Var6 == (_IMPLAT_ADAPTER *)0x0) {
              if (*(int *)(param_2 + 8) != 0) {
                p_Var13 = *(_IMPLAT_TEAM **)(*(longlong *)((longlong)param_1 + 0x48) + 0x88);
                NdisReleaseRWLock(p_Var13,&local_188);
LAB_1c000cd12:
                iVar5 = -0x3fdcffd3;
                goto LAB_1c000d7d0;
              }
              if ((uVar11 & ~*(uint *)((longlong)param_1 + 0x73c)) == 0) {
                for (puVar7 = *(undefined8 **)((longlong)param_1 + 0x60);
                    puVar7 != (undefined8 *)((longlong)param_1 + 0x60);
                    puVar7 = (undefined8 *)*puVar7) {
                  *(undefined4 *)(puVar7 + 9) = 0;
                }
                *(uint *)((longlong)param_1 + 0x76c) = uVar11;
                if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
                  McTemplateK0zq_EtwWriteTransfer
                            (puVar7,&TeamNicNewPktFiltersInfo,_Size,
                             *(wchar_t **)((longlong)param_1 + 0x30),(char)uVar11);
                }
                goto LAB_1c000d2ca;
              }
            }
            else if ((uVar11 & ~*(uint *)(p_Var6 + 0x80)) == 0) {
              *(undefined4 *)((longlong)param_1 + 0x76c) = 0;
              *(uint *)(local_178 + 0x68) = uVar11;
              if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
                McTemplateK0zzq_EtwWriteTransfer();
              }
LAB_1c000d2ca:
              plVar23 = *(longlong **)((longlong)param_1 + 0x60);
              if (plVar23 != (longlong *)((longlong)param_1 + 0x60)) {
                do {
                  if ((int)plVar23[8] != 0) {
                    NdisReleaseRWLock(*(undefined8 *)
                                       (*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_188);
                    iVar5 = implatRecalculateAdapterPacketFilters((_IMPLAT_ADAPTER *)plVar23[-4]);
                    _Size = (_IMPLAT_INTERNAL_BINDING *)0x0;
                    NdisAcquireRWLockWrite
                              (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),
                               &local_188);
                    if (iVar5 != 0) {
                      puVar19 = WPP_GLOBAL_Control;
                      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                        _Size = (_IMPLAT_INTERNAL_BINDING *)
                                &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids;
                        puVar19 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
                        WPP_SF_qq(puVar19,0x2d,&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,
                                  param_2,(char)plVar23[-4]);
                      }
                      if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 4) != 0) {
                        McTemplateK0zq_EtwWriteTransfer
                                  (puVar19,&MemberOidSetCurLookAheadErr,_Size,
                                   *(wchar_t **)(plVar23[-4] + 0x58),(char)iVar5);
                      }
                    }
                  }
                  plVar23 = (longlong *)*plVar23;
                } while (plVar23 != (longlong *)((longlong)param_1 + 0x60));
                uVar25 = local_170;
              }
              NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),
                                &local_188);
              p_Var13 = (_IMPLAT_TEAM *)WPP_GLOBAL_Control;
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                 (4 < (byte)WPP_GLOBAL_Control[0x29])) {
                p_Var13 = *(_IMPLAT_TEAM **)(WPP_GLOBAL_Control + 0x18);
                _Size = (_IMPLAT_INTERNAL_BINDING *)&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids
                ;
                WPP_SF_qdd(p_Var13,0x2e,&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_2,
                           (char)uVar11,(char)iVar5);
              }
              goto LAB_1c000d7bc;
            }
            p_Var13 = *(_IMPLAT_TEAM **)(*(longlong *)((longlong)param_1 + 0x48) + 0x88);
            NdisReleaseRWLock(p_Var13,&local_188);
LAB_1c000d249:
            iVar5 = -0x3ffeffeb;
            goto LAB_1c000d7d0;
          }
        }
        else if (uVar25 == 0x1010f) {
          *(undefined4 *)(param_2 + 0x38) = 4;
          if (3 < uVar11) {
            local_170 = *_Src;
            KeWaitForSingleObject(*(longlong *)((longlong)param_1 + 0x48) + 0x90,0,0,0);
            _Size = (_IMPLAT_INTERNAL_BINDING *)0x0;
            p_Var20 = *(_IMPLAT_INTERNAL_BINDING **)(*(longlong *)((longlong)param_1 + 0x48) + 0x88)
            ;
            NdisAcquireRWLockWrite(p_Var20,&local_188);
            plVar23 = *(longlong **)((longlong)param_1 + 0x60);
            iVar5 = local_184;
            if (plVar23 != (longlong *)((longlong)param_1 + 0x60)) {
              do {
                if ((int)plVar23[8] != 0) {
                  local_16c = local_170;
                  _Size = (_IMPLAT_INTERNAL_BINDING *)plVar23[-4];
                  p_Var8 = _Size + 0x238;
                  uVar11 = local_170;
                  for (p_Var20 = *(_IMPLAT_INTERNAL_BINDING **)p_Var8; p_Var20 != p_Var8;
                      p_Var20 = *(_IMPLAT_INTERNAL_BINDING **)p_Var20) {
                    pvVar4 = *(void **)(p_Var20 + -8);
                    if (pvVar4 != param_1) {
                      if (2 < *(int *)((longlong)pvVar4 + 200)) {
                        if (*(int *)(p_Var20 + 0x50) != 0) {
                          uVar27 = *(uint *)((longlong)pvVar4 + 0x768);
                          if (uVar11 < uVar27) {
                            uVar11 = uVar27;
                            local_16c = uVar27;
                          }
                        }
                      }
                    }
                    _Size = (_IMPLAT_INTERNAL_BINDING *)plVar23[-4];
                    p_Var8 = _Size + 0x238;
                  }
                  if (uVar11 != *(uint *)(_Size + 0x268)) {
                    NdisReleaseRWLock(*(undefined8 *)
                                       (*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_188);
                    iVar5 = implatDoOidRequestOnAdapter
                                      ((_IMPLAT_ADAPTER *)plVar23[-4],1,0x1010f,&local_16c,4,
                                       (_NDIS_OID_REQUEST *)0x0,(_IMPLAT_VIRTMINI *)0x0);
                    _Size = (_IMPLAT_INTERNAL_BINDING *)0x0;
                    NdisAcquireRWLockWrite
                              (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),
                               &local_188);
                    if (iVar5 == 0) {
                      p_Var20 = (_IMPLAT_INTERNAL_BINDING *)plVar23[-4];
                      *(uint *)(p_Var20 + 0x268) = local_16c;
                    }
                    else {
                      puVar19 = WPP_GLOBAL_Control;
                      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                        _Size = (_IMPLAT_INTERNAL_BINDING *)
                                &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids;
                        puVar19 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
                        WPP_SF_qqd(puVar19,0x2b,&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,
                                   param_2,(char)plVar23[-4],(char)local_16c);
                      }
                      if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 4) != 0) {
                        McTemplateK0zq_EtwWriteTransfer
                                  (puVar19,&MemberOidSetCurLookAheadErr,_Size,
                                   *(wchar_t **)(plVar23[-4] + 0x58),(char)iVar5);
                      }
                      p_Var20 = (_IMPLAT_INTERNAL_BINDING *)
                                (ulonglong)*(uint *)(plVar23[-4] + 0x268);
                      if (*(uint *)(plVar23[-4] + 0x268) < local_16c) break;
                      iVar5 = 0;
                    }
                  }
                }
                plVar23 = (longlong *)*plVar23;
              } while (plVar23 != (longlong *)((longlong)param_1 + 0x60));
            }
            if (iVar5 == 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                 (4 < (byte)WPP_GLOBAL_Control[0x29])) {
                _Size = (_IMPLAT_INTERNAL_BINDING *)&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids
                ;
                WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,
                          &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_2,(char)local_170);
              }
              *(uint *)((longlong)param_1 + 0x768) = local_170;
            }
            else if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 4) != 0) {
              McTemplateK0zq_EtwWriteTransfer
                        (p_Var20,&TeamNicOidSetCurLookAheadErr,_Size,
                         *(wchar_t **)((longlong)param_1 + 0x30),(char)iVar5);
            }
            NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),
                              &local_188);
            p_Var13 = (_IMPLAT_TEAM *)(*(longlong *)((longlong)param_1 + 0x48) + 0x90);
            KeReleaseMutex(p_Var13,0);
            goto LAB_1c000d7bc;
          }
        }
        else {
          if ((uVar25 == 0x10208) || (uVar25 == 0x10209)) goto LAB_1c000d415;
          if (uVar25 == 0x1021e) {
            *(undefined4 *)(param_2 + 0x38) = 8;
            if (7 < uVar11) {
              if ((((char)*_Src == -0x80) && (7 < *(ushort *)((longlong)_Src + 2))) &&
                 (*(char *)((longlong)_Src + 1) != '\0')) {
                NdisAcquireRWLockWrite
                          (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),
                           &local_188);
                uVar11 = _Src[1];
                *(uint *)((longlong)param_1 + 0x908) = uVar11;
                if (((uVar11 & 1) != 0) || ((*(uint *)((longlong)param_1 + 0x904) & 1) == 0)) {
                  uVar26 = 0;
                }
                *(undefined4 *)((longlong)param_1 + 0x5c8) = uVar26;
                iVar5 = implatRecalculateTeamOffloadCapabilities
                                  (*(_IMPLAT_TEAM **)((longlong)param_1 + 0x48),
                                   (_LOCK_STATE_EX *)&local_188);
                goto LAB_1c000d790;
              }
              goto LAB_1c000d249;
            }
          }
          else if (uVar25 == 0x1010103) {
            uVar27 = uVar11 / 6;
            p_Var13 = (_IMPLAT_TEAM *)(ulonglong)(uVar27 * 6);
            if ((uVar11 == uVar27 * 6) && (uVar27 <= *(uint *)((longlong)param_1 + 0x740))) {
              if (*(int *)(param_2 + 8) != 0) goto LAB_1c000cd12;
              NdisAcquireRWLockWrite
                        (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_188)
              ;
              *(uint *)((longlong)param_1 + 0x2084) = uVar27;
              memcpy((void *)((longlong)param_1 + 0x914),_Src,(size_t)p_Var20);
              plVar23 = (longlong *)((longlong)param_1 + 0x60);
              iVar5 = 0;
              plVar29 = (longlong *)*plVar23;
              _Size = p_Var20;
              if (plVar29 != plVar23) {
                do {
                  if ((int)plVar29[8] != 0) {
                    NdisReleaseRWLock(*(undefined8 *)
                                       (*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_188);
                    iVar5 = implatRecalculateAdapterPacketFilters((_IMPLAT_ADAPTER *)plVar29[-4]);
                    p_Var20 = (_IMPLAT_INTERNAL_BINDING *)0x0;
                    NdisAcquireRWLockWrite
                              (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),
                               &local_188);
                    if (iVar5 != 0) {
                      puVar19 = WPP_GLOBAL_Control;
                      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                         (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                        p_Var20 = (_IMPLAT_INTERNAL_BINDING *)
                                  &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids;
                        puVar19 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
                        WPP_SF_qq(puVar19,0x2f,&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,
                                  param_2,(char)plVar29[-4]);
                      }
                      if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 4) != 0) {
                        McTemplateK0zzd_EtwWriteTransfer
                                  (puVar19,&MemberOidMultiCastListOnTeamNicErr,p_Var20,
                                   *(wchar_t **)(plVar29[-4] + 0x58),
                                   *(wchar_t **)((longlong)param_1 + 0x30),(char)iVar5);
                      }
                    }
                  }
                  plVar29 = (longlong *)*plVar29;
                } while (plVar29 != plVar23);
                _Size = p_Var20;
                uVar25 = local_170;
              }
              NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),
                                &local_188);
              p_Var13 = (_IMPLAT_TEAM *)WPP_GLOBAL_Control;
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                 (4 < (byte)WPP_GLOBAL_Control[0x29])) {
                p_Var13 = *(_IMPLAT_TEAM **)(WPP_GLOBAL_Control + 0x18);
                _Size = (_IMPLAT_INTERNAL_BINDING *)&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids
                ;
                WPP_SF_qd(p_Var13,0x30,&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_2,
                          (char)iVar5);
              }
              goto LAB_1c000d7bc;
            }
          }
          else {
            if (uVar25 != 0x101010a) {
              if (uVar25 != 0x1010208) goto LAB_1c000c9e6;
              goto LAB_1c000d415;
            }
            *(undefined4 *)(param_2 + 0x38) = 0x1c;
            if (0x1b < uVar11) {
              if ((((char)*_Src == -0x58) && (0x1b < *(ushort *)((longlong)_Src + 2))) &&
                 (*(char *)((longlong)_Src + 1) != '\0')) {
                KeWaitForSingleObject(*(longlong *)((longlong)param_1 + 0x48) + 0x90,0,0,0);
                NdisAcquireRWLockWrite
                          (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),
                           &local_188);
                if (_Src[1] != 0) {
                  lVar30 = *(longlong *)((longlong)param_1 + 0x48);
                  *(undefined8 *)((longlong)param_1 + 0x8dc) = *(undefined8 *)(_Src + 1);
                  *(uint *)((longlong)param_1 + 0x8e4) = _Src[3];
                  *(undefined8 *)(lVar30 + 0x15c) = *(undefined8 *)((longlong)param_1 + 0x8dc);
                  *(undefined4 *)(lVar30 + 0x164) = *(undefined4 *)((longlong)param_1 + 0x8e4);
                }
                if (_Src[4] != 0) {
                  lVar30 = *(longlong *)((longlong)param_1 + 0x48);
                  *(undefined8 *)((longlong)param_1 + 0x8e8) = *(undefined8 *)(_Src + 4);
                  *(uint *)((longlong)param_1 + 0x8f0) = _Src[6];
                  *(undefined8 *)(lVar30 + 0x168) = *(undefined8 *)((longlong)param_1 + 0x8e8);
                  *(undefined4 *)(lVar30 + 0x170) = *(undefined4 *)((longlong)param_1 + 0x8f0);
                }
                *(byte *)((longlong)param_1 + 0x8f4) = *(byte *)((longlong)param_1 + 0x8f4) & 0xfd;
                plVar23 = (longlong *)((longlong)param_1 + 0x60);
                plVar29 = (longlong *)*plVar23;
                if (plVar29 != plVar23) {
                  do {
                    if ((int)plVar29[8] != 0) {
                      lVar30 = *(longlong *)((longlong)param_1 + 0x48);
                      iVar5 = memcmp((void *)(lVar30 + 0x158),(void *)(plVar29[-4] + 0x340),0x1c);
                      if (iVar5 != 0) {
                        NdisReleaseRWLock(*(undefined8 *)(lVar30 + 0x88),&local_188);
                        iVar5 = implatDoOidRequestOnAdapter
                                          ((_IMPLAT_ADAPTER *)plVar29[-4],1,0x101010a,
                                           (void *)(*(longlong *)((longlong)param_1 + 0x48) + 0x158)
                                           ,0x1c,(_NDIS_OID_REQUEST *)0x0,(_IMPLAT_VIRTMINI *)0x0);
                        NdisAcquireRWLockWrite
                                  (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),
                                   &local_188);
                        if (iVar5 == 0) {
                          lVar30 = *(longlong *)((longlong)param_1 + 0x48);
                          lVar3 = plVar29[-4];
                          uVar18 = *(undefined8 *)(lVar30 + 0x160);
                          *(undefined8 *)(lVar3 + 0x340) = *(undefined8 *)(lVar30 + 0x158);
                          *(undefined8 *)(lVar3 + 0x348) = uVar18;
                          *(undefined8 *)(lVar3 + 0x350) = *(undefined8 *)(lVar30 + 0x168);
                          *(undefined4 *)(lVar3 + 0x358) = *(undefined4 *)(lVar30 + 0x170);
                        }
                        else if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
                                (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x31,
                                    &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_2,
                                    (char)plVar29[-4]);
                        }
                      }
                    }
                    plVar29 = (longlong *)*plVar29;
                  } while (plVar29 != plVar23);
                  uVar25 = local_170;
                }
                NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),
                                  &local_188);
                KeReleaseMutex(*(longlong *)((longlong)param_1 + 0x48) + 0x90,0);
                _Size = (_IMPLAT_INTERNAL_BINDING *)0x0;
                NdisAcquireRWLockWrite
                          (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),
                           &local_188);
                lVar30 = *(longlong *)((longlong)param_1 + 0x48);
                puVar7 = (undefined8 *)(lVar30 + 0x100);
                for (puVar17 = (undefined8 *)*puVar7; puVar17 != puVar7;
                    puVar17 = (undefined8 *)*puVar17) {
                  implatTaskOffloadRecalculateAndIndicateChange((_IMPLAT_VIRTMINI *)(puVar17 + -2));
                  lVar30 = *(longlong *)((longlong)param_1 + 0x48);
                  puVar7 = (undefined8 *)(lVar30 + 0x100);
                }
                NdisReleaseRWLock(*(undefined8 *)(lVar30 + 0x88),&local_188);
                iVar5 = 0;
                goto LAB_1c000deaa;
              }
              goto LAB_1c000d249;
            }
          }
        }
LAB_1c000d60b:
        iVar5 = -0x3ffeffec;
      }
    }
    else {
      if (uVar25 == 0xfc01020c) {
        p_Var13 = (_IMPLAT_TEAM *)0x16;
        *(undefined4 *)(param_2 + 0x38) = 0x16;
        if (uVar11 < 0x16) goto LAB_1c000d60b;
        if ((((char)*_Src == -0x80) && (0x15 < *(ushort *)((longlong)_Src + 2))) &&
           (1 < *(byte *)((longlong)_Src + 1))) {
          if (((1 < *(byte *)((longlong)_Src + 9)) || (1 < *(byte *)((longlong)_Src + 10))) ||
             ((*(char *)((longlong)_Src + 0xd) != '\0' ||
              ((*(char *)((longlong)_Src + 0xe) != '\0' || (1 < *(byte *)((longlong)_Src + 0x15)))))
             )) goto LAB_1c000d249;
          NdisAcquireRWLockWrite
                    (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_188);
          if ((byte)_Src[1] != 0) {
            *(uint *)((longlong)param_1 + 0x468) = (byte)_Src[1] - 1;
          }
          if (*(byte *)((longlong)_Src + 5) != 0) {
            *(uint *)((longlong)param_1 + 0x488) = *(byte *)((longlong)_Src + 5) - 1;
          }
          if (*(byte *)((longlong)_Src + 6) != 0) {
            *(uint *)((longlong)param_1 + 0x4c8) = *(byte *)((longlong)_Src + 6) - 1;
          }
          if (*(byte *)((longlong)_Src + 7) != 0) {
            *(uint *)((longlong)param_1 + 0x4a8) = *(byte *)((longlong)_Src + 7) - 1;
          }
          if ((byte)_Src[2] != 0) {
            *(uint *)((longlong)param_1 + 0x4e8) = (byte)_Src[2] - 1;
          }
          if (*(char *)((longlong)_Src + 0xb) != '\0') {
            *(uint *)((longlong)param_1 + 0x508) = (uint)(*(char *)((longlong)_Src + 0xb) == '\x02')
            ;
          }
          if ((char)_Src[3] != '\0') {
            *(uint *)((longlong)param_1 + 0x528) = (uint)((char)_Src[3] == '\x02');
          }
          if ((byte)_Src[5] != 0) {
            *(uint *)((longlong)param_1 + 0x548) = (byte)_Src[5] - 1;
          }
          if ((2 < *(byte *)((longlong)_Src + 1)) && (0x19 < *(ushort *)((longlong)_Src + 2))) {
            if (*(byte *)((longlong)_Src + 0x16) != 0) {
              *(uint *)((longlong)param_1 + 0x568) = *(byte *)((longlong)_Src + 0x16) - 1;
            }
            if (*(byte *)((longlong)_Src + 0x17) != 0) {
              *(uint *)((longlong)param_1 + 0x588) = *(byte *)((longlong)_Src + 0x17) - 1;
            }
            if ((char)_Src[6] != '\0') {
              bVar10 = (char)_Src[6] == '\x01' | *(byte *)((longlong)param_1 + 0x8f4) & 0xfe;
              *(byte *)((longlong)param_1 + 0x8f4) = bVar10;
              *(uint *)((longlong)param_1 + 0x5a8) = bVar10 & 1;
            }
          }
          *(byte *)((longlong)param_1 + 0x8f4) = *(byte *)((longlong)param_1 + 0x8f4) & 0xfd;
          iVar5 = implatRecalculateTeamOffloadCapabilities
                            (*(_IMPLAT_TEAM **)((longlong)param_1 + 0x48),
                             (_LOCK_STATE_EX *)&local_188);
          if ((*(byte *)((longlong)param_1 + 0x8f4) & 2) == 0) {
            implatTaskOffloadRecalculateAndIndicateChange(param_1);
          }
LAB_1c000d790:
          NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),
                            &local_188);
          p_Var13 = *(_IMPLAT_TEAM **)((longlong)param_1 + 0x48);
          implatWaitForPendingAdapterUnbinds(p_Var13);
        }
        else {
          iVar5 = -0x3ffeffeb;
        }
      }
      else if (uVar25 == 0xfd010101) {
        *(undefined4 *)(param_2 + 0x38) = 4;
        if (uVar11 < 4) goto LAB_1c000d60b;
        NdisAcquireRWLockWrite
                  (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_188);
        *(uint *)((longlong)param_1 + 0xcc) = *_Src;
        NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_188
                         );
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
           (4 < (byte)WPP_GLOBAL_Control[0x29])) {
          _Size = (_IMPLAT_INTERNAL_BINDING *)&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids;
          WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
                    &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_2,
                    (char)*(undefined4 *)((longlong)param_1 + 0xcc));
        }
        p_Var13 = (_IMPLAT_TEAM *)((longlong)param_1 + 0xd0);
        if (*(int *)((longlong)param_1 + 0xcc) < 2) {
          KeClearEvent();
        }
        else {
          _Size = (_IMPLAT_INTERNAL_BINDING *)0x0;
          KeSetEvent(p_Var13,0);
          p_Var13 = param_1;
          implatWaitForOutstandingIndicationsOnVirtMini(param_1);
        }
        if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
          McTemplateK0zq_EtwWriteTransfer
                    (p_Var13,&NicPowerStateTransitionInfo,_Size,
                     *(wchar_t **)((longlong)param_1 + 0x30),
                     (char)*(undefined4 *)((longlong)param_1 + 0xcc));
        }
        iVar5 = local_184;
      }
      else {
        if ((6 < uVar25 + 0x2fefef7) ||
           (p_Var13 = (_IMPLAT_TEAM *)0x57, (0x57U >> (uVar25 + 0x2fefef7 & 0x1f) & 1) == 0)) {
LAB_1c000c9e6:
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0 &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])))) {
            uVar15 = 0x32;
            goto LAB_1c000d96f;
          }
          goto LAB_1c000d982;
        }
        if ((*(char *)((longlong)param_1 + 0x444) == '\0') ||
           (*(int *)((longlong)param_1 + 0x440) != 0)) {
LAB_1c000d502:
          iVar5 = -0x3fffff45;
          goto LAB_1c000d7bc;
        }
        iVar5 = *(int *)(param_2 + 0x20);
        if (iVar5 == -0x2fefef7) {
          uVar22 = 0x10;
          pcVar9 = implatSetPMParams;
LAB_1c000d4e3:
          _Size = (_IMPLAT_INTERNAL_BINDING *)0x1;
          uVar31 = '\x01';
        }
        else {
          if (iVar5 == -0x2fefef6) {
            uVar22 = 0xc4;
            pcVar9 = implatAddWolPattern;
            goto LAB_1c000d4e3;
          }
          if (iVar5 == -0x2fefef5) {
            pcVar9 = implatRemoveWolPattern;
          }
          else {
            if (iVar5 == -0x2fefef3) {
              uVar22 = 0xc4;
              pcVar9 = implatAddPMOffload;
              goto LAB_1c000d4e3;
            }
            if (iVar5 != -0x2fefef1) goto LAB_1c000d502;
            pcVar9 = implatRemovePMOffload;
          }
          uVar22 = 4;
          uVar31 = '\0';
        }
        p_Var13 = param_1;
        iVar5 = implatVerifyPMOidParamsAndCallHandler
                          (param_1,param_2,(uchar)_Size,uVar22,uVar31,pcVar9);
      }
LAB_1c000d7bc:
      if ((iVar5 == 0) || (iVar5 == -0x3ffeffe9)) goto LAB_1c000deaa;
    }
LAB_1c000d7d0:
    if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 4) == 0) goto LAB_1c000deaa;
    puVar19 = &TeamNicSetOidFailureErr;
  }
  McTemplateK0qzqbr2d_EtwWriteTransfer
            (p_Var13,puVar19,_Size,uVar25,*(wchar_t **)((longlong)param_1 + 0x30),
             *(undefined4 *)(param_2 + 0x30),*(undefined8 *)(param_2 + 0x28),(char)iVar5);
LAB_1c000deaa:
  implatDecreaseGlobalPendingOperationsCount();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qqdD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x34,_Size,param_1,(char)param_2,
                (char)local_160,(char)uVar25);
  }
  return iVar5;
}



===== implatOidRequestWorkItem @ 1c000df30 =====

/* void __cdecl implatOidRequestWorkItem(void * __ptr64,void * __ptr64) */

void __cdecl implatOidRequestWorkItem(void *param_1,void *param_2)

{
  _NDIS_OID_REQUEST *p_Var1;
  int iVar2;
  
  p_Var1 = *(_NDIS_OID_REQUEST **)((longlong)param_1 + 0x448);
  iVar2 = implatOidRequestInternal(param_1,p_Var1);
  if (iVar2 != 0x103) {
    *(undefined8 *)((longlong)param_1 + 0x448) = 0;
    NdisMOidRequestComplete(*(undefined8 *)((longlong)param_1 + 0x20),p_Var1,iVar2);
  }
  NdisFreeIoWorkItem(param_2);
  return;
}



===== implatRecalculateAdapterPacketFilters @ 1c000dfa0 =====

/* int __cdecl implatRecalculateAdapterPacketFilters(struct _IMPLAT_ADAPTER * __ptr64) */

int __cdecl implatRecalculateAdapterPacketFilters(_IMPLAT_ADAPTER *param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *_Buf1;
  longlong lVar4;
  ulong in_EDX;
  uint uVar5;
  _IMPLAT_ADAPTER *p_Var6;
  undefined *_Size;
  uint uVar7;
  undefined2 local_res18;
  undefined1 local_res1a;
  uint local_res20 [2];
  
  local_res20[0] = 0;
  lVar4 = 6000;
  bVar1 = false;
  _Size = (undefined *)0x10;
  local_res18 = 0;
  uVar7 = 0;
  local_res1a = 0;
  _Buf1 = implatAllocateNonPagedPoolWithTagPriority(6000,in_EDX,0x10);
  if (_Buf1 == (undefined4 *)0x0) {
    iVar3 = -0x3fffff66;
  }
  else {
    KeWaitForSingleObject(*(longlong *)(param_1 + 0x28) + 0x90,0,0,0,0);
    _Size = (undefined *)0x0;
    NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res18);
    if ((*(uint *)(param_1 + 0xf0) & 0xfffffffd) != 0) {
      uVar7 = 1;
      *_Buf1 = 0xc28001;
      *(undefined2 *)(_Buf1 + 1) = 0x200;
      p_Var6 = *(_IMPLAT_ADAPTER **)(param_1 + 0x238);
      local_res20[0] = local_res20[0] | 0x10002;
      bVar2 = false;
      if (p_Var6 != param_1 + 0x238) {
        do {
          lVar4 = *(longlong *)(p_Var6 + -8);
          uVar5 = *(uint *)(lVar4 + 0x76c) | *(uint *)(p_Var6 + 0x58);
          local_res20[0] = local_res20[0] | uVar5;
          if (((uVar5 & 1) != 0) &&
             ((*(int *)(lVar4 + 0x713) != *(int *)(param_1 + 0x62) ||
              (*(short *)(lVar4 + 0x711) != *(short *)(param_1 + 0x60))))) {
            local_res20[0] = local_res20[0] | 0x20;
          }
          iVar3 = *(int *)(lVar4 + 0x2084);
          if (((iVar3 != 0) && ((uVar5 & 2) != 0)) && (!bVar1)) {
            if (iVar3 + uVar7 < 0x3e9) {
              _Size = (undefined *)(ulonglong)(uint)(iVar3 * 6);
              memcpy((void *)((longlong)_Buf1 + (ulonglong)uVar7 * 6),(void *)(lVar4 + 0x914),
                     (size_t)_Size);
              uVar7 = uVar7 + *(int *)(lVar4 + 0x2084);
            }
            else {
              bVar1 = true;
            }
          }
          p_Var6 = *(_IMPLAT_ADAPTER **)p_Var6;
        } while (p_Var6 != param_1 + 0x238);
        bVar2 = bVar1;
      }
      uVar7 = -(uint)((local_res20[0] & 2) != 0) & uVar7;
      if ((bool)(bVar2 & (local_res20[0] & 2) != 0)) {
        uVar7 = 0;
        local_res20[0] = local_res20[0] | 4;
      }
    }
    uVar5 = local_res20[0];
    if (uVar7 == *(uint *)(param_1 + 0x1acc)) {
      if (uVar7 != 0) {
        _Size = (undefined *)(ulonglong)(uVar7 * 6);
        iVar3 = memcmp(_Buf1,param_1 + 0x35c,(size_t)_Size);
        if (iVar3 != 0) goto LAB_1c000e1a0;
      }
    }
    else {
LAB_1c000e1a0:
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res18);
      iVar3 = implatDoOidRequestOnAdapter
                        (param_1,1,0x1010103,_Buf1,uVar7 * 6,(_NDIS_OID_REQUEST *)0x0,
                         (_IMPLAT_VIRTMINI *)0x0);
      _Size = (undefined *)0x0;
      NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res18);
      if (iVar3 == 0) {
        _Size = (undefined *)(ulonglong)(uVar7 * 6);
        *(uint *)(param_1 + 0x1acc) = uVar7;
        memcpy(param_1 + 0x35c,_Buf1,(size_t)_Size);
        uVar5 = local_res20[0];
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          _Size = &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids;
          WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x37,
                     &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1,(char)uVar7,
                     (char)iVar3);
        }
        uVar5 = local_res20[0];
        if (uVar7 != 0) {
          local_res20[0] = local_res20[0] | 4;
          uVar5 = local_res20[0];
        }
      }
    }
    iVar3 = 0;
    if (uVar5 != *(uint *)(param_1 + 0x26c)) {
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res18);
      iVar3 = implatDoOidRequestOnAdapter
                        (param_1,1,0x1010e,local_res20,4,(_NDIS_OID_REQUEST *)0x0,
                         (_IMPLAT_VIRTMINI *)0x0);
      _Size = (undefined *)0x0;
      NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res18);
      if (iVar3 == 0) {
        *(uint *)(param_1 + 0x26c) = local_res20[0];
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          _Size = &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids;
          WPP_SF_qdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x38,
                     &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1,(char)local_res20[0],
                     (char)iVar3);
        }
        uVar7 = *(uint *)(param_1 + 0x26c);
        uVar5 = uVar7 | 2;
        if ((uVar7 & 4) == 0) {
          uVar5 = uVar7;
        }
        if (((uVar5 & local_res20[0]) == local_res20[0]) || ((uVar5 & 0x20) != 0)) {
          iVar3 = 0;
        }
      }
    }
    NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res18);
    lVar4 = *(longlong *)(param_1 + 0x28) + 0x90;
    KeReleaseMutex(lVar4,0);
    if (iVar3 == 0) goto LAB_1c000e3b8;
  }
  if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 4) != 0) {
    McTemplateK0zq_EtwWriteTransfer
              (lVar4,&MemberReCalcPktFiltersErr,_Size,*(wchar_t **)(param_1 + 0x58),(char)iVar3);
  }
  if (_Buf1 == (undefined4 *)0x0) {
    return iVar3;
  }
LAB_1c000e3b8:
  ExFreePoolWithTag(_Buf1,0x6c506d49);
  return iVar3;
}



===== implatStatusEx @ 1c000e3f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl implatStatusEx(void * __ptr64,struct _NDIS_STATUS_INDICATION * __ptr64) */

void __cdecl implatStatusEx(void *param_1,_NDIS_STATUS_INDICATION *param_2)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  longlong lVar4;
  undefined *puVar5;
  undefined2 uVar6;
  undefined *puVar7;
  size_t sVar8;
  undefined8 *puVar9;
  undefined1 auStackY_128 [32];
  undefined2 local_f8;
  undefined1 local_f6;
  _NDIS_STATUS_INDICATION *local_f0;
  undefined8 local_e8;
  undefined4 local_d8;
  undefined1 local_d4 [4];
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  _NDIS_STATUS_INDICATION *local_a8;
  undefined4 local_a0;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_128;
  local_f8 = 0;
  local_f6 = 0;
  puVar7 = (undefined *)0x70;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_f0 = param_2;
  memset(&local_d8,0,0x70);
  local_e8 = 0;
  puVar5 = WPP_GLOBAL_Control;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    puVar5 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
    puVar7 = &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids;
    WPP_SF_qd(puVar5,0x15,&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1,
              (char)*(undefined4 *)(param_2 + 0x14));
  }
  if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
    McTemplateK0zqbr1_EtwWriteTransfer
              (puVar5,&MemberStatusIndicationInfo,puVar7,*(wchar_t **)((longlong)param_1 + 0x58),
               *(undefined4 *)(param_2 + 0x38),*(undefined8 *)(param_2 + 0x30));
  }
  iVar1 = *(int *)(param_2 + 0x14);
  if (iVar1 < 0x40020008) {
    if (iVar1 == 0x40020007) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                 &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1);
      }
      pcVar3 = *(char **)(param_2 + 0x30);
      NdisAcquireRWLockWrite
                (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_f8,0);
      if ((pcVar3 != (char *)0x0) && (*pcVar3 == -0x59)) {
        sVar8 = 0xb4;
        memset((void *)((longlong)param_1 + 0x148),0,0xb4);
        if (*(ushort *)(pcVar3 + 2) < 0xb4) {
          sVar8 = (size_t)*(ushort *)(pcVar3 + 2);
        }
        memcpy((void *)((longlong)param_1 + 0x148),pcVar3,sVar8);
        for (puVar9 = *(undefined8 **)((longlong)param_1 + 0x238);
            puVar9 != (undefined8 *)((longlong)param_1 + 0x238); puVar9 = (undefined8 *)*puVar9) {
          implatTaskOffloadRecalculateAndIndicateChange((_IMPLAT_VIRTMINI *)puVar9[-1]);
        }
      }
    }
    else if (iVar1 == 0x40010004) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
                 &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1);
      }
      NdisAcquireRWLockWrite
                (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_f8,0);
      *(undefined1 *)((longlong)param_1 + 0xf8) = 1;
      KeClearEvent((longlong)param_1 + 0x130);
    }
    else if (iVar1 == 0x40010005) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
                 &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1);
      }
      NdisAcquireRWLockWrite
                (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_f8,0);
      *(undefined1 *)((longlong)param_1 + 0xf8) = 0;
      KeSetEvent((longlong)param_1 + 0x130,0,0);
    }
    else {
      if (iVar1 != 0x40010017) {
        if (iVar1 == 0x40010023) {
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 5)) goto LAB_1c000ecc4;
          uVar6 = 0x1f;
        }
        else {
          if (iVar1 == 0x40020006) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
               (4 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                       &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1);
            }
            pcVar3 = *(char **)(param_2 + 0x30);
            NdisAcquireRWLockWrite
                      (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_f8,0);
            if ((pcVar3 != (char *)0x0) && (*pcVar3 == -0x59)) {
              sVar8 = 0xb4;
              memset((void *)((longlong)param_1 + 0x28c),0,0xb4);
              if (*(ushort *)(pcVar3 + 2) < 0xb4) {
                sVar8 = (size_t)*(ushort *)(pcVar3 + 2);
              }
              memcpy((void *)((longlong)param_1 + 0x28c),pcVar3,sVar8);
              if (*(longlong *)((longlong)param_1 + 800) == 0) {
                *(byte *)((longlong)param_1 + 0x1af0) = *(byte *)((longlong)param_1 + 0x1af0) & 0xfe
                ;
              }
              for (puVar9 = *(undefined8 **)((longlong)param_1 + 0x238);
                  puVar9 != (undefined8 *)((longlong)param_1 + 0x238);
                  puVar9 = (undefined8 *)*puVar9) {
                implatTaskOffloadRecalculateAndIndicateChange((_IMPLAT_VIRTMINI *)puVar9[-1]);
              }
            }
            goto LAB_1c000ec6a;
          }
LAB_1c000ea4f:
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 5)) goto LAB_1c000ecc4;
          uVar6 = 0x23;
        }
LAB_1c000ea7a:
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,
                 &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1);
        goto LAB_1c000ecc4;
      }
      if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 1) != 0) {
        McTemplateK0zqbr1_EtwWriteTransfer
                  (0,&MemberLinkIndicationInfo,puVar7,*(wchar_t **)((longlong)param_1 + 0x58),
                   *(undefined4 *)(param_2 + 0x38),*(undefined8 *)(param_2 + 0x30));
      }
      lVar4 = *(longlong *)(param_2 + 0x30);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_DL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                  &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,
                  *(undefined4 *)((longlong)param_1 + 0xb0),(char)*(undefined4 *)(lVar4 + 4));
      }
      NdisAcquireRWLockWrite
                (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_f8,0);
      *(undefined4 *)((longlong)param_1 + 0xcc) = *(undefined4 *)(lVar4 + 4);
      *(undefined4 *)((longlong)param_1 + 0xd0) = *(undefined4 *)(lVar4 + 8);
      *(undefined8 *)((longlong)param_1 + 0xd8) = *(undefined8 *)(lVar4 + 0x10);
      *(undefined8 *)((longlong)param_1 + 0xe0) = *(undefined8 *)(lVar4 + 0x18);
      *(undefined4 *)((longlong)param_1 + 0xe8) = *(undefined4 *)(lVar4 + 0x20);
      puVar9 = *(undefined8 **)((longlong)param_1 + 0x238);
      *(undefined4 *)((longlong)param_1 + 0xec) = *(undefined4 *)(lVar4 + 0x24);
      for (; puVar9 != (undefined8 *)((longlong)param_1 + 0x238); puVar9 = (undefined8 *)*puVar9) {
        if ((2 < *(int *)(puVar9[-1] + 200)) && (*(int *)(puVar9 + 10) != 0)) {
          uStack_60 = *(undefined8 *)((longlong)param_1 + 0xd8);
          uVar2 = *(undefined4 *)((longlong)param_1 + 0xcc);
          uStack_40 = 0;
          local_58 = *(undefined8 *)((longlong)param_1 + 0xe0);
          local_68 = CONCAT44(uVar2,0x300180);
          uStack_50 = 0x200000000;
          local_48 = 2;
          memset(local_d4,0,0x6c);
          local_d8 = 0x700198;
          local_d0 = *(undefined8 *)(puVar9[-1] + 0x20);
          local_c8 = *(undefined4 *)(puVar9 + 10);
          local_c0 = 0;
          local_a8 = (_NDIS_STATUS_INDICATION *)&local_68;
          local_c4 = 0x40010022;
          local_a0 = 0x30;
          local_b8 = 0;
          uStack_b0 = 0;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0 &&
              (4 < (byte)WPP_GLOBAL_Control[0x29])))) {
            WPP_SF_DDL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                       &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,
                       *(undefined4 *)((longlong)param_1 + 0xb0),(char)*(undefined4 *)(puVar9 + 10),
                       (char)uVar2);
          }
          NdisMIndicateStatusEx(*(undefined8 *)(puVar9[-1] + 0x20));
        }
        implatCalculateVirtMiniLinkState((_IMPLAT_VIRTMINI *)puVar9[-1]);
        param_2 = local_f0;
      }
    }
  }
  else if (iVar1 == 0x4002000c) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
               &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1);
    }
    pcVar3 = *(char **)(param_2 + 0x30);
    NdisAcquireRWLockWrite
              (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_f8,0);
    if ((pcVar3 != (char *)0x0) && (*pcVar3 == -0x80)) {
      sVar8 = 0x1c;
      *(undefined8 *)((longlong)param_1 + 0x270) = 0;
      *(undefined8 *)((longlong)param_1 + 0x278) = 0;
      *(undefined8 *)((longlong)param_1 + 0x280) = 0;
      *(undefined4 *)((longlong)param_1 + 0x288) = 0;
      if (*(ushort *)(pcVar3 + 2) < 0x1c) {
        sVar8 = (size_t)*(ushort *)(pcVar3 + 2);
      }
      memcpy((undefined8 *)((longlong)param_1 + 0x270),pcVar3,sVar8);
    }
LAB_1c000ec6a:
    if ((*(int *)((longlong)param_1 + 0xf0) != 2) &&
       (lVar4 = NdisAllocateIoWorkItem(*(undefined8 *)((longlong)param_1 + 0x20)), lVar4 != 0)) {
      LOCK();
      *(int *)((longlong)param_1 + 0x264) = *(int *)((longlong)param_1 + 0x264) + 1;
      UNLOCK();
      NdisQueueIoWorkItem(lVar4,implatCheckAdapterOffloadParametersWorkItem,param_1);
    }
  }
  else {
    if (iVar1 == 0x40030051) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
                 &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1);
      }
      implatRejectWolPattern(param_1,**(ulong **)(param_2 + 0x30));
      goto LAB_1c000ecc4;
    }
    if (iVar1 == 0x40030052) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
                 &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1);
      }
      implatRejectPMOffload(param_1,**(ulong **)(param_2 + 0x30));
      goto LAB_1c000ecc4;
    }
    if (iVar1 == 0x40030053) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
         (4 < (byte)WPP_GLOBAL_Control[0x29])) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                 &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1);
      }
      implatSetAdapterPMCaps(param_1,*(_NDIS_PM_CAPABILITIES **)(param_2 + 0x30));
      goto LAB_1c000ecc4;
    }
    if (iVar1 != 0x40030055) {
      if ((((iVar1 != 0x4002000d) || (*(longlong *)(param_2 + 0x30) == 0)) ||
          (*(uint *)(param_2 + 0x38) < 0x10)) || (*(int *)((longlong)param_1 + 0x1c90) == 0))
      goto LAB_1c000ea4f;
      if (*(int *)(*(longlong *)(param_2 + 0x30) + 0xc) == 3) {
        KeSetEvent((longlong)param_1 + 0x1ca0,0,0);
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) == 0)) ||
         ((byte)WPP_GLOBAL_Control[0x29] < 5)) goto LAB_1c000ecc4;
      uVar6 = 0x22;
      goto LAB_1c000ea7a;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) &&
       (4 < (byte)WPP_GLOBAL_Control[0x29])) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1);
    }
    NdisAcquireRWLockWrite
              (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_f8,0);
    for (puVar9 = *(undefined8 **)((longlong)param_1 + 0x238);
        puVar9 != (undefined8 *)((longlong)param_1 + 0x238); puVar9 = (undefined8 *)*puVar9) {
      if ((2 < *(int *)(puVar9[-1] + 200)) && (*(int *)(puVar9 + 10) != 0)) {
        NdisMIndicateStatusEx(*(undefined8 *)(puVar9[-1] + 0x20),param_2);
      }
    }
  }
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_f8);
LAB_1c000ecc4:
  NdisAcquireRWLockRead(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_f8,0)
  ;
  for (puVar9 = *(undefined8 **)((longlong)param_1 + 0x238);
      puVar9 != (undefined8 *)((longlong)param_1 + 0x238); puVar9 = (undefined8 *)*puVar9) {
    if ((2 < *(int *)(puVar9[-1] + 200)) && (*(int *)(puVar9 + 10) != 0)) {
      memset(local_d4,0,0x6c);
      local_d8 = 0x700198;
      local_d0 = *(undefined8 *)(puVar9[-1] + 0x20);
      local_c8 = *(undefined4 *)(puVar9 + 10);
      local_c0 = 0;
      local_c4 = 0x40050001;
      local_a0 = 0x70;
      local_b8 = 0;
      uStack_b0 = 0;
      local_a8 = param_2;
      NdisMIndicateStatusEx(*(undefined8 *)(puVar9[-1] + 0x20));
    }
  }
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_f8);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
              &WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_1,
              (char)*(undefined4 *)(param_2 + 0x14));
  }
  return;
}



===== McTemplateK0qz_EtwWriteTransfer @ 1c000ee08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qz_EtwWriteTransfer(void)

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
  local_30 = 4;
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
  McGenEventWrite_EtwWriteTransfer(in_stack_00000028,&NetPnPEventInfo,0,3,local_48);
  return;
}



===== McTemplateK0qzqbr2d_EtwWriteTransfer @ 1c000eeb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qzqbr2d_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               wchar_t *param_5,undefined4 param_6,undefined8 param_7,undefined1 param_8)

{
  longlong lVar1;
  undefined4 local_res20 [2];
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = local_res20;
  local_60 = 4;
  if (param_5 == (wchar_t *)0x0) {
    local_50 = 10;
  }
  else {
    lVar1 = -1;
    do {
      lVar1 = lVar1 + 1;
    } while (param_5[lVar1] != L'\0');
    local_50 = (int)lVar1 * 2 + 2;
  }
  local_48 = &param_6;
  local_4c = 0;
  local_38 = param_7;
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_30 = param_6;
  local_28 = &param_8;
  local_2c = 0;
  local_40 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  local_58 = param_5;
  McGenEventWrite_EtwWriteTransfer(param_5,param_2,0,6,local_78);
  return;
}



===== McTemplateK0qzzd_EtwWriteTransfer @ 1c000ef88 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qzzd_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 local_res20 [8];
  wchar_t *in_stack_00000028;
  wchar_t *in_stack_00000030;
  undefined1 uStack0000000000000038;
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined1 *local_58;
  undefined8 local_50;
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res20;
  lVar1 = -1;
  local_50 = 4;
  local_30 = 10;
  if (in_stack_00000028 == (wchar_t *)0x0) {
    local_40 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_stack_00000028[lVar2] != L'\0');
    local_40 = (int)lVar2 * 2 + 2;
  }
  local_3c = 0;
  if (in_stack_00000028 == (wchar_t *)0x0) {
    in_stack_00000028 = L"NULL";
  }
  if (in_stack_00000030 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000030[lVar1] != L'\0');
    local_30 = (int)lVar1 * 2 + 2;
  }
  if (in_stack_00000030 == (wchar_t *)0x0) {
    in_stack_00000030 = L"NULL";
  }
  local_28 = &uStack0000000000000038;
  local_2c = 0;
  local_20 = 4;
  local_48 = in_stack_00000028;
  local_38 = in_stack_00000030;
  McGenEventWrite_EtwWriteTransfer(in_stack_00000028,&OidForwardingWarn,0,5,local_68);
  return;
}



===== McTemplateK0zzq_EtwWriteTransfer @ 1c000f078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0zzq_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  wchar_t *in_R9;
  wchar_t *in_stack_00000028;
  undefined1 uStack0000000000000030;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  wchar_t *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  wchar_t *local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar1 = -1;
  local_30 = 10;
  if (in_R9 == (wchar_t *)0x0) {
    uVar3 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (in_R9[lVar2] != L'\0');
    uVar3 = (ulonglong)((int)lVar2 * 2 + 2);
  }
  local_40 = (undefined4)uVar3;
  local_3c = 0;
  if (in_R9 == (wchar_t *)0x0) {
    in_R9 = L"NULL";
  }
  if (in_stack_00000028 != (wchar_t *)0x0) {
    do {
      lVar1 = lVar1 + 1;
    } while (in_stack_00000028[lVar1] != L'\0');
    local_30 = (int)lVar1 * 2 + 2;
  }
  if (in_stack_00000028 == (wchar_t *)0x0) {
    in_stack_00000028 = L"NULL";
  }
  local_28 = &uStack0000000000000030;
  local_2c = 0;
  local_20 = 4;
  local_48 = in_R9;
  local_38 = in_stack_00000028;
  McGenEventWrite_EtwWriteTransfer(uVar3,&TeamNicMemberNewPerPortPktFiltersInfo,0,4,local_58);
  return;
}



===== WPP_SF_qdD @ 1c000f158 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,0x35,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qdDd @ 1c000f1c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qdDd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,0x36,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qqdD @ 1c000f234 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqdD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b1805d27aad93bbaeb6dd2d360c8499d_Traceguids,param_2,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== implatPrepareForSendNetBufferLists @ 1c000f2a8 =====

/* int __cdecl implatPrepareForSendNetBufferLists(struct _IMPLAT_VIRTMINI * __ptr64,struct
   _IMPLAT_ADAPTER * __ptr64,struct _IMPLAT_INTERNAL_BINDING * __ptr64,struct _NET_BUFFER_LIST *
   __ptr64,unsigned long) */

int __cdecl
implatPrepareForSendNetBufferLists
          (_IMPLAT_VIRTMINI *param_1,_IMPLAT_ADAPTER *param_2,_IMPLAT_INTERNAL_BINDING *param_3,
          _NET_BUFFER_LIST *param_4,ulong param_5)

{
  int *piVar1;
  ushort uVar2;
  uint uVar3;
  char *pcVar4;
  _NET_BUFFER_LIST *p_Var5;
  uchar uVar6;
  int iVar7;
  _NET_BUFFER_LIST *p_Var8;
  longlong lVar9;
  int iVar10;
  
  iVar10 = 0;
  if ((((*(int *)(param_2 + 0xf0) == 5) && (*(int *)(param_2 + 0xf4) == 1)) &&
      (param_2[0xf8] == (_IMPLAT_ADAPTER)0x0)) && (*(int *)(param_2 + 0xcc) == 1)) {
    uVar3 = *(uint *)(param_3 + 0x60);
    pcVar4 = *(char **)(*(longlong *)(param_2 + 0x28) + 0x438);
    p_Var5 = param_4;
    if (pcVar4 != (char *)0x0) {
      p_Var8 = param_4;
      if (*pcVar4 == '\0') {
        return 0x40020005;
      }
      do {
        if (*(longlong *)(p_Var8 + 0x98) != 0) {
          lVar9 = (ulonglong)(*(int *)(p_Var8 + 0x98) - 1) * 0x610;
          if (*(char *)(lVar9 + 1 + *(longlong *)(pcVar4 + 0x18)) != '\0') {
            return 0x40020005;
          }
          *(longlong *)(p_Var8 + 0x98) =
               *(longlong *)(*(longlong *)(pcVar4 + 0x18) + ((ulonglong)uVar3 + 1) * 0x18 + lVar9);
        }
        p_Var8 = *(_NET_BUFFER_LIST **)p_Var8;
      } while (p_Var8 != (_NET_BUFFER_LIST *)0x0);
    }
    while( true ) {
      if (p_Var5 == (_NET_BUFFER_LIST *)0x0) {
        piVar1 = (int *)(*(longlong *)(param_1 + 0xf0) +
                        (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
        *piVar1 = *piVar1 + iVar10;
        piVar1 = (int *)(*(longlong *)(param_2 + 600) +
                        (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
        *piVar1 = *piVar1 + iVar10;
        iVar10 = *(int *)(param_3 + 0x60);
        if ((*(int *)(param_1 + 0x428) != 0) && (param_4 != (_NET_BUFFER_LIST *)0x0)) {
          do {
            *(undefined2 *)(param_4 + 0x102) =
                 *(undefined2 *)
                  (*(longlong *)(param_1 + 0x430) +
                  ((ulonglong)*(ushort *)(param_4 + 0x102) * 0x15a + (ulonglong)(iVar10 - 1)) * 4);
            param_4 = *(_NET_BUFFER_LIST **)param_4;
          } while (param_4 != (_NET_BUFFER_LIST *)0x0);
        }
        return 0;
      }
      iVar10 = iVar10 + 1;
      iVar7 = NdisAllocateNetBufferListContext(p_Var5,0x10,0,0x6c506d49);
      if (iVar7 != 0) break;
      lVar9 = *(longlong *)(p_Var5 + 0x10);
      uVar2 = *(ushort *)(lVar9 + 10);
      *(_IMPLAT_VIRTMINI **)((ulonglong)uVar2 + 0x10 + lVar9) = param_1;
      *(undefined8 *)((ulonglong)uVar2 + 0x18 + lVar9) = *(undefined8 *)(p_Var5 + 0x78);
      if ((*(int *)(param_1 + 0x440) != 0) &&
         (uVar6 = implatShouldNblBeTagged(p_Var5), uVar6 != '\0')) {
        *(uint *)(p_Var5 + 0xb0) =
             (*(int *)(param_1 + 0x440) << 4 ^ *(uint *)(p_Var5 + 0xb0)) & 0xfff0 ^
             *(uint *)(p_Var5 + 0xb0);
      }
      *(undefined8 *)(p_Var5 + 0x78) = *(undefined8 *)(param_2 + 0x20);
      p_Var5 = *(_NET_BUFFER_LIST **)p_Var5;
    }
    for (; param_4 != p_Var5; param_4 = *(_NET_BUFFER_LIST **)param_4) {
      *(undefined8 *)(param_4 + 0x78) =
           *(undefined8 *)
            ((ulonglong)*(ushort *)(*(longlong *)(param_4 + 0x10) + 10) + 0x18 +
            *(longlong *)(param_4 + 0x10));
      NdisFreeNetBufferListContext(param_4,0x10);
    }
  }
  return -0x3fffffff;
}



===== implatReceiveNetBufferLists @ 1c000f4d0 =====

/* void __cdecl implatReceiveNetBufferLists(void * __ptr64,struct _NET_BUFFER_LIST *
   __ptr64,unsigned long,unsigned long,unsigned long) */

void __cdecl
implatReceiveNetBufferLists
          (void *param_1,_NET_BUFFER_LIST *param_2,ulong param_3,ulong param_4,ulong param_5)

{
  int *piVar1;
  _NET_BUFFER_LIST *p_Var2;
  char cVar3;
  _IMPLAT_INTERNAL_BINDING *p_Var4;
  _NET_BUFFER_LIST *p_Var5;
  undefined4 in_register_00000084;
  undefined4 in_register_0000008c;
  void *pvVar6;
  ulong uVar7;
  _IMPLAT_INTERNAL_BINDING *p_Var8;
  _NET_BUFFER_LIST *p_Var9;
  undefined2 local_res8;
  undefined1 local_resa;
  ulong in_stack_ffffffffffffffb0;
  uchar in_stack_ffffffffffffffc0;
  _NET_BUFFER_LIST *local_38;
  
  pvVar6 = (void *)CONCAT44(in_register_0000008c,param_4);
  local_res8 = 0;
  local_resa = 0;
  if ((param_5 & 1) == 0) {
    cVar3 = KfRaiseIrql(2,param_2,CONCAT44(in_register_00000084,param_3));
    param_5 = param_5 | 1;
  }
  else {
    cVar3 = '\x02';
  }
  NdisAcquireRWLockRead
            (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_res8,1);
  piVar1 = (int *)(*(longlong *)((longlong)param_1 + 600) + 4 +
                  (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
  *piVar1 = *piVar1 + param_4;
  if ((((*(int *)((longlong)param_1 + 0xf0) == 5) && (*(int *)((longlong)param_1 + 0xf4) == 1)) &&
      (*(int *)((longlong)param_1 + 0xcc) == 1)) &&
     ((*(char *)((longlong)param_1 + 0xf8) == '\0' && (*(int *)((longlong)param_1 + 0x26c) != 0))))
  {
    p_Var4 = (_IMPLAT_INTERNAL_BINDING *)0x0;
    uVar7 = 0;
    if (param_2 != (_NET_BUFFER_LIST *)0x0) {
      p_Var5 = (_NET_BUFFER_LIST *)0x0;
      p_Var8 = p_Var4;
      p_Var9 = param_2;
      local_38 = param_2;
      do {
        *(ulonglong *)(p_Var9 + 0x110) = (ulonglong)*(uint *)((longlong)param_1 + 0xb0);
        p_Var4 = implatRouteReceivedNBL(param_1,p_Var9);
        if ((p_Var4 == p_Var8) || (p_Var9 == param_2)) {
          uVar7 = uVar7 + 1;
        }
        else {
          *(undefined8 *)p_Var5 = 0;
          implatTryToIndicateReceiveNBLs
                    (p_Var8,param_1,local_38,uVar7,param_5 & 0xffffefff,in_stack_ffffffffffffffb0,
                     (_LOCK_STATE_EX *)&local_res8,in_stack_ffffffffffffffc0);
          if ((param_5 & 2) != 0) {
            *(_NET_BUFFER_LIST **)p_Var5 = p_Var9;
          }
          uVar7 = 1;
          local_38 = p_Var9;
        }
        p_Var2 = *(_NET_BUFFER_LIST **)p_Var9;
        p_Var5 = p_Var9;
        p_Var8 = p_Var4;
        p_Var9 = p_Var2;
      } while (p_Var2 != (_NET_BUFFER_LIST *)0x0);
      param_2 = local_38;
    }
    implatTryToIndicateReceiveNBLs
              (p_Var4,param_1,param_2,uVar7,param_5 & 0xffffefff,in_stack_ffffffffffffffb0,
               (_LOCK_STATE_EX *)&local_res8,in_stack_ffffffffffffffc0);
    if ((param_5 & 2) != 0) {
      piVar1 = (int *)(*(longlong *)((longlong)param_1 + 600) + 4 +
                      (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
      *piVar1 = *piVar1 - param_4;
    }
    NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_res8);
  }
  else {
    NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x28) + 0x88),&local_res8);
    implatEtwWritePerNblEvent(3,param_2,*(void **)((longlong)param_1 + 0x58),pvVar6);
    if ((param_5 & 2) == 0) {
      NdisReturnNetBufferLists(*(undefined8 *)((longlong)param_1 + 0x20),param_2,1);
    }
    piVar1 = (int *)(*(longlong *)((longlong)param_1 + 600) + 4 +
                    (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
    *piVar1 = *piVar1 - param_4;
  }
  if (cVar3 != '\x02') {
    KeLowerIrql(cVar3);
  }
  return;
}



===== implatReturnNetBufferLists @ 1c000f770 =====

/* void __cdecl implatReturnNetBufferLists(void * __ptr64,struct _NET_BUFFER_LIST * __ptr64,unsigned
   long) */

void __cdecl implatReturnNetBufferLists(void *param_1,_NET_BUFFER_LIST *param_2,ulong param_3)

{
  int *piVar1;
  longlong lVar2;
  char cVar3;
  _NET_BUFFER_LIST *p_Var4;
  _NET_BUFFER_LIST *p_Var5;
  _NET_BUFFER_LIST *p_Var6;
  longlong *plVar7;
  int iVar8;
  longlong *plVar9;
  int local_res8;
  _NET_BUFFER_LIST *local_res20;
  
  if ((param_3 & 1) == 0) {
    cVar3 = KfRaiseIrql();
    param_3 = param_3 | 1;
  }
  else {
    cVar3 = '\x02';
  }
  local_res20 = (_NET_BUFFER_LIST *)0x0;
  plVar9 = (longlong *)0x0;
  local_res8 = 0;
  iVar8 = 0;
  p_Var6 = param_2;
  if (param_2 != (_NET_BUFFER_LIST *)0x0) {
    iVar8 = 0;
    p_Var4 = param_2;
    plVar7 = plVar9;
    do {
      p_Var5 = p_Var4;
      plVar9 = *(longlong **)(p_Var5 + 0x138);
      iVar8 = iVar8 + 1;
      *(undefined8 *)(p_Var5 + 0x138) = 0;
      if (((ulonglong)plVar9 & 1) != 0) {
        plVar9 = (longlong *)((ulonglong)plVar9 & 0xfffffffffffffffe);
        *(undefined8 *)(p_Var5 + 0x138) =
             *(undefined8 *)
              ((ulonglong)*(ushort *)(*(longlong *)(p_Var5 + 0x10) + 10) + 0x10 +
              *(longlong *)(p_Var5 + 0x10));
        NdisFreeNetBufferListContext(p_Var5,8);
      }
      if ((plVar9 == plVar7) || (p_Var5 == param_2)) {
        local_res8 = local_res8 + 1;
      }
      else {
        *(undefined8 *)local_res20 = 0;
        lVar2 = plVar7[0xc];
        if ((*(int *)((longlong)param_1 + 0x428) != 0) && (p_Var6 != (_NET_BUFFER_LIST *)0x0)) {
          p_Var4 = p_Var6;
          do {
            *(undefined2 *)(p_Var4 + 0x102) =
                 *(undefined2 *)
                  (*(longlong *)((longlong)param_1 + 0x430) +
                  ((ulonglong)*(ushort *)(p_Var4 + 0x102) * 0x15a + (ulonglong)((int)lVar2 - 1)) * 4
                  );
            p_Var4 = *(_NET_BUFFER_LIST **)p_Var4;
          } while (p_Var4 != (_NET_BUFFER_LIST *)0x0);
        }
        NdisReturnNetBufferLists(*(undefined8 *)(*plVar7 + 0x20),p_Var6,param_3);
        piVar1 = (int *)(*(longlong *)(*plVar7 + 600) + 4 +
                        (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
        *piVar1 = *piVar1 - local_res8;
        local_res8 = 1;
        p_Var6 = p_Var5;
      }
      p_Var4 = *(_NET_BUFFER_LIST **)p_Var5;
      plVar7 = plVar9;
      local_res20 = p_Var5;
    } while (*(_NET_BUFFER_LIST **)p_Var5 != (_NET_BUFFER_LIST *)0x0);
  }
  lVar2 = plVar9[0xc];
  if ((*(int *)((longlong)param_1 + 0x428) != 0) && (p_Var6 != (_NET_BUFFER_LIST *)0x0)) {
    p_Var4 = p_Var6;
    do {
      *(undefined2 *)(p_Var4 + 0x102) =
           *(undefined2 *)
            (*(longlong *)((longlong)param_1 + 0x430) +
            ((ulonglong)*(ushort *)(p_Var4 + 0x102) * 0x15a + (ulonglong)((int)lVar2 - 1)) * 4);
      p_Var4 = *(_NET_BUFFER_LIST **)p_Var4;
    } while (p_Var4 != (_NET_BUFFER_LIST *)0x0);
  }
  NdisReturnNetBufferLists(*(undefined8 *)(*plVar9 + 0x20),p_Var6,param_3);
  piVar1 = (int *)(*(longlong *)((longlong)param_1 + 0xf0) + 4 +
                  (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
  *piVar1 = *piVar1 - iVar8;
  piVar1 = (int *)(*(longlong *)(*plVar9 + 600) + 4 + (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0)
  ;
  *piVar1 = *piVar1 - local_res8;
  if (cVar3 != '\x02') {
    KeLowerIrql(CONCAT31((int3)((uint)local_res8 >> 8),cVar3));
  }
  return;
}



===== implatRouteReceivedNBL @ 1c000f9c4 =====

/* struct _IMPLAT_INTERNAL_BINDING * __ptr64 __cdecl implatRouteReceivedNBL(struct _IMPLAT_ADAPTER *
   __ptr64,struct _NET_BUFFER_LIST * __ptr64) */

_IMPLAT_INTERNAL_BINDING * __cdecl
implatRouteReceivedNBL(_IMPLAT_ADAPTER *param_1,_NET_BUFFER_LIST *param_2)

{
  longlong lVar1;
  uchar uVar2;
  longlong lVar3;
  _IMPLAT_ADAPTER *p_Var4;
  _IMPLAT_INTERNAL_BINDING *p_Var5;
  
  lVar3 = RtlLookupEntryHashTable
                    (*(undefined8 *)(param_1 + 0x248),(*(uint *)(param_2 + 0xb0) >> 4 & 0xfff) + 1,0
                    );
  if ((lVar3 == 0) &&
     ((*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x150) == 0 ||
      (lVar3 = RtlLookupEntryHashTable
                         (*(undefined8 *)(param_1 + 0x248),
                          *(int *)(*(longlong *)(*(longlong *)(param_1 + 0x28) + 0x150) + 0x440) + 1
                          ,0), lVar3 == 0)))) {
    uVar2 = implatShouldNblBeTagged(param_2);
    if (uVar2 == '\0') {
      for (p_Var4 = *(_IMPLAT_ADAPTER **)(param_1 + 0x238); p_Var4 != param_1 + 0x238;
          p_Var4 = *(_IMPLAT_ADAPTER **)p_Var4) {
        lVar1 = *(longlong *)(p_Var4 + -8);
        if (((2 < *(int *)(lVar1 + 200)) && (*(int *)(p_Var4 + 0x50) != 0)) &&
           (*(int *)(lVar1 + 0xcc) < 2)) {
          lVar3 = RtlLookupEntryHashTable
                            (*(undefined8 *)(param_1 + 0x248),*(int *)(lVar1 + 0x440) + 1,0);
          break;
        }
      }
      if (lVar3 != 0) goto LAB_1c000faaa;
    }
    p_Var5 = (_IMPLAT_INTERNAL_BINDING *)0x0;
  }
  else {
LAB_1c000faaa:
    p_Var5 = (_IMPLAT_INTERNAL_BINDING *)(lVar3 + -0x30);
  }
  return p_Var5;
}



===== implatSendNetBufferLists @ 1c000fad0 =====

/* void __cdecl implatSendNetBufferLists(void * __ptr64,struct _NET_BUFFER_LIST * __ptr64,unsigned
   long,unsigned long) */

void __cdecl
implatSendNetBufferLists(void *param_1,_NET_BUFFER_LIST *param_2,ulong param_3,ulong param_4)

{
  char cVar1;
  int iVar2;
  undefined8 *puVar3;
  _IMPLAT_ADAPTER *p_Var4;
  _IMPLAT_ETW_NBL_EVENT_TYPE _Var5;
  _IMPLAT_INTERNAL_BINDING *p_Var6;
  void *pvVar7;
  undefined4 in_register_0000008c;
  _NET_BUFFER_LIST *p_Var8;
  _IMPLAT_ADAPTER *p_Var9;
  _IMPLAT_INTERNAL_BINDING *local_res8;
  undefined2 local_res20;
  undefined1 local_res22;
  ulong in_stack_ffffffffffffffc8;
  
  p_Var8 = (_NET_BUFFER_LIST *)CONCAT44(in_register_0000008c,param_4);
  p_Var9 = (_IMPLAT_ADAPTER *)0x0;
  local_res8 = (_IMPLAT_INTERNAL_BINDING *)0x0;
  local_res20 = 0;
  local_res22 = 0;
  iVar2 = -0x3fffffff;
  if ((param_4 & 1) == 0) {
    cVar1 = KfRaiseIrql(2);
    param_4 = param_4 | 1;
  }
  else {
    cVar1 = '\x02';
  }
  NdisAcquireRWLockRead
            (*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_res20);
  if (((*(int *)((longlong)param_1 + 200) == 5) && (*(int *)((longlong)param_1 + 0xcc) == 1)) &&
     (*(int *)((longlong)param_1 + 0xa4) == 1)) {
    if (param_3 == 0) {
      for (puVar3 = *(undefined8 **)((longlong)param_1 + 0x60);
          puVar3 != (undefined8 *)((longlong)param_1 + 0x60); puVar3 = (undefined8 *)*puVar3) {
        p_Var4 = *(_IMPLAT_ADAPTER **)(puVar3 + -4);
        if (((*(int *)(p_Var4 + 0xf0) == 5) && (*(int *)(p_Var4 + 0xf4) == 1)) &&
           ((p_Var4[0xf8] == (_IMPLAT_ADAPTER)0x0 &&
            ((*(int *)(p_Var4 + 0xcc) == 1 && (*(int *)(puVar3 + 8) != 0)))))) {
          p_Var6 = (_IMPLAT_INTERNAL_BINDING *)(puVar3 + -4);
          goto LAB_1c000fbd6;
        }
      }
    }
    else {
      p_Var4 = implatFindAdapterByPortNumber(param_1,param_3,&local_res8);
      p_Var6 = local_res8;
LAB_1c000fbd6:
      p_Var9 = p_Var4;
      if (p_Var4 != (_IMPLAT_ADAPTER *)0x0) {
        p_Var8 = param_2;
        iVar2 = implatPrepareForSendNetBufferLists
                          (param_1,p_Var4,p_Var6,param_2,in_stack_ffffffffffffffc8);
        if ((iVar2 == 0) || (iVar2 == 0x103)) goto LAB_1c000fc15;
        _Var5 = 2;
        goto LAB_1c000fc09;
      }
    }
    pvVar7 = (void *)0x0;
    _Var5 = 1;
    p_Var4 = p_Var9;
  }
  else {
    _Var5 = 0;
LAB_1c000fc09:
    pvVar7 = *(void **)((longlong)param_1 + 0x30);
    p_Var4 = p_Var9;
  }
  implatEtwWritePerNblEvent(_Var5,param_2,pvVar7,p_Var8);
LAB_1c000fc15:
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)((longlong)param_1 + 0x48) + 0x88),&local_res20);
  if (iVar2 == 0) {
    NdisSendNetBufferLists(*(undefined8 *)(p_Var4 + 0x20),param_2,0,param_4 & 0xfffffffd);
  }
  else {
    p_Var8 = param_2;
    if (iVar2 != 0x103) {
      for (; p_Var8 != (_NET_BUFFER_LIST *)0x0; p_Var8 = *(_NET_BUFFER_LIST **)p_Var8) {
        *(undefined4 *)(p_Var8 + 0x8c) = 0xc001000c;
      }
      implatUpdateOutStatisticsCounters(param_1,param_2);
      NdisMSendNetBufferListsComplete(*(undefined8 *)((longlong)param_1 + 0x20),param_2,1);
    }
  }
  if (cVar1 != '\x02') {
    KeLowerIrql(cVar1);
  }
  return;
}



===== implatSendNetBufferListsComplete @ 1c000fcd0 =====

/* void __cdecl implatSendNetBufferListsComplete(void * __ptr64,struct _NET_BUFFER_LIST *
   __ptr64,unsigned long) */

void __cdecl implatSendNetBufferListsComplete(void *param_1,_NET_BUFFER_LIST *param_2,ulong param_3)

{
  int *piVar1;
  ushort uVar2;
  longlong lVar3;
  char cVar4;
  _NET_BUFFER_LIST *p_Var5;
  _NET_BUFFER_LIST *p_Var6;
  _IMPLAT_VIRTMINI *p_Var7;
  _IMPLAT_VIRTMINI *p_Var8;
  _NET_BUFFER_LIST *p_Var9;
  int iVar10;
  int iVar11;
  _NET_BUFFER_LIST *local_res20;
  
  iVar11 = 0;
  iVar10 = 0;
  if ((param_3 & 1) == 0) {
    cVar4 = KfRaiseIrql(2);
    param_3 = param_3 | 1;
  }
  else {
    cVar4 = '\x02';
  }
  p_Var7 = (_IMPLAT_VIRTMINI *)0x0;
  local_res20 = param_2;
  if ((*(int *)((longlong)param_1 + 0x1c90) == 0) ||
     (p_Var5 = param_2, param_2 == (_NET_BUFFER_LIST *)0x0)) {
    if (param_2 == (_NET_BUFFER_LIST *)0x0) goto LAB_1c000fe4a;
  }
  else {
    do {
      *(undefined2 *)(p_Var5 + 0x102) =
           *(undefined2 *)
            (*(longlong *)((longlong)param_1 + 0x1c98) + (ulonglong)*(ushort *)(p_Var5 + 0x102) * 4)
      ;
      p_Var5 = *(_NET_BUFFER_LIST **)p_Var5;
    } while (p_Var5 != (_NET_BUFFER_LIST *)0x0);
  }
  iVar10 = 0;
  p_Var5 = param_2;
  p_Var8 = p_Var7;
  p_Var9 = (_NET_BUFFER_LIST *)0x0;
  do {
    p_Var6 = p_Var5;
    lVar3 = *(longlong *)(p_Var6 + 0x10);
    iVar10 = iVar10 + 1;
    uVar2 = *(ushort *)(lVar3 + 10);
    *(undefined8 *)(p_Var6 + 0x78) = *(undefined8 *)((ulonglong)uVar2 + 0x18 + lVar3);
    p_Var7 = *(_IMPLAT_VIRTMINI **)((ulonglong)uVar2 + 0x10 + lVar3);
    NdisFreeNetBufferListContext(p_Var6,0x10);
    if ((p_Var7 == p_Var8) || (p_Var6 == param_2)) {
      iVar11 = iVar11 + 1;
    }
    else {
      *(undefined8 *)p_Var9 = 0;
      implatUpdateOutStatisticsCounters(p_Var8,local_res20);
      NdisMSendNetBufferListsComplete(*(undefined8 *)(p_Var8 + 0x20),local_res20,param_3);
      piVar1 = (int *)(*(longlong *)(p_Var8 + 0xf0) + (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0)
      ;
      *piVar1 = *piVar1 - iVar11;
      iVar11 = 1;
      local_res20 = p_Var6;
    }
    p_Var5 = *(_NET_BUFFER_LIST **)p_Var6;
    p_Var8 = p_Var7;
    p_Var9 = p_Var6;
  } while (*(_NET_BUFFER_LIST **)p_Var6 != (_NET_BUFFER_LIST *)0x0);
LAB_1c000fe4a:
  implatUpdateOutStatisticsCounters(p_Var7,local_res20);
  NdisMSendNetBufferListsComplete(*(undefined8 *)(p_Var7 + 0x20),local_res20,param_3);
  piVar1 = (int *)(*(longlong *)(p_Var7 + 0xf0) + (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
  *piVar1 = *piVar1 - iVar11;
  piVar1 = (int *)(*(longlong *)((longlong)param_1 + 600) +
                  (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
  *piVar1 = *piVar1 - iVar10;
  if (cVar4 != '\x02') {
    KeLowerIrql(cVar4);
  }
  return;
}



===== implatShouldNblBeTagged @ 1c000fed4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* unsigned char __cdecl implatShouldNblBeTagged(struct _NET_BUFFER_LIST * __ptr64) */

uchar __cdecl implatShouldNblBeTagged(_NET_BUFFER_LIST *param_1)

{
  uchar uVar1;
  int *piVar2;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  int local_28;
  short local_24;
  undefined4 local_20;
  undefined2 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = 0xc28001;
  local_38 = 0;
  local_20 = 0;
  local_1c = 0;
  local_24 = 0x200;
  piVar2 = (int *)NdisGetDataBuffer(*(undefined8 *)(param_1 + 8),6,&local_20,1);
  if (((piVar2 == (int *)0x0) || (*piVar2 != local_28)) || ((short)piVar2[1] != local_24)) {
    uVar1 = '\x01';
  }
  else {
    uVar1 = '\0';
  }
  return uVar1;
}



===== implatTryToIndicateReceiveNBLs @ 1c000ff5c =====

/* void __cdecl implatTryToIndicateReceiveNBLs(struct _IMPLAT_INTERNAL_BINDING * __ptr64,struct
   _IMPLAT_ADAPTER * __ptr64,struct _NET_BUFFER_LIST * __ptr64,unsigned long,unsigned long,unsigned
   long,struct _LOCK_STATE_EX * __ptr64,unsigned char) */

void __cdecl
implatTryToIndicateReceiveNBLs
          (_IMPLAT_INTERNAL_BINDING *param_1,_IMPLAT_ADAPTER *param_2,_NET_BUFFER_LIST *param_3,
          ulong param_4,ulong param_5,ulong param_6,_LOCK_STATE_EX *param_7,uchar param_8)

{
  int *piVar1;
  _IMPLAT_VIRTMINI *p_Var2;
  longlong lVar3;
  _NET_BUFFER_LIST *p_Var4;
  int iVar5;
  _IMPLAT_ETW_NBL_EVENT_TYPE _Var6;
  _NET_BUFFER_LIST *p_Var7;
  _IMPLAT_INTERNAL_BINDING *p_Var8;
  _IMPLAT_INTERNAL_BINDING *p_Var9;
  void *pvVar10;
  undefined4 in_register_0000008c;
  void *pvVar11;
  bool bVar12;
  
  pvVar11 = (void *)CONCAT44(in_register_0000008c,param_4);
  if ((param_1 == (_IMPLAT_INTERNAL_BINDING *)0x0) || (*(int *)(param_1 + 0x60) == 0)) {
    pvVar10 = *(void **)(param_2 + 0x58);
    _Var6 = 5;
  }
  else {
    p_Var2 = *(_IMPLAT_VIRTMINI **)(param_1 + 8);
    if ((((*(int *)(p_Var2 + 200) == 5) && (*(int *)(p_Var2 + 0xcc) == 1)) &&
        (*(int *)(p_Var2 + 0xa4) == 1)) &&
       ((*(int *)(p_Var2 + 0x76c) != 0 || (*(int *)(param_1 + 0x68) != 0)))) {
      p_Var9 = param_1;
      p_Var7 = param_3;
      if ((param_5 & 2) == 0) {
        for (; p_Var7 != (_NET_BUFFER_LIST *)0x0; p_Var7 = *(_NET_BUFFER_LIST **)p_Var7) {
          lVar3 = *(longlong *)(p_Var7 + 0x138);
          if (lVar3 == 0) {
            p_Var8 = p_Var9;
          }
          else {
            iVar5 = NdisAllocateNetBufferListContext(p_Var7,8,0,0x6c506d49);
            p_Var4 = param_3;
            if (iVar5 != 0) goto joined_r0x0001c0010195;
            p_Var8 = (_IMPLAT_INTERNAL_BINDING *)((ulonglong)p_Var9 | 1);
            *(longlong *)
             ((ulonglong)*(ushort *)(*(longlong *)(p_Var7 + 0x10) + 10) + 0x10 +
             *(longlong *)(p_Var7 + 0x10)) = lVar3;
            p_Var9 = (_IMPLAT_INTERNAL_BINDING *)((ulonglong)p_Var9 & 0xfffffffffffffffe);
          }
          *(_IMPLAT_INTERNAL_BINDING **)(p_Var7 + 0x138) = p_Var8;
        }
      }
      piVar1 = (int *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xf0) + 4 +
                      (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
      *piVar1 = *piVar1 + param_4;
      p_Var7 = param_3;
      if (*(int *)(param_2 + 0x1c90) != 0) {
        for (; p_Var7 != (_NET_BUFFER_LIST *)0x0; p_Var7 = *(_NET_BUFFER_LIST **)p_Var7) {
          *(undefined2 *)(p_Var7 + 0x102) =
               *(undefined2 *)
                (*(longlong *)(param_2 + 0x1c98) + (ulonglong)*(ushort *)(p_Var7 + 0x102) * 4);
        }
      }
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x88),param_7);
      implatUpdateInStatisticsCounters(*(_IMPLAT_VIRTMINI **)(param_1 + 8),param_3,0);
      NdisMIndicateReceiveNetBufferLists
                (*(undefined8 *)(*(longlong *)(param_1 + 8) + 0x20),param_3,
                 *(undefined4 *)(param_1 + 0x60),param_4,param_5);
      NdisAcquireRWLockRead(*(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x88),param_7,1);
      bVar12 = false;
      if ((param_5 & 2) != 0) {
        piVar1 = (int *)(*(longlong *)(*(longlong *)(param_1 + 8) + 0xf0) + 4 +
                        (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
        *piVar1 = *piVar1 - param_4;
        bVar12 = false;
        lVar3 = *(longlong *)(param_1 + 8);
        iVar5 = *(int *)(param_1 + 0x60);
        if ((*(int *)(lVar3 + 0x428) != 0) && (param_3 != (_NET_BUFFER_LIST *)0x0)) {
          p_Var7 = param_3;
          do {
            *(undefined2 *)(p_Var7 + 0x102) =
                 *(undefined2 *)
                  (*(longlong *)(lVar3 + 0x430) +
                  ((ulonglong)*(ushort *)(p_Var7 + 0x102) * 0x15a + (ulonglong)(iVar5 - 1)) * 4);
            p_Var7 = *(_NET_BUFFER_LIST **)p_Var7;
          } while (p_Var7 != (_NET_BUFFER_LIST *)0x0);
          bVar12 = false;
        }
      }
      goto LAB_1c0010201;
    }
    implatUpdateInStatisticsCounters(p_Var2,param_3,-0x3fffffff);
    _Var6 = 4;
    pvVar10 = *(void **)(*(longlong *)(param_1 + 8) + 0x30);
  }
  implatEtwWritePerNblEvent(_Var6,param_3,pvVar10,pvVar11);
  bVar12 = (param_5 & 2) == 0;
  goto LAB_1c0010201;
joined_r0x0001c0010195:
  for (; p_Var4 != p_Var7; p_Var4 = *(_NET_BUFFER_LIST **)p_Var4) {
    *(undefined8 *)(p_Var4 + 0x138) =
         *(undefined8 *)
          ((ulonglong)*(ushort *)(*(longlong *)(p_Var4 + 0x10) + 10) + 0x10 +
          *(longlong *)(p_Var4 + 0x10));
    NdisFreeNetBufferListContext(p_Var4,8);
  }
  bVar12 = true;
LAB_1c0010201:
  if (bVar12) {
    NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x88),param_7);
    NdisReturnNetBufferLists(*(undefined8 *)(param_2 + 0x20),param_3,1);
    NdisAcquireRWLockRead(*(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x88),param_7,1);
    piVar1 = (int *)(*(longlong *)(param_2 + 600) + 4 +
                    (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
    *piVar1 = *piVar1 - param_4;
  }
  return;
}



===== implatUpdateInStatisticsCounters @ 1c00102a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl implatUpdateInStatisticsCounters(struct _IMPLAT_VIRTMINI * __ptr64,struct
   _NET_BUFFER_LIST * __ptr64,int) */

void __cdecl
implatUpdateInStatisticsCounters(_IMPLAT_VIRTMINI *param_1,_NET_BUFFER_LIST *param_2,int param_3)

{
  byte *pbVar1;
  ulonglong uVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  int local_78;
  longlong local_70;
  longlong local_68;
  _NET_BUFFER_LIST *local_60;
  _IMPLAT_VIRTMINI *local_58;
  undefined4 local_50;
  undefined2 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar7 = 0;
  lVar4 = 0;
  local_50 = 0;
  lVar10 = 0;
  local_4c = 0;
  lVar11 = 0;
  local_68 = 0;
  lVar5 = 0;
  local_70 = 0;
  lVar8 = 0;
  lVar9 = 0;
  lVar6 = 0;
  local_78 = param_3;
  local_60 = param_2;
  local_58 = param_1;
  if (param_2 != (_NET_BUFFER_LIST *)0x0) {
    do {
      plVar3 = *(longlong **)(local_60 + 8);
      if (plVar3 != (longlong *)0x0) {
        lVar6 = local_68;
        do {
          local_88 = 0;
          pbVar1 = (byte *)NdisGetDataBuffer(plVar3,6,&local_50);
          if (pbVar1 != (byte *)0x0) {
            lVar5 = lVar5 + 1;
            uVar2 = (ulonglong)((int)plVar3[3] + 4);
            local_70 = local_70 + uVar2;
            if (*pbVar1 == 0xff) {
              if ((((pbVar1[1] == 0xff) && (pbVar1[2] == 0xff)) && (pbVar1[3] == 0xff)) &&
                 ((pbVar1[4] == 0xff && (pbVar1[5] == 0xff)))) {
                lVar4 = lVar4 + 1;
                lVar8 = lVar8 + uVar2;
              }
              else {
LAB_1c0010391:
                lVar10 = lVar10 + 1;
                lVar9 = lVar9 + uVar2;
              }
            }
            else {
              if ((*pbVar1 & 1) != 0) goto LAB_1c0010391;
              lVar11 = lVar11 + 1;
              lVar6 = lVar6 + uVar2;
            }
          }
          plVar3 = (longlong *)*plVar3;
        } while (plVar3 != (longlong *)0x0);
        lVar7 = local_70;
        local_68 = lVar6;
      }
      local_60 = *(_NET_BUFFER_LIST **)local_60;
    } while (local_60 != (_NET_BUFFER_LIST *)0x0);
    lVar6 = local_68;
    param_1 = local_58;
  }
  if (local_78 == 0) {
    plVar3 = (longlong *)
             (*(longlong *)(param_1 + 0xf0) + 0x20 + (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
    *plVar3 = *plVar3 + lVar7;
    plVar3 = (longlong *)
             (*(longlong *)(param_1 + 0xf0) + 0x70 + (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
    *plVar3 = *plVar3 + lVar6;
    plVar3 = (longlong *)
             (*(longlong *)(param_1 + 0xf0) + 0x78 + (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
    *plVar3 = *plVar3 + lVar9;
    plVar3 = (longlong *)
             (*(longlong *)(param_1 + 0xf0) + 0x80 + (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
    *plVar3 = *plVar3 + lVar8;
    plVar3 = (longlong *)
             (*(longlong *)(param_1 + 0xf0) + 0xa8 + (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
    *plVar3 = *plVar3 + lVar5;
    plVar3 = (longlong *)
             (*(longlong *)(param_1 + 0xf0) + 0x28 + (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
    *plVar3 = *plVar3 + lVar11;
    plVar3 = (longlong *)
             (*(longlong *)(param_1 + 0xf0) + 0x30 + (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
    *plVar3 = *plVar3 + lVar10;
    plVar3 = (longlong *)
             (*(longlong *)(param_1 + 0xf0) + 0x38 + (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
    *plVar3 = *plVar3 + lVar4;
  }
  else {
    plVar3 = (longlong *)
             (*(longlong *)(param_1 + 0xf0) + 0x10 + (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
    *plVar3 = *plVar3 + lVar5;
  }
  return;
}



===== implatUpdateOutStatisticsCounters @ 1c00104f4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl implatUpdateOutStatisticsCounters(struct _IMPLAT_VIRTMINI * __ptr64,struct
   _NET_BUFFER_LIST * __ptr64) */

void __cdecl implatUpdateOutStatisticsCounters(_IMPLAT_VIRTMINI *param_1,_NET_BUFFER_LIST *param_2)

{
  int iVar1;
  byte *pbVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  longlong local_78;
  longlong local_70;
  longlong local_68;
  _NET_BUFFER_LIST *local_60;
  _IMPLAT_VIRTMINI *local_58;
  undefined4 local_50;
  undefined2 local_4c;
  ulonglong local_48;
  
  if (param_2 != (_NET_BUFFER_LIST *)0x0) {
    local_48 = __security_cookie ^ (ulonglong)auStack_a8;
    local_50 = 0;
    local_4c = 0;
    local_60 = param_2;
    local_58 = param_1;
    do {
      plVar7 = *(longlong **)(local_60 + 8);
      lVar11 = 0;
      local_78 = 0;
      lVar12 = 0;
      lVar9 = 0;
      lVar6 = 0;
      lVar10 = 0;
      lVar5 = 0;
      lVar4 = 0;
      lVar8 = 0;
      if (plVar7 != (longlong *)0x0) {
        lVar5 = 0;
        lVar4 = 0;
        do {
          local_88 = 0;
          pbVar2 = (byte *)NdisGetDataBuffer(plVar7,6,&local_50);
          if (pbVar2 != (byte *)0x0) {
            lVar6 = lVar6 + 1;
            uVar3 = (ulonglong)((int)plVar7[3] + 4);
            local_78 = local_78 + uVar3;
            if (*pbVar2 == 0xff) {
              if ((((pbVar2[1] == 0xff) && (pbVar2[2] == 0xff)) && (pbVar2[3] == 0xff)) &&
                 ((pbVar2[4] == 0xff && (pbVar2[5] == 0xff)))) {
                lVar11 = lVar11 + 1;
                lVar10 = lVar10 + uVar3;
              }
              else {
LAB_1c00105db:
                lVar12 = lVar12 + 1;
                lVar5 = lVar5 + uVar3;
              }
            }
            else {
              if ((*pbVar2 & 1) != 0) goto LAB_1c00105db;
              lVar9 = lVar9 + 1;
              lVar4 = lVar4 + uVar3;
            }
          }
          plVar7 = (longlong *)*plVar7;
        } while (plVar7 != (longlong *)0x0);
        param_1 = local_58;
        lVar8 = local_78;
        local_70 = lVar5;
        local_68 = lVar4;
      }
      iVar1 = *(int *)(local_60 + 0x8c);
      if (iVar1 == 0) {
        plVar7 = (longlong *)
                 (*(longlong *)(param_1 + 0xf0) + 0x40 +
                 (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
        *plVar7 = *plVar7 + lVar8;
        plVar7 = (longlong *)
                 (*(longlong *)(param_1 + 0xf0) + 0x88 +
                 (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
        *plVar7 = *plVar7 + lVar4;
        plVar7 = (longlong *)
                 (*(longlong *)(param_1 + 0xf0) + 0x90 +
                 (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
        *plVar7 = *plVar7 + lVar5;
        plVar7 = (longlong *)
                 (*(longlong *)(param_1 + 0xf0) + 0x98 +
                 (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
        *plVar7 = *plVar7 + lVar10;
        plVar7 = (longlong *)
                 (*(longlong *)(param_1 + 0xf0) + 0xa0 +
                 (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
        *plVar7 = *plVar7 + lVar6;
        plVar7 = (longlong *)
                 (*(longlong *)(param_1 + 0xf0) + 0x48 +
                 (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
        *plVar7 = *plVar7 + lVar9;
        plVar7 = (longlong *)
                 (*(longlong *)(param_1 + 0xf0) + 0x50 +
                 (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
        *plVar7 = *plVar7 + lVar12;
        plVar7 = (longlong *)
                 (*(longlong *)(param_1 + 0xf0) + 0x58 +
                 (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
        *plVar7 = *plVar7 + lVar11;
      }
      else if (((iVar1 == -0x3fffffff) || (iVar1 == -0x3ffeffec)) || (iVar1 == -0x3fffff66)) {
        plVar7 = (longlong *)
                 (*(longlong *)(param_1 + 0xf0) + 0x60 +
                 (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
        *plVar7 = *plVar7 + lVar6;
      }
      else {
        plVar7 = (longlong *)
                 (*(longlong *)(param_1 + 0xf0) + 0x68 +
                 (ulonglong)SystemReserved1[0x12]._4_4_ * 0xc0);
        *plVar7 = *plVar7 + lVar6;
      }
      local_60 = *(_NET_BUFFER_LIST **)local_60;
    } while (local_60 != (_NET_BUFFER_LIST *)0x0);
  }
  return;
}



===== implatAddPMOffload @ 1c00107a0 =====

/* int __cdecl implatAddPMOffload(struct _IMPLAT_VIRTMINI * __ptr64,unsigned char * __ptr64,unsigned
   long) */

int __cdecl implatAddPMOffload(_IMPLAT_VIRTMINI *param_1,uchar *param_2,ulong param_3)

{
  undefined8 uVar1;
  _IMPLAT_ADAPTER *p_Var2;
  code *pcVar3;
  int iVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong *plVar7;
  _IMPLAT_VIRTMINI *p_Var8;
  undefined1 *puVar9;
  int iVar10;
  undefined2 local_res18;
  undefined1 local_res1a;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  local_res18 = 0;
  iVar10 = 0;
  local_res1a = 0;
  plVar5 = implatAllocateNonPagedPoolWithTagPriority((ulonglong)param_3 + 0x18,(ulong)param_2,0x10);
  if (plVar5 == (longlong *)0x0) {
    iVar10 = -0x3fffff66;
  }
  else {
    memcpy((_NDIS_PM_PROTOCOL_OFFLOAD *)(plVar5 + 3),param_2,(ulonglong)param_3);
    NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88),&local_res18,0);
    puVar9 = auStack_38;
    lVar6 = *(longlong *)(param_1 + 0x48) + 0x4a8;
    plVar7 = *(longlong **)(*(longlong *)(param_1 + 0x48) + 0x4b0);
    if (*plVar7 != lVar6) {
      plVar7 = (longlong *)0x3;
      pcVar3 = (code *)swi(0x29);
      lVar6 = (*pcVar3)();
      puVar9 = auStack_30;
    }
    *plVar5 = lVar6;
    plVar5[1] = (longlong)plVar7;
    *plVar7 = (longlong)plVar5;
    *(longlong **)(lVar6 + 8) = plVar5;
    uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88);
    *(undefined8 *)(puVar9 + -8) = 0x1c001085d;
    NdisReleaseRWLock(uVar1,puVar9 + 0x50);
    for (p_Var8 = *(_IMPLAT_VIRTMINI **)(param_1 + 0x60); p_Var8 != param_1 + 0x60;
        p_Var8 = *(_IMPLAT_VIRTMINI **)p_Var8) {
      if (*(int *)(p_Var8 + 0x40) != 0) {
        p_Var2 = *(_IMPLAT_ADAPTER **)(p_Var8 + -0x20);
        *(undefined8 *)(puVar9 + -8) = 0x1c001087d;
        iVar4 = implatAddPMOffloadOnAdapter(p_Var2,(_NDIS_PM_PROTOCOL_OFFLOAD *)(plVar5 + 3));
        if (iVar4 != 0) {
          iVar10 = iVar4;
        }
      }
    }
  }
  return iVar10;
}



===== implatAddPMOffloadOnAdapter @ 1c00108ac =====

/* int __cdecl implatAddPMOffloadOnAdapter(struct _IMPLAT_ADAPTER * __ptr64,struct
   _NDIS_PM_PROTOCOL_OFFLOAD * __ptr64) */

int __cdecl implatAddPMOffloadOnAdapter(_IMPLAT_ADAPTER *param_1,_NDIS_PM_PROTOCOL_OFFLOAD *param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  _IMPLAT_ADAPTER *p_Var7;
  undefined1 *puVar8;
  undefined2 local_res10;
  undefined1 local_res12;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  uVar1 = *(undefined4 *)(param_2 + 0x94);
  local_res10 = 0;
  local_res12 = 0;
  puVar5 = implatAllocateNonPagedPoolWithTagPriority(0x18,(ulong)param_2,0x10);
  if (puVar5 == (undefined8 *)0x0) {
    iVar4 = -0x3fffff66;
  }
  else {
    *(undefined4 *)((longlong)puVar5 + 0x14) = uVar1;
    *(undefined4 *)(param_2 + 0x94) = 0;
    iVar4 = implatDoOidRequestOnAdapter
                      (param_1,1,0xfd01010d,param_2,0xf0,(_NDIS_OID_REQUEST *)0x0,
                       (_IMPLAT_VIRTMINI *)0x0);
    if (iVar4 == 0) {
      *(undefined4 *)(puVar5 + 2) = *(undefined4 *)(param_2 + 0x94);
      NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res10,0);
      puVar8 = auStackY_58;
      p_Var7 = param_1 + 0x1ae0;
      plVar6 = *(longlong **)(param_1 + 0x1ae8);
      if ((_IMPLAT_ADAPTER *)*plVar6 != p_Var7) {
        p_Var7 = (_IMPLAT_ADAPTER *)0x3;
        pcVar3 = (code *)swi(0x29);
        plVar6 = (longlong *)(*pcVar3)();
        puVar8 = auStackY_50;
      }
      *puVar5 = p_Var7;
      puVar5[1] = plVar6;
      *plVar6 = (longlong)puVar5;
      *(undefined8 **)(p_Var7 + 8) = puVar5;
      uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88);
      *(undefined8 *)(puVar8 + -8) = 0x1c0010991;
      NdisReleaseRWLock(uVar2,puVar8 + 0x68);
    }
    else {
      ExFreePoolWithTag(puVar5,0x6c506d49);
    }
    *(undefined4 *)(param_2 + 0x94) = uVar1;
  }
  return iVar4;
}



===== implatAddWolPattern @ 1c00109d0 =====

/* int __cdecl implatAddWolPattern(struct _IMPLAT_VIRTMINI * __ptr64,unsigned char *
   __ptr64,unsigned long) */

int __cdecl implatAddWolPattern(_IMPLAT_VIRTMINI *param_1,uchar *param_2,ulong param_3)

{
  undefined8 uVar1;
  _IMPLAT_ADAPTER *p_Var2;
  code *pcVar3;
  int iVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong *plVar7;
  _IMPLAT_VIRTMINI *p_Var8;
  undefined1 *puVar9;
  int iVar10;
  undefined2 local_res18;
  undefined1 local_res1a;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  local_res18 = 0;
  iVar10 = 0;
  local_res1a = 0;
  plVar5 = implatAllocateNonPagedPoolWithTagPriority((ulonglong)param_3 + 0x1c,(ulong)param_2,0x10);
  if (plVar5 == (longlong *)0x0) {
    iVar10 = -0x3fffff66;
  }
  else {
    memcpy((_NDIS_PM_WOL_PATTERN *)(plVar5 + 3),param_2,(ulonglong)param_3);
    *(ulong *)(plVar5 + 2) = param_3;
    NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88),&local_res18,0);
    puVar9 = auStack_48;
    lVar6 = *(longlong *)(param_1 + 0x48) + 0x498;
    plVar7 = *(longlong **)(*(longlong *)(param_1 + 0x48) + 0x4a0);
    if (*plVar7 != lVar6) {
      plVar7 = (longlong *)0x3;
      pcVar3 = (code *)swi(0x29);
      lVar6 = (*pcVar3)();
      puVar9 = auStack_40;
    }
    *plVar5 = lVar6;
    plVar5[1] = (longlong)plVar7;
    *plVar7 = (longlong)plVar5;
    *(longlong **)(lVar6 + 8) = plVar5;
    uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88);
    *(undefined8 *)(puVar9 + -8) = 0x1c0010a8e;
    NdisReleaseRWLock(uVar1,puVar9 + 0x60);
    for (p_Var8 = *(_IMPLAT_VIRTMINI **)(param_1 + 0x60); p_Var8 != param_1 + 0x60;
        p_Var8 = *(_IMPLAT_VIRTMINI **)p_Var8) {
      if (*(int *)(p_Var8 + 0x40) != 0) {
        p_Var2 = *(_IMPLAT_ADAPTER **)(p_Var8 + -0x20);
        *(undefined8 *)(puVar9 + -8) = 0x1c0010ab1;
        iVar4 = implatAddWolPatternOnAdapter(p_Var2,(_NDIS_PM_WOL_PATTERN *)(plVar5 + 3),param_3);
        if (iVar4 != 0) {
          iVar10 = iVar4;
        }
      }
    }
  }
  return iVar10;
}



===== implatAddWolPatternOnAdapter @ 1c0010ae0 =====

/* int __cdecl implatAddWolPatternOnAdapter(struct _IMPLAT_ADAPTER * __ptr64,struct
   _NDIS_PM_WOL_PATTERN * __ptr64,unsigned long) */

int __cdecl
implatAddWolPatternOnAdapter(_IMPLAT_ADAPTER *param_1,_NDIS_PM_WOL_PATTERN *param_2,ulong param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  _IMPLAT_ADAPTER *p_Var7;
  undefined1 *puVar8;
  undefined2 local_res10;
  undefined1 local_res12;
  undefined1 auStackY_58 [8];
  undefined1 auStackY_50 [24];
  
  uVar1 = *(undefined4 *)(param_2 + 0x94);
  local_res10 = 0;
  local_res12 = 0;
  puVar5 = implatAllocateNonPagedPoolWithTagPriority(0x18,(ulong)param_2,0x10);
  if (puVar5 == (undefined8 *)0x0) {
    iVar4 = -0x3fffff66;
  }
  else {
    *(undefined4 *)((longlong)puVar5 + 0x14) = uVar1;
    *(undefined4 *)(param_2 + 0x94) = 0;
    iVar4 = implatDoOidRequestOnAdapter
                      (param_1,1,0xfd01010a,param_2,param_3,(_NDIS_OID_REQUEST *)0x0,
                       (_IMPLAT_VIRTMINI *)0x0);
    if (iVar4 == 0) {
      *(undefined4 *)(puVar5 + 2) = *(undefined4 *)(param_2 + 0x94);
      NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res10,0);
      puVar8 = auStackY_58;
      p_Var7 = param_1 + 0x1ad0;
      plVar6 = *(longlong **)(param_1 + 0x1ad8);
      if ((_IMPLAT_ADAPTER *)*plVar6 != p_Var7) {
        p_Var7 = (_IMPLAT_ADAPTER *)0x3;
        pcVar3 = (code *)swi(0x29);
        plVar6 = (longlong *)(*pcVar3)();
        puVar8 = auStackY_50;
      }
      *puVar5 = p_Var7;
      puVar5[1] = plVar6;
      *plVar6 = (longlong)puVar5;
      *(undefined8 **)(p_Var7 + 8) = puVar5;
      uVar2 = *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88);
      *(undefined8 *)(puVar8 + -8) = 0x1c0010bc4;
      NdisReleaseRWLock(uVar2,puVar8 + 0x68);
    }
    else {
      ExFreePoolWithTag(puVar5,0x6c506d49);
    }
    *(undefined4 *)(param_2 + 0x94) = uVar1;
  }
  return iVar4;
}



===== implatClearPMParamsOnAdapter @ 1c0010c04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl implatClearPMParamsOnAdapter(struct _IMPLAT_ADAPTER * __ptr64) */

void __cdecl implatClearPMParamsOnAdapter(_IMPLAT_ADAPTER *param_1)

{
  _IMPLAT_WOL_PATTERN_MAPPING *p_Var1;
  _IMPLAT_PM_OFFLOAD_MAPPING *p_Var2;
  _IMPLAT_WOL_PATTERN_MAPPING *p_Var3;
  longlong lVar4;
  _IMPLAT_PM_OFFLOAD_MAPPING *p_Var5;
  code *pcVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  undefined4 local_28;
  undefined5 uStack_24;
  undefined8 uStack_1f;
  undefined2 local_17;
  undefined1 local_15;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  local_17 = 0;
  local_15 = 0;
  uStack_24 = 0;
  uStack_1f = 0;
  local_28 = 0x140280;
  iVar7 = implatDoOidRequestOnAdapter
                    (param_1,1,0xfd010109,&local_28,0x14,(_NDIS_OID_REQUEST *)0x0,
                     (_IMPLAT_VIRTMINI *)0x0);
  if ((((iVar7 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_5e95b5ed910d35ca391433f1176714fe_Traceguids,param_1);
  }
  puVar8 = auStackY_68;
  p_Var1 = (_IMPLAT_WOL_PATTERN_MAPPING *)(param_1 + 0x1ad0);
  while (p_Var3 = *(_IMPLAT_WOL_PATTERN_MAPPING **)p_Var1, p_Var3 != p_Var1) {
    if ((*(_IMPLAT_WOL_PATTERN_MAPPING **)(p_Var3 + 8) != p_Var1) ||
       (lVar4 = *(longlong *)p_Var3, *(_IMPLAT_WOL_PATTERN_MAPPING **)(lVar4 + 8) != p_Var3))
    goto LAB_1c0010cfc;
    *(longlong *)p_Var1 = lVar4;
    *(_IMPLAT_WOL_PATTERN_MAPPING **)(lVar4 + 8) = p_Var1;
    implatRemoveWolPatternMapping(param_1,p_Var3);
  }
  p_Var2 = (_IMPLAT_PM_OFFLOAD_MAPPING *)(param_1 + 0x1ae0);
  while (p_Var5 = *(_IMPLAT_PM_OFFLOAD_MAPPING **)p_Var2, p_Var5 != p_Var2) {
    if ((*(_IMPLAT_PM_OFFLOAD_MAPPING **)(p_Var5 + 8) != p_Var2) ||
       (lVar4 = *(longlong *)p_Var5, *(_IMPLAT_PM_OFFLOAD_MAPPING **)(lVar4 + 8) != p_Var5))
    goto LAB_1c0010cfc;
    *(longlong *)p_Var2 = lVar4;
    *(_IMPLAT_PM_OFFLOAD_MAPPING **)(lVar4 + 8) = p_Var2;
    implatRemovePMOffloadMapping(param_1,p_Var5);
  }
LAB_1c0010d03:
  *(undefined8 *)(puVar8 + -8) = 0x1c0010d10;
  return;
LAB_1c0010cfc:
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  puVar8 = auStackY_60;
  goto LAB_1c0010d03;
}



===== implatIndicatePMRejection @ 1c0010d24 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl implatIndicatePMRejection(struct _IMPLAT_VIRTMINI * __ptr64,unsigned long,unsigned
   long) */

void __cdecl implatIndicatePMRejection(_IMPLAT_VIRTMINI *param_1,ulong param_2,ulong param_3)

{
  undefined1 auStack_c8 [32];
  ulong local_a8 [4];
  undefined4 local_98;
  undefined4 local_94;
  undefined8 local_90;
  ulong local_84;
  ulong *local_68;
  undefined4 local_60;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_c8;
  local_94 = 0;
  local_a8[0] = param_3;
  memset((void *)((longlong)&local_98 + 1),0,0x6f);
  local_90 = *(undefined8 *)(param_1 + 0x20);
  local_68 = local_a8;
  local_98 = 0x700198;
  local_60 = 4;
  local_84 = param_2;
  NdisMIndicateStatusEx(local_90,&local_98);
  return;
}



===== implatRecalculatePMCapabilities @ 1c0010db0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl implatRecalculatePMCapabilities(struct _IMPLAT_TEAM * __ptr64) */

void __cdecl implatRecalculatePMCapabilities(_IMPLAT_TEAM *param_1)

{
  _IMPLAT_TEAM *p_Var1;
  longlong lVar2;
  _IMPLAT_TEAM *p_Var3;
  undefined1 auStack_118 [32];
  uint local_f8;
  undefined4 uStack_f4;
  uint uStack_f0;
  uint uStack_ec;
  uint uStack_e8;
  uint uStack_e4;
  uint uStack_e0;
  uint uStack_dc;
  uint uStack_d8;
  uint uStack_d4;
  uint uStack_d0;
  uint uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined1 uStack_c0;
  undefined2 local_bf;
  undefined1 local_bd;
  _IMPLAT_TEAM *local_b8;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined4 local_94;
  _IMPLAT_TEAM *local_78;
  undefined4 local_70;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_118;
  uStack_c4 = 0;
  uStack_c0 = 0;
  local_bf = 0;
  local_bd = 0;
  local_a4 = 0;
  local_f8 = (uint)(byte)local_f8;
  uStack_f4 = 0;
  uStack_f0 = 0;
  uStack_ec = 0;
  uStack_e8 = 0;
  uStack_e4 = 0;
  uStack_e0 = 0;
  uStack_dc = 0;
  uStack_d8 = 0;
  uStack_d4 = 0;
  uStack_d0 = 0;
  uStack_cc = 0;
  uStack_c8 = 0;
  memset((void *)((longlong)&local_a8 + 1),0,0x6f);
  lVar2 = *(longlong *)(param_1 + 0x150);
  if ((lVar2 != 0) && (*(int *)(lVar2 + 0x440) == 0)) {
    local_b8 = param_1 + 0xf0;
    local_f8 = 0x3c0280;
    if (*(_IMPLAT_TEAM **)local_b8 != local_b8) {
      uStack_c8 = 0;
      uStack_d0 = 0;
      uStack_cc = 0;
      if (*(int *)(param_1 + 0x3f0) != 0) {
        uStack_f0 = uStack_f0 | 2;
        uStack_d0 = 5;
      }
      if (*(int *)(param_1 + 0x3d0) != 0) {
        uStack_f0 = uStack_f0 | 0x10a0d;
        uStack_ec = 0xffffffff;
        uStack_e8 = 0xffffffff;
        uStack_e4 = 0xffffffff;
        uStack_e0 = 0xffffffff;
        uStack_cc = 5;
      }
      if (*(int *)(param_1 + 0x410) != 0) {
        uStack_dc = uStack_dc | 1;
        uStack_d8 = 0xffffffff;
      }
      p_Var3 = *(_IMPLAT_TEAM **)local_b8 + -0x10;
      if (*(int *)(param_1 + 0x430) != 0) {
        uStack_dc = uStack_dc | 2;
        uStack_d4 = 0xffffffff;
      }
      do {
        uStack_f0 = uStack_f0 & *(uint *)(p_Var3 + 0x204);
        uStack_dc = uStack_dc & *(uint *)(p_Var3 + 0x218);
        if (*(uint *)(p_Var3 + 0x214) <= uStack_e0) {
          uStack_e0 = *(uint *)(p_Var3 + 0x214);
        }
        if (*(uint *)(p_Var3 + 0x210) <= uStack_e4) {
          uStack_e4 = *(uint *)(p_Var3 + 0x210);
        }
        if (*(uint *)(p_Var3 + 0x20c) <= uStack_e8) {
          uStack_e8 = *(uint *)(p_Var3 + 0x20c);
        }
        if ((int)*(uint *)(p_Var3 + 0x224) <= (int)uStack_d0) {
          uStack_d0 = *(uint *)(p_Var3 + 0x224);
        }
        if ((int)*(uint *)(p_Var3 + 0x228) <= (int)uStack_cc) {
          uStack_cc = *(uint *)(p_Var3 + 0x228);
        }
        if (*(uint *)(p_Var3 + 0x21c) <= uStack_d8) {
          uStack_d8 = *(uint *)(p_Var3 + 0x21c);
        }
        if (*(uint *)(p_Var3 + 0x220) <= uStack_d4) {
          uStack_d4 = *(uint *)(p_Var3 + 0x220);
        }
        if (*(uint *)(p_Var3 + 0x208) <= uStack_ec) {
          uStack_ec = *(uint *)(p_Var3 + 0x208);
        }
        p_Var1 = p_Var3 + 0x10;
        p_Var3 = *(_IMPLAT_TEAM **)p_Var1 + -0x10;
      } while (*(_IMPLAT_TEAM **)p_Var1 != local_b8);
      uStack_d0 = -(uint)((uStack_f0 & 2) != 0) & uStack_d0;
      uStack_cc = -(uint)((uStack_f0 & 1) != 0) & uStack_cc;
    }
    if ((((((*(uint *)(param_1 + 0x45c) != uStack_e0) || (*(uint *)(param_1 + 0x458) != uStack_e4))
          || (*(uint *)(param_1 + 0x454) != uStack_e8)) ||
         ((*(uint *)(param_1 + 0x46c) != uStack_d0 || (*(uint *)(param_1 + 0x470) != uStack_cc))))
        || ((*(uint *)(param_1 + 0x464) != uStack_d8 ||
            ((*(uint *)(param_1 + 0x468) != uStack_d4 || (*(uint *)(param_1 + 0x450) != uStack_ec)))
            ))) ||
       ((*(uint *)(param_1 + 0x460) != uStack_dc || (*(uint *)(param_1 + 0x44c) != uStack_f0)))) {
      param_1[0x440] = (_IMPLAT_TEAM)0x0;
      *(ulonglong *)(param_1 + 0x444) = CONCAT44(uStack_f4,0x3c0280);
      *(ulonglong *)(param_1 + 0x44c) = CONCAT44(uStack_ec,uStack_f0);
      *(ulonglong *)(param_1 + 0x454) = CONCAT44(uStack_e4,uStack_e8);
      *(ulonglong *)(param_1 + 0x45c) = CONCAT44(uStack_dc,uStack_e0);
      *(uint *)(param_1 + 0x464) = uStack_d8;
      *(uint *)(param_1 + 0x468) = uStack_d4;
      *(uint *)(param_1 + 0x46c) = uStack_d0;
      *(uint *)(param_1 + 0x470) = uStack_cc;
      *(ulonglong *)(param_1 + 0x474) = CONCAT44(uStack_c4,uStack_c8);
      *(uint *)(param_1 + 0x47c) = CONCAT13(local_bd,CONCAT21(local_bf,uStack_c0));
    }
    local_78 = param_1 + 0x444;
    if ((param_1[0x440] == (_IMPLAT_TEAM)0x0) && (2 < *(int *)(lVar2 + 200))) {
      local_a8 = 0x700198;
      local_a0 = *(undefined8 *)(lVar2 + 0x20);
      local_94 = 0x40030054;
      local_70 = 0x3c;
      param_1[0x440] = (_IMPLAT_TEAM)0x1;
      NdisMIndicateStatusEx(*(undefined8 *)(lVar2 + 0x20),&local_a8);
    }
  }
  return;
}



===== implatRejectPMOffload @ 1c00110ec =====

/* void __cdecl implatRejectPMOffload(struct _IMPLAT_ADAPTER * __ptr64,unsigned long) */

void __cdecl implatRejectPMOffload(_IMPLAT_ADAPTER *param_1,ulong param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 *puVar4;
  _IMPLAT_ADAPTER *p_Var5;
  ulong uVar6;
  longlong *plVar7;
  longlong *plVar8;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res8,0);
  for (p_Var5 = *(_IMPLAT_ADAPTER **)(param_1 + 0x1ae0); p_Var5 != param_1 + 0x1ae0;
      p_Var5 = *(_IMPLAT_ADAPTER **)p_Var5) {
    if (*(ulong *)(p_Var5 + 0x10) == param_2) {
      plVar7 = (longlong *)(*(longlong *)(param_1 + 0x28) + 0x4a8);
      plVar8 = (longlong *)*plVar7;
      if (plVar8 == plVar7) goto LAB_1c00111a1;
      goto LAB_1c0011190;
    }
  }
  goto LAB_1c0011147;
  while (plVar8 = (longlong *)*plVar8, plVar8 != plVar7) {
LAB_1c0011190:
    if (*(int *)((longlong)plVar8 + 0xac) == *(int *)(p_Var5 + 0x14)) goto LAB_1c00111a3;
  }
LAB_1c00111a1:
  plVar8 = (longlong *)0x0;
LAB_1c00111a3:
  lVar3 = *(longlong *)p_Var5;
  uVar1 = *(undefined4 *)(p_Var5 + 0x14);
  if ((*(_IMPLAT_ADAPTER **)(lVar3 + 8) != p_Var5) ||
     (plVar7 = *(longlong **)(p_Var5 + 8), (_IMPLAT_ADAPTER *)*plVar7 != p_Var5)) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(3);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  *plVar7 = lVar3;
  *(longlong **)(lVar3 + 8) = plVar7;
  uVar6 = 0x6c506d49;
  ExFreePoolWithTag();
  if ((plVar8 != (longlong *)0x0) && ((char)plVar8[2] == '\0')) {
    lVar3 = NdisAllocateIoWorkItem(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x150));
    if (lVar3 != 0) {
      puVar4 = implatAllocateNonPagedPoolWithTagPriority(0x10,uVar6,0x10);
      if (puVar4 == (undefined8 *)0x0) {
        NdisFreeIoWorkItem(lVar3);
      }
      else {
        *(undefined1 *)(plVar8 + 2) = 1;
        *(undefined4 *)(puVar4 + 1) = uVar1;
        *puVar4 = *(undefined8 *)(param_1 + 0x28);
        NdisQueueIoWorkItem(lVar3,implatRejectPMOffloadWorkItem,puVar4);
      }
    }
  }
LAB_1c0011147:
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res8);
  return;
}



===== implatRejectPMOffloadWorkItem @ 1c0011270 =====

/* void __cdecl implatRejectPMOffloadWorkItem(void * __ptr64,void * __ptr64) */

void __cdecl implatRejectPMOffloadWorkItem(void *param_1,void *param_2)

{
  ulong *puVar1;
  longlong *plVar2;
  bool bVar3;
  longlong *plVar4;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  bVar3 = false;
  implatIncreaseGlobalPendingOperationsCount();
  NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)param_1 + 0x88),&local_res8,0);
  puVar1 = (ulong *)((longlong)param_1 + 8);
  plVar2 = (longlong *)(*(longlong *)param_1 + 0x4a8);
  plVar4 = (longlong *)*plVar2;
  if (plVar4 != plVar2) {
    do {
      if (*(ulong *)((longlong)plVar4 + 0xac) == *puVar1) {
        if (plVar4 != (longlong *)0x0) {
          bVar3 = false;
          if ((char)plVar4[2] != '\0') {
            bVar3 = true;
          }
        }
        break;
      }
      plVar4 = (longlong *)*plVar4;
    } while (plVar4 != plVar2);
  }
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)param_1 + 0x88),&local_res8);
  if (bVar3) {
    implatRemovePMOffload(*(_IMPLAT_VIRTMINI **)(*(longlong *)param_1 + 0x150),(uchar *)puVar1,4);
    implatIndicatePMRejection
              (*(_IMPLAT_VIRTMINI **)(*(longlong *)param_1 + 0x150),0x40030052,*puVar1);
  }
  ExFreePoolWithTag(param_1,0x6c506d49);
  NdisFreeIoWorkItem(param_2);
  implatDecreaseGlobalPendingOperationsCount();
  return;
}



===== implatRejectWolPattern @ 1c0011388 =====

/* void __cdecl implatRejectWolPattern(struct _IMPLAT_ADAPTER * __ptr64,unsigned long) */

void __cdecl implatRejectWolPattern(_IMPLAT_ADAPTER *param_1,ulong param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  longlong lVar3;
  undefined8 *puVar4;
  _IMPLAT_ADAPTER *p_Var5;
  ulong uVar6;
  longlong *plVar7;
  longlong *plVar8;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res8,0);
  for (p_Var5 = *(_IMPLAT_ADAPTER **)(param_1 + 0x1ad0); p_Var5 != param_1 + 0x1ad0;
      p_Var5 = *(_IMPLAT_ADAPTER **)p_Var5) {
    if (*(ulong *)(p_Var5 + 0x10) == param_2) {
      plVar7 = (longlong *)(*(longlong *)(param_1 + 0x28) + 0x498);
      plVar8 = (longlong *)*plVar7;
      if (plVar8 == plVar7) goto LAB_1c001143d;
      goto LAB_1c001142c;
    }
  }
  goto LAB_1c00113e3;
  while (plVar8 = (longlong *)*plVar8, plVar8 != plVar7) {
LAB_1c001142c:
    if (*(int *)((longlong)plVar8 + 0xac) == *(int *)(p_Var5 + 0x14)) goto LAB_1c001143f;
  }
LAB_1c001143d:
  plVar8 = (longlong *)0x0;
LAB_1c001143f:
  lVar3 = *(longlong *)p_Var5;
  uVar1 = *(undefined4 *)(p_Var5 + 0x14);
  if ((*(_IMPLAT_ADAPTER **)(lVar3 + 8) != p_Var5) ||
     (plVar7 = *(longlong **)(p_Var5 + 8), (_IMPLAT_ADAPTER *)*plVar7 != p_Var5)) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(3);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  *plVar7 = lVar3;
  *(longlong **)(lVar3 + 8) = plVar7;
  uVar6 = 0x6c506d49;
  ExFreePoolWithTag();
  if ((plVar8 != (longlong *)0x0) && (*(char *)((longlong)plVar8 + 0x14) == '\0')) {
    lVar3 = NdisAllocateIoWorkItem(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x150));
    if (lVar3 != 0) {
      puVar4 = implatAllocateNonPagedPoolWithTagPriority(0x10,uVar6,0x10);
      if (puVar4 == (undefined8 *)0x0) {
        NdisFreeIoWorkItem(lVar3);
      }
      else {
        *(undefined1 *)((longlong)plVar8 + 0x14) = 1;
        *(undefined4 *)(puVar4 + 1) = uVar1;
        *puVar4 = *(undefined8 *)(param_1 + 0x28);
        NdisQueueIoWorkItem(lVar3,implatRejectWolPatternWorkItem,puVar4);
      }
    }
  }
LAB_1c00113e3:
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res8);
  return;
}



===== implatRejectWolPatternWorkItem @ 1c0011510 =====

/* void __cdecl implatRejectWolPatternWorkItem(void * __ptr64,void * __ptr64) */

void __cdecl implatRejectWolPatternWorkItem(void *param_1,void *param_2)

{
  ulong *puVar1;
  longlong *plVar2;
  bool bVar3;
  longlong *plVar4;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  bVar3 = false;
  implatIncreaseGlobalPendingOperationsCount();
  NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)param_1 + 0x88),&local_res8,0);
  puVar1 = (ulong *)((longlong)param_1 + 8);
  plVar2 = (longlong *)(*(longlong *)param_1 + 0x498);
  plVar4 = (longlong *)*plVar2;
  if (plVar4 != plVar2) {
    do {
      if (*(ulong *)((longlong)plVar4 + 0xac) == *puVar1) {
        if (plVar4 != (longlong *)0x0) {
          bVar3 = false;
          if (*(char *)((longlong)plVar4 + 0x14) != '\0') {
            bVar3 = true;
          }
        }
        break;
      }
      plVar4 = (longlong *)*plVar4;
    } while (plVar4 != plVar2);
  }
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)param_1 + 0x88),&local_res8);
  if (bVar3) {
    implatRemoveWolPattern(*(_IMPLAT_VIRTMINI **)(*(longlong *)param_1 + 0x150),(uchar *)puVar1,4);
    implatIndicatePMRejection
              (*(_IMPLAT_VIRTMINI **)(*(longlong *)param_1 + 0x150),0x40030051,*puVar1);
  }
  ExFreePoolWithTag(param_1,0x6c506d49);
  NdisFreeIoWorkItem(param_2);
  implatDecreaseGlobalPendingOperationsCount();
  return;
}



===== implatRemovePMOffload @ 1c0011630 =====

/* int __cdecl implatRemovePMOffload(struct _IMPLAT_VIRTMINI * __ptr64,unsigned char *
   __ptr64,unsigned long) */

int __cdecl implatRemovePMOffload(_IMPLAT_VIRTMINI *param_1,uchar *param_2,ulong param_3)

{
  _IMPLAT_ADAPTER *p_Var1;
  longlong lVar2;
  _IMPLAT_ADAPTER *p_Var3;
  _IMPLAT_PM_OFFLOAD_MAPPING *p_Var4;
  code *pcVar5;
  _IMPLAT_PM_OFFLOAD_MAPPING *p_Var6;
  int iVar7;
  longlong *plVar8;
  _IMPLAT_VIRTMINI *p_Var9;
  longlong *plVar10;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined2 local_res10;
  undefined1 local_res12;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88),&local_res8,0);
  plVar10 = (longlong *)(*(longlong *)(param_1 + 0x48) + 0x4a8);
  plVar8 = (longlong *)*plVar10;
  if (plVar8 != plVar10) {
    do {
      if (*(int *)((longlong)plVar8 + 0xac) == *(int *)param_2) {
        if (plVar8 != (longlong *)0x0) {
          lVar2 = *plVar8;
          if ((*(longlong **)(lVar2 + 8) != plVar8) ||
             (plVar10 = (longlong *)plVar8[1], (longlong *)*plVar10 != plVar8)) goto LAB_1c00117c4;
          *plVar10 = lVar2;
          *(longlong **)(lVar2 + 8) = plVar10;
          ExFreePoolWithTag(plVar8,0x6c506d49);
        }
        break;
      }
      plVar8 = (longlong *)*plVar8;
    } while (plVar8 != plVar10);
  }
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88),&local_res8);
  p_Var9 = *(_IMPLAT_VIRTMINI **)(param_1 + 0x60);
  do {
    if (p_Var9 == param_1 + 0x60) {
      return 0;
    }
    if (*(int *)(p_Var9 + 0x40) != 0) {
      p_Var3 = *(_IMPLAT_ADAPTER **)(p_Var9 + -0x20);
      iVar7 = *(int *)param_2;
      local_res10 = 0;
      local_res12 = 0;
      NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(p_Var3 + 0x28) + 0x88),&local_res10,0);
      p_Var1 = p_Var3 + 0x1ae0;
      p_Var4 = *(_IMPLAT_PM_OFFLOAD_MAPPING **)p_Var1;
      do {
        p_Var6 = p_Var4;
        if (p_Var6 == (_IMPLAT_PM_OFFLOAD_MAPPING *)p_Var1) goto LAB_1c0011772;
        p_Var4 = *(_IMPLAT_PM_OFFLOAD_MAPPING **)p_Var6;
      } while (*(int *)(p_Var6 + 0x14) != iVar7);
      if ((*(_IMPLAT_PM_OFFLOAD_MAPPING **)(p_Var4 + 8) != p_Var6) ||
         (plVar8 = *(longlong **)(p_Var6 + 8), (_IMPLAT_PM_OFFLOAD_MAPPING *)*plVar8 != p_Var6)) {
LAB_1c00117c4:
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        pcVar5 = (code *)swi(3);
        iVar7 = (*pcVar5)();
        return iVar7;
      }
      *plVar8 = (longlong)p_Var4;
      *(longlong **)(p_Var4 + 8) = plVar8;
LAB_1c0011772:
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(p_Var3 + 0x28) + 0x88),&local_res10);
      if (p_Var6 != (_IMPLAT_PM_OFFLOAD_MAPPING *)p_Var1) {
        implatRemovePMOffloadMapping(p_Var3,p_Var6);
      }
    }
    p_Var9 = *(_IMPLAT_VIRTMINI **)p_Var9;
  } while( true );
}



===== implatRemovePMOffloadMapping @ 1c00117d4 =====

/* int __cdecl implatRemovePMOffloadMapping(struct _IMPLAT_ADAPTER * __ptr64,struct
   _IMPLAT_PM_OFFLOAD_MAPPING * __ptr64) */

int __cdecl
implatRemovePMOffloadMapping(_IMPLAT_ADAPTER *param_1,_IMPLAT_PM_OFFLOAD_MAPPING *param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_2 + 0x14) = 0;
  iVar1 = implatDoOidRequestOnAdapter
                    (param_1,1,0xfd01010f,param_2 + 0x10,4,(_NDIS_OID_REQUEST *)0x0,
                     (_IMPLAT_VIRTMINI *)0x0);
  ExFreePoolWithTag(param_2,0x6c506d49);
  return iVar1;
}



===== implatRemoveWolPattern @ 1c0011840 =====

/* int __cdecl implatRemoveWolPattern(struct _IMPLAT_VIRTMINI * __ptr64,unsigned char *
   __ptr64,unsigned long) */

int __cdecl implatRemoveWolPattern(_IMPLAT_VIRTMINI *param_1,uchar *param_2,ulong param_3)

{
  _IMPLAT_ADAPTER *p_Var1;
  longlong lVar2;
  _IMPLAT_ADAPTER *p_Var3;
  _IMPLAT_WOL_PATTERN_MAPPING *p_Var4;
  code *pcVar5;
  _IMPLAT_WOL_PATTERN_MAPPING *p_Var6;
  int iVar7;
  longlong *plVar8;
  _IMPLAT_VIRTMINI *p_Var9;
  longlong *plVar10;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined2 local_res10;
  undefined1 local_res12;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88),&local_res8,0);
  plVar10 = (longlong *)(*(longlong *)(param_1 + 0x48) + 0x498);
  plVar8 = (longlong *)*plVar10;
  if (plVar8 != plVar10) {
    do {
      if (*(int *)((longlong)plVar8 + 0xac) == *(int *)param_2) {
        if (plVar8 != (longlong *)0x0) {
          lVar2 = *plVar8;
          if ((*(longlong **)(lVar2 + 8) != plVar8) ||
             (plVar10 = (longlong *)plVar8[1], (longlong *)*plVar10 != plVar8)) goto LAB_1c00119d4;
          *plVar10 = lVar2;
          *(longlong **)(lVar2 + 8) = plVar10;
          ExFreePoolWithTag(plVar8,0x6c506d49);
        }
        break;
      }
      plVar8 = (longlong *)*plVar8;
    } while (plVar8 != plVar10);
  }
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88),&local_res8);
  p_Var9 = *(_IMPLAT_VIRTMINI **)(param_1 + 0x60);
  do {
    if (p_Var9 == param_1 + 0x60) {
      return 0;
    }
    if (*(int *)(p_Var9 + 0x40) != 0) {
      p_Var3 = *(_IMPLAT_ADAPTER **)(p_Var9 + -0x20);
      iVar7 = *(int *)param_2;
      local_res10 = 0;
      local_res12 = 0;
      NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(p_Var3 + 0x28) + 0x88),&local_res10,0);
      p_Var1 = p_Var3 + 0x1ad0;
      p_Var4 = *(_IMPLAT_WOL_PATTERN_MAPPING **)p_Var1;
      do {
        p_Var6 = p_Var4;
        if (p_Var6 == (_IMPLAT_WOL_PATTERN_MAPPING *)p_Var1) goto LAB_1c0011982;
        p_Var4 = *(_IMPLAT_WOL_PATTERN_MAPPING **)p_Var6;
      } while (*(int *)(p_Var6 + 0x14) != iVar7);
      if ((*(_IMPLAT_WOL_PATTERN_MAPPING **)(p_Var4 + 8) != p_Var6) ||
         (plVar8 = *(longlong **)(p_Var6 + 8), (_IMPLAT_WOL_PATTERN_MAPPING *)*plVar8 != p_Var6)) {
LAB_1c00119d4:
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        pcVar5 = (code *)swi(3);
        iVar7 = (*pcVar5)();
        return iVar7;
      }
      *plVar8 = (longlong)p_Var4;
      *(longlong **)(p_Var4 + 8) = plVar8;
LAB_1c0011982:
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(p_Var3 + 0x28) + 0x88),&local_res10);
      if (p_Var6 != (_IMPLAT_WOL_PATTERN_MAPPING *)p_Var1) {
        implatRemoveWolPatternMapping(p_Var3,p_Var6);
      }
    }
    p_Var9 = *(_IMPLAT_VIRTMINI **)p_Var9;
  } while( true );
}



===== implatRemoveWolPatternMapping @ 1c00119e4 =====

/* int __cdecl implatRemoveWolPatternMapping(struct _IMPLAT_ADAPTER * __ptr64,struct
   _IMPLAT_WOL_PATTERN_MAPPING * __ptr64) */

int __cdecl
implatRemoveWolPatternMapping(_IMPLAT_ADAPTER *param_1,_IMPLAT_WOL_PATTERN_MAPPING *param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_2 + 0x14) = 0;
  iVar1 = implatDoOidRequestOnAdapter
                    (param_1,1,0xfd01010b,param_2 + 0x10,4,(_NDIS_OID_REQUEST *)0x0,
                     (_IMPLAT_VIRTMINI *)0x0);
  ExFreePoolWithTag(param_2,0x6c506d49);
  return iVar1;
}



===== implatSetAdapterPMCaps @ 1c0011a44 =====

/* void __cdecl implatSetAdapterPMCaps(struct _IMPLAT_ADAPTER * __ptr64,struct _NDIS_PM_CAPABILITIES
   * __ptr64) */

void __cdecl implatSetAdapterPMCaps(_IMPLAT_ADAPTER *param_1,_NDIS_PM_CAPABILITIES *param_2)

{
  uint uVar1;
  undefined2 local_res8;
  undefined1 local_resa;
  
  local_res8 = 0;
  local_resa = 0;
  NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res8,0);
  if ((param_2 != (_NDIS_PM_CAPABILITIES *)0x0) && (*param_2 == (_NDIS_PM_CAPABILITIES)0x80)) {
    uVar1 = 0x3c;
    if (*(ushort *)(param_2 + 2) < 0x3c) {
      uVar1 = (uint)*(ushort *)(param_2 + 2);
    }
    memcpy(param_1 + 0x1fc,param_2,(ulonglong)uVar1);
    *(short *)(param_1 + 0x1fe) = (short)uVar1;
    implatRecalculatePMCapabilities(*(_IMPLAT_TEAM **)(param_1 + 0x28));
  }
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res8);
  return;
}



===== implatSetPMParams @ 1c0011b00 =====

/* int __cdecl implatSetPMParams(struct _IMPLAT_VIRTMINI * __ptr64,unsigned char * __ptr64,unsigned
   long) */

int __cdecl implatSetPMParams(_IMPLAT_VIRTMINI *param_1,uchar *param_2,ulong param_3)

{
  ushort uVar1;
  int iVar2;
  _IMPLAT_VIRTMINI *p_Var3;
  int iVar4;
  uint uVar5;
  
  iVar4 = 0;
  uVar1 = *(ushort *)(param_2 + 2);
  uVar5 = 0x14;
  if (uVar1 < 0x15) {
    uVar5 = (uint)uVar1;
  }
  if ((uVar5 <= param_3) && (param_3 = 0x14, uVar1 < 0x15)) {
    param_3 = (uint)uVar1;
  }
  memcpy((void *)(*(longlong *)(param_1 + 0x48) + 0x480),param_2,(ulonglong)param_3);
  *(short *)(*(longlong *)(param_1 + 0x48) + 0x482) = (short)param_3;
  for (p_Var3 = *(_IMPLAT_VIRTMINI **)(param_1 + 0x60); p_Var3 != param_1 + 0x60;
      p_Var3 = *(_IMPLAT_VIRTMINI **)p_Var3) {
    if (*(int *)(p_Var3 + 0x40) != 0) {
      iVar2 = implatDoOidRequestOnAdapter
                        (*(_IMPLAT_ADAPTER **)(p_Var3 + -0x20),1,0xfd010109,
                         (void *)(*(longlong *)(param_1 + 0x48) + 0x480),0x14,
                         (_NDIS_OID_REQUEST *)0x0,(_IMPLAT_VIRTMINI *)0x0);
      if (iVar2 != 0) {
        iVar4 = iVar2;
      }
    }
  }
  return iVar4;
}



===== implatVerifyPMOidParamsAndCallHandler @ 1c0011bd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* int __cdecl implatVerifyPMOidParamsAndCallHandler(struct _IMPLAT_VIRTMINI * __ptr64,struct
   _NDIS_OID_REQUEST * __ptr64,unsigned char,unsigned short,unsigned char,int (__cdecl*)(struct
   _IMPLAT_VIRTMINI * __ptr64,unsigned char * __ptr64,unsigned long)) */

int __cdecl
implatVerifyPMOidParamsAndCallHandler
          (_IMPLAT_VIRTMINI *param_1,_NDIS_OID_REQUEST *param_2,uchar param_3,ushort param_4,
          uchar param_5,_func_int__IMPLAT_VIRTMINI_ptr_uchar_ptr_ulong *param_6)

{
  uchar *puVar1;
  int iVar2;
  
  puVar1 = *(uchar **)(param_2 + 0x28);
  if ((puVar1 == (uchar *)0x0) || (*(uint *)(param_2 + 0x30) < (uint)param_4)) {
    *(undefined4 *)(param_2 + 0x34) = 0;
    *(uint *)(param_2 + 0x38) = (uint)param_4;
    iVar2 = -0x3ffeffea;
  }
  else if ((param_3 == '\0') || ((param_5 <= puVar1[1] && (param_4 <= *(ushort *)(puVar1 + 2))))) {
    *(uint *)(param_2 + 0x34) = (uint)param_4;
    implatIncreaseGlobalPendingOperationsCount();
    iVar2 = (*param_6)(param_1,puVar1,*(ulong *)(param_2 + 0x30));
    implatDecreaseGlobalPendingOperationsCount();
  }
  else {
    *(undefined4 *)(param_2 + 0x34) = 4;
    iVar2 = -0x3fffff45;
  }
  return iVar2;
}



===== RtlStringCbPrintfW @ 1c0011c6c =====

/* long __cdecl RtlStringCbPrintfW(unsigned short * __ptr64,unsigned __int64,unsigned short const *
   __ptr64,...) */

long __cdecl RtlStringCbPrintfW(ushort *param_1,__uint64 param_2,ushort *param_3,...)

{
  int iVar1;
  ulonglong uVar2;
  long lVar3;
  undefined8 in_R9;
  undefined8 local_res20;
  
  uVar2 = param_2 >> 1;
  if (uVar2 - 1 < 0x7fffffff) {
    uVar2 = uVar2 - 1;
    lVar3 = 0;
    local_res20 = in_R9;
    iVar1 = _vsnwprintf((wchar_t *)param_1,uVar2,(wchar_t *)param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (uVar2 < (ulonglong)(longlong)iVar1)) {
      lVar3 = -0x7ffffffb;
    }
    else if ((longlong)iVar1 != uVar2) {
      return 0;
    }
    param_1[uVar2] = 0;
  }
  else {
    lVar3 = -0x3ffffff3;
    if (uVar2 != 0) {
      *param_1 = 0;
    }
  }
  return lVar3;
}



===== SysEventWriteStrStatus @ 1c0011ce8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl SysEventWriteStrStatus(int,unsigned short * __ptr64,int) */

void __cdecl SysEventWriteStrStatus(int param_1,ushort *param_2,int param_3)

{
  long lVar1;
  longlong lVar2;
  undefined1 auStack_78 [32];
  ushort **local_58;
  undefined4 local_50;
  undefined8 local_48;
  ushort *local_38;
  ushort *local_30;
  ushort local_28 [12];
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  lVar1 = RtlStringCbPrintfW(local_28,0x18,(ushort *)L"0x%x",(ulonglong)(uint)param_3);
  if (-1 < lVar1) {
    local_30 = local_28;
    lVar2 = DAT_1c001b1e8;
    if (_Global != 0) {
      lVar2 = _Global;
    }
    local_48 = 0;
    local_50 = 0;
    local_58 = &local_38;
    local_38 = param_2;
    NdisWriteEventLogEntry(lVar2,param_1,0,2);
  }
  return;
}



===== SysEventWriteStrStrStatus @ 1c0011d98 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl SysEventWriteStrStrStatus(int,unsigned short * __ptr64,unsigned short * __ptr64,int)
    */

void __cdecl SysEventWriteStrStrStatus(int param_1,ushort *param_2,ushort *param_3,int param_4)

{
  long lVar1;
  longlong lVar2;
  undefined4 in_register_0000008c;
  undefined1 auStack_88 [32];
  ushort **local_68;
  undefined4 local_60;
  undefined8 local_58;
  ushort *local_48;
  ushort *local_40;
  ushort *local_38;
  ushort local_30 [12];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  lVar1 = RtlStringCbPrintfW(local_30,0x18,(ushort *)L"0x%x",CONCAT44(in_register_0000008c,param_4))
  ;
  if (-1 < lVar1) {
    local_38 = local_30;
    lVar2 = DAT_1c001b1e8;
    if (_Global != 0) {
      lVar2 = _Global;
    }
    local_58 = 0;
    local_60 = 0;
    local_68 = &local_48;
    local_48 = param_2;
    local_40 = param_3;
    NdisWriteEventLogEntry(lVar2,param_1,0,3);
  }
  return;
}



===== implatEtwWritePerNblEvent @ 1c0011e5c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl implatEtwWritePerNblEvent(enum _IMPLAT_ETW_NBL_EVENT_TYPE,struct _NET_BUFFER_LIST *
   __ptr64,void * __ptr64,void * __ptr64) */

void __cdecl
implatEtwWritePerNblEvent
          (_IMPLAT_ETW_NBL_EVENT_TYPE param_1,_NET_BUFFER_LIST *param_2,void *param_3,void *param_4)

{
  _NET_BUFFER_LIST *p_Var1;
  uint uVar2;
  ulonglong uVar3;
  _NET_BUFFER_LIST *p_Var4;
  undefined1 auStack_58 [32];
  ulonglong local_38 [4];
  
  if (param_2 != (_NET_BUFFER_LIST *)0x0) {
    local_38[2] = __security_cookie ^ (ulonglong)auStack_58;
    p_Var1 = param_2 + 0xf8;
    p_Var4 = param_2;
    do {
      local_38[1] = 0;
      local_38[0] = *(ulonglong *)p_Var1 & 0x7fffffffffffffff;
      if (param_1 == 0) {
        if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 8) != 0) {
          param_2 = (_NET_BUFFER_LIST *)&SendFailedNoTNicWarn;
          uVar3 = 0;
          goto LAB_1c0011f37;
        }
      }
      else if (param_1 == 1) {
        if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 8) != 0) {
          McTemplateK0_EtwWriteTransfer(0,param_2,local_38);
        }
      }
      else if (param_1 == 2) {
        if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 8) != 0) {
          param_2 = (_NET_BUFFER_LIST *)&SendAbortedOnTeamNicWarn;
          uVar3 = 0;
          goto LAB_1c0011f37;
        }
      }
      else if (param_1 == 3) {
        if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 8) != 0) {
          param_2 = (_NET_BUFFER_LIST *)&FailedReceiveMemberNotReadyWarn;
          uVar3 = 0;
          goto LAB_1c0011f37;
        }
      }
      else {
        uVar2 = param_1 - 4;
        uVar3 = (ulonglong)uVar2;
        if (uVar2 == 0) {
          if ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 8) != 0) {
            param_2 = (_NET_BUFFER_LIST *)&FailedReceiveTeamNicNotReadyWarn;
            goto LAB_1c0011f37;
          }
        }
        else if ((uVar2 == 1) &&
                ((Microsoft_Windows_NdisImPlatformEventProviderEnableBits & 8) != 0)) {
          param_2 = (_NET_BUFFER_LIST *)&FailedReceiveNoTNicForMemberWarn;
LAB_1c0011f37:
          McTemplateK0z_EtwWriteTransfer(uVar3,param_2,local_38,param_3);
        }
      }
      p_Var4 = *(_NET_BUFFER_LIST **)p_Var4;
    } while (p_Var4 != (_NET_BUFFER_LIST *)0x0);
  }
  return;
}



===== McTemplateK0_EtwWriteTransfer @ 1c0011f74 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer(param_1,&SendFailedNoMemberWarn,param_3,1,local_28);
  return;
}



===== IPsecLbfoAdapterSaAddComplete @ 1c0011fbc =====

void IPsecLbfoAdapterSaAddComplete(longlong param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  undefined2 local_res18;
  undefined1 local_res1a;
  
  plVar3 = *(longlong **)(param_2 + 0xd8);
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x438);
  lVar5 = (ulonglong)*(uint *)(plVar3 + 2) * 0x610 + *(longlong *)(lVar4 + 0x18);
  if ((int)param_3 == 0) {
    *(undefined8 *)(lVar5 + ((ulonglong)*(uint *)((longlong)plVar3 + 0x14) + 1) * 0x18) =
         *(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x30);
  }
  else {
    *(int *)(lVar5 + 0x20 + (ulonglong)*(uint *)((longlong)plVar3 + 0x14) * 0x18) = (int)param_3;
    LOCK();
    *(int *)(lVar5 + 8) = *(int *)(lVar5 + 8) + 1;
    UNLOCK();
  }
  LOCK();
  piVar1 = (int *)(lVar5 + 4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    local_res18 = 0;
    local_res1a = 0;
    if (*(int *)(lVar5 + 8) == 0) {
      *(ulonglong *)(*(longlong *)(plVar3[1] + 0x28) + 0x30) = (ulonglong)((int)plVar3[2] + 1);
    }
    else {
      param_3 = 0xc000009a;
    }
    NdisMDirectOidRequestComplete(*(undefined8 *)(*plVar3 + 0x20),plVar3[1],param_3);
    NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res18,0);
    piVar1 = (int *)(lVar4 + 0x20);
    *piVar1 = *piVar1 + -1;
    NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res18);
  }
  ExFreePoolWithTag(plVar3,0);
  NdisFreeCloneOidRequest(*(undefined8 *)(param_1 + 0x20),param_2);
  return;
}



===== IPsecLbfoAdapterSaDeleteComplete @ 1c00120f0 =====

void IPsecLbfoAdapterSaDeleteComplete(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined2 *puVar6;
  longlong lVar7;
  undefined2 local_res8;
  undefined1 local_resa;
  longlong local_res10 [2];
  longlong local_res20;
  
  plVar4 = *(longlong **)(param_2 + 0xd8);
  lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x438);
  lVar7 = (ulonglong)*(uint *)(plVar4 + 2) * 0x610 + *(longlong *)(lVar5 + 0x18);
  IPsecLbfopReturnUploadOid
            (param_2,(longlong *)
                     (lVar5 + 0x28 + (ulonglong)*(uint *)((longlong)plVar4 + 0x14) * 0x38));
  *(undefined8 *)(lVar7 + ((ulonglong)*(uint *)((longlong)plVar4 + 0x14) + 1) * 0x18) = 0;
  LOCK();
  piVar1 = (int *)(lVar7 + 4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    local_res10[0] = 0;
    local_res20 = 0;
    local_res8 = 0;
    local_resa = 0;
    NdisMDirectOidRequestComplete(*(undefined8 *)(*plVar4 + 0x20),plVar4[1],0);
    NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res8,0);
    uVar3 = *(uint *)(plVar4 + 2);
    lVar5 = *(longlong *)(*(longlong *)(*plVar4 + 0x48) + 0x438);
    puVar6 = (undefined2 *)((ulonglong)uVar3 * 0x610 + *(longlong *)(lVar5 + 0x18));
    *puVar6 = 0;
    *(undefined4 *)(puVar6 + 6) = *(undefined4 *)(lVar5 + 0xc);
    *(int *)(lVar5 + 8) = *(int *)(lVar5 + 8) + -1;
    *(uint *)(lVar5 + 0xc) = uVar3;
    IPsecLbfopCheckForQueuedUploadRequest(*(longlong *)(param_1 + 0x28),local_res10,&local_res20);
    NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x88),&local_res8);
    if (local_res10[0] != 0) {
      IPsecLbfopProcessQueuedUploadRequest(local_res20,local_res10[0]);
    }
  }
  return;
}



===== IPsecLbfoAdapterSaUploadComplete @ 1c0012224 =====

void IPsecLbfoAdapterSaUploadComplete(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  
  lVar3 = *(longlong *)(param_2 + 0xd8);
  lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x438);
  lVar4 = *(longlong *)(lVar6 + 0x18);
  lVar6 = (ulonglong)*(uint *)(lVar3 + 0x14) * 0x38 + lVar6;
  lVar2 = (ulonglong)*(uint *)(lVar3 + 0x10) * 0x610 + (ulonglong)*(uint *)(lVar3 + 0x14) * 0x18;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0)) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_4c7e1387f9ea3c086637b58d47ad9570_Traceguids,param_1);
  }
  LOCK();
  *(int *)(lVar6 + 0x54) = *(int *)(lVar6 + 0x54) + 1;
  UNLOCK();
  LOCK();
  piVar1 = (int *)(lVar6 + 0x58);
  iVar5 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar5 == 1) {
    iVar5 = *(int *)(lVar6 + 0x50) - *(int *)(lVar6 + 0x54);
    *(int *)(lVar6 + 0x50) = iVar5;
    if (iVar5 < 1) {
      KeSetEvent(lVar6 + 0x38,0,0);
    }
    else {
      do {
        *(undefined4 *)(lVar6 + 0x58) = 1;
        IPsecLbfopAdapterRemove(param_1,*(uint *)(lVar3 + 0x14),(longlong *)(lVar6 + 0x28));
        LOCK();
        piVar1 = (int *)(lVar6 + 0x58);
        iVar5 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar5 != 1) break;
        *(int *)(lVar6 + 0x50) = *(int *)(lVar6 + 0x50) - *(int *)(lVar6 + 0x54);
      } while (0 < *(int *)(lVar6 + 0x50));
    }
  }
  *(undefined8 *)(lVar2 + 0x18 + lVar4) = 0;
  *(undefined1 *)(lVar2 + 0x10 + lVar4) = 0;
  IPsecLbfopReturnUploadOid(param_2,(longlong *)(lVar6 + 0x28));
  return;
}



===== IPsecLbfoOffloadMapAlloc @ 1c0012350 =====

undefined8 IPsecLbfoOffloadMapAlloc(longlong param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  longlong lVar7;
  
  uVar1 = *(uint *)((longlong)param_2 + 0x8c);
  puVar3 = (undefined1 *)ExAllocatePool2(0x40,0xf70,0x6d6f6c49);
  if (puVar3 != (undefined1 *)0x0) {
    if (SUB168(ZEXT816(0x610) * ZEXT416(uVar1),8) == 0) {
      lVar4 = ExAllocatePool2(0x40,SUB168(ZEXT816(0x610) * ZEXT416(uVar1),0),0x6d6f6c49);
      *(longlong *)(puVar3 + 0x18) = lVar4;
      if (lVar4 != 0) {
        uVar6 = 0;
        if (uVar1 != 0) {
          lVar4 = 0;
          lVar7 = 0;
          do {
            memset((void *)(*(longlong *)(puVar3 + 0x18) + 0x10 + lVar7),0,0x600);
            lVar5 = 0;
            do {
              *(undefined1 *)(*(longlong *)(puVar3 + 0x18) + lVar4 + lVar5) = 0;
              lVar5 = lVar5 + 1;
            } while (lVar5 < 2);
            uVar6 = uVar6 + 1;
            *(undefined4 *)(*(longlong *)(puVar3 + 0x18) + 4 + lVar4) = 0;
            *(undefined4 *)(*(longlong *)(puVar3 + 0x18) + 8 + lVar4) = 0;
            *(uint *)(*(longlong *)(puVar3 + 0x18) + 0xc + lVar4) = uVar6;
            lVar7 = lVar7 + 0x610;
            lVar4 = lVar4 + 0x610;
          } while (uVar6 < uVar1);
        }
        *(undefined4 *)((ulonglong)(uVar6 - 1) * 0x610 + 0xc + *(longlong *)(puVar3 + 0x18)) =
             0xffffffff;
        *(uint *)(puVar3 + 0x10) = uVar1;
        *(undefined8 *)(puVar3 + 8) = 0;
        *(uint *)(puVar3 + 4) = uVar1;
        *(undefined4 *)(puVar3 + 0x20) = 0;
        puVar3[0xf60] = 0;
        *(undefined8 *)(puVar3 + 0xf68) = 0;
        memset(puVar3 + 0x28,0,0xe00);
        uVar2 = param_2[1];
        *(undefined8 *)(puVar3 + 0xe28) = *param_2;
        *(undefined8 *)(puVar3 + 0xe30) = uVar2;
        uVar2 = param_2[3];
        *(undefined8 *)(puVar3 + 0xe38) = param_2[2];
        *(undefined8 *)(puVar3 + 0xe40) = uVar2;
        uVar2 = param_2[5];
        *(undefined8 *)(puVar3 + 0xe48) = param_2[4];
        *(undefined8 *)(puVar3 + 0xe50) = uVar2;
        uVar2 = param_2[7];
        *(undefined8 *)(puVar3 + 0xe58) = param_2[6];
        *(undefined8 *)(puVar3 + 0xe60) = uVar2;
        uVar2 = param_2[9];
        *(undefined8 *)(puVar3 + 0xe68) = param_2[8];
        *(undefined8 *)(puVar3 + 0xe70) = uVar2;
        uVar2 = param_2[0xb];
        *(undefined8 *)(puVar3 + 0xe78) = param_2[10];
        *(undefined8 *)(puVar3 + 0xe80) = uVar2;
        uVar2 = param_2[0xd];
        *(undefined8 *)(puVar3 + 0xe88) = param_2[0xc];
        *(undefined8 *)(puVar3 + 0xe90) = uVar2;
        uVar2 = param_2[0xf];
        *(undefined8 *)(puVar3 + 0xe98) = param_2[0xe];
        *(undefined8 *)(puVar3 + 0xea0) = uVar2;
        uVar2 = param_2[0x11];
        *(undefined8 *)(puVar3 + 0xea8) = param_2[0x10];
        *(undefined8 *)(puVar3 + 0xeb0) = uVar2;
        *(undefined8 *)(puVar3 + 0xeb8) = param_2[0x12];
        *(undefined4 *)(puVar3 + 0xec0) = *(undefined4 *)(param_2 + 0x13);
        *puVar3 = 1;
        *(undefined1 **)(param_1 + 0x438) = puVar3;
        return 0;
      }
    }
    ExFreePoolWithTag(puVar3,0);
  }
  return 0xc000009a;
}



===== IPsecLbfoOffloadMapReAlloc @ 1c001253c =====

undefined8 IPsecLbfoOffloadMapReAlloc(longlong param_1,undefined8 *param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  undefined8 uVar5;
  uint uVar6;
  ulonglong uVar7;
  void *_Dst;
  undefined8 *puVar8;
  
  lVar2 = *(longlong *)(param_1 + 0x438);
  uVar5 = 0;
  uVar1 = *(uint *)((longlong)param_2 + 0x8c);
  if (uVar1 <= *(uint *)(lVar2 + 0x10)) {
    *(uint *)(lVar2 + 4) = uVar1;
    return 0;
  }
  if ((SUB168(ZEXT816(0x610) * ZEXT416(uVar1),8) == 0) &&
     (lVar4 = ExAllocatePool2(0x40,SUB168(ZEXT816(0x610) * ZEXT416(uVar1),0),0x6d6f6c49), lVar4 != 0
     )) {
    uVar7 = 0;
    if (*(int *)(lVar2 + 0x10) != 0) {
      do {
        memcpy((void *)(uVar7 * 0x610 + lVar4),(void *)(uVar7 * 0x610 + *(longlong *)(lVar2 + 0x18))
               ,0x610);
        uVar6 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar6;
      } while (uVar6 < *(uint *)(lVar2 + 0x10));
    }
    uVar6 = (uint)uVar7;
    if (uVar6 < uVar1) {
      puVar8 = (undefined8 *)(lVar4 + 4 + uVar7 * 0x610);
      _Dst = (void *)(lVar4 + 0x10 + uVar7 * 0x610);
      do {
        memset(_Dst,0,0x600);
        uVar6 = (int)uVar7 + 1;
        uVar7 = (ulonglong)uVar6;
        *(undefined2 *)((longlong)puVar8 + -4) = 0;
        *(uint *)(puVar8 + 1) = uVar6;
        *puVar8 = 0;
        _Dst = (void *)((longlong)_Dst + 0x610);
        puVar8 = puVar8 + 0xc2;
      } while (uVar6 < uVar1);
    }
    *(undefined4 *)((ulonglong)(uVar6 - 1) * 0x610 + 0xc + lVar4) = *(undefined4 *)(lVar2 + 0xc);
    ExFreePoolWithTag(*(undefined8 *)(lVar2 + 0x18),0);
    *(undefined4 *)(lVar2 + 0xc) = *(undefined4 *)(lVar2 + 0x10);
    *(uint *)(lVar2 + 0x10) = uVar1;
    *(longlong *)(lVar2 + 0x18) = lVar4;
    *(uint *)(lVar2 + 4) = uVar1;
    uVar3 = param_2[1];
    *(undefined8 *)(lVar2 + 0xe28) = *param_2;
    *(undefined8 *)(lVar2 + 0xe30) = uVar3;
    uVar3 = param_2[3];
    *(undefined8 *)(lVar2 + 0xe38) = param_2[2];
    *(undefined8 *)(lVar2 + 0xe40) = uVar3;
    uVar3 = param_2[5];
    *(undefined8 *)(lVar2 + 0xe48) = param_2[4];
    *(undefined8 *)(lVar2 + 0xe50) = uVar3;
    uVar3 = param_2[7];
    *(undefined8 *)(lVar2 + 0xe58) = param_2[6];
    *(undefined8 *)(lVar2 + 0xe60) = uVar3;
    uVar3 = param_2[9];
    *(undefined8 *)(lVar2 + 0xe68) = param_2[8];
    *(undefined8 *)(lVar2 + 0xe70) = uVar3;
    uVar3 = param_2[0xb];
    *(undefined8 *)(lVar2 + 0xe78) = param_2[10];
    *(undefined8 *)(lVar2 + 0xe80) = uVar3;
    uVar3 = param_2[0xd];
    *(undefined8 *)(lVar2 + 0xe88) = param_2[0xc];
    *(undefined8 *)(lVar2 + 0xe90) = uVar3;
    uVar3 = param_2[0xf];
    *(undefined8 *)(lVar2 + 0xe98) = param_2[0xe];
    *(undefined8 *)(lVar2 + 0xea0) = uVar3;
    uVar3 = param_2[0x11];
    *(undefined8 *)(lVar2 + 0xea8) = param_2[0x10];
    *(undefined8 *)(lVar2 + 0xeb0) = uVar3;
    *(undefined8 *)(lVar2 + 0xeb8) = param_2[0x12];
    *(undefined4 *)(lVar2 + 0xec0) = *(undefined4 *)(param_2 + 0x13);
  }
  else {
    uVar5 = 0xc000009a;
  }
  return uVar5;
}



===== IPsecLbfoOffloadMapWaitForIdleAndAcquireExclusiveTeamLock @ 1c00126f0 =====

void IPsecLbfoOffloadMapWaitForIdleAndAcquireExclusiveTeamLock(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0x88);
  while( true ) {
    NdisAcquireRWLockWrite(uVar2,param_2,0);
    lVar1 = *(longlong *)(param_1 + 0x438);
    if ((lVar1 == 0) || ((*(int *)(lVar1 + 0x20) == 0 && (*(char *)(lVar1 + 0xf60) == '\0'))))
    break;
    NdisReleaseRWLock(*(undefined8 *)(param_1 + 0x88),param_2);
    KeDelayExecutionThread(0,0);
    uVar2 = *(undefined8 *)(param_1 + 0x88);
  }
  return;
}



===== IPsecLbfoTeamSaAdd @ 1c0012784 =====

int IPsecLbfoTeamSaAdd(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  char *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  ulonglong uVar8;
  uint uVar9;
  int iVar10;
  ulonglong uVar11;
  longlong lVar12;
  undefined2 local_res8;
  undefined1 local_resa;
  undefined2 local_res18;
  undefined1 local_res1a;
  
  uVar11 = 0;
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x48) + 0x438);
  local_res8 = 0;
  local_resa = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0)) &&
     (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_4c7e1387f9ea3c086637b58d47ad9570_Traceguids,param_1);
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88),&local_res8,0);
  iVar6 = 0;
  pcVar5 = *(char **)(*(longlong *)(param_1 + 0x48) + 0x438);
  if (*pcVar5 == '\0') {
    iVar6 = 0x40020005;
  }
  else if (*(uint *)(pcVar5 + 8) < *(uint *)(pcVar5 + 4)) {
    uVar11 = (ulonglong)*(uint *)(pcVar5 + 0xc);
    puVar7 = (undefined1 *)(uVar11 * 0x610 + *(longlong *)(pcVar5 + 0x18));
    *puVar7 = 1;
    uVar3 = *(undefined4 *)(puVar7 + 0xc);
    *(int *)(pcVar5 + 8) = *(int *)(pcVar5 + 8) + 1;
    *(int *)(pcVar5 + 0x20) = *(int *)(pcVar5 + 0x20) + 1;
    *(undefined4 *)(pcVar5 + 0xc) = uVar3;
  }
  else {
    iVar6 = -0x3fffff66;
  }
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88),&local_res8);
  if (iVar6 == 0) {
    iVar10 = (int)uVar11;
    lVar12 = uVar11 * 0x610 + *(longlong *)(lVar4 + 0x18);
    *(undefined4 *)(lVar12 + 4) = 1;
    uVar8 = IPsecLbfopTeamSaAdd(param_1,param_2,iVar10,lVar4 + 0x28,lVar12);
    iVar6 = (int)uVar8;
    LOCK();
    piVar1 = (int *)(lVar12 + 4);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      local_res18 = 0;
      local_res1a = 0;
      if (*(int *)(lVar12 + 8) == 0) {
        lVar12 = *(longlong *)(param_2 + 0x28);
        uVar9 = iVar10 + 1;
        *(ulonglong *)(lVar12 + 0x30) = (ulonglong)uVar9;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_Dq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)uVar9,uVar11,
                    *(undefined4 *)(lVar12 + 0x44),(char)uVar9);
        }
      }
      NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88),&local_res18,0);
      *(int *)(lVar4 + 0x20) = *(int *)(lVar4 + 0x20) + -1;
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88),&local_res18);
    }
  }
  return iVar6;
}



===== IPsecLbfoTeamSaDelete @ 1c0012960 =====

int IPsecLbfoTeamSaDelete(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  int iVar7;
  longlong *plVar8;
  undefined2 local_res8;
  undefined1 local_resa;
  longlong local_res10;
  longlong local_res18;
  
  iVar7 = 0;
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x48) + 0x438);
  uVar5 = *(int *)(*(longlong *)(param_2 + 0x28) + 0x10) - 1;
  lVar6 = (ulonglong)uVar5 * 0x610;
  plVar8 = (longlong *)(*(longlong *)(lVar2 + 0x18) + lVar6);
  local_res8 = 0;
  local_resa = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0)) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_4c7e1387f9ea3c086637b58d47ad9570_Traceguids,param_1,
              (char)*(undefined8 *)(*(longlong *)(param_2 + 0x28) + 0x10));
  }
  NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88),&local_res8,0);
  if (*(char *)(lVar2 + 0xf60) == '\0') {
    *(undefined1 *)(lVar2 + 0xf60) = 1;
  }
  else {
    *(longlong *)(param_2 + 200) = param_1;
    iVar7 = 0x103;
    *(undefined8 *)(param_2 + 0xd0) = *(undefined8 *)(lVar2 + 0xf68);
    *(longlong *)(lVar2 + 0xf68) = param_2;
  }
  NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88),&local_res8);
  iVar4 = 0x103;
  if (iVar7 != 0x103) {
    *(undefined4 *)((longlong)plVar8 + 4) = 1;
    IPsecLbfopTeamSaDelete(param_1,param_2,uVar5,plVar8);
    LOCK();
    piVar1 = (int *)((longlong)plVar8 + 4);
    iVar4 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar4 == 1) {
      local_res10 = 0;
      local_res18 = 0;
      NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88),&local_res8,0);
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x48) + 0x438);
      lVar3 = *(longlong *)(lVar2 + 0x18);
      *(undefined2 *)(lVar3 + lVar6) = 0;
      *(undefined4 *)(lVar3 + 0xc + lVar6) = *(undefined4 *)(lVar2 + 0xc);
      *(int *)(lVar2 + 8) = *(int *)(lVar2 + 8) + -1;
      *(uint *)(lVar2 + 0xc) = uVar5;
      IPsecLbfopCheckForQueuedUploadRequest(*(longlong *)(param_1 + 0x48),&local_res10,&local_res18)
      ;
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + 0x48) + 0x88),&local_res8);
      if (local_res10 != 0) {
        IPsecLbfopProcessQueuedUploadRequest(local_res18,local_res10);
      }
    }
    iVar4 = iVar7;
  }
  return iVar4;
}



===== IPsecLbfopAdapterRemove @ 1c0012b44 =====

void IPsecLbfopAdapterRemove(longlong param_1,uint param_2,longlong *param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong lVar8;
  
  uVar7 = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0x438);
  if (*(int *)(lVar1 + 0x10) != 0) {
    do {
      lVar2 = *(longlong *)(lVar1 + 0x18);
      lVar8 = uVar7 * 0x610 + (ulonglong)param_2 * 0x18;
      if (*(char *)(lVar8 + 0x10 + lVar2) != '\0') {
        lVar5 = IPsecLbfopGetUploadOid(param_3,'\x01',*(undefined8 *)(lVar8 + 0x18 + lVar2));
        if (lVar5 != 0) {
          lVar3 = *(longlong *)(lVar5 + 0xd8);
          *(undefined1 *)(lVar5 + 0xe0) = 1;
          *(uint *)(lVar3 + 0x14) = param_2;
          *(int *)(lVar3 + 0x10) = (int)uVar7;
          LOCK();
          *(int *)(param_3 + 6) = (int)param_3[6] + 1;
          UNLOCK();
          iVar4 = NdisDirectOidRequest(param_3[1],lVar5);
          if (iVar4 == 0) {
            *(undefined8 *)(lVar8 + 0x18 + lVar2) = 0;
            *(undefined1 *)(lVar8 + 0x10 + lVar2) = 0;
            LOCK();
            *(int *)(param_3 + 6) = (int)param_3[6] + -1;
            UNLOCK();
            LOCK();
            *(int *)((longlong)param_3 + 0x2c) = *(int *)((longlong)param_3 + 0x2c) + 1;
            UNLOCK();
            IPsecLbfopReturnUploadOid(lVar5,param_3);
          }
        }
      }
      uVar6 = (int)uVar7 + 1;
      uVar7 = (ulonglong)uVar6;
    } while (uVar6 < *(uint *)(lVar1 + 0x10));
  }
  return;
}



===== IPsecLbfopCheckForQueuedUploadRequest @ 1c0012c30 =====

void IPsecLbfopCheckForQueuedUploadRequest(longlong param_1,longlong *param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x438);
  lVar2 = *(longlong *)(lVar1 + 0xf68);
  if (lVar2 == 0) {
    *(undefined1 *)(lVar1 + 0xf60) = 0;
    lVar2 = 0;
  }
  else {
    *param_3 = *(undefined8 *)(lVar2 + 200);
    *(undefined8 *)(lVar1 + 0xf68) = *(undefined8 *)(lVar2 + 0xd0);
    *(undefined8 *)(lVar2 + 200) = 0;
    *(undefined8 *)(lVar2 + 0xd0) = 0;
  }
  *param_2 = lVar2;
  return;
}



===== IPsecLbfopDisableTOv2 @ 1c0012c84 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IPsecLbfopDisableTOv2(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  undefined4 local_84;
  undefined8 local_80;
  undefined4 local_74;
  undefined8 *local_58;
  undefined4 local_50;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar1 = *(longlong *)(param_1 + 0x438);
  local_84 = 0;
  *(undefined8 *)(lVar1 + 0xec4) = *(undefined8 *)(lVar1 + 0xe28);
  *(undefined8 *)(lVar1 + 0xecc) = *(undefined8 *)(lVar1 + 0xe30);
  *(undefined8 *)(lVar1 + 0xed4) = *(undefined8 *)(lVar1 + 0xe38);
  *(undefined8 *)(lVar1 + 0xedc) = *(undefined8 *)(lVar1 + 0xe40);
  *(undefined8 *)(lVar1 + 0xee4) = *(undefined8 *)(lVar1 + 0xe48);
  *(undefined8 *)(lVar1 + 0xeec) = *(undefined8 *)(lVar1 + 0xe50);
  *(undefined8 *)(lVar1 + 0xef4) = *(undefined8 *)(lVar1 + 0xe58);
  *(undefined8 *)(lVar1 + 0xefc) = *(undefined8 *)(lVar1 + 0xe60);
  *(undefined8 *)(lVar1 + 0xf04) = *(undefined8 *)(lVar1 + 0xe68);
  *(undefined8 *)(lVar1 + 0xf0c) = *(undefined8 *)(lVar1 + 0xe70);
  *(undefined8 *)(lVar1 + 0xf14) = *(undefined8 *)(lVar1 + 0xe78);
  *(undefined8 *)(lVar1 + 0xf1c) = *(undefined8 *)(lVar1 + 0xe80);
  *(undefined8 *)(lVar1 + 0xf24) = *(undefined8 *)(lVar1 + 0xe88);
  *(undefined8 *)(lVar1 + 0xf2c) = *(undefined8 *)(lVar1 + 0xe90);
  *(undefined8 *)(lVar1 + 0xf34) = *(undefined8 *)(lVar1 + 0xe98);
  *(undefined8 *)(lVar1 + 0xf3c) = *(undefined8 *)(lVar1 + 0xea0);
  *(undefined8 *)(lVar1 + 0xf44) = *(undefined8 *)(lVar1 + 0xea8);
  *(undefined8 *)(lVar1 + 0xf4c) = *(undefined8 *)(lVar1 + 0xeb0);
  *(undefined8 *)(lVar1 + 0xf54) = *(undefined8 *)(lVar1 + 0xeb8);
  *(undefined4 *)(lVar1 + 0xf5c) = *(undefined4 *)(lVar1 + 0xec0);
  *(undefined2 *)(lVar1 + 0xf3e) = 0;
  *(undefined1 *)(lVar1 + 0xf40) = 1;
  memset(&local_88,0,0x70);
  local_88 = 0x700198;
  local_74 = 0x40020006;
  local_50 = 0x9c;
  local_58 = (undefined8 *)(lVar1 + 0xec4);
  for (puVar2 = *(undefined8 **)(param_1 + 0x100); puVar2 != (undefined8 *)(param_1 + 0x100);
      puVar2 = (undefined8 *)*puVar2) {
    local_80 = puVar2[2];
    NdisMIndicateStatusEx(puVar2[2],&local_88);
  }
  return;
}



===== IPsecLbfopEnableTOv2 @ 1c0012dc4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IPsecLbfopEnableTOv2(longlong param_1)

{
  undefined8 *puVar1;
  undefined1 auStack_a8 [32];
  undefined4 local_88 [2];
  undefined8 local_80;
  undefined4 local_74;
  longlong local_58;
  undefined4 local_50;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  memset(local_88,0,0x70);
  puVar1 = *(undefined8 **)(param_1 + 0x100);
  local_58 = *(longlong *)(param_1 + 0x438) + 0xe28;
  local_88[0] = 0x700198;
  local_74 = 0x40020006;
  local_50 = 0x9c;
  for (; puVar1 != (undefined8 *)(param_1 + 0x100); puVar1 = (undefined8 *)*puVar1) {
    local_80 = puVar1[2];
    NdisMIndicateStatusEx(puVar1[2],local_88);
  }
  return;
}



===== IPsecLbfopGetUploadOid @ 1c0012e7c =====

longlong IPsecLbfopGetUploadOid(longlong *param_1,char param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong local_res20;
  
  local_res20 = 0;
  if ((param_2 != '\0') && (IPsecLbfopUploadOidAllocate(0,param_3,&local_res20), local_res20 != 0))
  {
    return local_res20;
  }
  lVar1 = *param_1;
  if (lVar1 != 0) {
    *param_1 = 0;
    *(undefined8 *)(*(longlong *)(lVar1 + 0x28) + 0x10) = param_3;
  }
  return lVar1;
}



===== IPsecLbfopProcessQueuedUploadRequest @ 1c0012ed8 =====

void IPsecLbfopProcessQueuedUploadRequest(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong lVar9;
  uint uVar10;
  longlong *plVar11;
  longlong local_res8;
  longlong local_res10;
  undefined2 local_res18;
  undefined1 local_res1a;
  
  plVar11 = (longlong *)(param_1 + 0x48);
  lVar3 = *(longlong *)(*plVar11 + 0x438);
  local_res8 = param_1;
  local_res10 = param_2;
  do {
    uVar10 = *(int *)(*(longlong *)(local_res10 + 0x28) + 0x10) - 1;
    lVar9 = (ulonglong)uVar10 * 0x610;
    plVar8 = (longlong *)(*(longlong *)(lVar3 + 0x18) + lVar9);
    *(undefined4 *)((longlong)plVar8 + 4) = 1;
    IPsecLbfopTeamSaDelete(param_1,local_res10,uVar10,plVar8);
    lVar7 = local_res10;
    lVar6 = local_res8;
    LOCK();
    piVar1 = (int *)((longlong)plVar8 + 4);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      local_res18 = 0;
      local_res1a = 0;
      NdisAcquireRWLockWrite(*(undefined8 *)(*plVar11 + 0x88),&local_res18,0);
      lVar4 = *(longlong *)(*plVar11 + 0x438);
      lVar5 = *(longlong *)(lVar4 + 0x18);
      *(undefined2 *)(lVar9 + lVar5) = 0;
      *(undefined4 *)(lVar9 + 0xc + lVar5) = *(undefined4 *)(lVar4 + 0xc);
      *(int *)(lVar4 + 8) = *(int *)(lVar4 + 8) + -1;
      *(uint *)(lVar4 + 0xc) = uVar10;
      IPsecLbfopCheckForQueuedUploadRequest(*plVar11,&local_res10,&local_res8);
      param_1 = local_res8;
      plVar11 = (longlong *)(local_res8 + 0x48);
      NdisReleaseRWLock(*(undefined8 *)(*plVar11 + 0x88),&local_res18);
      NdisMDirectOidRequestComplete(*(undefined8 *)(lVar6 + 0x20),lVar7,0);
    }
    else {
      param_1 = local_res8;
    }
  } while (local_res10 != 0);
  return;
}



===== IPsecLbfopReturnUploadOid @ 1c0013018 =====

void IPsecLbfopReturnUploadOid(longlong param_1,longlong *param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0xd8);
  if (*(char *)(puVar1 + 3) == '\0') {
    ExFreePoolWithTag(param_1,0);
  }
  else {
    *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x10) = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    LOCK();
    UNLOCK();
    *(undefined1 *)(puVar1 + 3) = 1;
    *param_2 = param_1;
  }
  return;
}



===== IPsecLbfopSignalUploadOfExistingSAs @ 1c001306c =====

void IPsecLbfopSignalUploadOfExistingSAs(longlong param_1)

{
  undefined8 local_res10 [3];
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000) != 0)) &&
     (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
             &WPP_4c7e1387f9ea3c086637b58d47ad9570_Traceguids,param_1);
  }
  IPsecLbfopDisableTOv2(param_1);
  local_res10[0] = 0xfffffffffff85ee0;
  KeDelayExecutionThread(0,0,local_res10);
  IPsecLbfopEnableTOv2(param_1);
  return;
}



===== IPsecLbfopTeamSaAdd @ 1c00130ec =====

ulonglong IPsecLbfopTeamSaAdd(longlong param_1,longlong param_2,undefined4 param_3,longlong param_4,
                             longlong param_5)

{
  longlong *plVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong lVar4;
  uint uVar5;
  longlong *plVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined2 local_58;
  undefined1 local_56;
  longlong local_50 [2];
  
  uVar8 = 0;
  plVar1 = (longlong *)(param_1 + 0x60);
  local_50[0] = 0;
  plVar9 = (longlong *)*plVar1;
  if ((longlong *)*plVar1 != plVar1) {
    do {
      plVar10 = plVar9;
      lVar4 = plVar10[-4];
      local_58 = 0;
      local_56 = 0;
      NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(lVar4 + 0x28) + 0x88),&local_58,0);
      iVar3 = *(int *)(lVar4 + 0xf0);
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(lVar4 + 0x28) + 0x88),&local_58);
      plVar6 = (longlong *)0x0;
      if (iVar3 != 2) {
        puVar2 = (undefined8 *)(lVar4 + 0x20);
        uVar5 = NdisAllocateCloneOidRequest(*puVar2,param_2,0x676f6c49,local_50);
        uVar8 = (ulonglong)uVar5;
        if (uVar5 != 0) goto LAB_1c00132f4;
        plVar6 = (longlong *)ExAllocatePool2(0x40,0x20,0x676f6c49);
        if (plVar6 == (longlong *)0x0) {
          uVar8 = 0xc000009a;
          goto LAB_1c0013315;
        }
        plVar9 = (longlong *)((ulonglong)*(uint *)(plVar10 + 8) * 0x38 + param_4);
        if (*plVar9 == 0) {
          uVar7 = IPsecLbfopUploadOidAllocate(1,0,plVar9);
          uVar8 = uVar7 & 0xffffffff;
          if ((int)uVar7 != 0) goto LAB_1c00132f4;
          KeInitializeEvent((ulonglong)*(uint *)(plVar10 + 8) * 0x38 + 0x10 + param_4,0);
          *(undefined8 *)((ulonglong)*(uint *)(plVar10 + 8) * 0x38 + 8 + param_4) = *puVar2;
        }
        *plVar6 = param_1;
        plVar6[1] = param_2;
        *(undefined4 *)(plVar6 + 2) = param_3;
        *(int *)((longlong)plVar6 + 0x14) = (int)plVar10[8];
        *(undefined1 *)(plVar6 + 3) = 0;
        LOCK();
        *(int *)(param_5 + 4) = *(int *)(param_5 + 4) + 1;
        UNLOCK();
        *(longlong **)(local_50[0] + 0xd8) = plVar6;
        uVar5 = NdisDirectOidRequest(*puVar2,local_50[0]);
        uVar8 = (ulonglong)uVar5;
        if (uVar5 == 0x103) {
LAB_1c00132d1:
          if (uVar5 != 0x103) break;
        }
        else {
          LOCK();
          *(int *)(param_5 + 4) = *(int *)(param_5 + 4) + -1;
          UNLOCK();
          if (uVar5 != 0) goto LAB_1c00132d1;
          *(undefined8 *)(param_5 + ((ulonglong)*(uint *)(plVar10 + 8) + 1) * 0x18) =
               *(undefined8 *)(*(longlong *)(local_50[0] + 0x28) + 0x30);
        }
        local_50[0] = 0;
      }
      plVar6 = (longlong *)0x0;
      plVar9 = (longlong *)*plVar10;
    } while ((longlong *)*plVar10 != plVar1);
    if ((int)uVar8 != 0) {
LAB_1c00132f4:
      if ((int)uVar8 != 0x103) {
        if (plVar6 != (longlong *)0x0) {
          ExFreePoolWithTag(plVar6,0);
        }
LAB_1c0013315:
        if (local_50[0] != 0) {
          NdisFreeCloneOidRequest(*(undefined8 *)(lVar4 + 0x20));
        }
        *(int *)(param_5 + 0x20 + (ulonglong)*(uint *)(plVar10 + 8) * 0x18) = (int)uVar8;
        LOCK();
        *(int *)(param_5 + 8) = *(int *)(param_5 + 8) + 1;
        UNLOCK();
      }
    }
  }
  return uVar8;
}



===== IPsecLbfopTeamSaDelete @ 1c0013364 =====

void IPsecLbfopTeamSaDelete(longlong param_1,longlong param_2,undefined4 param_3,longlong *param_4)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  int iVar4;
  uint uVar5;
  longlong *plVar6;
  longlong *plVar7;
  
  uVar5 = 0;
  plVar7 = (longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x48) + 0x438) + 0x28);
  plVar3 = param_4;
  do {
    plVar6 = plVar3 + 3;
    lVar1 = *plVar6;
    if ((lVar1 != 0) && ((char)plVar3[2] == '\0')) {
      lVar2 = *plVar7;
      if (lVar2 != 0) {
        *plVar7 = 0;
        *(longlong *)(*(longlong *)(lVar2 + 0x28) + 0x10) = lVar1;
      }
      plVar3 = *(longlong **)(lVar2 + 0xd8);
      *(undefined1 *)(lVar2 + 0xe0) = 0;
      *plVar3 = param_1;
      *(undefined4 *)(plVar3 + 2) = param_3;
      *(uint *)((longlong)plVar3 + 0x14) = uVar5;
      plVar3[1] = param_2;
      LOCK();
      *(int *)((longlong)param_4 + 4) = *(int *)((longlong)param_4 + 4) + 1;
      UNLOCK();
      iVar4 = NdisDirectOidRequest(plVar7[1],lVar2);
      if (iVar4 == 0) {
        *plVar6 = 0;
        LOCK();
        *(int *)((longlong)param_4 + 4) = *(int *)((longlong)param_4 + 4) + -1;
        UNLOCK();
        IPsecLbfopReturnUploadOid(lVar2,plVar7);
      }
    }
    uVar5 = uVar5 + 1;
    plVar7 = plVar7 + 7;
    plVar3 = plVar6;
  } while (uVar5 < 0x40);
  return;
}



===== IPsecLbfopUploadOidAllocate @ 1c0013444 =====

undefined8 IPsecLbfopUploadOidAllocate(undefined1 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined4 *)ExAllocatePool2(0x40,0x128,0x676f6c49);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    *puVar1 = 0xf00196;
    puVar1[1] = 1;
    puVar1[8] = 0xfc030203;
    *(undefined4 **)(puVar1 + 10) = puVar1 + 0x3c;
    *(undefined8 *)(puVar1 + 0x3e) = 0;
    puVar1[0x3c] = 0x180180;
    *(undefined8 *)(puVar1 + 0x40) = param_2;
    puVar1[0xc] = 0x18;
    *(undefined8 *)(puVar1 + 0x42) = 0;
    *(undefined8 *)(puVar1 + 0x44) = 0;
    *(undefined8 *)(puVar1 + 0x46) = 0;
    *(undefined8 *)(puVar1 + 0x48) = 0;
    LOCK();
    UNLOCK();
    *(undefined1 *)(puVar1 + 0x48) = param_1;
    uVar2 = 0;
    *(undefined4 **)(puVar1 + 0x36) = puVar1 + 0x42;
    *param_3 = puVar1;
  }
  return uVar2;
}



===== WPP_SF_Dq @ 1c0013500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4c7e1387f9ea3c086637b58d47ad9570_Traceguids,0xd,local_res20,4,
             &param_5,8,0);
  return;
}



===== vmqAllocateQueue @ 1c0013560 =====

int vmqAllocateQueue(longlong param_1,void *param_2)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  undefined8 *puVar4;
  uint uVar5;
  void *_Dst;
  size_t _Size;
  undefined2 local_res8;
  undefined1 local_resa;
  int local_res10 [2];
  longlong local_res18 [2];
  
  local_res8 = 0;
  local_resa = 0;
  iVar3 = -0x3fffffff;
  bVar2 = false;
  if (*(uint *)(param_1 + 0x18) < *(uint *)((longlong)param_2 + 0xc)) {
    return -0x3ffffff3;
  }
  NdisAcquireRWLockRead(*(undefined8 *)(*(longlong *)(param_1 + -0xb0) + 0x88),&local_res8,0);
  if (*(char *)(param_1 + 0x198) == '\0') {
    uVar5 = *(uint *)((longlong)param_2 + 0xc);
    if (uVar5 == 0) {
      uVar5 = 1;
      if (*(uint *)(param_1 + 0x18) != 0) {
        do {
          if (*(int *)((ulonglong)uVar5 * 0x568 + 0x548 + *(longlong *)(param_1 + 0x338)) == 0)
          goto LAB_1c001360a;
          uVar5 = uVar5 + 1;
        } while (uVar5 <= *(uint *)(param_1 + 0x18));
      }
      uVar5 = 0;
LAB_1c001360a:
      *(uint *)((longlong)param_2 + 0xc) = uVar5;
      if (uVar5 == 0) {
        iVar3 = -0x3fffff66;
        goto LAB_1c0013616;
      }
    }
    _Size = 0x448;
    _Dst = (void *)((ulonglong)uVar5 * 0x568 + *(longlong *)(param_1 + 0x338));
    *(undefined4 *)((longlong)_Dst + 0x548) = 1;
    *(int *)(param_1 + 0x330) = *(int *)(param_1 + 0x330) + 1;
    if (*(ushort *)((longlong)param_2 + 2) < 0x448) {
      _Size = (size_t)*(ushort *)((longlong)param_2 + 2);
    }
    memcpy((void *)((longlong)_Dst + 0x100),param_2,_Size);
    *(undefined4 *)((longlong)_Dst + 0x540) = 0;
    lVar1 = (longlong)_Dst + 0x550;
    *(longlong *)((longlong)_Dst + 0x558) = lVar1;
    *(longlong *)lVar1 = lVar1;
    *(undefined4 *)((longlong)param_2 + 0x440) = 0;
    NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + -0xb0) + 0x88));
    for (puVar4 = *(undefined8 **)(param_1 + -0x98); puVar4 != (undefined8 *)(param_1 + -0x98);
        puVar4 = (undefined8 *)*puVar4) {
      local_res10[0] = *(int *)(puVar4 + 8);
      if (local_res10[0] != 0) {
        local_res18[0] = puVar4[-4] + 0x1af8;
        goto LAB_1c00136d6;
      }
    }
    local_res10[0] = 0;
    local_res18[0] = 0;
LAB_1c00136d6:
    if (local_res18[0] != 0) {
      do {
        iVar3 = vmqAllocateQueueOnMNic
                          (param_1,local_res18[0],local_res10[0],(void *)((longlong)_Dst + 0x100));
        if (iVar3 == 0) {
          bVar2 = true;
        }
        vmqcGetNextMNic(param_1,local_res18,local_res10);
      } while (local_res18[0] != 0);
      if (bVar2) {
        return 0;
      }
    }
    memset(_Dst,0,0x568);
    *(int *)(param_1 + 0x330) = *(int *)(param_1 + 0x330) + -1;
  }
  else {
    iVar3 = -0x3fdcefff;
LAB_1c0013616:
    NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + -0xb0) + 0x88),&local_res8);
  }
  return iVar3;
}



===== vmqAllocateQueueOnMNic @ 1c001376c =====

int vmqAllocateQueueOnMNic(longlong param_1,longlong param_2,int param_3,void *param_4)

{
  uint uVar1;
  int iVar2;
  void *_Dst;
  
  uVar1 = 0x448;
  if (*(ushort *)((longlong)param_4 + 2) < 0x448) {
    uVar1 = (uint)*(ushort *)((longlong)param_4 + 2);
  }
  _Dst = (void *)ExAllocatePoolWithTagPriority(0x200,uVar1,0x5156544e,0x10);
  if (_Dst == (void *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    memcpy(_Dst,param_4,(ulonglong)uVar1);
    *(undefined4 *)((longlong)_Dst + 0xc) = 0;
    iVar2 = vmqcIssueOidRequest(param_2,0x10223,0xc,_Dst,uVar1);
    if (iVar2 == 0) {
      *(undefined4 *)
       (*(longlong *)(param_2 + 0x1a0) + (ulonglong)*(uint *)((longlong)_Dst + 0xc) * 4) =
           *(undefined4 *)((longlong)param_4 + 0xc);
      *(undefined4 *)
       (*(longlong *)(param_1 + 0x338) +
       ((ulonglong)*(uint *)((longlong)param_4 + 0xc) * 0x15a + (ulonglong)(param_3 - 1)) * 4) =
           *(undefined4 *)((longlong)_Dst + 0xc);
      *(int *)(param_2 + 0x198) = *(int *)(param_2 + 0x198) + 1;
    }
    ExFreePoolWithTag(_Dst,0x5156544e);
  }
  return iVar2;
}



===== vmqAllocateTNicQueueArray @ 1c001387c =====

undefined8 vmqAllocateTNicQueueArray(longlong param_1)

{
  uint uVar1;
  void *in_RAX;
  void *_Dst;
  longlong lVar2;
  
  if (*(char *)(param_1 + 0x32c) != '\0') {
    uVar1 = *(int *)(param_1 + 0x18) + 1;
    in_RAX = (void *)(ulonglong)uVar1;
    uVar1 = uVar1 * 0x568;
    if (*(uint *)(param_1 + 0x340) < uVar1) {
      if (*(longlong *)(param_1 + 0x338) != 0) {
        ExFreePoolWithTag(*(longlong *)(param_1 + 0x338),0x5156544e);
      }
      _Dst = (void *)ExAllocatePoolWithTagPriority(0x200,uVar1,0x5156544e,0x10);
      *(void **)(param_1 + 0x338) = _Dst;
      if (_Dst == (void *)0x0) {
        *(undefined4 *)(param_1 + 0x340) = 0;
        return 0;
      }
      *(uint *)(param_1 + 0x340) = uVar1;
      in_RAX = memset(_Dst,0,(ulonglong)uVar1);
      *(undefined4 *)(*(longlong *)(param_1 + 0x338) + 0x548) = 2;
      lVar2 = *(longlong *)(param_1 + 0x338) + 0x550;
      *(longlong *)(*(longlong *)(param_1 + 0x338) + 0x558) = lVar2;
      *(longlong *)lVar2 = lVar2;
    }
  }
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== vmqChangeQueueParams @ 1c0013960 =====

int vmqChangeQueueParams(longlong param_1,void *param_2)

{
  undefined8 *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined8 uVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  int local_res10 [2];
  longlong local_res18 [2];
  
  uVar3 = *(uint *)((longlong)param_2 + 0xc);
  iVar5 = 0;
  if ((((uVar3 == 0) || (*(uint *)(param_1 + 0x18) < uVar3)) ||
      (*(int *)((ulonglong)uVar3 * 0x568 + 0x548 + *(longlong *)(param_1 + 0x338)) == 0)) ||
     ((*(uint *)((longlong)param_2 + 4) & 0xffff0000) == 0)) {
    return -0x3ffffff3;
  }
  for (puVar6 = *(undefined8 **)(param_1 + -0x98); puVar6 != (undefined8 *)(param_1 + -0x98);
      puVar6 = (undefined8 *)*puVar6) {
    local_res10[0] = *(int *)(puVar6 + 8);
    if (local_res10[0] != 0) {
      local_res18[0] = puVar6[-4] + 0x1af8;
      goto LAB_1c00139ef;
    }
  }
  local_res10[0] = 0;
  local_res18[0] = 0;
LAB_1c00139ef:
  if (local_res18[0] != 0) {
    do {
      if ((*(int *)(*(longlong *)(param_1 + 0x338) +
                   ((ulonglong)*(uint *)((longlong)param_2 + 0xc) * 0x15a +
                   (ulonglong)(local_res10[0] - 1)) * 4) != 0) &&
         (iVar5 = vmqSetQueueParamsOnMNic(param_1,local_res18[0],local_res10[0],param_2), iVar5 != 0
         )) goto LAB_1c0013b70;
      vmqcGetNextMNic(param_1,local_res18,local_res10);
    } while (local_res18[0] != 0);
    if (iVar5 != 0) {
LAB_1c0013b70:
      puVar6 = *(undefined8 **)(param_1 + -0x98);
      do {
        if (puVar6 == (undefined8 *)(param_1 + -0x98)) {
          local_res10[0] = 0;
          local_res18[0] = 0;
LAB_1c0013b9b:
          if (local_res18[0] == 0) {
            return iVar5;
          }
          do {
            if (*(int *)(*(longlong *)(param_1 + 0x338) +
                        ((ulonglong)(local_res10[0] - 1) +
                        (ulonglong)*(uint *)((longlong)param_2 + 0xc) * 0x15a) * 4) != 0) {
              puVar2 = (uint *)((ulonglong)*(uint *)((longlong)param_2 + 0xc) * 0x568 + 0x104 +
                               *(longlong *)(param_1 + 0x338));
              *puVar2 = *puVar2 | *(uint *)((longlong)param_2 + 4) & 0xffff0000;
              vmqSetQueueParamsOnMNic
                        (param_1,local_res18[0],local_res10[0],
                         (void *)(*(longlong *)(param_1 + 0x338) + 0x100 +
                                 (ulonglong)*(uint *)((longlong)param_2 + 0xc) * 0x568));
              *(undefined2 *)
               ((ulonglong)*(uint *)((longlong)param_2 + 0xc) * 0x568 + 0x106 +
               *(longlong *)(param_1 + 0x338)) = 0;
            }
            vmqcGetNextMNic(param_1,local_res18,local_res10);
          } while (local_res18[0] != 0);
          return iVar5;
        }
        local_res10[0] = *(int *)(puVar6 + 8);
        if (local_res10[0] != 0) {
          local_res18[0] = puVar6[-4] + 0x1af8;
          goto LAB_1c0013b9b;
        }
        puVar6 = (undefined8 *)*puVar6;
      } while( true );
    }
  }
  if ((*(uint *)((longlong)param_2 + 4) >> 0x10 & 1) != 0) {
    *(uint *)((ulonglong)*(uint *)((longlong)param_2 + 0xc) * 0x568 + 0x104 +
             *(longlong *)(param_1 + 0x338)) = *(uint *)((longlong)param_2 + 4) & 0xffff;
  }
  if ((*(uint *)((longlong)param_2 + 4) & 0x20000) != 0) {
    uVar4 = *(undefined8 *)((longlong)param_2 + 0x20);
    puVar6 = (undefined8 *)
             ((ulonglong)*(uint *)((longlong)param_2 + 0xc) * 0x568 + 0x118 +
             *(longlong *)(param_1 + 0x338));
    *puVar6 = *(undefined8 *)((longlong)param_2 + 0x18);
    puVar6[1] = uVar4;
  }
  if ((*(uint *)((longlong)param_2 + 4) & 0x40000) != 0) {
    *(undefined4 *)
     ((ulonglong)*(uint *)((longlong)param_2 + 0xc) * 0x568 + 0x128 + *(longlong *)(param_1 + 0x338)
     ) = *(undefined4 *)((longlong)param_2 + 0x28);
  }
  if ((*(uint *)((longlong)param_2 + 4) & 0x80000) != 0) {
    puVar6 = (undefined8 *)((longlong)param_2 + 0x238);
    lVar7 = 4;
    puVar8 = (undefined8 *)
             (*(longlong *)(param_1 + 0x338) +
             (ulonglong)*(uint *)((longlong)param_2 + 0xc) * 0x568 + 0x338);
    do {
      uVar4 = puVar6[1];
      *puVar8 = *puVar6;
      puVar8[1] = uVar4;
      uVar4 = puVar6[3];
      puVar8[2] = puVar6[2];
      puVar8[3] = uVar4;
      uVar4 = puVar6[5];
      puVar8[4] = puVar6[4];
      puVar8[5] = uVar4;
      uVar4 = puVar6[7];
      puVar8[6] = puVar6[6];
      puVar8[7] = uVar4;
      uVar4 = puVar6[9];
      puVar8[8] = puVar6[8];
      puVar8[9] = uVar4;
      uVar4 = puVar6[0xb];
      puVar8[10] = puVar6[10];
      puVar8[0xb] = uVar4;
      uVar4 = puVar6[0xd];
      puVar8[0xc] = puVar6[0xc];
      puVar8[0xd] = uVar4;
      puVar9 = puVar8 + 0x10;
      puVar1 = puVar6 + 0xe;
      uVar4 = puVar6[0xf];
      puVar6 = puVar6 + 0x10;
      puVar8[0xe] = *puVar1;
      puVar8[0xf] = uVar4;
      lVar7 = lVar7 + -1;
      puVar8 = puVar9;
    } while (lVar7 != 0);
    *(undefined4 *)puVar9 = *(undefined4 *)puVar6;
  }
  return 0;
}



===== vmqClearCapabilities @ 1c0013c70 =====

void vmqClearCapabilities(undefined4 *param_1)

{
  memset(param_1 + 1,0,0x50);
  *param_1 = 0x540280;
  memset((void *)((longlong)param_1 + 0xc9),0,0x53);
  param_1[0x32] = 0x540280;
  memset((void *)((longlong)param_1 + 0x55),0,0x73);
  param_1[0x15] = 0x200180;
  memset((void *)((longlong)param_1 + 0x11d),0,0x73);
  param_1[0x47] = 0x200180;
  return;
}



===== vmqClearFilter @ 1c0013d00 =====

int vmqClearFilter(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  int iVar5;
  longlong *plVar6;
  
  uVar1 = *(uint *)(param_2 + 8);
  if (((*(uint *)(param_1 + 0x18) < uVar1) ||
      (*(int *)((ulonglong)uVar1 * 0x568 + 0x548 + *(longlong *)(param_1 + 0x338)) == 0)) ||
     (plVar6 = vmqFindFilter(param_1,uVar1,*(int *)(param_2 + 0xc)), plVar6 == (longlong *)0x0)) {
    return -0x3ffffff3;
  }
  iVar5 = vmqClearFilterOnMNics(param_1,(longlong)plVar6);
  if (iVar5 == 0) {
    lVar2 = *plVar6;
    if ((*(longlong **)(lVar2 + 8) != plVar6) ||
       (plVar3 = (longlong *)plVar6[1], (longlong *)*plVar3 != plVar6)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      return -0x3ffffff3;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    ExFreePoolWithTag(plVar6,0x5156544e);
  }
  return iVar5;
}



===== vmqClearFilterOnMNic @ 1c0013da4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void vmqClearFilterOnMNic
               (longlong param_1,longlong param_2,int param_3,ulonglong param_4,longlong param_5)

{
  ulonglong uVar1;
  undefined1 auStackY_58 [32];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  local_24 = 0;
  uVar1 = (ulonglong)(param_3 - 1);
  local_28 = 0x100180;
  local_20 = *(undefined4 *)
              (*(longlong *)(param_1 + 0x338) + ((param_4 & 0xffffffff) * 0x15a + uVar1) * 4);
  local_1c = *(undefined4 *)(param_5 + 0x10 + uVar1 * 4);
  vmqcIssueOidRequest(param_2,0x10228,1,&local_28,0x10);
  *(undefined4 *)(param_5 + 0x10 + uVar1 * 4) = 0;
  return;
}



===== vmqClearFilterOnMNics @ 1c0013e44 =====

int vmqClearFilterOnMNics(longlong param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  int iVar4;
  int local_res8 [2];
  longlong local_res10;
  
  uVar1 = *(uint *)(param_2 + 0x11c);
  puVar3 = *(undefined8 **)(param_1 + -0x98);
  iVar4 = 0;
  do {
    if (puVar3 == (undefined8 *)(param_1 + -0x98)) {
      local_res8[0] = 0;
      local_res10 = 0;
LAB_1c0013e80:
      iVar2 = 0;
      if (local_res10 != 0) {
        while( true ) {
          iVar4 = iVar2;
          if (*(int *)(param_2 + 0x10 + (ulonglong)(local_res8[0] - 1) * 4) != 0) {
            iVar2 = vmqClearFilterOnMNic(param_1,local_res10,local_res8[0],(ulonglong)uVar1,param_2)
            ;
            if (iVar2 != 0) {
              iVar4 = iVar2;
            }
          }
          vmqcGetNextMNic(param_1,&local_res10,local_res8);
          if (local_res10 == 0) break;
          iVar2 = iVar4;
        }
      }
      return iVar4;
    }
    local_res8[0] = *(int *)(puVar3 + 8);
    if (local_res8[0] != 0) {
      local_res10 = puVar3[-4] + 0x1af8;
      goto LAB_1c0013e80;
    }
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



===== vmqClearFiltersOnMNic @ 1c0013ef8 =====

void vmqClearFiltersOnMNic(longlong param_1,longlong param_2,int param_3,longlong param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  
  plVar1 = (longlong *)(param_4 + 0x550);
  plVar2 = (longlong *)*plVar1;
  if (plVar2 != plVar1) {
    do {
      if (*(int *)((longlong)plVar2 + (ulonglong)(param_3 - 1) * 4 + 0x10) != 0) {
        vmqClearFilterOnMNic
                  (param_1,param_2,param_3,(ulonglong)*(uint *)(param_4 + 0x10c),(longlong)plVar2);
      }
      plVar2 = (longlong *)*plVar2;
    } while (plVar2 != plVar1);
  }
  return;
}



===== vmqEnumFilters @ 1c0013f84 =====

undefined8 vmqEnumFilters(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  longlong lVar6;
  int iVar7;
  
  *(undefined4 *)(param_2 + 0x3c) = 0;
  puVar2 = *(undefined4 **)(param_2 + 0x28);
  if ((puVar2 == (undefined4 *)0x0) || (*(uint *)(param_2 + 0x30) < 0x1c)) {
    *(undefined4 *)(param_2 + 0x40) = 0;
    *(undefined4 *)(param_2 + 0x44) = 0x1c;
  }
  else {
    if ((*(byte *)((longlong)puVar2 + 1) < 2) || (*(ushort *)((longlong)puVar2 + 2) < 0x1c)) {
      *(undefined4 *)(param_2 + 0x40) = 4;
      return 0xc00000bb;
    }
    lVar6 = (ulonglong)(uint)puVar2[1] * 0x568 + *(longlong *)(param_1 + 0x338);
    puVar4 = puVar2 + 7;
    *(undefined4 *)(param_2 + 0x40) = 0x1c;
    if ((*(uint *)(param_1 + 0x18) < (uint)puVar2[1]) || (*(int *)(lVar6 + 0x548) == 0)) {
      return 0xc000000d;
    }
    puVar1 = (undefined8 *)(lVar6 + 0x550);
    iVar7 = 0;
    for (puVar3 = (undefined8 *)*puVar1; puVar3 != puVar1; puVar3 = (undefined8 *)*puVar3) {
      iVar7 = iVar7 + 1;
    }
    uVar5 = iVar7 * 0x10 + 0x1c;
    if (uVar5 <= *(uint *)(param_2 + 0x34)) {
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[2] = 0x1c;
      puVar2[4] = 0x10;
      *puVar2 = 0x1c0280;
      puVar2[3] = iVar7;
      for (puVar3 = (undefined8 *)*puVar1; puVar3 != puVar1; puVar3 = (undefined8 *)*puVar3) {
        *puVar4 = 0x100180;
        puVar4[3] = *(undefined4 *)(puVar3 + 0x24);
        puVar4[2] = *(undefined4 *)(puVar3 + 0x23);
        puVar4[1] = *(undefined4 *)((longlong)puVar3 + 0x114);
        puVar4 = puVar4 + 4;
      }
      *(uint *)(param_2 + 0x3c) = uVar5;
      return 0;
    }
    *(uint *)(param_2 + 0x44) = uVar5;
  }
  return 0xc0010016;
}



===== vmqEnumQueues @ 1c00140b4 =====

undefined8 vmqEnumQueues(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined4 *puVar8;
  
  iVar3 = *(int *)(param_1 + 0x330) * 0x448;
  iVar1 = *(int *)(param_2 + 4);
  puVar2 = *(undefined4 **)(param_2 + 0x28);
  uVar6 = iVar3 + 0x458;
  if (iVar1 != 2) {
    uVar6 = iVar3 + 0x10;
  }
  if ((puVar2 == (undefined4 *)0x0) || (*(uint *)(param_2 + 0x30) < uVar6)) {
    *(undefined4 *)(param_2 + 0x34) = 0;
    uVar4 = 0xc0010016;
    *(uint *)(param_2 + 0x38) = uVar6;
  }
  else {
    *puVar2 = 0x100180;
    uVar7 = 1;
    puVar2[3] = 0x448;
    puVar8 = puVar2 + 4;
    puVar2[1] = 0x10;
    iVar3 = *(int *)(param_1 + 0x330);
    puVar2[2] = iVar3;
    if (iVar1 == 2) {
      puVar2[2] = iVar3 + 1;
      uVar7 = 0;
    }
    for (; (uint)uVar7 <= *(uint *)(param_1 + 0x18); uVar7 = (ulonglong)((uint)uVar7 + 1)) {
      lVar5 = uVar7 * 0x568 + *(longlong *)(param_1 + 0x338);
      if (*(int *)(lVar5 + 0x548) != 0) {
        vmqSetQueueInfo(puVar8,lVar5);
        puVar8 = puVar8 + 0x112;
      }
    }
    *(uint *)(param_2 + 0x34) = uVar6;
    uVar4 = 0;
  }
  return uVar4;
}



===== vmqEqualRcvFilterCaps @ 1c0014194 =====

ulonglong vmqEqualRcvFilterCaps(longlong param_1,longlong param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)*(uint *)(param_2 + 8);
  if ((((((*(uint *)(param_1 + 8) == *(uint *)(param_2 + 8)) &&
         (uVar2 = (ulonglong)*(uint *)(param_2 + 0xc),
         *(uint *)(param_1 + 0xc) == *(uint *)(param_2 + 0xc))) &&
        (uVar2 = (ulonglong)*(uint *)(param_2 + 0x14),
        *(uint *)(param_1 + 0x14) == *(uint *)(param_2 + 0x14))) &&
       ((uVar2 = (ulonglong)*(uint *)(param_2 + 0x18),
        *(uint *)(param_1 + 0x18) == *(uint *)(param_2 + 0x18) &&
        (uVar2 = (ulonglong)*(uint *)(param_2 + 0x1c),
        *(uint *)(param_1 + 0x1c) == *(uint *)(param_2 + 0x1c))))) &&
      ((uVar2 = (ulonglong)*(uint *)(param_2 + 0x20),
       *(uint *)(param_1 + 0x20) == *(uint *)(param_2 + 0x20) &&
       ((uVar2 = (ulonglong)*(uint *)(param_2 + 0x10),
        *(uint *)(param_1 + 0x10) == *(uint *)(param_2 + 0x10) &&
        (uVar2 = (ulonglong)*(uint *)(param_2 + 0x24),
        *(uint *)(param_1 + 0x24) == *(uint *)(param_2 + 0x24))))))) &&
     ((uVar2 = (ulonglong)*(uint *)(param_2 + 0x2c),
      *(uint *)(param_1 + 0x2c) == *(uint *)(param_2 + 0x2c) &&
      ((uVar2 = (ulonglong)*(uint *)(param_2 + 0x28),
       *(uint *)(param_1 + 0x28) == *(uint *)(param_2 + 0x28) &&
       (uVar2 = (ulonglong)*(uint *)(param_2 + 0x30),
       *(uint *)(param_1 + 0x30) == *(uint *)(param_2 + 0x30))))))) {
    uVar1 = *(uint *)(param_2 + 0x34);
    uVar2 = (ulonglong)uVar1;
    if (*(uint *)(param_1 + 0x34) == uVar1) {
      return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
    }
  }
  return uVar2 & 0xffffffffffffff00;
}



===== vmqFindFilter @ 1c0014204 =====

undefined8 * vmqFindFilter(longlong param_1,uint param_2,int param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  if ((param_2 <= *(uint *)(param_1 + 0x18)) &&
     (*(int *)(*(longlong *)(param_1 + 0x338) + 0x548 + (ulonglong)param_2 * 0x568) != 0)) {
    puVar2 = (undefined8 *)(*(longlong *)(param_1 + 0x338) + 0x550 + (ulonglong)param_2 * 0x568);
    for (puVar1 = (undefined8 *)*puVar2; puVar1 != puVar2; puVar1 = (undefined8 *)*puVar1) {
      if (*(int *)(puVar1 + 0x24) == param_3) {
        return puVar1;
      }
    }
  }
  return (undefined8 *)0x0;
}



===== vmqFreeQueue @ 1c0014260 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int vmqFreeQueue(longlong param_1,longlong param_2)

{
  uint uVar1;
  int iVar2;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  uVar1 = *(uint *)(param_2 + 8);
  if (((uVar1 == 0) || (*(uint *)(param_1 + 0x18) < uVar1)) ||
     (*(int *)((ulonglong)uVar1 * 0x568 + 0x548 + *(longlong *)(param_1 + 0x338)) == 0)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    iVar2 = vmqFreeQueueOnMNics(param_1,uVar1);
    if (iVar2 == 0) {
      local_20 = *(undefined4 *)(param_2 + 8);
      local_24 = 0;
      local_28 = 0x100180;
      local_1c = 3;
      vmqcGenerateStatusIndication(param_1,0x4002000d,&local_28,0x10);
      memset((void *)((ulonglong)*(uint *)(param_2 + 8) * 0x568 + *(longlong *)(param_1 + 0x338)),0,
             0x568);
    }
  }
  return iVar2;
}



===== vmqFreeQueueOnMNic @ 1c0014334 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void vmqFreeQueueOnMNic(longlong param_1,int param_2,longlong param_3)

{
  int iVar1;
  undefined1 auStackY_68 [32];
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_68;
  local_34 = 0;
  local_30 = *(uint *)(param_3 + (ulonglong)(param_2 - 1U) * 4);
  local_38 = 0xc0180;
  KeClearEvent(param_1 + 0x1a8);
  iVar1 = vmqcIssueOidRequest(param_1,0x10224,1,&local_38,0xc);
  if (iVar1 == 0) {
    *(undefined4 *)(*(longlong *)(param_1 + 0x1a0) + (ulonglong)local_30 * 4) = 0;
    *(int *)(param_1 + 0x198) = *(int *)(param_1 + 0x198) + -1;
    *(undefined4 *)(param_3 + (ulonglong)(param_2 - 1U) * 4) = 0;
  }
  return;
}



===== vmqFreeQueueOnMNics @ 1c00143e0 =====

int vmqFreeQueueOnMNics(longlong param_1,uint param_2)

{
  int iVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong local_res8;
  int local_res10 [2];
  
  iVar3 = 0;
  puVar2 = *(undefined8 **)(param_1 + -0x98);
  do {
    if (puVar2 == (undefined8 *)(param_1 + -0x98)) {
      local_res10[0] = 0;
      local_res8 = 0;
LAB_1c0014413:
      if (local_res8 != 0) {
        iVar3 = 0;
        do {
          if ((*(int *)(*(longlong *)(param_1 + 0x338) +
                       ((ulonglong)(local_res10[0] - 1) + (ulonglong)param_2 * 0x15a) * 4) != 0) &&
             (iVar1 = vmqFreeQueueOnMNic(local_res8,local_res10[0],
                                         (ulonglong)param_2 * 0x568 + *(longlong *)(param_1 + 0x338)
                                        ), iVar1 != 0)) {
            iVar3 = iVar1;
          }
          vmqcGetNextMNic(param_1,&local_res8,local_res10);
        } while (local_res8 != 0);
      }
      return iVar3;
    }
    local_res10[0] = *(int *)(puVar2 + 8);
    if (local_res10[0] != 0) {
      local_res8 = puVar2[-4] + 0x1af8;
      goto LAB_1c0014413;
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== vmqIndicateNewCaps @ 1c001449c =====

void vmqIndicateNewCaps(longlong param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  longlong lVar9;
  
  lVar9 = 3;
  puVar5 = (undefined8 *)(param_1 + 8);
  puVar6 = (undefined8 *)(param_1 + 0x19c);
  do {
    puVar8 = puVar6;
    puVar7 = puVar5;
    uVar1 = puVar8[1];
    uVar2 = puVar8[2];
    uVar3 = puVar8[3];
    *puVar7 = *puVar8;
    puVar7[1] = uVar1;
    uVar1 = puVar8[4];
    uVar4 = puVar8[5];
    puVar7[2] = uVar2;
    puVar7[3] = uVar3;
    uVar2 = puVar8[6];
    uVar3 = puVar8[7];
    puVar7[4] = uVar1;
    puVar7[5] = uVar4;
    uVar1 = puVar8[8];
    uVar4 = puVar8[9];
    puVar7[6] = uVar2;
    puVar7[7] = uVar3;
    uVar2 = puVar8[10];
    uVar3 = puVar8[0xb];
    puVar7[8] = uVar1;
    puVar7[9] = uVar4;
    uVar1 = puVar8[0xc];
    uVar4 = puVar8[0xd];
    puVar7[10] = uVar2;
    puVar7[0xb] = uVar3;
    uVar2 = puVar8[0xe];
    uVar3 = puVar8[0xf];
    puVar7[0xc] = uVar1;
    puVar7[0xd] = uVar4;
    puVar7[0xe] = uVar2;
    puVar7[0xf] = uVar3;
    lVar9 = lVar9 + -1;
    puVar5 = puVar7 + 0x10;
    puVar6 = puVar8 + 0x10;
  } while (lVar9 != 0);
  uVar1 = puVar8[0x11];
  puVar7[0x10] = puVar8[0x10];
  puVar7[0x11] = uVar1;
  vmqcGenerateStatusIndication(param_1,0x40020020,param_1 + 0xd0,0x54);
  vmqcGenerateStatusIndication(param_1,0x40020050,param_1 + 0x124,0x74);
  if (*(char *)(param_1 + 0x32c) != '\0') {
    vmqcGenerateStatusIndication(param_1,0x40020010,param_1 + 8,0x54);
    vmqcGenerateStatusIndication(param_1,0x40020040,param_1 + 0x5c,0x74);
    if (*(char *)(param_1 + 0x32c) != '\0') {
      vmqAllocateTNicQueueArray(param_1);
    }
  }
  return;
}



===== vmqIndicateQueueAllocState @ 1c001459c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void vmqIndicateQueueAllocState(longlong param_1,char param_2)

{
  undefined1 auStack_1c8 [32];
  undefined4 local_1a8 [100];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1c8;
  memset(local_1a8,0,400);
  if (param_2 == '\0') {
    vmqClearCapabilities(local_1a8);
    vmqcGenerateStatusIndication(param_1,0x40020010,local_1a8,0x54);
  }
  return;
}



===== vmqInitMNicState @ 1c0014620 =====

void vmqInitMNicState(undefined8 *param_1,undefined8 param_2)

{
  void *_Dst;
  
  *param_1 = param_2;
  vmqcIssueOidRequest((longlong)param_1,0x1022d,0,param_1 + 1,0x54);
  vmqcIssueOidRequest((longlong)param_1,0x10221,0,param_1 + 0x1a,0x54);
  vmqcIssueOidRequest((longlong)param_1,0x1022f,0,(void *)((longlong)param_1 + 0x5c),0x74);
  vmqcIssueOidRequest((longlong)param_1,0x1022e,0,(void *)((longlong)param_1 + 0x124),0x74);
  if (*(int *)(param_1 + 3) != 0) {
    _Dst = (void *)ExAllocatePoolWithTagPriority
                             (0x200,(ulonglong)(*(int *)(param_1 + 3) + 1) << 2,0x5156544e,0x10);
    param_1[0x34] = _Dst;
    if (_Dst == (void *)0x0) {
      memset((void *)((longlong)param_1 + 9),0,0x53);
      *(undefined4 *)(param_1 + 1) = 0x540280;
      memset((void *)((longlong)param_1 + 0x5d),0,0x73);
      *(undefined4 *)((longlong)param_1 + 0x5c) = 0x200180;
    }
    else {
      memset(_Dst,0,(ulonglong)(*(int *)(param_1 + 3) + 1) << 2);
      KeInitializeEvent(param_1 + 0x35,0,0);
    }
  }
  return;
}



===== vmqInterceptOidRequest @ 1c0014760 =====

undefined8 vmqInterceptOidRequest(longlong param_1,longlong param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  ushort uVar4;
  undefined2 local_res10;
  undefined1 local_res12;
  byte bVar5;
  undefined1 uVar6;
  code *pcVar7;
  
  iVar2 = *(int *)(param_2 + 4);
  local_res10 = 0;
  local_res12 = 0;
  if (iVar2 == 0) {
LAB_1c001494c:
    iVar2 = *(int *)(param_2 + 0x20);
    if (iVar2 == 0x10221) {
      pcVar7 = vmqQueryRcvFilterHwCaps;
LAB_1c00149be:
      uVar4 = 0x54;
      uVar6 = 2;
    }
    else {
      if (iVar2 == 0x10222) {
        uVar4 = 0x10;
        pcVar7 = vmqQueryRcvFilterGlobalParams;
      }
      else {
        if (iVar2 == 0x10225) {
          uVar3 = vmqEnumQueues(param_1,param_2);
          goto LAB_1c00147fa;
        }
        if (iVar2 == 0x1022d) {
          pcVar7 = vmqQueryRcvFilterCaps;
          goto LAB_1c00149be;
        }
        if ((iVar2 != 0x1022e) && (iVar2 != 0x1022f)) {
          return 0;
        }
        pcVar7 = vmqQueryNicSwitchHwCaps;
        uVar4 = 0x20;
      }
      uVar6 = 1;
    }
    uVar3 = vmqVerifyQueryOidParamsAndCallHandler(param_1,param_2,param_3,uVar4,uVar6,pcVar7);
    goto LAB_1c00149d6;
  }
  if (iVar2 == 1) {
    iVar2 = *(int *)(param_2 + 0x20);
    if (iVar2 == 0x10224) {
      uVar3 = vmqVerifySetOidParamsAndCallHandler(param_1,param_2,param_3,0xc,1,vmqFreeQueue);
      if (*param_3 == 0) {
        NdisAcquireRWLockRead(*(undefined8 *)(*(longlong *)(param_1 + -0xb0) + 0x88),&local_res10,0)
        ;
        piVar1 = (int *)(param_1 + 0x330);
        *piVar1 = *piVar1 + -1;
        if ((*piVar1 == 0) && (*(char *)(param_1 + 0x198) != '\0')) {
          iVar2 = *param_3;
          *(undefined8 *)(param_1 + 0x350) = 0;
          NdisMOidRequestComplete(*(undefined8 *)(param_1 + -0xd8),param_2,iVar2);
          vmqIndicateNewCaps(param_1);
          *(undefined1 *)(param_1 + 0x198) = 0;
          *param_3 = 0x103;
        }
        uVar3 = NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + -0xb0) + 0x88),
                                  &local_res10);
      }
    }
    else {
      if (iVar2 == 0x10226) {
        uVar4 = 0x444;
        pcVar7 = vmqChangeQueueParams;
        bVar5 = 2;
      }
      else {
        if (iVar2 != 0x10228) {
          return 0;
        }
        pcVar7 = vmqClearFilter;
        uVar4 = 0x10;
        bVar5 = 1;
      }
      uVar3 = vmqVerifySetOidParamsAndCallHandler(param_1,param_2,param_3,uVar4,bVar5,pcVar7);
    }
    goto LAB_1c00149d6;
  }
  if (iVar2 == 2) goto LAB_1c001494c;
  if (iVar2 != 0xc) {
    return 0;
  }
  iVar2 = *(int *)(param_2 + 0x20);
  if (iVar2 == 0x10223) {
    uVar4 = 0x444;
    pcVar7 = vmqAllocateQueue;
LAB_1c0014818:
    bVar5 = 2;
  }
  else {
    if (iVar2 == 0x10226) {
      uVar4 = 0x444;
      pcVar7 = vmqQueryQueueParams;
      goto LAB_1c0014818;
    }
    if (iVar2 == 0x10227) {
      uVar4 = 0x2c;
      pcVar7 = vmqSetFilter;
      goto LAB_1c0014818;
    }
    if (iVar2 == 0x10229) {
      uVar3 = vmqEnumFilters(param_1,param_2);
LAB_1c00147fa:
      *param_3 = (int)uVar3;
      goto LAB_1c00149d6;
    }
    if (iVar2 == 0x1022a) {
      uVar3 = vmqQueryFilterParams(param_1,param_2);
      goto LAB_1c00147fa;
    }
    if (iVar2 != 0x1022b) {
      return 0;
    }
    uVar4 = 0x14;
    pcVar7 = vmqQueueAllocationComplete;
    bVar5 = 1;
  }
  uVar3 = vmqVerifyMethodOidParamsAndCallHandler(param_1,param_2,param_3,uVar4,bVar5,pcVar7);
LAB_1c00149d6:
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== vmqQueryFilterParams @ 1c00149f0 =====

undefined8 vmqQueryFilterParams(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  uint uVar3;
  int iVar4;
  
  *(undefined4 *)(param_2 + 0x3c) = 0;
  lVar1 = *(longlong *)(param_2 + 0x28);
  iVar4 = 0x2c;
  if ((lVar1 == 0) || (*(uint *)(param_2 + 0x30) < 0x2c)) {
    *(undefined4 *)(param_2 + 0x40) = 0;
    *(undefined4 *)(param_2 + 0x44) = 0x2c;
  }
  else {
    if ((*(byte *)(lVar1 + 1) < 2) || (*(ushort *)(lVar1 + 2) < 0x2c)) {
      *(undefined4 *)(param_2 + 0x40) = 4;
      return 0xc00000bb;
    }
    puVar2 = vmqFindFilter(param_1,*(uint *)(lVar1 + 0xc),*(int *)(lVar1 + 0x10));
    *(int *)(param_2 + 0x40) = iVar4;
    if (puVar2 == (undefined8 *)0x0) {
      return 0xc000000d;
    }
    uVar3 = *(int *)((longlong)puVar2 + 300) * *(int *)(puVar2 + 0x25) + iVar4;
    if (uVar3 <= *(uint *)(param_2 + 0x34)) {
      memcpy(*(void **)(param_2 + 0x28),puVar2 + 0x22,(ulonglong)uVar3);
      *(uint *)(param_2 + 0x3c) = uVar3;
      return 0;
    }
    *(uint *)(param_2 + 0x44) = uVar3;
  }
  return 0xc0010016;
}



===== vmqQueryNicSwitchHwCaps @ 1c0014aa0 =====

undefined8 vmqQueryNicSwitchHwCaps(longlong param_1,void *param_2)

{
  memcpy(param_2,(void *)(param_1 + 0x5c),(ulonglong)*(ushort *)((longlong)param_2 + 2));
  return 0;
}



===== vmqQueryQueueParams @ 1c0014ad0 =====

undefined8 vmqQueryQueueParams(longlong param_1,void *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  size_t _Size;
  
  uVar1 = *(uint *)((longlong)param_2 + 0xc);
  if (((uVar1 == 0) || (*(uint *)(param_1 + 0x18) < uVar1)) ||
     (*(int *)((ulonglong)uVar1 * 0x568 + 0x548 + *(longlong *)(param_1 + 0x338)) == 0)) {
    uVar2 = 0xc000000d;
  }
  else {
    _Size = 0x448;
    if (*(ushort *)((longlong)param_2 + 2) < 0x448) {
      _Size = (size_t)*(ushort *)((longlong)param_2 + 2);
    }
    memcpy(param_2,(void *)((ulonglong)uVar1 * 0x568 + *(longlong *)(param_1 + 0x338) + 0x100),_Size
          );
    uVar2 = 0;
  }
  return uVar2;
}



===== vmqQueryRcvFilterCaps @ 1c0014b40 =====

undefined8 vmqQueryRcvFilterCaps(longlong param_1,void *param_2)

{
  memcpy(param_2,(void *)(param_1 + 8),(ulonglong)*(ushort *)((longlong)param_2 + 2));
  return 0;
}



===== vmqQueryRcvFilterGlobalParams @ 1c0014b70 =====

undefined8 vmqQueryRcvFilterGlobalParams(longlong param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0x14);
  return 0;
}



===== vmqQueryRcvFilterHwCaps @ 1c0014b90 =====

undefined8 vmqQueryRcvFilterHwCaps(longlong param_1,void *param_2)

{
  memcpy(param_2,(void *)(param_1 + 0xd0),(ulonglong)*(ushort *)((longlong)param_2 + 2));
  return 0;
}



===== vmqQueueAllocationComplete @ 1c0014bc0 =====

undefined8 vmqQueueAllocationComplete(longlong param_1,void *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  void *_Dst;
  _IMPLAT_ADAPTER *p_Var5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ulong uVar11;
  undefined2 local_res10;
  undefined1 local_res12;
  int local_res18;
  ulonglong local_res20;
  
  if (*(int *)((longlong)param_2 + 0xc) != 0) {
    uVar8 = *(int *)((longlong)param_2 + 0xc) * *(int *)((longlong)param_2 + 0x10) +
            *(int *)((longlong)param_2 + 8);
    _Dst = (void *)ExAllocatePoolWithTagPriority(0x200,uVar8,0x5156544e,0x10);
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    for (uVar10 = *(uint *)((longlong)param_2 + 8); uVar10 < uVar8;
        uVar10 = uVar10 + *(int *)((longlong)param_2 + 0x10)) {
      *(undefined4 *)((ulonglong)uVar10 + 0xc + (longlong)param_2) = 0xc0000001;
    }
    uVar11 = 1;
    do {
      local_res10 = 0;
      local_res12 = 0;
      NdisAcquireRWLockWrite(*(undefined8 *)(*(longlong *)(param_1 + -0xb0) + 0x88),&local_res10);
      p_Var5 = implatFindAdapterByPortNumber
                         ((_IMPLAT_VIRTMINI *)(param_1 + -0xf8),uVar11,
                          (_IMPLAT_INTERNAL_BINDING **)0x0);
      NdisReleaseRWLock(*(undefined8 *)(*(longlong *)(param_1 + -0xb0) + 0x88),&local_res10);
      uVar6 = -(ulonglong)(p_Var5 != (_IMPLAT_ADAPTER *)0x0) & (ulonglong)(p_Var5 + 0x1af8);
      local_res20 = uVar6;
      if (uVar6 != 0) {
        memcpy(_Dst,param_2,(ulonglong)uVar8);
        uVar10 = *(uint *)((longlong)param_2 + 8);
        if (uVar10 < uVar8) {
          iVar3 = *(int *)((longlong)param_2 + 0x10);
          uVar9 = uVar10;
          do {
            iVar1 = *(int *)(*(longlong *)(param_1 + 0x338) +
                            ((ulonglong)*(uint *)((ulonglong)uVar9 + 8 + (longlong)param_2) * 0x15a
                            + (ulonglong)(uVar11 - 1)) * 4);
            if (iVar1 == 0) {
              uVar10 = uVar10 - iVar3;
              *(int *)((longlong)_Dst + 0xc) = *(int *)((longlong)_Dst + 0xc) + -1;
            }
            else {
              *(undefined4 *)((ulonglong)uVar10 + 0xc + (longlong)_Dst) = 0;
              *(int *)((ulonglong)uVar10 + 8 + (longlong)_Dst) = iVar1;
            }
            iVar3 = *(int *)((longlong)param_2 + 0x10);
            uVar9 = uVar9 + iVar3;
            uVar10 = uVar10 + iVar3;
          } while (uVar9 < uVar8);
          uVar6 = local_res20;
        }
        if (*(int *)((longlong)_Dst + 0xc) != 0) {
          iVar3 = vmqcIssueOidRequest(uVar6,0x1022b,0xc,_Dst,uVar8);
          uVar10 = *(uint *)((longlong)_Dst + 8);
          uVar9 = 0;
          local_res18 = iVar3;
          if (*(int *)((longlong)_Dst + 0xc) != 0) {
            do {
              uVar2 = *(uint *)(*(longlong *)(uVar6 + 0x1a0) +
                               (ulonglong)*(uint *)((ulonglong)uVar10 + 8 + (longlong)_Dst) * 4);
              if ((iVar3 == 0) && (*(int *)((ulonglong)uVar10 + 0xc + (longlong)_Dst) == 0)) {
                for (uVar4 = *(uint *)((longlong)param_2 + 8); uVar4 < uVar8;
                    uVar4 = uVar4 + *(int *)((longlong)param_2 + 0x10)) {
                  if (*(uint *)((ulonglong)uVar4 + 8 + (longlong)param_2) == uVar2) {
                    *(undefined4 *)((ulonglong)uVar4 + 0xc + (longlong)param_2) = 0;
                  }
                }
              }
              else {
                lVar7 = (ulonglong)uVar2 * 0x568;
                vmqClearFiltersOnMNic
                          (param_1,local_res20,uVar11,*(longlong *)(param_1 + 0x338) + lVar7);
                uVar6 = local_res20;
                vmqFreeQueueOnMNic(local_res20,uVar11,*(longlong *)(param_1 + 0x338) + lVar7);
                iVar3 = local_res18;
              }
              uVar10 = uVar10 + *(int *)((longlong)_Dst + 0x10);
              uVar9 = uVar9 + 1;
            } while (uVar9 < *(uint *)((longlong)_Dst + 0xc));
          }
        }
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < 0x41);
    for (uVar10 = *(uint *)((longlong)param_2 + 8); uVar10 < uVar8;
        uVar10 = uVar10 + *(int *)((longlong)param_2 + 0x10)) {
      if (*(int *)((ulonglong)uVar10 + 0xc + (longlong)param_2) == 0) {
        *(undefined4 *)
         ((ulonglong)*(uint *)((ulonglong)uVar10 + 8 + (longlong)param_2) * 0x568 + 0x548 +
         *(longlong *)(param_1 + 0x338)) = 2;
      }
    }
    ExFreePoolWithTag(_Dst,0x5156544e);
  }
  return 0;
}



===== vmqSetFilter @ 1c0014e80 =====

int vmqSetFilter(longlong param_1,void *param_2)

{
  longlong *plVar1;
  code *pcVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  longlong *_Dst;
  undefined8 *puVar6;
  uint uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  uint uVar10;
  size_t _Size;
  int local_res8 [2];
  longlong local_res10;
  
  iVar5 = 0;
  uVar10 = *(int *)((longlong)param_2 + 0x1c) * *(int *)((longlong)param_2 + 0x18);
  uVar4 = *(uint *)((longlong)param_2 + 0xc);
  if ((uVar4 <= *(uint *)(param_1 + 0x18)) && (uVar4 != 0)) {
    if (*(int *)((ulonglong)uVar4 * 0x568 + 0x548 + *(longlong *)(param_1 + 0x338)) == 0) {
      return -0x3ffffff3;
    }
    bVar3 = true;
    if (*(int *)((longlong)param_2 + 0x10) == 0) {
      uVar7 = 1;
      puVar9 = (undefined8 *)((ulonglong)uVar4 * 0x568 + *(longlong *)(param_1 + 0x338) + 0x550);
      for (puVar6 = (undefined8 *)*puVar9; (puVar6 != puVar9 && (*(uint *)(puVar6 + 0x24) <= uVar7))
          ; puVar6 = (undefined8 *)*puVar6) {
        uVar7 = uVar7 + 1;
      }
      uVar4 = 0;
      if (uVar7 <= *(uint *)(param_1 + 0x2c)) {
        uVar4 = uVar7;
      }
      *(uint *)((longlong)param_2 + 0x10) = uVar4;
      if (uVar4 == 0) {
        return -0x3fffff66;
      }
    }
    _Dst = (longlong *)
           ExAllocatePoolWithTagPriority(0x200,(ulonglong)uVar10 + 0x140,0x5156544e,0x10);
    if (_Dst == (longlong *)0x0) {
      return -0x3fffff66;
    }
    memset(_Dst,0,0x140);
    _Size = (size_t)*(ushort *)((longlong)param_2 + 2);
    if (0x2b < *(ushort *)((longlong)param_2 + 2)) {
      _Size = 0x2c;
    }
    memcpy(_Dst + 0x22,param_2,_Size);
    *(undefined4 *)((longlong)_Dst + 0x124) = 0x2c;
    memcpy((void *)((longlong)_Dst + 0x13c),
           (void *)((ulonglong)*(uint *)((longlong)param_2 + 0x14) + (longlong)param_2),
           (ulonglong)uVar10);
    for (puVar6 = *(undefined8 **)(param_1 + -0x98); puVar6 != (undefined8 *)(param_1 + -0x98);
        puVar6 = (undefined8 *)*puVar6) {
      local_res8[0] = *(int *)(puVar6 + 8);
      if (local_res8[0] != 0) {
        local_res10 = puVar6[-4] + 0x1af8;
        goto LAB_1c0014fbf;
      }
    }
    local_res8[0] = 0;
    local_res10 = 0;
LAB_1c0014fbf:
    if (local_res10 != 0) {
      do {
        if ((*(int *)(*(longlong *)(param_1 + 0x338) +
                     ((ulonglong)*(uint *)((longlong)param_2 + 0xc) * 0x15a +
                     (ulonglong)(local_res8[0] - 1)) * 4) != 0) &&
           (iVar5 = vmqSetFilterOnMNic(param_1,local_res10,local_res8[0],(longlong)_Dst), iVar5 != 0
           )) goto LAB_1c0015038;
        vmqcGetNextMNic(param_1,&local_res10,local_res8);
      } while (local_res10 != 0);
      if (iVar5 != 0) {
LAB_1c0015038:
        vmqClearFilterOnMNics(param_1,(longlong)_Dst);
        ExFreePoolWithTag(_Dst,0x5156544e);
        return iVar5;
      }
    }
    uVar4 = *(uint *)((longlong)param_2 + 0x10);
    *(uint *)(_Dst + 0x24) = uVar4;
    *(undefined4 *)((longlong)_Dst + 0x11c) = *(undefined4 *)((longlong)param_2 + 0xc);
    lVar8 = (ulonglong)*(uint *)((longlong)param_2 + 0xc) * 0x568 + *(longlong *)(param_1 + 0x338);
    for (puVar6 = *(undefined8 **)(lVar8 + 0x550); puVar6 != (undefined8 *)(lVar8 + 0x550);
        puVar6 = (undefined8 *)*puVar6) {
      if (uVar4 < *(uint *)(puVar6 + 0x24)) {
        if (!bVar3) goto LAB_1c00150a5;
        plVar1 = (longlong *)(lVar8 + 0x550);
        lVar8 = *plVar1;
        if (*(longlong **)(lVar8 + 8) == plVar1) {
          *_Dst = lVar8;
          _Dst[1] = (longlong)plVar1;
          *(longlong **)(lVar8 + 8) = _Dst;
          *plVar1 = (longlong)_Dst;
          return 0;
        }
        goto LAB_1c00150e6;
      }
      bVar3 = false;
    }
    puVar6 = (undefined8 *)(lVar8 + 0x550);
LAB_1c00150a5:
    puVar9 = (undefined8 *)puVar6[1];
    if ((undefined8 *)*puVar9 == puVar6) {
      *_Dst = (longlong)puVar6;
      _Dst[1] = (longlong)puVar9;
      *puVar9 = _Dst;
      puVar6[1] = _Dst;
      return 0;
    }
LAB_1c00150e6:
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(3);
  }
  return -0x3ffffff3;
}



===== vmqSetFilterOnMNic @ 1c0015110 =====

void vmqSetFilterOnMNic(longlong param_1,longlong param_2,int param_3,longlong param_4)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  bool bVar6;
  int iVar7;
  ulonglong uVar8;
  
  bVar6 = false;
  uVar2 = *(uint *)(param_4 + 0x11c);
  uVar3 = *(undefined4 *)(param_4 + 0x120);
  uVar8 = (ulonglong)*(uint *)(param_4 + 0x124);
  uVar4 = *(undefined4 *)
           (*(longlong *)(param_1 + 0x338) +
           ((ulonglong)uVar2 * 0x15a + (ulonglong)(param_3 - 1)) * 4);
  *(undefined4 *)(param_4 + 0x120) = 0;
  *(undefined4 *)(param_4 + 0x11c) = uVar4;
  if ((((*(int *)(param_4 + 0x128) == 1) && ((*(uint *)(param_2 + 0x28) & 8) != 0)) &&
      ((*(uint *)(param_1 + 0x28) & 8) == 0)) &&
     (((*(char *)(uVar8 + 0x111 + param_4) != '\0' && (0x37 < *(ushort *)(uVar8 + 0x112 + param_4)))
      && ((*(int *)(uVar8 + 0x120 + param_4) != 4 &&
          (uVar5 = *(uint *)(uVar8 + 0x114 + param_4), (uVar5 & 1) == 0)))))) {
    bVar6 = true;
    *(uint *)(uVar8 + 0x114 + param_4) = uVar5 | 1;
  }
  iVar7 = vmqcIssueOidRequest(param_2,0x10227,0xc,(void *)(param_4 + 0x110),
                              *(int *)(param_4 + 300) * *(int *)(param_4 + 0x128) + 0x2c);
  if (iVar7 == 0) {
    *(undefined4 *)(param_4 + 0x10 + (ulonglong)(param_3 - 1) * 4) =
         *(undefined4 *)(param_4 + 0x120);
  }
  *(undefined4 *)(param_4 + 0x120) = uVar3;
  *(uint *)(param_4 + 0x11c) = uVar2;
  if (bVar6) {
    puVar1 = (uint *)(uVar8 + 0x114 + param_4);
    *puVar1 = *puVar1 & 0xfffffffe;
  }
  return;
}



===== vmqSetNewCapabilities @ 1c0015234 =====

void vmqSetNewCapabilities(longlong param_1,undefined8 *param_2,char param_3,char param_4)

{
  ulonglong uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  
  if (*(char *)(param_1 + 0x32c) == '\0') {
    memset((void *)((longlong)param_2 + 4),0,0x50);
    *(undefined4 *)param_2 = 0x540280;
    memset((void *)((longlong)param_2 + 0x55),0,0x73);
    *(undefined4 *)((longlong)param_2 + 0x54) = 0x200180;
  }
  else {
    if (*(char *)(param_1 + 0x32d) == '\0') {
      *(undefined4 *)((longlong)param_2 + 0x34) = 0;
      *(undefined4 *)(param_2 + 6) = 0;
      *(uint *)((longlong)param_2 + 0x14) = *(uint *)((longlong)param_2 + 0x14) & 0xfffffffb;
    }
    if (*(char *)(param_1 + 0x32e) == '\0') {
      *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffff7;
      *(undefined4 *)(param_2 + 0xd) = 0;
    }
  }
  puVar6 = (undefined8 *)(param_1 + 8);
  uVar1 = vmqEqualRcvFilterCaps((longlong)puVar6,(longlong)param_2);
  if (((((((char)uVar1 != '\0') &&
         (uVar1 = vmqEqualRcvFilterCaps((longlong)(puVar6 + 0x19),(longlong)(param_2 + 0x19)),
         (char)uVar1 != '\0')) &&
        (*(int *)((longlong)puVar6 + 100) == *(int *)((longlong)param_2 + 100))) &&
       ((*(int *)(puVar6 + 0xd) == *(int *)(param_2 + 0xd) &&
        (*(int *)(puVar6 + 0xc) == *(int *)(param_2 + 0xc))))) &&
      ((*(int *)((longlong)puVar6 + 300) == *(int *)((longlong)param_2 + 300) &&
       ((*(int *)(puVar6 + 0x26) == *(int *)(param_2 + 0x26) &&
        (*(int *)(puVar6 + 0x25) == *(int *)(param_2 + 0x25))))))) && (param_4 == '\0')) {
    return;
  }
  lVar5 = 3;
  if (param_3 == '\0') {
    puVar2 = param_2;
    do {
      puVar7 = puVar6;
      puVar3 = puVar2;
      uVar4 = puVar3[1];
      *puVar7 = *puVar3;
      puVar7[1] = uVar4;
      uVar4 = puVar3[3];
      puVar7[2] = puVar3[2];
      puVar7[3] = uVar4;
      uVar4 = puVar3[5];
      puVar7[4] = puVar3[4];
      puVar7[5] = uVar4;
      uVar4 = puVar3[7];
      puVar7[6] = puVar3[6];
      puVar7[7] = uVar4;
      uVar4 = puVar3[9];
      puVar7[8] = puVar3[8];
      puVar7[9] = uVar4;
      uVar4 = puVar3[0xb];
      puVar7[10] = puVar3[10];
      puVar7[0xb] = uVar4;
      uVar4 = puVar3[0xd];
      puVar7[0xc] = puVar3[0xc];
      puVar7[0xd] = uVar4;
      uVar4 = puVar3[0xf];
      puVar7[0xe] = puVar3[0xe];
      puVar7[0xf] = uVar4;
      lVar5 = lVar5 + -1;
      puVar2 = puVar3 + 0x10;
      puVar6 = puVar7 + 0x10;
    } while (lVar5 != 0);
    uVar4 = puVar3[0x11];
    puVar7[0x10] = puVar3[0x10];
    puVar7[0x11] = uVar4;
    uVar4 = vmqAllocateTNicQueueArray(param_1);
    if ((char)uVar4 == '\0') {
      memset((void *)((longlong)param_2 + 4),0,0x50);
      *(undefined4 *)param_2 = 0x540280;
      memset((void *)((longlong)param_2 + 0x55),0,0x73);
      *(undefined4 *)((longlong)param_2 + 0x54) = 0x200180;
    }
  }
  else {
    puVar6 = (undefined8 *)(param_1 + 0x19c);
    do {
      puVar3 = param_2;
      puVar2 = puVar6;
      uVar4 = puVar3[1];
      *puVar2 = *puVar3;
      puVar2[1] = uVar4;
      uVar4 = puVar3[3];
      puVar2[2] = puVar3[2];
      puVar2[3] = uVar4;
      uVar4 = puVar3[5];
      puVar2[4] = puVar3[4];
      puVar2[5] = uVar4;
      uVar4 = puVar3[7];
      puVar2[6] = puVar3[6];
      puVar2[7] = uVar4;
      uVar4 = puVar3[9];
      puVar2[8] = puVar3[8];
      puVar2[9] = uVar4;
      uVar4 = puVar3[0xb];
      puVar2[10] = puVar3[10];
      puVar2[0xb] = uVar4;
      uVar4 = puVar3[0xd];
      puVar2[0xc] = puVar3[0xc];
      puVar2[0xd] = uVar4;
      uVar4 = puVar3[0xf];
      puVar2[0xe] = puVar3[0xe];
      puVar2[0xf] = uVar4;
      lVar5 = lVar5 + -1;
      puVar6 = puVar2 + 0x10;
      param_2 = puVar3 + 0x10;
    } while (lVar5 != 0);
    uVar4 = puVar3[0x11];
    puVar2[0x10] = puVar3[0x10];
    puVar2[0x11] = uVar4;
    if (*(char *)(param_1 + 0x198) == '\0') {
      vmqIndicateQueueAllocState(param_1,'\0');
      if (*(int *)(param_1 + 0x330) == 0) {
        vmqIndicateNewCaps(param_1);
      }
      else {
        *(undefined1 *)(param_1 + 0x198) = 1;
      }
    }
  }
  return;
}



===== vmqSetQueueInfo @ 1c0015488 =====

void vmqSetQueueInfo(undefined4 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined4 uVar6;
  longlong lVar7;
  int iVar8;
  longlong lVar9;
  
  *param_1 = 0x4480280;
  param_1[1] = *(undefined4 *)(param_2 + 0x104);
  param_1[0xc] = *(undefined4 *)(param_2 + 0x130);
  lVar7 = 4;
  param_1[0xb] = *(undefined4 *)(param_2 + 300);
  lVar9 = 4;
  param_1[10] = *(undefined4 *)(param_2 + 0x128);
  uVar2 = *(undefined8 *)(param_2 + 0x120);
  *(undefined8 *)(param_1 + 6) = *(undefined8 *)(param_2 + 0x118);
  *(undefined8 *)(param_1 + 8) = uVar2;
  param_1[4] = *(undefined4 *)(param_2 + 0x110);
  param_1[3] = *(undefined4 *)(param_2 + 0x10c);
  puVar3 = (undefined8 *)(param_2 + 0x338);
  puVar4 = (undefined8 *)(param_1 + 0x8e);
  do {
    uVar2 = puVar3[1];
    *puVar4 = *puVar3;
    puVar4[1] = uVar2;
    uVar2 = puVar3[3];
    puVar4[2] = puVar3[2];
    puVar4[3] = uVar2;
    uVar2 = puVar3[5];
    puVar4[4] = puVar3[4];
    puVar4[5] = uVar2;
    uVar2 = puVar3[7];
    puVar4[6] = puVar3[6];
    puVar4[7] = uVar2;
    uVar2 = puVar3[9];
    puVar4[8] = puVar3[8];
    puVar4[9] = uVar2;
    uVar2 = puVar3[0xb];
    puVar4[10] = puVar3[10];
    puVar4[0xb] = uVar2;
    uVar2 = puVar3[0xd];
    puVar4[0xc] = puVar3[0xc];
    puVar4[0xd] = uVar2;
    puVar5 = puVar4 + 0x10;
    puVar1 = puVar3 + 0xe;
    uVar2 = puVar3[0xf];
    puVar3 = puVar3 + 0x10;
    puVar4[0xe] = *puVar1;
    puVar4[0xf] = uVar2;
    lVar9 = lVar9 + -1;
    puVar4 = puVar5;
  } while (lVar9 != 0);
  *(undefined4 *)puVar5 = *(undefined4 *)puVar3;
  param_1[2] = *(undefined4 *)(param_2 + 0x108);
  puVar3 = (undefined8 *)(param_2 + 0x134);
  puVar4 = (undefined8 *)(param_1 + 0xd);
  do {
    uVar2 = puVar3[1];
    *puVar4 = *puVar3;
    puVar4[1] = uVar2;
    uVar2 = puVar3[3];
    puVar4[2] = puVar3[2];
    puVar4[3] = uVar2;
    uVar2 = puVar3[5];
    puVar4[4] = puVar3[4];
    puVar4[5] = uVar2;
    uVar2 = puVar3[7];
    puVar4[6] = puVar3[6];
    puVar4[7] = uVar2;
    uVar2 = puVar3[9];
    puVar4[8] = puVar3[8];
    puVar4[9] = uVar2;
    uVar2 = puVar3[0xb];
    puVar4[10] = puVar3[10];
    puVar4[0xb] = uVar2;
    uVar2 = puVar3[0xd];
    puVar4[0xc] = puVar3[0xc];
    puVar4[0xd] = uVar2;
    puVar5 = puVar4 + 0x10;
    puVar1 = puVar3 + 0xe;
    uVar2 = puVar3[0xf];
    puVar3 = puVar3 + 0x10;
    puVar4[0xe] = *puVar1;
    puVar4[0xf] = uVar2;
    lVar7 = lVar7 + -1;
    puVar4 = puVar5;
  } while (lVar7 != 0);
  iVar8 = 0;
  *(undefined4 *)puVar5 = *(undefined4 *)puVar3;
  puVar3 = (undefined8 *)(param_2 + 0x550);
  uVar6 = 1;
  for (puVar4 = (undefined8 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined8 *)*puVar4) {
    iVar8 = iVar8 + 1;
  }
  param_1[0x10f] = iVar8;
  param_1[0x110] = *(undefined4 *)(param_2 + 0x540);
  if ((*(int *)(param_2 + 0x548) != 2) || ((undefined8 *)*puVar3 == puVar3)) {
    uVar6 = 2;
  }
  param_1[5] = uVar6;
  return;
}



===== vmqSetQueueParamsOnMNic @ 1c00155f4 =====

int vmqSetQueueParamsOnMNic(longlong param_1,longlong param_2,int param_3,void *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  void *_Dst;
  
  uVar2 = 0x448;
  uVar1 = *(uint *)((longlong)param_4 + 0xc);
  if (*(ushort *)((longlong)param_4 + 2) < 0x448) {
    uVar2 = (uint)*(ushort *)((longlong)param_4 + 2);
  }
  _Dst = (void *)ExAllocatePoolWithTagPriority(0x200,uVar2,0x5156544e,0x10);
  if (_Dst == (void *)0x0) {
    iVar3 = -0x3fffff66;
  }
  else {
    memcpy(_Dst,param_4,(ulonglong)uVar2);
    *(undefined4 *)((longlong)_Dst + 0xc) =
         *(undefined4 *)
          (*(longlong *)(param_1 + 0x338) +
          ((ulonglong)uVar1 * 0x15a + (ulonglong)(param_3 - 1)) * 4);
    iVar3 = vmqcIssueOidRequest(param_2,0x10226,1,_Dst,uVar2);
    ExFreePoolWithTag(_Dst,0x5156544e);
  }
  return iVar3;
}



===== vmqUpdateRcvFilterCaps @ 1c00156e4 =====

void vmqUpdateRcvFilterCaps(longlong param_1,longlong param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  longlong lVar5;
  uint uVar6;
  
  uVar6 = *(uint *)(param_1 + 0x10);
  if (*(uint *)(param_2 + 0x10) <= *(uint *)(param_1 + 0x10)) {
    uVar6 = *(uint *)(param_2 + 0x10);
  }
  *(uint *)(param_1 + 0x10) = uVar6;
  uVar6 = *(uint *)(param_1 + 0x24);
  if (*(uint *)(param_2 + 0x24) <= *(uint *)(param_1 + 0x24)) {
    uVar6 = *(uint *)(param_2 + 0x24);
  }
  *(uint *)(param_1 + 0x24) = uVar6;
  puVar1 = (uint *)(param_1 + 0x14);
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & *(uint *)(param_2 + 8);
  lVar5 = 4;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & *(uint *)(param_2 + 0xc);
  puVar4 = puVar1;
  do {
    *puVar4 = *puVar4 & *(uint *)((param_2 - param_1) + (longlong)puVar4);
    puVar4 = puVar4 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  uVar6 = *(uint *)(param_1 + 0x30);
  if (*(uint *)(param_1 + 0x30) <= *(uint *)(param_2 + 0x30)) {
    uVar6 = *(uint *)(param_2 + 0x30);
  }
  *(uint *)(param_1 + 0x30) = uVar6;
  uVar3 = *(uint *)(param_1 + 0x34);
  if (*(uint *)(param_2 + 0x34) <= *(uint *)(param_1 + 0x34)) {
    uVar3 = *(uint *)(param_2 + 0x34);
  }
  uVar2 = *puVar1;
  *(uint *)(param_1 + 0x34) = uVar3;
  *puVar1 = uVar2 | 0x40;
  if (uVar3 < uVar6) {
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *puVar1 = uVar2 & 0xfffffffb | 0x40;
  }
  return;
}



===== vmqVerifyMethodOidParamsAndCallHandler @ 1c0015784 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void vmqVerifyMethodOidParamsAndCallHandler
               (undefined8 param_1,longlong param_2,int *param_3,ushort param_4,byte param_5,
               undefined *param_6)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  
  lVar1 = *(longlong *)(param_2 + 0x28);
  if (((lVar1 == 0) || (*(uint *)(param_2 + 0x30) < (uint)param_4)) ||
     (*(uint *)(param_2 + 0x34) < (uint)param_4)) {
    iVar2 = -0x3ffeffea;
    *(uint *)(param_2 + 0x44) = (uint)param_4;
    *(undefined4 *)(param_2 + 0x40) = 0;
  }
  else {
    if ((param_5 <= *(byte *)(lVar1 + 1)) && (param_4 <= *(ushort *)(lVar1 + 2))) {
      *(uint *)(param_2 + 0x40) = (uint)param_4;
      implatIncreaseGlobalPendingOperationsCount();
      iVar2 = (*(code *)param_6)(param_1,lVar1);
      *param_3 = iVar2;
      implatDecreaseGlobalPendingOperationsCount();
      iVar2 = *param_3;
      goto LAB_1c0015815;
    }
    *(undefined4 *)(param_2 + 0x40) = 4;
    iVar2 = -0x3fffff45;
  }
  *param_3 = iVar2;
LAB_1c0015815:
  uVar3 = (uint)param_4;
  if (iVar2 != 0) {
    uVar3 = 0;
  }
  *(uint *)(param_2 + 0x3c) = uVar3;
  return;
}



===== vmqVerifyQueryOidParamsAndCallHandler @ 1c0015840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void vmqVerifyQueryOidParamsAndCallHandler
               (undefined8 param_1,longlong param_2,int *param_3,ushort param_4,undefined1 param_5,
               undefined *param_6)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  
  puVar1 = *(undefined1 **)(param_2 + 0x28);
  uVar3 = 0;
  if ((puVar1 == (undefined1 *)0x0) || (*(uint *)(param_2 + 0x30) < (uint)param_4)) {
    *(uint *)(param_2 + 0x38) = (uint)param_4;
    *param_3 = -0x3ffeffea;
  }
  else {
    puVar1[1] = param_5;
    *puVar1 = 0x80;
    *(ushort *)(puVar1 + 2) = param_4;
    iVar2 = (*(code *)param_6)(param_1,puVar1);
    *param_3 = iVar2;
    if (iVar2 == 0) {
      uVar3 = (uint)*(ushort *)(puVar1 + 2);
    }
  }
  *(uint *)(param_2 + 0x34) = uVar3;
  return;
}



===== vmqVerifySetOidParamsAndCallHandler @ 1c00158c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void vmqVerifySetOidParamsAndCallHandler
               (undefined8 param_1,longlong param_2,undefined4 *param_3,ushort param_4,byte param_5,
               undefined *param_6)

{
  longlong lVar1;
  undefined4 uVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x28);
  if ((lVar1 == 0) || (*(uint *)(param_2 + 0x30) < (uint)param_4)) {
    *(undefined4 *)(param_2 + 0x34) = 0;
    *(uint *)(param_2 + 0x38) = (uint)param_4;
    *param_3 = 0xc0010016;
  }
  else if ((*(byte *)(lVar1 + 1) < param_5) || (*(ushort *)(lVar1 + 2) < param_4)) {
    *(undefined4 *)(param_2 + 0x34) = 4;
    *param_3 = 0xc00000bb;
  }
  else {
    implatIncreaseGlobalPendingOperationsCount();
    uVar2 = (*(code *)param_6)(param_1,lVar1);
    *param_3 = uVar2;
    implatDecreaseGlobalPendingOperationsCount();
  }
  return;
}



===== Microsoft_Windows_Networking_Correlation_EtwEnableCallback @ 1c0015950 =====

void Microsoft_Windows_Networking_Correlation_EtwEnableCallback
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,ulonglong param_4)

{
  LOCK();
  Microsoft_Windows_Networking_CorrelationEnabled = param_2;
  UNLOCK();
  LOCK();
  Microsoft_Windows_Networking_CorrelationTraceActivityPayload = (uint)(param_4 >> 3) & 1;
  UNLOCK();
  return;
}



===== __GSHandlerCheck @ 1c0015978 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c001599c =====

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



===== __cpu_features_init @ 1c0015a10 =====

/* WARNING: Removing unreachable block (ram,0x0001c0015a7a) */
/* WARNING: Removing unreachable block (ram,0x0001c0015a29) */
/* WARNING: Removing unreachable block (ram,0x0001c0015a1a) */

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



===== __security_check_cookie @ 1c0015ae0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0015b20 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0015b50 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0015b50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0015b80 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 1c0015be0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_1c0015c23;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1c0015c94;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1c0015c90:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0015c94;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1c0015c8c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0015c90;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0015c8c;
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
LAB_1c0015c94:
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
LAB_1c0015c23:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memcpy @ 1c0015d00 =====

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



===== memset @ 1c0016000 =====

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



===== __memset_repmovs @ 1c0016140 =====

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



===== __memset_query @ 1c00161c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0016240 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0016380 =====

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



===== __memset_spec_plain @ 1c0016400 =====

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



===== WppCleanupKm @ 1c001f008 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(void)

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
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
  }
  return;
}



===== WppInitKm @ 1c001f088 =====

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



===== WppLoadTracingSupport @ 1c001f118 =====

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



===== WppTraceCallback @ 1c001f260 =====

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



===== _tlgEnableCallback @ 1c001f4f0 =====

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



===== entry @ 1c0020010 =====

void entry(_DRIVER_OBJECT *param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c0020044 =====

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



===== DriverEntry @ 1c0020078 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DriverEntry(_DRIVER_OBJECT *param_1,undefined8 param_2)

{
  undefined2 uVar1;
  code *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  undefined1 auStack_1f8 [8];
  undefined1 auStack_1f0 [56];
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 uStack_188;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined8 local_158;
  code *local_150;
  code *local_148;
  code *local_140;
  code *local_138;
  code *local_130;
  undefined8 local_128;
  code *local_120;
  code *local_118;
  code *local_110;
  code *local_108;
  code *local_100;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined8 local_e8;
  code *local_e0;
  code *local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  code *local_a8;
  code *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  code *local_88;
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_68;
  ushort *local_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  ushort local_48 [12];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_1f8;
  memset(&local_178,0,0x80);
  uVar7 = 0;
  memset(&local_f8,0,0x98);
  _DAT_1c001b2c8 = 1;
  local_198 = 0;
  DAT_1c001b2a8 = &WPP_ThisDir_CTLGUID_NdisImPlatformWPPGuid;
  local_1b8 = 0;
  uStack_1b0 = 0;
  _WPP_MAIN_CB = 0;
  local_1a8 = 0;
  uStack_1a0 = 0;
  DAT_1c001b2b0 = 0;
  uStack_190 = 0;
  uStack_188 = 0;
  _DAT_1c001b2c0 = 0;
  WppLoadTracingSupport();
  _DAT_1c001b2c0 = 0;
  WppInitKm();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar7 = 10;
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_186dd776e650347706de1e499c297719_Traceguids);
  }
  uVar3 = McGenEventRegister_EtwRegister
                    (&NdisImPlatformEventProvider,uVar7,&NdisImPlatformEventProvider_Context,
                     &NdisImPlatformEventProvider_Context);
  uVar4 = NdisConvertNtStatusToNdisStatus(uVar3);
  puVar9 = auStack_1f8;
  uVar8 = (ulonglong)uVar4;
  if (uVar4 == 0) {
    DAT_1c001b290 = DAT_1c001b290 | 1;
    uVar3 = McGenEventRegister_EtwRegister
                      (&NdisImPlatformSysEvtProvider,uVar7,&NdisImPlatformSysEvtProvider_Context,
                       (longlong *)&NdisImPlatformSysEvtProvider_Context);
    uVar4 = NdisConvertNtStatusToNdisStatus(uVar3);
    puVar9 = auStack_1f8;
    uVar8 = (ulonglong)uVar4;
    if (uVar4 == 0) {
      DAT_1c001b290 = DAT_1c001b290 | 2;
      iVar5 = 0;
      if (Microsoft_Windows_Networking_CorrelationHandle == 0) {
        iVar5 = EtwRegister(&Microsoft_Windows_Networking_CorrelationId,
                            Microsoft_Windows_Networking_Correlation_EtwEnableCallback,0,
                            &Microsoft_Windows_Networking_CorrelationHandle);
        if (iVar5 == 0) goto LAB_1c0020202;
      }
      else {
LAB_1c0020202:
        _Microsoft_Windows_Networking_ProviderId = 0x11c5d8ad;
        uRam00000001c001b324 = 0x42c2756a;
        uRam00000001c001b328 = 0x1beb8780;
        uRam00000001c001b32c = 0x46a8724a;
      }
      uVar4 = NdisConvertNtStatusToNdisStatus(iVar5);
      puVar9 = auStack_1f8;
      uVar8 = (ulonglong)uVar4;
      if (uVar4 == 0) {
        DAT_1c001b290 = DAT_1c001b290 | 4;
        local_58 = *(ushort **)(PTR_DAT_1c001b0a8 + -0x10);
        uStack_50 = *(undefined4 *)(PTR_DAT_1c001b0a8 + -8);
        uStack_4c = *(undefined4 *)(PTR_DAT_1c001b0a8 + -4);
        puVar9 = auStack_1f8;
        if (DAT_1c001b0c0 != 0) {
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)(5);
          puVar9 = auStack_1f0;
        }
        _DAT_1c001b0c8 = 0;
        DAT_1c001b0d0 = 0;
        *(undefined8 *)(puVar9 + -8) = 0x1c002027f;
        iVar5 = EtwRegister(&local_58,_tlgEnableCallback,&DAT_1c001b0a0,&DAT_1c001b0c0);
        if (iVar5 == 0) {
          uVar1 = *(undefined2 *)PTR_DAT_1c001b0a8;
          *(undefined8 *)(puVar9 + -8) = 0x1c00202a4;
          EtwSetInformation(DAT_1c001b0c0,2,PTR_DAT_1c001b0a8,uVar1);
        }
        DAT_1c001b250 = &DAT_1c001b248;
        DAT_1c001b248 = &DAT_1c001b248;
        DAT_1c001b260 = &DAT_1c001b258;
        _DAT_1c001b258 = &DAT_1c001b258;
        DAT_1c001b270 = &DAT_1c001b268;
        DAT_1c001b268 = &DAT_1c001b268;
        *(undefined8 *)(puVar9 + -8) = 0x1c00202fd;
        KeInitializeMutex(&DAT_1c001b1f0,0xffff);
        DAT_1c001b1d8 = 0;
        _Global = 0;
        DAT_1c001b1e0 = 0;
        DAT_1c001b228 = 0;
        *(undefined8 *)(puVar9 + -8) = 0x1c0020338;
        DAT_1c001b1e8 = param_1;
        KeInitializeEvent(&DAT_1c001b230,0,1);
        *(undefined8 *)(puVar9 + -8) = 0x1c0020346;
        DAT_1c001b278 = NdisGroupMaxProcessorCount(0xffff);
        *(undefined8 *)(puVar9 + 0x40) = 0x280180;
        *(code **)(puVar9 + 0x48) = implatTeamQueryObject;
        *(code **)(puVar9 + 0x50) = implatTeamSetObject;
        *(undefined8 *)(puVar9 + 0x58) = 0;
        *(undefined8 *)(puVar9 + 0x60) = 0;
        *(undefined8 *)(puVar9 + -8) = 0x1c0020390;
        uVar4 = NdisIfRegisterProvider(puVar9 + 0x40,0,&DAT_1c001b1e0);
        uVar8 = (ulonglong)uVar4;
        if (uVar4 == 0) {
          local_f8 = 0x98028a;
          local_e0 = implatInitializeEx;
          local_f4 = 0x1013206;
          local_d8 = implatHaltEx;
          local_f0 = 0xd;
          local_d0 = implatDriverUnload;
          local_e8 = 0;
          local_c8 = implatPause;
          local_98 = 0;
          local_c0 = implatRestart;
          local_b8 = implatOidRequest;
          local_b0 = implatSendNetBufferLists;
          local_a8 = implatReturnNetBufferLists;
          local_a0 = implatCancelOidRequest;
          local_88 = implatCancelOidRequest;
          local_80 = implatShutdownEx;
          local_78 = implatCancelOidRequest;
          local_70 = implatDirectOidRequest;
          local_68 = implatCancelOidRequest;
          *(undefined8 **)(puVar9 + 0x20) = &DAT_1c001b1d8;
          local_90 = 0;
          *(undefined8 *)(puVar9 + -8) = 0x1c00204b8;
          uVar4 = NdisMRegisterMiniportDriver(param_1,param_2,0,&local_f8);
          uVar8 = (ulonglong)uVar4;
          if (uVar4 == 0) {
            local_178 = 0x800295;
            local_174 = 0x1013206;
            local_170 = 0x10000000;
            *(undefined8 *)(puVar9 + -8) = 0x1c0020524;
            RtlInitUnicodeString(puVar9 + 0x68,L"NdisImPlatform");
            local_168 = *(undefined4 *)(puVar9 + 0x68);
            uStack_164 = *(undefined4 *)(puVar9 + 0x6c);
            uStack_160 = *(undefined4 *)(puVar9 + 0x70);
            uStack_15c = *(undefined4 *)(puVar9 + 0x74);
            local_158 = 0;
            local_150 = implatBindAdapterEx;
            local_128 = 0;
            local_148 = implatUnbindAdapterEx;
            local_140 = implatOpenAdapterCompleteEx;
            local_138 = implatCloseAdapterCompleteEx;
            local_130 = implatNetPnPEvent;
            local_120 = implatOidRequestComplete;
            local_118 = implatStatusEx;
            local_110 = implatReceiveNetBufferLists;
            local_108 = implatSendNetBufferListsComplete;
            local_100 = implatDirectOidRequestComplete;
            *(undefined8 *)(puVar9 + -8) = 0x1c00205bd;
            uVar4 = NdisRegisterProtocolDriver(0,&local_178,&Global);
            uVar8 = (ulonglong)uVar4;
            if (uVar4 == 0) {
              *(undefined8 *)(puVar9 + -8) = 0x1c0020613;
              NdisIMAssociateMiniport(DAT_1c001b1d8,_Global);
              *(undefined8 *)(puVar9 + -8) = 0x1c002061d;
              uVar4 = implatControlDeviceRegister();
              uVar8 = (ulonglong)uVar4;
              if (uVar4 == 0) goto LAB_1c00206c9;
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (WPP_GLOBAL_Control[0x29] != '\0')) {
                uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
                *(undefined8 *)(puVar9 + -8) = 0x1c0020654;
                WPP_SF_D(uVar7,0xe,&WPP_186dd776e650347706de1e499c297719_Traceguids,uVar4);
              }
            }
            else {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (WPP_GLOBAL_Control[0x29] != '\0')) {
                uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
                *(undefined8 *)(puVar9 + -8) = 0x1c00205f5;
                WPP_SF_D(uVar7,0xd,&WPP_186dd776e650347706de1e499c297719_Traceguids,uVar4);
              }
              _Global = 0;
            }
          }
          else {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (WPP_GLOBAL_Control[0x29] != '\0')) {
              uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
              *(undefined8 *)(puVar9 + -8) = 0x1c00204f0;
              WPP_SF_D(uVar7,0xc,&WPP_186dd776e650347706de1e499c297719_Traceguids,uVar4);
            }
            DAT_1c001b1d8 = 0;
          }
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (WPP_GLOBAL_Control[0x29] != '\0')) {
            uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
            *(undefined8 *)(puVar9 + -8) = 0x1c00203c8;
            WPP_SF_D(uVar7,0xb,&WPP_186dd776e650347706de1e499c297719_Traceguids,uVar4);
          }
          DAT_1c001b1e0 = 0;
        }
      }
    }
  }
  if ((DAT_1c001b290 & 2) != 0) {
    *(undefined8 *)(puVar9 + -8) = 0x1c0020678;
    lVar6 = RtlStringCbPrintfW(local_48,0x18,(ushort *)L"0x%x",uVar8);
    if (-1 < lVar6) {
      local_58 = local_48;
      *(undefined8 *)(puVar9 + 0x30) = 0;
      *(undefined4 *)(puVar9 + 0x28) = 0;
      *(ushort ***)(puVar9 + 0x20) = &local_58;
      *(undefined8 *)(puVar9 + -8) = 0x1c00206bc;
      NdisWriteEventLogEntry(DAT_1c001b1e8,0x80004267,0,1);
    }
  }
  *(undefined8 *)(puVar9 + -8) = 0x1c00206c9;
  implatDriverUnload(param_1);
LAB_1c00206c9:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar9 + -8) = 0x1c00206f6;
    WPP_SF_D(uVar7,0xf,&WPP_186dd776e650347706de1e499c297719_Traceguids,(int)uVar8);
  }
  *(undefined8 *)(puVar9 + -8) = 0x1c00206ff;
  NdisConvertNdisStatusToNtStatus(uVar8);
  *(undefined8 *)(puVar9 + -8) = 0x1c0020713;
  return;
}


