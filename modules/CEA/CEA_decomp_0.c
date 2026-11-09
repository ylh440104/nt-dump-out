
===== _tlgWriteTransfer_EtwWriteTransfer @ 140001008 =====

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
  *param_6 = PTR_DAT_14000e008;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_14000e008;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_14000e020,&local_18,0,0,param_5,param_6);
  return;
}



===== __report_gsfailure @ 1400010c0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== CleanupLibrary @ 1400010d0 =====

void CleanupLibrary(void)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined8 in_R9;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  EaLibAcquireLockExclusive(0x14000e160);
  lVar4 = DAT_14000e0c0;
  DAT_14000e0c0 = 0;
  EaLibReleaseLockExclusive(0x14000e160);
  if (lVar4 != 0) {
    cVar5 = RtlInitEnumerationHashTable(lVar4,&local_38);
    if (cVar5 != '\0') {
      lVar6 = RtlEnumerateEntryHashTable(lVar4,&local_38);
      while (lVar3 = lVar6, lVar3 != 0) {
        uVar8 = 0;
        RtlRemoveEntryHashTable(lVar4,lVar3);
        puVar7 = &local_38;
        lVar6 = RtlEnumerateEntryHashTable(lVar4);
        EaiDisableAggregateEvent(lVar3,puVar7,uVar8,in_R9);
        LOCK();
        piVar1 = (int *)(lVar3 + 0x88);
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if (iVar2 == 1) {
          EaiFreeTriggerPayload(lVar3);
          if ((*(uint *)(lVar3 + 0x8c) & 8) == 0) {
            EaiFreeEaAggregateEvent((undefined8 *)(lVar3 + 0x38));
          }
          ExFreePoolWithTag(lVar3,0);
        }
      }
      RtlEndEnumerationHashTable(lVar4,&local_38);
    }
    RtlDeleteHashTable(lVar4);
  }
  BriCleanup();
  return;
}



===== EACreateAggregateEvent @ 140001220 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EACreateAggregateEvent(int *param_1,undefined8 *param_2,void *param_3,undefined4 *param_4)

{
  char cVar1;
  int iVar2;
  void *_Dst;
  longlong *plVar3;
  undefined4 *puVar4;
  void *_Dst_00;
  undefined8 *puVar5;
  void *pvVar6;
  uint uVar7;
  void *pvVar8;
  undefined1 auStackY_c8 [32];
  int local_98 [2];
  void *local_90;
  undefined8 local_88 [4];
  void **local_68;
  undefined8 local_60;
  int *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
                    /* 0x1220  11  EACreateAggregateEvent */
  local_48 = __security_cookie ^ (ulonglong)auStackY_c8;
  puVar4 = (undefined4 *)0x0;
  _Dst_00 = (void *)0x0;
  _Dst = (void *)0x0;
  puVar5 = param_2;
  if (4 < DAT_14000e000) {
    puVar5 = (undefined8 *)&DAT_14000cc6e;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000cc6e,param_3,param_4,2,local_88);
  }
  if (param_2 != (undefined8 *)0x0) {
    cVar1 = EaiValidateParameters(param_1,puVar5,param_3,param_4);
    if (cVar1 != '\0') {
      param_3 = (void *)0x41747645;
      _Dst = (void *)ExAllocatePool2(0x100);
      if (_Dst == (void *)0x0) {
        iVar2 = -0x3fffffe9;
        goto LAB_1400015ba;
      }
      memset(_Dst,0,0xa0);
      param_3 = (void *)0x41747645;
      pvVar6 = (void *)0x38;
      plVar3 = (longlong *)ExAllocatePool2(0x100);
      if (plVar3 == (longlong *)0x0) {
        iVar2 = -0x3fffffe9;
      }
      else {
        *plVar3 = 0;
        plVar3[1] = 0;
        plVar3[2] = 0;
        plVar3[3] = 0;
        plVar3[4] = 0;
        plVar3[5] = 0;
        plVar3[6] = 0;
        if ((*param_1 == 0) && (param_1[1] == 0)) {
LAB_140001363:
          if (param_1[3] != 0) {
            param_3 = (void *)0x41747645;
            puVar4 = (undefined4 *)ExAllocatePool2(0x100,0x38);
            if (puVar4 != (undefined4 *)0x0) {
              param_3 = (void *)0x41747645;
              pvVar8 = (void *)((ulonglong)(uint)param_1[3] * 0x38);
              _Dst_00 = (void *)ExAllocatePool2(0x100);
              if (_Dst_00 != (void *)0x0) {
                pvVar6 = (void *)0x0;
                memset(_Dst_00,0,(size_t)pvVar8);
                param_3 = pvVar8;
                goto LAB_1400013d3;
              }
              iVar2 = -0x3fffffe9;
              goto LAB_14000156b;
            }
            goto LAB_140001349;
          }
LAB_1400013d3:
          EaLibLockInitialize((undefined8 *)((longlong)_Dst + 0x50));
          EaLibInitializeWnfSerialization((longlong)_Dst);
          *(undefined4 *)((longlong)_Dst + 0x6c) = 0;
          *(longlong **)((longlong)_Dst + 0x38) = plVar3;
          *(undefined8 *)((longlong)_Dst + 0x48) = *(undefined8 *)(param_1 + 0xc);
          *(undefined8 *)((longlong)_Dst + 0x18) = *(undefined8 *)(param_1 + 8);
          *(undefined8 *)((longlong)_Dst + 0x20) = *(undefined8 *)(param_1 + 10);
          *(undefined8 *)((longlong)_Dst + 0x28) = 0;
          *(undefined8 *)((longlong)_Dst + 0x30) = 0;
          if (*plVar3 != 0) {
            *(undefined8 *)(*plVar3 + 8) = *(undefined8 *)param_1;
            *(int *)(*plVar3 + 0x14) = param_1[2];
          }
          param_4 = (undefined4 *)0x1;
          if (param_1[3] != 0) {
            *puVar4 = 1;
            param_3 = (void *)0x0;
            puVar4[2] = param_1[6];
            puVar4[3] = param_1[3];
            *(void **)(puVar4 + 4) = _Dst_00;
            pvVar8 = param_3;
            if (param_1[3] != 0) {
              do {
                uVar7 = (int)pvVar8 + 1;
                param_3 = (void *)(ulonglong)uVar7;
                pvVar6 = (void *)((longlong)pvVar8 * 0x38);
                *(undefined4 *)((longlong)pvVar6 + (longlong)_Dst_00) = 0;
                *(undefined8 *)((longlong)pvVar6 + 0x10 + (longlong)_Dst_00) =
                     *(undefined8 *)(*(longlong *)(param_1 + 4) + (longlong)pvVar8 * 8);
                *(undefined1 *)((longlong)pvVar6 + 0x30 + (longlong)_Dst_00) = 1;
                pvVar8 = param_3;
              } while (uVar7 < (uint)param_1[3]);
            }
            plVar3[1] = (longlong)puVar4;
          }
          if ((*param_1 == 0) && (param_1[1] == 0)) {
            *(undefined1 *)((longlong)_Dst + 0x40) = 1;
          }
          if ((param_1[2] & 1U) != 0) {
            *(uint *)((longlong)_Dst + 0x8c) = *(uint *)((longlong)_Dst + 0x8c) | 1;
          }
          if ((param_1[2] & 2U) != 0) {
            *(uint *)((longlong)_Dst + 0x8c) = *(uint *)((longlong)_Dst + 0x8c) | 2;
          }
          *(uint *)((longlong)_Dst + 0x8c) = *(uint *)((longlong)_Dst + 0x8c) & 0xfffffff7;
          *(undefined4 *)((longlong)_Dst + 0x88) = 1;
          EaLibAcquireLockExclusive(0x14000e160);
          if (DAT_14000e0c0 == 0) {
            iVar2 = -0x3fffff1b;
          }
          else {
            param_4 = (undefined4 *)0x0;
            pvVar6 = _Dst;
            param_3 = _Dst;
            cVar1 = RtlInsertEntryHashTable();
            iVar2 = 0;
            if (cVar1 == '\0') {
              iVar2 = -0x3fffff66;
            }
          }
          EaLibReleaseLockExclusive(0x14000e160);
          if (-1 < iVar2) {
            iVar2 = EaiEnableAggregateEvent((longlong)_Dst,pvVar6,(longlong)param_3,param_4);
            if (-1 < iVar2) {
              *param_2 = _Dst;
              goto LAB_1400015ba;
            }
            EaLibAcquireLockExclusive(0x14000e160);
            if (DAT_14000e0c0 != 0) {
              param_3 = (void *)0x0;
              RtlRemoveEntryHashTable(DAT_14000e0c0,_Dst);
            }
            EaLibReleaseLockExclusive(0x14000e160);
          }
          if (_Dst_00 != (void *)0x0) {
            ExFreePoolWithTag(_Dst_00,0);
          }
          if (puVar4 != (undefined4 *)0x0) {
LAB_14000156b:
            ExFreePoolWithTag(puVar4,0);
          }
        }
        else {
          pvVar6 = (void *)0x28;
          param_3 = (void *)0x41747645;
          puVar5 = (undefined8 *)ExAllocatePool2();
          *plVar3 = (longlong)puVar5;
          if (puVar5 != (undefined8 *)0x0) {
            *puVar5 = 0;
            puVar5[1] = 0;
            puVar5[2] = 0;
            puVar5[3] = 0;
            puVar5[4] = 0;
            goto LAB_140001363;
          }
LAB_140001349:
          iVar2 = -0x3fffffe9;
        }
        if (*plVar3 != 0) {
          ExFreePoolWithTag(*plVar3,0);
          *plVar3 = 0;
        }
        ExFreePoolWithTag(plVar3,0);
      }
      ExFreePoolWithTag(_Dst,0);
      _Dst = (void *)0x0;
      goto LAB_1400015ba;
    }
  }
  iVar2 = -0x3ffffff3;
LAB_1400015ba:
  if (4 < DAT_14000e000) {
    local_68 = &local_90;
    local_58 = local_98;
    local_60 = 8;
    local_50 = 4;
    local_98[0] = iVar2;
    local_90 = _Dst;
    _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_14000c8dc,param_3,param_4,4,local_88);
  }
  RtlNtStatusToDosError(iVar2);
  return;
}



===== EADeleteAggregateEvent @ 140001640 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EADeleteAggregateEvent
               (longlong param_1,undefined *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  longlong lVar2;
  undefined1 auStackY_98 [32];
  int local_68 [2];
  longlong local_60;
  undefined8 local_58 [4];
  longlong *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
                    /* 0x1640  12  EADeleteAggregateEvent */
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  if (4 < DAT_14000e000) {
    param_2 = &DAT_14000c6e4;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000c6e4,param_3,param_4,2,local_58);
  }
  lVar2 = param_1;
  iVar1 = EaDeleteAggregation(param_1,param_2,param_3,param_4);
  if (4 < DAT_14000e000) {
    local_2c = 0;
    local_38 = &local_60;
    local_1c = 0;
    local_28 = local_68;
    local_30 = 8;
    local_20 = 4;
    local_68[0] = iVar1;
    local_60 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(lVar2,&DAT_14000c9d2,param_3,param_4,4,local_58);
  }
  RtlNtStatusToDosError(iVar1);
  return;
}



===== EAEnumerateAggregateEvents @ 140001720 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EAEnumerateAggregateEvents
               (uint *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  longlong lVar2;
  uint *puVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 auStackY_d8 [32];
  undefined4 local_a8 [2];
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  ulonglong local_78 [2];
  undefined8 local_68 [4];
  ulonglong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
                    /* 0x1720  13  EAEnumerateAggregateEvents */
  local_28 = __security_cookie ^ (ulonglong)auStackY_d8;
  uVar6 = 0;
  local_80 = 0;
  uVar5 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  uStack_88 = 0;
  puVar3 = param_1;
  if (4 < DAT_14000e000) {
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000c95f,param_3,param_4,2,local_68);
  }
  if ((*param_1 == 0) || (param_2 != 0)) {
    EaLibAcquireLockShared(&AggregateEventListLock);
    if (DAT_14000e0c0 == 0) {
      uVar4 = 0xc00000e5;
    }
    else {
      cVar1 = RtlInitEnumerationHashTable(DAT_14000e0c0,&local_a0);
      if (cVar1 != '\0') {
        while (lVar2 = RtlEnumerateEntryHashTable(DAT_14000e0c0,&local_a0), lVar2 != 0) {
          uVar5 = uVar5 + 1;
        }
        RtlEndEnumerationHashTable(DAT_14000e0c0,&local_a0);
      }
      if (*param_1 < uVar5) {
        *param_1 = (uint)uVar5;
        uVar4 = 0xc0000023;
      }
      else {
        cVar1 = RtlInitEnumerationHashTable(DAT_14000e0c0,&local_a0);
        if (cVar1 != '\0') {
          while (lVar2 = RtlEnumerateEntryHashTable(DAT_14000e0c0,&local_a0), lVar2 != 0) {
            *(longlong *)(param_2 + uVar6 * 8) = lVar2;
            uVar6 = (ulonglong)((int)uVar6 + 1);
          }
          RtlEndEnumerationHashTable(DAT_14000e0c0,&local_a0);
        }
        *param_1 = (uint)uVar5;
        uVar4 = 0;
      }
    }
    puVar3 = (uint *)&AggregateEventListLock;
    EaLibReleaseLockShared(&AggregateEventListLock);
  }
  else {
    uVar4 = 0xc000000d;
  }
  if (4 < DAT_14000e000) {
    local_3c = 0;
    local_48 = local_78;
    local_2c = 0;
    local_38 = local_a8;
    local_40 = 8;
    local_30 = 4;
    local_a8[0] = uVar4;
    local_78[0] = uVar5;
    _tlgWriteTransfer_EtwWriteTransfer(puVar3,&DAT_14000c70a,param_3,param_4,4,local_68);
  }
  RtlNtStatusToDosError(uVar4);
  return;
}



===== EAQueryAggregateEventData @ 140001910 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EAQueryAggregateEventData
               (longlong param_1,undefined8 *param_2,longlong param_3,ulonglong param_4)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint uVar9;
  longlong lVar10;
  longlong lVar11;
  uint uVar12;
  bool bVar13;
  undefined1 auStackY_b8 [32];
  longlong local_88;
  longlong local_80;
  undefined8 local_78 [4];
  longlong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
                    /* 0x1910  14  EAQueryAggregateEventData */
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  lVar6 = 0;
  uVar12 = 0;
  local_88 = 0;
  lVar10 = param_1;
  if (4 < DAT_14000e000) {
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000cdff,param_3,param_4,2,local_78);
  }
  if ((param_1 == 0) || (param_2 == (undefined8 *)0x0)) {
    uVar7 = 0xc000000d;
    goto LAB_140001ac2;
  }
  lVar10 = param_1;
  uVar4 = EaiFindAndAcquireAggregateEvent(param_1,&local_88);
  lVar6 = local_88;
  uVar7 = uVar4 & 0xffffffff;
  if ((int)uVar4 < 0) goto LAB_140001ac2;
  EaLibAcquireLockShared(local_88 + 0x50);
  if (*(longlong *)(lVar6 + 0x38) == 0) {
LAB_1400019af:
    uVar7 = 0xc00000e5;
  }
  else {
    piVar1 = *(int **)(*(longlong *)(lVar6 + 0x38) + 8);
    if (piVar1 == (int *)0x0) {
LAB_1400019f5:
      param_2[4] = *(undefined8 *)(lVar6 + 0x18);
      param_2[5] = *(undefined8 *)(lVar6 + 0x20);
      param_2[6] = *(undefined8 *)(lVar6 + 0x48);
      *(uint *)((longlong)param_2 + 0xc) = uVar12;
      if (piVar1 == (int *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = piVar1[2];
      }
      *(int *)(param_2 + 3) = iVar3;
      uVar5 = 0;
      if (**(longlong **)(lVar6 + 0x38) != 0) {
        uVar5 = *(undefined8 *)(**(longlong **)(lVar6 + 0x38) + 8);
      }
      *param_2 = uVar5;
      *(undefined4 *)(param_2 + 1) = 0;
      bVar13 = (*(uint *)(lVar6 + 0x8c) & 1) != 0;
      if (bVar13) {
        *(undefined4 *)(param_2 + 1) = 1;
      }
      if ((*(uint *)(lVar6 + 0x8c) & 2) != 0) {
        *(uint *)(param_2 + 1) = bVar13 | 2;
      }
      param_4 = 0;
      if (uVar12 != 0) {
        param_3 = 0;
        lVar11 = 0x10;
        lVar10 = 0;
        do {
          lVar2 = *(longlong *)(piVar1 + 4);
          if (*(int *)(lVar2 + lVar10) != 0) goto LAB_1400019af;
          lVar8 = 2;
          do {
            *(undefined4 *)(param_3 + param_2[2]) =
                 *(undefined4 *)(lVar2 + lVar10 + param_3 + lVar11);
            param_3 = param_3 + 4;
            lVar8 = lVar8 + -1;
          } while (lVar8 != 0);
          uVar9 = (int)param_4 + 1;
          param_4 = (ulonglong)uVar9;
          lVar10 = lVar10 + 0x38;
          lVar11 = lVar11 + -8;
        } while (uVar9 < uVar12);
      }
      uVar7 = 0;
    }
    else {
      if (*piVar1 != 1) goto LAB_1400019af;
      uVar12 = piVar1[3];
      if (uVar12 == 0) goto LAB_1400019f5;
      if (*(uint *)((longlong)param_2 + 0xc) < uVar12) {
        *(uint *)((longlong)param_2 + 0xc) = uVar12;
        uVar7 = 0xc0000023;
      }
      else {
        if (param_2[2] != 0) goto LAB_1400019f5;
        uVar7 = 0xc000000d;
      }
    }
  }
  lVar10 = lVar6 + 0x50;
  EaLibReleaseLockShared(lVar10);
LAB_140001ac2:
  if (lVar6 != 0) {
    EaiReleaseAggregateEvent(lVar6);
    lVar10 = lVar6;
  }
  if (4 < DAT_14000e000) {
    local_4c = 0;
    local_58 = &local_80;
    local_3c = 0;
    local_48 = &local_88;
    local_50 = 8;
    local_88 = CONCAT44(local_88._4_4_,(int)uVar7);
    local_40 = 4;
    local_80 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(lVar10,&DAT_14000c5e6,param_3,param_4,4,local_78);
  }
  RtlNtStatusToDosError(uVar7);
  return;
}



===== EaCreateAggregation @ 140001b60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EaCreateAggregation(longlong *param_1,longlong param_2,longlong *param_3,undefined4 *param_4,
                       longlong param_5,longlong param_6,uint param_7,undefined8 *param_8)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  longlong lVar5;
  int iVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  undefined4 *puVar9;
  undefined1 auStackY_e8 [32];
  longlong *local_a8;
  longlong *local_a0;
  longlong *local_98;
  code *local_90;
  undefined8 local_88;
  undefined8 local_80;
  longlong **local_78;
  undefined8 local_70;
  longlong **local_68;
  undefined8 local_60;
  longlong local_58 [4];
  ulonglong local_38;
  
                    /* 0x1b60  16  EaCreateAggregation */
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_a0 = (longlong *)0x0;
  puVar9 = param_4;
  if (4 < DAT_14000e000) {
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000cea3,0,param_4,2,local_58);
  }
  local_a8 = (longlong *)0x0;
  plVar8 = (longlong *)0x0;
  local_58[0] = 0;
  local_58[1] = 0;
  if (param_1 == (longlong *)0x0) {
    iVar6 = -0x3ffffff3;
LAB_140001ce4:
    if (plVar8 != (longlong *)0x0) {
      EaiFreeEaAggregateEvent(&local_a8);
    }
    plVar8 = (longlong *)0x0;
    if (iVar6 < 0) goto LAB_140001d37;
  }
  else {
    plVar8 = (longlong *)ExAllocatePool2(0x100,0x38);
    local_a8 = plVar8;
    if (plVar8 == (longlong *)0x0) {
LAB_140001c16:
      iVar6 = -0x3fffffe9;
      goto LAB_140001ce4;
    }
    lVar5 = param_1[1];
    *plVar8 = *param_1;
    plVar8[1] = lVar5;
    lVar5 = param_1[3];
    plVar8[2] = param_1[2];
    plVar8[3] = lVar5;
    uVar2 = *(undefined4 *)((longlong)param_1 + 0x24);
    lVar5 = param_1[5];
    uVar3 = *(undefined4 *)((longlong)param_1 + 0x2c);
    *(int *)(plVar8 + 4) = (int)param_1[4];
    *(undefined4 *)((longlong)plVar8 + 0x24) = uVar2;
    *(int *)(plVar8 + 5) = (int)lVar5;
    *(undefined4 *)((longlong)plVar8 + 0x2c) = uVar3;
    plVar8[6] = param_1[6];
    *plVar8 = 0;
    plVar8[1] = 0;
    if (*param_1 != 0) {
      puVar7 = (undefined8 *)ExAllocatePool2(0x100,0x28);
      *plVar8 = (longlong)puVar7;
      if (puVar7 == (undefined8 *)0x0) goto LAB_140001c16;
      puVar1 = (undefined8 *)*param_1;
      uVar4 = puVar1[1];
      *puVar7 = *puVar1;
      puVar7[1] = uVar4;
      uVar4 = puVar1[3];
      puVar7[2] = puVar1[2];
      puVar7[3] = uVar4;
      puVar7[4] = puVar1[4];
    }
    if (param_1[1] != 0) {
      local_98 = local_58;
      local_88 = 0;
      local_80 = 0;
      local_90 = EaiAggregationConditionNextChild;
      local_78 = (longlong **)EaiDuplicateConditionsVisitNode;
      iVar6 = EapTreeTraverse(&local_98,param_1[1]);
      if (iVar6 < 0) goto LAB_140001ce4;
      plVar8[1] = local_58[0];
    }
  }
  iVar6 = EaiCreateAggregation(plVar8,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if (-1 < iVar6) {
    plVar8 = (longlong *)0x0;
  }
  puVar9 = param_4;
  local_a0 = plVar8;
LAB_140001d37:
  if (plVar8 != (longlong *)0x0) {
    EaiFreeEaAggregateEvent(&local_a0);
  }
  if ((param_8 == (undefined8 *)0x0) || (iVar6 < 0)) {
    local_a0 = (longlong *)0x0;
  }
  else {
    local_a0 = (longlong *)*param_8;
  }
  if (4 < DAT_14000e000) {
    local_78 = &local_a0;
    local_70 = 8;
    local_68 = &local_a8;
    local_a8 = (longlong *)CONCAT44(local_a8._4_4_,iVar6);
    local_60 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_14000ca3d,0,puVar9,4,&local_98);
  }
  return iVar6;
}



===== EaDeleteAggregation @ 140001de0 =====

int EaDeleteAggregation(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
                    /* 0x1de0  20  EaDeleteAggregation */
  if (param_1 == 0) {
    iVar1 = -0x3ffffff3;
  }
  else {
    EaLibAcquireLockExclusive(0x14000e160);
    if ((DAT_14000e0c0 != 0) && (lVar2 = RtlLookupEntryHashTable(DAT_14000e0c0,param_1), lVar2 != 0)
       ) {
      uVar4 = 0;
      lVar3 = lVar2;
      RtlRemoveEntryHashTable(DAT_14000e0c0);
      EaLibReleaseLockExclusive(0x14000e160);
      iVar1 = EaiDisableAggregateEvent(lVar2,lVar3,uVar4,param_4);
      if (iVar1 < 0) {
        return iVar1;
      }
      EaiReleaseAggregateEvent(lVar2);
      return 0;
    }
    EaLibReleaseLockExclusive(0x14000e160);
    iVar1 = -0x3ffffddb;
  }
  return iVar1;
}



===== EaDisableAggregatedEvent @ 140001e90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EaDisableAggregatedEvent
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined1 auStackY_98 [32];
  longlong local_68;
  longlong local_60;
  undefined8 local_58 [4];
  longlong *local_38;
  undefined8 local_30;
  longlong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
                    /* 0x1e90  21  EaDisableAggregatedEvent */
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar5 = 0;
  local_68 = 0;
  lVar3 = param_1;
  if (4 < DAT_14000e000) {
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000ce1f,param_3,param_4,2,local_58);
  }
  if (param_1 == 0) {
    iVar1 = -0x3ffffff3;
  }
  else {
    plVar4 = &local_68;
    uVar2 = EaiFindAndAcquireAggregateEvent(param_1,plVar4);
    lVar5 = local_68;
    if ((int)uVar2 < 0) {
      iVar1 = -0x3ffffddb;
      lVar3 = param_1;
    }
    else {
      lVar3 = local_68;
      iVar1 = EaiDisableAggregateEvent(local_68,plVar4,param_3,param_4);
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
    if (lVar5 != 0) {
      lVar3 = lVar5;
      EaiReleaseAggregateEvent(lVar5);
    }
  }
  if (4 < DAT_14000e000) {
    local_38 = &local_60;
    local_28 = &local_68;
    local_30 = 8;
    local_68 = CONCAT44(local_68._4_4_,iVar1);
    local_20 = 4;
    local_60 = lVar5;
    _tlgWriteTransfer_EtwWriteTransfer(lVar3,&DAT_14000c749,param_3,param_4,4,local_58);
  }
  return iVar1;
}



===== EaEnableAggregatedEvent @ 140001fb0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong EaEnableAggregatedEvent
                    (longlong param_1,undefined8 param_2,longlong param_3,undefined4 *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong *plVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined1 auStackY_98 [32];
  longlong local_68;
  longlong local_60;
  undefined8 local_58 [4];
  longlong *local_38;
  undefined8 local_30;
  longlong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
                    /* 0x1fb0  22  EaEnableAggregatedEvent */
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar6 = 0;
  local_68 = 0;
  lVar3 = param_1;
  if (4 < DAT_14000e000) {
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000ce46,param_3,param_4,2,local_58);
  }
  if (param_1 == 0) {
    uVar5 = 0xc000000d;
  }
  else {
    plVar4 = &local_68;
    uVar2 = EaiFindAndAcquireAggregateEvent(param_1,plVar4);
    lVar6 = local_68;
    uVar5 = uVar2 & 0xffffffff;
    lVar3 = param_1;
    if (-1 < (int)uVar2) {
      lVar3 = local_68;
      uVar1 = EaiEnableAggregateEvent(local_68,plVar4,param_3,param_4);
      uVar5 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        uVar5 = 0;
      }
    }
    if (lVar6 != 0) {
      lVar3 = lVar6;
      EaiReleaseAggregateEvent(lVar6);
    }
  }
  if (4 < DAT_14000e000) {
    local_38 = &local_60;
    local_28 = &local_68;
    local_30 = 8;
    local_68 = CONCAT44(local_68._4_4_,(int)uVar5);
    local_20 = 4;
    local_60 = lVar6;
    _tlgWriteTransfer_EtwWriteTransfer(lVar3,&DAT_14000c6a8,param_3,param_4,4,local_58);
  }
  return uVar5;
}



===== EaGetAggregation @ 1400020d0 =====

void EaGetAggregation(longlong param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4)

{
                    /* 0x20d0  26  EaGetAggregation */
  EaiExtractEventAggregation(param_1,'\0',param_2,param_4);
  return;
}



===== EaQueryAggregateEventConditionState @ 1400020f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong EaQueryAggregateEventConditionState
                    (longlong param_1,undefined1 *param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined1 auStackY_a8 [32];
  longlong local_78;
  longlong local_70;
  undefined8 local_68 [4];
  longlong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
                    /* 0x20f0  27  EaQueryAggregateEventConditionState */
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  lVar4 = 0;
  local_78 = 0;
  lVar3 = param_1;
  if (4 < DAT_14000e000) {
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000c840,param_3,param_4,2,local_68);
  }
  if (param_2 == (undefined1 *)0x0) {
    uVar5 = 0xc000000d;
  }
  else {
    uVar2 = EaiFindAndAcquireAggregateEvent(param_1,&local_78);
    lVar4 = local_78;
    uVar5 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      uVar5 = 0xc0000225;
      lVar3 = param_1;
    }
    else {
      EaLibAcquireLockShared(local_78 + 0x50);
      uVar1 = EaiEvaluateConditions(lVar4);
      lVar3 = lVar4 + 0x50;
      *param_2 = uVar1;
      EaLibReleaseLockShared(lVar3);
    }
    if (lVar4 != 0) {
      lVar3 = lVar4;
      EaiReleaseAggregateEvent(lVar4);
    }
  }
  if (4 < DAT_14000e000) {
    local_3c = 0;
    local_48 = &local_70;
    local_2c = 0;
    local_38 = &local_78;
    local_40 = 8;
    local_78 = CONCAT44(local_78._4_4_,(int)uVar5);
    local_30 = 4;
    local_70 = lVar4;
    _tlgWriteTransfer_EtwWriteTransfer(lVar3,&DAT_14000c664,param_3,param_4,4,local_68);
  }
  return uVar5;
}



===== EaQueryAggregatedEvent @ 140002220 =====

undefined8 EaQueryAggregatedEvent(void)

{
                    /* 0x2220  28  EaQueryAggregatedEvent */
  return 0xc0000002;
}



===== EaSignalAggregatedEvent @ 140002230 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong EaSignalAggregatedEvent
                    (longlong *param_1,longlong *param_2,longlong *param_3,undefined8 param_4,
                    longlong *param_5,longlong *param_6,void *param_7,uint param_8,longlong *param_9
                    )

