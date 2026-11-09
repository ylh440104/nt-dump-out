
===== _tlgCreate1Sz_char @ 140001008 =====

void _tlgCreate1Sz_char(longlong *param_1,char *param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 == (char *)0x0) {
    param_2 = "";
    iVar1 = 1;
  }
  else {
    lVar2 = -1;
    do {
      lVar2 = lVar2 + 1;
    } while (param_2[lVar2] != '\0');
    iVar1 = (int)lVar2 + 1;
  }
  *(undefined4 *)((longlong)param_1 + 0xc) = 0;
  *param_1 = (longlong)param_2;
  *(int *)(param_1 + 1) = iVar1;
  return;
}



===== _tlgKeywordOn @ 14000103c =====

undefined1 _tlgKeywordOn(longlong param_1,ulonglong param_2)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if ((param_2 == 0) ||
     (((*(ulonglong *)(param_1 + 0x10) & param_2) != 0 &&
      ((*(ulonglong *)(param_1 + 0x18) & param_2) == *(ulonglong *)(param_1 + 0x18))))) {
    uVar1 = 1;
  }
  return uVar1;
}



===== _tlgWriteTransfer_EtwWriteTransfer @ 140001068 =====

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
  *param_6 = PTR_DAT_14001b048;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_14001b048;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_14001b060,&local_18,0,0,param_5,param_6);
  return;
}



===== VmbPacketSendWithExternalMdl @ 140001120 =====

void VmbPacketSendWithExternalMdl
               (ulonglong param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  code *pcVar3;
  byte bVar4;
  undefined1 *puVar5;
  uint uVar6;
  byte bVar7;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [48];
  
                    /* 0x1120  81  VmbPacketSendWithExternalMdl */
  puVar5 = auStack_38;
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)();
    puVar5 = auStack_30;
  }
  uVar1 = *(uint *)(puVar5 + 0x70);
  bVar7 = *(byte *)(param_1 + 0x3e) & 0xfe;
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(puVar5 + 0x60);
  uVar2 = *(undefined4 *)(puVar5 + 0x68);
  *(undefined8 *)(param_1 + 0x40) = param_4;
  uVar6 = uVar1 & 2;
  *(undefined4 *)(param_1 + 0x4c) = uVar2;
  *(undefined1 *)(param_1 + 0x3d) = 1;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(byte *)(param_1 + 0x3e) = uVar6 != 0 | bVar7;
  if ((uVar1 & 8) == 0) {
    if ((uVar1 & 0x10) == 0) goto LAB_14000119f;
    bVar4 = (uVar6 != 0) + 0x20;
  }
  else {
    bVar4 = (uVar6 != 0) + 0x10;
  }
  *(byte *)(param_1 + 0x3e) = bVar4 | bVar7;
LAB_14000119f:
  if ((uVar1 & 4) == 0) {
    *(undefined4 *)(puVar5 + 0x20) = 1;
    *(undefined8 *)(puVar5 + -8) = 0x1400011e2;
    OutSendPacket(param_1,param_2,param_3,(uVar1 & 1) != 0,*(uint *)(puVar5 + 0x20));
  }
  else {
    *(undefined4 *)(puVar5 + 0x28) = 0;
    puVar5[0x20] = (char)(uVar1 & 1);
    *(undefined8 *)(puVar5 + -8) = 0x1400011c4;
    OutCopyAndSendPacket
              (param_1,(undefined8 *)(puVar5 + 0x48),(uint *)(puVar5 + 0x50),(ulonglong)uVar6,
               puVar5[0x20],*(uint *)(puVar5 + 0x28));
  }
  return;
}



===== OutSendPacket @ 140001200 =====

int OutSendPacket(ulonglong param_1,undefined8 param_2,undefined4 param_3,char param_4,uint param_5)

{
  longlong *plVar1;
  uint uVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined1 uVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  int unaff_EDI;
  bool bVar10;
  undefined1 local_res8 [8];
  int in_stack_ffffffffffffffc8;
  byte bVar11;
  uint local_28 [4];
  
  if (*(int *)(param_1 + 0x18) != 1) {
    return unaff_EDI;
  }
  plVar3 = *(longlong **)(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x30) = param_2;
  *(undefined4 *)(param_1 + 0x38) = param_3;
  *(char *)(param_1 + 0x3c) = param_4;
  uVar5 = KeAcquireSpinLockRaiseToDpc(plVar3 + 0x20);
  local_res8[0] = uVar5;
  if ((int)plVar3[0x21] == 1) {
    uVar9 = 0;
    if (param_4 != '\0') {
      uVar7 = OutpAllocateHandle((longlong)plVar3,param_1);
      uVar9 = uVar7 & 0xffffffff;
      if ((int)uVar7 == 0) goto LAB_1400012fa;
    }
    if (((*(char *)(param_1 + 0x3d) != '\x01') || (*(char *)(*plVar3 + 0xb51) == '\0')) ||
       ((*(int *)(param_1 + 0x18) == 2 && (*(longlong *)(param_1 + 0x50) != 0)))) {
LAB_140001391:
      uVar2 = *(uint *)(param_1 + 0x38);
      uVar7 = (ulonglong)uVar2;
      if (*(char *)(param_1 + 0x3d) == '\0') {
        uVar8 = PkSendPacketSimple(plVar3 + 8,*(void **)(param_1 + 0x30),uVar2,uVar9,param_4);
        iVar6 = (int)uVar8;
      }
      else {
        plVar1 = plVar3 + 8;
        if (*(char *)(param_1 + 0x3d) == '\x01') {
          bVar11 = *(byte *)(param_1 + 0x3e) & 1;
          if (*(longlong **)(param_1 + 0x50) == (longlong *)0x0) {
            uVar8 = PkSendPacketGpaDirect
                              (plVar1,*(void **)(param_1 + 0x30),uVar2,uVar9,
                               *(longlong **)(param_1 + 0x40),*(uint *)(param_1 + 0x48),
                               *(uint *)(param_1 + 0x4c),bVar11);
            iVar6 = (int)uVar8;
          }
          else {
            uVar8 = PkSendPacketGpaDirectList
                              (plVar1,*(void **)(param_1 + 0x30),uVar2,uVar9,
                               *(longlong **)(param_1 + 0x50),*(uint *)(param_1 + 0x48),
                               *(uint *)(param_1 + 0x4c),bVar11);
            iVar6 = (int)uVar8;
          }
        }
        else {
          uVar8 = PkSendPacketTransferPage
                            (plVar1,*(void **)(param_1 + 0x30),uVar2,uVar9,
                             *(ushort *)(param_1 + 0x48),*(undefined8 **)(param_1 + 0x40),
                             in_stack_ffffffffffffffc8);
          iVar6 = (int)uVar8;
        }
      }
      if ((Microsoft_Windows_Hyper_V_KMCL_ChildEnableBits & 2) != 0) {
        lVar4 = *plVar3;
        McTemplateK0jjxth_EtwWriteTransfer
                  (lVar4 + 0xac0,&VMBUS_SEND_PACKET,uVar7,lVar4 + 0xad0,lVar4 + 0xac0,(char)uVar9,0,
                   (char)*(undefined2 *)(lVar4 + 0xcd0));
      }
      if (-1 < iVar6) {
        if ((param_4 != '\0') && (KmclPerformanceCounterTimingCounters != 0)) {
          uVar8 = KeQueryPerformanceCounter(0);
          bVar10 = KmclPerformanceCounterTimingCounters != 0;
          *(undefined8 *)(param_1 + 0x80) = uVar8;
          if (bVar10) {
            *(int *)(plVar3 + 0x40) = (int)plVar3[0x40] + 1;
          }
        }
        *(int *)(plVar3 + 0x39) = (int)plVar3[0x39] + 1;
        if (iVar6 == 0x214) {
          bVar10 = KmclSendSignal(*plVar3);
          if (bVar10) {
            plVar3[0x3b] = plVar3[0x3b] + 1;
          }
          else {
            plVar3[0x3c] = plVar3[0x3c] + 1;
          }
        }
        if (param_4 == '\0') {
          if ((param_5 & 2) == 0) {
            OutpTransitionPacketToReadyToComplete(plVar3,param_1);
            KeReleaseSpinLock(plVar3 + 0x20);
            OutCompletePacketToClient(param_1,0,0);
            return unaff_EDI;
          }
        }
        else {
          *(undefined4 *)(param_1 + 0x18) = 3;
        }
        goto LAB_140001678;
      }
      if (iVar6 != -0x7ffffffb) {
        if (iVar6 != -0x3ffffff3) {
          *(undefined4 *)(plVar3 + 0x21) = 6;
          *(int *)((longlong)plVar3 + 0x42c) = iVar6;
        }
        uVar2 = *(uint *)(param_1 + 0x1c);
        if (uVar2 != 0) {
          local_28[1] = 0;
          local_28[2] = 0;
          if (uVar2 < *(uint *)(plVar3 + 0x5a)) {
            DvpPushFreeEntries((ulonglong *)plVar3[0x59],uVar2,(ulonglong *)plVar3[0x59] + uVar2);
          }
          else {
            local_28[0] = uVar2;
            RtlDeleteElementGenericTableAvl(plVar3[0x5e],local_28);
          }
          *(undefined4 *)(param_1 + 0x1c) = 0;
        }
        if ((*(char *)(param_1 + 0x3d) == '\x01') &&
           (*(undefined8 **)(param_1 + 0x50) != (undefined8 *)0x0)) {
          KmclpFreeBounceList(*plVar3,*(undefined8 **)(param_1 + 0x50));
          *(undefined8 *)(param_1 + 0x50) = 0;
        }
        *(undefined4 *)(param_1 + 0x18) = 1;
        *(undefined1 *)(param_1 + 0x3d) = 0;
        goto LAB_140001678;
      }
      if ((int)plVar3[0x21] != 5) {
        *(undefined4 *)(plVar3 + 0x21) = 2;
        if ((*(byte *)(plVar3[0xb] + 0x40) & 1) == 0) {
          OutpEnqueuePollingTimer((longlong)plVar3);
        }
      }
      goto LAB_1400012fa;
    }
    iVar6 = OutpPreparePacketForIsolation(plVar3,param_1);
    if (iVar6 == -0x3fffffe9) {
      *(undefined4 *)(plVar3 + 0x21) = 5;
      IoQueueWorkItem(*(undefined8 *)(*plVar3 + 0xb78),OutPacketAddMoreBounceWorkerRoutine,1,plVar3)
      ;
      goto LAB_1400012fa;
    }
    if (-1 < iVar6) {
      OutpPacketCopyToBouncePagesCycleLock((longlong)plVar3,param_1,local_res8);
      uVar5 = local_res8[0];
      if (((int)plVar3[0x21] == 1) || ((int)plVar3[0x21] == 5)) goto LAB_140001391;
      goto LAB_1400012fa;
    }
  }
  else {
    if ((int)plVar3[0x21] == 0) {
      *(int *)(plVar3 + 0x41) = (int)plVar3[0x41] + 1;
      *(undefined4 *)(param_1 + 0x18) = 1;
      *(undefined1 *)(param_1 + 0x3d) = 0;
      goto LAB_140001678;
    }
LAB_1400012fa:
    if (((*(char *)(param_1 + 0x3d) == '\x01') &&
        (*(undefined8 **)(param_1 + 0x50) != (undefined8 *)0x0)) &&
       ((longlong *)plVar3[0x22] != plVar3 + 0x22)) {
      KmclpFreeBounceList(*plVar3,*(undefined8 **)(param_1 + 0x50));
      *(undefined8 *)(param_1 + 0x50) = 0;
    }
    if ((param_5 & 4) == 0) {
      if ((param_5 & 1) != 0) {
        if (*(uint *)(param_1 + 0xac) < *(uint *)(param_1 + 0x38)) {
          *(int *)((longlong)plVar3 + 0x20c) = *(int *)((longlong)plVar3 + 0x20c) + 1;
          goto LAB_140001351;
        }
        memmove((void *)(param_1 + 0xf0),*(void **)(param_1 + 0x30),
                (ulonglong)*(uint *)(param_1 + 0x38));
        *(void **)(param_1 + 0x30) = (void *)(param_1 + 0xf0);
      }
      OutpEnqueuePacket((longlong)plVar3,(longlong *)(param_1 + 0x90));
      *(undefined4 *)(param_1 + 0x18) = 2;
      if ((int)plVar3[0x21] == 2) {
        *(int *)((longlong)plVar3 + 0x1cc) = *(int *)((longlong)plVar3 + 0x1cc) + 1;
      }
      goto LAB_140001678;
    }
    *(int *)((longlong)plVar3 + 0x204) = *(int *)((longlong)plVar3 + 0x204) + 1;
  }
LAB_140001351:
  OutpTransitionPacketToReadyToComplete(plVar3,param_1);
  *(undefined4 *)(param_1 + 0x18) = 1;
  *(undefined1 *)(param_1 + 0x3d) = 0;
LAB_140001678:
  KeReleaseSpinLock(plVar3 + 0x20,uVar5);
  if ((*(char *)(*plVar3 + 0xb51) != '\0') &&
     (*(uint *)(plVar3 + 0x39) == (*(uint *)(plVar3 + 0x39) / 10000) * 10000)) {
    KmclpFreeOldBounceBlocks(*plVar3);
  }
  return unaff_EDI;
}



===== InpBatchProcessAndEnqueue @ 1400016f0 =====

undefined8 InpBatchProcessAndEnqueue(longlong *param_1,undefined8 param_2,ulonglong param_3)

{
  undefined8 *puVar1;
  short sVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  code *pcVar6;
  bool bVar7;
  undefined8 uVar8;
  longlong *plVar9;
  
  do {
    plVar9 = param_1 + 0xa0;
    while( true ) {
      plVar3 = (longlong *)param_1[0xa2];
      if (plVar3 == param_1 + 0xa2) {
        return 1;
      }
      sVar2 = *(short *)(plVar3 + 2);
      if (((sVar2 != 9) && (sVar2 != 6)) && (sVar2 != 7)) break;
      param_3 = (ulonglong)((*(int *)(plVar3 + -0xc) - *(uint *)(plVar3 + 5)) - 0xa0);
      memset((void *)((ulonglong)*(uint *)(plVar3 + 5) + 0xa0 + (longlong)(plVar3 + -0xd)),0,param_3
            );
      if (*(short *)(plVar3 + 2) == 9) {
        param_3 = (ulonglong)*(uint *)((longlong)plVar3 + 0x34);
        bVar7 = InpParseGpaDirectPacket
                          ((longlong)(plVar3 + -0xd),*(int *)((longlong)plVar3 + 0x2c),
                           *(uint *)((longlong)plVar3 + 0x34));
        if (!bVar7) {
          if ((int)param_1[0x89] == 0) {
            return 0xb;
          }
          *(undefined4 *)(param_1 + 0xaf) = 1;
          goto LAB_14000191e;
        }
      }
      puVar1 = plVar3 + -10;
      *(byte *)(plVar3 + -0xb) =
           (*(byte *)((longlong)plVar3 + 0x16) & 1) << 2 | *(byte *)(plVar3 + -0xb) & 0xfb;
      plVar4 = (longlong *)param_1[0xa1];
      if ((longlong *)*plVar4 != plVar9) goto LAB_14000194c;
      *puVar1 = plVar9;
      plVar3[-9] = (longlong)plVar4;
      *plVar4 = (longlong)puVar1;
      param_1[0xa1] = (longlong)puVar1;
      lVar5 = *plVar3;
      if (((longlong *)*(longlong *)(lVar5 + 8) != plVar3) ||
         (plVar4 = (longlong *)plVar3[1], (longlong *)*plVar4 != plVar3)) goto LAB_14000194c;
      bVar7 = KmclPerformanceCounterTimingCounters != 0;
      *plVar4 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar4;
      if (bVar7) {
        uVar8 = KeQueryPerformanceCounter(0);
        plVar3[-2] = uVar8;
      }
      if ((Microsoft_Windows_Hyper_V_KMCL_ChildEnableBits & 1) != 0) {
        lVar5 = *param_1;
        McTemplateK0jjxth_EtwWriteTransfer
                  (lVar5 + 0xac0,&VMBUS_FETCH_PACKET,param_3,lVar5 + 0xad0,lVar5 + 0xac0,
                   (char)plVar3[3],0,(char)*(undefined2 *)(lVar5 + 0xcd0));
      }
    }
    if ((sVar2 == 10) || (sVar2 != 0xb)) {
      *(undefined4 *)(param_1 + 0xaf) = 3;
LAB_14000191e:
      *(undefined4 *)((longlong)param_1 + 0x57c) = 2;
      return 0xb;
    }
    plVar4 = (longlong *)param_1[0xa1];
    puVar1 = plVar3 + -4;
    if ((longlong *)*plVar4 != plVar9) {
LAB_14000194c:
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      pcVar6 = (code *)swi(3);
      uVar8 = (*pcVar6)();
      return uVar8;
    }
    *puVar1 = plVar9;
    plVar3[-3] = (longlong)plVar4;
    *plVar4 = (longlong)puVar1;
    param_1[0xa1] = (longlong)puVar1;
    lVar5 = *plVar3;
    if (((longlong *)*(longlong *)(lVar5 + 8) != plVar3) ||
       (plVar9 = (longlong *)plVar3[1], (longlong *)*plVar9 != plVar3)) goto LAB_14000194c;
    *plVar9 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar9;
    if ((Microsoft_Windows_Hyper_V_KMCL_ChildEnableBits & 1) != 0) {
      lVar5 = *param_1;
      McTemplateK0jjxth_EtwWriteTransfer
                (lVar5 + 0xac0,&VMBUS_FETCH_PACKET,param_3,lVar5 + 0xad0,lVar5 + 0xac0,
                 (char)plVar3[3],1,(char)*(undefined2 *)(lVar5 + 0xcd0));
    }
  } while( true );
}



===== InpProcessQueue @ 140001960 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 InpProcessQueue(longlong *param_1,char param_2,uint param_3,uint *param_4)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  bool bVar5;
  code *pcVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulonglong uVar9;
  uint uVar10;
  longlong lVar11;
  int iVar12;
  
  lVar1 = *param_1;
  uVar10 = 0;
  uVar8 = 1;
  do {
    if ((param_3 <= uVar10) || (plVar2 = (longlong *)param_1[0xa0], plVar2 == param_1 + 0xa0))
    goto LAB_140001b27;
    if (*(int *)(plVar2 + 2) == 1) {
      lVar3 = *plVar2;
      uVar9 = 0;
      if ((*(byte *)((longlong)plVar2 + -0x52) & 2) == 0) {
        uVar9 = 0xc0000023;
      }
      if (((longlong *)*(longlong *)(lVar3 + 8) != plVar2) ||
         (plVar4 = (longlong *)plVar2[1], (longlong *)*plVar4 != plVar2)) {
LAB_140001bae:
        pcVar6 = (code *)swi(0x29);
        (*pcVar6)(3);
        pcVar6 = (code *)swi(3);
        uVar8 = (*pcVar6)();
        return uVar8;
      }
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      OutCompletePacketToClient
                ((longlong)(plVar2 + -0x12),uVar9,*(undefined4 *)((longlong)plVar2 + -0x1c));
    }
    else {
      lVar3 = (longlong)(plVar2 + -3);
      if (((*(byte *)(plVar2 + -1) & 2) != 0) && (param_2 != '\0')) {
        *(undefined1 *)((longlong)param_1 + 0x4b1) = 1;
LAB_140001b27:
        *param_4 = uVar10;
        return uVar8;
      }
      bVar5 = *(int *)((longlong)plVar2 + 0x34) != 0;
      *(undefined8 *)((longlong)param_1 + 0x584) = 0;
      lVar11 = *plVar2;
      if (((longlong *)*(longlong *)(lVar11 + 8) != plVar2) ||
         (plVar4 = (longlong *)plVar2[1], (longlong *)*plVar4 != plVar2)) goto LAB_140001bae;
      *plVar4 = lVar11;
      *(longlong **)(lVar11 + 8) = plVar4;
      *(int *)((longlong)param_1 + 0x524) = *(int *)((longlong)param_1 + 0x524) + 1;
      if (*(char *)((longlong)plVar2 + -7) != '\0') {
        *(int *)(param_1 + 0xa5) = (int)param_1[0xa5] + 1;
      }
      lVar11 = (ulonglong)*(ushort *)((longlong)plVar2 + 0x8a) * 8;
      iVar12 = (uint)*(ushort *)((longlong)plVar2 + 0x8c) * 8 - (int)lVar11;
      if (KmclPerformanceCounterTimingCounters != 0) {
        uVar7 = KeQueryPerformanceCounter(0);
        plVar2[9] = uVar7;
      }
      lVar11 = lVar11 + 0xa0 + lVar3;
      if (*(char *)(lVar1 + 0x7c8) == '\0') {
        (**(code **)(lVar1 + 2000))(lVar1,lVar3,lVar11,iVar12,bVar5);
      }
      else {
        (**(code **)(lVar1 + 2000))(lVar1,*(undefined8 *)(lVar1 + 0x7e0),lVar3,lVar11,iVar12,bVar5);
      }
      iVar12 = *(int *)((longlong)param_1 + 0x584);
      if (iVar12 != 0) {
        if (iVar12 == 1) {
          *(undefined4 *)((longlong)param_1 + 0x584) = 0;
          InRequeuePacket((longlong)param_1,lVar3);
          uVar8 = 8;
          goto LAB_140001b27;
        }
        if (iVar12 == 2) {
          *(undefined4 *)((longlong)param_1 + 0x584) = 0;
          InRequeuePacket((longlong)param_1,lVar3);
          uVar8 = 7;
          goto LAB_140001b27;
        }
        if (iVar12 == 3) {
          *(undefined4 *)((longlong)param_1 + 0x584) = 0;
          *(undefined1 *)((longlong)param_1 + 0x4b1) = 1;
          InRequeuePacket((longlong)param_1,lVar3);
          goto LAB_140001b27;
        }
      }
    }
    uVar10 = uVar10 + 1;
  } while( true );
}



===== OutpPacketNeedsIsolation @ 140001bc0 =====

ulonglong OutpPacketNeedsIsolation(ulonglong *param_1,longlong param_2)

{
  ulonglong in_RAX;
  
  if (((*(char *)(param_2 + 0x3d) == '\x01') &&
      (in_RAX = *param_1, *(char *)(in_RAX + 0xb51) != '\0')) &&
     ((*(int *)(param_2 + 0x18) != 2 || (*(longlong *)(param_2 + 0x50) == 0)))) {
    return CONCAT71((int7)(in_RAX >> 8),1);
  }
  return in_RAX & 0xffffffffffffff00;
}



===== OutpPacketCopyBouncePagesToMdl @ 140001bf0 =====

void OutpPacketCopyBouncePagesToMdl(longlong param_1,longlong param_2,char param_3)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  void *pvVar4;
  undefined1 uVar5;
  uint uVar6;
  ulonglong uVar7;
  size_t _Size;
  void *_Dst;
  uint uVar8;
  void *_Src;
  longlong lVar9;
  size_t sVar10;
  undefined8 *puVar11;
  uint uVar12;
  uint local_res10;
  ulonglong local_res20;
  longlong local_88;
  uint local_80;
  void *local_78;
  void *local_70;
  longlong *local_60;
  longlong *local_58;
  
  uVar5 = 0;
  local_80 = 0;
  bVar3 = false;
  if ((*(char *)(param_2 + 0x3d) == '\x01') &&
     (local_60 = *(longlong **)(param_2 + 0x50), local_60 != (longlong *)0x0)) {
    bVar1 = *(byte *)(param_2 + 0x3e);
    if (param_3 == '\0') {
      bVar2 = bVar1 & 0x10;
    }
    else {
      bVar2 = bVar1 & 0x20;
    }
    if (bVar2 == 0) {
      uVar12 = *(uint *)(param_2 + 0x48);
      if ((((uVar12 != 0) || (*(int *)(param_2 + 0x4c) != 0)) || (uVar8 = 0, (bVar1 & 1) != 0)) &&
         (uVar8 = uVar12, (bVar1 & 1) != 0)) {
        local_80 = *(uint *)(param_2 + 0x4c);
      }
      puVar11 = *(undefined8 **)(param_2 + 0x40);
      uVar12 = local_80;
      do {
        uVar6 = *(uint *)((longlong)puVar11 + 0x2c);
        lVar9 = (ulonglong)uVar6 + puVar11[4];
        if ((*(byte *)((longlong)puVar11 + 10) & 5) == 0) {
          local_78 = (void *)MmMapLockedPagesSpecifyCache
                                       (puVar11,0,1,0,0,ExDefaultMdlProtection | 0x40000020);
          uVar6 = *(uint *)((longlong)puVar11 + 0x2c);
        }
        else {
          local_78 = (void *)puVar11[3];
        }
        pvVar4 = local_78;
        local_res20 = (ulonglong)uVar6;
        if (uVar12 == 0) {
          local_res10 = *(uint *)(puVar11 + 5);
          uVar6 = uVar12;
        }
        else {
          local_80 = 0;
          uVar6 = 0;
          local_res10 = uVar12;
        }
        sVar10 = (size_t)local_res10;
        local_58 = (longlong *)local_60[2];
        uVar12 = uVar6;
        if (local_58 != local_60 + 2) {
          _Src = local_78;
          local_88 = lVar9;
          do {
            local_70 = (void *)local_58[4];
            if ((int)local_res20 != 0) {
              if (param_3 == '\0') {
                memset(local_70,0,local_res20);
                sVar10 = (size_t)local_res10;
                _Src = local_78;
                lVar9 = local_88;
              }
            }
            uVar12 = 0x1000 - (int)local_res20;
            local_70 = (void *)((longlong)local_70 + local_res20);
            local_res20 = 0;
            if (uVar8 != 0) {
              uVar6 = uVar8;
              if (uVar12 < uVar8) {
                uVar6 = uVar12;
              }
              uVar7 = (ulonglong)uVar6;
              if (param_3 == '\0') {
                memset(local_70,0,(ulonglong)uVar6);
                sVar10 = (size_t)local_res10;
                _Src = local_78;
                lVar9 = local_88;
              }
              local_70 = (void *)((longlong)local_70 + uVar7);
              uVar12 = uVar12 - uVar6;
              lVar9 = lVar9 + uVar7;
              _Src = (void *)((longlong)_Src + uVar7);
              local_res20 = (ulonglong)-uVar6;
              uVar8 = uVar8 - uVar6;
              local_88 = lVar9;
              local_78 = _Src;
            }
            _Size = sVar10;
            if (uVar12 < (uint)sVar10) {
              _Size = (size_t)uVar12;
            }
            uVar6 = (uint)_Size;
            if (uVar6 != 0) {
              if (pvVar4 == (void *)0x0) {
                if (param_3 == '\0') {
                  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x100);
                  bVar3 = true;
                  lVar9 = local_88;
                }
                _Src = (void *)OutpAcquireReservedMapping(param_1,param_3,puVar11,lVar9,uVar6);
              }
              if (param_3 == '\0') {
                _Dst = local_70;
              }
              else {
                _Dst = _Src;
                _Src = local_70;
              }
              memmove(_Dst,_Src,_Size);
              if ((pvVar4 == (void *)0x0) && (OutpReleaseReservedMapping(param_1,param_3), bVar3)) {
                KeReleaseSpinLock(param_1 + 0x100,uVar5);
                bVar3 = false;
              }
              uVar12 = uVar12 - uVar6;
              lVar9 = local_88 + _Size;
              _Src = (void *)((longlong)local_78 + _Size);
              local_70 = (void *)((longlong)local_70 + _Size);
              local_res10 = local_res10 - uVar6;
              sVar10 = (size_t)local_res10;
              local_88 = lVar9;
              local_78 = _Src;
            }
            if (uVar12 != 0) {
              if (param_3 == '\0') {
                memset(local_70,0,(ulonglong)uVar12);
                sVar10 = (size_t)local_res10;
                _Src = local_78;
                lVar9 = local_88;
              }
            }
            local_58 = (longlong *)*local_58;
          } while (local_58 != local_60 + 2);
          uVar12 = local_80;
        }
        local_60 = (longlong *)*local_60;
        puVar11 = (undefined8 *)*puVar11;
      } while (local_60 != (longlong *)0x0);
    }
  }
  return;
}



===== OutpTrySendControlPacket @ 140001f90 =====

ulonglong OutpTrySendControlPacket
                    (longlong *param_1,undefined8 param_2,longlong param_3,char param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  int iVar6;
  ulonglong uVar7;
  bool bVar8;
  int in_stack_ffffffffffffffe8;
  byte bVar9;
  
  plVar5 = param_1 + 8;
  if (*(char *)(param_3 + 0x3d) == '\0') {
    uVar7 = (ulonglong)*(uint *)(param_3 + 0x38);
    uVar2 = PkSendPacketSimple(plVar5,*(void **)(param_3 + 0x30),*(uint *)(param_3 + 0x38),param_2,
                               param_4);
  }
  else if (*(char *)(param_3 + 0x3d) == '\x01') {
    bVar9 = *(byte *)(param_3 + 0x3e) & 1;
    if (*(longlong **)(param_3 + 0x50) == (longlong *)0x0) {
      uVar7 = (ulonglong)*(uint *)(param_3 + 0x38);
      uVar2 = PkSendPacketGpaDirect
                        (plVar5,*(void **)(param_3 + 0x30),*(uint *)(param_3 + 0x38),param_2,
                         *(longlong **)(param_3 + 0x40),*(uint *)(param_3 + 0x48),
                         *(uint *)(param_3 + 0x4c),bVar9);
    }
    else {
      uVar7 = (ulonglong)*(uint *)(param_3 + 0x38);
      uVar2 = PkSendPacketGpaDirectList
                        (plVar5,*(void **)(param_3 + 0x30),*(uint *)(param_3 + 0x38),param_2,
                         *(longlong **)(param_3 + 0x50),*(uint *)(param_3 + 0x48),
                         *(uint *)(param_3 + 0x4c),bVar9);
    }
  }
  else {
    uVar7 = (ulonglong)*(uint *)(param_3 + 0x38);
    uVar2 = PkSendPacketTransferPage
                      (plVar5,*(void **)(param_3 + 0x30),*(uint *)(param_3 + 0x38),param_2,
                       *(ushort *)(param_3 + 0x48),*(undefined8 **)(param_3 + 0x40),
                       in_stack_ffffffffffffffe8);
  }
  uVar4 = uVar2 & 0xffffffff;
  if ((Microsoft_Windows_Hyper_V_KMCL_ChildEnableBits & 2) != 0) {
    lVar1 = *param_1;
    McTemplateK0jjxth_EtwWriteTransfer
              (lVar1 + 0xac0,&VMBUS_SEND_PACKET,uVar7,lVar1 + 0xad0,lVar1 + 0xac0,(char)param_2,0,
               (char)*(undefined2 *)(lVar1 + 0xcd0));
  }
  iVar6 = (int)uVar2;
  if (iVar6 < 0) {
    if (iVar6 == -0x7ffffffb) {
      if (((int)param_1[0x21] != 5) &&
         (*(undefined4 *)(param_1 + 0x21) = 2, (*(byte *)(param_1[0xb] + 0x40) & 1) == 0)) {
        OutpEnqueuePollingTimer((longlong)param_1);
      }
      uVar4 = 0x80000005;
    }
    else if (iVar6 != -0x3ffffff3) {
      *(undefined4 *)(param_1 + 0x21) = 6;
      *(int *)((longlong)param_1 + 0x42c) = iVar6;
    }
  }
  else {
    if ((param_4 != '\0') && (KmclPerformanceCounterTimingCounters != 0)) {
      uVar3 = KeQueryPerformanceCounter(0);
      bVar8 = KmclPerformanceCounterTimingCounters != 0;
      *(undefined8 *)(param_3 + 0x80) = uVar3;
      if (bVar8) {
        *(int *)(param_1 + 0x40) = (int)param_1[0x40] + 1;
      }
    }
    *(int *)(param_1 + 0x39) = (int)param_1[0x39] + 1;
    if (iVar6 == 0x214) {
      bVar8 = KmclSendSignal(*param_1);
      if (bVar8) {
        param_1[0x3b] = param_1[0x3b] + 1;
      }
      else {
        param_1[0x3c] = param_1[0x3c] + 1;
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}



===== OutSendCompletionAtDpcLevel @ 140002170 =====

undefined8
OutSendCompletionAtDpcLevel
          (longlong *param_1,longlong *param_2,void *param_3,uint param_4,char param_5)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  longlong *plVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  void *pvVar13;
  longlong lVar14;
  undefined4 *puVar15;
  uint uVar16;
  bool bVar17;
  
  plVar9 = param_1 + 0x20;
  pvVar13 = param_3;
  KeAcquireSpinLockAtDpcLevel();
  if ((int)param_1[0x21] == 1) {
    lVar3 = param_2[5];
    iVar11 = 0;
    uVar10 = param_4 + 0x10;
    if (uVar10 < 0x7fff9) {
      uVar1 = *(uint *)(param_1 + 0x18);
      uVar16 = param_4 + 0x17 & 0xfffffff8;
      uVar2 = *(uint *)(param_1 + 10);
      puVar15 = (undefined4 *)((ulonglong)uVar1 + param_1[9]);
      pvVar13 = (void *)(ulonglong)(uVar16 + 8);
      uVar6 = (*(int *)((longlong)param_1 + 0xc4) - uVar1) - 8;
      if (uVar2 <= uVar6) {
        uVar6 = uVar6 + uVar2;
      }
      lVar14 = lVar3;
      if (uVar6 < uVar16 + 8) {
        lVar4 = param_1[8];
        plVar9 = (longlong *)(ulonglong)uVar2;
        uVar6 = *(uint *)(lVar4 + 4);
        cVar5 = PkpValidatePointer(uVar2,uVar6);
        if (cVar5 == '\0') {
          iVar12 = -0x3ffffefe;
        }
        else {
          *(uint *)((longlong)param_1 + 0xc4) = uVar6;
          uVar6 = (uVar6 - uVar1) - 8;
          if (uVar2 <= uVar6) {
            uVar6 = uVar6 + uVar2;
          }
          if ((uint)pvVar13 <= uVar6) goto code_r0x000140002303;
          if ((uint)pvVar13 < uVar2) {
            if ((int)param_1[0x19] == 0) {
              PkpExpectInterrupt((longlong)(param_1 + 8),'\0');
              pvVar13 = (void *)(ulonglong)(uVar16 + 8);
              lVar14 = lVar3;
            }
            uVar6 = uVar1 - (int)param_1[0x18];
            if (uVar2 <= uVar6) {
              uVar6 = uVar6 + uVar2;
            }
            uVar6 = uVar6 + (int)pvVar13;
            uVar7 = uVar2 - 8;
            if (uVar6 < uVar2) {
              uVar7 = uVar6;
            }
            *(uint *)(lVar4 + 0xc) = uVar7;
            *(uint *)(param_1 + 0x19) = uVar16;
            LOCK();
            UNLOCK();
            uVar6 = *(uint *)(lVar4 + 4);
            plVar9 = (longlong *)(ulonglong)uVar2;
            cVar5 = PkpValidatePointer(uVar2,uVar6);
            if (cVar5 == '\0') {
              iVar12 = -0x3ffffefe;
            }
            else {
              *(uint *)((longlong)param_1 + 0xc4) = uVar6;
              uVar6 = (uVar6 - uVar1) - 8;
              if (uVar2 <= uVar6) {
                uVar6 = uVar6 + uVar2;
              }
              if ((uint)pvVar13 <= uVar6) goto code_r0x000140002303;
              iVar12 = -0x7ffffffb;
            }
          }
          else {
            iVar12 = -0x3ffffff3;
          }
        }
      }
      else {
code_r0x000140002303:
        *puVar15 = 0x2000b;
        *(short *)(puVar15 + 1) = (short)((ulonglong)uVar10 + 7 >> 3);
        *(undefined2 *)((longlong)puVar15 + 6) = 0;
        *(longlong *)(puVar15 + 2) = lVar14;
        memmove(puVar15 + 4,param_3,(ulonglong)param_4);
        pvVar13 = (void *)(ulonglong)uVar10;
        uVar10 = PkWritePacketFooter(param_1 + 8,uVar1,uVar10);
        plVar9 = param_1 + 8;
        uVar8 = PkCompleteInsertion(plVar9,uVar10);
        iVar12 = (int)uVar8;
      }
    }
    else {
      iVar12 = -0x3ffffff3;
    }
    if ((Microsoft_Windows_Hyper_V_KMCL_ChildEnableBits & 2) != 0) {
      lVar14 = *param_1;
      plVar9 = (longlong *)(ulonglong)*(ushort *)(lVar14 + 0xcd0);
      McTemplateK0jjxth_EtwWriteTransfer
                (plVar9,&VMBUS_SEND_PACKET,pvVar13,lVar14 + 0xad0,lVar14 + 0xac0,(char)lVar3,1,
                 (char)*(ushort *)(lVar14 + 0xcd0));
    }
    if (iVar12 < 0) {
      if (iVar12 == -0x7ffffffb) {
        if (((int)param_1[0x21] != 5) &&
           (*(undefined4 *)(param_1 + 0x21) = 2, (*(byte *)(param_1[0xb] + 0x40) & 1) == 0)) {
          plVar9 = param_1;
          OutpEnqueuePollingTimer((longlong)param_1);
        }
        iVar12 = -0x7ffffffb;
      }
      else if (iVar12 != -0x3ffffff3) {
        *(undefined4 *)(param_1 + 0x21) = 6;
        *(int *)((longlong)param_1 + 0x42c) = iVar12;
      }
    }
    else {
      *(int *)(param_1 + 0x42) = (int)param_1[0x42] + 1;
      *(int *)(param_1 + 0x39) = (int)param_1[0x39] + 1;
      bVar17 = iVar12 == 0x214;
      iVar12 = iVar11;
      if (bVar17) {
        plVar9 = (longlong *)*param_1;
        bVar17 = KmclSendSignal((longlong)plVar9);
        if (bVar17) {
          param_1[0x3b] = param_1[0x3b] + 1;
        }
        else {
          param_1[0x3c] = param_1[0x3c] + 1;
        }
      }
    }
    if (iVar12 < 0) goto LAB_140002449;
LAB_140002475:
    uVar8 = 1;
  }
  else {
LAB_140002449:
    if (param_5 == '\0') {
      param_2[6] = (longlong)param_3;
    }
    else {
      if (*(uint *)(param_2 + 3) < param_4) {
        MicrosoftTelemetryAssertTriggeredArgsKM(plVar9,param_4,*(uint *)(param_2 + 3));
        goto LAB_140002475;
      }
      memmove((void *)param_2[6],param_3,(ulonglong)param_4);
    }
    *(uint *)(param_2 + 3) = param_4;
    *(undefined4 *)(param_2 + 2) = 2;
    OutpEnqueuePacket((longlong)param_1,param_2);
    uVar8 = 0;
  }
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x20);
  return uVar8;
}



===== OutpTrySendCompletionPacket @ 1400024c0 =====

byte OutpTrySendCompletionPacket(longlong *param_1,undefined8 param_2,void *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  void *_Src;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  
  iVar8 = 0;
  uVar9 = param_4 + 0x10;
  if (0x7fff8 < uVar9) {
    iVar10 = -0x3ffffff3;
    goto LAB_140002697;
  }
  uVar12 = param_4 + 0x17 & 0xfffffff8;
  uVar1 = *(uint *)(param_1 + 10);
  uVar2 = *(uint *)(param_1 + 0x18);
  uVar13 = uVar12 + 8;
  puVar11 = (undefined4 *)((ulonglong)uVar2 + param_1[9]);
  uVar5 = (*(int *)((longlong)param_1 + 0xc4) - uVar2) - 8;
  if (uVar1 <= uVar5) {
    uVar5 = uVar5 + uVar1;
  }
  uVar7 = param_2;
  _Src = param_3;
  if (uVar5 < uVar13) {
    lVar3 = param_1[8];
    uVar5 = *(uint *)(lVar3 + 4);
    cVar4 = PkpValidatePointer(uVar1,uVar5);
    if (cVar4 == '\0') {
      iVar10 = -0x3ffffefe;
      param_2 = uVar7;
      goto LAB_140002697;
    }
    *(uint *)((longlong)param_1 + 0xc4) = uVar5;
    uVar5 = (uVar5 - uVar2) - 8;
    if (uVar1 <= uVar5) {
      uVar5 = uVar5 + uVar1;
    }
    if (uVar5 < uVar13) {
      if (uVar1 <= uVar13) {
        iVar10 = -0x3ffffff3;
        param_2 = uVar7;
        goto LAB_140002697;
      }
      if ((int)param_1[0x19] == 0) {
        PkpExpectInterrupt((longlong)(param_1 + 8),'\0');
        uVar7 = param_2;
        _Src = param_3;
      }
      uVar5 = uVar2 - (int)param_1[0x18];
      if (uVar1 <= uVar5) {
        uVar5 = uVar5 + uVar1;
      }
      uVar6 = uVar1 - 8;
      if (uVar5 + uVar13 < uVar1) {
        uVar6 = uVar5 + uVar13;
      }
      *(uint *)(lVar3 + 0xc) = uVar6;
      *(uint *)(param_1 + 0x19) = uVar12;
      LOCK();
      UNLOCK();
      uVar5 = *(uint *)(lVar3 + 4);
      cVar4 = PkpValidatePointer(uVar1,uVar5);
      if (cVar4 == '\0') {
        iVar10 = -0x3ffffefe;
        param_2 = uVar7;
        goto LAB_140002697;
      }
      *(uint *)((longlong)param_1 + 0xc4) = uVar5;
      uVar5 = (uVar5 - uVar2) - 8;
      if (uVar1 <= uVar5) {
        uVar5 = uVar5 + uVar1;
      }
      if (uVar5 < uVar13) {
        iVar10 = -0x7ffffffb;
        param_2 = uVar7;
        goto LAB_140002697;
      }
    }
  }
  *puVar11 = 0x2000b;
  *(short *)(puVar11 + 1) = (short)((ulonglong)uVar9 + 7 >> 3);
  *(undefined2 *)((longlong)puVar11 + 6) = 0;
  *(undefined8 *)(puVar11 + 2) = uVar7;
  memmove(puVar11 + 4,_Src,(ulonglong)param_4);
  uVar9 = PkWritePacketFooter(param_1 + 8,uVar2,uVar9);
  uVar7 = PkCompleteInsertion(param_1 + 8,uVar9);
  iVar10 = (int)uVar7;
LAB_140002697:
  if ((Microsoft_Windows_Hyper_V_KMCL_ChildEnableBits & 2) != 0) {
    lVar3 = *param_1;
    McTemplateK0jjxth_EtwWriteTransfer
              ((ulonglong)*(ushort *)(lVar3 + 0xcd0),&VMBUS_SEND_PACKET,param_2,lVar3 + 0xad0,
               lVar3 + 0xac0,(char)param_2,1,(char)*(ushort *)(lVar3 + 0xcd0));
  }
  if (iVar10 < 0) {
    if (iVar10 == -0x7ffffffb) {
      if (((int)param_1[0x21] != 5) &&
         (*(undefined4 *)(param_1 + 0x21) = 2, (*(byte *)(param_1[0xb] + 0x40) & 1) == 0)) {
        OutpEnqueuePollingTimer((longlong)param_1);
      }
      iVar10 = -0x7ffffffb;
    }
    else if (iVar10 != -0x3ffffff3) {
      *(undefined4 *)(param_1 + 0x21) = 6;
      *(int *)((longlong)param_1 + 0x42c) = iVar10;
    }
  }
  else {
    *(int *)(param_1 + 0x42) = (int)param_1[0x42] + 1;
    *(int *)(param_1 + 0x39) = (int)param_1[0x39] + 1;
    bVar14 = iVar10 == 0x214;
    iVar10 = iVar8;
    if (bVar14) {
      bVar14 = KmclSendSignal(*param_1);
      if (bVar14) {
        param_1[0x3b] = param_1[0x3b] + 1;
      }
      else {
        param_1[0x3c] = param_1[0x3c] + 1;
      }
    }
  }
  return (byte)((uint)iVar10 >> 0x1f) ^ 1;
}



===== InCompletePacket @ 140002790 =====

void InCompletePacket(longlong *param_1,longlong param_2,void *param_3,uint param_4)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  longlong *plVar4;
  undefined8 uVar5;
  code *pcVar6;
  undefined1 uVar7;
  char cVar8;
  uint uVar9;
  longlong lVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  int iVar13;
  longlong *plVar14;
  int iVar15;
  undefined1 *puVar16;
  void *pvVar17;
  uint uVar18;
  undefined4 *puVar19;
  uint uVar20;
  uint uVar21;
  bool bVar22;
  undefined1 local_98 [8];
  undefined1 auStackY_90 [24];
  
  pvVar17 = param_3;
  if (((*(longlong *)(param_2 + 0x58) != 0) && (*(longlong *)(param_2 + 0x60) != 0)) &&
     (KmclPerformanceCounterTimingCounters != 0)) {
    *(longlong *)(param_2 + 0x58) = *(longlong *)(param_2 + 0x60) - *(longlong *)(param_2 + 0x58);
    lVar10 = KeQueryPerformanceCounter(0);
    bVar22 = KmclPerformanceCounterTimingCounters != 0;
    *(longlong *)(param_2 + 0x60) = lVar10 - *(longlong *)(param_2 + 0x60);
    if (bVar22) {
      param_1[0xab] = param_1[0xab] + *(longlong *)(param_2 + 0x58);
      param_1[0xac] = param_1[0xac] + *(longlong *)(param_2 + 0x60);
    }
  }
  if (*(longlong *)(param_2 + 0x30) != 0) {
    InpUnmapPacketMdl(param_1,param_2);
  }
  uVar7 = KfRaiseIrql(2);
  plVar14 = param_1 + 0x88;
  if ((*(byte *)(param_2 + 0x10) & 0x10) != 0) {
    KeAcquireSpinLockAtDpcLevel(plVar14);
    iVar15 = (int)param_1[0x89];
    puVar16 = local_98;
    if ((iVar15 == 0) || (puVar16 = local_98, iVar15 == 10)) {
LAB_1400028ab:
      if (((*(byte *)(param_2 + 0x10) & 4) != 0) && (iVar15 == 0)) {
        uVar21 = *(uint *)(param_2 + 0x54);
        uVar2 = *(uint *)(param_2 + 0x40);
        *(undefined8 *)(puVar16 + -8) = 0x1400028d3;
        memmove((void *)((ulonglong)uVar2 + 0xa0 + (ulonglong)uVar21 + param_2),param_3,
                (ulonglong)param_4);
        *(uint *)(param_2 + 0x50) = param_4;
      }
      *(byte *)(param_2 + 0x10) = *(byte *)(param_2 + 0x10) | 0x20;
      iVar15 = *(int *)((longlong)param_1 + 0x484) + 1;
      *(int *)((longlong)param_1 + 0x484) = iVar15;
      if (((int)param_1[0x89] == 10) && ((int)param_1[0x90] == iVar15)) {
        lVar10 = param_1[0x98];
        *(undefined4 *)(param_1 + 0x89) = 0;
        *(undefined8 *)(puVar16 + -8) = 0x140002917;
        KeSetEvent(lVar10,0,0);
        param_1[0x98] = 0;
      }
      *(undefined8 *)(puVar16 + -8) = 0x140002931;
      KeReleaseSpinLock(plVar14,uVar7);
      return;
    }
    lVar10 = *(longlong *)(param_2 + 0x18);
    if ((*(longlong *)(lVar10 + 8) != param_2 + 0x18) ||
       (plVar4 = *(longlong **)(param_2 + 0x20), *plVar4 != param_2 + 0x18)) {
      iVar15 = 3;
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)();
      puVar16 = auStackY_90;
      goto LAB_1400028ab;
    }
    *plVar4 = lVar10;
    *(longlong **)(lVar10 + 8) = plVar4;
    *(int *)(param_1 + 0x90) = (int)param_1[0x90] + -1;
    KeReleaseSpinLockFromDpcLevel(plVar14);
  }
  cVar1 = *(char *)(param_2 + 0x11);
  if ((*(byte *)(param_2 + 0x10) & 4) == 0) {
LAB_140002ca7:
    iVar15 = *(int *)(param_2 + 8);
    iVar13 = *(int *)(param_2 + 0xc);
    InpFreePacket((longlong)param_1,param_2);
    KeAcquireSpinLockAtDpcLevel(param_1 + 0x88);
    InpPacketFreedLocked((longlong)param_1,(ulonglong)(uint)(iVar15 - iVar13));
  }
  else {
    plVar14 = param_1 + 0x20;
    *(undefined8 *)(param_2 + 0x40) = *(undefined8 *)(param_2 + 0xa8);
    *(code **)(param_2 + 0x38) = InpCompletionSent;
    *(longlong *)(param_2 + 0x48) = param_2 + 0xa0;
    *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)((longlong)param_1 + 0x5ac);
    KeAcquireSpinLockAtDpcLevel();
    if ((int)param_1[0x21] == 1) {
      uVar5 = *(undefined8 *)(param_2 + 0x40);
      uVar21 = param_4 + 0x10;
      iVar15 = -0x7ffffffb;
      if (uVar21 < 0x7fff9) {
        uVar2 = *(uint *)(param_1 + 0x18);
        pvVar17 = (void *)(ulonglong)uVar2;
        uVar3 = *(uint *)(param_1 + 10);
        uVar20 = param_4 + 0x17 & 0xfffffff8;
        puVar19 = (undefined4 *)((ulonglong)uVar2 + param_1[9]);
        uVar18 = uVar20 + 8;
        uVar9 = (*(int *)((longlong)param_1 + 0xc4) - uVar2) - 8;
        if (uVar3 <= uVar9) {
          uVar9 = uVar9 + uVar3;
        }
        if (uVar9 < uVar18) {
          lVar10 = param_1[8];
          plVar14 = (longlong *)(ulonglong)uVar3;
          uVar9 = *(uint *)(lVar10 + 4);
          cVar8 = PkpValidatePointer(uVar3,uVar9);
          if (cVar8 == '\0') {
            iVar13 = -0x3ffffefe;
          }
          else {
            *(uint *)((longlong)param_1 + 0xc4) = uVar9;
            uVar9 = (uVar9 - (int)pvVar17) - 8;
            if (uVar3 <= uVar9) {
              uVar9 = uVar9 + uVar3;
            }
            if (uVar18 <= uVar9) goto code_r0x000140002afb;
            if (uVar18 < uVar3) {
              if ((int)param_1[0x19] == 0) {
                PkpExpectInterrupt((longlong)(param_1 + 8),'\0');
                pvVar17 = (void *)(ulonglong)uVar2;
                uVar18 = uVar20 + 8;
              }
              uVar9 = (int)pvVar17 - (int)param_1[0x18];
              if (uVar3 <= uVar9) {
                uVar9 = uVar9 + uVar3;
              }
              uVar9 = uVar9 + uVar18;
              if (uVar3 <= uVar9) {
                uVar9 = uVar3 - 8;
              }
              *(uint *)(lVar10 + 0xc) = uVar9;
              *(uint *)(param_1 + 0x19) = uVar20;
              LOCK();
              UNLOCK();
              uVar9 = *(uint *)(lVar10 + 4);
              plVar14 = (longlong *)(ulonglong)uVar3;
              cVar8 = PkpValidatePointer(uVar3,uVar9);
              if (cVar8 == '\0') {
                iVar13 = -0x3ffffefe;
              }
              else {
                *(uint *)((longlong)param_1 + 0xc4) = uVar9;
                uVar9 = (uVar9 - (int)pvVar17) - 8;
                if (uVar3 <= uVar9) {
                  uVar9 = uVar9 + uVar3;
                }
                if (uVar18 <= uVar9) goto code_r0x000140002afb;
                iVar13 = -0x7ffffffb;
              }
            }
            else {
              iVar13 = -0x3ffffff3;
            }
          }
        }
        else {
code_r0x000140002afb:
          *puVar19 = 0x2000b;
          *(short *)(puVar19 + 1) = (short)((ulonglong)uVar21 + 7 >> 3);
          *(undefined2 *)((longlong)puVar19 + 6) = 0;
          *(undefined8 *)(puVar19 + 2) = uVar5;
          memmove(puVar19 + 4,param_3,(ulonglong)param_4);
          pvVar17 = (void *)(ulonglong)uVar21;
          uVar21 = PkWritePacketFooter(param_1 + 8,uVar2,uVar21);
          plVar14 = param_1 + 8;
          uVar11 = PkCompleteInsertion(plVar14,uVar21);
          iVar13 = (int)uVar11;
        }
      }
      else {
        iVar13 = -0x3ffffff3;
      }
      if ((Microsoft_Windows_Hyper_V_KMCL_ChildEnableBits & 2) != 0) {
        lVar10 = *param_1;
        plVar14 = (longlong *)(ulonglong)*(ushort *)(lVar10 + 0xcd0);
        McTemplateK0jjxth_EtwWriteTransfer
                  (plVar14,&VMBUS_SEND_PACKET,pvVar17,lVar10 + 0xad0,lVar10 + 0xac0,(char)uVar5,1,
                   (char)*(ushort *)(lVar10 + 0xcd0));
      }
      if (iVar13 < 0) {
        if (iVar13 == -0x7ffffffb) {
          iVar13 = iVar15;
          if (((int)param_1[0x21] != 5) &&
             (*(undefined4 *)(param_1 + 0x21) = 2, (*(byte *)(param_1[0xb] + 0x40) & 1) == 0)) {
            plVar14 = param_1;
            OutpEnqueuePollingTimer((longlong)param_1);
          }
        }
        else if (iVar13 != -0x3ffffff3) {
          *(undefined4 *)(param_1 + 0x21) = 6;
          *(int *)((longlong)param_1 + 0x42c) = iVar13;
        }
      }
      else {
        *(int *)(param_1 + 0x42) = (int)param_1[0x42] + 1;
        *(int *)(param_1 + 0x39) = (int)param_1[0x39] + 1;
        if (iVar13 == 0x214) {
          plVar14 = (longlong *)*param_1;
          bVar22 = KmclSendSignal((longlong)plVar14);
          if (bVar22) {
            param_1[0x3b] = param_1[0x3b] + 1;
          }
          else {
            param_1[0x3c] = param_1[0x3c] + 1;
          }
        }
        iVar13 = 0;
      }
      if (iVar13 < 0) goto LAB_140002c35;
LAB_140002c94:
      KeReleaseSpinLockFromDpcLevel(param_1 + 0x20);
      goto LAB_140002ca7;
    }
LAB_140002c35:
    if (*(uint *)(param_2 + 0x30) < param_4) {
      MicrosoftTelemetryAssertTriggeredArgsKM(plVar14,param_4,*(uint *)(param_2 + 0x30));
      goto LAB_140002c94;
    }
    memmove(*(void **)(param_2 + 0x48),param_3,(ulonglong)param_4);
    *(uint *)(param_2 + 0x30) = param_4;
    *(undefined4 *)(param_2 + 0x28) = 2;
    OutpEnqueuePacket((longlong)param_1,(longlong *)(param_2 + 0x18));
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x20);
    KeAcquireSpinLockAtDpcLevel(param_1 + 0x88);
  }
  cVar8 = '\0';
  if (cVar1 == '\0') {
    if ((((int)param_1[0x89] != 4) || ((char)param_1[0x96] == '\0')) ||
       (*(int *)((longlong)param_1 + 0x84) == *(int *)param_1[0xb])) goto LAB_140002d40;
    ((int *)param_1[0xb])[2] = 1;
    *(byte *)((longlong)param_1 + 0x44c) = *(byte *)((longlong)param_1 + 0x44c) | 4;
    *(int *)((longlong)param_1 + 0x47c) = *(int *)((longlong)param_1 + 0x47c) + 1;
    iVar15 = (int)param_1[0x89];
  }
  else {
    iVar15 = (int)param_1[0x91] + -1;
    *(int *)(param_1 + 0x91) = iVar15;
    if ((int)param_1[0x89] == 4) {
      if (*(int *)((longlong)param_1 + 0x84) != *(int *)param_1[0xb]) {
        *(int *)((longlong)param_1 + 0x47c) = *(int *)((longlong)param_1 + 0x47c) + 1;
        iVar15 = (int)param_1[0x89];
        goto LAB_140002d5d;
      }
      if ((int)param_1[0xa5] + iVar15 == *(int *)((longlong)param_1 + 0x52c) + -1) {
        cVar8 = '\0';
        lVar10 = InpDisableInterruptMaskingAndPollLocked((longlong)param_1);
        if ((char)lVar10 == '\0') {
          cVar8 = '\x01';
        }
      }
    }
LAB_140002d40:
    iVar15 = (int)param_1[0x89];
    iVar13 = *(int *)((longlong)param_1 + 0x47c) + 1;
    *(int *)((longlong)param_1 + 0x47c) = iVar13;
    if (cVar8 == '\0') {
      if (iVar15 == 2) {
        uVar12 = InpPrepareToQueueWorkerLocked((longlong)param_1,'\0','\0');
        if ((char)uVar12 != '\0') {
          *(int *)((longlong)param_1 + 0x49c) = *(int *)((longlong)param_1 + 0x49c) + 1;
        }
      }
      else if ((iVar15 == 9) && (iVar13 + (int)param_1[0x90] == *(int *)((longlong)param_1 + 0x524))
              ) {
        *(undefined4 *)(param_1 + 0x89) = 0;
        KmclDecrementRundownCount(*param_1,'\x01',0x8e8);
      }
      goto LAB_140002ed8;
    }
  }
LAB_140002d5d:
  if ((iVar15 == 1) && (param_1[0x98] != 0)) {
    KeSetEvent(param_1[0x98],0,0);
    param_1[0x98] = 0;
    param_1[0x8d] = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x89) = 2;
    param_1[0x8d] = 0;
    iVar15 = SystemReserved1[0x12]._4_4_;
    if ((((param_1[0x8e] == 0) && ((int)param_1[0xcc] != SystemReserved1[0x12]._4_4_)) &&
        (*(int *)((longlong)param_1 + 0x664) != SystemReserved1[0x12]._4_4_)) &&
       ((int)param_1[0xcd] != SystemReserved1[0x12]._4_4_)) {
      if (*(char *)((longlong)param_1 + 0x4b1) == '\0') {
        if ((int)param_1[0xcc] == -1) {
          *(int *)(param_1 + 0xcc) = SystemReserved1[0x12]._4_4_;
          lVar10 = 0x5d8;
        }
        else {
          if (*(int *)((longlong)param_1 + 0x664) != -1) goto LAB_140002ed8;
          *(int *)((longlong)param_1 + 0x664) = SystemReserved1[0x12]._4_4_;
          lVar10 = 0x618;
        }
        param_1[0x95] = param_1[0x95] + 1;
        lVar10 = lVar10 + (longlong)param_1;
        *(byte *)((longlong)param_1 + 0x44c) = *(byte *)((longlong)param_1 + 0x44c) & 0xfe;
      }
      else {
        if ((int)param_1[0xcd] != -1) goto LAB_140002ed8;
        *(byte *)((longlong)param_1 + 0x44c) = *(byte *)((longlong)param_1 + 0x44c) | 2;
        param_1[0x94] = param_1[0x94] + 1;
        *(int *)(param_1 + 0xcd) = iVar15;
        lVar10 = param_1[0xcb];
      }
      *(int *)((longlong)param_1 + 0x48c) = *(int *)((longlong)param_1 + 0x48c) + 1;
      *(int *)(param_1 + 0x93) = (int)param_1[0x93] + 1;
      param_1[0x8e] = lVar10;
    }
  }
LAB_140002ed8:
  InpReleaseLockAndPerformWork(param_1);
  return;
}



===== InpReleaseLockAndPerformWork @ 140002f10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void InpReleaseLockAndPerformWork(longlong *param_1)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  char cVar4;
  
  lVar2 = param_1[0x8e];
  if (lVar2 == 0) {
    *(undefined1 *)((longlong)param_1 + 0x44c) = 0;
    KeReleaseSpinLock(param_1 + 0x88);
    return;
  }
  bVar1 = *(byte *)((longlong)param_1 + 0x44c);
  param_1[0x8e] = 0;
  *(undefined1 *)((longlong)param_1 + 0x44c) = 0;
  if ((bVar1 & 4) != 0) {
    lVar3 = *param_1;
    cVar4 = (**(code **)(lVar3 + 0x9d8))(*(undefined8 *)(lVar3 + 0x940));
    if (cVar4 != '\0') {
      *(longlong *)(lVar3 + 0x688) = *(longlong *)(lVar3 + 0x688) + 1;
      KeReleaseSpinLock();
      OutPollQueue((longlong)param_1,'\0');
      goto LAB_140002fdc;
    }
  }
  KeReleaseSpinLock(param_1 + 0x88);
LAB_140002fdc:
  if ((bVar1 & 2) == 0) {
    KeInsertQueueDpc(lVar2,bVar1 & 1,0);
  }
  else {
    (**(code **)(*param_1 + 0x9e0))
              (*(undefined8 *)(*param_1 + 0x940),lVar2,InpProcessingWorkerRoutine,param_1);
  }
  return;
}



===== InpPacketFreedLocked @ 140003040 =====

void InpPacketFreedLocked(longlong param_1,ulonglong param_2)

{
  int iVar1;
  
  LOCK();
  *(int *)(param_1 + 0x478) = *(int *)(param_1 + 0x478) + 1;
  UNLOCK();
  *(longlong *)(param_1 + 0x490) = *(longlong *)(param_1 + 0x490) + (param_2 & 0xffffffff);
  iVar1 = *(int *)(param_1 + 0x448);
  if (iVar1 == 1) {
    *(byte *)(param_1 + 0x460) = *(byte *)(param_1 + 0x460) | 2;
  }
  else if ((iVar1 == 5) || (iVar1 == 6)) {
    InpPrepareToQueueWorkerLocked(param_1,'\0','\0');
  }
  return;
}



===== PkCompleteInsertion @ 140003088 =====

undefined8 PkCompleteInsertion(longlong *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined8 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  puVar2 = (undefined4 *)*param_1;
  uVar1 = *(uint *)(param_1 + 2);
  uVar7 = *(uint *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *puVar2 = param_2;
  LOCK();
  UNLOCK();
  iVar6 = puVar2[2];
  uVar5 = puVar2[1];
  cVar3 = PkpValidatePointer(uVar1,uVar5);
  if (cVar3 == '\0') {
    uVar4 = 0xc0000102;
  }
  else {
    *(uint *)((longlong)param_1 + 0x84) = uVar5;
    if (uVar7 == uVar5) {
      if (iVar6 == 0) {
        return 0x214;
      }
      *(longlong *)param_1[0x13] = *(longlong *)param_1[0x13] + 1;
    }
    uVar4 = 0;
  }
  return uVar4;
}



===== PkWritePacketFooter @ 1400030f4 =====

uint PkWritePacketFooter(longlong *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong *puVar4;
  
  uVar1 = *(uint *)(param_1 + 2);
  if ((param_3 & 7) != 0) {
    puVar4 = (ulonglong *)((ulonglong)((param_3 & 0xfffffff8) + param_2) + param_1[1]);
    *puVar4 = (1L << (sbyte)((param_3 & 7) << 3)) - 1U & *puVar4;
    param_3 = param_3 + 7 & 0xfffffff8;
  }
  *(ulonglong *)((ulonglong)(param_2 + param_3) + param_1[1]) = (ulonglong)param_2 << 0x20;
  if ((int)param_1[0x11] != 0) {
    *(undefined4 *)(param_1 + 0x11) = 0;
    *(undefined4 *)(*param_1 + 0xc) = 0;
  }
  uVar3 = param_2 + param_3 + 8;
  uVar2 = uVar3 - uVar1;
  if (uVar3 < uVar1) {
    uVar2 = uVar3;
  }
  return uVar2;
}



===== InpFreePacket @ 140003190 =====

void InpFreePacket(longlong param_1,longlong param_2)

{
  uint *puVar1;
  uint uVar2;
  
  if ((*(byte *)(param_2 + 0x10) & 1) == 0) {
    puVar1 = *(uint **)(param_1 + 0x5a0);
    uVar2 = *(uint *)(param_2 + 8) - 1 >> 10;
    if ((uVar2 < *puVar1) && (*(uint *)(param_2 + 8) == puVar1[(ulonglong)uVar2 * 0x20 + 0x1b])) {
      ExFreeToNPagedLookasideList(puVar1 + (ulonglong)uVar2 * 0x20 + 0x10,param_2);
      return;
    }
  }
  else if (param_2 == *(longlong *)(param_1 + 0x5b0)) {
    LOCK();
    *(longlong *)(param_1 + 0x5b8) = param_2;
    UNLOCK();
    return;
  }
  ExFreePoolWithTag(param_2,0x6e696b56);
  return;
}



===== KmclpVmbusIsr @ 140003210 =====

bool KmclpVmbusIsr(longlong *param_1)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined8 uVar4;
  
  param_1[0xd0] = param_1[0xd0] + 1;
  iVar3 = PkpExpectedInterruptCount((longlong)(param_1 + 8));
  if (iVar3 == 0) {
    *(int *)(param_1 + 0xd2) = (int)param_1[0xd2] + 1;
  }
  else {
    LOCK();
    *(int *)((longlong)param_1 + 0x8c) = *(int *)((longlong)param_1 + 0x8c) + 1;
    UNLOCK();
  }
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x88);
  if ((int)param_1[0x89] == 4) {
    *(undefined4 *)(param_1[0xb] + 8) = 1;
    *(undefined4 *)(param_1 + 0x89) = 1;
    param_1[0x8d] = (longlong)SystemReserved1[0xf];
    KeReleaseSpinLockFromDpcLevel();
    InpRunQueueAtDpcLevel(param_1,0);
  }
  else {
    KeReleaseSpinLockFromDpcLevel(param_1 + 0x88);
  }
  if ((int)param_1[0x19] != 0) {
    uVar4 = PkIsOutgoingRingFull(param_1 + 8,(int)param_1[0x19]);
    if ((char)uVar4 == '\0') {
      uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x20);
      if ((int)param_1[0x21] == 2) {
        OutpEnqueuePollingDpc((longlong)param_1);
        cVar2 = KeCancelTimer(param_1 + 0x69);
        if (cVar2 != '\0') {
          *(int *)(param_1 + 0x81) = (int)param_1[0x81] + -1;
        }
      }
      KeReleaseSpinLock(param_1 + 0x20,uVar1);
    }
  }
  return iVar3 != 0;
}



===== PkpExpectedInterruptCount @ 140003350 =====

int PkpExpectedInterruptCount(longlong param_1)

{
  return (*(int *)(param_1 + 0x8c) - *(int *)(param_1 + 0x4c)) + *(int *)(param_1 + 0x48);
}



===== InpRunQueueAtDpcLevel @ 140003368 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InpRunQueueAtDpcLevel(longlong *param_1,undefined8 param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 extraout_var;
  ulonglong uVar5;
  undefined1 auStackY_58 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
  lVar1 = _DAT_fffff78000000320;
  local_10 = __security_cookie ^ (ulonglong)auStackY_58;
  if (param_1[0xba] == -1) {
    iVar3 = InpFillAndProcessQueue
                      (param_1,CONCAT71((int7)((ulonglong)param_2 >> 8),2),(undefined4 *)0x1e);
  }
  else {
    if (((char)param_2 == '\0') && (uVar5 = _DAT_fffff78000000320 - param_1[0xb8], uVar5 != 0)) {
      if (uVar5 < 0x10) {
        uVar2 = param_1[0xb9];
        if (uVar5 == 1) {
          param_1[0xb9] = uVar2 - (uVar2 >> 4);
        }
        else {
          param_1[0xb9] = (0x10 - uVar5) * uVar2 >> 4;
        }
      }
      else {
        param_1[0xb9] = 0;
      }
      param_1[0xb8] = lVar1;
    }
    if ((ulonglong)param_1[0xba] <= (ulonglong)param_1[0xb9]) {
LAB_140003493:
      KeAcquireSpinLockAtDpcLevel(param_1 + 0x88);
      uVar4 = 0;
      InpPrepareToQueueWorkerLocked((longlong)param_1,'\x01','\0');
      InpReleaseLockAndPerformWork(param_1);
      *(int *)((longlong)param_1 + 0x534) = *(int *)((longlong)param_1 + 0x534) + 1;
      if ((Microsoft_Windows_Hyper_V_KMCL_ChildEnableBits & 4) == 0) {
        return;
      }
      lVar1 = *param_1;
      McTemplateK0jjh_EtwWriteTransfer
                (lVar1 + 0xac0,&VMBUS_HIT_DPC_LIMIT,uVar4,lVar1 + 0xad0,lVar1 + 0xac0,
                 (char)*(undefined2 *)(lVar1 + 0xcd0));
      return;
    }
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    uVar4 = KeQueryDpcWatchdogInformation(&local_28);
    if (-1 < (int)uVar4) {
      uVar4 = 0;
      if (uStack_20._4_4_ < (uint)((int)uStack_20 * 0x1e) / 100) goto LAB_140003493;
    }
    uVar5 = rdtsc();
    iVar3 = InpFillAndProcessQueue
                      (param_1,CONCAT71((int7)((uVar5 & 0xffffffff00000000) >> 8),2),
                       (undefined4 *)0x1e);
    uVar2 = rdtsc();
    param_1[0xb9] =
         param_1[0xb9] +
         ((CONCAT44(extraout_var,(int)uVar2) | uVar2 & 0xffffffff00000000) -
         (CONCAT44((int)((ulonglong)uVar4 >> 0x20),(int)uVar5) | uVar5 & 0xffffffff00000000));
  }
  InpTransitionRunningQueue(param_1,'\x01',iVar3);
  return;
}



===== InpPacketCompletedLocked @ 140003520 =====

void InpPacketCompletedLocked(longlong *param_1,char param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  
  cVar5 = '\0';
  if (param_2 == '\0') {
    if ((((int)param_1[0x89] == 4) && ((char)param_1[0x96] != '\0')) &&
       (*(int *)((longlong)param_1 + 0x84) != *(int *)param_1[0xb])) {
      ((int *)param_1[0xb])[2] = 1;
      *(byte *)((longlong)param_1 + 0x44c) = *(byte *)((longlong)param_1 + 0x44c) | 4;
      *(int *)((longlong)param_1 + 0x47c) = *(int *)((longlong)param_1 + 0x47c) + 1;
      iVar4 = (int)param_1[0x89];
      goto LAB_1400035a9;
    }
  }
  else {
    iVar4 = (int)param_1[0x91] + -1;
    *(int *)(param_1 + 0x91) = iVar4;
    if ((int)param_1[0x89] == 4) {
      if (*(int *)((longlong)param_1 + 0x84) != *(int *)param_1[0xb]) {
        *(int *)((longlong)param_1 + 0x47c) = *(int *)((longlong)param_1 + 0x47c) + 1;
        iVar4 = (int)param_1[0x89];
        goto LAB_1400035a9;
      }
      if (((int)param_1[0xa5] + iVar4 == *(int *)((longlong)param_1 + 0x52c) + -1) &&
         (cVar5 = '\0', lVar1 = InpDisableInterruptMaskingAndPollLocked((longlong)param_1),
         (char)lVar1 == '\0')) {
        cVar5 = '\x01';
      }
    }
  }
  iVar4 = (int)param_1[0x89];
  iVar3 = *(int *)((longlong)param_1 + 0x47c) + 1;
  *(int *)((longlong)param_1 + 0x47c) = iVar3;
  if (cVar5 == '\0') {
    if (iVar4 == 2) {
      uVar2 = InpPrepareToQueueWorkerLocked((longlong)param_1,'\0','\0');
      if ((char)uVar2 == '\0') {
        return;
      }
      *(int *)((longlong)param_1 + 0x49c) = *(int *)((longlong)param_1 + 0x49c) + 1;
      return;
    }
    if (iVar4 != 9) {
      return;
    }
    if (iVar3 + (int)param_1[0x90] == *(int *)((longlong)param_1 + 0x524)) {
      *(undefined4 *)(param_1 + 0x89) = 0;
      KmclDecrementRundownCount(*param_1,'\x01',0x8e8);
      return;
    }
    return;
  }
LAB_1400035a9:
  if ((iVar4 == 1) && (param_1[0x98] != 0)) {
    KeSetEvent(param_1[0x98],0,0);
    param_1[0x98] = 0;
    param_1[0x8d] = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x89) = 2;
    param_1[0x8d] = 0;
    iVar4 = SystemReserved1[0x12]._4_4_;
    if ((param_1[0x8e] == 0) &&
       ((((int)param_1[0xcc] != SystemReserved1[0x12]._4_4_ &&
         (*(int *)((longlong)param_1 + 0x664) != SystemReserved1[0x12]._4_4_)) &&
        ((int)param_1[0xcd] != SystemReserved1[0x12]._4_4_)))) {
      if (*(char *)((longlong)param_1 + 0x4b1) == '\0') {
        if ((int)param_1[0xcc] == -1) {
          *(int *)(param_1 + 0xcc) = SystemReserved1[0x12]._4_4_;
          lVar1 = 0x5d8;
        }
        else {
          if (*(int *)((longlong)param_1 + 0x664) != -1) {
            return;
          }
          *(int *)((longlong)param_1 + 0x664) = SystemReserved1[0x12]._4_4_;
          lVar1 = 0x618;
        }
        param_1[0x95] = param_1[0x95] + 1;
        lVar1 = lVar1 + (longlong)param_1;
        *(byte *)((longlong)param_1 + 0x44c) = *(byte *)((longlong)param_1 + 0x44c) & 0xfe;
      }
      else {
        if ((int)param_1[0xcd] != -1) {
          return;
        }
        *(byte *)((longlong)param_1 + 0x44c) = *(byte *)((longlong)param_1 + 0x44c) | 2;
        param_1[0x94] = param_1[0x94] + 1;
        *(int *)(param_1 + 0xcd) = iVar4;
        lVar1 = param_1[0xcb];
      }
      *(int *)((longlong)param_1 + 0x48c) = *(int *)((longlong)param_1 + 0x48c) + 1;
      *(int *)(param_1 + 0x93) = (int)param_1[0x93] + 1;
      param_1[0x8e] = lVar1;
    }
  }
  return;
}



===== OutSetupGpaDirectPacket @ 140003740 =====

void OutSetupGpaDirectPacket
               (longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               uint param_5)

{
  uint uVar1;
  byte bVar2;
  
  *(undefined4 *)(param_1 + 0x48) = param_3;
  bVar2 = *(byte *)(param_1 + 0x3e) & 0xfe;
  *(undefined8 *)(param_1 + 0x40) = param_2;
  *(undefined4 *)(param_1 + 0x4c) = param_4;
  uVar1 = param_5 & 2;
  *(undefined1 *)(param_1 + 0x3d) = 1;
  *(undefined8 *)(param_1 + 0x50) = 0;
  *(byte *)(param_1 + 0x3e) = uVar1 != 0 | bVar2;
  if ((param_5 & 8) != 0) {
    *(byte *)(param_1 + 0x3e) = (uVar1 != 0) + 0x10U | bVar2;
    return;
  }
  if ((param_5 & 0x10) != 0) {
    *(byte *)(param_1 + 0x3e) = (uVar1 != 0) + 0x20U | bVar2;
  }
  return;
}



===== PkGetSendBufferEx @ 1400037b0 =====

undefined8
PkGetSendBufferEx(longlong *param_1,uint param_2,int param_3,longlong *param_4,int *param_5)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  
  uVar2 = *(uint *)(param_1 + 2);
  uVar7 = param_3 + 7U & 0xfffffff8;
  lVar8 = (ulonglong)param_2 + param_1[1];
  uVar1 = uVar7 + 8;
  uVar6 = (*(int *)((longlong)param_1 + 0x84) - param_2) - 8;
  if (uVar2 <= uVar6) {
    uVar6 = uVar6 + uVar2;
  }
  if (uVar6 < uVar1) {
    lVar3 = *param_1;
    uVar6 = *(uint *)(lVar3 + 4);
    cVar4 = PkpValidatePointer(uVar2,uVar6);
    if (cVar4 == '\0') {
      return 0xc0000102;
    }
    *(uint *)((longlong)param_1 + 0x84) = uVar6;
    uVar6 = (uVar6 - param_2) - 8;
    if (uVar2 <= uVar6) {
      uVar6 = uVar6 + uVar2;
    }
    if (uVar6 < uVar1) {
      if (uVar2 <= uVar1) {
        return 0xc000000d;
      }
      if ((int)param_1[0x11] == 0) {
        PkpExpectInterrupt((longlong)param_1,'\0');
      }
      uVar6 = param_2 - (int)param_1[0x10];
      if (uVar2 <= uVar6) {
        uVar6 = uVar6 + uVar2;
      }
      uVar5 = uVar2 - 8;
      if (uVar6 + uVar1 < uVar2) {
        uVar5 = uVar6 + uVar1;
      }
      *(uint *)(lVar3 + 0xc) = uVar5;
      *(uint *)(param_1 + 0x11) = uVar7;
      LOCK();
      UNLOCK();
      uVar6 = *(uint *)(lVar3 + 4);
      cVar4 = PkpValidatePointer(uVar2,uVar6);
      if (cVar4 == '\0') {
        return 0xc0000102;
      }
      *(uint *)((longlong)param_1 + 0x84) = uVar6;
      uVar6 = (uVar6 - param_2) - 8;
      if (uVar2 <= uVar6) {
        uVar6 = uVar6 + uVar2;
      }
      if (uVar6 < uVar1) {
        return 0x80000005;
      }
    }
  }
  *param_4 = lVar8;
  *param_5 = uVar6 - 8;
  return 0;
}



===== OutpTransitionPacketToReadyToComplete @ 1400038f0 =====

void OutpTransitionPacketToReadyToComplete(longlong *param_1,longlong param_2)

{
  uint uVar1;
  uint local_18 [4];
  
  uVar1 = *(uint *)(param_2 + 0x1c);
  if (uVar1 != 0) {
    local_18[1] = 0;
    local_18[2] = 0;
    if (uVar1 < *(uint *)(param_1 + 0x5a)) {
      DvpPushFreeEntries((ulonglong *)param_1[0x59],uVar1,(ulonglong *)param_1[0x59] + uVar1);
    }
    else {
      local_18[0] = uVar1;
      RtlDeleteElementGenericTableAvl(param_1[0x5e],local_18);
    }
    *(undefined4 *)(param_2 + 0x1c) = 0;
  }
  if ((*(char *)(param_2 + 0x3d) == '\x01') &&
     (*(undefined8 **)(param_2 + 0x50) != (undefined8 *)0x0)) {
    KmclpFreeBounceList(*param_1,*(undefined8 **)(param_2 + 0x50));
    *(undefined8 *)(param_2 + 0x50) = 0;
  }
  *(undefined4 *)(param_2 + 0x18) = 4;
  return;
}



===== InpPrepareToQueueWorkerLocked @ 140003990 =====

ulonglong InpPrepareToQueueWorkerLocked(longlong param_1,char param_2,char param_3)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  if ((*(int *)(param_1 + 0x448) == 1) && (*(longlong *)(param_1 + 0x4c0) != 0)) {
    KeSetEvent(*(longlong *)(param_1 + 0x4c0),0,0);
    *(undefined8 *)(param_1 + 0x4c0) = 0;
    *(undefined8 *)(param_1 + 0x468) = 0;
    return 0;
  }
  uVar2 = 0;
  *(undefined4 *)(param_1 + 0x448) = 2;
  *(undefined8 *)(param_1 + 0x468) = 0;
  uVar1 = SystemReserved1[0x12]._4_4_;
  if (*(longlong *)(param_1 + 0x470) == 0) {
    uVar2 = (ulonglong)SystemReserved1[0x12]._4_4_;
    if (((*(uint *)(param_1 + 0x660) != SystemReserved1[0x12]._4_4_) &&
        (*(uint *)(param_1 + 0x664) != SystemReserved1[0x12]._4_4_)) &&
       (*(uint *)(param_1 + 0x668) != SystemReserved1[0x12]._4_4_)) {
      if ((param_2 == '\0') && (*(char *)(param_1 + 0x4b1) == '\0')) {
        if (*(uint *)(param_1 + 0x660) == 0xffffffff) {
          *(uint *)(param_1 + 0x660) = SystemReserved1[0x12]._4_4_;
          lVar3 = 0x5d8;
        }
        else {
          if (*(uint *)(param_1 + 0x664) != 0xffffffff) goto LAB_140003ab5;
          *(uint *)(param_1 + 0x664) = SystemReserved1[0x12]._4_4_;
          lVar3 = 0x618;
        }
        *(longlong *)(param_1 + 0x4a8) = *(longlong *)(param_1 + 0x4a8) + 1;
        *(longlong *)(param_1 + 0x470) = lVar3 + param_1;
        uVar4 = 0;
        *(byte *)(param_1 + 0x44c) = param_3 != '\0' | *(byte *)(param_1 + 0x44c) & 0xfe;
      }
      else {
        if (*(uint *)(param_1 + 0x668) != 0xffffffff) goto LAB_140003ab5;
        *(byte *)(param_1 + 0x44c) = *(byte *)(param_1 + 0x44c) | 2;
        *(longlong *)(param_1 + 0x4a0) = *(longlong *)(param_1 + 0x4a0) + 1;
        *(uint *)(param_1 + 0x668) = uVar1;
        uVar4 = *(undefined8 *)(param_1 + 0x658);
        *(undefined8 *)(param_1 + 0x470) = uVar4;
      }
      *(int *)(param_1 + 0x48c) = *(int *)(param_1 + 0x48c) + 1;
      return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);
    }
  }
LAB_140003ab5:
  return uVar2 & 0xffffffffffffff00;
}



===== OutPollQueue @ 140003ad0 =====

void OutPollQueue(longlong param_1,char param_2)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 uVar3;
  
  if (param_2 == '\0') {
    if (*(int *)(param_1 + 200) == 0) {
      return;
    }
    uVar3 = PkIsOutgoingRingFull((longlong *)(param_1 + 0x40),*(int *)(param_1 + 200));
    if ((char)uVar3 != '\0') {
      return;
    }
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x100);
  if (*(int *)(param_1 + 0x108) == 2) {
    OutpEnqueuePollingDpc(param_1);
    cVar2 = KeCancelTimer(param_1 + 0x348);
    if (cVar2 != '\0') {
      *(int *)(param_1 + 0x408) = *(int *)(param_1 + 0x408) + -1;
    }
  }
  KeReleaseSpinLock(param_1 + 0x100,uVar1);
  return;
}



===== __report_gsfailure @ 140003b80 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 140003b8d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x000140003b8d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== KmclCalibrateTsc @ 140003ba0 =====

ulonglong KmclCalibrateTsc(void)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined1 uVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  longlong lVar8;
  longlong local_res8;
  
  uVar7 = 0;
  local_res8 = 0;
  uVar4 = KfRaiseIrql(2);
  lVar5 = KeQueryPerformanceCounter(&local_res8);
  uVar1 = rdtsc();
  lVar8 = lVar5;
  do {
    lVar6 = KeQueryPerformanceCounter(0);
    uVar3 = uVar7 + 1;
    if (lVar6 == lVar8) {
      uVar3 = uVar7;
    }
    uVar7 = uVar3;
    lVar8 = lVar6;
  } while (uVar7 < 10);
  uVar2 = rdtsc();
  KeLowerIrql(CONCAT31((int3)(uVar7 >> 8),uVar4));
  return (((CONCAT44((int)((ulonglong)lVar6 >> 0x20),(int)uVar2) | uVar2 & 0xffffffff00000000) -
          (CONCAT44((int)((ulonglong)lVar5 >> 0x20),(int)uVar1) | uVar1 & 0xffffffff00000000)) *
         local_res8) / (ulonglong)(lVar6 - lVar5);
}



===== KmclChannelCleanupParentDevice @ 140003c68 =====

void KmclChannelCleanupParentDevice(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x8b0) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(param_1 + 0x8b0) = 0;
  }
  if (*(longlong *)(param_1 + 0xae8) != 0) {
    IoFreeWorkItem();
    *(undefined8 *)(param_1 + 0xae8) = 0;
  }
  if (*(longlong *)(param_1 + 0xcc0) != 0) {
    ObfDereferenceObject();
    *(undefined8 *)(param_1 + 0xcc0) = 0;
  }
  return;
}



===== KmclInitializeChannel @ 140003ce0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 KmclInitializeChannel(void *param_1,undefined8 param_2,char param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  uint uVar9;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined8 local_48;
  undefined4 local_40;
  undefined2 local_38;
  ulonglong local_28 [4];
  
  local_28[2] = __security_cookie ^ (ulonglong)auStack_68;
  memset(param_1,0,0xd80);
  uVar8 = 0;
  *(undefined4 *)((longlong)param_1 + 0x8f0) = 1;
  *(undefined8 *)((longlong)param_1 + 0x8f8) = 0;
  *(undefined4 *)((longlong)param_1 + 0x900) = 0;
  KeInitializeEvent((longlong)param_1 + 0x908,1,0);
  *(undefined4 *)((longlong)param_1 + 0xc68) = 1;
  *(undefined8 *)((longlong)param_1 + 0xc70) = 0;
  *(undefined4 *)((longlong)param_1 + 0xc78) = 0;
  KeInitializeEvent((longlong)param_1 + 0xc80,1,0);
  lVar3 = (longlong)param_1 + 0xcb0;
  *(longlong *)((longlong)param_1 + 0xcb8) = lVar3;
  *(longlong *)lVar3 = lVar3;
  lVar3 = (longlong)param_1 + 0xca0;
  *(longlong *)((longlong)param_1 + 0xca8) = lVar3;
  *(longlong *)lVar3 = lVar3;
  lVar3 = (longlong)param_1 + 0xb58;
  *(longlong *)((longlong)param_1 + 0xb60) = lVar3;
  *(longlong *)lVar3 = lVar3;
  lVar3 = (longlong)param_1 + 0xb68;
  *(longlong *)((longlong)param_1 + 0xb70) = lVar3;
  *(longlong *)lVar3 = lVar3;
  *(void **)param_1 = param_1;
  *(undefined1 *)((longlong)param_1 + 0x4b0) = 1;
  *(uint *)((longlong)param_1 + 0x574) = (-(uint)(param_3 != '\0') & 0x101) - 1;
  VmbChannelSetAllowableDpcCpuUsage((longlong)param_1,0x1e);
  *(char *)((longlong)param_1 + 0x6c0) = param_3;
  if (param_3 == '\0') {
    *(byte *)((longlong)param_1 + 0x928) = *(byte *)((longlong)param_1 + 0x928) | 1;
  }
  *(undefined4 *)((longlong)param_1 + 0x7b0) = 0xffffffff;
  *(code **)((longlong)param_1 + 0x7f8) = KmclpDefaultChannelOpenedEx;
  *(undefined1 *)((longlong)param_1 + 0x7e8) = 0;
  *(code **)((longlong)param_1 + 0x800) = _guard_check_icall;
  *(code **)((longlong)param_1 + 0x808) = _guard_check_icall;
  *(code **)((longlong)param_1 + 0x810) = _guard_check_icall;
  *(code **)((longlong)param_1 + 0x818) = _guard_check_icall;
  *(code **)((longlong)param_1 + 0x858) = _guard_check_icall;
  *(undefined8 *)((longlong)param_1 + 0xcc0) = param_2;
  ObfReferenceObject(param_2);
  lVar3 = IoAllocateWorkItem(*(undefined8 *)((longlong)param_1 + 0xcc0));
  *(longlong *)((longlong)param_1 + 0x8b0) = lVar3;
  if (lVar3 != 0) {
    lVar3 = IoAllocateWorkItem(*(undefined8 *)((longlong)param_1 + 0xcc0));
    *(longlong *)((longlong)param_1 + 0xae8) = lVar3;
    if (lVar3 != 0) {
      if (param_3 == '\0') {
        local_28[0] = 0;
        local_28[1] = 0;
        HviGetHypervisorFeatures(local_28);
        if ((local_28[0] & 0x40000000000000) != 0) {
          *(undefined2 *)((longlong)param_1 + 0xb50) = 0x101;
        }
        if (*(char *)((longlong)param_1 + 0xb51) != '\0') {
          lVar3 = IoAllocateWorkItem(*(undefined8 *)((longlong)param_1 + 0xcc0));
          *(longlong *)((longlong)param_1 + 0xb78) = lVar3;
          if (lVar3 == 0) goto LAB_140003f0a;
          local_38 = 0;
          uVar9 = ExDefaultNonPagedPoolType | 0x200;
          local_40 = 0x636d6b56;
          *(undefined4 *)((longlong)param_1 + 0x7b4) = 0;
          *(undefined4 *)((longlong)param_1 + 0x7b8) = 0x80000;
          *(undefined4 *)((longlong)param_1 + 0x7bc) = 0x2000000;
          local_48 = 0x20;
          ExInitializeNPagedLookasideList((longlong)param_1 + 0xb80,0,0,uVar9);
          *(undefined1 *)((longlong)param_1 + 0xc00) = 1;
        }
      }
      ExAcquireFastMutex(&KmclChannelListLock);
      puVar7 = auStack_68;
      puVar6 = &KmclChannelList;
      puVar4 = (undefined8 *)((longlong)param_1 + 0x860);
      puVar5 = DAT_140016288;
      if ((undefined8 *)*DAT_140016288 != &KmclChannelList) {
        puVar5 = (undefined8 *)0x3;
        pcVar1 = (code *)swi(0x29);
        puVar4 = (undefined8 *)(*pcVar1)();
        puVar7 = auStack_60;
      }
      puVar4[1] = puVar5;
      *puVar4 = puVar6;
      *puVar5 = puVar4;
      *(undefined8 *)(puVar7 + -8) = 0x140003fca;
      DAT_140016288 = puVar4;
      ExReleaseFastMutex(&KmclChannelListLock);
      uVar2 = KmclPerformanceCounterFrequency;
      *(undefined8 *)((longlong)param_1 + 0x250) = 0xffffffffffffffff;
      *(undefined8 *)((longlong)param_1 + 0x260) = uVar2;
      *(undefined8 *)((longlong)param_1 + 0x248) = 0;
      goto LAB_140003fec;
    }
  }
LAB_140003f0a:
  uVar8 = 0xc000009a;
  VmbChannelCleanup((longlong)param_1);
  puVar7 = auStack_68;
LAB_140003fec:
  *(undefined8 *)(puVar7 + -8) = 0x140003ffb;
  return uVar8;
}



===== _guard_check_icall @ 140004020 =====

void _guard_check_icall(void)

{
  return;
}



===== KmclpDefaultChannelOpenedEx @ 140004030 =====

undefined8 KmclpDefaultChannelOpenedEx(void)

{
  return 0;
}



===== VmbChannelAllocate @ 140004040 =====

ulonglong VmbChannelAllocate(undefined8 param_1,char param_2,undefined8 *param_3)

{
  void *pvVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
                    /* 0x4040  3  VmbChannelAllocate */
  pvVar1 = (void *)ExAllocatePool2(0x40,0xd80,0x636d6b56);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar3 = KmclInitializeChannel(pvVar1,param_1,param_2);
    uVar2 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      ExFreePoolWithTag(pvVar1,0x636d6b56);
    }
    else {
      *(byte *)((longlong)pvVar1 + 0x928) = *(byte *)((longlong)pvVar1 + 0x928) | 8;
      uVar2 = 0;
      *param_3 = pvVar1;
    }
  }
  return uVar2;
}



===== VmbChannelCleanup @ 1400040e0 =====

void VmbChannelCleanup(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  
                    /* 0x40e0  6  VmbChannelCleanup */
  if (*(int *)(param_1 + 0x898) != 0xc) {
    lVar2 = *(longlong *)(param_1 + 0xc58);
    if (lVar2 != 0) {
      KmclLockChannel(lVar2);
      ExAcquireFastMutexUnsafe(lVar2 + 0xc68);
      plVar1 = (longlong *)(param_1 + 0xcb0);
      lVar3 = *plVar1;
      if ((*(longlong **)(lVar3 + 8) != plVar1) ||
         (plVar4 = *(longlong **)(param_1 + 0xcb8), (longlong *)*plVar4 != plVar1))
      goto LAB_14000438d;
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      ExReleaseFastMutexUnsafe(lVar2 + 0xc68);
      KmclUnlockChannel(lVar2);
      *(undefined8 *)(param_1 + 0xc58) = 0;
    }
    plVar1 = (longlong *)(param_1 + 0xca0);
    if ((longlong *)*plVar1 != plVar1) {
      KeEnterCriticalRegion();
      ExAcquireFastMutexUnsafe(param_1 + 0xc68);
      while (plVar4 = (longlong *)*plVar1, plVar4 != plVar1) {
        if (((longlong *)plVar4[1] != plVar1) ||
           (lVar2 = *plVar4, *(longlong **)(lVar2 + 8) != plVar4)) goto LAB_14000438d;
        *plVar1 = lVar2;
        *(longlong **)(lVar2 + 8) = plVar1;
        plVar4[1] = (longlong)plVar4;
        *plVar4 = (longlong)plVar4;
        plVar4[-0xb] = 0;
      }
      ExReleaseFastMutexUnsafe(param_1 + 0xc68);
      KeLeaveCriticalRegion();
    }
    if (*(longlong *)(param_1 + 0x890) != 0) {
      RtlFreeUnicodeString(param_1 + 0x888);
    }
    plVar1 = (longlong *)(param_1 + 0x860);
    if (*plVar1 != 0) {
      ExAcquireFastMutex(&KmclChannelListLock);
      lVar2 = *plVar1;
      if ((*(longlong **)(lVar2 + 8) != plVar1) ||
         (plVar4 = *(longlong **)(param_1 + 0x868), (longlong *)*plVar4 != plVar1)) {
LAB_14000438d:
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        pcVar5 = (code *)swi(3);
        (*pcVar5)();
        return;
      }
      *plVar4 = lVar2;
      *(longlong **)(lVar2 + 8) = plVar4;
      ExReleaseFastMutex(&KmclChannelListLock);
    }
    if (*(longlong *)(param_1 + 0xb78) != 0) {
      IoFreeWorkItem();
      *(undefined8 *)(param_1 + 0xb78) = 0;
    }
    KmclpFreeAllBounceBlocks(param_1);
    if (*(char *)(param_1 + 0xc00) != '\0') {
      ExDeleteNPagedLookasideList(param_1 + 0xb80);
      *(undefined1 *)(param_1 + 0xc00) = 0;
    }
    if ((*(char *)(param_1 + 0x6c1) == '\0') && ((*(byte *)(param_1 + 0x928) & 0x20) != 0)) {
      OutUninitializeQueue(param_1);
    }
    if (*(char *)(param_1 + 0x8e8) != '\0') {
      *(undefined1 *)(param_1 + 0x8e9) = 1;
      KeSetEvent(param_1 + 0x8b8,0,0);
      KeWaitForSingleObject(param_1 + 0x8d0,0,0,0,0);
      *(undefined1 *)(param_1 + 0x8e8) = 0;
    }
    if (*(longlong *)(param_1 + 0xaa0) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(param_1 + 0xaa0) = 0;
    }
    if (*(longlong *)(param_1 + 0xaa8) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(param_1 + 0xaa8) = 0;
    }
    KmclChannelCleanupParentDevice(param_1);
    if ((*(byte *)(param_1 + 0x928) & 8) != 0) {
      ExFreePoolWithTag(param_1,0x636d6b56);
    }
  }
  return;
}



===== VmbChannelInitSetBounceBufferSizes @ 1400043a0 =====

undefined8
VmbChannelInitSetBounceBufferSizes(longlong param_1,uint param_2,uint param_3,uint param_4)

{
                    /* 0x43a0  30  VmbChannelInitSetBounceBufferSizes */
  if ((*(char *)(param_1 + 0x6c0) != '\0') || (*(int *)(param_1 + 0x898) != 0)) {
    return 0xc00000ef;
  }
  if (param_2 != 0) {
    if ((param_2 < 0x40000) || ((param_2 & 0xfff) != 0)) {
      return 0xc00000f0;
    }
    *(uint *)(param_1 + 0x7b4) = param_2;
  }
  if (param_3 != 0) {
    if ((param_3 < 0x40000) || ((param_3 & 0xfff) != 0)) {
      return 0xc00000f1;
    }
    *(uint *)(param_1 + 0x7b8) = param_3;
  }
  if (param_4 != 0) {
    if ((param_4 < 0x40000) || ((param_4 & 0xfff) != 0)) {
      return 0xc00000f2;
    }
    *(uint *)(param_1 + 0x7bc) = param_4;
  }
  return 0;
}



===== VmbChannelInitSetFlags @ 140004430 =====

undefined8 VmbChannelInitSetFlags(longlong param_1,uint param_2)

{
                    /* 0x4430  32  VmbChannelInitSetFlags */
  if (*(int *)(param_1 + 0x898) != 0) {
    return 0xc00000ef;
  }
  if ((param_2 & 0xfffffffc) != 0) {
    return 0xc00000f0;
  }
  if ((param_2 & 1) != 0) {
    *(undefined1 *)(param_1 + 0x700) = 1;
  }
  if ((param_2 & 2) != 0) {
    *(undefined1 *)(param_1 + 0x7c2) = 1;
  }
  return 0;
}



===== VmbChannelInitSetMaximumPacketSize @ 140004480 =====

undefined8 VmbChannelInitSetMaximumPacketSize(longlong param_1,int param_2)

{
                    /* 0x4480  37  VmbChannelInitSetMaximumPacketSize */
  if (*(int *)(param_1 + 0x898) != 0) {
    return 0xc00000ef;
  }
  if (param_2 == 0) {
    return 0xc00000f0;
  }
  *(uint *)(param_1 + 0x6c8) = param_2 + 7U & 0xfffffff8;
  return 0;
}



===== VmbChannelInitSetPrimaryChannel @ 1400044c0 =====

undefined8 VmbChannelInitSetPrimaryChannel(longlong param_1,longlong param_2,short param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
                    /* 0x44c0  38  VmbChannelInitSetPrimaryChannel */
  if (*(int *)(param_2 + 0x898) != 0xc) {
    if (*(int *)(param_1 + 0x898) != 0) {
      return 0xc00000ef;
    }
    if ((((*(char *)(param_1 + 0xc60) != '\0') || (*(char *)(param_1 + 0x7c0) != '\0')) ||
        (*(char *)(param_2 + 0xc60) != '\0')) || ((*(byte *)(param_2 + 0x928) & 4) != 0)) {
      return 0xc00000f0;
    }
    if (param_3 == 0) {
      return 0xc00000f1;
    }
    *(longlong *)(param_1 + 0xc58) = param_2;
    *(undefined1 *)(param_1 + 0xc60) = 1;
    *(short *)(param_1 + 0xcd0) = param_3;
    KmclLockChannel(param_2);
    *(byte *)(param_2 + 0x928) = *(byte *)(param_2 + 0x928) & 0xfd;
    ExAcquireFastMutexUnsafe(param_2 + 0xc68);
    puVar6 = auStack_28;
    lVar4 = param_2 + 0xca0;
    plVar5 = *(longlong **)(param_2 + 0xca8);
    plVar3 = (longlong *)(param_1 + 0xcb0);
    if (*plVar5 != lVar4) {
      lVar4 = 3;
      pcVar1 = (code *)swi(0x29);
      plVar3 = (longlong *)(*pcVar1)();
      puVar6 = auStack_20;
    }
    *plVar3 = lVar4;
    plVar3[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar3;
    *(longlong **)(lVar4 + 8) = plVar3;
    *(undefined8 *)(puVar6 + -8) = 0x1400045b3;
    ExReleaseFastMutexUnsafe(param_2 + 0xc68);
    *(undefined8 *)(puVar6 + -8) = 0x1400045c0;
    KmclUnlockChannel(param_2);
    if (*(char *)(param_1 + 0x6c0) == '\0') {
      uVar2 = *(undefined8 *)(param_2 + 0xac8);
      *(undefined8 *)(param_1 + 0x6ec) = *(undefined8 *)(param_2 + 0xac0);
      *(undefined8 *)(param_1 + 0x6f4) = uVar2;
      uVar7 = *(undefined4 *)(param_2 + 0xab0);
      uVar8 = *(undefined4 *)(param_2 + 0xab4);
      uVar9 = *(undefined4 *)(param_2 + 0xab8);
      uVar10 = *(undefined4 *)(param_2 + 0xabc);
      *(undefined1 *)(param_1 + 0x7c0) = 1;
    }
    else {
      uVar2 = *(undefined8 *)(param_2 + 0x6f4);
      *(undefined8 *)(param_1 + 0x6ec) = *(undefined8 *)(param_2 + 0x6ec);
      *(undefined8 *)(param_1 + 0x6f4) = uVar2;
      uVar7 = *(undefined4 *)(param_2 + 0x6dc);
      uVar8 = *(undefined4 *)(param_2 + 0x6e0);
      uVar9 = *(undefined4 *)(param_2 + 0x6e4);
      uVar10 = *(undefined4 *)(param_2 + 0x6e8);
    }
    *(undefined4 *)(param_1 + 0x6dc) = uVar7;
    *(undefined4 *)(param_1 + 0x6e0) = uVar8;
    *(undefined4 *)(param_1 + 0x6e4) = uVar9;
    *(undefined4 *)(param_1 + 0x6e8) = uVar10;
  }
  return 0;
}



===== VmbChannelInitSetProcessPacketCallbacks @ 140004630 =====

undefined8
VmbChannelInitSetProcessPacketCallbacks(longlong param_1,undefined8 param_2,undefined8 param_3)

{
                    /* 0x4630  39  VmbChannelInitSetProcessPacketCallbacks */
  if ((*(int *)(param_1 + 0x898) == 0) || (*(int *)(param_1 + 0x898) == 0xc)) {
    *(undefined1 *)(param_1 + 0x7c8) = 0;
    *(undefined8 *)(param_1 + 2000) = param_2;
    *(undefined8 *)(param_1 + 0x7d8) = param_3;
    return 0;
  }
  return 0xc00000ef;
}



===== VmbChannelInitSetProcessPacketCallbacksEx @ 140004670 =====

undefined8
VmbChannelInitSetProcessPacketCallbacksEx
          (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
                    /* 0x4670  40  VmbChannelInitSetProcessPacketCallbacksEx */
  if ((*(int *)(param_1 + 0x898) == 0) || (*(int *)(param_1 + 0x898) == 0xc)) {
    *(undefined1 *)(param_1 + 0x7c8) = 1;
    *(undefined8 *)(param_1 + 0x7e0) = param_2;
    *(undefined8 *)(param_1 + 2000) = param_3;
    *(undefined8 *)(param_1 + 0x7d8) = param_4;
    return 0;
  }
  return 0xc00000ef;
}



===== VmbChannelInitSetStateChangeCallbacks @ 1400046b0 =====

undefined8 VmbChannelInitSetStateChangeCallbacks(longlong param_1,int *param_2)

{
  code *pcVar1;
  
                    /* 0x46b0  42  VmbChannelInitSetStateChangeCallbacks */
  if ((*(int *)(param_1 + 0x898) != 0) && (*(int *)(param_1 + 0x898) != 0xc)) {
    return 0xc00000ef;
  }
  if (*param_2 == 5) {
    if (param_2[1] != 0x38) {
      return 0xc00000f0;
    }
    *(undefined1 *)(param_1 + 0x7e8) = 1;
    *(undefined8 *)(param_1 + 0x7f8) = *(undefined8 *)(param_2 + 2);
    pcVar1 = KmclpDefaultChannelOpenedEx;
    if (*(code **)(param_2 + 4) != (code *)0x0) {
      pcVar1 = *(code **)(param_2 + 4);
    }
    *(code **)(param_1 + 0x800) = pcVar1;
    pcVar1 = _guard_check_icall;
    if (*(code **)(param_2 + 6) != (code *)0x0) {
      pcVar1 = *(code **)(param_2 + 6);
    }
    *(code **)(param_1 + 0x808) = pcVar1;
    pcVar1 = _guard_check_icall;
    if (*(code **)(param_2 + 10) != (code *)0x0) {
      pcVar1 = *(code **)(param_2 + 10);
    }
    *(code **)(param_1 + 0x818) = pcVar1;
    pcVar1 = _guard_check_icall;
    if (*(code **)(param_2 + 0xc) != (code *)0x0) {
      pcVar1 = *(code **)(param_2 + 0xc);
    }
    *(code **)(param_1 + 0x820) = pcVar1;
    pcVar1 = _guard_check_icall;
    if (*(code **)(param_2 + 8) != (code *)0x0) {
      pcVar1 = *(code **)(param_2 + 8);
    }
    *(code **)(param_1 + 0x810) = pcVar1;
  }
  else {
    if (*param_2 != 1) {
      return 0xc00000f0;
    }
    if (param_2[1] != 0x30) {
      return 0xc00000f0;
    }
    if (*(longlong *)(param_2 + 4) != 0) {
      *(longlong *)(param_1 + 0x800) = *(longlong *)(param_2 + 4);
    }
    if (*(longlong *)(param_2 + 2) != 0) {
      *(longlong *)(param_1 + 0x7f8) = *(longlong *)(param_2 + 2);
    }
    if (*(longlong *)(param_2 + 8) != 0) {
      *(longlong *)(param_1 + 0x810) = *(longlong *)(param_2 + 8);
    }
    if (*(longlong *)(param_2 + 10) != 0) {
      *(longlong *)(param_1 + 0x818) = *(longlong *)(param_2 + 10);
    }
    if (*(longlong *)(param_2 + 6) != 0) {
      *(longlong *)(param_1 + 0x808) = *(longlong *)(param_2 + 6);
    }
  }
  return 0;
}



===== VmbClientChannelInitSetRingBufferPageCount @ 1400047e0 =====

undefined8
VmbClientChannelInitSetRingBufferPageCount(longlong param_1,undefined4 param_2,undefined4 param_3)

{
                    /* 0x47e0  69  VmbClientChannelInitSetRingBufferPageCount */
  if ((*(char *)(param_1 + 0x6c0) == '\0') && (*(int *)(param_1 + 0x898) == 0)) {
    *(undefined4 *)(param_1 + 0x7a8) = param_2;
    *(undefined4 *)(param_1 + 0x7ac) = param_3;
    return 0;
  }
  return 0xc00000ef;
}



===== VmbClientChannelInitSetTargetPnp @ 140004810 =====

undefined8
VmbClientChannelInitSetTargetPnp
          (longlong param_1,undefined8 *param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
                    /* 0x4810  71  VmbClientChannelInitSetTargetPnp */
  if ((*(char *)(param_1 + 0x6c0) != '\0') || (*(int *)(param_1 + 0x898) != 0)) {
    return 0xc00000ef;
  }
  if (*(char *)(param_1 + 0x7c1) != '\0') {
    return 0xc00000f0;
  }
  uVar1 = param_2[1];
  *(undefined8 *)(param_1 + 0x6dc) = *param_2;
  *(undefined8 *)(param_1 + 0x6e4) = uVar1;
  if (param_3 != (undefined8 *)0x0) {
    uVar1 = param_3[1];
    *(undefined8 *)(param_1 + 0x6ec) = *param_3;
    *(undefined8 *)(param_1 + 0x6f4) = uVar1;
  }
  if (param_4 != 0) {
    *(longlong *)(param_1 + 0x858) = param_4;
  }
  *(undefined1 *)(param_1 + 0x7c0) = 1;
  return 0;
}



===== VmbClientChannelInitSetTargetProcessorIndex @ 140004870 =====

undefined8 VmbClientChannelInitSetTargetProcessorIndex(longlong param_1,undefined4 param_2)

{
                    /* 0x4870  72  VmbClientChannelInitSetTargetProcessorIndex */
  if ((*(char *)(param_1 + 0x6c0) == '\0') && (*(int *)(param_1 + 0x898) == 0)) {
    *(undefined4 *)(param_1 + 0x7b0) = param_2;
    return 0;
  }
  return 0xc00000ef;
}



===== VmbSizeofChannel @ 1400048a0 =====

undefined8 VmbSizeofChannel(void)

{
                    /* 0x48a0  87  VmbSizeofChannel */
  return 0xd80;
}



===== Feature_3130672440__private_IsEnabledDeviceUsageNoInline @ 1400048b0 =====

ulonglong Feature_3130672440__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  undefined4 *local_res8;
  
  local_res8 = (undefined4 *)(ulonglong)Feature_3130672440__private_featureState;
  if ((Feature_3130672440__private_featureState & 0x10) == 0) {
    uVar1 = Feature_3130672440__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_3130672440__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_3130672440__private_IsEnabledFallback @ 1400048e8 =====

void Feature_3130672440__private_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2);
  return;
}



===== InClientPollQueue @ 140004900 =====

undefined1 InClientPollQueue(longlong *param_1,ulonglong param_2)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  undefined1 uVar6;
  int iVar7;
  undefined8 uVar8;
  
  uVar6 = 0;
  bVar4 = false;
  bVar3 = false;
  bVar2 = false;
  cVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
  iVar7 = (int)param_1[0x89];
  if (iVar7 == 1) {
    *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) | 1;
    goto LAB_1400049a9;
  }
  if (iVar7 == 3) {
    bVar2 = true;
    if (*(char *)((longlong)param_1 + 0x4b1) != '\0') {
      *(undefined1 *)((longlong)param_1 + 0x4b1) = 0;
      bVar4 = true;
    }
  }
  else if (iVar7 == 4) {
    uVar1 = *(uint *)((longlong)param_1 + 0x84);
    param_2 = (ulonglong)uVar1;
    bVar2 = uVar1 != *(uint *)param_1[0xb];
    if (uVar1 == *(uint *)param_1[0xb]) goto LAB_1400049a9;
  }
  else {
    if (iVar7 != 7) goto LAB_1400049a9;
    bVar2 = true;
  }
  bVar3 = bVar4;
  *(undefined4 *)(param_1 + 0x89) = 1;
  param_1[0x8d] = (longlong)SystemReserved1[0xf];
LAB_1400049a9:
  uVar8 = CONCAT71((int7)(param_2 >> 8),cVar5);
  KeReleaseSpinLock(param_1 + 0x88,uVar8);
  if (bVar2) {
    iVar7 = InpFillAndProcessQueue
                      (param_1,CONCAT71((int7)((ulonglong)uVar8 >> 8),cVar5),
                       (undefined4 *)(ulonglong)((-(uint)(cVar5 != '\0') & 0xffffff56) + 200));
    if (bVar3) {
      *(undefined1 *)((longlong)param_1 + 0x4b1) = 1;
    }
    InpTransitionRunningQueue(param_1,'\0',iVar7);
    if ((iVar7 == 1) || (iVar7 - 5U < 3)) {
      uVar6 = 1;
    }
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}



===== InCloseChannel @ 140004a34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void InCloseChannel(longlong *param_1)

{
  InpReleasePacketAllocationResources((longlong)param_1);
  if (param_1[0xb2] != 0) {
    ExFreePoolWithTag(param_1[0xb2],0x636d6b56);
    param_1[0xb2] = 0;
  }
  if (param_1[0xcb] != 0) {
    (**(code **)(*param_1 + 0x9f8))(*(undefined8 *)(*param_1 + 0x940));
    param_1[0xcb] = 0;
  }
  return;
}



===== InDereferencePacketProfiler @ 140004aa0 =====

void InDereferencePacketProfiler(uint *param_1)

{
  uint *puVar1;
  
  ExAcquireFastMutex(&KmclProfilerListLock);
  puVar1 = param_1 + 1;
  *puVar1 = *puVar1 - 1;
  if (*puVar1 == 0) {
    InpFreePacketProfilerLocked(param_1);
  }
  ExReleaseFastMutex(&KmclProfilerListLock);
  return;
}



===== InInitializeQueue @ 140004aec =====

undefined8 InInitializeQueue(longlong *param_1)

{
  longlong *plVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  int iVar8;
  
  lVar4 = *param_1;
  *(undefined4 *)(param_1 + 0x89) = 0;
  KeInitializeDpc(param_1 + 0xbb,InpProcessingDpcRoutine,param_1);
  KeInitializeDpc(param_1 + 0xc3,InpProcessingDpcRoutine,param_1);
  *(undefined4 *)(param_1 + 0xcc) = 0xffffffff;
  *(undefined4 *)((longlong)param_1 + 0x664) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xcd) = 0xffffffff;
  plVar1 = param_1 + 0xa0;
  param_1[0xa1] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  plVar1 = param_1 + 0x8a;
  param_1[0x8b] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  plVar1 = param_1 + 0xa2;
  param_1[0xa3] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  *(undefined4 *)(param_1 + 0xae) = *(undefined4 *)(lVar4 + 0x6d4);
  *(undefined1 *)((longlong)param_1 + 0x4b3) = *(undefined1 *)(lVar4 + 0x706);
  uVar3 = *(undefined4 *)(lVar4 + 0x6fc);
  *(undefined4 *)((longlong)param_1 + 0x584) = 0;
  param_1[0xb4] = 0;
  *(undefined4 *)((longlong)param_1 + 0x52c) = uVar3;
  lVar5 = *param_1;
  if (*(char *)(lVar5 + 0x7c8) == '\0') {
    if (*(longlong *)(lVar5 + 2000) == 0) {
      *(code **)(lVar5 + 2000) = InpChannelProcessPacketNoOp;
    }
    lVar5 = *param_1;
    lVar6 = *(longlong *)(lVar5 + 0x7d8);
  }
  else {
    if (*(longlong *)(lVar5 + 2000) == 0) {
      *(code **)(lVar5 + 2000) = InpChannelProcessPacketExNoOp;
    }
    lVar5 = *param_1;
    lVar6 = *(longlong *)(lVar5 + 0x7d8);
  }
  if (lVar6 == 0) {
    *(code **)(lVar5 + 0x7d8) = _guard_check_icall;
  }
  iVar7 = *(int *)(lVar4 + 0x6d0);
  iVar8 = *(int *)(lVar4 + 0x6c8);
  if (iVar7 == 0) {
    iVar7 = iVar8 + 0xb0;
  }
  else {
    iVar2 = (*(int *)(lVar4 + 0x6cc) + 0xfffU >> 0xc) + iVar7 * 2;
    iVar7 = (iVar8 + 0xd7 + (iVar7 + iVar2) * 8 & 0xfffffff0U) + (iVar2 + iVar7 * 8) * 8;
  }
  iVar7 = (iVar7 + 0xfU & 0xfffffff0) + (int)param_1[0xae];
  if (*(char *)((longlong)param_1 + 0x4b3) != '\0') {
    iVar8 = *(int *)(lVar4 + 0x798);
    iVar7 = iVar7 + iVar8;
  }
  *(int *)((longlong)param_1 + 0x5ac) = iVar8;
  *(int *)(param_1 + 0xb5) = iVar7;
  return 0;
}



===== InLookasideAllocate @ 140004cb0 =====

void InLookasideAllocate(undefined8 param_1,undefined4 param_2)

{
  longlong lVar1;
  
  lVar1 = ExAllocatePoolWithTag();
  if (lVar1 != 0) {
    *(undefined4 *)(lVar1 + 8) = param_2;
  }
  return;
}



===== InMapPacketMdl @ 140004cdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 InMapPacketMdl(longlong *param_1,longlong param_2,ulonglong param_3)

{
  undefined8 *puVar1;
  uint uVar2;
  byte bVar3;
  undefined8 uVar4;
  longlong lVar5;
  int iVar6;
  
  if (*(char *)(*param_1 + 0x6c0) == '\0') {
    return 0xc0000184;
  }
  uVar2 = *(uint *)(param_2 + 0x4c);
  if (uVar2 == 0) {
LAB_140004dca:
    uVar4 = 0;
  }
  else {
    bVar3 = KeGetCurrentIrql();
    if (bVar3 <= *(byte *)(param_1 + 0xb3)) {
      iVar6 = 1;
      if ((param_3 & 1) == 0) {
        iVar6 = (-(uint)((*(byte *)(param_2 + 0x10) & 0x10) != 0) & 2) + 2;
      }
      *(int *)(param_2 + 0x44) = iVar6;
      lVar5 = (ulonglong)*(uint *)(param_2 + 0x38) + 0xa0 + param_2;
      *(longlong *)(param_1[0xb2] + 8) = param_2;
      puVar1 = (undefined8 *)(lVar5 + (ulonglong)uVar2 * 8);
      uVar4 = (**(code **)(*param_1 + 0xa20))
                        (*(undefined8 *)(*param_1 + 0x940),param_1[0xb2] + 0x10,
                         InpMapPacketMdlComplete,iVar6,lVar5,puVar1,uVar2);
      if ((int)uVar4 == 0) {
        InpPostProcessMappedMdl(param_2,puVar1,uVar2);
        goto LAB_140004dca;
      }
      if ((int)uVar4 != -0x3fffff28) {
        return uVar4;
      }
    }
    uVar4 = 0xc0000148;
  }
  return uVar4;
}



===== InMarkPacketShortLifetime @ 140004de8 =====

void InMarkPacketShortLifetime(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  
  LOCK();
  cVar1 = *(char *)(param_2 + 0x11);
  *(char *)(param_2 + 0x11) = '\x01';
  UNLOCK();
  if (cVar1 == '\0') {
    if (((*(int *)(param_1 + 0x448) == 1) && (*(void **)(param_1 + 0x468) == SystemReserved1[0xf]))
       && ((iVar3 = KeIsExecutingDpc(), iVar3 == 0 || (*(char *)(param_1 + 0x580) != '\0')))) {
      *(int *)(param_1 + 0x528) = *(int *)(param_1 + 0x528) + 1;
      return;
    }
    uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x440);
    iVar3 = *(int *)(param_1 + 0x488) + 1;
    *(int *)(param_1 + 0x488) = iVar3;
    if ((*(int *)(param_1 + 0x448) == 4) &&
       (*(int *)(param_1 + 0x528) + iVar3 == *(int *)(param_1 + 0x52c))) {
      *(undefined4 *)(*(longlong *)(param_1 + 0x58) + 8) = 1;
    }
    KeReleaseSpinLock(param_1 + 0x440,uVar2);
  }
  return;
}



===== InOpenChannel @ 140004eb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong InOpenChannel(longlong *param_1)

{
  longlong lVar1;
  uint uVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 local_res8;
  
  lVar1 = *param_1;
  local_res8 = 0;
  if (*(char *)(lVar1 + 0x6c0) != '\0') {
    uVar2 = (**(code **)(lVar1 + 0xa18))(*(undefined8 *)(lVar1 + 0x940),&local_res8);
    uVar5 = (ulonglong)uVar2;
    if ((int)uVar2 < 0) goto LAB_140004f27;
    puVar3 = (undefined8 *)ExAllocatePool2(0x40,(int)local_res8 + 0x10,0x636d6b56);
    param_1[0xb2] = (longlong)puVar3;
    if (puVar3 == (undefined8 *)0x0) {
      uVar5 = 0xc000009a;
      goto LAB_140004f27;
    }
    *puVar3 = param_1;
    *(undefined1 *)(param_1 + 0xb3) = local_res8._4_1_;
  }
  uVar2 = (**(code **)(lVar1 + 0x9f0))
                    (*(undefined8 *)(lVar1 + 0x940),*(undefined8 *)(*param_1 + 0xcc0),param_1 + 0xcb
                    );
  uVar5 = (ulonglong)uVar2;
  if (-1 < (int)uVar2) {
    uVar4 = InpReacquirePacketAllocationResources(param_1,*(uint *)(param_1 + 0xb5));
    uVar5 = uVar4 & 0xffffffff;
    if (-1 < (int)uVar4) {
      return 0;
    }
  }
LAB_140004f27:
  InCloseChannel(param_1);
  return uVar5;
}



===== InPauseQueue @ 140004f98 =====

void InPauseQueue(longlong *param_1)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  undefined1 local_res8 [8];
  
  local_res8[0] = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
  if ((int)param_1[0x89] == 8) {
    uVar4 = InpCancelMdlMapLocked(param_1);
    if ((char)uVar4 != '\0') {
      *(undefined4 *)(param_1 + 0x89) = 7;
    }
  }
  if (((int)param_1[0x89] == 1) || ((int)param_1[0x89] == 8)) {
    InpWaitForQueueStopEvent((longlong)param_1,local_res8);
    if (param_1[0x97] != 0) {
      KeSetEvent(param_1[0x97],0,0);
      param_1[0x97] = 0;
    }
  }
  if (*(int *)((longlong)param_1 + 0x524) ==
      (int)param_1[0x90] + *(int *)((longlong)param_1 + 0x47c)) {
    *(undefined4 *)(param_1 + 0x89) = 0;
  }
  else {
    lVar2 = *param_1;
    *(undefined4 *)(param_1 + 0x89) = 9;
    LOCK();
    *(int *)(lVar2 + 0x8a8) = *(int *)(lVar2 + 0x8a8) + 1;
    UNLOCK();
    LOCK();
    piVar1 = (int *)(lVar2 + 0xce0);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    uVar7 = iVar3 + 1;
    uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      iVar3 = (int)((ulonglong)((longlong)(int)uVar7 * -0x2aaaaaab) >> 0x20);
      iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
    }
    else {
      iVar3 = (uVar7 / 0x18) * -0x18;
    }
    lVar6 = (longlong)(int)(uVar7 + iVar3);
    *(undefined1 *)(lVar2 + 0xce4 + lVar6 * 6) = *(undefined1 *)(lVar2 + 0x898);
    *(undefined1 *)(lVar2 + 0xce5 + lVar6 * 6) = *(undefined1 *)(lVar2 + 0x89c);
    *(short *)(lVar2 + 0xce6 + lVar6 * 6) = (short)*(undefined4 *)(lVar2 + 0x8a8);
    *(undefined2 *)(lVar2 + 0xce8 + lVar6 * 6) = 0xdda;
  }
  KeReleaseSpinLock(param_1 + 0x88,local_res8[0]);
  return;
}



===== InPurgeQueue @ 140005104 =====

void InPurgeQueue(longlong *param_1)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  code *pcVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar7 = auStack_28;
  plVar1 = param_1 + 0xa0;
  do {
    plVar4 = (longlong *)*plVar1;
    if (plVar4 == plVar1) {
LAB_14000517a:
      if (*(char *)((longlong)param_1 + 0x4b3) != '\0') {
        *(undefined8 *)(puVar7 + -8) = 0x14000518d;
        InpProcessCompletedDeferredPackets(param_1,'\0');
      }
      return;
    }
    if (((longlong *)plVar4[1] != plVar1) ||
       (lVar5 = *plVar4, (longlong *)*(longlong *)(lVar5 + 8) != plVar4)) {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      puVar7 = auStack_20;
      goto LAB_14000517a;
    }
    *plVar1 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar1;
    if (plVar4[3] != 0) {
      InpUnmapPacketMdl(param_1,(longlong)(plVar4 + -3));
    }
    iVar2 = *(int *)(plVar4 + -2);
    iVar3 = *(int *)((longlong)plVar4 + -0xc);
    InpFreePacket((longlong)param_1,(longlong)(plVar4 + -3));
    InpPacketFreedLocked((longlong)param_1,(ulonglong)(uint)(iVar2 - iVar3));
  } while( true );
}



===== InReferenceProfilerForQueue @ 1400051ac =====

ulonglong InReferenceProfilerForQueue(longlong *param_1,uint param_2,undefined8 *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong *plVar3;
  ulonglong uVar4;
  undefined8 *puVar5;
  longlong *local_res8;
  
  local_res8 = (longlong *)0x0;
  ExAcquireFastMutex();
  if ((*(char *)(*param_1 + 0x6c0) == '\0') ||
     (puVar5 = KmclProfilerList, (undefined8 **)KmclProfilerList == &KmclProfilerList)) {
LAB_14000527b:
    uVar2 = InpAllocatePacketProfilerLocked(param_1,param_2,&local_res8);
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) goto LAB_14000529d;
    plVar3 = local_res8;
  }
  else {
    do {
      plVar3 = puVar5 + -1;
      if (puVar5[5] == *(longlong *)(*param_1 + 0xcc0)) {
        local_res8 = plVar3;
        lVar1 = RtlCompareMemory(puVar5 + 2,*param_1 + 0xab0,0x10);
        if ((((lVar1 == 0x10) && (*(short *)(*param_1 + 0xcc8) == *(short *)(puVar5 + 4))) &&
            (*(uint *)((longlong)puVar5 + -4) < 4)) && (param_2 <= (uint)((int)*plVar3 * 0x400)))
        break;
      }
      puVar5 = (undefined8 *)*puVar5;
      plVar3 = (longlong *)0x0;
      local_res8 = (longlong *)0x0;
    } while ((undefined8 **)puVar5 != &KmclProfilerList);
    if (plVar3 == (longlong *)0x0) goto LAB_14000527b;
  }
  *(int *)((longlong)plVar3 + 4) = *(int *)((longlong)plVar3 + 4) + 1;
  *param_3 = plVar3;
  uVar4 = 0;
LAB_14000529d:
  ExReleaseFastMutex(&KmclProfilerListLock);
  return uVar4;
}



===== InRequeuePacket @ 1400052d4 =====

void InRequeuePacket(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  code *pcVar2;
  undefined1 uVar3;
  longlong *plVar4;
  longlong lVar5;
  
  plVar1 = (longlong *)(param_2 + 0x18);
  if ((*(byte *)(param_2 + 0x10) & 0x10) == 0) {
LAB_140005342:
    plVar4 = (longlong *)(param_1 + 0x500);
    lVar5 = *plVar4;
    if (*(longlong **)(lVar5 + 8) == plVar4) goto LAB_140005359;
  }
  else {
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x440);
    lVar5 = *plVar1;
    if ((*(longlong **)(lVar5 + 8) == plVar1) &&
       (plVar4 = *(longlong **)(param_2 + 0x20), (longlong *)*plVar4 == plVar1)) {
      *plVar4 = lVar5;
      *(longlong **)(lVar5 + 8) = plVar4;
      *(int *)(param_1 + 0x480) = *(int *)(param_1 + 0x480) + -1;
      KeReleaseSpinLock(param_1 + 0x440,CONCAT71((int7)((ulonglong)plVar4 >> 8),uVar3));
      *(byte *)(param_2 + 0x10) = *(byte *)(param_2 + 0x10) & 0xef;
      goto LAB_140005342;
    }
  }
  lVar5 = 3;
  pcVar2 = (code *)swi(0x29);
  plVar4 = (longlong *)(*pcVar2)();
LAB_140005359:
  *plVar1 = lVar5;
  *(longlong **)(param_2 + 0x20) = plVar4;
  *(longlong **)(lVar5 + 8) = plVar1;
  *plVar4 = (longlong)plVar1;
  *(int *)(param_1 + 0x524) = *(int *)(param_1 + 0x524) + -1;
  if (*(char *)(param_2 + 0x11) != '\0') {
    *(int *)(param_1 + 0x528) = *(int *)(param_1 + 0x528) + -1;
  }
  return;
}



===== InSetPollingMode @ 140005398 =====

void InSetPollingMode(longlong *param_1,char param_2)

{
  longlong *plVar1;
  int iVar2;
  undefined1 uVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  plVar1 = param_1 + 0x88;
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(plVar1);
  if (*(char *)((longlong)param_1 + 0x4b4) != param_2) {
    *(char *)((longlong)param_1 + 0x4b4) = param_2;
    *(char *)(*param_1 + 0x929) = param_2;
    iVar2 = (int)param_1[0x89];
    if (iVar2 == 1) {
      if (param_2 != '\0') {
        KeInitializeEvent(&local_28,1);
        param_1[0x97] = (longlong)&local_28;
        KeReleaseSpinLock(plVar1,uVar3);
        KeWaitForSingleObject(&local_28,0,0,0,0);
        return;
      }
    }
    else {
      if (iVar2 != 2) {
        if (iVar2 == 3) {
          plVar5 = param_1;
          lVar4 = InpDisableInterruptMaskingAndPollLocked((longlong)param_1);
          if ((char)lVar4 == '\0') {
            InpPrepareToQueueWorkerLocked((longlong)plVar5,'\0','\0');
            InpReleaseLockAndPerformWork(param_1);
            return;
          }
          *(undefined4 *)(param_1 + 0x89) = 4;
          goto LAB_140005420;
        }
        if ((((iVar2 != 4) && (iVar2 != 5)) && (iVar2 != 6)) && (iVar2 != 7)) goto LAB_140005420;
      }
      *(undefined4 *)(param_1[0xb] + 8) = 1;
      *(undefined4 *)(param_1 + 0x89) = 3;
    }
  }
LAB_140005420:
  KeReleaseSpinLock(plVar1,uVar3);
  return;
}



===== InStartQueue @ 1400054f4 =====

void InStartQueue(longlong *param_1)

{
  undefined1 uVar1;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
  if (*(int *)((longlong)param_1 + 0x48c) == 0) {
    *(undefined4 *)((longlong)param_1 + 0x48c) = 1;
  }
  if (*(char *)((longlong)param_1 + 0x4b3) != '\0') {
    InpProcessCompletedDeferredPackets(param_1,'\x01');
  }
  if (*(char *)((longlong)param_1 + 0x4b4) == '\0') {
    *(undefined4 *)(param_1[0xb] + 8) = 1;
    *(undefined4 *)(param_1 + 0x89) = 1;
    param_1[0x8d] = (longlong)SystemReserved1[0xf];
    InpPrepareToQueueWorkerLocked((longlong)param_1,'\0','\0');
    InpReleaseLockAndPerformWork(param_1);
  }
  else {
    *(undefined4 *)(param_1 + 0x89) = 3;
    *(undefined4 *)(param_1[0xb] + 8) = 1;
    KeReleaseSpinLock(param_1 + 0x88,uVar1);
  }
  return;
}



===== InStopQueue @ 1400055c8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void InStopQueue(longlong *param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
  puVar6 = auStack_28;
  if ((int)param_1[0xcd] != -1) {
    pcVar1 = *(code **)(*param_1 + 0x9e8);
    puVar6 = auStack_28;
    if (pcVar1 != (code *)0x0) {
      cVar3 = (*pcVar1)(*(undefined8 *)(*param_1 + 0x940),param_1[0xcb]);
      puVar5 = auStack_28;
      puVar6 = auStack_28;
      if (cVar3 != '\0') {
        iVar4 = *(int *)((longlong)param_1 + 0x48c);
        if (iVar4 == 0) {
          pcVar1 = (code *)swi(0x29);
          iVar4 = (*pcVar1)(0xe);
          puVar5 = auStack_20;
        }
        *(undefined4 *)(param_1 + 0xcd) = 0xffffffff;
        *(int *)((longlong)param_1 + 0x48c) = iVar4 + -1;
        puVar6 = puVar5;
      }
    }
  }
  if (*(uint *)((longlong)param_1 + 0x48c) < 2) {
    *(undefined4 *)((longlong)param_1 + 0x48c) = 0;
  }
  else {
    *(uint *)((longlong)param_1 + 0x48c) = *(uint *)((longlong)param_1 + 0x48c) - 1;
    *(undefined8 *)(puVar6 + -8) = 0x140005664;
    InpWaitForQueueStopEvent((longlong)param_1,puVar6 + 0x30);
    uVar2 = puVar6[0x30];
  }
  *(undefined8 *)(puVar6 + -8) = 0x14000567f;
  KeReleaseSpinLock(param_1 + 0x88,uVar2);
  return;
}



===== InpAllocatePacket @ 14000569c =====

undefined4
InpAllocatePacket(longlong param_1,int param_2,int param_3,int param_4,char param_5,
                 undefined8 *param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  longlong *plVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = param_2 + 0xfU & 0xfffffff0;
  uVar6 = (param_4 + param_3 * 6) * 8 + 0xfU & 0xfffffff0;
  uVar5 = param_3 * 0x10 + uVar6 + uVar7 + *(int *)(param_1 + 0x570);
  uVar8 = uVar5 + 0xa0;
  if (param_5 != '\0') {
    uVar2 = *(uint *)(param_1 + 0x5ac);
    if (*(char *)(param_1 + 0x4b3) == '\0') {
      if (uVar2 <= uVar5) goto LAB_140005711;
      uVar2 = uVar2 - uVar5;
    }
    uVar8 = uVar8 + uVar2;
  }
LAB_140005711:
  if (*(uint *)(param_1 + 0x5a8) < uVar8) {
    if (*(int *)(param_1 + 0x448) != 0) {
      *(undefined4 *)(param_1 + 0x578) = 0;
      *(undefined4 *)(param_1 + 0x57c) = 1;
    }
    uVar3 = 0xb;
  }
  else {
    plVar4 = (longlong *)
             ExAllocateFromNPagedLookasideList
                       ((ulonglong)(uVar8 - 1 >> 10) * 0x80 + *(longlong *)(param_1 + 0x5a0) + 0x40)
    ;
    if (plVar4 == (longlong *)0x0) {
      LOCK();
      plVar4 = *(longlong **)(param_1 + 0x5b8);
      *(longlong *)(param_1 + 0x5b8) = 0;
      UNLOCK();
      if (plVar4 == (longlong *)0x0) {
        return 6;
      }
      *(undefined1 *)(plVar4 + 2) = 1;
    }
    else {
      *(undefined1 *)(plVar4 + 2) = 0;
    }
    iVar1 = uVar7 + param_3 * 0x10;
    *(longlong *)(param_1 + 0x568) =
         *(longlong *)(param_1 + 0x568) + (ulonglong)((int)plVar4[1] - uVar8);
    uVar3 = 1;
    *(int *)((longlong)plVar4 + 0x3c) = iVar1;
    *(uint *)(plVar4 + 8) = iVar1 + uVar6;
    *(uint *)((longlong)plVar4 + 0xc) = uVar8;
    *plVar4 = param_1;
    *(undefined4 *)(plVar4 + 5) = 0;
    plVar4[6] = 0;
    *(uint *)(plVar4 + 7) = uVar7;
    *(undefined4 *)((longlong)plVar4 + 0x54) = *(undefined4 *)(param_1 + 0x570);
    plVar4[9] = 0;
    *(undefined1 *)((longlong)plVar4 + 0x11) = 0;
    plVar4[0xb] = 0;
    *param_6 = plVar4;
    plVar4[0xc] = 0;
  }
  return uVar3;
}



===== InpAllocatePacketProfilerLocked @ 1400057f8 =====

undefined8 InpAllocatePacketProfilerLocked(longlong *param_1,uint param_2,undefined8 *param_3)

{
  uint *puVar1;
  longlong lVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  uint *puVar9;
  uint uVar10;
  undefined2 *puVar11;
  
  uVar5 = (param_2 >> 10) + 1;
  if ((param_2 & 0x3ff) == 0) {
    uVar5 = param_2 >> 10;
  }
  puVar6 = (uint *)ExAllocatePool2(0x40,uVar5 * 0x80 + 0x40,0x6e696b56);
  uVar8 = 0;
  if (puVar6 == (uint *)0x0) {
    uVar8 = 0xc000009a;
  }
  else {
    puVar1 = puVar6 + 2;
    uVar10 = 0;
    *(uint **)(puVar6 + 4) = puVar1;
    *(uint **)puVar1 = puVar1;
    if (uVar5 != 0) {
      puVar11 = (undefined2 *)((longlong)puVar6 + 0x52);
      puVar9 = puVar6 + 0x10;
      do {
        ExInitializeNPagedLookasideList
                  (puVar9,InLookasideAllocate,0,ExDefaultNonPagedPoolType | 0x200,
                   (uVar10 + 1) * 0x400,0x6e696b56,0);
        *puVar11 = 0x400;
        puVar9 = puVar9 + 0x20;
        puVar11 = puVar11 + 0x40;
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar5);
    }
    *puVar6 = uVar5;
    *(undefined2 *)(puVar6 + 10) = *(undefined2 *)(*param_1 + 0xcc8);
    *(undefined8 *)(puVar6 + 0xc) = *(undefined8 *)(*param_1 + 0xcc0);
    puVar7 = &KmclProfilerList;
    lVar2 = *param_1;
    uVar5 = *(uint *)(lVar2 + 0xab4);
    uVar10 = *(uint *)(lVar2 + 0xab8);
    uVar4 = *(uint *)(lVar2 + 0xabc);
    puVar6[6] = *(uint *)(lVar2 + 0xab0);
    puVar6[7] = uVar5;
    puVar6[8] = uVar10;
    puVar6[9] = uVar4;
    if (*(undefined8 **)DAT_140016228 != &KmclProfilerList) {
      puVar7 = (undefined8 *)0x3;
      pcVar3 = (code *)swi(0x29);
      DAT_140016228 = (uint *)(*pcVar3)();
    }
    *(undefined8 **)puVar1 = puVar7;
    *(uint **)(puVar6 + 4) = DAT_140016228;
    *(uint **)DAT_140016228 = puVar1;
    DAT_140016228 = puVar1;
    *param_3 = puVar6;
  }
  return uVar8;
}



===== InpBuildDeferredDataPacket @ 140005968 =====

int InpBuildDeferredDataPacket
              (longlong *param_1,int param_2,undefined8 *param_3,uint param_4,int param_5,
              longlong *param_6,undefined8 *param_7)

{
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined8 *puVar6;
  longlong local_res8;
  
  local_res8 = 0;
  if (*(uint *)(*param_1 + 0x6c8) < param_5 - param_4) {
    if ((int)param_1[0x89] == 0) {
      return 0xb;
    }
    *(undefined4 *)(param_1 + 0xaf) = 0;
  }
  else {
    if (param_2 != 9) {
      uVar4 = 0;
      uVar5 = 0;
LAB_140005a0b:
      puVar6 = param_3;
      if (param_7 != (undefined8 *)0x0) {
        puVar6 = param_7;
      }
      iVar3 = InpAllocatePacket((longlong)param_1,param_5,uVar4,uVar5,
                                *(byte *)((longlong)puVar6 + 6) & 1,&local_res8);
      if (iVar3 == 1) {
        uVar2 = puVar6[1];
        *(undefined8 *)(local_res8 + 0x78) = *puVar6;
        *(undefined8 *)(local_res8 + 0x80) = uVar2;
        lVar1 = local_res8 + 0x68;
        *(longlong *)(local_res8 + 0x70) = lVar1;
        *(longlong *)lVar1 = lVar1;
        *(int *)(local_res8 + 0x90) = param_5;
        *(undefined8 **)(local_res8 + 0x88) = param_3;
        *(uint *)(local_res8 + 0x94) = param_4;
        *(uint *)(local_res8 + 0x9c) = uVar4;
        *(uint *)(local_res8 + 0x98) = uVar5;
        *(int *)(param_1 + 0xa4) = (int)param_1[0xa4] + 1;
        *param_6 = local_res8;
        return 1;
      }
      return iVar3;
    }
    if (0x17 < param_4) {
      uVar4 = *(uint *)((longlong)param_3 + 0x14);
      if ((uVar4 != 0) && (uVar4 <= param_4 - 0x18 >> 3)) {
        uVar5 = (param_4 - 0x18) + uVar4 * -8 >> 3;
        goto LAB_140005a0b;
      }
    }
    if ((int)param_1[0x89] == 0) {
      return 0xb;
    }
    *(undefined4 *)(param_1 + 0xaf) = 1;
  }
  *(undefined4 *)((longlong)param_1 + 0x57c) = 1;
  return 0xb;
}



===== InpCancelMdlMapLocked @ 140005ad0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 InpCancelMdlMapLocked(longlong *param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  pcVar1 = *(code **)(*param_1 + 0xa68);
  if (pcVar1 != (code *)0x0) {
    uVar2 = (*pcVar1)(*(undefined8 *)(*param_1 + 0x940),param_1[0xb2] + 0x10);
  }
  return uVar2;
}



===== InpChannelProcessPacketExNoOp @ 140005b10 =====

void InpChannelProcessPacketExNoOp(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  *(undefined4 *)(*param_3 + 0x584) = 2;
  return;
}



===== InpChannelProcessPacketNoOp @ 140005b30 =====

void InpChannelProcessPacketNoOp(undefined8 param_1,longlong *param_2)

{
  *(undefined4 *)(*param_2 + 0x584) = 2;
  return;
}



===== InpCompletionSent @ 140005b50 =====

void InpCompletionSent(longlong param_1)

{
  int iVar1;
  int iVar2;
  longlong *plVar3;
  
  plVar3 = *(longlong **)(param_1 + -0x18);
  iVar1 = *(int *)(param_1 + -0x10);
  iVar2 = *(int *)(param_1 + -0xc);
  InpFreePacket((longlong)plVar3,(longlong)(param_1 + -0x18));
  KeAcquireSpinLockRaiseToDpc(plVar3 + 0x88);
  InpPacketFreedLocked((longlong)plVar3,(ulonglong)(uint)(iVar1 - iVar2));
  InpReleaseLockAndPerformWork(plVar3);
  return;
}



===== InpDisableInterruptMaskingAndPollLocked @ 140005bb4 =====

longlong InpDisableInterruptMaskingAndPollLocked(longlong param_1)

{
  int iVar1;
  uint7 uVar2;
  
  *(undefined4 *)(*(longlong *)(param_1 + 0x58) + 8) = 0;
  LOCK();
  UNLOCK();
  iVar1 = **(int **)(param_1 + 0x58);
  uVar2 = (uint7)(uint3)((uint)iVar1 >> 8);
  if (*(int *)(param_1 + 0x84) == iVar1) {
    return CONCAT71(uVar2,1);
  }
  (*(int **)(param_1 + 0x58))[2] = 1;
  return (ulonglong)uVar2 << 8;
}



===== InpFillAndProcessQueue @ 140005be8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int InpFillAndProcessQueue(longlong *param_1,ulonglong param_2,undefined4 *param_3)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint local_res10 [2];
  undefined4 local_res18 [2];
  
  local_res10[0] = 0;
  local_res18[0] = 0;
  cVar4 = (char)param_2;
  uVar5 = 0;
  *(bool *)(param_1 + 0xb0) = cVar4 == '\x02';
  puVar7 = param_3;
  do {
    if ((uint)param_3 <= uVar5) {
LAB_140005c81:
      iVar2 = 1;
      goto LAB_140005c86;
    }
    if (param_1[0x98] != 0) {
      iVar2 = 7;
      goto LAB_140005c86;
    }
    if ((longlong *)param_1[0xa0] == param_1 + 0xa0) {
      puVar7 = local_res18;
      iVar2 = InpFillQueue(param_1,param_2,puVar7);
      if (iVar2 != 1) goto LAB_140005c86;
    }
    if ((*(char *)((longlong)param_1 + 0x4b1) != '\0') && (cVar4 != '\0')) goto LAB_140005c81;
    uVar6 = (uint)param_3 - uVar5;
    puVar7 = (undefined4 *)(ulonglong)uVar6;
    param_2 = CONCAT71((int7)(param_2 >> 8),cVar4);
    uVar3 = InpProcessQueue(param_1,cVar4,uVar6,local_res10);
    uVar5 = uVar5 + local_res10[0];
    iVar2 = (int)uVar3;
    if (iVar2 != 1) {
LAB_140005c86:
      if (uVar5 != 0) {
        lVar1 = *param_1;
        if (*(char *)(lVar1 + 0x7c8) == '\0') {
          param_2 = (ulonglong)uVar5;
          (**(code **)(lVar1 + 0x7d8))();
        }
        else {
          param_2 = *(ulonglong *)(lVar1 + 0x7e0);
          puVar7 = (undefined4 *)(ulonglong)uVar5;
          (**(code **)(lVar1 + 0x7d8))();
        }
      }
      if ((Microsoft_Windows_Hyper_V_KMCL_ChildEnableBits & 1) != 0) {
        lVar1 = *param_1;
        McTemplateK0jjqqh_EtwWriteTransfer
                  (lVar1 + 0xac0,param_2,puVar7,lVar1 + 0xad0,lVar1 + 0xac0,(char)uVar5,
                   (char)param_3,(char)*(undefined2 *)(lVar1 + 0xcd0));
      }
      *(undefined1 *)(param_1 + 0xb0) = 0;
      return iVar2;
    }
  } while( true );
}



===== InpFillQueue @ 140005d20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int InpFillQueue(longlong *param_1,undefined8 param_2,undefined8 param_3)

{
  short sVar1;
  int iVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined8 uVar7;
  byte bVar8;
  char cVar9;
  uint uVar10;
  longlong lVar11;
  void *pvVar12;
  void *_Dst;
  undefined8 uVar13;
  ulonglong uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  uint uVar21;
  void *pvVar22;
  int iVar23;
  uint *puVar24;
  longlong *plVar25;
  int iVar26;
  uint uVar27;
  uint *puVar28;
  void *_Src;
  bool bVar29;
  undefined1 auStackY_128 [8];
  undefined1 auStackY_120 [24];
  uint local_e8;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  longlong *local_c8;
  undefined8 *local_c0;
  longlong local_b8;
  longlong local_98;
  uint local_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  void *local_80;
  undefined8 local_78;
  uint local_68;
  uint uStack_64;
  uint uStack_60;
  uint uStack_5c;
  undefined8 local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_128;
  uVar17 = *(uint *)((longlong)param_1 + 0x84);
  local_58 = 0;
  uStack_50 = 0;
  local_78 = param_3;
  KeAcquireSpinLockRaiseToDpc(param_1 + 0x58);
  puVar19 = auStackY_128;
  local_e8 = 0;
  do {
    puVar24 = (uint *)0x0;
    uVar15 = *(uint *)(param_1 + 0x10);
    uVar10 = *(uint *)(param_1 + 0xd);
    puVar18 = (uint *)(ulonglong)uVar10;
    uVar27 = local_e8;
    if (uVar15 == uVar17) {
      uVar15 = *(uint *)param_1[0xb];
      if ((uVar15 < uVar10) && ((uVar15 & 7) == 0)) {
        *(uint *)(param_1 + 0x10) = uVar15;
        if (uVar15 != uVar17) goto LAB_140005dc4;
        iVar26 = 4;
      }
      else {
LAB_1400064ba:
        param_1[0xaf] = 4;
        iVar26 = 0xb;
      }
      goto LAB_14000640c;
    }
LAB_140005dc4:
    uVar15 = uVar15 - uVar17;
    if (uVar10 <= uVar15) {
      uVar15 = uVar15 + uVar10;
    }
    puVar28 = (uint *)((ulonglong)uVar17 + param_1[0xc]);
    local_68 = *puVar28;
    uStack_64 = puVar28[1];
    uVar13 = *(undefined8 *)puVar28;
    uStack_60 = puVar28[2];
    uStack_5c = puVar28[3];
    uVar7 = *(undefined8 *)(puVar28 + 2);
    uVar21 = (uStack_64 & 0xffff) * 8;
    if ((uVar21 < 0x10) || (uVar15 < uVar21 + 8)) goto LAB_1400064ba;
    local_d4 = uVar17 + uVar21 + 8;
    if (uVar10 <= local_d4) {
      local_d4 = local_d4 - uVar10;
    }
    local_58._2_2_ = (short)(local_68 >> 0x10);
    iVar26 = (int)local_58._2_2_;
    uVar27 = iVar26 * 8;
    local_58 = uVar13;
    uStack_50 = uVar7;
    if ((uVar21 < uVar27) || (uVar27 < 0x10)) {
      param_1[0xaf] = 0;
LAB_140006402:
      iVar26 = 0xb;
LAB_140006407:
      uVar27 = local_e8;
      goto LAB_14000640c;
    }
    puVar18 = (uint *)((ulonglong)local_68 & 0xffff);
    uVar15 = local_68 & 0xffff;
    if (((uVar15 != 6) && (uVar15 != 7)) && (uVar15 != 9)) {
      if ((uVar15 == 10) || (uVar15 != 0xb)) {
        param_1[0xaf] = 3;
      }
      else {
        if (uVar21 + iVar26 * -8 <= *(uint *)((longlong)param_1 + 0x5ac)) {
          local_b8 = 0;
          uStack_88 = 0;
          local_90 = 0;
          local_8c = 0;
          if (uStack_60 < *(uint *)(param_1 + 0x5a)) {
            lVar11 = *(longlong *)(param_1[0x59] + (ulonglong)uStack_60 * 8);
            if (lVar11 < 0) {
              local_b8 = lVar11;
            }
          }
          else if (param_1[0x5e] != 0) {
            puVar18 = &local_90;
            local_90 = uStack_60;
            lVar11 = RtlLookupElementGenericTableAvl();
            if (lVar11 != 0) {
              local_b8 = *(longlong *)(lVar11 + 8);
            }
          }
          if (local_b8 != 0) {
            if (*(int *)(local_b8 + 0x18) != 3) {
              KeAcquireSpinLockAtDpcLevel(param_1 + 0x20);
              if (*(int *)(local_b8 + 0x18) != 3) {
                KeReleaseSpinLockFromDpcLevel(param_1 + 0x20);
                goto LAB_1400063f7;
              }
              *(int *)(param_1 + 0x85) = (int)param_1[0x85] + 1;
              KeReleaseSpinLockFromDpcLevel(param_1 + 0x20);
            }
            if ((*(longlong *)(local_b8 + 0x80) != 0) && (KmclPerformanceCounterTimingCounters != 0)
               ) {
              lVar11 = KeQueryPerformanceCounter(0);
              lVar11 = lVar11 - *(longlong *)(local_b8 + 0x80);
              bVar29 = KmclPerformanceCounterTimingCounters != 0;
              *(longlong *)(local_b8 + 0x80) = lVar11;
              if (bVar29) {
                param_1[0x3f] = param_1[0x3f] + lVar11;
              }
            }
            local_dc = 0;
            puVar24 = (uint *)0x0;
            local_d8 = 0;
            if (((*(char *)(local_b8 + 0x3d) == '\x01') &&
                (local_c8 = *(longlong **)(local_b8 + 0x50), local_c8 != (longlong *)0x0)) &&
               (bVar8 = *(byte *)(local_b8 + 0x3e), (bVar8 & 0x20) == 0)) {
              uVar17 = *(uint *)(local_b8 + 0x48);
              if ((((uVar17 == 0) && (*(int *)(local_b8 + 0x4c) == 0)) && ((bVar8 & 1) == 0)) ||
                 (local_dc = uVar17, (bVar8 & 1) == 0)) {
                local_c0 = *(undefined8 **)(local_b8 + 0x40);
              }
              else {
                local_d8 = *(uint *)(local_b8 + 0x4c);
                puVar24 = (uint *)(ulonglong)local_d8;
                local_c0 = *(undefined8 **)(local_b8 + 0x40);
              }
              uVar15 = local_dc;
              do {
                uVar17 = *(uint *)((longlong)local_c0 + 0x2c);
                lVar11 = (ulonglong)uVar17 + local_c0[4];
                if ((*(byte *)((longlong)local_c0 + 10) & 5) == 0) {
                  pvVar12 = (void *)MmMapLockedPagesSpecifyCache(local_c0,0,1);
                  uVar17 = *(uint *)((longlong)local_c0 + 0x2c);
                }
                else {
                  pvVar12 = (void *)local_c0[3];
                }
                if ((int)puVar24 == 0) {
                  puVar24 = (uint *)(ulonglong)*(uint *)(local_c0 + 5);
                }
                else {
                  local_d8 = 0;
                }
                plVar25 = (longlong *)local_c8[2];
                local_e0 = (uint)puVar24;
                pvVar22 = pvVar12;
                local_80 = pvVar12;
                if (plVar25 != local_c8 + 2) {
                  do {
                    _Src = (void *)(plVar25[4] + (ulonglong)uVar17);
                    uVar10 = 0x1000 - uVar17;
                    uVar17 = 0;
                    if (uVar15 != 0) {
                      uVar16 = uVar10;
                      if (uVar15 <= uVar10) {
                        uVar16 = uVar15;
                      }
                      uVar14 = (ulonglong)uVar16;
                      uVar10 = uVar10 - uVar16;
                      _Src = (void *)((longlong)_Src + uVar14);
                      lVar11 = lVar11 + uVar14;
                      pvVar22 = (void *)((longlong)pvVar22 + uVar14);
                      uVar17 = -uVar16;
                      uVar15 = uVar15 - uVar16;
                      local_dc = uVar15;
                    }
                    puVar18 = puVar24;
                    if (uVar10 < (uint)puVar24) {
                      puVar18 = (uint *)(ulonglong)uVar10;
                    }
                    iVar23 = (int)puVar18;
                    if (iVar23 != 0) {
                      if (pvVar12 == (void *)0x0) {
                        puVar3 = (undefined8 *)param_1[0x60];
                        lVar4 = param_1[0x5f];
                        *puVar3 = 0;
                        *(undefined2 *)((longlong)puVar3 + 10) = 0;
                        puVar3[4] = 0;
                        *(undefined4 *)((longlong)puVar3 + 0x2c) = 0;
                        *(short *)(puVar3 + 1) =
                             ((short)((longlong)puVar18 + 0xfffU >> 0xc) + 6) * 8;
                        *(int *)(puVar3 + 5) = iVar23;
                        IoBuildPartialMdl(local_c0,puVar3,lVar11,puVar18);
                        _Dst = (void *)MmMapLockedPagesWithReservedMapping(lVar4,0x636d6b56,puVar3);
                        if (_Dst == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
                          KeBugCheckEx(0x53495650,0x361,param_1,lVar4);
                        }
                      }
                      else {
                        _Dst = pvVar22;
                      }
                      memmove(_Dst,_Src,(size_t)puVar18);
                      if (local_80 == (void *)0x0) {
                        lVar4 = param_1[0x60];
                        MmUnmapReservedMapping(param_1[0x5f],0x636d6b56,lVar4);
                        if ((*(byte *)(lVar4 + 10) & 0x20) != 0) {
                          MmUnmapLockedPages(*(undefined8 *)(lVar4 + 0x18),lVar4);
                        }
                      }
                      lVar11 = lVar11 + (longlong)puVar18;
                      local_e0 = local_e0 - iVar23;
                      puVar24 = (uint *)(ulonglong)local_e0;
                      pvVar22 = (void *)((longlong)pvVar22 + (longlong)puVar18);
                      uVar15 = local_dc;
                    }
                    plVar25 = (longlong *)*plVar25;
                  } while (plVar25 != local_c8 + 2);
                }
                uVar17 = (uint)plVar25;
                local_c8 = (longlong *)*local_c8;
                local_c0 = (undefined8 *)*local_c0;
                puVar24 = (uint *)(ulonglong)local_d8;
              } while (local_c8 != (longlong *)0x0);
            }
            KeAcquireSpinLockAtDpcLevel(param_1 + 0x20);
            OutpTransitionPacketToReadyToComplete(param_1,local_b8);
            KeReleaseSpinLockFromDpcLevel(param_1 + 0x20);
            puVar18 = (uint *)(local_b8 + 0xb0);
            *(uint **)(local_b8 + 0xb8) = puVar18;
            uVar15 = uVar21 + iVar26 * -8;
            *(uint **)puVar18 = puVar18;
            *(undefined8 *)(local_b8 + 0xc0) = local_58;
            *(undefined8 *)(local_b8 + 200) = uStack_50;
            *(uint **)(local_b8 + 0xd0) = puVar28;
            *(uint *)(local_b8 + 0xd8) = uVar27;
            *(uint *)(local_b8 + 0xdc) = uVar21;
            if (*(uint *)(local_b8 + 0x70) < uVar15) {
              iVar26 = 0;
            }
            else {
              iVar26 = uVar21 + iVar26 * -8;
            }
            bVar8 = *(byte *)(local_b8 + 0x3e) | 2;
            if (*(uint *)(local_b8 + 0x70) < uVar15) {
              bVar8 = *(byte *)(local_b8 + 0x3e) & 0xfd;
            }
            *(byte *)(local_b8 + 0x3e) = bVar8;
            *(int *)(local_b8 + 0x74) = iVar26;
            puVar28 = puVar24;
            goto LAB_1400063a3;
          }
        }
LAB_1400063f7:
        param_1[0xaf] = 2;
      }
      goto LAB_140006402;
    }
    if (*(uint *)((longlong)param_1 + 0x574) <= (uint)((int)param_1[0xa4] - (int)param_1[0x8f])) {
      param_1[0xa7] = param_1[0xa7] + 1;
      iVar26 = 5;
      if ((Microsoft_Windows_Hyper_V_KMCL_ChildEnableBits & 4) != 0) {
        lVar11 = *param_1;
        puVar18 = (uint *)&VMBUS_HIT_INCOMING_QUOTA;
        McTemplateK0jjh_EtwWriteTransfer
                  (lVar11 + 0xac0,&VMBUS_HIT_INCOMING_QUOTA,0,lVar11 + 0xad0,lVar11 + 0xac0,
                   (char)*(undefined2 *)(lVar11 + 0xcd0));
      }
      goto LAB_140006407;
    }
    local_98 = 0;
    puVar24 = puVar28;
    iVar26 = InpBuildDeferredDataPacket
                       (param_1,local_68 & 0xffff,(undefined8 *)puVar28,uVar27,uVar21,&local_98,
                        &local_58);
    if (iVar26 != 1) goto LAB_140006407;
    puVar18 = (uint *)(local_98 + 0x68);
LAB_1400063a3:
    puVar24 = (uint *)(param_1 + 0xa2);
    plVar25 = (longlong *)param_1[0xa3];
    if ((uint *)*plVar25 != puVar24) goto LAB_14000669b;
    *(uint **)puVar18 = puVar24;
    local_e8 = local_e8 + 1;
    *(longlong **)(puVar18 + 2) = plVar25;
    *plVar25 = (longlong)puVar18;
    param_1[0xa3] = (longlong)puVar18;
    *(int *)(param_1 + 0xa6) = (int)param_1[0xa6] + 1;
    uVar17 = local_d4;
  } while (local_e8 < 0x40);
  iVar26 = 1;
  uVar27 = local_e8;
LAB_14000640c:
  for (plVar25 = (longlong *)param_1[0xa2]; plVar25 != param_1 + 0xa2;
      plVar25 = (longlong *)*plVar25) {
    if ((short)plVar25[2] == 0xb) {
      if (*(uint *)((longlong)plVar25 + -0x3c) != 0) {
        puVar24 = (uint *)(ulonglong)*(uint *)((longlong)plVar25 + -0x3c);
        puVar18 = (uint *)((ulonglong)*(uint *)(plVar25 + 5) + plVar25[4]);
        memmove((void *)plVar25[-9],puVar18,(size_t)puVar24);
      }
    }
    else {
      puVar24 = (uint *)(ulonglong)*(uint *)(plVar25 + 5);
      puVar18 = (uint *)plVar25[4];
      memmove(plVar25 + 7,puVar18,(size_t)puVar24);
      plVar25[7] = plVar25[2];
      plVar25[8] = plVar25[3];
    }
  }
  uVar13 = InpBatchProcessAndEnqueue(param_1,puVar18,(ulonglong)puVar24);
  local_d4 = (uint)uVar13;
  KeReleaseSpinLock(param_1 + 0x58);
  puVar20 = auStackY_128;
  if ((longlong *)param_1[0xa2] != param_1 + 0xa2) {
    bVar8 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
    puVar28 = (uint *)(ulonglong)bVar8;
    while (plVar25 = (longlong *)param_1[0xa2], plVar25 != param_1 + 0xa2) {
      lVar11 = *plVar25;
      if (((longlong *)*(longlong *)(lVar11 + 8) != plVar25) ||
         (plVar5 = (longlong *)plVar25[1], (longlong *)*plVar5 != plVar25)) goto LAB_14000669b;
      *plVar5 = lVar11;
      *(longlong **)(lVar11 + 8) = plVar5;
      sVar1 = *(short *)(plVar25 + 2);
      if (((sVar1 == 6) || (sVar1 == 7)) || (sVar1 == 9)) {
        uVar15 = *(uint *)(plVar25 + -0xc);
        lVar11 = (longlong)(plVar25 + -0xd);
        iVar23 = *(int *)((longlong)plVar25 + -0x5c);
        if ((*(byte *)(plVar25 + -0xb) & 1) == 0) {
          puVar18 = (uint *)param_1[0xb4];
          uVar10 = uVar15 - 1 >> 10;
          if ((*puVar18 <= uVar10) || (uVar15 != puVar18[(ulonglong)uVar10 * 0x20 + 0x1b]))
          goto LAB_140006640;
          ExFreeToNPagedLookasideList(puVar18 + (ulonglong)uVar10 * 0x20 + 0x10);
        }
        else if (lVar11 == param_1[0xb6]) {
          LOCK();
          param_1[0xb7] = lVar11;
          UNLOCK();
        }
        else {
LAB_140006640:
          ExFreePoolWithTag(lVar11);
        }
        LOCK();
        *(int *)(param_1 + 0x8f) = (int)param_1[0x8f] + 1;
        UNLOCK();
        iVar2 = (int)param_1[0x89];
        param_1[0x92] = param_1[0x92] + (ulonglong)(uVar15 - iVar23);
        if (iVar2 == 1) {
          *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) | 2;
        }
        else if ((iVar2 == 5) || (iVar2 == 6)) {
          InpPrepareToQueueWorkerLocked((longlong)param_1,'\0','\0');
        }
      }
      else if (sVar1 == 0xb) {
        *(undefined4 *)(plVar25 + -0x13) = 1;
        *(undefined1 *)((longlong)plVar25 + -0x73) = 0;
        *(undefined4 *)((longlong)plVar25 + -0x3c) = 0;
        if ((*(byte *)((longlong)plVar25 + -0x72) & 0x40) == 0) {
          (*(code *)plVar25[-0xb])(plVar25 + -0x16,0xc00002b6,plVar25[-9],0);
        }
        else {
          (*(code *)plVar25[-0xb])(plVar25 + -0x16,plVar25[-10],0xc00002b6,plVar25[-9]);
        }
      }
    }
    goto LAB_1400066a2;
  }
LAB_1400066b9:
  **(uint **)(puVar20 + 0xb0) = uVar27;
  if ((local_d4 == 0xb) || (iVar26 == 0xb)) {
    iVar26 = 0xb;
  }
  else if (uVar27 != 0) {
    *(undefined8 *)(puVar20 + -8) = 0x1400066e0;
    uVar14 = PkCompleteRemoval((longlong)(param_1 + 8),uVar17);
    if ((int)uVar14 == 0x214) {
      lVar11 = *param_1;
      cVar9 = *(char *)(lVar11 + 0x929);
      uVar13 = *(undefined8 *)(lVar11 + 0x940);
      pcVar6 = *(code **)(lVar11 + 0x9d0);
      *(undefined8 *)(puVar20 + -8) = 0x140006709;
      cVar9 = (*pcVar6)(uVar13,cVar9 == '\0');
      if (cVar9 != '\0') {
        LOCK();
        *(int *)(lVar11 + 0x694) = *(int *)(lVar11 + 0x694) + 1;
        UNLOCK();
        param_1[0xa8] = param_1[0xa8] + 1;
        iVar26 = 1;
        goto LAB_140006739;
      }
      param_1[0xa9] = param_1[0xa9] + 1;
    }
    iVar26 = 1;
  }
LAB_140006739:
  *(undefined8 *)(puVar20 + -8) = 0x140006749;
  return iVar26;
LAB_14000669b:
  pcVar6 = (code *)swi(0x29);
  (*pcVar6)(3);
  puVar19 = auStackY_120;
LAB_1400066a2:
  *(undefined8 *)(puVar19 + -8) = 0x1400066b4;
  KeReleaseSpinLock(param_1 + 0x88,(ulonglong)puVar28 & 0xff);
  puVar20 = puVar19;
  goto LAB_1400066b9;
}



===== InpFreePacketProfilerLocked @ 14000676c =====

void InpFreePacketProfilerLocked(uint *param_1)

{
  uint *puVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  uint uVar5;
  ulonglong uVar6;
  
  uVar6 = 0;
  if (*param_1 != 0) {
    do {
      ExDeleteNPagedLookasideList(param_1 + uVar6 * 0x20 + 0x10);
      uVar5 = (int)uVar6 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < *param_1);
  }
  puVar1 = param_1 + 2;
  lVar2 = *(longlong *)puVar1;
  if ((*(uint **)(lVar2 + 8) == puVar1) &&
     (plVar3 = *(longlong **)(param_1 + 4), (uint *)*plVar3 == puVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    ExFreePoolWithTag(param_1,0x6e696b56);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== InpMapPacketMdlComplete @ 1400067f0 =====

void InpMapPacketMdlComplete(longlong param_1,int param_2)

{
  byte bVar1;
  longlong *plVar2;
  longlong lVar3;
  bool bVar4;
  int iVar5;
  
  plVar2 = *(longlong **)(param_1 + -0x10);
  bVar4 = true;
  if (param_2 < 0) {
    *(undefined4 *)(plVar2 + 0xaf) = 5;
    iVar5 = 0xb;
    *(undefined4 *)((longlong)plVar2 + 0x57c) = 4;
  }
  else {
    lVar3 = *(longlong *)(param_1 + -8);
    InpPostProcessMappedMdl
              (lVar3,(undefined8 *)
                     ((ulonglong)*(uint *)(lVar3 + 0x38) + lVar3 +
                      (ulonglong)*(uint *)(lVar3 + 0x4c) * 8 + 0xa0),*(uint *)(lVar3 + 0x4c));
    iVar5 = 1;
  }
  KeAcquireSpinLockRaiseToDpc(plVar2 + 0x88);
  if ((int)plVar2[0x89] == 8) {
    *(undefined4 *)(plVar2 + 0x89) = 1;
    plVar2[0x8d] = (longlong)SystemReserved1[0xf];
  }
  else {
    bVar1 = *(byte *)(plVar2 + 0x8c);
    *(byte *)(plVar2 + 0x8c) = bVar1 | 4;
    if (param_2 < 0) {
      *(byte *)(plVar2 + 0x8c) = bVar1 | 0xc;
    }
    bVar4 = false;
  }
  KeReleaseSpinLock(plVar2 + 0x88);
  if (bVar4) {
    InpTransitionRunningQueue(plVar2,'\0',iVar5);
  }
  return;
}



===== InpParseGpaDirectPacket @ 1400068ec =====

bool InpParseGpaDirectPacket(longlong param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  bool bVar5;
  uint local_res10 [2];
  
  uVar1 = *(uint *)(param_1 + 0x3c);
  iVar2 = *(int *)(param_1 + 0x40);
  lVar4 = param_1 + 0xa0 + (ulonglong)*(uint *)(param_1 + 0x38);
  local_res10[0] = 0;
  uVar3 = PkParseGpaRanges((uint *)(param_1 + 0xb8),param_2 - 0x18,param_3,lVar4,local_res10);
  bVar5 = -1 < (int)uVar3;
  if (bVar5) {
    PkCalculateMdlOffsets
              ((ulonglong)uVar1 + 0xa0 + param_1,iVar2 - uVar1,(uint *)(param_1 + 0xb8),param_3,
               lVar4 + (ulonglong)param_3 * 8);
    *(uint *)(param_1 + 0x48) = local_res10[0];
    *(uint *)(param_1 + 0x4c) = param_3;
    *(uint *)(param_1 + 0xb4) = param_3;
  }
  return bVar5;
}



===== InpPostProcessMappedMdl @ 140006990 =====

void InpPostProcessMappedMdl(longlong param_1,undefined8 *param_2,uint param_3)

{
  undefined8 *puVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  if (1 < param_3) {
    uVar2 = (ulonglong)(param_3 - 1);
    puVar4 = param_2;
    puVar3 = param_2;
    do {
      puVar3 = puVar3 + 1;
      puVar1 = (undefined8 *)*puVar4;
      puVar4 = puVar4 + 1;
      *puVar1 = *puVar3;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  *(undefined8 *)(param_1 + 0x30) = *param_2;
  return;
}



===== InpProcessCompletedDeferredPackets @ 1400069cc =====

void InpProcessCompletedDeferredPackets(longlong *param_1,char param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined8 uVar8;
  longlong *plVar9;
  longlong *plVar10;
  
  plVar4 = (longlong *)param_1[0x8a];
  do {
    do {
      plVar10 = plVar4;
      if (plVar10 == param_1 + 0x8a) {
        return;
      }
      plVar4 = (longlong *)*plVar10;
      plVar9 = plVar10 + -3;
    } while ((*(byte *)(plVar10 + -1) & 0x20) == 0);
    if (plVar10[3] != 0) {
      InpUnmapPacketMdl(param_1,(longlong)plVar9);
    }
    lVar5 = *plVar10;
    if ((*(longlong **)(lVar5 + 8) != plVar10) ||
       (plVar6 = (longlong *)plVar10[1], (longlong *)*plVar6 != plVar10)) {
      pcVar7 = (code *)swi(0x29);
      (*pcVar7)(3);
      pcVar7 = (code *)swi(3);
      (*pcVar7)();
      return;
    }
    *plVar6 = lVar5;
    *(longlong **)(lVar5 + 8) = plVar6;
    *(int *)(param_1 + 0x90) = (int)param_1[0x90] + -1;
    *(int *)((longlong)param_1 + 0x484) = *(int *)((longlong)param_1 + 0x484) + -1;
    cVar1 = *(char *)((longlong)plVar10 + -7);
    if ((param_2 == '\0') || ((*(byte *)(plVar10 + -1) & 4) == 0)) {
LAB_140006aa5:
      lVar5 = plVar10[-2];
      iVar3 = *(int *)((longlong)plVar10 + -0xc);
      InpFreePacket((longlong)param_1,(longlong)plVar9);
      InpPacketFreedLocked((longlong)param_1,(ulonglong)(uint)((int)lVar5 - iVar3));
    }
    else {
      uVar2 = *(uint *)(plVar10 + 5);
      plVar10[5] = plVar10[0x12];
      plVar10[4] = (longlong)InpCompletionSent;
      uVar8 = OutSendCompletionAtDpcLevel
                        (param_1,plVar10,
                         (void *)((longlong)plVar9 +
                                 (ulonglong)uVar2 + 0xa0 +
                                 (ulonglong)*(uint *)((longlong)plVar10 + 0x3c)),
                         *(uint *)(plVar10 + 7),'\0');
      if ((char)uVar8 != '\0') goto LAB_140006aa5;
    }
    InpPacketCompletedLocked(param_1,cVar1);
  } while( true );
}



===== InpProcessingDpcRoutine @ 140006b10 =====

void InpProcessingDpcRoutine(longlong *param_1,longlong *param_2,longlong param_3)

{
  ulonglong uVar1;
  undefined7 uVar2;
  
  uVar2 = (undefined7)((ulonglong)param_2 >> 8);
  KeAcquireSpinLockAtDpcLevel(param_2 + 0x88);
  if (param_1 == param_2 + 0xbb) {
    *(undefined4 *)(param_2 + 0xcc) = 0xffffffff;
  }
  else {
    *(undefined4 *)((longlong)param_2 + 0x664) = 0xffffffff;
  }
  uVar1 = InpWorkerTakeProcessingOwnershipLocked((longlong)param_2);
  KeReleaseSpinLockFromDpcLevel(param_2 + 0x88);
  if ((char)uVar1 != '\0') {
    InpRunQueueAtDpcLevel(param_2,CONCAT71(uVar2,param_3 != 0));
  }
  return;
}



===== InpProcessingWorkerRoutine @ 140006bb0 =====

void InpProcessingWorkerRoutine(longlong *param_1)

{
  int iVar1;
  ulonglong uVar2;
  
  KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0xcd) = 0xffffffff;
  uVar2 = InpWorkerTakeProcessingOwnershipLocked((longlong)param_1);
  KeReleaseSpinLock(param_1 + 0x88);
  if ((char)uVar2 != '\0') {
    iVar1 = InpFillAndProcessQueue(param_1,0,(undefined4 *)0xc8);
    *(undefined1 *)((longlong)param_1 + 0x4b1) = *(undefined1 *)((longlong)param_1 + 0x4b2);
    InpTransitionRunningQueue(param_1,'\0',iVar1);
  }
  return;
}



===== InpReacquirePacketAllocationResources @ 140006c4c =====

ulonglong InpReacquirePacketAllocationResources(longlong *param_1,uint param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  uint *puVar3;
  ulonglong uVar4;
  uint *local_res18 [2];
  
  local_res18[0] = (uint *)0x0;
  lVar1 = ExAllocatePool2(0x40,param_2,0x6e696b56);
  if (lVar1 == 0) {
    uVar4 = 0xc000009a;
  }
  else {
    *(uint *)(lVar1 + 8) = param_2;
    uVar2 = InReferenceProfilerForQueue(param_1,param_2,local_res18);
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      puVar3 = local_res18[0];
    }
    else {
      InpReleasePacketAllocationResources((longlong)param_1);
      param_1[0xb6] = lVar1;
      param_1[0xb7] = lVar1;
      lVar1 = 0;
      param_1[0xb4] = (longlong)local_res18[0];
      uVar4 = 0;
      puVar3 = (uint *)0x0;
    }
    if (puVar3 != (uint *)0x0) {
      InDereferencePacketProfiler(puVar3);
    }
    if (lVar1 != 0) {
      ExFreePoolWithTag(lVar1,0x6e696b56);
    }
  }
  return uVar4;
}



===== InpReleasePacketAllocationResources @ 140006d14 =====

void InpReleasePacketAllocationResources(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x5b0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x5b0),0x6e696b56);
    *(undefined8 *)(param_1 + 0x5b0) = 0;
    *(undefined8 *)(param_1 + 0x5b8) = 0;
  }
  if (*(uint **)(param_1 + 0x5a0) != (uint *)0x0) {
    InDereferencePacketProfiler(*(uint **)(param_1 + 0x5a0));
    *(undefined8 *)(param_1 + 0x5a0) = 0;
  }
  return;
}



===== InpTransitionRunningQueue @ 140006d70 =====

void InpTransitionRunningQueue(longlong *param_1,char param_2,int param_3)

{
  code *pcVar1;
  byte bVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  iVar8 = 1;
  KeAcquireSpinLockRaiseToDpc(param_1 + 0x88);
  puVar5 = auStack_38;
  puVar6 = auStack_38;
  puVar7 = auStack_38;
  if (param_3 != 1) {
    if (param_3 == 4) {
      puVar7 = auStack_38;
      if ((*(char *)((longlong)param_1 + 0x4b4) == '\0') &&
         (puVar7 = auStack_38, *(int *)((longlong)param_1 + 0x84) == *(int *)param_1[0xb])) {
        puVar6 = auStack_38;
        if ((uint)((int)param_1[0xa5] + (int)param_1[0x91]) < *(uint *)((longlong)param_1 + 0x52c))
        {
          lVar3 = InpDisableInterruptMaskingAndPollLocked((longlong)param_1);
          puVar6 = auStack_38;
          puVar7 = auStack_38;
          if ((char)lVar3 == '\0') goto LAB_140006e4c;
        }
LAB_140006e4a:
        puVar7 = puVar6;
        iVar8 = param_3;
      }
    }
    else {
      if ((param_3 == 5) || (param_3 == 6)) {
        bVar2 = *(byte *)(param_1 + 0x8c) & 2;
      }
      else {
        if (param_3 != 7) {
          if (param_3 != 8) {
            puVar6 = auStack_38;
            if (param_3 == 0xb) goto LAB_140006e4a;
            pcVar1 = (code *)swi(0x29);
            (*pcVar1)(5);
            puVar5 = auStack_30;
          }
          puVar6 = puVar5;
          if ((*(byte *)(param_1 + 0x8c) & 4) == 0) goto LAB_140006e4a;
          puVar7 = puVar5;
          if ((*(byte *)(param_1 + 0x8c) & 8) != 0) {
            *(undefined4 *)(param_1 + 0xaf) = 5;
            *(undefined4 *)((longlong)param_1 + 0x57c) = 3;
            iVar8 = 0xb;
          }
          goto LAB_140006e4c;
        }
        bVar2 = *(byte *)(param_1 + 0x8c) & 1;
      }
      puVar7 = auStack_38;
      if (bVar2 == 0) goto LAB_140006e4a;
    }
  }
LAB_140006e4c:
  *(undefined1 *)(param_1 + 0x8c) = 0;
  if ((iVar8 == 1) && (*(char *)((longlong)param_1 + 0x4b4) == '\0')) {
    *(undefined8 *)(puVar7 + -8) = 0x140006e6e;
    InpPrepareToQueueWorkerLocked((longlong)param_1,'\0',param_2);
    goto LAB_140006ef8;
  }
  if (param_1[0x98] == 0) {
LAB_140006eb0:
    if (*(char *)((longlong)param_1 + 0x4b4) != '\0') {
      if ((iVar8 != 8) && (iVar8 != 0xb)) {
        iVar8 = 3;
      }
      lVar3 = param_1[0x97];
      if (lVar3 != 0) {
        *(undefined8 *)(puVar7 + -8) = 0x140006edd;
        KeSetEvent(lVar3,0,0);
        param_1[0x97] = 0;
      }
    }
    *(int *)(param_1 + 0x89) = iVar8;
  }
  else {
    if (iVar8 == 8) {
      *(undefined8 *)(puVar7 + -8) = 0x140006e8a;
      uVar4 = InpCancelMdlMapLocked(param_1);
      if ((char)uVar4 == '\0') goto LAB_140006eb0;
    }
    lVar3 = param_1[0x98];
    *(undefined8 *)(puVar7 + -8) = 0x140006ea1;
    KeSetEvent(lVar3,0,0);
    param_1[0x98] = 0;
  }
  param_1[0x8d] = 0;
LAB_140006ef8:
  *(undefined8 *)(puVar7 + -8) = 0x140006f03;
  InpReleaseLockAndPerformWork(param_1);
  return;
}



===== InpUnmapPacketMdl @ 140006f24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void InpUnmapPacketMdl(longlong *param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = param_2 + 0xa0 + (ulonglong)*(uint *)(param_2 + 0x38);
  iVar1 = (**(code **)(*param_1 + 0xa28))
                    (*(undefined8 *)(*param_1 + 0x940),lVar2,
                     lVar2 + (ulonglong)*(uint *)(param_2 + 0x4c) * 8,
                     (ulonglong)*(uint *)(param_2 + 0x4c),*(undefined4 *)(param_2 + 0x44));
  if (-1 < iVar1) {
    *(undefined8 *)(param_2 + 0x30) = 0;
  }
  return;
}



===== InpWaitForQueueStopEvent @ 140006f78 =====

void InpWaitForQueueStopEvent(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_28,1,0);
  uVar1 = *param_2;
  *(undefined8 **)(param_1 + 0x4c0) = &local_28;
  KeReleaseSpinLock(param_1 + 0x440,uVar1);
  KeWaitForSingleObject(&local_28,0,0,0,0);
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x440);
  *param_2 = uVar1;
  return;
}



===== InpWorkerTakeProcessingOwnershipLocked @ 140007018 =====

ulonglong InpWorkerTakeProcessingOwnershipLocked(longlong param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar7 = auStack_28;
  iVar3 = *(int *)(param_1 + 0x48c);
  lVar6 = param_1;
  if (iVar3 == 0) {
    lVar6 = 0xe;
    pcVar2 = (code *)swi(0x29);
    iVar3 = (*pcVar2)();
    puVar7 = auStack_20;
  }
  uVar4 = iVar3 - 1;
  uVar5 = (ulonglong)uVar4;
  *(uint *)(lVar6 + 0x48c) = uVar4;
  if (*(int *)(lVar6 + 0x448) == 2) {
    *(undefined4 *)(lVar6 + 0x448) = 1;
    uVar5 = CONCAT71((uint7)(uint3)(uVar4 >> 8),1);
    *(void **)(param_1 + 0x468) = SystemReserved1[0xf];
  }
  else {
    if (uVar4 == 0) {
      uVar1 = *(undefined8 *)(lVar6 + 0x4c0);
      *(undefined8 *)(puVar7 + -8) = 0x140007076;
      uVar5 = KeSetEvent(uVar1,0,0);
      *(undefined8 *)(param_1 + 0x4c0) = 0;
    }
    uVar5 = uVar5 & 0xffffffffffffff00;
  }
  return uVar5;
}



===== McGenEventWrite_EtwWriteTransfer @ 140007094 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_140016008;
  uVar2 = 0;
  if (DAT_140016008 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_140016008;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(VMBKMCL_PROVIDER_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateK0jjh_EtwWriteTransfer @ 1400070f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jjh_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined1 param_6)

{
  undefined1 auStackY_88 [32];
  undefined8 local_58 [2];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_38 = param_5;
  local_28 = &param_6;
  local_40 = 0x10;
  local_30 = 0x10;
  local_20 = 2;
  local_48 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,4,local_58);
  return;
}



===== McTemplateK0jjqqh_EtwWriteTransfer @ 140007170 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jjqqh_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_58 = param_5;
  local_48 = &param_6;
  local_38 = &param_7;
  local_28 = &param_8;
  local_60 = 0x10;
  local_50 = 0x10;
  local_40 = 4;
  local_30 = 4;
  local_20 = 2;
  local_68 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,&VMBUS_FINISH_FETCHING,param_3,6,local_78);
  return;
}



===== McTemplateK0jjxth_EtwWriteTransfer @ 140007210 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0jjxth_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined1 auStackY_a8 [32];
  undefined8 local_78 [2];
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined1 *local_48;
  undefined8 local_40;
  undefined1 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_a8;
  local_58 = param_5;
  local_48 = &param_6;
  local_38 = &param_7;
  local_28 = &param_8;
  local_60 = 0x10;
  local_50 = 0x10;
  local_40 = 8;
  local_30 = 4;
  local_20 = 2;
  local_68 = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,6,local_78);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 1400072a8 =====

void wil_details_FeatureReporting_IncrementOpportunityInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar4 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar4 | 1;
    if ((uVar4 >> 0x16 & 1) != (uint)(param_2 == 5)) {
      uVar3 = uVar4 >> 0xf & 0x7f;
      if (uVar3 != 0) {
        param_4[1] = uVar3;
        uVar3 = 5;
        if (param_2 != 1) {
          uVar3 = 1;
        }
        uVar1 = uVar4 & 0xffc07fff | 1;
        param_4[2] = uVar3;
      }
      uVar3 = 0;
      if (param_2 == 5) {
        uVar3 = 0x400000;
      }
      uVar1 = uVar3 | uVar1 & 0xffbfffff;
    }
    uVar2 = uVar1 >> 0xf & 0x7f;
    uVar3 = uVar2 + 1;
    if ((0x7f < uVar3) || (uVar3 < uVar2)) {
      uVar3 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar4 == uVar2) {
      *param_1 = (uVar3 << 0xf ^ uVar1) & 0x3f8000 ^ uVar1;
      uVar1 = uVar4;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar4 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar4 & 1;
  return;
}



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140007380 =====

void wil_details_FeatureReporting_IncrementUsageInCache
               (uint *param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_1;
  do {
    uVar3 = uVar1;
    param_4[1] = 0;
    uVar1 = uVar3 | 1;
    if ((uVar3 >> 0xe & 1) != (uint)(param_2 == 4)) {
      uVar4 = uVar3 >> 5 & 0x1ff;
      if (uVar4 != 0) {
        param_4[1] = uVar4;
        param_4[2] = ~-(uint)(param_2 != 0) & 4;
        uVar1 = uVar3 & 0xffffc01f | 1;
      }
      uVar4 = 0;
      if (param_2 == 4) {
        uVar4 = 0x4000;
      }
      uVar1 = uVar4 | uVar1 & 0xffffbfff;
    }
    uVar2 = uVar1 >> 5 & 0x1ff;
    uVar4 = uVar2 + 1;
    if ((0x1ff < uVar4) || (uVar4 < uVar2)) {
      uVar4 = 1;
      param_4[2] = param_2;
      param_4[1] = uVar2;
    }
    LOCK();
    uVar2 = *param_1;
    if (uVar3 == uVar2) {
      *param_1 = (uVar4 << 5 ^ uVar1) & 0x3fe0 ^ uVar1;
      uVar1 = uVar3;
    }
    else {
      uVar1 = uVar2;
    }
    UNLOCK();
  } while (uVar3 != uVar2);
  param_4[4] = 0;
  *param_4 = ~uVar3 & 1;
  return;
}



===== wil_details_FeatureReporting_RecordUsageInCache @ 140007464 =====

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
LAB_1400075bc:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_1400075af:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_1400075bc;
      if (uVar5 == 5) goto LAB_1400075af;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 1400075e4 =====

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
              (0x3cdf870,&Feature_3130672440_logged_traits,0,uVar4,local_res18,0,0,1);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140007660 =====

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
                     (local_50,(uint *)&Feature_3130672440__private_reporting,param_3,
                      (uint)((ulonglong)param_2 >> 0x20));
  local_38 = *puVar2;
  uStack_34 = puVar2[1];
  uStack_30 = puVar2[2];
  uStack_2c = puVar2[3];
  local_28 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    local_68 = &local_38;
    (*g_wil_details_recordFeatureUsage)
              (0x3cdf870,param_3 & 0xffffffff,1,&Feature_3130672440__private_reporting);
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && ((int)param_3 != 0xfe)) {
    local_58._0_6_ = CONCAT24((short)(param_3 & 0xffffffff),0x3cdf870);
    uVar1 = (uint6)local_58;
    local_58 = (ulonglong)(uint6)local_58;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_58 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_58);
  }
  return (int)local_28 == 0;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 14000774c =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 14000785c =====

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
  if ((Feature_3130672440__private_featureState & 2) != 0) {
    uVar1 = Feature_3130672440__private_featureState;
    while ((uVar1 & 1) == (param_1 & 1)) {
      LOCK();
      bVar3 = uVar1 == Feature_3130672440__private_featureState;
      if (bVar3) {
        Feature_3130672440__private_featureState = uVar2 | uVar1;
      }
      else {
        uVar1 = Feature_3130672440__private_featureState;
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



===== wil_details_GetCurrentFeatureEnabledState @ 1400078b0 =====

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



===== wil_details_IsEnabledFallback @ 140007a10 =====

uint wil_details_IsEnabledFallback(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  ulonglong local_res18;
  
  local_res18 = (ulonglong)param_1 & 0xffffffff;
  if (((ulonglong)param_1 & 2) == 0) {
    puVar1 = &Feature_3130672440__private_featureState;
    local_res18 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                            (&Feature_3130672440__private_featureState,(ulonglong)param_1,
                             0x140015b88);
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



===== wil_details_MapReportingKind @ 140007aa0 =====

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



===== KmclpAllocateBounceBlock @ 140007b40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint KmclpAllocateBounceBlock(longlong param_1,undefined8 param_2,undefined1 param_3)

{
  longlong *plVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  undefined1 uVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong lVar10;
  longlong *plVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  uint uVar14;
  longlong *plVar15;
  uint uVar16;
  ulonglong uVar17;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  uint local_20;
  
  if (*(char *)(param_1 + 0xb51) == '\0') {
    return ~-(uint)(*(char *)(param_1 + 0xb50) != '\0') & 0xc00000bb;
  }
  plVar8 = (longlong *)ExAllocatePool2(0x40,0x48,0x636d6b56);
  if (plVar8 == (longlong *)0x0) {
    uVar14 = 0xc000009a;
  }
  else {
    local_20 = 4;
    local_28 = 1;
    lVar10 = MmAllocatePagesForMdlEx(0,0xffffffffffffffff,0);
    plVar8[8] = lVar10;
    if (lVar10 == 0) {
LAB_140007cc9:
      uVar14 = 0xc000009a;
    }
    else {
      iVar2 = *(int *)(lVar10 + 0x2c);
      plVar1 = plVar8 + 2;
      iVar3 = *(int *)(lVar10 + 0x20);
      uVar16 = *(uint *)(lVar10 + 0x28);
      plVar8[1] = (longlong)plVar8;
      *plVar8 = (longlong)plVar8;
      uVar17 = (ulonglong)uVar16 + 0xfff + (ulonglong)(iVar2 + iVar3 & 0xfff) >> 0xc;
      plVar8[3] = (longlong)plVar1;
      *plVar1 = (longlong)plVar1;
      uVar16 = (uint)uVar17;
      *(uint *)((longlong)plVar8 + 0x2c) = uVar16;
      *(undefined1 *)((longlong)plVar8 + 0x31) = param_3;
      if (*(char *)(param_1 + 0xb50) == '\0') {
LAB_140007c55:
        lVar10 = plVar8[8];
        plVar15 = (longlong *)(lVar10 + 0x30);
        if ((*(byte *)(lVar10 + 10) & 5) == 0) {
          local_20 = ExDefaultMdlProtection | 0x40000010;
          local_28 = 0;
          lVar10 = MmMapLockedPagesSpecifyCache(lVar10,0,1);
        }
        else {
          lVar10 = *(longlong *)(lVar10 + 0x18);
        }
        if (lVar10 != 0) {
          lVar9 = ExAllocatePool2(0x40,uVar17 * 0x28);
          plVar8[4] = lVar9;
          if (lVar9 != 0) {
            uVar14 = 0;
            if (uVar16 != 0) {
              lVar9 = 0;
              do {
                plVar11 = (longlong *)(plVar8[4] + lVar9);
                plVar11[1] = (longlong)plVar11;
                *plVar11 = (longlong)plVar11;
                lVar4 = *plVar15;
                plVar15 = plVar15 + 1;
                plVar11[2] = lVar4;
                plVar11[3] = (longlong)plVar8;
                plVar11[4] = (ulonglong)(uVar14 << 0xc) + lVar10;
                plVar5 = (longlong *)plVar8[3];
                if ((longlong *)*plVar5 != plVar1) goto LAB_140007e19;
                *plVar11 = (longlong)plVar1;
                uVar14 = uVar14 + 1;
                plVar11[1] = (longlong)plVar5;
                lVar9 = lVar9 + 0x28;
                *plVar5 = (longlong)plVar11;
                plVar8[3] = (longlong)plVar11;
              } while (uVar14 < uVar16);
            }
            if (*(char *)((longlong)plVar8 + 0x31) == '\0') {
              lVar10 = KeQueryUnbiasedInterruptTime();
              plVar8[7] = lVar10;
            }
            lVar10 = param_1 + 0x100;
            uVar7 = KeAcquireSpinLockRaiseToDpc(lVar10);
            puVar13 = auStack_48;
            lVar9 = param_1 + 0xb58;
            plVar11 = *(longlong **)(param_1 + 0xb60);
            if (*plVar11 != lVar9) {
LAB_140007e19:
              lVar9 = 3;
              pcVar6 = (code *)swi(0x29);
              uVar7 = (*pcVar6)();
              puVar13 = auStack_40;
            }
            *plVar8 = lVar9;
            plVar8[1] = (longlong)plVar11;
            *plVar11 = (longlong)plVar8;
            *(longlong **)(lVar9 + 8) = plVar8;
            *(undefined8 *)(puVar13 + -8) = 0x140007e3a;
            KeReleaseSpinLock(lVar10,uVar7);
            uVar14 = 0;
            lVar10 = 0x218;
            goto LAB_140007e46;
          }
        }
        goto LAB_140007cc9;
      }
      uVar14 = (**(code **)(param_1 + 0xa60))(*(undefined8 *)(param_1 + 0x940),plVar8[8],1);
      if (-1 < (int)uVar14) {
        *(undefined1 *)(plVar8 + 6) = 1;
        goto LAB_140007c55;
      }
    }
    if (plVar8[4] != 0) {
      ExFreePoolWithTag(plVar8[4],0x636d6b56);
      plVar8[4] = 0;
    }
    puVar12 = auStack_48;
    lVar10 = plVar8[8];
    if (lVar10 != 0) {
      if ((*(byte *)(lVar10 + 10) & 1) != 0) {
        MmUnmapLockedPages(*(undefined8 *)(lVar10 + 0x18),lVar10);
      }
      puVar12 = auStack_48;
      if ((char)plVar8[6] != '\0') {
        uVar14 = (**(code **)(param_1 + 0xa60))(*(undefined8 *)(param_1 + 0x940),plVar8[8],3);
        puVar12 = auStack_48;
        if ((int)uVar14 < 0) {
          pcVar6 = (code *)swi(0x29);
          (*pcVar6)(0x3a);
          puVar12 = auStack_40;
        }
        *(undefined1 *)(plVar8 + 6) = 0;
      }
      lVar10 = plVar8[8];
      *(undefined8 *)(puVar12 + -8) = 0x140007d4e;
      MmFreePagesFromMdl(lVar10);
      lVar10 = plVar8[8];
      *(undefined8 *)(puVar12 + -8) = 0x140007d60;
      ExFreePoolWithTag(lVar10,0);
    }
    *(undefined8 *)(puVar12 + -8) = 0x140007d74;
    ExFreePoolWithTag(plVar8,0x636d6b56);
  }
  lVar10 = 0x220;
LAB_140007e46:
  LOCK();
  *(longlong *)(lVar10 + param_1) = *(longlong *)(lVar10 + param_1) + 1;
  UNLOCK();
  return uVar14;
}



===== KmclpAllocateBounceList @ 140007e70 =====

int KmclpAllocateBounceList(longlong param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  int iVar13;
  ulonglong uVar14;
  undefined8 *puVar15;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  
  lVar5 = 0;
  *param_3 = 0;
  if (KmclPerformanceCounterTimingCounters != 0) {
    lVar5 = KeQueryPerformanceCounter(0);
  }
  puVar12 = auStack_38;
  puVar11 = auStack_38;
  puVar10 = auStack_38;
  puVar15 = (undefined8 *)0x0;
  do {
    if (param_2 == (undefined8 *)0x0) {
      *(longlong *)(param_1 + 0x230) = *(longlong *)(param_1 + 0x230) + 1;
      iVar13 = 0;
LAB_14000802e:
      if (KmclPerformanceCounterTimingCounters != 0) {
        *(undefined8 *)(puVar12 + -8) = 0x140008041;
        lVar7 = KeQueryPerformanceCounter(0);
        uVar14 = lVar7 - lVar5;
        if (*(ulonglong *)(param_1 + 0x248) < uVar14) {
          *(ulonglong *)(param_1 + 0x248) = uVar14;
        }
        if (uVar14 < *(ulonglong *)(param_1 + 0x250)) {
          *(ulonglong *)(param_1 + 0x250) = uVar14;
        }
        if (iVar13 < 0) {
          *(longlong *)(param_1 + 0x270) = *(longlong *)(param_1 + 0x270) + 1;
          *(ulonglong *)(param_1 + 0x278) = uVar14 + *(longlong *)(param_1 + 0x278);
        }
        else {
          *(longlong *)(param_1 + 0x268) = *(longlong *)(param_1 + 0x268) + 1;
          *(longlong *)(param_1 + 0x280) = *(longlong *)(param_1 + 0x280) + uVar14;
        }
      }
      return iVar13;
    }
    uVar14 = (ulonglong)*(uint *)(param_2 + 5) +
             (ulonglong)(*(int *)(param_2 + 4) + *(int *)((longlong)param_2 + 0x2c) & 0xfff) + 0xfff
             >> 0xc;
    iVar13 = (int)uVar14;
    puVar6 = (undefined8 *)ExAllocateFromNPagedLookasideList(param_1 + 0xb80);
    if (puVar6 == (undefined8 *)0x0) {
      iVar13 = -0x3fffff66;
LAB_140008008:
      puVar15 = (undefined8 *)*param_3;
      if (puVar15 != (undefined8 *)0x0) {
        *(undefined8 *)(puVar11 + -8) = 0x140008018;
        KmclpFreeBounceList(param_1,puVar15);
      }
      *param_3 = 0;
      *(longlong *)(param_1 + 0x238) = *(longlong *)(param_1 + 0x238) + 1;
      puVar12 = puVar11;
      goto LAB_14000802e;
    }
    *puVar6 = 0;
    puVar1 = puVar6 + 2;
    *(undefined4 *)(puVar6 + 1) = *(undefined4 *)(param_2 + 5);
    *(undefined4 *)((longlong)puVar6 + 0xc) = *(undefined4 *)((longlong)param_2 + 0x2c);
    puVar6[3] = puVar1;
    *puVar1 = puVar1;
    if (puVar15 == (undefined8 *)0x0) {
      *param_3 = puVar6;
    }
    else {
      *puVar15 = puVar6;
    }
    plVar2 = (longlong *)(param_1 + 0xb58);
    plVar8 = (longlong *)*plVar2;
    if (plVar8 != plVar2) {
      while (iVar13 = (int)uVar14, plVar8 != plVar2) {
        plVar9 = plVar8 + 2;
        while( true ) {
          plVar3 = (longlong *)*plVar9;
          iVar13 = (int)uVar14;
          if ((plVar3 == plVar9) || (iVar13 == 0)) break;
          *(int *)(plVar8 + 5) = (int)plVar8[5] + 1;
          plVar8[7] = 0;
          if (((longlong *)plVar3[1] != plVar9) ||
             (lVar7 = *plVar3, *(longlong **)(lVar7 + 8) != plVar3)) goto LAB_140007ff5;
          *plVar9 = lVar7;
          uVar14 = (ulonglong)(iVar13 - 1);
          *(longlong **)(lVar7 + 8) = plVar9;
          puVar15 = (undefined8 *)puVar6[3];
          if ((undefined8 *)*puVar15 != puVar1) goto LAB_140007ff5;
          *plVar3 = (longlong)puVar1;
          plVar3[1] = (longlong)puVar15;
          *puVar15 = plVar3;
          puVar6[3] = plVar3;
        }
        plVar9 = plVar8;
        if ((int)plVar8[5] == *(int *)((longlong)plVar8 + 0x2c)) {
          lVar7 = *plVar8;
          plVar9 = (longlong *)plVar8[1];
          if ((*(longlong **)(lVar7 + 8) == plVar8) && ((longlong *)*plVar9 == plVar8)) {
            *plVar9 = lVar7;
            *(longlong **)(lVar7 + 8) = plVar9;
            plVar3 = *(longlong **)(param_1 + 0xb70);
            if (*plVar3 == param_1 + 0xb68) {
              *plVar8 = param_1 + 0xb68;
              plVar8[1] = (longlong)plVar3;
              *plVar3 = (longlong)plVar8;
              *(longlong **)(param_1 + 0xb70) = plVar8;
              *(undefined1 *)((longlong)plVar8 + 0x32) = 1;
              goto LAB_140007fdd;
            }
          }
LAB_140007ff5:
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          puVar10 = auStack_30;
          goto LAB_140007ffc;
        }
LAB_140007fdd:
        if (iVar13 == 0) goto LAB_140007fed;
        plVar8 = (longlong *)*plVar9;
      }
    }
    if (iVar13 != 0) {
LAB_140007ffc:
      iVar13 = -0x3fffffe9;
      puVar11 = puVar10;
      goto LAB_140008008;
    }
LAB_140007fed:
    param_2 = (undefined8 *)*param_2;
    puVar15 = puVar6;
  } while( true );
}



===== KmclpFreeAllBounceBlocks @ 1400080c8 =====

void KmclpFreeAllBounceBlocks(longlong param_1)

{
  longlong ****pppplVar1;
  longlong ****pppplVar2;
  longlong ***ppplVar3;
  code *pcVar4;
  undefined1 uVar5;
  longlong ****local_18;
  longlong ****local_10;
  
  local_10 = (longlong ****)&local_18;
  local_18 = (longlong ****)&local_18;
  uVar5 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x100);
  pppplVar1 = (longlong ****)(param_1 + 0xb58);
  while (pppplVar2 = (longlong ****)*pppplVar1, pppplVar2 != pppplVar1) {
    if (((longlong ****)pppplVar2[1] != pppplVar1) ||
       (ppplVar3 = *pppplVar2, (longlong ****)ppplVar3[1] != pppplVar2)) goto LAB_140008194;
    *pppplVar1 = ppplVar3;
    ppplVar3[1] = (longlong **)pppplVar1;
    if ((longlong *****)*local_10 != &local_18) goto LAB_140008194;
    pppplVar2[1] = (longlong ***)local_10;
    *pppplVar2 = (longlong ***)&local_18;
    *local_10 = (longlong ***)pppplVar2;
    local_10 = pppplVar2;
  }
  KeReleaseSpinLock(param_1 + 0x100,CONCAT71((int7)((ulonglong)pppplVar1 >> 8),uVar5));
  while( true ) {
    pppplVar1 = local_18;
    if ((longlong *****)local_18 == &local_18) {
      return;
    }
    if (((longlong *****)local_18[1] != &local_18) ||
       (pppplVar2 = (longlong ****)*local_18, (longlong ****)pppplVar2[1] != local_18)) break;
    pppplVar2[1] = (longlong ***)&local_18;
    local_18 = pppplVar2;
    KmclpFreeBounceBlock(param_1,(longlong)pppplVar1);
  }
LAB_140008194:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  return;
}



===== KmclpFreeBounceBlock @ 1400081b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KmclpFreeBounceBlock(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  
  if (*(longlong *)(param_2 + 0x20) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x20),0x636d6b56);
    *(undefined8 *)(param_2 + 0x20) = 0;
  }
  lVar1 = *(longlong *)(param_2 + 0x40);
  if (lVar1 != 0) {
    if ((*(byte *)(lVar1 + 10) & 1) != 0) {
      MmUnmapLockedPages(*(undefined8 *)(lVar1 + 0x18),lVar1);
    }
    if (*(char *)(param_2 + 0x30) != '\0') {
      iVar2 = (**(code **)(param_1 + 0xa60))
                        (*(undefined8 *)(param_1 + 0x940),*(undefined8 *)(param_2 + 0x40),3);
      if (iVar2 < 0) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x53495650,0xf4e,param_1,param_2,0);
      }
      *(undefined1 *)(param_2 + 0x30) = 0;
    }
    MmFreePagesFromMdl(*(undefined8 *)(param_2 + 0x40));
    ExFreePoolWithTag(*(undefined8 *)(param_2 + 0x40),0);
  }
  ExFreePoolWithTag(param_2,0x636d6b56);
  LOCK();
  *(longlong *)(param_1 + 0x228) = *(longlong *)(param_1 + 0x228) + 1;
  UNLOCK();
  return;
}



===== KmclpFreeBounceList @ 1400082a8 =====

void KmclpFreeBounceList(longlong param_1,undefined8 *param_2)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  code *pcVar7;
  undefined8 uVar8;
  
joined_r0x0001400082ca:
  if (param_2 == (undefined8 *)0x0) {
    *(longlong *)(param_1 + 0x240) = *(longlong *)(param_1 + 0x240) + 1;
    return;
  }
  puVar2 = (undefined8 *)*param_2;
  plVar1 = param_2 + 2;
LAB_1400082da:
  do {
    plVar3 = (longlong *)*plVar1;
    if (plVar3 == plVar1) break;
    if (((longlong *)plVar3[1] != plVar1) || (lVar4 = *plVar3, *(longlong **)(lVar4 + 8) != plVar3))
    goto LAB_1400083ee;
    *plVar1 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar1;
    lVar4 = plVar3[3];
    plVar5 = *(longlong **)(lVar4 + 0x18);
    if (*plVar5 != lVar4 + 0x10) goto LAB_1400083ee;
    *plVar3 = lVar4 + 0x10;
    plVar3[1] = (longlong)plVar5;
    *plVar5 = (longlong)plVar3;
    *(longlong **)(lVar4 + 0x18) = plVar3;
    *(int *)(plVar3[3] + 0x28) = *(int *)(plVar3[3] + 0x28) + -1;
    if ((*(int *)(plVar3[3] + 0x28) == 0) && (*(char *)(plVar3[3] + 0x31) == '\0')) {
      uVar8 = KeQueryUnbiasedInterruptTime();
      *(undefined8 *)(plVar3[3] + 0x38) = uVar8;
    }
    plVar5 = (longlong *)plVar3[3];
    if (*(char *)((longlong)plVar5 + 0x32) != '\0') {
      lVar4 = *plVar5;
      if ((*(longlong **)(lVar4 + 8) == plVar5) &&
         (plVar6 = (longlong *)plVar5[1], (longlong *)*plVar6 == plVar5)) {
        *plVar6 = lVar4;
        *(longlong **)(lVar4 + 8) = plVar6;
        plVar5 = *(longlong **)(param_1 + 0xb60);
        plVar6 = (longlong *)plVar3[3];
        if (*plVar5 == param_1 + 0xb58) {
          *plVar6 = param_1 + 0xb58;
          plVar6[1] = (longlong)plVar5;
          *plVar5 = (longlong)plVar6;
          *(longlong **)(param_1 + 0xb60) = plVar6;
          *(undefined1 *)(plVar3[3] + 0x32) = 0;
          goto LAB_1400082da;
        }
      }
LAB_1400083ee:
      pcVar7 = (code *)swi(0x29);
      (*pcVar7)(3);
      pcVar7 = (code *)swi(3);
      (*pcVar7)();
      return;
    }
  } while( true );
  ExFreeToNPagedLookasideList(param_1 + 0xb80,param_2);
  param_2 = puVar2;
  goto joined_r0x0001400082ca;
}



===== KmclpFreeOldBounceBlocks @ 1400083fc =====

void KmclpFreeOldBounceBlocks(longlong param_1)

{
  longlong ***ppplVar1;
  longlong ***ppplVar2;
  code *pcVar3;
  undefined1 uVar4;
  longlong lVar5;
  longlong ****pppplVar6;
  longlong ****pppplVar7;
  longlong ****local_18;
  longlong ****local_10;
  
  local_10 = (longlong ****)&local_18;
  local_18 = (longlong ****)&local_18;
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x100);
  lVar5 = KeQueryUnbiasedInterruptTime();
  pppplVar7 = *(longlong *****)(param_1 + 0xb58);
  while (pppplVar7 != (longlong ****)(param_1 + 0xb58)) {
    pppplVar6 = (longlong ****)0x0;
    if ((pppplVar7[7] != (longlong ***)0x0) &&
       (600000000 < (ulonglong)(lVar5 - (longlong)pppplVar7[7]))) {
      pppplVar6 = pppplVar7;
    }
    pppplVar7 = (longlong ****)*pppplVar7;
    if (pppplVar6 != (longlong ****)0x0) {
      ppplVar1 = *pppplVar6;
      if (((longlong ****)ppplVar1[1] != pppplVar6) ||
         (ppplVar2 = pppplVar6[1], (longlong ****)*ppplVar2 != pppplVar6)) goto LAB_140008502;
      *ppplVar2 = (longlong **)ppplVar1;
      ppplVar1[1] = (longlong **)ppplVar2;
      if ((longlong *****)*local_10 != &local_18) goto LAB_140008502;
      pppplVar6[1] = (longlong ***)local_10;
      *pppplVar6 = (longlong ***)&local_18;
      *local_10 = (longlong ***)pppplVar6;
      local_10 = pppplVar6;
    }
  }
  KeReleaseSpinLock(param_1 + 0x100,uVar4);
  while( true ) {
    pppplVar7 = local_18;
    if ((longlong *****)local_18 == &local_18) {
      return;
    }
    if (((longlong *****)local_18[1] != &local_18) ||
       (pppplVar6 = (longlong ****)*local_18, (longlong ****)pppplVar6[1] != local_18)) break;
    pppplVar6[1] = (longlong ***)&local_18;
    local_18 = pppplVar6;
    KmclpFreeBounceBlock(param_1,(longlong)pppplVar7);
  }
LAB_140008502:
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return;
}



===== OutCancelPacket @ 140008528 =====

void OutCancelPacket(longlong *param_1,longlong param_2)

{
  undefined1 uVar1;
  bool bVar2;
  
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x58);
  KeAcquireSpinLockAtDpcLevel(param_1 + 0x20);
  bVar2 = *(int *)(param_2 + 0x18) == 2;
  if (bVar2) {
    OutpDequeuePacket((longlong)param_1,(longlong *)(param_2 + 0x90));
    OutpTransitionPacketToReadyToComplete(param_1,param_2);
  }
  KeReleaseSpinLockFromDpcLevel(param_1 + 0x20);
  KeReleaseSpinLock(param_1 + 0x58,uVar1);
  if (bVar2) {
    OutCompletePacketToClient(param_2,0xc0000120,0);
  }
  return;
}



===== OutCompletePacketToClient @ 1400085f4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void OutCompletePacketToClient(longlong param_1,ulonglong param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x18) = 1;
  *(undefined1 *)(param_1 + 0x3d) = 0;
  *(undefined4 *)(param_1 + 0x74) = param_3;
  if ((*(byte *)(param_1 + 0x3e) & 0x40) == 0) {
    (**(code **)(param_1 + 0x58))(param_1,param_2,*(undefined8 *)(param_1 + 0x68),param_3);
  }
  else {
    (**(code **)(param_1 + 0x58))
              (param_1,*(undefined8 *)(param_1 + 0x60),param_2 & 0xffffffff,
               *(undefined8 *)(param_1 + 0x68),param_3);
  }
  return;
}



===== OutCopyAndSendPacket @ 140008648 =====

void OutCopyAndSendPacket
               (ulonglong param_1,undefined8 *param_2,uint *param_3,undefined8 param_4,char param_5,
               uint param_6)

{
  uint uVar1;
  bool bVar2;
  ulonglong uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0xac);
  uVar3 = 0;
  bVar2 = false;
  while( true ) {
    if (bVar2) {
      OutSendPacket(param_1,param_1 + 0xf0,(int)uVar3,param_5,param_6 & 0xfffffffe);
      return;
    }
    uVar1 = *param_3;
    if (uVar4 < uVar1) break;
    memmove((void *)(uVar3 + 0xf0 + param_1),(void *)*param_2,(ulonglong)uVar1);
    uVar3 = (ulonglong)((int)uVar3 + uVar1);
    uVar4 = uVar4 - uVar1;
    bVar2 = true;
  }
  return;
}



===== OutInitializePacket @ 1400086fc =====

void OutInitializePacket(undefined8 param_1,longlong param_2,int param_3,undefined8 param_4)

{
  *(undefined8 *)(param_2 + 0x10) = param_1;
  *(undefined8 *)(param_2 + 0x18) = 1;
  *(longlong *)(param_2 + 0x68) = param_2 + 0xf0;
  *(undefined8 *)(param_2 + 0x20) = 0;
  *(undefined8 *)(param_2 + 0x28) = 0;
  *(undefined4 *)(param_2 + 0xa0) = 1;
  *(undefined2 *)(param_2 + 0x3d) = 0;
  *(int *)(param_2 + 0xac) = param_3 + -0xf0;
  *(int *)(param_2 + 0x70) = param_3 + -0xf0;
  *(undefined8 *)(param_2 + 0x88) = 0;
  *(undefined8 *)(param_2 + 0x78) = 0;
  *(undefined8 *)(param_2 + 0x80) = 0;
  *(undefined8 *)(param_2 + 0x58) = param_4;
  return;
}



===== OutInitializeQueue @ 14000875c =====

undefined8 OutInitializeQueue(longlong *param_1)

{
  longlong *plVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 uVar5;
  
  uVar5 = 0;
  *(undefined4 *)(param_1 + 0x21) = 0;
  KeInitializeSpinLock(param_1 + 0x20);
  KeInitializeSpinLock(param_1 + 0x58);
  plVar1 = param_1 + 0x22;
  param_1[0x23] = (longlong)plVar1;
  *plVar1 = (longlong)plVar1;
  KeInitializeTimer(param_1 + 0x69);
  KeInitializeDpc(param_1 + 0x71,OutpPollingDpcRoutine,param_1);
  KeInitializeDpc(param_1 + 0x79,OutpPollingDpcRoutine,param_1);
  ExInitializeNPagedLookasideList
            (param_1 + 0x28,0,0,ExDefaultNonPagedPoolType | 0x200,
             (ulonglong)*(uint *)(*param_1 + 0x6c8) + (ulonglong)*(uint *)(*param_1 + 0x6d8) + 0xf0,
             0x756f6b56,0);
  *(undefined1 *)(param_1 + 0x38) = 1;
  uVar2 = *(uint *)(*param_1 + 0x6c4);
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  uVar4 = 0x4000;
  if (0x4000 < uVar2) {
    uVar4 = uVar2;
  }
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  *(uint *)((longlong)param_1 + 0x2d4) = uVar4;
  param_1[0x59] = (longlong)(param_1 + 0x5d);
  param_1[0x5c] = 0x40;
  *(undefined4 *)(param_1 + 0x5b) = 0x636d6b56;
  *(undefined4 *)(param_1 + 0x5a) = 1;
  if (*(char *)(*param_1 + 0xb51) != '\0') {
    lVar3 = MmAllocateMappingAddress(0x1000,0x636d6b56);
    param_1[0x51] = lVar3;
    if (lVar3 != 0) {
      lVar3 = IoAllocateMdl(0,0x1000,0,0,0);
      param_1[0x52] = lVar3;
      if (lVar3 != 0) {
        lVar3 = MmAllocateMappingAddress(0x1000,0x636d6b56);
        param_1[0x5f] = lVar3;
        if (lVar3 != 0) {
          lVar3 = IoAllocateMdl(0,0x1000,0,0,0);
          param_1[0x60] = lVar3;
          if (lVar3 != 0) {
            return 0;
          }
        }
      }
    }
    uVar5 = 0xc000009a;
    OutUninitializeQueue((longlong)param_1);
  }
  return uVar5;
}



===== OutPacketAddMoreBounceWorkerRoutine @ 140008980 =====

void OutPacketAddMoreBounceWorkerRoutine(undefined8 param_1,ulonglong *param_2)

{
  ulonglong *puVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined1 local_res10 [8];
  undefined8 ****local_18;
  undefined8 ****local_10;
  
  uVar2 = *(uint *)(*param_2 + 0x7b8);
  uVar3 = (ulonglong)uVar2;
  if (uVar2 < 0x40000) {
    uVar3 = 0x40000;
  }
  KmclpAllocateBounceBlock(*param_2,uVar3,0);
  puVar1 = param_2 + 0x20;
  local_res10[0] = KeAcquireSpinLockRaiseToDpc(puVar1);
  if ((int)param_2[0x21] == 5) {
    local_10 = &local_18;
    *(undefined4 *)(param_2 + 0x21) = 2;
    local_18 = &local_18;
    OutpProcessQueueLocked(param_2,(ulonglong)&local_18,local_res10);
    if ((undefined8 *****)local_18 != &local_18) {
      KeReleaseSpinLock(puVar1,local_res10[0]);
      OutpCompletePacketListToClient((longlong *)&local_18);
      return;
    }
  }
  else {
    KeSetEvent(param_2[0x82],0,0);
    param_2[0x82] = 0;
  }
  KeReleaseSpinLock(puVar1,local_res10[0]);
  return;
}



===== OutPurgeQueue @ 140008a6c =====

void OutPurgeQueue(longlong *param_1)

{
  code *pcVar1;
  longlong lVar2;
  undefined8 ***pppuVar3;
  uint local_res8 [2];
  undefined8 ***local_18;
  undefined8 ***local_10;
  
  local_18 = &local_18;
  local_10 = &local_18;
  while (pppuVar3 = (undefined8 ***)param_1[0x22], pppuVar3 != (undefined8 ***)(param_1 + 0x22)) {
    OutpDequeuePacket((longlong)param_1,(longlong *)pppuVar3);
    if (*(int *)(pppuVar3 + 2) == 1) {
      *(undefined4 *)(pppuVar3 + 3) = 0xc00002b6;
      OutpTransitionPacketToReadyToComplete(param_1,(longlong)(pppuVar3 + -0x12));
    }
    if ((undefined8 ****)*local_10 != &local_18) goto LAB_140008b6f;
    pppuVar3[1] = local_10;
    *pppuVar3 = &local_18;
    *local_10 = pppuVar3;
    local_10 = pppuVar3;
  }
  local_res8[0] = 0;
  while( true ) {
    lVar2 = DvGetNextHandleEntry(param_1 + 0x59,local_res8);
    if (lVar2 == 0) {
      OutpCompletePacketListToClient((longlong *)&local_18);
      return;
    }
    *(undefined4 *)(lVar2 + 0xa8) = 0xc00002b6;
    OutpTransitionPacketToReadyToComplete(param_1,lVar2);
    pppuVar3 = (undefined8 ***)(lVar2 + 0x90);
    if ((undefined8 ****)*local_10 != &local_18) break;
    *(undefined8 ****)(lVar2 + 0x98) = local_10;
    *pppuVar3 = &local_18;
    *local_10 = pppuVar3;
    local_10 = pppuVar3;
  }
LAB_140008b6f:
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== OutStopQueue @ 140008b7c =====

void OutStopQueue(longlong param_1)

{
  undefined1 uVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  
  local_58 = 0;
  local_40 = 0;
  local_28 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_38 = 0;
  uStack_30 = 0;
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x100);
  bVar3 = *(int *)(param_1 + 0x108) == 5;
  if (bVar3) {
    KeInitializeEvent(&local_50,1);
    *(undefined8 **)(param_1 + 0x410) = &local_50;
  }
  bVar4 = *(int *)(param_1 + 0x418) != 0;
  if (bVar4) {
    KeInitializeEvent(&local_38,1);
    *(undefined8 **)(param_1 + 0x420) = &local_38;
  }
  *(undefined4 *)(param_1 + 0x108) = 0;
  cVar2 = KeCancelTimer(param_1 + 0x348);
  if (cVar2 != '\0') {
    *(int *)(param_1 + 0x408) = *(int *)(param_1 + 0x408) + -1;
  }
  bVar5 = *(int *)(param_1 + 0x408) != 0;
  if (bVar5) {
    KeInitializeEvent(&local_68,1);
    *(undefined8 **)(param_1 + 0x340) = &local_68;
  }
  KeReleaseSpinLock(param_1 + 0x100,uVar1);
  if (bVar5) {
    KeWaitForSingleObject(&local_68,0,0,0,0);
  }
  if (bVar3) {
    KeWaitForSingleObject(&local_50,0,0,0,0);
  }
  if (bVar4) {
    KeWaitForSingleObject(&local_38,0,0,0,0);
  }
  return;
}



===== OutUninitializeQueue @ 140008d30 =====

void OutUninitializeQueue(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x2c8);
  if ((lVar1 != param_1 + 0x2e8) && (lVar1 != 0)) {
    ExFreePoolWithTag(lVar1,*(undefined4 *)(param_1 + 0x2d8));
  }
  *(undefined8 *)(param_1 + 0x2c8) = 0;
  if (*(longlong *)(param_1 + 0x2f0) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x2f0),*(undefined4 *)(param_1 + 0x2d8));
    *(undefined8 *)(param_1 + 0x2f0) = 0;
  }
  if (*(char *)(param_1 + 0x1c0) != '\0') {
    ExDeleteNPagedLookasideList(param_1 + 0x140);
    *(undefined1 *)(param_1 + 0x1c0) = 0;
  }
  if (*(longlong *)(param_1 + 0x288) != 0) {
    MmFreeMappingAddress(*(longlong *)(param_1 + 0x288),0x636d6b56);
    *(undefined8 *)(param_1 + 0x288) = 0;
  }
  if (*(longlong *)(param_1 + 0x290) != 0) {
    IoFreeMdl();
    *(undefined8 *)(param_1 + 0x290) = 0;
  }
  if (*(longlong *)(param_1 + 0x2f8) != 0) {
    MmFreeMappingAddress(*(longlong *)(param_1 + 0x2f8),0x636d6b56);
    *(undefined8 *)(param_1 + 0x2f8) = 0;
  }
  if (*(longlong *)(param_1 + 0x300) != 0) {
    IoFreeMdl();
    *(undefined8 *)(param_1 + 0x300) = 0;
  }
  return;
}



===== OutpAcquireReservedMapping @ 140008e4c =====

void OutpAcquireReservedMapping
               (longlong param_1,char param_2,undefined8 param_3,undefined8 param_4,uint param_5)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  if (param_2 == '\0') {
    puVar3 = *(undefined8 **)(param_1 + 0x290);
    uVar2 = *(undefined8 *)(param_1 + 0x288);
  }
  else {
    puVar3 = *(undefined8 **)(param_1 + 0x300);
    uVar2 = *(undefined8 *)(param_1 + 0x2f8);
  }
  *puVar3 = 0;
  *(undefined2 *)((longlong)puVar3 + 10) = 0;
  puVar3[4] = 0;
  *(undefined4 *)((longlong)puVar3 + 0x2c) = 0;
  *(uint *)(puVar3 + 5) = param_5;
  *(short *)(puVar3 + 1) = ((short)((ulonglong)param_5 + 0xfff >> 0xc) + 6) * 8;
  IoBuildPartialMdl(param_3,puVar3,param_4);
  lVar1 = MmMapLockedPagesWithReservedMapping(uVar2,0x636d6b56,puVar3,1);
  if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x53495650,0x361,param_1,uVar2,0);
  }
  return;
}



===== OutpAllocateHandle @ 140008f30 =====

ulonglong OutpAllocateHandle(longlong param_1,ulonglong param_2)

{
  ulonglong uVar1;
  
  uVar1 = DvAllocateHandleEntryWithoutResizing((undefined8 *)(param_1 + 0x2c8),param_2);
  if ((int)uVar1 == 0) {
    *(undefined4 *)(param_1 + 0x108) = 4;
    OutpEnqueuePollingDpc(param_1);
  }
  else {
    *(int *)(param_2 + 0x1c) = (int)uVar1;
  }
  return uVar1 & 0xffffffff;
}



===== OutpCompletePacketListToClient @ 140008f74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void OutpCompletePacketListToClient(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  
  while( true ) {
    plVar1 = (longlong *)*param_1;
    if (plVar1 == param_1) {
      return;
    }
    if (((longlong *)plVar1[1] != param_1) || (lVar2 = *plVar1, *(longlong **)(lVar2 + 8) != plVar1)
       ) break;
    *param_1 = lVar2;
    *(longlong **)(lVar2 + 8) = param_1;
    if ((int)plVar1[2] == 2) {
      (*(code *)plVar1[4])();
    }
    else {
      OutCompletePacketToClient((longlong)(plVar1 + -0x12),(ulonglong)*(uint *)(plVar1 + 3),0);
    }
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  return;
}



===== OutpDequeuePacket @ 140008fd4 =====

void OutpDequeuePacket(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong lVar4;
  bool bVar5;
  
  lVar1 = *param_2;
  if ((*(longlong **)(lVar1 + 8) != param_2) ||
     (plVar2 = (longlong *)param_2[1], (longlong *)*plVar2 != param_2)) {
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  *plVar2 = lVar1;
  *(longlong **)(lVar1 + 8) = plVar2;
  if ((*(longlong **)(param_1 + 0x110) == (longlong *)(param_1 + 0x110)) &&
     (*(int *)(param_1 + 0x108) != 0)) {
    *(undefined4 *)(param_1 + 0x108) = 1;
  }
  if ((((int)param_2[2] == 1) && (param_2[-3] != 0)) && (KmclPerformanceCounterTimingCounters != 0))
  {
    lVar4 = KeQueryPerformanceCounter(0);
    lVar1 = param_2[-3];
    bVar5 = KmclPerformanceCounterTimingCounters != 0;
    param_2[-3] = lVar4 - lVar1;
    if (bVar5) {
      *(longlong *)(param_1 + 0x1f0) = *(longlong *)(param_1 + 0x1f0) + (lVar4 - lVar1);
    }
  }
  return;
}



===== OutpEnqueuePacket @ 140009074 =====

void OutpEnqueuePacket(longlong param_1,longlong *param_2)

{
  code *pcVar1;
  longlong lVar2;
  longlong *plVar3;
  
  if (((int)param_2[2] == 1) && (KmclPerformanceCounterTimingCounters != 0)) {
    lVar2 = KeQueryPerformanceCounter(0);
    param_2[-3] = lVar2;
  }
  lVar2 = param_1 + 0x110;
  plVar3 = *(longlong **)(param_1 + 0x118);
  if (*plVar3 != lVar2) {
    plVar3 = (longlong *)0x3;
    pcVar1 = (code *)swi(0x29);
    lVar2 = (*pcVar1)();
  }
  *param_2 = lVar2;
  param_2[1] = (longlong)plVar3;
  *plVar3 = (longlong)param_2;
  *(longlong **)(lVar2 + 8) = param_2;
  return;
}



===== OutpEnqueuePollingDpc @ 1400090e0 =====

void OutpEnqueuePollingDpc(longlong param_1)

{
  char cVar1;
  
  cVar1 = KeInsertQueueDpc(param_1 + 0x3c8,0,0);
  if (cVar1 != '\0') {
    *(int *)(param_1 + 0x408) = *(int *)(param_1 + 0x408) + 1;
  }
  return;
}



===== OutpEnqueuePollingTimer @ 140009118 =====

void OutpEnqueuePollingTimer(longlong param_1)

{
  char cVar1;
  
  cVar1 = KeSetTimer(param_1 + 0x348,0xfffffffffd050f80,param_1 + 0x388);
  if (cVar1 == '\0') {
    *(int *)(param_1 + 0x408) = *(int *)(param_1 + 0x408) + 1;
  }
  return;
}



===== OutpPacketCopyToBouncePagesCycleLock @ 14000915c =====

void OutpPacketCopyToBouncePagesCycleLock(longlong param_1,longlong param_2,undefined1 *param_3)

{
  longlong lVar1;
  int *piVar2;
  undefined1 uVar3;
  
  *(int *)(param_1 + 0x418) = *(int *)(param_1 + 0x418) + 1;
  lVar1 = param_1 + 0x100;
  if (param_3 == (undefined1 *)0x0) {
    KeReleaseSpinLockFromDpcLevel(lVar1);
  }
  else {
    KeReleaseSpinLock(lVar1,*param_3);
  }
  OutpPacketCopyBouncePagesToMdl(param_1,param_2,'\0');
  if (param_3 == (undefined1 *)0x0) {
    KeAcquireSpinLockAtDpcLevel(lVar1);
  }
  else {
    uVar3 = KeAcquireSpinLockRaiseToDpc();
    *param_3 = uVar3;
  }
  piVar2 = (int *)(param_1 + 0x418);
  *piVar2 = *piVar2 + -1;
  if ((*piVar2 == 0) && (*(longlong *)(param_1 + 0x420) != 0)) {
    KeSetEvent(*(longlong *)(param_1 + 0x420),0,0);
  }
  return;
}



===== OutpPollingDpcRoutine @ 140009220 =====

void OutpPollingDpcRoutine(undefined8 param_1,ulonglong *param_2)

{
  ulonglong *puVar1;
  ulonglong *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 ***local_18;
  undefined8 ***local_10;
  
  local_10 = &local_18;
  puVar1 = param_2 + 0x20;
  local_18 = &local_18;
  KeAcquireSpinLockAtDpcLevel(puVar1);
  iVar3 = (int)param_2[0x21];
  if (iVar3 == 4) {
    KeReleaseSpinLockFromDpcLevel(puVar1);
    KeAcquireSpinLockAtDpcLevel(param_2 + 0x58);
    KeAcquireSpinLockAtDpcLevel(puVar1);
    uVar4 = DvEnsureFreeHandleEntries(param_2 + 0x59);
    *(int *)(param_2 + 0x3a) = (int)param_2[0x5a];
    KeReleaseSpinLockFromDpcLevel(param_2 + 0x58);
    if ((int)uVar4 < 0) {
      OutpEnqueuePollingTimer((longlong)param_2);
      goto LAB_140009337;
    }
    iVar3 = (int)param_2[0x21];
    if (iVar3 != 4) goto LAB_1400092ee;
    *(undefined4 *)(param_2 + 0x21) = 2;
  }
  else {
LAB_1400092ee:
    if (iVar3 != 2) goto LAB_140009337;
  }
  OutpProcessQueueLocked(param_2,(ulonglong)&local_18,(undefined1 *)0x0);
  if ((undefined8 ****)local_18 != &local_18) {
    KeReleaseSpinLockFromDpcLevel(puVar1);
    OutpCompletePacketListToClient((longlong *)&local_18);
    KeAcquireSpinLockAtDpcLevel(puVar1);
  }
LAB_140009337:
  puVar2 = param_2 + 0x81;
  *(int *)puVar2 = (int)*puVar2 + -1;
  if (((int)*puVar2 == 0) && (param_2[0x68] != 0)) {
    KeSetEvent(param_2[0x68],0,0);
    param_2[0x68] = 0;
  }
  KeReleaseSpinLockFromDpcLevel(puVar1);
  return;
}



===== OutpPreparePacketForIsolation @ 140009390 =====

int OutpPreparePacketForIsolation(longlong *param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  if ((KmclPerformanceCounterTimingCounters != 0) && (*(longlong *)(param_2 + 0x88) == 0)) {
    uVar2 = KeQueryPerformanceCounter(0);
    *(undefined8 *)(param_2 + 0x88) = uVar2;
  }
  iVar1 = KmclpAllocateBounceList
                    (*param_1,*(undefined8 **)(param_2 + 0x40),(undefined8 *)(param_2 + 0x50));
  if (-1 < iVar1) {
    if (KmclPerformanceCounterTimingCounters != 0) {
      lVar3 = KeQueryPerformanceCounter(0);
      *(longlong *)(*param_1 + 600) =
           *(longlong *)(*param_1 + 600) + (lVar3 - *(longlong *)(param_2 + 0x88));
    }
    iVar1 = 0;
  }
  return iVar1;
}



===== OutpProcessQueueLocked @ 14000941c =====

void OutpProcessQueueLocked(ulonglong *param_1,ulonglong param_2,undefined1 *param_3)

{
  ulonglong *puVar1;
  ulonglong *puVar2;
  code *pcVar3;
  byte bVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong *puVar7;
  ulonglong *puVar8;
  char cVar9;
  
  if ((int)param_1[0x21] == 3) {
    return;
  }
LAB_140009456:
  puVar1 = (ulonglong *)param_1[0x22];
  if (puVar1 == param_1 + 0x22) {
    return;
  }
  if ((int)puVar1[2] == 1) goto code_r0x00014000946c;
  bVar4 = OutpTrySendCompletionPacket
                    ((longlong *)param_1,puVar1[5],(void *)puVar1[6],(uint)puVar1[3]);
  if (bVar4 == 0) {
    return;
  }
  OutpDequeuePacket((longlong)param_1,(longlong *)puVar1);
  goto LAB_14000956b;
code_r0x00014000946c:
  puVar2 = puVar1 + -0x12;
  if ((int)puVar1[-0xf] != 2) goto LAB_140009456;
  cVar9 = *(char *)((longlong)puVar1 + -0x54);
  if (((cVar9 != '\0') && (*(int *)((longlong)puVar1 + -0x74) == 0)) &&
     (uVar6 = OutpAllocateHandle((longlong)param_1,(ulonglong)puVar2), (int)uVar6 == 0)) {
    *(undefined4 *)(param_1 + 0x21) = 4;
    OutpEnqueuePollingDpc((longlong)param_1);
    return;
  }
  puVar7 = param_1;
  puVar8 = puVar2;
  uVar6 = OutpPacketNeedsIsolation(param_1,(longlong)puVar2);
  if ((char)uVar6 == '\0') {
LAB_1400094f8:
    uVar6 = OutpTrySendControlPacket
                      ((longlong *)param_1,(ulonglong)*(uint *)((longlong)puVar1 + -0x74),
                       (longlong)puVar2,cVar9);
    iVar5 = (int)uVar6;
    *(int *)(puVar1 + 3) = iVar5;
    if (iVar5 != -0x3ffffff3) {
      if (iVar5 < 0) {
        return;
      }
      goto LAB_14000951f;
    }
  }
  else {
    iVar5 = OutpPreparePacketForIsolation((longlong *)puVar7,(longlong)puVar8);
    if (iVar5 == -0x3fffffe9) {
      *(undefined4 *)(param_1 + 0x21) = 5;
      IoQueueWorkItem(*(undefined8 *)(*param_1 + 0xb78),OutPacketAddMoreBounceWorkerRoutine,1,
                      param_1);
      return;
    }
    if (-1 < iVar5) {
      *(undefined4 *)(puVar1 + -0xf) = 5;
      *(undefined4 *)(param_1 + 0x21) = 3;
      OutpPacketCopyToBouncePagesCycleLock((longlong)param_1,(longlong)puVar2,param_3);
      *(undefined4 *)(puVar1 + -0xf) = 2;
      if ((int)param_1[0x21] != 3) {
        return;
      }
      *(undefined4 *)(param_1 + 0x21) = 2;
      goto LAB_1400094f8;
    }
  }
  cVar9 = '\0';
LAB_14000951f:
  OutpDequeuePacket((longlong)param_1,(longlong *)puVar1);
  if (cVar9 == '\0') {
    OutpTransitionPacketToReadyToComplete((longlong *)param_1,(longlong)puVar2);
LAB_14000956b:
    puVar2 = *(ulonglong **)(param_2 + 8);
    if (*puVar2 != param_2) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    *puVar1 = param_2;
    puVar1[1] = (ulonglong)puVar2;
    *puVar2 = (ulonglong)puVar1;
    *(ulonglong **)(param_2 + 8) = puVar1;
  }
  else {
    *(undefined4 *)(puVar1 + -0xf) = 3;
  }
  goto LAB_140009456;
}



===== OutpReleaseReservedMapping @ 1400095f8 =====

void OutpReleaseReservedMapping(longlong param_1,char param_2)

{
  undefined8 uVar1;
  longlong lVar2;
  
  if (param_2 == '\0') {
    lVar2 = *(longlong *)(param_1 + 0x290);
    uVar1 = *(undefined8 *)(param_1 + 0x288);
  }
  else {
    lVar2 = *(longlong *)(param_1 + 0x300);
    uVar1 = *(undefined8 *)(param_1 + 0x2f8);
  }
  MmUnmapReservedMapping(uVar1,0x636d6b56,lVar2);
  if ((*(byte *)(lVar2 + 10) & 0x20) != 0) {
    MmUnmapLockedPages(*(undefined8 *)(lVar2 + 0x18),lVar2);
  }
  return;
}



===== KmclpFreeCompletionRoutine @ 140009660 =====

void KmclpFreeCompletionRoutine(longlong param_1)

{
  VmbPacketFree(param_1);
  return;
}



===== KmclpSynchronousPacketCompletionRoutine @ 140009680 =====

void KmclpSynchronousPacketCompletionRoutine(longlong param_1,undefined4 param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined1 *puVar3;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [32];
  
  puVar3 = auStack_28;
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)();
    puVar3 = auStack_20;
  }
  lVar1 = *(longlong *)(param_1 + 0x20);
  *(undefined4 *)(lVar1 + 0x18) = param_2;
  *(undefined8 *)(puVar3 + -8) = 0x1400096a8;
  KeSetEvent(lVar1,0,0);
  return;
}



===== VmbChannelSendMultipleBufferSynchronousRequest @ 1400096bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void VmbChannelSendMultipleBufferSynchronousRequest
               (longlong *param_1,undefined8 *param_2,uint *param_3,undefined8 param_4,
               longlong param_5,uint param_6,undefined8 param_7,undefined4 *param_8,
               longlong *param_9)

{
  int extraout_EAX;
  int iVar1;
  code *pcVar2;
  uint uVar3;
  ulonglong uVar4;
  bool bVar5;
  undefined1 auStackY_188 [32];
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined1 local_128 [16];
  undefined8 *local_118;
  undefined8 local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_188;
  local_138 = 0;
  uStack_130 = 0;
  memset(local_128,0,0xe0);
  local_158 = 0;
  uStack_150 = 0;
  local_148 = 0;
  uStack_140 = 0;
  KeInitializeEvent(&local_158,1);
  pcVar2 = KmclpSynchronousPacketCompletionRoutine;
  OutInitializePacket(param_1,(longlong)&local_138,0xf0,KmclpSynchronousPacketCompletionRoutine);
  uVar4 = (ulonglong)param_6;
  local_118 = &local_158;
  bVar5 = (param_6 & 1) != 0;
  if (bVar5) {
    local_c8 = *param_8;
    local_d0 = param_7;
  }
  uVar3 = 2;
  if ((param_9 != (longlong *)0x0) && (uVar3 = 2, *param_9 == 0)) {
    uVar3 = 6;
  }
  if (param_5 != 0) {
    pcVar2 = (code *)0x0;
    OutSetupGpaDirectPacket((longlong)&local_138,param_5,0,0,param_6 & 0xfffffffd);
  }
  if ((uVar4 & 4) == 0) {
    OutSendPacket((ulonglong)&local_138,*param_2,*param_3,bVar5,uVar3);
    iVar1 = extraout_EAX;
  }
  else {
    iVar1 = OutCopyAndSendPacket((ulonglong)&local_138,param_2,param_3,pcVar2,bVar5,uVar3);
  }
  if (iVar1 == 0x103) {
    iVar1 = KeWaitForSingleObject(&local_158,0,0,0);
    if (iVar1 == 0x102) {
      OutCancelPacket(param_1,(longlong)&local_138);
      KeWaitForSingleObject(&local_158,0,0,0);
    }
    if (param_8 != (undefined4 *)0x0) {
      *param_8 = local_c4;
    }
  }
  return;
}



===== VmbChannelSendSynchronousRequest @ 140009890 =====

void VmbChannelSendSynchronousRequest
               (longlong *param_1,undefined8 param_2,uint param_3,undefined8 param_4,uint param_5,
               undefined8 param_6,undefined4 *param_7,longlong *param_8)

{
  undefined8 local_res10;
  uint local_res18 [4];
  
                    /* 0x9890  56  VmbChannelSendSynchronousRequest */
  local_res10 = param_2;
  local_res18[0] = param_3;
  VmbChannelSendMultipleBufferSynchronousRequest
            (param_1,&local_res10,local_res18,param_4,param_4,param_5,param_6,param_7,param_8);
  return;
}



===== VmbPacketAddTransferPageRanges @ 1400098f0 =====

undefined8
VmbPacketAddTransferPageRanges
          (longlong param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  
                    /* 0x98f0  73  VmbPacketAddTransferPageRanges */
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  *(byte *)(param_1 + 0x3e) = *(byte *)(param_1 + 0x3e) | 4;
  *(undefined8 *)(param_1 + 0x40) = param_4;
  *(undefined2 *)(param_1 + 0x48) = param_2;
  return 0;
}



===== VmbPacketAllocate @ 140009920 =====

longlong VmbPacketAllocate(longlong *param_1)

{
  longlong lVar1;
  
                    /* 0x9920  74  VmbPacketAllocate */
  lVar1 = ExAllocateFromNPagedLookasideList(param_1 + 0x28);
  if (lVar1 != 0) {
    OutInitializePacket(param_1,lVar1,*(int *)(*param_1 + 0x6c8) + 0xf0,KmclpFreeCompletionRoutine);
    if (*(int *)(*param_1 + 0x6d8) != 0) {
      *(ulonglong *)(lVar1 + 0x28) = (ulonglong)*(uint *)(lVar1 + 0xac) + 0xf0 + lVar1;
    }
    *(byte *)(lVar1 + 0x3e) = *(byte *)(lVar1 + 0x3e) | 8;
  }
  return lVar1;
}



===== VmbPacketFree @ 1400099a0 =====

void VmbPacketFree(longlong param_1)

{
  code *pcVar1;
  
                    /* 0x99a0  75  VmbPacketFree */
  if ((*(int *)(param_1 + 0x18) - 1U < 5) && (*(int *)(param_1 + 0x18) == 1)) {
    *(undefined4 *)(param_1 + 0x18) = 6;
    ExFreeToNPagedLookasideList(*(longlong *)(param_1 + 0x10) + 0x140);
    return;
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(5);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== VmbPacketGetChannel @ 1400099f0 =====

undefined8 VmbPacketGetChannel(longlong param_1)

{
  code *pcVar1;
  
                    /* 0x99f0  76  VmbPacketGetChannel */
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  return **(undefined8 **)(param_1 + 0x10);
}



===== VmbPacketGetInlinePacketContextPointer @ 140009a10 =====

undefined8 VmbPacketGetInlinePacketContextPointer(longlong param_1)

{
  code *pcVar1;
  
                    /* 0x9a10  77  VmbPacketGetInlinePacketContextPointer */
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  return *(undefined8 *)(param_1 + 0x28);
}



===== VmbPacketGetPointer @ 140009a30 =====

undefined8 VmbPacketGetPointer(longlong param_1)

{
  code *pcVar1;
  
                    /* 0x9a30  78  VmbPacketGetPointer */
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  return *(undefined8 *)(param_1 + 0x20);
}



===== VmbPacketInitialize @ 140009a50 =====

undefined8 VmbPacketInitialize(undefined8 param_1,longlong param_2,int param_3)

{
                    /* 0x9a50  79  VmbPacketInitialize */
  *(undefined8 *)(param_2 + 0x10) = param_1;
  *(undefined8 *)(param_2 + 0x18) = 1;
  *(int *)(param_2 + 0xac) = param_3 + -0xf0;
  *(longlong *)(param_2 + 0x68) = param_2 + 0xf0;
  *(int *)(param_2 + 0x70) = param_3 + -0xf0;
  *(code **)(param_2 + 0x58) = _guard_check_icall;
  *(undefined4 *)(param_2 + 0xa0) = 1;
  *(undefined8 *)(param_2 + 0x20) = 0;
  *(undefined8 *)(param_2 + 0x28) = 0;
  *(undefined2 *)(param_2 + 0x3d) = 0;
  *(undefined8 *)(param_2 + 0x88) = 0;
  *(undefined8 *)(param_2 + 0x78) = 0;
  *(undefined8 *)(param_2 + 0x80) = 0;
  return 0;
}



===== VmbPacketSend @ 140009ac0 =====

int VmbPacketSend(ulonglong param_1,undefined8 param_2,undefined4 param_3,longlong param_4)

{
  code *pcVar1;
  int iVar2;
  int extraout_EAX;
  int iVar3;
  undefined1 *puVar4;
  char cVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
                    /* 0x9ac0  80  VmbPacketSend */
  puVar4 = auStack_38;
  lVar8 = param_4;
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
    puVar4 = auStack_30;
  }
  uVar7 = (ulonglong)*(uint *)(puVar4 + 0x60);
  if (lVar8 != 0) {
    param_4 = 0;
    *(uint *)(puVar4 + 0x20) = *(uint *)(puVar4 + 0x60) & 0xfffffffd;
    *(undefined8 *)(puVar4 + -8) = 0x140009b16;
    OutSetupGpaDirectPacket(param_1,lVar8,0,0,*(uint *)(puVar4 + 0x20));
  }
  uVar6 = CONCAT71((int7)((ulonglong)param_4 >> 8),(char)uVar7) & 0xffffffffffffff01;
  cVar5 = (char)uVar6;
  if ((uVar7 & 4) == 0) {
    *(undefined4 *)(puVar4 + 0x20) = 1;
    *(undefined8 *)(puVar4 + -8) = 0x140009b50;
    OutSendPacket(param_1,param_2,param_3,cVar5,*(uint *)(puVar4 + 0x20));
    iVar2 = extraout_EAX;
  }
  else {
    *(undefined4 *)(puVar4 + 0x28) = 0;
    puVar4[0x20] = cVar5;
    *(undefined8 *)(puVar4 + -8) = 0x140009b3b;
    iVar2 = OutCopyAndSendPacket
                      (param_1,(undefined8 *)(puVar4 + 0x48),(uint *)(puVar4 + 0x50),uVar6,
                       puVar4[0x20],*(uint *)(puVar4 + 0x28));
  }
  iVar3 = 0;
  if (iVar2 < 0) {
    iVar3 = iVar2;
  }
  return iVar3;
}



===== VmbPacketSendWithExternalPfns @ 140009b70 =====

undefined4
VmbPacketSendWithExternalPfns
          (ulonglong param_1,undefined8 param_2,undefined4 param_3,void *param_4,uint param_5)

{
  undefined4 uVar1;
  longlong lVar2;
  
                    /* 0x9b70  82  VmbPacketSendWithExternalPfns */
  if ((param_4 == (void *)0x0) || (param_5 == 0)) {
    uVar1 = 0xc000000d;
  }
  else {
    lVar2 = IoAllocateMdl(0,param_5 << 0xc,0,0,0);
    if (lVar2 == 0) {
      uVar1 = 0xc000009a;
    }
    else {
      *(ushort *)(lVar2 + 10) = *(ushort *)(lVar2 + 10) | 2;
      memmove((void *)(lVar2 + 0x30),param_4,(ulonglong)param_5 << 3);
      uVar1 = VmbPacketSendWithExternalMdl(param_1,param_2,param_3,lVar2);
      IoFreeMdl(lVar2);
    }
  }
  return uVar1;
}



===== VmbPacketSendWithTransferPageRanges @ 140009c60 =====

int VmbPacketSendWithTransferPageRanges
              (ulonglong param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  byte bVar1;
  byte bVar2;
  undefined8 uVar3;
  code *pcVar4;
  int iVar5;
  int extraout_EAX;
  int iVar6;
  undefined1 *puVar7;
  undefined1 uVar8;
  byte bVar9;
  undefined1 uVar10;
  undefined6 uVar11;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
                    /* 0x9c60  83  VmbPacketSendWithTransferPageRanges */
  uVar8 = (undefined1)param_4;
  uVar10 = (undefined1)((ulonglong)param_4 >> 8);
  uVar11 = (undefined6)((ulonglong)param_4 >> 0x10);
  puVar7 = auStack_38;
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)();
    puVar7 = auStack_30;
  }
  uVar3 = *(undefined8 *)(puVar7 + 0x68);
  *(ushort *)(param_1 + 0x48) = CONCAT11(uVar10,uVar8);
  bVar1 = puVar7[0x70];
  bVar9 = bVar1 & 1;
  *(undefined1 *)(param_1 + 0x3d) = 2;
  bVar2 = puVar7[0x70];
  *(undefined8 *)(param_1 + 0x40) = uVar3;
  if ((bVar2 & 4) == 0) {
    *(undefined4 *)(puVar7 + 0x20) = 1;
    *(undefined8 *)(puVar7 + -8) = 0x140009ccb;
    OutSendPacket(param_1,param_2,param_3,bVar9,*(uint *)(puVar7 + 0x20));
    iVar5 = extraout_EAX;
  }
  else {
    *(undefined4 *)(puVar7 + 0x28) = 0;
    puVar7[0x20] = bVar9;
    *(undefined8 *)(puVar7 + -8) = 0x140009cbc;
    iVar5 = OutCopyAndSendPacket
                      (param_1,(undefined8 *)(puVar7 + 0x48),(uint *)(puVar7 + 0x50),
                       CONCAT62(uVar11,CONCAT11(uVar10,bVar1)) & 0xffffffffffffff01,puVar7[0x20],
                       *(uint *)(puVar7 + 0x28));
  }
  iVar6 = 0;
  if (iVar5 < 0) {
    iVar6 = iVar5;
  }
  return iVar6;
}



===== VmbPacketSetCompletionRoutine @ 140009ce0 =====

void VmbPacketSetCompletionRoutine(longlong param_1,undefined8 param_2)

{
  code *pcVar1;
  
                    /* 0x9ce0  84  VmbPacketSetCompletionRoutine */
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  if ((*(byte *)(param_1 + 0x3e) & 0x40) == 0) {
    *(undefined8 *)(param_1 + 0x58) = param_2;
  }
  return;
}



===== VmbPacketSetCompletionRoutineEx @ 140009d10 =====

void VmbPacketSetCompletionRoutineEx(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  
                    /* 0x9d10  85  VmbPacketSetCompletionRoutineEx */
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  *(byte *)(param_1 + 0x3e) = *(byte *)(param_1 + 0x3e) | 0x40;
  *(undefined8 *)(param_1 + 0x58) = param_3;
  *(undefined8 *)(param_1 + 0x60) = param_2;
  return;
}



===== VmbPacketSetPointer @ 140009d40 =====

void VmbPacketSetPointer(longlong param_1,undefined8 param_2)

{
  code *pcVar1;
  
                    /* 0x9d40  86  VmbPacketSetPointer */
  if (4 < *(int *)(param_1 + 0x18) - 1U) {
    param_1 = 5;
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)();
  }
  *(undefined8 *)(param_1 + 0x20) = param_2;
  return;
}



===== KmclSendSignal @ 140009d60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool KmclSendSignal(longlong param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(param_1 + 0x9d0))
                    (*(undefined8 *)(param_1 + 0x940),*(char *)(param_1 + 0x929) == '\0');
  if (cVar1 != '\0') {
    LOCK();
    *(int *)(param_1 + 0x694) = *(int *)(param_1 + 0x694) + 1;
    UNLOCK();
  }
  return cVar1 != '\0';
}



===== VmbChannelSendInterrupt @ 140009db0 =====

void VmbChannelSendInterrupt(longlong param_1)

{
                    /* 0x9db0  55  VmbChannelSendInterrupt */
  KmclSendSignal(param_1);
  return;
}



===== VmbusDropArrivalRemovalInterface @ 140009dc8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbusDropArrivalRemovalInterface(longlong param_1)

{
  if (*(char *)(param_1 + 0xb09) != '\0') {
    KmclUnlockChannel(param_1);
    (*DAT_140016368)(param_1 + 0x6dc,param_1 + 0x6ec,*(undefined2 *)(param_1 + 0xcd0));
    KmclLockChannel(param_1);
  }
  if (*(code **)(param_1 + 0xb28) != (code *)0x0) {
    (**(code **)(param_1 + 0xb28))(*(undefined8 *)(param_1 + 0xb18));
  }
  memset((void *)(param_1 + 0xb10),0,0x40);
  return;
}



===== VmbusDropInterface @ 140009e40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbusDropInterface(longlong param_1)

{
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_49e0e7fd91be3488c49f0fce69c73577_Traceguids,param_1);
  }
  if (*(code **)(param_1 + 0x950) != (code *)0x0) {
    (**(code **)(param_1 + 0x950))(*(undefined8 *)(param_1 + 0x940));
  }
  memset((void *)(param_1 + 0x938),0,0x140);
  return;
}



===== VmbusSendInterfaceQuery @ 140009ebc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int VmbusSendInterfaceQuery(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
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
  uVar3 = IoGetAttachedDeviceReference(*(undefined8 *)(param_1 + 0xaa0));
  KeInitializeEvent(&local_28,1);
  lVar4 = IoBuildAsynchronousFsdRequest(0x1b,uVar3,0,0,0,&local_38);
  if (lVar4 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(code **)(lVar1 + -0x10) = VmbusSendInterfaceQueryCompletionRoutine;
    *(undefined8 **)(lVar1 + -8) = &local_28;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(undefined **)(lVar1 + -0x40) = &GUID_VMBUS_INTERFACE_STANDARD;
    *(longlong *)(lVar1 + -0x30) = param_1 + 0x938;
    *(undefined1 *)(lVar1 + -0x47) = 8;
    *(undefined4 *)(lVar1 + -0x38) = 0xd0140;
    *(undefined8 *)(lVar1 + -0x28) = *(undefined8 *)(param_1 + 0xaa8);
    *(undefined8 *)(lVar1 + -0x18) = *(undefined8 *)(param_1 + 0xaa8);
    *(undefined4 *)(lVar4 + 0x30) = 0xc00000bb;
    iVar2 = IofCallDriver(uVar3);
    if (iVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      iVar2 = (int)local_38;
    }
    if (-1 < iVar2) {
      if (*(short *)(param_1 + 0x93a) == 0xd) {
        iVar2 = 0;
      }
      else {
        if (*(code **)(param_1 + 0x950) != (code *)0x0) {
          (**(code **)(param_1 + 0x950))(*(undefined8 *)(param_1 + 0x940));
          *(undefined8 *)(param_1 + 0x950) = 0;
        }
        iVar2 = -0x3fffffa7;
      }
    }
  }
  ObfDereferenceObject(uVar3);
  return iVar2;
}



===== VmbusSendInterfaceQueryCompletionRoutine @ 14000a060 =====

undefined8
VmbusSendInterfaceQueryCompletionRoutine(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  IoFreeIrp(param_2);
  return 0xc0000016;
}



===== WPP_SF_q @ 14000a0a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== KmclChannelArriveCallback @ 14000a0f0 =====

void KmclChannelArriveCallback
               (longlong *param_1,longlong param_2,longlong *param_3,longlong *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong *plVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong *plVar9;
  longlong *plVar10;
  bool bVar11;
  
  bVar11 = (void *)param_1[0x150] == SystemReserved1[0xf];
  plVar10 = param_3;
  if (!bVar11) {
    KmclLockChannel((longlong)param_1);
  }
  *(undefined1 *)((longlong)param_1 + 0xb09) = 0;
  if ((int)param_1[0x113] == 1) {
    lVar3 = param_4[1];
    lVar7 = 2;
    param_1[0x162] = *param_4;
    param_1[0x163] = lVar3;
    lVar3 = param_4[3];
    uVar8 = 0x80;
    param_1[0x164] = param_4[2];
    param_1[0x165] = lVar3;
    lVar3 = param_4[5];
    param_1[0x166] = param_4[4];
    param_1[0x167] = lVar3;
    lVar3 = param_4[7];
    param_1[0x168] = param_4[6];
    param_1[0x169] = lVar3;
    plVar4 = param_1 + 0x127;
    do {
      plVar9 = param_3;
      plVar5 = plVar4;
      lVar3 = plVar9[1];
      *plVar5 = *plVar9;
      plVar5[1] = lVar3;
      lVar3 = plVar9[3];
      plVar5[2] = plVar9[2];
      plVar5[3] = lVar3;
      lVar3 = plVar9[5];
      plVar5[4] = plVar9[4];
      plVar5[5] = lVar3;
      lVar3 = plVar9[7];
      plVar5[6] = plVar9[6];
      plVar5[7] = lVar3;
      lVar3 = plVar9[9];
      plVar5[8] = plVar9[8];
      plVar5[9] = lVar3;
      lVar3 = plVar9[0xb];
      plVar5[10] = plVar9[10];
      plVar5[0xb] = lVar3;
      lVar3 = plVar9[0xd];
      plVar5[0xc] = plVar9[0xc];
      plVar5[0xd] = lVar3;
      lVar3 = plVar9[0xf];
      plVar5[0xe] = plVar9[0xe];
      plVar5[0xf] = lVar3;
      lVar7 = lVar7 + -1;
      plVar4 = plVar5 + 0x10;
      param_3 = plVar9 + 0x10;
    } while (lVar7 != 0);
    lVar3 = plVar9[0x11];
    plVar5[0x10] = plVar9[0x10];
    plVar5[0x11] = lVar3;
    lVar3 = plVar9[0x13];
    plVar5[0x12] = plVar9[0x12];
    plVar5[0x13] = lVar3;
    uVar1 = *(undefined4 *)((longlong)plVar9 + 0xa4);
    lVar3 = plVar9[0x15];
    uVar2 = *(undefined4 *)((longlong)plVar9 + 0xac);
    *(int *)(plVar5 + 0x14) = (int)plVar9[0x14];
    *(undefined4 *)((longlong)plVar5 + 0xa4) = uVar1;
    *(int *)(plVar5 + 0x15) = (int)lVar3;
    *(undefined4 *)((longlong)plVar5 + 0xac) = uVar2;
    uVar1 = *(undefined4 *)((longlong)plVar9 + 0xb4);
    lVar3 = plVar9[0x17];
    uVar2 = *(undefined4 *)((longlong)plVar9 + 0xbc);
    *(int *)(plVar5 + 0x16) = (int)plVar9[0x16];
    *(undefined4 *)((longlong)plVar5 + 0xb4) = uVar1;
    *(int *)(plVar5 + 0x17) = (int)lVar3;
    *(undefined4 *)((longlong)plVar5 + 0xbc) = uVar2;
    ObfReferenceObject(param_2);
    param_1[0x154] = param_2;
    if (bVar11) {
      *(undefined4 *)(param_1 + 0x151) = 0;
      return;
    }
    uVar6 = KmclpClientOpenChannel(param_1);
    if ((int)uVar6 == 0) {
      KmclpResumePausedChannelAndUnlock(param_1,uVar8,plVar10);
      return;
    }
    KmclpDisableClosedChannel((longlong)param_1);
  }
  else if (bVar11) {
    return;
  }
  KmclUnlockChannel((longlong)param_1);
  return;
}



===== KmclDecrementRundownCount @ 14000a25c =====

void KmclDecrementRundownCount(longlong param_1,char param_2,undefined2 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x8a8);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  LOCK();
  piVar1 = (int *)(param_1 + 0xce0);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  uVar6 = iVar2 + 1;
  uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 == 0) {
    iVar2 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
    iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
  }
  else {
    iVar2 = (uVar6 / 0x18) * -0x18;
  }
  lVar5 = (longlong)(int)(uVar6 + iVar2);
  *(undefined1 *)(param_1 + 0xce4 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x898);
  *(undefined1 *)(param_1 + 0xce5 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x89c);
  *(short *)(param_1 + 0xce6 + lVar5 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
  *(undefined2 *)(param_1 + 0xce8 + lVar5 * 6) = param_3;
  if ((iVar3 == 1) && (param_2 != '\0')) {
    LOCK();
    piVar1 = (int *)(param_1 + 0xce0);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    uVar6 = iVar3 + 1;
    uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      iVar3 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
      iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
    }
    else {
      iVar3 = (uVar6 / 0x18) * -0x18;
    }
    lVar5 = (longlong)(int)(uVar6 + iVar3);
    *(undefined1 *)(param_1 + 0xce4 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x898);
    *(undefined1 *)(param_1 + 0xce5 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x89c);
    *(short *)(param_1 + 0xce6 + lVar5 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
    *(undefined2 *)(param_1 + 0xce8 + lVar5 * 6) = 0x10d5;
    if (*(char *)(param_1 + 0x8e8) == '\0') {
      IoQueueWorkItem(*(undefined8 *)(param_1 + 0x8b0),KmclpRundownCountZero,1,param_1);
    }
    else {
      KeSetEvent(param_1 + 0x8b8,0,0);
    }
  }
  return;
}



===== KmclLockChannel @ 14000a3fc =====

void KmclLockChannel(longlong param_1)

{
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(param_1 + 0x8f0);
  return;
}



===== KmclUnlockChannel @ 14000a434 =====

void KmclUnlockChannel(longlong param_1)

{
  ExReleaseFastMutexUnsafe(param_1 + 0x8f0);
  KeLeaveCriticalRegion();
  return;
}



===== KmclpAllocateForStorageChannel @ 14000a464 =====

undefined8 KmclpAllocateForStorageChannel(longlong param_1)

{
  undefined8 uVar1;
  undefined8 local_res8 [4];
  
  local_res8[0] = 0;
  *(undefined1 *)(param_1 + 0x8e9) = 0;
  KeInitializeEvent(param_1 + 0x8b8,1);
  KeInitializeEvent(param_1 + 0x8d0,0,0);
  uVar1 = PsCreateSystemThread(local_res8,0x1fffff,0,0,0,KmclpRundownCountZeroThread,param_1);
  if (-1 < (int)uVar1) {
    *(undefined1 *)(param_1 + 0x8e8) = 1;
    ZwClose(local_res8[0]);
    if (*(longlong *)(param_1 + 0x8b0) != 0) {
      IoFreeWorkItem();
      *(undefined8 *)(param_1 + 0x8b0) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



===== KmclpClientCloseChannel @ 14000a52c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KmclpClientCloseChannel(longlong param_1)

{
  ExAcquirePushLockExclusiveEx(param_1 + 0xaf8,0);
  *(undefined1 *)(param_1 + 0xaf6) = 0;
  ExReleasePushLockExclusiveEx(param_1 + 0xaf8,0);
  (**(code **)(param_1 + 0x958))(*(undefined8 *)(param_1 + 0x940));
  return;
}



===== KmclpClientFindVmbusAndUnlock @ 14000a590 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KmclpClientFindVmbusAndUnlock(longlong *param_1,undefined8 param_2,longlong *param_3)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined2 uVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  longlong *plVar9;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,param_3,param_1,(char)param_1[0x113]);
  }
  lVar7 = 0;
  *(undefined4 *)(param_1 + 0x113) = 1;
  LOCK();
  plVar9 = param_1 + 0x19c;
  lVar6 = *plVar9;
  *(int *)plVar9 = (int)*plVar9 + 1;
  UNLOCK();
  uVar8 = (int)lVar6 + 1;
  uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    iVar2 = (int)((ulonglong)((longlong)(int)uVar8 * -0x2aaaaaab) >> 0x20);
    iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
  }
  else {
    iVar2 = (uVar8 / 0x18) * -0x18;
  }
  lVar6 = (longlong)(int)(uVar8 + iVar2);
  *(char *)((longlong)param_1 + lVar6 * 6 + 0xce4) = (char)param_1[0x113];
  *(undefined1 *)((longlong)param_1 + lVar6 * 6 + 0xce5) =
       *(undefined1 *)((longlong)param_1 + 0x89c);
  *(short *)((longlong)param_1 + lVar6 * 6 + 0xce6) = (short)param_1[0x115];
  *(undefined2 *)((longlong)param_1 + lVar6 * 6 + 0xce8) = 0x50f;
  if (*(char *)((longlong)param_1 + 0x7c1) == '\0') {
    if ((char)param_1[0xf8] == '\0') {
      lVar4 = IoGetLowerDeviceObject(param_1[0x198]);
      param_1[0x154] = lVar4;
      if (lVar4 == 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,param_3,param_1,
                    (char)param_1[0x198]);
        }
        iVar2 = -0x3ffffff3;
      }
      else {
        iVar2 = VmbusSendInterfaceQuery((longlong)param_1);
        if (-1 < iVar2) goto LAB_14000a8d8;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,param_3,param_1,(char)iVar2);
        }
        ObfDereferenceObject(param_1[0x154]);
        param_1[0x154] = 0;
      }
      goto LAB_14000a915;
    }
    param_3 = (longlong *)((longlong)param_1 + 0x6dc);
    param_1[0x150] = (longlong)SystemReserved1[0xf];
    *(undefined4 *)(param_1 + 0x151) = 0x103;
    cVar1 = (*DAT_140016370)(param_3,(short)param_1[0x19a]);
    if (cVar1 == '\0') {
      lVar6 = 1;
      iVar2 = IoRegisterPlugPlayNotification
                        (2,1,param_3,*(undefined8 *)(param_1[0x198] + 8),
                         KmclpVmbusArrivalNotification,param_1,param_1 + 0x14f);
    }
    else {
      plVar9 = (longlong *)(ulonglong)*(ushort *)(param_1 + 0x19a);
      lVar6 = (longlong)param_1 + 0x6ec;
      *(undefined2 *)(param_1 + 0x161) = 0x101;
      iVar2 = (*DAT_140016360)(param_3,lVar6,plVar9,KmclChannelArriveCallback,param_1);
      param_3 = plVar9;
    }
    param_1[0x150] = 0;
    if (iVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar5 = 0x28;
        goto LAB_14000a909;
      }
      goto LAB_14000a915;
    }
    iVar2 = (int)param_1[0x151];
    if (iVar2 != 0x103) {
      if ((char)param_1[0x161] == '\0') {
        lVar7 = param_1[0x14f];
        param_1[0x14f] = 0;
        if (iVar2 < 0) goto LAB_14000a915;
      }
LAB_14000a8d8:
      uVar3 = KmclpClientOpenChannel(param_1);
      iVar2 = (int)uVar3;
      if (-1 < iVar2) {
        KmclpResumePausedChannelAndUnlock(param_1,lVar6,param_3);
        iVar2 = 0;
        goto LAB_14000a931;
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar5 = 0x2a;
        goto LAB_14000a909;
      }
      goto LAB_14000a915;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_3 = (longlong *)&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,
               &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
    }
    iVar2 = 0;
  }
  else {
    iVar2 = VmbusSendInterfaceQuery((longlong)param_1);
    if (-1 < iVar2) goto LAB_14000a8d8;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar5 = 0x25;
LAB_14000a909:
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,param_3,param_1,(char)iVar2);
    }
LAB_14000a915:
    KmclpDisableClosedChannel((longlong)param_1);
  }
  KmclUnlockChannel((longlong)param_1);
LAB_14000a931:
  if (lVar7 != 0) {
    IoUnregisterPlugPlayNotificationEx(lVar7);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,param_3,param_1,(char)iVar2);
  }
  return iVar2;
}



===== KmclpClientOpenChannel @ 14000a998 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong KmclpClientOpenChannel(longlong *param_1)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined2 uVar10;
  longlong lVar11;
  longlong lVar12;
  code *pcVar13;
  undefined1 auStackY_1f8 [32];
  undefined4 local_1b8;
  undefined4 local_1b4;
  int local_1b0 [4];
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  ulonglong uStack_188;
  longlong local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  longlong local_160;
  longlong lStack_158;
  longlong local_150;
  longlong lStack_148;
  int local_140;
  undefined1 local_13a;
  longlong local_138;
  longlong local_130;
  longlong local_128;
  longlong lStack_120;
  longlong local_118;
  longlong lStack_110;
  longlong local_108;
  longlong lStack_100;
  longlong local_f8;
  longlong lStack_f0;
  longlong local_e8;
  longlong lStack_e0;
  longlong local_d8;
  longlong lStack_d0;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  longlong local_b8;
  undefined1 local_b0 [120];
  int local_38;
  undefined4 local_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_1f8;
  memset(local_b0,0,0x80);
  pcVar13 = (code *)0xb0;
  memset(&local_160,0,0xb0);
  local_1b0[0] = 0;
  local_1b0[1] = 0;
  local_1b4 = 0;
  local_180 = 0;
  uStack_178 = 0;
  local_1b8 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x35,pcVar13,param_1,(char)param_1[0x113],
               (char)param_1[0x161]);
  }
  local_170 = 0;
  uStack_168 = 0;
  if ((char)param_1[0x161] == '\0') {
    pcVar13 = (code *)0x0;
    uVar9 = KmclpSynchronousIoControl((longlong)param_1,0x3ec024,0,0,&local_160,0xb0);
    uVar5 = (uint)uVar9;
  }
  else {
    uVar5 = (*(code *)param_1[0x167])(param_1[0x163],&local_160);
  }
  uVar9 = (ulonglong)uVar5;
  if ((int)uVar5 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar10 = 0x36;
LAB_14000ac69:
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,pcVar13,param_1,(char)uVar9);
    }
  }
  else {
    param_1[0x181] = local_138;
    param_1[0x182] = local_130;
    param_1[0x156] = local_160;
    param_1[0x157] = lStack_158;
    param_1[0x158] = local_150;
    param_1[0x159] = lStack_148;
    if ((char)param_1[0x16a] != '\0') {
      *(undefined1 *)((longlong)param_1 + 0xb51) = local_13a;
    }
    param_1[0xe4] = local_128;
    param_1[0xe5] = lStack_120;
    param_1[0xe6] = local_118;
    param_1[0xe7] = lStack_110;
    param_1[0xe8] = local_108;
    param_1[0xe9] = lStack_100;
    param_1[0xea] = local_f8;
    param_1[0xeb] = lStack_f0;
    param_1[0xec] = local_e8;
    param_1[0xed] = lStack_e0;
    param_1[0xee] = local_d8;
    param_1[0xef] = lStack_d0;
    *(undefined4 *)(param_1 + 0xf0) = local_c8;
    *(undefined4 *)((longlong)param_1 + 0x784) = uStack_c4;
    *(undefined4 *)(param_1 + 0xf1) = uStack_c0;
    *(undefined4 *)((longlong)param_1 + 0x78c) = uStack_bc;
    param_1[0xf2] = local_b8;
    iVar7 = (int)param_1[0xf6];
    if ((int)param_1[0xf6] == -1) {
      *(int *)(param_1 + 0xf6) = local_140;
      iVar7 = local_140;
    }
    iVar4 = KeGetProcessorNumberFromIndex(iVar7,&local_1b8);
    if (-1 < iVar4) {
      uStack_178 = CONCAT62(uStack_178._2_6_,(undefined2)local_1b8);
      local_180 = 1L << (local_1b8._2_1_ & 0x3f);
      KeSetSystemGroupAffinityThread(&local_180,&local_170);
    }
    if ((*(char *)((longlong)param_1 + 0xb51) != '\0') &&
       (*(uint *)((longlong)param_1 + 0x7b4) != 0)) {
      pcVar13 = (code *)CONCAT71((int7)((ulonglong)pcVar13 >> 8),1);
      uVar5 = KmclpAllocateBounceBlock
                        ((longlong)param_1,(ulonglong)*(uint *)((longlong)param_1 + 0x7b4),1);
      uVar9 = (ulonglong)uVar5;
      if ((int)uVar5 < 0) goto LAB_14000ad17;
    }
    if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
      uVar8 = InOpenChannel(param_1);
      uVar9 = uVar8 & 0xffffffff;
      if ((int)uVar8 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar10 = 0x37;
          goto LAB_14000ac69;
        }
        goto LAB_14000ad17;
      }
    }
    uVar5 = KmclpInitializeVmbusConnection((longlong)param_1);
    uVar9 = (ulonglong)uVar5;
    if ((int)uVar5 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        uVar10 = 0x38;
        goto LAB_14000ac69;
      }
    }
    else {
      lVar12 = param_1[0xf5];
      iVar2 = *(int *)((longlong)param_1 + 0x7ac);
      iVar4 = (int)lVar12 + 1;
      uVar5 = iVar2 + 1;
      *(int *)(param_1 + 0x153) = iVar4;
      iVar4 = iVar4 + uVar5;
      *(uint *)((longlong)param_1 + 0xa9c) = uVar5;
      if ((char)param_1[0x161] == '\0') {
        pcVar13 = (code *)local_1b0;
        local_1b0[1] = uVar5;
        local_1b0[0] = iVar4;
        uVar8 = KmclpSynchronousIoControl((longlong)param_1,0x3ec02e,pcVar13,8,&local_1b4,4);
        uVar9 = uVar8 & 0xffffffff;
        if (-1 < (int)uVar8) {
          (*(code *)param_1[0x132])(param_1[0x128],local_1b4,param_1 + 0x152);
          goto LAB_14000adf9;
        }
      }
      else {
        pcVar13 = (code *)(ulonglong)uVar5;
        uVar6 = (*(code *)param_1[0x168])(param_1[0x163],iVar4,pcVar13,param_1 + 0x152);
        uVar9 = (ulonglong)uVar6;
        if (-1 < (int)uVar6) {
LAB_14000adf9:
          if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
            lVar3 = param_1[0x152];
            lVar11 = (ulonglong)(uVar5 * 0x1000) + lVar3;
            pcVar13 = (code *)(lVar11 + 0x1000);
            uVar9 = PkInitializeRingBuffer
                              (param_1 + 8,lVar11,pcVar13,(int)lVar12,lVar3,lVar3 + 0x1000,iVar2);
            uVar8 = uVar9 & 0xffffffff;
            if (-1 < (int)uVar9) {
              param_1[0x1b] = (longlong)(param_1 + 0x3d);
              goto LAB_14000ae8e;
            }
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar10 = 0x3a;
              goto LAB_14000b045;
            }
          }
          else {
LAB_14000ae8e:
            uVar9 = 0;
            ExAcquirePushLockExclusiveEx(param_1 + 0x15f,0);
            *(undefined1 *)((longlong)param_1 + 0xaf6) = 1;
            ExReleasePushLockExclusiveEx(param_1 + 0x15f,0);
            local_34 = 1;
            if (*(char *)((longlong)param_1 + 0x7c2) != '\0') {
              local_34 = 3;
            }
            local_38 = iVar7;
            if ((char)param_1[0x161] == '\0') {
              pcVar13 = (code *)local_b0;
              uVar8 = KmclpSynchronousIoControl((longlong)param_1,0x3ec034,pcVar13,0x80,0,0);
              uVar8 = uVar8 & 0xffffffff;
            }
            else {
              local_1a0 = 0;
              uStack_198 = 0;
              local_190 = 0;
              uStack_188 = 0;
              KeInitializeEvent(&local_1a0,1,0);
              pcVar13 = KmclpOpenChannelCompletionCallback;
              uVar5 = (*(code *)param_1[0x169])
                                (param_1[0x163],local_b0,KmclpOpenChannelCompletionCallback,
                                 &local_1a0);
              uVar8 = (ulonglong)uVar5;
              if (uVar5 == 0x103) {
                pcVar13 = (code *)0x0;
                KeWaitForSingleObject(&local_1a0,0,0,0);
                uVar8 = uStack_188 & 0xffffffff;
              }
            }
            if ((int)uVar8 < 0) {
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar10 = 0x3b;
LAB_14000b045:
                WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar10,pcVar13,param_1,
                          (char)uVar8);
              }
            }
            else {
              *(int *)((longlong)param_1 + 0xccc) = iVar7;
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                pcVar13 = (code *)&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids;
                WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3c,
                         &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
              }
              if ((char)param_1[0xfd] == '\0') {
                uVar5 = (*(code *)param_1[0xff])(param_1);
              }
              else {
                uVar5 = (*(code *)param_1[0x100])(param_1,param_1[0xff]);
              }
              uVar8 = (ulonglong)uVar5;
              if (-1 < (int)uVar5) {
                if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                   (3 < (byte)WPP_GLOBAL_Control[0x29])) {
                  WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3e,pcVar13,param_1,
                            (char)uVar5);
                }
                *(undefined4 *)(param_1 + 0x113) = 4;
                LOCK();
                plVar1 = param_1 + 0x19c;
                lVar12 = *plVar1;
                *(int *)plVar1 = (int)*plVar1 + 1;
                UNLOCK();
                uVar5 = (int)lVar12 + 1;
                uVar8 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
                if ((int)uVar8 == 0) {
                  iVar7 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
                  iVar7 = ((iVar7 >> 2) - (iVar7 >> 0x1f)) * 0x18;
                }
                else {
                  iVar7 = (uVar5 / 0x18) * -0x18;
                }
                lVar12 = (longlong)(int)(uVar5 + iVar7);
                *(char *)((longlong)param_1 + lVar12 * 6 + 0xce4) = (char)param_1[0x113];
                *(undefined1 *)((longlong)param_1 + lVar12 * 6 + 0xce5) =
                     *(undefined1 *)((longlong)param_1 + 0x89c);
                *(short *)((longlong)param_1 + lVar12 * 6 + 0xce6) = (short)param_1[0x115];
                *(undefined2 *)((longlong)param_1 + lVar12 * 6 + 0xce8) = 0x919;
                goto LAB_14000ad27;
              }
              if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                  ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
                 (1 < (byte)WPP_GLOBAL_Control[0x29])) {
                uVar10 = 0x3d;
                goto LAB_14000b045;
              }
            }
          }
          KmclpClientCloseChannel((longlong)param_1);
          uVar9 = uVar8;
          goto LAB_14000ad17;
        }
      }
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x39,pcVar13,param_1,(char)uVar9);
      }
      if (-1 < (int)uVar9) goto LAB_14000ad27;
    }
  }
LAB_14000ad17:
  KmclpTeardownOpenChannelState(param_1);
  KmclpDisableClosedChannel((longlong)param_1);
LAB_14000ad27:
  KeRevertToUserGroupAffinityThread(&local_170);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x3f,pcVar13,param_1,(char)uVar9);
  }
  return uVar9;
}



===== KmclpContinueChannelRundownAndUnlock @ 14000b128 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KmclpContinueChannelRundownAndUnlock(longlong *param_1,longlong param_2,undefined8 param_3)

{
  longlong *plVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  undefined2 uVar6;
  longlong *plVar7;
  longlong local_res8;
  longlong local_res10;
  undefined1 uVar8;
  
  local_res10 = 0;
  local_res8 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_2 = 0x62;
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x62,param_3,param_1,(char)param_1[0x113]);
  }
  iVar2 = (int)param_1[0x113];
  if (iVar2 == 3) {
    iVar2 = *(int *)((longlong)param_1 + 0x89c);
    if (iVar2 != 1) {
      if ((iVar2 == 4) || ((char)param_1[0xd8] == '\0')) {
        *(byte *)(param_1 + 0x125) = *(byte *)(param_1 + 0x125) & 0xfd;
        KmclpDisableClosedChannel((longlong)param_1);
      }
      else if (iVar2 != 3) {
        *(undefined4 *)(param_1 + 0x113) = 5;
        LOCK();
        plVar7 = param_1 + 0x19c;
        lVar4 = *plVar7;
        *(int *)plVar7 = (int)*plVar7 + 1;
        UNLOCK();
        uVar5 = (int)lVar4 + 1;
        uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar3 == 0) {
          iVar2 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
          iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
        }
        else {
          iVar2 = (uVar5 / 0x18) * -0x18;
        }
        param_2 = (longlong)(int)(uVar5 + iVar2);
        *(char *)((longlong)param_1 + param_2 * 6 + 0xce4) = (char)param_1[0x113];
        *(undefined1 *)((longlong)param_1 + param_2 * 6 + 0xce5) =
             *(undefined1 *)((longlong)param_1 + 0x89c);
        *(short *)((longlong)param_1 + param_2 * 6 + 0xce6) = (short)param_1[0x115];
        *(undefined2 *)((longlong)param_1 + param_2 * 6 + 0xce8) = 0xf54;
        KmclpStartWaitForAction((longlong)param_1,param_2,param_3);
      }
    }
LAB_14000bdd6:
    KmclpFinishSuspendProcessAndUnlock((longlong)param_1,param_2,param_3);
    goto LAB_14000bdde;
  }
  if (iVar2 == 4) {
    if (*(int *)((longlong)param_1 + 0x89c) == 1) goto LAB_14000bdd6;
    if ((*(char *)((longlong)param_1 + 0x706) != '\0') && (*(int *)((longlong)param_1 + 0x89c) == 3)
       ) {
      local_res10 = param_1[0x114];
      param_1[0x114] = 0;
      if ((*(byte *)(param_1 + 0x125) & 0x40) != 0) {
        local_res8 = param_1[0x18b];
        *(byte *)(param_1 + 0x125) = *(byte *)(param_1 + 0x125) & 0xbf;
      }
    }
    *(undefined4 *)(param_1 + 0x113) = 0xb;
    LOCK();
    plVar7 = param_1 + 0x19c;
    lVar4 = *plVar7;
    *(int *)plVar7 = (int)*plVar7 + 1;
    UNLOCK();
    uVar5 = (int)lVar4 + 1;
    uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      iVar2 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
      iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
    }
    else {
      iVar2 = (uVar5 / 0x18) * -0x18;
    }
    lVar4 = (longlong)(int)(uVar5 + iVar2);
    *(char *)((longlong)param_1 + lVar4 * 6 + 0xce4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar4 * 6 + 0xce5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar4 * 6 + 0xce6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar4 * 6 + 0xce8) = 0xeab;
    LOCK();
    *(undefined4 *)(param_1 + 0x115) = 1;
    UNLOCK();
    LOCK();
    plVar7 = param_1 + 0x19c;
    lVar4 = *plVar7;
    *(int *)plVar7 = (int)*plVar7 + 1;
    UNLOCK();
    uVar5 = (int)lVar4 + 1;
    uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      iVar2 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
      iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
    }
    else {
      iVar2 = (uVar5 / 0x18) * -0x18;
    }
    lVar4 = (longlong)(int)(uVar5 + iVar2);
    *(char *)((longlong)param_1 + lVar4 * 6 + 0xce4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar4 * 6 + 0xce5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar4 * 6 + 0xce6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar4 * 6 + 0xce8) = 0xead;
    *(byte *)(param_1 + 0x125) = *(byte *)(param_1 + 0x125) & 0xfd;
    KmclUnlockChannel((longlong)param_1);
    KeEnterCriticalRegion();
    ExAcquireFastMutexUnsafe(param_1 + 0x18d);
    plVar7 = (longlong *)param_1[0x194];
    if (plVar7 != param_1 + 0x194) {
      do {
        LOCK();
        *(int *)(param_1 + 0x115) = (int)param_1[0x115] + 1;
        UNLOCK();
        LOCK();
        plVar1 = param_1 + 0x19c;
        lVar4 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + 1;
        UNLOCK();
        uVar5 = (int)lVar4 + 1;
        uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar3 == 0) {
          iVar2 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
          iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
        }
        else {
          iVar2 = (uVar5 / 0x18) * -0x18;
        }
        lVar4 = (longlong)(int)(uVar5 + iVar2);
        *(char *)((longlong)param_1 + lVar4 * 6 + 0xce4) = (char)param_1[0x113];
        *(undefined1 *)((longlong)param_1 + lVar4 * 6 + 0xce5) =
             *(undefined1 *)((longlong)param_1 + 0x89c);
        *(short *)((longlong)param_1 + lVar4 * 6 + 0xce6) = (short)param_1[0x115];
        *(undefined2 *)((longlong)param_1 + lVar4 * 6 + 0xce8) = 0xec4;
        uVar8 = SUB81(plVar7 + -0x196,0);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x69,param_3,param_1,uVar8);
        }
        KmclpDisableChannel((longlong)(plVar7 + -0x196),'\0',param_3);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6a,param_3,param_1,uVar8);
        }
        plVar7 = (longlong *)*plVar7;
      } while (plVar7 != param_1 + 0x194);
    }
    ExReleaseFastMutexUnsafe(param_1 + 0x18d);
    KeLeaveCriticalRegion();
    if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6b,
                 &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
      }
      InStopQueue(param_1);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6c,
                 &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
      }
    }
    if ((char)param_1[0xd8] == '\0') {
      KmclpClientCloseChannel((longlong)param_1);
    }
    if (local_res10 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6d,
                 &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
      }
      KmclpSignalWaiters(local_res10);
    }
    if (local_res8 != 0) {
      KmclDecrementRundownCount(local_res8,'\x01',0xf09);
    }
    uVar6 = 0xf0c;
  }
  else if (iVar2 == 5) {
    *(undefined4 *)(param_1 + 0x113) = 8;
    LOCK();
    plVar7 = param_1 + 0x19c;
    lVar4 = *plVar7;
    *(int *)plVar7 = (int)*plVar7 + 1;
    UNLOCK();
    uVar5 = (int)lVar4 + 1;
    uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      iVar2 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
      iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
    }
    else {
      iVar2 = (uVar5 / 0x18) * -0x18;
    }
    lVar4 = (longlong)(int)(uVar5 + iVar2);
    *(char *)((longlong)param_1 + lVar4 * 6 + 0xce4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar4 * 6 + 0xce5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar4 * 6 + 0xce6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar4 * 6 + 0xce8) = 0xf17;
    LOCK();
    *(undefined4 *)(param_1 + 0x115) = 1;
    UNLOCK();
    LOCK();
    plVar7 = param_1 + 0x19c;
    lVar4 = *plVar7;
    *(int *)plVar7 = (int)*plVar7 + 1;
    UNLOCK();
    uVar5 = (int)lVar4 + 1;
    uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      iVar2 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
      iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
    }
    else {
      iVar2 = (uVar5 / 0x18) * -0x18;
    }
    lVar4 = (longlong)(int)(uVar5 + iVar2);
    *(char *)((longlong)param_1 + lVar4 * 6 + 0xce4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar4 * 6 + 0xce5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar4 * 6 + 0xce6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar4 * 6 + 0xce8) = 0xf19;
    if (*(char *)((longlong)param_1 + 0xaf4) != '\0') {
      if ((char)param_1[0x161] == '\0') {
        LOCK();
        *(int *)(param_1 + 0x115) = (int)param_1[0x115] + 1;
        UNLOCK();
        LOCK();
        plVar7 = param_1 + 0x19c;
        lVar4 = *plVar7;
        *(int *)plVar7 = (int)*plVar7 + 1;
        UNLOCK();
        uVar5 = (int)lVar4 + 1;
        uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar3 == 0) {
          iVar2 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
          iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
        }
        else {
          iVar2 = (uVar5 / 0x18) * -0x18;
        }
        lVar4 = (longlong)(int)(uVar5 + iVar2);
        *(char *)((longlong)param_1 + lVar4 * 6 + 0xce4) = (char)param_1[0x113];
        *(undefined1 *)((longlong)param_1 + lVar4 * 6 + 0xce5) =
             *(undefined1 *)((longlong)param_1 + 0x89c);
        *(short *)((longlong)param_1 + lVar4 * 6 + 0xce6) = (short)param_1[0x115];
        *(undefined2 *)((longlong)param_1 + lVar4 * 6 + 0xce8) = 0xf29;
        IoCancelIrp(param_1[0x15c]);
      }
      else {
        (*(code *)param_1[0x166])(param_1[0x163],0,0);
        *(undefined1 *)((longlong)param_1 + 0xaf4) = 0;
      }
    }
    KmclUnlockChannel((longlong)param_1);
    uVar6 = 0xf30;
  }
  else {
    if (iVar2 == 6) {
      *(undefined4 *)(param_1 + 0x113) = 9;
      LOCK();
      plVar7 = param_1 + 0x19c;
      lVar4 = *plVar7;
      *(int *)plVar7 = (int)*plVar7 + 1;
      UNLOCK();
      uVar5 = (int)lVar4 + 1;
      uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar3 == 0) {
        iVar2 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
        iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
      }
      else {
        iVar2 = (uVar5 / 0x18) * -0x18;
      }
      lVar4 = (longlong)(int)(uVar5 + iVar2);
      *(char *)((longlong)param_1 + lVar4 * 6 + 0xce4) = (char)param_1[0x113];
      *(undefined1 *)((longlong)param_1 + lVar4 * 6 + 0xce5) =
           *(undefined1 *)((longlong)param_1 + 0x89c);
      *(short *)((longlong)param_1 + lVar4 * 6 + 0xce6) = (short)param_1[0x115];
      *(undefined2 *)((longlong)param_1 + lVar4 * 6 + 0xce8) = 0xdea;
      KmclUnlockChannel((longlong)param_1);
      goto LAB_14000bdde;
    }
    if (iVar2 != 7) goto LAB_14000bdde;
    LOCK();
    plVar7 = param_1 + 0x19c;
    lVar4 = *plVar7;
    *(int *)plVar7 = (int)*plVar7 + 1;
    UNLOCK();
    uVar5 = (int)lVar4 + 1;
    uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      iVar2 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
      iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
    }
    else {
      iVar2 = (uVar5 / 0x18) * -0x18;
    }
    lVar4 = (longlong)(int)(uVar5 + iVar2);
    *(char *)((longlong)param_1 + lVar4 * 6 + 0xce4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar4 * 6 + 0xce5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar4 * 6 + 0xce6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar4 * 6 + 0xce8) = 0xdf8;
    LOCK();
    *(undefined4 *)(param_1 + 0x115) = 1;
    UNLOCK();
    LOCK();
    plVar7 = param_1 + 0x19c;
    lVar4 = *plVar7;
    *(int *)plVar7 = (int)*plVar7 + 1;
    UNLOCK();
    uVar5 = (int)lVar4 + 1;
    uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      iVar2 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
      iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
    }
    else {
      iVar2 = (uVar5 / 0x18) * -0x18;
    }
    lVar4 = (longlong)(int)(uVar5 + iVar2);
    *(char *)((longlong)param_1 + lVar4 * 6 + 0xce4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar4 * 6 + 0xce5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar4 * 6 + 0xce6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar4 * 6 + 0xce8) = 0xdfa;
    *(undefined4 *)(param_1 + 0x113) = 10;
    LOCK();
    plVar7 = param_1 + 0x19c;
    lVar4 = *plVar7;
    *(int *)plVar7 = (int)*plVar7 + 1;
    UNLOCK();
    uVar5 = (int)lVar4 + 1;
    uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar3 == 0) {
      iVar2 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
      iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
    }
    else {
      iVar2 = (uVar5 / 0x18) * -0x18;
    }
    lVar4 = (longlong)(int)(uVar5 + iVar2);
    *(char *)((longlong)param_1 + lVar4 * 6 + 0xce4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar4 * 6 + 0xce5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar4 * 6 + 0xce6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar4 * 6 + 0xce8) = 0xe02;
    if (*(char *)((longlong)param_1 + 0xaf4) != '\0') {
      if ((char)param_1[0x161] == '\0') {
        LOCK();
        *(int *)(param_1 + 0x115) = (int)param_1[0x115] + 1;
        UNLOCK();
        LOCK();
        plVar7 = param_1 + 0x19c;
        lVar4 = *plVar7;
        *(int *)plVar7 = (int)*plVar7 + 1;
        UNLOCK();
        uVar5 = (int)lVar4 + 1;
        uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar3 == 0) {
          iVar2 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
          iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
        }
        else {
          iVar2 = (uVar5 / 0x18) * -0x18;
        }
        lVar4 = (longlong)(int)(uVar5 + iVar2);
        *(char *)((longlong)param_1 + lVar4 * 6 + 0xce4) = (char)param_1[0x113];
        *(undefined1 *)((longlong)param_1 + lVar4 * 6 + 0xce5) =
             *(undefined1 *)((longlong)param_1 + 0x89c);
        *(short *)((longlong)param_1 + lVar4 * 6 + 0xce6) = (short)param_1[0x115];
        *(undefined2 *)((longlong)param_1 + lVar4 * 6 + 0xce8) = 0xe16;
        IoCancelIrp(param_1[0x15c]);
      }
      else {
        param_3 = 0;
        (*(code *)param_1[0x166])(param_1[0x163],0);
        *(undefined1 *)((longlong)param_1 + 0xaf4) = 0;
      }
    }
    KmclUnlockChannel((longlong)param_1);
    KeEnterCriticalRegion();
    ExAcquireFastMutexUnsafe(param_1 + 0x18d);
    for (plVar7 = (longlong *)param_1[0x194]; plVar7 != param_1 + 0x194;
        plVar7 = (longlong *)*plVar7) {
      LOCK();
      *(int *)(param_1 + 0x115) = (int)param_1[0x115] + 1;
      UNLOCK();
      LOCK();
      plVar1 = param_1 + 0x19c;
      lVar4 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + 1;
      UNLOCK();
      uVar5 = (int)lVar4 + 1;
      uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar3 == 0) {
        iVar2 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
        iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
      }
      else {
        iVar2 = (uVar5 / 0x18) * -0x18;
      }
      lVar4 = (longlong)(int)(uVar5 + iVar2);
      *(char *)((longlong)param_1 + lVar4 * 6 + 0xce4) = (char)param_1[0x113];
      *(undefined1 *)((longlong)param_1 + lVar4 * 6 + 0xce5) =
           *(undefined1 *)((longlong)param_1 + 0x89c);
      *(short *)((longlong)param_1 + lVar4 * 6 + 0xce6) = (short)param_1[0x115];
      *(undefined2 *)((longlong)param_1 + lVar4 * 6 + 0xce8) = 0xe2c;
      uVar8 = SUB81(plVar7 + -0x196,0);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),99,param_3,param_1,uVar8);
      }
      KmclpPauseChannel((longlong)(plVar7 + -0x196),'\0',param_3);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),100,param_3,param_1,uVar8);
      }
    }
    ExReleaseFastMutexUnsafe(param_1 + 0x18d);
    KeLeaveCriticalRegion();
    if ((*(char *)((longlong)param_1 + 0x6c1) == '\0') || (param_1[0x10a] != 0)) {
      (*(code *)param_1[0x139])(param_1[0x128]);
    }
    if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x65,
                 &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
      }
      InPauseQueue(param_1);
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x66,
                   &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
        }
        goto LAB_14000b624;
      }
    }
    else {
LAB_14000b624:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x67,
                 &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
      }
    }
    if ((char)param_1[0xfd] == '\0') {
      (*(code *)param_1[0x101])(param_1);
    }
    else {
      (*(code *)param_1[0x102])(param_1,param_1[0xff]);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x68,
               &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
    }
    uVar6 = 0xe89;
  }
  KmclDecrementRundownCount((longlong)param_1,'\x01',uVar6);
LAB_14000bdde:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6e,
             &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
  }
  return;
}



===== KmclpDirectWaitForActionCallback @ 14000be40 =====

void KmclpDirectWaitForActionCallback(longlong param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xaf0) = param_2;
  IoQueueWorkItem(*(undefined8 *)(param_1 + 0xae8),KmclpWaitForActionWorkerRoutine,1,param_1);
  return;
}



===== KmclpDisableChannel @ 14000be7c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KmclpDisableChannel(longlong param_1,char param_2,undefined8 param_3)

{
  int *piVar1;
  undefined8 uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  
  KmclLockChannel(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,param_3,param_1,
               (char)*(undefined4 *)(param_1 + 0x898),param_2);
  }
  *(byte *)(param_1 + 0x928) = *(byte *)(param_1 + 0x928) & 0xfb;
  iVar3 = *(int *)(param_1 + 0x898);
  if (iVar3 != 0) {
    if (iVar3 != 1) {
      if (iVar3 != 0xc) {
        *(undefined4 *)(param_1 + 0x89c) = 4;
        LOCK();
        piVar1 = (int *)(param_1 + 0xce0);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        uVar6 = iVar3 + 1;
        uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar4 == 0) {
          iVar3 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
          iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
        }
        else {
          iVar3 = (uVar6 / 0x18) * -0x18;
        }
        lVar5 = (longlong)(int)(uVar6 + iVar3);
        *(undefined1 *)(param_1 + 0xce4 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x898);
        *(undefined1 *)(param_1 + 0xce5 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x89c);
        *(short *)(param_1 + 0xce6 + lVar5 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
        *(undefined2 *)(param_1 + 0xce8 + lVar5 * 6) = 0x29c;
        KmclpRundownChannelStateAndUnlock(param_1,param_2,param_3);
        return;
      }
      KmclUnlockChannel(param_1);
      if (*(char *)(param_1 + 0x7e8) == '\0') {
        (**(code **)(param_1 + 0x800))(param_1);
        return;
      }
      (**(code **)(param_1 + 0x808))(param_1,*(undefined8 *)(param_1 + 0x7f8));
      return;
    }
    *(undefined4 *)(param_1 + 0x898) = 2;
    LOCK();
    piVar1 = (int *)(param_1 + 0xce0);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    uVar6 = iVar3 + 1;
    uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      iVar3 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
      iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
    }
    else {
      iVar3 = (uVar6 / 0x18) * -0x18;
    }
    lVar5 = (longlong)(int)(uVar6 + iVar3);
    *(undefined1 *)(param_1 + 0xce4 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x898);
    *(undefined1 *)(param_1 + 0xce5 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x89c);
    *(short *)(param_1 + 0xce6 + lVar5 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
    *(undefined2 *)(param_1 + 0xce8 + lVar5 * 6) = 0x26e;
    if (*(char *)(param_1 + 0xb08) == '\0') {
      uVar2 = *(undefined8 *)(param_1 + 0xa78);
      *(undefined8 *)(param_1 + 0xa78) = 0;
      KmclUnlockChannel(param_1);
      IoUnregisterPlugPlayNotificationEx(uVar2);
      KmclLockChannel(param_1);
    }
    else {
      VmbusDropArrivalRemovalInterface(param_1);
    }
    *(undefined4 *)(param_1 + 0x898) = 0;
    LOCK();
    piVar1 = (int *)(param_1 + 0xce0);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    uVar6 = iVar3 + 1;
    uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      iVar3 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
      iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
    }
    else {
      iVar3 = (uVar6 / 0x18) * -0x18;
    }
    lVar5 = (longlong)(int)(uVar6 + iVar3);
    *(undefined1 *)(param_1 + 0xce4 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x898);
    *(undefined1 *)(param_1 + 0xce5 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x89c);
    *(short *)(param_1 + 0xce6 + lVar5 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
    *(undefined2 *)(param_1 + 0xce8 + lVar5 * 6) = 0x28b;
  }
  KmclUnlockChannel(param_1);
  if (param_2 == '\0') {
    LOCK();
    piVar1 = (int *)(param_1 + 0xce0);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    uVar6 = iVar3 + 1;
    uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      iVar3 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
      iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
    }
    else {
      iVar3 = (uVar6 / 0x18) * -0x18;
    }
    lVar5 = (longlong)(int)(uVar6 + iVar3);
    *(undefined1 *)(param_1 + 0xce4 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x898);
    *(undefined1 *)(param_1 + 0xce5 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x89c);
    *(short *)(param_1 + 0xce6 + lVar5 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
    *(undefined2 *)(param_1 + 0xce8 + lVar5 * 6) = 0x294;
    KmclDecrementRundownCount(*(longlong *)(param_1 + 0xc58),'\0',0x295);
  }
  return;
}



===== KmclpDisableClosedChannel @ 14000c1e4 =====

void KmclpDisableClosedChannel(longlong param_1)

{
  int *piVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  longlong lVar6;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x79,
             &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
  }
  ExAcquireFastMutex(&KmclPerformanceCounterLock);
  lVar4 = *(longlong *)(param_1 + 0x878);
  lVar6 = 0;
  if (lVar4 != 0) {
    *(undefined8 *)(param_1 + 0x878) = 0;
    *(undefined2 *)(param_1 + 0x870) = 0;
    lVar6 = lVar4;
  }
  ExReleaseFastMutex(&KmclPerformanceCounterLock);
  if (lVar6 != 0) {
    ExFreePoolWithTag(lVar6,0x636d6b56);
  }
  if (*(longlong *)(param_1 + 0xae0) != 0) {
    IoFreeIrp();
    *(undefined8 *)(param_1 + 0xae0) = 0;
  }
  if (*(char *)(param_1 + 0xb51) != '\0') {
    KmclpFreeAllBounceBlocks(param_1);
  }
  VmbusDropInterface(param_1);
  VmbusDropArrivalRemovalInterface(param_1);
  if (*(char *)(param_1 + 0x7c1) == '\0') {
    if (*(longlong *)(param_1 + 0xaa0) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(param_1 + 0xaa0) = 0;
    }
    if (*(longlong *)(param_1 + 0xaa8) != 0) {
      ObfDereferenceObject();
      *(undefined8 *)(param_1 + 0xaa8) = 0;
    }
  }
  *(undefined8 *)(param_1 + 0xac0) = 0;
  *(undefined8 *)(param_1 + 0xac8) = 0;
  *(undefined8 *)(param_1 + 0xab0) = 0;
  *(undefined8 *)(param_1 + 0xab8) = 0;
  *(undefined4 *)(param_1 + 0x898) = 0;
  LOCK();
  piVar1 = (int *)(param_1 + 0xce0);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  uVar5 = iVar2 + 1;
  uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    iVar2 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
    iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
  }
  else {
    iVar2 = (uVar5 / 0x18) * -0x18;
  }
  lVar4 = (longlong)(int)(uVar5 + iVar2);
  *(undefined1 *)(param_1 + 0xce4 + lVar4 * 6) = *(undefined1 *)(param_1 + 0x898);
  *(undefined1 *)(param_1 + 0xce5 + lVar4 * 6) = *(undefined1 *)(param_1 + 0x89c);
  *(short *)(param_1 + 0xce6 + lVar4 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
  *(undefined2 *)(param_1 + 0xce8 + lVar4 * 6) = 0x119a;
  return;
}



===== KmclpFinishSuspendProcessAndUnlock @ 14000c3c4 =====

void KmclpFinishSuspendProcessAndUnlock(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x77,param_3,param_1,
               (char)*(undefined4 *)(param_1 + 0x898),*(byte *)(param_1 + 0x928) >> 6 & 1);
  }
  *(undefined4 *)(param_1 + 0x89c) = 0;
  LOCK();
  piVar1 = (int *)(param_1 + 0xce0);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  uVar6 = iVar3 + 1;
  uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 == 0) {
    iVar3 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
    iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
  }
  else {
    iVar3 = (uVar6 / 0x18) * -0x18;
  }
  lVar5 = (longlong)(int)(uVar6 + iVar3);
  *(undefined1 *)(param_1 + 0xce4 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x898);
  *(undefined1 *)(param_1 + 0xce5 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x89c);
  *(short *)(param_1 + 0xce6 + lVar5 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
  *(undefined2 *)(param_1 + 0xce8 + lVar5 * 6) = 0x110f;
  if ((*(byte *)(param_1 + 0x928) & 0x40) == 0) {
    lVar5 = 0;
  }
  else {
    lVar5 = *(longlong *)(param_1 + 0xc58);
    *(byte *)(param_1 + 0x928) = *(byte *)(param_1 + 0x928) & 0xbf;
  }
  lVar2 = *(longlong *)(param_1 + 0x8a0);
  *(undefined8 *)(param_1 + 0x8a0) = 0;
  KmclUnlockChannel(param_1);
  if (lVar5 != 0) {
    KmclDecrementRundownCount(*(longlong *)(param_1 + 0xc58),'\x01',0x112a);
  }
  if (lVar2 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x78,
               &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
    }
    KmclpSignalWaiters(lVar2);
  }
  return;
}



===== KmclpInitializeVmbusConnection @ 14000c554 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KmclpInitializeVmbusConnection(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  
  if (*(char *)(param_1 + 0xb08) == '\0') {
    lVar2 = IoAllocateIrp(CONCAT71((int7)((ulonglong)*(longlong *)(param_1 + 0xaa0) >> 8),
                                   *(undefined1 *)(*(longlong *)(param_1 + 0xaa0) + 0x4c)),0);
    *(longlong *)(param_1 + 0xae0) = lVar2;
    if (lVar2 == 0) {
      return -0x3fffff66;
    }
  }
  else {
    *(undefined8 *)(param_1 + 0xae0) = 0;
  }
  (**(code **)(param_1 + 0xa10))(*(undefined8 *)(param_1 + 0x940),0,0,param_1 + 0xad0);
  iVar1 = KmclpEnablePerformanceCounters(param_1);
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}



===== KmclpOpenChannelCompletionCallback @ 14000c5e0 =====

void KmclpOpenChannelCompletionCallback(longlong param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  KeSetEvent(param_1,0,0);
  return;
}



===== KmclpPauseChannel @ 14000c604 =====

void KmclpPauseChannel(longlong param_1,char param_2,undefined8 param_3)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  
  KmclLockChannel(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,param_3,param_1,
                (char)*(undefined4 *)(param_1 + 0x898),(char)*(undefined4 *)(param_1 + 0x89c),
                param_2);
  }
  iVar3 = *(int *)(param_1 + 0x898);
  if (((iVar3 == 0) || (iVar3 == 1)) || ((iVar3 == 3 || ((iVar3 == 4 || (iVar3 == 0xc)))))) {
    KmclUnlockChannel(param_1);
    if (param_2 != '\0') goto LAB_14000c906;
    LOCK();
    piVar1 = (int *)(param_1 + 0xce0);
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    uVar6 = iVar3 + 1;
    uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      iVar3 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
      iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
    }
    else {
      iVar3 = (uVar6 / 0x18) * -0x18;
    }
    param_3 = 0x3bd;
    lVar5 = (longlong)(int)(uVar6 + iVar3);
    *(undefined1 *)(param_1 + 0xce4 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x898);
    *(undefined1 *)(param_1 + 0xce5 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x89c);
    uVar2 = (undefined2)*(undefined4 *)(param_1 + 0x8a8);
    *(undefined2 *)(param_1 + 0xce8 + lVar5 * 6) = 0x3bc;
LAB_14000c8f0:
    *(undefined2 *)(param_1 + 0xce6 + lVar5 * 6) = uVar2;
    KmclDecrementRundownCount(*(longlong *)(param_1 + 0xc58),'\0',(short)param_3);
  }
  else {
    if (*(int *)(param_1 + 0x89c) == 0) {
      *(undefined4 *)(param_1 + 0x89c) = 1;
      LOCK();
      piVar1 = (int *)(param_1 + 0xce0);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      uVar6 = iVar3 + 1;
      uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar4 == 0) {
        iVar3 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
        iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
      }
      else {
        iVar3 = (uVar6 / 0x18) * -0x18;
      }
      lVar5 = (longlong)(int)(uVar6 + iVar3);
      *(undefined1 *)(param_1 + 0xce4 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x898);
      *(undefined1 *)(param_1 + 0xce5 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x89c);
      *(short *)(param_1 + 0xce6 + lVar5 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
      *(undefined2 *)(param_1 + 0xce8 + lVar5 * 6) = 0x3c6;
    }
    else if (*(int *)(param_1 + 0x89c) == 2) {
      *(undefined4 *)(param_1 + 0x89c) = 3;
      LOCK();
      piVar1 = (int *)(param_1 + 0xce0);
      iVar3 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      uVar6 = iVar3 + 1;
      uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar4 == 0) {
        iVar3 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
        iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
      }
      else {
        iVar3 = (uVar6 / 0x18) * -0x18;
      }
      lVar5 = (longlong)(int)(uVar6 + iVar3);
      *(undefined1 *)(param_1 + 0xce4 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x898);
      *(undefined1 *)(param_1 + 0xce5 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x89c);
      *(short *)(param_1 + 0xce6 + lVar5 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
      *(undefined2 *)(param_1 + 0xce8 + lVar5 * 6) = 0x3cb;
      if (*(int *)(param_1 + 0x898) == 0xb) {
        KmclUnlockChannel(param_1);
        if (param_2 != '\0') goto LAB_14000c906;
        LOCK();
        piVar1 = (int *)(param_1 + 0xce0);
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + 1;
        UNLOCK();
        uVar6 = iVar3 + 1;
        uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar4 == 0) {
          iVar3 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
          iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
        }
        else {
          iVar3 = (uVar6 / 0x18) * -0x18;
        }
        param_3 = 0x3e2;
        lVar5 = (longlong)(int)(uVar6 + iVar3);
        *(undefined1 *)(param_1 + 0xce4 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x898);
        *(undefined1 *)(param_1 + 0xce5 + lVar5 * 6) = *(undefined1 *)(param_1 + 0x89c);
        uVar2 = (undefined2)*(undefined4 *)(param_1 + 0x8a8);
        *(undefined2 *)(param_1 + 0xce8 + lVar5 * 6) = 0x3e1;
        goto LAB_14000c8f0;
      }
    }
    KmclpRundownChannelStateAndUnlock(param_1,param_2,param_3);
  }
LAB_14000c906:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,param_3,param_1,param_2);
  }
  return;
}



===== KmclpResumePausedChannelAndUnlock @ 14000c958 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KmclpResumePausedChannelAndUnlock(longlong *param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined1 uVar4;
  int iVar5;
  ulonglong uVar6;
  code *pcVar7;
  longlong lVar8;
  uint uVar9;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x46,param_3,param_1,(char)param_1[0x113]);
  }
  *(undefined4 *)(param_1 + 0x113) = 6;
  LOCK();
  plVar2 = param_1 + 0x19c;
  lVar3 = *plVar2;
  *(int *)plVar2 = (int)*plVar2 + 1;
  UNLOCK();
  uVar9 = (int)lVar3 + 1;
  uVar6 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar6 == 0) {
    iVar5 = (int)((ulonglong)((longlong)(int)uVar9 * -0x2aaaaaab) >> 0x20);
    iVar5 = ((iVar5 >> 2) - (iVar5 >> 0x1f)) * 0x18;
  }
  else {
    iVar5 = (uVar9 / 0x18) * -0x18;
  }
  pcVar7 = (code *)(longlong)(int)(uVar9 + iVar5);
  *(char *)((longlong)param_1 + (longlong)pcVar7 * 6 + 0xce4) = (char)param_1[0x113];
  *(undefined1 *)((longlong)param_1 + (longlong)pcVar7 * 6 + 0xce5) =
       *(undefined1 *)((longlong)param_1 + 0x89c);
  *(short *)((longlong)param_1 + (longlong)pcVar7 * 6 + 0xce6) = (short)param_1[0x115];
  *(undefined2 *)((longlong)param_1 + (longlong)pcVar7 * 6 + 0xce8) = 0xa81;
  if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
    uVar4 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x20);
    plVar2 = param_1 + 0x22;
    pcVar7 = (code *)CONCAT71((int7)((ulonglong)plVar2 >> 8),uVar4);
    uVar9 = ((longlong *)*plVar2 != plVar2) + 1;
    param_3 = (longlong *)(ulonglong)uVar9;
    *(uint *)(param_1 + 0x21) = uVar9;
    KeReleaseSpinLock(param_1 + 0x20);
  }
  KmclUnlockChannel((longlong)param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    pcVar7 = (code *)0x47;
    param_3 = (longlong *)&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x47,
             &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
  }
  if ((char)param_1[0xfd] == '\0') {
    (*(code *)param_1[0x102])(param_1);
  }
  else {
    pcVar7 = (code *)param_1[0xff];
    (*(code *)param_1[0x103])();
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    pcVar7 = (code *)0x48;
    param_3 = (longlong *)&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x48,
             &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
  }
  if ((*(char *)((longlong)param_1 + 0x6c1) == '\0') || (param_1[0x10a] != 0)) {
    pcVar7 = KmclpVmbusManualIsr;
    if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
      pcVar7 = KmclpVmbusIsr;
    }
    param_3 = param_1;
    (*(code *)param_1[0x138])(param_1[0x128]);
  }
  if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pcVar7 = (code *)0x0;
      param_3 = (longlong *)&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x49,
               &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
    }
    pcVar7 = (code *)CONCAT71((int7)((ulonglong)pcVar7 >> 8),1);
    OutPollQueue((longlong)param_1,'\x01');
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pcVar7 = (code *)0x4a;
      param_3 = (longlong *)&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4a,
               &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
    }
    InStartQueue(param_1);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pcVar7 = (code *)0x4b;
      param_3 = (longlong *)&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4b,
               &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
    }
  }
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(param_1 + 0x18d);
  for (plVar2 = (longlong *)param_1[0x194]; plVar2 != param_1 + 0x194; plVar2 = (longlong *)*plVar2)
  {
    plVar1 = plVar2 + -0x196;
    KmclLockChannel((longlong)plVar1);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pcVar7 = (code *)0x4c;
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4c,param_3,param_1,(char)plVar1);
    }
    KmclpStartChannelAndUnlock(plVar1,pcVar7,param_3);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      pcVar7 = (code *)0x4d;
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4d,param_3,param_1,(char)plVar1);
    }
  }
  ExReleaseFastMutexUnsafe(param_1 + 0x18d);
  KeLeaveCriticalRegion();
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = (longlong *)&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4e,
             &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
  }
  if ((char)param_1[0xfd] == '\0') {
    (*(code *)param_1[0x103])(param_1);
  }
  else {
    (*(code *)param_1[0x104])(param_1,param_1[0xff]);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = (longlong *)&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x4f,
             &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
  }
  KmclLockChannel((longlong)param_1);
  lVar3 = param_1[0x113];
  *(undefined4 *)(param_1 + 0x113) = 7;
  LOCK();
  plVar2 = param_1 + 0x19c;
  lVar8 = *plVar2;
  *(int *)plVar2 = (int)*plVar2 + 1;
  UNLOCK();
  uVar9 = (int)lVar8 + 1;
  uVar6 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar6 == 0) {
    iVar5 = (int)((ulonglong)((longlong)(int)uVar9 * -0x2aaaaaab) >> 0x20);
    iVar5 = ((iVar5 >> 2) - (iVar5 >> 0x1f)) * 0x18;
  }
  else {
    iVar5 = (uVar9 / 0x18) * -0x18;
  }
  lVar8 = (longlong)(int)(uVar9 + iVar5);
  *(char *)((longlong)param_1 + lVar8 * 6 + 0xce4) = (char)param_1[0x113];
  *(undefined1 *)((longlong)param_1 + lVar8 * 6 + 0xce5) =
       *(undefined1 *)((longlong)param_1 + 0x89c);
  *(short *)((longlong)param_1 + lVar8 * 6 + 0xce6) = (short)param_1[0x115];
  *(undefined2 *)((longlong)param_1 + lVar8 * 6 + 0xce8) = 0xb23;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    lVar8 = 0x50;
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x50,param_3,param_1,(char)lVar3);
  }
  if ((int)lVar3 == 6) {
    KmclpStartWaitForAction((longlong)param_1,lVar8,param_3);
    KmclUnlockChannel((longlong)param_1);
  }
  else {
    KmclpContinueChannelRundownAndUnlock(param_1,lVar8,param_3);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x51,
             &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
  }
  return;
}



===== KmclpRundownChannelStateAndUnlock @ 14000cea4 =====

void KmclpRundownChannelStateAndUnlock(longlong param_1,char param_2,undefined8 param_3)

{
  undefined7 in_register_00000011;
  longlong lVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  lVar1 = CONCAT71(in_register_00000011,param_2);
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uStack_10 = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    lVar1 = 0x74;
    WPP_SF_qLLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x74,param_3,param_1,
                (char)*(undefined4 *)(param_1 + 0x898),(char)*(undefined4 *)(param_1 + 0x89c),
                param_2);
  }
  if (param_2 == '\0') {
    *(byte *)(param_1 + 0x928) = *(byte *)(param_1 + 0x928) | 0x40;
  }
  else {
    param_3 = 0;
    lVar1 = 1;
    KeInitializeEvent(&local_28);
    uStack_10 = *(undefined8 *)(param_1 + 0x8a0);
    *(undefined8 **)(param_1 + 0x8a0) = &local_28;
  }
  if (*(int *)(param_1 + 0x898) - 8U < 4) {
    KmclUnlockChannel(param_1);
  }
  else {
    KmclpContinueChannelRundownAndUnlock((longlong *)param_1,lVar1,param_3);
  }
  if (param_2 != '\0') {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x75,
               &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
    }
    KeWaitForSingleObject(&local_28,0,0,0,0);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x76,
               &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
    }
  }
  return;
}



===== KmclpRundownCountZero @ 14000d010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KmclpRundownCountZero(undefined8 param_1,longlong *param_2,longlong *param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  int iVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  undefined1 *puVar11;
  longlong *plVar12;
  uint uVar13;
  longlong *plVar14;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  
  KmclLockChannel((longlong)param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x6f,param_3,param_2,(char)param_2[0x113]);
  }
  if ((int)param_2[0x113] == 8) {
    *(undefined4 *)(param_2 + 0x113) = 3;
    LOCK();
    plVar12 = param_2 + 0x19c;
    lVar9 = *plVar12;
    *(int *)plVar12 = (int)*plVar12 + 1;
    UNLOCK();
    uVar13 = (int)lVar9 + 1;
    uVar8 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    puVar11 = auStack_48;
    if ((int)uVar8 == 0) {
      iVar7 = (int)((ulonglong)((longlong)(int)uVar13 * -0x2aaaaaab) >> 0x20);
      iVar7 = ((iVar7 >> 2) - (iVar7 >> 0x1f)) * 0x18;
    }
    else {
      iVar7 = (uVar13 / 0x18) * -0x18;
    }
    lVar10 = (longlong)(int)(uVar13 + iVar7);
    *(char *)((longlong)param_2 + lVar10 * 6 + 0xce4) = (char)param_2[0x113];
    lVar9 = lVar10 * 3;
    *(undefined1 *)((longlong)param_2 + lVar10 * 6 + 0xce5) =
         *(undefined1 *)((longlong)param_2 + 0x89c);
    uVar6 = (undefined2)param_2[0x115];
    *(undefined2 *)((longlong)param_2 + lVar10 * 6 + 0xce8) = 3999;
  }
  else if ((int)param_2[0x113] == 10) {
    if (*(char *)((longlong)param_2 + 0x6c1) == '\0') {
      OutStopQueue((longlong)param_2);
    }
    *(undefined4 *)(param_2 + 0x113) = 4;
    LOCK();
    plVar12 = param_2 + 0x19c;
    lVar9 = *plVar12;
    *(int *)plVar12 = (int)*plVar12 + 1;
    UNLOCK();
    uVar13 = (int)lVar9 + 1;
    uVar8 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    puVar11 = auStack_48;
    if ((int)uVar8 == 0) {
      iVar7 = (int)((ulonglong)((longlong)(int)uVar13 * -0x2aaaaaab) >> 0x20);
      iVar7 = ((iVar7 >> 2) - (iVar7 >> 0x1f)) * 0x18;
    }
    else {
      iVar7 = (uVar13 / 0x18) * -0x18;
    }
    lVar10 = (longlong)(int)(uVar13 + iVar7);
    *(char *)((longlong)param_2 + lVar10 * 6 + 0xce4) = (char)param_2[0x113];
    lVar9 = lVar10 * 3;
    *(undefined1 *)((longlong)param_2 + lVar10 * 6 + 0xce5) =
         *(undefined1 *)((longlong)param_2 + 0x89c);
    uVar6 = (undefined2)param_2[0x115];
    *(undefined2 *)((longlong)param_2 + lVar10 * 6 + 0xce8) = 0xf9a;
  }
  else {
    if (*(char *)((longlong)param_2 + 0x6c1) == '\0') {
      OutPurgeQueue(param_2);
      plVar12 = param_2 + 0xa0;
      plVar14 = (longlong *)*plVar12;
      while (plVar14 != plVar12) {
        plVar1 = (longlong *)*plVar14;
        if ((int)plVar14[2] == 1) {
          puVar2 = (undefined8 *)plVar14[1];
          if (((longlong *)plVar1[1] != plVar14) || ((longlong *)*puVar2 != plVar14)) {
            pcVar3 = (code *)swi(0x29);
            (*pcVar3)(3);
            puVar11 = auStack_40;
            goto LAB_14000d150;
          }
          *puVar2 = plVar1;
          param_3 = (longlong *)0x0;
          plVar1[1] = (longlong)puVar2;
          plVar1 = (longlong *)*plVar14;
          OutCompletePacketToClient((longlong)(plVar14 + -0x12),0xc00002b6,0);
          plVar14 = plVar1;
        }
        else {
          plVar14 = plVar1;
        }
      }
    }
    puVar11 = auStack_48;
    KmclUnlockChannel((longlong)param_2);
    plVar12 = (longlong *)&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_3 = (longlong *)&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x70,
               &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_2);
    }
    if ((char)param_2[0xfd] == '\0') {
LAB_14000d150:
      pcVar3 = (code *)param_2[0x100];
      *(undefined8 *)(puVar11 + -8) = 0x14000d15c;
      (*pcVar3)();
    }
    else {
      (*(code *)param_2[0x101])(param_2,param_2[0xff]);
      puVar11 = auStack_48;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
      *(undefined8 *)(puVar11 + -8) = 0x14000d18a;
      param_3 = plVar12;
      WPP_SF_q(uVar4,0x71,plVar12,param_2);
    }
    if (*(char *)((longlong)param_2 + 0x6c1) == '\0') {
      if (*(char *)((longlong)param_2 + 0x706) != '\0') {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(undefined8 *)(puVar11 + -8) = 0x14000d1d2;
          param_3 = plVar12;
          WPP_SF_q(uVar4,0x72,plVar12,param_2);
        }
        *(undefined8 *)(puVar11 + -8) = 0x14000d1e3;
        uVar5 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x88);
        iVar7 = *(int *)((longlong)param_2 + 0x484);
        puVar11[0x58] = uVar5;
        if ((int)param_2[0x90] != iVar7) {
          *(undefined4 *)(param_2 + 0x89) = 10;
          *(undefined8 *)(puVar11 + -8) = 0x14000d211;
          InpWaitForQueueStopEvent((longlong)param_2,puVar11 + 0x58);
          uVar5 = puVar11[0x58];
        }
        *(undefined8 *)(puVar11 + -8) = 0x14000d221;
        KeReleaseSpinLock(param_2 + 0x88,uVar5);
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (3 < (byte)WPP_GLOBAL_Control[0x29])) {
          uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(undefined8 *)(puVar11 + -8) = 0x14000d254;
          WPP_SF_q(uVar4,0x73,plVar12,param_2);
          param_3 = plVar12;
        }
      }
      *(undefined8 *)(puVar11 + -8) = 0x14000d25c;
      InPurgeQueue(param_2);
    }
    *(undefined8 *)(puVar11 + -8) = 0x14000d264;
    KmclLockChannel((longlong)param_2);
    *(undefined8 *)(puVar11 + -8) = 0x14000d26c;
    KmclpTeardownOpenChannelState(param_2);
    *(undefined4 *)(param_2 + 0x113) = 3;
    LOCK();
    plVar12 = param_2 + 0x19c;
    lVar9 = *plVar12;
    *(int *)plVar12 = (int)*plVar12 + 1;
    UNLOCK();
    uVar13 = (int)lVar9 + 1;
    *(undefined8 *)(puVar11 + -8) = 0x14000d287;
    uVar8 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar8 == 0) {
      iVar7 = (int)((ulonglong)((longlong)(int)uVar13 * -0x2aaaaaab) >> 0x20);
      iVar7 = ((iVar7 >> 2) - (iVar7 >> 0x1f)) * 0x18;
    }
    else {
      iVar7 = (uVar13 / 0x18) * -0x18;
    }
    lVar10 = (longlong)(int)(uVar13 + iVar7);
    *(char *)((longlong)param_2 + lVar10 * 6 + 0xce4) = (char)param_2[0x113];
    lVar9 = lVar10 * 3;
    *(undefined1 *)((longlong)param_2 + lVar10 * 6 + 0xce5) =
         *(undefined1 *)((longlong)param_2 + 0x89c);
    uVar6 = (undefined2)param_2[0x115];
    *(undefined2 *)((longlong)param_2 + lVar10 * 6 + 0xce8) = 0xffb;
  }
  *(undefined2 *)((longlong)param_2 + lVar9 * 2 + 0xce6) = uVar6;
  *(undefined8 *)(puVar11 + -8) = 0x14000d408;
  KmclpContinueChannelRundownAndUnlock(param_2,lVar10,param_3);
  return;
}



===== KmclpRundownCountZeroThread @ 14000d430 =====

void KmclpRundownCountZeroThread(longlong *param_1)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  longlong *plVar7;
  
  cVar2 = *(char *)((longlong)param_1 + 0x8e9);
  while (cVar2 == '\0') {
    plVar7 = (longlong *)0x0;
    KeWaitForSingleObject(param_1 + 0x117,0,0,0,0);
    if (*(char *)((longlong)param_1 + 0x8e9) != '\0') break;
    LOCK();
    plVar1 = param_1 + 0x19c;
    lVar5 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + 1;
    UNLOCK();
    uVar6 = (int)lVar5 + 1;
    uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 == 0) {
      iVar3 = (int)((ulonglong)((longlong)(int)uVar6 * -0x2aaaaaab) >> 0x20);
      iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
    }
    else {
      iVar3 = (uVar6 / 0x18) * -0x18;
    }
    lVar5 = (longlong)(int)(uVar6 + iVar3);
    *(char *)((longlong)param_1 + lVar5 * 6 + 0xce4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar5 * 6 + 0xce5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar5 * 6 + 0xce6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar5 * 6 + 0xce8) = 0x1054;
    KmclpRundownCountZero(0,param_1,plVar7);
    cVar2 = *(char *)((longlong)param_1 + 0x8e9);
  }
  KeSetEvent(param_1 + 0x11a,0,0);
  return;
}



===== KmclpSignalWaiters @ 14000d540 =====

void KmclpSignalWaiters(longlong param_1)

{
  longlong lVar1;
  
  while (param_1 != 0) {
    lVar1 = *(longlong *)(param_1 + 0x18);
    KeSetEvent(param_1,0,0);
    param_1 = lVar1;
  }
  return;
}



===== KmclpStartChannelAndUnlock @ 14000d574 =====

void KmclpStartChannelAndUnlock(longlong *param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_2 = 0x21;
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,param_3,param_1,(char)param_1[0x113]);
  }
  iVar2 = (int)param_1[0x113];
  if ((iVar2 != 0) && (iVar2 != 1)) {
    if (iVar2 == 3) {
      *(undefined4 *)(param_1 + 0x113) = 5;
      LOCK();
      plVar1 = param_1 + 0x19c;
      lVar4 = *plVar1;
      *(int *)plVar1 = (int)*plVar1 + 1;
      UNLOCK();
      uVar5 = (int)lVar4 + 1;
      uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar3 == 0) {
        iVar2 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
        iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
      }
      else {
        iVar2 = (uVar5 / 0x18) * -0x18;
      }
      lVar4 = (longlong)(int)(uVar5 + iVar2);
      *(char *)((longlong)param_1 + lVar4 * 6 + 0xce4) = (char)param_1[0x113];
      *(undefined1 *)((longlong)param_1 + lVar4 * 6 + 0xce5) =
           *(undefined1 *)((longlong)param_1 + 0x89c);
      *(short *)((longlong)param_1 + lVar4 * 6 + 0xce6) = (short)param_1[0x115];
      *(undefined2 *)((longlong)param_1 + lVar4 * 6 + 0xce8) = 0x486;
      KmclpStartWaitForAction((longlong)param_1,lVar4,param_3);
    }
    else {
      if (iVar2 == 4) {
        KmclpResumePausedChannelAndUnlock(param_1,param_2,param_3);
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
          return;
        }
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
                 &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
        return;
      }
      if (((iVar2 != 5) && (iVar2 != 7)) &&
         ((iVar2 != 10 && ((iVar2 == 0xb && (*(int *)((longlong)param_1 + 0x89c) == 3)))))) {
        *(undefined4 *)((longlong)param_1 + 0x89c) = 2;
        LOCK();
        plVar1 = param_1 + 0x19c;
        lVar4 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + 1;
        UNLOCK();
        uVar5 = (int)lVar4 + 1;
        uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar3 == 0) {
          iVar2 = (int)((ulonglong)((longlong)(int)uVar5 * -0x2aaaaaab) >> 0x20);
          iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
        }
        else {
          iVar2 = (uVar5 / 0x18) * -0x18;
        }
        lVar4 = (longlong)(int)(uVar5 + iVar2);
        *(char *)((longlong)param_1 + lVar4 * 6 + 0xce4) = (char)param_1[0x113];
        *(undefined1 *)((longlong)param_1 + lVar4 * 6 + 0xce5) =
             *(undefined1 *)((longlong)param_1 + 0x89c);
        *(short *)((longlong)param_1 + lVar4 * 6 + 0xce6) = (short)param_1[0x115];
        *(undefined2 *)((longlong)param_1 + lVar4 * 6 + 0xce8) = 0x467;
      }
    }
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,param_3,param_1,(char)param_1[0x113]);
  }
  KmclUnlockChannel((longlong)param_1);
  return;
}



===== KmclpStartWaitForAction @ 14000d7d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KmclpStartWaitForAction(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5e,param_3,param_1,
               (char)*(undefined4 *)(param_1 + 0x898),*(undefined1 *)(param_1 + 0xaf5));
  }
  if (*(char *)(param_1 + 0xaf5) == '\0') {
    if (*(char *)(param_1 + 0xb08) == '\0') {
      lVar1 = *(longlong *)(param_1 + 0xae0);
      IoReuseIrp(lVar1,0x103);
      lVar2 = *(longlong *)(lVar1 + 0xb8);
      *(undefined4 *)(lVar2 + -0x38) = 0;
      *(undefined1 *)(lVar2 + -0x48) = 0xe;
      *(undefined4 *)(lVar2 + -0x30) = 0x3ec008;
      *(undefined4 *)(lVar2 + -0x40) = 4;
      *(undefined8 *)(lVar2 + -0x18) = *(undefined8 *)(param_1 + 0xaa8);
      *(undefined8 *)(lVar2 + -0x20) = *(undefined8 *)(param_1 + 0xaa0);
      *(undefined1 *)(lVar1 + 0x40) = 0;
      *(void **)(lVar1 + 0x98) = SystemReserved1[0xf];
      *(undefined8 *)(lVar1 + 0xc0) = *(undefined8 *)(lVar2 + -0x18);
      *(longlong *)(lVar1 + 0x18) = param_1 + 0xaf0;
      *(longlong *)(lVar1 + 0x70) = param_1 + 0xaf0;
      lVar3 = *(longlong *)(lVar1 + 0xb8);
      *(code **)(lVar3 + -0x10) = KmclpWaitForActionCompleted;
      *(longlong *)(lVar3 + -8) = param_1;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      IofCallDriver(*(undefined8 *)(lVar2 + -0x20),lVar1);
    }
    else {
      uVar4 = (**(code **)(param_1 + 0xb30))
                        (*(undefined8 *)(param_1 + 0xb18),KmclpDirectWaitForActionCallback,param_1);
      if ((int)uVar4 < 0) {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
          return;
        }
        WPP_SF_qLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5f,(ulonglong)uVar4,param_1,
                   (char)*(undefined4 *)(param_1 + 0x898),(char)uVar4);
        return;
      }
    }
  }
  else {
    *(undefined1 *)(param_1 + 0xaf5) = 0;
    IoQueueWorkItem(*(undefined8 *)(param_1 + 0xae8),KmclpWaitForActionWorkerRoutine,1,param_1);
  }
  *(undefined1 *)(param_1 + 0xaf4) = 1;
  return;
}



===== KmclpSynchronousIoControl @ 14000d99c =====

ulonglong KmclpSynchronousIoControl
                    (longlong param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
                    undefined8 param_5,undefined4 param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_38 [6];
  
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  KeInitializeEvent(local_38 + 2,1,0);
  lVar1 = IoBuildDeviceIoControlRequest
                    (param_2,*(undefined8 *)(param_1 + 0xaa0),param_3,param_4,param_5,param_6,0,
                     local_38 + 2,local_38);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    *(undefined8 *)(*(longlong *)(lVar1 + 0xb8) + -0x18) = *(undefined8 *)(param_1 + 0xaa8);
    uVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0xaa0),lVar1);
    if ((int)uVar2 == 0x103) {
      KeWaitForSingleObject(local_38 + 2,0,0,0,0);
      uVar2 = local_38[0] & 0xffffffff;
    }
  }
  return uVar2;
}



===== KmclpTeardownOpenChannelState @ 14000dab4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void KmclpTeardownOpenChannelState(longlong *param_1)

{
  if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
    PkUninitializeRingBuffer((longlong)(param_1 + 8));
    InCloseChannel(param_1);
  }
  if ((char)param_1[0xd8] != '\0') {
    ExAcquirePushLockExclusiveEx(param_1 + 0x15f,0);
    *(undefined1 *)((longlong)param_1 + 0xaf6) = 0;
    ExReleasePushLockExclusiveEx(param_1 + 0x15f,0);
    if ((int)param_1[0x183] != 0) {
      param_1[0x152] = 0;
      (*(code *)param_1[0x135])(param_1[0x128]);
      *(undefined4 *)(param_1 + 0x183) = 0;
    }
    if ((*(byte *)(param_1 + 0x125) & 0x10) != 0) {
      (*(code *)param_1[299])(param_1[0x128]);
      *(byte *)(param_1 + 0x125) = *(byte *)(param_1 + 0x125) & 0xef;
    }
  }
  return;
}



===== KmclpVmbusArrivalNotification @ 14000db80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x00014000ddf5) */
/* WARNING: Removing unreachable block (ram,0x00014000de0c) */
/* WARNING: Removing unreachable block (ram,0x00014000de18) */
/* WARNING: Removing unreachable block (ram,0x00014000de22) */

undefined8 KmclpVmbusArrivalNotification(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined2 uVar8;
  undefined **ppuVar9;
  undefined8 uVar10;
  longlong *plVar11;
  bool bVar12;
  undefined1 auStackY_118 [32];
  undefined1 uVar13;
  undefined1 local_e0 [16];
  longlong local_d0;
  longlong local_c8;
  short local_bc;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_118;
  uVar10 = 0xb0;
  memset(local_e0,0,0xb0);
  lVar6 = 0;
  bVar12 = (void *)param_2[0x150] != SystemReserved1[0xf];
  if (bVar12) {
    KmclLockChannel((longlong)param_2);
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,uVar10,param_2,(char)param_2[0x113]);
  }
  if (((int)param_2[0x151] != 0x103) || ((int)param_2[0x113] != 1)) {
LAB_14000dfd0:
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2d,uVar10,param_2,(char)param_2[0x113])
      ;
    }
    if (bVar12) {
      KmclUnlockChannel((longlong)param_2);
    }
    return 0;
  }
  lVar5 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4004;
  if (lVar5 == 0) {
    lVar5 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
  }
  if (lVar5 != 0) goto LAB_14000dfd0;
  plVar1 = param_2 + 0x154;
  plVar2 = param_2 + 0x155;
  uVar3 = IoGetDeviceObjectPointer(*(undefined8 *)(param_1 + 0x28),0x1f01ff,plVar2,plVar1);
  plVar11 = (longlong *)(ulonglong)uVar3;
  if ((int)uVar3 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      lVar6 = 0;
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,plVar11,param_2,(char)uVar3);
    }
    goto LAB_14000dcdf;
  }
  ObfReferenceObject(*plVar1);
  lVar6 = IoGetDeviceAttachmentBaseRef(*plVar1);
  IoGetDeviceProperty(lVar6);
  plVar11 = (longlong *)0x0;
  ppuVar9 = (undefined **)0x3ec024;
  uVar7 = KmclpSynchronousIoControl((longlong)param_2,0x3ec024,0,0,local_e0,0xb0);
  iVar4 = (int)uVar7;
  if (iVar4 < 0) {
    ppuVar9 = &WPP_GLOBAL_Control;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_14000dd19;
    if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_14000dce4;
    uVar8 = 0x30;
    uVar13 = (undefined1)uVar7;
LAB_14000de91:
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar8,plVar11,param_2,uVar13);
LAB_14000dce4:
    ppuVar9 = &WPP_GLOBAL_Control;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      ppuVar9 = (undefined **)0x33;
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x33,plVar11,param_2,(char)iVar4);
    }
  }
  else {
    lVar5 = *(longlong *)((longlong)param_2 + 0x6ec);
    if (lVar5 == 0) {
      lVar5 = *(longlong *)((longlong)param_2 + 0x6f4);
    }
    if (lVar5 == 0) {
      if (local_bc == 0) goto LAB_14000df07;
LAB_14000dcdf:
      iVar4 = 0x103;
      goto LAB_14000dce4;
    }
    local_d0 = *(longlong *)((longlong)param_2 + 0x6ec) - local_d0;
    if (local_d0 == 0) {
      local_d0 = *(longlong *)((longlong)param_2 + 0x6f4) - local_c8;
    }
    if ((local_d0 != 0) || ((short)param_2[0x19a] != local_bc)) goto LAB_14000dcdf;
LAB_14000df07:
    iVar4 = VmbusSendInterfaceQuery((longlong)param_2);
    if (-1 < iVar4) {
      if (bVar12) {
        uVar7 = KmclpClientOpenChannel(param_2);
        iVar4 = (int)uVar7;
        if (iVar4 < 0) {
          if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
            if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar8 = 0x32;
              goto LAB_14000df46;
            }
            goto LAB_14000dce4;
          }
          goto LAB_14000dd19;
        }
      }
      iVar4 = 0;
      goto LAB_14000dce4;
    }
    if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        uVar8 = 0x31;
LAB_14000df46:
        uVar13 = (undefined1)iVar4;
        goto LAB_14000de91;
      }
      goto LAB_14000dce4;
    }
  }
LAB_14000dd19:
  *(int *)(param_2 + 0x151) = iVar4;
  if (iVar4 != 0) {
    VmbusDropInterface((longlong)param_2);
    if (*plVar1 != 0) {
      ObfDereferenceObject();
      *plVar1 = 0;
    }
    if (*plVar2 != 0) {
      ObfDereferenceObject();
      *plVar2 = 0;
    }
  }
  if (bVar12) {
    if (iVar4 != 0x103) {
      if (param_2[0x14f] != 0) {
        IoUnregisterPlugPlayNotificationEx();
        param_2[0x14f] = 0;
      }
      if (iVar4 == 0) {
        KmclpResumePausedChannelAndUnlock(param_2,ppuVar9,plVar11);
        goto LAB_14000dfba;
      }
    }
    KmclUnlockChannel((longlong)param_2);
    if (iVar4 < 0) {
      (*(code *)param_2[0x10b])(param_2,iVar4);
    }
  }
LAB_14000dfba:
  if (lVar6 == 0) {
    return 0;
  }
  ObfDereferenceObject(lVar6);
  return 0;
}



===== KmclpVmbusManualIsr @ 14000e050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool KmclpVmbusManualIsr(longlong param_1)

{
  char cVar1;
  
  *(longlong *)(param_1 + 0x680) = *(longlong *)(param_1 + 0x680) + 1;
  cVar1 = (**(code **)(param_1 + 0x850))();
  if (cVar1 == '\0') {
    *(int *)(param_1 + 0x690) = *(int *)(param_1 + 0x690) + 1;
  }
  return cVar1 != '\0';
}



===== KmclpWaitForActionCompleted @ 14000e090 =====

undefined8 KmclpWaitForActionCompleted(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  IoQueueWorkItem(*(undefined8 *)(param_3 + 0xae8),KmclpWaitForActionWorkerRoutine,1,param_3);
  return 0xc0000016;
}



===== KmclpWaitForActionWorkerRoutine @ 14000e0d0 =====

void KmclpWaitForActionWorkerRoutine(undefined8 param_1,longlong *param_2,undefined8 param_3)

{
  longlong *plVar1;
  undefined2 uVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  int iVar6;
  longlong lVar7;
  uint uVar8;
  longlong *plVar9;
  
  KmclLockChannel((longlong)param_2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x60,param_3,param_2,(char)param_2[0x113]);
  }
  *(undefined1 *)((longlong)param_2 + 0xaf4) = 0;
  if ((char)param_2[0x161] == '\0') {
    uVar4 = (ulonglong)*(uint *)(param_2[0x15c] + 0x30);
  }
  else {
    uVar4 = 0;
  }
  iVar3 = (int)param_2[0x113];
  uVar8 = *(uint *)(param_2 + 0x15e);
  plVar9 = (longlong *)(ulonglong)uVar8;
  iVar6 = (int)uVar4;
  if (iVar3 == 5) {
    if (-1 < iVar6) {
      if (uVar8 == 1) {
        uVar5 = KmclpServerOpenChannel(param_2,uVar4,(undefined *)0x1);
        if (-1 < (int)uVar5) {
          KmclpResumePausedChannelAndUnlock(param_2,uVar4,plVar9);
          goto LAB_14000e2e9;
        }
      }
LAB_14000e2d9:
      KmclpStartWaitForAction((longlong)param_2,uVar4,plVar9);
    }
  }
  else if (iVar3 == 7) {
    if (-1 < iVar6) {
      if (uVar8 == 3) {
        *(undefined4 *)((longlong)param_2 + 0x89c) = 2;
        LOCK();
        plVar1 = param_2 + 0x19c;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + 1;
        UNLOCK();
        uVar8 = (int)lVar7 + 1;
        uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar4 == 0) {
          iVar3 = (int)((ulonglong)((longlong)(int)uVar8 * -0x2aaaaaab) >> 0x20);
          iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
        }
        else {
          iVar3 = (uVar8 / 0x18) * -0x18;
        }
        lVar7 = (longlong)(int)(uVar8 + iVar3);
        *(char *)((longlong)param_2 + lVar7 * 6 + 0xce4) = (char)param_2[0x113];
        *(undefined1 *)((longlong)param_2 + lVar7 * 6 + 0xce5) =
             *(undefined1 *)((longlong)param_2 + 0x89c);
        uVar2 = (undefined2)param_2[0x115];
        *(undefined2 *)((longlong)param_2 + lVar7 * 6 + 0xce8) = 0xd79;
      }
      else {
        if (uVar8 != 4) goto LAB_14000e2d9;
        *(undefined4 *)((longlong)param_2 + 0x89c) = 4;
        LOCK();
        plVar1 = param_2 + 0x19c;
        lVar7 = *plVar1;
        *(int *)plVar1 = (int)*plVar1 + 1;
        UNLOCK();
        uVar8 = (int)lVar7 + 1;
        uVar4 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar4 == 0) {
          iVar3 = (int)((ulonglong)((longlong)(int)uVar8 * -0x2aaaaaab) >> 0x20);
          iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
        }
        else {
          iVar3 = (uVar8 / 0x18) * -0x18;
        }
        lVar7 = (longlong)(int)(uVar8 + iVar3);
        *(char *)((longlong)param_2 + lVar7 * 6 + 0xce4) = (char)param_2[0x113];
        *(undefined1 *)((longlong)param_2 + lVar7 * 6 + 0xce5) =
             *(undefined1 *)((longlong)param_2 + 0x89c);
        uVar2 = (undefined2)param_2[0x115];
        *(undefined2 *)((longlong)param_2 + lVar7 * 6 + 0xce8) = 0xd80;
      }
      *(undefined2 *)((longlong)param_2 + lVar7 * 6 + 0xce6) = uVar2;
      KmclpContinueChannelRundownAndUnlock(param_2,lVar7,plVar9);
      goto LAB_14000e2e9;
    }
  }
  else if ((iVar3 == 8) || (iVar3 == 10)) {
    if (-1 < iVar6) {
      *(undefined1 *)((longlong)param_2 + 0xaf5) = 1;
    }
    KmclDecrementRundownCount((longlong)param_2,'\x01',0xdaa);
  }
  KmclUnlockChannel((longlong)param_2);
LAB_14000e2e9:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x61,
             &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_2);
  }
  return;
}



===== RtlUnicodeStringPrintf @ 14000e334 =====

undefined8
RtlUnicodeStringPrintf(ushort *param_1,wchar_t *param_2,undefined8 param_3,undefined8 param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong _Count;
  undefined8 local_res18;
  undefined8 local_res20;
  
  uVar1 = *param_1;
  if ((((((uVar1 & 1) == 0) && (uVar2 = param_1[1], (uVar2 & 1) == 0)) && (uVar1 <= uVar2)) &&
      (uVar2 != 0xffff)) &&
     ((uVar5 = 0, *(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    _Count = (ulonglong)(param_1[1] >> 1);
    local_res18 = param_3;
    local_res20 = param_4;
    iVar3 = _vsnwprintf(*(wchar_t **)(param_1 + 4),_Count,param_2,(va_list)&local_res18);
    if ((iVar3 < 0) || (uVar4 = (longlong)iVar3, _Count < (ulonglong)(longlong)iVar3)) {
      uVar5 = 0x80000005;
      uVar4 = _Count;
    }
    *param_1 = (short)uVar4 * 2;
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== VmbChannelDisable @ 14000e3e0 =====

void VmbChannelDisable(longlong param_1,undefined8 param_2,undefined8 param_3)

{
                    /* 0xe3e0  12  VmbChannelDisable */
  KmclpDisableChannel(param_1,'\x01',param_3);
  return;
}



===== VmbChannelEnable @ 14000e400 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong VmbChannelEnable(longlong *param_1,undefined8 param_2,ulonglong param_3)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  undefined2 uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  bool bVar9;
  
                    /* 0xe400  13  VmbChannelEnable */
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = (ulonglong)(*(byte *)(param_1 + 0x125) >> 2 & 1);
    WPP_SF_qLd_guid__guid_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(longlong)param_1 + 0x6dc,param_3,param_1,
               (char)param_1[0x113],*(byte *)(param_1 + 0x125) >> 2 & 1,(longlong)param_1 + 0x6dc,
               (longlong)param_1 + 0x6ec);
  }
  if ((int)param_1[0x113] == 0xc) {
    if ((char)param_1[0xfd] == '\0') {
      (*(code *)param_1[0xff])(param_1);
    }
    else {
      (*(code *)param_1[0x100])(param_1,param_1[0xff]);
    }
    return 0;
  }
  if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
    param_3 = (ulonglong)*(uint *)(param_1 + 0xd9);
    if (*(uint *)(param_1 + 0xd9) == 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000000d;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return 0xc000000d;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc000000d;
      }
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,0,param_1,0);
      return 0xc000000d;
    }
  }
  else if (*(char *)((longlong)param_1 + 0x706) != '\0') {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0xc000000d;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc000000d;
    }
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
             &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
    return 0xc000000d;
  }
  if ((int)param_1[0xda] == 0) {
    *(undefined4 *)(param_1 + 0xda) = 1;
  }
  if (*(int *)((longlong)param_1 + 0x6fc) == 0) {
    *(undefined4 *)((longlong)param_1 + 0x6fc) = 1;
  }
  uVar7 = 0;
  if ((((int)param_1[0xe2] != 0) || (*(int *)((longlong)param_1 + 0x714) != 0)) ||
     (((int)param_1[0xe3] != 0 || (*(int *)((longlong)param_1 + 0x71c) != 0)))) {
    plVar5 = (longlong *)param_1[0xf4];
    param_3 = 0;
    if (plVar5 != (longlong *)0x0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc000000d;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return 0xc000000d;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc000000d;
      }
      uVar6 = 0xd;
      plVar8 = plVar5;
      goto LAB_14000e670;
    }
  }
  if ((*(char *)((longlong)param_1 + 0x701) != '\0') &&
     ((((int)param_1[0xe2] != 0 || (*(int *)((longlong)param_1 + 0x714) != 0)) ||
      (((int)param_1[0xe3] != 0 ||
       ((*(int *)((longlong)param_1 + 0x71c) != 0 || (param_1[0xf4] != 0)))))))) {
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc000000d;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
      return 0xc000000d;
    }
    if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
      return 0xc000000d;
    }
    plVar8 = (longlong *)param_1[0xf4];
    plVar5 = param_1 + 0xe2;
    uVar6 = 0xe;
LAB_14000e670:
    WPP_SF_q_guid_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,plVar5,param_1,param_1 + 0xe2,
                    (char)plVar8);
    return 0xc000000d;
  }
  if ((*(char *)((longlong)param_1 + 0x6c1) == '\0') && ((*(byte *)(param_1 + 0x125) & 0x20) == 0))
  {
    uVar3 = InInitializeQueue(param_1);
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar4;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return uVar4;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return uVar4;
      }
      uVar6 = 0xf;
LAB_14000e6c9:
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,param_3,param_1,(char)uVar4);
      return uVar4;
    }
    uVar3 = OutInitializeQueue(param_1);
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar4;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return uVar4;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return uVar4;
      }
      uVar6 = 0x10;
      goto LAB_14000e6c9;
    }
    *(byte *)(param_1 + 0x125) = *(byte *)(param_1 + 0x125) | 0x20;
  }
  if ((char)param_1[0xd8] == '\0') {
    LOCK();
    iVar1 = KmclDirectInterfaceReferenceCount + 1;
    UNLOCK();
    bVar9 = KmclDirectInterfaceReferenceCount == 0;
    KmclDirectInterfaceReferenceCount = iVar1;
    if (bVar9) {
      do {
        iVar1 = KmclpFindVmbus();
      } while (iVar1 < 0);
      param_3 = 0;
      uVar7 = 0;
      KeSetEvent(&KmclDirectInterfaceReady);
    }
    else {
      param_3 = 0;
      uVar7 = 0;
      KeWaitForSingleObject(&KmclDirectInterfaceReady,0,0,0,0);
    }
  }
  plVar5 = (longlong *)param_1[0x18b];
  if (plVar5 == (longlong *)0x0) {
    if ((char)param_1[0x18c] != '\0') {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000184;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return 0xc0000184;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 2) {
        return 0xc0000184;
      }
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,param_3,param_1,(char)param_1[0x113]
               );
      return 0xc0000184;
    }
    KmclLockChannel((longlong)param_1);
  }
  else {
    KmclLockChannel((longlong)plVar5);
    KmclLockChannel((longlong)param_1);
    uVar2 = *(uint *)(plVar5 + 0x113);
    uVar7 = (ulonglong)uVar2;
    if ((10 < uVar2) || ((0x6d0U >> (uVar2 & 0x1f) & 1) == 0)) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qLqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,param_3,param_1,
                    (char)param_1[0x113],(char)plVar5,(char)uVar2);
      }
      KmclUnlockChannel((longlong)param_1);
      goto LAB_14000e9ab;
    }
    KmclUnlockChannel((longlong)plVar5);
  }
  uVar2 = *(uint *)(param_1 + 0x113);
  plVar8 = (longlong *)(ulonglong)uVar2;
  if ((uVar2 == 0) && ((*(byte *)(param_1 + 0x125) & 4) == 0)) {
    if ((char)param_1[0xd8] == '\0') {
      uVar2 = KmclpClientFindVmbusAndUnlock(param_1,uVar7,(longlong *)0x0);
      uVar3 = (ulonglong)uVar2;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return uVar3;
      }
      if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,plVar8,param_1,(char)uVar2);
      }
    }
    else {
      uVar4 = KmclpServerOfferChannel(param_1);
      uVar3 = uVar4 & 0xffffffff;
      KmclUnlockChannel((longlong)param_1);
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          (uVar7 = (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),
          (*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
      {
        WPP_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,plVar8,param_1,(char)plVar5,
                   (char)uVar4);
      }
      if (plVar5 != (longlong *)0x0) {
        KmclLockChannel((longlong)plVar5);
        if ((int)plVar5[0x113] - 6U < 2) {
          KmclLockChannel((longlong)param_1);
          KmclUnlockChannel((longlong)plVar5);
          KmclpStartChannelAndUnlock(param_1,uVar7,plVar8);
        }
        else {
          KmclUnlockChannel((longlong)plVar5);
        }
      }
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,plVar8,param_1,(char)uVar3);
    }
    return uVar3;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,plVar8,param_1,(char)uVar2,
               *(byte *)(param_1 + 0x125) >> 2 & 1);
  }
  plVar5 = param_1;
LAB_14000e9ab:
  KmclUnlockChannel((longlong)plVar5);
  return 0xc0000184;
}



===== VmbChannelGetServicingState @ 14000e9e0 =====

bool VmbChannelGetServicingState(longlong param_1,undefined8 param_2,undefined8 param_3)

{
                    /* 0xe9e0  23  VmbChannelGetServicingState */
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,param_3,param_1,
              (char)*(undefined4 *)(param_1 + 0x898));
  }
  return *(int *)(param_1 + 0x898) == 0xc;
}



===== VmbChannelSetInterruptLatency @ 14000ea40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelSetInterruptLatency(longlong param_1)

{
                    /* 0xea40  60  VmbChannelSetInterruptLatency */
  (**(code **)(param_1 + 0xa50))(*(undefined8 *)(param_1 + 0x940));
  return;
}



===== VmbChannelSetServicingState @ 14000ea70 =====

undefined8 VmbChannelSetServicingState(longlong param_1,char param_2,undefined8 param_3)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined8 uVar9;
  longlong *plVar10;
  
                    /* 0xea70  63  VmbChannelSetServicingState */
  KmclLockChannel(param_1);
  iVar3 = *(int *)(param_1 + 0x898);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,param_3,param_1,(char)iVar3,param_2);
  }
  uVar9 = 0;
  if ((*(char *)(param_1 + 0xb51) == '\0') && (*(int *)(param_1 + 0x108) == 0)) {
    if (param_2 == '\0') {
      if ((iVar3 != 0xc) || (*(longlong *)(param_1 + 0xcc0) == 0)) goto LAB_14000ecc8;
      uVar7 = 4;
    }
    else {
      if (iVar3 != 4) goto LAB_14000ecc8;
      uVar7 = 0xc;
      KmclChannelCleanupParentDevice(param_1);
    }
    *(undefined4 *)(param_1 + 0x898) = uVar7;
    LOCK();
    piVar1 = (int *)(param_1 + 0xce0);
    iVar4 = *piVar1;
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    uVar8 = iVar4 + 1;
    uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar5 == 0) {
      iVar4 = (int)((ulonglong)((longlong)(int)uVar8 * -0x2aaaaaab) >> 0x20);
      iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
    }
    else {
      iVar4 = (uVar8 / 0x18) * -0x18;
    }
    lVar6 = (longlong)(int)(uVar8 + iVar4);
    plVar2 = (longlong *)(param_1 + 0xca0);
    *(undefined1 *)(param_1 + 0xce4 + lVar6 * 6) = *(undefined1 *)(param_1 + 0x898);
    *(undefined1 *)(param_1 + 0xce5 + lVar6 * 6) = *(undefined1 *)(param_1 + 0x89c);
    *(short *)(param_1 + 0xce6 + lVar6 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
    *(undefined2 *)(param_1 + 0xce8 + lVar6 * 6) = 0x33d;
    if ((longlong *)*plVar2 != plVar2) {
      KeEnterCriticalRegion();
      ExAcquireFastMutexUnsafe(param_1 + 0xc68);
      plVar10 = (longlong *)*plVar2;
      if (plVar10 != plVar2) {
        do {
          if (iVar3 == 4) {
            KmclChannelCleanupParentDevice((longlong)(plVar10 + -0x196));
          }
          *(undefined4 *)(plVar10 + -0x83) = uVar7;
          LOCK();
          plVar2 = plVar10 + 6;
          lVar6 = *plVar2;
          *(int *)plVar2 = (int)*plVar2 + 1;
          UNLOCK();
          uVar8 = (int)lVar6 + 1;
          uVar5 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
          if ((int)uVar5 == 0) {
            iVar4 = (int)((ulonglong)((longlong)(int)uVar8 * -0x2aaaaaab) >> 0x20);
            iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
          }
          else {
            iVar4 = (uVar8 / 0x18) * -0x18;
          }
          lVar6 = (longlong)(int)(uVar8 + iVar4);
          *(char *)((longlong)plVar10 + lVar6 * 6 + 0x34) = (char)plVar10[-0x83];
          *(undefined1 *)((longlong)plVar10 + lVar6 * 6 + 0x35) =
               *(undefined1 *)((longlong)plVar10 + -0x414);
          *(short *)((longlong)plVar10 + lVar6 * 6 + 0x36) = (short)plVar10[-0x81];
          *(undefined2 *)((longlong)plVar10 + lVar6 * 6 + 0x38) = 0x359;
          plVar10 = (longlong *)*plVar10;
        } while (plVar10 != (longlong *)(param_1 + 0xca0));
      }
      ExReleaseFastMutexUnsafe(param_1 + 0xc68);
      KeLeaveCriticalRegion();
    }
  }
  else {
LAB_14000ecc8:
    uVar9 = 0xc0000184;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,param_3,param_1,(char)iVar3);
    }
  }
  KmclUnlockChannel(param_1);
  return uVar9;
}



===== WPP_SF_qL @ 14000ed2c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qL(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_2,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_qLL @ 14000ed84 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,0x18,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qLLd @ 14000edec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLLd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qL_guid__guid_ @ 14000ee60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qL_guid__guid_
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined8 param_6,undefined8 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,0x1e,&local_res20,8,
             &param_5,4,param_6,0x10,param_7,0x10,0);
  return;
}



===== WPP_SF_qLd @ 14000eee0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_2,&local_res20,8,
             &param_5,4,&param_6,4,0);
  return;
}



===== WPP_SF_qLd_guid__guid_ @ 14000ef48 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLd_guid__guid_
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6,undefined8 param_7,undefined8 param_8)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,10,&local_res20,8,
             &param_5,4,&param_6,4,param_7,0x10,param_8,0x10,0);
  return;
}



===== WPP_SF_qLdd @ 14000efd8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLdd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,0x1f,&local_res20,8,
             &param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qLqd @ 14000f04c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qLqd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,0x11,&local_res20,8,
             &param_5,4,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_SF_q_guid_q @ 14000f0c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q_guid_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                    undefined8 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_2,&local_res20,8,
             param_5,0x10,&param_6,8,0);
  return;
}



===== WPP_SF_qq @ 14000f12c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_2,&local_res20,8,
             &param_5,8,0);
  return;
}



===== WPP_SF_qqd @ 14000f184 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,0x14,&local_res20,8,
             &param_5,8,&param_6,4,0);
  return;
}



===== VmbChannelAllocateBounceBuffer @ 14000f1f0 =====

uint VmbChannelAllocateBounceBuffer(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  
                    /* 0xf1f0  4  VmbChannelAllocateBounceBuffer */
  if (*(char *)(param_1 + 0x6c0) == '\0') {
    uVar1 = KmclpAllocateBounceBlock(param_1,param_2,1);
  }
  else {
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



===== VmbChannelAllocateForStorage @ 14000f220 =====

undefined8 VmbChannelAllocateForStorage(longlong param_1)

{
  undefined8 uVar1;
  
                    /* 0xf220  5  VmbChannelAllocateForStorage */
  if (*(char *)(param_1 + 0x6c0) == '\0') {
    if (*(int *)(param_1 + 0x898) == 0) {
      uVar1 = KmclpAllocateForStorageChannel(param_1);
    }
    else {
      uVar1 = 0xc00000ef;
    }
  }
  else {
    uVar1 = 0xc00000bb;
  }
  return uVar1;
}



===== VmbChannelCreateGpadl @ 14000f260 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelCreateGpadl
               (longlong param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  
                    /* 0xf260  7  VmbChannelCreateGpadl */
  iVar1 = (**(code **)(param_1 + 0x970))(*(undefined8 *)(param_1 + 0x940),param_3,param_4);
  if (-1 < iVar1) {
    LOCK();
    *(int *)(param_1 + 0xb00) = *(int *)(param_1 + 0xb00) + 1;
    UNLOCK();
  }
  return;
}



===== VmbChannelCreateGpadlFromBuffer @ 14000f2a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelCreateGpadlFromBuffer
               (longlong param_1,uint param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5)

{
  int iVar1;
  
                    /* 0xf2a0  8  VmbChannelCreateGpadlFromBuffer */
  iVar1 = (**(code **)(param_1 + 0x978))
                    (*(undefined8 *)(param_1 + 0x940),param_3,param_4,(~param_2 & 1) * 2,param_5);
  if (-1 < iVar1) {
    LOCK();
    *(int *)(param_1 + 0xb00) = *(int *)(param_1 + 0xb00) + 1;
    UNLOCK();
  }
  return;
}



===== VmbChannelCreateGpadlFromMdl @ 14000f300 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelCreateGpadlFromMdl
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5,undefined8 param_6)

{
  int iVar1;
  
                    /* 0xf300  9  VmbChannelCreateGpadlFromMdl */
  iVar1 = (**(code **)(param_1 + 0x988))
                    (*(undefined8 *)(param_1 + 0x940),param_3,param_4,param_5,param_6);
  if (-1 < iVar1) {
    LOCK();
    *(int *)(param_1 + 0xb00) = *(int *)(param_1 + 0xb00) + 1;
    UNLOCK();
  }
  return;
}



===== VmbChannelCreateGpadlFromPfnList @ 14000f350 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
VmbChannelCreateGpadlFromPfnList
          (longlong param_1,undefined8 param_2,longlong param_3,int param_4,undefined8 param_5)

{
  undefined8 uVar1;
  
                    /* 0xf350  10  VmbChannelCreateGpadlFromPfnList */
  if (*(char *)(param_1 + 0x6c0) == '\0') {
    if ((param_3 == 0) || (param_4 == 0)) {
      uVar1 = 0xc00000f1;
    }
    else {
      uVar1 = (**(code **)(param_1 + 0x980))
                        (*(undefined8 *)(param_1 + 0x940),param_3,param_4,param_5);
      if (-1 < (int)uVar1) {
        LOCK();
        *(int *)(param_1 + 0xb00) = *(int *)(param_1 + 0xb00) + 1;
        UNLOCK();
      }
    }
  }
  else {
    uVar1 = 0xc00000ef;
  }
  return uVar1;
}



===== VmbChannelDeleteGpadl @ 14000f3c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelDeleteGpadl(longlong param_1)

{
                    /* 0xf3c0  11  VmbChannelDeleteGpadl */
  LOCK();
  *(int *)(param_1 + 0xb00) = *(int *)(param_1 + 0xb00) + -1;
  UNLOCK();
  (**(code **)(param_1 + 0x998))(*(undefined8 *)(param_1 + 0x940));
  return;
}



===== VmbChannelGetClientStatsBuffer @ 14000f3f0 =====

longlong VmbChannelGetClientStatsBuffer(longlong param_1)

{
                    /* 0xf3f0  14  VmbChannelGetClientStatsBuffer */
  return param_1 + 0x698;
}



===== VmbChannelGetInterfaceInstance @ 14000f400 =====

void VmbChannelGetInterfaceInstance(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
                    /* 0xf400  15  VmbChannelGetInterfaceInstance */
  uVar1 = *(undefined8 *)(param_1 + 0xac8);
  *param_2 = *(undefined8 *)(param_1 + 0xac0);
  param_2[1] = uVar1;
  return;
}



===== VmbChannelGetMmioSpace @ 14000f420 =====

void VmbChannelGetMmioSpace(longlong param_1,undefined8 *param_2,undefined8 *param_3)

{
                    /* 0xf420  16  VmbChannelGetMmioSpace */
  *param_2 = *(undefined8 *)(param_1 + 0xc08);
  *param_3 = *(undefined8 *)(param_1 + 0xc10);
  return;
}



===== VmbChannelGetNumaNodeMap @ 14000f440 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelGetNumaNodeMap(longlong param_1)

{
                    /* 0xf440  17  VmbChannelGetNumaNodeMap */
  (**(code **)(param_1 + 0xa08))(*(undefined8 *)(param_1 + 0x940));
  return;
}



===== VmbChannelGetOfferData @ 14000f480 =====

void VmbChannelGetOfferData(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
                    /* 0xf480  18  VmbChannelGetOfferData */
  uVar1 = *(undefined8 *)(param_1 + 0x728);
  *param_2 = *(undefined8 *)(param_1 + 0x720);
  param_2[1] = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x738);
  param_2[2] = *(undefined8 *)(param_1 + 0x730);
  param_2[3] = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x748);
  param_2[4] = *(undefined8 *)(param_1 + 0x740);
  param_2[5] = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x758);
  param_2[6] = *(undefined8 *)(param_1 + 0x750);
  param_2[7] = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x768);
  param_2[8] = *(undefined8 *)(param_1 + 0x760);
  param_2[9] = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x778);
  param_2[10] = *(undefined8 *)(param_1 + 0x770);
  param_2[0xb] = uVar1;
  uVar1 = *(undefined8 *)(param_1 + 0x788);
  param_2[0xc] = *(undefined8 *)(param_1 + 0x780);
  param_2[0xd] = uVar1;
  param_2[0xe] = *(undefined8 *)(param_1 + 0x790);
  return;
}



===== VmbChannelGetPacketDescriptor @ 14000f4f0 =====

void VmbChannelGetPacketDescriptor(longlong param_1,int *param_2)

{
                    /* 0xf4f0  19  VmbChannelGetPacketDescriptor */
  if (param_2 != (int *)0x0) {
    *param_2 = (uint)*(ushort *)(param_1 + 0xa4) << 3;
  }
  return;
}



===== VmbChannelGetParentDeviceObject @ 14000f510 =====

void VmbChannelGetParentDeviceObject(longlong param_1,undefined8 *param_2)

{
                    /* 0xf510  20  VmbChannelGetParentDeviceObject */
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = *(undefined8 *)(param_1 + 0xcc0);
  }
  return;
}



===== VmbChannelGetPointer @ 14000f530 =====

undefined8 VmbChannelGetPointer(longlong param_1)

{
                    /* 0xf530  21  VmbChannelGetPointer */
  return *(undefined8 *)(param_1 + 0x930);
}



===== VmbChannelGetRingBuffer @ 14000f540 =====

void VmbChannelGetRingBuffer
               (longlong param_1,longlong *param_2,int *param_3,longlong *param_4,int *param_5)

{
  int iVar1;
  
                    /* 0xf540  22  VmbChannelGetRingBuffer */
  if (*(char *)(param_1 + 0x6c0) == '\0') {
    *param_4 = *(longlong *)(param_1 + 0xa90);
    iVar1 = *(int *)(param_1 + 0xa9c);
    *param_5 = iVar1;
    *param_2 = (ulonglong)(uint)(iVar1 << 0xc) + *param_4;
    *param_3 = *(int *)(param_1 + 0xa98);
    return;
  }
  *param_2 = *(longlong *)(param_1 + 0xa90);
  iVar1 = *(int *)(param_1 + 0xa98);
  *param_3 = iVar1;
  *param_4 = (ulonglong)(uint)(iVar1 << 0xc) + *param_2;
  *param_5 = *(int *)(param_1 + 0xa9c);
  return;
}



===== VmbChannelGetSystemAddressForGpadl @ 14000f5b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint VmbChannelGetSystemAddressForGpadl
               (longlong param_1,undefined8 param_2,undefined4 param_3,longlong *param_4)

{
                    /* 0xf5b0  25  VmbChannelGetSystemAddressForGpadl */
  (**(code **)(param_1 + 0x990))(*(undefined8 *)(param_1 + 0x940),param_3,param_4);
  return ~-(uint)(*param_4 != 0) & 0xc000009a;
}



===== VmbChannelGetTargetDeviceObject @ 14000f5f0 =====

void VmbChannelGetTargetDeviceObject(longlong param_1,undefined8 *param_2)

{
                    /* 0xf5f0  26  VmbChannelGetTargetDeviceObject */
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = *(undefined8 *)(param_1 + 0xaa0);
  }
  return;
}



===== VmbChannelGetTargetProcessorIndex @ 14000f610 =====

undefined4 VmbChannelGetTargetProcessorIndex(longlong param_1)

{
                    /* 0xf610  27  VmbChannelGetTargetProcessorIndex */
  return *(undefined4 *)(param_1 + 0xccc);
}



===== VmbChannelGetVMBusInterface @ 14000f620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 VmbChannelGetVMBusInterface(longlong param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  
                    /* 0xf620  28  VmbChannelGetVMBusInterface */
  uVar10 = 0;
  if (*(longlong *)(param_1 + 0x940) == 0) {
    memset(param_2,0,0x140);
    uVar10 = 0xc00002b9;
  }
  else {
    lVar7 = 2;
    puVar5 = param_2;
    puVar6 = (undefined8 *)(param_1 + 0x938);
    do {
      puVar9 = puVar6;
      puVar8 = puVar5;
      uVar4 = puVar9[1];
      *puVar8 = *puVar9;
      puVar8[1] = uVar4;
      uVar4 = puVar9[3];
      puVar8[2] = puVar9[2];
      puVar8[3] = uVar4;
      uVar4 = puVar9[5];
      puVar8[4] = puVar9[4];
      puVar8[5] = uVar4;
      uVar4 = puVar9[7];
      puVar8[6] = puVar9[6];
      puVar8[7] = uVar4;
      uVar4 = puVar9[9];
      puVar8[8] = puVar9[8];
      puVar8[9] = uVar4;
      uVar4 = puVar9[0xb];
      puVar8[10] = puVar9[10];
      puVar8[0xb] = uVar4;
      uVar4 = puVar9[0xd];
      puVar8[0xc] = puVar9[0xc];
      puVar8[0xd] = uVar4;
      uVar4 = puVar9[0xf];
      puVar8[0xe] = puVar9[0xe];
      puVar8[0xf] = uVar4;
      lVar7 = lVar7 + -1;
      puVar5 = puVar8 + 0x10;
      puVar6 = puVar9 + 0x10;
    } while (lVar7 != 0);
    uVar4 = puVar9[0x11];
    puVar8[0x10] = puVar9[0x10];
    puVar8[0x11] = uVar4;
    uVar4 = puVar9[0x13];
    puVar8[0x12] = puVar9[0x12];
    puVar8[0x13] = uVar4;
    uVar1 = *(undefined4 *)((longlong)puVar9 + 0xa4);
    uVar2 = *(undefined4 *)(puVar9 + 0x15);
    uVar3 = *(undefined4 *)((longlong)puVar9 + 0xac);
    *(undefined4 *)(puVar8 + 0x14) = *(undefined4 *)(puVar9 + 0x14);
    *(undefined4 *)((longlong)puVar8 + 0xa4) = uVar1;
    *(undefined4 *)(puVar8 + 0x15) = uVar2;
    *(undefined4 *)((longlong)puVar8 + 0xac) = uVar3;
    uVar1 = *(undefined4 *)((longlong)puVar9 + 0xb4);
    uVar2 = *(undefined4 *)(puVar9 + 0x17);
    uVar3 = *(undefined4 *)((longlong)puVar9 + 0xbc);
    *(undefined4 *)(puVar8 + 0x16) = *(undefined4 *)(puVar9 + 0x16);
    *(undefined4 *)((longlong)puVar8 + 0xb4) = uVar1;
    *(undefined4 *)(puVar8 + 0x17) = uVar2;
    *(undefined4 *)((longlong)puVar8 + 0xbc) = uVar3;
    (*(code *)param_2[2])(param_2[1]);
  }
  return uVar10;
}



===== VmbChannelGetVirtualProcessorCount @ 14000f6f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4 VmbChannelGetVirtualProcessorCount(longlong param_1)

{
  undefined4 local_res8 [8];
  
                    /* 0xf6f0  29  VmbChannelGetVirtualProcessorCount */
  local_res8[0] = 0;
  (**(code **)(param_1 + 0xa08))(*(undefined8 *)(param_1 + 0x940),0,0,0,local_res8);
  return local_res8[0];
}



===== VmbChannelPacketComplete @ 14000f730 =====

void VmbChannelPacketComplete(undefined8 *param_1,void *param_2,uint param_3)

{
                    /* 0xf730  45  VmbChannelPacketComplete */
  InCompletePacket((longlong *)*param_1,(longlong)param_1,param_2,param_3);
  return;
}



===== VmbChannelPacketDeferToPassive @ 14000f760 =====

void VmbChannelPacketDeferToPassive(longlong *param_1)

{
                    /* 0xf760  46  VmbChannelPacketDeferToPassive */
  *(undefined4 *)(*param_1 + 0x584) = 3;
  return;
}



===== VmbChannelPacketDeferUntilPolled @ 14000f780 =====

void VmbChannelPacketDeferUntilPolled(longlong *param_1)

{
                    /* 0xf780  47  VmbChannelPacketDeferUntilPolled
                       0xf780  48  VmbChannelPacketFail */
  *(undefined4 *)(*param_1 + 0x584) = 2;
  return;
}



===== VmbChannelPacketGetClientContext @ 14000f7a0 =====

longlong VmbChannelPacketGetClientContext(longlong param_1)

{
                    /* 0xf7a0  49  VmbChannelPacketGetClientContext */
  return (ulonglong)*(uint *)(param_1 + 0x40) + 0xa0 + param_1;
}



===== VmbChannelPacketGetExternalData @ 14000f7c0 =====

ulonglong VmbChannelPacketGetExternalData(longlong *param_1,uint param_2,longlong *param_3)

{
  int iVar1;
  ulonglong uVar2;
  
                    /* 0xf7c0  50  VmbChannelPacketGetExternalData */
  if (param_1[6] == 0) {
    uVar2 = InMapPacketMdl((longlong *)*param_1,(longlong)param_1,(ulonglong)param_2);
    iVar1 = (int)uVar2;
    uVar2 = uVar2 & 0xffffffff;
    if (iVar1 == 0) {
      *param_3 = param_1[6];
    }
    else if (iVar1 == 0x103) {
      *(undefined4 *)(*param_1 + 0x584) = 1;
    }
    else if (iVar1 == -0x3ffffeb8) {
      uVar2 = 0x103;
      *(undefined4 *)(*param_1 + 0x584) = 3;
    }
  }
  else {
    *param_3 = param_1[6];
    uVar2 = 0;
  }
  return uVar2;
}



===== VmbChannelPacketShortLifetime @ 14000f840 =====

void VmbChannelPacketShortLifetime(longlong *param_1)

{
                    /* 0xf840  51  VmbChannelPacketShortLifetime */
  InMarkPacketShortLifetime(*param_1,(longlong)param_1);
  return;
}



===== VmbChannelPollRingBuffer @ 14000f860 =====

void VmbChannelPollRingBuffer(longlong *param_1,ulonglong param_2)

{
                    /* 0xf860  53  VmbChannelPollRingBuffer */
  InClientPollQueue(param_1,param_2);
  return;
}



===== VmbChannelSetAllowableDpcCpuUsage @ 14000f880 =====

void VmbChannelSetAllowableDpcCpuUsage(longlong param_1,byte param_2)

{
  undefined1 auVar1 [16];
  longlong lVar2;
  ulonglong uVar3;
  
                    /* 0xf880  57  VmbChannelSetAllowableDpcCpuUsage */
  if (param_2 < 100) {
    uVar3 = (ulonglong)param_2 * 0x10 * KmclTscTicksPerNtTick;
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar3;
    lVar2 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar1,8);
    uVar3 = (uVar3 - lVar2 >> 1) + lVar2 >> 6;
  }
  else {
    uVar3 = 0xffffffffffffffff;
  }
  *(ulonglong *)(param_1 + 0x5d0) = uVar3;
  return;
}



===== VmbChannelSetIncomingPollOnCompletion @ 14000f8d0 =====

void VmbChannelSetIncomingPollOnCompletion(longlong param_1,char param_2)

{
                    /* 0xf8d0  58  VmbChannelSetIncomingPollOnCompletion */
  *(bool *)(param_1 + 0x4b0) = param_2 != '\0';
  return;
}



===== VmbChannelSetIncomingProcessingAtPassive @ 14000f8f0 =====

void VmbChannelSetIncomingProcessingAtPassive(longlong param_1,char param_2)

{
                    /* 0xf8f0  59  VmbChannelSetIncomingProcessingAtPassive */
  *(bool *)(param_1 + 0x4b2) = param_2 != '\0';
  if (param_2 != '\0') {
    *(undefined1 *)(param_1 + 0x4b1) = 1;
  }
  return;
}



===== VmbChannelSetPointer @ 14000f910 =====

void VmbChannelSetPointer(longlong param_1,undefined8 param_2)

{
                    /* 0xf910  61  VmbChannelSetPointer */
  *(undefined8 *)(param_1 + 0x930) = param_2;
  return;
}



===== VmbChannelSetPollingMode @ 14000f920 =====

void VmbChannelSetPollingMode(longlong *param_1,char param_2)

{
                    /* 0xf920  62  VmbChannelSetPollingMode */
  if ((*(byte *)(param_1 + 0x125) & 0x20) == 0) {
    *(char *)((longlong)param_1 + 0x4b4) = param_2;
  }
  else {
    InSetPollingMode(param_1,param_2);
  }
  return;
}



===== VmbChannelSetTransactionQuota @ 14000f950 =====

void VmbChannelSetTransactionQuota(longlong param_1,undefined4 param_2)

{
                    /* 0xf950  64  VmbChannelSetTransactionQuota */
  *(undefined4 *)(param_1 + 0x574) = param_2;
  return;
}



===== VmbChannelSizeofPacket @ 14000f960 =====

int VmbChannelSizeofPacket(longlong param_1)

{
                    /* 0xf960  65  VmbChannelSizeofPacket */
  return *(int *)(param_1 + 0x6c8) + 0xf0 + *(int *)(param_1 + 0x6d8);
}



===== VmbChannelUpdateClientContextSize @ 14000f980 =====

void VmbChannelUpdateClientContextSize(longlong *param_1,int param_2)

{
                    /* 0xf980  67  VmbChannelUpdateClientContextSize */
  InChangeClientContextSize(param_1,param_2);
  return;
}



===== VmbChannelUpdateInterruptProcessor @ 14000f9a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VmbChannelUpdateInterruptProcessor(longlong param_1)

{
                    /* 0xf9a0  68  VmbChannelUpdateInterruptProcessor */
  (**(code **)(param_1 + 0xa58))(*(undefined8 *)(param_1 + 0x940));
  return;
}



===== DllUnload @ 14000f9d0 =====

undefined8 DllUnload(void)

{
                    /* 0xf9d0  2  DllUnload */
  if (KmclPcChannel != 0) {
    PcwUnregister();
  }
  if (KmclPcPipeChannel != 0) {
    PcwUnregister();
  }
  if (KmclPcChannelState != 0) {
    PcwUnregister();
  }
  UninitializeTelemetryAssertsKM();
  McGenEventUnregister_EtwUnregister();
  WppCleanupKm();
  wil_UninitializeFeatureStaging();
  return 0;
}



===== McGenControlCallbackV2 @ 14000fa40 =====

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



===== McGenEventRegister_EtwRegister @ 14000fb50 =====

void McGenEventRegister_EtwRegister(void)

{
  if (VMBKMCL_PROVIDER_Context == 0) {
    EtwRegister(&VMBKMCL_PROVIDER,McGenControlCallbackV2,&VMBKMCL_PROVIDER_Context,
                &VMBKMCL_PROVIDER_Context);
  }
  return;
}



===== McGenEventUnregister_EtwUnregister @ 14000fb90 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (VMBKMCL_PROVIDER_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    VMBKMCL_PROVIDER_Context = 0;
  }
  return uVar1;
}



===== WppClassicProviderCallback @ 14000fbd0 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 14000fc04 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_140015bbf < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 14000fc30 =====

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



===== wil_details_RecordFeatureUsageReporting @ 14000fd90 =====

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



===== KmclpEnablePerformanceCounters @ 14000fe14 =====

int KmclpEnablePerformanceCounters(longlong param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  char local_res10 [8];
  
  local_res10[0] = '\0';
  iVar1 = KmclpUsePerformanceCounters(local_res10);
  if ((-1 < iVar1) && (local_res10[0] != '\0')) {
    uVar2 = KmclpGetInstanceNameLength(param_1);
    lVar3 = ExAllocatePool2(0x40,uVar2 & 0xffff,0x636d6b56);
    if (lVar3 == 0) {
      iVar1 = -0x3fffff66;
    }
    else {
      ExAcquireFastMutex(&KmclPerformanceCounterLock);
      *(undefined8 *)(param_1 + 0x870) = 0;
      *(undefined8 *)(param_1 + 0x878) = 0;
      *(short *)(param_1 + 0x872) = (short)uVar2;
      *(longlong *)(param_1 + 0x878) = lVar3;
      *(int *)(param_1 + 0x880) = KmclPerformanceCounterNextID;
      KmclPerformanceCounterNextID = KmclPerformanceCounterNextID + 1;
      if (KmclPerformanceCounterNextID == 0) {
        KmclPerformanceCounterNextID = 1;
      }
      ExReleaseFastMutex(&KmclPerformanceCounterLock);
      iVar1 = 0;
    }
  }
  return iVar1;
}



===== KmclpGetInstanceNameLength @ 14000fef4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

uint KmclpGetInstanceNameLength(longlong param_1)

{
  uint uVar1;
  int iVar2;
  ushort local_res8 [4];
  
  iVar2 = 0;
  local_res8[0] = 0;
  if (*(longlong *)(param_1 + 0x890) != 0) {
    iVar2 = *(ushort *)(param_1 + 0x888) + 2;
  }
  if (*(char *)(param_1 + 0x6c0) != '\0') {
    (**(code **)(param_1 + 0xa10))(*(undefined8 *)(param_1 + 0x940),0,local_res8,0);
    iVar2 = iVar2 + local_res8[0] + 2;
  }
  uVar1 = (-(uint)(*(short *)(param_1 + 0xcd0) != 0) & 10) + 0x4c + iVar2;
  if (0xfffe < uVar1) {
    uVar1 = 0xfffe;
  }
  return uVar1;
}



===== KmclpUsePerformanceCounters @ 14000ff7c =====

int KmclpUsePerformanceCounters(char *param_1)

{
  int iVar1;
  undefined8 local_48;
  undefined1 *puStack_40;
  undefined8 local_38;
  undefined1 *puStack_30;
  code *local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_48 = 0;
  puStack_40 = (undefined1 *)0x0;
  local_18 = local_18 & 0xffffffff00000000;
  local_38 = 0;
  puStack_30 = (undefined1 *)0x0;
  local_28 = (code *)0x0;
  uStack_20 = 0;
  KeEnterCriticalRegion();
  ExAcquireFastMutexUnsafe(&KmclPerformanceCounterLock);
  if (KmclPerformanceCountersRegistered == '\0') {
    local_48 = 0x100;
    puStack_40 = &`KmclPcInitRegistrationInformationChannel'::__l2::Name;
    local_38 = 0x2b;
    puStack_30 = &`KmclPcInitRegistrationInformationChannel'::__l2::Descriptors;
    local_18 = 0;
    local_28 = KmclpStatsCallback;
    uStack_20 = 1;
    iVar1 = PcwRegister(&KmclPcChannel,&local_48);
    if ((-1 < iVar1) && (KmclPcChannel != 0)) {
      local_48 = 0x100;
      puStack_40 = &`KmclPcInitRegistrationInformationChannelState'::__l2::Name;
      local_38 = 0xc;
      puStack_30 = &`KmclPcInitRegistrationInformationChannelState'::__l2::Descriptors;
      local_18 = 0;
      local_28 = KmclpStatsCallback;
      uStack_20 = 3;
      iVar1 = PcwRegister(&KmclPcChannelState,&local_48);
      if ((-1 < iVar1) && (KmclPcChannel != 0)) {
        local_48 = 0x100;
        puStack_40 = &`KmclPcInitRegistrationInformationPipeChannel'::__l2::Name;
        local_38 = 4;
        puStack_30 = &`KmclPcInitRegistrationInformationPipeChannel'::__l2::Descriptors;
        local_18 = 0;
        local_28 = KmclpStatsCallback;
        uStack_20 = 2;
        iVar1 = PcwRegister(&KmclPcPipeChannel,&local_48);
        if ((-1 < iVar1) && (KmclPcPipeChannel != 0)) {
          KmclPerformanceCountersRegistered = '\x01';
          goto LAB_140010108;
        }
      }
    }
    iVar1 = -0x3fffffff;
  }
  else {
    iVar1 = 0;
  }
LAB_140010108:
  *param_1 = KmclPerformanceCountersRegistered;
  ExReleaseFastMutexUnsafe(&KmclPerformanceCounterLock);
  KeLeaveCriticalRegion();
  return iVar1;
}



===== HviGetHypervisorFeatures @ 140010150 =====

/* WARNING: Removing unreachable block (ram,0x000140010169) */

void HviGetHypervisorFeatures(undefined8 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = HviIsHypervisorMicrosoftCompatible();
  if ((char)uVar4 == '\0') {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    puVar1 = (undefined4 *)cpuid(0x40000003);
    uVar4 = puVar1[1];
    uVar2 = puVar1[2];
    uVar3 = puVar1[3];
    *(undefined4 *)param_1 = *puVar1;
    *(undefined4 *)((longlong)param_1 + 4) = uVar4;
    *(undefined4 *)(param_1 + 1) = uVar3;
    *(undefined4 *)((longlong)param_1 + 0xc) = uVar2;
  }
  return;
}



===== HviIsAnyHypervisorPresent @ 140010190 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0001400101c4) */
/* WARNING: Removing unreachable block (ram,0x0001400101b3) */

undefined8 HviIsAnyHypervisorPresent(void)

{
  uint *puVar1;
  ulonglong uVar2;
  undefined1 uVar3;
  
  puVar1 = (uint *)cpuid_Version_info(1);
  uVar2 = (ulonglong)*puVar1;
  uVar3 = 0;
  if ((int)puVar1[3] < 0) {
    puVar1 = (uint *)cpuid(0x40000001);
    uVar2 = (ulonglong)*puVar1;
    uVar3 = 0;
    if (*puVar1 != 0x766e6258) {
      uVar3 = 1;
    }
  }
  return CONCAT71((int7)(uVar2 >> 8),uVar3);
}



===== HviIsHypervisorMicrosoftCompatible @ 1400101ec =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000140010219) */

undefined4 HviIsHypervisorMicrosoftCompatible(void)

{
  int *piVar1;
  undefined8 uVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uStack_20 = 0;
  uVar2 = HviIsAnyHypervisorPresent();
  if ((char)uVar2 == '\0') {
  }
  else {
    piVar1 = (int *)cpuid(0x40000001);
    local_28._0_4_ = *piVar1;
  }
  return CONCAT31((int3)((uint)(int)local_28 >> 8),(int)local_28 == 0x31237648);
}



===== GetImageTuple @ 140010244 =====

/* WARNING: Removing unreachable block (ram,0x00014001027a) */

undefined8 GetImageTuple(undefined8 param_1,dword *param_2,dword *param_3)

{
  *param_2 = 0x7c0c8772;
  *param_3 = 0x27000;
  return 1;
}



===== InitializeTelemetryAssertsKM @ 140010294 =====

ulonglong InitializeTelemetryAssertsKM(ushort *param_1)

{
  uint uVar1;
  uint uVar2;
  void *_Dst;
  ulonglong uVar3;
  undefined8 local_b8;
  longlong lStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined1 local_78 [8];
  undefined4 local_70;
  wchar_t *local_68;
  undefined8 *local_60;
  undefined4 local_58;
  
  local_b8 = 0;
  lStack_b0 = 0;
  uVar3 = 0xc0000017;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) {
    RtlInitAnsiString(&local_b8,0);
    _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)*param_1 + 2,0x74727341);
    if (_Dst != (void *)0x0) {
      memmove(_Dst,*(void **)(param_1 + 4),(ulonglong)*param_1);
      local_a8 = 0;
      uStack_a0 = 0;
      RtlInitUnicodeString(&local_a8);
      memset(local_78,0,0x70);
      local_68 = L"ImagePath";
      local_60 = &local_a8;
      local_70 = 0x20;
      local_58 = 2;
      uVar2 = RtlQueryRegistryValuesEx(0,_Dst,local_78,0,0);
      uVar3 = (ulonglong)uVar2;
      if (-1 < (int)uVar2) {
        uVar2 = RtlUnicodeStringToAnsiString(&local_b8,&local_a8,1);
        uVar3 = (ulonglong)uVar2;
        ExFreePoolWithTag(uStack_a0,0);
        if (-1 < (int)uVar2) {
          uVar2 = (uint)(ushort)local_b8;
          do {
            uVar1 = uVar2;
            uVar2 = uVar1 - 1;
            if (uVar2 == 0) goto LAB_14001040e;
          } while (*(char *)((ulonglong)uVar2 + lStack_b0) != '\\');
          if (uVar2 != (ushort)local_b8) {
            local_98 = 0;
            uStack_90 = 0;
            RtlInitAnsiString(&local_98,(ulonglong)uVar1 + lStack_b0);
            local_88 = local_98;
            uStack_80 = uStack_90;
            uVar3 = InitializeTelemetryAssertsKMWorkerInternal((ushort *)&local_88);
            uVar3 = uVar3 & 0xffffffff;
          }
LAB_14001040e:
          RtlFreeAnsiString(&local_b8);
        }
      }
      ExFreePoolWithTag(_Dst,0x74727341);
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



===== InitializeTelemetryAssertsKMWorkerInternal @ 140010454 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 InitializeTelemetryAssertsKMWorkerInternal(ushort *param_1)

{
  undefined8 uVar1;
  
  KeInitializeSpinLock(&g_AssertSpinLock);
  uVar1 = 0;
  g_ModuleName = (void *)ExAllocatePool2(0x40,(ulonglong)*param_1 + 1,0x74727341);
  if (g_ModuleName == (void *)0x0) {
    uVar1 = 0xc0000017;
  }
  else {
    memmove(g_ModuleName,*(void **)(param_1 + 4),(ulonglong)*param_1);
    _DAT_1400161a8 = &g_MicrosoftTelemetryAssertsTriggeredList;
    g_MicrosoftTelemetryAssertsTriggeredList = &g_MicrosoftTelemetryAssertsTriggeredList;
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x14001b040);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x14001b008);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(0x14001b078);
    LOCK();
    g_AssertsOperational = g_AssertsOperational + 1;
    UNLOCK();
  }
  return uVar1;
}



===== MicrosoftTelemetryAssertTriggeredArgsKM @ 140010508 =====

void MicrosoftTelemetryAssertTriggeredArgsKM
               (undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  IMAGE_DOS_HEADER *unaff_retaddr;
  
  MicrosoftTelemetryAssertTriggeredWorker(unaff_retaddr,1,0,param_2,param_3);
  return;
}



===== MicrosoftTelemetryAssertTriggeredWorker @ 140010538 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MicrosoftTelemetryAssertTriggeredWorker
               (IMAGE_DOS_HEADER *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5)

{
  code *pcVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  char cVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined8 uVar12;
  longlong *plVar13;
  char *pcVar14;
  uint uVar15;
  undefined1 *puVar16;
  ulonglong uVar17;
  char *pcVar18;
  longlong lVar19;
  undefined1 auStack_1a8 [8];
  undefined1 auStack_1a0 [120];
  undefined4 local_128;
  char *local_120;
  undefined1 local_118 [32];
  undefined1 *local_f8;
  undefined8 local_f0;
  undefined1 *local_e8;
  undefined8 local_e0;
  undefined1 *local_d8;
  undefined8 local_d0;
  undefined1 *local_c8;
  undefined8 local_c0;
  longlong local_b8 [2];
  undefined1 *local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  undefined8 local_90;
  undefined1 *local_88;
  undefined8 local_80;
  longlong local_78 [2];
  undefined1 *local_68;
  undefined8 local_60;
  undefined1 *local_58;
  undefined8 local_50;
  longlong local_48 [2];
  ulonglong local_38;
  
  puVar16 = auStack_1a8;
  local_38 = __security_cookie ^ (ulonglong)auStack_1a8;
  LOCK();
  UNLOCK();
  if (g_AssertsOperational == 0) goto LAB_140010ac1;
  local_128 = param_4;
  uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
  puVar16 = auStack_1a8;
  for (plVar11 = g_MicrosoftTelemetryAssertsTriggeredList;
      (longlong **)plVar11 != &g_MicrosoftTelemetryAssertsTriggeredList;
      plVar11 = (longlong *)*plVar11) {
    plVar10 = plVar11 + -4;
    if ((IMAGE_DOS_HEADER *)*plVar10 == param_1) goto LAB_14001066e;
  }
  plVar10 = (longlong *)ExAllocatePool2(0x42,0x30,0x74727341);
  lVar19 = _DAT_fffff78000000320;
  puVar16 = auStack_1a8;
  if (plVar10 != (longlong *)0x0) {
    *plVar10 = (longlong)param_1;
    uVar7 = KeQueryTimeIncrement();
    puVar16 = auStack_1a8;
    *(undefined4 *)(plVar10 + 2) = 0;
    *(undefined4 *)((longlong)plVar10 + 0x14) = 0;
    *(undefined4 *)(plVar10 + 3) = 0;
    plVar10[1] = (longlong)((ulonglong)uVar7 * lVar19) / 10000 + -0xea61;
    plVar11 = plVar10 + 4;
    plVar13 = g_MicrosoftTelemetryAssertsTriggeredList;
    if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
        &g_MicrosoftTelemetryAssertsTriggeredList) {
      plVar13 = (longlong *)0x3;
      pcVar1 = (code *)swi(0x29);
      plVar11 = (longlong *)(*pcVar1)();
      puVar16 = auStack_1a0;
    }
    *plVar11 = (longlong)plVar13;
    plVar11[1] = (longlong)&g_MicrosoftTelemetryAssertsTriggeredList;
    plVar13[1] = (longlong)plVar11;
    g_MicrosoftTelemetryAssertsTriggeredList = plVar11;
LAB_14001066e:
    *(int *)(plVar10 + 2) = (int)plVar10[2] + 1;
    *(int *)((longlong)plVar10 + 0x14) = *(int *)((longlong)plVar10 + 0x14) + 1;
    lVar2 = _DAT_fffff78000000320;
    *(undefined8 *)(puVar16 + -8) = 0x14001067e;
    uVar7 = KeQueryTimeIncrement();
    *(undefined4 *)(puVar16 + 0x54) = 0;
    *(undefined4 *)(puVar16 + 0x50) = 0;
    lVar19 = (longlong)((ulonglong)uVar7 * lVar2) / 10000;
    if (60000 < (ulonglong)(lVar19 - plVar10[1])) {
      *(undefined8 *)(puVar16 + -8) = 0x1400106cc;
      uVar12 = GetImageTuple((ulonglong)uVar7 * lVar2,(dword *)(puVar16 + 0x54),
                             (dword *)(puVar16 + 0x50));
      uVar7 = *(uint *)(puVar16 + 0x50);
      iVar8 = (int)uVar12;
      if ((((iVar8 == 0) || (param_1 < &IMAGE_DOS_HEADER_140000000)) ||
          ((IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + uVar7) <
           (IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + 1))) ||
         ((IMAGE_DOS_HEADER *)(IMAGE_DOS_HEADER_140000000.e_magic + uVar7) < param_1)) {
        uVar15 = 0;
      }
      else {
        uVar15 = (int)param_1 + 0xc0000000;
      }
      *(int *)(puVar16 + 0x50) = (int)plVar10[2];
      plVar10[1] = lVar19;
      lVar19 = plVar10[3];
      *(undefined4 *)(puVar16 + 0x7c) = *(undefined4 *)((longlong)plVar10 + 0x14);
      *(undefined8 *)(puVar16 + -8) = 0x140010720;
      KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
      local_120 = g_ModuleName;
      if (5 < DAT_14001b040) {
        *(undefined8 *)(puVar16 + -8) = 0x14001075a;
        pcVar18 = g_ModuleName;
        cVar5 = _tlgKeywordOn(0x14001b040,0x400000000000);
        uVar12 = 0;
        if (cVar5 != '\0') {
          local_f8 = puVar16 + 0x58;
          *(undefined4 *)(puVar16 + 0x58) = 10;
          local_e8 = puVar16 + 0x5c;
          local_f0 = 4;
          *(uint *)(puVar16 + 0x5c) = uVar15;
          local_d8 = puVar16 + 0x60;
          local_e0 = 4;
          *(uint *)(puVar16 + 0x60) = -(uint)(iVar8 != 0) & *(uint *)(puVar16 + 0x54);
          local_c8 = puVar16 + 100;
          local_d0 = 4;
          local_c0 = 4;
          *(uint *)(puVar16 + 100) = -(uint)(iVar8 != 0) & uVar7;
          pcVar14 = "<unknown>";
          if (pcVar18 != (char *)0x0) {
            pcVar14 = pcVar18;
          }
          *(undefined8 *)(puVar16 + -8) = 0x1400107e5;
          _tlgCreate1Sz_char(local_b8,pcVar14);
          local_a8 = puVar16 + 0x68;
          *(undefined4 *)(puVar16 + 0x6c) = *(undefined4 *)(puVar16 + 0x7c);
          local_98 = puVar16 + 0x6c;
          *(undefined4 *)(puVar16 + 0x68) = *(undefined4 *)(puVar16 + 0x50);
          local_a0 = 4;
          local_90 = 4;
          *(undefined8 *)(puVar16 + -8) = 0x14001081e;
          bVar6 = KeGetCurrentIrql();
          *(uint *)(puVar16 + 0x70) = (uint)bVar6;
          local_88 = puVar16 + 0x70;
          local_80 = 4;
          *(undefined8 *)(puVar16 + -8) = 0x140010848;
          _tlgCreate1Sz_char(local_78,local_120);
          uVar3 = local_128;
          local_68 = puVar16 + 0x74;
          *(undefined4 *)(puVar16 + 0x78) = param_5;
          local_58 = puVar16 + 0x78;
          *(undefined4 *)(puVar16 + 0x74) = uVar3;
          local_60 = 4;
          local_50 = 4;
          *(undefined8 *)(puVar16 + -8) = 0x140010887;
          _tlgCreate1Sz_char(local_48,"<unknown>");
          *(undefined1 **)(puVar16 + 0x28) = local_118;
          *(undefined4 *)(puVar16 + 0x20) = 0xe;
          *(undefined8 *)(puVar16 + -8) = 0x1400108a4;
          _tlgWriteTransfer_EtwWriteTransfer
                    (local_118,&DAT_140014811,uVar12,pcVar18,*(undefined4 *)(puVar16 + 0x20),
                     *(undefined8 **)(puVar16 + 0x28));
        }
      }
      if ((DAT_14001b078 == 0) || ((int)lVar19 != 0)) goto LAB_140010ac1;
      *(undefined8 *)(puVar16 + -8) = 0x1400108c3;
      cVar5 = KeGetCurrentIrql();
      if (cVar5 != '\0') goto LAB_140010ac1;
      *(undefined4 *)(puVar16 + 0x40) = 0;
      *(undefined8 *)(puVar16 + 0x38) = 0;
      *(undefined8 *)(puVar16 + 0x30) = 0;
      *(ulonglong *)(puVar16 + 0x28) = (ulonglong)uVar7;
      *(ulonglong *)(puVar16 + 0x20) = (ulonglong)*(uint *)(puVar16 + 0x54);
      uVar17 = (ulonglong)uVar15;
      *(undefined8 *)(puVar16 + -8) = 0x14001090d;
      pcVar18 = g_ModuleName;
      iVar9 = DbgkWerCaptureLiveKernelDump(L"TELASSERT",0x1d1);
      if (5 < DAT_14001b040) {
        *(undefined8 *)(puVar16 + -8) = 0x140010937;
        cVar5 = _tlgKeywordOn(0x14001b040,0x400000000000);
        if (cVar5 != '\0') {
          local_f8 = puVar16 + 0x78;
          *(undefined4 *)(puVar16 + 0x78) = 10;
          local_e8 = puVar16 + 0x74;
          local_f0 = 4;
          local_d8 = puVar16 + 0x70;
          *(uint *)(puVar16 + 0x74) = uVar15;
          *(uint *)(puVar16 + 0x70) = -(uint)(iVar8 != 0) & *(uint *)(puVar16 + 0x54);
          local_e0 = 4;
          local_d0 = 4;
          local_c0 = 4;
          *(uint *)(puVar16 + 0x6c) = -(uint)(iVar8 != 0) & uVar7;
          local_c8 = puVar16 + 0x6c;
          pcVar14 = "<unknown>";
          if (g_ModuleName != (char *)0x0) {
            pcVar14 = g_ModuleName;
          }
          *(undefined8 *)(puVar16 + -8) = 0x1400109c4;
          _tlgCreate1Sz_char(local_b8,pcVar14);
          plVar11 = local_78;
          *(undefined4 *)(puVar16 + 0x68) = *(undefined4 *)(puVar16 + 0x50);
          local_a8 = puVar16 + 0x68;
          *(undefined4 *)(puVar16 + 100) = *(undefined4 *)(puVar16 + 0x7c);
          local_98 = puVar16 + 100;
          local_88 = puVar16 + 0x60;
          local_a0 = 4;
          local_90 = 4;
          *(int *)(puVar16 + 0x60) = iVar9;
          local_80 = 4;
          *(undefined8 *)(puVar16 + -8) = 0x140010a18;
          _tlgCreate1Sz_char(plVar11,local_120);
          *(undefined4 *)(puVar16 + 0x5c) = local_128;
          local_68 = puVar16 + 0x5c;
          *(undefined4 *)(puVar16 + 0x58) = param_5;
          local_58 = puVar16 + 0x58;
          *(undefined1 **)(puVar16 + 0x28) = local_118;
          *(undefined4 *)(puVar16 + 0x20) = 0xd;
          local_60 = 4;
          local_50 = 4;
          *(undefined8 *)(puVar16 + -8) = 0x140010a68;
          _tlgWriteTransfer_EtwWriteTransfer
                    (plVar11,&DAT_1400148bb,uVar17,pcVar18,*(undefined4 *)(puVar16 + 0x20),
                     *(undefined8 **)(puVar16 + 0x28));
        }
      }
      if (iVar9 != 0) goto LAB_140010ac1;
      *(undefined8 *)(puVar16 + -8) = 0x140010a7a;
      uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
      plVar11 = g_MicrosoftTelemetryAssertsTriggeredList;
      if ((longlong **)g_MicrosoftTelemetryAssertsTriggeredList !=
          &g_MicrosoftTelemetryAssertsTriggeredList) {
        do {
          if ((IMAGE_DOS_HEADER *)plVar11[-4] == param_1) {
            *(int *)(plVar11 + -1) = (int)plVar11[-1] + 1;
            break;
          }
          plVar11 = (longlong *)*plVar11;
        } while ((longlong **)plVar11 != &g_MicrosoftTelemetryAssertsTriggeredList);
      }
    }
  }
  *(undefined8 *)(puVar16 + -8) = 0x140010abc;
  KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
LAB_140010ac1:
  *(undefined8 *)(puVar16 + -8) = 0x140010acd;
  return;
}



===== UninitializeTelemetryAssertsKM @ 140010af0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UninitializeTelemetryAssertsKM(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  LOCK();
  UNLOCK();
  if (g_AssertsOperational != 0) {
    LOCK();
    g_AssertsOperational = g_AssertsOperational + -1;
    UNLOCK();
    uVar4 = KeAcquireSpinLockRaiseToDpc(&g_AssertSpinLock);
    puVar6 = auStack_28;
    while ((undefined8 **)g_MicrosoftTelemetryAssertsTriggeredList !=
           &g_MicrosoftTelemetryAssertsTriggeredList) {
      if (((undefined8 **)g_MicrosoftTelemetryAssertsTriggeredList[1] !=
           &g_MicrosoftTelemetryAssertsTriggeredList) ||
         (puVar1 = (undefined8 *)*g_MicrosoftTelemetryAssertsTriggeredList,
         (undefined8 *)puVar1[1] != g_MicrosoftTelemetryAssertsTriggeredList)) {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        puVar6 = auStack_20;
        break;
      }
      puVar5 = g_MicrosoftTelemetryAssertsTriggeredList + -4;
      g_MicrosoftTelemetryAssertsTriggeredList = puVar1;
      puVar1[1] = &g_MicrosoftTelemetryAssertsTriggeredList;
      ExFreePoolWithTag(puVar5,0x74727341);
    }
    *(undefined8 *)(puVar6 + -8) = 0x140010b83;
    KeReleaseSpinLock(&g_AssertSpinLock,uVar4);
    if (g_ModuleName != 0) {
      *(undefined8 *)(puVar6 + -8) = 0x140010ba0;
      ExFreePoolWithTag(g_ModuleName,0x74727341);
      g_ModuleName = 0;
    }
    uVar3 = DAT_14001b098;
    DAT_14001b098 = 0;
    DAT_14001b078 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140010bca;
    EtwUnregister(uVar3);
    uVar3 = DAT_14001b028;
    DAT_14001b028 = 0;
    _DAT_14001b008 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140010bec;
    EtwUnregister(uVar3);
    uVar3 = DAT_14001b060;
    DAT_14001b060 = 0;
    DAT_14001b040 = 0;
    *(undefined8 *)(puVar6 + -8) = 0x140010c0e;
    EtwUnregister(uVar3);
  }
  return;
}



===== _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv @ 140010c28 =====

void _tlgDefineProvider_annotation__Tlgmtakm_hTelemetryAssertProv(void)

{
  return;
}



===== DvAllocateHandleEntryWithoutResizing @ 140010c34 =====

ulonglong DvAllocateHandleEntryWithoutResizing(undefined8 *param_1,ulonglong param_2)

{
  ulonglong uVar1;
  ulonglong *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  
  puVar2 = (ulonglong *)*param_1;
  uVar4 = *puVar2;
  do {
    uVar3 = uVar4;
    if (uVar3 == 0) {
      return 0;
    }
    uVar5 = uVar3 & 0xffffffff;
    LOCK();
    uVar1 = *puVar2;
    if (uVar3 == uVar1) {
      *puVar2 = puVar2[uVar5];
      uVar4 = uVar3;
    }
    else {
      uVar4 = uVar1;
    }
    UNLOCK();
  } while (uVar3 != uVar1);
  if ((int)uVar3 != 0) {
    puVar2[uVar5] = param_2;
  }
  return uVar5;
}



===== DvEnsureFreeHandleEntries @ 140010c6c =====

undefined8 DvEnsureFreeHandleEntries(undefined8 *param_1)

{
  undefined8 uVar1;
  
  if (*(int *)*param_1 == 0) {
    uVar1 = DvpReallocateTable(param_1,*(int *)(param_1 + 1) + 1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



===== DvGetNextHandleEntry @ 140010c94 =====

longlong DvGetNextHandleEntry(longlong *param_1,uint *param_2)

{
  longlong lVar1;
  uint *puVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 local_res8;
  int local_18 [4];
  
  uVar4 = (ulonglong)*param_2;
  local_res8 = 0;
  local_18[2] = 0;
  local_18[1] = 0;
  do {
    local_18[0] = (int)uVar4;
    uVar3 = local_18[0] + 1;
    uVar4 = (ulonglong)uVar3;
    if (*(uint *)(param_1 + 1) <= uVar3) {
      if (param_1[5] != 0) {
        local_res8 = RtlLookupElementGenericTableAvl(param_1[5],local_18);
        puVar2 = (uint *)RtlEnumerateGenericTableWithoutSplayingAvl(param_1[5],&local_res8);
        if (puVar2 != (uint *)0x0) {
          lVar1 = *(longlong *)(puVar2 + 2);
          *param_2 = *puVar2;
          return lVar1;
        }
      }
      return 0;
    }
    lVar1 = *(longlong *)(*param_1 + uVar4 * 8);
  } while (-1 < lVar1);
  *param_2 = uVar3;
  return lVar1;
}



===== DvpPushFreeEntries @ 140010d3c =====

void DvpPushFreeEntries(ulonglong *param_1,uint param_2,ulonglong *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  bool bVar3;
  
  uVar1 = *param_1;
  do {
    *param_3 = uVar1;
    LOCK();
    if (uVar1 == *param_1) {
      *param_1 = (ulonglong)param_2;
      uVar2 = uVar1;
    }
    else {
      uVar2 = *param_1;
    }
    UNLOCK();
    bVar3 = uVar2 != uVar1;
    uVar1 = uVar2;
  } while (bVar3);
  return;
}



===== DvpReallocateTable @ 140010d5c =====

undefined8 DvpReallocateTable(undefined8 *param_1,uint param_2)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong *_Dst;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  uVar6 = *(uint *)((longlong)param_1 + 0xc);
  uVar1 = *(uint *)(param_1 + 1);
  if (uVar6 < param_2) {
    uVar2 = 0xc0000044;
  }
  else {
    uVar3 = 8;
    if (7 < param_2) {
      uVar3 = param_2;
    }
    uVar5 = uVar1 * 2;
    uVar7 = uVar5;
    if (uVar5 < uVar3) {
      uVar7 = uVar3;
    }
    if ((uVar7 <= uVar6) && (uVar6 = uVar5, uVar5 < uVar3)) {
      uVar6 = uVar3;
    }
    _Dst = (ulonglong *)
           ExAllocatePool2(param_1[3],(ulonglong)uVar6 << 3,*(undefined4 *)(param_1 + 2));
    if (_Dst == (ulonglong *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      memmove(_Dst,(void *)*param_1,(ulonglong)uVar1 << 3);
      uVar3 = uVar6 - 1;
      if (uVar1 <= uVar3) {
        uVar8 = (ulonglong)uVar3;
        uVar5 = uVar6;
        do {
          uVar7 = (int)uVar8 - 1;
          uVar4 = (ulonglong)uVar5;
          uVar5 = uVar5 - 1;
          _Dst[uVar8] = uVar4;
          uVar8 = (ulonglong)uVar7;
        } while (uVar1 <= uVar7);
      }
      DvpPushFreeEntries(_Dst,uVar1,_Dst + uVar3);
      if ((undefined8 *)*param_1 != param_1 + 4) {
        ExFreePoolWithTag((undefined8 *)*param_1,*(undefined4 *)(param_1 + 2));
      }
      *param_1 = _Dst;
      uVar2 = 0;
      *(uint *)(param_1 + 1) = uVar6;
    }
  }
  return uVar2;
}



===== PkCompleteRemoval @ 140010e5c =====

ulonglong PkCompleteRemoval(longlong param_1,uint param_2)

{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  puVar1 = *(uint **)(param_1 + 0x18);
  uVar9 = *(uint *)(param_1 + 0x28);
  if ((longlong)(int)*puVar1 == (ulonglong)param_2) {
    PkpExpectInterrupt(param_1,'\x01');
  }
  iVar7 = *(int *)(param_1 + 0x44);
  uVar4 = 0;
  *(uint *)(param_1 + 0x44) = param_2;
  puVar1[1] = param_2;
  LOCK();
  UNLOCK();
  uVar5 = *puVar1;
  uVar6 = puVar1[3] & 0xfffffff8;
  cVar2 = PkpValidatePointer(uVar9,uVar5);
  if (cVar2 == '\0') {
    uVar4 = 0xc0000102;
  }
  else {
    *(uint *)(param_1 + 0x40) = uVar5;
    if (uVar6 != 0) {
      uVar8 = (iVar7 - uVar5) - 8;
      if (uVar9 <= uVar8) {
        uVar8 = uVar8 + uVar9;
      }
      uVar3 = (param_2 - uVar5) - 8;
      if (uVar9 <= uVar3) {
        uVar3 = uVar3 + uVar9;
      }
      if ((uVar6 <= uVar3) && (uVar8 < uVar6)) {
        return 0x214;
      }
    }
    uVar4 = uVar4 & 0xffffffff;
    if (param_2 == uVar5) {
      uVar4 = 0x213;
    }
  }
  return uVar4;
}



===== PkIsOutgoingRingFull @ 140010f10 =====

undefined8 PkIsOutgoingRingFull(longlong *param_1,int param_2)

{
  char cVar1;
  undefined7 extraout_var;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar4 = *(uint *)(param_1 + 2);
  iVar6 = (int)param_1[0x10];
  uVar5 = (param_2 + 7U & 0xfffffff8) + 8;
  uVar3 = *(uint *)(*param_1 + 4);
  cVar1 = PkpValidatePointer(uVar4,uVar3);
  uVar2 = 0;
  if ((cVar1 != '\0') && (uVar2 = (uVar3 - iVar6) - 8, uVar4 <= uVar2)) {
    uVar2 = uVar2 + uVar4;
  }
  return CONCAT71(extraout_var,uVar2 < uVar5);
}



===== PkSendPacketSimple @ 140010f64 =====

undefined8
PkSendPacketSimple(longlong *param_1,void *param_2,uint param_3,undefined8 param_4,char param_5)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  int local_res18 [4];
  undefined4 *local_38 [2];
  
  local_38[0] = (undefined4 *)0x0;
  local_res18[0] = 0;
  uVar3 = param_3 + 0x10;
  if (uVar3 < 0x7fff9) {
    uVar1 = *(uint *)(param_1 + 0x10);
    uVar2 = PkGetSendBufferEx(param_1,uVar1,uVar3,(longlong *)local_38,local_res18);
    if (-1 < (int)uVar2) {
      *local_38[0] = 0x20006;
      *(short *)(local_38[0] + 1) = (short)((ulonglong)uVar3 + 7 >> 3);
      *(ushort *)((longlong)local_38[0] + 6) = (ushort)(param_5 != '\0');
      *(undefined8 *)(local_38[0] + 2) = param_4;
      memmove(local_38[0] + 4,param_2,(ulonglong)param_3);
      uVar3 = PkWritePacketFooter(param_1,uVar1,uVar3);
      uVar2 = PkCompleteInsertion(param_1,uVar3);
    }
  }
  else {
    uVar2 = 0xc000000d;
  }
  return uVar2;
}



===== PkSendPacketTransferPage @ 14001103c =====

undefined8
PkSendPacketTransferPage
          (longlong *param_1,void *param_2,uint param_3,undefined8 param_4,ushort param_5,
          undefined8 *param_6,int param_7)

{
  uint uVar1;
  undefined8 *puVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  undefined8 *local_68;
  undefined2 local_60;
  undefined2 uStack_5e;
  undefined2 uStack_5c;
  undefined2 uStack_5a;
  undefined8 uStack_58;
  ushort local_50;
  undefined2 uStack_4e;
  int iStack_4c;
  undefined8 uStack_48;
  
  param_7 = 0;
  iVar6 = 0;
  local_68 = (undefined8 *)0x0;
  uVar7 = 0;
  uStack_48 = 0;
  for (puVar2 = param_6; puVar2 != (undefined8 *)0x0; puVar2 = (undefined8 *)*puVar2) {
    iVar6 = iVar6 + *(int *)(puVar2 + 1);
  }
  uVar3 = iVar6 * 8 + 0x18;
  uVar5 = uVar3 + param_3;
  if (uVar5 < 0x7fff9) {
    uVar1 = *(uint *)(param_1 + 0x10);
    uVar4 = PkGetSendBufferEx(param_1,uVar1,uVar5,(longlong *)&local_68,&param_7);
    puVar2 = local_68;
    if (-1 < (int)uVar4) {
      uStack_5e = (undefined2)(uVar3 >> 3);
      local_60 = 7;
      uStack_5c = (undefined2)((ulonglong)uVar5 + 7 >> 3);
      uStack_5a = 1;
      local_50 = param_5;
      uStack_4e = 0;
      *local_68 = CONCAT26(1,CONCAT24(uStack_5c,CONCAT22(uStack_5e,7)));
      local_68[1] = param_4;
      local_68[2] = CONCAT44(iVar6,(uint)param_5);
      local_68[3] = uStack_48;
      uStack_58 = param_4;
      iStack_4c = iVar6;
      for (; param_6 != (undefined8 *)0x0; param_6 = (undefined8 *)*param_6) {
        memmove(puVar2 + uVar7 + 3,(void *)((longlong)param_6 + 0xc),
                (ulonglong)*(uint *)(param_6 + 1) << 3);
        uVar7 = (ulonglong)(uint)((int)uVar7 + *(int *)(param_6 + 1));
      }
      memmove((void *)((ulonglong)uVar3 + (longlong)puVar2),param_2,(ulonglong)param_3);
      uVar3 = PkWritePacketFooter(param_1,uVar1,uVar5);
      uVar4 = PkCompleteInsertion(param_1,uVar3);
    }
  }
  else {
    uVar4 = 0xc000000d;
  }
  return uVar4;
}



===== PkpExpectInterrupt @ 14001119c =====

void PkpExpectInterrupt(longlong param_1,char param_2)

{
  uint uVar1;
  
  uVar1 = PkpExpectedInterruptCount(param_1);
  if (uVar1 < 0x40) {
    if (param_2 == '\0') {
      LOCK();
      *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x8c) + 1;
      UNLOCK();
    }
    else {
      LOCK();
      *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
      UNLOCK();
    }
  }
  return;
}



===== PkpInitRingBufferControl @ 1400111d0 =====

undefined8 PkpInitRingBufferControl(longlong *param_1)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = *(uint *)param_1[3];
  uVar4 = *(uint *)(param_1[3] + 4);
  uVar5 = *(uint *)*param_1;
  uVar6 = *(uint *)(*param_1 + 4);
  uVar3 = *(uint *)(param_1 + 5);
  cVar2 = PkpValidatePointer(uVar3,uVar1);
  if ((cVar2 != '\0') && (cVar2 = PkpValidatePointer(uVar3,uVar4), cVar2 != '\0')) {
    uVar3 = *(uint *)(param_1 + 2);
    cVar2 = PkpValidatePointer(uVar3,uVar5);
    if ((cVar2 != '\0') && (cVar2 = PkpValidatePointer(uVar3,uVar6), cVar2 != '\0')) {
      *(uint *)(param_1 + 8) = uVar1;
      *(uint *)((longlong)param_1 + 0x44) = uVar4;
      *(uint *)(param_1 + 0x10) = uVar5;
      *(uint *)((longlong)param_1 + 0x84) = uVar6;
      *(undefined4 *)(*param_1 + 0xc) = 0;
      *(undefined4 *)(param_1[3] + 8) = 0;
      *(undefined4 *)(*param_1 + 0x40) = 0;
      *(uint *)(*param_1 + 0x40) = *(uint *)(*param_1 + 0x40) | 1;
      PkpExpectInterrupt((longlong)param_1,'\x01');
      PkpExpectInterrupt((longlong)param_1,'\0');
      return 0;
    }
  }
  return 0xc0000102;
}



===== PkpValidatePointer @ 140011288 =====

undefined1 PkpValidatePointer(uint param_1,uint param_2)

{
  if ((param_2 < param_1) && ((param_2 & 7) == 0)) {
    return 1;
  }
  return 0;
}



===== PkCalculateMdlOffsets @ 1400112a0 =====

undefined8
PkCalculateMdlOffsets(ulonglong param_1,uint param_2,uint *param_3,uint param_4,longlong param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  
  uVar2 = 0;
  uVar3 = param_1;
  while( true ) {
    if (param_4 <= (uint)uVar2) {
      return 0;
    }
    uVar1 = (ulonglong)*param_3 + 0xfff + (ulonglong)(param_3[1] & 0xfff) >> 0xc;
    if (0xfffff < (uint)uVar1) break;
    *(ulonglong *)(param_5 + uVar2 * 8) = uVar3;
    param_3 = param_3 + uVar1 * 2 + 2;
    uVar3 = uVar3 + uVar1 * 8 + 0x30;
    if ((param_2 != 0) && (param_1 + param_2 < uVar3)) {
      return 0xc0000023;
    }
    uVar2 = (ulonglong)((uint)uVar2 + 1);
  }
  return 0xc000000d;
}



===== PkCreateGpaRangesEx @ 140011338 =====

void PkCreateGpaRangesEx(undefined8 param_1,longlong *param_2,uint *param_3,undefined8 param_4,
                        uint param_5,uint param_6,char param_7)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  uint *puVar7;
  
  if (param_2 != (longlong *)0x0) {
    bVar2 = false;
    do {
      uVar3 = *(uint *)(param_2 + 5);
      if (param_5 < uVar3) {
        uVar3 = uVar3 - param_5;
        if (param_6 != 0) {
          if ((param_7 == '\0') && (uVar3 < param_6)) {
            param_6 = param_6 - uVar3;
          }
          else {
            bVar2 = true;
            uVar3 = param_6;
          }
        }
        iVar1 = *(int *)((longlong)param_2 + 0x2c);
        *param_3 = uVar3;
        param_3[1] = *(int *)((longlong)param_2 + 0x2c) + param_5 & 0xfff;
        uVar6 = (ulonglong)uVar3 + 0xfff + (ulonglong)(iVar1 + param_5 & 0xfff) >> 0xc;
        uVar3 = *(int *)((longlong)param_2 + 0x2c) + param_5 >> 0xc;
        if ((short)uVar6 != 0) {
          uVar5 = uVar6 & 0xffff;
          puVar7 = param_3;
          do {
            puVar7 = puVar7 + 2;
            uVar4 = (ulonglong)uVar3;
            uVar3 = uVar3 + 1;
            *(longlong *)puVar7 = param_2[uVar4 + 6];
            uVar5 = uVar5 - 1;
          } while (uVar5 != 0);
        }
        param_3 = (uint *)((longlong)param_3 + (ulonglong)((int)uVar6 * 8 + 8));
        if (bVar2) {
          return;
        }
        param_5 = 0;
      }
      else {
        param_5 = param_5 - uVar3;
      }
      param_2 = (longlong *)*param_2;
    } while (param_2 != (longlong *)0x0);
  }
  return;
}



===== PkCreateGpaRangesList @ 14001142c =====

void PkCreateGpaRangesList
               (undefined8 param_1,longlong *param_2,uint *param_3,undefined8 param_4,uint param_5,
               uint param_6,char param_7)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  longlong *plVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  
  if (param_2 != (longlong *)0x0) {
    bVar2 = false;
    do {
      uVar3 = *(uint *)(param_2 + 1);
      if (param_5 < uVar3) {
        uVar3 = uVar3 - param_5;
        if (param_6 != 0) {
          if ((param_7 == '\0') && (uVar3 < param_6)) {
            param_6 = param_6 - uVar3;
          }
          else {
            bVar2 = true;
            uVar3 = param_6;
          }
        }
        iVar1 = *(int *)((longlong)param_2 + 0xc);
        *param_3 = uVar3;
        param_3[1] = *(int *)((longlong)param_2 + 0xc) + param_5 & 0xfff;
        plVar4 = (longlong *)param_2[2];
        uVar7 = *(int *)((longlong)param_2 + 0xc) + param_5 >> 0xc;
        uVar6 = 0;
        while ((uVar5 = (uint)((ulonglong)uVar3 + 0xfff + (ulonglong)(iVar1 + param_5 & 0xfff) >>
                              0xc), plVar4 != param_2 + 2 && ((uint)uVar6 < uVar5))) {
          if (uVar7 == 0) {
            *(longlong *)(param_3 + uVar6 * 2 + 2) = plVar4[2];
            uVar6 = (ulonglong)((uint)uVar6 + 1);
          }
          else {
            uVar7 = uVar7 - 1;
          }
          plVar4 = (longlong *)*plVar4;
        }
        param_3 = (uint *)((longlong)param_3 + (ulonglong)(uVar5 * 8 + 8));
        if (bVar2) {
          return;
        }
        param_5 = 0;
      }
      else {
        param_5 = param_5 - uVar3;
      }
      param_2 = (longlong *)*param_2;
    } while (param_2 != (longlong *)0x0);
  }
  return;
}



===== PkParseGpaRanges @ 140011530 =====

undefined8 PkParseGpaRanges(uint *param_1,uint param_2,uint param_3,longlong param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  ulonglong uVar4;
  uint *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint *puVar8;
  uint uVar9;
  
  uVar2 = 0;
  uVar7 = 0;
  puVar8 = param_1;
  uVar9 = 0;
  while( true ) {
    if (param_3 <= (uint)uVar7) {
      if (param_5 != (uint *)0x0) {
        *param_5 = uVar9;
      }
      return 0;
    }
    if (((int)uVar2 < 0) ||
       (uVar6 = ((ulonglong)param_2 - (longlong)puVar8) + (longlong)param_1, uVar6 < 8)) {
      return 0xc0000004;
    }
    if ((*puVar8 == 0) || (0xfff < puVar8[1])) {
      return 0xc000000d;
    }
    uVar4 = (ulonglong)(puVar8[1] & 0xfff) + 0xfff + (ulonglong)*puVar8 >> 0xc;
    if (0xfffff < (uint)uVar4) {
      return 0xc000000d;
    }
    uVar1 = uVar9 + (uint)uVar4;
    if (uVar1 < uVar9) break;
    if (uVar6 < uVar4 * 8 + 8) {
      return 0xc0000004;
    }
    if (param_4 != 0) {
      *(uint **)(param_4 + uVar7 * 8) = puVar8;
    }
    puVar5 = puVar8 + uVar4 * 2 + 2;
    puVar3 = (uint *)0xffffffffffffffff;
    if (puVar8 <= puVar5) {
      puVar3 = puVar5;
    }
    uVar2 = -(uint)(puVar5 < puVar8) & 0xc0000095;
    uVar7 = (ulonglong)((uint)uVar7 + 1);
    puVar8 = puVar3;
    uVar9 = uVar1;
  }
  return 0xc0000095;
}



===== PkSendPacketGpaDirect @ 140011628 =====

undefined8
PkSendPacketGpaDirect
          (longlong *param_1,void *param_2,uint param_3,undefined8 param_4,longlong *param_5,
          uint param_6,uint param_7,char param_8)

{
  bool bVar1;
  undefined2 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  int iVar7;
  undefined2 **ppuVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int local_res18 [2];
  undefined8 local_res20;
  undefined2 *local_48 [2];
  
  local_res18[0] = 0;
  iVar7 = 0;
  local_48[0] = (undefined2 *)0x0;
  bVar1 = false;
  iVar11 = 0;
  uVar10 = param_6;
  uVar9 = param_7;
  for (plVar6 = param_5; plVar6 != (longlong *)0x0; plVar6 = (longlong *)*plVar6) {
    uVar3 = *(uint *)(plVar6 + 5);
    if (uVar10 < uVar3) {
      iVar11 = iVar11 + 1;
      uVar3 = uVar3 - uVar10;
      uVar4 = (ulonglong)uVar3;
      if (uVar9 != 0) {
        if ((param_8 == '\0') && (uVar3 < uVar9)) {
          uVar9 = uVar9 - uVar3;
        }
        else {
          bVar1 = true;
          uVar4 = (ulonglong)uVar9;
        }
      }
      iVar7 = iVar7 + (int)((ulonglong)(*(int *)((longlong)plVar6 + 0x2c) + uVar10 & 0xfff) + 0xfff
                            + uVar4 >> 0xc) * 8 + 8;
      uVar10 = 0;
    }
    else {
      uVar10 = uVar10 - uVar3;
    }
    if (bVar1) break;
  }
  uVar10 = iVar7 + 0x18;
  uVar9 = uVar10 + param_3;
  if (uVar9 < 0x7fff9) {
    uVar3 = *(uint *)(param_1 + 0x10);
    ppuVar8 = local_48;
    plVar6 = param_1;
    local_res20 = param_4;
    uVar5 = PkGetSendBufferEx(param_1,uVar3,uVar9,(longlong *)ppuVar8,local_res18);
    puVar2 = local_48[0];
    if (-1 < (int)uVar5) {
      *local_48[0] = 9;
      local_48[0][3] = 1;
      local_48[0][1] = (short)(uVar10 >> 3);
      local_48[0][2] = (short)((ulonglong)uVar9 + 7 >> 3);
      *(undefined8 *)(local_48[0] + 4) = local_res20;
      *(int *)(local_48[0] + 10) = iVar11;
      PkCreateGpaRangesEx(plVar6,param_5,(uint *)(local_48[0] + 0xc),ppuVar8,param_6,param_7,param_8
                         );
      memmove((void *)((ulonglong)uVar10 + (longlong)puVar2),param_2,(ulonglong)param_3);
      uVar10 = PkWritePacketFooter(param_1,uVar3,uVar9);
      uVar5 = PkCompleteInsertion(param_1,uVar10);
    }
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== PkSendPacketGpaDirectList @ 1400117d0 =====

undefined8
PkSendPacketGpaDirectList
          (longlong *param_1,void *param_2,uint param_3,undefined8 param_4,longlong *param_5,
          uint param_6,uint param_7,char param_8)

{
  bool bVar1;
  undefined2 *puVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong *plVar6;
  int iVar7;
  undefined2 **ppuVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int local_res18 [2];
  undefined8 local_res20;
  undefined2 *local_48 [2];
  
  local_res18[0] = 0;
  iVar7 = 0;
  local_48[0] = (undefined2 *)0x0;
  bVar1 = false;
  iVar11 = 0;
  uVar10 = param_6;
  uVar9 = param_7;
  for (plVar6 = param_5; plVar6 != (longlong *)0x0; plVar6 = (longlong *)*plVar6) {
    uVar3 = *(uint *)(plVar6 + 1);
    if (uVar10 < uVar3) {
      iVar11 = iVar11 + 1;
      uVar3 = uVar3 - uVar10;
      uVar4 = (ulonglong)uVar3;
      if (uVar9 != 0) {
        if ((param_8 == '\0') && (uVar3 < uVar9)) {
          uVar9 = uVar9 - uVar3;
        }
        else {
          bVar1 = true;
          uVar4 = (ulonglong)uVar9;
        }
      }
      iVar7 = iVar7 + (int)((ulonglong)(*(int *)((longlong)plVar6 + 0xc) + uVar10 & 0xfff) + 0xfff +
                            uVar4 >> 0xc) * 8 + 8;
      uVar10 = 0;
    }
    else {
      uVar10 = uVar10 - uVar3;
    }
    if (bVar1) break;
  }
  uVar10 = iVar7 + 0x18;
  uVar9 = uVar10 + param_3;
  if (uVar9 < 0x7fff9) {
    uVar3 = *(uint *)(param_1 + 0x10);
    ppuVar8 = local_48;
    plVar6 = param_1;
    local_res20 = param_4;
    uVar5 = PkGetSendBufferEx(param_1,uVar3,uVar9,(longlong *)ppuVar8,local_res18);
    puVar2 = local_48[0];
    if (-1 < (int)uVar5) {
      *local_48[0] = 9;
      local_48[0][3] = 1;
      local_48[0][1] = (short)(uVar10 >> 3);
      local_48[0][2] = (short)((ulonglong)uVar9 + 7 >> 3);
      *(undefined8 *)(local_48[0] + 4) = local_res20;
      *(int *)(local_48[0] + 10) = iVar11;
      PkCreateGpaRangesList
                (plVar6,param_5,(uint *)(local_48[0] + 0xc),ppuVar8,param_6,param_7,param_8);
      memmove((void *)((ulonglong)uVar10 + (longlong)puVar2),param_2,(ulonglong)param_3);
      uVar10 = PkWritePacketFooter(param_1,uVar3,uVar9);
      uVar5 = PkCompleteInsertion(param_1,uVar10);
    }
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== PkInitializeRingBuffer @ 140011978 =====

ulonglong PkInitializeRingBuffer
                    (longlong *param_1,longlong param_2,undefined8 param_3,int param_4,
                    longlong param_5,undefined8 param_6,int param_7)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong local_38;
  longlong local_30;
  longlong local_28;
  longlong local_20;
  
  local_28 = 0;
  local_20 = 0;
  local_30 = 0;
  local_38 = 0;
  uVar1 = PkpDoubleMapBuffer(param_3,param_4 << 0xc,&local_30,&local_28);
  lVar2 = 0;
  if (-1 < (int)uVar1) {
    uVar1 = PkpDoubleMapBuffer(param_6,param_7 << 0xc,&local_38,&local_20);
    if (-1 < (int)uVar1) {
      memset(param_1,0,0xc0);
      param_1[4] = local_28;
      *param_1 = param_5;
      param_1[1] = local_20;
      param_1[0x13] = (longlong)(param_1 + 0x12);
      param_1[3] = param_2;
      *(int *)(param_1 + 5) = param_4 << 0xc;
      *(int *)(param_1 + 2) = param_7 << 0xc;
      uVar1 = PkpInitRingBufferControl(param_1);
      if (-1 < (int)uVar1) {
        param_1[6] = local_30;
        param_1[7] = local_38;
        return 0;
      }
    }
    lVar2 = local_38;
  }
  if (local_30 != 0) {
    PkpFreeDoubleMappedBuffer(local_30);
  }
  if (lVar2 != 0) {
    PkpFreeDoubleMappedBuffer(lVar2);
  }
  return uVar1 & 0xffffffff;
}



===== PkUninitializeRingBuffer @ 140011a98 =====

void PkUninitializeRingBuffer(longlong param_1)

{
  if (*(longlong *)(param_1 + 0x30) != 0) {
    PkpFreeDoubleMappedBuffer(*(longlong *)(param_1 + 0x30));
    *(undefined8 *)(param_1 + 0x30) = 0;
  }
  if (*(longlong *)(param_1 + 0x38) != 0) {
    PkpFreeDoubleMappedBuffer(*(longlong *)(param_1 + 0x38));
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  return;
}



===== PkpDoubleMapBuffer @ 140011ad4 =====

undefined8 PkpDoubleMapBuffer(undefined8 param_1,uint param_2,longlong *param_3,undefined8 *param_4)

{
  size_t _Size;
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  bVar1 = false;
  uVar5 = 0;
  lVar2 = IoAllocateMdl(param_1,param_2 * 2,0,0,0);
  if (lVar2 != 0) {
    *(uint *)(lVar2 + 0x28) = param_2;
    MmProbeAndLockPages(lVar2,0,2);
    bVar1 = true;
    _Size = (ulonglong)(param_2 >> 0xc) * 8;
    memmove((void *)(_Size + lVar2 + 0x30),(void *)(lVar2 + 0x30),_Size);
    *(uint *)(lVar2 + 0x28) = param_2 * 2;
    lVar3 = MmMapLockedPagesSpecifyCache
                      (lVar2,0,1,0,uVar5 & 0xffffffff00000000,ExDefaultMdlProtection | 0x40000010);
    if (lVar3 != 0) {
      *param_3 = lVar2;
      *param_4 = *(undefined8 *)(lVar2 + 0x18);
      lVar2 = 0;
      uVar4 = 0;
      goto LAB_140011bc1;
    }
    *(uint *)(lVar2 + 0x28) = *(uint *)(lVar2 + 0x28) >> 1;
  }
  uVar4 = 0xc000009a;
LAB_140011bc1:
  if (lVar2 != 0) {
    if (bVar1) {
      MmUnlockPages(lVar2);
    }
    IoFreeMdl(lVar2);
  }
  return uVar4;
}



===== PkpFreeDoubleMappedBuffer @ 140011c0c =====

void PkpFreeDoubleMappedBuffer(longlong param_1)

{
  MmUnmapLockedPages(*(undefined8 *)(param_1 + 0x18),param_1);
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) >> 1;
  MmUnlockPages(param_1);
  IoFreeMdl(param_1);
  return;
}



===== PkSetInterruptMaskSkipCount @ 140011c58 =====

void PkSetInterruptMaskSkipCount(longlong param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x98) = param_2;
  return;
}



===== __GSHandlerCheck @ 140011c78 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 140011c9c =====

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



===== __cpu_features_init @ 140011d10 =====

/* WARNING: Removing unreachable block (ram,0x000140011d7a) */
/* WARNING: Removing unreachable block (ram,0x000140011d29) */
/* WARNING: Removing unreachable block (ram,0x000140011d1a) */

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



===== __security_check_cookie @ 140011de0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140011e20 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 140011e50 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000140011e50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 140011e80 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memmove @ 140011f00 =====

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



===== memset @ 140012200 =====

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



===== __memset_repmovs @ 140012340 =====

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



===== __memset_query @ 1400123c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140012440 =====

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



===== __memset_spec_ermsb_repmovsb @ 140012580 =====

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



===== __memset_spec_plain @ 140012600 =====

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



===== VmbChannelInitSetClientContextSize @ 14001c010 =====

undefined8 VmbChannelInitSetClientContextSize(longlong param_1,undefined4 param_2)

{
                    /* 0x1c010  31  VmbChannelInitSetClientContextSize */
  if (*(int *)(param_1 + 0x898) == 0) {
    *(undefined4 *)(param_1 + 0x6d4) = param_2;
    return 0;
  }
  return 0xc00000ef;
}



===== VmbChannelInitSetFriendlyName @ 14001c030 =====

undefined8 VmbChannelInitSetFriendlyName(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
                    /* 0x1c030  33  VmbChannelInitSetFriendlyName */
  if (*(int *)(param_1 + 0x898) == 0) {
    if (*(longlong *)(param_1 + 0x890) == 0) {
      uVar1 = RtlDuplicateUnicodeString(1,param_2,param_1 + 0x888);
    }
    else {
      uVar1 = 0xc00000f0;
    }
  }
  else {
    uVar1 = 0xc00000ef;
  }
  return uVar1;
}



===== VmbChannelInitSetInlinePacketContextSize @ 14001c080 =====

undefined8 VmbChannelInitSetInlinePacketContextSize(longlong param_1,int param_2)

{
                    /* 0x1c080  34  VmbChannelInitSetInlinePacketContextSize */
  if (*(int *)(param_1 + 0x898) == 0) {
    *(uint *)(param_1 + 0x6d8) = param_2 + 7U & 0xfffffff8;
    return 0;
  }
  return 0xc00000ef;
}



===== VmbChannelInitSetMaximumExternalData @ 14001c0b0 =====

undefined8 VmbChannelInitSetMaximumExternalData(longlong param_1,int param_2,int param_3)

{
                    /* 0x1c0b0  35  VmbChannelInitSetMaximumExternalData */
  if (*(int *)(param_1 + 0x898) != 0) {
    return 0xc00000ef;
  }
  if (param_2 == 0) {
    return 0xc00000f0;
  }
  if (param_3 == 0) {
    return 0xc00000f1;
  }
  *(int *)(param_1 + 0x6cc) = param_2;
  *(int *)(param_1 + 0x6d0) = param_3;
  return 0;
}



===== VmbChannelInitSetMaximumPacketCount @ 14001c0f0 =====

undefined8 VmbChannelInitSetMaximumPacketCount(longlong param_1,int param_2)

{
                    /* 0x1c0f0  36  VmbChannelInitSetMaximumPacketCount */
  if (*(int *)(param_1 + 0x898) != 0) {
    return 0xc00000ef;
  }
  if (param_2 == 0) {
    return 0xc00000f0;
  }
  *(int *)(param_1 + 0x6c4) = param_2;
  return 0;
}



===== VmbChannelInitSetShortLifetimeThreshold @ 14001c120 =====

undefined8 VmbChannelInitSetShortLifetimeThreshold(longlong param_1,undefined4 param_2)

{
                    /* 0x1c120  41  VmbChannelInitSetShortLifetimeThreshold */
  if (*(int *)(param_1 + 0x898) == 0) {
    *(undefined4 *)(param_1 + 0x6fc) = param_2;
    return 0;
  }
  return 0xc00000ef;
}



===== VmbChannelInitSuppressQueueManagement @ 14001c140 =====

undefined8 VmbChannelInitSuppressQueueManagement(longlong param_1,undefined8 param_2)

{
                    /* 0x1c140  43  VmbChannelInitSuppressQueueManagement */
  if ((*(int *)(param_1 + 0x898) == 0) || (*(int *)(param_1 + 0x898) == 0xc)) {
    *(undefined1 *)(param_1 + 0x6c1) = 1;
    *(undefined8 *)(param_1 + 0x850) = param_2;
    return 0;
  }
  return 0xc00000ef;
}



===== VmbChannelInitialize @ 14001c170 =====

int VmbChannelInitialize(undefined8 param_1,char param_2,void *param_3,uint param_4)

{
  int iVar1;
  undefined8 uVar2;
  
                    /* 0x1c170  44  VmbChannelInitialize */
  if (param_4 < 0xd80) {
    iVar1 = -0x3fffffdd;
  }
  else {
    uVar2 = KmclInitializeChannel(param_3,param_1,param_2);
    iVar1 = 0;
    if ((int)uVar2 < 0) {
      iVar1 = (int)uVar2;
    }
  }
  return iVar1;
}



===== VmbClientChannelInitSetTargetFile @ 14001c1b0 =====

undefined8 VmbClientChannelInitSetTargetFile(longlong param_1,undefined8 param_2,longlong param_3)

{
  undefined8 uVar1;
  
                    /* 0x1c1b0  70  VmbClientChannelInitSetTargetFile */
  if ((*(char *)(param_1 + 0x6c0) == '\0') && (*(int *)(param_1 + 0x898) == 0)) {
    if ((*(char *)(param_1 + 0x7c0) == '\0') && (*(char *)(param_1 + 0x7c1) == '\0')) {
      ObfReferenceObject(param_2);
      *(undefined8 *)(param_1 + 0xaa0) = param_2;
      if (param_3 != 0) {
        ObfReferenceObject(param_3);
        *(longlong *)(param_1 + 0xaa8) = param_3;
      }
      *(undefined1 *)(param_1 + 0x7c1) = 1;
      uVar1 = 0;
    }
    else {
      uVar1 = 0xc00000f0;
    }
  }
  else {
    uVar1 = 0xc00000ef;
  }
  return uVar1;
}



===== InChangeClientContextSize @ 14001c24c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong InChangeClientContextSize(longlong *param_1,int param_2)

{
  byte bVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  bool bVar5;
  ulonglong uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  uint uVar11;
  longlong *plVar12;
  longlong *plVar13;
  uint uVar14;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [24];
  longlong local_68 [6];
  
  puVar10 = auStack_88;
  local_68[4] = __security_cookie ^ (ulonglong)auStack_88;
  local_68[0] = 0;
  local_68[1] = 0;
  if ((int)param_1[0x89] != 0) {
    uVar6 = 0xc0000184;
    puVar10 = auStack_88;
    goto LAB_14001c48c;
  }
  if (param_2 == (int)param_1[0xae]) {
    uVar6 = 0;
    goto LAB_14001c48c;
  }
  local_68[2] = 0;
  local_68[3] = 0;
  KeQueryNodeActiveAffinity(*(undefined2 *)(*param_1 + 0xcc8),local_68,0);
  if (local_68[0] != 0) {
    KeSetSystemGroupAffinityThread(local_68,local_68 + 2);
  }
  puVar9 = auStack_88;
  uVar14 = ((int)param_1[0xb5] - (int)param_1[0xae]) + param_2;
  plVar12 = (longlong *)param_1[0xa0];
  while (plVar12 != param_1 + 0xa0) {
    plVar13 = plVar12;
    if ((int)plVar12[2] == 0) {
      uVar11 = (*(int *)((longlong)plVar12 + -0xc) - *(int *)((longlong)plVar12 + 0x3c)) + param_2;
      if (*(uint *)(plVar12 + -2) < uVar11) {
        puVar7 = (undefined8 *)ExAllocatePool2(0x40,uVar11,0x6e696b56);
        if (puVar7 != (undefined8 *)0x0) {
          *(uint *)(puVar7 + 1) = uVar11;
          *(uint *)((longlong)puVar7 + 0xc) = uVar11;
          *(undefined1 *)(puVar7 + 2) = 0x40;
          plVar13 = puVar7 + 3;
          puVar7[4] = plVar13;
          *plVar13 = (longlong)plVar13;
          *(undefined4 *)(puVar7 + 5) = 0;
          puVar7[6] = 0;
          puVar7[9] = 0;
          *(undefined1 *)((longlong)puVar7 + 0x11) = 0;
          bVar1 = *(byte *)(plVar12 + -1);
          *(int *)((longlong)plVar12 + 0x3c) = param_2;
          *puVar7 = param_1;
          *(byte *)(puVar7 + 2) = bVar1 & 0xfe | 0x40;
          *(int *)(puVar7 + 7) = (int)plVar12[4];
          *(undefined4 *)((longlong)puVar7 + 0x3c) = *(undefined4 *)((longlong)plVar12 + 0x24);
          *(int *)(puVar7 + 8) = (int)plVar12[5];
          memmove(puVar7 + 0x14,plVar12 + 0x11,(ulonglong)*(uint *)(plVar12 + 4));
          if (*(uint *)((longlong)plVar12 + 0x34) != 0) {
            bVar5 = InpParseGpaDirectPacket
                              ((longlong)puVar7,(uint)*(ushort *)((longlong)puVar7 + 0xa2) << 3,
                               *(uint *)((longlong)plVar12 + 0x34));
            if (!bVar5) {
              uVar6 = 0xc0000102;
              ExFreePoolWithTag(puVar7,0x6e696b56);
              puVar10 = auStack_88;
              goto LAB_14001c479;
            }
          }
          plVar2 = (longlong *)plVar12[1];
          if ((longlong *)*plVar2 == plVar12) {
            *plVar13 = (longlong)plVar12;
            puVar7[4] = plVar2;
            *plVar2 = (longlong)plVar13;
            plVar12[1] = (longlong)plVar13;
            lVar3 = *plVar12;
            if ((*(longlong **)(lVar3 + 8) == plVar12) && ((longlong *)*plVar13 == plVar12)) {
              *plVar13 = lVar3;
              *(longlong **)(lVar3 + 8) = plVar13;
              InpFreePacket((longlong)param_1,(longlong)(plVar12 + -3));
              goto LAB_14001c41d;
            }
          }
          pcVar4 = (code *)swi(0x29);
          (*pcVar4)(3);
          puVar9 = auStack_80;
        }
        uVar6 = 0xc000009a;
        puVar10 = puVar9;
        goto LAB_14001c479;
      }
      param_1[0xad] = param_1[0xad] + (ulonglong)(*(int *)((longlong)plVar12 + -0xc) - uVar11);
      *(uint *)((longlong)plVar12 + -0xc) = uVar11;
      *(int *)((longlong)plVar12 + 0x3c) = param_2;
    }
LAB_14001c41d:
    plVar12 = (longlong *)*plVar13;
  }
  if (param_1[0xb6] == 0) {
LAB_14001c469:
    *(uint *)(param_1 + 0xb5) = uVar14;
    uVar6 = 0;
    *(int *)(param_1 + 0xae) = param_2;
    puVar10 = auStack_88;
  }
  else {
    uVar8 = InpReacquirePacketAllocationResources(param_1,uVar14);
    uVar6 = uVar8 & 0xffffffff;
    puVar10 = auStack_88;
    if (-1 < (int)uVar8) goto LAB_14001c469;
  }
LAB_14001c479:
  *(undefined8 *)(puVar10 + -8) = 0x14001c485;
  KeRevertToUserGroupAffinityThread(puVar10 + 0x30);
LAB_14001c48c:
  *(undefined8 *)(puVar10 + -8) = 0x14001c499;
  return uVar6;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 14001c4b8 =====

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



===== KmclpFindVmbus @ 14001c584 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int KmclpFindVmbus(void)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  undefined8 local_res8;
  longlong local_res10;
  undefined8 local_48;
  wchar_t *local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_res8 = 0;
  local_res10 = 0;
  local_40 = L"\\Device\\VMBus\\kmcl_interface";
  local_48 = 0x3a0038;
  local_18 = 0;
  DAT_140016370 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  _KmclDirectInterface = 0;
  uRam0000000140016348 = 0;
  _DAT_140016350 = 0;
  uRam0000000140016358 = 0;
  DAT_140016360 = 0;
  DAT_140016368 = 0;
  iVar2 = IoGetDeviceObjectPointer(&local_48,0x1f01ff,&local_res10,&local_res8);
  if (-1 < iVar2) {
    KeInitializeEvent(&local_28,1);
    lVar3 = IoBuildSynchronousFsdRequest(0x1b,local_res8,0,0,0,&local_28,&local_38);
    if (lVar3 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      lVar1 = *(longlong *)(lVar3 + 0xb8);
      *(undefined8 *)(lVar1 + -0x28) = 0;
      *(undefined **)(lVar1 + -0x40) = &VMBUS_DIRECT_INTERFACE_TYPE;
      *(undefined **)(lVar1 + -0x30) = &KmclDirectInterface;
      *(undefined1 *)(lVar1 + -0x47) = 8;
      *(undefined4 *)(lVar1 + -0x38) = 0x10038;
      *(undefined4 *)(lVar3 + 0x30) = 0xc00000bb;
      iVar2 = IofCallDriver(local_res8);
      if (iVar2 == 0x103) {
        iVar2 = KeWaitForSingleObject(&local_28,0,0,0,0);
        if (iVar2 == 0) {
          iVar2 = (int)local_38;
        }
      }
    }
  }
  if (local_res10 != 0) {
    ObfDereferenceObject();
  }
  return iVar2;
}



===== KmclpServerOfferChannel @ 14001c70c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong KmclpServerOfferChannel(longlong *param_1)

{
  longlong *plVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined2 uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  undefined1 auStackY_298 [32];
  undefined8 local_228;
  ushort local_220 [4];
  undefined1 *local_218;
  undefined8 local_210;
  longlong local_208;
  undefined8 local_200;
  longlong lStack_1f8;
  ushort *local_1f0;
  undefined8 uStack_1e8;
  undefined8 local_1e0;
  ulonglong uStack_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  ulonglong local_198;
  ushort local_190;
  undefined2 local_18e;
  undefined2 local_18c;
  undefined2 local_18a;
  undefined1 local_188;
  longlong local_180;
  longlong lStack_178;
  longlong local_170;
  longlong lStack_168;
  longlong local_160;
  longlong lStack_158;
  longlong local_150;
  longlong lStack_148;
  longlong local_140;
  longlong lStack_138;
  longlong local_130;
  longlong lStack_128;
  longlong local_120;
  longlong lStack_118;
  longlong local_110;
  wchar_t local_f8 [32];
  undefined1 local_b8 [128];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_298;
  builtin_wcsncpy(local_f8 + 0x10,L"s\\offer\\",9);
  local_218 = local_b8;
  builtin_wcsncpy(local_f8,L"\\DosDevices\\VMBu",0x10);
  local_220[0] = 0;
  local_220[1] = 0x7e;
  local_220[2] = 0;
  local_220[3] = 0;
  local_210 = 0;
  local_228 = 0;
  puVar9 = (undefined8 *)0xc0;
  local_1e0 = 0;
  uStack_1d8 = uStack_1d8 & 0xffffffff00000000;
  local_1d0 = 0;
  uStack_1c8 = 0;
  local_200 = 0;
  lStack_1f8 = 0;
  local_1f0 = (ushort *)0x0;
  uStack_1e8 = 0;
  memset(&local_1b8,0,0xc0);
  param_1[0x156] = *(longlong *)((longlong)param_1 + 0x6dc);
  param_1[0x157] = *(longlong *)((longlong)param_1 + 0x6e4);
  *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)((longlong)param_1 + 0x6ec);
  *(int *)((longlong)param_1 + 0xac4) = (int)param_1[0xde];
  *(undefined4 *)(param_1 + 0x159) = *(undefined4 *)((longlong)param_1 + 0x6f4);
  *(int *)((longlong)param_1 + 0xacc) = (int)param_1[0xdf];
  if (param_1[0xf4] == 0) {
    RtlUnicodeStringPrintf
              (local_220,L"%s{%08lx-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",local_f8,
               (ulonglong)*(uint *)(param_1 + 0xe2));
    lStack_1f8 = 0;
LAB_14001c987:
    uStack_1e8 = CONCAT44(uStack_1e8._4_4_,0x240);
    local_1f0 = local_220;
    local_200 = CONCAT44(local_200._4_4_,0x30);
    puVar9 = &local_200;
    local_1e0 = 0;
    uStack_1d8 = 0;
    uVar3 = ZwOpenFile(&local_228,0x1f01ff,puVar9,&local_1d0);
    uVar8 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      local_208 = 0;
      ObReferenceObjectByHandle(local_228,0,*(undefined8 *)IoFileObjectType_exref,0);
      param_1[0x155] = local_208;
      ZwClose(local_228);
      lVar5 = IoGetRelatedDeviceObject(param_1[0x155]);
      param_1[0x154] = lVar5;
      ObfReferenceObject(lVar5);
      local_18e = *(undefined2 *)((longlong)param_1 + 0x70a);
      local_1b8 = *(undefined8 *)((longlong)param_1 + 0x6dc);
      uStack_1b0 = *(undefined8 *)((longlong)param_1 + 0x6e4);
      local_18c = *(undefined2 *)((longlong)param_1 + 0x70c);
      local_1a8 = *(undefined8 *)((longlong)param_1 + 0x6ec);
      uStack_1a0 = *(undefined8 *)((longlong)param_1 + 0x6f4);
      local_188 = *(undefined1 *)((longlong)param_1 + 0x7c3);
      if (*(ushort *)(param_1 + 0xe1) != 0) {
        local_190 = local_190 | 0x400;
        local_198 = (ulonglong)*(ushort *)(param_1 + 0xe1);
      }
      if (*(char *)((longlong)param_1 + 0x703) != '\0') {
        local_190 = local_190 | 0x10;
      }
      if (*(char *)((longlong)param_1 + 0x701) != '\0') {
        local_190 = local_190 | 0x100;
      }
      if (*(char *)((longlong)param_1 + 0x702) != '\0') {
        local_190 = local_190 | 1;
      }
      if (*(char *)((longlong)param_1 + 0x704) != '\0') {
        local_190 = local_190 | 0x1000;
      }
      if (*(char *)((longlong)param_1 + 0x705) != '\0') {
        local_190 = local_190 | 0x2000;
      }
      if ((char)param_1[0x18c] != '\0') {
        local_18a = (undefined2)param_1[0x19a];
      }
      local_180 = param_1[0xe4];
      lStack_178 = param_1[0xe5];
      local_170 = param_1[0xe6];
      lStack_168 = param_1[0xe7];
      local_160 = param_1[0xe8];
      lStack_158 = param_1[0xe9];
      local_150 = param_1[0xea];
      lStack_148 = param_1[0xeb];
      local_140 = param_1[0xec];
      lStack_138 = param_1[0xed];
      local_130 = param_1[0xee];
      lStack_128 = param_1[0xef];
      local_120 = param_1[0xf0];
      lStack_118 = param_1[0xf1];
      local_110 = param_1[0xf2];
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x40,
                 &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
      }
      puVar9 = &local_1b8;
      uVar6 = KmclpSynchronousIoControl((longlong)param_1,0x3ec01c,puVar9,0xc0,0,0);
      uVar8 = uVar6 & 0xffffffff;
      if (-1 < (int)uVar6) {
        uVar3 = VmbusSendInterfaceQuery((longlong)param_1);
        uVar8 = (ulonglong)uVar3;
        if ((int)uVar3 < 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (1 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar7 = 0x41;
LAB_14001cc24:
            WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,puVar9,param_1,(char)uVar8);
          }
        }
        else {
          uVar3 = KmclpInitializeVmbusConnection((longlong)param_1);
          uVar8 = (ulonglong)uVar3;
          if ((int)uVar3 < 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (1 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar7 = 0x42;
              goto LAB_14001cc24;
            }
          }
          else {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              puVar9 = (undefined8 *)&WPP_fa014546bb113ca58de70d4b381949e7_Traceguids;
              WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x43,
                       &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
            }
            *(undefined4 *)(param_1 + 0x113) = 3;
            LOCK();
            plVar1 = param_1 + 0x19c;
            lVar5 = *plVar1;
            *(int *)plVar1 = (int)*plVar1 + 1;
            UNLOCK();
            uVar3 = (int)lVar5 + 1;
            uVar8 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
            if ((int)uVar8 == 0) {
              iVar4 = (int)((ulonglong)((longlong)(int)uVar3 * -0x2aaaaaab) >> 0x20);
              iVar4 = ((iVar4 >> 2) - (iVar4 >> 0x1f)) * 0x18;
            }
            else {
              iVar4 = (uVar3 / 0x18) * -0x18;
            }
            lVar5 = (longlong)(int)(uVar3 + iVar4);
            *(char *)((longlong)param_1 + lVar5 * 6 + 0xce4) = (char)param_1[0x113];
            *(undefined1 *)((longlong)param_1 + lVar5 * 6 + 0xce5) =
                 *(undefined1 *)((longlong)param_1 + 0x89c);
            *(short *)((longlong)param_1 + lVar5 * 6 + 0xce6) = (short)param_1[0x115];
            *(undefined2 *)((longlong)param_1 + lVar5 * 6 + 0xce8) = 0xa31;
            uVar6 = KmclpServerOpenChannel(param_1,lVar5,(undefined *)puVar9);
            uVar8 = uVar6 & 0xffffffff;
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x44,puVar9,param_1,(char)uVar6);
            }
            if ((((int)uVar6 + 0x80000000U & 0x80000000) != 0) || ((int)uVar6 == -0x3fffff5d)) {
              uVar8 = 0;
              goto LAB_14001c821;
            }
          }
        }
      }
    }
  }
  else {
    cVar2 = ObIsKernelHandle();
    if (cVar2 != '\0') {
      puVar9 = &local_210;
      uVar3 = ZwQueryVolumeInformationFile(param_1[0xf4],&local_1d0,puVar9,8);
      uVar8 = (ulonglong)uVar3;
      if ((int)uVar3 < 0) goto LAB_14001c819;
      if ((int)local_210 == 0x3e) {
        RtlAppendUnicodeToString(local_220,L"offer");
        lStack_1f8 = param_1[0xf4];
        goto LAB_14001c987;
      }
    }
    uVar8 = 0xc000000d;
  }
LAB_14001c819:
  KmclpDisableClosedChannel((longlong)param_1);
LAB_14001c821:
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x45,puVar9,param_1,(char)uVar8);
  }
  return uVar8;
}



===== KmclpServerOpenChannel @ 14001cd94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong KmclpServerOpenChannel(longlong *param_1,undefined8 param_2,undefined *param_3)

{
  longlong *plVar1;
  bool bVar2;
  int iVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  undefined1 auStackY_a8 [32];
  longlong local_68;
  undefined8 local_60;
  undefined4 local_58;
  longlong local_50 [5];
  
  local_50[4] = __security_cookie ^ (ulonglong)auStackY_a8;
  local_68 = 0;
  bVar2 = false;
  local_60 = 0;
  local_58 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x52,param_3,param_1,(char)param_1[0x113]);
  }
  uVar9 = (*(code *)param_1[300])(param_1[0x128],&local_60);
  uVar10 = (ulonglong)uVar9;
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x53,param_3,param_1,(char)uVar9);
  }
  if ((int)uVar9 < 0) {
LAB_14001d251:
    KmclpTeardownOpenChannelState(param_1);
    if (!bVar2) goto LAB_14001d2d7;
  }
  else {
    param_3 = (undefined *)0x2;
    *(undefined2 *)(param_1 + 0x199) = (undefined2)local_58;
    bVar2 = true;
    uVar9 = (*(code *)param_1[0x134])(param_1[0x128],local_60 & 0xffffffff,2,&local_68);
    uVar10 = (ulonglong)uVar9;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x54,param_3,param_1,(char)uVar9);
    }
    if ((int)uVar9 < 0) goto LAB_14001d251;
    *(undefined4 *)(param_1 + 0x183) = (undefined4)local_60;
    if ((*(int *)(local_68 + 0x2c) != 0) || ((*(uint *)(local_68 + 0x28) & 0xfff) != 0)) {
LAB_14001d24c:
      uVar10 = 0xc000000d;
      goto LAB_14001d251;
    }
    uVar9 = local_60._4_4_;
    uVar8 = *(uint *)(local_68 + 0x28) >> 0xc;
    if ((uVar8 <= local_60._4_4_) ||
       ((uVar8 = uVar8 - local_60._4_4_, local_60._4_4_ < 2 || (uVar8 < 2)))) goto LAB_14001d24c;
    if ((*(byte *)(local_68 + 10) & 5) == 0) {
      param_3 = (undefined *)0x1;
      lVar7 = MmMapLockedPagesSpecifyCache(local_68,0,1,0);
    }
    else {
      lVar7 = *(longlong *)(local_68 + 0x18);
    }
    param_1[0x152] = lVar7;
    if (lVar7 == 0) {
      uVar10 = 0xc000009a;
      goto LAB_14001d251;
    }
    *(uint *)(param_1 + 0x153) = uVar9;
    *(uint *)((longlong)param_1 + 0xa9c) = uVar8;
    if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
      lVar6 = (ulonglong)(uVar9 << 0xc) + lVar7;
      param_3 = (undefined *)(lVar7 + 0x1000);
      uVar4 = PkInitializeRingBuffer
                        (param_1 + 8,lVar7,param_3,uVar9 - 1,lVar6,lVar6 + 0x1000,uVar8 - 1);
      uVar10 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        PkSetInterruptMaskSkipCount((longlong)(param_1 + 8),param_1 + 0x3d);
        goto LAB_14001d01f;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_14001d251;
      uVar5 = 0x55;
LAB_14001cff3:
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,param_3,param_1,(char)uVar10);
      goto LAB_14001d251;
    }
LAB_14001d01f:
    ExAcquirePushLockExclusiveEx(param_1 + 0x15f,0);
    *(undefined1 *)((longlong)param_1 + 0xaf6) = 1;
    ExReleasePushLockExclusiveEx(param_1 + 0x15f,0);
    if (*(char *)((longlong)param_1 + 0x6c1) == '\0') {
      param_3 = (undefined *)0x0;
      KeQueryNodeActiveAffinity((undefined2)local_58,local_50);
      if (local_50[0] != 0) {
        KeSetSystemGroupAffinityThread(local_50,local_50 + 2);
      }
      uVar4 = InOpenChannel(param_1);
      uVar10 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_14001d251;
        uVar5 = 0x56;
        goto LAB_14001cff3;
      }
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      param_3 = &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids;
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x57,
               &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
    }
    if ((char)param_1[0xfd] == '\0') {
      uVar9 = (*(code *)param_1[0xff])(param_1);
    }
    else {
      uVar9 = (*(code *)param_1[0x100])(param_1,param_1[0xff]);
    }
    uVar10 = (ulonglong)uVar9;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x58,param_3,param_1,(char)uVar9);
    }
    if ((int)uVar9 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_14001d251;
      uVar5 = 0x59;
      goto LAB_14001cff3;
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5a,param_3,param_1,(char)uVar9);
    }
    *(undefined4 *)(param_1 + 0x113) = 4;
    LOCK();
    plVar1 = param_1 + 0x19c;
    lVar7 = *plVar1;
    *(int *)plVar1 = (int)*plVar1 + 1;
    UNLOCK();
    uVar9 = (int)lVar7 + 1;
    uVar10 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar10 == 0) {
      iVar3 = (int)((ulonglong)((longlong)(int)uVar9 * -0x2aaaaaab) >> 0x20);
      iVar3 = ((iVar3 >> 2) - (iVar3 >> 0x1f)) * 0x18;
    }
    else {
      iVar3 = (uVar9 / 0x18) * -0x18;
    }
    lVar7 = (longlong)(int)(uVar9 + iVar3);
    *(char *)((longlong)param_1 + lVar7 * 6 + 0xce4) = (char)param_1[0x113];
    *(undefined1 *)((longlong)param_1 + lVar7 * 6 + 0xce5) =
         *(undefined1 *)((longlong)param_1 + 0x89c);
    *(short *)((longlong)param_1 + lVar7 * 6 + 0xce6) = (short)param_1[0x115];
    *(undefined2 *)((longlong)param_1 + lVar7 * 6 + 0xce8) = 0xc4a;
    *(byte *)(param_1 + 0x125) = *(byte *)(param_1 + 0x125) | 0x10;
    uVar10 = 0;
  }
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5b,
             &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
  }
  (*(code *)param_1[0x12d])(param_1[0x128],uVar10);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    param_3 = &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids;
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5c,
             &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
  }
LAB_14001d2d7:
  KeRevertToUserGroupAffinityThread(local_50 + 2);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x5d,param_3,param_1,(char)uVar10);
  }
  return uVar10;
}



===== VmbChannelPause @ 14001d350 =====

void VmbChannelPause(longlong param_1,undefined8 param_2,undefined8 param_3)

{
                    /* 0x1d350  52  VmbChannelPause */
  KmclpPauseChannel(param_1,'\x01',param_3);
  return;
}



===== VmbChannelPurge @ 14001d370 =====

void VmbChannelPurge(longlong param_1,undefined8 param_2,longlong param_3)

{
  int *piVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  
                    /* 0x1d370  54  VmbChannelPurge */
  KmclLockChannel(param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1,
               (char)*(undefined4 *)(param_1 + 0x898),(char)*(undefined4 *)(param_1 + 0x89c));
  }
  *(byte *)(param_1 + 0x928) = *(byte *)(param_1 + 0x928) & 0xfb;
  iVar2 = *(int *)(param_1 + 0x898);
  if (((iVar2 == 0) || (iVar2 == 1)) || ((iVar2 == 3 || (iVar2 == 0xc)))) {
    KmclUnlockChannel(param_1);
  }
  else {
    if (*(int *)(param_1 + 0x89c) != 4) {
      *(undefined4 *)(param_1 + 0x89c) = 3;
      LOCK();
      piVar1 = (int *)(param_1 + 0xce0);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      uVar4 = iVar2 + 1;
      uVar3 = Feature_3130672440__private_IsEnabledDeviceUsageNoInline();
      if ((int)uVar3 == 0) {
        iVar2 = (int)((ulonglong)((longlong)(int)uVar4 * -0x2aaaaaab) >> 0x20);
        iVar2 = ((iVar2 >> 2) - (iVar2 >> 0x1f)) * 0x18;
      }
      else {
        iVar2 = (uVar4 / 0x18) * -0x18;
      }
      param_3 = (longlong)(int)(uVar4 + iVar2);
      *(undefined1 *)(param_1 + 0xce4 + param_3 * 6) = *(undefined1 *)(param_1 + 0x898);
      *(undefined1 *)(param_1 + 0xce5 + param_3 * 6) = *(undefined1 *)(param_1 + 0x89c);
      *(short *)(param_1 + 0xce6 + param_3 * 6) = (short)*(undefined4 *)(param_1 + 0x8a8);
      *(undefined2 *)(param_1 + 0xce8 + param_3 * 6) = 0x2d3;
    }
    KmclpRundownChannelStateAndUnlock(param_1,'\x01',param_3);
  }
  return;
}



===== VmbChannelStart @ 14001d4b0 =====

void VmbChannelStart(longlong *param_1,undefined8 param_2,longlong *param_3)

{
  byte bVar1;
  
                    /* 0x1d4b0  66  VmbChannelStart */
  KmclLockChannel((longlong)param_1);
  if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
      ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    WPP_SF_qL_guid__guid_
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(longlong)param_1 + 0x6dc,param_3,param_1,
               (char)param_1[0x113],(longlong)param_1 + 0x6dc,(longlong)param_1 + 0x6ec);
  }
  bVar1 = *(byte *)(param_1 + 0x125);
  if ((bVar1 & 6) == 0) {
    KmclpStartChannelAndUnlock(param_1,(ulonglong)bVar1,param_3);
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
               &WPP_fa014546bb113ca58de70d4b381949e7_Traceguids,param_1);
    }
  }
  else {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qLdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)(bVar1 >> 1 & 1),param_3,
                  param_1,(char)param_1[0x113],bVar1 >> 1 & 1,bVar1 >> 2 & 1);
    }
    KmclUnlockChannel((longlong)param_1);
  }
  return;
}



===== VmbChannelGetStatistics @ 14001d5c0 =====

void VmbChannelGetStatistics(longlong param_1,ulonglong *param_2)

{
                    /* 0x1d5c0  24  VmbChannelGetStatistics */
  *param_2 = (ulonglong)*(uint *)(param_1 + 0x1c8);
  param_2[1] = (ulonglong)*(uint *)(param_1 + 0x530);
  param_2[2] = *(ulonglong *)(param_1 + 0x680);
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = *(ulonglong *)(param_1 + 0x4a8);
  param_2[6] = *(ulonglong *)(param_1 + 0x4a0);
  param_2[7] = *(ulonglong *)(param_1 + 0x1d8);
  param_2[8] = *(ulonglong *)(param_1 + 0x1e0);
  param_2[9] = *(ulonglong *)(param_1 + 0x1e8);
  param_2[10] = *(ulonglong *)(param_1 + 0x540);
  param_2[0xb] = *(ulonglong *)(param_1 + 0x548);
  param_2[0xc] = *(ulonglong *)(param_1 + 0x688);
  param_2[0xd] = *(ulonglong *)(param_1 + 0x538);
  param_2[0xe] = (ulonglong)(uint)(*(int *)(param_1 + 0x520) - *(int *)(param_1 + 0x478));
  param_2[0xf] = 0;
  param_2[0x10] = 0;
  param_2[0x11] = 0;
  param_2[0x12] = 0;
  param_2[0x13] = 0;
  param_2[0x14] = 0;
  param_2[0x15] = 0;
  *(undefined4 *)(param_2 + 0x16) = 0;
  param_2[0x17] = 0;
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x1cc);
  *(undefined8 *)((longlong)param_2 + 0xc4) = 0;
  *(undefined4 *)((longlong)param_2 + 0xcc) = 0;
  memset(param_2 + 0x1a,0,0x60);
  return;
}



===== WppCleanupKm @ 14001d6c4 =====

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



===== WppInitKm @ 14001d744 =====

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



===== WppLoadTracingSupport @ 14001d7d4 =====

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



===== WppTraceCallback @ 14001d920 =====

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



===== wil_UninitializeFeatureStaging @ 14001dba8 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 14001dc00 =====

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
      goto LAB_14001dc5d;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_14001dc5d;
    }
  }
  uVar1 = 0x206;
LAB_14001dc5d:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 14001dc68 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 14001dd20 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 14001dd58 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_14001ddda;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_14001ddda;
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
LAB_14001ddda:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 14001de30 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 14001de90 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14001deac =====

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



===== KmclpCreateInstanceName @ 14001df60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int KmclpCreateInstanceName(longlong param_1,ushort *param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined2 local_res8 [4];
  ushort local_38;
  short local_36;
  undefined4 local_34;
  longlong local_30;
  undefined8 local_28;
  longlong lStack_20;
  
  local_34 = 0;
  local_res8[0] = 0;
  local_28 = 0;
  lStack_20 = 0;
  KmclpGetInstanceNameLength(param_1);
  if (*(char *)(param_1 + 0x6c0) != '\0') {
    param_4 = 0;
    (**(code **)(param_1 + 0xa10))(*(undefined8 *)(param_1 + 0x940),param_2,local_res8);
    RtlAppendUnicodeToString(param_2,L":");
  }
  if (*(longlong *)(param_1 + 0x890) != 0) {
    RtlAppendUnicodeStringToString(param_2,param_1 + 0x888);
    RtlAppendUnicodeToString(param_2,L"-");
  }
  iVar1 = RtlStringFromGUID(param_1 + 0xac0,&local_28);
  if (-1 < iVar1) {
    RtlAppendUnicodeStringToString(param_2,&local_28);
    if (*(ushort *)(param_1 + 0xcd0) != 0) {
      local_38 = 0;
      local_30 = *(longlong *)(param_2 + 4) + (ulonglong)(*param_2 >> 1) * 2;
      local_36 = param_2[1] - *param_2;
      RtlUnicodeStringPrintf(&local_38,L"-%04x",(ulonglong)*(ushort *)(param_1 + 0xcd0),param_4);
      *param_2 = *param_2 + local_38;
    }
    iVar1 = 0;
  }
  if (lStack_20 != 0) {
    ExFreePoolWithTag(lStack_20,0x636d6b56);
  }
  return iVar1;
}



===== KmclpStatsCallback @ 14001e0c0 =====

int KmclpStatsCallback(int param_1,uint *param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = (int)param_3;
  if (param_1 == 0) {
    if (iVar1 == 1) {
      KmclPerformanceCounterTimingCounters =
           KmclPerformanceCounterTimingCounters | (ulonglong)(*param_2 & 0x200000) | 0xfc00000;
    }
  }
  else {
    if (param_1 != 1) {
      if ((param_1 == 2) || (param_1 == 3)) {
        iVar1 = KmclpStatsRequest(iVar1,param_2[4],*(ulonglong *)(param_2 + 6),param_3);
        return iVar1;
      }
      return -0x3fffffff;
    }
    if (iVar1 == 1) {
      KmclPerformanceCounterTimingCounters =
           KmclPerformanceCounterTimingCounters & ~((ulonglong)(*param_2 & 0x200000) | 0xfc00000);
    }
  }
  return 0;
}



===== KmclpStatsRequest @ 14001e13c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int KmclpStatsRequest(int param_1,int param_2,ulonglong param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined1 auStack_118 [32];
  undefined8 **local_f8;
  undefined8 local_e8;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined8 local_d8;
  undefined4 local_d0;
  undefined8 *local_c8;
  undefined4 local_c0;
  undefined8 *local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 *local_90;
  undefined8 *local_88;
  undefined4 local_80;
  undefined8 *local_78;
  undefined4 local_70;
  undefined8 *local_68;
  undefined4 local_60;
  undefined8 *local_58;
  undefined4 local_50;
  undefined8 *local_48;
  undefined4 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_118;
  iVar2 = 0;
  uVar5 = param_3;
  ExAcquireFastMutex(&KmclChannelListLock);
  puVar6 = KmclChannelList;
  do {
    if ((undefined8 **)puVar6 == &KmclChannelList) {
LAB_14001e427:
      ExReleaseFastMutex(&KmclChannelListLock);
      return iVar2;
    }
    puVar1 = (undefined8 *)*puVar6;
    ExAcquireFastMutex(&KmclPerformanceCounterLock);
    if ((((0xfffffffd < param_2 - 1U) || (param_2 == *(int *)(puVar6 + 4))) && (puVar6[0x1d] != 0))
       && (puVar6[3] != 0)) {
      if (*(ushort *)(puVar6 + 2) == 0) {
        KmclpCreateInstanceName((longlong)(puVar6 + -0x10c),(ushort *)(puVar6 + 2),uVar5,param_4);
      }
      if (param_1 == 1) {
        local_88 = puVar6 + -0x3c;
        param_4 = 5;
        local_78 = puVar6 + -0xd3;
        local_68 = puVar6 + -0x66;
        local_58 = puVar6 + -0x79;
        local_48 = puVar6 + -0x35;
        puVar6[-0x62] = puVar6[-0x5f] - puVar6[-0x7a];
        local_f8 = &local_88;
        local_80 = 0x18;
        local_70 = 0xc0;
        local_60 = 0x38;
        local_50 = 0x18;
        local_40 = 0x110;
LAB_14001e3e4:
        uVar5 = (ulonglong)*(uint *)(puVar6 + 4);
        iVar2 = PcwAddInstance(param_3);
      }
      else if (param_1 == 2) {
        if (*(char *)(puVar6 + -0x2c) != '\0') {
          local_c8 = puVar6 + -0x39;
          local_c0 = 0x20;
          param_4 = 1;
          local_f8 = &local_c8;
          goto LAB_14001e3e4;
        }
      }
      else if (param_1 == 3) {
        local_a8 = 0;
        local_90 = (undefined8 *)0x0;
        local_b8 = (undefined8 *)0x0;
        uStack_b0 = 0;
        local_a0 = 0;
        uStack_98 = 0;
        ExAcquirePushLockSharedEx(puVar6 + 0x53,0);
        if (*(char *)((longlong)puVar6 + 0x296) != '\0') {
          puVar4 = (undefined4 *)puVar6[0x46];
          if (*(char *)(puVar6 + -0x34) == '\0') {
            puVar3 = (undefined4 *)
                     ((ulonglong)(uint)(*(int *)((longlong)puVar6 + 0x23c) << 0xc) +
                     (longlong)puVar4);
          }
          else {
            puVar3 = puVar4;
            puVar4 = (undefined4 *)
                     ((ulonglong)(uint)(*(int *)(puVar6 + 0x47) << 0xc) + (longlong)puVar4);
          }
          local_e8 = (undefined8 **)CONCAT44(*puVar3,*(int *)(puVar6 + 0x47) << 0xc);
          uStack_b0 = *(undefined8 *)(puVar3 + 1);
          local_d8 = (undefined8 *)CONCAT44(puVar3[0x10],puVar3[3]);
          iVar2 = *(int *)((longlong)puVar6 + 0x23c) << 0xc;
          local_b8 = local_e8;
          local_a8 = local_d8;
          local_e8 = (undefined8 **)CONCAT44(*puVar4,iVar2);
          uStack_e0 = puVar4[1];
          uStack_dc = puVar4[2];
          uStack_98 = *(undefined8 *)(puVar4 + 1);
          local_d8 = (undefined8 *)CONCAT44(puVar4[0x10],puVar4[3]);
          local_a0 = CONCAT44(*puVar4,iVar2);
          local_90 = local_d8;
        }
        ExReleasePushLockSharedEx(puVar6 + 0x53,0);
        local_e8 = &local_b8;
        local_d8 = &local_a0;
        local_f8 = (undefined8 **)&local_e8;
        uStack_e0 = 0x18;
        local_d0 = 0x18;
        param_4 = 2;
        goto LAB_14001e3e4;
      }
      if (iVar2 < 0) {
        iVar2 = -0x3fffffff;
        goto LAB_14001e427;
      }
    }
    ExReleaseFastMutex(&KmclPerformanceCounterLock);
    puVar6 = puVar1;
  } while( true );
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 14001e470 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(longlong param_1)

{
  longlong *plVar1;
  undefined2 uVar2;
  longlong lVar3;
  undefined2 *puVar4;
  code *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  ulonglong local_18;
  
  puVar7 = auStack_48;
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  lVar3 = *(longlong *)(param_1 + 8);
  plVar1 = (longlong *)(param_1 + 0x20);
  local_28 = *(undefined4 *)(lVar3 + -0x10);
  uStack_24 = *(undefined4 *)(lVar3 + -0xc);
  uStack_20 = *(undefined4 *)(lVar3 + -8);
  uStack_1c = *(undefined4 *)(lVar3 + -4);
  if (*plVar1 != 0) {
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)(5);
    puVar7 = auStack_40;
  }
  *(undefined8 *)(param_1 + 0x28) = 0;
  *(undefined8 *)(param_1 + 0x30) = 0;
  *(undefined8 *)(puVar7 + -8) = 0x14001e4d3;
  iVar6 = EtwRegister(puVar7 + 0x20,_tlgEnableCallback,param_1,plVar1);
  if (iVar6 == 0) {
    puVar4 = *(undefined2 **)(param_1 + 8);
    lVar3 = *plVar1;
    uVar2 = *puVar4;
    *(undefined8 *)(puVar7 + -8) = 0x14001e4f3;
    EtwSetInformation(lVar3,2,puVar4,uVar2);
  }
  *(undefined8 *)(puVar7 + -8) = 0x14001e507;
  return iVar6;
}



===== _tlgEnableCallback @ 14001e520 =====

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



===== entry @ 140020010 =====

void entry(void)

{
  __security_init_cookie();
  DriverEntry();
  return;
}



===== __security_init_cookie @ 140020044 =====

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



===== DllInitialize @ 140020080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DllInitialize(ushort *param_1)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined1 auStack_168 [32];
  undefined8 local_148 [2];
  undefined4 local_138;
  uint local_134;
  uint local_130;
  ulonglong local_18;
  
                    /* 0x20080  1  DllInitialize */
  local_18 = __security_cookie ^ (ulonglong)auStack_168;
  wil_InitializeFeatureStaging();
  _WPP_MAIN_CB = 0;
  DAT_1400162e8 = &WPP_ThisDir_CTLGUID_VMBKmclDriverTraceGuid;
  DAT_1400162f0 = 0;
  _DAT_140016300 = 0;
  _DAT_140016308 = 1;
  WppLoadTracingSupport();
  _DAT_140016300 = 0;
  WppInitKm();
  memset(&local_134,0,0x110);
  local_138 = 0x114;
  iVar1 = RtlGetVersion(&local_138);
  if ((-1 < iVar1) && ((6 < local_134 || ((local_134 == 6 && (1 < local_130)))))) {
    ExDefaultNonPagedPoolType = 0x200;
    ExDefaultMdlProtection = 0x40000000;
  }
  _KmclChannelListLock = 1;
  _DAT_1400162a8 = 0;
  _DAT_1400162b0 = 0;
  KeInitializeEvent(&DAT_1400162b8,1,0);
  _KmclProfilerListLock = 1;
  DAT_140016288 = &KmclChannelList;
  KmclChannelList = &KmclChannelList;
  _DAT_140016248 = 0;
  _DAT_140016250 = 0;
  KeInitializeEvent(&DAT_140016258,1,0);
  local_148[0] = 0;
  DAT_140016228 = &KmclProfilerList;
  KmclProfilerList = &KmclProfilerList;
  _KmclPerformanceCounterLock = 1;
  _DAT_1400161e8 = 0;
  _DAT_1400161f0 = 0;
  KeInitializeEvent(&DAT_1400161f8,1,0);
  KeQueryPerformanceCounter(local_148);
  KmclPerformanceCounterFrequency = local_148[0];
  InitializeTelemetryAssertsKM(param_1);
  if (KmclTscTicksPerNtTick == 0) {
    uVar2 = KeQueryTimeIncrement();
    uVar3 = KmclCalibrateTsc();
    KmclTscTicksPerNtTick = uVar3 / (10000000 / (ulonglong)uVar2);
  }
  KeInitializeEvent(&KmclDirectInterfaceReady,0,0);
  McGenEventRegister_EtwRegister();
  return 0;
}



===== DriverEntry @ 140020294 =====

undefined8 DriverEntry(void)

{
  return 0xc0000001;
}



===== wil_InitializeFeatureStaging @ 1400202a4 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 140020394 =====

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


