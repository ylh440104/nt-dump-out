
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
  *param_6 = PTR_DAT_14000b0a0;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_14000b0a0;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_14000b0b8,&local_18,0,0,param_5,param_6);
  return;
}



===== _tlgKeywordOn @ 1400010b8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong _tlgKeywordOn(void)

{
  ulonglong in_RAX;
  
  if (((_DAT_14000b0a8 & 0x400000000000) == 0) ||
     (in_RAX = DAT_14000b0b0 & 0x400000000000, in_RAX != DAT_14000b0b0)) {
    return in_RAX & 0xffffffffffffff00;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== MupFindMatchingChar @ 1400010f0 =====

short * MupFindMatchingChar(short *param_1,undefined8 param_2,longlong param_3)

{
  if (param_3 != 0) {
    for (; (param_3 != 0 && (*param_1 != 0)); param_1 = param_1 + 1) {
      if (*param_1 == 0x5c) {
        return param_1;
      }
      param_3 = param_3 + -1;
    }
  }
  return (short *)0x0;
}



===== MupCreateIrpContext @ 140001130 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
MupCreateIrpContext(longlong param_1,longlong param_2,longlong param_3,char param_4,
                   undefined8 *param_5)

{
  int iVar1;
  undefined8 *puVar2;
  bool bVar3;
  ushort uVar4;
  ushort uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined8 *puVar9;
  bool bVar10;
  undefined4 local_48;
  
  puVar9 = (undefined8 *)0x0;
  bVar3 = false;
  local_48 = 0;
  if ((*(uint *)(param_1 + 0xf0) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x103,4,param_3,*(undefined8 *)(param_1 + 0x90),param_1);
  }
  uVar8 = *(int *)(param_1 + 0xd8) + 0x88;
  uVar5 = 0xffff;
  if (uVar8 < 0x119) {
    uVar5 = KeGetCurrentNodeNumber();
    puVar6 = (undefined8 *)
             ExAllocateFromNPagedLookasideList
                       ((ulonglong)uVar5 * 0x80 + MupiIrpContextLookasideLists);
    if (puVar6 == (undefined8 *)0x0) goto LAB_140001357;
    uVar4 = uVar5;
    bVar10 = true;
LAB_1400011e7:
    bVar3 = bVar10;
    uVar5 = uVar4;
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6[3] = 0;
    puVar6[4] = 0;
    puVar6[5] = 0;
    puVar6[6] = 0;
    puVar6[7] = 0;
    puVar6[8] = 0;
    puVar6[9] = 0;
    puVar6[10] = 0;
    puVar6[0xb] = 0;
    puVar6[0xc] = 0;
    puVar6[0xd] = 0;
    puVar6[0xe] = 0;
    puVar6[0xf] = 0;
    puVar6[0x10] = 0;
  }
  else {
    puVar6 = (undefined8 *)ExAllocatePool2(0x42,uVar8,0x6349754d);
    uVar4 = 0xffff;
    bVar10 = false;
    if (puVar6 != (undefined8 *)0x0) goto LAB_1400011e7;
LAB_140001357:
    if (param_4 != '\0') {
      LOCK();
      iVar1 = MupReserveIrpContext + -1;
      UNLOCK();
      bVar10 = MupReserveIrpContext != 1;
      MupReserveIrpContext = iVar1;
      if (bVar10) {
        KeWaitForSingleObject(&DAT_14000bba8,0,0,0,0);
      }
      puVar6 = (undefined8 *)&DAT_14000bbc8;
      _DAT_14000bbc0 = SystemReserved1[0xf];
      memset(&DAT_14000bbc8,0,0x88);
      _DAT_14000bbd0 = 2;
    }
    if (puVar6 == (undefined8 *)0x0) {
      local_48 = 0xc000009a;
      goto LAB_1400012bb;
    }
  }
  *(undefined2 *)puVar6 = 0x710a;
  *(short *)((longlong)puVar6 + 2) = (short)uVar8;
  *(undefined4 *)((longlong)puVar6 + 4) = 1;
  if (bVar3) {
    *(ushort *)((longlong)puVar6 + 0x66) = uVar5 + 1;
  }
  puVar9 = puVar6 + 9;
  puVar6[10] = puVar9;
  *puVar9 = puVar9;
  puVar6[5] = param_1;
  puVar6[6] = param_2;
  if (param_2 != 0) {
    MupReferenceContainerContext();
    uVar7 = PsGetCurrentServerSilo();
    puVar6[7] = uVar7;
  }
  puVar6[2] = param_3;
  *(undefined4 *)(puVar6 + 3) = 0;
  *(undefined4 *)(puVar6 + 4) = 0xc0000001;
  *(undefined4 *)((longlong)puVar6 + 0x1c) = 0xc0000016;
  *(undefined4 *)((longlong)puVar6 + 0x24) = 0xc0000016;
  puVar6[8] = 0;
  *(undefined2 *)((longlong)puVar6 + 100) = 0xffff;
  if ((**(char **)(param_3 + 0xb8) == '\0') &&
     (iVar1 = *(int *)(*(char **)(param_3 + 0xb8) + 0x20), *(int *)(puVar6 + 0xc) = iVar1,
     iVar1 != 0)) {
    puVar6[0xb] = *(undefined8 *)(param_3 + 0x18);
  }
  puVar9 = puVar6 + 0x11;
  for (puVar2 = *(undefined8 **)(param_1 + 200); puVar2 != (undefined8 *)(param_1 + 200);
      puVar2 = (undefined8 *)*puVar2) {
    MupInitSurrogateIrpContext((longlong)(puVar2 + -1),(longlong)puVar6,(undefined4 *)puVar9);
    puVar9 = puVar9 + 0x12;
  }
  puVar9 = puVar6;
LAB_1400012bb:
  *param_5 = puVar9;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
               &WPP_4224fc6462d239efe09d540716e6c5d6_Traceguids,param_1,(char)puVar9,(char)local_48)
    ;
  }
  return local_48;
}



===== MupiCheckForProviderAvoidPath @ 140001420 =====

ulonglong MupiCheckForProviderAvoidPath(ushort *param_1,undefined8 *param_2,undefined1 *param_3)

{
  undefined *puVar1;
  ulonglong uVar2;
  short local_18 [8];
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  MupiGetPathComponents(param_1,(short *)0x0,local_18,(short *)0x0,(short *)0x0);
  puVar1 = (undefined *)RtlCompareUnicodeString(&MupiDavShareName,local_18,1);
  if ((int)puVar1 == 0) {
    if (param_2 != (undefined8 *)0x0) {
      puVar1 = &MupiDavAvoidProviderName;
      *param_2 = &MupiDavAvoidProviderName;
    }
    if (param_3 != (undefined1 *)0x0) {
      *param_3 = 0;
    }
    uVar2 = CONCAT71((int7)((ulonglong)puVar1 >> 8),1);
  }
  else {
    uVar2 = (ulonglong)puVar1 & 0xffffffffffffff00;
  }
  return uVar2;
}



===== MupiGetPathComponents @ 1400014a0 =====

void MupiGetPathComponents
               (ushort *param_1,short *param_2,short *param_3,short *param_4,short *param_5)

{
  longlong lVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  ulonglong uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  bVar7 = param_2 != (short *)0x0;
  bVar8 = param_3 != (short *)0x0;
  lVar1 = *(longlong *)(param_1 + 4);
  bVar9 = param_4 != (short *)0x0;
  bVar10 = param_5 != (short *)0x0;
  if ((lVar1 != 0) && (*param_1 != 0)) {
    uVar4 = *param_1 >> 1;
    uVar5 = 0;
    if (uVar4 != 0) {
      do {
        if ((*(short *)(lVar1 + (ulonglong)uVar5 * 2) != 0x5c) || (1 < uVar5)) break;
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar4);
    }
    uVar2 = uVar5;
    if (uVar5 < uVar4) {
      do {
        if (*(short *)(lVar1 + (ulonglong)uVar2 * 2) == 0x5c) break;
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar4);
    }
    if (uVar2 != uVar5) {
      if (param_2 != (short *)0x0) {
        *(ulonglong *)(param_2 + 4) = lVar1 + (ulonglong)uVar5 * 2;
        sVar3 = (uVar2 - uVar5) * 2;
        *param_2 = sVar3;
        param_2[1] = sVar3;
      }
      bVar7 = false;
      uVar2 = uVar2 + 1;
      uVar6 = (ulonglong)uVar2;
      if (uVar2 < *param_1 >> 1) {
        do {
          sVar3 = *(short *)(*(longlong *)(param_1 + 4) + uVar6 * 2);
          if ((sVar3 == 0x5c) || (sVar3 == 0x3a)) break;
          uVar4 = (short)uVar6 + 1;
          uVar6 = (ulonglong)uVar4;
        } while (uVar4 < *param_1 >> 1);
      }
      uVar4 = (ushort)uVar6;
      if (uVar2 < uVar4) {
        if (param_3 != (short *)0x0) {
          *(ulonglong *)(param_3 + 4) = *(longlong *)(param_1 + 4) + (ulonglong)uVar2 * 2;
          sVar3 = (uVar4 - uVar2) * 2;
          *param_3 = sVar3;
          param_3[1] = sVar3;
        }
        bVar8 = false;
        if (param_4 != (short *)0x0) {
          bVar9 = false;
          lVar1 = *(longlong *)(param_2 + 4);
          *(longlong *)(param_4 + 4) = lVar1;
          sVar3 = *param_2;
          *param_4 = sVar3;
          if (uVar5 != 0) {
            sVar3 = sVar3 + 2;
            *(longlong *)(param_4 + 4) = lVar1 + -2;
            *param_4 = sVar3;
          }
          if (*param_3 != 0) {
            *param_4 = sVar3 + 2;
            sVar3 = sVar3 + 2 + *param_3;
            *param_4 = sVar3;
          }
          param_4[1] = sVar3;
        }
        uVar5 = *param_1 >> 1;
        if ((uVar4 < uVar5) && (*(short *)(*(longlong *)(param_1 + 4) + uVar6 * 2) == 0x5c)) {
          uVar6 = (ulonglong)(ushort)(uVar4 + 1);
        }
        if ((param_5 != (short *)0x0) && ((ushort)uVar6 < uVar5)) {
          lVar1 = *(longlong *)(param_1 + 4);
          bVar10 = false;
          sVar3 = (uVar5 - (ushort)uVar6) * 2;
          *param_5 = sVar3;
          param_5[1] = sVar3;
          *(ulonglong *)(param_5 + 4) = lVar1 + uVar6 * 2;
        }
      }
    }
  }
  if (bVar7) {
    RtlInitUnicodeString(param_2,0);
  }
  if (bVar8) {
    RtlInitUnicodeString(param_3,0);
  }
  if (bVar9) {
    RtlInitUnicodeString(param_4,0);
  }
  if (bVar10) {
    RtlInitUnicodeString(param_5,0);
  }
  return;
}



===== RtlHashBytesEx @ 1400017b0 =====

longlong RtlHashBytesEx(byte *param_1,ulonglong param_2,longlong param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte bVar8;
  ulonglong uVar9;
  
  if (7 < (longlong)param_2) {
    uVar9 = param_2 >> 3;
    param_2 = param_2 + uVar9 * -8;
    do {
      bVar8 = *param_1;
      pbVar1 = param_1 + 1;
      pbVar2 = param_1 + 2;
      pbVar3 = param_1 + 3;
      pbVar4 = param_1 + 4;
      pbVar5 = param_1 + 5;
      pbVar6 = param_1 + 6;
      pbVar7 = param_1 + 7;
      param_1 = param_1 + 8;
      param_3 = (((((((param_3 * 0x25 + (ulonglong)bVar8) * 0x25 + (ulonglong)*pbVar1) * 0x25 +
                    (ulonglong)*pbVar2) * 0x25 + (ulonglong)*pbVar3) * 0x25 + (ulonglong)*pbVar4) *
                  0x25 + (ulonglong)*pbVar5) * 0x25 + (ulonglong)*pbVar6) * 0x25 +
                (ulonglong)*pbVar7;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
  }
  if (param_2 != 2) {
    switch(param_2) {
    case 1:
      goto switchD_140001884_caseD_1;
    default:
      return param_3;
    case 7:
      param_3 = param_3 * 0x25 + (ulonglong)*param_1;
      param_1 = param_1 + 1;
    case 6:
      param_3 = param_3 * 0x25 + (ulonglong)*param_1;
      param_1 = param_1 + 1;
    case 5:
      param_3 = param_3 * 0x25 + (ulonglong)*param_1;
      param_1 = param_1 + 1;
    case 4:
      param_3 = param_3 * 0x25 + (ulonglong)*param_1;
      param_1 = param_1 + 1;
    case 3:
      param_3 = param_3 * 0x25 + (ulonglong)*param_1;
      param_1 = param_1 + 1;
    }
  }
  param_3 = param_3 * 0x25 + (ulonglong)*param_1;
  param_1 = param_1 + 1;
switchD_140001884_caseD_1:
  return param_3 * 0x25 + (ulonglong)*param_1;
}



===== RtlHashBytesGeneric @ 1400018e0 =====

longlong RtlHashBytesGeneric(byte *param_1,ulonglong param_2,longlong param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte bVar8;
  ulonglong uVar9;
  
  if (7 < (longlong)param_2) {
    uVar9 = param_2 >> 3;
    param_2 = param_2 + uVar9 * -8;
    do {
      bVar8 = *param_1;
      pbVar1 = param_1 + 1;
      pbVar2 = param_1 + 2;
      pbVar3 = param_1 + 3;
      pbVar4 = param_1 + 4;
      pbVar5 = param_1 + 5;
      pbVar6 = param_1 + 6;
      pbVar7 = param_1 + 7;
      param_1 = param_1 + 8;
      param_3 = (((((((param_3 * 0x25 + (ulonglong)bVar8) * 0x25 + (ulonglong)*pbVar1) * 0x25 +
                    (ulonglong)*pbVar2) * 0x25 + (ulonglong)*pbVar3) * 0x25 + (ulonglong)*pbVar4) *
                  0x25 + (ulonglong)*pbVar5) * 0x25 + (ulonglong)*pbVar6) * 0x25 +
                (ulonglong)*pbVar7;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
  }
  if (param_2 != 2) {
    switch(param_2) {
    case 1:
      goto switchD_1400019b4_caseD_1;
    default:
      return param_3;
    case 7:
      param_3 = param_3 * 0x25 + (ulonglong)*param_1;
      param_1 = param_1 + 1;
    case 6:
      param_3 = param_3 * 0x25 + (ulonglong)*param_1;
      param_1 = param_1 + 1;
    case 5:
      param_3 = param_3 * 0x25 + (ulonglong)*param_1;
      param_1 = param_1 + 1;
    case 4:
      param_3 = param_3 * 0x25 + (ulonglong)*param_1;
      param_1 = param_1 + 1;
    case 3:
      param_3 = param_3 * 0x25 + (ulonglong)*param_1;
      param_1 = param_1 + 1;
    }
  }
  param_3 = param_3 * 0x25 + (ulonglong)*param_1;
  param_1 = param_1 + 1;
switchD_1400019b4_caseD_1:
  return param_3 * 0x25 + (ulonglong)*param_1;
}



===== MupReleaseIrpContext @ 140001a10 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MupReleaseIrpContext(longlong param_1)

{
  int *piVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_4224fc6462d239efe09d540716e6c5d6_Traceguids,param_1);
  }
  LOCK();
  piVar1 = (int *)(param_1 + 4);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_4224fc6462d239efe09d540716e6c5d6_Traceguids,param_1);
    }
    puVar4 = *(undefined8 **)(param_1 + 0x48);
    while (puVar4 != (undefined8 *)(param_1 + 0x48)) {
      puVar2 = puVar4 + -1;
      puVar4 = (undefined8 *)*puVar4;
      MupReleaseSurrogateIrpContext((longlong)puVar2);
    }
    if (*(longlong *)(param_1 + 0x30) != 0) {
      MupDereferenceContainerContext();
      *(undefined8 *)(param_1 + 0x30) = 0;
      *(undefined8 *)(param_1 + 0x38) = 0;
    }
    iVar3 = MupReserveIrpContext;
    if ((*(uint *)(param_1 + 8) & 2) == 0) {
      if (*(ushort *)(param_1 + 0x66) == 0) {
        ExFreePoolWithTag(param_1,0);
      }
      else {
        ExFreeToNPagedLookasideList
                  ((ulonglong)*(ushort *)(param_1 + 0x66) * 0x80 +
                   MupiIrpContextLookasideLists + -0x80,param_1);
      }
    }
    else {
      _DAT_14000bbc0 = 0;
      LOCK();
      MupReserveIrpContext = MupReserveIrpContext + 1;
      UNLOCK();
      if (MupReserveIrpContext == 0 || iVar3 < -1) {
        KeSetEvent(&DAT_14000bba8,1);
        return;
      }
    }
  }
  return;
}



===== MupiUncProviderCompletion @ 140001b90 =====

undefined8 MupiUncProviderCompletion(undefined8 param_1,longlong param_2,longlong param_3)

{
  byte *pbVar1;
  byte bVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2e,
              &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,param_2,
              (char)*(undefined4 *)(param_2 + 0x30));
  }
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  *(undefined4 *)(param_3 + 0x20) = *(undefined4 *)(param_2 + 0x30);
  if (*(char *)(param_2 + 0x41) != '\0') {
    bVar2 = KeGetCurrentIrql();
    if (1 < bVar2) {
      *(undefined8 *)(param_3 + 0x68) = 0;
      *(code **)(param_3 + 0x78) = MupStateMachineWorker;
      *(longlong *)(param_3 + 0x80) = param_3;
      ExQueueWorkItem((undefined8 *)(param_3 + 0x68),0);
      return 0xc0000016;
    }
    MupStateMachineWorker(param_3);
  }
  return 0xc0000016;
}



===== MupFindFileContext @ 140001c70 =====

longlong MupFindFileContext(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = FsRtlLookupPerFileObjectContext(param_1,MupDeviceObject,0);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    lVar1 = lVar1 + -8;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_4224fc6462d239efe09d540716e6c5d6_Traceguids,param_1,(char)lVar1);
  }
  return lVar1;
}



===== MupReleaseSurrogateFileContext @ 140001cf0 =====

void MupReleaseSurrogateFileContext(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x18);
  if (lVar2 != 0) {
    piVar1 = (int *)(*(longlong *)(param_1 + 0x20) + 0xd8);
    *piVar1 = *piVar1 + -0x90;
    MupReleaseSurrogateProvider(lVar2);
  }
  lVar2 = *(longlong *)(param_1 + 8);
  if ((*(longlong *)(lVar2 + 8) == param_1 + 8) &&
     (plVar3 = *(longlong **)(param_1 + 0x10), *plVar3 == param_1 + 8)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    ExFreePoolWithTag(param_1,0);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== MupGetRequiredHardeningCapabilitiesFromIrp @ 140001d60 =====

ulonglong MupGetRequiredHardeningCapabilitiesFromIrp(undefined8 param_1,uint *param_2)

{
  int iVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong local_res20;
  longlong local_18 [2];
  
  uVar4 = 0;
  local_res20 = 0;
  local_18[0] = 0;
  iVar1 = IoGetIrpExtraCreateParameter(param_1,&local_res20);
  if (iVar1 != 0) {
    return 0xc00000e5;
  }
  uVar5 = 0;
  if (local_res20 != 0) {
    uVar2 = FsRtlFindExtraCreateParameter(local_res20,&GUID_ECP_NETWORK_OPEN_CONTEXT,local_18,0);
    uVar5 = uVar2 & 0xffffffff;
    if ((int)uVar2 == -0x3ffffddb) {
      *param_2 = 0;
      return 0;
    }
    if ((int)uVar2 != 0) {
      return uVar2;
    }
  }
  if (local_18[0] != 0) {
    if (*(int *)(local_18[0] + 8) == 3) {
      uVar4 = 6;
    }
    else if ((*(int *)(local_18[0] + 8) - 2U & 0xfffffffd) == 0) {
      uVar4 = 2;
    }
    uVar3 = uVar4 | 1;
    if ((*(uint *)(local_18[0] + 0xc) & 8) == 0) {
      uVar3 = uVar4;
    }
    *param_2 = uVar3;
  }
  return uVar5;
}



===== MupGetUncProviderDeviceObjectFromFileObject @ 140001e20 =====

undefined8 MupGetUncProviderDeviceObjectFromFileObject(undefined8 param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = FsRtlLookupPerFileObjectContext(param_1,MupDeviceObject,0);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    lVar1 = lVar1 + -8;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
              &WPP_4224fc6462d239efe09d540716e6c5d6_Traceguids,param_1,(char)lVar1);
  }
  if ((lVar1 == 0) || (*(longlong *)(lVar1 + 0xa8) == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined8 *)(*(longlong *)(lVar1 + 0xa8) + 0xa8);
  }
  return uVar2;
}



===== RfsUtilFilterEa @ 140001ebc =====

undefined1 RfsUtilFilterEa(uint *param_1,int *param_2,void *param_3,uint param_4)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  uint *_Dst;
  int iVar4;
  int iVar5;
  uint *puVar6;
  
  iVar5 = *param_2;
  iVar4 = 0;
  puVar6 = (uint *)0x0;
  if (iVar5 == 0) {
    uVar2 = 0;
  }
  else {
    while ((_Dst = param_1, *(byte *)((longlong)_Dst + 5) != param_4 ||
           (iVar3 = memcmp(_Dst + 2,param_3,(ulonglong)param_4), iVar3 != 0))) {
      uVar1 = *_Dst;
      if (uVar1 == 0) {
        return 0;
      }
      iVar4 = iVar4 + uVar1;
      param_1 = (uint *)((longlong)_Dst + (ulonglong)uVar1);
      puVar6 = _Dst;
    }
    uVar2 = 1;
    if (*_Dst == 0) {
      *param_2 = iVar4;
      if (puVar6 != (uint *)0x0) {
        *puVar6 = 0;
      }
    }
    else {
      iVar5 = iVar5 - *_Dst;
      *param_2 = iVar5;
      memmove(_Dst,(void *)((ulonglong)*_Dst + (longlong)_Dst),(ulonglong)(uint)(iVar5 - iVar4));
    }
  }
  return uVar2;
}



===== MupiQueryPathCompletionRoutine @ 140001f80 =====

undefined8 MupiQueryPathCompletionRoutine(undefined8 param_1,longlong param_2,longlong param_3)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
              &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,param_2,(char)param_3);
  }
  if ((-1 < *(int *)(param_2 + 0x30)) && (*(int *)(param_3 + 0x50) == 0)) {
    *(undefined4 *)(param_2 + 0x30) = 0xc0000001;
  }
  if (*(char *)(param_2 + 0x41) != '\0') {
    KeSetEvent(param_3 + 0x38,0,0);
  }
  return 0xc0000016;
}



===== MupGetUncCacheHostPrefixTable @ 140002014 =====

undefined * MupGetUncCacheHostPrefixTable(void)

{
  return &DAT_14000ba08;
}



===== MupiUpdateMupDeviceOpenCount @ 140002024 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MupiUpdateMupDeviceOpenCount(char param_1)

{
  KeAcquireGuardedMutex(&MupiMupDeviceOpenCountMutex);
  if (param_1 == '\0') {
    _MupiMupDeviceOpenCount = _MupiMupDeviceOpenCount + -1;
    if (_MupiMupDeviceOpenCount == 0) {
      FsRtlTeardownPerStreamContexts(&g_MupAdvancedFcbHeader);
    }
  }
  else {
    _MupiMupDeviceOpenCount = _MupiMupDeviceOpenCount + 1;
  }
  KeReleaseGuardedMutex(&MupiMupDeviceOpenCountMutex);
  return;
}



===== WPP_SF_qD @ 14000208c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,4,0);
  return;
}



===== MupWriteTelemetryKnownRemoteMailslotFailed @ 1400020e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void MupWriteTelemetryKnownRemoteMailslotFailed
               (ushort *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined1 auStackY_88 [32];
  undefined8 local_58 [4];
  uint *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  uint local_20 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  if (5 < DAT_14000b098) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_2c = 0;
      local_38 = local_20;
      local_20[1] = 0;
      local_28 = *(undefined8 *)(param_1 + 4);
      local_20[0] = (uint)*param_1;
      local_30 = 2;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140008fee,param_3,param_4,4,local_58);
    }
  }
  return;
}



===== WPP_SF_qq @ 140002170 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,0);
  return;
}



===== WPP_SF_q @ 1400021c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,0);
  return;
}



===== McGenEventUnregister_EtwUnregister @ 140002204 =====

undefined8 McGenEventUnregister_EtwUnregister(void)

{
  undefined8 uVar1;
  
  if (REMOTEFS_MUP_Context == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = EtwUnregister();
    REMOTEFS_MUP_Context = 0;
  }
  return uVar1;
}



===== MupUnregisterTelemetryProvider @ 140002238 =====

void MupUnregisterTelemetryProvider(void)

{
  undefined8 uVar1;
  
  uVar1 = DAT_14000b0b8;
  DAT_14000b0b8 = 0;
  DAT_14000b098 = 0;
  EtwUnregister(uVar1);
  return;
}



===== McGenEventRegister_EtwRegister @ 14000226c =====

void McGenEventRegister_EtwRegister(void)

{
  if (REMOTEFS_MUP_Context == 0) {
    EtwRegister(&REMOTEFS_MUP,McGenControlCallbackV2,&REMOTEFS_MUP_Context,&REMOTEFS_MUP_Context);
  }
  return;
}



===== MupRegisterTelemetryProvider @ 1400022ac =====

void MupRegisterTelemetryProvider(void)

{
  TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
  return;
}



===== __report_gsfailure @ 1400022d0 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 1400022dd =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0001400022dd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== MupRegisterFileSystemFilterCallbacks @ 1400022f0 =====

void MupRegisterFileSystemFilterCallbacks(undefined8 param_1)

{
  undefined4 local_88 [2];
  code *local_80;
  code *local_78;
  code *local_70;
  code *local_60;
  code *local_50;
  code *local_40;
  code *local_30;
  
  memset(local_88,0,0x78);
  local_88[0] = 0x78;
  local_80 = MupPreAcquireForSectionSynchronisation;
  local_78 = MupPostAcquireForSectionSynchronisation;
  local_70 = MupPreReleaseForSectionSynchronisation;
  local_60 = MupPreAcquireForCcFlush;
  local_50 = MupPreReleaseForCcFlush;
  local_40 = MupPreAcquireForCcFlush;
  local_30 = MupPreAcquireForCcFlush;
  FsRtlRegisterFileSystemFilterCallbacks(param_1,local_88);
  return;
}



===== WPP_SF_qZ @ 14000238c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZ(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              wchar_t *param_5)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1400023c5;
    }
  }
  pwVar1 = L"NULL";
LAB_1400023c5:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4224fc6462d239efe09d540716e6c5d6_Traceguids,0xf,&local_res20,8,
             param_5,2,pwVar1,wVar2,0);
  return;
}



===== WPP_SF_qqD @ 140002434 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqD(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,&local_res20,8,&param_5,8,&param_6,4,0);
  return;
}



===== Feature_28513592__private_IsEnabledDeviceUsageNoInline @ 140002494 =====

ulonglong Feature_28513592__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_28513592__private_featureState;
  if ((Feature_28513592__private_featureState & 0x10) == 0) {
    uVar1 = Feature_28513592__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_28513592__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_28513592__private_IsEnabledFallback @ 1400024cc =====

void Feature_28513592__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&wil_details_featureDescriptors_a);
  return;
}



===== WPP_SF_ @ 1400024e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_(undefined8 param_1,undefined2 param_2,undefined8 param_3)

{
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,0);
  return;
}



===== WPP_SF_D @ 140002514 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_D(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_DDqZ @ 140002558 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_DDqZ(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                undefined1 param_5,undefined1 param_6,wchar_t *param_7)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  undefined4 local_res20 [2];
  
  if (param_7 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_7;
    if (*param_7 != L'\0') {
      pwVar1 = *(wchar_t **)(param_7 + 4);
      goto LAB_140002594;
    }
  }
  pwVar1 = L"NULL";
LAB_140002594:
  pwVar2 = param_7;
  if (param_7 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,0x16,local_res20,4,
             &param_5,4,&param_6,8,pwVar2,2,pwVar1,wVar3,0);
  return;
}



===== WPP_SF_Z @ 14000262c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Z(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_4;
    if (*param_4 != L'\0') {
      pwVar1 = *(wchar_t **)(param_4 + 4);
      goto LAB_140002659;
    }
  }
  pwVar1 = L"NULL";
LAB_140002659:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,2,pwVar1,wVar2,0);
  return;
}



===== WPP_SF_Zdd @ 1400026ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Zdd(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_4;
    if (*param_4 != L'\0') {
      pwVar1 = *(wchar_t **)(param_4 + 4);
      goto LAB_1400026d9;
    }
  }
  pwVar1 = L"NULL";
LAB_1400026d9:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,2,pwVar1,wVar2,&param_5,4,&param_6,4,0)
  ;
  return;
}



===== WPP_SF_ZqD @ 140002758 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZqD(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_4;
    if (*param_4 != L'\0') {
      pwVar1 = *(wchar_t **)(param_4 + 4);
      goto LAB_140002786;
    }
  }
  pwVar1 = L"NULL";
LAB_140002786:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,2,pwVar1,wVar2,&param_5,8,&param_6,4,0)
  ;
  return;
}



===== WPP_SF_ZqZD @ 140002800 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZqZD(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
                undefined1 param_5,wchar_t *param_6,undefined1 param_7)

{
  wchar_t wVar1;
  wchar_t *pwVar2;
  wchar_t wVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  
  pwVar4 = L"NULL";
  if (param_6 == (wchar_t *)0x0) {
    wVar3 = L'\b';
  }
  else {
    wVar3 = *param_6;
    if (*param_6 != L'\0') {
      pwVar5 = *(wchar_t **)(param_6 + 4);
      goto LAB_14000284a;
    }
  }
  pwVar5 = L"NULL";
LAB_14000284a:
  pwVar2 = param_6;
  if (param_6 == (wchar_t *)0x0) {
    pwVar2 = L"\b";
  }
  if (param_4 == (wchar_t *)0x0) {
    wVar1 = L'\b';
  }
  else {
    wVar1 = *param_4;
    if (*param_4 != L'\0') {
      pwVar4 = *(wchar_t **)(param_4 + 4);
    }
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,0x1f,param_4,2,pwVar4,
             wVar1,&param_5,8,pwVar2,2,pwVar5,wVar3,&param_7,4,0);
  return;
}



===== WPP_SF_Zqq @ 140002914 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Zqq(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_4;
    if (*param_4 != L'\0') {
      pwVar1 = *(wchar_t **)(param_4 + 4);
      goto LAB_140002945;
    }
  }
  pwVar1 = L"NULL";
LAB_140002945:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,param_2,param_4,2,pwVar1,
             wVar2,&param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_qqDD @ 1400029bc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,0xe,&local_res20,8,
             &param_5,8,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qqq @ 140002a30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,param_2,&local_res20,8,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_qqqD @ 140002a94 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqqD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,0x2d,&local_res20,8,
             &param_5,8,&param_6,8,&param_7,4,0);
  return;
}



===== WPP_SF_qqqq @ 140002b08 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqqq(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,param_2,&local_res20,8,
             &param_5,8,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_SF_qqqqs @ 140002b78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqqqs(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined1 param_5,undefined1 param_6,undefined1 param_7,char *param_8)

{
  longlong lVar1;
  longlong lVar2;
  char *pcVar3;
  undefined8 local_res20;
  
  if (param_8 == (char *)0x0) {
    lVar2 = 5;
  }
  else {
    lVar1 = -1;
    do {
      lVar2 = lVar1;
      lVar1 = lVar2 + 1;
    } while (param_8[lVar1] != '\0');
    lVar2 = lVar2 + 2;
  }
  pcVar3 = param_8;
  if (param_8 == (char *)0x0) {
    pcVar3 = "NULL";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,0x28,&local_res20,8,
             &param_5,8,&param_6,8,&param_7,8,pcVar3,lVar2,0);
  return;
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 140002c40 =====

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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 140002d18 =====

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



===== wil_details_FeatureReporting_RecordUsageInCache @ 140002dfc =====

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
LAB_140002f54:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,uVar5,param_3,param_1);
  }
  else {
    if (uVar5 == 1) {
LAB_140002f47:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,uVar5,param_3,param_1);
      return param_1;
    }
    if ((uVar5 != 2) && (uVar5 != 3)) {
      if (uVar5 == 4) goto LAB_140002f54;
      if (uVar5 == 5) goto LAB_140002f47;
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



===== wil_details_FeatureReporting_ReportUsageToService @ 140002f7c =====

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



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 140003000 =====

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



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 1400030f0 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 140003200 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 140003264 =====

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



===== wil_details_IsEnabledFallback @ 1400033c4 =====

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



===== wil_details_MapReportingKind @ 140003458 =====

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



===== MupFlushKnownPrefixTableForSurrogate @ 1400034f8 =====

void MupFlushKnownPrefixTableForSurrogate(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
            &WPP_ea0133f9b224365980f4880a222ef939_Traceguids);
  }
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_14000b7c0,1);
  puVar1 = DAT_14000ba20;
  while (puVar2 = puVar1, (undefined8 **)puVar2 != &DAT_14000ba20) {
    puVar1 = (undefined8 *)*puVar2;
    if (param_1 == puVar2[-1]) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
        WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
                  &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,(wchar_t *)(puVar2 + -5),
                  (char)(puVar2 + -0xf));
      }
      if (*(int *)(puVar2 + 2) == 0) {
        MupiRemoveKnownPrefixEntry((longlong)(puVar2 + -0xf));
      }
      else {
        puVar2[-1] = 0;
      }
    }
  }
  ExReleaseResourceLite(&DAT_14000b7c0);
  KeLeaveCriticalRegion();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,
            &WPP_ea0133f9b224365980f4880a222ef939_Traceguids);
  }
  return;
}



===== MupPinKnownPrefix @ 140003640 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int MupPinKnownPrefix(wchar_t *param_1,wchar_t *param_2,longlong param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined *puVar3;
  longlong lVar4;
  undefined2 uVar5;
  undefined *local_res20;
  
                    /* 0x3640  2  MupPinKnownPrefix */
  local_res20 = (undefined *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_ZZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
              &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,param_1,param_2);
  }
  puVar2 = MupAcquireUncProviderByName(param_2);
  if (puVar2 == (undefined8 *)0x0) {
    iVar1 = -0x3fffffc7;
  }
  else {
    iVar1 = MupGetContainerContextFromSilo(param_3,&local_res20);
    if (-1 < iVar1) {
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(&DAT_14000b7c0,1);
      iVar1 = DAT_14000b7b8;
      puVar3 = MupGetUncCachePrefixTable(local_res20);
      lVar4 = MupiLookupKnownPrefixEntry(puVar3,param_1);
      if (lVar4 == 0) {
        iVar1 = MupInsertKnownPrefix
                          (local_res20,param_1,(uint)(ushort)*param_1,(longlong)puVar2,iVar1,'\0',0)
        ;
        if (-1 < iVar1) {
          puVar3 = MupGetUncCachePrefixTable(local_res20);
          lVar4 = MupiLookupKnownPrefixEntry(puVar3,param_1);
          if (lVar4 != 0) goto LAB_140003756;
LAB_1400037b1:
          iVar1 = -0x3fffff66;
        }
      }
      else {
LAB_140003756:
        if (*(undefined8 **)(lVar4 + 0x68) == puVar2) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
            WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
                      &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,(wchar_t *)(lVar4 + 0x50),
                      (char)lVar4);
          }
          if (*(int *)(lVar4 + 0x88) == -1) goto LAB_1400037b1;
          if (*(int *)(lVar4 + 0x88) == 0) {
            _DAT_14000ba48 = _DAT_14000ba48 + *(int *)(lVar4 + 8);
          }
          *(int *)(lVar4 + 0x88) = *(int *)(lVar4 + 0x88) + 1;
          iVar1 = 0;
        }
        else {
          iVar1 = -0x3fffffc7;
        }
      }
      ExReleaseResourceLite(&DAT_14000b7c0);
      KeLeaveCriticalRegion();
    }
    MupReleaseUncProvider((longlong)puVar2);
    if (-1 < iVar1) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return iVar1;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) == 0) {
        return iVar1;
      }
      uVar5 = 0x21;
      goto LAB_14000381e;
    }
  }
  if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
    return iVar1;
  }
  if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) == 0) {
    return iVar1;
  }
  uVar5 = 0x20;
LAB_14000381e:
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,
           &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,iVar1);
  return iVar1;
}



===== MupRegisterPrefixCacheKeyChangeNotification @ 140003850 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MupRegisterPrefixCacheKeyChangeNotification(void)

{
  if (MupiMupServicesKeyHandleValid != '\0') {
    _DAT_14000b9d0 = MupiPrefixCacheRegistryChangeHandler;
    _DAT_14000b9d8 = 0;
    _MupiPrefixCacheRegistryChangeWork = 0;
    ZwNotifyChangeKey(MupiMupServicesKeyHandle,0,&MupiPrefixCacheRegistryChangeWork,1,
                      &MupiPrefixCacheRegistryChangeIoStatus,4,1,0,0,1);
  }
  return;
}



===== MupUnpinKnownPrefix @ 1400038d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int MupUnpinKnownPrefix(wchar_t *param_1,longlong param_2)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  longlong lVar4;
  undefined *local_res18 [2];
  
                    /* 0x38d0  16  MupUnpinKnownPrefix */
  local_res18[0] = (undefined *)0x0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
             &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,param_1);
  }
  iVar1 = MupGetContainerContextFromSilo(param_2,local_res18);
  if (-1 < iVar1) {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_14000b7c0,1);
    puVar3 = MupGetUncCachePrefixTable(local_res18[0]);
    lVar4 = MupiLookupKnownPrefixEntry(puVar3,param_1);
    if (lVar4 != 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
        WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
                  &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,(wchar_t *)(lVar4 + 0x50),
                  (char)lVar4);
      }
      if (*(int *)(lVar4 + 0x88) == 0) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x103,6,param_1,param_2,0);
      }
      iVar2 = *(int *)(lVar4 + 0x88) + -1;
      *(int *)(lVar4 + 0x88) = iVar2;
      if (iVar2 == 0) {
        _DAT_14000ba48 = _DAT_14000ba48 - *(int *)(lVar4 + 8);
      }
    }
    ExReleaseResourceLite(&DAT_14000b7c0);
    KeLeaveCriticalRegion();
  }
  return iVar1;
}



===== MupiPrefixGarbageCollectionDpcHandler @ 140003a30 =====

void MupiPrefixGarbageCollectionDpcHandler(void)

{
  IoQueueWorkItem(pMupiPrefixGarbageCollectionWorkItem,MupiPrefixCacheReaperRoutine,1);
  return;
}



===== WPP_SF_ZDq @ 140003a64 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZDq(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
               undefined1 param_5,undefined1 param_6)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_4;
    if (*param_4 != L'\0') {
      pwVar1 = *(wchar_t **)(param_4 + 4);
      goto LAB_140003a92;
    }
  }
  pwVar1 = L"NULL";
LAB_140003a92:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,2,pwVar1,wVar2,&param_5,4,&param_6,8,0)
  ;
  return;
}



===== WPP_SF_ZZ @ 140003b0c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZZ(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
              wchar_t *param_5)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  wchar_t *pwVar3;
  wchar_t wVar4;
  
  pwVar3 = L"NULL";
  wVar2 = L'\b';
  if (param_5 == (wchar_t *)0x0) {
    wVar4 = L'\b';
  }
  else {
    wVar4 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_140003b59;
    }
  }
  pwVar1 = L"NULL";
LAB_140003b59:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  if ((param_4 != (wchar_t *)0x0) && (wVar2 = *param_4, *param_4 != L'\0')) {
    pwVar3 = *(wchar_t **)(param_4 + 4);
  }
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,param_3,param_2,param_4,2,pwVar3,wVar2,param_5,2,pwVar1,wVar4,0);
  return;
}



===== WPP_SF_Zq @ 140003bec =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Zq(undefined8 param_1,undefined2 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  
  if (param_4 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_4;
    if (*param_4 != L'\0') {
      pwVar1 = *(wchar_t **)(param_4 + 4);
      goto LAB_140003c1a;
    }
  }
  pwVar1 = L"NULL";
LAB_140003c1a:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,param_2,param_4,2,pwVar1,wVar2,&param_5,8,0);
  return;
}



===== MupTransferListEntries @ 140003c7c =====

void MupTransferListEntries(longlong *param_1,longlong *param_2)

{
  if ((longlong *)*param_2 == param_2) {
    param_1[1] = (longlong)param_1;
    *param_1 = (longlong)param_1;
    return;
  }
  ((longlong *)*param_2)[1] = (longlong)param_1;
  *(longlong **)param_2[1] = param_1;
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_2[1] = (longlong)param_2;
  *param_2 = (longlong)param_2;
  return;
}



===== McGenControlCallbackV2 @ 140003cc0 =====

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



===== RtlStringCbPrintfW @ 140003dd0 =====

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
      uVar3 = 0x80000005;
    }
    else if ((longlong)iVar1 != uVar2) {
      return 0;
    }
    param_1[uVar2] = L'\0';
  }
  else {
    uVar3 = 0xc000000d;
    if (uVar2 != 0) {
      *param_1 = L'\0';
    }
  }
  return uVar3;
}



===== WppClassicProviderCallback @ 140003e50 =====

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



===== wil_details_FeatureDescriptors_SkipPadding @ 140003e84 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_14000ab0f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== wil_details_RecordCachedUsage @ 140003eac =====

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



===== wil_details_RecordFeatureUsageReporting @ 140004000 =====

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



===== MupiAssignProvidersPriorityValue @ 140004084 =====

void MupiAssignProvidersPriorityValue(longlong param_1,longlong param_2,int param_3)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  
  if (param_2 == 0) {
    iVar1 = 0x7fffffff;
  }
  else {
    iVar1 = *(int *)(param_2 + 0x3c);
  }
  if (param_1 == 0) {
    iVar4 = 0;
    lVar2 = MupiGetFirstUncProvider(&DAT_14000b7a8);
  }
  else {
    iVar4 = *(int *)(param_1 + 0x3c);
    lVar2 = MupiGetNextUncProvider(0x14000b7a8,param_1);
  }
  uVar3 = (uint)(iVar1 - iVar4) / (param_3 + 1U);
  if (1000 < uVar3) {
    uVar3 = 1000;
  }
  for (; (lVar2 != 0 && (lVar2 != param_2)); lVar2 = MupiGetNextUncProvider(0x14000b7a8,lVar2)) {
    if (*(char *)(lVar2 + 0x40) != '\0') {
      iVar4 = iVar4 + uVar3;
      *(int *)(lVar2 + 0x3c) = iVar4;
      if ((*(longlong *)(lVar2 + 0x30) != 0) &&
         (iVar1 = MupiCreateNetworkProviderOrderRegValueInRegistry(lVar2 + 0x28,iVar4), -1 < iVar1))
      {
        *(undefined1 *)(lVar2 + 0x40) = 0;
      }
    }
  }
  return;
}



===== MupiGetFirstUncProvider @ 140004158 =====

longlong MupiGetFirstUncProvider(longlong *param_1)

{
  if ((longlong *)*param_1 == param_1) {
    return 0;
  }
  return (longlong)((longlong *)*param_1 + -1);
}



===== MupiGetNextKnownPriorityProvider @ 140004170 =====

void MupiGetNextKnownPriorityProvider(longlong param_1,int *param_2)

{
  undefined8 *puVar1;
  int iVar2;
  
  iVar2 = 1;
  *param_2 = 1;
  puVar1 = &DAT_14000b7a8;
  while( true ) {
    param_1 = MupiGetNextUncProvider((longlong)puVar1,param_1);
    if ((param_1 == 0) || (*(char *)(param_1 + 0x40) == '\0')) break;
    iVar2 = iVar2 + 1;
    *param_2 = iVar2;
  }
  return;
}



===== MupiGetNextUncProvider @ 1400041b4 =====

longlong MupiGetNextUncProvider(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = 0;
  if ((param_2 != 0) && (*(longlong *)(param_2 + 8) != param_1)) {
    lVar1 = *(longlong *)(param_2 + 8) + -8;
  }
  return lVar1;
}



===== MupiProviderIsInstalled @ 1400041d4 =====

int MupiProviderIsInstalled(ushort *param_1,undefined1 *param_2)

{
  ushort uVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined8 local_res8;
  undefined2 local_58;
  undefined2 local_56;
  undefined4 local_54;
  wchar_t *local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined8 local_40;
  undefined2 *local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  
  uVar1 = *param_1;
  local_2c = 0;
  local_54 = 0;
  local_res8 = 0;
  local_44 = 0;
  pwVar3 = (wchar_t *)ExAllocatePool2(0x102,uVar1 + 0x8c,0x2070754d);
  if (pwVar3 == (wchar_t *)0x0) {
    iVar2 = -0x3fffff66;
  }
  else {
    local_58 = 0x68;
    local_56 = (undefined2)(uVar1 + 0x8c);
    builtin_wcsncpy(pwVar3,L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\",0x34);
    local_50 = pwVar3;
    RtlAppendUnicodeStringToString(&local_58,param_1);
    RtlAppendUnicodeToString(&local_58,L"\\NetworkProvider");
    local_40 = 0;
    local_38 = &local_58;
    local_48 = 0x30;
    local_30 = 0x240;
    local_28 = 0;
    uStack_20 = 0;
    iVar2 = ZwOpenKey(&local_res8,1,&local_48);
    if (iVar2 < 0) {
      if (iVar2 == -0x3fffffcc) {
        *param_2 = 0;
        iVar2 = 0;
      }
    }
    else {
      *param_2 = 1;
      ZwClose(local_res8);
    }
    ExFreePoolWithTag(pwVar3,0);
  }
  return iVar2;
}



===== WPP_SF_ZD @ 140004350 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZD(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
              undefined1 param_5)

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
      goto LAB_140004378;
    }
  }
  pwVar2 = L"NULL";
LAB_140004378:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_b8ec61bc8b283db232150b702b34e2f1_Traceguids,0x12,param_4,2,pwVar2,
             wVar1,&param_5,4,0);
  return;
}



===== WPP_SF_ZddD @ 1400043e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_ZddD(undefined8 param_1,undefined8 param_2,undefined8 param_3,wchar_t *param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

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
      goto LAB_140004415;
    }
  }
  pwVar2 = L"NULL";
LAB_140004415:
  if (param_4 == (wchar_t *)0x0) {
    param_4 = L"\b";
  }
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,0xc,param_4,2,pwVar2,
             wVar1,&param_5,4,&param_6,4,&param_7,4,0);
  return;
}



===== WPP_SF_qZd @ 1400044a8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qZd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               wchar_t *param_5,undefined1 param_6)

{
  wchar_t *pwVar1;
  wchar_t wVar2;
  undefined8 local_res20;
  
  if (param_5 == (wchar_t *)0x0) {
    wVar2 = L'\b';
  }
  else {
    wVar2 = *param_5;
    if (*param_5 != L'\0') {
      pwVar1 = *(wchar_t **)(param_5 + 4);
      goto LAB_1400044e1;
    }
  }
  pwVar1 = L"NULL";
LAB_1400044e1:
  if (param_5 == (wchar_t *)0x0) {
    param_5 = L"\b";
  }
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,0x1a,&local_res20,8,
             param_5,2,pwVar1,wVar2,&param_6,4,0);
  return;
}



===== WPP_SF_qd @ 140004568 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,0xf,&local_res20,8,
             &param_5,4,0);
  return;
}



===== Feature_2966577467__private_IsEnabledDeviceUsageNoInline @ 1400045c4 =====

ulonglong Feature_2966577467__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_2966577467__private_featureState;
  if ((Feature_2966577467__private_featureState & 0x10) == 0) {
    uVar1 = Feature_2966577467__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_2966577467__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_2966577467__private_IsEnabledFallback @ 1400045fc =====

void Feature_2966577467__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback(param_1,param_2,&Feature_2966577467__private_descriptor);
  return;
}



===== McGenEventWrite_EtwWriteTransfer @ 140004618 =====

void McGenEventWrite_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 *param_5)

{
  ushort *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  puVar1 = DAT_14000b028;
  uVar2 = 0;
  if (DAT_14000b028 == (ushort *)0x0) {
    *param_5 = 0;
    uVar3 = 0;
  }
  else {
    *param_5 = DAT_14000b028;
    uVar2 = 2;
    uVar3 = (uint)*puVar1;
  }
  *(uint *)(param_5 + 1) = uVar3;
  *(undefined4 *)((longlong)param_5 + 0xc) = uVar2;
  EtwWriteTransfer(REMOTEFS_MUP_Context,param_2,0,0,param_4,param_5);
  return;
}



===== McTemplateK0hzr0hzr2q_EtwWriteTransfer @ 14000467c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hzr0hzr2q_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,ushort param_6,undefined8 param_7,undefined1 param_8)

{
  undefined1 auStackY_b8 [32];
  undefined2 local_88 [8];
  undefined8 local_78 [2];
  undefined2 *local_68;
  undefined8 local_60;
  wchar_t *local_58;
  undefined8 local_50;
  ushort *local_48;
  undefined8 local_40;
  undefined8 local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_60 = 2;
  local_2c = 0;
  local_88[0] = 0x54;
  local_68 = local_88;
  local_58 = 
  L"HKEY_LOCAL_MACHINE\\Software\\Policies\\Microsoft\\Windows\\NetworkProvider\\HardenedPaths";
  local_48 = &param_6;
  local_50 = 0xa8;
  local_38 = param_7;
  local_30 = (uint)param_6 * 2;
  local_40 = 2;
  local_28 = &param_8;
  local_20 = 4;
  McGenEventWrite_EtwWriteTransfer
            (param_1,&UncHardening_UnsupportedRegistryValueType,param_3,6,local_78);
  return;
}



===== McTemplateK0hzr0qzr2_EtwWriteTransfer @ 140004730 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hzr0qzr2_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,ushort param_4,
               undefined8 param_5,int param_6,undefined8 param_7)

{
  ushort local_res20 [4];
  undefined1 auStackY_98 [32];
  undefined8 local_68 [2];
  ushort *local_58;
  undefined8 local_50;
  undefined8 local_48;
  int local_40;
  undefined4 local_3c;
  int *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_98;
  local_50 = 2;
  local_58 = local_res20;
  local_3c = 0;
  local_48 = param_5;
  local_40 = (uint)param_4 * 2;
  local_30 = 4;
  local_38 = &param_6;
  local_28 = param_7;
  local_20 = param_6 * 2;
  local_1c = 0;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(0,param_2,param_3,5,local_68);
  return;
}



===== McTemplateK0hzr0qzr2hzr4hzr6_EtwWriteTransfer @ 1400047c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hzr0qzr2hzr4hzr6_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,ushort param_4,
               undefined8 param_5,int param_6,undefined8 param_7,ushort param_8,undefined8 param_9,
               ushort param_10,undefined8 param_11)

{
  ushort local_res20 [4];
  undefined1 auStackY_d8 [32];
  undefined8 local_a8 [2];
  ushort *local_98;
  undefined8 local_90;
  undefined8 local_88;
  int local_80;
  undefined4 local_7c;
  int *local_78;
  undefined8 local_70;
  undefined8 local_68;
  int local_60;
  undefined4 local_5c;
  ushort *local_58;
  undefined8 local_50;
  undefined8 local_48;
  int local_40;
  undefined4 local_3c;
  ushort *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_90 = 2;
  local_98 = local_res20;
  local_7c = 0;
  local_88 = param_5;
  local_80 = (uint)param_4 * 2;
  local_70 = 4;
  local_78 = &param_6;
  local_68 = param_7;
  local_60 = param_6 * 2;
  local_5c = 0;
  local_58 = &param_8;
  local_48 = param_9;
  local_40 = (uint)param_8 * 2;
  local_50 = 2;
  local_38 = &param_10;
  local_28 = param_11;
  local_20 = (uint)param_10 * 2;
  local_3c = 0;
  local_30 = 2;
  local_1c = 0;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,0,9,local_a8);
  return;
}



===== McTemplateK0hzr0qzr2hzr4x_EtwWriteTransfer @ 1400048b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hzr0qzr2hzr4x_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,ushort param_4,
               undefined8 param_5,int param_6,undefined8 param_7,ushort param_8,undefined8 param_9,
               undefined1 param_10)

{
  ushort local_res20 [4];
  undefined1 auStackY_c8 [32];
  undefined8 local_98 [2];
  ushort *local_88;
  undefined8 local_80;
  undefined8 local_78;
  int local_70;
  undefined4 local_6c;
  int *local_68;
  undefined8 local_60;
  undefined8 local_58;
  int local_50;
  undefined4 local_4c;
  ushort *local_48;
  undefined8 local_40;
  undefined8 local_38;
  int local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_80 = 2;
  local_88 = local_res20;
  local_6c = 0;
  local_78 = param_5;
  local_70 = (uint)param_4 * 2;
  local_4c = 0;
  local_68 = &param_6;
  local_58 = param_7;
  local_50 = param_6 * 2;
  local_2c = 0;
  local_48 = &param_8;
  local_60 = 4;
  local_38 = param_9;
  local_30 = (uint)param_8 * 2;
  local_40 = 2;
  local_28 = &param_10;
  local_20 = 8;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer
            (param_1,&UncHardening_UnsupportedProperty_IntValue,param_3,8,local_98);
  return;
}



===== McTemplateK0hzr0qzr2qhzr5_EtwWriteTransfer @ 140004980 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0hzr0qzr2qhzr5_EtwWriteTransfer
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,ushort param_4,
               undefined8 param_5,int param_6,undefined8 param_7,undefined1 param_8,ushort param_9,
               undefined8 param_10)

{
  ushort local_res20 [4];
  undefined1 auStackY_c8 [32];
  undefined8 local_98 [2];
  ushort *local_88;
  undefined8 local_80;
  undefined8 local_78;
  int local_70;
  undefined4 local_6c;
  int *local_68;
  undefined8 local_60;
  undefined8 local_58;
  int local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined8 local_40;
  ushort *local_38;
  undefined8 local_30;
  undefined8 local_28;
  int local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_c8;
  local_80 = 2;
  local_88 = local_res20;
  local_6c = 0;
  local_78 = param_5;
  local_70 = (uint)param_4 * 2;
  local_60 = 4;
  local_68 = &param_6;
  local_58 = param_7;
  local_50 = param_6 * 2;
  local_4c = 0;
  local_48 = &param_8;
  local_38 = &param_9;
  local_28 = param_10;
  local_20 = (uint)param_9 * 2;
  local_40 = 4;
  local_30 = 2;
  local_1c = 0;
  local_res20[0] = param_4;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,8,local_98);
  return;
}



===== McTemplateK0_EtwWriteTransfer @ 140004a50 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void McTemplateK0_EtwWriteTransfer(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 auStackY_58 [32];
  undefined8 local_28 [2];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_58;
  McGenEventWrite_EtwWriteTransfer(param_1,param_2,param_3,1,local_28);
  return;
}



===== MupAttempttoLoadRegistryParametersKeyRunOnce @ 140004aa0 =====

undefined8 MupAttempttoLoadRegistryParametersKeyRunOnce(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  int iVar2;
  
  plVar1 = (longlong *)(param_2 + 0x18);
  iVar2 = MupiOpenParametersKeyFromRegistry(plVar1);
  if (-1 < iVar2) {
    MupEnableMailslots = MupiReadEnableMailslotsFromRegistry(*plVar1,'\0');
    iVar2 = MupiRegisterParametersKeyRegistryChangeNotification(param_2);
    if (-1 < iVar2) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                &WPP_511a9a8026a53b8720c76e64765e5363_Traceguids);
      }
      return 1;
    }
  }
  if (*plVar1 != 0) {
    ZwClose();
    *plVar1 = 0;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_511a9a8026a53b8720c76e64765e5363_Traceguids,iVar2);
  }
  return 0;
}



===== MupRefreshRegistryParametersKeyTimerCallback @ 140004b80 =====

void MupRefreshRegistryParametersKeyTimerCallback(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  longlong local_res10;
  
  local_res10 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x1a & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_511a9a8026a53b8720c76e64765e5363_Traceguids);
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(param_2 + 0x10,0);
  plVar1 = (longlong *)(param_2 + 0x18);
  if (*plVar1 == 0) {
    cVar2 = ExAcquireRundownProtection(param_2 + 8);
    if (cVar2 != '\0') {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x1a & 1) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_511a9a8026a53b8720c76e64765e5363_Traceguids);
      }
      iVar3 = MupiOpenParametersKeyFromRegistry(plVar1);
      if (-1 < iVar3) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x1a & 1) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                  &WPP_511a9a8026a53b8720c76e64765e5363_Traceguids);
        }
        iVar3 = MupiRegisterParametersKeyRegistryChangeNotification(param_2);
        if (iVar3 < 0) {
          ZwClose(*plVar1);
          *plVar1 = 0;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                     &WPP_511a9a8026a53b8720c76e64765e5363_Traceguids,iVar3);
          }
        }
      }
      MupiArmPoliciesKeyRefreshTimer(param_2);
      ExReleaseRundownProtection(param_2 + 8);
    }
  }
  else {
    iVar3 = ObDuplicateObject(*(undefined8 *)PsInitialSystemProcess_exref,*plVar1,
                              *(undefined8 *)PsInitialSystemProcess_exref,&local_res10,0,0x200,2,0);
    if (((iVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_511a9a8026a53b8720c76e64765e5363_Traceguids,iVar3);
    }
  }
  ExReleasePushLockSharedEx(param_2 + 0x10,0);
  KeLeaveCriticalRegion();
  if (local_res10 != 0) {
    MupEnableMailslots = MupiReadEnableMailslotsFromRegistry(local_res10,'\x01');
    if (local_res10 != 0) {
      ZwClose();
    }
  }
  return;
}



===== MupRegistryParametersKeyChangeNotification @ 140004da0 =====

void MupRegistryParametersKeyChangeNotification(longlong param_1)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  undefined4 local_res8 [2];
  
  local_res8[0] = 0;
  cVar2 = ExAcquireRundownProtection(param_1 + 8);
  if (cVar2 != '\0') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
              &WPP_511a9a8026a53b8720c76e64765e5363_Traceguids);
    }
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_1 + 0x10,0);
    plVar1 = (longlong *)(param_1 + 0x18);
    iVar3 = ZwQueryKey(*plVar1,4,0,0,local_res8);
    if ((iVar3 == -0x3ffffe84) || (iVar3 == -0x3ffffbdb)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                &WPP_511a9a8026a53b8720c76e64765e5363_Traceguids);
      }
      if (*plVar1 != 0) {
        ZwClose();
        *plVar1 = 0;
      }
      iVar3 = MupiOpenParametersKeyFromRegistry(plVar1);
      if (((iVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                 &WPP_511a9a8026a53b8720c76e64765e5363_Traceguids,iVar3);
      }
    }
    if (*plVar1 != 0) {
      MupEnableMailslots = MupiReadEnableMailslotsFromRegistry(*plVar1,'\x01');
      iVar3 = MupiRegisterParametersKeyRegistryChangeNotification(param_1);
      if (iVar3 < 0) {
        ZwClose(*plVar1);
        *plVar1 = 0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                   &WPP_511a9a8026a53b8720c76e64765e5363_Traceguids,iVar3);
        }
      }
    }
    MupiArmPoliciesKeyRefreshTimer(param_1);
    ExReleasePushLockExclusiveEx(param_1 + 0x10,0);
    KeLeaveCriticalRegion();
    ExReleaseRundownProtection(param_1 + 8);
  }
  return;
}



===== WPP_SF_dDD @ 140004f90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_dDD(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)(param_1,0x2b,param_3,0xc,local_res20,4,&param_5,4,&param_6,4,0);
  return;
}



===== MupAttempttoLoadRegistryPoliciesKeyRunOnce @ 140004ff0 =====

undefined8 MupAttempttoLoadRegistryPoliciesKeyRunOnce(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  int iVar2;
  
  plVar1 = (longlong *)(param_2 + 0x18);
  iVar2 = MupiOpenPoliciesKeyFromRegistry(plVar1);
  if (-1 < iVar2) {
    MupEnableMailslotsByPolicy = MupiReadEnableMailslotsFromPoliciesRegistry(*plVar1,'\0');
    iVar2 = MupiRegisterPoliciesKeyRegistryChangeNotification(param_2);
    if (-1 < iVar2) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                &WPP_4108bb1397623747c94676978a28aeb5_Traceguids);
      }
      return 1;
    }
  }
  if (*plVar1 != 0) {
    ZwClose();
    *plVar1 = 0;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_4108bb1397623747c94676978a28aeb5_Traceguids,iVar2);
  }
  return 0;
}



===== MupRefreshRegistryPoliciesKeyTimerCallback @ 1400050d0 =====

void MupRefreshRegistryPoliciesKeyTimerCallback(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  longlong local_res10;
  
  local_res10 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x1a & 1) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_4108bb1397623747c94676978a28aeb5_Traceguids);
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(param_2 + 0x10,0);
  plVar1 = (longlong *)(param_2 + 0x18);
  if (*plVar1 == 0) {
    cVar2 = ExAcquireRundownProtection(param_2 + 8);
    if (cVar2 != '\0') {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x1a & 1) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_4108bb1397623747c94676978a28aeb5_Traceguids);
      }
      iVar3 = MupiOpenPoliciesKeyFromRegistry(plVar1);
      if (-1 < iVar3) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x1a & 1) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                  &WPP_4108bb1397623747c94676978a28aeb5_Traceguids);
        }
        iVar3 = MupiRegisterPoliciesKeyRegistryChangeNotification(param_2);
        if (iVar3 < 0) {
          ZwClose(*plVar1);
          *plVar1 = 0;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                     &WPP_4108bb1397623747c94676978a28aeb5_Traceguids,iVar3);
          }
        }
      }
      MupiArmPoliciesKeyRefreshTimer(param_2);
      ExReleaseRundownProtection(param_2 + 8);
    }
  }
  else {
    iVar3 = ObDuplicateObject(*(undefined8 *)PsInitialSystemProcess_exref,*plVar1,
                              *(undefined8 *)PsInitialSystemProcess_exref,&local_res10,0,0x200,2,0);
    if (((iVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_4108bb1397623747c94676978a28aeb5_Traceguids,iVar3);
    }
  }
  ExReleasePushLockSharedEx(param_2 + 0x10,0);
  KeLeaveCriticalRegion();
  if (local_res10 != 0) {
    MupEnableMailslotsByPolicy = MupiReadEnableMailslotsFromPoliciesRegistry(local_res10,'\x01');
    if (local_res10 != 0) {
      ZwClose();
    }
  }
  return;
}



===== MupRegistryPoliciesKeyChangeNotification @ 1400052f0 =====

void MupRegistryPoliciesKeyChangeNotification(longlong param_1)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  undefined4 local_res8 [2];
  
  local_res8[0] = 0;
  cVar2 = ExAcquireRundownProtection(param_1 + 8);
  if (cVar2 != '\0') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
              &WPP_4108bb1397623747c94676978a28aeb5_Traceguids);
    }
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_1 + 0x10,0);
    plVar1 = (longlong *)(param_1 + 0x18);
    iVar3 = ZwQueryKey(*plVar1,4,0,0,local_res8);
    if ((iVar3 == -0x3ffffe84) || (iVar3 == -0x3ffffbdb)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                &WPP_4108bb1397623747c94676978a28aeb5_Traceguids);
      }
      if (*plVar1 != 0) {
        ZwClose();
        *plVar1 = 0;
      }
      iVar3 = MupiOpenPoliciesKeyFromRegistry(plVar1);
      if (((iVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                 &WPP_4108bb1397623747c94676978a28aeb5_Traceguids,iVar3);
      }
    }
    if (*plVar1 != 0) {
      MupEnableMailslotsByPolicy = MupiReadEnableMailslotsFromPoliciesRegistry(*plVar1,'\x01');
      iVar3 = MupiRegisterPoliciesKeyRegistryChangeNotification(param_1);
      if (iVar3 < 0) {
        ZwClose(*plVar1);
        *plVar1 = 0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                   &WPP_4108bb1397623747c94676978a28aeb5_Traceguids,iVar3);
        }
      }
    }
    MupiArmPoliciesKeyRefreshTimer(param_1);
    ExReleasePushLockExclusiveEx(param_1 + 0x10,0);
    KeLeaveCriticalRegion();
    ExReleaseRundownProtection(param_1 + 8);
  }
  return;
}



===== MupWriteTelemetryOtherRemoteMailslotFailed @ 1400054e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void MupWriteTelemetryOtherRemoteMailslotFailed(undefined8 param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  uint *puVar3;
  undefined1 auStackY_88 [32];
  uint local_58 [2];
  ulonglong local_50;
  undefined8 local_48 [4];
  ulonglong *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  local_58[0] = 0;
  puVar3 = local_58;
  uVar2 = 0;
  RtlHashUnicodeString(param_1,1);
  if (5 < DAT_14000b098) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_50 = (ulonglong)local_58[0];
      local_1c = 0;
      local_28 = &local_50;
      local_20 = 8;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_140008fb1,uVar2,puVar3,3,local_48);
    }
  }
  return;
}



===== _tlgDefineProvider_annotation__TlgMupTelemetryProviderProv @ 140005580 =====

void _tlgDefineProvider_annotation__TlgMupTelemetryProviderProv(void)

{
  return;
}



===== DllInitialize @ 140005590 =====

uint DllInitialize(void)

{
                    /* 0x5590  1  DllInitialize */
  return ~-(uint)(MupiInitSuccessful != '\0') & 0xc0000010;
}



===== RfsTimerCancel @ 1400055ac =====

undefined1 RfsTimerCancel(longlong param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined1 uVar4;
  bool bVar5;
  uint local_res18 [2];
  
  puVar1 = (uint *)(param_1 + 0x40);
  local_res18[0] = *puVar1;
  do {
    LOCK();
    uVar3 = *puVar1;
    bVar5 = local_res18[0] == uVar3;
    if (bVar5) {
      *puVar1 = local_res18[0] | 4;
    }
    else {
      local_res18[0] = uVar3;
    }
    UNLOCK();
  } while (!bVar5);
  puVar2 = (uint *)(param_1 + 0x40);
  while ((local_res18[0] & 2) != 0) {
    ExBlockOnAddressPushLock(param_1 + 0xb8,puVar2,local_res18,4,0);
    local_res18[0] = *puVar2;
  }
  uVar4 = KeCancelTimer(param_1);
  KeFlushQueuedDpcs();
  local_res18[0] = *puVar2;
  while (((local_res18[0] & 8) != 0 || ((local_res18[0] & 0x10) != 0))) {
    ExBlockOnAddressPushLock(param_1 + 0xb8,puVar1,local_res18,4,0);
    local_res18[0] = *(uint *)(param_1 + 0x40);
  }
  LOCK();
  *puVar1 = *puVar1 & 0xfffffffb;
  UNLOCK();
  return uVar4;
}



===== RfsTimerCleanup @ 140005690 =====

void RfsTimerCleanup(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = *(uint *)(param_1 + 0x40);
  do {
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x40);
    bVar3 = uVar2 == uVar1;
    if (bVar3) {
      *(uint *)(param_1 + 0x40) = uVar2 | 1;
    }
    else {
      uVar2 = uVar1;
    }
    UNLOCK();
  } while (!bVar3);
  if ((uVar2 & 0x20) != 0) {
    RfsTimerCancel(param_1);
  }
  return;
}



===== RfsTimerSet @ 1400056bc =====

void RfsTimerSet(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar2 = RfsTimerpSetFlagsSafe(param_1,2);
  if (((uVar2 & 1) == 0) && ((uVar2 & 4) == 0)) {
    KeSetCoalescableTimer();
    uVar2 = *(uint *)(param_1 + 0x40);
    do {
      LOCK();
      uVar1 = *(uint *)(param_1 + 0x40);
      bVar3 = uVar2 == uVar1;
      if (bVar3) {
        *(uint *)(param_1 + 0x40) = uVar2 & 0xfffffffd;
      }
      else {
        uVar2 = uVar1;
      }
      UNLOCK();
    } while (!bVar3);
    if (((uVar2 & 1) != 0) || ((uVar2 & 4) != 0)) {
      ExUnblockOnAddressPushLockEx(param_1 + 0xb8,0);
    }
  }
  return;
}



===== RfsTimerpExpirationDpc @ 140005740 =====

void RfsTimerpExpirationDpc(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = RfsTimerpSetFlagsSafe(param_2,8);
  if (((((uVar1 & 1) == 0) && ((uVar1 & 4) == 0)) && ((uVar1 & 8) == 0)) && ((uVar1 & 0x10) == 0)) {
    ExQueueWorkItem(param_2 + 0x88);
  }
  return;
}



===== RfsTimerpSetFlagsSafe @ 140005788 =====

uint RfsTimerpSetFlagsSafe(longlong param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x40);
  while( true ) {
    if ((uVar3 & 1) != 0) {
      return uVar3;
    }
    uVar2 = 0;
    if ((uVar3 & 4) == 0) {
      uVar2 = param_2;
    }
    LOCK();
    uVar1 = *(uint *)(param_1 + 0x40);
    if (uVar3 == uVar1) {
      *(uint *)(param_1 + 0x40) = uVar2 | uVar3;
      uVar2 = uVar3;
    }
    else {
      uVar2 = uVar1;
    }
    UNLOCK();
    if (uVar3 == uVar1) break;
    uVar3 = uVar2;
  }
  return uVar3;
}



===== _guard_check_icall @ 1400057d0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1400057e8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 14000580c =====

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



===== __cpu_features_init @ 140005880 =====

/* WARNING: Removing unreachable block (ram,0x0001400058ea) */
/* WARNING: Removing unreachable block (ram,0x000140005899) */
/* WARNING: Removing unreachable block (ram,0x00014000588a) */

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



===== __security_check_cookie @ 140005950 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140005990 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400059c0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400059c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400059f0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 140005a20 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140005a63;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_140005ad4;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_140005ad0:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140005ad4;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_140005acc:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140005ad0;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_140005acc;
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
LAB_140005ad4:
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
LAB_140005a63:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140005b40 =====

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



===== memset @ 140005e40 =====

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



===== __memset_repmovs @ 140005f80 =====

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



===== __memset_query @ 140006000 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140006080 =====

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



===== __memset_spec_ermsb_repmovsb @ 1400061c0 =====

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



===== __memset_spec_plain @ 140006240 =====

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



===== _tlgEnableCallback @ 140010010 =====

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



===== MupFsctlGetUncCacheInfo @ 14001008c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int MupFsctlGetUncCacheInfo(longlong param_1)

{
  uint *_Dst;
  void *pvVar1;
  ushort uVar2;
  ushort uVar3;
  undefined4 *puVar4;
  longlong lVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  undefined *puVar10;
  ulonglong uVar11;
  longlong lVar12;
  uint *puVar13;
  uint *puVar14;
  int iVar15;
  int iVar16;
  undefined8 *puVar17;
  uint uVar18;
  int local_res10;
  undefined *local_res20;
  
  puVar4 = *(undefined4 **)(param_1 + 0x18);
  local_res20 = (undefined *)0x0;
  if (puVar4 == (undefined4 *)0x0) {
    *(undefined8 *)(param_1 + 0x38) = 0;
    return -0x3ffffff3;
  }
  uVar7 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 8);
  if (uVar7 < 4) {
    *(undefined8 *)(param_1 + 0x38) = 0;
    return -0x3fffffdd;
  }
  lVar9 = MupGetSiloFromFileObject();
  iVar6 = MupGetContainerContextFromSilo(lVar9,&local_res20);
  if (iVar6 != 0) {
    return iVar6;
  }
  puVar10 = MupGetUncCachePrefixTable(local_res20);
  iVar16 = 0x10;
  uVar11 = 0x10;
  local_res10 = 0;
  uVar18 = uVar7 - 0x10;
  iVar6 = 0;
  if (uVar7 < 0x11) {
    uVar18 = 0;
  }
  iVar15 = 0;
  puVar13 = puVar4 + 4;
  KeEnterCriticalRegion();
  ExAcquireResourceSharedLite(&DAT_14000b7c0,1);
  if ((undefined8 **)DAT_14000ba20 == &DAT_14000ba20) {
LAB_14001032d:
    uVar7 = iVar16 + 0x28;
    uVar11 = (ulonglong)uVar7;
    if (0x27 < uVar18) {
      puVar13[0] = 0;
      puVar13[1] = 0;
      *(undefined8 *)(puVar4 + 6) = 0;
      *(undefined8 *)(puVar4 + 8) = 0;
      *(undefined8 *)(puVar4 + 10) = 0;
      *(undefined8 *)(puVar4 + 0xc) = 0;
      *puVar13 = 0x28;
      goto LAB_14001034d;
    }
    iVar6 = -0x7ffffffb;
  }
  else {
    puVar14 = puVar13;
    puVar17 = DAT_14000ba20;
    do {
      if ((undefined *)puVar17[-6] == puVar10) {
        iVar16 = *(ushort *)puVar17[-7] + 0x24 + (uint)*(ushort *)(puVar17[-2] + 0x18);
        if (puVar17[-1] != 0) {
          iVar16 = iVar16 + (uint)*(ushort *)(puVar17[-1] + 0x28);
        }
        uVar7 = iVar16 + 3U & 0xfffffffc;
        if (uVar18 < uVar7) {
          uVar18 = 0;
          iVar6 = -0x7ffffffb;
        }
        else {
          *puVar14 = uVar7;
          puVar14[7] = *(uint *)(puVar17[-2] + 0x3c);
          lVar5 = _DAT_fffff78000000320;
          lVar12 = 0;
          lVar9 = puVar17[-3];
          if (_DAT_fffff78000000320 < lVar9) {
            uVar8 = KeQueryTimeIncrement();
            lVar12 = (ulonglong)uVar8 * (lVar9 - lVar5) * 100;
          }
          _Dst = puVar14 + 9;
          puVar14[8] = (uint)(lVar12 / 1000000000);
          uVar2 = *(ushort *)puVar17[-7];
          *(ushort *)(puVar14 + 2) = uVar2;
          iVar16 = (int)puVar14;
          puVar14[1] = ((int)_Dst - iVar16) - 0x24;
          memmove(_Dst,*(void **)(puVar17[-7] + 8),(ulonglong)uVar2);
          uVar3 = *(ushort *)(puVar17[-2] + 0x18);
          *(ushort *)(puVar14 + 4) = uVar3;
          pvVar1 = (void *)((longlong)_Dst + (ulonglong)(uVar2 >> 1) * 2);
          puVar14[3] = ((int)pvVar1 - iVar16) - 0x24;
          memmove(pvVar1,*(void **)(puVar17[-2] + 0x20),(ulonglong)uVar3);
          pvVar1 = (void *)((longlong)pvVar1 + (ulonglong)(uVar3 >> 1) * 2);
          if (puVar17[-1] == 0) {
            puVar14[5] = 0;
            *(undefined2 *)(puVar14 + 6) = 0;
          }
          else {
            uVar2 = *(ushort *)(puVar17[-1] + 0x28);
            *(ushort *)(puVar14 + 6) = uVar2;
            puVar14[5] = ((int)pvVar1 - iVar16) - 0x24;
            memmove(pvVar1,*(void **)(puVar17[-1] + 0x30),(ulonglong)uVar2);
          }
          *(undefined2 *)((longlong)puVar14 + 0x1a) = 0;
          if (*(char *)((longlong)puVar17 + 0x14) != '\0') {
            *(undefined2 *)((longlong)puVar14 + 0x1a) = 1;
          }
          puVar14 = (uint *)((longlong)puVar14 + (ulonglong)*puVar14);
          uVar18 = uVar18 - uVar7;
          iVar15 = local_res10;
        }
        uVar11 = (ulonglong)((int)uVar11 + uVar7);
        iVar15 = iVar15 + 1;
        local_res10 = iVar15;
      }
      iVar16 = (int)uVar11;
      puVar17 = (undefined8 *)*puVar17;
    } while ((undefined8 **)puVar17 != &DAT_14000ba20);
    if (iVar15 == 0) goto LAB_14001032d;
LAB_14001034d:
    uVar7 = (uint)uVar11;
    if (iVar6 == 0) {
      *puVar4 = DAT_14000ba38;
      puVar4[1] = DAT_14000ba3c;
      lVar9 = SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816(DAT_14000ba30),8) + DAT_14000ba30;
      puVar4[3] = iVar15;
      puVar4[2] = (int)(lVar9 >> 0x17) - (int)(lVar9 >> 0x3f);
      goto LAB_1400103ad;
    }
  }
  **(uint **)(param_1 + 0x18) = uVar7;
  uVar11 = 4;
LAB_1400103ad:
  *(ulonglong *)(param_1 + 0x38) = uVar11;
  ExReleaseResourceLite(&DAT_14000b7c0);
  KeLeaveCriticalRegion();
  return iVar6;
}



===== MupiAllocKnownPrefixEntry @ 1400103ec =====

void MupiAllocKnownPrefixEntry(int param_1)

{
  undefined2 *puVar1;
  int iVar2;
  
  iVar2 = param_1 + 0x90;
  puVar1 = (undefined2 *)ExAllocatePool2(0x102,iVar2,0x6550754d);
  if (puVar1 != (undefined2 *)0x0) {
    puVar1[1] = (short)iVar2;
    *puVar1 = 0x7101;
    *(undefined4 *)(puVar1 + 2) = 1;
    *(int *)(puVar1 + 4) = iVar2;
  }
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 14001043c =====

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
  local_28 = *(undefined4 *)(PTR_DAT_14000b0a0 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_14000b0a0 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_14000b0a0 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_14000b0a0 + -4);
  if (DAT_14000b0b8 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_14000b0c0 = 0;
  uRam000000014000b0c8 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x14001049f;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_14000b098,&DAT_14000b0b8);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_14000b0a0;
    *(undefined8 *)(puVar4 + -8) = 0x1400104c6;
    EtwSetInformation(DAT_14000b0b8,2,PTR_DAT_14000b0a0,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x1400104da;
  return iVar3;
}



===== WppInitKm @ 1400104e8 =====

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



===== MupDereferenceContainerContext @ 140010578 =====

void MupDereferenceContainerContext(void)

{
  PsDereferenceSiloContext();
  return;
}



===== MupFastIoDetachDevice @ 1400105a0 =====

void MupFastIoDetachDevice(void)

{
  return;
}



===== MupFastIoMdlRead @ 1400105b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MupFastIoMdlRead(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                     undefined8 param_5,undefined8 param_6)

{
  uint *puVar1;
  longlong local_18 [2];
  
  local_18[0] = 0;
  puVar1 = (uint *)MupiGetProviderFastIoDispatchTable(param_1,local_18);
  if (((puVar1 == (uint *)0x0) || (*puVar1 < 0x88)) || (*(code **)(puVar1 + 0x20) == (code *)0x0)) {
    FsRtlMdlReadDev(param_1,param_2,param_3,param_4,param_5,param_6,local_18[0]);
  }
  else {
    (**(code **)(puVar1 + 0x20))(param_1,param_2,param_3,param_4,param_5,param_6,local_18[0]);
  }
  return;
}



===== MupFastIoMdlReadComplete @ 140010690 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MupFastIoMdlReadComplete(undefined8 param_1,undefined8 param_2)

{
  uint *puVar1;
  longlong local_res20;
  
  local_res20 = 0;
  puVar1 = (uint *)MupiGetProviderFastIoDispatchTable(param_1,&local_res20);
  if (((puVar1 == (uint *)0x0) || (*puVar1 < 0x90)) || (*(code **)(puVar1 + 0x22) == (code *)0x0)) {
    FsRtlMdlReadCompleteDev(param_1,param_2,local_res20);
  }
  else {
    (**(code **)(puVar1 + 0x22))(param_1,param_2,local_res20);
  }
  return;
}



===== MupFastIoMdlReadCompleteCompressed @ 140010710 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 MupFastIoMdlReadCompleteCompressed(undefined8 param_1,undefined8 param_2)

{
  undefined1 uVar1;
  uint *puVar2;
  longlong local_res20;
  
  uVar1 = 0;
  local_res20 = 0;
  puVar2 = (uint *)MupiGetProviderFastIoDispatchTable(param_1,&local_res20);
  if (((puVar2 != (uint *)0x0) && (0xb7 < *puVar2)) && (*(code **)(puVar2 + 0x2c) != (code *)0x0)) {
    uVar1 = (**(code **)(puVar2 + 0x2c))(param_1,param_2,local_res20);
  }
  return uVar1;
}



===== MupFastIoMdlWriteComplete @ 140010780 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MupFastIoMdlWriteComplete(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint *puVar1;
  longlong local_18 [2];
  
  local_18[0] = 0;
  puVar1 = (uint *)MupiGetProviderFastIoDispatchTable(param_1,local_18);
  if (((puVar1 == (uint *)0x0) || (*puVar1 < 0xa0)) || (*(code **)(puVar1 + 0x26) == (code *)0x0)) {
    FsRtlMdlWriteCompleteDev(param_1,param_2,param_3,local_18[0]);
  }
  else {
    (**(code **)(puVar1 + 0x26))(param_1,param_2,param_3,local_18[0]);
  }
  return;
}



===== MupFastIoMdlWriteCompleteCompressed @ 140010810 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
MupFastIoMdlWriteCompleteCompressed(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  uint *puVar2;
  longlong local_18 [2];
  
  uVar1 = 0;
  local_18[0] = 0;
  puVar2 = (uint *)MupiGetProviderFastIoDispatchTable(param_1,local_18);
  if (((puVar2 != (uint *)0x0) && (0xbf < *puVar2)) && (*(code **)(puVar2 + 0x2e) != (code *)0x0)) {
    uVar1 = (**(code **)(puVar2 + 0x2e))(param_1,param_2,param_3,local_18[0]);
  }
  return uVar1;
}



===== MupFastIoPrepareMdlWrite @ 140010890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MupFastIoPrepareMdlWrite
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined8 param_5,undefined8 param_6)

{
  uint *puVar1;
  longlong local_18 [2];
  
  local_18[0] = 0;
  puVar1 = (uint *)MupiGetProviderFastIoDispatchTable(param_1,local_18);
  if (((puVar1 == (uint *)0x0) || (*puVar1 < 0x98)) || (*(code **)(puVar1 + 0x24) == (code *)0x0)) {
    FsRtlPrepareMdlWriteDev(param_1,param_2,param_3,param_4,param_5,param_6,local_18[0]);
  }
  else {
    (**(code **)(puVar1 + 0x24))(param_1,param_2,param_3,param_4,param_5,param_6,local_18[0]);
  }
  return;
}



===== MupFastIoReadCompressed @ 140010970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
MupFastIoReadCompressed
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5,undefined8 param_6,undefined4 *param_7,undefined8 param_8,
          undefined4 param_9)

{
  undefined1 uVar1;
  uint *puVar2;
  longlong local_18 [2];
  
  uVar1 = 0;
  local_18[0] = 0;
  puVar2 = (uint *)MupiGetProviderFastIoDispatchTable(param_1,local_18);
  if (((puVar2 == (uint *)0x0) || (*puVar2 < 0xa8)) || (*(code **)(puVar2 + 0x28) == (code *)0x0)) {
    *param_7 = 0xc00000bb;
  }
  else {
    uVar1 = (**(code **)(puVar2 + 0x28))
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       local_18[0]);
  }
  return uVar1;
}



===== MupFastIoUnlockAll @ 140010a50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 MupFastIoUnlockAll(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  uint *puVar2;
  longlong local_18 [2];
  
  uVar1 = 0;
  local_18[0] = 0;
  puVar2 = (uint *)MupiGetProviderFastIoDispatchTable(param_1,local_18);
  if (((puVar2 != (uint *)0x0) && (0x47 < *puVar2)) && (*(code **)(puVar2 + 0x10) != (code *)0x0)) {
    uVar1 = (**(code **)(puVar2 + 0x10))(param_1,param_2,param_3,local_18[0]);
  }
  return uVar1;
}



===== MupFastIoUnlockAllByKey @ 140010ad0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
MupFastIoUnlockAllByKey(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined1 uVar1;
  uint *puVar2;
  longlong local_18 [2];
  
  uVar1 = 0;
  local_18[0] = 0;
  puVar2 = (uint *)MupiGetProviderFastIoDispatchTable(param_1,local_18);
  if (((puVar2 != (uint *)0x0) && (0x4f < *puVar2)) && (*(code **)(puVar2 + 0x12) != (code *)0x0)) {
    uVar1 = (**(code **)(puVar2 + 0x12))(param_1,param_2,param_3,param_4,local_18[0]);
  }
  return uVar1;
}



===== MupFastIoWriteCompressed @ 140010b60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
MupFastIoWriteCompressed
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5,undefined8 param_6,undefined4 *param_7,undefined8 param_8,
          undefined4 param_9)

{
  undefined1 uVar1;
  uint *puVar2;
  longlong local_18 [2];
  
  uVar1 = 0;
  local_18[0] = 0;
  puVar2 = (uint *)MupiGetProviderFastIoDispatchTable(param_1,local_18);
  if (((puVar2 == (uint *)0x0) || (*puVar2 < 0xb0)) || (*(code **)(puVar2 + 0x2a) == (code *)0x0)) {
    *param_7 = 0xc00000bb;
  }
  else {
    uVar1 = (**(code **)(puVar2 + 0x2a))
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       local_18[0]);
  }
  return uVar1;
}



===== MupInitFastIo @ 140010c40 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MupInitFastIo(longlong param_1)

{
  _MupiFastIoDispatch = 0xe0;
  _DAT_14000be58 = 0;
  _DAT_14000be08 = MupFastIoCheckIfPossible;
  _DAT_14000be10 = MupFastIoRead;
  _DAT_14000be18 = MupFastIoWrite;
  _DAT_14000be20 = MupFastIoQueryBasicInfo;
  _DAT_14000be28 = MupFastIoQueryStandardInfo;
  _DAT_14000be30 = MupFastIoLock;
  _DAT_14000be38 = MupFastIoUnlockSingle;
  _DAT_14000be40 = MupFastIoUnlockAll;
  _DAT_14000be48 = MupFastIoUnlockAllByKey;
  _DAT_14000be50 = MupFastIoDeviceControl;
  _DAT_14000be68 = MupFastIoDetachDevice;
  _DAT_14000be70 = MupFastIoQueryNetworkOpenInfo;
  _DAT_14000be80 = MupFastIoMdlRead;
  _DAT_14000be88 = MupFastIoMdlReadComplete;
  _DAT_14000be90 = MupFastIoPrepareMdlWrite;
  _DAT_14000be98 = MupFastIoMdlWriteComplete;
  _DAT_14000bea0 = MupFastIoReadCompressed;
  _DAT_14000bea8 = MupFastIoWriteCompressed;
  _DAT_14000beb0 = MupFastIoMdlReadCompleteCompressed;
  _DAT_14000beb8 = MupFastIoMdlWriteCompleteCompressed;
  _DAT_14000bec0 = MupFastIoQueryOpen;
  _DAT_14000be60 = 0;
  _DAT_14000be78 = 0;
  _DAT_14000bec8 = 0;
  _DAT_14000bed0 = 0;
  _DAT_14000bed8 = 0;
  *(undefined **)(param_1 + 0x50) = &MupiFastIoDispatch;
  return;
}



===== MupRestoreFileNameInFileObject @ 140010db0 =====

undefined8 MupRestoreFileNameInFileObject(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  wchar_t *pwVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  uint uVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x90);
  pwVar1 = (wchar_t *)(param_1 + 0x60);
  uVar5 = (uint)(ushort)*pwVar1;
  uVar4 = 0;
  if (((char)param_2 == '\0') || (uVar5 = (ushort)*pwVar1 + 0x16, uVar5 < 0x10000)) {
    if (*(ushort *)(lVar2 + 0x5a) < uVar5) {
      lVar3 = ExAllocatePool2(0x102,uVar5,0x6e46754d);
      if (lVar3 == 0) {
        return 0xc000009a;
      }
      if (*(longlong *)(lVar2 + 0x60) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar2 + 0x60),0);
      }
      *(longlong *)(lVar2 + 0x60) = lVar3;
      *(short *)(lVar2 + 0x5a) = (short)uVar5;
    }
    *(undefined2 *)(lVar2 + 0x58) = 0;
    if ((char)param_2 != '\0') {
      RtlAppendUnicodeToString(lVar2 + 0x58,L"\\Device\\Mup");
    }
    RtlAppendUnicodeStringToString(lVar2 + 0x58,pwVar1);
  }
  else {
    uVar4 = 0xc000000d;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
      WPP_SF_qZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,lVar2,pwVar1);
    }
  }
  return uVar4;
}



===== MupSetupUndecoratedFileNameForRelativeOpen @ 140010ed0 =====

undefined4 MupSetupUndecoratedFileNameForRelativeOpen(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  lVar1 = *(longlong *)(param_1 + 0x98);
  uVar5 = 0;
  lVar2 = *(longlong *)(param_1 + 0x90);
  bVar3 = false;
  bVar4 = false;
  uVar8 = (uint)(*(ushort *)(lVar1 + 0x28) >> 1);
  uVar10 = (uint)(*(ushort *)(lVar2 + 0x58) >> 1);
  uVar7 = uVar8;
  if ((uVar10 != 0) && (uVar8 != 0)) {
    uVar9 = uVar8 - 1;
    if (**(short **)(lVar2 + 0x60) == 0x3a) {
      if (*(short *)(*(longlong *)(lVar1 + 0x30) + (ulonglong)uVar9 * 2) == 0x5c) {
        bVar4 = true;
        uVar7 = uVar9;
      }
    }
    else if (*(short *)(*(longlong *)(lVar1 + 0x30) + (ulonglong)uVar9 * 2) != 0x5c) {
      bVar3 = true;
      uVar7 = uVar8 + 1;
    }
  }
  uVar7 = (uVar10 + uVar7) * 2;
  if (uVar7 < 0xffff) {
    lVar6 = ExAllocatePool2(0x102,uVar7);
    if (lVar6 == 0) {
      uVar5 = 0xc000009a;
    }
    else {
      RtlInitUnicodeString(param_1 + 0x28,0);
      *(longlong *)(param_1 + 0x58) = lVar6;
      *(longlong *)(param_1 + 0x30) = lVar6;
      *(short *)(param_1 + 0x2a) = (short)uVar7;
      MupSaveUnstrippedFileName(param_1,(ushort *)(lVar1 + 0x28),'\0');
      if (bVar3) {
        *(undefined2 *)(*(longlong *)(param_1 + 0x30) + (ulonglong)uVar8 * 2) = 0x5c;
        *(short *)(param_1 + 0x28) = *(short *)(param_1 + 0x28) + 2;
      }
      else if (bVar4) {
        *(short *)(param_1 + 0x28) = *(short *)(param_1 + 0x28) + -2;
      }
      if (uVar10 != 0) {
        uVar5 = RtlAppendUnicodeStringToString(param_1 + 0x28,lVar2 + 0x58);
      }
    }
  }
  else {
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== MupInitFileIo @ 140011020 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 MupInitFileIo(void)

{
  _MupQueryContextTable = 0x587106;
  _DAT_14000bb44 = 1;
  KeInitializeGuardedMutex(&DAT_14000bb58);
  DAT_14000bb50 = &DAT_14000bb48;
  _DAT_14000bb48 = &DAT_14000bb48;
  KeInitializeGuardedMutex(&MupiMupDeviceOpenCountMutex);
  return 0;
}



===== MupiAllocLegacyQueryPathRequest @ 140011084 =====

uint * MupiAllocLegacyQueryPathRequest(undefined8 param_1,ushort *param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)ExAllocatePool2(0x42,(ulonglong)*param_2 + 0x18,0x2070754d);
  if (puVar1 != (uint *)0x0) {
    *(undefined8 *)(puVar1 + 2) = param_1;
    *puVar1 = (uint)*param_2;
    memmove(puVar1 + 4,*(void **)(param_2 + 4),(ulonglong)*param_2);
  }
  return puVar1;
}



===== MupiRerouteCreateToProvider @ 1400110f4 =====

int MupiRerouteCreateToProvider(longlong param_1,wchar_t *param_2)

{
  wchar_t *pwVar1;
  int iVar2;
  wchar_t *pwVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong local_18;
  longlong lStack_10;
  
  pwVar1 = (wchar_t *)(param_1 + 0x58);
  local_18 = 0;
  lStack_10 = 0;
  uVar4 = (uint)(ushort)*param_2 + (uint)(ushort)*pwVar1;
  uVar5 = (ulonglong)uVar4;
  if (uVar4 < 0x10000) {
    pwVar3 = (wchar_t *)(uVar5 & 0xffff);
    uVar5 = 0x6e46754d;
    local_18 = (ulonglong)(ushort)uVar4 << 0x10;
    lStack_10 = ExAllocatePool2(0x102);
    if (lStack_10 == 0) {
      iVar2 = -0x3fffff66;
    }
    else {
      RtlCopyUnicodeString(&local_18,param_2);
      iVar2 = RtlAppendUnicodeStringToString(&local_18);
      pwVar3 = (wchar_t *)0x0;
      if (iVar2 < 0) {
        ExFreePoolWithTag(lStack_10);
      }
      else {
        ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x60));
        iVar2 = 0x104;
        *(longlong *)pwVar1 = local_18;
        *(longlong *)(param_1 + 0x60) = lStack_10;
      }
    }
  }
  else {
    iVar2 = -0x3ffffefa;
    pwVar3 = param_2;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_ZqZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pwVar3,uVar5,pwVar1,(char)param_1,param_2
                ,(char)iVar2);
  }
  return iVar2;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 14001121c =====

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



===== MupFlushKnownPrefixTable @ 1400112e8 =====

void MupFlushKnownPrefixTable(longlong param_1,longlong param_2,char param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
            &WPP_ea0133f9b224365980f4880a222ef939_Traceguids);
  }
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_14000b7c0,1);
  puVar1 = DAT_14000ba20;
  while (puVar2 = puVar1, (undefined8 **)puVar2 != &DAT_14000ba20) {
    puVar1 = (undefined8 *)*puVar2;
    if (((param_2 == 0) || (puVar2[-2] == param_2)) && ((param_1 == 0 || (puVar2[-6] == param_1))))
    {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
        WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                  &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,(wchar_t *)(puVar2 + -5),
                  (char)(puVar2 + -0xf));
      }
      if ((*(int *)(puVar2 + 2) == 0) || (param_3 != '\0')) {
        MupiRemoveKnownPrefixEntry((longlong)(puVar2 + -0xf));
      }
    }
  }
  ExReleaseResourceLite(&DAT_14000b7c0);
  KeLeaveCriticalRegion();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
            &WPP_ea0133f9b224365980f4880a222ef939_Traceguids);
  }
  return;
}



===== MupFlushPrefixEntry @ 140011448 =====

undefined1 MupFlushPrefixEntry(undefined8 param_1,wchar_t *param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,param_2);
  }
  uVar2 = 0;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_14000b7c0,1);
  lVar1 = MupiLookupKnownPrefixEntry(param_1,param_2);
  if ((lVar1 != 0) && (*(int *)(lVar1 + 0x88) == 0)) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
      WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
                &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,(wchar_t *)(lVar1 + 0x50),
                (char)lVar1);
    }
    MupiRemoveKnownPrefixEntry(lVar1);
    uVar2 = 1;
  }
  ExReleaseResourceLite(&DAT_14000b7c0);
  KeLeaveCriticalRegion();
  return uVar2;
}



===== MupInitPrefixCache @ 140011550 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 MupInitPrefixCache(void)

{
  int iVar1;
  undefined8 uVar2;
  bool bVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  uVar2 = MupDeviceObject;
  _MupiKnownPrefixInfo = 0x507102;
  local_1c = 0;
  local_34 = 0;
  bVar3 = true;
  _DAT_14000ba04 = 1;
  RtlInitializeUnicodePrefix(&DAT_14000ba08);
  DAT_14000ba3c = 0;
  _DAT_14000ba48 = 0;
  DAT_14000ba28 = &DAT_14000ba20;
  DAT_14000ba20 = &DAT_14000ba20;
  KeInitializeTimerEx(&MupiPrefixGarbageCollectionTimer,0);
  KeInitializeDpc(&MupiPrefixGarbageCollectionDpc,MupiPrefixGarbageCollectionDpcHandler,0);
  pMupiPrefixGarbageCollectionWorkItem = IoAllocateWorkItem(uVar2);
  if (pMupiPrefixGarbageCollectionWorkItem == 0) {
    return 0xc0000017;
  }
  local_30 = 0;
  local_28 = &g_MupServicesRegistryKey;
  local_38 = 0x30;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwOpenKey(&MupiMupServicesKeyHandle,0x20019,&local_38);
  if (-1 < iVar1) {
    MupiMupServicesKeyHandleValid = 1;
    iVar1 = MupiReadPrefixCacheTimeoutFromRegistry(&DAT_14000ba30);
    uVar2 = MupiReadPrefixCacheMaxSizeFromRegistry(&DAT_14000ba38);
    bVar3 = (int)uVar2 != 0;
    if (iVar1 == 0) goto LAB_140011697;
  }
  DAT_14000ba30 = 9000000000;
LAB_140011697:
  if (bVar3) {
    DAT_14000ba38 = 0x4000;
  }
  return 0;
}



===== MupiFreeKnownPrefixEntry @ 1400116bc =====

void MupiFreeKnownPrefixEntry(undefined8 param_1)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
             &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,param_1);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== MupiPrefixCacheReaperRoutine @ 140011720 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MupiPrefixCacheReaperRoutine(void)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1b,
            &WPP_ea0133f9b224365980f4880a222ef939_Traceguids);
  }
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_14000b7c0,1);
  puVar1 = DAT_14000ba20;
  while (puVar2 = puVar1, (undefined8 **)puVar2 != &DAT_14000ba20) {
    puVar1 = (undefined8 *)*puVar2;
    if ((*(int *)(puVar2 + 2) == 0) && ((longlong)puVar2[-3] <= _DAT_fffff78000000320)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
        WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                  &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,(wchar_t *)(puVar2 + -5),
                  (char)(puVar2 + -0xf));
      }
      MupiRemoveKnownPrefixEntry((longlong)(puVar2 + -0xf));
    }
  }
  MupiPrefixScheduleGarbageCollectionTimeout();
  ExReleaseResourceLite(&DAT_14000b7c0);
  KeLeaveCriticalRegion();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
            &WPP_ea0133f9b224365980f4880a222ef939_Traceguids);
  }
  return;
}



===== MupiPrefixCacheRegistryChangeHandler @ 140011870 =====

void MupiPrefixCacheRegistryChangeHandler(void)

{
  char cVar1;
  
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_14000b7c0,1);
  MupiReadPrefixCacheTimeoutFromRegistry(&DAT_14000ba30);
  cVar1 = KeCancelTimer(&MupiPrefixGarbageCollectionTimer);
  if (cVar1 != '\0') {
    MupiPrefixScheduleGarbageCollectionTimeout();
  }
  MupiReadPrefixCacheMaxSizeFromRegistry(&DAT_14000ba38);
  MupiPrefixCacheSizePolicyCheck();
  ExReleaseResourceLite(&DAT_14000b7c0);
  KeLeaveCriticalRegion();
  ZwNotifyChangeKey(MupiMupServicesKeyHandle,0,&MupiPrefixCacheRegistryChangeWork,1,
                    &MupiPrefixCacheRegistryChangeIoStatus,4,1,0,0,1);
  return;
}



===== MupiPrefixCacheSizePolicyCheck @ 140011944 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MupiPrefixCacheSizePolicyCheck(void)

{
  undefined8 *puVar1;
  int *piVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  puVar4 = DAT_14000ba20;
  while (((undefined8 **)puVar4 != &DAT_14000ba20 &&
         (DAT_14000ba38 < (uint)(DAT_14000ba3c - _DAT_14000ba48)))) {
    puVar1 = puVar4 + -0xf;
    puVar3 = (undefined8 *)*puVar4;
    piVar2 = (int *)(puVar4 + 2);
    puVar4 = puVar3;
    if (*piVar2 == 0) {
      MupiRemoveKnownPrefixEntry((longlong)puVar1);
    }
  }
  return;
}



===== MupiPrefixScheduleGarbageCollectionTimeout @ 1400119a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MupiPrefixScheduleGarbageCollectionTimeout(void)

{
  longlong lVar1;
  uint uVar2;
  undefined8 *puVar3;
  longlong lVar4;
  longlong lVar5;
  
  lVar1 = _DAT_fffff78000000320;
  if ((undefined8 **)DAT_14000ba20 != &DAT_14000ba20) {
    lVar4 = 0;
    for (puVar3 = DAT_14000ba20; lVar5 = DAT_14000ba30, (undefined8 **)puVar3 != &DAT_14000ba20;
        puVar3 = (undefined8 *)*puVar3) {
      if (*(int *)(puVar3 + 2) == 0) {
        lVar5 = puVar3[-3];
        if (_DAT_fffff78000000320 < lVar5) {
          uVar2 = KeQueryTimeIncrement();
          lVar4 = (ulonglong)uVar2 * (lVar5 - lVar1) * 100;
        }
        lVar4 = SUB168(SEXT816(-0x5c28f5c28f5c28f5) * SEXT816(lVar4),8) + lVar4;
        lVar5 = (lVar4 >> 6) - (lVar4 >> 0x3f);
        if (DAT_14000ba30 < lVar5) {
          lVar5 = DAT_14000ba30;
        }
        break;
      }
    }
    _MupiPrefixGarbageCollectionTimeoutValue = -lVar5;
    KeSetCoalescableTimer
              (&MupiPrefixGarbageCollectionTimer,_MupiPrefixGarbageCollectionTimeoutValue,0,1000,
               &MupiPrefixGarbageCollectionDpc);
  }
  return;
}



===== MupiReadPrefixCacheMaxSizeFromRegistry @ 140011a7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 MupiReadPrefixCacheMaxSizeFromRegistry(int *param_1)

{
  undefined8 uVar1;
  uint uVar2;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  undefined4 *local_50;
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_48[0] = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  local_40 = 0;
  uStack_38 = 0;
  RtlInitUnicodeString(&local_40,L"PrefixCacheSizeInKB");
  local_50 = local_48;
  local_58 = 0x14;
  uVar1 = ZwQueryValueKey(MupiMupServicesKeyHandle,&local_40,2,&local_30);
  if ((int)uVar1 == 0) {
    if (local_30._4_4_ == 4) {
      if (uStack_28._4_4_ == 0) {
        uVar2 = 0x10;
      }
      else {
        uVar2 = 5;
        if ((4 < uStack_28._4_4_) && (uVar2 = uStack_28._4_4_, 0x800 < uStack_28._4_4_)) {
          uVar2 = 0x800;
        }
      }
      *param_1 = uVar2 << 10;
    }
    else {
      uVar1 = 0xc000000d;
    }
  }
  return uVar1;
}



===== MupiReadPrefixCacheTimeoutFromRegistry @ 140011b4c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MupiReadPrefixCacheTimeoutFromRegistry(longlong *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_78 [32];
  undefined4 local_58;
  undefined4 *local_50;
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  local_48[0] = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_20 = 0;
  local_40 = 0;
  uStack_38 = 0;
  RtlInitUnicodeString(&local_40,L"ProviderCacheTimeoutInMinutes");
  local_50 = local_48;
  local_58 = 0x14;
  iVar1 = ZwQueryValueKey(MupiMupServicesKeyHandle,&local_40,2,&local_30);
  if (iVar1 == 0) {
    if (local_30._4_4_ == 4) {
      uVar3 = uStack_28._4_4_ * 0x3c;
      if (uVar3 == 0) {
        uVar2 = 900;
      }
      else {
        uVar2 = 0x3c;
        if ((0x3b < uVar3) && (uVar2 = uVar3, 0xe10 < uVar3)) {
          uVar2 = 0xe10;
        }
      }
      *param_1 = (ulonglong)uVar2 * 10000000;
    }
    else {
      iVar1 = -0x3ffffff3;
    }
  }
  return iVar1;
}



===== MupiRemoveKnownPrefixEntry @ 140011c2c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MupiRemoveKnownPrefixEntry(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1a,
              &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,(wchar_t *)(param_1 + 0x50),
              (char)param_1);
  }
  RtlRemoveUnicodePrefix(*(undefined8 *)(param_1 + 0x48),param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x48) = 0;
  plVar1 = (longlong *)(param_1 + 0x78);
  lVar2 = *plVar1;
  if ((*(longlong **)(lVar2 + 8) != plVar1) ||
     (plVar3 = *(longlong **)(param_1 + 0x80), (longlong *)*plVar3 != plVar1)) {
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  *plVar3 = lVar2;
  *(longlong **)(lVar2 + 8) = plVar3;
  DAT_14000ba40 = DAT_14000ba40 + -1;
  if (DAT_14000ba40 == 0) {
    KeCancelTimer(&MupiPrefixGarbageCollectionTimer);
  }
  DAT_14000ba3c = DAT_14000ba3c - *(int *)(param_1 + 8);
  if (*(int *)(param_1 + 0x88) != 0) {
    _DAT_14000ba48 = _DAT_14000ba48 - *(int *)(param_1 + 8);
  }
  MupiFreeKnownPrefixEntry(param_1);
  return;
}



===== MupiGetIrpStackSize @ 140011cf8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1 MupiGetIrpStackSize(void)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 auStack_a8 [32];
  undefined4 local_88;
  undefined4 *local_80;
  undefined4 local_78 [2];
  longlong local_70 [5];
  undefined *local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  local_70[3] = 0x30;
  local_3c = 0;
  local_78[0] = 0;
  local_70[0] = 0;
  local_70[4] = 0;
  uVar2 = 3;
  local_18 = 0;
  local_48 = &g_MupParametersRegistryKey;
  local_28 = 0;
  uStack_20 = 0;
  local_40 = 0x240;
  local_70[1] = 0;
  local_70[2] = 0;
  local_38 = 0;
  uStack_30 = 0;
  iVar1 = ZwOpenKey(local_70,0x20019,local_70 + 3);
  if (-1 < iVar1) {
    RtlInitUnicodeString(local_70 + 1,L"IrpStackSize");
    local_80 = local_78;
    local_88 = 0x14;
    iVar1 = ZwQueryValueKey(local_70[0],local_70 + 1,2,&local_28);
    if ((-1 < iVar1) && (local_28._4_4_ == 4)) {
      uVar2 = 3;
      if (uStack_20._4_4_ - 4U < 7) {
        uVar2 = (char)((ulonglong)uStack_20 >> 0x20);
      }
    }
  }
  if (local_70[0] != 0) {
    ZwClose();
  }
  return uVar2;
}



===== WppTraceCallback @ 140011e20 =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 1400120a8 =====

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
      goto LAB_140012105;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_140012105;
    }
  }
  uVar1 = 0x206;
LAB_140012105:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies @ 140012110 =====

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



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1400121c8 =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 140012200 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_140012282;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_140012282;
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
LAB_140012282:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1400122d0 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 140012330 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 14001234c =====

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



===== MupDeInitUncProviderModule @ 140012400 =====

void MupDeInitUncProviderModule(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined1 *puVar4;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  ExWaitForRundownProtectionRelease(&UncProviderModuleRundownRef);
  RfsTimerCleanup(0x14000b6c0);
  if (MupiOrderKeyHandleValid != '\0') {
    MupiOrderKeyHandleValid = '\0';
    ZwClose(MupiOrderKeyHandle);
  }
  if (MupiNetworkProviderOrderKeyHandle != 0) {
    ZwClose();
    MupiNetworkProviderOrderKeyHandle = 0;
  }
  puVar4 = auStack_28;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_14000b7c0,1);
  do {
    if ((undefined8 **)DAT_14000b7a8 == &DAT_14000b7a8) {
LAB_1400124c8:
      *(undefined8 *)(puVar4 + -8) = 0x1400124d6;
      ExReleaseResourceLite(&DAT_14000b7c0);
      *(undefined8 *)(puVar4 + -8) = 0x1400124e2;
      KeLeaveCriticalRegion();
      *(undefined8 *)(puVar4 + -8) = 0x1400124f5;
      ExDeleteResourceLite(&DAT_14000b7c0);
      return;
    }
    if (((undefined8 **)DAT_14000b7a8[1] != &DAT_14000b7a8) ||
       (puVar1 = (undefined8 *)*DAT_14000b7a8, (undefined8 *)puVar1[1] != DAT_14000b7a8)) {
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)(3);
      puVar4 = auStack_20;
      goto LAB_1400124c8;
    }
    puVar3 = DAT_14000b7a8 + -1;
    DAT_14000b7a8 = puVar1;
    puVar1[1] = &DAT_14000b7a8;
    MupiFreeProvider((longlong)puVar3);
  } while( true );
}



===== MupDeregisterUncProvider @ 140012508 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MupDeregisterUncProvider(longlong param_1)

{
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_14000b7c0,1);
  *(undefined4 *)(param_1 + 0x44) = 4;
  _DAT_14000b82c = _DAT_14000b82c + -1;
  MupFlushKnownPrefixTable(0,param_1,'\x01');
  DAT_14000b7b8 = DAT_14000b7b8 + 1;
  ExReleaseResourceLite(&DAT_14000b7c0);
  KeLeaveCriticalRegion();
  MupReleaseUncProvider(param_1);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
             &WPP_b8ec61bc8b283db232150b702b34e2f1_Traceguids,param_1);
  }
  return;
}



===== MupFsctlGetUncProviderList @ 1400125bc =====

int MupFsctlGetUncProviderList(longlong param_1)

{
  uint *puVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  ulonglong uVar7;
  uint uVar8;
  undefined8 *puVar9;
  uint uVar10;
  uint uVar11;
  
  piVar3 = *(int **)(param_1 + 0x18);
  uVar7 = 0;
  if (piVar3 == (int *)0x0) {
    iVar6 = -0x3ffffff3;
    goto LAB_140012758;
  }
  uVar8 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 8);
  if (uVar8 < 4) {
    iVar6 = -0x3fffffdd;
    goto LAB_140012758;
  }
  uVar11 = uVar8 - 4;
  uVar10 = 4;
  puVar1 = (uint *)(piVar3 + 1);
  if (uVar8 < 5) {
    uVar11 = 0;
  }
  iVar6 = 0;
  KeEnterCriticalRegion();
  ExAcquireResourceSharedLite(&DAT_14000b7c0,1);
  iVar4 = DAT_14000b828;
  if ((undefined8 **)DAT_14000b7a8 != &DAT_14000b7a8) {
    puVar5 = puVar1;
    puVar9 = DAT_14000b7a8;
    do {
      uVar8 = *(ushort *)(puVar9 + 2) + 0x19 & 0xfffffffc;
      if (uVar11 < uVar8) {
        uVar11 = 0;
        iVar6 = -0x7ffffffb;
      }
      else {
        *puVar5 = uVar8;
        puVar5[1] = *(uint *)((longlong)puVar9 + -4);
        puVar5[2] = *(uint *)((longlong)puVar9 + 0x34);
        puVar5[3] = *(uint *)((longlong)puVar9 + 0x3c);
        puVar5[4] = *(uint *)(puVar9 + 6);
        uVar2 = *(ushort *)(puVar9 + 2);
        memmove((void *)((longlong)puVar5 + 0x16),(void *)puVar9[3],(ulonglong)uVar2);
        *(ushort *)(puVar5 + 5) = uVar2;
        puVar5 = (uint *)((longlong)puVar5 + (ulonglong)*puVar5);
        uVar11 = uVar11 - uVar8;
      }
      puVar9 = (undefined8 *)*puVar9;
      uVar10 = uVar10 + uVar8;
    } while ((undefined8 **)puVar9 != &DAT_14000b7a8);
  }
  ExReleaseResourceLite();
  KeLeaveCriticalRegion();
  if (iVar4 == 0) {
    uVar10 = uVar10 + 0x18;
    if (0x17 < uVar11) {
      puVar1[0] = 0;
      puVar1[1] = 0;
      piVar3[3] = 0;
      piVar3[4] = 0;
      piVar3[5] = 0;
      piVar3[6] = 0;
      *puVar1 = 0x18;
      goto LAB_14001273c;
    }
    iVar6 = -0x7ffffffb;
  }
  else {
LAB_14001273c:
    if (iVar6 == 0) {
      *piVar3 = iVar4;
      uVar7 = (ulonglong)uVar10;
      goto LAB_140012758;
    }
  }
  uVar7 = 4;
  **(uint **)(param_1 + 0x18) = uVar10;
LAB_140012758:
  *(ulonglong *)(param_1 + 0x38) = uVar7;
  return iVar6;
}



===== MupInitUncProviderModule @ 140012778 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 MupInitUncProviderModule(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_1c = 0;
  local_34 = 0;
  local_48 = 0;
  uStack_40 = 0;
  ExInitializeRundownProtection(&UncProviderModuleRundownRef);
  RfsTimerInitialize(0x14000b6c0,param_2,MupiProviderOrderChangeHandler,0);
  _MupProviderTable = 0x907104;
  _DAT_14000b7b0 = &DAT_14000b7a8;
  DAT_14000b7a8 = &DAT_14000b7a8;
  _DAT_14000b7a4 = 1;
  ExInitializeResourceLite(&DAT_14000b7c0);
  DAT_14000b7b8 = 0;
  RtlInitUnicodeString
            (&local_48,
             L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Networkprovider\\Order");
  local_30 = 0;
  local_28 = &local_48;
  local_20 = 0x240;
  local_38 = 0x30;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwOpenKey(&MupiOrderKeyHandle,0x10,&local_38);
  if (-1 < iVar1) {
    MupiOrderKeyHandleValid = 1;
    RtlInitUnicodeString
              (&local_48,
               L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Networkprovider\\ProviderOrder"
              );
    local_30 = 0;
    local_28 = &local_48;
    local_38 = 0x30;
    local_20 = 0x240;
    local_18 = 0;
    uStack_10 = 0;
    iVar1 = ZwOpenKey(&MupiNetworkProviderOrderKeyHandle,0x10,&local_38);
    if (-1 < iVar1) {
      MupiCleanupOrphanProviderOrderRegValues();
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(&DAT_14000b7c0);
      pwVar2 = MupiReadProviderOrderFromRegistry();
      if (pwVar2 != (wchar_t *)0x0) {
        MupiSetupKnownProviderList(pwVar2,'\0');
        ExFreePoolWithTag(pwVar2,0);
      }
      ExReleaseResourceLite(&DAT_14000b7c0);
      KeLeaveCriticalRegion();
      goto LAB_140012932;
    }
  }
  MupiNetworkProviderOrderKeyHandle = 0;
LAB_140012932:
  FsRtlRegisterMupCalls(&MupiFsRtlMupCalls);
  return 0;
}



===== MupRegisterProviderKeyChangeNotification @ 14001295c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MupRegisterProviderKeyChangeNotification(void)

{
  if (MupiOrderKeyHandleValid != '\0') {
    _DAT_14000b690 = MupiOrderRegKeyChangeHandler;
    _DAT_14000b698 = 0;
    _MupiProviderOrderWork = 0;
    ZwNotifyChangeKey(MupiOrderKeyHandle,0,&MupiProviderOrderWork,1,&MupiProviderOrderIoStatus,4,0,0
                      ,0,1);
  }
  return;
}



===== MupRegisterProviderOrderKeyChangeNotification @ 1400129d8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MupRegisterProviderOrderKeyChangeNotification(void)

{
  if (MupiNetworkProviderOrderKeyHandle != 0) {
    _DAT_14000b670 = MupiProviderOrderRegKeyChangeHandler;
    _DAT_14000b678 = 0;
    _MupiNetworkProviderOrderWork = 0;
    ZwNotifyChangeKey(MupiNetworkProviderOrderKeyHandle,0,&MupiNetworkProviderOrderWork,1,
                      &MupiNetworkProviderOrderIoStatus,4,0,0,0,1);
  }
  return;
}



===== MupRegisterUncProvider @ 140012a50 =====

uint MupRegisterUncProvider(longlong param_1)

{
  ushort uVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  uint uVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_28 = 0;
  uStack_20 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_b8ec61bc8b283db232150b702b34e2f1_Traceguids,param_1);
  }
  puVar2 = *(undefined8 **)(param_1 + 0x18);
  lVar3 = *(longlong *)(param_1 + 0xb8);
  local_28 = *puVar2;
  uStack_20 = puVar2[1];
  lVar4 = puVar2[3];
  if (*(byte *)(lVar4 + 3) < 3) {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_14000b7c0);
    puVar5 = MupiFindProviderByName(&local_28);
    if (puVar5 == (undefined8 *)0x0) {
      puVar5 = (undefined8 *)MupiAddKnownProvider((wchar_t *)&local_28,0,(short *)0x0,0x7fffffff);
      uVar6 = ~-(uint)(puVar5 != (undefined8 *)0x0) & 0xc000009a;
    }
    else {
      uVar6 = 0;
      if (*(int *)((longlong)puVar5 + 0x44) != 1) {
        uVar6 = 0xc0000010;
      }
    }
    ExReleaseResourceLite(&DAT_14000b7c0);
    KeLeaveCriticalRegion();
    if (uVar6 == 0) {
      puVar5[0x12] = 0;
      puVar5[0x13] = 0;
      puVar5[0x14] = 0;
      puVar5[0x15] = 0;
      uVar1 = *(ushort *)(lVar4 + 2);
      *(ushort *)(puVar5 + 0x12) = uVar1;
      if (uVar1 < 0x101) {
        uVar6 = MupiProcessPreVistaProviderRegistration
                          ((longlong)puVar5,(byte)*(undefined4 *)(lVar4 + 4));
      }
      else {
        uVar6 = MupiProcessProviderRegistration((longlong)puVar5,puVar2[2],lVar4);
      }
      if (-1 < (int)uVar6) {
        MupiCompleteProviderRegistration((longlong)puVar5,*(longlong *)(lVar3 + 0x30));
      }
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
      WPP_SF_Zdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_b8ec61bc8b283db232150b702b34e2f1_Traceguids,(wchar_t *)&local_28,
                 *(byte *)(lVar4 + 3),*(undefined1 *)(lVar4 + 2));
    }
    uVar6 = 0xc00000bb;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_b8ec61bc8b283db232150b702b34e2f1_Traceguids,param_1,(char)uVar6);
  }
  return uVar6;
}



===== MupiAddKnownProvider @ 140012c4c =====

undefined2 *
MupiAddKnownProvider(wchar_t *param_1,longlong param_2,short *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  
  puVar2 = MupiAllocProvider(param_1,param_2,param_3,param_4);
  if (puVar2 != (undefined2 *)0x0) {
    uVar1 = RtlComputeCrc32(0,*(undefined8 *)(param_1 + 4),*param_1);
    *(undefined4 *)(puVar2 + 0x1c) = uVar1;
    MupiAddProviderToList((longlong)puVar2);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_ZDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
               &WPP_b8ec61bc8b283db232150b702b34e2f1_Traceguids,param_1,(char)param_4,(char)puVar2);
  }
  return puVar2;
}



===== MupiAddProviderToList @ 140012ce8 =====

void MupiAddProviderToList(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar2 = DAT_14000b7a8;
  if ((undefined8 **)DAT_14000b7a8 != &DAT_14000b7a8) {
    do {
      if (*(uint *)(param_1 + 0x3c) < *(uint *)((longlong)puVar2 + 0x34)) break;
      puVar2 = (undefined8 *)*puVar2;
    } while ((undefined8 **)puVar2 != &DAT_14000b7a8);
  }
  puVar1 = (undefined8 *)(param_1 + 8);
  *puVar1 = puVar2;
  *(undefined8 *)(param_1 + 0x10) = puVar2[1];
  *(undefined8 **)puVar2[1] = puVar1;
  puVar2[1] = puVar1;
  DAT_14000b828 = DAT_14000b828 + 1;
  return;
}



===== MupiAllocProvider @ 140012d38 =====

undefined2 * MupiAllocProvider(wchar_t *param_1,longlong param_2,short *param_3,undefined4 param_4)

{
  undefined2 *_Dst;
  longlong lVar1;
  wchar_t wVar2;
  uint uVar3;
  ushort uVar4;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_ZD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,param_1,(char)param_4);
  }
  if (param_1 == (wchar_t *)0x0) {
    wVar2 = L'\0';
  }
  else {
    wVar2 = param_1[1];
  }
  if (param_3 == (short *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = param_3[1];
  }
  uVar3 = (uint)(ushort)wVar2 + uVar4 + 0xb0;
  _Dst = (undefined2 *)ExAllocatePool2(0x102,uVar3,0x6e55754d);
  if (_Dst != (undefined2 *)0x0) {
    memset(_Dst,0,(ulonglong)uVar3);
    _Dst[1] = (short)uVar3;
    *(undefined2 **)(_Dst + 0x10) = _Dst + 0x58;
    *_Dst = 0x7103;
    *(undefined4 *)(_Dst + 2) = 1;
    *(undefined4 *)(_Dst + 0x1e) = param_4;
    _Dst[0xd] = wVar2;
    RtlCopyUnicodeString(_Dst + 0xc,param_1);
    *(undefined4 *)(_Dst + 0x22) = 1;
    if (param_2 == 0) {
      *(undefined8 *)(_Dst + 0x18) = 0;
      *(undefined4 *)(_Dst + 0x14) = 0;
    }
    else {
      lVar1 = ExAllocatePool2(0x102,*(undefined2 *)(param_2 + 2),0x4e50754d);
      *(longlong *)(_Dst + 0x18) = lVar1;
      if (lVar1 == 0) goto LAB_140012e74;
      _Dst[0x15] = *(undefined2 *)(param_2 + 2);
      RtlCopyUnicodeString(_Dst + 0x14,param_2);
    }
    if ((param_3 != (short *)0x0) && (*param_3 != 0)) {
      *(undefined8 *)(_Dst + 0x34) = 0;
      lVar1 = ExAllocatePool2(0x42,0x18,0x2070754d);
      *(longlong *)(_Dst + 0x44) = lVar1;
      if (lVar1 == 0) {
LAB_140012e74:
        MupiFreeProvider((longlong)_Dst);
        return (undefined2 *)0x0;
      }
      KeInitializeEvent(lVar1,0,0);
      _Dst[0x25] = uVar4;
      *(ulonglong *)(_Dst + 0x28) = (ulonglong)(ushort)wVar2 + 0xb0 + (longlong)_Dst;
      RtlCopyUnicodeString(_Dst + 0x24,param_3);
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
             &WPP_b8ec61bc8b283db232150b702b34e2f1_Traceguids,_Dst);
  }
  return _Dst;
}



===== MupiCleanupOrphanProviderOrderRegValues @ 140012f58 =====

void MupiCleanupOrphanProviderOrderRegValues(void)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined4 uVar4;
  int iVar5;
  char local_res8 [8];
  undefined4 local_res10 [2];
  longlong local_res18 [2];
  ushort local_78;
  undefined1 auStack_76 [6];
  longlong lStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 *local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  
  local_res10[0] = 0;
  local_res18[0] = 0;
  uVar4 = 0x400;
  local_res8[0] = '\0';
  local_58 = 0;
  uStack_50 = 0;
  local_38 = 0;
  local_48 = (undefined8 *)0x0;
  uStack_40 = 0;
  uStack_30 = uStack_30 & 0xffffffff00000000;
  local_68 = 0;
  uStack_60 = 0;
  if (MupiNetworkProviderOrderKeyHandle != 0) {
    lVar3 = ExAllocatePool2(0x102,0x400,0x4f50754d);
    iVar1 = 0;
    if (lVar3 != 0) {
LAB_140012fc5:
      do {
        iVar5 = iVar1;
        _local_78 = 0;
        lStack_70 = 0;
        iVar1 = ZwEnumerateValueKey(MupiNetworkProviderOrderKeyHandle,iVar5,0,lVar3,uVar4,
                                    local_res10);
        if (iVar1 == -0x7fffffe6) break;
        if ((iVar1 != -0x7ffffffb) && (iVar1 != -0x3fffffdd)) {
          if (iVar1 < 0) break;
          lStack_70 = lVar3 + 0xc;
          iVar1 = iVar5 + 1;
          _local_78 = CONCAT62(CONCAT42(auStack_76._2_4_,*(undefined2 *)(lVar3 + 8)),
                               *(undefined2 *)(lVar3 + 8));
          if (((*(int *)(lVar3 + 4) != 4) ||
              (iVar2 = MupiProviderIsInstalled(&local_78,local_res8), iVar2 < 0)) ||
             (local_res8[0] != '\0')) goto LAB_140012fc5;
          if (local_res18[0] == 0) {
            RtlInitUnicodeString
                      (&local_68,
                       L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Networkprovider\\ProviderOrder"
                      );
            uStack_50 = 0;
            local_48 = &local_68;
            local_58 = CONCAT44(local_58._4_4_,0x30);
            uStack_40 = CONCAT44(uStack_40._4_4_,0x240);
            local_38 = 0;
            uStack_30 = 0;
            iVar2 = ZwOpenKey(local_res18,2);
            if (iVar2 < 0) goto LAB_140012fc5;
          }
          iVar2 = ZwDeleteValueKey(local_res18[0],&local_78);
          if (-1 < iVar2) {
            iVar1 = iVar5;
          }
          goto LAB_140012fc5;
        }
        ExFreePoolWithTag(lVar3,0x4f50754d);
        uVar4 = local_res10[0];
        lVar3 = ExAllocatePool2(0x102,local_res10[0]);
        iVar1 = iVar5;
      } while (lVar3 != 0);
      if (lVar3 != 0) {
        ExFreePoolWithTag(lVar3,0x4f50754d);
      }
    }
    if (local_res18[0] != 0) {
      ZwClose();
    }
  }
  return;
}



===== MupiCompleteProviderRegistration @ 140013164 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MupiCompleteProviderRegistration(longlong param_1,longlong param_2)

{
  *(longlong *)(param_2 + 0x20) = param_1;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite();
  *(undefined4 *)(param_1 + 0x44) = 3;
  _DAT_14000b82c = _DAT_14000b82c + 1;
  MupFlushKnownPrefixTable(0,0,'\0');
  DAT_14000b7b8 = DAT_14000b7b8 + 1;
  ExReleaseResourceLite(&DAT_14000b7c0);
  KeLeaveCriticalRegion();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
             &WPP_b8ec61bc8b283db232150b702b34e2f1_Traceguids,param_1);
  }
  return;
}



===== MupiCreateNetworkProviderOrderRegValueInRegistry @ 140013214 =====

int MupiCreateNetworkProviderOrderRegValueInRegistry(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_res10 [2];
  undefined8 local_res18;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined8 *local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18 = 0;
  local_1c = 0;
  local_34 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_res10[0] = param_2;
  RtlInitUnicodeString
            (&local_48,
             L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Networkprovider\\ProviderOrder"
            );
  local_30 = 0;
  local_28 = &local_48;
  local_38 = 0x30;
  local_20 = 0x240;
  local_18 = 0;
  uStack_10 = 0;
  iVar1 = ZwOpenKey(&local_res18,2,&local_38);
  if (-1 < iVar1) {
    iVar1 = ZwSetValueKey(local_res18,param_1,0,4,local_res10,4);
    ZwClose(local_res18);
  }
  return iVar1;
}



===== MupiCreateProviderSymbolicLink @ 1400132f4 =====

int MupiCreateProviderSymbolicLink(wchar_t *param_1)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  short *psVar4;
  ulonglong uVar5;
  undefined8 local_38;
  longlong lStack_30;
  ushort local_28;
  ushort local_26;
  undefined4 local_24;
  short *local_20;
  
  psVar4 = (short *)(*(longlong *)(param_1 + 4) + 2);
  uVar5 = (ulonglong)(((ushort)*param_1 >> 1) - 1);
  local_38 = 0;
  lStack_30 = 0;
  local_24 = 0;
  local_20 = MupFindMatchingChar(psVar4,psVar4,uVar5);
  local_20 = local_20 + 1;
  local_28 = ((short)uVar5 - (short)((longlong)local_20 - (longlong)psVar4 >> 1)) * 2;
  uVar1 = (uint)local_28;
  local_26 = local_28;
  lVar3 = ExAllocatePool2(0x102,uVar1 + 0x1a,0x2070754d);
  if (lVar3 == 0) {
    iVar2 = -0x3fffff66;
  }
  else {
    local_38 = (ulonglong)CONCAT42(local_38._4_4_,(short)(uVar1 + 0x1a)) << 0x10;
    lStack_30 = lVar3;
    RtlAppendUnicodeToString(&local_38,L"\\Device\\Mup");
    RtlAppendUnicodeToString(&local_38,L"\\");
    RtlAppendUnicodeToString(&local_38,L";");
    RtlAppendUnicodeStringToString(&local_38,&local_28);
    iVar2 = IoDeleteSymbolicLink(param_1);
    if ((((iVar2 == 0) || (iVar2 == -0x3fffffcc)) &&
        (iVar2 = IoCreateSymbolicLink(param_1,&local_38), iVar2 == 0)) &&
       (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)))) {
      WPP_SF_ZZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                &WPP_b8ec61bc8b283db232150b702b34e2f1_Traceguids,param_1,(wchar_t *)&local_38);
    }
    ExFreePoolWithTag(lVar3,0);
    if (iVar2 == 0) {
      return 0;
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_b8ec61bc8b283db232150b702b34e2f1_Traceguids,iVar2);
  }
  return iVar2;
}



===== MupiFreeProvider @ 1400134cc =====

void MupiFreeProvider(longlong param_1)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
             &WPP_b8ec61bc8b283db232150b702b34e2f1_Traceguids,param_1);
  }
  if (*(longlong *)(param_1 + 0x30) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x30),0);
  }
  if (*(longlong *)(param_1 + 0x88) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x88),0);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== MupiGetProviderInfoFromFileObject @ 140013560 =====

int MupiGetProviderInfoFromFileObject
              (longlong param_1,int param_2,undefined8 *param_3,uint *param_4)

{
  wchar_t wVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 uVar6;
  wchar_t *pwVar7;
  undefined8 *puVar8;
  undefined4 uVar9;
  wchar_t *pwVar10;
  undefined4 local_38 [4];
  
  iVar3 = 0;
  puVar8 = (undefined8 *)0x0;
  local_38[0] = 0;
  pwVar7 = (wchar_t *)0x0;
  uVar4 = 0;
  bVar2 = false;
  if ((param_3 == (undefined8 *)0x0) || (param_4 == (uint *)0x0)) {
    return -0x3ffffff3;
  }
  lVar5 = MupFindFileContext(param_1);
  if (lVar5 == 0) {
    if ((*(uint *)(*(longlong *)(param_1 + 8) + 0x34) & 0x10) == 0) {
      return -0x3fffffcc;
    }
    bVar2 = true;
    uVar6 = IoGetBaseFileSystemDeviceObject(param_1);
    uVar9 = 0x10;
    while( true ) {
      pwVar7 = (wchar_t *)ExAllocatePool2(0x102,uVar9,0x2070754d);
      if (pwVar7 == (wchar_t *)0x0) {
        return -0x3fffff66;
      }
      iVar3 = ObQueryNameString(uVar6,pwVar7,uVar9,local_38);
      if (iVar3 != -0x3ffffffc) break;
      ExFreePoolWithTag(pwVar7,0);
      uVar9 = local_38[0];
    }
    if (iVar3 == 0) {
      puVar8 = MupAcquireUncProviderByName(pwVar7);
      pwVar10 = pwVar7;
      if (puVar8 != (undefined8 *)0x0) goto LAB_140013684;
      iVar3 = -0x3fffffcc;
    }
  }
  else {
    puVar8 = *(undefined8 **)(lVar5 + 0xa8);
    if (puVar8 == (undefined8 *)0x0) {
      return -0x3fffffcc;
    }
    pwVar10 = (wchar_t *)(puVar8 + 3);
LAB_140013684:
    if (param_2 == 1) {
      uVar4 = 4;
      if (*param_4 < 4) {
LAB_1400136f9:
        iVar3 = -0x3fffffdd;
      }
      else {
        *(undefined4 *)param_3 = *(undefined4 *)(puVar8 + 7);
      }
    }
    else if (param_2 == 2) {
      uVar4 = 0x18;
      if (*param_4 < 0x18) goto LAB_1400136f9;
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      *(undefined4 *)param_3 = *(undefined4 *)(puVar8 + 7);
      uVar4 = (ushort)*pwVar10 + 0x18;
      if (*param_4 < uVar4) {
        iVar3 = -0x7ffffffb;
      }
      else {
        param_3[2] = param_3 + 3;
        wVar1 = *pwVar10;
        *(wchar_t *)((longlong)param_3 + 10) = wVar1;
        *(wchar_t *)(param_3 + 1) = wVar1;
        memmove(param_3 + 3,*(void **)(pwVar10 + 4),(ulonglong)(ushort)wVar1);
      }
    }
    else {
      iVar3 = -0x3ffffff3;
    }
    if (pwVar7 == (wchar_t *)0x0) goto LAB_14001371c;
  }
  ExFreePoolWithTag(pwVar7,0);
LAB_14001371c:
  if ((bVar2) && (puVar8 != (undefined8 *)0x0)) {
    MupReleaseUncProvider((longlong)puVar8);
  }
  if ((iVar3 == -0x3fffffdd) || (iVar3 == -0x7ffffffb)) {
    *param_4 = uVar4;
    return iVar3;
  }
  return iVar3;
}



===== MupiLockProviderTriggerStartExclusive @ 140013774 =====

void MupiLockProviderTriggerStartExclusive(longlong param_1)

{
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(param_1 + 0x68,0);
  return;
}



===== MupiOrderRegKeyChangeHandler @ 1400137b0 =====

void MupiOrderRegKeyChangeHandler(void)

{
  char cVar1;
  
  cVar1 = ExAcquireRundownProtection(&UncProviderModuleRundownRef);
  if (cVar1 != '\0') {
    ZwNotifyChangeKey(MupiOrderKeyHandle,0,&MupiProviderOrderWork,1,&MupiProviderOrderIoStatus,4,0,0
                      ,0,1);
    RfsTimerSet(0x14000b6c0);
    ExReleaseRundownProtection(&UncProviderModuleRundownRef);
  }
  return;
}



===== MupiProcessPreVistaProviderRegistration @ 14001384c =====

int MupiProcessPreVistaProviderRegistration(longlong param_1,byte param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 local_res8;
  undefined8 local_res18 [2];
  
  local_res8 = 0;
  local_res18[0] = 0;
  lVar2 = param_1;
  MupiSetProviderFlags(param_1,param_2);
  iVar1 = IoGetDeviceObjectPointer(lVar2 + 0x18,0x20,local_res18,&local_res8);
  if (-1 < iVar1) {
    LOCK();
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    UNLOCK();
    ObReferenceObjectByPointer(local_res8,0x20,0);
    *(undefined8 *)(param_1 + 0xa8) = local_res8;
    *(undefined8 *)(param_1 + 0xa0) = local_res18[0];
  }
  return iVar1;
}



===== MupiProcessProviderRegistration @ 1400138dc =====

int MupiProcessProviderRegistration(longlong param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  undefined8 local_res8;
  undefined8 local_res18 [2];
  
  local_res18[0] = 0;
  local_res8 = 0;
  LOCK();
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  UNLOCK();
  if (*(char *)(param_3 + 3) == '\x01') {
    MupiSetProviderFlags(param_1,(byte)*(undefined4 *)(param_3 + 4));
  }
  else {
    if (*(char *)(param_3 + 3) != '\x02') {
      iVar1 = -0x3fffff1b;
      goto LAB_140013915;
    }
    MupiSetProviderFlags(param_1,(byte)*(undefined4 *)(param_3 + 4));
    *(uint *)(param_1 + 0x98) = *(uint *)(param_3 + 8) & 7;
  }
  iVar1 = MupiCreateProviderSymbolicLink((wchar_t *)(param_1 + 0x18));
  if (-1 < iVar1) {
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 4;
    iVar1 = ObReferenceObjectByPointer(param_2,0x20,0);
    if (-1 < iVar1) {
      *(undefined8 *)(param_1 + 0xa8) = param_2;
      LOCK();
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
      UNLOCK();
      *(undefined4 *)(param_1 + 0x44) = 2;
      iVar1 = IoGetDeviceObjectPointer(param_1 + 0x18,0x20,&local_res8,local_res18);
      MupReleaseUncProvider(param_1);
      if (-1 < iVar1) {
        *(undefined8 *)(param_1 + 0xa0) = local_res8;
        return 0;
      }
    }
  }
LAB_140013915:
  *(undefined4 *)(param_1 + 0x44) = 4;
  MupReleaseUncProvider(param_1);
  return iVar1;
}



===== MupiProviderOrderChangeHandler @ 1400139f0 =====

void MupiProviderOrderChangeHandler(void)

{
  char cVar1;
  wchar_t *pwVar2;
  undefined8 *puVar3;
  
  cVar1 = ExAcquireRundownProtection(&UncProviderModuleRundownRef);
  if (cVar1 != '\0') {
    pwVar2 = MupiReadProviderOrderFromRegistry();
    if (pwVar2 != (wchar_t *)0x0) {
      KeEnterCriticalRegion();
      ExAcquireResourceExclusiveLite(&DAT_14000b7c0,1);
      for (puVar3 = DAT_14000b7a8; (undefined8 **)puVar3 != &DAT_14000b7a8;
          puVar3 = (undefined8 *)*puVar3) {
        *(undefined4 *)((longlong)puVar3 + 0x34) = 0x7fffffff;
        *(undefined1 *)(puVar3 + 7) = 0;
      }
      MupiSetupKnownProviderList(pwVar2,'\x01');
      MupFlushKnownPrefixTable(0,0,'\0');
      DAT_14000b7b8 = DAT_14000b7b8 + 1;
      ExReleaseResourceLite(&DAT_14000b7c0);
      KeLeaveCriticalRegion();
      ExFreePoolWithTag(pwVar2,0);
    }
    ExReleaseRundownProtection(&UncProviderModuleRundownRef);
  }
  return;
}



===== MupiProviderOrderRegKeyChangeHandler @ 140013ae0 =====

void MupiProviderOrderRegKeyChangeHandler(void)

{
  char cVar1;
  
  cVar1 = ExAcquireRundownProtection(&UncProviderModuleRundownRef);
  if (cVar1 != '\0') {
    ZwNotifyChangeKey(MupiNetworkProviderOrderKeyHandle,0,&MupiNetworkProviderOrderWork,1,
                      &MupiNetworkProviderOrderIoStatus,4,0,0,0,1);
    RfsTimerSet(0x14000b6c0);
    ExReleaseRundownProtection(&UncProviderModuleRundownRef);
  }
  return;
}



===== MupiReadNetworkProviderOrderFromRegistry @ 140013b7c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MupiReadNetworkProviderOrderFromRegistry(undefined8 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined4 *local_90;
  undefined4 local_88 [2];
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 *local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulonglong uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined1 local_30 [4];
  int local_2c;
  int local_28;
  undefined4 local_24;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  local_88[0] = 0;
  local_60 = 0;
  local_80 = 0;
  uStack_78 = 0;
  uStack_58 = uStack_58 & 0xffffffff00000000;
  local_70 = (undefined8 *)0x0;
  uStack_68 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  if (MupiNetworkProviderOrderKeyHandle == 0) {
    RtlInitUnicodeString
              (&local_50,
               L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\Networkprovider\\ProviderOrder"
              );
    uStack_78 = 0;
    local_70 = &local_50;
    local_80 = CONCAT44(local_80._4_4_,0x30);
    uStack_68 = CONCAT44(uStack_68._4_4_,0x240);
    local_60 = 0;
    uStack_58 = 0;
    iVar1 = ZwOpenKey(&MupiNetworkProviderOrderKeyHandle,0x10,&local_80);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  RtlInitUnicodeString(&local_40,param_1);
  local_90 = local_88;
  local_98 = 0x18;
  iVar1 = ZwQueryValueKey(MupiNetworkProviderOrderKeyHandle,&local_40,2,local_30);
  if (((-1 < iVar1) && (local_2c == 4)) && (local_28 == 4)) {
    *param_2 = local_24;
  }
  return iVar1;
}



===== MupiReadProviderInfoFromRegistry @ 140013cb4 =====

undefined8 * MupiReadProviderInfoFromRegistry(undefined8 *param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  void *pvVar4;
  int iVar5;
  longlong local_res8;
  undefined8 local_58;
  wchar_t *pwStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 *local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  
  local_28 = 0;
  uStack_20 = uStack_20 & 0xffffffff00000000;
  *param_1 = 0;
  param_1[1] = 0;
  lVar2 = -1;
  param_1[2] = 0;
  param_1[3] = 0;
  local_res8 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = (undefined8 *)0x0;
  uStack_30 = 0;
  local_58 = 0;
  pwStack_50 = (wchar_t *)0x0;
  do {
    lVar2 = lVar2 + 1;
  } while (*(short *)(param_2 + lVar2 * 2) != 0);
  iVar5 = (int)lVar2 * 2 + 0x8c;
  pwVar3 = (wchar_t *)ExAllocatePool2(0x102,iVar5,0x2070754d);
  if (pwVar3 == (wchar_t *)0x0) goto LAB_140013e92;
  local_58 = CONCAT62(CONCAT42(local_58._4_4_,(short)iVar5),0x68);
  builtin_wcsncpy(pwVar3,L"\\Registry\\Machine\\System\\CurrentControlSet\\Services\\",0x34);
  pwStack_50 = pwVar3;
  RtlAppendUnicodeToString(&local_58,param_2);
  RtlAppendUnicodeToString(&local_58,L"\\NetworkProvider");
  local_38 = &local_58;
  local_48 = CONCAT44(local_48._4_4_,0x30);
  uStack_40 = 0;
  uStack_30 = CONCAT44(uStack_30._4_4_,0x240);
  local_28 = 0;
  uStack_20 = 0;
  iVar5 = ZwOpenKey(&local_res8,1,&local_48);
  if (iVar5 < 0) goto LAB_140013e92;
  ExFreePoolWithTag(pwVar3,0);
  pvVar4 = MupiReadRegistryStringValue(local_res8);
  pwVar3 = (wchar_t *)0x0;
  if (pvVar4 == (void *)0x0) goto LAB_140013e92;
  lVar2 = MupiReadRegistryValue(local_res8);
  if (lVar2 != 0) {
    if (*(int *)(lVar2 + 4) == 7) {
      cVar1 = MupiReadRegistryWnfStateName(local_res8,L"TriggerStartNotification",param_1 + 2);
      if (cVar1 != '\0') {
        cVar1 = MupiReadRegistryWnfStateName
                          (local_res8,L"TriggerStartCompleteNotification",param_1 + 3);
        if (cVar1 != '\0') goto LAB_140013e88;
      }
    }
    ExFreePoolWithTag(lVar2,0);
    lVar2 = 0;
  }
LAB_140013e88:
  *param_1 = pvVar4;
  pwVar3 = (wchar_t *)0x0;
  param_1[1] = lVar2;
LAB_140013e92:
  if (local_res8 != 0) {
    ZwClose();
  }
  if (pwVar3 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwVar3,0);
  }
  return param_1;
}



===== MupiReadProviderOrderFromRegistry @ 140013ee4 =====

void * MupiReadProviderOrderFromRegistry(void)

{
  uint uVar1;
  int iVar2;
  void *_Dst;
  uint local_res8 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_res8[0] = 0;
  RtlInitUnicodeString(&local_18,L"ProviderOrder");
  iVar2 = ZwQueryValueKey(MupiOrderKeyHandle,&local_18,1,0,0,local_res8);
  if (iVar2 == -0x3fffffdd) {
    _Dst = (void *)ExAllocatePool2(0x102,(ulonglong)local_res8[0] + 2,0x2070754d);
    if (_Dst == (void *)0x0) {
      return (void *)0x0;
    }
    iVar2 = ZwQueryValueKey(MupiOrderKeyHandle,&local_18,1,_Dst,local_res8[0],local_res8);
    if (((iVar2 == 0) && (*(int *)((longlong)_Dst + 4) == 1)) &&
       (uVar1 = *(uint *)((longlong)_Dst + 0xc), (uVar1 & 1) == 0)) {
      memmove(_Dst,(void *)((ulonglong)*(uint *)((longlong)_Dst + 8) + (longlong)_Dst),
              (ulonglong)uVar1);
      *(undefined2 *)((longlong)_Dst + (ulonglong)(uVar1 >> 1) * 2) = 0;
      return _Dst;
    }
    ExFreePoolWithTag(_Dst,0);
  }
  return (void *)0x0;
}



===== MupiReadRegistryStringValue @ 140014004 =====

void * MupiReadRegistryStringValue(undefined8 param_1)

{
  uint uVar1;
  void *_Dst;
  void *pvVar2;
  
  pvVar2 = (void *)0x0;
  _Dst = (void *)MupiReadRegistryValue(param_1);
  if (_Dst != (void *)0x0) {
    if ((*(int *)((longlong)_Dst + 4) == 1) &&
       (uVar1 = *(uint *)((longlong)_Dst + 0xc), (uVar1 & 1) == 0)) {
      memmove(_Dst,(void *)((ulonglong)*(uint *)((longlong)_Dst + 8) + (longlong)_Dst),
              (ulonglong)uVar1);
      *(undefined2 *)((longlong)_Dst + (ulonglong)(uVar1 >> 1) * 2) = 0;
      pvVar2 = _Dst;
    }
    else {
      ExFreePoolWithTag(_Dst,0);
    }
  }
  return pvVar2;
}



===== MupiReadRegistryValue @ 14001408c =====

longlong MupiReadRegistryValue(undefined8 param_1)

{
  int iVar1;
  longlong lVar2;
  uint local_res18 [4];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res18[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  lVar2 = 0;
  RtlInitUnicodeString(&local_18);
  iVar1 = ZwQueryValueKey(param_1,&local_18,1,0,0,local_res18);
  if (iVar1 == -0x3fffffdd) {
    lVar2 = ExAllocatePool2(0x102,(ulonglong)local_res18[0] + 2,0x2070754d);
    if (lVar2 != 0) {
      iVar1 = ZwQueryValueKey(param_1,&local_18,1,lVar2,local_res18[0],local_res18);
      if (iVar1 < 0) {
        ExFreePoolWithTag(lVar2,0);
        lVar2 = 0;
      }
    }
  }
  return lVar2;
}



===== MupiReadRegistryWnfStateName @ 14001416c =====

undefined1 MupiReadRegistryWnfStateName(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  lVar1 = MupiReadRegistryValue(param_1);
  if (lVar1 != 0) {
    if ((*(int *)(lVar1 + 4) == 3) && (*(int *)(lVar1 + 0xc) == 8)) {
      uVar2 = 1;
      *param_3 = *(undefined8 *)((ulonglong)*(uint *)(lVar1 + 8) + lVar1);
    }
    ExFreePoolWithTag(lVar1,0);
  }
  return uVar2;
}



===== MupiSetProviderFlags @ 1400141c8 =====

void MupiSetProviderFlags(longlong param_1,byte param_2)

{
  ushort uVar1;
  uint *puVar2;
  
  uVar1 = *(ushort *)(param_1 + 0x90);
  puVar2 = (uint *)(param_1 + 0x94);
  if (uVar1 == 0x100) {
    *puVar2 = *puVar2 | 8;
  }
  if ((param_2 & 1) != 0) {
    *puVar2 = *puVar2 | 1;
  }
  if ((param_2 & 2) != 0) {
    *puVar2 = *puVar2 | 2;
  }
  puVar2 = (uint *)(param_1 + 0x94);
  if ((0x100 < uVar1) && ((param_2 & 4) != 0)) {
    *puVar2 = *puVar2 | 0x10;
  }
  if ((0x200 < uVar1) && ((param_2 & 8) != 0)) {
    *puVar2 = *puVar2 | 0x20;
  }
  return;
}



===== MupiSetupKnownProviderList @ 140014238 =====

void MupiSetupKnownProviderList(wchar_t *param_1,char param_2)

{
  longlong *plVar1;
  undefined8 *puVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  longlong lVar6;
  wchar_t *pwVar7;
  wchar_t *pwVar8;
  longlong *plVar9;
  undefined8 *puVar10;
  undefined2 *puVar11;
  longlong lVar12;
  longlong lVar13;
  undefined8 *puVar14;
  uint uVar15;
  undefined1 uVar16;
  uint local_res18 [2];
  char local_res20;
  uint local_a8 [2];
  short local_a0 [4];
  longlong lStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  wchar_t local_80 [16];
  longlong local_60;
  longlong lStack_58;
  longlong local_50;
  longlong lStack_48;
  
  local_res20 = '\0';
  lVar6 = -1;
  uVar15 = 1;
  do {
    lVar6 = lVar6 + 1;
  } while (param_1[lVar6] != L'\0');
  if (lVar6 != 0) {
    local_a8[0] = 0;
    local_res18[0] = local_res18[0] & 0xffffff00;
    do {
      uVar16 = 0;
      for (; (*param_1 == L' ' || (*param_1 == L'\t')); param_1 = param_1 + 1) {
      }
      pwVar7 = wcschr(param_1,L',');
      if (pwVar7 == (wchar_t *)0x0) {
        local_res18[0] = CONCAT31(local_res18[0]._1_3_,1);
      }
      else {
        *pwVar7 = L'\0';
      }
      lVar6 = -1;
      do {
        lVar13 = lVar6;
        lVar6 = lVar13 + 1;
      } while (param_1[lVar6] != L'\0');
      for (pwVar8 = param_1 + lVar13;
          (param_1 < pwVar8 && ((*pwVar8 == L' ' || (*pwVar8 == L'\t')))); pwVar8 = pwVar8 + -1) {
        *pwVar8 = L'\0';
      }
      iVar5 = MupiReadNetworkProviderOrderFromRegistry(param_1,local_a8);
      if (iVar5 < 0) {
        if (iVar5 == -0x3fffffcc) {
          uVar16 = 1;
          local_res20 = '\x01';
          local_a8[0] = uVar15;
        }
        else {
          local_a8[0] = 0x7fffffff;
        }
      }
      else if (uVar15 < local_a8[0]) {
        uVar15 = local_a8[0];
      }
      uVar4 = local_a8[0];
      plVar9 = MupiReadProviderInfoFromRegistry((undefined8 *)local_80,(longlong)param_1);
      lVar6 = *plVar9;
      lStack_58 = plVar9[1];
      local_50 = plVar9[2];
      lStack_48 = plVar9[3];
      local_80[0] = L'\0';
      local_80[1] = L'\0';
      local_80[2] = L'\0';
      local_80[3] = L'\0';
      local_80[4] = L'\0';
      local_80[5] = L'\0';
      local_80[6] = L'\0';
      local_80[7] = L'\0';
      local_60 = lVar6;
      if (lVar6 == 0) {
        RtlInitUnicodeString(local_80,param_1);
        puVar11 = MupiAddKnownProvider(local_80,(longlong)local_80,(short *)0x0,uVar4);
        if (puVar11 != (undefined2 *)0x0) {
          *(uint *)(puVar11 + 0x4a) = *(uint *)(puVar11 + 0x4a) | 0x40;
          *(undefined1 *)(puVar11 + 0x20) = uVar16;
        }
      }
      else {
        local_90 = 0;
        uStack_88 = 0;
        local_a0[0] = 0;
        local_a0[1] = 0;
        local_a0[2] = 0;
        local_a0[3] = 0;
        lStack_98 = 0;
        RtlInitUnicodeString(local_80,lVar6);
        RtlInitUnicodeString(&local_90,param_1);
        lVar13 = lStack_58;
        if (lStack_58 == 0) {
          RtlInitUnicodeString(local_a0,0);
        }
        else {
          lStack_98 = (ulonglong)*(uint *)(lStack_58 + 8) + lStack_58;
          local_a0[1] = *(undefined2 *)(lStack_58 + 0xc);
          local_a0[0] = *(undefined2 *)(lStack_58 + 0xc);
        }
        puVar10 = MupiFindProviderByName(local_80);
        if (puVar10 == (undefined8 *)0x0) {
          puVar11 = MupiAddKnownProvider(local_80,(longlong)&local_90,local_a0,uVar4);
          if (puVar11 != (undefined2 *)0x0) {
            *(undefined1 *)(puVar11 + 0x20) = uVar16;
          }
          if (lVar13 != 0) {
            *(longlong *)(puVar11 + 0x2c) = local_50;
            *(longlong *)(puVar11 + 0x30) = lStack_48;
          }
        }
        else if ((param_2 != '\0') && (*(int *)((longlong)puVar10 + 0x3c) == 0x7fffffff)) {
          plVar9 = puVar10 + 1;
          lVar12 = *plVar9;
          if ((*(longlong **)(lVar12 + 8) != plVar9) ||
             (plVar1 = (longlong *)puVar10[2], (longlong *)*plVar1 != plVar9)) goto LAB_1400145cf;
          *plVar1 = lVar12;
          *(longlong **)(lVar12 + 8) = plVar1;
          DAT_14000b828 = DAT_14000b828 + -1;
          if (puVar10[6] == 0) {
            lVar12 = ExAllocatePool2(0x102,local_90._2_2_);
            puVar10[6] = lVar12;
            if (lVar12 != 0) {
              *(undefined2 *)((longlong)puVar10 + 0x2a) = local_90._2_2_;
              RtlCopyUnicodeString(puVar10 + 5,&local_90);
            }
          }
          *(uint *)((longlong)puVar10 + 0x3c) = uVar4;
          *(undefined1 *)(puVar10 + 8) = uVar16;
          MupiAddProviderToList((longlong)puVar10);
        }
        ExFreePoolWithTag(lVar6,0);
        if (lVar13 != 0) {
          ExFreePoolWithTag(lVar13,0);
        }
      }
      param_1 = pwVar7 + 1;
    } while ((char)local_res18[0] == '\0');
    if (local_res20 != '\0') {
      lVar6 = 0;
      for (lVar13 = MupiGetFirstUncProvider((longlong *)&DAT_14000b7a8); lVar13 != 0;
          lVar13 = MupiGetNextUncProvider(0x14000b7a8,lVar13)) {
        if (*(char *)(lVar13 + 0x40) != '\0') {
          local_res18[0] = 0;
          lVar13 = MupiGetNextKnownPriorityProvider(lVar13,(int *)local_res18);
          MupiAssignProvidersPriorityValue(lVar6,lVar13,local_res18[0]);
          if (lVar13 == 0) break;
        }
        lVar6 = lVar13;
      }
    }
    puVar10 = DAT_14000b7a8;
    while (puVar14 = puVar10, (undefined8 **)puVar14 != &DAT_14000b7a8) {
      puVar10 = (undefined8 *)*puVar14;
      if ((*(uint *)((longlong)puVar14 + 0x8c) & 0x40) != 0) {
        if (((undefined8 *)puVar10[1] != puVar14) ||
           (puVar2 = (undefined8 *)puVar14[1], (undefined8 *)*puVar2 != puVar14)) {
LAB_1400145cf:
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(3);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        *puVar2 = puVar10;
        puVar10[1] = puVar2;
        DAT_14000b828 = DAT_14000b828 + -1;
        MupiFreeProvider((longlong)(puVar14 + -1));
      }
    }
  }
  return;
}



===== MupiTriggerStartWnfCallback @ 1400145e0 =====

undefined8 MupiTriggerStartWnfCallback(void)

{
  longlong in_stack_00000030;
  
  KeSetEvent(*(undefined8 *)(in_stack_00000030 + 0x88),0,0);
  return 0;
}



===== MupiUnlockProviderTriggerStartExclusive @ 140014610 =====

void MupiUnlockProviderTriggerStartExclusive(longlong param_1)

{
  ExReleasePushLockExclusiveEx(param_1 + 0x68,0);
  KeLeaveCriticalRegion();
  return;
}



===== MupiWaitForProviderTriggerStart @ 140014640 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool MupiWaitForProviderTriggerStart(longlong param_1,undefined8 param_2)

{
  longlong *plVar1;
  int iVar2;
  bool bVar3;
  undefined8 local_res8;
  
  local_res8 = 0xfffffffffa0a1f00;
  iVar2 = FsRtlCancellableWaitForSingleObject(*(undefined8 *)(param_1 + 0x88),&local_res8,param_2);
  if (iVar2 == 0x102) {
    KeSetEvent(*(undefined8 *)(param_1 + 0x88),0,0);
  }
  MupiLockProviderTriggerStartExclusive(param_1);
  plVar1 = (longlong *)(param_1 + 0x70);
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    if (*(longlong *)(param_1 + 0x78) != 0) {
      ExUnsubscribeWnfStateChange();
      *(undefined8 *)(param_1 + 0x78) = 0;
    }
    *(undefined8 *)(param_1 + 0x80) = _DAT_fffff78000000008;
    KeResetEvent(*(undefined8 *)(param_1 + 0x88));
  }
  MupiUnlockProviderTriggerStartExclusive(param_1);
  if ((iVar2 == -0x3ffffee0) || (iVar2 == -0x3fffffb5)) {
    bVar3 = false;
  }
  else {
    bVar3 = *(int *)(param_1 + 0x44) == 3;
  }
  return bVar3;
}



===== MupFsctlGetSurrogateProviderList @ 140014714 =====

int MupFsctlGetSurrogateProviderList(longlong param_1)

{
  uint *puVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ulonglong uVar7;
  uint uVar8;
  undefined8 *puVar9;
  uint *puVar10;
  uint uVar11;
  
  piVar3 = *(int **)(param_1 + 0x18);
  uVar7 = 0;
  if (piVar3 == (int *)0x0) {
    iVar6 = -0x3ffffff3;
    goto LAB_140014890;
  }
  uVar8 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 8);
  if (uVar8 < 4) {
    iVar6 = -0x3fffffdd;
    goto LAB_140014890;
  }
  uVar11 = uVar8 - 4;
  uVar5 = 4;
  puVar1 = (uint *)(piVar3 + 1);
  if (uVar8 < 5) {
    uVar11 = 0;
  }
  iVar6 = 0;
  MupiAcquireSurrogateListLockShared();
  iVar4 = DAT_14000b648;
  if ((undefined8 **)DAT_14000b5c8 != &DAT_14000b5c8) {
    puVar9 = DAT_14000b5c8;
    puVar10 = puVar1;
    do {
      uVar8 = *(ushort *)(puVar9 + 4) + 0x19 & 0xfffffffc;
      if (uVar11 < uVar8) {
        uVar11 = 0;
        iVar6 = -0x7ffffffb;
      }
      else {
        *puVar10 = uVar8;
        puVar10[1] = *(uint *)((longlong)puVar9 + -4);
        puVar10[2] = *(uint *)(puVar9 + 2);
        puVar10[3] = *(uint *)(puVar9 + 3);
        puVar10[4] = 0;
        uVar2 = *(ushort *)(puVar9 + 4);
        memmove((void *)((longlong)puVar10 + 0x16),(void *)puVar9[5],(ulonglong)uVar2);
        *(ushort *)(puVar10 + 5) = uVar2;
        puVar10 = (uint *)((longlong)puVar10 + (ulonglong)*puVar10);
        uVar11 = uVar11 - uVar8;
      }
      puVar9 = (undefined8 *)*puVar9;
      uVar5 = uVar5 + uVar8;
    } while ((undefined8 **)puVar9 != &DAT_14000b5c8);
  }
  ExReleaseResourceLite();
  KeLeaveCriticalRegion();
  if (iVar4 == 0) {
    uVar5 = uVar5 + 0x18;
    if (0x17 < uVar11) {
      puVar1[0] = 0;
      puVar1[1] = 0;
      piVar3[3] = 0;
      piVar3[4] = 0;
      piVar3[5] = 0;
      piVar3[6] = 0;
      *puVar1 = 0x18;
      goto LAB_140014876;
    }
    iVar6 = -0x7ffffffb;
  }
  else {
LAB_140014876:
    if (iVar6 == 0) {
      *piVar3 = iVar4;
      uVar7 = (ulonglong)uVar5;
      goto LAB_140014890;
    }
  }
  uVar7 = 4;
  **(uint **)(param_1 + 0x18) = uVar5;
LAB_140014890:
  *(ulonglong *)(param_1 + 0x38) = uVar7;
  return iVar6;
}



===== MupInitSurrogateProviderModule @ 1400148b0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 MupInitSurrogateProviderModule(void)

{
  _MupiSurrogateList = 0x90710c;
  DAT_14000b5d0 = &DAT_14000b5c8;
  DAT_14000b5c8 = &DAT_14000b5c8;
  _DAT_14000b5c4 = 1;
  ExInitializeResourceLite(&DAT_14000b5e0);
  DAT_14000b648 = 0;
  _DAT_14000b5d8 = 0;
  return 0;
}



===== MupSurrogateCloneProvider @ 140014910 =====

undefined8 MupSurrogateCloneProvider(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
                    /* 0x14910  4  MupSurrogateCloneProvider */
  lVar3 = MupFindFileContext(param_2);
  if ((lVar3 == 0) || (lVar4 = MupFindFileContext(param_1), lVar4 == 0)) {
    return 0xc000000d;
  }
  lVar1 = *(longlong *)(lVar4 + 0xa8);
  lVar2 = *(longlong *)(lVar3 + 0xa8);
  if (lVar1 != lVar2) {
    if (lVar2 != 0) {
      if (lVar1 != 0) {
        return 0xc00000bb;
      }
      if (lVar2 != 0) {
        *(longlong *)(lVar3 + 0xb0) = lVar2;
        *(undefined8 *)(lVar3 + 0xa8) = 0;
        goto LAB_1400149b6;
      }
    }
    lVar2 = *(longlong *)(lVar3 + 0xb0);
    if (lVar2 == 0) {
      *(longlong *)(lVar3 + 0xa8) = lVar1;
      LOCK();
      *(int *)(lVar1 + 4) = *(int *)(lVar1 + 4) + 1;
      UNLOCK();
    }
    else {
      if (lVar2 != lVar1) {
        return 0xc00000bb;
      }
      *(longlong *)(lVar3 + 0xa8) = lVar2;
      *(undefined8 *)(lVar3 + 0xb0) = 0;
    }
  }
LAB_1400149b6:
  lVar4 = *(longlong *)(lVar4 + 0xb8);
  lVar1 = *(longlong *)(lVar3 + 0xb8);
  if (lVar4 == lVar1) {
    return 0;
  }
  if (lVar1 != 0) {
    if (lVar4 != 0) {
      return 0xc00000bb;
    }
    if (lVar1 != 0) {
      *(longlong *)(lVar3 + 0xc0) = lVar1;
      *(undefined8 *)(lVar3 + 0xb8) = 0;
      return 0;
    }
  }
  lVar1 = *(longlong *)(lVar3 + 0xc0);
  if (lVar1 == 0) {
    *(longlong *)(lVar3 + 0xb8) = lVar4;
    LOCK();
    *(int *)(lVar4 + 4) = *(int *)(lVar4 + 4) + 1;
    UNLOCK();
    return 0;
  }
  if (lVar1 == lVar4) {
    *(longlong *)(lVar3 + 0xb8) = lVar1;
    *(undefined8 *)(lVar3 + 0xc0) = 0;
    return 0;
  }
  return 0xc00000bb;
}



===== MupSurrogateDeregisterProvider @ 140014a40 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 MupSurrogateDeregisterProvider(wchar_t *param_1,undefined8 param_2,undefined *param_3)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
                    /* 0x14a40  5  MupSurrogateDeregisterProvider */
  local_28 = 0;
  uStack_20 = 0;
  local_18 = 0;
  uVar2 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    param_2 = 0xe;
    param_3 = &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids;
    WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,param_1);
  }
  MupiAcquireSurrogateListLockExclusive();
  puVar1 = MupiFindSurrogateByName(param_1);
  if ((puVar1 == (undefined8 *)0x0) || (*(int *)(puVar1 + 4) == 3)) {
    ExReleaseResourceLite(&DAT_14000b5e0);
    KeLeaveCriticalRegion();
    uVar2 = 0xc0000010;
  }
  else {
    param_3 = (undefined *)0x0;
    param_2 = 1;
    KeInitializeEvent(&local_28);
    *(undefined4 *)(puVar1 + 4) = 3;
    puVar1[0xb] = SystemReserved1[0xf];
    puVar1[0xc] = &local_28;
    MupFlushKnownPrefixTableForSurrogate((longlong)puVar1);
    _DAT_14000b5d8 = _DAT_14000b5d8 + 1;
    ExReleaseResourceLite(&DAT_14000b5e0);
    KeLeaveCriticalRegion();
    MupReleaseSurrogateProvider((longlong)puVar1);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,param_3,puVar1,(char)uVar2);
  }
  return uVar2;
}



===== MupSurrogatePurgeNegativeCacheEntry @ 140014b80 =====

undefined8 MupSurrogatePurgeNegativeCacheEntry(longlong *param_1,wchar_t *param_2)

{
  undefined8 uVar1;
  undefined *puVar2;
  
                    /* 0x14b80  8  MupSurrogatePurgeNegativeCacheEntry */
  if ((char)*(undefined4 *)(*param_1 + 0x10) < '\0') {
    puVar2 = MupGetUncCachePrefixTable(*(undefined **)(param_1[-2] + 0x30));
    MupFlushPrefixEntry(puVar2,param_2);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xc0000010;
  }
  return uVar1;
}



===== MupSurrogateRegisterProvider @ 140014bc0 =====

void MupSurrogateRegisterProvider
               (wchar_t *param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  
                    /* 0x14bc0  9  MupSurrogateRegisterProvider */
  local_24 = 0;
  local_28 = 0x1000018;
  local_20 = param_3;
  local_18 = param_4;
  MupiSurrogateRegisterProviderInternal(param_1,param_2,(undefined *)&local_28);
  return;
}



===== MupSurrogateRegisterProviderEx @ 140014bf0 =====

int MupSurrogateRegisterProviderEx(wchar_t *param_1,int param_2,undefined *param_3)

{
  int iVar1;
  
                    /* 0x14bf0  10  MupSurrogateRegisterProviderEx */
  if (*(ushort *)(param_3 + 2) < 0x200) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
      WPP_SF_Zdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                 &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,param_1,
                 (char)(*(ushort *)(param_3 + 2) >> 8),param_3[2]);
    }
    iVar1 = -0x3fffff45;
  }
  else {
    iVar1 = MupiSurrogateRegisterProviderInternal(param_1,param_2,param_3);
  }
  return iVar1;
}



===== MupSurrogateRestartIo @ 140014c70 =====

ulonglong MupSurrogateRestartIo(longlong param_1)

{
  code *pcVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  
                    /* 0x14c70  12  MupSurrogateRestartIo */
  if (*(int *)(*(longlong *)(*(longlong *)(param_1 + -8) + 0x18) + 0x18) == 1) {
    lVar3 = *(longlong *)(param_1 + -0x10);
    uVar4 = 0;
    lVar5 = *(longlong *)(lVar3 + 0x10);
    if (**(char **)(lVar5 + 0xb8) == '\0') {
      uVar4 = 0xc000000d;
    }
    else {
      iVar2 = MupGetIoStatus(lVar3);
      if ((iVar2 == -0x3fffffea) && (*(uint *)(lVar3 + 0xc) < 10)) {
        *(uint *)(lVar3 + 8) = *(uint *)(lVar3 + 8) | 4;
        iVar2 = *(uint *)(lVar3 + 0xc) + 1;
        *(int *)(lVar3 + 0xc) = iVar2;
        if (iVar2 != 10) goto LAB_140014cfb;
        if (((**(char **)(lVar5 + 0xb8) - 2U & 0xef) == 0) ||
           ((*KdDebuggerEnabled_exref == (code)0x1 &&
            (*KdDebuggerNotPresent_exref == SUB81(uVar4,0))))) {
          pcVar1 = (code *)swi(3);
          uVar4 = (*pcVar1)();
          return uVar4;
        }
      }
      uVar4 = 0xc0000001;
    }
  }
  else {
    uVar4 = 0xc00000bb;
  }
LAB_140014cfb:
  return uVar4 & 0xffffffff;
}



===== MupSurrogateRestoreFileNameInFileObject @ 140014d10 =====

ulonglong MupSurrogateRestoreFileNameInFileObject
                    (longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined2 uVar3;
  ulonglong uVar4;
  
                    /* 0x14d10  13  MupSurrogateRestoreFileNameInFileObject */
  if (-1 < (char)*(undefined4 *)(param_1 + 0x10)) {
    return 0xc0000010;
  }
  uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0xb8) + 0x30);
  lVar2 = MupFindFileContext(uVar1);
  if (lVar2 == 0) {
    uVar4 = 0xc0000225;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc0000225;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) == 0) {
      return 0xc0000225;
    }
    uVar3 = 0x12;
  }
  else {
    if (*(longlong *)(lVar2 + 0x98) == 0) {
      uVar4 = MupRestoreFileNameInFileObject
                        (lVar2,CONCAT71((int7)((ulonglong)param_2 >> 8),1),param_3);
      return uVar4 & 0xffffffff;
    }
    uVar4 = 0xc00000bb;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return 0xc00000bb;
    }
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) == 0) {
      return 0xc00000bb;
    }
    uVar3 = 0x13;
  }
  WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar3,
           &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,uVar1);
  return uVar4;
}



===== MupSurrogateResumeIo @ 140014dd0 =====

void MupSurrogateResumeIo(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  
                    /* 0x14dd0  14  MupSurrogateResumeIo */
  lVar2 = *(longlong *)(param_1 + -0x10);
  iVar1 = *(int *)(param_1 + 0x38);
  lVar3 = *(longlong *)(param_1 + -8);
  if (*(int *)(lVar2 + 0x18) == 2) {
    if (iVar1 != -0x3fffffea) {
      *(int *)(lVar2 + 0x1c) = iVar1;
    }
  }
  else if ((*(int *)(lVar2 + 0x18) == 4) && (iVar1 != -0x3fffffea)) {
    *(int *)(lVar2 + 0x24) = iVar1;
  }
  if ((*(int *)(*(longlong *)(lVar3 + 0x18) + 0x18) == 2) &&
     (*(short *)(lVar2 + 100) != *(short *)(param_1 + 0x4c))) {
    *(short *)(lVar2 + 100) = *(short *)(param_1 + 0x4c);
  }
  MupStateMachine(*(longlong *)(param_1 + -0x10));
  return;
}



===== MupSurrogateSetUndecoratedFileName @ 140014e40 =====

undefined8 MupSurrogateSetUndecoratedFileName(longlong param_1,ushort *param_2)

{
  ushort uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  ushort uVar5;
  longlong lVar6;
  longlong lVar7;
  
                    /* 0x14e40  15  MupSurrogateSetUndecoratedFileName */
  lVar7 = 0;
  if ((*(int *)(*(longlong *)(*(longlong *)(param_1 + -8) + 0x18) + 0x18) == 1) &&
     (*(int *)(*(longlong *)(param_1 + -0x10) + 0x18) == 2)) {
    lVar2 = *(longlong *)(*(longlong *)(param_1 + -8) + 0x20);
    lVar3 = *(longlong *)(lVar2 + 0x90);
    if (*(longlong *)(lVar3 + 0x40) == 0) {
      uVar5 = *param_2;
      if (uVar5 == 0) {
        return 0xc000000d;
      }
      if (*(longlong *)(lVar2 + 0x58) == 0) {
        lVar6 = ExAllocatePool2(0x102,uVar5);
        if (lVar6 == 0) {
          return 0xc000009a;
        }
        if ((*(ushort *)(lVar3 + 0x5a) < uVar5) &&
           (lVar7 = ExAllocatePool2(0x102,uVar5), lVar7 == 0)) {
          ExFreePoolWithTag(lVar6,0);
          return 0xc000009a;
        }
        *(longlong *)(lVar2 + 0x58) = lVar6;
        RtlInitUnicodeString(lVar2 + 0x28,0);
        *(ushort *)(lVar2 + 0x2a) = uVar5;
        *(longlong *)(lVar2 + 0x30) = lVar6;
        MupSaveUnstrippedFileName(lVar2,param_2,'\0');
        MupSaveProviderStrippedFileName(lVar2,'\0');
        uVar1 = *(ushort *)(lVar2 + 0x38);
        MupSaveStrippedFileName(lVar2,'\0');
        *(ushort *)(lVar3 + 0x58) = uVar1;
        if (lVar7 == 0) {
          uVar5 = *(short *)(lVar3 + 0x5a) - uVar1;
          if (uVar5 != 0) {
            memset((void *)(*(longlong *)(lVar3 + 0x60) + (ulonglong)(uVar1 >> 1) * 2),0,
                   (ulonglong)uVar5);
          }
        }
        else {
          uVar4 = *(undefined8 *)(lVar3 + 0x60);
          *(longlong *)(lVar3 + 0x60) = lVar7;
          *(ushort *)(lVar3 + 0x5a) = uVar5;
          ExFreePoolWithTag(uVar4,0);
        }
        memmove(*(void **)(lVar3 + 0x60),*(void **)(lVar2 + 0x40),(ulonglong)uVar1);
        return 0;
      }
    }
  }
  return 0xc00000bb;
}



===== MupiAcquireSurrogateListLockExclusive @ 140014fe4 =====

void MupiAcquireSurrogateListLockExclusive(void)

{
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_14000b5e0,1);
  return;
}



===== MupiAddSurrogateToList @ 140015018 =====

void MupiAddSurrogateToList(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  longlong *plVar4;
  
  plVar4 = DAT_14000b5c8;
  if (((longlong **)DAT_14000b5c8 != &DAT_14000b5c8) && (*(int *)(param_1 + 0x18) != 1)) {
    plVar1 = (longlong *)(param_1 + 8);
    if (*(int *)(param_1 + 0x18) != 2) {
      if ((longlong **)*DAT_14000b5d0 != &DAT_14000b5c8) goto LAB_1400150a3;
      *plVar1 = (longlong)&DAT_14000b5c8;
      *(longlong **)(param_1 + 0x10) = DAT_14000b5d0;
      *DAT_14000b5d0 = (longlong)plVar1;
      DAT_14000b5d0 = plVar1;
      goto LAB_140015076;
    }
    if ((int)DAT_14000b5c8[2] == 1) {
      lVar2 = *DAT_14000b5c8;
      if (*(longlong **)(lVar2 + 8) == DAT_14000b5c8) {
        *plVar1 = lVar2;
        *(longlong **)(param_1 + 0x10) = plVar4;
        *(longlong **)(lVar2 + 8) = plVar1;
        *plVar4 = (longlong)plVar1;
        goto LAB_140015076;
      }
      goto LAB_1400150a3;
    }
  }
  plVar4 = (longlong *)(param_1 + 8);
  if ((longlong **)DAT_14000b5c8[1] != &DAT_14000b5c8) {
LAB_1400150a3:
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  *plVar4 = (longlong)DAT_14000b5c8;
  *(longlong ***)(param_1 + 0x10) = &DAT_14000b5c8;
  DAT_14000b5c8[1] = (longlong)plVar4;
  DAT_14000b5c8 = plVar4;
LAB_140015076:
  DAT_14000b648 = DAT_14000b648 + 1;
  return;
}



===== MupiAllocSurrogateProvider @ 1400150b0 =====

undefined2 * MupiAllocSurrogateProvider(int param_1)

{
  undefined2 *_Dst;
  uint uVar1;
  
  uVar1 = param_1 + 0x78;
  _Dst = (undefined2 *)ExAllocatePool2(0x102,uVar1,0x7053754d);
  if (_Dst != (undefined2 *)0x0) {
    memset(_Dst,0,(ulonglong)uVar1);
    *_Dst = 0x710d;
    *(undefined4 *)(_Dst + 2) = 1;
    *(undefined4 *)(_Dst + 0x10) = 1;
    _Dst[1] = (short)uVar1;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1f,
             &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,_Dst);
  }
  return _Dst;
}



===== MupiFindSurrogateByNameAndType @ 140015154 =====

ulonglong MupiFindSurrogateByNameAndType(undefined8 param_1,int param_2)

{
  byte bVar1;
  char cVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  bVar1 = 0;
  puVar4 = (undefined8 *)0x0;
  puVar3 = DAT_14000b5c8;
  do {
    if ((undefined8 **)puVar3 == &DAT_14000b5c8) {
LAB_1400151c2:
      return -(ulonglong)bVar1 & (ulonglong)puVar4;
    }
    puVar4 = puVar3 + -1;
    cVar2 = RtlEqualUnicodeString(param_1,puVar3 + 4,1);
    if (((cVar2 != '\0') && (param_2 == *(int *)(puVar3 + 2))) ||
       ((param_2 - 1U < 2 && (param_2 == *(int *)(puVar3 + 2))))) {
      bVar1 = 1;
      goto LAB_1400151c2;
    }
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



===== MupiFreeSurrogateProvider @ 1400151ec =====

void MupiFreeSurrogateProvider(undefined8 param_1)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x20,
             &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,param_1);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== MupiSurrogateRegisterProviderInternal @ 140015248 =====

int MupiSurrogateRegisterProviderInternal(wchar_t *param_1,int param_2,undefined *param_3)

{
  undefined2 *puVar1;
  int iVar2;
  ulonglong uVar3;
  undefined2 *puVar4;
  undefined *puVar5;
  
  puVar5 = param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    puVar5 = &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids;
    WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,param_1);
  }
  MupiAcquireSurrogateListLockExclusive();
  uVar3 = MupiFindSurrogateByNameAndType(param_1,param_2);
  if (uVar3 == 0) {
    puVar4 = MupiAllocSurrogateProvider((uint)(ushort)*param_1);
    if (puVar4 == (undefined2 *)0x0) {
      iVar2 = -0x3fffff66;
      goto LAB_14001536a;
    }
    *(int *)(puVar4 + 0xc) = param_2;
    puVar1 = puVar4 + 0x14;
    puVar4[0xe] = *(undefined2 *)(param_3 + 2);
    *puVar1 = 0;
    puVar4[0x15] = *param_1;
    *(undefined2 **)(puVar4 + 0x18) = puVar4 + 0x3c;
    RtlCopyUnicodeString(puVar1,param_1);
    if (*(char *)((longlong)puVar4 + 0x1d) == '\x01') {
      *(undefined8 *)(puVar4 + 0x24) = *(undefined8 *)(param_3 + 8);
      *(undefined8 *)(puVar4 + 0x28) = *(undefined8 *)(param_3 + 0x10);
LAB_14001541a:
      iVar2 = IoGetDeviceObjectPointer(puVar1,0x20,puVar4 + 0x20,puVar4 + 0x1c);
      if (iVar2 == 0) {
        *(undefined4 *)(puVar4 + 0x10) = 2;
        if ((*(int *)(puVar4 + 0xc) - 1U & 0xfffffffd) == 0) {
          LOCK();
          MupiCachingAndGenericSurrogateCount = MupiCachingAndGenericSurrogateCount + 1;
          UNLOCK();
        }
        MupiAddSurrogateToList((longlong)puVar4);
        iVar2 = 0;
        goto LAB_14001536a;
      }
    }
    else {
      if (*(char *)((longlong)puVar4 + 0x1d) == '\x02') {
        *(undefined8 *)(puVar4 + 0x24) = *(undefined8 *)(param_3 + 8);
        *(undefined8 *)(puVar4 + 0x28) = *(undefined8 *)(param_3 + 0x10);
        *(uint *)(puVar4 + 0x36) = *(uint *)(param_3 + 0x18) & 7;
        if (0x200 < *(ushort *)(param_3 + 2)) {
          *(uint *)(puVar4 + 0x38) = *(uint *)(param_3 + 0x1c) & 1;
        }
        goto LAB_14001541a;
      }
      iVar2 = -0x3fffff1b;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
        WPP_SF_ZddD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)(byte)param_3[3],puVar5,
                    param_1,param_3[3],param_3[2],0xe5);
      }
    }
    MupiFreeSurrogateProvider(puVar4);
  }
  else {
    iVar2 = -0x3ffffff0;
  }
  puVar4 = (undefined2 *)0x0;
LAB_14001536a:
  ExReleaseResourceLite(&DAT_14000b5e0);
  KeLeaveCriticalRegion();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_ZqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,param_1,(char)puVar4,(char)iVar2);
  }
  return iVar2;
}



===== MupAttemptToLoadRegistryConfigurationRunOnce @ 140015470 =====

undefined8 MupAttemptToLoadRegistryConfigurationRunOnce(undefined8 param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  int iVar4;
  ulonglong uVar5;
  
  lVar3 = *param_2;
  plVar1 = param_2 + 4;
  iVar4 = MupiOpenUncHardeningRegistryKey(plVar1);
  if (-1 < iVar4) {
    plVar2 = (longlong *)(lVar3 + 8);
    *(longlong **)(lVar3 + 0x10) = plVar2;
    *plVar2 = (longlong)plVar2;
    uVar5 = MupiLoadUncHardeningDefaultsToList((longlong)plVar2);
    iVar4 = (int)uVar5;
    if (-1 < iVar4) {
      uVar5 = MupiLoadUncHardeningConfigurationToList(*plVar1,plVar2);
      iVar4 = (int)uVar5;
      if ((-1 < iVar4) &&
         (iVar4 = MupiRegisterUncHardeningConfigurationRegistryChangeNotification((longlong)param_2)
         , -1 < iVar4)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                  &WPP_64aa67e67b403fd701aa854e8be64937_Traceguids);
        }
        return 1;
      }
    }
  }
  MupiFreeUncHardeningConfigurationEntryList((longlong *)(lVar3 + 8));
  if (*plVar1 != 0) {
    ZwClose();
    *plVar1 = 0;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
             &WPP_64aa67e67b403fd701aa854e8be64937_Traceguids,iVar4);
  }
  return 0;
}



===== MupFsctlGetUncHardeningPrefixTable @ 14001558c =====

void MupFsctlGetUncHardeningPrefixTable(longlong param_1)

{
  uint uVar1;
  void *_Dst;
  int iVar2;
  ulonglong uVar3;
  void *pvVar4;
  uint local_res8 [2];
  
  _Dst = *(void **)(param_1 + 0x18);
  local_res8[0] = 0;
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 8);
  pvVar4 = _Dst;
  memset(_Dst,0,(ulonglong)uVar1);
  uVar3 = MupiPackUncHardeningPrefixTableForFsctl((ulonglong)pvVar4,uVar1,(longlong)_Dst,local_res8)
  ;
  iVar2 = (int)uVar3;
  if (((-1 < iVar2) || (iVar2 == -0x7ffffffb)) || (iVar2 == -0x3fffffdd)) {
    *(ulonglong *)(param_1 + 0x38) = (ulonglong)local_res8[0];
  }
  return;
}



===== MupFsctlQueryUncHardeningConfigurationForPath @ 140015600 =====

int MupFsctlQueryUncHardeningConfigurationForPath(longlong param_1)

{
  ulonglong uVar1;
  ushort uVar2;
  uint uVar3;
  uint *puVar4;
  undefined8 *puVar5;
  int iVar6;
  ulonglong uVar7;
  longlong local_res8;
  ulonglong local_18;
  short *psStack_10;
  
  local_res8 = 0;
  if (7 < *(uint *)(*(longlong *)(param_1 + 0xb8) + 8)) {
    uVar3 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 0x10);
    if (3 < uVar3) {
      puVar4 = *(uint **)(param_1 + 0x18);
      if ((9 < *puVar4) && (*puVar4 <= uVar3)) {
        uVar7 = (ulonglong)puVar4[1];
        uVar2 = (ushort)puVar4[2];
        uVar1 = uVar2 + uVar7;
        if ((uVar7 <= uVar1) &&
           (((uVar1 < 0x100000000 && (uVar1 <= uVar3)) &&
            (psStack_10 = (short *)(uVar7 + (longlong)puVar4), ((ulonglong)psStack_10 & 1) == 0))))
        {
          local_18 = (ulonglong)CONCAT22(uVar2,uVar2);
          if (((uVar2 < 5) || (*psStack_10 != 0x5c)) || (psStack_10[1] != 0x5c)) {
            iVar6 = -0x3ffffff3;
          }
          else {
            iVar6 = MupiCreatePrefixEntryForPathFromConfiguration
                              ((ulonglong)uVar3,(ushort *)&local_18,&local_res8);
            if (-1 < iVar6) {
              puVar5 = *(undefined8 **)(param_1 + 0x18);
              iVar6 = 0;
              *puVar5 = 0;
              *(undefined4 *)puVar5 = 8;
              *(undefined4 *)((longlong)puVar5 + 4) = *(undefined4 *)(local_res8 + 0x58);
              *(undefined8 *)(param_1 + 0x38) = 8;
            }
          }
          if (local_res8 == 0) {
            return iVar6;
          }
          MupiDereferenceUncHardeningPrefixEntry(local_res8);
          return iVar6;
        }
      }
    }
  }
  return -0x3ffffff3;
}



===== MupInitializeUncHardeningModule @ 140015710 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MupInitializeUncHardeningModule(void)

{
  undefined8 uVar1;
  
  _DAT_14000b248 = 0;
  uVar1 = 0;
  _DAT_14000b258 = &DAT_14000b250;
  DAT_14000b250 = &DAT_14000b250;
  memset(&DAT_14000b268,0,0x110);
  _DAT_14000b260 = &DAT_14000b248;
  ExInitializeRundownProtection(&DAT_14000b270);
  RtlRunOnceInitialize(&DAT_14000b268);
  RfsTimerInitialize(0x14000b2b8,uVar1,MupRefreshUncHardeningConfigurationTimerCallback,
                     &DAT_14000b260);
  _DAT_14000b228 = 0;
  RtlInitializeUnicodePrefix(&DAT_14000b230);
  MupiTryStartUncHardeningRegistryWatcher();
  return;
}



===== MupRefreshUncHardeningConfigurationTimerCallback @ 1400157c0 =====

void MupRefreshUncHardeningConfigurationTimerCallback(undefined8 param_1,longlong *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  char cVar3;
  int iVar4;
  ulonglong uVar5;
  longlong local_res10;
  undefined8 ****local_48;
  undefined8 ****local_40;
  undefined8 ****local_38;
  undefined8 ****local_30;
  
  lVar2 = *param_2;
  local_40 = &local_48;
  local_res10 = 0;
  local_48 = &local_48;
  local_30 = &local_38;
  local_38 = &local_38;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
            &WPP_64aa67e67b403fd701aa854e8be64937_Traceguids);
  }
  KeEnterCriticalRegion();
  ExAcquirePushLockSharedEx(param_2 + 3,0);
  plVar1 = param_2 + 4;
  if (*plVar1 == 0) {
    cVar3 = ExAcquireRundownProtection(param_2 + 2);
    if (cVar3 != '\0') {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_64aa67e67b403fd701aa854e8be64937_Traceguids);
      }
      iVar4 = MupiOpenUncHardeningRegistryKey(plVar1);
      if (-1 < iVar4) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
                  &WPP_64aa67e67b403fd701aa854e8be64937_Traceguids);
        }
        iVar4 = MupiRegisterUncHardeningConfigurationRegistryChangeNotification((longlong)param_2);
        if (iVar4 < 0) {
          ZwClose(*plVar1);
          *plVar1 = 0;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
            WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
                     &WPP_64aa67e67b403fd701aa854e8be64937_Traceguids,iVar4);
          }
        }
      }
      MupiArmUncHardeningConfigurationRefreshTimer((longlong)param_2);
      ExReleaseRundownProtection(param_2 + 2);
    }
  }
  else {
    iVar4 = ObDuplicateObject(*(undefined8 *)PsInitialSystemProcess_exref,*plVar1,
                              *(undefined8 *)PsInitialSystemProcess_exref,&local_res10,0,0x200,2,0);
    if (((iVar4 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_64aa67e67b403fd701aa854e8be64937_Traceguids,iVar4);
    }
  }
  ExReleasePushLockSharedEx(param_2 + 3,0);
  KeLeaveCriticalRegion();
  if (local_res10 != 0) {
    uVar5 = Feature_2966577467__private_IsEnabledDeviceUsageNoInline();
    if (((int)uVar5 == 0) ||
       (uVar5 = MupiLoadUncHardeningDefaultsToList((longlong)&local_48), -1 < (int)uVar5)) {
      uVar5 = MupiLoadUncHardeningConfigurationToList(*plVar1,(longlong *)&local_48);
      iVar4 = (int)uVar5;
      if (((iVar4 + 0x80000000U & 0x80000000) == 0) && (iVar4 != -0x3ffffe84)) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
                   &WPP_64aa67e67b403fd701aa854e8be64937_Traceguids,iVar4);
        }
      }
      else {
        KeEnterCriticalRegion();
        ExAcquirePushLockExclusiveEx(lVar2,0);
        MupTransferListEntries((longlong *)&local_38,(longlong *)(lVar2 + 8));
        MupTransferListEntries((longlong *)(lVar2 + 8),(longlong *)&local_48);
        ExReleasePushLockExclusiveEx(lVar2,0);
        KeLeaveCriticalRegion();
      }
    }
    if (local_res10 != 0) {
      ZwClose();
    }
  }
  MupiFreeUncHardeningConfigurationEntryList((longlong *)&local_38);
  MupiFreeUncHardeningConfigurationEntryList((longlong *)&local_48);
  return;
}



===== MupiArmUncHardeningConfigurationRefreshTimer @ 140015af0 =====

void MupiArmUncHardeningConfigurationRefreshTimer(longlong param_1)

{
  RfsTimerSet(param_1 + 0x58);
  return;
}



===== MupiOpenUncHardeningRegistryKey @ 140015b2c =====

int MupiOpenUncHardeningRegistryKey(undefined8 *param_1)

{
  int iVar1;
  ushort uVar2;
  undefined8 local_res10;
  ushort local_68 [4];
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  undefined8 local_50;
  ushort *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_58 = 0x30;
  local_48 = (ushort *)&MUPI_HARDENED_PATHS_REGISTRY_KEY_PATH;
  local_40 = 0x240;
  local_50 = 0;
  local_38 = 0;
  uStack_30 = 0;
  iVar1 = ZwOpenKey(0,0x20019,&local_58);
  if (iVar1 == -0x3fffffcc) {
    uVar2 = 0;
    local_68[0] = 0;
    local_68[1] = 0xa8;
    local_68[2] = 0;
    local_68[3] = 0;
    uStack_60 = 0x40008b20;
    uStack_5c = 1;
    while( true ) {
      if (0xa6 < local_68[0]) break;
      local_res10 = 0;
      while ((local_68[0] + 2 < 0xa7 &&
             (*(short *)(CONCAT44(uStack_5c,uStack_60) + (ulonglong)(local_68[0] >> 1) * 2) != 0x5c)
             )) {
        local_68[0] = local_68[0] + 2;
      }
      if ((ushort)(local_68[0] - 1) < 0xa5) {
        uVar2 = uVar2 + 1;
      }
      if (4 < uVar2) {
        local_48 = local_68;
        local_58 = CONCAT44(local_58._4_4_,0x30);
        local_50 = 0;
        local_38 = 0;
        uStack_30 = 0;
        local_40 = CONCAT44(local_40._4_4_,0x240);
        iVar1 = ZwCreateKey(&local_res10,0x20019,&local_58,0,0,0,0);
        if (iVar1 < 0) goto LAB_140015ca7;
        if (local_68[0] == 0xa6) {
          *param_1 = local_res10;
          goto LAB_140015c81;
        }
        ZwClose(local_res10);
      }
      local_68[0] = local_68[0] + 2;
    }
  }
  if (iVar1 < 0) {
LAB_140015ca7:
    *param_1 = 0;
  }
  else {
LAB_140015c81:
    iVar1 = 0;
  }
  return iVar1;
}



===== MupiRegisterUncHardeningConfigurationRegistryChangeNotification @ 140015cb4 =====

void MupiRegisterUncHardeningConfigurationRegistryChangeNotification(longlong param_1)

{
  *(code **)(param_1 + 0x38) = MupiUncHardeningRegistryWatcherKeyChangeNotification;
  *(longlong *)(param_1 + 0x40) = param_1;
  *(undefined8 *)(param_1 + 0x28) = 0;
  ZwNotifyChangeKey(*(undefined8 *)(param_1 + 0x20),0,(undefined8 *)(param_1 + 0x28),1,
                    param_1 + 0x48,4,0,0,0,1);
  return;
}



===== MupiUncHardeningRegistryWatcherKeyChangeNotification @ 140015d20 =====

void MupiUncHardeningRegistryWatcherKeyChangeNotification(longlong param_1)

{
  longlong *plVar1;
  char cVar2;
  int iVar3;
  undefined4 local_res8 [2];
  
  local_res8[0] = 0;
  cVar2 = ExAcquireRundownProtection(param_1 + 0x10);
  if (cVar2 != '\0') {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_64aa67e67b403fd701aa854e8be64937_Traceguids);
    }
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(param_1 + 0x18,0);
    plVar1 = (longlong *)(param_1 + 0x20);
    iVar3 = ZwQueryKey(*plVar1,4,0,0,local_res8);
    if ((iVar3 == -0x3ffffe84) || (iVar3 == -0x3ffffbdb)) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                &WPP_64aa67e67b403fd701aa854e8be64937_Traceguids);
      }
      if (*plVar1 != 0) {
        ZwClose();
        *plVar1 = 0;
      }
      iVar3 = MupiOpenUncHardeningRegistryKey(plVar1);
      if (((iVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                 &WPP_64aa67e67b403fd701aa854e8be64937_Traceguids,iVar3);
      }
    }
    if (*plVar1 != 0) {
      iVar3 = MupiRegisterUncHardeningConfigurationRegistryChangeNotification(param_1);
      if (iVar3 < 0) {
        ZwClose(*plVar1);
        *plVar1 = 0;
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
          WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                   &WPP_64aa67e67b403fd701aa854e8be64937_Traceguids,iVar3);
        }
      }
    }
    MupiArmUncHardeningConfigurationRefreshTimer(param_1);
    ExReleasePushLockExclusiveEx(param_1 + 0x18,0);
    KeLeaveCriticalRegion();
    ExReleaseRundownProtection(param_1 + 0x10);
  }
  return;
}



===== MupiApplyUncHardeningConfigurationEntryToPrefixEntry @ 140015f00 =====

void MupiApplyUncHardeningConfigurationEntryToPrefixEntry(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  uVar1 = 0;
  if (*(int *)(param_1 + 0x50) < 1) {
    uVar1 = 0;
    if (*(int *)(param_1 + 0x50) < 0) {
      uVar1 = 1;
    }
  }
  else {
    uVar2 = 1;
  }
  if (*(int *)(param_1 + 0x54) < 1) {
    if (*(int *)(param_1 + 0x54) < 0) {
      uVar1 = uVar1 | 2;
    }
  }
  else {
    uVar2 = uVar2 | 2;
  }
  if (*(int *)(param_1 + 0x58) < 1) {
    if (*(int *)(param_1 + 0x58) < 0) {
      uVar1 = uVar1 | 4;
    }
  }
  else {
    uVar2 = uVar2 | 4;
  }
  *(uint *)(param_2 + 0x58) = ~uVar1 & *(uint *)(param_2 + 0x58) | uVar2;
  return;
}



===== MupiCreateUncHardeningConfigurationEntry @ 140015f5c =====

ulonglong MupiCreateUncHardeningConfigurationEntry
                    (short *param_1,ushort *param_2,undefined8 *param_3)

{
  undefined4 *puVar1;
  short sVar2;
  undefined4 *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ushort uVar6;
  
  if (param_1 == (short *)0x0) {
    sVar2 = 0;
  }
  else {
    sVar2 = *param_1;
  }
  if (param_2 == (ushort *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = *param_2;
  }
  *param_3 = 0;
  if ((sVar2 == 0) && (uVar6 == 0)) {
    uVar5 = 0xc000000d;
  }
  else {
    puVar3 = (undefined4 *)ExAllocatePool2(0x102,(ulonglong)uVar6 + 0x60,0x4855754d);
    if (puVar3 == (undefined4 *)0x0) {
      uVar5 = 0xc0000017;
    }
    else {
      memset(puVar3 + 4,0,0x50);
      puVar1 = puVar3 + 2;
      *puVar3 = 0x60710e;
      puVar3[1] = 1;
      *(undefined4 **)(puVar3 + 4) = puVar1;
      *(undefined4 **)puVar1 = puVar1;
      uVar4 = MupInitializeServerName((longlong)param_1,puVar3 + 6);
      uVar5 = uVar4 & 0xffffffff;
      if ((int)uVar4 < 0) {
        MupiDereferenceUncHardeningConfigurationEntry((longlong)puVar3);
      }
      else {
        if (uVar6 != 0) {
          *(ushort *)((longlong)puVar3 + 0x42) = uVar6;
          *(undefined4 **)(puVar3 + 0x12) = puVar3 + 0x18;
          *(ushort *)(puVar3 + 0x10) = uVar6;
          memmove(puVar3 + 0x18,*(void **)(param_2 + 4),(ulonglong)uVar6);
        }
        *param_3 = puVar3;
        uVar5 = 0;
      }
    }
  }
  return uVar5;
}



===== MupiDereferenceUncHardeningConfigurationEntry @ 140016078 =====

void MupiDereferenceUncHardeningConfigurationEntry(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    RfsServerNameCleanup((int *)(param_1 + 0x18));
    ExFreePoolWithTag(param_1,0x4855754d);
  }
  return;
}



===== MupiFindOrCreateUncHardeningConfigurationEntry @ 1400160b8 =====

ulonglong MupiFindOrCreateUncHardeningConfigurationEntry
                    (longlong *param_1,short *param_2,ushort *param_3,undefined8 param_4,
                    longlong *param_5)

{
  code *pcVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  longlong *plVar5;
  longlong local_18 [2];
  
  local_18[0] = 0;
  *param_5 = 0;
  uVar2 = MupiFindUncHardeningConfigurationEntry(param_1,(longlong)param_2,param_3,param_4,local_18)
  ;
  uVar3 = (ulonglong)uVar2;
  if (-1 < (int)uVar2) {
    if (local_18[0] == 0) {
      uVar3 = MupiCreateUncHardeningConfigurationEntry(param_2,param_3,local_18);
      if ((int)uVar3 < 0) {
        return uVar3 & 0xffffffff;
      }
      plVar5 = (longlong *)param_1[1];
      puVar4 = (undefined8 *)(local_18[0] + 8);
      if ((longlong *)*plVar5 != param_1) {
        puVar4 = (undefined8 *)0x3;
        pcVar1 = (code *)swi(0x29);
        local_18[0] = (*pcVar1)();
      }
      *puVar4 = param_1;
      puVar4[1] = plVar5;
      *plVar5 = (longlong)puVar4;
      param_1[1] = (longlong)puVar4;
    }
    uVar3 = 0;
    *param_5 = local_18[0];
  }
  return uVar3;
}



===== MupiFindUncHardeningConfigurationEntry @ 140016164 =====

int MupiFindUncHardeningConfigurationEntry
              (longlong *param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
              longlong *param_5)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint local_38 [12];
  
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  *param_5 = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[6] = 0;
  local_38[7] = 0;
  local_38[8] = 0;
  local_38[9] = 0;
  lVar4 = 0;
  uVar3 = MupInitializeServerName(param_2,(int *)local_38);
  iVar2 = (int)uVar3;
  if (-1 < iVar2) {
    for (lVar4 = MupiGetFirstUncHardeningConfigurationEntry(param_1); lVar4 != 0;
        lVar4 = MupiGetNextUncHardeningConfigurationEntry((longlong)param_1,lVar4)) {
      uVar3 = RfsServerNameEqualEx((uint *)(lVar4 + 0x18),local_38,'\x01');
      if ((char)uVar3 != '\0') {
        cVar1 = RtlEqualUnicodeString(lVar4 + 0x40,param_3,1);
        if (cVar1 != '\0') break;
      }
    }
    iVar2 = 0;
  }
  RfsServerNameCleanup((int *)local_38);
  if (-1 < iVar2) {
    *param_5 = lVar4;
  }
  return iVar2;
}



===== MupiFreeUncHardeningConfigurationEntryList @ 14001623c =====

void MupiFreeUncHardeningConfigurationEntryList(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  longlong lVar5;
  
  do {
    lVar5 = MupiGetFirstUncHardeningConfigurationEntry(param_1);
    if (lVar5 == 0) {
      return;
    }
    plVar1 = (longlong *)(lVar5 + 8);
    plVar2 = (longlong *)*plVar1;
    if (plVar2 != plVar1) {
      if (((longlong *)plVar2[1] != plVar1) ||
         (plVar3 = *(longlong **)(lVar5 + 0x10), (longlong *)*plVar3 != plVar1)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      *plVar3 = (longlong)plVar2;
      plVar2[1] = (longlong)plVar3;
      *(longlong **)(lVar5 + 0x10) = plVar1;
      *plVar1 = (longlong)plVar1;
    }
    MupiDereferenceUncHardeningConfigurationEntry(lVar5);
  } while( true );
}



===== MupiGetFirstOrNextUncHardeningPrefixEntry @ 14001629c =====

ulonglong MupiGetFirstOrNextUncHardeningPrefixEntry(void)

{
  longlong lVar1;
  
  lVar1 = RtlNextUnicodePrefix();
  return -(ulonglong)(lVar1 != 0) & lVar1 - 8U;
}



===== MupiLoadUncHardeningConfigurationToList @ 1400162c8 =====

ulonglong MupiLoadUncHardeningConfigurationToList(undefined8 param_1,longlong *param_2)

{
  uint uVar1;
  char cVar2;
  short sVar3;
  uint uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined *puVar7;
  ulonglong uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  ulonglong *puVar11;
  ushort uVar12;
  undefined8 uVar13;
  int iVar14;
  undefined4 local_res18 [2];
  longlong local_res20;
  ushort **in_stack_ffffffffffffff58;
  ushort local_88;
  undefined1 auStack_86 [6];
  ushort **ppuStack_80;
  ulonglong local_78 [2];
  ulonglong local_68 [2];
  ushort *local_58;
  longlong lStack_50;
  uint local_48;
  undefined4 local_44;
  longlong local_40;
  
  local_res20 = 0;
  iVar14 = 0;
  local_res18[0] = 0;
  uVar9 = 0x400;
LAB_140016303:
  lVar5 = ExAllocatePool2(0x102,uVar9,0x4855754d);
  if (lVar5 == 0) {
    return 0xc000009a;
  }
LAB_140016329:
  while( true ) {
    do {
      uVar10 = 1;
      in_stack_ffffffffffffff58 =
           (ushort **)CONCAT44((int)((ulonglong)in_stack_ffffffffffffff58 >> 0x20),uVar9);
      _local_88 = 0;
      ppuStack_80 = (ushort **)0x0;
      uVar4 = ZwEnumerateValueKey(param_1,iVar14,1,lVar5,in_stack_ffffffffffffff58,local_res18);
      uVar8 = (ulonglong)uVar4;
      if (uVar4 == 0x8000001a) {
        uVar8 = 0;
        goto LAB_140016586;
      }
      if ((uVar4 == 0x80000005) || (uVar4 == 0xc0000023)) goto LAB_140016562;
      if ((int)uVar4 < 0) goto LAB_140016586;
      ppuStack_80 = (ushort **)(lVar5 + 0x14);
      iVar14 = iVar14 + 1;
      uVar12 = *(ushort *)(lVar5 + 0x10);
      _local_88 = CONCAT62(CONCAT42(auStack_86._2_4_,uVar12),uVar12);
    } while (uVar12 == 0);
    uVar4 = *(uint *)(lVar5 + 4);
    if ((uVar4 == 1) || (uVar4 == 7)) break;
    if ((Microsoft_Windows_NetworkProviderEnableBits & 1) != 0) {
      McTemplateK0hzr0hzr2q_EtwWriteTransfer
                ((ulonglong)uVar4,ppuStack_80,uVar10,(ulonglong)(uVar12 >> 1),
                 in_stack_ffffffffffffff58,uVar12 >> 1,ppuStack_80,(char)uVar4);
    }
  }
  if ((uVar12 < 4) || ((*(short *)ppuStack_80 != 0x5c || (*(short *)(lVar5 + 0x16) != 0x5c)))) {
    if ((Microsoft_Windows_NetworkProviderEnableBits & 1) == 0) goto LAB_140016329;
    uVar1 = *(uint *)(lVar5 + 8);
    uVar4 = *(uint *)(lVar5 + 0xc);
    puVar7 = &UncHardening_InvalidUncPath;
  }
  else {
    in_stack_ffffffffffffff58 = &local_58;
    uVar13 = 0;
    puVar11 = local_78;
    local_68[0] = 0;
    local_68[1] = 0;
    local_78[0] = 0;
    local_78[1] = 0;
    local_58 = (ushort *)0x0;
    lStack_50 = 0;
    MupiGetPathComponents
              (&local_88,(short *)local_68,(short *)puVar11,(short *)0x0,
               (short *)in_stack_ffffffffffffff58);
    uVar10 = CONCAT71((int7)((ulonglong)puVar11 >> 8),1);
    cVar2 = RtlEqualUnicodeString(local_68,&MupiUncHardeningWildcard,uVar10);
    if (cVar2 != '\0') {
      local_68[0] = local_68[0] & 0xffffffffffff0000;
    }
    uVar10 = CONCAT71((int7)((ulonglong)uVar10 >> 8),1);
    cVar2 = RtlEqualUnicodeString(local_78,&MupiUncHardeningWildcard);
    if (cVar2 == '\0') {
      sVar3 = (short)local_78[0];
    }
    else {
      local_78[0] = local_78[0] & 0xffffffffffff0000;
      sVar3 = 0;
    }
    if ((((short)local_68[0] != 0) || (sVar3 != 0)) && ((short)local_58 == 0)) {
      puVar11 = local_78;
      uVar6 = MupiFindOrCreateUncHardeningConfigurationEntry
                        (param_2,(short *)local_68,(ushort *)puVar11,uVar13,&local_res20);
      uVar8 = uVar6 & 0xffffffff;
      if (-1 < (int)uVar6) {
        local_58 = &local_88;
        local_48 = *(uint *)(lVar5 + 0xc);
        lStack_50 = (ulonglong)*(uint *)(lVar5 + 8) + lVar5;
        local_40 = local_res20;
        in_stack_ffffffffffffff58 = &local_58;
        local_44 = 0;
        uVar4 = RfsCskvParse(lStack_50,(ulonglong)local_48,puVar11,uVar13,
                             (longlong)in_stack_ffffffffffffff58);
        uVar8 = (ulonglong)uVar4;
        if (-1 < (int)uVar4) goto LAB_140016329;
      }
LAB_140016586:
      if (lVar5 == 0) {
        return uVar8;
      }
      ExFreePoolWithTag(lVar5,0x4855754d);
      return uVar8;
    }
    if ((Microsoft_Windows_NetworkProviderEnableBits & 1) == 0) goto LAB_140016329;
    uVar4 = *(uint *)(lVar5 + 0xc);
    puVar7 = &UncHardening_UnsupportedUncPath;
    uVar1 = *(uint *)(lVar5 + 8);
    uVar12 = local_88;
  }
  McTemplateK0hzr0qzr2_EtwWriteTransfer
            ((ulonglong)uVar1 + lVar5,puVar7,uVar10,uVar12 >> 1,ppuStack_80,uVar4 >> 1,
             (ulonglong)uVar1 + lVar5);
  in_stack_ffffffffffffff58 = ppuStack_80;
  goto LAB_140016329;
LAB_140016562:
  ExFreePoolWithTag(lVar5,0x4855754d);
  uVar9 = local_res18[0];
  goto LAB_140016303;
}



===== MupiPackUncHardeningPrefixTableEntryForFsctl @ 1400165c4 =====

undefined8
MupiPackUncHardeningPrefixTableEntryForFsctl
          (longlong param_1,uint param_2,void *param_3,uint *param_4)

{
  ushort uVar1;
  undefined8 uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = *(ushort *)(param_1 + 0x40) + 0x18;
  *param_4 = 0;
  if (uVar3 < 0x18) {
    uVar2 = 0xc0000095;
  }
  else {
    if (param_2 < uVar3) {
      uVar2 = 0xc0000023;
    }
    else {
      memset(param_3,0,(ulonglong)uVar3);
      *(undefined4 *)((longlong)param_3 + 4) = 0x18;
      uVar1 = *(ushort *)(param_1 + 0x40);
      *(ushort *)((longlong)param_3 + 8) = uVar1;
      *(undefined4 *)((longlong)param_3 + 0xc) = *(undefined4 *)(param_1 + 0x58);
      *(undefined8 *)((longlong)param_3 + 0x10) = *(undefined8 *)(param_1 + 0x50);
      memmove((void *)((longlong)param_3 + 0x18),*(void **)(param_1 + 0x48),(ulonglong)uVar1);
    }
    *param_4 = uVar3;
  }
  return uVar2;
}



===== MupiPackUncHardeningPrefixTableForFsctl @ 14001666c =====

ulonglong MupiPackUncHardeningPrefixTableForFsctl
                    (ulonglong param_1,uint param_2,longlong param_3,uint *param_4)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  ulonglong local_res8;
  
  local_res8 = param_1 & 0xffffffff00000000;
  bVar1 = false;
  bVar2 = false;
  uVar5 = 0;
  KeEnterCriticalRegion();
  ExAcquirePushLockExclusiveEx(&DAT_14000b228,0);
  puVar9 = (undefined4 *)0x0;
  do {
    uVar7 = 0;
    uVar4 = MupiGetFirstOrNextUncHardeningPrefixEntry();
    uVar3 = uVar5;
    if (uVar4 == 0) {
LAB_14001677f:
      ExReleasePushLockExclusiveEx(&DAT_14000b228,0);
      KeLeaveCriticalRegion();
      if ((-1 < (int)uVar7) && (bVar2)) {
        uVar7 = 0xc0000023;
      }
      *param_4 = uVar3;
      return uVar7;
    }
    if (uVar5 + 0xf < uVar5) {
LAB_14001677a:
      uVar7 = 0xc0000095;
      goto LAB_14001677f;
    }
    uVar3 = uVar5 + 0xf & 0xfffffff0;
    if (param_2 <= uVar3) {
      uVar3 = uVar5;
      if (!bVar1) {
        puVar9 = (undefined4 *)0x0;
        puVar8 = (undefined4 *)0x0;
        uVar6 = 0;
        goto LAB_14001670b;
      }
LAB_140016769:
      uVar7 = 0x80000005;
      goto LAB_14001677f;
    }
    puVar8 = (undefined4 *)((ulonglong)uVar3 + param_3);
    uVar6 = param_2 - uVar3;
LAB_14001670b:
    uVar4 = MupiPackUncHardeningPrefixTableEntryForFsctl(uVar4,uVar6,puVar8,(uint *)&local_res8);
    uVar7 = uVar4 & 0xffffffff;
    if ((int)uVar4 < 0) {
      if ((int)uVar4 != -0x3fffffdd) goto LAB_14001677f;
      if (bVar1) goto LAB_140016769;
      bVar2 = true;
    }
    else {
      bVar1 = true;
    }
    uVar5 = (int)local_res8 + uVar3;
    if (uVar5 < uVar3) {
      uVar3 = 0xffffffff;
      goto LAB_14001677a;
    }
    if (puVar9 != (undefined4 *)0x0) {
      if (0xffffffff < (ulonglong)((longlong)puVar8 - (longlong)puVar9)) {
        *puVar9 = 0xffffffff;
        uVar3 = uVar5;
        goto LAB_14001677a;
      }
      *puVar9 = (int)((longlong)puVar8 - (longlong)puVar9);
    }
    puVar9 = puVar8;
  } while( true );
}



===== MupiSelectBestMatchingConfigurationEntry @ 1400167d4 =====

longlong MupiSelectBestMatchingConfigurationEntry(int *param_1,longlong param_2,longlong param_3)

{
  if (param_2 == 0) {
    return param_3;
  }
  if (param_3 == 0) {
    return param_2;
  }
  if ((*param_1 == 1) && (*(short *)((longlong)param_1 + 0x12) != (short)param_1[4])) {
    if ((*(int *)(param_2 + 0x18) == 1) &&
       (*(short *)(param_2 + 0x2a) != *(short *)(param_2 + 0x28))) {
      return param_2;
    }
    if (*(int *)(param_3 + 0x18) != 1) {
      return param_2;
    }
    if (*(short *)(param_3 + 0x2a) == *(short *)(param_3 + 0x28)) {
      return param_2;
    }
  }
  else {
    if (*(int *)(param_2 + 0x18) != 1) {
      return param_2;
    }
    if (*(short *)(param_2 + 0x2a) == *(short *)(param_2 + 0x28)) {
      return param_2;
    }
    if ((*(int *)(param_3 + 0x18) == 1) &&
       (*(short *)(param_3 + 0x2a) != *(short *)(param_3 + 0x28))) {
      return param_2;
    }
  }
  return param_3;
}



===== MupiUncHardeningRegistryParserCallback @ 140016850 =====

undefined8
MupiUncHardeningRegistryParserCallback
          (ushort *param_1,int param_2,longlong *param_3,undefined8 *param_4)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  ushort *puVar4;
  char cVar5;
  undefined *puVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  lVar3 = param_4[3];
  cVar5 = RtlEqualUnicodeString(param_1,&MupiUncHardeningProperty_RequireMutualAuthentication,1);
  if (cVar5 == '\0') {
    cVar5 = RtlEqualUnicodeString(param_1,&MupiUncHardeningProperty_RequireIntegrity,1);
    if (cVar5 == '\0') {
      cVar5 = RtlEqualUnicodeString(param_1,&MupiUncHardeningProperty_RequirePrivacy,1);
      if (cVar5 == '\0') {
        if (param_2 == 0) {
          if ((Microsoft_Windows_NetworkProviderEnableBits & 2) == 0) {
            return 0;
          }
          puVar4 = (ushort *)*param_4;
          McTemplateK0hzr0qzr2hzr4x_EtwWriteTransfer
                    ((ulonglong)(*param_1 >> 1),(ulonglong)(*(uint *)(param_4 + 2) >> 1),puVar4,
                     *puVar4 >> 1,*(undefined8 *)(puVar4 + 4),*(uint *)(param_4 + 2) >> 1,param_4[1]
                     ,*param_1 >> 1,*(undefined8 *)(param_1 + 4),(char)*param_3);
          return 0;
        }
        if (param_2 != 1) {
          return 0;
        }
        if ((Microsoft_Windows_NetworkProviderEnableBits & 2) == 0) {
          return 0;
        }
        uVar1 = *param_1;
        uVar2 = *(ushort *)*param_3;
        uVar9 = *(undefined8 *)((ushort *)*param_3 + 4);
        uVar8 = *(undefined8 *)(param_1 + 4);
        puVar6 = &UncHardening_UnsupportedProperty_StrValue;
        goto LAB_1400169af;
      }
      if (param_2 == 0) {
        uVar7 = 1;
        if (*param_3 < 1) {
          uVar7 = 0xffffffff;
        }
        *(undefined4 *)(lVar3 + 0x58) = uVar7;
        return 0;
      }
    }
    else if (param_2 == 0) {
      uVar7 = 1;
      if (*param_3 < 1) {
        uVar7 = 0xffffffff;
      }
      *(undefined4 *)(lVar3 + 0x54) = uVar7;
      return 0;
    }
  }
  else if (param_2 == 0) {
    uVar7 = 1;
    if (*param_3 < 1) {
      uVar7 = 0xffffffff;
    }
    *(undefined4 *)(lVar3 + 0x50) = uVar7;
    return 0;
  }
  if (param_2 != 1) {
    return 0;
  }
  if ((Microsoft_Windows_NetworkProviderEnableBits & 1) == 0) {
    return 0;
  }
  uVar1 = *param_1;
  uVar2 = *(ushort *)*param_3;
  uVar9 = *(undefined8 *)((ushort *)*param_3 + 4);
  uVar8 = *(undefined8 *)(param_1 + 4);
  puVar6 = &UncHardening_UnsupportedPropertyValue_StrValue_ExpectBoolValue;
LAB_1400169af:
  McTemplateK0hzr0qzr2hzr4hzr6_EtwWriteTransfer
            ((ulonglong)(uVar2 >> 1),puVar6,(ulonglong)(*(uint *)(param_4 + 2) >> 1),
             *(ushort *)*param_4 >> 1,*(undefined8 *)((ushort *)*param_4 + 4),
             *(uint *)(param_4 + 2) >> 1,param_4[1],uVar1 >> 1,uVar8,uVar2 >> 1,uVar9);
  return 0;
}



===== MupiUncHardeningRegistryParserErrorCallback @ 140016a60 =====

undefined8
MupiUncHardeningRegistryParserErrorCallback(int param_1,ushort *param_2,undefined8 *param_3)

{
  ushort *puVar1;
  ushort uVar2;
  ulonglong uVar3;
  uint uVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  undefined8 uVar8;
  
  if (param_1 < 7) {
    if (param_1 == 6) {
LAB_140016c74:
      if ((Microsoft_Windows_NetworkProviderEnableBits & 2) == 0) {
        return 0;
      }
      puVar1 = (ushort *)*param_3;
      McTemplateK0hzr0qzr2hzr4hzr6_EtwWriteTransfer
                ((ulonglong)(*param_2 >> 1),&UncHardening_UnsupportedProperty_StrValue,puVar1,
                 *puVar1 >> 1,*(undefined8 *)(puVar1 + 4),*(uint *)(param_3 + 2) >> 1,param_3[1],
                 *param_2 >> 1,*(undefined8 *)(param_2 + 4),0,0);
      return 0;
    }
    if (param_1 == 1) {
      if ((Microsoft_Windows_NetworkProviderEnableBits & 1) == 0) {
        return 0;
      }
      McTemplateK0hzr0qzr2_EtwWriteTransfer
                ((ulonglong)(*(uint *)(param_3 + 2) >> 1),&UncHardening_InvalidSyntax_UnknownError,
                 param_3,*(ushort *)*param_3 >> 1,*(undefined8 *)((ushort *)*param_3 + 4),
                 *(uint *)(param_3 + 2) >> 1,param_3[1]);
      return 0;
    }
    if (param_1 == 2) {
      if ((Microsoft_Windows_NetworkProviderEnableBits & 1) == 0) {
        return 0;
      }
      uVar8 = *(undefined8 *)(param_2 + 4);
      uVar2 = *param_2 >> 1;
      uVar3 = (ulonglong)uVar2;
      uVar7 = 1;
    }
    else if (param_1 == 3) {
      if ((Microsoft_Windows_NetworkProviderEnableBits & 1) == 0) {
        return 0;
      }
      uVar8 = *(undefined8 *)(param_2 + 4);
      uVar2 = *param_2 >> 1;
      uVar3 = (ulonglong)uVar2;
      uVar7 = 2;
    }
    else if (param_1 == 4) {
      if ((Microsoft_Windows_NetworkProviderEnableBits & 1) == 0) {
        return 0;
      }
      uVar8 = *(undefined8 *)(param_2 + 4);
      uVar2 = *param_2 >> 1;
      uVar3 = (ulonglong)uVar2;
      uVar7 = 3;
    }
    else {
      if (param_1 != 5) {
        return 0;
      }
      if ((Microsoft_Windows_NetworkProviderEnableBits & 1) == 0) {
        return 0;
      }
      uVar8 = *(undefined8 *)(param_2 + 4);
      uVar2 = *param_2 >> 1;
      uVar3 = (ulonglong)uVar2;
      uVar7 = 6;
    }
    uVar6 = param_3[1];
    uVar4 = *(uint *)(param_3 + 2) >> 1;
    puVar5 = &UncHardening_InvalidSyntax_UnexpectedToken;
  }
  else {
    if (param_1 == 7) goto LAB_140016c74;
    if (param_1 == 8) {
      if ((Microsoft_Windows_NetworkProviderEnableBits & 1) == 0) {
        return 0;
      }
      uVar8 = *(undefined8 *)(param_2 + 4);
      uVar6 = param_3[1];
      uVar2 = *param_2 >> 1;
      uVar3 = (ulonglong)uVar2;
      uVar7 = 4;
      uVar4 = *(uint *)(param_3 + 2) >> 1;
      puVar5 = &UncHardening_InvalidSyntax_IllegalInteger;
    }
    else {
      if ((param_1 != 9) && (param_1 != 10)) {
        return 0;
      }
      if ((Microsoft_Windows_NetworkProviderEnableBits & 1) == 0) {
        return 0;
      }
      uVar8 = *(undefined8 *)(param_2 + 4);
      uVar6 = param_3[1];
      uVar2 = *param_2 >> 1;
      uVar3 = (ulonglong)uVar2;
      uVar7 = 5;
      uVar4 = *(uint *)(param_3 + 2) >> 1;
      puVar5 = &UncHardening_InvalidSyntax_IllegalString;
    }
  }
  puVar1 = (ushort *)*param_3;
  McTemplateK0hzr0qzr2qhzr5_EtwWriteTransfer
            (uVar3,puVar5,puVar1,*puVar1 >> 1,*(undefined8 *)(puVar1 + 4),uVar4,uVar6,uVar7,uVar2,
             uVar8);
  return 0;
}



===== MupInitializeContainerModule @ 140016ce0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MupInitializeContainerModule(longlong param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 auStack_58 [40];
  undefined1 local_30;
  undefined4 local_2f;
  undefined2 local_2b;
  undefined1 local_29;
  longlong local_28;
  code *local_20;
  code *local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
            &WPP_c898274d75623dfd801520d1a3be50ef_Traceguids);
  }
  local_30 = 1;
  local_28 = param_1 + 0x38;
  local_2f = 0;
  local_2b = 0;
  local_20 = MupiContainerCreateNotify;
  local_29 = 0;
  local_18 = MupiContainerTerminateNotify;
  iVar1 = PsRegisterSiloMonitor(&local_30,&ContainerMonitor);
  if (iVar1 < 0) {
    if (((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) == 0)) goto LAB_140016dec;
    uVar2 = 0x11;
  }
  else {
    iVar1 = PsStartSiloMonitor(ContainerMonitor);
    if (((-1 < iVar1) || ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control)) ||
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) == 0)) {
      if (iVar1 == 0) {
        return 0;
      }
      goto LAB_140016dec;
    }
    uVar2 = 0x10;
  }
  WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar2,
           &WPP_c898274d75623dfd801520d1a3be50ef_Traceguids,iVar1);
LAB_140016dec:
  MupTerminateContainerModule();
  return iVar1;
}



===== MupReferenceContainerContext @ 140016e18 =====

void MupReferenceContainerContext(void)

{
  PsReferenceSiloContext();
  return;
}



===== MupTerminateContainerModule @ 140016e34 =====

void MupTerminateContainerModule(void)

{
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
            &WPP_c898274d75623dfd801520d1a3be50ef_Traceguids);
  }
  if (ContainerMonitor != 0) {
    PsUnregisterSiloMonitor();
    ContainerMonitor = 0;
  }
  return;
}



===== MupiContainerCleanupNotify @ 140016ea0 =====

void MupiContainerCleanupNotify(undefined *param_1)

{
  undefined *puVar1;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
             &WPP_c898274d75623dfd801520d1a3be50ef_Traceguids,param_1);
  }
  puVar1 = MupGetUncCachePrefixTable(param_1);
  MupFlushKnownPrefixTable((longlong)puVar1,0,'\x01');
  return;
}



===== MupiContainerCreateNotify @ 140016f00 =====

int MupiContainerCreateNotify(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  bool bVar4;
  undefined8 *local_res10;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_res10 = (undefined8 *)0x0;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
             &WPP_c898274d75623dfd801520d1a3be50ef_Traceguids,param_1);
  }
  iVar1 = PsCreateSiloContext(param_1,0x18,1,MupiContainerCleanupNotify,&local_res10);
  if (iVar1 == 0) {
    *local_res10 = 0;
    local_res10[1] = 0;
    local_res10[2] = 0;
    RtlInitializeUnicodePrefix(local_res10);
    uVar3 = PsAttachSiloToCurrentThread(param_1);
    RtlInitUnicodeString(&local_28,L"\\Device\\Mup");
    RtlInitUnicodeString(&local_38,L"\\??\\UNC");
    IoDeleteSymbolicLink(&local_38);
    iVar1 = IoCreateSymbolicLink(&local_38,&local_28);
    PsDetachSiloFromCurrentThread(uVar3);
    bVar4 = -1 < iVar1;
    if (bVar4) {
      uVar2 = PsGetSiloMonitorContextSlot(ContainerMonitor);
      iVar1 = PsInsertPermanentSiloContext(param_1,uVar2,local_res10);
    }
    if (iVar1 != 0) {
      if (bVar4) {
        uVar3 = PsAttachSiloToCurrentThread(param_1);
        IoDeleteSymbolicLink(&local_38);
        PsDetachSiloFromCurrentThread(uVar3);
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_c898274d75623dfd801520d1a3be50ef_Traceguids,iVar1);
      }
    }
    PsDereferenceSiloContext(local_res10);
  }
  else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_c898274d75623dfd801520d1a3be50ef_Traceguids,param_1,(char)iVar1);
  }
  return iVar1;
}



===== MupiContainerTerminateNotify @ 140017130 =====

void MupiContainerTerminateNotify(undefined8 param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined *puVar3;
  undefined *local_res10 [3];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res10[0] = (undefined *)0x0;
  uVar1 = PsGetSiloMonitorContextSlot(ContainerMonitor);
  PsGetPermanentSiloContext(param_1,uVar1,local_res10);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_c898274d75623dfd801520d1a3be50ef_Traceguids,param_1,(char)local_res10[0]);
  }
  if (local_res10[0] != (undefined *)0x0) {
    local_18 = 0;
    uStack_10 = 0;
    uVar2 = PsAttachSiloToCurrentThread(param_1);
    RtlInitUnicodeString(&local_18);
    IoDeleteSymbolicLink(&local_18);
    PsDetachSiloFromCurrentThread(uVar2);
    puVar3 = MupGetUncCachePrefixTable(local_res10[0]);
    MupFlushKnownPrefixTable((longlong)puVar3,0,'\x01');
  }
  return;
}



===== MupInitRegistryParametersKeyModule @ 140017224 =====

void MupInitRegistryParametersKeyModule(void)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  memset(&DAT_14000b380,0,0x110);
  ExInitializeRundownProtection(&DAT_14000b388);
  RtlRunOnceInitialize(&DAT_14000b380);
  RfsTimerInitialize(0x14000b3d0,uVar1,MupRefreshRegistryParametersKeyTimerCallback,&DAT_14000b380);
  RtlRunOnceExecuteOnce
            (&DAT_14000b380,MupAttempttoLoadRegistryParametersKeyRunOnce,&DAT_14000b380,0);
  return;
}



===== MupiArmPoliciesKeyRefreshTimer @ 1400172a4 =====

void MupiArmPoliciesKeyRefreshTimer(longlong param_1)

{
  RfsTimerSet(param_1 + 0x50);
  return;
}



===== MupiOpenParametersKeyFromRegistry @ 1400172e0 =====

int MupiOpenParametersKeyFromRegistry(undefined8 *param_1)

{
  int iVar1;
  ushort uVar2;
  undefined8 local_res10;
  ushort local_68 [4];
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  undefined8 local_50;
  ushort *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_58 = 0x30;
  local_48 = (ushort *)&g_MupParametersRegistryKey;
  local_40 = 0x240;
  local_50 = 0;
  local_38 = 0;
  uStack_30 = 0;
  iVar1 = ZwOpenKey(0,0x20019,&local_58);
  if (iVar1 == -0x3fffffcc) {
    uVar2 = 0;
    local_68[0] = 0;
    local_68[1] = 0x86;
    local_68[2] = 0;
    local_68[3] = 0;
    uStack_60 = 0x40008d30;
    uStack_5c = 1;
    while( true ) {
      if (0x84 < local_68[0]) break;
      local_res10 = 0;
      while ((local_68[0] + 2 < 0x85 &&
             (*(short *)(CONCAT44(uStack_5c,uStack_60) + (ulonglong)(local_68[0] >> 1) * 2) != 0x5c)
             )) {
        local_68[0] = local_68[0] + 2;
      }
      if ((ushort)(local_68[0] - 1) < 0x83) {
        uVar2 = uVar2 + 1;
      }
      if (5 < uVar2) {
        local_48 = local_68;
        local_58 = CONCAT44(local_58._4_4_,0x30);
        local_50 = 0;
        local_38 = 0;
        uStack_30 = 0;
        local_40 = CONCAT44(local_40._4_4_,0x240);
        iVar1 = ZwCreateKey(&local_res10,0x20019,&local_58,0,0,0,0);
        if (iVar1 < 0) goto LAB_14001745b;
        if (local_68[0] == 0x84) {
          *param_1 = local_res10;
          goto LAB_140017435;
        }
        ZwClose(local_res10);
      }
      local_68[0] = local_68[0] + 2;
    }
  }
  if (iVar1 < 0) {
LAB_14001745b:
    *param_1 = 0;
  }
  else {
LAB_140017435:
    iVar1 = 0;
  }
  return iVar1;
}



===== MupiReadEnableMailslotsFromRegistry @ 140017468 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

char MupiReadEnableMailslotsFromRegistry(undefined8 param_1,char param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  char cVar4;
  undefined *puVar5;
  undefined1 auStackY_78 [32];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_40 = 0;
  uStack_38 = 0;
  RtlInitUnicodeString(&local_40,L"EnableMailslots");
  puVar5 = (undefined *)0x2;
  iVar1 = ZwQueryValueKey(param_1,&local_40,2,&local_30);
  puVar2 = WPP_GLOBAL_Control;
  if ((iVar1 < 0) || (local_30._4_4_ != 4)) {
    cVar4 = '\0';
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
      puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      puVar5 = &WPP_511a9a8026a53b8720c76e64765e5363_Traceguids;
      WPP_SF_D(puVar2,0xd,&WPP_511a9a8026a53b8720c76e64765e5363_Traceguids,iVar1);
    }
  }
  else {
    cVar4 = uStack_28._4_1_;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
      puVar5 = &WPP_511a9a8026a53b8720c76e64765e5363_Traceguids;
      puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_dDD(puVar2,&WPP_GLOBAL_Control,&WPP_511a9a8026a53b8720c76e64765e5363_Traceguids,iVar1,4
                 ,uStack_28._4_1_);
    }
  }
  if ((param_2 != '\0') && (MupEnableMailslots != cVar4)) {
    if (cVar4 == '\0') {
      if ((Microsoft_Windows_NetworkProviderEnableBits & 8) == 0) {
        return '\0';
      }
      puVar3 = &RemoteMailslotsDisabled;
    }
    else {
      if ((Microsoft_Windows_NetworkProviderEnableBits & 4) == 0) {
        return cVar4;
      }
      puVar3 = &RemoteMailslotsEnabled;
    }
    McTemplateK0_EtwWriteTransfer(puVar2,puVar3,puVar5);
  }
  return cVar4;
}



===== MupiRegisterParametersKeyRegistryChangeNotification @ 1400175c8 =====

int MupiRegisterParametersKeyRegistryChangeNotification(longlong param_1)

{
  int iVar1;
  
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(code **)(param_1 + 0x30) = MupRegistryParametersKeyChangeNotification;
  *(longlong *)(param_1 + 0x38) = param_1;
  iVar1 = ZwNotifyChangeKey(*(undefined8 *)(param_1 + 0x18),0,(undefined8 *)(param_1 + 0x20),1,
                            param_1 + 0x40,4,0,0,0,1);
  if (((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_511a9a8026a53b8720c76e64765e5363_Traceguids,iVar1);
  }
  return iVar1;
}



===== MupInitRegistryPoliciesKeyModule @ 14001766c =====

void MupInitRegistryPoliciesKeyModule(void)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  memset(&MupiPoliciesKeyRegistryWatcher,0,0x110);
  ExInitializeRundownProtection(&DAT_14000b4a8);
  RtlRunOnceInitialize(&MupiPoliciesKeyRegistryWatcher);
  RfsTimerInitialize(0x14000b4f0,uVar1,MupRefreshRegistryPoliciesKeyTimerCallback,
                     &MupiPoliciesKeyRegistryWatcher);
  MupiTryStartPoliciesKeyRegistryWatcher();
  return;
}



===== MupiOpenPoliciesKeyFromRegistry @ 1400176d8 =====

int MupiOpenPoliciesKeyFromRegistry(undefined8 *param_1)

{
  int iVar1;
  ushort uVar2;
  undefined8 local_res10;
  ushort local_68 [4];
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined8 local_58;
  undefined8 local_50;
  ushort *local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  
  local_58 = 0x30;
  local_48 = (ushort *)&MUPI_REGISTRY_POLICIES_KEY_PATH;
  local_40 = 0x240;
  local_50 = 0;
  local_38 = 0;
  uStack_30 = 0;
  iVar1 = ZwOpenKey(0,0x20019,&local_58);
  if (iVar1 == -0x3fffffcc) {
    uVar2 = 0;
    local_68[2] = 0;
    local_68[3] = 0;
    uStack_60 = 0x40008df0;
    uStack_5c = 1;
    local_68[0] = 0;
    local_68[1] = 0x8c;
    do {
      local_res10 = 0;
      while ((local_68[0] + 2 < 0x8b &&
             (*(short *)(CONCAT44(uStack_5c,uStack_60) + (ulonglong)(local_68[0] >> 1) * 2) != 0x5c)
             )) {
        local_68[0] = local_68[0] + 2;
      }
      if ((ushort)(local_68[0] - 1) < 0x8a) {
        uVar2 = uVar2 + 1;
      }
      if (4 < uVar2) {
        local_48 = local_68;
        local_58 = CONCAT44(local_58._4_4_,0x30);
        local_50 = 0;
        local_38 = 0;
        uStack_30 = 0;
        local_40 = CONCAT44(local_40._4_4_,0x240);
        iVar1 = ZwCreateKey(&local_res10,0x20019,&local_58,0,0,0,0);
        if (iVar1 < 0) goto LAB_140017829;
        if (local_68[0] == 0x8a) {
          *param_1 = local_res10;
          goto LAB_140017835;
        }
        ZwClose(local_res10);
      }
      local_68[0] = local_68[0] + 2;
    } while (local_68[0] < 0x8b);
  }
  if (iVar1 < 0) {
LAB_140017829:
    *param_1 = 0;
  }
  else {
LAB_140017835:
    iVar1 = 0;
  }
  return iVar1;
}



===== MupiReadEnableMailslotsFromPoliciesRegistry @ 140017860 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte MupiReadEnableMailslotsFromPoliciesRegistry(undefined8 param_1,char param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  byte bVar4;
  undefined *puVar5;
  undefined1 auStackY_78 [32];
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_20 = 0;
  local_30 = 0;
  uStack_28 = 0;
  local_40 = 0;
  uStack_38 = 0;
  RtlInitUnicodeString(&local_40,L"EnableMailslots");
  puVar5 = (undefined *)0x2;
  iVar1 = ZwQueryValueKey(param_1,&local_40,2,&local_30);
  puVar2 = WPP_GLOBAL_Control;
  if ((iVar1 < 0) || (local_30._4_4_ != 4)) {
    bVar4 = 2;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
      puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      puVar5 = &WPP_4108bb1397623747c94676978a28aeb5_Traceguids;
      WPP_SF_D(puVar2,0xd,&WPP_4108bb1397623747c94676978a28aeb5_Traceguids,iVar1);
    }
  }
  else {
    bVar4 = uStack_28._4_1_;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
      puVar5 = &WPP_4108bb1397623747c94676978a28aeb5_Traceguids;
      puVar2 = *(undefined **)(WPP_GLOBAL_Control + 0x18);
      WPP_SF_dDD(puVar2,&WPP_GLOBAL_Control,&WPP_4108bb1397623747c94676978a28aeb5_Traceguids,iVar1,4
                 ,uStack_28._4_1_);
    }
  }
  if (((param_2 != '\0') && (_MupEnableMailslotsByPolicy != bVar4)) && (bVar4 != 2)) {
    if (bVar4 == 0) {
      if ((Microsoft_Windows_NetworkProviderEnableBits & 8) == 0) {
        return 0;
      }
      puVar3 = &RemoteMailslotsDisabledByPolicy;
    }
    else {
      if ((Microsoft_Windows_NetworkProviderEnableBits & 4) == 0) {
        return bVar4;
      }
      puVar3 = &RemoteMailslotsEnabledByPolicy;
    }
    McTemplateK0_EtwWriteTransfer(puVar2,puVar3,puVar5);
  }
  return bVar4;
}



===== MupiRegisterPoliciesKeyRegistryChangeNotification @ 1400179c8 =====

int MupiRegisterPoliciesKeyRegistryChangeNotification(longlong param_1)

{
  int iVar1;
  
  *(undefined8 *)(param_1 + 0x20) = 0;
  *(code **)(param_1 + 0x30) = MupRegistryPoliciesKeyChangeNotification;
  *(longlong *)(param_1 + 0x38) = param_1;
  iVar1 = ZwNotifyChangeKey(*(undefined8 *)(param_1 + 0x18),0,(undefined8 *)(param_1 + 0x20),1,
                            param_1 + 0x40,4,0,0,0,1);
  if (((iVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_4108bb1397623747c94676978a28aeb5_Traceguids,iVar1);
  }
  return iVar1;
}



===== MupiTryStartPoliciesKeyRegistryWatcher @ 140017a6c =====

byte MupiTryStartPoliciesKeyRegistryWatcher(void)

{
  byte extraout_var;
  
  RtlRunOnceExecuteOnce
            (&MupiPoliciesKeyRegistryWatcher,MupAttempttoLoadRegistryPoliciesKeyRunOnce,
             &MupiPoliciesKeyRegistryWatcher,0);
  return extraout_var >> 7 ^ 1;
}



===== RfspServerNameEqualDnsName @ 140017aa4 =====

ulonglong RfspServerNameEqualDnsName(longlong param_1,longlong param_2,char param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ulonglong in_RAX;
  ulonglong uVar4;
  ulonglong *puVar5;
  ulonglong *puVar6;
  undefined7 in_register_00000081;
  ulonglong local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  undefined8 uStack_10;
  
  uVar4 = CONCAT71(in_register_00000081,param_3);
  uVar1 = *(ushort *)(param_1 + 0x10);
  uVar2 = *(ushort *)(param_2 + 0x10);
  if (uVar1 == uVar2) {
    in_RAX = *(ulonglong *)(param_2 + 0x18);
    if (*(ulonglong *)(param_1 + 0x18) != in_RAX) goto LAB_140017c10;
    uStack_20 = *(undefined8 *)(param_1 + 8);
    uStack_30 = *(undefined8 *)(param_2 + 8);
    puVar6 = &local_38;
    local_38 = (ulonglong)CONCAT22(uVar1,uVar1);
    uVar3 = CONCAT22(uVar2,uVar2);
    local_28 = local_38;
  }
  else {
    if (param_3 != '\0') goto LAB_140017c10;
    if (uVar1 < uVar2) {
      uVar2 = *(ushort *)(param_1 + 0x12);
      uVar4 = (ulonglong)uVar2;
      if ((uVar2 != uVar1) ||
         (in_RAX = *(ulonglong *)(param_2 + 0x20), *(ulonglong *)(param_1 + 0x20) != in_RAX))
      goto LAB_140017c10;
      uStack_10 = *(undefined8 *)(param_1 + 8);
      puVar5 = &local_18;
      uStack_30 = *(undefined8 *)(param_2 + 8);
      local_38 = (ulonglong)CONCAT22(uVar2,uVar2);
      puVar6 = &local_28;
      uVar3 = CONCAT22(*(undefined2 *)(param_2 + 0x12),*(undefined2 *)(param_2 + 0x12));
      local_18 = local_38;
      local_28 = (ulonglong)uVar3;
      uStack_20 = uStack_30;
      goto LAB_140017b17;
    }
    if (uVar1 <= uVar2) {
LAB_140017c10:
      return in_RAX & 0xffffffffffffff00;
    }
    uVar1 = *(ushort *)(param_2 + 0x12);
    uVar4 = (ulonglong)uVar1;
    if ((uVar1 != uVar2) ||
       (in_RAX = *(ulonglong *)(param_2 + 0x20), *(ulonglong *)(param_1 + 0x20) != in_RAX))
    goto LAB_140017c10;
    uStack_20 = *(undefined8 *)(param_1 + 8);
    local_38 = (ulonglong)CONCAT22(*(undefined2 *)(param_1 + 0x12),*(undefined2 *)(param_1 + 0x12));
    uStack_30 = *(undefined8 *)(param_2 + 8);
    puVar6 = &local_18;
    local_28 = local_38;
    uVar3 = CONCAT22(uVar1,uVar1);
    local_18 = (ulonglong)uVar3;
    uStack_10 = uStack_30;
  }
  puVar5 = &local_28;
LAB_140017b17:
  local_38 = (ulonglong)uVar3;
  uVar4 = RtlEqualUnicodeString(puVar5,puVar6,CONCAT71((int7)(uVar4 >> 8),1));
  return uVar4;
}



===== RfspServerNameEqualSockaddr @ 140017c20 =====

ulonglong RfspServerNameEqualSockaddr(longlong param_1,longlong param_2)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  ushort *puVar4;
  ulonglong uVar5;
  longlong lVar6;
  
  uVar5 = *(ulonglong *)(param_2 + 0x10);
  puVar3 = *(ushort **)(param_1 + 8);
  puVar4 = *(ushort **)(param_2 + 8);
  if (*(ulonglong *)(param_1 + 0x10) == uVar5) {
    uVar1 = *puVar3;
    uVar5 = (ulonglong)uVar1;
    if (uVar1 == *puVar4) {
      if (uVar1 == 2) {
        uVar5 = (ulonglong)*(uint *)(puVar4 + 2);
        if (*(uint *)(puVar3 + 2) == *(uint *)(puVar4 + 2)) {
          return (ulonglong)CONCAT11((char)(puVar4[1] >> 8),puVar3[1] == puVar4[1]);
        }
      }
      else if (uVar1 == 0x17) {
        lVar6 = *(longlong *)(puVar3 + 4) - *(longlong *)(puVar4 + 4);
        if (lVar6 == 0) {
          lVar6 = *(longlong *)(puVar3 + 8) - *(longlong *)(puVar4 + 8);
        }
        if ((lVar6 == 0) && (uVar5 = (ulonglong)puVar4[1], puVar3[1] == puVar4[1])) {
          uVar2 = *(uint *)(puVar4 + 0xc);
          uVar5 = (ulonglong)uVar2;
          if (*(uint *)(puVar3 + 0xc) == uVar2) {
            return CONCAT71((uint7)(uint3)(uVar2 >> 8),1);
          }
        }
      }
    }
  }
  return uVar5 & 0xffffffffffffff00;
}



===== RfsTimerInitialize @ 140017c9c =====

void RfsTimerInitialize(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  *(undefined4 *)(param_1 + 0x40) = 0x20;
  *(undefined8 *)(param_1 + 0xa8) = param_3;
  *(undefined8 *)(param_1 + 0xb0) = param_4;
  KeInitializeTimerEx(param_1,0);
  KeInitializeDpc(param_1 + 0x48,RfsTimerpExpirationDpc,param_1);
  *(undefined8 *)(param_1 + 0x88) = 0;
  *(code **)(param_1 + 0x98) = RfsTimerpExpirationWorker;
  *(longlong *)(param_1 + 0xa0) = param_1;
  *(undefined8 *)(param_1 + 0xb8) = 0;
  return;
}



===== RfsTimerpExpirationWorker @ 140017d20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void RfsTimerpExpirationWorker(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  iVar4 = 0;
  while( true ) {
    uVar2 = *(uint *)(param_1 + 0x40);
    do {
      uVar7 = 0x10;
      uVar6 = uVar2 & 8;
      if (((uVar6 == 0) || ((uVar2 & 1) != 0)) || ((uVar2 & 4) != 0)) {
        uVar7 = 0;
      }
      uVar5 = uVar2 & 4;
      uVar3 = uVar2 & 1;
      LOCK();
      uVar1 = *(uint *)(param_1 + 0x40);
      bVar8 = uVar2 == uVar1;
      if (bVar8) {
        *(uint *)(param_1 + 0x40) = ~(iVar4 * 0x10 + 8U) & uVar2 | uVar7;
      }
      else {
        uVar2 = uVar1;
      }
      UNLOCK();
    } while (!bVar8);
    if ((uVar3 != 0) || (uVar5 != 0)) break;
    if (uVar6 == 0) {
      return;
    }
    (**(code **)(param_1 + 0xa8))(param_1,*(undefined8 *)(param_1 + 0xb0));
    iVar4 = 1;
  }
  ExUnblockOnAddressPushLockEx(param_1 + 0xb8,0);
  return;
}



===== RfsCskvLexerGetError @ 140017dc8 =====

undefined8 RfsCskvLexerGetError(longlong *param_1,undefined4 *param_2)

{
  ushort *puVar1;
  ushort uVar2;
  ushort uVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  
  puVar1 = (ushort *)(param_2 + 2);
  RfsCskvLexerStreamGetViewAsString(param_1,(short *)puVar1);
  uVar4 = 0;
  uVar3 = 0;
  uVar5 = 1;
  if (*puVar1 >> 1 != 0) {
    do {
      uVar3 = (ushort)uVar4;
      uVar2 = *(ushort *)(*(longlong *)(param_2 + 4) + uVar4 * 2);
      if ((uVar2 < 0x3e) && ((0x2000100100002601U >> ((ulonglong)uVar2 & 0x3f) & 1) != 0)) break;
      uVar3 = uVar3 + 1;
      uVar4 = (ulonglong)uVar3;
    } while (uVar3 < *puVar1 >> 1);
  }
  *puVar1 = uVar3 * 2;
  RfsCskvLexerStreamAdvance((longlong)param_1,(ulonglong)(ushort)(uVar3 * 2));
  *param_2 = 6;
  param_2[1] = uVar5;
  return 0;
}



===== RfsCskvLexerGetIdentifier @ 140017e58 =====

undefined8 RfsCskvLexerGetIdentifier(longlong *param_1,undefined4 *param_2)

{
  ushort *puVar1;
  bool bVar2;
  undefined8 uVar3;
  longlong *plVar4;
  ushort uVar5;
  ulonglong uVar6;
  ushort local_res10 [4];
  
  puVar1 = (ushort *)(param_2 + 2);
  local_res10[0] = 0;
  bVar2 = true;
  RfsCskvLexerStreamGetViewAsString(param_1,(short *)puVar1);
  uVar6 = 0;
  uVar5 = 0;
  if (*puVar1 >> 1 != 0) {
    bVar2 = true;
    do {
      uVar5 = (ushort)uVar6;
      local_res10[0] = *(ushort *)(*(longlong *)(param_2 + 4) + uVar6 * 2);
      if ((((local_res10[0] < 0x21) &&
           ((0x100002601U >> ((ulonglong)local_res10[0] & 0x3f) & 1) != 0)) ||
          (local_res10[0] == 0x2c)) || (local_res10[0] == 0x3d)) break;
      if ((0x39 < (ushort)(local_res10[0] - 0x41)) ||
         ((0x3ffffff43ffffffU >> ((ulonglong)(ushort)(local_res10[0] - 0x41) & 0x3f) & 1) == 0)) {
        bVar2 = false;
      }
      uVar5 = uVar5 + 1;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < *puVar1 >> 1);
  }
  *puVar1 = uVar5 * 2;
  plVar4 = param_1;
  RfsCskvLexerStreamAdvance((longlong)param_1,(ulonglong)(ushort)(uVar5 * 2));
  if (bVar2) {
    if (((uVar5 == 0x7fff) &&
        (uVar3 = RfsCskvLexerStreamPeekChar(plVar4,local_res10), (char)uVar3 != '\0')) &&
       ((uVar6 = 0x2000100100002601, 0x3d < local_res10[0] ||
        ((0x2000100100002601U >> ((ulonglong)local_res10[0] & 0x3f) & 1) == 0)))) {
      plVar4 = param_1;
      while ((uVar3 = RfsCskvLexerStreamPeekChar(plVar4,local_res10), (char)uVar3 != '\0' &&
             ((0x3d < local_res10[0] || ((uVar6 >> ((ulonglong)local_res10[0] & 0x3f) & 1) == 0)))))
      {
        plVar4 = param_1;
        RfsCskvLexerStreamGetChar(param_1,local_res10);
      }
      *param_2 = 6;
      param_2[1] = 7;
      return 0;
    }
    *param_2 = 3;
  }
  else {
    *param_2 = 6;
    param_2[1] = 6;
  }
  return 0;
}



===== RfsCskvLexerGetNumber @ 140017fbc =====

ulonglong RfsCskvLexerGetNumber(longlong *param_1,undefined4 *param_2)

{
  ushort *puVar1;
  ushort uVar2;
  undefined8 uVar3;
  int iVar4;
  ushort uVar5;
  ulonglong uVar6;
  short local_res10;
  
  puVar1 = (ushort *)(param_2 + 2);
  RfsCskvLexerStreamGetViewAsString(param_1,(short *)puVar1);
  uVar3 = *(undefined8 *)(param_2 + 4);
  iVar4 = RtlUnicodeStringToInt64(puVar1,0,param_2 + 6);
  local_res10 = (short)uVar3;
  uVar6 = 0;
  uVar5 = local_res10 - *(short *)(param_2 + 4);
  *puVar1 = uVar5;
  if ((iVar4 < 0) || (uVar5 != 0)) {
    if ((iVar4 < 0) ||
       ((uVar5 < *(ushort *)((longlong)param_2 + 10) &&
        ((uVar2 = *(ushort *)(*(longlong *)(param_2 + 4) + (ulonglong)(uVar5 >> 1) * 2),
         0x3d < uVar2 || ((0x2000100100002601U >> ((ulonglong)uVar2 & 0x3f) & 1) == 0)))))) {
      *puVar1 = 0;
      if (*(ushort *)((longlong)param_2 + 10) != 0) {
        uVar5 = 0;
        do {
          uVar2 = *(ushort *)(*(longlong *)(param_2 + 4) + (ulonglong)(uVar5 >> 1) * 2);
          if ((uVar2 < 0x3e) && ((0x2000100100002601U >> ((ulonglong)uVar2 & 0x3f) & 1) != 0))
          break;
          uVar5 = uVar5 + 2;
          *puVar1 = uVar5;
        } while (uVar5 < *(ushort *)((longlong)param_2 + 10));
      }
      RfsCskvLexerStreamAdvance((longlong)param_1,(ulonglong)*puVar1);
      *param_2 = 6;
      param_2[1] = 8;
    }
    else {
      RfsCskvLexerStreamAdvance((longlong)param_1,(ulonglong)uVar5);
      *param_2 = 4;
    }
  }
  else {
    uVar6 = 0xc00000e5;
  }
  return uVar6 & 0xffffffff;
}



===== RfsCskvLexerGetString @ 1400180d4 =====

ulonglong RfsCskvLexerGetString(longlong *param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined8 uVar2;
  char cVar3;
  int iVar4;
  char cVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  ushort local_res10 [4];
  ushort local_res18 [4];
  
  uVar6 = 0;
  *(undefined2 *)(param_2 + 2) = 0;
  local_res18[0] = 0;
  local_res10[0] = 0;
  bVar1 = false;
  uVar2 = RfsCskvLexerStreamGetChar(param_1,local_res10);
  if ((char)uVar2 != '\0') {
    uVar8 = (int)uVar6 + 0x27;
    uVar7 = (int)uVar6 + 0x22;
    cVar5 = '\x01';
    if ((local_res10[0] == (ushort)uVar8) || (local_res10[0] == (ushort)uVar7)) {
LAB_140018133:
      do {
        uVar2 = RfsCskvLexerStreamGetChar(param_1,local_res18);
        if ((char)uVar2 == '\0') goto LAB_1400181c3;
        if (!bVar1) {
          if ((local_res18[0] == uVar7) || (local_res18[0] == uVar8)) {
            if (local_res18[0] == local_res10[0]) {
              if (cVar5 != '\0') {
                *param_2 = 5;
                goto LAB_1400181e2;
              }
              param_2[1] = 9;
              goto LAB_1400181db;
            }
          }
          else if (local_res18[0] == 0x5c) {
            bVar1 = true;
            goto LAB_140018133;
          }
        }
        if ((ulonglong)*(ushort *)((longlong)param_2 + 10) < (ulonglong)*(ushort *)(param_2 + 2) + 2
           ) {
          iVar4 = -0x3fffffdd;
        }
        else {
          *(ushort *)(*(longlong *)(param_2 + 4) + (ulonglong)(*(ushort *)(param_2 + 2) >> 1) * 2) =
               local_res18[0];
          iVar4 = (int)uVar6;
          *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + 2;
        }
        cVar3 = (char)uVar6;
        if (-1 < iVar4) {
          cVar3 = cVar5;
        }
        cVar5 = cVar3;
      } while( true );
    }
  }
  param_2[1] = 1;
  uVar6 = 0xc00000e5;
LAB_1400181db:
  *param_2 = 6;
LAB_1400181e2:
  return uVar6 & 0xffffffff;
LAB_1400181c3:
  param_2[1] = 10;
  goto LAB_1400181db;
}



===== RfsCskvLexerGetToken @ 140018200 =====

ulonglong RfsCskvLexerGetToken(longlong *param_1,undefined8 *param_2)

{
  longlong lVar1;
  int iVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  undefined4 uVar6;
  ushort local_res8 [4];
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  local_res8[0] = 0;
  plVar5 = param_1;
  while (((uVar3 = RfsCskvLexerStreamPeekChar(plVar5,local_res8), (char)uVar3 != '\0' &&
          (local_res8[0] < 0x21)) && ((0x100002601U >> ((ulonglong)local_res8[0] & 0x3f) & 1) != 0))
        ) {
    plVar5 = param_1;
    RfsCskvLexerStreamGetChar(param_1,local_res8);
  }
  uVar3 = RfsCskvLexerStreamPeekChar(param_1,local_res8);
  if ((char)uVar3 == '\0') {
    *(undefined4 *)param_2 = 0;
  }
  else {
    if ((local_res8[0] == 0x27) || (local_res8[0] == 0x22)) {
      lVar1 = param_1[5];
      param_2[1] = param_1[4];
      param_2[2] = lVar1;
      uVar4 = RfsCskvLexerGetString(param_1,(undefined4 *)param_2);
      return uVar4;
    }
    if (local_res8[0] == 0x2c) {
      RfsCskvLexerStreamGetChar(param_1,local_res8);
      uVar6 = 0x40008e94;
      *(undefined4 *)param_2 = 1;
    }
    else {
      if (local_res8[0] != 0x3d) {
        if (((ushort)(local_res8[0] - 0x41) < 0x3a) &&
           ((0x3ffffff43ffffffU >> ((ulonglong)(local_res8[0] - 0x41) & 0x3f) & 1) != 0)) {
          uVar4 = RfsCskvLexerGetIdentifier(param_1,(undefined4 *)param_2);
          return uVar4;
        }
        if ((local_res8[0] == 0x2d) ||
           (((ushort)(local_res8[0] - 0x30) < 10 || (iVar2 = iswdigit(local_res8[0]), iVar2 != 0))))
        {
          uVar4 = RfsCskvLexerGetNumber(param_1,(undefined4 *)param_2);
          return uVar4;
        }
        uVar4 = RfsCskvLexerGetError(param_1,(undefined4 *)param_2);
        return uVar4;
      }
      RfsCskvLexerStreamGetChar(param_1,local_res8);
      uVar6 = 0x40008e90;
      *(undefined4 *)param_2 = 2;
    }
    *(undefined4 *)(param_2 + 1) = 0x40002;
    *(undefined4 *)((longlong)param_2 + 0xc) = 0;
    *(undefined4 *)(param_2 + 2) = uVar6;
    *(undefined4 *)((longlong)param_2 + 0x14) = 1;
  }
  return 0;
}



===== RfsCskvLexerStreamAdvance @ 140018368 =====

void RfsCskvLexerStreamAdvance(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  
  uVar1 = *(ulonglong *)(param_1 + 0x10) + param_2;
  if ((uVar1 < *(ulonglong *)(param_1 + 0x10)) ||
     (*(ulonglong *)(param_1 + 0x10) = uVar1, *(ulonglong *)(param_1 + 8) < uVar1)) {
    *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(param_1 + 8);
  }
  return;
}



===== RfsCskvLexerStreamGetChar @ 140018390 =====

undefined8 RfsCskvLexerStreamGetChar(longlong *param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  ulonglong uVar2;
  
  uVar2 = param_1[2];
  if (uVar2 < (ulonglong)param_1[1]) {
    uVar1 = *(undefined2 *)(*param_1 + (uVar2 & 0xfffffffffffffffe));
    param_1[2] = uVar2 + 2;
    *param_2 = uVar1;
    return CONCAT71((int7)(uVar2 + 2 >> 8),1);
  }
  *param_2 = 0;
  return 0;
}



===== RfsCskvLexerStreamGetViewAsString @ 1400183c8 =====

void RfsCskvLexerStreamGetViewAsString(longlong *param_1,short *param_2)

{
  short sVar1;
  
  if ((ulonglong)param_1[1] <= (ulonglong)param_1[2]) {
    param_2[0] = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    return;
  }
  *(ulonglong *)(param_2 + 4) = *param_1 + (param_1[2] & 0xfffffffffffffffeU);
  sVar1 = -2;
  if ((ulonglong)(param_1[1] - param_1[2]) < 0xffff) {
    sVar1 = (short)param_1[1] - (short)param_1[2];
  }
  *param_2 = sVar1;
  param_2[1] = sVar1;
  return;
}



===== RfsCskvLexerStreamPeekChar @ 14001841c =====

undefined8 RfsCskvLexerStreamPeekChar(longlong *param_1,undefined2 *param_2)

{
  longlong lVar1;
  
  if ((ulonglong)param_1[2] < (ulonglong)param_1[1]) {
    lVar1 = *param_1;
    *param_2 = *(undefined2 *)(lVar1 + (param_1[2] & 0xfffffffffffffffeU));
    return CONCAT71((int7)((ulonglong)lVar1 >> 8),1);
  }
  *param_2 = 0;
  return 0;
}



===== RfsCskvParse @ 140018448 =====

int RfsCskvParse(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                longlong param_5)

{
  int iVar1;
  longlong *_Dst;
  
  _Dst = (longlong *)ExAllocatePool2(0x102,0x1007e,0x5266534c);
  if (_Dst == (longlong *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    memset(_Dst,0,0x80);
    *(undefined2 *)((longlong)_Dst + 0x22) = 0xfffe;
    _Dst[6] = (longlong)MupiUncHardeningRegistryParserCallback;
    _Dst[5] = (longlong)(_Dst + 0x10);
    _Dst[7] = (longlong)MupiUncHardeningRegistryParserErrorCallback;
    _Dst[8] = param_5;
    *_Dst = param_1;
    _Dst[1] = param_2;
    iVar1 = RfsCskvParseInner(_Dst);
    ExFreePoolWithTag(_Dst,0x5266534c);
  }
  return iVar1;
}



===== RfsCskvParseInner @ 140018508 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int RfsCskvParseInner(longlong *param_1)

{
  longlong *plVar1;
  ulonglong uVar2;
  longlong *plVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar5 = 0;
  *(undefined4 *)(param_1 + 3) = 0;
LAB_140018533:
  if (iVar5 < 0) {
    return iVar5;
  }
  plVar3 = param_1 + 9;
  uVar2 = RfsCskvLexerGetToken(param_1,plVar3);
  iVar5 = (int)uVar2;
  if (iVar5 < 0) {
    return iVar5;
  }
  iVar4 = (int)param_1[3];
  if (iVar4 == 0) {
    iVar4 = (int)*plVar3;
    if (iVar4 == 0) {
      return 0;
    }
    if (iVar4 == 1) {
      *(undefined4 *)(param_1 + 3) = 0;
      goto LAB_140018533;
    }
    if (iVar4 != 2) {
      if (iVar4 == 3) {
        *(undefined4 *)(param_1 + 3) = 1;
        param_1[0xd] = param_1[10];
        param_1[0xe] = param_1[0xb];
        goto LAB_140018533;
      }
      if ((iVar4 != 4) && (iVar4 = iVar4 + -5, iVar4 != 0)) goto LAB_1400186b7;
    }
    uVar6 = 2;
  }
  else {
    if (iVar4 == 1) {
      iVar4 = (int)*plVar3;
      if ((iVar4 == 0) || (iVar4 == 1)) {
LAB_140018685:
        uVar6 = 3;
        goto LAB_1400186e2;
      }
      if (iVar4 != 2) {
        if (((iVar4 != 3) && (iVar4 != 4)) && (iVar4 = iVar4 + -5, iVar4 != 0)) goto LAB_1400186b7;
        goto LAB_140018685;
      }
      *(undefined4 *)(param_1 + 3) = 2;
      goto LAB_140018533;
    }
    if (iVar4 == 2) {
      iVar4 = (int)*plVar3;
      if ((((iVar4 == 0) || (iVar4 == 1)) || (iVar4 == 2)) || (iVar4 == 3)) {
        uVar6 = 4;
        goto LAB_1400186e2;
      }
      iVar5 = iVar4 + -4;
      if (iVar5 == 0) {
        plVar3 = (longlong *)param_1[0xc];
        iVar5 = 0;
      }
      else {
        iVar4 = iVar4 + -5;
        if (iVar4 != 0) {
LAB_1400186b7:
          if (iVar4 != 1) goto LAB_1400186c0;
          uVar6 = *(undefined4 *)((longlong)param_1 + 0x4c);
          goto LAB_1400186e2;
        }
        plVar3 = param_1 + 10;
      }
      plVar1 = param_1 + 0xf;
      *plVar1 = (longlong)plVar3;
      *(undefined4 *)(param_1 + 3) = 3;
      iVar5 = (*(code *)param_1[6])(param_1 + 0xd,iVar5,plVar1,param_1[8]);
      param_1[0xd] = 0;
      param_1[0xe] = 0;
      *plVar1 = 0;
      goto LAB_140018533;
    }
    if (iVar4 != 3) {
      if (iVar4 == 4) {
        iVar4 = (int)*plVar3;
        if (iVar4 == 0) {
          return 0;
        }
        if (iVar4 == 1) goto LAB_1400185e4;
        if (((iVar4 == 2) || (iVar4 == 3)) || ((iVar4 == 4 || ((iVar4 == 5 || (iVar4 == 6)))))) {
          *(undefined4 *)(param_1 + 3) = 4;
          goto LAB_140018533;
        }
      }
LAB_1400186c0:
      iVar5 = -0x3fffff1b;
      goto LAB_140018533;
    }
    iVar4 = (int)*plVar3;
    if (iVar4 == 0) {
      return 0;
    }
    if (iVar4 == 1) {
LAB_1400185e4:
      *(undefined4 *)(param_1 + 3) = 0;
      param_1[0xd] = 0;
      param_1[0xe] = 0;
      param_1[0xf] = 0;
      goto LAB_140018533;
    }
    if (((iVar4 != 2) && (iVar4 != 3)) && ((iVar4 != 4 && (iVar4 = iVar4 + -5, iVar4 != 0))))
    goto LAB_1400186b7;
    uVar6 = 5;
  }
LAB_1400186e2:
  *(undefined4 *)(param_1 + 3) = 4;
  iVar5 = (*(code *)param_1[7])(uVar6,param_1 + 10,param_1[8]);
  goto LAB_140018533;
}



===== MupSetupRelatedSurrogateFileContextList @ 140018730 =====

undefined4 MupSetupRelatedSurrogateFileContextList(longlong param_1,char param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  uint uVar5;
  undefined8 *puVar6;
  
  uVar3 = 0;
  uVar5 = 0;
  if (*(longlong *)(param_1 + 0xf8) != 0) {
    uVar5 = *(uint *)(*(longlong *)(param_1 + 0xf8) + 0x58);
  }
  puVar6 = (undefined8 *)(*(longlong *)(param_1 + 0x98) + 200);
  puVar4 = (undefined8 *)*puVar6;
  do {
    if (puVar4 == puVar6) {
LAB_1400187ab:
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
        WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
                  &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,param_1,(char)uVar3);
      }
      return uVar3;
    }
    lVar1 = puVar4[2];
    if (((uVar5 & ~*(uint *)(lVar1 + 0x6c)) == 0) &&
       ((param_2 != '\x01' || ((*(uint *)(lVar1 + 0x70) & 1) != 0)))) {
      LOCK();
      *(int *)(lVar1 + 4) = *(int *)(lVar1 + 4) + 1;
      UNLOCK();
      lVar2 = MupiAllocSurrogateFileContext(lVar1,param_1);
      if (lVar2 == 0) {
        MupReleaseSurrogateProvider(lVar1);
        uVar3 = 0xc000009a;
        goto LAB_1400187ab;
      }
    }
    puVar4 = (undefined8 *)*puVar4;
  } while( true );
}



===== MupiAllocSurrogateFileContext @ 140018830 =====

void MupiAllocSurrogateFileContext(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)ExAllocatePool2(0x102,0x30,0x6653754d);
  if (puVar4 != (undefined4 *)0x0) {
    plVar1 = (longlong *)(puVar4 + 2);
    *(undefined8 *)(puVar4 + 2) = 0;
    *(undefined8 *)(puVar4 + 4) = 0;
    *(undefined8 *)(puVar4 + 10) = 0;
    *puVar4 = 0x307109;
    puVar4[1] = 1;
    *(longlong *)(puVar4 + 8) = param_2;
    *(undefined8 *)(puVar4 + 6) = param_1;
    *(int *)(param_2 + 0xd8) = *(int *)(param_2 + 0xd8) + 0x90;
    plVar2 = *(longlong **)(param_2 + 0xd0);
    if (*plVar2 != param_2 + 200) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    *plVar1 = param_2 + 200;
    *(longlong **)(puVar4 + 4) = plVar2;
    *plVar2 = (longlong)plVar1;
    *(longlong **)(param_2 + 0xd0) = plVar1;
  }
  return;
}



===== MupiCancelQueryIrp @ 1400188d4 =====

void MupiCancelQueryIrp(longlong param_1,undefined1 param_2,undefined8 param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined1 uVar4;
  
  uVar4 = (undefined1)param_3;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qqqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,param_3,
                *(undefined8 *)(param_1 + 0x20),(char)*(undefined8 *)(param_1 + 0x30),param_2,uVar4)
    ;
  }
  cVar1 = IoCancelIrp(*(undefined8 *)(param_1 + 0x20));
  if (cVar1 != '\0') {
    iVar2 = KeReadStateEvent(param_1 + 0x38);
    if (iVar2 != 0) goto LAB_1400189cb;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    pcVar3 = "";
    if (cVar1 == '\0') {
      pcVar3 = "NOT";
    }
    WPP_SF_qqqqs(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),"NOT",param_3,
                 *(undefined8 *)(param_1 + 0x20),(char)*(undefined8 *)(param_1 + 0x30),param_2,uVar4
                 ,pcVar3);
  }
  param_3 = 0;
  KeWaitForSingleObject(param_1 + 0x38,0,0,0,0);
LAB_1400189cb:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qqqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,param_3,
                *(undefined8 *)(param_1 + 0x20),(char)*(undefined8 *)(param_1 + 0x30),param_2,uVar4)
    ;
  }
  return;
}



===== MupAllocFileContextForRelativeOpen @ 140018a28 =====

int MupAllocFileContextForRelativeOpen(ushort *param_1,longlong param_2,undefined8 *param_3)

{
  ushort *puVar1;
  ushort uVar2;
  short sVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  undefined2 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar9 = (uint)(*(ushort *)(param_2 + 0x60) >> 1);
  bVar4 = false;
  uVar10 = (uint)(*param_1 >> 1);
  bVar5 = false;
  iVar6 = 0;
  uVar8 = uVar9;
  if ((uVar10 != 0) && (uVar9 != 0)) {
    sVar3 = *(short *)(*(longlong *)(param_2 + 0x68) + (ulonglong)(uVar9 - 1) * 2);
    if (**(short **)(param_1 + 4) == 0x3a) {
      if (sVar3 == 0x5c) {
        bVar5 = true;
        uVar8 = uVar9 - 1;
      }
    }
    else if (sVar3 != 0x5c) {
      bVar4 = true;
      uVar8 = uVar9 + 1;
    }
  }
  if ((uVar8 + uVar10) * 2 < 0xffff) {
    puVar7 = MupAllocFileContext(uVar8 + uVar10);
    if (puVar7 == (undefined2 *)0x0) {
      iVar6 = -0x3fffff66;
    }
    else {
      uVar2 = *(ushort *)(param_2 + 0x60);
      puVar1 = puVar7 + 0x30;
      if (uVar2 != 0) {
        *puVar1 = uVar2;
        *(undefined8 *)(puVar7 + 0x14) = *(undefined8 *)puVar1;
        *(undefined8 *)(puVar7 + 0x18) = *(undefined8 *)(puVar7 + 0x34);
        memmove(*(void **)(puVar7 + 0x34),*(void **)(param_2 + 0x68),(ulonglong)uVar2);
      }
      if (bVar4) {
        *(undefined2 *)(*(longlong *)(puVar7 + 0x34) + (ulonglong)uVar9 * 2) = 0x5c;
        *puVar1 = *puVar1 + 2;
      }
      else if (bVar5) {
        *puVar1 = *puVar1 - 2;
      }
      if (uVar10 != 0) {
        iVar6 = RtlAppendUnicodeStringToString(puVar1,param_1);
      }
      puVar7[0x14] = *puVar1;
      if (iVar6 == 0) {
        *param_3 = puVar7;
      }
    }
  }
  else {
    iVar6 = -0x3ffffff3;
  }
  return iVar6;
}



===== MupAllocFileContext @ 140018b90 =====

undefined2 * MupAllocFileContext(int param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 *_Dst;
  size_t _Size;
  
  iVar2 = param_1 * 2;
  _Size = 0x108;
  if (iVar2 != 0) {
    _Size = (size_t)(iVar2 + 0x100);
  }
  _Dst = (undefined2 *)ExAllocatePool2(0x42,_Size,0x6346754d);
  if (_Dst != (undefined2 *)0x0) {
    memset(_Dst,0,_Size);
    *_Dst = 0x7108;
    puVar1 = _Dst + 100;
    _Dst[1] = (short)_Size;
    *(undefined4 *)(_Dst + 2) = 1;
    *(undefined2 **)(_Dst + 0x68) = puVar1;
    *(undefined2 **)puVar1 = puVar1;
    _Dst[0x80] = 0;
    *(undefined2 **)(_Dst + 0x34) = _Dst + 0x80;
    uVar3 = 2;
    if (iVar2 != 0) {
      uVar3 = (short)iVar2;
    }
    *(undefined4 *)(_Dst + 0x50) = 0;
    _Dst[0x31] = uVar3;
    _Dst[0x30] = 0;
  }
  return _Dst;
}



===== MupiDeInitQueryContext @ 140018c4c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MupiDeInitQueryContext(void *param_1)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  longlong lVar4;
  longlong *plVar5;
  code *pcVar6;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,
             &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,param_1);
  }
  LOCK();
  piVar1 = (int *)((longlong)param_1 + 4);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    KeAcquireGuardedMutex(&DAT_14000bb58);
    plVar2 = (longlong *)((longlong)param_1 + 8);
    lVar4 = *plVar2;
    if ((*(longlong **)(lVar4 + 8) != plVar2) ||
       (plVar5 = *(longlong **)((longlong)param_1 + 0x10), (longlong *)*plVar5 != plVar2)) {
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)(3);
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    *plVar5 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar5;
    _DAT_14000bb90 = _DAT_14000bb90 + -1;
    KeReleaseGuardedMutex(&DAT_14000bb58);
    if (*(longlong *)((longlong)param_1 + 0xa8) != 0) {
      ExFreePoolWithTag();
    }
    memset(param_1,0,0xb0);
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,
               &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,param_1);
    }
  }
  return;
}



===== MupSurrogateResolvePrefix @ 140018d70 =====

ulonglong MupSurrogateResolvePrefix(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong local_res8;
  
                    /* 0x18d70  11  MupSurrogateResolvePrefix */
  local_res8 = 0;
  lVar2 = *(longlong *)(param_1 + -0x10);
  lVar3 = *(longlong *)(*(longlong *)(param_1 + -8) + 0x18);
  if (*(longlong *)(lVar2 + 0x40) == param_1 + -0x28) {
    lVar4 = *(longlong *)(param_1 + 0x40);
    iVar1 = *(int *)(param_1 + 0x48);
    if ((lVar4 == 0) || (iVar1 == 0)) {
      lVar7 = 0;
      iVar5 = 0;
    }
    else {
      lVar7 = lVar4;
      iVar5 = iVar1;
    }
    *(longlong *)(lVar2 + 0x58) = lVar7;
    *(int *)(lVar2 + 0x60) = iVar5;
    lVar7 = *(longlong *)(lVar2 + 0x28);
    if (*(longlong *)(lVar7 + 0xa8) != 0) {
      MupReleaseUncProvider(*(longlong *)(lVar7 + 0xa8));
      *(undefined8 *)(lVar7 + 0xa8) = 0;
    }
    uVar6 = MupLocateUncProviderForPath
                      (lVar7,*(longlong *)(lVar2 + 0x10),&local_res8,lVar3,lVar4,iVar1,
                       *(undefined4 **)(param_1 + 0x50),*(undefined **)(lVar2 + 0x30));
    if ((int)uVar6 == 0) {
      *(longlong *)(lVar7 + 0xa8) = local_res8;
      if (*(longlong *)(lVar7 + 0xb8) == 0) {
        LOCK();
        *(int *)(lVar3 + 4) = *(int *)(lVar3 + 4) + 1;
        UNLOCK();
        *(longlong *)(lVar7 + 0xb8) = lVar3;
      }
    }
    else {
      *(undefined8 *)(lVar2 + 0x58) = 0;
      *(undefined4 *)(lVar2 + 0x60) = 0;
    }
  }
  else {
    uVar6 = 0xc0000010;
  }
  return uVar6;
}



===== MupiCreateWithRelativePath @ 140018e8c =====

int MupiCreateWithRelativePath(longlong param_1,char param_2,longlong *param_3)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong local_res20;
  
  lVar5 = 0;
  local_res20 = 0;
  *param_3 = 0;
  if ((*(ushort *)(param_1 + 0x58) < 2) || (**(short **)(param_1 + 0x60) != 0x5c)) {
    lVar4 = MupFindFileContext(*(undefined8 *)(param_1 + 0x40));
    if (lVar4 == 0) {
      iVar3 = -0x3ffffff0;
    }
    else {
      iVar3 = MupAllocFileContextForRelativeOpen((ushort *)(param_1 + 0x58),lVar4,&local_res20);
      lVar5 = local_res20;
      if (iVar3 == 0) {
        *(longlong *)(local_res20 + 0x90) = param_1;
        *(longlong *)(local_res20 + 0x98) = lVar4;
        if (*(longlong *)(lVar4 + 0x58) != 0) {
          iVar3 = MupSetupUndecoratedFileNameForRelativeOpen(local_res20);
        }
        if (iVar3 == 0) {
          lVar2 = *(longlong *)(lVar4 + 0xb8);
          if (lVar2 == 0) {
            lVar2 = *(longlong *)(lVar4 + 0xa8);
            if (lVar2 != 0) {
              LOCK();
              *(int *)(lVar2 + 4) = *(int *)(lVar2 + 4) + 1;
              UNLOCK();
              lVar5 = local_res20;
            }
            *(longlong *)(lVar5 + 0xa8) = lVar2;
          }
          else {
            *(undefined8 *)(lVar5 + 0xa8) = 0;
            LOCK();
            piVar1 = (int *)(lVar2 + 4);
            *piVar1 = *piVar1 + 1;
            UNLOCK();
            lVar5 = local_res20;
          }
          *(undefined4 *)(lVar5 + 0xa0) = *(undefined4 *)(lVar4 + 0xa0);
          *(longlong *)(lVar5 + 0xb8) = *(longlong *)(lVar4 + 0xb8);
          MupSaveProviderStrippedFileName(lVar5,'\x01');
          MupSaveStrippedFileName(lVar5,'\x01');
          iVar3 = MupInitializeUncHardeningFileContext
                            ((undefined4 *)(lVar5 + 0x80),(undefined8 *)(lVar5 + 0xf8));
          if (-1 < iVar3) {
            iVar3 = MupSetupRelatedSurrogateFileContextList(lVar5,param_2);
          }
        }
      }
    }
  }
  else {
    iVar3 = -0x3ffffff3;
  }
  if ((iVar3 == 0) || (lVar5 == 0)) {
    *param_3 = lVar5;
  }
  else {
    MupReleaseFileContext(lVar5);
    *param_3 = 0;
  }
  return iVar3;
}



===== MupiTriggerStartProvider @ 140019054 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool MupiTriggerStartProvider(ulonglong param_1,ushort *param_2,undefined8 param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  ulonglong uVar6;
  short sVar7;
  short *psVar8;
  ushort uVar9;
  ushort uVar10;
  undefined4 local_res8 [2];
  undefined4 local_res20 [2];
  undefined8 local_68;
  short *psStack_60;
  short local_58;
  short sStack_56;
  undefined4 uStack_54;
  short *psStack_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  local_68 = 0;
  local_48 = *(undefined4 *)(param_1 + 0x48);
  uStack_44 = *(undefined4 *)(param_1 + 0x4c);
  uStack_40 = *(undefined4 *)(param_1 + 0x50);
  uStack_3c = *(undefined4 *)(param_1 + 0x54);
  local_res20[0] = 0;
  local_res8[0] = 0;
  bVar4 = true;
  uStack_54 = 0;
  psVar8 = *(short **)(param_1 + 0x50);
  uVar10 = (ushort)local_48;
  while( true ) {
    uVar9 = uVar10;
    psStack_50 = psVar8;
    if ((uVar9 == 0) || (psStack_50 == (short *)0x0)) {
      return false;
    }
    uVar6 = (ulonglong)(uVar9 >> 1);
    for (psVar8 = psStack_50; (uVar6 != 0 && (*psVar8 != 0)); psVar8 = psVar8 + 1) {
      uVar6 = uVar6 - 1;
    }
    if (uVar6 == 0) break;
    uVar2 = ((uVar9 >> 1) - uVar6) * 2;
    sVar7 = (short)uVar2;
    _local_58 = CONCAT22(sVar7,sVar7);
    uVar6 = uVar2;
    if (uVar2 < uVar9) {
      uVar6 = uVar2 + 2;
    }
    psVar8 = (short *)((longlong)psStack_50 + uVar6);
    uVar10 = uVar9 - (short)uVar6;
    if ((((sVar7 != 0) && ((uVar2 & 0xffff) + 4 <= (ulonglong)*param_2)) &&
        (psStack_60 = *(short **)(param_2 + 4), *psStack_60 == 0x5c)) &&
       (*(short *)((longlong)psStack_60 + (uVar2 & 0xfffe) + 2) == 0x5c)) {
      psStack_60 = psStack_60 + 1;
      local_68._0_4_ = CONCAT22(sVar7,sVar7);
      cVar3 = RtlEqualUnicodeString(&local_58,&local_68,CONCAT71((uint7)(byte)(uVar9 >> 8),1));
      if (cVar3 != '\0') {
        MupiLockProviderTriggerStartExclusive(param_1);
        if ((*(longlong *)(param_1 + 0x70) != 0) || (*(int *)(param_1 + 0x44) != 3)) {
          if ((*(longlong *)(param_1 + 0x80) == 0) ||
             (299999999 < (ulonglong)(_DAT_fffff78000000008 - *(longlong *)(param_1 + 0x80)))) {
            *(longlong *)(param_1 + 0x70) = *(longlong *)(param_1 + 0x70) + 1;
            lVar1 = *(longlong *)(param_1 + 0x70);
            MupiUnlockProviderTriggerStartExclusive(param_1);
            if ((lVar1 == 1) &&
               (((iVar5 = ZwQueryWnfStateData(param_1 + 0x60,0,0,local_res8,0,local_res20),
                 iVar5 < 0 ||
                 (uVar6 = param_1,
                 iVar5 = ExSubscribeWnfStateChange
                                   (param_1 + 0x78,param_1 + 0x60,1,local_res8[0],
                                    MupiTriggerStartWnfCallback,param_1), iVar5 < 0)) ||
                (iVar5 = ZwUpdateWnfStateData(param_1 + 0x58,0,0,0,0,uVar6 & 0xffffffff00000000,0),
                iVar5 < 0)))) {
              KeSetEvent(*(undefined8 *)(param_1 + 0x88),0,0);
            }
            bVar4 = MupiWaitForProviderTriggerStart(param_1,param_3);
            return bVar4;
          }
          bVar4 = false;
        }
        MupiUnlockProviderTriggerStartExclusive(param_1);
        return bVar4;
      }
    }
  }
  return false;
}



===== MupiAllocQueryIrp @ 1400192a8 =====

longlong MupiAllocQueryIrp(longlong param_1)

{
  longlong lVar1;
  void *pvVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 uVar6;
  bool bVar7;
  
  lVar4 = *(longlong *)(param_1 + 0x30);
  bVar7 = (*(uint *)(lVar4 + 0x94) & 8) != 0;
  if (bVar7) {
    lVar5 = IoGetRelatedDeviceObject(*(undefined8 *)(lVar4 + 0xa0));
    uVar6 = 0x14018f;
  }
  else {
    lVar5 = *(longlong *)(lVar4 + 0xa8);
    uVar6 = 0x140193;
  }
  lVar3 = IoAllocateIrp(*(char *)(lVar5 + 0x4c) + '\x01',0);
  if (lVar3 != 0) {
    *(undefined1 *)(lVar3 + 0x40) = 0;
    *(undefined8 *)(lVar3 + 0xc0) = *(undefined8 *)(lVar4 + 0xa0);
    pvVar2 = SystemReserved1[0xf];
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(char *)(lVar3 + 0x43) = *(char *)(lVar3 + 0x43) + -1;
    *(void **)(lVar3 + 0x98) = pvVar2;
    *(longlong *)(lVar3 + 0xb8) = lVar1 + -0x48;
    *(code **)(lVar1 + -0x58) = MupiQueryPathCompletionRoutine;
    *(longlong *)(lVar1 + -0x50) = param_1;
    *(undefined1 *)(lVar1 + -0x8d) = 0xe0;
    lVar1 = *(longlong *)(lVar3 + 0xb8);
    *(undefined2 *)(lVar1 + -0x48) = 0xe;
    *(undefined8 *)(lVar1 + -0x18) = *(undefined8 *)(lVar4 + 0xa0);
    *(longlong *)(lVar1 + -0x20) = lVar5;
    *(undefined4 *)(lVar1 + -0x30) = uVar6;
    *(undefined4 *)(lVar1 + -0x40) = 4;
    if (bVar7) {
      *(int *)(lVar1 + -0x38) = **(int **)(param_1 + 0xa8) + 0x18;
      lVar4 = *(longlong *)(param_1 + 0xa8);
    }
    else {
      *(undefined4 *)(lVar1 + -0x38) = 0x50;
      lVar4 = param_1 + 0x58;
    }
    *(longlong *)(lVar1 + -0x28) = lVar4;
    *(undefined8 *)(lVar3 + 8) = 0;
    *(undefined8 *)(lVar3 + 0x18) = 0;
    *(longlong *)(lVar3 + 0x70) = param_1 + 0x50;
  }
  return lVar3;
}



===== MupiIssueQueryRequest @ 140019410 =====

int MupiIssueQueryRequest(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x30);
  iVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0xa8),*(undefined8 *)(param_1 + 0x20));
  if (iVar2 == 0x103) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
      WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,
               &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,(wchar_t *)(lVar1 + 0x18));
    }
    iVar2 = FsRtlCancellableWaitForSingleObject(param_1 + 0x38,0,*(undefined8 *)(param_1 + 0x18));
    if ((iVar2 == -0x3ffffee0) || (iVar2 == -0x3fffffb5)) {
      lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x30) + 0xa8);
      MupiCancelQueryIrp(param_1,(char)lVar1,*(undefined8 *)(lVar1 + 8));
    }
  }
  else {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
      WPP_SF_Zdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,
                 &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,(wchar_t *)(lVar1 + 0x18),
                 (char)iVar2,(char)*(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0x30));
    }
    iVar2 = 0;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x25,
              &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,param_1,(char)iVar2);
  }
  return iVar2;
}



===== MupLocateUncProviderForPath @ 140019570 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong MupLocateUncProviderForPath
                    (longlong param_1,longlong param_2,longlong *param_3,undefined8 param_4,
                    undefined8 param_5,undefined4 param_6,undefined4 *param_7,undefined *param_8)

{
  longlong lVar1;
  code *pcVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  ulonglong uVar10;
  undefined *puVar11;
  longlong lVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  uint *puVar15;
  uint uVar16;
  longlong lVar17;
  undefined8 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  longlong lVar21;
  longlong lVar22;
  undefined8 *puVar23;
  undefined8 uVar24;
  wchar_t *pwVar25;
  ulonglong uVar26;
  char cVar27;
  bool bVar28;
  undefined1 auStackY_1a8 [8];
  undefined1 auStackY_1a0 [24];
  uint local_150 [2];
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  longlong local_130;
  undefined8 local_128;
  uint *local_120;
  wchar_t *local_118;
  undefined4 local_108;
  undefined4 local_104;
  undefined *local_100;
  undefined **local_f8;
  longlong local_f0;
  longlong local_e8;
  longlong local_e0;
  undefined8 *local_d8;
  undefined1 local_d0 [24];
  uint local_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined8 local_78;
  undefined8 local_70;
  uint *local_60;
  
  cVar27 = '\0';
  local_150[0] = 0;
  uVar24 = 0xb0;
  memset(&local_108,0,0xb0);
  iVar9 = 0;
  local_140 = 0;
  local_138 = 0;
  local_148 = 0;
  local_128 = *(undefined8 *)(*(longlong *)(param_2 + 0xb8) + 8);
  lVar22 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  local_130 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_Zqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,uVar24,(wchar_t *)(lVar22 + 0x58),
               (char)lVar22,(char)param_4);
  }
  puVar19 = auStackY_1a8;
  if (*(longlong *)(param_1 + 0xf8) == 0) {
    uVar16 = 0;
  }
  else {
    uVar16 = *(uint *)(*(longlong *)(param_1 + 0xf8) + 0x58);
  }
  puVar15 = local_150;
  uVar10 = MupGetRequiredHardeningCapabilitiesFromIrp(param_2,puVar15);
  uVar26 = uVar10 & 0xffffffff;
  puVar20 = auStackY_1a8;
  if ((int)uVar10 < 0) goto LAB_1400197b3;
  uVar7 = uVar16 | local_150[0];
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_DDqZ(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar15,uVar24,local_150[0],(char)uVar16,
                (char)lVar22,(wchar_t *)(lVar22 + 0x58));
  }
  pwVar25 = (wchar_t *)(lVar22 + 0x58);
  local_118 = pwVar25;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,pwVar25);
  }
  lVar17 = 0;
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_14000b7c0,1);
  puVar11 = param_8;
  if (param_8 == (undefined *)0x0) {
    puVar11 = MupGetUncCacheHostPrefixTable();
  }
  lVar12 = RtlFindUnicodePrefix(puVar11,pwVar25,1);
  lVar21 = lVar12 + -0x10;
  if (lVar12 == 0) {
    lVar21 = 0;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,pwVar25,(char)lVar21);
  }
  lVar12 = 0;
  if (lVar21 != 0) {
    lVar17 = *(longlong *)(lVar21 + 0x68);
    LOCK();
    *(int *)(lVar17 + 4) = *(int *)(lVar17 + 4) + 1;
    UNLOCK();
    lVar1 = *(longlong *)(lVar21 + 0x70);
    iVar9 = *(int *)(lVar21 + 0x88);
    cVar27 = *(char *)(lVar21 + 0x8c);
    if (lVar1 != 0) {
      LOCK();
      *(int *)(lVar1 + 4) = *(int *)(lVar1 + 4) + 1;
      UNLOCK();
      lVar12 = lVar1;
    }
  }
  ExReleaseResourceLite(&DAT_14000b7c0);
  KeLeaveCriticalRegion();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,lVar17);
  }
  *param_3 = lVar17;
  if (lVar17 == 0) {
LAB_14001981b:
    FsRtlGetEcpListFromIrp(param_2,&local_140);
    uVar24 = local_140;
    local_b0 = local_128;
    local_a8 = param_6;
    local_a0 = param_5;
    local_108 = 0xb07105;
    local_104 = 1;
    local_60 = (uint *)0x0;
    local_f0 = param_2;
    local_e0 = lVar22;
    local_70 = MupGetSiloFromFileObject();
    local_98 = *(undefined4 *)pwVar25;
    uStack_94 = *(undefined4 *)(pwVar25 + 2);
    uStack_90 = *(undefined4 *)(pwVar25 + 4);
    uStack_8c = *(undefined4 *)(pwVar25 + 6);
    if (param_7 != (undefined4 *)0x0) {
      local_88 = *param_7;
      uStack_84 = param_7[1];
      uStack_80 = param_7[2];
      uStack_7c = param_7[3];
    }
    local_78 = uVar24;
    local_b8 = 0;
    KeAcquireGuardedMutex(&DAT_14000bb58);
    if (*DAT_14000bb50 == &DAT_14000bb48) {
      local_100 = &DAT_14000bb48;
      local_f8 = DAT_14000bb50;
      *DAT_14000bb50 = (undefined *)&local_100;
      DAT_14000bb50 = &local_100;
      _DAT_14000bb90 = _DAT_14000bb90 + 1;
      KeReleaseGuardedMutex(&DAT_14000bb58);
      puVar19 = auStackY_1a8;
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) goto LAB_140019922;
      puVar11 = WPP_GLOBAL_Control;
      puVar19 = auStackY_1a8;
      puVar20 = auStackY_1a8;
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) == 0) goto LAB_140019922;
    }
    else {
      puVar11 = (undefined *)0x3;
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)();
      puVar20 = auStackY_1a0;
    }
    puVar19 = puVar20;
    uVar24 = *(undefined8 *)(puVar11 + 0x18);
    *(undefined4 **)(puVar19 + 0x20) = &local_108;
    *(undefined8 *)(puVar19 + -8) = 0x140019e56;
    WPP_SF_qq(uVar24,0x20,&WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,lVar22,puVar19[0x20]);
LAB_140019922:
    *(undefined8 *)(puVar19 + -8) = 0x140019933;
    uVar24 = MupiCheckForProviderAvoidPath
                       ((ushort *)&local_98,(undefined8 *)(puVar19 + 0x70),(undefined1 *)0x0);
    if ((char)uVar24 != '\0') {
      *(undefined8 *)(puVar19 + -8) = 0x140019e65;
      puVar13 = MupAcquireUncProviderByName(*(wchar_t **)(puVar19 + 0x70));
      *(undefined8 **)(puVar19 + 0x60) = puVar13;
    }
    bVar6 = false;
    local_120 = (uint *)0x0;
    bVar4 = false;
    puVar19[0x40] = 0;
    *(undefined4 *)(puVar19 + 0x4c) = 0;
    iVar9 = 0;
    puVar13 = (undefined8 *)0x0;
    uVar10 = 0xc0000001;
    bVar5 = false;
LAB_14001996e:
    uVar26 = uVar10;
    lVar22 = local_f0;
    puVar18 = *(undefined8 **)(puVar19 + 0x78);
    puVar23 = puVar13;
    if (puVar18 == (undefined8 *)0x0) {
      do {
        puVar18 = (undefined8 *)0x0;
        *(undefined8 *)(puVar19 + -8) = 0x14001998a;
        KeEnterCriticalRegion();
        *(undefined8 *)(puVar19 + -8) = 0x14001999f;
        ExAcquireResourceSharedLite(&DAT_14000b7c0,1);
        bVar6 = false;
        bVar28 = false;
        if (puVar23 == (undefined8 *)0x0) {
LAB_140019e84:
          *(int *)(puVar19 + 0x44) = DAT_14000b7b8;
          puVar14 = DAT_14000b7a8;
        }
        else {
          if (iVar9 != DAT_14000b7b8) {
            bVar6 = true;
            goto LAB_140019e84;
          }
          puVar14 = (undefined8 *)puVar23[1];
          *(int *)(puVar19 + 0x44) = iVar9;
        }
        bVar3 = false;
        for (; (undefined8 **)puVar14 != &DAT_14000b7a8; puVar14 = (undefined8 *)*puVar14) {
          iVar9 = *(int *)((longlong)puVar14 + 0x3c);
          puVar18 = puVar14 + -1;
          if (((iVar9 - 2U < 2) || ((iVar9 == 1 && (puVar14[9] != 0)))) &&
             ((!bVar6 || (puVar18 != puVar23)))) {
            bVar28 = iVar9 == 1;
            if (!bVar28) {
              LOCK();
              *(int *)((longlong)puVar14 + -4) = *(int *)((longlong)puVar14 + -4) + 1;
              UNLOCK();
            }
            bVar3 = true;
            break;
          }
        }
        *(undefined8 *)(puVar19 + -8) = 0x140019a1f;
        ExReleaseResourceLite(&DAT_14000b7c0);
        *(undefined8 *)(puVar19 + -8) = 0x140019a2b;
        KeLeaveCriticalRegion();
        puVar23 = (undefined8 *)0x0;
        if (bVar3) {
          puVar23 = puVar18;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
          uVar24 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(undefined8 *)(puVar19 + -8) = 0x140019eba;
          WPP_SF_q(uVar24,0xe,&WPP_b8ec61bc8b283db232150b702b34e2f1_Traceguids,puVar23);
        }
        if (!bVar28) goto code_r0x000140019a64;
        *(undefined8 *)(puVar19 + -8) = 0x140019bc0;
        bVar6 = MupiTriggerStartProvider((ulonglong)puVar23,(ushort *)&local_98,lVar22);
        if (bVar6) {
          *(undefined8 *)(puVar19 + -8) = 0x140019ec6;
          KeEnterCriticalRegion();
          *(undefined8 *)(puVar19 + -8) = 0x140019edb;
          ExAcquireResourceSharedLite(&DAT_14000b7c0,1);
          if (*(int *)((longlong)puVar23 + 0x44) - 2U < 2) {
            LOCK();
            *(int *)((longlong)puVar23 + 4) = *(int *)((longlong)puVar23 + 4) + 1;
            UNLOCK();
            *(undefined8 *)(puVar19 + -8) = 0x140019f1a;
            ExReleaseResourceLite(&DAT_14000b7c0);
            goto LAB_140019faf;
          }
          *(undefined8 *)(puVar19 + -8) = 0x140019ef9;
          ExReleaseResourceLite();
          *(undefined8 *)(puVar19 + -8) = 0x140019f05;
          KeLeaveCriticalRegion();
        }
        iVar9 = *(int *)(puVar19 + 0x44);
      } while( true );
    }
    puVar23 = (undefined8 *)0x0;
    if (puVar13 != puVar18) {
      puVar23 = puVar18;
    }
    goto LAB_140019a89;
  }
  if (lVar12 != 0) {
    MupReleaseSurrogateProvider(lVar12);
    lVar17 = *param_3;
  }
  uVar26 = 0;
  if ((param_7 != (undefined4 *)0x0) && (cVar27 == '\0')) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
              &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids);
      lVar17 = *param_3;
    }
    uVar26 = 0xc0000225;
  }
  if ((uVar7 & ~*(uint *)(lVar17 + 0x98)) == 0) {
    puVar19 = auStackY_1a8;
    if (((int)uVar26 < 0) && (puVar19 = auStackY_1a8, (int)uVar26 != -0x3ffffdff)) {
      if (iVar9 == 0) goto LAB_140019e14;
      local_130 = lVar17;
      goto LAB_140019c97;
    }
  }
  else {
    if (iVar9 == 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids);
        lVar17 = *param_3;
      }
LAB_140019e14:
      MupReleaseUncProvider(lVar17);
LAB_140019c97:
      *param_3 = 0;
      pwVar25 = local_118;
      goto LAB_14001981b;
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids);
    }
    uVar26 = 0xc0000201;
  }
LAB_1400197ae:
  lVar22 = *(longlong *)(puVar19 + 0x50);
  puVar20 = puVar19;
LAB_1400197b3:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    uVar24 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(int *)(puVar20 + 0x20) = (int)uVar26;
    *(undefined8 *)(puVar20 + -8) = 0x14001a098;
    WPP_SF_qD(uVar24,0x1b,&WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,lVar22,puVar20[0x20]);
  }
  return uVar26;
code_r0x000140019a64:
  if (((puVar23 != (undefined8 *)0x0) && (puVar23[10] != 0)) && (puVar23[0xe] != 0)) {
    *(undefined8 *)(puVar19 + -8) = 0x140019f36;
    KeEnterCriticalRegion();
    *(undefined8 *)(puVar19 + -8) = 0x140019f48;
    ExAcquirePushLockExclusiveEx(puVar23 + 0xd,0);
    if (puVar23[0xe] != 0) {
      uVar24 = puVar23[0x11];
      *(undefined8 *)(puVar19 + -8) = 0x140019f62;
      iVar9 = KeReadStateEvent(uVar24);
      if (iVar9 == 0) {
        puVar23[0xe] = puVar23[0xe] + 1;
        *(undefined8 *)(puVar19 + -8) = 0x140019f7c;
        ExReleasePushLockExclusiveEx(puVar23 + 0xd,0);
        *(undefined8 *)(puVar19 + -8) = 0x140019f88;
        KeLeaveCriticalRegion();
        *(undefined8 *)(puVar19 + -8) = 0x140019f98;
        MupiWaitForProviderTriggerStart((longlong)puVar23,lVar22);
        goto LAB_140019a74;
      }
    }
    *(undefined8 *)(puVar19 + -8) = 0x140019faa;
    ExReleasePushLockExclusiveEx(puVar23 + 0xd,0);
LAB_140019faf:
    *(undefined8 *)(puVar19 + -8) = 0x140019fb6;
    KeLeaveCriticalRegion();
  }
LAB_140019a74:
  iVar9 = *(int *)(puVar19 + 0x44);
  bVar6 = bVar4;
LAB_140019a89:
  if (puVar13 != (undefined8 *)0x0) {
    *(undefined8 *)(puVar19 + -8) = 0x140019a96;
    MupReleaseUncProvider((longlong)puVar13);
  }
  if (puVar23 == (undefined8 *)0x0) goto LAB_140019c12;
  uVar16 = *(uint *)((longlong)puVar23 + 0x94);
  puVar19[0x40] = 1;
  puVar13 = puVar23;
  uVar10 = uVar26;
  if ((((uVar16 & 0x10) == 0) && (param_7 != (undefined4 *)0x0)) ||
     ((param_8 != (undefined *)0x0 && ((uVar16 & 0x20) == 0)))) goto LAB_14001996e;
  uVar7 = *(uint *)(puVar19 + 0x48);
  if ((uVar7 & ~*(uint *)(puVar23 + 0x13)) != 0) goto LAB_14001996e;
  bVar5 = true;
  bVar28 = true;
  if (puVar23 == *(undefined8 **)(puVar19 + 0x60)) {
    *(undefined8 *)(puVar19 + -8) = 0x140019fd6;
    MupReleaseUncProvider((longlong)*(undefined8 **)(puVar19 + 0x60));
    *(undefined8 *)(puVar19 + 0x60) = 0;
    bVar5 = bVar28;
    goto LAB_14001996e;
  }
  if (((uVar16 & 8) != 0) && (local_120 == (uint *)0x0)) {
    *(undefined8 *)(puVar19 + -8) = 0x140019ffa;
    local_120 = MupiAllocLegacyQueryPathRequest(local_128,(ushort *)&local_98);
    if (local_120 == (uint *)0x0) goto LAB_14001a01c;
    local_60 = local_120;
  }
  *(undefined8 *)(puVar19 + -8) = 0x140019b03;
  local_d8 = puVar23;
  local_e8 = MupiAllocQueryIrp((longlong)&local_108);
  if (local_e8 == 0) {
LAB_14001a01c:
    uVar26 = 0xc000009a;
    *(undefined8 *)(puVar19 + -8) = 0x14001a02a;
    MupReleaseUncProvider((longlong)puVar23);
    goto LAB_140019c16;
  }
  *(undefined8 *)(puVar19 + -8) = 0x140019b22;
  KeInitializeEvent(local_d0,1);
  *(undefined8 *)(puVar19 + -8) = 0x140019b30;
  iVar8 = MupiIssueQueryRequest((longlong)&local_108);
  if ((iVar8 == -0x3ffffee0) || (iVar8 == -0x3fffffb5)) {
    bVar6 = true;
    bVar4 = true;
  }
  uVar16 = *(uint *)(local_e8 + 0x30);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    uVar24 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar19 + -8) = 0x140019c01;
    WPP_SF_D(uVar24,0x1a,&WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,uVar16);
  }
  *(undefined8 *)(puVar19 + -8) = 0x140019b67;
  IoFreeIrp(local_e8);
  local_e8 = 0;
  if (-1 < (int)uVar16) {
    uVar26 = 0;
    uVar7 = *(uint *)(puVar19 + 0x48);
    *param_3 = (longlong)puVar23;
    uVar16 = local_b8;
    goto LAB_140019c22;
  }
  if (!bVar6) {
    _DAT_14000bb94 = _DAT_14000bb94 + 1;
    puVar15 = &MupiOrderedErrorList;
    while( true ) {
      uVar7 = *puVar15;
      uVar10 = (ulonglong)uVar16;
      bVar5 = bVar28;
      if ((uVar7 == 0) || (uVar7 == (uint)uVar26)) break;
      uVar10 = uVar26;
      if (uVar7 == uVar16) break;
      puVar15 = puVar15 + 1;
    }
    goto LAB_14001996e;
  }
  uVar26 = (ulonglong)uVar16;
  *(undefined8 *)(puVar19 + -8) = 0x14001a03a;
  MupReleaseUncProvider((longlong)puVar23);
LAB_140019c12:
  uVar7 = *(uint *)(puVar19 + 0x48);
LAB_140019c16:
  uVar16 = *(uint *)(puVar19 + 0x4c);
LAB_140019c22:
  lVar22 = *param_3;
  if (lVar22 != 0) {
    *(undefined8 *)(puVar19 + 0x30) = param_4;
    puVar19[0x28] = param_7 != (undefined4 *)0x0;
    *(int *)(puVar19 + 0x20) = iVar9;
    *(undefined8 *)(puVar19 + -8) = 0x14001a069;
    MupInsertKnownPrefix
              (param_8,local_118,uVar16,lVar22,*(int *)(puVar19 + 0x20),puVar19[0x28],
               *(undefined8 *)(puVar19 + 0x30));
  }
  if (*(longlong *)(puVar19 + 0x60) != 0) {
    *(undefined8 *)(puVar19 + -8) = 0x14001a076;
    MupReleaseUncProvider(*(longlong *)(puVar19 + 0x60));
  }
  *(undefined8 *)(puVar19 + -8) = 0x140019c45;
  MupiDeInitQueryContext(&local_108);
  if (uVar7 != 0) {
    lVar22 = *(longlong *)(puVar19 + 0x50);
    puVar20 = puVar19;
    if ((puVar19[0x40] != '\0') && (!bVar5)) {
      uVar26 = 0xc0000201;
    }
    goto LAB_1400197b3;
  }
  goto LAB_1400197ae;
}



===== MupFsControl @ 14001a0b0 =====

ulonglong MupFsControl(undefined8 param_1,longlong param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined *puVar7;
  undefined *local_res10;
  longlong local_res18 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  uVar2 = *(uint *)(lVar4 + 0x18);
  if (uVar2 == 0x10002c) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    uVar2 = MupFsctlGetUncCacheInfo(param_2);
  }
  else if (uVar2 < 0x100039) {
    if (uVar2 == 0x100038) {
      *(undefined8 *)(param_2 + 0x38) = 0;
      uVar2 = MupFsctlGetUncHardeningPrefixTable(param_2);
    }
    else {
      if (uVar2 == 0x100004) {
        if (*(char *)(param_2 + 0x40) == '\0') {
          uVar2 = MupRegisterUncProvider(param_2);
          uVar6 = (ulonglong)uVar2;
        }
        else {
          uVar6 = 0xc0000022;
        }
        goto LAB_14001a1f5;
      }
      if (uVar2 == 0x100030) {
        *(undefined8 *)(param_2 + 0x38) = 0;
        uVar2 = MupFsctlGetUncProviderList(param_2);
      }
      else {
        if (uVar2 != 0x100034) goto LAB_14001a0f9;
        *(undefined8 *)(param_2 + 0x38) = 0;
        uVar2 = MupFsctlGetSurrogateProviderList(param_2);
      }
    }
  }
  else {
    if (uVar2 != 0x10003c) {
      if (uVar2 == 0x108028) {
        uVar2 = *(uint *)(lVar4 + 0x10);
        local_res10 = (undefined *)0x0;
        uVar6 = 0xc000000d;
        if (((uVar2 & 1) == 0) && (uVar2 < 0xffff)) {
          lVar4 = MupGetSiloFromFileObject();
          uVar3 = MupGetContainerContextFromSilo(lVar4,&local_res10);
          uVar6 = (ulonglong)uVar3;
          if (uVar3 == 0) {
            puVar7 = MupGetUncCachePrefixTable(local_res10);
            if ((uVar2 == 2) && (**(short **)(param_2 + 0x18) == 0x2a)) {
              MupFlushKnownPrefixTable((longlong)puVar7,0,'\0');
            }
            else {
              uStack_20 = *(undefined8 *)(param_2 + 0x18);
              local_28 = (ulonglong)CONCAT22((short)uVar2,(short)uVar2);
              cVar1 = MupFlushPrefixEntry(puVar7,(wchar_t *)&local_28);
              if (cVar1 == '\0') {
                uVar6 = 0xc0000225;
              }
            }
          }
        }
        *(undefined8 *)(param_2 + 0x38) = 0;
        *(int *)(param_2 + 0x30) = (int)uVar6;
        goto LAB_14001a192;
      }
LAB_14001a0f9:
      lVar4 = MupFindFileContext(*(undefined8 *)(lVar4 + 0x30));
      if (lVar4 == 0) {
        uVar6 = 0xc0000010;
        *(undefined4 *)(param_2 + 0x30) = 0xc0000010;
        goto LAB_14001a192;
      }
      local_res10 = (undefined *)0x0;
      local_res18[0] = 0;
      lVar5 = MupGetSiloFromFileObject();
      uVar2 = MupGetContainerContextFromSilo(lVar5,&local_res10);
      uVar6 = (ulonglong)uVar2;
      if (uVar2 == 0) {
        uVar2 = MupCreateIrpContext(lVar4,(longlong)local_res10,param_2,'\0',local_res18);
        uVar6 = (ulonglong)uVar2;
        if (uVar2 == 0) {
          uVar6 = MupStateMachine(local_res18[0]);
          return uVar6;
        }
      }
LAB_14001a1f5:
      *(int *)(param_2 + 0x30) = (int)uVar6;
      goto LAB_14001a192;
    }
    *(undefined8 *)(param_2 + 0x38) = 0;
    uVar2 = MupFsctlQueryUncHardeningConfigurationForPath(param_2);
  }
  uVar6 = (ulonglong)uVar2;
  *(uint *)(param_2 + 0x30) = uVar2;
LAB_14001a192:
  IofCompleteRequest(param_2,2);
  return uVar6;
}



===== MupStateMachineWorker @ 14001a2f0 =====

ulonglong MupStateMachineWorker(longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  
  if (*(longlong *)(param_1 + 0x38) == 0) {
    uVar1 = MupStateMachine(param_1);
  }
  else {
    uVar2 = PsAttachSiloToCurrentThread();
    uVar1 = MupStateMachine(param_1);
    uVar1 = uVar1 & 0xffffffff;
    PsDetachSiloFromCurrentThread(uVar2);
  }
  return uVar1;
}



===== MupReleaseFileContext @ 14001a350 =====

void MupReleaseFileContext(longlong param_1)

{
  int *piVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
              &WPP_4224fc6462d239efe09d540716e6c5d6_Traceguids,*(undefined8 *)(param_1 + 0x90),
              (char)param_1);
  }
  LOCK();
  piVar1 = (int *)(param_1 + 4);
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 == 1) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_4224fc6462d239efe09d540716e6c5d6_Traceguids,param_1);
    }
    puVar4 = *(undefined8 **)(param_1 + 200);
    while (puVar4 != (undefined8 *)(param_1 + 200)) {
      puVar2 = puVar4 + -1;
      puVar4 = (undefined8 *)*puVar4;
      MupReleaseSurrogateFileContext((longlong)puVar2);
    }
    if (*(longlong *)(param_1 + 0xa8) != 0) {
      MupReleaseUncProvider(*(longlong *)(param_1 + 0xa8));
    }
    if (*(longlong *)(param_1 + 0xb8) != 0) {
      MupReleaseSurrogateProvider(*(longlong *)(param_1 + 0xb8));
    }
    if (*(longlong *)(param_1 + 0xb0) != 0) {
      MupReleaseUncProvider(*(longlong *)(param_1 + 0xb0));
    }
    if (*(longlong *)(param_1 + 0xc0) != 0) {
      MupReleaseSurrogateProvider(*(longlong *)(param_1 + 0xc0));
    }
    if (*(longlong *)(param_1 + 0x58) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_1 + 0x58),0);
    }
    MupCleanupUncHardeningFileContext((longlong *)(param_1 + 0xf8));
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== MupClose @ 14001a4d0 =====

ulonglong MupClose(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong local_res10;
  longlong local_res18 [2];
  
  uVar4 = 0;
  local_res18[0] = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  local_res10 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
             &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,lVar1);
  }
  lVar2 = MupFindFileContext(lVar1);
  if (lVar2 == 0) {
    if (*(undefined **)(lVar1 + 0x18) != &g_MupAdvancedFcbHeader) {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x103,1,param_2,lVar1,param_1);
    }
    MupiUpdateMupDeviceOpenCount('\0');
    if (*(longlong *)(lVar1 + 0x20) != 0) {
      MupDeregisterUncProvider(*(longlong *)(lVar1 + 0x20));
    }
    *(undefined4 *)(param_2 + 0x30) = 0;
    IofCompleteRequest(param_2,2);
  }
  else {
    lVar3 = MupGetSiloFromFileObject();
    MupGetContainerContextFromSilo(lVar3,&local_res10);
    MupCreateIrpContext(lVar2,local_res10,param_2,'\x01',local_res18);
    uVar4 = MupStateMachine(local_res18[0]);
    uVar4 = uVar4 & 0xffffffff;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
              &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,lVar1,(char)uVar4);
  }
  return uVar4;
}



===== MupCreate @ 14001a640 =====

ulonglong MupCreate(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  char *pcVar1;
  longlong lVar2;
  bool bVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  int iVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  longlong local_res18;
  longlong local_res20;
  longlong local_40;
  
  lVar10 = 0;
  local_res20 = 0;
  pcVar1 = *(char **)(param_2 + 0xb8);
  lVar2 = *(longlong *)(pcVar1 + 0x30);
  lVar9 = 0;
  local_res18 = 0;
  local_40 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_Zqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,param_3,(wchar_t *)(lVar2 + 0x58),
               (char)lVar2,(char)param_2);
  }
  lVar5 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if ((*(short *)(lVar5 + 0x58) == 0) &&
     ((*(longlong *)(lVar5 + 0x40) == 0 ||
      (*(undefined **)(*(longlong *)(lVar5 + 0x40) + 0x18) == &g_MupAdvancedFcbHeader)))) {
    *(undefined **)(lVar5 + 0x18) = &g_MupAdvancedFcbHeader;
    MupiUpdateMupDeviceOpenCount('\x01');
    uVar8 = 0;
  }
  else {
    uVar8 = 0xc0000016;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x1a & 1) != 0)) {
    WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1c,
               &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,lVar5,(char)param_2,(char)uVar8);
  }
  if ((int)uVar8 != -0x3fffffea) {
    bVar3 = true;
    goto LAB_14001a98e;
  }
  lVar5 = MupGetSiloFromFileObject();
  uVar4 = MupGetContainerContextFromSilo(lVar5,&local_res20);
  uVar8 = (ulonglong)uVar4;
  if (uVar4 == 0) {
    if (*(longlong *)(lVar2 + 0x40) == 0) {
      uVar8 = 0xc0000016;
      if (*pcVar1 == '\0') {
        uVar4 = MupiCheckForMailslotRequest(lVar2,&local_res18,local_res20 != 0);
        uVar8 = (ulonglong)uVar4;
        lVar9 = local_res18;
      }
      if ((int)uVar8 == -0x3fffffea) {
        puVar6 = MupiCreateWithAbsolutePath(lVar2,local_res20 != 0,&local_res18);
        uVar4 = (uint)puVar6;
        goto LAB_14001a77f;
      }
      if ((int)uVar8 != 0) {
        bVar3 = false;
        goto LAB_14001a98e;
      }
    }
    else {
      uVar4 = MupiCreateWithRelativePath(lVar2,local_res20 != 0,&local_res18);
LAB_14001a77f:
      uVar8 = (ulonglong)uVar4;
      lVar9 = local_res18;
    }
    if ((int)uVar8 == 0) {
      if (*(longlong *)(lVar9 + 0xf8) == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(uint *)(*(longlong *)(lVar9 + 0xf8) + 0x58);
      }
      if (uVar4 == 0) {
LAB_14001a7b0:
        uVar8 = 0;
      }
      else if ((*(longlong *)(lVar9 + 0xa8) == 0) ||
              ((~*(uint *)(*(longlong *)(lVar9 + 0xa8) + 0x98) & uVar4) == 0)) {
        if ((*(longlong *)(lVar9 + 0xb8) == 0) ||
           (uVar8 = 0xc0000201, (~*(uint *)(*(longlong *)(lVar9 + 0xb8) + 0x6c) & uVar4) == 0))
        goto LAB_14001a7b0;
      }
      else {
        uVar8 = 0xc0000201;
      }
      if ((int)uVar8 == 0) {
        uVar4 = MupCreateIrpContext(lVar9,local_res20,param_2,'\0',&local_40);
        uVar8 = (ulonglong)uVar4;
        if (uVar4 == 0) {
          *(undefined8 *)(lVar9 + 0x18) = MupDeviceObject;
          *(undefined8 *)(lVar9 + 0x20) = 0;
          uVar4 = FsRtlInsertPerFileObjectContext(*(undefined8 *)(lVar9 + 0x90),lVar9 + 8);
          uVar8 = (ulonglong)uVar4;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x1a & 1) != 0)) {
            WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                      &WPP_4224fc6462d239efe09d540716e6c5d6_Traceguids,*(undefined8 *)(lVar9 + 0x90)
                      ,(char)lVar9);
          }
          bVar3 = false;
          lVar10 = local_40;
          goto LAB_14001a98e;
        }
        lVar10 = local_40;
      }
    }
  }
  bVar3 = false;
LAB_14001a98e:
  iVar7 = (int)uVar8;
  if (iVar7 != 0) {
    if (lVar9 != 0) {
      MupReleaseFileContext(lVar9);
    }
    if (lVar10 != 0) {
      MupReleaseIrpContext(lVar10);
    }
  }
  if ((bVar3) || (iVar7 != 0)) {
    *(int *)(param_2 + 0x30) = iVar7;
    IofCompleteRequest(param_2,2);
  }
  else {
    uVar8 = MupStateMachine(lVar10);
    uVar8 = uVar8 & 0xffffffff;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_ZqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
               &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,(wchar_t *)(lVar2 + 0x58),
               (char)lVar2,(char)uVar8);
  }
  return uVar8;
}



===== MupCleanup @ 14001aa30 =====

ulonglong MupCleanup(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong local_res10;
  longlong local_res18 [2];
  
  uVar5 = 0;
  local_res18[0] = 0;
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30);
  local_res10 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,lVar1,(char)param_2);
  }
  lVar3 = MupFindFileContext(lVar1);
  if (lVar3 == 0) {
    if (*(undefined **)(lVar1 + 0x18) != &g_MupAdvancedFcbHeader) {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x103,1,param_2,lVar1,param_1);
    }
    *(undefined4 *)(param_2 + 0x30) = 0;
    IofCompleteRequest(param_2,2);
  }
  else {
    lVar4 = MupGetSiloFromFileObject();
    uVar2 = MupGetContainerContextFromSilo(lVar4,&local_res10);
    uVar5 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = MupCreateIrpContext(lVar3,local_res10,param_2,'\x01',local_res18);
      uVar5 = (ulonglong)uVar2;
      if (uVar2 == 0) {
        uVar5 = MupStateMachine(local_res18[0]);
        uVar5 = uVar5 & 0xffffffff;
      }
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,lVar1,(char)param_2,(char)uVar5);
  }
  return uVar5;
}



===== MupFsdIrpPassThrough @ 14001aba0 =====

int MupFsdIrpPassThrough(undefined8 param_1,longlong param_2,undefined8 param_3)

{
  byte *pbVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  longlong local_res10;
  longlong local_res18 [2];
  
  pbVar1 = *(byte **)(param_2 + 0xb8);
  local_res18[0] = 0;
  lVar2 = *(longlong *)(pbVar1 + 0x30);
  local_res10 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qqDD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),(ulonglong)*pbVar1,param_3,lVar2,
                (char)param_2,*pbVar1,pbVar1[1]);
  }
  if (lVar2 == 0) {
LAB_14001aca8:
    iVar3 = -0x3ffffff0;
  }
  else {
    lVar4 = MupFindFileContext(lVar2);
    if (lVar4 == 0) {
      if (*(undefined **)(lVar2 + 0x18) != &g_MupAdvancedFcbHeader) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x103,1,param_2,lVar2,param_1);
      }
      goto LAB_14001aca8;
    }
    if (((*pbVar1 == 3) || (*pbVar1 == 4)) && (MupiCachingAndGenericSurrogateCount == 0)) {
      iVar3 = MupiBypassMupAndCallUncProviderDirectly(*(longlong *)(lVar4 + 0xa8),param_2);
      goto LAB_14001ac7b;
    }
    lVar5 = MupGetSiloFromFileObject();
    iVar3 = MupGetContainerContextFromSilo(lVar5,&local_res10);
    if ((iVar3 == 0) &&
       (iVar3 = MupCreateIrpContext(lVar4,local_res10,param_2,'\0',local_res18), iVar3 == 0)) {
      uVar6 = MupStateMachine(local_res18[0]);
      iVar3 = (int)uVar6;
      goto LAB_14001ac7b;
    }
  }
  *(int *)(param_2 + 0x30) = iVar3;
  IofCompleteRequest(param_2,2);
LAB_14001ac7b:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
               &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,lVar2,(char)param_2,(char)iVar3);
  }
  return iVar3;
}



===== MupGetContainerContextFromSilo @ 14001ad70 =====

void MupGetContainerContextFromSilo(longlong param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    *param_2 = 0;
  }
  else {
    uVar1 = PsGetSiloMonitorContextSlot(ContainerMonitor);
    iVar2 = PsGetPermanentSiloContext(param_1,uVar1,param_2);
    if (iVar2 < 0) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
        WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                  &WPP_c898274d75623dfd801520d1a3be50ef_Traceguids,param_1,(char)iVar2);
      }
      *param_2 = 0;
    }
  }
  return;
}



===== MupGetSiloFromFileObject @ 14001ae10 =====

undefined8 MupGetSiloFromFileObject(void)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = IoGetSiloParameters();
  uVar2 = 0;
  if (lVar1 != 0) {
    uVar2 = *(undefined8 *)(lVar1 + 8);
  }
  return uVar2;
}



===== MupStateMachine @ 14001ae40 =====

ulonglong MupStateMachine(longlong param_1)

{
  uint uVar1;
  char *pcVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  uint *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  char cVar10;
  byte bVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  undefined4 extraout_var_00;
  undefined8 uVar15;
  undefined4 extraout_var_01;
  undefined4 extraout_var_02;
  ulonglong uVar16;
  undefined7 extraout_var;
  uint uVar17;
  wchar_t *pwVar18;
  wchar_t *pwVar19;
  ulonglong uVar20;
  undefined1 uVar21;
  ulonglong uVar22;
  IMAGE_DOS_HEADER *pIVar23;
  char *pcVar24;
  ulonglong local_res8;
  longlong local_res10;
  longlong local_res18;
  
  uVar1 = *(uint *)(param_1 + 0x18);
  pwVar19 = (wchar_t *)(ulonglong)uVar1;
  do {
    pwVar18 = (wchar_t *)0x0;
    pIVar23 = &IMAGE_DOS_HEADER_140000000;
    uVar12 = 0;
    switch((int)pwVar19) {
    case 0:
      *(undefined4 *)(param_1 + 0x18) = 1;
      pwVar19 = (wchar_t *)0x1;
      break;
    case 1:
      lVar4 = *(longlong *)(param_1 + 0x10);
      pcVar2 = *(char **)(lVar4 + 0xb8);
      cVar10 = *pcVar2;
      if (((cVar10 == '\0') || (cVar10 == '\x01')) || (cVar10 == '\x13')) {
        lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x28) + 0xf8);
        if (lVar3 != 0) {
          uVar12 = *(uint *)(lVar3 + 0x58);
        }
        local_res10 = 0;
        local_res18 = 0;
        local_res8 = local_res8 & 0xffffffffffffff00;
        if ((cVar10 == '\0') && (*(int *)(pcVar2 + 0x20) != 0)) {
          puVar6 = *(uint **)(lVar4 + 0x18);
          cVar10 = RfsUtilFilterEa(puVar6,(int *)(pcVar2 + 0x20),
                                   "ECP{c584edbf-00df-4d28-00b8-8435baca8911e8}-PRIVACY",0x33);
          pcVar24 = "ECP{c584edbf-00df-4d28-00b8-8435baca8911e8}-INTEGRITY";
          uVar14 = -(uint)(cVar10 != '\0') & 4;
          cVar10 = RfsUtilFilterEa(puVar6,(int *)(pcVar2 + 0x20),
                                   "ECP{c584edbf-00df-4d28-00b8-8435baca8911e8}-INTEGRITY",0x35);
          if (cVar10 != '\0') {
            uVar14 = uVar14 | 2;
          }
          uVar12 = uVar12 | uVar14;
          pIVar23 = (IMAGE_DOS_HEADER *)pcVar24;
        }
        iVar13 = 0;
        if ((*pcVar2 == '\0') && ((char)*(undefined4 *)(pcVar2 + 0x10) < '\0')) {
          uVar17 = *(ushort *)(pcVar2 + 0x18) >> 0xc & 4;
          uVar14 = uVar17 | 2;
          if (-1 < (short)*(ushort *)(pcVar2 + 0x18)) {
            uVar14 = uVar17;
          }
          uVar12 = uVar12 | uVar14;
        }
        if (uVar12 == 0) {
LAB_14001af36:
          if (-1 < iVar13) goto LAB_14001af45;
        }
        else {
          uVar15 = MupiGetOrCreateEcpListForCreateIrp(lVar4,&local_res10);
          if (-1 < (int)uVar15) {
            uVar14 = MupiFindOrCreateNetworkOpenEcp
                               (local_res10,&local_res18,(ulonglong)pIVar23,
                                (undefined1 *)&local_res8);
            lVar4 = local_res18;
            if (-1 < (int)uVar14) {
              if ((char)local_res8 == '\0') {
                FsRtlPrepareToReuseEcp(local_res18);
                *(undefined8 *)(lVar4 + 0x10) = 0;
                *(undefined4 *)(lVar4 + 0x18) = 0;
              }
              bVar11 = MupiGetNetworkOpenEcpIntegrityLevelFromHardeningCapabilities((byte)uVar12);
              uVar14 = (uint)CONCAT71(extraout_var,bVar11);
              if (*(uint *)(lVar4 + 8) != uVar14) {
                if ((*(uint *)(lVar4 + 8) & 0xfffffffb) != 0) {
                  iVar13 = -0x3ffffdff;
                  goto LAB_14001af36;
                }
                *(uint *)(lVar4 + 8) = uVar14;
              }
              *(uint *)(lVar4 + 0xc) = *(uint *)(lVar4 + 0xc) | (uVar12 & 1) << 3;
              goto LAB_14001af36;
            }
          }
        }
        pwVar19 = (wchar_t *)0x6;
      }
      else {
LAB_14001af45:
        pwVar19 = (wchar_t *)0x2;
      }
      *(int *)(param_1 + 0x18) = (int)pwVar19;
      break;
    case 2:
      iVar13 = MupCallSurrogatePrePost(param_1);
      if (iVar13 == 0x103) {
        return CONCAT44(extraout_var_01,iVar13);
      }
      uVar12 = (*(int *)(param_1 + 0x1c) != -0x3fffffea) + 3;
      pwVar19 = (wchar_t *)(ulonglong)uVar12;
      *(uint *)(param_1 + 0x18) = uVar12;
      break;
    case 3:
      if (uVar1 != 3) {
        lVar4 = *(longlong *)(param_1 + 0x28);
        pwVar18 = *(wchar_t **)(param_1 + 0x10);
        uVar22 = *(ulonglong *)(lVar4 + 0xa8);
        puVar5 = *(undefined8 **)(pwVar18 + 0x5c);
        local_res8 = uVar22;
        if (uVar22 == 0) {
          if ((char)*(undefined4 *)(pwVar18 + 8) < '\0') {
            pIVar23 = *(IMAGE_DOS_HEADER **)(lVar4 + 0x98);
            if (pIVar23 == (IMAGE_DOS_HEADER *)0x0) {
              if (*(longlong *)(lVar4 + 0xb8) == 0) {
                pIVar23 = (IMAGE_DOS_HEADER *)&local_res8;
                pwVar19 = pwVar18;
                uVar16 = MupLocateUncProviderForPath
                                   (lVar4,(longlong)pwVar18,(longlong *)pIVar23,0,
                                    *(undefined8 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x60),
                                    (undefined4 *)0x0,*(undefined **)(param_1 + 0x30));
                uVar22 = local_res8;
                uVar20 = uVar16 & 0xffffffff;
                if (-1 < (int)uVar16) {
                  *(ulonglong *)(lVar4 + 0xa8) = local_res8;
                  if ((*(uint *)(local_res8 + 0x94) & 8) == 0) goto LAB_14001af84;
                  pwVar19 = (wchar_t *)(local_res8 + 0x18);
                  uVar12 = MupiRerouteCreateToProvider(puVar5[6],pwVar19);
                  goto LAB_14001aff3;
                }
                goto LAB_14001aff5;
              }
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
                pwVar19 = (wchar_t *)0x2c;
                WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2c,0,
                           *(longlong *)(lVar4 + 0xb8),(char)pwVar18,(char)lVar4);
                uVar20 = 0xc0000001;
                goto LAB_14001affd;
              }
            }
            else if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                    ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
              pwVar19 = (wchar_t *)0x2b;
              WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,pIVar23,pwVar18,(char)lVar4
                         ,(char)pIVar23);
            }
            uVar20 = 0xc0000001;
          }
          else {
            uVar20 = 0xc0000016;
          }
LAB_14001affd:
          uVar21 = (undefined1)uVar22;
          *(int *)(param_1 + 0x20) = (int)uVar20;
        }
        else {
LAB_14001af84:
          uVar22 = local_res8;
          lVar4 = *(longlong *)(pwVar18 + 0x5c);
          uVar15 = puVar5[1];
          *(undefined8 *)(lVar4 + -0x48) = *puVar5;
          *(undefined8 *)(lVar4 + -0x40) = uVar15;
          uVar15 = puVar5[3];
          *(undefined8 *)(lVar4 + -0x38) = puVar5[2];
          *(undefined8 *)(lVar4 + -0x30) = uVar15;
          uVar15 = puVar5[5];
          *(undefined8 *)(lVar4 + -0x28) = puVar5[4];
          *(undefined8 *)(lVar4 + -0x20) = uVar15;
          uVar7 = *(undefined4 *)((longlong)puVar5 + 0x34);
          uVar8 = *(undefined4 *)(puVar5 + 7);
          uVar9 = *(undefined4 *)((longlong)puVar5 + 0x3c);
          *(undefined4 *)(lVar4 + -0x18) = *(undefined4 *)(puVar5 + 6);
          *(undefined4 *)(lVar4 + -0x14) = uVar7;
          *(undefined4 *)(lVar4 + -0x10) = uVar8;
          *(undefined4 *)(lVar4 + -0xc) = uVar9;
          *(undefined8 *)(lVar4 + -8) = puVar5[8];
          lVar4 = *(longlong *)(pwVar18 + 0x5c);
          *(code **)(lVar4 + -0x10) = MupiUncProviderCompletion;
          *(longlong *)(lVar4 + -8) = param_1;
          *(undefined1 *)(lVar4 + -0x45) = 0xe0;
          uVar15 = IoGetAttachedDevice(*(undefined8 *)(local_res8 + 0xa8));
          pwVar19 = pwVar18;
          uVar12 = IofCallDriver(uVar15);
LAB_14001aff3:
          uVar20 = (ulonglong)uVar12;
LAB_14001aff5:
          uVar21 = (undefined1)uVar22;
          if ((int)uVar20 != 0x103) goto LAB_14001affd;
        }
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
          WPP_SF_qqqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),pwVar19,pIVar23,pwVar18,uVar21,
                      (char)param_1,(char)uVar20);
        }
        if ((int)uVar20 == 0x103) {
          return uVar20;
        }
      }
      *(undefined4 *)(param_1 + 0x18) = 4;
      pwVar19 = (wchar_t *)0x4;
      break;
    case 4:
      iVar13 = MupCallSurrogatePrePost(param_1);
      if (iVar13 == 0x103) {
        return CONCAT44(extraout_var_00,iVar13);
      }
      if ((*(uint *)(param_1 + 8) & 4) == 0) {
        pwVar18 = (wchar_t *)0x5;
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                   &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,*(undefined8 *)(param_1 + 0x10))
          ;
        }
        *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffffb;
      }
      *(int *)(param_1 + 0x18) = (int)pwVar18;
      pwVar19 = pwVar18;
      break;
    case 5:
      cVar10 = **(char **)(*(longlong *)(param_1 + 0x10) + 0xb8);
      if (((cVar10 == '\0') || (cVar10 == '\x01')) || (cVar10 == '\x13')) {
        MupUncHardeningPostProcessCreate(param_1);
      }
      *(undefined4 *)(param_1 + 0x18) = 6;
      pwVar19 = (wchar_t *)0x6;
      break;
    case 6:
      iVar13 = MupiIoPostProcess(param_1,pwVar19,&IMAGE_DOS_HEADER_140000000);
      return CONCAT44(extraout_var_02,iVar13);
    }
  } while( true );
}



===== MupCallSurrogatePrePost @ 14001b3a0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int MupCallSurrogatePrePost(longlong param_1)

{
  uint *puVar1;
  longlong lVar2;
  bool bVar3;
  int iVar4;
  code *pcVar5;
  undefined8 *puVar6;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x18,
              &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,param_1,
              (char)*(undefined8 *)(param_1 + 0x10));
  }
  if (*(int *)(param_1 + 0x18) == 2) {
    bVar3 = true;
    if ((char)*(undefined4 *)(*(longlong *)(param_1 + 0x10) + 0x10) < '\0') {
      puVar1 = (uint *)(*(longlong *)(param_1 + 0x28) + 0xf0);
      *puVar1 = *puVar1 | 1;
    }
  }
  else {
    bVar3 = false;
  }
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (lVar2 == 0) {
    if (bVar3) {
      puVar6 = *(undefined8 **)(param_1 + 0x48);
    }
    else {
      puVar6 = *(undefined8 **)(param_1 + 0x50);
    }
    iVar4 = -0x3fffffea;
  }
  else {
    if (bVar3) {
      puVar6 = *(undefined8 **)(lVar2 + 8);
      iVar4 = *(int *)(param_1 + 0x1c);
    }
    else {
      puVar6 = *(undefined8 **)(lVar2 + 0x10);
      iVar4 = *(int *)(param_1 + 0x24);
    }
    if (iVar4 != -0x3fffffea) goto LAB_14001b4fe;
  }
  do {
    if (puVar6 == (undefined8 *)(param_1 + 0x48)) goto LAB_14001b506;
    *(undefined8 **)(param_1 + 0x40) = puVar6 + -1;
    lVar2 = puVar6[3];
    iVar4 = MupGetIoStatus(param_1);
    *(int *)((longlong)puVar6 + 0x5c) = iVar4;
    if ((*(int *)(*(longlong *)(lVar2 + 0x18) + 0x18) == 1) &&
       (*(short *)((longlong)puVar6 + 0x6c) != *(short *)(param_1 + 100))) {
      *(short *)((longlong)puVar6 + 0x6c) = *(short *)(param_1 + 100);
    }
    if (bVar3) {
      pcVar5 = *(code **)(*(longlong *)(lVar2 + 0x18) + 0x48);
    }
    else {
      pcVar5 = *(code **)(*(longlong *)(lVar2 + 0x18) + 0x50);
    }
    if (pcVar5 == (code *)0x0) {
      iVar4 = -0x3fffffea;
    }
    else {
      iVar4 = (*pcVar5)(puVar6 + 4);
      if (((iVar4 != 0x103) && (*(int *)(*(longlong *)(lVar2 + 0x18) + 0x18) == 2)) &&
         (*(short *)(param_1 + 100) != *(short *)((longlong)puVar6 + 0x6c))) {
        *(short *)(param_1 + 100) = *(short *)((longlong)puVar6 + 0x6c);
      }
    }
    if (bVar3) {
      puVar6 = (undefined8 *)*puVar6;
    }
    else {
      puVar6 = (undefined8 *)puVar6[1];
    }
  } while (iVar4 == -0x3fffffea);
LAB_14001b4fe:
  if (iVar4 != 0x103) {
LAB_14001b506:
    *(undefined8 *)(param_1 + 0x40) = 0;
    if (iVar4 != -0x3fffffea) {
      if (bVar3) {
        *(int *)(param_1 + 0x1c) = iVar4;
      }
      else {
        *(int *)(param_1 + 0x24) = iVar4;
      }
    }
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,param_1,(char)iVar4);
  }
  return iVar4;
}



===== MupGetIoStatus @ 14001b610 =====

int MupGetIoStatus(longlong param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x24);
  if (iVar3 < 0) {
    iVar1 = *(int *)(param_1 + 0x1c);
    if (-1 < iVar1) {
      return iVar1;
    }
    iVar2 = *(int *)(param_1 + 0x20);
    if (iVar2 < 0) {
      if (iVar3 != -0x3fffffea) {
        return iVar3;
      }
      if (iVar1 != -0x3fffffea) {
        iVar2 = iVar1;
      }
    }
    iVar3 = iVar2;
  }
  return iVar3;
}



===== MupiIoPostProcess @ 14001b650 =====

int MupiIoPostProcess(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int *piVar1;
  undefined8 *puVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 *puVar8;
  longlong lVar9;
  undefined8 uVar10;
  int iVar11;
  longlong lVar12;
  
  iVar11 = *(int *)(param_1 + 0x24);
  if (iVar11 < 0) {
    iVar4 = *(int *)(param_1 + 0x1c);
    if (iVar4 < 0) {
      iVar5 = *(int *)(param_1 + 0x20);
      if (iVar5 < 0) {
        if ((iVar11 == -0x3fffffea) && (iVar11 = iVar5, iVar4 != -0x3fffffea)) {
          iVar11 = iVar4;
        }
      }
      else {
        iVar11 = iVar5;
      }
    }
    else {
      iVar11 = iVar4;
    }
  }
  lVar6 = *(longlong *)(param_1 + 0x10);
  lVar7 = *(longlong *)(param_1 + 0x28);
  cVar3 = **(char **)(lVar6 + 0xb8);
  if (cVar3 == '\x02') {
    lVar9 = FsRtlRemovePerFileObjectContext(*(undefined8 *)(lVar7 + 0x90),MupDeviceObject,0);
    lVar12 = lVar9 + -8;
    if (lVar9 == 0) {
      lVar12 = 0;
    }
    if (lVar12 != lVar7) {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x103,2,lVar7,lVar12,0);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
                &WPP_4224fc6462d239efe09d540716e6c5d6_Traceguids,*(undefined8 *)(lVar7 + 0x90),
                (char)lVar7);
    }
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
                &WPP_4224fc6462d239efe09d540716e6c5d6_Traceguids,*(undefined8 *)(lVar7 + 0x90),
                (char)lVar7);
    }
    LOCK();
    piVar1 = (int *)(lVar7 + 4);
    iVar4 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar4 == 1) {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                 &WPP_4224fc6462d239efe09d540716e6c5d6_Traceguids,lVar7);
      }
      puVar8 = *(undefined8 **)(lVar7 + 200);
      while (puVar8 != (undefined8 *)(lVar7 + 200)) {
        puVar2 = puVar8 + -1;
        puVar8 = (undefined8 *)*puVar8;
        MupReleaseSurrogateFileContext((longlong)puVar2);
      }
      if (*(longlong *)(lVar7 + 0xa8) != 0) {
        MupReleaseUncProvider(*(longlong *)(lVar7 + 0xa8));
      }
      if (*(longlong *)(lVar7 + 0xb8) != 0) {
        MupReleaseSurrogateProvider(*(longlong *)(lVar7 + 0xb8));
      }
      if (*(longlong *)(lVar7 + 0xb0) != 0) {
        MupReleaseUncProvider(*(longlong *)(lVar7 + 0xb0));
      }
      if (*(longlong *)(lVar7 + 0xc0) != 0) {
        MupReleaseSurrogateProvider(*(longlong *)(lVar7 + 0xc0));
      }
      if (*(longlong *)(lVar7 + 0x58) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar7 + 0x58),0);
      }
      MupCleanupUncHardeningFileContext((longlong *)(lVar7 + 0xf8));
      ExFreePoolWithTag(lVar7,0);
    }
  }
  else if (((cVar3 == '\0') || (cVar3 == '\x01')) || (cVar3 == '\x13')) {
    if (-1 < iVar11) {
      if (iVar11 != 0x104) {
        *(uint *)(lVar7 + 0xf0) = *(uint *)(lVar7 + 0xf0) & 0xfffffffe;
        for (puVar8 = *(undefined8 **)(param_1 + 0x48); puVar8 != (undefined8 *)(param_1 + 0x48);
            puVar8 = (undefined8 *)*puVar8) {
          if (*(char *)((longlong)puVar8 + 0x6e) == '\0') {
            MupReleaseSurrogateFileContext(puVar8[3]);
            puVar8[3] = 0;
          }
          else {
            *(undefined8 *)(puVar8[3] + 0x28) = puVar8[0xf];
          }
        }
        goto LAB_14001b7c0;
      }
      if (((2 < *(ulonglong *)(lVar6 + 0x38)) && (*(longlong *)(lVar7 + 0x98) == 0)) &&
         (*(int *)(lVar7 + 0xa0) - 2U < 2)) {
        uVar10 = MupRestoreFileNameInFileObject(lVar7,0,param_3);
        if ((int)uVar10 != 0) {
          *(undefined8 *)(lVar6 + 0x38) = 0;
          iVar11 = (int)uVar10;
        }
      }
    }
    MupRemoveFileContext(lVar7);
    MupReleaseFileContext(lVar7);
  }
LAB_14001b7c0:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2f,
               &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,param_1,(char)lVar6,(char)iVar11);
  }
  *(int *)(lVar6 + 0x30) = iVar11;
  IofCompleteRequest(lVar6,2);
  MupReleaseIrpContext(param_1);
  return iVar11;
}



===== MupCleanupUncHardeningFileContext @ 14001b9f0 =====

void MupCleanupUncHardeningFileContext(longlong *param_1)

{
  longlong *plVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  
  lVar4 = *param_1;
  if (lVar4 != 0) {
    KeEnterCriticalRegion();
    ExAcquirePushLockExclusiveEx(&DAT_14000b228,0);
    plVar1 = (longlong *)(lVar4 + 0x50);
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      RtlRemoveUnicodePrefix(&DAT_14000b230,lVar4 + 8);
      *(undefined8 *)(lVar4 + 0x20) = 0;
      ExReleasePushLockExclusiveEx(&DAT_14000b228,0);
      KeLeaveCriticalRegion();
      LOCK();
      piVar2 = (int *)(lVar4 + 4);
      iVar3 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
      if (iVar3 == 1) {
        ExFreePoolWithTag(lVar4,0x4855754d);
      }
    }
    else {
      ExReleasePushLockExclusiveEx(&DAT_14000b228,0);
      KeLeaveCriticalRegion();
    }
  }
  return;
}



===== MupReleaseUncProvider @ 14001bac0 =====

void MupReleaseUncProvider(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
             &WPP_b8ec61bc8b283db232150b702b34e2f1_Traceguids,param_1);
  }
  LOCK();
  piVar1 = (int *)(param_1 + 4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (*(ushort *)(param_1 + 0x90) < 0x101) {
    if (iVar2 != 2) {
      return;
    }
  }
  else if (iVar2 != 3) goto LAB_14001bb0b;
  LOCK();
  lVar3 = *(longlong *)(param_1 + 0xa0);
  *(longlong *)(param_1 + 0xa0) = 0;
  UNLOCK();
  if (lVar3 != 0) {
    ObfDereferenceObject();
  }
LAB_14001bb0b:
  if (iVar2 == 2) {
    if ((*(uint *)(param_1 + 0x94) & 4) != 0) {
      IoDeleteSymbolicLink(param_1 + 0x18);
    }
    lVar3 = *(longlong *)(param_1 + 0xa8);
    *(undefined8 *)(param_1 + 0xa8) = 0;
    if (*(longlong *)(param_1 + 0x88) != 0) {
      KeResetEvent();
    }
    *(undefined4 *)(param_1 + 0x44) = 1;
    if (lVar3 != 0) {
      ObfDereferenceObject(lVar3);
    }
  }
  return;
}



===== MupiCheckForMailslotRequest @ 14001bbd0 =====

undefined4 MupiCheckForMailslotRequest(longlong param_1,undefined8 *param_2,char param_3)

{
  short sVar1;
  undefined8 uVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  short *psVar6;
  ulonglong uVar7;
  undefined2 *puVar8;
  undefined8 *puVar9;
  ushort *puVar10;
  short sVar11;
  ushort uVar12;
  undefined8 *puVar13;
  undefined4 uVar14;
  undefined *puVar15;
  uint uVar16;
  ulonglong uVar17;
  short *psVar18;
  undefined2 uVar19;
  ushort local_48 [4];
  short *psStack_40;
  undefined8 local_38;
  short *psStack_30;
  
  psVar18 = (short *)(*(longlong *)(param_1 + 0x60) + 2);
  uVar14 = 0xc0000016;
  local_38 = 0;
  psStack_30 = (short *)0x0;
  uVar16 = (*(ushort *)(param_1 + 0x58) >> 1) - 1;
  if ((((uVar16 != 0) && (*psVar18 != 0x5c)) && (*psVar18 != 0x3b)) &&
     (puVar13 = param_2, psVar6 = MupFindMatchingChar(psVar18,param_2,(ulonglong)uVar16),
     psVar6 != (short *)0x0)) {
    psVar6 = psVar6 + 1;
    uVar16 = uVar16 - (int)((longlong)psVar6 - (longlong)psVar18 >> 1);
    uVar17 = (ulonglong)uVar16;
    if ((uVar16 != 0) && (*psVar6 != 0x3b)) {
      uVar7 = (ulonglong)uVar16;
      psVar18 = MupFindMatchingChar(psVar6,puVar13,uVar7);
      if (psVar18 != (short *)0x0) {
        uVar17 = (longlong)psVar18 - (longlong)psVar6 >> 1;
      }
      uVar16 = (int)uVar17 * 2;
      if (uVar16 < 0x10000) {
        RtlInitUnicodeString(&local_38,0);
        puVar15 = (undefined *)CONCAT71((int7)(uVar7 >> 8),1);
        uVar19 = (undefined2)uVar16;
        local_38 = CONCAT62(CONCAT42(local_38._4_4_,uVar19),uVar19);
        psStack_30 = psVar6;
        iVar5 = RtlCompareUnicodeString(&MupiMailSlotName,&local_38,puVar15);
        if (iVar5 == 0) {
          MupiTryStartPoliciesKeyRegistryWatcher();
          sVar1 = *(short *)(param_1 + 0x58);
          uVar2 = *(undefined8 *)(param_1 + 0x60);
          local_48[0] = 0;
          local_48[1] = 0;
          local_48[2] = 0;
          local_48[3] = 0;
          psStack_40 = (short *)0x0;
          cVar4 = MupEnableMailslotsByPolicy;
          if (MupEnableMailslotsByPolicy == '\x02') {
            cVar4 = MupEnableMailslots;
          }
          if (cVar4 == '\0') {
            uVar14 = 0xc05d0005;
            if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
               ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
              puVar15 = &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids;
              uVar17 = 0xc05d0005;
              WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1d,
                       &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,0xc05d0005);
            }
            if (psVar18 != (short *)0x0) {
              RtlInitUnicodeString(local_48,0);
              uVar7 = Feature_28513592__private_IsEnabledDeviceUsageNoInline();
              if ((int)uVar7 == 0) {
                sVar11 = (short)psVar18;
              }
              else {
                sVar11 = (short)(psVar18 + 1);
              }
              sVar11 = (sVar1 + (short)uVar2) - sVar11;
              local_48[1] = sVar11;
              local_48[0] = sVar11;
              uVar12 = 0;
              psStack_40 = psVar18 + 1;
              do {
                puVar10 = local_48;
                puVar15 = (undefined *)CONCAT71((int7)((ulonglong)puVar15 >> 8),1);
                iVar5 = RtlCompareUnicodeString(&DAT_140008080 + (ulonglong)uVar12 * 0x10);
                if (iVar5 == 0) {
                  MupWriteTelemetryKnownRemoteMailslotFailed(local_48,puVar10,puVar15,uVar17);
                  break;
                }
                uVar12 = uVar12 + 1;
              } while (uVar12 < 6);
              if (uVar12 == 6) {
                MupWriteTelemetryOtherRemoteMailslotFailed(local_48);
              }
            }
          }
          else {
            puVar8 = MupAllocFileContext(0);
            if (puVar8 != (undefined2 *)0x0) {
              puVar13 = (undefined8 *)0x0;
              bVar3 = false;
              KeEnterCriticalRegion();
              ExAcquireResourceSharedLite(&DAT_14000b7c0,1);
              puVar9 = DAT_14000b7a8;
              if ((undefined8 **)DAT_14000b7a8 != &DAT_14000b7a8) {
                do {
                  puVar13 = puVar9 + -1;
                  if (((*(int *)((longlong)puVar9 + 0x3c) == 3) &&
                      ((*(uint *)((longlong)puVar9 + 0x8c) & 1) != 0)) &&
                     ((param_3 == '\0' || ((*(uint *)((longlong)puVar9 + 0x8c) & 0x20) != 0)))) {
                    LOCK();
                    *(int *)((longlong)puVar9 + -4) = *(int *)((longlong)puVar9 + -4) + 1;
                    UNLOCK();
                    bVar3 = true;
                    break;
                  }
                  puVar9 = (undefined8 *)*puVar9;
                } while ((undefined8 **)puVar9 != &DAT_14000b7a8);
              }
              ExReleaseResourceLite(&DAT_14000b7c0);
              KeLeaveCriticalRegion();
              puVar9 = (undefined8 *)0x0;
              if (bVar3) {
                puVar9 = puVar13;
              }
              if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                 ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
                WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                         &WPP_b8ec61bc8b283db232150b702b34e2f1_Traceguids,puVar9);
              }
              if (puVar9 == (undefined8 *)0x0) {
                *param_2 = 0;
                uVar14 = 0xc0000001;
                MupReleaseFileContext((longlong)puVar8);
              }
              else {
                *(undefined8 **)(puVar8 + 0x54) = puVar9;
                uVar14 = 0;
                *(undefined4 *)(puVar8 + 0x50) = 1;
                *(undefined4 *)(puVar8 + 0x6c) = 0;
                *(longlong *)(puVar8 + 0x48) = param_1;
                *param_2 = puVar8;
              }
              goto LAB_14001be07;
            }
            uVar14 = 0xc000009a;
          }
        }
      }
    }
  }
  *param_2 = 0;
LAB_14001be07:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
              &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,param_1,(char)uVar14);
  }
  return uVar14;
}



===== MupiCreateWithAbsolutePath @ 14001bf80 =====

undefined8 * MupiCreateWithAbsolutePath(longlong param_1,char param_2,undefined8 *param_3)

{
  undefined2 *puVar1;
  int iVar2;
  code *pcVar3;
  longlong lVar4;
  char cVar5;
  ushort uVar6;
  uint in_EAX;
  uint uVar7;
  int iVar8;
  undefined2 *_Dst;
  short *psVar9;
  undefined8 uVar10;
  longlong lVar11;
  undefined4 *_Dst_00;
  ulonglong uVar12;
  undefined8 *puVar13;
  undefined *puVar14;
  short sVar15;
  undefined4 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  ushort *puVar19;
  undefined8 *puVar20;
  short *_Size;
  short *psVar21;
  undefined8 *puVar22;
  char cVar23;
  undefined2 uVar24;
  uint uVar25;
  undefined8 *puVar26;
  bool bVar27;
  bool bVar28;
  char local_res20;
  undefined1 auStackY_168 [8];
  undefined1 auStackY_160 [24];
  char local_135;
  byte local_134;
  char local_133;
  int local_130;
  short *local_128;
  uint local_120;
  uint local_11c;
  ulonglong local_118;
  uint local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  longlong lStack_e8;
  undefined4 local_e0;
  undefined4 uStack_dc;
  short *psStack_d8;
  int local_d0 [2];
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  short *local_a8;
  longlong local_a0;
  undefined8 local_98;
  short *psStack_90;
  ushort local_88 [8];
  undefined8 local_78;
  undefined8 uStack_70;
  ushort local_68 [8];
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 *local_48;
  undefined8 *local_40;
  
  local_f0 = 0;
  lStack_e8 = 0;
  local_11c = in_EAX & 0xffffff00;
  local_134 = 0;
  local_135 = '\0';
  *param_3 = 0;
  RtlInitUnicodeString(&local_f0,0);
  local_res20 = '\0';
  bVar28 = false;
  local_133 = '\0';
  uVar6 = *(ushort *)(param_1 + 0x58);
  uVar25 = uVar6 & 0xfffffffe;
  local_100 = (short *)(CONCAT44(local_100._4_4_,(uint)uVar6) & 0xfffffffffffffffe);
  if ((uVar6 & 0xfffe) == 0) {
    uVar7 = 0x108;
    uVar25 = 2;
    local_100 = (short *)CONCAT44(local_100._4_4_,2);
  }
  else {
    uVar7 = uVar25 + 0x100;
  }
  local_128 = (short *)(ulonglong)uVar7;
  _Size = (short *)0x6346754d;
  local_108 = uVar7;
  _Dst = (undefined2 *)ExAllocatePool2(0x42);
  if (_Dst == (undefined2 *)0x0) {
    puVar22 = (undefined8 *)0xc000009a;
    local_130 = -0x3fffff66;
  }
  else {
    _Size = local_128;
    memset(_Dst,0,(size_t)local_128);
    *_Dst = 0x7108;
    _Dst[1] = (short)uVar7;
    *(undefined4 *)(_Dst + 2) = 1;
    puVar1 = _Dst + 100;
    *(undefined2 **)(_Dst + 0x68) = puVar1;
    *(undefined2 **)puVar1 = puVar1;
    *(undefined4 *)(_Dst + 0x50) = 0;
    _Dst[0x80] = 0;
    *(undefined2 **)(_Dst + 0x34) = _Dst + 0x80;
    _Dst[0x31] = (short)uVar25;
    _Dst[0x30] = 0;
    *(longlong *)(_Dst + 0x48) = param_1;
    uVar6 = *(ushort *)(param_1 + 0x58);
    if (uVar6 != 0) {
      _Dst[0x30] = uVar6;
      *(undefined8 *)(_Dst + 0x14) = *(undefined8 *)(_Dst + 0x30);
      *(undefined8 *)(_Dst + 0x18) = *(undefined8 *)(_Dst + 0x34);
      _Size = (short *)(ulonglong)uVar6;
      memmove(*(void **)(_Dst + 0x34),*(void **)(param_1 + 0x60),(size_t)_Size);
    }
    bVar27 = false;
    uVar25 = (uint)(*(ushort *)(param_1 + 0x58) >> 1);
    uVar12 = (ulonglong)uVar25;
    if (uVar25 != 0) {
      psVar21 = (short *)(*(longlong *)(param_1 + 0x60) + 2);
      uVar12 = (ulonglong)(uVar25 - 1);
      _Size = (short *)(ulonglong)(uVar25 - 1);
      psVar9 = MupFindMatchingChar(psVar21,uVar12,(longlong)_Size);
      if ((psVar9 != (short *)0x0) &&
         ((int)uVar12 != (int)((longlong)(psVar9 + 1) - (longlong)psVar21 >> 1))) {
        bVar27 = psVar9[1] == 0x3b;
      }
    }
    if (bVar27) {
      *(undefined4 *)(_Dst + 0x50) = 3;
LAB_14001c411:
      if (bVar28 == false) goto LAB_14001c161;
    }
    else {
      bVar28 = false;
      if (1 < uVar25) {
        bVar28 = *(short *)(*(longlong *)(param_1 + 0x60) + 2) == 0x3b;
      }
      local_133 = bVar28;
      if (bVar28 != false) {
        *(undefined4 *)(_Dst + 0x50) = 2;
        goto LAB_14001c411;
      }
LAB_14001c161:
      if (!bVar27) {
        *(undefined8 *)(_Dst + 0x5c) = 0;
        *(undefined8 *)(_Dst + 0x54) = 0;
        *(undefined4 *)(_Dst + 0x50) = 1;
        MupSaveProviderStrippedFileName((longlong)_Dst,'\x01');
        MupSaveStrippedFileName((longlong)_Dst,'\x01');
        local_res20 = '\x01';
        _Size = (short *)&local_135;
        uVar10 = MupiCheckForProviderAvoidPath
                           ((ushort *)(param_1 + 0x58),(undefined8 *)0x0,(undefined1 *)_Size);
        if ((char)uVar10 != '\0') {
          local_11c = local_11c & 0xff;
          if (local_135 == '\0') {
            local_11c = 1;
          }
          local_134 = (byte)local_11c;
        }
        local_130 = 0;
        puVar22 = (undefined8 *)0x0;
        goto LAB_14001c549;
      }
    }
    local_98 = 0;
    psStack_90 = (short *)0x0;
    local_128 = (short *)((ulonglong)local_128 & 0xffffffff00000000);
    local_118 = local_118 & 0xffffffff00000000;
    lVar11 = 0;
    local_a0 = 0;
    local_a8 = *(short **)(param_1 + 0x60);
    uVar25 = (uint)(*(ushort *)(param_1 + 0x58) >> 1);
    if (uVar25 == 0) {
      puVar22 = (undefined8 *)0xc0000420;
      local_120 = 0;
LAB_14001c51c:
      if (lVar11 != 0) {
        ExFreePoolWithTag(lVar11,0);
      }
    }
    else {
      psVar9 = local_a8 + 1;
      local_120 = uVar25 - 1;
      if (local_120 == 0) {
        puVar22 = (undefined8 *)0xc0000420;
        local_a8 = psVar9;
        goto LAB_14001c51c;
      }
      if (*psVar9 == 0x3b) {
        local_120 = uVar25 - 2;
        psVar9 = local_a8 + 2;
        if (local_120 == 0) {
          puVar22 = (undefined8 *)0xc0000420;
          local_a8 = local_a8 + 2;
          goto LAB_14001c51c;
        }
      }
      local_a8 = psVar9;
      psVar9 = local_a8;
      uVar25 = local_120;
      _Size = (short *)(ulonglong)local_120;
      local_100 = MupFindMatchingChar(local_a8,uVar12,(longlong)_Size);
      if (local_100 == (short *)0x0) {
        uVar12 = (ulonglong)uVar25;
      }
      else {
        uVar12 = (longlong)local_100 - (longlong)psVar9 >> 1;
      }
      lVar4 = (uVar12 & 0xffffffff) * 2;
      uVar7 = (int)lVar4 + 0x10;
      local_118 = CONCAT44(local_118._4_4_,uVar7);
      if (0xffff < uVar7) {
LAB_14001c514:
        puVar22 = (undefined8 *)0xc000000d;
        goto LAB_14001c51c;
      }
      _Size = (short *)0x6e44754d;
      lVar11 = ExAllocatePool2(0x102,uVar7);
      local_a0 = lVar11;
      if (lVar11 == 0) {
        puVar22 = (undefined8 *)0xc000009a;
        goto LAB_14001c51c;
      }
      uVar25 = uVar25 - (int)uVar12;
      uVar12 = (ulonglong)uVar25 * 2;
      uVar7 = (uint)uVar12;
      local_128 = (short *)CONCAT44(local_128._4_4_,uVar7);
      local_120 = uVar25;
      if (0xffff < uVar7) goto LAB_14001c514;
      local_f0 = (ulonglong)CONCAT42(local_f0._4_4_,(short)local_118) << 0x10;
      lStack_e8 = lVar11;
      RtlAppendUnicodeToString(&local_f0,L"\\Device\\");
      uVar24 = (undefined2)lVar4;
      local_98 = CONCAT62(CONCAT42(local_98._4_4_,uVar24),uVar24);
      psStack_90 = psVar9;
      RtlAppendUnicodeStringToString(&local_f0,&local_98);
      if (uVar25 == 0) {
        ExFreePoolWithTag(*(void **)(param_1 + 0x60),0);
        RtlInitUnicodeString(param_1 + 0x58,0);
      }
      else {
        *(short *)(param_1 + 0x58) = (short)uVar12;
        memmove(*(void **)(param_1 + 0x60),local_100,uVar12 & 0xffffffff);
        _Size = (short *)(ulonglong)(*(ushort *)(param_1 + 0x5a) - uVar7);
        memset((void *)(uVar12 + *(longlong *)(param_1 + 0x60)),0,(size_t)_Size);
      }
      puVar22 = (undefined8 *)0x0;
    }
    local_130 = (int)puVar22;
    if (local_130 == 0) {
      if ((!bVar27) ||
         (local_48 = MupAcquireSurrogateProviderByName((wchar_t *)&local_f0),
         local_48 == (undefined8 *)0x0)) {
        puVar20 = MupAcquireUncProviderByName((wchar_t *)&local_f0);
        local_40 = puVar20;
        if (puVar20 == (undefined8 *)0x0) {
          puVar22 = (undefined8 *)0xc0000039;
          local_130 = -0x3fffffc7;
        }
        else {
          MupSaveProviderStrippedFileName((longlong)_Dst,'\x01');
          MupSaveStrippedFileName((longlong)_Dst,'\x01');
          *(undefined8 **)(_Dst + 0x54) = puVar20;
          *(undefined8 *)(_Dst + 0x5c) = 0;
          if (*(short *)(param_1 + 0x58) != 0) {
            if (*(int *)((longlong)puVar20 + 0x44) == 2) {
              local_130 = -0x3fffff5d;
              puVar22 = (undefined8 *)0xc00000a3;
            }
            else {
              local_res20 = '\x01';
            }
          }
        }
      }
      else {
        *(undefined8 *)(_Dst + 0x54) = 0;
        *(undefined8 **)(_Dst + 0x5c) = local_48;
        MupSaveProviderStrippedFileName((longlong)_Dst,'\x01');
        MupSaveStrippedFileName((longlong)_Dst,'\x01');
        local_res20 = '\x01';
        local_130 = 0;
        puVar22 = (undefined8 *)0x0;
      }
    }
  }
LAB_14001c549:
  puVar17 = auStackY_168;
  puVar18 = auStackY_168;
  if (lStack_e8 != 0) {
    ExFreePoolWithTag(lStack_e8,0);
  }
  if ((int)puVar22 != 0) goto LAB_14001c9a3;
  local_e0 = *(undefined4 *)(_Dst + 0x40);
  uStack_dc = *(undefined4 *)(_Dst + 0x42);
  psStack_d8 = *(short **)(_Dst + 0x44);
  *(undefined8 *)(_Dst + 0x7c) = 0;
  KeEnterCriticalRegion();
  uVar6 = (ushort)local_e0;
  if (1 < (ushort)local_e0) {
    _Size = (short *)0xfffe;
    sVar15 = local_e0._2_2_;
    do {
      if (*psStack_d8 != 0x5c) break;
      psStack_d8 = psStack_d8 + 1;
      uVar6 = uVar6 - 2;
      sVar15 = sVar15 + -2;
      local_e0 = CONCAT22(sVar15,uVar6);
    } while (1 < uVar6);
  }
  if (uVar6 == 0) {
LAB_14001c989:
    puVar22 = (undefined8 *)0x0;
  }
  else {
    _Size = (short *)&DAT_14000b260;
    iVar8 = RtlRunOnceExecuteOnce
                      (&DAT_14000b268,MupAttemptToLoadRegistryConfigurationRunOnce,&DAT_14000b260,0)
    ;
    if (-1 < iVar8) {
      ExAcquirePushLockExclusiveEx(&DAT_14000b228,0);
      _Size = (short *)0x0;
      lVar11 = RtlFindUnicodePrefix(&DAT_14000b230,&local_e0);
      puVar16 = (undefined4 *)(lVar11 + -8);
      if (lVar11 == 0) {
        puVar16 = (undefined4 *)0x0;
      }
      if (puVar16 == (undefined4 *)0x0) {
        ExReleasePushLockExclusiveEx(&DAT_14000b228,0);
        local_88[0] = 0;
        local_88[1] = 0;
        local_88[2] = 0;
        local_88[3] = 0;
        local_88[4] = 0;
        local_88[5] = 0;
        local_88[6] = 0;
        local_88[7] = 0;
        local_58 = 0;
        uStack_50 = 0;
        local_68[0] = 0;
        local_68[1] = 0;
        local_68[2] = 0;
        local_68[3] = 0;
        local_68[4] = 0;
        local_68[5] = 0;
        local_68[6] = 0;
        local_68[7] = 0;
        _Size = (short *)&local_58;
        MupiGetPathComponents
                  ((ushort *)&local_e0,(short *)local_88,_Size,(short *)local_68,(short *)0x0);
        if (local_68[0] == 0) {
          puVar19 = local_88;
          uVar6 = local_88[0];
        }
        else {
          puVar19 = local_68;
          uVar6 = local_68[0];
        }
        puVar16 = (undefined4 *)0x0;
        if (uVar6 < 2) {
          puVar20 = (undefined8 *)0xc000000d;
LAB_14001cd3e:
          puVar22 = puVar20;
          _Dst_00 = (undefined4 *)0x0;
          if (puVar16 != (undefined4 *)0x0) {
            MupiDereferenceUncHardeningPrefixEntry((longlong)puVar16);
            _Dst_00 = (undefined4 *)0x0;
          }
        }
        else {
          _Size = (short *)0x4855754d;
          _Dst_00 = (undefined4 *)ExAllocatePool2(0x102);
          if (_Dst_00 == (undefined4 *)0x0) {
            puVar20 = (undefined8 *)0xc0000017;
            goto LAB_14001cd3e;
          }
          memset(_Dst_00,0,0x60);
          *_Dst_00 = 0x60710f;
          _Dst_00[1] = 1;
          *(undefined4 **)(_Dst_00 + 0x12) = _Dst_00 + 0x18;
          uVar6 = *puVar19;
          *(ushort *)((longlong)_Dst_00 + 0x42) = uVar6;
          *(ushort *)(_Dst_00 + 0x10) = uVar6;
          memmove(_Dst_00 + 0x18,*(void **)(puVar19 + 4),(ulonglong)*puVar19);
          KeEnterCriticalRegion();
          ExAcquirePushLockSharedEx(&DAT_14000b248,0);
          local_d0[0] = 0;
          local_d0[1] = 0;
          uStack_c8 = 0;
          local_c0 = 0;
          uStack_b8 = 0;
          local_b0 = 0;
          local_118 = 0;
          psVar9 = (short *)0x0;
          local_128 = (short *)0x0;
          local_100 = (short *)0x0;
          local_78 = 0;
          uStack_70 = 0;
          _Size = (short *)&local_78;
          uVar25 = RtlDuplicateUnicodeString(0,local_88);
          puVar20 = (undefined8 *)(ulonglong)uVar25;
          if (-1 < (int)uVar25) {
            MupiUndecorateServerName((ushort *)&local_78);
            uVar12 = RfsServerNameInitialize(&local_78,local_d0);
            puVar20 = (undefined8 *)(uVar12 & 0xffffffff);
          }
          RtlFreeUnicodeString(&local_78);
          iVar8 = local_d0[0];
          if (-1 < (int)puVar20) {
            puVar22 = &DAT_14000b250;
            if (((undefined8 **)DAT_14000b250 != &DAT_14000b250) &&
               (psVar21 = (short *)(DAT_14000b250 + -1), psVar21 != (short *)0x0)) {
              do {
                bVar28 = false;
                iVar2 = *(int *)(psVar21 + 0xc);
                if (iVar2 == iVar8) {
                  if (iVar2 == 0) {
                    cVar23 = '\x01';
                  }
                  else if (iVar2 == 1) {
                    _Size = (short *)0x0;
                    uVar12 = RfspServerNameEqualDnsName
                                       ((longlong)(psVar21 + 0xc),(longlong)local_d0,'\0');
                    cVar23 = (char)uVar12;
                    puVar22 = &DAT_14000b250;
                    iVar8 = local_d0[0];
                  }
                  else if (iVar2 == 2) {
                    uVar12 = RfspServerNameEqualSockaddr
                                       ((longlong)(psVar21 + 0xc),(longlong)local_d0);
                    cVar23 = (char)uVar12;
                    iVar8 = local_d0[0];
                  }
                  else {
                    cVar23 = '\0';
                  }
                }
                else {
                  cVar23 = '\0';
                }
                if (psVar21[0x20] != 0) {
                  _Size = (short *)CONCAT71((int7)((ulonglong)_Size >> 8),1);
                  cVar5 = RtlEqualUnicodeString(psVar21 + 0x20,&local_58);
                  bVar28 = cVar5 != '\0';
                  puVar22 = &DAT_14000b250;
                  iVar8 = local_d0[0];
                }
                if (cVar23 == '\0') {
LAB_14001c853:
                  if ((bVar28) && (*(int *)(psVar21 + 0xc) == 0)) {
                    local_128 = psVar21;
                  }
                }
                else {
                  if (bVar28) {
                    _Size = psVar21;
                    local_100 = (short *)MupiSelectBestMatchingConfigurationEntry
                                                   (local_d0,(longlong)local_100,(longlong)psVar21);
                  }
                  else {
                    if ((cVar23 == '\0') || (psVar21[0x20] != 0)) goto LAB_14001c853;
                    _Size = psVar21;
                    local_118 = MupiSelectBestMatchingConfigurationEntry
                                          (local_d0,local_118,(longlong)psVar21);
                  }
                  iVar8 = local_d0[0];
                }
              } while ((*(undefined8 **)(psVar21 + 4) != puVar22) &&
                      (psVar21 = (short *)(*(undefined8 **)(psVar21 + 4) + -1),
                      psVar21 != (short *)0x0));
              psVar9 = local_128;
            }
            if (psVar9 != (short *)0x0) {
              MupiApplyUncHardeningConfigurationEntryToPrefixEntry
                        ((longlong)psVar9,(longlong)_Dst_00);
              iVar8 = local_d0[0];
            }
            if (local_118 != 0) {
              MupiApplyUncHardeningConfigurationEntryToPrefixEntry(local_118,(longlong)_Dst_00);
              iVar8 = local_d0[0];
            }
            if (local_100 != (short *)0x0) {
              MupiApplyUncHardeningConfigurationEntryToPrefixEntry
                        ((longlong)local_100,(longlong)_Dst_00);
              iVar8 = local_d0[0];
            }
            puVar20 = (undefined8 *)0x0;
          }
          puVar22 = (undefined8 *)0x0;
          if (iVar8 == 1) {
            local_100 = (short *)0x0;
            local_f8 = uStack_c8;
            RtlFreeUnicodeString(&local_100);
          }
          else if (iVar8 == 2) {
            ExFreePoolWithTag(uStack_c8,0x5266534c);
          }
          ExReleasePushLockSharedEx(&DAT_14000b248,0);
          KeLeaveCriticalRegion();
          puVar16 = _Dst_00;
          if ((int)puVar20 < 0) goto LAB_14001cd3e;
        }
        if ((int)puVar22 < 0) goto LAB_14001c993;
        ExAcquirePushLockExclusiveEx(&DAT_14000b228,0);
        _Size = (short *)0x0;
        lVar11 = RtlFindUnicodePrefix(&DAT_14000b230,&local_e0);
        puVar16 = (undefined4 *)(lVar11 + -8);
        if (lVar11 == 0) {
          puVar16 = (undefined4 *)0x0;
        }
        if (puVar16 == (undefined4 *)0x0) {
          _Size = (short *)(_Dst_00 + 2);
          RtlInsertUnicodePrefix(&DAT_14000b230,_Dst_00 + 0x10);
          puVar16 = _Dst_00;
        }
        else {
          MupiDereferenceUncHardeningPrefixEntry((longlong)_Dst_00);
        }
      }
      *(longlong *)(puVar16 + 0x14) = *(longlong *)(puVar16 + 0x14) + 1;
      ExReleasePushLockExclusiveEx(&DAT_14000b228,0);
      *(undefined4 **)(_Dst + 0x7c) = puVar16;
      goto LAB_14001c989;
    }
    puVar22 = (undefined8 *)0xc0000201;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
      _Size = (short *)&WPP_64aa67e67b403fd701aa854e8be64937_Traceguids;
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
               &WPP_64aa67e67b403fd701aa854e8be64937_Traceguids,0xc0000201);
    }
  }
LAB_14001c993:
  KeLeaveCriticalRegion();
  local_130 = (int)puVar22;
LAB_14001c9a3:
  puVar20 = (undefined8 *)0x0;
  if ((int)puVar22 == 0) {
    puVar17 = auStackY_168;
    if (local_res20 != (char)puVar22) {
      if (*(longlong *)(_Dst + 0x7c) == 0) {
        local_118._0_4_ = 0;
      }
      else {
        local_118._0_4_ = *(undefined4 *)(*(longlong *)(_Dst + 0x7c) + 0x58);
      }
      bVar28 = false;
      puVar22 = puVar20;
LAB_14001c9db:
      do {
        do {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
            _Size = (short *)&WPP_0fb1d46681b331a7af1167046103ae69_Traceguids;
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,
                     &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,puVar22);
          }
          bVar27 = false;
          puVar26 = (undefined8 *)0x0;
          KeEnterCriticalRegion();
          ExAcquireResourceSharedLite(&DAT_14000b5e0,1);
          if (puVar22 == (undefined8 *)0x0) {
            puVar13 = DAT_14000b5c8;
          }
          else {
            puVar13 = (undefined8 *)puVar22[1];
          }
          for (; (undefined8 **)puVar13 != &DAT_14000b5c8; puVar13 = (undefined8 *)*puVar13) {
            puVar26 = puVar13 + -1;
            if (*(int *)(puVar13 + 3) == 2) {
              LOCK();
              *(int *)((longlong)puVar13 + -4) = *(int *)((longlong)puVar13 + -4) + 1;
              UNLOCK();
              bVar27 = true;
              local_11c = (uint)local_134;
              break;
            }
          }
          ExReleaseResourceLite(&DAT_14000b5e0);
          KeLeaveCriticalRegion();
          puVar13 = (undefined8 *)0x0;
          if (bVar27) {
            puVar13 = puVar26;
          }
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
            _Size = (short *)&WPP_0fb1d46681b331a7af1167046103ae69_Traceguids;
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x16,
                     &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,puVar13);
          }
          if ((puVar22 != (undefined8 *)0x0) && (bVar28)) {
            MupReleaseSurrogateProvider((longlong)puVar22);
            bVar28 = false;
          }
          if (puVar13 == (undefined8 *)0x0) goto LAB_14001cb63;
          puVar22 = puVar13;
          if ((~*(uint *)((longlong)puVar13 + 0x6c) & (uint)local_118) != 0) {
            bVar28 = true;
            goto LAB_14001c9db;
          }
        } while ((param_2 == '\x01') && ((*(byte *)(puVar13 + 0xe) & 1) == 0));
        if ((*(int *)(puVar13 + 3) == 2) &&
           (((char)local_11c != '\0' ||
            ((*(longlong *)(_Dst + 0x54) != 0 && (*(longlong *)(_Dst + 0x5c) == 0)))))) {
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
            WPP_SF_qZd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),puVar13 + 5,_Size,puVar13,
                       (wchar_t *)(puVar13 + 5),(char)local_11c);
          }
          bVar28 = true;
          goto LAB_14001c9db;
        }
        puVar16 = (undefined4 *)ExAllocatePool2(0x102,0x30,0x6653754d);
        if (puVar16 == (undefined4 *)0x0) break;
        *(undefined8 *)(puVar16 + 2) = 0;
        *(undefined8 *)(puVar16 + 4) = 0;
        *puVar16 = 0x307109;
        puVar16[1] = 1;
        *(undefined2 **)(puVar16 + 8) = _Dst;
        *(undefined8 **)(puVar16 + 6) = puVar13;
        *(undefined8 *)(puVar16 + 10) = 0;
        *(int *)(_Dst + 0x6c) = *(int *)(_Dst + 0x6c) + 0x90;
        puVar26 = (undefined8 *)(puVar16 + 2);
        _Size = *(short **)(_Dst + 0x68);
        if (*(undefined2 **)_Size != _Dst + 100) {
          puVar14 = (undefined *)0x3;
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)();
          puVar18 = auStackY_160;
          puVar22 = puVar20;
          goto LAB_14001cf05;
        }
        *puVar26 = _Dst + 100;
        *(short **)(puVar16 + 4) = _Size;
        *(undefined8 **)_Size = puVar26;
        *(undefined8 **)(_Dst + 0x68) = puVar26;
      } while (puVar16 != (undefined4 *)0x0);
      MupReleaseSurrogateProvider((longlong)puVar13);
      puVar20 = (undefined8 *)0xc000009a;
LAB_14001cb63:
      puVar17 = auStackY_168;
      puVar22 = puVar20;
      if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
        puVar14 = WPP_GLOBAL_Control;
        puVar17 = auStackY_168;
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0) {
LAB_14001cf05:
          *(int *)(puVar18 + 0x20) = (int)puVar22;
          uVar10 = *(undefined8 *)(puVar14 + 0x18);
          *(undefined8 *)(puVar18 + -8) = 0x14001cf21;
          WPP_SF_qD(uVar10,0x1b,&WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,_Dst,puVar18[0x20])
          ;
          puVar17 = puVar18;
        }
      }
    }
    if ((int)puVar22 == 0) {
      **(undefined8 **)(puVar17 + 0x180) = _Dst;
      return puVar22;
    }
  }
  if (_Dst != (undefined2 *)0x0) {
    *(undefined8 *)(puVar17 + -8) = 0x14001cf37;
    MupReleaseFileContext((longlong)_Dst);
  }
  return puVar22;
}



===== MupReleaseSurrogateProvider @ 14001cf50 =====

void MupReleaseSurrogateProvider(longlong param_1)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 uVar5;
  code *pcVar6;
  undefined1 *puVar7;
  bool bVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [40];
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x17,
             &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,param_1);
  }
  puVar7 = auStack_38;
  LOCK();
  piVar1 = (int *)(param_1 + 4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_14000b5e0,1);
    lVar3 = *(longlong *)(param_1 + 8);
    if ((*(longlong *)(lVar3 + 8) == param_1 + 8) &&
       (plVar4 = *(longlong **)(param_1 + 0x10), *plVar4 == param_1 + 8)) {
      *plVar4 = lVar3;
      *(longlong **)(lVar3 + 8) = plVar4;
      DAT_14000b648 = DAT_14000b648 + -1;
      ExReleaseResourceLite(&DAT_14000b5e0);
      KeLeaveCriticalRegion();
      if ((*(int *)(param_1 + 0x18) - 1U & 0xfffffffd) == 0) {
        LOCK();
        MupiCachingAndGenericSurrogateCount = MupiCachingAndGenericSurrogateCount + -1;
        UNLOCK();
      }
      lVar3 = *(longlong *)(param_1 + 0x40);
      bVar8 = *(void **)(param_1 + 0x58) != SystemReserved1[0xf];
      if (bVar8) {
        KeSetEvent(*(undefined8 *)(param_1 + 0x60),0,0);
      }
      if (lVar3 != 0) {
        ObfDereferenceObject(lVar3);
      }
      if (bVar8) {
        return;
      }
      goto LAB_14001d0c1;
    }
    pcVar6 = (code *)swi(0x29);
    (*pcVar6)(3);
    puVar7 = auStack_30;
  }
  else {
    puVar7 = auStack_38;
    if (*(void **)(param_1 + 0x58) != SystemReserved1[0xf]) {
      return;
    }
  }
  uVar5 = *(undefined8 *)(param_1 + 0x60);
  *(undefined8 *)(puVar7 + 0x20) = 0;
  *(undefined8 *)(puVar7 + -8) = 0x14001d0bc;
  KeWaitForSingleObject(uVar5,0,0,0);
LAB_14001d0c1:
  *(undefined8 *)(puVar7 + -8) = 0x14001d0c9;
  MupiFreeSurrogateProvider(param_1);
  return;
}



===== MupUncHardeningPostProcessCreate @ 14001d0e0 =====

undefined8 MupUncHardeningPostProcessCreate(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  char cVar5;
  byte bVar6;
  int iVar7;
  undefined7 extraout_var;
  uint local_res8 [2];
  longlong local_res10;
  longlong local_res18;
  
  lVar2 = *(longlong *)(param_1 + 0x28);
  lVar3 = *(longlong *)(lVar2 + 0xf8);
  if (lVar3 != 0) {
    uVar1 = *(uint *)(lVar3 + 0x58);
    uVar4 = *(undefined8 *)(param_1 + 0x10);
    local_res18 = 0;
    local_res10 = 0;
    local_res8[0] = 0;
    if ((uVar1 != 0) && (iVar7 = MupGetIoStatus(param_1), -1 < iVar7)) {
      iVar7 = FsRtlGetEcpListFromIrp(uVar4,&local_res18);
      if ((-1 < iVar7) &&
         ((((local_res18 != 0 &&
            (iVar7 = FsRtlFindExtraCreateParameter
                               (local_res18,&GUID_ECP_NETWORK_OPEN_CONTEXT,&local_res10,local_res8),
            -1 < iVar7)) && (local_res10 != 0)) &&
          ((0x1b < local_res8[0] && (cVar5 = FsRtlIsEcpAcknowledged(), cVar5 != '\0')))))) {
        bVar6 = MupiGetNetworkOpenEcpIntegrityLevelFromHardeningCapabilities((byte)uVar1);
        iVar7 = (int)CONCAT71(extraout_var,bVar6);
        if (((iVar7 == 0) ||
            ((*(int *)(local_res10 + 0x14) == iVar7 ||
             ((iVar7 == 2 && (*(int *)(local_res10 + 0x14) == 3)))))) &&
           ((~*(uint *)(local_res10 + 0x18) & (uVar1 & 1) << 3) == 0)) {
          return 0;
        }
      }
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x103,5,uVar4,param_1,lVar2);
    }
  }
  return 0;
}



===== MupAcquireUncProviderByName @ 14001d200 =====

undefined8 * MupAcquireUncProviderByName(wchar_t *param_1)

{
  undefined8 *puVar1;
  
  KeEnterCriticalRegion();
  ExAcquireResourceSharedLite(&DAT_14000b7c0,1);
  puVar1 = MupiFindProviderByName(param_1);
  if (puVar1 != (undefined8 *)0x0) {
    if ((*(int *)((longlong)puVar1 + 0x44) == 4) || (*(int *)((longlong)puVar1 + 0x44) == 1)) {
      puVar1 = (undefined8 *)0x0;
    }
    else {
      LOCK();
      *(int *)((longlong)puVar1 + 4) = *(int *)((longlong)puVar1 + 4) + 1;
      UNLOCK();
    }
  }
  ExReleaseResourceLite(&DAT_14000b7c0);
  KeLeaveCriticalRegion();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_b8ec61bc8b283db232150b702b34e2f1_Traceguids,param_1,(char)puVar1);
  }
  return puVar1;
}



===== MupSaveProviderStrippedFileName @ 14001d2d0 =====

void MupSaveProviderStrippedFileName(longlong param_1,char param_2)

{
  short sVar1;
  undefined8 uVar2;
  short *psVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  short *psVar8;
  short *psVar9;
  
  while( true ) {
    lVar7 = 0x70;
    lVar6 = 0x60;
    if (param_2 == '\0') {
      lVar7 = 0x38;
      lVar6 = 0x28;
    }
    psVar8 = (short *)(lVar7 + param_1);
    if (*(int *)(param_1 + 0xa0) == 1) {
      uVar2 = ((undefined8 *)(lVar6 + param_1))[1];
      *(undefined8 *)psVar8 = *(undefined8 *)(lVar6 + param_1);
      *(undefined8 *)(psVar8 + 4) = uVar2;
    }
    else {
      RtlInitUnicodeString(psVar8,0);
      uVar4 = (uint)(*(ushort *)(lVar6 + param_1) >> 1);
      if (uVar4 != 0) {
        uVar4 = uVar4 - 1;
        uVar5 = (ulonglong)uVar4;
        psVar9 = (short *)(*(longlong *)(lVar6 + 8 + param_1) + 2);
        psVar3 = MupFindMatchingChar(psVar9,uVar5,(ulonglong)uVar4);
        if (psVar3 != (short *)0x0) {
          *(short **)(psVar8 + 4) = psVar3;
          sVar1 = ((short)uVar5 - (short)((longlong)psVar3 - (longlong)psVar9 >> 1)) * 2;
          *psVar8 = sVar1;
          psVar8[1] = sVar1;
        }
      }
    }
    if (param_2 == '\0') break;
    param_2 = '\0';
  }
  return;
}



===== MupSaveStrippedFileName @ 14001d3a0 =====

void MupSaveStrippedFileName(longlong param_1,char param_2)

{
  short sVar1;
  undefined8 uVar2;
  short *psVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  short *psVar8;
  short *psVar9;
  
  while( true ) {
    lVar7 = 0x80;
    lVar6 = 0x70;
    if (param_2 == '\0') {
      lVar7 = 0x48;
      lVar6 = 0x38;
    }
    psVar8 = (short *)(lVar7 + param_1);
    if (*(int *)(param_1 + 0xa0) - 1U < 2) {
      uVar2 = ((undefined8 *)(lVar6 + param_1))[1];
      *(undefined8 *)psVar8 = *(undefined8 *)(lVar6 + param_1);
      *(undefined8 *)(psVar8 + 4) = uVar2;
    }
    else {
      RtlInitUnicodeString(psVar8,0);
      uVar4 = (uint)(*(ushort *)(lVar6 + param_1) >> 1);
      if (uVar4 != 0) {
        uVar4 = uVar4 - 1;
        uVar5 = (ulonglong)uVar4;
        psVar9 = (short *)(*(longlong *)(lVar6 + 8 + param_1) + 2);
        psVar3 = MupFindMatchingChar(psVar9,uVar5,(ulonglong)uVar4);
        if (psVar3 != (short *)0x0) {
          *(short **)(psVar8 + 4) = psVar3;
          sVar1 = ((short)uVar5 - (short)((longlong)psVar3 - (longlong)psVar9 >> 1)) * 2;
          *psVar8 = sVar1;
          psVar8[1] = sVar1;
        }
      }
    }
    if (param_2 == '\0') break;
    param_2 = '\0';
  }
  return;
}



===== MupiFindProviderByName @ 14001d480 =====

undefined8 * MupiFindProviderByName(undefined8 param_1)

{
  bool bVar1;
  char cVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  bVar1 = false;
  puVar4 = (undefined8 *)0x0;
  puVar3 = DAT_14000b7a8;
  do {
    if ((undefined8 **)puVar3 == &DAT_14000b7a8) {
LAB_14001d4db:
      puVar3 = (undefined8 *)0x0;
      if (bVar1) {
        puVar3 = puVar4;
      }
      return puVar3;
    }
    puVar4 = puVar3 + -1;
    cVar2 = RtlEqualUnicodeString(param_1,puVar3 + 2,1);
    if (cVar2 != '\0') {
      bVar1 = true;
      goto LAB_14001d4db;
    }
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



===== MupAcquireSurrogateProviderByName @ 14001d510 =====

undefined8 * MupAcquireSurrogateProviderByName(wchar_t *param_1)

{
  undefined8 *puVar1;
  
  KeEnterCriticalRegion();
  ExAcquireResourceSharedLite(&DAT_14000b5e0,1);
  puVar1 = MupiFindSurrogateByName(param_1);
  if (puVar1 != (undefined8 *)0x0) {
    if (*(int *)(puVar1 + 4) == 2) {
      LOCK();
      *(int *)((longlong)puVar1 + 4) = *(int *)((longlong)puVar1 + 4) + 1;
      UNLOCK();
    }
    else {
      puVar1 = (undefined8 *)0x0;
    }
  }
  ExReleaseResourceLite(&DAT_14000b5e0);
  KeLeaveCriticalRegion();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
              &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,param_1,(char)puVar1);
  }
  return puVar1;
}



===== MupiFindSurrogateByName @ 14001d5d0 =====

undefined8 * MupiFindSurrogateByName(undefined8 param_1)

{
  bool bVar1;
  char cVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  bVar1 = false;
  puVar4 = (undefined8 *)0x0;
  puVar3 = DAT_14000b5c8;
  do {
    if ((undefined8 **)puVar3 == &DAT_14000b5c8) {
LAB_14001d62b:
      puVar3 = (undefined8 *)0x0;
      if (bVar1) {
        puVar3 = puVar4;
      }
      return puVar3;
    }
    puVar4 = puVar3 + -1;
    cVar2 = RtlEqualUnicodeString(param_1,puVar3 + 4,1);
    if (cVar2 != '\0') {
      bVar1 = true;
      goto LAB_14001d62b;
    }
    puVar3 = (undefined8 *)*puVar3;
  } while( true );
}



===== MupSurrogateCheckNegativeCache @ 14001d660 =====

ulonglong MupSurrogateCheckNegativeCache(longlong *param_1,wchar_t *param_2)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined *puVar4;
  longlong lVar5;
  undefined *local_res8;
  
                    /* 0x1d660  3  MupSurrogateCheckNegativeCache */
  local_res8 = (undefined *)0x0;
  if ((param_1 == (longlong *)0x0) || (*param_1 == 0)) {
    uVar3 = MupGetContainerContextFromThread(&local_res8);
  }
  else {
    lVar2 = MupGetSiloFromFileObject();
    uVar3 = MupGetContainerContextFromSilo(lVar2,&local_res8);
  }
  puVar4 = local_res8;
  if ((int)uVar3 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
      WPP_SF_Z(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,param_2);
    }
    lVar2 = 0;
    KeEnterCriticalRegion();
    ExAcquireResourceExclusiveLite(&DAT_14000b7c0,1);
    puVar4 = MupGetUncCachePrefixTable(puVar4);
    lVar5 = RtlFindUnicodePrefix(puVar4,param_2,1);
    uVar3 = -(ulonglong)(lVar5 != 0) & lVar5 - 0x10U;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
      WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
                &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,param_2,(char)uVar3);
    }
    lVar5 = 0;
    if (uVar3 != 0) {
      lVar2 = *(longlong *)(uVar3 + 0x68);
      LOCK();
      *(int *)(lVar2 + 4) = *(int *)(lVar2 + 4) + 1;
      UNLOCK();
      lVar1 = *(longlong *)(uVar3 + 0x70);
      if (lVar1 != 0) {
        LOCK();
        *(int *)(lVar1 + 4) = *(int *)(lVar1 + 4) + 1;
        UNLOCK();
        lVar5 = lVar1;
      }
    }
    ExReleaseResourceLite(&DAT_14000b7c0);
    KeLeaveCriticalRegion();
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x12,
               &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,lVar2);
    }
    if (lVar2 != 0) {
      MupReleaseUncProvider(lVar2);
      if (lVar5 == 0) {
        return 0;
      }
      MupReleaseSurrogateProvider(lVar5);
    }
    uVar3 = 0xc0000225;
  }
  return uVar3;
}



===== MupGetContainerContextFromThread @ 14001d844 =====

ulonglong MupGetContainerContextFromThread(undefined8 *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  
  cVar1 = PsIsCurrentThreadInServerSilo();
  if (cVar1 == '\0') {
    uVar4 = 0;
    *param_1 = 0;
  }
  else {
    uVar2 = PsGetSiloMonitorContextSlot(ContainerMonitor);
    uVar3 = PsGetCurrentServerSilo();
    uVar4 = PsGetPermanentSiloContext(uVar3,uVar2,param_1);
    if ((((int)uVar4 != 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
      WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x13,
               &WPP_c898274d75623dfd801520d1a3be50ef_Traceguids,(int)uVar4);
      uVar4 = uVar4 & 0xffffffff;
    }
  }
  return uVar4;
}



===== MupGetUncCachePrefixTable @ 14001d8ec =====

undefined * MupGetUncCachePrefixTable(undefined *param_1)

{
  if (param_1 == (undefined *)0x0) {
    param_1 = MupGetUncCacheHostPrefixTable();
  }
  return param_1;
}



===== MupiGetNetworkOpenEcpIntegrityLevelFromHardeningCapabilities @ 14001d90c =====

byte MupiGetNetworkOpenEcpIntegrityLevelFromHardeningCapabilities(byte param_1)

{
  if ((param_1 & 4) == 0) {
    return param_1 & 2;
  }
  return 3;
}



===== MupiGetOrCreateEcpListForCreateIrp @ 14001d928 =====

undefined8 MupiGetOrCreateEcpListForCreateIrp(undefined8 param_1,longlong *param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong local_res10 [3];
  
  *param_2 = 0;
  local_res10[0] = 0;
  iVar1 = FsRtlGetEcpListFromIrp(param_1,local_res10);
  if (iVar1 < 0) {
LAB_14001d957:
    uVar2 = 0xc00000e5;
  }
  else {
    if (local_res10[0] == 0) {
      uVar2 = FsRtlAllocateExtraCreateParameterList(0,local_res10);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      iVar1 = FsRtlSetEcpListIntoIrp(param_1,local_res10[0]);
      if (iVar1 < 0) {
        FsRtlFreeExtraCreateParameterList();
        goto LAB_14001d957;
      }
    }
    uVar2 = 0;
    *param_2 = local_res10[0];
  }
  return uVar2;
}



===== MupiFindOrCreateNetworkOpenEcp @ 14001d9c0 =====

uint MupiFindOrCreateNetworkOpenEcp
               (undefined8 param_1,undefined8 *param_2,ulonglong param_3,undefined1 *param_4)

{
  uint uVar1;
  int iVar2;
  short *local_res10;
  ulonglong local_res18;
  
  local_res10 = (short *)0x0;
  local_res18 = param_3 & 0xffffffff00000000;
  *param_2 = 0;
  if (param_4 != (undefined1 *)0x0) {
    *param_4 = 0;
  }
  uVar1 = FsRtlFindExtraCreateParameter
                    (param_1,&GUID_ECP_NETWORK_OPEN_CONTEXT,&local_res10,&local_res18);
  if (uVar1 == 0xc0000225) {
    local_res10 = (short *)0x0;
  }
  else if ((int)uVar1 < 0) {
    return uVar1;
  }
  if (local_res10 == (short *)0x0) {
    local_res18 = CONCAT44(local_res18._4_4_,0x1c);
    uVar1 = FsRtlAllocateExtraCreateParameter
                      (&GUID_ECP_NETWORK_OPEN_CONTEXT,0x1c,0,0,0x6345754d,&local_res10);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    local_res10[0] = 0;
    local_res10[1] = 0;
    local_res10[2] = 0;
    local_res10[3] = 0;
    local_res10[4] = 0;
    local_res10[5] = 0;
    local_res10[6] = 0;
    local_res10[7] = 0;
    local_res10[8] = 0;
    local_res10[9] = 0;
    local_res10[10] = 0;
    local_res10[0xb] = 0;
    local_res10[0xc] = 0;
    local_res10[0xd] = 0;
    *local_res10 = 0x1c;
    iVar2 = FsRtlInsertExtraCreateParameter(param_1,local_res10);
    if (iVar2 < 0) {
      FsRtlFreeExtraCreateParameter(local_res10);
      return 0xc00000e5;
    }
    uVar1 = 0;
    if (param_4 != (undefined1 *)0x0) {
      *param_4 = 1;
    }
  }
  else {
    uVar1 = 0xc000000d;
    if (0x1b < (uint)local_res18) {
      uVar1 = -(uint)(*local_res10 != 0x1c) & 0xc000000d;
    }
    if ((int)uVar1 < 0) {
      return uVar1;
    }
  }
  *param_2 = local_res10;
  return uVar1;
}



===== MupInsertKnownPrefix @ 14001db0c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
MupInsertKnownPrefix
          (undefined *param_1,wchar_t *param_2,uint param_3,longlong param_4,int param_5,
          char param_6,undefined8 param_7)

{
  undefined8 uVar1;
  code *pcVar2;
  char cVar3;
  uint uVar4;
  undefined *puVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined1 *puVar11;
  undefined4 uVar12;
  undefined1 auStackY_48 [8];
  undefined1 auStackY_40 [24];
  
  uVar12 = 0;
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x19 & 1) != 0)) {
    WPP_SF_ZDq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
               &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,param_2,(char)param_3,(char)param_4)
    ;
  }
  puVar5 = MupGetUncCachePrefixTable(param_1);
  lVar6 = MupiAllocKnownPrefixEntry(param_3);
  puVar11 = auStackY_48;
  if (lVar6 == 0) {
    uVar12 = 0xc000009a;
    goto LAB_14001de47;
  }
  *(undefined4 *)(lVar6 + 0x88) = 0;
  *(longlong *)(lVar6 + 0x68) = param_4;
  *(undefined8 *)(lVar6 + 0x70) = param_7;
  *(void **)(lVar6 + 0x58) = (void *)(lVar6 + 0x8e);
  *(short *)(lVar6 + 0x50) = (short)param_3;
  *(short *)(lVar6 + 0x52) = (short)param_3;
  *(undefined1 *)(lVar6 + 0x8c) = 0;
  memmove((void *)(lVar6 + 0x8e),*(void **)(param_2 + 4),(ulonglong)param_3 & 0xffff);
  KeEnterCriticalRegion();
  ExAcquireResourceExclusiveLite(&DAT_14000b7c0,1);
  lVar7 = MupiLookupKnownPrefixEntry(puVar5,param_2);
  puVar11 = auStackY_48;
  if (lVar7 == 0) {
LAB_14001dcd5:
    if (DAT_14000b7b8 == param_5) {
LAB_14001dce4:
      lVar7 = _DAT_fffff78000000320;
      uVar4 = KeQueryTimeIncrement();
      *(longlong *)(lVar6 + 0x60) = DAT_14000ba30 / (longlong)(ulonglong)uVar4 + lVar7;
      cVar3 = RtlInsertUnicodePrefix(puVar5,lVar6 + 0x50,lVar6 + 0x10);
      puVar11 = auStackY_48;
      if (cVar3 == '\x01') {
        puVar10 = &DAT_14000ba20;
        puVar8 = (undefined8 *)(lVar6 + 0x78);
        puVar9 = DAT_14000ba28;
        if ((undefined8 *)*DAT_14000ba28 != &DAT_14000ba20) {
          puVar9 = (undefined8 *)0x3;
          pcVar2 = (code *)swi(0x29);
          puVar8 = (undefined8 *)(*pcVar2)();
          puVar11 = auStackY_40;
        }
        puVar8[1] = puVar9;
        *puVar8 = puVar10;
        *puVar9 = puVar8;
        DAT_14000ba28 = puVar8;
        *(undefined **)(lVar6 + 0x48) = puVar5;
        _DAT_14000ba44 = _DAT_14000ba44 + 1;
        DAT_14000ba40 = DAT_14000ba40 + 1;
        DAT_14000ba3c = DAT_14000ba3c + *(int *)(lVar6 + 8);
        if (DAT_14000ba40 == 1) {
          *(undefined8 *)(puVar11 + -8) = 0x14001dd8b;
          MupiPrefixScheduleGarbageCollectionTimeout();
        }
        *(undefined8 *)(puVar11 + -8) = 0x14001dd90;
        MupiPrefixCacheSizePolicyCheck();
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x19 & 1) != 0)) {
          uVar1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
          *(undefined8 *)(puVar11 + -8) = 0x14001ddbb;
          WPP_SF_q(uVar1,0xd,&WPP_ea0133f9b224365980f4880a222ef939_Traceguids,lVar6);
        }
        lVar6 = 0;
      }
      else {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x19 & 1) != 0)) {
          WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xe,
                  &WPP_ea0133f9b224365980f4880a222ef939_Traceguids);
        }
        puVar11 = auStackY_48;
        uVar12 = 0x40000000;
      }
    }
    else {
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x19 & 1) != 0)) {
        WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xf,
                &WPP_ea0133f9b224365980f4880a222ef939_Traceguids);
      }
      puVar11 = auStackY_48;
      uVar12 = 0xc0000001;
    }
  }
  else {
    if ((*(int *)(lVar7 + 0x88) == 0) || (*(longlong *)(lVar7 + 0x68) == param_4)) {
      if ((param_6 == '\0') || (*(char *)(lVar7 + 0x8c) != '\0')) goto LAB_14001dcd5;
      if (*(longlong *)(lVar7 + 0x68) == param_4) {
        if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
           ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x19 & 1) != 0)) {
          WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
                   &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,lVar7);
        }
        puVar11 = auStackY_48;
        *(undefined1 *)(lVar7 + 0x8c) = 1;
        goto LAB_14001de1b;
      }
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x19 & 1) != 0)) {
        WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
                 &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,lVar7);
      }
      MupiRemoveKnownPrefixEntry(lVar7);
      goto LAB_14001dce4;
    }
    uVar12 = 0x40000000;
  }
LAB_14001de1b:
  *(undefined8 *)(puVar11 + -8) = 0x14001de29;
  ExReleaseResourceLite(&DAT_14000b7c0);
  *(undefined8 *)(puVar11 + -8) = 0x14001de35;
  KeLeaveCriticalRegion();
  if (lVar6 != 0) {
    *(undefined8 *)(puVar11 + -8) = 0x14001de47;
    MupiFreeKnownPrefixEntry(lVar6);
  }
LAB_14001de47:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) >> 0x19 & 1) != 0)) {
    uVar1 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    *(undefined8 *)(puVar11 + -8) = 0x14001de72;
    WPP_SF_D(uVar1,0x10,&WPP_ea0133f9b224365980f4880a222ef939_Traceguids,uVar12);
  }
  return uVar12;
}



===== MupInitializeUncHardeningFileContext @ 14001dea0 =====

int MupInitializeUncHardeningFileContext(undefined4 *param_1,undefined8 *param_2)

{
  int iVar1;
  char cVar2;
  char cVar3;
  ushort uVar4;
  int iVar5;
  longlong lVar6;
  undefined4 *_Dst;
  ulonglong uVar7;
  short sVar8;
  undefined8 *puVar9;
  longlong lVar10;
  undefined4 *puVar11;
  undefined8 *puVar12;
  ushort *puVar13;
  undefined8 *puVar14;
  bool bVar15;
  undefined4 local_d8;
  undefined4 uStack_d4;
  short *psStack_d0;
  undefined4 *local_c8;
  undefined8 local_c0;
  ushort local_b8 [8];
  undefined8 local_a8;
  undefined8 uStack_a0;
  int local_98 [2];
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  ushort local_70 [8];
  undefined8 local_60;
  undefined8 uStack_58;
  
  local_d8 = *param_1;
  uStack_d4 = param_1[1];
  psStack_d0 = *(short **)(param_1 + 2);
  *param_2 = 0;
  KeEnterCriticalRegion();
  uVar4 = (ushort)local_d8;
  if (1 < (ushort)local_d8) {
    sVar8 = local_d8._2_2_;
    do {
      if (*psStack_d0 != 0x5c) break;
      psStack_d0 = psStack_d0 + 1;
      uVar4 = uVar4 - 2;
      sVar8 = sVar8 + -2;
      local_d8 = CONCAT22(sVar8,uVar4);
    } while (1 < uVar4);
  }
  if (uVar4 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = RtlRunOnceExecuteOnce
                      (&DAT_14000b268,MupAttemptToLoadRegistryConfigurationRunOnce,&DAT_14000b260,0)
    ;
    if (iVar5 < 0) {
      iVar5 = -0x3ffffdff;
      if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
         ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x1000000) != 0)) {
        WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x14,
                 &WPP_64aa67e67b403fd701aa854e8be64937_Traceguids,0xc0000201);
      }
    }
    else {
      ExAcquirePushLockExclusiveEx(&DAT_14000b228,0);
      lVar6 = RtlFindUnicodePrefix(&DAT_14000b230,&local_d8,0);
      puVar9 = (undefined8 *)0x0;
      puVar11 = (undefined4 *)(lVar6 + -8);
      if (lVar6 == 0) {
        puVar11 = (undefined4 *)0x0;
      }
      if (puVar11 == (undefined4 *)0x0) {
        ExReleasePushLockExclusiveEx(&DAT_14000b228,0);
        local_b8[0] = 0;
        local_b8[1] = 0;
        local_b8[2] = 0;
        local_b8[3] = 0;
        local_b8[4] = 0;
        local_b8[5] = 0;
        local_b8[6] = 0;
        local_b8[7] = 0;
        local_60 = 0;
        uStack_58 = 0;
        local_70[0] = 0;
        local_70[1] = 0;
        local_70[2] = 0;
        local_70[3] = 0;
        local_70[4] = 0;
        local_70[5] = 0;
        local_70[6] = 0;
        local_70[7] = 0;
        MupiGetPathComponents
                  ((ushort *)&local_d8,(short *)local_b8,(short *)&local_60,(short *)local_70,
                   (short *)0x0);
        if (local_70[0] == 0) {
          puVar13 = local_b8;
          uVar4 = local_b8[0];
        }
        else {
          puVar13 = local_70;
          uVar4 = local_70[0];
        }
        if (uVar4 < 2) {
          iVar5 = -0x3ffffff3;
          goto LAB_14001e29d;
        }
        _Dst = (undefined4 *)ExAllocatePool2(0x102,(ulonglong)uVar4 + 0x60,0x4855754d);
        local_c8 = _Dst;
        if (_Dst == (undefined4 *)0x0) {
          iVar5 = -0x3fffffe9;
          goto LAB_14001e29d;
        }
        memset(_Dst,0,0x60);
        *_Dst = 0x60710f;
        *(undefined4 **)(_Dst + 0x12) = _Dst + 0x18;
        _Dst[1] = 1;
        uVar4 = *puVar13;
        *(ushort *)((longlong)_Dst + 0x42) = uVar4;
        *(ushort *)(_Dst + 0x10) = uVar4;
        memmove(_Dst + 0x18,*(void **)(puVar13 + 4),(ulonglong)*puVar13);
        KeEnterCriticalRegion();
        ExAcquirePushLockSharedEx(&DAT_14000b248,0);
        local_78 = 0;
        local_98[0] = 0;
        local_98[1] = 0;
        uStack_90 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_a8 = 0;
        uStack_a0 = 0;
        iVar5 = RtlDuplicateUnicodeString(0,local_b8);
        if (-1 < iVar5) {
          MupiUndecorateServerName((ushort *)&local_a8);
          uVar7 = RfsServerNameInitialize(&local_a8,local_98);
          iVar5 = (int)uVar7;
        }
        RtlFreeUnicodeString(&local_a8);
        iVar1 = local_98[0];
        if (-1 < iVar5) {
          puVar12 = &DAT_14000b250;
          if (((undefined8 **)DAT_14000b250 != &DAT_14000b250) &&
             (puVar14 = DAT_14000b250 + -1, puVar14 != (undefined8 *)0x0)) {
            lVar10 = 0;
            lVar6 = 0;
            do {
              iVar5 = *(int *)(puVar14 + 3);
              bVar15 = false;
              if (iVar5 == iVar1) {
                if (iVar5 == 0) {
                  cVar2 = '\x01';
                }
                else if (iVar5 == 1) {
                  uVar7 = RfspServerNameEqualDnsName
                                    ((longlong)(puVar14 + 3),(longlong)local_98,'\0');
                  cVar2 = (char)uVar7;
                  puVar12 = &DAT_14000b250;
                }
                else if (iVar5 == 2) {
                  uVar7 = RfspServerNameEqualSockaddr((longlong)(puVar14 + 3),(longlong)local_98);
                  cVar2 = (char)uVar7;
                }
                else {
                  cVar2 = '\0';
                }
              }
              else {
                cVar2 = '\0';
              }
              if (*(short *)(puVar14 + 8) != 0) {
                cVar3 = RtlEqualUnicodeString(puVar14 + 8,&local_60);
                bVar15 = cVar3 != '\0';
                puVar12 = &DAT_14000b250;
              }
              if (cVar2 == '\0') {
                if ((bVar15) && (*(int *)(puVar14 + 3) == 0)) {
                  puVar9 = puVar14;
                }
              }
              else if (bVar15) {
                lVar6 = MupiSelectBestMatchingConfigurationEntry(local_98,lVar6,(longlong)puVar14);
              }
              else if (*(short *)(puVar14 + 8) == 0) {
                lVar10 = MupiSelectBestMatchingConfigurationEntry(local_98,lVar10,(longlong)puVar14)
                ;
              }
              _Dst = local_c8;
            } while (((undefined8 *)puVar14[1] != puVar12) &&
                    (puVar14 = (undefined8 *)puVar14[1] + -1, puVar14 != (undefined8 *)0x0));
            if (puVar9 != (undefined8 *)0x0) {
              MupiApplyUncHardeningConfigurationEntryToPrefixEntry
                        ((longlong)puVar9,(longlong)local_c8);
            }
            if (lVar10 != 0) {
              MupiApplyUncHardeningConfigurationEntryToPrefixEntry(lVar10,(longlong)_Dst);
            }
            if (lVar6 != 0) {
              MupiApplyUncHardeningConfigurationEntryToPrefixEntry(lVar6,(longlong)_Dst);
            }
          }
          iVar5 = 0;
        }
        if (iVar1 == 1) {
          local_c0 = uStack_90;
          local_c8 = (undefined4 *)0x0;
          RtlFreeUnicodeString(&local_c8);
        }
        else if (iVar1 == 2) {
          ExFreePoolWithTag(uStack_90,0x5266534c);
        }
        ExReleasePushLockSharedEx(&DAT_14000b248,0);
        KeLeaveCriticalRegion();
        if (iVar5 < 0) {
          MupiDereferenceUncHardeningPrefixEntry((longlong)_Dst);
          goto LAB_14001e29d;
        }
        ExAcquirePushLockExclusiveEx(&DAT_14000b228,0);
        lVar6 = RtlFindUnicodePrefix(&DAT_14000b230,&local_d8,0);
        puVar11 = (undefined4 *)(lVar6 + -8);
        if (lVar6 == 0) {
          puVar11 = (undefined4 *)0x0;
        }
        if (puVar11 == (undefined4 *)0x0) {
          RtlInsertUnicodePrefix(&DAT_14000b230,_Dst + 0x10,_Dst + 2);
          puVar11 = _Dst;
        }
        else {
          MupiDereferenceUncHardeningPrefixEntry((longlong)_Dst);
        }
      }
      iVar5 = 0;
      *(longlong *)(puVar11 + 0x14) = *(longlong *)(puVar11 + 0x14) + 1;
      ExReleasePushLockExclusiveEx(&DAT_14000b228,0);
      *param_2 = puVar11;
    }
  }
LAB_14001e29d:
  KeLeaveCriticalRegion();
  return iVar5;
}



===== MupiCreatePrefixEntryForPathFromConfiguration @ 14001e490 =====

int MupiCreatePrefixEntryForPathFromConfiguration
              (undefined8 param_1,ushort *param_2,undefined8 *param_3)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  ushort uVar4;
  int iVar5;
  undefined4 *_Dst;
  ulonglong uVar6;
  ushort *puVar7;
  longlong lVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  char cVar12;
  longlong local_b8;
  undefined4 *local_b0;
  undefined8 local_a8;
  ushort local_a0 [8];
  undefined8 local_90;
  undefined8 uStack_88;
  int local_80 [2];
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ushort local_58 [8];
  undefined8 local_48;
  undefined8 uStack_40;
  
  *param_3 = 0;
  local_a0[0] = 0;
  local_a0[1] = 0;
  local_a0[2] = 0;
  local_a0[3] = 0;
  local_a0[4] = 0;
  local_a0[5] = 0;
  local_a0[6] = 0;
  local_a0[7] = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[4] = 0;
  local_58[5] = 0;
  local_58[6] = 0;
  local_58[7] = 0;
  MupiGetPathComponents(param_2,(short *)local_a0,(short *)&local_48,(short *)local_58,(short *)0x0)
  ;
  if (local_58[0] == 0) {
    puVar7 = local_a0;
    uVar4 = local_a0[0];
  }
  else {
    puVar7 = local_58;
    uVar4 = local_58[0];
  }
  if (uVar4 < 2) {
    *param_3 = 0;
    iVar5 = -0x3ffffff3;
  }
  else {
    _Dst = (undefined4 *)ExAllocatePool2(0x102,(ulonglong)uVar4 + 0x60,0x4855754d);
    if (_Dst == (undefined4 *)0x0) {
      iVar5 = -0x3fffffe9;
    }
    else {
      local_b0 = _Dst;
      memset(_Dst,0,0x60);
      *_Dst = 0x60710f;
      *(undefined4 **)(_Dst + 0x12) = _Dst + 0x18;
      _Dst[1] = 1;
      uVar4 = *puVar7;
      *(ushort *)((longlong)_Dst + 0x42) = uVar4;
      *(ushort *)(_Dst + 0x10) = uVar4;
      memmove(_Dst + 0x18,*(void **)(puVar7 + 4),(ulonglong)*puVar7);
      KeEnterCriticalRegion();
      ExAcquirePushLockSharedEx(&DAT_14000b248,0);
      local_b8 = 0;
      local_60 = 0;
      local_80[0] = 0;
      local_80[1] = 0;
      uStack_78 = 0;
      local_70 = 0;
      uStack_68 = 0;
      local_90 = 0;
      uStack_88 = 0;
      iVar5 = RtlDuplicateUnicodeString(0,local_a0);
      if (-1 < iVar5) {
        MupiUndecorateServerName((ushort *)&local_90);
        uVar6 = RfsServerNameInitialize(&local_90,local_80);
        iVar5 = (int)uVar6;
      }
      RtlFreeUnicodeString(&local_90);
      iVar2 = local_80[0];
      if (-1 < iVar5) {
        puVar10 = &DAT_14000b250;
        if (((undefined8 **)DAT_14000b250 != &DAT_14000b250) &&
           (puVar9 = DAT_14000b250 + -1, puVar9 != (undefined8 *)0x0)) {
          puVar11 = (undefined8 *)0x0;
          lVar8 = 0;
          do {
            iVar5 = *(int *)(puVar9 + 3);
            bVar1 = false;
            if (iVar5 == iVar2) {
              if (iVar5 == 0) {
                cVar12 = '\x01';
              }
              else if (iVar5 == 1) {
                uVar6 = RfspServerNameEqualDnsName((longlong)(puVar9 + 3),(longlong)local_80,'\0');
                cVar12 = (char)uVar6;
                puVar10 = &DAT_14000b250;
              }
              else if (iVar5 == 2) {
                uVar6 = RfspServerNameEqualSockaddr((longlong)(puVar9 + 3),(longlong)local_80);
                cVar12 = (char)uVar6;
              }
              else {
                cVar12 = '\0';
              }
            }
            else {
              cVar12 = '\0';
            }
            if (*(short *)(puVar9 + 8) != 0) {
              cVar3 = RtlEqualUnicodeString(puVar9 + 8,&local_48);
              bVar1 = false;
              puVar10 = &DAT_14000b250;
              if (cVar3 != '\0') {
                bVar1 = true;
              }
            }
            if (cVar12 == '\0') {
              if ((bVar1) && (*(int *)(puVar9 + 3) == 0)) {
                puVar11 = puVar9;
              }
            }
            else if (bVar1) {
              local_b8 = MupiSelectBestMatchingConfigurationEntry
                                   (local_80,local_b8,(longlong)puVar9);
            }
            else if (*(short *)(puVar9 + 8) == 0) {
              lVar8 = MupiSelectBestMatchingConfigurationEntry(local_80,lVar8,(longlong)puVar9);
            }
            _Dst = local_b0;
          } while (((undefined8 *)puVar9[1] != puVar10) &&
                  (puVar9 = (undefined8 *)puVar9[1] + -1, puVar9 != (undefined8 *)0x0));
          if (puVar11 != (undefined8 *)0x0) {
            MupiApplyUncHardeningConfigurationEntryToPrefixEntry
                      ((longlong)puVar11,(longlong)local_b0);
          }
          if (lVar8 != 0) {
            MupiApplyUncHardeningConfigurationEntryToPrefixEntry(lVar8,(longlong)_Dst);
          }
          if (local_b8 != 0) {
            MupiApplyUncHardeningConfigurationEntryToPrefixEntry(local_b8,(longlong)_Dst);
          }
        }
        iVar5 = 0;
      }
      if (iVar2 == 1) {
        local_a8 = uStack_78;
        local_b0 = (undefined4 *)0x0;
        RtlFreeUnicodeString(&local_b0);
      }
      else if (iVar2 == 2) {
        ExFreePoolWithTag(uStack_78,0x5266534c);
      }
      ExReleasePushLockSharedEx(&DAT_14000b248,0);
      KeLeaveCriticalRegion();
      if (-1 < iVar5) {
        *param_3 = _Dst;
        return 0;
      }
      MupiDereferenceUncHardeningPrefixEntry((longlong)_Dst);
    }
    *param_3 = 0;
  }
  return iVar5;
}



===== MupInitializeServerName @ 14001e890 =====

ulonglong MupInitializeServerName(longlong param_1,int *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  ushort local_18 [8];
  
  local_18[0] = 0;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  local_18[4] = 0;
  local_18[5] = 0;
  local_18[6] = 0;
  local_18[7] = 0;
  if (param_1 != 0) {
    uVar1 = RtlDuplicateUnicodeString(0,param_1,local_18);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) goto LAB_14001e8df;
  }
  MupiUndecorateServerName(local_18);
  uVar2 = RfsServerNameInitialize(local_18,param_2);
  uVar2 = uVar2 & 0xffffffff;
LAB_14001e8df:
  RtlFreeUnicodeString(local_18);
  return uVar2;
}



===== MupiUndecorateServerName @ 14001e910 =====

void MupiUndecorateServerName(ushort *param_1)

{
  ushort *puVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  ulonglong uVar6;
  ushort uVar7;
  longlong lVar8;
  undefined4 local_18;
  undefined4 uStack_14;
  longlong lStack_10;
  
  lVar8 = 0;
  uStack_14 = 0;
  if (0xd < *param_1) {
    local_18 = 0xe000e;
    lStack_10 = ((ulonglong)*param_1 - 0xe) + *(longlong *)(param_1 + 4);
    cVar2 = RtlEqualUnicodeString(&local_18,&MupiServerNameDecoration_NOCSC,1);
    if (cVar2 != '\0') {
      *param_1 = *param_1 - 0xe;
    }
  }
  local_18 = *(undefined4 *)param_1;
  uStack_14 = *(undefined4 *)(param_1 + 2);
  lStack_10 = *(longlong *)(param_1 + 4);
  uVar3 = (ushort)local_18;
  do {
    if (uVar3 < 8) {
LAB_14001e9a6:
      if (*param_1 >> 1 != 0) {
        uVar6 = (ulonglong)(*param_1 >> 1);
        do {
          if (*(short *)(*(longlong *)(param_1 + 4) + lVar8) == 0x40) {
            *(undefined2 *)(*(longlong *)(param_1 + 4) + lVar8) = 0x3a;
          }
          lVar8 = lVar8 + 2;
          uVar6 = uVar6 - 1;
        } while (uVar6 != 0);
      }
      return;
    }
    cVar2 = RtlPrefixUnicodeString(&MupiServerNameDecoration_SSL,&local_18,1);
    if (cVar2 != '\0') {
      puVar1 = param_1 + 4;
      if (lStack_10 != 0) {
        uVar7 = (short)lStack_10 - *puVar1;
        uVar4 = 8;
        uVar3 = *param_1;
        if (uVar7 <= uVar3) {
          uVar5 = (uint)uVar3;
          if (uVar5 < uVar7 + 8) {
            uVar4 = uVar3 - uVar7;
          }
          if (uVar5 - uVar4 <= (uint)param_1[1]) {
            uVar6 = (ulonglong)uVar7;
            memmove((void *)(uVar6 + *(longlong *)puVar1),
                    (void *)(uVar4 + uVar6 + *(longlong *)puVar1),
                    (longlong)(int)((uVar5 - uVar4) - (uint)uVar7));
            memmove((void *)(*(longlong *)puVar1 + uVar6),(void *)0x0,0);
            uVar4 = *param_1 - uVar4;
            *param_1 = uVar4;
            if (1 < (ulonglong)param_1[1] - (ulonglong)uVar4) {
              *(undefined2 *)(*(longlong *)puVar1 + (ulonglong)(uVar4 >> 1) * 2) = 0;
            }
          }
        }
      }
      goto LAB_14001e9a6;
    }
    lStack_10 = lStack_10 + 2;
    uVar3 = (ushort)local_18 - 2;
    local_18 = CONCAT22(local_18._2_2_ + -2,uVar3);
  } while( true );
}



===== RfsServerNameInitialize @ 14001eb10 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong RfsServerNameInitialize(undefined8 param_1,int *param_2)

{
  undefined2 *puVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  ulonglong *puVar6;
  ushort uVar7;
  longlong lVar8;
  undefined2 *puVar9;
  longlong lVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined1 auStack_2b8 [32];
  ushort *local_298;
  undefined1 *local_290;
  ulonglong local_288;
  undefined2 *puStack_280;
  undefined4 local_278;
  undefined4 local_274;
  longlong local_270;
  undefined8 local_268;
  undefined2 *puStack_260;
  ulonglong local_258;
  undefined4 local_250;
  undefined1 local_248 [512];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_2b8;
  param_2[0] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  param_2[8] = 0;
  param_2[9] = 0;
  local_288 = 0;
  puStack_280 = (undefined2 *)0x0;
  uVar3 = RtlDuplicateUnicodeString(1,param_1,&local_288);
  uVar12 = (ulonglong)uVar3;
  if ((int)uVar3 < 0) goto LAB_14001ee9f;
  if ((ushort)local_288 == 0) {
    uVar12 = 0;
    *param_2 = 0;
    goto LAB_14001ee9f;
  }
  local_268 = 0;
  puStack_260 = (undefined2 *)0x0;
  iVar4 = RtlIpv4StringToAddressExW(puStack_280,1,(longlong)&local_268 + 4,(longlong)&local_268 + 2)
  ;
  if (iVar4 < 0) {
    local_258 = 0;
    local_250 = 0;
    local_268 = 0;
    puStack_260 = (undefined2 *)0x0;
    iVar4 = RtlIpv6StringToAddressExW(puStack_280,&puStack_260,&local_250,(longlong)&local_268 + 2);
    if (-1 < iVar4) {
      local_268 = CONCAT62(local_268._2_6_,0x17);
      puVar6 = (ulonglong *)ExAllocatePool2(0x102,0x1c,0x5266534c);
      *(ulonglong **)(param_2 + 2) = puVar6;
      if (puVar6 == (ulonglong *)0x0) goto LAB_14001f23e;
      *param_2 = 2;
      *puVar6 = local_268;
      puVar6[1] = (ulonglong)puStack_260;
      puVar6[2] = local_258;
      *(undefined4 *)(puVar6 + 3) = local_250;
      uVar5 = (ulonglong)local_250._3_1_;
      uVar11 = (((((((((((((((((ulonglong)puStack_260 >> 0x18 & 0xff) * 0x25 +
                             ((ulonglong)puStack_260 >> 0x20 & 0xff)) * 0x25 +
                            ((ulonglong)puStack_260 >> 0x28 & 0xff)) * 0x25 +
                           ((ulonglong)puStack_260 >> 0x30 & 0xff)) * 0x25 +
                          ((ulonglong)puStack_260 >> 0x38)) * 0x25 + (local_258 & 0xff)) * 0x25 +
                        (local_258 >> 8 & 0xff)) * 0x25 + (local_258 >> 0x10 & 0xff)) * 0x25 +
                      (local_258 >> 0x18 & 0xff)) * 0x25 + (local_258 >> 0x20 & 0xff)) * 0x25 +
                    (local_258 >> 0x28 & 0xff)) * 0x25 + (local_258 >> 0x30 & 0xff)) * 0x25 +
                   (local_268 >> 0x28 & 0xff) * -0x426f3c9cddc876e7 +
                   (local_268 & 0xff) * -0x1301f3864a8c6433 +
                   (local_268 >> 0x18 & 0xff) * -0x44db22de0503d94f +
                   (local_268 >> 0x38) * -0x2393ff1bfa2d963f +
                   (local_268 >> 0x10 & 0xff) * 0xc53f5e946719795 +
                   ((ulonglong)puStack_260 >> 0x10 & 0xff) * 0x3433b6f080ff8f35 +
                   (local_268 >> 8 & 0xff) * -0x37dd7548d1951777 +
                   (local_268 >> 0x20 & 0xff) * 0x65ec3d53f206d09d +
                   ((ulonglong)puStack_260 >> 8 & 0xff) * -0x74868f3d5b104d57 +
                   (local_268 >> 0x30 & 0xff) * -0x2463df0b2896b71b +
                   ((ulonglong)puStack_260 & 0xff) * 0x288d4c21d6a4d26d + -0x27dd6fa364fcfb71 +
                  (local_258 >> 0x38)) * 0x25 + (ulonglong)(byte)local_250) * 0x25 +
                (ulonglong)local_250._1_1_) * 0x25 + (ulonglong)local_250._2_1_) * 0x25;
      goto LAB_14001efcf;
    }
    local_290 = local_248;
    uVar12 = 0;
    local_298 = (ushort *)0x2000000;
    if (((ushort)local_288 < 0x1ff) && (local_274 = 0, 0x21 < (ushort)local_288)) {
      local_278 = 0x220022;
      local_270 = (longlong)puStack_280 + ((local_288 & 0xffff) - 0x22);
      cVar2 = RtlEqualUnicodeString(&local_278,&RfspIpv6LiteralDomainName,1);
      if (cVar2 == '\0') {
LAB_14001ed42:
        goto LAB_14001ed48;
      }
      puStack_260 = puStack_280;
      local_268._2_6_ = (undefined6)(local_288 >> 0x10);
      local_268 = CONCAT62(local_268._2_6_,(short)local_288 + -0x22);
      RtlCopyUnicodeString(&local_298,&local_268);
      if ((ushort)local_298 >> 1 != 0) {
        lVar8 = 0;
        uVar11 = (ulonglong)((ushort)local_298 >> 1);
        do {
          if (*(short *)(local_290 + lVar8) == 0x2d) {
            *(undefined2 *)(local_290 + lVar8) = 0x3a;
          }
          lVar8 = lVar8 + 2;
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
      if ((ushort)local_298 >> 1 != 0) {
        lVar8 = 0;
        uVar11 = (ulonglong)((ushort)local_298 >> 1);
        do {
          if (*(short *)(local_290 + lVar8) == 0x73) {
            *(undefined2 *)(local_290 + lVar8) = 0x25;
          }
          lVar8 = lVar8 + 2;
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
      if ((ushort)local_298 >> 1 != 0) {
        lVar8 = 0;
        uVar11 = (ulonglong)((ushort)local_298 >> 1);
        do {
          if (*(short *)(local_290 + lVar8) == 0x53) {
            *(undefined2 *)(local_290 + lVar8) = 0x25;
          }
          lVar8 = lVar8 + 2;
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
      uVar11 = RfspServerNameInitializeAsIpv6((longlong)&local_298,param_2);
      if ((int)uVar11 == -0x3fffffea) goto LAB_14001ed42;
      uVar12 = uVar11 & 0xffffffff;
      if ((int)uVar11 < 0) goto LAB_14001ee9f;
    }
    else {
LAB_14001ed48:
      *(undefined2 **)(param_2 + 2) = puStack_280;
      *param_2 = 1;
      *(ushort *)(param_2 + 4) = (ushort)local_288;
      for (uVar7 = 0; uVar7 < (ushort)local_288 >> 1; uVar7 = uVar7 + 1) {
        if (puStack_280[uVar7] == 0x2e) {
          if (puStack_280 + uVar7 != (undefined2 *)0x0) {
            *(short *)((longlong)param_2 + 0x12) =
                 (short)((longlong)(puStack_280 + uVar7) - (longlong)puStack_280 >> 1) * 2;
            goto LAB_14001edae;
          }
          break;
        }
      }
      *(ushort *)((longlong)param_2 + 0x12) = (ushort)local_288;
LAB_14001edae:
      local_298 = (ushort *)((longlong)param_2 + 0x12);
      lVar8 = 0x4cb2f;
      lVar10 = 0x4cb2f;
      puVar1 = puStack_280 + ((ushort)local_288 >> 1);
      puVar9 = puStack_280;
      if (puStack_280 < puVar1) {
        do {
          uVar7 = RtlUpcaseUnicodeChar(*puVar9);
          puVar9 = puVar9 + 1;
          lVar10 = (ulonglong)(uVar7 >> 8) + (lVar10 * 0x25 + ((ulonglong)uVar7 & 0xff)) * 0x25;
        } while (puVar9 < puVar1);
      }
      uVar7 = *local_298;
      *(longlong *)(param_2 + 6) = lVar10;
      puVar9 = *(undefined2 **)(param_2 + 2);
      puVar1 = puVar9 + (uVar7 >> 1);
      for (; puVar9 < puVar1; puVar9 = puVar9 + 1) {
        uVar7 = RtlUpcaseUnicodeChar(*puVar9);
        lVar8 = (ulonglong)(uVar7 >> 8) + (lVar8 * 0x25 + ((ulonglong)uVar7 & 0xff)) * 0x25;
      }
      *(longlong *)(param_2 + 8) = lVar8;
    }
  }
  else {
    local_268 = CONCAT62(local_268._2_6_,2);
    puVar6 = (ulonglong *)ExAllocatePool2(0x102,0x10,0x5266534c);
    *(ulonglong **)(param_2 + 2) = puVar6;
    if (puVar6 == (ulonglong *)0x0) {
LAB_14001f23e:
      uVar12 = 0xc000009a;
      goto LAB_14001ee9f;
    }
    *param_2 = 2;
    *puVar6 = local_268;
    puVar6[1] = (ulonglong)puStack_260;
    uVar11 = (ulonglong)puStack_260 >> 0x38;
    uVar5 = ((((((((((((local_268 >> 0x18 & 0xff) * 0x25 + (local_268 >> 0x20 & 0xff)) * 0x25 +
                     (local_268 >> 0x28 & 0xff)) * 0x25 + (local_268 >> 0x30 & 0xff)) * 0x25 +
                   (local_268 >> 0x38)) * 0x25 + ((ulonglong)puStack_260 & 0xff)) * 0x25 +
                 ((ulonglong)puStack_260 >> 8 & 0xff)) * 0x25 +
                ((ulonglong)puStack_260 >> 0x10 & 0xff)) * 0x25 +
               ((ulonglong)puStack_260 >> 0x18 & 0xff)) * 0x25 +
              ((ulonglong)puStack_260 >> 0x20 & 0xff)) * 0x25 +
             ((ulonglong)puStack_260 >> 0x28 & 0xff)) * 0x25 +
            ((ulonglong)puStack_260 >> 0x30 & 0xff)) * 0x25 +
            (local_268 >> 0x10 & 0xff) * 0x3433b6f080ff8f35 +
            (local_268 >> 8 & 0xff) * -0x74868f3d5b104d57 + (local_268 & 0xff) * 0x288d4c21d6a4d26d
            + 0x201911c49281756f;
LAB_14001efcf:
    uVar12 = 0;
    *(ulonglong *)(param_2 + 4) = uVar11 + uVar5;
  }
  if (*param_2 == 1) {
    return uVar12;
  }
LAB_14001ee9f:
  RtlFreeUnicodeString(&local_288);
  return uVar12;
}



===== RfspServerNameInitializeAsIpv6 @ 14001f250 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 RfspServerNameInitializeAsIpv6(longlong param_1,undefined4 *param_2)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong *puVar3;
  undefined1 auStack_58 [32];
  undefined8 local_38;
  ulonglong uStack_30;
  ulonglong local_28;
  undefined4 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = 0;
  local_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  iVar1 = RtlIpv6StringToAddressExW
                    (*(undefined8 *)(param_1 + 8),&uStack_30,&local_20,(longlong)&local_38 + 2);
  if (iVar1 < 0) {
    uVar2 = 0xc0000016;
  }
  else {
    local_38 = CONCAT62(local_38._2_6_,0x17);
    puVar3 = (ulonglong *)ExAllocatePool2(0x102,0x1c,0x5266534c);
    *(ulonglong **)(param_2 + 2) = puVar3;
    if (puVar3 == (ulonglong *)0x0) {
      uVar2 = 0xc000009a;
    }
    else {
      *param_2 = 2;
      *puVar3 = local_38;
      puVar3[1] = uStack_30;
      puVar3[2] = local_28;
      *(undefined4 *)(puVar3 + 3) = local_20;
      *(ulonglong *)(param_2 + 4) =
           ((((((((((((((((uStack_30 >> 0x18 & 0xff) * 0x25 + (uStack_30 >> 0x20 & 0xff)) * 0x25 +
                        (uStack_30 >> 0x28 & 0xff)) * 0x25 + (uStack_30 >> 0x30 & 0xff)) * 0x25 +
                      (uStack_30 >> 0x38)) * 0x25 + (local_28 & 0xff)) * 0x25 +
                    (local_28 >> 8 & 0xff)) * 0x25 + (local_28 >> 0x10 & 0xff)) * 0x25 +
                  (local_28 >> 0x18 & 0xff)) * 0x25 + (local_28 >> 0x20 & 0xff)) * 0x25 +
                (local_28 >> 0x28 & 0xff)) * 0x25 + (local_28 >> 0x30 & 0xff)) * 0x25 +
               (local_38 >> 0x18 & 0xff) * -0x44db22de0503d94f +
               (local_38 >> 0x38) * -0x2393ff1bfa2d963f +
               (local_38 >> 0x10 & 0xff) * 0xc53f5e946719795 +
               (local_38 & 0xff) * -0x1301f3864a8c6433 +
               (uStack_30 >> 0x10 & 0xff) * 0x3433b6f080ff8f35 +
               (local_38 >> 8 & 0xff) * -0x37dd7548d1951777 +
               (local_38 >> 0x20 & 0xff) * 0x65ec3d53f206d09d +
               (uStack_30 >> 8 & 0xff) * -0x74868f3d5b104d57 +
               (local_38 >> 0x30 & 0xff) * -0x2463df0b2896b71b +
               (uStack_30 & 0xff) * 0x288d4c21d6a4d26d +
               (local_38 >> 0x28 & 0xff) * -0x426f3c9cddc876e7 + -0x27dd6fa364fcfb71 +
              (local_28 >> 0x38)) * 0x25 + (ulonglong)(byte)local_20) * 0x25 +
            (ulonglong)local_20._1_1_) * 0x25 + (ulonglong)local_20._2_1_) * 0x25 +
           (ulonglong)local_20._3_1_;
      uVar2 = 0;
    }
  }
  return uVar2;
}



===== MupiDereferenceUncHardeningPrefixEntry @ 14001f4d0 =====

void MupiDereferenceUncHardeningPrefixEntry(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 4);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    ExFreePoolWithTag(param_1,0x4855754d);
  }
  return;
}



===== MupInitSurrogateIrpContext @ 14001f500 =====

void MupInitSurrogateIrpContext(longlong param_1,longlong param_2,undefined4 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined1 uVar6;
  undefined *puVar7;
  undefined1 *puVar8;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [48];
  
  puVar8 = auStack_38;
  lVar2 = *(longlong *)(param_1 + 0x20);
  *(longlong *)(param_3 + 6) = param_2;
  *param_3 = 0x90710b;
  param_3[1] = 1;
  *(longlong *)(param_3 + 8) = param_1;
  *(undefined8 *)(param_3 + 10) = *(undefined8 *)(param_2 + 0x10);
  *(longlong *)(param_3 + 0x12) = lVar2 + 0x60;
  *(longlong *)(param_3 + 0x14) = lVar2 + 0x70;
  *(longlong *)(param_3 + 0x16) = lVar2 + 0x80;
  *(longlong *)(param_3 + 0xc) = lVar2 + 0x28;
  *(longlong *)(param_3 + 0xe) = lVar2 + 0x38;
  *(longlong *)(param_3 + 0x10) = lVar2 + 0x48;
  param_3[0x18] = 0xc0000016;
  param_3[0x19] = 0xc0000016;
  *(undefined2 *)(param_3 + 0x1d) = 0xffff;
  *(undefined8 *)(param_3 + 0x22) = 0;
  *(undefined8 *)(param_3 + 0x20) = *(undefined8 *)(param_1 + 0x28);
  *(undefined1 *)((longlong)param_3 + 0x76) = 0;
  if ((*(longlong *)(lVar2 + 0xb8) == 0) || (*(int *)(*(longlong *)(lVar2 + 0xb8) + 0x18) != 2)) {
    uVar6 = 0;
  }
  else {
    uVar6 = 1;
  }
  *(undefined1 *)((longlong)param_3 + 0x77) = uVar6;
  *(undefined8 *)(param_3 + 0x1e) = 0;
  plVar1 = (longlong *)(param_3 + 2);
  plVar3 = *(longlong **)(param_2 + 0x50);
  if (*plVar3 == param_2 + 0x48) {
    *plVar1 = param_2 + 0x48;
    *(longlong **)(param_3 + 4) = plVar3;
    *plVar3 = (longlong)plVar1;
    *(longlong **)(param_2 + 0x50) = plVar1;
    if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
      return;
    }
    puVar7 = WPP_GLOBAL_Control;
    if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) == 0) {
      return;
    }
  }
  else {
    puVar7 = (undefined *)0x3;
    pcVar5 = (code *)swi(0x29);
    (*pcVar5)();
    puVar8 = auStack_30;
  }
  uVar4 = *(undefined8 *)(puVar7 + 0x18);
  *(undefined4 **)(puVar8 + 0x20) = param_3;
  *(undefined8 *)(puVar8 + -8) = 0x14001f611;
  WPP_SF_qq(uVar4,0x1d,&WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,param_2,puVar8[0x20]);
  return;
}



===== MupReleaseSurrogateIrpContext @ 14001f620 =====

void MupReleaseSurrogateIrpContext(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x1e,
             &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,param_1);
  }
  lVar1 = *(longlong *)(param_1 + 8);
  if ((*(longlong *)(lVar1 + 8) == param_1 + 8) &&
     (plVar2 = *(longlong **)(param_1 + 0x10), *plVar2 == param_1 + 8)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    *(undefined8 *)(param_1 + 0x20) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x80) = 0;
    *(undefined8 *)(param_1 + 0x88) = 0;
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== MupSurrogateGetUncProviderDeviceObject @ 14001f6b0 =====

undefined8 MupSurrogateGetUncProviderDeviceObject(longlong param_1,byte *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
                    /* 0x1f6b0  7  MupSurrogateGetUncProviderDeviceObject */
  lVar1 = *(longlong *)(*(longlong *)(*(longlong *)(param_1 + -8) + 0x20) + 0xa8);
  if (lVar1 == 0) {
    return 0;
  }
  uVar2 = *(undefined8 *)(lVar1 + 0xa8);
  *param_2 = *(byte *)(lVar1 + 0x94) >> 3 & 1;
  return uVar2;
}



===== MupSurrogateGetFileName @ 14001f6f0 =====

undefined8 MupSurrogateGetFileName(longlong param_1,int param_2,char param_3,undefined8 *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
                    /* 0x1f6f0  6  MupSurrogateGetFileName */
  uVar2 = 0;
  if (param_1 == 0) {
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
      WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x10,
              &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids);
    }
LAB_14001f77b:
    uVar2 = 0xc000000d;
  }
  else {
    *param_4 = 0;
    param_4[1] = 0;
    lVar1 = MupFindFileContext(param_1);
    if (lVar1 == 0) {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0xc0000225;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) == 0) {
        return 0xc0000225;
      }
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x11,
               &WPP_0fb1d46681b331a7af1167046103ae69_Traceguids,param_1);
      return 0xc0000225;
    }
    if (param_2 == 3) {
      if (param_3 == '\0') {
        uVar3 = *(undefined4 *)(lVar1 + 0x48);
        uVar4 = *(undefined4 *)(lVar1 + 0x4c);
        uVar5 = *(undefined4 *)(lVar1 + 0x50);
        uVar6 = *(undefined4 *)(lVar1 + 0x54);
      }
      else {
        uVar3 = *(undefined4 *)(lVar1 + 0x80);
        uVar4 = *(undefined4 *)(lVar1 + 0x84);
        uVar5 = *(undefined4 *)(lVar1 + 0x88);
        uVar6 = *(undefined4 *)(lVar1 + 0x8c);
      }
    }
    else if (param_2 == 1) {
      if (param_3 == '\0') {
        uVar3 = *(undefined4 *)(lVar1 + 0x28);
        uVar4 = *(undefined4 *)(lVar1 + 0x2c);
        uVar5 = *(undefined4 *)(lVar1 + 0x30);
        uVar6 = *(undefined4 *)(lVar1 + 0x34);
      }
      else {
        uVar3 = *(undefined4 *)(lVar1 + 0x60);
        uVar4 = *(undefined4 *)(lVar1 + 100);
        uVar5 = *(undefined4 *)(lVar1 + 0x68);
        uVar6 = *(undefined4 *)(lVar1 + 0x6c);
      }
    }
    else {
      if (param_2 != 2) goto LAB_14001f77b;
      if (param_3 == '\0') {
        uVar3 = *(undefined4 *)(lVar1 + 0x38);
        uVar4 = *(undefined4 *)(lVar1 + 0x3c);
        uVar5 = *(undefined4 *)(lVar1 + 0x40);
        uVar6 = *(undefined4 *)(lVar1 + 0x44);
      }
      else {
        uVar3 = *(undefined4 *)(lVar1 + 0x70);
        uVar4 = *(undefined4 *)(lVar1 + 0x74);
        uVar5 = *(undefined4 *)(lVar1 + 0x78);
        uVar6 = *(undefined4 *)(lVar1 + 0x7c);
      }
    }
    *(undefined4 *)param_4 = uVar3;
    *(undefined4 *)((longlong)param_4 + 4) = uVar4;
    *(undefined4 *)(param_4 + 1) = uVar5;
    *(undefined4 *)((longlong)param_4 + 0xc) = uVar6;
  }
  return uVar2;
}



===== MupRemoveFileContext @ 14001f830 =====

void MupRemoveFileContext(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = FsRtlRemovePerFileObjectContext(*(undefined8 *)(param_1 + 0x90),MupDeviceObject,0);
  lVar2 = lVar1 + -8;
  if (lVar1 == 0) {
    lVar2 = 0;
  }
  if (lVar2 != param_1) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x103,2,param_1,lVar2,0);
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
              &WPP_4224fc6462d239efe09d540716e6c5d6_Traceguids,*(undefined8 *)(param_1 + 0x90),
              (char)param_1);
  }
  return;
}



===== MupiLookupKnownPrefixEntry @ 14001f8e0 =====

longlong MupiLookupKnownPrefixEntry(undefined8 param_1,wchar_t *param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = RtlFindUnicodePrefix(param_1,param_2,1);
  lVar2 = lVar1 + -0x10;
  if (lVar1 == 0) {
    lVar2 = 0;
  }
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_Zq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x19,
              &WPP_ea0133f9b224365980f4880a222ef939_Traceguids,param_2,(char)lVar2);
  }
  return lVar2;
}



===== MupSaveUnstrippedFileName @ 14001f960 =====

void MupSaveUnstrippedFileName(longlong param_1,ushort *param_2,char param_3)

{
  ushort uVar1;
  ushort *puVar2;
  ushort *puVar3;
  
  uVar1 = *param_2;
  if (uVar1 != 0) {
    puVar3 = (ushort *)(param_1 + 0x28);
    if (param_3 == '\0') {
      *puVar3 = uVar1;
    }
    else {
      puVar2 = (ushort *)(param_1 + 0x60);
      *puVar2 = uVar1;
      *(undefined8 *)puVar3 = *(undefined8 *)puVar2;
      *(undefined8 *)(param_1 + 0x30) = *(undefined8 *)(param_1 + 0x68);
      puVar3 = puVar2;
    }
    memmove(*(void **)(puVar3 + 4),*(void **)(param_2 + 4),(ulonglong)uVar1);
  }
  return;
}



===== MupiAcquireSurrogateListLockShared @ 14001f9b0 =====

void MupiAcquireSurrogateListLockShared(void)

{
  KeEnterCriticalRegion();
  ExAcquireResourceSharedLite(&DAT_14000b5e0,1);
  return;
}



===== MupiGetProviderFastIoDispatchTable @ 14001f9f0 =====

undefined8 MupiGetProviderFastIoDispatchTable(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = MupGetUncProviderDeviceObjectFromFileObject(param_1);
  if (lVar2 == 0) {
    uVar3 = 0;
  }
  else {
    lVar1 = *(longlong *)(lVar2 + 8);
    *param_2 = lVar2;
    uVar3 = *(undefined8 *)(lVar1 + 0x50);
  }
  return uVar3;
}



===== MupFastIoRead @ 14001fa20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong MupFastIoRead(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined1 param_4,
                       undefined4 param_5,undefined8 param_6,undefined8 param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  
  uVar2 = MupGetUncProviderDeviceObjectFromFileObject(param_1);
  if ((((uVar2 == 0) ||
       (puVar1 = *(uint **)(*(longlong *)(uVar2 + 8) + 0x50), puVar1 == (uint *)0x0)) ||
      (*puVar1 < 0x18)) || (*(code **)(puVar1 + 4) == (code *)0x0)) {
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  else {
    uVar2 = (**(code **)(puVar1 + 4))(param_1,param_2,param_3,param_4,param_5,param_6,param_7,uVar2)
    ;
  }
  return uVar2;
}



===== MupFastIoCheckIfPossible @ 14001fad0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong MupFastIoCheckIfPossible
                    (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined1 param_4,
                    undefined4 param_5,undefined1 param_6,undefined8 param_7)

{
  uint *puVar1;
  ulonglong uVar2;
  
  uVar2 = MupGetUncProviderDeviceObjectFromFileObject(param_1);
  if ((((uVar2 == 0) ||
       (puVar1 = *(uint **)(*(longlong *)(uVar2 + 8) + 0x50), puVar1 == (uint *)0x0)) ||
      (*puVar1 < 0x10)) || (*(code **)(puVar1 + 2) == (code *)0x0)) {
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  else {
    uVar2 = (**(code **)(puVar1 + 2))(param_1,param_2,param_3,param_4,param_5,param_6,param_7,uVar2)
    ;
  }
  return uVar2;
}



===== MupFastIoDeviceControl @ 14001fb80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong MupFastIoDeviceControl
                    (undefined8 param_1,undefined1 param_2,undefined8 param_3,undefined4 param_4,
                    undefined8 param_5,undefined4 param_6,undefined4 param_7,undefined8 param_8)

{
  uint *puVar1;
  ulonglong uVar2;
  
  uVar2 = MupGetUncProviderDeviceObjectFromFileObject(param_1);
  if ((((uVar2 == 0) ||
       (puVar1 = *(uint **)(*(longlong *)(uVar2 + 8) + 0x50), puVar1 == (uint *)0x0)) ||
      (*puVar1 < 0x58)) || (*(code **)(puVar1 + 0x14) == (code *)0x0)) {
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  else {
    uVar2 = (**(code **)(puVar1 + 0x14))
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,uVar2);
  }
  return uVar2;
}



===== RfsServerNameCleanup @ 14001fc30 =====

void RfsServerNameCleanup(int *param_1)

{
  undefined8 local_18;
  undefined8 local_10;
  
  if (*param_1 == 1) {
    local_10 = *(undefined8 *)(param_1 + 2);
    local_18 = 0;
    RtlFreeUnicodeString(&local_18);
  }
  else if (*param_1 == 2) {
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 2),0x5266534c);
    return;
  }
  return;
}



===== MupiGetNextUncHardeningConfigurationEntry @ 14001fc90 =====

longlong MupiGetNextUncHardeningConfigurationEntry(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = 0;
  if ((param_2 != 0) && (*(longlong *)(param_2 + 8) != param_1)) {
    lVar1 = *(longlong *)(param_2 + 8) + -8;
  }
  return lVar1;
}



===== MupiTryStartUncHardeningRegistryWatcher @ 14001fcb0 =====

byte MupiTryStartUncHardeningRegistryWatcher(void)

{
  byte extraout_var;
  
  RtlRunOnceExecuteOnce
            (&DAT_14000b268,MupAttemptToLoadRegistryConfigurationRunOnce,&DAT_14000b260,0);
  return extraout_var >> 7 ^ 1;
}



===== RfsServerNameEqualEx @ 14001fcf0 =====

ulonglong RfsServerNameEqualEx(uint *param_1,uint *param_2,char param_3)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar1 = *param_1;
  if (uVar1 == *param_2) {
    if (uVar1 == 0) {
      return 1;
    }
    uVar1 = uVar1 - 1;
    if (uVar1 == 0) {
      uVar2 = RfspServerNameEqualDnsName((longlong)param_1,(longlong)param_2,param_3);
      return uVar2;
    }
    if (uVar1 == 1) {
      uVar2 = RfspServerNameEqualSockaddr((longlong)param_1,(longlong)param_2);
      return uVar2;
    }
  }
  return (ulonglong)uVar1 & 0xffffffffffffff00;
}



===== MupSetInformationFile @ 14001fd30 =====

ulonglong MupSetInformationFile(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong local_res10;
  longlong local_res18 [2];
  
  lVar4 = *(longlong *)(param_2 + 0xb8);
  local_res10 = 0;
  lVar1 = *(longlong *)(lVar4 + 0x30);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xc,
              &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,lVar1,(char)param_2);
  }
  lVar3 = MupFindFileContext(lVar1);
  if (lVar3 == 0) {
    if (*(undefined **)(lVar1 + 0x18) != &g_MupAdvancedFcbHeader) {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x103,1,param_2,lVar1,param_1);
    }
LAB_14001fe01:
    uVar5 = 0xc0000010;
  }
  else if (((*(int *)(lVar4 + 0x10) - 10U < 2) || (*(int *)(lVar4 + 0x10) == 0x1f)) &&
          (lVar4 = *(longlong *)(lVar4 + 0x18), lVar4 != 0)) {
    lVar6 = MupFindFileContext(lVar4);
    if (lVar6 == 0) {
      if (*(undefined **)(lVar4 + 0x18) != &g_MupAdvancedFcbHeader) {
                    /* WARNING: Subroutine does not return */
        KeBugCheckEx(0x103,1,param_2,lVar4,param_1);
      }
      goto LAB_14001fe01;
    }
    if (((*(longlong *)(lVar3 + 0xa8) == 0) || (*(longlong *)(lVar6 + 0xa8) == 0)) ||
       (*(longlong *)(*(longlong *)(lVar3 + 0xa8) + 0xa8) ==
        *(longlong *)(*(longlong *)(lVar6 + 0xa8) + 0xa8))) goto LAB_14001fd96;
    uVar5 = 0xc00000d4;
  }
  else {
LAB_14001fd96:
    lVar4 = MupGetSiloFromFileObject();
    uVar2 = MupGetContainerContextFromSilo(lVar4,&local_res10);
    local_res18[0] = 0;
    uVar5 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      uVar2 = MupCreateIrpContext(lVar3,local_res10,param_2,'\0',local_res18);
      uVar5 = (ulonglong)uVar2;
      if (uVar2 == 0) {
        uVar5 = MupStateMachine(local_res18[0]);
        uVar5 = uVar5 & 0xffffffff;
        goto LAB_14001fe1a;
      }
    }
  }
  *(int *)(param_2 + 0x30) = (int)uVar5;
  IofCompleteRequest(param_2,2);
LAB_14001fe1a:
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xd,
               &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,lVar1,(char)param_2,(char)uVar5);
  }
  return uVar5;
}



===== MupiGetFirstUncHardeningConfigurationEntry @ 14001ff48 =====

longlong MupiGetFirstUncHardeningConfigurationEntry(longlong *param_1)

{
  if ((longlong *)*param_1 == param_1) {
    return 0;
  }
  return (longlong)((longlong *)*param_1 + -1);
}



===== MupFastIoQueryStandardInfo @ 14001ff60 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
MupFastIoQueryStandardInfo
          (undefined8 param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  undefined1 uVar2;
  longlong lVar3;
  
  lVar3 = MupGetUncProviderDeviceObjectFromFileObject(param_1);
  uVar2 = 0;
  if ((((lVar3 != 0) &&
       (puVar1 = *(uint **)(*(longlong *)(lVar3 + 8) + 0x50), puVar1 != (uint *)0x0)) &&
      (0x2f < *puVar1)) && (*(code **)(puVar1 + 10) != (code *)0x0)) {
    uVar2 = (**(code **)(puVar1 + 10))(param_1,param_2,param_3,param_4,lVar3);
  }
  return uVar2;
}



===== MupiBypassMupAndCallUncProviderDirectly @ 14001ffe8 =====

undefined4 MupiBypassMupAndCallUncProviderDirectly(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  uVar2 = IoGetAttachedDevice(*(undefined8 *)(param_1 + 0xa8));
  uVar1 = IofCallDriver(uVar2,param_2);
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_qqD(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,
               &WPP_4d0a826c214c3a52d4131c62238d98a9_Traceguids,param_2,(char)param_1,(char)uVar1);
  }
  return uVar1;
}



===== MupFastIoLock @ 140020090 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
MupFastIoLock(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
             undefined4 param_5,undefined1 param_6,undefined1 param_7,undefined8 param_8)

{
  uint *puVar1;
  undefined1 uVar2;
  longlong lVar3;
  
  lVar3 = MupGetUncProviderDeviceObjectFromFileObject(param_1);
  uVar2 = 0;
  if ((((lVar3 != 0) &&
       (puVar1 = *(uint **)(*(longlong *)(lVar3 + 8) + 0x50), puVar1 != (uint *)0x0)) &&
      (0x37 < *puVar1)) && (*(code **)(puVar1 + 0xc) != (code *)0x0)) {
    uVar2 = (**(code **)(puVar1 + 0xc))
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,lVar3);
  }
  return uVar2;
}



===== MupFastIoQueryBasicInfo @ 140020150 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
MupFastIoQueryBasicInfo(undefined8 param_1,undefined1 param_2,undefined8 param_3,undefined8 param_4)

{
  uint *puVar1;
  undefined1 uVar2;
  longlong lVar3;
  
  lVar3 = MupGetUncProviderDeviceObjectFromFileObject(param_1);
  uVar2 = 0;
  if ((((lVar3 != 0) &&
       (puVar1 = *(uint **)(*(longlong *)(lVar3 + 8) + 0x50), puVar1 != (uint *)0x0)) &&
      (0x27 < *puVar1)) && (*(code **)(puVar1 + 8) != (code *)0x0)) {
    uVar2 = (**(code **)(puVar1 + 8))(param_1,param_2,param_3,param_4,lVar3);
  }
  return uVar2;
}



===== MupPreReleaseForSectionSynchronisation @ 1400201e0 =====

undefined8 MupPreReleaseForSectionSynchronisation(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = MupFindFileContext(*(undefined8 *)(param_1 + 0x10));
  uVar3 = 0;
  if (lVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x103,1,0,*(undefined8 *)(param_1 + 0x10),0);
  }
  if (*(void **)(lVar2 + 0xe8) != SystemReserved1[0xf]) {
                    /* WARNING: Subroutine does not return */
    KeBugCheckEx(0x103,0x100,*(void **)(lVar2 + 0xe8),*(undefined8 *)(param_1 + 0x10),
                 *(undefined8 *)(lVar2 + 0xe0));
  }
  lVar1 = *(longlong *)(lVar2 + 0xe0);
  *(undefined8 *)(lVar2 + 0xe8) = 0;
  *(undefined8 *)(lVar2 + 0xe0) = 0;
  if (lVar1 == 0) {
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18);
    if ((lVar2 != 0) && (*(longlong *)(lVar2 + 8) != 0)) {
      IoSetTopLevelIrp(0);
      ExReleaseResourceLite(*(undefined8 *)(lVar2 + 8));
      uVar3 = 0x126;
    }
  }
  else {
    IoSetTopLevelIrp(0);
    *(longlong *)(param_1 + 8) = lVar1;
  }
  return uVar3;
}



===== MupFastIoQueryNetworkOpenInfo @ 1400202e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
MupFastIoQueryNetworkOpenInfo
          (undefined8 param_1,undefined1 param_2,undefined8 param_3,undefined4 *param_4)

{
  uint *puVar1;
  undefined1 uVar2;
  longlong lVar3;
  
  lVar3 = MupGetUncProviderDeviceObjectFromFileObject(param_1);
  uVar2 = 0;
  if ((((lVar3 == 0) ||
       (puVar1 = *(uint **)(*(longlong *)(lVar3 + 8) + 0x50), puVar1 == (uint *)0x0)) ||
      (*puVar1 < 0x78)) || (*(code **)(puVar1 + 0x1c) == (code *)0x0)) {
    *param_4 = 0xc00000bb;
  }
  else {
    uVar2 = (**(code **)(puVar1 + 0x1c))(param_1,param_2,param_3,param_4,lVar3);
  }
  return uVar2;
}



===== MupFastIoQueryOpen @ 140020370 =====

undefined1 MupFastIoQueryOpen(void)

{
  return 0;
}



===== MupPreReleaseForCcFlush @ 140020380 =====

undefined8 MupPreReleaseForCcFlush(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = MupGetUncProviderDeviceObjectFromFileObject(*(undefined8 *)(param_1 + 0x10));
  uVar2 = 0;
  if (lVar1 == 0) {
    uVar2 = 0xc0000010;
  }
  else {
    *(longlong *)(param_1 + 8) = lVar1;
  }
  return uVar2;
}



===== MupFastIoUnlockSingle @ 1400203c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
MupFastIoUnlockSingle
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined4 param_5,undefined8 param_6)

{
  uint *puVar1;
  undefined1 uVar2;
  longlong lVar3;
  
  lVar3 = MupGetUncProviderDeviceObjectFromFileObject(param_1);
  uVar2 = 0;
  if ((((lVar3 != 0) &&
       (puVar1 = *(uint **)(*(longlong *)(lVar3 + 8) + 0x50), puVar1 != (uint *)0x0)) &&
      (0x3f < *puVar1)) && (*(code **)(puVar1 + 0xe) != (code *)0x0)) {
    uVar2 = (**(code **)(puVar1 + 0xe))(param_1,param_2,param_3,param_4,param_5,param_6,lVar3);
  }
  return uVar2;
}



===== MupPreAcquireForCcFlush @ 140020470 =====

undefined8 MupPreAcquireForCcFlush(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = MupGetUncProviderDeviceObjectFromFileObject(*(undefined8 *)(param_1 + 0x10));
  uVar2 = 0;
  if (lVar1 == 0) {
    uVar2 = 0xc0000010;
  }
  else {
    *(longlong *)(param_1 + 8) = lVar1;
  }
  return uVar2;
}



===== MupPreAcquireForSectionSynchronisation @ 1400204b0 =====

undefined8 MupPreAcquireForSectionSynchronisation(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = MupGetUncProviderDeviceObjectFromFileObject(*(undefined8 *)(param_1 + 0x10));
  uVar2 = 0;
  *param_2 = lVar1;
  if (lVar1 == 0) {
    lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x18);
    if ((lVar1 != 0) && (*(longlong *)(lVar1 + 8) != 0)) {
      IoSetTopLevelIrp(1);
      ExAcquireResourceExclusiveLite(*(undefined8 *)(lVar1 + 8),1);
      uVar2 = 0x126;
      MupPostAcquireForSectionSynchronisation(param_1,0x126,*param_2);
    }
  }
  else {
    IoSetTopLevelIrp(1);
    *(longlong *)(param_1 + 8) = lVar1;
  }
  return uVar2;
}



===== MupiGetProviderIdFromName @ 140020560 =====

undefined8 MupiGetProviderIdFromName(wchar_t *param_1,undefined4 *param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (param_2 == (undefined4 *)0x0) {
    uVar2 = 0xc000000d;
  }
  else {
    puVar1 = MupAcquireUncProviderByName(param_1);
    if (puVar1 == (undefined8 *)0x0) {
      uVar2 = 0xc0000034;
    }
    else {
      *param_2 = *(undefined4 *)(puVar1 + 7);
      MupReleaseUncProvider((longlong)puVar1);
    }
  }
  return uVar2;
}



===== MupiLoadUncHardeningDefaultsToList @ 1400205b0 =====

ulonglong MupiLoadUncHardeningDefaultsToList(longlong param_1)

{
  short *psVar1;
  longlong *plVar2;
  code *pcVar3;
  short sVar4;
  char cVar5;
  short *psVar6;
  ulonglong uVar7;
  longlong *plVar8;
  longlong lVar9;
  char *pcVar10;
  longlong local_res10;
  undefined8 local_38;
  short *psStack_30;
  undefined8 local_28;
  short *psStack_20;
  
  pcVar10 = "\x01\x01";
  local_res10 = 0;
  do {
    psVar1 = *(short **)(pcVar10 + -0x10);
    if (psVar1 == (short *)0x0) {
      return 0;
    }
    local_38 = 0;
    psStack_30 = (short *)0x0;
    lVar9 = 0x7fff;
    local_28 = 0;
    psStack_20 = (short *)0x0;
    psVar6 = psVar1;
    do {
      if (*psVar6 == 0) break;
      psVar6 = psVar6 + 1;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    if (lVar9 != 0) {
      sVar4 = (0x7fff - (short)lVar9) * 2;
      local_28 = (ulonglong)CONCAT22(sVar4 + 2,sVar4);
      psStack_20 = psVar1;
    }
    if (-1 < (int)-(uint)(lVar9 != 0)) {
      return 0xc00000e5;
    }
    cVar5 = RtlEqualUnicodeString
                      (&local_28,&MupiUncHardeningWildcard,
                       CONCAT71((int7)((ulonglong)psVar1 >> 8),1));
    if (cVar5 != '\0') {
      local_28 = local_28 & 0xffffffffffff0000;
    }
    psVar1 = *(short **)(pcVar10 + -8);
    local_38 = 0;
    psStack_30 = (short *)0x0;
    if (psVar1 != (short *)0x0) {
      lVar9 = 0x7fff;
      psVar6 = psVar1;
      do {
        if (*psVar6 == 0) {
          sVar4 = (0x7fff - (short)lVar9) * 2;
          local_38 = (ulonglong)CONCAT22(sVar4 + 2,sVar4);
          psStack_30 = psVar1;
          break;
        }
        psVar6 = psVar6 + 1;
        lVar9 = lVar9 + -1;
      } while (lVar9 != 0);
    }
    cVar5 = RtlEqualUnicodeString(&local_38,&MupiUncHardeningWildcard,1);
    if (cVar5 != '\0') {
      local_38 = local_38 & 0xffffffffffff0000;
    }
    uVar7 = MupiCreateUncHardeningConfigurationEntry
                      ((short *)&local_28,(ushort *)&local_38,&local_res10);
    if ((int)uVar7 < 0) {
      return uVar7;
    }
    if (*pcVar10 != '\0') {
      *(undefined4 *)(local_res10 + 0x50) = 1;
    }
    if (pcVar10[1] != '\0') {
      *(undefined4 *)(local_res10 + 0x54) = 1;
    }
    if (pcVar10[2] != '\0') {
      *(undefined4 *)(local_res10 + 0x58) = 1;
    }
    plVar2 = *(longlong **)(param_1 + 8);
    plVar8 = (longlong *)(local_res10 + 8);
    if (*plVar2 != param_1) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      return 0xc00000e5;
    }
    *plVar8 = param_1;
    pcVar10 = pcVar10 + 0x18;
    *(longlong **)(local_res10 + 0x10) = plVar2;
    *plVar2 = (longlong)plVar8;
    *(longlong **)(param_1 + 8) = plVar8;
  } while( true );
}



===== MupPostAcquireForSectionSynchronisation @ 140020760 =====

void MupPostAcquireForSectionSynchronisation(longlong param_1,int param_2,undefined8 param_3)

{
  longlong lVar1;
  
  if (-1 < param_2) {
    lVar1 = MupFindFileContext(*(undefined8 *)(param_1 + 0x10));
    if (lVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      KeBugCheckEx(0x103,1,0,*(undefined8 *)(param_1 + 0x10),param_3);
    }
    *(undefined8 *)(lVar1 + 0xe0) = param_3;
    *(void **)(lVar1 + 0xe8) = SystemReserved1[0xf];
  }
  return;
}



===== MupFastIoWrite @ 1400207d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
MupFastIoWrite(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined1 param_4,
              undefined4 param_5,undefined8 param_6,undefined8 param_7)

{
  uint *puVar1;
  undefined1 uVar2;
  longlong lVar3;
  
  lVar3 = MupGetUncProviderDeviceObjectFromFileObject(param_1);
  uVar2 = 0;
  if ((((lVar3 != 0) &&
       (puVar1 = *(uint **)(*(longlong *)(lVar3 + 8) + 0x50), puVar1 != (uint *)0x0)) &&
      (0x1f < *puVar1)) && (*(code **)(puVar1 + 6) != (code *)0x0)) {
    uVar2 = (**(code **)(puVar1 + 6))
                      (param_1,param_2,param_3,CONCAT71((int7)((ulonglong)puVar1 >> 8),param_4),
                       param_5,param_6,param_7,lVar3);
  }
  return uVar2;
}



===== WppLoadTracingSupport @ 140020888 =====

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



===== DriverEntry @ 1400209cc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(longlong param_1,ushort *param_2)

{
  undefined1 uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  wchar_t *pwVar8;
  ulonglong uVar9;
  longlong *plVar10;
  longlong lVar11;
  ushort uVar12;
  longlong *plVar13;
  undefined *puVar14;
  ulonglong uVar15;
  undefined8 *puVar16;
  uint local_res10;
  int local_res20;
  undefined4 uVar17;
  uint in_stack_ffffffffffffff80;
  longlong *plVar18;
  longlong local_68 [6];
  
  local_68[3] = 0;
  local_68[4] = 0;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  wil_InitializeFeatureStaging();
  RtlInitUnicodeString(&g_MupServicesRegistryKey,0);
  RtlInitUnicodeString(local_68 + 1,0);
  _DAT_14000b868 = 1;
  iVar5 = 0x103;
  MupDeviceObject = 0;
  local_res10 = 0x103;
  DAT_14000b848 = &WPP_ThisDir_CTLGUID_MupLog;
  iVar6 = 0x103;
  local_res20 = 0x103;
  DAT_14000b850 = &DAT_14000b880;
  iVar7 = 0x103;
  _WPP_MAIN_CB = 0;
  _DAT_14000b888 = &WPP_ThisDir_CTLGUID_RFSMon;
  _DAT_14000b860 = 0;
  _DAT_14000b880 = 0;
  _DAT_14000b890 = 0;
  _DAT_14000b8a0 = 0;
  _DAT_14000b8a8 = 1;
  WppLoadTracingSupport();
  _DAT_14000b860 = 0;
  WppInitKm();
  if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x4000000) != 0)) {
    WPP_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),10,
            &WPP_28988ea4fccc34e34a882626d4fa5735_Traceguids);
  }
  iVar3 = McGenEventRegister_EtwRegister();
  if (((iVar3 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
     ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x2000000) != 0)) {
    WPP_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0xb,
             &WPP_28988ea4fccc34e34a882626d4fa5735_Traceguids,iVar3);
  }
  MupRegisterTelemetryProvider();
  uVar12 = *param_2;
  if (((uVar12 & 1) == 0) && (1 < uVar12)) {
    if (*(short *)(*(longlong *)(param_2 + 4) + -2 + (ulonglong)(uVar12 >> 1) * 2) == 0x5c) {
      uVar12 = uVar12 - 2;
      *param_2 = uVar12;
    }
    uVar4 = uVar12 + 0x18;
    if (uVar4 < 0x10000) {
      pwVar8 = (wchar_t *)ExAllocatePool2(0x42,uVar4,0x2070754d);
      if (pwVar8 == (wchar_t *)0x0) {
        uVar15 = 0xc000009a;
      }
      else {
        uVar17 = 1;
        RtlStringCbPrintfW(pwVar8,(ulonglong)uVar4,L"%wZ%s",param_2);
        RtlInitUnicodeString(&g_MupParametersRegistryKey,pwVar8);
        _DAT_14000b928 = DAT_14000b8c8;
        _g_MupServicesRegistryKey = *param_2;
        _DAT_14000b922 = _g_MupServicesRegistryKey;
        RtlInitUnicodeString(local_68 + 3,L"\\Device\\Mup");
        plVar18 = local_68;
        uVar4 = IoCreateDevice(param_1,0,local_68 + 3,0x14,CONCAT44(uVar17,0x20010),
                               in_stack_ffffffffffffff80 & 0xffffff00,plVar18);
        uVar15 = (ulonglong)uVar4;
        if (-1 < (int)uVar4) {
          MupDeviceObject = local_68[0];
          RtlInitUnicodeString(local_68 + 1,L"\\??\\UNC");
          IoDeleteSymbolicLink(local_68 + 1);
          plVar13 = local_68 + 3;
          plVar10 = local_68 + 1;
          uVar4 = IoCreateSymbolicLink();
          uVar15 = (ulonglong)uVar4;
          if (-1 < (int)uVar4) {
            MupInitRegistryParametersKeyModule();
            local_res20 = 0;
            MupInitRegistryPoliciesKeyModule();
            uVar15 = MupInitUncProviderModule(plVar10,plVar13);
            iVar5 = (int)uVar15;
            if (iVar5 == 0) {
              uVar15 = MupInitPrefixCache();
              iVar6 = (int)uVar15;
              if ((iVar6 == 0) && (uVar15 = MupInitFileIo(), (int)uVar15 == 0)) {
                uVar15 = MupInitSurrogateProviderModule();
                iVar7 = (int)uVar15;
                if (iVar7 == 0) {
                  uVar9 = MupInitIrpContextList();
                  uVar15 = uVar9 & 0xffffffff;
                  if ((int)uVar9 == 0) {
                    uVar9 = MupInitReserveIrpContext();
                    uVar15 = uVar9 & 0xffffffff;
                    if ((int)uVar9 == 0) {
                      uVar4 = MupRegisterFileSystemFilterCallbacks(param_1);
                      uVar15 = (ulonglong)uVar4;
                      if (uVar4 == 0) {
                        MupInitializeUncHardeningModule();
                        uVar4 = 0;
                        local_res10 = MupInitializeContainerModule(param_1);
                        iVar3 = 0;
                        if (local_res10 == 0) {
                          sVar2 = KeQueryHighestNodeNumber();
                          MupiIrpContextLookasideListsCeLength = sVar2 + 1;
                          MupiIrpContextLookasideLists =
                               ExAllocatePool2(0x4a,(ulonglong)MupiIrpContextLookasideListsCeLength
                                                    << 7,0x2070754d);
                          if (MupiIrpContextLookasideLists != 0) {
                            if (MupiIrpContextLookasideListsCeLength != 0) {
                              do {
                                plVar18 = (longlong *)((ulonglong)plVar18 & 0xffffffffffff0000);
                                ExInitializeNPagedLookasideList
                                          ((longlong)iVar3 * 0x80 + MupiIrpContextLookasideLists,0,0
                                           ,0x200,0x118,0x6349754d,plVar18);
                                iVar3 = iVar3 + 1;
                              } while (iVar3 < (int)(uint)MupiIrpContextLookasideListsCeLength);
                            }
                            _MupiAdvancedFcbHeaderFastMutex = 1;
                            _DAT_14000b8e8 = 0;
                            _DAT_14000b8f0 = 0;
                            KeInitializeEvent(&DAT_14000b8f8,1,0);
                            DAT_14000b944 = DAT_14000b944 | 0x40;
                            DAT_14000b946 = DAT_14000b946 | 2;
                            DAT_14000b947 = DAT_14000b947 & 0xf | 0x50;
                            _DAT_14000b9a8 = 0;
                            _DAT_14000b980 = &DAT_14000b978;
                            _DAT_14000b978 = &DAT_14000b978;
                            _DAT_14000b970 = &MupiAdvancedFcbHeaderFastMutex;
                            _DAT_14000b988 = 0;
                            uRam000000014000b990 = 0;
                            _DAT_14000b9b0 = 0;
                            _DAT_14000b998 = 0;
                            uRam000000014000b9a0 = 0;
                            MupRegisterProviderKeyChangeNotification();
                            MupRegisterProviderOrderKeyChangeNotification();
                            MupRegisterPrefixCacheKeyChangeNotification();
                            puVar16 = (undefined8 *)(param_1 + 0x70);
                            for (lVar11 = 0x1c; lVar11 != 0; lVar11 = lVar11 + -1) {
                              *puVar16 = MupFsdIrpPassThrough;
                              puVar16 = puVar16 + 1;
                            }
                            *(code **)(param_1 + 0x70) = MupCreate;
                            *(code **)(param_1 + 0x78) = MupCreate;
                            *(code **)(param_1 + 0x108) = MupCreate;
                            *(code **)(param_1 + 0xd8) = MupFsControl;
                            *(code **)(param_1 + 0x100) = MupCleanup;
                            *(code **)(param_1 + 0x80) = MupClose;
                            *(code **)(param_1 + 0xa0) = MupSetInformationFile;
                            MupInitFastIo(param_1);
                            uVar1 = MupiGetIrpStackSize();
                            *(undefined1 *)(MupDeviceObject + 0x4c) = uVar1;
                            IoRegisterFileSystem();
                            MupiInitSuccessful = 1;
                            *(uint *)(MupDeviceObject + 0x30) =
                                 *(uint *)(MupDeviceObject + 0x30) & 0xffffff7f | 0x40000;
                            return 0;
                          }
                          uVar15 = 0xc000009a;
                          MupiIrpContextLookasideLists = 0;
                        }
                        else {
                          uVar15 = (ulonglong)local_res10;
                        }
                        goto LAB_140020ba4;
                      }
                    }
                  }
                }
                else {
                  uVar15 = uVar15 & 0xffffffff;
                }
                uVar4 = local_res10;
              }
              else {
                uVar15 = uVar15 & 0xffffffff;
                uVar4 = 0x103;
              }
            }
            else {
              uVar15 = uVar15 & 0xffffffff;
              uVar4 = 0x103;
            }
            goto LAB_140020ba4;
          }
          RtlInitUnicodeString(local_68 + 1,0);
        }
      }
      uVar4 = 0x103;
      goto LAB_140020ba4;
    }
  }
  uVar15 = 0xc000000d;
  uVar4 = 0x103;
LAB_140020ba4:
  iVar3 = 0;
  if (MupiIrpContextLookasideLists != 0) {
    if (MupiIrpContextLookasideListsCeLength != 0) {
      do {
        ExDeleteNPagedLookasideList((longlong)iVar3 * 0x80 + MupiIrpContextLookasideLists);
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)(uint)MupiIrpContextLookasideListsCeLength);
    }
    ExFreePoolWithTag(MupiIrpContextLookasideLists,0x2070754d);
    MupiIrpContextLookasideLists = 0;
    MupiIrpContextLookasideListsCeLength = 0;
  }
  if (uVar4 == 0) {
    ExWaitForRundownProtectionRelease(&DAT_14000b270);
    RfsTimerCleanup(0x14000b2b8);
    if (DAT_14000b280 != 0) {
      ZwClose();
    }
    MupiFreeUncHardeningConfigurationEntryList(&DAT_14000b250);
  }
  if (iVar7 == 0) {
    ExDeleteResourceLite(&DAT_14000b5e0);
  }
  if (local_res10 == 0) {
    MupTerminateContainerModule();
  }
  if (iVar6 == 0) {
    if (MupiMupServicesKeyHandleValid != '\0') {
      MupiMupServicesKeyHandleValid = '\0';
      ZwClose(MupiMupServicesKeyHandle);
    }
    KeCancelTimer(&MupiPrefixGarbageCollectionTimer);
    IoFreeWorkItem(pMupiPrefixGarbageCollectionWorkItem);
    pMupiPrefixGarbageCollectionWorkItem = 0;
  }
  if (iVar5 == 0) {
    MupDeInitUncProviderModule();
  }
  if (local_res20 == 0) {
    ExWaitForRundownProtectionRelease(&DAT_14000b388);
    RfsTimerCleanup(0x14000b3d0);
    if (DAT_14000b398 != 0) {
      ZwClose();
      DAT_14000b398 = 0;
    }
    ExWaitForRundownProtectionRelease(&DAT_14000b4a8);
    RfsTimerCleanup(0x14000b4f0);
    if (DAT_14000b4b8 != 0) {
      ZwClose();
      DAT_14000b4b8 = 0;
    }
  }
  if (DAT_14000b8c8 != 0) {
    ExFreePoolWithTag(DAT_14000b8c8,0);
  }
  if (MupDeviceObject != 0) {
    IoDeleteDevice();
  }
  if (local_68[2] != 0) {
    IoDeleteSymbolicLink(local_68 + 1);
  }
  McGenEventUnregister_EtwUnregister();
  MupUnregisterTelemetryProvider();
  if ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) {
    puVar14 = WPP_GLOBAL_Control;
    if (WPPTraceSuite == 4) {
      for (; puVar14 != (undefined *)0x0; puVar14 = *(undefined **)(puVar14 + 0x10)) {
        if (*(longlong *)(puVar14 + 0x38) != 0) {
          (*pfnEtwUnregister)();
          *(undefined8 *)(puVar14 + 0x38) = 0;
        }
      }
    }
    else if (WPPTraceSuite == 2) {
      IoWMIRegistrationControl(WPP_GLOBAL_Control,0x80000002);
    }
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
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
  return uVar15;
}



===== MupiCreateWithRelativePath$fin$0 @ 140021230 =====

void MupiCreateWithRelativePath_fin_0(char param_1,longlong param_2)

{
  if (((*(int *)(param_2 + 0x20) == 0) && (param_1 == '\0')) || (*(longlong *)(param_2 + 0x98) == 0)
     ) {
    **(undefined8 **)(param_2 + 0x90) = *(undefined8 *)(param_2 + 0x98);
  }
  else {
    MupReleaseFileContext(*(longlong *)(param_2 + 0x98));
    **(undefined8 **)(param_2 + 0x90) = 0;
  }
  return;
}



===== MupCreate$fin$0 @ 140021280 =====

void MupCreate_fin_0(char param_1,longlong param_2)

{
  if ((*(int *)(param_2 + 0x30) != 0) || (param_1 != '\0')) {
    if (*(longlong *)(param_2 + 0x90) != 0) {
      MupReleaseFileContext(*(longlong *)(param_2 + 0x90));
    }
    if (*(longlong *)(param_2 + 0x38) != 0) {
      MupReleaseIrpContext(*(longlong *)(param_2 + 0x38));
    }
  }
  return;
}



===== MupiCreateWithAbsolutePath$fin$0 @ 1400212d0 =====

void MupiCreateWithAbsolutePath_fin_0(undefined8 param_1,longlong param_2)

{
  if (*(longlong *)(param_2 + 0x80) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_2 + 0x80),0);
  }
  return;
}



===== entry @ 140023010 =====

void entry(longlong param_1,ushort *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 140023044 =====

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



===== MupInitIrpContextList @ 140023078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 MupInitIrpContextList(void)

{
  _DAT_14000bef8 = &MupIrpContextList;
  _MupIrpContextList = &MupIrpContextList;
  KeInitializeSpinLock(&MupIrpContextListLock);
  return 0;
}



===== MupInitReserveIrpContext @ 1400230b4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 MupInitReserveIrpContext(void)

{
  _DAT_14000bbc0 = 0;
  MupReserveIrpContext = 1;
  KeInitializeEvent(&DAT_14000bba8,1,0);
  return 0;
}



===== wil_InitializeFeatureStaging @ 1400230f0 =====

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



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1400231e0 =====

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