{
  longlong lVar1;
  ulonglong uVar2;
  longlong *plVar3;
  longlong *_Dst;
  uint uVar4;
  ulonglong uVar5;
  longlong *plVar6;
  char cVar7;
  longlong *_Size;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined7 uVar10;
  undefined1 auStackY_f8 [32];
  uint local_b4;
  longlong *local_b0;
  longlong *local_a8;
  void *local_a0;
  undefined8 local_98 [4];
  longlong **local_78;
  undefined4 local_70;
  undefined4 local_6c;
  uint *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  ulonglong local_58;
  
                    /* 0x2230  30  EaSignalAggregatedEvent */
  uVar8 = (undefined1)param_4;
  uVar10 = (undefined7)((ulonglong)param_4 >> 8);
  local_58 = __security_cookie ^ (ulonglong)auStackY_f8;
  plVar3 = (longlong *)0x0;
  local_b4 = 0;
  plVar6 = (longlong *)0x0;
  cVar7 = (char)param_3;
  local_a0 = param_7;
  local_b0 = param_9;
  local_a8 = (longlong *)0x0;
  uVar9 = uVar8;
  if (4 < DAT_14000e000) {
    _tlgWriteTransfer_EtwWriteTransfer(param_9,&DAT_14000c5c5,param_3,param_4,2,local_98);
  }
  if (((int)*param_2 != 0) || (*(int *)((longlong)param_2 + 4) != 0)) {
    _Size = (longlong *)(ulonglong)param_8;
    if ((param_8 == 0) || (local_a0 != (void *)0x0)) {
      uVar2 = EaiFindAndAcquireAggregateEvent(param_1,(longlong *)&local_a8);
      plVar6 = local_a8;
      uVar5 = uVar2 & 0xffffffff;
      if (-1 < (int)uVar2) {
        param_1 = local_a8 + 10;
        EaLibAcquireLockShared(param_1);
        if (((cVar7 == '\0') || (lVar1 = *(longlong *)plVar6[7], lVar1 == 0)) ||
           (((int)*param_2 == *(int *)(lVar1 + 8) &&
            (*(int *)((longlong)param_2 + 4) == *(int *)(lVar1 + 0xc))))) {
          EaLibReleaseLockShared(param_1);
          uVar4 = (-(uint)(param_6 != (longlong *)0x0) & 0x10) +
                  (-(uint)(param_5 != (longlong *)0x0) & 0x10) + param_8;
          if (uVar4 != 0) {
            param_1 = (longlong *)0x100;
            param_3 = (longlong *)0x41747645;
            plVar3 = (longlong *)ExAllocatePool2(0x100,uVar4);
            if (plVar3 == (longlong *)0x0) {
              uVar5 = 0xc0000017;
              goto LAB_1400023f9;
            }
            if (param_5 == (longlong *)0x0) {
              _Dst = plVar3;
            }
            else {
              lVar1 = param_5[1];
              local_b4 = 2;
              *plVar3 = *param_5;
              plVar3[1] = lVar1;
              _Dst = plVar3 + 2;
            }
            if (param_6 != (longlong *)0x0) {
              lVar1 = param_6[1];
              local_b4 = local_b4 | 1;
              *_Dst = *param_6;
              _Dst[1] = lVar1;
              _Dst = _Dst + 2;
            }
            memmove(_Dst,local_a0,(size_t)_Size);
            param_3 = _Size;
          }
          param_3 = (longlong *)CONCAT71((int7)((ulonglong)param_3 >> 8),cVar7);
          param_1 = plVar6;
          uVar5 = EaiProcessNotification
                            ((longlong)plVar6,param_2,param_3,(longlong *)CONCAT71(uVar10,uVar8),
                             plVar3,uVar4,local_b4,(undefined4 *)local_b0);
          uVar5 = uVar5 & 0xffffffff;
          uVar9 = uVar8;
        }
        else {
          EaLibReleaseLockShared(param_1);
          uVar5 = 0xc00000bb;
        }
      }
LAB_1400023f9:
      if (plVar6 != (longlong *)0x0) {
        param_1 = plVar6;
        EaiReleaseAggregateEvent((longlong)plVar6);
      }
      if (plVar3 != (longlong *)0x0) {
        ExFreePoolWithTag(plVar3,0);
        param_1 = plVar3;
      }
      goto LAB_14000241c;
    }
  }
  uVar5 = 0xc000000d;
  param_1 = param_9;
LAB_14000241c:
  local_b4 = (uint)uVar5;
  if (4 < DAT_14000e000) {
    local_6c = 0;
    local_78 = &local_b0;
    local_5c = 0;
    local_68 = &local_b4;
    local_70 = 8;
    local_60 = 4;
    local_b0 = plVar6;
    _tlgWriteTransfer_EtwWriteTransfer
              (param_1,&DAT_14000c7d3,param_3,CONCAT71(uVar10,uVar9),4,local_98);
  }
  return uVar5;
}



===== EaiAggregationConditionNextChild @ 1400024a0 =====

undefined8
EaiAggregationConditionNextChild(undefined8 param_1,int *param_2,ushort param_3,longlong *param_4)

{
  *param_4 = 0;
  if ((*param_2 == 1) && ((uint)param_3 < (uint)param_2[3])) {
    *param_4 = (ulonglong)param_3 * 0x38 + *(longlong *)(param_2 + 4);
  }
  return 0;
}



===== EaiCreateAggregation @ 1400024cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EaiCreateAggregation
              (longlong *param_1,longlong param_2,longlong *param_3,undefined4 *param_4,
              longlong param_5,longlong param_6,uint param_7,undefined8 *param_8)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  longlong *_Dst;
  longlong *plVar4;
  undefined4 uVar5;
  longlong *plVar6;
  undefined4 *puVar7;
  undefined1 auStackY_a8 [32];
  int local_78;
  undefined4 local_74 [3];
  undefined8 local_68 [4];
  int *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  puVar7 = param_4;
  if ((param_8 == (undefined8 *)0x0) || (param_1 == (longlong *)0x0)) {
    uVar5 = 100;
  }
  else {
    if ((*param_1 != 0) || (param_1[1] != 0)) {
      plVar6 = (longlong *)0x41747645;
      plVar4 = (longlong *)0x100;
      _Dst = (longlong *)ExAllocatePool2();
      if (_Dst == (longlong *)0x0) {
        iVar3 = -0x3fffffe9;
        uVar5 = 300;
        _Dst = plVar4;
      }
      else {
        plVar4 = (longlong *)0x0;
        plVar6 = (longlong *)0xa0;
        memset(_Dst,0,0xa0);
        *(uint *)((longlong)_Dst + 0x8c) = *(uint *)((longlong)_Dst + 0x8c) | 0x10;
        _Dst[5] = param_5;
        _Dst[9] = param_6;
        *(undefined4 *)(_Dst + 0x11) = 1;
        _Dst[7] = (longlong)param_1;
        _Dst[3] = param_2;
        _Dst[4] = (longlong)param_3;
        _Dst[6] = (longlong)param_4;
        EaLibLockInitialize(_Dst + 10);
        EaLibInitializeWnfSerialization((longlong)_Dst);
        lVar1 = *(longlong *)_Dst[7];
        if ((lVar1 == 0) || ((*(int *)(lVar1 + 8) == 0 && (*(int *)(lVar1 + 0xc) == 0)))) {
          *(undefined1 *)(_Dst + 8) = 1;
        }
        if ((param_7 & 1) != 0) {
          *(uint *)((longlong)_Dst + 0x8c) = *(uint *)((longlong)_Dst + 0x8c) | 1;
        }
        if ((param_7 & 2) != 0) {
          *(uint *)((longlong)_Dst + 0x8c) = *(uint *)((longlong)_Dst + 0x8c) | 2;
        }
        if ((param_7 & 4) != 0) {
          *(uint *)((longlong)_Dst + 0x8c) = *(uint *)((longlong)_Dst + 0x8c) | 4;
        }
        EaLibAcquireLockExclusive(0x14000e160);
        if (DAT_14000e0c0 == 0) {
          iVar3 = -0x3fffff1b;
        }
        else {
          puVar7 = (undefined4 *)0x0;
          plVar4 = _Dst;
          plVar6 = _Dst;
          cVar2 = RtlInsertEntryHashTable();
          iVar3 = 0;
          if (cVar2 == '\0') {
            iVar3 = -0x3fffff66;
          }
        }
        EaLibReleaseLockExclusive(0x14000e160);
        if (iVar3 < 0) {
          uVar5 = 400;
        }
        else {
          if (((param_7 & 8) != 0) ||
             (iVar3 = EaiEnableAggregateEvent((longlong)_Dst,plVar4,(longlong)plVar6,puVar7),
             -1 < iVar3)) {
            *param_8 = _Dst;
            return iVar3;
          }
          uVar5 = 500;
          EaLibAcquireLockExclusive(0x14000e160);
          if (DAT_14000e0c0 != 0) {
            plVar6 = (longlong *)0x0;
            RtlRemoveEntryHashTable(DAT_14000e0c0,_Dst);
          }
          EaLibReleaseLockExclusive(0x14000e160);
        }
        ExFreePoolWithTag(_Dst,0);
      }
      goto LAB_1400026cb;
    }
    uVar5 = 200;
  }
  iVar3 = -0x3ffffff3;
  _Dst = param_1;
  plVar6 = param_3;
LAB_1400026cb:
  if (2 < DAT_14000e000) {
    local_3c = 0;
    local_48 = &local_78;
    local_2c = 0;
    local_38 = local_74;
    local_40 = 4;
    local_30 = 4;
    local_78 = iVar3;
    local_74[0] = uVar5;
    _tlgWriteTransfer_EtwWriteTransfer(_Dst,&DAT_14000c61c,plVar6,puVar7,4,local_68);
  }
  return iVar3;
}



===== EaiDisableAggregateEvent @ 140002760 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EaiDisableAggregateEvent
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 auStackY_98 [32];
  longlong local_68;
  longlong local_60;
  undefined8 local_58 [4];
  longlong *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  if (4 < DAT_14000e000) {
    local_2c = 0;
    local_38 = &local_68;
    local_30 = 8;
    local_68 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000ce6c,param_3,param_4,3,local_58);
  }
  lVar3 = param_1 + 0x50;
  iVar1 = 0;
  EaLibAcquireLockExclusive(lVar3);
  if (*(int *)(param_1 + 0x6c) != 0) {
    EaLibClearAndReleaseTimer(param_1);
    lVar2 = EaLibGetCurrentThreadId();
    if (*(longlong *)(param_1 + 0x70) != lVar2) {
      *(undefined4 *)(param_1 + 0x6c) = 0;
      EaLibReleaseLockExclusive(lVar3);
      if (((longlong *)**(longlong **)(param_1 + 0x38) != (longlong *)0x0) &&
         (*(longlong *)**(longlong **)(param_1 + 0x38) != 0)) {
        EaLibUnsubscribeWnfStateChangeNotification();
        *(undefined8 *)**(undefined8 **)(param_1 + 0x38) = 0;
      }
      lVar3 = param_1;
      iVar1 = EaiSetAggregateConditionsEnabledState(param_1,0,param_3,param_4);
      goto LAB_1400027ff;
    }
    iVar1 = -0x3fffff45;
  }
  EaLibReleaseLockExclusive(lVar3);
LAB_1400027ff:
  if (4 < DAT_14000e000) {
    local_2c = 0;
    local_38 = &local_60;
    local_1c = 0;
    local_28 = &local_68;
    local_30 = 8;
    local_68 = CONCAT44(local_68._4_4_,iVar1);
    local_20 = 4;
    local_60 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(lVar3,&DAT_14000cecf,param_3,param_4,4,local_58);
  }
  return iVar1;
}



===== EaiDumpAggregateEvent @ 1400028c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EaiDumpAggregateEvent
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  longlong lVar2;
  undefined1 auStackY_f8 [32];
  longlong local_c8 [3];
  undefined8 local_b0;
  longlong *local_a8;
  longlong *local_a0;
  code *local_98;
  undefined8 local_90;
  undefined8 local_88;
  code *local_80;
  undefined8 local_78 [4];
  longlong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong **local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_f8;
  plVar1 = *(longlong **)(param_1 + 0x38);
  if ((plVar1 == (longlong *)0x0) || (*plVar1 == 0)) {
    local_c8[0] = 0;
  }
  else {
    local_c8[0] = *(longlong *)(*plVar1 + 8);
  }
  if (4 < DAT_14000e000) {
    local_4c = 0;
    local_58 = local_c8 + 2;
    local_3c = 0;
    local_2c = 0;
    local_1c = 0;
    local_b0 = *(undefined8 *)(param_1 + 0x48);
    local_28 = local_c8;
    local_48 = &local_b0;
    local_38 = &local_a8;
    local_50 = 8;
    local_40 = 8;
    local_30 = 8;
    local_20 = 8;
    local_c8[2] = param_1;
    local_a8 = plVar1;
    _tlgWriteTransfer_EtwWriteTransfer(local_38,&DAT_14000cd4f,8,param_4,6,local_78);
  }
  lVar2 = *(longlong *)(param_1 + 0x38);
  if ((lVar2 != 0) && (local_c8[1] = 0, *(longlong *)(lVar2 + 8) != 0)) {
    local_90 = 0;
    local_a0 = local_c8;
    local_88 = 0;
    local_98 = EaiAggregationConditionNextChild;
    local_80 = EaiDumpConditionVisitNode;
    local_c8[0] = param_1;
    EapTreeTraverse(&local_a0,*(undefined8 *)(lVar2 + 8));
  }
  return;
}



===== EaiDumpConditionVisitNode @ 1400029f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
EaiDumpConditionVisitNode(undefined8 param_1,int *param_2,undefined2 param_3,ulonglong param_4)

{
  byte bVar1;
  byte *pbVar2;
  ulonglong uVar3;
  undefined1 auStackY_d8 [32];
  undefined4 uVar4;
  undefined2 local_a8 [2];
  int local_a4;
  uint local_a0;
  undefined4 local_9c;
  undefined8 local_98 [2];
  undefined8 local_88 [4];
  undefined2 *local_68;
  undefined8 local_60;
  int *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined8 local_40;
  int *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  if (*param_2 == 0) {
    if (param_2 == (int *)0xfffffffffffffff8) {
      local_98[0] = 0;
      bVar1 = 0;
      uVar3 = 0;
      param_4 = 0;
    }
    else {
      local_98[0] = *(undefined8 *)(param_2 + 4);
      bVar1 = *(byte *)(param_2 + 8);
      uVar3 = (ulonglong)(uint)param_2[6];
      param_4 = (ulonglong)(uint)param_2[7];
    }
    if (DAT_14000e000 < 5) {
      return 0;
    }
    local_58 = (int *)local_98;
    pbVar2 = &DAT_14000cdab;
    local_a0 = (uint)bVar1;
    local_38 = &local_a4;
    local_28 = &local_9c;
    uVar4 = 7;
    local_50 = 8;
    local_a4 = (int)uVar3;
    local_30 = 4;
    local_9c = (undefined4)param_4;
    local_20 = 4;
  }
  else {
    if (*param_2 != 1) {
      return 0xc00000e5;
    }
    if (param_2 + 2 == (int *)0x0) {
      local_a4 = 2;
      uVar3 = 0;
    }
    else {
      local_a4 = param_2[2];
      uVar3 = (ulonglong)(uint)param_2[3];
    }
    if (DAT_14000e000 < 5) {
      return 0;
    }
    local_58 = &local_a4;
    pbVar2 = &DAT_14000c918;
    uVar4 = 5;
    local_50 = 4;
    local_a0 = (uint)uVar3;
  }
  local_48 = &local_a0;
  local_68 = local_a8;
  local_60 = 2;
  local_40 = 4;
  local_a8[0] = param_3;
  _tlgWriteTransfer_EtwWriteTransfer(4,pbVar2,uVar3,param_4,uVar4,local_88);
  return 0;
}



===== EaiDuplicateConditionsVisitNode @ 140002b70 =====

undefined4 EaiDuplicateConditionsVisitNode(longlong *param_1,int *param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  longlong lVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  void *_Dst;
  longlong lVar11;
  int iVar12;
  undefined4 uVar13;
  longlong lVar14;
  ushort uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined8 local_res8;
  undefined1 local_98 [16];
  int local_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  int local_78;
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  int local_68;
  undefined8 uStack_60;
  undefined4 local_58;
  undefined4 uStack_54;
  
  local_58 = 0;
  uStack_54 = 0;
  uVar13 = 0xc00000e5;
  local_98 = ZEXT816(0);
  local_88 = 0;
  iStack_84 = 0;
  iStack_80 = 0;
  iStack_7c = 0;
  if (*param_2 == 0) {
    local_78 = *param_2;
    iStack_74 = param_2[1];
    iStack_70 = param_2[2];
    iStack_6c = param_2[3];
    local_98 = *(undefined1 (*) [16])(param_2 + 4);
    local_58 = local_98._0_4_;
    uStack_54 = local_98._4_4_;
    uVar16 = local_98._8_4_;
    uVar17 = local_98._12_4_;
    local_88 = param_2[8];
    iStack_84 = param_2[9];
    iStack_80 = param_2[10];
    iStack_7c = param_2[0xb];
    local_res8 = *(undefined8 *)(param_2 + 0xc);
    uVar9 = local_98._0_8_;
LAB_140002cf3:
    if (*(ushort *)((longlong)param_1 + 10) == *(ushort *)(param_1 + 1)) {
      _Dst = (void *)ExAllocatePool2(0x100,((ulonglong)*(ushort *)(param_1 + 1) + 5) * 0x38,
                                     0x41747645);
      if (_Dst == (void *)0x0) {
        uVar13 = 0xc0000017;
        goto LAB_140002d32;
      }
      if ((void *)*param_1 != (void *)0x0) {
        memmove(_Dst,(void *)*param_1,(ulonglong)*(ushort *)(param_1 + 1) * 0x38);
        ExFreePoolWithTag(*param_1,0);
      }
      *(short *)(param_1 + 1) = (short)param_1[1] + 5;
      *param_1 = (longlong)_Dst;
      local_58 = local_98._0_4_;
      uStack_54 = local_98._4_4_;
      uVar16 = local_98._8_4_;
      uVar17 = local_98._12_4_;
    }
    uVar13 = 0;
    lVar11 = (ulonglong)*(ushort *)((longlong)param_1 + 10) * 0x38;
    lVar7 = *param_1;
    *(undefined8 *)(lVar11 + lVar7) = CONCAT44(iStack_74,local_78);
    ((undefined8 *)(lVar11 + lVar7))[1] = CONCAT44(iStack_6c,iStack_70);
    puVar3 = (undefined4 *)(lVar11 + 0x10 + lVar7);
    *puVar3 = local_58;
    puVar3[1] = uStack_54;
    puVar3[2] = uVar16;
    puVar3[3] = uVar17;
    piVar4 = (int *)(lVar11 + 0x20 + lVar7);
    *piVar4 = local_88;
    piVar4[1] = iStack_84;
    piVar4[2] = iStack_80;
    piVar4[3] = iStack_7c;
    *(undefined8 *)(lVar11 + 0x30 + lVar7) = local_res8;
    *(short *)((longlong)param_1 + 10) = *(short *)((longlong)param_1 + 10) + 1;
  }
  else {
    if (*param_2 == 1) {
      uVar5 = param_2[3];
      if (*(ushort *)((longlong)param_1 + 10) < uVar5) goto LAB_140002cbe;
      uVar6 = param_2[2];
      iVar12 = 0;
      uStack_60 = (ulonglong)uVar6;
      if (uVar5 == 0) {
        uVar9 = 0;
LAB_140002caa:
        uVar17 = 0;
        uVar16 = 0;
        local_78 = 1;
        iStack_74 = 0;
        iStack_70 = (int)uStack_60;
        iStack_6c = uStack_60._4_4_;
        local_res8 = 0;
        goto LAB_140002cf3;
      }
      uVar9 = ExAllocatePool2(0x100,(ulonglong)uVar5 * 0x38,0x41747645);
      if (uVar9 != 0) {
        uVar15 = 0;
        if (param_2[3] != 0) {
          do {
            lVar7 = *param_1;
            iVar12 = iVar12 + 1;
            lVar14 = (ulonglong)*(ushort *)((longlong)param_1 + 10) * 0x38;
            uVar10 = (ulonglong)uVar15;
            uVar15 = uVar15 + 1;
            lVar11 = uVar10 * 0x38;
            puVar1 = (undefined8 *)(lVar14 + -0x38 + lVar7);
            uVar8 = puVar1[1];
            *(undefined8 *)(lVar11 + uVar9) = *puVar1;
            ((undefined8 *)(lVar11 + uVar9))[1] = uVar8;
            puVar1 = (undefined8 *)(lVar14 + -0x28 + lVar7);
            uVar8 = puVar1[1];
            puVar2 = (undefined8 *)(lVar11 + 0x10 + uVar9);
            *puVar2 = *puVar1;
            puVar2[1] = uVar8;
            puVar1 = (undefined8 *)(lVar14 + -0x18 + lVar7);
            uVar8 = puVar1[1];
            puVar2 = (undefined8 *)(lVar11 + 0x20 + uVar9);
            *puVar2 = *puVar1;
            puVar2[1] = uVar8;
            *(undefined8 *)(lVar11 + 0x30 + uVar9) = *(undefined8 *)(lVar14 + -8 + lVar7);
            *(short *)((longlong)param_1 + 10) = *(short *)((longlong)param_1 + 10) + -1;
          } while ((uint)uVar15 < (uint)param_2[3]);
          uStack_60 = CONCAT44(iVar12,uVar6);
        }
        local_58 = (undefined4)uVar9;
        uStack_54 = (undefined4)(uVar9 >> 0x20);
        local_98._8_8_ = 0;
        local_98._0_8_ = uVar9;
        goto LAB_140002caa;
      }
      uVar13 = 0xc0000017;
    }
    else {
LAB_140002cbe:
      uVar9 = 0;
      local_68 = 0;
      local_78 = local_68;
LAB_140002d32:
      if (local_78 != 1) {
        return uVar13;
      }
    }
    if (uVar9 != 0) {
      ExFreePoolWithTag(uVar9,0);
    }
  }
  return uVar13;
}



===== EaiEnableAggregateEvent @ 140002de8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EaiEnableAggregateEvent
              (longlong param_1,undefined8 param_2,longlong param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 auStackY_d8 [32];
  uint local_a8 [2];
  longlong local_a0;
  undefined4 local_98;
  int local_94;
  longlong local_90;
  longlong local_88;
  undefined8 local_80;
  undefined8 local_78 [4];
  longlong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  int *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  longlong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_98 = 0x1000;
  lVar4 = 0;
  lVar5 = param_1 + 0x50;
  local_a8[0] = 0;
  iVar3 = 0;
  local_80 = 0;
  EaLibAcquireLockExclusive(lVar5);
  if (4 < DAT_14000e000) {
    local_4c = 0;
    local_58 = &local_a0;
    local_50 = 8;
    local_a0 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(lVar5,&DAT_14000cbb2,param_3,param_4,3,local_78);
  }
  if (*(int *)(param_1 + 0x6c) == 0) {
    param_3 = 0x41747645;
    lVar4 = ExAllocatePool2(0x100,0x1000);
    if (lVar4 == 0) {
      iVar3 = -0x3fffffe9;
      goto LAB_140002f5b;
    }
    *(undefined8 *)(param_1 + 0x70) = 0;
    lVar5 = **(longlong **)(param_1 + 0x38);
    iVar3 = 0;
    if (lVar5 == 0) {
LAB_140002f0a:
      if (*(longlong *)(*(longlong *)(param_1 + 0x38) + 8) != 0) {
        iVar3 = EaiSetAggregateConditionsEnabledState(param_1,1,param_3,param_4);
        if (iVar3 < 0) goto LAB_140002f25;
      }
      *(undefined4 *)(param_1 + 0x6c) = 1;
      goto LAB_140002f5b;
    }
    iVar1 = *(int *)(lVar5 + 8);
    iVar2 = *(int *)(**(longlong **)(param_1 + 0x38) + 0xc);
    local_80 = CONCAT44(iVar2,iVar1);
    if ((iVar1 == 0) && (iVar2 == 0)) goto LAB_140002f0a;
    if ((*(uint *)(param_1 + 0x8c) & 2) == 0) {
LAB_140002eed:
      param_4 = (undefined4 *)(ulonglong)local_a8[0];
      param_3 = local_80;
      iVar3 = EaLibSubscribeWnfStateChangeNotification
                        (param_1,**(undefined8 **)(param_1 + 0x38),local_80);
      if (-1 < iVar3) goto LAB_140002f0a;
    }
    else {
      param_4 = &local_98;
      param_3 = lVar4;
      iVar3 = EaLibQueryWnfStateData(&local_80,local_a8,lVar4,param_4);
      if (-1 < iVar3) goto LAB_140002eed;
    }
LAB_140002f25:
    EaLibReleaseLockExclusive(param_1 + 0x50);
    if (((longlong *)**(longlong **)(param_1 + 0x38) != (longlong *)0x0) &&
       (*(longlong *)**(longlong **)(param_1 + 0x38) != 0)) {
      EaLibUnsubscribeWnfStateChangeNotification();
      *(undefined8 *)**(undefined8 **)(param_1 + 0x38) = 0;
    }
  }
  else {
LAB_140002f5b:
    lVar5 = param_1 + 0x50;
    EaLibReleaseLockExclusive(lVar5);
    if (lVar4 == 0) goto LAB_140002f7a;
  }
  lVar5 = lVar4;
  ExFreePoolWithTag(lVar5,0);
LAB_140002f7a:
  if (4 < DAT_14000e000) {
    local_4c = 0;
    local_58 = &local_90;
    local_3c = 0;
    local_2c = 0;
    local_1c = 0;
    local_88 = local_80;
    local_48 = &local_88;
    local_38 = &local_94;
    local_a0 = CONCAT44(local_a0._4_4_,local_a8[0]);
    local_28 = &local_a0;
    local_50 = 8;
    local_40 = 8;
    local_30 = 4;
    local_20 = 4;
    local_94 = iVar3;
    local_90 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(lVar5,&DAT_14000cc94,param_3,param_4,6,local_78);
  }
  return iVar3;
}



===== EaiEvaluateAggregationConditionVisitNode @ 140003030 =====

undefined8 EaiEvaluateAggregationConditionVisitNode(longlong *param_1,int *param_2)

{
  byte bVar1;
  byte bVar2;
  void *_Dst;
  undefined8 uVar3;
  ushort uVar4;
  ushort uVar5;
  byte bVar6;
  
  uVar3 = 0;
  if (*param_2 == 0) {
    bVar6 = *(byte *)(param_2 + 8);
LAB_1400030bb:
    if (*(ushort *)((longlong)param_1 + 10) == *(ushort *)(param_1 + 1)) {
      _Dst = (void *)ExAllocatePool2(0x100,(ulonglong)*(ushort *)(param_1 + 1) + 5,0x41747645);
      if (_Dst == (void *)0x0) {
        return 0xc0000017;
      }
      if ((void *)*param_1 != (void *)0x0) {
        memmove(_Dst,(void *)*param_1,(ulonglong)*(ushort *)(param_1 + 1));
        ExFreePoolWithTag(*param_1,0);
      }
      *(short *)(param_1 + 1) = (short)param_1[1] + 5;
      *param_1 = (longlong)_Dst;
    }
    *(byte *)((ulonglong)*(ushort *)((longlong)param_1 + 10) + *param_1) = bVar6;
    *(short *)((longlong)param_1 + 10) = *(short *)((longlong)param_1 + 10) + 1;
  }
  else {
    if (*param_2 == 1) {
      bVar6 = param_2[2] == 0;
      uVar4 = *(ushort *)((longlong)param_1 + 10);
      if ((uint)param_2[3] <= (uint)uVar4) {
        uVar5 = 0;
        if (param_2[3] != 0) {
          do {
            bVar1 = *(byte *)(((ulonglong)uVar4 - 1) + *param_1);
            bVar2 = bVar1 | bVar6;
            bVar6 = bVar1 & bVar6;
            if (param_2[2] != 0) {
              bVar6 = bVar2;
            }
            uVar5 = uVar5 + 1;
            uVar4 = uVar4 - 1;
            *(ushort *)((longlong)param_1 + 10) = uVar4;
          } while ((uint)uVar5 < (uint)param_2[3]);
        }
        goto LAB_1400030bb;
      }
    }
    uVar3 = 0xc00000e5;
  }
  return uVar3;
}



===== EaiEvaluateConditions @ 140003158 =====

undefined1 EaiEvaluateConditions(longlong param_1)

{
  int iVar1;
  undefined1 uVar2;
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong local_38;
  longlong *local_30;
  code *local_28;
  undefined8 local_20;
  undefined8 local_18;
  code *local_10;
  
  local_3c = 0;
  uVar2 = 1;
  if (*(longlong *)(*(longlong *)(param_1 + 0x38) + 8) != 0) {
    local_30 = &local_48;
    local_48 = 0;
    local_28 = EaiAggregationConditionNextChild;
    local_40 = 0;
    local_10 = EaiEvaluateAggregationConditionVisitNode;
    local_20 = 0;
    local_18 = 0;
    local_38 = param_1;
    iVar1 = EapTreeTraverse(&local_30,*(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8));
    if (-1 < iVar1) {
      uVar2 = *(undefined1 *)(((ulonglong)local_40._2_2_ - 1) + local_48);
      local_40 = CONCAT22(local_40._2_2_ - 1,(undefined2)local_40);
    }
    if (local_48 != 0) {
      ExFreePoolWithTag(local_48,0);
    }
  }
  return uVar2;
}



===== EaiExtractEventAggregation @ 140003204 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong EaiExtractEventAggregation
                    (longlong param_1,char param_2,undefined8 *param_3,undefined8 param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  undefined1 auStackY_a8 [32];
  longlong local_78;
  longlong local_70;
  undefined8 local_68 [4];
  longlong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_78 = 0;
  puVar3 = param_3;
  if ((param_1 == 0) || (param_3 == (undefined8 *)0x0)) {
    uVar2 = 0xc000000d;
  }
  else {
    uVar1 = EaiFindAndAcquireAggregateEvent(param_1,&local_78);
    uVar2 = uVar1 & 0xffffffff;
    if ((int)uVar1 < 0) {
      uVar2 = 0xc0000225;
    }
    else {
      *param_3 = *(undefined8 *)(local_78 + 0x38);
      if (param_2 != '\0') {
        *(uint *)(local_78 + 0x8c) = *(uint *)(local_78 + 0x8c) | 8;
      }
    }
    if (local_78 != 0) {
      EaiReleaseAggregateEvent(local_78);
    }
    if (-1 < (int)uVar2) {
      return uVar2;
    }
  }
  if (2 < DAT_14000e000) {
    local_3c = 0;
    local_48 = &local_70;
    local_2c = 0;
    local_38 = &local_78;
    local_40 = 8;
    local_78 = CONCAT44(local_78._4_4_,(int)uVar2);
    local_30 = 4;
    local_70 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_14000c86e,puVar3,param_4,4,local_68);
  }
  return uVar2;
}



