
===== _tlgKeywordOn @ 1c0001008 =====

ulonglong _tlgKeywordOn(void)

{
  ulonglong in_RAX;
  
  if (((DAT_1c0017060 & 0x400000000000) == 0) ||
     (in_RAX = DAT_1c0017068 & 0x400000000000, in_RAX != DAT_1c0017068)) {
    return in_RAX & 0xffffffffffffff00;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 1c000103c =====

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
  *param_6 = PTR_DAT_1c0017058;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_1c0017058;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_1c0017070,&local_18,0,0,param_5,param_6);
  return;
}



===== TeredoWfpTryToOffloadFlow @ 1c00010f0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 TeredoWfpTryToOffloadFlow(ulonglong *param_1,undefined8 param_2,undefined8 param_3)

{
  longlong *plVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  undefined1 uVar6;
  ulonglong *puVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined1 uVar10;
  undefined7 uVar11;
  undefined8 uVar12;
  longlong *local_res8;
  
  uVar11 = (undefined7)((ulonglong)param_3 >> 8);
  uVar9 = 0;
  local_res8 = (longlong *)0x0;
  LOCK();
  _DAT_1c00173f8 = _DAT_1c00173f8 + 1;
  UNLOCK();
  uVar12 = 0;
  puVar7 = param_1 + 2;
  uVar10 = 1;
  TeredoWfpLocateOrCreateV6Flow(param_1,puVar7,'\x01','\0',&local_res8);
  plVar5 = local_res8;
  if (local_res8 == (longlong *)0x0) {
    uVar9 = 0xc000009a;
  }
  else {
    plVar1 = local_res8 + 2;
    uVar6 = KeAcquireSpinLockRaiseToDpc(plVar1);
    uVar8 = CONCAT71((int7)((ulonglong)puVar7 >> 8),uVar6);
    *(int *)((longlong)plVar5 + 0x5c) = (int)param_1[4];
    *(undefined4 *)(plVar5 + 0xc) = *(undefined4 *)((longlong)param_1 + 0x24);
    *(short *)((longlong)plVar5 + 100) = (short)param_1[5];
    *(undefined2 *)((longlong)plVar5 + 0x66) = *(undefined2 *)((longlong)param_1 + 0x2a);
    uVar4 = param_1[1];
    plVar5[0x13] = *param_1;
    plVar5[0x14] = uVar4;
    uVar4 = param_1[3];
    plVar5[0x15] = param_1[2];
    plVar5[0x16] = uVar4;
    uVar2 = *(undefined4 *)((longlong)param_1 + 0x24);
    uVar4 = param_1[5];
    uVar3 = *(undefined4 *)((longlong)param_1 + 0x2c);
    *(int *)(plVar5 + 0x17) = (int)param_1[4];
    *(undefined4 *)((longlong)plVar5 + 0xbc) = uVar2;
    *(int *)(plVar5 + 0x18) = (int)uVar4;
    *(undefined4 *)((longlong)plVar5 + 0xc4) = uVar3;
    plVar5[0x19] = param_1[6];
    if (*(char *)((longlong)plVar5 + 0x8e) == '\x01') {
      KeReleaseSpinLock();
      TeredoWfpDereferenceFlowContextImp(plVar5,uVar8,CONCAT71(uVar11,uVar10));
    }
    else {
      *(undefined1 *)((longlong)plVar5 + 0x8e) = 1;
      KeReleaseSpinLock(plVar1);
      TeredoWfpPrintV6Flow((longlong)param_1,uVar8,CONCAT71(uVar11,uVar10),uVar12);
    }
  }
  return uVar9;
}



===== TunnelTeredoDispatchIoControl @ 1c0001200 =====

undefined4 TunnelTeredoDispatchIoControl(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong *puVar5;
  undefined *puVar6;
  undefined4 uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong *puVar10;
  undefined8 uVar11;
  uint uVar12;
  longlong *local_res10;
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  uVar7 = 0;
  puVar5 = *(ulonglong **)(param_2 + 0x18);
  uVar12 = 0;
  local_res10 = (longlong *)((ulonglong)local_res10 & 0xffffffff00000000);
  uVar1 = *(uint *)(lVar4 + 0x10);
  uVar8 = (ulonglong)uVar1;
  uVar2 = *(uint *)(lVar4 + 8);
  puVar6 = *(undefined **)(*(longlong *)(lVar4 + 0x30) + 0x20);
  uVar3 = *(uint *)(lVar4 + 0x18);
  if (uVar3 < 0x12cc1d) {
    if (uVar3 == 0x12cc1c) {
      if ((puVar5 != (ulonglong *)0x0) && (0x37 < uVar1)) {
        uVar8 = RoReferenceEx((uint *)(puVar6 + 0x220),1);
        if ((char)uVar8 != '\0') {
          uVar11 = TeredoWfpTerminateOffload(puVar5);
          uVar7 = (undefined4)uVar11;
          goto LAB_1c000133c;
        }
        goto LAB_1c0001328;
      }
    }
    else {
      if ((((uVar3 == 0x12cc04) || (uVar3 == 0x12cc08)) || (uVar3 == 0x12cc0c)) ||
         (uVar3 == 0x12cc10)) {
LAB_1c0001471:
        uVar7 = 0xc00000bb;
        goto LAB_1c0001476;
      }
      if (uVar3 == 0x12cc14) {
        if ((puVar5 != (ulonglong *)0x0) && (0x37 < uVar1)) {
          uVar11 = 1;
          uVar9 = RoReferenceEx((uint *)(puVar6 + 0x220),1);
          if ((char)uVar9 != '\0') {
            uVar11 = TeredoWfpTryToOffloadFlow(puVar5,uVar11,uVar8);
            uVar7 = (undefined4)uVar11;
LAB_1c000133c:
            TunnelTeredoWfpDereference((longlong)puVar6);
            goto LAB_1c0001476;
          }
LAB_1c0001328:
          uVar7 = 0xc00000a3;
          goto LAB_1c0001476;
        }
      }
      else {
        if (uVar3 != 0x12cc18) goto LAB_1c0001471;
        if (((puVar5 != (ulonglong *)0x0) && (0x47 < uVar1)) && (0x47 < uVar2)) {
          uVar8 = RoReferenceEx((uint *)(puVar6 + 0x220),1);
          if ((char)uVar8 != '\0') {
            local_res10 = (longlong *)0x0;
            puVar10 = puVar5 + 2;
            uVar11 = 0;
            uVar7 = 0xc0000225;
            TeredoWfpLocateOrCreateV6Flow(puVar5,puVar10,'\0','\0',&local_res10);
            if (local_res10 != (longlong *)0x0) {
              uVar8 = local_res10[0x1b];
              uVar12 = 0x48;
              puVar5[7] = local_res10[0x1a];
              puVar5[8] = uVar8;
              TeredoWfpDereferenceFlowContextImp(local_res10,puVar10,uVar11);
              uVar7 = 0;
            }
            goto LAB_1c000133c;
          }
          goto LAB_1c0001328;
        }
      }
    }
  }
  else {
    if (uVar3 == 0x12cc20) goto LAB_1c0001471;
    if (uVar3 == 0x12cc24) {
      if ((puVar5 != (ulonglong *)0x0) && (7 < uVar1)) {
        uVar1 = (uint)*puVar5;
        TwKernelOffloadV4FlowParams =
             uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
        DAT_1c001a024 =
             *(ushort *)((longlong)puVar5 + 4) >> 8 | *(ushort *)((longlong)puVar5 + 4) << 8;
        goto LAB_1c0001476;
      }
    }
    else if (uVar3 == 0x12cc28) {
      if ((puVar5 != (ulonglong *)0x0) && (0xf < uVar2)) {
        uVar12 = 0x10;
        LOCK();
        *puVar5 = DAT_1c001a028;
        UNLOCK();
        LOCK();
        puVar5[1] = DAT_1c001a030;
        UNLOCK();
        goto LAB_1c0001476;
      }
    }
    else {
      if (uVar3 == 0x12cc2c) {
        TunnelIndicateStatus((longlong)puVar6,1,100000);
        goto LAB_1c0001476;
      }
      if (uVar3 == 0x12cc30) {
        uVar8 = TeredoWfpEnableOffload(puVar6,param_2,uVar8);
        uVar7 = (undefined4)uVar8;
        goto LAB_1c0001476;
      }
      if (uVar3 != 0x12cc3c) goto LAB_1c0001471;
      if (((puVar5 != (ulonglong *)0x0) && (0x47 < uVar1)) && (0x47 < uVar2)) {
        uVar8 = RoReferenceEx((uint *)(puVar6 + 0x220),1);
        if ((char)uVar8 != '\0') {
          uVar11 = TeredoWfpQueryCachedState(puVar5,(undefined4 *)&local_res10);
          uVar7 = (undefined4)uVar11;
          TunnelTeredoWfpDereference((longlong)puVar6);
          uVar12 = (uint)local_res10;
          goto LAB_1c0001476;
        }
        goto LAB_1c0001328;
      }
    }
  }
  uVar7 = 0xc000000d;
LAB_1c0001476:
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar12;
  *(undefined4 *)(param_2 + 0x30) = uVar7;
  IofCompleteRequest(param_2,0);
  return uVar7;
}



===== TunnelTeredoWfpDereference @ 1c00014b4 =====

void TunnelTeredoWfpDereference(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x220);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -2;
  UNLOCK();
  if (iVar2 == 3) {
    KeSetEvent(param_1 + 0x228,0,0);
  }
  return;
}



===== TeredoWfpReclaimEntriesInAllBuckets @ 1c00014f0 =====

void TeredoWfpReclaimEntriesInAllBuckets(longlong param_1,undefined8 param_2,ulonglong param_3)

{
  undefined2 uVar1;
  longlong ****pppplVar2;
  longlong ***ppplVar3;
  code *pcVar4;
  int iVar5;
  bool bVar6;
  byte bVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  longlong ****pppplVar11;
  ulonglong uVar12;
  longlong ****pppplVar13;
  bool bVar14;
  longlong ****local_28;
  longlong ****local_20;
  
  lVar9 = 0;
  do {
    local_20 = (longlong ****)&local_28;
    lVar10 = DAT_1c0017360 + lVar9;
    local_28 = (longlong ****)&local_28;
    bVar6 = false;
    bVar7 = KeAcquireSpinLockRaiseToDpc(lVar10);
    pppplVar11 = (longlong ****)(lVar10 + 0x10);
    uVar12 = (ulonglong)bVar7;
    pppplVar13 = *(longlong *****)(lVar10 + 0x10);
    if (*(longlong *****)(lVar10 + 0x10) != pppplVar11) {
      do {
        pppplVar2 = (longlong ****)*pppplVar13;
        if ((param_1 == 0) ||
           (((*(int *)((longlong)pppplVar13 + 0x24) == 2 && ((longlong)pppplVar13[0x1b] < param_1))
            && ((longlong)pppplVar13[0x1a] < param_1)))) {
          if (((longlong ****)pppplVar2[1] != pppplVar13) ||
             (ppplVar3 = pppplVar13[1], (longlong ****)*ppplVar3 != pppplVar13)) goto LAB_1c0001703;
          *ppplVar3 = (longlong **)pppplVar2;
          pppplVar2[1] = ppplVar3;
          pppplVar13[1] = (longlong ***)0x0;
          *pppplVar13 = (longlong ***)0x0;
          *(int *)(lVar10 + 8) = *(int *)(lVar10 + 8) + -1;
          *(undefined1 *)((longlong)pppplVar13 + 0x8f) = 0;
          LOCK();
          bVar14 = *(int *)(pppplVar13 + 4) == 0;
          if (bVar14) {
            *(undefined4 *)(pppplVar13 + 4) = 1;
          }
          UNLOCK();
          if ((bVar14) &&
             ((*(int *)((longlong)pppplVar13 + 0x24) == 2 ||
              (uVar8 = RoReferenceEx((uint *)((longlong)pppplVar13 + 0x1c),1), (char)uVar8 != '\0'))
             )) {
            if ((longlong *****)*local_20 != &local_28) goto LAB_1c0001703;
            pppplVar13[1] = (longlong ***)local_20;
            *pppplVar13 = (longlong ***)&local_28;
            *local_20 = (longlong ***)pppplVar13;
            local_20 = pppplVar13;
          }
          LOCK();
          iVar5 = DAT_1c001a120 + -2;
          UNLOCK();
          bVar14 = DAT_1c001a120 == 3;
          DAT_1c001a120 = iVar5;
          if (bVar14) {
            bVar6 = true;
          }
        }
        pppplVar13 = pppplVar2;
      } while (pppplVar2 != pppplVar11);
    }
    KeReleaseSpinLock(lVar10,uVar12 & 0xff);
    while (pppplVar11 = local_28, (longlong *****)local_28 != &local_28) {
      if (((longlong *****)local_28[1] != &local_28) ||
         (pppplVar13 = (longlong ****)*local_28, (longlong ****)pppplVar13[1] != local_28)) {
LAB_1c0001703:
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      pppplVar13[1] = (longlong ***)&local_28;
      if (*(int *)((longlong)local_28 + 0x24) == 2) {
        LOCK();
        *(int *)((longlong)local_28 + 0x1c) = *(int *)((longlong)local_28 + 0x1c) + -1;
        UNLOCK();
        local_28 = pppplVar13;
        TeredoWfpDereferenceFlowContextImp((longlong *)pppplVar11,&local_28,param_3);
      }
      else {
        ppplVar3 = local_28[6];
        uVar1 = *(undefined2 *)(local_28 + 7);
        local_28 = pppplVar13;
        TeredoWfpDereferenceFlowContextImp((longlong *)pppplVar11,&local_28,param_3);
        param_3 = (ulonglong)TwCalloutIdV4;
        FwpsFlowRemoveContext0(ppplVar3,uVar1);
      }
    }
    if (bVar6) {
      param_3 = 0;
      KeSetEvent(&HashTableUninitializedEvent,0);
    }
    lVar9 = lVar9 + 0x20;
    if (0x80df < lVar9) {
      return;
    }
  } while( true );
}



===== TeredoWfpTerminateOffload @ 1c0001710 =====

undefined8 TeredoWfpTerminateOffload(ulonglong *param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  bool bVar4;
  longlong *local_res8 [4];
  
  local_res8[0] = (longlong *)0x0;
  uVar3 = 0;
  uVar2 = 0xc0000225;
  TeredoWfpLocateOrCreateV6Flow(param_1,param_1 + 2,'\0','\0',local_res8);
  plVar1 = local_res8[0];
  if (local_res8[0] != (longlong *)0x0) {
    uVar2 = 1;
    *(undefined1 *)(local_res8[0] + 0x12) = 1;
    *(undefined1 *)((longlong)local_res8[0] + 0x8e) = 0;
    LOCK();
    bVar4 = (int)local_res8[0][4] == 0;
    if (bVar4) {
      *(int *)(local_res8[0] + 4) = 1;
    }
    UNLOCK();
    if (bVar4) {
      LOCK();
      *(int *)((longlong)local_res8[0] + 0x1c) = *(int *)((longlong)local_res8[0] + 0x1c) + -1;
      UNLOCK();
      TeredoWfpDereferenceFlowContextImp(local_res8[0],1,uVar3);
    }
    TeredoWfpDereferenceFlowContextImp(plVar1,uVar2,uVar3);
    uVar2 = 0;
  }
  return uVar2;
}



===== TeredoWfpRestoreAndFreeInjectionClone @ 1c00017a0 =====

void TeredoWfpRestoreAndFreeInjectionClone(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = *(undefined8 **)(param_1 + 8);
  for (puVar2 = *(undefined8 **)(param_2 + 8); (puVar1 != (undefined8 *)0x0 && (puVar2[0x10] != 0));
      puVar2 = (undefined8 *)*puVar2) {
    if ((*(byte *)(puVar1[1] + 10) & 5) == 0) {
      MmMapLockedPagesSpecifyCache(puVar1[1],0,1,0,0,0x40000000);
    }
    ExFreeToNPagedLookasideList(&TwUdpHeaderPool);
    puVar1[1] = puVar2[0x10];
    puVar1[4] = puVar2[0x11];
    *(undefined4 *)(puVar1 + 2) = *(undefined4 *)(puVar2 + 0x12);
    *(undefined4 *)(puVar1 + 5) = *(undefined4 *)(puVar2 + 0x13);
    *(undefined4 *)(puVar1 + 3) = *(undefined4 *)(puVar2 + 3);
    puVar1 = (undefined8 *)*puVar1;
  }
  FwpsFreeCloneNetBufferList0(param_1,0);
  return;
}



===== TunnelTeredoOffloadSendNbl @ 1c0001880 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong TunnelTeredoOffloadSendNbl(longlong param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  char cVar2;
  longlong *plVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  uint uVar8;
  longlong lVar9;
  uint uVar10;
  byte *pbVar11;
  longlong *plVar12;
  uint uVar13;
  uint uVar14;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_78;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  plVar3 = TeredoWfpLocateFlowForOutboundPacket(param_2);
  uVar6 = 0;
  if (plVar3 != (longlong *)0x0) {
    WfpNblInfoSetFlags(param_2,1);
    lVar9 = param_2;
    plVar12 = plVar3;
    lVar5 = TeredoWfpInitializeCloneForInjection(param_1,param_2,(longlong)plVar3);
    if (lVar5 != 0) {
      uVar6 = RoReferenceEx((uint *)(DAT_1c001a0c0 + 0x40),1);
      if ((char)uVar6 != '\0') {
        lVar9 = *(longlong *)(param_2 + 8);
        uVar13 = 0;
        uVar10 = 0;
        if ((*(int *)(lVar9 + 0x18) != 0) && (lVar1 = *(longlong *)(lVar9 + 8), lVar1 != 0)) {
          if ((*(byte *)(lVar1 + 10) & 5) == 0) {
            local_50 = 0x40000010;
            local_58 = 0;
            lVar7 = MmMapLockedPagesSpecifyCache(lVar1,0,1);
          }
          else {
            lVar7 = *(longlong *)(lVar1 + 0x18);
          }
          if (lVar7 != 0) {
            uVar8 = *(uint *)(lVar9 + 0x10);
            if (((uVar8 < *(uint *)(lVar1 + 0x28)) && (0x27 < *(uint *)(lVar1 + 0x28) - uVar8)) &&
               (lVar9 = lVar7 + (ulonglong)uVar8,
               ((byte)*(undefined4 *)(lVar7 + (ulonglong)uVar8) & 0xf0) == 0x60)) {
              local_48 = *(undefined8 *)(lVar9 + 0x18);
              uStack_40 = *(undefined8 *)(lVar9 + 0x20);
              local_38 = *(undefined8 *)(lVar9 + 8);
              uStack_30 = *(undefined8 *)(lVar9 + 0x10);
            }
          }
        }
        uVar8 = 0;
        uVar14 = 0;
        pbVar11 = (byte *)((longlong)&uStack_40 + 1);
        do {
          uVar14 = uVar14 + 8;
          uVar8 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[-1] * 4) ^ uVar8 * 2
          ;
          uVar8 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)*pbVar11 * 4) ^ uVar8 * 2;
          uVar8 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[1] * 4) ^ uVar8 * 2;
          uVar8 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[2] * 4) ^ uVar8 * 2;
          uVar8 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[3] * 4) ^ uVar8 * 2;
          uVar8 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[4] * 4) ^ uVar8 * 2;
          uVar8 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[5] * 4) ^ uVar8 * 2;
          uVar8 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[6] * 4) ^ uVar8 * 2;
          pbVar11 = pbVar11 + 8;
        } while (uVar14 < 8);
        pbVar11 = &DAT_1c0017341;
        do {
          uVar13 = uVar13 + 8;
          uVar8 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[-1] * 4) ^ uVar8 * 2
          ;
          uVar8 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)*pbVar11 * 4) ^ uVar8 * 2;
          uVar8 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[1] * 4) ^ uVar8 * 2;
          uVar8 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[2] * 4) ^ uVar8 * 2;
          uVar8 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[3] * 4) ^ uVar8 * 2;
          uVar8 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[4] * 4) ^ uVar8 * 2;
          uVar8 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[5] * 4) ^ uVar8 * 2;
          uVar8 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[6] * 4) ^ uVar8 * 2;
          pbVar11 = pbVar11 + 8;
        } while (uVar13 < 8);
        pbVar11 = (byte *)((longlong)&uStack_30 + 1);
        do {
          uVar10 = uVar10 + 8;
          uVar13 = uVar8 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[-1] * 4) ^
                   uVar8 * 2;
          uVar13 = uVar13 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)*pbVar11 * 4) ^ uVar13 * 2
          ;
          uVar13 = uVar13 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[1] * 4) ^
                   uVar13 * 2;
          uVar13 = uVar13 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[2] * 4) ^
                   uVar13 * 2;
          uVar13 = uVar13 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[3] * 4) ^
                   uVar13 * 2;
          uVar13 = uVar13 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[4] * 4) ^
                   uVar13 * 2;
          uVar13 = uVar13 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[5] * 4) ^
                   uVar13 * 2;
          uVar8 = uVar13 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[6] * 4) ^
                  uVar13 * 2;
          pbVar11 = pbVar11 + 8;
        } while (uVar10 < 8);
        lVar9 = (ulonglong)(uVar8 & 0x3f) * 0x58;
        if (param_3 == '\0') {
          cVar2 = KeAcquireSpinLockRaiseToDpc();
        }
        else {
          KeAcquireSpinLockAtDpcLevel(lVar9 + 0x1c0018a38);
          cVar2 = '\x02';
        }
        **(longlong **)(&DAT_1c0018a28 + lVar9) = lVar5;
        *(longlong *)(&DAT_1c0018a60 + lVar9) = *(longlong *)(&DAT_1c0018a60 + lVar9) + 1;
        *(longlong *)(&DAT_1c0018a28 + lVar9) = lVar5;
        if ((&DAT_1c0018a40)[lVar9] == '\0') {
          *(longlong *)(&DAT_1c0018a68 + lVar9) = *(longlong *)(&DAT_1c0018a68 + lVar9) + 1;
          (&DAT_1c0018a40)[lVar9] = 1;
          IoQueueWorkItem(*(undefined8 *)(&DAT_1c0018a48 + lVar9),LwWorker,1,&DAT_1c0018a20 + lVar9)
          ;
        }
        if (cVar2 == '\x02') {
          uVar4 = KeReleaseSpinLockFromDpcLevel(lVar9 + 0x1c0018a38);
          return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
        }
        uVar4 = KeReleaseSpinLock(lVar9 + 0x1c0018a38,cVar2);
        return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
      }
      TeredoWfpRestoreAndFreeInjectionClone(lVar5,param_2);
      lVar9 = param_2;
    }
    uVar6 = TeredoWfpDereferenceFlowContextImp(plVar3,lVar9,plVar12);
    uVar6 = uVar6 & 0xffffffffffffff00;
  }
  return uVar6;
}



===== TeredoWfpLocateFlowForOutboundPacket @ 1c0001ce0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong * TeredoWfpLocateFlowForOutboundPacket(longlong param_1)

{
  int *piVar1;
  short sVar2;
  longlong lVar3;
  int iVar4;
  bool bVar5;
  undefined1 uVar6;
  byte bVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  uint uVar11;
  longlong lVar12;
  longlong *plVar13;
  byte *pbVar14;
  byte *pbVar15;
  short sVar16;
  uint uVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  longlong lVar21;
  longlong *plVar22;
  longlong lVar23;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  undefined4 local_80;
  short local_78;
  undefined4 local_68;
  int local_64;
  short local_60;
  short local_5e;
  longlong local_58;
  undefined8 uStack_50;
  longlong local_48;
  longlong lStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar3 = *(longlong *)(param_1 + 8);
  plVar13 = (longlong *)0x0;
  if ((*(int *)(lVar3 + 0x18) != 0) && (lVar23 = *(longlong *)(lVar3 + 8), lVar23 != 0)) {
    if ((*(byte *)(lVar23 + 10) & 5) == 0) {
      local_80 = 0x40000010;
      local_88 = 0;
      lVar10 = MmMapLockedPagesSpecifyCache(lVar23,0,1);
    }
    else {
      lVar10 = *(longlong *)(lVar23 + 0x18);
    }
    if (lVar10 != 0) {
      uVar11 = *(uint *)(lVar3 + 0x10);
      uVar8 = (ulonglong)uVar11;
      if (((uVar11 < *(uint *)(lVar23 + 0x28)) && (0x27 < *(uint *)(lVar23 + 0x28) - uVar11)) &&
         (((byte)*(undefined4 *)(uVar8 + lVar10) & 0xf0) == 0x60)) {
        plVar22 = (longlong *)(uVar8 + 0x18 + lVar10);
        local_58 = *plVar22;
        uStack_50 = plVar22[1];
        plVar22 = (longlong *)(uVar8 + 8 + lVar10);
        local_48 = *plVar22;
        lStack_40 = plVar22[1];
        bVar5 = TeredoWfpIsDataPacket(*(longlong *)(param_1 + 8),(uint)lVar10);
        if (bVar5) {
          plVar22 = (longlong *)0x0;
          uVar8 = RoReferenceEx((uint *)&DAT_1c001a120,1);
          if ((char)uVar8 != '\0') {
            uVar11 = 0;
            uVar17 = 0;
            pbVar14 = (byte *)((longlong)&uStack_50 + 1);
            do {
              uVar17 = uVar17 + 8;
              uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[-1] * 4) ^
                       uVar11 * 2;
              uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)*pbVar14 * 4) ^
                       uVar11 * 2;
              uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[1] * 4) ^
                       uVar11 * 2;
              uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[2] * 4) ^
                       uVar11 * 2;
              uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[3] * 4) ^
                       uVar11 * 2;
              uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[4] * 4) ^
                       uVar11 * 2;
              uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[5] * 4) ^
                       uVar11 * 2;
              uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[6] * 4) ^
                       uVar11 * 2;
              pbVar14 = pbVar14 + 8;
            } while (uVar17 < 8);
            uVar17 = 0;
            pbVar14 = &DAT_1c0017341;
            do {
              pbVar15 = pbVar14 + 8;
              uVar17 = uVar17 + 8;
              uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[-1] * 4) ^
                       uVar11 * 2;
              uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)*pbVar14 * 4) ^
                       uVar11 * 2;
              uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[1] * 4) ^
                       uVar11 * 2;
              uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[2] * 4) ^
                       uVar11 * 2;
              uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[3] * 4) ^
                       uVar11 * 2;
              uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[4] * 4) ^
                       uVar11 * 2;
              uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[5] * 4) ^
                       uVar11 * 2;
              uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[6] * 4) ^
                       uVar11 * 2;
              pbVar14 = pbVar15;
            } while (uVar17 < 8);
            lVar12 = (ulonglong)(uVar11 % 0x407) * 0x20 + DAT_1c0017360;
            uVar6 = KeAcquireSpinLockRaiseToDpc(lVar12);
            lVar10 = local_48;
            lVar23 = uStack_50;
            lVar3 = local_58;
            plVar18 = *(longlong **)(lVar12 + 0x10);
            plVar20 = (longlong *)(lVar12 + 0x10);
            if (plVar18 != plVar20) {
              lVar21 = lStack_40;
              do {
                plVar22 = plVar18;
                plVar18 = plVar22;
                if ((((plVar22[0xd] == lVar10) && (plVar22[0xe] == lVar21)) &&
                    ((plVar22[0xf] == lVar3 &&
                     ((plVar22[0x10] == lVar23 && (*(char *)((longlong)plVar22 + 0x8e) != '\0'))))))
                   && (uVar8 = RoReferenceEx((uint *)((longlong)plVar22 + 0x1c),1),
                      (char)uVar8 != '\0')) break;
                plVar18 = (longlong *)*plVar18;
              } while (plVar18 != plVar20);
            }
            plVar20 = (longlong *)0x0;
            if (plVar18 != (longlong *)(lVar12 + 0x10)) {
              plVar20 = plVar22;
            }
            KeReleaseSpinLock(lVar12,uVar6);
            LOCK();
            iVar4 = DAT_1c001a120 + -2;
            UNLOCK();
            bVar5 = DAT_1c001a120 == 3;
            DAT_1c001a120 = iVar4;
            if (bVar5) {
              pbVar15 = (byte *)0x0;
              KeSetEvent(&HashTableUninitializedEvent,0);
            }
            if (plVar20 != (longlong *)0x0) {
              sVar16 = *(short *)((longlong)plVar20 + 100);
              sVar2 = *(short *)((longlong)plVar20 + 0x66);
              lVar3 = plVar20[0xc];
              plVar22 = (longlong *)0x0;
              iVar4 = *(int *)((longlong)plVar20 + 0x5c);
              local_78 = sVar16;
              uVar8 = RoReferenceEx((uint *)&DAT_1c001a120,1);
              if ((char)uVar8 != '\0') {
                local_60 = sVar16;
                local_68 = iVar4;
                uVar11 = 0;
                local_64 = (int)lVar3;
                local_5e = sVar2;
                uVar17 = 0;
                pbVar14 = (byte *)((longlong)&local_68 + 1);
                do {
                  uVar17 = uVar17 + 0xc;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[-1] * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)*pbVar14 * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[1] * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[2] * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[3] * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[4] * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[5] * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[6] * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[7] * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[8] * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[9] * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[10] * 4) ^
                           uVar11 * 2;
                  pbVar14 = pbVar14 + 0xc;
                } while (uVar17 < 0xc);
                uVar17 = 0;
                pbVar14 = &DAT_1c0017341;
                do {
                  uVar17 = uVar17 + 8;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[-1] * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)*pbVar14 * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[1] * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[2] * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[3] * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[4] * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[5] * 4) ^
                           uVar11 * 2;
                  uVar11 = uVar11 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[6] * 4) ^
                           uVar11 * 2;
                  pbVar14 = pbVar14 + 8;
                } while (uVar17 < 8);
                pbVar15 = (byte *)(ulonglong)(uVar11 % 0x407);
                lVar23 = (ulonglong)(uVar11 % 0x407) * 0x20 + DAT_1c0017360;
                bVar7 = KeAcquireSpinLockRaiseToDpc(lVar23);
                sVar16 = local_78;
                plVar19 = *(longlong **)(lVar23 + 0x10);
                plVar18 = (longlong *)(lVar23 + 0x10);
                uVar8 = (ulonglong)bVar7;
                if (plVar19 != plVar18) {
                  do {
                    plVar22 = plVar19;
                    plVar19 = plVar22;
                    if (((((*(int *)((longlong)plVar22 + 0x24) == 1) &&
                          (iVar4 == *(int *)((longlong)plVar22 + 0x5c))) &&
                         ((int)lVar3 == (int)plVar22[0xc])) &&
                        ((sVar16 == *(short *)((longlong)plVar22 + 100) &&
                         (sVar2 == *(short *)((longlong)plVar22 + 0x66))))) &&
                       ((*(char *)((longlong)plVar22 + 0x8c) != '\0' &&
                        (uVar9 = RoReferenceEx((uint *)((longlong)plVar22 + 0x1c),1),
                        (char)uVar9 != '\0')))) break;
                    plVar19 = (longlong *)*plVar19;
                  } while (plVar19 != plVar18);
                }
                if (plVar19 != (longlong *)(lVar23 + 0x10)) {
                  plVar13 = plVar22;
                }
                KeReleaseSpinLock(lVar23,uVar8 & 0xff);
                LOCK();
                iVar4 = DAT_1c001a120 + -2;
                UNLOCK();
                bVar5 = DAT_1c001a120 == 3;
                plVar22 = plVar13;
                DAT_1c001a120 = iVar4;
                if (bVar5) {
                  pbVar15 = (byte *)0x0;
                  KeSetEvent(&HashTableUninitializedEvent,0);
                }
              }
              plVar13 = plVar22;
              plVar20[0x1b] = *(longlong *)(DAT_1c001a0c0 + 0x2c0);
              LOCK();
              piVar1 = (int *)((longlong)plVar20 + 0x1c);
              iVar4 = *piVar1;
              *piVar1 = *piVar1 + -2;
              UNLOCK();
              if (iVar4 == 3) {
                TeredoWfpRemoveHashEntry(plVar20);
                if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
                  McTemplateK0q_EtwWriteTransfer
                            (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_TEREDO_FLOW_FREED,
                             pbVar15,*(undefined4 *)((longlong)plVar20 + 0x24));
                }
                if (plVar20[9] != 0) {
                  ExFreePoolWithTag(plVar20[9],0x64437754);
                }
                plVar22 = &DAT_1c0017408;
                if (*(int *)((longlong)plVar20 + 0x24) != 2) {
                  plVar22 = &DAT_1c0017400;
                }
                LOCK();
                *plVar22 = *plVar22 + -1;
                UNLOCK();
                ExFreePoolWithTag(plVar20,0x70667754);
              }
            }
          }
        }
      }
    }
  }
  return plVar13;
}



===== TeredoWfpInitializeCloneForInjection @ 1c0002490 =====

longlong TeredoWfpInitializeCloneForInjection(longlong param_1,longlong param_2,longlong param_3)

{
  ushort *puVar1;
  uint uVar2;
  ushort *puVar3;
  longlong lVar4;
  int iVar5;
  ushort *_Dst;
  longlong lVar6;
  longlong lVar7;
  longlong *plVar8;
  ushort *puVar9;
  undefined8 *puVar10;
  longlong local_res8;
  longlong *plVar11;
  
  plVar11 = &local_res8;
  *(undefined8 *)(param_2 + 0x60) = 0;
  local_res8 = 0;
  iVar5 = FwpsAllocateCloneNetBufferList0(param_2,*(undefined8 *)(param_1 + 0x160),0,0,plVar11);
  if (iVar5 < 0) {
    local_res8 = 0;
  }
  else {
    *(longlong *)(param_2 + 0x60) = local_res8;
    *(longlong *)(param_2 + 0x68) = param_3;
    *(longlong *)(local_res8 + 0x60) = param_2;
  }
  lVar4 = local_res8;
  if (local_res8 == 0) {
    return 0;
  }
  plVar8 = *(longlong **)(param_2 + 8);
  puVar10 = *(undefined8 **)(local_res8 + 8);
  if (plVar8 == (longlong *)0x0) {
    return local_res8;
  }
  while( true ) {
    plVar8[0x10] = 0;
    plVar8[0x11] = 0;
    plVar8[0x12] = 0;
    plVar8[0x13] = 0;
    if (((int)plVar8[3] != 0) && (lVar7 = plVar8[1], lVar7 != 0)) {
      if ((*(byte *)(lVar7 + 10) & 5) == 0) {
        plVar11 = (longlong *)((ulonglong)plVar11 & 0xffffffff00000000);
        lVar6 = MmMapLockedPagesSpecifyCache(lVar7,0,1,0,plVar11,0x40000010);
      }
      else {
        lVar6 = *(longlong *)(lVar7 + 0x18);
      }
      if (lVar6 != 0) {
        uVar2 = *(uint *)(plVar8 + 2);
        if (((uVar2 < *(uint *)(lVar7 + 0x28)) && (0x27 < *(uint *)(lVar7 + 0x28) - uVar2)) &&
           (((byte)*(undefined4 *)((ulonglong)uVar2 + lVar6) & 0xf0) == 0x60)) {
          FwpiParseIPv6Protocol0(plVar8);
        }
      }
    }
    if ((0xfffe < (ulonglong)*(uint *)(plVar8 + 3) + 8) ||
       (_Dst = (ushort *)ExAllocateFromNPagedLookasideList(&TwUdpHeaderPool), _Dst == (ushort *)0x0)
       ) break;
    memset(_Dst,0,0x108);
    puVar1 = _Dst + 4;
    puVar9 = _Dst + 0x24;
    _Dst[0x18] = 8;
    _Dst[0x19] = 0;
    _Dst[9] = 0;
    *(ulonglong *)(_Dst + 0x14) = (ulonglong)_Dst & 0xfffffffffffff000;
    _Dst[8] = (((ushort)(((ushort)_Dst & 0xfff) + 0x1007) >> 0xc) + 6) * 8;
    *(uint *)(_Dst + 0x1a) = (uint)_Dst & 0xfff;
    MmBuildMdlForNonPagedPool(puVar1);
    puVar3 = (ushort *)puVar10[1];
    if (*(int *)(puVar10 + 2) == 0) {
      puVar9 = puVar3;
    }
    else {
      if ((puVar3[5] & 5) == 0) {
        plVar11 = (longlong *)((ulonglong)plVar11 & 0xffffffff00000000);
        lVar7 = MmMapLockedPagesSpecifyCache(puVar3,0,1,0,plVar11,0x40000000);
      }
      else {
        lVar7 = *(longlong *)(puVar3 + 0xc);
      }
      IoBuildPartialMdl(puVar10[1],puVar9,(ulonglong)*(uint *)(plVar8 + 2) + lVar7);
    }
    *_Dst = *(ushort *)(param_3 + 100) >> 8 | *(ushort *)(param_3 + 100) << 8;
    _Dst[1] = *(ushort *)(param_3 + 0x66) >> 8 | *(ushort *)(param_3 + 0x66) << 8;
    _Dst[2] = (ushort)(*(short *)(puVar10 + 3) + 8U) >> 8 | (*(short *)(puVar10 + 3) + 8U) * 0x100;
    *(ushort **)puVar1 = puVar9;
    *(undefined8 *)puVar9 = *(undefined8 *)puVar10[1];
    plVar8[0x10] = puVar10[1];
    plVar8[0x11] = puVar10[4];
    plVar8[0x12] = (ulonglong)*(uint *)(puVar10 + 2);
    plVar8[0x13] = (ulonglong)*(uint *)(puVar10 + 5);
    puVar10[1] = puVar1;
    lVar7 = plVar8[3];
    puVar10[4] = puVar1;
    *(int *)(puVar10 + 3) = (int)lVar7 + 8;
    *(undefined4 *)(puVar10 + 2) = 0;
    LOCK();
    DAT_1c001a030 = DAT_1c001a030 + 1;
    UNLOCK();
    *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
    *(longlong *)(param_1 + 0x88) =
         *(longlong *)(param_1 + 0x88) + (ulonglong)*(uint *)(puVar10 + 3);
    plVar8 = (longlong *)*plVar8;
    puVar10 = (undefined8 *)*puVar10;
    if (plVar8 == (longlong *)0x0) {
      return lVar4;
    }
  }
  TeredoWfpRestoreAndFreeInjectionClone(local_res8,param_2);
  return 0;
}



===== TeredoWfpDereferenceFlowContextImp @ 1c0002810 =====

longlong TeredoWfpDereferenceFlowContextImp(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  longlong *plVar4;
  
  LOCK();
  piVar1 = (int *)((longlong)param_1 + 0x1c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -2;
  UNLOCK();
  if (iVar2 != 3) {
    return (ulonglong)(uint3)((uint)iVar2 >> 8) << 8;
  }
  TeredoWfpRemoveHashEntry(param_1);
  if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
    McTemplateK0q_EtwWriteTransfer
              (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_TEREDO_FLOW_FREED,param_3,
               *(undefined4 *)((longlong)param_1 + 0x24));
  }
  if (param_1[9] != 0) {
    ExFreePoolWithTag(param_1[9],0x64437754);
  }
  plVar4 = &DAT_1c0017408;
  if (*(int *)((longlong)param_1 + 0x24) != 2) {
    plVar4 = &DAT_1c0017400;
  }
  LOCK();
  *plVar4 = *plVar4 + -1;
  UNLOCK();
  uVar3 = ExFreePoolWithTag(param_1,0x70667754);
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== TeredoWfpLocateOrCreateV6Flow @ 1c00028c0 =====

bool TeredoWfpLocateOrCreateV6Flow
               (ulonglong *param_1,ulonglong *param_2,char param_3,char param_4,undefined8 *param_5)

{
  int iVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  uint uVar6;
  byte *pbVar7;
  ulonglong *puVar8;
  uint uVar9;
  ulonglong *puVar10;
  ulonglong *puVar11;
  bool bVar12;
  bool bVar13;
  
  puVar11 = (ulonglong *)0x0;
  bVar13 = false;
  uVar3 = RoReferenceEx(&DAT_1c001a120,1);
  if ((char)uVar3 == '\0') {
    *param_5 = 0;
    return false;
  }
  uVar6 = 0;
  uVar9 = 0;
  pbVar7 = (byte *)((longlong)param_2 + 10);
  do {
    uVar9 = uVar9 + 8;
    uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[-2] * 4) ^ uVar6 * 2;
    uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[-1] * 4) ^ uVar6 * 2;
    uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)*pbVar7 * 4) ^ uVar6 * 2;
    uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[1] * 4) ^ uVar6 * 2;
    uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[2] * 4) ^ uVar6 * 2;
    uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[3] * 4) ^ uVar6 * 2;
    uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[4] * 4) ^ uVar6 * 2;
    uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[5] * 4) ^ uVar6 * 2;
    pbVar7 = pbVar7 + 8;
  } while (uVar9 < 8);
  uVar9 = 0;
  pbVar7 = &DAT_1c0017341;
  do {
    uVar9 = uVar9 + 8;
    uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[-1] * 4) ^ uVar6 * 2;
    uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)*pbVar7 * 4) ^ uVar6 * 2;
    uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[1] * 4) ^ uVar6 * 2;
    uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[2] * 4) ^ uVar6 * 2;
    uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[3] * 4) ^ uVar6 * 2;
    uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[4] * 4) ^ uVar6 * 2;
    uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[5] * 4) ^ uVar6 * 2;
    uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[6] * 4) ^ uVar6 * 2;
    pbVar7 = pbVar7 + 8;
  } while (uVar9 < 8);
  uVar3 = (ulonglong)(uVar6 % 0x407) * 0x20 + DAT_1c0017360;
  uVar2 = KeAcquireSpinLockRaiseToDpc(uVar3);
  puVar10 = (ulonglong *)(uVar3 + 0x10);
  puVar8 = (ulonglong *)*puVar10;
  *param_5 = 0;
  if (puVar8 != puVar10) {
    do {
      puVar11 = puVar8;
      puVar8 = puVar11;
      if (((((puVar11[0xd] == *param_1) && (puVar11[0xe] == param_1[1])) &&
           (puVar11[0xf] == *param_2)) && (puVar11[0x10] == param_2[1])) &&
         (((param_4 == '\0' || (*(char *)((longlong)puVar11 + 0x8e) != '\0')) &&
          (uVar4 = RoReferenceEx((uint *)((longlong)puVar11 + 0x1c),1), (char)uVar4 != '\0'))))
      break;
      puVar8 = (ulonglong *)*puVar8;
    } while (puVar8 != puVar10);
  }
  puVar5 = (ulonglong *)0x0;
  if (puVar8 != puVar10) {
    puVar5 = puVar11;
  }
  if (((puVar5 == (ulonglong *)0x0) && (param_3 != '\0')) && ((DAT_1c001a120 & 1) == 0)) {
    puVar5 = TeredoWfpCreateAndInsertV6Flow(uVar3,param_1,param_2);
    bVar13 = puVar5 != (ulonglong *)0x0;
  }
  KeReleaseSpinLock(uVar3,uVar2);
  LOCK();
  iVar1 = DAT_1c001a120 - 2;
  UNLOCK();
  bVar12 = DAT_1c001a120 == 3;
  DAT_1c001a120 = iVar1;
  if (bVar12) {
    KeSetEvent(&HashTableUninitializedEvent,0,0);
  }
  *param_5 = puVar5;
  return bVar13;
}



===== TeredoWfpDdLayerClassify @ 1c0002c10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001c0003302) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TeredoWfpDdLayerClassify
               (longlong param_1,longlong param_2,longlong param_3,undefined8 *param_4,
               longlong param_5,int *param_6)

{
  int *piVar1;
  longlong lVar2;
  short sVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong *plVar7;
  short sVar8;
  uint uVar9;
  longlong *plVar10;
  uint uVar11;
  longlong lVar12;
  int iVar13;
  byte *pbVar14;
  byte *pbVar15;
  longlong lVar16;
  uint uVar17;
  
  uVar11 = 0;
  iVar13 = 0x1002;
  if ((*(uint *)(param_2 + 4) & 0xc0) == 0) {
    lVar12 = param_2;
    lVar16 = param_3;
    if (param_5 == 0) {
      if ((*(short *)(*(longlong *)(param_1 + 8) + 0x48) == DAT_1c001a024) &&
         (*(int *)(*(longlong *)(param_1 + 8) + 0x18) == TwKernelOffloadV4FlowParams)) {
LAB_1c0003210:
        lVar16 = 0;
        plVar7 = TeredoWfpNewFlowV4Flow(param_1,param_2,0);
        if (plVar7 != (longlong *)0x0) goto LAB_1c000304f;
      }
      else {
        lVar16 = *(longlong *)(param_3 + 8);
        if ((*(int *)(lVar16 + 0x18) != 0) && (lVar2 = *(longlong *)(lVar16 + 8), lVar2 != 0)) {
          if ((*(byte *)(lVar2 + 10) & 5) == 0) {
            lVar5 = MmMapLockedPagesSpecifyCache(lVar2,0,1);
          }
          else {
            lVar5 = *(longlong *)(lVar2 + 0x18);
          }
          if (lVar5 != 0) {
            uVar9 = *(uint *)(lVar16 + 0x10);
            if (((uVar9 < *(uint *)(lVar2 + 0x28)) && (0x27 < *(uint *)(lVar2 + 0x28) - uVar9)) &&
               (lVar16 = lVar5 + (ulonglong)uVar9,
               ((byte)*(undefined4 *)(lVar5 + (ulonglong)uVar9) & 0xf0) == 0x60)) {
              if (((*(short *)(lVar16 + 0x18) != 0x120) || (*(short *)(lVar16 + 0x1a) != 0)) &&
                 ((*(short *)(lVar16 + 0x18) != -0x1c1 || (*(short *)(lVar16 + 0x1a) != 0x1f83)))) {
                sVar8 = (short)*(undefined8 *)(lVar16 + 8);
                sVar3 = (short)((ulonglong)*(undefined8 *)(lVar16 + 8) >> 0x10);
                if (((sVar8 != 0x120) || (sVar3 != 0)) && ((sVar8 != -0x1c1 || (sVar3 != 0x1f83))))
                {
                  if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0))
                  {
                    McTemplateK0qbr0br0_EtwWriteTransfer(&MS_TUNNEL_DRIVER_PROVIDER_ID_Context);
                  }
                  LOCK();
                  _DAT_1c00173c8 = _DAT_1c00173c8 + 1;
                  UNLOCK();
                  goto LAB_1c0002daa;
                }
              }
              goto LAB_1c0003210;
            }
          }
        }
        LOCK();
        _DAT_1c00173c0 = _DAT_1c00173c0 + 1;
        UNLOCK();
      }
    }
    else {
LAB_1c000304f:
      if ((param_6[6] & 1U) == 0) {
        if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
          McTemplateK0xxx_EtwWriteTransfer
                    (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,lVar12,lVar16,
                     *(undefined8 *)(param_2 + 0x40),(char)*param_4,
                     (char)*(undefined8 *)(param_2 + 0x20));
        }
      }
      else {
        iVar4 = FwpsQueryPacketInjectionState0(DAT_1c001a0e0,param_3);
        if (((iVar4 - 1U & 0xfffffffd) != 0) &&
           (plVar7 = TeredoWfpLocateV6FlowForInboundPacket(param_3), plVar7 != (longlong *)0x0)) {
          FwpsReferenceNetBufferList0(param_3,1);
          pbVar14 = (byte *)0x0;
          iVar4 = FwpsAllocateCloneNetBufferList0
                            (param_3,*(undefined8 *)(DAT_1c001a0c0 + 0x160),0,0);
          if (iVar4 < 0) {
LAB_1c0003310:
            FwpsDereferenceNetBufferList0(param_3,1);
          }
          else {
            uRam0000000000000068 = 0x43667754;
            uRam0000000000000110 = *(undefined8 *)(param_3 + 0x110);
            lRam0000000000000060 = param_3;
            uVar6 = RoReferenceEx((uint *)(DAT_1c001a0c0 + 0x40),1);
            lVar12 = DAT_1c001a0c0;
            if ((char)uVar6 == '\0') goto LAB_1c0003310;
            LOCK();
            DAT_1c001a028 = DAT_1c001a028 + 1;
            UNLOCK();
            uVar17 = 0;
            *(int *)(DAT_1c001a0c0 + 0x74) = *(int *)(DAT_1c001a0c0 + 0x74) + 1;
            *(longlong *)(lVar12 + 0x90) =
                 *(longlong *)(lVar12 + 0x90) + (ulonglong)*(uint *)(lRam0000000000000008 + 0x18);
            uVar9 = 0;
            pbVar14 = (byte *)((longlong)plVar7 + 0x82);
            do {
              uVar17 = uVar17 + 8;
              uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[-2] * 4) ^
                      uVar9 * 2;
              uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[-1] * 4) ^
                      uVar9 * 2;
              uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)*pbVar14 * 4) ^
                      uVar9 * 2;
              uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[1] * 4) ^
                      uVar9 * 2;
              uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[2] * 4) ^
                      uVar9 * 2;
              uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[3] * 4) ^
                      uVar9 * 2;
              uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[4] * 4) ^
                      uVar9 * 2;
              uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar14[5] * 4) ^
                      uVar9 * 2;
              pbVar14 = pbVar14 + 8;
            } while (uVar17 < 8);
            uVar17 = 0;
            pbVar15 = &DAT_1c0017341;
            do {
              pbVar14 = pbVar15 + 8;
              uVar17 = uVar17 + 8;
              uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar15[-1] * 4) ^
                      uVar9 * 2;
              uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)*pbVar15 * 4) ^
                      uVar9 * 2;
              uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar15[1] * 4) ^
                      uVar9 * 2;
              uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar15[2] * 4) ^
                      uVar9 * 2;
              uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar15[3] * 4) ^
                      uVar9 * 2;
              uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar15[4] * 4) ^
                      uVar9 * 2;
              uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar15[5] * 4) ^
                      uVar9 * 2;
              uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar15[6] * 4) ^
                      uVar9 * 2;
              pbVar15 = pbVar14;
            } while (uVar17 < 8);
            if (plVar7 != (longlong *)0xffffffffffffff98) {
              pbVar15 = (byte *)((longlong)plVar7 + 0x72);
              do {
                pbVar14 = pbVar15 + 8;
                uVar11 = uVar11 + 8;
                uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar15[-2] * 4) ^
                        uVar9 * 2;
                uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar15[-1] * 4) ^
                        uVar9 * 2;
                uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)*pbVar15 * 4) ^
                        uVar9 * 2;
                uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar15[1] * 4) ^
                        uVar9 * 2;
                uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar15[2] * 4) ^
                        uVar9 * 2;
                uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar15[3] * 4) ^
                        uVar9 * 2;
                uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar15[4] * 4) ^
                        uVar9 * 2;
                uVar9 = uVar9 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar15[5] * 4) ^
                        uVar9 * 2;
                pbVar15 = pbVar14;
              } while (uVar11 < 8);
            }
            lVar12 = (ulonglong)(uVar9 & 0x3f) * 0x58;
            KeAcquireSpinLockAtDpcLevel(lVar12 + 0x1c0017438);
            **(undefined8 **)(&DAT_1c0017428 + lVar12) = 0;
            *(longlong *)(&DAT_1c0017460 + lVar12) = *(longlong *)(&DAT_1c0017460 + lVar12) + 1;
            *(undefined8 *)(&DAT_1c0017428 + lVar12) = 0;
            if ((&DAT_1c0017440)[lVar12] == '\0') {
              *(longlong *)(&DAT_1c0017468 + lVar12) = *(longlong *)(&DAT_1c0017468 + lVar12) + 1;
              pbVar14 = (byte *)0x1;
              (&DAT_1c0017440)[lVar12] = 1;
              IoQueueWorkItem(*(undefined8 *)(&DAT_1c0017448 + lVar12),LwWorker,1,
                              &DAT_1c0017420 + lVar12);
            }
            KeReleaseSpinLockFromDpcLevel(lVar12 + 0x1c0017438);
            iVar13 = 0x1001;
            uVar11 = 1;
            plVar7[0x1a] = *(longlong *)(DAT_1c001a0c0 + 0x2c0);
            param_6[6] = param_6[6] & 0xfffffffe;
          }
          LOCK();
          piVar1 = (int *)((longlong)plVar7 + 0x1c);
          iVar4 = *piVar1;
          *piVar1 = *piVar1 + -2;
          UNLOCK();
          if (iVar4 == 3) {
            TeredoWfpRemoveHashEntry(plVar7);
            if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
              McTemplateK0q_EtwWriteTransfer
                        (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_TEREDO_FLOW_FREED,
                         pbVar14,*(undefined4 *)((longlong)plVar7 + 0x24));
            }
            if (plVar7[9] != 0) {
              ExFreePoolWithTag(plVar7[9],0x64437754);
            }
            plVar10 = &DAT_1c0017408;
            if (*(int *)((longlong)plVar7 + 0x24) != 2) {
              plVar10 = &DAT_1c0017400;
            }
            LOCK();
            *plVar10 = *plVar10 + -1;
            UNLOCK();
            ExFreePoolWithTag(plVar7,0x70667754);
          }
          if (iVar13 != 0x1002) goto LAB_1c0002db6;
        }
      }
    }
  }
LAB_1c0002daa:
  if ((*(byte *)((longlong)param_4 + 0x1a) & 1) != 0) {
    param_6[6] = param_6[6] & 0xfffffffe;
  }
LAB_1c0002db6:
  param_6[7] = param_6[7] | uVar11;
  *param_6 = iVar13;
  return;
}



===== TeredoWfpRemoveHashEntry @ 1c0003374 =====

void TeredoWfpRemoveHashEntry(longlong *param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  int iVar5;
  undefined1 uVar6;
  bool bVar7;
  
  lVar1 = param_1[5];
  if (*(char *)((longlong)param_1 + 0x8f) != '\0') {
    uVar6 = KeAcquireSpinLockRaiseToDpc(lVar1);
    lVar2 = *param_1;
    if ((*(longlong **)(lVar2 + 8) != param_1) ||
       (plVar3 = (longlong *)param_1[1], (longlong *)*plVar3 != param_1)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    param_1[1] = (longlong)param_1;
    *param_1 = (longlong)param_1;
    *(int *)(lVar1 + 8) = *(int *)(lVar1 + 8) + -1;
    *(undefined1 *)((longlong)param_1 + 0x8f) = 0;
    KeReleaseSpinLock(lVar1,CONCAT71((int7)((ulonglong)lVar2 >> 8),uVar6));
    LOCK();
    iVar5 = DAT_1c001a120 + -2;
    UNLOCK();
    bVar7 = DAT_1c001a120 == 3;
    DAT_1c001a120 = iVar5;
    if (bVar7) {
      KeSetEvent(&HashTableUninitializedEvent,0,0);
    }
  }
  return;
}



===== TeredoWfpNewFlowV4Flow @ 1c000341c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * TeredoWfpNewFlowV4Flow(longlong param_1,longlong param_2,int param_3)

{
  longlong *plVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  longlong *plVar7;
  undefined1 uVar8;
  int iVar9;
  longlong lVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  longlong *plVar13;
  ulonglong uVar14;
  undefined1 auStackY_b8 [32];
  undefined1 uStack_77;
  undefined1 uStack_76;
  undefined1 uStack_75;
  undefined1 uStack_73;
  undefined1 uStack_72;
  undefined1 uStack_71;
  longlong *local_70;
  undefined8 local_68;
  undefined1 auStack_60 [5];
  undefined1 uStack_5b;
  undefined1 uStack_5a;
  undefined1 uStack_59;
  undefined8 local_58;
  undefined1 auStack_50 [5];
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined1 uStack_49;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_70 = (longlong *)0x0;
  LOCK();
  _DAT_1c00173e0 = _DAT_1c00173e0 + 1;
  UNLOCK();
  lVar6 = *(longlong *)(param_1 + 8);
  lVar10 = (longlong)param_3;
  uVar2 = *(ushort *)(lVar6 + 8 + (ulonglong)*(uint *)(&DAT_1c00149e8 + lVar10 * 0x18) * 0x10);
  uVar14 = (ulonglong)uVar2;
  uVar4 = *(uint *)(lVar6 + 8 + (ulonglong)*(uint *)(&DAT_1c00149dc + lVar10 * 0x18) * 0x10);
  uVar5 = *(uint *)(lVar6 + 8 + (ulonglong)*(uint *)(&DAT_1c00149e0 + lVar10 * 0x18) * 0x10);
  uVar3 = *(ushort *)(lVar6 + 8 + (ulonglong)*(uint *)(&DAT_1c00149ec + lVar10 * 0x18) * 0x10);
  uVar12 = (ulonglong)uVar5;
  uVar11 = TeredoWfpLocateOrCreateV4Flow(uVar4,uVar5,uVar2,uVar3,'\x01',&local_70);
  plVar13 = local_70;
  if (local_70 != (longlong *)0x0) {
    uStack_71 = (undefined1)(uVar5 >> 0x18);
    if ((char)uVar11 == '\0') {
      TeredoWfpDereferenceFlowContextImp(local_70,uVar12,uVar14);
      uStack_77 = (undefined1)(uVar4 >> 8);
      plVar13 = (longlong *)0x0;
      local_58 = 0;
      uStack_76 = (undefined1)(uVar4 >> 0x10);
      uStack_75 = (undefined1)(uVar4 >> 0x18);
      local_68 = 0;
      _auStack_50 = CONCAT17(uStack_75,CONCAT16(uStack_76,CONCAT15(uStack_77,0xffff0000)));
      uStack_73 = (undefined1)(uVar5 >> 8);
      uStack_72 = (undefined1)(uVar5 >> 0x10);
      _auStack_60 = CONCAT17(uStack_71,CONCAT16(uStack_72,CONCAT15(uStack_73,0xffff0000)));
      auStack_50 = (undefined1  [5])CONCAT14((char)uVar4,0xffff0000);
      auStack_60 = (undefined1  [5])CONCAT14((char)uVar5,0xffff0000);
      if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
        McTemplateK0qbr0br0_EtwWriteTransfer(&MS_TUNNEL_DRIVER_PROVIDER_ID_Context);
      }
    }
    else {
      if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
        McTemplateK0qqhh_EtwWriteTransfer
                  (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,uVar12,uVar14,
                   uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18,
                   uStack_71,(char)(uVar2 >> 8),(char)(uVar3 >> 8));
      }
      plVar1 = plVar13 + 2;
      uVar8 = KeAcquireSpinLockRaiseToDpc(plVar1);
      *(undefined2 *)(plVar13 + 7) = 0x18;
      plVar13[6] = *(longlong *)(param_2 + 0x20);
      plVar13[8] = *(longlong *)(param_2 + 0x70);
      *(undefined4 *)(plVar13 + 0xb) = *(undefined4 *)(param_2 + 0x78);
      uVar11 = TeredoWfpDuplicateControlData((longlong)plVar13,param_2);
      plVar7 = local_70;
      if ((int)uVar11 < 0) {
        LOCK();
        *(int *)((longlong)plVar13 + 0x1c) = *(int *)((longlong)plVar13 + 0x1c) + -1;
        UNLOCK();
        TeredoWfpDereferenceFlowContextImp(local_70,param_2,uVar14);
        KeReleaseSpinLock(plVar1,uVar8);
        plVar13 = plVar7;
      }
      else {
        KeReleaseSpinLock(plVar1,uVar8);
        uVar14 = (ulonglong)TwCalloutIdV4;
        uVar12 = (ulonglong)*(ushort *)(plVar13 + 7);
        iVar9 = FwpsFlowAssociateContext0(plVar13[6],uVar12,uVar14,plVar13);
        *(undefined1 *)((longlong)plVar13 + 0x91) = 1;
        if (iVar9 < 0) {
          LOCK();
          *(int *)((longlong)plVar13 + 0x1c) = *(int *)((longlong)plVar13 + 0x1c) + -1;
          UNLOCK();
          TeredoWfpDereferenceFlowContextImp(local_70,uVar12,uVar14);
          plVar13 = (longlong *)0x0;
        }
        else {
          *(undefined1 *)((longlong)plVar13 + 0x8c) = 1;
        }
      }
    }
  }
  return plVar13;
}



===== RoReferenceEx @ 1c0003680 =====

ulonglong RoReferenceEx(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  do {
    uVar2 = *param_1;
    if ((uVar2 & 1) != 0) {
      return (ulonglong)(uVar2 & 0xffffff00);
    }
    LOCK();
    uVar1 = *param_1;
    bVar3 = uVar2 == uVar1;
    if (bVar3) {
      *param_1 = uVar2 + param_2 * 2;
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (!bVar3);
  return CONCAT71((uint7)(uint3)(uVar1 >> 8),1);
}



===== TeredoWfpLocateV6FlowForInboundPacket @ 1c00036b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong * TeredoWfpLocateV6FlowForInboundPacket(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  undefined1 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong *plVar10;
  byte *pbVar11;
  uint uVar12;
  longlong *plVar13;
  longlong lVar14;
  undefined1 auStack_88 [32];
  undefined4 local_68;
  undefined4 local_60;
  longlong local_58;
  undefined8 uStack_50;
  longlong local_48;
  longlong lStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_88;
  lVar1 = *(longlong *)(param_1 + 8);
  if ((*(int *)(lVar1 + 0x18) != 0) && (lVar2 = *(longlong *)(lVar1 + 8), lVar2 != 0)) {
    if ((*(byte *)(lVar2 + 10) & 5) == 0) {
      local_60 = 0x40000010;
      local_68 = 0;
      lVar6 = MmMapLockedPagesSpecifyCache(lVar2,0,1);
    }
    else {
      lVar6 = *(longlong *)(lVar2 + 0x18);
    }
    if (lVar6 != 0) {
      uVar7 = *(uint *)(lVar1 + 0x10);
      uVar5 = (ulonglong)uVar7;
      if (((uVar7 < *(uint *)(lVar2 + 0x28)) && (0x27 < *(uint *)(lVar2 + 0x28) - uVar7)) &&
         (((byte)*(undefined4 *)(uVar5 + lVar6) & 0xf0) == 0x60)) {
        plVar9 = (longlong *)(uVar5 + 0x18 + lVar6);
        local_48 = *plVar9;
        lStack_40 = plVar9[1];
        plVar9 = (longlong *)(uVar5 + 8 + lVar6);
        local_58 = *plVar9;
        uStack_50 = plVar9[1];
        bVar3 = TeredoWfpIsDataPacket(*(longlong *)(param_1 + 8),(uint)lVar6);
        if (bVar3) {
          plVar9 = (longlong *)0x0;
          uVar5 = RoReferenceEx((uint *)&DAT_1c001a120,1);
          if ((char)uVar5 == '\0') {
            return (longlong *)0x0;
          }
          uVar7 = 0;
          uVar12 = 0;
          pbVar11 = (byte *)((longlong)&uStack_50 + 1);
          do {
            uVar12 = uVar12 + 8;
            uVar7 = uVar7 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[-1] * 4) ^
                    uVar7 * 2;
            uVar7 = uVar7 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)*pbVar11 * 4) ^ uVar7 * 2;
            uVar7 = uVar7 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[1] * 4) ^
                    uVar7 * 2;
            uVar7 = uVar7 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[2] * 4) ^
                    uVar7 * 2;
            uVar7 = uVar7 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[3] * 4) ^
                    uVar7 * 2;
            uVar7 = uVar7 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[4] * 4) ^
                    uVar7 * 2;
            uVar7 = uVar7 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[5] * 4) ^
                    uVar7 * 2;
            uVar7 = uVar7 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[6] * 4) ^
                    uVar7 * 2;
            pbVar11 = pbVar11 + 8;
          } while (uVar12 < 8);
          uVar12 = 0;
          pbVar11 = &DAT_1c0017341;
          do {
            uVar12 = uVar12 + 8;
            uVar7 = uVar7 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[-1] * 4) ^
                    uVar7 * 2;
            uVar7 = uVar7 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)*pbVar11 * 4) ^ uVar7 * 2;
            uVar7 = uVar7 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[1] * 4) ^
                    uVar7 * 2;
            uVar7 = uVar7 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[2] * 4) ^
                    uVar7 * 2;
            uVar7 = uVar7 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[3] * 4) ^
                    uVar7 * 2;
            uVar7 = uVar7 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[4] * 4) ^
                    uVar7 * 2;
            uVar7 = uVar7 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[5] * 4) ^
                    uVar7 * 2;
            uVar7 = uVar7 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar11[6] * 4) ^
                    uVar7 * 2;
            pbVar11 = pbVar11 + 8;
          } while (uVar12 < 8);
          lVar8 = (ulonglong)(uVar7 % 0x407) * 0x20 + DAT_1c0017360;
          uVar4 = KeAcquireSpinLockRaiseToDpc(lVar8);
          lVar6 = local_48;
          lVar2 = uStack_50;
          lVar1 = local_58;
          plVar13 = *(longlong **)(lVar8 + 0x10);
          plVar10 = (longlong *)(lVar8 + 0x10);
          if (plVar13 != plVar10) {
            lVar14 = lStack_40;
            do {
              plVar9 = plVar13;
              plVar13 = plVar9;
              if ((((plVar9[0xd] == lVar6) && (plVar9[0xe] == lVar14)) &&
                  ((plVar9[0xf] == lVar1 &&
                   ((plVar9[0x10] == lVar2 && (*(char *)((longlong)plVar9 + 0x8e) != '\0')))))) &&
                 (uVar5 = RoReferenceEx((uint *)((longlong)plVar9 + 0x1c),1), (char)uVar5 != '\0'))
              break;
              plVar13 = (longlong *)*plVar13;
            } while (plVar13 != plVar10);
          }
          plVar10 = (longlong *)0x0;
          if (plVar13 != (longlong *)(lVar8 + 0x10)) {
            plVar10 = plVar9;
          }
          KeReleaseSpinLock(lVar8,uVar4);
          LOCK();
          UNLOCK();
          if (DAT_1c001a120 == 3) {
            DAT_1c001a120 = DAT_1c001a120 + -2;
            KeSetEvent(&HashTableUninitializedEvent,0,0);
            return plVar10;
          }
          DAT_1c001a120 = DAT_1c001a120 + -2;
          return plVar10;
        }
      }
    }
  }
  return (longlong *)0x0;
}



===== TeredoWfpIsDataPacket @ 1c0003a40 =====

bool TeredoWfpIsDataPacket(longlong param_1,uint param_2)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  uint local_res10 [6];
  
  local_res10[0] = param_2 & 0xffffff00;
  if ((*(int *)(param_1 + 0x18) != 0) && (lVar2 = *(longlong *)(param_1 + 8), lVar2 != 0)) {
    if ((*(byte *)(lVar2 + 10) & 5) == 0) {
      lVar4 = MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000010);
    }
    else {
      lVar4 = *(longlong *)(lVar2 + 0x18);
    }
    if (lVar4 != 0) {
      uVar1 = *(uint *)(param_1 + 0x10);
      if (((uVar1 < *(uint *)(lVar2 + 0x28)) && (0x27 < *(uint *)(lVar2 + 0x28) - uVar1)) &&
         (((byte)*(undefined4 *)((ulonglong)uVar1 + lVar4) & 0xf0) == 0x60)) {
        iVar3 = FwpiParseIPv6Protocol0(param_1,local_res10);
        if (-1 < iVar3) {
          if ((char)local_res10[0] == ':') {
            return false;
          }
          return (char)local_res10[0] != ';';
        }
      }
    }
  }
  return true;
}



===== TunnelUserReadFile @ 1c0003b20 =====

int TunnelUserReadFile(undefined8 param_1,longlong *******param_2,longlong *******param_3)

{
  longlong ****pppplVar1;
  longlong ****pppplVar2;
  longlong *******ppppppplVar3;
  longlong ****pppplVar4;
  longlong ********pppppppplVar5;
  longlong ***ppplVar6;
  code *pcVar7;
  uint uVar8;
  int iVar9;
  ulonglong uVar10;
  longlong *****ppppplVar11;
  longlong ******pppppplVar12;
  int iVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined8 *puVar16;
  undefined8 *local_res18 [2];
  undefined1 auStack_98 [8];
  undefined1 auStack_90 [24];
  undefined4 local_78;
  undefined4 local_70;
  longlong ********local_68;
  longlong ********local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  puVar16 = (undefined8 *)0x0;
  iVar9 = 0;
  local_res18[0] = (undefined8 *)0x0;
  local_60 = (longlong ********)&local_68;
  pppplVar4 = param_2[0x17][6][4];
  pppppplVar12 = param_2[1];
  local_68 = (longlong ********)&local_68;
  iVar13 = *(int *)(pppplVar4 + 3);
  if (pppppplVar12 == (longlong ******)0x0) goto LAB_1c0003d32;
  if ((*(byte *)((longlong)pppppplVar12 + 10) & 5) == 0) {
    local_70 = 0x40000010;
    local_78 = 0;
    param_3 = (longlong *******)0x1;
    ppppplVar11 = (longlong *****)MmMapLockedPagesSpecifyCache();
  }
  else {
    ppppplVar11 = pppppplVar12[3];
  }
  if (ppppplVar11 == (longlong *****)0x0) {
    iVar13 = -0x3fffff66;
  }
  else {
    if (*param_2[1] == (longlong *****)0x0) {
      uVar8 = 0x550;
      if (iVar13 != 0xe) {
        uVar8 = 0x508;
      }
      if (uVar8 <= *(uint *)(param_2[1] + 5)) {
        pppplVar2 = pppplVar4 + 0x23;
        param_2[0x10] = (longlong ******)0x1;
        KeAcquireSpinLockRaiseToDpc(pppplVar2);
        if (((ulonglong)pppplVar4[0x59] & 1) == 0) {
          pppplVar1 = pppplVar4 + 8;
          pppppplVar12 = (longlong ******)0x1;
          uVar10 = RoReferenceEx((uint *)pppplVar1,1);
          if ((char)uVar10 != '\0') {
            *(int *)((longlong)pppplVar4 + 0x14c) = *(int *)((longlong)pppplVar4 + 0x14c) + 1;
            param_2[0xf] = pppppplVar12;
            ppppppplVar3 = param_2 + 0x15;
            pppppplVar12 = (longlong ******)pppplVar4[0x26];
            if (*pppppplVar12 != (longlong *****)(pppplVar4 + 0x25)) goto LAB_1c0003f51;
            *ppppppplVar3 = (longlong ******)(pppplVar4 + 0x25);
            param_2[0x16] = pppppplVar12;
            *pppppplVar12 = (longlong *****)ppppppplVar3;
            pppplVar4[0x26] = (longlong ***)ppppppplVar3;
            LOCK();
            param_2[0xd] = (longlong ******)TunnelUserIoCancelRead;
            UNLOCK();
            if (*(char *)((longlong)param_2 + 0x44) == '\0') {
LAB_1c0003c80:
              iVar13 = 0x103;
              *(byte *)((longlong)param_2[0x17] + 3) = *(byte *)((longlong)param_2[0x17] + 3) | 1;
              *(undefined4 *)(pppplVar4 + 0x3a) = 0;
              if ((pppplVar4[0x2d] != (longlong ***)0x0) && (((ulonglong)pppplVar4[0x59] & 4) == 0))
              {
                if (((ulonglong)pppplVar4[0x59] & 0x20) == 0) {
                  iVar9 = TunnelServiceReadRequests((longlong)pppplVar4,(longlong *)local_res18);
                }
                else {
                  param_3 = (longlong *******)&local_68;
                  iVar9 = TunnelUserServiceBatchedReadRequests
                                    ((longlong)pppplVar4,local_res18,(longlong ******)param_3,'\0');
                }
              }
            }
            else {
              LOCK();
              pppppplVar12 = param_2[0xd];
              param_2[0xd] = (longlong ******)0x0;
              UNLOCK();
              if (pppppplVar12 == (longlong ******)0x0) goto LAB_1c0003c80;
              iVar13 = -0x3ffffee0;
            }
            KeReleaseSpinLock(pppplVar2);
            local_48 = 0;
            local_58 = 0;
            uStack_50 = 0;
            LOCK();
            uVar8 = *(uint *)pppplVar1;
            *(uint *)pppplVar1 = *(uint *)pppplVar1 - 2;
            UNLOCK();
            if (uVar8 == 3) {
              RtlAcquireWriteLock((longlong)(pppplVar4[2] + 3));
              ppplVar6 = pppplVar4[9];
              pppplVar4[9] = (longlong ***)0x0;
              if (((ulonglong)pppplVar4[0x17] & 1) == 0) {
                KeReleaseInStackQueuedSpinLock(&local_58);
              }
              else {
                *(uint *)(pppplVar4 + 0x17) = *(uint *)(pppplVar4 + 0x17) & 0xfffffffe | 2;
                KeReleaseInStackQueuedSpinLock();
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
                  param_3 = (longlong *******)&WPP_9608820f130d35da1284a1080d801204_Traceguids;
                  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                           &WPP_9608820f130d35da1284a1080d801204_Traceguids,
                           *(undefined4 *)(pppplVar4 + 5));
                }
                if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
                  McTemplateK0q_EtwWriteTransfer
                            (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,
                             &EVENT_TUNNEL_INTERFACE_PAUSE_COMPLETE,param_3,
                             *(undefined4 *)(pppplVar4 + 5));
                }
                NdisMPauseComplete(pppplVar4[7]);
              }
              if (ppplVar6 != (longlong ***)0x0) {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
                  param_3 = (longlong *******)&WPP_9608820f130d35da1284a1080d801204_Traceguids;
                  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                           &WPP_9608820f130d35da1284a1080d801204_Traceguids,
                           *(undefined4 *)(pppplVar4 + 5));
                }
                if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
                  McTemplateK0q_EtwWriteTransfer
                            (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,
                             &EVENT_TUNNEL_INTERFACE_POWER_COMPLETE,param_3,
                             *(undefined4 *)(pppplVar4 + 5));
                }
                TunnelPnpLogRequestCompletion((longlong)pppplVar4);
                IofCompleteRequest(ppplVar6);
              }
            }
            puVar16 = local_res18[0];
            if (iVar13 == 0x103) goto LAB_1c0003cf2;
            goto LAB_1c0003b8a;
          }
        }
        else {
          TunnelUserSignalCloseComplete((longlong)pppplVar4);
        }
        iVar13 = -0x3ffffe7c;
        KeReleaseSpinLock(pppplVar2);
        goto LAB_1c0003b8a;
      }
    }
LAB_1c0003d32:
    iVar13 = -0x3ffffff3;
  }
LAB_1c0003b8a:
  *(int *)(param_2 + 6) = iVar13;
  param_2[7] = (longlong ******)0x0;
  while( true ) {
    IofCompleteRequest(param_2);
LAB_1c0003cf2:
    puVar15 = auStack_98;
    if ((longlong *********)local_68 == &local_68) {
      puVar14 = auStack_98;
      if (puVar16 != (undefined8 *)0x0) goto LAB_1c0003f58;
      goto LAB_1c0003d0e;
    }
    if (((longlong *********)local_68[1] != &local_68) ||
       (pppppppplVar5 = (longlong ********)*local_68,
       (longlong ********)pppppppplVar5[1] != local_68)) break;
    pppppppplVar5[1] = (longlong *******)&local_68;
    param_2 = (longlong *******)(local_68 + -0x15);
    local_68 = pppppppplVar5;
  }
LAB_1c0003f51:
  pcVar7 = (code *)swi(0x29);
  (*pcVar7)(3);
  puVar15 = auStack_90;
LAB_1c0003f58:
  ppplVar6 = pppplVar4[7];
  *(undefined4 *)(puVar15 + 0x28) = 0;
  *(undefined4 *)(puVar15 + 0x20) = 0;
  *(undefined8 *)(puVar15 + -8) = 0x1c0003f73;
  TunnelUserRestoreAndFreeNblAndNbState
            (puVar16,'\0','\x01',ppplVar6,*(undefined4 *)(puVar15 + 0x20),
             *(undefined4 *)(puVar15 + 0x28));
  puVar14 = puVar15;
LAB_1c0003d0e:
  if (iVar9 != 0) {
    *(undefined8 *)(puVar14 + -8) = 0x1c0003f86;
    TunnelInterfaceDereferenceExImp((longlong)pppplVar4,iVar9,(undefined *)0x0);
  }
  return iVar13;
}



===== TunnelServiceReadRequests @ 1c0003fa0 =====

int TunnelServiceReadRequests(longlong param_1,longlong *param_2)

{
  uint uVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong lVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  code *pcVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined2 uVar12;
  longlong lVar13;
  longlong lVar14;
  ulonglong uVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  longlong *plVar18;
  int iVar19;
  undefined8 *puVar20;
  undefined8 *puVar21;
  bool bVar22;
  undefined4 local_res8;
  ulonglong local_res18;
  ulonglong local_res20;
  undefined1 auStack_a8 [8];
  undefined1 auStack_a0 [24];
  ulonglong local_88;
  ulonglong *local_80;
  undefined8 *local_78;
  undefined8 local_70;
  ulonglong local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  
  puVar17 = auStack_a8;
  *(uint *)(param_1 + 0x2c8) = *(uint *)(param_1 + 0x2c8) | 4;
  iVar19 = 0;
  local_78 = (undefined8 *)0x0;
  puVar20 = (undefined8 *)0x0;
  plVar18 = param_2;
  puVar21 = puVar20;
  if (*(longlong *)(param_1 + 0x168) != 0) {
    do {
      plVar2 = *(longlong **)(param_1 + 0x128);
      puVar20 = puVar21;
      if (plVar2 == (longlong *)(param_1 + 0x128)) break;
      *(int *)(param_1 + 0x14c) = *(int *)(param_1 + 0x14c) + -1;
      lVar14 = *plVar2;
      if ((*(longlong **)(lVar14 + 8) != plVar2) ||
         (plVar3 = (longlong *)plVar2[1], (longlong *)*plVar3 != plVar2)) {
        pcVar8 = (code *)swi(0x29);
        (*pcVar8)(3);
        puVar17 = auStack_a0;
        goto LAB_1c0004313;
      }
      *plVar3 = lVar14;
      *(longlong **)(lVar14 + 8) = plVar3;
      *plVar2 = 0;
      plVar2[-6] = 0;
      plVar2[1] = 0;
      LOCK();
      lVar14 = plVar2[-8];
      plVar2[-8] = 0;
      UNLOCK();
      puVar4 = local_78;
      if (lVar14 != 0) {
        puVar4 = *(undefined8 **)(param_1 + 0x168);
        *(undefined8 *)(param_1 + 0x168) = *puVar4;
        *puVar4 = 0;
        if (*(longlong *)(param_1 + 0x168) == 0) {
          *(undefined8 *)(param_1 + 0x170) = 0;
        }
        KeReleaseSpinLockFromDpcLevel(param_1 + 0x118);
        lVar14 = puVar4[1];
        lVar5 = plVar2[-0x14];
        local_res8 = 0;
        local_res20 = (ulonglong)*(uint *)(lVar14 + 0x18);
        local_70 = *(undefined8 *)(lVar14 + 8);
        local_68 = (ulonglong)*(uint *)(lVar14 + 0x10);
        local_res18 = 0;
        if (*(uint *)(lVar5 + 0x28) < local_res20) {
          local_res8 = 0x80000005;
        }
        else {
          if ((char)plVar2[-5] != '\0') {
            if ((*(byte *)(lVar5 + 10) & 5) == 0) {
              local_80 = (ulonglong *)CONCAT44(local_80._4_4_,0x40000000);
              local_88 = local_88 & 0xffffffff00000000;
              lVar14 = MmMapLockedPagesSpecifyCache(lVar5,0,1);
            }
            else {
              lVar14 = *(longlong *)(lVar5 + 0x18);
            }
            for (lVar13 = puVar4[0x21]; lVar13 != 0; lVar13 = *(longlong *)(lVar13 + 8)) {
              if (*(int *)(lVar13 + 0x10) == 0x10001) {
                puVar6 = *(undefined4 **)(lVar13 + 0x18);
                if (puVar6 != (undefined4 *)0x0) {
                  uVar9 = puVar6[1];
                  uVar10 = puVar6[2];
                  uVar11 = puVar6[3];
                  *(undefined4 *)(lVar14 + 4) = *puVar6;
                  *(undefined4 *)(lVar14 + 8) = uVar9;
                  *(undefined4 *)(lVar14 + 0xc) = uVar10;
                  *(undefined4 *)(lVar14 + 0x10) = uVar11;
                  *(undefined8 *)(lVar14 + 0x14) = *(undefined8 *)(puVar6 + 4);
                  *(undefined4 *)(lVar14 + 0x1c) = puVar6[6];
                  uVar12 = *(undefined2 *)(puVar6 + 7);
                  goto LAB_1c000411a;
                }
                break;
              }
            }
            uVar12 = 0;
            *(undefined8 *)(lVar14 + 4) = 0;
            *(undefined8 *)(lVar14 + 0xc) = 0;
            *(undefined8 *)(lVar14 + 0x14) = 0;
            *(undefined4 *)(lVar14 + 0x1c) = 0;
LAB_1c000411a:
            *(undefined2 *)(lVar14 + 0x20) = uVar12;
            bVar22 = Microsoft_Windows_Networking_CorrelationEnabled != 0;
            if (bVar22) {
              uVar15 = puVar4[0x1f] & 0x7fffffffffffffff;
              uStack_58 = 0;
              local_60._0_4_ = (undefined4)uVar15;
              local_60._4_4_ = (undefined4)(uVar15 >> 0x20);
              *(undefined4 *)(lVar14 + 0x24) = (undefined4)local_60;
              *(undefined4 *)(lVar14 + 0x28) = local_60._4_4_;
              *(undefined4 *)(lVar14 + 0x2c) = 0;
              *(undefined4 *)(lVar14 + 0x30) = 0;
              local_60 = uVar15;
            }
            *(bool *)(lVar14 + 0x22) = bVar22;
          }
          local_80 = &local_res18;
          local_88 = local_res20;
          RtlCopyMdlToMdl(local_70,local_68,lVar5);
          if (local_res18 < local_res20) {
            local_res8 = 0x80000005;
          }
        }
        uVar15 = local_res18;
        plVar18 = (longlong *)(param_1 + 0x170);
        *(undefined4 *)(plVar2 + -0xf) = local_res8;
        plVar2[-0xe] = local_res18 & 0xffffffff;
        IofCompleteRequest(plVar2 + -0x15,2);
        KeAcquireSpinLockAtDpcLevel(param_1 + 0x118);
        *(int *)(puVar4 + 0xd) = *(int *)(puVar4 + 0xd) + -1;
        *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
        *(longlong *)(param_1 + 0x88) = *(longlong *)(param_1 + 0x88) + uVar15;
        puVar4[1] = *(undefined8 *)puVar4[1];
        if (*(int *)(puVar4 + 0xd) == 0) {
          iVar19 = iVar19 + 1;
          puVar20 = puVar4;
          if (puVar21 != (undefined8 *)0x0) {
            *local_78 = puVar4;
            puVar20 = puVar21;
          }
        }
        else {
          uVar7 = *(undefined8 *)(param_1 + 0x168);
          *(undefined8 **)(param_1 + 0x168) = puVar4;
          *puVar4 = uVar7;
          puVar4 = local_78;
          if (*plVar18 == 0) {
            *plVar18 = *(longlong *)(param_1 + 0x168);
          }
        }
      }
      local_78 = puVar4;
      puVar21 = puVar20;
    } while (*(longlong *)(param_1 + 0x168) != 0);
  }
  uVar1 = *(uint *)(param_1 + 0x2c8);
  *(uint *)(param_1 + 0x2c8) = uVar1 & 0xfffffffb;
  puVar16 = auStack_a8;
  plVar18 = param_2;
  puVar21 = puVar20;
  if ((uVar1 & 1) != 0) {
LAB_1c0004313:
    *(undefined8 *)(puVar17 + -8) = 0x1c000431b;
    TunnelCompletePendingNdisAppSends(param_1);
    puVar16 = puVar17;
  }
  *(undefined8 *)(puVar16 + -8) = 0x1c000421f;
  TunnelUserSignalCloseComplete(param_1);
  *plVar18 = (longlong)puVar21;
  return iVar19;
}



===== TunnelUserWriteFile @ 1c0004330 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TunnelUserWriteFile(undefined8 param_1,longlong param_2,undefined *param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined1 uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  undefined1 auStackY_c8 [32];
  ulonglong local_58 [4];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_c8;
  puVar6 = (undefined8 *)0x0;
  iVar11 = 0;
  lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x20);
  lVar8 = *(longlong *)(param_2 + 8);
  iVar10 = *(int *)(lVar4 + 0x18);
  if (lVar8 == 0) {
LAB_1c000464f:
    *(int *)(lVar4 + 0x7c) = *(int *)(lVar4 + 0x7c) + 1;
    iVar10 = -0x3ffffff3;
    goto LAB_1c00045c8;
  }
  if ((*(byte *)(lVar8 + 10) & 5) == 0) {
    param_3 = (undefined *)0x1;
    lVar8 = MmMapLockedPagesSpecifyCache(lVar8,0);
  }
  else {
    lVar8 = *(longlong *)(lVar8 + 0x18);
  }
  if (lVar8 == 0) {
LAB_1c000439b:
    iVar10 = -0x3fffff66;
  }
  else {
    if (iVar10 == 0xe) {
      if ((**(longlong **)(param_2 + 8) != 0) || (*(uint *)(*(longlong **)(param_2 + 8) + 5) < 0x54)
         ) goto LAB_1c000464f;
      *(undefined8 *)(param_2 + 0x80) = 1;
    }
    param_3 = (undefined *)0x0;
    puVar6 = (undefined8 *)NdisAllocateNetBufferList(*(undefined8 *)(lVar4 + 0x158),0);
    if (puVar6 == (undefined8 *)0x0) goto LAB_1c000439b;
    TunnelUserSnapshotNblAndNbState(puVar6);
    *(undefined4 *)(puVar6[1] + 0x10) = 0;
    *(undefined4 *)(puVar6[1] + 0x28) = 0;
    if (DAT_1c001aa1a != '\0') {
      *(uint *)(puVar6 + 0x13) = *(uint *)(puVar6 + 0x13) | 2;
    }
    lVar8 = *(longlong *)(puVar6[1] + 8);
    if ((*(byte *)(lVar8 + 10) & 5) == 0) {
      param_3 = (undefined *)0x1;
      lVar8 = MmMapLockedPagesSpecifyCache(lVar8,0);
    }
    else {
      lVar8 = *(longlong *)(lVar8 + 0x18);
    }
    if (lVar8 == 0) {
      NdisFreeNetBufferList(puVar6);
      puVar6 = (undefined8 *)0x0;
      goto LAB_1c000439b;
    }
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar4 + 0x118);
    if ((*(uint *)(lVar4 + 0x2c8) & 1) == 0) {
      *(int *)(lVar4 + 0x148) = *(int *)(lVar4 + 0x148) + 1;
      uVar7 = RoReferenceEx((uint *)(lVar4 + 0x40),2);
      if ((char)uVar7 == '\0') {
        iVar10 = -0x3ffffe7c;
      }
      else {
        lVar8 = *(longlong *)(param_2 + 8);
        param_3 = *(undefined **)(puVar6[1] + 0x20);
        uVar7 = (ulonglong)*(uint *)(lVar8 + 0x28);
        if (*(char *)(param_2 + 0x80) != '\0') {
          if ((*(byte *)(lVar8 + 10) & 5) == 0) {
            puVar9 = (uint *)MmMapLockedPagesSpecifyCache(lVar8,0,1);
          }
          else {
            puVar9 = *(uint **)(lVar8 + 0x18);
          }
          uVar3 = puVar9[0xe];
          puVar6[0x22] = (ulonglong)*puVar9;
          if ((Microsoft_Windows_Networking_CorrelationEnabled != 0) &&
             (*(char *)((longlong)puVar9 + 0x22) != '\0')) {
            local_58[0] = puVar6[0x1f] & 0x7fffffffffffffff;
            local_58[1] = 0;
            if (Microsoft_Windows_Networking_CorrelationEnabled != 0) {
              EtwEx_tidActivityInfoTransfer();
            }
          }
          uVar7 = uVar7 - (uVar3 + 0x50);
        }
        RtlCopyMdlToMdl(lVar8);
        if (uVar7 == 0) {
          *(undefined4 *)(puVar6[1] + 0x18) = 0;
          puVar6[0x19] = 0xdd86;
          KeReleaseSpinLockFromDpcLevel(lVar4 + 0x118);
          param_3 = (undefined *)0x0;
          NdisMIndicateReceiveNetBufferLists(*(undefined8 *)(lVar4 + 0x38),puVar6);
          iVar10 = 0;
          KeAcquireSpinLockAtDpcLevel(lVar4 + 0x118);
        }
        else {
          iVar10 = -0x7ffffffb;
        }
        *(int *)(lVar4 + 0x74) = *(int *)(lVar4 + 0x74) + 1;
        iVar11 = (iVar10 != 0) + 1;
        *(undefined8 *)(lVar4 + 0x90) = *(undefined8 *)(lVar4 + 0x90);
      }
    }
    else {
      iVar10 = -0x3ffffe7c;
      TunnelUserSignalCloseComplete(lVar4);
    }
    *(int *)(lVar4 + 0x148) = *(int *)(lVar4 + 0x148) + -1;
    TunnelUserSignalCloseComplete(lVar4);
    KeReleaseSpinLock(lVar4 + 0x118,uVar5);
    if (-1 < iVar10) goto LAB_1c00045c8;
  }
  *(int *)(lVar4 + 0x7c) = *(int *)(lVar4 + 0x7c) + 1;
LAB_1c00045c8:
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(int *)(param_2 + 0x30) = iVar10;
  IofCompleteRequest(param_2,0);
  if ((iVar10 != 0) && (puVar6 != (undefined8 *)0x0)) {
    param_3 = (undefined *)0x0;
    TunnelUserRestoreAndFreeNblAndNbState(puVar6,'\x01','\0',0,0,0);
    *(int *)(lVar4 + 0x7c) = *(int *)(lVar4 + 0x7c) + 1;
  }
  if (iVar11 != 0) {
    local_58[2] = 0;
    local_58[0] = 0;
    local_58[1] = 0;
    LOCK();
    piVar1 = (int *)(lVar4 + 0x40);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + iVar11 * -2;
    UNLOCK();
    if (iVar2 + iVar11 * -2 == 1) {
      RtlAcquireWriteLock(*(longlong *)(lVar4 + 0x10) + 0x18);
      lVar8 = *(longlong *)(lVar4 + 0x48);
      *(undefined8 *)(lVar4 + 0x48) = 0;
      if ((*(byte *)(lVar4 + 0xb8) & 1) == 0) {
        KeReleaseInStackQueuedSpinLock(local_58);
      }
      else {
        *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) & 0xfffffffe | 2;
        KeReleaseInStackQueuedSpinLock();
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
          param_3 = &WPP_9608820f130d35da1284a1080d801204_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                   &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(undefined4 *)(lVar4 + 0x28));
        }
        if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
          McTemplateK0q_EtwWriteTransfer
                    (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_PAUSE_COMPLETE,
                     param_3,*(undefined4 *)(lVar4 + 0x28));
        }
        NdisMPauseComplete(*(undefined8 *)(lVar4 + 0x38));
      }
      if (lVar8 != 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
          param_3 = &WPP_9608820f130d35da1284a1080d801204_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                   &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(undefined4 *)(lVar4 + 0x28));
        }
        if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
          McTemplateK0q_EtwWriteTransfer
                    (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_POWER_COMPLETE,
                     param_3,*(undefined4 *)(lVar4 + 0x28));
        }
        TunnelPnpLogRequestCompletion(lVar4);
        IofCompleteRequest(lVar8,0);
      }
    }
  }
  return iVar10;
}



===== TunnelUserSignalCloseComplete @ 1c0004910 =====

ulonglong TunnelUserSignalCloseComplete(longlong param_1)

{
  ulonglong uVar1;
  longlong *plVar2;
  undefined8 uVar3;
  
  plVar2 = (longlong *)(param_1 + 0x128);
  if ((((longlong *)*plVar2 == plVar2) && (*(int *)(param_1 + 0x148) == 0)) &&
     (plVar2 = (longlong *)((ulonglong)*(uint *)(param_1 + 0x2c8) & 0xffffffffffffff05),
     (char)plVar2 == '\x01')) {
    uVar3 = KeSetEvent(param_1 + 0x1d8,2);
    uVar1 = CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
  }
  else {
    uVar1 = (ulonglong)plVar2 & 0xffffffffffffff00;
  }
  return uVar1;
}



===== TunnelUserSendNetBufferList @ 1c0004970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TunnelUserSendNetBufferList
               (longlong param_1,undefined8 *param_2,longlong *******param_3,uint param_4)

{
  int *piVar1;
  undefined4 uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  longlong ********pppppppplVar5;
  code *pcVar6;
  undefined1 uVar7;
  char cVar8;
  int iVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  longlong ********pppppppplVar13;
  int iVar14;
  undefined1 *puVar15;
  char cVar16;
  int iVar17;
  longlong ********pppppppplVar18;
  longlong lVar19;
  undefined1 local_res10;
  undefined1 auStackY_c8 [8];
  undefined1 auStackY_c0 [24];
  undefined8 *local_90;
  undefined8 *local_88;
  undefined8 *local_80;
  undefined8 *local_78;
  longlong ********local_70;
  longlong ********local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  
  cVar16 = '\0';
  local_88 = (undefined8 *)0x0;
  local_90 = (undefined8 *)0x0;
  pppppppplVar18 = (longlong ********)param_3;
  uVar7 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x118);
  puVar12 = (undefined8 *)0x0;
  local_78 = (undefined8 *)0x0;
  local_68 = (longlong ********)&local_70;
  local_80 = (undefined8 *)0x0;
  local_70 = (longlong ********)&local_70;
  local_res10 = 0;
  cVar8 = (**(code **)(*(longlong *)(param_1 + 0x20) + 0xa0))(param_1);
  puVar15 = auStackY_c8;
  if (cVar8 != '\0') {
    if (param_2 != (undefined8 *)0x0) {
      puVar10 = puVar12;
      cVar16 = '\0';
      do {
        puVar3 = (undefined8 *)*param_2;
        pppppppplVar18 = (longlong ********)((ulonglong)param_3 & 0xff);
        *param_2 = 0;
        cVar8 = (**(code **)(*(longlong *)(param_1 + 0x20) + 0xa8))(param_1,param_2);
        if (cVar8 == '\0') {
          if (puVar12 == (undefined8 *)0x0) {
            puVar12 = param_2;
          }
          else {
            *local_78 = param_2;
          }
          puVar10 = (undefined8 *)(ulonglong)((int)puVar10 + 1);
          local_78 = param_2;
        }
        else {
          cVar16 = cVar16 + '\x01';
        }
        param_2 = puVar3;
      } while (puVar3 != (undefined8 *)0x0);
      local_res10 = SUB81(puVar10,0);
      local_80 = puVar12;
    }
    if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
      McTemplateK0qqq_EtwWriteTransfer
                (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_OFFLOADED_SEND_NBL,
                 pppppppplVar18,*(undefined4 *)(param_1 + 0x18),cVar16,local_res10);
    }
    param_2 = puVar12;
  }
  iVar9 = 0;
  lVar19 = param_1 + 0x118;
  if (param_2 == (undefined8 *)0x0) {
LAB_1c0004a76:
    KeReleaseSpinLock(lVar19,uVar7);
LAB_1c0004a89:
    puVar12 = local_88;
  }
  else {
    iVar14 = 1;
    puVar10 = (undefined8 *)*param_2;
    puVar12 = param_2;
    while (puVar3 = puVar10, puVar3 != (undefined8 *)0x0) {
      iVar14 = iVar14 + 1;
      puVar12 = puVar3;
      puVar10 = (undefined8 *)*puVar3;
    }
    TunnelUserSnapshotNblAndNbState(param_2);
    if ((((*(uint *)(param_1 + 0x2c8) & 1) != 0) || ((*(uint *)(param_1 + 0xb8) & 0x20) == 0)) ||
       (uVar11 = RoReferenceEx((uint *)(param_1 + 0x40),iVar14), (char)uVar11 == '\0')) {
      iVar17 = -0x3ffffe7c;
      if ((DAT_1c0017024 == 0) || ((Microsoft_Windows_TunnelDriverEnableBits & 1) == 0)) {
LAB_1c0004c64:
        KeReleaseSpinLock(lVar19,uVar7);
        if (-1 < iVar17) goto LAB_1c0004a89;
      }
      else {
        McTemplateK0qqq_EtwWriteTransfer
                  (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,
                   &EVENT_TUNNEL_SEND_FAILED_INVALID_DEVICE_STATE,pppppppplVar18,
                   *(undefined4 *)(param_1 + 0x18),(char)*(undefined4 *)(param_1 + 0x28),
                   (char)iVar14);
        KeReleaseSpinLock(lVar19,uVar7);
      }
      uVar4 = *(undefined8 *)(param_1 + 0x38);
      *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + iVar14;
      puVar12 = param_2;
      do {
        puVar10 = (undefined8 *)puVar12[0xc];
        if (puVar12[0xd] == 0x43667754) {
          puVar3 = (undefined8 *)*puVar12;
          *puVar12 = 0;
          puVar12[0xc] = 0;
          puVar12[0xd] = 0;
          FwpsFreeCloneNetBufferList0(puVar12,0);
          FwpsDereferenceNetBufferList0(puVar10);
          puVar12 = puVar3;
        }
        else {
          puVar12[1] = puVar10;
          for (; puVar10 != (undefined8 *)0x0; puVar10 = (undefined8 *)*puVar10) {
            puVar10[1] = puVar10[0x10];
            *(undefined4 *)(puVar10 + 2) = *(undefined4 *)(puVar10 + 0x11);
            *(undefined4 *)(puVar10 + 5) = *(undefined4 *)((longlong)puVar10 + 0x8c);
          }
          *(undefined4 *)((longlong)puVar12 + 0x8c) = 0xc0000001;
          puVar12 = (undefined8 *)*puVar12;
        }
      } while (puVar12 != (undefined8 *)0x0);
      pppppppplVar18 = (longlong ********)(ulonglong)param_4;
      NdisMSendNetBufferListsComplete(uVar4,param_2);
      puVar12 = local_88;
      goto LAB_1c0004a91;
    }
    iVar17 = 0x103;
    if (*(longlong *)(param_1 + 0x168) == 0) {
      *(undefined8 **)(param_1 + 0x168) = param_2;
    }
    else {
      **(undefined8 **)(param_1 + 0x170) = param_2;
    }
    *(undefined8 **)(param_1 + 0x170) = puVar12;
    if (*(longlong **)(param_1 + 0x128) == (longlong *)(param_1 + 0x128)) goto LAB_1c0004a76;
    if ((*(uint *)(param_1 + 0x2c8) & 4) != 0) goto LAB_1c0004c64;
    if ((*(uint *)(param_1 + 0x2c8) & 0x20) == 0) {
      iVar9 = TunnelServiceReadRequests(param_1,(longlong *)&local_90);
    }
    else {
      local_68 = (longlong ********)&local_70;
      pppppppplVar18 = (longlong ********)&local_70;
      local_70 = (longlong ********)&local_70;
      iVar9 = TunnelUserServiceBatchedReadRequests
                        (param_1,&local_90,(longlong ******)pppppppplVar18,'\x01');
    }
    KeReleaseSpinLock(lVar19,uVar7);
    puVar12 = local_90;
  }
LAB_1c0004a91:
  do {
    if ((longlong *********)local_70 == &local_70) {
      if (puVar12 != (undefined8 *)0x0) {
        uVar4 = *(undefined8 *)(param_1 + 0x38);
        puVar10 = puVar12;
        do {
          puVar3 = (undefined8 *)puVar10[0xc];
          if (puVar10[0xd] == 0x43667754) {
            puVar3 = (undefined8 *)*puVar10;
            *puVar10 = 0;
            puVar10[0xc] = 0;
            puVar10[0xd] = 0;
            FwpsFreeCloneNetBufferList0(puVar10,0);
            FwpsDereferenceNetBufferList0();
            puVar10 = puVar3;
          }
          else {
            puVar10[1] = puVar3;
            for (; puVar3 != (undefined8 *)0x0; puVar3 = (undefined8 *)*puVar3) {
              puVar3[1] = puVar3[0x10];
              *(undefined4 *)(puVar3 + 2) = *(undefined4 *)(puVar3 + 0x11);
              *(undefined4 *)(puVar3 + 5) = *(undefined4 *)((longlong)puVar3 + 0x8c);
            }
            *(undefined4 *)((longlong)puVar10 + 0x8c) = 0;
            puVar10 = (undefined8 *)*puVar10;
          }
        } while (puVar10 != (undefined8 *)0x0);
        pppppppplVar18 = (longlong ********)(ulonglong)param_4;
        NdisMSendNetBufferListsComplete(uVar4,puVar12);
      }
      if (iVar9 != 0) {
        local_50 = 0;
        local_60 = 0;
        uStack_58 = 0;
        LOCK();
        piVar1 = (int *)(param_1 + 0x40);
        iVar14 = *piVar1;
        *piVar1 = *piVar1 + iVar9 * -2;
        UNLOCK();
        if (iVar14 + iVar9 * -2 == 1) {
LAB_1c0004e37:
          lVar19 = *(longlong *)(param_1 + 0x10);
          *(undefined8 *)(puVar15 + -8) = 0x1c0004e48;
          RtlAcquireWriteLock(lVar19 + 0x18);
          lVar19 = *(longlong *)(param_1 + 0x48);
          *(undefined8 *)(param_1 + 0x48) = 0;
          if ((*(byte *)(param_1 + 0xb8) & 1) == 0) {
            *(undefined8 *)(puVar15 + -8) = 0x1c0004f03;
            KeReleaseInStackQueuedSpinLock(&local_60);
          }
          else {
            *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffe | 2;
            *(undefined8 *)(puVar15 + -8) = 0x1c0004e88;
            KeReleaseInStackQueuedSpinLock();
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
              uVar2 = *(undefined4 *)(param_1 + 0x28);
              pppppppplVar18 = (longlong ********)&WPP_9608820f130d35da1284a1080d801204_Traceguids;
              uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
              *(undefined8 *)(puVar15 + -8) = 0x1c0004ec1;
              WPP_SF_D(uVar4,10,&WPP_9608820f130d35da1284a1080d801204_Traceguids,uVar2);
            }
            if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
              uVar2 = *(undefined4 *)(param_1 + 0x28);
              *(undefined8 *)(puVar15 + -8) = 0x1c0004eea;
              McTemplateK0q_EtwWriteTransfer
                        (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,
                         &EVENT_TUNNEL_INTERFACE_PAUSE_COMPLETE,pppppppplVar18,uVar2);
            }
            uVar4 = *(undefined8 *)(param_1 + 0x38);
            *(undefined8 *)(puVar15 + -8) = 0x1c0004ef5;
            NdisMPauseComplete(uVar4);
          }
          if (lVar19 != 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
              uVar2 = *(undefined4 *)(param_1 + 0x28);
              pppppppplVar18 = (longlong ********)&WPP_9608820f130d35da1284a1080d801204_Traceguids;
              uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
              *(undefined8 *)(puVar15 + -8) = 0x1c0004f45;
              WPP_SF_D(uVar4,0xb,&WPP_9608820f130d35da1284a1080d801204_Traceguids,uVar2);
            }
            if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
              uVar2 = *(undefined4 *)(param_1 + 0x28);
              *(undefined8 *)(puVar15 + -8) = 0x1c0004f6e;
              McTemplateK0q_EtwWriteTransfer
                        (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,
                         &EVENT_TUNNEL_INTERFACE_POWER_COMPLETE,pppppppplVar18,uVar2);
            }
            *(undefined8 *)(puVar15 + -8) = 0x1c0004f76;
            TunnelPnpLogRequestCompletion(param_1);
            *(undefined8 *)(puVar15 + -8) = 0x1c0004f82;
            IofCompleteRequest(lVar19,0);
          }
        }
      }
      return;
    }
    if (((longlong *********)local_70[1] != &local_70) ||
       (pppppppplVar5 = (longlong ********)*local_70,
       (longlong ********)pppppppplVar5[1] != local_70)) {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      puVar15 = auStackY_c0;
      goto LAB_1c0004e37;
    }
    pppppppplVar5[1] = (longlong *******)&local_70;
    pppppppplVar13 = local_70 + -0x15;
    local_70 = pppppppplVar5;
    IofCompleteRequest(pppppppplVar13,CONCAT71((int7)((ulonglong)&local_70 >> 8),2));
  } while( true );
}



===== TunnelUserSnapshotNblAndNbState @ 1c0004fa0 =====

int TunnelUserSnapshotNblAndNbState(undefined8 *param_1)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  for (; param_1 != (undefined8 *)0x0; param_1 = (undefined8 *)*param_1) {
    puVar1 = (undefined8 *)param_1[1];
    iVar3 = 0;
    param_1[0xc] = puVar1;
    for (; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)*puVar1) {
      iVar3 = iVar3 + 1;
      puVar1[0x10] = puVar1[1];
      *(undefined4 *)(puVar1 + 0x11) = *(undefined4 *)(puVar1 + 2);
      *(undefined4 *)((longlong)puVar1 + 0x8c) = *(undefined4 *)(puVar1 + 5);
    }
    *(int *)(param_1 + 0xd) = iVar3;
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}



===== TunnelUserServiceBatchedReadRequests @ 1c0005000 =====

int TunnelUserServiceBatchedReadRequests
              (longlong param_1,undefined8 *param_2,longlong ******param_3,char param_4)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  longlong *********ppppppppplVar4;
  code *pcVar5;
  bool bVar6;
  int iVar7;
  longlong *plVar8;
  int iVar9;
  undefined4 uVar10;
  ulonglong uVar11;
  longlong *plVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
  undefined1 *puVar16;
  longlong **********pppppppppplVar17;
  longlong *********ppppppppplVar18;
  ulonglong uVar19;
  int iVar20;
  undefined8 *puVar21;
  undefined8 *puVar22;
  undefined8 *puVar23;
  uint local_res20;
  undefined1 auStack_118 [8];
  undefined1 auStack_110 [24];
  ulonglong local_f8;
  longlong *local_f0;
  int local_e8;
  uint local_e4;
  longlong *local_e0;
  undefined8 *local_d8;
  longlong **********local_d0;
  longlong **********local_c8;
  int local_c0;
  int local_bc;
  longlong local_b8;
  undefined8 *local_b0;
  longlong *********local_a8;
  undefined8 *local_a0;
  ulonglong local_98;
  undefined8 *local_90;
  undefined8 *local_88;
  longlong *local_80;
  undefined8 uStack_78;
  undefined8 *local_70;
  longlong *local_68;
  undefined8 uStack_60;
  longlong **********local_58;
  
  puVar16 = auStack_118;
  puVar14 = *(undefined8 **)(param_1 + 0x168);
  local_e4 = 0;
  uVar11 = 0;
  local_90 = (undefined8 *)0x0;
  puVar22 = (undefined8 *)0x0;
  local_d8 = (undefined8 *)0x0;
  local_e8 = 0;
  local_bc = 0;
  puVar15 = (undefined8 *)0x0;
  local_c0 = 0;
  local_e0 = (longlong *)0x0;
  uVar19 = 0;
  local_88 = (undefined8 *)0x0;
  local_a0 = (undefined8 *)0x0;
  local_70 = (undefined8 *)0x0;
  local_res20 = 0;
  local_c8 = (longlong **********)&local_d0;
  local_d0 = (longlong **********)&local_d0;
  local_80 = (longlong *)0x0;
  uStack_78 = 0;
  local_68 = (longlong *)0x0;
  uStack_60 = 0;
  if (param_4 != '\0') {
    if ((((*(longlong **)(param_1 + 0x128) != (longlong *)(param_1 + 0x128)) &&
         (puVar14 != (undefined8 *)0x0)) && ((*(uint *)(param_1 + 0x2c8) & 0x40) == 0)) &&
       (uVar11 = RoReferenceEx((uint *)(param_1 + 0x40),1), (char)uVar11 != '\0')) {
      *(uint *)(param_1 + 0x2c8) = *(uint *)(param_1 + 0x2c8) | 0x40;
      KeInitializeDpc(param_1 + 0x188,TunnelUserSendNBLDpc,param_1);
      KeSetImportanceDpc(param_1 + 0x188,3);
      KeInsertQueueDpc(param_1 + 0x188,0,0);
    }
    return 0;
  }
  if (puVar14 == (undefined8 *)0x0) {
LAB_1c00052ee:
    local_e0 = local_68;
    local_e8 = (int)uStack_60;
    local_a0 = local_70;
  }
  else {
    do {
      iVar20 = local_e8;
      plVar12 = TunnelUserGetNextReadIrp(param_1);
      if (plVar12 == (longlong *)0x0) break;
      uVar3 = *(uint *)(plVar12[1] + 0x28);
      puVar21 = (undefined8 *)(ulonglong)*(uint *)(puVar14[1] + 0x18);
      LOCK();
      lVar2 = plVar12[0xd];
      plVar12[0xd] = 0;
      UNLOCK();
      if (lVar2 == 0) {
LAB_1c00052aa:
        puVar15 = local_88;
      }
      else {
        lVar2 = plVar12[1];
        if ((*(byte *)(lVar2 + 10) & 5) == 0) {
          local_f0 = (longlong *)CONCAT44(local_f0._4_4_,0x40000000);
          local_f8 = local_f8 & 0xffffffff00000000;
          puVar13 = (undefined8 *)MmMapLockedPagesSpecifyCache(lVar2,0,1);
          uVar11 = (ulonglong)local_e4;
          uVar19 = (ulonglong)local_res20;
        }
        else {
          puVar13 = *(undefined8 **)(lVar2 + 0x18);
        }
        puVar23 = (undefined8 *)((ulonglong)uVar3 - 8);
        *puVar13 = *(undefined8 *)(param_1 + 0x178);
        pppppppppplVar17 = (longlong **********)(plVar12 + 0x15);
        *(longlong *)(param_1 + 0x178) = *(longlong *)(param_1 + 0x178) + 1;
        if ((longlong ***********)*local_c8 != &local_d0) goto LAB_1c000557a;
        plVar12[0x16] = (longlong)local_c8;
        *pppppppppplVar17 = (longlong *********)&local_d0;
        *local_c8 = (longlong *********)pppppppppplVar17;
        local_c8 = pppppppppplVar17;
        if (puVar23 < puVar21) goto LAB_1c00052aa;
        plVar12 = local_e0;
        puVar15 = local_88;
        do {
          if (local_e8 == 0) {
            plVar12 = (longlong *)puVar14[1];
            local_e0 = plVar12;
          }
          *(int *)(param_1 + 0x70) = *(int *)(param_1 + 0x70) + 1;
          local_e8 = local_e8 + 1;
          *(longlong *)(param_1 + 0x88) = *(longlong *)(param_1 + 0x88) + (longlong)puVar21;
          puVar23 = (undefined8 *)((longlong)puVar23 - (longlong)puVar21);
          puVar14[1] = *(undefined8 *)puVar14[1];
          *(int *)(puVar14 + 0xd) = *(int *)(puVar14 + 0xd) + -1;
          if (puVar14[1] == 0) {
            *(undefined8 *)(param_1 + 0x168) = *puVar14;
            *puVar14 = 0;
            if ((longlong *)puVar14[0xc] == plVar12) {
              local_e4 = (int)uVar11 + 1;
              uVar11 = (ulonglong)local_e4;
              if (puVar22 == (undefined8 *)0x0) {
                puVar22 = puVar14;
                local_90 = puVar14;
              }
              else {
                *local_d8 = puVar14;
              }
              local_d8 = puVar14;
            }
            else {
              *(int *)(puVar14 + 0xd) = *(int *)(puVar14 + 0xd) + local_e8;
              local_res20 = (uint)uVar19 | 1;
              uVar19 = (ulonglong)local_res20;
              uStack_78 = CONCAT44(uStack_78._4_4_,local_e8);
              puVar15 = puVar14;
              local_88 = puVar14;
              local_80 = plVar12;
            }
            puVar14 = *(undefined8 **)(param_1 + 0x168);
            plVar12 = (longlong *)0x0;
            local_e8 = 0;
            local_e0 = (longlong *)0x0;
            if (puVar14 == (undefined8 *)0x0) break;
          }
          puVar21 = (undefined8 *)(ulonglong)*(uint *)(puVar14[1] + 0x18);
        } while (puVar21 <= puVar23);
      }
      iVar20 = local_e8;
    } while (*(longlong *)(param_1 + 0x168) != 0);
    if (((puVar14 == (undefined8 *)0x0) || (*(int *)(puVar14 + 0xd) == 0)) || (iVar20 == 0))
    goto LAB_1c00052ee;
    *(int *)(puVar14 + 0xd) = *(int *)(puVar14 + 0xd) + iVar20;
    local_a0 = puVar14;
  }
  puVar23 = local_a0;
  plVar12 = local_e0;
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x118);
  puVar14 = puVar22;
  if (puVar22 != (undefined8 *)0x0) {
    do {
      puVar21 = (undefined8 *)puVar14[0xc];
      if (puVar14[0xd] == 0x43667754) {
        puVar13 = (undefined8 *)*puVar14;
        *puVar14 = 0;
        puVar14[0xc] = 0;
        puVar14[0xd] = 0;
        FwpsFreeCloneNetBufferList0();
        FwpsDereferenceNetBufferList0(puVar21);
        puVar14 = puVar13;
      }
      else {
        puVar14[1] = puVar21;
        for (; puVar21 != (undefined8 *)0x0; puVar21 = (undefined8 *)*puVar21) {
          puVar21[1] = puVar21[0x10];
          *(undefined4 *)(puVar21 + 2) = *(undefined4 *)(puVar21 + 0x11);
          *(undefined4 *)(puVar21 + 5) = *(undefined4 *)((longlong)puVar21 + 0x8c);
        }
        puVar14 = (undefined8 *)*puVar14;
      }
    } while (puVar14 != (undefined8 *)0x0);
    plVar12 = local_e0;
  }
  local_b0 = puVar22;
  if ((local_res20 & 1) == 0) {
    if (puVar22 == (undefined8 *)0x0) {
      iVar20 = 2;
    }
    else {
      plVar12 = (longlong *)puVar22[1];
      iVar20 = 1;
    }
  }
  else {
    iVar20 = 0;
    plVar12 = local_80;
  }
  while( true ) {
    plVar8 = local_e0;
    iVar7 = local_e8;
    local_58 = local_d0;
    if ((longlong ***********)local_d0 == &local_d0) break;
    local_b8 = 0;
    local_a8 = (longlong *********)0x8;
    if (((longlong ***********)local_d0[1] != &local_d0) ||
       (pppppppppplVar17 = (longlong **********)*local_d0,
       (longlong **********)pppppppppplVar17[1] != local_d0)) goto LAB_1c000557a;
    iVar9 = (int)uStack_78;
    pppppppppplVar17[1] = (longlong *********)&local_d0;
    ppppppppplVar4 = local_d0[-0x14];
    ppppppppplVar18 = (longlong *********)0x8;
    bVar6 = false;
    local_98 = (ulonglong)*(uint *)(ppppppppplVar4 + 5) - 8;
    local_d0 = pppppppppplVar17;
LAB_1c0005459:
    do {
      if ((local_98 < *(uint *)(plVar12 + 3)) || (bVar6)) break;
      local_f0 = &local_b8;
      local_f8 = (ulonglong)*(uint *)(plVar12 + 3);
      RtlCopyMdlToMdl(plVar12[1],(int)plVar12[2],ppppppppplVar4,ppppppppplVar18);
      ppppppppplVar18 = (longlong *********)((longlong)ppppppppplVar18 + local_b8);
      plVar12 = (longlong *)*plVar12;
      local_98 = local_98 - local_b8;
      if (iVar20 == 0) {
        local_bc = local_bc + 1;
        if (local_bc == iVar9) {
          if (local_b0 == (undefined8 *)0x0) goto LAB_1c00054ec;
          plVar12 = (longlong *)local_b0[1];
          iVar20 = 1;
        }
        else {
LAB_1c000551d:
        }
      }
      else if (iVar20 == 1) {
        if (plVar12 != (longlong *)0x0) goto LAB_1c0005459;
        local_b0 = (undefined8 *)*local_b0;
        if (local_b0 == (undefined8 *)0x0) {
LAB_1c00054ec:
          iVar20 = 2;
          plVar12 = plVar8;
        }
        else {
          plVar12 = (longlong *)local_b0[1];
        }
      }
      else {
        if ((iVar20 != 2) || (local_c0 = local_c0 + 1, local_c0 != iVar7)) goto LAB_1c000551d;
        bVar6 = true;
      }
    } while (plVar12 != (longlong *)0x0);
    pppppppppplVar17 = local_58;
    puVar15 = local_88;
    puVar22 = local_90;
    puVar23 = local_a0;
    uVar10 = 0;
    if (local_b8 == 0) {
      uVar10 = 0xc0000023;
    }
    local_a8 = ppppppppplVar18;
    *(undefined4 *)(local_58 + -0xf) = uVar10;
    pppppppppplVar17[-0xe] = local_a8;
    ppppppppplVar4 = (longlong *********)param_3[1];
    if (*ppppppppplVar4 != (longlong ********)param_3) goto LAB_1c000557a;
    *pppppppppplVar17 = (longlong *********)param_3;
    pppppppppplVar17[1] = ppppppppplVar4;
    *ppppppppplVar4 = (longlong ********)pppppppppplVar17;
    param_3[1] = (longlong *****)pppppppppplVar17;
  }
LAB_1c0005581:
  *(undefined8 *)(puVar16 + -8) = 0x1c000558f;
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x118);
  iVar20 = *(int *)(puVar16 + 0x34);
  if ((int)uStack_78 != 0) {
    piVar1 = (int *)(puVar15 + 0xd);
    *piVar1 = *piVar1 - (int)uStack_78;
    if (*piVar1 == 0) {
      iVar20 = iVar20 + 1;
      *puVar15 = 0;
      if (puVar22 == (undefined8 *)0x0) {
        puVar22 = puVar15;
      }
      else {
        *local_d8 = puVar15;
      }
      goto LAB_1c00055cc;
    }
  }
  puVar15 = local_d8;
LAB_1c00055cc:
  if (*(int *)(puVar16 + 0x30) != 0) {
    piVar1 = (int *)(puVar23 + 0xd);
    *piVar1 = *piVar1 - *(int *)(puVar16 + 0x30);
    if (*piVar1 == 0) {
      iVar20 = iVar20 + 1;
      *puVar23 = 0;
      if (puVar22 == (undefined8 *)0x0) {
        puVar22 = puVar23;
      }
      else {
        *puVar15 = puVar23;
      }
    }
  }
  *(uint *)(param_1 + 0x2c8) = *(uint *)(param_1 + 0x2c8) & 0xfffffffb;
  if ((*(uint *)(param_1 + 0x2c8) & 1) != 0) {
    *(undefined8 *)(puVar16 + -8) = 0x1c000560a;
    TunnelCompletePendingNdisAppSends(param_1);
  }
  *(undefined8 *)(puVar16 + -8) = 0x1c0005612;
  TunnelUserSignalCloseComplete(param_1);
  *param_2 = puVar22;
  return iVar20;
LAB_1c000557a:
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  puVar16 = auStack_110;
  goto LAB_1c0005581;
}



===== TeredoWfpCreateAndInsertV6Flow @ 1c0005638 =====

ulonglong * TeredoWfpCreateAndInsertV6Flow(ulonglong param_1,ulonglong *param_2,ulonglong *param_3)

{
  code *pcVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  int iVar5;
  undefined1 *puVar6;
  bool bVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar2 = (ulonglong *)ExAllocatePool2(0x40,0xe0,0x70667754);
  if (puVar2 != (ulonglong *)0x0) {
    KeInitializeSpinLock(puVar2 + 2);
    *(undefined4 *)(puVar2 + 3) = 0x43667754;
    *(undefined4 *)((longlong)puVar2 + 0x24) = 2;
    *(uint *)((longlong)puVar2 + 0x1c) = 2;
    iVar5 = 1;
    RoReferenceEx((uint *)((longlong)puVar2 + 0x1c),1);
    bVar7 = DAT_1c0017360 != 0;
    uVar3 = param_2[1];
    puVar2[0xd] = *param_2;
    puVar2[0xe] = uVar3;
    uVar3 = param_3[1];
    puVar2[0xf] = *param_3;
    puVar2[0x10] = uVar3;
    if (bVar7) {
      uVar3 = RoReferenceEx(&DAT_1c001a120,iVar5);
      puVar6 = auStack_28;
      if ((char)uVar3 != '\0') {
        puVar4 = (ulonglong *)(param_1 + 0x10);
        uVar3 = *puVar4;
        if (*(ulonglong **)(uVar3 + 8) != puVar4) {
          uVar3 = (ulonglong)(iVar5 + 2);
          pcVar1 = (code *)swi(0x29);
          puVar4 = (ulonglong *)(*pcVar1)();
          puVar6 = auStack_20;
        }
        *puVar2 = uVar3;
        puVar2[1] = (ulonglong)puVar4;
        *(ulonglong **)(uVar3 + 8) = puVar2;
        *puVar4 = (ulonglong)puVar2;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        *(undefined8 *)(puVar6 + -8) = 0x1c0005706;
        KeResetEvent(&HashTableUninitializedEvent);
        *(undefined1 *)((longlong)puVar2 + 0x8f) = 1;
        puVar2[5] = param_1;
        LOCK();
        DAT_1c0017408 = DAT_1c0017408 + 1;
        UNLOCK();
        return puVar2;
      }
    }
    ExFreePoolWithTag(puVar2,0x70667754);
  }
  return (ulonglong *)0x0;
}



===== TunnelUserGetNextReadIrp @ 1c0005758 =====

longlong * TunnelUserGetNextReadIrp(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  
  plVar4 = *(longlong **)(param_1 + 0x128);
  if (plVar4 == (longlong *)(param_1 + 0x128)) {
    return (longlong *)0x0;
  }
  *(int *)(param_1 + 0x14c) = *(int *)(param_1 + 0x14c) + -1;
  lVar1 = *plVar4;
  if ((*(longlong **)(lVar1 + 8) == plVar4) &&
     (plVar2 = (longlong *)plVar4[1], (longlong *)*plVar2 == plVar4)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    plVar4[-6] = 0;
    *plVar4 = 0;
    plVar4[1] = 0;
    return plVar4 + -0x15;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  plVar4 = (longlong *)(*pcVar3)();
  return plVar4;
}



===== TunnelUserCleanupFile @ 1c00057b0 =====

undefined4 TunnelUserCleanupFile(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  uVar6 = 0;
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x20);
  lVar2 = *(longlong *)(lVar1 + 0x10);
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  if (DAT_1c001aa19 != '\0') {
    LOCK();
    iVar4 = DAT_1c001a0f8 + -1;
    UNLOCK();
    bVar3 = 1 < DAT_1c001a0f8;
    DAT_1c001a0f8 = iVar4;
    if (bVar3) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0;
      goto LAB_1c000590d;
    }
  }
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x118);
  KeInitializeEvent(lVar1 + 0x1d8,0,0);
  *(uint *)(lVar1 + 0x2c8) = *(uint *)(lVar1 + 0x2c8) | 1;
  TunnelUserCancelPendingReads(lVar1);
  TunnelCompletePendingNdisAppSends(lVar1);
  TunnelUserSignalCloseComplete(lVar1);
  KeReleaseSpinLock(lVar1 + 0x118,uVar5);
  uVar6 = KeWaitForSingleObject(lVar1 + 0x1d8,0,0,0,0);
  TunnelIndicateStatus(lVar1,2,100000);
  KeAcquireInStackQueuedSpinLock(lVar2 + 0x18,&local_38);
  do {
  } while (*(int *)(lVar2 + 0x20) != 0);
  *(uint *)(lVar1 + 0xb8) = *(uint *)(lVar1 + 0xb8) & 0xffffffdf;
  KeReleaseInStackQueuedSpinLock(&local_38);
  *(uint *)(lVar1 + 0x2c8) = *(uint *)(lVar1 + 0x2c8) & 0xfffffffe;
  KeSetEvent(lVar1 + 0x1f0,0,0);
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = uVar6;
LAB_1c000590d:
  IofCompleteRequest(param_2,0);
  return uVar6;
}



===== TunnelCompletePendingNdisAppSends @ 1c0005948 =====

void TunnelCompletePendingNdisAppSends(longlong param_1)

{
  undefined8 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined8 **)(param_1 + 0x168);
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined8 *)(param_1 + 0x168) = 0;
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x118);
    iVar2 = TunnelUserRestoreAndFreeNblAndNbState
                      (puVar1,'\0','\x01',*(undefined8 *)(param_1 + 0x38),1,0xc0000001);
    TunnelInterfaceDereferenceExImp(param_1,iVar2,(undefined *)0x0);
    *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + iVar2;
    KeAcquireSpinLockAtDpcLevel(param_1 + 0x118);
  }
  return;
}



===== TunnelUserCancelPendingReads @ 1c00059e0 =====

void TunnelUserCancelPendingReads(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  
  while (plVar2 = TunnelUserGetNextReadIrp(param_1), plVar2 != (longlong *)0x0) {
    LOCK();
    lVar1 = plVar2[0xd];
    plVar2[0xd] = 0;
    UNLOCK();
    if (lVar1 != 0) {
      KeReleaseSpinLockFromDpcLevel(param_1 + 0x118);
      plVar2[7] = 0;
      *(undefined4 *)(plVar2 + 6) = 0xc0000120;
      IofCompleteRequest(plVar2);
      KeAcquireSpinLockAtDpcLevel(param_1 + 0x118);
    }
  }
  return;
}



===== TunnelNlDeleteAddressNotificationHelper @ 1c0005a68 =====

void TunnelNlDeleteAddressNotificationHelper(undefined8 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  char cVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  longlong *local_res8;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  puVar1 = param_1 + -7;
  local_res8 = (longlong *)0x0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + -4,&local_38);
  do {
  } while (*(int *)(param_1 + -3) != 0);
  for (puVar6 = (undefined8 *)*puVar1; puVar6 != puVar1; puVar6 = (undefined8 *)*puVar6) {
    if (param_2 == 0) {
      TunnelRemoveAllPhysicalInterfaceAssociationForTunnel((longlong)puVar6);
    }
    else {
      cVar3 = TunnelIsNlLocalAddressAssociatedWithTunnel
                        ((longlong)puVar6,param_2,(int *)0x0,&local_res8);
      if (cVar3 != '\0') {
        TunnelRemoveV4AddressAssociationForTunnel((longlong)puVar6,local_res8);
        local_res8 = (longlong *)0x0;
      }
    }
    lVar2 = puVar6[0x20];
    if ((lVar2 != 0) && ((param_2 == 0 || (lVar2 == param_2)))) {
      TunnelNlDereferenceLocalAddressObject(param_1,lVar2);
      puVar6[0x20] = 0;
      uVar4 = TunnelUpdateLinkSpeed((longlong)puVar6,&local_38);
      uVar5 = RoReferenceEx((uint *)(puVar6 + 8),1);
      if ((char)uVar5 != '\0') {
        KeReleaseInStackQueuedSpinLock(&local_38);
        TunnelIndicateStatus((longlong)puVar6,2,uVar4);
        KeAcquireInStackQueuedSpinLock(param_1 + -4,&local_38);
        do {
        } while (*(int *)(param_1 + -3) != 0);
        TunnelInterfaceDereferenceExImp
                  ((longlong)puVar6,1,(undefined *)CONCAT71((int7)((ulonglong)uVar4 >> 8),1));
        puVar6 = (undefined8 *)*puVar1;
      }
    }
  }
  KeReleaseInStackQueuedSpinLock(&local_38);
  return;
}



===== TunnelNlcDetachNlProvider @ 1c0005be0 =====

uint TunnelNlcDetachNlProvider(undefined8 *param_1)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  puVar1 = param_1 + -7;
  param_1[2] = param_1[3];
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + -4,&local_28);
  do {
  } while (*(int *)(param_1 + -3) != 0);
  for (puVar6 = (undefined8 *)*puVar1; puVar6 != puVar1; puVar6 = (undefined8 *)*puVar6) {
    TunnelRemoveAllPhysicalInterfaceAssociationForTunnel((longlong)puVar6);
    if (puVar6[0x20] != 0) {
      TunnelNlDereferenceLocalAddressObject(param_1,puVar6[0x20]);
      puVar6[0x20] = 0;
      uVar4 = TunnelUpdateLinkSpeed((longlong)puVar6,&local_28);
      uVar5 = RoReferenceEx((uint *)(puVar6 + 8),1);
      if ((char)uVar5 != '\0') {
        KeReleaseInStackQueuedSpinLock(&local_28);
        TunnelIndicateStatus((longlong)puVar6,2,uVar4);
        KeAcquireInStackQueuedSpinLock(param_1 + -4,&local_28);
        do {
        } while (*(int *)(param_1 + -3) != 0);
        TunnelInterfaceDereferenceExImp
                  ((longlong)puVar6,1,(undefined *)CONCAT71((int7)((ulonglong)uVar4 >> 8),1));
        puVar6 = (undefined8 *)*puVar1;
      }
    }
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  LOCK();
  piVar2 = (int *)(param_1 + 5);
  iVar3 = *piVar2;
  *piVar2 = *piVar2 + -1;
  UNLOCK();
  return -(uint)(iVar3 != 2) & 0x103;
}



===== TunnelWorkQueueRoutine @ 1c0005d30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TunnelWorkQueueRoutine(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(&DAT_1c001a9d0);
  do {
    puVar2 = DAT_1c001a9c0;
    *DAT_1c001a9c8 = 0;
    DAT_1c001a9c8 = &DAT_1c001a9c0;
    DAT_1c001a9c0 = &DAT_1c001a9c0;
    KeReleaseSpinLock(&DAT_1c001a9d0,uVar3);
    while (puVar2 != (undefined8 *)0x0) {
      puVar1 = (undefined8 *)*puVar2;
      if ((code *)puVar2[3] == TunnelTimeoutWorkItemRoutine) {
        TunnelTimeoutWorkItemRoutine();
        puVar2 = puVar1;
      }
      else {
        (*(code *)puVar2[3])(puVar2[2]);
        puVar2 = puVar1;
      }
    }
    uVar3 = KeAcquireSpinLockRaiseToDpc(&DAT_1c001a9d0);
  } while ((undefined8 **)DAT_1c001a9c0 != &DAT_1c001a9c0);
  DAT_1c001aa18 = 0;
  KeSetEvent(&DAT_1c001a9d8,0,0);
  KeReleaseSpinLock(&DAT_1c001a9d0,uVar3);
  return;
}



===== TunnelTimeoutWorkItemRoutine @ 1c0005e40 =====

int TunnelTimeoutWorkItemRoutine(void)

{
  int iVar1;
  
  TunnelTimeoutTunnelSet((longlong *)&DAT_1c001a8b0);
  iVar1 = 1;
  LOCK();
  if (DAT_1c001a9f0 == 1) {
    DAT_1c001a9f0 = 0;
  }
  else {
    iVar1 = DAT_1c001a9f0;
  }
  UNLOCK();
  return iVar1;
}



===== TunnelUserSendNBLDpc @ 1c0005e70 =====

void TunnelUserSendNBLDpc(undefined8 param_1,longlong param_2)

{
  longlong *******ppppppplVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  longlong *******ppppppplVar5;
  undefined1 *puVar6;
  undefined8 *local_res10;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [40];
  longlong *******local_18;
  longlong *******local_10;
  
  local_res10 = (undefined8 *)0x0;
  local_10 = (longlong *******)&local_18;
  local_18 = (longlong *******)&local_18;
  KeAcquireSpinLockAtDpcLevel(param_2 + 0x118);
  *(uint *)(param_2 + 0x2c8) = *(uint *)(param_2 + 0x2c8) & 0xffffffbf;
  if ((*(uint *)(param_2 + 0x2c8) & 0x20) == 0) {
    iVar4 = TunnelServiceReadRequests(param_2,(longlong *)&local_res10);
  }
  else {
    iVar4 = TunnelUserServiceBatchedReadRequests
                      (param_2,&local_res10,(longlong ******)&local_18,'\0');
  }
  KeReleaseSpinLockFromDpcLevel(param_2 + 0x118);
  puVar6 = auStack_48;
  do {
    if ((longlong ********)local_18 == &local_18) {
LAB_1c0005f3b:
      if (local_res10 != (undefined8 *)0x0) {
        *(undefined4 *)(puVar6 + 0x28) = 0;
        *(undefined4 *)(puVar6 + 0x20) = 0;
        uVar2 = *(undefined8 *)(param_2 + 0x38);
        *(undefined8 *)(puVar6 + -8) = 0x1c0005f5c;
        TunnelUserRestoreAndFreeNblAndNbState
                  (local_res10,'\0','\x01',uVar2,*(undefined4 *)(puVar6 + 0x20),
                   *(undefined4 *)(puVar6 + 0x28));
      }
      if (iVar4 != 0) {
        *(undefined8 *)(puVar6 + -8) = 0x1c0005f6d;
        TunnelInterfaceDereferenceExImp(param_2,iVar4,(undefined *)0x0);
      }
      *(undefined8 *)(puVar6 + -8) = 0x1c0005f7c;
      TunnelInterfaceDereferenceExImp(param_2,1,(undefined *)0x0);
      return;
    }
    if (((longlong ********)local_18[1] != &local_18) ||
       (ppppppplVar1 = (longlong *******)*local_18, (longlong *******)ppppppplVar1[1] != local_18))
    {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      puVar6 = auStack_40;
      goto LAB_1c0005f3b;
    }
    ppppppplVar1[1] = (longlong ******)&local_18;
    ppppppplVar5 = local_18 + -0x15;
    local_18 = ppppppplVar1;
    IofCompleteRequest(ppppppplVar5);
  } while( true );
}



===== TunnelTimeoutTunnelSet @ 1c0005fa0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte TunnelTimeoutTunnelSet(longlong *param_1)

{
  longlong *plVar1;
  byte bVar2;
  ulonglong uVar3;
  byte bVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  code *pcVar7;
  undefined8 local_res8;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_res8 = 0;
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  bVar4 = 1;
  KeAcquireInStackQueuedSpinLock(param_1 + 3,&local_38);
  do {
  } while ((int)param_1[4] != 0);
  plVar5 = (longlong *)*param_1;
  if (plVar5 != param_1) {
    param_1[0xd] = *plVar5;
    local_res8 = _DAT_fffff78000000320;
    do {
      plVar1 = (longlong *)param_1[0xd];
      param_1[0xd] = *plVar1;
      pcVar7 = *(code **)(plVar5[4] + 0x60);
      if (pcVar7 != (code *)0x0) {
        uVar3 = RoReferenceEx((uint *)(plVar5 + 8),1);
        if ((char)uVar3 != '\0') {
          puVar6 = &local_38;
          bVar2 = (*pcVar7)(plVar5,&local_res8,puVar6);
          bVar4 = bVar4 & bVar2;
          TunnelInterfaceDereferenceExImp
                    ((longlong)plVar5,1,(undefined *)CONCAT71((int7)((ulonglong)puVar6 >> 8),1));
        }
      }
      plVar5 = plVar1;
    } while (plVar1 != param_1);
    param_1[0xd] = 0;
  }
  KeReleaseInStackQueuedSpinLock(&local_38);
  return bVar4;
}



===== TunnelInterfaceDereferenceExImp @ 1c00060a0 =====

void TunnelInterfaceDereferenceExImp(longlong param_1,int param_2,undefined *param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  byte bVar4;
  char cVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  cVar5 = (char)param_3;
  local_28 = 0;
  uStack_20 = 0;
  LOCK();
  piVar1 = (int *)(param_1 + 0x40);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + param_2 * -2;
  UNLOCK();
  if (iVar2 + param_2 * -2 == 1) {
    if (cVar5 == '\0') {
      RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10) + 0x18);
    }
    lVar3 = *(longlong *)(param_1 + 0x48);
    *(undefined8 *)(param_1 + 0x48) = 0;
    bVar4 = *(byte *)(param_1 + 0xb8) & 1;
    if (bVar4 != 0) {
      *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffe | 2;
    }
    if (cVar5 == '\0') {
      KeReleaseInStackQueuedSpinLock(&local_28);
    }
    if (bVar4 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
        param_3 = &WPP_9608820f130d35da1284a1080d801204_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(undefined4 *)(param_1 + 0x28));
      }
      if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
        McTemplateK0q_EtwWriteTransfer
                  (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_PAUSE_COMPLETE,
                   param_3,*(undefined4 *)(param_1 + 0x28));
      }
      NdisMPauseComplete(*(undefined8 *)(param_1 + 0x38));
    }
    if (lVar3 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
        param_3 = &WPP_9608820f130d35da1284a1080d801204_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(undefined4 *)(param_1 + 0x28));
      }
      if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
        McTemplateK0q_EtwWriteTransfer
                  (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_POWER_COMPLETE,
                   param_3,*(undefined4 *)(param_1 + 0x28));
      }
      TunnelPnpLogRequestCompletion(param_1);
      IofCompleteRequest(lVar3,0);
    }
  }
  return;
}



===== TunnelUserReceiveIndicationWorker @ 1c0006250 =====

void TunnelUserReceiveIndicationWorker(undefined8 param_1,longlong param_2,undefined *param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  int iVar4;
  undefined1 uVar5;
  int iVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  undefined8 uVar10;
  int local_res10 [4];
  uint local_res20 [2];
  int *piVar11;
  undefined4 uVar12;
  undefined8 *local_68;
  longlong local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  lVar2 = *(longlong *)(param_2 + 0x10);
  local_res10[0] = 0;
  lVar8 = lVar2 + 0x18;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_60 = lVar8;
  KeAcquireInStackQueuedSpinLock(lVar8,&local_58);
  do {
  } while (*(int *)(lVar2 + 0x20) != 0);
  lVar2 = param_2 + 0x118;
  uVar5 = KeAcquireSpinLockRaiseToDpc(lVar2);
  while( true ) {
    plVar3 = *(longlong **)(param_2 + 0x138);
    if (plVar3 == (longlong *)(param_2 + 0x138)) break;
    lVar9 = (longlong)(plVar3 + -0x15);
    TunnelUserDequeueWriteIrp(param_2,lVar9);
    if (lVar9 == 0) break;
    LOCK();
    lVar1 = plVar3[-8];
    plVar3[-8] = 0;
    UNLOCK();
    if (lVar1 == 0) {
      param_3 = (undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),1);
      TunnelInterfaceDereferenceExImp(param_2,1,param_3);
    }
    else {
      KeReleaseSpinLock(lVar2,uVar5);
      KeReleaseInStackQueuedSpinLock(&local_58);
      local_68 = (undefined8 *)0x0;
      piVar11 = local_res10;
      local_res20[0] = 0;
      iVar6 = TunnelUserAllocateNblsForIrp(param_2,lVar9,local_res20,&local_68,piVar11);
      uVar12 = (undefined4)((ulonglong)piVar11 >> 0x20);
      RtlAcquireWriteLock(lVar8);
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar2);
      iVar4 = local_res10[0];
      if ((iVar6 < 0) || (local_res10[0] == 0)) {
LAB_1c00063d0:
        iVar6 = -0x3ffffe7c;
        KeReleaseSpinLock(lVar2,uVar5);
        KeReleaseInStackQueuedSpinLock(&local_58);
        uVar10 = 0;
        TunnelUserRestoreAndFreeNblAndNbState(local_68,'\x01','\0',0,0,0);
      }
      else {
        uVar7 = RoReferenceEx((uint *)(param_2 + 0x40),local_res10[0]);
        if ((char)uVar7 == '\0') goto LAB_1c00063d0;
        KeReleaseSpinLock(lVar2,uVar5);
        KeReleaseInStackQueuedSpinLock(&local_58);
        uVar10 = 0;
        NdisMIndicateReceiveNetBufferLists
                  (*(undefined8 *)(param_2 + 0x38),local_68,0,iVar4,CONCAT44(uVar12,0x100));
      }
      uVar7 = (ulonglong)local_res20[0];
      plVar3[-0xe] = uVar7;
      *(int *)(plVar3 + -0xf) = iVar6;
      IofCompleteRequest(lVar9,0);
      RtlAcquireWriteLock(*(longlong *)(param_2 + 0x10) + 0x18);
      uVar5 = KeAcquireSpinLockRaiseToDpc(lVar2);
      *(longlong *)(param_2 + 0x90) = *(longlong *)(param_2 + 0x90) + uVar7;
      param_3 = (undefined *)CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
      TunnelInterfaceDereferenceExImp(param_2,1,param_3);
      *(int *)(param_2 + 0x74) = *(int *)(param_2 + 0x74) + iVar4;
      lVar8 = local_60;
    }
  }
  *(uint *)(param_2 + 0x2c8) = *(uint *)(param_2 + 0x2c8) & 0xffffff7f;
  KeReleaseSpinLock(lVar2,uVar5);
  TunnelInterfaceDereferenceExImp
            (param_2,1,(undefined *)CONCAT71((int7)((ulonglong)param_3 >> 8),1));
  KeReleaseInStackQueuedSpinLock(&local_58);
  return;
}



===== TeredoWfpAleLayerClassify @ 1c00064d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TeredoWfpAleLayerClassify
               (longlong param_1,longlong param_2,longlong param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6)

{
  int iVar1;
  longlong lVar2;
  short sVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  uint uVar7;
  int iVar8;
  longlong lVar9;
  undefined1 auStack_98 [32];
  undefined8 *local_78;
  undefined8 *local_70;
  char local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_98;
  local_50 = 0;
  uStack_48 = 0;
  local_60 = 0;
  uStack_58 = 0;
  iVar1 = *(int *)(*(longlong *)(param_1 + 8) + 200);
  plVar6 = (longlong *)0x0;
  LOCK();
  _TwOffloadCounters = _TwOffloadCounters + 1;
  UNLOCK();
  if (param_3 == 0) goto LAB_1c0006523;
  lVar2 = *(longlong *)(param_1 + 8);
  if (*(int *)(lVar2 + 0x58) != 0x11) {
    LOCK();
    _DAT_1c00173b8 = _DAT_1c00173b8 + 1;
    UNLOCK();
    goto LAB_1c0006523;
  }
  if ((*(short *)(lVar2 + 0x48) == DAT_1c001a024) &&
     (*(int *)(lVar2 + 0x28) == TwKernelOffloadV4FlowParams)) {
LAB_1c00067fb:
    plVar6 = TeredoWfpNewFlowV4Flow(param_1,param_2,1);
  }
  else {
    lVar2 = *(longlong *)(param_3 + 8);
    iVar8 = -0x3fffffff;
    local_68 = '\0';
    if (iVar1 == 1) {
LAB_1c00065a5:
      if ((*(int *)(lVar2 + 0x18) == 0) || (lVar9 = *(longlong *)(lVar2 + 8), lVar9 == 0)) {
LAB_1c00065ee:
        lVar9 = 0;
      }
      else {
        if ((*(byte *)(lVar9 + 10) & 5) == 0) {
          local_70 = (undefined8 *)CONCAT44(local_70._4_4_,0x40000010);
          local_78 = (undefined8 *)((ulonglong)local_78 & 0xffffffff00000000);
          lVar5 = MmMapLockedPagesSpecifyCache(lVar9,0,1);
        }
        else {
          lVar5 = *(longlong *)(lVar9 + 0x18);
        }
        if (lVar5 == 0) goto LAB_1c00065ee;
        uVar7 = *(uint *)(lVar2 + 0x10);
        if (((*(uint *)(lVar9 + 0x28) <= uVar7) || (*(uint *)(lVar9 + 0x28) - uVar7 < 0x28)) ||
           (lVar9 = lVar5 + (ulonglong)uVar7,
           ((byte)*(undefined4 *)(lVar5 + (ulonglong)uVar7) & 0xf0) != 0x60)) goto LAB_1c00065ee;
        iVar8 = 0;
      }
      if (local_68 != '\0') {
        if (*(uint *)(lVar2 + 0x10) < 8) {
          NdisRetreatNetBufferDataStart(lVar2,8,0,NetioAllocateMdl_exref);
        }
        else {
          *(int *)(lVar2 + 0x28) = *(int *)(lVar2 + 0x28) + -8;
          *(int *)(lVar2 + 0x18) = *(int *)(lVar2 + 0x18) + 8;
          *(uint *)(lVar2 + 0x10) = *(uint *)(lVar2 + 0x10) - 8;
        }
      }
      if (-1 < iVar8) {
        if (iVar1 == 1) {
          local_60 = *(undefined8 *)(lVar9 + 8);
          uStack_58 = *(undefined8 *)(lVar9 + 0x10);
          local_50 = *(undefined8 *)(lVar9 + 0x18);
          uStack_48 = *(undefined8 *)(lVar9 + 0x20);
        }
        else {
          local_50 = *(undefined8 *)(lVar9 + 8);
          uStack_48 = *(undefined8 *)(lVar9 + 0x10);
          local_60 = *(undefined8 *)(lVar9 + 0x18);
          uStack_58 = *(undefined8 *)(lVar9 + 0x20);
        }
        sVar3 = (short)((ulonglong)local_50 >> 0x10);
        if ((((short)local_50 != 0x120) || (sVar3 != 0)) &&
           (((short)local_50 != -0x1c1 || (sVar3 != 0x1f83)))) {
          sVar3 = (short)((ulonglong)local_60 >> 0x10);
          if ((((short)local_60 != 0x120) || (sVar3 != 0)) &&
             (((short)local_60 != -0x1c1 || (sVar3 != 0x1f83)))) {
            if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
              local_70 = &local_60;
              local_78 = &local_50;
              McTemplateK0qbr0br0_EtwWriteTransfer(&MS_TUNNEL_DRIVER_PROVIDER_ID_Context);
            }
            LOCK();
            _DAT_1c00173c8 = _DAT_1c00173c8 + 1;
            UNLOCK();
            goto LAB_1c0006523;
          }
        }
        goto LAB_1c00067fb;
      }
    }
    else if (7 < *(uint *)(lVar2 + 0x18)) {
      uVar7 = *(int *)(lVar2 + 0x10) + 8;
      if (uVar7 < *(uint *)(*(longlong *)(lVar2 + 8) + 0x28)) {
        *(int *)(lVar2 + 0x28) = *(int *)(lVar2 + 0x28) + 8;
        *(uint *)(lVar2 + 0x18) = *(uint *)(lVar2 + 0x18) - 8;
        *(uint *)(lVar2 + 0x10) = uVar7;
        local_68 = '\x01';
      }
      else {
        NdisAdvanceNetBufferDataStart(lVar2,8,0);
        local_68 = '\x01';
      }
      goto LAB_1c00065a5;
    }
    LOCK();
    _DAT_1c00173c0 = _DAT_1c00173c0 + 1;
    UNLOCK();
  }
LAB_1c0006523:
  *param_6 = 0x1002;
  plVar4 = &DAT_1c00173f0;
  if (plVar6 != (longlong *)0x0) {
    plVar4 = &DAT_1c00173e8;
  }
  LOCK();
  *plVar4 = *plVar4 + 1;
  UNLOCK();
  return;
}



===== TunnelMiniportOidRequest @ 1c0006820 =====

int TunnelMiniportOidRequest(longlong param_1,longlong param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  void *pvVar4;
  
  uVar1 = *(uint *)(param_2 + 4);
  if ((uVar1 & 0xfffffffd) == 0) {
    pvVar4 = *(void **)(param_2 + 0x28);
    iVar2 = TunnelQueryInformation
                      (param_1,*(uint *)(param_2 + 0x20),pvVar4,*(uint *)(param_2 + 0x30),
                       (uint *)(param_2 + 0x34),(uint *)(param_2 + 0x38));
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
      return iVar2;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) == 0) {
      return iVar2;
    }
    uVar3 = 0x22;
  }
  else {
    if (uVar1 != 1) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return -0x3fffff45;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
        return -0x3fffff45;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) == 0) {
        return -0x3fffff45;
      }
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,param_3,uVar1,
                (char)*(undefined4 *)(param_1 + 0x28));
      return -0x3fffff45;
    }
    pvVar4 = (void *)(ulonglong)*(uint *)(param_2 + 0x20);
    iVar2 = TunnelSetInformation
                      (param_1,param_2 + 0x34,*(uint *)(param_2 + 0x20),*(uint **)(param_2 + 0x28),
                       *(uint *)(param_2 + 0x30),(uint *)(param_2 + 0x34),
                       (undefined4 *)(param_2 + 0x38));
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return iVar2;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
      return iVar2;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) == 0) {
      return iVar2;
    }
    uVar3 = 0x23;
  }
  WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,pvVar4,*(undefined4 *)(param_2 + 4),
             (char)*(undefined4 *)(param_1 + 0x28),(char)iVar2);
  return iVar2;
}



===== TunnelQueryInformation @ 1c0006970 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int TunnelQueryInformation
              (longlong param_1,uint param_2,void *param_3,uint param_4,uint *param_5,uint *param_6)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  undefined1 auStack_158 [32];
  undefined4 local_128;
  char local_124 [4];
  uint local_120 [2];
  uint *local_118;
  void *local_110;
  char local_108 [16];
  ulonglong local_f8;
  undefined8 local_f0;
  ulonglong local_e8;
  undefined8 local_d0;
  ulonglong local_c8;
  ulonglong local_b0;
  char local_68 [32];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_158;
  local_118 = param_5;
  local_128 = 0;
  local_124[0] = '\0';
  local_124[1] = '\0';
  iVar1 = 0;
  local_110 = param_3;
  memset(local_108,0,0x98);
  *param_5 = 0;
  local_120[0] = 0;
  uVar2 = 4;
  *param_6 = 0;
  pcVar3 = (char *)&local_128;
  local_68[0] = '\0';
  local_68[1] = '\0';
  local_68[2] = '\0';
  local_68[3] = '\0';
  local_68[4] = '\0';
  local_68[5] = '\0';
  local_68[6] = '\0';
  local_68[7] = '\0';
  local_68[8] = '\0';
  local_68[9] = '\0';
  local_68[10] = '\0';
  local_68[0xb] = '\0';
  local_68[0xc] = '\0';
  local_68[0xd] = '\0';
  local_68[0xe] = '\0';
  local_68[0xf] = '\0';
  local_68[0x10] = '\0';
  local_68[0x11] = '\0';
  local_68[0x12] = '\0';
  local_68[0x13] = '\0';
  local_68[0x14] = '\0';
  local_68[0x15] = '\0';
  local_68[0x16] = '\0';
  local_68[0x17] = '\0';
  local_68[0x18] = '\0';
  local_68[0x19] = '\0';
  local_68[0x1a] = '\0';
  local_68[0x1b] = '\0';
  local_68[0x1c] = '\0';
  local_68[0x1d] = '\0';
  local_68[0x1e] = '\0';
  local_68[0x1f] = '\0';
  if (param_2 == 0x20106) {
    local_f0 = *(undefined8 *)(param_1 + 0x90);
    pcVar3 = local_108;
    uVar2 = 0x98;
    local_d0 = *(undefined8 *)(param_1 + 0x88);
    local_e8 = (ulonglong)*(uint *)(param_1 + 0x74);
    local_c8 = (ulonglong)*(uint *)(param_1 + 0x70);
    local_f8 = (ulonglong)*(uint *)(param_1 + 0x7c);
    local_b0 = (ulonglong)*(uint *)(param_1 + 0x78);
    local_108[0] = -0x80;
    local_108[1] = '\x01';
    local_108[2] = -0x68;
    local_108[3] = '\0';
    local_108[4] = '\b';
    local_108[5] = '\x02';
    local_108[6] = '\0';
    local_108[7] = '\0';
  }
  else if (param_2 < 0x20102) {
    if (param_2 == 0x20101) {
      pcVar3 = (char *)(param_1 + 0x70);
    }
    else {
      switch(param_2) {
      case 0x10101:
        pcVar3 = "\x01\x01\x01";
        uVar2 = 0x88;
        break;
      case 0x10102:
        break;
      case 0x10103:
        pcVar3 = "\x0f";
        break;
      case 0x10104:
        local_128 = 0xf;
        break;
      case 0x10105:
      case 0x10108:
      case 0x10109:
      case 0x10111:
        local_128 = 0x10000;
        break;
      case 0x10106:
        local_128 = *(undefined4 *)(param_1 + 0x58);
        break;
      case 0x10107:
        pcVar3 = (char *)(param_1 + 0x68);
        uVar2 = 8;
        break;
      case 0x1010a:
      case 0x1010b:
        local_128 = 1;
        break;
      case 0x1010c:
        pcVar3 = &DAT_1c0014a08;
        uVar2 = 3;
        break;
      case 0x1010d:
        pcVar3 = "Microsoft Tunnel Interface Driver";
        uVar2 = 0x22;
        break;
      case 0x1010e:
        local_128 = *(undefined4 *)(param_1 + 0x60);
        break;
      case 0x1010f:
        local_128 = *(undefined4 *)(param_1 + 0x5c);
        break;
      case 0x10110:
        pcVar3 = local_124;
        local_124[0] = 'Q';
        local_124[1] = '\x06';
        uVar2 = 2;
        break;
      default:
        return -0x3fffff45;
      case 0x10113:
        local_128 = 8;
        break;
      case 0x10114:
        local_128 = (**(code **)(*(longlong *)(param_1 + 0x20) + 0x40))(param_1);
        break;
      case 0x10115:
        local_128 = 0x100;
      }
    }
  }
  else if (param_2 < 0xf010102) {
    if (param_2 != 0xf010101) {
      if (param_2 == 0x20102) {
        pcVar3 = (char *)(param_1 + 0x74);
        goto switchD_1c0006ba3_caseD_10102;
      }
      if (param_2 == 0x20103) {
        pcVar3 = (char *)(param_1 + 0x78);
        goto switchD_1c0006ba3_caseD_10102;
      }
      if (param_2 == 0x20104) {
        pcVar3 = (char *)(param_1 + 0x7c);
        goto switchD_1c0006ba3_caseD_10102;
      }
      if (param_2 == 0x20105) {
        pcVar3 = (char *)(param_1 + 0x80);
        goto switchD_1c0006ba3_caseD_10102;
      }
      if (param_2 != 0x1010102) {
        return -0x3fffff45;
      }
    }
    pcVar3 = local_68;
    iVar1 = (*(code *)**(undefined8 **)(param_1 + 0x20))(param_1,0x20,pcVar3,local_120);
    if (iVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,pcVar3,
                  *(undefined4 *)(param_1 + 0x28),(char)iVar1);
      }
      uVar2 = 0;
    }
    else {
      uVar2 = local_120[0];
    }
    pcVar3 = local_68;
  }
  else if (param_2 == 0xf010102) {
    pcVar3 = (char *)(param_1 + 0xdc);
    uVar2 = *(int *)(param_1 + 0xfc) + 8;
  }
  else {
    if (param_2 != 0xf010104) {
      if (param_2 == 0xfd010102) {
        *local_118 = 0;
        return 0;
      }
      return -0x3fffff45;
    }
    pcVar3 = (char *)(param_1 + 0x18);
  }
switchD_1c0006ba3_caseD_10102:
  *param_6 = uVar2;
  if (param_4 < uVar2) {
    iVar1 = -0x3ffeffea;
  }
  else {
    *local_118 = uVar2;
    if (uVar2 != 0) {
      memcpy(local_110,pcVar3,(ulonglong)uVar2);
    }
  }
  return iVar1;
}



===== TunnelSetInformation @ 1c0006d28 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
TunnelSetInformation
          (longlong param_1,undefined8 param_2,int param_3,uint *param_4,uint param_5,uint *param_6,
          undefined4 *param_7)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  *param_6 = 0;
  *param_7 = 0;
  if (param_3 == -0x2fefeff) {
    return 0;
  }
  if (param_3 == 0x1010e) {
    if (param_5 == 4) {
      uVar2 = *param_4;
      *param_6 = 4;
      *(uint *)(param_1 + 0x60) = uVar2;
      return 0;
    }
  }
  else if (param_3 == 0x1010f) {
    if (param_5 == 4) {
      uVar2 = *param_4;
      if (0x10000 < uVar2) {
        return 0xc0010014;
      }
      if (uVar2 < *(uint *)(param_1 + 0x5c)) {
        return 0;
      }
      *(uint *)(param_1 + 0x5c) = uVar2;
      *param_6 = 4;
      return 0;
    }
  }
  else {
    if ((param_3 == 0x1010102) || (param_3 == 0xf010101)) {
      uVar1 = (**(code **)(*(longlong *)(param_1 + 0x20) + 0x58))(0,param_4,param_5,param_6);
      return uVar1;
    }
    if (param_3 == 0xf010102) {
      uVar2 = *(int *)(param_1 + 0xfc) + 8;
      if (param_5 == uVar2) {
        memcpy((void *)(param_1 + 0xdc),param_4,(ulonglong)uVar2);
        *param_6 = uVar2;
        return 0;
      }
    }
    else if (param_3 == 0xf010106) {
      if (param_5 == 0x14) {
        RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10) + 0x18);
        if ((char)param_4[3] == '\0') {
          TunnelInsertPhysicalInterfaceAssociationForTunnel(param_1,param_4,'\x01');
        }
        else {
          TunnelRemovePhysicalInterfaceAssociationForTunnel(param_1,param_4[1],param_4[2]);
        }
        goto LAB_1c0006e5d;
      }
    }
    else {
      if (param_3 != 0xf010117) {
        return 0xc00000bb;
      }
      if (((param_5 & 0xfffffffb) == 0) && (*(int *)(param_1 + 0x18) == 0xd)) {
        RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10) + 0x18);
        if (param_4 == (uint *)0x0) {
          TunnelRemoveAllPotentialRoutersForTunnel(param_1);
        }
        else {
          TunnelInsertPotentialRouterForTunnel(param_1,(int *)param_4);
        }
LAB_1c0006e5d:
        KeReleaseInStackQueuedSpinLock(&local_28);
        return 0;
      }
    }
  }
  return 0xc0010015;
}



===== TeredoWfpLocateOrCreateV4Flow @ 1c0006f30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
TeredoWfpLocateOrCreateV4Flow
          (int param_1,uint param_2,short param_3,ushort param_4,char param_5,undefined8 *param_6)

{
  undefined1 uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  undefined8 uVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  ulonglong *puVar9;
  ulonglong *puVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  ulonglong *puVar13;
  bool bVar14;
  undefined1 auStack_88 [32];
  ushort local_68;
  short local_66;
  undefined4 local_60;
  uint local_5c;
  short local_58;
  ushort local_56;
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStack_88;
  puVar13 = (ulonglong *)0x0;
  uVar12 = 0;
  local_68 = param_4;
  local_66 = param_3;
  uVar2 = RoReferenceEx(&DAT_1c001a120,1);
  if ((char)uVar2 == '\0') {
    *param_6 = 0;
  }
  else {
    uVar6 = 0;
    local_56 = param_4;
    uVar8 = 0;
    local_60 = param_1;
    local_5c = param_2;
    local_58 = param_3;
    pbVar7 = (byte *)((longlong)&local_60 + 1);
    do {
      uVar8 = uVar8 + 0xc;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[-1] * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)*pbVar7 * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[1] * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[2] * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[3] * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[4] * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[5] * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[6] * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[7] * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[8] * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[9] * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[10] * 4) ^ uVar6 * 2;
      pbVar7 = pbVar7 + 0xc;
    } while (uVar8 < 0xc);
    uVar8 = 0;
    pbVar7 = &DAT_1c0017341;
    do {
      uVar8 = uVar8 + 8;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[-1] * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)*pbVar7 * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[1] * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[2] * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[3] * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[4] * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[5] * 4) ^ uVar6 * 2;
      uVar6 = uVar6 >> 0x1f ^ *(uint *)(&DAT_1c0013910 + (ulonglong)pbVar7[6] * 4) ^ uVar6 * 2;
      pbVar7 = pbVar7 + 8;
    } while (uVar8 < 8);
    uVar2 = (ulonglong)(uVar6 % 0x407) * 0x20 + DAT_1c0017360;
    uVar1 = KeAcquireSpinLockRaiseToDpc(uVar2);
    puVar10 = (ulonglong *)(uVar2 + 0x10);
    *param_6 = 0;
    puVar9 = (ulonglong *)*puVar10;
    if (puVar9 != puVar10) {
      uVar11 = (ulonglong)local_68;
      do {
        puVar13 = puVar9;
        puVar9 = puVar13;
        if (((((*(int *)((longlong)puVar13 + 0x24) == 1) &&
              (param_1 == *(int *)((longlong)puVar13 + 0x5c))) && (param_2 == (uint)puVar13[0xc]))
            && ((param_3 == *(short *)((longlong)puVar13 + 100) &&
                ((short)uVar11 == *(short *)((longlong)puVar13 + 0x66))))) &&
           ((*(char *)((longlong)puVar13 + 0x8c) != '\0' &&
            (uVar3 = RoReferenceEx((uint *)((longlong)puVar13 + 0x1c),1), (char)uVar3 != '\0'))))
        break;
        puVar9 = (ulonglong *)*puVar9;
      } while (puVar9 != puVar10);
    }
    puVar4 = (ulonglong *)0x0;
    if (puVar9 != puVar10) {
      puVar4 = puVar13;
    }
    if (((puVar4 == (ulonglong *)0x0) && (param_5 != '\0')) &&
       (((DAT_1c001a120 & 1) == 0 &&
        (puVar4 = (ulonglong *)ExAllocatePool2(0x40,0xe0,0x70667754), puVar4 != (ulonglong *)0x0))))
    {
      KeInitializeSpinLock(puVar4 + 2);
      *(uint *)((longlong)puVar4 + 0x1c) = 2;
      *(undefined4 *)(puVar4 + 3) = 0x43667754;
      *(undefined4 *)((longlong)puVar4 + 0x24) = 1;
      RoReferenceEx((uint *)((longlong)puVar4 + 0x1c),1);
      *(short *)((longlong)puVar4 + 100) = local_66;
      *(uint *)(puVar4 + 0xc) = param_2;
      *(ushort *)((longlong)puVar4 + 0x66) = local_68;
      *(int *)((longlong)puVar4 + 0x5c) = param_1;
      *(uint *)(puVar4 + 0x11) =
           param_2 >> 0x18 | (param_2 & 0xff0000) >> 8 | (param_2 & 0xff00) << 8 | param_2 << 0x18;
      uVar5 = TeredoWfpInsertHashEntryInLockedBucket(puVar4,uVar2);
      if ((char)uVar5 == '\0') {
        ExFreePoolWithTag(puVar4,0x70667754);
        puVar4 = (ulonglong *)0x0;
      }
      else {
        LOCK();
        DAT_1c0017400 = DAT_1c0017400 + 1;
        UNLOCK();
        uVar12 = 1;
      }
    }
    KeReleaseSpinLock(uVar2,uVar1);
    LOCK();
    uVar6 = DAT_1c001a120 - 2;
    UNLOCK();
    bVar14 = DAT_1c001a120 == 3;
    DAT_1c001a120 = uVar6;
    if (bVar14) {
      KeSetEvent(&HashTableUninitializedEvent,0,0);
    }
    *param_6 = puVar4;
  }
  return uVar12;
}



===== TeredoWfpInsertHashEntryInLockedBucket @ 1c0007378 =====

ulonglong TeredoWfpInsertHashEntryInLockedBucket(ulonglong *param_1,ulonglong param_2)

{
  code *pcVar1;
  ulonglong in_RAX;
  ulonglong *puVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (DAT_1c0017360 != 0) {
    iVar5 = 1;
    in_RAX = RoReferenceEx(&DAT_1c001a120,1);
    puVar6 = auStack_28;
    if ((char)in_RAX != '\0') {
      puVar2 = (ulonglong *)(param_2 + 0x10);
      uVar4 = *puVar2;
      if (*(ulonglong **)(uVar4 + 8) != puVar2) {
        uVar4 = (ulonglong)(iVar5 + 2);
        pcVar1 = (code *)swi(0x29);
        puVar2 = (ulonglong *)(*pcVar1)();
        puVar6 = auStack_20;
      }
      *param_1 = uVar4;
      param_1[1] = (ulonglong)puVar2;
      *(ulonglong **)(uVar4 + 8) = param_1;
      *puVar2 = (ulonglong)param_1;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
      *(undefined8 *)(puVar6 + -8) = 0x1c00073d8;
      uVar3 = KeResetEvent(&HashTableUninitializedEvent);
      *(undefined1 *)((longlong)param_1 + 0x8f) = 1;
      param_1[5] = param_2;
      return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== TunnelUserRestoreAndFreeNblAndNbState @ 1c0007400 =====

int TunnelUserRestoreAndFreeNblAndNbState
              (undefined8 *param_1,char param_2,char param_3,undefined8 param_4,undefined4 param_5,
              undefined4 param_6)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar3 = param_1;
  while (puVar3 != (undefined8 *)0x0) {
    if (puVar3[0xd] == 0x43667754) {
      puVar1 = (undefined8 *)*puVar3;
      uVar2 = puVar3[0xc];
      *puVar3 = 0;
      puVar3[0xc] = 0;
      puVar3[0xd] = 0;
      FwpsFreeCloneNetBufferList0(puVar3,0);
      FwpsDereferenceNetBufferList0(uVar2);
      puVar3 = puVar1;
    }
    else {
      puVar1 = (undefined8 *)puVar3[0xc];
      puVar3[1] = puVar1;
      for (; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)*puVar1) {
        puVar1[1] = puVar1[0x10];
        *(undefined4 *)(puVar1 + 2) = *(undefined4 *)(puVar1 + 0x11);
        *(undefined4 *)(puVar1 + 5) = *(undefined4 *)((longlong)puVar1 + 0x8c);
      }
      puVar1 = (undefined8 *)*puVar3;
      if (param_2 == '\0') {
        if (param_3 != '\0') {
          *(undefined4 *)((longlong)puVar3 + 0x8c) = param_6;
        }
      }
      else {
        *puVar3 = 0;
        NdisFreeNetBufferList(puVar3);
      }
      iVar4 = iVar4 + 1;
      puVar3 = puVar1;
    }
  }
  if (param_3 != '\0') {
    NdisMSendNetBufferListsComplete(param_4,param_1,param_5);
  }
  return iVar4;
}



===== LwWorker @ 1c0007550 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void LwWorker(undefined8 param_1,undefined8 *param_2)

{
  char cVar1;
  longlong lVar2;
  
  cVar1 = KeAcquireSpinLockRaiseToDpc(param_2 + 3);
  lVar2 = *(longlong *)*param_2;
  *(longlong *)*param_2 = 0;
  param_2[10] = param_2[10] + 1;
  param_2[1] = *param_2;
  if (lVar2 == 0) {
    *(undefined1 *)(param_2 + 4) = 0;
  }
  if (cVar1 == '\x02') {
    KeReleaseSpinLockFromDpcLevel(param_2 + 3);
  }
  else {
    KeReleaseSpinLock(param_2 + 3,cVar1);
  }
  while (lVar2 != 0) {
    (*(code *)param_2[6])(param_1,lVar2);
    lVar2 = LwDequeueAll(param_2);
  }
  return;
}



===== LwDequeueAll @ 1c0007600 =====

longlong LwDequeueAll(undefined8 *param_1)

{
  longlong lVar1;
  char cVar2;
  
  cVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 3);
  lVar1 = *(longlong *)*param_1;
  *(longlong *)*param_1 = 0;
  param_1[10] = param_1[10] + 1;
  param_1[1] = *param_1;
  if (lVar1 == 0) {
    *(undefined1 *)(param_1 + 4) = 0;
  }
  if (cVar2 == '\x02') {
    KeReleaseSpinLockFromDpcLevel(param_1 + 3);
    return lVar1;
  }
  KeReleaseSpinLock(param_1 + 3,cVar2);
  return lVar1;
}



===== TunnelUserReturnNetBufferLists @ 1c00076a0 =====

void TunnelUserReturnNetBufferLists(longlong param_1,undefined8 *param_2,undefined *param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  int iVar6;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  iVar6 = 0;
  while (param_2 != (undefined8 *)0x0) {
    puVar3 = (undefined8 *)param_2[0xc];
    if (param_2[0xd] == 0x43667754) {
      puVar4 = (undefined8 *)*param_2;
      *param_2 = 0;
      param_2[0xc] = 0;
      param_2[0xd] = 0;
      FwpsFreeCloneNetBufferList0(param_2,0);
      FwpsDereferenceNetBufferList0(puVar3);
      param_2 = puVar4;
    }
    else {
      param_2[1] = puVar3;
      for (; puVar3 != (undefined8 *)0x0; puVar3 = (undefined8 *)*puVar3) {
        puVar3[1] = puVar3[0x10];
        *(undefined4 *)(puVar3 + 2) = *(undefined4 *)(puVar3 + 0x11);
        *(undefined4 *)(puVar3 + 5) = *(undefined4 *)((longlong)puVar3 + 0x8c);
      }
      puVar3 = (undefined8 *)*param_2;
      *param_2 = 0;
      NdisFreeNetBufferList(param_2);
      iVar6 = iVar6 + 1;
      param_2 = puVar3;
    }
  }
  local_28 = 0;
  local_38 = 0;
  uStack_30 = 0;
  LOCK();
  piVar1 = (int *)(param_1 + 0x40);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + iVar6 * -2;
  UNLOCK();
  if (iVar2 + iVar6 * -2 == 1) {
    RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10) + 0x18);
    lVar5 = *(longlong *)(param_1 + 0x48);
    *(undefined8 *)(param_1 + 0x48) = 0;
    if ((*(byte *)(param_1 + 0xb8) & 1) == 0) {
      KeReleaseInStackQueuedSpinLock(&local_38);
    }
    else {
      *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffe | 2;
      KeReleaseInStackQueuedSpinLock();
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
        param_3 = &WPP_9608820f130d35da1284a1080d801204_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(undefined4 *)(param_1 + 0x28));
      }
      if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
        McTemplateK0q_EtwWriteTransfer
                  (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_PAUSE_COMPLETE,
                   param_3,*(undefined4 *)(param_1 + 0x28));
      }
      NdisMPauseComplete(*(undefined8 *)(param_1 + 0x38));
    }
    if (lVar5 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
        param_3 = &WPP_9608820f130d35da1284a1080d801204_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(undefined4 *)(param_1 + 0x28));
      }
      if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
        McTemplateK0q_EtwWriteTransfer
                  (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_POWER_COMPLETE,
                   param_3,*(undefined4 *)(param_1 + 0x28));
      }
      TunnelPnpLogRequestCompletion(param_1);
      IofCompleteRequest(lVar5,0);
    }
  }
  return;
}



===== TeredoWfpIndicationWorker @ 1c00078f0 =====

void TeredoWfpIndicationWorker(undefined8 param_1,longlong *param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  int iVar6;
  undefined *puVar7;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (param_2 == (longlong *)0x0) {
    if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
      McTemplateK0_EtwWriteTransfer
                (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_TEREDO_WFP_CLONE_LIST_NULL,
                 param_3);
    }
  }
  else {
    iVar6 = 0;
    plVar5 = param_2;
    do {
      plVar5[0x19] = 0xdd86;
      iVar6 = iVar6 + 1;
      plVar5 = (longlong *)*plVar5;
    } while (plVar5 != (longlong *)0x0);
    puVar7 = (undefined *)0x0;
    NdisMIndicateReceiveNetBufferLists(*(undefined8 *)(DAT_1c001a0c0 + 0x38),param_2,0,iVar6,0x100);
    lVar4 = DAT_1c001a0c0;
    local_18 = 0;
    local_28 = 0;
    uStack_20 = 0;
    LOCK();
    piVar1 = (int *)(DAT_1c001a0c0 + 0x40);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + iVar6 * -2;
    UNLOCK();
    if (iVar2 + iVar6 * -2 == 1) {
      RtlAcquireWriteLock(*(longlong *)(lVar4 + 0x10) + 0x18);
      lVar3 = *(longlong *)(lVar4 + 0x48);
      *(undefined8 *)(lVar4 + 0x48) = 0;
      if ((*(byte *)(lVar4 + 0xb8) & 1) == 0) {
        KeReleaseInStackQueuedSpinLock(&local_28);
      }
      else {
        *(uint *)(lVar4 + 0xb8) = *(uint *)(lVar4 + 0xb8) & 0xfffffffe | 2;
        KeReleaseInStackQueuedSpinLock();
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
          puVar7 = &WPP_9608820f130d35da1284a1080d801204_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                   &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(undefined4 *)(lVar4 + 0x28));
        }
        if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
          McTemplateK0q_EtwWriteTransfer
                    (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_PAUSE_COMPLETE,
                     puVar7,*(undefined4 *)(lVar4 + 0x28));
        }
        NdisMPauseComplete(*(undefined8 *)(lVar4 + 0x38));
      }
      if (lVar3 != 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
          puVar7 = &WPP_9608820f130d35da1284a1080d801204_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                   &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(undefined4 *)(lVar4 + 0x28));
        }
        if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
          McTemplateK0q_EtwWriteTransfer
                    (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_POWER_COMPLETE,
                     puVar7,*(undefined4 *)(lVar4 + 0x28));
        }
        TunnelPnpLogRequestCompletion(lVar4);
        IofCompleteRequest(lVar3,0);
      }
    }
  }
  return;
}



===== TeredoWfpInjectComplete @ 1c0007b10 =====

void TeredoWfpInjectComplete(longlong param_1,longlong param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined1 uVar6;
  longlong *plVar7;
  undefined8 uVar8;
  
  plVar3 = *(longlong **)(param_1 + 0x68);
  puVar4 = *(undefined8 **)(param_1 + 8);
  *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_2 + 0x8c);
  puVar5 = *(undefined8 **)(param_2 + 8);
  for (; (puVar5 != (undefined8 *)0x0 && (puVar4[0x10] != 0)); puVar4 = (undefined8 *)*puVar4) {
    if ((*(byte *)(puVar5[1] + 10) & 5) == 0) {
      MmMapLockedPagesSpecifyCache(puVar5[1],0,1,0,0,0x40000000);
    }
    ExFreeToNPagedLookasideList(&TwUdpHeaderPool);
    puVar5[1] = puVar4[0x10];
    puVar5[4] = puVar4[0x11];
    *(undefined4 *)(puVar5 + 2) = *(undefined4 *)(puVar4 + 0x12);
    *(undefined4 *)(puVar5 + 5) = *(undefined4 *)(puVar4 + 0x13);
    *(undefined4 *)(puVar5 + 3) = *(undefined4 *)(puVar4 + 3);
    puVar5 = (undefined8 *)*puVar5;
  }
  FwpsFreeCloneNetBufferList0(param_2,0);
  if (param_3 == '\0') {
    uVar6 = KfRaiseIrql(2);
    uVar8 = 1;
    NdisMSendNetBufferListsComplete(*(undefined8 *)(DAT_1c001a0c0 + 0x38),param_1);
    KeLowerIrql(uVar6);
  }
  else {
    uVar8 = 1;
    NdisMSendNetBufferListsComplete(*(undefined8 *)(DAT_1c001a0c0 + 0x38),param_1);
  }
  LOCK();
  piVar1 = (int *)((longlong)plVar3 + 0x1c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -2;
  UNLOCK();
  if (iVar2 == 3) {
    TeredoWfpRemoveHashEntry(plVar3);
    if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
      McTemplateK0q_EtwWriteTransfer
                (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_TEREDO_FLOW_FREED,uVar8,
                 *(undefined4 *)((longlong)plVar3 + 0x24));
    }
    if (plVar3[9] != 0) {
      ExFreePoolWithTag(plVar3[9],0x64437754);
    }
    plVar7 = &DAT_1c0017408;
    if (*(int *)((longlong)plVar3 + 0x24) != 2) {
      plVar7 = &DAT_1c0017400;
    }
    LOCK();
    *plVar7 = *plVar7 + -1;
    UNLOCK();
    ExFreePoolWithTag(plVar3,0x70667754);
  }
  return;
}



===== TeredoWfpInjectionWorker @ 1c0007d20 =====

void TeredoWfpInjectionWorker(undefined8 param_1,undefined8 *param_2,undefined *param_3)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  int iVar5;
  int iVar6;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  longlong local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  
  iVar6 = 0;
  lVar3 = DAT_1c001a0c0;
  while (puVar4 = param_2, DAT_1c001a0c0 = lVar3, puVar4 != (undefined8 *)0x0) {
    local_44 = 0;
    param_2 = (undefined8 *)*puVar4;
    local_34 = 0;
    iVar6 = iVar6 + 1;
    lVar2 = puVar4[0xc];
    *puVar4 = 0;
    puVar4[0xc] = 0;
    lVar3 = *(longlong *)(lVar2 + 0x68);
    local_50 = lVar3 + 0x88;
    local_40 = *(undefined8 *)(lVar3 + 0x48);
    local_38 = *(undefined4 *)(lVar3 + 0x50);
    local_48 = *(undefined4 *)(lVar3 + 0x58);
    param_3 = *(undefined **)(lVar3 + 0x40);
    iVar5 = FwpsInjectTransportSendAsync0
                      (DAT_1c001a0e0,0,param_3,0,&local_50,2,1,puVar4,TeredoWfpInjectComplete,lVar2)
    ;
    lVar3 = DAT_1c001a0c0;
    if (iVar5 < 0) {
      param_3 = (undefined *)0x0;
      *(undefined4 *)((longlong)puVar4 + 0x8c) = 0xc0000001;
      TeredoWfpInjectComplete(lVar2,(longlong)puVar4,'\0');
      lVar3 = DAT_1c001a0c0;
    }
  }
  local_58 = 0;
  local_68 = 0;
  uStack_60 = 0;
  LOCK();
  piVar1 = (int *)(lVar3 + 0x40);
  iVar5 = *piVar1;
  *piVar1 = *piVar1 + iVar6 * -2;
  UNLOCK();
  if (iVar5 + iVar6 * -2 == 1) {
    RtlAcquireWriteLock(*(longlong *)(lVar3 + 0x10) + 0x18);
    lVar2 = *(longlong *)(lVar3 + 0x48);
    *(undefined8 *)(lVar3 + 0x48) = 0;
    if ((*(byte *)(lVar3 + 0xb8) & 1) == 0) {
      KeReleaseInStackQueuedSpinLock(&local_68);
    }
    else {
      *(uint *)(lVar3 + 0xb8) = *(uint *)(lVar3 + 0xb8) & 0xfffffffe | 2;
      KeReleaseInStackQueuedSpinLock();
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
        param_3 = &WPP_9608820f130d35da1284a1080d801204_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(undefined4 *)(lVar3 + 0x28));
      }
      if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
        McTemplateK0q_EtwWriteTransfer
                  (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_PAUSE_COMPLETE,
                   param_3,*(undefined4 *)(lVar3 + 0x28));
      }
      NdisMPauseComplete(*(undefined8 *)(lVar3 + 0x38));
    }
    if (lVar2 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
        param_3 = &WPP_9608820f130d35da1284a1080d801204_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(undefined4 *)(lVar3 + 0x28));
      }
      if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
        McTemplateK0q_EtwWriteTransfer
                  (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_POWER_COMPLETE,
                   param_3,*(undefined4 *)(lVar3 + 0x28));
      }
      TunnelPnpLogRequestCompletion(lVar3);
      IofCompleteRequest(lVar2,0);
    }
  }
  return;
}



===== TunnelMiniportSendNetBufferLists @ 1c0007fc0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TunnelMiniportSendNetBufferLists(longlong param_1)

{
  (**(code **)(*(longlong *)(param_1 + 0x20) + 0x50))();
  return;
}



===== TunnelUserBatchedWriteFile @ 1c0007ff0 =====

ulonglong TunnelUserBatchedWriteFile(undefined8 param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  code *pcVar5;
  undefined1 uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined1 *puVar11;
  longlong *plVar12;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  lVar4 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x20);
  uVar7 = TunnelUserValidateRwIrp(param_2,4,*(int *)(lVar4 + 0x18),'\0');
  uVar9 = uVar7 & 0xffffffff;
  if ((int)uVar7 < 0) goto LAB_1c0008084;
  lVar2 = lVar4 + 0x118;
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2);
  if ((char)*(undefined4 *)(lVar4 + 0x2c8) < '\0') {
LAB_1c00080e3:
    LOCK();
    *(code **)(param_2 + 0x68) = TunnelUserIoCancelWrite;
    UNLOCK();
    if (*(char *)(param_2 + 0x44) == '\0') {
LAB_1c0008109:
      uVar10 = 1;
      uVar7 = RoReferenceEx((uint *)(lVar4 + 0x40),1);
      puVar11 = auStack_28;
      if ((char)uVar7 != '\0') {
        pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
        *pbVar1 = *pbVar1 | (byte)uVar10;
        *(int *)(lVar4 + 0x148) = *(int *)(lVar4 + 0x148) + 1;
        *(undefined8 *)(param_2 + 0x78) = uVar10;
        plVar12 = (longlong *)(param_2 + 0xa8);
        plVar8 = *(longlong **)(lVar4 + 0x140);
        if (*plVar8 != lVar4 + 0x138) {
          pcVar5 = (code *)swi(0x29);
          plVar8 = (longlong *)(*pcVar5)((int)uVar10 + 2);
          puVar11 = auStack_20;
        }
        *plVar12 = lVar4 + 0x138;
        *(longlong **)(param_2 + 0xb0) = plVar8;
        *plVar8 = (longlong)plVar12;
        *(longlong **)(lVar4 + 0x140) = plVar12;
        *(undefined8 *)(puVar11 + -8) = 0x1c000816f;
        KeReleaseSpinLock(lVar2,uVar6);
        return 0x103;
      }
      goto LAB_1c000806d;
    }
    LOCK();
    lVar3 = *(longlong *)(param_2 + 0x68);
    *(longlong *)(param_2 + 0x68) = 0;
    UNLOCK();
    if (lVar3 == 0) goto LAB_1c0008109;
    uVar9 = 0xc0000120;
  }
  else {
    uVar9 = 1;
    uVar7 = RoReferenceEx((uint *)(lVar4 + 0x40),1);
    if ((char)uVar7 != '\0') {
      IoQueueWorkItemEx(*(undefined8 *)(lVar4 + 0x1c8),TunnelUserReceiveIndicationWorker,
                        uVar9 & 0xffffffff,lVar4);
      *(uint *)(lVar4 + 0x2c8) = *(uint *)(lVar4 + 0x2c8) | 0x80;
      goto LAB_1c00080e3;
    }
LAB_1c000806d:
    uVar9 = 0xc0000184;
  }
  KeReleaseSpinLock(lVar2,uVar6);
LAB_1c0008084:
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(int *)(param_2 + 0x30) = (int)uVar9;
  IofCompleteRequest(param_2,0);
  return uVar9;
}



===== TunnelUserValidateRwIrp @ 1c0008180 =====

undefined8 TunnelUserValidateRwIrp(longlong param_1,int param_2,int param_3,char param_4)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(param_1 + 8);
  if (lVar1 != 0) {
    if ((*(byte *)(lVar1 + 10) & 5) == 0) {
      lVar1 = MmMapLockedPagesSpecifyCache(lVar1,0,1,0,0,0x40000010);
    }
    else {
      lVar1 = *(longlong *)(lVar1 + 0x18);
    }
    if (lVar1 == 0) {
      return 0xc000009a;
    }
    if ((param_4 != '\x01') && (param_3 != 0xe)) {
      return 0;
    }
    if (**(longlong **)(param_1 + 8) == 0) {
      iVar2 = 0x50;
      if (param_3 != 0xe) {
        iVar2 = 8;
      }
      if ((uint)(iVar2 + param_2) <= *(uint *)(*(longlong **)(param_1 + 8) + 5)) {
        *(undefined8 *)(param_1 + 0x80) = 1;
        return 0;
      }
    }
  }
  return 0xc000000d;
}



===== TunnelUserAllocateNblForIndication @ 1c0008250 =====

undefined8 TunnelUserAllocateNblForIndication(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  int iVar6;
  
  uVar4 = *(undefined8 *)(param_1 + 0x158);
  *param_2 = 0;
  plVar2 = (longlong *)NdisAllocateNetBufferList(uVar4,0,0);
  if (plVar2 == (longlong *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    plVar5 = plVar2;
    do {
      puVar1 = (undefined8 *)plVar5[1];
      iVar6 = 0;
      plVar5[0xc] = (longlong)puVar1;
      for (; puVar1 != (undefined8 *)0x0; puVar1 = (undefined8 *)*puVar1) {
        iVar6 = iVar6 + 1;
        puVar1[0x10] = puVar1[1];
        *(undefined4 *)(puVar1 + 0x11) = *(undefined4 *)(puVar1 + 2);
        *(undefined4 *)((longlong)puVar1 + 0x8c) = *(undefined4 *)(puVar1 + 5);
      }
      *(int *)(plVar5 + 0xd) = iVar6;
      plVar5 = (longlong *)*plVar5;
    } while (plVar5 != (longlong *)0x0);
    *(undefined4 *)(plVar2[1] + 0x10) = 0;
    *(undefined4 *)(plVar2[1] + 0x28) = 0;
    if (DAT_1c001aa1a != '\0') {
      *(uint *)(plVar2 + 0x13) = *(uint *)(plVar2 + 0x13) | 2;
    }
    lVar3 = *(longlong *)(plVar2[1] + 8);
    if ((*(byte *)(lVar3 + 10) & 5) == 0) {
      lVar3 = MmMapLockedPagesSpecifyCache(lVar3,0,1,0,0,0x40000010);
    }
    else {
      lVar3 = *(longlong *)(lVar3 + 0x18);
    }
    if (lVar3 == 0) {
      NdisFreeNetBufferList(plVar2);
      *param_2 = 0;
      return 0xc000009a;
    }
    uVar4 = 0;
  }
  *param_2 = plVar2;
  return uVar4;
}



===== TunnelMiniportDirectOidRequest @ 1c0008370 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int TunnelMiniportDirectOidRequest(longlong param_1,longlong param_2,longlong param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  if (*(int *)(param_2 + 4) != 1) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
      WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,(ulonglong)*(uint *)(param_1 + 0x28)
                ,*(int *)(param_2 + 4),(char)*(uint *)(param_1 + 0x28));
    }
    return -0x3ffffffe;
  }
  iVar1 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if (*(int *)(param_2 + 0x20) == 0xf010106) {
    if (*(int *)(param_2 + 0x30) == 0x88) {
      param_3 = param_2;
      iVar1 = (**(code **)(*(longlong *)(param_1 + 0x20) + 0x98))(0,*(undefined8 *)(param_2 + 0x28))
      ;
      uVar2 = 0x88;
      if (iVar1 != 0) {
        uVar2 = 0;
      }
      *(undefined4 *)(param_2 + 0x34) = uVar2;
      if (iVar1 == 0x103) {
        RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10) + 0x18);
        if ((*(uint *)(param_1 + 0xb8) & 3) == 0) {
          *(longlong *)(param_1 + 0x50) = param_2;
        }
        KeReleaseInStackQueuedSpinLock(&local_28);
      }
    }
    else {
      iVar1 = -0x3ffeffeb;
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)
     ) {
    WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_3,*(undefined4 *)(param_2 + 4),
               (char)*(undefined4 *)(param_1 + 0x28),(char)iVar1);
  }
  return iVar1;
}



===== TunnelDriverDispatchDevControl @ 1c00084f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong TunnelDriverDispatchDevControl(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  uint *puVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong *plVar6;
  uint uVar7;
  longlong *plVar8;
  undefined *puVar9;
  GUID *pGVar10;
  longlong *plVar11;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if (*(int *)(lVar1 + 0x18) == 0x12cc40) {
    if (*(int *)(lVar1 + 0x10) != 0x58) {
LAB_1c0008678:
      uVar7 = 0xc0000206;
      goto LAB_1c00086da;
    }
    puVar2 = *(uint **)(param_2 + 0x18);
    KeEnterCriticalRegion();
    pGVar10 = (GUID *)0x0;
    uVar3 = 0;
    KeWaitForSingleObject(&DAT_1c001aa70,0,0,0,0);
    uVar4 = TunnelMiniportInitializeLWM(puVar2,uVar3,pGVar10);
    uVar7 = (uint)uVar4;
  }
  else {
    if (*(int *)(lVar1 + 0x18) != 0x12cc44) {
      lVar1 = *(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x20);
      if (lVar1 != 0) {
        uVar4 = (**(code **)(*(longlong *)(lVar1 + 0x20) + 0x80))(param_1,param_2);
        return uVar4;
      }
      uVar7 = 0xc0000225;
      goto LAB_1c00086da;
    }
    if (*(int *)(lVar1 + 0x10) != 0x58) goto LAB_1c0008678;
    lVar1 = *(longlong *)(param_2 + 0x18);
    KeEnterCriticalRegion();
    uVar4 = 0;
    puVar9 = (undefined *)0x0;
    KeWaitForSingleObject(&DAT_1c001aa70,0,0,0,0);
    uVar7 = 0;
    local_38 = 0;
    uStack_30 = 0;
    local_28 = 0;
    do {
      plVar11 = &DAT_1c001a6f0 + (ulonglong)uVar7 * 0xe;
      RtlAcquireWriteLock((longlong)(&DAT_1c001a708 + (ulonglong)uVar7 * 0x70));
      for (plVar8 = (longlong *)*plVar11; plVar8 != plVar11; plVar8 = (longlong *)*plVar8) {
        lVar5 = plVar8[0x21] - *(longlong *)(lVar1 + 4);
        if (lVar5 == 0) {
          lVar5 = plVar8[0x22] - *(longlong *)(lVar1 + 0xc);
        }
        if (lVar5 == 0) {
          KeReleaseInStackQueuedSpinLock(&local_38);
          plVar6 = (longlong *)0x0;
          if (plVar8 != (longlong *)0x0) {
            plVar6 = plVar11;
          }
          goto LAB_1c0008641;
        }
      }
      KeReleaseInStackQueuedSpinLock(&local_38);
      uVar7 = uVar7 + 1;
      plVar8 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
    } while (uVar7 < 5);
LAB_1c0008641:
    if (plVar8 == (longlong *)0x0) {
      uVar7 = 0xc0000225;
    }
    else {
      uVar3 = TunnelMiniportHaltLWM(plVar8,(longlong)plVar6,puVar9,uVar4);
      uVar7 = (uint)uVar3;
    }
  }
  KeReleaseMutex(&DAT_1c001aa70,0);
  KeLeaveCriticalRegion();
LAB_1c00086da:
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(uint *)(param_2 + 0x30) = uVar7;
  IofCompleteRequest(param_2,0);
  return (ulonglong)uVar7;
}



===== RtlAcquireWriteLock @ 1c0008704 =====

void RtlAcquireWriteLock(longlong param_1)

{
  KeAcquireInStackQueuedSpinLock();
  do {
  } while (*(int *)(param_1 + 8) != 0);
  return;
}



===== TunnelDriverDispatchRead @ 1c0008730 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 TunnelDriverDispatchRead(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x20);
  if (lVar1 == 0) {
    uVar2 = 0xc0000225;
  }
  else {
    uVar2 = (**(code **)(*(longlong *)(lVar1 + 0x20) + 0x88))(param_1);
  }
  return uVar2;
}



===== TunnelUserDequeueReadIrp @ 1c0008774 =====

void TunnelUserDequeueReadIrp(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  *(int *)(param_1 + 0x14c) = *(int *)(param_1 + 0x14c) + -1;
  plVar1 = (longlong *)(param_2 + 0xa8);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    *(undefined8 *)(param_2 + 0x78) = 0;
    *plVar1 = 0;
    *(undefined8 *)(param_2 + 0xb0) = 0;
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== TunnelTeredoGetPhysicalInterface @ 1c00087c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TunnelTeredoGetPhysicalInterface(longlong param_1,longlong param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined1 auStack_188 [32];
  undefined4 local_168;
  undefined8 *local_160;
  undefined4 local_158;
  longlong **local_150;
  undefined4 local_148;
  undefined8 local_140;
  undefined4 local_138;
  uint local_128 [4];
  undefined1 local_118 [8];
  undefined4 local_110;
  uint *local_d8;
  undefined8 local_d0;
  longlong *local_a0;
  longlong *local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_188;
  local_68 = *(undefined8 *)(param_1 + 0x30);
  uVar4 = 0;
  local_138 = 0;
  local_140 = 0;
  local_148 = 0x10;
  local_150 = &local_78;
  local_158 = 0x20;
  local_160 = &local_48;
  local_78 = (longlong *)0x0;
  uStack_70 = 0;
  local_58 = *(undefined4 *)(param_2 + 8);
  uStack_54 = *(undefined4 *)(param_2 + 0xc);
  uStack_50 = *(undefined4 *)(param_2 + 0x10);
  uStack_4c = *(undefined4 *)(param_2 + 0x14);
  local_168 = 0x20;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_60 = local_68;
  iVar1 = NsiGetAllParameters(1,&NPI_MS_IPV6_MODULEID,0xb,&local_68);
  if (((iVar1 < 0) || ((uint)local_78 < 2)) || (uStack_70._1_1_ != '\0')) {
    iVar1 = -0x3fffffea;
  }
  else {
    local_128[0] = ~uStack_40._2_4_;
    memset(local_118,0,0xa0);
    uVar3 = 1;
    iVar1 = -0x3fffffff;
    local_78 = (longlong *)0x0;
    uStack_70 = 0;
    uVar2 = RoReferenceEx((uint *)&DAT_1c001a7c0,1);
    if ((char)uVar2 != '\0') {
      local_d0 = 0;
      local_d8 = local_128;
      local_110 = uVar3;
      iVar1 = (**(code **)(DAT_1c001a7a0 + 0x40))(DAT_1c001a798,local_118);
      if (-1 < iVar1) {
        uVar4 = *(undefined8 *)(*(longlong *)(*local_a0 + 8) + 0x10);
        local_78 = local_a0;
        (**(code **)(DAT_1c001a7a0 + 0x48))(&local_78);
      }
      TunnelNlDereferenceNlBinding(0x1c001a760);
    }
    if (iVar1 < 0) {
      iVar1 = -0x3ffeffd7;
    }
    else {
      *(undefined8 *)(param_2 + 0x80) = uVar4;
    }
  }
  return iVar1;
}



===== TunnelDriverDispatchWrite @ 1c0008960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 TunnelDriverDispatchWrite(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x20);
  if (lVar1 == 0) {
    uVar2 = 0xc0000225;
  }
  else {
    uVar2 = (**(code **)(*(longlong *)(lVar1 + 0x20) + 0x90))(param_1);
  }
  return uVar2;
}



===== TunnelTeredoSupportsOffload @ 1c00089b0 =====

uint TunnelTeredoSupportsOffload(longlong param_1)

{
  return CONCAT31((uint3)(*(uint *)(param_1 + 0x2c8) >> 0xb),(char)(*(uint *)(param_1 + 0x2c8) >> 3)
                 ) & 0xffffff01;
}



===== TunnelNlcUpdateInterfaceNotification @ 1c00089d0 =====

void TunnelNlcUpdateInterfaceNotification(longlong param_1,longlong param_2,int param_3)

{
  bool bVar1;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong lVar9;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  if (param_3 == 0) {
    bVar1 = false;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
      WPP_SF_Ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,(ulonglong)*(byte *)(param_2 + 8),
                 *(undefined4 *)(*(longlong *)(param_1 + 8) + 8),*(byte *)(param_2 + 8),
                 *(undefined1 *)(param_2 + 9));
    }
    piVar6 = &DAT_1c001a710;
    lVar9 = 4;
    do {
      uVar2 = KfRaiseIrql(2);
      local_38 = 0;
      local_48 = 0;
      uStack_40 = 0;
      LOCK();
      *piVar6 = *piVar6 + 1;
      UNLOCK();
      cVar3 = KeTestSpinLock(piVar6 + -2);
      if (cVar3 == '\0') {
        LOCK();
        *piVar6 = *piVar6 + -1;
        UNLOCK();
        KeAcquireInStackQueuedSpinLockAtDpcLevel(piVar6 + -2,&local_48);
        LOCK();
        *piVar6 = *piVar6 + 1;
        UNLOCK();
        KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_48);
      }
      for (piVar5 = *(int **)(piVar6 + -8); piVar5 != piVar6 + -8; piVar5 = *(int **)piVar5) {
        if (piVar5[10] == *(int *)(*(longlong *)(param_1 + 8) + 8)) {
          uVar4 = piVar5[0x2e];
          if ((uVar4 >> 3 & 1) != (uint)*(byte *)(param_2 + 8)) {
            bVar1 = true;
            uVar4 = ((uint)*(byte *)(param_2 + 8) * 8 ^ uVar4) & 8 ^ uVar4;
            piVar5[0x2e] = uVar4;
          }
          if ((uVar4 >> 4 & 1) == (uint)*(byte *)(param_2 + 9)) {
            if (!bVar1) break;
          }
          else {
            bVar1 = true;
            uVar4 = ((uint)*(byte *)(param_2 + 9) << 4 ^ uVar4) & 0x10 ^ uVar4;
            piVar5[0x2e] = uVar4;
          }
          uVar8 = (ulonglong)uVar4;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
            uVar7 = uVar4 >> 3 & 1;
            uVar8 = (ulonglong)uVar7;
            WPP_SF_Ddd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,uVar8,piVar5[10],(char)uVar7,
                       (byte)(uVar4 >> 4) & 1);
          }
          if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
            McTemplateK0qqq_EtwWriteTransfer
                      (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,
                       &EVENT_TUNNEL_INTERFACE_UPDATE_NOTIFICATION,uVar8,
                       *(undefined4 *)(*(longlong *)(param_1 + 8) + 8),*(undefined1 *)(param_2 + 8),
                       *(undefined1 *)(param_2 + 9));
          }
          break;
        }
      }
      LOCK();
      *piVar6 = *piVar6 + -1;
      UNLOCK();
      KeLowerIrql(uVar2);
      piVar6 = piVar6 + 0x1c;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
  }
  return;
}



===== TunnelMiniportReturnNetBufferLists @ 1c0008c10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TunnelMiniportReturnNetBufferLists(longlong param_1)

{
  (**(code **)(*(longlong *)(param_1 + 0x20) + 0x48))();
  return;
}



===== TunnelNlMapIcmpv4ToIcmpv6 @ 1c0008c30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0008ff7) */
/* WARNING: Removing unreachable block (ram,0x0001c00090bb) */
/* WARNING: Removing unreachable block (ram,0x0001c00090eb) */
/* WARNING: Removing unreachable block (ram,0x0001c0009102) */
/* WARNING: Removing unreachable block (ram,0x0001c000910c) */
/* WARNING: Removing unreachable block (ram,0x0001c0009119) */
/* WARNING: Removing unreachable block (ram,0x0001c0009083) */
/* WARNING: Removing unreachable block (ram,0x0001c000909a) */
/* WARNING: Removing unreachable block (ram,0x0001c00090a4) */
/* WARNING: Removing unreachable block (ram,0x0001c00090b1) */
/* WARNING: Removing unreachable block (ram,0x0001c0009123) */
/* WARNING: Removing unreachable block (ram,0x0001c000915a) */

longlong TunnelNlMapIcmpv4ToIcmpv6(longlong *param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong *plVar9;
  undefined8 uVar10;
  undefined *puVar11;
  undefined *puVar12;
  undefined1 auStackY_1b8 [32];
  longlong *local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined1 local_138 [8];
  undefined4 local_130;
  undefined8 *local_f8;
  longlong *local_c0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined2 local_50;
  undefined2 local_4e;
  uint local_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1b8;
  lVar1 = *(longlong *)(param_2 + 8);
  lVar2 = *(longlong *)(lVar1 + 8);
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_170 = 0;
  uStack_168 = 0;
  local_160 = 0;
  uStack_158 = 0;
  local_150 = 0;
  uStack_148 = 0;
  memset(local_138,0,0xa0);
  *param_3 = 0;
  local_180 = (longlong *)0x0;
  uStack_178 = 0;
  if ((*(char *)(param_2 + 0xa0) - 3U & 0xf6) != 0) {
    *(undefined4 *)(lVar1 + 0x8c) = 0xc0000001;
    return 0;
  }
  iVar5 = 1;
  uVar7 = RoReferenceEx((uint *)(param_1 + 0xc),1);
  if ((char)uVar7 == '\0') {
    return 0;
  }
  lVar1 = param_1[6];
  if ((0x17 < *(uint *)(lVar2 + 0x18)) &&
     (lVar8 = NdisGetDataBuffer(lVar2,iVar5 + 0x17), lVar8 != 0)) {
    local_98 = *(undefined8 *)(lVar8 + 8);
    uStack_90 = *(undefined8 *)(lVar8 + 0x10);
    puVar12 = *(undefined **)(param_2 + 0x18);
    puVar3 = *(undefined8 **)(*(longlong *)(param_2 + 0x20) + 8);
    puVar4 = (undefined4 *)*puVar3;
    plVar9 = TunnelNlFindReceiver
                       (param_1,puVar4,puVar12,
                        **(undefined8 **)(*(longlong *)(param_2 + 0x20) + 0x10),&local_98,
                        *(undefined4 *)(puVar3 + 1));
    *param_3 = (longlong)plVar9;
    if (plVar9 == (longlong *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
        puVar12 = &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids);
      }
      if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
        McTemplateK0_EtwWriteTransfer
                  (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_NOT_FOUND_FOR_ICMP,
                   puVar12);
      }
    }
    else {
      local_130 = *puVar4;
      local_f8 = &local_98;
      iVar5 = (**(code **)(*(longlong *)(lVar1 + 0x40) + 0x40))
                        (*(undefined8 *)(lVar1 + 0x38),local_138);
      if (iVar5 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                  &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids);
        }
        puVar12 = (undefined *)0x0;
        if ((DAT_1c0017024 == 0) || ((Microsoft_Windows_TunnelDriverEnableBits & 1) == 0))
        goto LAB_1c0008db7;
        puVar11 = &EVENT_TUNNEL_ICMP_SOURCE_NOT_FOUND;
      }
      else {
        local_88 = *(undefined8 *)**(longlong **)(*local_c0 + 0x10);
        uStack_80 = ((undefined8 *)**(longlong **)(*local_c0 + 0x10))[1];
        uStack_178 = 0;
        local_180 = local_c0;
        (**(code **)(*(longlong *)(lVar1 + 0x40) + 0x48))(&local_180);
        if ((*(char *)(param_2 + 0xa0) == '\x03') && (*(char *)(param_2 + 0xa1) == '\x04')) {
          uVar6 = *(uint *)(param_2 + 0xa4);
          uVar6 = (uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18)
                  - 0x14;
          local_50 = 2;
          local_4c = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 |
                     uVar6 * 0x1000000;
        }
        else {
          local_50 = 0x401;
        }
        local_4e = 0;
        uVar10 = NetioRetreatNetBuffer(lVar2,8);
        if ((int)uVar10 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                    &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids);
          }
          goto LAB_1c0008db7;
        }
        puVar12 = (undefined *)(ulonglong)*(uint *)(lVar2 + 0x28);
        RtlCopyBufferToMdl(&local_50,*(undefined8 *)(lVar2 + 0x20),puVar12,8);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
          puVar12 = &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                  &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids);
        }
        if ((DAT_1c0017024 == 0) || ((Microsoft_Windows_TunnelDriverEnableBits & 1) == 0))
        goto LAB_1c0008db7;
        puVar11 = &EVENT_TUNNEL_FAILED_COPY_BUFFER_TO_MDL;
      }
      McTemplateK0q_EtwWriteTransfer
                (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,puVar11,puVar12,
                 *(undefined4 *)(*param_3 + 0x28));
    }
  }
LAB_1c0008db7:
  TunnelNlDereferenceNlBinding((longlong)param_1);
  if (*param_3 != 0) {
    TunnelInterfaceDereferenceExImp(*param_3,1,(undefined *)0x0);
    *param_3 = 0;
  }
  return 0;
}



===== NetioRetreatNetBuffer @ 1c0009170 =====

undefined8 NetioRetreatNetBuffer(longlong param_1,uint param_2)

{
  undefined8 uVar1;
  
  if (*(uint *)(param_1 + 0x10) < param_2) {
    uVar1 = NdisRetreatNetBufferDataStart();
  }
  else {
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - param_2;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + param_2;
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) - param_2;
    uVar1 = 0;
  }
  return uVar1;
}



===== TunnelTimeoutRoutine @ 1c00091b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong TunnelTimeoutRoutine(void)

{
  ulonglong uVar1;
  bool bVar2;
  
  uVar1 = 0;
  LOCK();
  bVar2 = DAT_1c001a9f0 == 0;
  if (bVar2) {
    DAT_1c001a9f0 = 1;
  }
  else {
    uVar1 = (ulonglong)DAT_1c001a9f0;
  }
  UNLOCK();
  if (bVar2) {
    _DAT_1c001aa08 = 0;
    _DAT_1c001aa10 = TunnelTimeoutWorkItemRoutine;
    uVar1 = TunnelQueueWorkItem((undefined8 *)&DAT_1c001a9f8);
  }
  return uVar1;
}



===== TunnelQueueWorkItem @ 1c00091f8 =====

void TunnelQueueWorkItem(undefined8 *param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_1c001a9d0);
  puVar5 = auStack_28;
  puVar3 = &DAT_1c001a9c0;
  puVar4 = DAT_1c001a9c8;
  if ((undefined8 *)*DAT_1c001a9c8 != &DAT_1c001a9c0) {
    puVar4 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    puVar3 = (undefined8 *)(*pcVar1)();
    puVar5 = auStack_20;
  }
  *param_1 = puVar3;
  param_1[1] = puVar4;
  *puVar4 = param_1;
  DAT_1c001a9c8 = param_1;
  if (DAT_1c001aa18 == '\0') {
    *(undefined8 *)(puVar5 + -8) = 0x1c000926a;
    IoQueueWorkItem(DAT_1c001a9b8,TunnelWorkQueueRoutine,0,0);
    DAT_1c001aa18 = '\x01';
    *(undefined8 *)(puVar5 + -8) = 0x1c0009284;
    KeResetEvent(&DAT_1c001a9d8);
  }
  *(undefined8 *)(puVar5 + -8) = 0x1c000929a;
  KeReleaseSpinLock(&DAT_1c001a9d0,uVar2);
  return;
}



===== TunnelUserTimeoutHandler @ 1c00092c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint TunnelUserTimeoutHandler(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  uVar3 = 0;
  lVar6 = SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816(_DAT_fffff78000000014),8) +
          _DAT_fffff78000000014;
  iVar4 = *(int *)(param_1 + 0x1d4) + 1;
  *(longlong *)(param_1 + 0x2c0) = (lVar6 >> 0x17) - (lVar6 >> 0x3f);
  *(int *)(param_1 + 0x1d4) = iVar4;
  if (*(longlong *)(param_1 + 0x168) != 0) {
    KeReleaseInStackQueuedSpinLock(param_3);
    bVar2 = KeGetCurrentIrql();
    if (bVar2 < 2) {
      uVar3 = KfRaiseIrql();
    }
    KeAcquireSpinLockAtDpcLevel(param_1 + 0x118);
    iVar5 = *(int *)(param_1 + 0x1d0) + 1;
    *(int *)(param_1 + 0x1d0) = iVar5;
    if (4999 < (uint)(iVar5 * 15000)) {
      *(undefined4 *)(param_1 + 0x1d0) = 0;
      TunnelCompletePendingNdisAppSends(param_1);
    }
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x118);
    if (bVar2 < 2) {
      KeLowerIrql(uVar3);
    }
    RtlAcquireWriteLock(lVar1 + 0x18);
  }
  if (29999 < (uint)(iVar4 * 15000)) {
    *(undefined4 *)(param_1 + 0x1d4) = 0;
    KeReleaseInStackQueuedSpinLock(param_3);
    (**(code **)(*(longlong *)(param_1 + 0x20) + 0xb0))(param_1);
    KeAcquireInStackQueuedSpinLock(lVar1 + 0x18,param_3);
    do {
    } while (*(int *)(lVar1 + 0x20) != 0);
  }
  return CONCAT31((uint3)(*(uint *)(param_1 + 0xb8) >> 0xd),(char)(*(uint *)(param_1 + 0xb8) >> 5))
         & 0xffffff01;
}



===== TeredoInitializeHashTable @ 1c000946c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 TeredoInitializeHashTable(void)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  
  DAT_1c001a120 = 1;
  DAT_1c0017360 = ExAllocatePool2(0x40,0x80e0,0x74487754);
  if (DAT_1c0017360 == 0) {
    uVar1 = 0xc000009a;
  }
  else {
    lVar2 = DAT_1c0017360 + 0x10;
    lVar3 = 0x407;
    do {
      *(longlong *)(lVar2 + 8) = lVar2;
      *(longlong *)lVar2 = lVar2;
      lVar2 = lVar2 + 0x20;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    _DAT_1c0017340 = _DAT_fffff78000000008;
    DAT_1c001a120 = 2;
    KeInitializeEvent(&HashTableUninitializedEvent,0,0);
    uVar1 = 0;
  }
  return uVar1;
}



===== TeredoWfpDdLayerDelete @ 1c0009510 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TeredoWfpDdLayerDelete(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  longlong *plVar4;
  
  LOCK();
  _DAT_1c00173b0 = _DAT_1c00173b0 + 1;
  UNLOCK();
  plVar4 = param_3;
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_3 + 2);
  *(undefined2 *)((longlong)param_3 + 0x8c) = 0x100;
  *(undefined1 *)((longlong)param_3 + 0x91) = 0;
  KeReleaseSpinLock(param_3 + 2,uVar3);
  LOCK();
  *(int *)((longlong)param_3 + 0x1c) = *(int *)((longlong)param_3 + 0x1c) + -1;
  UNLOCK();
  LOCK();
  piVar1 = (int *)((longlong)param_3 + 0x1c);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -2;
  UNLOCK();
  if (iVar2 == 3) {
    TeredoWfpRemoveHashEntry(param_3);
    if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
      McTemplateK0q_EtwWriteTransfer
                (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_TEREDO_FLOW_FREED,plVar4,
                 *(undefined4 *)((longlong)param_3 + 0x24));
    }
    if (param_3[9] != 0) {
      ExFreePoolWithTag(param_3[9],0x64437754);
    }
    plVar4 = &DAT_1c0017408;
    if (*(int *)((longlong)param_3 + 0x24) != 2) {
      plVar4 = &DAT_1c0017400;
    }
    LOCK();
    *plVar4 = *plVar4 + -1;
    UNLOCK();
    ExFreePoolWithTag(param_3,0x70667754);
  }
  return;
}



===== TunnelUserGetCurrentAddress @ 1c0009600 =====

undefined8 TunnelUserGetCurrentAddress(longlong param_1,uint param_2,void *param_3,uint *param_4)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  uVar1 = *(int *)(param_1 + 0xfc) + 8;
  *param_4 = uVar1;
  if (param_2 < uVar1) {
    uVar2 = 0xc0000023;
  }
  else {
    memcpy(param_3,(void *)(param_1 + 0xbc),(ulonglong)uVar1);
  }
  return uVar2;
}



===== TunnelGetDlAddressFromNblHelper @ 1c0009644 =====

undefined8 TunnelGetDlAddressFromNblHelper(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x108);
  while( true ) {
    if (lVar1 == 0) {
      return 0;
    }
    if (*(int *)(lVar1 + 0x10) == 0x10001) break;
    lVar1 = *(longlong *)(lVar1 + 8);
  }
  return *(undefined8 *)(lVar1 + 0x18);
}



===== TeredoWfpRegisterCallouts @ 1c0009670 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int TeredoWfpRegisterCallouts(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  undefined1 auStack_128 [32];
  undefined8 *local_108;
  undefined4 local_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  wchar_t *local_e8;
  wchar_t *local_e0;
  undefined4 local_d8;
  undefined *local_d0;
  undefined2 local_b8;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  wchar_t *local_98;
  wchar_t *local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined1 local_68 [16];
  wchar_t *local_58;
  wchar_t *local_50;
  undefined4 local_48;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_128;
  memset(&local_a8,0,0x40);
  memset(&local_f8,0,0x48);
  memset(local_68,0,0x48);
  local_48 = 1;
  local_58 = L"Teredo Tunnel Session";
  puVar4 = &DAT_1c001a0e0;
  local_50 = L"Session used by the Teredo tunnel driver";
  iVar1 = FwpsInjectionHandleCreate0(0,2);
  if (iVar1 < 0) {
    DAT_1c001a0e0 = 0;
  }
  else {
    puVar4 = (undefined8 *)0x0;
    local_108 = &DAT_1c001a0f0;
    iVar1 = FwpmEngineOpen0(0,10,0,local_68);
    if (iVar1 < 0) {
      DAT_1c001a0f0 = 0;
    }
    else {
      iVar1 = FwpmTransactionBegin0(DAT_1c001a0f0,0);
      if (-1 < iVar1) {
        local_98 = L"Microsoft Corporation";
        local_88 = 0;
        uStack_80 = 0;
        local_90 = L"Microsoft Windows Teredo tunnel driver provider";
        puVar4 = (undefined8 *)0x0;
        local_a8 = _TeredoWfpProviderGuid;
        uStack_a4 = uRam00000001c0017154;
        uStack_a0 = uRam00000001c0017158;
        uStack_9c = uRam00000001c001715c;
        local_78 = 0;
        uStack_70 = 0;
        iVar1 = FwpmProviderAdd0(DAT_1c001a0f0,&local_a8);
        if (-1 < iVar1) {
          local_e8 = L"Teredo Tunnel Sublayer";
          puVar3 = &local_f8;
          local_d8 = 0;
          local_e0 = L"Sublayer used by the Teredo tunnel driver";
          puVar4 = (undefined8 *)0x0;
          local_b8 = 0;
          local_d0 = &TeredoWfpProviderGuid;
          local_f8 = 0x7bf26662;
          uStack_f4 = 0x4d581886;
          uStack_f0 = 0x7c50c485;
          uStack_ec = 0xc5532ace;
          lVar2 = DAT_1c001a0f0;
          iVar1 = FwpmSubLayerAdd0();
          if (-1 < iVar1) {
            puVar4 = *(undefined8 **)(param_1 + 0x120);
            iVar1 = TeredoWfpRegisterAleLayerCallouts(lVar2,puVar3,puVar4);
            if (-1 < iVar1) {
              puVar4 = *(undefined8 **)(param_1 + 0x120);
              iVar1 = TeredoWfpRegisterDdLayerCallouts(lVar2,puVar3,puVar4);
              if (-1 < iVar1) {
                iVar1 = FwpmTransactionCommit0(DAT_1c001a0f0);
                if (-1 < iVar1) goto LAB_1c00098e7;
              }
            }
          }
        }
        FwpmTransactionAbort0(DAT_1c001a0f0);
      }
    }
  }
  if (TwCalloutIdV4 != 0) {
    FwpsCalloutUnregisterById0();
    TwCalloutIdV4 = 0;
  }
  if (DAT_1c001a0e8 != 0) {
    FwpsCalloutUnregisterById0();
    DAT_1c001a0e8 = 0;
  }
  if (DAT_1c001a0f0 != 0) {
    FwpmEngineClose0();
    DAT_1c001a0f0 = 0;
  }
  if (DAT_1c001a0e0 != 0) {
    FwpsInjectionHandleDestroy0();
    DAT_1c001a0e0 = 0;
  }
LAB_1c00098e7:
  if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
    McTemplateK0q_EtwWriteTransfer
              (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_TEREDOWFP_REGISTRATION,puVar4,
               iVar1);
  }
  return iVar1;
}



===== TunnelNlGetNextHopInterface @ 1c000993c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int TunnelNlGetNextHopInterface
              (longlong param_1,undefined8 param_2,longlong param_3,undefined8 *param_4)

{
  int iVar1;
  ulonglong uVar2;
  undefined4 uVar3;
  longlong *local_b8;
  undefined8 uStack_b0;
  undefined1 local_a8 [8];
  undefined4 local_a0;
  undefined8 local_68;
  longlong local_60;
  longlong *local_30;
  
  memset(local_a8,0,0xa0);
  uVar3 = 1;
  iVar1 = -0x3fffffff;
  local_b8 = (longlong *)0x0;
  uStack_b0 = 0;
  uVar2 = RoReferenceEx((uint *)(param_1 + 0x60),1);
  if ((char)uVar2 != '\0') {
    if (param_3 == 0) {
      local_a0 = uVar3;
    }
    local_68 = param_2;
    local_60 = param_3;
    iVar1 = (**(code **)(*(longlong *)(param_1 + 0x40) + 0x40))
                      (*(undefined8 *)(param_1 + 0x38),local_a8);
    if (-1 < iVar1) {
      *param_4 = *(undefined8 *)(*(longlong *)(*local_30 + 8) + 0x10);
      local_b8 = local_30;
      (**(code **)(*(longlong *)(param_1 + 0x40) + 0x48))(&local_b8);
    }
    TunnelNlDereferenceNlBinding(param_1);
  }
  return iVar1;
}



===== TunnelTeredoInitializeSpecific @ 1c0009a30 =====

int TunnelTeredoInitializeSpecific(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined7 uVar5;
  
  puVar4 = &g_TunnelTeredoUserDevicePath;
  *(undefined **)(param_1 + 0x2d8) = &g_TunnelTeredoUserDevicePath;
  puVar3 = &g_TunnelTeredoNtDevicePath;
  iVar1 = TunnelRegisterDevice
                    (*(undefined8 *)(DAT_1c001a6d8 + 8),&g_TunnelTeredoNtDevicePath,
                     &g_TunnelTeredoUserDevicePath,(longlong *)(param_1 + 0x120));
  if (iVar1 == 0) {
    uVar5 = (undefined7)((ulonglong)puVar4 >> 8);
    uVar2 = TunnelUserAllocatePacketPools(param_1,puVar3,'\x01');
    iVar1 = (int)uVar2;
    if (iVar1 == 0) {
      KeInitializeEvent(param_1 + 0x208,0,CONCAT71(uVar5,1));
      *(undefined4 *)(param_1 + 0x220) = 1;
      KeInitializeEvent(param_1 + 0x228,0,1);
      return 0;
    }
  }
  TunnelUserFreePacketPools(param_1);
  TunnelUserDestroyDevice(param_1);
  return iVar1;
}



===== TunnelRegisterDevice @ 1c0009ae0 =====

int TunnelRegisterDevice(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  int iVar1;
  
  iVar1 = WdmlibIoCreateDeviceSecure(param_1,param_2,param_2);
  if (-1 < iVar1) {
    *(uint *)(*param_4 + 0x30) = *(uint *)(*param_4 + 0x30) | 0x10;
    *(uint *)(*param_4 + 0x30) = *(uint *)(*param_4 + 0x30) & 0xffffff7f;
    iVar1 = IoCreateSymbolicLink(param_3,param_2);
    if (iVar1 < 0) {
      IoDeleteDevice(*param_4);
      *param_4 = 0;
    }
  }
  return iVar1;
}



===== TeredoUninitializeWorkQueues @ 1c0009b74 =====

void TeredoUninitializeWorkQueues(void)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = 0;
  lVar2 = 0x40;
  do {
    LwUninitializeQueue((longlong)(&DAT_1c0018a20 + lVar1));
    LwUninitializeQueue((longlong)(&DAT_1c0017420 + lVar1));
    lVar1 = lVar1 + 0x58;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}



===== LwUninitializeQueue @ 1c0009bd0 =====

void LwUninitializeQueue(longlong param_1)

{
  if (*(char *)(param_1 + 0x21) != '\0') {
    *(undefined1 *)(param_1 + 0x21) = 0;
    IoUninitializeWorkItem(*(undefined8 *)(param_1 + 0x28));
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x28),0x6957714c);
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  return;
}



===== RtlAcquireReadLock @ 1c0009c1c =====

void RtlAcquireReadLock(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  uVar1 = KfRaiseIrql(2);
  *param_2 = uVar1;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  LOCK();
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  UNLOCK();
  cVar2 = KeTestSpinLock(param_1);
  if (cVar2 == '\0') {
    LOCK();
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
    UNLOCK();
    KeAcquireInStackQueuedSpinLockAtDpcLevel(param_1,&local_28);
    LOCK();
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    UNLOCK();
    KeReleaseInStackQueuedSpinLockFromDpcLevel(&local_28);
  }
  return;
}



===== TunnelMiniportInitializeLWM @ 1c0009ca4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong TunnelMiniportInitializeLWM(uint *param_1,undefined8 param_2,GUID *param_3)

{
  PNET_IFINDEX InterfaceIndex;
  GUID *InterfaceGuid;
  ULONG UVar1;
  undefined8 uVar2;
  code *pcVar3;
  bool bVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  longlong *plVar9;
  undefined4 *puVar10;
  undefined2 uVar11;
  ulonglong uVar12;
  undefined1 *puVar13;
  uint uVar14;
  ulonglong uVar15;
  longlong *plVar16;
  longlong *local_res10;
  uchar local_res18 [8];
  undefined1 auStackY_88 [8];
  undefined1 auStackY_80 [24];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  
  uVar6 = *param_1;
  local_res18[0] = '\0';
  local_res18[1] = '\0';
  local_res18[2] = '\0';
  local_res18[3] = '\0';
  local_res18[4] = '\0';
  local_res18[5] = '\0';
  local_res18[6] = '\0';
  local_res18[7] = '\0';
  local_res10 = (longlong *)0x0;
  local_48 = 0;
  bVar4 = false;
  plVar9 = (longlong *)0x0;
  plVar16 = (longlong *)0x0;
  local_58 = 0;
  uStack_50 = 0;
  if (uVar6 == 1) {
LAB_1c000a313:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
      param_3 = (GUID *)&WPP_9608820f130d35da1284a1080d801204_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_9608820f130d35da1284a1080d801204_Traceguids,uVar6);
    }
    if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
      McTemplateK0qq_EtwWriteTransfer
                (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_UNKNOWN_INTERFACE,param_3,
                 0xffffffff,(char)*param_1);
    }
LAB_1c000a37d:
    uVar12 = 0xc0000010;
    uVar14 = 0xb;
    goto LAB_1c000a387;
  }
  uVar14 = 9;
  if (uVar6 == 2) {
    if ((param_1[5] != 4) && (param_1[5] != 0x10)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((1 < (byte)WPP_GLOBAL_Control[0x29] &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)))) {
        param_3 = (GUID *)&WPP_9608820f130d35da1284a1080d801204_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                &WPP_9608820f130d35da1284a1080d801204_Traceguids);
      }
      uVar14 = 0xc;
      uVar12 = 0xc000000d;
      goto LAB_1c000a387;
    }
  }
  else if (uVar6 == 0xb) {
    lVar8 = *(longlong *)(param_1 + 1) + -0x490ee68b07374750;
    if (lVar8 == 0) {
      lVar8 = *(longlong *)(param_1 + 3) + 0x498e327a2860cf6d;
    }
    if (lVar8 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
        uVar11 = 0x12;
        goto LAB_1c0009d70;
      }
      goto LAB_1c000a37d;
    }
  }
  else if (uVar6 != 0xd) {
    if (uVar6 == 0xe) {
      lVar8 = *(longlong *)(param_1 + 1) + -0x4e04962993123211;
      if (lVar8 == 0) {
        lVar8 = *(longlong *)(param_1 + 3) + -0x6814224f2eeaf082;
      }
      if (lVar8 != 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
          uVar11 = 0x13;
LAB_1c0009d70:
          param_3 = (GUID *)&WPP_9608820f130d35da1284a1080d801204_Traceguids;
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
                  &WPP_9608820f130d35da1284a1080d801204_Traceguids);
        }
        goto LAB_1c000a37d;
      }
    }
    else {
      if (uVar6 != 0xf) goto LAB_1c000a313;
      lVar8 = *(longlong *)(param_1 + 1) + -0x4d88a0922ee2c70c;
      if (lVar8 == 0) {
        lVar8 = *(longlong *)(param_1 + 3) + 0x2aa39b283767ab5a;
      }
      if (lVar8 != 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
          uVar11 = 0x14;
          goto LAB_1c0009d70;
        }
        goto LAB_1c000a37d;
      }
    }
  }
  InterfaceGuid = (GUID *)(param_1 + 1);
  param_3 = (GUID *)&local_res10;
  TunnelGetTunnelFromGuid((longlong *)InterfaceGuid,(undefined8 *)local_res18,(ulonglong *)param_3);
  if ((local_res18 == (uchar  [8])0x0) && (local_res10 == (longlong *)0x0)) {
    uVar12 = TunnelGetTunnelInterfaceSize(*param_1);
    param_3 = (GUID *)0x49507554;
    plVar9 = (longlong *)ExAllocatePool2(0x40,uVar12 & 0xffffffff);
    if (plVar9 == (longlong *)0x0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
        param_3 = (GUID *)&WPP_9608820f130d35da1284a1080d801204_Traceguids;
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                &WPP_9608820f130d35da1284a1080d801204_Traceguids);
      }
      uVar14 = 0;
      uVar12 = 0xc000009a;
    }
    else {
      *(undefined4 *)(plVar9 + 8) = 1;
      plVar16 = plVar9 + 0x25;
      plVar9[0x26] = (longlong)plVar16;
      *plVar16 = (longlong)plVar16;
      plVar16 = plVar9 + 0x27;
      plVar9[0x28] = (longlong)plVar16;
      *plVar16 = (longlong)plVar16;
      plVar16 = plVar9 + 0x13;
      plVar9[0x14] = (longlong)plVar16;
      *plVar16 = (longlong)plVar16;
      plVar16 = plVar9 + 0x15;
      plVar9[0x16] = (longlong)plVar16;
      *plVar16 = (longlong)plVar16;
      *(uint *)(plVar9 + 0x17) = *(uint *)(plVar9 + 0x17) | 2;
      param_3 = InterfaceGuid;
      uVar5 = NdisLWMInitializeNetworkInterface(DAT_1c001a6e8,plVar9,InterfaceGuid,plVar9 + 7);
      uVar6 = NdisConvertNdisStatusToNtStatus(uVar5);
      uVar12 = (ulonglong)uVar6;
      if ((int)uVar6 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
          param_3 = (GUID *)&WPP_9608820f130d35da1284a1080d801204_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
                   &WPP_9608820f130d35da1284a1080d801204_Traceguids,uVar6);
        }
        uVar14 = 7;
      }
      else {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
          param_3 = (GUID *)&WPP_9608820f130d35da1284a1080d801204_Traceguids;
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                   &WPP_9608820f130d35da1284a1080d801204_Traceguids,uVar6);
        }
        uVar6 = ConvertInterfaceGuidToLuid(InterfaceGuid,(PNET_LUID)(plVar9 + 6));
        uVar12 = (ulonglong)uVar6;
        if ((int)uVar6 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
            uVar11 = 0x1a;
LAB_1c000a064:
            param_3 = (GUID *)&WPP_9608820f130d35da1284a1080d801204_Traceguids;
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,
                     &WPP_9608820f130d35da1284a1080d801204_Traceguids,uVar6);
          }
        }
        else {
          InterfaceIndex = (PNET_IFINDEX)(plVar9 + 5);
          uVar6 = ConvertInterfaceLuidToIndex((NET_LUID *)(plVar9 + 6),InterfaceIndex);
          uVar12 = (ulonglong)uVar6;
          if (-1 < (int)uVar6) {
            uVar6 = *param_1;
            puVar10 = (undefined4 *)TunnelGetTunnelTypeParameters(uVar6,param_1[5]);
            if (puVar10 == (undefined4 *)0x0) {
              uVar12 = 0xc0000001;
              uVar14 = 5;
            }
            else {
              *(uint *)(plVar9 + 3) = uVar6;
              *(undefined4 *)(plVar9 + 0xb) = *puVar10;
              *(undefined4 *)((longlong)plVar9 + 0xfc) = puVar10[1];
              local_res10 = *(longlong **)(puVar10 + 2);
              plVar9[2] = (longlong)local_res10;
              plVar9[4] = *(longlong *)(puVar10 + 4);
              *(undefined4 *)((longlong)plVar9 + 0x5c) = 0;
              plVar9[0xd] = 100000;
              lVar8 = *(longlong *)(param_1 + 3);
              plVar9[0x21] = *(longlong *)InterfaceGuid;
              plVar9[0x22] = lVar8;
              TunnelInitNetworkAddress((longlong)plVar9);
              uVar6 = (**(code **)(plVar9[4] + 0x10))(plVar9,param_1);
              uVar12 = (ulonglong)uVar6;
              if (uVar6 == 0) {
                bVar4 = true;
                iVar7 = TunnelInitSetGeneralAttributes(plVar9[7],(longlong)plVar9);
                uVar6 = NdisConvertNdisStatusToNtStatus(iVar7);
                uVar12 = (ulonglong)uVar6;
                if ((int)uVar6 < 0) {
                  uVar14 = 1;
                }
                else {
                  *(undefined4 *)(plVar9 + 0xc) = 0x20;
                  uVar5 = NdisLWMStartNetworkInterface(plVar9[7]);
                  uVar6 = NdisConvertNdisStatusToNtStatus(uVar5);
                  uVar12 = (ulonglong)uVar6;
                  if (-1 < (int)uVar6) {
                    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
                      WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,param_3,
                                 *InterfaceIndex,(char)plVar9[3],(char)uVar6);
                    }
                    plVar16 = local_res10;
                    RtlAcquireWriteLock((longlong)(local_res10 + 3));
                    puVar13 = auStackY_88;
                    lVar8 = *plVar16;
                    if (*(longlong **)(lVar8 + 8) != plVar16) {
                      pcVar3 = (code *)swi(0x29);
                      lVar8 = (*pcVar3)(3);
                      puVar13 = auStackY_80;
                    }
                    *plVar9 = lVar8;
                    plVar9[1] = (longlong)plVar16;
                    *(longlong **)(lVar8 + 8) = plVar9;
                    *plVar16 = (longlong)plVar9;
                    *(undefined8 *)(puVar13 + -8) = 0x1c000a255;
                    KeReleaseInStackQueuedSpinLock(&local_58);
                    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
                      UVar1 = *InterfaceIndex;
                      uVar2 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
                      *(int *)(puVar13 + 0x20) = (int)plVar9[3];
                      *(undefined8 *)(puVar13 + -8) = 0x1c000a28a;
                      WPP_SF_DD(uVar2,0x1e,param_3,UVar1,puVar13[0x20]);
                    }
                    if ((DAT_1c0017024 != 0) &&
                       ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
                      lVar8 = plVar9[3];
                      *(ULONG *)(puVar13 + 0x20) = *InterfaceIndex;
                      *(undefined8 *)(puVar13 + -8) = 0x1c000a2b9;
                      McTemplateK0qq_EtwWriteTransfer
                                (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,
                                 &EVENT_TUNNEL_MINIPORT_INITIALIZED,param_3,(int)lVar8,puVar13[0x20]
                                );
                    }
                    uVar6 = *(uint *)(plVar9 + 3);
                    *(undefined8 *)(puVar13 + -8) = 0x1c000a2c7;
                    TunnelTelemetryMiniportInitialization((ulonglong)uVar6,0xffffffff,uVar12);
                    return 0;
                  }
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
                    WPP_SF_DDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,param_3,
                               *InterfaceIndex,(char)plVar9[3],(char)uVar6);
                  }
                  uVar14 = 8;
                }
              }
              else {
                uVar14 = 6;
              }
            }
            goto LAB_1c000a30d;
          }
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
            uVar11 = 0x1b;
            goto LAB_1c000a064;
          }
        }
        uVar14 = 10;
      }
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((1 < (byte)WPP_GLOBAL_Control[0x29] && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)
        ))) {
      param_3 = (GUID *)&WPP_9608820f130d35da1284a1080d801204_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
              &WPP_9608820f130d35da1284a1080d801204_Traceguids);
    }
    uVar12 = 0xc0000510;
  }
LAB_1c000a30d:
  plVar16 = local_res10;
LAB_1c000a387:
  if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
    McTemplateK0qqq_EtwWriteTransfer
              (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_MINIPORT_INIT_FAILED,param_3,
               *param_1,(char)uVar12,(char)uVar14);
  }
  uVar15 = uVar12;
  TunnelTelemetryMiniportInitialization((ulonglong)*param_1,uVar14,uVar12);
  if (plVar9 != (longlong *)0x0) {
    if (bVar4) {
      RtlAcquireWriteLock((longlong)(plVar16 + 3));
      (**(code **)(plVar9[4] + 8))(plVar9,&local_58);
      KeReleaseInStackQueuedSpinLock(&local_58);
    }
    if (plVar9[7] != 0) {
      NdisLWMUninitializeNetworkInterface();
      plVar9[7] = 0;
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
        WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,uVar15,(int)plVar9[5],
                  (char)plVar9[3]);
      }
    }
    ExFreePoolWithTag(plVar9,0x49507554);
  }
  return uVar12;
}



===== TunnelInitNetworkAddress @ 1c000a488 =====

void TunnelInitNetworkAddress(longlong param_1)

{
  uint *puVar1;
  uint local_res8 [2];
  int local_res10 [2];
  longlong local_res18;
  void *local_res20;
  
  local_res8[0] = 0;
  local_res18 = 0;
  local_res20 = (void *)0x0;
  local_res10[0] =
       TunnelInitOpenNdisConfiguration
                 (*(undefined8 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x28),
                  (undefined *)&local_res18);
  if (local_res10[0] < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(undefined4 *)(param_1 + 0x28));
    }
  }
  else {
    puVar1 = local_res8;
    NdisReadNetworkAddress(local_res10,&local_res20,puVar1,local_res18);
    if ((local_res10[0] == 0) && (local_res8[0] == *(int *)(param_1 + 0xfc) + 8U)) {
      memcpy((void *)(param_1 + 0xbc),local_res20,(ulonglong)local_res8[0]);
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((2 < (byte)WPP_GLOBAL_Control[0x29] &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)))) {
        puVar1 = (uint *)&WPP_9608820f130d35da1284a1080d801204_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                 &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(undefined4 *)(param_1 + 0x28));
      }
      if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
        McTemplateK0qqq_EtwWriteTransfer
                  (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_READ_ERROR,puVar1,
                   *(undefined4 *)(param_1 + 0x28),(char)local_res10[0],4);
      }
    }
  }
  *(undefined4 *)(param_1 + 0xc0) = 0xe0000000;
  if (local_res18 != 0) {
    NdisCloseConfiguration();
  }
  return;
}



===== TeredoWfpDuplicateControlData @ 1c000a5f0 =====

undefined8 TeredoWfpDuplicateControlData(longlong param_1,longlong param_2)

{
  void *_Dst;
  undefined8 uVar1;
  
  uVar1 = 0;
  if (*(longlong *)(param_2 + 0x80) != 0) {
    _Dst = (void *)ExAllocatePool2(0x42,*(undefined4 *)(param_2 + 0x88),0x64437754);
    *(void **)(param_1 + 0x48) = _Dst;
    if (_Dst == (void *)0x0) {
      uVar1 = 0xc000009a;
    }
    else {
      memcpy(_Dst,*(void **)(param_2 + 0x80),(ulonglong)*(uint *)(param_2 + 0x88));
      *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_2 + 0x88);
    }
  }
  return uVar1;
}



===== TeredoWfpRemoveFilters @ 1c000a674 =====

void TeredoWfpRemoveFilters(void)

{
  if (DAT_1c001a0f0 != 0) {
    if (DAT_1c001a0d8 != 0) {
      FwpmFilterDeleteById0();
      DAT_1c001a0d8 = 0;
    }
    if (DAT_1c001a0c8 != 0) {
      FwpmFilterDeleteById0(DAT_1c001a0f0);
      DAT_1c001a0c8 = 0;
    }
    if (DAT_1c001a0d0 != 0) {
      FwpmFilterDeleteById0(DAT_1c001a0f0);
      DAT_1c001a0d0 = 0;
    }
    FwpmCalloutDeleteById0(DAT_1c001a0f0,TwCalloutIdV4);
    FwpmCalloutDeleteById0(DAT_1c001a0f0,DAT_1c001a0e8);
  }
  return;
}



===== TunnelInsertPotentialRouterForTunnel @ 1c000a734 =====

undefined8 TunnelInsertPotentialRouterForTunnel(longlong param_1,int *param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 uVar6;
  
  uVar6 = 0;
  uVar2 = TunnelIsPotentialRouterAssociatedWithTunnel(param_1,*param_2);
  if ((char)uVar2 == '\0') {
    plVar3 = (longlong *)ExAllocatePool2(0x40,0x18,0x52507554);
    if (plVar3 == (longlong *)0x0) {
      uVar6 = 0xc000009a;
    }
    else {
      *(int *)(plVar3 + 2) = *param_2;
      lVar4 = param_1 + 0xa8;
      plVar5 = *(longlong **)(param_1 + 0xb0);
      if (*plVar5 != lVar4) {
        plVar3 = (longlong *)0x3;
        pcVar1 = (code *)swi(0x29);
        lVar4 = (*pcVar1)();
      }
      *plVar3 = lVar4;
      plVar3[1] = (longlong)plVar5;
      *plVar5 = (longlong)plVar3;
      *(longlong **)(lVar4 + 8) = plVar3;
    }
  }
  return uVar6;
}



===== TeredoInitializeWorkQueues @ 1c000a7c0 =====

ulonglong TeredoInitializeWorkQueues(longlong param_1)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  
  uVar2 = 0;
  for (iVar3 = 0; iVar3 < 0x40; iVar3 = iVar3 + 1) {
    uVar1 = LwInitializeQueue(*(longlong *)(param_1 + 0x120),
                              (longlong *)(&DAT_1c0018a20 + (longlong)iVar3 * 0x58),0x1c0007d20);
    uVar2 = uVar1 & 0xffffffff;
    if ((int)uVar1 < 0) goto LAB_1c000a83e;
  }
  iVar3 = 0;
  while( true ) {
    if (0x3f < iVar3) {
      return uVar2;
    }
    uVar1 = LwInitializeQueue(*(longlong *)(param_1 + 0x120),
                              (longlong *)(&DAT_1c0017420 + (longlong)iVar3 * 0x58),0x1c00078f0);
    uVar2 = uVar1 & 0xffffffff;
    if ((int)uVar1 < 0) break;
    iVar3 = iVar3 + 1;
  }
LAB_1c000a83e:
  TeredoUninitializeWorkQueues();
  return uVar2;
}



===== WPP_SF_qD @ 1c000a85c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9608820f130d35da1284a1080d801204_Traceguids,0x2d,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_DDD @ 1c000a8b8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9608820f130d35da1284a1080d801204_Traceguids,param_2,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== TunnelUserCreateFile @ 1c000a920 =====

int TunnelUserCreateFile(undefined8 param_1,longlong param_2,undefined1 *param_3)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x20);
  *param_3 = 0;
  if ((*(uint *)(lVar1 + 0xb8) & 0x20) == 0) {
    KeInitializeEvent(lVar1 + 0x1f0,0,0);
    if ((*(uint *)(lVar1 + 0xb8) & 4) != 0) {
      iVar2 = -0x3ffffe7c;
      goto LAB_1c000a99f;
    }
    *(undefined8 *)(lVar1 + 0x178) = 0;
    *(uint *)(lVar1 + 0xb8) = *(uint *)(lVar1 + 0xb8) | 0x20;
  }
  else if (DAT_1c001aa19 == '\0') {
    return -0x3fffffc8;
  }
  iVar2 = 0;
  if (*(int *)(lVar1 + 0x18) != 0xe) {
    *param_3 = 1;
  }
LAB_1c000a99f:
  if ((DAT_1c001aa19 != '\0') && (iVar2 == 0)) {
    LOCK();
    DAT_1c001a0f8 = DAT_1c001a0f8 + 1;
    UNLOCK();
  }
  return iVar2;
}



===== TunnelDriverDispatchCreate @ 1c000a9d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 TunnelDriverDispatchCreate(longlong param_1,longlong param_2)

{
  longlong lVar1;
  bool bVar2;
  undefined4 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong *plVar6;
  uint uVar7;
  char local_res8 [8];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  lVar4 = 0;
  local_res8[0] = '\0';
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  if (param_1 == DAT_1c001a6d8) {
    uVar3 = 0;
    LOCK();
    DAT_1c001a6e0 = DAT_1c001a6e0 + 1;
    UNLOCK();
  }
  else {
    uVar7 = 0;
    plVar6 = &DAT_1c001a718;
    do {
      RtlAcquireWriteLock((longlong)(plVar6 + -2));
      bVar2 = true;
      if (*(code **)(*plVar6 + 0x10) != (code *)0x0) {
        lVar4 = (**(code **)(*plVar6 + 0x10))(plVar6 + -5,param_1);
        if (lVar4 != 0) goto LAB_1c000aa8c;
      }
      KeReleaseInStackQueuedSpinLock(&local_48);
      bVar2 = false;
      uVar7 = uVar7 + 1;
      plVar6 = plVar6 + 0xe;
    } while (uVar7 < 5);
    if (lVar4 == 0) {
      uVar3 = 0xc0000225;
    }
    else {
LAB_1c000aa8c:
      *(undefined8 *)(*(longlong *)(lVar1 + 0x30) + 0x18) = 0x556e7554;
      *(longlong *)(*(longlong *)(lVar1 + 0x30) + 0x20) = lVar4;
      uVar3 = (**(code **)(*(longlong *)(lVar4 + 0x20) + 0x78))(param_1,param_2,local_res8);
      if (local_res8[0] != '\0') {
        uVar5 = RoReferenceEx((uint *)(lVar4 + 0x40),1);
        if ((char)uVar5 == '\0') {
          local_res8[0] = '\0';
        }
      }
      if (bVar2) {
        KeReleaseInStackQueuedSpinLock(&local_48);
      }
      if (local_res8[0] != '\0') {
        TunnelIndicateStatus(lVar4,1,*(undefined8 *)(lVar4 + 0x68));
        TunnelInterfaceDereferenceExImp(lVar4,1,(undefined *)0x0);
      }
    }
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = uVar3;
  IofCompleteRequest(param_2,0);
  return uVar3;
}



===== TunnelTeredoReclaimInactiveFlows @ 1c000ab60 =====

void TunnelTeredoReclaimInactiveFlows(longlong param_1,undefined8 param_2,ulonglong param_3)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong lVar4;
  bool bVar5;
  
  lVar4 = *(longlong *)(param_1 + 0x2c0);
  if (DAT_1c0017360 != 0) {
    uVar3 = 1;
    uVar2 = RoReferenceEx((uint *)&DAT_1c001a120,1);
    if ((char)uVar2 != '\0') {
      TeredoWfpReclaimEntriesInAllBuckets(lVar4 + -0x1e,uVar3,param_3);
      LOCK();
      iVar1 = DAT_1c001a120 + -2;
      UNLOCK();
      bVar5 = DAT_1c001a120 == 3;
      DAT_1c001a120 = iVar1;
      if (bVar5) {
        KeSetEvent(&HashTableUninitializedEvent,0,0);
      }
    }
  }
  return;
}



===== TunnelUserHaltTunnel @ 1c000abd0 =====

void TunnelUserHaltTunnel(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined *puVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  
  uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x118);
  TunnelUserCancelPendingReads(param_1);
  KeReleaseSpinLock(param_1 + 0x118,uVar3);
  TunnelUserFreePacketPools(param_1);
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 4;
  uVar1 = *(uint *)(param_1 + 0xb8);
  uVar2 = *(uint *)(param_1 + 0x2c8);
  KeReleaseInStackQueuedSpinLock(param_2);
  if ((uVar2 & 0x10) != 0) {
    KeWaitForSingleObject(param_1 + 0x208,0,0,0,0);
  }
  RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10) + 0x18);
  if ((*(uint *)(param_1 + 0x2c8) & 8) == 0) {
    KeReleaseInStackQueuedSpinLock(param_2);
  }
  else {
    *(uint *)(param_1 + 0x2c8) = *(uint *)(param_1 + 0x2c8) & 0xfffffff7;
    KeReleaseInStackQueuedSpinLock();
    LOCK();
    *(int *)(param_1 + 0x220) = *(int *)(param_1 + 0x220) + -1;
    UNLOCK();
    TunnelTeredoWfpDereference(param_1);
    puVar4 = (undefined *)(param_1 + 0x228);
    uVar6 = 0;
    uVar5 = 0;
    KeWaitForSingleObject();
    TeredoUnregisterWithWfp(puVar4,uVar5,uVar6);
  }
  if ((uVar1 & 0x20) != 0) {
    KeWaitForSingleObject(param_1 + 0x1f0,0,0,0,0);
  }
  TunnelUserFreeWorkItem(param_1);
  TunnelUserDestroyDevice(param_1);
  RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10) + 0x18);
  return;
}



===== TunnelUserFreeWorkItem @ 1c000ad44 =====

void TunnelUserFreeWorkItem(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x1c8) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(param_1 + 0x1c8) = 0;
  }
  return;
}



===== TunnelUserFreePacketPools @ 1c000ad7c =====

void TunnelUserFreePacketPools(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x160) != 0) {
    NdisFreeNetBufferListPool();
    *(undefined8 *)(param_1 + 0x160) = 0;
  }
  if (*(longlong *)(param_1 + 0x158) != 0) {
    NdisFreeNetBufferListPool();
    *(undefined8 *)(param_1 + 0x158) = 0;
  }
  return;
}



===== TunnelUserDestroyDevice @ 1c000add4 =====

void TunnelUserDestroyDevice(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x120) != 0) {
    IoDeleteSymbolicLink(*(undefined8 *)(param_1 + 0x2d8));
    *(undefined8 *)(param_1 + 0x2d8) = 0;
    IoDeleteDevice(*(undefined8 *)(param_1 + 0x120));
    *(undefined8 *)(param_1 + 0x120) = 0;
  }
  return;
}



===== TeredoUnregisterWithWfp @ 1c000ae2c =====

void TeredoUnregisterWithWfp(undefined *param_1,undefined8 param_2,ulonglong param_3)

{
  bool bVar1;
  
  DAT_1c001a028 = 0;
  DAT_1c001a030 = 0;
  TeredoUninitializeWorkQueues();
  LOCK();
  bVar1 = TwUdpHeaderPoolInitialized == 1;
  if (bVar1) {
    TwUdpHeaderPoolInitialized = 0;
  }
  UNLOCK();
  if (bVar1) {
    param_1 = &TwUdpHeaderPool;
    ExDeleteNPagedLookasideList();
  }
  TeredoWfpRemoveFilters();
  TeredoUninitializeHashTable(param_1,param_2,param_3);
  TeredoWfpUnregisterCallouts();
  DAT_1c001a0c0 = 0;
  return;
}



===== TeredoWfpUnregisterCallouts @ 1c000ae88 =====

void TeredoWfpUnregisterCallouts(void)

{
  if (DAT_1c001a0f0 != 0) {
    FwpmSubLayerDeleteByKey0(DAT_1c001a0f0,&TEREDO_WFP_SUBLAYER);
    FwpmProviderDeleteByKey0(DAT_1c001a0f0,&TeredoWfpProviderGuid);
    FwpmEngineClose0(DAT_1c001a0f0);
    DAT_1c001a0f0 = 0;
    FwpsCalloutUnregisterById0(TwCalloutIdV4);
    FwpsCalloutUnregisterById0(DAT_1c001a0e8);
    TwCalloutIdV4 = 0;
    DAT_1c001a0e8 = 0;
  }
  if (DAT_1c001a0e0 != 0) {
    FwpsInjectionHandleDestroy0();
    DAT_1c001a0e0 = 0;
  }
  return;
}



===== TeredoUninitializeHashTable @ 1c000af40 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TeredoUninitializeHashTable(undefined8 param_1,undefined8 param_2,ulonglong param_3)

{
  int iVar1;
  bool bVar2;
  
  if (DAT_1c0017360 != 0) {
    LOCK();
    iVar1 = DAT_1c001a120 + -1;
    UNLOCK();
    bVar2 = DAT_1c001a120 == 2;
    DAT_1c001a120 = iVar1;
    if (bVar2) {
      param_3 = 0;
      param_2 = 0;
      KeSetEvent();
    }
    TeredoWfpReclaimEntriesInAllBuckets(0,param_2,param_3);
    KeWaitForSingleObject(&HashTableUninitializedEvent,0,0,0,0);
    if (DAT_1c0017360 != 0) {
      ExFreePoolWithTag(DAT_1c0017360,0x74487754);
      DAT_1c0017360 = 0;
    }
    _DAT_1c0017340 = 0;
  }
  return;
}



===== TunnelMiniportHaltLWM @ 1c000afdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
TunnelMiniportHaltLWM(longlong *param_1,longlong param_2,undefined *param_3,ulonglong param_4)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  NdisLWMUninitializeNetworkInterface(param_1[7]);
  param_1[7] = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)
     ) {
    param_4 = (ulonglong)*(uint *)(param_1 + 5);
    param_3 = &WPP_9608820f130d35da1284a1080d801204_Traceguids;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
             &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(uint *)(param_1 + 5));
  }
  if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
    param_4 = (ulonglong)*(uint *)(param_1 + 3);
    McTemplateK0qqq_EtwWriteTransfer
              (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_OP,param_3,
               *(uint *)(param_1 + 3),(char)param_1[5],0);
  }
  KeAcquireInStackQueuedSpinLock(param_2 + 0x18,&local_28);
  do {
  } while (*(int *)(param_2 + 0x20) != 0);
  TunnelRemoveAllPhysicalInterfaceAssociationForTunnel((longlong)param_1);
  TunnelRemoveAllPotentialRoutersForTunnel((longlong)param_1);
  if (*(longlong **)(param_2 + 0x68) == param_1) {
    *(longlong *)(param_2 + 0x68) = *param_1;
  }
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) == param_1) &&
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 == param_1)) {
    *plVar2 = lVar1;
    puVar5 = &local_28;
    *(longlong **)(lVar1 + 8) = plVar2;
    (**(code **)(param_1[4] + 8))(param_1);
    KeReleaseInStackQueuedSpinLock(&local_28);
    TunnelTelemetryMiniportHalt((longlong)param_1,puVar5,param_3,param_4);
    ExFreePoolWithTag(param_1,0x49507554);
    return 0;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  uVar4 = (*pcVar3)();
  return uVar4;
}



===== TunnelTelemetryMiniportHalt @ 1c000b13c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TunnelTelemetryMiniportHalt
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined1 auStackY_a8 [32];
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70 [2];
  undefined8 local_68 [4];
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  if (5 < DAT_1c0017050) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_78 = *(undefined4 *)(param_1 + 0x18);
      local_48 = &local_78;
      local_74 = *(undefined4 *)(param_1 + 0x70);
      local_38 = &local_74;
      local_70[0] = *(undefined4 *)(param_1 + 0x74);
      local_28 = local_70;
      local_40 = 4;
      local_30 = 4;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c0014f11,param_3,param_4,5,local_68);
    }
  }
  return;
}



===== TunnelRemoveAllPhysicalInterfaceAssociationForTunnel @ 1c000b1e8 =====

void TunnelRemoveAllPhysicalInterfaceAssociationForTunnel(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  
  plVar2 = (longlong *)(param_1 + 0x98);
  while( true ) {
    plVar3 = (longlong *)*plVar2;
    if (plVar3 == plVar2) {
      return;
    }
    if (((longlong *)plVar3[1] != plVar2) ||
       (lVar4 = *plVar3, (longlong *)*(longlong *)(lVar4 + 8) != plVar3)) break;
    *plVar2 = lVar4;
    plVar1 = plVar3 + 3;
    *(longlong **)(lVar4 + 8) = plVar2;
    while (plVar5 = (longlong *)*plVar1, plVar5 != plVar1) {
      if (((longlong *)plVar5[1] != plVar1) ||
         (lVar4 = *plVar5, (longlong *)*(longlong *)(lVar4 + 8) != plVar5)) goto LAB_1c000b299;
      *plVar1 = lVar4;
      *(longlong **)(lVar4 + 8) = plVar1;
      if (plVar5[3] != 0) {
        TunnelNlDereferenceLocalAddressObject
                  ((undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x38),plVar5[3]);
        plVar5[3] = 0;
      }
      ExFreePoolWithTag(plVar5,0x34567554);
    }
    ExFreePoolWithTag(plVar3,0x69507554);
  }
LAB_1c000b299:
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  return;
}



===== TunnelRemoveAllPotentialRoutersForTunnel @ 1c000b2c4 =====

void TunnelRemoveAllPotentialRoutersForTunnel(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  
  plVar1 = (longlong *)(param_1 + 0xa8);
  while( true ) {
    plVar2 = (longlong *)*plVar1;
    if (plVar2 == plVar1) {
      return;
    }
    if (((longlong *)plVar2[1] != plVar1) ||
       (lVar3 = *plVar2, (longlong *)*(longlong *)(lVar3 + 8) != plVar2)) break;
    *plVar1 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar1;
    ExFreePoolWithTag(plVar2,0x52507554);
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  return;
}



===== TunnelNlcAddAddressNotification @ 1c000b320 =====

void TunnelNlcAddAddressNotification(undefined8 *param_1)

{
  TunnelNlAddAddressNotificationHelper((undefined8 *)*param_1,param_1[1]);
  return;
}



===== TunnelNlAddAddressNotificationHelper @ 1c000b33c =====

void TunnelNlAddAddressNotificationHelper(undefined8 *param_1,longlong param_2)

{
  undefined8 *puVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  puVar1 = param_1 + -7;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  KeAcquireInStackQueuedSpinLock(param_1 + -4,&local_38);
  do {
  } while (*(int *)(param_1 + -3) != 0);
  puVar6 = (undefined8 *)*puVar1;
  do {
    if (puVar6 == puVar1) {
      KeReleaseInStackQueuedSpinLock(&local_38);
      return;
    }
    if (puVar6[0x20] == 0) {
      if (param_2 != 0) {
        iVar2 = memcmp((void *)**(undefined8 **)(param_2 + 0x10),(void *)((longlong)puVar6 + 0xc4),
                       (ulonglong)*(uint *)((longlong)puVar6 + 0xfc));
        if (iVar2 != 0) goto LAB_1c000b43f;
      }
      lVar3 = TunnelNlReferenceLocalAddressByDlAddress
                        (param_1,(undefined4 *)((longlong)puVar6 + 0xbc));
      puVar6[0x20] = lVar3;
      if (lVar3 != 0) {
        uVar4 = RoReferenceEx((uint *)(puVar6 + 8),1);
        if ((char)uVar4 != '\0') {
          uVar5 = TunnelUpdateLinkSpeed((longlong)puVar6,&local_38);
          KeReleaseInStackQueuedSpinLock(&local_38);
          TunnelIndicateStatus((longlong)puVar6,1,uVar5);
          RtlAcquireWriteLock((longlong)(param_1 + -4));
          TunnelInterfaceDereferenceExImp
                    ((longlong)puVar6,1,(undefined *)CONCAT71((int7)((ulonglong)uVar5 >> 8),1));
          puVar6 = (undefined8 *)*puVar1;
        }
      }
    }
LAB_1c000b43f:
    puVar6 = (undefined8 *)*puVar6;
  } while( true );
}



===== TeredoWfpRegisterDdLayerCallouts @ 1c000b480 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TeredoWfpRegisterDdLayerCallouts(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStackY_e8 [32];
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 local_94;
  code *local_90;
  code *local_88;
  code *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  wchar_t *local_68;
  wchar_t *local_60;
  undefined8 local_58;
  undefined *local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_94 = 0;
  local_98 = 0x200;
  local_58 = 0;
  local_28 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_90 = TeredoWfpDdLayerClassify;
  local_88 = TunnelUserMapIcmpStub;
  local_80 = TeredoWfpDdLayerDelete;
  local_a8 = 0x3ffa7b0d;
  uStack_a4 = 0x401143c3;
  uStack_a0 = 0xa2fe11ab;
  uStack_9c = 0xbde7bf46;
  iVar1 = FwpsCalloutRegister0(param_3,&local_a8,&TwCalloutIdV4);
  if (-1 < iVar1) {
    local_68 = L"Teredo Datagram Data Layer Callout";
    local_78 = 0x401143c33ffa7b0d;
    uStack_70 = 0xbde7bf46a2fe11ab;
    uVar2 = 0;
    local_60 = L"Intercepts tunneled UDPv4 Teredo traffic";
    local_38 = 0x3d08bf4e;
    uStack_34 = 0x493045f6;
    uStack_30 = 0x704122a9;
    uStack_2c = 0x2700e298;
    local_50 = &TeredoWfpProviderGuid;
    iVar1 = FwpmCalloutAdd0(DAT_1c001a0f0,&local_78,0);
    if (-1 < iVar1) {
      iVar1 = TeredoWfpAddFilter(L"Teredo Datagram Data Layer Filter (inbound)",
                                 L"Intercepts and fast-tracks inbound tunneled UDPv4 Teredo traffic"
                                 ,1,uVar2,(undefined8 *)&FWPM_LAYER_DATAGRAM_DATA_V4,
                                 (undefined8 *)&TEREDO_WFP_CALLOUT_V4,&DAT_1c001a0d8);
      if (-1 < iVar1) {
        return iVar1;
      }
      FwpmCalloutDeleteById0(DAT_1c001a0f0,TwCalloutIdV4);
    }
    FwpsCalloutUnregisterById0(TwCalloutIdV4);
    TwCalloutIdV4 = 0;
  }
  return iVar1;
}



===== TeredoWfpRegisterAleLayerCallouts @ 1c000b608 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TeredoWfpRegisterAleLayerCallouts(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStackY_e8 [32];
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 local_94;
  code *local_90;
  code *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  wchar_t *local_68;
  wchar_t *local_60;
  undefined8 local_58;
  undefined *local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_94 = 0;
  local_80 = 0;
  local_58 = 0;
  local_28 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_90 = TeredoWfpAleLayerClassify;
  local_98 = 0x200;
  local_88 = TeredoWfpAleLayerNotify;
  local_a8 = 0xdc65b81;
  uStack_a4 = 0x404edf58;
  uStack_a0 = 0x936130b8;
  uStack_9c = 0xb1feef04;
  iVar1 = FwpsCalloutRegister0(param_3,&local_a8,&DAT_1c001a0e8);
  if (-1 < iVar1) {
    local_68 = L"Teredo Flow-Established Callout";
    local_78 = 0x404edf580dc65b81;
    uStack_70 = 0xb1feef04936130b8;
    uVar2 = 0;
    local_60 = L"Intercepts flow creations for Teredo UDPv4 flows";
    local_38 = 0xaf80470a;
    uStack_34 = 0x4c135596;
    uStack_30 = 0x9e539299;
    uStack_2c = 0x6779e56f;
    local_50 = &TeredoWfpProviderGuid;
    iVar1 = FwpmCalloutAdd0(DAT_1c001a0f0,&local_78,0);
    if (-1 < iVar1) {
      iVar1 = TeredoWfpAddFilter(L"Teredo Flow-Established Filter (inbound)",
                                 L"Intercepts inbound tunneled UDPv4 Teredo flow creations",1,uVar2,
                                 (undefined8 *)&FWPM_LAYER_ALE_FLOW_ESTABLISHED_V4,
                                 (undefined8 *)&TEREDO_WFP_FLOW_ESTABLISHED_CALLOUT_V4,
                                 &DAT_1c001a0c8);
      if (-1 < iVar1) {
        iVar1 = TeredoWfpAddFilter(L"Teredo Flow-Established Filter  (outbound)",
                                   L"Intercepts outbound tunneled UDPv4 Teredo flow creations",0,
                                   uVar2,(undefined8 *)&FWPM_LAYER_ALE_FLOW_ESTABLISHED_V4,
                                   (undefined8 *)&TEREDO_WFP_FLOW_ESTABLISHED_CALLOUT_V4,
                                   &DAT_1c001a0d0);
        if (-1 < iVar1) {
          return iVar1;
        }
        FwpmFilterDeleteById0(DAT_1c001a0f0,DAT_1c001a0c8);
      }
      FwpmCalloutDeleteById0(DAT_1c001a0f0,DAT_1c001a0e8);
    }
    FwpsCalloutUnregisterById0(DAT_1c001a0e8);
    DAT_1c001a0e8 = 0;
  }
  return iVar1;
}



===== TeredoWfpAddFilter @ 1c000b7ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TeredoWfpAddFilter(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                       undefined8 *param_5,undefined8 *param_6,undefined8 param_7)

{
  undefined1 auStack_1a8 [32];
  undefined1 local_188 [16];
  undefined8 local_178;
  undefined8 local_170;
  undefined *local_160;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined4 local_128;
  undefined4 local_118;
  undefined4 *local_110;
  undefined4 local_108;
  undefined8 local_104;
  undefined8 uStack_fc;
  undefined8 local_f0;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 local_a0;
  undefined4 local_98;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1a8;
  memset(local_188,0,200);
  memset(&local_b8,0,0x78);
  local_148 = *param_5;
  uStack_140 = param_5[1];
  local_160 = &TeredoWfpProviderGuid;
  local_110 = &local_b8;
  local_104 = *param_6;
  uStack_fc = param_6[1];
  local_108 = 0x5003;
  local_128 = 0;
  local_138 = 0x4d5818867bf26662;
  uStack_130 = 0xc5532ace7c50c485;
  local_f0 = 0;
  local_a8 = 0;
  local_a0 = 3;
  local_b8 = 0x8784c146;
  uStack_b4 = 0x44d6ca97;
  uStack_b0 = 0xfb19d19f;
  uStack_ac = 0xf7cb4018;
  local_118 = 1;
  local_178 = param_1;
  local_170 = param_2;
  local_98 = param_3;
  FwpmFilterAdd0(DAT_1c001a0f0,local_188,0,param_7);
  return;
}



===== TunnelConvertInterfaceIndexToLuid @ 1c000b914 =====

undefined8 TunnelConvertInterfaceIndexToLuid(undefined4 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined4 local_res8 [8];
  
  if (param_2 == (undefined8 *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    local_res8[0] = param_1;
    uVar1 = NsiGetParameter(1,&NPI_MS_NDIS_MODULEID,2,local_res8,4,2,param_2,8,0);
    if ((int)uVar1 < 0) {
      *param_2 = 0;
    }
  }
  return uVar1;
}



===== TunnelDereferenceDriver @ 1c000b984 =====

void TunnelDereferenceDriver(void)

{
  int iVar1;
  bool bVar2;
  
  LOCK();
  iVar1 = DAT_1c0017368 + -1;
  UNLOCK();
  bVar2 = DAT_1c0017368 == 1;
  DAT_1c0017368 = iVar1;
  if (bVar2) {
    KeSetEvent(&DAT_1c001a128,0,0);
  }
  return;
}



===== TunnelUserAllocatePacketPools @ 1c000b9bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 TunnelUserAllocatePacketPools(longlong param_1,undefined8 param_2,char param_3)

{
  longlong lVar1;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined8 local_3c;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 0x140180;
  local_44 = 0x100;
  local_40 = 0x624e7554;
  local_28 = 0x624e7554;
  local_3c = 0x5e8;
  local_30 = 0x140180;
  local_2c = 0x100;
  local_20 = 0;
  lVar1 = NdisAllocateNetBufferListPool(*(undefined8 *)(param_1 + 0x38),&local_48);
  *(longlong *)(param_1 + 0x158) = lVar1;
  if (lVar1 != 0) {
    if (param_3 == '\0') {
      return 0;
    }
    lVar1 = NdisAllocateNetBufferListPool(*(undefined8 *)(param_1 + 0x38),&local_30);
    *(longlong *)(param_1 + 0x160) = lVar1;
    if (lVar1 != 0) {
      return 0;
    }
  }
  TunnelUserFreePacketPools(param_1);
  return 0xc000009a;
}



===== TeredoWfpPrintV6Flow @ 1c000ba9c =====

void TeredoWfpPrintV6Flow(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  
  if (((param_1 != 0) && (DAT_1c0017024 != 0)) &&
     ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
    uVar1 = *(uint *)(param_1 + 0x24);
    McTemplateK0qqqbr0br0q_EtwWriteTransfer
              (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,
               (ulonglong)
               (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18),
               param_1,param_4,(char)((uint)*(undefined4 *)(param_1 + 0x20) >> 0x18),
               (char)(uVar1 >> 0x18),param_1,param_1 + 0x10);
  }
  return;
}



===== TunnelGetTunnelFromGuid @ 1c000baf4 =====

longlong TunnelGetTunnelFromGuid(longlong *param_1,undefined8 *param_2,ulonglong *param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  *param_2 = 0;
  *param_3 = 0;
  puVar5 = (undefined8 *)0x0;
  uVar4 = 0;
  do {
    iVar3 = (int)uVar4;
    puVar6 = &DAT_1c001a6f0 + uVar4 * 0xe;
    RtlAcquireWriteLock((longlong)(&DAT_1c001a708 + uVar4 * 0x70));
    for (puVar1 = (undefined8 *)*puVar6; puVar1 != puVar6; puVar1 = (undefined8 *)*puVar1) {
      lVar2 = puVar1[0x21] - *param_1;
      if (lVar2 == 0) {
        lVar2 = puVar1[0x22] - param_1[1];
      }
      if (lVar2 == 0) {
        iVar3 = 5;
        puVar5 = puVar1;
        break;
      }
      puVar5 = (undefined8 *)0x0;
    }
    KeReleaseInStackQueuedSpinLock();
    uVar4 = (ulonglong)(iVar3 + 1U);
    if (4 < iVar3 + 1U) {
      *param_2 = puVar5;
      *param_3 = -(ulonglong)(puVar5 != (undefined8 *)0x0) & (ulonglong)puVar6;
      return -(longlong)puVar5;
    }
  } while( true );
}



===== TunnelNlDereferenceLocalAddressObject @ 1c000bbdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TunnelNlDereferenceLocalAddressObject(undefined8 *param_1,undefined8 param_2)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = *param_1;
  local_30 = 0;
  uStack_28 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_20 = param_2;
  (**(code **)(param_1[1] + 0x98))(&local_38);
  return;
}



===== TunnelNlDereferenceNlBinding @ 1c000bc20 =====

void TunnelNlDereferenceNlBinding(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x60);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -2;
  UNLOCK();
  if (iVar2 == 3) {
    NmrClientDetachProviderComplete(*(undefined8 *)(param_1 + 0x48));
  }
  return;
}



===== TunnelNlcAttachNlProvider @ 1c000bc50 =====

ulonglong TunnelNlcAttachNlProvider(longlong param_1,longlong param_2,longlong param_3)

{
  ushort uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  longlong lVar6;
  bool bVar7;
  
  lVar2 = *(longlong *)(param_3 + 0x20);
  if ((lVar2 != 0) && ((uVar1 = *(ushort *)(lVar2 + 4), uVar1 == 2 || (uVar1 == 0x17)))) {
    uVar3 = (param_2 + -0x1c00130d0) / 0x48;
    uVar4 = (ulonglong)((int)uVar3 + (uVar1 & 1) * 2);
    lVar6 = uVar4 * 0x70;
    puVar5 = (undefined8 *)(&DAT_1c001a728 + lVar6);
    LOCK();
    bVar7 = *(longlong *)(&DAT_1c001a740 + lVar6) == 0;
    if (bVar7) {
      *(longlong *)(&DAT_1c001a740 + lVar6) = param_1;
    }
    UNLOCK();
    if (bVar7) {
      *(longlong *)(&DAT_1c001a748 + lVar6) = lVar2;
      uVar3 = NmrClientAttachProvider
                        (param_1,puVar5,&TunnelNlcDispatch + (uVar3 & 0xffffffff) * 0x98,puVar5,
                         lVar6 + 0x1c001a730);
      if ((int)uVar3 < 0) {
        *puVar5 = 0;
        *(undefined8 *)(lVar6 + 0x1c001a730) = 0;
        *(undefined8 *)(&DAT_1c001a738 + lVar6) = 0;
        *(undefined8 *)(&DAT_1c001a748 + lVar6) = 0;
        *(undefined8 *)(&DAT_1c001a740 + lVar6) = 0;
        return uVar3;
      }
      (&DAT_1c001a750)[uVar4 * 0x1c] = 2;
      TunnelNlAddAddressNotificationHelper(puVar5,0);
      return uVar3 & 0xffffffff;
    }
  }
  return 0xc00002b9;
}



===== TunnelTelemetryMiniportInitialization @ 1c000bd70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TunnelTelemetryMiniportInitialization(undefined8 param_1,uint param_2,undefined8 param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined1 auStackY_a8 [32];
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70 [2];
  undefined8 local_68 [4];
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  uVar2 = (ulonglong)param_2;
  if (5 < DAT_1c0017050) {
    uVar1 = _tlgKeywordOn();
    local_70[0] = (undefined4)param_3;
    if ((char)uVar1 != '\0') {
      local_48 = &local_78;
      local_78 = (undefined4)param_1;
      local_38 = &local_74;
      local_40 = 4;
      local_28 = local_70;
      local_74 = (undefined4)uVar2;
      local_30 = 4;
      local_20 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c0014f62,param_3,uVar2,5,local_68);
    }
  }
  return;
}



===== TunnelInitializeWorkQueue @ 1c000be18 =====

undefined8 TunnelInitializeWorkQueue(void)

{
  undefined8 uVar1;
  
  DAT_1c001a9b8 = IoAllocateWorkItem();
  if (DAT_1c001a9b8 == 0) {
    uVar1 = 0xc000009a;
  }
  else {
    DAT_1c001a9c8 = &DAT_1c001a9c0;
    DAT_1c001a9c0 = &DAT_1c001a9c0;
    KeInitializeSpinLock(&DAT_1c001a9d0);
    KeInitializeEvent(&DAT_1c001a9d8,0,1);
    uVar1 = 0;
    DAT_1c001aa18 = 0;
  }
  return uVar1;
}



===== TunnelIndicateStatus @ 1c000be90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TunnelIndicateStatus(longlong param_1,int param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined1 auStack_f8 [32];
  undefined4 local_c8 [2];
  undefined8 local_c0;
  undefined4 local_b4;
  undefined4 *local_98;
  undefined4 local_90;
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_f8;
  local_4c = 0;
  local_34 = 0;
  uVar1 = 0x70;
  memset(local_c8,0,0x70);
  local_58 = 0x280180;
  local_c8[0] = 0x700198;
  local_b4 = 0x40010017;
  local_50 = 0;
  if (param_2 == 1) {
    local_50 = 2;
  }
  local_90 = 0x28;
  local_38 = 0;
  local_c0 = *(undefined8 *)(param_1 + 0x38);
  local_98 = &local_58;
  local_54 = param_2;
  local_48 = param_3;
  local_40 = param_3;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)
     ) {
    WPP_SF_DD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,uVar1,*(undefined4 *)(param_1 + 0x28),
              (char)param_2);
  }
  if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
    McTemplateK0qq_EtwWriteTransfer
              (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_MEDIA_STATUS,uVar1,
               *(undefined4 *)(param_1 + 0x28),(char)param_2);
  }
  NdisMIndicateStatusEx(*(undefined8 *)(param_1 + 0x38),local_c8);
  return;
}



===== TunnelGetTunnelInterfaceSize @ 1c000bfb4 =====

undefined8 TunnelGetTunnelInterfaceSize(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((((param_1 == 2) || (param_1 == 0xb)) || (param_1 == 0xd)) ||
     ((param_1 == 0xe || (param_1 == 0xf)))) {
    uVar1 = 0x2e0;
  }
  return uVar1;
}



===== TunnelGetTunnelTypeParameters @ 1c000bfe0 =====

undefined * TunnelGetTunnelTypeParameters(int param_1,int param_2)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if (param_1 == 2) {
    puVar1 = &DAT_1c0013750;
    if (param_2 != 4) {
      puVar1 = &DAT_1c0013738;
    }
  }
  else if (param_1 == 0xb) {
    puVar1 = &DAT_1c0013780;
  }
  else if (param_1 == 0xd) {
    puVar1 = &DAT_1c0013768;
  }
  else if (param_1 == 0xe) {
    puVar1 = &DAT_1c0013708;
  }
  else if (param_1 == 0xf) {
    puVar1 = &DAT_1c0013720;
  }
  return puVar1;
}



===== TunnelUserGetPacketLength @ 1c000c040 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
TunnelUserGetPacketLength
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong *param_4)

{
  undefined8 uVar1;
  undefined1 auStack_78 [32];
  longlong *local_58;
  longlong local_48;
  ushort uStack_3c;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  local_58 = &local_48;
  RtlCopyMdlToBuffer(param_2,param_3,&stack0xffffffffffffffc0,0x28);
  if (local_48 == 0x28) {
    *param_4 = (ulonglong)(ushort)(uStack_3c >> 8 | uStack_3c << 8) + 0x28;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== TunnelUninitializeTimer @ 1c000c0dc =====

void TunnelUninitializeTimer(void)

{
  int iVar1;
  
  iVar1 = 1;
  LOCK();
  if (DAT_1c001a9b0 == 1) {
    DAT_1c001a9b0 = 0;
  }
  else {
    iVar1 = DAT_1c001a9b0;
  }
  UNLOCK();
  if (iVar1 != 0) {
    KeCancelTimer(&DAT_1c001a930);
    KeFlushQueuedDpcs();
  }
  return;
}



===== TunnelDriverDispatchClose @ 1c000c120 =====

undefined8 TunnelDriverDispatchClose(longlong param_1,longlong param_2)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == DAT_1c001a6d8) {
    LOCK();
    iVar1 = DAT_1c001a6e0 + -1;
    UNLOCK();
    bVar2 = DAT_1c001a6e0 == 1;
    DAT_1c001a6e0 = iVar1;
    if (bVar2) {
      KeEnterCriticalRegion();
      TunnelMiniportCleanupOrphanLWMs();
      KeLeaveCriticalRegion();
    }
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== TunnelSetInitialize @ 1c000c188 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TunnelSetInitialize(void)

{
  undefined8 *_Dst;
  undefined **ppuVar1;
  uint uVar2;
  undefined8 *puVar3;
  
  uVar2 = 0;
  ppuVar1 = &PTR_TunnelNlGetSourceAndDestinationV4_1c0013050;
  puVar3 = &DAT_1c001a720;
  do {
    _Dst = puVar3 + -6;
    memset(_Dst,0,0x70);
    *puVar3 = &DAT_1c001a6f0 + (ulonglong)((uVar2 & 1) * 2) * 0xe;
    KeInitializeSpinLock(puVar3 + -3);
    *(undefined4 *)(puVar3 + -2) = 0;
    puVar3[-5] = _Dst;
    *_Dst = _Dst;
    *(uint *)(puVar3 + -4) = uVar2;
    uVar2 = uVar2 + 1;
    puVar3[-1] = ppuVar1;
    ppuVar1 = ppuVar1 + 3;
    *(undefined4 *)(puVar3 + 6) = 1;
    puVar3 = puVar3 + 0xe;
  } while (uVar2 < 4);
  memset(&DAT_1c001a8b0,0,0x70);
  KeInitializeSpinLock(&DAT_1c001a8c8);
  _DAT_1c001a8d0 = 0;
  _DAT_1c001a8b8 = &DAT_1c001a8b0;
  _DAT_1c001a8b0 = &DAT_1c001a8b0;
  _DAT_1c001a8d8 = &PTR_TunnelUserGetSourceAndDestination_1c00130b0;
  _DAT_1c001a910 = 1;
  _DAT_1c001a8c0 = 4;
  return;
}



===== TunnelInitOpenNdisConfiguration @ 1c000c28c =====

int TunnelInitOpenNdisConfiguration(undefined8 param_1,undefined4 param_2,undefined *param_3)

{
  int iVar1;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  
  local_18 = 0;
  local_28 = 0x1801a9;
  local_20 = param_1;
  iVar1 = NdisOpenConfigurationEx(&local_28,param_3);
  if (iVar1 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (2 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
      param_3 = &WPP_9608820f130d35da1284a1080d801204_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_9608820f130d35da1284a1080d801204_Traceguids,param_2);
    }
    if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
      McTemplateK0qqq_EtwWriteTransfer
                (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_READ_ERROR,param_3,
                 param_2,(char)iVar1,0);
    }
  }
  return iVar1;
}



===== TunnelNlcDeleteAddressNotification @ 1c000c350 =====

void TunnelNlcDeleteAddressNotification(undefined8 *param_1)

{
  TunnelNlDeleteAddressNotificationHelper((undefined8 *)*param_1,param_1[1]);
  return;
}



===== TunnelInitializeDriver @ 1c000c36c =====

undefined8 TunnelInitializeDriver(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)(param_1 + 0x70);
  for (lVar1 = 0x1b; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = TunnelDriverDispatchUnsupported;
    puVar2 = puVar2 + 1;
  }
  *(code **)(param_1 + 0x70) = TunnelDriverDispatchCreate;
  *(code **)(param_1 + 0x80) = TunnelDriverDispatchClose;
  *(code **)(param_1 + 0x88) = TunnelDriverDispatchRead;
  *(code **)(param_1 + 0x90) = TunnelDriverDispatchWrite;
  *(code **)(param_1 + 0xe0) = TunnelDriverDispatchDevControl;
  *(code **)(param_1 + 0x100) = TunnelDriverDispatchCleanup;
  *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 8) = 0;
  *(code **)(param_1 + 0x68) = TunnelDriverUnload;
  return 0;
}



===== TunnelNlFindReceiver @ 1c000c3fc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong *
TunnelNlFindReceiver
          (longlong *param_1,undefined4 *param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined4 param_6)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  longlong *plVar4;
  undefined1 local_res8 [8];
  longlong *local_28 [2];
  
  local_28[0] = (longlong *)0x0;
  local_res8[0] = 0;
  iVar2 = TunnelNlGetIndexForLocalAddress((longlong)param_1,param_2,param_5);
  RtlAcquireReadLock((longlong)(param_1 + 3),local_res8);
  plVar4 = (longlong *)*param_1;
  if (plVar4 != param_1) {
    do {
      cVar1 = (**(code **)(plVar4[4] + 0x38))(plVar4,param_4,param_3,param_5,param_6);
      if (cVar1 != '\0') {
        TunnelNlUpdateBestTunnel(iVar2,(longlong)plVar4,(longlong *)local_28);
      }
      plVar4 = (longlong *)*plVar4;
    } while (plVar4 != param_1);
    if (local_28[0] != (longlong *)0x0) {
      uVar3 = RoReferenceEx((uint *)(local_28[0] + 8),1);
      local_28[0] = (longlong *)(-(ulonglong)((char)uVar3 != '\0') & (ulonglong)local_28[0]);
    }
  }
  LOCK();
  *(int *)(param_1 + 4) = (int)param_1[4] + -1;
  UNLOCK();
  KeLowerIrql(local_res8[0]);
  return local_28[0];
}



===== TunnelNlGetIndexForLocalAddress @ 1c000c4f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 TunnelNlGetIndexForLocalAddress(longlong param_1,undefined4 *param_2,undefined8 param_3)

{
  longlong lVar1;
  int iVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined8 local_10;
  
  lVar1 = *(longlong *)(param_1 + 0x30);
  uVar4 = 0;
  uVar3 = RoReferenceEx((uint *)(lVar1 + 0x60),1);
  if ((char)uVar3 != '\0') {
    local_30 = 0;
    local_24 = 0;
    uStack_20 = 0;
    local_1c = 0;
    local_14 = 0;
    local_38 = *(undefined8 *)(lVar1 + 0x38);
    local_28 = *param_2;
    local_18 = 0;
    local_10 = param_3;
    iVar2 = (**(code **)(*(longlong *)(lVar1 + 0x40) + 0x90))(&local_38);
    if (-1 < iVar2) {
      uVar4 = *(undefined4 *)(*(longlong *)(CONCAT44(local_1c,uStack_20) + 8) + 8);
      (**(code **)(*(longlong *)(lVar1 + 0x40) + 0x98))(&local_38);
    }
    TunnelNlDereferenceNlBinding(*(longlong *)(param_1 + 0x30));
  }
  return uVar4;
}



===== TunnelUserDequeueWriteIrp @ 1c000c5a8 =====

void TunnelUserDequeueWriteIrp(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  *(int *)(param_1 + 0x148) = *(int *)(param_1 + 0x148) + -1;
  plVar1 = (longlong *)(param_2 + 0xa8);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) == plVar1) &&
     (plVar3 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    *(undefined8 *)(param_2 + 0x78) = 0;
    *plVar1 = 0;
    *(undefined8 *)(param_2 + 0xb0) = 0;
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== TunnelMiniportPause @ 1c000c5f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 TunnelMiniportPause(longlong param_1,undefined8 param_2,undefined *param_3)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar3 = *(longlong *)(param_1 + 0x10);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  KeAcquireInStackQueuedSpinLock(lVar3 + 0x18,&local_28);
  uVar4 = 0;
  do {
  } while (*(int *)(lVar3 + 0x20) != 0);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)
     ) {
    param_3 = &WPP_9608820f130d35da1284a1080d801204_Traceguids;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,
             &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(undefined4 *)(param_1 + 0x28));
  }
  if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
    McTemplateK0qqq_EtwWriteTransfer
              (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_OP,param_3,
               *(undefined4 *)(param_1 + 0x18),(char)*(undefined4 *)(param_1 + 0x28),1);
  }
  if (*(longlong *)(param_1 + 0x48) == 0) {
    LOCK();
    piVar1 = (int *)(param_1 + 0x40);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 2) {
      *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 2;
      goto LAB_1c000c6dc;
    }
    *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 1;
  }
  uVar4 = 0x103;
LAB_1c000c6dc:
  KeReleaseInStackQueuedSpinLock(&local_28);
  (**(code **)(*(longlong *)(param_1 + 0x20) + 0x28))(param_1);
  return uVar4;
}



===== TunnelUserGetNextHopInterfaceV4 @ 1c000c718 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 TunnelUserGetNextHopInterfaceV4(undefined4 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_118 [32];
  undefined4 local_f8;
  undefined8 local_f0;
  undefined4 local_e8;
  undefined1 *local_e0;
  undefined4 local_d8;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined1 local_88 [88];
  undefined4 local_30;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_118;
  local_b8 = 0;
  local_98 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  memset(local_88,0,0x68);
  local_c8 = 0;
  local_e0 = local_88;
  local_d0 = 0;
  local_d8 = 0x68;
  local_e8 = 0;
  local_f0 = 0;
  local_f8 = 0x20;
  local_b0 = 1;
  local_ac = param_1;
  iVar1 = NsiGetAllParameters(1,&NPI_MS_IPV4_MODULEID,0,&local_b0);
  if ((iVar1 < 0) ||
     (uVar2 = TunnelConvertInterfaceIndexToLuid(local_30,&local_b8), (int)uVar2 == 0)) {
    return local_b8;
  }
  return 0;
}



===== TunnelRunningOnXboxOne @ 1c000c804 =====

undefined1 TunnelRunningOnXboxOne(void)

{
  int iVar1;
  undefined1 uVar2;
  int local_res8 [2];
  undefined4 local_res10 [2];
  undefined4 local_res18 [4];
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar2 = 0;
  local_res18[0] = 0;
  local_res10[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_res8[0] = 0;
  RtlInitUnicodeString(&local_18,L"Kernel-OneCore-DeviceFamilyID");
  iVar1 = ZwQueryLicenseValue(&local_18,local_res18,local_res8,4,local_res10);
  if ((-1 < iVar1) && (uVar2 = 0, local_res8[0] == 5)) {
    uVar2 = 1;
  }
  return uVar2;
}



===== TunnelNlReceiveHelper @ 1c000c884 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

longlong TunnelNlReceiveHelper
                   (longlong param_1,longlong param_2,undefined *param_3,undefined8 param_4,
                   undefined8 param_5,undefined8 param_6)

{
  uint uVar1;
  char cVar2;
  ushort uVar3;
  longlong lVar4;
  undefined *puVar5;
  ulonglong uVar6;
  
  if (*(int *)(param_3 + 0x60) == 0) {
    puVar5 = param_3;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
      puVar5 = &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
               &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids,*(undefined4 *)(param_3 + 0x28));
    }
    if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
      McTemplateK0q_EtwWriteTransfer
                (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_RECEIVES_DISABLED,
                 puVar5,*(undefined4 *)(param_3 + 0x28));
    }
  }
  else {
    puVar5 = (undefined *)0x0;
    uVar6 = 0;
    cVar2 = (**(code **)(*(longlong *)(param_3 + 0x20) + 0x20))
                      (param_3,param_1,0,param_4,0,param_5,param_6);
    if (cVar2 != '\0') {
      uVar1 = *(uint *)(*(longlong *)(param_2 + 8) + 0x18);
      if (*(uint *)(param_3 + 0x5c) <= uVar1) {
        uVar1 = *(uint *)(param_3 + 0x5c);
      }
      lVar4 = NdisGetDataBuffer(*(longlong *)(param_2 + 8),uVar1,0,1,uVar6 & 0xffffffff00000000);
      if (lVar4 == 0) {
        lVar4 = NetioAllocateAndReferenceCopyNetBufferListEx
                          (param_2,NetioCompleteCopyNetBufferListChain_exref);
        if (lVar4 != 0) {
          *(undefined8 *)(lVar4 + 0x18) = 0;
          *(undefined8 *)(param_1 + 8) = 0;
          NetioDereferenceNetBufferList(param_2,0);
LAB_1c000ca69:
          uVar3 = 0x800;
          if (*(int *)(param_1 + 0x2c) != 4) {
            uVar3 = 0x86dd;
          }
          *(ulonglong *)(lVar4 + 200) = (ulonglong)(ushort)(uVar3 >> 8 | uVar3 << 8);
          return lVar4;
        }
      }
      else {
        lVar4 = NdisAllocateCloneNetBufferList(param_2,0,0,0);
        if (lVar4 != 0) {
          *(longlong *)(lVar4 + 0x18) = param_2;
          WfpNblInfoClone(param_2,lVar4,0,0,1);
          *(undefined8 *)(param_1 + 8) = 0;
          goto LAB_1c000ca69;
        }
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids);
      }
      *(undefined4 *)(param_2 + 0x8c) = 0xc000009a;
      return 0;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
      puVar5 = &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
              &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids);
    }
    if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
      McTemplateK0qq_EtwWriteTransfer
                (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_PACKET_INTEGRITY_CHECK_FAILED,
                 puVar5,*(undefined4 *)(param_3 + 0x18),(char)*(undefined4 *)(param_3 + 0x28));
    }
  }
  *(undefined4 *)(param_2 + 0x8c) = 0xc000021b;
  return 0;
}



===== TunnelUpdateLinkSpeed @ 1c000cae8 =====

undefined8 TunnelUpdateLinkSpeed(longlong param_1,undefined8 param_2)

{
  undefined1 auVar1 [16];
  int iVar2;
  longlong lVar3;
  longlong local_res8;
  ulonglong local_res18;
  
  if (*(longlong *)(param_1 + 0x100) == 0) {
    *(undefined8 *)(param_1 + 0x68) = 100000;
  }
  else {
    local_res18 = 0;
    local_res8 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x100) + 8) + 0x10);
    KeReleaseInStackQueuedSpinLock(param_2);
    iVar2 = NsiGetParameter(1,&NPI_MS_NDIS_MODULEID,0,&local_res8,8,1,&local_res18,8,0x18);
    RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10) + 0x18);
    if (((-1 < iVar2) && (*(longlong *)(param_1 + 0x100) != 0)) &&
       (local_res8 == *(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x100) + 8) + 0x10))) {
      auVar1._8_8_ = 0;
      auVar1._0_8_ = local_res18;
      lVar3 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar1,8);
      *(ulonglong *)(param_1 + 0x68) = ((local_res18 - lVar3 >> 1) + lVar3 >> 6) * 0x1e;
    }
  }
  return *(undefined8 *)(param_1 + 0x68);
}



===== TunnelTelemetryDriverInitialization @ 1c000cbec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TunnelTelemetryDriverInitialization
               (undefined4 param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined1 auStackY_98 [32];
  undefined4 local_68;
  undefined4 local_64 [3];
  undefined8 local_58 [4];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  uVar2 = (ulonglong)param_2;
  if (5 < DAT_1c0017050) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_2c = 0;
      local_38 = &local_68;
      local_1c = 0;
      local_28 = local_64;
      local_30 = 4;
      local_64[0] = (undefined4)uVar2;
      local_20 = 4;
      local_68 = param_1;
      _tlgWriteTransfer_EtwWriteTransfer(4,&DAT_1c0014fda,uVar2,param_4,4,local_58);
    }
  }
  return;
}



===== TunnelNlRegisterNlClient @ 1c000cc88 =====

ulonglong TunnelNlRegisterNlClient(void)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = NmrRegisterClient(&TunnelNlcNotify,&TunnelNlcNotify,&DAT_1c001a920);
  if (-1 < (int)uVar2) {
    LOCK();
    DAT_1c0017368 = DAT_1c0017368 + 1;
    UNLOCK();
    uVar1 = NmrRegisterClient(&DAT_1c0013118,&DAT_1c0013118,&DAT_1c001a928);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) {
      NmrDeregisterClient(DAT_1c001a920);
      NmrWaitForClientDeregisterComplete(DAT_1c001a920);
      TunnelDereferenceDriver();
    }
    else {
      LOCK();
      DAT_1c0017368 = DAT_1c0017368 + 1;
      UNLOCK();
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== TunnelInitializeTimer @ 1c000cd20 =====

void TunnelInitializeTimer(void)

{
  int iVar1;
  
  iVar1 = 0;
  LOCK();
  if (DAT_1c001a9b0 == 0) {
    DAT_1c001a9b0 = 1;
  }
  else {
    iVar1 = DAT_1c001a9b0;
  }
  UNLOCK();
  if (iVar1 != 1) {
    KeInitializeDpc(&DAT_1c001a970,TunnelTimeoutRoutine,0);
    KeInitializeTimerEx(&DAT_1c001a930,0);
    KeSetCoalescableTimer(&DAT_1c001a930,0xfffffffff70f2e80,15000,5000,&DAT_1c001a970);
    DAT_1c001a9f0 = 0;
  }
  return;
}



===== McGenEventRegister_EtwRegister @ 1c000cdb0 =====

void McGenEventRegister_EtwRegister(void)

{
  if (MS_TUNNEL_DRIVER_PROVIDER_ID_Context == 0) {
    EtwRegister(&MS_TUNNEL_DRIVER_PROVIDER_ID,McGenControlCallbackV2,
                &MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&MS_TUNNEL_DRIVER_PROVIDER_ID_Context);
  }
  return;
}



===== TunnelIsPotentialRouterAssociatedWithTunnel @ 1c000cdf0 =====

undefined8 TunnelIsPotentialRouterAssociatedWithTunnel(longlong param_1,int param_2)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  puVar1 = *(undefined8 **)(param_1 + 0xa8);
  do {
    if (puVar1 == (undefined8 *)(param_1 + 0xa8)) {
LAB_1c000ce0f:
      return CONCAT71((int7)((ulonglong)puVar1 >> 8),uVar2);
    }
    if (*(int *)(puVar1 + 2) == param_2) {
      uVar2 = 1;
      goto LAB_1c000ce0f;
    }
    puVar1 = (undefined8 *)*puVar1;
  } while( true );
}



===== TunnelReferenceDriver @ 1c000ce1c =====

void TunnelReferenceDriver(void)

{
  LOCK();
  DAT_1c0017368 = DAT_1c0017368 + 1;
  UNLOCK();
  return;
}



===== __report_gsfailure @ 1c000ce40 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 1c000ce50 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = (ushort *)param_1[1];
  uVar2 = 0;
  if (puVar1 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = puVar1;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(*param_1,param_2,&MS_TUNNEL_DRIVER_PROVIDER_ID,0,param_4,param_5);
  return;
}



===== McTemplateK0qq_EtwWriteTransfer @ 1c000ceb4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qq_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_78 [32];
  undefined8 local_48 [2];
  undefined4 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_38 = local_res20;
  local_28 = &param_5;
  local_30 = 4;
  local_2c = 0;
  local_20 = 4;
  local_1c = 0;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,4,3,local_48);
  return;
}



===== TunnelProcessorAddCallback @ 1c000cf20 =====

void TunnelProcessorAddCallback(undefined8 param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if ((-1 < *param_3) || (*param_2 != 0)) {
    KeWaitForSingleObject(&DAT_1c001aa20,0,0,0,0);
    if (DAT_1c001aa68 == '\0') {
      iVar1 = NetioStackBlockProcessorAddHandler(DAT_1c001a6c8,param_2[1],*param_2);
    }
    *param_3 = iVar1;
    KeReleaseMutex(&DAT_1c001aa20,0);
  }
  return;
}



===== WPP_SF_ @ 1c000cfb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 1c000cfe0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c000d030 =====

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



===== LwInitializeQueue @ 1c000d064 =====

undefined8 LwInitializeQueue(longlong param_1,longlong *param_2,longlong param_3)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  memset(param_2,0,0x58);
  param_2[6] = param_3;
  *param_2 = (longlong)(param_2 + 2);
  param_2[1] = (longlong)(param_2 + 2);
  param_2[7] = param_1;
  KeInitializeSpinLock(param_2 + 3);
  uVar1 = IoSizeofWorkItem();
  lVar2 = ExAllocatePool2(0x42,uVar1,0x6957714c);
  param_2[5] = lVar2;
  if (lVar2 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    IoInitializeWorkItem(param_1,lVar2);
    uVar3 = 0;
    *(undefined1 *)((longlong)param_2 + 0x21) = 1;
  }
  return uVar3;
}



===== IN6_IS_ADDR_ISATAP @ 1c000d114 =====

undefined8 IN6_IS_ADDR_ISATAP(longlong param_1)

{
  if (((*(ushort *)(param_1 + 8) & 0xfffd) == 0) && (*(short *)(param_1 + 10) == -0x1a2)) {
    return 0xfe01;
  }
  return 0;
}



===== IN6_IS_ADDR_V4COMPAT @ 1c000d138 =====

undefined8 IN6_IS_ADDR_V4COMPAT(short *param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (((((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0)) &&
      ((param_1[3] == 0 && (param_1[4] == 0)))) &&
     ((param_1[5] == 0 &&
      (((param_1[6] != 0 || ((char)param_1[7] != '\0')) || (1 < *(byte *)((longlong)param_1 + 0xf)))
      )))) {
    uVar1 = 1;
  }
  return uVar1;
}



===== McTemplateK0_EtwWriteTransfer @ 1c000d178 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,1,local_28);
  return;
}



===== McTemplateK0q_EtwWriteTransfer @ 1c000d1bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0q_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_68 [32];
  undefined8 local_38 [2];
  undefined4 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_28 = local_res20;
  local_1c = 0;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,2,local_38);
  return;
}



===== McTemplateK0qqq_EtwWriteTransfer @ 1c000d218 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqq_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = local_res20;
  local_38 = &param_5;
  local_28 = &param_6;
  local_40 = 4;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,4,local_58);
  return;
}



===== NetioExpandKernelStackAndCallout @ 1c000d28c =====

int NetioExpandKernelStackAndCallout
              (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              uint param_5,byte param_6)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined1 uVar7;
  
  if (param_6 < 2) {
    uVar7 = 1;
  }
  else {
    uVar7 = 0;
    if ((*(uint *)(param_1 + 0x3c) & 1) == 0) {
      uVar4 = *(uint *)(param_1 + 0x48 + (ulonglong)param_5 * 0x10);
      if ((uVar4 & 1) == 0) {
        *(uint *)(param_1 + 0x48 + (ulonglong)param_5 * 0x10) = uVar4 | 1;
        lVar6 = *(longlong *)(param_1 + ((ulonglong)param_5 + 4) * 0x10);
        goto LAB_1c000d2e7;
      }
    }
  }
  lVar6 = 0;
LAB_1c000d2e7:
  while (iVar3 = KeExpandKernelStackAndCalloutEx
                           (TunnelNlSendNetBufferListCalloutRoutine,param_3,0x4800,uVar7,lVar6),
        iVar3 == -0x3fffffe9) {
    if (lVar6 != 0) goto LAB_1c000d37f;
    if (param_6 < 2) {
      KeWaitForSingleObject(param_1,0,0,0,0);
      uVar5 = (ulonglong)*(uint *)(param_1 + 0x38);
      uVar4 = *(uint *)(param_1 + 0x48 + uVar5 * 0x10);
      uVar2 = *(uint *)(param_1 + 0x38);
      if ((uVar4 & 1) != 0) goto LAB_1c000d39f;
    }
    else {
      uVar5 = (ulonglong)param_5;
      uVar4 = *(uint *)(param_1 + 0x48 + uVar5 * 0x10);
      uVar2 = param_5;
      if ((uVar4 & 1) != 0) {
        return -0x3fffffe9;
      }
    }
    lVar6 = *(longlong *)(param_1 + ((ulonglong)uVar2 + 4) * 0x10);
    *(uint *)(param_1 + 0x48 + uVar5 * 0x10) = uVar4 | 1;
  }
  if (lVar6 != 0) {
LAB_1c000d37f:
    if (param_6 < 2) {
      puVar1 = (uint *)(param_1 + 0x48 + (ulonglong)*(uint *)(param_1 + 0x38) * 0x10);
      *puVar1 = *puVar1 & 0xfffffffe;
LAB_1c000d39f:
      KeReleaseMutex(param_1,0);
    }
    else {
      puVar1 = (uint *)(param_1 + 0x48 + (ulonglong)param_5 * 0x10);
      *puVar1 = *puVar1 & 0xfffffffe;
    }
  }
  return iVar3;
}



===== NetioRestoreNetBufferList @ 1c000d3d8 =====

void NetioRestoreNetBufferList(longlong param_1)

{
  longlong *plVar1;
  int iVar2;
  uint uVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 *puVar6;
  int iVar7;
  
  for (puVar6 = *(undefined8 **)(param_1 + 8); puVar6 != (undefined8 *)0x0;
      puVar6 = (undefined8 *)*puVar6) {
    iVar7 = *(int *)(puVar6 + 0xb);
    plVar1 = puVar6 + 4;
    *(undefined4 *)(puVar6 + 0xb) = 0;
    for (iVar7 = ((iVar7 - *(int *)((longlong)puVar6 + 0x54)) - *(int *)(puVar6 + 10)) +
                 *(int *)(puVar6 + 5) + *(int *)(puVar6 + 3); iVar7 != 0; iVar7 = iVar7 - iVar2) {
      plVar4 = (longlong *)*plVar1;
      *plVar1 = *plVar4;
      iVar2 = *(int *)(plVar4 + 5);
      NetioFreeMdl();
    }
    lVar5 = *plVar1;
    *(undefined4 *)(puVar6 + 3) = *(undefined4 *)((longlong)puVar6 + 0x54);
    uVar3 = *(uint *)(puVar6 + 10);
    *(uint *)(puVar6 + 5) = uVar3;
    puVar6[1] = lVar5;
    *(uint *)(puVar6 + 2) = uVar3;
    if ((lVar5 != 0) && (*(uint *)(lVar5 + 0x28) < uVar3)) {
      NdisAdjustNetBufferCurrentMdl(puVar6);
    }
  }
  return;
}



===== RoIsDeleted @ 1c000d474 =====

undefined4 RoIsDeleted(int *param_1)

{
  return CONCAT31((int3)((uint)*param_1 >> 8),*param_1 == 1);
}



===== Tunnel6to4PacketIntegrityCheck @ 1c000d490 =====

undefined1
Tunnel6to4PacketIntegrityCheck
          (longlong param_1,longlong param_2,undefined *param_3,uint *param_4,undefined8 param_5,
          short *param_6,char *param_7)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined1 uVar4;
  
  uVar4 = 0;
  if (*(int *)(param_2 + 0x2c) == 0x29) {
    uVar1 = *param_4;
    if (((((uVar1 & 0xf0) != 0xe0) && (uVar1 - 1 < 0xfffffffe)) &&
        (cVar2 = (char)uVar1, (uVar1 & 0xf0) != 0xf0 && cVar2 != '\0')) &&
       (((cVar2 != '\x7f' && ((uVar1 & 0xffff) != 0xfea9)) &&
        ((cVar2 != '\n' && (((uVar1 & 0xf0ff) != 0x10ac && ((uVar1 & 0xffff) != 0xa8c0)))))))) {
      if (((char)*param_6 != -1) &&
         ((*param_7 != -1 && (((char)*param_6 != -2 || ((short)(*param_6 & -0x4000) != -0x8000))))))
      {
        if (*param_6 == 0x220) {
          iVar3 = memcmp(param_4,param_6 + 1,(ulonglong)*(uint *)(param_1 + 0xfc));
          uVar4 = 0;
          if (iVar3 == 0) {
            uVar4 = 1;
          }
        }
        else {
          uVar4 = 1;
        }
      }
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
      param_3 = &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
              &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids);
    }
    if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
      McTemplateK0q_EtwWriteTransfer
                (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_NON_IPV6_PACKET,param_3,
                 *(undefined4 *)(param_1 + 0x28));
    }
  }
  return uVar4;
}



===== TunnelIsatapPacketIntegrityCheck @ 1c000d5e0 =====

bool TunnelIsatapPacketIntegrityCheck
               (longlong param_1,longlong param_2,undefined *param_3,int *param_4,undefined8 param_5
               ,char *param_6,short *param_7)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 local_res10 [8];
  
  local_res10[0] = 0;
  if (*(int *)(param_2 + 0x2c) != 0x29) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
      param_3 = &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids;
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
              &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids);
    }
    if (DAT_1c0017024 == 0) {
      return false;
    }
    if ((Microsoft_Windows_TunnelDriverEnableBits & 1) == 0) {
      return false;
    }
    McTemplateK0q_EtwWriteTransfer
              (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_NON_IPV6_PACKET,param_3,
               *(undefined4 *)(param_1 + 0x28));
    return false;
  }
  uVar4 = IN6_IS_ADDR_V4COMPAT(param_7);
  if ((char)uVar4 == '\0') {
    if (*param_6 == -1) {
      return false;
    }
    uVar4 = IN6_IS_ADDR_ISATAP((longlong)param_6);
    if (((char)uVar4 == '\0') ||
       (iVar3 = memcmp(param_4,param_6 + 0xc,(ulonglong)*(uint *)(param_1 + 0xfc)), iVar3 != 0)) {
      lVar2 = *(longlong *)(param_1 + 0x10);
      RtlAcquireReadLock(lVar2 + 0x18,local_res10);
      uVar4 = TunnelIsPotentialRouterAssociatedWithTunnel(param_1,*param_4);
      LOCK();
      piVar1 = (int *)(lVar2 + 0x20);
      *piVar1 = *piVar1 + -1;
      UNLOCK();
      KeLowerIrql(local_res10[0]);
      return (char)uVar4 != '\0';
    }
  }
  return true;
}



===== TunnelNlCloseNlClient @ 1c000d704 =====

void TunnelNlCloseNlClient(void)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  puVar1 = &DAT_1c001a920;
  lVar2 = 2;
  do {
    NmrWaitForClientDeregisterComplete(*puVar1);
    TunnelDereferenceDriver();
    puVar1 = puVar1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}



===== TunnelNlCompleteSendNetBufferListChain @ 1c000d750 =====

void TunnelNlCompleteSendNetBufferListChain(longlong *param_1,ulonglong param_2,undefined1 param_3)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  int iVar10;
  undefined8 local_res8;
  
  uVar6 = 0;
  local_res8 = 0;
  lVar7 = 0;
  iVar10 = 0;
  puVar8 = (undefined8 *)0x0;
  if (param_1 != (longlong *)0x0) {
    do {
      plVar2 = (longlong *)*param_1;
      NetioRestoreNetBufferList((longlong)param_1);
      lVar3 = param_1[0xb];
      puVar9 = puVar8;
      if (lVar3 != 0) {
        if (lVar3 != lVar7) {
          if (lVar7 != 0) {
            *puVar8 = 0;
            NdisMSendNetBufferListsComplete(*(undefined8 *)(lVar7 + 0x38),uVar6);
            TunnelInterfaceDereferenceExImp(lVar7,iVar10,(undefined *)0x0);
          }
          iVar10 = 0;
          puVar8 = &local_res8;
          lVar7 = lVar3;
        }
        puVar9 = (undefined8 *)param_1[9];
        iVar10 = iVar10 + 1;
        *puVar8 = puVar9;
        iVar1 = *(int *)((longlong)param_1 + 0x8c);
        *(int *)((longlong)puVar9 + 0x8c) = iVar1;
        if (iVar1 < 0) {
          *(int *)(lVar3 + 0x78) = *(int *)(lVar3 + 0x78) + 1;
        }
        else {
          *(int *)(lVar3 + 0x70) = *(int *)(lVar3 + 0x70) + 1;
          plVar4 = (longlong *)param_1[1];
          if (plVar4 != (longlong *)0x0) {
            lVar5 = *(longlong *)(lVar3 + 0x88);
            do {
              lVar5 = lVar5 + (ulonglong)*(uint *)(plVar4 + 3);
              *(longlong *)(lVar3 + 0x88) = lVar5;
              plVar4 = (longlong *)*plVar4;
            } while (plVar4 != (longlong *)0x0);
          }
        }
        NetioFreeCloneNetBufferList(param_1,param_3);
        uVar6 = local_res8;
      }
      puVar8 = puVar9;
      param_1 = plVar2;
    } while (plVar2 != (longlong *)0x0);
    if (lVar7 != 0) {
      *puVar9 = 0;
      NdisMSendNetBufferListsComplete(*(undefined8 *)(lVar7 + 0x38),uVar6);
      TunnelInterfaceDereferenceExImp(lVar7,iVar10,(undefined *)0x0);
    }
  }
  return;
}



===== TunnelNlDeregisterNlClient @ 1c000d8a4 =====

void TunnelNlDeregisterNlClient(void)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  puVar1 = &DAT_1c001a920;
  lVar2 = 2;
  do {
    NmrDeregisterClient(*puVar1);
    puVar1 = puVar1 + 1;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return;
}



===== TunnelNlGetPhysicalInterface @ 1c000d8f0 =====

int TunnelNlGetPhysicalInterface(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 local_res8 [8];
  undefined8 local_res10;
  
  local_res10 = 0;
  iVar2 = 0;
  lVar4 = 0;
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_res8[0] = 0;
  if (*(int *)(param_1 + 0x18) == 0xd) {
    lVar3 = 0x14;
  }
  else {
    if (*(int *)(param_1 + 0x18) != 0xb) {
      return -0x3fffffff;
    }
    lVar3 = 10;
  }
  RtlAcquireReadLock(lVar1 + 0x18,local_res8);
  if (*(longlong *)(param_1 + 0x100) == 0) {
    iVar2 = -0x3fffffff;
  }
  else {
    lVar4 = TunnelNlGetUnconstrainedPreferredSourceAddressForSendHelper(param_1);
  }
  LOCK();
  *(int *)(lVar1 + 0x20) = *(int *)(lVar1 + 0x20) + -1;
  UNLOCK();
  KeLowerIrql(local_res8[0]);
  if (iVar2 == 0) {
    iVar2 = TunnelNlGetNextHopInterface
                      (*(longlong *)(param_1 + 0x10),lVar3 + param_2,lVar4,&local_res10);
    if (lVar4 != 0) {
      TunnelNlDereferenceLocalAddressObject((undefined8 *)(lVar1 + 0x38),lVar4);
    }
    if (iVar2 < 0) {
      iVar2 = -0x3ffeffd7;
    }
    else {
      iVar2 = 0;
      *(undefined8 *)(param_2 + 0x80) = local_res10;
    }
  }
  return iVar2;
}



===== TunnelNlGetSourceAddressForSend @ 1c000d9dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong TunnelNlGetSourceAddressForSend(longlong param_1,undefined8 param_2,undefined4 *param_3)

{
  longlong lVar1;
  char cVar2;
  int *piVar3;
  longlong lVar4;
  undefined1 auStack_c8 [32];
  undefined8 *local_a8;
  undefined1 local_98 [8];
  undefined8 local_90;
  longlong local_88;
  undefined8 local_80;
  undefined8 local_78;
  int *piStack_70;
  undefined8 local_68;
  undefined1 local_60 [40];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_c8;
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_90 = 0;
  local_68 = 0;
  lVar4 = 0;
  *param_3 = 0;
  local_88 = 0;
  local_98[0] = 0;
  local_78 = 0;
  piStack_70 = (int *)0x0;
  local_a8 = &local_90;
  cVar2 = (*(code *)**(undefined8 **)(*(longlong *)(param_1 + 0x10) + 0x28))
                    (0,param_2,local_60,&local_68);
  if (cVar2 == '\0') {
    return 0;
  }
  RtlAcquireReadLock(lVar1 + 0x18,local_98);
  if (*(longlong *)(param_1 + 0x100) != 0) {
    *param_3 = *(undefined4 *)**(undefined8 **)(*(longlong *)(param_1 + 0x100) + 8);
    piVar3 = (int *)(**(code **)(*(longlong *)(param_1 + 0x20) + 0x18))(local_90);
    if (piVar3 != (int *)0x0) {
      cVar2 = TunnelIsNlLocalAddressAssociatedWithTunnel(param_1,0,piVar3,&local_88);
      if (cVar2 != '\0') {
        local_80 = *(undefined8 *)(local_88 + 0x18);
        lVar4 = TunnelNlReferenceLocalAddressByArgs
                          ((undefined8 *)(lVar1 + 0x38),&local_80,
                           **(undefined8 **)(*(longlong *)(param_1 + 0x100) + 8));
        if (lVar4 != 0) goto LAB_1c000db19;
      }
      local_80 = 0;
      local_78 = 0;
      piStack_70 = piVar3;
      lVar4 = TunnelNlReferenceLocalAddressByArgs
                        ((undefined8 *)(lVar1 + 0x38),&local_80,
                         **(undefined8 **)(*(longlong *)(param_1 + 0x100) + 8));
      if (lVar4 != 0) goto LAB_1c000db19;
    }
    lVar4 = TunnelNlGetUnconstrainedPreferredSourceAddressForSendHelper(param_1);
  }
LAB_1c000db19:
  LOCK();
  *(int *)(lVar1 + 0x20) = *(int *)(lVar1 + 0x20) + -1;
  UNLOCK();
  KeLowerIrql(local_98[0]);
  return lVar4;
}



===== TunnelNlGetSourceAndDestinationV4 @ 1c000db50 =====

ulonglong TunnelNlGetSourceAndDestinationV4
                    (longlong param_1,longlong param_2,undefined8 param_3,longlong *param_4,
                    longlong *param_5)

{
  longlong lVar1;
  ulonglong uVar2;
  
  uVar2 = *(ulonglong *)(param_2 + 8);
  *param_4 = 0;
  *param_5 = 0;
  if (((param_1 == 0) || (*(int *)(param_1 + 0x2c) == 4)) && (0x13 < *(uint *)(uVar2 + 0x18))) {
    lVar1 = NdisGetDataBuffer(uVar2);
    *param_4 = lVar1 + 0x10;
    *param_5 = lVar1 + 0xc;
    uVar2 = CONCAT71((int7)((ulonglong)(lVar1 + 0xc) >> 8),1);
  }
  else {
    *param_4 = 0;
    uVar2 = uVar2 & 0xffffffffffffff00;
    *param_5 = 0;
  }
  return uVar2;
}



===== TunnelNlGetSourceAndDestinationV6 @ 1c000dbd0 =====

ulonglong TunnelNlGetSourceAndDestinationV6
                    (longlong param_1,longlong param_2,undefined8 param_3,longlong *param_4,
                    longlong *param_5)

{
  longlong lVar1;
  ulonglong uVar2;
  
  uVar2 = *(ulonglong *)(param_2 + 8);
  *param_4 = 0;
  *param_5 = 0;
  if (((param_1 == 0) || (*(int *)(param_1 + 0x2c) == 0x29)) && (0x27 < *(uint *)(uVar2 + 0x18))) {
    lVar1 = NdisGetDataBuffer(uVar2,0x28,param_3,4,0);
    *param_4 = lVar1 + 0x18;
    *param_5 = lVar1 + 8;
    uVar2 = CONCAT71((int7)((ulonglong)(lVar1 + 8) >> 8),1);
  }
  else {
    *param_4 = 0;
    uVar2 = uVar2 & 0xffffffffffffff00;
    *param_5 = 0;
  }
  return uVar2;
}



===== TunnelNlGetUnconstrainedPreferredSourceAddressForSendHelper @ 1c000dc48 =====

undefined8 TunnelNlGetUnconstrainedPreferredSourceAddressForSendHelper(longlong param_1)

{
  byte bVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 uStack_18;
  
  uVar3 = 0;
  puVar4 = (undefined8 *)0x0;
  bVar1 = 0;
  for (puVar5 = *(undefined8 **)(param_1 + 0x98); puVar5 != (undefined8 *)(param_1 + 0x98);
      puVar5 = (undefined8 *)*puVar5) {
    for (puVar2 = (undefined8 *)puVar5[3]; puVar2 != puVar5 + 3; puVar2 = (undefined8 *)*puVar2) {
      if (puVar4 == (undefined8 *)0x0) {
        puVar4 = puVar2;
      }
      else if (*(uint *)((longlong)puVar4 + 0x14) != *(uint *)((longlong)puVar2 + 0x14)) {
        if (*(uint *)((longlong)puVar4 + 0x14) < *(uint *)((longlong)puVar2 + 0x14)) {
          puVar4 = puVar2;
        }
        bVar1 = 1;
      }
    }
  }
  if ((-(ulonglong)bVar1 & (ulonglong)puVar4) != 0) {
    local_28 = *(undefined8 *)((-(ulonglong)bVar1 & (ulonglong)puVar4) + 0x18);
    local_20 = 0;
    uStack_18 = 0;
    uVar3 = TunnelNlReferenceLocalAddressByArgs
                      ((undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x38),&local_28,
                       **(undefined8 **)(*(longlong *)(param_1 + 0x100) + 8));
  }
  return uVar3;
}



===== TunnelNlHaltTunnel @ 1c000dd10 =====

void TunnelNlHaltTunnel(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x100);
  *(undefined8 *)(param_1 + 0x100) = 0;
  lVar2 = *(longlong *)(param_1 + 0x10);
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) | 4;
  KeReleaseInStackQueuedSpinLock(param_2);
  if (lVar1 != 0) {
    TunnelNlDereferenceLocalAddressObject((undefined8 *)(lVar2 + 0x38),lVar1);
  }
  RtlAcquireWriteLock(lVar2 + 0x18);
  return;
}



===== TunnelNlInitializeLocalAddressObject @ 1c000dd80 =====

void TunnelNlInitializeLocalAddressObject(longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  
  uVar1 = RoReferenceEx((uint *)(*(longlong *)(param_1 + 0x10) + 0x60),1);
  if ((char)uVar1 != '\0') {
    uVar2 = TunnelNlReferenceLocalAddressByDlAddress
                      ((undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x38),
                       (undefined4 *)(param_1 + 0xbc));
    *(undefined8 *)(param_1 + 0x100) = uVar2;
    TunnelNlDereferenceNlBinding(*(longlong *)(param_1 + 0x10));
  }
  return;
}



===== TunnelNlInvalidateRoutingEpoch @ 1c000ddd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TunnelNlInvalidateRoutingEpoch(longlong param_1,undefined8 param_2)

{
  (**(code **)(*(longlong *)(param_1 + 8) + 0xe8))(param_2);
  return;
}



===== TunnelNlMapIcmpStub @ 1c000de00 =====

undefined8 TunnelNlMapIcmpStub(undefined8 param_1,longlong param_2,undefined8 *param_3)

{
  *(undefined4 *)(*(longlong *)(param_2 + 8) + 0x8c) = 0xc0000002;
  *param_3 = 0;
  return 0;
}



===== TunnelNlMapInnerSourceToOuter @ 1c000de20 =====

short * TunnelNlMapInnerSourceToOuter(short *param_1,longlong param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  short *psVar3;
  short *psVar4;
  undefined8 local_28;
  undefined8 local_20;
  short *local_18;
  
  psVar4 = (short *)0x0;
  local_28 = 0;
  local_20 = 0;
  if (*(int *)(param_2 + 0x18) == 0xd) {
    psVar3 = param_1;
    uVar1 = IN6_IS_ADDR_ISATAP((longlong)param_1);
    if ((char)uVar1 != '\0') {
      local_18 = psVar3;
      lVar2 = TunnelNlReferenceLocalAddressByArgs2
                        ((undefined8 *)(*(longlong *)(*(longlong *)(param_2 + 0x10) + 0x30) + 0x38),
                         &local_28,*(uint *)**(undefined8 **)(*(longlong *)(param_2 + 0x100) + 8));
      if (lVar2 != 0) {
        psVar4 = param_1 + 6;
        TunnelNlDereferenceLocalAddressObject
                  ((undefined8 *)(*(longlong *)(*(longlong *)(param_2 + 0x10) + 0x30) + 0x38),lVar2)
        ;
      }
    }
  }
  else if ((*(int *)(param_2 + 0x18) == 0xb) && (*param_1 == 0x220)) {
    psVar4 = param_1 + 1;
  }
  return psVar4;
}



===== _guard_check_icall @ 1c000ded0 =====

void _guard_check_icall(void)

{
  return;
}



===== TunnelNlQueryMediaConnectStatus @ 1c000dee0 =====

bool TunnelNlQueryMediaConnectStatus(longlong param_1)

{
  return *(longlong *)(param_1 + 0x100) == 0;
}



===== TunnelNlReferenceLocalAddressByArgs @ 1c000def4 =====

void TunnelNlReferenceLocalAddressByArgs(undefined8 *param_1,undefined8 *param_2,undefined8 param_3)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_38 = *param_1;
  local_28 = 0;
  uStack_20 = *param_2;
  local_18 = param_2[1];
  uStack_10 = param_2[2];
  local_30 = param_3;
  TunnelReferenceLocalAddressByRequest((longlong)param_1,(longlong)&local_38);
  return;
}



===== TunnelNlReferenceLocalAddressByArgs2 @ 1c000df40 =====

void TunnelNlReferenceLocalAddressByArgs2(undefined8 *param_1,undefined8 *param_2,uint param_3)

{
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uStack_10 = param_2[2];
  local_38 = *param_1;
  local_28 = (ulonglong)param_3;
  uStack_30 = 0;
  uStack_20 = *param_2;
  local_18 = param_2[1];
  TunnelReferenceLocalAddressByRequest((longlong)param_1,(longlong)&local_38);
  return;
}



===== TunnelNlReferenceLocalAddressByDlAddress @ 1c000df8c =====

void TunnelNlReferenceLocalAddressByDlAddress(undefined8 *param_1,undefined4 *param_2)

{
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined8 local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 *local_10;
  
  local_30 = 0;
  local_24 = 0;
  local_1c = 0;
  local_14 = 0;
  local_38 = *param_1;
  local_10 = param_2 + 2;
  local_18 = param_2[1];
  local_28 = *param_2;
  TunnelReferenceLocalAddressByRequest((longlong)param_1,(longlong)&local_38);
  return;
}



===== TunnelNlReturnNetBufferLists @ 1c000dfe0 =====

void TunnelNlReturnNetBufferLists(longlong param_1,longlong *param_2,undefined1 param_3)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong local_res10;
  
  if (param_2 != (longlong *)0x0) {
    local_res10 = 0;
    plVar3 = &local_res10;
    do {
      plVar4 = (longlong *)param_2[3];
      plVar1 = (longlong *)*param_2;
      if (plVar4 == (longlong *)0x0) {
        NetioFreeMdl(*(undefined8 *)(param_2[1] + 0x20));
        NdisFreeNetBufferList(param_2);
        plVar4 = plVar3;
      }
      else {
        *(undefined4 *)((longlong)plVar4 + 0x8c) = *(undefined4 *)((longlong)param_2 + 0x8c);
        NdisFreeCloneNetBufferList(param_2,0);
        *plVar3 = (longlong)plVar4;
      }
      uVar2 = 0;
      TunnelInterfaceDereferenceExImp(param_1,1,(undefined *)0x0);
      param_2 = plVar1;
      plVar3 = plVar4;
    } while (plVar1 != (longlong *)0x0);
    if (local_res10 != 0) {
      *plVar4 = 0;
      NetioDereferenceNetBufferListChain
                (local_res10,CONCAT71((int7)((ulonglong)uVar2 >> 8),param_3) & 0xffffffffffffff01);
    }
  }
  return;
}



===== TunnelNlSendNetBufferList @ 1c000e0d0 =====

void TunnelNlSendNetBufferList
               (undefined8 param_1,undefined8 param_2,undefined1 param_3,undefined8 param_4)

{
  byte bVar1;
  uint uVar2;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 local_18;
  undefined2 local_17;
  undefined1 local_15;
  undefined4 local_14;
  
  local_14 = (undefined4)param_4;
  local_17 = 0;
  local_15 = 0;
  local_28 = param_1;
  local_20 = param_2;
  local_18 = param_3;
  bVar1 = KeGetCurrentIrql();
  uVar2 = KeGetCurrentProcessorNumberEx(0);
  NetioExpandKernelStackAndCallout(DAT_1c001a6c8,param_2,&local_28,param_4,uVar2,bVar1);
  return;
}



===== TunnelNlSendNetBufferListCalloutRoutine @ 1c000e140 =====

void TunnelNlSendNetBufferListCalloutRoutine(longlong *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)param_1[1];
  while (puVar2 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*puVar2;
    *puVar2 = 0;
    TunnelNlSendSingleNetBufferList
              (*param_1,(longlong)puVar2,(char)param_1[2],*(undefined4 *)((longlong)param_1 + 0x14))
    ;
    puVar2 = puVar1;
  }
  return;
}



===== TunnelNlSendSingleNetBufferList @ 1c000e188 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TunnelNlSendSingleNetBufferList
               (longlong param_1,longlong param_2,undefined1 param_3,undefined4 param_4)

{
  ushort uVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong lVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  int local_1e8 [2];
  longlong local_1e0;
  undefined8 local_1d8;
  longlong local_1d0;
  undefined8 local_1c8;
  longlong lStack_1c0;
  undefined8 local_1b8;
  undefined1 local_1a8 [8];
  int local_1a0;
  undefined4 local_170;
  longlong local_168;
  longlong local_160;
  undefined8 local_138;
  longlong local_130;
  longlong local_108 [4];
  longlong local_e8;
  longlong local_e0;
  undefined2 local_d8;
  undefined2 local_d0;
  longlong local_98;
  undefined4 local_80;
  longlong local_78;
  
  memset(local_108,0,0xd0);
  lVar2 = *(longlong *)(param_1 + 0x10);
  memset(local_1a8,0,0xa0);
  local_1b8 = 0;
  local_1e8[0] = 0;
  lVar7 = 0;
  local_1c8 = 0;
  lStack_1c0 = 0;
  lVar4 = TunnelNlGetSourceAddressForSend(param_1,param_2,local_1e8);
  if (local_1e8[0] != 0) {
    lVar5 = NetioAllocateAndReferenceCloneNetBufferListEx
                      (param_2,TunnelNlCompleteSendNetBufferListChain,param_1);
    cVar9 = '\0';
    cVar8 = '\x01';
    cVar10 = '\x01';
    if (lVar5 != 0) {
      cVar8 = '\x01';
      uVar6 = RoReferenceEx((uint *)(param_1 + 0x40),1);
      cVar10 = '\x01';
      if ((char)uVar6 != '\0') {
        cVar10 = cVar9;
      }
    }
    local_1d0 = TunnelGetDlAddressFromNblHelper(param_2);
    uVar1 = *(ushort *)(param_2 + 200);
    if (local_1d0 == 0) {
      cVar10 = cVar8;
    }
    if (cVar10 == '\0') {
      local_1a0 = local_1e8[0];
      local_168 = local_1d0 + 8;
      local_170 = *(undefined4 *)(local_1d0 + 4);
      local_160 = lVar4;
      iVar3 = (**(code **)(*(longlong *)(lVar2 + 0x40) + 0x40))
                        (*(undefined8 *)(lVar2 + 0x38),local_1a8);
      if ((-1 < iVar3) &&
         (lVar7 = (**(code **)(*(longlong *)(lVar2 + 0x40) + 0x120))(local_130), lVar7 != 0)) {
        local_1c8 = *(undefined8 *)(lVar2 + 0x38);
        lStack_1c0 = lVar7;
        iVar3 = (**(code **)(*(longlong *)(lVar2 + 0x40) + 0x88))(&local_1c8);
        if (iVar3 < 0) {
          local_d0 = 4;
          if ((ushort)(uVar1 >> 8 | uVar1 << 8) != 0x800) {
            local_d0 = 0x29;
          }
          local_80 = *(undefined4 *)(local_1d0 + 4);
          local_78 = local_1d0 + 8;
          local_e8 = local_130;
          local_d8 = 0xffff;
          local_108[0] = lVar5;
          local_e0 = lVar7;
          local_98 = lVar4;
          (**(code **)(*(longlong *)(lVar2 + 0x40) + 0x10))(*(undefined8 *)(lVar2 + 0x38),local_108)
          ;
          if (lVar4 != 0) {
            TunnelNlDereferenceLocalAddressObject((undefined8 *)(lVar2 + 0x38),lVar4);
          }
          if (lVar7 != 0) {
            (**(code **)(*(longlong *)(lVar2 + 0x40) + 0x80))(lVar7);
          }
          if (local_130 == 0) {
            return;
          }
          local_1e0 = local_130;
          local_1d8 = local_138;
          (**(code **)(*(longlong *)(lVar2 + 0x40) + 0x48))(&local_1e0);
          return;
        }
        TunnelNlDereferenceLocalAddressObject((undefined8 *)(lVar2 + 0x38),local_1b8);
      }
    }
    if (lVar5 != 0) {
      *(undefined4 *)(lVar5 + 0x8c) = 0xc0000001;
      NetioDereferenceNetBufferList(lVar5,param_3);
      goto LAB_1c000e42c;
    }
  }
  *(undefined4 *)(param_2 + 0x8c) = 0xc0000001;
  NdisMSendNetBufferListsComplete(*(undefined8 *)(param_1 + 0x38),param_2,param_4);
LAB_1c000e42c:
  if (lVar4 != 0) {
    TunnelNlDereferenceLocalAddressObject((undefined8 *)(lVar2 + 0x38),lVar4);
  }
  if (lVar7 != 0) {
    (**(code **)(*(longlong *)(lVar2 + 0x40) + 0x80))(lVar7);
  }
  if (local_130 != 0) {
    local_1e0 = local_130;
    local_1d8 = local_138;
    (**(code **)(*(longlong *)(lVar2 + 0x40) + 0x48))(&local_1e0);
  }
  *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + 1;
  return;
}



===== TunnelNlSetCurrentAddress @ 1c000e4b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
TunnelNlSetCurrentAddress(longlong param_1,undefined4 *param_2,uint param_3,uint *param_4)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined8 uVar5;
  int iVar6;
  uint uVar7;
  undefined1 auStack_98 [32];
  uint *local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  uint local_58 [2];
  uint5 uStack_50;
  undefined3 uStack_4b;
  undefined4 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_98;
  lVar4 = 0;
  local_60 = 0;
  local_48 = 0;
  lVar1 = *(longlong *)(param_1 + 0x10);
  *param_4 = 0;
  uVar7 = *(int *)(param_1 + 0xfc) + 8;
  local_70 = 0;
  uStack_68 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  _uStack_50 = 0;
  if (param_3 != uVar7) {
    return 0xc0010015;
  }
  local_78 = param_4;
  uVar3 = RoReferenceEx((uint *)(lVar1 + 0x60),1);
  if ((char)uVar3 != '\0') {
    lVar4 = TunnelNlReferenceLocalAddressByDlAddress((undefined8 *)(lVar1 + 0x38),param_2);
    TunnelNlDereferenceNlBinding(lVar1);
  }
  RtlAcquireWriteLock(lVar1 + 0x18);
  lVar2 = *(longlong *)(param_1 + 0x100);
  *(longlong *)(param_1 + 0x100) = lVar4;
  memcpy((void *)(param_1 + 0xbc),param_2,(ulonglong)uVar7);
  uVar5 = TunnelUpdateLinkSpeed(param_1,&local_70);
  if (lVar4 != 0) {
    local_48 = 0xffffffff;
    local_58[1] = *(undefined4 *)(*(longlong *)(lVar4 + 8) + 8);
    local_58[0] = *(undefined4 *)**(undefined8 **)(lVar4 + 8);
    uStack_50 = (uint5)*(uint *)(param_1 + 0xc4);
    TunnelInsertPhysicalInterfaceAssociationForTunnel(param_1,local_58,'\0');
  }
  KeReleaseInStackQueuedSpinLock(&local_70);
  if (lVar2 == 0) {
    if (lVar4 == 0) goto LAB_1c000e5f8;
    iVar6 = 1;
  }
  else {
    TunnelNlDereferenceLocalAddressObject((undefined8 *)(lVar1 + 0x38),lVar2);
    if (lVar4 != 0) goto LAB_1c000e5f8;
    iVar6 = 2;
  }
  TunnelIndicateStatus(param_1,iVar6,uVar5);
LAB_1c000e5f8:
  *local_78 = uVar7;
  return 0;
}



===== TunnelNlUpdateBestTunnel @ 1c000e62c =====

void TunnelNlUpdateBestTunnel(int param_1,longlong param_2,longlong *param_3)

{
  undefined4 uVar1;
  
  if (*param_3 != 0) {
    if ((param_1 != 0) &&
       (((*(int *)(param_2 + 0x28) == param_1 ||
         (((*(uint *)(param_2 + 0xb8) & 0x10) != 0 && ((*(uint *)(*param_3 + 0xb8) & 0x10) == 0))))
        && (uVar1 = RoIsDeleted((int *)(param_2 + 0x40)), (char)uVar1 == '\0'))))
    goto LAB_1c000e688;
    if ((*(uint *)(param_2 + 0xb8) & 8) == 0) {
      return;
    }
    if ((*(uint *)(*param_3 + 0xb8) & 8) != 0) {
      return;
    }
  }
  uVar1 = RoIsDeleted((int *)(param_2 + 0x40));
  if ((char)uVar1 != '\0') {
    return;
  }
LAB_1c000e688:
  *param_3 = param_2;
  return;
}



===== TunnelNlcCleanupNlProviderContext @ 1c000e6a0 =====

void TunnelNlcCleanupNlProviderContext(undefined8 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  return;
}



===== TunnelNlcReceiveControlMessage @ 1c000e6c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TunnelNlcReceiveControlMessage(longlong *param_1)

{
  longlong lVar1;
  longlong local_res8 [4];
  
  local_res8[0] = 0;
  lVar1 = (**(code **)(*(longlong *)(*param_1 + -0x10) + 8))(*param_1 + -0x38,param_1[1],local_res8)
  ;
  if (lVar1 != 0) {
    NdisMIndicateReceiveNetBufferLists(*(undefined8 *)(local_res8[0] + 0x38),lVar1,0,1,0);
  }
  return;
}



===== TunnelNlcReceiveDatagrams @ 1c000e720 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void TunnelNlcReceiveDatagrams(longlong *param_1)

{
  longlong lVar1;
  char cVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined *puVar8;
  longlong lVar9;
  int iVar10;
  longlong lVar11;
  undefined1 auStackY_b8 [32];
  longlong local_88;
  undefined8 local_80;
  longlong *local_78;
  undefined8 local_70;
  longlong *local_68;
  undefined local_60 [40];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_68 = &local_88;
  plVar7 = (longlong *)param_1[2];
  plVar5 = (longlong *)0x0;
  local_80 = 0;
  plVar6 = (longlong *)(*param_1 + -0x38);
  local_70 = 0;
  lVar11 = 0;
  iVar10 = 0;
  local_88 = 0;
  lVar9 = 0;
  local_78 = plVar6;
  if (plVar7 != (longlong *)0x0) {
    do {
      lVar1 = plVar7[1];
      if (*(int *)(plVar7[4] + 0x18) - 3U < 2) {
LAB_1c000e826:
        *(undefined4 *)(lVar1 + 0x8c) = 0xc000021b;
      }
      else {
        puVar8 = local_60;
        cVar2 = (**(code **)plVar6[5])(plVar7,lVar1,puVar8,&local_80);
        if (cVar2 == '\0') {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
            puVar8 = &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                    &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids);
          }
          if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
            McTemplateK0_EtwWriteTransfer
                      (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,
                       &EVENT_TUNNEL_PACKET_WITH_INCOMPLETE_INNER_IP_HEADER,puVar8);
          }
          goto LAB_1c000e826;
        }
        puVar8 = (undefined *)plVar7[3];
        puVar4 = *(undefined8 **)(plVar7[4] + 8);
        plVar6 = TunnelNlFindReceiver
                           (plVar6,(undefined4 *)*puVar4,puVar8,**(undefined8 **)(plVar7[4] + 0x10),
                            local_80,*(undefined4 *)(puVar4 + 1));
        if (plVar6 == (longlong *)0x0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
            puVar8 = &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids;
            WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                    &WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids);
          }
          if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
            McTemplateK0_EtwWriteTransfer
                      (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,
                       &EVENT_TUNNEL_INTERFACE_NOT_FOUND_FOR_PACKET,puVar8);
          }
          *(undefined4 *)(lVar1 + 0x8c) = 0xc000023e;
        }
        else {
          plVar3 = (longlong *)
                   TunnelNlReceiveHelper
                             ((longlong)plVar7,lVar1,(undefined *)plVar6,plVar7[3],local_70,local_80
                             );
          if (plVar3 == (longlong *)0x0) {
            *(int *)((longlong)plVar6 + 0x7c) = *(int *)((longlong)plVar6 + 0x7c) + 1;
            TunnelInterfaceDereferenceExImp((longlong)plVar6,1,(undefined *)0x0);
          }
          else {
            if (plVar6 != plVar5) {
              if (plVar5 != (longlong *)0x0) {
                *(int *)((longlong)plVar5 + 0x74) = *(int *)((longlong)plVar5 + 0x74) + iVar10;
                plVar5[0x12] = plVar5[0x12] + lVar9;
                NdisMIndicateReceiveNetBufferLists(plVar5[7],lVar11,0,iVar10);
              }
              iVar10 = 0;
              local_68 = &local_88;
              lVar9 = 0;
              local_88 = 0;
              plVar5 = plVar6;
            }
            iVar10 = iVar10 + 1;
            for (puVar4 = (undefined8 *)plVar3[1]; puVar4 != (undefined8 *)0x0;
                puVar4 = (undefined8 *)*puVar4) {
              lVar9 = lVar9 + (ulonglong)*(uint *)(puVar4 + 3);
            }
            *local_68 = (longlong)plVar3;
            lVar11 = local_88;
            local_68 = plVar3;
          }
        }
        plVar6 = local_78;
      }
      plVar7 = (longlong *)*plVar7;
    } while (plVar7 != (longlong *)0x0);
    if (lVar11 != 0) {
      *(int *)((longlong)plVar5 + 0x74) = *(int *)((longlong)plVar5 + 0x74) + iVar10;
      plVar5[0x12] = plVar5[0x12] + lVar9;
      NdisMIndicateReceiveNetBufferLists(plVar5[7],lVar11,0,iVar10);
    }
  }
  return;
}



===== TunnelP2mpInitializeSpecific @ 1c000ea00 =====

undefined8 TunnelP2mpInitializeSpecific(longlong param_1)

{
  TunnelNlInitializeLocalAddressObject(param_1);
  return 0;
}



===== TunnelP2mpQueryAcceptPacket @ 1c000ea20 =====

void TunnelP2mpQueryAcceptPacket(longlong param_1)

{
  int in_stack_00000028;
  
  TunnelIsPhysicalInterfaceAssociatedWithTunnel(param_1,in_stack_00000028,(undefined8 *)0x0);
  return;
}



===== TunnelP2pGetPhysicalInterface @ 1c000ea40 =====

undefined8 TunnelP2pGetPhysicalInterface(void)

{
  return 0xc0000002;
}



===== TunnelP2pInitializeSpecific @ 1c000ea50 =====

undefined8 TunnelP2pInitializeSpecific(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  uint uVar2;
  uint local_res8 [2];
  
  local_res8[0] = 0;
  uVar2 = *(int *)(param_1 + 0xfc) + 8;
  if (uVar2 == *(int *)(param_2 + 0x14) + 8U) {
    memcpy((void *)(param_1 + 0xdc),(void *)(param_2 + 0x38),(ulonglong)uVar2);
    *(undefined4 *)(param_1 + 0xe0) = 0xe0000000;
    TunnelNlInitializeLocalAddressObject(param_1);
    TunnelNlSetCurrentAddress
              (param_1,(undefined4 *)(param_2 + 0x18),*(int *)(param_2 + 0x14) + 8,local_res8);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xc0010015;
  }
  return uVar1;
}



===== TunnelP2pMapInnerSourceToOuter @ 1c000eae0 =====

undefined8 TunnelP2pMapInnerSourceToOuter(undefined8 param_1,longlong param_2)

{
  return **(undefined8 **)(*(longlong *)(param_2 + 0x100) + 0x10);
}



===== TunnelP2pPacketIntegrityCheck @ 1c000eb00 =====

undefined1 TunnelP2pPacketIntegrityCheck(void)

{
  return 1;
}



===== TunnelP2pQueryAcceptPacket @ 1c000eb10 =====

undefined1 TunnelP2pQueryAcceptPacket(longlong param_1,void *param_2,void *param_3)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  
  uVar1 = *(uint *)(param_1 + 0xfc);
  iVar2 = memcmp((void *)(param_1 + 0xc4),param_2,(ulonglong)uVar1);
  uVar3 = 0;
  if (iVar2 == 0) {
    iVar2 = memcmp((void *)(param_1 + 0xe4),param_3,(ulonglong)uVar1);
    if (iVar2 == 0) {
      uVar3 = 1;
    }
  }
  return uVar3;
}



===== TunnelReferenceLocalAddressByRequest @ 1c000eb7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 TunnelReferenceLocalAddressByRequest(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = (**(code **)(*(longlong *)(param_1 + 8) + 0x90))(param_2);
  if (iVar1 < 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined8 *)(param_2 + 0x18);
  }
  return uVar2;
}



===== WPP_SF_Ddd @ 1c000ebb4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Ddd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_85c3e440199236d985a4ad1a4e3df00f_Traceguids,param_2,local_res20,4,
             &param_5,4,&param_6,4,0);
  return;
}



===== McTemplateK0qbr0br0_EtwWriteTransfer @ 1c000ec18 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qbr0br0_EtwWriteTransfer(undefined8 *param_1)

{
  undefined1 auStackY_98 [32];
  undefined4 local_68 [4];
  undefined8 local_58 [2];
  undefined4 *local_48;
  undefined8 local_40;
  undefined8 local_30;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_48 = local_68;
  local_68[0] = 0x10;
  local_40 = 4;
  local_30 = 0x10;
  local_20 = 0x10;
  McGenEventWrite_EtwWriteTransfer(param_1,&EVENT_TUNNEL_NON_TEREDO_FLOW_SKIPPED,0x10,4,local_58);
  return;
}



===== McTemplateK0qqhh_EtwWriteTransfer @ 1c000ec98 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqhh_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  undefined4 *local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_58 = local_res20;
  local_50 = 4;
  local_48 = &param_5;
  local_40 = 4;
  local_38 = &param_6;
  local_30 = 2;
  local_28 = &param_7;
  local_20 = 2;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&EVENT_TUNNEL_TEREDO_V4FLOW_CREATED,param_3,5,local_68);
  return;
}



===== McTemplateK0qqqbr0br0q_EtwWriteTransfer @ 1c000ed30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqqbr0br0q_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined1 auStackY_c8 [32];
  undefined4 local_98 [2];
  undefined4 local_90 [2];
  undefined8 local_88 [2];
  undefined4 *local_78;
  undefined8 local_70;
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_70 = 4;
  local_78 = local_98;
  local_90[0] = 0;
  local_68 = &param_5;
  local_58 = &param_6;
  local_48 = param_7;
  local_38 = param_8;
  local_28 = local_90;
  local_98[0] = 0x10;
  local_40 = 0x10;
  local_30 = 0x10;
  local_60 = 4;
  local_50 = 4;
  local_20 = 4;
  McGenEventWrite_EtwWriteTransfer(param_1,&EVENT_TUNNEL_TEREDO_V6FLOW_CREATED,param_3,7,local_88);
  return;
}



===== McTemplateK0xxx_EtwWriteTransfer @ 1c000ede8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0xxx_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_48 = &local_res20;
  local_40 = 8;
  local_38 = &param_5;
  local_30 = 8;
  local_28 = &param_6;
  local_20 = 8;
  local_res20 = param_4;
  McGenEventWrite_EtwWriteTransfer
            (param_1,&EVENT_TUNNEL_TEREDO_CALLOUT_WRITE_NOT_PERMITTED,param_3,4,local_58);
  return;
}



===== TeredoRegisterWithWfp @ 1c000ee70 =====

ulonglong TeredoRegisterWithWfp(undefined *param_1,undefined8 param_2,ulonglong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined *puVar3;
  ulonglong uVar4;
  
  puVar3 = param_1;
  uVar2 = TeredoInitializeHashTable();
  uVar4 = uVar2 & 0xffffffff;
  if (-1 < (int)uVar2) {
    puVar3 = param_1;
    uVar1 = TeredoWfpRegisterCallouts((longlong)param_1);
    uVar4 = (ulonglong)uVar1;
    if (-1 < (int)uVar1) {
      param_3 = 0;
      param_2 = 0;
      ExInitializeNPagedLookasideList(&TwUdpHeaderPool,0,0,0x200,0x108,0x75437754,0);
      TwUdpHeaderPoolInitialized = 1;
      puVar3 = param_1;
      uVar2 = TeredoInitializeWorkQueues((longlong)param_1);
      uVar4 = uVar2 & 0xffffffff;
      if (-1 < (int)uVar2) {
        DAT_1c001a0c0 = param_1;
        return uVar2;
      }
    }
  }
  TeredoUnregisterWithWfp(puVar3,param_2,param_3);
  return uVar4;
}



===== TeredoWfpAleLayerNotify @ 1c000ef10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 TeredoWfpAleLayerNotify(void)

{
  LOCK();
  _DAT_1c00173a8 = _DAT_1c00173a8 + 1;
  UNLOCK();
  return 0;
}



===== TunnelUserMapIcmpStub @ 1c000ef30 =====

undefined8 TunnelUserMapIcmpStub(void)

{
  return 0;
}



===== TeredoWfpEnableOffload @ 1c000ef3c =====

ulonglong TeredoWfpEnableOffload(undefined *param_1,undefined8 param_2,ulonglong param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  puVar2 = &local_28;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10) + 0x18);
  if (*(int *)(param_1 + 0x18) == 0xe) {
    if ((*(uint *)(param_1 + 0xb8) & 4) == 0) {
      uVar1 = *(uint *)(param_1 + 0x2c8);
      if ((uVar1 & 8) != 0) {
        uVar3 = 0;
        goto LAB_1c000efa0;
      }
      if ((uVar1 & 0x10) == 0) {
        *(uint *)(param_1 + 0x2c8) = uVar1 | 0x10;
        KeResetEvent(param_1 + 0x208);
        KeReleaseInStackQueuedSpinLock(&local_28);
        uVar3 = TeredoRegisterWithWfp(param_1,puVar2,param_3);
        RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10) + 0x18);
        if (-1 < (int)uVar3) {
          *(uint *)(param_1 + 0x2c8) = *(uint *)(param_1 + 0x2c8) | 8;
          KeResetEvent(param_1 + 0x228);
          *(uint *)(param_1 + 0x220) = 2;
          RoReferenceEx((uint *)(param_1 + 0x220),1);
        }
        *(uint *)(param_1 + 0x2c8) = *(uint *)(param_1 + 0x2c8) & 0xffffffef;
        KeReleaseInStackQueuedSpinLock(&local_28);
        KeSetEvent(param_1 + 0x208,0,0);
        return uVar3 & 0xffffffff;
      }
    }
    uVar3 = 0xc00000a3;
  }
  else {
    uVar3 = 0xc000000d;
  }
LAB_1c000efa0:
  KeReleaseInStackQueuedSpinLock(&local_28);
  return uVar3;
}



===== TeredoWfpQueryCachedState @ 1c000f084 =====

undefined8 TeredoWfpQueryCachedState(ulonglong *param_1,undefined4 *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong *local_res8;
  
  *param_2 = 0;
  local_res8 = (longlong *)0x0;
  puVar3 = param_1 + 2;
  uVar5 = 0;
  uVar4 = 0xc0000225;
  TeredoWfpLocateOrCreateV6Flow(param_1,puVar3,'\0','\0',&local_res8);
  if (local_res8 != (longlong *)0x0) {
    uVar1 = local_res8[0x13];
    uVar2 = local_res8[0x14];
    *param_2 = 0x48;
    *param_1 = uVar1;
    param_1[1] = uVar2;
    uVar1 = local_res8[0x16];
    param_1[2] = local_res8[0x15];
    param_1[3] = uVar1;
    uVar1 = local_res8[0x18];
    param_1[4] = local_res8[0x17];
    param_1[5] = uVar1;
    param_1[6] = local_res8[0x19];
    TeredoWfpDereferenceFlowContextImp(local_res8,puVar3,uVar5);
    uVar4 = 0;
  }
  return uVar4;
}



===== McTemplateK0qqqqq_EtwWriteTransfer @ 1c000f11c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0qqqqq_EtwWriteTransfer
               (undefined8 *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 local_res20 [2];
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined4 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
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
  local_58 = &param_5;
  local_50 = 4;
  local_48 = &param_6;
  local_40 = 4;
  local_38 = &param_7;
  local_28 = &param_8;
  local_30 = 4;
  local_20 = 4;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer
            (param_1,&EVENT_TUNNEL_V4ADDRESS_ASSOCIATED_WITH_INTERFACE,param_3,6,local_78);
  return;
}



===== TunnelDriverDispatchCleanup @ 1c000f1d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 TunnelDriverDispatchCleanup(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (param_1 == DAT_1c001a6d8) {
    *(undefined4 *)(param_2 + 0x30) = 0;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    uVar2 = 0;
  }
  else {
    lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x20);
    if (lVar1 == 0) {
      uVar2 = 0xc0000225;
    }
    else {
      uVar2 = (**(code **)(*(longlong *)(lVar1 + 0x20) + 0x68))(param_1);
    }
  }
  return uVar2;
}



===== TunnelDriverDispatchUnsupported @ 1c000f240 =====

undefined8 TunnelDriverDispatchUnsupported(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
  IofCompleteRequest(param_2,0);
  return 0xc00000bb;
}



===== TunnelInitSetGeneralAttributes @ 1c000f270 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TunnelInitSetGeneralAttributes(undefined8 param_1,longlong param_2)

{
  int iVar1;
  undefined1 auStack_128 [32];
  undefined4 local_108 [2];
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  int local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined8 local_c0;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  ushort local_ac;
  undefined1 local_aa [32];
  undefined1 local_8a [34];
  undefined8 local_68;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined2 local_54;
  undefined1 local_52;
  undefined4 local_50;
  undefined *local_40;
  undefined4 local_38;
  undefined8 local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_128;
  memset(local_108,0,0xe0);
  local_f8 = *(undefined4 *)(param_2 + 0x58);
  local_5c = 0;
  local_b8 = 8;
  local_f0 = 100000;
  local_e0 = 100000;
  local_e8 = 100000;
  local_d8 = 100000;
  local_54 = 0x83;
  local_108[0] = 0xe0029f;
  local_100 = 0xf;
  local_c0 = 0;
  local_60 = (*(int *)(param_2 + 0x18) != 2) + 3;
  local_30 = 0;
  local_b0 = 0;
  local_ac = *(short *)(param_2 + 0xfc) + 8;
  local_cc = 2;
  local_c8 = 0x10000;
  local_58 = 1;
  local_52 = 0;
  local_b4 = 0x21;
  memcpy(local_aa,(void *)(param_2 + 0xbc),(ulonglong)local_ac);
  memcpy(local_8a,(void *)(param_2 + 0xbc),(ulonglong)local_ac);
  local_fc = 0;
  local_68 = 0;
  local_40 = &TunnelSupportedOidArray;
  local_50 = 0x40001f;
  local_38 = 0x88;
  local_d0 = 2 - (uint)(*(longlong *)(param_2 + 0x100) != 0);
  iVar1 = NdisMSetMiniportAttributes(param_1,local_108);
  if ((iVar1 != 0) && (*(longlong *)(param_2 + 0x100) != 0)) {
    TunnelNlDereferenceLocalAddressObject
              ((undefined8 *)(*(longlong *)(param_2 + 0x10) + 0x38),*(longlong *)(param_2 + 0x100));
  }
  return iVar1;
}



===== TunnelInsertPhysicalInterfaceAssociationForTunnel @ 1c000f400 =====

undefined8
TunnelInsertPhysicalInterfaceAssociationForTunnel(longlong param_1,uint *param_2,char param_3)

{
  uint *puVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  code *pcVar4;
  undefined8 uVar5;
  longlong *plVar6;
  undefined8 *puVar7;
  longlong lVar8;
  ulonglong uVar9;
  longlong *local_res8;
  longlong local_res20;
  undefined8 local_48;
  undefined8 local_40;
  uint *local_38;
  
  local_res8 = (longlong *)0x0;
  local_res20 = 0;
  local_48 = 0;
  local_40 = 0;
  if (3 < *(uint *)(*(longlong *)(param_1 + 0x10) + 0x10)) {
    return 0xc00000bb;
  }
  uVar5 = TunnelIsPhysicalInterfaceAssociatedWithTunnel(param_1,param_2[1],&local_res8);
  if ((char)uVar5 == '\0') {
    plVar6 = (longlong *)ExAllocatePool2(0x40,0x28,0x69507554);
    if (plVar6 != (longlong *)0x0) {
      *(uint *)(plVar6 + 2) = param_2[1];
      plVar2 = plVar6 + 3;
      plVar6[4] = (longlong)plVar2;
      *plVar2 = (longlong)plVar2;
      plVar2 = *(longlong **)(param_1 + 0xa0);
      if (*plVar2 != param_1 + 0x98) goto LAB_1c000f65c;
      *plVar6 = param_1 + 0x98;
      plVar6[1] = (longlong)plVar2;
      *plVar2 = (longlong)plVar6;
      *(longlong **)(param_1 + 0xa0) = plVar6;
      goto LAB_1c000f4c2;
    }
LAB_1c000f47a:
    uVar5 = 0xc000009a;
  }
  else {
    plVar6 = local_res8;
LAB_1c000f4c2:
    puVar1 = param_2 + 2;
    uVar5 = TunnelIsV4AddressAssociatedWithPhysicalInterface((longlong)plVar6,*puVar1,&local_res20);
    if ((char)uVar5 != '\0') {
      if (param_3 == '\0') {
        return 0;
      }
      if (*(uint *)(local_res20 + 0x14) == param_2[4]) {
        return 0;
      }
      *(uint *)(local_res20 + 0x14) = param_2[4];
      TunnelNlInvalidateRoutingEpoch
                (*(longlong *)(param_1 + 0x10) + 0x38,
                 **(undefined8 **)(*(longlong *)(local_res20 + 0x18) + 8));
      return 0;
    }
    puVar7 = (undefined8 *)ExAllocatePool2(0x40,0x20,0x34567554);
    if (puVar7 == (undefined8 *)0x0) goto LAB_1c000f47a;
    *(uint *)(puVar7 + 2) = *puVar1;
    *(uint *)((longlong)puVar7 + 0x14) = param_2[4];
    uVar9 = (ulonglong)*param_2;
    local_38 = puVar1;
    lVar8 = TunnelNlReferenceLocalAddressByArgs2
                      ((undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x38),&local_48,*param_2);
    puVar7[3] = lVar8;
    if (lVar8 != 0) {
      uVar5 = **(undefined8 **)(lVar8 + 8);
      TunnelNlInvalidateRoutingEpoch(*(longlong *)(param_1 + 0x10) + 0x38,uVar5);
      puVar3 = (undefined8 *)plVar6[4];
      if ((longlong *)*puVar3 == plVar6 + 3) {
        *puVar7 = plVar6 + 3;
        puVar7[1] = puVar3;
        *puVar3 = puVar7;
        plVar6[4] = (longlong)puVar7;
        if (DAT_1c0017024 == 0) {
          return 0;
        }
        if ((Microsoft_Windows_TunnelDriverEnableBits & 1) == 0) {
          return 0;
        }
        McTemplateK0qqqqq_EtwWriteTransfer
                  (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,uVar5,uVar9,*(undefined4 *)(param_1 + 0x18)
                   ,(char)*(undefined4 *)(param_1 + 0x28),(char)*puVar1,1,(char)param_2[1]);
        return 0;
      }
      goto LAB_1c000f65c;
    }
    uVar5 = 0xc0000001;
    ExFreePoolWithTag(puVar7,0x34567554);
  }
  if ((plVar6 != (longlong *)0x0) && ((longlong *)plVar6[3] == plVar6 + 3)) {
    lVar8 = *plVar6;
    if ((*(longlong **)(lVar8 + 8) != plVar6) ||
       (plVar2 = (longlong *)plVar6[1], (longlong *)*plVar2 != plVar6)) {
LAB_1c000f65c:
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      uVar5 = (*pcVar4)();
      return uVar5;
    }
    *plVar2 = lVar8;
    *(longlong **)(lVar8 + 8) = plVar2;
    ExFreePoolWithTag(plVar6,0x69507554);
  }
  return uVar5;
}



===== TunnelIsNlLocalAddressAssociatedWithTunnel @ 1c000f66c =====

undefined1
TunnelIsNlLocalAddressAssociatedWithTunnel
          (longlong param_1,longlong param_2,int *param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  *param_4 = 0;
  puVar2 = *(undefined8 **)(param_1 + 0x98);
  do {
    if (puVar2 == (undefined8 *)(param_1 + 0x98)) {
      return 0;
    }
    for (puVar1 = (undefined8 *)puVar2[3]; puVar1 != puVar2 + 3; puVar1 = (undefined8 *)*puVar1) {
      if (((param_2 != 0) && (puVar1[3] == param_2)) ||
         ((param_3 != (int *)0x0 && (*param_3 == *(int *)(puVar1 + 2))))) {
        *param_4 = puVar1;
        return 1;
      }
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== TunnelIsPhysicalInterfaceAssociatedWithTunnel @ 1c000f6d8 =====

undefined8
TunnelIsPhysicalInterfaceAssociatedWithTunnel(longlong param_1,int param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  puVar1 = *(undefined8 **)(param_1 + 0x98);
  do {
    if (puVar1 == (undefined8 *)(param_1 + 0x98)) {
LAB_1c000f6ff:
      return CONCAT71((int7)((ulonglong)puVar1 >> 8),uVar2);
    }
    if (*(int *)(puVar1 + 2) == param_2) {
      uVar2 = 1;
      if (param_3 != (undefined8 *)0x0) {
        *param_3 = puVar1;
      }
      goto LAB_1c000f6ff;
    }
    puVar1 = (undefined8 *)*puVar1;
  } while( true );
}



===== TunnelIsV4AddressAssociatedWithPhysicalInterface @ 1c000f70c =====

undefined8
TunnelIsV4AddressAssociatedWithPhysicalInterface(longlong param_1,int param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  puVar1 = *(undefined8 **)(param_1 + 0x18);
  do {
    if (puVar1 == (undefined8 *)(param_1 + 0x18)) {
LAB_1c000f730:
      return CONCAT71((int7)((ulonglong)puVar1 >> 8),uVar2);
    }
    if (*(int *)(puVar1 + 2) == param_2) {
      uVar2 = 1;
      if (param_3 != (undefined8 *)0x0) {
        *param_3 = puVar1;
      }
      goto LAB_1c000f730;
    }
    puVar1 = (undefined8 *)*puVar1;
  } while( true );
}



===== TunnelMiniportCancelDirectOidRequest @ 1c000f740 =====

void TunnelMiniportCancelDirectOidRequest(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  byte bVar3;
  ulonglong uVar4;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)
     ) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_2,
              (char)*(undefined4 *)(param_1 + 0x28));
  }
  if (param_2 == *(longlong *)(*(longlong *)(param_1 + 0x50) + 0x10)) {
    RtlAcquireWriteLock(lVar1 + 0x18);
    lVar1 = *(longlong *)(param_1 + 0x50);
    *(undefined8 *)(param_1 + 0x50) = 0;
    KeReleaseInStackQueuedSpinLock(&local_28);
    if (lVar1 != 0) {
      LOCK();
      UNLOCK();
      uVar4 = (longlong)PnpRecordIndex % 0x20 & 0xffffffff;
      PnpRecordIndex = PnpRecordIndex + 1;
      *(longlong *)(&DAT_1c001a168 + uVar4 * 0x28) = param_1;
      *(undefined8 *)(&DAT_1c001a170 + uVar4 * 0x28) = *(undefined8 *)(param_1 + 0x38);
      *(undefined4 *)(&PnpRecords + uVar4 * 0x28) = 3;
      uVar2 = *(undefined8 *)(param_1 + 0x48);
      *(undefined4 *)(&DAT_1c001a180 + uVar4 * 0x28) = 0;
      *(undefined8 *)(&DAT_1c001a178 + uVar4 * 0x28) = uVar2;
      bVar3 = (&DAT_1c001a184)[uVar4 * 0x28] & 0xfe;
      (&DAT_1c001a184)[uVar4 * 0x28] = bVar3;
      bVar3 = (bVar3 ^ *(byte *)(param_1 + 0xb8)) & 2 ^ bVar3;
      (&DAT_1c001a184)[uVar4 * 0x28] = bVar3;
      bVar3 = (*(byte *)(param_1 + 0xb8) & 1) << 2 | bVar3 & 0xfb;
      (&DAT_1c001a184)[uVar4 * 0x28] = bVar3;
      (&DAT_1c001a184)[uVar4 * 0x28] = ((byte)(*(uint *)(param_1 + 0xb8) >> 3) ^ bVar3) & 8 ^ bVar3;
      NdisMOidRequestComplete(*(undefined8 *)(param_1 + 0x38),lVar1,0xc001000c);
    }
  }
  return;
}



===== TunnelMiniportCancelOidRequest @ 1c000f8b0 =====

void TunnelMiniportCancelOidRequest(longlong param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)
     ) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
             &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(undefined4 *)(param_1 + 0x28));
  }
  return;
}



===== TunnelMiniportCancelSend @ 1c000f900 =====

void TunnelMiniportCancelSend(longlong param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)
     ) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
             &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(undefined4 *)(param_1 + 0x28));
  }
  return;
}



===== TunnelMiniportCleanupOrphanLWMs @ 1c000f950 =====

void TunnelMiniportCleanupOrphanLWMs(void)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined *puVar5;
  ulonglong uVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  uVar6 = 0;
  local_18 = 0;
  puVar5 = (undefined *)0x0;
  KeWaitForSingleObject(&DAT_1c001aa70,0,0,0,0);
  plVar4 = &DAT_1c001a6f0;
  lVar2 = 5;
  do {
    RtlAcquireWriteLock((longlong)(plVar4 + 3));
    plVar3 = (longlong *)*plVar4;
    while (plVar3 != plVar4) {
      plVar1 = (longlong *)*plVar3;
      KeReleaseInStackQueuedSpinLock(&local_28);
      TunnelMiniportHaltLWM(plVar3,(longlong)plVar4,puVar5,uVar6);
      RtlAcquireWriteLock((longlong)(plVar4 + 3));
      plVar3 = plVar1;
    }
    KeReleaseInStackQueuedSpinLock();
    plVar4 = plVar4 + 0xe;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  KeReleaseMutex(&DAT_1c001aa70,0);
  return;
}



===== TunnelMiniportRestart @ 1c000fa40 =====

undefined8 TunnelMiniportRestart(longlong param_1,undefined8 param_2,undefined *param_3)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  RtlAcquireWriteLock(*(longlong *)(param_1 + 0x10) + 0x18);
  *(uint *)(param_1 + 0xb8) = *(uint *)(param_1 + 0xb8) & 0xfffffffd;
  if ((*(uint *)(param_1 + 0xb8) & 0x40) == 0) {
    *(undefined4 *)(param_1 + 0x40) = 2;
  }
  KeReleaseInStackQueuedSpinLock(&local_28);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      (3 < (byte)WPP_GLOBAL_Control[0x29])) && ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)
     ) {
    param_3 = &WPP_9608820f130d35da1284a1080d801204_Traceguids;
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,
             &WPP_9608820f130d35da1284a1080d801204_Traceguids,*(undefined4 *)(param_1 + 0x28));
  }
  if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
    McTemplateK0qqq_EtwWriteTransfer
              (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_INTERFACE_OP,param_3,
               *(undefined4 *)(param_1 + 0x18),(char)*(undefined4 *)(param_1 + 0x28),2);
  }
  return 0;
}



===== TunnelPnpLogRequestCompletion @ 1c000fb18 =====

void TunnelPnpLogRequestCompletion(longlong param_1)

{
  undefined8 uVar1;
  byte bVar2;
  ulonglong uVar3;
  
  LOCK();
  UNLOCK();
  uVar3 = (longlong)PnpRecordIndex % 0x20 & 0xffffffff;
  PnpRecordIndex = PnpRecordIndex + 1;
  *(longlong *)(&DAT_1c001a168 + uVar3 * 0x28) = param_1;
  *(undefined8 *)(&DAT_1c001a170 + uVar3 * 0x28) = *(undefined8 *)(param_1 + 0x38);
  *(undefined4 *)(&PnpRecords + uVar3 * 0x28) = 2;
  uVar1 = *(undefined8 *)(param_1 + 0x48);
  *(undefined4 *)(&DAT_1c001a180 + uVar3 * 0x28) = 0;
  *(undefined8 *)(&DAT_1c001a178 + uVar3 * 0x28) = uVar1;
  bVar2 = (&DAT_1c001a184)[uVar3 * 0x28] & 0xfe;
  (&DAT_1c001a184)[uVar3 * 0x28] = bVar2;
  bVar2 = (bVar2 ^ *(byte *)(param_1 + 0xb8)) & 2 ^ bVar2;
  (&DAT_1c001a184)[uVar3 * 0x28] = bVar2;
  bVar2 = (*(byte *)(param_1 + 0xb8) & 1) << 2 | bVar2 & 0xfb;
  (&DAT_1c001a184)[uVar3 * 0x28] = bVar2;
  (&DAT_1c001a184)[uVar3 * 0x28] = ((byte)(*(uint *)(param_1 + 0xb8) >> 3) ^ bVar2) & 8 ^ bVar2;
  return;
}



===== TunnelRemovePhysicalInterfaceAssociationForTunnel @ 1c000fbb8 =====

undefined8
TunnelRemovePhysicalInterfaceAssociationForTunnel(longlong param_1,int param_2,uint param_3)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong *plVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  longlong **pplVar7;
  int iVar8;
  undefined1 uVar9;
  longlong *local_res20;
  longlong *local_18 [2];
  
  uVar6 = (ulonglong)param_3;
  local_res20 = (longlong *)0x0;
  local_18[0] = (longlong *)0x0;
  uVar5 = TunnelIsPhysicalInterfaceAssociatedWithTunnel(param_1,param_2,&local_res20);
  plVar4 = local_res20;
  uVar9 = (undefined1)param_2;
  iVar8 = (int)uVar6;
  if ((char)uVar5 != '\0') {
    pplVar7 = local_18;
    uVar6 = uVar6 & 0xffffffff;
    uVar5 = TunnelIsV4AddressAssociatedWithPhysicalInterface((longlong)local_res20,iVar8,pplVar7);
    if ((char)uVar5 != '\0') {
      if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
        McTemplateK0qqqqq_EtwWriteTransfer
                  (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,uVar6,pplVar7,
                   *(undefined4 *)(param_1 + 0x18),(char)*(undefined4 *)(param_1 + 0x28),(char)iVar8
                   ,0,uVar9);
      }
      TunnelRemoveV4AddressAssociationForTunnel(param_1,local_18[0]);
      if ((longlong *)plVar4[3] != plVar4 + 3) {
        return 0;
      }
      lVar1 = *plVar4;
      if ((*(longlong **)(lVar1 + 8) == plVar4) &&
         (plVar2 = (longlong *)plVar4[1], (longlong *)*plVar2 == plVar4)) {
        *plVar2 = lVar1;
        *(longlong **)(lVar1 + 8) = plVar2;
        ExFreePoolWithTag(plVar4,0x69507554);
        return 0;
      }
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      uVar5 = (*pcVar3)();
      return uVar5;
    }
  }
  return 0xc0000225;
}



===== TunnelRemoveV4AddressAssociationForTunnel @ 1c000fca4 =====

undefined8 TunnelRemoveV4AddressAssociationForTunnel(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  lVar1 = *param_2;
  if ((*(longlong **)(lVar1 + 8) == param_2) &&
     (plVar2 = (longlong *)param_2[1], (longlong *)*plVar2 == param_2)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    TunnelNlDereferenceLocalAddressObject
              ((undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x38),param_2[3]);
    param_2[3] = 0;
    ExFreePoolWithTag(param_2,0x34567554);
    return 0;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  uVar4 = (*pcVar3)();
  return uVar4;
}



===== TunnelUninitializeWorkQueue @ 1c000fd08 =====

void TunnelUninitializeWorkQueue(void)

{
  KeWaitForSingleObject(&DAT_1c001a9d8,0,0,0,0);
  IoFreeWorkItem(DAT_1c001a9b8);
  DAT_1c001a9b8 = 0;
  return;
}



===== WPP_SF_DD @ 1c000fd54 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4,
              undefined1 param_5)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_9608820f130d35da1284a1080d801204_Traceguids,param_2,local_res20,4,
             &param_5,4,0);
  return;
}



===== _tlgDefineProvider_annotation__Tlgg_TunnelTelemetryProviderProv @ 1c000fdac =====

void _tlgDefineProvider_annotation__Tlgg_TunnelTelemetryProviderProv(void)

{
  return;
}



===== McGenControlCallbackV2 @ 1c000fdc0 =====

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



===== McGenEventUnregister_EtwUnregister @ 1c000fed0 =====

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



===== EtwEx_tidActivityInfoTransfer @ 1c000ff04 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void EtwEx_tidActivityInfoTransfer(void)

{
  undefined1 auStack_78 [32];
  undefined4 local_58;
  undefined **local_50;
  undefined4 local_48 [2];
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined *local_30;
  undefined8 local_28;
  undefined4 *local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_78;
  local_48[0] = 1;
  local_40 = 0x1000ea63;
  uStack_3c = 0x901;
  uStack_38 = 1;
  uStack_34 = 0x80000000;
  if (Microsoft_Windows_Networking_CorrelationTraceActivityPayload == 0) {
    local_50 = (undefined **)0x0;
    local_58 = 0;
  }
  else {
    local_28 = 0x10;
    local_30 = &Microsoft_Windows_Networking_ProviderId;
    local_20 = local_48;
    local_50 = &local_30;
    local_58 = 2;
    local_18 = 4;
  }
  EtwWriteTransfer(Microsoft_Windows_Networking_CorrelationHandle,&local_40);
  return;
}



===== TunnelIpTlsInitializeSpecific @ 1c000ffb0 =====

int TunnelIpTlsInitializeSpecific(longlong param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined *puVar4;
  
  *(undefined **)(param_1 + 0x2d8) = &g_TunnelIpTlsUserDevicePath;
  puVar4 = &g_TunnelIpTlsNtDevicePath;
  iVar1 = TunnelRegisterDevice
                    (*(undefined8 *)(DAT_1c001a6d8 + 8),&g_TunnelIpTlsNtDevicePath,
                     &g_TunnelIpTlsUserDevicePath,(longlong *)(param_1 + 0x120));
  if (iVar1 == 0) {
    uVar2 = TunnelUserAllocatePacketPools(param_1,puVar4,'\0');
    iVar1 = (int)uVar2;
    if (iVar1 == 0) {
      *(uint *)(param_1 + 0x2c8) = *(uint *)(param_1 + 0x2c8) | 0x20;
      lVar3 = IoAllocateWorkItem(*(longlong *)(param_1 + 0x120));
      *(longlong *)(param_1 + 0x1c8) = lVar3;
      if (lVar3 != 0) {
        return 0;
      }
      iVar1 = -0x3fffff66;
    }
  }
  TunnelUserFreeWorkItem(param_1);
  TunnelUserFreePacketPools(param_1);
  TunnelUserDestroyDevice(param_1);
  return iVar1;
}



===== TunnelTeredoSetCurrentAddress @ 1c0010070 =====

undefined8
TunnelTeredoSetCurrentAddress(longlong param_1,undefined8 *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 local_res10 [3];
  longlong local_18 [2];
  
  local_res10[0] = 0;
  if (param_3 == 0x1e) {
    *(undefined4 *)(param_1 + 0xfc) = 0x1e;
    uVar2 = param_2[1];
    *(undefined8 *)(param_1 + 0xbc) = *param_2;
    *(undefined8 *)(param_1 + 0xc4) = uVar2;
    *(undefined8 *)(param_1 + 0xcc) = param_2[2];
    *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_2 + 3);
    *(undefined2 *)(param_1 + 0xd8) = *(undefined2 *)((longlong)param_2 + 0x1c);
    *param_4 = 0x1e;
    local_18[0] = TunnelUserGetNextHopInterfaceV4(~*(uint *)((longlong)param_2 + 10));
    if (local_18[0] != 0) {
      iVar1 = NsiGetParameter(1,&NPI_MS_NDIS_MODULEID,0,local_18,8,1,local_res10,8,0x18);
      if (-1 < iVar1) {
        *(undefined8 *)(param_1 + 0x68) = local_res10[0];
      }
    }
    uVar2 = 0;
  }
  else {
    *param_4 = 0;
    uVar2 = 0xc0010015;
  }
  return uVar2;
}



===== TunnelUserAllocateNblsForIrp @ 1c001013c =====

int TunnelUserAllocateNblsForIrp
              (longlong param_1,longlong param_2,undefined4 *param_3,undefined8 *param_4,
              int *param_5)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  int iVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  longlong lVar9;
  int local_78;
  undefined8 *local_70;
  longlong local_68;
  ulonglong local_60;
  longlong local_58;
  
  lVar5 = *(longlong *)(param_2 + 8);
  iVar3 = 0;
  local_78 = 0;
  puVar7 = (undefined8 *)0x0;
  lVar9 = 0;
  uVar8 = (ulonglong)*(uint *)(lVar5 + 0x28);
  puVar6 = (undefined8 *)0x0;
  local_58 = lVar5;
  while( true ) {
    if (uVar8 == 0) {
      *param_3 = (int)lVar9;
      *param_4 = puVar7;
      *param_5 = local_78;
      return iVar3;
    }
    local_68 = 0;
    local_60 = 0;
    local_70 = (undefined8 *)0x0;
    uVar4 = TunnelUserGetPacketLength
                      (lVar5,*(undefined8 *)(param_2 + 8),lVar9,(longlong *)&local_60);
    uVar2 = local_60;
    iVar3 = (int)uVar4;
    if (iVar3 < 0) break;
    if ((uVar8 < local_60) || (0x500 < local_60)) {
      iVar3 = -0x3ffffff3;
      break;
    }
    uVar4 = TunnelUserAllocateNblForIndication(param_1,&local_70);
    puVar1 = local_70;
    iVar3 = (int)uVar4;
    if (iVar3 < 0) break;
    if (puVar7 == (undefined8 *)0x0) {
      puVar7 = local_70;
    }
    else {
      *puVar6 = local_70;
    }
    local_78 = local_78 + 1;
    RtlCopyMdlToMdl(local_58,lVar9,*(undefined8 *)(local_70[1] + 0x20),0,uVar2,&local_68);
    lVar5 = puVar1[1];
    uVar8 = uVar8 - uVar2;
    *(undefined4 *)(lVar5 + 0x18) = (undefined4)local_68;
    puVar1[0x19] = 0xdd86;
    lVar9 = lVar9 + local_68;
    puVar6 = puVar1;
  }
  TunnelUserRestoreAndFreeNblAndNbState(puVar7,'\x01','\0',0,0,0);
  return iVar3;
}



===== TunnelUserDispatchIoControl @ 1c00102e0 =====

undefined4 TunnelUserDispatchIoControl(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar6 = 0;
  iVar1 = *(int *)(lVar2 + 0x18);
  lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x30) + 0x20);
  if ((((iVar1 == 0x12cc04) || (iVar1 == 0x12cc08)) || (iVar1 == 0x12cc0c)) ||
     ((iVar1 == 0x12cc10 || (iVar1 != 0x12cc34)))) {
    uVar6 = 0xc00000bb;
  }
  else if (*(int *)(lVar2 + 0x10) == 8) {
    puVar4 = *(undefined8 **)(param_2 + 0x18);
    uVar5 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x118);
    if ((*(uint *)(lVar3 + 0x2c8) & 1) == 0) {
      *(undefined8 *)(lVar3 + 0x2d0) = *puVar4;
    }
    else {
      uVar6 = 0xc0000184;
      TunnelUserSignalCloseComplete(lVar3);
    }
    KeReleaseSpinLock(lVar3 + 0x118,uVar5);
  }
  else {
    uVar6 = 0xc000000d;
  }
  *(undefined4 *)(lVar2 + 8) = 0;
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = uVar6;
  IofCompleteRequest(param_2,0);
  return uVar6;
}



===== TunnelUserGetPhysicalInterface @ 1c00103e0 =====

undefined8 TunnelUserGetPhysicalInterface(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  undefined8 uVar2;
  
  uVar2 = 0xc0010029;
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x118);
  if (((*(uint *)(param_1 + 0x2c8) & 1) == 0) && (*(longlong *)(param_1 + 0x2d0) != 0)) {
    *(longlong *)(param_2 + 0x80) = *(longlong *)(param_1 + 0x2d0);
    uVar2 = 0;
  }
  KeReleaseSpinLock(param_1 + 0x118,uVar1);
  return uVar2;
}



===== TunnelUserGetSourceAndDestination @ 1c0010470 =====

undefined1 TunnelUserGetSourceAndDestination(void)

{
  return 0;
}



===== TunnelUserGetTunnelForDevice @ 1c0010480 =====

ulonglong TunnelUserGetTunnelForDevice(undefined8 *param_1,longlong param_2)

{
  byte bVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  bVar1 = 0;
  puVar2 = (undefined8 *)*param_1;
  puVar3 = (undefined8 *)0x0;
  do {
    if (puVar2 == param_1) {
LAB_1c00104a2:
      return -(ulonglong)bVar1 & (ulonglong)puVar3;
    }
    puVar3 = puVar2;
    if (puVar2[0x24] == param_2) {
      bVar1 = 1;
      goto LAB_1c00104a2;
    }
    puVar2 = (undefined8 *)*puVar2;
  } while( true );
}



===== TunnelUserIoCancelIrp @ 1c00104b4 =====

void TunnelUserIoCancelIrp(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  undefined1 uVar1;
  longlong lVar2;
  undefined7 uVar3;
  
  uVar3 = (undefined7)((ulonglong)param_3 >> 8);
  uVar1 = *(undefined1 *)(param_2 + 0x45);
  lVar2 = *(longlong *)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x20);
  KeAcquireSpinLockAtDpcLevel(lVar2 + 0x118);
  IoReleaseCancelSpinLock(2);
  if (*(char *)(param_2 + 0x78) != '\0') {
    if ((char)param_3 == '\0') {
      TunnelUserDequeueWriteIrp(lVar2,param_2);
      TunnelInterfaceDereferenceExImp(lVar2,1,(undefined *)CONCAT71(uVar3,1));
    }
    else {
      TunnelUserDequeueReadIrp(lVar2,param_2);
    }
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
  IofCompleteRequest(param_2,0);
  KeReleaseSpinLock(lVar2 + 0x118,uVar1);
  return;
}



===== TunnelUserIoCancelRead @ 1c0010590 =====

void TunnelUserIoCancelRead(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  TunnelUserIoCancelIrp(param_1,param_2,CONCAT71((int7)((ulonglong)param_3 >> 8),1));
  return;
}



===== TunnelUserIoCancelWrite @ 1c00105b0 =====

void TunnelUserIoCancelWrite(undefined8 param_1,longlong param_2)

{
  TunnelUserIoCancelIrp(param_1,param_2,0);
  return;
}



===== TunnelUserPauseOrPowerDown @ 1c00105c8 =====

void TunnelUserPauseOrPowerDown(longlong param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x118);
  TunnelCompletePendingNdisAppSends(param_1);
  KeReleaseSpinLock(param_1 + 0x118,uVar1);
  return;
}



===== TunnelUserPauseTunnel @ 1c0010630 =====

void TunnelUserPauseTunnel(longlong param_1)

{
  TunnelUserPauseOrPowerDown(param_1);
  return;
}



===== TunnelUserPowerTransition @ 1c0010650 =====

void TunnelUserPowerTransition(longlong param_1,int param_2)

{
  if (param_2 != 1) {
    TunnelUserPauseOrPowerDown(param_1);
  }
  return;
}



===== TunnelUserQueryMediaConnectStatus @ 1c0010670 =====

uint TunnelUserQueryMediaConnectStatus(longlong param_1)

{
  return ~(*(uint *)(param_1 + 0xb8) >> 5) & 1;
}



===== TunnelUserSetCurrentAddress @ 1c0010690 =====

undefined8 TunnelUserSetCurrentAddress(longlong param_1,void *param_2,uint param_3,uint *param_4)

{
  undefined8 uVar1;
  
  if (*(int *)(param_1 + 0xfc) + 8U < param_3) {
    uVar1 = 0xc0010022;
  }
  else {
    memcpy((void *)(param_1 + 0xbc),param_2,(ulonglong)param_3);
    *(uint *)(param_1 + 0xfc) = param_3;
    uVar1 = 0;
    *param_4 = param_3;
  }
  return uVar1;
}



===== WdmlibRtlInitUnicodeStringEx @ 1c00106f0 =====

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



===== Microsoft_Windows_Networking_Correlation_EtwEnableCallback @ 1c0010740 =====

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



===== __GSHandlerCheck @ 1c0010768 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c001078c =====

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



===== __cpu_features_init @ 1c0010800 =====

/* WARNING: Removing unreachable block (ram,0x0001c001086a) */
/* WARNING: Removing unreachable block (ram,0x0001c0010819) */
/* WARNING: Removing unreachable block (ram,0x0001c001080a) */

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



===== __security_check_cookie @ 1c00108d0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0010910 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0010940 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0010940. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0010970 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 1c00109a0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_1c00109e3;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1c0010a54;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1c0010a50:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0010a54;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1c0010a4c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0010a50;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1c0010a4c;
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
LAB_1c0010a54:
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
LAB_1c00109e3:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memcpy @ 1c0010ac0 =====

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



===== memset @ 1c0010dc0 =====

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



===== __memset_repmovs @ 1c0010f00 =====

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



===== __memset_query @ 1c0010f80 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0011000 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0011140 =====

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



===== __memset_spec_plain @ 1c00111c0 =====

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



===== WppLoadTracingSupport @ 1c001f008 =====

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



===== TunnelStartEtwTrace @ 1c001f14c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 TunnelStartEtwTrace(void)

{
  int iVar1;
  
  McGenEventRegister_EtwRegister();
  if ((Microsoft_Windows_Networking_CorrelationHandle == 0) &&
     (iVar1 = EtwRegister(&Microsoft_Windows_Networking_CorrelationId,
                          Microsoft_Windows_Networking_Correlation_EtwEnableCallback,0,
                          &Microsoft_Windows_Networking_CorrelationHandle), iVar1 != 0)) {
    return 0;
  }
  uRam00000001c001a148 = 0x990292fab5b8e893;
  _Microsoft_Windows_Networking_ProviderId = 0x4cf09ed34edbe902;
  return 0;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 1c001f1a4 =====

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
  local_28 = *(undefined4 *)(PTR_DAT_1c0017058 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_1c0017058 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_1c0017058 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_1c0017058 + -4);
  if (DAT_1c0017070 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_1c0017078 = 0;
  DAT_1c0017080 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x1c001f207;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_1c0017050,&DAT_1c0017070);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_1c0017058;
    *(undefined8 *)(puVar4 + -8) = 0x1c001f22e;
    EtwSetInformation(DAT_1c0017070,2,PTR_DAT_1c0017058,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c001f242;
  return iVar3;
}



===== WppInitKm @ 1c001f250 =====

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



===== TunnelDriverUnload @ 1c001f2e0 =====

void TunnelDriverUnload(void)

{
  undefined8 uVar1;
  
  TunnelUninitializeTimer();
  KeInitializeEvent(&DAT_1c001a128,0,0);
  TunnelDereferenceDriver();
  KeWaitForSingleObject(&DAT_1c001aa20,0,0,0,0);
  DAT_1c001aa68 = 1;
  NetioFreeStackBlock(DAT_1c001a6c8,0x42537554);
  KeReleaseMutex(&DAT_1c001aa20,0);
  NetioUnRegisterProcessorAddCallback(&DAT_1c001aa58);
  TunnelNlDeregisterNlClient();
  TunnelUninitializeWorkQueue();
  NdisLWMDeregisterMiniportDriver(DAT_1c001a6e8);
  TunnelNlCloseNlClient();
  KeWaitForSingleObject(&DAT_1c001a128,6,0,0,0);
  NetioUnInitializeNetBufferListLibrary();
  IoDeleteSymbolicLink(&TunnelControlDeviceUserPath);
  IoDeleteDevice(DAT_1c001a6d8);
  WppCleanupKm();
  TunnelStopEtwTrace();
  uVar1 = DAT_1c0017070;
  DAT_1c0017070 = 0;
  DAT_1c0017050 = 0;
  EtwUnregister(uVar1);
  return;
}



===== WppCleanupKm @ 1c001f420 =====

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



===== WppTraceCallback @ 1c001f4a0 =====

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



===== _tlgEnableCallback @ 1c001f730 =====

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



===== TunnelStopEtwTrace @ 1c001f7ac =====

void TunnelStopEtwTrace(void)

{
  if (MS_TUNNEL_DRIVER_PROVIDER_ID_Context != 0) {
    EtwUnregister(Microsoft_Windows_Networking_CorrelationHandle);
    Microsoft_Windows_Networking_CorrelationHandle = 0;
    McGenEventUnregister_EtwUnregister(&MS_TUNNEL_DRIVER_PROVIDER_ID_Context);
  }
  return;
}



===== WdmlibInit @ 1c001f7f0 =====

void WdmlibInit(void)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"IoCreateDeviceSecure");
  PfnIoCreateDeviceSecure = (code *)MmGetSystemRoutineAddress(&local_18);
  if (PfnIoCreateDeviceSecure == (code *)0x0) {
    PfnIoCreateDeviceSecure = IoDevObjCreateDeviceSecure;
  }
  RtlInitUnicodeString(&local_18,L"IoValidateDeviceIoControlAccess");
  MmGetSystemRoutineAddress(&local_18);
  WdmlibInitialized = 1;
  return;
}



===== IoDevObjCreateDeviceSecure @ 1c001f880 =====

ulonglong IoDevObjCreateDeviceSecure
                    (ulonglong param_1,ulonglong param_2,longlong param_3,undefined4 param_4,
                    undefined4 param_5,undefined1 param_6,ushort *param_7,uint *param_8,
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
  if ((param_8 != (uint *)0x0) &&
     (uVar5 = param_1,
     uVar4 = PpRegStateReadCreateClassCreationSettings(param_8,param_1,(uint *)&local_68),
     (int)uVar4 < 0)) {
    return uVar4;
  }
  uVar6 = (uint)local_68;
  if ((local_68 & 2) == 0) {
    uVar5 = SeSddlSecurityDescriptorFromSDDL(param_7,uVar5,&local_res18);
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) goto LAB_1c001f9e0;
    uVar6 = 2;
    local_68 = CONCAT44(local_68._4_4_,2);
    lStack_60 = local_res18;
    if (param_8 != (uint *)0x0) {
      local_50 = 2;
      local_40 = 0;
      local_48 = local_res18;
      uVar5 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_50);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_1c001f9e0;
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
LAB_1c001f9e0:
  if ((uVar6 & 2) != 0) {
    ExFreePoolWithTag(lStack_60,0);
  }
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 1c001fa14 =====

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



===== SeSddlSecurityDescriptorFromSDDL @ 1c001fb04 =====

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



===== SepSddlAddAceToAcl @ 1c001fbe4 =====

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



===== SepSddlDaclFromSDDLString @ 1c001fce4 =====

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



===== SepSddlGetAclForString @ 1c001fdd0 =====

int SepSddlGetAclForString(wchar_t *param_1,longlong *param_2,undefined8 *param_3)

{
  wchar_t wVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  wchar_t *pwVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined2 *_Dst;
  undefined8 uVar9;
  wchar_t *pwVar10;
  uint uVar11;
  short *psVar12;
  short **ppsVar13;
  undefined8 uVar14;
  uint uVar15;
  short *local_res8;
  uint local_res10;
  uint local_res18 [2];
  uint local_res20 [2];
  wchar_t *local_58;
  longlong local_50 [2];
  
  *param_2 = 0;
  local_res18[0] = 0;
  iVar5 = 0;
  local_58 = (wchar_t *)0x0;
  local_50[0] = 0;
  uVar15 = 0;
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
  bVar3 = false;
  bVar2 = false;
  uVar14 = 1;
  for (pwVar10 = param_1; pwVar10 < pwVar6; pwVar10 = pwVar10 + 1) {
    if (*pwVar10 == L';') {
      uVar15 = uVar15 + 1;
    }
    else {
      bVar2 = bVar3;
      if (*pwVar10 != L' ') {
        bVar3 = true;
        bVar2 = true;
      }
    }
  }
  uVar11 = uVar15 / 5;
  local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar11);
  if ((uVar15 != uVar11 * 5) || ((uVar15 == 0 && (bVar2)))) {
    iVar5 = -0x3ffffff3;
  }
  else {
    if (uVar11 == 0) {
      puVar8 = (undefined8 *)ExAllocatePoolWithTag(1,8);
      *param_2 = (longlong)puVar8;
      if (puVar8 != (undefined8 *)0x0) {
        *puVar8 = 0x80002;
        return 0;
      }
    }
    else {
      uVar15 = uVar11 * 0x30 + 8;
      if (0xffff < uVar15) {
        uVar15 = 0xffff;
      }
      _Dst = (undefined2 *)ExAllocatePoolWithTag(1,uVar15,0x6c416553);
      *param_2 = (longlong)_Dst;
      if (_Dst != (undefined2 *)0x0) {
        local_res20[0] = 8;
        memset(_Dst,0,(ulonglong)uVar15);
        *_Dst = 2;
        _Dst[1] = (short)uVar15;
        *(undefined4 *)(_Dst + 2) = 0;
        uVar15 = (uint)local_res8;
        for (local_res10 = 0; uVar11 = 0, local_res10 < uVar15; local_res10 = local_res10 + 1) {
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
LAB_1c00200f4:
            iVar5 = -0x3ffffff3;
LAB_1c00200f6:
            lVar7 = *param_2;
            goto LAB_1c0020102;
          }
          for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
          }
          if (*pwVar6 != L';') goto LAB_1c00200f4;
          do {
            pwVar6 = pwVar6 + 1;
          } while (*pwVar6 == L' ');
          while (wVar1 = *pwVar6, wVar1 != L';') {
            while (wVar1 == L' ') {
              pwVar6 = pwVar6 + 1;
              wVar1 = *pwVar6;
            }
            uVar9 = SepSddlLookupAccessMaskInTable(pwVar6,local_res18,(longlong *)&local_58);
            if ((int)uVar9 == 0) {
              SepSddlParseWideStringUlong((ushort *)pwVar6,&local_58,(uint *)&local_res8);
              if (local_58 == pwVar6) goto LAB_1c00200f4;
              uVar11 = (uint)local_res8;
            }
            else {
              local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar11 | local_res18[0]);
              uVar11 = uVar11 | local_res18[0];
            }
            pwVar6 = local_58;
          }
          pwVar6 = pwVar6 + 1;
          if (iVar5 != 0) goto LAB_1c00200f6;
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
          if (iVar5 != 0) goto LAB_1c00200f6;
          for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
          }
          local_res8 = (short *)0x0;
          ppsVar13 = &local_res8;
          uVar9 = SepSddlGetSidForString(pwVar6,local_50,(longlong *)ppsVar13);
          iVar5 = (int)uVar9;
          if (iVar5 != 0) break;
          psVar12 = local_res8;
          if (local_res8 == (short *)0x0) {
LAB_1c002008e:
            iVar5 = -0x3fffff89;
            goto LAB_1c00200f6;
          }
          for (; *psVar12 == 0x20; psVar12 = psVar12 + 1) {
          }
          if (*psVar12 != 0x29) goto LAB_1c002008e;
          param_1 = psVar12 + 1;
          if (local_50[0] != 0) {
            uVar9 = SepSddlAddAceToAcl(param_2,local_res20,ppsVar13,uVar14,uVar11,
                                       uVar15 - local_res10,local_50[0]);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) goto LAB_1c00200f6;
          }
          if (*param_1 == L'(') {
            param_1 = psVar12 + 2;
          }
        }
        lVar7 = *param_2;
        if (iVar5 == 0) {
          *(undefined2 *)(lVar7 + 2) = (undefined2)local_res20[0];
          return 0;
        }
LAB_1c0020102:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 1c0020140 =====

undefined8 SepSddlGetSidForString(wchar_t *param_1,undefined8 *param_2,longlong *param_3)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  
  uVar5 = 0;
  uVar6 = 0;
  do {
    if (0xd < uVar6) {
      uVar4 = 0xc0000073;
LAB_1c00201e8:
      *param_2 = uVar5;
      return uVar4;
    }
    uVar3 = (ulonglong)uVar6;
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_1c001716c + uVar3 * 0x18),
                      (ulonglong)*(uint *)(&DAT_1c0017174 + uVar3 * 0x18));
    if (iVar2 == 0) {
      iVar2 = *(int *)(&DAT_1c0017168 + uVar3 * 0x18);
      uVar6 = *(uint *)(&DAT_1c0017174 + uVar3 * 0x18);
      *param_3 = (longlong)(param_1 + uVar6);
      if (iVar2 == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto code_r0x0001c00201cd;
      }
      else {
code_r0x0001c00201cd:
        uVar5 = *(undefined8 *)
                 (*(longlong *)(&DAT_1c0017160 + uVar3 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar4 = 0;
      goto LAB_1c00201e8;
    }
    uVar6 = uVar6 + 1;
  } while( true );
}



===== SepSddlLookupAccessMaskInTable @ 1c0020214 =====

undefined8 SepSddlLookupAccessMaskInTable(wchar_t *param_1,undefined4 *param_2,longlong *param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar2 = 0;
  while( true ) {
    if (7 < uVar2) {
      *param_2 = 0;
      *param_3 = (longlong)param_1;
      return 0;
    }
    uVar3 = (ulonglong)uVar2;
    iVar1 = _wcsnicmp(param_1,(wchar_t *)(&PTR_u_RC_1c0017090)[uVar3 * 2],
                      (ulonglong)(uint)(&DAT_1c0017098)[uVar3 * 4]);
    if (iVar1 == 0) break;
    uVar2 = uVar2 + 1;
  }
  *param_2 = (&DAT_1c001709c)[uVar3 * 4];
  *param_3 = (longlong)(param_1 + (uint)(&DAT_1c0017098)[uVar3 * 4]);
  return 1;
}



===== SepSddlParseWideStringUlong @ 1c00202ac =====

undefined8 SepSddlParseWideStringUlong(ushort *param_1,undefined8 *param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar1 = *param_1;
  *param_3 = 0;
  *param_2 = param_1;
  if (uVar1 == 0x30) {
    if ((param_1[1] - 0x58 & 0xffdf) != 0) {
LAB_1c0020319:
      iVar6 = 10;
      goto LAB_1c00202f0;
    }
    param_1 = param_1 + 2;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_1c0020319;
  iVar6 = 0x10;
LAB_1c00202f0:
  uVar7 = 0;
  for (puVar4 = param_1; uVar1 = *puVar4, uVar1 != 0; puVar4 = puVar4 + 1) {
    if ((ushort)(uVar1 - 0x30) < 10) {
      iVar2 = uVar1 - 0x30;
    }
    else {
      if (iVar6 != 0x10) break;
      if ((ushort)(uVar1 - 0x41) < 6) {
        iVar2 = uVar1 - 0x37;
      }
      else {
        if (5 < (ushort)(uVar1 - 0x61)) break;
        iVar2 = uVar1 - 0x57;
      }
    }
    uVar5 = iVar6 * uVar7 + iVar2;
    if (uVar5 < uVar7) goto LAB_1c002035d;
    uVar7 = uVar5;
  }
  if (puVar4 == param_1) {
LAB_1c002035d:
    uVar3 = 0;
  }
  else {
    *param_2 = puVar4;
    uVar3 = 1;
    *param_3 = uVar7;
  }
  return uVar3;
}



===== SepSddlSecurityDescriptorFromSDDLString @ 1c0020384 =====

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
        goto LAB_1c00204c9;
      }
    }
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_1c00204c9:
  return (ulonglong)uVar2;
}



===== PiRegStateOpenClassKey @ 1c0020528 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong PiRegStateOpenClassKey
                    (uint *param_1,undefined8 param_2,int param_3,undefined4 *param_4,
                    undefined8 *param_5)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  wchar_t *pwVar5;
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
  uVar3 = CmRegUtilOpenExistingWstrKey(0,0x1c0014d30,0x20019,&local_b0);
  if (-1 < (int)uVar3) {
    uVar3 = (ulonglong)*param_1;
    pwVar5 = L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}";
    _snwprintf(local_98,0x27,L"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}");
    uVar1 = local_b0;
    local_4c = 0;
    if (local_b4 == 0) {
      uVar2 = CmRegUtilOpenExistingWstrKey(local_b0,(longlong)local_98,0xf003f,local_a8);
      uVar4 = 2;
    }
    else {
      uVar2 = CmRegUtilCreateWstrKey(local_b0,(longlong)local_98,pwVar5,uVar3,0,&local_b8,local_a8);
      uVar4 = local_b8;
    }
    uVar3 = (ulonglong)uVar2;
    ZwClose(uVar1);
    if ((-1 < (int)uVar2) && (*param_5 = local_a8[0], param_4 != (undefined4 *)0x0)) {
      *param_4 = uVar4;
    }
  }
  return uVar3;
}



===== PiRegStateReadStackCreationSettingsFromKey @ 1c00206c4 =====

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
  uVar2 = WdmlibRtlInitUnicodeStringEx((short *)local_50,0x1c0014cb0);
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
      if ((int)uVar3 < 0) goto LAB_1c0020843;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c0014cc8,param_3,param_2 + 1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1c0020843;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c0014ce0,param_3,param_2 + 4);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_1c0020843;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1c0014d10,param_3,param_2 + 5);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_2 = *param_2 | 8;
      return uVar5;
    }
    if ((int)uVar3 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_1c0020843:
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



===== PpRegStateReadCreateClassCreationSettings @ 1c0020888 =====

ulonglong PpRegStateReadCreateClassCreationSettings(uint *param_1,longlong param_2,uint *param_3)

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
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x1c0014c50,0x20019,puVar6);
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
      uVar3 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,0x1c0014c68);
      uVar2 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = CmRegUtilUcValueSetUcString(uVar4,&local_18,puVar7);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_res18[0] = 0x31;
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1c0014c78,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x1c0014c98,(longlong)local_res18);
            uVar2 = (ulonglong)uVar1;
          }
        }
      }
    }
  }
  ZwClose(uVar4);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 1c00209ec =====

ulonglong PpRegStateUpdateStackCreationSettings(uint *param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
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
  if (-1 < (int)uVar4) {
    puVar6 = &PiRegStateSysAllInherittedSecurityDescriptor;
    if (PiRegStateDiscriptor == 0) {
      uVar8 = CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
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
    uVar2 = CmRegUtilCreateWstrKey
                      (local_res20,0x1c0014c50,uVar7,uVar8,puVar6,(undefined4 *)0x0,&local_38);
    uVar4 = (ulonglong)uVar2;
    ZwClose(local_res20);
    if (-1 < (int)uVar2) {
      uVar3 = RtlLengthSecurityDescriptor(*(undefined8 *)(param_2 + 8));
      uVar7 = *(undefined8 *)(param_2 + 8);
      local_30[0] = 0;
      local_30[1] = 0;
      local_30[2] = 0;
      local_30[3] = 0;
      local_30[4] = 0;
      local_30[5] = 0;
      local_30[6] = 0;
      local_30[7] = 0;
      uVar5 = WdmlibRtlInitUnicodeStringEx(local_30,0x1c0014cb0);
      uVar4 = uVar5 & 0xffffffff;
      if (-1 < (int)uVar5) {
        uVar2 = ZwSetValueKey(local_38,local_30,0,3,uVar7,uVar3);
        uVar4 = (ulonglong)uVar2;
      }
      ZwClose(local_38);
    }
  }
  return uVar4;
}



===== SeUtilSecurityInfoFromSecurityDescriptor @ 1c0020b54 =====

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



===== CmRegUtilCreateUcKey @ 1c0020c50 =====

int CmRegUtilCreateUcKey
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  int iVar1;
  undefined8 local_res8 [3];
  undefined4 local_res20 [2];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 local_10;
  
  local_1c = 0;
  local_res20[0] = 0;
  local_res8[0] = 0;
  local_10 = 0;
  local_18 = param_5;
  local_38 = 0x30;
  local_20 = 0x240;
  local_30 = param_1;
  local_28 = param_2;
  iVar1 = ZwCreateKey(local_res8,0xf003f,&local_38,0,0,0,local_res20);
  if (iVar1 < 0) {
    local_res8[0] = 0;
    local_res20[0] = 0;
  }
  *param_7 = local_res8[0];
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = local_res20[0];
  }
  return iVar1;
}



===== CmRegUtilCreateWstrKey @ 1c0020cf8 =====

void CmRegUtilCreateWstrKey
               (undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 *param_6,undefined8 *param_7)

{
  undefined8 uVar1;
  short local_18 [12];
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  uVar1 = WdmlibRtlInitUnicodeStringEx(local_18,param_2);
  if (-1 < (int)uVar1) {
    CmRegUtilCreateUcKey(param_1,local_18,param_3,param_1,param_5,param_6,param_7);
  }
  return;
}



===== CmRegUtilOpenExistingWstrKey @ 1c0020d58 =====

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



===== CmRegUtilUcValueGetFullBuffer @ 1c0020dec =====

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
    if (iVar1 < 0) goto LAB_1c0020f24;
  }
  if (*(int *)((longlong)_Dst + 4) == 3) {
    *param_5 = _Dst;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_1c0020f24:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 1c0020f68 =====

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



===== CmRegUtilWstrValueGetDword @ 1c00210b4 =====

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



===== CmRegUtilWstrValueSetWstrString @ 1c0021158 =====

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



===== DriverEntry @ 1c00211b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(longlong param_1)

{
  undefined8 uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined1 auStack_158 [32];
  undefined8 local_108;
  wchar_t *local_100;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 *local_e0;
  undefined8 local_d8;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  code *local_a8;
  code *local_a0;
  code *local_98;
  code *local_90;
  undefined8 local_88;
  undefined8 local_78;
  undefined4 local_70;
  undefined2 local_6c;
  wchar_t local_68 [24];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_158;
  local_70 = 0x6c0065;
  uVar4 = 8;
  local_6c = 0;
  builtin_wcsncpy(local_68,L"\\Device\\TunnelControl",0x16);
  local_100 = local_68;
  local_e0 = &local_78;
  local_d0 = TunnelMiniportPause;
  local_c8 = TunnelMiniportRestart;
  local_c0 = TunnelMiniportOidRequest;
  local_b8 = TunnelMiniportSendNetBufferLists;
  local_b0 = TunnelMiniportReturnNetBufferLists;
  local_a8 = TunnelMiniportCancelSend;
  local_78 = 0x6e006e00750074;
  local_a0 = TunnelMiniportCancelOidRequest;
  local_98 = TunnelMiniportDirectOidRequest;
  local_90 = TunnelMiniportCancelDirectOidRequest;
  local_108 = 0x2c002a;
  local_f8 = 0x7801c7;
  local_f4 = 0x15106;
  local_f0 = 0;
  local_e8 = 0xe000c;
  local_d8 = 0;
  local_88 = 0;
  DAT_1c001aa19 = TunnelRunningOnXboxOne();
  DAT_1c001aa1a = DAT_1c001aa19;
  KeInitializeMutex(&DAT_1c001aa20,0);
  KeInitializeMutex(&DAT_1c001aa70,0);
  _WPP_MAIN_CB = 0;
  DAT_1c001a688 = &WPP_ThisDir_CTLGUID_NETIO;
  DAT_1c001a690 = 0;
  _DAT_1c001a6a0 = 0;
  _DAT_1c001a6a8 = 1;
  WppLoadTracingSupport();
  _DAT_1c001a6a0 = 0;
  WppInitKm();
  TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
  TunnelStartEtwTrace();
  TunnelInitializeDriver(param_1);
  if (WdmlibInitialized == '\0') {
    WdmlibInit();
  }
  puVar6 = &local_108;
  uVar7 = 0x12;
  uVar2 = (*PfnIoCreateDeviceSecure)(param_1,0);
  uVar5 = (ulonglong)uVar2;
  if ((int)uVar2 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
      uVar7 = (ulonglong)uVar2;
      puVar6 = (undefined8 *)&WPP_28e2058d176430dca178da03616b2fa6_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_28e2058d176430dca178da03616b2fa6_Traceguids,uVar2);
    }
    uVar4 = 9;
  }
  else {
    uVar2 = IoCreateSymbolicLink(&TunnelControlDeviceUserPath,&local_108);
    uVar5 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
        uVar7 = (ulonglong)uVar2;
        puVar6 = (undefined8 *)&WPP_28e2058d176430dca178da03616b2fa6_Traceguids;
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_28e2058d176430dca178da03616b2fa6_Traceguids,uVar2);
      }
      uVar4 = 10;
    }
    else {
      uVar2 = NetioInitializeNetBufferListLibrary();
      uVar5 = (ulonglong)uVar2;
      if ((int)uVar2 < 0) {
        uVar4 = 0;
      }
      else {
        puVar6 = &DAT_1c001a6e8;
        _DAT_1c001a6d0 = param_1;
        uVar2 = NdisLWMRegisterMiniportDriver(0,&local_f8);
        uVar5 = (ulonglong)uVar2;
        if (uVar2 == 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
            puVar6 = (undefined8 *)&WPP_28e2058d176430dca178da03616b2fa6_Traceguids;
            uVar7 = 0;
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                     &WPP_28e2058d176430dca178da03616b2fa6_Traceguids,0);
          }
          TunnelSetInitialize();
          uVar3 = TunnelInitializeWorkQueue();
          uVar5 = uVar3 & 0xffffffff;
          if ((int)uVar3 < 0) {
            uVar4 = 2;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
              uVar7 = uVar3 & 0xffffffff;
              puVar6 = (undefined8 *)&WPP_28e2058d176430dca178da03616b2fa6_Traceguids;
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                       &WPP_28e2058d176430dca178da03616b2fa6_Traceguids,(int)uVar3);
            }
          }
          else {
            uVar3 = TunnelNlRegisterNlClient();
            uVar5 = uVar3 & 0xffffffff;
            if ((int)uVar3 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
                uVar7 = uVar3 & 0xffffffff;
                puVar6 = (undefined8 *)&WPP_28e2058d176430dca178da03616b2fa6_Traceguids;
                WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                         &WPP_28e2058d176430dca178da03616b2fa6_Traceguids,(int)uVar3);
              }
              uVar4 = 4;
            }
            else {
              uVar7 = 0;
              KeWaitForSingleObject(&DAT_1c001aa20,0);
              puVar6 = (undefined8 *)0x0;
              uVar2 = NetioRegisterProcessorAddCallback(&DAT_1c001aa58,TunnelProcessorAddCallback);
              uVar5 = (ulonglong)uVar2;
              if ((int)uVar2 < 0) {
                uVar4 = 5;
              }
              else {
                DAT_1c001a6c8 = NetioAllocateAndInitializeStackBlock(0,0x42537554);
                if (DAT_1c001a6c8 != 0) {
                  KeReleaseMutex(&DAT_1c001aa20,0);
                  TunnelInitializeTimer();
                  TunnelReferenceDriver();
                  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                      (3 < (byte)WPP_GLOBAL_Control[0x29])) &&
                     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
                    puVar6 = (undefined8 *)&WPP_28e2058d176430dca178da03616b2fa6_Traceguids;
                    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                            &WPP_28e2058d176430dca178da03616b2fa6_Traceguids);
                  }
                  *(uint *)(DAT_1c001a6d8 + 0x30) = *(uint *)(DAT_1c001a6d8 + 0x30) & 0xffffff7f;
                  goto LAB_1c002173c;
                }
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
                   ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
                  puVar6 = (undefined8 *)&WPP_28e2058d176430dca178da03616b2fa6_Traceguids;
                  WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                          &WPP_28e2058d176430dca178da03616b2fa6_Traceguids);
                }
                uVar4 = 6;
                uVar5 = 0xc0000017;
                NetioUnRegisterProcessorAddCallback(&DAT_1c001aa58);
              }
              KeReleaseMutex(&DAT_1c001aa20,0);
              TunnelNlDeregisterNlClient();
            }
            TunnelUninitializeWorkQueue();
          }
          NdisLWMDeregisterMiniportDriver(DAT_1c001a6e8);
        }
        else {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x100) != 0)) {
            uVar7 = (ulonglong)uVar2;
            puVar6 = (undefined8 *)&WPP_28e2058d176430dca178da03616b2fa6_Traceguids;
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                     &WPP_28e2058d176430dca178da03616b2fa6_Traceguids,uVar2);
          }
          uVar4 = 1;
        }
        NetioUnInitializeNetBufferListLibrary();
      }
      IoDeleteSymbolicLink(&TunnelControlDeviceUserPath);
    }
    IoDeleteDevice(DAT_1c001a6d8);
  }
LAB_1c002173c:
  if ((DAT_1c0017024 != 0) && ((Microsoft_Windows_TunnelDriverEnableBits & 1) != 0)) {
    uVar7 = (ulonglong)uVar4;
    McTemplateK0qq_EtwWriteTransfer
              (&MS_TUNNEL_DRIVER_PROVIDER_ID_Context,&EVENT_TUNNEL_DRIVER_ENTRY,puVar6,uVar4,
               (char)uVar5);
  }
  TunnelTelemetryDriverInitialization(uVar4,(uint)uVar5,puVar6,uVar7);
  if ((int)(uint)uVar5 < 0) {
    TunnelStopEtwTrace();
    WppCleanupKm();
    uVar1 = DAT_1c0017070;
    DAT_1c0017070 = 0;
    DAT_1c0017050 = 0;
    EtwUnregister(uVar1);
  }
  return uVar5;
}



===== WdmlibIoCreateDeviceSecure @ 1c00217d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdmlibIoCreateDeviceSecure(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 in_stack_00000038;
  undefined8 in_stack_00000048;
  
  if (WdmlibInitialized == '\0') {
    WdmlibInit();
  }
  (*PfnIoCreateDeviceSecure)
            (param_1,0,param_3,0x12,0x100,0,in_stack_00000038,&TUNNEL_DEVICE_CLASS_GUID,
             in_stack_00000048);
  return;
}



===== entry @ 1c0022010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 1c0022044 =====

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0001c002307b) overlaps instruction at (ram,0x0001c002307a)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl __security_init_cookie(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 uVar3;
  code *pcVar4;
  byte bVar5;
  char cVar6;
  byte *pbVar7;
  undefined7 uVar10;
  undefined4 *puVar8;
  char *pcVar9;
  ulonglong uVar11;
  char *in_RDX;
  byte unaff_BL;
  undefined7 unaff_00000019;
  byte *unaff_RBP;
  ulonglong unaff_RSI;
  char *in_R8;
  
  if ((__security_cookie != 0) && (__security_cookie != 0x2b992ddfa232)) {
    ___security_cookie_complement = ~__security_cookie;
    return;
  }
  uVar11 = 6;
  pcVar4 = (code *)swi(0x29);
  pbVar7 = (byte *)(*pcVar4)();
  bVar5 = (byte)pbVar7;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 + bVar5;
  *in_RDX = *in_RDX + (char)in_RDX;
  bVar2 = *pbVar7;
  *pbVar7 = *pbVar7 + bVar5;
  *pbVar7 = *pbVar7 - CARRY1(bVar2,bVar5);
  *pbVar7 = *pbVar7 + (char)in_RDX;
  uVar10 = (undefined7)((ulonglong)pbVar7 >> 8);
  *pbVar7 = *pbVar7 + (char)((ulonglong)pbVar7 >> 8);
  *pbVar7 = *pbVar7 + (char)((ulonglong)in_RDX >> 8);
  cVar6 = *in_R8;
  *in_R8 = *in_R8 + bVar5;
  if (SCARRY1(cVar6,bVar5)) {
    puVar8 = (undefined4 *)CONCAT71(uVar10,bVar5 * '\x02');
    LOCK();
    uVar3 = *puVar8;
    *puVar8 = (int)puVar8;
    pcVar9 = (char *)CONCAT44((int)((ulonglong)pbVar7 >> 0x20),uVar3);
    UNLOCK();
    pcVar9[-0x77] = pcVar9[-0x77] + (char)((uint)uVar3 >> 8);
    *pcVar9 = *pcVar9 + (char)uVar3;
    uVar10 = (undefined7)((ulonglong)pcVar9 >> 8);
    pcVar9 = (char *)CONCAT71(uVar10,0x89);
    *pcVar9 = *pcVar9 + -0x77;
    pbVar7 = (byte *)(uVar11 - 0x73f00000);
    *pbVar7 = *pbVar7 >> 1 | *pbVar7 << 7;
    *pcVar9 = *pcVar9 + -0x77;
    pbVar7 = (byte *)((longlong)pcVar9 * 2 + 0x91b000);
    *pbVar7 = *pbVar7 ^ (byte)uVar11;
    pbVar7 = (byte *)((ulonglong)in_RDX & 0xffffffff);
    in_RDX = (char *)(CONCAT71(uVar10,0x12) & 0xffffffff);
    bVar2 = *pbVar7;
    *pbVar7 = *pbVar7 + (byte)pbVar7;
    unaff_RBP[-0x6a000000] = unaff_RBP[-0x6a000000] + (char)in_RDX + CARRY1(bVar2,(byte)pbVar7);
  }
  else {
    *pbVar7 = *pbVar7 + bVar5;
    pbVar7 = (byte *)CONCAT71(uVar10,0x57);
    *pbVar7 = *pbVar7 + 0x57;
    uVar11 = uVar11 - 1;
    if (uVar11 == 0 || *pbVar7 == 0) {
      *pbVar7 = *pbVar7 + 0x57;
      *unaff_RBP = *unaff_RBP ^ unaff_BL;
      pbVar7[0x5e] = pbVar7[0x5e] + 0x57;
      bVar2 = *pbVar7;
      *pbVar7 = *pbVar7 + 0x57;
      if (!SCARRY1(bVar2,'W')) {
        *pbVar7 = *pbVar7 + 0x57;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      goto code_r0x0001c0023088;
    }
    pcVar9 = (char *)(uVar11 & 0xffffffff);
    uVar11 = (ulonglong)pbVar7 & 0xffffffff;
    *pcVar9 = *pcVar9 + (char)pcVar9;
    in_RDX[-0x6af00000] = in_RDX[-0x6af00000];
    *pcVar9 = *pcVar9 + (char)pcVar9;
    pbVar7 = (byte *)(unaff_RSI & 0xffffffff);
  }
  *pbVar7 = *pbVar7 + (char)pbVar7;
code_r0x0001c0023088:
  in_RDX[-0x56e00000] = in_RDX[-0x56e00000] ^ unaff_BL;
  cVar6 = (char)pbVar7;
  *pbVar7 = *pbVar7 + cVar6;
  *(byte *)(uVar11 - 0x54a00000) = *(byte *)(uVar11 - 0x54a00000) >> 1;
  *pbVar7 = *pbVar7 + cVar6;
  pbVar1 = (byte *)(CONCAT71(unaff_00000019,unaff_BL) + -0x4ce00000);
  *pbVar1 = *pbVar1 >> 1;
  *pbVar7 = *pbVar7 + cVar6;
  *pbVar7 = *pbVar7 + cVar6;
  pbRam00000000c11ffff8 = pbVar7;
  return;
}


