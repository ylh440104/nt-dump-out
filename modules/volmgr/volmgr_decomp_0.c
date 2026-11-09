
===== Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>_> @ 140001008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: static long __cdecl _tlgWriteTemplate<long __cdecl(struct _tlgProvider_t const *
   __ptr64,void const * __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned
   int,struct _EVENT_DATA_DESCRIPTOR * __ptr64),&long __cdecl
   _tlgWriteTransfer_EtwWriteTransfer(struct _tlgProvider_t const * __ptr64,void const *
   __ptr64,struct _GUID const * __ptr64,struct _GUID const * __ptr64,unsigned int,struct
   _EVENT_DATA_DESCRIPTOR * __ptr64),struct _GUID const * __ptr64,struct _GUID const *
   __ptr64>::Write<struct _tlgWrapperByRef<16>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct _tlgWrapperByVal<1>,struct
   _tlgWrapperByVal<1> >(struct _tlgProvider_t const * __ptr64,void const * __ptr64,struct _GUID
   const * __ptr64,struct _GUID const * __ptr64,struct _tlgWrapperByRef<16> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64,struct _tlgWrapperByVal<1> const & __ptr64,struct
   _tlgWrapperByVal<1> const & __ptr64) */

long __cdecl
_tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
::
Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>_>
          (_tlgProvider_t *param_1,void *param_2,_GUID *param_3,_GUID *param_4,
          _tlgWrapperByRef<16> *param_5,_tlgWrapperByVal<1> *param_6,_tlgWrapperByVal<1> *param_7,
          _tlgWrapperByVal<1> *param_8,_tlgWrapperByVal<1> *param_9,_tlgWrapperByVal<1> *param_10)

{
  long lVar1;
  undefined1 auStackY_c8 [32];
  undefined8 local_98 [4];
  undefined8 local_78;
  undefined8 local_70;
  _tlgWrapperByVal<1> *local_68;
  undefined8 local_60;
  _tlgWrapperByVal<1> *local_58;
  undefined8 local_50;
  _tlgWrapperByVal<1> *local_48;
  undefined8 local_40;
  _tlgWrapperByVal<1> *local_38;
  undefined8 local_30;
  _tlgWrapperByVal<1> *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_28 = param_10;
  local_38 = param_9;
  local_48 = param_8;
  local_58 = param_7;
  local_68 = param_6;
  local_20 = 1;
  local_30 = 1;
  local_40 = 1;
  local_78 = *(undefined8 *)param_5;
  local_50 = 1;
  local_60 = 1;
  local_70 = 0x10;
  lVar1 = _tlgWriteTransfer_EtwWriteTransfer(0x14000b048,param_2,0,0,8,local_98);
  return lVar1;
}



===== _tlgKeywordOn @ 1400010c8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _tlgKeywordOn(void)

{
  if (((_DAT_14000b058 & 0x400000000000) == 0) ||
     ((DAT_14000b060 & 0x400000000000) != DAT_14000b060)) {
    return 0;
  }
  return CONCAT71((int7)((DAT_14000b060 & 0x400000000000) >> 8),1);
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 1400010fc =====

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



===== VmpZeroRefCallback @ 1400011a0 =====

/* long __cdecl VmpZeroRefCallback(class VM_VOLUME_EXTENSION * __ptr64,long (__cdecl*)(class
   VM_VOLUME_EXTENSION * __ptr64,void * __ptr64),void * __ptr64) */

long __cdecl
VmpZeroRefCallback(VM_VOLUME_EXTENSION *param_1,_func_long_VM_VOLUME_EXTENSION_ptr_void_ptr *param_2
                  ,void *param_3)

{
  long lVar1;
  undefined1 uVar2;
  
  VmpAcquireRundown(param_1);
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  LOCK();
  *(undefined4 *)(param_1 + 0x3c) = 0;
  UNLOCK();
  *(_func_long_VM_VOLUME_EXTENSION_ptr_void_ptr **)(param_1 + 0x40) = param_2;
  *(void **)(param_1 + 0x48) = param_3;
  KeReleaseSpinLock(param_1 + 0x18,uVar2);
  KeClearEvent(param_1 + 0x88);
  VmpDecrementRefCount(param_1);
  KeWaitForSingleObject(param_1 + 0x88,0,0,0,0);
  lVar1 = *(long *)(param_1 + 0x48);
  VmpReleaseRundown(param_1);
  return lVar1;
}



===== VmDeviceControl @ 140001260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Type propagation algorithm not settling */

long VmDeviceControl(longlong param_1,_LIST_ENTRY *param_2)

{
  VM_ROOT_EXTENSION *pVVar1;
  _LIST_ENTRY *p_Var2;
  VM_VOLUME_EXTENSION *pVVar3;
  VM_VOLUME_EXTENSION VVar4;
  uint uVar5;
  VM_ROOT_EXTENSION *pVVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  longlong *plVar9;
  longlong *******ppppppplVar10;
  code *pcVar11;
  bool bVar12;
  VM_VOLUME_EXTENSION *pVVar13;
  undefined1 uVar14;
  byte bVar15;
  long lVar16;
  undefined4 uVar17;
  int iVar18;
  long lVar19;
  longlong lVar20;
  VM_VOLUME_EXTENSION *pVVar21;
  _LIST_ENTRY *p_Var22;
  VM_VOLUME_EXTENSION *pVVar23;
  VM_VOLUME_EXTENSION *pVVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  undefined1 *puVar27;
  undefined1 *puVar28;
  _LIST_ENTRY *p_Var29;
  undefined8 uStack_70;
  undefined1 auStack_68 [32];
  longlong *******local_38;
  VM_VOLUME_EXTENSION *local_30;
  
  puVar28 = auStack_68;
  puVar27 = auStack_68;
  puVar26 = auStack_68;
  pVVar24 = *(VM_VOLUME_EXTENSION **)(param_1 + 0x40);
  lVar19 = 0;
  pVVar21 = *(VM_VOLUME_EXTENSION **)(param_2 + 0xb8);
  pVVar6 = *(VM_ROOT_EXTENSION **)(pVVar24 + 8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar5 = *(uint *)(pVVar21 + 0x18);
  if (*(int *)(pVVar24 + 0x10) == 0) {
    if (uVar5 == 0x76c3b0) {
switchD_140001ded_caseD_764328:
      if (*(longlong *)(pVVar6 + 0x188) == 0) {
switchD_140001ded_caseD_764329:
        puVar27 = auStack_68;
        lVar19 = -0x3ffffff0;
        goto LAB_14000156b;
      }
      VmpAcquireAll(pVVar6);
      VmpRestoreExtensionDriver((longlong)pVVar6);
      lVar19 = (**(code **)(*(longlong *)(pVVar6 + 0x188) + 0x60))(param_2);
      VmpPageExtensionDriver((longlong)pVVar6);
    }
    else {
      if (0x76c340 < uVar5) {
        switch(uVar5) {
        case 0x76c344:
        case 0x76c348:
        case 0x76c34c:
        case 0x76c350:
        case 0x76c354:
        case 0x76c358:
        case 0x76c35c:
        case 0x76c360:
        case 0x76c364:
        case 0x76c368:
        case 0x76c36c:
        case 0x76c370:
        case 0x76c374:
        case 0x76c378:
        case 0x76c37c:
        case 0x76c380:
        case 0x76c384:
        case 0x76c388:
        case 0x76c38c:
        case 0x76c390:
        case 0x76c3a4:
        case 0x76c3a8:
          goto switchD_140001ded_caseD_764328;
        default:
          goto switchD_140001ded_caseD_764329;
        }
      }
      if (uVar5 == 0x76c340) {
        lVar19 = VmpCheckDynamicDiskConversion(pVVar6,(_IRP *)param_2);
        puVar27 = auStack_68;
        if (lVar19 < 0) goto LAB_14000156b;
        goto switchD_140001ded_caseD_764328;
      }
      if (0x764324 < uVar5) {
        switch(uVar5) {
        case 0x764328:
        case 0x76432c:
        case 0x764330:
        case 0x764334:
        case 0x764338:
        case 0x76433c:
        case 0x764394:
        case 0x764398:
        case 0x76439c:
        case 0x7643a0:
        case 0x7643ac:
          goto switchD_140001ded_caseD_764328;
        default:
          goto switchD_140001ded_caseD_764329;
        }
      }
      if (uVar5 == 0x764324) goto switchD_140001ded_caseD_764328;
      if (uVar5 != 0x760320) goto switchD_140001ded_caseD_764329;
      VmpAcquireAll(pVVar6);
      lVar19 = VmpQueryCapabilities(pVVar6,(_IRP *)param_2);
    }
    puVar27 = auStack_68;
    VmpReleaseAll(pVVar6);
    if (lVar19 == 0x103) {
      return 0x103;
    }
LAB_14000156b:
    *(long *)(param_2 + 0x30) = lVar19;
    *(undefined8 *)(puVar27 + -8) = 0x14000157b;
    IofCompleteRequest(param_2,0);
    return lVar19;
  }
  p_Var29 = param_2;
  if (uVar5 == 0x4d0008) {
    uVar14 = KeAcquireSpinLockRaiseToDpc(pVVar24 + 0x18);
    if (*(longlong *)(pVVar24 + 0x40) != 0) {
LAB_140001489:
      puVar27 = auStack_68;
      pVVar21 = pVVar24 + 0x18;
      p_Var22 = *(_LIST_ENTRY **)(param_2 + 0xb8);
      pVVar23 = pVVar24 + 0xa0;
      p_Var29 = param_2 + 0xa8;
      p_Var22[3] = (_LIST_ENTRY)((byte)p_Var22[3] | 1);
      puVar7 = *(undefined8 **)(pVVar24 + 0xa8);
      pVVar13 = local_30;
      if ((VM_VOLUME_EXTENSION *)*puVar7 != pVVar23) goto LAB_140001c3f;
      *(VM_VOLUME_EXTENSION **)p_Var29 = pVVar23;
      *(undefined8 **)(param_2 + 0xb0) = puVar7;
      *puVar7 = p_Var29;
      *(_LIST_ENTRY **)(pVVar24 + 0xa8) = p_Var29;
      KeReleaseSpinLock(pVVar21,uVar14);
      return 0x103;
    }
    if (pVVar24[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
      if (*(longlong *)(pVVar24 + 0x178) == 0) goto LAB_14000151d;
LAB_1400012ea:
      bVar12 = true;
    }
    else {
      if (*(longlong *)(pVVar24 + 0x1d0) != 0) goto LAB_1400012ea;
LAB_14000151d:
      bVar12 = false;
    }
    if (pVVar24[0xbc] != (VM_VOLUME_EXTENSION)0x0) {
      if ((bVar12) && (pVVar24[0xc0] == (VM_VOLUME_EXTENSION)0x0)) {
        LOCK();
        *(undefined4 *)(pVVar24 + 0x3c) = 1;
        UNLOCK();
      }
      LOCK();
      *(int *)(pVVar24 + 0x38) = *(int *)(pVVar24 + 0x38) + 1;
      UNLOCK();
      KeReleaseSpinLock(pVVar24 + 0x18,uVar14);
      lVar16 = VmpQueryDeviceName(pVVar24,(_IRP *)param_2);
      LOCK();
      pVVar21 = pVVar24 + 0x38;
      iVar18 = *(int *)pVVar21;
      *(int *)pVVar21 = *(int *)pVVar21 + -1;
      UNLOCK();
      if (iVar18 == 1) {
        bVar15 = KeAcquireSpinLockRaiseToDpc(pVVar24 + 0x18);
        pVVar21 = (VM_VOLUME_EXTENSION *)(ulonglong)bVar15;
        if (*(code **)(pVVar24 + 0x40) == (code *)0x0) {
          KeReleaseSpinLock(pVVar24 + 0x18,pVVar21);
        }
        else {
          p_Var22 = *(_LIST_ENTRY **)(pVVar24 + 0x48);
          uVar17 = (**(code **)(pVVar24 + 0x40))(pVVar24);
          *(undefined4 *)(pVVar24 + 0x48) = uVar17;
          *(undefined8 *)(pVVar24 + 0x40) = 0;
          LOCK();
          *(int *)(pVVar24 + 0x38) = *(int *)(pVVar24 + 0x38) + 1;
          UNLOCK();
          pVVar3 = pVVar24 + 0xa0;
          ppppppplVar10 = *(longlong ********)pVVar3;
          pVVar23 = pVVar24;
          puVar27 = auStack_68;
          pVVar13 = local_30;
          if ((VM_VOLUME_EXTENSION *)ppppppplVar10[1] != pVVar3) goto LAB_140001c3f;
          p_Var22 = (_LIST_ENTRY *)&local_38;
          ppppppplVar10[1] = (longlong ******)p_Var22;
          *(longlong *********)pVVar3 = &local_38;
          local_30 = *(VM_VOLUME_EXTENSION **)(pVVar24 + 0xa8);
          puVar27 = auStack_68;
          local_38 = ppppppplVar10;
          pVVar13 = pVVar3;
          if (*(VM_VOLUME_EXTENSION **)local_30 != pVVar3) goto LAB_140001c3f;
          *(longlong *********)local_30 = &local_38;
          *(VM_VOLUME_EXTENSION **)(pVVar24 + 0xa8) = pVVar3;
          *(VM_VOLUME_EXTENSION **)pVVar3 = pVVar3;
          KeReleaseSpinLock(pVVar24 + 0x18,pVVar21);
          KeSetEvent(pVVar24 + 0x88,0,0);
          if ((longlong ********)local_38 != &local_38) {
            p_Var22 = (_LIST_ENTRY *)&local_38;
            VmpProcessIrpQueueAtDispatchLevel(pVVar24,p_Var22);
            if ((longlong ********)local_38 != &local_38) {
              lVar20 = IoAllocateWorkItem(*(undefined8 *)pVVar24);
              if (lVar20 == 0) {
                while( true ) {
                  if ((longlong ********)local_38 == &local_38) break;
                  puVar27 = auStack_68;
                  pVVar13 = local_30;
                  if ((longlong ********)local_38[1] != &local_38) goto LAB_140001c3f;
                  ppppppplVar10 = (longlong *******)*local_38;
                  puVar27 = auStack_68;
                  if ((longlong *******)ppppppplVar10[1] != local_38) goto LAB_140001c3f;
                  ppppppplVar10[1] = (longlong ******)&local_38;
                  p_Var22 = (_LIST_ENTRY *)0x0;
                  *(undefined4 *)(local_38 + -0xf) = 0xc000009a;
                  local_38[-0xe] = (longlong ******)0x0;
                  local_38 = ppppppplVar10;
                  IofCompleteRequest();
                }
              }
              else {
                p_Var22 = (_LIST_ENTRY *)&local_38;
                puVar27 = auStack_68;
                pVVar13 = local_30;
                if ((_LIST_ENTRY *)local_38[1] != p_Var22) goto LAB_140001c3f;
                p_Var22 = (_LIST_ENTRY *)&local_38;
                puVar27 = auStack_68;
                if (*(_LIST_ENTRY **)local_30 != p_Var22) goto LAB_140001c3f;
                *(longlong ********)local_30 = local_38;
                local_38[1] = (longlong ******)local_30;
                local_30 = (VM_VOLUME_EXTENSION *)&local_38;
                local_38 = (longlong *******)&local_38;
                IoQueueWorkItemEx(lVar20,VmpProcessIrpQueueWorkerRoutine,0);
              }
            }
          }
        }
      }
      goto LAB_140001345;
    }
LAB_1400014f3:
    KeReleaseSpinLock(pVVar24 + 0x18,uVar14);
    lVar16 = -0x3ffffff2;
LAB_140001345:
    *(long *)(param_2 + 0x30) = lVar16;
    IofCompleteRequest(param_2,0);
    return lVar16;
  }
  if (uVar5 == 0x560038) {
    KeWaitForSingleObject(pVVar6 + 0x38,0,0,0);
    KeWaitForSingleObject(pVVar6 + 0x70,0,0,0);
    pVVar1 = pVVar6 + 0xb8;
    if (*(VM_ROOT_EXTENSION **)pVVar1 != pVVar1) {
      VmpProcessDiskNotifications(pVVar6);
    }
    puVar27 = auStack_68;
    iVar18 = VmpGetGptAttributes(pVVar24,(_IRP *)param_2);
    if (*(VM_ROOT_EXTENSION **)pVVar1 != pVVar1) {
      VmpProcessDiskNotifications(pVVar6);
    }
    KeReleaseMutex(pVVar6 + 0x70,0);
    KeReleaseMutex(pVVar6 + 0x38,0);
    goto LAB_14000146e;
  }
  if (uVar5 < 0x560001) {
    if (uVar5 == 0x560000) {
LAB_140001876:
      lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01','\0');
      puVar28 = auStack_68;
      if (lVar19 == 0x103) {
        return 0x103;
      }
      if (lVar19 < 0) goto LAB_1400018b0;
      lVar19 = VmpGetVolumeDiskExtents(pVVar24,(_IRP *)param_2);
      puVar28 = auStack_68;
      goto LAB_1400018a6;
    }
    if (0x2d08c0 < uVar5) {
      if (uVar5 == 0x4d0018) {
        lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01','\0');
        puVar28 = auStack_68;
        if (lVar19 == 0x103) {
          return 0x103;
        }
        if (lVar19 < 0) goto LAB_1400018b0;
        lVar19 = VmpQueryStableGuid(pVVar24,(_IRP *)param_2);
        puVar28 = auStack_68;
      }
      else if (uVar5 < 0x4d0019) {
        if (uVar5 == 0x2d9404) {
          bVar15 = KeAcquireSpinLockRaiseToDpc(pVVar24 + 0x18);
          puVar26 = auStack_68;
          puVar25 = auStack_68;
          puVar27 = auStack_68;
          if (*(longlong *)(pVVar24 + 0x40) != 0) goto LAB_140001784;
          if (pVVar24[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
            if (*(longlong *)(pVVar24 + 0x178) == 0) goto LAB_1400018e5;
LAB_140001755:
            bVar12 = true;
          }
          else {
            if (*(longlong *)(pVVar24 + 0x1d0) != 0) goto LAB_140001755;
LAB_1400018e5:
            bVar12 = false;
          }
          puVar26 = auStack_68;
          if ((pVVar24[0xbc] == (VM_VOLUME_EXTENSION)0x0) || (puVar26 = auStack_68, !bVar12)) {
LAB_140001857:
            lVar19 = -0x3ffffff2;
            puVar27 = puVar26;
          }
          else if (pVVar24[0xc0] == (VM_VOLUME_EXTENSION)0x0) {
LAB_140001661:
            LOCK();
            *(undefined4 *)(pVVar24 + 0x3c) = 1;
            UNLOCK();
LAB_140001669:
            LOCK();
            *(int *)(pVVar24 + 0x38) = *(int *)(pVVar24 + 0x38) + 1;
            UNLOCK();
            puVar27 = puVar25;
          }
          else {
            lVar19 = -0x7ffffff0;
          }
LAB_14000166d:
          *(undefined8 *)(puVar27 + -8) = 0x140001678;
          KeReleaseSpinLock(pVVar24 + 0x18);
          goto LAB_14000167d;
        }
        if (uVar5 != 0x4d0000) {
          if (uVar5 == 0x4d000c) {
            VmpAcquireAll(pVVar6);
            iVar18 = VmpQuerySuggestedLinkName(pVVar24,(_IRP *)param_2);
            goto LAB_140001e76;
          }
          goto switchD_1400013c8_caseD_560005;
        }
        lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\0','\x01','\0');
        puVar28 = auStack_68;
        if (lVar19 == 0x103) {
          return 0x103;
        }
        if (lVar19 < 0) goto LAB_1400018b0;
        lVar19 = VmpQueryUniqueId(pVVar24,(_IRP *)param_2);
        puVar28 = auStack_68;
      }
      else {
        iVar18 = uVar5 - 0x4d001c;
        if (iVar18 != 0) goto LAB_140001c46;
        lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01','\0');
        puVar28 = auStack_68;
        if (lVar19 == 0x103) {
          return 0x103;
        }
        if (lVar19 < 0) goto LAB_1400018b0;
        lVar19 = VmpQueryInterfaceName(pVVar24,(_IRP *)param_2);
        puVar28 = auStack_68;
      }
      goto LAB_1400018a6;
    }
    if (uVar5 == 0x2d08c0) {
      lVar19 = VmpManageBypassIo(pVVar24,(_IRP *)param_2);
      return lVar19;
    }
    if (0x70224 < uVar5) {
      if (uVar5 == 0x74004) {
        lVar19 = VmpGetPartitionInfo(pVVar24,(_IRP *)param_2);
        return lVar19;
      }
      if (uVar5 == 0x7405c) {
        lVar19 = VmpGetLengthInfo(pVVar24,(_IRP *)param_2);
        return lVar19;
      }
      puVar26 = auStack_68;
      if (uVar5 == 0x7c064) goto switchD_140001ded_caseD_764329;
switchD_1400013c8_caseD_560005:
      do {
        *(undefined8 *)(puVar26 + -8) = 0x140001615;
        bVar15 = KeAcquireSpinLockRaiseToDpc(pVVar24 + 0x18);
        param_2 = p_Var29;
        if (*(longlong *)(pVVar24 + 0x40) == 0) {
          if (pVVar24[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
            if (*(longlong *)(pVVar24 + 0x178) == 0) goto LAB_14000186f;
LAB_140001641:
            bVar12 = true;
          }
          else {
            if (*(longlong *)(pVVar24 + 0x1d0) != 0) goto LAB_140001641;
LAB_14000186f:
            bVar12 = false;
          }
          if ((pVVar24[0xbc] == (VM_VOLUME_EXTENSION)0x0) || (!bVar12)) goto LAB_140001857;
          puVar25 = puVar26;
          if (pVVar24[0xc0] != (VM_VOLUME_EXTENSION)0x0) goto LAB_140001669;
          goto LAB_140001661;
        }
LAB_140001784:
        p_Var22 = (_LIST_ENTRY *)(ulonglong)bVar15;
        p_Var2 = param_2 + 0xa8;
        *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) =
             *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
        plVar9 = *(longlong **)(pVVar24 + 0xa8);
        pVVar23 = pVVar24;
        puVar27 = puVar26;
        p_Var29 = param_2;
        pVVar13 = local_30;
        if ((VM_VOLUME_EXTENSION *)*plVar9 == pVVar24 + 0xa0) {
          *(VM_VOLUME_EXTENSION **)p_Var2 = pVVar24 + 0xa0;
          lVar19 = 0x103;
          *(longlong **)(param_2 + 0xb0) = plVar9;
          *plVar9 = (longlong)p_Var2;
          *(_LIST_ENTRY **)(pVVar24 + 0xa8) = p_Var2;
          goto LAB_14000166d;
        }
LAB_140001c3f:
        local_30 = pVVar13;
        pcVar11 = (code *)swi(0x29);
        iVar18 = (*pcVar11)(3);
        puVar28 = puVar27 + 8;
        param_2 = p_Var22;
        pVVar24 = pVVar23;
LAB_140001c46:
        if (iVar18 == 0xbff4) {
          puVar28[0x20] = 0;
          *(undefined8 *)(puVar28 + -8) = 0x140001c65;
          lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01',puVar28[0x20]);
          if (lVar19 == 0x103) {
            return 0x103;
          }
          param_2 = p_Var29;
          if (lVar19 < 0) goto LAB_1400018b0;
          *(undefined8 *)(puVar28 + -8) = 0x140001c85;
          lVar19 = VmpLinkDeleted(pVVar24,(_IRP *)p_Var29);
          goto LAB_1400018a6;
        }
        puVar26 = puVar28;
      } while (iVar18 != 0xbff8);
      puVar28[0x20] = 0;
      *(undefined8 *)(puVar28 + -8) = 0x140001ea2;
      lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01',puVar28[0x20]);
      if (lVar19 == 0x103) {
        return 0x103;
      }
      param_2 = p_Var29;
      if (lVar19 < 0) goto LAB_1400018b0;
      *(undefined8 *)(puVar28 + -8) = 0x140001ec2;
      lVar19 = VmpLinkDeleted(pVVar24,(_IRP *)p_Var29);
      goto LAB_1400018a6;
    }
    if (uVar5 != 0x70224) {
      if (uVar5 == 0x70020) {
        iVar18 = VmpPerformance(pVVar24,(_IRP *)param_2);
        puVar27 = auStack_68;
        goto LAB_14000146e;
      }
      if (uVar5 == 0x70024) {
        if ((*(ulonglong *)(pVVar24 + 0x158) >> 0x3c & 1) == 0) {
          lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01','\x01');
          puVar27 = auStack_68;
          if (lVar19 == 0x103) {
            return 0x103;
          }
          if (-1 < lVar19) {
            lVar19 = VmpDiskIsWritable(pVVar24,(_IRP *)param_2);
            return lVar19;
          }
        }
        else {
          lVar19 = -0x3fffff5e;
        }
        goto LAB_14000156b;
      }
      if (uVar5 == 0x70048) {
        lVar19 = VmpGetPartitionInfoEx(pVVar24,(_IRP *)param_2);
        return lVar19;
      }
      puVar26 = auStack_68;
      if (uVar5 == 0x70060) {
        VmpPerformanceOff(pVVar24,(_IRP *)param_2);
        goto switchD_1400013c8_caseD_560004;
      }
      goto switchD_1400013c8_caseD_560005;
    }
    goto switchD_140001ded_caseD_764329;
  }
  if (0x564000 < uVar5) {
    if (uVar5 < 0x56c041) {
      if (uVar5 == 0x56c040) {
        lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01','\x01');
        puVar28 = auStack_68;
        if (lVar19 == 0x103) {
          return 0x103;
        }
        if (lVar19 < 0) goto LAB_1400018b0;
        lVar19 = VmpAllocateBCStream(pVVar24,(_IRP *)param_2);
        puVar28 = auStack_68;
      }
      else if (uVar5 == 0x56403c) {
        lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01','\0');
        puVar28 = auStack_68;
        if (lVar19 == 0x103) {
          return 0x103;
        }
        if (lVar19 < 0) goto LAB_1400018b0;
        lVar19 = VmpGetBCProperties(pVVar24,(_IRP *)param_2);
        puVar28 = auStack_68;
      }
      else {
        if (uVar5 != 0x564058) {
          if (uVar5 == 0x56c008) {
            lVar19 = VmpOnline(pVVar24,(_IRP *)param_2);
            return lVar19;
          }
          puVar26 = auStack_68;
          if (uVar5 == 0x56c00c) {
            lVar19 = VmpOffline(pVVar24,(_IRP *)param_2);
            return lVar19;
          }
          goto switchD_1400013c8_caseD_560005;
        }
        pVVar21 = pVVar24;
        lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01','\0');
        puVar28 = auStack_68;
        if (lVar19 == 0x103) {
          return 0x103;
        }
        if (lVar19 < 0) goto LAB_1400018b0;
        lVar19 = VmpQueryMinimumShrinkSize(pVVar21,(_IRP *)param_2);
        puVar28 = auStack_68;
      }
      goto LAB_1400018a6;
    }
    if (uVar5 == 0x56c044) {
      lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01','\x01');
      puVar28 = auStack_68;
      if (lVar19 == 0x103) {
        return 0x103;
      }
      if (lVar19 < 0) goto LAB_1400018b0;
      lVar19 = VmpFreeBCStream(pVVar24,(_IRP *)param_2);
      puVar28 = auStack_68;
      goto LAB_1400018a6;
    }
    if (uVar5 != 0x56c04c) {
      puVar26 = auStack_68;
      if (uVar5 != 0x56c05c) goto switchD_1400013c8_caseD_560005;
      pVVar21 = pVVar24;
      lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01','\0');
      puVar28 = auStack_68;
      if (lVar19 == 0x103) {
        return 0x103;
      }
      if (lVar19 < 0) goto LAB_1400018b0;
      lVar19 = VmpPrepareForShrink(pVVar21,(_IRP *)param_2);
      puVar28 = auStack_68;
      goto LAB_1400018a6;
    }
    pVVar21 = pVVar24 + 0x18;
    uVar14 = KeAcquireSpinLockRaiseToDpc(pVVar21);
    if (*(longlong *)(pVVar24 + 0x40) != 0) goto LAB_140001489;
    if (pVVar24[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
      if (*(longlong *)(pVVar24 + 0x178) == 0) goto LAB_1400018f9;
LAB_1400017fd:
      bVar12 = true;
    }
    else {
      if (*(longlong *)(pVVar24 + 0x1d0) != 0) goto LAB_1400017fd;
LAB_1400018f9:
      bVar12 = false;
    }
    if ((pVVar24[0xbc] != (VM_VOLUME_EXTENSION)0x0) && (bVar12)) {
      if (pVVar24[0xc0] == (VM_VOLUME_EXTENSION)0x0) {
        LOCK();
        *(undefined4 *)(pVVar24 + 0x3c) = 1;
        UNLOCK();
        LOCK();
        *(int *)(pVVar24 + 0x38) = *(int *)(pVVar24 + 0x38) + 1;
        UNLOCK();
        KeReleaseSpinLock(pVVar21,uVar14);
        lVar16 = VmpPrepareForShrink(pVVar21,(_IRP *)param_2);
        VmpDecrementRefCount(pVVar24);
      }
      else {
        KeReleaseSpinLock(pVVar21,uVar14);
        lVar16 = -0x7ffffff0;
      }
      goto LAB_140001345;
    }
    goto LAB_1400014f3;
  }
  if (uVar5 == 0x564000) goto LAB_140001876;
  puVar26 = auStack_68;
  switch(uVar5) {
  case 0x560004:
switchD_1400013c8_caseD_560004:
    *(undefined4 *)(param_2 + 0x30) = 0;
    IofCompleteRequest(param_2,0);
    return 0;
  default:
    goto switchD_1400013c8_caseD_560005;
  case 0x560010:
    lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01','\0');
    puVar28 = auStack_68;
    if (lVar19 == 0x103) {
      return 0x103;
    }
    if (lVar19 < 0) goto LAB_1400018b0;
    puVar27 = auStack_68;
    if (pVVar24[0xc0] == (VM_VOLUME_EXTENSION)0x0) {
      lVar19 = -0x3fffffff;
      puVar27 = auStack_68;
    }
    goto LAB_1400018a8;
  case 0x560014:
    lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01','\0');
    puVar28 = auStack_68;
    if (lVar19 == 0x103) {
      return 0x103;
    }
    puVar27 = auStack_68;
    if (lVar19 < 0) goto LAB_1400018b0;
    goto LAB_1400018a8;
  case 0x560018:
    VmpAcquireAll(pVVar6);
    iVar18 = VmpQueryFailoverSet(pVVar24,(_IRP *)param_2);
    goto LAB_140001e76;
  case 0x56001c:
    lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01','\0');
    puVar28 = auStack_68;
    if (lVar19 == 0x103) {
      return 0x103;
    }
    if (lVar19 < 0) goto LAB_1400018b0;
    lVar19 = VmpQueryVolumeNumber(pVVar24,(_IRP *)param_2);
    puVar28 = auStack_68;
    break;
  case 0x560020:
    lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01','\0');
    puVar28 = auStack_68;
    if (lVar19 == 0x103) {
      return 0x103;
    }
    if (lVar19 < 0) goto LAB_1400018b0;
    lVar19 = VmpLogicalToPhysical(pVVar24,(_IRP *)param_2);
    puVar28 = auStack_68;
    break;
  case 0x560024:
    lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01','\0');
    puVar28 = auStack_68;
    if (lVar19 == 0x103) {
      return 0x103;
    }
    if (lVar19 < 0) goto LAB_1400018b0;
    lVar19 = VmpPhysicalToLogical(pVVar24,(_IRP *)param_2);
    puVar28 = auStack_68;
    break;
  case 0x560028:
    lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01','\0');
    puVar28 = auStack_68;
    if (lVar19 == 0x103) {
      return 0x103;
    }
    if (lVar19 < 0) goto LAB_1400018b0;
    lVar19 = VmpIsPartition(pVVar24,(_IRP *)param_2);
    puVar28 = auStack_68;
    break;
  case 0x560034:
    lVar19 = VmpCheckSecurity(pVVar24,(_IRP *)param_2);
    puVar27 = auStack_68;
    if (lVar19 < 0) {
LAB_14000167d:
      if (lVar19 == 0x103) {
        return 0x103;
      }
      if (-1 < lVar19) {
        puVar7 = *(undefined8 **)(param_2 + 0xb8);
        VVar4 = pVVar24[0x1ca];
        puVar7[-9] = *puVar7;
        puVar7[-8] = puVar7[1];
        puVar7[-7] = puVar7[2];
        puVar7[-6] = puVar7[3];
        *(undefined4 *)(puVar7 + -5) = *(undefined4 *)(puVar7 + 4);
        *(undefined4 *)((longlong)puVar7 + -0x24) = *(undefined4 *)((longlong)puVar7 + 0x24);
        *(undefined4 *)(puVar7 + -4) = *(undefined4 *)(puVar7 + 5);
        *(undefined4 *)((longlong)puVar7 + -0x1c) = *(undefined4 *)((longlong)puVar7 + 0x2c);
        puVar7[-3] = puVar7[6];
        *(undefined1 *)((longlong)puVar7 + -0x45) = 0;
        lVar20 = *(longlong *)(param_2 + 0xb8);
        uVar5 = *(uint *)(pVVar21 + 0x18);
        *(code **)(lVar20 + -0x10) = VmpRefCountCompletionRoutine;
        *(ulonglong *)(lVar20 + -8) = (ulonglong)uVar5;
        *(undefined1 *)(lVar20 + -0x45) = 0xe0;
        if (VVar4 == (VM_VOLUME_EXTENSION)0x0) {
          uVar8 = *(undefined8 *)(pVVar24 + 0x178);
          *(undefined8 *)(puVar27 + -8) = 0x1400016fc;
          lVar19 = IofCallDriver(uVar8);
          return lVar19;
        }
        param_2[0x43] = (_LIST_ENTRY)((char)param_2[0x43] + -1);
        *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + -0x48;
        uVar8 = *(undefined8 *)(pVVar24 + 0x1d0);
        pcVar11 = *(code **)(*(longlong *)(pVVar6 + 0x188) + 0x68);
        *(undefined8 *)(puVar27 + -8) = 0x140001d76;
        iVar18 = (*pcVar11)(uVar8,param_2);
        if (iVar18 == 0x103) {
          return 0x103;
        }
        goto LAB_14000146e;
      }
      goto LAB_14000156b;
    }
    VmpAcquireAll(pVVar6);
    iVar18 = VmpSetGptAttributes(pVVar24,(_IRP *)param_2);
    goto LAB_140001e76;
  case 0x560048:
    lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\x01','\x01','\0');
    puVar28 = auStack_68;
    if (lVar19 == 0x103) {
      return 0x103;
    }
    if (lVar19 < 0) goto LAB_1400018b0;
    lVar19 = VmpIsDynamic(pVVar24,(_IRP *)param_2);
    puVar28 = auStack_68;
    break;
  case 0x560054:
    VmpAcquireAll(pVVar6);
    iVar18 = VmpUpdateProperties(pVVar24,(_IRP *)param_2);
LAB_140001e76:
    puVar27 = auStack_68;
    VmpReleaseAll(pVVar6);
LAB_14000146e:
    *(int *)(param_2 + 0x30) = iVar18;
    *(undefined8 *)(puVar27 + -8) = 0x14000147d;
    IofCompleteRequest(param_2,0);
    return iVar18;
  case 0x560060:
    pVVar21 = pVVar24;
    lVar19 = VmpAllSystemsGo(pVVar24,(_IRP *)param_2,'\0','\x01','\0');
    puVar28 = auStack_68;
    if (lVar19 == 0x103) {
      return 0x103;
    }
    if (lVar19 < 0) goto LAB_1400018b0;
    lVar19 = VmpIsCsv(pVVar21,(_IRP *)param_2);
    puVar28 = auStack_68;
  }
LAB_1400018a6:
  puVar27 = puVar28;
LAB_1400018a8:
  puVar28 = puVar27;
  *(undefined8 *)(puVar28 + -8) = 0x1400018b0;
  VmpDecrementRefCount(pVVar24);
LAB_1400018b0:
  *(long *)(param_2 + 0x30) = lVar19;
  *(undefined8 *)(puVar28 + -8) = 0x1400018bf;
  IofCompleteRequest(param_2,0);
  return lVar19;
}



===== VmpRefCountCompletionRoutine @ 1400021a0 =====

undefined8 VmpRefCountCompletionRoutine(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  VM_VOLUME_EXTENSION *pVVar2;
  
  pVVar2 = *(VM_VOLUME_EXTENSION **)(param_1 + 0x40);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  VmpDecrementRefCount(pVVar2);
  return 0;
}



===== VmpDecrementRefCount @ 1400021d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl VmpDecrementRefCount(class VM_VOLUME_EXTENSION * __ptr64) */

void __cdecl VmpDecrementRefCount(VM_VOLUME_EXTENSION *param_1)

{
  VM_VOLUME_EXTENSION *pVVar1;
  int iVar2;
  longlong *******ppppppplVar3;
  code *pcVar4;
  VM_VOLUME_EXTENSION *pVVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  longlong lVar8;
  longlong *******ppppppplVar9;
  undefined1 *puVar10;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  longlong *******local_18;
  VM_VOLUME_EXTENSION *local_10;
  
  LOCK();
  pVVar1 = param_1 + 0x38;
  iVar2 = *(int *)pVVar1;
  *(int *)pVVar1 = *(int *)pVVar1 + -1;
  UNLOCK();
  if (iVar2 != 1) {
    return;
  }
  uVar6 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  puVar10 = auStack_38;
  if (*(code **)(param_1 + 0x40) != (code *)0x0) {
    uVar7 = (**(code **)(param_1 + 0x40))(param_1,*(undefined8 *)(param_1 + 0x48));
    *(undefined4 *)(param_1 + 0x48) = uVar7;
    *(undefined8 *)(param_1 + 0x40) = 0;
    LOCK();
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
    UNLOCK();
    pVVar1 = param_1 + 0xa0;
    ppppppplVar3 = *(longlong ********)pVVar1;
    pVVar5 = local_10;
    if ((VM_VOLUME_EXTENSION *)ppppppplVar3[1] == pVVar1) {
      ppppppplVar3[1] = (longlong ******)&local_18;
      *(longlong *********)pVVar1 = &local_18;
      local_10 = *(VM_VOLUME_EXTENSION **)(param_1 + 0xa8);
      local_18 = ppppppplVar3;
      pVVar5 = pVVar1;
      if (*(VM_VOLUME_EXTENSION **)local_10 == pVVar1) {
        *(longlong *********)local_10 = &local_18;
        *(VM_VOLUME_EXTENSION **)(param_1 + 0xa8) = pVVar1;
        *(VM_VOLUME_EXTENSION **)pVVar1 = pVVar1;
        KeReleaseSpinLock(param_1 + 0x18,uVar6);
        KeSetEvent(param_1 + 0x88,0,0);
        if ((longlong ********)local_18 == &local_18) {
          return;
        }
        VmpProcessIrpQueueAtDispatchLevel(param_1,(_LIST_ENTRY *)&local_18);
        if ((longlong ********)local_18 == &local_18) {
          return;
        }
        lVar8 = IoAllocateWorkItem(*(undefined8 *)param_1);
        if (lVar8 == 0) {
          while( true ) {
            if ((longlong ********)local_18 == &local_18) {
              return;
            }
            pVVar5 = local_10;
            if (((longlong ********)local_18[1] != &local_18) ||
               (ppppppplVar3 = (longlong *******)*local_18,
               (longlong *******)ppppppplVar3[1] != local_18)) break;
            ppppppplVar3[1] = (longlong ******)&local_18;
            ppppppplVar9 = local_18 + -0x15;
            *(undefined4 *)(local_18 + -0xf) = 0xc000009a;
            local_18[-0xe] = (longlong ******)0x0;
            local_18 = ppppppplVar3;
            IofCompleteRequest(ppppppplVar9,0);
          }
        }
        else {
          pVVar5 = local_10;
          if (((longlong ********)local_18[1] == &local_18) &&
             ((longlong ********)*(longlong ********)local_10 == &local_18)) {
            *(longlong ********)local_10 = local_18;
            local_18[1] = (longlong ******)local_10;
            local_10 = (VM_VOLUME_EXTENSION *)&local_18;
            local_18 = (longlong *******)&local_18;
            IoQueueWorkItemEx(lVar8,VmpProcessIrpQueueWorkerRoutine,0);
            return;
          }
        }
      }
    }
    local_10 = pVVar5;
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    puVar10 = auStack_30;
  }
  *(undefined8 *)(puVar10 + -8) = 0x14000237d;
  KeReleaseSpinLock(param_1 + 0x18,uVar6);
  return;
}



===== VmpAllSystemsGo @ 1400023d0 =====

/* long __cdecl VmpAllSystemsGo(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64,unsigned
   char,unsigned char,unsigned char) */

long __cdecl
VmpAllSystemsGo(VM_VOLUME_EXTENSION *param_1,_IRP *param_2,uchar param_3,uchar param_4,uchar param_5
               )

{
  longlong *plVar1;
  code *pcVar2;
  bool bVar3;
  undefined1 uVar4;
  long lVar5;
  _IRP *p_Var6;
  
  lVar5 = 0;
  if (param_2 != (_IRP *)0x0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
  }
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
  if (*(longlong *)(param_1 + 0x40) != 0) {
    p_Var6 = param_2 + 0xa8;
    *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) = *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
    plVar1 = *(longlong **)(param_1 + 0xa8);
    if ((VM_VOLUME_EXTENSION *)*plVar1 != param_1 + 0xa0) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3,uVar4);
      pcVar2 = (code *)swi(3);
      lVar5 = (*pcVar2)();
      return lVar5;
    }
    *(VM_VOLUME_EXTENSION **)p_Var6 = param_1 + 0xa0;
    lVar5 = 0x103;
    *(longlong **)(param_2 + 0xb0) = plVar1;
    *plVar1 = (longlong)p_Var6;
    *(_IRP **)(param_1 + 0xa8) = p_Var6;
    goto LAB_14000245d;
  }
  if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
    if (*(longlong *)(param_1 + 0x178) == 0) goto LAB_1400024f5;
LAB_140002437:
    bVar3 = true;
  }
  else {
    if (*(longlong *)(param_1 + 0x1d0) != 0) goto LAB_140002437;
LAB_1400024f5:
    bVar3 = false;
  }
  if (((param_1[0xbc] == (VM_VOLUME_EXTENSION)0x0) || (!bVar3)) ||
     (param_1[0xc0] != (VM_VOLUME_EXTENSION)0x0)) {
    if (((param_3 != '\0') && (param_1[0xbc] == (VM_VOLUME_EXTENSION)0x0)) ||
       ((param_4 != '\0' && (!bVar3)))) {
      lVar5 = -0x3ffffff2;
      goto LAB_14000245d;
    }
    if ((param_5 != '\0') && (param_1[0xc0] != (VM_VOLUME_EXTENSION)0x0)) {
      lVar5 = -0x7ffffff0;
      goto LAB_14000245d;
    }
  }
  else {
    LOCK();
    *(undefined4 *)(param_1 + 0x3c) = 1;
    UNLOCK();
  }
  LOCK();
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
  UNLOCK();
LAB_14000245d:
  KeReleaseSpinLock(param_1 + 0x18);
  return lVar5;
}



===== VmpReleaseAll @ 140002520 =====

/* void __cdecl VmpReleaseAll(class VM_ROOT_EXTENSION * __ptr64) */

void __cdecl VmpReleaseAll(VM_ROOT_EXTENSION *param_1)

{
  if (*(VM_ROOT_EXTENSION **)(param_1 + 0xb8) != param_1 + 0xb8) {
    VmpProcessDiskNotifications(param_1);
  }
  KeReleaseMutex(param_1 + 0x70,0);
  KeReleaseMutex(param_1 + 0x38,0);
  return;
}



===== VmpAcquireAll @ 140002570 =====

/* void __cdecl VmpAcquireAll(class VM_ROOT_EXTENSION * __ptr64) */

void __cdecl VmpAcquireAll(VM_ROOT_EXTENSION *param_1)

{
  KeWaitForSingleObject(param_1 + 0x38,0,0,0,0);
  KeWaitForSingleObject(param_1 + 0x70,0,0,0,0);
  if (*(VM_ROOT_EXTENSION **)(param_1 + 0xb8) != param_1 + 0xb8) {
    VmpProcessDiskNotifications(param_1);
  }
  return;
}



===== VmpReadWriteCompletionRoutine @ 1400025e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 VmpReadWriteCompletionRoutine(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  VM_VOLUME_EXTENSION *pVVar2;
  int iVar3;
  VM_VOLUME_EXTENSION *pVVar4;
  longlong ****pppplVar5;
  code *pcVar6;
  VM_VOLUME_EXTENSION *pVVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  longlong lVar10;
  longlong ****pppplVar11;
  undefined1 *puVar12;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  longlong ****local_18;
  VM_VOLUME_EXTENSION *local_10;
  
  pVVar4 = *(VM_VOLUME_EXTENSION **)(param_1 + 0x40);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  if (*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x18) != 0) {
    (**(code **)(*(longlong *)(pVVar4 + 8) + 0x148))(*(undefined8 *)(pVVar4 + 0x100));
  }
  LOCK();
  pVVar2 = pVVar4 + 0x38;
  iVar3 = *(int *)pVVar2;
  *(int *)pVVar2 = *(int *)pVVar2 + -1;
  UNLOCK();
  if (iVar3 != 1) {
    return 0;
  }
  uVar8 = KeAcquireSpinLockRaiseToDpc(pVVar4 + 0x18);
  puVar12 = auStack_38;
  if (*(code **)(pVVar4 + 0x40) != (code *)0x0) {
    uVar9 = (**(code **)(pVVar4 + 0x40))(pVVar4,*(undefined8 *)(pVVar4 + 0x48));
    *(undefined4 *)(pVVar4 + 0x48) = uVar9;
    *(undefined8 *)(pVVar4 + 0x40) = 0;
    LOCK();
    *(int *)(pVVar4 + 0x38) = *(int *)(pVVar4 + 0x38) + 1;
    UNLOCK();
    pVVar2 = pVVar4 + 0xa0;
    pppplVar5 = *(longlong *****)pVVar2;
    pVVar7 = local_10;
    if ((VM_VOLUME_EXTENSION *)pppplVar5[1] == pVVar2) {
      pppplVar5[1] = (longlong ***)&local_18;
      *(longlong ******)pVVar2 = &local_18;
      local_10 = *(VM_VOLUME_EXTENSION **)(pVVar4 + 0xa8);
      local_18 = pppplVar5;
      pVVar7 = pVVar2;
      if (*(VM_VOLUME_EXTENSION **)local_10 == pVVar2) {
        *(longlong ******)local_10 = &local_18;
        *(VM_VOLUME_EXTENSION **)(pVVar4 + 0xa8) = pVVar2;
        *(VM_VOLUME_EXTENSION **)pVVar2 = pVVar2;
        KeReleaseSpinLock(pVVar4 + 0x18,uVar8);
        KeSetEvent(pVVar4 + 0x88,0,0);
        if ((longlong *****)local_18 == &local_18) {
          return 0;
        }
        VmpProcessIrpQueueAtDispatchLevel(pVVar4,(_LIST_ENTRY *)&local_18);
        if ((longlong *****)local_18 == &local_18) {
          return 0;
        }
        lVar10 = IoAllocateWorkItem(*(undefined8 *)pVVar4);
        if (lVar10 == 0) {
          while( true ) {
            if ((longlong *****)local_18 == &local_18) {
              return 0;
            }
            pVVar7 = local_10;
            if (((longlong *****)local_18[1] != &local_18) ||
               (pppplVar5 = (longlong ****)*local_18, (longlong ****)pppplVar5[1] != local_18))
            break;
            pppplVar5[1] = (longlong ***)&local_18;
            pppplVar11 = local_18 + -0x15;
            *(undefined4 *)(local_18 + -0xf) = 0xc000009a;
            local_18[-0xe] = (longlong ***)0x0;
            local_18 = pppplVar5;
            IofCompleteRequest(pppplVar11,0);
          }
        }
        else {
          pVVar7 = local_10;
          if (((longlong *****)local_18[1] == &local_18) &&
             ((longlong *****)*(longlong *****)local_10 == &local_18)) {
            *(longlong *****)local_10 = local_18;
            local_18[1] = (longlong ***)local_10;
            local_10 = (VM_VOLUME_EXTENSION *)&local_18;
            local_18 = (longlong ****)&local_18;
            IoQueueWorkItemEx(lVar10,VmpProcessIrpQueueWorkerRoutine,0);
            return 0;
          }
        }
      }
    }
    local_10 = pVVar7;
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    puVar12 = auStack_30;
  }
  *(undefined8 *)(puVar12 + -8) = 0x1400027d3;
  KeReleaseSpinLock(pVVar4 + 0x18,uVar8);
  return 0;
}



===== RtlStringCbPrintfW @ 140002820 =====

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
      param_1[uVar2] = L'\0';
      uVar3 = 0x80000005;
    }
    else if ((longlong)iVar1 == uVar2) {
      param_1[uVar2] = L'\0';
    }
  }
  else {
    uVar3 = 0xc000000d;
    if (uVar2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar3;
}



===== VmCleanup @ 1400028b0 =====

undefined8 VmCleanup(longlong param_1,longlong param_2)

{
  VM_VOLUME_EXTENSION *pVVar1;
  
  pVVar1 = *(VM_VOLUME_EXTENSION **)(param_1 + 0x40);
  if ((*(int *)(pVVar1 + 0x10) == 1) &&
     (*(longlong *)(pVVar1 + 0x160) == *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30))) {
    VmpAcquireAll(*(VM_ROOT_EXTENSION **)(pVVar1 + 8));
    VmpRevertGptAttributes(pVVar1);
    VmpReleaseAll(*(VM_ROOT_EXTENSION **)(pVVar1 + 8));
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== VmCreate @ 140002930 =====

undefined8 VmCreate(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== VmFlushBuffers @ 140002960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong VmFlushBuffers(longlong param_1,longlong param_2)

{
  longlong lVar1;
  byte *pbVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined1 uVar8;
  ulonglong uVar9;
  uint uVar10;
  longlong *plVar11;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(lVar3 + 0x10) == 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    IofCompleteRequest(param_2,0);
    return 0xc0000010;
  }
  if (param_2 != 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
  }
  lVar1 = lVar3 + 0x18;
  uVar8 = KeAcquireSpinLockRaiseToDpc(lVar1);
  if (*(longlong *)(lVar3 + 0x40) != 0) {
    plVar11 = (longlong *)(param_2 + 0xa8);
    pbVar2 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar2 = *pbVar2 | 1;
    plVar6 = *(longlong **)(lVar3 + 0xa8);
    if (*plVar6 == lVar3 + 0xa0) {
      *plVar11 = lVar3 + 0xa0;
      *(longlong **)(param_2 + 0xb0) = plVar6;
      *plVar6 = (longlong)plVar11;
      *(longlong **)(lVar3 + 0xa8) = plVar11;
      KeReleaseSpinLock(lVar1);
      return 0x103;
    }
    pcVar7 = (code *)swi(0x29);
    (*pcVar7)(3,uVar8);
    pcVar7 = (code *)swi(3);
    uVar9 = (*pcVar7)();
    return uVar9;
  }
  if (*(char *)(lVar3 + 0x1ca) == '\0') {
    lVar4 = *(longlong *)(lVar3 + 0x178);
  }
  else {
    lVar4 = *(longlong *)(lVar3 + 0x1d0);
  }
  if ((*(char *)(lVar3 + 0xbc) == '\0') || (lVar4 == 0)) {
    uVar10 = 0xc000000e;
  }
  else {
    if (*(char *)(lVar3 + 0xc0) == '\0') {
      LOCK();
      *(undefined4 *)(lVar3 + 0x3c) = 1;
      UNLOCK();
      LOCK();
      *(int *)(lVar3 + 0x38) = *(int *)(lVar3 + 0x38) + 1;
      UNLOCK();
      KeReleaseSpinLock(lVar1);
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
      lVar1 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar1 + -0x10) = VmpRefCountCompletionRoutine;
      *(undefined8 *)(lVar1 + -8) = 9;
      *(undefined1 *)(lVar1 + -0x45) = 0xe0;
      if (*(char *)(lVar3 + 0x1ca) == '\0') {
        uVar9 = IofCallDriver(*(undefined8 *)(lVar3 + 400));
        return uVar9;
      }
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + -0x48;
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + -1;
      pbVar2 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar2 = *pbVar2 | 1;
      (**(code **)(*(longlong *)(*(longlong *)(lVar3 + 8) + 0x188) + 0xd8))
                (*(undefined8 *)(lVar3 + 0x1d0),param_2,VmBroadcastIrpCompletionRoutine,param_2,1);
      return 0x103;
    }
    uVar10 = 0x80000010;
  }
  KeReleaseSpinLock(lVar1);
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(uint *)(param_2 + 0x30) = uVar10;
  IofCompleteRequest(param_2,0);
  return (ulonglong)uVar10;
}



===== VmWmi @ 140002bc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong VmWmi(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  int local_res8 [2];
  
  local_res8[0] = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if (*(int *)(lVar1 + 0x10) == 0) {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = lVar2 + 0x48;
    uVar4 = IofCallDriver(*(undefined8 *)(*(longlong *)(lVar1 + 8) + 0x28),param_2);
    return uVar4;
  }
  if (*(char *)(lVar2 + 1) == '\r') {
    if (*(int *)(lVar2 + 0x18) == 0x10) {
      if (**(int **)(lVar2 + 0x20) == 1) {
        *(undefined8 *)(lVar1 + 0x148) = *(undefined8 *)(*(int **)(lVar2 + 0x20) + 2);
        if ((*(char *)(lVar1 + 0x1ca) != '\0') && (*(longlong *)(lVar1 + 0x1d0) != 0)) {
          (**(code **)(*(longlong *)(*(longlong *)(lVar1 + 8) + 0x188) + 0xf0))
                    (*(longlong *)(lVar1 + 0x1d0));
        }
        uVar4 = 0;
      }
      else {
        uVar4 = 0xc00000bb;
      }
    }
    else {
      uVar4 = 0xc000000d;
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(int *)(param_2 + 0x30) = (int)uVar4;
  }
  else {
    uVar3 = WmiSystemControl(lVar1 + 0x108,param_1,param_2,local_res8);
    uVar4 = (ulonglong)uVar3;
    if (local_res8[0] == 0) {
      return uVar4;
    }
    if (local_res8[0] != 1) {
      uVar4 = (ulonglong)*(uint *)(param_2 + 0x30);
    }
  }
  IofCompleteRequest(param_2,0);
  return uVar4;
}



===== VmpSendDeviceControl @ 140002ce0 =====

ulonglong VmpSendDeviceControl
                    (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
                    undefined8 param_5,undefined4 param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_38 [6];
  
  local_38[4] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  KeInitializeEvent(local_38 + 2,0,0);
  lVar1 = IoBuildDeviceIoControlRequest
                    (param_2,param_1,param_3,param_4,param_5,param_6,0,local_38 + 2,local_38);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = IofCallDriver(param_1,lVar1);
    if ((int)uVar2 == 0x103) {
      KeWaitForSingleObject(local_38 + 2,0,0,0,0);
      uVar2 = local_38[0] & 0xffffffff;
    }
  }
  return uVar2;
}



===== VmInternalDeviceControl @ 140002df0 =====

int VmInternalDeviceControl(longlong param_1,_IRP *param_2)

{
  uint uVar1;
  longlong lVar2;
  VM_ROOT_EXTENSION *pVVar3;
  int iVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  iVar4 = 0;
  pVVar3 = *(VM_ROOT_EXTENSION **)(lVar2 + 8);
  *(undefined8 *)(param_2 + 0x38) = 0;
  if (*(int *)(lVar2 + 0x10) != 0) {
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    IofCompleteRequest(param_2,0);
    return -0x3ffffff0;
  }
  uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 0x18);
  if (uVar1 == 0x760018) goto switchD_140002ece_caseD_76001c;
  if (uVar1 == 0x760028) {
    iVar4 = VmpSetPowerState(pVVar3,param_2);
  }
  else {
    if (0x760640 < uVar1) {
switchD_140002ece_caseD_760001:
      iVar4 = -0x3ffffff0;
      goto switchD_140002ece_caseD_76001c;
    }
    if (uVar1 == 0x760640) {
      iVar4 = VmpExtensionDriverStarted(pVVar3,param_2);
    }
    else {
      switch(uVar1) {
      case 0x760000:
        iVar4 = VmpPartitionArrived(pVVar3,param_2);
        break;
      default:
        goto switchD_140002ece_caseD_760001;
      case 0x760004:
        iVar4 = VmpPartitionRemoved(pVVar3,param_2);
        break;
      case 0x760008:
        iVar4 = VmpWholeDiskRemoved(pVVar3,param_2);
        break;
      case 0x76000c:
        iVar4 = VmpReferenceDependantVolume(pVVar3,param_2);
        break;
      case 0x76001c:
        goto switchD_140002ece_caseD_76001c;
      case 0x760020:
        iVar4 = VmpPartitionChanged(pVVar3,param_2);
        break;
      case 0x760024:
        iVar4 = VmpPmWmiCounterLibContext(pVVar3,param_2);
        break;
      case 0x76002c:
        iVar4 = VmpWholeDiskArrived(pVVar3,param_2);
        break;
      case 0x760030:
        iVar4 = VmpIsRedirectionSupported(pVVar3,param_2);
        break;
      case 0x760034:
        iVar4 = VmpRedirectRequest(pVVar3,param_2);
        break;
      case 0x760038:
        iVar4 = VmpQueryVetoQueryRemove(pVVar3,param_2);
      }
    }
  }
  if (iVar4 == 0x103) {
    return 0x103;
  }
switchD_140002ece_caseD_76001c:
  *(int *)(param_2 + 0x30) = iVar4;
  IofCompleteRequest(param_2,0);
  return iVar4;
}



===== VmpSetPowerState @ 140002f70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpSetPowerState(class VM_ROOT_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpSetPowerState(VM_ROOT_EXTENSION *param_1,_IRP *param_2)

{
  undefined8 *puVar1;
  VM_VOLUME_EXTENSION *pVVar2;
  
  puVar1 = *(undefined8 **)(param_2 + 0x18);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x18) {
    return -0x3ffffff3;
  }
  KeWaitForSingleObject(param_1 + 0x70,0,0,0,0);
  pVVar2 = VmpFindExtensionForBasicVolume((_DEVICE_OBJECT *)*puVar1);
  if (pVVar2 == (VM_VOLUME_EXTENSION *)0x0) {
    if (*(longlong *)(param_1 + 0x188) != 0) {
      VmpRestoreExtensionDriver((longlong)param_1);
      (**(code **)(*(longlong *)(param_1 + 0x188) + 0x58))
                (puVar1[1],*puVar1,*(undefined4 *)(puVar1 + 2));
      VmpPageExtensionDriver((longlong)param_1);
    }
  }
  else {
    VmpSetDevicePowerState(pVVar2,*(_DEVICE_POWER_STATE *)(puVar1 + 2));
  }
  KeReleaseMutex(param_1 + 0x70,0);
  return 0;
}



===== VmpFindExtensionForBasicVolume @ 140003040 =====

/* class VM_VOLUME_EXTENSION * __ptr64 __cdecl VmpFindExtensionForBasicVolume(struct _DEVICE_OBJECT
   * __ptr64) */

VM_VOLUME_EXTENSION * __cdecl VmpFindExtensionForBasicVolume(_DEVICE_OBJECT *param_1)

{
  bool bVar1;
  VM_ROOT_EXTENSION *pVVar2;
  VM_ROOT_EXTENSION *pVVar3;
  
  bVar1 = false;
  pVVar2 = (VM_ROOT_EXTENSION *)0x0;
  pVVar3 = *(VM_ROOT_EXTENSION **)(VmRootExtension + 0xd0);
  do {
    if (pVVar3 == VmRootExtension + 0xd0) {
LAB_140003086:
      if (!bVar1) {
        pVVar2 = (VM_ROOT_EXTENSION *)0x0;
      }
      return (VM_VOLUME_EXTENSION *)pVVar2;
    }
    pVVar2 = pVVar3 + -0x20;
    if ((pVVar3[0x1aa] == (VM_ROOT_EXTENSION)0x0) &&
       ((*(_DEVICE_OBJECT **)(pVVar3 + 0x158) == param_1 ||
        (*(_DEVICE_OBJECT **)(pVVar3 + 0x160) == param_1)))) {
      bVar1 = true;
      goto LAB_140003086;
    }
    pVVar3 = *(VM_ROOT_EXTENSION **)pVVar3;
  } while( true );
}



===== VmpSetDevicePowerState @ 1400030a0 =====

/* void __cdecl VmpSetDevicePowerState(class VM_VOLUME_EXTENSION * __ptr64,enum _DEVICE_POWER_STATE)
    */

void __cdecl VmpSetDevicePowerState(VM_VOLUME_EXTENSION *param_1,_DEVICE_POWER_STATE param_2)

{
  if ((param_1[0xbc] != (VM_VOLUME_EXTENSION)0x0) &&
     (*(_DEVICE_POWER_STATE *)(param_1 + 0x150) != param_2)) {
    *(_DEVICE_POWER_STATE *)(param_1 + 0x150) = param_2;
    PoSetPowerState(*(undefined8 *)param_1,1,param_2);
  }
  return;
}



===== VmVolumeRequestCompletionRoutine @ 1400030e0 =====

/* void __cdecl VmVolumeRequestCompletionRoutine(struct _IRP * __ptr64) */

void __cdecl VmVolumeRequestCompletionRoutine(_IRP *param_1)

{
  IofCompleteRequest(param_1,1);
  return;
}



===== VmpAcquireDevices @ 140003100 =====

/* void __cdecl VmpAcquireDevices(class VM_ROOT_EXTENSION * __ptr64) */

void __cdecl VmpAcquireDevices(VM_ROOT_EXTENSION *param_1)

{
  KeWaitForSingleObject(param_1 + 0x70,0,0,0,0);
  return;
}



===== IsRecognized @ 140003140 =====

/* public: unsigned char __cdecl SC_PART_ENTRY::IsRecognized(void) __ptr64 */

uchar __thiscall SC_PART_ENTRY::IsRecognized(SC_PART_ENTRY *this)

{
  SC_PART_ENTRY SVar1;
  longlong lVar2;
  
  if (*(int *)this == 0) {
    SVar1 = this[0x20];
    if (((0x2d < (byte)SVar1) || ((0x3f80000058d2U >> ((ulonglong)(byte)SVar1 & 0x3f) & 1) == 0)) &&
       (SVar1 != (SC_PART_ENTRY)0xef)) {
      return '\0';
    }
  }
  else {
    if (*(int *)this != 1) {
      return '\0';
    }
    lVar2 = *(longlong *)(this + 0x20) + -0x45b94df957434f53;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(this + 0x28) + -0x7c4506f070239e8e;
    }
    if (lVar2 != 0) {
      lVar2 = *(longlong *)(this + 0x20) + -0x43f094cb57434f53;
      if (lVar2 == 0) {
        lVar2 = *(longlong *)(this + 0x28) + -0x7da5cf103cd733a5;
      }
      if (lVar2 != 0) {
        lVar2 = *(longlong *)(this + 0x20) + -0x4433b9e5ebd0a0a2;
        if (lVar2 == 0) {
          lVar2 = *(longlong *)(this + 0x28) + 0x3866d94849973f79;
        }
        if (lVar2 != 0) {
          lVar2 = *(longlong *)(this + 0x20) + -0x405e8f4557434f53;
          if (lVar2 == 0) {
            lVar2 = *(longlong *)(this + 0x28) + 0x2ccfbc7592e7dc76;
          }
          if (lVar2 != 0) {
            lVar2 = *(longlong *)(this + 0x20) + -0x4d4006d1de94bba4;
            if (lVar2 == 0) {
              lVar2 = *(longlong *)(this + 0x28) + 0x532986fe2a40955f;
            }
            if (lVar2 != 0) {
              lVar2 = *(longlong *)(this + 0x20) + -0x44d523f257434f53;
              if (lVar2 == 0) {
                lVar2 = *(longlong *)(this + 0x28) + 0x6f659254498cf58;
              }
              if (lVar2 != 0) {
                lVar2 = *(longlong *)(this + 0x20) + -0x41967fe057434f53;
                if (lVar2 == 0) {
                  lVar2 = *(longlong *)(this + 0x28) + 0x7bcb9bae84bdbd65;
                }
                if (lVar2 != 0) {
                  lVar2 = *(longlong *)(this + 0x20) + -0x4014432e57434f53;
                  if (lVar2 == 0) {
                    lVar2 = *(longlong *)(this + 0x28) + -0x6a00c0a9ea8d4cae;
                  }
                  if (lVar2 != 0) {
                    lVar2 = *(longlong *)(this + 0x20) + -0x4a05c69157434f53;
                    if (lVar2 == 0) {
                      lVar2 = *(longlong *)(this + 0x28) + 0x31d62d50c28fb145;
                    }
                    if (lVar2 != 0) {
                      lVar2 = *(longlong *)(this + 0x20) + -0x460b4b8157434f53;
                      if (lVar2 == 0) {
                        lVar2 = *(longlong *)(this + 0x28) + -0x146d13feb6ff19a3;
                      }
                      if (lVar2 != 0) {
                        lVar2 = *(longlong *)(this + 0x20) + -0x4e84e84d57434f53;
                        if (lVar2 == 0) {
                          lVar2 = *(longlong *)(this + 0x28) + 0x2046fb4244130c56;
                        }
                        if (lVar2 != 0) {
                          lVar2 = *(longlong *)(this + 0x20) + -0x4631e3e357434f53;
                          if (lVar2 == 0) {
                            lVar2 = *(longlong *)(this + 0x28) + 0x558cc7db2dd93a5b;
                          }
                          if (lVar2 != 0) {
                            return '\0';
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
  return '\x01';
}



===== VmpRemove @ 140003300 =====

/* void __cdecl VmpRemove(class VM_VOLUME_EXTENSION * __ptr64) */

void __cdecl VmpRemove(VM_VOLUME_EXTENSION *param_1)

{
  undefined1 uVar1;
  
  if (param_1[0xbc] != (VM_VOLUME_EXTENSION)0x0) {
    uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x18);
    LOCK();
    *(undefined4 *)(param_1 + 0x3c) = 0;
    UNLOCK();
    param_1[0xbc] = (VM_VOLUME_EXTENSION)0x0;
    KeReleaseSpinLock(param_1 + 0x18,uVar1);
    IoSetDevicePropertyData(*(undefined8 *)param_1,&DEVPKEY_Device_SessionId,0,0,0,0,0);
    VmpDeregisterDevice(*(longlong *)param_1);
    VmpReleaseInterfaces((longlong)param_1);
  }
  return;
}



===== VmpReleaseInterfaces @ 1400033a0 =====

void VmpReleaseInterfaces(longlong param_1)

{
  longlong lVar1;
  undefined *puVar2;
  
  if (*(longlong *)(param_1 + 0xd0) != 0) {
    lVar1 = param_1 + 200;
    IoSetDeviceInterfaceState(lVar1,0);
    if (*(char *)(param_1 + 0x1ca) == '\0') {
      IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_Disk_Number,0,0,0,0,0);
      IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_Partition_Number,0,0,0,0,0);
      if (*(char *)(param_1 + 0x1c8) == '\0') {
        puVar2 = &DEVPKEY_Storage_Mbr_Type;
      }
      else {
        IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_Gpt_Type,0,0,0,0,0);
        puVar2 = &DEVPKEY_Storage_Gpt_Name;
      }
      IoSetDeviceInterfacePropertyData(lVar1,puVar2,0,0,0,0,0);
    }
    IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_Portable,0,0,0,0,0);
    IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_Removable_Media,0,0,0,0,0);
    IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_System_Critical,0,0,0,0,0);
    RtlFreeUnicodeString(lVar1);
  }
  if (*(longlong *)(param_1 + 0xe0) != 0) {
    lVar1 = param_1 + 0xd8;
    IoSetDeviceInterfaceState(lVar1,0);
    if (*(char *)(param_1 + 0x1ca) == '\0') {
      IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_Disk_Number,0,0,0,0,0);
      IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_Partition_Number,0,0,0,0,0);
      if (*(char *)(param_1 + 0x1c8) == '\0') {
        puVar2 = &DEVPKEY_Storage_Mbr_Type;
      }
      else {
        IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_Gpt_Type,0,0,0,0,0);
        puVar2 = &DEVPKEY_Storage_Gpt_Name;
      }
      IoSetDeviceInterfacePropertyData(lVar1,puVar2,0,0,0,0,0);
    }
    IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_Portable,0,0,0,0,0);
    IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_Removable_Media,0,0,0,0,0);
    IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_System_Critical,0,0,0,0,0);
    RtlFreeUnicodeString(lVar1);
  }
  if (*(longlong *)(param_1 + 0xf0) != 0) {
    lVar1 = param_1 + 0xe8;
    IoSetDeviceInterfaceState(lVar1,0);
    if (*(char *)(param_1 + 0x1ca) == '\0') {
      IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_Disk_Number,0,0,0,0,0);
      IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_Partition_Number,0,0,0,0,0);
      if (*(char *)(param_1 + 0x1c8) == '\0') {
        puVar2 = &DEVPKEY_Storage_Mbr_Type;
      }
      else {
        IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_Gpt_Type,0,0,0,0,0);
        puVar2 = &DEVPKEY_Storage_Gpt_Name;
      }
      IoSetDeviceInterfacePropertyData(lVar1,puVar2,0,0,0,0,0);
    }
    IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_Portable,0,0,0,0,0);
    IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_Removable_Media,0,0,0,0,0);
    IoSetDeviceInterfacePropertyData(lVar1,&DEVPKEY_Storage_System_Critical,0,0,0,0,0);
    RtlFreeUnicodeString(lVar1);
  }
  return;
}



===== VmBroadcastIrpCompletionRoutine @ 140003910 =====

/* void __cdecl VmBroadcastIrpCompletionRoutine(void * __ptr64,long) */

void __cdecl VmBroadcastIrpCompletionRoutine(void *param_1,long param_2)

{
  *(long *)((longlong)param_1 + 0x30) = param_2;
  *(undefined8 *)((longlong)param_1 + 0x38) = 0;
  IofCompleteRequest(param_1,1);
  return;
}



===== VmpIsSafeForDirectAccess @ 140003940 =====

undefined8 VmpIsSafeForDirectAccess(longlong *param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 local_res8 [8];
  
  uVar2 = 0;
  local_res8[0] = 0;
  if (*(char *)((longlong)param_1 + 0xb9) == '\0') {
    IoAcquireVpbSpinLock(local_res8);
    lVar1 = *(longlong *)(*param_1 + 0x38);
    if (((lVar1 == 0) || (*(int *)(lVar1 + 0x1c) == 0)) || ((*(byte *)(lVar1 + 4) & 0x21) != 1)) {
      uVar2 = 1;
    }
    IoReleaseVpbSpinLock(local_res8[0]);
  }
  return uVar2;
}



===== VmpReleaseDevices @ 1400039c0 =====

/* void __cdecl VmpReleaseDevices(class VM_ROOT_EXTENSION * __ptr64) */

void __cdecl VmpReleaseDevices(VM_ROOT_EXTENSION *param_1)

{
  KeReleaseMutex(param_1 + 0x70,0);
  return;
}



===== VmpReleaseConfig @ 1400039f0 =====

/* void __cdecl VmpReleaseConfig(class VM_ROOT_EXTENSION * __ptr64) */

void __cdecl VmpReleaseConfig(VM_ROOT_EXTENSION *param_1)

{
  KeReleaseMutex(param_1 + 0x38,0);
  return;
}



===== McTemplateK0qzqxt_EtwWriteTransfer @ 140003a20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qzqxt_EtwWriteTransfer(void)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 local_res20 [8];
  wchar_t *in_stack_00000028;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined1 *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  int local_50;
  undefined4 local_4c;
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
  if (in_stack_00000028 == (wchar_t *)0x0) {
    local_50 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar1 = lVar2 + 1;
      lVar2 = lVar2 + 1;
    } while (in_stack_00000028[lVar1] != L'\0');
    local_50 = (int)lVar2 * 2 + 2;
  }
  local_48 = &uStack0000000000000030;
  local_4c = 0;
  local_38 = &uStack0000000000000038;
  local_40 = 4;
  if (in_stack_00000028 == (wchar_t *)0x0) {
    in_stack_00000028 = L"NULL";
  }
  local_28 = &uStack0000000000000040;
  local_30 = 8;
  local_20 = 4;
  local_58 = in_stack_00000028;
  McGenEventWrite_EtwWriteTransfer(in_stack_00000028,&VolumeRemoved,0,6,local_78);
  return;
}



===== McTemplateK0qzqx_EtwWriteTransfer @ 140003b30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qzqx_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               wchar_t *param_5,undefined1 param_6,undefined1 param_7)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 local_res20 [2];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  wchar_t *local_48;
  int local_40;
  undefined4 local_3c;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res20;
  local_50 = 4;
  if (param_5 == (wchar_t *)0x0) {
    local_40 = 10;
  }
  else {
    lVar2 = -1;
    do {
      lVar1 = lVar2 + 1;
      lVar2 = lVar2 + 1;
    } while (param_5[lVar1] != L'\0');
    local_40 = (int)lVar2 * 2 + 2;
  }
  local_38 = &param_6;
  local_3c = 0;
  local_28 = &param_7;
  local_30 = 4;
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"NULL";
  }
  local_20 = 8;
  local_res20[0] = param_4;
  local_48 = param_5;
  McGenEventWrite_EtwWriteTransfer(param_5,param_2,L"NULL",5,local_68);
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 140003c20 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  uint uVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_14000b008;
  if (DAT_14000b008 == (ushort *)0x0) {
    uVar3 = 0;
    *param_5 = 0;
    uVar2 = 0;
  }
  else {
    *param_5 = DAT_14000b008;
    uVar3 = 2;
    uVar2 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar2;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar3;
  EtwWriteTransfer(StorageVolumeProvider_Context,param_2,0,0,param_4,param_5);
  return;
}



===== VmpInitializeInterfaces @ 140003c90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl VmpInitializeInterfaces(class VM_VOLUME_EXTENSION * __ptr64) */

long __cdecl VmpInitializeInterfaces(VM_VOLUME_EXTENSION *param_1)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined *puVar4;
  uint uVar5;
  VM_VOLUME_EXTENSION *pVVar6;
  undefined1 auStackY_108 [32];
  undefined8 local_c0;
  undefined8 uStack_b8;
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
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_108;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  iVar1 = IoRegisterDeviceInterface
                    (*(undefined8 *)param_1,&GUID_DEVINTERFACE_VOLUME,0,param_1 + 200);
  if (((-1 < iVar1) &&
      (iVar1 = IoRegisterDeviceInterface
                         (*(undefined8 *)param_1,&GUID_DEVINTERFACE_HIDDEN_VOLUME,0,param_1 + 0xd8),
      -1 < iVar1)) &&
     (iVar1 = IoRegisterDeviceInterface(*(undefined8 *)param_1,&GUID_DEVINTERFACE_SERVICE_VOLUME),
     -1 < iVar1)) {
    if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
      uVar2 = VmpSendDeviceControl(*(undefined8 *)(param_1 + 0x178),0x70048,0,0,&local_a8,0x90);
      if ((int)uVar2 < 0) {
        return (int)uVar2;
      }
    }
    uVar5 = 0;
    do {
      if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
        pVVar6 = param_1 + (ulonglong)uVar5 * 0x10 + 200;
        iVar1 = IoSetDeviceInterfacePropertyData(pVVar6,&DEVPKEY_Storage_Disk_Number,0,0);
        if (iVar1 < 0) {
          return iVar1;
        }
        iVar1 = IoSetDeviceInterfacePropertyData(pVVar6,&DEVPKEY_Storage_Partition_Number);
        if (iVar1 < 0) {
          return iVar1;
        }
        if (param_1[0x1c8] == (VM_VOLUME_EXTENSION)0x0) {
          puVar4 = &DEVPKEY_Storage_Mbr_Type;
        }
        else {
          iVar1 = IoSetDeviceInterfacePropertyData(pVVar6,&DEVPKEY_Storage_Gpt_Type);
          if (iVar1 < 0) {
            return iVar1;
          }
          RtlInitUnicodeString(&local_c0,&uStack_60);
          puVar4 = &DEVPKEY_Storage_Gpt_Name;
        }
        iVar1 = IoSetDeviceInterfacePropertyData(pVVar6,puVar4);
        if (iVar1 < 0) {
          return iVar1;
        }
      }
      pVVar6 = param_1 + (ulonglong)uVar5 * 0x10 + 200;
      iVar1 = IoSetDeviceInterfacePropertyData(pVVar6,&DEVPKEY_Storage_Portable);
      if (iVar1 < 0) {
        return iVar1;
      }
      iVar1 = IoSetDeviceInterfacePropertyData(pVVar6,&DEVPKEY_Storage_Removable_Media);
      if (iVar1 < 0) {
        return iVar1;
      }
      iVar1 = IoSetDeviceInterfacePropertyData(pVVar6,&DEVPKEY_Storage_System_Critical);
      if (iVar1 < 0) {
        return iVar1;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < 3);
    lVar3 = 200;
    if (param_1[0xb8] == (VM_VOLUME_EXTENSION)0x0) {
      lVar3 = 0xd8;
    }
    iVar1 = IoSetDeviceInterfaceState(param_1 + lVar3,0);
    if (-1 < iVar1) {
      lVar3 = 200;
      if (param_1[0xb8] != (VM_VOLUME_EXTENSION)0x0) {
        lVar3 = 0xd8;
      }
      iVar1 = IoSetDeviceInterfaceState(param_1 + lVar3,1);
      if (-1 < iVar1) {
        iVar1 = IoSetDeviceInterfaceState(param_1 + 0xe8,param_1[0xb9] != (VM_VOLUME_EXTENSION)0x0);
      }
    }
  }
  return iVar1;
}



===== VmpSetTargetCallback @ 1400040c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpSetTargetCallback(class VM_VOLUME_EXTENSION * __ptr64,void * __ptr64) */

long __cdecl VmpSetTargetCallback(VM_VOLUME_EXTENSION *param_1,void *param_2)

{
  longlong lVar1;
  bool bVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  bVar2 = false;
  uVar3 = Feature_Servicing_VolmgrHighIrqlPagedMemoryAccess__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    if (param_1[0x1ca] == *(VM_VOLUME_EXTENSION *)param_2) {
      if ((param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) &&
         (*(longlong *)(param_1 + 0x188) != *(longlong *)((longlong)param_2 + 0x10))) {
        bVar2 = false;
        if (*(longlong *)((longlong)param_2 + 0x10) != 0) {
          bVar2 = true;
        }
      }
    }
    else {
      bVar2 = true;
    }
  }
  if ((*(char *)param_2 != '\0') && (*(longlong *)((longlong)param_2 + 0x60) != 0)) {
    if (param_1[0x1ca] != (VM_VOLUME_EXTENSION)0x0) {
      uVar4 = *(undefined8 *)(param_1 + 0x1d0);
    }
    (**(code **)(*(longlong *)(VmRootExtension + 0x188) + 0xf0))
              (*(longlong *)((longlong)param_2 + 0x60),*(undefined8 *)(param_1 + 0x148));
    (**(code **)(*(longlong *)(VmRootExtension + 0x188) + 0xe8))
              (uVar4,*(undefined8 *)((longlong)param_2 + 0x60),0 < *(int *)(param_1 + 0xb4));
  }
  if ((((param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) && (*(char *)param_2 == '\0')) &&
      (*(longlong *)(param_1 + 0x178) != 0)) &&
     ((*(longlong *)((longlong)param_2 + 8) != 0 &&
      (*(longlong *)(param_1 + 0x178) != *(longlong *)((longlong)param_2 + 8))))) {
    *(char *)(*(longlong *)param_1 + 0x4c) = *(char *)(*(longlong *)param_1 + 0x4c) + -1;
    IoAdjustStackSizeForRedirection(*(undefined8 *)param_1,*(undefined8 *)((longlong)param_2 + 8),0)
    ;
    *(char *)(*(longlong *)param_1 + 0x4c) = *(char *)(*(longlong *)param_1 + 0x4c) + '\x01';
  }
  param_1[0x1ca] = *(VM_VOLUME_EXTENSION *)param_2;
  *(undefined8 *)(param_1 + 0x178) = *(undefined8 *)((longlong)param_2 + 8);
  *(undefined8 *)(param_1 + 0x188) = *(undefined8 *)((longlong)param_2 + 0x10);
  *(undefined8 *)(param_1 + 400) = *(undefined8 *)((longlong)param_2 + 0x18);
  *(undefined4 *)(param_1 + 0x1a0) = *(undefined4 *)((longlong)param_2 + 0x20);
  *(undefined4 *)(param_1 + 0x1a4) = *(undefined4 *)((longlong)param_2 + 0x30);
  *(undefined8 *)(param_1 + 0x1a8) = *(undefined8 *)((longlong)param_2 + 0x38);
  *(undefined8 *)(param_1 + 0x1b0) = *(undefined8 *)((longlong)param_2 + 0x40);
  uVar4 = *(undefined8 *)((longlong)param_2 + 0x50);
  *(undefined8 *)(param_1 + 0x1b8) = *(undefined8 *)((longlong)param_2 + 0x48);
  *(undefined8 *)(param_1 + 0x1c0) = uVar4;
  param_1[0x1c8] = *(VM_VOLUME_EXTENSION *)((longlong)param_2 + 0x58);
  param_1[0x1c9] = *(VM_VOLUME_EXTENSION *)((longlong)param_2 + 0x59);
  *(undefined8 *)(param_1 + 0x1d0) = *(undefined8 *)((longlong)param_2 + 0x60);
  uVar3 = Feature_Servicing_VolmgrHighIrqlPagedMemoryAccess__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar3 != 0) &&
     (lVar1 = *(longlong *)(param_1 + 0x198), lVar1 != *(longlong *)((longlong)param_2 + 0x28))) {
    if (lVar1 != 0) {
      ExFreePoolWithTag(lVar1,0);
    }
    *(undefined8 *)(param_1 + 0x198) = *(undefined8 *)((longlong)param_2 + 0x28);
  }
  if ((((*(uint *)(*(longlong *)param_1 + 0x34) & 1) != 0) && (*(longlong *)(param_1 + 0x178) != 0))
     && ((*(uint *)(*(longlong *)(param_1 + 0x178) + 0x30) & 2) != 0)) {
    *(uint *)(*(longlong *)param_1 + 0x30) = *(uint *)(*(longlong *)param_1 + 0x30) | 2;
    *(uint *)(*(longlong *)(param_1 + 0x178) + 0x30) =
         *(uint *)(*(longlong *)(param_1 + 0x178) + 0x30) & 0xfffffffd;
  }
  uVar3 = Feature_Servicing_VolmgrHighIrqlPagedMemoryAccess__private_IsEnabledDeviceUsageNoInline();
  if (((int)uVar3 == 0) && (bVar2)) {
    if (*(longlong *)(param_1 + 0x198) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x198),0);
      *(undefined8 *)(param_1 + 0x198) = 0;
    }
    if (*(_DEVICE_OBJECT **)(param_1 + 0x188) != (_DEVICE_OBJECT *)0x0) {
      VmpGetInstancePath(*(_DEVICE_OBJECT **)(param_1 + 0x188),(ushort **)(param_1 + 0x198));
    }
  }
  return 0;
}



===== VmPower @ 140004340 =====

ulonglong VmPower(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  uint uVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  uVar5 = *(uint *)(param_2 + 0x30);
  if (*(int *)(lVar2 + 0x10) == 0) {
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = lVar3 + 0x48;
    uVar4 = IofCallDriver(*(undefined8 *)(lVar2 + 0x28),param_2);
    return uVar4;
  }
  cVar1 = *(char *)(lVar3 + 1);
  if ((cVar1 != '\0') && (cVar1 != '\x01')) {
    if (cVar1 == '\x02') {
      if (((*(int *)(lVar3 + 0x10) == 0) && (*(int *)(lVar3 + 0x20) == 3)) &&
         (*(char *)(lVar2 + 0x1c9) != '\0')) {
        *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 2;
      }
    }
    else if (cVar1 != '\x03') goto LAB_1400043c7;
  }
  uVar5 = 0;
LAB_1400043c7:
  *(uint *)(param_2 + 0x30) = uVar5;
  IofCompleteRequest(param_2,0);
  return (ulonglong)uVar5;
}



===== VmReadWrite @ 1400043f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VmReadWrite(longlong param_1,_IRP *param_2)

{
  byte *pbVar1;
  _IRP *p_Var2;
  VM_VOLUME_EXTENSION *pVVar3;
  undefined8 *puVar4;
  longlong lVar5;
  long lVar6;
  int iVar7;
  ulonglong uVar8;
  
  pVVar3 = *(VM_VOLUME_EXTENSION **)(param_1 + 0x40);
  if (*(int *)(pVVar3 + 0x10) != 1) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc000000e;
    IofCompleteRequest(param_2,0);
    return -0x3ffffff2;
  }
  LOCK();
  *(int *)(pVVar3 + 0x38) = *(int *)(pVVar3 + 0x38) + 1;
  UNLOCK();
  uVar8 = Feature_Servicing_KcsanRacyAccessesInVolmgr__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar8 == 0) {
    iVar7 = *(int *)(pVVar3 + 0x3c);
  }
  else {
    iVar7 = *(int *)(pVVar3 + 0x3c);
  }
  if (iVar7 == 0) {
    VmpDecrementRefCount(pVVar3);
    lVar6 = VmpAllSystemsGo(pVVar3,param_2,'\x01','\x01','\x01');
    if (lVar6 == 0x103) {
      return 0x103;
    }
    if (lVar6 < 0) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(long *)(param_2 + 0x30) = lVar6;
      IofCompleteRequest(param_2,0);
      return lVar6;
    }
  }
  if (((*(ulonglong *)(pVVar3 + 0x158) >> 0x3c & 1) == 0) || (**(char **)(param_2 + 0xb8) != '\x04')
     ) {
    if ((*(longlong *)(pVVar3 + 0x178) != 0) &&
       ((*(uint *)(*(longlong *)(pVVar3 + 0x178) + 0x30) & 2) != 0)) {
      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 2;
      *(uint *)(*(longlong *)(pVVar3 + 0x178) + 0x30) =
           *(uint *)(*(longlong *)(pVVar3 + 0x178) + 0x30) & 0xfffffffd;
    }
    p_Var2 = param_2 + 0xb8;
    if (((*(uint *)(param_1 + 0x30) & 2) == 0) || ((*(byte *)(*(longlong *)p_Var2 + 2) & 2) != 0)) {
      puVar4 = *(undefined8 **)p_Var2;
      puVar4[-9] = *puVar4;
      puVar4[-8] = puVar4[1];
      puVar4[-7] = puVar4[2];
      puVar4[-6] = puVar4[3];
      puVar4[-5] = puVar4[4];
      puVar4[-4] = puVar4[5];
      puVar4[-3] = puVar4[6];
      *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
      lVar5 = *(longlong *)p_Var2;
      *(code **)(lVar5 + -0x10) = VmpReadWriteCompletionRoutine;
      *(VM_VOLUME_EXTENSION **)(lVar5 + -8) = pVVar3;
      *(undefined1 *)(lVar5 + -0x45) = 0xe0;
      lVar5 = *(longlong *)p_Var2;
      uVar8 = Feature_RacyAccessesInVolmgrAreCountersEnabled__private_IsEnabledDeviceUsageNoInline()
      ;
      if ((int)uVar8 == 0) {
        if (pVVar3[0xc1] == SUB81(uVar8,0)) {
          *(undefined8 *)(lVar5 + 0x18) = 0;
        }
        else {
          (**(code **)(*(longlong *)(pVVar3 + 8) + 0x140))
                    (*(undefined8 *)(pVVar3 + 0x100),lVar5 + 0x18);
        }
      }
      else if (pVVar3[0xc1] == (VM_VOLUME_EXTENSION)0x0) {
        *(undefined8 *)(lVar5 + 0x18) = 0;
      }
      else {
        (**(code **)(*(longlong *)(pVVar3 + 8) + 0x140))
                  (*(undefined8 *)(pVVar3 + 0x100),lVar5 + 0x18);
      }
      if (pVVar3[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
        pbVar1 = (byte *)(*(longlong *)p_Var2 + -0x46);
        *pbVar1 = *pbVar1 | 0x10;
        iVar7 = IofCallDriver(*(undefined8 *)(pVVar3 + 0x178),param_2);
        if (((iVar7 == -0x7fffffea) && (*(longlong *)(pVVar3 + 0x178) != 0)) &&
           ((*(uint *)(*(longlong *)(pVVar3 + 0x178) + 0x30) & 2) != 0)) {
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 2;
          *(uint *)(*(longlong *)(pVVar3 + 0x178) + 0x30) =
               *(uint *)(*(longlong *)(pVVar3 + 0x178) + 0x30) & 0xfffffffd;
        }
      }
      else {
        param_2[0x43] = (_IRP)((char)param_2[0x43] + -1);
        *(longlong *)(param_2 + 0xb8) = *(longlong *)p_Var2 + -0x48;
        iVar7 = (**(code **)(*(longlong *)(*(longlong *)(pVVar3 + 8) + 0x188) + 0x70))
                          (*(undefined8 *)(pVVar3 + 0x1d0));
      }
    }
    else {
      IoSetHardErrorOrVerifyDevice(param_2,param_1);
      VmpDecrementRefCount(pVVar3);
      *(undefined4 *)(param_2 + 0x30) = 0x80000016;
      *(undefined8 *)(param_2 + 0x38) = 0;
      IofCompleteRequest(param_2,0);
      iVar7 = -0x7fffffea;
    }
  }
  else {
    VmpDecrementRefCount(pVVar3);
    *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    iVar7 = -0x3ffffff0;
  }
  return iVar7;
}



===== VmpProcessIrpQueueAtDispatchLevel @ 140004700 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl VmpProcessIrpQueueAtDispatchLevel(class VM_VOLUME_EXTENSION * __ptr64,struct
   _LIST_ENTRY * __ptr64) */

void __cdecl VmpProcessIrpQueueAtDispatchLevel(VM_VOLUME_EXTENSION *param_1,_LIST_ENTRY *param_2)

{
  byte bVar1;
  _LIST_ENTRY *p_Var2;
  undefined8 uVar3;
  longlong lVar4;
  byte *pbVar5;
  longlong lVar6;
  code *pcVar7;
  _LIST_ENTRY *p_Var8;
  
  p_Var2 = *(_LIST_ENTRY **)param_2;
  uVar3 = *(undefined8 *)param_1;
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 8) + 0x20);
  do {
    if (p_Var2 == param_2) {
      return;
    }
    pbVar5 = *(byte **)(p_Var2 + 0x10);
    bVar1 = *pbVar5;
    if (((bVar1 == 3) || (bVar1 == 4)) || (p_Var8 = p_Var2, bVar1 == 0x16)) {
      lVar6 = *(longlong *)p_Var2;
      p_Var8 = *(_LIST_ENTRY **)(p_Var2 + 8);
      if ((*(_LIST_ENTRY **)(lVar6 + 8) != p_Var2) || (*(_LIST_ENTRY **)p_Var8 != p_Var2)) {
        pcVar7 = (code *)swi(0x29);
        (*pcVar7)(3,p_Var2 + -0xa8);
        pcVar7 = (code *)swi(3);
        (*pcVar7)();
        return;
      }
      *(longlong *)p_Var8 = lVar6;
      *(_LIST_ENTRY **)(lVar6 + 8) = p_Var8;
      (**(code **)(lVar4 + 0x70 + (ulonglong)*pbVar5 * 8))(uVar3);
    }
    p_Var2 = *(_LIST_ENTRY **)p_Var8;
  } while( true );
}



===== VmpRestoreExtensionDriver @ 1400047a0 =====

void VmpRestoreExtensionDriver(longlong param_1)

{
  *(int *)(param_1 + 0x180) = *(int *)(param_1 + 0x180) + 1;
  if (*(int *)(param_1 + 0x180) == 1) {
    MmResetDriverPaging(**(undefined8 **)(param_1 + 0x188));
  }
  return;
}



===== VmpPageExtensionDriver @ 1400047e0 =====

void VmpPageExtensionDriver(longlong param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 + 0x180);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    MmPageEntireDriver(**(undefined8 **)(param_1 + 0x188));
  }
  return;
}



===== __report_gsfailure @ 140004820 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 14000482d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000482d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== operator_new @ 140004840 =====

/* public: static void * __ptr64 __cdecl VM_ALLOCATED_OBJECT::operator new(unsigned __int64) */

void * __cdecl VM_ALLOCATED_OBJECT::operator_new(__uint64 param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)ExAllocatePool2(0x102,0x28,0x20204d56);
  return pvVar1;
}



===== operator_delete @ 14000486c =====

/* public: static void __cdecl VM_ALLOCATED_OBJECT::operator delete(void * __ptr64) */

void __cdecl VM_ALLOCATED_OBJECT::operator_delete(void *param_1)

{
  if (param_1 != (void *)0x0) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== VmFindNextDynamicExtension @ 140004890 =====

/* void * __ptr64 __cdecl VmFindNextDynamicExtension(void * __ptr64,void * __ptr64,void * __ptr64 *
   __ptr64) */

void * __cdecl VmFindNextDynamicExtension(void *param_1,void *param_2,void **param_3)

{
  undefined8 *puVar1;
  
  *param_3 = (void *)0x0;
  if (param_2 == (void *)0x0) {
    puVar1 = *(undefined8 **)((longlong)param_1 + 0xd0);
  }
  else {
    puVar1 = *(undefined8 **)((longlong)param_2 + 0x20);
  }
  while( true ) {
    if (puVar1 == (undefined8 *)((longlong)param_1 + 0xd0)) {
      return (void *)0x0;
    }
    if ((*(char *)((longlong)puVar1 + 0x1aa) != '\0') && ((void *)puVar1[0x36] != (void *)0x0))
    break;
    puVar1 = (undefined8 *)*puVar1;
  }
  *param_3 = (void *)puVar1[0x36];
  return puVar1 + -4;
}



===== VmSetDevicePowerState @ 1400048e0 =====

/* void __cdecl VmSetDevicePowerState(void * __ptr64,enum _DEVICE_POWER_STATE) */

void __cdecl VmSetDevicePowerState(void *param_1,_DEVICE_POWER_STATE param_2)

{
  VmpSetDevicePowerState(param_1,param_2);
  return;
}



===== VmpChangeOfflineCallback @ 140004900 =====

/* long __cdecl VmpChangeOfflineCallback(class VM_VOLUME_EXTENSION * __ptr64,void * __ptr64) */

long __cdecl VmpChangeOfflineCallback(VM_VOLUME_EXTENSION *param_1,void *param_2)

{
  param_1[0xc0] = (VM_VOLUME_EXTENSION)(param_2 != (void *)0x0);
  return 0;
}



===== VmpNoOpCallback @ 140004920 =====

/* long __cdecl VmpNoOpCallback(class VM_VOLUME_EXTENSION * __ptr64,void * __ptr64) */

long __cdecl VmpNoOpCallback(VM_VOLUME_EXTENSION *param_1,void *param_2)

{
  return 0;
}



===== VmpSetAttributesCallback @ 140004930 =====

/* long __cdecl VmpSetAttributesCallback(class VM_VOLUME_EXTENSION * __ptr64,void * __ptr64) */

long __cdecl VmpSetAttributesCallback(VM_VOLUME_EXTENSION *param_1,void *param_2)

{
  *(undefined8 *)(param_1 + 0x158) = *(undefined8 *)param_2;
  return 0;
}



===== VmpStartDevice @ 140004944 =====

/* long __cdecl VmpStartDevice(class VM_VOLUME_EXTENSION * __ptr64) */

long __cdecl VmpStartDevice(VM_VOLUME_EXTENSION *param_1)

{
  bool bVar1;
  int iVar2;
  
  KeWaitForSingleObject(VmRootExtension + 0x70,0,0,0,0);
  bVar1 = VmpIsVolumeDead((longlong)param_1);
  if (bVar1) {
    iVar2 = -0x3ffffff2;
    goto LAB_140004a63;
  }
  *(undefined2 *)(param_1 + 0xbc) = 0x101;
  VmpMarkDeleted(*(_DEVICE_OBJECT **)param_1,'\0');
  *(uint *)(*(longlong *)param_1 + 0x34) = *(uint *)(*(longlong *)param_1 + 0x34) & 0xfffffeff;
  if (param_1[0x1c9] == (VM_VOLUME_EXTENSION)0x0) {
    if (param_1[0xb9] != (VM_VOLUME_EXTENSION)0x0) {
      iVar2 = VmpApplyServiceProtection(param_1);
      goto LAB_140004a0d;
    }
    if ((((*(uint *)(*(longlong *)param_1 + 0x34) & 0x40000) != 0) ||
        ((*(uint *)(*(longlong *)param_1 + 0x34) & 1) != 0)) &&
       ((*(uint *)(*(longlong *)param_1 + 0x30) & 0x600100) == 0)) {
      iVar2 = VmpApplyHotplugProtection(param_1);
      goto LAB_140004a0d;
    }
  }
  else {
    iVar2 = VmpApplyEspProtection(param_1);
LAB_140004a0d:
    if (iVar2 < 0) goto LAB_140004a63;
  }
  iVar2 = VmpInitializeInterfaces(param_1);
  if (-1 < iVar2) {
    VmpCreateLegacyNameLinks(param_1,'\0');
    if (param_1[0xb8] == (VM_VOLUME_EXTENSION)0x0) {
      iVar2 = VmpRegisterDevice(*(longlong *)param_1);
      if (iVar2 < 0) goto LAB_140004a63;
    }
    VmpSetDevicePowerState(param_1,1);
    IoInvalidateDeviceRelations(*(undefined8 *)param_1,2);
  }
LAB_140004a63:
  KeReleaseMutex(VmRootExtension + 0x70,0);
  return iVar2;
}



===== VmpTestAcquireConfig @ 140004a90 =====

/* unsigned char __cdecl VmpTestAcquireConfig(class VM_ROOT_EXTENSION * __ptr64) */

uchar __cdecl VmpTestAcquireConfig(VM_ROOT_EXTENSION *param_1)

{
  int iVar1;
  undefined8 local_res8 [4];
  
  local_res8[0] = 0;
  iVar1 = KeWaitForSingleObject(param_1 + 0x38,0,0,0,local_res8);
  return iVar1 == 0;
}



===== Feature_RacyAccessesInVolmgrAreCountersEnabled__private_IsEnabledDeviceUsageNoInline @ 140004ad0 =====

ulonglong Feature_RacyAccessesInVolmgrAreCountersEnabled__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_RacyAccessesInVolmgrAreCountersEnabled__private_featureState;
  if ((Feature_RacyAccessesInVolmgrAreCountersEnabled__private_featureState & 0x10) == 0) {
    uVar1 = Feature_RacyAccessesInVolmgrAreCountersEnabled__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_RacyAccessesInVolmgrAreCountersEnabled__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_RacyAccessesInVolmgrAreCountersEnabled__private_IsEnabledFallback @ 140004b08 =====

void Feature_RacyAccessesInVolmgrAreCountersEnabled__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_RacyAccessesInVolmgrAreCountersEnabled__private_descriptor);
  return;
}



===== Feature_Servicing_KcsanRacyAccessesInVolmgr__private_IsEnabledDeviceUsageNoInline @ 140004b24 =====

ulonglong Feature_Servicing_KcsanRacyAccessesInVolmgr__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_KcsanRacyAccessesInVolmgr__private_featureState;
  if ((Feature_Servicing_KcsanRacyAccessesInVolmgr__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_KcsanRacyAccessesInVolmgr__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_KcsanRacyAccessesInVolmgr__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_Servicing_KcsanRacyAccessesInVolmgr__private_IsEnabledFallback @ 140004b5c =====

void Feature_Servicing_KcsanRacyAccessesInVolmgr__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_KcsanRacyAccessesInVolmgr__private_descriptor);
  return;
}



===== Feature_Servicing_VolmgrHighIrqlPagedMemoryAccess__private_IsEnabledDeviceUsageNoInline @ 140004b78 =====

ulonglong Feature_Servicing_VolmgrHighIrqlPagedMemoryAccess__private_IsEnabledDeviceUsageNoInline
                    (void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_Servicing_VolmgrHighIrqlPagedMemoryAccess__private_featureState;
  if ((Feature_Servicing_VolmgrHighIrqlPagedMemoryAccess__private_featureState & 0x10) == 0) {
    uVar1 = Feature_Servicing_VolmgrHighIrqlPagedMemoryAccess__private_IsEnabledFallback
                      (local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_Servicing_VolmgrHighIrqlPagedMemoryAccess__private_featureState & 1)
    ;
  }
  return uVar1;
}



===== Feature_Servicing_VolmgrHighIrqlPagedMemoryAccess__private_IsEnabledFallback @ 140004bb0 =====

void Feature_Servicing_VolmgrHighIrqlPagedMemoryAccess__private_IsEnabledFallback
               (ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_Servicing_VolmgrHighIrqlPagedMemoryAccess__private_descriptor)
  ;
  return;
}



===== McGenControlCallbackV2 @ 140004bd0 =====

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



===== McGenEventRegister_EtwRegister @ 140004ce0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (StorageVolumeProvider_Context == 0) {
    EtwRegister(&StorageVolumeProvider,McGenControlCallbackV2,&StorageVolumeProvider_Context,
                &StorageVolumeProvider_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140004d20 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (StorageVolumeProvider_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    StorageVolumeProvider_Context = 0;
  }
  return uVar1;
}



===== RtlStringCbCopyExW @ 140004d54 =====

uint RtlStringCbCopyExW(short *param_1,ulonglong param_2,longlong param_3,undefined8 *param_4,
                       longlong *param_5)

{
  short sVar1;
  short *psVar2;
  longlong lVar3;
  longlong lVar4;
  short *psVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  
  uVar7 = param_2 >> 1;
  if (uVar7 - 1 < 0x7fffffff) {
    lVar4 = 0;
    psVar5 = param_1;
    uVar8 = uVar7;
    do {
      if (((0x7ffffffe - uVar7) + uVar8 == 0) ||
         (sVar1 = *(short *)((param_3 - (longlong)param_1) + (longlong)psVar5), sVar1 == 0)) break;
      *psVar5 = sVar1;
      lVar4 = lVar4 + 1;
      psVar5 = psVar5 + 1;
      uVar8 = uVar8 - 1;
    } while (uVar8 != 0);
    psVar2 = psVar5 + -1;
    if (uVar8 != 0) {
      psVar2 = psVar5;
    }
    *psVar2 = 0;
    lVar3 = lVar4 + -1;
    if (uVar8 != 0) {
      lVar3 = lVar4;
    }
    uVar6 = ~-(uint)(uVar8 != 0) & 0x80000005;
    if ((-1 < (int)uVar6) || (uVar6 == 0x80000005)) {
      if (param_4 != (undefined8 *)0x0) {
        *param_4 = param_1 + lVar3;
      }
      if (param_5 != (longlong *)0x0) {
        *param_5 = (ulonglong)((uint)param_2 & 1) + (uVar7 - lVar3) * 2;
      }
    }
  }
  else {
    uVar6 = 0xc000000d;
    if (uVar7 != 0) {
      *param_1 = 0;
    }
  }
  return uVar6;
}



===== VmShutdown @ 140004e40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong VmShutdown(longlong param_1,_IRP *param_2)

{
  VM_VOLUME_EXTENSION *pVVar1;
  VM_VOLUME_EXTENSION *pVVar2;
  VM_VOLUME_EXTENSION *pVVar3;
  longlong lVar4;
  long lVar5;
  VM_VOLUME_EXTENSION *pVVar6;
  undefined8 *puVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  
  pVVar3 = *(VM_VOLUME_EXTENSION **)(param_1 + 0x40);
  if (*(int *)(pVVar3 + 0x10) == 0) {
    VmpAcquireAll((VM_ROOT_EXTENSION *)pVVar3);
    if (*(longlong *)(pVVar3 + 0x188) != 0) {
      pVVar2 = pVVar3 + 0xd0;
      uVar8 = 0;
      pVVar6 = *(VM_VOLUME_EXTENSION **)pVVar2;
      if (pVVar6 == pVVar2) {
LAB_140004f99:
        VmpReleaseAll((VM_ROOT_EXTENSION *)pVVar3);
      }
      else {
        do {
          pVVar6 = *(VM_VOLUME_EXTENSION **)pVVar6;
          uVar8 = uVar8 + 1;
        } while (pVVar6 != pVVar2);
        if (uVar8 == 0) goto LAB_140004f99;
        puVar7 = (undefined8 *)ExAllocatePool2(0x42,(ulonglong)uVar8 << 3,0x20204d56);
        if (puVar7 == (undefined8 *)0x0) {
          VmpReleaseAll((VM_ROOT_EXTENSION *)pVVar3);
          uVar8 = 0xc000009a;
          *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
          goto LAB_140004ff3;
        }
        pVVar6 = *(VM_VOLUME_EXTENSION **)pVVar2;
        uVar9 = 0;
        if (pVVar6 != pVVar2) {
          do {
            pVVar1 = pVVar6 + -0x20;
            VmpAcquireRundown(pVVar1);
            lVar5 = VmpAllSystemsGo(pVVar1,(_IRP *)0x0,'\x01','\x01','\x01');
            VmpReleaseRundown(pVVar1);
            if (-1 < lVar5) {
              if (pVVar6[0x1aa] == (VM_VOLUME_EXTENSION)0x0) {
                VmpDecrementRefCount(pVVar1);
              }
              else {
                puVar7[uVar9] = pVVar1;
                uVar9 = (ulonglong)((int)uVar9 + 1);
              }
            }
            pVVar6 = *(VM_VOLUME_EXTENSION **)pVVar6;
          } while (pVVar6 != pVVar2);
        }
        VmpReleaseAll((VM_ROOT_EXTENSION *)pVVar3);
        if ((int)uVar9 != 0) {
          puVar10 = puVar7;
          do {
            pVVar2 = (VM_VOLUME_EXTENSION *)*puVar10;
            (**(code **)(*(longlong *)(pVVar3 + 0x188) + 0xe0))(*(undefined8 *)(pVVar2 + 0x1d0));
            VmpDecrementRefCount(pVVar2);
            puVar10 = puVar10 + 1;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        ExFreePoolWithTag(puVar7,0);
      }
      VmpAcquireAll((VM_ROOT_EXTENSION *)pVVar3);
      (**(code **)(*(longlong *)(pVVar3 + 0x188) + 0x50))();
    }
    uVar8 = 0;
    VmpReleaseAll((VM_ROOT_EXTENSION *)pVVar3);
    *(undefined4 *)(param_2 + 0x30) = 0;
LAB_140004ff3:
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar9 = (ulonglong)uVar8;
  }
  else {
    uVar8 = VmpAllSystemsGo(pVVar3,param_2,'\x01','\x01','\x01');
    if (uVar8 != 0x103) {
      if ((int)uVar8 < 0) {
        *(uint *)(param_2 + 0x30) = uVar8;
        goto LAB_140004ff3;
      }
      puVar7 = *(undefined8 **)(param_2 + 0xb8);
      puVar7[-9] = *puVar7;
      puVar7[-8] = puVar7[1];
      puVar7[-7] = puVar7[2];
      puVar7[-6] = puVar7[3];
      *(undefined4 *)(puVar7 + -5) = *(undefined4 *)(puVar7 + 4);
      *(undefined4 *)((longlong)puVar7 + -0x24) = *(undefined4 *)((longlong)puVar7 + 0x24);
      *(undefined4 *)(puVar7 + -4) = *(undefined4 *)(puVar7 + 5);
      *(undefined4 *)((longlong)puVar7 + -0x1c) = *(undefined4 *)((longlong)puVar7 + 0x2c);
      puVar7[-3] = puVar7[6];
      *(undefined1 *)((longlong)puVar7 + -0x45) = 0;
      lVar4 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar4 + -0x10) = VmpRefCountCompletionRoutine;
      *(undefined8 *)(lVar4 + -8) = 0x10;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      if (pVVar3[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
        uVar9 = IofCallDriver(*(undefined8 *)(pVVar3 + 400),param_2);
        return uVar9;
      }
      (**(code **)(*(longlong *)(*(longlong *)(pVVar3 + 8) + 0x188) + 0xe0))
                (*(undefined8 *)(pVVar3 + 0x1d0));
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + -0x48;
      param_2[0x43] = (_IRP)((char)param_2[0x43] + -1);
      *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) =
           *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
      (**(code **)(*(longlong *)(*(longlong *)(pVVar3 + 8) + 0x188) + 0xd8))
                (*(undefined8 *)(pVVar3 + 0x1d0),param_2,VmBroadcastIrpCompletionRoutine,param_2,0);
    }
    uVar9 = 0x103;
  }
  return uVar9;
}



===== VmpDeviceUsageNotificationCompletionRoutine @ 140005110 =====

undefined8 VmpDeviceUsageNotificationCompletionRoutine(longlong param_1,longlong param_2)

{
  VM_VOLUME_EXTENSION *pVVar1;
  longlong lVar2;
  bool bVar3;
  undefined1 uVar4;
  int iVar5;
  
  pVVar1 = *(VM_VOLUME_EXTENSION **)(param_1 + 0x40);
  bVar3 = false;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  if (*(char *)(param_2 + 0x41) != '\0') {
    *(byte *)(lVar2 + 3) = *(byte *)(lVar2 + 3) | 1;
  }
  if ((*(int *)(param_2 + 0x30) < 0) || (*(int *)(lVar2 + 0x10) != 1)) goto LAB_1400051c4;
  uVar4 = KeAcquireSpinLockRaiseToDpc(pVVar1 + 0x18);
  if (*(char *)(lVar2 + 8) == '\0') {
    iVar5 = *(int *)(pVVar1 + 0xb4) + -1;
    *(int *)(pVVar1 + 0xb4) = iVar5;
    if (iVar5 == 0) {
      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x2000;
      goto LAB_14000519d;
    }
  }
  else {
    iVar5 = *(int *)(pVVar1 + 0xb4) + 1;
    *(int *)(pVVar1 + 0xb4) = iVar5;
    if (iVar5 == 1) {
      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xffffdfff;
LAB_14000519d:
      bVar3 = true;
    }
  }
  KeReleaseSpinLock(pVVar1 + 0x18,uVar4);
  if (bVar3) {
    IoInvalidateDeviceState(*(undefined8 *)pVVar1);
  }
LAB_1400051c4:
  VmpDecrementRefCount(pVVar1);
  return 0;
}



===== _tlgDefineProvider_annotation__TlgVmTelemetryProv @ 1400051f0 =====

void _tlgDefineProvider_annotation__TlgVmTelemetryProv(void)

{
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 1400051fc =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000abdf < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140005224 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140005308 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 1400053f8 =====

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
LAB_140005554:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140005544:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140005554;
      if (uVar5 == 5) goto LAB_140005544;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 14000557c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,undefined8 param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  uint uVar3;
  int local_res18 [4];
  
  uVar3 = (uint)param_2 & 1;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar3);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,(ulonglong)uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar3,local_res18,0
               ,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140005600 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,ulonglong param_3)

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
              (*(undefined4 *)(param_1 + 0x18),param_3 & 0xffffffff,1,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_68._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_68;
    local_68 = (ulonglong)(uint6)local_68;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_68 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_68);
  }
  return (int)local_38 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400056f0 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140005800 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 140005864 =====

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



===== wil_details_IsEnabledFallback @ 1400059c4 =====

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



===== wil_details_MapReportingKind @ 140005a58 =====

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



===== wil_details_RecordCachedUsage @ 140005af8 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140005c50 =====

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



===== _guard_check_icall @ 140005ce0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140005cf8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140005d1c =====

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



===== __cpu_features_init @ 140005d90 =====

/* WARNING: Removing unreachable block (ram,0x000140005dfa) */
/* WARNING: Removing unreachable block (ram,0x000140005da9) */
/* WARNING: Removing unreachable block (ram,0x000140005d9a) */

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



===== __security_check_cookie @ 140005e60 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140005ea0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140005ed0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140005ed0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140005f00 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 140005f80 =====

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



===== memset @ 140006280 =====

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



===== __memset_repmovs @ 1400063c0 =====

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



===== __memset_query @ 140006440 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1400064c0 =====

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



===== __memset_spec_ermsb_repmovsb @ 140006600 =====

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



===== __memset_spec_plain @ 140006680 =====

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



===== VmpBuildName @ 14000f008 =====

errno_t VmpBuildName(short *param_1,int param_2,int param_3,int param_4)

{
  void *_Dst;
  errno_t eVar1;
  ulonglong uVar2;
  wchar_t *pwVar3;
  ushort uVar4;
  ulonglong uVar5;
  wchar_t *_DstBuf;
  ushort uVar6;
  longlong lVar7;
  
  uVar4 = 0;
  pwVar3 = (wchar_t *)0x0;
  _Dst = *(void **)(param_1 + 4);
  uVar6 = param_1[1];
  *param_1 = 0;
  if (param_2 == 0) {
    pwVar3 = L"\\Device\\HarddiskVolume";
    uVar4 = 0x2c;
LAB_14000f0a1:
    if (uVar4 <= uVar6) goto LAB_14000f0b1;
  }
  else {
    if ((param_2 == 1) || (param_2 == 2)) {
      pwVar3 = L"\\Device\\Harddisk";
      uVar4 = 0x20;
      goto LAB_14000f0a1;
    }
    if (param_2 == 3) {
      pwVar3 = L"\\DosDevices\\HarddiskVolume";
      uVar4 = 0x34;
      goto LAB_14000f0a1;
    }
    if ((param_2 == 4) || (param_2 == 5)) {
      pwVar3 = L"\\DosDevices\\Harddisk";
      uVar4 = 0x28;
      goto LAB_14000f0a1;
    }
LAB_14000f0b1:
    memcpy(_Dst,pwVar3,(ulonglong)uVar4);
    _DstBuf = (wchar_t *)((longlong)_Dst + (ulonglong)uVar4);
    uVar6 = uVar6 - uVar4;
    eVar1 = _itow_s(param_3,_DstBuf,(ulonglong)uVar6,10);
    if (-1 < eVar1) {
      lVar7 = -1;
      uVar5 = 0xffffffffffffffff;
      do {
        uVar5 = uVar5 + 1;
      } while (_DstBuf[uVar5] != L'\0');
      uVar2 = uVar5 & 0xffff;
      uVar6 = uVar6 + (short)uVar5 * -2;
      if (param_2 == 0) goto LAB_14000f1d3;
      if (param_2 == 1) {
        pwVar3 = L"\\Partition";
        uVar5 = 0x14;
      }
      else if (param_2 == 2) {
        pwVar3 = L"\\ClusterPartition";
        uVar5 = 0x22;
      }
      else {
        if (param_2 == 3) goto LAB_14000f1d3;
        if (param_2 == 4) {
          pwVar3 = L"Partition";
          uVar5 = 0x12;
        }
        else if (param_2 == 5) {
          pwVar3 = L"ClusterPartition";
          uVar5 = 0x20;
        }
      }
      if ((ushort)uVar5 <= uVar6) {
        memcpy(_DstBuf + uVar2,pwVar3,uVar5 & 0xffff);
        pwVar3 = (wchar_t *)((longlong)(_DstBuf + uVar2) + (uVar5 & 0xffff));
        uVar6 = uVar6 - (ushort)uVar5;
        eVar1 = _itow_s(param_4,pwVar3,(ulonglong)uVar6,10);
        if (-1 < eVar1) {
          do {
            lVar7 = lVar7 + 1;
          } while (pwVar3[lVar7] != L'\0');
          uVar6 = uVar6 + (short)lVar7 * -2;
          goto LAB_14000f1d3;
        }
      }
    }
  }
  eVar1 = -0x3fffffdd;
LAB_14000f1d3:
  *param_1 = param_1[1] - uVar6;
  return eVar1;
}



===== VmpProcessDiskNotifications @ 14000f210 =====

/* void __cdecl VmpProcessDiskNotifications(class VM_ROOT_EXTENSION * __ptr64) */

void __cdecl VmpProcessDiskNotifications(VM_ROOT_EXTENSION *param_1)

{
  VM_ROOT_EXTENSION *pVVar1;
  int iVar2;
  VM_ROOT_EXTENSION *pVVar3;
  code *pcVar4;
  longlong lVar5;
  
  pVVar1 = param_1 + 0xb8;
  do {
    pVVar3 = *(VM_ROOT_EXTENSION **)pVVar1;
    if (pVVar3 == pVVar1) {
      return;
    }
    if ((*(VM_ROOT_EXTENSION **)(pVVar3 + 8) != pVVar1) ||
       (lVar5 = *(longlong *)pVVar3, *(VM_ROOT_EXTENSION **)(lVar5 + 8) != pVVar3)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      return;
    }
    *(longlong *)pVVar1 = lVar5;
    *(VM_ROOT_EXTENSION **)(lVar5 + 8) = pVVar1;
    iVar2 = *(int *)(pVVar3 + 0x10);
    if (iVar2 == 0) {
      VmpWholeDiskArrivedDelayed(param_1,*(_DEVICE_OBJECT **)(pVVar3 + 0x18));
LAB_14000f2d0:
      lVar5 = *(longlong *)(pVVar3 + 0x18);
LAB_14000f2d4:
      ObfDereferenceObject(lVar5);
    }
    else {
      if (iVar2 == 1) {
        VmpPartitionArrivedDelayed
                  (param_1,*(_DEVICE_OBJECT **)(pVVar3 + 0x18),*(_DEVICE_OBJECT **)(pVVar3 + 0x20));
        ObfDereferenceObject(*(longlong *)(pVVar3 + 0x20));
        goto LAB_14000f2d0;
      }
      if (iVar2 == 2) {
        VmpPartitionRemovedDelayed
                  (param_1,*(_DEVICE_OBJECT **)(pVVar3 + 0x18),*(_DEVICE_OBJECT **)(pVVar3 + 0x20));
        ObfDereferenceObject(*(longlong *)(pVVar3 + 0x20));
        lVar5 = *(longlong *)(pVVar3 + 0x18);
        if (lVar5 == 0) goto LAB_14000f2e0;
        goto LAB_14000f2d4;
      }
      if (iVar2 == 3) {
        VmpWholeDiskRemovedDelayed(param_1,*(_DEVICE_OBJECT **)(pVVar3 + 0x18));
        goto LAB_14000f2d0;
      }
    }
LAB_14000f2e0:
    VM_ALLOCATED_OBJECT::operator_delete(pVVar3);
  } while( true );
}



===== VmAcquireAll @ 14000f310 =====

/* void __cdecl VmAcquireAll(void * __ptr64) */

void __cdecl VmAcquireAll(void *param_1)

{
  VmpAcquireAll(param_1);
  return;
}



===== VmAcquireDevices @ 14000f330 =====

/* void __cdecl VmAcquireDevices(void * __ptr64) */

void __cdecl VmAcquireDevices(void *param_1)

{
  VmpAcquireDevices(param_1);
  return;
}



===== VmCommitDevices @ 14000f350 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* void __cdecl VmCommitDevices(void * __ptr64,unsigned long,struct _VM_DEVICE_CHANGE * __ptr64) */

void __cdecl VmCommitDevices(void *param_1,ulong param_2,_VM_DEVICE_CHANGE *param_3)

{
  VM_VOLUME_EXTENSION *pVVar1;
  VM_VOLUME_EXTENSION VVar2;
  VM_VOLUME_EXTENSION *pVVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  bool bVar7;
  char cVar8;
  uint uVar9;
  undefined4 uVar10;
  long lVar11;
  __uint64 _Var12;
  ulonglong uVar13;
  VM_VOLUME_EXTENSION *pVVar14;
  uint uVar15;
  _VM_DEVICE_CHANGE *p_Var16;
  int iVar17;
  undefined1 auStack_168 [32];
  uint local_148;
  longlong local_140;
  ulong local_138;
  _VM_DEVICE_CHANGE *local_130;
  _VM_DEVICE_CHANGE local_128;
  undefined1 local_127 [7];
  longlong local_120;
  _DEVICE_OBJECT *local_118;
  longlong local_110;
  undefined4 local_108;
  ushort *local_100;
  undefined4 local_f8;
  longlong local_f0;
  longlong local_e8;
  longlong local_e0;
  longlong lStack_d8;
  _VM_DEVICE_CHANGE local_d0;
  longlong local_c8;
  ushort local_b8;
  uchar local_b6 [54];
  ushort local_80;
  uchar local_7e [54];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_168;
  local_140 = *(longlong *)((longlong)param_1 + 0x188);
  local_138 = param_2;
  local_130 = param_3;
  memset(&local_128,0,0x68);
  bVar7 = false;
  uVar15 = 0;
  if (param_2 != 0) {
    p_Var16 = param_3 + 0x10;
    do {
      pVVar3 = *(VM_VOLUME_EXTENSION **)(p_Var16 + -0x10);
      if (pVVar3 != (VM_VOLUME_EXTENSION *)0x0) {
        if (*p_Var16 == (_VM_DEVICE_CHANGE)0x0) {
          lVar4 = *(longlong *)(p_Var16 + 8);
        }
        else {
          lVar4 = *(longlong *)(p_Var16 + 0x58);
        }
        if (lVar4 == 0) {
          *(undefined8 *)(pVVar3 + 0x30) = _DAT_fffff78000000014;
          if (pVVar3[0xbe] == (VM_VOLUME_EXTENSION)0x0) {
            pVVar14 = pVVar3 + 0x20;
            lVar4 = *(longlong *)pVVar14;
            if ((*(VM_VOLUME_EXTENSION **)(lVar4 + 8) != pVVar14) ||
               (plVar5 = *(longlong **)(pVVar3 + 0x28), (VM_VOLUME_EXTENSION *)*plVar5 != pVVar14))
            goto LAB_14000f8d1;
            *plVar5 = lVar4;
            *(longlong **)(lVar4 + 8) = plVar5;
            VmpCleanupVolumeExtension(pVVar3);
            IoDeleteDevice(*(undefined8 *)pVVar3);
          }
          else {
            if (p_Var16[1] != (_VM_DEVICE_CHANGE)0x0) {
              VmpNotify(pVVar3,(_GUID *)&GUID_IO_VOLUME_PREPARE_DELETE,0,(void *)0x0);
            }
            VmpDeleteLegacyNameLinks(pVVar3,'\0');
            VmpReleaseInterfaces((longlong)pVVar3);
            memset(local_127,0,0x67);
            local_128 = *p_Var16;
            VmpZeroRefCallback(pVVar3,VmpSetTargetCallback,&local_128);
            pVVar14 = pVVar3 + 0x20;
            lVar4 = *(longlong *)pVVar14;
            if ((*(VM_VOLUME_EXTENSION **)(lVar4 + 8) != pVVar14) ||
               (plVar5 = *(longlong **)(pVVar3 + 0x28), (VM_VOLUME_EXTENSION *)*plVar5 != pVVar14))
            goto LAB_14000f8d1;
            *plVar5 = lVar4;
            *(longlong **)(lVar4 + 8) = plVar5;
            plVar5 = *(longlong **)((longlong)param_1 + 0xe8);
            if (*plVar5 != (longlong)param_1 + 0xe0) goto LAB_14000f8d1;
            *(longlong *)pVVar14 = (longlong)param_1 + 0xe0;
            *(longlong **)(pVVar3 + 0x28) = plVar5;
            *plVar5 = (longlong)pVVar14;
            *(VM_VOLUME_EXTENSION **)((longlong)param_1 + 0xe8) = pVVar14;
            if (p_Var16[1] != (_VM_DEVICE_CHANGE)0x0) {
              pVVar3[0xbf] = (VM_VOLUME_EXTENSION)0x1;
            }
            bVar7 = true;
          }
        }
      }
      uVar15 = uVar15 + 1;
      p_Var16 = p_Var16 + 0x70;
    } while (uVar15 < param_2);
    uVar15 = 0;
    p_Var16 = local_130 + 0x68;
    do {
      pVVar3 = *(VM_VOLUME_EXTENSION **)(p_Var16 + -0x68);
      if (pVVar3 != (VM_VOLUME_EXTENSION *)0x0) {
        if (p_Var16[-0x58] == (_VM_DEVICE_CHANGE)0x0) {
          lVar4 = *(longlong *)(p_Var16 + -0x50);
        }
        else {
          lVar4 = *(longlong *)p_Var16;
        }
        if (lVar4 != 0) {
          VVar2 = pVVar3[0x1ca];
          local_b8 = 0x30;
          uVar9 = VmpQueryUniqueIdInternal(pVVar3,&local_b8,local_b6);
          local_148 = uVar9 >> 0x1f;
          VmpDeleteLegacyNameLinks(pVVar3,'\0');
          memset(&local_128,0,0x68);
          local_128 = p_Var16[-0x58];
          if (local_128 == (_VM_DEVICE_CHANGE)0x0) {
            *(undefined4 *)(*(longlong *)pVVar3 + 0x98) =
                 *(undefined4 *)(*(longlong *)(p_Var16 + -0x50) + 0x98);
            *(char *)(*(longlong *)pVVar3 + 0x4c) =
                 *(char *)(*(longlong *)(p_Var16 + -0x50) + 0x4c) + '\x01';
            local_120 = *(longlong *)(p_Var16 + -0x50);
            local_e0 = *(longlong *)(p_Var16 + -0x20);
            lStack_d8 = *(longlong *)(p_Var16 + -0x18);
            local_118 = *(_DEVICE_OBJECT **)(p_Var16 + -0x48);
            local_110 = *(longlong *)(p_Var16 + -0x40);
            local_108 = *(undefined4 *)(p_Var16 + -0x38);
            local_f8 = *(undefined4 *)(p_Var16 + -0x34);
            local_f0 = *(longlong *)(p_Var16 + -0x30);
            local_e8 = *(longlong *)(p_Var16 + -0x28);
            local_d0 = p_Var16[-8];
            uVar13 = Feature_Servicing_VolmgrHighIrqlPagedMemoryAccess__private_IsEnabledDeviceUsageNoInline
                               ();
            if ((int)uVar13 != 0) {
              VmpGetInstancePath(local_118,&local_100);
            }
            pVVar14 = VmpFindExtensionForPendingBasicVolume
                                (param_1,*(_DEVICE_OBJECT **)(p_Var16 + -0x50));
            if (pVVar14 != (VM_VOLUME_EXTENSION *)0x0) {
              pVVar1 = pVVar14 + 0x20;
              lVar4 = *(longlong *)pVVar1;
              if ((*(VM_VOLUME_EXTENSION **)(lVar4 + 8) != pVVar1) ||
                 (plVar5 = *(longlong **)(pVVar14 + 0x28), (VM_VOLUME_EXTENSION *)*plVar5 != pVVar1)
                 ) goto LAB_14000f8d1;
              *plVar5 = lVar4;
              *(longlong **)(lVar4 + 8) = plVar5;
              VmpCleanupVolumeExtension(pVVar14);
              IoDeleteDevice(*(undefined8 *)pVVar14);
            }
            uVar9 = local_148;
          }
          else {
            uVar10 = (**(code **)(local_140 + 0x88))(*(longlong *)p_Var16);
            *(undefined4 *)(*(longlong *)pVVar3 + 0x98) = uVar10;
            cVar8 = (**(code **)(local_140 + 0x80))(*(longlong *)p_Var16);
            *(char *)(*(longlong *)pVVar3 + 0x4c) = cVar8 + '\x02';
            local_c8 = *(longlong *)p_Var16;
            uVar9 = uVar9 >> 0x1f;
          }
          VmpZeroRefCallback(pVVar3,VmpSetTargetCallback,&local_128);
          if (p_Var16[-0x58] != (_VM_DEVICE_CHANGE)0x0) {
            _Var12 = (**(code **)(local_140 + 0x98))(*(undefined8 *)(pVVar3 + 0x1d0));
            VmpApplyGptAttributes(pVVar3,_Var12);
          }
          VmpCreateLegacyNameLinks(pVVar3,'\0');
          VmpSetDevicePowerState(pVVar3,*(_DEVICE_POWER_STATE *)(p_Var16 + -0x54));
          if (p_Var16[-0x58] == (_VM_DEVICE_CHANGE)0x0) {
            if (VVar2 != (VM_VOLUME_EXTENSION)0x0) {
              VmpPageExtensionDriver((longlong)param_1);
            }
          }
          else if (VVar2 == (VM_VOLUME_EXTENSION)0x0) {
            VmpRestoreExtensionDriver((longlong)param_1);
          }
          if (pVVar3[0xbe] != (VM_VOLUME_EXTENSION)0x0) {
            IoInvalidateDeviceRelations(*(undefined8 *)pVVar3,2);
          }
          local_80 = 0x30;
          lVar11 = VmpQueryUniqueIdInternal(pVVar3,&local_80,local_7e);
          if (((((char)uVar9 != '\0') || (lVar11 < 0)) || (local_80 != local_b8)) ||
             (uVar13 = RtlCompareMemory(local_7e,local_b6), uVar13 != local_b8)) {
            VmpNotify(pVVar3,(_GUID *)&GUID_IO_VOLUME_UNIQUE_ID_CHANGE,local_80 + 2,&local_80);
          }
          VmpNotify(pVVar3,(_GUID *)&GUID_IO_VOLUME_PHYSICAL_CONFIGURATION_CHANGE,0,(void *)0x0);
          param_2 = local_138;
        }
      }
      uVar15 = uVar15 + 1;
      p_Var16 = p_Var16 + 0x70;
    } while (uVar15 < param_2);
    uVar15 = 0;
    p_Var16 = local_130 + 0x68;
    do {
      iVar17 = 0;
      if (*(longlong *)(p_Var16 + -0x68) == 0) {
        if (p_Var16[-0x58] == (_VM_DEVICE_CHANGE)0x0) {
          lVar4 = *(longlong *)(p_Var16 + -0x50);
        }
        else {
          lVar4 = *(longlong *)p_Var16;
        }
        if (lVar4 != 0) {
          pVVar14 = VmpFindExtensionForPendingDynamicVolume(param_1,*(void **)p_Var16);
          pVVar3 = pVVar14 + 0x20;
          lVar4 = *(longlong *)pVVar3;
          if ((*(VM_VOLUME_EXTENSION **)(lVar4 + 8) != pVVar3) ||
             (plVar5 = *(longlong **)(pVVar14 + 0x28), (VM_VOLUME_EXTENSION *)*plVar5 != pVVar3)) {
LAB_14000f8d1:
            pcVar6 = (code *)swi(0x29);
            (*pcVar6)(3);
            pcVar6 = (code *)swi(3);
            (*pcVar6)();
            return;
          }
          *plVar5 = lVar4;
          *(longlong **)(lVar4 + 8) = plVar5;
          (**(code **)(local_140 + 0xe8))(0,*(longlong *)p_Var16,iVar17 < *(int *)(pVVar14 + 0xb4));
          plVar5 = *(longlong **)((longlong)param_1 + 0xd8);
          if (*plVar5 != (longlong)param_1 + 0xd0) goto LAB_14000f8d1;
          *(longlong **)(pVVar14 + 0x28) = plVar5;
          *(longlong *)pVVar3 = (longlong)param_1 + 0xd0;
          *plVar5 = (longlong)pVVar3;
          *(VM_VOLUME_EXTENSION **)((longlong)param_1 + 0xd8) = pVVar3;
          VmpSetDevicePowerState(pVVar14,*(_DEVICE_POWER_STATE *)(p_Var16 + -0x54));
          bVar7 = true;
        }
      }
      uVar15 = uVar15 + 1;
      p_Var16 = p_Var16 + 0x70;
    } while (uVar15 < param_2);
    if (bVar7) {
      IoInvalidateDeviceRelations(*(undefined8 *)((longlong)param_1 + 0x30),5);
    }
  }
  return;
}



===== VmCreatePendingDynamicDevice @ 14000f8e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl VmCreatePendingDynamicDevice(void * __ptr64,void * __ptr64) */

long __cdecl VmCreatePendingDynamicDevice(void *param_1,void *param_2)

{
  code *pcVar1;
  long lVar2;
  __uint64 _Var3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  _DEVICE_OBJECT *local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_68;
  lVar4 = *(longlong *)((longlong)param_1 + 0x188);
  local_28 = (_DEVICE_OBJECT *)0x0;
  local_20 = 0;
  uStack_18 = 0;
  (**(code **)(lVar4 + 0x78))(param_2,&local_20);
  if (*(longlong *)((longlong)param_1 + 0x168) != 0) {
    VmpCheckForRevertGptAttributes
              (param_1,'\x01','\0',(_GUID *)&local_20,(_GUID *)0x0,0,param_2,(_DEVICE_OBJECT *)0x0);
  }
  _Var3 = (**(code **)(lVar4 + 0x98))(param_2);
  lVar2 = VmpCreateDynamicDevice(param_2,(_GUID *)&local_20,_Var3,&local_28);
  puVar7 = auStackY_68;
  puVar8 = auStackY_68;
  if (-1 < lVar2) {
    lVar4 = (longlong)param_1 + 0xf0;
    plVar6 = *(longlong **)((longlong)param_1 + 0xf8);
    plVar5 = (longlong *)(*(longlong *)(local_28 + 0x40) + 0x20);
    if (*plVar6 != lVar4) {
      plVar5 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      lVar4 = (*pcVar1)();
      puVar7 = auStackY_60;
    }
    *plVar5 = lVar4;
    plVar5[1] = (longlong)plVar6;
    *plVar6 = (longlong)plVar5;
    *(longlong **)(lVar4 + 8) = plVar5;
    lVar2 = 0;
    puVar8 = puVar7;
  }
  *(undefined8 *)(puVar8 + -8) = 0x14000f9c4;
  return lVar2;
}



===== VmDeletePendingDynamicDevice @ 14000f9e0 =====

/* void __cdecl VmDeletePendingDynamicDevice(void * __ptr64,void * __ptr64) */

void __cdecl VmDeletePendingDynamicDevice(void *param_1,void *param_2)

{
  VM_VOLUME_EXTENSION *pVVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  VM_VOLUME_EXTENSION *pVVar5;
  
  pVVar5 = VmpFindExtensionForPendingDynamicVolume(param_1,param_2);
  if (pVVar5 != (VM_VOLUME_EXTENSION *)0x0) {
    pVVar1 = pVVar5 + 0x20;
    lVar2 = *(longlong *)pVVar1;
    if ((*(VM_VOLUME_EXTENSION **)(lVar2 + 8) != pVVar1) ||
       (plVar3 = *(longlong **)(pVVar5 + 0x28), (VM_VOLUME_EXTENSION *)*plVar3 != pVVar1)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    VmpCleanupVolumeExtension(pVVar5);
    IoDeleteDevice(*(undefined8 *)pVVar5);
  }
  return;
}



===== VmFreezeBasicDeviceCreation @ 14000fa40 =====

/* void __cdecl VmFreezeBasicDeviceCreation(void * __ptr64,struct _DEVICE_OBJECT * __ptr64) */

void __cdecl VmFreezeBasicDeviceCreation(void *param_1,_DEVICE_OBJECT *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined1 *puVar6;
  char cVar7;
  longlong lVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
  puVar6 = auStack_28;
  lVar8 = 0;
  if (param_2 == (_DEVICE_OBJECT *)0x0) {
    *(undefined8 *)((longlong)param_1 + 0x110) = 0;
    plVar1 = (longlong *)((longlong)param_1 + 0x100);
    while (cVar7 = (char)lVar8, plVar2 = (longlong *)*plVar1, plVar2 != plVar1) {
      if (((longlong *)plVar2[1] != plVar1) ||
         (lVar8 = *plVar2, *(longlong **)(lVar8 + 8) != plVar2)) {
LAB_14000faa5:
        cVar7 = (char)lVar8;
        param_1 = (void *)0x3;
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)();
        puVar6 = auStack_20;
        break;
      }
      *plVar1 = lVar8;
      *(longlong **)(lVar8 + 8) = plVar1;
      lVar8 = (longlong)param_1 + 0xd0;
      plVar3 = *(longlong **)((longlong)param_1 + 0xd8);
      if (*plVar3 != lVar8) goto LAB_14000faa5;
      *plVar2 = lVar8;
      plVar2[1] = (longlong)plVar3;
      *plVar3 = (longlong)plVar2;
      *(longlong **)((longlong)param_1 + 0xd8) = plVar2;
      lVar8 = 1;
    }
    if (cVar7 != '\0') {
      uVar4 = *(undefined8 *)((longlong)param_1 + 0x30);
      *(undefined8 *)(puVar6 + -8) = 0x14000fac1;
      IoInvalidateDeviceRelations(uVar4,5);
    }
  }
  else {
    *(_DEVICE_OBJECT **)((longlong)param_1 + 0x110) = param_2;
  }
  return;
}



===== VmLoadExtensionDriver @ 14000fae0 =====

/* void __cdecl VmLoadExtensionDriver(void * __ptr64) */

void __cdecl VmLoadExtensionDriver(void *param_1)

{
  VmpRestoreExtensionDriver((longlong)param_1);
  return;
}



===== VmQueryBasicExtension @ 14000fb00 =====

/* void * __ptr64 __cdecl VmQueryBasicExtension(void * __ptr64,unsigned long,unsigned
   __int64,unsigned __int64,struct _DEVICE_OBJECT * __ptr64 * __ptr64) */

void * __cdecl
VmQueryBasicExtension
          (void *param_1,ulong param_2,__uint64 param_3,__uint64 param_4,_DEVICE_OBJECT **param_5)

{
  VM_VOLUME_EXTENSION *pVVar1;
  _DEVICE_OBJECT *p_Var2;
  
  pVVar1 = VmpFindExtensionForPartition(param_1,param_2,param_3,param_4);
  p_Var2 = (_DEVICE_OBJECT *)0x0;
  if (param_5 != (_DEVICE_OBJECT **)0x0) {
    if (pVVar1 != (VM_VOLUME_EXTENSION *)0x0) {
      p_Var2 = *(_DEVICE_OBJECT **)(pVVar1 + 0x178);
    }
    *param_5 = p_Var2;
  }
  return pVVar1;
}



===== VmQueryBootInformation @ 14000fb30 =====

/* void __cdecl VmQueryBootInformation(void * __ptr64,struct _BOOTDISK_INFORMATION_LITE * __ptr64 *
   __ptr64) */

void __cdecl VmQueryBootInformation(void *param_1,_BOOTDISK_INFORMATION_LITE **param_2)

{
  *param_2 = *(_BOOTDISK_INFORMATION_LITE **)((longlong)param_1 + 0x158);
  return;
}



===== VmQueryUniqueIdBuffer @ 14000fb50 =====

/* long __cdecl VmQueryUniqueIdBuffer(void * __ptr64,unsigned short * __ptr64,unsigned char *
   __ptr64) */

long __cdecl VmQueryUniqueIdBuffer(void *param_1,ushort *param_2,uchar *param_3)

{
  long lVar1;
  
  lVar1 = VmpQueryUniqueIdInternal(param_1,param_2,param_3);
  return lVar1;
}



===== VmReleaseAll @ 14000fb70 =====

/* void __cdecl VmReleaseAll(void * __ptr64) */

void __cdecl VmReleaseAll(void *param_1)

{
  VmpReleaseAll(param_1);
  return;
}



===== VmReleaseDevices @ 14000fb90 =====

/* void __cdecl VmReleaseDevices(void * __ptr64) */

void __cdecl VmReleaseDevices(void *param_1)

{
  VmpReleaseDevices(param_1);
  return;
}



===== VmUnloadExtensionDriver @ 14000fbb0 =====

/* void __cdecl VmUnloadExtensionDriver(void * __ptr64) */

void __cdecl VmUnloadExtensionDriver(void *param_1)

{
  VmpPageExtensionDriver((longlong)param_1);
  return;
}



===== VmpAllocateBCStream @ 14000fbc8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl VmpAllocateBCStream(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpAllocateBCStream(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  int iStack_24;
  int local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined2 local_1a;
  int local_18;
  int local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
    if ((((*(uint *)(lVar1 + 0x10) < 0x28) || (*(uint *)(lVar1 + 8) < 0x10)) ||
        (piVar2 = *(int **)(param_2 + 0x18), *piVar2 != 1)) ||
       ((*(ulonglong *)(piVar2 + 6) < *(ulonglong *)(piVar2 + 4) ||
        (*(ulonglong *)(param_1 + 0x1b0) <= *(ulonglong *)(piVar2 + 6))))) {
      iVar3 = -0x3ffffff3;
    }
    else {
      local_1a = 0;
      local_28 = 1;
      iStack_24 = piVar2[1];
      local_20 = piVar2[2];
      local_1c = (undefined1)piVar2[3];
      local_1b = *(undefined1 *)((longlong)piVar2 + 0xd);
      local_18 = piVar2[8];
      local_14 = piVar2[9];
      *(undefined1 *)(lVar1 + 1) = 4;
      *(undefined4 *)(lVar1 + 8) = 0x10;
      *(undefined4 *)(lVar1 + 0x10) = 0x18;
      *(undefined4 *)(lVar1 + 0x18) = 0x2dd804;
      *(undefined4 **)(param_2 + 0x18) = &local_28;
      IoForwardIrpSynchronously(*(undefined8 *)(param_1 + 400),param_2);
      iVar3 = *(int *)(param_2 + 0x30);
      *(int **)(param_2 + 0x18) = piVar2;
      if (-1 < iVar3) {
        piVar2[0] = 0;
        piVar2[1] = 0;
        piVar2[2] = 0;
        piVar2[3] = 0;
        *(ulonglong *)piVar2 = CONCAT44(iStack_24,local_28);
        piVar2[2] = local_20;
        *(undefined8 *)(param_2 + 0x38) = 0x10;
      }
    }
  }
  else {
    iVar3 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x188) + 0x68))
                      (*(undefined8 *)(param_1 + 0x1d0),param_2);
  }
  return iVar3;
}



===== VmpApplyEspProtection @ 14000fd1c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl VmpApplyEspProtection(class VM_VOLUME_EXTENSION * __ptr64) */

long __cdecl VmpApplyEspProtection(VM_VOLUME_EXTENSION *param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  undefined4 *puVar8;
  longlong lVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined2 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  lVar2 = *(longlong *)param_1;
  local_38 = 0;
  local_30 = 0;
  local_2c = 0x500;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  lVar7 = ExAllocatePool2(0x102,0x44,0x20204d56);
  if (lVar7 == 0) {
    iVar3 = -0x3fffff66;
  }
  else {
    iVar3 = RtlInitializeSid(lVar7,&local_30,6);
    if (-1 < iVar3) {
      uVar10 = 0;
      puVar11 = &DAT_140008910;
      do {
        uVar1 = *puVar11;
        puVar8 = (undefined4 *)RtlSubAuthoritySid(lVar7,uVar10);
        uVar10 = uVar10 + 1;
        puVar11 = puVar11 + 1;
        *puVar8 = uVar1;
      } while (uVar10 < 6);
      iVar3 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
      iVar4 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
      iVar5 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0xc0));
      iVar6 = RtlLengthSid(lVar7);
      iVar3 = iVar3 + iVar4 + iVar5 + iVar6 + 0x38;
      lVar9 = ExAllocatePool2(0x102,iVar3,0x20204d56);
      if (lVar9 == 0) {
        iVar3 = -0x3fffff66;
      }
      else {
        iVar3 = RtlCreateAcl(lVar9,iVar3,2);
        if (-1 < iVar3) {
          iVar3 = RtlAddAccessAllowedAce
                            (lVar9,2,0x120080,*(undefined8 *)(*(longlong *)SeExports_exref + 0xc0));
          if (-1 < iVar3) {
            iVar3 = RtlAddAccessAllowedAce
                              (lVar9,2,0x10000000,
                               *(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
            if (-1 < iVar3) {
              iVar3 = RtlAddAccessAllowedAce
                                (lVar9,2,0x10000000,
                                 *(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
              if (-1 < iVar3) {
                iVar3 = RtlAddAccessAllowedAce(lVar9,2,0x10000000,lVar7);
                if (-1 < iVar3) {
                  iVar3 = RtlCreateSecurityDescriptor(&local_58,1);
                  if (-1 < iVar3) {
                    iVar3 = RtlSetDaclSecurityDescriptor(&local_58,1,lVar9,0);
                    if (-1 < iVar3) {
                      iVar3 = ObSetSecurityObjectByPointer(lVar2,4,&local_58);
                      if (-1 < iVar3) {
                        *(uint *)(lVar2 + 0x34) = *(uint *)(lVar2 + 0x34) | 0x100100;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        ExFreePoolWithTag(lVar9,0);
      }
    }
    ExFreePoolWithTag(lVar7,0);
  }
  return iVar3;
}



===== VmpApplyGptAttributes @ 140010008 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl VmpApplyGptAttributes(class VM_VOLUME_EXTENSION * __ptr64,unsigned __int64) */

void __cdecl VmpApplyGptAttributes(VM_VOLUME_EXTENSION *param_1,__uint64 param_2)

{
  int iVar1;
  ulonglong uVar2;
  code *pcVar3;
  undefined8 uVar4;
  byte bVar5;
  VM_VOLUME_EXTENSION VVar6;
  __uint64 local_res10;
  undefined1 auStackY_78 [32];
  undefined8 local_48;
  ulonglong uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_78;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_res10 = param_2;
  if (*(__uint64 *)(param_1 + 0x158) != param_2) {
    pcVar3 = VmpSetAttributesCallback;
    VmpZeroRefCallback(param_1,VmpSetAttributesCallback,&local_res10);
    param_2 = (__uint64)pcVar3;
  }
  VVar6 = (VM_VOLUME_EXTENSION)((local_res10 & 0x4000000000000000) != 0);
  if (param_1[0xba] == (VM_VOLUME_EXTENSION)0x0) {
    if (((local_res10 & 0x4000000000000000) == 0) && (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0)) {
      param_2 = 0x70214;
      uVar2 = VmpSendDeviceControl(*(undefined8 *)(param_1 + 400),0x70214,0,0,&local_48,0x20);
      if ((-1 < (int)uVar2) && (((uStack_40 & 2) != 0 && ((uStack_40 & 4) == 0)))) {
        VVar6 = (VM_VOLUME_EXTENSION)0x1;
      }
    }
  }
  else {
    VVar6 = (VM_VOLUME_EXTENSION)0x1;
  }
  if (param_1[0xb8] != VVar6) {
    if (param_1[0xbc] != (VM_VOLUME_EXTENSION)0x0) {
      uVar4 = 0;
      iVar1 = IoSetDeviceInterfaceState(param_1 + ((ulonglong)(byte)VVar6 ^ 1) * 0x10 + 200,0);
      if (iVar1 < 0) {
        return;
      }
      param_2 = CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
      iVar1 = IoSetDeviceInterfaceState(param_1 + (ulonglong)(byte)VVar6 * 0x10 + 200,param_2);
      if (iVar1 < 0) {
        return;
      }
    }
    param_1[0xb8] = VVar6;
  }
  bVar5 = (byte)(local_res10 >> 0x39);
  VVar6 = (VM_VOLUME_EXTENSION)(bVar5 & 1);
  if (param_1[0xb9] != VVar6) {
    if ((param_1[0xbc] != (VM_VOLUME_EXTENSION)0x0) &&
       (iVar1 = IoSetDeviceInterfaceState
                          (param_1 + 0xe8,CONCAT71((int7)(param_2 >> 8),bVar5) & 0xffffffffffffff01)
       , iVar1 < 0)) {
      return;
    }
    param_1[0xb9] = VVar6;
  }
  return;
}



===== VmpApplyServiceProtection @ 1400101a0 =====

/* long __cdecl VmpApplyServiceProtection(class VM_VOLUME_EXTENSION * __ptr64) */

long __cdecl VmpApplyServiceProtection(VM_VOLUME_EXTENSION *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  iVar1 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x210));
  iVar2 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
  iVar3 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
  iVar1 = iVar1 + iVar2 + iVar3 + 0x20;
  lVar4 = ExAllocatePool2(0x102,iVar1,0x20204d56);
  if (lVar4 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = RtlCreateAcl(lVar4,iVar1,2);
    if (-1 < iVar1) {
      iVar1 = RtlAddAccessAllowedAce
                        (lVar4,2,0x80000000,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
      if (-1 < iVar1) {
        iVar1 = RtlAddAccessAllowedAce
                          (lVar4,2,0x80000000,*(undefined8 *)(*(longlong *)SeExports_exref + 0x210))
        ;
        if (-1 < iVar1) {
          iVar1 = RtlAddAccessAllowedAce
                            (lVar4,2,0x80000000,
                             *(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
          if (-1 < iVar1) {
            iVar1 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x218));
            lVar5 = ExAllocatePool2(0x102,iVar1 + 0x10,0x20204d56);
            if (lVar5 == 0) {
              iVar1 = -0x3fffff66;
            }
            else {
              iVar1 = RtlCreateAcl(lVar5,iVar1 + 0x10,2);
              if (-1 < iVar1) {
                iVar1 = RtlAddProcessTrustLabelAce
                                  (lVar5,2,0,*(undefined8 *)(*(longlong *)SeExports_exref + 0x218),
                                   0x14,0x120089);
                if (-1 < iVar1) {
                  iVar1 = RtlCreateSecurityDescriptor(&local_38,1);
                  if (-1 < iVar1) {
                    iVar1 = RtlSetDaclSecurityDescriptor(&local_38,1,lVar4,0);
                    if (-1 < iVar1) {
                      iVar1 = RtlSetSaclSecurityDescriptor(&local_38,1,lVar5,0);
                      if (-1 < iVar1) {
                        iVar1 = ObSetSecurityObjectByPointer(*(undefined8 *)param_1,0x84,&local_38);
                        *(uint *)(*(longlong *)param_1 + 0x34) =
                             *(uint *)(*(longlong *)param_1 + 0x34) | 0x100;
                      }
                    }
                  }
                }
              }
              ExFreePoolWithTag(lVar5,0);
            }
          }
        }
      }
    }
    ExFreePoolWithTag(lVar4,0);
  }
  return iVar1;
}



===== VmpCheckDynamicDiskConversion @ 140010480 =====

/* long __cdecl VmpCheckDynamicDiskConversion(class VM_ROOT_EXTENSION * __ptr64,struct _IRP *
   __ptr64) */

long __cdecl VmpCheckDynamicDiskConversion(VM_ROOT_EXTENSION *param_1,_IRP *param_2)

{
  int *piVar1;
  VM_ROOT_EXTENSION *pVVar2;
  long lVar3;
  
  lVar3 = 0;
  piVar1 = *(int **)(param_2 + 0x18);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x58) {
    lVar3 = -0x3ffffff3;
  }
  else {
    VmpAcquireAll(param_1);
    for (pVVar2 = *(VM_ROOT_EXTENSION **)(param_1 + 0xd0); pVVar2 != param_1 + 0xd0;
        pVVar2 = *(VM_ROOT_EXTENSION **)pVVar2) {
      if (((pVVar2[0x1aa] == (VM_ROOT_EXTENSION)0x0) && (*(int *)(pVVar2 + 0x180) == *piVar1)) &&
         (pVVar2[0x90] != (VM_ROOT_EXTENSION)0x0)) {
        lVar3 = -0x3fffff45;
        break;
      }
    }
    VmpReleaseAll(param_1);
  }
  return lVar3;
}



===== VmpCheckForRevertGptAttributes @ 140010508 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl VmpCheckForRevertGptAttributes(class VM_ROOT_EXTENSION * __ptr64,unsigned
   char,unsigned char,struct _GUID * __ptr64,struct _GUID * __ptr64,unsigned long,void *
   __ptr64,struct _DEVICE_OBJECT * __ptr64) */

void __cdecl
VmpCheckForRevertGptAttributes
          (VM_ROOT_EXTENSION *param_1,uchar param_2,uchar param_3,_GUID *param_4,_GUID *param_5,
          ulong param_6,void *param_7,_DEVICE_OBJECT *param_8)

{
  uint uVar1;
  int iVar2;
  ulong *puVar3;
  ulong *puVar4;
  longlong lVar5;
  uint uVar6;
  _GUID *p_Var7;
  ulong *puVar8;
  bool bVar9;
  
  uVar1 = *(uint *)(param_1 + 0x160);
  puVar8 = (ulong *)0x0;
  uVar6 = 0;
  puVar3 = *(ulong **)(param_1 + 0x168);
  p_Var7 = (_GUID *)(ulonglong)param_3;
  if (uVar1 != 0) {
    puVar4 = puVar3;
    do {
      puVar8 = puVar4;
      p_Var7 = param_5;
      if (param_2 == '\0') {
        if (param_3 == '\0') {
          if ((puVar8[6] == 0) && (puVar8[7] == 0)) {
            bVar9 = param_6 == *puVar8;
            goto LAB_1400105a6;
          }
        }
        else if (puVar8[7] != 0) {
          lVar5 = *(longlong *)param_5 - *(longlong *)puVar8;
          if (lVar5 == 0) {
            lVar5 = *(longlong *)(param_5 + 8);
            goto LAB_140010575;
          }
          goto LAB_140010579;
        }
      }
      else if (puVar8[6] != 0) {
        lVar5 = *(longlong *)param_4 - *(longlong *)puVar8;
        if (lVar5 == 0) {
          lVar5 = *(longlong *)(param_4 + 8);
LAB_140010575:
          lVar5 = lVar5 - *(longlong *)(puVar8 + 2);
        }
LAB_140010579:
        bVar9 = lVar5 == 0;
LAB_1400105a6:
        if (bVar9) break;
      }
      uVar6 = uVar6 + 1;
      puVar4 = puVar8 + 8;
    } while (uVar6 < uVar1);
  }
  if (uVar6 != uVar1) {
    if (param_2 == '\0') {
      VmpDiskSetGptAttributes(param_8,*(__uint64 *)(puVar8 + 4),(uchar)p_Var7);
    }
    else {
      (**(code **)(*(longlong *)(param_1 + 0x188) + 0xb0))(param_7,*(__uint64 *)(puVar8 + 4),1);
    }
    iVar2 = *(int *)(param_1 + 0x160);
    *(int *)(param_1 + 0x160) = iVar2 + -1;
    if (uVar6 + 1 == uVar1) {
      if (iVar2 + -1 == 0) {
        ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x168),0);
        *(undefined8 *)(param_1 + 0x168) = 0;
      }
    }
    else {
      memcpy(puVar3 + (ulonglong)uVar6 * 8,puVar3 + (ulonglong)(uVar6 + 1) * 8,
             (ulonglong)((uVar1 - uVar6) - 1) << 5);
    }
  }
  return;
}



===== VmpCheckSecurity @ 140010664 =====

/* long __cdecl VmpCheckSecurity(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpCheckSecurity(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  _IRP _Var1;
  char cVar2;
  undefined8 uVar3;
  long lVar4;
  long local_res18 [2];
  undefined4 local_res20 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_res20[0] = 0;
  SeCaptureSubjectContext(&local_28);
  SeLockSubjectContext(&local_28);
  local_res18[0] = -0x3fffffde;
  _Var1 = param_2[0x40];
  uVar3 = IoGetFileObjectGenericMapping();
  cVar2 = SeAccessCheck(*(undefined8 *)(*(longlong *)param_1 + 0x110),&local_28,1,1,0,0,uVar3,_Var1,
                        local_res20,local_res18);
  SeUnlockSubjectContext(&local_28);
  SeReleaseSubjectContext(&local_28);
  lVar4 = 0;
  if (cVar2 == '\0') {
    lVar4 = local_res18[0];
  }
  return lVar4;
}



===== VmpCleanupVolumeExtension @ 140010760 =====

/* void __cdecl VmpCleanupVolumeExtension(class VM_VOLUME_EXTENSION * __ptr64) */

void __cdecl VmpCleanupVolumeExtension(VM_VOLUME_EXTENSION *param_1)

{
  if (*(longlong *)(param_1 + 0x198) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x198),0);
  }
  if (param_1[0x1ca] != (VM_VOLUME_EXTENSION)0x0) {
    VmpPageExtensionDriver(*(longlong *)(param_1 + 8));
  }
  return;
}



===== VmpCompleteConversion @ 1400107a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl VmpCompleteConversion(class VM_VOLUME_EXTENSION * __ptr64,struct _DEVICE_OBJECT *
   __ptr64) */

long __cdecl VmpCompleteConversion(VM_VOLUME_EXTENSION *param_1,_DEVICE_OBJECT *param_2)

{
  _DEVICE_OBJECT *p_Var1;
  longlong lVar2;
  int iVar3;
  long lVar4;
  _DEVICE_OBJECT *p_Var5;
  ulonglong uVar6;
  VM_VOLUME_EXTENSION *pVVar7;
  VM_VOLUME_EXTENSION *pVVar8;
  undefined8 uVar9;
  undefined1 auStackY_148 [32];
  VM_VOLUME_EXTENSION local_108 [8];
  _DEVICE_OBJECT *local_100;
  _DEVICE_OBJECT *local_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  ushort *local_e0;
  undefined4 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  VM_VOLUME_EXTENSION local_b0;
  VM_VOLUME_EXTENSION local_af;
  undefined8 local_a8;
  undefined8 local_98;
  undefined4 local_90;
  undefined8 local_88;
  longlong lStack_80;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  ushort local_60;
  uchar local_5e [54];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_148;
  pVVar7 = local_108;
  uVar9 = 0x68;
  memset(pVVar7,0,0x68);
  p_Var1 = *(_DEVICE_OBJECT **)(param_1 + 0x180);
  *(undefined8 *)(param_1 + 0x180) = 0;
  local_68 = 0;
  uStack_64 = 0;
  local_88 = 0;
  lStack_80 = 0;
  local_78 = 0;
  uStack_74 = 0;
  uStack_70 = 0;
  uStack_6c = 0;
  if (p_Var1 == (_DEVICE_OBJECT *)0x0) {
    return -0x3ffffddb;
  }
  if (p_Var1 == param_2) {
    if ((Microsoft_Windows_StorageVolumeEnableBits & 1) == 0) {
      return 0;
    }
    McTemplateK0qzqx_EtwWriteTransfer
              (pVVar7,&VolumeConversionCancel,uVar9,*(undefined4 *)(param_1 + 0xc4),
               *(wchar_t **)(param_1 + 0x198),(char)*(undefined4 *)(param_1 + 0x1a0),
               (char)*(undefined8 *)(param_1 + 0x1a8));
    return 0;
  }
  lVar2 = *(longlong *)(p_Var1 + 0x40);
  p_Var5 = (_DEVICE_OBJECT *)IoGetDeviceAttachmentBaseRef(*(undefined8 *)(lVar2 + 0x10));
  ObfDereferenceObject(p_Var5);
  local_98 = 0;
  local_90 = 0;
  uVar6 = VmpSendDeviceControl(p_Var1,0x2d1084,0,0,&local_88,0x28);
  iVar3 = (int)uVar6;
  if (iVar3 < 0) {
    uVar6 = VmpSendDeviceControl(p_Var1,0x2d1080,0,0,&local_98,0xc);
    iVar3 = (int)uVar6;
    if (-1 < iVar3) {
      lStack_80 = local_98 << 0x20;
      local_78 = local_98._4_4_;
      uStack_64 = local_90;
      uStack_74 = 0;
      uStack_70 = 0;
      uStack_6c = 0;
      local_68 = 0;
      local_88 = 0x2800000028;
      goto LAB_14001091c;
    }
  }
  if (iVar3 < 0) {
    return iVar3;
  }
LAB_14001091c:
  VmpDeleteLegacyNameLinks(param_1,'\x01');
  local_108[0] = param_1[0x1ca];
  local_f0 = *(undefined8 *)(lVar2 + 0x10);
  local_e8 = local_78;
  local_d8 = uStack_64;
  local_d0 = *(undefined8 *)(lVar2 + 0xb0);
  local_c8 = *(undefined8 *)(lVar2 + 0xb8);
  local_c0 = *(undefined8 *)(lVar2 + 0x40);
  uStack_b8 = *(undefined8 *)(lVar2 + 0x48);
  local_b0 = param_1[0x1c8];
  local_af = param_1[0x1c9];
  local_a8 = *(undefined8 *)(param_1 + 0x1d0);
  local_100 = p_Var1;
  local_f8 = p_Var5;
  uVar6 = Feature_Servicing_VolmgrHighIrqlPagedMemoryAccess__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar6 != 0) {
    VmpGetInstancePath(local_f8,&local_e0);
  }
  pVVar7 = local_108;
  VmpZeroRefCallback(param_1,VmpSetTargetCallback,pVVar7);
  pVVar8 = param_1;
  VmpCreateLegacyNameLinks(param_1,'\x01');
  if ((Microsoft_Windows_StorageVolumeEnableBits & 1) != 0) {
    McTemplateK0qzqx_EtwWriteTransfer
              (pVVar8,&VolumeConversionComplete,pVVar7,*(undefined4 *)(param_1 + 0xc4),
               *(wchar_t **)(param_1 + 0x198),(char)*(undefined4 *)(param_1 + 0x1a0),
               (char)*(undefined8 *)(param_1 + 0x1a8));
  }
  local_60 = 0x30;
  lVar4 = VmpQueryUniqueIdInternal(param_1,&local_60,local_5e);
  if (lVar4 < 0) {
    lVar4 = 0;
  }
  else {
    VmpNotify(param_1,(_GUID *)&GUID_IO_VOLUME_UNIQUE_ID_CHANGE,local_60 + 2,&local_60);
  }
  return lVar4;
}



===== VmpCreateDeviceObject @ 140010a78 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl VmpCreateDeviceObject(unsigned long,unsigned __int64,unsigned char,struct
   _DEVICE_OBJECT * __ptr64 * __ptr64) */

long __cdecl
VmpCreateDeviceObject(ulong param_1,__uint64 param_2,uchar param_3,_DEVICE_OBJECT **param_4)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  VM_ROOT_EXTENSION *pVVar4;
  int iVar5;
  undefined1 auStack_c8 [32];
  uint local_a8;
  undefined1 local_a0;
  _DEVICE_OBJECT **local_98;
  _DEVICE_OBJECT *local_88;
  short local_80 [4];
  undefined1 *local_78;
  undefined1 local_70 [64];
  ulonglong local_30;
  
  pVVar4 = VmRootExtension;
  local_30 = __security_cookie ^ (ulonglong)auStack_c8;
  local_80[0] = 0;
  local_80[1] = 0x3c;
  local_80[2] = 0;
  local_80[3] = 0;
  local_78 = local_70;
  *param_4 = (_DEVICE_OBJECT *)0x0;
  local_88 = (_DEVICE_OBJECT *)0x0;
  VmpBuildName(local_80,0,*(int *)(pVVar4 + 0x118),0);
  local_98 = &local_88;
  local_a8 = param_1 | 0x20000;
  local_a0 = 0;
  iVar5 = IoCreateDevice(*(undefined8 *)(VmRootExtension + 0x20),0x1d8,local_80,7);
  if (-1 < iVar5) {
    *(uint *)(local_88 + 0x30) = *(uint *)(local_88 + 0x30) | 0x10;
    puVar3 = *(undefined8 **)(local_88 + 0x40);
    KeInitializeSpinLock(puVar3 + 3);
    KeInitializeEvent(puVar3 + 0x11,0,0);
    KeInitializeMutex(puVar3 + 10,0);
    puVar1 = puVar3 + 0x14;
    puVar3[0x15] = puVar1;
    *puVar1 = puVar1;
    pVVar4 = VmRootExtension;
    puVar3[6] = _DAT_fffff78000000014;
    *puVar3 = local_88;
    puVar3[1] = pVVar4;
    *(undefined4 *)(puVar3 + 2) = 1;
    *(undefined4 *)(puVar3 + 7) = 1;
    *(undefined4 *)(puVar3 + 0x2a) = 0;
    *(undefined1 *)((longlong)puVar3 + 0xbe) = 0;
    *(uchar *)(puVar3 + 0x17) = param_3;
    *(undefined1 *)(puVar3 + 0x18) = 1;
    iVar2 = *(int *)(pVVar4 + 0x118);
    *(int *)(pVVar4 + 0x118) = iVar2 + 1;
    puVar3[0x22] = &DiskperfGuidList;
    puVar3[0x23] = VmQueryWmiRegInfo;
    puVar3[0x24] = VmQueryWmiDataBlock;
    puVar3[0x28] = VmWmiFunctionControl;
    *(int *)((longlong)puVar3 + 0xc4) = iVar2;
    *(undefined1 *)((longlong)puVar3 + 0xba) = 0;
    puVar3[0x2b] = param_2;
    *(undefined4 *)(puVar3 + 0x21) = 1;
    *param_4 = local_88;
  }
  return iVar5;
}



===== VmpCreateDynamicDevice @ 140010c70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpCreateDynamicDevice(void * __ptr64,struct _GUID * __ptr64,unsigned __int64,struct
   _DEVICE_OBJECT * __ptr64 * __ptr64) */

long __cdecl
VmpCreateDynamicDevice(void *param_1,_GUID *param_2,__uint64 param_3,_DEVICE_OBJECT **param_4)

{
  longlong *plVar1;
  longlong lVar2;
  VM_ROOT_EXTENSION *pVVar3;
  _DEVICE_OBJECT *p_Var4;
  char cVar5;
  long lVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  _tlgProvider_t *p_Var9;
  _DEVICE_OBJECT *p_Var10;
  _GUID *p_Var11;
  _GUID *p_Var12;
  _GUID local_res18 [8];
  _tlgWrapperByVal<1> local_res20 [8];
  _GUID local_48;
  _tlgWrapperByVal<1> local_47;
  _tlgWrapperByVal<1> local_46;
  _GUID local_45;
  _tlgWrapperByVal<1> local_44;
  _GUID local_43 [3];
  _DEVICE_OBJECT *local_40;
  
  *param_4 = (_DEVICE_OBJECT *)0x0;
  local_48 = (_GUID)0x0;
  local_res18[0] = (_GUID)0x0;
  local_40 = (_DEVICE_OBJECT *)0x0;
  local_res20[0] = (_tlgWrapperByVal<1>)0x0;
  lVar6 = VmpCreateDeviceObject(0,param_3,(byte)(param_3 >> 0x3e) & 1,&local_40);
  p_Var10 = local_40;
  pVVar3 = VmRootExtension;
  if (lVar6 < 0) {
    if (local_40 != (_DEVICE_OBJECT *)0x0) {
      IoDeleteDevice();
    }
  }
  else {
    p_Var12 = local_res18;
    p_Var11 = &local_48;
    plVar1 = *(longlong **)(local_40 + 0x40);
    *(undefined1 *)((longlong)plVar1 + 0x1ca) = 1;
    plVar1[0x3a] = (longlong)param_1;
    lVar2 = *(longlong *)(pVVar3 + 0x188);
    (**(code **)(lVar2 + 0x90))(param_1,local_res20);
    if (local_res20[0] != (_tlgWrapperByVal<1>)0x0) {
      *(uint *)(local_40 + 0x30) = *(uint *)(p_Var10 + 0x30) | 0x200000;
      p_Var10 = local_40;
    }
    if (local_48 != (_GUID)0x0) {
      *(uint *)(local_40 + 0x30) = *(uint *)(p_Var10 + 0x30) | 0x100;
      p_Var10 = local_40;
    }
    if (local_res18[0] != (_GUID)0x0) {
      *(uint *)(local_40 + 0x30) = *(uint *)(p_Var10 + 0x30) | 0x400000;
    }
    if (((*(uint *)(*plVar1 + 0x30) & 0x600100) != 0) || (*(int *)((longlong)plVar1 + 0xb4) != 0)) {
      *(undefined1 *)(plVar1 + 0x18) = 0;
    }
    uVar7 = (**(code **)(lVar2 + 0x88))(plVar1[0x3a]);
    p_Var10 = local_40;
    *(undefined4 *)(local_40 + 0x98) = uVar7;
    cVar5 = (**(code **)(lVar2 + 0x80))(plVar1[0x3a]);
    *(char *)(p_Var10 + 0x4c) = cVar5 + '\x02';
    p_Var9 = (_tlgProvider_t *)plVar1[0x3a];
    (**(code **)(lVar2 + 0x78))(p_Var9,plVar1 + 0x37);
    p_Var4 = local_40;
    *(uint *)(local_40 + 0x30) = *(uint *)(p_Var10 + 0x30) & 0xffffff7f;
    if (5 < DAT_14000b048) {
      uVar8 = _tlgKeywordOn();
      if ((char)uVar8 != '\0') {
        local_47 = (_tlgWrapperByVal<1>)((byte)((ulonglong)plVar1[0x2b] >> 0x3c) & 1);
        local_46 = *(_tlgWrapperByVal<1> *)(plVar1 + 0x17);
        local_45 = local_res18[0];
        local_44 = local_res20[0];
        local_43[0] = local_48;
        local_40 = (_DEVICE_OBJECT *)param_2;
        _tlgWriteTemplate<long___cdecl(_tlgProvider_t_const*___ptr64,void_const*___ptr64,_GUID_const*___ptr64,_GUID_const*___ptr64,unsigned_int,_EVENT_DATA_DESCRIPTOR*___ptr64),&long___cdecl__tlgWriteTransfer_EtwWriteTransfer(struct__tlgProvider_t_const*___ptr64,void_const*___ptr64,struct__GUID_const*___ptr64,struct__GUID_const*___ptr64,unsigned_int,struct__EVENT_DATA_DESCRIPTOR*___ptr64),_GUID_const*___ptr64,_GUID_const*___ptr64>
        ::
        Write<_tlgWrapperByRef<16>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>,_tlgWrapperByVal<1>_>
                  (p_Var9,&DAT_1400091c4,p_Var11,p_Var12,(_tlgWrapperByRef<16> *)&local_40,
                   (_tlgWrapperByVal<1> *)local_43,&local_44,(_tlgWrapperByVal<1> *)&local_45,
                   &local_46,&local_47);
      }
    }
    pVVar3 = VmRootExtension;
    *param_4 = p_Var4;
    VmpRestoreExtensionDriver((longlong)pVVar3);
  }
  return lVar6;
}



===== VmpCreateLegacyNameLinks @ 140010e84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl VmpCreateLegacyNameLinks(class VM_VOLUME_EXTENSION * __ptr64,unsigned char) */

void __cdecl VmpCreateLegacyNameLinks(VM_VOLUME_EXTENSION *param_1,uchar param_2)

{
  undefined1 auStack_198 [32];
  short local_178 [4];
  undefined1 *local_170;
  short local_168 [4];
  undefined1 *local_160;
  undefined1 local_158 [128];
  undefined1 local_d8 [192];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_198;
  local_170 = local_158;
  local_160 = local_d8;
  local_178[0] = 0;
  local_178[1] = 0x80;
  local_178[2] = 0;
  local_178[3] = 0;
  local_168[0] = 0;
  local_168[1] = 0xc0;
  local_168[2] = 0;
  local_168[3] = 0;
  VmpBuildName(local_178,0,*(int *)(param_1 + 0xc4),0);
  if (param_2 == '\0') {
    VmpBuildName(local_168,3,*(int *)(param_1 + 0xc4),0);
    IoCreateSymbolicLink(local_168,local_178);
    if ((*(uint *)(*(longlong *)param_1 + 0x30) >> 0x15 & 1) != 0) {
      IoCreateSymbolicLink(&DAT_140008130,local_178);
      IoCreateSymbolicLink(&DAT_1400081a0,local_178);
    }
    if ((*(uint *)(*(longlong *)param_1 + 0x30) >> 8 & 1) != 0) {
      IoCreateSymbolicLink(&DAT_140008048,local_178);
      IoCreateSymbolicLink(&DAT_140008058,local_178);
    }
  }
  if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
    VmpBuildName(local_168,1,*(int *)(param_1 + 0x1a0),*(int *)(param_1 + 0x1a4));
    IoCreateSymbolicLink(local_168,local_178);
    VmpBuildName(local_168,4,*(int *)(param_1 + 0x1a0),*(int *)(param_1 + 0x1a4));
    IoCreateSymbolicLink(local_168,local_178);
    if (param_1[0xbb] != (VM_VOLUME_EXTENSION)0x0) {
      VmpBuildName(local_168,2,*(int *)(param_1 + 0x1a0),*(int *)(param_1 + 0x1a4));
      IoCreateSymbolicLink(local_168,local_178);
      VmpBuildName(local_168,5,*(int *)(param_1 + 0x1a0),*(int *)(param_1 + 0x1a4));
      IoCreateSymbolicLink(local_168,local_178);
    }
  }
  else {
    (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x188) + 0xb8))
              (*(undefined8 *)(param_1 + 0x1d0),local_158);
  }
  return;
}



===== VmpDeleteGptAttributesRevertRecord @ 1400110d8 =====

/* void __cdecl VmpDeleteGptAttributesRevertRecord(unsigned char,unsigned char,struct _GUID *
   __ptr64,struct _GUID * __ptr64,unsigned long) */

void __cdecl
VmpDeleteGptAttributesRevertRecord
          (uchar param_1,uchar param_2,_GUID *param_3,_GUID *param_4,ulong param_5)

{
  ulong uVar1;
  VM_GPT_ATTRIBUTES_REVERT_ENTRY *pVVar2;
  long lVar3;
  int iVar4;
  VM_GPT_ATTRIBUTES_REVERT_ENTRY *pVVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  bool bVar9;
  ulong local_38 [2];
  undefined8 local_30;
  VM_GPT_ATTRIBUTES_REVERT_ENTRY *local_28 [2];
  
  local_30 = 0;
  local_28[0] = (VM_GPT_ATTRIBUTES_REVERT_ENTRY *)0x0;
  local_38[0] = 0;
  lVar3 = VmpQueryRegistryRevertEntries(local_28,local_38);
  pVVar2 = local_28[0];
  uVar1 = local_38[0];
  if (-1 < lVar3) {
    uVar8 = 0;
    if (local_38[0] != 0) {
      do {
        pVVar5 = local_28[0] + uVar8 * 0x20;
        if (param_1 == '\0') {
          if (param_2 == '\0') {
            if ((*(ulong *)(pVVar5 + 0x18) == 0) && (*(ulong *)(pVVar5 + 0x1c) == 0)) {
              bVar9 = param_5 == *(ulong *)pVVar5;
              goto LAB_14001118a;
            }
          }
          else if (*(ulong *)(pVVar5 + 0x1c) != 0) {
            lVar6 = *(longlong *)param_4 - *(longlong *)pVVar5;
            if (lVar6 == 0) {
              lVar6 = *(longlong *)(param_4 + 8);
              goto LAB_140011159;
            }
            goto LAB_14001115d;
          }
        }
        else if (*(ulong *)(pVVar5 + 0x18) != 0) {
          lVar6 = *(longlong *)param_3 - *(longlong *)pVVar5;
          if (lVar6 == 0) {
            lVar6 = *(longlong *)(param_3 + 8);
LAB_140011159:
            lVar6 = lVar6 - *(longlong *)(pVVar5 + 8);
          }
LAB_14001115d:
          bVar9 = lVar6 == 0;
LAB_14001118a:
          if (bVar9) break;
        }
        uVar7 = (int)uVar8 + 1;
        uVar8 = (ulonglong)uVar7;
      } while (uVar7 < local_38[0]);
    }
    uVar7 = (uint)uVar8;
    if (uVar7 == local_38[0]) {
      if (local_28[0] == (VM_GPT_ATTRIBUTES_REVERT_ENTRY *)0x0) {
        return;
      }
    }
    else {
      if (uVar7 + 1 < local_38[0]) {
        memcpy(local_28[0] + uVar8 * 0x20,local_28[0] + (ulonglong)(uVar7 + 1) * 0x20,
               (ulonglong)((local_38[0] - uVar7) - 1) << 5);
      }
      iVar4 = IoOpenDriverRegistryKey(*(undefined8 *)(VmRootExtension + 0x20),1,2,0,&local_30);
      if (iVar4 < 0) {
        return;
      }
      if (uVar1 == 1) {
        iVar4 = RtlDeleteRegistryValue(0x40000000,local_30,L"GptAttributeRevertEntries");
      }
      else {
        iVar4 = RtlWriteRegistryValue();
      }
      if (-1 < iVar4) {
        ZwFlushKey(local_30);
      }
      ZwClose(local_30);
    }
    ExFreePoolWithTag(pVVar2,0);
  }
  return;
}



===== VmpDeleteLegacyNameLinks @ 1400112a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl VmpDeleteLegacyNameLinks(class VM_VOLUME_EXTENSION * __ptr64,unsigned char) */

void __cdecl VmpDeleteLegacyNameLinks(VM_VOLUME_EXTENSION *param_1,uchar param_2)

{
  VM_VOLUME_EXTENSION *pVVar1;
  undefined1 auStack_f8 [32];
  short local_d8 [4];
  undefined1 *local_d0;
  undefined1 local_c8 [160];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_f8;
  local_d8[0] = 0;
  local_d8[1] = 0xa0;
  local_d8[2] = 0;
  local_d8[3] = 0;
  local_d0 = local_c8;
  if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
    pVVar1 = param_1 + 0x1a4;
    if (param_1[0xbb] != (VM_VOLUME_EXTENSION)0x0) {
      VmpBuildName(local_d8,5,*(int *)(param_1 + 0x1a0),*(int *)pVVar1);
      IoDeleteSymbolicLink(local_d8);
      VmpBuildName(local_d8,2,*(int *)(param_1 + 0x1a0),*(int *)pVVar1);
      IoDeleteSymbolicLink(local_d8);
    }
    VmpBuildName(local_d8,4,*(int *)(param_1 + 0x1a0),*(int *)pVVar1);
    IoDeleteSymbolicLink(local_d8);
    VmpBuildName(local_d8,1,*(int *)(param_1 + 0x1a0),*(int *)pVVar1);
    IoDeleteSymbolicLink(local_d8);
  }
  else {
    if (*(longlong *)(param_1 + 0x1d0) == 0) {
      return;
    }
    (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x188) + 0xc0))();
  }
  if (param_2 == '\0') {
    if ((*(uint *)(*(longlong *)param_1 + 0x30) >> 8 & 1) != 0) {
      IoDeleteSymbolicLink(&DAT_140008058);
      IoDeleteSymbolicLink(&DAT_140008048);
    }
    if ((*(uint *)(*(longlong *)param_1 + 0x30) >> 0x15 & 1) != 0) {
      IoDeleteSymbolicLink(&DAT_1400081a0);
      IoDeleteSymbolicLink(&DAT_140008130);
    }
    VmpBuildName(local_d8,3,*(int *)(param_1 + 0xc4),0);
    IoDeleteSymbolicLink(local_d8);
  }
  return;
}



===== VmpDiskSetGptAttributes @ 140011488 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl VmpDiskSetGptAttributes(struct _DEVICE_OBJECT * __ptr64,unsigned __int64,unsigned
   char) */

long __cdecl VmpDiskSetGptAttributes(_DEVICE_OBJECT *param_1,__uint64 param_2,uchar param_3)

{
  ulonglong uVar1;
  undefined1 auStackY_58 [32];
  undefined4 local_28;
  undefined1 local_24;
  undefined2 local_23;
  undefined1 local_21;
  __uint64 local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_58;
  local_23 = 0;
  local_21 = 0;
  local_28 = 0x18;
  local_24 = 1;
  local_18 = 0xffffffffffffffff;
  local_20 = param_2;
  uVar1 = VmpSendDeviceControl(param_1,0x7c0ec,&local_28,0x18,0,0);
  return (long)uVar1;
}



===== VmpExtensionDriverStarted @ 1400114f0 =====

/* long __cdecl VmpExtensionDriverStarted(class VM_ROOT_EXTENSION * __ptr64,struct _IRP * __ptr64)
    */

long __cdecl VmpExtensionDriverStarted(VM_ROOT_EXTENSION *param_1,_IRP *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 *puVar4;
  
  if ((*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0xf8) ||
     (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0xa0)) {
    lVar3 = -0x3ffffff3;
  }
  else {
    VmpAcquireAll(param_1);
    puVar1 = *(undefined8 **)(param_2 + 0x18);
    puVar4 = (undefined8 *)ExAllocatePool2(0x42,0xf8,0x20204d56);
    *(undefined8 **)(param_1 + 0x188) = puVar4;
    if (puVar4 == (undefined8 *)0x0) {
      VmpReleaseAll(param_1);
      lVar3 = -0x3fffff66;
    }
    else {
      uVar2 = puVar1[1];
      *puVar4 = *puVar1;
      puVar4[1] = uVar2;
      uVar2 = puVar1[3];
      puVar4[2] = puVar1[2];
      puVar4[3] = uVar2;
      uVar2 = puVar1[5];
      puVar4[4] = puVar1[4];
      puVar4[5] = uVar2;
      uVar2 = puVar1[7];
      puVar4[6] = puVar1[6];
      puVar4[7] = uVar2;
      uVar2 = puVar1[9];
      puVar4[8] = puVar1[8];
      puVar4[9] = uVar2;
      uVar2 = puVar1[0xb];
      puVar4[10] = puVar1[10];
      puVar4[0xb] = uVar2;
      uVar2 = puVar1[0xd];
      puVar4[0xc] = puVar1[0xc];
      puVar4[0xd] = uVar2;
      uVar2 = puVar1[0xf];
      puVar4[0xe] = puVar1[0xe];
      puVar4[0xf] = uVar2;
      uVar2 = puVar1[0x11];
      puVar4[0x10] = puVar1[0x10];
      puVar4[0x11] = uVar2;
      uVar2 = puVar1[0x13];
      puVar4[0x12] = puVar1[0x12];
      puVar4[0x13] = uVar2;
      uVar2 = puVar1[0x15];
      puVar4[0x14] = puVar1[0x14];
      puVar4[0x15] = uVar2;
      uVar2 = puVar1[0x17];
      puVar4[0x16] = puVar1[0x16];
      puVar4[0x17] = uVar2;
      uVar2 = puVar1[0x19];
      puVar4[0x18] = puVar1[0x18];
      puVar4[0x19] = uVar2;
      uVar2 = puVar1[0x1b];
      puVar4[0x1a] = puVar1[0x1a];
      puVar4[0x1b] = uVar2;
      uVar2 = puVar1[0x1d];
      puVar4[0x1c] = puVar1[0x1c];
      puVar4[0x1d] = uVar2;
      puVar4[0x1e] = puVar1[0x1e];
      puVar1[1] = VmLogError;
      *puVar1 = param_1;
      puVar1[2] = VmAcquireDevices;
      puVar1[3] = VmReleaseDevices;
      puVar1[4] = VmAcquireAll;
      puVar1[5] = VmReleaseAll;
      puVar1[6] = VmLoadExtensionDriver;
      puVar1[7] = VmUnloadExtensionDriver;
      puVar1[8] = VmVolumeRequestCompletionRoutine;
      puVar1[9] = VmQueryBasicExtension;
      puVar1[10] = VmQueryDynamicExtension;
      puVar1[0xb] = VmFindNextDynamicExtension;
      puVar1[0xc] = VmCreatePendingDynamicDevice;
      puVar1[0xd] = VmDeletePendingDynamicDevice;
      puVar1[0xe] = VmCommitDevices;
      puVar1[0xf] = VmQueryDeviceName;
      puVar1[0x10] = VmQueryUniqueIdBuffer;
      puVar1[0x11] = VmFreezeBasicDeviceCreation;
      puVar1[0x12] = VmSetDevicePowerState;
      puVar1[0x13] = VmQueryBootInformation;
      *(undefined8 *)(param_2 + 0x38) = 0xa0;
      VmpReleaseAll(param_1);
      lVar3 = 0;
    }
  }
  return lVar3;
}



===== VmpFindExtensionForPartition @ 140011704 =====

/* class VM_VOLUME_EXTENSION * __ptr64 __cdecl VmpFindExtensionForPartition(class VM_ROOT_EXTENSION
   * __ptr64,unsigned long,unsigned __int64,unsigned __int64) */

VM_VOLUME_EXTENSION * __cdecl
VmpFindExtensionForPartition
          (VM_ROOT_EXTENSION *param_1,ulong param_2,__uint64 param_3,__uint64 param_4)

{
  ulonglong uVar1;
  VM_ROOT_EXTENSION *pVVar2;
  undefined1 local_a8 [8];
  __uint64 local_a0;
  __uint64 local_98;
  
  memset(local_a8,0,0x90);
  pVVar2 = *(VM_ROOT_EXTENSION **)(param_1 + 0xd0);
  while( true ) {
    if (pVVar2 == param_1 + 0xd0) {
      return (VM_VOLUME_EXTENSION *)0x0;
    }
    if ((((pVVar2[0x1aa] == (VM_ROOT_EXTENSION)0x0) && (*(longlong *)(pVVar2 + 0x158) != 0)) &&
        (*(ulong *)(pVVar2 + 0x180) == param_2)) &&
       (((uVar1 = VmpSendDeviceControl(*(longlong *)(pVVar2 + 0x158),0x70048,0,0,local_a8,0x90),
         -1 < (int)uVar1 && (local_a0 == param_3)) && (local_98 == param_4)))) break;
    pVVar2 = *(VM_ROOT_EXTENSION **)pVVar2;
  }
  return (VM_VOLUME_EXTENSION *)(pVVar2 + -0x20);
}



===== VmpFindExtensionForPendingBasicVolume @ 1400117d0 =====

/* class VM_VOLUME_EXTENSION * __ptr64 __cdecl VmpFindExtensionForPendingBasicVolume(class
   VM_ROOT_EXTENSION * __ptr64,struct _DEVICE_OBJECT * __ptr64) */

VM_VOLUME_EXTENSION * __cdecl
VmpFindExtensionForPendingBasicVolume(VM_ROOT_EXTENSION *param_1,_DEVICE_OBJECT *param_2)

{
  VM_ROOT_EXTENSION *pVVar1;
  
  pVVar1 = *(VM_ROOT_EXTENSION **)(param_1 + 0x100);
  while( true ) {
    if (pVVar1 == param_1 + 0x100) {
      return (VM_VOLUME_EXTENSION *)0x0;
    }
    if ((pVVar1[0x1aa] == (VM_ROOT_EXTENSION)0x0) &&
       (*(_DEVICE_OBJECT **)(pVVar1 + 0x158) == param_2)) break;
    pVVar1 = *(VM_ROOT_EXTENSION **)pVVar1;
  }
  return (VM_VOLUME_EXTENSION *)(pVVar1 + -0x20);
}



===== VmpFindExtensionForPendingDynamicVolume @ 140011808 =====

/* class VM_VOLUME_EXTENSION * __ptr64 __cdecl VmpFindExtensionForPendingDynamicVolume(class
   VM_ROOT_EXTENSION * __ptr64,void * __ptr64) */

VM_VOLUME_EXTENSION * __cdecl
VmpFindExtensionForPendingDynamicVolume(VM_ROOT_EXTENSION *param_1,void *param_2)

{
  VM_ROOT_EXTENSION *pVVar1;
  
  pVVar1 = *(VM_ROOT_EXTENSION **)(param_1 + 0xf0);
  while( true ) {
    if (pVVar1 == param_1 + 0xf0) {
      return (VM_VOLUME_EXTENSION *)0x0;
    }
    if ((pVVar1[0x1aa] != (VM_ROOT_EXTENSION)0x0) && (*(void **)(pVVar1 + 0x1b0) == param_2)) break;
    pVVar1 = *(VM_ROOT_EXTENSION **)pVVar1;
  }
  return (VM_VOLUME_EXTENSION *)(pVVar1 + -0x20);
}



===== VmpFreeBCStream @ 140011840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpFreeBCStream(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpFreeBCStream(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  longlong lVar1;
  long lVar2;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
    *(undefined1 *)(lVar1 + 1) = 4;
    *(undefined4 *)(lVar1 + 0x18) = 0x2dd808;
    IoForwardIrpSynchronously(*(undefined8 *)(param_1 + 400));
    lVar2 = *(long *)(param_2 + 0x30);
  }
  else {
    lVar2 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x188) + 0x68))
                      (*(undefined8 *)(param_1 + 0x1d0));
  }
  return lVar2;
}



===== VmpGetBCProperties @ 1400118a4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl VmpGetBCProperties(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpGetBCProperties(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  lVar1 = *(longlong *)(param_2 + 0xb8);
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
    if ((((*(uint *)(lVar1 + 0x10) < 0x20) || (*(uint *)(lVar1 + 8) < 0x20)) ||
        (piVar2 = *(int **)(param_2 + 0x18), *piVar2 != 1)) ||
       ((*(ulonglong *)(piVar2 + 4) < *(ulonglong *)(piVar2 + 2) ||
        (*(ulonglong *)(param_1 + 0x1b0) <= *(ulonglong *)(piVar2 + 4))))) {
      iVar3 = -0x3ffffff3;
    }
    else {
      *(undefined4 *)(lVar1 + 0x10) = 0;
      *(undefined4 *)(lVar1 + 8) = 0x20;
      *(undefined4 *)(lVar1 + 0x18) = 0x2d5800;
      *(undefined8 **)(param_2 + 0x18) = &local_38;
      IoForwardIrpSynchronously(*(undefined8 *)(param_1 + 400),param_2);
      iVar3 = *(int *)(param_2 + 0x30);
      *(int **)(param_2 + 0x18) = piVar2;
      if (-1 < iVar3) {
        piVar2[0] = 0;
        piVar2[1] = 0;
        piVar2[2] = 0;
        piVar2[3] = 0;
        piVar2[4] = 0;
        piVar2[5] = 0;
        piVar2[6] = 0;
        piVar2[7] = 0;
        *piVar2 = (int)local_38;
        piVar2[1] = local_38._4_4_;
        *(undefined8 *)(piVar2 + 2) = uStack_30;
        piVar2[4] = (int)local_28;
        *(undefined8 *)(piVar2 + 6) = uStack_20;
        piVar2[5] = local_28._4_4_;
        *(undefined8 *)(param_2 + 0x38) = 0x20;
      }
    }
  }
  else {
    iVar3 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x188) + 0x68))
                      (*(undefined8 *)(param_1 + 0x1d0));
  }
  return iVar3;
}



===== VmpGetDeviceObjectPointer @ 1400119d8 =====

/* long __cdecl VmpGetDeviceObjectPointer(struct _UNICODE_STRING * __ptr64,struct _FILE_OBJECT *
   __ptr64 * __ptr64) */

long __cdecl VmpGetDeviceObjectPointer(_UNICODE_STRING *param_1,_FILE_OBJECT **param_2)

{
  int iVar1;
  longlong local_res8;
  _FILE_OBJECT *local_res10;
  undefined8 in_stack_ffffffffffffffa8;
  uint uVar2;
  undefined8 in_stack_ffffffffffffffb0;
  undefined4 uVar3;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  _UNICODE_STRING *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar2 = (uint)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20);
  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffb0 >> 0x20);
  local_res8 = 0;
  local_34 = 0;
  local_1c = 0;
  *param_2 = (_FILE_OBJECT *)0x0;
  local_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0x30;
  local_18 = 0;
  uStack_10 = 0;
  local_20 = 0x240;
  local_28 = param_1;
  KeEnterCriticalRegion();
  iVar1 = ZwOpenFile(&local_res8,0x80,&local_38,&local_48,(ulonglong)uVar2 << 0x20,
                     CONCAT44(uVar3,0x40040));
  if (-1 < iVar1) {
    local_res10 = (_FILE_OBJECT *)0x0;
    iVar1 = ObReferenceObjectByHandle
                      (local_res8,0,*(undefined8 *)IoFileObjectType_exref,0,&local_res10,0);
    if (iVar1 < 0) {
      if (local_res10 != (_FILE_OBJECT *)0x0) {
        ObfDereferenceObject();
      }
    }
    else {
      *param_2 = local_res10;
    }
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  KeLeaveCriticalRegion();
  return iVar1;
}



===== VmpGetInstancePath @ 140011aec =====

/* long __cdecl VmpGetInstancePath(struct _DEVICE_OBJECT * __ptr64,unsigned short * __ptr64 *
   __ptr64) */

long __cdecl VmpGetInstancePath(_DEVICE_OBJECT *param_1,ushort **param_2)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  int local_res10 [2];
  undefined4 local_res18 [4];
  
  *param_2 = (ushort *)0x0;
  local_res10[0] = 0;
  local_res18[0] = 0;
  iVar1 = IoGetDevicePropertyData
                    (param_1,&DEVPKEY_Device_InstanceId,0,0,0,0,local_res10,local_res18);
  iVar2 = 0;
  if (iVar1 != -0x3fffffdd) {
    iVar2 = iVar1;
  }
  if (local_res10[0] == 0) {
    iVar2 = -0x3ffffffc;
  }
  else if (-1 < iVar2) {
    puVar3 = (ushort *)ExAllocatePool2(0x42,local_res10[0],0x20204d56);
    if (puVar3 == (ushort *)0x0) {
      iVar2 = -0x3fffff66;
    }
    else {
      iVar2 = IoGetDevicePropertyData
                        (param_1,&DEVPKEY_Device_InstanceId,0,0,local_res10[0],puVar3,local_res10,
                         local_res18);
      if (iVar2 < 0) {
        ExFreePoolWithTag(puVar3,0);
      }
      else {
        *param_2 = puVar3;
      }
    }
  }
  return iVar2;
}



===== VmpGetPartitionInfo @ 140011c00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpGetPartitionInfo(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpGetPartitionInfo(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  longlong lVar1;
  VM_ROOT_EXTENSION *pVVar2;
  bool bVar3;
  int iVar4;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined8 local_10;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  pVVar2 = *(VM_ROOT_EXTENSION **)(param_1 + 8);
  iVar4 = VmpAllSystemsGo(param_1,param_2,'\x01','\x01','\0');
  if (-1 < iVar4) {
    if (iVar4 == 0x103) {
      return 0x103;
    }
    if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
      IoForwardIrpSynchronously(*(undefined8 *)(param_1 + 0x178),param_2);
      iVar4 = *(int *)(param_2 + 0x30);
      VmpDecrementRefCount(param_1);
      if (((-1 < iVar4) && ((*(byte *)(lVar1 + 2) & 2) != 0)) &&
         ((*(uint *)(*(longlong *)param_1 + 0x34) & 1) != 0)) {
        local_98 = 0;
        local_10 = 0;
        local_90 = **(undefined8 **)(param_2 + 0x18);
        local_88 = (*(undefined8 **)(param_2 + 0x18))[1];
        local_80 = 0;
        uStack_78 = 0;
        local_70 = 0;
        uStack_68 = 0;
        local_60 = 0;
        uStack_58 = 0;
        local_50 = 0;
        uStack_48 = 0;
        local_40 = 0;
        uStack_38 = 0;
        local_30 = 0;
        uStack_28 = 0;
        local_20 = 0;
        uStack_18 = 0;
        VmpAcquireDevices(pVVar2);
        bVar3 = VmpIsVolumeDead((longlong)param_1);
        if (!bVar3) {
          VmpSetPartitionInformation(param_1,(_PARTITION_INFORMATION_EX *)&local_98);
        }
        VmpReleaseDevices(pVVar2);
      }
    }
    else {
      iVar4 = (**(code **)(*(longlong *)(pVVar2 + 0x188) + 0x68))(*(undefined8 *)(param_1 + 0x1d0));
      VmpDecrementRefCount(param_1);
    }
  }
  *(int *)(param_2 + 0x30) = iVar4;
  IofCompleteRequest(param_2,0);
  return iVar4;
}



===== VmpIsConversionInProgress @ 140011d78 =====

/* unsigned char __cdecl VmpIsConversionInProgress(struct _DEVICE_OBJECT * __ptr64) */

uchar __cdecl VmpIsConversionInProgress(_DEVICE_OBJECT *param_1)

{
  longlong lVar1;
  longlong lVar2;
  VM_ROOT_EXTENSION *pVVar3;
  VM_ROOT_EXTENSION *pVVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(lVar1 + 0x58);
  if (lVar2 == 0) {
    lVar2 = *(longlong *)(lVar1 + 0x60);
  }
  if (lVar2 != 0) {
    pVVar3 = VmRootExtension + 0xd0;
    for (pVVar4 = *(VM_ROOT_EXTENSION **)pVVar3; pVVar4 != pVVar3;
        pVVar4 = *(VM_ROOT_EXTENSION **)pVVar4) {
      if (pVVar4[0x1aa] == (VM_ROOT_EXTENSION)0x0) {
        lVar2 = *(longlong *)(pVVar4 + 0x198) - *(longlong *)(lVar1 + 0x58);
        if (lVar2 == 0) {
          lVar2 = *(longlong *)(pVVar4 + 0x1a0) - *(longlong *)(lVar1 + 0x60);
        }
        if (lVar2 == 0) {
          *(_DEVICE_OBJECT **)(pVVar4 + 0x160) = param_1;
          if ((Microsoft_Windows_StorageVolumeEnableBits & 1) == 0) {
            return '\x01';
          }
          McTemplateK0qzqx_EtwWriteTransfer
                    (*(undefined8 *)(pVVar4 + 0x178),&VolumeConversionStart,pVVar3,
                     *(undefined4 *)(pVVar4 + 0xa4),(wchar_t *)*(undefined8 *)(pVVar4 + 0x178),
                     (char)*(undefined4 *)(pVVar4 + 0x180),(char)*(undefined8 *)(pVVar4 + 0x188));
          return '\x01';
        }
      }
    }
  }
  return '\0';
}



===== VmpIsRedirectionSupported @ 140011e40 =====

/* long __cdecl VmpIsRedirectionSupported(class VM_ROOT_EXTENSION * __ptr64,struct _IRP * __ptr64)
    */

long __cdecl VmpIsRedirectionSupported(VM_ROOT_EXTENSION *param_1,_IRP *param_2)

{
  return -(uint)(*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x18) & 0xc000000d;
}



===== VmpLinkDeleted @ 140011e5c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpLinkDeleted(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpLinkDeleted(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  uint uVar1;
  
  if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
    uVar1 = -(uint)(*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 4) & 0xc000000d;
  }
  else {
    uVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x188) + 0x68))
                      (*(undefined8 *)(param_1 + 0x1d0));
  }
  return uVar1;
}



===== VmpLogicalToPhysical @ 140011ea4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpLogicalToPhysical(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpLogicalToPhysical(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  long lVar3;
  ulonglong uVar4;
  undefined1 local_98 [8];
  longlong local_90;
  longlong local_88;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  memset(local_98,0,0x90);
  if (param_1[0x1ca] != (VM_VOLUME_EXTENSION)0x0) {
    lVar3 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x188) + 0x68))
                      (*(undefined8 *)(param_1 + 0x1d0),param_2);
    return lVar3;
  }
  if ((7 < *(uint *)(lVar1 + 0x10)) && (0x17 < *(uint *)(lVar1 + 8))) {
    lVar1 = **(longlong **)(param_2 + 0x18);
    uVar4 = VmpSendDeviceControl(*(undefined8 *)(param_1 + 0x178),0x70048,0,0,local_98,0x90);
    if ((int)uVar4 < 0) {
      return (int)uVar4;
    }
    if ((-1 < lVar1) && (lVar1 < local_88)) {
      puVar2 = *(undefined4 **)(param_2 + 0x18);
      *puVar2 = 1;
      puVar2[2] = *(undefined4 *)(param_1 + 0x1a0);
      *(longlong *)(puVar2 + 4) = local_90 + lVar1;
      *(undefined8 *)(param_2 + 0x38) = 0x18;
      return 0;
    }
  }
  return -0x3ffffff3;
}



===== VmpMarkDeleted @ 140011f98 =====

/* long __cdecl VmpMarkDeleted(struct _DEVICE_OBJECT * __ptr64,unsigned char) */

long __cdecl VmpMarkDeleted(_DEVICE_OBJECT *param_1,uchar param_2)

{
  int iVar1;
  longlong local_res20;
  
  local_res20 = 0;
  iVar1 = IoOpenDeviceRegistryKey(param_1,1,0x2001f,&local_res20);
  if (-1 < iVar1) {
    if (param_2 == '\0') {
      iVar1 = RtlDeleteRegistryValue(0x40000000,local_res20,L"IsDeleted");
    }
    else {
      iVar1 = RtlWriteRegistryValue();
    }
  }
  if (local_res20 != 0) {
    ZwClose();
  }
  return iVar1;
}



===== VmpNotify @ 140012044 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl VmpNotify(class VM_VOLUME_EXTENSION * __ptr64,struct _GUID const * __ptr64,unsigned
   short,void * __ptr64) */

void __cdecl VmpNotify(VM_VOLUME_EXTENSION *param_1,_GUID *param_2,ushort param_3,void *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  short sVar6;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_88;
  local_48 = 0;
  puVar5 = &local_68;
  sVar6 = 0x24;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (param_1[0xbc] != (VM_VOLUME_EXTENSION)0x0) {
    if (param_3 != 0) {
      sVar6 = param_3 + 0x24;
      puVar5 = (undefined8 *)ExAllocatePool2(0x42,sVar6,0x20204d56);
      if (puVar5 == (undefined8 *)0x0) {
        return;
      }
    }
    *(undefined2 *)puVar5 = 1;
    *(short *)((longlong)puVar5 + 2) = sVar6;
    uVar1 = *(undefined4 *)param_2;
    uVar2 = *(undefined4 *)(param_2 + 4);
    uVar3 = *(undefined4 *)(param_2 + 8);
    uVar4 = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)(puVar5 + 4) = 0xffffffff;
    puVar5[3] = 0;
    *(undefined4 *)((longlong)puVar5 + 4) = uVar1;
    *(undefined4 *)(puVar5 + 1) = uVar2;
    *(undefined4 *)((longlong)puVar5 + 0xc) = uVar3;
    *(undefined4 *)(puVar5 + 2) = uVar4;
    if (param_3 != 0) {
      memcpy((undefined2 *)((longlong)puVar5 + 0x24),param_4,(ulonglong)param_3);
    }
    IoReportTargetDeviceChangeAsynchronous(*(undefined8 *)param_1,puVar5,0,0);
    if (puVar5 != &local_68) {
      ExFreePoolWithTag(puVar5,0);
    }
  }
  return;
}



===== VmpOffline @ 14001214c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpOffline(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpOffline(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  long lVar1;
  
  lVar1 = 0;
  if (param_1[0xc0] == (VM_VOLUME_EXTENSION)0x0) {
    if (((*(uint *)(*(longlong *)param_1 + 0x30) & 0x600100) == 0) &&
       (*(int *)(param_1 + 0xb4) == 0)) {
      lVar1 = VmpZeroRefCallback(param_1,VmpChangeOfflineCallback,(void *)0x1);
      if (-1 < lVar1) {
        KeWaitForSingleObject(param_1 + 0x50,0,0,0,0);
        if ((param_1[0x1ca] != (VM_VOLUME_EXTENSION)0x0) && (*(longlong *)(param_1 + 0x1d0) != 0)) {
          (**(code **)(*(longlong *)(VmRootExtension + 0x188) + 0xe0))();
        }
        KeReleaseMutex(param_1 + 0x50,0);
      }
    }
    else {
      lVar1 = -0x3ffffff0;
    }
  }
  *(long *)(param_2 + 0x30) = lVar1;
  IofCompleteRequest(param_2,0);
  return lVar1;
}



===== VmpPartitionArrived @ 140012238 =====

/* long __cdecl VmpPartitionArrived(class VM_ROOT_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpPartitionArrived(VM_ROOT_EXTENSION *param_1,_IRP *param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  longlong *plVar5;
  VM_ROOT_EXTENSION *pVVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  uchar local_res10 [8];
  uchar local_res18 [16];
  undefined1 auStackY_48 [8];
  undefined1 auStackY_40 [24];
  
  plVar1 = *(longlong **)(param_2 + 0x18);
  local_res10[0] = '\0';
  local_res18[0] = '\0';
  if ((*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x18) ||
     (*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 0)) {
    lVar4 = -0x3ffffff3;
  }
  else {
    VmpAcquireDevices(param_1);
    pVVar6 = param_1;
    lVar4 = VmpPartitionArrivedImmediate
                      (param_1,(_DEVICE_OBJECT *)plVar1[1],(_DEVICE_OBJECT *)*plVar1,
                       (_PARTITION_INFORMATION_EX *)plVar1[2],local_res10,local_res18);
    puVar9 = auStackY_48;
    if ((-1 < lVar4) && (puVar9 = auStackY_48, local_res10[0] != '\0')) {
      plVar5 = VM_ALLOCATED_OBJECT::operator_new((__uint64)pVVar6);
      puVar9 = auStackY_48;
      if (plVar5 == (longlong *)0x0) {
        lVar4 = 0;
      }
      else {
        *plVar5 = 0;
        plVar5[1] = 0;
        plVar5[2] = 0;
        plVar5[3] = 0;
        plVar5[4] = 0;
        *(undefined4 *)(plVar5 + 2) = 1;
        plVar5[3] = plVar1[1];
        plVar5[4] = *plVar1;
        pVVar6 = param_1 + 0xb8;
        plVar8 = *(longlong **)(param_1 + 0xc0);
        puVar9 = auStackY_48;
        if ((VM_ROOT_EXTENSION *)*plVar8 != pVVar6) {
          plVar8 = (longlong *)0x3;
          pcVar3 = (code *)swi(0x29);
          pVVar6 = (VM_ROOT_EXTENSION *)(*pcVar3)();
          puVar9 = auStackY_40;
        }
        *plVar5 = (longlong)pVVar6;
        plVar5[1] = (longlong)plVar8;
        *plVar8 = (longlong)plVar5;
        *(longlong **)(pVVar6 + 8) = plVar5;
        lVar7 = plVar1[1];
        *(undefined8 *)(puVar9 + -8) = 0x14001231b;
        ObfReferenceObject(lVar7);
        lVar7 = *plVar1;
        *(undefined8 *)(puVar9 + -8) = 0x14001232a;
        ObfReferenceObject(lVar7);
        if (param_1[200] == (VM_ROOT_EXTENSION)0x0) {
          uVar2 = *(undefined8 *)param_1;
          *(undefined8 *)(puVar9 + -8) = 0x140012342;
          lVar7 = IoAllocateWorkItem(uVar2);
          if (lVar7 != 0) {
            param_1[200] = (VM_ROOT_EXTENSION)0x1;
            *(undefined8 *)(puVar9 + -8) = 0x14001236d;
            IoQueueWorkItem(lVar7,VmpProcessDiskNotificationsWorkRoutine,1,lVar7);
          }
        }
      }
    }
    *(undefined8 *)(puVar9 + -8) = 0x14001237e;
    VmpReleaseDevices(param_1);
    if (-1 < lVar4) {
      *(undefined1 *)plVar1 = puVar9[0x60];
      *(undefined8 *)(param_2 + 0x38) = 1;
    }
  }
  return lVar4;
}



===== VmpPartitionArrivedDelayed @ 1400123b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpPartitionArrivedDelayed(class VM_ROOT_EXTENSION * __ptr64,struct _DEVICE_OBJECT *
   __ptr64,struct _DEVICE_OBJECT * __ptr64) */

long __cdecl
VmpPartitionArrivedDelayed
          (VM_ROOT_EXTENSION *param_1,_DEVICE_OBJECT *param_2,_DEVICE_OBJECT *param_3)

{
  int iVar1;
  int iVar2;
  
  if (*(longlong *)(param_1 + 0x188) == 0) {
    iVar2 = 0;
  }
  else {
    VmpRestoreExtensionDriver((longlong)param_1);
    iVar1 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x18))(param_2,param_3);
    VmpPageExtensionDriver((longlong)param_1);
    iVar2 = 0;
    if (iVar1 < 0) {
      iVar2 = iVar1;
    }
  }
  return iVar2;
}



===== VmpPartitionArrivedImmediate @ 140012424 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpPartitionArrivedImmediate(class VM_ROOT_EXTENSION * __ptr64,struct _DEVICE_OBJECT
   * __ptr64,struct _DEVICE_OBJECT * __ptr64,struct _PARTITION_INFORMATION_EX * __ptr64,unsigned
   char * __ptr64,unsigned char * __ptr64) */

long __cdecl
VmpPartitionArrivedImmediate
          (VM_ROOT_EXTENSION *param_1,_DEVICE_OBJECT *param_2,_DEVICE_OBJECT *param_3,
          _PARTITION_INFORMATION_EX *param_4,uchar *param_5,uchar *param_6)

{
  longlong *plVar1;
  undefined8 uVar2;
  code *pcVar3;
  uchar uVar4;
  int iVar5;
  long lVar6;
  longlong lVar7;
  VM_ROOT_EXTENSION *pVVar8;
  longlong *plVar9;
  _DEVICE_OBJECT *p_Var10;
  undefined1 *puVar11;
  VM_ROOT_EXTENSION *pVVar12;
  bool bVar13;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [40];
  _DEVICE_OBJECT *local_28 [2];
  
  iVar5 = 0;
  local_28[0] = (_DEVICE_OBJECT *)0x0;
  *param_5 = '\0';
  *param_6 = '\x01';
  uVar4 = VmpIsConversionInProgress(param_3);
  if (uVar4 != '\0') {
    *param_6 = '\0';
    return 0;
  }
  if (*(longlong *)(param_1 + 0x188) != 0) {
    VmpRestoreExtensionDriver((longlong)param_1);
    iVar5 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x10))(param_2,param_3,param_4,param_5);
    VmpPageExtensionDriver((longlong)param_1);
    if (iVar5 < 0) {
      return iVar5;
    }
  }
  if (*(int *)param_4 == 0) {
    bVar13 = param_4[0x20] == (_PARTITION_INFORMATION_EX)0x42;
  }
  else {
    if (*(int *)param_4 != 1) {
      return -0x3fffffff;
    }
    lVar7 = *(longlong *)(param_4 + 0x20) + -0x4f621431af9b60a0;
    if (lVar7 == 0) {
      lVar7 = *(longlong *)(param_4 + 0x28) + 0x5296b58eeecc9744;
    }
    if (lVar7 == 0) goto LAB_140012514;
    lVar7 = *(longlong *)(param_4 + 0x20) + -0x42e07e8f5808c8aa;
    if (lVar7 == 0) {
      lVar7 = *(longlong *)(param_4 + 0x28) + 0x4c30cbfb161e2d7b;
    }
    bVar13 = lVar7 == 0;
  }
  if (bVar13) {
LAB_140012514:
    *param_6 = '\0';
    return iVar5;
  }
  p_Var10 = param_2;
  lVar6 = VmpCreateBasicDevice(param_3,param_2,param_4,local_28);
  puVar11 = auStack_58;
  if (lVar6 < 0) {
    return lVar6;
  }
  lVar7 = *(longlong *)(local_28[0] + 0x40);
  plVar9 = (longlong *)(lVar7 + 0x20);
  if (*(_DEVICE_OBJECT **)(param_1 + 0x110) == param_2) {
    pVVar12 = param_1 + 0x100;
    plVar1 = *(longlong **)(param_1 + 0x108);
    if ((VM_ROOT_EXTENSION *)*plVar1 == pVVar12) {
      *plVar9 = (longlong)pVVar12;
      *(longlong **)(lVar7 + 0x28) = plVar1;
      *plVar1 = (longlong)plVar9;
      *(longlong **)(param_1 + 0x108) = plVar9;
      return lVar6;
    }
  }
  else {
    pVVar8 = param_1 + 0xd0;
    p_Var10 = *(_DEVICE_OBJECT **)(param_1 + 0xd8);
    pVVar12 = param_1;
    if (*(VM_ROOT_EXTENSION **)p_Var10 == pVVar8) goto LAB_140012583;
  }
  plVar9 = (longlong *)0x3;
  pcVar3 = (code *)swi(0x29);
  pVVar8 = (VM_ROOT_EXTENSION *)(*pcVar3)();
  puVar11 = auStack_50;
  param_1 = pVVar12;
LAB_140012583:
  plVar9[1] = (longlong)p_Var10;
  *plVar9 = (longlong)pVVar8;
  *(longlong **)p_Var10 = plVar9;
  *(longlong **)(pVVar8 + 8) = plVar9;
  uVar2 = *(undefined8 *)(param_1 + 0x30);
  *(undefined8 *)(puVar11 + -8) = 0x1400125a1;
  IoInvalidateDeviceRelations(uVar2,5);
  return lVar6;
}



===== VmpPartitionRemoved @ 1400125d0 =====

/* long __cdecl VmpPartitionRemoved(class VM_ROOT_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpPartitionRemoved(VM_ROOT_EXTENSION *param_1,_IRP *param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  code *pcVar3;
  uchar uVar4;
  long lVar5;
  longlong *plVar6;
  VM_ROOT_EXTENSION *pVVar7;
  longlong lVar8;
  longlong *plVar9;
  undefined1 *puVar10;
  uchar local_res10 [8];
  undefined1 auStackY_38 [8];
  undefined1 auStackY_30 [24];
  
  plVar1 = *(longlong **)(param_2 + 0x18);
  local_res10[0] = '\0';
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x18) {
    lVar5 = -0x3ffffff3;
  }
  else {
    VmpAcquireDevices(param_1);
    pVVar7 = param_1;
    lVar5 = VmpPartitionRemovedImmediate
                      (param_1,(_DEVICE_OBJECT *)plVar1[1],(_DEVICE_OBJECT *)*plVar1,
                       (_PARTITION_INFORMATION_EX *)plVar1[2],local_res10);
    if ((lVar5 < 0) || (local_res10[0] == '\0')) {
      VmpReleaseDevices(param_1);
    }
    else {
      plVar6 = VM_ALLOCATED_OBJECT::operator_new((__uint64)pVVar7);
      puVar10 = auStackY_38;
      if (plVar6 == (longlong *)0x0) {
        VmpReleaseDevices(param_1);
      }
      else {
        *plVar6 = 0;
        plVar6[1] = 0;
        plVar6[2] = 0;
        plVar6[3] = 0;
        plVar6[4] = 0;
        *(undefined4 *)(plVar6 + 2) = 2;
        plVar6[3] = plVar1[1];
        plVar6[4] = *plVar1;
        pVVar7 = param_1 + 0xb8;
        plVar9 = *(longlong **)(param_1 + 0xc0);
        if ((VM_ROOT_EXTENSION *)*plVar9 != pVVar7) {
          plVar9 = (longlong *)0x3;
          pcVar3 = (code *)swi(0x29);
          pVVar7 = (VM_ROOT_EXTENSION *)(*pcVar3)();
          puVar10 = auStackY_30;
        }
        *plVar6 = (longlong)pVVar7;
        plVar6[1] = (longlong)plVar9;
        *plVar9 = (longlong)plVar6;
        *(longlong **)(pVVar7 + 8) = plVar6;
        if (plVar1[1] != 0) {
          *(undefined8 *)(puVar10 + -8) = 0x1400126a5;
          ObfReferenceObject();
        }
        lVar8 = *plVar1;
        *(undefined8 *)(puVar10 + -8) = 0x1400126b4;
        ObfReferenceObject(lVar8);
        if (param_1[200] == (VM_ROOT_EXTENSION)0x0) {
          uVar2 = *(undefined8 *)param_1;
          *(undefined8 *)(puVar10 + -8) = 0x1400126cc;
          lVar8 = IoAllocateWorkItem(uVar2);
          if (lVar8 != 0) {
            param_1[200] = (VM_ROOT_EXTENSION)0x1;
          }
        }
        else {
          lVar8 = 0;
        }
        *(undefined8 *)(puVar10 + -8) = 0x1400126ec;
        VmpReleaseDevices(param_1);
        *(undefined8 *)(puVar10 + -8) = 0x1400126f4;
        uVar4 = VmpTestAcquireConfig(param_1);
        if (uVar4 == '\0') {
          if (lVar8 != 0) {
            *(undefined8 *)(puVar10 + -8) = 0x140012754;
            IoQueueWorkItem(lVar8,VmpProcessDiskNotificationsWorkRoutine,1,lVar8);
          }
        }
        else {
          *(undefined8 *)(puVar10 + -8) = 0x140012700;
          VmpAcquireDevices(param_1);
          *(undefined8 *)(puVar10 + -8) = 0x140012708;
          VmpProcessDiskNotifications(param_1);
          if (lVar8 != 0) {
            *(undefined8 *)(puVar10 + -8) = 0x140012717;
            IoFreeWorkItem(lVar8);
            param_1[200] = (VM_ROOT_EXTENSION)0x0;
          }
          *(undefined8 *)(puVar10 + -8) = 0x14001272b;
          VmpReleaseDevices(param_1);
          *(undefined8 *)(puVar10 + -8) = 0x140012733;
          VmpReleaseConfig(param_1);
        }
      }
      lVar5 = 0;
    }
  }
  return lVar5;
}



===== VmpPartitionRemovedDelayed @ 140012788 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpPartitionRemovedDelayed(class VM_ROOT_EXTENSION * __ptr64,struct _DEVICE_OBJECT *
   __ptr64,struct _DEVICE_OBJECT * __ptr64) */

long __cdecl
VmpPartitionRemovedDelayed
          (VM_ROOT_EXTENSION *param_1,_DEVICE_OBJECT *param_2,_DEVICE_OBJECT *param_3)

{
  int iVar1;
  int iVar2;
  
  if (*(longlong *)(param_1 + 0x188) == 0) {
    iVar2 = 0;
  }
  else {
    VmpRestoreExtensionDriver((longlong)param_1);
    iVar1 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x28))(param_2,param_3);
    VmpPageExtensionDriver((longlong)param_1);
    iVar2 = 0;
    if (iVar1 < 0) {
      iVar2 = iVar1;
    }
  }
  return iVar2;
}



===== VmpPartitionRemovedImmediate @ 1400127fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl VmpPartitionRemovedImmediate(class VM_ROOT_EXTENSION * __ptr64,struct _DEVICE_OBJECT
   * __ptr64,struct _DEVICE_OBJECT * __ptr64,struct _PARTITION_INFORMATION_EX * __ptr64,unsigned
   char * __ptr64) */

long __cdecl
VmpPartitionRemovedImmediate
          (VM_ROOT_EXTENSION *param_1,_DEVICE_OBJECT *param_2,_DEVICE_OBJECT *param_3,
          _PARTITION_INFORMATION_EX *param_4,uchar *param_5)

{
  VM_VOLUME_EXTENSION VVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  VM_VOLUME_EXTENSION *pVVar7;
  undefined8 *puVar8;
  VM_VOLUME_EXTENSION *pVVar9;
  undefined1 *puVar10;
  undefined1 auStack_e8 [32];
  undefined8 local_c8;
  undefined4 local_c0;
  undefined8 local_b8;
  uint local_b0;
  undefined1 local_a8 [56];
  undefined8 local_70;
  undefined8 local_68;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_e8;
  *param_5 = '\0';
  if (*(longlong *)(param_1 + 0x188) != 0) {
    VmpRestoreExtensionDriver((longlong)param_1);
    iVar5 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x20))(param_2,param_3);
    VmpPageExtensionDriver((longlong)param_1);
    if (iVar5 < 0) {
      return iVar5;
    }
  }
  pVVar7 = VmpFindExtensionForPendingBasicVolume(param_1,param_3);
  if ((pVVar7 == (VM_VOLUME_EXTENSION *)0x0) &&
     (pVVar7 = VmpFindExtensionForBasicVolume(param_3), pVVar7 == (VM_VOLUME_EXTENSION *)0x0)) {
    return 0;
  }
  if (pVVar7[0xbe] == (VM_VOLUME_EXTENSION)0x0) {
    pVVar9 = pVVar7 + 0x20;
    lVar2 = *(longlong *)pVVar9;
    if ((*(VM_VOLUME_EXTENSION **)(lVar2 + 8) == pVVar9) &&
       (plVar3 = *(longlong **)(pVVar7 + 0x28), (VM_VOLUME_EXTENSION *)*plVar3 == pVVar9)) {
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      VmpCleanupVolumeExtension(pVVar7);
      IoDeleteDevice(*(undefined8 *)pVVar7);
      return 0;
    }
  }
  else {
    lVar6 = VmpCompleteConversion(pVVar7,param_3);
    if (-1 < lVar6) {
      return lVar6;
    }
    if ((param_2 != (_DEVICE_OBJECT *)0x0) && (param_4 == (_PARTITION_INFORMATION_EX *)0x0)) {
      pVVar7[0xbf] = (VM_VOLUME_EXTENSION)0x1;
    }
    *(undefined8 *)(pVVar7 + 0x30) = _DAT_fffff78000000014;
    if ((Microsoft_Windows_StorageVolumeEnableBits & 1) != 0) {
      local_b0 = (uint)(byte)pVVar7[0xbf];
      local_b8 = *(undefined8 *)(pVVar7 + 0x1a8);
      local_c0 = *(undefined4 *)(pVVar7 + 0x1a0);
      local_c8 = *(undefined8 *)(pVVar7 + 0x198);
      McTemplateK0qzqxt_EtwWriteTransfer();
    }
    VVar1 = pVVar7[0x1c8];
    if (pVVar7[0xbf] != (VM_VOLUME_EXTENSION)0x0) {
      VmpNotify(pVVar7,(_GUID *)&GUID_IO_VOLUME_PREPARE_DELETE,0,(void *)0x0);
    }
    VmpDeleteLegacyNameLinks(pVVar7,'\0');
    VmpReleaseInterfaces((longlong)pVVar7);
    memset(local_a8,0,0x68);
    local_70 = *(undefined8 *)(pVVar7 + 0x1a8);
    puVar10 = local_a8;
    local_68 = *(undefined8 *)(pVVar7 + 0x1b0);
    VmpZeroRefCallback(pVVar7,VmpSetTargetCallback,puVar10);
    if ((pVVar7[0xbf] != (VM_VOLUME_EXTENSION)0x0) && (VVar1 == (VM_VOLUME_EXTENSION)0x0)) {
      for (puVar8 = *(undefined8 **)(*(longlong *)(pVVar7 + 8) + 0xd0);
          puVar8 != (undefined8 *)(*(longlong *)(pVVar7 + 8) + 0xd0); puVar8 = (undefined8 *)*puVar8
          ) {
        if ((((VM_VOLUME_EXTENSION *)(puVar8 + -4) != pVVar7) &&
            (*(char *)((longlong)puVar8 + 0x1aa) == '\0')) &&
           ((_DEVICE_OBJECT *)puVar8[0x2d] == param_2)) goto LAB_140012a30;
      }
      VmpDiskSetGptAttributes(param_2,0,(uchar)puVar10);
    }
LAB_140012a30:
    pVVar9 = pVVar7 + 0x20;
    lVar2 = *(longlong *)pVVar9;
    if ((*(VM_VOLUME_EXTENSION **)(lVar2 + 8) == pVVar9) &&
       (plVar3 = *(longlong **)(pVVar7 + 0x28), (VM_VOLUME_EXTENSION *)*plVar3 == pVVar9)) {
      *plVar3 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar3;
      plVar3 = *(longlong **)(param_1 + 0xe8);
      if ((VM_ROOT_EXTENSION *)*plVar3 == param_1 + 0xe0) {
        *(longlong **)(pVVar7 + 0x28) = plVar3;
        *(VM_ROOT_EXTENSION **)pVVar9 = param_1 + 0xe0;
        *plVar3 = (longlong)pVVar9;
        *(VM_VOLUME_EXTENSION **)(param_1 + 0xe8) = pVVar9;
        IoInvalidateDeviceRelations(*(undefined8 *)(param_1 + 0x30),5);
        return 0;
      }
    }
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  lVar6 = (*pcVar4)();
  return lVar6;
}



===== VmpPerformanceOff @ 140012a94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* void __cdecl VmpPerformanceOff(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

void __cdecl VmpPerformanceOff(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  VM_VOLUME_EXTENSION VVar1;
  char cVar2;
  ulonglong uVar3;
  bool bVar4;
  
  uVar3 = Feature_RacyAccessesInVolmgrAreCountersEnabled__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    VVar1 = param_1[0xc1];
  }
  else {
    VVar1 = param_1[0xc1];
  }
  if (VVar1 != (VM_VOLUME_EXTENSION)0x0) {
    LOCK();
    bVar4 = *(int *)(param_1 + 0xf8) == 1;
    if (bVar4) {
      *(int *)(param_1 + 0xf8) = 0;
    }
    UNLOCK();
    if ((bVar4) &&
       (cVar2 = (**(code **)(*(longlong *)(param_1 + 8) + 0x138))(param_1 + 0x100,0,0),
       cVar2 == '\0')) {
      param_1[0xc1] = (VM_VOLUME_EXTENSION)0x0;
    }
  }
  return;
}



===== VmpPhysicalToLogical @ 140012b08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpPhysicalToLogical(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpPhysicalToLogical(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  longlong lVar1;
  long lVar2;
  ulonglong uVar3;
  undefined1 local_98 [8];
  longlong local_90;
  longlong local_88;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  memset(local_98,0,0x90);
  if (param_1[0x1ca] != (VM_VOLUME_EXTENSION)0x0) {
    lVar2 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x188) + 0x68))
                      (*(undefined8 *)(param_1 + 0x1d0),param_2);
    return lVar2;
  }
  if (((0xf < *(uint *)(lVar1 + 0x10)) && (7 < *(uint *)(lVar1 + 8))) &&
     (lVar1 = *(longlong *)(*(int **)(param_2 + 0x18) + 2),
     *(int *)(param_1 + 0x1a0) == **(int **)(param_2 + 0x18))) {
    uVar3 = VmpSendDeviceControl(*(undefined8 *)(param_1 + 0x178),0x70048,0,0,local_98,0x90);
    if ((int)uVar3 < 0) {
      return (int)uVar3;
    }
    if ((local_90 <= lVar1) && (lVar1 < local_88 + local_90)) {
      **(longlong **)(param_2 + 0x18) = lVar1 - local_90;
      *(undefined8 *)(param_2 + 0x38) = 8;
      return 0;
    }
  }
  return -0x3ffffff3;
}



===== VmpPmWmiCounterLibContext @ 140012bfc =====

/* long __cdecl VmpPmWmiCounterLibContext(class VM_ROOT_EXTENSION * __ptr64,struct _IRP * __ptr64)
    */

long __cdecl VmpPmWmiCounterLibContext(VM_ROOT_EXTENSION *param_1,_IRP *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x28) {
    lVar3 = -0x3ffffff3;
  }
  else {
    VmpAcquireAll(param_1);
    puVar1 = *(undefined8 **)(param_2 + 0x18);
    uVar2 = puVar1[1];
    *(undefined8 *)(param_1 + 0x130) = *puVar1;
    *(undefined8 *)(param_1 + 0x138) = uVar2;
    uVar2 = puVar1[3];
    *(undefined8 *)(param_1 + 0x140) = puVar1[2];
    *(undefined8 *)(param_1 + 0x148) = uVar2;
    *(undefined8 *)(param_1 + 0x150) = puVar1[4];
    VmpReleaseAll(param_1);
    lVar3 = 0;
  }
  return lVar3;
}



===== VmpQueryCapabilities @ 140012c68 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpQueryCapabilities(class VM_ROOT_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpQueryCapabilities(VM_ROOT_EXTENSION *param_1,_IRP *param_2)

{
  undefined2 *puVar1;
  long lVar2;
  
  lVar2 = 0;
  if (*(longlong *)(param_1 + 0x188) == 0) {
    if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 3) {
      return -0x3ffffff3;
    }
    puVar1 = *(undefined2 **)(param_2 + 0x18);
    *puVar1 = 0;
    *(undefined1 *)(puVar1 + 1) = 0;
    *(undefined8 *)(param_2 + 0x38) = 3;
  }
  else {
    VmpRestoreExtensionDriver((longlong)param_1);
    lVar2 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x60))(param_2);
    VmpPageExtensionDriver((longlong)param_1);
  }
  return lVar2;
}



===== VmpQueryDiskSignature @ 140012cec =====

/* long __cdecl VmpQueryDiskSignature(struct _DEVICE_OBJECT * __ptr64,unsigned long * __ptr64) */

long __cdecl VmpQueryDiskSignature(_DEVICE_OBJECT *param_1,ulong *param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  ulong local_res10 [2];
  
  local_res10[0] = 0;
  *param_2 = 0;
  uVar1 = IoGetAttachedDeviceReference();
  uVar2 = VmpSendDeviceControl(uVar1,0x704008,0,0,local_res10,4);
  ObfDereferenceObject(uVar1);
  if (-1 < (int)uVar2) {
    *param_2 = local_res10[0];
  }
  return (int)uVar2;
}



===== VmpQueryFailoverSet @ 140012d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpQueryFailoverSet(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpQueryFailoverSet(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  undefined4 *puVar1;
  long lVar2;
  
  if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
    if (*(longlong *)(param_1 + 0x178) != 0) {
      if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 8) {
        return -0x3ffffff3;
      }
      puVar1 = *(undefined4 **)(param_2 + 0x18);
      *puVar1 = 1;
      puVar1[1] = *(undefined4 *)(param_1 + 0x1a0);
      *(undefined8 *)(param_2 + 0x38) = 8;
      return 0;
    }
  }
  else if (*(longlong *)(param_1 + 0x1d0) != 0) {
    lVar2 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x188) + 0x68))();
    return lVar2;
  }
  return -0x3ffffff2;
}



===== VmpQueryMinimumShrinkSize @ 140012df0 =====

/* long __cdecl VmpQueryMinimumShrinkSize(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64)
    */

long __cdecl VmpQueryMinimumShrinkSize(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 8) {
    return -0x3ffffff3;
  }
  **(undefined8 **)(param_2 + 0x18) = 0;
  *(undefined8 *)(param_2 + 0x38) = 8;
  return 0;
}



===== VmpQueryRegistryRevertEntries @ 140012e20 =====

/* long __cdecl VmpQueryRegistryRevertEntries(class VM_GPT_ATTRIBUTES_REVERT_ENTRY * __ptr64 *
   __ptr64,unsigned long * __ptr64) */

long __cdecl VmpQueryRegistryRevertEntries(VM_GPT_ATTRIBUTES_REVERT_ENTRY **param_1,ulong *param_2)

{
  VM_ROOT_EXTENSION *pVVar1;
  int iVar2;
  ulong local_res8 [2];
  undefined8 local_res10;
  VM_GPT_ATTRIBUTES_REVERT_ENTRY *local_res18;
  code *local_88;
  undefined4 local_80 [2];
  wchar_t *local_78;
  ulong *local_70;
  
  local_res8[0] = 0;
  local_res10 = 0;
  memset(local_80,0,0x68);
  *param_1 = (VM_GPT_ATTRIBUTES_REVERT_ENTRY *)0x0;
  pVVar1 = VmRootExtension;
  *param_2 = 0;
  local_res18 = (VM_GPT_ATTRIBUTES_REVERT_ENTRY *)0x0;
  local_88 = VmpQueryRegistryRevertEntriesCallback;
  local_78 = L"GptAttributeRevertEntries";
  local_70 = local_res8;
  local_80[0] = 4;
  iVar2 = IoOpenDriverRegistryKey(*(undefined8 *)(pVVar1 + 0x20),1,1,0,&local_res10);
  if (-1 < iVar2) {
    iVar2 = RtlQueryRegistryValuesEx(0x40000000,local_res10,&local_88,&local_res18,0);
    ZwClose(local_res10);
    if (-1 < iVar2) {
      *param_1 = local_res18;
      *param_2 = local_res8[0];
    }
  }
  return iVar2;
}



===== VmpQuerySuggestedLinkName @ 140012f14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpQuerySuggestedLinkName(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64)
    */

long __cdecl VmpQuerySuggestedLinkName(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  undefined4 *puVar1;
  long lVar2;
  
  if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
    if (*(longlong *)(param_1 + 0x178) != 0) {
      if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 6) {
        return -0x3ffffff3;
      }
      if ((*(uint *)(*(longlong *)param_1 + 0x30) & 0x400100) != 0) {
        return -0x3ffffddb;
      }
      if (param_1[0x1c8] == (VM_VOLUME_EXTENSION)0x0) {
        if ((*(uint *)(*(longlong *)param_1 + 0x30) >> 0x15 & 1) == 0) {
          return -0x3ffffddb;
        }
        if (VmRootExtension[0x11d] != (VM_ROOT_EXTENSION)0x0) {
          return -0x3ffffddb;
        }
      }
      else if (param_1[0x1c9] == (VM_VOLUME_EXTENSION)0x0) {
        return -0x3ffffddb;
      }
      puVar1 = *(undefined4 **)(param_2 + 0x18);
      *puVar1 = 0;
      *(undefined2 *)(puVar1 + 1) = 0;
      *(undefined8 *)(param_2 + 0x38) = 6;
      return 0;
    }
  }
  else if (*(longlong *)(param_1 + 0x1d0) != 0) {
    lVar2 = (**(code **)(*(longlong *)(VmRootExtension + 0x188) + 0x68))();
    return lVar2;
  }
  return -0x3ffffff2;
}



===== VmpQueryVetoQueryRemove @ 140012fd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpQueryVetoQueryRemove(class VM_ROOT_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpQueryVetoQueryRemove(VM_ROOT_EXTENSION *param_1,_IRP *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  long lVar5;
  VM_ROOT_EXTENSION *pVVar6;
  char local_res10 [8];
  
  local_res10[0] = '\0';
  if ((*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x18) ||
     (*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 0)) {
    lVar5 = -0x3ffffff3;
  }
  else {
    plVar1 = *(longlong **)(param_2 + 0x18);
    lVar2 = *plVar1;
    lVar3 = plVar1[1];
    *(undefined1 *)plVar1 = 0;
    *(undefined8 *)(param_2 + 0x38) = 1;
    VmpAcquireDevices(param_1);
    for (pVVar6 = *(VM_ROOT_EXTENSION **)(param_1 + 0xd0); pVVar6 != param_1 + 0xd0;
        pVVar6 = *(VM_ROOT_EXTENSION **)pVVar6) {
      if (pVVar6[0x1aa] == (VM_ROOT_EXTENSION)0x0) {
        if ((*(longlong *)(pVVar6 + 0x158) == lVar2) && (pVVar6[0x9c] != (VM_ROOT_EXTENSION)0x0))
        break;
      }
      else if ((*(longlong *)(pVVar6 + 0x1b0) != 0) && (pVVar6[0x9c] != (VM_ROOT_EXTENSION)0x0)) {
        cVar4 = (**(code **)(*(longlong *)(param_1 + 0x188) + 200))
                          (*(longlong *)(pVVar6 + 0x1b0),lVar3,local_res10);
        if (cVar4 != '\0') {
          *(bool *)plVar1 = local_res10[0] == '\0';
          break;
        }
      }
    }
    VmpReleaseDevices(param_1);
    lVar5 = 0;
  }
  return lVar5;
}



===== VmpQueryVolumeNumber @ 1400130cc =====

/* long __cdecl VmpQueryVolumeNumber(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpQueryVolumeNumber(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  undefined4 *puVar1;
  
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x14) {
    return -0x3ffffff3;
  }
  puVar1 = *(undefined4 **)(param_2 + 0x18);
  *puVar1 = *(undefined4 *)(param_1 + 0xc4);
  builtin_wcsncpy((wchar_t *)(puVar1 + 1),L"VOLM",4);
  builtin_wcsncpy((wchar_t *)(puVar1 + 3),L"GR  ",4);
  *(undefined8 *)(param_2 + 0x38) = 0x14;
  return 0;
}



===== VmpRedirectRequest @ 140013110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpRedirectRequest(class VM_ROOT_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpRedirectRequest(VM_ROOT_EXTENSION *param_1,_IRP *param_2)

{
  longlong *plVar1;
  char *pcVar2;
  longlong lVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  bool bVar8;
  char cVar9;
  int iVar10;
  undefined8 uVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  uint uVar15;
  VM_ROOT_EXTENSION *pVVar16;
  longlong lVar17;
  undefined4 uVar18;
  VM_ROOT_EXTENSION *pVVar19;
  undefined1 local_res18 [8];
  longlong local_res20;
  
  pVVar16 = (VM_ROOT_EXTENSION *)0x0;
  local_res20 = 0;
  uVar18 = 0;
  local_res18[0] = 0;
  lVar17 = 0;
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x30) {
    return -0x3ffffff3;
  }
  plVar1 = *(longlong **)(param_2 + 0x18);
  lVar12 = *plVar1;
  lVar13 = plVar1[1];
  pcVar2 = *(char **)(plVar1[2] + 0xb8);
  bVar4 = (byte)(*pcVar2 - 3U) < 2;
  if (bVar4) {
    local_res20 = plVar1[4];
    lVar17 = plVar1[3];
    uVar18 = (undefined4)plVar1[5];
  }
  VmpAcquireDevices(param_1);
  bVar8 = false;
  pVVar19 = *(VM_ROOT_EXTENSION **)(param_1 + 0xd0);
  do {
    if (pVVar19 == param_1 + 0xd0) {
      if (bVar8) {
LAB_14001324b:
        if (bVar4) {
          if (pVVar19 != param_1 + 0xd0) {
            lVar12 = IoGetAttachedDeviceReference(*(longlong *)pVVar16);
            VmpReleaseDevices(param_1);
            lVar13 = IoMakeAssociatedIrp(plVar1[2],*(char *)(lVar12 + 0x4c) + '\x01');
            if (lVar13 == 0) {
              iVar10 = -0x3fffff66;
            }
            else {
              lVar14 = IoAllocateMdl(lVar17,uVar18,0,0,lVar13);
              if (lVar14 == 0) {
                iVar10 = -0x3fffff66;
              }
              else {
                IoBuildPartialMdl(*(undefined8 *)(plVar1[2] + 8),lVar14,lVar17,uVar18);
                lVar3 = *(longlong *)(lVar13 + 0xb8);
                uVar11 = *(undefined8 *)(pcVar2 + 8);
                *(undefined8 *)(lVar3 + -0x48) = *(undefined8 *)pcVar2;
                *(undefined8 *)(lVar3 + -0x40) = uVar11;
                uVar11 = *(undefined8 *)(pcVar2 + 0x18);
                *(undefined8 *)(lVar3 + -0x38) = *(undefined8 *)(pcVar2 + 0x10);
                *(undefined8 *)(lVar3 + -0x30) = uVar11;
                uVar5 = *(undefined4 *)(pcVar2 + 0x24);
                uVar6 = *(undefined4 *)(pcVar2 + 0x28);
                uVar7 = *(undefined4 *)(pcVar2 + 0x2c);
                *(undefined4 *)(lVar3 + -0x28) = *(undefined4 *)(pcVar2 + 0x20);
                *(undefined4 *)(lVar3 + -0x24) = uVar5;
                *(undefined4 *)(lVar3 + -0x20) = uVar6;
                *(undefined4 *)(lVar3 + -0x1c) = uVar7;
                *(undefined8 *)(lVar3 + -0x18) = *(undefined8 *)(pcVar2 + 0x30);
                *(undefined4 *)(lVar3 + -0x40) = uVar18;
                *(longlong *)(lVar3 + -0x30) = local_res20;
                *(char *)(lVar13 + 0x43) = *(char *)(lVar13 + 0x43) + -1;
                *(longlong *)(lVar13 + 0xb8) = *(longlong *)(lVar13 + 0xb8) + -0x48;
                iVar10 = IoPropagateIrpExtensionEx
                                   (param_2,lVar13,
                                    (lVar17 - (ulonglong)
                                              *(uint *)(*(longlong *)(plVar1[2] + 8) + 0x2c)) -
                                    *(longlong *)(*(longlong *)(plVar1[2] + 8) + 0x20),0xffffffff);
                if (-1 < iVar10) {
                  IoForwardIrpSynchronously(lVar12,lVar13);
                  iVar10 = *(int *)(lVar13 + 0x30);
                  if (-1 < iVar10) {
                    LOCK();
                    *(int *)(plVar1[2] + 0x38) =
                         *(int *)(plVar1[2] + 0x38) + *(int *)(lVar13 + 0x38);
                    UNLOCK();
                  }
                }
                IoFreeMdl(lVar14);
              }
              IoFreeIrp(lVar13);
            }
            ObfDereferenceObject(lVar12);
            return iVar10;
          }
          uVar15 = 0xc00000bb;
        }
        else {
          uVar15 = 0;
        }
      }
      else {
        uVar15 = 0xc000000d;
      }
LAB_140013270:
      VmpReleaseDevices(param_1);
      return uVar15;
    }
    pVVar16 = pVVar19 + -0x20;
    if (pVVar19[0x1aa] == (VM_ROOT_EXTENSION)0x0) {
      if (*(longlong *)(pVVar19 + 0x158) == lVar12) goto LAB_140013206;
    }
    else if ((*(longlong *)(pVVar19 + 0x1b0) != 0) &&
            (cVar9 = (**(code **)(*(longlong *)(param_1 + 0x188) + 200))
                               (*(longlong *)(pVVar19 + 0x1b0),lVar13,local_res18), cVar9 != '\0'))
    {
LAB_140013206:
      bVar8 = true;
      if (pVVar19[0x9c] == (VM_ROOT_EXTENSION)0x0) {
        uVar15 = -(uint)bVar4 & 0xc0000002;
        if ((int)uVar15 < 0) goto LAB_140013270;
        goto LAB_14001324b;
      }
      uVar11 = VmpIsSafeForDirectAccess((longlong *)pVVar16);
      if ((char)uVar11 == '\0') {
        uVar15 = 0xc0000022;
        goto LAB_140013270;
      }
      if (pVVar19[0x1aa] == (VM_ROOT_EXTENSION)0x0) goto LAB_14001324b;
    }
    pVVar19 = *(VM_ROOT_EXTENSION **)pVVar19;
  } while( true );
}



===== VmpReferenceDependantVolume @ 140013400 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpReferenceDependantVolume(class VM_ROOT_EXTENSION * __ptr64,struct _IRP * __ptr64)
    */

long __cdecl VmpReferenceDependantVolume(VM_ROOT_EXTENSION *param_1,_IRP *param_2)

{
  VM_ROOT_EXTENSION *pVVar1;
  longlong *plVar2;
  ulonglong uVar3;
  longlong lVar4;
  char cVar5;
  longlong lVar6;
  long lVar7;
  undefined4 uVar8;
  VM_ROOT_EXTENSION *pVVar9;
  ulonglong uVar10;
  VM_ROOT_EXTENSION *pVVar11;
  int iVar12;
  undefined1 local_res10 [8];
  longlong local_res18;
  longlong local_res20;
  
  lVar7 = 0;
  local_res10[0] = 0;
  pVVar11 = (VM_ROOT_EXTENSION *)0x0;
  if ((*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x18) ||
     (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 8)) {
    lVar7 = -0x3ffffff3;
  }
  else {
    plVar2 = *(longlong **)(param_2 + 0x18);
    local_res18 = *plVar2;
    local_res20 = plVar2[1];
    VmpAcquireDevices(param_1);
    pVVar1 = param_1 + 0xd0;
    iVar12 = 0;
    for (pVVar9 = *(VM_ROOT_EXTENSION **)pVVar1; pVVar9 != pVVar1;
        pVVar9 = *(VM_ROOT_EXTENSION **)pVVar9) {
      pVVar11 = pVVar9 + -0x20;
      if (pVVar9[0x1aa] == (VM_ROOT_EXTENSION)0x0) {
        if (*(longlong *)(pVVar9 + 0x158) == local_res18) {
          if (pVVar9[0x9c] != (VM_ROOT_EXTENSION)0x0) {
            iVar12 = iVar12 + 1;
          }
          break;
        }
      }
      else if (((*(longlong *)(pVVar9 + 0x1b0) != 0) && (pVVar9[0x9c] != (VM_ROOT_EXTENSION)0x0)) &&
              (cVar5 = (**(code **)(*(longlong *)(param_1 + 0x188) + 200))
                                 (*(longlong *)(pVVar9 + 0x1b0),local_res20,local_res10),
              cVar5 != '\0')) {
        iVar12 = iVar12 + 1;
      }
    }
    lVar6 = ExAllocatePool2(0x102,(longlong)(iVar12 * 8 + 8),0x20204d56);
    lVar4 = local_res18;
    *plVar2 = lVar6;
    if (lVar6 == 0) {
      lVar7 = -0x3fffff66;
    }
    else {
      *(undefined8 *)(param_2 + 0x38) = 8;
      if (pVVar9 == pVVar1) {
        uVar8 = 0;
        uVar3 = 0;
        for (pVVar11 = *(VM_ROOT_EXTENSION **)pVVar1; pVVar11 != pVVar1;
            pVVar11 = *(VM_ROOT_EXTENSION **)pVVar11) {
          uVar10 = uVar3;
          if (((pVVar11[0x1aa] != (VM_ROOT_EXTENSION)0x0) && (*(longlong *)(pVVar11 + 0x1b0) != 0))
             && ((pVVar11[0x9c] != (VM_ROOT_EXTENSION)0x0 &&
                 (cVar5 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0xd0))
                                    (*(longlong *)(pVVar11 + 0x1b0),local_res20,lVar4),
                 cVar5 != '\0')))) {
            uVar10 = (ulonglong)((int)uVar3 + 1);
            *(undefined8 *)(*plVar2 + 8 + uVar3 * 8) = *(undefined8 *)(pVVar11 + -0x20);
            ObfReferenceObject(*(undefined8 *)(pVVar11 + -0x20));
          }
          uVar8 = (undefined4)uVar10;
          uVar3 = uVar10;
        }
        *(undefined4 *)*plVar2 = uVar8;
        VmpReleaseDevices(param_1);
        return 0;
      }
      if (pVVar11[0xbc] == (VM_ROOT_EXTENSION)0x0) {
        *(undefined4 *)*plVar2 = 0;
      }
      else {
        *(undefined4 *)*plVar2 = 1;
        *(undefined8 *)(*plVar2 + 8) = *(undefined8 *)pVVar11;
        ObfReferenceObject(*(undefined8 *)pVVar11);
      }
    }
    VmpReleaseDevices(param_1);
  }
  return lVar7;
}



===== VmpRevertGptAttributes @ 1400135f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl VmpRevertGptAttributes(class VM_VOLUME_EXTENSION * __ptr64) */

void __cdecl VmpRevertGptAttributes(VM_VOLUME_EXTENSION *param_1)

{
  longlong lVar1;
  longlong lVar2;
  uchar uVar3;
  long lVar4;
  ulonglong uVar5;
  uchar uVar6;
  undefined8 *puVar7;
  _GUID *p_Var8;
  undefined8 *puVar9;
  undefined1 auStackY_108 [32];
  ulong uVar10;
  ulong local_d8 [2];
  undefined8 local_d0;
  undefined8 uStack_c8;
  int local_b8 [36];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  lVar1 = *(longlong *)(param_1 + 8);
  lVar2 = *(longlong *)(lVar1 + 0x188);
  local_d0 = 0;
  uStack_c8 = 0;
  memset(local_b8,0,0x90);
  local_d8[0] = 0;
  *(undefined8 *)(param_1 + 0x160) = 0;
  if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
    if (*(longlong *)(param_1 + 0x178) == 0) {
      return;
    }
    uVar6 = '\0';
    uVar5 = VmpSendDeviceControl(*(longlong *)(param_1 + 0x178),0x70048,0,0,local_b8,0x90);
    if ((int)uVar5 < 0) {
      return;
    }
    uVar3 = SC_PART_ENTRY::IsRecognized((SC_PART_ENTRY *)local_b8);
    if (uVar3 == '\0') {
      return;
    }
    if (local_b8[0] == 1) {
      VmpDiskSetGptAttributes
                (*(_DEVICE_OBJECT **)(param_1 + 0x178),*(__uint64 *)(param_1 + 0x168),uVar6);
      VmpDeleteGptAttributesRevertRecord('\0','\x01',(_GUID *)0x0,(_GUID *)(param_1 + 0x1b8),0);
      if (param_1[0x170] == (VM_VOLUME_EXTENSION)0x0) {
        return;
      }
      puVar9 = (undefined8 *)(lVar1 + 0xd0);
      for (puVar7 = (undefined8 *)*puVar9; puVar7 != puVar9; puVar7 = (undefined8 *)*puVar7) {
        if ((((VM_VOLUME_EXTENSION *)(puVar7 + -4) != param_1) &&
            (*(char *)((longlong)puVar7 + 0x1aa) == '\0')) &&
           (puVar7[0x2d] == *(longlong *)(param_1 + 0x188))) {
          uVar6 = '\0';
          uVar5 = VmpSendDeviceControl(puVar7[0x2b],0x70048,0,0,local_b8,0x90);
          if ((-1 < (int)uVar5) &&
             (uVar3 = SC_PART_ENTRY::IsRecognized((SC_PART_ENTRY *)local_b8), uVar3 != '\0')) {
            VmpDiskSetGptAttributes
                      ((_DEVICE_OBJECT *)puVar7[0x2b],*(__uint64 *)(param_1 + 0x168),uVar6);
            VmpDeleteGptAttributesRevertRecord('\0','\x01',(_GUID *)0x0,(_GUID *)(puVar7 + 0x33),0);
          }
        }
      }
      return;
    }
    if (local_b8[0] != 0) {
      return;
    }
    VmpDiskSetGptAttributes
              (*(_DEVICE_OBJECT **)(param_1 + 0x178),*(__uint64 *)(param_1 + 0x168),uVar6);
    lVar4 = VmpQueryDiskSignature(*(_DEVICE_OBJECT **)(param_1 + 0x188),local_d8);
    if (lVar4 < 0) {
      return;
    }
    p_Var8 = (_GUID *)0x0;
    uVar6 = '\0';
    uVar10 = local_d8[0];
  }
  else {
    if (*(longlong *)(param_1 + 0x1d0) == 0) {
      return;
    }
    (**(code **)(lVar2 + 0x78))(*(longlong *)(param_1 + 0x1d0),&local_d0);
    (**(code **)(lVar2 + 0xb0))(*(undefined8 *)(param_1 + 0x1d0),*(undefined8 *)(param_1 + 0x168),0)
    ;
    p_Var8 = (_GUID *)&local_d0;
    uVar6 = '\x01';
    uVar10 = 0;
  }
  VmpDeleteGptAttributesRevertRecord(uVar6,'\0',p_Var8,(_GUID *)0x0,uVar10);
  return;
}



===== VmpSetGptAttributes @ 14001383c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl VmpSetGptAttributes(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpSetGptAttributes(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong *puVar3;
  longlong lVar4;
  undefined8 uVar5;
  char cVar6;
  uchar uVar7;
  uchar uVar8;
  long lVar9;
  int iVar10;
  __uint64 _Var11;
  ulonglong uVar12;
  ulong uVar13;
  undefined8 *puVar14;
  _GUID *p_Var15;
  VM_VOLUME_EXTENSION *pVVar16;
  undefined1 auStackY_128 [32];
  ulong local_f8 [2];
  __uint64 local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  int local_d8 [36];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  lVar1 = *(longlong *)(param_1 + 8);
  lVar2 = *(longlong *)(param_2 + 0xb8);
  puVar3 = *(ulonglong **)(param_2 + 0x18);
  lVar4 = *(longlong *)(lVar1 + 0x188);
  local_e8 = 0;
  uStack_e0 = 0;
  local_f0 = 0;
  memset(local_d8,0,0x90);
  local_f8[0] = 0;
  if (((*(uint *)(lVar2 + 0x10) < 0x10) || (*(short *)((longlong)puVar3 + 10) != 0)) ||
     (*(int *)((longlong)puVar3 + 0xc) != 0)) {
    return -0x3ffffff3;
  }
  if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
    if (*(longlong *)(param_1 + 0x178) == 0) {
      return -0x3ffffff2;
    }
    uVar8 = '\0';
    uVar12 = VmpSendDeviceControl(*(longlong *)(param_1 + 0x178),0x70048,0,0,local_d8,0x90);
    if ((int)uVar12 < 0) {
      return (int)uVar12;
    }
    uVar7 = SC_PART_ENTRY::IsRecognized((SC_PART_ENTRY *)local_d8);
    if (uVar7 == '\0') {
      return -0x3ffffff3;
    }
    uVar13 = 0;
    if ((*puVar3 >> 0x3b & 1) != 0) {
      if (*(char *)((longlong)puVar3 + 9) != '\0') {
        return -0x3ffffff0;
      }
      if ((*(uint *)(*(longlong *)param_1 + 0x30) & 0x600100) != 0) {
        return -0x3ffffff0;
      }
      if (*(int *)(param_1 + 0xb4) != 0) {
        return -0x3ffffff0;
      }
      uVar13 = local_f8[0];
    }
    if (((*puVar3 & 0x600000000000000) != 0) && (*(char *)((longlong)puVar3 + 9) != '\0')) {
      return -0x3ffffff0;
    }
    lVar9 = VmpDiskGetGptAttributes(*(_DEVICE_OBJECT **)(param_1 + 0x178),&local_f0);
    _Var11 = local_f0;
    if (lVar9 < 0) {
      return lVar9;
    }
    if (local_d8[0] != 1) {
      if (local_d8[0] != 0) {
        return -0x3fffffff;
      }
      if (*(char *)((longlong)puVar3 + 9) == '\0') {
        return -0x3ffffff3;
      }
      if ((char)puVar3[1] != '\0') {
        *(undefined8 *)(param_1 + 0x160) = *(undefined8 *)(lVar2 + 0x30);
        *(__uint64 *)(param_1 + 0x168) = local_f0;
        param_1[0x170] = *(VM_VOLUME_EXTENSION *)((longlong)puVar3 + 9);
        lVar9 = VmpQueryDiskSignature(*(_DEVICE_OBJECT **)(param_1 + 0x188),local_f8);
        uVar13 = local_f8[0];
        if (-1 < lVar9) {
          uVar8 = '\0';
          lVar9 = VmpStoreGptAttributesRevertRecord
                            ('\0','\0',(_GUID *)0x0,(_GUID *)0x0,local_f8[0],_Var11);
          if (-1 < lVar9) goto LAB_140013ce0;
        }
LAB_14001398a:
        *(undefined8 *)(param_1 + 0x160) = 0;
        return lVar9;
      }
LAB_140013ce0:
      lVar9 = VmpDiskSetGptAttributes(*(_DEVICE_OBJECT **)(param_1 + 0x178),*puVar3,uVar8);
      if (lVar9 < 0) {
        if ((char)puVar3[1] != '\0') {
          *(undefined8 *)(param_1 + 0x160) = 0;
          VmpDeleteGptAttributesRevertRecord('\0','\0',(_GUID *)0x0,(_GUID *)0x0,uVar13);
        }
        return lVar9;
      }
      if ((char)puVar3[1] != '\0') {
        return 0;
      }
      VmpApplyGptAttributes(param_1,*puVar3);
      for (puVar14 = *(undefined8 **)(lVar1 + 0xd0); puVar14 != (undefined8 *)(lVar1 + 0xd0);
          puVar14 = (undefined8 *)*puVar14) {
        if ((((VM_VOLUME_EXTENSION *)(puVar14 + -4) != param_1) &&
            (*(char *)((longlong)puVar14 + 0x1aa) == '\0')) &&
           ((puVar14[0x2d] == *(longlong *)(param_1 + 0x188) &&
            ((uVar12 = VmpSendDeviceControl(puVar14[0x2b],0x70048,0,0,local_d8,0x90),
             -1 < (int)uVar12 &&
             (uVar8 = SC_PART_ENTRY::IsRecognized((SC_PART_ENTRY *)local_d8), uVar8 != '\0')))))) {
          VmpApplyGptAttributes((VM_VOLUME_EXTENSION *)(puVar14 + -4),*puVar3);
        }
      }
      return 0;
    }
    if ((char)puVar3[1] != '\0') {
      uVar5 = *(undefined8 *)(lVar2 + 0x30);
      uVar8 = '\0';
      *(__uint64 *)(param_1 + 0x168) = local_f0;
      *(undefined8 *)(param_1 + 0x160) = uVar5;
      param_1[0x170] = *(VM_VOLUME_EXTENSION *)((longlong)puVar3 + 9);
      lVar9 = VmpStoreGptAttributesRevertRecord
                        ('\0','\x01',(_GUID *)0x0,(_GUID *)(param_1 + 0x1b8),0,local_f0);
      if (lVar9 < 0) goto LAB_14001398a;
    }
    iVar10 = VmpDiskSetGptAttributes(*(_DEVICE_OBJECT **)(param_1 + 0x178),*puVar3,uVar8);
    if (-1 < iVar10) {
      if ((char)puVar3[1] == '\0') {
        VmpApplyGptAttributes(param_1,*puVar3);
      }
      if (*(char *)((longlong)puVar3 + 9) == '\0') {
        return 0;
      }
      puVar14 = *(undefined8 **)(lVar1 + 0xd0);
      do {
        if (puVar14 == (undefined8 *)(lVar1 + 0xd0)) {
          return 0;
        }
        if ((((VM_VOLUME_EXTENSION *)(puVar14 + -4) != param_1) &&
            (*(char *)((longlong)puVar14 + 0x1aa) == '\0')) &&
           (puVar14[0x2d] == *(longlong *)(param_1 + 0x188))) {
          uVar8 = '\0';
          uVar12 = VmpSendDeviceControl(puVar14[0x2b],0x70048,0,0,local_d8,0x90);
          iVar10 = (int)uVar12;
          if (iVar10 < 0) {
LAB_140013c55:
            cVar6 = (char)puVar3[1];
LAB_140013c59:
            if (cVar6 != '\0') {
              VmpRevertGptAttributes(param_1);
            }
            return iVar10;
          }
          uVar7 = SC_PART_ENTRY::IsRecognized((SC_PART_ENTRY *)local_d8);
          if (uVar7 != '\0') {
            iVar10 = VmpDiskGetGptAttributes((_DEVICE_OBJECT *)puVar14[0x2b],&local_f0);
            cVar6 = (char)puVar3[1];
            if (iVar10 < 0) goto LAB_140013c59;
            if (cVar6 != '\0') {
              uVar8 = '\0';
              iVar10 = VmpStoreGptAttributesRevertRecord
                                 ('\0','\x01',(_GUID *)0x0,(_GUID *)(puVar14 + 0x33),0,local_f0);
              if (iVar10 < 0) goto LAB_140013c55;
            }
            iVar10 = VmpDiskSetGptAttributes((_DEVICE_OBJECT *)puVar14[0x2b],*puVar3,uVar8);
            cVar6 = (char)puVar3[1];
            if (iVar10 < 0) goto LAB_140013c59;
            if (cVar6 == '\0') {
              VmpApplyGptAttributes((VM_VOLUME_EXTENSION *)(puVar14 + -4),*puVar3);
            }
          }
        }
        puVar14 = (undefined8 *)*puVar14;
      } while( true );
    }
    if ((char)puVar3[1] == '\0') {
      return iVar10;
    }
    p_Var15 = (_GUID *)0x0;
    pVVar16 = param_1 + 0x1b8;
    uVar8 = '\0';
    uVar7 = '\x01';
  }
  else {
    if (*(longlong *)(param_1 + 0x1d0) == 0) {
      return -0x3ffffff2;
    }
    if (((*puVar3 >> 0x3a & 1) != 0) ||
       (((*puVar3 >> 0x3b & 1) != 0 &&
        (((*(uint *)(*(longlong *)param_1 + 0x30) & 0x600100) != 0 ||
         (*(int *)(param_1 + 0xb4) != 0)))))) {
      return -0x3ffffff0;
    }
    if (*(char *)((longlong)puVar3 + 9) != '\0') {
      return -0x3ffffff3;
    }
    _Var11 = (**(code **)(lVar4 + 0x98))(*(undefined8 *)(param_1 + 0x1d0));
    if ((char)puVar3[1] != '\0') {
      *(undefined8 *)(param_1 + 0x160) = *(undefined8 *)(lVar2 + 0x30);
      *(__uint64 *)(param_1 + 0x168) = _Var11;
      param_1[0x170] = *(VM_VOLUME_EXTENSION *)((longlong)puVar3 + 9);
      (**(code **)(lVar4 + 0x78))(*(undefined8 *)(param_1 + 0x1d0));
      lVar9 = VmpStoreGptAttributesRevertRecord
                        ('\x01','\0',(_GUID *)&local_e8,(_GUID *)0x0,0,_Var11);
      if (lVar9 < 0) goto LAB_14001398a;
    }
    iVar10 = (**(code **)(lVar4 + 0xb0))(*(undefined8 *)(param_1 + 0x1d0),*puVar3,0);
    if (-1 < iVar10) {
      if ((char)puVar3[1] == '\0') {
        VmpApplyGptAttributes(param_1,*puVar3);
      }
      return 0;
    }
    if ((char)puVar3[1] == '\0') {
      return iVar10;
    }
    pVVar16 = (VM_VOLUME_EXTENSION *)0x0;
    p_Var15 = (_GUID *)&local_e8;
    uVar7 = '\0';
    uVar8 = '\x01';
  }
  *(undefined8 *)(param_1 + 0x160) = 0;
  VmpDeleteGptAttributesRevertRecord(uVar8,uVar7,p_Var15,(_GUID *)pVVar16,0);
  return iVar10;
}



===== VmpStoreGptAttributesRevertRecord @ 140013dec =====

/* long __cdecl VmpStoreGptAttributesRevertRecord(unsigned char,unsigned char,struct _GUID *
   __ptr64,struct _GUID * __ptr64,unsigned long,unsigned __int64) */

long __cdecl
VmpStoreGptAttributesRevertRecord
          (uchar param_1,uchar param_2,_GUID *param_3,_GUID *param_4,ulong param_5,__uint64 param_6)

{
  long lVar1;
  int iVar2;
  VM_GPT_ATTRIBUTES_REVERT_ENTRY *pVVar3;
  longlong lVar4;
  VM_GPT_ATTRIBUTES_REVERT_ENTRY *pVVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  ulong local_58 [2];
  undefined8 local_50;
  VM_GPT_ATTRIBUTES_REVERT_ENTRY *local_48 [2];
  
  local_50 = 0;
  local_48[0] = (VM_GPT_ATTRIBUTES_REVERT_ENTRY *)0x0;
  local_58[0] = 0;
  lVar1 = VmpQueryRegistryRevertEntries(local_48,local_58);
  if (lVar1 < 0) {
    pVVar5 = (VM_GPT_ATTRIBUTES_REVERT_ENTRY *)0x0;
    uVar8 = 0;
  }
  else {
    pVVar5 = local_48[0];
    uVar8 = local_58[0];
  }
  uVar7 = 0;
  uVar6 = 0;
  if (uVar8 != 0) {
    do {
      uVar6 = (uint)uVar7;
      pVVar3 = pVVar5 + uVar7 * 0x20;
      if (param_1 == '\0') {
        if (param_2 == '\0') {
          if ((*(ulong *)(pVVar3 + 0x18) == 0) && (*(ulong *)(pVVar3 + 0x1c) == 0)) {
            bVar10 = param_5 == *(ulong *)pVVar3;
            goto LAB_140013ea4;
          }
        }
        else if (*(ulong *)(pVVar3 + 0x1c) != 0) {
          lVar4 = *(longlong *)param_4 - *(longlong *)pVVar3;
          if (lVar4 == 0) {
            lVar4 = *(longlong *)(param_4 + 8);
            goto LAB_140013e72;
          }
          goto LAB_140013e76;
        }
      }
      else if (*(ulong *)(pVVar3 + 0x18) != 0) {
        lVar4 = *(longlong *)param_3 - *(longlong *)pVVar3;
        if (lVar4 == 0) {
          lVar4 = *(longlong *)(param_3 + 8);
LAB_140013e72:
          lVar4 = lVar4 - *(longlong *)(pVVar3 + 8);
        }
LAB_140013e76:
        bVar10 = lVar4 == 0;
LAB_140013ea4:
        if (bVar10) break;
      }
      uVar6 = uVar6 + 1;
      uVar7 = (ulonglong)uVar6;
    } while (uVar6 < uVar8);
  }
  pVVar3 = pVVar5;
  uVar9 = uVar8;
  if (uVar6 == uVar8) {
    uVar9 = uVar8 + 1;
    pVVar3 = (VM_GPT_ATTRIBUTES_REVERT_ENTRY *)
             ExAllocatePool2(0x102,(ulonglong)uVar9 << 5,0x20204d56);
    if (pVVar3 == (VM_GPT_ATTRIBUTES_REVERT_ENTRY *)0x0) {
      if (pVVar5 != (VM_GPT_ATTRIBUTES_REVERT_ENTRY *)0x0) {
        ExFreePoolWithTag(pVVar5,0);
      }
      return -0x3fffff66;
    }
    if (uVar8 != 0) {
      if (pVVar5 == (VM_GPT_ATTRIBUTES_REVERT_ENTRY *)0x0) goto LAB_140013f45;
      memcpy(pVVar3,pVVar5,(ulonglong)uVar8 << 5);
    }
    if (pVVar5 != (VM_GPT_ATTRIBUTES_REVERT_ENTRY *)0x0) {
      ExFreePoolWithTag(pVVar5,0);
    }
  }
LAB_140013f45:
  lVar4 = (ulonglong)uVar6 * 0x20;
  *(undefined8 *)(pVVar3 + lVar4) = 0;
  *(undefined8 *)(pVVar3 + lVar4 + 8) = 0;
  *(undefined8 *)(pVVar3 + lVar4 + 0x18) = 0;
  *(__uint64 *)(pVVar3 + lVar4 + 0x10) = param_6;
  if (param_1 == '\0') {
    if (param_2 == '\0') {
      *(ulong *)(pVVar3 + lVar4) = param_5;
      goto LAB_140013f9a;
    }
    *(undefined4 *)(pVVar3 + lVar4 + 0x1c) = 1;
    uVar11 = *(undefined4 *)param_4;
    uVar12 = *(undefined4 *)(param_4 + 4);
    uVar13 = *(undefined4 *)(param_4 + 8);
    uVar14 = *(undefined4 *)(param_4 + 0xc);
  }
  else {
    *(undefined4 *)(pVVar3 + lVar4 + 0x18) = 1;
    uVar11 = *(undefined4 *)param_3;
    uVar12 = *(undefined4 *)(param_3 + 4);
    uVar13 = *(undefined4 *)(param_3 + 8);
    uVar14 = *(undefined4 *)(param_3 + 0xc);
  }
  pVVar5 = pVVar3 + lVar4;
  *(undefined4 *)pVVar5 = uVar11;
  *(undefined4 *)(pVVar5 + 4) = uVar12;
  *(undefined4 *)(pVVar5 + 8) = uVar13;
  *(undefined4 *)(pVVar5 + 0xc) = uVar14;
LAB_140013f9a:
  iVar2 = IoOpenDriverRegistryKey(*(undefined8 *)(VmRootExtension + 0x20),1,2,0,&local_50);
  if (-1 < iVar2) {
    iVar2 = RtlWriteRegistryValue
                      (0x40000000,local_50,L"GptAttributeRevertEntries",3,pVVar3,uVar9 << 5);
    if (-1 < iVar2) {
      ZwFlushKey(local_50);
    }
    ZwClose(local_50);
    ExFreePoolWithTag(pVVar3,0);
  }
  return iVar2;
}



===== VmpUpdateProperties @ 140014058 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpUpdateProperties(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpUpdateProperties(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  uchar uVar1;
  long lVar2;
  ulonglong uVar3;
  longlong lVar4;
  __uint64 _Var5;
  _DEVICE_OBJECT *p_Var6;
  undefined1 auStackY_e8 [32];
  __uint64 local_b8 [2];
  int local_a8 [8];
  char local_88;
  undefined7 uStack_87;
  longlong local_80;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_b8[0] = 0;
  memset(local_a8,0,0x90);
  if (param_1[0x1ca] != (VM_VOLUME_EXTENSION)0x0) {
    if (*(longlong *)(param_1 + 0x1d0) == 0) {
      return -0x3ffffff2;
    }
    lVar2 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x188) + 0x68))
                      (*(longlong *)(param_1 + 0x1d0),param_2);
    return lVar2;
  }
  if (*(longlong *)(param_1 + 0x178) == 0) {
    return -0x3ffffff2;
  }
  uVar3 = VmpSendDeviceControl(*(longlong *)(param_1 + 0x178),0x70048,0,0,local_a8,0x90);
  lVar2 = (long)uVar3;
  if (lVar2 < 0) {
    return lVar2;
  }
  if (*(longlong *)(param_1 + 0x180) != 0) {
    if (local_a8[0] == 0) {
      if (local_88 == -0x29) {
LAB_14001414e:
        lVar2 = VmpCompleteConversion(param_1,(_DEVICE_OBJECT *)0x0);
        if (-1 < lVar2) {
          return lVar2;
        }
      }
    }
    else if (local_a8[0] == 1) {
      lVar4 = CONCAT71(uStack_87,local_88) + -0x4539dc34e7addcb4;
      if (lVar4 == 0) {
        lVar4 = local_80 + -0x7e6fbe07bdeb769a;
      }
      if (lVar4 == 0) goto LAB_14001414e;
    }
  }
  VmpSetPartitionInformation(param_1,(_PARTITION_INFORMATION_EX *)local_a8);
  p_Var6 = *(_DEVICE_OBJECT **)(param_1 + 0x178);
  lVar4 = *(longlong *)(p_Var6 + 0x40);
  uVar1 = SC_PART_ENTRY::IsRecognized((SC_PART_ENTRY *)local_a8);
  if (uVar1 == '\0') {
    if (((*(uint *)(lVar4 + 0x28) >> 9 & 1) == 0) &&
       (((local_a8[0] != 1 || (CONCAT71(uStack_87,local_88) != 0x11d2f81fc12a7328)) ||
        (local_80 != 0x3bc93ec9a0004bba)))) {
      _Var5 = 0x4000000000000000;
      goto LAB_140014198;
    }
  }
  else {
    lVar2 = VmpDiskGetGptAttributes(p_Var6,local_b8);
    if (lVar2 < 0) {
      return lVar2;
    }
  }
  _Var5 = local_b8[0];
LAB_140014198:
  VmpApplyGptAttributes(param_1,_Var5);
  VmpNotify(param_1,(_GUID *)&GUID_IO_VOLUME_PHYSICAL_CONFIGURATION_CHANGE,0,(void *)0x0);
  return lVar2;
}



===== VmpWholeDiskArrived @ 140014218 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpWholeDiskArrived(class VM_ROOT_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpWholeDiskArrived(VM_ROOT_EXTENSION *param_1,_IRP *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  uchar uVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  VM_ROOT_EXTENSION *pVVar8;
  longlong *plVar9;
  undefined1 *puVar10;
  char local_res10 [8];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar1 = *(undefined8 **)(param_2 + 0x18);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 8) {
    return -0x3ffffff3;
  }
  pVVar8 = param_1;
  VmpAcquireDevices(param_1);
  uVar2 = *puVar1;
  local_res10[0] = '\0';
  if (*(longlong *)(param_1 + 0x188) != 0) {
    VmpRestoreExtensionDriver((longlong)param_1);
    iVar5 = (*(code *)**(undefined8 **)(param_1 + 0x188))(uVar2,local_res10);
    pVVar8 = param_1;
    VmpPageExtensionDriver((longlong)param_1);
    if (iVar5 < 0) goto LAB_1400143a0;
  }
  lVar7 = 0;
  iVar5 = 0;
  if (local_res10[0] != '\0') {
    puVar6 = VM_ALLOCATED_OBJECT::operator_new((__uint64)pVVar8);
    puVar10 = auStack_28;
    if (puVar6 == (undefined8 *)0x0) {
      VmpReleaseDevices(param_1);
    }
    else {
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
      puVar6[3] = 0;
      puVar6[4] = 0;
      *(undefined4 *)(puVar6 + 2) = 0;
      puVar6[3] = *puVar1;
      pVVar8 = param_1 + 0xb8;
      plVar9 = *(longlong **)(param_1 + 0xc0);
      if ((VM_ROOT_EXTENSION *)*plVar9 != pVVar8) {
        pVVar8 = (VM_ROOT_EXTENSION *)0x3;
        pcVar3 = (code *)swi(0x29);
        puVar6 = (undefined8 *)(*pcVar3)();
        puVar10 = auStack_20;
      }
      *puVar6 = pVVar8;
      puVar6[1] = plVar9;
      *plVar9 = (longlong)puVar6;
      *(undefined8 **)(pVVar8 + 8) = puVar6;
      uVar2 = *puVar1;
      *(undefined8 *)(puVar10 + -8) = 0x1400142f1;
      ObfReferenceObject(uVar2);
      if (param_1[200] == (VM_ROOT_EXTENSION)0x0) {
        uVar2 = *(undefined8 *)param_1;
        *(undefined8 *)(puVar10 + -8) = 0x140014309;
        lVar7 = IoAllocateWorkItem(uVar2);
        if (lVar7 != 0) {
          param_1[200] = (VM_ROOT_EXTENSION)0x1;
        }
      }
      *(undefined8 *)(puVar10 + -8) = 0x140014325;
      VmpReleaseDevices(param_1);
      *(undefined8 *)(puVar10 + -8) = 0x14001432d;
      uVar4 = VmpTestAcquireConfig(param_1);
      if (uVar4 == '\0') {
        if (lVar7 != 0) {
          *(undefined8 *)(puVar10 + -8) = 0x14001438d;
          IoQueueWorkItem(lVar7,VmpProcessDiskNotificationsWorkRoutine,1,lVar7);
        }
      }
      else {
        *(undefined8 *)(puVar10 + -8) = 0x140014339;
        VmpAcquireDevices(param_1);
        *(undefined8 *)(puVar10 + -8) = 0x140014341;
        VmpProcessDiskNotifications(param_1);
        if (lVar7 != 0) {
          *(undefined8 *)(puVar10 + -8) = 0x140014350;
          IoFreeWorkItem(lVar7);
          param_1[200] = (VM_ROOT_EXTENSION)0x0;
        }
        *(undefined8 *)(puVar10 + -8) = 0x140014364;
        VmpReleaseDevices(param_1);
        *(undefined8 *)(puVar10 + -8) = 0x14001436c;
        VmpReleaseConfig(param_1);
      }
    }
    return 0;
  }
LAB_1400143a0:
  VmpReleaseDevices(param_1);
  return iVar5;
}



===== VmpWholeDiskArrivedDelayed @ 1400143c4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpWholeDiskArrivedDelayed(class VM_ROOT_EXTENSION * __ptr64,struct _DEVICE_OBJECT *
   __ptr64) */

long __cdecl VmpWholeDiskArrivedDelayed(VM_ROOT_EXTENSION *param_1,_DEVICE_OBJECT *param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(longlong *)(param_1 + 0x188) == 0) {
    iVar2 = 0;
  }
  else {
    VmpRestoreExtensionDriver((longlong)param_1);
    iVar1 = (**(code **)(*(longlong *)(param_1 + 0x188) + 8))(param_2);
    VmpPageExtensionDriver((longlong)param_1);
    iVar2 = 0;
    if (iVar1 < 0) {
      iVar2 = iVar1;
    }
  }
  return iVar2;
}



===== VmpWholeDiskRemoved @ 140014428 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpWholeDiskRemoved(class VM_ROOT_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpWholeDiskRemoved(VM_ROOT_EXTENSION *param_1,_IRP *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  uchar uVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  VM_ROOT_EXTENSION *pVVar8;
  undefined1 *puVar9;
  longlong *plVar10;
  char local_res10 [8];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar1 = *(undefined8 **)(param_2 + 0x18);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 8) {
    return -0x3ffffff3;
  }
  pVVar8 = param_1;
  VmpAcquireDevices(param_1);
  uVar2 = *puVar1;
  local_res10[0] = '\0';
  if (*(longlong *)(param_1 + 0x188) != 0) {
    VmpRestoreExtensionDriver((longlong)param_1);
    iVar5 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x30))(uVar2,local_res10);
    pVVar8 = param_1;
    VmpPageExtensionDriver((longlong)param_1);
    if (iVar5 < 0) goto LAB_1400145b1;
  }
  lVar7 = 0;
  iVar5 = 0;
  if (local_res10[0] != '\0') {
    puVar6 = VM_ALLOCATED_OBJECT::operator_new((__uint64)pVVar8);
    puVar9 = auStack_28;
    if (puVar6 == (undefined8 *)0x0) {
      VmpReleaseDevices(param_1);
    }
    else {
      *puVar6 = 0;
      puVar6[1] = 0;
      puVar6[2] = 0;
      puVar6[3] = 0;
      puVar6[4] = 0;
      *(undefined4 *)(puVar6 + 2) = 3;
      puVar6[3] = *puVar1;
      pVVar8 = param_1 + 0xb8;
      plVar10 = *(longlong **)(param_1 + 0xc0);
      if ((VM_ROOT_EXTENSION *)*plVar10 != pVVar8) {
        pcVar3 = (code *)swi(0x29);
        puVar6 = (undefined8 *)(*pcVar3)();
        puVar9 = auStack_20;
      }
      *puVar6 = pVVar8;
      puVar6[1] = plVar10;
      *plVar10 = (longlong)puVar6;
      *(undefined8 **)(pVVar8 + 8) = puVar6;
      uVar2 = *puVar1;
      *(undefined8 *)(puVar9 + -8) = 0x140014502;
      ObfReferenceObject(uVar2);
      if (param_1[200] == (VM_ROOT_EXTENSION)0x0) {
        uVar2 = *(undefined8 *)param_1;
        *(undefined8 *)(puVar9 + -8) = 0x14001451a;
        lVar7 = IoAllocateWorkItem(uVar2);
        if (lVar7 != 0) {
          param_1[200] = (VM_ROOT_EXTENSION)0x1;
        }
      }
      *(undefined8 *)(puVar9 + -8) = 0x140014536;
      VmpReleaseDevices(param_1);
      *(undefined8 *)(puVar9 + -8) = 0x14001453e;
      uVar4 = VmpTestAcquireConfig(param_1);
      if (uVar4 == '\0') {
        if (lVar7 != 0) {
          *(undefined8 *)(puVar9 + -8) = 0x14001459e;
          IoQueueWorkItem(lVar7,VmpProcessDiskNotificationsWorkRoutine,1,lVar7);
        }
      }
      else {
        *(undefined8 *)(puVar9 + -8) = 0x14001454a;
        VmpAcquireDevices(param_1);
        *(undefined8 *)(puVar9 + -8) = 0x140014552;
        VmpProcessDiskNotifications(param_1);
        if (lVar7 != 0) {
          *(undefined8 *)(puVar9 + -8) = 0x140014561;
          IoFreeWorkItem(lVar7);
          param_1[200] = (VM_ROOT_EXTENSION)0x0;
        }
        *(undefined8 *)(puVar9 + -8) = 0x140014575;
        VmpReleaseDevices(param_1);
        *(undefined8 *)(puVar9 + -8) = 0x14001457d;
        VmpReleaseConfig(param_1);
      }
    }
    return 0;
  }
LAB_1400145b1:
  VmpReleaseDevices(param_1);
  return iVar5;
}



===== VmpWholeDiskRemovedDelayed @ 1400145d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpWholeDiskRemovedDelayed(class VM_ROOT_EXTENSION * __ptr64,struct _DEVICE_OBJECT *
   __ptr64) */

long __cdecl VmpWholeDiskRemovedDelayed(VM_ROOT_EXTENSION *param_1,_DEVICE_OBJECT *param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(longlong *)(param_1 + 0x188) == 0) {
    iVar2 = 0;
  }
  else {
    VmpRestoreExtensionDriver((longlong)param_1);
    iVar1 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x38))(param_2);
    VmpPageExtensionDriver((longlong)param_1);
    iVar2 = 0;
    if (iVar1 < 0) {
      iVar2 = iVar1;
    }
  }
  return iVar2;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 140014638 =====

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
  local_28 = *(undefined4 *)(PTR_DAT_14000b050 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_14000b050 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_14000b050 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_14000b050 + -4);
  if (DAT_14000b068 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_14000b070 = 0;
  uRam000000014000b078 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x14001469b;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_14000b048,&DAT_14000b068);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_14000b050;
    *(undefined8 *)(puVar4 + -8) = 0x1400146c2;
    EtwSetInformation(DAT_14000b068,2,PTR_DAT_14000b050,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x1400146d6;
  return iVar3;
}



===== VmBootDriverReinitialization @ 1400146f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmBootDriverReinitialization(void)

{
  if (*(longlong *)(VmRootExtension + 0x188) != 0) {
    VmpAcquireAll(VmRootExtension);
    (**(code **)(*(longlong *)(VmRootExtension + 0x188) + 0x40))();
    VmpReleaseAll(VmRootExtension);
  }
  return;
}



===== VmDriverReinitialization @ 140014740 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmDriverReinitialization(void)

{
  if (*(longlong *)(VmRootExtension + 0x188) != 0) {
    VmpAcquireAll(VmRootExtension);
    (**(code **)(*(longlong *)(VmRootExtension + 0x188) + 0x48))();
    VmpPageExtensionDriver((longlong)VmRootExtension);
    VmpReleaseAll(VmRootExtension);
  }
  return;
}



===== VmLogError @ 1400147a0 =====

void VmLogError(undefined8 *param_1,undefined4 param_2,ushort param_3,undefined8 param_4)

{
  short *psVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined4 in_register_00000014;
  ushort uVar5;
  undefined8 uVar6;
  ushort *puVar7;
  ushort local_res18 [4];
  undefined8 local_res20;
  short *local_68;
  ulonglong local_60;
  undefined8 local_58;
  longlong lStack_50;
  
  local_60 = 0;
  local_58 = 0;
  lStack_50 = 0;
  if (param_1 == (undefined8 *)0x0) {
    uVar6 = *(undefined8 *)(VmRootExtension + 0x20);
  }
  else {
    uVar6 = *param_1;
  }
  local_res18[0] = param_3;
  local_res20 = param_4;
  lVar4 = IoAllocateErrorLogEntry
                    (uVar6,CONCAT71((int7)(CONCAT44(in_register_00000014,param_2) >> 8),0xf0));
  if (lVar4 == 0) goto LAB_1400148fe;
  *(undefined4 *)(lVar4 + 0xc) = param_2;
  local_60 = 200;
  psVar1 = (short *)(lVar4 + 0x28);
  *(undefined4 *)(lVar4 + 2) = 0;
  *(undefined2 *)(lVar4 + 6) = 0x28;
  local_68 = psVar1;
  if (param_1 != (undefined8 *)0x0) {
    iVar2 = IoVolumeDeviceToDosName(uVar6,&local_58);
    if ((iVar2 < 0) || ((ushort)local_58 < 2)) goto LAB_1400148fe;
    uVar3 = RtlStringCbCopyExW(psVar1,200,lStack_50,&local_68,(longlong *)&local_60);
    if ((int)uVar3 < 0) goto LAB_1400148fe;
    local_68 = local_68 + 1;
    *(short *)(lVar4 + 4) = *(short *)(lVar4 + 4) + 1;
    local_60 = local_60 - 2;
  }
  uVar5 = 0;
  puVar7 = local_res18;
  for (; (uVar5 < local_res18[0] && (local_60 != 0)); local_60 = local_60 - 2) {
    puVar7 = puVar7 + 4;
    if (*(longlong *)puVar7 == 0) goto LAB_1400148fe;
    uVar3 = RtlStringCbCopyExW(local_68,local_60,*(longlong *)puVar7,&local_68,(longlong *)&local_60
                              );
    if ((int)uVar3 < 0) goto LAB_1400148fe;
    local_68 = local_68 + 1;
    *(short *)(lVar4 + 4) = *(short *)(lVar4 + 4) + 1;
    uVar5 = uVar5 + 1;
  }
  IoWriteErrorLogEntry(lVar4);
LAB_1400148fe:
  if (lStack_50 != 0) {
    ExFreePoolWithTag(lStack_50,0);
  }
  return;
}



===== VmUnload @ 140014930 =====

void VmUnload(void)

{
  undefined8 uVar1;
  
  McGenEventUnregister_EtwUnregister();
  uVar1 = DAT_14000b068;
  DAT_14000b068 = 0;
  DAT_14000b048 = 0;
  EtwUnregister(uVar1);
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



===== VmVolumeDeviceNotification @ 1400149b0 =====

undefined8 VmVolumeDeviceNotification(longlong param_1)

{
  _FILE_OBJECT *p_Var1;
  long lVar2;
  longlong lVar3;
  _FILE_OBJECT *local_res8;
  
  local_res8 = (_FILE_OBJECT *)0x0;
  lVar3 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4004;
  if (lVar3 == 0) {
    lVar3 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
  }
  if (lVar3 == 0) {
    lVar2 = VmpGetDeviceObjectPointer(*(_UNICODE_STRING **)(param_1 + 0x28),&local_res8);
    p_Var1 = local_res8;
    if (-1 < lVar2) {
      lVar3 = IoGetAttachedDeviceReference(*(undefined8 *)(local_res8 + 8));
      VmpSendDeviceControl(lVar3,0x56c008,0,0,0,0);
      VmpSendDeviceControl(lVar3,0x56c064,0,0,0,0);
      if (lVar3 != 0) {
        ObfDereferenceObject(lVar3);
      }
    }
    if (p_Var1 != (_FILE_OBJECT *)0x0) {
      ObfDereferenceObject(p_Var1);
    }
  }
  return 0;
}



===== VmpProcessDiskNotificationsWorkRoutine @ 140014a90 =====

void VmpProcessDiskNotificationsWorkRoutine(longlong param_1,undefined8 param_2)

{
  VM_ROOT_EXTENSION *pVVar1;
  
  pVVar1 = *(VM_ROOT_EXTENSION **)(param_1 + 0x40);
  VmpAcquireAll(pVVar1);
  pVVar1[200] = (VM_ROOT_EXTENSION)0x0;
  VmpReleaseAll(pVVar1);
  IoFreeWorkItem(param_2);
  return;
}



===== VmpProcessIrpQueueWorkerRoutine @ 140014ae0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmpProcessIrpQueueWorkerRoutine(undefined8 param_1,longlong ****param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong ******pppppplVar2;
  code *pcVar3;
  longlong ******pppppplVar4;
  longlong ******local_18;
  longlong ******local_10;
  
  lVar1 = *(longlong *)(VmRootExtension + 0x20);
  local_18 = (longlong ******)&local_18;
  pppppplVar4 = (longlong ******)&local_18;
  if (((longlong ****)(*param_2)[1] == param_2) &&
     (local_10 = (longlong ******)param_2[1], *local_10 == (longlong *****)param_2)) {
    *local_10 = (longlong *****)&local_18;
    param_2[1] = (longlong ***)&local_18;
    local_18 = (longlong ******)param_2;
    while( true ) {
      if ((longlong *******)local_18 == &local_18) {
        IoFreeWorkItem(param_3);
        return;
      }
      pppppplVar4 = local_10;
      if (((longlong *******)local_18[1] != &local_18) ||
         (pppppplVar2 = (longlong ******)*local_18, (longlong ******)pppppplVar2[1] != local_18))
      break;
      pppppplVar2[1] = (longlong *****)&local_18;
      pppppplVar4 = local_18 + 2;
      local_18 = pppppplVar2;
      (**(code **)(lVar1 + 0x70 + (ulonglong)*(byte *)*pppppplVar4 * 8))(param_1);
    }
  }
  local_10 = pppppplVar4;
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== VmpQueryHotplugProtectionQueryRoutine @ 140014bd0 =====

undefined8
VmpQueryHotplugProtectionQueryRoutine
          (undefined8 param_1,undefined8 param_2,void *param_3,uint param_4,undefined8 param_5,
          undefined8 *param_6)

{
  char cVar1;
  void *_Dst;
  
  if ((param_4 < 0x28) || (cVar1 = RtlValidSecurityDescriptor(param_3), cVar1 == '\0')) {
    return 0xc0000079;
  }
  _Dst = (void *)ExAllocatePool2(0x102,(ulonglong)param_4,0x20204d56);
  if (_Dst == (void *)0x0) {
    return 0xc000009a;
  }
  memcpy(_Dst,param_3,(ulonglong)param_4);
  *param_6 = _Dst;
  return 0;
}



===== VmpQueryRegistryRevertEntriesCallback @ 140014c70 =====

undefined8
VmpQueryRegistryRevertEntriesCallback
          (undefined8 param_1,int param_2,void *param_3,uint param_4,undefined8 *param_5,
          uint *param_6)

{
  void *_Dst;
  
  if (param_2 == 3) {
    _Dst = (void *)ExAllocatePool2(0x102,(ulonglong)param_4,0x20204d56);
    *param_5 = _Dst;
    if (_Dst == (void *)0x0) {
      return 0xc000009a;
    }
    memcpy(_Dst,param_3,(ulonglong)param_4);
    *param_6 = param_4 >> 5;
  }
  return 0;
}



===== VmpRemoveDevice @ 140014ce8 =====

void VmpRemoveDevice(longlong param_1,char param_2)

{
  VM_ROOT_EXTENSION *pVVar1;
  
  pVVar1 = VmRootExtension;
  if (*(longlong *)(VmRootExtension + 0x178) != 0) {
    IoUnregisterPlugPlayNotification(*(longlong *)(VmRootExtension + 0x178));
    pVVar1 = VmRootExtension;
    *(undefined8 *)(VmRootExtension + 0x178) = 0;
  }
  if (*(longlong *)(pVVar1 + 0x168) != 0) {
    ExFreePoolWithTag(*(longlong *)(pVVar1 + 0x168),0);
    pVVar1 = VmRootExtension;
    *(undefined8 *)(VmRootExtension + 0x168) = 0;
  }
  if (*(longlong *)(pVVar1 + 0x158) != 0) {
    ExFreePoolWithTag(*(longlong *)(pVVar1 + 0x158),0);
    pVVar1 = VmRootExtension;
    *(undefined8 *)(VmRootExtension + 0x158) = 0;
  }
  RtlFreeUnicodeString(pVVar1 + 0x120);
  if ((*(uint *)(param_1 + 0x30) >> 0xb & 1) != 0) {
    IoUnregisterShutdownNotification(param_1);
  }
  IoDeleteSymbolicLink(&DAT_140008090);
  if (*(longlong *)(VmRootExtension + 0xb0) != 0) {
    IoSetDeviceInterfaceState(VmRootExtension + 0xa8,0);
    RtlFreeUnicodeString(VmRootExtension + 0xa8);
  }
  if (param_2 != '\0') {
    if (*(longlong *)(VmRootExtension + 0x28) != 0) {
      IoDetachDevice();
      *(undefined8 *)(VmRootExtension + 0x28) = 0;
    }
    IoDeleteDevice(param_1);
  }
  return;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 140014e50 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 140014f1c =====

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
      goto LAB_140014f79;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_140014f79;
    }
  }
  uVar1 = 0x206;
LAB_140014f79:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140014f84 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  bool bVar6;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding
                     ((longlong *)&Feature_SFS_CD_BugFixes_2505__private_descriptor);
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
  ppuVar2 = &Feature_SFS_CD_BugFixes_2505__private_descriptor;
  while( true ) {
    plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)ppuVar2);
    if (plVar1 == (longlong *)0x0) break;
    wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState
              ((uint *)*plVar1,(longlong)plVar1);
    ppuVar2 = (undefined **)(plVar1 + 7);
  }
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001503c =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140015074 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_1400150f6;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_1400150f6;
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
LAB_1400150f6:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140015140 =====

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
      ppuVar3 = &Feature_SFS_CD_BugFixes_2505__private_descriptor;
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



===== wil_details_RecordFeatureUsageCallback @ 140015194 =====

void wil_details_RecordFeatureUsageCallback(void)

{
  RtlRecordFeatureUsage();
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1400151b0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 1400151cc =====

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
  ppuVar3 = &Feature_SFS_CD_BugFixes_2505__private_descriptor;
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



===== VmQueryWmiRegInfo @ 140015280 =====

undefined8
VmQueryWmiRegInfo(longlong param_1,undefined4 *param_2,longlong param_3,longlong *param_4,
                 undefined8 param_5,longlong *param_6)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(undefined8 *)(param_3 + 8) = 0;
  *param_4 = *(longlong *)(lVar1 + 8) + 0x120;
  *param_2 = 0x21;
  *param_6 = param_1;
  return 0;
}



===== VmWmiFunctionControl @ 1400152b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmWmiFunctionControl(longlong param_1,undefined8 param_2,int param_3,int param_4,char param_5)

{
  longlong lVar1;
  longlong lVar2;
  undefined1 uVar3;
  int iVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar2 = *(longlong *)(lVar1 + 8);
  if (param_3 == 0) {
    iVar4 = 0;
    if (param_4 == 1) {
      if (param_5 == '\0') {
        Feature_RacyAccessesInVolmgrAreCountersEnabled__private_IsEnabledDeviceUsageNoInline();
        uVar3 = (**(code **)(lVar2 + 0x138))(lVar1 + 0x100,0,0);
        *(undefined1 *)(lVar1 + 0xc1) = uVar3;
      }
      else {
        iVar4 = (**(code **)(lVar2 + 0x130))(lVar1 + 0x100);
        if (-1 < iVar4) {
          Feature_RacyAccessesInVolmgrAreCountersEnabled__private_IsEnabledDeviceUsageNoInline();
          *(undefined1 *)(lVar1 + 0xc1) = 1;
        }
      }
    }
  }
  else {
    iVar4 = -0x3ffffd6b;
  }
  WmiCompleteRequest(param_1,param_2,iVar4,0,0);
  return;
}



===== VmpQueryEnableCountersAlways @ 140015380 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int VmpQueryEnableCountersAlways(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined4 *local_90;
  undefined4 local_88 [2];
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined8 local_60;
  undefined8 *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined1 local_38 [8];
  int local_30;
  int local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_b8;
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_64 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_4c = 0;
  local_80 = 0;
  local_88[0] = 0;
  RtlInitUnicodeString
            (&local_78,L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\Partmgr");
  local_58 = &local_78;
  local_68 = 0x30;
  local_60 = 0;
  local_50 = 0x240;
  local_48 = 0;
  uStack_40 = 0;
  iVar2 = ZwOpenKey(&local_80,0x20019,&local_68);
  if (-1 < iVar2) {
    RtlInitUnicodeString(&local_78,L"EnableCounterForIoctl");
    local_90 = local_88;
    local_98 = 0x10;
    iVar2 = ZwQueryValueKey(local_80,&local_78,2,local_38);
    iVar3 = 0;
    if ((-1 < iVar2) && (iVar3 = 0, local_30 == 4)) {
      iVar3 = local_2c;
    }
    ZwClose(local_80);
    if (-1 < iVar2) {
      if (iVar3 == 1) {
        LOCK();
        bVar4 = *(int *)(lVar1 + 0xf8) == 0;
        if (bVar4) {
          *(int *)(lVar1 + 0xf8) = 1;
        }
        UNLOCK();
        if (bVar4) {
          iVar2 = (**(code **)(*(longlong *)(lVar1 + 8) + 0x130))(lVar1 + 0x100);
          if (iVar2 < 0) {
            LOCK();
            *(undefined4 *)(lVar1 + 0xf8) = 0;
            UNLOCK();
          }
          else {
            Feature_RacyAccessesInVolmgrAreCountersEnabled__private_IsEnabledDeviceUsageNoInline();
            *(undefined1 *)(lVar1 + 0xc1) = 1;
          }
        }
      }
      else {
        iVar2 = -0x3ffffff0;
      }
    }
  }
  return iVar2;
}



===== VmpRegisterDevice @ 140015510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VmpRegisterDevice(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  iVar3 = IoWMIRegistrationControl(param_1,0x810001);
  if (-1 < iVar3) {
    lVar2 = *(longlong *)(lVar1 + 8);
    (**(code **)(lVar2 + 0x130))(lVar1 + 0x100);
    (**(code **)(lVar2 + 0x138))(lVar1 + 0x100,0,0);
  }
  return iVar3;
}



===== VmpQueryDeviceName @ 140015590 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl VmpQueryDeviceName(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpQueryDeviceName(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  longlong lVar1;
  ushort *puVar2;
  longlong lVar3;
  errno_t eVar4;
  long lVar5;
  ulonglong uVar6;
  longlong lVar8;
  longlong lVar7;
  short sVar9;
  undefined1 auStack_a8 [48];
  wchar_t local_78 [40];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if (*(uint *)(lVar1 + 8) < 4) {
    lVar5 = -0x3ffffff3;
  }
  else {
    builtin_wcsncpy(local_78,L"\\Device\\HarddiskVolume",0x16);
    sVar9 = 0x16;
    eVar4 = _itow_s(*(int *)(param_1 + 0xc4),local_78 + 0x16,0x16,10);
    if (-1 < eVar4) {
      lVar8 = -1;
      do {
        lVar7 = lVar8 + 1;
        lVar3 = lVar8 + 0x17;
        lVar8 = lVar7;
      } while (local_78[lVar3] != L'\0');
      sVar9 = (short)lVar7 * -2 + 0x16;
    }
    puVar2 = *(ushort **)(param_2 + 0x18);
    *puVar2 = 0x42U - sVar9;
    uVar6 = (ulonglong)(ushort)(0x42U - sVar9) + 2;
    *(ulonglong *)(param_2 + 0x38) = uVar6;
    if (*(uint *)(lVar1 + 8) < uVar6) {
      *(undefined8 *)(param_2 + 0x38) = 2;
      lVar5 = -0x7ffffffb;
    }
    else {
      memcpy(puVar2 + 1,local_78,(ulonglong)*puVar2);
      lVar5 = 0;
    }
  }
  return lVar5;
}



===== VmpGetVolumeDiskExtents @ 1400156d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpGetVolumeDiskExtents(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64)
    */

long __cdecl VmpGetVolumeDiskExtents(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  int iVar3;
  ulonglong uVar4;
  undefined1 local_98 [8];
  undefined8 local_90;
  undefined8 local_88;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  memset(local_98,0,0x90);
  if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
    if (*(uint *)(lVar1 + 8) < 0x20) {
      iVar3 = -0x3ffffff3;
    }
    else {
      uVar4 = VmpSendDeviceControl(*(undefined8 *)(param_1 + 0x178),0x70048,0,0,local_98,0x90);
      iVar3 = (int)uVar4;
      if (-1 < iVar3) {
        puVar2 = *(undefined8 **)(param_2 + 0x18);
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[3] = 0;
        *(undefined4 *)puVar2 = 1;
        *(undefined4 *)(puVar2 + 1) = *(undefined4 *)(param_1 + 0x1a0);
        puVar2[2] = local_90;
        puVar2[3] = local_88;
        iVar3 = 0;
        *(undefined8 *)(param_2 + 0x38) = 0x20;
      }
    }
  }
  else {
    iVar3 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x188) + 0x68))
                      (*(undefined8 *)(param_1 + 0x1d0),param_2);
  }
  return iVar3;
}



===== VmpDiskGetGptAttributes @ 1400157d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl VmpDiskGetGptAttributes(struct _DEVICE_OBJECT * __ptr64,unsigned __int64 * __ptr64)
    */

long __cdecl VmpDiskGetGptAttributes(_DEVICE_OBJECT *param_1,__uint64 *param_2)

{
  ulonglong uVar1;
  undefined1 auStackY_58 [32];
  undefined8 local_28;
  __uint64 _Stack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  *param_2 = 0;
  local_28 = 0;
  _Stack_20 = 0;
  uVar1 = VmpSendDeviceControl(param_1,0x700e8,0,0,&local_28,0x10);
  if (-1 < (int)uVar1) {
    *param_2 = _Stack_20;
  }
  return (int)uVar1;
}



===== VmpDiskIsWritable @ 140015840 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpDiskIsWritable(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpDiskIsWritable(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  long lVar4;
  
  puVar2 = *(undefined8 **)(param_2 + 0xb8);
  puVar2[-9] = *puVar2;
  puVar2[-8] = puVar2[1];
  puVar2[-7] = puVar2[2];
  puVar2[-6] = puVar2[3];
  *(undefined4 *)(puVar2 + -5) = *(undefined4 *)(puVar2 + 4);
  *(undefined4 *)((longlong)puVar2 + -0x24) = *(undefined4 *)((longlong)puVar2 + 0x24);
  *(undefined4 *)(puVar2 + -4) = *(undefined4 *)(puVar2 + 5);
  *(undefined4 *)((longlong)puVar2 + -0x1c) = *(undefined4 *)((longlong)puVar2 + 0x2c);
  uVar1 = puVar2[6];
  puVar2[-3] = uVar1;
  *(undefined1 *)((longlong)puVar2 + -0x45) = 0;
  lVar3 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar3 + -0x10) = VmpRefCountCompletionRoutine;
  *(undefined8 *)(lVar3 + -8) = 0x70024;
  *(undefined1 *)(lVar3 + -0x45) = 0xe0;
  if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
    lVar4 = IofCallDriver(*(undefined8 *)(param_1 + 0x178));
  }
  else {
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + -0x48;
    param_2[0x43] = (_IRP)((char)param_2[0x43] + -1);
    *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) = *(byte *)(*(longlong *)(param_2 + 0xb8) + 3) | 1;
    (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x188) + 0xd8))
              (*(undefined8 *)(param_1 + 0x1d0),(int)uVar1,VmBroadcastIrpCompletionRoutine,param_2,1
              );
    lVar4 = 0x103;
  }
  return lVar4;
}



===== VmpQueryUniqueId @ 140015910 =====

/* long __cdecl VmpQueryUniqueId(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpQueryUniqueId(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  ushort *puVar1;
  long lVar2;
  
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 4) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    lVar2 = -0x3ffffff3;
  }
  else {
    puVar1 = *(ushort **)(param_2 + 0x18);
    *puVar1 = (short)*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) - 2;
    lVar2 = VmpQueryUniqueIdInternal(param_1,puVar1,(uchar *)(puVar1 + 1));
    if (-1 < lVar2) {
      *(ulonglong *)(param_2 + 0x38) = (ulonglong)*puVar1 + 2;
      return lVar2;
    }
    *(undefined8 *)(param_2 + 0x38) = 2;
  }
  return lVar2;
}



===== VmpQueryUniqueIdInternal @ 140015990 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpQueryUniqueIdInternal(class VM_VOLUME_EXTENSION * __ptr64,unsigned short *
   __ptr64,unsigned char * __ptr64) */

long __cdecl VmpQueryUniqueIdInternal(VM_VOLUME_EXTENSION *param_1,ushort *param_2,uchar *param_3)

{
  undefined8 uVar1;
  long lVar2;
  longlong lVar3;
  ushort uVar4;
  
  lVar3 = 0;
  if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
    lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x178) + 0x40);
    uVar4 = **(ushort **)(lVar3 + 0x50);
  }
  else {
    uVar4 = 0x18;
  }
  if (*param_2 < uVar4) {
    *param_2 = uVar4;
    lVar2 = -0x7ffffffb;
  }
  else {
    if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
      memcpy(param_3,(void *)(*(longlong *)(lVar3 + 0x50) + 2),(ulonglong)uVar4);
    }
    else {
      (**(code **)(*(longlong *)(VmRootExtension + 0x188) + 0x78))
                (*(undefined8 *)(param_1 + 0x1d0),param_1 + 0x1b8);
      param_3[0] = 'D';
      param_3[1] = 'M';
      param_3[2] = 'I';
      param_3[3] = 'O';
      param_3[4] = ':';
      param_3[5] = 'I';
      param_3[6] = 'D';
      param_3[7] = ':';
      uVar1 = *(undefined8 *)(param_1 + 0x1c0);
      *(undefined8 *)(param_3 + 8) = *(undefined8 *)(param_1 + 0x1b8);
      *(undefined8 *)(param_3 + 0x10) = uVar1;
    }
    lVar2 = 0;
    *param_2 = uVar4;
  }
  return lVar2;
}



===== VmpPrepareForShrink @ 140015a70 =====

/* long __cdecl VmpPrepareForShrink(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpPrepareForShrink(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  return -(uint)(*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 8) & 0xc000000d;
}



===== VmpIsCsv @ 140015a90 =====

/* long __cdecl VmpIsCsv(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpIsCsv(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 0) {
    return -0x3ffffff3;
  }
  **(undefined1 **)(param_2 + 0x18) = 0;
  *(undefined8 *)(param_2 + 0x38) = 1;
  return 0;
}



===== VmpIsDynamic @ 140015ac0 =====

/* long __cdecl VmpIsDynamic(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpIsDynamic(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 0) {
    return -0x3ffffff3;
  }
  *(bool *)*(undefined8 *)(param_2 + 0x18) = param_1[0x1ca] != (VM_VOLUME_EXTENSION)0x0;
  *(undefined8 *)(param_2 + 0x38) = 1;
  return 0;
}



===== _tlgEnableCallback @ 140015b00 =====

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



===== VmpQueryInterfaceName @ 140015b90 =====

/* long __cdecl VmpQueryInterfaceName(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpQueryInterfaceName(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  VM_VOLUME_EXTENSION VVar1;
  ushort *puVar2;
  long lVar3;
  longlong lVar4;
  longlong lVar5;
  uint uVar6;
  
  lVar5 = *(longlong *)(param_2 + 0xb8);
  if (*(uint *)(lVar5 + 8) < 2) {
    return -0x3ffffff3;
  }
  VVar1 = param_1[0xb8];
  puVar2 = *(ushort **)(param_2 + 0x18);
  lVar4 = 200;
  if (VVar1 != (VM_VOLUME_EXTENSION)0x0) {
    lVar4 = 0xd8;
  }
  *puVar2 = *(ushort *)(param_1 + lVar4);
  *(undefined8 *)(param_2 + 0x38) = 2;
  uVar6 = *puVar2 + 2;
  if (*(uint *)(lVar5 + 8) < uVar6) {
    lVar3 = -0x7ffffffb;
  }
  else {
    lVar5 = 0xd0;
    if (VVar1 != (VM_VOLUME_EXTENSION)0x0) {
      lVar5 = 0xe0;
    }
    memcpy(puVar2 + 1,*(void **)(param_1 + lVar5),(ulonglong)*puVar2);
    if (param_2[0x40] != (_IRP)0x0) {
      puVar2[2] = 0x5c;
    }
    lVar3 = 0;
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar6;
  }
  return lVar3;
}



===== VmQueryDynamicExtension @ 140015c50 =====

/* void * __ptr64 __cdecl VmQueryDynamicExtension(void * __ptr64,void * __ptr64) */

void * __cdecl VmQueryDynamicExtension(void *param_1,void *param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)((longlong)param_1 + 0xd0);
  while( true ) {
    if (puVar1 == (undefined8 *)((longlong)param_1 + 0xd0)) {
      return (void *)0x0;
    }
    if ((*(char *)((longlong)puVar1 + 0x1aa) != '\0') && ((void *)puVar1[0x36] == param_2)) break;
    puVar1 = (undefined8 *)*puVar1;
  }
  return puVar1 + -4;
}



===== VmpOnline @ 140015c90 =====

/* long __cdecl VmpOnline(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpOnline(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  long lVar1;
  
  lVar1 = 0;
  if (param_1[0xc0] != (VM_VOLUME_EXTENSION)0x0) {
    if ((*(ulonglong *)(param_1 + 0x158) >> 0x3b & 1) == 0) {
      lVar1 = VmpZeroRefCallback(param_1,VmpChangeOfflineCallback,(void *)0x0);
      if (-1 < lVar1) {
        KeWaitForSingleObject(param_1 + 0x50,0,0,0,0);
        if ((param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) && (*(longlong *)(param_1 + 0x178) != 0)) {
          IoForwardIrpSynchronously(*(longlong *)(param_1 + 0x178),param_2);
        }
        KeReleaseMutex(param_1 + 0x50,0);
      }
    }
    else {
      lVar1 = -0x3ffffff0;
    }
  }
  *(long *)(param_2 + 0x30) = lVar1;
  IofCompleteRequest(param_2,0);
  return lVar1;
}



===== VmQueryDeviceName @ 140015d70 =====

/* void __cdecl VmQueryDeviceName(void * __ptr64,unsigned short * __ptr64,unsigned long) */

void __cdecl VmQueryDeviceName(void *param_1,ushort *param_2,ulong param_3)

{
  int _Val;
  wchar_t *pwVar1;
  
  _Val = *(int *)((longlong)param_1 + 0xc4);
  if (0x2b < (ushort)param_3) {
    param_2[0] = L'\\';
    param_2[1] = L'D';
    param_2[2] = L'e';
    param_2[3] = L'v';
    pwVar1 = (wchar_t *)(param_2 + 4);
    pwVar1[0] = L'i';
    pwVar1[1] = L'c';
    pwVar1[2] = L'e';
    pwVar1[3] = L'\\';
    (param_2 + 8)[0] = L'H';
    (param_2 + 8)[1] = L'a';
    (param_2 + 10)[0] = L'r';
    (param_2 + 10)[1] = L'd';
    (param_2 + 0xc)[0] = L'd';
    (param_2 + 0xc)[1] = L'i';
    (param_2 + 0xe)[0] = L's';
    (param_2 + 0xe)[1] = L'k';
    param_2[0x10] = 0x56;
    param_2[0x11] = 0x6f;
    param_2[0x12] = 0x6c;
    param_2[0x13] = 0x75;
    param_2[0x14] = 0x6d;
    param_2[0x15] = 0x65;
    _itow_s(_Val,(wchar_t *)(param_2 + 0x16),(ulonglong)(ushort)((ushort)param_3 - 0x2c),10);
  }
  return;
}



===== VmpAcquireRundown @ 140015de0 =====

/* void __cdecl VmpAcquireRundown(class VM_VOLUME_EXTENSION * __ptr64) */

void __cdecl VmpAcquireRundown(VM_VOLUME_EXTENSION *param_1)

{
  KeWaitForSingleObject(param_1 + 0x50,0,0,0,0);
  return;
}



===== VmpManageBypassIo @ 140015e20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl VmpManageBypassIo(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpManageBypassIo(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *_Dst;
  bool bVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  undefined1 auStack_a8 [32];
  wchar_t local_88 [12];
  wchar_t local_70 [32];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar4 = *(longlong *)(param_2 + 0xb8);
  iVar6 = 0;
  builtin_wcsncpy(local_88,L"volmgr.sys",0xb);
  builtin_wcsncpy(local_70,L"Dynamic volumes not supported",0x1e);
  VmpAcquireAll(*(VM_ROOT_EXTENSION **)(param_1 + 8));
  bVar3 = VmpIsVolumeDead((longlong)param_1);
  if (bVar3) {
    iVar6 = -0x3ffffff2;
  }
  else if (*(uint *)(lVar4 + 0x10) < 0x18) {
    iVar6 = -0x3ffffffc;
  }
  else {
    _Dst = *(undefined4 **)(param_2 + 0x18);
    iVar1 = _Dst[2];
    if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
      IoForwardIrpSynchronously(*(undefined8 *)(param_1 + 0x178),param_2);
      iVar6 = *(int *)(param_2 + 0x30);
      if (-1 < iVar6) {
        if (iVar1 == 2) {
          param_1[0xb0] = (VM_VOLUME_EXTENSION)0x0;
        }
        else if ((iVar1 == 1) && (-1 < *(int *)(*(longlong *)(param_2 + 0x18) + 0x18))) {
          param_1[0xb0] = (VM_VOLUME_EXTENSION)0x1;
        }
      }
    }
    else if ((iVar1 - 1U & 0xfffffffd) == 0) {
      uVar2 = *(uint *)(lVar4 + 8);
      if (uVar2 < 0x160) {
        iVar6 = -0x3fffffdd;
      }
      else {
        memset(_Dst,0,(ulonglong)uVar2);
        lVar4 = -1;
        *_Dst = 0x160;
        lVar5 = -1;
        _Dst[1] = 0x160;
        _Dst[2] = iVar1;
        _Dst[6] = 0xc00004c6;
        do {
          lVar5 = lVar5 + 1;
        } while (local_88[lVar5] != L'\0');
        *(short *)(_Dst + 7) = (short)lVar5;
        do {
          lVar4 = lVar4 + 1;
        } while (local_70[lVar4] != L'\0');
        *(short *)((longlong)_Dst + 0x5e) = (short)lVar4;
        wcscpy_s((wchar_t *)((longlong)_Dst + 0x1e),0x40,local_88);
        wcscpy_s((wchar_t *)(_Dst + 0x18),0x100,local_70);
        *(undefined8 *)(param_2 + 0x38) = 0x160;
      }
    }
  }
  VmpReleaseAll(*(VM_ROOT_EXTENSION **)(param_1 + 8));
  *(int *)(param_2 + 0x30) = iVar6;
  IofCompleteRequest(param_2,0);
  return iVar6;
}



===== VmpIsVolumeDead @ 140016060 =====

bool VmpIsVolumeDead(longlong param_1)

{
  longlong lVar1;
  
  if (*(char *)(param_1 + 0x1ca) == '\0') {
    lVar1 = *(longlong *)(param_1 + 0x178);
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x1d0);
  }
  return lVar1 == 0;
}



===== VmpIsPartition @ 140016090 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpIsPartition(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpIsPartition(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  long lVar1;
  
  if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
    lVar1 = 0;
  }
  else {
    lVar1 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x188) + 0x68))
                      (*(undefined8 *)(param_1 + 0x1d0));
  }
  return lVar1;
}



===== VmpReleaseRundown @ 1400160d0 =====

/* void __cdecl VmpReleaseRundown(class VM_VOLUME_EXTENSION * __ptr64) */

void __cdecl VmpReleaseRundown(VM_VOLUME_EXTENSION *param_1)

{
  KeReleaseMutex(param_1 + 0x50,0);
  return;
}



===== VmpPartitionChanged @ 140016100 =====

/* long __cdecl VmpPartitionChanged(class VM_ROOT_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpPartitionChanged(VM_ROOT_EXTENSION *param_1,_IRP *param_2)

{
  VM_ROOT_EXTENSION *pVVar1;
  longlong *plVar2;
  VM_ROOT_EXTENSION *pVVar3;
  uint *puVar4;
  undefined8 uVar5;
  uint uVar6;
  long lVar7;
  uint *puVar8;
  ulonglong uVar9;
  
  plVar2 = *(longlong **)(param_2 + 0x18);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 0x10) < 0x18) {
    return -0x3ffffff3;
  }
  VmpAcquireDevices(param_1);
  pVVar1 = param_1 + 0xd0;
  pVVar3 = *(VM_ROOT_EXTENSION **)pVVar1;
  do {
    if (pVVar3 == pVVar1) {
      lVar7 = -0x3ffffff3;
LAB_140016269:
      VmpReleaseDevices(param_1);
      return lVar7;
    }
    if (((pVVar3[0x9c] != (VM_ROOT_EXTENSION)0x0) && (pVVar3[0x1aa] == (VM_ROOT_EXTENSION)0x0)) &&
       (*(longlong *)(pVVar3 + 0x158) == *plVar2)) {
      puVar4 = (uint *)ExAllocatePool2(0x102,0x10);
      if (puVar4 == (uint *)0x0) {
        lVar7 = -0x3fffff66;
        goto LAB_140016269;
      }
      pVVar3 = *(VM_ROOT_EXTENSION **)pVVar1;
      *puVar4 = 0;
      break;
    }
    pVVar3 = *(VM_ROOT_EXTENSION **)pVVar3;
  } while( true );
LAB_1400161af:
  if (pVVar3 == pVVar1) {
    VmpReleaseDevices(param_1);
LAB_14001622a:
    if (*puVar4 != 0) {
      uVar9 = (ulonglong)*puVar4;
      puVar8 = puVar4;
      do {
        puVar8 = puVar8 + 2;
        ObfDereferenceObject(*(undefined8 *)puVar8);
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
    }
    ExFreePoolWithTag(puVar4,0);
    return 0;
  }
  if (((pVVar3[0x9c] != (VM_ROOT_EXTENSION)0x0) && (pVVar3[0x1aa] == (VM_ROOT_EXTENSION)0x0)) &&
     (*(longlong *)(pVVar3 + 0x158) == *plVar2)) {
    uVar5 = IoGetAttachedDeviceReference(*(undefined8 *)(pVVar3 + -0x20));
    *(undefined8 *)(puVar4 + 2) = uVar5;
    *puVar4 = 1;
    VmpReleaseDevices(param_1);
    uVar9 = 0;
    do {
      VmpSendDeviceControl(*(undefined8 *)(puVar4 + uVar9 * 2 + 2),0x560054,0,0,0,0);
      uVar6 = (int)uVar9 + 1;
      uVar9 = (ulonglong)uVar6;
    } while (uVar6 == 0);
    goto LAB_14001622a;
  }
  pVVar3 = *(VM_ROOT_EXTENSION **)pVVar3;
  goto LAB_1400161af;
}



===== VmpApplyHotplugProtection @ 1400162a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* long __cdecl VmpApplyHotplugProtection(class VM_VOLUME_EXTENSION * __ptr64) */

long __cdecl VmpApplyHotplugProtection(VM_VOLUME_EXTENSION *param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  longlong lVar8;
  undefined1 auStack_288 [32];
  undefined8 local_268;
  int local_258;
  int local_254;
  longlong local_250 [7];
  undefined4 local_218;
  undefined1 local_214 [278];
  char local_fe;
  code *local_f8;
  undefined4 local_f0 [2];
  wchar_t *local_e8;
  longlong *local_e0;
  undefined4 local_d8;
  undefined4 local_b8;
  wchar_t *local_b0;
  int *local_a8;
  undefined4 local_a0;
  undefined4 local_80;
  wchar_t *local_78;
  int *local_70;
  undefined4 local_68;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_288;
  lVar1 = *(longlong *)param_1;
  local_254 = 0;
  memset(local_f0,0,0xd8);
  local_250[0] = 0;
  local_258 = -1;
  local_250[5] = 0;
  local_250[1] = 0;
  local_250[2] = 0;
  local_250[3] = 0;
  local_250[4] = 0;
  memset(local_214,0,0x118);
  local_f0[0] = 0x100;
  local_f8 = VmpQueryHotplugProtectionQueryRoutine;
  local_d8 = 0x3000000;
  local_e8 = L"HotplugSecurityDescriptor";
  local_e0 = local_250;
  local_b8 = 0x120;
  local_a0 = 0x4000000;
  local_b0 = L"Deny_Execute";
  local_a8 = &local_254;
  local_80 = 0x120;
  local_78 = L"HotplugSecureOpen";
  local_70 = &local_258;
  local_68 = 0x4000000;
  local_268 = 0;
  iVar2 = RtlQueryRegistryValuesEx
                    (0,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Storage",&local_f8
                     ,0);
  iVar3 = 0;
  if (iVar2 != -0x3fffffcc) {
    iVar3 = iVar2;
  }
  if (-1 < iVar3) {
    if (local_254 == 1) {
      *(uint *)(lVar1 + 0x30) = *(uint *)(lVar1 + 0x30) | 0x800000;
    }
    if (local_250[0] == 0) {
      if (local_258 == 1) {
        *(uint *)(lVar1 + 0x34) = *(uint *)(lVar1 + 0x34) | 0x100;
      }
      local_218 = 0x11c;
      iVar3 = RtlGetVersion(&local_218);
      if (iVar3 < 0) {
        return iVar3;
      }
      if ((byte)(local_fe - 2U) < 2) {
        return iVar3;
      }
      iVar3 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x158));
      iVar2 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
      iVar4 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
      iVar5 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x100));
      iVar6 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0xc0));
      iVar3 = iVar3 + iVar2 + iVar4 + iVar5 + iVar6 + 0x44;
      lVar8 = ExAllocatePool2(0x102,iVar3,0x20204d56);
      if (lVar8 == 0) {
        lVar7 = -0x3fffff66;
      }
      else {
        lVar7 = RtlCreateAcl(lVar8,iVar3,2);
        if (((((-1 < lVar7) &&
              (lVar7 = RtlAddAccessAllowedAce
                                 (lVar8,2,0x20000000,
                                  *(undefined8 *)(*(longlong *)SeExports_exref + 0xc0)), -1 < lVar7)
              ) && (lVar7 = RtlAddAccessAllowedAce
                                      (lVar8,2,0x10000000,
                                       *(undefined8 *)(*(longlong *)SeExports_exref + 0x108)),
                   -1 < lVar7)) &&
            ((lVar7 = RtlAddAccessAllowedAce
                                (lVar8,2,0x10000000,
                                 *(undefined8 *)(*(longlong *)SeExports_exref + 0x110)), -1 < lVar7
             && (lVar7 = RtlAddAccessAllowedAce
                                   (lVar8,2,0x20000000,
                                    *(undefined8 *)(*(longlong *)SeExports_exref + 0x158)),
                -1 < lVar7)))) &&
           (lVar7 = RtlAddAccessAllowedAce
                              (lVar8,2,0xc0010000,
                               *(undefined8 *)(*(longlong *)SeExports_exref + 0x100)), -1 < lVar7))
        {
          lVar7 = RtlCreateSecurityDescriptor(local_250 + 1,1);
          if ((-1 < lVar7) &&
             (lVar7 = RtlSetDaclSecurityDescriptor(local_250 + 1,1,lVar8,0), -1 < lVar7)) {
            lVar7 = ObSetSecurityObjectByPointer(lVar1,4,local_250 + 1);
          }
        }
        ExFreePoolWithTag(lVar8,0);
      }
      return lVar7;
    }
    if (local_258 != 0) {
      *(uint *)(lVar1 + 0x34) = *(uint *)(lVar1 + 0x34) | 0x100;
    }
    iVar3 = ObSetSecurityObjectByPointer(lVar1,0xc,local_250[0]);
    ExFreePoolWithTag(local_250[0],0);
  }
  return iVar3;
}



===== VmpCreateBasicDevice @ 140016730 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* long __cdecl VmpCreateBasicDevice(struct _DEVICE_OBJECT * __ptr64,struct _DEVICE_OBJECT *
   __ptr64,struct _PARTITION_INFORMATION_EX * __ptr64,struct _DEVICE_OBJECT * __ptr64 * __ptr64) */

long __cdecl
VmpCreateBasicDevice
          (_DEVICE_OBJECT *param_1,_DEVICE_OBJECT *param_2,_PARTITION_INFORMATION_EX *param_3,
          _DEVICE_OBJECT **param_4)

{
  _DEVICE_OBJECT *p_Var1;
  longlong *plVar2;
  uchar uVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  ulonglong uVar8;
  uint uVar9;
  longlong *plVar10;
  uint uVar11;
  uint uVar12;
  __uint64 _Var13;
  byte bVar14;
  undefined8 uVar15;
  longlong *plVar16;
  ushort uVar17;
  byte bVar18;
  VM_ROOT_EXTENSION *pVVar19;
  undefined1 auStackY_2c8 [32];
  byte local_288;
  byte local_287;
  byte local_286;
  byte local_285;
  byte local_284;
  byte local_283;
  _PARTITION_INFORMATION_EX local_282;
  _PARTITION_INFORMATION_EX local_281;
  undefined1 local_280;
  _PARTITION_INFORMATION_EX local_27f;
  _PARTITION_INFORMATION_EX local_27e [6];
  _DEVICE_OBJECT *local_278;
  ulong local_270;
  undefined4 local_260;
  undefined4 local_25c;
  int local_258 [2];
  longlong local_250;
  longlong local_248;
  undefined4 local_240;
  undefined4 local_23c;
  undefined8 local_238;
  _DEVICE_OBJECT *local_230;
  longlong local_228;
  longlong local_220;
  _DEVICE_OBJECT **local_218;
  undefined8 local_210;
  undefined4 local_208;
  undefined4 local_200;
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  undefined4 uStack_1f4;
  undefined4 local_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined4 uStack_1e4;
  undefined4 local_1e0;
  undefined4 uStack_1dc;
  undefined4 local_1d8;
  undefined1 local_1d4;
  undefined2 local_1d3;
  undefined1 local_1d1;
  longlong local_1d0;
  undefined8 local_1c8;
  undefined4 local_1c0;
  undefined1 local_1bc;
  undefined2 local_1bb;
  undefined1 local_1b9;
  longlong local_1b8;
  undefined8 local_1b0;
  undefined8 local_1a8;
  __uint64 _Stack_1a0;
  undefined8 local_198;
  ulonglong uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  undefined *local_178;
  uint local_170;
  undefined4 local_16c;
  undefined *local_168;
  undefined4 local_160;
  undefined4 local_15c;
  longlong *local_158;
  undefined8 local_150;
  undefined4 *local_148;
  undefined8 local_140;
  undefined4 *local_138;
  undefined8 local_130;
  longlong *local_128;
  undefined8 local_120;
  longlong *local_118;
  undefined8 local_110;
  _PARTITION_INFORMATION_EX *local_108;
  undefined8 local_100;
  _PARTITION_INFORMATION_EX *local_f8;
  undefined8 local_f0;
  byte *local_e8;
  undefined8 local_e0;
  byte *local_d8;
  undefined8 local_d0;
  byte *local_c8;
  undefined8 local_c0;
  byte *local_b8;
  undefined8 local_b0;
  byte *local_a8;
  undefined8 local_a0;
  undefined4 *local_98;
  undefined8 local_90;
  byte *local_88;
  undefined8 local_80;
  _PARTITION_INFORMATION_EX *local_78;
  undefined8 local_70;
  _PARTITION_INFORMATION_EX *local_68;
  undefined8 local_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_2c8;
  local_1e0 = 0;
  uStack_1dc = 0;
  local_228 = *(longlong *)(param_1 + 0x40);
  *param_4 = (_DEVICE_OBJECT *)0x0;
  local_270 = *(uint *)(param_1 + 0x34) & 0x40001;
  local_278 = (_DEVICE_OBJECT *)0x0;
  local_198 = 0;
  uStack_190 = 0;
  local_280 = 0;
  local_188 = 0;
  uStack_180 = 0;
  local_200 = 0;
  uStack_1fc = 0;
  uStack_1f8 = 0;
  uStack_1f4 = 0;
  local_1f0 = 0;
  uStack_1ec = 0;
  uStack_1e8 = 0;
  uStack_1e4 = 0;
  local_230 = param_2;
  local_218 = param_4;
  lVar7 = IoGetAttachedDeviceReference(param_2);
  local_220 = lVar7;
  uVar8 = VmpSendDeviceControl(lVar7,0x70214,0,0,&local_198,0x20);
  ObfDereferenceObject(lVar7);
  pVVar19 = VmRootExtension;
  if ((int)uVar8 < 0) {
    return (int)uVar8;
  }
  if (*(longlong *)(VmRootExtension + 0x168) != 0) {
    if (*(int *)param_3 == 0) {
      local_258[0] = 0;
      uVar15 = IoGetAttachedDeviceReference(param_2);
      uVar8 = VmpSendDeviceControl(uVar15,0x704008,0,0,local_258,4);
      ObfDereferenceObject(uVar15);
      pVVar19 = VmRootExtension;
      if (-1 < (int)uVar8) {
        plVar10 = (longlong *)0x0;
        uVar11 = 0;
        uVar12 = *(uint *)(VmRootExtension + 0x160);
        plVar16 = *(longlong **)(VmRootExtension + 0x168);
        if (uVar12 != 0) {
          plVar2 = plVar16;
          do {
            plVar10 = plVar2;
            if ((((int)plVar10[3] == 0) && (*(int *)((longlong)plVar10 + 0x1c) == 0)) &&
               (local_258[0] == (int)*plVar10)) break;
            uVar11 = uVar11 + 1;
            plVar2 = plVar10 + 4;
          } while (uVar11 < uVar12);
        }
        if (uVar11 != uVar12) {
          local_1b8 = plVar10[2];
          local_1bb = 0;
          local_1b9 = 0;
          local_1c0 = 0x18;
          local_1bc = 1;
          local_1b0 = 0xffffffffffffffff;
          VmpSendDeviceControl(param_1,0x7c0ec,&local_1c0,0x18,0,0);
          uVar9 = uVar11 + 1;
          iVar5 = *(int *)(pVVar19 + 0x160) + -1;
          *(int *)(pVVar19 + 0x160) = iVar5;
          if (uVar9 == uVar12) goto LAB_1400168d1;
LAB_1400169fa:
          memcpy(plVar16 + (ulonglong)uVar11 * 4,plVar16 + (ulonglong)uVar9 * 4,
                 (ulonglong)((uVar12 - uVar11) - 1) << 5);
        }
      }
    }
    else if (*(int *)param_3 == 1) {
      uVar12 = *(uint *)(VmRootExtension + 0x160);
      plVar10 = (longlong *)0x0;
      plVar16 = *(longlong **)(VmRootExtension + 0x168);
      uVar11 = 0;
      if (uVar12 != 0) {
        plVar2 = plVar16;
        do {
          plVar10 = plVar2;
          if (((*(int *)((longlong)plVar10 + 0x1c) != 0) &&
              (*(longlong *)(param_3 + 0x30) == *plVar10)) &&
             (*(longlong *)(param_3 + 0x38) == plVar10[1])) break;
          uVar11 = uVar11 + 1;
          plVar2 = plVar10 + 4;
        } while (uVar11 < uVar12);
      }
      if (uVar11 != uVar12) {
        local_1d0 = plVar10[2];
        local_1d3 = 0;
        local_1d1 = 0;
        local_1d8 = 0x18;
        local_1d4 = 1;
        local_1c8 = 0xffffffffffffffff;
        VmpSendDeviceControl(param_1,0x7c0ec,&local_1d8,0x18,0,0);
        uVar9 = uVar11 + 1;
        iVar5 = *(int *)(pVVar19 + 0x160) + -1;
        *(int *)(pVVar19 + 0x160) = iVar5;
        if (uVar9 != uVar12) goto LAB_1400169fa;
LAB_1400168d1:
        if (iVar5 == 0) {
          ExFreePoolWithTag(*(undefined8 *)(pVVar19 + 0x168),0);
          *(undefined8 *)(pVVar19 + 0x168) = 0;
        }
      }
    }
  }
  _Var13 = 0;
  iVar5 = *(int *)param_3;
  bVar14 = (byte)uStack_190;
  uVar8 = uStack_190;
  uVar3 = SC_PART_ENTRY::IsRecognized((SC_PART_ENTRY *)param_3);
  if (uVar3 == '\0') {
    if (((iVar5 == 1) && (*(longlong *)(param_3 + 0x20) == 0x11d2f81fc12a7328)) &&
       (*(longlong *)(param_3 + 0x28) == 0x3bc93ec9a0004bba)) {
      bVar18 = 0;
    }
    else {
      uVar8 = uStack_190;
      bVar18 = 1;
      if ((*(uint *)(local_228 + 0x28) & 0x200) != 0) {
        bVar18 = 0;
      }
    }
  }
  else if (iVar5 == 1) {
    _Var13 = *(__uint64 *)(param_3 + 0x40);
    bVar18 = (byte)(*(__uint64 *)(param_3 + 0x40) >> 0x3e) & 1;
  }
  else {
    local_1a8 = 0;
    _Stack_1a0 = 0;
    uVar8 = VmpSendDeviceControl(param_1,0x700e8,0,0,&local_1a8,0x10);
    if ((int)uVar8 < 0) {
      return (int)uVar8;
    }
    _Var13 = _Stack_1a0;
    uVar8 = uStack_190;
    bVar18 = (byte)(_Stack_1a0 >> 0x3e) & 1;
  }
  if (((uVar8 & 2) != 0) && ((uVar8 & 4) == 0)) {
    bVar18 = 1;
  }
  iVar5 = VmpCreateDeviceObject(local_270,_Var13,bVar18,&local_278);
  p_Var1 = local_278;
  if (iVar5 < 0) goto LAB_1400172cc;
  plVar16 = *(longlong **)(local_278 + 0x40);
  VmpGetInstancePath(local_230,(ushort **)(plVar16 + 0x33));
  *(_PARTITION_INFORMATION_EX *)((longlong)plVar16 + 0xb9) = param_3[0x1d];
  plVar16[0x32] = local_220;
  plVar16[0x31] = (longlong)local_230;
  plVar16[0x2f] = (longlong)param_1;
  *(byte *)((longlong)plVar16 + 0xbb) = bVar14 & 1;
  lVar7 = *(longlong *)(local_228 + 0x48);
  plVar16[0x37] = *(longlong *)(local_228 + 0x40);
  plVar16[0x38] = lVar7;
  p_Var1[0x4c] = (_DEVICE_OBJECT)((char)param_1[0x4c] + '\x01');
  *(undefined4 *)(p_Var1 + 0x98) = *(undefined4 *)(plVar16[0x2f] + 0x98);
  uVar17 = 0x200;
  if (0x200 < *(ushort *)(plVar16[0x2f] + 0x130)) {
    uVar17 = *(ushort *)(plVar16[0x2f] + 0x130);
  }
  *(ushort *)(p_Var1 + 0x130) = uVar17;
  uVar12 = 0x2000;
  if ((*(uint *)(plVar16[0x32] + 0x30) & 0x4000) != 0) {
    uVar12 = 0x4000;
  }
  *(uint *)(local_278 + 0x30) =
       *(uint *)(local_278 + 0x30) | *(uint *)(plVar16[0x2f] + 0x30) & 0x600100 | uVar12;
  if (((*(uint *)(*plVar16 + 0x30) & 0x600100) != 0) || (*(int *)((longlong)plVar16 + 0xb4) != 0)) {
    *(undefined1 *)(plVar16 + 0x18) = 0;
  }
  lVar7 = plVar16[0x2f];
  local_210 = 0;
  local_208 = 0;
  uVar15 = 0;
  uVar8 = VmpSendDeviceControl(lVar7,0x2d1084,0,0,&local_200,0x28);
  iVar5 = (int)uVar8;
  if (iVar5 < 0) {
    uVar15 = 0;
    uVar8 = VmpSendDeviceControl(lVar7,0x2d1080,0,0,&local_210,0xc);
    iVar5 = (int)uVar8;
    if (iVar5 < 0) goto LAB_140016c99;
    uStack_1f4 = (undefined4)local_210;
    uStack_1dc = local_208;
    uStack_1fc = 0x28;
    uStack_1f8 = 0;
    uStack_1ec = 0;
    uStack_1e8 = 0;
    uStack_1e4 = 0;
    local_1e0 = 0;
    local_200 = 0x28;
    local_1f0 = local_210._4_4_;
  }
  else {
LAB_140016c99:
    if (iVar5 < 0) goto LAB_1400172cc;
  }
  *(undefined4 *)(plVar16 + 0x34) = local_1f0;
  *(undefined4 *)((longlong)plVar16 + 0x1a4) = uStack_1dc;
  plVar16[0x35] = *(longlong *)(param_3 + 8);
  plVar16[0x36] = *(longlong *)(param_3 + 0x10);
  if (*(int *)param_3 == 1) {
    *(undefined1 *)(plVar16 + 0x39) = 1;
    lVar7 = *(longlong *)(param_3 + 0x20) + -0x11d2f81fc12a7328;
    if (lVar7 == 0) {
      lVar7 = *(longlong *)(param_3 + 0x28) + -0x3bc93ec9a0004bba;
    }
    uVar4 = lVar7 == 0;
LAB_140016d3f:
    *(undefined1 *)((longlong)plVar16 + 0x1c9) = uVar4;
  }
  else if (((*(uint *)(plVar16[0x2f] + 0x30) >> 0x15 & 1) != 0) &&
          ((param_3[0x20] == (_PARTITION_INFORMATION_EX)0xb ||
           (param_3[0x20] == (_PARTITION_INFORMATION_EX)0xc)))) {
    iVar6 = RtlCheckPortableOperatingSystem(&local_280);
    iVar5 = 0;
    if (iVar6 != -0x3ffffddb) {
      iVar5 = iVar6;
    }
    if (iVar5 < 0) {
LAB_1400172cc:
      if (local_278 == (_DEVICE_OBJECT *)0x0) {
        return iVar5;
      }
      IoDeleteDevice();
      return iVar5;
    }
    uVar4 = local_280;
    goto LAB_140016d3f;
  }
  uVar8 = (ulonglong)(*(uint *)(local_278 + 0x30) & 0xffffff7f);
  *(uint *)(local_278 + 0x30) = *(uint *)(local_278 + 0x30) & 0xffffff7f;
  if (*(int *)param_3 == 0) {
    if (((DAT_14000b048 < 6) || (uVar15 = 0x400000000000, (_DAT_14000b058 & 0x400000000000) == 0))
       || ((DAT_14000b060 & 0x400000000000) != DAT_14000b060)) goto LAB_140017285;
    local_281 = param_3[0x20];
    local_282 = param_3[0x21];
    local_283 = *(byte *)((longlong)plVar16 + 0x1c9);
    bVar14 = (byte)((ulonglong)plVar16[0x2b] >> 0x38);
    local_284 = bVar14 >> 5 & 1;
    local_285 = bVar14 >> 4 & 1;
    local_286 = *(byte *)((longlong)plVar16 + 0xb9);
    local_288 = (byte)(*(uint *)(local_278 + 0x30) >> 0x16) & 1;
    local_27f = (_PARTITION_INFORMATION_EX)((byte)(*(uint *)(local_278 + 0x30) >> 0x15) & 1);
    local_248 = plVar16[0x36];
    local_250 = plVar16[0x35];
    local_260 = *(undefined4 *)((longlong)plVar16 + 0x1a4);
    local_68 = &local_281;
    local_78 = &local_282;
    local_88 = &local_283;
    local_27e[0] = (_PARTITION_INFORMATION_EX)
                   ((byte)((uint)*(undefined4 *)(local_278 + 0x30) >> 8) & 1);
    local_98 = &local_25c;
    local_a8 = &local_284;
    local_60 = 1;
    local_b8 = &local_285;
    local_c8 = &local_286;
    local_d8 = &local_287;
    local_e8 = &local_288;
    local_f8 = &local_27f;
    local_108 = local_27e;
    local_118 = &local_248;
    local_128 = &local_250;
    local_138 = &local_260;
    local_70 = 1;
    uVar17 = *(ushort *)PTR_DAT_14000b050;
    local_168 = &DAT_1400090d4;
    local_160 = 0xef;
    local_25c = 0;
    local_287 = bVar18;
  }
  else {
    if (((*(int *)param_3 != 1) || (DAT_14000b048 < 6)) ||
       ((uVar15 = 0x400000000000, (_DAT_14000b058 & 0x400000000000) == 0 ||
        ((DAT_14000b060 & 0x400000000000) != DAT_14000b060)))) goto LAB_140017285;
    local_288 = *(byte *)((longlong)plVar16 + 0x1c9);
    local_78 = param_3 + 0x20;
    bVar14 = (byte)((ulonglong)plVar16[0x2b] >> 0x38);
    local_286 = bVar14 >> 4 & 1;
    local_285 = *(byte *)((longlong)plVar16 + 0xb9);
    local_283 = (byte)(*(uint *)(local_278 + 0x30) >> 0x16) & 1;
    local_282 = (_PARTITION_INFORMATION_EX)((byte)(*(uint *)(local_278 + 0x30) >> 0x15) & 1);
    local_250 = plVar16[0x36];
    local_248 = plVar16[0x35];
    local_25c = *(undefined4 *)((longlong)plVar16 + 0x1a4);
    local_88 = &local_288;
    local_98 = &local_260;
    local_a8 = &local_287;
    local_b8 = &local_286;
    local_c8 = &local_285;
    local_281 = (_PARTITION_INFORMATION_EX)
                ((byte)((uint)*(undefined4 *)(local_278 + 0x30) >> 8) & 1);
    local_d8 = &local_284;
    local_e8 = &local_283;
    local_f8 = &local_282;
    local_108 = &local_281;
    local_118 = &local_250;
    local_128 = &local_248;
    local_138 = &local_25c;
    local_70 = 0x10;
    uVar17 = *(ushort *)PTR_DAT_14000b050;
    local_168 = &DAT_140008fdc;
    local_160 = 0xec;
    local_260 = 1;
    local_287 = bVar14 >> 5 & 1;
    local_284 = bVar18;
  }
  local_15c = 1;
  local_170 = (uint)uVar17;
  local_80 = 1;
  local_90 = 4;
  local_a0 = 1;
  local_b0 = 1;
  local_c0 = 1;
  local_d0 = 1;
  local_e0 = 1;
  local_f0 = 1;
  local_100 = 1;
  local_110 = 8;
  local_120 = 8;
  local_130 = 4;
  local_140 = 0x10;
  local_148 = &uStack_1ec;
  local_150 = 0x10;
  local_16c = 2;
  local_178 = PTR_DAT_14000b050;
  local_238 = 0x400000000000;
  local_23c = 5;
  local_240 = 0xb000000;
  local_270 = 0x2bf;
  uVar15 = 0;
  uVar8 = DAT_14000b068;
  local_158 = plVar16 + 0x37;
  EtwWriteTransfer(DAT_14000b068,&local_240,0,0);
LAB_140017285:
  *local_218 = local_278;
  if ((Microsoft_Windows_StorageVolumeEnableBits & 1) != 0) {
    McTemplateK0qzqx_EtwWriteTransfer
              (uVar8,&VolumeArrived,uVar15,*(undefined4 *)((longlong)plVar16 + 0xc4),
               (wchar_t *)plVar16[0x33],(char)plVar16[0x34],(char)plVar16[0x35]);
  }
  return iVar5;
}



===== VmpGetGptAttributes @ 140017310 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpGetGptAttributes(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpGetGptAttributes(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  ulonglong *puVar1;
  longlong lVar2;
  uchar uVar3;
  int iVar4;
  ulonglong uVar5;
  undefined1 auStackY_f8 [32];
  undefined8 local_c8;
  ulonglong uStack_c0;
  int local_b8 [8];
  longlong local_98;
  longlong lStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_f8;
  puVar1 = *(ulonglong **)(param_2 + 0x18);
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 8) {
    return -0x3ffffff3;
  }
  if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
    lVar2 = *(longlong *)(param_1 + 0x178);
  }
  else {
    lVar2 = *(longlong *)(param_1 + 0x1d0);
  }
  if (lVar2 == 0) {
    return -0x3ffffff2;
  }
  iVar4 = 0;
  local_b8[0] = 0;
  local_b8[1] = 0;
  local_b8[2] = 0;
  local_b8[3] = 0;
  local_b8[4] = 0;
  local_b8[5] = 0;
  local_b8[6] = 0;
  local_b8[7] = 0;
  local_98 = 0;
  lStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (param_1[0x1ca] != (VM_VOLUME_EXTENSION)0x0) {
    uStack_c0 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x188) + 0x98))
                          (*(undefined8 *)(param_1 + 0x1d0));
    goto LAB_1400174fd;
  }
  uVar5 = VmpSendDeviceControl(*(undefined8 *)(param_1 + 0x178),0x70048,0,0,local_b8,0x90);
  iVar4 = (int)uVar5;
  uStack_c0 = 0;
  if (-1 < iVar4) {
    uVar3 = SC_PART_ENTRY::IsRecognized((SC_PART_ENTRY *)local_b8);
    if (uVar3 == '\0') {
      return -0x3ffffff3;
    }
    local_c8 = 0;
    uStack_c0 = 0;
    uVar5 = VmpSendDeviceControl(*(undefined8 *)(param_1 + 0x178),0x700e8,0,0,&local_c8,0x10);
    iVar4 = (int)uVar5;
    if (iVar4 < 0) {
      return iVar4;
    }
    if (local_b8[0] != 0) {
      if (local_b8[0] != 1) {
        return -0x3fffffff;
      }
      if (((local_98 == 0x4d4006d1de94bba4) && (lStack_90 == -0x532986fe2a40955f)) &&
         (*(char *)(*(longlong *)(param_1 + 8) + 0x11c) == '\0')) {
        uStack_c0 = uStack_c0 | 0x8000000000000000;
      }
      goto LAB_1400174fd;
    }
    if (((char)local_98 == '\'') && (*(char *)(*(longlong *)(param_1 + 8) + 0x11c) == '\0')) {
      uStack_c0 = uStack_c0 | 0x8000000000000000;
      goto LAB_1400174fd;
    }
  }
  if (iVar4 < 0) {
    return iVar4;
  }
LAB_1400174fd:
  if ((*(uint *)(*(longlong *)param_1 + 0x30) >> 8 & 1) != 0) {
    uStack_c0 = uStack_c0 & 0x7fffffffffffffff;
  }
  *puVar1 = uStack_c0;
  *(undefined8 *)(param_2 + 0x38) = 8;
  return iVar4;
}



===== VmpGetLengthInfo @ 140017560 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpGetLengthInfo(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpGetLengthInfo(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  uint uVar1;
  longlong lVar2;
  VM_ROOT_EXTENSION *pVVar3;
  undefined8 *puVar4;
  longlong lVar5;
  bool bVar6;
  int iVar7;
  long lVar8;
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
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  pVVar3 = *(VM_ROOT_EXTENSION **)(param_1 + 8);
  local_a8 = 0;
  uStack_a0 = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (*(uint *)(lVar2 + 8) < 8) {
    iVar7 = -0x3fffffdd;
  }
  else {
    iVar7 = VmpAllSystemsGo(param_1,param_2,'\x01','\x01','\0');
    if (-1 < iVar7) {
      if (iVar7 == 0x103) {
        return 0x103;
      }
      if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
        if (((*(byte *)(lVar2 + 2) & 2) == 0) || ((*(uint *)(*(longlong *)param_1 + 0x34) & 1) == 0)
           ) {
          puVar4 = *(undefined8 **)(param_2 + 0xb8);
          puVar4[-9] = *puVar4;
          puVar4[-8] = puVar4[1];
          puVar4[-7] = puVar4[2];
          puVar4[-6] = puVar4[3];
          *(undefined4 *)(puVar4 + -5) = *(undefined4 *)(puVar4 + 4);
          *(undefined4 *)((longlong)puVar4 + -0x24) = *(undefined4 *)((longlong)puVar4 + 0x24);
          *(undefined4 *)(puVar4 + -4) = *(undefined4 *)(puVar4 + 5);
          *(undefined4 *)((longlong)puVar4 + -0x1c) = *(undefined4 *)((longlong)puVar4 + 0x2c);
          puVar4[-3] = puVar4[6];
          *(undefined1 *)((longlong)puVar4 + -0x45) = 0;
          lVar5 = *(longlong *)(param_2 + 0xb8);
          uVar1 = *(uint *)(lVar2 + 0x18);
          *(code **)(lVar5 + -0x10) = VmpRefCountCompletionRoutine;
          *(ulonglong *)(lVar5 + -8) = (ulonglong)uVar1;
          *(undefined1 *)(lVar5 + -0x45) = 0xe0;
          lVar8 = IofCallDriver(*(undefined8 *)(param_1 + 0x178),param_2);
          return lVar8;
        }
        puVar4 = *(undefined8 **)(param_2 + 0x18);
        *(undefined8 **)(param_2 + 0x18) = &local_a8;
        *(undefined4 *)(lVar2 + 0x18) = 0x70048;
        *(undefined4 *)(lVar2 + 8) = 0x90;
        IoForwardIrpSynchronously(*(undefined8 *)(param_1 + 0x178),param_2);
        iVar7 = *(int *)(param_2 + 0x30);
        *(undefined8 **)(param_2 + 0x18) = puVar4;
        VmpDecrementRefCount(param_1);
        if (-1 < iVar7) {
          VmpAcquireDevices(pVVar3);
          bVar6 = VmpIsVolumeDead((longlong)param_1);
          if (!bVar6) {
            VmpSetPartitionInformation(param_1,(_PARTITION_INFORMATION_EX *)&local_a8);
          }
          VmpReleaseDevices(pVVar3);
          *puVar4 = local_98;
          *(undefined8 *)(param_2 + 0x38) = 8;
        }
      }
      else {
        iVar7 = (**(code **)(*(longlong *)(pVVar3 + 0x188) + 0x68))
                          (*(undefined8 *)(param_1 + 0x1d0),param_2);
        VmpDecrementRefCount(param_1);
      }
    }
  }
  *(int *)(param_2 + 0x30) = iVar7;
  IofCompleteRequest(param_2,0);
  return iVar7;
}



===== VmpGetPartitionInfoEx @ 140017760 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpGetPartitionInfoEx(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpGetPartitionInfoEx(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  longlong lVar1;
  VM_ROOT_EXTENSION *pVVar2;
  _PARTITION_INFORMATION_EX *p_Var3;
  bool bVar4;
  int iVar5;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  pVVar2 = *(VM_ROOT_EXTENSION **)(param_1 + 8);
  iVar5 = VmpAllSystemsGo(param_1,param_2,'\x01','\x01','\0');
  if (-1 < iVar5) {
    if (iVar5 == 0x103) {
      return 0x103;
    }
    if (param_1[0x1ca] == (VM_VOLUME_EXTENSION)0x0) {
      IoForwardIrpSynchronously(*(undefined8 *)(param_1 + 0x178),param_2);
      iVar5 = *(int *)(param_2 + 0x30);
      VmpDecrementRefCount(param_1);
      if (((-1 < iVar5) && ((*(byte *)(lVar1 + 2) & 2) != 0)) &&
         ((*(uint *)(*(longlong *)param_1 + 0x34) & 1) != 0)) {
        p_Var3 = *(_PARTITION_INFORMATION_EX **)(param_2 + 0x18);
        VmpAcquireDevices(pVVar2);
        bVar4 = VmpIsVolumeDead((longlong)param_1);
        if (!bVar4) {
          VmpSetPartitionInformation(param_1,p_Var3);
        }
        VmpReleaseDevices(pVVar2);
      }
    }
    else {
      iVar5 = (**(code **)(*(longlong *)(pVVar2 + 0x188) + 0x68))(*(undefined8 *)(param_1 + 0x1d0));
      VmpDecrementRefCount(param_1);
    }
  }
  *(int *)(param_2 + 0x30) = iVar5;
  IofCompleteRequest(param_2,0);
  return iVar5;
}



===== VmpPerformance @ 140017880 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpPerformance(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpPerformance(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  int iVar1;
  ulonglong uVar2;
  
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x58) {
    return -0x3ffffff3;
  }
  uVar2 = Feature_RacyAccessesInVolmgrAreCountersEnabled__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar2 == 0) {
    if ((param_1[0xc1] == SUB81(uVar2,0)) &&
       (iVar1 = VmpQueryEnableCountersAlways(*(longlong *)param_1), iVar1 < 0)) {
      return iVar1;
    }
  }
  else if ((param_1[0xc1] == (VM_VOLUME_EXTENSION)0x0) &&
          (iVar1 = VmpQueryEnableCountersAlways(*(longlong *)param_1), iVar1 < 0)) {
    return iVar1;
  }
  (**(code **)(*(longlong *)(param_1 + 8) + 0x150))
            (*(undefined8 *)(param_1 + 0x100),*(undefined8 *)(param_2 + 0x18),L"VOLMGR  ",
             *(undefined4 *)(param_1 + 0xc4));
  *(undefined8 *)(param_2 + 0x38) = 0x58;
  return 0;
}



===== VmpQueryStableGuid @ 140017940 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* long __cdecl VmpQueryStableGuid(class VM_VOLUME_EXTENSION * __ptr64,struct _IRP * __ptr64) */

long __cdecl VmpQueryStableGuid(VM_VOLUME_EXTENSION *param_1,_IRP *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (param_1[0x1ca] != (VM_VOLUME_EXTENSION)0x0) {
    lVar3 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 8) + 0x188) + 0x68))
                      (*(undefined8 *)(param_1 + 0x1d0));
    return lVar3;
  }
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x10) {
    return -0x3ffffff3;
  }
  if ((*(uint *)(*(longlong *)(*(longlong *)(param_1 + 0x178) + 0x40) + 0x28) >> 9 & 1) == 0) {
    puVar1 = *(undefined8 **)(param_2 + 0x18);
    uVar2 = *(undefined8 *)(param_1 + 0x1c0);
    *puVar1 = *(undefined8 *)(param_1 + 0x1b8);
    puVar1[1] = uVar2;
    *(undefined8 *)(param_2 + 0x38) = 0x10;
    return 0;
  }
  return -0x3fffffff;
}



===== VmpSetPartitionInformation @ 1400179d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* void __cdecl VmpSetPartitionInformation(class VM_VOLUME_EXTENSION * __ptr64,struct
   _PARTITION_INFORMATION_EX * __ptr64) */

void __cdecl
VmpSetPartitionInformation(VM_VOLUME_EXTENSION *param_1,_PARTITION_INFORMATION_EX *param_2)

{
  int iVar1;
  bool bVar2;
  long lVar3;
  longlong lVar4;
  ulonglong uVar5;
  char cVar6;
  undefined1 auStack_f8 [32];
  ulonglong local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  ulonglong local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  longlong lStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  ushort local_68;
  uchar local_66 [54];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_f8;
  iVar1 = *(int *)param_2;
  if (param_1[0x1c8] == (VM_VOLUME_EXTENSION)(iVar1 == 1)) {
    lVar4 = *(longlong *)(param_2 + 8);
    bVar2 = false;
    if ((*(longlong *)(param_1 + 0x1a8) == lVar4) && (*(longlong *)(param_1 + 0x1b0) == lVar4)) {
      return;
    }
  }
  else {
    bVar2 = true;
  }
  cVar6 = '\0';
  if (iVar1 == 1) {
    lVar4 = *(longlong *)(param_2 + 0x20) + -0x11d2f81fc12a7328;
    if (lVar4 == 0) {
      lVar4 = *(longlong *)(param_2 + 0x28) + -0x3bc93ec9a0004bba;
    }
    cVar6 = '\0';
    if (lVar4 == 0) {
      cVar6 = '\x01';
    }
  }
  local_78 = 0;
  local_d8 = (ulonglong)(byte)param_1[0x1ca];
  uStack_d0 = *(undefined8 *)(param_1 + 0x178);
  local_c8 = *(undefined8 *)(param_1 + 0x188);
  uStack_c0 = *(undefined8 *)(param_1 + 400);
  uStack_b0 = 0;
  local_b8 = (ulonglong)*(uint *)(param_1 + 0x1a0);
  local_a8 = 0;
  lStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  uVar5 = Feature_Servicing_VolmgrHighIrqlPagedMemoryAccess__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar5 != 0) {
    uStack_b0 = *(undefined8 *)(param_1 + 0x198);
  }
  uStack_90 = *(undefined8 *)(param_1 + 0x1b8);
  local_88 = *(undefined8 *)(param_1 + 0x1c0);
  local_a8 = CONCAT44(local_a8._4_4_,*(undefined4 *)(param_1 + 0x1a4));
  lStack_a0 = *(longlong *)(param_2 + 8);
  local_98 = *(undefined8 *)(param_2 + 0x10);
  local_78 = *(undefined8 *)(param_1 + 0x1d0);
  uStack_80._0_2_ = CONCAT11(cVar6,iVar1 == 1);
  VmpZeroRefCallback(param_1,VmpSetTargetCallback,&local_d8);
  if (bVar2) {
    if (cVar6 != '\0') {
      VmpApplyEspProtection(param_1);
    }
    local_68 = 0x30;
    lVar3 = VmpQueryUniqueIdInternal(param_1,&local_68,local_66);
    if (-1 < lVar3) {
      VmpNotify(param_1,(_GUID *)&GUID_IO_VOLUME_UNIQUE_ID_CHANGE,local_68 + 2,&local_68);
    }
  }
  return;
}



===== VmPnp @ 140017ba0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong VmPnp(longlong param_1,_IRP *param_2)

{
  uint *puVar1;
  byte *pbVar2;
  VM_ROOT_EXTENSION *pVVar3;
  VM_ROOT_EXTENSION *pVVar4;
  longlong lVar5;
  undefined8 uVar6;
  VM_ROOT_EXTENSION *pVVar7;
  undefined8 *puVar8;
  code *pcVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  void *pvVar12;
  int iVar13;
  size_t sVar14;
  undefined1 *puVar15;
  uint uVar16;
  wchar_t *pwVar17;
  undefined1 auStack_108 [8];
  undefined1 auStack_100 [24];
  int *local_c0;
  undefined4 local_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined8 local_98;
  void *pvStack_90;
  undefined8 local_88;
  void *pvStack_80;
  longlong local_78;
  longlong lStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  puVar15 = auStack_108;
  local_48 = __security_cookie ^ (ulonglong)auStack_108;
  pVVar4 = *(VM_ROOT_EXTENSION **)(param_1 + 0x40);
  lVar5 = *(longlong *)(param_2 + 0xb8);
  local_c0 = (int *)0x0;
  if (*(int *)(pVVar4 + 0x10) == 0) {
    uVar6 = *(undefined8 *)(pVVar4 + 0x28);
    switch(*(undefined1 *)(lVar5 + 1)) {
    case 0:
    case 3:
    case 6:
    case 10:
    case 0xb:
      *(undefined4 *)(param_2 + 0x30) = 0;
      break;
    case 1:
    case 0x16:
      goto switchD_140017c0b_caseD_1;
    case 2:
      VmpRemoveDevice(param_1,'\x01');
      puVar15 = auStack_108;
      goto LAB_140017dcc;
    case 7:
      if (*(int *)(lVar5 + 8) == 0) {
        VmpAcquireDevices(pVVar4);
        pVVar3 = pVVar4 + 0xd0;
        iVar13 = 0;
        for (pVVar7 = *(VM_ROOT_EXTENSION **)pVVar3; pVVar7 != pVVar3;
            pVVar7 = *(VM_ROOT_EXTENSION **)pVVar7) {
          iVar13 = iVar13 + 1;
        }
        local_c0 = (int *)ExAllocatePool2(0x102,iVar13 * 8 + 8,0x20204d56);
        puVar15 = auStack_108;
        if (local_c0 == (int *)0x0) {
          VmpReleaseDevices(pVVar4);
          uVar11 = 0xc000009a;
          *(undefined8 *)(param_2 + 0x38) = 0;
          goto LAB_1400187a4;
        }
        *local_c0 = iVar13;
        uVar16 = 0;
        for (pVVar7 = *(VM_ROOT_EXTENSION **)pVVar3; pVVar7 != pVVar3;
            pVVar7 = *(VM_ROOT_EXTENSION **)pVVar7) {
          uVar11 = (ulonglong)uVar16;
          uVar16 = uVar16 + 1;
          *(undefined8 *)(local_c0 + uVar11 * 2 + 2) = *(undefined8 *)(pVVar7 + -0x20);
          ObfReferenceObject(*(undefined8 *)(pVVar7 + -0x20));
          pVVar7[0x9e] = (VM_ROOT_EXTENSION)0x1;
        }
        pVVar3 = pVVar4 + 0xe0;
        while (pVVar7 = *(VM_ROOT_EXTENSION **)pVVar3, pVVar7 != pVVar3) {
          if ((*(VM_ROOT_EXTENSION **)(pVVar7 + 8) != pVVar3) ||
             (lVar5 = *(longlong *)pVVar7, *(VM_ROOT_EXTENSION **)(lVar5 + 8) != pVVar7)) {
            pcVar9 = (code *)swi(0x29);
            (*pcVar9)(3);
            puVar15 = auStack_100;
            break;
          }
          *(longlong *)pVVar3 = lVar5;
          *(VM_ROOT_EXTENSION **)(lVar5 + 8) = pVVar3;
          if (pVVar7[0x9f] != (VM_ROOT_EXTENSION)0x0) {
            local_b0 = 0;
            iVar13 = IoOpenDeviceRegistryKey(*(undefined8 *)(pVVar7 + -0x20),1,0x2001f,&local_b0);
            if (-1 < iVar13) {
              RtlWriteRegistryValue(0x40000000,local_b0,L"IsDeleted",4);
            }
            if (local_b0 != 0) {
              ZwClose();
            }
          }
          pVVar7[0x9e] = (VM_ROOT_EXTENSION)0x0;
        }
        *(undefined8 *)(puVar15 + -8) = 0x140017dc4;
        VmpReleaseDevices(pVVar4);
        *(int **)(param_2 + 0x38) = local_c0;
        goto LAB_140017dcc;
      }
      break;
    case 9:
      IoForwardIrpSynchronously(uVar6);
      puVar1 = (uint *)(*(longlong *)(lVar5 + 8) + 4);
      *puVar1 = *puVar1 | 0xc0;
      uVar11 = (ulonglong)*(uint *)(param_2 + 0x30);
      goto LAB_140018787;
    case 0x13:
      iVar13 = *(int *)(lVar5 + 8);
      if ((iVar13 == 0) || (iVar13 == 1)) {
        pwVar17 = L"ROOT\\VOLMGR";
        sVar14 = 0x18;
LAB_140017e1b:
        pvVar12 = (void *)ExAllocatePool2(0x102,sVar14 + 2,0x20204d56);
        if (pvVar12 == (void *)0x0) {
LAB_140017e42:
          uVar11 = 0xc000009a;
          goto LAB_1400187a4;
        }
        memcpy(pvVar12,pwVar17,sVar14);
        puVar15 = auStack_108;
        *(void **)(param_2 + 0x38) = pvVar12;
        *(undefined4 *)(param_2 + 0x30) = 0;
        *(undefined2 *)((longlong)pvVar12 + sVar14) = 0;
      }
      else if (iVar13 == 3) {
        pwVar17 = L"0000";
        sVar14 = 10;
        goto LAB_140017e1b;
      }
      goto LAB_140017dd0;
    case 0x14:
      IoForwardIrpSynchronously(uVar6);
      uVar11 = 0;
      *(undefined8 *)(param_2 + 0x38) = 0x22;
      goto LAB_140018787;
    case 0x17:
      VmpRemoveDevice(param_1,'\0');
      puVar15 = auStack_108;
LAB_140017dcc:
      *(undefined4 *)(param_2 + 0x30) = 0;
LAB_140017dd0:
      param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      *(undefined8 *)(puVar15 + -8) = 0x140017de8;
      uVar11 = IofCallDriver(uVar6,param_2);
      goto LAB_1400187b9;
    }
    param_2[0x43] = (_IRP)((char)param_2[0x43] + '\x01');
    *(longlong *)(param_2 + 0xb8) = lVar5 + 0x48;
    uVar11 = IofCallDriver(uVar6);
    puVar15 = auStack_108;
    goto LAB_1400187b9;
  }
  if (*(int *)(pVVar4 + 0x10) != 1) {
    *(undefined8 *)(param_2 + 0x38) = 0;
switchD_140017c0b_caseD_1:
    uVar11 = 0xc0000010;
    goto LAB_1400187a4;
  }
  switch(*(undefined1 *)(lVar5 + 1)) {
  case 0:
    uVar16 = VmpStartDevice((VM_VOLUME_EXTENSION *)pVVar4);
    uVar11 = (ulonglong)uVar16;
    break;
  case 1:
    uVar11 = (ulonglong)(-(uint)((*(uint *)(*(longlong *)pVVar4 + 0x30) & 0x100) != 0) & 0xc0000010)
    ;
    break;
  case 2:
  case 0x17:
    pVVar3 = *(VM_ROOT_EXTENSION **)(pVVar4 + 8);
    VmpAcquireDevices(pVVar3);
    VmpRemove((VM_VOLUME_EXTENSION *)pVVar4);
    if ((*(char *)(lVar5 + 1) == '\x02') &&
       (VmpZeroRefCallback((VM_VOLUME_EXTENSION *)pVVar4,VmpNoOpCallback,(void *)0x0),
       pVVar4[0xbe] == (VM_ROOT_EXTENSION)0x0)) {
      VmpReleaseDevices(pVVar3);
      VmpCleanupVolumeExtension((VM_VOLUME_EXTENSION *)pVVar4);
      IoDeleteDevice(*(undefined8 *)pVVar4);
      uVar11 = 0;
    }
    else {
      VmpReleaseDevices(pVVar3);
      uVar11 = 0;
    }
    goto LAB_1400187a4;
  case 3:
  case 6:
  case 10:
    goto switchD_140017ef4_caseD_3;
  default:
switchD_140017ef4_caseD_4:
    uVar11 = 0xc00000bb;
    break;
  case 5:
    uVar11 = 0xc0000001;
    goto LAB_1400187a4;
  case 7:
    if (*(int *)(lVar5 + 8) == 2) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      uVar16 = VmpAllSystemsGo((VM_VOLUME_EXTENSION *)pVVar4,param_2,'\x01','\x01','\0');
      uVar11 = (ulonglong)uVar16;
      uVar10 = 0x103;
      if (uVar16 == 0x103) goto LAB_14001877d;
      if (-1 < (int)uVar16) {
        if (pVVar4[0x1ca] == (VM_ROOT_EXTENSION)0x0) {
          local_c0 = (int *)ExAllocatePool2(0x102,0x10,0x20204d56);
          if (local_c0 == (int *)0x0) {
            uVar11 = 0xc000009a;
            VmpDecrementRefCount((VM_VOLUME_EXTENSION *)pVVar4);
            goto LAB_1400187a4;
          }
          ObfReferenceObject(*(undefined8 *)(pVVar4 + 0x188));
          uVar11 = 0;
          *local_c0 = 1;
          *(undefined8 *)(local_c0 + 2) = *(undefined8 *)(pVVar4 + 0x188);
          VmpDecrementRefCount((VM_VOLUME_EXTENSION *)pVVar4);
          *(int **)(param_2 + 0x38) = local_c0;
        }
        else {
          uVar16 = (**(code **)(*(longlong *)(*(longlong *)(pVVar4 + 8) + 0x188) + 0xa0))
                             (*(undefined8 *)(pVVar4 + 0x1d0),&local_c0);
          uVar11 = (ulonglong)uVar16;
          VmpDecrementRefCount((VM_VOLUME_EXTENSION *)pVVar4);
          if (-1 < (int)uVar16) {
            *(int **)(param_2 + 0x38) = local_c0;
          }
        }
      }
      break;
    }
    if (*(int *)(lVar5 + 8) == 4) {
      local_c0 = (int *)ExAllocatePool2(0x102,0x10,0x20204d56);
      if (local_c0 != (int *)0x0) {
        ObfReferenceObject(param_1);
        uVar11 = 0;
        *local_c0 = 1;
        *(longlong *)(local_c0 + 2) = param_1;
        *(int **)(param_2 + 0x38) = local_c0;
        goto LAB_1400187a4;
      }
      goto LAB_140017e42;
    }
    goto LAB_140018793;
  case 8:
    uVar11 = (ulonglong)*(uint *)(param_2 + 0x30);
    goto LAB_1400187a6;
  case 9:
    lVar5 = *(longlong *)(lVar5 + 8);
    puVar1 = (uint *)(lVar5 + 4);
    *puVar1 = *puVar1 | 0x2c0;
    *(undefined4 *)(lVar5 + 8) = *(undefined4 *)(pVVar4 + 0xc4);
    goto switchD_140017ef4_caseD_3;
  case 0xb:
    pVVar3 = *(VM_ROOT_EXTENSION **)(pVVar4 + 8);
    local_a8 = 0;
    local_b0 = (ulonglong)local_b0._4_4_ << 0x20;
    local_a4 = 0;
    VmpAcquireDevices(pVVar3);
    if (pVVar4[0x1ca] == (VM_ROOT_EXTENSION)0x0) {
      lVar5 = *(longlong *)(pVVar4 + 0x178);
    }
    else {
      lVar5 = *(longlong *)(pVVar4 + 0x1d0);
    }
    if (lVar5 == 0) {
      uVar11 = 0xc000000e;
      VmpReleaseDevices(pVVar3);
    }
    else {
      uVar11 = 0;
      local_a0 = 0;
      local_b8 = 0;
      if ((*(uint *)(*(longlong *)pVVar4 + 0x30) & 0x600100) == 0) {
        if (pVVar4[0x1ca] == (VM_ROOT_EXTENSION)0x0) {
          uVar16 = IoGetDevicePropertyData
                             (*(undefined8 *)(pVVar4 + 0x188),&DEVPKEY_Device_SessionId,0,0);
          if ((int)uVar16 < 0) {
            if (uVar16 != 0xc0000034) {
              uVar11 = (ulonglong)uVar16;
            }
          }
          else {
            uVar16 = IoSetDevicePropertyData(*(undefined8 *)pVVar4,&DEVPKEY_Device_SessionId,0,0);
            uVar11 = (ulonglong)uVar16;
            if (-1 < (int)uVar16) {
              pVVar4[0xb8] = (VM_ROOT_EXTENSION)0x1;
              pVVar4[0xba] = (VM_ROOT_EXTENSION)0x1;
              goto LAB_140017fc0;
            }
          }
        }
        if (-1 < (int)uVar11) goto LAB_140017fc0;
      }
      else {
LAB_140017fc0:
        if (pVVar4[0x1ca] == (VM_ROOT_EXTENSION)0x0) {
          iVar13 = IoGetDevicePropertyData
                             (*(undefined8 *)(pVVar4 + 0x188),&DEVPKEY_Device_Numa_Node,0,0);
        }
        else {
          iVar13 = (**(code **)(*(longlong *)(pVVar3 + 0x188) + 0xa8))
                             (*(undefined8 *)(pVVar4 + 0x1d0),&local_a8);
        }
        if (iVar13 < 0) {
          uVar11 = 0;
          VmpReleaseDevices(pVVar3);
          break;
        }
        uVar16 = IoSetDevicePropertyData(param_1,&DEVPKEY_Device_Numa_Node,0,1);
        uVar11 = (ulonglong)uVar16;
        if ((int)uVar16 < 0) {
          uVar11 = 0;
        }
      }
      VmpReleaseDevices(pVVar3);
    }
    break;
  case 0x13:
    iVar13 = *(int *)(lVar5 + 8);
    if ((iVar13 == 0) || (iVar13 == 1)) {
      local_b8 = 0;
      local_78 = 0;
      lStack_70 = 0;
      uVar11 = 0;
      KeWaitForSingleObject(pVVar4 + 0x50,0,0,0);
      if (pVVar4[0x1ca] == (VM_ROOT_EXTENSION)0x0) {
        if (*(longlong *)(pVVar4 + 0x178) != 0) {
          uVar16 = IoGetDevicePropertyData
                             (*(undefined8 *)(pVVar4 + 0x188),&DEVPKEY_Device_ClassGuid,0,0);
          uVar11 = (ulonglong)uVar16;
          pvVar12 = (void *)0x0;
          if ((int)uVar16 < 0) goto LAB_140018613;
          goto LAB_140018583;
        }
      }
      else if (*(longlong *)(pVVar4 + 0x1d0) != 0) {
LAB_140018583:
        if ((local_78 == 0x4585680f53487c23) && (lStack_70 == -0x7d818829efe03c54)) {
          pwVar17 = L"SMR\\Volume";
          sVar14 = 0x16;
        }
        else if ((*(ulonglong *)(pVVar4 + 0x158) >> 0x3a & 1) == 0) {
          pwVar17 = L"STORAGE\\Volume";
          sVar14 = 0x1e;
        }
        else {
          pwVar17 = L"SCM\\Volume";
          sVar14 = 0x16;
        }
        pvVar12 = (void *)ExAllocatePool2(0x102,sVar14 + 2,0x20204d56);
        if (pvVar12 == (void *)0x0) {
          uVar11 = 0xc000009a;
        }
        else {
          memcpy(pvVar12,pwVar17,sVar14);
          *(undefined2 *)((longlong)pvVar12 + sVar14) = 0;
        }
        goto LAB_140018613;
      }
LAB_14001852c:
      uVar11 = 0xc000000e;
      pvVar12 = (void *)0x0;
LAB_140018613:
      KeReleaseMutex(pVVar4 + 0x50,0);
    }
    else {
      if (iVar13 == 3) {
        pvVar12 = (void *)0x0;
        local_58 = 0;
        uStack_50 = 0;
        local_98 = 0;
        pvStack_90 = (void *)0x0;
        KeWaitForSingleObject(pVVar4 + 0x50,0,0,0);
        if (pVVar4[0x1ca] == (VM_ROOT_EXTENSION)0x0) {
          if (*(longlong *)(pVVar4 + 0x178) == 0) {
            uVar11 = 0xc000000e;
          }
          else {
            uVar16 = RtlDuplicateUnicodeString
                               (1,*(longlong *)(*(longlong *)(pVVar4 + 0x178) + 0x40) + 0x30,
                                &local_98);
            uVar11 = (ulonglong)uVar16;
            if (-1 < (int)uVar16) {
              pvVar12 = pvStack_90;
            }
          }
        }
        else {
          if (*(longlong *)(pVVar4 + 0x1d0) == 0) goto LAB_14001852c;
          (**(code **)(*(longlong *)(VmRootExtension + 0x188) + 0x78))
                    (*(undefined8 *)(pVVar4 + 0x1d0),&local_58);
          uVar16 = RtlStringFromGUID(&local_58,&local_98);
          uVar11 = (ulonglong)uVar16;
          if (-1 < (int)uVar16) {
            pvVar12 = pvStack_90;
          }
        }
        goto LAB_140018613;
      }
      if (iVar13 != 5) goto switchD_140017ef4_caseD_4;
      local_a4 = 0;
      local_68 = 0;
      uStack_60 = 0;
      local_b0 = (ulonglong)local_b0._4_4_ << 0x20;
      pvVar12 = (void *)0x0;
      local_88 = 0;
      pvStack_80 = (void *)0x0;
      VmpAcquireDevices(VmRootExtension);
      if (pVVar4[0x1ca] == (VM_ROOT_EXTENSION)0x0) {
        lVar5 = *(longlong *)(pVVar4 + 0x178);
      }
      else {
        lVar5 = *(longlong *)(pVVar4 + 0x1d0);
      }
      if (lVar5 == 0) {
        uVar11 = 0xc000000e;
        VmpReleaseDevices(VmRootExtension);
      }
      else {
        if (pVVar4[0x1ca] == (VM_ROOT_EXTENSION)0x0) {
          uVar16 = IoGetDevicePropertyData
                             (*(undefined8 *)(pVVar4 + 0x188),&DEVPKEY_Device_ContainerId,0,0);
          uVar11 = (ulonglong)uVar16;
          if (-1 < (int)uVar16) goto LAB_1400183e3;
        }
        else {
LAB_1400183e3:
          uVar16 = RtlStringFromGUID(&local_68,&local_88);
          uVar11 = (ulonglong)uVar16;
          if (-1 < (int)uVar16) {
            pvVar12 = pvStack_80;
          }
        }
        VmpReleaseDevices(VmRootExtension);
      }
    }
    if ((int)uVar11 < 0) {
      if (pvVar12 != (void *)0x0) {
        ExFreePoolWithTag(pvVar12,0);
      }
    }
    else {
      *(void **)(param_2 + 0x38) = pvVar12;
    }
    break;
  case 0x14:
    *(undefined8 *)(param_2 + 0x38) = 2;
    if (((*(uint *)(*(longlong *)pVVar4 + 0x30) & 0x200100) != 0) || (0 < *(int *)(pVVar4 + 0xb4)))
    {
      *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 0x20;
    }
    uVar11 = 0;
    goto LAB_1400187a4;
  case 0x16:
    uVar16 = VmpAllSystemsGo((VM_VOLUME_EXTENSION *)pVVar4,param_2,'\x01','\x01','\0');
    uVar10 = 0x103;
    if (uVar16 != 0x103) {
      if ((int)uVar16 < 0) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(uint *)(param_2 + 0x30) = uVar16;
        IofCompleteRequest(param_2,0);
        puVar15 = auStack_108;
        uVar11 = (ulonglong)uVar16;
        goto LAB_1400187b9;
      }
      puVar8 = *(undefined8 **)(param_2 + 0xb8);
      puVar8[-9] = *puVar8;
      puVar8[-8] = puVar8[1];
      puVar8[-7] = puVar8[2];
      puVar8[-6] = puVar8[3];
      *(undefined4 *)(puVar8 + -5) = *(undefined4 *)(puVar8 + 4);
      *(undefined4 *)((longlong)puVar8 + -0x24) = *(undefined4 *)((longlong)puVar8 + 0x24);
      *(undefined4 *)(puVar8 + -4) = *(undefined4 *)(puVar8 + 5);
      *(undefined4 *)((longlong)puVar8 + -0x1c) = *(undefined4 *)((longlong)puVar8 + 0x2c);
      puVar8[-3] = puVar8[6];
      *(undefined1 *)((longlong)puVar8 + -0x45) = 0;
      lVar5 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar5 + -0x10) = VmpDeviceUsageNotificationCompletionRoutine;
      *(VM_ROOT_EXTENSION **)(lVar5 + -8) = pVVar4;
      *(undefined1 *)(lVar5 + -0x45) = 0xe0;
      if (pVVar4[0x1ca] != (VM_ROOT_EXTENSION)0x0) {
        param_2[0x43] = (_IRP)((char)param_2[0x43] + -1);
        lVar5 = *(longlong *)(param_2 + 0xb8);
        *(longlong *)(param_2 + 0xb8) = lVar5 + -0x48;
        pbVar2 = (byte *)(lVar5 + -0x45);
        *pbVar2 = *pbVar2 | 1;
        (**(code **)(*(longlong *)(*(longlong *)(pVVar4 + 8) + 0x188) + 0xd8))
                  (*(undefined8 *)(pVVar4 + 0x1d0),param_2,VmBroadcastIrpCompletionRoutine,param_2);
        puVar15 = auStack_108;
        uVar11 = 0x103;
        goto LAB_1400187b9;
      }
      uVar16 = IofCallDriver(*(undefined8 *)(pVVar4 + 400),param_2);
      uVar10 = (ulonglong)uVar16;
    }
LAB_14001877d:
    uVar11 = uVar10;
    puVar15 = auStack_108;
    goto LAB_1400187b9;
  }
LAB_140018787:
  if ((int)uVar11 == -0x3fffff45) {
LAB_140018793:
    uVar11 = (ulonglong)*(uint *)(param_2 + 0x30);
  }
  else {
LAB_1400187a4:
    *(int *)(param_2 + 0x30) = (int)uVar11;
  }
LAB_1400187a6:
  puVar15 = auStack_108;
  IofCompleteRequest(param_2,0);
LAB_1400187b9:
  *(undefined8 *)(puVar15 + -8) = 0x1400187c5;
  return uVar11;
switchD_140017ef4_caseD_3:
  uVar11 = 0;
  goto LAB_1400187a4;
}



===== VmQueryWmiDataBlock @ 1400187f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmQueryWmiDataBlock(longlong param_1,undefined8 param_2,int param_3,undefined8 param_4,
                        undefined8 param_5,uint *param_6,uint param_7,longlong param_8)

{
  longlong lVar1;
  ushort uVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 auStack_c8 [32];
  undefined1 local_a8;
  wchar_t local_98 [40];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_c8;
  uVar6 = 0;
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar5 = 0;
  if (param_3 == 0) {
    uVar3 = Feature_RacyAccessesInVolmgrAreCountersEnabled__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      if (*(char *)(lVar1 + 0xc1) == '\0') {
        uVar6 = 0xc0000001;
        goto LAB_140018911;
      }
    }
    else if (*(char *)(lVar1 + 0xc1) == '\0') {
      uVar6 = 0xc0000001;
      goto LAB_140018911;
    }
    RtlStringCbPrintfW(local_98,0x50,L"\\Device\\HarddiskVolume%d",
                       (ulonglong)*(uint *)(lVar1 + 0xc4));
    lVar4 = -1;
    do {
      lVar4 = lVar4 + 1;
    } while (local_98[lVar4] != L'\0');
    uVar2 = (short)lVar4 * 2;
    uVar5 = uVar2 + 0x5a;
    if (param_7 < uVar5) {
      uVar6 = 0xc0000023;
    }
    else {
      (**(code **)(*(longlong *)(lVar1 + 8) + 0x150))
                (*(undefined8 *)(lVar1 + 0x100),param_8,L"VOLMGR  ",*(undefined4 *)(lVar1 + 0xc4));
      *(ushort *)(param_8 + 0x58) = uVar2;
      memcpy((void *)(param_8 + 0x5a),local_98,(ulonglong)uVar2);
      *param_6 = uVar5;
    }
  }
  else {
    uVar6 = 0xc0000295;
  }
LAB_140018911:
  local_a8 = 0;
  WmiCompleteRequest(param_1,param_2,uVar6,uVar5);
  return;
}



===== VmpDeregisterDevice @ 140018960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 VmpDeregisterDevice(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  IoWMIRegistrationControl(param_1,2);
  (**(code **)(*(longlong *)(lVar1 + 8) + 0x138))(lVar1 + 0x100,1);
  Feature_RacyAccessesInVolmgrAreCountersEnabled__private_IsEnabledDeviceUsageNoInline();
  *(undefined1 *)(lVar1 + 0xc1) = 0;
  return 0;
}



===== fin$0 @ 1400189b4 =====

void `VmpCheckSecurity'::__l1::fin_0(undefined8 param_1,longlong param_2)

{
  SeUnlockSubjectContext(param_2 + 0x50);
  SeReleaseSubjectContext(param_2 + 0x50);
  return;
}



===== entry @ 140019010 =====

void entry(longlong param_1,undefined8 param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 140019044 =====

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



===== DriverEntry @ 140019078 =====

ulonglong DriverEntry(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  undefined8 local_res8;
  
  local_res8 = 0;
  wil_InitializeFeatureStaging();
  TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
  McGenEventRegister_EtwRegister();
  *(code **)(param_1 + 0x70) = VmCreate;
  *(code **)(param_1 + 0x88) = VmReadWrite;
  *(code **)(param_1 + 0x90) = VmReadWrite;
  *(code **)(param_1 + 0xb8) = VmFlushBuffers;
  *(code **)(param_1 + 0xe0) = VmDeviceControl;
  *(code **)(param_1 + 0xe8) = VmInternalDeviceControl;
  *(code **)(param_1 + 0xf0) = VmShutdown;
  *(code **)(param_1 + 0x100) = VmCleanup;
  *(code **)(param_1 + 0x120) = VmPower;
  *(code **)(param_1 + 0x128) = VmWmi;
  *(code **)(param_1 + 0x148) = VmPnp;
  *(code **)(param_1 + 0x68) = VmUnload;
  uVar1 = IoReportDetectedDevice(param_1,0xffffffff,0xffffffff,0xffffffff,0,0,1,&local_res8);
  uVar3 = (ulonglong)uVar1;
  if (-1 < (int)uVar1) {
    uVar2 = VmAddDevice(param_1,local_res8);
    uVar3 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar2) {
      uVar1 = RtlDuplicateUnicodeString(1,param_2,VmRootExtension + 0x120);
      uVar3 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        uVar1 = VmpQueryGlobalSettings();
        uVar3 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          uVar1 = IoRegisterPlugPlayNotification
                            (2,0,&GUID_DEVINTERFACE_HIDDEN_VOLUME,param_1,VmVolumeDeviceNotification
                             ,0,VmRootExtension + 0x178);
          uVar3 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            IoRegisterBootDriverReinitialization(param_1,VmBootDriverReinitialization,0);
            IoRegisterDriverReinitialization(param_1,VmDriverReinitialization,0);
            IoInvalidateDeviceState(local_res8);
            return uVar3;
          }
        }
      }
    }
  }
  if (VmRootExtension != (VM_ROOT_EXTENSION *)0x0) {
    VmpRemoveDevice(*(longlong *)VmRootExtension,'\x01');
  }
  VmUnload();
  return uVar3;
}



===== VmAddDevice @ 140019290 =====

ulonglong VmAddDevice(undefined8 param_1,undefined8 param_2)

{
  VM_ROOT_EXTENSION *pVVar1;
  VM_ROOT_EXTENSION *pVVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  uVar4 = IoCreateDevice(param_1,400,&DAT_140008160,0x12,0x100,0,local_res18);
  if (-1 < (int)uVar4) {
    pVVar1 = *(VM_ROOT_EXTENSION **)(local_res18[0] + 0x40);
    VmRootExtension = pVVar1;
    *(undefined4 *)(pVVar1 + 0x10) = 0;
    *(longlong *)pVVar1 = local_res18[0];
    *(VM_ROOT_EXTENSION **)(pVVar1 + 8) = pVVar1;
    *(undefined8 *)(pVVar1 + 0x20) = param_1;
    *(undefined8 *)(pVVar1 + 0x30) = param_2;
    *(undefined4 *)(pVVar1 + 0x118) = 1;
    *(undefined4 *)(pVVar1 + 0x180) = 1;
    KeInitializeSpinLock(pVVar1 + 0x18);
    KeInitializeMutex(VmRootExtension + 0x38,0);
    KeInitializeMutex(VmRootExtension + 0x70,0);
    pVVar2 = VmRootExtension;
    pVVar1 = VmRootExtension + 0xb8;
    *(VM_ROOT_EXTENSION **)(VmRootExtension + 0xc0) = pVVar1;
    *(VM_ROOT_EXTENSION **)pVVar1 = pVVar1;
    pVVar1 = pVVar2 + 0xd0;
    *(VM_ROOT_EXTENSION **)(pVVar2 + 0xd8) = pVVar1;
    *(VM_ROOT_EXTENSION **)pVVar1 = pVVar1;
    pVVar1 = pVVar2 + 0xe0;
    *(VM_ROOT_EXTENSION **)(pVVar2 + 0xe8) = pVVar1;
    *(VM_ROOT_EXTENSION **)pVVar1 = pVVar1;
    pVVar1 = pVVar2 + 0xf0;
    *(VM_ROOT_EXTENSION **)(pVVar2 + 0xf8) = pVVar1;
    *(VM_ROOT_EXTENSION **)pVVar1 = pVVar1;
    pVVar1 = pVVar2 + 0x100;
    *(VM_ROOT_EXTENSION **)(pVVar2 + 0x108) = pVVar1;
    *(VM_ROOT_EXTENSION **)pVVar1 = pVVar1;
    uVar3 = VmpUpdateControlStackSd(param_2);
    if (-1 < (int)uVar3) {
      lVar5 = IoAttachDeviceToDeviceStack(local_res18[0],param_2);
      pVVar1 = VmRootExtension;
      *(longlong *)(VmRootExtension + 0x28) = lVar5;
      if (lVar5 == 0) {
        uVar3 = 0xc000000e;
      }
      else {
        uVar3 = IoRegisterDeviceInterface
                          (*(undefined8 *)(pVVar1 + 0x30),&VOLMGR_VOLUME_MANAGER_GUID,0,
                           pVVar1 + 0xa8);
        if ((-1 < (int)uVar3) &&
           (uVar3 = IoSetDeviceInterfaceState(VmRootExtension + 0xa8,1), -1 < (int)uVar3)) {
          IoCreateSymbolicLink(&DAT_140008090,&DAT_140008160);
          uVar3 = IoRegisterLastChanceShutdownNotification(local_res18[0]);
          if (-1 < (int)uVar3) {
            *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) & 0xffffff7f;
            local_res18[0] = 0;
          }
        }
      }
    }
    if (local_res18[0] != 0) {
      VmpRemoveDevice(local_res18[0],'\x01');
    }
    uVar4 = (ulonglong)uVar3;
  }
  return uVar4;
}



===== VmpQueryGlobalSettings @ 1400194a4 =====

int VmpQueryGlobalSettings(void)

{
  VM_ROOT_EXTENSION *pVVar1;
  VM_ROOT_EXTENSION *pVVar2;
  int iVar3;
  uint local_res8 [2];
  longlong local_res10;
  undefined8 local_res18;
  undefined8 local_78;
  undefined4 local_70 [2];
  wchar_t *local_68;
  uint *local_60;
  undefined4 local_58;
  
  local_res10 = 0;
  local_res18 = 0;
  local_78 = 0;
  memset(local_70,0,0x68);
  local_res8[0] = 0;
  iVar3 = RtlCheckRegistryKey(2,L"MiniNT");
  if (iVar3 < 0) {
    if (iVar3 != -0x3fffffcc) goto LAB_14001962c;
  }
  else {
    VmRootExtension[0x11c] = (VM_ROOT_EXTENSION)0x1;
  }
  iVar3 = IoGetBootDiskInformationLite(&local_res10);
  if (-1 < iVar3) {
    *(longlong *)(VmRootExtension + 0x158) = local_res10;
    local_res10 = 0;
    local_68 = L"SystemDriveLetter";
    local_60 = local_res8;
    local_70[0] = 0x124;
    local_58 = 0x4000000;
    iVar3 = RtlQueryRegistryValuesEx(0,L"\\Registry\\Machine\\System\\Setup",&local_78,0,0);
    pVVar2 = VmRootExtension;
    if (iVar3 == -0x3fffffcc) {
      local_res8[0] = 0;
    }
    else if (iVar3 < 0) goto LAB_14001962c;
    if (1 < local_res8[0]) {
      local_res8[0] = 1;
    }
    pVVar1 = VmRootExtension + 0x160;
    VmRootExtension[0x11d] = (VM_ROOT_EXTENSION)((byte)local_res8[0] | (byte)VmRootExtension[0x11c])
    ;
    VmpQueryRegistryRevertEntries
              ((VM_GPT_ATTRIBUTES_REVERT_ENTRY **)(pVVar2 + 0x168),(ulong *)pVVar1);
    iVar3 = IoOpenDriverRegistryKey(*(undefined8 *)(VmRootExtension + 0x20),1,2,0,&local_res18);
    RtlDeleteRegistryValue(0x40000000,local_res18,L"GptAttributeRevertEntries");
    ZwClose(local_res18);
  }
LAB_14001962c:
  if (local_res10 != 0) {
    ExFreePoolWithTag(local_res10,0);
  }
  return iVar3;
}



===== VmpUpdateControlStackSd @ 140019660 =====

int VmpUpdateControlStackSd(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  iVar1 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x158));
  iVar2 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
  iVar3 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0x108));
  iVar4 = RtlLengthSid(*(undefined8 *)(*(longlong *)SeExports_exref + 0xc0));
  iVar1 = iVar1 + iVar2 + iVar3 + iVar4 + 0x38;
  lVar5 = ExAllocatePool2(0x102,iVar1,0x20204d56);
  if (lVar5 == 0) {
    iVar1 = -0x3fffff66;
  }
  else {
    iVar1 = RtlCreateAcl(lVar5,iVar1,2);
    if (-1 < iVar1) {
      iVar1 = RtlAddAccessAllowedAce
                        (lVar5,2,0xa0000000,*(undefined8 *)(*(longlong *)SeExports_exref + 0xc0));
      if (-1 < iVar1) {
        iVar1 = RtlAddAccessAllowedAce
                          (lVar5,2,0x10000000,*(undefined8 *)(*(longlong *)SeExports_exref + 0x108))
        ;
        if (-1 < iVar1) {
          iVar1 = RtlAddAccessAllowedAce
                            (lVar5,2,0x10000000,
                             *(undefined8 *)(*(longlong *)SeExports_exref + 0x110));
          if (-1 < iVar1) {
            iVar1 = RtlAddAccessAllowedAce
                              (lVar5,2,0xa0000000,
                               *(undefined8 *)(*(longlong *)SeExports_exref + 0x158));
            if (-1 < iVar1) {
              iVar1 = RtlCreateSecurityDescriptor(&local_38,1);
              if (-1 < iVar1) {
                iVar1 = RtlSetDaclSecurityDescriptor(&local_38,1,lVar5,0);
                if (-1 < iVar1) {
                  iVar1 = ObSetSecurityObjectByPointer(param_1,4,&local_38);
                }
              }
            }
          }
        }
      }
    }
    ExFreePoolWithTag(lVar5,0);
  }
  return iVar1;
}



===== wil_InitializeFeatureStaging @ 14001989c =====

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
    ppuVar4 = &Feature_SFS_CD_BugFixes_2505__private_descriptor;
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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 14001998c =====

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
  ppuVar3 = &Feature_SFS_CD_BugFixes_2505__private_descriptor;
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