===== EaiFindAndAcquireAggregateEvent @ 140003304 =====

undefined8 EaiFindAndAcquireAggregateEvent(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  
  EaLibAcquireLockShared(&AggregateEventListLock);
  if ((DAT_14000e0c0 == 0) || (lVar1 = RtlLookupEntryHashTable(DAT_14000e0c0,param_1,0), lVar1 == 0)
     ) {
    EaLibReleaseLockShared(&AggregateEventListLock);
    return 0xc0000008;
  }
  LOCK();
  *(int *)(lVar1 + 0x88) = *(int *)(lVar1 + 0x88) + 1;
  UNLOCK();
  EaLibReleaseLockShared(&AggregateEventListLock);
  *param_2 = lVar1;
  return 0;
}



===== EaiFreeAggregationConditionVisitNode @ 140003390 =====

undefined8 EaiFreeAggregationConditionVisitNode(undefined8 param_1,int *param_2)

{
  if (*param_2 != 0) {
    if (*param_2 != 1) {
      return 0xc00000e5;
    }
    ExFreePoolWithTag(*(undefined8 *)(param_2 + 4));
    param_2[4] = 0;
    param_2[5] = 0;
  }
  return 0;
}



===== EaiFreeEaAggregateEvent @ 1400033d4 =====

int EaiFreeEaAggregateEvent(undefined8 *param_1)

{
  longlong *plVar1;
  int iVar2;
  undefined8 local_38;
  code *local_30;
  undefined8 local_28;
  undefined8 local_20;
  code *local_18;
  
  iVar2 = 0;
  if (param_1 == (undefined8 *)0x0) {
    iVar2 = -0x3ffffff3;
  }
  else {
    plVar1 = (longlong *)*param_1;
    if (*plVar1 != 0) {
      ExFreePoolWithTag(*plVar1,0);
      *plVar1 = 0;
    }
    if (plVar1[1] != 0) {
      local_38 = 0;
      local_28 = 0;
      local_20 = 0;
      local_30 = EaiAggregationConditionNextChild;
      local_18 = EaiFreeAggregationConditionVisitNode;
      iVar2 = EapTreeTraverse(&local_38,plVar1[1]);
      ExFreePoolWithTag(plVar1[1],0);
      plVar1[1] = 0;
    }
    ExFreePoolWithTag(plVar1,0);
    *param_1 = 0;
  }
  return iVar2;
}



===== EaiFreeTriggerPayload @ 140003494 =====

void EaiFreeTriggerPayload(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x60) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x60),0);
    *(undefined8 *)(param_1 + 0x60) = 0;
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  return;
}



===== EaiHandleTimeLimitReached @ 1400034cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EaiHandleTimeLimitReached
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 auStackY_b8 [32];
  uint local_78 [2];
  longlong local_70 [3];
  undefined8 local_58 [4];
  longlong *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  uint *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_70[1] = 0;
  if (*(char *)(param_1 + 0x78) != '\0') {
    if (4 < DAT_14000e000) {
      local_2c = 0;
      local_38 = local_70;
      local_30 = 8;
      local_78[0] = *(uint *)(*(longlong *)(param_1 + 0x38) + 0x20);
      local_28 = local_78;
      local_1c = 0;
      local_20 = 4;
      local_70[0] = param_1;
      _tlgWriteTransfer_EtwWriteTransfer
                ((ulonglong)local_78[0],&DAT_14000cf0f,param_3,param_4,4,local_58);
    }
    EaiSignalCallback(1,param_1,local_70 + 1,(longlong *)0x0,0,0);
    *(undefined1 *)(param_1 + 0x41) = 0;
    *(undefined1 *)(param_1 + 0x78) = 0;
  }
  return;
}



===== EaiProcessNotification @ 1400035a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong EaiProcessNotification
                    (longlong param_1,longlong *param_2,longlong *param_3,longlong *param_4,
                    longlong *param_5,uint param_6,uint param_7,undefined4 *param_8)

{
  char cVar1;
  longlong lVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  ulonglong uVar6;
  int iVar7;
  int iVar8;
  ulonglong uVar9;
  undefined1 auStackY_198 [32];
  char local_158;
  byte local_157;
  char local_156;
  int local_154;
  uint local_150;
  uint local_14c;
  uint local_148 [2];
  longlong local_140;
  longlong local_138;
  uint local_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  uint *local_120;
  code *local_118;
  undefined8 local_110;
  undefined8 local_108;
  code *local_100;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined8 local_e8 [4];
  longlong *local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  uint *local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  char *local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  int *local_98;
  undefined4 local_90;
  undefined4 local_8c;
  uint *local_88;
  undefined4 local_80;
  undefined4 local_7c;
  uint *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  uint *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_198;
  local_156 = *(char *)(param_1 + 0x40);
  uVar9 = 0;
  cVar4 = (char)param_4;
  local_157 = (byte)param_3;
  local_158 = cVar4;
  if (4 < DAT_14000e000) {
    local_f4 = 0;
    local_100 = (code *)&local_140;
    local_f8 = 8;
    local_140 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000cd18,param_3,param_4,3,&local_120);
  }
  EaLibAcquireLockExclusive(param_1 + 0x50);
  EaLibClearAndReleaseTimer(param_1);
  iVar8 = *(int *)(param_1 + 0x6c);
  local_154 = iVar8;
  if (iVar8 == 0) {
    iVar7 = 0;
    goto LAB_140003958;
  }
  lVar2 = **(longlong **)(param_1 + 0x38);
  if (((lVar2 == 0) || ((int)*param_2 != *(int *)(lVar2 + 8))) ||
     (*(int *)((longlong)param_2 + 4) != *(int *)(lVar2 + 0xc))) {
    uStack_12c = (undefined4)*param_2;
    uStack_128 = (undefined4)((ulonglong)*param_2 >> 0x20);
    local_130 = (uint)(cVar4 != '\0');
    local_110 = 0;
    local_120 = &local_130;
    local_108 = 0;
    local_118 = EaiAggregationConditionNextChild;
    local_100 = EaiSetAggregationConditionVisitNode;
    uVar5 = EapTreeTraverse(&local_120,(*(longlong **)(param_1 + 0x38))[1]);
    uVar9 = 0;
    if ((int)uVar5 < 0) {
      uVar9 = (ulonglong)uVar5;
    }
    iVar7 = 0;
    if (-1 < (int)uVar9) {
      cVar4 = EaiEvaluateConditions(param_1);
      if (*(char *)(param_1 + 0x40) == '\x01') {
        if ((cVar4 != '\0') && (*(char *)(param_1 + 0x41) == '\0')) {
          param_4 = *(longlong **)(param_1 + 0x60);
          param_3 = param_2;
          EaiSignalCallback(0,param_1,param_2,param_4,*(uint *)(param_1 + 0x68),param_7);
          *(undefined1 *)(param_1 + 0x41) = 1;
          EaLibCreateAndSetLimitTimer(param_1);
          EaiFreeTriggerPayload(param_1);
        }
        if (((*(char *)(param_1 + 0x40) == '\x01') && (cVar4 == '\0')) &&
           (*(char *)(param_1 + 0x41) != '\0')) {
          param_4 = (longlong *)0x0;
          param_3 = param_2;
          EaiSignalCallback(1,param_1,param_2,(longlong *)0x0,0,param_7);
          *(undefined1 *)(param_1 + 0x41) = 0;
          lVar2 = **(longlong **)(param_1 + 0x38);
          if ((lVar2 != 0) && ((*(int *)(lVar2 + 8) != 0 || (*(int *)(lVar2 + 0xc) != 0)))) {
            *(undefined1 *)(param_1 + 0x40) = 0;
          }
          EaiFreeTriggerPayload(param_1);
        }
      }
      iVar8 = local_154;
      cVar4 = local_158;
    }
    goto LAB_140003958;
  }
  cVar3 = EaiEvaluateConditions(param_1);
  if (local_157 == 0) {
    cVar1 = *(char *)(param_1 + 0x40);
    if (cVar4 == '\0') {
      if (cVar1 == '\0') {
        param_4 = (longlong *)0x0;
        iVar7 = 1;
        param_3 = param_2;
        EaiSignalCallback(1,param_1,param_2,(longlong *)0x0,0,param_7);
        goto LAB_140003958;
      }
      if (cVar1 == '\x01') {
        if (((*(uint *)(param_1 + 0x8c) & 1) == 0) || (*(char *)(param_1 + 0x41) != '\0')) {
          param_3 = param_2;
          EaiSignalCallback(1,param_1,param_2,param_5,param_6,param_7);
        }
        else {
          param_5 = *(longlong **)(param_1 + 0x60);
          param_3 = param_2;
          EaiSignalCallback(0,param_1,param_2,param_5,*(uint *)(param_1 + 0x68),param_7);
          EaLibCreateAndSetLimitTimer(param_1);
        }
        *(undefined2 *)(param_1 + 0x40) = 0;
        EaiFreeTriggerPayload(param_1);
        param_4 = param_5;
      }
    }
    else {
      if (cVar1 == '\0') {
        if (cVar3 != '\0') goto LAB_1400036a2;
      }
      else {
        if (cVar1 != '\x01') goto LAB_140003762;
        if (cVar3 != '\0') goto LAB_1400036a6;
      }
      uVar5 = *(uint *)(param_1 + 0x8c);
      if ((uVar5 & 4) == 0) goto LAB_1400036fb;
LAB_14000375b:
      if (param_8 != (undefined4 *)0x0) {
        *param_8 = 0;
      }
    }
  }
  else if (cVar3 == '\0') {
    if ((*(uint *)(param_1 + 0x8c) & 4) != 0) goto LAB_14000375b;
    if (param_8 != (undefined4 *)0x0) {
      *param_8 = 2;
    }
    uVar5 = *(uint *)(param_1 + 0x8c);
LAB_1400036fb:
    *(undefined1 *)(param_1 + 0x40) = 1;
    if (((uVar5 & 0x10) == 0) || (*(longlong *)(param_1 + 0x28) == 0)) {
      param_3 = (longlong *)(ulonglong)param_6;
      uVar6 = EaiResetTriggerPayload(param_1,param_5,param_6);
      uVar9 = uVar6 & 0xffffffff;
      iVar7 = 1;
      if ((int)uVar6 < 0) goto LAB_140003958;
    }
    else {
      param_3 = param_2;
      EaiSignalCallback(2,param_1,param_2,param_5,param_6,param_7);
      param_4 = param_5;
    }
  }
  else {
LAB_1400036a2:
    *(undefined1 *)(param_1 + 0x40) = 1;
LAB_1400036a6:
    param_3 = param_2;
    EaiSignalCallback(0,param_1,param_2,param_5,param_6,param_7);
    *(undefined1 *)(param_1 + 0x41) = 1;
    EaLibCreateAndSetLimitTimer(param_1);
    param_4 = param_5;
  }
LAB_140003762:
  iVar7 = 1;
LAB_140003958:
  EaLibReleaseLockExclusive(param_1 + 0x50);
  if (4 < DAT_14000e000) {
    local_bc = 0;
    local_ac = 0;
    local_c8 = &local_138;
    local_9c = 0;
    local_8c = 0;
    local_7c = 0;
    local_130 = (uint)*param_2;
    uStack_12c = (undefined4)((ulonglong)*param_2 >> 0x20);
    local_b8 = &local_130;
    local_a8 = &local_158;
    local_98 = &local_154;
    local_150 = (uint)local_157;
    local_88 = &local_150;
    local_c0 = 8;
    local_b0 = 8;
    local_6c = 0;
    local_14c = (uint)(local_156 != '\0');
    local_78 = &local_14c;
    local_158 = (char)iVar8;
    local_a0 = 1;
    local_5c = 0;
    local_4c = 0;
    local_148[0] = (uint)(cVar4 != '\0');
    local_68 = local_148;
    local_58 = &local_140;
    local_90 = 4;
    local_80 = 4;
    local_70 = 4;
    local_60 = 4;
    local_140 = CONCAT44(local_140._4_4_,(int)uVar9);
    local_50 = 4;
    local_154 = iVar7;
    local_138 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_14000cb27,param_3,param_4,10,local_e8);
  }
  return uVar9;
}



===== EaiReleaseAggregateEvent @ 140003a84 =====

void EaiReleaseAggregateEvent(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x88);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    EaiFreeTriggerPayload(param_1);
    if ((*(uint *)(param_1 + 0x8c) & 8) == 0) {
      EaiFreeEaAggregateEvent((undefined8 *)(param_1 + 0x38));
    }
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== EaiResetTriggerPayload @ 140003ad4 =====

undefined8 EaiResetTriggerPayload(longlong param_1,void *param_2,uint param_3)

{
  void *_Dst;
  undefined8 uVar1;
  
  EaiFreeTriggerPayload(param_1);
  uVar1 = 0;
  if (param_3 != 0) {
    _Dst = (void *)ExAllocatePool2(0x100,(ulonglong)param_3,0x41747645);
    if (_Dst == (void *)0x0) {
      uVar1 = 0xc0000017;
    }
    else {
      memmove(_Dst,param_2,(ulonglong)param_3);
      *(void **)(param_1 + 0x60) = _Dst;
      *(uint *)(param_1 + 0x68) = param_3;
    }
  }
  return uVar1;
}



===== EaiRunOnceCallback @ 140003b60 =====

bool EaiRunOnceCallback(void)

{
  char cVar1;
  
  EaLibLockInitialize((undefined8 *)&AggregateEventListLock);
  cVar1 = RtlCreateHashTable(&DAT_14000e0c0,0,0);
  return cVar1 != '\0';
}



===== EaiSetAggregateConditionsEnabledState @ 140003ba0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EaiSetAggregateConditionsEnabledState
              (longlong param_1,byte param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined1 auStackY_108 [32];
  uint local_d8;
  int local_d4;
  int local_d0 [2];
  longlong local_c8;
  ulonglong uStack_c0;
  longlong local_b8;
  longlong *local_b0;
  code *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  code *local_90;
  undefined8 local_88 [4];
  longlong *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  uint *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  int *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  int *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStackY_108;
  if (*(longlong *)(*(longlong *)(param_1 + 0x38) + 8) == 0) {
    iVar1 = 0;
  }
  else {
    local_a0 = 0;
    local_b0 = &local_c8;
    local_98 = 0;
    local_a8 = EaiAggregationConditionNextChild;
    uStack_c0 = (ulonglong)param_2;
    local_90 = EaiSetConditionsEnabledStateVisitNode;
    local_c8 = param_1;
    iVar1 = EapTreeTraverse(&local_b0,*(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8));
    if (iVar1 < 0) {
      uStack_c0 = CONCAT71(uStack_c0._1_7_,param_2 == 0);
      local_d0[0] = EapTreeTraverse(&local_b0,*(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8));
      if (2 < DAT_14000e000) {
        local_5c = 0;
        local_68 = &local_b8;
        local_4c = 0;
        local_3c = 0;
        local_2c = 0;
        local_38 = local_d0;
        local_58 = &local_d8;
        local_48 = &local_d4;
        local_50 = 4;
        local_40 = 4;
        local_30 = 4;
        local_60 = 8;
        local_d8 = (uint)param_2;
        local_d4 = iVar1;
        local_b8 = param_1;
        _tlgWriteTransfer_EtwWriteTransfer(local_48,&DAT_14000cac8,param_3,param_4,6,local_88);
      }
    }
  }
  return iVar1;
}



===== EaiSetAggregationConditionVisitNode @ 140003ce0 =====

undefined8 EaiSetAggregationConditionVisitNode(char *param_1,int *param_2)

{
  if (*param_2 == 0) {
    if ((*(int *)(param_1 + 4) == param_2[4]) && (*(int *)(param_1 + 8) == param_2[5])) {
      *(bool *)(param_2 + 8) = *param_1 == (char)param_2[0xc];
    }
  }
  else if (*param_2 != 1) {
    return 0xc00000e5;
  }
  return 0;
}



===== EaiSetConditionsEnabledStateVisitNode @ 140003d20 =====

undefined8 EaiSetConditionsEnabledStateVisitNode(undefined8 *param_1,int *param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  
  if (*param_2 == 0) {
    plVar1 = (longlong *)(param_2 + 2);
    if (*(char *)(param_1 + 1) == '\0') {
      if (*plVar1 != 0) {
        EaLibUnsubscribeWnfStateChangeNotification();
        *plVar1 = 0;
      }
    }
    else {
      uVar2 = EaLibSubscribeWnfStateChangeNotification(*param_1,plVar1,*(undefined8 *)(param_2 + 4))
      ;
      *(undefined1 *)(param_2 + 8) = 0;
      if ((int)uVar2 < 0) {
        return uVar2;
      }
    }
  }
  else if (*param_2 != 1) {
    return 0xc00000e5;
  }
  return 0;
}



===== EaiSignalAggregateCallback @ 140003d9c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EaiSignalAggregateCallback
               (longlong param_1,longlong *param_2,undefined *param_3,undefined8 param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined *puVar3;
  undefined1 auStackY_98 [32];
  longlong local_68;
  undefined8 local_60 [4];
  longlong *local_40;
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_98;
  lVar2 = param_1;
  puVar3 = param_3;
  uVar1 = param_4;
  if (4 < DAT_14000e000) {
    local_34 = 0;
    local_40 = &local_68;
    local_38 = 8;
    local_68 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000ca0e,param_3,param_4,3,local_60);
  }
  if (param_3 != (undefined *)0x0) {
    local_68 = *param_2;
    *(undefined4 *)(param_1 + 0x6c) = 2;
    uVar1 = EaLibGetCurrentThreadId();
    *(undefined8 *)(param_1 + 0x70) = uVar1;
    EaLibReleaseLockExclusive(param_1 + 0x50);
    puVar3 = *(undefined **)(param_1 + 0x48);
    (*(code *)param_3)(param_1,local_68);
    lVar2 = param_1 + 0x50;
    EaLibAcquireLockExclusive(lVar2);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar1 = param_4;
    if (*(int *)(param_1 + 0x6c) == 2) {
      *(undefined4 *)(param_1 + 0x6c) = 1;
    }
  }
  if (4 < DAT_14000e000) {
    local_34 = 0;
    local_40 = &local_68;
    local_38 = 8;
    local_68 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(lVar2,&DAT_14000c8ac,puVar3,uVar1,3,local_60);
  }
  return;
}



===== EaiSignalAggregateEvent @ 140003ec0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EaiSignalAggregateEvent
               (longlong param_1,int param_2,longlong *param_3,longlong *param_4,uint param_5,
               uint param_6)

{
  undefined8 uVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined1 auStackY_e8 [32];
  longlong local_a8;
  longlong local_a0;
  longlong local_98 [2];
  undefined8 local_88 [4];
  longlong *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  longlong *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  plVar3 = param_3;
  plVar4 = param_4;
  if (4 < DAT_14000e000) {
    local_5c = 0;
    local_68 = &local_a8;
    local_60 = 8;
    local_a8 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000c80a,param_3,param_4,3,local_88);
  }
  local_a8 = *param_3;
  if (*(int *)(param_1 + 0x6c) == 1) {
    *(undefined4 *)(param_1 + 0x6c) = 2;
  }
  uVar1 = EaLibGetCurrentThreadId();
  *(undefined8 *)(param_1 + 0x70) = uVar1;
  EaLibReleaseLockExclusive(param_1 + 0x50);
  if (param_2 == 0) {
    if (*(code **)(param_1 + 0x18) != (code *)0x0) {
      plVar3 = *(longlong **)(param_1 + 0x48);
      (**(code **)(param_1 + 0x18))(param_1,local_a8);
      plVar4 = param_4;
    }
    goto LAB_140003ff0;
  }
  if (param_2 == 1) {
    pcVar2 = *(code **)(param_1 + 0x20);
  }
  else {
    if (param_2 == 2) {
      if (*(code **)(param_1 + 0x28) != (code *)0x0) {
        plVar4 = (longlong *)(ulonglong)param_5;
        (**(code **)(param_1 + 0x28))(param_1,*(undefined8 *)(param_1 + 0x48));
        plVar3 = param_4;
      }
      goto LAB_140003ff0;
    }
    if (param_2 != 3) goto LAB_140003ff0;
    pcVar2 = *(code **)(param_1 + 0x30);
  }
  if (pcVar2 != (code *)0x0) {
    plVar4 = (longlong *)(ulonglong)param_6;
    plVar3 = *(longlong **)(param_1 + 0x48);
    (*pcVar2)(param_1,local_a8);
  }
LAB_140003ff0:
  EaLibAcquireLockExclusive(param_1 + 0x50);
  *(undefined8 *)(param_1 + 0x70) = 0;
  if (*(int *)(param_1 + 0x6c) == 2) {
    *(undefined4 *)(param_1 + 0x6c) = 1;
  }
  if (4 < DAT_14000e000) {
    local_5c = 0;
    local_68 = &local_a0;
    local_4c = 0;
    local_3c = 0;
    local_98[0] = *param_3;
    local_58 = local_98;
    local_48 = &local_a8;
    local_60 = 8;
    local_50 = 8;
    local_a8 = CONCAT44(local_a8._4_4_,param_2);
    local_40 = 4;
    local_a0 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(8,&DAT_14000c786,plVar3,plVar4,5,local_88);
  }
  return;
}



===== EaiSignalCallback @ 1400040a4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EaiSignalCallback(longlong param_1,longlong param_2,longlong *param_3,longlong *param_4,
                      uint param_5,uint param_6)

{
  longlong lVar1;
  int iVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined1 auStackY_f8 [32];
  uint local_b8 [2];
  longlong local_b0;
  longlong local_a8 [2];
  undefined8 local_98 [4];
  longlong *local_78;
  undefined4 local_70;
  undefined4 local_6c;
  uint *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  longlong *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_f8;
  lVar1 = param_1;
  plVar3 = param_3;
  plVar4 = param_4;
  if (4 < DAT_14000e000) {
    local_6c = 0;
    local_78 = &local_b0;
    local_70 = 8;
    local_b0 = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000ca7f,param_3,param_4,3,local_98);
  }
  iVar2 = (int)param_1;
  if ((*(uint *)(param_2 + 0x8c) & 0x10) == 0) {
    if (iVar2 == 0) {
      plVar3 = *(longlong **)(param_2 + 0x18);
    }
    else {
      if (iVar2 != 1) goto LAB_14000416a;
      plVar3 = *(longlong **)(param_2 + 0x20);
    }
    lVar1 = param_2;
    EaiSignalAggregateCallback(param_2,param_3,(undefined *)plVar3,param_4);
    plVar4 = param_4;
  }
  else {
    lVar1 = param_2;
    EaiSignalAggregateEvent(param_2,iVar2,param_3,param_4,param_5,param_6);
    plVar3 = param_3;
    plVar4 = param_4;
  }
LAB_14000416a:
  if (4 < DAT_14000e000) {
    local_6c = 0;
    local_78 = local_a8;
    local_5c = 0;
    local_4c = 0;
    local_b8[0] = *(uint *)(param_2 + 0x8c) >> 4 & 1;
    local_68 = local_b8;
    local_58 = &local_b0;
    local_70 = 8;
    local_60 = 4;
    local_b0 = CONCAT44(local_b0._4_4_,iVar2);
    local_50 = 4;
    local_a8[0] = param_2;
    _tlgWriteTransfer_EtwWriteTransfer(lVar1,&DAT_14000c989,plVar3,plVar4,5,local_98);
  }
  return;
}



===== EaiValidateParameters @ 140004204 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
EaiValidateParameters(int *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  if (param_1 == (int *)0x0) {
    local_48[0] = 100;
    goto LAB_140004275;
  }
  if ((param_1[2] & 0xfffffff0U) != 0) {
    local_48[0] = 200;
    goto LAB_140004275;
  }
  uVar1 = param_1[3];
  if (uVar1 < 0x21) {
    if ((*param_1 == 0) && (param_1[1] == 0)) {
      if (uVar1 == 0) goto LAB_14000423d;
LAB_140004257:
      if (*(longlong *)(param_1 + 4) == 0) {
        local_48[0] = 400;
        goto LAB_140004275;
      }
    }
    else if (uVar1 != 0) goto LAB_140004257;
    if ((*(longlong *)(param_1 + 8) != 0) || (*(longlong *)(param_1 + 10) != 0)) {
      return 1;
    }
    local_48[0] = 500;
  }
  else {
LAB_14000423d:
    local_48[0] = 300;
  }
LAB_140004275:
  if (2 < DAT_14000e000) {
    local_20 = local_48;
    local_18 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000c591,param_3,param_4,3,local_40);
  }
  return 0;
}



===== EventAggregationCaptureStateCallback @ 1400042e0 =====

void EventAggregationCaptureStateCallback
               (undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (param_2 == 2) {
    EaLibAcquireLockShared(&AggregateEventListLock);
    if ((DAT_14000e0c0 != 0) &&
       (cVar1 = RtlInitEnumerationHashTable(DAT_14000e0c0,&local_38), cVar1 != '\0')) {
      while( true ) {
        puVar3 = &local_38;
        lVar2 = RtlEnumerateEntryHashTable(DAT_14000e0c0);
        if (lVar2 == 0) break;
        EaiDumpAggregateEvent(lVar2,puVar3,param_3,param_4);
      }
      RtlEndEnumerationHashTable(DAT_14000e0c0,&local_38);
    }
    EaLibReleaseLockShared(&AggregateEventListLock);
  }
  return;
}



===== WnfEventCallback @ 140004384 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
WnfEventCallback(longlong param_1,longlong *param_2,ulonglong param_3,uint *param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  longlong *plVar9;
  longlong *plVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  byte bVar14;
  bool bVar15;
  undefined1 auStackY_198 [32];
  uint local_158 [2];
  undefined4 local_150 [2];
  uint local_148;
  uint local_144;
  uint *local_140;
  longlong local_138;
  longlong local_130;
  longlong local_128 [2];
  undefined8 local_118 [4];
  longlong *local_f8;
  undefined8 local_f0;
  longlong *local_e8;
  undefined8 local_e0;
  uint *local_d8;
  undefined8 local_d0;
  uint *local_c8;
  undefined8 local_c0;
  uint *local_b8;
  undefined8 local_b0;
  uint **local_a8;
  undefined8 local_a0;
  longlong *local_98;
  undefined8 local_90;
  undefined4 *local_88;
  undefined8 local_80;
  undefined8 local_78 [4];
  longlong *local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_198;
  local_158[0] = (uint)param_3;
  local_140 = param_4;
  if (4 < DAT_14000e000) {
    local_58 = &local_138;
    local_50 = 8;
    local_138 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_14000cce9,param_3,param_4,3,local_78);
    param_3 = (ulonglong)local_158[0];
  }
  iVar3 = 0;
  uVar12 = 0;
  uVar13 = 0;
  bVar14 = 0;
  if ((int)param_3 == 0) {
    EaLibAcquireLockExclusive(param_1 + 0x50);
    plVar10 = (longlong *)0x0;
    plVar9 = param_2;
    EaiSignalCallback(3,param_1,param_2,(longlong *)0x0,0,0);
    lVar6 = param_1 + 0x50;
    EaLibReleaseLockExclusive(lVar6);
    if (4 < DAT_14000e000) {
      _tlgWriteTransfer_EtwWriteTransfer(lVar6,&DAT_14000caab,plVar9,plVar10,2,local_78);
    }
LAB_140004576:
    iVar3 = 0;
    uVar7 = 0;
  }
  else {
    plVar10 = (longlong *)(ulonglong)param_5;
    if (param_5 < 8) {
      uVar7 = 10;
      goto LAB_14000457d;
    }
    uVar1 = *local_140;
    uVar5 = uVar1 >> 0x17 & 1;
    bVar15 = (uVar1 >> 0x18 & 1) == 0;
    uVar2 = uVar5 + 1;
    if (bVar15) {
      uVar2 = uVar5;
    }
    uVar11 = uVar5 | 2;
    if (bVar15) {
      uVar11 = uVar5;
    }
    if (uVar2 == 0) {
LAB_1400044f1:
      if (plVar10 < (longlong *)(((ulonglong)(uVar1 >> 2) & 0xfff) + 8)) {
        uVar7 = 0x28;
      }
      else {
        uVar12 = uVar1 >> 2 & 0xfff;
        uVar13 = uVar1 & 1;
        bVar14 = (byte)(uVar1 >> 1);
        plVar10 = (longlong *)
                  ((ulonglong)CONCAT31((int3)(param_5 >> 8),bVar14) & 0xffffffffffffff01);
        uVar4 = EaiProcessNotification
                          (param_1,param_2,(longlong *)CONCAT71(0xf,(byte)uVar13 ^ 1),plVar10,
                           (longlong *)(-(ulonglong)(uVar12 != 0) & (ulonglong)(local_140 + 2)),
                           uVar1 >> 2 & 0xfff,uVar11,(undefined4 *)0x0);
        bVar14 = bVar14 & 1;
        iVar3 = (int)uVar4;
        if (-1 < iVar3) goto LAB_140004576;
        uVar7 = 0x32;
      }
    }
    else if (plVar10 < (longlong *)((ulonglong)uVar2 * 0x10 + 8)) {
      uVar7 = 0x14;
    }
    else {
      if (((uVar1 & 0x3ffc) == 0) || ((ulonglong)uVar2 * 0x10 <= (ulonglong)(uVar1 >> 2 & 0xfff)))
      goto LAB_1400044f1;
      uVar7 = 0x1e;
    }
  }
  param_3 = (ulonglong)local_158[0];
LAB_14000457d:
  if (4 < DAT_14000e000) {
    local_f8 = &local_130;
    local_d0 = 4;
    local_128[0] = *param_2;
    local_e8 = local_128;
    local_d8 = local_158;
    local_c8 = &local_148;
    local_b8 = &local_144;
    local_140 = (uint *)CONCAT44(local_140._4_4_,(uint)bVar14);
    local_a8 = &local_140;
    local_98 = &local_138;
    local_88 = local_150;
    local_c0 = 4;
    local_b0 = 4;
    local_a0 = 4;
    local_90 = 4;
    local_80 = 4;
    local_f0 = 8;
    local_e0 = 8;
    local_158[0] = (uint)param_3;
    local_138 = CONCAT44(local_138._4_4_,iVar3);
    local_150[0] = (undefined4)uVar7;
    local_148 = uVar12;
    local_144 = uVar13;
    local_130 = param_1;
    _tlgWriteTransfer_EtwWriteTransfer(uVar7,&DAT_14000cbe8,param_3,plVar10,10,local_118);
  }
  uVar8 = 0;
  if (iVar3 == -0x3fffffe9) {
    uVar8 = 0xc0000017;
  }
  return uVar8;
}



===== _tlgDefineProvider_annotation__TlgghEventAggregationProviderProv @ 140004684 =====

void _tlgDefineProvider_annotation__TlgghEventAggregationProviderProv(void)

{
  return;
}



===== EaCreateAggregatedEvent @ 140004690 =====

ulonglong EaCreateAggregatedEvent
                    (longlong *param_1,uint param_2,longlong param_3,longlong *param_4,
                    undefined4 *param_5,longlong param_6,longlong param_7,uint param_8,
                    undefined8 *param_9)

{
  uint uVar1;
  ulonglong uVar2;
  longlong *plVar3;
  ulonglong uVar4;
  longlong *local_18 [2];
  
                    /* 0x4690  15  EaCreateAggregatedEvent */
  local_18[0] = (longlong *)0x0;
  uVar2 = EapCreateAggregatedEvent(param_1,param_2,local_18);
  plVar3 = local_18[0];
  uVar4 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    uVar1 = EaiCreateAggregation
                      (local_18[0],param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    uVar4 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      plVar3 = (longlong *)0x0;
    }
  }
  if (plVar3 != (longlong *)0x0) {
    EapDeleteAggregatedEvent(plVar3,param_2 & 1);
  }
  return uVar4;
}



===== EaDeleteAggregatedEvent @ 140004760 =====

ulonglong EaDeleteAggregatedEvent
                    (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined4 extraout_var;
  undefined8 uVar3;
  longlong **pplVar4;
  longlong *local_res8;
  
                    /* 0x4760  18  EaDeleteAggregatedEvent */
  local_res8 = (longlong *)0x0;
  if (param_1 == 0) {
    uVar2 = 0xc000000d;
  }
  else {
    pplVar4 = &local_res8;
    uVar3 = CONCAT71((int7)((ulonglong)param_2 >> 8),1);
    uVar2 = EaiExtractEventAggregation(param_1,'\x01',pplVar4,param_4);
    if (-1 < (int)uVar2) {
      iVar1 = EaDeleteAggregation(param_1,uVar3,pplVar4,param_4);
      uVar2 = CONCAT44(extraout_var,iVar1);
      if (-1 < iVar1) {
        uVar2 = EapDeleteAggregatedEvent(local_res8,(uint)param_2);
      }
    }
  }
  return uVar2;
}



===== EapFreeAggregatedEventConditionNextChild @ 1400047c0 =====

undefined8
EapFreeAggregatedEventConditionNextChild
          (undefined8 param_1,int *param_2,ushort param_3,longlong *param_4)

{
  *param_4 = 0;
  if ((*param_2 == 1) && ((uint)param_3 < (uint)param_2[3])) {
    *param_4 = *(longlong *)(param_2 + 4) + (ulonglong)param_3 * 0x28;
  }
  return 0;
}



===== EapCreateAggregatedEvent @ 1400047f0 =====

ulonglong EapCreateAggregatedEvent(longlong *param_1,uint param_2,undefined8 *param_3)

{
  uint uVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (((param_1 == (longlong *)0x0) || (param_3 == (undefined8 *)0x0)) ||
     ((*param_1 == 0 && (param_1[1] == 0)))) {
    return 0xc000000d;
  }
  plVar2 = (longlong *)ExAllocatePool2(0x100,0x38,0x41747645);
  if (plVar2 == (longlong *)0x0) {
    return 0xc0000017;
  }
  *plVar2 = 0;
  plVar2[1] = 0;
  plVar2[2] = 0;
  plVar2[3] = 0;
  plVar2[4] = 0;
  plVar2[5] = 0;
  plVar2[6] = 0;
  plVar2[5] = param_1[5];
  plVar2[6] = param_1[6];
  plVar2[2] = param_1[2];
  plVar2[3] = param_1[3];
  *(int *)(plVar2 + 4) = (int)param_1[4];
  if (*param_1 == 0) {
LAB_140004946:
    if (param_1[1] != 0) {
      puVar3 = (undefined8 *)ExAllocatePool2(0x100,0x38,0x41747645);
      plVar2[1] = (longlong)puVar3;
      if (puVar3 == (undefined8 *)0x0) goto LAB_1400048d6;
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = 0;
      puVar3[5] = 0;
      puVar3[6] = 0;
      uVar1 = EapCreateAggregatedEventCondition((longlong)param_1,param_2,(undefined8 *)plVar2[1]);
      uVar5 = (ulonglong)uVar1;
      if ((int)uVar1 < 0) goto LAB_14000499c;
    }
    *param_3 = plVar2;
    uVar5 = 0;
  }
  else {
    puVar3 = (undefined8 *)ExAllocatePool2(0x100,0x28,0x41747645);
    *plVar2 = (longlong)puVar3;
    if (puVar3 == (undefined8 *)0x0) {
LAB_1400048d6:
      uVar5 = 0xc0000017;
    }
    else {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      puVar3[3] = 0;
      puVar3[4] = 0;
      uVar4 = BriCreateBrokeredEventEx
                        ((UUID *)*param_1,param_1[7],param_1[8],(UUID *)*param_1 + 1,param_2,0,
                         (undefined8 *)(*plVar2 + 8),&local_38,0);
      uVar5 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        *(undefined4 *)(*plVar2 + 0x10) = (undefined4)local_38;
        *(undefined4 *)(*plVar2 + 0x14) = (undefined4)uStack_30;
        goto LAB_140004946;
      }
    }
LAB_14000499c:
    EapDeleteAggregatedEvent(plVar2,param_2 & 1);
  }
  return uVar5;
}



===== EapCreateAggregatedEventCondition @ 1400049dc =====

int EapCreateAggregatedEventCondition(longlong param_1,uint param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  int iVar3;
  longlong lVar4;
  ushort uVar5;
  longlong local_68;
  undefined8 local_60;
  longlong local_58;
  uint local_50;
  undefined4 local_4c;
  longlong *local_48;
  code *local_40;
  undefined8 local_38;
  undefined8 local_30;
  code *local_28;
  
  local_48 = &local_68;
  local_40 = EapFreeAggregatedEventConditionNextChild;
  local_60 = 0;
  local_28 = EapCreateAggregatedEventConditionVisitNode;
  local_4c = 0;
  local_68 = 0;
  local_38 = 0;
  local_30 = 0;
  local_58 = param_1;
  local_50 = param_2;
  iVar3 = EapTreeTraverse(&local_48,*(undefined8 *)(param_1 + 8));
  if (iVar3 < 0) {
    uVar5 = local_60._2_2_;
  }
  else {
    iVar3 = 0;
    lVar4 = (ulonglong)local_60._2_2_ * 0x38;
    uVar5 = local_60._2_2_ - 1;
    puVar1 = (undefined8 *)(lVar4 + -0x38 + local_68);
    uVar2 = puVar1[1];
    *param_3 = *puVar1;
    param_3[1] = uVar2;
    puVar1 = (undefined8 *)(lVar4 + -0x28 + local_68);
    uVar2 = puVar1[1];
    param_3[2] = *puVar1;
    param_3[3] = uVar2;
    puVar1 = (undefined8 *)(lVar4 + -0x18 + local_68);
    uVar2 = puVar1[1];
    param_3[4] = *puVar1;
    param_3[5] = uVar2;
    param_3[6] = *(undefined8 *)(lVar4 + -8 + local_68);
    local_60._0_4_ = CONCAT22(uVar5,(undefined2)local_60);
  }
  if (local_68 != 0) {
    while (uVar5 != 0) {
      EapDeleteAggregatedEventCondition((ulonglong)uVar5 * 0x38 + local_68 + -0x38,param_2 & 1);
      uVar5 = local_60._2_2_ - 1;
      local_60._0_4_ = CONCAT22(uVar5,(undefined2)local_60);
    }
    ExFreePoolWithTag(local_68,0);
  }
  return iVar3;
}



===== EapCreateAggregatedEventConditionVisitNode @ 140004b00 =====

ulonglong EapCreateAggregatedEventConditionVisitNode(longlong *param_1,int *param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  longlong *plVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  void *_Dst;
  longlong lVar12;
  longlong lVar13;
  ushort uVar14;
  int iVar15;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  longlong local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined4 local_28;
  undefined4 uStack_24;
  
  local_28 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  lStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (*param_2 == 0) {
    local_28 = 1;
    uVar11 = BriCreateBrokeredEventEx
                       ((UUID *)(param_2 + 2),*(undefined8 *)(param_1[2] + 0x38),
                        *(longlong *)(param_1[2] + 0x40),param_2 + 6,*(uint *)(param_1 + 3),0,
                        &local_48,&local_78,0);
    if ((int)uVar11 < 0) {
      return uVar11;
    }
    local_88 = local_38;
    uStack_80 = uStack_30;
    lStack_40 = CONCAT44((undefined4)uStack_70,(int)local_78);
LAB_140004c86:
    if (*(ushort *)((longlong)param_1 + 10) == *(ushort *)(param_1 + 1)) {
      _Dst = (void *)ExAllocatePool2(0x100,((ulonglong)*(ushort *)(param_1 + 1) + 5) * 0x38,
                                     0x41747645);
      if (_Dst == (void *)0x0) goto LAB_140004ba8;
      if ((void *)*param_1 != (void *)0x0) {
        memmove(_Dst,(void *)*param_1,(ulonglong)*(ushort *)(param_1 + 1) * 0x38);
        ExFreePoolWithTag(*param_1,0);
      }
      *(short *)(param_1 + 1) = (short)param_1[1] + 5;
      *param_1 = (longlong)_Dst;
    }
    lVar12 = (ulonglong)*(ushort *)((longlong)param_1 + 10) * 0x38;
    lVar6 = *param_1;
    *(undefined8 *)(lVar12 + lVar6) = local_58;
    ((undefined8 *)(lVar12 + lVar6))[1] = uStack_50;
    plVar5 = (longlong *)(lVar12 + 0x10 + lVar6);
    *plVar5 = local_48;
    plVar5[1] = lStack_40;
    puVar1 = (undefined8 *)(lVar12 + 0x20 + lVar6);
    *puVar1 = local_88;
    puVar1[1] = uStack_80;
    *(ulonglong *)(lVar12 + 0x30 + lVar6) = CONCAT44(uStack_24,local_28);
    uVar11 = 0;
    *(short *)((longlong)param_1 + 10) = *(short *)((longlong)param_1 + 10) + 1;
  }
  else {
    if ((*param_2 != 1) || ((uint)*(ushort *)((longlong)param_1 + 10) < (uint)param_2[3])) {
      return 0xc00000e5;
    }
    local_58 = 1;
    iVar15 = 0;
    uStack_50 = (ulonglong)(uint)param_2[2];
    local_48 = ExAllocatePool2(0x100,(ulonglong)(uint)param_2[3] * 0x38,0x41747645);
    if (local_48 != 0) {
      uVar14 = 0;
      if (param_2[3] != 0) {
        do {
          lVar6 = *param_1;
          iVar15 = iVar15 + 1;
          lVar13 = (ulonglong)*(ushort *)((longlong)param_1 + 10) * 0x38;
          uVar11 = (ulonglong)uVar14;
          uVar14 = uVar14 + 1;
          lVar12 = uVar11 * 0x38;
          puVar1 = (undefined8 *)(lVar13 + -0x38 + lVar6);
          uVar10 = puVar1[1];
          *(undefined8 *)(lVar12 + local_48) = *puVar1;
          ((undefined8 *)(lVar12 + local_48))[1] = uVar10;
          puVar1 = (undefined8 *)(lVar13 + -0x28 + lVar6);
          uVar10 = puVar1[1];
          puVar2 = (undefined8 *)(lVar12 + 0x10 + local_48);
          *puVar2 = *puVar1;
          puVar2[1] = uVar10;
          puVar3 = (undefined4 *)(lVar13 + -0x18 + lVar6);
          uVar7 = puVar3[1];
          uVar8 = puVar3[2];
          uVar9 = puVar3[3];
          puVar4 = (undefined4 *)(lVar12 + 0x20 + local_48);
          *puVar4 = *puVar3;
          puVar4[1] = uVar7;
          puVar4[2] = uVar8;
          puVar4[3] = uVar9;
          *(undefined8 *)(lVar12 + 0x30 + local_48) = *(undefined8 *)(lVar13 + -8 + lVar6);
          *(short *)((longlong)param_1 + 10) = *(short *)((longlong)param_1 + 10) + -1;
        } while ((uint)uVar14 < (uint)param_2[3]);
        uStack_50 = CONCAT44(iVar15,(undefined4)uStack_50);
      }
      goto LAB_140004c86;
    }
LAB_140004ba8:
    uVar11 = 0xc0000017;
  }
  return uVar11;
}



===== EapDeleteAggregatedEvent @ 140004d4c =====

ulonglong EapDeleteAggregatedEvent(longlong *param_1,uint param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined4 extraout_var;
  
  if (param_1 == (longlong *)0x0) {
    uVar2 = 0xc000000d;
  }
  else {
    if (param_1[1] != 0) {
      iVar1 = EapDeleteAggregatedEventCondition(param_1[1],param_2);
      if (iVar1 < 0) {
        return CONCAT44(extraout_var,iVar1);
      }
      ExFreePoolWithTag(param_1[1],0);
      param_1[1] = 0;
    }
    if (*param_1 != 0) {
      uVar2 = BriDeleteBrokeredEvent(*param_1 + 8,param_2);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      ExFreePoolWithTag(*param_1,0);
      *param_1 = 0;
    }
    ExFreePoolWithTag(param_1,0);
    uVar2 = 0;
  }
  return uVar2;
}



===== EapDeleteAggregatedEventCondition @ 140004de4 =====

int EapDeleteAggregatedEventCondition(longlong param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_res10 [6];
  undefined4 *local_38;
  code *local_30;
  undefined8 local_28;
  undefined8 local_20;
  code *local_18;
  
  if (param_1 == 0) {
    iVar1 = -0x3ffffff3;
  }
  else {
    local_38 = local_res10;
    local_28 = 0;
    local_20 = 0;
    local_30 = EaiAggregationConditionNextChild;
    local_18 = EapDeleteAggregatedEventConditionVisitNode;
    local_res10[0] = param_2;
    iVar1 = EapTreeTraverse(&local_38,param_1);
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



===== EapDeleteAggregatedEventConditionVisitNode @ 140004e50 =====

undefined8 EapDeleteAggregatedEventConditionVisitNode(uint *param_1,int *param_2)

{
  if (*param_2 == 0) {
    BriDeleteBrokeredEvent((longlong)(param_2 + 4),*param_1);
    param_2[4] = 0;
    param_2[5] = 0;
  }
  else if (*param_2 == 1) {
    ExFreePoolWithTag(*(undefined8 *)(param_2 + 4),0);
  }
  return 0;
}



===== BriAllocateRpcBuffer @ 140004eb0 =====

void BriAllocateRpcBuffer(size_t param_1)

{
                    /* 0x4eb0  1  BriAllocateRpcBuffer */
  MIDL_user_allocate(param_1);
  return;
}



===== BriCleanup @ 140004ed0 =====

void BriCleanup(void)

{
                    /* 0x4ed0  2  BriCleanup */
  if (BrokerInternalClientInitialized != '\0') {
    BripCleanupEventTable();
    BripCleanupBindingTable();
    BrokerInternalClientInitialized = '\0';
  }
  return;
}



===== BriCreateBrokeredEvent @ 140004f00 =====

void BriCreateBrokeredEvent
               (UUID *param_1,undefined8 param_2,longlong param_3,undefined8 param_4,uint param_5,
               undefined8 param_6,undefined8 *param_7,undefined8 *param_8)

{
                    /* 0x4f00  3  BriCreateBrokeredEvent */
  BriCreateBrokeredEventEx(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,0);
  return;
}



===== BriCreateBrokeredEventEx @ 140004f50 =====

ulonglong BriCreateBrokeredEventEx
                    (UUID *param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
                    uint param_5,undefined8 param_6,undefined8 *param_7,undefined8 *param_8,
                    undefined8 param_9)

{
  ulonglong uVar1;
  uint uVar2;
  
                    /* 0x4f50  4  BriCreateBrokeredEventEx */
  if ((param_5 & 0xfffffffc) == 0) {
    uVar2 = 0;
    do {
      uVar2 = uVar2 + 1;
      uVar1 = BripCreateBrokeredEvent
                        ((param_5 & 1) + 1,param_1,param_2,param_3,param_4,param_5 >> 1 & 1,param_6,
                         param_7,param_8,param_9);
      if ((int)uVar1 != -0x3ffdffe4) {
        return uVar1;
      }
    } while (uVar2 < 2);
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== BriDeleteBrokeredEvent @ 140005020 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BriDeleteBrokeredEvent(longlong param_1,uint param_2)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined1 auStack_58 [32];
  RPC_BINDING_HANDLE local_38;
  undefined8 local_30;
  UUID local_28;
  ulonglong local_18;
  
                    /* 0x5020  5  BriDeleteBrokeredEvent */
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_30 = 0;
  local_38 = (RPC_BINDING_HANDLE)0x0;
  local_28.Data1 = 0;
  local_28.Data2 = 0;
  local_28.Data3 = 0;
  local_28.Data4[0] = '\0';
  local_28.Data4[1] = '\0';
  local_28.Data4[2] = '\0';
  local_28.Data4[3] = '\0';
  local_28.Data4[4] = '\0';
  local_28.Data4[5] = '\0';
  local_28.Data4[6] = '\0';
  local_28.Data4[7] = '\0';
  if ((param_1 == 0) || ((param_2 & 0xfffffffe) != 0)) {
    uVar4 = 0xc000000d;
  }
  else {
    uVar1 = RtlRunOnceExecuteOnce(&BrokerInternalClientInitOnce,BrpInitOnceRunOnceCallback,0,0);
    uVar4 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar2 = BripGetEventContextData(param_1,(undefined8 *)&local_28,&local_30);
      uVar4 = uVar2 & 0xffffffff;
      if (-1 < (int)uVar2) {
        uVar1 = BripCreateRpcBindingHandle(&local_28,(longlong *)&local_38);
        if (uVar1 == 0) {
          uVar1 = EapSystemBriDeleteEvent(&local_28,local_38);
          if (uVar1 == 0) {
            EaLibAcquireLockExclusive(0x14000e150);
            lVar3 = BripFindEventContextByEventId(param_1);
            if (lVar3 == 0) {
              uVar4 = 0xc0000225;
            }
            else {
              RtlRemoveEntryHashTable(BrokeredEventTable,lVar3,0);
              ExFreePoolWithTag(lVar3,0);
              uVar4 = 0;
            }
            EaLibReleaseLockExclusive(0x14000e150);
            goto LAB_14000514f;
          }
        }
        uVar1 = BripMapRpcStatus(uVar1);
        uVar4 = (ulonglong)uVar1;
      }
    }
  }
LAB_14000514f:
  RpcBindingFree(&local_38);
  return uVar4;
}



===== BriFreeRpcBuffer @ 140005190 =====

void BriFreeRpcBuffer(void *param_1)

{
                    /* 0x5190  6  BriFreeRpcBuffer */
  if (param_1 != (void *)0x0) {
    MIDL_user_free(param_1);
  }
  return;
}



===== BriIsBrokerRegistered @ 1400051b0 =====

undefined1 BriIsBrokerRegistered(undefined8 *param_1)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  void *pvVar5;
  undefined1 uVar6;
  
                    /* 0x51b0  7  BriIsBrokerRegistered */
  uVar6 = 0;
  bVar1 = false;
  iVar2 = RtlRunOnceExecuteOnce(&BrokerInternalClientInitOnce,BrpInitOnceRunOnceCallback,0,0);
  if (iVar2 < 0) {
    return 0;
  }
  EaLibAcquireLockShared(&BrokerBindingTableLock);
  lVar3 = BripFindBindingContextByBrokerId(param_1);
  if (lVar3 == 0) {
    uVar4 = EaLibConvertLockSharedToExclusive();
    lVar3 = 0;
    if ((char)uVar4 == '\0') {
      lVar3 = BripFindBindingContextByBrokerId(param_1);
    }
    bVar1 = true;
    if ((lVar3 == 0) && (pvVar5 = BripCreateBindingContext(param_1), pvVar5 == (void *)0x0))
    goto LAB_14000523e;
  }
  uVar6 = 1;
  if (!bVar1) {
    EaLibReleaseLockShared(&BrokerBindingTableLock);
    return 1;
  }
LAB_14000523e:
  EaLibReleaseLockExclusive(0x14000e140);
  return uVar6;
}



===== BriResolveBrokerIdByEventId @ 140005280 =====

undefined8 BriResolveBrokerIdByEventId(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
                    /* 0x5280  8  BriResolveBrokerIdByEventId */
  if ((param_1 == 0) || (param_2 == (undefined8 *)0x0)) {
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = RtlRunOnceExecuteOnce(&BrokerInternalClientInitOnce,BrpInitOnceRunOnceCallback,0,0);
    if (-1 < (int)uVar1) {
      uVar1 = BripGetEventContextData(param_1,param_2,(undefined8 *)0x0);
    }
  }
  return uVar1;
}



===== BripCleanupBindingTable @ 1400052e8 =====

void BripCleanupBindingTable(void)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_38 = 0;
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  EaLibAcquireLockExclusive(0x14000e140);
  if (BrokerBindingTable != 0) {
    cVar1 = RtlInitEnumerationHashTable(BrokerBindingTable,&local_38);
    if (cVar1 != '\0') {
      lVar2 = RtlEnumerateEntryHashTable(BrokerBindingTable,&local_38);
      while (lVar2 != 0) {
        RtlRemoveEntryHashTable(BrokerBindingTable,lVar2,0);
        lVar3 = RtlEnumerateEntryHashTable(BrokerBindingTable,&local_38);
        BripFreeBindingContext(lVar2);
        lVar2 = lVar3;
      }
      RtlEndEnumerationHashTable(BrokerBindingTable,&local_38);
    }
    RtlDeleteHashTable(BrokerBindingTable);
    BrokerBindingTable = 0;
  }
  EaLibReleaseLockExclusive(0x14000e140);
  return;
}



===== BripCleanupEventTable @ 1400053ec =====

void BripCleanupEventTable(void)

{
  char cVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  RPC_BINDING_HANDLE local_res8;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res8 = (RPC_BINDING_HANDLE)0x0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  EaLibAcquireLockExclusive(0x14000e150);
  if (BrokeredEventTable != 0) {
    cVar1 = RtlInitEnumerationHashTable(BrokeredEventTable,&local_38);
    if (cVar1 != '\0') {
      lVar3 = RtlEnumerateEntryHashTable(BrokeredEventTable,&local_38);
      while (lVar3 != 0) {
        RtlRemoveEntryHashTable(BrokeredEventTable,lVar3,0);
        lVar4 = RtlEnumerateEntryHashTable(BrokeredEventTable,&local_38);
        uVar2 = BripCreateRpcBindingHandle((UUID *)(lVar3 + 0x28),(longlong *)&local_res8);
        if (uVar2 == 0) {
          EapSystemBriDeleteEvent((UUID *)(lVar3 + 0x28),local_res8);
        }
        RpcBindingFree(&local_res8);
        ExFreePoolWithTag(lVar3,0);
        lVar3 = lVar4;
      }
      RtlEndEnumerationHashTable(BrokeredEventTable,&local_38);
    }
    RtlDeleteHashTable(BrokeredEventTable);
    BrokeredEventTable = 0;
  }
  EaLibReleaseLockExclusive(0x14000e150);
  return;
}



===== BripCreateBindingContext @ 140005550 =====

void * BripCreateBindingContext(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  void *_Dst;
  ulonglong uVar6;
  longlong lVar7;
  int iVar8;
  undefined4 local_res10 [2];
  longlong local_res18;
  longlong local_res20;
  longlong local_98 [2];
  void *pvStack_88;
  longlong local_80 [2];
  undefined4 local_70;
  undefined4 uStack_6c;
  longlong lStack_68;
  longlong *local_60;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined8 local_50;
  ulonglong uStack_48;
  
  local_res20 = 0;
  local_98[0] = 0;
  local_res10[0] = 0;
  lVar7 = 0;
  local_70 = 0;
  uStack_6c = 0;
  lStack_68 = 0;
  local_50 = 0;
  local_60 = (longlong *)0x0;
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_48 = uStack_48 & 0xffffffff00000000;
  _Dst = (void *)0x0;
  local_98[1] = 0;
  pvStack_88 = (void *)0x0;
  local_res18 = 0;
  local_80[0] = 0;
  local_80[1] = 0;
  iVar4 = RtlStringFromGUID(0,local_98 + 1);
  if (-1 < iVar4) {
    iVar4 = RtlInitUnicodeStringEx
                      (local_80,
                       L"\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\BackgroundModel\\Brokers"
                      );
    if (-1 < iVar4) {
      lStack_68 = 0;
      local_60 = local_80;
      local_70 = 0x30;
      uStack_58 = 0x40;
      local_50 = 0;
      uStack_48 = 0;
      iVar4 = ZwOpenKey(local_98,0x101,&local_70);
      if (-1 < iVar4) {
        lStack_68 = local_98[0];
        local_60 = local_98 + 1;
        local_70 = 0x30;
        uStack_58 = 0x40;
        local_50 = 0;
        uStack_48 = 0;
        iVar4 = ZwOpenKey(&local_res20,0x101,&local_70);
        if (-1 < iVar4) {
          _Dst = (void *)ExAllocatePool2(0x40,0x40,0x41747645);
          puVar1 = (undefined8 *)((longlong)_Dst + 0x18);
          if (_Dst == (void *)0x0) {
            iVar4 = -0x3fffffe9;
          }
          else {
            memset(_Dst,0,0x40);
            uVar2 = param_1[1];
            *puVar1 = *param_1;
            *(undefined8 *)((longlong)_Dst + 0x20) = uVar2;
            uVar2 = param_1[1];
            *puVar1 = *param_1;
            *(undefined8 *)((longlong)_Dst + 0x20) = uVar2;
            uVar6 = BripQueryBindingContextProperties
                              (local_res20,(longlong)_Dst,&local_res18,local_res10);
            iVar4 = (int)uVar6;
            if (-1 < iVar4) {
              iVar5 = RtlComputeCrc32(0,puVar1,0x10);
              iVar8 = 1;
              if (iVar5 != 0) {
                iVar8 = iVar5;
              }
              cVar3 = RtlInsertEntryHashTable(BrokerBindingTable,_Dst,iVar8,0);
              if (cVar3 == '\0') {
                iVar4 = -0x3fffff66;
              }
            }
            lVar7 = local_res18;
          }
        }
      }
    }
  }
  if (local_res20 != 0) {
    ZwClose();
  }
  if (local_98[0] != 0) {
    ZwClose();
  }
  if (pvStack_88 != (void *)0x0) {
    MIDL_user_free(pvStack_88);
  }
  if (lVar7 != 0) {
    ExFreePoolWithTag(lVar7,0);
  }
  if ((iVar4 < 0) && (_Dst != (void *)0x0)) {
    BripFreeBindingContext((longlong)_Dst);
    _Dst = (void *)0x0;
  }
  return _Dst;
}



===== BripCreateBrokeredEvent @ 140005790 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BripCreateBrokeredEvent
                    (undefined4 param_1,UUID *param_2,undefined8 param_3,longlong param_4,
                    undefined8 param_5,undefined4 param_6,undefined8 param_7,undefined8 *param_8,
                    undefined8 *param_9,undefined8 param_10)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  CLIENT_CALL_RETURN CVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 auStack_128 [32];
  undefined4 local_108;
  undefined8 local_100;
  undefined4 *local_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined8 local_e0;
  undefined8 *local_d8;
  undefined8 *local_d0;
  longlong *local_c8;
  undefined8 local_c0;
  longlong local_b8;
  RPC_BINDING_HANDLE local_b0;
  undefined8 local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStack_128;
  local_88 = param_5;
  local_90 = param_7;
  local_a8 = param_10;
  uStack_98._0_4_ = 0;
  local_a0 = 0;
  local_9c = 0;
  local_80 = 0;
  local_b0 = (RPC_BINDING_HANDLE)0x0;
  local_b8 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((((param_2 == (UUID *)0x0) || (param_8 == (undefined8 *)0x0)) ||
      (param_9 == (undefined8 *)0x0)) || (param_4 == 0)) {
    uVar6 = 0xc000000d;
    goto LAB_14000597e;
  }
  cVar2 = RtlValidSid(param_4);
  if (cVar2 == '\0') {
    uVar6 = 0xc000000d;
    lVar1 = CONCAT44(uStack_98._4_4_,(undefined4)uStack_98);
  }
  else {
    uVar3 = RtlRunOnceExecuteOnce(&BrokerInternalClientInitOnce,BrpInitOnceRunOnceCallback,0,0);
    uVar6 = (ulonglong)uVar3;
    lVar1 = CONCAT44(uStack_98._4_4_,(undefined4)uStack_98);
    if (-1 < (int)uVar3) {
      *param_8 = 0;
      uVar3 = BripCreateRpcBindingHandle(param_2,(longlong *)&local_b0);
      if (uVar3 == 0) {
        uStack_98 = param_4;
        local_a0 = RtlLengthSid(param_4);
        local_c0 = local_a8;
        local_c8 = &local_b8;
        local_d0 = &local_78;
        local_d8 = &local_80;
        local_e0 = local_90;
        local_e8 = param_6;
        local_f0 = local_88;
        local_f8 = &local_a0;
        local_108 = param_1;
        local_100 = param_3;
        CVar4 = NdrClientCall3((MIDL_STUBLESS_PROXY_INFO *)&PTR_PTR_14000b860,0,(void *)0x0);
        uVar3 = (uint)CVar4.Simple;
        if ((uint)CVar4.Simple == 0) {
          uVar5 = BripCreateEventContext(&local_80,(undefined8 *)param_2,local_b8);
          uVar6 = uVar5 & 0xffffffff;
          lVar1 = uStack_98;
          if (-1 < (int)uVar5) {
            uVar6 = 0;
            *param_8 = local_80;
            *param_9 = local_78;
            param_9[1] = uStack_70;
            param_9[2] = local_68;
            param_9[3] = uStack_60;
            goto LAB_14000597e;
          }
          goto LAB_14000584b;
        }
      }
      uVar3 = BripMapRpcStatus(uVar3);
      uVar6 = (ulonglong)uVar3;
      lVar1 = uStack_98;
      if (-1 < (int)uVar3) goto LAB_14000597e;
    }
  }
LAB_14000584b:
  uStack_98._4_4_ = (undefined4)((ulonglong)lVar1 >> 0x20);
  uStack_98._0_4_ = (undefined4)lVar1;
  if (local_b8 != 0) {
    uStack_98 = lVar1;
    EapSystemBriDeleteEvent(param_2,local_b0);
  }
LAB_14000597e:
  RpcBindingFree(&local_b0);
  return uVar6;
}



===== BripCreateEventContext @ 1400059b8 =====

undefined8 BripCreateEventContext(undefined8 *param_1,undefined8 *param_2,undefined8 param_3)

{
  undefined8 uVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  int iVar6;
  
  lVar4 = ExAllocatePool2(0x40,0x38,0x41747645);
  uVar5 = 0;
  if (lVar4 == 0) {
    uVar5 = 0xc000009a;
  }
  else {
    uVar1 = param_2[1];
    *(undefined8 *)(lVar4 + 0x28) = *param_2;
    *(undefined8 *)(lVar4 + 0x30) = uVar1;
    *(undefined8 *)(lVar4 + 0x20) = *param_1;
    *(undefined8 *)(lVar4 + 0x18) = param_3;
    EaLibAcquireLockExclusive(0x14000e150);
    iVar3 = RtlComputeCrc32(0,lVar4 + 0x20,8);
    iVar6 = 1;
    if (iVar3 != 0) {
      iVar6 = iVar3;
    }
    cVar2 = RtlInsertEntryHashTable(BrokeredEventTable,lVar4,iVar6,0);
    if (cVar2 == '\0') {
      uVar5 = 0xc000009a;
      ExFreePoolWithTag(lVar4,0);
    }
    EaLibReleaseLockExclusive(0x14000e150);
  }
  return uVar5;
}



===== BripCreateRpcBindingHandle @ 140005ab0 =====

uint BripCreateRpcBindingHandle(UUID *param_1,longlong *param_2)

{
  bool bVar1;
  uint uVar2;
  void *pvVar3;
  ulonglong uVar4;
  
  *param_2 = 0;
  bVar1 = false;
  EaLibAcquireLockShared(&BrokerBindingTableLock);
  pvVar3 = (void *)BripFindBindingContextByBrokerId(param_1);
  if (pvVar3 == (void *)0x0) {
    uVar4 = EaLibConvertLockSharedToExclusive();
    if ((char)uVar4 == '\0') {
      pvVar3 = (void *)BripFindBindingContextByBrokerId(param_1);
    }
    bVar1 = true;
    if ((pvVar3 == (void *)0x0) &&
       (pvVar3 = BripCreateBindingContext((undefined8 *)param_1), pvVar3 == (void *)0x0)) {
      uVar2 = 0xc002000b;
      goto LAB_140005b41;
    }
  }
  uVar2 = EapSystemBriCreateRpcBindingHandle
                    (param_1,*(undefined8 *)((longlong)pvVar3 + 0x28),
                     *(undefined8 *)((longlong)pvVar3 + 0x30),param_2);
  uVar2 = -(uint)(uVar2 != 0) & uVar2;
  if (!bVar1) {
    EaLibReleaseLockShared(&BrokerBindingTableLock);
    return uVar2;
  }
LAB_140005b41:
  EaLibReleaseLockExclusive(0x14000e140);
  return uVar2;
}



===== BripFindBindingContextByBrokerId @ 140005b7c =====

longlong BripFindBindingContextByBrokerId(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = RtlComputeCrc32(0,param_1,0x10);
  iVar4 = 1;
  if (iVar1 != 0) {
    iVar4 = iVar1;
  }
  lVar2 = RtlLookupEntryHashTable(BrokerBindingTable,iVar4,&local_28);
  while( true ) {
    if (lVar2 == 0) {
      return 0;
    }
    lVar3 = RtlCompareMemory(param_1,lVar2 + 0x18,0x10);
    if (lVar3 == 0x10) break;
    lVar2 = RtlGetNextEntryHashTable(BrokerBindingTable,&local_28);
  }
  return lVar2;
}



===== BripFindEventContextByEventId @ 140005c2c =====

longlong BripFindEventContextByEventId(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  iVar1 = RtlComputeCrc32(0,param_1,8);
  iVar4 = 1;
  if (iVar1 != 0) {
    iVar4 = iVar1;
  }
  lVar2 = RtlLookupEntryHashTable(BrokeredEventTable,iVar4,&local_28);
  while( true ) {
    if (lVar2 == 0) {
      return 0;
    }
    lVar3 = RtlCompareMemory(param_1,lVar2 + 0x20,8);
    if (lVar3 == 8) break;
    lVar2 = RtlGetNextEntryHashTable(BrokeredEventTable,&local_28);
  }
  return lVar2;
}



===== BripFreeBindingContext @ 140005cdc =====

void BripFreeBindingContext(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x30) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x30),0);
  }
  if (*(longlong *)(param_1 + 0x28) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x28),0);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== BripGetEventContextData @ 140005d34 =====

undefined8 BripGetEventContextData(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  EaLibAcquireLockShared(&BrokeredEventTableLock);
  lVar2 = BripFindEventContextByEventId(param_1);
  uVar3 = 0;
  if (lVar2 == 0) {
    uVar3 = 0xc0000225;
  }
  else {
    uVar1 = *(undefined8 *)(lVar2 + 0x30);
    *param_2 = *(undefined8 *)(lVar2 + 0x28);
    param_2[1] = uVar1;
    if (param_3 != (undefined8 *)0x0) {
      *param_3 = *(undefined8 *)(lVar2 + 0x18);
    }
  }
  EaLibReleaseLockShared(&BrokeredEventTableLock);
  return uVar3;
}



===== BripMapRpcStatus @ 140005da8 =====

uint BripMapRpcStatus(uint param_1)

{
  ushort uVar1;
  
  if (-1 < (int)param_1) {
    uVar1 = 0;
    do {
      if (*(uint *)(&RpcErrMap + (ulonglong)uVar1 * 8) == param_1) {
        return *(uint *)(&DAT_14000bb84 + (ulonglong)uVar1 * 8);
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x6f);
    if (0 < (int)param_1) {
      param_1 = param_1 & 0xffff | 0xc0070000;
    }
  }
  return param_1;
}



===== BripQueryBindingContextProperties @ 140005dec =====

ulonglong BripQueryBindingContextProperties
                    (undefined8 param_1,longlong param_2,longlong *param_3,undefined4 *param_4)

{
  ulonglong uVar1;
  void *pvVar2;
  
  uVar1 = BripQueryValue(param_1,L"ServerAuth",3,param_3,param_4);
  if ((int)uVar1 < 0) {
    return uVar1 & 0xffffffff;
  }
  pvVar2 = (void *)ExAllocatePool2(0x40,*(undefined4 *)(*param_3 + 8),0x41747645);
  *(void **)(param_2 + 0x30) = pvVar2;
  if (pvVar2 != (void *)0x0) {
    memmove(pvVar2,(void *)(*param_3 + 0xc),(ulonglong)*(uint *)(*param_3 + 8));
    uVar1 = BripQueryValue(param_1,L"ServerPrincipal",3,param_3,param_4);
    if ((int)uVar1 < 0) {
      return uVar1 & 0xffffffff;
    }
    pvVar2 = (void *)ExAllocatePool2(0x40,*(undefined4 *)(*param_3 + 8),0x41747645);
    *(void **)(param_2 + 0x28) = pvVar2;
    if (pvVar2 != (void *)0x0) {
      memmove(pvVar2,(void *)(*param_3 + 0xc),(ulonglong)*(uint *)(*param_3 + 8));
      uVar1 = BripQueryValue(param_1,L"AvailabilityStateName",0xb,param_3,param_4);
      if (-1 < (int)uVar1) {
        memmove((void *)(param_2 + 0x38),(void *)(*param_3 + 0xc),(ulonglong)*(uint *)(*param_3 + 8)
               );
        return uVar1 & 0xffffffff;
      }
      if ((int)uVar1 == -0x3fffffcc) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        return 0;
      }
      return uVar1 & 0xffffffff;
    }
  }
  return 0xc000009a;
}



===== BripQueryValue @ 140005f44 =====

ulonglong BripQueryValue(undefined8 param_1,undefined8 param_2,int param_3,longlong *param_4,
                        undefined4 *param_5)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined4 local_res18 [4];
  undefined8 local_28;
  undefined8 uStack_20;
  
  lVar2 = *param_4;
  local_res18[0] = *param_5;
  local_28 = 0;
  uStack_20 = 0;
  RtlInitUnicodeString(&local_28);
  uVar1 = ZwQueryValueKey(param_1,&local_28,2,lVar2,local_res18[0],local_res18);
  if (((int)uVar1 == -0x3fffffdd) || ((int)uVar1 == -0x7ffffffb)) {
    lVar2 = ExAllocatePool2(0x40,local_res18[0],0x41747645);
    if (lVar2 == 0) {
      return 0xc0000017;
    }
    if (*param_4 != 0) {
      ExFreePoolWithTag(*param_4,0);
    }
    *param_4 = lVar2;
    *param_5 = local_res18[0];
    uVar1 = ZwQueryValueKey(param_1,&local_28,2,lVar2,local_res18[0],local_res18);
  }
  if ((-1 < (int)uVar1) && (uVar1 = uVar1 & 0xffffffff, *(int *)(lVar2 + 4) != param_3)) {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== BrpInitOnceRunOnceCallback @ 140006070 =====

undefined8 BrpInitOnceRunOnceCallback(void)

{
  char cVar1;
  
  EaLibLockInitialize((undefined8 *)&BrokerBindingTableLock);
  cVar1 = RtlCreateHashTable(&BrokerBindingTable,0,0);
  if (cVar1 != '\0') {
    EaLibLockInitialize((undefined8 *)&BrokeredEventTableLock);
    cVar1 = RtlCreateHashTable(&BrokeredEventTable,0,0);
    if (cVar1 != '\0') {
      BrokerInternalClientInitialized = 1;
      return 1;
    }
  }
  if (BrokerBindingTable != 0) {
    RtlDeleteHashTable();
    BrokerBindingTable = 0;
  }
  if (BrokeredEventTable != 0) {
    RtlDeleteHashTable();
    BrokeredEventTable = 0;
  }
  return 0;
}



===== EaFreeBuffer @ 140006130 =====

void EaFreeBuffer(undefined8 param_1)

{
                    /* 0x6130  25  EaFreeBuffer */
  ExFreePoolWithTag(param_1,0);
  return;
}



===== EapTreeTraverse @ 140006150 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int EapTreeTraverse(undefined8 *param_1,undefined8 param_2)

{
  short *psVar1;
  bool bVar2;
  int iVar3;
  undefined8 *_Src;
  undefined8 *puVar4;
  ushort uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong local_res8;
  
  local_res8 = 0;
  if ((param_1 == (undefined8 *)0x0) || (param_1[1] == 0)) {
    iVar3 = -0x3ffffff3;
  }
  else {
    _Src = (undefined8 *)ExAllocatePool2(0x100,0x50,0x41747645);
    if (_Src == (undefined8 *)0x0) {
      iVar3 = -0x3fffffe9;
    }
    else {
      *_Src = param_2;
      uVar6 = 5;
      *(undefined4 *)(_Src + 1) = 0;
      bVar2 = false;
      uVar5 = 1;
      do {
        if ((((code *)param_1[3] != (code *)0x0) && (!bVar2)) &&
           (iVar3 = (*(code *)param_1[3])
                              (*param_1,_Src[(ulonglong)uVar5 * 2 + -2],
                               *(undefined2 *)(_Src + (ulonglong)uVar5 * 2 + -1)), iVar3 < 0))
        goto LAB_140006349;
        uVar7 = (ulonglong)uVar5;
        iVar3 = (*(code *)param_1[1])
                          (*param_1,_Src[uVar7 * 2 + -2],
                           *(undefined2 *)((longlong)_Src + uVar7 * 0x10 + -6),&local_res8);
        if (iVar3 < 0) goto LAB_140006349;
        if (local_res8 == 0) {
          if ((((code *)param_1[4] != (code *)0x0) &&
              (iVar3 = (*(code *)param_1[4])
                                 (*param_1,_Src[uVar7 * 2 + -2],
                                  *(undefined2 *)(_Src + uVar7 * 2 + -1)), iVar3 < 0)) ||
             (((code *)param_1[2] != (code *)0x0 &&
              ((1 < uVar5 &&
               (iVar3 = (*(code *)param_1[2])(*param_1,_Src[uVar7 * 2 + -2]), iVar3 < 0))))))
          goto LAB_140006349;
          uVar5 = uVar5 - 1;
          bVar2 = true;
        }
        else {
          puVar4 = _Src;
          if (uVar5 == (ushort)uVar6) {
            puVar4 = (undefined8 *)ExAllocatePool2(0x100,(uVar6 + 5) * 0x10,0x41747645);
            if (puVar4 == (undefined8 *)0x0) {
              iVar3 = -0x3fffffe9;
              goto LAB_140006349;
            }
            memmove(puVar4,_Src,uVar6 << 4);
            ExFreePoolWithTag(_Src,0);
            uVar6 = (ulonglong)(ushort)((ushort)uVar6 + 5);
          }
          psVar1 = (short *)((longlong)puVar4 + uVar7 * 0x10 + -6);
          *psVar1 = *psVar1 + 1;
          puVar4[uVar7 * 2] = local_res8;
          *(short *)(puVar4 + uVar7 * 2 + 1) = *(short *)(puVar4 + uVar7 * 2 + -1) + 1;
          uVar5 = uVar5 + 1;
          *(undefined2 *)((longlong)puVar4 + uVar7 * 0x10 + 10) = 0;
          bVar2 = false;
          _Src = puVar4;
        }
      } while (uVar5 != 0);
      iVar3 = 0;
LAB_140006349:
      if (_Src != (undefined8 *)0x0) {
        if ((param_1[2] != 0) && (1 < uVar5)) {
          puVar4 = _Src + (ulonglong)uVar5 * 2 + -2;
          uVar6 = (ulonglong)(ushort)(uVar5 - 1);
          do {
            (*(code *)param_1[2])(*param_1,*puVar4);
            puVar4 = puVar4 + -2;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
        ExFreePoolWithTag(_Src,0);
      }
    }
  }
  return iVar3;
}



===== EaDeleteAggregatedEventParameters @ 1400063d0 =====

int EaDeleteAggregatedEventParameters(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  longlong local_res18 [2];
  longlong local_48;
  undefined4 local_40;
  undefined4 local_3c;
  longlong *local_38;
  code *local_30;
  code *local_28;
  undefined8 local_20;
  code *local_18;
  
                    /* 0x63d0  19  EaDeleteAggregatedEventParameters */
  local_res18[0] = 0;
  local_3c = 0;
  local_48 = 0;
  local_40 = 0;
  iVar1 = EapOpenAggregatedEventNode(param_1,param_2,local_res18);
  if (-1 < iVar1) {
    local_20 = 0;
    local_38 = &local_48;
    local_30 = EaDeleteAggregatedEventParametersNextChild;
    local_28 = EaDeleteAggregatedEventParametersCloseChild;
    local_18 = EaDeleteAggregatedEventParametersPostVisitNode;
    iVar1 = EapTreeTraverse(&local_38,local_res18[0]);
  }
  if (local_res18[0] != 0) {
    ZwClose();
  }
  if (local_48 != 0) {
    ExFreePoolWithTag(local_48,0);
  }
  return iVar1;
}



===== EaDeleteAggregatedEventParametersCloseChild @ 140006480 =====

undefined8 EaDeleteAggregatedEventParametersCloseChild(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = ZwClose(param_2);
  }
  return uVar1;
}



===== EaDeleteAggregatedEventParametersNextChild @ 1400064b0 =====

ulonglong EaDeleteAggregatedEventParametersNextChild
                    (longlong *param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong local_res8;
  undefined8 local_58;
  longlong lStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 *local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  
  local_res8 = 0;
  local_28 = 0;
  uStack_20 = uStack_20 & 0xffffffff00000000;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = (undefined8 *)0x0;
  uStack_30 = 0;
  local_58 = 0;
  lStack_50 = 0;
  uVar3 = EapEnumerateKey(param_2,0,param_1);
  uVar4 = uVar3 & 0xffffffff;
  if ((int)uVar3 == -0x7fffffe6) {
    *param_4 = 0;
    uVar4 = 0;
  }
  else if (-1 < (int)uVar3) {
    lVar1 = *param_1;
    if (*(uint *)(lVar1 + 0xc) < 0x10000) {
      lStack_50 = lVar1 + 0x10;
      local_58._0_4_ = CONCAT22(*(undefined2 *)(lVar1 + 0xc),*(undefined2 *)(lVar1 + 0xc));
      local_38 = &local_58;
      local_48 = CONCAT44(local_48._4_4_,0x30);
      uStack_30 = CONCAT44(uStack_30._4_4_,0x40);
      local_28 = 0;
      uStack_20 = 0;
      uStack_40 = param_2;
      uVar2 = ZwOpenKey(&local_res8,0xf003f,&local_48);
      lVar1 = local_res8;
      uVar4 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        local_res8 = 0;
        *param_4 = lVar1;
      }
    }
    else {
      uVar4 = 0x80000005;
    }
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  return uVar4;
}



===== EaDeleteAggregatedEventParametersPostVisitNode @ 1400065c0 =====

undefined8 EaDeleteAggregatedEventParametersPostVisitNode(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0xc000000d;
  }
  else {
    uVar1 = ZwDeleteKey(param_2);
  }
  return uVar1;
}



===== EaFreeAggregatedEventParameters @ 1400065f0 =====

void EaFreeAggregatedEventParameters(longlong *param_1)

{
  undefined8 local_38;
  code *local_30;
  undefined8 local_28;
  undefined8 local_20;
  code *local_18;
  
                    /* 0x65f0  24  EaFreeAggregatedEventParameters */
  if (param_1 != (longlong *)0x0) {
    if (*param_1 != 0) {
      EapFreeSimpleEventParameters(*param_1);
      ExFreePoolWithTag(*param_1,0);
    }
    if (param_1[1] != 0) {
      local_38 = 0;
      local_28 = 0;
      local_20 = 0;
      local_30 = EapFreeAggregatedEventConditionNextChild;
      local_18 = EapFreeAggregatedEventConditionPostVisitNode;
      EapTreeTraverse(&local_38,param_1[1]);
      ExFreePoolWithTag(param_1[1],0);
    }
    if (param_1[7] != 0) {
      ExFreePoolWithTag(param_1[7],0);
    }
    if (param_1[8] != 0) {
      ExFreePoolWithTag(param_1[8],0);
    }
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== EaQueryAggregatedEventParameters @ 1400066c0 =====

int EaQueryAggregatedEventParameters
              (undefined8 param_1,undefined8 param_2,undefined8 *param_3,undefined8 param_4)

{
  longlong lVar1;
  int iVar2;
  longlong *_Dst;
  ulonglong uVar3;
  void *_Dst_00;
  longlong *plVar4;
  ulonglong local_res20;
  int local_48 [2];
  longlong local_40;
  longlong local_38 [2];
  
                    /* 0x66c0  29  EaQueryAggregatedEventParameters */
  local_38[1] = 0;
  local_40 = 0;
  local_38[0] = 0;
  _Dst = (longlong *)ExAllocatePool2(0x100,0x48,0x41747645);
  if (_Dst == (longlong *)0x0) {
LAB_140006717:
    iVar2 = -0x3fffffe9;
  }
  else {
    memset(_Dst,0,0x48);
    iVar2 = EapOpenAggregatedEventNode(param_1,param_2,&local_40);
    if (iVar2 < 0) goto LAB_1400069d3;
    uVar3 = EapQueryAggregatedEventTrigger(local_40,local_38,_Dst);
    iVar2 = (int)uVar3;
    if (iVar2 < 0) goto LAB_1400069d3;
    uVar3 = EapQueryAggregatedEventCondition(local_40,local_38,_Dst + 1);
    iVar2 = (int)uVar3;
    if (iVar2 < 0) goto LAB_1400069d3;
    local_res20 = 0;
    uVar3 = EapQueryValue(local_40,L"StartBoundary",0xb,param_4,&local_res20,8,local_38);
    iVar2 = (int)uVar3;
    if (iVar2 < 0) goto LAB_1400069d3;
    _Dst[5] = local_res20;
    local_res20 = 0;
    uVar3 = EapQueryValue(local_40,L"EndBoundary",0xb,param_4,&local_res20,8,local_38);
    iVar2 = (int)uVar3;
    if (iVar2 < 0) goto LAB_1400069d3;
    _Dst[6] = local_res20;
    uVar3 = EapQueryAggregatedEventOwnerAppName(local_40,local_38,_Dst + 7);
    iVar2 = (int)uVar3;
    if (iVar2 < 0) goto LAB_1400069d3;
    plVar4 = local_38;
    _Dst[8] = 0;
    uVar3 = EapQueryBuffer(local_40,L"OwnerUserSid",3,plVar4);
    lVar1 = local_38[0];
    iVar2 = (int)uVar3;
    if (iVar2 != -0x3fffffcc) {
      if (iVar2 < 0) goto LAB_1400069d3;
      _Dst_00 = (void *)ExAllocatePool2(0x100,*(undefined4 *)(local_38[0] + 0xc),0x41747645);
      if (_Dst_00 == (void *)0x0) goto LAB_140006717;
      memmove(_Dst_00,(void *)((ulonglong)*(uint *)(lVar1 + 8) + lVar1),
              (ulonglong)*(uint *)(lVar1 + 0xc));
      _Dst[8] = (longlong)_Dst_00;
    }
    lVar1 = local_40;
    local_res20 = local_res20 & 0xffffffff00000000;
    local_48[0] = 0;
    uVar3 = EapQueryValue(local_40,L"RepetitionIntervalInSeconds",4,plVar4,&local_res20,4,local_38);
    iVar2 = (int)uVar3;
    if (-1 < iVar2) {
      uVar3 = EapQueryValue(lVar1,L"NumberOfRepetitions",4,plVar4,local_48,4,local_38);
      lVar1 = local_40;
      iVar2 = (int)uVar3;
      if (-1 < iVar2) {
        *(undefined4 *)(_Dst + 3) = (undefined4)local_res20;
        *(int *)((longlong)_Dst + 0x1c) = local_48[0];
        local_res20 = local_res20 & 0xffffffff00000000;
        local_48[0] = 0;
        uVar3 = EapQueryValue(local_40,L"DelayIntervalInSeconds",4,plVar4,&local_res20,4,local_38);
        iVar2 = (int)uVar3;
        if (-1 < iVar2) {
          uVar3 = EapQueryValue(lVar1,L"IsRandom",4,plVar4,local_48,4,local_38);
          iVar2 = (int)uVar3;
          if (-1 < iVar2) {
            *(undefined4 *)(_Dst + 2) = (undefined4)local_res20;
            local_res20 = local_res20 & 0xffffffff00000000;
            *(bool *)((longlong)_Dst + 0x14) = local_48[0] != 0;
            uVar3 = EapQueryValue(local_40,L"TimeLimitInSeconds",4,plVar4,&local_res20,4,local_38);
            iVar2 = (int)uVar3;
            if (-1 < iVar2) {
              iVar2 = 0;
              *(undefined4 *)(_Dst + 4) = (undefined4)local_res20;
              *param_3 = _Dst;
              _Dst = (longlong *)0x0;
            }
          }
        }
      }
    }
  }
LAB_1400069d3:
  if (local_40 != 0) {
    ZwClose();
  }
  if (_Dst != (longlong *)0x0) {
    EaFreeAggregatedEventParameters(_Dst);
  }
  if (local_38[0] != 0) {
    ExFreePoolWithTag(local_38[0],0);
  }
  return iVar2;
}



===== EaStoreAggregatedEventParameters @ 140006a30 =====

int EaStoreAggregatedEventParameters(longlong param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong local_res8;
  
                    /* 0x6a30  31  EaStoreAggregatedEventParameters */
  local_res8 = 0;
  lVar5 = 0;
  if (((param_1 == 0) || (param_3 == (longlong *)0x0)) || (param_2 == 0)) {
    iVar2 = -0x3ffffff3;
  }
  else {
    iVar2 = EapCreateAggregatedEventNode(param_1,param_2,&local_res8);
    lVar5 = local_res8;
    if (-1 < iVar2) {
      if (*param_3 != 0) {
        iVar2 = EapStoreAggregatedEventTrigger(local_res8,*param_3);
        if (iVar2 < 0) goto LAB_140006c67;
      }
      if (param_3[1] != 0) {
        iVar2 = EapStoreAggregatedEventCondition(lVar5,param_3[1]);
        if (iVar2 < 0) goto LAB_140006c67;
      }
      if (param_3[5] != 0) {
        iVar2 = EapSetValue(lVar5,L"StartBoundary",0xb,param_3 + 5,8);
        if (iVar2 < 0) goto LAB_140006c67;
      }
      if (param_3[6] != 0) {
        iVar2 = EapSetValue(lVar5,L"EndBoundary",0xb,param_3 + 6,8);
        if (iVar2 < 0) goto LAB_140006c67;
      }
      lVar1 = param_3[7];
      if (lVar1 != 0) {
        lVar4 = -1;
        do {
          lVar4 = lVar4 + 1;
        } while (*(short *)(lVar1 + lVar4 * 2) != 0);
        iVar2 = EapSetValue(lVar5,L"OwnerAppName",1,lVar1,(int)lVar4 * 2 + 2);
        if (iVar2 < 0) goto LAB_140006c67;
      }
      lVar1 = param_3[8];
      if (lVar1 != 0) {
        uVar3 = RtlLengthSid(lVar1);
        iVar2 = EapSetValue(lVar5,L"OwnerUserSid",3,lVar1,uVar3);
        if (iVar2 < 0) goto LAB_140006c67;
      }
      if (*(int *)((longlong)param_3 + 0x1c) != 0) {
        iVar2 = EapSetValue(lVar5,L"RepetitionIntervalInSeconds",4,param_3 + 3,4);
        if ((-1 < iVar2) && (*(int *)((longlong)param_3 + 0x1c) != 0)) {
          iVar2 = EapSetValue(lVar5,L"NumberOfRepetitions",4,(int *)((longlong)param_3 + 0x1c),4);
        }
        if (iVar2 < 0) goto LAB_140006c67;
      }
      if ((int)param_3[2] != 0) {
        iVar2 = EapSetValue(lVar5,L"DelayIntervalInSeconds",4,param_3 + 2,4);
        if ((-1 < iVar2) && (*(char *)((longlong)param_3 + 0x14) != '\0')) {
          iVar2 = EapSetValue(lVar5,L"IsRandom",4,(char *)((longlong)param_3 + 0x14),4);
        }
        if (iVar2 < 0) goto LAB_140006c67;
      }
      if ((int)param_3[4] != 0) {
        iVar2 = EapSetValue(lVar5,L"TimeLimitInSeconds",4,param_3 + 4,4);
        if (iVar2 < 0) goto LAB_140006c67;
      }
      iVar2 = 0;
    }
  }
LAB_140006c67:
  if (lVar5 != 0) {
    ZwClose(lVar5);
  }
  return iVar2;
}



===== EapCreateAggregatedEventNode @ 140006ca0 =====

int EapCreateAggregatedEventNode(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  int iVar1;
  int local_res20 [2];
  longlong local_68 [3];
  undefined8 local_50;
  undefined8 uStack_48;
  longlong *local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  ulonglong uStack_28;
  
  local_res20[0] = 0;
  local_30 = 0;
  uStack_28 = uStack_28 & 0xffffffff00000000;
  local_68[1] = 0;
  local_68[0] = 0;
  local_68[2] = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = (longlong *)0x0;
  uStack_38 = 0;
  iVar1 = RtlStringFromGUID(param_2,local_68 + 1);
  if (-1 < iVar1) {
    local_40 = local_68 + 1;
    local_50 = CONCAT44(local_50._4_4_,0x30);
    uStack_38 = CONCAT44(uStack_38._4_4_,0x40);
    local_30 = 0;
    uStack_28 = 0;
    uStack_48 = param_1;
    iVar1 = ZwCreateKey(local_68,0xf003f,&local_50,0,0,0,local_res20);
    if (-1 < iVar1) {
      if (local_res20[0] == 1) {
        *param_3 = local_68[0];
        local_68[0] = 0;
      }
      else {
        iVar1 = -0x3fffffcb;
      }
    }
  }
  if (local_68[2] != 0) {
    RtlFreeUnicodeString(local_68 + 1);
  }
  if (local_68[0] != 0) {
    ZwClose();
  }
  return iVar1;
}



===== EapEnumerateKey @ 140006dc0 =====

undefined8 EapEnumerateKey(undefined8 param_1,ulonglong param_2,longlong *param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined4 local_res18 [4];
  
  local_res18[0] = 0;
  uVar2 = ZwEnumerateKey(param_1,param_2,0,*param_3,(int)param_3[1],local_res18);
  uVar1 = local_res18[0];
  if (((int)uVar2 == -0x3fffffdd) || ((int)uVar2 == -0x7ffffffb)) {
    lVar3 = ExAllocatePool2(0x100,local_res18[0],0x41747645);
    if (lVar3 == 0) {
      uVar2 = 0xc0000017;
    }
    else {
      if (*param_3 != 0) {
        ExFreePoolWithTag(*param_3,0);
      }
      *param_3 = lVar3;
      *(undefined4 *)(param_3 + 1) = uVar1;
      uVar2 = ZwEnumerateKey(param_1,param_2 & 0xffffffff,0,lVar3,uVar1,local_res18);
    }
  }
  return uVar2;
}



===== EapExpandValueQueryBuffer @ 140006e98 =====

undefined8 EapExpandValueQueryBuffer(longlong *param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = ExAllocatePool2(0x100,param_2,0x41747645);
  uVar2 = 0;
  if (lVar1 == 0) {
    uVar2 = 0xc0000017;
  }
  else {
    if (*param_1 != 0) {
      ExFreePoolWithTag(*param_1,0);
      *(undefined4 *)(param_1 + 1) = 0;
    }
    *param_1 = lVar1;
    *(undefined4 *)(param_1 + 1) = param_2;
  }
  return uVar2;
}



===== EapFreeAggregatedEventConditionPostVisitNode @ 140006f30 =====

undefined8 EapFreeAggregatedEventConditionPostVisitNode(undefined8 param_1,int *param_2)

{
  if (*param_2 == 0) {
    EapFreeSimpleEventParameters((longlong)(param_2 + 2));
  }
  else if ((*param_2 == 1) && (*(longlong *)(param_2 + 4) != 0)) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 4),0);
  }
  return 0;
}



===== EapFreeSimpleEventParameters @ 140006f70 =====

void EapFreeSimpleEventParameters(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  ushort uVar3;
  longlong lVar4;
  
  if (*(longlong *)(param_1 + 0x18) != 0) {
    uVar3 = 0;
    if (*(short *)(param_1 + 0x10) != 0) {
      do {
        lVar2 = *(longlong *)(param_1 + 0x18);
        lVar4 = (ulonglong)uVar3 * 0x20;
        iVar1 = *(int *)(lVar4 + 8 + lVar2);
        if (iVar1 == 2) {
          lVar2 = *(longlong *)(lVar4 + 0x10 + lVar2);
LAB_140006fc2:
          if (lVar2 != 0) {
            ExFreePoolWithTag(lVar2,0);
          }
        }
        else if ((iVar1 == 3) || (iVar1 == 4)) {
          lVar2 = *(longlong *)(lVar4 + 0x18 + lVar2);
          goto LAB_140006fc2;
        }
        lVar2 = *(longlong *)(lVar4 + *(longlong *)(param_1 + 0x18));
        if (lVar2 != 0) {
          ExFreePoolWithTag(lVar2,0);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(ushort *)(param_1 + 0x10));
    }
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x18),0);
  }
  return;
}



===== EapOpenAggregatedEventNode @ 140007028 =====

int EapOpenAggregatedEventNode(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 *local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong uStack_10;
  
  local_18 = 0;
  uStack_10 = uStack_10 & 0xffffffff00000000;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = (undefined8 *)0x0;
  uStack_20 = 0;
  local_48 = 0;
  lStack_40 = 0;
  RtlInitUnicodeString(&local_48,0);
  iVar1 = RtlStringFromGUID(param_2,&local_48);
  if (-1 < iVar1) {
    local_28 = &local_48;
    local_38 = CONCAT44(local_38._4_4_,0x30);
    uStack_20 = CONCAT44(uStack_20._4_4_,0x40);
    local_18 = 0;
    uStack_10 = 0;
    uStack_30 = param_1;
    iVar1 = ZwOpenKey(param_3,0xf003f,&local_38);
  }
  if (lStack_40 != 0) {
    RtlFreeUnicodeString(&local_48);
  }
  return iVar1;
}



===== EapQueryAggregatedEventCondition @ 140007100 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong EapQueryAggregatedEventCondition(undefined8 param_1,longlong *param_2,undefined8 *param_3)

{
  short sVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  ulonglong uVar6;
  undefined1 auStackY_e8 [32];
  longlong local_b8;
  undefined8 *local_b0;
  undefined8 local_a8;
  longlong local_a0;
  ulonglong local_98;
  longlong local_90;
  ulonglong local_88;
  undefined8 **local_80;
  code *local_78;
  code *local_70;
  undefined8 local_68;
  code *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_b0 = (undefined8 *)0x0;
  local_a8 = 0;
  local_98 = 0;
  local_88 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_a0 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0;
  local_b8 = 0;
  uVar4 = EapQueryStringValue(param_1,L"Condition",param_3,(undefined2 *)&local_58,param_2);
  uVar6 = uVar4 & 0xffffffff;
  if ((int)uVar4 == -0x3fffffcc) {
    *param_3 = 0;
  }
  else {
    if ((int)uVar4 < 0) goto LAB_140007257;
    uVar3 = RtlGUIDFromString(&local_58,&local_48);
    uVar6 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) goto LAB_140007257;
    uVar3 = EapOpenAggregatedEventNode(param_1,&local_48,&local_b8);
    uVar6 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) goto LAB_140007257;
    local_80 = &local_b0;
    local_68 = 0;
    local_78 = EapQueryAggregatedEventConditionNextChild;
    local_70 = EaDeleteAggregatedEventParametersCloseChild;
    local_60 = EapQueryAggregatedEventConditionPostVisitNode;
    uVar3 = EapTreeTraverse(&local_80,local_b8);
    uVar6 = (ulonglong)uVar3;
    if ((int)uVar3 < 0) goto LAB_140007257;
    puVar5 = (undefined8 *)ExAllocatePool2(0x100,0x28,0x41747645);
    if (puVar5 == (undefined8 *)0x0) {
      uVar6 = 0xc0000017;
      goto LAB_140007257;
    }
    uVar2 = local_b0[1];
    *puVar5 = *local_b0;
    puVar5[1] = uVar2;
    uVar2 = local_b0[3];
    puVar5[2] = local_b0[2];
    puVar5[3] = uVar2;
    puVar5[4] = local_b0[4];
    local_a8._0_4_ = CONCAT22(local_a8._2_2_ + -1,(undefined2)local_a8);
    *param_3 = puVar5;
  }
  uVar6 = 0;
LAB_140007257:
  if (local_b0 != (undefined8 *)0x0) {
    sVar1 = local_a8._2_2_;
    while (sVar1 != 0) {
      local_80 = (undefined8 **)0x0;
      local_78 = EapFreeAggregatedEventConditionNextChild;
      local_70 = (code *)0x0;
      local_60 = EapFreeAggregatedEventConditionPostVisitNode;
      local_68 = 0;
      EapTreeTraverse(&local_80,local_b0);
      sVar1 = local_a8._2_2_ + -1;
      local_a8._0_4_ = CONCAT22(sVar1,(undefined2)local_a8);
    }
    ExFreePoolWithTag(local_b0,0);
  }
  if (local_90 != 0) {
    ExFreePoolWithTag(local_90,0);
    local_90 = 0;
    local_88 = local_88 & 0xffffffff00000000;
  }
  if (local_a0 != 0) {
    ExFreePoolWithTag(local_a0,0);
    local_a0 = 0;
    local_98 = local_98 & 0xffffffff00000000;
  }
  if (local_b8 != 0) {
    ZwClose();
  }
  return uVar6;
}



===== EapQueryAggregatedEventConditionNextChild @ 140007330 =====

ulonglong EapQueryAggregatedEventConditionNextChild
                    (longlong param_1,undefined8 param_2,ushort param_3,longlong *param_4)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong local_res8;
  undefined8 local_58;
  longlong lStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 *local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  
  local_res8 = 0;
  local_28 = 0;
  uStack_20 = uStack_20 & 0xffffffff00000000;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = (undefined8 *)0x0;
  uStack_30 = 0;
  local_58 = 0;
  lStack_50 = 0;
  uVar3 = EapEnumerateKey(param_2,(ulonglong)param_3,(longlong *)(param_1 + 0x10));
  uVar4 = uVar3 & 0xffffffff;
  if ((int)uVar3 == -0x7fffffe6) {
    *param_4 = 0;
    uVar4 = 0;
  }
  else if (-1 < (int)uVar3) {
    lVar1 = *(longlong *)(param_1 + 0x10);
    if (*(uint *)(lVar1 + 0xc) < 0x10000) {
      lStack_50 = lVar1 + 0x10;
      local_58._0_4_ = CONCAT22(*(undefined2 *)(lVar1 + 0xc),*(undefined2 *)(lVar1 + 0xc));
      local_38 = &local_58;
      local_48 = CONCAT44(local_48._4_4_,0x30);
      uStack_30 = CONCAT44(uStack_30._4_4_,0x40);
      local_28 = 0;
      uStack_20 = 0;
      uStack_40 = param_2;
      uVar2 = ZwOpenKey(&local_res8,0xf003f,&local_48);
      lVar1 = local_res8;
      uVar4 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        local_res8 = 0;
        *param_4 = lVar1;
      }
    }
    else {
      uVar4 = 0x80000005;
    }
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  return uVar4;
}



===== EapQueryAggregatedEventConditionPostVisitNode @ 140007440 =====

ulonglong EapQueryAggregatedEventConditionPostVisitNode
                    (longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 uVar5;
  int iVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  void *_Dst;
  uint uVar9;
  ushort uVar10;
  ushort uVar11;
  undefined8 local_78;
  undefined *local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong uStack_40;
  longlong local_38;
  longlong lStack_30;
  undefined4 local_28;
  undefined4 uStack_24;
  
  local_28 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  lStack_30 = 0;
  uVar7 = EapQueryStringValue(param_2,0,param_3,(undefined2 *)&local_58,param_1 + 4);
  if ((int)uVar7 < 0) {
    return uVar7;
  }
  local_64 = 0;
  local_78 = 0x80008;
  local_70 = &EA_STORE_PREDICATE_AND_STRING;
  iVar6 = RtlCompareUnicodeString(&local_78,&local_58,1);
  if (iVar6 == 0) {
    uStack_40 = 0;
LAB_1400074e0:
    iVar6 = 1;
    local_38 = 0;
  }
  else {
    local_68 = 0x60006;
    local_60 = &EA_STORE_PREDICATE_OR_STRING;
    iVar6 = RtlCompareUnicodeString(&local_68,&local_58,1);
    if (iVar6 == 0) {
      uStack_40 = 1;
      goto LAB_1400074e0;
    }
    iVar6 = 0;
  }
  local_48 = CONCAT44(local_48._4_4_,iVar6);
  if (iVar6 == 0) {
    uVar7 = EapQuerySimpleEventParameters(param_2,param_1 + 4,&uStack_40);
    if ((int)uVar7 < 0) {
      return uVar7;
    }
LAB_140007635:
    if (*(ushort *)((longlong)param_1 + 10) == *(ushort *)(param_1 + 1)) {
      _Dst = (void *)ExAllocatePool2(0x100,((ulonglong)*(ushort *)(param_1 + 1) + 5) * 0x30,
                                     0x41747645);
      if (_Dst == (void *)0x0) goto LAB_1400075ac;
      if ((void *)*param_1 != (void *)0x0) {
        memmove(_Dst,(void *)*param_1,(ulonglong)*(ushort *)(param_1 + 1) * 0x30);
        ExFreePoolWithTag(*param_1,0);
      }
      *(short *)(param_1 + 1) = (short)param_1[1] + 5;
      *param_1 = (longlong)_Dst;
    }
    uVar7 = (ulonglong)*(ushort *)((longlong)param_1 + 10);
    lVar4 = *param_1;
    puVar1 = (undefined8 *)(lVar4 + uVar7 * 0x30);
    *puVar1 = local_48;
    puVar1[1] = uStack_40;
    plVar3 = (longlong *)(lVar4 + 0x10 + uVar7 * 0x30);
    *plVar3 = local_38;
    plVar3[1] = lStack_30;
    *(ulonglong *)(lVar4 + 0x20 + uVar7 * 0x30) = CONCAT44(uStack_24,local_28);
    *(short *)(*param_1 + 0x28 + (ulonglong)*(ushort *)((longlong)param_1 + 10) * 0x30) =
         (short)param_3;
    uVar7 = 0;
    *(short *)((longlong)param_1 + 10) = *(short *)((longlong)param_1 + 10) + 1;
  }
  else {
    if (iVar6 != 1) {
      return 0xc00000e5;
    }
    uVar11 = *(ushort *)((longlong)param_1 + 10);
    uVar10 = 0;
    if (uVar11 == 0) goto LAB_140007635;
    uVar9 = ((uint)param_3 & 0xffff) + 1;
    do {
      if (*(ushort *)(*param_1 + -8 + ((ulonglong)uVar11 - (ulonglong)uVar10) * 0x30) != uVar9)
      break;
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar11);
    if (uVar10 == 0) goto LAB_140007635;
    local_38 = ExAllocatePool2(0x100,(ulonglong)uVar10 * 0x28,0x41747645);
    if (local_38 != 0) {
      uVar11 = 0;
      uStack_40 = (ulonglong)CONCAT24(uVar10,(undefined4)uStack_40);
      while (*(ushort *)((longlong)param_1 + 10) != 0) {
        lVar4 = *param_1;
        uVar7 = (ulonglong)*(ushort *)((longlong)param_1 + 10);
        if (*(ushort *)(lVar4 + -8 + uVar7 * 0x30) != uVar9) break;
        puVar2 = (undefined8 *)(lVar4 + -0x30 + uVar7 * 0x30);
        uVar5 = puVar2[1];
        uVar8 = (ulonglong)uVar11;
        puVar1 = (undefined8 *)(local_38 + uVar8 * 0x28);
        *puVar1 = *puVar2;
        puVar1[1] = uVar5;
        puVar1 = (undefined8 *)(lVar4 + -0x20 + uVar7 * 0x30);
        uVar5 = puVar1[1];
        puVar2 = (undefined8 *)(local_38 + 0x10 + uVar8 * 0x28);
        *puVar2 = *puVar1;
        puVar2[1] = uVar5;
        *(undefined8 *)(local_38 + 0x20 + uVar8 * 0x28) =
             *(undefined8 *)(lVar4 + -0x10 + uVar7 * 0x30);
        *(short *)((longlong)param_1 + 10) = *(short *)((longlong)param_1 + 10) + -1;
        uVar11 = uVar11 + 1;
      }
      goto LAB_140007635;
    }
LAB_1400075ac:
    uVar7 = 0xc0000017;
  }
  return uVar7;
}



===== EapQueryAggregatedEventOwnerAppName @ 140007714 =====

ulonglong EapQueryAggregatedEventOwnerAppName
                    (undefined8 param_1,longlong *param_2,undefined8 *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  void *_Dst;
  ulonglong uVar3;
  
  *param_3 = 0;
  uVar2 = EapQueryBuffer(param_1,L"OwnerAppName",1,param_2);
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 == -0x3fffffcc) {
    uVar3 = 0;
  }
  else if (-1 < (int)uVar2) {
    _Dst = (void *)ExAllocatePool2(0x100,(ulonglong)*(uint *)(*param_2 + 0xc) + 2,0x41747645);
    if (_Dst == (void *)0x0) {
      uVar3 = 0xc0000017;
    }
    else {
      memset(_Dst,0,(ulonglong)*(uint *)(*param_2 + 0xc) + 2);
      lVar1 = *param_2;
      memmove(_Dst,(void *)((ulonglong)*(uint *)(lVar1 + 8) + lVar1),
              (ulonglong)*(uint *)(lVar1 + 0xc));
      *param_3 = _Dst;
    }
  }
  return uVar3;
}



===== EapQueryAggregatedEventTrigger @ 1400077d8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong EapQueryAggregatedEventTrigger(undefined8 param_1,longlong *param_2,undefined8 *param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined1 auStackY_78 [32];
  longlong local_48 [6];
  
  local_48[5] = __security_cookie ^ (ulonglong)auStackY_78;
  local_48[0] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  puVar3 = param_3;
  RtlInitUnicodeString(local_48 + 1,0);
  uVar2 = EapQueryStringValue(param_1,L"Trigger",puVar3,(undefined2 *)(local_48 + 1),param_2);
  uVar4 = uVar2 & 0xffffffff;
  if ((int)uVar2 == -0x3fffffcc) {
    *param_3 = 0;
    uVar4 = 0;
  }
  else if (-1 < (int)uVar2) {
    uVar1 = RtlGUIDFromString(local_48 + 1,local_48 + 3);
    uVar4 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      uVar1 = EapOpenAggregatedEventNode(param_1,local_48 + 3,local_48);
      uVar4 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        puVar3 = (undefined8 *)ExAllocatePool2(0x100,0x20,0x41747645);
        if (puVar3 == (undefined8 *)0x0) {
          uVar4 = 0xc0000017;
        }
        else {
          uVar2 = EapQuerySimpleEventParameters(local_48[0],param_2,puVar3);
          uVar4 = uVar2 & 0xffffffff;
          if ((int)uVar2 < 0) {
            ExFreePoolWithTag(puVar3,0);
          }
          else {
            *param_3 = puVar3;
          }
        }
      }
    }
  }
  if (local_48[0] != 0) {
    ZwClose();
  }
  return uVar4;
}



===== EapQueryBuffer @ 140007924 =====

ulonglong EapQueryBuffer(undefined8 param_1,undefined8 param_2,int param_3,longlong *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 local_res20 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res20[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18);
  uVar1 = ZwQueryValueKey(param_1,&local_18,1,*param_4,(int)param_4[1],local_res20);
  if ((uVar1 == 0xc0000023) || (uVar1 == 0x80000005)) {
    uVar2 = EapExpandValueQueryBuffer(param_4,local_res20[0]);
    if ((int)uVar2 < 0) {
      return uVar2 & 0xffffffff;
    }
    uVar1 = ZwQueryValueKey(param_1,&local_18,1,*param_4,(int)param_4[1],local_res20);
  }
  uVar2 = (ulonglong)uVar1;
  if ((-1 < (int)uVar1) && (param_3 != *(int *)(*param_4 + 4))) {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== EapQuerySimpleEventParameters @ 140007a04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong EapQuerySimpleEventParameters(undefined8 param_1,longlong *param_2,undefined8 *param_3)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  void *pvVar4;
  void *_Dst;
  longlong lVar5;
  void *_Src;
  int iVar6;
  longlong *plVar7;
  ushort uVar8;
  ushort uVar9;
  ushort uVar10;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined4 *local_90;
  uint local_88;
  int local_84;
  undefined4 local_7c;
  undefined8 local_78;
  void *local_70;
  undefined8 local_68;
  longlong lStack_60;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_b8;
  local_70 = (void *)0x0;
  _Dst = (void *)0x0;
  local_68 = 0;
  lStack_60 = 0;
  local_50 = 0;
  uStack_48 = 0;
  uVar8 = 0;
  uVar9 = 0;
  local_78 = param_1;
  do {
    uVar10 = 0;
    local_84 = 0;
    iVar6 = 0;
LAB_140007a64:
    local_90 = &local_7c;
    local_98 = (undefined4)param_2[1];
    local_7c = 0;
    local_88 = ZwEnumerateValueKey(local_78,iVar6,1,*param_2);
    if ((local_88 == 0x80000005) || (local_88 == 0xc0000023)) {
      uVar3 = EapExpandValueQueryBuffer(param_2,local_7c);
      local_88 = (uint)uVar3;
      uVar3 = uVar3 & 0xffffffff;
      if (-1 < (int)local_88) {
        local_90 = &local_7c;
        local_98 = (undefined4)param_2[1];
        local_88 = ZwEnumerateValueKey(local_78,local_84,1,*param_2);
        goto LAB_140007ae7;
      }
    }
    else {
LAB_140007ae7:
      uVar3 = (ulonglong)local_88;
    }
    if ((int)uVar3 != -0x7fffffe6) {
      if ((int)uVar3 < 0) {
LAB_140007e69:
        if (_Dst == (void *)0x0) {
          return uVar3;
        }
LAB_140007e72:
        if (uVar9 == 0) goto LAB_140007efc;
        plVar7 = (longlong *)((longlong)_Dst + 0x18);
        uVar3 = (ulonglong)uVar9;
        break;
      }
      lVar5 = *param_2;
      iVar6 = local_84 + 1;
      local_84 = iVar6;
      if (*(int *)(lVar5 + 0x10) == 0) {
        if (*(int *)(lVar5 + 4) != 1) {
LAB_140007e61:
          uVar3 = 0xc000000d;
LAB_140007e66:
          local_88 = (uint)uVar3;
          goto LAB_140007e69;
        }
        if (0xffff < *(uint *)(lVar5 + 0xc)) {
          uVar3 = 0x80000005;
          goto LAB_140007e66;
        }
        lStack_60 = (ulonglong)*(uint *)(lVar5 + 8) + lVar5;
        local_68 = CONCAT62(CONCAT42(local_68._4_4_,*(undefined2 *)(lVar5 + 0xc)),
                            *(undefined2 *)(lVar5 + 0xc));
        iVar2 = RtlGUIDFromString(&local_68,&local_50);
        if (iVar2 < 0) goto LAB_140007dc7;
      }
      else {
        if (_Dst != (void *)0x0) {
          if (uVar10 < uVar9) {
            pvVar4 = (void *)ExAllocatePool2(0x100);
            *(void **)((ulonglong)uVar10 * 0x20 + (longlong)_Dst) = pvVar4;
            if (pvVar4 != (void *)0x0) {
              memset(pvVar4,0,(ulonglong)*(uint *)(*param_2 + 0x10) + 2);
              memmove(*(void **)((ulonglong)uVar10 * 0x20 + (longlong)_Dst),
                      (void *)(*param_2 + 0x14),(ulonglong)*(uint *)(*param_2 + 0x10));
              goto LAB_140007be2;
            }
LAB_140007ea0:
            uVar3 = 0xc0000017;
          }
          else {
LAB_140007ea7:
            uVar3 = 0x80000005;
          }
LAB_140007eac:
          local_88 = (uint)uVar3;
          goto LAB_140007e72;
        }
LAB_140007be2:
        lVar5 = *param_2;
        iVar6 = *(int *)(lVar5 + 4);
        if (iVar6 == 1) {
          if (_Dst != (void *)0x0) {
            lVar5 = (ulonglong)uVar10 * 0x20;
            *(undefined4 *)(lVar5 + 8 + (longlong)_Dst) = 2;
            pvVar4 = (void *)ExAllocatePool2(0x100);
            *(void **)(lVar5 + 0x10 + (longlong)_Dst) = pvVar4;
            if (pvVar4 == (void *)0x0) goto LAB_140007ea0;
            memset(pvVar4,0,(ulonglong)*(uint *)(*param_2 + 0xc) + 2);
            pvVar4 = *(void **)(lVar5 + 0x10 + (longlong)_Dst);
LAB_140007d9d:
            lVar5 = *param_2;
            uVar1 = *(uint *)(lVar5 + 0xc);
            _Src = (void *)((ulonglong)*(uint *)(lVar5 + 8) + lVar5);
LAB_140007daa:
            memmove(pvVar4,_Src,(ulonglong)uVar1);
          }
        }
        else if (iVar6 == 3) {
          if (_Dst != (void *)0x0) {
            lVar5 = (ulonglong)uVar10 * 0x20;
            *(undefined4 *)(lVar5 + 8 + (longlong)_Dst) = 4;
            pvVar4 = (void *)ExAllocatePool2(0x100,*(undefined4 *)(*param_2 + 0xc));
            *(void **)(lVar5 + 0x18 + (longlong)_Dst) = pvVar4;
            if (pvVar4 == (void *)0x0) goto LAB_140007ea0;
            if (0x1fffe < *(uint *)(*param_2 + 0xc)) goto LAB_140007ea7;
            *(undefined2 *)(lVar5 + 0x10 + (longlong)_Dst) = *(undefined2 *)(*param_2 + 0xc);
LAB_140007c9d:
            lVar5 = *param_2;
            uVar1 = *(uint *)(lVar5 + 0xc);
            _Src = (void *)((ulonglong)*(uint *)(lVar5 + 8) + lVar5);
            goto LAB_140007daa;
          }
        }
        else if (iVar6 == 4) {
          if (_Dst != (void *)0x0) {
            if (*(int *)(lVar5 + 0xc) != 4) {
LAB_140007eb1:
              uVar3 = 0xc000000d;
              goto LAB_140007eac;
            }
            lVar5 = (ulonglong)uVar10 * 0x20;
            *(undefined4 *)(lVar5 + 8 + (longlong)_Dst) = 0;
LAB_140007c31:
            pvVar4 = (void *)(lVar5 + 0x10 + (longlong)_Dst);
            goto LAB_140007d9d;
          }
        }
        else if (iVar6 == 7) {
          if (_Dst != (void *)0x0) {
            lVar5 = (ulonglong)uVar10 * 0x20;
            *(undefined4 *)(lVar5 + 8 + (longlong)_Dst) = 3;
            pvVar4 = (void *)ExAllocatePool2(0x100,*(undefined4 *)(*param_2 + 0xc));
            *(void **)(lVar5 + 0x18 + (longlong)_Dst) = pvVar4;
            if (pvVar4 != (void *)0x0) {
              if (0x1fffe < *(uint *)(*param_2 + 0xc)) goto LAB_140007ea7;
              *(short *)(lVar5 + 0x10 + (longlong)_Dst) = (short)(*(uint *)(*param_2 + 0xc) >> 1);
              goto LAB_140007c9d;
            }
            goto LAB_140007ea0;
          }
        }
        else {
          if (iVar6 != 0xb) goto LAB_140007e61;
          if (_Dst != (void *)0x0) {
            if (*(int *)(lVar5 + 0xc) != 8) goto LAB_140007eb1;
            lVar5 = (ulonglong)uVar10 * 0x20;
            *(undefined4 *)(lVar5 + 8 + (longlong)_Dst) = 1;
            goto LAB_140007c31;
          }
        }
        uVar10 = uVar10 + 1;
        iVar6 = local_84;
      }
      goto LAB_140007a64;
    }
LAB_140007dc7:
    if (uVar10 == 0) {
LAB_140007f16:
      param_3[3] = _Dst;
      *(ushort *)(param_3 + 2) = uVar9;
      *param_3 = local_50;
      param_3[1] = uStack_48;
      return 0;
    }
    if (uVar8 == 0) {
      _Dst = (void *)ExAllocatePool2(0x100,(ulonglong)uVar10 << 5,0x41747645);
      if (_Dst == (void *)0x0) {
        return 0xc0000017;
      }
      local_70 = _Dst;
      memset(_Dst,0,(ulonglong)uVar10 << 5);
      uVar8 = 1;
      uVar9 = uVar10;
    }
    else {
      uVar8 = uVar8 + 1;
      if (1 < uVar8) goto LAB_140007f16;
      local_70 = _Dst;
    }
  } while( true );
LAB_140007e8c:
  iVar6 = (int)plVar7[-2];
  if (iVar6 == 2) {
    lVar5 = plVar7[-1];
LAB_140007ebc:
    if (lVar5 != 0) {
      ExFreePoolWithTag(lVar5,0,0);
    }
  }
  else if ((iVar6 == 3) || (iVar6 == 4)) {
    lVar5 = *plVar7;
    goto LAB_140007ebc;
  }
  if (plVar7[-3] != 0) {
    ExFreePoolWithTag();
  }
  plVar7 = plVar7 + 4;
  uVar3 = uVar3 - 1;
  if (uVar3 == 0) {
    uVar3 = (ulonglong)local_88;
    _Dst = local_70;
LAB_140007efc:
    ExFreePoolWithTag(_Dst,0);
    return uVar3;
  }
  goto LAB_140007e8c;
}



===== EapQueryStringValue @ 140007f5c =====

ulonglong EapQueryStringValue(undefined8 param_1,undefined8 param_2,undefined8 param_3,
                             undefined2 *param_4,longlong *param_5)

{
  undefined2 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  if (param_4 != (undefined2 *)0x0) {
    RtlInitUnicodeString(param_4,0);
    uVar3 = EapQueryBuffer(param_1,param_2,1,param_5);
    if ((int)uVar3 < 0) {
      return uVar3 & 0xffffffff;
    }
    lVar2 = *param_5;
    if (*(uint *)(lVar2 + 0xc) < 0x10000) {
      *(ulonglong *)(param_4 + 4) = (ulonglong)*(uint *)(lVar2 + 8) + lVar2;
      uVar1 = *(undefined2 *)(*param_5 + 0xc);
      param_4[1] = uVar1;
      *param_4 = uVar1;
      return uVar3 & 0xffffffff;
    }
  }
  return 0xc000000d;
}



===== EapQueryValue @ 140007ff8 =====

ulonglong EapQueryValue(undefined8 param_1,undefined8 param_2,int param_3,undefined8 param_4,
                       void *param_5,uint param_6,longlong *param_7)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  if (param_5 == (void *)0x0) {
    uVar3 = 0xc000000d;
  }
  else {
    uVar2 = EapQueryBuffer(param_1,param_2,param_3,param_7);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 == -0x3fffffcc) {
      uVar3 = 0;
    }
    else if (-1 < (int)uVar2) {
      lVar1 = *param_7;
      if (param_6 < *(uint *)(lVar1 + 0xc)) {
        uVar3 = 0xc0000023;
      }
      else {
        memmove(param_5,(void *)((ulonglong)*(uint *)(lVar1 + 8) + lVar1),
                (ulonglong)*(uint *)(lVar1 + 0xc));
      }
    }
  }
  return uVar3;
}



===== EapSetValue @ 14000806c =====

void EapSetValue(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                undefined4 param_5)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18);
  ZwSetValueKey(param_1,&local_18,0,param_3,param_4,param_5);
  return;
}



===== EapStoreAggregatedEventCondition @ 1400080dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EapStoreAggregatedEventCondition(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  int iVar2;
  undefined1 auStackY_98 [32];
  longlong local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  longlong lStack_50;
  longlong *local_48;
  code *local_40;
  undefined8 local_38;
  code *local_30;
  code *local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_98;
  local_20 = 0;
  uStack_18 = 0;
  local_58 = 0;
  lStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  RtlInitUnicodeString(&local_58,0);
  local_68 = ExAllocatePool2(0x100,0x78,0x41747645);
  if (local_68 == 0) {
    iVar2 = -0x3fffffe9;
  }
  else {
    local_38 = 0;
    *(undefined8 *)(local_68 + (ulonglong)uStack_60._2_2_ * 0x18) = param_1;
    local_48 = &local_68;
    uStack_60._0_4_ = CONCAT22(uStack_60._2_2_ + 1,5);
    local_40 = EapFreeAggregatedEventConditionNextChild;
    local_30 = EapStoreAggregatedEventConditionPreVisitNode;
    local_28 = EapStoreAggregatedEventConditionPostVisitNode;
    iVar2 = EapTreeTraverse(&local_48,param_2);
    if (-1 < iVar2) {
      puVar1 = (undefined8 *)(local_68 + -0x10 + (ulonglong)uStack_60._2_2_ * 0x18);
      local_20 = *puVar1;
      uStack_18 = puVar1[1];
      uStack_60._0_4_ = CONCAT22(uStack_60._2_2_ - 1,(undefined2)uStack_60);
      iVar2 = RtlStringFromGUID(&local_20,&local_58);
      if (-1 < iVar2) {
        iVar2 = EapSetValue(param_1,L"Condition",1,lStack_50,(uint)(ushort)local_58);
      }
    }
  }
  if (local_68 != 0) {
    ExFreePoolWithTag(local_68,0);
  }
  if (lStack_50 != 0) {
    RtlFreeUnicodeString(&local_58);
  }
  return iVar2;
}



===== EapStoreAggregatedEventConditionPostVisitNode @ 140008280 =====

undefined8 EapStoreAggregatedEventConditionPostVisitNode(longlong *param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(*param_1 + -0x18 + (ulonglong)*(ushort *)((longlong)param_1 + 10) * 0x18);
  *(ushort *)((longlong)param_1 + 10) = *(ushort *)((longlong)param_1 + 10) - 1;
  if (lVar1 != 0) {
    ZwClose(lVar1);
  }
  return 0;
}



===== EapStoreAggregatedEventConditionPreVisitNode @ 1400082c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EapStoreAggregatedEventConditionPreVisitNode(longlong *param_1,int *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  RPC_STATUS RVar3;
  int iVar4;
  undefined4 uVar5;
  void *_Dst;
  longlong lVar6;
  undefined *puVar7;
  undefined1 auStackY_78 [32];
  longlong local_48;
  UUID local_40;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar6 = 0;
  local_40.Data1 = 0;
  local_40.Data2 = 0;
  local_40.Data3 = 0;
  local_40.Data4[0] = '\0';
  local_40.Data4[1] = '\0';
  local_40.Data4[2] = '\0';
  local_40.Data4[3] = '\0';
  local_40.Data4[4] = '\0';
  local_40.Data4[5] = '\0';
  local_40.Data4[6] = '\0';
  local_40.Data4[7] = '\0';
  local_48 = 0;
  uVar2 = *(undefined8 *)(*param_1 + -0x18 + (ulonglong)*(ushort *)((longlong)param_1 + 10) * 0x18);
  RVar3 = UuidCreate(&local_40);
  if (RVar3 != 0) {
    iVar4 = -0x3fffff1b;
    goto LAB_140008454;
  }
  iVar4 = EapCreateAggregatedEventNode(uVar2,&local_40,&local_48);
  lVar6 = local_48;
  if (iVar4 < 0) goto LAB_140008454;
  if (*param_2 == 0) {
    iVar4 = EapStoreSimpleEventParameters(local_48,(longlong)(param_2 + 2));
  }
  else {
    if (*param_2 != 1) {
      iVar4 = -0x3ffffff3;
      goto LAB_140008454;
    }
    if (param_2[2] == 0) {
      puVar7 = &EA_STORE_PREDICATE_AND_STRING;
      uVar5 = 8;
    }
    else {
      if (param_2[2] != 1) {
        iVar4 = -0x3ffffff3;
        goto LAB_1400083af;
      }
      puVar7 = &EA_STORE_PREDICATE_OR_STRING;
      uVar5 = 6;
    }
    iVar4 = EapSetValue(local_48,0,1,puVar7,uVar5);
  }
LAB_1400083af:
  if (-1 < iVar4) {
    if (*(ushort *)((longlong)param_1 + 10) == *(ushort *)(param_1 + 1)) {
      _Dst = (void *)ExAllocatePool2(0x100,((ulonglong)*(ushort *)(param_1 + 1) + 5) * 0x18,
                                     0x41747645);
      if (_Dst == (void *)0x0) goto LAB_140008454;
      if ((void *)*param_1 != (void *)0x0) {
        memmove(_Dst,(void *)*param_1,(ulonglong)*(ushort *)(param_1 + 1) * 0x18);
        ExFreePoolWithTag(*param_1,0);
      }
      *(short *)(param_1 + 1) = (short)param_1[1] + 5;
      *param_1 = (longlong)_Dst;
    }
    puVar1 = (undefined8 *)
             (*param_1 + -0x10 + (ulonglong)*(ushort *)((longlong)param_1 + 10) * 0x18);
    *puVar1 = local_40._0_8_;
    *(uchar (*) [8])(puVar1 + 1) = local_40.Data4;
    *(longlong *)(*param_1 + (ulonglong)*(ushort *)((longlong)param_1 + 10) * 0x18) = lVar6;
    lVar6 = 0;
    *(short *)((longlong)param_1 + 10) = *(short *)((longlong)param_1 + 10) + 1;
    iVar4 = 0;
  }
LAB_140008454:
  if (lVar6 != 0) {
    ZwClose(lVar6);
  }
  return iVar4;
}



===== EapStoreAggregatedEventTrigger @ 140008494 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EapStoreAggregatedEventTrigger(undefined8 param_1,longlong param_2)

{
  RPC_STATUS RVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auStackY_88 [32];
  longlong local_58;
  undefined8 local_50;
  longlong lStack_48;
  UUID local_40;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_88;
  local_50 = 0;
  lStack_48 = 0;
  local_40.Data1 = 0;
  local_40.Data2 = 0;
  local_40.Data3 = 0;
  local_40.Data4[0] = '\0';
  local_40.Data4[1] = '\0';
  local_40.Data4[2] = '\0';
  local_40.Data4[3] = '\0';
  local_40.Data4[4] = '\0';
  local_40.Data4[5] = '\0';
  local_40.Data4[6] = '\0';
  local_40.Data4[7] = '\0';
  RtlInitUnicodeString(&local_50,0);
  lVar3 = 0;
  local_58 = 0;
  RVar1 = UuidCreate(&local_40);
  if (RVar1 == 0) {
    iVar2 = EapCreateAggregatedEventNode(param_1,&local_40,&local_58);
    lVar3 = local_58;
    if (-1 < iVar2) {
      iVar2 = EapStoreSimpleEventParameters(local_58,param_2);
      if (-1 < iVar2) {
        iVar2 = RtlStringFromGUID(&local_40,&local_50);
        if (-1 < iVar2) {
          iVar2 = EapSetValue(param_1,L"Trigger",1,lStack_48,(uint)(ushort)local_50);
          if (-1 < iVar2) {
            iVar2 = 0;
          }
        }
      }
    }
  }
  else {
    iVar2 = -0x3fffff1b;
  }
  if (lStack_48 != 0) {
    RtlFreeUnicodeString(&local_50);
  }
  if (lVar3 != 0) {
    ZwClose(lVar3);
  }
  return iVar2;
}



===== EapStoreSimpleEventParameters @ 1400085c4 =====

int EapStoreSimpleEventParameters(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  ushort uVar6;
  undefined4 uVar7;
  longlong lVar8;
  undefined8 local_28;
  longlong lStack_20;
  
  local_28 = 0;
  lStack_20 = 0;
  iVar2 = RtlStringFromGUID(param_2);
  if (-1 < iVar2) {
    iVar2 = EapSetValue(param_1,0,1,lStack_20,(uint)(ushort)local_28);
    if ((-1 < iVar2) && (uVar6 = 0, *(short *)(param_2 + 0x10) != 0)) {
      do {
        lVar1 = *(longlong *)(param_2 + 0x18);
        lVar5 = (ulonglong)uVar6 * 0x20;
        iVar2 = *(int *)(lVar5 + 8 + lVar1);
        if (iVar2 == 0) {
          uVar7 = 4;
          uVar3 = 4;
LAB_1400086c9:
          lVar8 = lVar1 + 0x10 + lVar5;
        }
        else {
          if (iVar2 == 1) {
            uVar7 = 0xb;
            uVar3 = 8;
            goto LAB_1400086c9;
          }
          if (iVar2 == 2) {
            lVar8 = *(longlong *)(lVar5 + 0x10 + lVar1);
            uVar7 = 1;
            lVar4 = -1;
            do {
              lVar4 = lVar4 + 1;
            } while (*(short *)(lVar8 + lVar4 * 2) != 0);
            uVar3 = (int)lVar4 * 2 + 2;
          }
          else if (iVar2 == 3) {
            uVar7 = 7;
            lVar8 = *(longlong *)(lVar5 + 0x18 + lVar1);
            uVar3 = (uint)*(ushort *)(lVar5 + 0x10 + lVar1) * 2;
          }
          else {
            if (iVar2 != 4) {
              iVar2 = -0x3fffff1b;
              break;
            }
            lVar8 = *(longlong *)(lVar5 + 0x18 + lVar1);
            uVar7 = 3;
            uVar3 = (uint)*(ushort *)(lVar5 + 0x10 + lVar1);
          }
        }
        iVar2 = EapSetValue(param_1,*(undefined8 *)(lVar5 + lVar1),uVar7,lVar8,uVar3);
        if ((iVar2 < 0) || (uVar6 = uVar6 + 1, *(ushort *)(param_2 + 0x10) <= uVar6)) break;
      } while( true );
    }
  }
  if (lStack_20 != 0) {
    RtlFreeUnicodeString(&local_28);
  }
  return iVar2;
}



===== EapSystemBriCreateRpcBindingHandle @ 140008738 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int EapSystemBriCreateRpcBindingHandle
              (UUID *param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined1 auStack_108 [32];
  RPC_BINDING_HANDLE local_e8;
  RPC_STATUS local_e0 [2];
  undefined4 local_d8;
  undefined8 local_d4;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined8 local_c0;
  undefined4 *local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_108;
  local_e8 = (RPC_BINDING_HANDLE)0x0;
  local_6c = 0;
  local_88 = 0;
  local_d4 = 0;
  local_cc = 0;
  local_c0 = 0;
  local_78 = 1;
  local_70 = 5;
  local_48 = 0;
  local_b0 = 5;
  local_b8 = &local_b0;
  local_58 = 0;
  uStack_50 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_68 = 0x100000001;
  uStack_40._0_4_ = param_1->Data1;
  uStack_40._4_2_ = param_1->Data2;
  uStack_40._6_2_ = param_1->Data3;
  uStack_38 = *(undefined4 *)param_1->Data4;
  uStack_34 = *(undefined4 *)(param_1->Data4 + 4);
  local_74 = 1;
  local_ac = 1;
  local_a8 = 1;
  local_d8 = 1;
  uStack_60 = 3;
  local_a4 = 2;
  local_c8 = 6;
  local_c4 = 0x14;
  local_90 = param_2;
  local_80 = param_3;
  iVar1 = RpcBindingCreateW(&local_68,&local_d8,&local_78,&local_e8);
  if (iVar1 == 0) {
    local_e0[0] = 0;
    iVar1 = UuidEqual(param_1,(UUID *)&g_SmsRouterBrokerId,local_e0);
    puVar2 = &DAT_14000b360;
    if (iVar1 == 0) {
      puVar2 = &DAT_14000b460;
    }
    iVar1 = RpcBindingBind(0,local_e8,puVar2);
    if (iVar1 == 0) {
      *param_4 = (longlong)local_e8;
      local_e8 = (RPC_BINDING_HANDLE)0x0;
    }
  }
  if (local_e8 != (RPC_BINDING_HANDLE)0x0) {
    RpcBindingFree(&local_e8);
  }
  return iVar1;
}



===== EapSystemBriDeleteEvent @ 14000889c =====

/* WARNING: Restarted to delay deadcode elimination for space: register */

void EapSystemBriDeleteEvent(UUID *param_1,undefined8 param_2)

{
  int iVar1;
  undefined **pProxyInfo;
  ulong nProcNum;
  RPC_STATUS local_18 [4];
  
  local_18[0] = 0;
  iVar1 = UuidEqual(param_1,(UUID *)&g_SmsRouterBrokerId,local_18);
  if (iVar1 == 0) {
    nProcNum = 2;
    pProxyInfo = &PTR_PTR_14000b860;
  }
  else {
    nProcNum = 1;
    pProxyInfo = &PTR_PTR_14000b428;
  }
  NdrClientCall3((MIDL_STUBLESS_PROXY_INFO *)pProxyInfo,nProcNum,(void *)0x0,param_2);
  return;
}



===== EaLibAllocate @ 140008920 =====

void EaLibAllocate(undefined8 param_1,char param_2)

{
  ExAllocatePool2((-(uint)(param_2 != '\0') & 0xc0) + 0x40,param_1,0x41747645);
  return;
}



===== EaLibTimeLimitCallback @ 140008960 =====

void EaLibTimeLimitCallback(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_2 + 0x88);
  *puVar1 = 0;
  puVar1[3] = param_2;
  puVar1[2] = EaLibTimeLimitCallbackWorker;
  ExQueueWorkItem(*(undefined8 *)(param_2 + 0x88),0);
  return;
}



===== wil_details_RecordCachedUsage @ 1400089a4 =====

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



===== wil_details_RecordFeatureUsageReporting @ 140008b00 =====

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



===== Feature_382177595__private_IsEnabledDeviceUsageNoInline @ 140008b84 =====

ulonglong Feature_382177595__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_382177595__private_featureState;
  if ((Feature_382177595__private_featureState & 0x10) == 0) {
    uVar1 = Feature_382177595__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_382177595__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_382177595__private_IsEnabledFallback @ 140008bbc =====

void Feature_382177595__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140008bd4 =====

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
LAB_140008ddd:
    uVar6 = *param_2;
    do {
      uVar4 = uVar6;
      param_1[1] = 0;
      uVar6 = uVar4 | 1;
      if ((uVar4 >> 0xe & 1) != (uint)(param_3 == 4)) {
        uVar3 = uVar4 >> 5 & 0x1ff;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          param_1[2] = ~-(uint)(param_3 != 0) & 4;
          uVar6 = uVar4 & 0xffffc01f | 1;
        }
        uVar3 = 0;
        if (param_3 == 4) {
          uVar3 = 0x4000;
        }
        uVar6 = uVar3 | uVar6 & 0xffffbfff;
      }
      uVar5 = uVar6 >> 5 & 0x1ff;
      uVar3 = uVar5 + 1;
      if ((0x1ff < uVar3) || (uVar3 < uVar5)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar5;
      }
      LOCK();
      uVar5 = *param_2;
      if (uVar4 == uVar5) {
        *param_2 = (uVar3 << 5 ^ uVar6) & 0x3fe0 ^ uVar6;
        uVar6 = uVar4;
      }
      else {
        uVar6 = uVar5;
      }
      UNLOCK();
    } while (uVar4 != uVar5);
    *param_1 = ~uVar4 & 1;
  }
  else {
    if (param_3 != 1) {
      if ((param_3 == 2) || (param_3 == 3)) {
LAB_140008caf:
        uVar6 = 0;
        if (param_3 == 2) {
          uVar6 = 2;
        }
        else if (param_3 == 3) {
          uVar6 = 8;
        }
        else if (param_3 == 6) {
          uVar6 = 4;
        }
        else if (param_3 == 7) {
          uVar6 = 0x10;
        }
        uVar3 = 1;
        uVar4 = *param_2;
        do {
          uVar2 = uVar4;
          uVar4 = uVar6 | uVar2;
          param_1[4] = (uint)(uVar4 == uVar2);
          uVar5 = uVar4 | 1;
          if (uVar4 == uVar2) {
            uVar5 = uVar4;
          }
          LOCK();
          uVar1 = *param_2;
          if (uVar2 == uVar1) {
            *param_2 = uVar5;
            uVar4 = uVar2;
          }
          else {
            uVar4 = uVar1;
          }
          UNLOCK();
        } while (uVar2 != uVar1);
        if (((uVar5 & 1) == 0) || ((uVar2 & 1) != 0)) {
          uVar3 = 0;
        }
        *param_1 = uVar3;
        return param_1;
      }
      if (param_3 == 4) goto LAB_140008ddd;
      if (param_3 != 5) {
        if ((param_3 != 6) && (param_3 != 7)) {
          uVar6 = param_3 - 0x140;
          if ((int)uVar6 < 0x40) {
            uVar4 = param_2[1];
            do {
              if (((uVar4 & 0x10) == 0) || ((uVar4 >> 5 & 0x3f) != uVar6)) {
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
                param_2[1] = (uVar6 * 0x20 ^ uVar4) & 0x7e0 ^ uVar4 | 0x10;
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
        goto LAB_140008caf;
      }
    }
    uVar6 = *param_2;
    do {
      uVar4 = uVar6;
      param_1[1] = 0;
      uVar6 = uVar4 | 1;
      if ((uVar4 >> 0x16 & 1) != (uint)(param_3 == 5)) {
        uVar3 = uVar4 >> 0xf & 0x7f;
        if (uVar3 != 0) {
          param_1[1] = uVar3;
          uVar3 = 5;
          if (param_3 != 1) {
            uVar3 = 1;
          }
          uVar6 = uVar4 & 0xffc07fff | 1;
          param_1[2] = uVar3;
        }
        uVar3 = 0;
        if (param_3 == 5) {
          uVar3 = 0x400000;
        }
        uVar6 = uVar3 | uVar6 & 0xffbfffff;
      }
      uVar5 = uVar6 >> 0xf & 0x7f;
      uVar3 = uVar5 + 1;
      if ((0x7f < uVar3) || (uVar3 < uVar5)) {
        uVar3 = 1;
        param_1[2] = param_3;
        param_1[1] = uVar5;
      }
      LOCK();
      uVar5 = *param_2;
      if (uVar4 == uVar5) {
        *param_2 = (uVar3 << 0xf ^ uVar6) & 0x3f8000 ^ uVar6;
        uVar6 = uVar4;
      }
      else {
        uVar6 = uVar5;
      }
      UNLOCK();
    } while (uVar4 != uVar5);
    *param_1 = ~uVar4 & 1;
  }
  param_1[4] = 0;
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 140008ec8 =====

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
      goto LAB_140008f8b;
    }
    if (param_3 == 2) {
      uVar2 = (uVar4 ^ 1) * 4 + 1;
      uVar3 = 0;
      goto LAB_140008f8b;
    }
    if (param_3 == 3) {
      uVar2 = (uVar4 ^ 1) * 4 + 2;
      uVar3 = 0;
      goto LAB_140008f8b;
    }
    if (param_3 == 4) {
      uVar2 = (uVar4 ^ 1) * 4 + 3;
      uVar3 = 0;
      goto LAB_140008f8b;
    }
    uVar2 = param_3 - 5;
    uVar3 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = (uVar4 ^ 1) * 2 + 8;
      goto LAB_140008f8b;
    }
    if (uVar2 == 1) {
      uVar2 = (uVar4 ^ 1) * 2 + 9;
      goto LAB_140008f8b;
    }
    bVar5 = (char)param_3 + 0x9c;
    if (bVar5 < 0x32) {
      uVar2 = (-(uint)((param_2 & 1) != 0) & 0xffffffce) + 0x96 + (uint)bVar5;
      goto LAB_140008f8b;
    }
  }
  uVar2 = 0xff;
LAB_140008f8b:
  local_res18[0] = param_3;
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(uVar3,param_2,uVar2);
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (0x3b8ef9b,&Feature_382177595_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140008fe4 =====

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
                     (local_50,&Feature_382177595__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)(0x3b8ef9b,param_3,1,&Feature_382177595__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)param_3,0x3b8ef9b);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400090d0 =====

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
LAB_140009183:
    uVar8 = uVar8 << 10;
    if (uVar5 != 0) {
      uVar5 = 0x800;
      goto LAB_1400091b1;
    }
  }
  else {
    uVar8 = 0;
    uVar5 = 0;
    uVar11 = (uint)local_70;
    if (iVar4 != 0x117) goto LAB_140009183;
    bVar2 = 1;
    uVar8 = (local_58._4_4_ >> 7 & 1) << 10;
  }
  uVar5 = 0;
LAB_1400091b1:
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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000933c =====

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
  if ((Feature_382177595__private_featureState & 2) != 0) {
    uVar1 = Feature_382177595__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_382177595__private_featureState;
      if (bVar3) {
        Feature_382177595__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_382177595__private_featureState;
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



===== wil_details_IsEnabledFallback @ 140009390 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_382177595__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_382177595__private_featureState,(ulonglong)param_1,0x14000dc90
                            );
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



===== _guard_check_icall @ 140009430 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 140009448 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000946c =====

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



===== __cpu_features_init @ 1400094e0 =====

/* WARNING: Removing unreachable block (ram,0x00014000954a) */
/* WARNING: Removing unreachable block (ram,0x0001400094f9) */
/* WARNING: Removing unreachable block (ram,0x0001400094ea) */

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



===== __security_check_cookie @ 1400095b0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1400095f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140009620 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140009620. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140009650 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 1400096c0 =====

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



===== memset @ 1400099c0 =====

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



===== __memset_repmovs @ 140009b00 =====

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



===== __memset_query @ 140009b80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140009c00 =====

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



===== __memset_spec_ermsb_repmovsb @ 140009d40 =====

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



===== __memset_spec_plain @ 140009dc0 =====

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



===== EaDecodeBrokeredEvent @ 140011010 =====

ulonglong EaDecodeBrokeredEvent(char *param_1,ushort param_2,undefined8 *param_3)

{
  ulonglong uVar1;
  ushort *puVar2;
  ulonglong uVar3;
  ushort local_res20 [4];
  
                    /* 0x11010  17  EaDecodeBrokeredEvent */
  local_res20[0] = 0;
  puVar2 = (ushort *)0x0;
  uVar1 = BrpDecodeBrokeredEvent_V1(param_1,param_2,0,(ushort *)0x0,local_res20);
  if ((int)uVar1 == -0x3fffffdd) {
    puVar2 = (ushort *)EaLibAllocate((ulonglong)local_res20[0],'\x01');
    if (puVar2 == (ushort *)0x0) {
      return 0xc0000017;
    }
    uVar1 = BrpDecodeBrokeredEvent_V1(param_1,param_2,local_res20[0],puVar2,local_res20);
  }
  uVar3 = uVar1 & 0xffffffff;
  if ((int)uVar1 < 0) {
    if (puVar2 != (ushort *)0x0) {
      EaFreeBuffer(puVar2);
    }
  }
  else {
    *param_3 = puVar2;
    uVar3 = 0;
  }
  return uVar3;
}



===== EaEncodeBrokeredEvent @ 1400110d0 =====

ulonglong EaEncodeBrokeredEvent(ushort *param_1,longlong *param_2,ushort *param_3)

{
  ushort uVar1;
  ulonglong uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ushort uVar5;
  ushort local_res8 [4];
  
                    /* 0x110d0  23  EaEncodeBrokeredEvent */
  local_res8[0] = 0;
  lVar3 = 0;
  if ((param_1 == (ushort *)0x0) || (param_2 == (longlong *)0x0)) {
    uVar4 = 0xc000000d;
  }
  else {
    uVar2 = BrpEncodeBrokeredEvent_V1(param_1,0,0,local_res8);
    uVar1 = local_res8[0];
    uVar5 = 0;
    if ((int)uVar2 == -0x3fffffdd) {
      lVar3 = EaLibAllocate((ulonglong)local_res8[0],'\x01');
      if (lVar3 == 0) {
        return 0xc0000017;
      }
      uVar2 = BrpEncodeBrokeredEvent_V1(param_1,uVar1,lVar3,local_res8);
      uVar5 = uVar1;
    }
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      if (lVar3 != 0) {
        EaFreeBuffer(lVar3);
      }
    }
    else {
      *param_3 = uVar5;
      uVar4 = 0;
      *param_2 = lVar3;
    }
  }
  return uVar4;
}



===== AggregateEventWnfCallback @ 1400111a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int AggregateEventWnfCallback
              (undefined8 param_1,longlong *param_2,undefined8 param_3,uint param_4,
              undefined8 param_5,longlong param_6)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  undefined1 auStackY_d8 [32];
  uint local_a8 [2];
  uint local_a0 [2];
  int local_98 [2];
  longlong local_90;
  undefined8 local_88 [4];
  longlong *local_68;
  undefined4 local_60;
  undefined4 local_5c;
  int *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48 [2];
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_d8;
  puVar3 = local_48;
  local_a8[0] = 8;
  bVar1 = false;
  local_a0[0] = param_4;
  EaLibAcquireLockExclusive(param_6 + 0x90);
  puVar5 = local_a8;
  puVar4 = local_48;
  iVar2 = ExQueryWnfStateData(param_1,local_a0);
  if (iVar2 == -0x3fffffdd) {
    bVar1 = true;
    puVar3 = (uint *)EaLibAllocate((ulonglong)local_a8[0],'\x01');
    if (puVar3 == (uint *)0x0) {
      iVar2 = -0x3fffffe9;
      goto LAB_14001127e;
    }
    puVar5 = local_a8;
    puVar4 = puVar3;
    iVar2 = ExQueryWnfStateData(param_1,local_a0);
  }
  if (-1 < iVar2) {
    puVar4 = (uint *)(ulonglong)local_a0[0];
    puVar5 = puVar3;
    iVar2 = WnfEventCallback(param_6,param_2,(ulonglong)puVar4,puVar3,local_a8[0]);
  }
  if (bVar1) {
    EaFreeBuffer(puVar3);
  }
LAB_14001127e:
  *(undefined8 *)(param_6 + 0x98) = 0;
  ExReleasePushLockExclusiveEx(param_6 + 0x90,0);
  if ((iVar2 < 0) && (2 < DAT_14000e000)) {
    local_5c = 0;
    local_68 = &local_90;
    local_4c = 0;
    local_58 = local_98;
    local_90 = param_6;
    local_60 = 8;
    local_50 = 4;
    local_98[0] = iVar2;
    _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_14000cf57,puVar4,puVar5,4,local_88);
  }
  return iVar2;
}



===== DllUnload @ 140011320 =====

undefined8 DllUnload(void)

{
  undefined8 uVar1;
  
                    /* 0x11320  10  DllUnload */
  CleanupLibrary();
  if (g_wil_details_featureChangeNotification != 0) {
    RtlUnregisterFeatureConfigurationChangeNotification();
    g_wil_details_featureChangeNotification = 0;
  }
  if (g_wil_details_featureUsageProvider != 0) {
    RtlUnregisterFeatureUsageProvider();
    g_wil_details_featureUsageProvider = 0;
  }
  uVar1 = DAT_14000e020;
  DAT_14000e020 = 0;
  g_wil_details_isFeatureStagingInitialized = 0;
  DAT_14000e000 = 0;
  EtwUnregister(uVar1);
  return 0;
}



===== EaLibAcquireLockExclusive @ 1400113a0 =====

void EaLibAcquireLockExclusive(longlong param_1)

{
  ExAcquirePushLockExclusiveEx(param_1,0);
  *(void **)(param_1 + 8) = SystemReserved1[0xf];
  return;
}



===== EaLibAcquireLockShared @ 1400113d4 =====

void EaLibAcquireLockShared(undefined8 param_1)

{
  ExAcquirePushLockSharedEx(param_1,0);
  return;
}



===== EaLibClearAndReleaseTimer @ 1400113f4 =====

void EaLibClearAndReleaseTimer(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  
  if ((*(char *)(param_1 + 0x78) != '\0') && (lVar1 = *(longlong *)(param_1 + 0x80), lVar1 != 0)) {
    *(undefined8 *)(param_1 + 0x80) = 0;
    *(undefined1 *)(param_1 + 0x78) = 0;
    cVar2 = KeCancelTimer(lVar1 + 8);
    if (cVar2 != '\0') {
      EaFreeBuffer(*(undefined8 *)(lVar1 + 0x88));
      EaFreeBuffer(lVar1);
      LOCK();
      *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + -1;
      UNLOCK();
    }
  }
  return;
}



===== EaLibConvertLockSharedToExclusive @ 140011460 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong EaLibConvertLockSharedToExclusive(void)

{
  ExReleasePushLockSharedEx(&BrokerBindingTableLock,0);
  ExAcquirePushLockExclusiveEx(&BrokerBindingTableLock,0);
  _DAT_14000e148 = SystemReserved1[0xf];
  return (ulonglong)SystemReserved1[0xf] & 0xffffffffffffff00;
}



===== EaLibCreateAndSetLimitTimer @ 1400114ac =====

undefined8 EaLibCreateAndSetLimitTimer(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar4 = 0;
  if (*(int *)(*(longlong *)(param_1 + 0x38) + 0x20) != 0) {
    lVar2 = EaLibAllocate(0x90,'\0');
    *(longlong *)(param_1 + 0x80) = lVar2;
    if (lVar2 == 0) {
      uVar4 = 0xc0000017;
    }
    else {
      uVar3 = EaLibAllocate(0x20,'\0');
      *(undefined8 *)(*(longlong *)(param_1 + 0x80) + 0x88) = uVar3;
      plVar1 = *(longlong **)(param_1 + 0x80);
      if (plVar1[0x11] == 0) {
        uVar4 = 0xc0000017;
        if (plVar1 != (longlong *)0x0) {
          if (plVar1[0x11] != 0) {
            EaFreeBuffer(plVar1[0x11]);
          }
          EaFreeBuffer(*(undefined8 *)(param_1 + 0x80));
          *(undefined8 *)(param_1 + 0x80) = 0;
        }
      }
      else {
        *plVar1 = param_1;
        KeInitializeDpc(*(longlong *)(param_1 + 0x80) + 0x48,EaLibTimeLimitCallback);
        KeInitializeTimer(*(longlong *)(param_1 + 0x80) + 8);
        KeSetTimer(*(longlong *)(param_1 + 0x80) + 8,
                   (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x38) + 0x20) * -10000000,
                   *(longlong *)(param_1 + 0x80) + 0x48);
        *(undefined1 *)(param_1 + 0x78) = 1;
        LOCK();
        *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
        UNLOCK();
      }
    }
  }
  return uVar4;
}



===== EaLibGetCurrentThreadId @ 1400115cc =====

void EaLibGetCurrentThreadId(void)

{
  PsGetCurrentThreadId();
  return;
}



===== EaLibInitializeWnfSerialization @ 1400115e8 =====

void EaLibInitializeWnfSerialization(longlong param_1)

{
  *(undefined8 *)(param_1 + 0x98) = 0;
  *(undefined8 *)(param_1 + 0x90) = 0;
  return;
}



===== EaLibLockInitialize @ 140011600 =====

void EaLibLockInitialize(undefined8 *param_1)

{
  param_1[1] = 0;
  *param_1 = 0;
  return;
}



===== EaLibQueryWnfStateData @ 140011614 =====

void EaLibQueryWnfStateData
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ZwQueryWnfStateData(param_1,0,0,param_2,param_3,param_4);
  return;
}



===== EaLibReleaseLockExclusive @ 140011644 =====

void EaLibReleaseLockExclusive(longlong param_1)

{
  *(undefined8 *)(param_1 + 8) = 0;
  ExReleasePushLockExclusiveEx(param_1,0);
  return;
}



===== EaLibReleaseLockShared @ 140011668 =====

void EaLibReleaseLockShared(undefined8 param_1)

{
  ExReleasePushLockSharedEx(param_1,0);
  return;
}



===== EaLibSubscribeWnfStateChangeNotification @ 140011688 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EaLibSubscribeWnfStateChangeNotification
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStack_48 [32];
  code *local_28;
  undefined8 local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = AggregateEventWnfCallback;
  local_20 = param_1;
  local_18 = param_3;
  ExSubscribeWnfStateChange(param_2,&local_18,1);
  return;
}



===== EaLibTimeLimitCallbackWorker @ 1400116f0 =====

void EaLibTimeLimitCallbackWorker
               (longlong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  
  lVar1 = *param_1;
  EaLibAcquireLockExclusive(lVar1 + 0x50);
  if (*(longlong **)(lVar1 + 0x80) == param_1) {
    EaiHandleTimeLimitReached(lVar1,param_2,param_3,param_4);
    *(undefined8 *)(lVar1 + 0x80) = 0;
  }
  *(undefined8 *)(lVar1 + 0x58) = 0;
  ExReleasePushLockExclusiveEx(lVar1 + 0x50,0);
  LOCK();
  *(int *)(lVar1 + 0x88) = *(int *)(lVar1 + 0x88) + -1;
  UNLOCK();
  EaFreeBuffer(param_1[0x11]);
  EaFreeBuffer(param_1);
  return;
}



===== EaLibUnsubscribeWnfStateChangeNotification @ 140011770 =====

void EaLibUnsubscribeWnfStateChangeNotification(void)

{
  ExUnsubscribeWnfStateChange();
  return;
}



===== MIDL_user_free @ 140011790 =====

void __stdcall MIDL_user_free(void *param_1)

{
  EaFreeBuffer(param_1);
  return;
}



===== MIDL_user_allocate @ 1400117b0 =====

void * __stdcall MIDL_user_allocate(size_t size)

{
  void *pvVar1;
  
  pvVar1 = (void *)EaLibAllocate(size,'\x01');
  return pvVar1;
}



===== _tlgEnableCallback @ 1400117d0 =====

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



===== wil_details_EvaluateFeatureDependencies @ 14001184c =====

void wil_details_EvaluateFeatureDependencies(void)

{
  uint uVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  bool bVar5;
  
  puVar4 = (undefined *)0x0;
  ppuVar3 = &Feature_382177595__private_descriptor;
  ppuVar2 = &Feature_382177595__private_descriptor;
  do {
    if (*ppuVar2 != (undefined *)0x0) goto joined_r0x000140011887;
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &wil_details_featureDescriptors_z);
LAB_140011901:
  while( true ) {
    if (&UNK_14000dcc7 < ppuVar3) {
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
      if (&UNK_14000dcc7 < ppuVar3) {
        return;
      }
      if (*ppuVar3 != puVar4) break;
      ppuVar3 = ppuVar3 + 1;
    }
  } while( true );
joined_r0x000140011887:
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
      if (&UNK_14000dcc7 < ppuVar2) goto LAB_140011901;
      if (*ppuVar2 != (undefined *)0x0) break;
      ppuVar2 = ppuVar2 + 1;
    }
  }
  goto LAB_140011901;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001193c =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_1400119d4;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_1400119d4;
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
LAB_1400119d4:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 140011a20 =====

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
      for (ppuVar2 = &Feature_382177595__private_descriptor;
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
              if (&UNK_14000dcc7 < ppuVar2) {
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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140011aa0 =====

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
  for (ppuVar3 = &Feature_382177595__private_descriptor; ppuVar3 < &wil_details_featureDescriptors_z
      ; ppuVar3 = ppuVar3 + 1) {
    if (*ppuVar3 != (undefined *)0x0) goto LAB_140011b9d;
  }
LAB_140011ba6:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_140011b9d:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140011ba6;
  if (((*(char *)((longlong)ppuVar3 + 0x1d) == '\0') &&
      (*(char *)((longlong)ppuVar3 + 0x1e) == '\0')) &&
     (*(char *)((longlong)ppuVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration(*(undefined4 *)(ppuVar3 + 3),1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_140011b6e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_140011b6e;
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
    if (&UNK_14000dcc7 < ppuVar3) goto LAB_140011ba6;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_140011b9d;
}



===== BrpDecodeBrokeredEvent_V1 @ 140011bcc =====

undefined8
BrpDecodeBrokeredEvent_V1
          (char *param_1,ushort param_2,ushort param_3,ushort *param_4,ushort *param_5)

{
  wchar_t *pwVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  ushort *puVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  size_t sVar8;
  int iVar9;
  ulonglong uVar10;
  ushort uVar11;
  ushort uVar12;
  uint uVar13;
  ushort *puVar14;
  ushort *puVar15;
  uint uVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  ushort local_58;
  ushort local_56;
  ushort local_52;
  ushort local_50;
  
  uVar4 = 0;
  local_58 = 0;
  local_52 = 0;
  puVar14 = (ushort *)0x0;
  uVar13 = 0;
  uVar16 = 0;
  uVar17 = 0;
  if (((param_2 < 4) || (param_1 == (char *)0x0)) || (*param_1 != '\x01')) {
    return 0xc000000d;
  }
  uVar2 = *(ushort *)(param_1 + 2);
  local_50 = 0;
  do {
    puVar5 = (ushort *)(param_1 + 4);
    local_56 = 0;
    uVar7 = 0;
    if (uVar2 != 0) {
      uVar18 = (ulonglong)param_2;
      do {
        if (puVar14 != (ushort *)0x0) {
          puVar6 = (undefined8 *)(uVar7 * 0x20 + *(longlong *)(puVar14 + 4));
          *puVar6 = 0;
          puVar6[1] = 0;
          puVar6[2] = 0;
          puVar6[3] = 0;
        }
        uVar13 = (uint)(ushort)((short)uVar13 + 0x20);
        if (param_1 + (uVar18 - (longlong)puVar5) < (char *)0x2) {
          return 0xc000000d;
        }
        uVar10 = (ulonglong)*puVar5;
        if (uVar18 < uVar10 + 2) {
          return 0xc000000d;
        }
        if (*puVar5 != 0) {
          pwVar1 = (wchar_t *)(param_1 + uVar10);
          if (pwVar1 == (wchar_t *)0x0) {
            uVar10 = 2;
          }
          else {
            sVar8 = wcsnlen(pwVar1,uVar18 - uVar10 >> 1);
            uVar10 = sVar8 * 2 + 2;
            if (0xffff < uVar10) {
              return 0xc0000095;
            }
            uVar7 = (ulonglong)local_56;
          }
          if (puVar14 != (ushort *)0x0) {
            *(ulonglong *)(uVar7 * 0x20 + *(longlong *)(puVar14 + 4)) = uVar17 + (longlong)puVar14;
            memmove(*(void **)(uVar7 * 0x20 + *(longlong *)(puVar14 + 4)),pwVar1,uVar10 & 0xffff);
          }
          uVar4 = (int)uVar10 + (int)uVar17;
          if ((ushort)uVar4 < (ushort)uVar17) {
            return 0xc0000095;
          }
          uVar7 = (ulonglong)local_56;
          uVar17 = (ulonglong)(uVar4 & 0xffff);
        }
        if (param_1 + (uVar18 - (longlong)(puVar5 + 1)) < &DAT_00000004) {
          return 0xc000000d;
        }
        iVar9 = *(int *)(puVar5 + 1);
        puVar15 = puVar5 + 3;
        if (puVar14 != (ushort *)0x0) {
          *(int *)(uVar7 * 0x20 + 8 + *(longlong *)(puVar14 + 4)) = iVar9;
        }
        if (iVar9 == 0) {
          if (param_1 + (uVar18 - (longlong)puVar15) < &DAT_00000004) {
            return 0xc000000d;
          }
          puVar5 = puVar5 + 5;
          if (puVar14 != (ushort *)0x0) {
            *(undefined4 *)(uVar7 * 0x20 + 0x10 + *(longlong *)(puVar14 + 4)) =
                 *(undefined4 *)puVar15;
          }
LAB_140011f7a:
          uVar16 = (uint)local_58;
        }
        else {
          if (iVar9 != 1) {
            uVar11 = (ushort)uVar17;
            if (iVar9 == 2) {
              if (param_1 + (uVar18 - (longlong)puVar15) < (char *)0x2) {
                return 0xc000000d;
              }
              uVar10 = (ulonglong)*puVar15;
              puVar5 = puVar5 + 4;
              if (uVar18 < uVar10 + 2) {
                return 0xc000000d;
              }
              if (*puVar15 != 0) {
                pwVar1 = (wchar_t *)(param_1 + uVar10);
                if (pwVar1 == (wchar_t *)0x0) {
                  uVar7 = 2;
                }
                else {
                  sVar8 = wcsnlen(pwVar1,uVar18 - uVar10 >> 1);
                  uVar7 = sVar8 * 2 + 2;
                  if (0xffff < uVar7) {
                    return 0xc0000095;
                  }
                }
                if (puVar14 != (ushort *)0x0) {
                  *(ulonglong *)((ulonglong)local_56 * 0x20 + 0x10 + *(longlong *)(puVar14 + 4)) =
                       uVar17 + (longlong)puVar14;
                  memmove(*(void **)((ulonglong)local_56 * 0x20 + 0x10 + *(longlong *)(puVar14 + 4))
                          ,pwVar1,uVar7 & 0xffff);
                }
                uVar4 = (int)uVar7 + (int)uVar17;
                if ((ushort)uVar4 < uVar11) {
                  return 0xc0000095;
                }
                uVar17 = (ulonglong)(uVar4 & 0xffff);
LAB_140011f6e:
                uVar7 = (ulonglong)local_56;
              }
            }
            else if (iVar9 == 3) {
              if (param_1 + (uVar18 - (longlong)puVar15) < (char *)0x2) {
                return 0xc000000d;
              }
              uVar12 = *puVar15;
              if (puVar14 != (ushort *)0x0) {
                *(ushort *)(uVar7 * 0x20 + 0x10 + *(longlong *)(puVar14 + 4)) = uVar12;
              }
              if (param_1 + (uVar18 - (longlong)(puVar5 + 4)) < (char *)0x2) {
                return 0xc000000d;
              }
              uVar3 = puVar5[4];
              puVar5 = puVar5 + 5;
              if (param_2 < uVar3) {
                return 0xc000000d;
              }
              if (uVar3 != 0) {
                uVar7 = Feature_382177595__private_IsEnabledDeviceUsageNoInline();
                if ((int)uVar7 == 0) {
                  if (puVar14 != (ushort *)0x0) {
                    *(ulonglong *)((ulonglong)local_56 * 0x20 + 0x18 + *(longlong *)(puVar14 + 4)) =
                         uVar17 + (longlong)puVar14;
                    memmove(*(void **)((ulonglong)local_56 * 0x20 + 0x18 +
                                      *(longlong *)(puVar14 + 4)),param_1 + uVar3,
                            (ulonglong)uVar12 * 2);
                  }
                  uVar4 = (uint)(ushort)(uVar12 * 2);
                }
                else {
                  uVar4 = (uint)uVar12 * 2;
                  if (0xffff < uVar4) {
                    return 0xc0000095;
                  }
                  if (param_2 < (ushort)uVar4) {
                    return 0xc000000d;
                  }
                  if ((int)((uint)param_2 - (uint)uVar3) < (int)(uVar4 & 0xffff)) {
                    return 0xc000000d;
                  }
                  if (puVar14 != (ushort *)0x0) {
                    *(ulonglong *)((ulonglong)local_56 * 0x20 + 0x18 + *(longlong *)(puVar14 + 4)) =
                         uVar17 + (longlong)puVar14;
                    memmove(*(void **)((ulonglong)local_56 * 0x20 + 0x18 +
                                      *(longlong *)(puVar14 + 4)),param_1 + uVar3,
                            (ulonglong)(uVar4 & 0xffff));
                  }
                }
                uVar12 = (short)uVar4 + uVar11;
                if (uVar12 < uVar11) {
                  return 0xc0000095;
                }
                uVar17 = (ulonglong)uVar12;
                goto LAB_140011f6e;
              }
            }
            else {
              if (iVar9 != 4) {
                return 0xc00000e5;
              }
              if (param_1 + (uVar18 - (longlong)puVar15) < (char *)0x2) {
                return 0xc000000d;
              }
              uVar11 = *puVar15;
              if (puVar14 != (ushort *)0x0) {
                *(ushort *)(uVar7 * 0x20 + 0x10 + *(longlong *)(puVar14 + 4)) = uVar11;
              }
              if (param_1 + (uVar18 - (longlong)(puVar5 + 4)) < (char *)0x2) {
                return 0xc000000d;
              }
              uVar12 = puVar5[4];
              puVar5 = puVar5 + 5;
              if (param_2 < uVar12) {
                return 0xc000000d;
              }
              if (uVar12 != 0) {
                uVar7 = Feature_382177595__private_IsEnabledDeviceUsageNoInline();
                if ((int)uVar7 != 0) {
                  if (param_2 < uVar11) {
                    return 0xc000000d;
                  }
                  if ((int)((uint)param_2 - (uint)uVar12) < (int)(uint)uVar11) {
                    return 0xc000000d;
                  }
                }
                if (puVar14 != (ushort *)0x0) {
                  *(ulonglong *)((ulonglong)local_56 * 0x20 + 0x18 + *(longlong *)(puVar14 + 4)) =
                       (ulonglong)local_58 + (longlong)puVar14;
                  memmove(*(void **)((ulonglong)local_56 * 0x20 + 0x18 + *(longlong *)(puVar14 + 4))
                          ,param_1 + uVar12,(ulonglong)uVar11);
                }
                uVar11 = uVar11 + local_58;
                if (uVar11 < local_58) {
                  return 0xc0000095;
                }
                uVar16 = (uint)uVar11;
                uVar7 = (ulonglong)local_56;
                local_58 = uVar11;
                goto LAB_140011f80;
              }
            }
            goto LAB_140011f7a;
          }
          if (param_1 + (uVar18 - (longlong)puVar15) < (char *)0x8) {
            return 0xc000000d;
          }
          puVar5 = puVar5 + 7;
          uVar16 = (uint)local_58;
          if (puVar14 != (ushort *)0x0) {
            *(undefined8 *)(uVar7 * 0x20 + 0x10 + *(longlong *)(puVar14 + 4)) =
                 *(undefined8 *)puVar15;
          }
        }
LAB_140011f80:
        local_56 = (short)uVar7 + 1;
        uVar7 = (ulonglong)local_56;
      } while (local_56 < uVar2);
      uVar4 = (uint)local_52;
    }
    if (puVar14 == (ushort *)0x0) {
      uVar11 = (ushort)(uVar13 + 0x10);
      if (uVar11 < 0x10) {
        return 0xc0000095;
      }
      iVar9 = uVar13 + 0x10 + (int)uVar17;
      uVar12 = (ushort)iVar9;
      if (uVar12 < uVar11) {
        return 0xc0000095;
      }
      uVar4 = uVar16 + iVar9;
      local_52 = (ushort)uVar4;
      if (local_52 < uVar12) {
        return 0xc0000095;
      }
      if ((param_4 == (ushort *)0x0) || (param_3 < local_52)) {
        *param_5 = local_52;
        return 0xc0000023;
      }
      param_4[4] = 0;
      param_4[5] = 0;
      param_4[6] = 0;
      param_4[7] = 0;
      *param_4 = 0;
      if (uVar2 != 0) {
        *param_4 = uVar2;
        *(ushort **)(param_4 + 4) = param_4 + 8;
      }
      local_58 = (short)uVar13 + (short)uVar17 + 0x10;
      uVar16 = (uint)local_58;
      uVar17 = (ulonglong)(uVar13 + 0x10);
      uVar13 = 0;
      puVar14 = param_4;
    }
    local_50 = local_50 + 1;
    if (1 < local_50) {
      *param_5 = (ushort)uVar4;
      return 0;
    }
  } while( true );
}



===== BrpEncodeBrokeredEvent_V1 @ 14001223c =====

undefined8
BrpEncodeBrokeredEvent_V1(ushort *param_1,ushort param_2,longlong param_3,ushort *param_4)

{
  int iVar1;
  longlong lVar2;
  wchar_t *_Src;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  ushort uVar6;
  ushort uVar7;
  uint uVar8;
  ulonglong uVar9;
  void *_Src_00;
  longlong lVar10;
  ulonglong uVar11;
  longlong lVar12;
  ushort uVar13;
  ulonglong uVar14;
  bool bVar15;
  ushort local_res8;
  ushort local_58;
  ushort local_54;
  ushort local_52;
  
  local_54 = 0;
  local_res8 = 0;
  lVar10 = 0;
  uVar3 = 0;
  uVar9 = 0;
  uVar11 = 0;
  uVar14 = 0;
  if ((param_1 == (ushort *)0x0) || (param_4 == (ushort *)0x0)) {
    return 0xc000000d;
  }
  local_52 = 0;
  do {
    if (lVar10 != 0) {
      *(undefined2 *)((uVar9 & 0xffff) + lVar10) = 1;
    }
    uVar8 = (int)uVar9 + 2;
    uVar13 = (ushort)uVar8;
    if (uVar13 < (ushort)uVar9) {
      return 0xc0000095;
    }
    if (lVar10 != 0) {
      *(ushort *)((ulonglong)(uVar8 & 0xffff) + lVar10) = *param_1;
    }
    uVar8 = (int)uVar9 + 4;
    uVar9 = (ulonglong)uVar8;
    if ((ushort)uVar8 < uVar13) {
      return 0xc0000095;
    }
    local_58 = 0;
    if (*param_1 != 0) {
      do {
        lVar12 = (ulonglong)local_58 * 0x20;
        uVar13 = (ushort)uVar9;
        iVar4 = (int)uVar9;
        if (*(longlong *)(lVar12 + *(longlong *)(param_1 + 4)) == 0) {
          if (lVar10 != 0) {
            *(undefined2 *)((uVar9 & 0xffff) + lVar10) = 0;
          }
          if ((ushort)(uVar13 + 2) < uVar13) {
            return 0xc0000095;
          }
        }
        else {
          if (lVar10 != 0) {
            *(ushort *)((uVar9 & 0xffff) + lVar10) = (ushort)uVar11;
          }
          if ((ushort)(uVar13 + 2) < uVar13) {
            return 0xc0000095;
          }
          if (*(wchar_t **)(lVar12 + *(longlong *)(param_1 + 4)) == (wchar_t *)0x0) {
            return 0xc000000d;
          }
          sVar5 = wcsnlen(*(wchar_t **)(lVar12 + *(longlong *)(param_1 + 4)),0x40);
          uVar9 = sVar5 * 2 + 2;
          if (0xffff < uVar9) {
            return 0xc0000095;
          }
          if (lVar10 != 0) {
            memmove((void *)(uVar11 + lVar10),*(void **)(*(longlong *)(param_1 + 4) + lVar12),
                    uVar9 & 0xffff);
          }
          uVar3 = (int)uVar9 + (int)uVar11;
          if ((ushort)uVar3 < (ushort)uVar11) {
            return 0xc0000095;
          }
          uVar14 = (ulonglong)local_res8;
          uVar11 = (ulonglong)(uVar3 & 0xffff);
        }
        if (lVar10 != 0) {
          *(undefined4 *)((ulonglong)(iVar4 + 2U & 0xffff) + lVar10) =
               *(undefined4 *)(*(longlong *)(param_1 + 4) + 8 + lVar12);
        }
        uVar3 = iVar4 + 6;
        uVar9 = (ulonglong)uVar3;
        uVar13 = (ushort)uVar3;
        if (uVar13 < (ushort)(iVar4 + 2U)) {
          return 0xc0000095;
        }
        lVar2 = *(longlong *)(param_1 + 4);
        iVar1 = *(int *)(lVar2 + 8 + lVar12);
        if (iVar1 == 0) {
          if (lVar10 != 0) {
            *(undefined4 *)((ulonglong)(uVar3 & 0xffff) + lVar10) =
                 *(undefined4 *)(lVar2 + 0x10 + lVar12);
          }
          uVar9 = (ulonglong)(iVar4 + 10);
LAB_14001260b:
          bVar15 = (ushort)uVar9 < uVar13;
LAB_14001260e:
          if (bVar15) {
            return 0xc0000095;
          }
        }
        else {
          if (iVar1 == 1) {
            if (lVar10 != 0) {
              *(undefined8 *)((uVar9 & 0xffff) + lVar10) = *(undefined8 *)(lVar2 + 0x10 + lVar12);
            }
            uVar9 = (ulonglong)(iVar4 + 0xe);
            goto LAB_14001260b;
          }
          uVar6 = (ushort)uVar11;
          if (iVar1 != 2) {
            if (iVar1 == 3) {
              if (lVar10 != 0) {
                *(undefined2 *)((uVar9 & 0xffff) + lVar10) = *(undefined2 *)(lVar2 + 0x10 + lVar12);
              }
              uVar7 = (ushort)(iVar4 + 8U);
              if (uVar7 < uVar13) {
                return 0xc0000095;
              }
              if (*(longlong *)(*(longlong *)(param_1 + 4) + 0x18 + lVar12) != 0) {
                if (lVar10 != 0) {
                  *(ushort *)((ulonglong)(iVar4 + 8U & 0xffff) + lVar10) = uVar6;
                }
                uVar9 = (ulonglong)(iVar4 + 10U);
                if ((ushort)(iVar4 + 10U) < uVar7) {
                  return 0xc0000095;
                }
                uVar3 = (uint)*(ushort *)(*(longlong *)(param_1 + 4) + 0x10 + lVar12) * 2;
                uVar14 = (ulonglong)uVar3;
                if (0xffff < uVar3) {
                  return 0xc0000095;
                }
                if (lVar10 != 0) {
                  _Src_00 = *(void **)(*(longlong *)(param_1 + 4) + 0x18 + lVar12);
                  goto LAB_140012533;
                }
                goto LAB_140012543;
              }
            }
            else {
              if (iVar1 != 4) {
                return 0xc00000e5;
              }
              if (lVar10 != 0) {
                *(undefined2 *)((uVar9 & 0xffff) + lVar10) = *(undefined2 *)(lVar2 + 0x10 + lVar12);
              }
              uVar6 = (ushort)(iVar4 + 8U);
              if (uVar6 < uVar13) {
                return 0xc0000095;
              }
              if (*(longlong *)(*(longlong *)(param_1 + 4) + 0x18 + lVar12) != 0) {
                if (lVar10 != 0) {
                  *(short *)((ulonglong)(iVar4 + 8U & 0xffff) + lVar10) = (short)uVar14;
                }
                uVar9 = (ulonglong)(iVar4 + 10U);
                if ((ushort)(iVar4 + 10U) < uVar6) {
                  return 0xc0000095;
                }
                uVar13 = *(ushort *)(*(longlong *)(param_1 + 4) + 0x10 + lVar12);
                if (lVar10 != 0) {
                  memmove((void *)((uVar14 & 0xffff) + lVar10),
                          *(void **)(*(longlong *)(param_1 + 4) + 0x18 + lVar12),(ulonglong)uVar13);
                }
                uVar13 = uVar13 + local_res8;
                if (uVar13 < local_res8) {
                  return 0xc0000095;
                }
                uVar14 = (ulonglong)uVar13;
                local_res8 = uVar13;
                goto LAB_140012614;
              }
            }
            if (lVar10 != 0) {
              *(undefined2 *)((ulonglong)(iVar4 + 8U & 0xffff) + lVar10) = 0;
            }
            uVar9 = (ulonglong)(iVar4 + 10U);
            bVar15 = (ushort)(iVar4 + 10U) < (ushort)(iVar4 + 8U);
            goto LAB_14001260e;
          }
          if (*(longlong *)(lVar2 + 0x10 + lVar12) == 0) {
            if (lVar10 != 0) {
              *(undefined2 *)((uVar9 & 0xffff) + lVar10) = 0;
            }
            uVar9 = (ulonglong)(iVar4 + 8);
            goto LAB_14001260b;
          }
          if (lVar10 != 0) {
            *(ushort *)((uVar9 & 0xffff) + lVar10) = uVar6;
          }
          uVar9 = (ulonglong)(iVar4 + 8U);
          if ((ushort)(iVar4 + 8U) < uVar13) {
            return 0xc0000095;
          }
          _Src = *(wchar_t **)(*(longlong *)(param_1 + 4) + 0x10 + lVar12);
          if (_Src == (wchar_t *)0x0) {
            uVar14 = 2;
          }
          else {
            sVar5 = wcsnlen(_Src,0x800);
            uVar14 = sVar5 * 2 + 2;
            if (0xffff < uVar14) {
              return 0xc0000095;
            }
          }
          uVar3 = (uint)uVar14;
          if (lVar10 != 0) {
            _Src_00 = *(void **)(*(longlong *)(param_1 + 4) + 0x10 + lVar12);
LAB_140012533:
            uVar3 = (uint)uVar14;
            memmove((void *)(uVar11 + lVar10),_Src_00,uVar14 & 0xffff);
          }
LAB_140012543:
          uVar3 = uVar3 + (int)uVar11;
          if ((ushort)uVar3 < uVar6) {
            return 0xc0000095;
          }
          uVar14 = (ulonglong)local_res8;
          uVar11 = (ulonglong)(uVar3 & 0xffff);
        }
LAB_140012614:
        local_58 = local_58 + 1;
      } while (local_58 < *param_1);
      uVar3 = (uint)local_54;
    }
    if (lVar10 == 0) {
      iVar4 = uVar3 + (int)uVar9;
      uVar13 = (ushort)iVar4;
      if (uVar13 < (ushort)uVar3) {
        return 0xc0000095;
      }
      iVar4 = iVar4 + (int)uVar11;
      uVar6 = (ushort)iVar4;
      if (uVar6 < uVar13) {
        return 0xc0000095;
      }
      uVar3 = iVar4 + (int)uVar14;
      local_54 = (ushort)uVar3;
      if (local_54 < uVar6) {
        return 0xc0000095;
      }
      if ((param_3 == 0) || (param_2 < local_54)) {
        *param_4 = local_54;
        return 0xc0000023;
      }
      uVar8 = (int)uVar9 + (int)uVar11;
      uVar14 = (ulonglong)uVar8;
      uVar11 = uVar9 & 0xffff;
      local_res8 = (ushort)uVar8;
      uVar9 = 0;
      lVar10 = param_3;
    }
    local_52 = local_52 + 1;
    if (1 < local_52) {
      *param_4 = (ushort)uVar3;
      return 0;
    }
  } while( true );
}



===== entry @ 140014010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 140014044 =====

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



===== DllInitialize @ 140014080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DllInitialize(void)

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
  
                    /* 0x14080  9  DllInitialize */
  puVar4 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = *(undefined4 *)(PTR_DAT_14000e008 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_14000e008 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_14000e008 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_14000e008 + -4);
  if (DAT_14000e020 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_14000e030 = 0;
  _DAT_14000e028 = EventAggregationCaptureStateCallback;
  *(undefined8 *)(puVar4 + -8) = 0x1400140ec;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_14000e000,&DAT_14000e020);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_14000e008;
    *(undefined8 *)(puVar4 + -8) = 0x140014111;
    EtwSetInformation(DAT_14000e020,2,PTR_DAT_14000e008,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x14001411b;
  wil_InitializeFeatureStaging();
  *(undefined8 *)(puVar4 + -8) = 0x140014136;
  RtlRunOnceExecuteOnce(&AggregateInitOnce,EaiRunOnceCallback,0,0);
  *(undefined8 *)(puVar4 + -8) = 0x140014148;
  return;
}



===== DriverEntry @ 140014154 =====

undefined8 DriverEntry(void)

{
  return 0;
}



===== wil_InitializeFeatureStaging @ 140014160 =====

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
    for (ppuVar3 = &Feature_382177595__private_descriptor;
        ppuVar3 < &wil_details_featureDescriptors_z; ppuVar3 = ppuVar3 + 1) {
      if (*ppuVar3 != (undefined *)0x0) goto LAB_1400141e7;
    }
LAB_140014221:
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
LAB_1400141e7:
  if (ppuVar3 == (undefined **)0x0) goto LAB_140014221;
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
    goto LAB_140014221;
  }
  ppuVar3 = ppuVar3 + 7;
  while( true ) {
    if (&UNK_14000dcc7 < ppuVar3) goto LAB_140014221;
    if (*ppuVar3 != (undefined *)0x0) break;
    ppuVar3 = ppuVar3 + 1;
  }
  goto LAB_1400141e7;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140014274 =====

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
  ppuVar4 = &Feature_382177595__private_descriptor;
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
            if (&UNK_14000dcc7 < ppuVar4) {
              return;
            }
            if (*ppuVar4 != (undefined *)0x0) break;
            ppuVar4 = ppuVar4 + 1;
          }
        } while (ppuVar4 != (undefined **)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_14001435e;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_14001435e;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_14001435e:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*ppuVar4;
    ppuVar4 = ppuVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_14000dcc7 < ppuVar4) {
        return;
      }
      if (*ppuVar4 != (undefined *)0x0) break;
      ppuVar4 = ppuVar4 + 1;
    }
  } while( true );
}


