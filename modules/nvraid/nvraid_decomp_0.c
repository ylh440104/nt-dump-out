
===== NvRaidApiInitializeRaidSystem @ 00011000 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
NvRaidApiInitializeRaidSystem
          (void *param_1,undefined4 param_2,undefined4 *param_3,undefined8 param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  
  memset(param_1,0,0xf0);
  memset(param_1,0,0x88);
  *(undefined8 *)((longlong)param_1 + 0x78) = 0;
  *(undefined8 *)((longlong)param_1 + 0x80) = 0;
  *(void **)((longlong)param_1 + 0x18) = param_1;
  *(undefined1 *)((longlong)param_1 + 8) = 0xff;
  *(undefined4 *)((longlong)param_1 + 4) = 2;
  *(undefined ***)((longlong)param_1 + 0x60) = &PTR_NvRaidVolumeDefaultCleanup_00027978;
  lVar4 = 0x20;
  *(undefined4 *)((longlong)param_1 + 0x68) = 0x20;
  *(undefined4 *)((longlong)param_1 + 0x6c) = 0x20;
  builtin_strncpy((char *)((longlong)param_1 + 0x2c),"NVIDIA  ",8);
  *(undefined4 *)((longlong)param_1 + 0x34) = 0x544f4f52;
  *(undefined4 **)((longlong)param_1 + 0x90) = param_3;
  *(undefined8 *)((longlong)param_1 + 0x98) = param_4;
  *(undefined4 *)((longlong)param_1 + 0x88) = param_2;
  *(undefined8 *)((longlong)param_1 + 0xb0) = 0;
  *(undefined8 *)((longlong)param_1 + 0xa0) = 0;
  *(undefined8 **)((longlong)param_1 + 0xa8) = (undefined8 *)((longlong)param_1 + 0xa0);
  *(undefined8 *)((longlong)param_1 + 0xb8) = 0;
  *(undefined8 *)((longlong)param_1 + 0xc0) = 0;
  *(undefined8 *)((longlong)param_1 + 200) = 0;
  *(undefined8 *)((longlong)param_1 + 0xd0) = 0;
  *(undefined8 *)((longlong)param_1 + 0xd8) = 0;
  if (param_3 != (undefined4 *)0x0) {
    if (gScratchBufCount != 0) {
      uVar1 = (ulonglong)gScratchBufCount;
      do {
        *param_3 = 0x200;
        *(undefined8 *)(param_3 + 2) = *(undefined8 *)((longlong)param_1 + 0xc0);
        *(undefined4 **)((longlong)param_1 + 0xc0) = param_3;
        param_3 = param_3 + 0x80;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
    }
    lVar2 = 8;
    do {
      *param_3 = 0x3b8;
      *(undefined8 *)(param_3 + 2) = *(undefined8 *)((longlong)param_1 + 0xd0);
      *(undefined4 **)((longlong)param_1 + 0xd0) = param_3;
      param_3 = param_3 + 0xee;
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
    lVar2 = 0x10;
    lVar3 = 0x10;
    do {
      *param_3 = 0x88;
      *(undefined8 *)(param_3 + 2) = *(undefined8 *)((longlong)param_1 + 200);
      *(undefined4 **)((longlong)param_1 + 200) = param_3;
      param_3 = param_3 + 0x22;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    lVar3 = 0x20;
    do {
      *param_3 = 0xf0;
      *(undefined8 *)(param_3 + 2) = *(undefined8 *)((longlong)param_1 + 0xb8);
      *(undefined4 **)((longlong)param_1 + 0xb8) = param_3;
      param_3 = param_3 + 0x3c;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    do {
      *param_3 = 0xb8;
      *(undefined8 *)(param_3 + 2) = *(undefined8 *)((longlong)param_1 + 0xd8);
      *(undefined4 **)((longlong)param_1 + 0xd8) = param_3;
      param_3 = param_3 + 0x2e;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    do {
      *param_3 = 0x30;
      *(undefined8 *)(param_3 + 2) = *(undefined8 *)((longlong)param_1 + 0xb0);
      *(undefined4 **)((longlong)param_1 + 0xb0) = param_3;
      param_3 = param_3 + 0xc;
      lVar2 = lVar2 + -1;
    } while (lVar2 != 0);
  }
  DAT_000290c0 = NvRaidPacketSoftwareInterruptRaid;
  _DAT_000290d8 = NvRaidResResourceIsr;
  return 0;
}



===== NvRaidApiUnloadRaidSystem @ 000111fc =====

void NvRaidApiUnloadRaidSystem(void)

{
  NvRaidResResourceCleanup(&DAT_00029990);
  NvRaidResResourceCleanup((longlong *)&DAT_00029998);
  NvRaidResResourceCleanup((longlong *)&DAT_000299a0);
  NvRaidResResourceCleanup((longlong *)&DAT_000299a8);
  NvRaidResResourceCleanup((longlong *)&DAT_000299b0);
  NvRaidResResourceCleanup((longlong *)&DAT_000299b8);
  NvRaidVolumeCleanup((undefined4 *)&RaidSystem);
  return;
}



===== NvRaidApiCreateArray @ 00011258 =====

undefined8
NvRaidApiCreateArray(longlong param_1,int param_2,uint param_3,byte param_4,longlong *param_5)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  int iVar7;
  longlong local_30;
  
  piVar4 = (int *)NvRaidFindRaidLevelMethod(param_2);
  iVar7 = 0;
  if (((piVar4 == (int *)0x0) || (*piVar4 == 0)) || (piVar4 + 1 == (int *)0x0)) {
    uVar6 = 0xc0000002;
  }
  else {
    cVar2 = NvRaidCalculateRequiredVolumes(param_2,param_4);
    if (((cVar2 != '\0') && (param_3 != 0)) && ((param_3 & param_3 - 1) == 0)) {
      NvRaidApiCreateVolume(param_1,&local_30);
      puVar5 = NvRaidResArrayAllocate(param_1);
      if (puVar5 != (undefined4 *)0x0) {
        *(uint *)(local_30 + 4) = *(uint *)(local_30 + 4) & 0xfffffff9 | 0x21;
        *(undefined8 *)(local_30 + 0x20) = 0;
        *(undefined4 *)(local_30 + 0x28) = 0x200;
        *(int **)(local_30 + 0x60) = piVar4 + 6;
        *(int **)(puVar5 + 0x22) = piVar4;
        *(int **)(puVar5 + 0x24) = piVar4;
        NvRaidVolumeBuildPaddedString((char *)(local_30 + 0x2c),"NVIDIA",8);
        NvRaidVolumeBuildPaddedString((char *)(local_30 + 0x34),(char *)(piVar4 + 1),0x10);
        NvRaidVolumeBuildPaddedString((char *)(local_30 + 0x44),"0100",4);
        *(undefined4 **)(local_30 + 0x58) = puVar5;
        *puVar5 = 0x640044;
        puVar5[6] = param_2;
        puVar5[0xe] = param_2;
        NvRaidResArrayGenerateSignature(puVar5 + 1);
        *(char *)((longlong)puVar5 + 0x16) = cVar2;
        puVar5[7] = param_3;
        *(byte *)((longlong)puVar5 + 0x15) = param_4;
        *(byte *)((longlong)puVar5 + 0x17) = param_4;
        puVar5[0xb] = param_4 * param_3;
        puVar5[9] = 0;
        puVar5[0xc] = (uint)param_4 * param_3 * 0x200;
        puVar5[8] = param_3 * 0x200;
        puVar5[10] = param_3 - 1;
        uVar3 = 1;
        if ((param_3 & 1) == 0) {
          do {
            uVar3 = uVar3 * 2;
            iVar7 = iVar7 + 1;
          } while ((param_3 & uVar3) == 0);
          puVar5[9] = iVar7;
        }
        lVar1 = *(longlong *)(local_30 + 0x18);
        *param_5 = local_30;
        NvRaidApiFireEvent(lVar1,4,local_30);
        return 0;
      }
    }
    uVar6 = 0xc000000d;
  }
  return uVar6;
}



===== NvRaidApiGetMetadataForSingleDiskStripe @ 0001140c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
NvRaidApiGetMetadataForSingleDiskStripe
          (longlong param_1,int param_2,uint param_3,byte param_4,longlong param_5,int *param_6)

{
  longlong lVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  uint uVar8;
  int iVar9;
  ulonglong uVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  undefined4 *local_50;
  undefined4 *local_48 [2];
  
  iVar13 = 0;
  local_50 = (undefined4 *)0x0;
  local_48[0] = (undefined4 *)0x0;
  piVar5 = (int *)NvRaidFindRaidLevelMethod(param_2);
  if (((piVar5 == (int *)0x0) || (*piVar5 == 0)) || (piVar5 == (int *)0xfffffffffffffffc)) {
    uVar7 = 0xc0000002;
  }
  else {
    cVar3 = NvRaidCalculateRequiredVolumes(param_2,param_4);
    if (((cVar3 == '\0') || (param_3 == 0)) || ((param_3 & param_3 - 1) != 0)) {
      uVar7 = 0xc000000d;
    }
    else {
      uVar4 = NvRaidApiCreateVolume(param_1,local_48);
      puVar2 = local_48[0];
      puVar11 = (undefined4 *)0x0;
      if (-1 < (int)uVar4) {
        *(undefined1 *)(local_48[0] + 2) = 0;
        uVar4 = NvRaidApiCreateVolume(param_1,&local_50);
        if (((int)uVar4 < 0) ||
           (puVar6 = NvRaidResArrayAllocate(param_1), puVar11 = local_50,
           puVar6 == (undefined4 *)0x0)) {
          puVar11 = local_50;
        }
        else {
          local_50[1] = local_50[1] & 0xfffffffa | 2;
          uVar8 = 1;
          uVar4 = param_3 & 1;
          while (uVar4 == 0) {
            uVar8 = uVar8 * 2;
            iVar13 = iVar13 + 1;
            uVar4 = param_3 & uVar8;
          }
          local_50[10] = 0x200;
          uVar10 = (param_5 - 2U) / (ulonglong)param_3 << ((byte)iVar13 & 0x3f);
          *(int **)(local_50 + 0x18) = piVar5 + 6;
          *(int **)(puVar6 + 0x22) = piVar5;
          *(int **)(puVar6 + 0x24) = piVar5;
          NvRaidVolumeBuildPaddedString((char *)(local_50 + 0xb),"NVIDIA",8);
          NvRaidVolumeBuildPaddedString((char *)(puVar11 + 0xd),(char *)(piVar5 + 1),0x10);
          iVar12 = 4;
          NvRaidVolumeBuildPaddedString((char *)(puVar11 + 0x11),"0100",4);
          *(undefined4 **)(puVar11 + 0x16) = puVar6;
          *(ulonglong *)(puVar6 + 0x12) = uVar10;
          *(ulonglong *)(puVar11 + 8) = uVar10;
          lVar1 = *(longlong *)(puVar11 + 0x16);
          *(ulonglong *)(lVar1 + 0x50) = uVar10;
          iVar9 = (int)uVar10;
          if (0xffffffff < uVar10) {
            iVar9 = iVar12 + -4;
          }
          *(int *)(lVar1 + 0x3c) = iVar9;
          NvRaidVolumeUpdateProductId((longlong)puVar11);
          puVar6[6] = param_2;
          puVar6[0xe] = param_2;
          *puVar6 = 0x640044;
          NvRaidResArrayGenerateSignature(puVar6 + 1);
          *(char *)((longlong)puVar6 + 0x16) = cVar3;
          *(byte *)((longlong)puVar6 + 0x15) = param_4;
          *(byte *)((longlong)puVar6 + 0x17) = param_4;
          puVar6[0xb] = param_4 * param_3;
          puVar6[7] = param_3;
          puVar6[9] = iVar13;
          puVar6[8] = param_3 * 0x200;
          puVar6[0xc] = (uint)param_4 * param_3 * 0x200;
          puVar6[10] = param_3 - 1;
          NvRaidSectorInitializeSector((longlong)puVar11,(longlong)puVar2,param_6);
        }
      }
      if (puVar2 != (undefined4 *)0x0) {
        _DAT_00029078 = _DAT_00029078 + 1;
        *puVar2 = 0x88;
        *(undefined8 *)(puVar2 + 2) = *(undefined8 *)(param_1 + 200);
        *(undefined4 **)(param_1 + 200) = puVar2;
      }
      if (puVar11 != (undefined4 *)0x0) {
        NvRaidVolumeCleanup(puVar11);
        _DAT_00029078 = _DAT_00029078 + 1;
        *puVar11 = 0x88;
        *(undefined8 *)(puVar11 + 2) = *(undefined8 *)(param_1 + 200);
        *(undefined4 **)(param_1 + 200) = puVar11;
      }
      uVar7 = 0;
    }
  }
  return uVar7;
}



===== NvRaidApiMorphArray @ 000116bc =====

undefined8 NvRaidApiMorphArray(longlong param_1,int param_2,byte param_3,longlong param_4)

{
  byte bVar1;
  longlong lVar2;
  int *piVar3;
  ulonglong uVar4;
  undefined **ppuVar5;
  undefined4 uVar6;
  ulonglong uVar7;
  byte bVar8;
  
  if (((param_1 == 0) || ((*(uint *)(param_1 + 4) & 1) != 0)) ||
     (lVar2 = param_1, (*(uint *)(param_1 + 4) >> 8 & 1) != 0)) {
    lVar2 = 0;
  }
  if (lVar2 != 0) {
    piVar3 = (int *)NvRaidFindRaidLevelMethod(param_2);
    if ((piVar3 == (int *)0x0) || (*piVar3 == 0)) {
      return 0xc0000002;
    }
    bVar8 = param_3;
    bVar1 = NvRaidCalculateRequiredVolumes(param_2,param_3);
    if ((uint)bVar1 < *(uint *)(param_1 + 0x78) || (uint)bVar1 == *(uint *)(param_1 + 0x78)) {
      uVar4 = NvRaidVolumeCalculateArrayCapacity(param_1,bVar8,bVar1);
      if ((((byte)*(undefined4 *)(param_1 + 4) & 0x42) != 2) || (*(char *)(param_4 + 0x14) != '\0'))
      {
        return 0x80000011;
      }
      *(undefined1 *)(param_4 + 0x14) = 4;
      lVar2 = *(longlong *)(param_1 + 0x58);
      *(undefined8 *)(lVar2 + 0x58) = 0;
      *(undefined4 *)(lVar2 + 0x34) = 0;
      *(int *)(param_4 + 0x18) = param_2;
      *(byte *)(param_4 + 0x15) = param_3;
      *(uint *)(param_4 + 0x2c) = *(int *)(param_4 + 0x1c) * (uint)param_3;
      if (bVar1 <= *(byte *)(param_4 + 0x16)) {
        bVar1 = *(byte *)(param_4 + 0x16);
      }
      *(byte *)(param_4 + 0x16) = bVar1;
      lVar2 = *(longlong *)(param_1 + 0x58);
      uVar7 = uVar4;
      if (*(ulonglong *)(param_1 + 0x20) < uVar4) {
        uVar7 = *(ulonglong *)(param_1 + 0x20);
      }
      *(ulonglong *)(lVar2 + 0x50) = uVar7;
      uVar6 = (undefined4)uVar7;
      if (0xffffffff < uVar7) {
        uVar6 = 0;
      }
      *(undefined4 *)(lVar2 + 0x3c) = uVar6;
      *(uint *)(param_4 + 0x40) = *(uint *)(param_4 + 0x40) & 0xfffffffb;
      *(int **)(param_4 + 0x88) = piVar3;
      ppuVar5 = &morphApi;
      if (piVar3 == *(int **)(param_4 + 0x90)) {
        ppuVar5 = (undefined **)(piVar3 + 6);
      }
      *(undefined ***)(param_1 + 0x60) = ppuVar5;
      *(ulonglong *)(*(longlong *)(param_1 + 0x58) + 0x48) = uVar4;
      *(ulonglong *)(param_1 + 0x20) = uVar4;
      NvRaidVolumeUpdateProductId(param_1);
      NvRaidJobScheduleRequest(param_1,1,0,0,0,0);
      return 0;
    }
  }
  return 0xc000000d;
}



===== NvRaidApiEnumerateRootVolumes @ 0001183c =====

undefined8 NvRaidApiEnumerateRootVolumes(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  byte bVar2;
  longlong lVar3;
  
  lVar1 = *param_2;
  *param_2 = 0;
  if (lVar1 == 0) {
    bVar2 = 0;
  }
  else {
    bVar2 = *(byte *)(lVar1 + 8);
    if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)bVar2)) {
      lVar3 = 0;
    }
    else {
      lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)bVar2 * 8);
    }
    if (lVar3 != lVar1) {
      return 0xc000000d;
    }
    bVar2 = bVar2 + 1;
  }
  lVar1 = 0;
  for (; (uint)bVar2 < *(uint *)(param_1 + 0x7c); bVar2 = bVar2 + 1) {
    if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)bVar2)) {
      lVar1 = 0;
    }
    else {
      lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)bVar2 * 8);
    }
    if (lVar1 != 0) break;
  }
  *param_2 = lVar1;
  return 0;
}



===== NvRaidApiGetArrayChild @ 000118c4 =====

undefined8 NvRaidApiGetArrayChild(longlong param_1,byte param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((param_1 != -0x78) && ((uint)param_2 < *(uint *)(param_1 + 0x7c))) {
    uVar1 = *(undefined8 *)(*(longlong *)(param_1 + 0x80) + (ulonglong)param_2 * 8);
  }
  return uVar1;
}



===== NvRaidApiCreateVolume @ 000118e4 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint NvRaidApiCreateVolume(longlong param_1,undefined8 *param_2)

{
  void *_Dst;
  
  _DAT_00029078 = _DAT_00029078 + -1;
  _Dst = (void *)NvRaidResResourceAllocate((longlong *)(param_1 + 200),0x88);
  if (_Dst == (void *)0x0) {
    _DAT_00029078 = _DAT_00029078 + 1;
    _Dst = (void *)0x0;
  }
  else {
    memset(_Dst,0,0x88);
    *(undefined8 *)((longlong)_Dst + 0x78) = 0;
    *(undefined8 *)((longlong)_Dst + 0x80) = 0;
    *(undefined ***)((longlong)_Dst + 0x60) = &PTR_NvRaidVolumeDefaultCleanup_00027978;
    *(longlong *)((longlong)_Dst + 0x18) = param_1;
    *(undefined4 *)((longlong)_Dst + 4) = 0x12;
    *(undefined1 *)((longlong)_Dst + 8) = 0xff;
    *(undefined4 *)((longlong)_Dst + 0x68) = 0x20;
    *(undefined4 *)((longlong)_Dst + 0x6c) = 0x20;
  }
  *param_2 = _Dst;
  return ~-(uint)(_Dst != (void *)0x0) & 0xc000009a;
}



===== NvRaidApiDestroyVolume @ 00011988 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 NvRaidApiDestroyVolume(longlong param_1,undefined4 *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar2 = 0xc000000d;
  }
  else if (*(char *)((longlong)param_2 + 10) == '\0') {
    lVar1 = *(longlong *)(param_2 + 0x14);
    *(undefined1 *)((longlong)param_2 + 10) = 1;
    while (lVar1 != 0) {
      NvRaidVolumeDeleteVolumeFromArray(*(undefined4 **)(param_2 + 0x14),(longlong)param_2);
      lVar1 = *(longlong *)(param_2 + 0x14);
    }
    NvRaidVolumeCleanup(param_2);
    NvRaidApiFireEvent(param_1,5,param_2);
    _DAT_00029078 = _DAT_00029078 + 1;
    *param_2 = 0x88;
    *(undefined8 *)(param_2 + 2) = *(undefined8 *)(param_1 + 200);
    *(undefined4 **)(param_1 + 200) = param_2;
    uVar2 = 0;
  }
  else {
    param_2[1] = param_2[1] | 0x80;
    uVar2 = 0x80000011;
  }
  return uVar2;
}



===== NvRaidApiFireEvent @ 00011a18 =====

undefined8 NvRaidApiFireEvent(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if (param_1 == 0) {
    uVar3 = 0xc000000d;
  }
  else {
    lVar1 = *(longlong *)(param_1 + 0x18);
    pcVar2 = *(code **)(lVar1 + 0xe0);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)();
    }
    if ((lVar1 != param_1) &&
       (pcVar2 = *(code **)(*(longlong *)(param_1 + 0x60) + 0x10), pcVar2 != (code *)0x0)) {
      (*pcVar2)(param_1,param_2,param_3);
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== NvRaidExtendValueSet @ 00011a88 =====

undefined8 NvRaidExtendValueSet(int *param_1,uint param_2,undefined8 param_3)

{
  uint uVar1;
  void *_Dst;
  
  if ((uint)param_1[1] <= param_2) {
    uVar1 = (param_2 + 4) * 8;
    _Dst = (void *)ExAllocatePoolWithTag(0,uVar1,0x644e7652);
    memset(_Dst,0,(ulonglong)uVar1);
    if (param_1[1] != 0) {
      memcpy(_Dst,*(void **)(param_1 + 2),(ulonglong)(uint)(param_1[1] << 3));
      ExFreePoolWithTag(*(undefined8 *)(param_1 + 2),0);
    }
    *(void **)(param_1 + 2) = _Dst;
    param_1[1] = param_2 + 4;
  }
  if (*(longlong *)(*(longlong *)(param_1 + 2) + (ulonglong)param_2 * 8) == 0) {
    *param_1 = *param_1 + 1;
    *(undefined8 *)(*(longlong *)(param_1 + 2) + (ulonglong)param_2 * 8) = param_3;
  }
  else {
    param_3 = 0;
  }
  return param_3;
}



===== NvRaidPacketSubmitRequest @ 00011b38 =====

ulonglong NvRaidPacketSubmitRequest(longlong param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  byte bVar7;
  ulonglong uVar8;
  longlong lVar9;
  byte bVar10;
  
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x58);
  uVar4 = NvRaidSyncSpinLockAcquire(0xffffffff);
  lVar2 = *(longlong *)(param_1 + 0x40);
  uVar5 = *(uint *)(lVar2 + 4);
  if ((uVar5 & 1) == 0) {
    if (lVar9 != 0) {
      bVar7 = (byte)(uVar5 >> 1) & 1;
      bVar10 = ((byte)(uVar5 >> 0xf) | (byte)(uVar5 >> 6)) & 1;
      if ((byte)(((byte)(*(uint *)(lVar9 + 0x40) >> 1) & 1 ^ bVar7) &
                ((byte)(uVar5 >> 10) & 1 | bVar10 | bVar7)) == 0) {
        if ((uVar5 >> 1 & 1) == 0) {
          uVar6 = NvRaidScsiConvertToUnitedCDB(param_1);
          if (((int)uVar6 == 0) && ((*(byte *)(param_1 + 0x82) & 2) != 0)) {
            *(uint *)(lVar9 + 0x40) = *(uint *)(lVar9 + 0x40) | 2;
            *(uint *)(lVar2 + 4) = *(uint *)(lVar2 + 4) | 0x200;
            if (bVar10 == 0) {
              NvRaidJobScheduleRequest(*(longlong *)(param_1 + 0x40),8,0,0,0,0);
            }
          }
        }
        else {
          if (*(char *)(lVar9 + 0x14) == '\0') {
            *(undefined1 *)(lVar9 + 0x14) = 3;
            lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x58);
            *(undefined8 *)(lVar3 + 0x58) = 0;
            *(undefined4 *)(lVar3 + 0x34) = 0;
          }
          *(uint *)(lVar9 + 0x40) = *(uint *)(lVar9 + 0x40) & 0xfffffffd;
          *(uint *)(lVar2 + 4) = *(uint *)(lVar2 + 4) | 0x200;
        }
      }
    }
    lVar9 = *(longlong *)(param_1 + 0x40);
    if ((*(uint *)(lVar9 + 4) & 0x200) != 0) {
      *(uint *)(lVar9 + 4) = *(uint *)(lVar9 + 4) & 0xfffffdff;
      if (*(longlong *)(lVar9 + 0x58) != 0) {
        NvRaidResArrayGenerateSignature((uint *)(*(longlong *)(lVar9 + 0x58) + 4));
        NvRaidJobScheduleRequest(lVar9,1,0,1,0,0);
      }
    }
    pcVar1 = (char *)(*(longlong *)(param_1 + 0x40) + 10);
    *pcVar1 = *pcVar1 + '\x01';
    uVar5 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60) + 8))
                      (*(longlong *)(param_1 + 0x40),param_1);
    uVar8 = (ulonglong)uVar5;
    if (uVar5 == 0xc0000010) {
      uVar8 = NvRaidVolumeDefaultSendCommand(*(longlong *)(param_1 + 0x40),param_1);
      uVar8 = uVar8 & 0xffffffff;
    }
    if (((int)uVar8 == 0x103) || ((int)uVar8 == 0)) goto LAB_00011cb2;
  }
  else {
    uVar8 = 0xc00000a3;
    *(undefined4 *)(param_1 + 0x4b) = 0x40202;
  }
  *(int *)(param_1 + 0x50) = (int)uVar8;
  NvRaidPacketCompleteRequest(param_1);
LAB_00011cb2:
  NvRaidSyncSpinLockRelease(uVar4);
  return uVar8;
}



===== NvRaidPacketSubmitSubRequests @ 00011cd8 =====

undefined8 NvRaidPacketSubmitSubRequests(longlong *param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong *plVar3;
  
  plVar3 = (longlong *)*param_1;
  if ((longlong *)*param_1 == (longlong *)0x0) {
    uVar2 = 0xc000000d;
  }
  else {
    do {
      plVar1 = (longlong *)*plVar3;
      NvRaidPacketSubmitRequest((longlong)plVar3);
      plVar3 = plVar1;
    } while (plVar1 != (longlong *)0x0);
    uVar2 = 0x103;
  }
  return uVar2;
}



===== NvRaidPacketSetupSubRequestsDevice @ 00011d08 =====

undefined8 NvRaidPacketSetupSubRequestsDevice(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  for (puVar2 = (undefined8 *)*param_2; puVar2 != (undefined8 *)0x0; puVar2 = (undefined8 *)*puVar2)
  {
    if (puVar2[8] == 0) {
      if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)*(byte *)(puVar2 + 9))) {
        uVar1 = 0;
      }
      else {
        uVar1 = *(undefined8 *)
                 (*(longlong *)(param_1 + 0x80) + (ulonglong)*(byte *)(puVar2 + 9) * 8);
      }
      puVar2[8] = uVar1;
    }
  }
  return 0x103;
}



===== NvRaidPacketCompleteRequest @ 00011d48 =====

undefined8 NvRaidPacketCompleteRequest(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = NvRaidSyncSpinLockAcquire(0xffffffff);
  lVar4 = DAT_00029008;
  if (DAT_00029008 != 0) {
    do {
      if (lVar4 == param_1) break;
      lVar4 = *(longlong *)(lVar4 + 0x10);
    } while (lVar4 != 0);
    if (lVar4 != 0) goto LAB_00011da3;
  }
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined **)(param_1 + 0x18) = PTR_DAT_00029010;
  *(longlong *)PTR_DAT_00029010 = param_1;
  PTR_DAT_00029010 = (undefined *)(param_1 + 0x10);
LAB_00011da3:
  if ((DAT_000290b4 & 1) == 0) {
    uVar2 = DAT_000290b4 | 1;
    while( true ) {
      uVar3 = uVar2;
      LOCK();
      UNLOCK();
      uVar2 = DAT_000290b4 | 1;
      DAT_000290b4 = uVar3;
      if (uVar2 == uVar3) break;
    }
  }
  NvRaidSyncSpinLockRelease(uVar1);
  return 0;
}



===== NvRaidPacketSoftwareInterruptRaid @ 00011dd4 =====

void NvRaidPacketSoftwareInterruptRaid(void)

{
  undefined4 *puVar1;
  longlong lVar2;
  uint uVar3;
  
  uVar3 = NvRaidSyncSpinLockAcquire(0xffffffff);
  while (lVar2 = DAT_00029008, DAT_00029008 != 0) {
    if (*(longlong *)(DAT_00029008 + 0x10) == 0) {
      PTR_DAT_00029010 = *(undefined **)(DAT_00029008 + 0x18);
    }
    else {
      *(undefined **)(*(longlong *)(DAT_00029008 + 0x10) + 0x18) =
           *(undefined **)(DAT_00029008 + 0x18);
    }
    **(undefined8 **)(lVar2 + 0x18) = *(undefined8 *)(lVar2 + 0x10);
    puVar1 = *(undefined4 **)(lVar2 + 0x40);
    *(char *)((longlong)puVar1 + 10) = *(char *)((longlong)puVar1 + 10) + -1;
    if (*(code **)(lVar2 + 0xa0) != (code *)0x0) {
      (**(code **)(lVar2 + 0xa0))(*(undefined8 *)(lVar2 + 0x70),lVar2);
    }
    if ((char)puVar1[1] < '\0') {
      NvRaidApiDestroyVolume(*(longlong *)(puVar1 + 6),puVar1);
    }
    if (((puVar1[1] & 0x400) != 0) && (*(char *)((longlong)puVar1 + 10) == '\0')) {
      NvRaidApiFireEvent((longlong)puVar1,0x83,0);
    }
  }
  NvRaidSyncSpinLockRelease(uVar3);
  return;
}



===== FUN_00011e84 @ 00011e84 =====

void FUN_00011e84(longlong param_1)

{
  if ((char)*(undefined4 *)(*(longlong *)(param_1 + 0x40) + 4) < '\0') {
    *(undefined4 *)(param_1 + 0x50) = 0xc000020f;
    *(undefined4 *)(param_1 + 0x4b) = 0x40202;
    NvRaidPacketCompleteRequest(param_1);
    return;
  }
  NvRaidPacketExecuteStateMachine(*(longlong *)(param_1 + 0x40),param_1);
  return;
}



===== NvRaidPacketScheduleRequest @ 00011eb0 =====

undefined8 NvRaidPacketScheduleRequest(longlong param_1,int param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    FUN_00011e84(param_1);
    uVar1 = 0;
  }
  else {
    uVar1 = NvRaidTimerQueueEvent
                      (*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x18),param_2,param_3,param_1,
                       *(longlong *)(param_1 + 0x40));
  }
  return uVar1;
}



===== FUN_00011edc @ 00011edc =====

undefined8 FUN_00011edc(undefined8 param_1,longlong param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)(*(longlong *)(param_2 + 0x40) + 10);
  *pcVar1 = *pcVar1 + -1;
  NvRaidPacketSubmitRequest(param_2);
  return 0x103;
}



===== NvRaidPacketScatterGatherElementAdd @ 00011efc =====

undefined8
NvRaidPacketScatterGatherElementAdd(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  void *pvVar1;
  longlong *plVar2;
  ulonglong uVar3;
  longlong lVar4;
  ushort *puVar5;
  
  uVar3 = (ulonglong)*(ushort *)(param_1 + 4);
  puVar5 = (ushort *)(param_1 + 6);
  plVar2 = (longlong *)(param_1 + 8);
  lVar4 = param_1;
  if (*puVar5 == 0) {
    *puVar5 = 1;
  }
  while( true ) {
    if ((uint)uVar3 < (uint)*puVar5) {
      *(undefined8 *)(lVar4 + 0x18 + uVar3 * 0x10) = param_2;
      *(undefined4 *)(lVar4 + (uVar3 + 2) * 0x10) = param_3;
      *(short *)(param_1 + 4) = *(short *)(param_1 + 4) + 1;
      return 0;
    }
    uVar3 = (ulonglong)((uint)uVar3 - (uint)*puVar5);
    if (*plVar2 == 0) {
      pvVar1 = NvRaidResSgGroupAllocate(*(longlong *)(param_1 + 0x10));
      *plVar2 = (longlong)pvVar1;
    }
    lVar4 = *plVar2;
    if (lVar4 == 0) break;
    plVar2 = (longlong *)(lVar4 + 8);
    puVar5 = (ushort *)(lVar4 + 6);
  }
  return 0xc000009a;
}



===== NvRaidPacketScatterGatherGroupBuildPartialGroup @ 00011fb8 =====

undefined8
NvRaidPacketScatterGatherGroupBuildPartialGroup
          (longlong param_1,longlong param_2,ulonglong param_3,uint param_4,uint param_5,
          uint param_6,uint param_7)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0;
  if (*(short *)(param_1 + 4) != 0) {
    do {
      uVar1 = (uint)*(ushort *)(param_1 + 6);
      lVar3 = param_1;
      uVar4 = uVar5;
      if (*(ushort *)(param_1 + 6) <= uVar5) {
        do {
          lVar3 = *(longlong *)(lVar3 + 8);
          uVar4 = uVar4 - uVar1;
          uVar1 = (uint)*(ushort *)(lVar3 + 6);
        } while (uVar1 <= uVar4);
      }
      uVar1 = *(uint *)(lVar3 + 0x20 + (ulonglong)uVar4 * 0x10);
      if (param_3 < uVar1) {
        uVar1 = uVar1 - (int)param_3;
        uVar2 = param_5;
        if (uVar1 < param_5) {
          uVar2 = uVar1;
        }
        uVar1 = param_4;
        if (uVar2 < param_4) {
          uVar1 = uVar2;
        }
        NvRaidPacketScatterGatherElementAdd
                  (param_2,*(longlong *)(lVar3 + 0x18 + (ulonglong)uVar4 * 0x10) + param_3,uVar1);
        param_5 = param_5 - uVar1;
        param_3 = param_3 + uVar1;
        param_4 = param_4 - uVar1;
        if (param_4 == 0) {
          return 0;
        }
        if (param_5 == 0) {
          param_3 = param_3 + param_7;
          param_5 = param_6;
        }
      }
      else {
        param_3 = param_3 - uVar1;
        uVar5 = uVar5 + 1;
      }
    } while (uVar5 < *(ushort *)(param_1 + 4));
  }
  return 0;
}



===== NvRaidPacketScatterGatherGroupZero @ 0001209c =====

undefined8 NvRaidPacketScatterGatherGroupZero(longlong param_1,int param_2,int param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar3 = param_2 << 9;
  uVar4 = param_3 << 9;
  uVar5 = 0;
  if (*(short *)(param_1 + 4) != 0) {
    do {
      uVar2 = (uint)*(ushort *)(param_1 + 6);
      lVar1 = param_1;
      uVar6 = uVar5;
      if (*(ushort *)(param_1 + 6) <= uVar5) {
        do {
          lVar1 = *(longlong *)(lVar1 + 8);
          uVar6 = uVar6 - uVar2;
          uVar2 = (uint)*(ushort *)(lVar1 + 6);
        } while (uVar2 <= uVar6);
      }
      uVar7 = (ulonglong)uVar6;
      if ((uVar3 == 0) || (uVar6 = *(uint *)(lVar1 + 0x20 + uVar7 * 0x10), uVar3 < uVar6)) {
        if (uVar4 == 0) {
          return 0;
        }
        uVar6 = *(int *)(lVar1 + 0x20 + uVar7 * 0x10) - uVar3;
        if (uVar4 < uVar6) {
          uVar6 = uVar4;
        }
        memset((void *)((ulonglong)uVar3 + *(longlong *)(lVar1 + 0x18 + uVar7 * 0x10)),0,
               (ulonglong)uVar6);
        uVar4 = uVar4 - uVar6;
        if (uVar4 == 0) {
          return 0;
        }
        uVar3 = 0;
      }
      else {
        uVar3 = uVar3 - uVar6;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(ushort *)(param_1 + 4));
  }
  return 0;
}



===== NvRaidPacketScatterGatherGroupXor @ 00012154 =====

undefined8
NvRaidPacketScatterGatherGroupXor
          (longlong param_1,int param_2,uint param_3,longlong param_4,int param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong *plVar12;
  longlong *plVar13;
  
  plVar12 = (longlong *)0x0;
  plVar13 = (longlong *)0x0;
  uVar9 = param_2 << 9;
  uVar10 = param_5 << 9;
  uVar11 = 0;
  if (*(ushort *)(param_4 + 4) != 0) {
    do {
      uVar7 = (uint)*(ushort *)(param_4 + 6);
      uVar3 = uVar11;
      lVar6 = param_4;
      if (uVar7 <= (uint)uVar11) {
        do {
          lVar6 = *(longlong *)(lVar6 + 8);
          uVar1 = (int)uVar3 - uVar7;
          uVar3 = (ulonglong)uVar1;
          uVar7 = (uint)*(ushort *)(lVar6 + 6);
        } while (uVar7 <= uVar1);
      }
      plVar12 = (longlong *)(lVar6 + 0x18 + uVar3 * 0x10);
      if ((uVar10 == 0) || (uVar10 < *(uint *)(plVar12 + 1))) break;
      uVar7 = (uint)uVar11 + 1;
      uVar11 = (ulonglong)uVar7;
      uVar10 = uVar10 - *(uint *)(plVar12 + 1);
    } while (uVar7 < *(ushort *)(param_4 + 4));
  }
  uVar3 = 0;
  if (*(ushort *)(param_1 + 4) != 0) {
    do {
      uVar7 = (uint)*(ushort *)(param_1 + 6);
      uVar4 = uVar3;
      lVar6 = param_1;
      if (uVar7 <= (uint)uVar3) {
        do {
          lVar6 = *(longlong *)(lVar6 + 8);
          uVar1 = (int)uVar4 - uVar7;
          uVar4 = (ulonglong)uVar1;
          uVar7 = (uint)*(ushort *)(lVar6 + 6);
        } while (uVar7 <= uVar1);
      }
      plVar13 = (longlong *)(lVar6 + 0x18 + uVar4 * 0x10);
      if ((uVar9 == 0) || (uVar9 < *(uint *)(plVar13 + 1))) break;
      uVar7 = (uint)uVar3 + 1;
      uVar3 = (ulonglong)uVar7;
      uVar9 = uVar9 - *(uint *)(plVar13 + 1);
    } while (uVar7 < *(ushort *)(param_1 + 4));
  }
  if (param_3 < param_6) {
    param_6 = param_3;
  }
  uVar7 = param_6 << 9;
  if ((plVar12 == (longlong *)0x0) || (plVar13 == (longlong *)0x0)) {
    uVar5 = 0xc0000001;
  }
  else {
    if (uVar7 != 0) {
LAB_00012251:
      uVar4 = (ulonglong)uVar10;
      uVar1 = (int)plVar12[1] - uVar10;
      uVar8 = (ulonglong)uVar9;
      if (uVar7 < uVar1) {
        uVar1 = uVar7;
      }
      uVar2 = (int)plVar13[1] - uVar9;
      if (uVar2 <= uVar1) {
        uVar1 = uVar2;
      }
      uVar7 = uVar7 - uVar1;
      uVar10 = uVar10 + uVar1;
      uVar9 = uVar9 + uVar1;
      FUN_00012524((uint *)(uVar4 + *plVar12),(uint *)(uVar8 + *plVar13),uVar1);
      if (uVar7 == 0) goto LAB_00012317;
      if (uVar10 == *(uint *)(plVar12 + 1)) {
        uVar10 = (int)uVar11 + 1;
        uVar11 = (ulonglong)uVar10;
        if (*(ushort *)(param_4 + 4) <= uVar10) goto LAB_00012317;
        uVar1 = (uint)*(ushort *)(param_4 + 6);
        lVar6 = param_4;
        if (*(ushort *)(param_4 + 6) <= uVar10) {
          do {
            lVar6 = *(longlong *)(lVar6 + 8);
            uVar10 = uVar10 - uVar1;
            uVar1 = (uint)*(ushort *)(lVar6 + 6);
          } while (uVar1 <= uVar10);
        }
        plVar12 = (longlong *)(lVar6 + 0x18 + (ulonglong)uVar10 * 0x10);
        uVar10 = 0;
      }
      if (uVar9 == *(uint *)(plVar13 + 1)) {
        uVar9 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar9;
        if (*(ushort *)(param_1 + 4) <= uVar9) goto LAB_00012317;
        uVar1 = (uint)*(ushort *)(param_1 + 6);
        lVar6 = param_1;
        if (*(ushort *)(param_1 + 6) <= uVar9) {
          do {
            lVar6 = *(longlong *)(lVar6 + 8);
            uVar9 = uVar9 - uVar1;
            uVar1 = (uint)*(ushort *)(lVar6 + 6);
          } while (uVar1 <= uVar9);
        }
        plVar13 = (longlong *)(lVar6 + 0x18 + (ulonglong)uVar9 * 0x10);
        uVar9 = 0;
      }
      goto LAB_00012251;
    }
LAB_00012317:
    uVar5 = 0;
  }
  return uVar5;
}



===== NvRaidPacketScatterGatherGroupCopy @ 00012340 =====

undefined8
NvRaidPacketScatterGatherGroupCopy
          (longlong param_1,int param_2,longlong param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong *plVar12;
  longlong *plVar13;
  
  plVar13 = (longlong *)0x0;
  plVar12 = (longlong *)0x0;
  uVar11 = 0;
  uVar9 = param_2 << 9;
  uVar10 = param_4 << 9;
  if (*(ushort *)(param_3 + 4) != 0) {
    do {
      uVar8 = (uint)*(ushort *)(param_3 + 6);
      uVar3 = uVar11;
      lVar6 = param_3;
      if (uVar8 <= (uint)uVar11) {
        do {
          lVar6 = *(longlong *)(lVar6 + 8);
          uVar1 = (int)uVar3 - uVar8;
          uVar3 = (ulonglong)uVar1;
          uVar8 = (uint)*(ushort *)(lVar6 + 6);
        } while (uVar8 <= uVar1);
      }
      plVar13 = (longlong *)(lVar6 + 0x18 + uVar3 * 0x10);
      if ((uVar10 == 0) || (uVar10 < *(uint *)(plVar13 + 1))) break;
      uVar8 = (uint)uVar11 + 1;
      uVar11 = (ulonglong)uVar8;
      uVar10 = uVar10 - *(uint *)(plVar13 + 1);
    } while (uVar8 < *(ushort *)(param_3 + 4));
  }
  uVar3 = 0;
  if (*(ushort *)(param_1 + 4) != 0) {
    do {
      uVar8 = (uint)*(ushort *)(param_1 + 6);
      uVar4 = uVar3;
      lVar6 = param_1;
      if (uVar8 <= (uint)uVar3) {
        do {
          lVar6 = *(longlong *)(lVar6 + 8);
          uVar1 = (int)uVar4 - uVar8;
          uVar4 = (ulonglong)uVar1;
          uVar8 = (uint)*(ushort *)(lVar6 + 6);
        } while (uVar8 <= uVar1);
      }
      plVar12 = (longlong *)(lVar6 + 0x18 + uVar4 * 0x10);
      if ((uVar9 == 0) || (uVar9 < *(uint *)(plVar12 + 1))) break;
      uVar8 = (uint)uVar3 + 1;
      uVar3 = (ulonglong)uVar8;
      uVar9 = uVar9 - *(uint *)(plVar12 + 1);
    } while (uVar8 < *(ushort *)(param_1 + 4));
  }
  uVar8 = param_5 << 9;
  if ((plVar13 == (longlong *)0x0) || (plVar12 == (longlong *)0x0)) {
    uVar5 = 0xc0000001;
  }
  else {
    if (uVar8 != 0) {
LAB_0001242e:
      uVar4 = (ulonglong)uVar10;
      uVar1 = (int)plVar13[1] - uVar10;
      if (uVar8 < uVar1) {
        uVar1 = uVar8;
      }
      uVar2 = (int)plVar12[1] - uVar9;
      if (uVar2 <= uVar1) {
        uVar1 = uVar2;
      }
      uVar8 = uVar8 - uVar1;
      uVar10 = uVar10 + uVar1;
      uVar7 = (ulonglong)uVar9;
      uVar9 = uVar9 + uVar1;
      memcpy((void *)(uVar7 + *plVar12),(void *)(uVar4 + *plVar13),(ulonglong)uVar1);
      if (uVar8 == 0) goto LAB_000124fc;
      if (uVar10 == *(uint *)(plVar13 + 1)) {
        uVar10 = (int)uVar11 + 1;
        uVar11 = (ulonglong)uVar10;
        if (*(ushort *)(param_3 + 4) <= uVar10) goto LAB_000124fc;
        uVar1 = (uint)*(ushort *)(param_3 + 6);
        lVar6 = param_3;
        if (*(ushort *)(param_3 + 6) <= uVar10) {
          do {
            lVar6 = *(longlong *)(lVar6 + 8);
            uVar10 = uVar10 - uVar1;
            uVar1 = (uint)*(ushort *)(lVar6 + 6);
          } while (uVar1 <= uVar10);
        }
        plVar13 = (longlong *)(lVar6 + 0x18 + (ulonglong)uVar10 * 0x10);
        uVar10 = 0;
      }
      if (uVar9 == *(uint *)(plVar12 + 1)) {
        uVar9 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar9;
        if (*(ushort *)(param_1 + 4) <= uVar9) goto LAB_000124fc;
        uVar1 = (uint)*(ushort *)(param_1 + 6);
        lVar6 = param_1;
        if (*(ushort *)(param_1 + 6) <= uVar9) {
          do {
            lVar6 = *(longlong *)(lVar6 + 8);
            uVar9 = uVar9 - uVar1;
            uVar1 = (uint)*(ushort *)(lVar6 + 6);
          } while (uVar1 <= uVar9);
        }
        plVar12 = (longlong *)(lVar6 + 0x18 + (ulonglong)uVar9 * 0x10);
        uVar9 = 0;
      }
      goto LAB_0001242e;
    }
LAB_000124fc:
    uVar5 = 0;
  }
  return uVar5;
}



===== FUN_00012524 @ 00012524 =====

void FUN_00012524(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  if (3 < param_3) {
    uVar3 = (ulonglong)(param_3 >> 2);
    do {
      uVar1 = *param_1;
      param_3 = param_3 - 4;
      param_1 = param_1 + 1;
      *param_2 = *param_2 ^ uVar1;
      param_2 = param_2 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  if (param_3 != 0) {
    lVar2 = (longlong)param_1 - (longlong)param_2;
    do {
      *(byte *)param_2 = (byte)*param_2 ^ *(byte *)(lVar2 + (longlong)param_2);
      param_2 = (uint *)((longlong)param_2 + 1);
      param_3 = param_3 - 1;
    } while (param_3 != 0);
  }
  return;
}



===== NvRaidPacketExecuteStateMachine @ 0001255c =====

void NvRaidPacketExecuteStateMachine(undefined8 param_1,longlong param_2)

{
  int iVar1;
  
  do {
    iVar1 = (**(code **)(*(longlong *)(param_2 + 0x58) + (ulonglong)*(byte *)(param_2 + 0x56) * 8))
                      (param_1,param_2);
  } while (iVar1 == 0);
  return;
}



===== NvRaidPacketScatterGatherGroupAllocBuildPartialGroup @ 00012590 =====

void NvRaidPacketScatterGatherGroupAllocBuildPartialGroup
               (longlong param_1,longlong param_2,ulonglong param_3,uint param_4)

{
  undefined8 uVar1;
  
  if ((*(longlong *)(param_2 + 0xa8) == 0) &&
     (uVar1 = NvRaidResSgGroupAllocateForNrp
                        (*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x18),param_2),
     (int)uVar1 < 0)) {
    return;
  }
  NvRaidPacketScatterGatherGroupBuildPartialGroup
            (*(longlong *)(param_1 + 0xa8),*(longlong *)(param_2 + 0xa8),param_3,param_4,param_4,0,0
            );
  return;
}



===== FUN_00012608 @ 00012608 =====

undefined8 FUN_00012608(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  ulonglong uVar9;
  
  lVar1 = *(longlong *)(param_2 + 0xa8);
  lVar7 = *(longlong *)(param_2 + 0x88);
  uVar8 = 0;
  if (*(short *)(lVar1 + 4) != 0) {
    do {
      uVar2 = (uint)*(ushort *)(lVar1 + 6);
      lVar6 = lVar1;
      uVar5 = uVar8;
      if (*(ushort *)(lVar1 + 6) <= uVar8) {
        do {
          lVar6 = *(longlong *)(lVar6 + 8);
          uVar5 = uVar5 - uVar2;
          uVar2 = (uint)*(ushort *)(lVar6 + 6);
        } while (uVar2 <= uVar5);
      }
      uVar9 = (ulonglong)uVar5;
      puVar3 = NvRaidResNrpAllocate(*(longlong *)(*(longlong *)(param_2 + 0x40) + 0x18));
      if (puVar3 == (undefined8 *)0x0) {
LAB_00012776:
        *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x02';
        return 0;
      }
      uVar4 = NvRaidResSgGroupAllocateForNrp
                        (*(longlong *)(*(longlong *)(param_2 + 0x40) + 0x18),(longlong)puVar3);
      if ((int)uVar4 < 0) {
        NvRaidResNrpFree(*(longlong *)(*(longlong *)(param_2 + 0x40) + 0x18),(undefined4 *)puVar3);
        goto LAB_00012776;
      }
      NvRaidPacketScatterGatherElementAdd
                (puVar3[0x15],*(undefined8 *)(lVar6 + 0x18 + uVar9 * 0x10),
                 *(undefined4 *)(lVar6 + 0x20 + uVar9 * 0x10));
      uVar8 = uVar8 + 1;
      puVar3[8] = *(undefined8 *)(param_2 + 0x40);
      *(undefined1 *)(puVar3 + 9) = *(undefined1 *)(param_2 + 0x48);
      puVar3[0x14] = NvRaidStateSubRequestsDone;
      *(undefined4 *)((longlong)puVar3 + 100) = *(undefined4 *)(param_2 + 100);
      *(uint *)(puVar3 + 0xc) = *(uint *)(puVar3 + 0xc) | *(uint *)(param_2 + 0x60) & 4;
      uVar5 = *(uint *)(lVar6 + 0x20 + uVar9 * 0x10);
      puVar3[0x10] = *(undefined8 *)(param_2 + 0x80);
      puVar3[0x11] = lVar7;
      *puVar3 = 0;
      uVar5 = uVar5 >> 9;
      *(uint *)(puVar3 + 0x12) = uVar5;
      puVar3[1] = *(undefined8 *)(param_2 + 0x28);
      **(undefined8 **)(param_2 + 0x28) = puVar3;
      *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
      *(undefined8 **)(param_2 + 0x28) = puVar3;
      puVar3[0xd] = param_2;
      puVar3[0xe] = *(undefined8 *)(param_2 + 0x40);
      lVar7 = lVar7 + (ulonglong)uVar5;
    } while (uVar8 < *(ushort *)(lVar1 + 4));
  }
  *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
  NvRaidPacketSubmitSubRequests((longlong *)(param_2 + 0x20));
  return 0x103;
}



===== FUN_00012780 @ 00012780 =====

ulonglong FUN_00012780(int *param_1,int *param_2)

{
  char cVar1;
  ulonglong uVar2;
  
  uVar2 = 0;
  if (*param_1 == 0) {
    cVar1 = NvRaidCalculateRequiredVolumes(*param_2,'\x01');
    if (cVar1 == '\0') goto LAB_000127b1;
  }
  else if (*param_1 != *param_2) goto LAB_000127b1;
  uVar2 = 1;
  *(int **)(param_2 + 2) = param_1;
LAB_000127b1:
  return uVar2 & 0xffffffff;
}



===== NvRaidFindRaidLevelMethod @ 000127bc =====

undefined8 NvRaidFindRaidLevelMethod(int param_1)

{
  ulonglong uVar1;
  undefined **ppuVar2;
  int local_18 [2];
  undefined8 local_10;
  
  ppuVar2 = &gNvRaidRaidLevelMethods;
  local_18[0] = param_1;
  do {
    uVar1 = FUN_00012780((int *)*ppuVar2,local_18);
    if ((int)uVar1 != 0) {
      return local_10;
    }
    ppuVar2 = ppuVar2 + 1;
  } while (ppuVar2 < &DAT_00029060);
  return 0;
}



===== NvRaidCalculateRequiredVolumes @ 00012800 =====

char NvRaidCalculateRequiredVolumes(int param_1,char param_2)

{
  if (param_1 == 0x80) {
    return param_2;
  }
  if (param_1 != 0x81) {
    if ((param_1 == 0x83) || (param_1 == 0x85)) {
LAB_0001283c:
      return param_2 + '\x01';
    }
    if (param_1 != 0x8a) {
      if (param_1 == 0x95) goto LAB_0001283c;
      if (param_1 == 0xff) {
        return param_2;
      }
      if ((param_1 != 0x8081) && (param_1 != 0x8180)) {
        return '\0';
      }
    }
  }
  return param_2 * '\x02';
}



===== NvRaidDefaultUpdateArrayStatus @ 00012844 =====

uint NvRaidDefaultUpdateArrayStatus(longlong param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  longlong lVar5;
  longlong lVar6;
  
  lVar6 = *(longlong *)(param_1 + 0x58);
  if (lVar6 == 0) {
    return *(uint *)(param_1 + 4);
  }
  bVar1 = *(byte *)(lVar6 + 0x16);
  uVar4 = *(uint *)(param_1 + 4) & 0xfffffff8;
  if ((uint)bVar1 <= *(uint *)(param_1 + 0x78)) {
    uVar3 = 0;
    bVar2 = 0;
    if (bVar1 != 0) {
      do {
        bVar2 = (byte)uVar3;
        if (((uint *)(param_1 + 0x78) == (uint *)0x0) || (*(uint *)(param_1 + 0x7c) <= uVar3)) {
          lVar5 = 0;
        }
        else {
          lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)uVar3 * 8);
        }
        if (((lVar5 == 0) || ((*(uint *)(lVar5 + 4) & 1) != 0)) ||
           ((*(char *)(lVar6 + 0x14) == '\0' && ((*(uint *)(lVar5 + 4) >> 8 & 1) != 0)))) {
          lVar5 = 0;
        }
        if ((lVar5 == 0) || ((*(uint *)(lVar5 + 4) & 2) == 0)) break;
        bVar2 = bVar2 + 1;
        uVar3 = (uint)bVar2;
      } while (bVar2 < bVar1);
    }
    if (((param_2 & 2) != 0) && (bVar2 != 0)) {
      bVar2 = bVar2 - 1;
    }
    if (bVar2 == bVar1) {
      uVar4 = uVar4 | 2;
      goto LAB_000128e7;
    }
  }
  uVar4 = uVar4 | 1;
LAB_000128e7:
  if ((param_2 & 8) != 0) {
    NvRaidResArrayGenerateSignature((uint *)(lVar6 + 4));
  }
  if (((((param_2 & 1) != 0) && (*(uint *)(param_1 + 4) = uVar4, (uVar4 & 0x102) == 2)) &&
      (*(char *)(lVar6 + 0x14) != '\0')) && ((param_2 & 4) != 0)) {
    NvRaidJobScheduleRequest(param_1,*(char *)(lVar6 + 0x14),0,0x3c,0,0);
  }
  return uVar4;
}



===== NvRaidStripeLockRelease @ 00012948 =====

undefined8 NvRaidStripeLockRelease(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x58);
  if (*(int *)(lVar1 + 0x70) != 0) {
    *(undefined4 *)(lVar1 + 0x70) = 0;
    while (lVar2 = *(longlong *)(lVar1 + 0x78), lVar2 != 0) {
      if (*(longlong *)(lVar2 + 0x10) == 0) {
        *(undefined8 *)(lVar1 + 0x80) = *(undefined8 *)(lVar2 + 0x18);
      }
      else {
        *(undefined8 *)(*(longlong *)(lVar2 + 0x10) + 0x18) = *(undefined8 *)(lVar2 + 0x18);
      }
      **(undefined8 **)(lVar2 + 0x18) = *(undefined8 *)(lVar2 + 0x10);
      FUN_00011e84(lVar2);
    }
  }
  return 0;
}



===== NvRaidStateSubRequestsFail @ 000129c0 =====

undefined4 NvRaidStateSubRequestsFail(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong *plVar2;
  uint uVar3;
  longlong lVar4;
  undefined4 uVar5;
  longlong *plVar6;
  char cVar7;
  uint local_res8 [2];
  char local_res10 [8];
  char local_res18;
  undefined1 local_res19;
  undefined1 local_res1a;
  undefined1 local_res1b;
  int local_res20 [2];
  
  *(undefined4 *)(param_2 + 0x50) = 0xc0000001;
  cVar7 = *(char *)(param_2 + 0x56) + -1;
  *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x02';
  lVar1 = *(longlong *)(param_1 + 0x58);
  if (lVar1 == 0) {
LAB_000129fc:
    uVar5 = 0;
  }
  else {
    if (*(longlong **)(param_2 + 0x20) == (longlong *)0x0) {
      *(undefined4 *)(param_2 + 0x50) = 0xc000000d;
      *(undefined4 *)(param_2 + 0x4b) = 0x40202;
    }
    else {
      plVar6 = *(longlong **)(param_2 + 0x20);
      uVar3 = local_res8[0];
      do {
        if (plVar6 == (longlong *)0x0) break;
        plVar2 = (longlong *)*plVar6;
        if ((int)plVar6[10] != 0) {
          if ((((int)plVar6[10] != -0x3fffff40) && ((*(uint *)(plVar6[8] + 4) & 8) != 0)) &&
             ((*(char *)((longlong)plVar6 + 0x4b) != '\x02' ||
              (((*(char *)((longlong)plVar6 + 0x4c) != '\0' ||
                (*(char *)((longlong)plVar6 + 0x4d) != '\0')) ||
               (*(char *)((longlong)plVar6 + 0x4e) != '\0')))))) {
            local_res19 = *(undefined1 *)((longlong)plVar6 + 0x4c);
            local_res1a = *(undefined1 *)((longlong)plVar6 + 0x4d);
            local_res1b = *(undefined1 *)((longlong)plVar6 + 0x4e);
            local_res18 = *(char *)((longlong)plVar6 + 0x4b);
            NvRaidApiFireEvent(plVar6[8],8,&local_res18);
          }
          if (param_1 == plVar6[8]) {
            if ((*(uint *)(plVar6 + 0xc) & 0x400) == 0) {
              uVar3 = NvRaidScsiErrorAction
                                (*(char *)((longlong)plVar6 + 0x4c),
                                 *(char *)((longlong)plVar6 + 0x4d),
                                 *(char *)((longlong)plVar6 + 0x4e),(char *)local_res8,local_res10);
              if ((((byte)local_res8[0] < 7) && ((0x5aU >> (local_res8[0] & 0x1f) & 1) != 0)) &&
                 (*(char *)(param_2 + 0x4a) != '\0')) {
                local_res20[0] = 1;
                *(char *)(param_2 + 0x4a) = *(char *)(param_2 + 0x4a) + -1;
                goto LAB_00012b2b;
              }
            }
            local_res20[0] = 3;
          }
          else {
            if ((*(uint *)(plVar6 + 0xc) & 4) == 0) {
              lVar4 = *(longlong *)(lVar1 + 0x88);
            }
            else {
              lVar4 = *(longlong *)(lVar1 + 0x90);
            }
            uVar3 = (**(code **)(lVar4 + 0x40))(param_1,plVar6,local_res20);
          }
LAB_00012b2b:
          if (local_res20[0] == 0) {
            *(uint *)(param_2 + 0x50) = uVar3;
          }
          else if (local_res20[0] == 1) {
            *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
            *(char *)(param_2 + 0x56) = cVar7;
            NvRaidPacketSubmitRequest((longlong)plVar6);
          }
          else {
            if (local_res20[0] == 2) {
              NvRaidResNrpFreeSubReqs(*(longlong *)(param_1 + 0x18),param_2);
              if (*(char *)(param_2 + 0xb0) != '\0') {
                NvRaidParityLockRelease
                          (param_2,*(ulonglong *)(param_2 + 0xb8),*(longlong *)(param_2 + 0x40));
              }
              *(undefined1 *)(param_2 + 0x56) = 0;
              goto LAB_000129fc;
            }
            if (local_res20[0] == 3) {
              *(uint *)(param_2 + 0x50) = uVar3;
              *(undefined1 *)(param_2 + 0x4b) = *(undefined1 *)((longlong)plVar6 + 0x4b);
              *(undefined1 *)(param_2 + 0x4c) = *(undefined1 *)((longlong)plVar6 + 0x4c);
              *(undefined1 *)(param_2 + 0x4d) = *(undefined1 *)((longlong)plVar6 + 0x4d);
              *(undefined1 *)(param_2 + 0x4e) = *(undefined1 *)((longlong)plVar6 + 0x4e);
            }
          }
        }
        plVar6 = plVar2;
      } while (plVar2 != (longlong *)0x0);
    }
    uVar5 = 0;
    if (*(char *)(param_2 + 0x56) == cVar7) {
      uVar5 = 0x103;
    }
  }
  return uVar5;
}



===== NvRaidStateSubRequestsFinish @ 00012bc4 =====

undefined8 NvRaidStateSubRequestsFinish(longlong param_1,longlong param_2)

{
  if (*(char *)(param_2 + 0xb0) != '\0') {
    NvRaidParityLockRelease(param_2,*(ulonglong *)(param_2 + 0xb8),*(longlong *)(param_2 + 0x40));
  }
  NvRaidResNrpFreeSubReqs(*(longlong *)(param_1 + 0x18),param_2);
  NvRaidPacketCompleteRequest(param_2);
  return 0x103;
}



===== NvRaidStateSubRequestsFinishAndKeep @ 00012c14 =====

undefined8 NvRaidStateSubRequestsFinishAndKeep(undefined8 param_1,longlong param_2)

{
  NvRaidPacketCompleteRequest(param_2);
  return 0x103;
}



===== FUN_00012c40 @ 00012c40 =====

longlong FUN_00012c40(longlong param_1,ulonglong param_2,byte param_3,int param_4)

{
  byte bVar1;
  longlong lVar2;
  byte bVar3;
  uint uVar4;
  ulonglong uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  lVar2 = *(longlong *)(param_1 + 0x58);
  if (param_4 == 0) {
    bVar1 = *(byte *)(lVar2 + 0x17);
    iVar6 = *(int *)(lVar2 + 0x38);
  }
  else {
    bVar1 = *(byte *)(lVar2 + 0x15);
    iVar6 = *(int *)(lVar2 + 0x18);
  }
  bVar3 = (byte)*(undefined4 *)(lVar2 + 0x24);
  if (((iVar6 - 0x83U & 0xffffffed) == 0) && (iVar6 != 0x93)) {
    iVar8 = *(byte *)(lVar2 + 0x15) + 1;
    uVar5 = param_2 >> (bVar3 & 0x3f);
    uVar7 = (uint)*(byte *)(lVar2 + 0x15);
    if (iVar6 != 0x83) {
      uVar7 = uVar7 - (int)(uVar5 % (ulonglong)(uVar7 + 1));
    }
    if (iVar6 == 0x95) {
      uVar4 = (uint)((ulonglong)
                     (((uint)(uVar5 % (ulonglong)(longlong)iVar8) & 0xff) + (uint)param_3) %
                    (ulonglong)(longlong)iVar8);
    }
    else {
      uVar4 = (uint)param_3;
      if (uVar7 < param_3) {
        uVar4 = param_3 - 1 & 0xff;
      }
    }
  }
  else {
    uVar4 = (uint)((ulonglong)param_3 % (ulonglong)(longlong)(int)(uint)bVar1);
  }
  return (ulonglong)((uVar4 & 0xff) << (bVar3 & 0x1f)) +
         (param_2 - param_2 % (ulonglong)*(uint *)(lVar2 + 0x1c)) * (ulonglong)bVar1;
}



===== FUN_00012d54 @ 00012d54 =====

undefined8 FUN_00012d54(undefined8 param_1,longlong param_2)

{
  uint *puVar1;
  char cVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_2 + 0x68);
  if (*(int *)(param_2 + 0x50) != 0) {
    puVar1 = (uint *)(lVar3 + 0x60);
    *puVar1 = *puVar1 | 8;
  }
  cVar2 = *(char *)(param_2 + 0x81);
  if (cVar2 == '(') {
    *(undefined1 *)(param_2 + 0x81) = 0x2a;
  }
  else if (cVar2 == '*') {
    *(undefined1 *)(param_2 + 0x81) = 0x28;
  }
  else if (cVar2 == -0x78) {
    *(undefined1 *)(param_2 + 0x81) = 0x8a;
  }
  else if (cVar2 == -0x76) {
    *(undefined1 *)(param_2 + 0x81) = 0x88;
  }
  NvRaidPacketExecuteStateMachine(param_1,lVar3);
  return 0;
}



===== FUN_00012db8 @ 00012db8 =====

undefined8 FUN_00012db8(longlong param_1,longlong param_2)

{
  uint *puVar1;
  char cVar2;
  longlong lVar3;
  byte bVar4;
  
  lVar3 = *(longlong *)(param_2 + 0x68);
  if ((*(uint *)(param_2 + 0x60) & 4) == 0) {
    bVar4 = *(byte *)(*(longlong *)(param_1 + 0x58) + 0x17);
  }
  else {
    bVar4 = *(byte *)(*(longlong *)(param_1 + 0x58) + 0x15);
  }
  cVar2 = *(char *)(param_2 + 0x81);
  if (cVar2 == '(') {
    *(undefined1 *)(param_2 + 0x81) = 0x2a;
  }
  else if (cVar2 == '*') {
    *(undefined1 *)(param_2 + 0x81) = 0x28;
  }
  else if (cVar2 == -0x78) {
    *(undefined1 *)(param_2 + 0x81) = 0x8a;
  }
  else if (cVar2 == -0x76) {
    *(undefined1 *)(param_2 + 0x81) = 0x88;
  }
  NvRaidScsiSetupReadWrite
            (param_2,*(undefined1 *)(*(longlong *)(param_2 + 0xc0) + 8),
             *(longlong *)(param_2 + 0xc0),FUN_00012d54,*(byte *)(param_2 + 0x81),
             *(ulonglong *)(param_2 + 0x88) / (ulonglong)bVar4,*(undefined4 *)(param_2 + 0x90));
  *(undefined8 *)(param_2 + 0xc0) = 0;
  *(uint *)(param_2 + 0x60) = *(uint *)(param_2 + 0x60) & 0xfffffbff;
  if (*(int *)(param_2 + 0x50) == 0) {
    NvRaidPacketSubmitRequest(param_2);
  }
  else {
    puVar1 = (uint *)(lVar3 + 0x60);
    *puVar1 = *puVar1 | 8;
    NvRaidPacketExecuteStateMachine(param_1,lVar3);
  }
  return 0;
}



===== NvRaidStateSubRequestsDone @ 00012ea8 =====

undefined8 NvRaidStateSubRequestsDone(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_2 + 0x68);
  if ((((*(int *)(param_2 + 0x50) == 0) || ((*(uint *)(lVar3 + 0x60) & 0x400) != 0)) ||
      (*(char *)(param_2 + 0x4c) != '\x03')) ||
     ((((byte)*(undefined4 *)(param_1 + 4) & 0x42) != 2 ||
      (lVar2 = *(longlong *)(param_2 + 0x40), lVar2 == param_1)))) {
    if (lVar3 != 0) {
      if (*(int *)(param_2 + 0x50) != 0) {
        *(uint *)(lVar3 + 0x60) = *(uint *)(lVar3 + 0x60) | 8;
      }
      NvRaidPacketExecuteStateMachine(param_1,lVar3);
    }
  }
  else {
    uVar1 = *(uint *)(param_2 + 0x60);
    lVar3 = FUN_00012c40(param_1,*(ulonglong *)(param_2 + 0x88),*(byte *)(param_2 + 0x48),uVar1 & 4)
    ;
    *(undefined4 *)(param_2 + 0x50) = 0;
    *(longlong *)(param_2 + 0xc0) = lVar2;
    *(undefined4 *)(param_2 + 0x4b) = 0;
    *(uint *)(param_2 + 0x60) = uVar1 | 0x400;
    NvRaidScsiSetupReadWrite
              (param_2,*(undefined1 *)(param_1 + 8),param_1,FUN_00012db8,*(byte *)(param_2 + 0x81),
               lVar3,*(undefined4 *)(param_2 + 0x90));
    NvRaidPacketSubmitRequest(param_2);
  }
  return 0;
}



===== NvRaidDefaultProcessError @ 00012f98 =====

int NvRaidDefaultProcessError(undefined4 *param_1,longlong param_2,uint *param_3)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  char local_res10 [8];
  byte local_res18 [8];
  
  iVar2 = *(int *)(param_2 + 0x50);
  *param_3 = 0;
  if (iVar2 == 0) {
    return 0;
  }
  bVar1 = *(byte *)(param_2 + 0x4b);
  if (bVar1 == 0) {
LAB_000130a6:
    *(undefined1 *)(param_2 + 0x4b) = 0;
    *param_3 = 0;
    return 0;
  }
  if (bVar1 != 2) {
    if ((bVar1 < 0x15) && ((0x110010U >> (bVar1 & 0x1f) & 1) != 0)) goto LAB_000130a6;
    if (bVar1 != 0x22) {
      return iVar2;
    }
  }
  if ((param_1 == (undefined4 *)0xffffffffffffff88) ||
     ((uint)param_1[0x1f] <= (uint)*(byte *)(param_2 + 0x48))) {
    lVar4 = 0;
  }
  else {
    lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x20) + (ulonglong)*(byte *)(param_2 + 0x48) * 8);
  }
  lVar5 = *(longlong *)(param_2 + 0x40);
  if (lVar4 != lVar5) {
    *param_3 = *(byte *)(param_1 + 1) & 1 | 2;
    return iVar2;
  }
  iVar2 = NvRaidScsiErrorAction
                    (*(char *)(param_2 + 0x4c),*(char *)(param_2 + 0x4d),*(char *)(param_2 + 0x4e),
                     local_res10,(char *)local_res18);
  if (local_res10[0] == '\x01') {
    *(char *)(lVar5 + 9) = *(char *)(lVar5 + 9) + '\x01';
    lVar5 = *(longlong *)(param_2 + 0x40);
    if (*(byte *)(lVar5 + 9) < 0x20) {
      if (*(char *)(param_2 + 0x4a) != '\0') {
        if ((local_res18[0] & 1) != 0) {
          *(char *)(param_2 + 0x4a) = *(char *)(param_2 + 0x4a) + -1;
        }
        *param_3 = 1;
        return iVar2;
      }
      goto LAB_0001305c;
    }
  }
  else if (((local_res10[0] - 3U & 0xfc) != 0) || (local_res10[0] == '\x05')) goto LAB_0001305c;
  uVar3 = NvRaidRemoveFailedVolumeFromArray(param_1,lVar5);
  if ((char)uVar3 != '\0') {
    *param_3 = 2;
    return iVar2;
  }
LAB_0001305c:
  *param_3 = 3;
  return *(int *)(param_2 + 0x50);
}



===== FUN_000130c4 @ 000130c4 =====

undefined8 FUN_000130c4(longlong param_1,undefined4 *param_2)

{
  code *pcVar1;
  
  if (*(longlong *)(param_2 + 0x1a) != 0) {
    pcVar1 = *(code **)(*(longlong *)(param_2 + 0x1a) + 0x78);
    *(undefined8 *)(param_2 + 0x1a) = 0;
    (*pcVar1)();
  }
  NvRaidResNrpFree(*(longlong *)(param_1 + 0x18),param_2);
  return 0;
}



===== NvRaidJobScheduleRequest @ 00013104 =====

undefined8
NvRaidJobScheduleRequest
          (longlong param_1,undefined1 param_2,longlong param_3,int param_4,longlong param_5,
          undefined8 param_6)

{
  char *pcVar1;
  undefined1 uVar2;
  void *pvVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  lVar5 = param_3;
  pvVar3 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    uVar2 = *(undefined1 *)(param_1 + 8);
    *(longlong *)((longlong)pvVar3 + 0x40) = param_1;
    *(undefined1 *)((longlong)pvVar3 + 0x48) = uVar2;
    uVar2 = *(undefined1 *)(param_1 + 8);
    *(undefined1 *)((longlong)pvVar3 + 0x4a) = 5;
    *(undefined1 *)((longlong)pvVar3 + 0x48) = uVar2;
    *(code **)((longlong)pvVar3 + 0xa0) = FUN_000130c4;
    *(undefined1 *)((longlong)pvVar3 + 0x80) = 0xff;
    *(undefined1 *)((longlong)pvVar3 + 0x81) = param_2;
    *(longlong *)((longlong)pvVar3 + 0x70) = param_1;
    if (param_3 != 0) {
      *(longlong *)((longlong)pvVar3 + 0x88) = param_3;
    }
    if (param_5 != 0) {
      *(longlong *)((longlong)pvVar3 + 0x68) = param_5;
      *(undefined8 *)(param_5 + 0x78) = param_6;
    }
    pcVar1 = (char *)(*(longlong *)((longlong)pvVar3 + 0x40) + 10);
    *pcVar1 = *pcVar1 + '\x01';
    *(undefined1 *)((longlong)pvVar3 + 0x56) = 0;
    *(undefined ***)((longlong)pvVar3 + 0x58) = &PTR_FUN_00027448;
    NvRaidPacketScheduleRequest((longlong)pvVar3,param_4,lVar5);
    uVar4 = 0;
  }
  return uVar4;
}



===== FUN_000131c8 @ 000131c8 =====

undefined8 FUN_000131c8(longlong param_1,longlong param_2,longlong param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  NvRaidResNrpFreePacketResources(*(longlong *)(param_1 + 0x18),param_2);
  puVar1 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
  if (puVar1 != (undefined8 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = *(undefined8 *)(param_2 + 0x28);
    **(undefined8 **)(param_2 + 0x28) = puVar1;
    *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
    *(undefined8 **)(param_2 + 0x28) = puVar1;
    puVar1[0xd] = param_2;
    puVar1[0xe] = *(undefined8 *)(param_2 + 0x40);
    param_3 = param_2;
    uVar2 = NvRaidResBufferAllocateForNrp(*(longlong *)(param_1 + 0x18),0x200,param_2);
    if ((int)uVar2 == 0) {
      *(char *)(puVar1 + 9) = (char)uVar2;
      *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
      return uVar2;
    }
  }
  *(undefined1 *)(param_2 + 0x56) = 0;
  NvRaidResNrpFreePacketResources(*(longlong *)(*(longlong *)(param_2 + 0x40) + 0x18),param_2);
  NvRaidTimerQueueEvent
            (*(longlong *)(*(longlong *)(param_2 + 0x40) + 0x18),1,param_3,param_2,
             *(longlong *)(param_2 + 0x40));
  return 0x103;
}



===== FUN_00013280 @ 00013280 =====

ulonglong FUN_00013280(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int *piVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_2 + 0x20);
  if (*(char *)(param_2 + 0x81) == '\a') {
    *(undefined1 *)(lVar1 + 0x48) = *(undefined1 *)(param_1 + 8);
    lVar4 = param_1;
  }
  else {
    if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)*(byte *)(lVar1 + 0x48))) {
      lVar4 = 0;
    }
    else {
      lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)*(byte *)(lVar1 + 0x48) * 8);
    }
    if (lVar4 == 0) {
      *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x03';
      return 0;
    }
  }
  piVar2 = *(int **)(*(longlong *)(param_2 + 0xa8) + 0x18);
  *(longlong *)(lVar1 + 0x40) = lVar4;
  NvRaidScsiSetupReadWrite
            (lVar1,*(undefined1 *)(lVar1 + 0x48),lVar4,NvRaidStateSubRequestsDone,0x2a,
             *(longlong *)(lVar4 + 0x20) + -2,1);
  if (*(char *)(param_2 + 0x81) == '\a') {
    piVar2[0] = 0;
    piVar2[1] = 0;
  }
  else {
    NvRaidSectorInitializeSector(param_1,lVar4,piVar2);
  }
  *(undefined8 *)(lVar1 + 0xa8) = *(undefined8 *)(param_2 + 0xa8);
  *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
  *(undefined1 *)(param_2 + 0x55) = 1;
  uVar3 = NvRaidPacketSubmitRequest(lVar1);
  return uVar3;
}



===== NvRaidJobInitialize @ 0001339c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 NvRaidJobInitialize(longlong param_1,longlong param_2)

{
  byte bVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined1 auStackY_78 [32];
  undefined **local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  lVar3 = *(longlong *)(param_1 + 0x58);
  bVar1 = *(byte *)(param_2 + 0x81);
  local_30 = &PTR_FUN_00027490;
  if (lVar3 == 0) {
LAB_000133ef:
    uVar5 = 0xc000000d;
  }
  else {
    if ((*(uint *)(param_1 + 4) & 2) == 0) {
      NvRaidJobClearInformation(param_1);
      return 0xc0000010;
    }
    if (*(byte *)(lVar3 + 0x14) == 0) {
      *(byte *)(lVar3 + 0x14) = bVar1;
      lVar4 = *(longlong *)(param_1 + 0x58);
      *(undefined8 *)(lVar4 + 0x58) = 0;
      *(undefined4 *)(lVar4 + 0x34) = 0;
LAB_0001342b:
      if ((*(uint *)(param_1 + 4) & 0x40) == 0) {
        if (((bVar1 - 3 & 0xfd) != 0) ||
           ((*(int *)(lVar3 + 0x18) != 0x80 && (*(int *)(lVar3 + 0x18) != 0xff)))) {
          local_28 = 0xc;
          local_24 = 9;
          local_20 = 0xf;
          local_1c = 0x13;
          uVar2 = *(undefined4 *)((longlong)&local_30 + (ulonglong)bVar1 * 4);
          uVar6 = 0;
          *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x40;
          NvRaidApiFireEvent(param_1,uVar2,0);
          uVar5 = *(undefined8 *)(auStackY_78 + (ulonglong)bVar1 * 8 + 0x20);
          *(undefined1 *)(param_2 + 0x56) = 0;
          *(undefined8 *)(param_2 + 0x58) = uVar5;
          *(undefined1 *)(param_2 + 0x82) = 1;
          NvRaidTimerQueueEvent
                    (*(longlong *)(*(longlong *)(param_2 + 0x40) + 0x18),1,uVar6,param_2,
                     *(longlong *)(param_2 + 0x40));
          return 0x103;
        }
        goto LAB_000133ef;
      }
    }
    else if (*(byte *)(lVar3 + 0x14) == bVar1) goto LAB_0001342b;
    uVar5 = 0x80000011;
  }
  return uVar5;
}



===== NvRaidJobClearInformation @ 000134e8 =====

void NvRaidJobClearInformation(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x58);
  lVar3 = 0;
  *(undefined1 *)(lVar1 + 0x14) = 0;
  lVar2 = *(longlong *)(param_1 + 0x58);
  *(undefined8 *)(lVar2 + 0x58) = 0;
  *(undefined4 *)(lVar2 + 0x34) = 0;
  NvRaidResArrayGenerateSignature((uint *)(lVar1 + 4));
  NvRaidJobScheduleRequest(param_1,1,0,0,lVar3,lVar3);
  return;
}



===== FUN_00013530 @ 00013530 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00013530(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  uint uVar11;
  longlong lVar12;
  byte bVar13;
  ulonglong uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  
  lVar3 = *(longlong *)(param_1 + 0x58);
  lVar12 = *(longlong *)(*(longlong *)(param_2 + 0x40) + 0x58);
  NvRaidResNrpFreePacketResources(*(longlong *)(param_1 + 0x18),param_2);
  puVar7 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
  if (puVar7 == (undefined8 *)0x0) goto LAB_00013843;
  *puVar7 = 0;
  puVar7[1] = *(undefined8 *)(param_2 + 0x28);
  **(undefined8 **)(param_2 + 0x28) = puVar7;
  *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
  *(undefined8 **)(param_2 + 0x28) = puVar7;
  puVar7[0xd] = param_2;
  puVar7[0xe] = *(undefined8 *)(param_2 + 0x40);
  uVar1 = *(undefined1 *)(param_1 + 8);
  puVar7[8] = param_1;
  *(undefined1 *)(puVar7 + 9) = uVar1;
  puVar7[0x14] = NvRaidStateSubRequestsDone;
  if (*(char *)(lVar3 + 0x14) == '\x04') {
    *(undefined8 *)(param_2 + 0x98) = *(undefined8 *)(lVar12 + 0x50);
    if (*(int *)(lVar3 + 0x18) == 0x81) {
      *(undefined4 *)(param_2 + 0x84) = 0x1000081;
    }
    *(uint *)(puVar7 + 0xc) = *(uint *)(puVar7 + 0xc) | 0x10;
  }
  else {
    *(undefined8 *)(param_2 + 0x98) = *(undefined8 *)(param_1 + 0x20);
  }
  uVar15 = *(uint *)(lVar3 + 0x2c);
  uVar16 = *(uint *)(lVar3 + 0x1c);
  if (gScratchBufCount == 0) {
    uVar5 = 0x10000;
  }
  else {
    uVar11 = 8 - _DAT_0002907c;
    if (uVar11 == 0) {
      uVar11 = 1;
    }
    uVar5 = DAT_000290b0;
    if (DAT_000290b0 <= uVar11) {
      uVar5 = DAT_000290b0 / uVar11;
    }
    uVar5 = uVar5 << 9;
  }
  cVar2 = *(char *)(lVar3 + 0x14);
  if (cVar2 == '\x02') {
LAB_00013682:
    uVar11 = uVar16;
  }
  else {
    uVar11 = uVar15;
    if (cVar2 == '\x03') {
      if ((*(int *)(lVar3 + 0x18) == 0x8180) || (*(int *)(lVar3 + 0x18) == 0x81)) goto LAB_00013682;
    }
    else {
      if (cVar2 == '\x04') {
        uVar15 = *(byte *)(lVar3 + 0x17) * uVar16;
      }
      else {
        if (cVar2 != '\x05') goto LAB_00013843;
        if (*(int *)(lVar3 + 0x18) != 0x8180) goto LAB_00013685;
      }
      uVar16 = uVar15;
      uVar11 = uVar15;
    }
  }
LAB_00013685:
  uVar17 = uVar15;
  if (uVar15 < uVar5 >> 9) {
    uVar17 = uVar5 >> 9;
  }
  if (*(int *)(lVar3 + 0x18) == 0x81) {
    uVar17 = uVar17 << 2;
  }
  else {
    uVar17 = uVar17 * 2;
  }
  lVar4 = *(longlong *)(param_1 + 0x58);
  uVar14 = (ulonglong)uVar15;
  uVar8 = (*(ulonglong *)(lVar12 + 0x58) / uVar14) * uVar14;
  *(ulonglong *)(lVar4 + 0x58) = uVar8;
  uVar6 = (undefined4)uVar8;
  if (0xffffffff < uVar8) {
    uVar6 = 0;
  }
  *(undefined4 *)(lVar4 + 0x34) = uVar6;
  if (*(longlong *)(param_2 + 0x88) == 0) {
    *(longlong *)(param_2 + 0x88) = *(longlong *)(param_2 + 0x98) - *(longlong *)(lVar12 + 0x58);
  }
  uVar9 = ((ulonglong)(uVar15 - 1) + *(longlong *)(param_2 + 0x88)) / uVar14;
  uVar8 = (ulonglong)uVar17 / (ulonglong)uVar11;
  if ((int)uVar8 == 0) {
    uVar8 = 1;
  }
  iVar18 = (int)uVar8;
  if (uVar9 < uVar8) {
    iVar18 = (int)uVar9;
  }
  *(ulonglong *)(param_2 + 0x88) = uVar14 * uVar9;
  *(ulonglong *)(param_2 + 0x90) = (ulonglong)(iVar18 * uVar15);
  iVar19 = iVar18 * uVar16;
  if (*(char *)(lVar3 + 0x14) == '\x04') {
    NvRaidScsiSetupReadWrite
              ((longlong)puVar7,*(undefined1 *)(param_1 + 8),param_1,NvRaidStateSubRequestsDone,0x2a
               ,*(undefined8 *)(lVar12 + 0x58),iVar19);
  }
  else {
    *(undefined1 *)(puVar7 + 0x10) = 0xff;
    uVar8 = *(ulonglong *)(lVar12 + 0x58);
    *(int *)(puVar7 + 0x12) = iVar18;
    puVar7[0x13] = uVar9;
    puVar7[0x11] = uVar8 / uVar14;
  }
  if (*(char *)(lVar3 + 0x14) == '\x03') {
    *(undefined1 *)((longlong)puVar7 + 0x82) = 0xff;
    bVar13 = 0;
    if (*(byte *)(lVar3 + 0x16) != 0) {
      do {
        if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)bVar13)) {
          lVar12 = 0;
        }
        else {
          lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)(uint)bVar13 * 8);
        }
        if (((lVar12 == 0) || ((*(uint *)(lVar12 + 4) & 1) != 0)) ||
           ((*(uint *)(lVar12 + 4) >> 8 & 1) != 0)) {
          lVar12 = 0;
        }
        if (lVar12 == 0) {
          *(byte *)((longlong)puVar7 + 0x82) = bVar13;
          break;
        }
        bVar13 = bVar13 + 1;
      } while (bVar13 < *(byte *)(lVar3 + 0x16));
    }
    if (*(char *)((longlong)puVar7 + 0x82) == -1) goto LAB_00013843;
  }
  uVar10 = NvRaidResBufferAllocateForNrp(*(longlong *)(param_1 + 0x18),iVar19 * 0x200,param_2);
  if (-1 < (int)uVar10) {
    puVar7[0x15] = *(undefined8 *)(param_2 + 0xa8);
    if (*(char *)(lVar3 + 0x14) == '\x02') {
      NvRaidPacketScatterGatherGroupZero(*(longlong *)(param_2 + 0xa8),0,iVar19);
    }
    *(undefined1 *)(param_2 + 0x56) = 3;
    return 0;
  }
LAB_00013843:
  *(undefined1 *)(param_2 + 0x56) = 6;
  return 0;
}



===== FUN_00013868 @ 00013868 =====

undefined8 FUN_00013868(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  
  uVar1 = *(ulonglong *)(param_2 + 0x90);
  if (*(ulonglong *)(param_2 + 0x88) < *(ulonglong *)(param_2 + 0x90)) {
    uVar1 = *(ulonglong *)(param_2 + 0x88);
  }
  *(ulonglong *)(param_2 + 0x90) = uVar1;
  *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
  NvRaidApiFireEvent(param_1,0x82,0);
  return 0;
}



===== FUN_000139a8 @ 000139a8 =====

undefined8 FUN_000139a8(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  
  *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x02';
  *(undefined4 *)(param_2 + 0x50) = 0xc0000001;
  puVar2 = *(undefined8 **)(param_2 + 0x20);
  do {
    puVar3 = puVar2;
    if (puVar3 == (undefined8 *)0x0) goto LAB_000139f5;
    puVar2 = (undefined8 *)*puVar3;
  } while (*(int *)(puVar3 + 10) == 0);
  *(undefined4 *)(param_2 + 0x50) = *(undefined4 *)(puVar3 + 10);
  *(undefined1 *)(param_2 + 0x4b) = *(undefined1 *)((longlong)puVar3 + 0x4b);
  *(undefined1 *)(param_2 + 0x4c) = *(undefined1 *)((longlong)puVar3 + 0x4c);
  *(undefined1 *)(param_2 + 0x4d) = *(undefined1 *)((longlong)puVar3 + 0x4d);
  *(undefined1 *)(param_2 + 0x4e) = *(undefined1 *)((longlong)puVar3 + 0x4e);
LAB_000139f5:
  NvRaidApiFireEvent(param_1,0x12,param_2);
  NvRaidStripeLockRelease(param_1);
  lVar1 = *(longlong *)(param_1 + 0x58);
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffffbf;
  if ((*(char *)(lVar1 + 0x14) == '\x03') && (lVar1 != 0)) {
    NvRaidResArrayGenerateSignature((uint *)(lVar1 + 4));
    NvRaidJobScheduleRequest(param_1,1,0,1,0,0);
  }
  return 0;
}



===== FUN_00013ad0 @ 00013ad0 =====

undefined8 FUN_00013ad0(longlong param_1,longlong param_2)

{
  NvRaidStripeLockRelease(param_1);
  *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
  return 0;
}



===== FUN_00013b20 @ 00013b20 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_00013b20(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  undefined1 auVar4 [16];
  bool bVar5;
  char cVar6;
  undefined4 uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  longlong lVar11;
  undefined1 uVar12;
  byte bVar13;
  longlong lVar14;
  byte bVar15;
  undefined1 auStackY_88 [32];
  longlong local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_88;
  lVar3 = *(longlong *)(param_1 + 0x58);
  lVar11 = *(longlong *)(*(longlong *)(param_2 + 0x40) + 0x58);
  local_50 = 0xe;
  local_4c = 0xb;
  local_48 = 0x11;
  local_44 = 0x15;
  bVar5 = false;
  bVar15 = 0;
  local_58 = *(longlong *)(param_1 + 0x18);
  auVar4._8_8_ = 0;
  auVar4._0_8_ = *(ulonglong *)(param_2 + 0x98);
  lVar10 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar4,8);
  uVar9 = (*(ulonglong *)(param_2 + 0x98) - lVar10 >> 1) + lVar10 >> 6;
  uVar8 = *(ulonglong *)(lVar11 + 0x58) / uVar9;
  if (100 < uVar8) {
    uVar8 = 100;
  }
  if (*(ulonglong *)(lVar11 + 0x58) % uVar9 <= *(ulonglong *)(param_2 + 0x90)) {
    NvRaidApiFireEvent(param_1,*(undefined4 *)
                                ((longlong)&local_58 + (ulonglong)*(byte *)(lVar3 + 0x14) * 4),
                       uVar8 & 0xffffffff);
  }
  lVar10 = *(longlong *)(param_2 + 0x20);
  if ((*(uint *)(param_1 + 4) & 0x10401) == 0) {
    plVar1 = (longlong *)(param_2 + 0x88);
    *plVar1 = *plVar1 - *(longlong *)(param_2 + 0x90);
    if (*plVar1 != 0) {
      *(undefined1 *)(param_2 + 0x56) = *(undefined1 *)(param_2 + 0x82);
      return 0;
    }
  }
  local_50 = 0xd;
  local_4c = 10;
  local_48 = 0x10;
  local_44 = 0x14;
  iVar2 = *(int *)((longlong)&local_58 + (ulonglong)*(byte *)(lVar3 + 0x14) * 4);
  lVar14 = local_58;
  if (*(longlong *)(param_2 + 0x98) == *(longlong *)(lVar11 + 0x58)) {
    if (*(byte *)(lVar3 + 0x14) == 4) {
      *(int *)(lVar3 + 0x38) = *(int *)(lVar3 + 0x18);
      *(char *)(lVar3 + 0x17) = *(char *)(lVar3 + 0x15);
      cVar6 = NvRaidCalculateRequiredVolumes(*(int *)(lVar3 + 0x18),*(char *)(lVar3 + 0x15));
      *(char *)(lVar3 + 0x16) = cVar6;
      *(longlong *)(lVar3 + 0x90) = *(longlong *)(lVar3 + 0x88);
      *(longlong *)(param_1 + 0x60) = *(longlong *)(lVar3 + 0x88) + 0x18;
    }
    if (((*(ulonglong *)(param_2 + 0x98) < *(ulonglong *)(param_1 + 0x20)) &&
        (*(int *)(lVar3 + 0x18) != 0x80)) && (*(int *)(lVar3 + 0x18) != 0xff)) {
      *(undefined1 *)(lVar3 + 0x14) = 5;
      bVar5 = true;
      uVar8 = (*(ulonglong *)(lVar11 + 0x58) / (ulonglong)*(uint *)(lVar3 + 0x2c)) *
              (ulonglong)*(uint *)(lVar3 + 0x2c);
      lVar11 = *(longlong *)(param_1 + 0x58);
      *(ulonglong *)(lVar11 + 0x58) = uVar8;
      uVar7 = (undefined4)uVar8;
      if (0xffffffff < uVar8) {
        uVar7 = 0;
      }
      *(undefined4 *)(lVar11 + 0x34) = uVar7;
    }
    if (*(char *)(lVar3 + 0x14) == '\x03') {
      if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)*(byte *)(lVar10 + 0x82))) {
        lVar11 = 0;
      }
      else {
        lVar11 = *(longlong *)
                  (*(longlong *)(param_1 + 0x80) + (ulonglong)*(byte *)(lVar10 + 0x82) * 8);
      }
      *(uint *)(lVar11 + 4) = *(uint *)(lVar11 + 4) & 0xfffffeff;
      bVar15 = 1;
    }
    bVar13 = 0;
    if (*(char *)(lVar3 + 0x16) != '\0') {
      do {
        if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)bVar13)) {
          lVar11 = 0;
        }
        else {
          lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)(uint)bVar13 * 8);
        }
        if (bVar15 == 0) {
          *(uint *)(lVar11 + 4) = *(uint *)(lVar11 + 4) & 0xfffffeff;
        }
        else if ((*(uint *)(lVar11 + 4) & 0x100) != 0) {
          bVar15 = bVar15 + 1;
          break;
        }
        bVar13 = bVar13 + 1;
      } while (bVar13 < *(byte *)(lVar3 + 0x16));
    }
    if ((!bVar5) && (bVar15 < 2)) {
      *(uint *)(lVar3 + 0x40) = *(uint *)(lVar3 + 0x40) | 4;
      *(undefined1 *)(lVar3 + 0x14) = 0;
    }
  }
  NvRaidResNrpFreePacketResources(lVar14,param_2);
  if (1 < bVar15) {
    *(undefined1 *)(param_2 + 0x56) = 0;
    lVar3 = *(longlong *)(param_1 + 0x58);
    *(undefined8 *)(lVar3 + 0x58) = 0;
    *(undefined4 *)(lVar3 + 0x34) = 0;
    return 0;
  }
  if ((*(uint *)(param_1 + 4) & 0x400) == 0) {
    NvRaidPacketCompleteRequest(param_2);
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffffbf;
    (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x58) + 0x88) + 0x30))(param_1,1);
    uVar12 = 1;
    if (bVar5) {
      uVar12 = 5;
    }
    NvRaidJobScheduleRequest(param_1,uVar12,0,0,0,0);
    if (iVar2 != 0) {
      NvRaidApiFireEvent(param_1,iVar2,0);
    }
  }
  else {
    *(int *)(param_2 + 0xb4) = iVar2;
    (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x58) + 0x88) + 0x30))(param_1,1);
    uVar12 = 1;
    if (bVar5) {
      uVar12 = 5;
    }
    NvRaidJobScheduleRequest(param_1,uVar12,0,0,param_2,FUN_00013e6c);
  }
  return 0x103;
}



===== FUN_00013e6c @ 00013e6c =====

undefined8 FUN_00013e6c(longlong param_1,longlong param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0xb4);
  NvRaidPacketCompleteRequest(param_2);
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffffbf;
  if (iVar1 != 0) {
    NvRaidApiFireEvent(param_1,iVar1,0);
  }
  return 0x103;
}



===== FUN_00013eac @ 00013eac =====

undefined8 FUN_00013eac(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  byte bVar6;
  byte bVar7;
  ulonglong uVar8;
  longlong lVar9;
  
  lVar2 = *(longlong *)(param_1 + 0x58);
  lVar3 = *(longlong *)(param_2 + 0x88);
  iVar1 = *(int *)(param_2 + 0x90);
  uVar8 = 0;
  bVar6 = (byte)*(undefined4 *)(lVar2 + 0x24);
  if (*(char *)(lVar2 + 0x16) != '\0') {
    do {
      if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)uVar8)) {
        lVar9 = 0;
      }
      else {
        lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x80) + uVar8 * 8);
      }
      if (((lVar9 == 0) || ((*(uint *)(lVar9 + 4) & 1) != 0)) ||
         ((*(uint *)(lVar9 + 4) >> 8 & 1) != 0)) {
        lVar9 = 0;
      }
      if (lVar9 != 0) {
        puVar5 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
        if (puVar5 == (undefined8 *)0x0) {
          return 0xc000009a;
        }
        NvRaidScsiSetupReadWrite
                  ((longlong)puVar5,*(undefined1 *)(lVar9 + 8),lVar9,NvRaidStateSubRequestsDone,0x2a
                   ,lVar3 << (bVar6 & 0x3f),iVar1 << (bVar6 & 0x1f));
        uVar4 = *(undefined8 *)(param_2 + 0xa8);
        *puVar5 = 0;
        puVar5[0x15] = uVar4;
        puVar5[1] = *(undefined8 *)(param_2 + 0x28);
        **(undefined8 **)(param_2 + 0x28) = puVar5;
        *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
        *(undefined8 **)(param_2 + 0x28) = puVar5;
        puVar5[0xd] = param_2;
        puVar5[0xe] = *(undefined8 *)(param_2 + 0x40);
      }
      bVar7 = (char)uVar8 + 1;
      uVar8 = (ulonglong)bVar7;
    } while (bVar7 < *(byte *)(lVar2 + 0x16));
  }
  *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
  NvRaidPacketSubmitSubRequests((longlong *)(param_2 + 0x20));
  return 0x103;
}



===== FUN_00013fe4 @ 00013fe4 =====

undefined8 FUN_00013fe4(longlong param_1,longlong param_2)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  byte bVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  longlong lVar10;
  byte bVar11;
  longlong local_res8;
  
  lVar3 = *(longlong *)(param_1 + 0x58);
  if ((*(uint *)(param_1 + 4) >> 10 & 1) == 0) {
    puVar1 = (uint *)(param_1 + 0x78);
    while (*puVar1 < (uint)*(byte *)(lVar3 + 0x16)) {
      if (gRaidConfig == '\x01') {
        *(undefined1 *)(lVar3 + 0x14) = 0;
        (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x58) + 0x88) + 0x30))(param_1,1);
        *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffffbf | 0x8000;
        goto LAB_00014269;
      }
      local_res8 = 0;
      lVar4 = *(longlong *)(param_1 + 0x18);
      do {
        NvRaidApiEnumerateRootVolumes(lVar4,&local_res8);
        lVar10 = local_res8;
        if (local_res8 == 0) {
          lVar3 = *(longlong *)(param_2 + 0x40);
          lVar4 = *(longlong *)(lVar3 + 0x18);
          puVar6 = (undefined8 *)NvRaidResResourceAllocate((longlong *)(lVar4 + 0xb0),0x30);
          if (puVar6 == (undefined8 *)0x0) {
            DbgPrint("NvRaidTimerQueueEvent: Failed to allocate TimerEvent\n");
            return 0x103;
          }
          puVar6[3] = param_2;
          *(undefined4 *)(puVar6 + 4) = 0x3c;
          puVar6[2] = FUN_00011e84;
          puVar6[5] = lVar3;
          puVar9 = *(undefined8 **)(lVar4 + 0xa0);
          while( true ) {
            if (puVar9 == (undefined8 *)0x0) {
              *puVar6 = 0;
              puVar6[1] = *(undefined8 *)(lVar4 + 0xa8);
              **(undefined8 **)(lVar4 + 0xa8) = puVar6;
              *(undefined8 **)(lVar4 + 0xa8) = puVar6;
              return 0x103;
            }
            uVar2 = *(uint *)(puVar6 + 4);
            if (uVar2 < *(uint *)(puVar9 + 4)) break;
            *(uint *)(puVar6 + 4) = uVar2 - *(uint *)(puVar9 + 4);
            puVar9 = (undefined8 *)*puVar9;
          }
          *(uint *)(puVar9 + 4) = *(int *)(puVar9 + 4) - uVar2;
          uVar5 = puVar9[1];
          *puVar6 = puVar9;
          puVar6[1] = uVar5;
          *(undefined8 **)puVar9[1] = puVar6;
          puVar9[1] = puVar6;
          return 0x103;
        }
      } while (((*(longlong *)(local_res8 + 0x58) != 0) ||
               ((*(uint *)(local_res8 + 4) & 0x107) != 0x102)) ||
              (*(ulonglong *)(local_res8 + 0x20) <
               *(ulonglong *)(param_1 + 0x20) / (ulonglong)*(byte *)(lVar3 + 0x15)));
      NvRaidApiFireEvent(param_1,7,local_res8);
      NvRaidVolumeAddVolumeToArray(param_1,lVar10,0xff);
    }
    bVar11 = *(byte *)(lVar3 + 0x16);
    lVar4 = *(longlong *)(param_1 + 0x80);
    uVar8 = 0;
    if (bVar11 != 0) {
      do {
        if ((puVar1 == (uint *)0x0) || (*(uint *)(param_1 + 0x7c) <= (uint)uVar8)) {
          lVar10 = 0;
        }
        else {
          lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x80) + uVar8 * 8);
        }
        if (lVar10 == 0) {
          while( true ) {
            if (*(uint *)(param_1 + 0x7c) <= (uint)bVar11) break;
            if ((puVar1 == (uint *)0x0) || (*(uint *)(param_1 + 0x7c) <= (uint)bVar11)) {
              lVar10 = 0;
            }
            else {
              lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)bVar11 * 8);
            }
            if (lVar10 != 0) {
              *(longlong *)(lVar4 + uVar8 * 8) = lVar10;
              *(char *)(lVar10 + 8) = (char)uVar8;
              *(undefined8 *)(lVar4 + (ulonglong)bVar11 * 8) = 0;
              break;
            }
            bVar11 = bVar11 + 1;
          }
        }
        bVar7 = (char)uVar8 + 1;
        uVar8 = (ulonglong)bVar7;
      } while (bVar7 < *(byte *)(lVar3 + 0x16));
    }
    *(undefined1 *)(lVar3 + 0x14) = 0;
    (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x58) + 0x88) + 0x30))(param_1,1);
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffffbf;
    NvRaidJobScheduleRequest(param_1,3,0,1,0,0);
LAB_00014269:
    *(undefined4 *)(param_2 + 0x50) = 0;
  }
  else {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffffbf | 0x4000;
    *(undefined4 *)(param_2 + 0x50) = 0;
  }
  NvRaidPacketCompleteRequest(param_2);
  return 0x103;
}



===== NvRaidRemoveFailedVolumeFromArray @ 00014294 =====

ulonglong NvRaidRemoveFailedVolumeFromArray(undefined4 *param_1,longlong param_2)

{
  byte bVar1;
  undefined4 *in_RAX;
  undefined8 uVar2;
  longlong lVar3;
  
  if (param_2 != 0) {
    bVar1 = *(byte *)(param_2 + 8);
    in_RAX = param_1 + 0x1e;
    if ((in_RAX == (undefined4 *)0x0) || ((uint)param_1[0x1f] <= (uint)bVar1)) {
      lVar3 = 0;
    }
    else {
      in_RAX = *(undefined4 **)(param_1 + 0x20);
      lVar3 = *(longlong *)(in_RAX + (ulonglong)bVar1 * 2);
    }
    if (((lVar3 == param_2) && (*(char *)(*(longlong *)(param_1 + 0x16) + 0x14) == '\0')) &&
       (in_RAX = (undefined4 *)
                 (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x16) + 0x88) + 0x30))
                           (param_1,(uint)bVar1 << 8 | 2), ((ulonglong)in_RAX & 1) == 0)) {
      *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffff9 | 1;
      uVar2 = NvRaidVolumeDeleteVolumeFromArray(param_1,param_2);
      param_1[1] = param_1[1] | 0x200;
      return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
    }
  }
  return (ulonglong)in_RAX & 0xffffffffffffff00;
}



===== NvRaidResNrpAllocate @ 0001431c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * NvRaidResNrpAllocate(longlong param_1)

{
  void *_Dst;
  
  _DAT_00029080 = _DAT_00029080 + -1;
  _Dst = (void *)NvRaidResResourceAllocate((longlong *)(param_1 + 0xb8),0xf0);
  if (_Dst == (void *)0x0) {
    _DAT_00029080 = _DAT_00029080 + 1;
  }
  else {
    memset(_Dst,0,0xf0);
    *(undefined8 *)((longlong)_Dst + 0x20) = 0;
    *(undefined8 **)((longlong)_Dst + 0x28) = (undefined8 *)((longlong)_Dst + 0x20);
    *(undefined8 *)((longlong)_Dst + 0xd0) = 0;
    *(undefined8 **)((longlong)_Dst + 0xd8) = (undefined8 *)((longlong)_Dst + 0xd0);
  }
  return _Dst;
}



===== NvRaidResNrpFree @ 00014380 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void NvRaidResNrpFree(longlong param_1,undefined4 *param_2)

{
  if (*(char *)(param_2 + 0x2c) != '\0') {
    NvRaidParityLockRelease
              ((longlong)param_2,*(ulonglong *)(param_2 + 0x2e),*(longlong *)(param_2 + 0x10));
  }
  NvRaidResNrpFreePacketResources(param_1,(longlong)param_2);
  _DAT_00029080 = _DAT_00029080 + 1;
  *param_2 = 0xf0;
  *(undefined8 *)(param_2 + 2) = *(undefined8 *)(param_1 + 0xb8);
  *(undefined4 **)(param_1 + 0xb8) = param_2;
  return;
}



===== NvRaidResNrpFreePacketResources @ 000143e0 =====

void NvRaidResNrpFreePacketResources(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  ulonglong uVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  NvRaidResNrpFreeSubReqs(param_1,param_2);
  if ((*(uint *)(param_2 + 0x60) >> 9 & 1) != 0) {
    uVar5 = 0;
    *(uint *)(param_2 + 0x60) = *(uint *)(param_2 + 0x60) & 0xfffffdff;
    if (*(short *)(*(longlong *)(param_2 + 0xa8) + 4) != 0) {
      do {
        lVar2 = *(longlong *)(param_2 + 0xa8);
        uVar7 = (uint)uVar5;
        uVar3 = (uint)*(ushort *)(lVar2 + 6);
        if (*(ushort *)(lVar2 + 6) <= uVar7) {
          do {
            lVar2 = *(longlong *)(lVar2 + 8);
            uVar4 = (int)uVar5 - uVar3;
            uVar5 = (ulonglong)uVar4;
            uVar3 = (uint)*(ushort *)(lVar2 + 6);
          } while (uVar3 <= uVar4);
        }
        NvRaidResBufferFree(param_1,*(undefined4 **)(lVar2 + 0x18 + uVar5 * 0x10),
                            *(int *)(lVar2 + 0x20 + uVar5 * 0x10));
        uVar7 = uVar7 + 1;
        uVar5 = (ulonglong)uVar7;
      } while (uVar7 < *(ushort *)(*(longlong *)(param_2 + 0xa8) + 4));
    }
  }
  if ((*(uint *)(param_2 + 0x60) >> 8 & 1) != 0) {
    *(uint *)(param_2 + 0x60) = *(uint *)(param_2 + 0x60) & 0xfffffeff;
    if (*(undefined4 **)(param_2 + 0xa8) != (undefined4 *)0x0) {
      puVar6 = *(undefined4 **)(param_2 + 0xa8);
      do {
        puVar1 = *(undefined4 **)(puVar6 + 2);
        *puVar6 = 0xb8;
        *(undefined8 *)(puVar6 + 2) = *(undefined8 *)(param_1 + 0xd8);
        DAT_00029060 = DAT_00029060 + 1;
        *(undefined4 **)(param_1 + 0xd8) = puVar6;
        puVar6 = puVar1;
      } while (puVar1 != (undefined4 *)0x0);
    }
    *(undefined8 *)(param_2 + 0xa8) = 0;
  }
  return;
}



===== NvRaidResNrpFreeSubReqs @ 000144d4 =====

void NvRaidResNrpFreeSubReqs(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  
  plVar1 = *(longlong **)(param_2 + 0x20);
  while (plVar1 != (longlong *)0x0) {
    if (*plVar1 == 0) {
      *(longlong *)(param_2 + 0x28) = plVar1[1];
    }
    else {
      *(longlong *)(*plVar1 + 8) = plVar1[1];
    }
    *(longlong *)plVar1[1] = *plVar1;
    NvRaidResNrpFree(param_1,(undefined4 *)plVar1);
    plVar1 = *(longlong **)(param_2 + 0x20);
  }
  return;
}



===== NvRaidResBufferAllocate @ 00014528 =====

longlong NvRaidResBufferAllocate(longlong param_1,uint param_2)

{
  longlong lVar1;
  
  if (gScratchBufCount == 0) {
    lVar1 = ExAllocatePoolWithTag(0,param_2,0x644e7652);
    if (lVar1 != 0) {
      DAT_000290b0 = DAT_000290b0 + param_2;
    }
  }
  else if (param_2 < 0x201) {
    DAT_000290b0 = DAT_000290b0 + -1;
    lVar1 = NvRaidResResourceAllocate((longlong *)(param_1 + 0xc0),0x200);
    if (lVar1 == 0) {
      DAT_000290b0 = DAT_000290b0 + 1;
    }
  }
  else {
    lVar1 = 0;
  }
  return lVar1;
}



===== NvRaidResBufferAllocateForNrp @ 00014588 =====

undefined8 NvRaidResBufferAllocateForNrp(longlong param_1,uint param_2,longlong param_3)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  
  puVar1 = *(undefined4 **)(param_3 + 0xa8);
  lVar3 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = NvRaidResSgGroupAllocateForNrp(param_1,param_3);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
  }
  else {
    *puVar1 = 2;
    *(undefined2 *)(puVar1 + 1) = 0;
  }
  for (; param_2 != 0; param_2 = param_2 - uVar4) {
    if (gScratchBufCount == 0) {
      uVar4 = param_2;
    }
    else {
      uVar4 = 0x200;
      if (param_2 < 0x200) {
        uVar4 = param_2;
      }
    }
    lVar3 = NvRaidResBufferAllocate(param_1,uVar4);
    if (lVar3 == 0) break;
    NvRaidPacketScatterGatherElementAdd(*(longlong *)(param_3 + 0xa8),lVar3,uVar4);
  }
  *(uint *)(param_3 + 0x60) = *(uint *)(param_3 + 0x60) | 0x200;
  if (lVar3 == 0) {
    NvRaidResNrpFreePacketResources(param_1,param_3);
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



===== NvRaidResBufferFree @ 00014650 =====

void NvRaidResBufferFree(longlong param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (gScratchBufCount == 0) {
    DAT_000290b0 = DAT_000290b0 - param_3;
    ExFreePoolWithTag(param_2,0);
    if ((DAT_000290b4 & 8) == 0) {
      uVar1 = DAT_000290b4 | 8;
      while( true ) {
        uVar2 = uVar1;
        LOCK();
        UNLOCK();
        uVar1 = DAT_000290b4 | 8;
        DAT_000290b4 = uVar2;
        if (uVar1 == uVar2) break;
      }
    }
  }
  else {
    DAT_000290b0 = DAT_000290b0 + 1;
    *param_2 = 0x200;
    *(undefined8 *)(param_2 + 2) = *(undefined8 *)(param_1 + 0xc0);
    *(undefined4 **)(param_1 + 0xc0) = param_2;
  }
  return;
}



===== NvRaidResArrayAllocate @ 000146b8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * NvRaidResArrayAllocate(longlong param_1)

{
  void *_Dst;
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  
  _DAT_0002907c = _DAT_0002907c + -1;
  _Dst = (void *)NvRaidResResourceAllocate((longlong *)(param_1 + 0xd0),0x3b8);
  if (_Dst == (void *)0x0) {
    _DAT_0002907c = _DAT_0002907c + 1;
  }
  else {
    memset(_Dst,0,0x3b8);
    plVar1 = (longlong *)((longlong)_Dst + 200);
    lVar2 = (longlong)_Dst + 0xc0;
    lVar3 = 0x20;
    do {
      plVar1[-2] = 0;
      plVar1[-1] = 0;
      *plVar1 = lVar2;
      lVar2 = lVar2 + 0x18;
      plVar1 = plVar1 + 3;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
  }
  return _Dst;
}



===== NvRaidResArrayGenerateSignature @ 0001472c =====

undefined8 NvRaidResArrayGenerateSignature(uint *param_1)

{
  longlong lVar1;
  
  lVar1 = 4;
  do {
    DAT_00029088 = DAT_00029088 * 0x41a7 + (DAT_00029088 / 0x1f31d) * -0x7fffffff;
    if (DAT_00029088 == 0) {
      DAT_00029088 = 0x7fffffff;
    }
    *param_1 = DAT_00029088;
    param_1 = param_1 + 1;
    lVar1 = lVar1 + -1;
  } while (lVar1 != 0);
  return 0;
}



===== NvRaidResSgGroupAllocate @ 0001477c =====

void * NvRaidResSgGroupAllocate(longlong param_1)

{
  void *_Dst;
  
  DAT_00029060 = DAT_00029060 + -1;
  _Dst = (void *)NvRaidResResourceAllocate((longlong *)(param_1 + 0xd8),0xb8);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0xb8);
    *(longlong *)((longlong)_Dst + 0x10) = param_1;
    *(undefined2 *)((longlong)_Dst + 6) = 10;
  }
  return _Dst;
}



===== NvRaidResSgGroupAllocateForNrp @ 000147d4 =====

undefined8 NvRaidResSgGroupAllocateForNrp(longlong param_1,longlong param_2)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  puVar1 = NvRaidResSgGroupAllocate(param_1);
  *(undefined4 **)(param_2 + 0xa8) = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    *puVar1 = 2;
    *(undefined2 *)(puVar1 + 1) = 0;
    *(uint *)(param_2 + 0x60) = *(uint *)(param_2 + 0x60) | 0x100;
    uVar2 = 0;
  }
  return uVar2;
}



===== NvRaidResResourceAllocate @ 00014810 =====

longlong NvRaidResResourceAllocate(longlong *param_1,undefined4 param_2)

{
  longlong lVar1;
  
  lVar1 = *param_1;
  if (lVar1 == 0) {
    lVar1 = ExAllocatePoolWithTag(0,param_2,0x644e7652);
  }
  else {
    *param_1 = *(longlong *)(lVar1 + 8);
  }
  return lVar1;
}



===== NvRaidResResourceCleanup @ 00014840 =====

void NvRaidResResourceCleanup(longlong *param_1)

{
  longlong lVar1;
  
  lVar1 = *param_1;
  while (lVar1 != 0) {
    *param_1 = *(longlong *)(lVar1 + 8);
    ExFreePoolWithTag(lVar1,0);
    lVar1 = *param_1;
  }
  return;
}



===== NvRaidResQueueLowResourceNrp @ 00014870 =====

undefined8 NvRaidResQueueLowResourceNrp(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = NvRaidSyncSpinLockAcquire(0xffffffff);
  puVar1 = (uint *)(*(longlong *)(param_1 + 0x40) + 4);
  *puVar1 = *puVar1 | 0x800;
  *(undefined8 *)(param_1 + 0x10) = 0;
  *(undefined **)(param_1 + 0x18) = PTR_DAT_00029070;
  *(longlong *)PTR_DAT_00029070 = param_1;
  PTR_DAT_00029070 = (undefined *)(param_1 + 0x10);
  NvRaidSyncSpinLockRelease(uVar2);
  return 0;
}



===== NvRaidResResourceIsr @ 000148c0 =====

void NvRaidResResourceIsr(void)

{
  uint *puVar1;
  longlong lVar2;
  uint uVar3;
  longlong local_18;
  longlong *plStack_10;
  
  uVar3 = NvRaidSyncSpinLockAcquire(0xffffffff);
  if (DAT_00029068 == 0) {
    local_18 = 0;
    plStack_10 = &local_18;
  }
  else {
    local_18 = DAT_00029068;
    plStack_10 = (longlong *)PTR_DAT_00029070;
    *(longlong **)(DAT_00029068 + 0x18) = &local_18;
  }
  DAT_00029068 = 0;
  PTR_DAT_00029070 = (undefined *)&DAT_00029068;
  while (local_18 != 0) {
    if (*(longlong *)(local_18 + 0x10) == 0) {
      plStack_10 = *(longlong **)(local_18 + 0x18);
    }
    else {
      *(longlong **)(*(longlong *)(local_18 + 0x10) + 0x18) = *(longlong **)(local_18 + 0x18);
    }
    **(undefined8 **)(local_18 + 0x18) = *(undefined8 *)(local_18 + 0x10);
    lVar2 = *(longlong *)(local_18 + 0x40);
    puVar1 = (uint *)(lVar2 + 4);
    *puVar1 = *puVar1 & 0xfffff7ff;
    NvRaidPacketExecuteStateMachine(*(undefined8 *)(local_18 + 0x40),local_18);
    if ((*(uint *)(lVar2 + 4) & 0x800) != 0) {
      if (local_18 != 0) {
        *(longlong *)PTR_DAT_00029070 = local_18;
        *(undefined **)(local_18 + 0x18) = PTR_DAT_00029070;
        PTR_DAT_00029070 = (undefined *)plStack_10;
      }
      plStack_10 = &local_18;
      local_18 = 0;
    }
  }
  NvRaidSyncSpinLockRelease(uVar3);
  return;
}



===== NvRaidScsiSetupReadWrite @ 000149cc =====

undefined8
NvRaidScsiSetupReadWrite
          (longlong param_1,undefined1 param_2,longlong param_3,undefined8 param_4,byte param_5,
          undefined8 param_6,undefined4 param_7)

{
  *(longlong *)(param_1 + 0x40) = param_3;
  *(undefined1 *)(param_1 + 0x48) = param_2;
  if (param_3 != 0) {
    *(undefined1 *)(param_1 + 0x48) = *(undefined1 *)(param_3 + 8);
  }
  *(undefined8 *)(param_1 + 0xa0) = param_4;
  *(undefined1 *)(param_1 + 0x4a) = 5;
  *(byte *)(param_1 + 0x80) = param_5;
  if (param_5 < 0x36) {
    if (param_5 == 0x35) {
LAB_00014a4e:
      *(undefined1 *)(param_1 + 0x82) = 4;
      goto LAB_00014a6a;
    }
    if (param_5 != 0x28) {
      if (param_5 != 0x2a) {
        if (param_5 == 0x2b) goto LAB_00014a23;
        if (param_5 != 0x2e) {
          if (param_5 != 0x2f) {
            return 0xc0000002;
          }
          goto LAB_00014a1b;
        }
      }
LAB_00014a58:
      *(undefined1 *)(param_1 + 0x82) = 2;
      goto LAB_00014a6a;
    }
  }
  else if (param_5 != 0x88) {
    if ((param_5 == 0x8a) || (param_5 == 0x8e)) goto LAB_00014a58;
    if (param_5 == 0x8f) {
LAB_00014a1b:
      *(undefined1 *)(param_1 + 0x82) = 0;
LAB_00014a23:
      *(undefined1 *)(param_1 + 0x82) = 8;
      goto LAB_00014a6a;
    }
    if (param_5 != 0x91) {
      return 0xc0000002;
    }
    goto LAB_00014a4e;
  }
  *(undefined1 *)(param_1 + 0x82) = 1;
LAB_00014a6a:
  *(undefined1 *)(param_1 + 0x80) = 0xfe;
  *(byte *)(param_1 + 0x81) = param_5;
  *(undefined8 *)(param_1 + 0x88) = param_6;
  *(undefined4 *)(param_1 + 0x90) = param_7;
  *(undefined1 *)(param_1 + 0x49) = 0x10;
  return 0;
}



===== NvRaidScsiConvertToUnitedCDB @ 00014a98 =====

undefined8 NvRaidScsiConvertToUnitedCDB(longlong param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  ulonglong uVar5;
  
  bVar1 = *(byte *)(param_1 + 0x80);
  if (bVar1 < 0x89) {
    if (bVar1 == 0x88) goto LAB_00014b5b;
    if (0x35 < bVar1) {
      return 0xc0000010;
    }
    if ((0x20cd0000000000U >> ((ulonglong)bVar1 & 0x3f) & 1) == 0) {
      return 0xc0000010;
    }
    uVar3 = (uint)*(byte *)(param_1 + 0x88);
    uVar5 = (ulonglong)*(uint *)(param_1 + 0x82);
    bVar2 = *(byte *)(param_1 + 0x87);
  }
  else {
    if (bVar1 != 0x8a) {
      if (bVar1 < 0x8e) {
        return 0xc0000010;
      }
      if ((0x8f < bVar1) && (bVar1 != 0x91)) {
        if (bVar1 == 0xfe) {
          return 0;
        }
        return 0xc0000010;
      }
    }
LAB_00014b5b:
    uVar5 = (ulonglong)*(uint *)(param_1 + 0x86) << 0x20 |
            (ulonglong)*(uint3 *)(param_1 + 0x83) << 8 | (ulonglong)*(byte *)(param_1 + 0x82);
    uVar3 = (uint)*(uint3 *)(param_1 + 0x8b);
    bVar2 = *(byte *)(param_1 + 0x8a);
  }
  bVar4 = bVar1 & 0x1f | 0x20;
  if (bVar4 == 0x28) {
    *(undefined1 *)(param_1 + 0x82) = 1;
    goto LAB_00014c3f;
  }
  if (bVar4 != 0x2a) {
    if (bVar4 == 0x2b) {
      *(undefined1 *)(param_1 + 0x82) = 8;
      goto LAB_00014c3f;
    }
    if (bVar4 != 0x2e) {
      if (bVar4 == 0x2f) {
        *(undefined1 *)(param_1 + 0x82) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0x82) = 4;
      }
      goto LAB_00014c3f;
    }
  }
  *(undefined1 *)(param_1 + 0x82) = 2;
LAB_00014c3f:
  *(byte *)(param_1 + 0x82) = *(byte *)(param_1 + 0x82) | (*(byte *)(param_1 + 0x81) & 8) * '\x02';
  *(byte *)(param_1 + 0x81) = bVar1;
  *(undefined1 *)(param_1 + 0x80) = 0xfe;
  *(ulonglong *)(param_1 + 0x88) = uVar5;
  *(uint *)(param_1 + 0x90) = uVar3 << 8 | (uint)bVar2;
  *(undefined1 *)(param_1 + 0x49) = 0x10;
  return 0;
}



===== NvRaidScsiSwapCDBEndian @ 00014c6c =====

undefined8 NvRaidScsiSwapCDBEndian(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *param_1;
  if (bVar1 < 0x89) {
    if (bVar1 != 0x88) {
      if (0x35 < bVar1) {
        return 0xc0000002;
      }
      if ((0x20cd0000000000U >> ((ulonglong)bVar1 & 0x3f) & 1) == 0) {
        return 0xc0000002;
      }
      *(uint *)(param_1 + 2) =
           CONCAT31(CONCAT21(CONCAT11(param_1[2],param_1[3]),param_1[4]),param_1[5]);
      *(ushort *)(param_1 + 7) = CONCAT11(param_1[7],param_1[8]);
      return 0;
    }
  }
  else {
    uVar2 = bVar1 - 0x8a;
    if ((7 < uVar2) || ((0xb1U >> (uVar2 & 0x1f) & 1) == 0)) {
      return 0xc0000002;
    }
  }
  *(ulonglong *)(param_1 + 2) =
       CONCAT71(CONCAT61(CONCAT51(CONCAT41(CONCAT31(CONCAT21(CONCAT11(param_1[2],param_1[3]),
                                                             param_1[4]),param_1[5]),param_1[6]),
                                  param_1[7]),param_1[8]),param_1[9]);
  *(uint *)(param_1 + 10) =
       CONCAT31(CONCAT21(CONCAT11(param_1[10],param_1[0xb]),param_1[0xc]),param_1[0xd]);
  return 0;
}



===== NvRaidScsiErrorAction @ 00014d6c =====

undefined4 NvRaidScsiErrorAction(char param_1,char param_2,char param_3,char *param_4,char *param_5)

{
  undefined4 uVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  uVar3 = 0;
  pcVar5 = "";
  do {
    cVar2 = *pcVar5;
    bVar6 = cVar2 == '\0';
    pcVar4 = (char *)0x0;
    if (bVar6) {
      cVar2 = pcVar5[1] - param_1;
      if ((pcVar5[3] & 4U) == 0) {
        bVar6 = cVar2 == '\0';
        if (!bVar6) goto LAB_00014dbf;
        pcVar4 = pcVar5;
        break;
      }
      if (-1 < cVar2) {
        pcVar4 = pcVar5 + -8;
        break;
      }
    }
    else {
LAB_00014dbf:
      if (!bVar6 && -1 < cVar2) break;
    }
    uVar3 = uVar3 + 1;
    pcVar5 = pcVar5 + 8;
  } while (uVar3 < 9);
  if (pcVar4 != (char *)0x0) {
    if (((param_1 == '\0') || (param_2 != '\0')) || (param_3 != '\0')) {
      pcVar5 = "";
      uVar3 = 0;
      do {
        cVar2 = *pcVar5 - param_2;
        if (cVar2 == '\0') {
          cVar2 = pcVar5[1] - param_3;
          if ((pcVar5[3] & 4U) == 0) {
            bVar6 = false;
            if (cVar2 == '\0') goto LAB_00014e0b;
            goto LAB_00014e37;
          }
          if (-1 < cVar2) {
            pcVar5 = pcVar5 + -8;
LAB_00014e0b:
            if (pcVar5 != (char *)0x0) {
              pcVar4 = pcVar5;
            }
            break;
          }
        }
        else {
          bVar6 = cVar2 == '\0';
LAB_00014e37:
          if (!bVar6 && -1 < cVar2) break;
        }
        uVar3 = uVar3 + 1;
        pcVar5 = pcVar5 + 8;
      } while (uVar3 < 9);
    }
    if (pcVar4 != (char *)0x0) {
      cVar2 = pcVar4[3];
      uVar1 = *(undefined4 *)(pcVar4 + 4);
      *param_4 = pcVar4[2];
      *param_5 = cVar2;
      return uVar1;
    }
  }
  *param_4 = '\x01';
  *param_5 = '\x01';
  return 0xc0000001;
}



===== FUN_00014e70 @ 00014e70 =====

uint FUN_00014e70(longlong param_1,uint param_2)

{
  uint *puVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  uint uVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  char cVar12;
  char cVar13;
  
  lVar2 = *(longlong *)(param_1 + 0x58);
  if (lVar2 == 0) {
    uVar8 = 0xc000000d;
  }
  else {
    bVar10 = *(byte *)(lVar2 + 0x15);
    puVar1 = (uint *)(param_1 + 0x78);
    uVar8 = *(uint *)(param_1 + 4) & 0xfffffff8;
    if (*puVar1 < (uint)bVar10) {
      uVar8 = uVar8 | 1;
    }
    else {
      cVar12 = '\0';
      bVar11 = 0;
      cVar13 = -1;
      if ((param_2 & 2) != 0) {
        cVar13 = (char)(param_2 >> 8);
      }
      bVar9 = 0;
      if (bVar10 != 0) {
        do {
          lVar6 = 0;
          if ((puVar1 != (uint *)0x0) && ((uint)bVar9 < *(uint *)(param_1 + 0x7c))) {
            lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)(uint)bVar9 * 8);
          }
          lVar7 = 0;
          if ((lVar6 == 0) || (lVar3 = lVar6, (*(uint *)(lVar6 + 4) & 1) != 0)) {
            lVar3 = lVar7;
          }
          if (lVar3 != 0) {
            bVar11 = bVar11 + 1;
          }
          if ((lVar6 == 0) || ((*(uint *)(lVar6 + 4) & 1) != 0)) {
            lVar6 = lVar7;
          }
          if (lVar6 != 0) {
            if (((*(char *)(lVar2 + 0x14) != '\x04') || ((*(uint *)(lVar6 + 4) & 0x100) == 0)) &&
               (((*(uint *)(lVar6 + 4) & 1) != 0 || ((*(uint *)(lVar6 + 4) >> 8 & 1) != 0)))) {
              lVar6 = lVar7;
            }
            if ((lVar6 != 0) && (*(char *)(lVar6 + 8) == cVar13)) {
              lVar6 = lVar7;
            }
          }
          uVar5 = (uint)bVar9 + (uint)bVar10 & 0xff;
          if ((puVar1 == (uint *)0x0) || (*(uint *)(param_1 + 0x7c) <= uVar5)) {
            lVar7 = 0;
          }
          else {
            lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)uVar5 * 8);
          }
          lVar3 = 0;
          if ((lVar7 == 0) || (lVar4 = lVar7, (*(uint *)(lVar7 + 4) & 1) != 0)) {
            lVar4 = lVar3;
          }
          if (lVar4 != 0) {
            bVar11 = bVar11 + 1;
          }
          if ((lVar7 == 0) || ((*(uint *)(lVar7 + 4) & 1) != 0)) {
            lVar7 = lVar3;
          }
          if (lVar7 != 0) {
            if (((*(char *)(lVar2 + 0x14) != '\x04') || ((*(uint *)(lVar7 + 4) & 0x100) == 0)) &&
               (((*(uint *)(lVar7 + 4) & 1) != 0 || ((*(uint *)(lVar7 + 4) >> 8 & 1) != 0)))) {
              lVar7 = lVar3;
            }
            if ((lVar7 != 0) && (*(char *)(lVar7 + 8) == cVar13)) {
              lVar7 = lVar3;
            }
          }
          if (lVar6 == 0) {
            if (lVar7 == 0) {
              uVar8 = uVar8 | 1;
              break;
            }
LAB_00015068:
            cVar12 = cVar12 + '\x01';
          }
          else if (lVar7 == 0) goto LAB_00015068;
          bVar9 = bVar9 + 1;
        } while (bVar9 < bVar10);
      }
      if ((bVar9 == bVar10) &&
         ((cVar12 == '\0' || (uVar8 = uVar8 | 4, (uint)bVar11 == (uint)bVar9 * 2)))) {
        uVar8 = uVar8 | 2;
      }
    }
    bVar10 = 1;
    if ((param_2 & 8) != 0) {
      bVar10 = 1;
      NvRaidResArrayGenerateSignature((uint *)(lVar2 + 4));
    }
    if ((bVar10 & (byte)param_2) != 0) {
      NvRaidDefaultUpdateArrayStatus(param_1,param_2);
      if ((uVar8 & 0x20) != 0) {
        uVar8 = *(uint *)(param_1 + 4);
      }
      *(uint *)(param_1 + 4) = uVar8;
    }
  }
  return uVar8;
}



===== NvRaidStripeDefaultSendCommand @ 00015078 =====

undefined8 NvRaidStripeDefaultSendCommand(undefined8 param_1,longlong param_2)

{
  char cVar1;
  undefined8 uVar2;
  undefined **ppuVar3;
  undefined **local_18 [2];
  
  *(undefined1 *)(param_2 + 0x56) = 0;
  uVar2 = NvRaidScsiConvertToUnitedCDB(param_2);
  if ((int)uVar2 == 0) {
    ppuVar3 = &PTR_FUN_000278e8;
    goto LAB_00015115;
  }
  cVar1 = *(char *)(param_2 + 0x80);
  if ((cVar1 == '\0') || (cVar1 == '\x15')) {
LAB_0001510e:
    ppuVar3 = &PTR_FUN_00027848;
  }
  else {
    if (cVar1 != '\x1a') {
      if ((cVar1 == '\x1b') || (cVar1 == 'U')) goto LAB_0001510e;
      if (cVar1 != 'Z') {
        if ((cVar1 != -1) || (3 < (byte)(*(char *)(param_2 + 0x81) - 0xcU))) {
          return 0xc0000010;
        }
        *(undefined1 *)(param_2 + 0x56) = 0;
        local_18[0] = &PTR_FUN_00027870;
        local_18[1] = &PTR_FUN_00027898;
        ppuVar3 = local_18[*(byte *)(param_2 + 0x81) & 1];
        goto LAB_00015115;
      }
    }
    ppuVar3 = &PTR_FUN_000278c0;
  }
LAB_00015115:
  *(undefined ***)(param_2 + 0x58) = ppuVar3;
  FUN_00011e84(param_2);
  return 0x103;
}



===== FUN_0001512c @ 0001512c =====

undefined8 FUN_0001512c(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  lVar1 = *(longlong *)(*(longlong *)(param_2 + 0x40) + 0x58);
  uVar3 = (ulonglong)*(uint *)(param_2 + 0x90) + *(ulonglong *)(param_2 + 0x88);
  if (((*(ulonglong *)(param_1 + 0x20) < uVar3) || (uVar3 < *(ulonglong *)(param_2 + 0x88))) ||
     ((*(char *)(*(longlong *)(param_1 + 0x58) + 0x14) == '\x04' &&
      ((*(ulonglong *)(lVar1 + 0x58) < uVar3 && (*(ulonglong *)(lVar1 + 0x50) < uVar3)))))) {
    *(undefined4 *)(param_2 + 0x50) = 0xc000000d;
    *(undefined4 *)(param_2 + 0x4b) = 0x210502;
    NvRaidPacketCompleteRequest(param_2);
    uVar2 = 0xc000000d;
  }
  else {
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
    uVar2 = 0;
  }
  return uVar2;
}



===== FUN_00015194 @ 00015194 =====

undefined8 FUN_00015194(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  int iVar8;
  ulonglong uVar9;
  uint uVar10;
  longlong local_38;
  longlong *plStack_30;
  
  lVar3 = *(longlong *)(param_1 + 0x58);
  uVar7 = *(ulonglong *)(param_2 + 0x88);
  uVar10 = *(uint *)(param_2 + 0x90);
  uVar9 = (ulonglong)uVar10;
  lVar4 = *(longlong *)(*(longlong *)(param_2 + 0x40) + 0x58);
  if ((((((*(uint *)(param_2 + 0x60) & 0x400) == 0) && (lVar3 != 0)) &&
       (*(int *)(lVar3 + 0x70) != 0)) &&
      ((*(int *)(lVar3 + 0x70) != *(int *)(param_2 + 100) &&
       (*(ulonglong *)(lVar3 + 0x60) <= uVar9 + uVar7)))) && (uVar7 <= *(ulonglong *)(lVar3 + 0x68))
     ) {
    *(undefined8 *)(param_2 + 0x10) = 0;
    *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(lVar3 + 0x80);
    **(longlong **)(lVar3 + 0x80) = param_2;
    *(undefined8 **)(lVar3 + 0x80) = (undefined8 *)(param_2 + 0x10);
  }
  else {
    if ((*(uint *)(param_1 + 4) >> 0xb & 1) == 0) {
      *(undefined1 *)(param_2 + 0x55) = 0;
      cVar2 = *(char *)(lVar3 + 0x14);
      iVar8 = 0;
      if ((((cVar2 == '\0') && (((byte)*(undefined4 *)(param_1 + 4) & 7) == 2)) ||
          ((*(char *)(param_2 + 0x81) == '5' || (*(char *)(param_2 + 0x81) == -0x6f)))) ||
         ((cVar2 != '\0' && (uVar7 < *(ulonglong *)(lVar4 + 0x58))))) {
        if ((cVar2 != '\0') && (uVar6 = *(longlong *)(lVar4 + 0x58) - uVar7, uVar6 < uVar9)) {
          uVar9 = uVar6 & 0xffffffff;
        }
        iVar8 = (int)uVar9;
        (**(code **)(*(longlong *)(lVar3 + 0x88) + 0x38))(param_1,param_2,0,uVar7,iVar8,1);
        uVar10 = uVar10 - iVar8;
        uVar7 = uVar7 + uVar9;
      }
      if ((uVar10 != 0) ||
         ((*(char *)(lVar3 + 0x14) == '\0' && (((byte)*(undefined4 *)(param_1 + 4) & 7) != 2)))) {
        cVar2 = *(char *)(param_2 + 0x55);
        plVar1 = (longlong *)(param_2 + 0x20);
        if (*plVar1 == 0) {
          plStack_30 = &local_38;
          local_38 = 0;
        }
        else {
          local_38 = *plVar1;
          plStack_30 = *(longlong **)(param_2 + 0x28);
          *(longlong **)(local_38 + 8) = &local_38;
        }
        *plVar1 = 0;
        *(undefined1 *)(param_2 + 0x55) = 0;
        *(longlong **)(param_2 + 0x28) = plVar1;
        (**(code **)(*(longlong *)(lVar3 + 0x90) + 0x38))(param_1,param_2,iVar8 << 9,uVar7,uVar10,0)
        ;
        *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + cVar2;
        if (local_38 != 0) {
          *plStack_30 = *plVar1;
          *(longlong **)(*plVar1 + 8) = plStack_30;
          *plVar1 = local_38;
          *(longlong **)(local_38 + 8) = plVar1;
        }
      }
      if (*(undefined ***)(param_2 + 0x58) == &PTR_FUN_000278e8) {
        *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
        uVar5 = NvRaidPacketSubmitSubRequests((longlong *)(param_2 + 0x20));
        return uVar5;
      }
      return 0;
    }
    NvRaidResQueueLowResourceNrp(param_2);
  }
  return 0x103;
}



===== FUN_00015398 @ 00015398 =====

undefined8
FUN_00015398(longlong param_1,longlong param_2,int param_3,ulonglong param_4,uint param_5,
            int param_6)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_2 + 0x80);
  if (bVar1 == 0xfe) {
    bVar1 = *(byte *)(param_2 + 0x81);
  }
  FUN_00015800(param_1,param_2,param_3,bVar1,param_4,param_5,param_6);
  NvRaidPacketSetupSubRequestsDevice(param_1,(undefined8 *)(param_2 + 0x20));
  return 0;
}



===== FUN_000153f8 @ 000153f8 =====

undefined8
FUN_000153f8(longlong param_1,longlong param_2,uint param_3,ulonglong param_4,uint param_5,
            int param_6)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_2 + 0x80);
  if (bVar1 == 0xfe) {
    bVar1 = *(byte *)(param_2 + 0x81);
  }
  FUN_00015994(param_1,param_2,param_3,bVar1,param_4,param_5,param_6);
  NvRaidPacketSetupSubRequestsDevice(param_1,(undefined8 *)(param_2 + 0x20));
  return 0;
}



===== FUN_00015458 @ 00015458 =====

undefined8
FUN_00015458(longlong param_1,longlong param_2,int param_3,ulonglong param_4,uint param_5,
            int param_6)

{
  longlong lVar1;
  byte bVar2;
  longlong lVar3;
  
  bVar2 = *(byte *)(param_2 + 0x80);
  if (bVar2 == 0xfe) {
    bVar2 = *(byte *)(param_2 + 0x81);
  }
  FUN_00015800(param_1,param_2,param_3,bVar2,param_4,param_5,param_6);
  if ((*(uint *)(param_2 + 0x60) & 0x10) != 0) {
    lVar1 = *(longlong *)(param_2 + 0x68);
    if (((((char *)(lVar1 + 0x80) != (char *)0x0) && (*(short *)(lVar1 + 0x84) == 0x81)) &&
        (*(char *)(lVar1 + 0x80) == -1)) && (*(char *)(lVar1 + 0x81) == '\x04')) {
      bVar2 = *(byte *)(lVar1 + 0x87);
      lVar1 = *(longlong *)(param_2 + 0x20);
      if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)bVar2)) {
        lVar3 = 0;
      }
      else {
        lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)bVar2 * 8);
      }
      if (((lVar3 == 0) || ((*(uint *)(lVar3 + 4) & 1) != 0)) ||
         ((param_6 == 0 && ((*(uint *)(lVar3 + 4) >> 8 & 1) != 0)))) {
        lVar3 = 0;
      }
      if (lVar3 == 0) {
        return 0xc0000001;
      }
      *(byte *)(lVar1 + 0x48) = bVar2;
      *(longlong *)(lVar1 + 0x40) = lVar3;
      return 0;
    }
  }
  if ((*(byte *)(param_2 + 0x82) & 6) == 0) {
    FUN_00016020(param_1,param_2,param_6);
  }
  else {
    FUN_00015d74(param_1,param_2,param_6);
  }
  return 0;
}



===== FUN_00015550 @ 00015550 =====

undefined8
FUN_00015550(longlong param_1,longlong param_2,uint param_3,ulonglong param_4,uint param_5,
            int param_6)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_2 + 0x80);
  if (bVar1 == 0xfe) {
    bVar1 = *(byte *)(param_2 + 0x81);
  }
  FUN_00015994(param_1,param_2,param_3,bVar1,param_4,param_5,param_6);
  if ((*(byte *)(param_2 + 0x82) & 6) == 0) {
    FUN_00016020(param_1,param_2,param_6);
  }
  else {
    FUN_00015d74(param_1,param_2,param_6);
  }
  return 0;
}



===== FUN_000155cc @ 000155cc =====

int FUN_000155cc(undefined4 *param_1,longlong param_2,uint *param_3)

{
  int iVar1;
  undefined8 uVar2;
  byte bVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  
  lVar5 = *(longlong *)(param_1 + 0x16);
  iVar1 = NvRaidDefaultProcessError(param_1,param_2,param_3);
  uVar6 = *param_3;
  if (0 < (int)uVar6) {
    if ((int)uVar6 < 3) {
      if ((lVar5 != 0) && ((*(uint *)(param_2 + 0x60) & 2) != 0)) {
        uVar6 = ~(*(uint *)(param_2 + 0x60) >> 2) & 1;
        if (uVar6 == 0) {
          bVar3 = *(byte *)(lVar5 + 0x15);
        }
        else {
          bVar3 = *(byte *)(lVar5 + 0x17);
        }
        uVar4 = (ulonglong)(byte)(bVar3 + *(char *)(param_2 + 0x48)) %
                (ulonglong)(longlong)(int)((uint)bVar3 * 2) & 0xff;
        if ((param_1 == (undefined4 *)0xffffffffffffff88) || ((uint)param_1[0x1f] <= (uint)uVar4)) {
          lVar5 = 0;
        }
        else {
          lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x20) + uVar4 * 8);
        }
        if (((lVar5 == 0) || ((*(uint *)(lVar5 + 4) & 1) != 0)) ||
           ((uVar6 == 0 && ((*(uint *)(lVar5 + 4) >> 8 & 1) != 0)))) {
          lVar5 = 0;
        }
        if (lVar5 != 0) {
          *(longlong *)(param_2 + 0x40) = lVar5;
          *(undefined1 *)(param_2 + 0x48) = *(undefined1 *)(lVar5 + 8);
          *param_3 = 1;
        }
      }
    }
    else if ((uVar6 == 3) && (*(char *)(param_2 + 0x80) == -2)) {
      uVar2 = NvRaidRemoveFailedVolumeFromArray(param_1,*(longlong *)(param_2 + 0x40));
      if ((char)uVar2 != '\0') {
        *param_3 = 2;
      }
    }
  }
  return iVar1;
}



===== FUN_000156d8 @ 000156d8 =====

undefined8
FUN_000156d8(longlong param_1,longlong param_2,undefined1 param_3,uint param_4,byte param_5,
            undefined8 param_6,int param_7,int param_8)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  puVar1 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
  if (puVar1 == (undefined8 *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    lVar3 = 0;
    NvRaidScsiSetupReadWrite
              ((longlong)puVar1,param_3,0,NvRaidStateSubRequestsDone,param_5,param_6,param_7);
    *(byte *)((longlong)puVar1 + 0x82) =
         *(byte *)((longlong)puVar1 + 0x82) | *(byte *)(param_2 + 0x82) & 0x10;
    puVar1[0x15] = *(undefined8 *)(param_2 + 0xa8);
    if ((*(longlong *)(param_2 + 0xa8) != lVar3) && (param_4 != 0)) {
      uVar2 = NvRaidResSgGroupAllocateForNrp(*(longlong *)(param_1 + 0x18),(longlong)puVar1);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      NvRaidPacketScatterGatherGroupBuildPartialGroup
                (*(longlong *)(param_2 + 0xa8),puVar1[0x15],(ulonglong)param_4,param_7 << 9,
                 param_7 << 9,0,0);
    }
    if (param_8 == 0) {
      *(uint *)(puVar1 + 0xc) = *(uint *)(puVar1 + 0xc) | 4;
    }
    *puVar1 = 0;
    puVar1[1] = *(undefined8 *)(param_2 + 0x28);
    **(undefined8 **)(param_2 + 0x28) = puVar1;
    *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
    *(undefined8 **)(param_2 + 0x28) = puVar1;
    puVar1[0xd] = param_2;
    puVar1[0xe] = *(undefined8 *)(param_2 + 0x40);
    uVar2 = 0;
  }
  return uVar2;
}



===== FUN_00015800 @ 00015800 =====

undefined8
FUN_00015800(longlong param_1,longlong param_2,int param_3,byte param_4,ulonglong param_5,
            uint param_6,int param_7)

{
  byte bVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  int iVar9;
  ulonglong uVar10;
  
  uVar10 = param_5;
  lVar3 = *(longlong *)(param_1 + 0x58);
  iVar9 = 0;
  *(undefined1 *)(param_2 + 0x55) = 0;
  param_5._0_4_ = 0;
  if (param_7 == 0) {
    bVar1 = *(byte *)(lVar3 + 0x17);
    iVar2 = *(int *)(lVar3 + 0x38);
  }
  else {
    bVar1 = *(byte *)(lVar3 + 0x15);
    iVar2 = *(int *)(lVar3 + 0x18);
  }
  if (param_7 == 0) {
    uVar8 = *(ulonglong *)(lVar3 + 0x50) / (ulonglong)bVar1;
  }
  else {
    uVar8 = *(ulonglong *)(param_1 + 0x20);
  }
  uVar7 = 0;
  if (bVar1 != 0) {
    do {
      if (iVar2 == 0xff) {
        if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)(uVar7 & 0xff))) {
          lVar5 = 0;
        }
        else {
          lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (uVar7 & 0xff) * 8);
        }
        uVar8 = ~(ulonglong)(*(int *)(lVar3 + 0x1c) - 1) & *(longlong *)(lVar5 + 0x20) - 2U;
      }
      if (uVar10 < uVar8) {
        uVar6 = (int)uVar8 - (int)uVar10;
        if (param_6 < uVar6) {
          uVar6 = param_6;
        }
        FUN_000156d8(param_1,param_2,(char)uVar7,iVar9 * 0x200 + param_3,param_4,uVar10,uVar6,
                     param_7);
        param_6 = param_6 - uVar6;
        uVar4 = (ulonglong)uVar6;
        iVar9 = (int)param_5 + uVar6;
        if (param_6 == 0) {
          return 0;
        }
        param_5._0_4_ = iVar9;
      }
      else {
        uVar4 = -uVar8;
        uVar7 = (ulonglong)((int)uVar7 + 1);
      }
      uVar10 = uVar10 + uVar4;
    } while ((uint)uVar7 < (uint)bVar1);
  }
  return 0;
}



===== FUN_00015994 @ 00015994 =====

undefined8
FUN_00015994(longlong param_1,longlong param_2,uint param_3,byte param_4,ulonglong param_5,
            uint param_6,int param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  ulonglong uVar15;
  uint uVar16;
  ulonglong uVar17;
  longlong lVar18;
  int iVar19;
  undefined1 uVar20;
  longlong lVar21;
  int iVar22;
  uint local_98;
  uint local_90;
  int local_80;
  uint local_68;
  
  lVar18 = *(longlong *)(param_1 + 0x58);
  *(undefined1 *)(param_2 + 0x55) = 0;
  if (param_7 == 0) {
    bVar10 = *(byte *)(lVar18 + 0x17);
  }
  else {
    bVar10 = *(byte *)(lVar18 + 0x15);
  }
  uVar13 = (uint)bVar10;
  if (uVar13 == 1) {
    uVar20 = 0;
  }
  else {
    uVar2 = *(uint *)(lVar18 + 0x1c);
    uVar3 = *(uint *)(lVar18 + 0x20);
    bVar10 = (byte)*(undefined4 *)(lVar18 + 0x24);
    uVar17 = param_5 >> (bVar10 & 0x3f);
    uVar15 = (ulonglong)uVar13;
    uVar6 = uVar17 / uVar15;
    uVar4 = (uint)param_5 & *(uint *)(lVar18 + 0x28);
    uVar11 = uVar2 - uVar4;
    if (param_6 < uVar2 - uVar4) {
      uVar11 = param_6;
    }
    uVar16 = uVar13;
    if ((param_6 == 0) && ((*(byte *)(param_2 + 0x82) & 4) != 0)) {
      uVar7 = (*(ulonglong *)(param_1 + 0x20) >> (bVar10 & 0x3f)) - 1;
      local_98 = uVar2;
    }
    else {
      uVar12 = ((uVar2 - 1) + (param_6 - uVar11) >> (bVar10 & 0x1f)) + 1;
      local_98 = param_6 - uVar11 & *(uint *)(lVar18 + 0x28);
      if (local_98 == 0) {
        local_98 = uVar2;
      }
      uVar7 = ((ulonglong)uVar12 - 1) + uVar17;
      if (uVar12 < uVar13) {
        uVar16 = uVar12;
      }
    }
    local_80 = (int)uVar6;
    if (uVar16 != 1) {
      iVar5 = (int)(uVar7 / uVar15);
      if ((param_6 == 0) && ((*(byte *)(param_2 + 0x82) & 4) != 0)) {
        iVar19 = 0;
      }
      else {
        iVar19 = (iVar5 - local_80) + 1 << (bVar10 & 0x1f);
      }
      uVar12 = (uint)(uVar17 % uVar15);
      lVar18 = (uVar6 & 0xffffffff) << (bVar10 & 0x3f);
      iVar22 = (-(uint)(uVar12 != 0) & ((uVar13 - uVar12) + -1 << (bVar10 & 0x1f)) + uVar11) << 9;
      uVar16 = 0;
      if (uVar13 == 0) {
        return 0;
      }
      while( true ) {
        bVar10 = (uVar16 < uVar12) + 1;
        local_68 = (uint)(uVar7 % uVar15);
        if ((uint)bVar10 + local_80 <= (uint)(uVar16 <= local_68) + iVar5) {
          lVar21 = lVar18;
          iVar14 = iVar19;
          local_90 = uVar3;
          if (uVar16 == uVar12) {
            iVar14 = iVar19 - uVar4;
            lVar21 = lVar18 + (ulonglong)uVar4;
            local_90 = uVar11 << 9;
          }
          if (1 < bVar10) {
            lVar21 = lVar21 + (ulonglong)uVar2;
            iVar14 = iVar14 - uVar2;
          }
          if (uVar16 > local_68) {
            iVar14 = iVar14 - uVar2;
          }
          if (uVar16 == local_68) {
            iVar14 = iVar14 + (local_98 - uVar2);
          }
          puVar8 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
          if (puVar8 == (undefined8 *)0x0) {
            return 0xc000009a;
          }
          NvRaidScsiSetupReadWrite
                    ((longlong)puVar8,(char)uVar16,0,NvRaidStateSubRequestsDone,param_4,lVar21,
                     iVar14);
          bVar10 = *(byte *)(param_2 + 0x82);
          puVar8[0xd] = param_2;
          *(byte *)((longlong)puVar8 + 0x82) = *(byte *)((longlong)puVar8 + 0x82) | bVar10 & 0x10;
          puVar8[0x15] = *(undefined8 *)(param_2 + 0xa8);
          if (*(longlong *)(param_2 + 0xa8) != 0) {
            uVar9 = NvRaidResSgGroupAllocateForNrp(*(longlong *)(param_1 + 0x18),(longlong)puVar8);
            if ((int)uVar9 < 0) {
              return uVar9;
            }
            NvRaidPacketScatterGatherGroupBuildPartialGroup
                      (*(longlong *)(param_2 + 0xa8),puVar8[0x15],(ulonglong)(param_3 + iVar22),
                       iVar14 << 9,local_90,uVar3,uVar3 * uVar13 - uVar3);
          }
          if (param_7 == 0) {
            *(uint *)(puVar8 + 0xc) = *(uint *)(puVar8 + 0xc) | 4;
          }
          *puVar8 = 0;
          puVar8[1] = *(undefined8 *)(param_2 + 0x28);
          **(undefined8 **)(param_2 + 0x28) = puVar8;
          *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
          *(undefined8 **)(param_2 + 0x28) = puVar8;
          puVar8[0xd] = param_2;
          puVar8[0xe] = *(undefined8 *)(param_2 + 0x40);
        }
        uVar1 = uVar16 + 1;
        if (uVar1 == uVar13) {
          return 0;
        }
        if (uVar1 == uVar12) {
          iVar22 = 0;
        }
        else if (uVar16 == uVar12) {
          iVar22 = uVar11 << 9;
        }
        else {
          iVar22 = iVar22 + uVar3;
        }
        if (uVar13 <= uVar1) break;
        uVar16 = uVar1;
      }
      return 0;
    }
    if (1 < uVar13) {
      param_5 = ((uVar6 & 0xffffffff) << (bVar10 & 0x3f)) + (ulonglong)uVar4;
    }
    uVar20 = (undefined1)(uVar17 % uVar15);
  }
  FUN_000156d8(param_1,param_2,uVar20,param_3,param_4,param_5,param_6,param_7);
  return 0;
}



===== FUN_00015d74 @ 00015d74 =====

undefined8 FUN_00015d74(longlong param_1,longlong param_2,int param_3)

{
  longlong *plVar1;
  byte bVar2;
  undefined1 uVar3;
  longlong *plVar4;
  longlong *plVar5;
  ulonglong uVar6;
  longlong *_Dst;
  longlong *plVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong *_Src;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  byte bVar13;
  longlong local_48;
  longlong *plStack_40;
  
  plVar1 = (longlong *)(param_2 + 0x20);
  plStack_40 = &local_48;
  _Src = (longlong *)*plVar1;
  local_48 = 0;
  if (param_3 == 0) {
    bVar13 = *(byte *)(*(longlong *)(param_1 + 0x58) + 0x17);
  }
  else {
    bVar13 = *(byte *)(*(longlong *)(param_1 + 0x58) + 0x15);
  }
  if (_Src != (longlong *)0x0) {
    do {
      lVar8 = 0;
      if (*_Src == 0) {
        *(longlong *)(param_2 + 0x28) = _Src[1];
      }
      else {
        *(longlong *)(*_Src + 8) = _Src[1];
      }
      *(longlong *)_Src[1] = *_Src;
      bVar2 = *(byte *)(_Src + 9);
      if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)bVar2)) {
        lVar12 = lVar8;
      }
      else {
        lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)bVar2 * 8);
      }
      if (((lVar12 == 0) || ((*(uint *)(lVar12 + 4) & 1) != 0)) ||
         ((param_3 == 0 && ((*(uint *)(lVar12 + 4) >> 8 & 1) != 0)))) {
        lVar12 = lVar8;
      }
      uVar6 = (ulonglong)(byte)(bVar2 + bVar13) % (ulonglong)(longlong)(int)((uint)bVar13 * 2) &
              0xff;
      if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)uVar6)) {
        lVar10 = lVar8;
      }
      else {
        lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x80) + uVar6 * 8);
      }
      if (((lVar10 == 0) || ((*(uint *)(lVar10 + 4) & 1) != 0)) ||
         ((param_3 == 0 && ((*(uint *)(lVar10 + 4) >> 8 & 1) != 0)))) {
        lVar10 = lVar8;
      }
      lVar11 = lVar10;
      if ((lVar12 != 0) || (lVar11 = lVar8, lVar12 = lVar10, lVar10 != 0)) {
        _Src[8] = lVar12;
        uVar3 = *(undefined1 *)(lVar12 + 8);
        *_Src = 0;
        *(undefined1 *)(_Src + 9) = uVar3;
        _Src[1] = (longlong)plStack_40;
        *plStack_40 = (longlong)_Src;
        plStack_40 = _Src;
        if (lVar11 != 0) {
          _Dst = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
          if (_Dst == (longlong *)0x0) {
            return 0xc000009a;
          }
          if ((((uint)_Src | (uint)_Dst) & 0xf) == 0) {
            lVar8 = 1;
            plVar4 = _Dst;
            plVar5 = _Src;
            do {
              plVar9 = plVar5;
              plVar7 = plVar4;
              lVar12 = plVar9[1];
              *plVar7 = *plVar9;
              plVar7[1] = lVar12;
              lVar12 = plVar9[3];
              plVar7[2] = plVar9[2];
              plVar7[3] = lVar12;
              lVar12 = plVar9[5];
              plVar7[4] = plVar9[4];
              plVar7[5] = lVar12;
              lVar12 = plVar9[7];
              plVar7[6] = plVar9[6];
              plVar7[7] = lVar12;
              lVar12 = plVar9[9];
              plVar7[8] = plVar9[8];
              plVar7[9] = lVar12;
              lVar12 = plVar9[0xb];
              plVar7[10] = plVar9[10];
              plVar7[0xb] = lVar12;
              lVar12 = plVar9[0xd];
              plVar7[0xc] = plVar9[0xc];
              plVar7[0xd] = lVar12;
              lVar12 = plVar9[0xf];
              plVar7[0xe] = plVar9[0xe];
              plVar7[0xf] = lVar12;
              lVar8 = lVar8 + -1;
              plVar4 = plVar7 + 0x10;
              plVar5 = plVar9 + 0x10;
            } while (lVar8 != 0);
            lVar8 = plVar9[0x11];
            plVar7[0x10] = plVar9[0x10];
            plVar7[0x11] = lVar8;
            lVar8 = plVar9[0x13];
            plVar7[0x12] = plVar9[0x12];
            plVar7[0x13] = lVar8;
            lVar8 = plVar9[0x15];
            plVar7[0x14] = plVar9[0x14];
            plVar7[0x15] = lVar8;
            lVar8 = plVar9[0x17];
            plVar7[0x16] = plVar9[0x16];
            plVar7[0x17] = lVar8;
            lVar8 = plVar9[0x19];
            plVar7[0x18] = plVar9[0x18];
            plVar7[0x19] = lVar8;
            lVar8 = plVar9[0x1b];
            plVar7[0x1a] = plVar9[0x1a];
            plVar7[0x1b] = lVar8;
            lVar8 = plVar9[0x1d];
            plVar7[0x1c] = plVar9[0x1c];
            plVar7[0x1d] = lVar8;
          }
          else {
            memcpy(_Dst,_Src,0xf0);
          }
          *(uint *)(_Dst + 0xc) = *(uint *)(_Dst + 0xc) & 0xfffffcff;
          *(undefined1 *)((longlong)_Dst + 0x55) = 0;
          _Dst[8] = lVar11;
          _Dst[4] = 0;
          _Dst[5] = (longlong)(_Dst + 4);
          *(undefined1 *)(_Dst + 9) = *(undefined1 *)(lVar11 + 8);
          bVar2 = *(byte *)((longlong)_Src + 0x82);
          *_Dst = 0;
          *(byte *)((longlong)_Dst + 0x82) = *(byte *)((longlong)_Dst + 0x82) | bVar2 & 0x10;
          _Dst[1] = (longlong)plStack_40;
          *plStack_40 = (longlong)_Dst;
          *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
          plStack_40 = _Dst;
        }
      }
      _Src = (longlong *)*plVar1;
    } while (_Src != (longlong *)0x0);
    if (local_48 != 0) {
      *plVar1 = local_48;
      *(longlong **)(param_2 + 0x28) = plStack_40;
      *(longlong **)(*plVar1 + 8) = plVar1;
      return 0;
    }
  }
  *plVar1 = 0;
  *(longlong **)(param_2 + 0x28) = plVar1;
  return 0;
}



===== FUN_00016020 @ 00016020 =====

undefined8 FUN_00016020(longlong param_1,longlong param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong *plVar9;
  
  plVar9 = *(longlong **)(param_2 + 0x20);
  if (param_3 == 0) {
    bVar1 = *(byte *)(*(longlong *)(param_1 + 0x58) + 0x17);
  }
  else {
    bVar1 = *(byte *)(*(longlong *)(param_1 + 0x58) + 0x15);
  }
  if (plVar9 != (longlong *)0x0) {
    do {
      bVar2 = *(byte *)(plVar9 + 9);
      if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)bVar2)) {
        lVar6 = 0;
      }
      else {
        lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)bVar2 * 8);
      }
      if (((lVar6 == 0) || ((*(uint *)(lVar6 + 4) & 1) != 0)) ||
         ((param_3 == 0 && ((*(uint *)(lVar6 + 4) >> 8 & 1) != 0)))) {
        lVar6 = 0;
      }
      uVar4 = (ulonglong)((uint)bVar1 + (uint)bVar2 & 0xff) %
              (ulonglong)(longlong)(int)((uint)bVar1 * 2);
      uVar5 = uVar4 & 0xff;
      if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)uVar5)) {
        lVar7 = 0;
      }
      else {
        lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x80) + uVar5 * 8);
      }
      if (((lVar7 == 0) || ((*(uint *)(lVar7 + 4) & 1) != 0)) ||
         ((param_3 == 0 && ((*(uint *)(lVar7 + 4) >> 8 & 1) != 0)))) {
        lVar7 = 0;
      }
      if ((*(uint *)(param_2 + 0x60) & 0x400) != 0) {
        if (bVar2 == *(byte *)(*(longlong *)(param_2 + 0xc0) + 8)) {
          lVar6 = 0;
        }
        if ((char)uVar4 == *(char *)(*(longlong *)(param_2 + 0xc0) + 8)) {
          lVar7 = 0;
        }
      }
      lVar8 = lVar7;
      if (lVar6 == 0) {
        if (lVar7 == 0) {
          return 0xc0000001;
        }
        lVar8 = 0;
        lVar6 = lVar7;
      }
      if (lVar8 != 0) {
        if ((((*(char *)(lVar8 + 0xb) - *(char *)(lVar6 + 0xb)) - *(char *)(lVar6 + 10)) +
             *(char *)(lVar8 + 10) & 0x80U) != 0) {
          lVar6 = lVar8;
        }
        *(uint *)(plVar9 + 0xc) = *(uint *)(plVar9 + 0xc) | 2;
      }
      *(char *)(lVar6 + 0xb) = *(char *)(lVar6 + 0xb) + '\x01';
      uVar3 = *(undefined1 *)(lVar6 + 8);
      plVar9[8] = lVar6;
      *(undefined1 *)(plVar9 + 9) = uVar3;
      plVar9 = (longlong *)*plVar9;
    } while (plVar9 != (longlong *)0x0);
  }
  return 0;
}



===== FUN_0001617c @ 0001617c =====

undefined8 FUN_0001617c(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *_Dst;
  undefined8 *puVar5;
  longlong lVar6;
  undefined8 *puVar7;
  byte bVar8;
  ulonglong uVar9;
  longlong lVar10;
  
  lVar1 = *(longlong *)(param_1 + 0x58);
  uVar9 = 0;
  if (*(char *)(lVar1 + 0x16) != '\0') {
    do {
      if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)uVar9)) {
        lVar10 = 0;
      }
      else {
        lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x80) + uVar9 * 8);
      }
      if (lVar10 != 0) {
        _Dst = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
        if (_Dst == (undefined8 *)0x0) {
          return 0xc000009a;
        }
        if ((((uint)param_2 | (uint)_Dst) & 0xf) == 0) {
          lVar6 = 1;
          puVar3 = _Dst;
          puVar4 = param_2;
          do {
            puVar7 = puVar4;
            puVar5 = puVar3;
            uVar2 = puVar7[1];
            *puVar5 = *puVar7;
            puVar5[1] = uVar2;
            uVar2 = puVar7[3];
            puVar5[2] = puVar7[2];
            puVar5[3] = uVar2;
            uVar2 = puVar7[5];
            puVar5[4] = puVar7[4];
            puVar5[5] = uVar2;
            uVar2 = puVar7[7];
            puVar5[6] = puVar7[6];
            puVar5[7] = uVar2;
            uVar2 = puVar7[9];
            puVar5[8] = puVar7[8];
            puVar5[9] = uVar2;
            uVar2 = puVar7[0xb];
            puVar5[10] = puVar7[10];
            puVar5[0xb] = uVar2;
            uVar2 = puVar7[0xd];
            puVar5[0xc] = puVar7[0xc];
            puVar5[0xd] = uVar2;
            uVar2 = puVar7[0xf];
            puVar5[0xe] = puVar7[0xe];
            puVar5[0xf] = uVar2;
            lVar6 = lVar6 + -1;
            puVar3 = puVar5 + 0x10;
            puVar4 = puVar7 + 0x10;
          } while (lVar6 != 0);
          uVar2 = puVar7[0x11];
          puVar5[0x10] = puVar7[0x10];
          puVar5[0x11] = uVar2;
          uVar2 = puVar7[0x13];
          puVar5[0x12] = puVar7[0x12];
          puVar5[0x13] = uVar2;
          uVar2 = puVar7[0x15];
          puVar5[0x14] = puVar7[0x14];
          puVar5[0x15] = uVar2;
          uVar2 = puVar7[0x17];
          puVar5[0x16] = puVar7[0x16];
          puVar5[0x17] = uVar2;
          uVar2 = puVar7[0x19];
          puVar5[0x18] = puVar7[0x18];
          puVar5[0x19] = uVar2;
          uVar2 = puVar7[0x1b];
          puVar5[0x1a] = puVar7[0x1a];
          puVar5[0x1b] = uVar2;
          uVar2 = puVar7[0x1d];
          puVar5[0x1c] = puVar7[0x1c];
          puVar5[0x1d] = uVar2;
        }
        else {
          memcpy(_Dst,param_2,0xf0);
        }
        *(uint *)(_Dst + 0xc) = *(uint *)(_Dst + 0xc) & 0xfffffcff;
        *_Dst = 0;
        *(undefined1 *)((longlong)_Dst + 0x55) = 0;
        *(char *)(_Dst + 9) = (char)uVar9;
        _Dst[8] = lVar10;
        _Dst[4] = 0;
        _Dst[5] = _Dst + 4;
        _Dst[0x14] = NvRaidStateSubRequestsDone;
        _Dst[1] = param_2[5];
        *(undefined8 **)param_2[5] = _Dst;
        *(char *)((longlong)param_2 + 0x55) = *(char *)((longlong)param_2 + 0x55) + '\x01';
        param_2[5] = _Dst;
        _Dst[0xd] = param_2;
        _Dst[0xe] = param_2[8];
      }
      bVar8 = (char)uVar9 + 1;
      uVar9 = (ulonglong)bVar8;
    } while (bVar8 < *(byte *)(lVar1 + 0x16));
  }
  *(char *)((longlong)param_2 + 0x56) = *(char *)((longlong)param_2 + 0x56) + '\x01';
  NvRaidPacketSubmitSubRequests(param_2 + 4);
  return 0x103;
}



===== FUN_00016334 @ 00016334 =====

undefined8 FUN_00016334(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 *_Dst;
  longlong lVar7;
  uint uVar8;
  undefined8 *puVar9;
  byte bVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  longlong lVar13;
  ulonglong uVar14;
  uint uVar15;
  longlong lVar16;
  
  lVar1 = *(longlong *)(param_1 + 0x18);
  lVar2 = *(longlong *)(param_1 + 0x58);
  uVar15 = 0;
  if (param_2[0x15] == 0) {
    uVar6 = 0xc0000010;
  }
  else {
    uVar11 = 0;
    if (*(char *)(lVar2 + 0x16) != '\0') {
      do {
        if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)uVar11)) {
          lVar16 = 0;
        }
        else {
          lVar16 = *(longlong *)(*(longlong *)(param_1 + 0x80) + uVar11 * 8);
        }
        if (lVar16 != 0) {
          _Dst = NvRaidResNrpAllocate(lVar1);
          if ((((uint)param_2 | (uint)_Dst) & 0xf) == 0) {
            lVar7 = 1;
            puVar3 = _Dst;
            puVar4 = param_2;
            do {
              puVar12 = puVar4;
              puVar9 = puVar3;
              uVar6 = puVar12[1];
              *puVar9 = *puVar12;
              puVar9[1] = uVar6;
              uVar6 = puVar12[3];
              puVar9[2] = puVar12[2];
              puVar9[3] = uVar6;
              uVar6 = puVar12[5];
              puVar9[4] = puVar12[4];
              puVar9[5] = uVar6;
              uVar6 = puVar12[7];
              puVar9[6] = puVar12[6];
              puVar9[7] = uVar6;
              uVar6 = puVar12[9];
              puVar9[8] = puVar12[8];
              puVar9[9] = uVar6;
              uVar6 = puVar12[0xb];
              puVar9[10] = puVar12[10];
              puVar9[0xb] = uVar6;
              uVar6 = puVar12[0xd];
              puVar9[0xc] = puVar12[0xc];
              puVar9[0xd] = uVar6;
              uVar6 = puVar12[0xf];
              puVar9[0xe] = puVar12[0xe];
              puVar9[0xf] = uVar6;
              lVar7 = lVar7 + -1;
              puVar3 = puVar9 + 0x10;
              puVar4 = puVar12 + 0x10;
            } while (lVar7 != 0);
            uVar6 = puVar12[0x11];
            puVar9[0x10] = puVar12[0x10];
            puVar9[0x11] = uVar6;
            uVar6 = puVar12[0x13];
            puVar9[0x12] = puVar12[0x12];
            puVar9[0x13] = uVar6;
            uVar6 = puVar12[0x15];
            puVar9[0x14] = puVar12[0x14];
            puVar9[0x15] = uVar6;
            uVar6 = puVar12[0x17];
            puVar9[0x16] = puVar12[0x16];
            puVar9[0x17] = uVar6;
            uVar6 = puVar12[0x19];
            puVar9[0x18] = puVar12[0x18];
            puVar9[0x19] = uVar6;
            uVar6 = puVar12[0x1b];
            puVar9[0x1a] = puVar12[0x1a];
            puVar9[0x1b] = uVar6;
            uVar6 = puVar12[0x1d];
            puVar9[0x1c] = puVar12[0x1c];
            puVar9[0x1d] = uVar6;
          }
          else {
            memcpy(_Dst,param_2,0xf0);
          }
          *(uint *)(_Dst + 0xc) = *(uint *)(_Dst + 0xc) & 0xfffffcff;
          _Dst[4] = 0;
          *(undefined1 *)((longlong)_Dst + 0x55) = 0;
          _Dst[5] = _Dst + 4;
          NvRaidResSgGroupAllocateForNrp(lVar1,(longlong)_Dst);
          lVar7 = param_2[0x15];
          uVar5 = 0;
          uVar8 = 0;
          if (*(short *)(lVar7 + 6) == 0) {
            do {
              lVar7 = *(longlong *)(lVar7 + 8);
              uVar5 = uVar5 - uVar8;
              uVar8 = (uint)*(ushort *)(lVar7 + 6);
            } while (uVar8 <= uVar5);
          }
          lVar13 = _Dst[0x15];
          uVar14 = (ulonglong)uVar5;
          uVar5 = 0;
          uVar8 = 0;
          if (*(short *)(lVar13 + 6) == 0) {
            do {
              lVar13 = *(longlong *)(lVar13 + 8);
              uVar5 = uVar5 - uVar8;
              uVar8 = (uint)*(ushort *)(lVar13 + 6);
            } while (uVar8 <= uVar5);
          }
          *(ulonglong *)(lVar13 + 0x18 + (ulonglong)uVar5 * 0x10) =
               (ulonglong)(uVar15 * *(int *)(lVar7 + 0x20 + uVar14 * 0x10)) +
               *(longlong *)(lVar7 + 0x18 + uVar14 * 0x10);
          *(undefined4 *)(lVar13 + 0x20 + (ulonglong)uVar5 * 0x10) =
               *(undefined4 *)(lVar7 + 0x20 + uVar14 * 0x10);
          *_Dst = 0;
          *(char *)(_Dst + 9) = (char)uVar11;
          _Dst[8] = lVar16;
          _Dst[0x14] = NvRaidStateSubRequestsDone;
          _Dst[1] = param_2[5];
          *(undefined8 **)param_2[5] = _Dst;
          *(char *)((longlong)param_2 + 0x55) = *(char *)((longlong)param_2 + 0x55) + '\x01';
          param_2[5] = _Dst;
          _Dst[0xd] = param_2;
          uVar15 = (uint)(byte)((char)uVar15 + 1);
          _Dst[0xe] = param_2[8];
        }
        bVar10 = (char)uVar11 + 1;
        uVar11 = (ulonglong)bVar10;
      } while (bVar10 < *(byte *)(lVar2 + 0x16));
    }
    *(char *)((longlong)param_2 + 0x56) = *(char *)((longlong)param_2 + 0x56) + '\x01';
    NvRaidPacketSubmitSubRequests(param_2 + 4);
    uVar6 = 0x103;
  }
  return uVar6;
}



===== FUN_00016578 @ 00016578 =====

undefined8 FUN_00016578(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  undefined8 *puVar4;
  byte bVar5;
  ulonglong uVar6;
  longlong lVar7;
  int iVar8;
  ulonglong uVar9;
  uint uVar10;
  bool bVar11;
  
  lVar1 = *(longlong *)(param_1 + 0x58);
  lVar2 = *(longlong *)(param_2 + 0x88);
  bVar5 = (byte)*(undefined4 *)(lVar1 + 0x24);
  iVar8 = *(int *)(param_2 + 0x90) << (bVar5 & 0x1f);
  bVar11 = (*(byte *)(param_2 + 0x81) & 2) == 0;
  if (bVar11) {
    uVar6 = 0;
  }
  else {
    uVar6 = (ulonglong)(byte)(*(char *)(param_2 + 0x82) + *(byte *)(lVar1 + 0x15)) %
            (ulonglong)(longlong)(int)((uint)*(byte *)(lVar1 + 0x15) * 2);
  }
  bVar11 = !bVar11;
  uVar9 = 0;
  uVar10 = iVar8 * 0x200;
  while (((byte)uVar6 < *(byte *)(lVar1 + 0x15) || (bVar11))) {
    if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)(uVar6 & 0xff))) {
      lVar7 = 0;
    }
    else {
      lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (uVar6 & 0xff) * 8);
    }
    if (((lVar7 == 0) || ((*(uint *)(lVar7 + 4) & 1) != 0)) ||
       ((*(uint *)(lVar7 + 4) >> 8 & 1) != 0)) {
      lVar7 = 0;
    }
    if (lVar7 != 0) {
      puVar4 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
      if (puVar4 == (undefined8 *)0x0) {
        return 0xc000009a;
      }
      NvRaidScsiSetupReadWrite
                ((longlong)puVar4,*(undefined1 *)(lVar7 + 8),lVar7,NvRaidStateSubRequestsDone,0x28,
                 lVar2 << (bVar5 & 0x3f),iVar8);
      NvRaidPacketScatterGatherGroupAllocBuildPartialGroup(param_2,(longlong)puVar4,uVar9,uVar10);
      *puVar4 = 0;
      puVar4[1] = *(undefined8 *)(param_2 + 0x28);
      **(undefined8 **)(param_2 + 0x28) = puVar4;
      *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
      *(undefined8 **)(param_2 + 0x28) = puVar4;
      puVar4[0xd] = param_2;
      puVar4[0xe] = *(undefined8 *)(param_2 + 0x40);
    }
    if (bVar11) {
      cVar3 = *(char *)(lVar1 + 0x15);
    }
    else {
      cVar3 = '\x01';
    }
    uVar6 = (ulonglong)(byte)((byte)uVar6 + cVar3);
    bVar11 = false;
    uVar9 = (ulonglong)((int)uVar9 + uVar10);
  }
  *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
  NvRaidPacketSubmitSubRequests((longlong *)(param_2 + 0x20));
  return 0x103;
}



===== FUN_00016720 @ 00016720 =====

undefined8 FUN_00016720(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x58);
  for (puVar1 = *(undefined8 **)(param_2 + 0x20); puVar1 != (undefined8 *)0x0;
      puVar1 = (undefined8 *)*puVar1) {
    *(char *)(puVar1 + 9) = *(char *)(puVar1 + 9) + *(char *)(lVar2 + 0x15);
    uVar3 = (ulonglong)*(byte *)(puVar1 + 9) %
            (ulonglong)(longlong)(int)((uint)*(byte *)(lVar2 + 0x15) * 2);
    *(char *)(puVar1 + 9) = (char)uVar3;
    uVar3 = uVar3 & 0xff;
    if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)uVar3)) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined8 *)(*(longlong *)(param_1 + 0x80) + uVar3 * 8);
    }
    puVar1[8] = uVar4;
    *(undefined2 *)((longlong)puVar1 + 0x81) = 0x22a;
    *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
  }
  *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
  NvRaidPacketSubmitSubRequests((longlong *)(param_2 + 0x20));
  return 0x103;
}



===== NvRaidTimerQueueEvent @ 000167a4 =====

undefined8
NvRaidTimerQueueEvent
          (longlong param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  puVar2 = (undefined8 *)NvRaidResResourceAllocate((longlong *)(param_1 + 0xb0),0x30);
  if (puVar2 == (undefined8 *)0x0) {
    DbgPrint("NvRaidTimerQueueEvent: Failed to allocate TimerEvent\n");
    uVar3 = 0xc000009a;
  }
  else {
    puVar2[3] = param_4;
    *(undefined4 *)(puVar2 + 4) = param_2;
    puVar2[2] = FUN_00011e84;
    puVar2[5] = param_5;
    for (puVar4 = *(undefined8 **)(param_1 + 0xa0); puVar4 != (undefined8 *)0x0;
        puVar4 = (undefined8 *)*puVar4) {
      uVar1 = *(uint *)(puVar2 + 4);
      if (uVar1 < *(uint *)(puVar4 + 4)) {
        *(uint *)(puVar4 + 4) = *(int *)(puVar4 + 4) - uVar1;
        uVar3 = puVar4[1];
        *puVar2 = puVar4;
        puVar2[1] = uVar3;
        *(undefined8 **)puVar4[1] = puVar2;
        puVar4[1] = puVar2;
        goto LAB_00016845;
      }
      *(uint *)(puVar2 + 4) = uVar1 - *(uint *)(puVar4 + 4);
    }
    *puVar2 = 0;
    puVar2[1] = *(undefined8 *)(param_1 + 0xa8);
    **(undefined8 **)(param_1 + 0xa8) = puVar2;
    *(undefined8 **)(param_1 + 0xa8) = puVar2;
LAB_00016845:
    uVar3 = 0;
  }
  return uVar3;
}



===== NvRaidVolumeSendCommandToVolumes @ 00016874 =====

undefined8 NvRaidVolumeSendCommandToVolumes(longlong param_1,undefined *param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  byte bVar5;
  
  iVar1 = (*(code *)param_2)(param_1,param_3);
  if (iVar1 == 0) {
    if ((*(longlong *)(param_1 + 0x58) != 0) && (bVar5 = 0, *(int *)(param_1 + 0x7c) != 0)) {
      uVar3 = 0;
      do {
        if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)uVar3)) {
          lVar4 = 0;
        }
        else {
          lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x80) + uVar3 * 8);
        }
        if (lVar4 != 0) {
          uVar2 = NvRaidVolumeSendCommandToVolumes(lVar4,param_2,param_3);
          if ((int)uVar2 != 0) goto LAB_0001689e;
        }
        bVar5 = bVar5 + 1;
        uVar3 = (ulonglong)bVar5;
      } while ((uint)bVar5 < *(uint *)(param_1 + 0x7c));
    }
    uVar2 = 0;
  }
  else {
LAB_0001689e:
    uVar2 = 1;
  }
  return uVar2;
}



===== NvRaidVolumeSendCommandToArrays @ 0001690c =====

undefined8 NvRaidVolumeSendCommandToArrays(longlong param_1,undefined *param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  byte bVar5;
  
  if ((*(longlong *)(param_1 + 0x58) == 0) ||
     (iVar1 = (*(code *)param_2)(param_1,param_3), iVar1 == 0)) {
    bVar5 = 0;
    if (*(int *)(param_1 + 0x7c) != 0) {
      uVar3 = 0;
      do {
        if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)uVar3)) {
          lVar4 = 0;
        }
        else {
          lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x80) + uVar3 * 8);
        }
        if (((lVar4 != 0) && (-1 < (char)*(undefined4 *)(lVar4 + 4))) &&
           (uVar2 = NvRaidVolumeSendCommandToArrays(lVar4,param_2,param_3), (int)uVar2 != 0))
        goto LAB_0001693e;
        bVar5 = bVar5 + 1;
        uVar3 = (ulonglong)bVar5;
      } while ((uint)bVar5 < *(uint *)(param_1 + 0x7c));
    }
    uVar2 = 0;
  }
  else {
LAB_0001693e:
    uVar2 = 1;
  }
  return uVar2;
}



===== NvRaidVolumeCleanup @ 000169b8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 NvRaidVolumeCleanup(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  byte bVar5;
  
  piVar1 = param_1 + 0x1e;
  if ((*piVar1 != 0) && (bVar5 = 0, param_1[0x1f] != 0)) {
    uVar3 = 0;
    do {
      if ((piVar1 == (int *)0x0) || ((uint)param_1[0x1f] <= (uint)uVar3)) {
        lVar4 = 0;
      }
      else {
        lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x20) + uVar3 * 8);
      }
      if (lVar4 != 0) {
        NvRaidVolumeDeleteVolumeFromArray(param_1,lVar4);
      }
      bVar5 = bVar5 + 1;
      uVar3 = (ulonglong)bVar5;
    } while ((uint)bVar5 < (uint)param_1[0x1f]);
  }
  if (param_1[0x1f] != 0) {
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x20),0);
  }
  piVar1[0] = 0;
  piVar1[1] = 0;
  *(undefined8 *)(param_1 + 0x20) = 0;
  (*(code *)**(undefined8 **)(param_1 + 0x18))(param_1);
  puVar2 = *(undefined4 **)(param_1 + 0x16);
  if (puVar2 != (undefined4 *)0x0) {
    lVar4 = *(longlong *)(param_1 + 6);
    _DAT_0002907c = _DAT_0002907c + 1;
    *puVar2 = 0x3b8;
    *(undefined8 *)(puVar2 + 2) = *(undefined8 *)(lVar4 + 0xd0);
    *(undefined4 **)(lVar4 + 0xd0) = puVar2;
  }
  return 0;
}



===== NvRaidVolumeAddVolumeToArray @ 00016a70 =====

undefined8 NvRaidVolumeAddVolumeToArray(longlong param_1,longlong param_2,byte param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  byte bVar6;
  uint uVar7;
  longlong lVar8;
  
  lVar8 = 0;
  uVar7 = (uint)param_3;
  if (param_2 == 0) {
    return 0xc000000d;
  }
  puVar1 = *(undefined4 **)(param_2 + 0x50);
  if (puVar1 != (undefined4 *)0x0) {
    if (*(undefined4 **)(param_2 + 0x18) != puVar1) {
      if ((undefined4 *)param_1 != puVar1) {
        return 0xc0000001;
      }
      if ((param_1 != -0x78) && ((uint)*(byte *)(param_2 + 8) < *(uint *)(param_1 + 0x7c))) {
        lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)*(byte *)(param_2 + 8) * 8)
        ;
      }
      if (param_2 == lVar8) {
        return 0;
      }
      return 0xc0000001;
    }
    NvRaidVolumeDeleteVolumeFromArray(puVar1,param_2);
  }
  if (param_1 == *(longlong *)(param_2 + 0x18)) {
LAB_00016b01:
    if (param_3 != 0xff) goto LAB_00016b43;
  }
  else {
    if (param_3 != 0xff) goto LAB_00016b43;
    *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 0x100;
    if ((*(uint *)(param_1 + 4) & 0x20) != 0) {
      *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffeff;
      goto LAB_00016b01;
    }
  }
  uVar7 = 0;
  if (*(uint *)(param_1 + 0x7c) != 0) {
    uVar3 = 0;
    uVar2 = 0;
    do {
      uVar7 = uVar2;
      if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= uVar3)) {
        lVar8 = 0;
      }
      else {
        lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)uVar3 * 8);
      }
      if (lVar8 == 0) break;
      bVar6 = (char)uVar7 + 1;
      uVar7 = (uint)bVar6;
      uVar3 = (uint)bVar6;
      uVar2 = (uint)bVar6;
    } while (uVar3 < *(uint *)(param_1 + 0x7c));
  }
LAB_00016b43:
  NvRaidExtendValueSet((int *)(param_1 + 0x78),uVar7,param_2);
  *(char *)(param_2 + 8) = (char)uVar7;
  *(longlong *)(param_2 + 0x50) = param_1;
  if (param_1 == *(longlong *)(param_1 + 0x18)) {
    if (*(longlong *)(param_2 + 0x58) == 0) {
      *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 0x100;
    }
  }
  else {
    *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 8;
    if ((*(longlong *)(param_1 + 0x58) != 0) &&
       (uVar5 = (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x58) + 0x88) + 0x30))(param_1,5)
       , (uVar5 & 6) != 0)) {
      if ((*(uint *)(param_1 + 4) & 0x20) != 0) {
        uVar5 = NvRaidVolumeCalculateArrayCapacity
                          (param_1,*(byte *)(*(longlong *)(param_1 + 0x58) + 0x15),
                           *(byte *)(*(longlong *)(param_1 + 0x58) + 0x16));
        *(ulonglong *)(*(longlong *)(param_1 + 0x58) + 0x48) = uVar5;
        lVar8 = *(longlong *)(param_1 + 0x58);
        *(ulonglong *)(param_1 + 0x20) = uVar5;
        *(ulonglong *)(lVar8 + 0x50) = uVar5;
        uVar4 = (undefined4)uVar5;
        if (0xffffffff < uVar5) {
          uVar4 = 0;
        }
        *(undefined4 *)(lVar8 + 0x3c) = uVar4;
        NvRaidVolumeUpdateProductId(param_1);
      }
      if (((*(char *)(*(longlong *)(param_1 + 0x58) + 0x14) != '\x04') ||
          (*(int *)(*(longlong *)(param_1 + 0x58) + 0x38) != 0x80)) ||
         ((*(uint *)(param_1 + 4) & 4) == 0)) {
        NvRaidVolumeProbeArrayInfo(param_1);
      }
      lVar8 = *(longlong *)(param_1 + 0x58);
      if ((((*(uint *)(lVar8 + 0xb0) & 1) == 0) && (*(char *)(lVar8 + 0x14) == '\0')) &&
         (((byte)*(undefined4 *)(param_1 + 4) & 7) == 2)) {
        uVar5 = NvRaidVolumeCalculateArrayCapacity
                          (param_1,*(byte *)(lVar8 + 0x15),*(byte *)(lVar8 + 0x16));
        *(ulonglong *)(*(longlong *)(param_1 + 0x58) + 0x48) = uVar5;
        lVar8 = *(longlong *)(param_1 + 0x58);
        *(ulonglong *)(param_1 + 0x20) = uVar5;
        *(ulonglong *)(lVar8 + 0x50) = uVar5;
        uVar4 = (undefined4)uVar5;
        if (0xffffffff < uVar5) {
          uVar4 = 0;
        }
        *(undefined4 *)(lVar8 + 0x3c) = uVar4;
        lVar8 = *(longlong *)(param_1 + 0x58);
        *(undefined8 *)(lVar8 + 0x58) = 0;
        *(undefined4 *)(lVar8 + 0x34) = 0;
      }
    }
  }
  NvRaidApiFireEvent(param_1,2,param_2);
  return 0;
}



===== NvRaidVolumeCalculateArrayCapacity @ 00016c80 =====

longlong NvRaidVolumeCalculateArrayCapacity(longlong param_1,byte param_2,byte param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong lVar8;
  ulonglong uVar9;
  
  lVar1 = *(longlong *)(param_1 + 0x58);
  uVar9 = 0xffffffffffffffff;
  if (lVar1 == 0) {
    lVar8 = 0;
  }
  else {
    uVar6 = *(uint *)(param_1 + 0x78);
    if ((uVar6 < param_3) || (param_3 == 0)) {
      lVar8 = 0xc000000d;
    }
    else {
      lVar2 = *(longlong *)(param_1 + 0x80);
      uVar5 = 0;
      if (uVar6 != 0) {
        do {
          lVar8 = *(longlong *)(lVar2 + uVar5 * 8);
          if (lVar8 == 0) break;
          uVar7 = *(ulonglong *)(lVar8 + 0x20);
          if (uVar7 < uVar9) {
            uVar9 = uVar7;
          }
          uVar4 = (int)uVar5 + 1;
          uVar5 = (ulonglong)uVar4;
        } while (uVar4 < uVar6);
      }
      uVar7 = uVar5;
      if ((uint)uVar5 < *(uint *)(param_1 + 0x7c)) {
        do {
          if (*(uint *)(param_1 + 0x78) <= (uint)uVar5) break;
          lVar8 = *(longlong *)(lVar2 + uVar7 * 8);
          if (lVar8 != 0) {
            if (*(ulonglong *)(lVar8 + 0x20) < uVar9) {
              uVar9 = *(ulonglong *)(lVar8 + 0x20);
            }
            *(longlong *)(lVar2 + uVar5 * 8) = lVar8;
            *(char *)(lVar8 + 8) = (char)uVar5;
            *(undefined8 *)(lVar2 + uVar7 * 8) = 0;
            uVar5 = (ulonglong)((uint)uVar5 + 1);
          }
          uVar6 = (int)uVar7 + 1;
          uVar7 = (ulonglong)uVar6;
        } while (uVar6 < *(uint *)(param_1 + 0x7c));
      }
      if (*(int *)(lVar1 + 0x18) == 0xff) {
        lVar8 = 0;
        uVar9 = 0;
        if (param_2 != 0) {
          do {
            if ((*(uint *)(param_1 + 0x78) <= (uint)uVar9) ||
               (lVar3 = *(longlong *)(lVar2 + uVar9 * 8), lVar3 == 0)) break;
            uVar6 = (uint)uVar9 + 1;
            uVar9 = (ulonglong)uVar6;
            lVar8 = lVar8 + ((ulonglong)~(*(int *)(lVar1 + 0x1c) - 1U) &
                            *(longlong *)(lVar3 + 0x20) - 2U);
          } while (uVar6 < param_2);
        }
      }
      else {
        lVar8 = ((uVar9 - 2) / (ulonglong)*(uint *)(lVar1 + 0x1c)) * (ulonglong)param_2 <<
                ((byte)*(undefined4 *)(lVar1 + 0x24) & 0x3f);
      }
    }
  }
  return lVar8;
}



===== NvRaidVolumeUpdateProductId @ 00016da4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 NvRaidVolumeUpdateProductId(longlong param_1)

{
  int *piVar1;
  char *pcVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  int *piVar9;
  uint uVar10;
  char *pcVar11;
  longlong lVar12;
  undefined1 auStack_48 [32];
  undefined4 local_28;
  undefined1 local_24;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0x474d4b42;
  local_24 = 0x54;
  if (*(longlong *)(param_1 + 0x58) != 0) {
    uVar10 = 0;
    uVar6 = 10;
    do {
      if (9 < uVar6) {
        uVar6 = uVar6 - 9;
        break;
      }
      uVar10 = uVar10 + 1;
      uVar6 = uVar6 + 10;
    } while (uVar10 < 5);
    uVar5 = 0;
    uVar7 = *(ulonglong *)(param_1 + 0x20);
    uVar4 = 0;
    while( true ) {
      uVar8 = uVar7;
      uVar3 = (uint)uVar5;
      uVar5 = uVar4;
      if (4 < uVar10) break;
      if (uVar4 == *(ulonglong *)(param_1 + 0x20)) {
        uVar4 = 0;
      }
      uVar3 = (uint)uVar4;
      uVar7 = uVar8 >> ((byte)uVar6 & 0x3f);
      uVar6 = 10;
      uVar5 = uVar8;
      if (uVar7 == 0) break;
      uVar10 = uVar10 + 1;
      uVar5 = uVar4;
      uVar4 = uVar8;
    }
    piVar9 = (int *)0x0;
    piVar1 = *(int **)(*(longlong *)(param_1 + 0x58) + 0x88);
    if (*piVar1 != 0) {
      piVar9 = piVar1 + 1;
    }
    NvRaidVolumeBuildPaddedString((char *)(param_1 + 0x34),(char *)piVar9,0x10);
    lVar12 = 2;
    *(undefined1 *)(param_1 + 0x43) = auStack_48[(ulonglong)uVar10 + 0x20];
    pcVar2 = (char *)(param_1 + 0x42);
    uVar7 = ((ulonglong)(uVar3 & 0x3ff) * 1000) / 0x2800;
    do {
      pcVar11 = pcVar2;
      *pcVar11 = (char)uVar7 + (char)(uVar7 / 10) * -10 + '0';
      lVar12 = lVar12 + -1;
      pcVar2 = pcVar11 + -1;
      uVar7 = uVar7 / 10;
    } while (lVar12 != 0);
    pcVar11[-1] = '.';
    pcVar11 = pcVar11 + -2;
    for (; uVar5 != 0; uVar5 = uVar5 / 10) {
      *pcVar11 = (char)uVar5 + (char)(uVar5 / 10) * -10 + '0';
      pcVar11 = pcVar11 + -1;
    }
  }
  return 0;
}



===== NvRaidVolumeDeleteVolumeFromArray @ 00016f10 =====

undefined8 NvRaidVolumeDeleteVolumeFromArray(undefined4 *param_1,longlong param_2)

{
  uint *puVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  undefined8 uVar5;
  byte bVar6;
  longlong lVar7;
  longlong lVar8;
  ulonglong uVar9;
  
  bVar3 = false;
  if (param_1 == (undefined4 *)0x0) {
LAB_0001708f:
    uVar5 = 0;
  }
  else {
    if (param_1 == *(undefined4 **)(param_2 + 0x50)) {
      bVar2 = *(byte *)(param_2 + 8);
      uVar9 = (ulonglong)bVar2;
      puVar1 = param_1 + 0x1e;
      if ((puVar1 == (uint *)0x0) || ((uint)param_1[0x1f] <= (uint)bVar2)) {
        lVar7 = 0;
      }
      else {
        lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x20) + uVar9 * 8);
      }
      if (param_2 == lVar7) {
        lVar7 = *(longlong *)(param_1 + 0x16);
        if (lVar7 != 0) {
          bVar6 = *(byte *)(lVar7 + 0x16);
          uVar4 = (uint)bVar6;
          if (uVar4 <= *puVar1) {
            while (uVar4 < (uint)param_1[0x1f]) {
              if ((puVar1 == (uint *)0x0) || ((uint)param_1[0x1f] <= uVar4)) {
                lVar8 = 0;
              }
              else {
                lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x20) + (ulonglong)uVar4 * 8);
              }
              if ((lVar8 != 0) && (param_2 == lVar8)) {
                bVar3 = true;
                break;
              }
              bVar6 = bVar6 + 1;
              uVar4 = (uint)bVar6;
            }
          }
        }
        if ((puVar1 == (uint *)0x0) || ((uint)param_1[0x1f] <= (uint)bVar2)) {
          lVar8 = 0;
        }
        else {
          lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x20) + uVar9 * 8);
        }
        if (lVar8 != 0) {
          *(undefined8 *)(*(longlong *)(param_1 + 0x20) + uVar9 * 8) = 0;
          *puVar1 = *puVar1 - 1;
        }
        *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) & 0xfffffff7;
        *(undefined8 *)(param_2 + 0x50) = 0;
        if (param_1 != *(undefined4 **)(param_2 + 0x18)) {
          if ((*(uint *)(param_2 + 4) & 1) == 0) {
            NvRaidJobScheduleRequest(param_2,7,0,1,0,0);
          }
          if ((param_1[1] & 6) != 0) {
            (**(code **)(*(longlong *)(*(longlong *)(param_1 + 0x16) + 0x88) + 0x30))(param_1,1);
          }
          NvRaidVolumeAddVolumeToArray(*(longlong *)(param_2 + 0x18),param_2,0xff);
          NvRaidApiFireEvent((longlong)param_1,1,param_2);
          if ((param_1[1] & 1) == 0) {
            if ((!bVar3) && (*(char *)(lVar7 + 0x14) == '\x03')) {
              *(undefined1 *)(lVar7 + 0x14) = 0;
              lVar7 = *(longlong *)(param_1 + 0x16);
              *(undefined8 *)(lVar7 + 0x58) = 0;
              *(undefined4 *)(lVar7 + 0x34) = 0;
            }
          }
          else if (*puVar1 == 0) {
            NvRaidApiDestroyVolume(*(longlong *)(param_1 + 6),param_1);
          }
        }
        goto LAB_0001708f;
      }
    }
    uVar5 = 0xc000000d;
  }
  return uVar5;
}



===== NvRaidVolumeDefaultSendCommand @ 000170b0 =====

undefined8 NvRaidVolumeDefaultSendCommand(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong *plVar2;
  undefined4 *puVar3;
  undefined1 *_Dst;
  char cVar4;
  undefined4 uVar5;
  undefined **ppuVar6;
  undefined8 uVar7;
  longlong lVar8;
  
  cVar4 = *(char *)(param_2 + 0x80);
  if (cVar4 == -2) {
    cVar4 = *(char *)(param_2 + 0x81);
  }
  if (cVar4 == '\0') {
LAB_000172d7:
    *(undefined4 *)(param_2 + 0x50) = 0;
    goto LAB_000172dd;
  }
  if (cVar4 == '\x12') {
    _Dst = *(undefined1 **)(*(longlong *)(param_2 + 0xa8) + 0x18);
    memset(_Dst,0,(ulonglong)*(uint *)(*(longlong *)(param_2 + 0xa8) + 0x20));
    *_Dst = 0;
    lVar8 = *(longlong *)(param_2 + 0x40);
    *(undefined8 *)(_Dst + 8) = *(undefined8 *)(lVar8 + 0x2c);
    *(undefined8 *)(_Dst + 0x10) = *(undefined8 *)(lVar8 + 0x34);
    *(undefined8 *)(_Dst + 0x18) = *(undefined8 *)(lVar8 + 0x3c);
    *(undefined4 *)(_Dst + 0x20) = *(undefined4 *)(lVar8 + 0x44);
    *(undefined2 *)(_Dst + 2) = 0x204;
    _Dst[4] = 0x1f;
  }
  else if (cVar4 == '%') {
    puVar3 = *(undefined4 **)(*(longlong *)(param_2 + 0xa8) + 0x18);
    lVar8 = *(longlong *)(*(longlong *)(param_2 + 0x40) + 0x58);
    if (*(char *)(lVar8 + 0x14) == '\x04') {
      lVar8 = *(longlong *)(lVar8 + 0x50);
    }
    else {
      lVar8 = *(longlong *)(*(longlong *)(param_2 + 0x40) + 0x20);
    }
    uVar5 = (undefined4)(lVar8 - 1U);
    if (0xfffffffe < lVar8 - 1U) {
      uVar5 = 0xffffffff;
    }
    *puVar3 = uVar5;
    puVar3[1] = *(undefined4 *)(*(longlong *)(param_2 + 0x40) + 0x28);
  }
  else {
    if ((cVar4 == '/') || (cVar4 == -0x71)) goto LAB_000172d7;
    if (cVar4 != -0x62) {
      if (cVar4 != -1) {
        return 0xc0000010;
      }
      bVar1 = *(byte *)(param_2 + 0x81);
      if (bVar1 == 1) {
LAB_000171ce:
        *(undefined1 *)(param_2 + 0x56) = 0;
        *(undefined ***)(param_2 + 0x58) = &PTR_FUN_000275a0;
        if ((*(longlong *)(param_1 + 0x58) == 0) && (*(char *)(param_2 + 0x81) == '\x01')) {
          return 0xc0000010;
        }
      }
      else {
        if (bVar1 < 2) {
          return 0xc0000010;
        }
        if (bVar1 < 6) {
          uVar7 = NvRaidJobInitialize(param_1,param_2);
          return uVar7;
        }
        if (bVar1 == 6) {
          ppuVar6 = &PTR_FUN_00027920;
        }
        else {
          if (bVar1 == 7) goto LAB_000171ce;
          if (bVar1 == 8) {
            *(undefined1 *)(param_2 + 0x56) = 0;
            *(undefined ***)(param_2 + 0x58) = &PTR_FUN_00027480;
            if ((*(longlong *)(param_1 + 0x58) == 0) || ((*(uint *)(param_1 + 4) & 0x41) != 0)) {
              *(undefined4 *)(param_2 + 0x50) = 0xc00000a3;
              *(undefined4 *)(param_2 + 0x4b) = 0xb02;
              NvRaidPacketCompleteRequest(param_2);
              return 0x103;
            }
            *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x40;
            NvRaidApiFireEvent(param_1,6,0);
            NvRaidPacketExecuteStateMachine(param_1,param_2);
            return 0x103;
          }
          if (bVar1 != 10) {
            return 0xc0000010;
          }
          ppuVar6 = &PTR_FUN_00027570;
        }
        *(undefined1 *)(param_2 + 0x56) = 0;
        *(undefined ***)(param_2 + 0x58) = ppuVar6;
      }
      FUN_00011e84(param_2);
      return 0x103;
    }
    plVar2 = *(longlong **)(*(longlong *)(param_2 + 0xa8) + 0x18);
    lVar8 = *(longlong *)(*(longlong *)(param_2 + 0x40) + 0x58);
    if (*(char *)(lVar8 + 0x14) == '\x04') {
      lVar8 = *(longlong *)(lVar8 + 0x50);
    }
    else {
      lVar8 = *(longlong *)(*(longlong *)(param_2 + 0x40) + 0x20);
    }
    *plVar2 = lVar8 + -1;
    *(undefined4 *)(plVar2 + 1) = *(undefined4 *)(*(longlong *)(param_2 + 0x40) + 0x28);
  }
  *(undefined4 *)(param_2 + 0x50) = 0;
LAB_000172dd:
  NvRaidPacketCompleteRequest(param_2);
  return 0;
}



===== FUN_000172fc @ 000172fc =====

undefined8 FUN_000172fc(longlong param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  NvRaidResNrpFree(*(longlong *)(param_1 + 0x18),param_2);
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffffaf;
  if ((*(uint *)(param_1 + 4) & 0x20) != 0) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffffdf;
    NvRaidJobScheduleRequest(param_1,1,0,0,0,0);
  }
  if (*(longlong *)(param_1 + 0x58) == 0) {
    uVar1 = NvRaidSyncSpinLockAcquire(4);
    if ((DAT_000290b4 & 4) == 0) {
      uVar2 = DAT_000290b4 | 4;
      while( true ) {
        uVar3 = uVar2;
        LOCK();
        UNLOCK();
        uVar2 = DAT_000290b4 | 4;
        DAT_000290b4 = uVar3;
        if (uVar2 == uVar3) break;
      }
    }
    NvRaidSyncSpinLockRelease(uVar1);
  }
  return 0;
}



===== NvRaidVolumeProbeArrayInfo @ 00017380 =====

undefined8 NvRaidVolumeProbeArrayInfo(longlong param_1)

{
  undefined1 uVar1;
  uint uVar2;
  undefined8 uVar3;
  void *pvVar4;
  
  uVar2 = *(uint *)(param_1 + 4);
  if ((uVar2 & 0x40) == 0) {
    if ((uVar2 & 0x10) == 0) {
      NvRaidJobScheduleRequest(param_1,1,0,0,0,0);
    }
    else {
      *(uint *)(param_1 + 4) = uVar2 | 0x40;
      pvVar4 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
      if (pvVar4 == (void *)0x0) {
        return 0xc000009a;
      }
      uVar1 = *(undefined1 *)(param_1 + 8);
      *(longlong *)((longlong)pvVar4 + 0x40) = param_1;
      *(undefined1 *)((longlong)pvVar4 + 0x48) = uVar1;
      uVar1 = *(undefined1 *)(param_1 + 8);
      *(undefined1 *)((longlong)pvVar4 + 0x4a) = 5;
      *(undefined1 *)((longlong)pvVar4 + 0x48) = uVar1;
      *(code **)((longlong)pvVar4 + 0xa0) = FUN_000172fc;
      *(undefined2 *)((longlong)pvVar4 + 0x80) = 0x6ff;
      *(longlong *)((longlong)pvVar4 + 0x70) = param_1;
      NvRaidPacketSubmitRequest((longlong)pvVar4);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0x80000011;
  }
  return uVar3;
}



===== FUN_00017414 @ 00017414 =====

undefined8 FUN_00017414(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  NvRaidResNrpFreePacketResources(*(longlong *)(param_1 + 0x18),param_2);
  *(undefined1 *)(param_2 + 0x55) = 0;
  puVar1 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
  if (puVar1 == (undefined8 *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = *(undefined8 *)(param_2 + 0x28);
    **(undefined8 **)(param_2 + 0x28) = puVar1;
    *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
    *(undefined8 **)(param_2 + 0x28) = puVar1;
    puVar1[0xd] = param_2;
    puVar1[0xe] = *(undefined8 *)(param_2 + 0x40);
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
    uVar2 = 0;
  }
  return uVar2;
}



===== FUN_00017480 @ 00017480 =====

ulonglong FUN_00017480(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_2 + 0x20);
  lVar4 = param_2;
  uVar2 = NvRaidResBufferAllocateForNrp
                    (*(longlong *)(param_1 + 0x18),*(uint *)(param_1 + 0x28),param_2);
  if ((int)uVar2 == 0) {
    *(undefined8 *)(lVar1 + 0xa8) = *(undefined8 *)(param_2 + 0xa8);
    NvRaidScsiSetupReadWrite
              (lVar1,*(undefined1 *)(param_1 + 8),param_1,NvRaidStateSubRequestsDone,0x28,
               *(longlong *)(param_1 + 0x20) + -2,1);
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
    *(undefined1 *)(param_2 + 0x55) = 1;
    uVar3 = NvRaidPacketSubmitRequest(lVar1);
  }
  else {
    *(undefined1 *)(param_2 + 0x56) = 0;
    NvRaidResNrpFreePacketResources(*(longlong *)(*(longlong *)(param_2 + 0x40) + 0x18),param_2);
    NvRaidTimerQueueEvent
              (*(longlong *)(*(longlong *)(param_2 + 0x40) + 0x18),1,lVar4,param_2,
               *(longlong *)(param_2 + 0x40));
    uVar3 = 0x103;
  }
  return uVar3;
}



===== FUN_00017540 @ 00017540 =====

undefined8 FUN_00017540(undefined8 param_1,longlong param_2)

{
  uint uVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  longlong lVar5;
  int *piVar6;
  ulonglong uVar7;
  bool bVar8;
  
  piVar2 = *(int **)(*(longlong *)(param_2 + 0xa8) + 0x18);
  if ((piVar2 != (int *)0x0) && (lVar5 = RtlCompareMemory(piVar2,"NVIDIA",6), lVar5 == 6)) {
    uVar1 = piVar2[2];
    iVar4 = 0;
    if (uVar1 != 0) {
      uVar7 = (ulonglong)uVar1;
      piVar6 = piVar2;
      do {
        iVar4 = iVar4 + *piVar6;
        piVar6 = piVar6 + 1;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
      if (iVar4 != 0) goto LAB_0001761d;
    }
    if ((uVar1 == 0x1e) && (piVar2[0xd] == 0x640044)) {
      if ((short)piVar2[0x1e] == 200) {
        uVar1 = *(uint *)((longlong)piVar2 + 0x7a);
        cVar3 = '\0';
        piVar6 = piVar2 + 0x1e;
        if (uVar1 != 0) {
          uVar7 = (ulonglong)uVar1;
          do {
            cVar3 = cVar3 + (char)*piVar6;
            piVar6 = (int *)((longlong)piVar6 + 1);
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
          if (cVar3 != '\0') goto LAB_0001761d;
        }
        if (uVar1 != 0x26) goto LAB_0001761d;
        lVar5 = RtlCompareMemory((longlong)piVar2 + 0x82,"NV64",4);
        bVar8 = lVar5 == 4;
      }
      else {
        bVar8 = (short)piVar2[4] == 100;
      }
      if ((bVar8) && (lVar5 = NvRaidFindRaidLevelMethod(piVar2[0x13]), lVar5 != 0)) {
        *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
        *(longlong *)(param_2 + 0x78) = lVar5;
        return 0;
      }
    }
  }
LAB_0001761d:
  *(undefined8 *)(param_2 + 0x78) = 0;
  *(undefined1 *)(param_2 + 0x56) = 10;
  return 0;
}



===== FUN_00017638 @ 00017638 =====

undefined8 FUN_00017638(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  longlong local_18;
  undefined8 local_10;
  
  local_18 = *(longlong *)(*(longlong *)(param_2 + 0xa8) + 0x18) + 0x38;
  uVar1 = NvRaidVolumeSendCommandToArrays(*(longlong *)(param_1 + 0x18),FUN_0001bdd4,&local_18);
  if ((int)uVar1 == 0) {
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
  }
  else {
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x02';
    *(undefined8 *)(param_2 + 0x78) = local_10;
  }
  return 0;
}



===== FUN_00017688 @ 00017688 =====

undefined8 FUN_00017688(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  longlong local_res8 [4];
  
  uVar1 = NvRaidSectorRestoreArray
                    (*(longlong *)(param_1 + 0x18),*(longlong *)(param_2 + 0x78),
                     *(undefined8 **)(*(longlong *)(param_2 + 0xa8) + 0x18),local_res8);
  if ((int)uVar1 == 0) {
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
    *(longlong *)(param_2 + 0x78) = local_res8[0];
    uVar1 = 0;
  }
  else {
    uVar1 = 0x103;
  }
  return uVar1;
}



===== FUN_000176d0 @ 000176d0 =====

undefined8 FUN_000176d0(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar2 = *(longlong *)(param_2 + 0x78);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xa8) + 0x18);
  bVar1 = *(byte *)(lVar3 + 0x12);
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffeff;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | *(uint *)(lVar3 + 0x30) & 0x100;
  NvRaidVolumeAddVolumeToArray(lVar2,param_1,bVar1);
  *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
  return 0;
}



===== FUN_00017714 @ 00017714 =====

undefined8 FUN_00017714(longlong param_1,longlong param_2)

{
  NvRaidResNrpFreePacketResources(*(longlong *)(param_1 + 0x18),param_2);
  NvRaidPacketCompleteRequest(param_2);
  return 0x103;
}



===== NvRaidVolumeBuildPaddedString @ 0001773c =====

char * NvRaidVolumeBuildPaddedString(char *param_1,char *param_2,uint param_3)

{
  ushort uVar1;
  
  uVar1 = 0;
  if (param_3 != 0) {
    do {
      if (*param_2 == '\0') {
        *param_1 = ' ';
      }
      else {
        *param_1 = *param_2;
        param_2 = param_2 + 1;
      }
      uVar1 = uVar1 + 1;
      param_1 = param_1 + 1;
    } while (uVar1 < param_3);
  }
  return param_1;
}



===== NvRaidSyncSpinLockAcquire @ 00017770 =====

/* WARNING: Removing unreachable block (ram,0x000177a0) */

uint NvRaidSyncSpinLockAcquire(uint param_1)

{
  uint uVar1;
  
  NvRaidSyncAtomicSpinLockAcquire();
  uVar1 = DAT_000291c0;
  if ((DAT_000291c0 & param_1) != param_1) {
    DAT_000291c0 = DAT_000291c0 | param_1;
    LOCK();
    UNLOCK();
  }
  return uVar1;
}



===== NvRaidSyncSpinLockRelease @ 000177b8 =====

void NvRaidSyncSpinLockRelease(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  
  LOCK();
  UNLOCK();
  DAT_000291c0 = param_1;
  uVar1 = NvRaidSyncSpinLockAcquire(~param_1);
  do {
    uVar5 = DAT_000290b4;
    LOCK();
    DAT_000290b4 = 0;
    UNLOCK();
    if (uVar5 == 0) {
LAB_00017850:
      LOCK();
      UNLOCK();
      DAT_000291c0 = uVar1;
      NvRaidSyncAtomicSpinLockRelease();
      NvRaidSyncAtomicSpinLockRelease();
      return;
    }
    uVar4 = uVar5 & param_1;
    if (uVar4 != 0) {
      uVar2 = uVar4;
      while( true ) {
        uVar3 = uVar2;
        LOCK();
        UNLOCK();
        uVar2 = DAT_000290b4 | uVar4;
        DAT_000290b4 = uVar3;
        if (uVar2 == uVar3) break;
      }
    }
    uVar5 = uVar5 & ~param_1;
    if (uVar5 == 0) goto LAB_00017850;
    uVar6 = 0;
    uVar4 = 1;
    do {
      if (0x1f < (uint)uVar6) break;
      if ((uVar5 & uVar4) != 0) {
        if ((code *)(&DAT_000290c0)[uVar6] != (code *)0x0) {
          (*(code *)(&DAT_000290c0)[uVar6])();
        }
        uVar5 = uVar5 & ~uVar4;
      }
      uVar6 = (ulonglong)((uint)uVar6 + 1);
      uVar4 = uVar4 * 2;
    } while (uVar5 != 0);
  } while( true );
}



===== FUN_0001787c @ 0001787c =====

uint FUN_0001787c(longlong param_1,uint param_2)

{
  byte bVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  bool bVar10;
  
  lVar2 = *(longlong *)(param_1 + 0x58);
  if (lVar2 == 0) {
    DbgPrint("NvRaidParityUpdateArrayStatus: Array is null\n");
    uVar5 = 0xc000000d;
  }
  else {
    bVar1 = *(byte *)(lVar2 + 0x15);
    uVar5 = *(uint *)(param_1 + 4) & 0xfffffff8;
    bVar7 = 1;
    if (*(uint *)(param_1 + 0x78) < (uint)bVar1) {
      uVar5 = uVar5 | 1;
    }
    else {
      bVar10 = (param_2 & 2) != 0;
      uVar9 = bVar1 + 1;
      bVar8 = 0;
      bVar6 = 0;
      if (bVar1 != 0xffffffff) {
        uVar3 = 0;
        do {
          if (((uint *)(param_1 + 0x78) == (uint *)0x0) || (*(uint *)(param_1 + 0x7c) <= uVar3)) {
            lVar4 = 0;
          }
          else {
            lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)uVar3 * 8);
          }
          if ((lVar4 == 0) || ((*(uint *)(lVar4 + 4) & 1) != 0)) {
            lVar4 = 0;
          }
          if (lVar4 == 0) {
LAB_00017959:
            if (bVar10) {
              uVar5 = uVar5 | 1;
              break;
            }
            bVar10 = true;
          }
          else {
            bVar8 = bVar8 + 1;
            if (((*(char *)(lVar2 + 0x14) != '\x04') || ((*(uint *)(lVar4 + 4) & 0x100) == 0)) &&
               (((*(uint *)(lVar4 + 4) & 1) != 0 || ((*(uint *)(lVar4 + 4) >> 8 & 1) != 0)))) {
              lVar4 = 0;
            }
            if (lVar4 == 0) goto LAB_00017959;
          }
          bVar6 = bVar6 + 1;
          uVar3 = (uint)bVar6;
        } while (uVar3 < uVar9);
      }
      if ((bVar6 == uVar9) && ((!bVar10 || (uVar5 = uVar5 | 4, bVar8 == bVar6)))) {
        uVar5 = uVar5 | 2;
      }
    }
    if ((param_2 & 8) != 0) {
      bVar7 = 1;
      NvRaidResArrayGenerateSignature((uint *)(lVar2 + 4));
    }
    if ((bVar7 & (byte)param_2) != 0) {
      NvRaidDefaultUpdateArrayStatus(param_1,param_2);
      if ((uVar5 & 0x20) != 0) {
        uVar5 = *(uint *)(param_1 + 4);
      }
      *(uint *)(param_1 + 4) = uVar5;
    }
  }
  return uVar5;
}



===== FUN_000179d8 @ 000179d8 =====

int FUN_000179d8(undefined4 *param_1,longlong param_2,uint *param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = NvRaidDefaultProcessError(param_1,param_2,param_3);
  if ((*param_3 == 3) && (*(char *)(param_2 + 0x80) == -2)) {
    uVar2 = NvRaidRemoveFailedVolumeFromArray(param_1,*(longlong *)(param_2 + 0x40));
    if ((char)uVar2 != '\0') {
      *param_3 = 2;
    }
  }
  return iVar1;
}



===== FUN_00017a38 @ 00017a38 =====

undefined8 FUN_00017a38(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  undefined8 uVar2;
  undefined **local_18 [3];
  
  if (*(char *)(param_2 + 0x80) != -1) {
LAB_00017a99:
    uVar2 = NvRaidStripeDefaultSendCommand(param_1,param_2);
    return uVar2;
  }
  bVar1 = *(byte *)(param_2 + 0x81);
  if (bVar1 != 9) {
    if (3 < (byte)(bVar1 - 0xc)) goto LAB_00017a99;
    *(undefined1 *)(param_2 + 0x56) = 0;
    local_18[0] = &PTR_FUN_00027ab0;
    local_18[1] = &PTR_FUN_00027c08;
    *(undefined ***)(param_2 + 0x58) = local_18[bVar1 & 1];
  }
  FUN_00011e84(param_2);
  return 0x103;
}



===== FUN_00017aa4 @ 00017aa4 =====

void * FUN_00017aa4(longlong param_1,longlong param_2,longlong param_3,int param_4,int param_5)

{
  void *pvVar1;
  
  pvVar1 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
  if (pvVar1 != (void *)0x0) {
    *(longlong *)((longlong)pvVar1 + 0x40) = param_1;
    *(undefined1 *)((longlong)pvVar1 + 0x48) = *(undefined1 *)(param_1 + 8);
    *(code **)((longlong)pvVar1 + 0xa0) = NvRaidStateSubRequestsDone;
    *(undefined4 *)((longlong)pvVar1 + 100) = *(undefined4 *)(param_2 + 100);
    if (param_5 == 0) {
      *(uint *)((longlong)pvVar1 + 0x60) = *(uint *)((longlong)pvVar1 + 0x60) | 4;
    }
    *(undefined8 *)((longlong)pvVar1 + 0x80) = *(undefined8 *)(param_2 + 0x80);
    *(longlong *)((longlong)pvVar1 + 0x88) = param_3;
    *(int *)((longlong)pvVar1 + 0x90) = param_4;
    *(byte *)((longlong)pvVar1 + 0x82) =
         *(byte *)((longlong)pvVar1 + 0x82) | *(byte *)(param_2 + 0x82) & 0x10;
    if (*(longlong *)(param_2 + 0xa8) != 0) {
      NvRaidPacketScatterGatherGroupAllocBuildPartialGroup
                (param_2,(longlong)pvVar1,(param_3 - *(longlong *)(param_2 + 0x88)) * 0x200,
                 param_4 << 9);
    }
  }
  return pvVar1;
}



===== FUN_00017b74 @ 00017b74 =====

undefined8
FUN_00017b74(longlong param_1,longlong param_2,undefined8 param_3,longlong param_4,int param_5,
            int param_6)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if (param_5 == *(int *)(param_2 + 0x90)) {
    uVar2 = FUN_00017bdc(param_1,param_2,param_6);
    return uVar2;
  }
  puVar1 = FUN_00017aa4(param_1,param_2,param_4,param_5,param_6);
  *puVar1 = 0;
  puVar1[1] = *(undefined8 *)(param_2 + 0x28);
  **(undefined8 **)(param_2 + 0x28) = puVar1;
  *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
  *(undefined8 **)(param_2 + 0x28) = puVar1;
  puVar1[0xd] = param_2;
  puVar1[0xe] = *(undefined8 *)(param_2 + 0x40);
  return 0;
}



===== FUN_00017bdc @ 00017bdc =====

undefined8 FUN_00017bdc(longlong param_1,longlong param_2,int param_3)

{
  longlong lVar1;
  byte bVar2;
  undefined8 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar4 = *(uint *)(param_2 + 0x90);
  puVar3 = (undefined8 *)0x0;
  lVar1 = *(longlong *)(param_1 + 0x58);
  if ((uVar4 == 0) || (*(longlong *)(param_2 + 0xa8) == 0)) {
    FUN_00017d00(param_1,param_2,param_3);
  }
  else {
    uVar7 = *(ulonglong *)(param_2 + 0x88);
    if (param_3 == 0) {
      bVar2 = *(byte *)(lVar1 + 0x17);
    }
    else {
      bVar2 = *(byte *)(lVar1 + 0x15);
    }
    uVar6 = *(int *)(lVar1 + 0x1c) * (uint)bVar2;
    uVar5 = uVar6 - (int)(uVar7 % (ulonglong)uVar6);
    do {
      if (uVar4 < uVar5) {
        uVar5 = uVar4;
      }
      if ((puVar3 == (undefined8 *)0x0) && (uVar5 == uVar4)) {
        if (param_3 == 0) {
          *(uint *)(param_2 + 0x60) = *(uint *)(param_2 + 0x60) | 4;
        }
        *(undefined1 *)(param_2 + 0x56) = 0;
        *(undefined ***)(param_2 + 0x58) = &PTR_LAB_00027b00;
        return 0;
      }
      puVar3 = FUN_00017aa4(param_1,param_2,uVar7,uVar5,param_3);
      *puVar3 = 0;
      puVar3[1] = *(undefined8 *)(param_2 + 0x28);
      **(undefined8 **)(param_2 + 0x28) = puVar3;
      *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
      *(undefined8 **)(param_2 + 0x28) = puVar3;
      puVar3[0xd] = param_2;
      puVar3[0xe] = *(undefined8 *)(param_2 + 0x40);
      uVar7 = uVar7 + uVar5;
      uVar4 = uVar4 - uVar5;
      uVar5 = uVar6;
    } while (uVar4 != 0);
  }
  NvRaidPacketSetupSubRequestsDevice(param_1,(undefined8 *)(param_2 + 0x20));
  return 0;
}



===== FUN_00017d00 @ 00017d00 =====

undefined8 FUN_00017d00(longlong param_1,longlong param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  ulonglong uVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined8 *puVar13;
  byte bVar14;
  int iVar15;
  uint uVar16;
  byte bVar17;
  byte bVar18;
  uint uVar19;
  ulonglong uVar20;
  uint uVar21;
  byte bVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  longlong lVar26;
  uint uVar27;
  ulonglong uVar28;
  bool bVar29;
  uint local_c0;
  uint local_b4;
  uint local_a8;
  int local_9c;
  byte local_90;
  uint local_8c;
  byte local_80;
  byte local_68;
  
  lVar26 = *(longlong *)(param_1 + 0x58);
  if (param_3 == 0) {
    bVar1 = *(byte *)(lVar26 + 0x17);
    uVar25 = *(uint *)(lVar26 + 0x38);
  }
  else {
    bVar1 = *(byte *)(lVar26 + 0x15);
    uVar25 = *(uint *)(lVar26 + 0x18);
  }
  iVar2 = *(int *)(lVar26 + 0x20);
  uVar3 = *(uint *)(lVar26 + 0x1c);
  bVar29 = uVar25 == 0x95;
  uVar19 = (uint)bVar1;
  local_9c = uVar19 * iVar2;
  if (bVar29) {
    local_9c = local_9c + iVar2;
  }
  bVar14 = (byte)*(undefined4 *)(lVar26 + 0x24);
  uVar20 = *(ulonglong *)(param_2 + 0x88) >> (bVar14 & 0x3f);
  uVar12 = CONCAT71(0,bVar1);
  auVar4._8_8_ = 0;
  auVar4._0_8_ = uVar12;
  auVar5._8_8_ = 0;
  auVar5._0_8_ = uVar20;
  uVar10 = uVar20 / uVar12;
  local_a8 = SUB164(auVar5 % auVar4,0);
  uVar8 = *(uint *)(param_2 + 0x88) & *(uint *)(lVar26 + 0x28);
  if ((*(int *)(param_2 + 0x90) == 0) && ((*(byte *)(param_2 + 0x82) & 4) != 0)) {
    if (param_3 == 0) {
      uVar20 = *(ulonglong *)(lVar26 + 0x50);
    }
    else {
      uVar20 = *(ulonglong *)(param_1 + 0x20);
    }
    uVar20 = (uVar20 >> (bVar14 & 0x3f)) - 1;
    local_8c = uVar3;
  }
  else {
    local_8c = *(int *)(param_2 + 0x90) + uVar8;
    uVar20 = (((uVar3 - 1) + local_8c >> (bVar14 & 0x1f)) - 1) + uVar20;
    local_8c = local_8c & *(uint *)(lVar26 + 0x28);
    if (local_8c == 0) {
      local_8c = uVar3;
    }
  }
  uVar23 = bVar1 + 1;
  uVar11 = uVar20 / uVar12;
  local_80 = (byte)(uVar20 % uVar12);
  bVar17 = SUB161(auVar5 % auVar4,0);
  if (uVar25 == 0x85) {
    bVar22 = bVar1 - (char)(uVar10 % (ulonglong)(bVar1 + 1));
    uVar20 = (ulonglong)bVar22;
    local_c0 = (uint)bVar22;
    if (bVar22 <= bVar17) {
      local_a8 = (uint)(byte)(bVar17 + 1);
      uVar20 = (ulonglong)(bVar22 + uVar19) % (ulonglong)(longlong)(int)uVar23;
      local_c0 = (uint)uVar20;
    }
    bVar22 = bVar1 - (char)(uVar11 % (ulonglong)(bVar1 + 1));
    if (bVar22 <= local_80) {
      local_80 = local_80 + 1;
    }
  }
  else {
    uVar20 = (ulonglong)bVar1;
    local_c0 = (uint)bVar1;
    bVar22 = bVar1;
  }
  bVar18 = (byte)local_a8;
  if (bVar18 == 0) {
    iVar24 = 0;
  }
  else {
    iVar24 = uVar19 - bVar17;
    if (!bVar29) {
      iVar24 = iVar24 + -1;
    }
    iVar24 = (uVar3 - uVar8) + (iVar24 << (bVar14 & 0x1f));
  }
  uVar19 = bVar1 + 1;
  uVar16 = iVar24 << 9;
  uVar12 = 0;
  if (uVar19 != 0) {
    do {
      local_b4 = (uint)bVar1;
      uVar27 = (uint)bVar1;
      bVar17 = (byte)uVar12;
      uVar21 = (uint)uVar12;
      if ((uVar25 != 0x83) || (bVar17 != bVar22)) {
        if (bVar29) {
          uVar12 = (longlong)
                   (int)(uVar27 + 1 +
                        (uVar21 - ((uint)(uVar10 % (ulonglong)(longlong)(int)uVar23) & 0xff))) %
                   (longlong)(int)uVar19 & 0xffffffff;
        }
        if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)(uVar12 & 0xff))) {
          lVar26 = 0;
        }
        else {
          lVar26 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (uVar12 & 0xff) * 8);
        }
        if (((lVar26 == 0) || ((*(uint *)(lVar26 + 4) & 1) != 0)) ||
           ((param_3 == 0 && ((*(uint *)(lVar26 + 4) >> 8 & 1) != 0)))) {
          lVar26 = 0;
        }
        if (lVar26 != 0) {
          uVar20 = (ulonglong)(bVar17 < bVar18);
          if (bVar29) {
            local_68 = (byte)((uVar11 - uVar10) % (ulonglong)(longlong)(int)uVar23);
            local_90 = (byte)((ulonglong)(local_68 + uVar21) %
                             (ulonglong)(longlong)(int)(uVar27 + 1));
          }
          else {
            uVar19 = uVar21;
            if (bVar1 < bVar17) {
              uVar19 = (uint)(byte)(bVar17 - 1);
            }
            local_90 = (byte)uVar19;
          }
          if ((bVar29) && (bVar17 == (byte)local_c0)) {
            uVar20 = 1;
          }
          uVar12 = uVar20 + uVar10;
          if (uVar25 == 0x85) {
            bVar22 = bVar1 - (char)(uVar12 % (ulonglong)(uVar27 + 1));
          }
          else {
            bVar22 = bVar1;
            if ((bVar29) && ((int)uVar20 != 0)) {
              bVar22 = bVar1 - 1;
            }
          }
          uVar28 = (uint)(local_90 <= local_80) + uVar11;
          uVar6 = uVar12;
          uVar19 = uVar16;
          if (((int)uVar20 + 1) + uVar10 <= uVar28) {
            for (; uVar6 < uVar28; uVar6 = uVar6 + 1) {
              if ((bVar17 == bVar22) && (*(longlong *)(param_2 + 0xa8) != 0)) {
                if (bVar29) {
                  uVar19 = uVar19 + (iVar2 - local_9c);
                }
              }
              else {
                puVar13 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
                if (puVar13 == (undefined8 *)0x0) {
                  return 0xc000009a;
                }
                uVar20 = 0;
                if ((uVar12 == uVar6) && (bVar17 == bVar18)) {
                  uVar20 = (ulonglong)uVar8;
                }
                uVar27 = uVar3;
                if ((((local_90 <= local_80) - 1) + uVar11 == uVar6) && (local_90 == local_80)) {
                  uVar27 = local_8c;
                }
                iVar24 = uVar27 - (int)uVar20;
                bVar7 = *(byte *)(param_2 + 0x80);
                if (bVar7 == 0xfe) {
                  bVar7 = *(byte *)(param_2 + 0x81);
                }
                NvRaidScsiSetupReadWrite
                          ((longlong)puVar13,*(undefined1 *)(lVar26 + 8),lVar26,
                           NvRaidStateSubRequestsDone,bVar7,uVar20 + (uVar6 << (bVar14 & 0x3f)),
                           iVar24);
                *(undefined1 *)((longlong)puVar13 + 0x82) = *(undefined1 *)(param_2 + 0x82);
                if (param_3 == 0) {
                  *(uint *)(puVar13 + 0xc) = *(uint *)(puVar13 + 0xc) | 4;
                }
                *puVar13 = 0;
                puVar13[1] = *(undefined8 *)(param_2 + 0x28);
                **(undefined8 **)(param_2 + 0x28) = puVar13;
                *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
                *(undefined8 **)(param_2 + 0x28) = puVar13;
                puVar13[0xd] = param_2;
                puVar13[0xe] = *(undefined8 *)(param_2 + 0x40);
                if (*(longlong *)(param_2 + 0xa8) != 0) {
                  NvRaidPacketScatterGatherGroupAllocBuildPartialGroup
                            (param_2,(longlong)puVar13,(ulonglong)uVar19,iVar24 << 9);
                }
                if (*(int *)(param_2 + 0x90) == 0) {
                  *(undefined4 *)(puVar13 + 0x12) = 0;
                  break;
                }
              }
              if ((bVar22 != 0) || (bVar29)) {
                iVar24 = 0;
              }
              else {
                iVar24 = iVar2;
              }
              iVar15 = 0;
              if (uVar19 == 0) {
                iVar15 = uVar8 << 9;
              }
              iVar9 = 0;
              if (bVar17 == bVar22) {
                iVar9 = iVar2;
              }
              if ((uVar25 & 0xffffffef) == 0x85) {
                bVar22 = (byte)((bVar22 + local_b4) % uVar23);
              }
              uVar19 = uVar19 + ((iVar24 - iVar15) - iVar9) + local_9c;
            }
          }
          uVar20 = (ulonglong)local_c0;
          uVar19 = uVar23;
        }
      }
      if (uVar21 + 1 == local_a8) {
        uVar16 = 0;
      }
      else if (bVar17 == bVar18) {
        uVar16 = (uVar3 - uVar8) * 0x200;
      }
      else if (bVar17 != (byte)uVar20) {
        uVar16 = uVar16 + iVar2;
      }
      uVar12 = (ulonglong)(byte)(bVar17 + 1);
    } while ((byte)(bVar17 + 1) < uVar19);
  }
  return 0;
}



===== FUN_00018360 @ 00018360 =====

undefined8 FUN_00018360(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x58);
  if ((~(byte)(*(uint *)(param_2 + 0x60) >> 2) & 1) == 0) {
    bVar1 = *(byte *)(lVar2 + 0x17);
  }
  else {
    bVar1 = *(byte *)(lVar2 + 0x15);
  }
  if (((*(uint *)(param_2 + 0x60) >> 10 & 1) != 0) ||
     (uVar3 = NvRaidParityLockAcquire
                        (param_2,(*(ulonglong *)(param_2 + 0x88) >>
                                 ((byte)*(undefined4 *)(lVar2 + 0x24) & 0x3f)) / (ulonglong)bVar1 &
                                 0xffffffff,param_1), (int)uVar3 != 0x103)) {
    FUN_00017d00(param_1,param_2,~(*(uint *)(param_2 + 0x60) >> 2) & 1);
    NvRaidPacketSetupSubRequestsDevice(param_1,(undefined8 *)(param_2 + 0x20));
    *(undefined1 *)(param_2 + 0x56) = 1;
    uVar3 = NvRaidPacketSubmitSubRequests((longlong *)(param_2 + 0x20));
    if ((int)uVar3 != 0x103) {
      *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
      DbgPrint(
              "NvRaidParityStripeHealthyRead: NvRaidPacketSubmitSubRequests called with no subreqs\n"
              );
      return 0;
    }
  }
  return 0x103;
}



===== FUN_0001841c @ 0001841c =====

undefined8 FUN_0001841c(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
  if (puVar1 == (undefined8 *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    puVar1[8] = param_1;
    *(undefined1 *)(puVar1 + 9) = *(undefined1 *)(param_1 + 8);
    puVar1[0x14] = NvRaidStateSubRequestsDone;
    *(uint *)(puVar1 + 0xc) = *(uint *)(puVar1 + 0xc) | *(uint *)(param_2 + 0x60) & 4;
    *(undefined2 *)(puVar1 + 0x10) = 0x9ff;
    *(undefined1 *)((longlong)puVar1 + 0x82) = 0;
    *puVar1 = 0;
    puVar1[1] = *(undefined8 *)(param_2 + 0x28);
    **(undefined8 **)(param_2 + 0x28) = puVar1;
    *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
    *(undefined8 **)(param_2 + 0x28) = puVar1;
    puVar1[0xd] = param_2;
    puVar1[0xe] = *(undefined8 *)(param_2 + 0x40);
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
    uVar2 = 0;
  }
  return uVar2;
}



===== FUN_000184b0 @ 000184b0 =====

undefined8 FUN_000184b0(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(param_2 + 0x20);
  *(undefined ***)(lVar1 + 0x58) = &PTR_FUN_00027bb0;
  *(undefined1 *)(lVar1 + 0x56) = 0;
  *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
  uVar2 = NvRaidPacketSubmitSubRequests((longlong *)(param_2 + 0x20));
  if ((int)uVar2 == 0x103) {
    uVar2 = 0x103;
  }
  else {
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
    DbgPrint("NvRaidParityProcessLoadStripe: NvRaidPacketSubmitSubRequests called with no subreqs\n"
            );
    uVar2 = 0;
  }
  return uVar2;
}



===== FUN_000184fc @ 000184fc =====

undefined8 FUN_000184fc(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  byte bVar3;
  
  lVar1 = *(longlong *)(param_2 + 0x20);
  *(undefined ***)(lVar1 + 0x58) = &PTR_FUN_00027a78;
  *(undefined1 *)(lVar1 + 0x56) = 0;
  bVar3 = *(byte *)(lVar1 + 0x82) & 7;
  if (bVar3 == 2) {
    NvRaidResNrpFreeSubReqs(*(longlong *)(param_1 + 0x18),param_2);
    *(undefined1 *)(param_2 + 0x56) = 5;
    uVar2 = 0;
  }
  else {
    if (bVar3 == 7) {
      *(undefined1 *)(param_2 + 0x56) = 1;
    }
    else {
      *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
    }
    *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
    NvRaidPacketSubmitSubRequests((longlong *)(param_2 + 0x20));
    uVar2 = 0x103;
  }
  return uVar2;
}



===== FUN_00018564 @ 00018564 =====

undefined8 FUN_00018564(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x20);
  *(undefined ***)(lVar1 + 0x58) = &PTR_FUN_00027be0;
  *(undefined1 *)(lVar1 + 0x56) = 0;
  *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
  *(undefined1 *)(param_2 + 0x56) = 1;
  NvRaidPacketSubmitSubRequests((longlong *)(param_2 + 0x20));
  return 0x103;
}



===== FUN_00018594 @ 00018594 =====

undefined8 FUN_00018594(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  if ((*(uint *)(param_1 + 4) & 0x800) == 0) {
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
    uVar1 = 0;
  }
  else {
    NvRaidResQueueLowResourceNrp(param_2);
    uVar1 = 0x103;
  }
  return uVar1;
}



===== FUN_000185bc @ 000185bc =====

undefined8 FUN_000185bc(longlong param_1,longlong param_2,longlong param_3,uint param_4)

{
  undefined8 uVar1;
  longlong lVar2;
  uint uVar3;
  
  if (((*(longlong *)(param_3 + 0xa8) != 0) ||
      (uVar1 = NvRaidResSgGroupAllocateForNrp(param_1,param_3), -1 < (int)uVar1)) &&
     ((*(longlong *)(param_2 + 0xa8) != 0 ||
      (uVar1 = NvRaidResSgGroupAllocateForNrp(param_1,param_2), -1 < (int)uVar1)))) {
    for (; param_4 != 0; param_4 = param_4 - uVar3) {
      if (gScratchBufCount == 0) {
        uVar3 = param_4;
      }
      else {
        uVar3 = 0x200;
        if (param_4 < 0x200) {
          uVar3 = param_4;
        }
      }
      lVar2 = NvRaidResBufferAllocate(param_1,uVar3);
      if (lVar2 == 0) {
        DbgPrint("NvRaidParityAllocateBufferForStripeNrp: nvrAllocBuffer Failed\n");
        return 0xc0000017;
      }
      NvRaidPacketScatterGatherElementAdd(*(longlong *)(param_3 + 0xa8),lVar2,uVar3);
      NvRaidPacketScatterGatherElementAdd(*(longlong *)(param_2 + 0xa8),lVar2,uVar3);
    }
    *(uint *)(param_2 + 0x60) = *(uint *)(param_2 + 0x60) | 0x200;
    uVar1 = 0;
  }
  return uVar1;
}



===== FUN_00018698 @ 00018698 =====

undefined8
FUN_00018698(longlong param_1,longlong param_2,longlong param_3,uint param_4,ulonglong param_5,
            uint param_6)

{
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  
  lVar1 = *(longlong *)(param_2 + 0x68);
  if ((*(byte *)(param_2 + 0x82) & 7) == 7) {
    iVar3 = *(int *)(param_3 + 0x90);
    if ((*(short *)(param_2 + 0x8a) != 0) && (iVar3 != 0)) {
      if (param_6 == 0) {
        iVar4 = iVar3;
      }
      else {
        if (param_5 <= *(ushort *)(param_2 + 0x88)) goto LAB_00018779;
        iVar4 = (int)param_5 - (uint)*(ushort *)(param_2 + 0x88);
      }
      if (iVar4 != 0) {
        uVar2 = FUN_000185bc(param_1,param_2,param_3,iVar4 << 9);
        if ((int)uVar2 != 0) goto LAB_0001875a;
        iVar3 = iVar3 - iVar4;
      }
    }
LAB_00018779:
    if ((param_6 != 0) && (iVar3 != 0)) {
      NvRaidPacketScatterGatherGroupAllocBuildPartialGroup
                (lVar1,param_3,(ulonglong)param_4 << 9,param_6 << 9);
      iVar3 = iVar3 - param_6;
    }
    if (*(ushort *)(param_2 + 0x8a) == 0) {
      return 0;
    }
    if (iVar3 == 0) {
      return 0;
    }
    if (param_6 != 0) {
      iVar3 = (uint)*(ushort *)(param_2 + 0x88) + (uint)*(ushort *)(param_2 + 0x8a);
      if ((ulonglong)(longlong)iVar3 <= param_6 + param_5) {
        return 0;
      }
      iVar3 = (iVar3 - (int)param_5) - param_6;
    }
    if (iVar3 == 0) {
      return 0;
    }
  }
  else {
    if (param_6 != 0) {
      NvRaidPacketScatterGatherGroupAllocBuildPartialGroup
                (lVar1,param_3,(ulonglong)param_4 << 9,param_6 << 9);
      return 0;
    }
    iVar3 = *(int *)(param_3 + 0x90);
  }
  uVar2 = FUN_000185bc(param_1,param_2,param_3,iVar3 << 9);
  if ((int)uVar2 == 0) {
    return 0;
  }
LAB_0001875a:
  DbgPrint(
          "NvRaidParityAllocateScatterGatherBufferForStripeNrp: NvRaidParityAllocateBufferForStripeNrp Failed\n"
          );
  return 0xc0000017;
}



===== FUN_0001880c @ 0001880c =====

undefined8 FUN_0001880c(longlong param_1,undefined4 *param_2)

{
  ushort *puVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  uint uVar10;
  ulonglong uVar11;
  longlong lVar12;
  longlong lVar13;
  undefined8 *puVar14;
  ushort uVar15;
  
  lVar13 = *(longlong *)(param_2 + 0x2a);
  if ((lVar13 != 0) && (uVar10 = 0, *(short *)(lVar13 + 4) != 0)) {
    do {
      puVar9 = (undefined8 *)0x0;
      uVar6 = (uint)*(ushort *)(lVar13 + 6);
      uVar7 = uVar10;
      if (*(ushort *)(lVar13 + 6) <= uVar10) {
        do {
          lVar13 = *(longlong *)(lVar13 + 8);
          uVar7 = uVar7 - uVar6;
          uVar6 = (uint)*(ushort *)(lVar13 + 6);
        } while (uVar6 <= uVar7);
      }
      lVar12 = *(longlong *)(param_1 + 0xa8);
      uVar11 = (ulonglong)uVar7;
      puVar1 = (ushort *)(lVar12 + 4);
      iVar2 = *(int *)(lVar13 + 0x20 + uVar11 * 0x10);
      lVar3 = *(longlong *)(lVar13 + 0x18 + uVar11 * 0x10);
      bVar5 = false;
      uVar15 = 0;
      puVar14 = puVar9;
      if (*puVar1 != 0) {
        do {
          if (*(ushort *)(lVar12 + 6) <= (ushort)puVar9) {
            lVar12 = *(longlong *)(lVar12 + 8);
            puVar9 = (undefined8 *)0x0;
          }
          lVar8 = (longlong)puVar9 * 0x10 + lVar12;
          if (bVar5) {
            if (puVar14 != (undefined8 *)0x0) {
              uVar4 = *(undefined8 *)(lVar8 + 0x20);
              *puVar14 = *(undefined8 *)(lVar8 + 0x18);
              puVar14[1] = uVar4;
            }
LAB_000188d0:
            puVar14 = (undefined8 *)(lVar8 + 0x18);
          }
          else if ((*(longlong *)(lVar8 + 0x18) == lVar3) && (*(int *)(lVar8 + 0x20) == iVar2)) {
            bVar5 = true;
            goto LAB_000188d0;
          }
          uVar15 = uVar15 + 1;
          puVar9 = (undefined8 *)(ulonglong)(ushort)((short)puVar9 + 1);
        } while (uVar15 < *puVar1);
        if (bVar5) {
          *puVar1 = *puVar1 - 1;
          NvRaidResBufferFree(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x18),
                              *(undefined4 **)(lVar13 + 0x18 + uVar11 * 0x10),
                              *(int *)(lVar13 + 0x20 + uVar11 * 0x10));
        }
      }
      lVar13 = *(longlong *)(param_2 + 0x2a);
      uVar10 = uVar10 + 1;
    } while (uVar10 < *(ushort *)(lVar13 + 4));
  }
  NvRaidResNrpFree(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x18),param_2);
  return 0;
}



===== FUN_00018954 @ 00018954 =====

undefined8 *
FUN_00018954(longlong param_1,undefined1 param_2,longlong param_3,byte param_4,undefined8 param_5,
            undefined4 param_6,uint param_7,ulonglong param_8,uint param_9)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x68);
  if (param_3 == 0) {
    pcVar5 = "NvRaidParityAllocParityRelatedRequest: Volume was NULL\n";
  }
  else {
    puVar3 = NvRaidResNrpAllocate(*(longlong *)(param_3 + 0x18));
    if (puVar3 == (undefined8 *)0x0) {
      return (undefined8 *)0x0;
    }
    NvRaidScsiSetupReadWrite
              ((longlong)puVar3,param_2,param_3,NvRaidStateSubRequestsDone,param_4,param_5,param_6);
    *(byte *)((longlong)puVar3 + 0x82) =
         *(byte *)((longlong)puVar3 + 0x82) | *(byte *)(lVar2 + 0x82) & 0x10;
    uVar4 = FUN_00018698(*(longlong *)(param_3 + 0x18),param_1,(longlong)puVar3,param_7,param_8,
                         param_9);
    if ((int)uVar4 == 0) {
      uVar1 = *(uint *)(param_1 + 0x60);
      *puVar3 = 0;
      *(uint *)(puVar3 + 0xc) = *(uint *)(puVar3 + 0xc) | uVar1 & 4;
      puVar3[1] = *(undefined8 *)(param_1 + 0x28);
      **(undefined8 **)(param_1 + 0x28) = puVar3;
      *(char *)(param_1 + 0x55) = *(char *)(param_1 + 0x55) + '\x01';
      *(undefined8 **)(param_1 + 0x28) = puVar3;
      puVar3[0xd] = param_1;
      puVar3[0xe] = *(undefined8 *)(param_1 + 0x40);
      return puVar3;
    }
    FUN_0001880c(param_1,(undefined4 *)puVar3);
    pcVar5 = 
    "NvRaidParityAllocParityRelatedRequest: NvRaidParityAllocateScatterGatherBufferForStripeNrp Failed\n"
    ;
  }
  DbgPrint(pcVar5);
  return (undefined8 *)0x0;
}



===== NvRaidParityLockAcquire @ 00018a7c =====

undefined8 NvRaidParityLockAcquire(longlong param_1,ulonglong param_2,longlong param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  
  lVar3 = *(longlong *)(param_3 + 0x58);
  if (*(char *)(param_1 + 0x80) != -2) {
    param_1 = *(longlong *)(param_1 + 0x68);
  }
  if (*(char *)(param_1 + 0xb0) == '\0') {
    if (lVar3 == 0) {
      lVar2 = *(longlong *)(param_3 + 0x50);
      do {
        if ((lVar2 == 0) || (lVar2 == *(longlong *)(param_3 + 0x18))) goto LAB_00018aa4;
        lVar3 = *(longlong *)(lVar2 + 0x58);
      } while (lVar3 == 0);
    }
    uVar1 = param_2 % (ulonglong)*(uint *)(param_3 + 0x68);
    for (lVar2 = *(longlong *)(lVar3 + 0xc0 + uVar1 * 0x18); lVar2 != 0;
        lVar2 = *(longlong *)(lVar2 + 0xe0)) {
      if (*(ulonglong *)(lVar2 + 0xb8) == param_2) {
        uVar4 = 0x103;
        *(undefined8 *)(param_1 + 0xe0) = 0;
        *(undefined8 *)(param_1 + 0xe8) = *(undefined8 *)(lVar2 + 0xd8);
        **(longlong **)(lVar2 + 0xd8) = param_1;
        *(undefined8 **)(lVar2 + 0xd8) = (undefined8 *)(param_1 + 0xe0);
        if (*(longlong *)(lVar2 + 0xd0) != param_1) {
          lVar2 = **(longlong **)(*(longlong *)(param_1 + 0xe8) + 8);
        }
        if ((*(char *)(lVar2 + 0xc9) == '\0') || ((*(byte *)(param_1 + 0x82) & 1) == 0))
        goto LAB_00018b35;
        goto LAB_00018b2d;
      }
    }
    *(undefined1 *)(param_1 + 200) = 1;
    *(undefined8 *)(param_1 + 0xe0) = 0;
    *(undefined8 *)(param_1 + 0xe8) = *(undefined8 *)(lVar3 + 200 + uVar1 * 0x18);
    **(longlong **)(lVar3 + 200 + uVar1 * 0x18) = param_1;
    *(undefined8 **)(lVar3 + 200 + uVar1 * 0x18) = (undefined8 *)(param_1 + 0xe0);
LAB_00018b2d:
    uVar4 = 0;
    *(undefined1 *)(param_1 + 0xc9) = 1;
LAB_00018b35:
    *(undefined1 *)(param_1 + 0xb0) = 1;
    *(ulonglong *)(param_1 + 0xb8) = param_2;
  }
  else {
LAB_00018aa4:
    uVar4 = 0;
  }
  return uVar4;
}



===== NvRaidParityLockRelease @ 00018bac =====

undefined8 NvRaidParityLockRelease(longlong param_1,ulonglong param_2,longlong param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  longlong lVar10;
  byte bVar11;
  
  lVar10 = *(longlong *)(param_3 + 0x58);
  if (*(char *)(param_1 + 0xb0) != '\0') {
    if (lVar10 == 0) {
      lVar8 = *(longlong *)(param_3 + 0x50);
      do {
        if (lVar8 == 0) {
          return 0;
        }
        if (lVar8 == *(longlong *)(param_3 + 0x18)) {
          return 0;
        }
        lVar10 = *(longlong *)(lVar8 + 0x58);
      } while (lVar10 == 0);
    }
    uVar7 = param_2 % (ulonglong)*(uint *)(param_3 + 0x68);
    if (*(char *)(param_1 + 200) == '\0') {
      puVar9 = *(undefined8 **)(param_1 + 0xe0);
      lVar8 = *(longlong *)(lVar10 + 0xc0 + uVar7 * 0x18);
      if (lVar8 != 0) {
        do {
          if (*(longlong *)(lVar8 + 0xb8) == *(longlong *)(param_1 + 0xb8)) break;
          lVar8 = *(longlong *)(lVar8 + 0xe0);
        } while (lVar8 != 0);
      }
      if (puVar9 == (undefined8 *)0x0) {
        *(undefined8 *)(lVar8 + 0xd8) = *(undefined8 *)(param_1 + 0xe8);
      }
      else {
        puVar9[0x1d] = *(undefined8 *)(param_1 + 0xe8);
      }
    }
    else {
      plVar1 = (longlong *)(param_1 + 0xd0);
      puVar9 = (undefined8 *)*plVar1;
      if (puVar9 != (undefined8 *)0x0) {
        plVar2 = puVar9 + 0x1c;
        *(undefined1 *)(puVar9 + 0x19) = 1;
        if (*plVar2 == 0) {
          *(undefined8 *)(param_1 + 0xd8) = puVar9[0x1d];
        }
        else {
          *(undefined8 *)(*plVar2 + 0xe8) = puVar9[0x1d];
        }
        *(longlong *)puVar9[0x1d] = *plVar2;
        if (*plVar1 == 0) {
          puVar9[0x1b] = puVar9 + 0x1a;
          puVar9[0x1a] = 0;
        }
        else {
          uVar4 = *(undefined8 *)(param_1 + 0xd8);
          plVar3 = puVar9 + 0x1a;
          *plVar3 = *plVar1;
          puVar9[0x1b] = uVar4;
          *(longlong **)(*plVar3 + 0xe8) = plVar3;
        }
        plVar3 = (longlong *)(param_1 + 0xe0);
        lVar8 = *plVar3;
        *plVar2 = lVar8;
        if (lVar8 == 0) {
          *(longlong **)(lVar10 + 200 + uVar7 * 0x18) = plVar2;
        }
        else {
          *(longlong **)(lVar8 + 0xe8) = plVar2;
        }
        *plVar3 = (longlong)puVar9;
        puVar9[0x1d] = plVar3;
        *plVar1 = 0;
        *(longlong **)(param_1 + 0xd8) = plVar1;
      }
      if (*(longlong *)(param_1 + 0xe0) == 0) {
        *(undefined8 *)(lVar10 + 200 + uVar7 * 0x18) = *(undefined8 *)(param_1 + 0xe8);
      }
      else {
        *(undefined8 *)(*(longlong *)(param_1 + 0xe0) + 0xe8) = *(undefined8 *)(param_1 + 0xe8);
      }
    }
    **(undefined8 **)(param_1 + 0xe8) = *(undefined8 *)(param_1 + 0xe0);
    *(undefined1 *)(param_1 + 0xb0) = 0;
    *(undefined2 *)(param_1 + 200) = 0;
    if (((puVar9 != (undefined8 *)0x0) && (*(char *)((longlong)puVar9 + 0xc9) == '\0')) &&
       (*(char *)(puVar9 + 0x19) != '\0')) {
      if ((puVar9[0x1a] != 0) && ((*(uint *)(*(longlong *)(param_3 + 0x18) + 0xe8) & 1) != 0)) {
        lVar8 = puVar9[0x1c];
        if (lVar8 == 0) {
          *(undefined8 *)(lVar10 + 200 + uVar7 * 0x18) = puVar9[0x1d];
        }
        else {
          *(undefined8 *)(lVar8 + 0xe8) = puVar9[0x1d];
        }
        *(undefined8 *)puVar9[0x1d] = puVar9[0x1c];
        puVar5 = FUN_0001a5d0((longlong)puVar9);
        if (puVar5 != (undefined8 *)0x0) {
          uVar4 = *(undefined8 *)(param_1 + 0xb8);
          *(undefined1 *)(puVar5 + 0x16) = 1;
          puVar5[0x17] = uVar4;
          *(undefined1 *)(puVar5 + 0x19) = 1;
          puVar9 = puVar5;
        }
        if (lVar8 == 0) {
          puVar9[0x1c] = 0;
          puVar9[0x1d] = *(undefined8 *)(lVar10 + 200 + uVar7 * 0x18);
          **(undefined8 **)(lVar10 + 200 + uVar7 * 0x18) = puVar9;
          *(undefined8 **)(lVar10 + 200 + uVar7 * 0x18) = puVar9 + 0x1c;
        }
        else {
          puVar9[0x1d] = *(undefined8 *)(lVar8 + 0xe8);
          puVar9[0x1c] = lVar8;
          **(undefined8 **)(lVar8 + 0xe8) = puVar9;
          *(undefined8 **)(lVar8 + 0xe8) = puVar9 + 0x1c;
        }
      }
      bVar11 = *(byte *)((longlong)puVar9 + 0x82);
      while (((bVar11 & 2) == 0 || (*(char *)(puVar9 + 0x19) != '\0'))) {
        *(undefined1 *)((longlong)puVar9 + 0xc9) = 1;
        if (*(char *)(puVar9 + 0x19) == '\0') {
          puVar5 = (undefined8 *)puVar9[0x1c];
        }
        else {
          puVar5 = (undefined8 *)puVar9[0x1a];
        }
        if ((((*(uint *)(param_3 + 4) & 4) != 0) && ((undefined **)puVar9[0xb] == &PTR_LAB_00027b00)
            ) && (*(char *)((longlong)puVar9 + 0x56) == '\x05')) {
          *(undefined1 *)((longlong)puVar9 + 0x56) = 0;
        }
        puVar6 = (undefined8 *)puVar9[4];
        if ((undefined8 *)puVar9[4] == (undefined8 *)0x0) {
          puVar6 = puVar9;
        }
        NvRaidPacketExecuteStateMachine(puVar6[8],(longlong)puVar6);
        if (((bVar11 & 2) != 0) && (*(char *)(puVar9 + 0x16) != '\0')) {
          return 0;
        }
        if (puVar5 == (undefined8 *)0x0) {
          return 0;
        }
        bVar11 = *(byte *)((longlong)puVar5 + 0x82);
        puVar9 = puVar5;
      }
    }
  }
  return 0;
}



===== FUN_00018f50 @ 00018f50 =====

undefined8 FUN_00018f50(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  bool bVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  longlong lVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  undefined8 *puVar12;
  ulonglong uVar13;
  byte bVar14;
  byte bVar15;
  longlong lVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  ulonglong uVar22;
  ushort uVar23;
  uint uVar24;
  ushort uVar25;
  ulonglong uVar26;
  byte bVar27;
  short sVar28;
  byte bVar29;
  ulonglong uVar30;
  byte bVar31;
  ushort uVar32;
  uint uVar33;
  byte bVar34;
  byte bVar35;
  byte bVar36;
  longlong lVar37;
  byte bVar38;
  bool bVar39;
  byte local_res10;
  byte local_res20;
  ushort local_b8;
  ushort local_b6;
  uint local_ac;
  uint local_a8;
  uint local_a0;
  ushort local_98;
  
  lVar37 = *(longlong *)(param_1 + 0x58);
  lVar2 = *(longlong *)(param_2 + 0x68);
  bVar35 = ~(byte)(*(uint *)(param_2 + 0x60) >> 2);
  bVar36 = bVar35 & 1;
  local_a0 = 0;
  local_ac = 0;
  if ((bVar35 & 1) == 0) {
    bVar35 = *(byte *)(lVar37 + 0x17);
    uVar24 = *(uint *)(lVar37 + 0x38);
  }
  else {
    bVar35 = *(byte *)(lVar37 + 0x15);
    uVar24 = *(uint *)(lVar37 + 0x18);
  }
  uVar1 = *(uint *)(lVar37 + 0x1c);
  bVar39 = uVar24 == 0x95;
  bVar14 = (byte)*(undefined4 *)(lVar37 + 0x24);
  uVar26 = *(ulonglong *)(lVar2 + 0x88) >> (bVar14 & 0x3f) & 0xffffffff;
  uVar4 = uVar26 / bVar35;
  uVar26 = uVar26 % (ulonglong)bVar35;
  iVar17 = (int)uVar26;
  lVar9 = uVar4 << (bVar14 & 0x3f);
  uVar18 = *(uint *)(lVar2 + 0x88) & *(uint *)(lVar37 + 0x28);
  uVar7 = *(int *)(lVar2 + 0x90) + uVar18;
  uVar8 = uVar7 & *(uint *)(lVar37 + 0x28);
  if (uVar8 == 0) {
    uVar8 = uVar1;
  }
  bVar27 = (byte)((uVar1 - 1) + uVar7 >> (bVar14 & 0x1f));
  local_98 = (ushort)uVar1;
  uVar25 = (ushort)uVar18;
  if (bVar27 < 2) {
    local_b8 = (ushort)uVar8 - uVar25;
    local_b6 = uVar25;
  }
  else {
    local_b6 = 0;
    local_b8 = local_98;
  }
  bVar34 = (byte)uVar26;
  bVar27 = (bVar27 - 1) + bVar34;
  if ((uVar24 & 0xffffffef) == 0x85) {
    *(byte *)(param_2 + 0x83) = bVar35 - (char)(uVar4 % (ulonglong)(bVar35 + 1));
  }
  else {
    *(byte *)(param_2 + 0x83) = bVar35;
  }
  local_res10 = *(byte *)(param_2 + 0x83);
  if (bVar39) {
    *(byte *)(param_2 + 0x82) = *(byte *)(param_2 + 0x82) | 8;
    *(char *)(param_2 + 0x87) = (char)(uVar4 % (ulonglong)(longlong)(int)(bVar35 + 1));
    local_res10 = bVar35;
  }
  *(byte *)(param_2 + 0x82) = *(byte *)(param_2 + 0x82) | 4;
  uVar24 = 0xff;
  local_res20 = 0xff;
  if (((*(uint *)(param_1 + 4) & 4) == 0) && ((*(uint *)(lVar2 + 0x60) & 0x400) == 0)) {
LAB_00019262:
    uVar25 = 0;
    uVar26 = 0;
  }
  else {
    uVar7 = bVar35 + 1;
    bVar29 = 0;
    if (uVar7 != 0) {
      do {
        if (bVar39) {
          uVar26 = (longlong)(int)(bVar35 + 1 + ((uint)bVar29 - (uint)*(byte *)(param_2 + 0x87))) %
                   (longlong)(int)uVar7 & 0xffffffff;
        }
        else {
          uVar26 = (ulonglong)bVar29;
        }
        lVar16 = 0;
        if ((param_1 != -0x78) && ((uint)(uVar26 & 0xff) < *(uint *)(param_1 + 0x7c))) {
          lVar16 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (uVar26 & 0xff) * 8);
        }
        if (((lVar16 == 0) || ((*(uint *)(lVar16 + 4) & 1) != 0)) ||
           ((bVar36 == 0 && ((*(uint *)(lVar16 + 4) >> 8 & 1) != 0)))) {
          lVar16 = 0;
        }
        if ((lVar16 == 0) ||
           (((*(uint *)(lVar2 + 0x60) & 0x400) != 0 &&
            ((char)uVar26 == *(char *)(*(longlong *)(lVar2 + 0xc0) + 8))))) {
          uVar24 = (uint)bVar29;
          local_res20 = bVar29;
          break;
        }
        bVar29 = bVar29 + 1;
      } while (bVar29 < uVar7);
    }
    uVar26 = 0;
    bVar29 = *(byte *)(param_2 + 0x82) & 0xfb;
    *(byte *)(param_2 + 0x82) = bVar29;
    bVar38 = (byte)uVar24;
    if (bVar38 == local_res10) {
      *(byte *)(param_2 + 0x82) = bVar29 | 2;
      goto LAB_00019262;
    }
    if (local_res10 < bVar38) {
      local_res20 = bVar38 - 1;
      uVar24 = (uint)local_res20;
    }
    bVar38 = (byte)uVar24;
    if (bVar38 == bVar34) {
      uVar26 = (ulonglong)uVar25;
      local_a0 = uVar18 & 0xffff;
    }
    else {
      local_a0 = 0;
    }
    uVar25 = (ushort)uVar8;
    if (bVar38 != bVar27) {
      uVar25 = local_98;
    }
    uVar25 = uVar25 - (short)uVar26;
    local_ac = (uint)uVar25;
    if ((bVar34 <= bVar38) && (bVar38 <= bVar27)) {
      *(byte *)(param_2 + 0x82) = bVar29 | 5;
    }
  }
  if ((((*(uint *)(lVar37 + 0x40) & 4) != 0) && ((char)uVar24 == -1)) &&
     (*(uint *)(lVar2 + 0x90) <= bVar35 * uVar1 >> 1)) {
    *(byte *)(param_2 + 0x82) = *(byte *)(param_2 + 0x82) & 0xfb;
  }
  if ((*(byte *)(lVar2 + 0x82) & 1) != 0) {
    *(byte *)(param_2 + 0x82) = *(byte *)(param_2 + 0x82) | 2;
  }
  bVar29 = *(byte *)(param_2 + 0x82) & 7;
  if ((*(byte *)(param_2 + 0x82) & 7) == 0) {
LAB_000192fe:
    local_a8 = 0;
    local_ac = 0;
LAB_00019308:
    uVar26 = (ulonglong)local_b6;
  }
  else {
    if (bVar29 == 2) {
      NvRaidPacketCompleteRequest(param_2);
      return 0x103;
    }
    if (bVar29 == 4) {
      uVar26 = (ulonglong)local_b6;
    }
    else {
      if (bVar29 == 5) {
        local_a8 = (uint)uVar26;
        goto LAB_00019308;
      }
      if (bVar29 != 7) goto LAB_000192fe;
      local_b8 = uVar25;
      local_b6 = (ushort)uVar26;
    }
    local_ac = (uint)local_b8;
    local_a8 = (uint)uVar26;
  }
  if (((*(uint *)(lVar2 + 0x60) >> 10 & 1) == 0) &&
     (uVar10 = NvRaidParityLockAcquire(param_2,uVar4,param_1), (int)uVar10 == 0x103)) {
    return 0x103;
  }
  *(byte *)(param_2 + 0x85) = bVar27;
  *(byte *)(param_2 + 0x84) = bVar34;
  sVar28 = (short)local_a8;
  *(short *)(param_2 + 0x88) = sVar28;
  uVar25 = (ushort)local_ac;
  *(ushort *)(param_2 + 0x8a) = uVar25;
  *(char *)(param_2 + 0x86) = (char)uVar24;
  *(short *)(param_2 + 0x8c) = (short)uVar26;
  *(ushort *)(param_2 + 0x8e) = local_b8;
  bVar29 = 0;
  if (*(char *)(param_2 + 0x57) != '\0') {
    bVar29 = *(char *)(param_2 + 0x57) - 1;
  }
  if (bVar29 < bVar35) {
    do {
      bVar6 = bVar29 + 1;
      bVar38 = bVar29;
      if (local_res10 <= bVar29) {
        bVar38 = bVar6;
      }
      if (bVar39) {
        bVar38 = (byte)((int)(bVar35 + 1 + ((uint)bVar38 - (uint)*(byte *)(param_2 + 0x87))) %
                       (int)(bVar35 + 1));
      }
      uVar24 = 0;
      if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)bVar38)) {
        lVar37 = 0;
      }
      else {
        lVar37 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)bVar38 * 8);
      }
      if (((lVar37 == 0) || ((*(uint *)(lVar37 + 4) & 1) != 0)) ||
         ((bVar36 == 0 && ((*(uint *)(lVar37 + 4) >> 8 & 1) != 0)))) {
        lVar37 = 0;
      }
      if ((lVar37 != 0) &&
         (((*(uint *)(lVar2 + 0x60) & 0x400) == 0 ||
          (bVar38 != *(byte *)(*(longlong *)(lVar2 + 0xc0) + 8))))) {
        bVar31 = 0x28;
        uVar7 = 0;
        uVar26 = 0;
        bVar5 = false;
        if ((bVar29 < bVar34) || (bVar27 < bVar29)) {
          if (uVar25 != 0) {
            uVar13 = (ulonglong)local_a8;
            uVar21 = local_ac;
            goto LAB_000195f7;
          }
        }
        else {
          if (bVar29 == bVar34) {
            uVar26 = (ulonglong)uVar18;
          }
          else {
            uVar7 = ((uint)bVar29 - iVar17 << (bVar14 & 0x1f)) - uVar18;
          }
          uVar24 = uVar1;
          if (bVar29 == bVar27) {
            uVar24 = uVar8;
          }
          uVar21 = (uint)uVar26;
          uVar24 = uVar24 - uVar21;
          bVar15 = *(byte *)(param_2 + 0x82) & 7;
          if ((*(byte *)(param_2 + 0x82) & 7) == 0) {
LAB_000195de:
            uVar13 = uVar26;
            uVar21 = uVar24;
LAB_000195d9:
            bVar5 = true;
          }
          else if (bVar15 == 4) {
            uVar13 = (ulonglong)local_b6;
            uVar23 = local_b8 + local_b6;
            uVar11 = uVar24 + uVar26;
            if ((uVar26 <= uVar13) && (uVar13 <= uVar11)) {
              uVar13 = uVar11;
            }
            uVar22 = (ulonglong)uVar23;
            if ((uVar26 <= uVar23) && (uVar23 <= uVar11)) {
              uVar22 = uVar26;
            }
            iVar20 = (int)uVar22;
            if (uVar22 <= uVar13) {
              uVar13 = 0;
              iVar20 = 0;
            }
            uVar21 = iVar20 - (int)uVar13;
            if (uVar21 != 0) goto LAB_000195d9;
LAB_0001957c:
            bVar31 = 0x2a;
            uVar13 = uVar26;
            uVar21 = uVar24;
          }
          else if (bVar15 == 5) {
            uVar11 = (ulonglong)local_a8;
            uVar23 = uVar25 + sVar28;
            uVar33 = uVar21 + uVar24;
            uVar32 = (ushort)uVar33;
            if (uVar26 == uVar11) {
              uVar19 = uVar33 & 0xffff;
              if (uVar23 < uVar32) {
                uVar19 = (uint)uVar23;
              }
              uVar13 = (longlong)(int)uVar19;
            }
            else {
              uVar13 = uVar11;
              if (uVar26 < uVar11) {
                uVar13 = uVar26;
              }
            }
            if (uVar23 == uVar32) {
              uVar19 = local_a8;
              if (uVar11 < uVar26) {
                uVar19 = uVar21;
              }
            }
            else {
              uVar19 = (uint)uVar23;
              if (uVar23 < uVar32) {
                uVar19 = uVar33 & 0xffff;
              }
            }
            if (uVar19 < uVar13) goto LAB_0001957c;
            bVar31 = 0x28;
            bVar5 = true;
            uVar21 = uVar19 - (int)uVar13;
          }
          else {
            if (bVar15 != 7) goto LAB_000195de;
            uVar23 = (short)uVar24 + (short)uVar26;
            uVar13 = (ulonglong)local_a8;
            if (uVar26 < local_a8) {
              uVar13 = uVar26;
            }
            uVar21 = (uint)uVar23;
            if (uVar23 < (ushort)(local_a8 + local_ac)) {
              uVar21 = local_a8 + local_ac & 0xffff;
            }
            uVar24 = 0;
            uVar21 = uVar21 - (int)uVar13;
          }
LAB_000195f7:
          if ((bVar31 == 0x2a) || (bVar5)) {
            *(char *)(param_2 + 0xb1) = *(char *)(param_2 + 0xb1) + '\x01';
          }
          uVar33 = uVar24;
          if (bVar5) {
            uVar33 = 0;
          }
          puVar12 = FUN_00018954(param_2,bVar38,lVar37,bVar31,uVar13 + lVar9,uVar21,uVar7,uVar26,
                                 uVar33);
          if (puVar12 == (undefined8 *)0x0) {
            *(byte *)(param_2 + 0x57) = bVar29 + 1;
            NvRaidResQueueLowResourceNrp(param_2);
            return 0x103;
          }
          if (bVar5) {
            FUN_00018954(param_2,bVar38,lVar37,0x2a,lVar9 + uVar26,uVar24,uVar7,uVar26,uVar24);
          }
        }
      }
      bVar29 = bVar6;
    } while (bVar6 < bVar35);
    uVar24 = (uint)local_res20;
    uVar26 = (ulonglong)local_b6;
  }
  uVar11 = 0;
  uVar13 = 1;
  if ((*(byte *)(param_2 + 0x82) & 7) == 0) {
LAB_0001975e:
    uVar22 = uVar11;
    uVar30 = uVar11;
    if ((char)uVar13 == '\0') goto LAB_0001981c;
  }
  else {
    if ((*(byte *)(param_2 + 0x82) & 7) != 7) {
      if (((short)uVar26 == sVar28) && (uVar13 = 1, local_b8 == uVar25)) {
        uVar13 = uVar11;
      }
      goto LAB_0001975e;
    }
    uVar30 = (ulonglong)local_a0;
    uVar22 = (ulonglong)((uVar24 - iVar17 << (bVar14 & 0x1f)) - uVar18);
    if ((byte)uVar24 == bVar34) {
      uVar22 = uVar11;
    }
  }
  bVar14 = *(byte *)(param_2 + 0x83);
  if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)bVar14)) {
    uVar13 = uVar11;
  }
  else {
    uVar13 = *(ulonglong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)bVar14 * 8);
  }
  if (((uVar13 == 0) || ((*(uint *)(uVar13 + 4) & 1) != 0)) ||
     ((bVar36 == 0 && ((*(uint *)(uVar13 + 4) >> 8 & 1) != 0)))) {
    uVar13 = uVar11;
  }
  if ((uVar13 != 0) &&
     (puVar12 = FUN_00018954(param_2,bVar14,uVar13,0x28,uVar26 + lVar9,(uint)local_b8,(uint)uVar22,
                             uVar30,0), puVar12 == (undefined8 *)0x0)) {
    *(byte *)(param_2 + 0x57) = bVar35 + 1;
    NvRaidResQueueLowResourceNrp(param_2);
    DbgPrint("NvRaidParityLoadStripe: NvRaidParityAllocParityRelatedRequest failed\n");
    return 0x103;
  }
LAB_0001981c:
  puVar12 = *(undefined8 **)(param_2 + 0x20);
  *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
  puVar3 = puVar12;
  while( true ) {
    if (puVar3 == (undefined8 *)0x0) {
      *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x02';
      return 0;
    }
    if ((*(byte *)((longlong)puVar3 + 0x82) & 1) != 0) break;
    puVar3 = (undefined8 *)*puVar3;
  }
  if (*(char *)(param_2 + 0x55) == '\0') {
    DbgPrint("NvRaidParityLoadStripe: NvRaidPacketSubmitSubRequests called with no subreqs\n");
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
    return 0;
  }
  if (puVar12 != (undefined8 *)0x0) {
    do {
      puVar3 = (undefined8 *)*puVar12;
      if ((*(byte *)((longlong)puVar12 + 0x82) & 1) != 0) {
        NvRaidPacketSubmitRequest((longlong)puVar12);
      }
      puVar12 = puVar3;
    } while (puVar3 != (undefined8 *)0x0);
    return 0x103;
  }
  *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
  DbgPrint("NvRaidParityLoadStripe: NvRaidPacketSubmitSubRequests called with no subreqs\n");
  if ((*(uint *)(lVar2 + 0x60) & 0x400) == 0) {
    NvRaidParityLockRelease(param_2,uVar4,param_1);
    return 0;
  }
  return 0;
}



===== FUN_000198dc @ 000198dc =====

undefined8 FUN_000198dc(longlong param_1,longlong param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  undefined4 uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  ulonglong uVar8;
  short sVar9;
  ushort uVar10;
  ulonglong uVar11;
  byte bVar12;
  byte bVar13;
  uint uVar14;
  int iVar15;
  ulonglong uVar16;
  int iVar17;
  ulonglong uVar18;
  longlong *plVar19;
  byte bVar20;
  ushort uVar21;
  uint uVar22;
  int iVar23;
  uint uVar24;
  longlong lVar25;
  ushort uVar26;
  ulonglong uVar27;
  ushort uVar28;
  byte bVar29;
  ushort uVar30;
  bool bVar31;
  ushort local_88;
  short local_7e;
  longlong local_78;
  int local_70;
  undefined8 *local_68;
  
  bVar1 = *(byte *)(param_2 + 0x82);
  lVar6 = *(longlong *)(param_2 + 0x68);
  bVar2 = *(byte *)(param_2 + 0x83);
  lVar25 = *(longlong *)(param_1 + 0x58);
  iVar17 = 0;
  bVar29 = bVar1 & 7;
  local_68 = (undefined8 *)0x0;
  local_78 = 0;
  local_88 = 0;
  local_7e = 0;
  local_70 = 0;
  bVar12 = ~(byte)(*(uint *)(param_2 + 0x60) >> 2) & 1;
  if (bVar12 == 0) {
    bVar20 = *(byte *)(lVar25 + 0x17);
  }
  else {
    bVar20 = *(byte *)(lVar25 + 0x15);
  }
  uVar24 = *(uint *)(lVar25 + 0x28);
  plVar19 = *(longlong **)(param_2 + 0x20);
  uVar4 = *(uint *)(lVar25 + 0x1c);
  uVar5 = *(undefined4 *)(lVar25 + 0x24);
  if (plVar19 == (longlong *)0x0) {
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
  }
  else {
    if ((((bVar1 & 2) == 0) && (*(ushort *)(param_2 + 0x8c) == *(ushort *)(param_2 + 0x88))) &&
       (*(ushort *)(param_2 + 0x8e) == *(ushort *)(param_2 + 0x8a))) {
      if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)bVar2)) {
        lVar25 = 0;
      }
      else {
        lVar25 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)bVar2 * 8);
      }
      if (((lVar25 == 0) || ((*(uint *)(lVar25 + 4) & 1) != 0)) ||
         ((bVar12 == 0 && ((*(uint *)(lVar25 + 4) >> 8 & 1) != 0)))) {
        lVar25 = 0;
      }
      if (lVar25 != 0) {
        puVar7 = FUN_00018954(param_2,bVar2,lVar25,0x2a,
                              (plVar19[0x11] & ~(ulonglong)uVar24) +
                              (ulonglong)*(ushort *)(param_2 + 0x8c),
                              (uint)*(ushort *)(param_2 + 0x8e),0,0,0);
        if (puVar7 == (undefined8 *)0x0) {
          NvRaidResQueueLowResourceNrp(param_2);
          DbgPrint("NvRaidParityCalculateStripeData: NvRaidParityAllocParityRelatedRequest failed\n"
                  );
          return 0x103;
        }
        *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + -1;
      }
    }
    bVar31 = (bVar1 & 3) == 1;
    do {
      if (*(byte *)(plVar19 + 9) == bVar2) {
        local_78 = plVar19[0x15];
        break;
      }
      plVar19 = (longlong *)*plVar19;
    } while (plVar19 != (longlong *)0x0);
    if ((((*(byte *)(param_2 + 0x82) & 2) == 0) && (*(ushort *)(param_2 + 0x8a) != 0)) &&
       (local_78 != 0)) {
      NvRaidPacketScatterGatherGroupZero
                (local_78,(uint)*(ushort *)(param_2 + 0x88) - (uint)*(ushort *)(param_2 + 0x8c),
                 (uint)*(ushort *)(param_2 + 0x8a));
    }
    uVar30 = (ushort)uVar24;
    uVar21 = *(ushort *)(lVar6 + 0x88) & uVar30;
    uVar28 = *(short *)(lVar6 + 0x90) + *(ushort *)(lVar6 + 0x88) & uVar30;
    puVar7 = *(undefined8 **)(param_2 + 0x20);
    if (uVar28 == 0) {
      uVar28 = (ushort)uVar4;
    }
LAB_00019b28:
    for (; bVar12 = (byte)uVar5, puVar7 != (undefined8 *)0x0; puVar7 = (undefined8 *)*puVar7) {
      bVar13 = *(byte *)(puVar7 + 9);
      if (bVar13 != bVar2) {
        if ((bVar1 & 8) == 0) {
          if (bVar2 < bVar13) {
            bVar13 = bVar13 - 1;
          }
        }
        else {
          bVar13 = (byte)((ulonglong)((uint)*(byte *)(param_2 + 0x87) + (uint)bVar13) %
                         (ulonglong)(longlong)(int)(bVar20 + 1));
        }
        lVar25 = puVar7[0x15];
        local_68 = puVar7 + 0x10;
        local_7e = *(short *)(puVar7 + 0x12);
        local_88 = *(ushort *)(puVar7 + 0x11) & uVar30;
        goto LAB_00019bb9;
      }
LAB_00019e2e:
      if (puVar7 == (undefined8 *)0x0) goto LAB_00019e4e;
    }
    if (bVar31) {
      bVar13 = *(byte *)(param_2 + 0x86);
      bVar31 = false;
      lVar25 = 0;
LAB_00019bb9:
      bVar3 = *(byte *)(param_2 + 0x84);
      if ((bVar13 < bVar3) || (*(byte *)(param_2 + 0x85) < bVar13)) {
        uVar18 = 0;
        uVar8 = 0;
      }
      else {
        uVar18 = (ulonglong)uVar21;
        if (bVar13 == bVar3) {
          local_70 = 0;
        }
        else {
          uVar18 = 0;
          local_70 = ((uint)bVar13 - (uint)bVar3 << (bVar12 & 0x1f)) - (uint)uVar21;
        }
        if (bVar13 == *(byte *)(param_2 + 0x85)) {
          uVar24 = (uint)uVar28;
        }
        else {
          uVar24 = uVar4 & 0xffff;
        }
        uVar8 = (ulonglong)(uVar24 - (int)uVar18);
      }
      if (local_78 == 0) goto LAB_00019e2e;
      uVar24 = (uint)uVar8;
      iVar23 = (int)uVar18;
      if (lVar25 != 0) {
        if ((*(byte *)((longlong)local_68 + 2) & 1) != 0) {
          if (bVar29 == 7) {
            uVar14 = (uint)*(ushort *)(param_2 + 0x88);
            sVar9 = *(short *)(param_2 + 0x8a);
          }
          else {
            uVar10 = *(ushort *)(param_2 + 0x88);
            uVar26 = *(short *)(param_2 + 0x8a) + uVar10;
            uVar8 = uVar8 + uVar18;
            uVar16 = (ulonglong)uVar10;
            if ((uVar18 <= uVar10) && (uVar10 <= uVar8)) {
              uVar16 = uVar8;
            }
            uVar11 = (ulonglong)uVar26;
            if ((uVar18 <= uVar26) && (uVar26 <= uVar8)) {
              uVar11 = uVar18;
            }
            sVar9 = (short)uVar11;
            if (uVar11 <= uVar16) {
              uVar16 = 0;
              sVar9 = 0;
            }
            uVar14 = (uint)uVar16;
            sVar9 = sVar9 - (short)uVar16;
          }
          uVar10 = sVar9 + (short)uVar14;
          uVar26 = local_7e + local_88;
          if ((uVar14 < uVar26) && (local_88 < uVar10)) {
            if (uVar14 < local_88) {
              uVar14 = (uint)local_88;
            }
            if (uVar26 < uVar10) {
              uVar10 = uVar26;
            }
            uVar22 = uVar10 - uVar14;
          }
          else {
            uVar22 = 0;
          }
          if (uVar22 != 0) {
            NvRaidPacketScatterGatherGroupXor
                      (local_78,uVar14 - *(ushort *)(param_2 + 0x8c),uVar22,lVar25,uVar14 - local_88
                       ,uVar22);
          }
        }
        if (bVar29 == 7) {
          if (uVar24 == 0) goto LAB_00019e2e;
          NvRaidPacketScatterGatherGroupCopy
                    (*(longlong *)(lVar6 + 0xa8),local_70,lVar25,iVar23,uVar24);
        }
      }
      if (uVar24 == 0) goto LAB_00019e2e;
      if ((bVar29 != 7) && ((lVar25 == 0 || ((*(byte *)((longlong)local_68 + 2) & 2) != 0)))) {
        NvRaidPacketScatterGatherGroupXor
                  (local_78,iVar23 - (uint)*(ushort *)(param_2 + 0x8c),uVar24,
                   *(longlong *)(lVar6 + 0xa8),local_70,uVar24);
      }
      if (lVar25 == 0) goto LAB_00019e2e;
      if (puVar7 != (undefined8 *)0x0) {
        if (((*(byte *)((longlong)local_68 + 2) & 1) != 0) && ((*(byte *)(lVar6 + 0x82) & 2) != 0))
        {
          uVar16 = (ulonglong)*(ushort *)(param_2 + 0x88);
          uVar8 = *(ushort *)(param_2 + 0x8a) + uVar16;
          uVar11 = (ulonglong)(uVar24 + iVar23) & 0xffff;
          if ((uVar16 <= uVar18) && (uVar18 <= uVar8)) {
            uVar18 = uVar8;
          }
          iVar15 = (int)uVar18;
          uVar27 = (ulonglong)(uVar24 + iVar23 & 0xffff);
          if ((uVar16 <= uVar27) && (uVar27 <= uVar8)) {
            uVar11 = (ulonglong)*(ushort *)(param_2 + 0x88);
          }
          iVar23 = (int)uVar11;
          if (uVar11 <= uVar18) {
            iVar15 = 0;
            iVar23 = 0;
          }
          uVar24 = iVar23 - iVar15;
          if (uVar24 != 0) {
            NvRaidPacketScatterGatherGroupXor
                      (local_78,iVar15 - (uint)*(ushort *)(param_2 + 0x8c),uVar24,lVar25,
                       iVar15 - (uint)local_88,uVar24);
          }
        }
        goto LAB_00019e2e;
      }
LAB_00019e4e:
      puVar7 = (undefined8 *)0x0;
      goto LAB_00019b28;
    }
    if (bVar29 == 7) {
      if (*(byte *)(param_2 + 0x86) != *(byte *)(param_2 + 0x84)) {
        iVar17 = ((uint)*(byte *)(param_2 + 0x86) - (uint)*(byte *)(param_2 + 0x84) <<
                 (bVar12 & 0x1f)) - (uint)uVar21;
      }
      NvRaidPacketScatterGatherGroupCopy
                (*(longlong *)(lVar6 + 0xa8),iVar17,local_78,0,(uint)*(ushort *)(param_2 + 0x8e));
    }
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x03';
  }
  return 0;
}



===== FUN_00019ee8 @ 00019ee8 =====

undefined8 FUN_00019ee8(longlong param_1,longlong param_2)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  
  cVar1 = *(char *)(param_2 + 0x83);
  lVar4 = *(longlong *)(param_2 + 0x68);
  uVar8 = 0;
  uVar3 = *(undefined4 *)(*(longlong *)(param_1 + 0x58) + 0x24);
  cVar2 = *(char *)(param_2 + 0x55);
  *(undefined1 *)(param_2 + 0x55) = 0;
  plVar6 = *(longlong **)(param_2 + 0x20);
  while (plVar6 != (longlong *)0x0) {
    plVar5 = (longlong *)*plVar6;
    if (((char)plVar6[9] == cVar1) ||
       ((cVar2 != '\0' && ((*(byte *)((longlong)plVar6 + 0x82) & 1) == 0)))) {
      *(undefined2 *)((longlong)plVar6 + 0x81) = 0x22a;
      uVar8 = (ulonglong)plVar6[0x11] >> ((byte)uVar3 & 0x3f);
      *(byte *)((longlong)plVar6 + 0x82) = *(byte *)(lVar4 + 0x82) & 0x10 | 2;
      *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
      plVar6 = plVar5;
    }
    else {
      if (plVar5 == (longlong *)0x0) {
        *(longlong *)(param_2 + 0x28) = plVar6[1];
      }
      else {
        plVar5[1] = plVar6[1];
      }
      *(longlong *)plVar6[1] = *plVar6;
      NvRaidResNrpFree(*(longlong *)(param_1 + 0x18),(undefined4 *)plVar6);
      plVar6 = plVar5;
    }
  }
  if (*(char *)(param_2 + 0x55) == '\0') {
    DbgPrint("NvRaidParityStoreStripe: NvRaidPacketSubmitSubRequests called with no subreqs\n");
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x02';
  }
  else {
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
    uVar7 = NvRaidPacketSubmitSubRequests((longlong *)(param_2 + 0x20));
    if ((int)uVar7 == 0x103) {
      return 0x103;
    }
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
    DbgPrint("NvRaidParityStoreStripe: NvRaidPacketSubmitSubRequests called with no subreqs\n");
    if ((*(uint *)(lVar4 + 0x60) & 0x400) == 0) {
      NvRaidParityLockRelease(param_2,uVar8,param_1);
    }
  }
  return 0;
}



===== FUN_0001a024 @ 0001a024 =====

undefined8 FUN_0001a024(longlong param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *_Dst;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  uint uVar6;
  undefined8 *puVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  
  if (((*(int *)(param_2 + 0x12) == 1) || ((*(byte *)((longlong)param_2 + 0x81) & 2) != 0)) ||
     (*(int *)(*(longlong *)(param_1 + 0x58) + 0x18) == 0x83)) {
    *(char *)((longlong)param_2 + 0x56) = *(char *)((longlong)param_2 + 0x56) + '\x05';
  }
  else {
    uVar10 = 0;
    uVar9 = 0;
    uVar6 = *(int *)(*(longlong *)(param_1 + 0x58) + 0x1c) * 0x200;
    if (*(int *)(param_2 + 0x12) != 0) {
      do {
        _Dst = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
        if (_Dst == (undefined8 *)0x0) {
          return 0xc000009a;
        }
        if ((((uint)param_2 | (uint)_Dst) & 0xf) == 0) {
          lVar3 = 1;
          puVar1 = _Dst;
          puVar2 = param_2;
          do {
            puVar7 = puVar2;
            puVar5 = puVar1;
            uVar4 = puVar7[1];
            *puVar5 = *puVar7;
            puVar5[1] = uVar4;
            uVar4 = puVar7[3];
            puVar5[2] = puVar7[2];
            puVar5[3] = uVar4;
            uVar4 = puVar7[5];
            puVar5[4] = puVar7[4];
            puVar5[5] = uVar4;
            uVar4 = puVar7[7];
            puVar5[6] = puVar7[6];
            puVar5[7] = uVar4;
            uVar4 = puVar7[9];
            puVar5[8] = puVar7[8];
            puVar5[9] = uVar4;
            uVar4 = puVar7[0xb];
            puVar5[10] = puVar7[10];
            puVar5[0xb] = uVar4;
            uVar4 = puVar7[0xd];
            puVar5[0xc] = puVar7[0xc];
            puVar5[0xd] = uVar4;
            uVar4 = puVar7[0xf];
            puVar5[0xe] = puVar7[0xe];
            puVar5[0xf] = uVar4;
            lVar3 = lVar3 + -1;
            puVar1 = puVar5 + 0x10;
            puVar2 = puVar7 + 0x10;
          } while (lVar3 != 0);
          uVar4 = puVar7[0x11];
          puVar5[0x10] = puVar7[0x10];
          puVar5[0x11] = uVar4;
          uVar4 = puVar7[0x13];
          puVar5[0x12] = puVar7[0x12];
          puVar5[0x13] = uVar4;
          uVar4 = puVar7[0x15];
          puVar5[0x14] = puVar7[0x14];
          puVar5[0x15] = uVar4;
          uVar4 = puVar7[0x17];
          puVar5[0x16] = puVar7[0x16];
          puVar5[0x17] = uVar4;
          uVar4 = puVar7[0x19];
          puVar5[0x18] = puVar7[0x18];
          puVar5[0x19] = uVar4;
          uVar4 = puVar7[0x1b];
          puVar5[0x1a] = puVar7[0x1a];
          puVar5[0x1b] = uVar4;
          uVar4 = puVar7[0x1d];
          puVar5[0x1c] = puVar7[0x1c];
          puVar5[0x1d] = uVar4;
        }
        else {
          memcpy(_Dst,param_2,0xf0);
        }
        *(uint *)(_Dst + 0xc) = *(uint *)(_Dst + 0xc) & 0xfffffcff;
        *(undefined1 *)((longlong)_Dst + 0x55) = 0;
        _Dst[4] = 0;
        _Dst[5] = _Dst + 4;
        lVar3 = param_2[0x11];
        *(undefined4 *)(_Dst + 0x12) = 1;
        _Dst[0x11] = uVar9 + lVar3;
        _Dst[0x15] = 0;
        NvRaidPacketScatterGatherGroupAllocBuildPartialGroup
                  ((longlong)param_2,(longlong)_Dst,uVar10,uVar6);
        *_Dst = 0;
        _Dst[1] = param_2[5];
        uVar8 = (int)uVar9 + 1;
        uVar9 = (ulonglong)uVar8;
        *(undefined8 **)param_2[5] = _Dst;
        *(char *)((longlong)param_2 + 0x55) = *(char *)((longlong)param_2 + 0x55) + '\x01';
        param_2[5] = _Dst;
        _Dst[0xd] = param_2;
        uVar10 = (ulonglong)((int)uVar10 + uVar6);
        _Dst[0xe] = param_2[8];
      } while (uVar8 < *(uint *)(param_2 + 0x12));
    }
    *(char *)((longlong)param_2 + 0x56) = *(char *)((longlong)param_2 + 0x56) + '\x01';
    uVar4 = NvRaidPacketSubmitSubRequests(param_2 + 4);
    if ((int)uVar4 == 0x103) {
      return 0x103;
    }
    *(char *)((longlong)param_2 + 0x56) = *(char *)((longlong)param_2 + 0x56) + '\x01';
    DbgPrint(
            "NvRaidParityJob_SplitStripeRequest: NvRaidPacketSubmitSubRequests called with no subreqs\n"
            );
  }
  return 0;
}



===== FUN_0001a22c @ 0001a22c =====

undefined8 FUN_0001a22c(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  byte bVar5;
  char *pcVar6;
  byte bVar7;
  longlong lVar8;
  int iVar9;
  byte bVar10;
  
  lVar8 = *(longlong *)(param_1 + 0x58);
  bVar1 = *(byte *)(lVar8 + 0x15);
  if ((*(byte *)(param_2 + 0x81) & 2) == 0) {
    if ((*(uint *)(lVar8 + 0x18) & 0xffffffef) == 0x85) {
      bVar7 = bVar1 - (char)(*(ulonglong *)(param_2 + 0x88) % (ulonglong)(bVar1 + 1));
    }
    else {
      bVar7 = bVar1;
    }
  }
  else {
    bVar7 = *(byte *)(param_2 + 0x82);
  }
  lVar2 = *(longlong *)(param_2 + 0x88);
  bVar5 = (byte)*(undefined4 *)(lVar8 + 0x24);
  iVar9 = *(int *)(param_2 + 0x90) << (bVar5 & 0x1f);
  bVar10 = 0;
  if (bVar1 != 0xffffffff) {
    do {
      if (bVar10 != bVar7) {
        if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)bVar10)) {
          lVar8 = 0;
        }
        else {
          lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)bVar10 * 8);
        }
        if ((lVar8 == 0) || ((*(uint *)(lVar8 + 4) & 1) != 0)) {
          lVar8 = 0;
        }
        if (lVar8 != 0) {
          puVar3 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
          if (puVar3 == (undefined8 *)0x0) {
            return 0xc000009a;
          }
          NvRaidScsiSetupReadWrite
                    ((longlong)puVar3,bVar10,lVar8,NvRaidStateSubRequestsDone,0x28,
                     lVar2 << (bVar5 & 0x3f),iVar9);
          uVar4 = NvRaidResBufferAllocateForNrp
                            (*(longlong *)(param_1 + 0x18),iVar9 << 9,(longlong)puVar3);
          if ((int)uVar4 < 0) {
            pcVar6 = "NvRaidParityJob_Read: NvRaidResBufferAllocateForNrp failed\n";
            goto LAB_0001a3b6;
          }
          *puVar3 = 0;
          puVar3[1] = *(undefined8 *)(param_2 + 0x28);
          **(undefined8 **)(param_2 + 0x28) = puVar3;
          *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
          *(undefined8 **)(param_2 + 0x28) = puVar3;
          puVar3[0xd] = param_2;
          puVar3[0xe] = *(undefined8 *)(param_2 + 0x40);
        }
      }
      bVar10 = bVar10 + 1;
    } while ((uint)bVar10 < bVar1 + 1);
  }
  *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
  uVar4 = NvRaidPacketSubmitSubRequests((longlong *)(param_2 + 0x20));
  if ((int)uVar4 == 0x103) {
    uVar4 = 0x103;
  }
  else {
    pcVar6 = "NvRaidParityJob_Read: NvRaidPacketSubmitSubRequests called with no subreqs\n";
LAB_0001a3b6:
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
    DbgPrint(pcVar6);
    uVar4 = 0;
  }
  return uVar4;
}



===== FUN_0001a3e4 @ 0001a3e4 =====

undefined8 FUN_0001a3e4(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  uint uVar2;
  
  uVar2 = *(int *)(param_2 + 0x90) <<
          ((byte)*(undefined4 *)(*(longlong *)(param_1 + 0x58) + 0x24) & 0x1f);
  NvRaidPacketScatterGatherGroupZero(*(longlong *)(param_2 + 0xa8),0,uVar2);
  for (puVar1 = *(undefined8 **)(param_2 + 0x20); puVar1 != (undefined8 *)0x0;
      puVar1 = (undefined8 *)*puVar1) {
    NvRaidPacketScatterGatherGroupXor(*(longlong *)(param_2 + 0xa8),0,uVar2,puVar1[0x15],0,uVar2);
  }
  *(undefined1 *)(param_2 + 0x56) = 3;
  return 0;
}



===== FUN_0001a45c @ 0001a45c =====

undefined8 FUN_0001a45c(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  byte bVar5;
  longlong lVar6;
  byte bVar7;
  
  lVar6 = *(longlong *)(param_1 + 0x58);
  bVar7 = *(byte *)(lVar6 + 0x15);
  if ((*(byte *)(param_2 + 0x81) & 2) == 0) {
    if ((*(uint *)(lVar6 + 0x18) & 0xffffffef) == 0x85) {
      bVar7 = bVar7 - (char)(*(ulonglong *)(param_2 + 0x88) % (ulonglong)(bVar7 + 1));
    }
  }
  else {
    bVar7 = *(byte *)(param_2 + 0x82);
  }
  lVar2 = *(longlong *)(param_2 + 0x88);
  iVar1 = *(int *)(param_2 + 0x90);
  bVar5 = (byte)*(undefined4 *)(lVar6 + 0x24);
  if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= (uint)bVar7)) {
    lVar6 = 0;
  }
  else {
    lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)bVar7 * 8);
  }
  if ((lVar6 == 0) || ((*(uint *)(lVar6 + 4) & 1) != 0)) {
    lVar6 = 0;
  }
  if (lVar6 == 0) {
    *(undefined1 *)(param_2 + 0x56) = 2;
  }
  else {
    puVar3 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
    if (puVar3 == (undefined8 *)0x0) {
      return 0xc000009a;
    }
    NvRaidScsiSetupReadWrite
              ((longlong)puVar3,bVar7,lVar6,NvRaidStateSubRequestsDone,0x2a,lVar2 << (bVar5 & 0x3f),
               iVar1 << (bVar5 & 0x1f));
    uVar4 = *(undefined8 *)(param_2 + 0xa8);
    *puVar3 = 0;
    puVar3[0x15] = uVar4;
    puVar3[1] = *(undefined8 *)(param_2 + 0x28);
    **(undefined8 **)(param_2 + 0x28) = puVar3;
    *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
    *(undefined8 **)(param_2 + 0x28) = puVar3;
    puVar3[0xd] = param_2;
    puVar3[0xe] = *(undefined8 *)(param_2 + 0x40);
    *(undefined1 *)(param_2 + 0x56) = 1;
    uVar4 = NvRaidPacketSubmitSubRequests((longlong *)(param_2 + 0x20));
    if ((int)uVar4 == 0x103) {
      return 0x103;
    }
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
    DbgPrint("NvRaidParityJob_Write: NvRaidPacketSubmitSubRequests called with no subreqs\n");
  }
  return 0;
}



===== FUN_0001a5d0 @ 0001a5d0 =====

undefined8 * FUN_0001a5d0(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  byte bVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 uVar6;
  bool bVar7;
  undefined8 *puVar8;
  longlong lVar9;
  uint uVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong lVar13;
  uint uVar14;
  uint uVar15;
  longlong local_58;
  undefined8 uStack_50;
  longlong local_48;
  longlong *local_40;
  
  plVar1 = (longlong *)(param_1 + 0xd0);
  bVar7 = false;
  if (*plVar1 != 0) {
    local_58 = *plVar1;
    uStack_50 = *(undefined8 *)(param_1 + 0xd8);
    *(longlong **)(local_58 + 0xe8) = &local_58;
    *plVar1 = 0;
    *(undefined8 *)(param_1 + 0xd8) = plVar1;
    local_40 = (longlong *)(param_1 + 0xe0);
    *local_40 = 0;
    *(longlong **)(param_1 + 0xe8) = &local_48;
    lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x58);
    if ((~(*(uint *)(param_1 + 0x60) >> 2) & 1) == 0) {
      bVar3 = *(byte *)(lVar4 + 0x17);
    }
    else {
      bVar3 = *(byte *)(lVar4 + 0x15);
    }
    uVar15 = *(int *)(lVar4 + 0x1c) * (uint)bVar3;
    uVar10 = *(uint *)(lVar4 + 0x28) & *(uint *)(param_1 + 0x88);
    uVar14 = *(uint *)(param_1 + 0x90);
    if (local_58 != 0) {
      lVar9 = local_58;
      lVar11 = param_1;
      lVar13 = param_1;
      while ((((*(char *)(lVar9 + 0x80) == *(char *)(param_1 + 0x80) &&
               (*(char *)(lVar9 + 0x81) == *(char *)(param_1 + 0x81))) &&
              (*(char *)(lVar9 + 0x82) == *(char *)(param_1 + 0x82))) &&
             (*(longlong *)(lVar9 + 0xa8) != 0))) {
        lVar5 = *(longlong *)(lVar9 + 0x88);
        if ((ulonglong)*(uint *)(param_1 + 0x90) + *(longlong *)(param_1 + 0x88) == lVar5) {
          uVar14 = uVar14 + *(int *)(lVar9 + 0x90);
          if ((uVar15 < uVar14) || (uVar15 < uVar10 + uVar14)) break;
          plVar2 = (longlong *)(lVar9 + 0xe0);
          lVar5 = *plVar2;
          if (lVar5 == 0) {
            uStack_50 = *(undefined8 *)(lVar9 + 0xe8);
          }
          else {
            *(undefined8 *)(lVar5 + 0xe8) = *(undefined8 *)(lVar9 + 0xe8);
          }
          plVar12 = (longlong *)(lVar13 + 0xe0);
          **(longlong **)(lVar9 + 0xe8) = *plVar2;
          lVar13 = *plVar12;
          *plVar2 = lVar13;
          if (lVar13 == 0) {
            local_40 = plVar2;
          }
          else {
            *(longlong **)(lVar13 + 0xe8) = plVar2;
          }
          *plVar12 = lVar9;
          *(longlong **)(lVar9 + 0xe8) = plVar12;
          lVar13 = lVar9;
          lVar9 = lVar5;
        }
        else {
          if (lVar5 + (ulonglong)*(uint *)(lVar9 + 0x90) != *(longlong *)(param_1 + 0x88)) break;
          uVar14 = uVar14 + *(uint *)(lVar9 + 0x90);
          uVar10 = (uint)lVar5 & *(uint *)(lVar4 + 0x28);
          if ((uVar15 < uVar14) || (uVar15 < uVar10 + uVar14)) break;
          plVar2 = (longlong *)(lVar9 + 0xe0);
          lVar5 = *plVar2;
          if (lVar5 == 0) {
            uStack_50 = *(undefined8 *)(lVar9 + 0xe8);
          }
          else {
            *(undefined8 *)(lVar5 + 0xe8) = *(undefined8 *)(lVar9 + 0xe8);
          }
          **(longlong **)(lVar9 + 0xe8) = *plVar2;
          uVar6 = *(undefined8 *)(lVar11 + 0xe8);
          *plVar2 = lVar11;
          *(undefined8 *)(lVar9 + 0xe8) = uVar6;
          **(longlong **)(lVar11 + 0xe8) = lVar9;
          *(longlong **)(lVar11 + 0xe8) = plVar2;
          lVar11 = lVar9;
          lVar9 = lVar5;
        }
        bVar7 = true;
        if (lVar9 == 0) break;
      }
      if (bVar7) {
        local_48 = param_1;
        puVar8 = FUN_0001a870(&local_48);
        if (local_58 == 0) {
          puVar8[0x1b] = puVar8 + 0x1a;
          puVar8[0x1a] = 0;
        }
        else {
          plVar1 = puVar8 + 0x1a;
          *plVar1 = local_58;
          puVar8[0x1b] = uStack_50;
          *(longlong **)(*plVar1 + 0xe8) = plVar1;
        }
        return puVar8;
      }
      if (local_58 != 0) {
        *plVar1 = local_58;
        *(undefined8 *)(param_1 + 0xd8) = uStack_50;
        *(longlong **)(*plVar1 + 0xe8) = plVar1;
        return (undefined8 *)0x0;
      }
    }
    *plVar1 = 0;
    *(undefined8 *)(param_1 + 0xd8) = plVar1;
  }
  return (undefined8 *)0x0;
}



===== FUN_0001a870 @ 0001a870 =====

undefined8 * FUN_0001a870(longlong *param_1)

{
  longlong *plVar1;
  char *pcVar2;
  undefined8 *_Src;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *_Dst;
  longlong lVar5;
  undefined8 *_Dst_00;
  undefined8 uVar6;
  uint uVar7;
  undefined8 *puVar8;
  uint uVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  uint uVar12;
  undefined8 *_Src_00;
  
  _Src_00 = (undefined8 *)*param_1;
  _Src = (undefined8 *)_Src_00[4];
  _Dst_00 = (undefined8 *)0x0;
  _Dst = NvRaidResNrpAllocate(*(longlong *)(_Src_00[8] + 0x18));
  if (_Dst == (undefined8 *)0x0) {
    return (undefined8 *)0x0;
  }
  if ((((uint)_Src_00 | (uint)_Dst) & 0xf) == 0) {
    lVar5 = 1;
    puVar3 = _Dst;
    puVar4 = _Src_00;
    do {
      puVar10 = puVar4;
      puVar8 = puVar3;
      uVar6 = puVar10[1];
      *puVar8 = *puVar10;
      puVar8[1] = uVar6;
      uVar6 = puVar10[3];
      puVar8[2] = puVar10[2];
      puVar8[3] = uVar6;
      uVar6 = puVar10[5];
      puVar8[4] = puVar10[4];
      puVar8[5] = uVar6;
      uVar6 = puVar10[7];
      puVar8[6] = puVar10[6];
      puVar8[7] = uVar6;
      uVar6 = puVar10[9];
      puVar8[8] = puVar10[8];
      puVar8[9] = uVar6;
      uVar6 = puVar10[0xb];
      puVar8[10] = puVar10[10];
      puVar8[0xb] = uVar6;
      uVar6 = puVar10[0xd];
      puVar8[0xc] = puVar10[0xc];
      puVar8[0xd] = uVar6;
      uVar6 = puVar10[0xf];
      puVar8[0xe] = puVar10[0xe];
      puVar8[0xf] = uVar6;
      lVar5 = lVar5 + -1;
      puVar3 = puVar8 + 0x10;
      puVar4 = puVar10 + 0x10;
    } while (lVar5 != 0);
    uVar6 = puVar10[0x11];
    puVar8[0x10] = puVar10[0x10];
    puVar8[0x11] = uVar6;
    uVar6 = puVar10[0x13];
    puVar8[0x12] = puVar10[0x12];
    puVar8[0x13] = uVar6;
    uVar6 = puVar10[0x15];
    puVar8[0x14] = puVar10[0x14];
    puVar8[0x15] = uVar6;
    uVar6 = puVar10[0x17];
    puVar8[0x16] = puVar10[0x16];
    puVar8[0x17] = uVar6;
    uVar6 = puVar10[0x19];
    puVar8[0x18] = puVar10[0x18];
    puVar8[0x19] = uVar6;
    uVar6 = puVar10[0x1b];
    puVar8[0x1a] = puVar10[0x1a];
    puVar8[0x1b] = uVar6;
    uVar6 = puVar10[0x1d];
    puVar8[0x1c] = puVar10[0x1c];
    puVar8[0x1d] = uVar6;
  }
  else {
    memcpy(_Dst,_Src_00,0xf0);
  }
  *(undefined1 *)((longlong)_Dst + 0x55) = 0;
  _Dst[4] = 0;
  _Dst[5] = _Dst + 4;
  *_Dst = 0;
  _Dst[1] = 0;
  _Dst[0x1c] = 0;
  _Dst[0x1d] = 0;
  if (_Src != (undefined8 *)0x0) {
    _Dst_00 = NvRaidResNrpAllocate(*(longlong *)(_Src_00[8] + 0x18));
    if (_Dst_00 == (undefined8 *)0x0) {
      _Dst_00 = _Dst;
      goto LAB_0001a9ab;
    }
    if ((((uint)_Src | (uint)_Dst_00) & 0xf) == 0) {
      lVar5 = 1;
      puVar3 = _Dst_00;
      puVar4 = _Src;
      do {
        puVar10 = puVar4;
        puVar8 = puVar3;
        uVar6 = puVar10[1];
        *puVar8 = *puVar10;
        puVar8[1] = uVar6;
        uVar6 = puVar10[3];
        puVar8[2] = puVar10[2];
        puVar8[3] = uVar6;
        uVar6 = puVar10[5];
        puVar8[4] = puVar10[4];
        puVar8[5] = uVar6;
        uVar6 = puVar10[7];
        puVar8[6] = puVar10[6];
        puVar8[7] = uVar6;
        uVar6 = puVar10[9];
        puVar8[8] = puVar10[8];
        puVar8[9] = uVar6;
        uVar6 = puVar10[0xb];
        puVar8[10] = puVar10[10];
        puVar8[0xb] = uVar6;
        uVar6 = puVar10[0xd];
        puVar8[0xc] = puVar10[0xc];
        puVar8[0xd] = uVar6;
        uVar6 = puVar10[0xf];
        puVar8[0xe] = puVar10[0xe];
        puVar8[0xf] = uVar6;
        lVar5 = lVar5 + -1;
        puVar3 = puVar8 + 0x10;
        puVar4 = puVar10 + 0x10;
      } while (lVar5 != 0);
      uVar6 = puVar10[0x11];
      puVar8[0x10] = puVar10[0x10];
      puVar8[0x11] = uVar6;
      uVar6 = puVar10[0x13];
      puVar8[0x12] = puVar10[0x12];
      puVar8[0x13] = uVar6;
      uVar6 = puVar10[0x15];
      puVar8[0x14] = puVar10[0x14];
      puVar8[0x15] = uVar6;
      uVar6 = puVar10[0x17];
      puVar8[0x16] = puVar10[0x16];
      puVar8[0x17] = uVar6;
      uVar6 = puVar10[0x19];
      puVar8[0x18] = puVar10[0x18];
      puVar8[0x19] = uVar6;
      uVar6 = puVar10[0x1b];
      puVar8[0x1a] = puVar10[0x1a];
      puVar8[0x1b] = uVar6;
      uVar6 = puVar10[0x1d];
      puVar8[0x1c] = puVar10[0x1c];
      puVar8[0x1d] = uVar6;
    }
    else {
      memcpy(_Dst_00,_Src,0xf0);
    }
    *(undefined1 *)((longlong)_Dst_00 + 0x55) = 0;
    _Dst_00[4] = 0;
    _Dst_00[5] = _Dst_00 + 4;
    *_Dst_00 = 0;
    _Dst_00[1] = 0;
    _Dst_00[0x1c] = 0;
    _Dst_00[0x1d] = 0;
    _Dst_00[0xd] = _Dst;
  }
  uVar6 = NvRaidResSgGroupAllocateForNrp(*(longlong *)(_Src_00[8] + 0x18),(longlong)_Dst);
  if (-1 < (int)uVar6) {
    *(undefined4 *)(_Dst + 0x12) = 0;
    do {
      uVar12 = 0;
      *(int *)(_Dst + 0x12) = *(int *)(_Dst + 0x12) + *(int *)(_Src_00 + 0x12);
      if (*(short *)(_Src_00[0x15] + 4) != 0) {
        do {
          lVar5 = _Src_00[0x15];
          uVar11 = (ulonglong)uVar12;
          uVar7 = (uint)*(ushort *)(lVar5 + 6);
          if (*(ushort *)(lVar5 + 6) <= uVar12) {
            do {
              lVar5 = *(longlong *)(lVar5 + 8);
              uVar9 = (int)uVar11 - uVar7;
              uVar11 = (ulonglong)uVar9;
              uVar7 = (uint)*(ushort *)(lVar5 + 6);
            } while (uVar7 <= uVar9);
          }
          NvRaidPacketScatterGatherElementAdd
                    (_Dst[0x15],*(undefined8 *)(lVar5 + 0x18 + uVar11 * 0x10),
                     *(undefined4 *)(lVar5 + 0x20 + uVar11 * 0x10));
          uVar12 = uVar12 + 1;
        } while (uVar12 < *(ushort *)(_Src_00[0x15] + 4));
      }
      *(undefined1 *)(_Src_00 + 0x16) = 0;
      _Src_00 = (undefined8 *)_Src_00[0x1c];
    } while (_Src_00 != (undefined8 *)0x0);
    if (*param_1 == 0) {
      _Dst[7] = _Dst + 6;
      _Dst[6] = 0;
    }
    else {
      lVar5 = param_1[1];
      plVar1 = _Dst + 6;
      *plVar1 = *param_1;
      _Dst[7] = lVar5;
      *(longlong **)(*plVar1 + 0xe8) = plVar1;
    }
    _Dst[0x14] = NvRaidParitySequentialReqsDone;
    _Dst[0xe] = _Dst[8];
    if (_Src == (undefined8 *)0x0) {
      pcVar2 = (char *)(_Dst[8] + 10);
      *pcVar2 = *pcVar2 + '\x01';
    }
    else {
      *_Dst_00 = 0;
      _Dst_00[1] = _Dst[5];
      *(undefined8 **)_Dst[5] = _Dst_00;
      *(char *)((longlong)_Dst + 0x55) = *(char *)((longlong)_Dst + 0x55) + '\x01';
      _Dst[5] = _Dst_00;
      _Dst_00[0xd] = _Dst;
      _Dst_00[0xe] = _Dst[8];
      *(char *)(_Dst[8] + 10) = *(char *)(_Dst[8] + 10) + '\x02';
    }
    return _Dst;
  }
  NvRaidResNrpFree(*(longlong *)(_Src_00[8] + 0x18),(undefined4 *)_Dst);
LAB_0001a9ab:
  NvRaidResNrpFree(*(longlong *)(_Src_00[8] + 0x18),(undefined4 *)_Dst_00);
  return (undefined8 *)0x0;
}



===== NvRaidParitySequentialReqsDone @ 0001abd4 =====

undefined8 NvRaidParitySequentialReqsDone(undefined8 param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar4 = *(longlong *)(param_2 + 0xc);
  while (lVar4 != 0) {
    if (*(longlong *)(lVar4 + 0xe0) == 0) {
      *(undefined8 *)(param_2 + 0xe) = *(undefined8 *)(lVar4 + 0xe8);
    }
    else {
      *(undefined8 *)(*(longlong *)(lVar4 + 0xe0) + 0xe8) = *(undefined8 *)(lVar4 + 0xe8);
    }
    **(undefined8 **)(lVar4 + 0xe8) = *(undefined8 *)(lVar4 + 0xe0);
    lVar3 = *(longlong *)(lVar4 + 0x20);
    *(undefined4 *)(lVar4 + 0x50) = param_2[0x14];
    *(undefined1 *)(lVar4 + 0x4b) = *(undefined1 *)((longlong)param_2 + 0x4b);
    *(undefined1 *)(lVar4 + 0x4c) = *(undefined1 *)(param_2 + 0x13);
    *(undefined1 *)(lVar4 + 0x4d) = *(undefined1 *)((longlong)param_2 + 0x4d);
    uVar1 = *(undefined1 *)((longlong)param_2 + 0x4e);
    *(undefined1 *)(lVar4 + 0x56) = 1;
    *(undefined1 *)(lVar4 + 0x4e) = uVar1;
    if (lVar3 == 0) {
      *(undefined1 *)(lVar4 + 0x56) = 4;
    }
    else {
      uVar2 = param_2[0x14];
      *(char *)(lVar3 + 0x56) = *(char *)(lVar3 + 0x56) + '\x03';
      *(undefined4 *)(lVar3 + 0x50) = uVar2;
      lVar4 = lVar3;
    }
    NvRaidPacketExecuteStateMachine(param_1,lVar4);
    lVar4 = *(longlong *)(param_2 + 0xc);
  }
  NvRaidResNrpFree(*(longlong *)(*(longlong *)(param_2 + 0x10) + 0x18),param_2);
  return 0;
}



===== FUN_0001accc @ 0001accc =====

uint FUN_0001accc(longlong param_1,uint param_2)

{
  byte bVar1;
  longlong lVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  bool bVar10;
  
  lVar2 = *(longlong *)(param_1 + 0x58);
  if (lVar2 == 0) {
    uVar5 = 0xc000000d;
  }
  else {
    bVar1 = *(byte *)(lVar2 + 0x15);
    uVar5 = *(uint *)(param_1 + 4) & 0xfffffff8;
    bVar7 = 1;
    if (*(uint *)(param_1 + 0x78) < (uint)bVar1) {
      uVar5 = uVar5 | 1;
    }
    else {
      bVar10 = (param_2 & 2) != 0;
      uVar9 = bVar1 + 1;
      bVar8 = 0;
      bVar6 = 0;
      if (bVar1 != 0xffffffff) {
        uVar3 = 0;
        do {
          if (((uint *)(param_1 + 0x78) == (uint *)0x0) || (*(uint *)(param_1 + 0x7c) <= uVar3)) {
            lVar4 = 0;
          }
          else {
            lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)uVar3 * 8);
          }
          if ((lVar4 == 0) || ((*(uint *)(lVar4 + 4) & 1) != 0)) {
            lVar4 = 0;
          }
          if (lVar4 == 0) {
LAB_0001ad9c:
            if (bVar10) {
              uVar5 = uVar5 | 1;
              break;
            }
            bVar10 = true;
          }
          else {
            bVar8 = bVar8 + 1;
            if (((*(char *)(lVar2 + 0x14) != '\x04') || ((*(uint *)(lVar4 + 4) & 0x100) == 0)) &&
               (((*(uint *)(lVar4 + 4) & 1) != 0 || ((*(uint *)(lVar4 + 4) >> 8 & 1) != 0)))) {
              lVar4 = 0;
            }
            if (lVar4 == 0) goto LAB_0001ad9c;
          }
          bVar6 = bVar6 + 1;
          uVar3 = (uint)bVar6;
        } while (uVar3 < uVar9);
      }
      if ((bVar6 == uVar9) && ((!bVar10 || (uVar5 = uVar5 | 4, bVar8 == bVar6)))) {
        uVar5 = uVar5 | 2;
      }
    }
    if ((param_2 & 8) != 0) {
      bVar7 = 1;
      NvRaidResArrayGenerateSignature((uint *)(lVar2 + 4));
    }
    if ((bVar7 & (byte)param_2) != 0) {
      NvRaidDefaultUpdateArrayStatus(param_1,param_2);
      if ((uVar5 & 0x20) != 0) {
        uVar5 = *(uint *)(param_1 + 4);
      }
      *(uint *)(param_1 + 4) = uVar5;
    }
  }
  return uVar5;
}



===== nvrSParityRaidSendCommand @ 0001ae1c =====

undefined8 nvrSParityRaidSendCommand(undefined8 param_1,longlong param_2)

{
  undefined8 uVar1;
  
  if ((*(char *)(param_2 + 0x80) == -1) && (*(char *)(param_2 + 0x81) == '\t')) {
    *(undefined1 *)(param_2 + 0x56) = 0;
    *(undefined ***)(param_2 + 0x58) = &PTR_FUN_00027c38;
    FUN_00011e84(param_2);
    return 0x103;
  }
  uVar1 = NvRaidStripeDefaultSendCommand(param_1,param_2);
  return uVar1;
}



===== FUN_0001ae5c @ 0001ae5c =====

void * FUN_0001ae5c(longlong param_1,longlong param_2,longlong param_3,int param_4,int param_5)

{
  void *pvVar1;
  
  pvVar1 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
  if (pvVar1 != (void *)0x0) {
    *(longlong *)((longlong)pvVar1 + 0x40) = param_1;
    *(undefined1 *)((longlong)pvVar1 + 0x48) = *(undefined1 *)(param_1 + 8);
    *(code **)((longlong)pvVar1 + 0xa0) = NvRaidStateSubRequestsDone;
    *(undefined4 *)((longlong)pvVar1 + 100) = *(undefined4 *)(param_2 + 100);
    if (param_5 == 0) {
      *(uint *)((longlong)pvVar1 + 0x60) = *(uint *)((longlong)pvVar1 + 0x60) | 4;
    }
    *(undefined8 *)((longlong)pvVar1 + 0x80) = *(undefined8 *)(param_2 + 0x80);
    *(longlong *)((longlong)pvVar1 + 0x88) = param_3;
    *(int *)((longlong)pvVar1 + 0x90) = param_4;
    *(byte *)((longlong)pvVar1 + 0x82) =
         *(byte *)((longlong)pvVar1 + 0x82) | *(byte *)(param_2 + 0x82) & 0x10;
    NvRaidPacketScatterGatherGroupAllocBuildPartialGroup
              (param_2,(longlong)pvVar1,(param_3 - *(longlong *)(param_2 + 0x88)) * 0x200,
               param_4 << 9);
  }
  return pvVar1;
}



===== FUN_0001af24 @ 0001af24 =====

undefined8
FUN_0001af24(longlong param_1,longlong param_2,undefined8 param_3,longlong param_4,int param_5,
            int param_6)

{
  undefined8 *puVar1;
  
  if (param_5 == *(int *)(param_2 + 0x90)) {
    if (param_6 == 0) {
      *(uint *)(param_2 + 0x60) = *(uint *)(param_2 + 0x60) | 4;
    }
    puVar1 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
    if (puVar1 == (undefined8 *)0x0) {
      return 0xc000009a;
    }
    puVar1[8] = param_1;
    *(undefined1 *)(puVar1 + 9) = *(undefined1 *)(param_1 + 8);
    puVar1[0x14] = NvRaidStateSubRequestsDone;
    *(uint *)(puVar1 + 0xc) = *(uint *)(puVar1 + 0xc) | *(uint *)(param_2 + 0x60) & 4;
    *(undefined2 *)(puVar1 + 0x10) = 0x9ff;
    *(undefined1 *)((longlong)puVar1 + 0x82) = 0;
    *puVar1 = 0;
    puVar1[1] = *(undefined8 *)(param_2 + 0x28);
    **(undefined8 **)(param_2 + 0x28) = puVar1;
    *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
    *(undefined8 **)(param_2 + 0x28) = puVar1;
    puVar1[0xd] = param_2;
    puVar1[0xe] = *(undefined8 *)(param_2 + 0x40);
  }
  else {
    puVar1 = FUN_0001ae5c(param_1,param_2,param_4,param_5,param_6);
    *puVar1 = 0;
    puVar1[1] = *(undefined8 *)(param_2 + 0x28);
    **(undefined8 **)(param_2 + 0x28) = puVar1;
    *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
    *(undefined8 **)(param_2 + 0x28) = puVar1;
    puVar1[0xd] = param_2;
    puVar1[0xe] = *(undefined8 *)(param_2 + 0x40);
  }
  return 0;
}



===== FUN_0001b004 @ 0001b004 =====

undefined8 FUN_0001b004(longlong param_1,longlong param_2)

{
  uint *puVar1;
  byte bVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong lVar10;
  byte bVar11;
  ulonglong uVar12;
  char cVar13;
  uint uVar14;
  byte bVar15;
  ulonglong uVar16;
  uint uVar17;
  ulonglong uVar18;
  byte bVar19;
  bool bVar20;
  
  lVar10 = *(longlong *)(param_1 + 0x58);
  NvRaidResNrpFreePacketResources(*(longlong *)(param_1 + 0x18),param_2);
  lVar3 = *(longlong *)(param_2 + 0x68);
  *(undefined1 *)(param_2 + 0x55) = 0;
  *(undefined4 *)(param_2 + 0x50) = 0;
  puVar6 = NvRaidResNrpAllocate(*(longlong *)(param_1 + 0x18));
  if (puVar6 == (undefined8 *)0x0) {
    uVar7 = 0xc000009a;
  }
  else {
    *puVar6 = 0;
    puVar6[1] = *(undefined8 *)(param_2 + 0x28);
    **(undefined8 **)(param_2 + 0x28) = puVar6;
    *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
    *(undefined8 **)(param_2 + 0x28) = puVar6;
    puVar6[0xd] = param_2;
    puVar6[0xe] = *(undefined8 *)(param_2 + 0x40);
    lVar4 = *(longlong *)(param_1 + 0x58);
    puVar1 = (uint *)(param_2 + 0x60);
    *puVar1 = *puVar1 & 4;
    bVar20 = *puVar1 != 0;
    if (bVar20) {
      bVar2 = *(byte *)(lVar4 + 0x17);
      uVar14 = *(uint *)(lVar4 + 0x38);
    }
    else {
      bVar2 = *(byte *)(lVar4 + 0x15);
      uVar14 = *(uint *)(lVar4 + 0x18);
    }
    if ((uVar14 & 0xffffffef) != 0x85) {
      *(byte *)(param_2 + 0x82) = *(byte *)(param_2 + 0x82) | 0x20;
    }
    if (uVar14 == 0x95) {
      *(byte *)(param_2 + 0x82) = *(byte *)(param_2 + 0x82) | 8;
    }
    if (((*(byte *)(lVar3 + 0x82) & 1) != 0) || (*(longlong *)(lVar3 + 0xa8) == 0)) {
      *(byte *)(param_2 + 0x82) = *(byte *)(param_2 + 0x82) | 2;
    }
    uVar14 = *(uint *)(lVar4 + 0x1c);
    bVar11 = (byte)*(undefined4 *)(lVar4 + 0x24);
    uVar16 = *(ulonglong *)(lVar3 + 0x88) >> (bVar11 & 0x3f);
    uVar18 = (ulonglong)bVar2;
    uVar8 = uVar16 / uVar18;
    uVar5 = *(uint *)(lVar3 + 0x88) & *(uint *)(lVar4 + 0x28);
    if ((*(int *)(lVar3 + 0x90) == 0) && ((*(byte *)(lVar3 + 0x82) & 4) != 0)) {
      if (bVar20) {
        uVar9 = (*(ulonglong *)(lVar10 + 0x50) >> (bVar11 & 0x3f)) - 1;
      }
      else {
        uVar9 = *(ulonglong *)(param_1 + 0x20);
      }
      uVar17 = uVar14;
    }
    else {
      uVar17 = *(int *)(lVar3 + 0x90) + uVar5;
      uVar9 = (((uVar14 - 1) + uVar17 >> (bVar11 & 0x1f)) - 1) + uVar16;
      uVar17 = uVar17 & *(uint *)(lVar4 + 0x28);
      if (uVar17 == 0) {
        uVar17 = uVar14;
      }
    }
    bVar19 = 0xff;
    if ((*(uint *)(param_1 + 4) & 4) != 0) {
      bVar15 = 0;
      if (bVar2 != 0xffffffff) {
        uVar12 = 0;
        do {
          lVar10 = 0;
          if ((param_1 != -0x78) && ((uint)uVar12 < *(uint *)(param_1 + 0x7c))) {
            lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x80) + uVar12 * 8);
          }
          if (((lVar10 == 0) || ((*(uint *)(lVar10 + 4) & 1) != 0)) ||
             ((bVar20 && ((*(uint *)(lVar10 + 4) >> 8 & 1) != 0)))) {
            lVar10 = 0;
          }
          if (lVar10 == 0) {
            bVar19 = bVar15;
            break;
          }
          bVar15 = bVar15 + 1;
          uVar12 = (ulonglong)bVar15;
        } while ((uint)bVar15 < bVar2 + 1);
      }
    }
    *(undefined1 *)(param_2 + 0x8e) = 0;
    *(char *)(param_2 + 0x83) = (char)(uVar16 % uVar18);
    *(char *)(param_2 + 0x84) = (char)(uVar9 % uVar18);
    *(short *)(param_2 + 0x78) = (short)uVar17;
    *(short *)(param_2 + 0x8c) = (short)uVar5;
    *(byte *)(param_2 + 0x8f) = bVar2;
    *(byte *)(param_2 + 0x85) = bVar19;
    cVar13 = (char)(uVar8 % (ulonglong)(longlong)(int)(bVar2 + 1));
    *(char *)(param_2 + 0x86) = cVar13;
    lVar10 = *(longlong *)(lVar3 + 0xa8);
    *(undefined2 *)(param_2 + 0x88) = 0;
    uVar16 = uVar9 / uVar18;
    if (lVar10 == 0) {
      uVar16 = uVar8;
    }
    *(char *)(param_2 + 0x87) = (cVar13 - (char)uVar8) + '\x01' + (char)uVar16;
    NvRaidScsiSetupReadWrite
              ((longlong)puVar6,0,0,NvRaidStateSubRequestsDone,*(byte *)(lVar3 + 0x81),
               uVar8 << (bVar11 & 0x3f),uVar14);
    *(byte *)((longlong)puVar6 + 0x82) =
         *(byte *)((longlong)puVar6 + 0x82) | *(byte *)(lVar3 + 0x82) & 0x10;
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
    uVar7 = 0;
  }
  return uVar7;
}



===== FUN_0001b2c0 @ 0001b2c0 =====

undefined4 FUN_0001b2c0(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  byte bVar2;
  uint uVar3;
  longlong lVar4;
  short sVar5;
  undefined4 uVar6;
  
  if (*(int *)(param_2 + 0x50) != 0) {
    uVar6 = NvRaidStateSubRequestsFail(param_1,param_2);
    return uVar6;
  }
  if (*(char *)(param_2 + 0x8e) == '\b') {
    lVar4 = *(longlong *)(param_1 + 0x58);
    bVar2 = *(byte *)(param_2 + 0x8f);
    uVar3 = *(uint *)(lVar4 + 0x1c);
    *(char *)(param_2 + 0x86) = *(char *)(param_2 + 0x86) + '\x01';
    plVar1 = (longlong *)(*(longlong *)(param_2 + 0x20) + 0x88);
    *plVar1 = *plVar1 + (ulonglong)uVar3;
    if (*(short *)(param_2 + 0x8a) == 0) {
      sVar5 = ((ushort)bVar2 - (ushort)*(byte *)(param_2 + 0x83) <<
              ((byte)*(undefined4 *)(lVar4 + 0x24) & 0x1f)) - *(short *)(param_2 + 0x8c);
    }
    else {
      sVar5 = (ushort)bVar2 * (short)uVar3;
    }
    *(short *)(param_2 + 0x8a) = *(short *)(param_2 + 0x8a) + sVar5;
  }
  if (*(byte *)(param_2 + 0x86) < *(byte *)(param_2 + 0x87)) {
    *(undefined1 *)(param_2 + 0x8e) = 0;
    *(undefined2 *)(param_2 + 0x88) = 0;
    *(undefined ***)(param_2 + 0x58) = &PTR_FUN_00027d48;
    *(undefined1 *)(param_2 + 0x56) = 0;
  }
  else {
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
  }
  return 0;
}



===== FUN_0001b388 @ 0001b388 =====

undefined8 FUN_0001b388(ulonglong param_1,longlong param_2)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  byte bVar8;
  undefined8 uVar9;
  longlong lVar10;
  byte bVar11;
  uint uVar12;
  byte bVar13;
  byte bVar14;
  int iVar15;
  uint uVar16;
  ulonglong uVar17;
  longlong lVar18;
  byte bVar19;
  byte bVar20;
  ulonglong uVar21;
  byte bVar22;
  ulonglong uVar23;
  byte local_res8;
  byte bStackX_9;
  byte local_res10;
  byte local_res18;
  byte local_res20;
  byte local_98;
  byte local_97;
  uint local_94;
  ushort local_88;
  uint local_84;
  uint local_80;
  ulonglong local_78;
  longlong local_68;
  
  local_88 = *(ushort *)(param_2 + 0x78);
  plVar4 = *(longlong **)(param_2 + 0x20);
  local_res20 = *(byte *)(param_2 + 0x83);
  local_res18 = *(byte *)(param_2 + 0x84);
  bVar14 = *(byte *)(param_2 + 0x8e);
  bVar19 = *(byte *)(param_2 + 0x85);
  uVar17 = (ulonglong)bVar19;
  lVar5 = *(longlong *)(param_2 + 0x68);
  bVar1 = *(byte *)(param_2 + 0x8f);
  bVar22 = *(byte *)(param_2 + 0x86);
  lVar6 = *(longlong *)(param_1 + 0x58);
  local_80 = (uint)*(ushort *)(param_2 + 0x8c);
  uVar3 = *(uint *)(lVar6 + 0x1c);
  bVar13 = *(byte *)(param_2 + 0x82) & 8;
  bVar20 = bVar1;
  if ((*(byte *)(param_2 + 0x82) & 0x20) == 0) {
    bVar20 = bVar1 - (char)((ulonglong)bVar22 % (ulonglong)(longlong)(int)(bVar1 + 1));
  }
  lVar18 = 0;
  if ((uint)bVar19 < bVar1 + 1) {
    if (bVar13 == 0) {
      bVar8 = bVar19;
      if (bVar20 < bVar19) {
        bVar8 = bVar19 - 1;
      }
      if (bVar19 == bVar20) {
        bVar8 = bVar1;
      }
      uVar17 = (ulonglong)bVar8;
    }
    else {
      uVar17 = (ulonglong)((uint)bVar22 + (uint)bVar19) % (ulonglong)(longlong)(int)(bVar1 + 1);
    }
  }
  if (*(short *)(param_2 + 0x8a) != 0) {
    local_res20 = 0;
    local_80 = 0;
  }
  uVar7 = (uint)bVar22;
  if ((int)uVar7 < (int)(*(byte *)(param_2 + 0x87) - 1)) {
    local_88 = (ushort)uVar3;
    local_res18 = bVar1 - 1;
  }
  local_res8 = (byte)param_1;
  if (bVar14 == 0) {
    bVar19 = bVar14;
  }
  else {
    bVar19 = 7;
    local_res8 = bVar14;
  }
  if (bVar19 == 8) {
LAB_0001bd38:
    *(undefined1 *)(param_2 + 0x8e) = 8;
    *(undefined ***)(param_2 + 0x58) = &PTR_FUN_00027c38;
    *(undefined1 *)(param_2 + 0x56) = 1;
    return 0;
  }
  bStackX_9 = (byte)(param_1 >> 8);
  local_94 = (uint)param_1 & 0xff;
  uVar23 = param_1 & 0xff;
  local_res10 = bStackX_9;
LAB_0001b529:
  uVar21 = local_78;
LAB_0001b52e:
  bVar22 = (byte)uVar17;
  bVar14 = (byte)uVar23;
  if (bVar19 < 8) {
    if (bVar19 == 7) {
      if (bVar13 == 0) {
        bVar14 = *(byte *)(plVar4 + 9);
        if (bVar14 == bVar20) {
          uVar23 = (ulonglong)bVar1;
        }
        else {
          if (bVar20 < bVar14) {
            bVar14 = bVar14 - 1;
          }
          uVar23 = (ulonglong)bVar14;
        }
      }
      else {
        uVar23 = (ulonglong)((uint)*(byte *)(plVar4 + 9) + (uint)*(byte *)(param_2 + 0x86)) %
                 (ulonglong)(longlong)(int)(bVar1 + 1);
      }
      if (local_res8 != 0x85) {
        bVar19 = local_res8;
        if ((byte)uVar23 == bVar1) {
          if (bVar22 < bVar1) {
            uVar23 = uVar17 & 0xff;
          }
        }
        goto LAB_0001b69e;
      }
LAB_0001b9c7:
      local_res8 = 0x85;
LAB_0001b610:
      local_res10 = (byte)uVar23;
      goto LAB_0001b613;
    }
    if (bVar19 == 0) {
      *(byte *)(param_2 + 0x82) = *(byte *)(param_2 + 0x82) & 0x2a;
      if (bVar22 == bVar1) {
        *(byte *)(param_2 + 0x82) = *(byte *)(param_2 + 0x82) | 0x10;
      }
      if ((local_res20 <= bVar22) && (bVar22 <= local_res18)) {
        *(byte *)(param_2 + 0x82) = *(byte *)(param_2 + 0x82) | 5;
      }
      uVar23 = 0;
      bVar19 = 1;
      if ((*(byte *)(param_2 + 0x82) & 0x12) != 0) goto LAB_0001b52e;
    }
    else {
      if (bVar19 == 1) {
        if ((bVar14 < local_res20) || (local_res18 < bVar14)) {
LAB_0001b5d1:
          bVar19 = 2;
        }
        else {
          bVar19 = 5;
        }
        goto LAB_0001b52e;
      }
      if (bVar19 != 2) {
        if (bVar19 == 3) {
          uVar2 = *(ushort *)(param_2 + 0x88);
          local_78 = 0;
          local_98 = local_res20;
          if (uVar2 < (ushort)local_80) {
            local_98 = local_res20 + 1;
          }
          local_97 = local_res18;
          if (local_88 <= uVar2) {
            local_97 = local_res18 - 1;
          }
          local_84 = uVar3;
          if (local_res8 == 0x86) {
            bVar19 = 0x82;
            if ((byte)(local_97 + 1) < (byte)(local_98 + 1)) goto LAB_0001b529;
            if ((bVar22 < local_98) || (local_97 < bVar22)) {
              if ((*(byte *)(param_2 + 0x82) & 2) != 0) goto LAB_0001b522;
              bVar14 = *(byte *)(param_2 + 0x82) & 0xfa;
              *(byte *)(param_2 + 0x82) = bVar14;
              if ((bVar1 + 1 <= ((uint)uVar17 & 0xff)) &&
                 (((*(uint *)(lVar6 + 0x40) & 4) == 0 ||
                  ((int)(uint)bVar1 <= (int)(((uint)local_97 - (uint)local_98) * 2 + 2))))) {
                *(byte *)(param_2 + 0x82) = bVar14 | 4;
              }
              bStackX_9 = 0xff;
            }
            else {
              *(byte *)(param_2 + 0x82) = *(byte *)(param_2 + 0x82) | 5;
              bStackX_9 = bVar22;
            }
          }
          if (bStackX_9 != 0xff) {
            if (bStackX_9 == local_res20) {
              local_78 = (ulonglong)local_80;
              local_84 = uVar3 - local_80;
            }
            if (bStackX_9 == local_res18) {
              local_84 = (uint)local_88 - (int)local_78;
            }
            if (bStackX_9 == local_res20) {
              iVar15 = 0;
            }
            else {
              iVar15 = ((uint)bStackX_9 - (uint)local_res20 <<
                       ((byte)*(undefined4 *)(lVar6 + 0x24) & 0x1f)) - local_80;
            }
            local_68 = (longlong)(int)((uint)*(ushort *)(param_2 + 0x8a) + iVar15);
          }
          if ((char)local_res8 < '\0') {
            local_68 = local_68 + (uVar2 - local_78);
            local_84 = 1;
            local_78 = (ulonglong)uVar2;
          }
          if (local_res8 != 0x86) {
            bVar19 = local_res8;
            if (local_res8 == 6) {
              NvRaidResNrpFreePacketResources(*(longlong *)(param_1 + 0x18),(longlong)plVar4);
              if (*(longlong *)(lVar5 + 0xa8) == 0) {
                local_84 = 0;
                local_res8 = 2;
              }
              else {
                NvRaidPacketScatterGatherGroupAllocBuildPartialGroup
                          (lVar5,(longlong)plVar4,local_68 << 9,local_84 << 9);
                local_res8 = 2;
              }
            }
            goto LAB_0001b69e;
          }
          bVar19 = 4;
          goto LAB_0001b522;
        }
        if (bVar19 == 4) {
          if (*plVar4 == 0) {
            *(longlong *)(param_2 + 0x28) = plVar4[1];
          }
          else {
            *(longlong *)(*plVar4 + 8) = plVar4[1];
          }
          *(longlong *)plVar4[1] = *plVar4;
          NvRaidResNrpFreePacketResources(*(longlong *)(param_1 + 0x18),(longlong)plVar4);
          plVar4[0x15] = 0;
          NvRaidResNrpFreePacketResources(*(longlong *)(param_1 + 0x18),param_2);
          *plVar4 = 0;
          plVar4[1] = *(longlong *)(param_2 + 0x28);
          uVar23 = 0;
          **(undefined8 **)(param_2 + 0x28) = plVar4;
          *(longlong **)(param_2 + 0x28) = plVar4;
          *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
          plVar4[0xd] = param_2;
          plVar4[0xe] = *(longlong *)(param_2 + 0x40);
          bVar19 = local_res8;
        }
        else {
          if (bVar19 == 5) {
            if (bVar14 == bVar22) {
              if ((*(byte *)(param_2 + 0x82) & 2) == 0) goto LAB_0001b5d1;
              local_94 = (uint)bVar20;
            }
            else if (bVar13 == 0) {
              local_94 = (uint)bVar14;
            }
            else {
              local_94 = (int)((((uint)uVar23 & 0xff) - uVar7 % (bVar1 + 1)) + 1 + (uint)bVar1) %
                         (int)(bVar1 + 1);
            }
            local_res8 = 6;
            goto LAB_0001b610;
          }
          if (bVar19 == 6) {
            if ((param_1 != 0xffffffffffffff88) && ((local_94 & 0xff) < *(uint *)(param_1 + 0x7c)))
            {
              lVar18 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)(byte)local_94 * 8);
            }
            if (local_res8 == 0x85) {
              bVar14 = 0x28;
            }
            else {
              bVar14 = *(byte *)(lVar5 + 0x80);
              if (bVar14 == 0xfe) {
                bVar14 = *(byte *)(lVar5 + 0x81);
              }
            }
            NvRaidScsiSetupReadWrite
                      ((longlong)plVar4,*(undefined1 *)(lVar18 + 8),lVar18,
                       NvRaidStateSubRequestsDone,bVar14,
                       uVar21 + (~(ulonglong)*(uint *)(lVar6 + 0x28) & plVar4[0x11]),local_84);
            *(byte *)((longlong)plVar4 + 0x82) =
                 *(byte *)((longlong)plVar4 + 0x82) | *(byte *)(param_2 + 0x82) & 0x10;
            *(byte *)(param_2 + 0x8e) = local_res8;
            *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
            *(undefined1 *)(param_2 + 0x55) = 1;
            NvRaidPacketSubmitSubRequests((longlong *)(param_2 + 0x20));
            return 0x103;
          }
        }
LAB_0001b69e:
        if (bVar19 == 8) goto LAB_0001bd38;
        uVar21 = local_78;
LAB_0001bba1:
        bStackX_9 = local_res10;
        goto LAB_0001b52e;
      }
      uVar23 = (ulonglong)(byte)(bVar14 + 1);
      if ((byte)(bVar14 + 1) < bVar1) {
        bVar19 = 1;
        goto LAB_0001b52e;
      }
      if ((*(longlong *)(lVar5 + 0xa8) == 0) || ((*(byte *)(param_2 + 0x82) & 3) != 3))
      goto LAB_0001bd38;
    }
LAB_0001b912:
    local_res8 = 0x86;
    local_res10 = bVar1;
LAB_0001b613:
    bVar19 = 3;
    bStackX_9 = local_res10;
    goto LAB_0001b52e;
  }
  if (bVar19 != 0x81) {
    if (bVar19 == 0x82) {
      *(short *)(param_2 + 0x88) = *(short *)(param_2 + 0x88) + 1;
      if (*(ushort *)(param_2 + 0x88) < uVar3) goto LAB_0001b912;
      if ((*(byte *)(param_2 + 0x82) & 2) != 0) goto LAB_0001bd38;
      local_res8 = 1;
      bVar19 = 4;
    }
    else if (bVar19 == 0x83) {
      bVar11 = 1;
      bVar8 = *(byte *)(param_2 + 0x82) >> 2 & 1;
      if ((bVar14 < local_98) || (local_97 < bVar14)) {
        bVar11 = 0;
      }
      bVar19 = 0x84;
      if ((bVar14 != bVar22) || (bStackX_9 = local_res10, (*(byte *)(param_2 + 0x82) & 2) == 0)) {
        if ((bVar11 != bVar8) || (bVar14 == bVar1)) {
          if (bVar13 != 0) {
            bVar14 = (byte)((int)((((uint)uVar23 & 0xff) - uVar7 % (bVar1 + 1)) + 1 + (uint)bVar1) %
                           (int)(bVar1 + 1));
          }
          local_94 = (uint)bVar14;
          local_res8 = 0x85;
          bVar19 = 6;
          goto LAB_0001bba1;
        }
        bStackX_9 = local_res10;
        if (bVar8 != 0) goto LAB_0001b9c7;
      }
    }
    else {
      if (bVar19 != 0x84) {
        if (bVar19 == 0x85) {
          bVar19 = *(byte *)(param_2 + 0x82);
          if ((bVar14 < local_98) || (local_97 < bVar14)) {
            bVar22 = 0;
          }
          else {
            bVar22 = 1;
            NvRaidPacketScatterGatherGroupXor
                      (*(longlong *)(param_2 + 0xa8),0,1,*(longlong *)(lVar5 + 0xa8),(int)local_68,1
                      );
          }
          if ((bVar22 != (bVar19 >> 2 & 1)) || (bVar14 == bVar1)) {
            NvRaidPacketScatterGatherGroupXor(*(longlong *)(param_2 + 0xa8),0,1,plVar4[0x15],0,1);
          }
          bVar19 = 0x84;
        }
        else {
          if (bVar19 != 0x86) goto LAB_0001b69e;
          uVar9 = NvRaidResBufferAllocateForNrp
                            (*(longlong *)(param_1 + 0x18),0x200,(longlong)plVar4);
          if ((int)uVar9 < 0) {
LAB_0001ba3a:
            DbgPrint("nvrParityStripeReadWriteArbitor: NvRaidResBufferAllocateForNrp failed\n");
            goto LAB_0001b69e;
          }
          if ((*(byte *)(param_2 + 0x82) & 2) == 0) {
            uVar9 = NvRaidResBufferAllocateForNrp(*(longlong *)(param_1 + 0x18),0x200,param_2);
            if ((int)uVar9 < 0) goto LAB_0001ba3a;
            lVar10 = *(longlong *)(param_2 + 0xa8);
            uVar16 = 0;
            uVar12 = 0;
            if (*(short *)(lVar10 + 6) == 0) {
              do {
                lVar10 = *(longlong *)(lVar10 + 8);
                uVar16 = uVar16 - uVar12;
                uVar12 = (uint)*(ushort *)(lVar10 + 6);
              } while (uVar12 <= uVar16);
            }
            memset(*(void **)(lVar10 + 0x18 + (ulonglong)uVar16 * 0x10),0,0x200);
          }
          else {
            NvRaidPacketScatterGatherGroupAllocBuildPartialGroup(lVar5,param_2,local_68 << 9,0x200);
          }
          bVar19 = 0x81;
        }
        goto LAB_0001b522;
      }
      uVar23 = (ulonglong)(byte)(bVar14 + 1);
      if ((uint)(byte)(bVar14 + 1) < (~(uint)(*(byte *)(param_2 + 0x82) >> 2) & 1) + (uint)bVar1) {
        bVar19 = 0x83;
        goto LAB_0001bba1;
      }
      bVar19 = 0x82;
      bStackX_9 = local_res10;
      if ((*(byte *)(param_2 + 0x82) & 2) == 0) goto code_r0x0001bbc0;
    }
    goto LAB_0001b52e;
  }
  uVar23 = 0;
  bVar19 = 0x83;
  goto LAB_0001b69e;
code_r0x0001bbc0:
  local_res8 = 0x82;
  bVar19 = 6;
  local_94 = (uint)bVar20;
  NvRaidResNrpFreePacketResources(*(longlong *)(param_1 + 0x18),(longlong)plVar4);
  plVar4[0x15] = *(longlong *)(param_2 + 0xa8);
LAB_0001b522:
  bStackX_9 = local_res10;
  goto LAB_0001b529;
}



===== FUN_0001bd94 @ 0001bd94 =====

undefined4 FUN_0001bd94(longlong param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (*(longlong *)(param_1 + 0x58) == 0) {
    uVar1 = 0xc000000d;
  }
  else {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x100;
    NvRaidDefaultUpdateArrayStatus(param_1,param_2);
    uVar1 = *(undefined4 *)(param_1 + 4);
  }
  return uVar1;
}



===== FUN_0001bdd4 @ 0001bdd4 =====

bool FUN_0001bdd4(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  
  lVar1 = RtlCompareMemory(*param_2,*(longlong *)(param_1 + 0x58) + 4,0x10);
  if (lVar1 == 0x10) {
    param_2[1] = param_1;
  }
  return lVar1 == 0x10;
}



===== NvRaidSectorRestoreArray @ 0001be1c =====

undefined8
NvRaidSectorRestoreArray(longlong param_1,longlong param_2,undefined8 *param_3,longlong *param_4)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined4 uVar4;
  uint uVar5;
  ulonglong uVar6;
  bool bVar7;
  longlong local_38 [2];
  
  NvRaidApiCreateVolume(param_1,local_38);
  puVar1 = NvRaidResArrayAllocate(param_1);
  if (puVar1 == (undefined8 *)0x0) {
    uVar2 = 0xc000009a;
  }
  else {
    *(uint *)(local_38[0] + 4) = *(uint *)(local_38[0] + 4) & 0xfffffff9 | 1;
    *(undefined4 *)(local_38[0] + 0x28) = *(undefined4 *)(param_3 + 3);
    *(longlong *)(local_38[0] + 0x60) = param_2 + 0x18;
    puVar1[0x11] = param_2;
    *(undefined8 *)(local_38[0] + 0x2c) = *param_3;
    *(undefined8 *)(local_38[0] + 0x34) = *(undefined8 *)((longlong)param_3 + 0x1c);
    *(undefined8 *)(local_38[0] + 0x3c) = *(undefined8 *)((longlong)param_3 + 0x24);
    *(undefined4 *)(local_38[0] + 0x44) = *(undefined4 *)((longlong)param_3 + 0x2c);
    *puVar1 = *(undefined8 *)((longlong)param_3 + 0x34);
    puVar1[1] = *(undefined8 *)((longlong)param_3 + 0x3c);
    puVar1[2] = *(undefined8 *)((longlong)param_3 + 0x44);
    puVar1[3] = *(undefined8 *)((longlong)param_3 + 0x4c);
    puVar1[4] = *(undefined8 *)((longlong)param_3 + 0x54);
    puVar1[5] = *(undefined8 *)((longlong)param_3 + 0x5c);
    puVar1[6] = *(undefined8 *)((longlong)param_3 + 100);
    puVar1[7] = *(undefined8 *)((longlong)param_3 + 0x6c);
    *(undefined4 *)(puVar1 + 8) = *(undefined4 *)((longlong)param_3 + 0x74);
    *(undefined8 **)(local_38[0] + 0x58) = puVar1;
    if ((*(short *)(param_3 + 0xf) == 200) &&
       (*(uint *)(puVar1 + 0x16) = *(uint *)(puVar1 + 0x16) | 1, *(short *)(param_3 + 0xf) == 200))
    {
      uVar2 = *(undefined8 *)((longlong)param_3 + 0x86);
      *(undefined8 *)(*(longlong *)(local_38[0] + 0x58) + 0x48) = uVar2;
      *(undefined8 *)(local_38[0] + 0x20) = uVar2;
    }
    else {
      *(ulonglong *)(local_38[0] + 0x20) = (ulonglong)*(uint *)((longlong)param_3 + 0x14);
      puVar1[9] = (ulonglong)*(uint *)((longlong)param_3 + 0x14);
    }
    lVar3 = NvRaidFindRaidLevelMethod(*(int *)(puVar1 + 7));
    puVar1[0x12] = lVar3;
    if (lVar3 == 0) {
      puVar1[0x12] = param_2;
      *(undefined4 *)(puVar1 + 7) = *(undefined4 *)(puVar1 + 3);
      *(undefined1 *)((longlong)puVar1 + 0x17) = *(undefined1 *)((longlong)puVar1 + 0x15);
    }
    if ((puVar1[0x12] != param_2) && (*(char *)((longlong)puVar1 + 0x14) == '\x04')) {
      *(undefined ***)(local_38[0] + 0x60) = &morphApi;
    }
    lVar3 = *(longlong *)(local_38[0] + 0x58);
    if (*(short *)(param_3 + 0xf) == 200) {
      uVar6 = *(ulonglong *)((longlong)param_3 + 0x8e);
      *(ulonglong *)(lVar3 + 0x50) = uVar6;
      uVar4 = (undefined4)uVar6;
      if (0xffffffff < uVar6) {
        uVar4 = 0;
      }
      *(undefined4 *)(lVar3 + 0x3c) = uVar4;
      bVar7 = *(longlong *)((longlong)param_3 + 0x8e) == 0;
    }
    else {
      uVar5 = *(uint *)((longlong)puVar1 + 0x3c);
      *(ulonglong *)(lVar3 + 0x50) = (ulonglong)uVar5;
      if (0xffffffff < (ulonglong)uVar5) {
        uVar5 = 0;
      }
      *(uint *)(lVar3 + 0x3c) = uVar5;
      bVar7 = *(int *)((longlong)puVar1 + 0x3c) == 0;
    }
    if (bVar7) {
      uVar6 = *(ulonglong *)(local_38[0] + 0x20);
      lVar3 = *(longlong *)(local_38[0] + 0x58);
      *(ulonglong *)(lVar3 + 0x50) = uVar6;
      uVar4 = (undefined4)uVar6;
      if (0xffffffff < uVar6) {
        uVar4 = 0;
      }
      *(undefined4 *)(lVar3 + 0x3c) = uVar4;
    }
    lVar3 = *(longlong *)(local_38[0] + 0x58);
    if (*(short *)(param_3 + 0xf) == 200) {
      uVar6 = *(ulonglong *)((longlong)param_3 + 0x96);
    }
    else {
      uVar6 = (ulonglong)*(uint *)((longlong)puVar1 + 0x34);
    }
    *(ulonglong *)(lVar3 + 0x58) = uVar6;
    *param_4 = local_38[0];
    uVar4 = (undefined4)uVar6;
    if (0xffffffff < uVar6) {
      uVar4 = 0;
    }
    *(undefined4 *)(lVar3 + 0x34) = uVar4;
    if ((*(uint *)(local_38[0] + 4) & 0x10) != 0) {
      NvRaidVolumeAddVolumeToArray(param_1,local_38[0],0xff);
      if (*(longlong *)(local_38[0] + 0x58) == 0) {
        NvRaidVolumeProbeArrayInfo(local_38[0]);
      }
    }
    NvRaidApiFireEvent(*(longlong *)(local_38[0] + 0x18),3,local_38[0]);
    uVar2 = 0;
  }
  return uVar2;
}



===== NvRaidSectorInitializeSector @ 0001c04c =====

undefined8 NvRaidSectorInitializeSector(longlong param_1,longlong param_2,int *param_3)

{
  uint uVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  int *piVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  
  lVar6 = *(longlong *)(param_1 + 0x58);
  uVar9 = 0;
  if (lVar6 == 0) {
    uVar9 = 0xc000000d;
  }
  else {
    *(undefined2 *)(param_3 + 4) = 100;
    if (*(ulonglong *)(param_1 + 0x20) < 0x100000000) {
      param_3[5] = *(int *)(param_1 + 0x20);
    }
    else {
      param_3[5] = 0;
      *(undefined2 *)(param_3 + 4) = 200;
    }
    if (*(ulonglong *)(lVar6 + 0x58) < 0x100000000) {
      *(undefined4 *)(lVar6 + 0x34) = *(undefined4 *)(lVar6 + 0x58);
    }
    else {
      *(undefined4 *)(lVar6 + 0x34) = 0;
    }
    if (*(ulonglong *)(lVar6 + 0x50) < 0x100000000) {
      *(undefined4 *)(lVar6 + 0x3c) = *(undefined4 *)(lVar6 + 0x50);
    }
    else {
      *(undefined4 *)(lVar6 + 0x3c) = 0;
    }
    param_3[6] = *(int *)(param_1 + 0x28);
    *(undefined8 *)param_3 = *(undefined8 *)(param_1 + 0x2c);
    *(undefined8 *)(param_3 + 7) = *(undefined8 *)(param_1 + 0x34);
    *(undefined8 *)(param_3 + 9) = *(undefined8 *)(param_1 + 0x3c);
    param_3[0xb] = *(int *)(param_1 + 0x44);
    puVar2 = *(undefined8 **)(param_1 + 0x58);
    *(undefined8 *)(param_3 + 0xd) = *puVar2;
    *(undefined8 *)(param_3 + 0xf) = puVar2[1];
    *(undefined8 *)(param_3 + 0x11) = puVar2[2];
    *(undefined8 *)(param_3 + 0x13) = puVar2[3];
    *(undefined8 *)(param_3 + 0x15) = puVar2[4];
    *(undefined8 *)(param_3 + 0x17) = puVar2[5];
    *(undefined8 *)(param_3 + 0x19) = puVar2[6];
    *(undefined8 *)(param_3 + 0x1b) = puVar2[7];
    param_3[0x1d] = *(int *)(puVar2 + 8);
    *(undefined1 *)((longlong)param_3 + 0x12) = *(undefined1 *)(param_2 + 8);
    uVar1 = *(uint *)(param_2 + 4);
    lVar6 = 0x1e;
    param_3[2] = 0x1e;
    param_3[3] = 0;
    param_3[0xc] = uVar1 & 0x100;
    iVar5 = 0;
    piVar7 = param_3;
    do {
      iVar5 = iVar5 + *piVar7;
      piVar7 = piVar7 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    param_3[3] = -iVar5;
    lVar6 = *(longlong *)(param_1 + 0x58);
    if (lVar6 == 0) {
      uVar9 = 0xc000000d;
    }
    else {
      piVar7 = param_3 + 0x1e;
      *(undefined8 *)((longlong)param_3 + 0x86) = *(undefined8 *)(lVar6 + 0x48);
      *(undefined8 *)((longlong)param_3 + 0x96) = *(undefined8 *)(lVar6 + 0x58);
      uVar3 = *(undefined8 *)(lVar6 + 0x50);
      *(undefined4 *)((longlong)param_3 + 0x7a) = 0x26;
      *(undefined8 *)((longlong)param_3 + 0x8e) = uVar3;
      *(uint *)((longlong)param_3 + 0x7e) = 0;
      *(undefined2 *)piVar7 = 200;
      *(undefined4 *)((longlong)param_3 + 0x82) = 0x3436564e;
      cVar4 = '\0';
      if (*(uint *)((longlong)param_3 + 0x7a) != 0) {
        uVar8 = (ulonglong)*(uint *)((longlong)param_3 + 0x7a);
        do {
          iVar5 = *piVar7;
          piVar7 = (int *)((longlong)piVar7 + 1);
          cVar4 = cVar4 + (char)iVar5;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      *(uint *)((longlong)param_3 + 0x7e) = (uint)(byte)-cVar4;
    }
  }
  return uVar9;
}



===== nvrStopDevice @ 0001c1d4 =====

undefined8 nvrStopDevice(longlong param_1,char param_2)

{
  int *piVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  if ((*(byte *)(*(longlong *)(param_1 + 0x40) + 0x68) & 1) == 0) {
    if (param_2 == '\x04') {
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
      uVar3 = PoRegisterDeviceForIdleDetection(param_1,0,0,4);
      *(undefined8 *)(lVar2 + 0x10) = uVar3;
      if (*(char *)(*(longlong *)(param_1 + 0x40) + 0x6a) == '\x05') {
        return 0;
      }
    }
    else if (param_2 != '\x05') {
      if (param_2 != '\x06') {
        return 0;
      }
      nvrPdoUnlockQueue(param_1);
      lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
      if (-1 < *(char *)(lVar2 + 0x1c)) {
        return 0;
      }
      if (*(int *)(lVar2 + 0x9c) == 0) {
        return 0;
      }
      IoStartTimer(param_1);
      return 0;
    }
    LOCK();
    piVar1 = (int *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60) + 0x18);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
    if ((*(char *)(lVar2 + 0x1c) < '\0') && (*(int *)(lVar2 + 0x9c) != 0)) {
      IoStopTimer(param_1);
    }
  }
  return 0;
}



===== nvrRemoveDevice @ 0001c29c =====

undefined8 nvrRemoveDevice(longlong param_1,char param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong lVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (param_2 == '\x02') {
    if ((*(byte *)(lVar1 + 0x68) & 1) == 0) {
      plVar2 = *(longlong **)(lVar1 + 0x60);
      lVar3 = *plVar2;
      if (lVar3 != 0) {
        if (param_1 == *(longlong *)(lVar3 + 0x10)) {
          *(undefined8 *)(lVar3 + 0x10) = 0;
        }
        *plVar2 = 0;
      }
    }
    else if ((*(byte *)(*(longlong *)(lVar1 + 0x60) + 0xe0) & 1) == 0) {
      nvrProcessRemovalForRaidDiskFdo(param_1);
    }
    ClassDeleteSrbLookasideList(lVar1);
  }
  return 0;
}



===== nvrPdoSendIrpSynch_Callback @ 0001c30c =====

undefined1 nvrPdoSendIrpSynch_Callback(longlong param_1,longlong *param_2)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  
  if (*(longlong *)(param_1 + 0x58) == 0) {
    uVar3 = *(undefined8 *)(param_1 + 0x10);
    if ((char)param_2[4] != '\0') {
      uVar3 = IoGetAttachedDeviceReference(uVar3);
    }
    if (param_1 == param_2[2]) {
      return 1;
    }
    puVar1 = *(undefined8 **)(*param_2 + 0xb8);
    puVar1[-9] = *puVar1;
    puVar1[-8] = puVar1[1];
    puVar1[-7] = puVar1[2];
    puVar1[-6] = puVar1[3];
    puVar1[-5] = puVar1[4];
    puVar1[-4] = puVar1[5];
    puVar1[-3] = puVar1[6];
    *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
    ClassSendIrpSynchronous(uVar3,*param_2);
    if ((char)param_2[4] != '\0') {
      ObfDereferenceObject(uVar3);
    }
    if ((*(int *)(*param_2 + 0x30) < 0) && ((code *)param_2[1] != (code *)0x0)) {
      uVar2 = (*(code *)param_2[1])(param_1,param_2);
      return uVar2;
    }
  }
  return 0;
}



===== nvrShutdownFlush @ 0001c3e8 =====

undefined4 nvrShutdownFlush(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  char *pcVar6;
  code *pcVar7;
  undefined8 uVar8;
  undefined2 *_Dst;
  undefined4 uVar9;
  longlong local_48;
  undefined1 *local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_28;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(lVar3 + 0x18);
  if ((*(byte *)(lVar3 + 0x68) & 1) == 0) {
    plVar5 = *(longlong **)(lVar3 + 0x60);
    ClassReleaseRemoveLock();
    if (*plVar5 == 0) {
      *(undefined4 *)(param_2 + 0x30) = 0xc00000c0;
    }
    else {
      if ((**(char **)(param_2 + 0xb8) == '\x10') &&
         (uVar8 = nvrOsShutdownPdo(param_1,param_2), (int)uVar8 == 0x103)) {
        return 0x103;
      }
      local_38 = 0;
      local_30 = 0;
      local_28 = 0;
      local_40 = &LAB_0001c3e4;
      local_48 = param_2;
      NvRaidVolumeSendCommandToVolumes(*plVar5,nvrPdoSendIrpSynch_Callback,&local_48);
    }
    uVar9 = *(undefined4 *)(param_2 + 0x30);
  }
  else {
    if ((*(byte *)(*(longlong *)(lVar4 + 0x60) + 0xe0) & 1) == 0) {
      _Dst = (undefined2 *)ExAllocatePoolWithTag(0,0x58,0x624e7652);
      if (_Dst != (undefined2 *)0x0) {
        memset(_Dst,0,0x58);
        *_Dst = 0x58;
        iVar2 = *(int *)(lVar4 + 0x248);
        _Dst[4] = 0x20ff;
        *(int *)(_Dst + 10) = iVar2 << 2;
        *(undefined4 *)(_Dst + 6) = *(undefined4 *)(lVar4 + 0x250);
        if ((*(byte *)(lVar4 + 0x280) & 1) != 0) {
          *(undefined1 *)(_Dst + 1) = 0;
          *(undefined1 *)(_Dst + 5) = 10;
          *(undefined1 *)(_Dst + 0x24) = 0x35;
          ClassSendSrbSynchronous(param_1,_Dst,0,0,1);
        }
        pcVar6 = *(char **)(param_2 + 0xb8);
        if (((*(uint *)(param_1 + 0x34) & 1) != 0) && (*pcVar6 == '\x10')) {
          *(undefined1 *)(_Dst + 5) = 6;
          *(byte *)(_Dst + 0x26) = *(byte *)(_Dst + 0x26) & 0xfe;
          *(undefined1 *)(_Dst + 0x24) = 0x1e;
          *(undefined4 *)(_Dst + 10) = *(undefined4 *)(lVar4 + 0x248);
          ClassSendSrbSynchronous(param_1,_Dst,0,0,1);
        }
        *(undefined1 *)(_Dst + 5) = 0;
        *(char *)(_Dst + 1) = (*pcVar6 != '\x10') + '\a';
        pcVar7 = ClassIoComplete_exref;
        pcVar6[0x20] = '\0';
        pcVar6[0x21] = '\0';
        pcVar6[0x22] = '\0';
        pcVar6[0x23] = '\0';
        pcVar6[0x24] = '\0';
        pcVar6[0x25] = '\0';
        pcVar6[0x26] = '\0';
        pcVar6[0x27] = '\0';
        lVar4 = *(longlong *)(param_2 + 0xb8);
        *(code **)(lVar4 + -0x10) = pcVar7;
        *(undefined2 **)(lVar4 + -8) = _Dst;
        *(undefined1 *)(lVar4 + -0x45) = 0xe0;
        lVar4 = *(longlong *)(param_2 + 0xb8);
        *(undefined1 *)(lVar4 + -0x48) = 0xf;
        *(undefined2 **)(lVar4 + -0x40) = _Dst;
        *(longlong *)(_Dst + 0x18) = param_2;
        pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
        *pbVar1 = *pbVar1 | 1;
        IofCallDriver(*(undefined8 *)(lVar3 + 0x10),param_2);
        return 0x103;
      }
      uVar9 = 0xc000009a;
      *(undefined4 *)(param_2 + 0x30) = 0xc000009a;
    }
    else {
      uVar9 = 0;
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
    ClassReleaseRemoveLock(param_1,param_2);
  }
  ClassCompleteRequest(param_1,param_2,0);
  return uVar9;
}



===== nvrResetBus @ 0001c638 =====

void nvrResetBus(longlong param_1)

{
  longlong *_Dst;
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if ((*(byte *)(*(longlong *)(lVar1 + 0x60) + 0xe0) & 1) == 0) {
    plVar3 = (longlong *)ExAllocatePoolWithTag(0,0xc0,0x664e7652);
    if (plVar3 != (longlong *)0x0) {
      _Dst = plVar3 + 1;
      *plVar3 = param_1;
      memset(_Dst,0,0x58);
      *(undefined2 *)_Dst = 0x58;
      *(undefined1 *)((longlong)plVar3 + 10) = 0x12;
      lVar4 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c),0);
      if (lVar4 == 0) {
        ExFreePoolWithTag(plVar3,0);
      }
      else {
        ClassAcquireRemoveLockEx
                  (param_1,lVar4,"drivers\\oem\\src\\storage\\nvraid\\nvraid\\nvraid.c",0x339);
        lVar2 = *(longlong *)(lVar4 + 0xb8);
        *(code **)(lVar2 + -0x10) = ClassAsynchronousCompletion_exref;
        *(longlong **)(lVar2 + -8) = plVar3;
        *(undefined1 *)(lVar2 + -0x45) = 0xe0;
        lVar2 = *(longlong *)(lVar4 + 0xb8);
        *(undefined1 *)(lVar2 + -0x48) = 0xf;
        plVar3[7] = lVar4;
        *(longlong **)(lVar2 + -0x40) = _Dst;
        IofCallDriver(*(undefined8 *)(lVar1 + 0x10),lVar4);
      }
    }
  }
  return;
}



===== _guard_check_icall @ 0001c738 =====

void _guard_check_icall(void)

{
  return;
}



===== nvrPdoSystemPowerComplete @ 0001c73c =====

void nvrPdoSystemPowerComplete
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4,
               undefined4 *param_5)

{
  byte *pbVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (param_4 != 0) {
    lVar2 = *(longlong *)(param_4 + 0xb8);
    if ((*(char *)(lVar2 + 1) == '\x02') && (*(int *)(lVar2 + 0x18) == 1)) {
      pbVar1 = (byte *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60) + 0x1c);
      *pbVar1 = *pbVar1 & 0xbf;
    }
    PoStartNextPowerIrp(param_4);
    uVar3 = param_5[1];
    uVar4 = param_5[2];
    uVar5 = param_5[3];
    *(undefined4 *)(param_4 + 0x30) = *param_5;
    *(undefined4 *)(param_4 + 0x34) = uVar3;
    *(undefined4 *)(param_4 + 0x38) = uVar4;
    *(undefined4 *)(param_4 + 0x3c) = uVar5;
    ClassCompleteRequest(*(undefined8 *)(lVar2 + 0x28),param_4,0);
  }
  return;
}



===== nvrInitializePendingQueue @ 0001c7a0 =====

void nvrInitializePendingQueue(longlong param_1)

{
  *(longlong *)(param_1 + 8) = param_1;
  *(longlong *)param_1 = param_1;
  KeInitializeSpinLock(param_1 + 0x10);
  *(undefined1 *)(param_1 + 0x18) = 1;
  return;
}



===== FUN_0001c7c4 @ 0001c7c4 =====

void FUN_0001c7c4(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  code *pcVar2;
  undefined1 uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong *plVar6;
  
  lVar5 = *(longlong *)(param_2 + 0x78);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  if (*(char *)(lVar5 + 0x18) != '\0') {
    uVar3 = KeAcquireSpinLockRaiseToDpc(lVar5 + 0x10);
    plVar6 = (longlong *)(param_2 + 0xa8);
    lVar4 = *plVar6;
    plVar1 = *(longlong **)(param_2 + 0xb0);
    if ((*(longlong **)(lVar4 + 8) != plVar6) || ((longlong *)*plVar1 != plVar6)) {
      lVar5 = 3;
      pcVar2 = (code *)swi(0x29);
      (*pcVar2)();
      if ((char)plVar6[3] != '\0') {
        while (lVar4 = ExInterlockedRemoveHeadList(plVar6,plVar6 + 2), lVar4 != 0) {
          LOCK();
          *(undefined8 *)(lVar4 + -0x40) = 0;
          UNLOCK();
          if (*(char *)(lVar4 + -100) == '\0') {
            nvrScsiPortDispatch(lVar5,lVar4 + -0xa8);
          }
          else {
            *(undefined8 *)(lVar4 + -0x70) = 0;
            *(undefined4 *)(lVar4 + -0x78) = 0xc0000120;
          }
        }
      }
      return;
    }
    *plVar1 = lVar4;
    *(longlong **)(lVar4 + 8) = plVar1;
    KeReleaseSpinLock(lVar5 + 0x10,CONCAT71((int7)((ulonglong)plVar6 >> 8),uVar3));
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
                    /* WARNING: Could not recover jumptable at 0x0001c846. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ClassCompleteRequest(param_1,param_2,0);
  return;
}



===== nvrFlushPendingQueue @ 0001c854 =====

void nvrFlushPendingQueue(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(char *)(param_2 + 0x18) != '\0') {
    while (lVar1 = ExInterlockedRemoveHeadList(param_2,param_2 + 0x10), lVar1 != 0) {
      LOCK();
      *(undefined8 *)(lVar1 + -0x40) = 0;
      UNLOCK();
      if (*(char *)(lVar1 + -100) == '\0') {
        nvrScsiPortDispatch(param_1,lVar1 + -0xa8);
      }
      else {
        *(undefined8 *)(lVar1 + -0x70) = 0;
        *(undefined4 *)(lVar1 + -0x78) = 0xc0000120;
      }
    }
  }
  return;
}



===== nvrClassMarkChildMissing @ 0001c8c0 =====

undefined1 nvrClassMarkChildMissing(longlong param_1)

{
  undefined1 uVar1;
  longlong lVar2;
  longlong lVar3;
  
  uVar1 = *(undefined1 *)(param_1 + 0x201);
  *(undefined1 *)(param_1 + 0x200) = 1;
  lVar3 = *(longlong *)(param_1 + 0x18);
  if (*(longlong *)(*(longlong *)(param_1 + 0x18) + 0x80) != 0) {
    do {
      lVar2 = *(longlong *)(lVar3 + 0x80);
      if (lVar2 == param_1) break;
      lVar3 = lVar2;
    } while (lVar2 != 0);
    if (lVar3 != 0) {
      lVar2 = *(longlong *)(lVar3 + 0x80);
      *(undefined8 *)(lVar3 + 0x80) = *(undefined8 *)(lVar2 + 0x80);
      *(undefined8 *)(lVar2 + 0x80) = 0;
    }
  }
  if (*(char *)(param_1 + 0x201) == '\0') {
    ClassRemoveDevice(*(undefined8 *)(param_1 + 8),2);
  }
  return uVar1;
}



===== nvrClassSendSrbAsynchronous @ 0001c938 =====

undefined8
nvrClassSendSrbAsynchronous
          (longlong param_1,undefined2 *param_2,longlong param_3,longlong param_4,undefined4 param_5
          ,char param_6)

{
  byte *pbVar1;
  uint uVar2;
  longlong lVar3;
  ushort uVar4;
  longlong lVar5;
  char cVar6;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  uVar2 = *(uint *)(param_2 + 6);
  cVar6 = '\0';
  *param_2 = 0x58;
  *(undefined1 *)(param_2 + 1) = 0;
  *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(lVar3 + 0x240);
  *(undefined1 *)((longlong)param_2 + 0xb) = 0x12;
  *(longlong *)(param_2 + 0xc) = param_4;
  if (param_4 == 0) {
    if (*(char *)(param_2 + 0x24) == -2) {
      *(uint *)(param_2 + 6) = (-(uint)(param_6 != '\0') & 0x40) + 0x40;
    }
    else {
      *(undefined4 *)(param_2 + 6) = 0;
    }
  }
  else {
    if (*(longlong *)(param_3 + 8) == 0) {
      lVar5 = IoAllocateMdl(param_4,param_5,0,0,param_3);
      if (lVar5 == 0) {
        *(undefined4 *)(param_3 + 0x30) = 0xc000009a;
        if ((((*(uint *)(param_2 + 6) >> 0x15 & 1) != 0) &&
            ((*(uint *)(param_2 + 6) >> 10 & 1) != 0)) &&
           (*(longlong *)(param_2 + 0x10) != *(longlong *)(lVar3 + 0x240))) {
          ExFreePoolWithTag(*(longlong *)(param_2 + 0x10),0);
          *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(lVar3 + 0x240);
          if (*(longlong *)(lVar3 + 0x240) != 0) {
            cVar6 = '\x12';
            if (*(char *)(lVar3 + 0x225) != '\0') {
              cVar6 = *(char *)(lVar3 + 0x225);
            }
          }
          *(uint *)(param_2 + 6) = *(uint *)(param_2 + 6) & 0xfffffbff;
          *(char *)((longlong)param_2 + 0xb) = cVar6;
        }
        if ((*(byte *)(lVar3 + 0x68) & 4) == 0) {
          ExFreePoolWithTag(param_2,0);
        }
        else {
          *(int *)(lVar3 + 0x11c) = *(int *)(lVar3 + 0x11c) + 1;
          uVar4 = ExQueryDepthSList(lVar3 + 0x100);
          if (uVar4 < *(ushort *)(lVar3 + 0x110)) {
            ExpInterlockedPushEntrySList(lVar3 + 0x100,param_2);
          }
          else {
            *(int *)(lVar3 + 0x120) = *(int *)(lVar3 + 0x120) + 1;
            (**(code **)(lVar3 + 0x138))(param_2);
          }
        }
        ClassReleaseRemoveLock(param_1,param_3);
        ClassCompleteRequest(param_1,param_3,0);
        return 0xc000009a;
      }
      MmBuildMdlForNonPagedPool();
    }
    *(uint *)(param_2 + 6) = (-(uint)(param_6 != '\0') & 0x40) + 0x40;
  }
  *(undefined4 *)(param_2 + 8) = param_5;
  *(undefined2 *)((longlong)param_2 + 3) = 0;
  *(undefined8 *)(param_2 + 0x14) = 0;
  *(uint *)(param_2 + 6) = *(uint *)(param_2 + 6) | uVar2 & 0xf0880000 | 8;
  *(undefined8 *)(*(longlong *)(param_3 + 0xb8) + 0x20) = 4;
  lVar5 = *(longlong *)(param_3 + 0xb8);
  *(code **)(lVar5 + -0x10) = ClassIoComplete_exref;
  *(undefined2 **)(lVar5 + -8) = param_2;
  *(undefined1 *)(lVar5 + -0x45) = 0xe0;
  lVar5 = *(longlong *)(param_3 + 0xb8);
  *(undefined1 *)(lVar5 + -0x48) = 0xf;
  *(undefined2 **)(lVar5 + -0x40) = param_2;
  *(longlong *)(param_2 + 0x18) = param_3;
  pbVar1 = (byte *)(*(longlong *)(param_3 + 0xb8) + 3);
  *pbVar1 = *pbVar1 | 1;
  IofCallDriver(*(undefined8 *)(lVar3 + 0x10),param_3);
  return 0x103;
}



===== RtlStringCbPrintfA @ 0001cb58 =====

int RtlStringCbPrintfA(char *param_1,longlong param_2,char *param_3,undefined8 param_4)

{
  size_t _Count;
  int iVar1;
  int iVar2;
  undefined8 local_res20;
  
  iVar2 = 0;
  if (0x7ffffffe < param_2 - 1U) {
    iVar2 = -0x3ffffff3;
  }
  if (iVar2 < 0) {
    if (param_2 != 0) {
      *param_1 = '\0';
    }
  }
  else {
    _Count = param_2 - 1;
    iVar2 = 0;
    local_res20 = param_4;
    iVar1 = _vsnprintf(param_1,_Count,param_3,(va_list)&local_res20);
    if ((iVar1 < 0) || (_Count < (ulonglong)(longlong)iVar1)) {
      param_1[_Count] = '\0';
      iVar2 = -0x7ffffffb;
    }
    else if ((longlong)iVar1 == _Count) {
      param_1[_Count] = '\0';
    }
  }
  return iVar2;
}



===== nvrFdoProcessError @ 0001cbcc =====

void nvrFdoProcessError(longlong param_1,longlong param_2,int *param_3,undefined1 *param_4)

{
  int *piVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (((*(byte *)(*(longlong *)(lVar2 + 0x60) + 0xe0) & 1) == 0) &&
     (((*(uint *)(param_1 + 0x34) & 1) != 0 || (*(char *)(param_2 + 0x48) != '\x1e')))) {
    if ((*param_3 == -0x3fffffc4) && ((*(char *)(param_2 + 0x48) - 0x28U & 0xfd) == 0)) {
      *param_4 = 1;
    }
    else {
      if (((*(byte *)(param_2 + 3) & 0x3f) != 4) || (*(char *)(param_2 + 4) != '\b')) {
        *param_4 = 0;
        return;
      }
      nvrResetBus(param_1);
    }
    piVar1 = (int *)(lVar2 + 0x254);
    *piVar1 = *piVar1 + 1;
  }
  return;
}



===== nvrFdoDispatchPnp @ 0001cc30 =====

ulonglong nvrFdoDispatchPnp(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong *plVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined4 *puVar8;
  longlong lVar9;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  cVar1 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
  if (cVar1 == '\x01') {
    plVar5 = *(longlong **)(lVar2 + 0x60);
    if ((((((*(byte *)(plVar5 + 0x1c) & 1) != 0) || (plVar5 == (longlong *)0x0)) || (*plVar5 == 0))
        || ((lVar2 = *(longlong *)(*plVar5 + 0x50), lVar2 == 0 ||
            (lVar2 = *(longlong *)(lVar2 + 0x58), lVar2 == 0)))) ||
       (3 < (byte)(*(char *)(lVar2 + 0x14) - 2U))) goto LAB_0001ccc4;
    uVar6 = 0xc0000001;
LAB_0001cde5:
    *(uint *)(param_2 + 0x30) = uVar6;
    ClassCompleteRequest(param_1,param_2,0);
    uVar7 = (ulonglong)uVar6;
  }
  else {
    if (cVar1 == '\a') {
      if ((*(int *)(*(longlong *)(param_2 + 0xb8) + 8) == 3) &&
         ((*(byte *)(*(longlong **)(lVar2 + 0x60) + 0x1c) & 1) == 0)) {
        lVar2 = **(longlong **)(lVar2 + 0x60);
        if (lVar2 == 0) {
LAB_0001cd3f:
          lVar9 = 0;
        }
        else {
          lVar9 = lVar2;
          do {
            lVar3 = *(longlong *)(lVar9 + 0x50);
            if (*(longlong *)(lVar9 + 0x18) == lVar3) break;
            lVar9 = lVar3;
          } while (lVar3 != 0);
          if ((((lVar9 == 0) || (*(longlong *)(lVar9 + 0x10) == 0)) ||
              (lVar3 = *(longlong *)(lVar9 + 0x58), lVar3 == 0)) ||
             ((*(char *)(lVar3 + 0x14) == '\0' &&
              (uVar7 = (**(code **)(*(longlong *)(lVar3 + 0x88) + 0x30))
                                 (lVar9,(uint)*(byte *)(lVar2 + 8) << 8 | 2), (uVar7 & 6) != 0))))
          goto LAB_0001cd3f;
        }
        if (lVar9 != 0) {
          puVar8 = (undefined4 *)ExAllocatePoolWithTag(1,0x10,0x204e7652);
          if (puVar8 == (undefined4 *)0x0) {
            uVar6 = 0xc000009a;
            goto LAB_0001cde5;
          }
          *(undefined4 *)(param_2 + 0x30) = 0;
          *(undefined4 **)(param_2 + 0x38) = puVar8;
          *puVar8 = 1;
          uVar4 = *(undefined8 *)(lVar9 + 0x10);
          *(undefined8 *)(puVar8 + 2) = uVar4;
          ObReferenceObjectByPointer(uVar4,0,0,0);
        }
      }
    }
    else if (cVar1 == '\x14') {
      if ((*(byte *)(*(longlong *)(lVar2 + 0x60) + 0xe0) & 1) == 0) {
        *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 0x22;
      }
      else {
        if (*(int *)(lVar2 + 0xb0) + *(int *)(lVar2 + 0xac) + *(int *)(lVar2 + 0xa8) == 0)
        goto LAB_0001ccc4;
        *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 0x20;
      }
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
    else if ((cVar1 == '\x16') && ((*(byte *)(*(longlong *)(lVar2 + 0x60) + 0xe0) & 1) != 0)) {
      uVar6 = nvrRaidBusDeviceUsageNotification(param_1,param_2);
      goto LAB_0001cde5;
    }
LAB_0001ccc4:
    uVar7 = (*pClassDispatchPnp)(param_1,param_2);
  }
  return uVar7;
}



===== nvrRaidBusDeviceUsageNotification @ 0001ce00 =====

int nvrRaidBusDeviceUsageNotification(longlong param_1,longlong param_2)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  int iVar4;
  int *piVar5;
  
  puVar2 = *(undefined8 **)(param_2 + 0xb8);
  lVar3 = *(longlong *)(param_1 + 0x40);
  puVar2[-9] = *puVar2;
  puVar2[-8] = puVar2[1];
  puVar2[-7] = puVar2[2];
  puVar2[-6] = puVar2[3];
  puVar2[-5] = puVar2[4];
  puVar2[-4] = puVar2[5];
  puVar2[-3] = puVar2[6];
  *(undefined1 *)((longlong)puVar2 + -0x45) = 0;
  iVar4 = ClassSendIrpSynchronous(*(undefined8 *)(lVar3 + 0x10));
  if (-1 < iVar4) {
    iVar1 = *(int *)(puVar2 + 2);
    if (iVar1 == 1) {
      piVar5 = (int *)(lVar3 + 0xa8);
    }
    else if (iVar1 == 2) {
      piVar5 = (int *)(lVar3 + 0xb0);
    }
    else {
      if (iVar1 != 3) {
        return iVar4;
      }
      piVar5 = (int *)(lVar3 + 0xac);
    }
    if (piVar5 != (int *)0x0) {
      if (*(char *)(puVar2 + 1) == '\0') {
        LOCK();
        *piVar5 = *piVar5 + -1;
        UNLOCK();
      }
      else {
        LOCK();
        *piVar5 = *piVar5 + 1;
        UNLOCK();
      }
      if (*(int *)(puVar2 + 2) == 1) {
        KeEnterCriticalRegion();
        iVar4 = KeWaitForSingleObject(lVar3 + 0xb8,0,0,0,0);
        if (*piVar5 == 0) {
          if ((*(uint *)(param_1 + 0x30) >> 0xe & 1) == 0) {
            *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x2000;
          }
        }
        else {
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xffffdfff;
        }
        KeSetEvent(lVar3 + 0xb8,0,0);
        KeLeaveCriticalRegion();
      }
      IoInvalidateDeviceState(*(undefined8 *)(lVar3 + 0x200));
    }
  }
  return iVar4;
}



===== FUN_0001cf60 @ 0001cf60 =====

undefined8 FUN_0001cf60(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  uint uVar7;
  undefined8 uVar8;
  
  plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x40) + 0x60);
  lVar3 = *(longlong *)(*(longlong *)(*plVar2 + 0x50) + 0x10);
  plVar4 = *(longlong **)(*(longlong *)(lVar3 + 0x40) + 0x60);
  PoStartNextPowerIrp(param_2);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  *(undefined1 *)(plVar2 + 0x1a) = 1;
  uVar8 = NvRaidVolumeSendCommandToVolumes(*plVar4,&nvrOsCheckPowerUpCompleteFdo,0);
  if ((int)uVar8 == 0) {
    lVar5 = *(longlong *)(*(longlong *)(lVar3 + 0x40) + 0x60);
    uVar7 = NvRaidSyncSpinLockAcquire(0xffffffff);
    lVar6 = *(longlong *)(lVar5 + 0x48);
    if (lVar6 == 0) {
      NvRaidSyncSpinLockRelease(uVar7);
    }
    else {
      pbVar1 = *(byte **)(lVar6 + 0xb8);
      *(undefined8 *)(lVar5 + 0x48) = 0;
      NvRaidSyncSpinLockRelease(uVar7);
      (**(code **)(*(longlong *)(lVar3 + 8) + 0x70 + (ulonglong)*pbVar1 * 8))(lVar3,lVar6);
    }
  }
  nvrPowerExecuteWorkerThread(param_1,&LAB_0001cf40,1,0,(longlong *)0x0);
  return 0;
}



===== nvrFdoPower @ 0001d050 =====

undefined4 nvrFdoPower(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  int *piVar2;
  longlong lVar3;
  longlong lVar4;
  longlong *plVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 *puVar8;
  char cVar9;
  uint uVar10;
  undefined4 uVar11;
  longlong lVar12;
  undefined8 uVar13;
  undefined4 uVar14;
  uint uVar15;
  bool bVar16;
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(param_2 + 0xb8);
  plVar5 = *(longlong **)(lVar3 + 0x60);
  lVar12 = 0;
  lVar6 = *plVar5;
  cVar9 = '\x01';
  NvRaidSyncAtomicSpinLockAcquire();
  if ((lVar6 != 0) && (*(longlong *)(lVar6 + 0x50) != 0)) {
    lVar12 = *(longlong *)(*(longlong *)(lVar6 + 0x50) + 0x58);
  }
  if (((*(int *)(lVar4 + 0x10) == 0) && (lVar6 != 0)) &&
     ((((lVar7 = *(longlong *)(lVar6 + 0x50), *(longlong *)(lVar6 + 0x18) == lVar7 ||
        ((lVar7 != 0 && ((*(uint *)(lVar7 + 4) & 1) != 0)))) ||
       ((lVar12 != 0 && (*(char *)(lVar12 + 0x14) == '\x02')))) &&
      ((byte)(*(char *)(lVar4 + 1) - 2U) < 2)))) {
    ClassReleaseRemoveLock(param_1,param_2);
    if (((lVar12 != 0) && (*(char *)(lVar12 + 0x14) == '\x02')) && (*(char *)(lVar4 + 1) == '\x02'))
    {
      lVar3 = *(longlong *)(lVar6 + 0x50);
      lVar6 = *(longlong *)(lVar3 + 0x58);
      if (((int)plVar5[1] < *(int *)(lVar4 + 0x18)) && ((*(uint *)(lVar3 + 4) & 0x40) != 0)) {
        if (*(longlong *)(lVar6 + 0xa0) == 0) {
          lVar12 = ExAllocatePoolWithTag(0,(ulonglong)*(byte *)(lVar12 + 0x16) << 3,0x204e7652);
          *(longlong *)(lVar6 + 0xa0) = lVar12;
          if (lVar12 == 0) {
            NvRaidSyncAtomicSpinLockRelease();
            return 0xc000009a;
          }
          *(undefined1 *)(lVar6 + 0xa8) = 0;
          *(uint *)(lVar3 + 4) = *(uint *)(lVar3 + 4) | 0x400;
          if ((*(int *)(lVar4 + 0x20) - 2U < 2) && ((*(uint *)(lVar6 + 0x98) & 2) == 0)) {
            uVar10 = *(uint *)(lVar6 + 0x98) & 0xfffffffe;
            LOCK();
            uVar15 = *(uint *)(lVar6 + 0x98);
            *(uint *)(lVar6 + 0x98) = uVar10;
            UNLOCK();
            uVar15 = uVar15 & 0xfffffffe;
            if (uVar15 != uVar10) {
              do {
                LOCK();
                uVar10 = *(uint *)(lVar6 + 0x98);
                *(uint *)(lVar6 + 0x98) = uVar15;
                UNLOCK();
                uVar10 = uVar10 & 0xfffffffe;
                bVar16 = uVar10 != uVar15;
                uVar15 = uVar10;
              } while (bVar16);
            }
            if ((*(uint *)(lVar6 + 0x98) & 2) == 0) {
              uVar15 = *(uint *)(lVar6 + 0x98) | 2;
              while( true ) {
                LOCK();
                uVar10 = *(uint *)(lVar6 + 0x98);
                *(uint *)(lVar6 + 0x98) = uVar15;
                UNLOCK();
                uVar10 = uVar10 | 2;
                if (uVar10 == uVar15) break;
                uVar15 = uVar10;
              }
            }
          }
        }
        *(longlong *)(*(longlong *)(lVar6 + 0xa0) + (ulonglong)*(byte *)(lVar6 + 0xa8) * 8) =
             param_2;
        *(char *)(lVar6 + 0xa8) = *(char *)(lVar6 + 0xa8) + '\x01';
        NvRaidSyncAtomicSpinLockRelease();
        pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
        *pbVar1 = *pbVar1 | 1;
        return 0x103;
      }
      if (*(int *)(lVar4 + 0x18) == 1) {
        *(uint *)(lVar3 + 4) = *(uint *)(lVar3 + 4) & 0xfffffbff;
        if ((*(uint *)(lVar6 + 0x98) & 2) != 0) {
          uVar10 = *(uint *)(lVar6 + 0x98) & 0xfffffffd;
          LOCK();
          uVar15 = *(uint *)(lVar6 + 0x98);
          *(uint *)(lVar6 + 0x98) = uVar10;
          UNLOCK();
          uVar15 = uVar15 & 0xfffffffd;
          if (uVar15 != uVar10) {
            do {
              LOCK();
              uVar10 = *(uint *)(lVar6 + 0x98);
              *(uint *)(lVar6 + 0x98) = uVar15;
              UNLOCK();
              uVar10 = uVar10 & 0xfffffffd;
              bVar16 = uVar10 != uVar15;
              uVar15 = uVar10;
            } while (bVar16);
          }
          if ((*(uint *)(lVar6 + 0x98) & 1) != 0) {
            nvrOsResumeRaidJob(lVar3);
            uVar10 = *(uint *)(lVar6 + 0x98) & 0xfffffffe;
            LOCK();
            uVar15 = *(uint *)(lVar6 + 0x98);
            *(uint *)(lVar6 + 0x98) = uVar10;
            UNLOCK();
            uVar15 = uVar15 & 0xfffffffe;
            if (uVar15 != uVar10) {
              do {
                LOCK();
                uVar10 = *(uint *)(lVar6 + 0x98);
                *(uint *)(lVar6 + 0x98) = uVar15;
                UNLOCK();
                uVar10 = uVar10 & 0xfffffffe;
                bVar16 = uVar10 != uVar15;
                uVar15 = uVar10;
              } while (bVar16);
            }
          }
        }
      }
    }
    NvRaidSyncAtomicSpinLockRelease();
  }
  else {
    ClassReleaseRemoveLock(param_1,param_2);
    if (*(int *)(lVar4 + 0x10) == 1) {
      if (*(char *)(lVar4 + 1) == '\x02') {
        *(undefined4 *)(plVar5 + 1) = *(undefined4 *)(lVar4 + 0x18);
        *(undefined4 *)((longlong)plVar5 + 0xc) = *(undefined4 *)(lVar4 + 0x20);
        goto LAB_0001d2c6;
      }
LAB_0001d334:
      NvRaidSyncAtomicSpinLockRelease();
    }
    else {
LAB_0001d2c6:
      if ((((((*(char *)(lVar4 + 1) != '\x02') ||
             ((*(byte *)(*(longlong *)(lVar3 + 0x60) + 0xe0) & 1) != 0)) || (lVar6 == 0)) ||
           ((lVar3 = *(longlong *)(lVar6 + 0x50), *(longlong *)(lVar6 + 0x18) == lVar3 ||
            (lVar3 == 0)))) ||
          (((*(uint *)(lVar3 + 4) & 1) != 0 ||
           ((lVar3 = *(longlong *)(lVar3 + 0x10), lVar3 == 0 || (lVar12 == 0)))))) ||
         (*(char *)(lVar12 + 0x14) == '\x02')) goto LAB_0001d334;
      if (*(int *)(lVar4 + 0x10) == 1) {
        if ((int)plVar5[1] < 2) {
          puVar8 = *(undefined8 **)(param_2 + 0xb8);
          puVar8[-9] = *puVar8;
          puVar8[-8] = puVar8[1];
          puVar8[-7] = puVar8[2];
          puVar8[-6] = puVar8[3];
          puVar8[-5] = puVar8[4];
          puVar8[-4] = puVar8[5];
          puVar8[-3] = puVar8[6];
          *(undefined1 *)((longlong)puVar8 + -0x45) = 0;
          lVar3 = *(longlong *)(param_2 + 0xb8);
          *(undefined8 *)(lVar3 + -8) = 0;
          cVar9 = '\0';
          *(code **)(lVar3 + -0x10) = FUN_0001cf60;
          *(undefined1 *)(lVar3 + -0x45) = 0xe0;
        }
        else {
          *(undefined1 *)(plVar5 + 0x1a) = 0;
          PoSetPowerState(param_1,1,*(undefined4 *)(lVar4 + 0x18));
        }
        goto LAB_0001d334;
      }
      NvRaidSyncAtomicSpinLockRelease();
      if ((int)plVar5[1] < *(int *)(lVar4 + 0x18)) {
        uVar13 = NvRaidFdoPowerProcessDeviceIrp(param_1,param_2);
        cVar9 = (char)uVar13;
        if (cVar9 == '\0') {
          return 0x103;
        }
        LOCK();
        piVar2 = (int *)(*(longlong *)(*(longlong *)(lVar3 + 0x40) + 0x60) + 0x18);
        *piVar2 = *piVar2 + 1;
        UNLOCK();
      }
      else {
        nvrPdoUnlockQueue(lVar3);
      }
    }
    if (cVar9 == '\0') {
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      goto LAB_0001d40d;
    }
  }
  PoStartNextPowerIrp(param_2);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
LAB_0001d40d:
  uVar11 = PoCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x10),param_2);
  uVar14 = 0x103;
  if (cVar9 != '\0') {
    uVar14 = uVar11;
  }
  return uVar14;
}



===== FUN_0001d448 @ 0001d448 =====

void FUN_0001d448(longlong param_1,undefined8 *param_2)

{
  char cVar1;
  
  if (param_2 != (undefined8 *)0x0) {
    cVar1 = *(char *)(*(longlong *)(param_1 + 0x40) + 0x6a);
    if (cVar1 == '\0') {
      FUN_0001d5b0(param_1,(longlong)(param_2 + 1));
    }
    else if ((cVar1 != '\x02') && (cVar1 != '\x17')) {
      IoQueueWorkItem(*param_2,FUN_0001d448,1,param_2);
      return;
    }
    IoFreeWorkItem(*param_2);
    ExFreePoolWithTag(param_2,0);
  }
  return;
}



===== FUN_0001d4a8 @ 0001d4a8 =====

undefined8 FUN_0001d4a8(longlong param_1,int *param_2,longlong param_3)

{
  char cVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong *plVar4;
  byte in_CR8;
  
  *param_2 = *param_2 - *(int *)(param_3 + 0xa8);
  param_2[2] = param_2[2] - *(int *)(param_3 + 0xac);
  param_2[1] = param_2[1] - *(int *)(param_3 + 0xb0);
  if ((((*param_2 == 0) && (param_2[2] == 0)) && (param_2[1] == 0)) ||
     ((cVar1 = *(char *)(param_3 + 0x6a), cVar1 == '\x02' || (cVar1 == '\x17')))) {
    uVar2 = 0;
  }
  else if ((cVar1 == '\0') && (in_CR8 < 2)) {
    uVar2 = FUN_0001d5b0(param_1,(longlong)param_2);
  }
  else {
    lVar3 = IoAllocateWorkItem(param_1);
    if (lVar3 != 0) {
      plVar4 = (longlong *)ExAllocatePoolWithTag(0,0x18,0x204e7652);
      if (plVar4 != (longlong *)0x0) {
        *plVar4 = lVar3;
        *(int *)(plVar4 + 1) = *param_2;
        *(int *)((longlong)plVar4 + 0xc) = param_2[1];
        *(int *)(plVar4 + 2) = param_2[2];
        IoQueueWorkItem(lVar3,FUN_0001d448,1);
        return 0x103;
      }
      IoFreeWorkItem();
    }
    uVar2 = 0xc000009a;
  }
  return uVar2;
}



===== FUN_0001d594 @ 0001d594 =====

undefined8 FUN_0001d594(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== FUN_0001d5b0 @ 0001d5b0 =====

undefined8 FUN_0001d5b0(longlong param_1,longlong param_2)

{
  int *piVar1;
  longlong lVar2;
  longlong lVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  longlong lVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined1 local_38 [32];
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if ((*(byte *)(lVar2 + 0x68) & 1) == 0) {
    uVar9 = 0;
  }
  else {
    lVar7 = IoGetAttachedDeviceReference();
    lVar8 = IoAllocateIrp(*(undefined1 *)(lVar7 + 0x4c),0);
    if (lVar8 == 0) {
      uVar9 = 0xc000009a;
    }
    else {
      uVar10 = 0;
      do {
        iVar6 = (int)uVar10;
        if (*(int *)(param_2 + uVar10 * 4) == 0) {
          uVar10 = (ulonglong)(iVar6 + 1);
        }
        else {
          lVar3 = *(longlong *)(lVar8 + 0xb8);
          *(undefined2 *)(lVar3 + -0x48) = 0x161b;
          bVar4 = ~(byte)((uint)*(undefined4 *)(param_2 + uVar10 * 4) >> 0x1f) & 1;
          *(byte *)(lVar3 + -0x40) = bVar4;
          if (bVar4 == 0) {
            piVar1 = (int *)(param_2 + uVar10 * 4);
            *piVar1 = *piVar1 + 1;
          }
          else {
            piVar1 = (int *)(param_2 + uVar10 * 4);
            *piVar1 = *piVar1 + -1;
          }
          iVar5 = (iVar6 != 1) + 2;
          if (iVar6 == 0) {
            iVar5 = 1;
          }
          *(int *)(lVar3 + -0x38) = iVar5;
          *(undefined4 *)(lVar8 + 0x30) = 0xc00000bb;
          KeInitializeEvent(local_38,0,0);
          lVar3 = *(longlong *)(lVar8 + 0xb8);
          *(code **)(lVar3 + -0x10) = FUN_0001d594;
          *(undefined1 **)(lVar3 + -8) = local_38;
          *(undefined1 *)(lVar3 + -0x45) = 0xe0;
          iVar6 = IofCallDriver(lVar7,lVar8);
          if (iVar6 == 0x103) {
            KeWaitForSingleObject(local_38,0,0,0,0);
          }
        }
      } while ((uint)uVar10 < 3);
      IoFreeIrp(lVar8);
      ObfDereferenceObject(lVar7);
      IoInvalidateDeviceState(*(undefined8 *)(lVar2 + 0x200));
      uVar9 = 0xc0000016;
    }
  }
  return uVar9;
}



===== IoctlScsiGetInquiryData @ 0001d6fc =====

undefined8 IoctlScsiGetInquiryData(undefined8 param_1,longlong param_2)

{
  undefined1 uVar1;
  longlong lVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  uint uVar7;
  byte bVar8;
  undefined1 *puVar9;
  longlong local_res8;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  bVar8 = 0;
  local_res8 = 0;
  while( true ) {
    NvRaidApiEnumerateRootVolumes(0x298e0,&local_res8);
    if (local_res8 == 0) break;
    if (*(longlong *)(local_res8 + 0x58) != 0) {
      bVar8 = bVar8 + 1;
    }
  }
  uVar7 = (uint)bVar8 * 0x30 + 0xc;
  if (*(uint *)(lVar2 + 8) < uVar7) {
    uVar5 = 0xc0000023;
  }
  else {
    puVar3 = *(undefined1 **)(param_2 + 0x18);
    *puVar3 = 1;
    puVar3[4] = bVar8;
    puVar3[5] = 0xff;
    if (bVar8 == 0) {
      *(undefined4 *)(puVar3 + 8) = 0;
    }
    else {
      *(int *)(puVar3 + 8) = (int)(puVar3 + 0xc) - (int)puVar3;
    }
    local_res8 = 0;
    puVar4 = puVar3 + 0xc;
    puVar9 = (undefined1 *)0x0;
    while( true ) {
      puVar6 = puVar4;
      NvRaidApiEnumerateRootVolumes(0x298e0,&local_res8);
      if (local_res8 == 0) break;
      puVar4 = puVar6;
      if (*(longlong *)(local_res8 + 0x58) != 0) {
        if (puVar9 != (undefined1 *)0x0) {
          *(int *)(puVar9 + 8) = (int)puVar6 - (int)puVar3;
        }
        *puVar6 = 0;
        uVar1 = *(undefined1 *)(local_res8 + 8);
        *(undefined4 *)(puVar6 + 8) = 0;
        puVar6[0xc] = puVar6[0xc] & 0xe0;
        puVar6[1] = uVar1;
        *(undefined2 *)(puVar6 + 2) = 0x100;
        *(undefined4 *)(puVar6 + 4) = 0x24;
        puVar6[0xf] = puVar6[0xf] & 0xf2 | 2;
        *(undefined8 *)(puVar6 + 0x14) = *(undefined8 *)(local_res8 + 0x2c);
        *(undefined8 *)(puVar6 + 0x1c) = *(undefined8 *)(local_res8 + 0x34);
        *(undefined8 *)(puVar6 + 0x24) = *(undefined8 *)(local_res8 + 0x3c);
        *(undefined4 *)(puVar6 + 0x2c) = *(undefined4 *)(local_res8 + 0x44);
        puVar4 = puVar6 + 0x30;
        puVar9 = puVar6;
      }
    }
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar7;
    uVar5 = 0;
  }
  return uVar5;
}



===== IoctlStorageQueryAdapterProperty @ 0001d838 =====

undefined8 IoctlStorageQueryAdapterProperty(longlong param_1,longlong param_2,longlong param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10;
  undefined4 local_e;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 4) == 0) {
    memset(&local_28,0,0x20);
    local_28 = 0x20;
    local_24 = 0x20;
    uVar1 = 0x20;
    if (*(uint *)(param_3 + 8) < 0x20) {
      uVar1 = *(uint *)(param_3 + 8);
    }
    local_1c = 0xffffffff;
    local_20 = 0x40000;
    local_18 = 0x3ffff;
    local_14 = 0x10001;
    local_10 = 8;
    local_e = 0;
    memcpy(*(void **)(param_2 + 0x18),&local_28,(ulonglong)uVar1);
    *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar1;
  }
  else if (*(int *)(param_1 + 4) != 1) {
    uVar2 = 0xc0000002;
  }
  return uVar2;
}



===== NvRaidFdoPowerForwardDeviceIrp @ 0001d8e4 =====

void NvRaidFdoPowerForwardDeviceIrp(void)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong in_R9;
  
  if (in_R9 != 0) {
    lVar1 = *(longlong *)(in_R9 + 0xb8);
    lVar2 = *(longlong *)(lVar1 + 0x28);
    lVar3 = *(longlong *)(*(longlong *)(lVar2 + 0x40) + 0x60);
    *(undefined4 *)(lVar3 + 8) = *(undefined4 *)(lVar1 + 0x18);
    *(undefined4 *)(lVar3 + 0xc) = *(undefined4 *)(lVar1 + 0x20);
    PoSetPowerState(lVar2,1,*(undefined4 *)(lVar1 + 0x18));
    PoStartNextPowerIrp();
    *(char *)(in_R9 + 0x43) = *(char *)(in_R9 + 0x43) + '\x01';
    *(longlong *)(in_R9 + 0xb8) = *(longlong *)(in_R9 + 0xb8) + 0x48;
    PoCallDriver(*(undefined8 *)(*(longlong *)(lVar2 + 0x40) + 0x10));
  }
  return;
}



===== NvRaidFdoPowerForwardSystemIrp @ 0001d958 =====

void NvRaidFdoPowerForwardSystemIrp(void)

{
  int *piVar1;
  longlong lVar2;
  longlong in_R9;
  
  if (in_R9 != 0) {
    lVar2 = *(longlong *)(*(longlong *)(in_R9 + 0xb8) + 0x28);
    LOCK();
    piVar1 = (int *)(*(longlong *)
                      (*(longlong *)
                        (*(longlong *)
                          (*(longlong *)(**(longlong **)(*(longlong *)(lVar2 + 0x40) + 0x60) + 0x50)
                          + 0x10) + 0x40) + 0x60) + 0x18);
    *piVar1 = *piVar1 + 1;
    UNLOCK();
    PoStartNextPowerIrp();
    *(char *)(in_R9 + 0x43) = *(char *)(in_R9 + 0x43) + '\x01';
    *(longlong *)(in_R9 + 0xb8) = *(longlong *)(in_R9 + 0xb8) + 0x48;
    PoCallDriver(*(undefined8 *)(*(longlong *)(lVar2 + 0x40) + 0x10));
  }
  return;
}



===== NvRaidFdoPowerProcessDeviceIrp @ 0001d9c4 =====

ulonglong NvRaidFdoPowerProcessDeviceIrp(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  undefined1 uVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  code *pcVar9;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  plVar3 = *(longlong **)(*(longlong *)(param_1 + 0x40) + 0x60);
  lVar4 = *(longlong *)(*(longlong *)(*plVar3 + 0x50) + 0x10);
  lVar5 = *(longlong *)(*(longlong *)(lVar4 + 0x40) + 0x60);
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar5 + 0xa0);
  if (*(int *)(lVar5 + 8) < *(int *)(lVar2 + 0x18)) {
    if (*(char *)(lVar5 + 0xa8) == '\0') {
      *(undefined1 *)(lVar5 + 0xa8) = 1;
      KeReleaseSpinLock();
      pcVar9 = NvRaidFdoPowerForwardSystemIrp;
      uVar8 = 1;
      if (1 < *(int *)(lVar2 + 0x18)) {
        uVar8 = 4;
      }
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      if (*(int *)(lVar2 + 0x10) == 1) {
        pcVar9 = NvRaidFdoPowerForwardDeviceIrp;
      }
      uVar7 = PoRequestPowerIrp(lVar4,*(undefined1 *)(lVar2 + 1),uVar8,pcVar9,param_2,0);
    }
    else {
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      plVar3[0x19] = param_2;
      uVar7 = KeReleaseSpinLock();
    }
    uVar7 = uVar7 & 0xffffffffffffff00;
  }
  else {
    uVar8 = KeReleaseSpinLock(lVar5 + 0xa0,CONCAT31((int3)((uint)*(int *)(lVar2 + 0x18) >> 8),uVar6)
                             );
    uVar7 = CONCAT71((int7)((ulonglong)uVar8 >> 8),1);
  }
  return uVar7;
}



===== nvrPdoDispatchPnp @ 0001dae4 =====

ulonglong nvrPdoDispatchPnp(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  undefined1 local_18 [8];
  undefined8 local_10;
  
  cVar2 = *(char *)(*(longlong *)(param_2 + 0xb8) + 1);
  lVar3 = *(longlong *)(param_1 + 0x40);
  lVar4 = *(longlong *)(lVar3 + 0x60);
  if (cVar2 == '\x02') {
    if ((*(byte *)(lVar4 + 0x1c) & 0x20) != 0) {
      ObfDereferenceObject(param_1);
      pbVar1 = (byte *)(lVar4 + 0x1c);
      *pbVar1 = *pbVar1 & 0xdf;
    }
LAB_0001dbaf:
    uVar7 = (*pClassDispatchPnp)(param_1,param_2);
    return uVar7;
  }
  if (cVar2 == '\f') {
    uVar6 = nvrQueryText(param_1,*(int *)(*(longlong *)(param_2 + 0xb8) + 8),local_18);
    uVar5 = (uint)uVar6;
    if (uVar5 == 0xc0000002) {
      uVar5 = *(uint *)(param_2 + 0x30);
    }
    else {
      uVar6 = 0;
      if (-1 < (int)uVar5) {
        uVar6 = local_10;
      }
      *(undefined8 *)(param_2 + 0x38) = uVar6;
    }
  }
  else {
    if (cVar2 != '\x14') {
      if (cVar2 != '\x16') goto LAB_0001dbaf;
      uVar5 = nvrPdoPnpDeviceUsageNotification(param_1,param_2);
      goto LAB_0001db92;
    }
    *(undefined4 *)(param_2 + 0x30) = 0;
    if (*(int *)(lVar3 + 0xb0) + *(int *)(lVar3 + 0xac) + *(int *)(lVar3 + 0xa8) != 0) {
      *(ulonglong *)(param_2 + 0x38) = *(ulonglong *)(param_2 + 0x38) | 0x20;
    }
    uVar5 = 0;
  }
  *(uint *)(param_2 + 0x30) = uVar5;
  ClassCompleteRequest(param_1,param_2,0);
LAB_0001db92:
  return (ulonglong)uVar5;
}



===== nvrPdoDeviceControl @ 0001dbc8 =====

ulonglong nvrPdoDeviceControl(longlong param_1,longlong param_2)

{
  undefined1 uVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  int *_Dst;
  longlong lVar5;
  undefined4 *puVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  size_t _Size;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 local_60;
  undefined1 local_5d;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_4c;
  undefined4 local_48;
  undefined8 local_40;
  undefined8 local_37;
  undefined8 uStack_2f;
  undefined4 local_26;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  plVar4 = *(longlong **)(*(longlong *)(param_1 + 0x40) + 0x60);
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar1 = ScsiPortNumber;
  iVar2 = *(int *)(lVar3 + 0x18);
  if (iVar2 == 0x41010) {
    uVar9 = IoctlScsiGetCapabilities(param_1,param_2);
    uVar7 = (uint)uVar9;
  }
  else {
    if (iVar2 == 0x41018) {
      puVar6 = *(undefined4 **)(param_2 + 0x18);
      if (*(uint *)(lVar3 + 8) < 8) {
        uVar7 = 0xc000000d;
        goto LAB_0001ddcb;
      }
      if (*plVar4 != 0) {
        *puVar6 = 8;
        *(undefined1 *)((longlong)puVar6 + 5) = 0;
        *(undefined1 *)(puVar6 + 1) = uVar1;
        uVar7 = 0;
        uVar1 = *(undefined1 *)(*plVar4 + 8);
        *(undefined1 *)((longlong)puVar6 + 7) = 0;
        *(undefined1 *)((longlong)puVar6 + 6) = uVar1;
        *(undefined8 *)(param_2 + 0x38) = 8;
        goto LAB_0001ddcb;
      }
LAB_0001dd92:
      uVar7 = 0xc00000c0;
      goto LAB_0001ddcb;
    }
    if (iVar2 == 0x41020) {
      if (*(uint *)(lVar3 + 8) < 0x30) {
        uVar7 = 0xc0000004;
      }
      else {
        uVar9 = nvrDiskDumpQueryDumpPointers(param_1,*(void **)(param_2 + 0x18));
        uVar7 = (uint)uVar9;
        if (-1 < (int)uVar7) {
          *(undefined8 *)(param_2 + 0x38) = 0x38;
        }
      }
      goto LAB_0001ddcb;
    }
    if (iVar2 == 0x4d004) {
      uVar8 = IoctlScsiPassThrough(param_1,param_2);
      uVar7 = (uint)uVar8;
    }
    else {
      if (iVar2 != 0x4d014) {
        if (iVar2 != 0x2d1400) {
LAB_0001dc70:
          uVar8 = ClassDeviceControl(param_1,param_2);
          return uVar8;
        }
        if (*(uint *)(lVar3 + 0x10) < 0xc) {
          uVar7 = 0xc0000023;
          goto LAB_0001ddcb;
        }
        _Dst = *(int **)(param_2 + 0x18);
        iVar2 = *_Dst;
        if (iVar2 != 0) {
          if (iVar2 == 1) {
            uVar9 = IoctlStorageQueryAdapterProperty((longlong)_Dst,param_2,lVar3);
            uVar7 = (uint)uVar9;
          }
          else {
            if (iVar2 != 2) goto LAB_0001dc70;
            uVar9 = IoctlStorageQueryDeviceIdProperty(param_1,param_2);
            uVar7 = (uint)uVar9;
          }
          goto LAB_0001ddcb;
        }
        if (_Dst[1] != 0) {
          if (_Dst[1] == 1) {
            uVar7 = 0;
          }
          else {
            uVar7 = 0xc0000002;
          }
          goto LAB_0001ddcb;
        }
        lVar5 = *plVar4;
        if (lVar5 != 0) {
          _Size = 0x48;
          if (*(uint *)(lVar3 + 8) < 0x48) {
            _Size = (size_t)*(uint *)(lVar3 + 8);
          }
          memset(&local_68,0,0x48);
          local_37 = *(undefined8 *)(lVar5 + 0x34);
          uStack_2f = *(undefined8 *)(lVar5 + 0x3c);
          local_68 = 0x28;
          local_5c = 0x28;
          local_40 = *(undefined8 *)(lVar5 + 0x2c);
          local_26 = *(undefined4 *)(lVar5 + 0x44);
          local_64 = 0x48;
          local_60 = 0;
          local_5d = 1;
          local_58 = 0x31;
          local_54 = 0x42;
          local_4c = 8;
          local_48 = 0x20;
          memcpy(_Dst,&local_68,_Size);
          uVar7 = 0;
          *(size_t *)(param_2 + 0x38) = _Size;
          goto LAB_0001ddcb;
        }
        goto LAB_0001dd92;
      }
      uVar8 = IoctlScsiPassThroughDirect(param_1,param_2);
      uVar7 = (uint)uVar8;
    }
  }
  *(uint *)(param_2 + 0x30) = uVar7;
LAB_0001ddcb:
  *(uint *)(param_2 + 0x30) = uVar7;
  if ((((uVar7 + 0x3fffff5e < 2) || (uVar7 == 0xc00000b5)) || (uVar7 + 0x3fffffee < 3)) ||
     (uVar7 == 0x80000016)) {
    IoSetHardErrorOrVerifyDevice(param_2,param_1);
  }
  ClassReleaseRemoveLock(param_1,param_2);
  ClassCompleteRequest(param_1,param_2,0);
  return (ulonglong)uVar7;
}



===== FUN_0001de38 @ 0001de38 =====

void FUN_0001de38(longlong param_1,longlong param_2)

{
  uint *puVar1;
  byte bVar2;
  longlong lVar3;
  longlong *plVar4;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  plVar4 = *(longlong **)(*(longlong *)(param_1 + 0x40) + 0x60);
  if (*plVar4 != 0) {
    puVar1 = (uint *)(*plVar4 + 4);
    *puVar1 = *puVar1 & 0xfffffbff;
  }
  if (*(int *)(lVar3 + 0x20) != 0) {
    nvrPdoUnlockQueue(param_1);
  }
  if ((int)plVar4[3] == 0) {
    nvrFlushPendingQueue(param_1,(longlong)(plVar4 + 5));
  }
  bVar2 = *(byte *)((longlong)plVar4 + 0x1c);
  if (((bVar2 & 4) != 0) && (*(byte *)((longlong)plVar4 + 0x1c) = bVar2 & 0xfb, (bVar2 & 2) != 0)) {
    nvrOsResumeRaidJob(*plVar4);
  }
  if ((*(uint *)(*plVar4 + 4) & 0x4000) != 0) {
    nvrOsResumeRaidJob(*plVar4);
  }
                    /* WARNING: Could not recover jumptable at 0x0001dec7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PoSetPowerState(param_1,1,*(undefined4 *)(lVar3 + 0x18));
  return;
}



===== nvrPdoPower @ 0001ded0 =====

undefined4 nvrPdoPower(longlong param_1,longlong param_2)

{
  int *piVar1;
  byte *pbVar2;
  longlong *plVar3;
  undefined4 uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong *plVar8;
  undefined1 uVar9;
  uint uVar10;
  int iVar11;
  undefined8 uVar12;
  uint uVar13;
  bool bVar14;
  
  lVar5 = *(longlong *)(param_1 + 0x40);
  lVar6 = *(longlong *)(param_2 + 0xb8);
  ClassReleaseRemoveLock();
  if ((*(char *)(lVar6 + 1) == '\x02') && (iVar11 = *(int *)(lVar6 + 0x20), 1 < iVar11)) {
    if (iVar11 < 4) {
      if ((*(int *)(lVar6 + 0x10) == 1) &&
         (lVar7 = *(longlong *)(lVar5 + 0x60), *(int *)(lVar7 + 8) < *(int *)(lVar6 + 0x18))) {
        if (*(code **)(param_2 + 0x78) != nvrPdoPower) {
          LOCK();
          piVar1 = (int *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60) + 0x18);
          *piVar1 = *piVar1 + 1;
          UNLOCK();
          *(code **)(param_2 + 0x78) = nvrPdoPower;
        }
        if ((*(byte *)(lVar7 + 0x1c) & 4) == 0) {
          uVar10 = *(uint *)(lVar7 + 0x1c) & 0xfffffffd;
          LOCK();
          uVar13 = *(uint *)(lVar7 + 0x1c);
          *(uint *)(lVar7 + 0x1c) = uVar10;
          UNLOCK();
          uVar13 = uVar13 & 0xfffffffd;
          if (uVar13 != uVar10) {
            do {
              LOCK();
              uVar10 = *(uint *)(lVar7 + 0x1c);
              *(uint *)(lVar7 + 0x1c) = uVar13;
              UNLOCK();
              uVar10 = uVar10 & 0xfffffffd;
              bVar14 = uVar10 != uVar13;
              uVar13 = uVar10;
            } while (bVar14);
          }
          if ((*(uint *)(lVar7 + 0x1c) & 4) == 0) {
            uVar10 = *(uint *)(lVar7 + 0x1c) | 4;
            LOCK();
            uVar13 = *(uint *)(lVar7 + 0x1c);
            *(uint *)(lVar7 + 0x1c) = uVar10;
            UNLOCK();
            uVar13 = uVar13 | 4;
            if (uVar13 != uVar10) {
              do {
                LOCK();
                uVar10 = *(uint *)(lVar7 + 0x1c);
                *(uint *)(lVar7 + 0x1c) = uVar13;
                UNLOCK();
                uVar10 = uVar10 | 4;
                bVar14 = uVar10 != uVar13;
                uVar13 = uVar10;
              } while (bVar14);
            }
          }
        }
        goto LAB_0001dfe4;
      }
    }
    else if ((iVar11 < 7) && ((*(int *)(lVar6 + 0x10) == 1 || (gIsWin2k != '\0')))) {
LAB_0001dfe4:
      uVar12 = nvrOsShutdownPdo(param_1,param_2);
      if ((int)uVar12 == 0x103) {
        return 0x103;
      }
    }
  }
  *(longlong *)(param_2 + 0x78) = 0;
  if (1 < (byte)(*(char *)(lVar6 + 1) - 2U)) goto LAB_0001e12e;
  plVar8 = *(longlong **)(lVar5 + 0x60);
  *(undefined4 *)(param_2 + 0x30) = 0;
  if (*plVar8 == 0) {
    *(undefined4 *)(param_2 + 0x30) = 0xc00000c0;
  }
  else {
    plVar3 = plVar8 + 0x14;
    if (*(int *)(lVar6 + 0x10) == 1) {
      if (*(char *)(lVar6 + 1) == '\x02') {
        *(undefined4 *)(plVar8 + 1) = *(undefined4 *)(lVar6 + 0x18);
        *(undefined4 *)((longlong)plVar8 + 0xc) = *(undefined4 *)(lVar6 + 0x20);
        uVar9 = KeAcquireSpinLockRaiseToDpc();
        *(undefined1 *)(plVar8 + 0x15) = 0;
        KeReleaseSpinLock(plVar3,uVar9);
        if ((int)plVar8[1] == 1) {
          uVar12 = NvRaidVolumeSendCommandToVolumes(*plVar8,&nvrOsCheckPoweredDownFdo,0);
          if ((int)uVar12 != 0) {
            pbVar2 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
            *pbVar2 = *pbVar2 | 1;
            nvrPowerExecuteWorkerThread(param_1,FUN_0001e1e8,0,param_2,(longlong *)(param_2 + 0x78))
            ;
            return 0x103;
          }
          uVar12 = NvRaidVolumeSendCommandToVolumes(*plVar8,&nvrOsCheckPowerUpCompleteFdo,0);
          if ((int)uVar12 != 0) {
            plVar8[9] = param_2;
            pbVar2 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
            *pbVar2 = *pbVar2 | 1;
            return 0x103;
          }
          FUN_0001de38(param_1,param_2);
        }
        else {
          PoSetPowerState(param_1,1);
          if (*plVar8 != 0) {
            NvRaidVolumeSendCommandToVolumes(*plVar8,nvrOsShutdownFdo,0);
          }
        }
      }
      else {
        uVar9 = KeAcquireSpinLockRaiseToDpc();
        *(undefined1 *)(plVar8 + 0x15) = 0;
LAB_0001e11e:
        KeReleaseSpinLock(plVar3,uVar9);
      }
    }
    else {
      uVar9 = KeAcquireSpinLockRaiseToDpc(plVar3);
      if ((char)plVar8[0x15] != '\0') goto LAB_0001e11e;
      *(undefined1 *)(plVar8 + 0x15) = 1;
      KeReleaseSpinLock(plVar3,uVar9);
      uVar12 = 1;
      if (1 < *(int *)(lVar6 + 0x18)) {
        uVar12 = 4;
      }
      if ((*(char *)(lVar6 + 1) == '\x02') && (*(int *)(lVar6 + 0x18) == 1)) {
        *(byte *)((longlong)plVar8 + 0x1c) = *(byte *)((longlong)plVar8 + 0x1c) | 0x40;
      }
      pbVar2 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar2 = *pbVar2 | 1;
      iVar11 = PoRequestPowerIrp(param_1,*(undefined1 *)(lVar6 + 1),uVar12,nvrPdoSystemPowerComplete
                                 ,param_2,0);
      if (iVar11 == 0x103) {
        return 0x103;
      }
    }
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
LAB_0001e12e:
  PoStartNextPowerIrp(param_2);
  uVar4 = *(undefined4 *)(param_2 + 0x30);
  ClassCompleteRequest(param_1,param_2,0);
  return uVar4;
}



===== FUN_0001e1e8 @ 0001e1e8 =====

void FUN_0001e1e8(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  code *pcVar2;
  
  if (param_2 != 0) {
    plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x40) + 0x60);
    pcVar2 = IoFreeWorkItem_exref;
    if (gUseNvrWorkItem != '\0') {
      pcVar2 = nvrFreeWorkItem;
    }
    (*pcVar2)(*(undefined8 *)(param_2 + 0x78));
    NvRaidVolumeSendCommandToVolumes(*plVar1,FUN_0001e274,param_2);
    FUN_0001de38(param_1,param_2);
    PoStartNextPowerIrp(param_2);
    ClassCompleteRequest(param_1,param_2,0);
  }
  return;
}



===== FUN_0001e274 @ 0001e274 =====

undefined8 FUN_0001e274(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 local_28 [32];
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  if (*(longlong *)(param_1 + 0x58) == 0) {
    lVar2 = *(longlong *)(param_1 + 0x10);
    lVar3 = *(longlong *)(lVar2 + 0x40);
    if (((*(byte *)(lVar3 + 0x68) & 1) != 0) && (1 < *(int *)(*(longlong *)(lVar3 + 0x60) + 8))) {
      KeInitializeEvent(local_28,0,0);
      uVar5 = 1;
      if (1 < *(int *)(lVar1 + 0x18)) {
        uVar5 = 4;
      }
      iVar4 = PoRequestPowerIrp(lVar2,*(undefined1 *)(lVar1 + 1),uVar5,FUN_0001e320,local_28,0);
      if (iVar4 == 0x103) {
        KeWaitForSingleObject(local_28,0,0,0,0);
      }
    }
  }
  return 0;
}



===== FUN_0001e320 @ 0001e320 =====

void FUN_0001e320(void)

{
  KeSetEvent();
  return;
}



===== nvrPdoUnlockQueue @ 0001e338 =====

undefined8 nvrPdoUnlockQueue(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
  if (*(int *)(lVar2 + 0x18) != 0) {
    LOCK();
    piVar1 = (int *)(lVar2 + 0x18);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 == 0) {
      nvrFlushPendingQueue(param_1,lVar2 + 0x28);
    }
  }
  return 0;
}



===== nvrPdoIoInvalidateDeviceRelations @ 0001e360 =====

undefined8 nvrPdoIoInvalidateDeviceRelations(longlong param_1,undefined4 *param_2)

{
  if (*(longlong *)(param_1 + 0x58) == 0) {
    IoInvalidateDeviceRelations
              (*(undefined8 *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40) + 0x200),*param_2
              );
  }
  return 0;
}



===== FUN_0001e38c @ 0001e38c =====

void FUN_0001e38c(longlong param_1,longlong param_2)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
  nvrPdoUnlockQueue(param_1);
  LOCK();
  piVar1 = (int *)(lVar3 + 0x9c);
  iVar2 = *piVar1;
  *piVar1 = 0;
  UNLOCK();
  if (iVar2 != 0) {
    IoStopTimer(param_1);
  }
  if (param_2 != 0) {
    IoFreeWorkItem(param_2);
  }
  return;
}



===== FUN_0001e3e4 @ 0001e3e4 =====

void FUN_0001e3e4(longlong param_1)

{
  int *piVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
  if (*(int *)(lVar2 + 0x98) != 0) {
    LOCK();
    piVar1 = (int *)(lVar2 + 0x98);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 == 0) {
      uVar3 = IoAllocateWorkItem();
      IoQueueWorkItem(uVar3,FUN_0001e38c,1,uVar3);
    }
  }
  return;
}



===== nvrPdoStartTimerForPnpIrp @ 0001e428 =====

void nvrPdoStartTimerForPnpIrp(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
  if ((*(char *)(lVar1 + 0x1c) < '\0') && (*(int *)(lVar1 + 0x9c) != 0)) {
    IoStartTimer();
  }
  return;
}



===== IoctlScsiPassThrough @ 0001e450 =====

ulonglong IoctlScsiPassThrough(longlong param_1,longlong param_2)

{
  longlong lVar1;
  char cVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  char in_CR8;
  uint local_res18;
  undefined4 uStackX_1c;
  ulonglong local_res20;
  undefined2 local_58;
  undefined1 local_56;
  undefined1 local_55;
  undefined1 local_54;
  undefined1 local_53;
  undefined1 local_52;
  undefined1 local_51;
  undefined1 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  longlong local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined8 uStack_2c;
  
  if (in_CR8 == '\0') {
    lVar1 = *(longlong *)(param_2 + 0xb8);
    cVar2 = IoIs32bitProcess();
    if ((-(ulonglong)(cVar2 != '\0') & 0xfffffffffffffff4) + 0x38 <=
        (ulonglong)*(uint *)(lVar1 + 0x10)) {
      IoIs32bitProcess(param_2);
      if (*(int *)(*(longlong *)(param_2 + 0x18) + 0xc) != 0) {
        cVar2 = IoIs32bitProcess(param_2);
        if (cVar2 == '\0') {
          uVar3 = *(ulonglong *)(*(longlong *)(param_2 + 0x18) + 0x18);
        }
        else {
          uVar3 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 0x18) + 0x14);
        }
        cVar2 = IoIs32bitProcess();
        if (uVar3 < (-(ulonglong)(cVar2 != '\0') & 0xfffffffffffffff4) + 0x38) {
          return 0xc000000d;
        }
      }
      nvrGetScsiPassThroughLengths(param_2,(longlong *)&local_res20,(ulonglong *)&local_res18);
      if ((local_res20 <= *(uint *)(lVar1 + 0x10)) &&
         (CONCAT44(uStackX_1c,local_res18) <= (ulonglong)*(uint *)(lVar1 + 8))) {
        IoIs32bitProcess(param_2);
        local_58 = **(undefined2 **)(param_2 + 0x18);
        IoIs32bitProcess(param_2);
        local_56 = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 2);
        IoIs32bitProcess(param_2);
        local_55 = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 3);
        IoIs32bitProcess(param_2);
        local_54 = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 4);
        IoIs32bitProcess(param_2);
        local_53 = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 5);
        IoIs32bitProcess(param_2);
        local_52 = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 6);
        IoIs32bitProcess(param_2);
        local_51 = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 7);
        IoIs32bitProcess(param_2);
        local_50 = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 8);
        IoIs32bitProcess(param_2);
        local_4c = *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0xc);
        IoIs32bitProcess(param_2);
        local_48 = *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0x10);
        cVar2 = IoIs32bitProcess(param_2);
        local_40 = *(longlong *)(param_2 + 0x18);
        if (cVar2 == '\0') {
          uVar3 = *(ulonglong *)(local_40 + 0x18);
        }
        else {
          uVar3 = (ulonglong)*(uint *)(local_40 + 0x14);
        }
        local_40 = local_40 + uVar3;
        cVar2 = IoIs32bitProcess(param_2);
        if (cVar2 == '\0') {
          local_38 = *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0x20);
        }
        else {
          local_38 = *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0x18);
        }
        cVar2 = IoIs32bitProcess(param_2);
        if (cVar2 == '\0') {
          puVar4 = (undefined8 *)(*(longlong *)(param_2 + 0x18) + 0x24);
        }
        else {
          puVar4 = (undefined8 *)(*(longlong *)(param_2 + 0x18) + 0x1c);
        }
        local_34 = *puVar4;
        uStack_2c = puVar4[1];
        uVar3 = nvrIoctlScsiPassThrough(param_1,param_2,(longlong)&local_58);
        if ((int)uVar3 < 0) {
          return uVar3;
        }
        IoIs32bitProcess(param_2);
        *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 2) = local_56;
        IoIs32bitProcess(param_2);
        *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 7) = local_51;
        IoIs32bitProcess(param_2);
        *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0xc) = local_4c;
        nvrGetScsiPassThroughLengths(param_2,(longlong *)&local_res20,(ulonglong *)&local_res18);
        *(ulonglong *)(param_2 + 0x38) = (ulonglong)local_res18;
        return 0;
      }
    }
    uVar3 = 0xc0000023;
  }
  else {
    uVar3 = 0xc00000bb;
  }
  return uVar3;
}



===== IoctlScsiPassThroughDirect @ 0001e6dc =====

ulonglong IoctlScsiPassThroughDirect(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  char cVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  int iVar6;
  longlong lVar7;
  uint uVar8;
  char in_CR8;
  undefined2 local_48;
  undefined1 local_46;
  undefined1 local_45;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  longlong local_30;
  undefined4 local_28;
  undefined8 local_24;
  undefined8 uStack_1c;
  
  if (in_CR8 != '\0') {
    return 0xc00000bb;
  }
  lVar2 = *(longlong *)(param_2 + 0xb8);
  cVar3 = IoIs32bitProcess();
  if ((-(ulonglong)(cVar3 != '\0') & 0xfffffffffffffff4) + 0x38 <=
      (ulonglong)*(uint *)(lVar2 + 0x10)) {
    IoIs32bitProcess(param_2);
    if (*(char *)(*(longlong *)(param_2 + 0x18) + 7) != '\0') {
      cVar3 = IoIs32bitProcess(param_2);
      if (cVar3 == '\0') {
        uVar8 = *(uint *)(*(longlong *)(param_2 + 0x18) + 0x20);
      }
      else {
        uVar8 = *(uint *)(*(longlong *)(param_2 + 0x18) + 0x18);
      }
      cVar3 = IoIs32bitProcess();
      if ((ulonglong)uVar8 < (-(ulonglong)(cVar3 != '\0') & 0xfffffffffffffff4) + 0x38) {
        return 0xc000000d;
      }
    }
    IoIs32bitProcess(param_2);
    if (*(int *)(*(longlong *)(param_2 + 0x18) + 0xc) != 0) {
      cVar3 = IoIs32bitProcess(param_2);
      if (cVar3 == '\0') {
        lVar7 = *(longlong *)(*(longlong *)(param_2 + 0x18) + 0x18);
      }
      else {
        lVar7 = (longlong)*(int *)(*(longlong *)(param_2 + 0x18) + 0x14);
      }
      if (lVar7 == 0) {
        return 0xc000000d;
      }
    }
    cVar3 = IoIs32bitProcess();
    if ((-(ulonglong)(cVar3 != '\0') & 0xfffffffffffffff4) + 0x38 <=
        (ulonglong)*(uint *)(lVar2 + 0x10)) {
      IoIs32bitProcess(param_2);
      bVar1 = *(byte *)(*(longlong *)(param_2 + 0x18) + 7);
      cVar3 = IoIs32bitProcess(param_2);
      if (cVar3 == '\0') {
        iVar6 = *(int *)(*(longlong *)(param_2 + 0x18) + 0x20);
      }
      else {
        iVar6 = *(int *)(*(longlong *)(param_2 + 0x18) + 0x18);
      }
      if (iVar6 + (uint)bVar1 <= *(uint *)(lVar2 + 8)) {
        IoIs32bitProcess(param_2);
        local_48 = **(undefined2 **)(param_2 + 0x18);
        IoIs32bitProcess(param_2);
        local_46 = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 2);
        IoIs32bitProcess(param_2);
        local_45 = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 3);
        IoIs32bitProcess(param_2);
        local_44 = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 4);
        IoIs32bitProcess(param_2);
        local_43 = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 5);
        IoIs32bitProcess(param_2);
        local_42 = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 6);
        IoIs32bitProcess(param_2);
        local_41 = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 7);
        IoIs32bitProcess(param_2);
        local_40 = *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 8);
        IoIs32bitProcess(param_2);
        local_3c = *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0xc);
        IoIs32bitProcess(param_2);
        local_38 = *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0x10);
        cVar3 = IoIs32bitProcess(param_2);
        if (cVar3 == '\0') {
          local_30 = *(longlong *)(*(longlong *)(param_2 + 0x18) + 0x18);
        }
        else {
          local_30 = (longlong)*(int *)(*(longlong *)(param_2 + 0x18) + 0x14);
        }
        cVar3 = IoIs32bitProcess(param_2);
        if (cVar3 == '\0') {
          local_28 = *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0x20);
        }
        else {
          local_28 = *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0x18);
        }
        cVar3 = IoIs32bitProcess(param_2);
        if (cVar3 == '\0') {
          puVar4 = (undefined8 *)(*(longlong *)(param_2 + 0x18) + 0x24);
        }
        else {
          puVar4 = (undefined8 *)(*(longlong *)(param_2 + 0x18) + 0x1c);
        }
        local_24 = *puVar4;
        uStack_1c = puVar4[1];
        uVar5 = nvrIoctlScsiPassThrough(param_1,param_2,(longlong)&local_48);
        if ((int)uVar5 < 0) {
          return uVar5;
        }
        IoIs32bitProcess(param_2);
        *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 2) = local_46;
        IoIs32bitProcess(param_2);
        *(undefined1 *)(*(longlong *)(param_2 + 0x18) + 7) = local_41;
        IoIs32bitProcess(param_2);
        *(undefined4 *)(*(longlong *)(param_2 + 0x18) + 0xc) = local_3c;
        IoIs32bitProcess(param_2);
        if (*(char *)(*(longlong *)(param_2 + 0x18) + 7) == '\0') {
          cVar3 = IoIs32bitProcess();
          uVar5 = (-(ulonglong)(cVar3 != '\0') & 0xfffffffffffffff4) + 0x38;
        }
        else {
          IoIs32bitProcess();
          bVar1 = *(byte *)(*(longlong *)(param_2 + 0x18) + 7);
          cVar3 = IoIs32bitProcess(param_2);
          if (cVar3 == '\0') {
            iVar6 = *(int *)(*(longlong *)(param_2 + 0x18) + 0x20);
          }
          else {
            iVar6 = *(int *)(*(longlong *)(param_2 + 0x18) + 0x18);
          }
          uVar5 = (ulonglong)(iVar6 + (uint)bVar1);
        }
        *(ulonglong *)(param_2 + 0x38) = uVar5;
        return 0;
      }
    }
  }
  return 0xc0000023;
}



===== nvrIoctlScsiPassThrough @ 0001ea28 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong nvrIoctlScsiPassThrough(longlong param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  longlong lVar2;
  int iVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 auStack_e8 [32];
  undefined8 local_c8;
  undefined1 local_b8 [32];
  undefined4 local_98;
  undefined1 local_94;
  undefined1 local_8e;
  char local_8d;
  uint local_8c;
  uint local_88;
  undefined4 local_84;
  longlong local_80;
  longlong local_78;
  longlong local_68;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_e8;
  if (((*(char *)(param_3 + 7) != '\0') && (*(uint *)(param_3 + 0x20) < 0x38)) ||
     ((*(int *)(param_3 + 0xc) != 0 &&
      ((*(longlong *)(param_3 + 0x18) == 0 ||
       ((*(int *)(param_3 + 0xc) != 0 && (*(char *)(param_3 + 8) == '\x02')))))))) {
    return 0xc000000d;
  }
  lVar4 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c));
  if (lVar4 == 0) {
    return 0xc000009a;
  }
  memset(&local_98,0,0x58);
  local_8e = *(undefined1 *)(param_3 + 6);
  local_50 = *(undefined4 *)(param_3 + 0x24);
  uStack_4c = *(undefined4 *)(param_3 + 0x28);
  uStack_48 = *(undefined4 *)(param_3 + 0x2c);
  uStack_44 = *(undefined4 *)(param_3 + 0x30);
  cVar1 = *(char *)(param_3 + 8);
  local_84 = *(undefined4 *)(param_3 + 0x10);
  local_98 = 0x58;
  local_94 = 0;
  local_68 = param_2;
  if (cVar1 == '\0') {
    local_8c = local_8c | 0x180;
  }
  else if (cVar1 == '\x01') {
    local_8c = local_8c | 0x140;
  }
  else {
    if (cVar1 != '\x02') {
      uVar6 = 0xc000000d;
      local_8c = local_8c | 0x100;
      goto LAB_0001ec1b;
    }
    local_8c = local_8c | 0x1c0;
  }
  local_8d = *(char *)(param_3 + 7);
  if (local_8d == '\0') {
    local_78 = 0;
  }
  else {
    local_78 = (ulonglong)*(uint *)(param_3 + 0x20) + *(longlong *)(param_2 + 0x18);
  }
  local_88 = *(uint *)(param_3 + 0xc);
  if (local_88 == 0) {
    local_80 = 0;
  }
  else {
    uVar5 = nvrAllocateAndLockMdl
                      (*(undefined8 *)(param_3 + 0x18),(ulonglong)local_88,~(local_8c >> 7) & 1,
                       (longlong *)(lVar4 + 8));
    uVar6 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) goto LAB_0001ec1b;
    local_80 = (ulonglong)*(uint *)(*(longlong *)(lVar4 + 8) + 0x2c) +
               *(longlong *)(*(longlong *)(lVar4 + 8) + 0x20);
  }
  KeInitializeEvent(local_b8,1);
  lVar2 = *(longlong *)(lVar4 + 0xb8);
  *(code **)(lVar2 + -0x10) = IoctlScsiPassThroughCompletion;
  *(undefined1 *)(lVar2 + -0x45) = 0xe0;
  *(undefined1 **)(lVar2 + -8) = local_b8;
  lVar2 = *(longlong *)(lVar4 + 0xb8);
  *(undefined1 *)(lVar2 + -0x48) = 0xf;
  *(undefined4 **)(lVar2 + -0x40) = &local_98;
  local_68 = lVar4;
  iVar3 = IofCallDriver(param_1,lVar4);
  if (iVar3 == 0x103) {
    local_c8 = 0;
    KeWaitForSingleObject(local_b8,0,0,0);
  }
  *(uint *)(param_3 + 0xc) = local_88;
  *(char *)(param_3 + 7) = local_8d;
  *(undefined1 *)(param_3 + 2) = local_94;
  if (*(longlong *)(lVar4 + 8) != 0) {
    MmUnlockPages();
    IoFreeMdl(*(undefined8 *)(lVar4 + 8));
    *(undefined8 *)(lVar4 + 8) = 0;
  }
  uVar6 = 0;
LAB_0001ec1b:
  IoFreeIrp(lVar4);
  return uVar6;
}



===== nvrAllocateAndLockMdl @ 0001ec4c =====

undefined8
nvrAllocateAndLockMdl(undefined8 param_1,undefined8 param_2,undefined4 param_3,longlong *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = IoAllocateMdl(param_1,param_2,0,0,0);
  *param_4 = lVar1;
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    MmProbeAndLockPages(lVar1,0,param_3);
    uVar2 = 0;
  }
  return uVar2;
}



===== nvrGetScsiPassThroughLengths @ 0001eca8 =====

void nvrGetScsiPassThroughLengths(longlong param_1,longlong *param_2,ulonglong *param_3)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  ulonglong uVar4;
  int iVar5;
  
  IoIs32bitProcess();
  if (*(char *)(*(longlong *)(param_1 + 0x18) + 8) == '\x01') {
    IoIs32bitProcess();
    if ((*(char *)(*(longlong *)(param_1 + 0x18) + 7) == '\0') &&
       (IoIs32bitProcess(param_1), *(int *)(*(longlong *)(param_1 + 0x18) + 0xc) == 0)) {
      *param_3 = 0x38;
    }
    else {
      IoIs32bitProcess(param_1);
      bVar1 = *(byte *)(*(longlong *)(param_1 + 0x18) + 7);
      cVar3 = IoIs32bitProcess(param_1);
      if (cVar3 == '\0') {
        iVar5 = *(int *)(*(longlong *)(param_1 + 0x18) + 0x20);
      }
      else {
        iVar5 = *(int *)(*(longlong *)(param_1 + 0x18) + 0x18);
      }
      IoIs32bitProcess(param_1);
      uVar2 = *(uint *)(*(longlong *)(param_1 + 0x18) + 0xc);
      cVar3 = IoIs32bitProcess(param_1);
      if (cVar3 == '\0') {
        uVar4 = *(ulonglong *)(*(longlong *)(param_1 + 0x18) + 0x18);
      }
      else {
        uVar4 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x18) + 0x14);
      }
      if ((ulonglong)(iVar5 + (uint)bVar1) < uVar2 + uVar4) {
        IoIs32bitProcess(param_1);
        uVar2 = *(uint *)(*(longlong *)(param_1 + 0x18) + 0xc);
        cVar3 = IoIs32bitProcess(param_1);
        if (cVar3 == '\0') {
          uVar4 = *(ulonglong *)(*(longlong *)(param_1 + 0x18) + 0x18);
        }
        else {
          uVar4 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x18) + 0x14);
        }
        *param_3 = uVar2 + uVar4;
      }
      else {
        IoIs32bitProcess();
        bVar1 = *(byte *)(*(longlong *)(param_1 + 0x18) + 7);
        cVar3 = IoIs32bitProcess(param_1);
        if (cVar3 == '\0') {
          iVar5 = *(int *)(*(longlong *)(param_1 + 0x18) + 0x20);
        }
        else {
          iVar5 = *(int *)(*(longlong *)(param_1 + 0x18) + 0x18);
        }
        *param_3 = (ulonglong)(iVar5 + (uint)bVar1);
      }
    }
    goto LAB_0001ed1c;
  }
  IoIs32bitProcess(param_1);
  if (*(char *)(*(longlong *)(param_1 + 0x18) + 8) == '\0') {
    IoIs32bitProcess();
    if (*(char *)(*(longlong *)(param_1 + 0x18) + 7) == '\0') {
LAB_0001ee7a:
      *param_3 = 0x38;
    }
    else {
LAB_0001eeed:
      IoIs32bitProcess(param_1);
      bVar1 = *(byte *)(*(longlong *)(param_1 + 0x18) + 7);
      cVar3 = IoIs32bitProcess(param_1);
      if (cVar3 == '\0') {
        iVar5 = *(int *)(*(longlong *)(param_1 + 0x18) + 0x20);
      }
      else {
        iVar5 = *(int *)(*(longlong *)(param_1 + 0x18) + 0x18);
      }
      *param_3 = (ulonglong)(iVar5 + (uint)bVar1);
    }
  }
  else {
    IoIs32bitProcess(param_1);
    if ((*(char *)(*(longlong *)(param_1 + 0x18) + 7) == '\0') &&
       (IoIs32bitProcess(param_1), *(int *)(*(longlong *)(param_1 + 0x18) + 0xc) == 0))
    goto LAB_0001ee7a;
    IoIs32bitProcess(param_1);
    bVar1 = *(byte *)(*(longlong *)(param_1 + 0x18) + 7);
    cVar3 = IoIs32bitProcess(param_1);
    if (cVar3 == '\0') {
      iVar5 = *(int *)(*(longlong *)(param_1 + 0x18) + 0x20);
    }
    else {
      iVar5 = *(int *)(*(longlong *)(param_1 + 0x18) + 0x18);
    }
    IoIs32bitProcess(param_1);
    uVar2 = *(uint *)(*(longlong *)(param_1 + 0x18) + 0xc);
    cVar3 = IoIs32bitProcess(param_1);
    if (cVar3 == '\0') {
      uVar4 = *(ulonglong *)(*(longlong *)(param_1 + 0x18) + 0x18);
    }
    else {
      uVar4 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x18) + 0x14);
    }
    if (uVar2 + uVar4 <= (ulonglong)(iVar5 + (uint)bVar1)) goto LAB_0001eeed;
    IoIs32bitProcess(param_1);
    uVar2 = *(uint *)(*(longlong *)(param_1 + 0x18) + 0xc);
    cVar3 = IoIs32bitProcess(param_1);
    if (cVar3 == '\0') {
      uVar4 = *(ulonglong *)(*(longlong *)(param_1 + 0x18) + 0x18);
    }
    else {
      uVar4 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x18) + 0x14);
    }
    *param_3 = uVar2 + uVar4;
  }
  IoIs32bitProcess(param_1);
  if (*(int *)(*(longlong *)(param_1 + 0x18) + 0xc) != 0) {
    IoIs32bitProcess(param_1);
    uVar2 = *(uint *)(*(longlong *)(param_1 + 0x18) + 0xc);
    cVar3 = IoIs32bitProcess(param_1);
    if (cVar3 == '\0') {
      uVar4 = *(ulonglong *)(*(longlong *)(param_1 + 0x18) + 0x18);
    }
    else {
      uVar4 = (ulonglong)*(uint *)(*(longlong *)(param_1 + 0x18) + 0x14);
    }
    *param_2 = uVar2 + uVar4;
    return;
  }
LAB_0001ed1c:
  *param_2 = 0x38;
  return;
}



===== IoctlScsiPassThroughCompletion @ 0001efa4 =====

undefined8 IoctlScsiPassThroughCompletion(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== IoctlScsiGetCapabilities @ 0001efc0 =====

undefined8 IoctlScsiGetCapabilities(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (*(uint *)(*(longlong *)(param_2 + 0xb8) + 8) < 0x18) {
    return 0xc0000023;
  }
  puVar2 = *(undefined4 **)(param_2 + 0x18);
  *puVar2 = 0x18;
  puVar2[1] = 0x40000;
  *(undefined8 *)(puVar2 + 2) = 0x41;
  uVar1 = *(undefined4 *)(param_1 + 0x98);
  *(undefined2 *)(puVar2 + 5) = 0;
  *(undefined1 *)((longlong)puVar2 + 0x16) = 1;
  puVar2[4] = uVar1;
  *(undefined8 *)(param_2 + 0x38) = 0x18;
  return 0;
}



===== IoctlStorageQueryDeviceIdProperty @ 0001f010 =====

undefined8 IoctlStorageQueryDeviceIdProperty(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined4 *_Dst;
  longlong lVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  _Dst = *(undefined4 **)(param_2 + 0x18);
  uVar4 = 0;
  uVar3 = 0;
  if (_Dst[1] == 0) {
    lVar2 = *(longlong *)(**(longlong **)(*(longlong *)(param_1 + 0x40) + 0x60) + 0x58);
    uVar1 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
    if (uVar1 < 8) {
      uVar3 = 0xc000000d;
      uVar4 = 0xc000000d;
    }
    else {
      if (uVar1 < 0x2a) {
        memset(_Dst,0,(ulonglong)uVar1);
        *_Dst = 0x10;
        _Dst[1] = 0x2a;
        *(undefined8 *)(param_2 + 0x38) = 8;
      }
      else {
        memset(_Dst,0,0x2a);
        *_Dst = 0x10;
        _Dst[1] = 0x2a;
        _Dst[2] = 1;
        _Dst[3] = 1;
        _Dst[4] = 2;
        *(undefined2 *)(_Dst + 5) = 8;
        _Dst[6] = 0;
        *(undefined2 *)(_Dst + 7) = 0x400;
        *(undefined1 *)((longlong)_Dst + 0x1e) = 0x4b;
        *(undefined4 *)((longlong)_Dst + 0x1f) = *(undefined4 *)(lVar2 + 4);
        *(undefined1 *)((longlong)_Dst + 0x23) = *(undefined1 *)(lVar2 + 8);
        *(undefined8 *)(param_2 + 0x38) = 0x2a;
      }
      uVar4 = 0;
    }
    *(undefined4 *)(param_2 + 0x30) = uVar3;
  }
  else if (_Dst[1] != 1) {
    uVar4 = 0xc000000d;
  }
  return uVar4;
}



===== NvRaidSyncAtomicSpinLockAcquire @ 0001f104 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void NvRaidSyncAtomicSpinLockAcquire(void)

{
  int iVar1;
  void *pvVar2;
  byte in_CR8;
  
  pvVar2 = SystemReserved1[0xf];
  if (in_CR8 < 3) {
    LOCK();
    iVar1 = DAT_00029214 + 1;
    UNLOCK();
    if ((DAT_00029214 + 1 + _DAT_00029218 == 1) ||
       (DAT_00029214 = iVar1, SystemReserved1[0xf] != DAT_00029220)) {
      DAT_00029214 = iVar1;
      DAT_00029210 = KeAcquireSpinLockRaiseToDpc(&DAT_00029208);
      DAT_00029220 = pvVar2;
    }
    LOCK();
    DAT_00029214 = DAT_00029214 + -1;
    UNLOCK();
    _DAT_00029218 = _DAT_00029218 + 1;
  }
  return;
}



===== NvRaidSyncAtomicSpinLockRelease @ 0001f16c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void NvRaidSyncAtomicSpinLockRelease(void)

{
  byte in_CR8;
  
  if ((in_CR8 < 3) && (_DAT_00029218 = _DAT_00029218 + -1, _DAT_00029218 == 0)) {
    DAT_00029220 = 0;
    KeReleaseSpinLock(&DAT_00029208,DAT_00029210);
  }
  return;
}



===== nvideRaidInitialize @ 0001f1a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nvideRaidInitialize(void)

{
  int iVar1;
  longlong lVar2;
  undefined1 local_res8 [8];
  undefined8 local_res10;
  undefined1 local_48 [16];
  undefined4 local_38 [2];
  longlong local_30;
  undefined2 *local_28;
  undefined4 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  DAT_00029088 = (undefined4)((ulonglong)_DAT_fffff78000000014 >> 8);
  KeInitializeSpinLock(&DAT_00029208);
  DAT_00029230 = &DAT_00029228;
  DAT_00029228 = &DAT_00029228;
  _DAT_00029214 = 0;
  KeInitializeSpinLock(&DAT_00029238);
  DAT_00029240 = 1;
  DAT_00029244 = 1;
  NvRaidApiInitializeRaidSystem(&RaidSystem,0,(undefined4 *)0x0,0);
  if (NvRaidRegistryPath != 0) {
    local_38[0] = 0x30;
    local_30 = 0;
    local_28 = &NvRaidRegistryPath;
    local_20 = 0x240;
    local_18 = 0;
    local_10 = 0;
    iVar1 = ZwOpenKey(&local_res10,0xf003f,local_38);
    if (-1 < iVar1) {
      lVar2 = ExAllocatePoolWithTag(1,0x14,0x644e7652);
      if (lVar2 != 0) {
        RtlInitUnicodeString(local_48,L"SgpioControl");
        iVar1 = ZwQueryValueKey(local_res10,local_48,2,lVar2,0x14,local_res8);
        if (-1 < iVar1) {
          if ((*(byte *)(lVar2 + 0xc) & 1) == 0) {
            _DAT_000299c8 = _DAT_000299c8 & 0xfffffffd;
          }
          else {
            _DAT_000299c8 = _DAT_000299c8 | 2;
          }
        }
        RtlInitUnicodeString(local_48,L"DisableRemoveable");
        iVar1 = ZwQueryValueKey(local_res10,local_48,2,lVar2,0x14,local_res8);
        if (-1 < iVar1) {
          if (*(char *)(lVar2 + 0xc) == '\0') {
            _gWindowsFlags = _gWindowsFlags | 1;
          }
          else {
            _gWindowsFlags = _gWindowsFlags & 0xfffffffe;
          }
        }
        ExFreePoolWithTag(lVar2,0);
        if (local_30 != 0) {
          ZwClose();
        }
        ZwClose(local_res10);
      }
    }
  }
  _DAT_000299c0 = FUN_00022838;
  KeInitializeEvent(&DAT_000291f0,1);
  _DAT_000290d0 = &LAB_0001f3ac;
  DAT_000290c8 = FUN_0001f9ec;
  return;
}



===== nvrideRegistIdeDisk @ 0001f3c0 =====

void nvrideRegistIdeDisk(longlong param_1)

{
  undefined4 *puVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  void *_Dst;
  undefined1 *puVar9;
  undefined1 *puVar10;
  uint *_Dst_00;
  undefined8 *puVar11;
  ulonglong in_stack_ffffffffffffffc8;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  plVar3 = *(longlong **)(lVar2 + 0x60);
  puVar9 = (undefined1 *)0x0;
  if (*plVar3 != 0) {
    return;
  }
  NvRaidApiCreateVolume(0x298e0,plVar3);
  _Dst = (void *)ExAllocatePoolWithTag(0,0x58,0x644e7652);
  if (_Dst == (void *)0x0) {
LAB_0001f425:
    iVar8 = -0x3fffff66;
  }
  else {
    memset(_Dst,0,0x58);
    *(undefined1 *)((longlong)_Dst + 10) = 6;
    *(undefined4 *)((longlong)_Dst + 0x14) = *(undefined4 *)(lVar2 + 0x248);
    *(undefined1 *)((longlong)_Dst + 0x48) = 0x25;
    puVar9 = (undefined1 *)ExAllocatePoolWithTag(0,0x68,0x644e7652);
    if (puVar9 == (undefined1 *)0x0) goto LAB_0001f425;
    in_stack_ffffffffffffffc8 = in_stack_ffffffffffffffc8 & 0xffffffffffffff00;
    iVar8 = ClassSendSrbSynchronous(param_1,_Dst,puVar9,8,in_stack_ffffffffffffffc8);
    if (-1 < iVar8) {
      *(undefined1 *)(*plVar3 + 0x70) = 1;
      *(longlong *)(*plVar3 + 0x10) = param_1;
      *(undefined1 *)(*plVar3 + 0x20) = puVar9[3];
      *(undefined1 *)(*plVar3 + 0x21) = puVar9[2];
      *(undefined1 *)(*plVar3 + 0x22) = puVar9[1];
      *(undefined1 *)(*plVar3 + 0x23) = *puVar9;
      *(undefined1 *)(*plVar3 + 0x28) = puVar9[7];
      *(undefined1 *)(*plVar3 + 0x29) = puVar9[6];
      *(undefined1 *)(*plVar3 + 0x2a) = puVar9[5];
      *(undefined1 *)(*plVar3 + 0x2b) = puVar9[4];
      if (*(ulonglong *)(*plVar3 + 0x20) < 0xffffffff) {
LAB_0001f5ea:
        *(longlong *)(*plVar3 + 0x20) = *(longlong *)(*plVar3 + 0x20) + 1;
        *(undefined ***)(*plVar3 + 0x60) = &PTR_NvRaidVolumeDefaultCleanup_00027dc8;
        *(uint *)(*plVar3 + 4) = *(uint *)(*plVar3 + 4) | 0x100;
        _Dst_00 = (uint *)ExAllocatePoolWithTag(0,0x38,0x644e7652);
        if (_Dst_00 == (uint *)0x0) goto LAB_0001f425;
        memset(_Dst_00,0,0x38);
        *_Dst_00 = 0x1c;
        memcpy(_Dst_00 + 1,"SCSIDISK",8);
        _Dst_00[3] = *(uint *)(lVar2 + 0x248);
        _Dst_00[6] = 0x1c;
        _Dst_00[4] = 0x1b0800;
        puVar11 = (undefined8 *)((ulonglong)*_Dst_00 + (longlong)_Dst_00);
        iVar8 = NvRaidOsSendSrbControl
                          (*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x10),(longlong)_Dst_00);
        if (-1 < iVar8) {
          lVar4 = *plVar3;
          *(undefined8 *)(lVar4 + 0x2c) = *puVar11;
          *(undefined8 *)(lVar4 + 0x34) = puVar11[1];
          *(undefined8 *)(lVar4 + 0x3c) = puVar11[2];
          *(undefined4 *)(lVar4 + 0x44) = *(undefined4 *)(puVar11 + 3);
          *(undefined8 *)
           ((ulonglong)*(uint *)(*(longlong *)(lVar2 + 0x208) + 0xc) + *(longlong *)(lVar2 + 0x208))
               = *(undefined8 *)(*plVar3 + 0x2c);
          lVar4 = *plVar3;
          uVar5 = *(undefined4 *)(lVar4 + 0x38);
          uVar6 = *(undefined4 *)(lVar4 + 0x3c);
          uVar7 = *(undefined4 *)(lVar4 + 0x40);
          puVar1 = (undefined4 *)
                   ((ulonglong)*(uint *)(*(longlong *)(lVar2 + 0x208) + 0x10) +
                   *(longlong *)(lVar2 + 0x208));
          *puVar1 = *(undefined4 *)(lVar4 + 0x34);
          puVar1[1] = uVar5;
          puVar1[2] = uVar6;
          puVar1[3] = uVar7;
          *(undefined4 *)
           ((ulonglong)*(uint *)(*(longlong *)(lVar2 + 0x208) + 0x14) + *(longlong *)(lVar2 + 0x208)
           ) = *(undefined4 *)(*plVar3 + 0x44);
        }
        ExFreePoolWithTag(_Dst_00,0);
      }
      else {
        memset(_Dst,0,0x58);
        *(undefined1 *)((longlong)_Dst + 10) = 10;
        *(undefined4 *)((longlong)_Dst + 0x14) = *(undefined4 *)(lVar2 + 0x248);
        *(undefined1 *)((longlong)_Dst + 0x48) = 0x9e;
        puVar10 = (undefined1 *)ExAllocatePoolWithTag(0,0xc,0x644e7652);
        if (puVar10 == (undefined1 *)0x0) goto LAB_0001f425;
        iVar8 = ClassSendSrbSynchronous
                          (param_1,_Dst,puVar10,0xc,in_stack_ffffffffffffffc8 & 0xffffffffffffff00);
        if (-1 < iVar8) {
          *(undefined1 *)(*plVar3 + 0x20) = puVar10[7];
          *(undefined1 *)(*plVar3 + 0x21) = puVar10[6];
          *(undefined1 *)(*plVar3 + 0x22) = puVar10[5];
          *(undefined1 *)(*plVar3 + 0x23) = puVar10[4];
          *(undefined1 *)(*plVar3 + 0x24) = puVar10[3];
          *(undefined1 *)(*plVar3 + 0x25) = puVar10[2];
          *(undefined1 *)(*plVar3 + 0x26) = puVar10[1];
          *(undefined1 *)(*plVar3 + 0x27) = *puVar10;
          *(undefined1 *)(*plVar3 + 0x28) = puVar10[0xb];
          *(undefined1 *)(*plVar3 + 0x29) = puVar10[10];
          *(undefined1 *)(*plVar3 + 0x2a) = puVar10[9];
          *(undefined1 *)(*plVar3 + 0x2b) = puVar10[8];
          ExFreePoolWithTag(puVar10,0);
          goto LAB_0001f5ea;
        }
        ExFreePoolWithTag(puVar10,0);
      }
      if (-1 < iVar8) goto LAB_0001f709;
    }
  }
  if ((undefined4 *)*plVar3 != (undefined4 *)0x0) {
    NvRaidApiDestroyVolume(0x298e0,(undefined4 *)*plVar3);
  }
LAB_0001f709:
  if (puVar9 != (undefined1 *)0x0) {
    ExFreePoolWithTag(puVar9,0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
  if (-1 < iVar8) {
    KeResetEvent(&DAT_000291f0);
    lVar4 = *plVar3;
    if (((*(uint *)(lVar4 + 4) & 0x10) != 0) &&
       (NvRaidVolumeAddVolumeToArray(0x298e0,lVar4,0xff), *(longlong *)(lVar4 + 0x58) == 0)) {
      NvRaidVolumeProbeArrayInfo(lVar4);
    }
    KeWaitForSingleObject(&DAT_000291f0,0,0,0,0);
    IoInvalidateDeviceRelations(*(undefined8 *)(lVar2 + 0x200),3);
  }
  return;
}



===== nvrProcessRemovalForRaidDiskFdo @ 0001f7b0 =====

void nvrProcessRemovalForRaidDiskFdo(longlong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined8 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  
  plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x40) + 0x60);
  lVar3 = *plVar2;
  lVar4 = *(longlong *)(lVar3 + 0x50);
  uVar8 = NvRaidSyncSpinLockAcquire(0xffffffff);
  lVar5 = *(longlong *)(lVar4 + 0x58);
  if (((lVar5 == 0) || (3 < (byte)(*(char *)(lVar5 + 0x14) - 2U))) ||
     (((uint)*(byte *)(lVar5 + 0x16) < *(uint *)(lVar4 + 0x78) &&
      (*(byte *)(lVar5 + 0x16) <= *(byte *)(lVar3 + 8))))) {
    NvRaidSyncSpinLockRelease(uVar8);
  }
  else {
    if ((*(uint *)(lVar4 + 4) & 0x40) == 0) {
      NvRaidSyncSpinLockRelease(uVar8);
    }
    else {
      *(uint *)(lVar4 + 4) = *(uint *)(lVar4 + 4) | 0x10000;
      NvRaidSyncSpinLockRelease(uVar8);
      KeWaitForSingleObject(plVar2 + 0x2a,0,0,0,0);
    }
    NvRaidJobClearInformation(lVar4);
    if (*(longlong *)(lVar4 + 0x10) == 0) {
      lVar3 = *(longlong *)(lVar4 + 0x58);
      if ((lVar3 != 0) && (*(char *)(lVar3 + 0x14) == '\x02')) {
        uVar9 = *(uint *)(lVar3 + 0x98) & 0xfffffffe;
        LOCK();
        uVar8 = *(uint *)(lVar3 + 0x98);
        *(uint *)(lVar3 + 0x98) = uVar9;
        UNLOCK();
        uVar8 = uVar8 & 0xfffffffe;
        if (uVar8 != uVar9) {
          do {
            LOCK();
            uVar9 = *(uint *)(lVar3 + 0x98);
            *(uint *)(lVar3 + 0x98) = uVar8;
            UNLOCK();
            uVar9 = uVar9 & 0xfffffffe;
            bVar10 = uVar9 != uVar8;
            uVar8 = uVar9;
          } while (bVar10);
        }
      }
    }
    else {
      lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x40) + 0x60);
      uVar9 = *(uint *)(lVar3 + 0x1c) & 0xfffffffd;
      LOCK();
      uVar8 = *(uint *)(lVar3 + 0x1c);
      *(uint *)(lVar3 + 0x1c) = uVar9;
      UNLOCK();
      uVar8 = uVar8 & 0xfffffffd;
      if (uVar8 != uVar9) {
        do {
          LOCK();
          uVar9 = *(uint *)(lVar3 + 0x1c);
          *(uint *)(lVar3 + 0x1c) = uVar8;
          UNLOCK();
          uVar9 = uVar9 & 0xfffffffd;
          bVar10 = uVar9 != uVar8;
          uVar8 = uVar9;
        } while (bVar10);
      }
    }
  }
  lVar3 = *(longlong *)(param_1 + 0x40);
  puVar6 = *(undefined8 **)(lVar3 + 0x60);
  puVar7 = (undefined4 *)*puVar6;
  if (puVar7 != (undefined4 *)0x0) {
    *puVar6 = 0;
    puVar7[1] = puVar7[1] & 0xfffffff9 | 1;
    NvRaidApiDestroyVolume(0x298e0,puVar7);
    lVar3 = *(longlong *)(lVar3 + 0x240);
    if (lVar3 != 0) {
      ExFreePoolWithTag(lVar3,0);
    }
  }
  if (puVar6[0x29] != 0) {
    puVar1 = puVar6 + 0x28;
    IoSetDeviceInterfaceState(puVar1,0);
    RtlFreeUnicodeString(puVar1);
    RtlInitUnicodeString(puVar1,0);
    RtlFreeUnicodeString(puVar6 + 0x26);
    RtlInitUnicodeString(puVar6 + 0x26,0);
  }
  return;
}



===== nvrideRaidScsiTimer @ 0001f97c =====

void nvrideRaidScsiTimer(longlong param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  
  if ((*(byte *)(*(longlong *)(param_1 + 0x40) + 0x340) & 1) != 0) {
    lVar3 = IoAllocateWorkItem();
    if (lVar3 != 0) {
      IoQueueWorkItem(lVar3,nvrScsiPortPassThroughEnable_worker,1,lVar3);
    }
  }
  uVar1 = NvRaidSyncSpinLockAcquire(2);
  if ((DAT_000290b4 & 2) == 0) {
    uVar2 = DAT_000290b4 | 2;
    while( true ) {
      uVar4 = uVar2;
      LOCK();
      UNLOCK();
      uVar2 = DAT_000290b4 | 2;
      DAT_000290b4 = uVar4;
      if (uVar2 == uVar4) break;
    }
  }
  NvRaidSyncSpinLockRelease(uVar1);
  return;
}



===== FUN_0001f9ec @ 0001f9ec =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001f9ec(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong *plVar4;
  
  uVar1 = NvRaidSyncSpinLockAcquire(2);
  do {
    plVar4 = DAT_00029980;
    while( true ) {
      if (plVar4 == (longlong *)0x0) {
        if ((DAT_000290b4 & 8) == 0) {
          uVar2 = DAT_000290b4 | 8;
          while( true ) {
            uVar3 = uVar2;
            LOCK();
            UNLOCK();
            uVar2 = DAT_000290b4 | 8;
            DAT_000290b4 = uVar3;
            if (uVar2 == uVar3) break;
          }
        }
        NvRaidSyncSpinLockRelease(uVar1);
        return;
      }
      if ((int)plVar4[4] == 0) break;
      *(int *)(plVar4 + 4) = (int)plVar4[4] + -1;
      plVar4 = (longlong *)*plVar4;
    }
    if (*plVar4 == 0) {
      _DAT_00029988 = plVar4[1];
    }
    else {
      *(longlong *)(*plVar4 + 8) = plVar4[1];
    }
    *(longlong *)plVar4[1] = *plVar4;
    (*(code *)plVar4[2])(plVar4[3]);
    *(undefined4 *)plVar4 = 0x30;
    plVar4[1] = (longlong)DAT_00029990;
    DAT_00029990 = plVar4;
  } while( true );
}



===== nvrEnumerateRaidVolume @ 0001fa98 =====

ulonglong nvrEnumerateRaidVolume(longlong param_1)

{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  undefined4 local_res8 [2];
  longlong local_res10;
  longlong local_res18;
  
  lVar8 = *(longlong *)(param_1 + 0x40);
  local_res10 = 0;
  bVar3 = false;
  uVar5 = 0;
  lVar9 = scsiRaidController;
  if ((*(byte *)(*(longlong *)(lVar8 + 0x60) + 0xe0) & 1) == 0) {
    uVar5 = 0xc0000010;
  }
  else {
LAB_0001fad8:
    NvRaidApiEnumerateRootVolumes(0x298e0,&local_res10);
    lVar4 = local_res10;
    if (local_res10 != 0) {
      if (*(longlong *)(local_res10 + 0x58) != 0) {
        if (((*(uint *)(local_res10 + 4) & 1) == 0) && ((*(uint *)(local_res10 + 4) >> 8 & 1) == 0))
        {
          lVar6 = local_res10;
        }
        else {
          lVar6 = 0;
        }
        if (lVar6 != 0) {
          if (*(longlong *)(local_res10 + 0x10) == 0) {
            if (((lVar9 == 0) || (*(char *)(*(longlong *)(local_res10 + 0x58) + 0x14) == '\x02')) ||
               (*(int *)(*(longlong *)(lVar9 + 0x40) + 0x344) != 0)) goto LAB_0001fad8;
            uVar7 = nvrCreatePdo(param_1,local_res10,&local_res18);
            uVar5 = uVar7 & 0xffffffff;
            lVar9 = scsiRaidController;
            if ((int)uVar7 < 0) goto LAB_0001fad8;
            local_res8[0] = 3;
            bVar3 = true;
            *(longlong *)(lVar4 + 0x10) = local_res18;
            NvRaidVolumeSendCommandToVolumes(lVar4,nvrPdoIoInvalidateDeviceRelations,local_res8);
          }
          pbVar1 = (byte *)(*(longlong *)(*(longlong *)(*(longlong *)(lVar4 + 0x10) + 0x40) + 0x60)
                           + 0x1c);
          *pbVar1 = *pbVar1 | 1;
          lVar9 = scsiRaidController;
        }
      }
      goto LAB_0001fad8;
    }
    lVar8 = *(longlong *)(lVar8 + 0x80);
    if (lVar8 != 0) {
      do {
        bVar2 = *(byte *)(*(longlong *)(lVar8 + 0x60) + 0x1c);
        if ((bVar2 & 1) == 0) {
          nvrClassMarkChildMissing(lVar8);
        }
        else {
          *(byte *)(*(longlong *)(lVar8 + 0x60) + 0x1c) = bVar2 & 0xfe;
        }
        lVar8 = *(longlong *)(lVar8 + 0x80);
      } while (lVar8 != 0);
      lVar9 = scsiRaidController;
    }
    if (((bVar3) && (lVar9 != 0)) && (*(longlong *)(*(longlong *)(lVar9 + 0x40) + 0x328) != 0)) {
      IoInvalidateDeviceState();
    }
  }
  return uVar5;
}



===== FUN_0001fbf8 @ 0001fbf8 =====

void FUN_0001fbf8(undefined8 param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  uVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_00029238);
  plVar1 = (longlong *)(param_2 + 0xa8);
  lVar2 = *plVar1;
  plVar3 = *(longlong **)(param_2 + 0xb0);
  if ((*(longlong **)(lVar2 + 8) == plVar1) && ((longlong *)*plVar3 == plVar1)) {
    *plVar3 = lVar2;
    *(longlong **)(lVar2 + 8) = plVar3;
    KeReleaseSpinLock(&DAT_00029238,CONCAT71((int7)((ulonglong)plVar1 >> 8),uVar5));
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
                    /* WARNING: Could not recover jumptable at 0x0001fc6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    ClassCompleteRequest(param_1,param_2,0);
    return;
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== FUN_0001fc7c @ 0001fc7c =====

ulonglong FUN_0001fc7c(int param_1,undefined8 *param_2)

{
  longlong lVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  uint uVar8;
  bool bVar9;
  
  uVar8 = 0x103;
  if (param_1 != 0) {
    bVar9 = param_2 != (undefined8 *)0x0;
    uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_00029238);
    puVar3 = DAT_00029228;
    while (DAT_00029228 = puVar3, DAT_00029244 != 0) {
      if (param_2 == (undefined8 *)0x0) {
        if ((undefined8 **)puVar3 == &DAT_00029228) break;
        DAT_00029228 = (undefined8 *)*puVar3;
        if (((undefined8 **)puVar3[1] != &DAT_00029228) || ((undefined8 *)DAT_00029228[1] != puVar3)
           ) {
          pcVar2 = (code *)swi(0x29);
          DAT_00029228 = puVar3;
          (*pcVar2)(3,uVar4);
          pcVar2 = (code *)swi(3);
          uVar7 = (*pcVar2)();
          return uVar7;
        }
        param_2 = puVar3 + -0x15;
        DAT_00029228[1] = &DAT_00029228;
        LOCK();
        lVar1 = puVar3[-8];
        puVar3[-8] = 0;
        UNLOCK();
        if (lVar1 != 0) {
          if (param_2 != (undefined8 *)0x0) goto LAB_0001fd32;
          break;
        }
      }
      else {
LAB_0001fd32:
        DAT_00029244 = 0;
        KeReleaseSpinLock();
        lVar1 = param_2[0x17];
        uVar5 = NvRaidSyncSpinLockAcquire(0xffffffff);
        uVar6 = FUN_0001ff28(*(longlong *)(lVar1 + 0x28),*(longlong *)(lVar1 + 8));
        NvRaidSyncSpinLockRelease(uVar5);
        if (bVar9) {
          bVar9 = false;
          uVar8 = uVar6;
        }
        uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_00029238);
      }
      param_2 = (undefined8 *)0x0;
      puVar3 = DAT_00029228;
    }
    DAT_00029240 = 1;
    KeReleaseSpinLock(&DAT_00029238);
  }
  return (ulonglong)uVar8;
}



===== FUN_0001fdd4 @ 0001fdd4 =====

void FUN_0001fdd4(void)

{
  int iVar1;
  
  KeAcquireSpinLockRaiseToDpc(&DAT_00029238);
  iVar1 = DAT_00029240;
  DAT_00029240 = 0;
  DAT_00029244 = 1;
  KeReleaseSpinLock(&DAT_00029238);
  FUN_0001fc7c(iVar1,(undefined8 *)0x0);
  return;
}



===== nvrDispatchScsi @ 0001fe1c =====

undefined4 nvrDispatchScsi(undefined8 param_1,undefined8 *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined4 uVar10;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  iVar9 = 0;
  uVar3 = KeAcquireSpinLockRaiseToDpc(&DAT_00029238);
  iVar2 = DAT_00029240;
  puVar7 = auStack_28;
  DAT_00029240 = 0;
  if ((iVar2 == 0) || (puVar8 = auStack_28, DAT_00029244 == 0)) {
    if (*(char *)((longlong)param_2 + 0x44) != '\0') {
      DAT_00029240 = iVar2;
      KeReleaseSpinLock(&DAT_00029238);
      param_2[7] = 0;
      *(undefined4 *)(param_2 + 6) = 0xc0000120;
      ClassCompleteRequest(param_1,param_2,0);
      return 0xc0000120;
    }
    *(byte *)(param_2[0x17] + 3) = *(byte *)(param_2[0x17] + 3) | 1;
    puVar6 = DAT_00029230;
    puVar4 = param_2 + 0x15;
    *puVar4 = &DAT_00029228;
    param_2[0x16] = puVar6;
    if ((undefined8 *)*puVar6 != &DAT_00029228) {
      puVar6 = (undefined8 *)0x3;
      pcVar1 = (code *)swi(0x29);
      puVar4 = (undefined8 *)(*pcVar1)(3,uVar3);
      puVar7 = auStack_20;
    }
    *puVar6 = puVar4;
    LOCK();
    DAT_00029230 = puVar4;
    param_2[0xd] = FUN_0001fbf8;
    UNLOCK();
    param_2 = (undefined8 *)0x0;
    iVar9 = 0x103;
    puVar8 = puVar7;
  }
  *(undefined8 *)(puVar8 + -8) = 0x1fefc;
  KeReleaseSpinLock(&DAT_00029238);
  *(undefined8 *)(puVar8 + -8) = 0x1ff06;
  uVar5 = FUN_0001fc7c(iVar2,param_2);
  uVar10 = 0x103;
  if (iVar9 != 0x103) {
    uVar10 = (int)uVar5;
  }
  return uVar10;
}



===== FUN_0001ff28 @ 0001ff28 =====

int FUN_0001ff28(longlong param_1,longlong param_2)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  char cVar4;
  longlong *plVar5;
  longlong lVar6;
  code *pcVar7;
  undefined1 uVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  undefined1 *puVar12;
  int iVar13;
  longlong *plVar14;
  undefined8 *puVar15;
  bool bVar16;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  longlong local_28;
  undefined8 local_20;
  
  plVar5 = *(longlong **)(*(longlong *)(param_1 + 0x40) + 0x60);
  *(undefined1 *)(param_2 + 5) = 0;
  *(undefined1 *)(param_2 + 3) = 1;
  iVar13 = 0;
  if (*plVar5 == 0) {
    iVar13 = -0x3ffffff2;
LAB_00020188:
    lVar6 = *(longlong *)(param_2 + 0x30);
    *(int *)(lVar6 + 0x30) = iVar13;
    ClassCompleteRequest(param_1,lVar6,0);
    bVar16 = true;
LAB_0002019e:
    puVar12 = auStack_48;
    if (!bVar16) {
      return iVar13;
    }
  }
  else {
    LOCK();
    iVar3 = *(int *)((longlong)plVar5 + 0x94);
    *(int *)((longlong)plVar5 + 0x94) = 0;
    UNLOCK();
    if (iVar3 != 0) {
      if (((byte)*(undefined4 *)(*plVar5 + 4) & 7) == 4) {
        if ((*(char *)(param_2 + 2) == '\0') && ((char)*(undefined4 *)(param_2 + 0xc) < '\0')) {
          lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
          *(undefined4 *)(lVar6 + 0x98) = 5;
          LOCK();
          piVar1 = (int *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60) + 0x18);
          *piVar1 = *piVar1 + 1;
          UNLOCK();
          if (*(char *)(lVar6 + 0x1c) < '\0') {
            LOCK();
            iVar3 = *(int *)(lVar6 + 0x9c);
            *(int *)(lVar6 + 0x9c) = 1;
            UNLOCK();
            if (iVar3 == 0) {
              IoStartTimer(param_1);
            }
          }
        }
        else {
          LOCK();
          *(undefined4 *)((longlong)plVar5 + 0x94) = 1;
          UNLOCK();
        }
      }
      else {
        FUN_00022f70(param_1);
      }
    }
    if (((int)plVar5[3] == 0) || ((*(uint *)(param_2 + 0xc) & 0x80000) != 0)) {
      if (((int)plVar5[1] < 2) || ((*(uint *)(param_2 + 0xc) & 0x80000) != 0)) {
        uVar8 = *(undefined1 *)(*plVar5 + 8);
        *(undefined1 *)(param_2 + 7) = 0;
        *(undefined1 *)(param_2 + 6) = uVar8;
        cVar4 = *(char *)(param_2 + 2);
        if (cVar4 != '\0') {
          if (cVar4 == '\x01') {
            *(longlong *)(param_2 + 0x18) = param_1;
            if ((*(byte *)((longlong)plVar5 + 0x1c) & 0x20) == 0) {
              *(byte *)((longlong)plVar5 + 0x1c) = *(byte *)((longlong)plVar5 + 0x1c) | 0x20;
              ObfReferenceObject(param_1);
            }
          }
          else if (cVar4 != '\x06') {
            if (cVar4 == '\a') {
              uVar10 = nvrOsShutdownPdo(param_1,*(longlong *)(param_2 + 0x30));
              iVar13 = (int)uVar10;
              bVar16 = true;
              goto LAB_0002015c;
            }
            if (cVar4 != '\b') {
              if (cVar4 == '\x18') {
                LOCK();
                piVar1 = (int *)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60) + 0x18);
                *piVar1 = *piVar1 + 1;
                UNLOCK();
              }
              else {
                if (cVar4 != '\x19') {
                  iVar13 = -0x3ffffff0;
                  *(undefined1 *)(param_2 + 3) = 6;
                  goto LAB_00020188;
                }
                nvrPdoUnlockQueue(param_1);
              }
            }
          }
LAB_00020169:
          if (*(char *)(param_2 + 0x48) != '\x03') {
            *(undefined1 *)(param_2 + 0xb) = 0;
          }
          goto LAB_00020188;
        }
        bVar16 = *(char *)(param_2 + 8) != -1;
        if (((*(byte *)((longlong)plVar5 + 0x1c) & 0x40) != 0) &&
           (*(char *)(param_2 + 0x48) == '\x1b')) goto LAB_00020169;
        uVar11 = FUN_00021330(param_1,param_2);
        iVar13 = (int)uVar11;
LAB_0002015c:
        if (iVar13 != 0x103) {
          if (iVar13 != 0) {
            if (iVar13 == -0x3fffff66) {
              *(undefined1 *)(param_2 + 3) = 0x30;
              *(undefined4 *)(param_2 + 0x40) = 0xc000009a;
            }
            goto LAB_00020188;
          }
          goto LAB_00020169;
        }
        goto LAB_0002019e;
      }
      if (*(int *)((longlong)plVar5 + 0xc) == 0) {
        local_20 = 0;
        local_28 = param_1;
        PoRequestPowerIrp(param_1,2,1,_guard_check_icall);
      }
    }
    puVar12 = auStack_48;
    lVar6 = *(longlong *)(param_2 + 0x30);
    plVar14 = plVar5 + 5;
    pbVar2 = (byte *)(*(longlong *)(lVar6 + 0xb8) + 3);
    *pbVar2 = *pbVar2 | 1;
    if ((char)plVar5[8] != '\0') {
      uVar8 = KeAcquireSpinLockRaiseToDpc(plVar5 + 7);
      puVar12 = auStack_48;
      if (*(char *)(lVar6 + 0x44) == '\0') {
        puVar15 = (undefined8 *)(lVar6 + 0xa8);
        LOCK();
        *(code **)(lVar6 + 0x68) = FUN_0001c7c4;
        UNLOCK();
        *(longlong **)(lVar6 + 0x78) = plVar14;
        puVar9 = (undefined8 *)plVar5[6];
        *(undefined8 **)(lVar6 + 0xb0) = puVar9;
        *puVar15 = plVar14;
        if ((longlong *)*puVar9 != plVar14) {
          pcVar7 = (code *)swi(0x29);
          puVar9 = (undefined8 *)(*pcVar7)(3,uVar8);
          puVar12 = auStack_40;
        }
        *puVar9 = puVar15;
        plVar5[6] = (longlong)puVar15;
      }
      else {
        *(undefined4 *)(lVar6 + 0x30) = 0xc0000120;
        *(undefined8 *)(lVar6 + 0x38) = 0;
        puVar12 = auStack_48;
      }
      *(undefined8 *)(puVar12 + -8) = 0x200a6;
      KeReleaseSpinLock(plVar5 + 7);
    }
    iVar13 = 0x103;
  }
  *(undefined8 *)(puVar12 + -8) = 0x201a8;
  FUN_0001fdd4();
  return iVar13;
}



===== FUN_000201cc @ 000201cc =====

undefined8 FUN_000201cc(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  if (((*(int *)(param_2 + 0x90) == 0) || (*(longlong *)(param_2 + 0xa8) == 0)) ||
     (*(ushort *)(*(longlong *)(param_2 + 0xa8) + 4) < 2)) {
    uVar1 = FUN_00020210(param_1,param_2);
    return uVar1;
  }
  *(undefined1 *)(param_2 + 0x56) = 0;
  *(undefined ***)(param_2 + 0x58) = &PTR_FUN_00027450;
  NvRaidPacketExecuteStateMachine(param_1,param_2);
  return 0;
}



===== FUN_00020210 @ 00020210 =====

undefined8 FUN_00020210(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  undefined8 uVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  
  bVar1 = *(byte *)(param_2 + 0x80);
  lVar2 = *(longlong *)(param_1 + 0x10);
  if (bVar1 == 0xfe) {
    bVar4 = *(byte *)(param_2 + 0x81);
  }
  else {
    bVar4 = bVar1;
  }
  uVar5 = (uint)bVar4;
  if (uVar5 < 0x36) {
    if (uVar5 == 0x35) {
      if (bVar1 == 0xfe) {
        uVar3 = *(undefined8 *)(param_2 + 0x88);
        *(undefined8 *)(param_2 + 0x80) = 0;
        *(undefined8 *)(param_2 + 0x88) = 0;
        *(undefined1 *)(param_2 + 0x80) = *(undefined1 *)(param_2 + 0x81);
        *(char *)(param_2 + 0x85) = (char)uVar3;
        *(char *)(param_2 + 0x88) = (char)*(undefined4 *)(param_2 + 0x90);
        *(char *)(param_2 + 0x82) = (char)((ulonglong)uVar3 >> 0x18);
        *(char *)(param_2 + 0x83) = (char)((ulonglong)uVar3 >> 0x10);
        *(char *)(param_2 + 0x84) = (char)((ulonglong)uVar3 >> 8);
        *(char *)(param_2 + 0x87) = (char)((uint)*(undefined4 *)(param_2 + 0x90) >> 8);
        *(undefined1 *)(param_2 + 0x49) = 10;
      }
      goto LAB_000202d9;
    }
    uVar5 = (uint)bVar4;
    if ((uVar5 == 0x15) || (uVar5 == 0x1a)) goto LAB_00020314;
    if (uVar5 == 0x1b) goto LAB_000202d9;
    iVar6 = uVar5 - 0x28;
  }
  else {
    if ((uVar5 == 0x55) || (uVar5 == 0x5a)) {
LAB_00020314:
      FUN_00020c10(lVar2,param_2);
      return 0x103;
    }
    iVar6 = uVar5 - 0x88;
  }
  if (((iVar6 == 0) || (iVar6 == 2)) || (iVar6 == 6)) {
    FUN_00020398(lVar2,param_2);
    return 0x103;
  }
  if (iVar6 != 7) {
    return 0xc0000010;
  }
LAB_000202d9:
  FUN_00020988(lVar2,param_2);
  return 0x103;
}



===== FUN_00020328 @ 00020328 =====

undefined8 FUN_00020328(undefined8 param_1,longlong param_2,longlong param_3)

{
  int *piVar1;
  
  if (param_3 != 0) {
    *(undefined4 *)(param_3 + 0x50) = *(undefined4 *)(param_2 + 0x30);
    if (*(longlong *)(param_2 + 8) != 0) {
      IoFreeMdl();
      *(undefined8 *)(param_2 + 8) = 0;
    }
    if (*(longlong *)(param_2 + 0x70) != 0) {
      ExFreePoolWithTag(*(longlong *)(param_2 + 0x70),0);
      *(undefined8 *)(param_2 + 0x70) = 0;
    }
    IoFreeIrp(param_2);
    LOCK();
    piVar1 = (int *)(param_3 + 0x78);
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (*piVar1 == 0) {
      NvRaidPacketCompleteRequest(param_3);
    }
  }
  return 0xc0000016;
}



===== FUN_00020398 @ 00020398 =====

ulonglong FUN_00020398(longlong param_1,longlong param_2)

{
  int iVar1;
  uint uVar2;
  longlong *plVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar1 = *(int *)(param_2 + 0x90);
  plVar3 = *(longlong **)(*(longlong *)(param_1 + 0x40) + 0x60);
  uVar2 = *(uint *)(plVar3 + 0x16);
  iVar4 = ClassAcquireRemoveLockEx
                    (param_1,param_2,"drivers\\oem\\src\\storage\\nvraid\\nvraid\\nvraidos.c",0x6d1)
  ;
  uVar9 = 0;
  if (iVar4 == 0) {
    uVar8 = iVar1 * *(int *)(*plVar3 + 0x28);
    if (*(longlong *)(param_2 + 0xa8) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = *(ulonglong *)(*(longlong *)(param_2 + 0xa8) + 0x18);
    }
    uVar5 = ((uVar2 - 1) + uVar8) / uVar2;
    *(uint *)(param_2 + 0x78) = uVar5;
    if (uVar5 != 0) {
      do {
        uVar7 = uVar8;
        if (uVar2 < uVar8) {
          uVar7 = uVar2;
        }
        FUN_00020494(param_1,param_2,uVar6,uVar7);
        uVar6 = uVar6 + uVar7;
        uVar8 = uVar8 - uVar7;
      } while ((uVar8 != 0) && (uVar9 = uVar9 + 1, uVar9 < uVar5));
    }
    uVar6 = ClassReleaseRemoveLock(param_1,param_2);
  }
  else {
    ClassReleaseRemoveLock(param_1,param_2);
    *(undefined4 *)(param_2 + 0x4b) = 0x40202;
    *(undefined4 *)(param_2 + 0x50) = 0xc00000c0;
    uVar6 = NvRaidPacketCompleteRequest(param_2);
  }
  return uVar6 & 0xffffffffffffff00;
}



===== FUN_00020494 @ 00020494 =====

ulonglong FUN_00020494(longlong param_1,longlong param_2,ulonglong param_3,uint param_4)

{
  longlong lVar1;
  longlong *plVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  bool bVar5;
  char cVar6;
  ushort uVar7;
  uint uVar8;
  int iVar9;
  longlong lVar10;
  undefined2 *_Dst;
  ulonglong uVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  char cVar14;
  longlong lVar15;
  uint uVar16;
  uint uVar17;
  ulonglong uVar18;
  char cVar19;
  longlong lVar20;
  uint uVar21;
  ulonglong uVar22;
  byte bVar23;
  uint uVar24;
  uint uVar25;
  ulonglong uVar26;
  undefined4 uVar27;
  undefined4 *_Dst_00;
  int local_res18;
  ushort local_96;
  uint local_94;
  ulonglong local_88;
  uint local_48;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  plVar2 = *(longlong **)(lVar1 + 0x60);
  bVar5 = true;
  lVar10 = IoAllocateIrp(*(char *)(param_1 + 0x4c) + '\x01');
  cVar19 = '\0';
  if (lVar10 == 0) {
    uVar27 = 0xc000009a;
  }
  else {
    lVar20 = lVar1 + 0x100;
    *(int *)(lVar1 + 0x114) = *(int *)(lVar1 + 0x114) + 1;
    _Dst = (undefined2 *)ExpInterlockedPopEntrySList(lVar20);
    if (_Dst == (undefined2 *)0x0) {
      *(int *)(lVar1 + 0x118) = *(int *)(lVar1 + 0x118) + 1;
      _Dst = (undefined2 *)
             (**(code **)(lVar1 + 0x130))
                       (*(undefined4 *)(lVar1 + 0x124),*(undefined4 *)(lVar1 + 300),
                        *(undefined4 *)(lVar1 + 0x128));
      if (_Dst != (undefined2 *)0x0) goto LAB_0002054c;
      uVar27 = 0xc000009a;
LAB_000208c6:
      if (*(longlong *)(lVar10 + 0x70) != 0) {
        ExFreePoolWithTag(*(longlong *)(lVar10 + 0x70),0);
      }
    }
    else {
LAB_0002054c:
      memset(_Dst,0,0x58);
      if ((*(longlong *)(param_2 + 0xa8) == 0) || (param_4 == 0)) {
        uVar27 = *(undefined4 *)(param_2 + 0x84);
        uVar3 = *(undefined4 *)(param_2 + 0x88);
        uVar4 = *(undefined4 *)(param_2 + 0x8c);
        *(undefined4 *)(_Dst + 0x24) = *(undefined4 *)(param_2 + 0x80);
        *(undefined4 *)(_Dst + 0x26) = uVar27;
        *(undefined4 *)(_Dst + 0x28) = uVar3;
        *(undefined4 *)(_Dst + 0x2a) = uVar4;
        local_88 = param_3;
        uVar16 = param_4;
LAB_0002080a:
        uVar27 = *(undefined4 *)(lVar1 + 0x248);
        _Dst[4] = 0x20ff;
        *(undefined1 *)(_Dst + 1) = 0;
        *(undefined4 *)(_Dst + 6) = 0x800000;
        *(undefined4 *)(_Dst + 10) = uVar27;
        *(longlong *)(*(longlong *)(lVar10 + 0xb8) + -0x20) = param_1;
        lVar15 = *(longlong *)(lVar10 + 0xb8);
        *(code **)(lVar15 + -0x10) = FUN_00020328;
        *(longlong *)(lVar15 + -8) = param_2;
        *(undefined1 *)(lVar15 + -0x45) = 0xe0;
        *(char *)(lVar10 + 0x43) = *(char *)(lVar10 + 0x43) + -1;
        *(longlong *)(lVar10 + 0xb8) = *(longlong *)(lVar10 + 0xb8) + -0x48;
        iVar9 = ClassAcquireRemoveLockEx
                          (param_1,lVar10,"drivers\\oem\\src\\storage\\nvraid\\nvraid\\nvraidos.c",
                           0x807);
        if (iVar9 == 0) {
          cVar6 = *(char *)(param_2 + 0x80);
          if (cVar6 == -2) {
            cVar14 = *(char *)(param_2 + 0x81);
          }
          else {
            cVar14 = cVar6;
          }
          if (cVar14 == '\n') {
LAB_00020949:
            cVar19 = '\x01';
          }
          else {
            if (cVar6 == -2) {
              cVar14 = *(char *)(param_2 + 0x81);
            }
            else {
              cVar14 = cVar6;
            }
            if (cVar14 == '*') goto LAB_00020949;
            if (cVar6 == -2) {
              cVar14 = *(char *)(param_2 + 0x81);
            }
            else {
              cVar14 = cVar6;
            }
            if (cVar14 == -0x76) goto LAB_00020949;
            if (cVar6 == -2) {
              cVar6 = *(char *)(param_2 + 0x81);
            }
            if (cVar6 == '.') goto LAB_00020949;
          }
          uVar13 = nvrClassSendSrbAsynchronous(param_1,_Dst,lVar10,local_88,uVar16,cVar19);
          goto LAB_00020968;
        }
        ClassReleaseRemoveLock(param_1,lVar10);
        uVar27 = 0xc00000c0;
        *(undefined4 *)(param_2 + 0x4b) = 0x40202;
      }
      else {
        _Dst_00 = (undefined4 *)0x0;
        while( true ) {
          lVar15 = *(longlong *)(param_2 + 0xa8);
          uVar13 = 0xffffffffffffffff;
          uVar26 = 0;
          local_88 = 0xffffffffffffffff;
          uVar16 = 0;
          uVar8 = 0;
          if (*(short *)(lVar15 + 6) == 0) {
            do {
              lVar15 = *(longlong *)(lVar15 + 8);
              uVar16 = uVar16 - uVar8;
              uVar8 = (uint)*(ushort *)(lVar15 + 6);
            } while (uVar8 <= uVar16);
          }
          local_res18 = (int)param_3;
          uVar24 = 0;
          local_96 = 0;
          uVar25 = local_res18 - *(int *)(lVar15 + 0x18 + (ulonglong)uVar16 * 0x10);
          local_94 = 0;
          uVar8 = *(uint *)(*plVar2 + 0x28);
          uVar11 = (ulonglong)uVar25 / (ulonglong)uVar8 + *(longlong *)(param_2 + 0x88);
          uVar8 = param_4 / uVar8;
          uVar16 = param_4;
          do {
            lVar15 = *(longlong *)(param_2 + 0xa8);
            uVar22 = (ulonglong)local_94;
            uVar17 = (uint)*(ushort *)(lVar15 + 6);
            if (*(ushort *)(lVar15 + 6) <= local_94) {
              do {
                lVar15 = *(longlong *)(lVar15 + 8);
                uVar21 = (int)uVar22 - uVar17;
                uVar22 = (ulonglong)uVar21;
                uVar17 = (uint)*(ushort *)(lVar15 + 6);
              } while (uVar17 <= uVar21);
            }
            uVar17 = *(uint *)(lVar15 + 0x20 + uVar22 * 0x10);
            if (uVar25 < uVar17) {
              uVar18 = (ulonglong)uVar25;
              local_48 = uVar17 - uVar25;
              uVar25 = 0;
              if (uVar16 < local_48) {
                local_48 = uVar16;
              }
              uVar18 = uVar18 + *(longlong *)(lVar15 + 0x18 + uVar22 * 0x10);
              local_96 = (short)uVar24 + 1;
              uVar24 = (uint)local_96;
              uVar16 = uVar16 - local_48;
              if (uVar18 < uVar13) {
                uVar13 = uVar18;
              }
              if (uVar26 < local_48 + uVar18) {
                uVar26 = local_48 + uVar18;
              }
              local_88 = uVar13;
              if (_Dst_00 != (undefined4 *)0x0) {
                NvRaidPacketScatterGatherElementAdd((longlong)_Dst_00,uVar18,local_48);
                uVar24 = (uint)local_96;
              }
            }
            else {
              uVar25 = uVar25 - uVar17;
            }
            local_94 = local_94 + 1;
          } while (uVar16 != 0);
          *(undefined1 *)(_Dst + 5) = *(undefined1 *)(param_2 + 0x49);
          uVar16 = (int)uVar26 - (int)uVar13;
          if ((short)uVar24 == 1) {
            bVar23 = *(byte *)(param_2 + 0x80);
            if (bVar23 == 0xfe) {
              bVar23 = *(byte *)(param_2 + 0x81);
            }
            if (0xffffffff < uVar11) {
              if (bVar23 == 0x28) {
                bVar23 = 0x88;
              }
              else if (bVar23 == 0x2a) {
                bVar23 = 0x8a;
              }
              else if (bVar23 == 0x2e) {
                bVar23 = 0x2e;
              }
              else if (bVar23 == 0x2f) {
                bVar23 = 0x2f;
              }
            }
            uVar12 = FUN_00022e64(bVar23,(longlong)_Dst,uVar11,uVar8);
            uVar16 = local_48;
            if (-1 < (int)uVar12) {
              if ((*(byte *)(param_2 + 0x82) & 0x10) != 0) {
                *(byte *)((longlong)_Dst + 0x49) = *(byte *)((longlong)_Dst + 0x49) | 8;
              }
              bVar5 = false;
            }
          }
          if (!bVar5) goto LAB_0002080a;
          if (_Dst_00 != (undefined4 *)0x0) {
            *(undefined4 **)(lVar10 + 0x70) = _Dst_00;
            uVar27 = *(undefined4 *)(param_2 + 0x84);
            uVar3 = *(undefined4 *)(param_2 + 0x88);
            uVar4 = *(undefined4 *)(param_2 + 0x8c);
            *(undefined4 *)(_Dst + 0x24) = *(undefined4 *)(param_2 + 0x80);
            *(undefined4 *)(_Dst + 0x26) = uVar27;
            *(undefined4 *)(_Dst + 0x28) = uVar3;
            *(undefined4 *)(_Dst + 0x2a) = uVar4;
            if (uVar8 < *(uint *)(_Dst + 0x2c)) {
              *(ulonglong *)(_Dst + 0x28) = uVar11;
              *(uint *)(_Dst + 0x2c) = uVar8;
            }
            local_88 = 0;
            uVar16 = 0;
            goto LAB_0002080a;
          }
          uVar8 = (uVar24 & 0xffff) * 0x10 + 0x18;
          _Dst_00 = (undefined4 *)ExAllocatePoolWithTag(0,uVar8,0x644e7652);
          if (_Dst_00 == (undefined4 *)0x0) break;
          memset(_Dst_00,0,(ulonglong)uVar8);
          uVar27 = **(undefined4 **)(param_2 + 0xa8);
          *(undefined2 *)(_Dst_00 + 1) = 0;
          *_Dst_00 = uVar27;
          *(ushort *)((longlong)_Dst_00 + 6) = local_96;
        }
        uVar27 = 0xc000009a;
      }
      *(int *)(lVar1 + 0x11c) = *(int *)(lVar1 + 0x11c) + 1;
      uVar7 = ExQueryDepthSList(lVar20);
      if (uVar7 < *(ushort *)(lVar1 + 0x110)) {
        ExpInterlockedPushEntrySList(lVar20,_Dst);
      }
      else {
        *(int *)(lVar1 + 0x120) = *(int *)(lVar1 + 0x120) + 1;
        (**(code **)(lVar1 + 0x138))(_Dst);
      }
      if (bVar5) goto LAB_000208c6;
    }
    IoFreeIrp(lVar10);
  }
  *(undefined4 *)(param_2 + 0x50) = uVar27;
  uVar13 = NvRaidPacketCompleteRequest(param_2);
LAB_00020968:
  return uVar13 & 0xffffffffffffff00;
}



===== FUN_00020988 @ 00020988 =====

ulonglong FUN_00020988(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char cVar8;
  ushort uVar9;
  int iVar10;
  longlong lVar11;
  undefined2 *_Dst;
  undefined8 uVar12;
  longlong lVar13;
  ulonglong uVar14;
  char cVar15;
  undefined4 uVar16;
  char cVar17;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  plVar3 = *(longlong **)(lVar2 + 0x60);
  cVar17 = '\x01';
  lVar11 = IoAllocateIrp(*(char *)(param_1 + 0x4c) + '\x01');
  if (lVar11 == 0) {
    uVar16 = 0xc000009a;
  }
  else {
    lVar1 = lVar2 + 0x100;
    *(int *)(lVar2 + 0x114) = *(int *)(lVar2 + 0x114) + 1;
    _Dst = (undefined2 *)ExpInterlockedPopEntrySList(lVar1);
    if (_Dst == (undefined2 *)0x0) {
      *(int *)(lVar2 + 0x118) = *(int *)(lVar2 + 0x118) + 1;
      _Dst = (undefined2 *)
             (**(code **)(lVar2 + 0x130))
                       (*(undefined4 *)(lVar2 + 0x124),*(undefined4 *)(lVar2 + 300),
                        *(undefined4 *)(lVar2 + 0x128));
      if (_Dst != (undefined2 *)0x0) goto LAB_00020a17;
      uVar16 = 0xc000009a;
    }
    else {
LAB_00020a17:
      memset(_Dst,0,0x58);
      *(undefined1 *)(_Dst + 5) = *(undefined1 *)(param_2 + 0x49);
      if ((*(char *)(param_2 + 0x80) != -2) ||
         (uVar12 = FUN_00022e64(*(byte *)(param_2 + 0x81),(longlong)_Dst,
                                *(undefined8 *)(param_2 + 0x88),*(undefined4 *)(param_2 + 0x90)),
         (int)uVar12 < 0)) {
        uVar16 = *(undefined4 *)(param_2 + 0x84);
        uVar6 = *(undefined4 *)(param_2 + 0x88);
        uVar7 = *(undefined4 *)(param_2 + 0x8c);
        *(undefined4 *)(_Dst + 0x24) = *(undefined4 *)(param_2 + 0x80);
        *(undefined4 *)(_Dst + 0x26) = uVar16;
        *(undefined4 *)(_Dst + 0x28) = uVar6;
        *(undefined4 *)(_Dst + 0x2a) = uVar7;
      }
      uVar16 = *(undefined4 *)(lVar2 + 0x248);
      _Dst[4] = 0x20ff;
      *(undefined1 *)(_Dst + 1) = 0;
      *(undefined4 *)(_Dst + 6) = 0x800000;
      *(undefined4 *)(_Dst + 10) = uVar16;
      lVar4 = *plVar3;
      if (lVar4 != 0) {
        lVar13 = lVar4;
        do {
          lVar5 = *(longlong *)(lVar13 + 0x50);
          if (*(longlong *)(lVar13 + 0x18) == lVar5) break;
          lVar13 = lVar5;
        } while (lVar5 != 0);
        if ((((lVar13 != 0) && (lVar13 != lVar4)) && (*(longlong *)(lVar13 + 0x10) != 0)) &&
           (*(int *)(*(longlong *)(*(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x40) + 0x60) + 0x18
                    ) != 0)) {
          *(undefined4 *)(_Dst + 6) = 0x880000;
        }
      }
      *(longlong *)(*(longlong *)(lVar11 + 0xb8) + -0x20) = param_1;
      lVar4 = *(longlong *)(lVar11 + 0xb8);
      *(code **)(lVar4 + -0x10) = FUN_00020328;
      *(longlong *)(lVar4 + -8) = param_2;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      *(char *)(lVar11 + 0x43) = *(char *)(lVar11 + 0x43) + -1;
      *(longlong *)(lVar11 + 0xb8) = *(longlong *)(lVar11 + 0xb8) + -0x48;
      iVar10 = ClassAcquireRemoveLockEx
                         (param_1,lVar11,"drivers\\oem\\src\\storage\\nvraid\\nvraid\\nvraidos.c");
      if (iVar10 == 0) {
        cVar8 = *(char *)(param_2 + 0x80);
        *(undefined4 *)(param_2 + 0x78) = 1;
        if (cVar8 == -2) {
          cVar15 = *(char *)(param_2 + 0x81);
        }
        else {
          cVar15 = cVar8;
        }
        if (cVar15 != '\n') {
          if (cVar8 == -2) {
            cVar15 = *(char *)(param_2 + 0x81);
          }
          else {
            cVar15 = cVar8;
          }
          if (cVar15 != '*') {
            if (cVar8 == -2) {
              cVar15 = *(char *)(param_2 + 0x81);
            }
            else {
              cVar15 = cVar8;
            }
            if (cVar15 != -0x76) {
              if (cVar8 == -2) {
                cVar8 = *(char *)(param_2 + 0x81);
              }
              if (cVar8 != '.') {
                cVar17 = '\0';
              }
            }
          }
        }
        uVar14 = nvrClassSendSrbAsynchronous(param_1,_Dst,lVar11,0,0,cVar17);
        goto LAB_00020bef;
      }
      ClassReleaseRemoveLock(param_1,lVar11);
      *(undefined4 *)(param_2 + 0x4b) = 0x40202;
      *(int *)(lVar2 + 0x11c) = *(int *)(lVar2 + 0x11c) + 1;
      uVar16 = 0xc00000c0;
      uVar9 = ExQueryDepthSList(lVar1);
      if (uVar9 < *(ushort *)(lVar2 + 0x110)) {
        ExpInterlockedPushEntrySList(lVar1,_Dst);
      }
      else {
        *(int *)(lVar2 + 0x120) = *(int *)(lVar2 + 0x120) + 1;
        (**(code **)(lVar2 + 0x138))(_Dst);
      }
    }
    IoFreeIrp(lVar11);
  }
  *(undefined4 *)(param_2 + 0x50) = uVar16;
  uVar14 = NvRaidPacketCompleteRequest(param_2);
LAB_00020bef:
  return uVar14 & 0xffffffffffffff00;
}



===== FUN_00020c10 @ 00020c10 =====

ulonglong FUN_00020c10(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  char cVar8;
  ushort uVar9;
  uint uVar10;
  int iVar11;
  longlong lVar12;
  undefined2 *_Dst;
  undefined8 uVar13;
  longlong lVar14;
  ulonglong uVar15;
  char cVar16;
  uint uVar17;
  char cVar18;
  undefined4 uVar19;
  longlong lVar20;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  cVar18 = '\0';
  plVar3 = *(longlong **)(lVar2 + 0x60);
  lVar20 = *(longlong *)(param_2 + 0xa8);
  uVar17 = 0;
  uVar10 = 0;
  if (*(short *)(lVar20 + 6) == 0) {
    do {
      lVar20 = *(longlong *)(lVar20 + 8);
      uVar17 = uVar17 - uVar10;
      uVar10 = (uint)*(ushort *)(lVar20 + 6);
    } while (uVar10 <= uVar17);
  }
  lVar12 = IoAllocateIrp(*(char *)(param_1 + 0x4c) + '\x01');
  if (lVar12 == 0) {
    uVar19 = 0xc000009a;
  }
  else {
    lVar1 = lVar2 + 0x100;
    *(int *)(lVar2 + 0x114) = *(int *)(lVar2 + 0x114) + 1;
    _Dst = (undefined2 *)ExpInterlockedPopEntrySList(lVar1);
    if (_Dst == (undefined2 *)0x0) {
      *(int *)(lVar2 + 0x118) = *(int *)(lVar2 + 0x118) + 1;
      _Dst = (undefined2 *)
             (**(code **)(lVar2 + 0x130))
                       (*(undefined4 *)(lVar2 + 0x124),*(undefined4 *)(lVar2 + 300),
                        *(undefined4 *)(lVar2 + 0x128));
      if (_Dst != (undefined2 *)0x0) goto LAB_00020cc3;
      uVar19 = 0xc000009a;
    }
    else {
LAB_00020cc3:
      memset(_Dst,0,0x58);
      *(undefined1 *)(_Dst + 5) = *(undefined1 *)(param_2 + 0x49);
      if ((*(char *)(param_2 + 0x80) != -2) ||
         (uVar13 = FUN_00022e64(*(byte *)(param_2 + 0x81),(longlong)_Dst,
                                *(undefined8 *)(param_2 + 0x88),*(undefined4 *)(param_2 + 0x90)),
         (int)uVar13 < 0)) {
        uVar19 = *(undefined4 *)(param_2 + 0x84);
        uVar6 = *(undefined4 *)(param_2 + 0x88);
        uVar7 = *(undefined4 *)(param_2 + 0x8c);
        *(undefined4 *)(_Dst + 0x24) = *(undefined4 *)(param_2 + 0x80);
        *(undefined4 *)(_Dst + 0x26) = uVar19;
        *(undefined4 *)(_Dst + 0x28) = uVar6;
        *(undefined4 *)(_Dst + 0x2a) = uVar7;
      }
      uVar19 = *(undefined4 *)(lVar2 + 0x248);
      _Dst[4] = 0x20ff;
      *(undefined4 *)(_Dst + 10) = uVar19;
      *(undefined1 *)(_Dst + 1) = 0;
      *(undefined4 *)(_Dst + 6) = 0x800000;
      lVar4 = *plVar3;
      if (lVar4 != 0) {
        lVar14 = lVar4;
        do {
          lVar5 = *(longlong *)(lVar14 + 0x50);
          if (*(longlong *)(lVar14 + 0x18) == lVar5) break;
          lVar14 = lVar5;
        } while (lVar5 != 0);
        if ((((lVar14 != 0) && (lVar14 != lVar4)) && (*(longlong *)(lVar14 + 0x10) != 0)) &&
           (*(int *)(*(longlong *)(*(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x40) + 0x60) + 0x18
                    ) != 0)) {
          *(undefined4 *)(_Dst + 6) = 0x880000;
        }
      }
      *(longlong *)(*(longlong *)(lVar12 + 0xb8) + -0x20) = param_1;
      lVar4 = *(longlong *)(lVar12 + 0xb8);
      *(code **)(lVar4 + -0x10) = FUN_00020328;
      *(longlong *)(lVar4 + -8) = param_2;
      *(undefined1 *)(lVar4 + -0x45) = 0xe0;
      *(char *)(lVar12 + 0x43) = *(char *)(lVar12 + 0x43) + -1;
      *(longlong *)(lVar12 + 0xb8) = *(longlong *)(lVar12 + 0xb8) + -0x48;
      iVar11 = ClassAcquireRemoveLockEx
                         (param_1,lVar12,"drivers\\oem\\src\\storage\\nvraid\\nvraid\\nvraidos.c",
                          0x901);
      if (iVar11 == 0) {
        cVar8 = *(char *)(param_2 + 0x80);
        *(undefined4 *)(param_2 + 0x78) = 1;
        if (cVar8 == -2) {
          cVar16 = *(char *)(param_2 + 0x81);
        }
        else {
          cVar16 = cVar8;
        }
        if (cVar16 == '\n') {
LAB_00020e8d:
          cVar18 = '\x01';
        }
        else {
          if (cVar8 == -2) {
            cVar16 = *(char *)(param_2 + 0x81);
          }
          else {
            cVar16 = cVar8;
          }
          if (cVar16 == '*') goto LAB_00020e8d;
          if (cVar8 == -2) {
            cVar16 = *(char *)(param_2 + 0x81);
          }
          else {
            cVar16 = cVar8;
          }
          if (cVar16 == -0x76) goto LAB_00020e8d;
          if (cVar8 == -2) {
            cVar8 = *(char *)(param_2 + 0x81);
          }
          if (cVar8 == '.') goto LAB_00020e8d;
        }
        uVar15 = nvrClassSendSrbAsynchronous
                           (param_1,_Dst,lVar12,
                            *(longlong *)((ulonglong)uVar17 * 0x10 + 0x18 + lVar20),
                            *(undefined4 *)((ulonglong)uVar17 * 0x10 + 0x20 + lVar20),cVar18);
        goto LAB_00020eb5;
      }
      ClassReleaseRemoveLock(param_1,lVar12);
      *(undefined4 *)(param_2 + 0x4b) = 0x40202;
      *(int *)(lVar2 + 0x11c) = *(int *)(lVar2 + 0x11c) + 1;
      uVar19 = 0xc00000c0;
      uVar9 = ExQueryDepthSList(lVar1);
      if (uVar9 < *(ushort *)(lVar2 + 0x110)) {
        ExpInterlockedPushEntrySList(lVar1,_Dst);
      }
      else {
        *(int *)(lVar2 + 0x120) = *(int *)(lVar2 + 0x120) + 1;
        (**(code **)(lVar2 + 0x138))(_Dst);
      }
    }
    IoFreeIrp(lVar12);
  }
  *(undefined4 *)(param_2 + 0x50) = uVar19;
  uVar15 = NvRaidPacketCompleteRequest(param_2);
LAB_00020eb5:
  return uVar15 & 0xffffffffffffff00;
}



===== FUN_00020ed0 @ 00020ed0 =====

void FUN_00020ed0(undefined8 *param_1)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  ushort *_Src;
  ushort *puVar4;
  uint uVar5;
  byte local_res8;
  
  _Src = (ushort *)((longlong)param_1 + 0x14);
  uVar5 = 0;
  if (*(int *)((longlong)param_1 + 0xc) != 0) {
    puVar4 = _Src;
    do {
      uVar3 = *(uint *)(param_1 + 1);
      if (*(char *)(param_1 + 2) == '\0') {
        if (3 < uVar3) {
          uVar1 = (byte)*puVar4 + 1;
          if (uVar1 < uVar3) {
            uVar3 = uVar1;
          }
LAB_00020f2d:
          lVar2 = ClassFindModePage(puVar4,uVar3,8,1);
          if (lVar2 != 0) {
            local_res8 = *(byte *)(lVar2 + 2) >> 2 & 1;
          }
        }
      }
      else if (7 < uVar3) {
        uVar1 = (ushort)(*puVar4 << 8 | *puVar4 >> 8) + 2;
        if (uVar1 < uVar3) {
          uVar3 = uVar1;
        }
        goto LAB_00020f2d;
      }
      if (local_res8 != 0) {
        _Src = puVar4;
        break;
      }
      uVar5 = uVar5 + 1;
      puVar4 = (ushort *)((longlong)puVar4 + (ulonglong)*(uint *)(param_1 + 1));
    } while (uVar5 < *(uint *)((longlong)param_1 + 0xc));
  }
  memcpy((void *)*param_1,_Src,(ulonglong)*(uint *)(param_1 + 1));
  return;
}



===== FUN_00020f88 @ 00020f88 =====

undefined8 FUN_00020f88(longlong param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 *puVar6;
  ushort *puVar7;
  uint uVar8;
  undefined8 *puVar9;
  longlong lVar10;
  uint uVar11;
  ulonglong uVar12;
  uint uVar13;
  longlong *plVar14;
  undefined8 local_res8;
  
  lVar3 = *(longlong *)(param_2 + 0x1a);
  lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
  lVar5 = *(longlong *)(lVar3 + 0x30);
  *(undefined1 *)(lVar3 + 4) = *(undefined1 *)((longlong)param_2 + 0x4b);
  *(undefined4 *)(lVar5 + 0x30) = param_2[0x14];
  iVar2 = param_2[0x14];
  uVar13 = 0x12;
  if (iVar2 == 0) {
    *(undefined1 *)(lVar3 + 3) = 1;
    *(ulonglong *)(lVar5 + 0x38) = (ulonglong)*(uint *)(lVar3 + 0x10);
    *(undefined1 *)(lVar3 + 0xb) = 0;
  }
  else {
    if (iVar2 == -0x7fffffef) {
LAB_00021039:
      *(undefined1 *)(lVar3 + 3) = 9;
    }
    else if (iVar2 == -0x3ffffff2) {
      *(undefined1 *)(lVar3 + 3) = 8;
    }
    else if (iVar2 == -0x3ffffff0) {
      *(undefined1 *)(lVar3 + 3) = 6;
      *(undefined4 *)((longlong)param_2 + 0x4b) = 0x200502;
    }
    else if (iVar2 == -0x3fffffc4) {
      *(undefined1 *)(lVar3 + 3) = 0x12;
    }
    else if (iVar2 == -0x3fffff66) {
      *(undefined1 *)(lVar3 + 3) = 0x30;
      *(undefined4 *)(lVar3 + 0x40) = 0xc000009a;
    }
    else if (iVar2 == -0x3fffff63) {
      *(undefined1 *)(lVar3 + 3) = 10;
    }
    else {
      if ((iVar2 == -0x3fffff5d) || (iVar2 == -0x3fffff4b)) goto LAB_00021039;
      *(undefined1 *)(lVar3 + 3) = 4;
    }
    puVar9 = *(undefined8 **)(lVar3 + 0x20);
    if ((puVar9 != (undefined8 *)0x0) && (0x11 < *(byte *)(lVar3 + 0xb))) {
      *puVar9 = 0;
      puVar9[1] = 0;
      *(undefined2 *)(puVar9 + 2) = 0;
      *(undefined1 *)(lVar3 + 4) = *(undefined1 *)((longlong)param_2 + 0x4b);
      *(undefined1 *)puVar9 = 0xf0;
      *(undefined1 *)((longlong)puVar9 + 7) = 0xb;
      *(byte *)((longlong)puVar9 + 2) =
           *(byte *)((longlong)puVar9 + 2) ^
           (*(byte *)((longlong)puVar9 + 2) ^ *(byte *)(param_2 + 0x13)) & 0xf;
      *(undefined1 *)((longlong)puVar9 + 0xc) = *(undefined1 *)((longlong)param_2 + 0x4d);
      *(undefined1 *)((longlong)puVar9 + 0xd) = *(undefined1 *)((longlong)param_2 + 0x4e);
      if ((*(char *)(lVar3 + 4) == '\x02') && (*(char *)(param_2 + 0x13) != '\0')) {
        *(byte *)(lVar3 + 3) = *(byte *)(lVar3 + 3) | 0x80;
      }
    }
  }
  if (*(char *)(lVar3 + 2) == '\0') {
    cVar1 = *(char *)(lVar3 + 0x48);
    if (cVar1 == '%') {
      lVar10 = *(longlong *)(param_2 + 0x2a);
      uVar11 = 0;
      uVar8 = 0;
      if (*(short *)(lVar10 + 6) == 0) {
        do {
          lVar10 = *(longlong *)(lVar10 + 8);
          uVar11 = uVar11 - uVar8;
          uVar8 = (uint)*(ushort *)(lVar10 + 6);
        } while (uVar8 <= uVar11);
      }
      puVar9 = (undefined8 *)(lVar10 + 0x18 + (ulonglong)uVar11 * 0x10);
      if (puVar9 != (undefined8 *)0x0) {
        puVar6 = (undefined4 *)*puVar9;
        local_res8._0_2_ =
             CONCAT11(*(undefined1 *)((longlong)puVar6 + 2),*(undefined1 *)((longlong)puVar6 + 3));
        local_res8._0_3_ = CONCAT12(*(undefined1 *)((longlong)puVar6 + 1),(undefined2)local_res8);
        local_res8._0_4_ = CONCAT13(*(undefined1 *)puVar6,(undefined3)local_res8);
        *puVar6 = (undefined4)local_res8;
        local_res8._0_2_ =
             CONCAT11(*(undefined1 *)((longlong)puVar6 + 6),*(undefined1 *)((longlong)puVar6 + 7));
        local_res8._0_3_ = CONCAT12(*(undefined1 *)((longlong)puVar6 + 5),(undefined2)local_res8);
        local_res8._0_4_ = CONCAT13(*(undefined1 *)(puVar6 + 1),(undefined3)local_res8);
        puVar6[1] = (undefined4)local_res8;
      }
    }
    else if (cVar1 == -0x62) {
      lVar10 = *(longlong *)(param_2 + 0x2a);
      uVar11 = 0;
      uVar8 = 0;
      if (*(short *)(lVar10 + 6) == 0) {
        do {
          lVar10 = *(longlong *)(lVar10 + 8);
          uVar11 = uVar11 - uVar8;
          uVar8 = (uint)*(ushort *)(lVar10 + 6);
        } while (uVar8 <= uVar11);
      }
      puVar9 = (undefined8 *)(lVar10 + 0x18 + (ulonglong)uVar11 * 0x10);
      if (puVar9 != (undefined8 *)0x0) {
        puVar9 = (undefined8 *)*puVar9;
        local_res8._0_2_ =
             CONCAT11(*(undefined1 *)((longlong)puVar9 + 6),*(undefined1 *)((longlong)puVar9 + 7));
        local_res8._0_3_ = CONCAT12(*(undefined1 *)((longlong)puVar9 + 5),(undefined2)local_res8);
        local_res8._0_4_ = CONCAT13(*(undefined1 *)((longlong)puVar9 + 4),(undefined3)local_res8);
        local_res8 = CONCAT17(*(undefined1 *)puVar9,
                              CONCAT16(*(undefined1 *)((longlong)puVar9 + 1),
                                       CONCAT15(*(undefined1 *)((longlong)puVar9 + 2),
                                                CONCAT14(*(undefined1 *)((longlong)puVar9 + 3),
                                                         (undefined4)local_res8))));
        *puVar9 = local_res8;
        local_res8._0_2_ =
             CONCAT11(*(undefined1 *)((longlong)puVar9 + 10),*(undefined1 *)((longlong)puVar9 + 0xb)
                     );
        local_res8._0_3_ = CONCAT12(*(undefined1 *)((longlong)puVar9 + 9),(undefined2)local_res8);
        local_res8._0_4_ = CONCAT13(*(undefined1 *)(puVar9 + 1),(undefined3)local_res8);
        *(undefined4 *)(puVar9 + 1) = (undefined4)local_res8;
      }
    }
    else {
      if (cVar1 == '(') {
        if (*(void **)(lVar5 + 0x78) == (void *)0x0) goto LAB_000212d1;
        lVar10 = *(longlong *)(param_2 + 0x2a);
        uVar12 = 0;
        uVar8 = 0;
        if (*(short *)(lVar10 + 6) == 0) {
          do {
            lVar10 = *(longlong *)(lVar10 + 8);
            uVar11 = (int)uVar12 - uVar8;
            uVar12 = (ulonglong)uVar11;
            uVar8 = (uint)*(ushort *)(lVar10 + 6);
          } while (uVar8 <= uVar11);
        }
        plVar14 = (longlong *)(lVar10 + 0x18 + uVar12 * 0x10);
        if (plVar14 == (longlong *)0x0) goto LAB_000212d1;
        memcpy(*(void **)(lVar5 + 0x78),(void *)*plVar14,(ulonglong)*(uint *)(plVar14 + 1));
        lVar10 = *plVar14;
      }
      else {
        if (((cVar1 - 0x1aU & 0xbf) != 0) || (param_2[0x14] != 0)) goto LAB_000212d1;
        lVar10 = *(longlong *)(param_2 + 0x2a);
        uVar12 = 0;
        uVar8 = 0;
        if (*(short *)(lVar10 + 6) == 0) {
          do {
            lVar10 = *(longlong *)(lVar10 + 8);
            uVar11 = (int)uVar12 - uVar8;
            uVar12 = (ulonglong)uVar11;
            uVar8 = (uint)*(ushort *)(lVar10 + 6);
          } while (uVar8 <= uVar11);
        }
        plVar14 = (longlong *)(lVar10 + 0x18 + uVar12 * 0x10);
        if (plVar14 == (longlong *)0x0) goto LAB_000212d1;
        lVar10 = *plVar14;
        FUN_00020ed0((undefined8 *)(lVar10 + -0x14));
        puVar7 = *(ushort **)(lVar10 + -0x14);
        if ((*(byte *)(lVar3 + 0x4a) & 0x3f) == 0x3f) {
          if (*(char *)(lVar3 + 0x48) == '\x1a') {
            *(byte *)puVar7 = (byte)*puVar7 + 0xc;
            *(uint *)(lVar3 + 0x10) = (byte)*puVar7 + 1;
          }
          else {
            *puVar7 = 0x26;
            *(undefined4 *)(lVar3 + 0x10) = 0x28;
            *puVar7 = *puVar7 << 8 | *puVar7 >> 8;
          }
        }
        lVar10 = lVar10 + -0x14;
      }
      ExFreePoolWithTag(lVar10,0);
    }
  }
LAB_000212d1:
  NvRaidResNrpFree(0x298e0,param_2);
  if (*(void **)(lVar3 + 0x20) != (void *)0x0) {
    if (*(byte *)(lVar3 + 0xb) < 0x12) {
      uVar13 = (uint)*(byte *)(lVar3 + 0xb);
    }
    memcpy((void *)(lVar4 + 200),*(void **)(lVar3 + 0x20),(ulonglong)uVar13);
  }
  ClassCompleteRequest(param_1,lVar5,0);
  FUN_0001fdd4();
  return 0;
}



===== FUN_00021330 @ 00021330 =====

ulonglong FUN_00021330(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  undefined4 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  longlong *plVar10;
  uint *_Dst;
  ulonglong uVar11;
  ulonglong uVar12;
  byte bVar13;
  longlong lVar14;
  byte bVar15;
  longlong local_res8;
  
  plVar10 = *(longlong **)(*(longlong *)(param_1 + 0x40) + 0x60);
  lVar7 = *plVar10;
  if (((lVar7 == 0) || ((*(uint *)(lVar7 + 4) & 1) != 0)) || ((*(uint *)(lVar7 + 4) >> 8 & 1) != 0))
  {
    lVar7 = 0;
  }
  if (lVar7 == 0) {
    uVar11 = 0xc000000e;
LAB_0002139b:
    *(undefined1 *)(param_2 + 3) = 10;
    return uVar11;
  }
  puVar8 = NvRaidResNrpAllocate(0x298e0);
  if (puVar8 == (undefined4 *)0x0) {
    uVar11 = 0xc000009a;
    goto LAB_0002139b;
  }
  *(undefined4 **)(param_2 + 0x38) = puVar8;
  *(longlong *)(puVar8 + 0x1a) = param_2;
  *(undefined1 *)(puVar8 + 0x12) = *(undefined1 *)(param_2 + 6);
  lVar7 = *plVar10;
  *(longlong *)(puVar8 + 0x1c) = param_1;
  *(longlong *)(puVar8 + 0x10) = lVar7;
  *(undefined1 *)((longlong)puVar8 + 0x4a) = 5;
  *(code **)(puVar8 + 0x28) = FUN_00020f88;
  *(undefined1 *)((longlong)puVar8 + 0x49) = *(undefined1 *)(param_2 + 10);
  uVar9 = *(undefined8 *)(param_2 + 0x50);
  *(undefined8 *)(puVar8 + 0x20) = *(undefined8 *)(param_2 + 0x48);
  *(undefined8 *)(puVar8 + 0x22) = uVar9;
  if ((*(int *)(param_2 + 0x10) == 0) && ((*(char *)(param_2 + 0x48) - 0x15U & 0xbf) != 0)) {
LAB_000216ae:
    NvRaidScsiSwapCDBEndian((byte *)(puVar8 + 0x20));
    uVar12 = 0x103;
    pbVar1 = (byte *)(*(longlong *)(*(longlong *)(param_2 + 0x30) + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
    NvRaidPacketSubmitRequest((longlong)puVar8);
LAB_000216d2:
    if ((int)uVar12 == 0x103) {
      return uVar12;
    }
  }
  else {
    lVar7 = *(longlong *)(param_2 + 0x30);
    uVar9 = NvRaidResSgGroupAllocateForNrp(0x298e0,(longlong)puVar8);
    if ((int)uVar9 < 0) {
      *(undefined1 *)(param_2 + 3) = 10;
    }
    else {
      *(undefined8 *)(*(longlong *)(param_2 + 0x30) + 0x78) = 0;
      lVar5 = *(longlong *)(lVar7 + 8);
      if (lVar5 == 0) {
        _Dst = *(uint **)(param_2 + 0x18);
LAB_00021498:
        if (*(char *)(param_2 + 0x48) == '\x12') {
          uVar11 = FUN_00021708((longlong)puVar8,param_2,(undefined8 *)_Dst);
          uVar12 = uVar11 & 0xffffffff;
          if ((int)uVar11 != 0x103) goto LAB_000216da;
        }
        cVar2 = *(char *)(param_2 + 0x48);
        if (cVar2 == '\x03') {
          puVar6 = *(undefined8 **)(param_2 + 0x20);
          lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
          *puVar6 = 0;
          puVar6[1] = 0;
          *(undefined2 *)(puVar6 + 2) = 0;
          *puVar6 = *(undefined8 *)(lVar7 + 200);
          puVar6[1] = *(undefined8 *)(lVar7 + 0xd0);
          *(undefined2 *)(puVar6 + 2) = *(undefined2 *)(lVar7 + 0xd8);
          *(undefined1 *)(param_2 + 0xb) = 0x12;
          *(undefined4 *)(param_2 + 0x10) = 0;
          *(undefined2 *)(param_2 + 3) = 1;
        }
        else {
          if (cVar2 != -0x60) {
            if ((cVar2 - 0x15U & 0xbf) == 0) {
              uVar11 = FUN_00021b38(param_2,(longlong)_Dst);
              uVar12 = uVar11 & 0xffffffff;
              if ((int)uVar11 != 0x103) goto LAB_000216da;
            }
            if ((*(char *)(param_2 + 0x48) - 0x1aU & 0xbf) == 0) {
              local_res8 = 0;
              lVar7 = *(longlong *)(*(longlong *)(puVar8 + 0x10) + 0x58);
              bVar15 = 0;
              uVar12 = FUN_000218f0(param_2,&local_res8,_Dst);
              lVar5 = local_res8;
              uVar12 = uVar12 & 0xffffffff;
              if (local_res8 != 0) {
                bVar3 = *(byte *)(lVar7 + 0x16);
                uVar11 = 0;
                if (bVar3 != 0) {
                  lVar7 = *(longlong *)(puVar8 + 0x10);
                  do {
                    if ((lVar7 == -0x78) || (*(uint *)(lVar7 + 0x7c) <= (uint)uVar11)) {
                      lVar14 = 0;
                    }
                    else {
                      lVar14 = *(longlong *)(*(longlong *)(lVar7 + 0x80) + uVar11 * 8);
                    }
                    if (lVar14 != 0) {
                      bVar15 = bVar15 + 1;
                    }
                    bVar13 = (char)uVar11 + 1;
                    uVar11 = (ulonglong)bVar13;
                  } while (bVar13 < bVar3);
                }
                plVar10 = (longlong *)
                          ExAllocatePoolWithTag
                                    (0,(uint)bVar15 * *(int *)(param_2 + 0x10) + 0x14,0x644e7652);
                if (plVar10 == (longlong *)0x0) goto LAB_00021462;
                _Dst = (uint *)((longlong)plVar10 + 0x14);
                memset(_Dst,0,(ulonglong)((uint)bVar15 * *(int *)(param_2 + 0x10)));
                *plVar10 = lVar5;
                uVar4 = *(undefined4 *)(param_2 + 0x10);
                *(uint *)((longlong)plVar10 + 0xc) = (uint)bVar15;
                *(undefined4 *)(plVar10 + 1) = uVar4;
                *(bool *)(plVar10 + 2) = *(char *)(param_2 + 0x48) == 'Z';
                goto LAB_0002168f;
              }
            }
            else {
LAB_0002168f:
              uVar11 = NvRaidPacketScatterGatherElementAdd
                                 (*(longlong *)(puVar8 + 0x2a),_Dst,*(undefined4 *)(param_2 + 0x10))
              ;
              uVar12 = uVar11 & 0xffffffff;
              if ((int)uVar11 == 0) goto LAB_000216ae;
              *(undefined1 *)(param_2 + 3) = 10;
            }
            goto LAB_000216d2;
          }
          if (*(uint *)(param_2 + 0x10) < 0x10) {
            puVar6 = *(undefined8 **)(param_2 + 0x20);
            *(undefined1 *)(param_2 + 4) = 2;
            if (puVar6 != (undefined8 *)0x0) {
              *puVar6 = 0;
              puVar6[1] = 0;
              *(undefined2 *)(puVar6 + 2) = 0;
              *(undefined1 *)puVar6 = 0xf0;
              *(undefined1 *)((longlong)puVar6 + 7) = 0xb;
              *(undefined2 *)((longlong)puVar6 + 0xc) = 0x20;
              *(byte *)((longlong)puVar6 + 2) = *(byte *)((longlong)puVar6 + 2) & 0xf5 | 5;
              *(undefined4 *)(param_2 + 0x10) = 0;
              *(undefined1 *)(param_2 + 0xb) = 0x12;
              *(undefined2 *)(param_2 + 3) = 0x206;
            }
            goto LAB_00021478;
          }
          if (*(byte *)(param_2 + 0x4a) < 3) {
            memset(_Dst,0,0x10);
            *_Dst = 8;
            *_Dst = *(byte *)((longlong)_Dst + 3) | 0x8000000;
            *(undefined2 *)(_Dst + 2) = 0;
            *(undefined4 *)(param_2 + 0x10) = 0x10;
            *(undefined1 *)(param_2 + 0xb) = 0;
          }
        }
        uVar12 = 0;
        goto LAB_000216da;
      }
      if ((*(byte *)(lVar5 + 10) & 5) == 0) {
        uVar11 = MmMapLockedPagesSpecifyCache(lVar5,0,1,0,0,0x10);
      }
      else {
        uVar11 = *(ulonglong *)(lVar5 + 0x18);
      }
      if (uVar11 != 0) {
        if ((uVar11 & *(uint *)(param_1 + 0x98)) == 0) {
          lVar7 = *(longlong *)(lVar7 + 8);
          _Dst = (uint *)(uVar11 + (uint)((*(int *)(param_2 + 0x18) - *(int *)(lVar7 + 0x2c)) -
                                         *(int *)(lVar7 + 0x20)));
          goto LAB_00021498;
        }
        *(undefined1 *)(param_2 + 3) = 6;
LAB_00021478:
        uVar12 = 0xc0000010;
        goto LAB_000216da;
      }
LAB_00021462:
      *(undefined1 *)(param_2 + 3) = 2;
    }
    uVar12 = 0xc000009a;
  }
LAB_000216da:
  NvRaidResNrpFree(0x298e0,puVar8);
  return uVar12;
}



===== FUN_00021708 @ 00021708 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_00021708(longlong param_1,longlong param_2,undefined8 *param_3)

{
  char cVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  int iVar4;
  longlong lVar5;
  uint *puVar6;
  int iVar7;
  undefined1 auStack_78 [32];
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined1 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_78;
  cVar1 = *(char *)(param_2 + 0x4a);
  uVar3 = 0x103;
  if ((cVar1 == '\0') || ((*(byte *)(param_2 + 0x49) & 3) != 0)) {
    if (*(char *)(param_2 + 0x49) == '\x01') {
      if (cVar1 == '\0') {
        if (*(uint *)(param_2 + 0x10) < 7) goto LAB_000218a7;
        *(undefined4 *)param_3 = 0;
        *(undefined4 *)((longlong)param_3 + 3) = 0x800003;
        *(undefined1 *)((longlong)param_3 + 6) = 0x83;
        *(undefined4 *)(param_2 + 0x10) = 7;
        *(undefined1 *)(param_2 + 4) = 0;
      }
      else if (cVar1 == -0x80) {
        lVar5 = 0;
        iVar7 = 0;
        puVar6 = *(uint **)(*(longlong *)(param_1 + 0x40) + 0x58);
        iVar4 = 0x19;
        do {
          puVar6 = puVar6 + 1;
          RtlStringCbPrintfA(auStack_78 + (longlong)iVar7 + 0x20,(longlong)iVar4,"%08x",
                             (ulonglong)*puVar6);
          iVar4 = iVar4 + -8;
          iVar7 = iVar7 + 8;
          if (iVar4 < 1) break;
          lVar5 = lVar5 + 1;
        } while (lVar5 < 4);
        if (*(uint *)(param_2 + 0x10) < 0x1d) goto LAB_000218a7;
        *param_3 = 0;
        param_3[1] = 0;
        param_3[2] = 0;
        *(undefined1 *)((longlong)param_3 + 1) = 0x80;
        *(undefined1 *)((longlong)param_3 + 3) = 0x19;
        *(undefined8 *)((longlong)param_3 + 4) = local_58;
        *(undefined8 *)((longlong)param_3 + 0xc) = local_50;
        *(undefined8 *)((longlong)param_3 + 0x14) = local_48;
        *(undefined1 *)((longlong)param_3 + 0x1c) = local_40;
        *(undefined1 *)(param_2 + 4) = 0;
        *(undefined4 *)(param_2 + 0x10) = 0x1d;
      }
      else {
        if (cVar1 != -0x7d) {
          *(undefined4 *)(param_2 + 0x10) = 0x24;
          return 0x103;
        }
        lVar5 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x58);
        if (*(uint *)(param_2 + 0x10) < 0x10) {
LAB_000218a7:
          *(undefined1 *)(param_2 + 3) = 2;
          return 0xc000000d;
        }
        *param_3 = 0;
        param_3[1] = 0;
        *(undefined1 *)((longlong)param_3 + 1) = 0x83;
        *(undefined1 *)((longlong)param_3 + 3) = 0xc;
        *(undefined4 *)((longlong)param_3 + 7) = 0x4b040008;
        *(byte *)((longlong)param_3 + 4) = *(byte *)((longlong)param_3 + 4) & 0xf1 | 1;
        *(byte *)((longlong)param_3 + 5) = *(byte *)((longlong)param_3 + 5) & 0xf2 | 2;
        *(undefined4 *)((longlong)param_3 + 0xb) = *(undefined4 *)(lVar5 + 4);
        *(undefined1 *)((longlong)param_3 + 0xf) = *(undefined1 *)(lVar5 + 8);
        *(undefined4 *)(param_2 + 0x10) = 0x10;
        *(undefined1 *)(param_2 + 4) = 0;
      }
      uVar3 = 0;
    }
  }
  else {
    puVar2 = *(undefined8 **)(param_2 + 0x20);
    uVar3 = 0xc0000001;
    *puVar2 = 0;
    puVar2[1] = 0;
    *(undefined2 *)(puVar2 + 2) = 0;
    *(undefined1 *)puVar2 = 0xf0;
    *(undefined1 *)((longlong)puVar2 + 7) = 0xb;
    *(undefined2 *)((longlong)puVar2 + 0xc) = 0x20;
    *(byte *)((longlong)puVar2 + 2) = *(byte *)((longlong)puVar2 + 2) & 0xf5 | 5;
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined1 *)(param_2 + 0xb) = 0x12;
    *(undefined2 *)(param_2 + 3) = 0x204;
  }
  return uVar3;
}



===== FUN_000218f0 @ 000218f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_000218f0(longlong param_1,undefined8 *param_2,undefined4 *param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  undefined8 *_Src;
  ulonglong _Size;
  byte bVar6;
  size_t _Size_00;
  undefined8 *_Dst;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined4 local_60;
  undefined8 local_58;
  undefined4 local_50;
  ulonglong local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_88;
  *param_2 = 0;
  bVar6 = 0;
  bVar4 = *(byte *)(param_1 + 0x4a) & 0x3f;
  if ((0x3f < bVar4) || ((0x8000000010000100U >> bVar4 & 1) == 0)) {
    if (*(uint *)(param_1 + 0x10) < 4) {
      *(undefined1 *)(param_1 + 3) = 2;
      return 0xc000000d;
    }
    *param_3 = 0;
    *(undefined1 *)param_3 = 3;
    *(undefined4 *)(param_1 + 0x10) = 4;
    *(undefined1 *)(param_1 + 4) = 0;
    return 0;
  }
  local_68 = 0;
  local_60 = 0;
  local_58 = 0;
  local_50 = 0;
  if ((bVar4 == 8) || (bVar4 == 0x3f)) {
    *param_2 = param_3;
    bVar6 = 0x14;
    local_68 = 0x1208;
  }
  bVar4 = *(byte *)(param_1 + 0x4a) & 0x3f;
  if ((bVar4 == 0x1c) || (bVar4 == 0x3f)) {
    bVar6 = bVar6 + 0xc;
    local_58 = 0xb1c;
  }
  if (*(char *)(param_1 + 0x48) == '\x1a') {
    bVar4 = 4;
    local_48 = CONCAT71((int7)(local_48 >> 8),bVar6 + 3) & 0xffffffff000000ff;
    _Size_00 = 4;
    if (*(uint *)(param_1 + 0x10) < 4) {
      _Size_00 = (size_t)*(uint *)(param_1 + 0x10);
    }
  }
  else {
    _Size_00 = 8;
    if (*(uint *)(param_1 + 0x10) < 8) {
      _Size_00 = (size_t)*(uint *)(param_1 + 0x10);
    }
    bVar4 = 8;
    local_48 = (ulonglong)(ushort)((bVar6 + 6) * 0x100);
  }
  memcpy(param_3,&local_48,_Size_00);
  if ((bVar6 == 0) || (uVar5 = *(uint *)(param_1 + 0x10), uVar5 <= (uint)_Size_00))
  goto LAB_00021abe;
  _Dst = (undefined8 *)(_Size_00 + (longlong)param_3);
  bVar1 = *(byte *)(param_1 + 0x4a) & 0x3f;
  if (bVar1 == 8) {
    uVar5 = uVar5 - bVar4;
    uVar3 = 0x14;
    if (uVar5 < 0x14) {
      uVar3 = uVar5;
    }
    memset(_Dst,0,(ulonglong)uVar3);
    uVar3 = *(int *)(param_1 + 0x10) - (uint)bVar4;
    uVar5 = 0xc;
    if (uVar3 < 0xc) {
      uVar5 = uVar3;
    }
    _Size = (ulonglong)uVar5;
LAB_00021ab2:
    _Src = &local_68;
  }
  else {
    if (bVar1 == 0x1c) {
      uVar5 = uVar5 - bVar4;
    }
    else {
      bVar2 = (char)uVar5 - bVar4;
      bVar1 = 0x14;
      if (bVar2 < 0x14) {
        bVar1 = bVar2;
      }
      local_48 = (ulonglong)bVar1;
      memset(_Dst,0,(ulonglong)bVar1);
      if (bVar1 != 0x14) {
        _Size = local_48;
        goto LAB_00021ab2;
      }
      *_Dst = local_68;
      *(undefined4 *)(_Dst + 1) = local_60;
      _Dst = (undefined8 *)((longlong)_Dst + 0x14);
      uVar5 = (*(int *)(param_1 + 0x10) - (uint)bVar4) - 0x14;
    }
    uVar3 = 0xc;
    if (uVar5 < 0xc) {
      uVar3 = uVar5;
    }
    _Size = (ulonglong)uVar3;
    _Src = &local_58;
  }
  memcpy(_Dst,_Src,_Size);
LAB_00021abe:
  uVar5 = (uint)bVar6 + (uint)bVar4;
  if (*(uint *)(param_1 + 0x10) < uVar5) {
    uVar5 = *(uint *)(param_1 + 0x10);
  }
  *(uint *)(param_1 + 0x10) = uVar5;
  if ((*(byte *)(param_1 + 0x4a) & 0x3f) == 0x3f) {
    uVar3 = bVar4 + 0x14;
    if (uVar5 < uVar3) {
      uVar3 = uVar5;
    }
    *(uint *)(param_1 + 0x10) = uVar3;
  }
  *(undefined1 *)(param_1 + 4) = 0;
  return 0;
}



===== FUN_00021b38 @ 00021b38 =====

undefined8 FUN_00021b38(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  ushort *puVar2;
  undefined8 uVar3;
  
  puVar2 = (ushort *)0x0;
  uVar3 = 0x103;
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined1 *)(param_1 + 0xb) = 0;
    *(undefined2 *)(param_1 + 3) = 1;
    return 0;
  }
  if (*(char *)(param_1 + 0x48) == 'U') {
    puVar2 = (ushort *)(param_1 + 0x4f);
    *puVar2 = *puVar2 << 8 | *puVar2 >> 8;
  }
  if (((*(char *)(param_1 + 0x48) == '\x15') &&
      ((ulonglong)*(byte *)(param_1 + 0x4c) < (ulonglong)*(byte *)(param_2 + 3) + 5)) ||
     ((*(char *)(param_1 + 0x48) == 'U' &&
      ((ulonglong)*puVar2 < (ulonglong)*(ushort *)(param_2 + 6) + 9)))) {
    puVar1 = *(undefined8 **)(param_1 + 0x20);
    uVar3 = 0x80000005;
    *puVar1 = 0;
    puVar1[1] = 0;
    *(undefined2 *)(puVar1 + 2) = 0;
    *(undefined1 *)puVar1 = 0xf0;
    *(undefined1 *)((longlong)puVar1 + 7) = 0xb;
    *(undefined2 *)((longlong)puVar1 + 0xc) = 0x20;
    *(byte *)((longlong)puVar1 + 2) = *(byte *)((longlong)puVar1 + 2) & 0xf5 | 5;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined1 *)(param_1 + 0xb) = 0x12;
    *(undefined2 *)(param_1 + 3) = 0x204;
  }
  return uVar3;
}



===== nvrOsRaidIoControl @ 00021be8 =====

undefined8
nvrOsRaidIoControl(uint param_1,uint param_2,uint *param_3,int *param_4,longlong *param_5)

{
  int *piVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  void *pvVar7;
  longlong lVar8;
  longlong lVar9;
  undefined1 uVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint *puVar13;
  uint uVar14;
  longlong lVar15;
  byte local_res8;
  ulonglong in_stack_ffffffffffffffa0;
  longlong local_48;
  longlong local_40;
  int local_38 [2];
  longlong local_30;
  
  if (param_1 < 10) {
    if (param_1 == 9) {
      if (param_2 < 0xc) goto LAB_000221ba;
      if ((byte)*param_3 < DAT_0002995c) {
        lVar8 = *(longlong *)(DAT_00029960 + (ulonglong)(uint)(byte)*param_3 * 8);
      }
      else {
        lVar8 = 0;
      }
      *(undefined1 *)((longlong)param_3 + 1) = 0;
      *param_4 = -0x3ffffff3;
      if (lVar8 == 0) {
        return 0;
      }
      if (*(longlong *)(lVar8 + 0x58) == 0) {
        return 0;
      }
      *(undefined1 *)((longlong)param_3 + 1) = *(undefined1 *)(*(longlong *)(lVar8 + 0x58) + 0x14);
      uVar6 = *(undefined8 *)(*(longlong *)(lVar8 + 0x58) + 0x58);
      *param_5 = *param_5 + 0xc;
      *(undefined8 *)(param_3 + 1) = uVar6;
    }
    else {
      if (param_1 != 0) {
        if (param_1 == 1) {
          if (10 < param_2) {
            uVar6 = NvRaidApiCreateArray(0x298e0,*param_3,param_3[1],(byte)param_3[2],&local_40);
            *param_4 = (int)uVar6;
            if ((int)uVar6 != 0) {
              return 0;
            }
            if (((*(uint *)(local_40 + 4) & 0x10) != 0) &&
               (NvRaidVolumeAddVolumeToArray(0x298e0,local_40,0xff),
               *(longlong *)(local_40 + 0x58) == 0)) {
              NvRaidVolumeProbeArrayInfo(local_40);
            }
            *(undefined1 *)((longlong)param_3 + 9) = *(undefined1 *)(local_40 + 8);
            *param_5 = *param_5 + 0xb;
            return 0;
          }
          *param_5 = *param_5 + 0xb;
          goto LAB_00022171;
        }
        if (param_1 == 2) {
          if (param_2 != 0) {
            if ((byte)*param_3 < DAT_0002995c) {
              puVar12 = *(undefined4 **)(DAT_00029960 + (ulonglong)(uint)(byte)*param_3 * 8);
            }
            else {
              puVar12 = (undefined4 *)0x0;
            }
            if (puVar12 != (undefined4 *)0x0) {
              if ((*(longlong *)(puVar12 + 4) != 0) &&
                 (lVar8 = *(longlong *)(*(longlong *)(puVar12 + 4) + 0x40),
                 *(int *)(lVar8 + 0xb0) + *(int *)(lVar8 + 0xac) + *(int *)(lVar8 + 0xa8) != 0)) {
LAB_000220c6:
                *param_4 = -0x7fffffef;
                return 0;
              }
              uVar6 = NvRaidApiDestroyVolume(0x298e0,puVar12);
              iVar4 = (int)uVar6;
LAB_000220de:
              *param_4 = iVar4;
              *param_5 = *param_5 + 1;
              return 0;
            }
            goto LAB_00022068;
          }
LAB_00022076:
          *param_5 = *param_5 + 1;
          goto LAB_00022171;
        }
        if (param_1 == 3) {
          if (1 < param_2) {
            if (*(byte *)((longlong)param_3 + 1) < DAT_0002995c) {
              lVar8 = *(longlong *)(DAT_00029960 + (ulonglong)*(byte *)((longlong)param_3 + 1) * 8);
            }
            else {
              lVar8 = 0;
            }
            if ((byte)*param_3 < DAT_0002995c) {
              lVar9 = *(longlong *)(DAT_00029960 + (ulonglong)(byte)*param_3 * 8);
            }
            else {
              lVar9 = 0;
            }
            if (lVar9 != 0) {
              if (((byte)*(undefined4 *)(lVar9 + 4) & 0x21) == 1) {
                *param_4 = -0x3ffffe7b;
                return 0;
              }
              if (lVar8 != 0) {
                uVar6 = NvRaidVolumeAddVolumeToArray(lVar9,lVar8,0xff);
                *param_4 = (int)uVar6;
                *(undefined1 *)((longlong)param_3 + 1) = *(undefined1 *)(lVar8 + 8);
                *param_5 = *param_5 + 2;
                return 0;
              }
            }
            goto LAB_00022068;
          }
          *param_5 = *param_5 + 2;
          goto LAB_00022171;
        }
        if (param_1 == 4) {
          if (7 < param_2) {
            if ((byte)*param_3 < DAT_0002995c) {
              lVar8 = *(longlong *)(DAT_00029960 + (ulonglong)(uint)(byte)*param_3 * 8);
            }
            else {
              lVar8 = 0;
            }
            *param_4 = -0x3ffffff3;
            if (lVar8 == 0) {
              return 0;
            }
            lVar9 = *(longlong *)(lVar8 + 0x58);
            if (lVar9 == 0) {
              return 0;
            }
            if (*(char *)(lVar9 + 0x14) == '\0') {
              if ((lVar8 == -0x78) ||
                 (*(uint *)(lVar8 + 0x7c) <= (uint)*(byte *)((longlong)param_3 + 1))) {
                lVar15 = 0;
              }
              else {
                lVar15 = *(longlong *)
                          (*(longlong *)(lVar8 + 0x80) +
                          (ulonglong)*(byte *)((longlong)param_3 + 1) * 8);
              }
              if (lVar15 == 0) {
                return 0;
              }
              uVar5 = (**(code **)(*(longlong *)(lVar9 + 0x88) + 0x30))
                                (lVar8,(uint)*(byte *)(lVar15 + 8) << 8 | 2);
              if ((uVar5 & 6) != 0) {
                *(uint *)(lVar15 + 4) = *(uint *)(lVar15 + 4) | 0x100;
                (**(code **)(*(longlong *)(*(longlong *)(lVar8 + 0x58) + 0x88) + 0x30))(lVar8,1);
              }
            }
            (**(code **)(*(longlong *)(*(longlong *)(lVar8 + 0x58) + 0x88) + 0x30))(lVar8,9);
            uVar5 = (ulonglong)param_3[1];
            uVar10 = 3;
LAB_00021fbc:
            uVar6 = NvRaidJobScheduleRequest(lVar8,uVar10,uVar5,1,0,0);
            *param_4 = (int)uVar6;
            goto LAB_00021fd3;
          }
          goto LAB_00022169;
        }
        if (param_1 == 5) {
          if (param_2 != 0) {
            if ((byte)*param_3 < DAT_0002995c) {
              lVar8 = *(longlong *)(DAT_00029960 + (ulonglong)(uint)(byte)*param_3 * 8);
            }
            else {
              lVar8 = 0;
            }
            if ((lVar8 != 0) && (*(longlong *)(lVar8 + 0x10) == 0)) {
              uVar6 = NvRaidJobScheduleRequest(lVar8,2,0,0,0,0);
              iVar4 = (int)uVar6;
              goto LAB_000220de;
            }
            goto LAB_00022068;
          }
          goto LAB_00022076;
        }
        if (param_1 == 6) {
          lVar8 = *(longlong *)(scsiRaidController + 0x40);
          if (7 < param_2) {
            if ((byte)*param_3 < DAT_0002995c) {
              lVar9 = *(longlong *)(DAT_00029960 + (ulonglong)(uint)(byte)*param_3 * 8);
            }
            else {
              lVar9 = 0;
            }
            iVar4 = -0x3ffffff3;
            *param_4 = -0x3ffffff3;
            if (lVar9 == 0) {
              return 0;
            }
            uVar14 = param_3[1];
            if (uVar14 == 0x83) {
              bVar3 = *(byte *)(lVar8 + 0x348);
LAB_00021e6e:
              if ((~bVar3 & 1) != 0) {
                return 0;
              }
            }
            else if ((uVar14 == 0x85) || (uVar14 == 0x95)) {
              bVar3 = *(byte *)(lVar8 + 0x348) >> 1;
              goto LAB_00021e6e;
            }
            if (*(longlong *)(lVar9 + 0x58) != 0) {
              uVar6 = NvRaidApiMorphArray(lVar9,uVar14,*(byte *)((longlong)param_3 + 1),
                                          *(longlong *)(lVar9 + 0x58));
              iVar4 = (int)uVar6;
            }
            *param_4 = iVar4;
            goto LAB_00021fd3;
          }
        }
        else {
          if (param_1 != 7) {
            if (param_1 != 8) {
              return 0xc0000010;
            }
            lVar8 = 0;
            local_48 = 0;
            local_res8 = 0;
            if (param_2 < 0x3c) {
              *param_4 = -0x3fffffdd;
              *param_5 = *param_5 + 0x3c;
              return 0;
            }
            bVar3 = (byte)param_3[1];
            if (bVar3 == 0xff) {
              *param_3 = DAT_00029958;
            }
            else {
              if (bVar3 < DAT_0002995c) {
                lVar8 = *(longlong *)(DAT_00029960 + (ulonglong)(uint)bVar3 * 8);
              }
              if (lVar8 == 0) {
                return 0;
              }
              if (*(longlong *)(lVar8 + 0x58) == 0) {
                memset(param_3,0,(ulonglong)param_2);
                return 0;
              }
              *param_3 = 0;
            }
            uVar14 = param_2 - 8;
            puVar13 = param_3 + 2;
            do {
              if (bVar3 == 0xff) {
                NvRaidApiEnumerateRootVolumes(0x298e0,&local_48);
              }
              else {
                do {
                  if (((uint *)(lVar8 + 0x78) == (uint *)0x0) ||
                     (*(uint *)(lVar8 + 0x7c) <= (uint)local_res8)) {
                    local_48 = 0;
                  }
                  else {
                    local_48 = *(longlong *)
                                (*(longlong *)(lVar8 + 0x80) + (ulonglong)(uint)local_res8 * 8);
                  }
                  local_res8 = local_res8 + 1;
                  if (local_48 == 0) {
                    if (*(uint *)(lVar8 + 0x78) <= *param_3) break;
                  }
                  else {
                    *param_3 = *param_3 + 1;
                  }
                } while (local_48 == 0);
              }
              if (local_48 == 0) break;
              *(undefined1 *)puVar13 = *(undefined1 *)(local_48 + 8);
              *(undefined8 *)(puVar13 + 10) = *(undefined8 *)(local_48 + 0x20);
              uVar11 = *(uint *)(local_48 + 0x28);
              puVar13[2] = 0;
              puVar13[0xc] = uVar11;
              puVar13[1] = *(uint *)(local_48 + 4);
              if (*(longlong *)(local_48 + 0x58) != 0) {
                puVar13[2] = *(uint *)(*(longlong *)(local_48 + 0x58) + 0x18);
              }
              uVar14 = uVar14 - 0x34;
              *(undefined8 *)(puVar13 + 3) = *(undefined8 *)(local_48 + 0x2c);
              *(undefined8 *)(puVar13 + 5) = *(undefined8 *)(local_48 + 0x34);
              *(undefined8 *)(puVar13 + 7) = *(undefined8 *)(local_48 + 0x3c);
              puVar13[9] = *(uint *)(local_48 + 0x44);
              puVar13 = puVar13 + 0xd;
            } while (0x33 < uVar14);
            uVar5 = (ulonglong)(param_2 - uVar14);
LAB_00021db1:
            *param_5 = *param_5 + uVar5;
            return 0;
          }
          if (7 < param_2) {
            if ((byte)*param_3 < DAT_0002995c) {
              lVar8 = *(longlong *)(DAT_00029960 + (ulonglong)(uint)(byte)*param_3 * 8);
            }
            else {
              lVar8 = 0;
            }
            *param_4 = -0x3ffffff3;
            if (lVar8 == 0) {
              return 0;
            }
            uVar5 = (ulonglong)param_3[1];
            uVar10 = 4;
            goto LAB_00021fbc;
          }
        }
LAB_00022169:
        *param_5 = *param_5 + 8;
LAB_00022171:
        *param_4 = -0x3fffffdd;
        return 0;
      }
      if (param_2 < 8) goto LAB_00022169;
      if (*param_3 != 0x4144564e) {
        return 0;
      }
      if (0x100 < param_3[1]) {
        return 0;
      }
      *param_3 = 0x44494152;
      param_3[1] = 0x100;
      *param_5 = *param_5 + 8;
    }
LAB_000227de:
    *param_4 = 0;
  }
  else {
    if (param_1 == 10) {
      if (param_2 < 0x10) {
        *param_5 = *param_5 + 0x10;
        goto LAB_00022171;
      }
      if ((byte)*param_3 < DAT_0002995c) {
        lVar8 = *(longlong *)(DAT_00029960 + (ulonglong)(uint)(byte)*param_3 * 8);
      }
      else {
        lVar8 = 0;
      }
      *(undefined1 *)((longlong)param_3 + 1) = 0;
      *param_4 = -0x3ffffff3;
      if (lVar8 == 0) {
        return 0;
      }
      lVar8 = *(longlong *)(lVar8 + 0x58);
      if (lVar8 == 0) {
        return 0;
      }
      *(undefined1 *)((longlong)param_3 + 1) = *(undefined1 *)(lVar8 + 0x14);
      *(undefined1 *)((longlong)param_3 + 2) = *(undefined1 *)(lVar8 + 0x15);
      *(undefined1 *)((longlong)param_3 + 3) = *(undefined1 *)(lVar8 + 0x17);
      param_3[1] = *(uint *)(lVar8 + 0x18);
      param_3[2] = *(uint *)(lVar8 + 0x20);
      param_3[3] = *(uint *)(lVar8 + 0x38);
      *param_5 = *param_5 + 0x10;
      goto LAB_000227de;
    }
    if (param_1 == 0xb) {
      if (0xb < param_2) {
        if ((byte)*param_3 < DAT_0002995c) {
          lVar8 = *(longlong *)(DAT_00029960 + (ulonglong)(uint)(byte)*param_3 * 8);
        }
        else {
          lVar8 = 0;
        }
        *param_4 = -0x3ffffff3;
        if (lVar8 == 0) {
          return 0;
        }
        lVar9 = *(longlong *)(lVar8 + 0x58);
        if (lVar9 == 0) {
          return 0;
        }
        uVar14 = *(uint *)(lVar9 + 0x40);
        uVar11 = ~param_3[2] & uVar14;
        *(uint *)(lVar9 + 0x40) = uVar11;
        uVar11 = param_3[1] | uVar11;
        *(uint *)(lVar9 + 0x40) = uVar11;
        param_3[1] = uVar11;
        if (uVar14 != *(uint *)(lVar9 + 0x40)) {
          NvRaidJobScheduleRequest(lVar8,1,0,0,0,0);
        }
        *param_4 = 0;
        *param_5 = *param_5 + 0xc;
        return 0;
      }
LAB_000221ba:
      *param_5 = *param_5 + 0xc;
      goto LAB_00022171;
    }
    if (param_1 == 0xc) {
      if (3 < param_2) {
        if ((byte)*param_3 < DAT_0002995c) {
          puVar12 = *(undefined4 **)(DAT_00029960 + (ulonglong)(uint)(byte)*param_3 * 8);
        }
        else {
          puVar12 = (undefined4 *)0x0;
        }
        *param_4 = -0x3ffffff3;
        if (puVar12 == (undefined4 *)0x0) {
          return 0;
        }
        if (*(longlong *)(puVar12 + 0x16) == 0) {
          return 0;
        }
        if ((puVar12 == (undefined4 *)0xffffffffffffff88) ||
           ((uint)puVar12[0x1f] <= (uint)*(byte *)((longlong)param_3 + 1))) {
          lVar8 = 0;
        }
        else {
          lVar8 = *(longlong *)
                   (*(longlong *)(puVar12 + 0x20) + (ulonglong)*(byte *)((longlong)param_3 + 1) * 8)
          ;
        }
        if (lVar8 == 0) {
          return 0;
        }
        if ((*(uint *)(lVar8 + 4) & 0x100) == 0) {
          *param_4 = -0x3ffffff3;
        }
        else {
          uVar6 = NvRaidVolumeDeleteVolumeFromArray(puVar12,lVar8);
          *param_4 = (int)uVar6;
        }
        *param_5 = *param_5 + 4;
        return 0;
      }
LAB_00022637:
      *param_5 = *param_5 + 4;
      goto LAB_00022171;
    }
    if (param_1 == 0xd) {
      if (7 < param_2) {
        if ((byte)*param_3 < DAT_0002995c) {
          lVar8 = *(longlong *)(DAT_00029960 + (ulonglong)(uint)(byte)*param_3 * 8);
        }
        else {
          lVar8 = 0;
        }
        *param_4 = -0x3ffffff3;
        if (lVar8 == 0) {
          return 0;
        }
        uVar5 = (ulonglong)param_3[1];
        uVar10 = 5;
        goto LAB_00021fbc;
      }
      goto LAB_00022169;
    }
    if (param_1 != 0xf) {
      if (param_1 == 0x80000000) {
        if (param_2 < 0x14) {
          *param_5 = *param_5 + 0x14;
        }
        else {
          uVar14 = param_3[2];
          uVar11 = param_3[3];
          uVar2 = uVar11;
          if (uVar11 < uVar14) {
            uVar2 = uVar14;
          }
          if ((ulonglong)uVar2 + 0x14 <= (ulonglong)param_2) {
            if ((byte)*param_3 < DAT_0002995c) {
              lVar8 = *(longlong *)(DAT_00029960 + (ulonglong)(uint)(byte)*param_3 * 8);
            }
            else {
              lVar8 = 0;
            }
            *param_4 = -0x3ffffff3;
            if (lVar8 != 0) {
              if (*(longlong *)(lVar8 + 0x58) != 0) {
                if ((lVar8 == -0x78) ||
                   (*(uint *)(lVar8 + 0x7c) <= (uint)*(byte *)((longlong)param_3 + 1))) {
                  lVar8 = 0;
                }
                else {
                  lVar8 = *(longlong *)
                           (*(longlong *)(lVar8 + 0x80) +
                           (ulonglong)*(byte *)((longlong)param_3 + 1) * 8);
                }
                if ((lVar8 == 0) || (*(longlong *)(lVar8 + 0x58) != 0)) goto LAB_00022068;
              }
              if (*(longlong *)(lVar8 + 0x10) != 0) {
                ClassSendDeviceIoControlSynchronous
                          (param_3[1],*(longlong *)(lVar8 + 0x10),param_3 + 4,param_3[2],param_3[3],
                           in_stack_ffffffffffffffa0 & 0xffffffffffffff00,local_38);
                *param_4 = local_38[0];
                uVar5 = local_30 + 0x10;
                goto LAB_00021db1;
              }
            }
LAB_00022068:
            *param_4 = -0x3ffffff3;
            return 0;
          }
          if (uVar11 < uVar14) {
            uVar11 = uVar14;
          }
          *param_5 = *param_5 + (ulonglong)uVar11 + 0x14;
        }
        goto LAB_00022171;
      }
      if (param_1 == 0x80000001) {
        if (3 < param_2) {
          if ((byte)*param_3 < DAT_0002995c) {
            lVar8 = *(longlong *)(DAT_00029960 + (ulonglong)(uint)(byte)*param_3 * 8);
          }
          else {
            lVar8 = 0;
          }
          if (lVar8 != 0) {
            if (*(longlong *)(lVar8 + 0x10) != 0) goto LAB_000220c6;
            if (scsiRaidController != 0) {
              LOCK();
              piVar1 = (int *)(*(longlong *)(scsiRaidController + 0x40) + 0x344);
              *piVar1 = *piVar1 + 1;
              UNLOCK();
              nvrScsiPortInvalidateDeviceRelations();
            }
            puVar12 = NvRaidResNrpAllocate(0x298e0);
            if (puVar12 == (undefined4 *)0x0) goto LAB_000223ba;
            uVar6 = NvRaidResBufferAllocateForNrp(0x298e0,*(uint *)(lVar8 + 0x28),(longlong)puVar12)
            ;
            if ((int)uVar6 != 0) {
              FUN_00023010(lVar8,puVar12);
              *param_4 = -0x3fffffe9;
              return 0;
            }
            memset(*(void **)(*(longlong *)(puVar12 + 0x2a) + 0x18),0,
                   (ulonglong)*(uint *)(lVar8 + 0x28));
            *(longlong *)(puVar12 + 0x1c) = lVar8;
            NvRaidScsiSetupReadWrite
                      ((longlong)puVar12,*(undefined1 *)(lVar8 + 8),lVar8,FUN_00023010,0x2a,0,1);
            NvRaidPacketSubmitRequest((longlong)puVar12);
LAB_0002243b:
            *param_4 = 0;
            return 0;
          }
          goto LAB_00022068;
        }
      }
      else {
        if (param_1 != 0x80000002) {
          if (param_1 != 0x80000003) {
            return 0xc0000010;
          }
          if (0x410 < param_2) {
            uVar6 = NvRaidApiGetMetadataForSingleDiskStripe
                              (0x298e0,*param_3,param_3[1],(byte)param_3[2],
                               *(longlong *)((longlong)param_3 + 9),
                               (int *)((longlong)param_3 + 0x11));
            *param_4 = (int)uVar6;
            if ((int)uVar6 == 0) {
              *param_5 = *param_5 + 0x411;
              return 0;
            }
            return 0;
          }
          *param_5 = *param_5 + 0x411;
          goto LAB_00022171;
        }
        if (3 < param_2) {
          if ((byte)*param_3 < DAT_0002995c) {
            lVar8 = *(longlong *)(DAT_00029960 + (ulonglong)(uint)(byte)*param_3 * 8);
          }
          else {
            lVar8 = 0;
          }
          if (lVar8 != 0) {
            pvVar7 = NvRaidResNrpAllocate(*(longlong *)(lVar8 + 0x18));
            if (pvVar7 == (void *)0x0) {
LAB_000223ba:
              *param_4 = -0x3fffff66;
              return 0;
            }
            *(longlong *)((longlong)pvVar7 + 0x40) = lVar8;
            *(undefined1 *)((longlong)pvVar7 + 0x48) = *(undefined1 *)(lVar8 + 8);
            *(code **)((longlong)pvVar7 + 0xa0) = NvRaidStateSubRequestsDone;
            *(undefined ***)((longlong)pvVar7 + 0x58) = &PTR_FUN_00027de0;
            FUN_00011e84((longlong)pvVar7);
            goto LAB_0002243b;
          }
          goto LAB_00022068;
        }
      }
      goto LAB_00022637;
    }
    if (param_2 < 8) goto LAB_00022169;
    if ((byte)*param_3 < DAT_0002995c) {
      lVar8 = *(longlong *)(DAT_00029960 + (ulonglong)(uint)(byte)*param_3 * 8);
    }
    else {
      lVar8 = 0;
    }
    *param_4 = -0x3ffffff3;
    if ((((lVar8 != 0) && (lVar9 = *(longlong *)(lVar8 + 0x58), lVar9 != 0)) &&
        (*(int *)(lVar9 + 0x18) == 0x81)) &&
       ((uVar14 = param_3[1], uVar14 != 0 && ((uVar14 & uVar14 - 1) == 0)))) {
      uVar11 = 1;
      *(uint *)(lVar9 + 0x1c) = uVar14;
      *(undefined4 *)(lVar9 + 0x24) = 0;
      *(uint *)(lVar9 + 0x20) = uVar14 << 9;
      if ((uVar14 & 1) == 0) {
        iVar4 = 0;
        do {
          uVar11 = uVar11 * 2;
          iVar4 = iVar4 + 1;
        } while ((uVar11 & uVar14) == 0);
        *(int *)(lVar9 + 0x24) = iVar4;
      }
      NvRaidJobScheduleRequest(lVar8,1,0,0,0,0);
      *param_4 = 0;
    }
LAB_00021fd3:
    *param_5 = *param_5 + 8;
  }
  return 0;
}



===== FUN_00022804 @ 00022804 =====

undefined8 FUN_00022804(longlong param_1)

{
  longlong lVar1;
  
  if ((*(longlong *)(param_1 + 0x10) != 0) &&
     (lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40),
     (*(byte *)(lVar1 + 0x68) & 1) != 0)) {
    KeSetEvent(*(longlong *)(lVar1 + 0x60) + 0x150,0,0);
  }
  return 0;
}



===== FUN_00022838 @ 00022838 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_00022838(longlong param_1,uint param_2,longlong param_3)

{
  uint *puVar1;
  undefined4 *puVar2;
  longlong lVar3;
  byte *pbVar4;
  longlong lVar5;
  uint uVar6;
  undefined8 uVar7;
  uint uVar8;
  longlong lVar9;
  byte bVar10;
  ulonglong uVar11;
  undefined1 auStack_68 [32];
  int local_48 [4];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_68;
  if (0x82 < param_2) {
    if (param_2 != 0x83) {
      return 0;
    }
    lVar9 = *(longlong *)(param_1 + 0x10);
    NvRaidSyncAtomicSpinLockAcquire();
    if (lVar9 != 0) {
      NvRaidSyncAtomicSpinLockRelease();
      nvrOsShutdownPdo(lVar9,0);
      return 0;
    }
    lVar9 = *(longlong *)(param_1 + 0x58);
    if (lVar9 == 0) {
      return 0;
    }
    if (*(char *)(lVar9 + 0xa8) == '\0') {
      return 0;
    }
    if ((*(uint *)(param_1 + 4) & 0x40) != 0) {
      return 0;
    }
    uVar11 = 0;
    if (*(char *)(lVar9 + 0xa8) != '\0') {
      do {
        lVar3 = *(longlong *)(*(longlong *)(lVar9 + 0xa0) + uVar11 * 8);
        pbVar4 = *(byte **)(lVar3 + 0xb8);
        lVar5 = *(longlong *)(pbVar4 + 0x28);
        NvRaidSyncAtomicSpinLockRelease();
        (**(code **)(*(longlong *)(lVar5 + 8) + 0x70 + (ulonglong)*pbVar4 * 8))(lVar5,lVar3);
        NvRaidSyncAtomicSpinLockAcquire();
        bVar10 = (char)uVar11 + 1;
        uVar11 = (ulonglong)bVar10;
      } while (bVar10 < *(byte *)(lVar9 + 0xa8));
    }
    *(undefined1 *)(lVar9 + 0xa8) = 0;
    ExFreePoolWithTag(*(undefined8 *)(lVar9 + 0xa0),0);
    *(undefined8 *)(lVar9 + 0xa0) = 0;
    NvRaidSyncAtomicSpinLockRelease();
    return 0;
  }
  if (param_2 == 0x82) {
    if (*(longlong *)(param_1 + 0x10) == 0) {
      return 0;
    }
    puVar2 = *(undefined4 **)
              (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x10) + 0x40) + 0x60) + 0x10);
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    *puVar2 = 0;
    return 0;
  }
  switch(param_2) {
  case 1:
  case 2:
  case 7:
    if (param_1 != 0) {
      lVar9 = *(longlong *)(param_1 + 0x10);
      if (param_1 != *(longlong *)(param_1 + 0x18)) {
        if (lVar9 == 0) {
          if ((*(uint *)(param_1 + 4) & 6) != 0) {
            nvrScsiPortInvalidateDeviceRelations();
          }
        }
        else {
          nvrOsUpdateCheckDuplicateMdlPage(lVar9);
          if ((*(uint *)(param_1 + 4) & 2) != 0) {
            FUN_00022f70(lVar9);
          }
        }
      }
      if (param_2 == 2) {
        if (param_3 == 0) goto switchD_00022898_caseD_3;
        local_48[0] = 0;
        local_48[1] = 0;
        local_48[2] = 0;
        if (param_1 == *(longlong *)(param_3 + 0x18)) {
          lVar9 = 0;
        }
        else {
          lVar9 = *(longlong *)(param_1 + 0x10);
        }
        lVar3 = *(longlong *)(param_3 + 0x10);
        if (lVar9 != 0) {
          lVar9 = *(longlong *)(lVar9 + 0x40);
          local_48[2] = *(undefined4 *)(lVar9 + 0xac);
          local_48[1] = *(undefined4 *)(lVar9 + 0xb0);
          local_48[0] = *(undefined4 *)(lVar9 + 0xa8);
        }
        if ((lVar3 != 0) && ((*(byte *)(*(longlong *)(lVar3 + 0x40) + 0x68) & 1) != 0)) {
          FUN_0001d4a8(lVar3,local_48,*(longlong *)(lVar3 + 0x40));
        }
      }
    }
    if ((((param_3 != 0) && (*(longlong *)(param_3 + 0x58) == 0)) &&
        (lVar9 = *(longlong *)(*(longlong *)(param_3 + 0x10) + 0x40),
        (*(byte *)(lVar9 + 0x68) & 1) != 0)) &&
       (*(longlong *)(*(longlong *)(lVar9 + 0x60) + 200) != 0)) {
      nvrOsShutdownFdo(param_3);
    }
  case 3:
  case 4:
switchD_00022898_caseD_3:
    nvrPerformSgpioUpdate(param_1,param_2,param_3);
    break;
  case 5:
    if (((param_3 != 0) && (*(longlong *)(param_3 + 0x58) != 0)) &&
       (*(longlong *)(param_3 + 0x10) != 0)) {
      lVar9 = *(longlong *)(*(longlong *)(param_3 + 0x10) + 0x40);
      **(undefined8 **)(lVar9 + 0x60) = 0;
      nvrClassMarkChildMissing(lVar9);
      nvrScsiPortInvalidateDeviceRelations();
    }
    break;
  case 10:
  case 0xd:
  case 0x10:
  case 0x14:
    if (param_1 != 0) {
      lVar9 = *(longlong *)(param_1 + 0x10);
      if ((*(uint *)(param_1 + 4) & 0x400) != 0) {
        if (lVar9 == 0) {
          lVar3 = *(longlong *)(param_1 + 0x58);
          if (((lVar3 != 0) && (*(char *)(lVar3 + 0x14) == '\x02')) &&
             ((*(uint *)(lVar3 + 0x98) & 1) == 0)) {
            uVar8 = *(uint *)(lVar3 + 0x98) | 1;
            while( true ) {
              LOCK();
              uVar6 = *(uint *)(lVar3 + 0x98);
              *(uint *)(lVar3 + 0x98) = uVar8;
              UNLOCK();
              uVar6 = uVar6 | 1;
              if (uVar6 == uVar8) break;
              uVar8 = uVar6;
            }
          }
        }
        else {
          lVar3 = *(longlong *)(*(longlong *)(lVar9 + 0x40) + 0x60);
          uVar8 = *(uint *)(lVar3 + 0x1c);
          if ((uVar8 & 2) == 0) {
            uVar8 = uVar8 | 2;
            while( true ) {
              LOCK();
              puVar1 = (uint *)(lVar3 + 0x1c);
              uVar6 = *puVar1;
              *puVar1 = uVar8;
              UNLOCK();
              uVar6 = uVar6 | 2;
              if (uVar6 == uVar8) break;
              uVar8 = uVar6;
            }
          }
          nvrPerformSgpioUpdate(param_1,param_2,0);
        }
      }
      if ((*(uint *)(param_1 + 4) & 0x10000) != 0) {
        NvRaidVolumeSendCommandToVolumes(param_1,FUN_00022804,0);
      }
      if (lVar9 != 0) {
        lVar3 = *(longlong *)(*(longlong *)(lVar9 + 0x40) + 0x60);
        uVar7 = PoRegisterDeviceForIdleDetection(lVar9,0xffffffff,0xffffffff,4);
        *(undefined8 *)(lVar3 + 0x10) = uVar7;
      }
    }
    if (param_2 == 0xd) {
      if (param_1 == 0) {
        return 0;
      }
      if ((*(longlong *)(param_1 + 0x58) != 0) &&
         (*(char *)(*(longlong *)(param_1 + 0x58) + 0x14) == '\0')) {
        nvrScsiPortInvalidateDeviceRelations();
      }
    }
  case 6:
  case 9:
  case 0xc:
  case 0xf:
  case 0x13:
    if (param_1 != 0) {
      lVar9 = *(longlong *)(param_1 + 0x10);
      if (lVar9 != 0) {
        lVar3 = *(longlong *)(*(longlong *)(lVar9 + 0x40) + 0x60);
        uVar7 = PoRegisterDeviceForIdleDetection(lVar9,0,0,4);
        *(undefined8 *)(lVar3 + 0x10) = uVar7;
      }
      nvrPerformSgpioUpdate(param_1,param_2,0);
      nvrOsUpdateCheckDuplicateMdlPage(lVar9);
    }
  }
  return 0;
}



===== nvrOsShutdownFdo @ 00022c60 =====

undefined8 nvrOsShutdownFdo(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  byte *pbVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x10);
  lVar2 = *(longlong *)(lVar1 + 0x40);
  lVar3 = *(longlong *)(lVar2 + 0x60);
  if (((*(byte *)(lVar2 + 0x68) & 1) != 0) && (lVar2 = *(longlong *)(lVar3 + 200), lVar2 != 0)) {
    pbVar4 = *(byte **)(lVar2 + 0xb8);
    *(undefined8 *)(lVar3 + 200) = 0;
    (**(code **)(*(longlong *)(lVar1 + 8) + 0x70 + (ulonglong)*pbVar4 * 8))();
  }
  return 0;
}



===== nvrOsShutdownPdo @ 00022ca8 =====

/* WARNING: Removing unreachable block (ram,0x00022e2d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nvrOsShutdownPdo(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  uint uVar6;
  byte bVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  
  uVar9 = 0;
  plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x40) + 0x60);
  if (*plVar2 != 0) {
    uVar6 = NvRaidSyncSpinLockAcquire(0xffffffff);
    if (*(char *)(*plVar2 + 10) == '\0') {
      if (param_2 == 0) {
        while (((int)plVar2[0x12] != 0 && (*(char *)(*plVar2 + 10) == '\0'))) {
          uVar8 = 0;
          do {
            lVar3 = plVar2[uVar8 + 10];
            if (lVar3 != 0) {
              plVar2[uVar8 + 10] = 0;
              *(int *)(plVar2 + 0x12) = (int)plVar2[0x12] + -1;
              break;
            }
            bVar7 = (char)uVar8 + 1;
            uVar8 = (ulonglong)bVar7;
          } while (bVar7 < 8);
          pbVar1 = *(byte **)(lVar3 + 0xb8);
          NvRaidSyncSpinLockRelease(uVar6);
          (**(code **)(*(longlong *)(param_1 + 8) + 0x70 + (ulonglong)*pbVar1 * 8))(param_1,lVar3);
          uVar6 = NvRaidSyncSpinLockAcquire(0xffffffff);
        }
      }
    }
    else if (param_2 != 0) {
      uVar8 = 0;
      do {
        if (plVar2[uVar8 + 10] == 0) {
          plVar2[uVar8 + 10] = param_2;
          *(int *)(plVar2 + 0x12) = (int)plVar2[0x12] + 1;
          break;
        }
        bVar7 = (char)uVar8 + 1;
        uVar8 = (ulonglong)bVar7;
      } while (bVar7 < 8);
      uVar9 = 0x103;
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      *(uint *)(*plVar2 + 4) = *(uint *)(*plVar2 + 4) | 0x400;
    }
    NvRaidSyncSpinLockRelease(uVar6);
  }
  uVar6 = NvRaidSyncSpinLockAcquire(2);
  lVar3 = *plVar2;
  puVar4 = DAT_00029980;
  while (puVar5 = puVar4, puVar5 != (undefined8 *)0x0) {
    puVar4 = (undefined8 *)*puVar5;
    if (puVar5[5] == lVar3) {
      if (puVar4 == (undefined8 *)0x0) {
        _DAT_00029988 = puVar5[1];
      }
      else {
        puVar4[1] = puVar5[1];
      }
      *(undefined8 *)puVar5[1] = *puVar5;
      (*(code *)puVar5[2])(puVar5[3]);
      *(undefined4 *)puVar5 = 0x30;
      puVar5[1] = DAT_00029990;
      DAT_00029990 = puVar5;
    }
  }
  if ((DAT_000290b4 & 8) == 0) {
    DAT_000290b4 = DAT_000290b4 | 8;
    LOCK();
    UNLOCK();
  }
  NvRaidSyncSpinLockRelease(uVar6);
  return uVar9;
}



===== FUN_00022e64 @ 00022e64 =====

undefined8 FUN_00022e64(byte param_1,longlong param_2,undefined8 param_3,undefined4 param_4)

{
  undefined1 uVar4;
  undefined1 uVar3;
  undefined1 uVar2;
  undefined1 uVar1;
  
  uVar1 = (undefined1)((ulonglong)param_3 >> 8);
  uVar2 = (undefined1)((ulonglong)param_3 >> 0x10);
  uVar3 = (undefined1)((ulonglong)param_3 >> 0x18);
  uVar4 = (undefined1)((uint)param_4 >> 8);
  if (param_1 != 0x28) {
    if (param_1 < 0x2a) {
      return 0xc0000001;
    }
    if (0x2b < param_1) {
      if (param_1 < 0x2e) {
        return 0xc0000001;
      }
      if (0x2f < param_1) {
        if (7 < (byte)(param_1 + 0x78)) {
          return 0xc0000001;
        }
        if ((0xc5U >> (param_1 + 0x78 & 0x1f) & 1) == 0) {
          return 0xc0000001;
        }
        *(undefined8 *)(param_2 + 0x48) = 0;
        *(undefined8 *)(param_2 + 0x50) = 0;
        *(byte *)(param_2 + 0x48) = param_1;
        *(char *)(param_2 + 0x51) = (char)param_3;
        *(char *)(param_2 + 0x4a) = (char)((ulonglong)param_3 >> 0x38);
        *(char *)(param_2 + 0x55) = (char)param_4;
        *(char *)(param_2 + 0x4b) = (char)((ulonglong)param_3 >> 0x30);
        *(char *)(param_2 + 0x4c) = (char)((ulonglong)param_3 >> 0x28);
        *(char *)(param_2 + 0x4d) = (char)((ulonglong)param_3 >> 0x20);
        *(undefined1 *)(param_2 + 0x4e) = uVar3;
        *(undefined1 *)(param_2 + 0x4f) = uVar2;
        *(undefined1 *)(param_2 + 0x50) = uVar1;
        *(char *)(param_2 + 0x52) = (char)((uint)param_4 >> 0x18);
        *(char *)(param_2 + 0x53) = (char)((uint)param_4 >> 0x10);
        *(undefined1 *)(param_2 + 0x54) = uVar4;
        *(undefined1 *)(param_2 + 10) = 0x10;
        return 0;
      }
    }
  }
  *(undefined8 *)(param_2 + 0x48) = 0;
  *(undefined8 *)(param_2 + 0x50) = 0;
  *(byte *)(param_2 + 0x48) = param_1;
  *(char *)(param_2 + 0x4d) = (char)param_3;
  *(undefined1 *)(param_2 + 0x4a) = uVar3;
  *(char *)(param_2 + 0x50) = (char)param_4;
  *(undefined1 *)(param_2 + 0x4b) = uVar2;
  *(undefined1 *)(param_2 + 0x4c) = uVar1;
  *(undefined1 *)(param_2 + 0x4f) = uVar4;
  *(undefined1 *)(param_2 + 10) = 10;
  return 0;
}



===== FUN_00022f70 @ 00022f70 =====

void FUN_00022f70(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
  LOCK();
  iVar1 = *(int *)(lVar2 + 0x98);
  *(int *)(lVar2 + 0x98) = 0;
  UNLOCK();
  if (iVar1 != 0) {
    nvrPdoUnlockQueue(param_1);
    if (*(char *)(lVar2 + 0x1c) < '\0') {
      LOCK();
      iVar1 = *(int *)(lVar2 + 0x9c);
      *(int *)(lVar2 + 0x9c) = 0;
      UNLOCK();
      if (iVar1 != 0) {
        IoStopTimer(param_1);
      }
    }
  }
  return;
}



===== nvrOsResumeRaidJob @ 00022fc0 =====

void nvrOsResumeRaidJob(longlong param_1)

{
  char cVar1;
  int iVar2;
  
  if ((param_1 != 0) && (*(longlong *)(param_1 + 0x58) != 0)) {
    if ((*(uint *)(param_1 + 4) >> 0xe & 1) == 0) {
      cVar1 = *(char *)(*(longlong *)(param_1 + 0x58) + 0x14);
      if (cVar1 == '\0') {
        return;
      }
      iVar2 = 0x1e;
    }
    else {
      iVar2 = 0;
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffbfff;
      cVar1 = '\b';
    }
    NvRaidJobScheduleRequest(param_1,cVar1,0,iVar2,0,0);
  }
  return;
}



===== FUN_00023010 @ 00023010 =====

undefined8 FUN_00023010(undefined8 param_1,undefined4 *param_2)

{
  int *piVar1;
  
  NvRaidResNrpFree(0x298e0,param_2);
  if (scsiRaidController != 0) {
    if ((*(uint *)(*(longlong *)(scsiRaidController + 0x40) + 0x344) & 0x7fffffff) != 0) {
      LOCK();
      piVar1 = (int *)(*(longlong *)(scsiRaidController + 0x40) + 0x344);
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    nvrScsiPortInvalidateDeviceRelations();
  }
  return 0;
}



===== FUN_00023050 @ 00023050 =====

undefined8 FUN_00023050(undefined8 param_1,undefined4 *param_2)

{
  NvRaidResNrpFree(0x298e0,param_2);
  return 0;
}



===== nvrOsUpdateCheckDuplicateMdlPage @ 00023068 =====

ulonglong nvrOsUpdateCheckDuplicateMdlPage(longlong param_1)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong in_RAX;
  char cVar5;
  
  cVar5 = '\0';
  if (param_1 != 0) {
    in_RAX = *(ulonglong *)(param_1 + 0x40);
    plVar2 = *(longlong **)(in_RAX + 0x60);
    lVar3 = *plVar2;
    if ((lVar3 != 0) && (lVar4 = *(longlong *)(lVar3 + 0x58), lVar4 != 0)) {
      iVar1 = *(int *)(lVar4 + 0x18);
      if (((iVar1 == 0x83) || ((iVar1 == 0x85 || (iVar1 == 0x95)))) &&
         ((in_RAX = (ulonglong)*(uint *)(lVar3 + 4), (*(uint *)(lVar3 + 4) & 4) != 0 ||
          (*(char *)(lVar4 + 0x14) == '\x03')))) {
        cVar5 = '\x01';
      }
      *(byte *)((longlong)plVar2 + 0x1c) =
           *(byte *)((longlong)plVar2 + 0x1c) ^
           (cVar5 << 3 ^ *(byte *)((longlong)plVar2 + 0x1c)) & 8;
      return CONCAT71((int7)(in_RAX >> 8),cVar5);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== nvrPerformSgpioUpdate @ 000230c8 =====

ulonglong nvrPerformSgpioUpdate(longlong param_1,uint param_2,longlong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uStackX_c;
  
  uVar2 = 0;
  if ((param_1 != 0) && ((*(uint *)(param_1 + 4) & 0x400) != 0)) {
    return 0;
  }
  if (param_2 < 0xb) {
    if (8 < param_2) goto LAB_000231d3;
    if (param_2 == 0) {
      return 0;
    }
    if (param_2 < 3) {
      if (param_1 == 0) {
        return 0;
      }
      if (*(longlong *)(param_1 + 0x58) != 0) {
        uVar2 = nvrSgpioUpdateArrayEvents
                          (param_1,(ulonglong)CONCAT14(~*(byte *)(param_1 + 4),param_2) &
                                   0x1ffffffff | 0x200000000);
        uVar2 = uVar2 & 0xffffffff;
      }
      if (param_3 == 0) {
        return uVar2;
      }
      if (*(longlong *)(param_3 + 0x58) != 0) {
        return uVar2;
      }
      if (param_2 != 1) {
        return uVar2;
      }
      if (*(longlong *)(param_3 + 0x10) == 0) {
        return uVar2;
      }
      uVar3 = nvrSgpioSendIoctl(*(longlong *)(param_3 + 0x10),0x400000001);
      uVar1 = (uint)uVar3;
      goto LAB_000231f3;
    }
    if (param_2 < 5) {
      if (param_3 == 0) {
        return 0;
      }
      if (*(longlong *)(param_3 + 0x58) == 0) {
        return 0;
      }
      uStackX_c = (byte)~*(byte *)(param_3 + 4) & 1 | 2;
    }
    else {
      if (param_2 != 5) {
        return 0;
      }
      uStackX_c = 1;
    }
  }
  else {
    if ((param_2 - 0xf & 0xfffffffa) != 0) {
      return 0;
    }
LAB_000231d3:
    if (param_2 == 9) {
      uStackX_c = 6;
    }
    param_3 = param_1;
  }
  uVar3 = nvrSgpioUpdateArrayEvents(param_3,CONCAT44(uStackX_c,param_2));
  uVar1 = (uint)uVar3;
LAB_000231f3:
  return (ulonglong)uVar1;
}



===== NvRaidOsSendSrbControl @ 00023208 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 NvRaidOsSendSrbControl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined1 auStack_d8 [32];
  undefined8 local_b8;
  undefined1 local_a8 [32];
  undefined4 local_88;
  undefined1 local_84;
  undefined4 local_7c;
  int local_78;
  undefined4 local_74;
  longlong local_70;
  longlong local_58;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_d8;
  lVar4 = IoAllocateIrp(*(undefined1 *)(param_1 + 0x4c));
  if (lVar4 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    memset(&local_88,0,0x58);
    local_74 = *(undefined4 *)(param_2 + 0xc);
    local_78 = *(int *)(param_2 + 0x18) + 0x1c;
    local_88 = 0x20058;
    local_84 = 0;
    local_7c = 0x80000;
    local_70 = param_2;
    local_58 = lVar4;
    KeInitializeEvent(local_a8,1,0);
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(code **)(lVar1 + -0x10) = IoctlScsiPassThroughCompletion;
    *(undefined1 *)(lVar1 + -0x45) = 0xe0;
    *(undefined1 **)(lVar1 + -8) = local_a8;
    lVar1 = *(longlong *)(lVar4 + 0xb8);
    *(undefined4 **)(lVar1 + -0x40) = &local_88;
    *(undefined1 *)(lVar1 + -0x48) = 0xf;
    iVar2 = IofCallDriver(param_1,lVar4);
    if (iVar2 == 0x103) {
      local_b8 = 0;
      KeWaitForSingleObject(local_a8,0,0,0);
    }
    uVar3 = *(undefined4 *)(lVar4 + 0x30);
    IoFreeIrp(lVar4);
  }
  return uVar3;
}



===== nvrSgpioUpdateArrayEvents @ 00023330 =====

undefined8 nvrSgpioUpdateArrayEvents(longlong param_1,longlong param_2)

{
  uint uVar1;
  undefined8 uVar2;
  byte bVar3;
  longlong lVar4;
  int iStackX_14;
  
  if ((param_1 == 0) || ((*(uint *)(param_1 + 4) & 0x400) != 0)) {
    uVar2 = 0;
  }
  else {
    if ((*(longlong *)(param_1 + 0x58) != 0) && (bVar3 = 0, *(int *)(param_1 + 0x7c) != 0)) {
      uVar1 = 0;
      do {
        if ((param_1 == -0x78) || (*(uint *)(param_1 + 0x7c) <= uVar1)) {
          lVar4 = 0;
        }
        else {
          lVar4 = *(longlong *)(*(longlong *)(param_1 + 0x80) + (ulonglong)uVar1 * 8);
        }
        if (((lVar4 != 0) && (*(longlong *)(lVar4 + 0x10) != 0)) &&
           ((iStackX_14 = (int)((ulonglong)param_2 >> 0x20), iStackX_14 != 6 ||
            (((*(longlong *)(param_1 + 0x18) == 0 ||
              ((*(uint *)(*(longlong *)(param_1 + 0x18) + 0xe8) & 2) == 0)) ||
             ((*(uint *)(lVar4 + 4) & 0x100) != 0)))))) {
          nvrSgpioSendIoctl(*(longlong *)(lVar4 + 0x10),param_2);
        }
        bVar3 = bVar3 + 1;
        uVar1 = (uint)bVar3;
      } while (uVar1 < *(uint *)(param_1 + 0x7c));
    }
    uVar2 = 0xc0000001;
  }
  return uVar2;
}



===== nvrSgpioSendIoctl @ 000233ec =====

undefined8 nvrSgpioSendIoctl(undefined8 param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  longlong *plVar3;
  
  lVar2 = IoAllocateWorkItem();
  if (lVar2 != 0) {
    plVar3 = (longlong *)ExAllocatePoolWithTag(0,0x10,0x204e7652);
    if (plVar3 != (longlong *)0x0) {
      iVar1 = ClassAcquireRemoveLockEx
                        (param_1,plVar3,"drivers\\oem\\src\\storage\\nvraid\\nvraid\\nvraidos.c",
                         0x1561);
      if (iVar1 == 0) {
        *plVar3 = lVar2;
        plVar3[1] = param_2;
        IoQueueWorkItem(lVar2,nvrSgpioSendIoctl_Worker,1,plVar3);
        return 0x103;
      }
      ClassReleaseRemoveLock(param_1,plVar3);
      IoFreeWorkItem(lVar2);
      ExFreePoolWithTag(plVar3,0);
      return 0xc00000c0;
    }
    IoFreeWorkItem(lVar2);
  }
  return 0xc000009a;
}



===== nvrSgpioSendIoctl_Worker @ 000234c0 =====

void nvrSgpioSendIoctl_Worker(longlong param_1,undefined8 *param_2)

{
  int *_Dst;
  
  if (param_2 != (undefined8 *)0x0) {
    _Dst = (int *)ExAllocatePoolWithTag(0,0x24,0x204e7652);
    if (_Dst == (int *)0x0) {
      ClassReleaseRemoveLock(param_1,param_2);
    }
    else {
      memset(_Dst,0,0x24);
      *_Dst = 0x1c;
      _Dst[3] = 2;
      _Dst[4] = 0x1b0ff2;
      _Dst[6] = 8;
      _Dst[7] = *(int *)(param_2 + 1);
      _Dst[8] = *(int *)((longlong)param_2 + 0xc);
      FUN_00023980(param_1,_Dst);
      ClassReleaseRemoveLock(param_1,param_2);
      ExFreePoolWithTag(_Dst,0);
      IoFreeWorkItem(*param_2);
      ExFreePoolWithTag(param_2,0);
    }
  }
  return;
}



===== nvrGetIdentifyData @ 00023584 =====

void nvrGetIdentifyData(longlong param_1,int *param_2)

{
  int iVar1;
  longlong lVar2;
  int *_Dst;
  ulonglong uVar3;
  ushort *puVar4;
  byte *pbVar5;
  longlong lVar6;
  
  lVar6 = *(longlong *)(param_1 + 0x40);
  *param_2 = 0;
  lVar2 = *(longlong *)(lVar6 + 0x60);
  _Dst = (int *)ExAllocatePoolWithTag(4,0x240,0x634e7652);
  if (_Dst == (int *)0x0) {
    *param_2 = -0x3fffff66;
  }
  else {
    memset(_Dst,0,0x240);
    *_Dst = 0x1c;
    _Dst[6] = 0x211;
    iVar1 = *(int *)(lVar6 + 0x248);
    _Dst[4] = 0x1b0501;
    _Dst[7] = 0x200;
    *(undefined1 *)((longlong)_Dst + 0x26) = 0xec;
    _Dst[3] = iVar1;
    *(undefined1 *)(_Dst + 10) = *(undefined1 *)(lVar2 + 0xba);
    uVar3 = FUN_00023980(param_1,_Dst);
    *param_2 = (int)uVar3;
    if ((-1 < (int)uVar3) && ((char)_Dst[8] == '\0')) {
      puVar4 = (ushort *)((longlong)_Dst + 0x62);
      lVar6 = 0x14;
      do {
        *puVar4 = *puVar4 << 8 | *puVar4 >> 8;
        puVar4 = puVar4 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      puVar4 = (ushort *)(_Dst + 0x10);
      lVar6 = 10;
      do {
        *puVar4 = *puVar4 << 8 | *puVar4 >> 8;
        puVar4 = puVar4 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      *(undefined8 *)(lVar2 + 0xe8) = *(undefined8 *)((longlong)_Dst + 0x62);
      pbVar5 = (byte *)(lVar2 + 0x10f);
      *(undefined8 *)(lVar2 + 0xf0) = *(undefined8 *)((longlong)_Dst + 0x6a);
      *(undefined8 *)(lVar2 + 0xf8) = *(undefined8 *)((longlong)_Dst + 0x72);
      *(undefined8 *)(lVar2 + 0x100) = *(undefined8 *)((longlong)_Dst + 0x7a);
      *(undefined8 *)(lVar2 + 0x108) = *(undefined8 *)((longlong)_Dst + 0x82);
      do {
        if ((*pbVar5 & 0xdf) != 0) break;
        *pbVar5 = 0;
        pbVar5 = pbVar5 + -1;
      } while (-1 < (longlong)pbVar5 - (lVar2 + 0xe8));
      *(undefined8 *)(lVar2 + 0x110) = *(undefined8 *)(_Dst + 0x10);
      pbVar5 = (byte *)(lVar2 + 0x123);
      *(undefined8 *)(lVar2 + 0x118) = *(undefined8 *)(_Dst + 0x12);
      *(int *)(lVar2 + 0x120) = _Dst[0x14];
      do {
        if ((*pbVar5 & 0xdf) != 0) break;
        *pbVar5 = 0;
        pbVar5 = pbVar5 + -1;
      } while (-1 < (longlong)pbVar5 - (lVar2 + 0x110));
      if ((*(byte *)(_Dst + 0x72) & 8) == 0) {
        *(byte *)(lVar2 + 0xe0) = *(byte *)(lVar2 + 0xe0) & 0xfd;
      }
      else {
        *(byte *)(lVar2 + 0xe0) = *(byte *)(lVar2 + 0xe0) | 2;
      }
    }
    ExFreePoolWithTag(_Dst,0);
  }
  return;
}



===== nvrGetPCIData @ 00023734 =====

void nvrGetPCIData(longlong param_1,int *param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  undefined4 *_Dst;
  
  if (((param_1 == 0) || (lVar1 = *(longlong *)(param_1 + 0x40), lVar1 == 0)) ||
     (lVar2 = *(longlong *)(lVar1 + 0x60), lVar2 == 0)) {
    *param_2 = -0x3ffffff3;
  }
  else {
    _Dst = (undefined4 *)ExAllocatePoolWithTag(0,0x2c,0x204e7652);
    if (_Dst == (undefined4 *)0x0) {
      *param_2 = -0x3fffff66;
    }
    else {
      memset(_Dst,0,0x2c);
      *_Dst = 0x1c;
      _Dst[3] = *(undefined4 *)(lVar1 + 0x248);
      _Dst[4] = 0x1b0802;
      _Dst[6] = 0xe;
      iVar3 = NvRaidOsSendSrbControl(param_1,(longlong)_Dst);
      *param_2 = iVar3;
      if (-1 < iVar3) {
        *(undefined1 *)(lVar2 + 0x124) = *(undefined1 *)(_Dst + 7);
        *(undefined1 *)(lVar2 + 0x125) = *(undefined1 *)((longlong)_Dst + 0x1d);
        *(undefined1 *)(lVar2 + 0x126) = *(undefined1 *)((longlong)_Dst + 0x1e);
        *(undefined1 *)(lVar2 + 0x127) = *(undefined1 *)(_Dst + 8);
        *(undefined2 *)(lVar2 + 0x128) = *(undefined2 *)((longlong)_Dst + 0x22);
        *(undefined2 *)(lVar2 + 0x12a) = *(undefined2 *)(_Dst + 9);
        *(undefined2 *)(lVar2 + 300) = *(undefined2 *)((longlong)_Dst + 0x26);
      }
      ExFreePoolWithTag(_Dst,0);
    }
  }
  return;
}



===== nvrClearArrayMemberMBR_InitializeSubRequest @ 00023844 =====

undefined8 nvrClearArrayMemberMBR_InitializeSubRequest(longlong param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  lVar1 = **(longlong **)(*(longlong *)(param_1 + 0x40) + 0x60);
  puVar2 = NvRaidResNrpAllocate(0x298e0);
  if (puVar2 == (undefined8 *)0x0) {
    uVar3 = 0xc000009a;
  }
  else {
    uVar3 = NvRaidResBufferAllocateForNrp(0x298e0,*(uint *)(lVar1 + 0x28),(longlong)puVar2);
    if ((int)uVar3 == 0) {
      memset(*(void **)(puVar2[0x15] + 0x18),0,(ulonglong)*(uint *)(lVar1 + 0x28));
      puVar2[0xe] = lVar1;
      NvRaidScsiSetupReadWrite
                ((longlong)puVar2,*(undefined1 *)(lVar1 + 8),lVar1,FUN_00023050,0x2a,0,1);
      *puVar2 = 0;
      puVar2[1] = *(undefined8 *)(param_2 + 0x28);
      **(undefined8 **)(param_2 + 0x28) = puVar2;
      *(char *)(param_2 + 0x55) = *(char *)(param_2 + 0x55) + '\x01';
      *(undefined8 **)(param_2 + 0x28) = puVar2;
      puVar2[0xd] = param_2;
      puVar2[0xe] = *(undefined8 *)(param_2 + 0x40);
      uVar3 = 0;
    }
    else {
      NvRaidResNrpFree(0x298e0,(undefined4 *)puVar2);
      uVar3 = 0xc0000017;
    }
  }
  return uVar3;
}



===== nvrClearArrayMemberMBR_Callback @ 00023928 =====

undefined8 nvrClearArrayMemberMBR_Callback(longlong param_1,longlong param_2)

{
  if (*(longlong *)(param_1 + 0x58) == 0) {
    nvrClearArrayMemberMBR_InitializeSubRequest(*(longlong *)(param_1 + 0x10),param_2);
  }
  return 0;
}



===== FUN_00023944 @ 00023944 =====

undefined8 FUN_00023944(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  NvRaidVolumeSendCommandToVolumes(param_1,nvrClearArrayMemberMBR_Callback,param_2);
  uVar1 = NvRaidPacketSubmitSubRequests((longlong *)(param_2 + 0x20));
  if ((int)uVar1 == 0x103) {
    uVar1 = 0x103;
  }
  else {
    *(char *)(param_2 + 0x56) = *(char *)(param_2 + 0x56) + '\x01';
    uVar1 = 0;
  }
  return uVar1;
}



===== FUN_00023980 @ 00023980 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_00023980(longlong param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined1 auStack_108 [32];
  undefined8 *local_e8;
  undefined1 *local_e0;
  uint *local_d8;
  uint local_c8 [4];
  undefined8 local_b8;
  undefined1 local_b0 [24];
  undefined2 local_98;
  undefined1 local_96;
  undefined1 local_93;
  undefined1 local_92;
  undefined1 local_91;
  undefined2 local_90;
  undefined1 local_8d;
  uint local_8c;
  int local_88;
  int local_84;
  int *local_80;
  undefined8 local_78;
  longlong local_68;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_108;
  lVar3 = *(longlong *)(param_1 + 0x40);
  local_c8[0] = 0;
  local_c8[1] = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  lVar4 = *(longlong *)(lVar3 + 0x60);
  KeInitializeEvent(local_b0,1,0);
  iVar1 = param_2[6];
  local_d8 = local_c8;
  iVar2 = *param_2;
  local_e0 = local_b0;
  local_b8 = 1;
  local_e8 = &local_b8;
  local_68 = IoBuildSynchronousFsdRequest(0xf,*(undefined8 *)(lVar3 + 0x10),param_2,iVar1 + iVar2);
  if (local_68 == 0) {
    uVar6 = 0xc000009a;
  }
  else {
    lVar5 = *(longlong *)(local_68 + 0xb8);
    *(undefined2 **)(lVar5 + -0x40) = &local_98;
    *(undefined2 *)(lVar5 + -0x48) = 0x10f;
    memset(&local_98,0,0x58);
    local_93 = *(undefined1 *)(lVar4 + 0xb9);
    local_92 = *(undefined1 *)(lVar4 + 0xba);
    local_91 = *(undefined1 *)(lVar4 + 0xbb);
    local_96 = 2;
    local_98 = 0x58;
    local_8c = *(uint *)(lVar3 + 0x250) | 0x100140;
    local_90 = 0x20ff;
    local_84 = param_2[3];
    local_78 = *(undefined8 *)(lVar3 + 0x240);
    local_8d = 0x12;
    local_88 = iVar1 + iVar2;
    local_80 = param_2;
    uVar6 = IofCallDriver(*(undefined8 *)(lVar3 + 0x10),local_68);
    if ((int)uVar6 == 0x103) {
      local_e8 = (undefined8 *)0x0;
      KeWaitForSingleObject(local_b0,0,0,0);
      uVar6 = (ulonglong)local_c8[0];
    }
  }
  return uVar6;
}



===== nvrPowerExecuteWorkerThread @ 00023b04 =====

longlong nvrPowerExecuteWorkerThread
                   (undefined8 param_1,undefined8 param_2,undefined4 param_3,longlong param_4,
                   longlong *param_5)

{
  longlong lVar1;
  code *pcVar2;
  longlong lVar3;
  code *pcVar4;
  
  pcVar2 = IoQueueWorkItem_exref;
  pcVar4 = IoAllocateWorkItem_exref;
  if (gUseNvrWorkItem != '\0') {
    pcVar4 = nvrAllocateWorkItem;
    pcVar2 = nvrQueueWorkItem;
  }
  lVar1 = (*pcVar4)();
  if (param_5 != (longlong *)0x0) {
    *param_5 = lVar1;
  }
  lVar3 = lVar1;
  if (param_4 != 0) {
    lVar3 = param_4;
  }
  (*pcVar2)(lVar1,param_2,param_3,lVar3);
  return lVar1;
}



===== FUN_00023b98 @ 00023b98 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_00023b98(byte *param_1)

{
  ushort uVar1;
  code *pcVar2;
  bool bVar3;
  longlong lVar4;
  short *psVar5;
  short *psVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  char cVar10;
  int iVar11;
  ushort *puVar12;
  ulonglong uVar13;
  uint uVar14;
  uint uVar15;
  undefined **ppuVar16;
  short *psVar17;
  uint uVar18;
  uint uVar19;
  ulonglong uVar20;
  byte *pbVar21;
  undefined1 auStack_98 [32];
  int local_78;
  uint local_74;
  uint local_70;
  short *local_68;
  uint local_60;
  longlong local_58;
  ulonglong local_50;
  char *local_48;
  char local_40 [8];
  short local_38 [4];
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_98;
  pbVar21 = param_1 + 1;
  builtin_strncpy(local_40,"JBOD",4);
  uVar15 = 0;
  *param_1 = 0;
  local_40[4] = 0;
  pbVar21[0] = 0;
  pbVar21[1] = 0;
  pbVar21[2] = 0;
  pbVar21[3] = 0;
  pbVar21[4] = 0;
  pbVar21[5] = 0;
  pbVar21[6] = 0;
  pbVar21[7] = 0;
  local_70 = 0xc0000225;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  psVar5 = (short *)MmMapIoSpace(0xc0000,0x30000,0);
  if (psVar5 == (short *)0x0) {
    return 0xc000000d;
  }
  uVar18 = 0;
  psVar17 = psVar5;
  local_68 = psVar5;
  do {
    if (*psVar5 == -0x55ab) {
      uVar20 = (ulonglong)*(byte *)(psVar5 + 1) * 0x200;
      local_74 = (uint)uVar20;
      local_50 = uVar20;
      if (psVar17 + 0x18000 < psVar5 + (ulonglong)*(byte *)(psVar5 + 1) * 0x100) break;
      cVar10 = '\0';
      if (local_74 != 0) {
        psVar6 = psVar5;
        uVar13 = uVar20;
        do {
          cVar10 = cVar10 + (char)*psVar6;
          psVar6 = (short *)((longlong)psVar6 + 1);
          uVar13 = uVar13 - 1;
        } while (uVar13 != 0);
        if (cVar10 != '\0') goto LAB_00023e53;
      }
      uVar19 = local_74 - 0xc;
      uVar14 = 0;
      uVar18 = (uVar18 - 0x200) + local_74;
      if (local_74 != 0xc) {
        do {
          lVar7 = RtlCompareMemory((char *)((ulonglong)uVar14 + (longlong)psVar5),&s_NVFT,4);
          if ((lVar7 == 4) &&
             (lVar7 = RtlCompareMemory((char *)((ulonglong)(uVar14 + 4) + 4 + (longlong)psVar5),
                                       &s_TFVN,4), lVar7 == 4)) {
            uVar20 = (ulonglong)uVar14;
            if ((*(uint *)(uVar20 + 4 + (longlong)psVar5) & 0x10000) != 0) {
              *param_1 = *param_1 | 0x40;
            }
            if ((*(uint *)(uVar20 + 4 + (longlong)psVar5) & 0x40000) != 0) {
              *param_1 = *param_1 | 0x80;
            }
            if ((*(uint *)(uVar20 + 4 + (longlong)psVar5) & 8) != 0) {
              *param_1 = *param_1 | 1;
            }
            if ((*(uint *)(uVar20 + 4 + (longlong)psVar5) & 0x20) != 0) {
              *param_1 = *param_1 | 2;
            }
            if ((*(uint *)(uVar20 + 4 + (longlong)psVar5) & 1) != 0) {
              *param_1 = *param_1 | 4;
            }
            if ((*(uint *)(uVar20 + 4 + (longlong)psVar5) & 2) != 0) {
              *param_1 = *param_1 | 8;
            }
            if ((*(uint *)(uVar20 + 4 + (longlong)psVar5) & 4) != 0) {
              *param_1 = *param_1 | 0x20;
            }
            if ((*(uint *)(uVar20 + 4 + (longlong)psVar5) & 0x10) != 0) {
              *param_1 = *param_1 | 0x10;
            }
            if ((*(uint *)(uVar20 + 4 + (longlong)psVar5) & 0x20000) == 0) goto LAB_00023f6f;
            puVar12 = (ushort *)(uVar20 + 0xc + (longlong)psVar5);
            uVar1 = *puVar12;
            *(undefined8 *)pbVar21 = *(undefined8 *)((longlong)puVar12 + (0x17 - (ulonglong)uVar1));
            *(undefined4 *)(param_1 + 9) =
                 *(undefined4 *)((longlong)puVar12 + (0x1f - (ulonglong)uVar1));
            goto LAB_00023f33;
          }
          uVar14 = uVar14 + 1;
        } while (uVar14 < uVar19);
        uVar20 = (ulonglong)local_74;
      }
      uVar14 = 0;
      uVar13 = 0;
      do {
        if (7 < uVar13) {
          pcVar2 = (code *)swi(0x29);
          (*pcVar2)(8);
          pcVar2 = (code *)swi(3);
          uVar20 = (*pcVar2)();
          return uVar20;
        }
        uVar14 = uVar14 + 1;
        *(undefined2 *)((longlong)local_38 + uVar13) = 0;
        uVar13 = uVar13 + 2;
      } while (uVar14 < 4);
      local_60 = (int)uVar20 - 0x14;
      uVar14 = 0;
      if (local_60 == 0) {
        iVar11 = local_78;
      }
      else {
        do {
          iVar11 = 0;
          psVar17 = local_38;
          local_78 = 0;
          local_58 = 4;
          ppuVar16 = &gNvRaidRaidLevelMethods;
          do {
            if (*psVar17 == 0) {
              lVar7 = RtlCompareMemory((char *)((ulonglong)uVar14 + (longlong)psVar5),*ppuVar16,4);
              if (lVar7 == 4) {
                local_48 = (char *)((ulonglong)(uVar14 + 4) + (longlong)psVar5);
                lVar7 = RtlCompareMemory(local_48,*ppuVar16 + 4);
                if (lVar7 != 0x10) {
                  lVar7 = -1;
                  do {
                    lVar8 = lVar7 + 1;
                    lVar7 = lVar7 + 1;
                  } while (local_40[lVar8] != '\0');
                  lVar8 = RtlCompareMemory(local_48,local_40);
                  lVar7 = -1;
                  do {
                    lVar9 = lVar7 + 1;
                    lVar4 = lVar7 + 1;
                    lVar7 = lVar9;
                  } while (local_40[lVar4] != '\0');
                  if (lVar8 != lVar9) goto LAB_00023dc8;
                }
                *psVar17 = (short)uVar14;
              }
              else {
LAB_00023dc8:
                local_78 = local_78 + 1;
              }
              iVar11 = local_78;
            }
            ppuVar16 = ppuVar16 + 1;
            psVar17 = psVar17 + 1;
            local_58 = local_58 + -1;
          } while (local_58 != 0);
          local_58 = 0;
          if (iVar11 == 0) goto LAB_00023e06;
          uVar14 = uVar14 + 1;
        } while (uVar14 < local_60);
        psVar17 = local_68;
      }
      if (iVar11 == 0) {
LAB_00023e06:
        uVar14 = 0;
        uVar20 = local_50 - 8;
        if (local_50 != 8) {
          uVar13 = 0;
          do {
            lVar7 = RtlCompareMemory((char *)(uVar13 + (longlong)psVar5),local_38,8);
            if (lVar7 == 8) {
              if ((char *)((ulonglong)uVar14 + (longlong)psVar5) != (char *)0x0) {
                uVar20 = 0;
                bVar3 = false;
                goto LAB_00023f8f;
              }
              break;
            }
            uVar14 = uVar14 + 1;
            uVar13 = (ulonglong)uVar14;
          } while (uVar13 < uVar20);
        }
        psVar17 = local_68;
      }
    }
LAB_00023e53:
    uVar18 = uVar18 + 0x200;
    psVar5 = (short *)((ulonglong)uVar18 + (longlong)psVar17);
  } while (uVar18 < 0x30000);
  goto LAB_00023e6d;
  while( true ) {
    uVar15 = uVar15 + 1;
    pbVar21 = pbVar21 + 1;
    if (0xb < uVar15) break;
LAB_00023f33:
    if ((*pbVar21 < 0x21) && ((0x100002401U >> ((ulonglong)*pbVar21 & 0x3f) & 1) != 0)) break;
  }
  if (uVar15 < 0xc) {
    memset(param_1 + (ulonglong)uVar15 + 1,0,(ulonglong)(0xc - uVar15));
  }
LAB_00023f6f:
  MmUnmapIoSpace(psVar17,0x30000);
  return 0;
LAB_00023f8f:
  do {
    uVar1 = *(ushort *)((char *)((ulonglong)uVar14 + (longlong)psVar5) + uVar20 * 2);
    if (local_74 <= uVar1) break;
    iVar11 = *(int *)((ulonglong)uVar1 + (longlong)psVar5);
    if (iVar11 == 0x80) {
      *param_1 = *param_1 | 4;
    }
    else if (iVar11 == 0x81) {
      *param_1 = *param_1 | 8;
    }
    else if (iVar11 == 0x83) {
      *param_1 = *param_1 | 1;
    }
    else if (iVar11 == 0x85) {
LAB_00023fe3:
      *param_1 = *param_1 | 2;
    }
    else if (iVar11 == 0x8a) {
LAB_00023fde:
      *param_1 = *param_1 | 0x10;
    }
    else {
      if (iVar11 == 0x95) goto LAB_00023fe3;
      if (iVar11 == 0xff) {
        *param_1 = *param_1 | 0x20;
      }
      else {
        if ((iVar11 == 0x8081) || (iVar11 == 0x8180)) goto LAB_00023fde;
        bVar3 = true;
      }
    }
    uVar20 = (ulonglong)((int)uVar20 + 1);
  } while (!bVar3);
  local_70 = 0;
  psVar17 = local_68;
LAB_00023e6d:
  MmUnmapIoSpace(psVar17,0x30000);
  return (ulonglong)local_70;
}



===== nvrScsiPortDispatch @ 00024014 =====

void nvrScsiPortDispatch(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  undefined4 *puVar2;
  longlong lVar3;
  
  pbVar1 = *(byte **)(param_2 + 0xb8);
  lVar3 = IoGetDriverObjectExtension(*(undefined8 *)(param_1 + 8),0x4452564e);
  if (param_1 == scsiRaidController) {
    (**(code **)(*(longlong *)(param_1 + 0x40) + 0x200 + (ulonglong)*pbVar1 * 8))(param_1,param_2);
  }
  else {
    if (((*(byte *)(*(longlong *)(param_1 + 0x40) + 0x68) & 1) == 0) &&
       (puVar2 = *(undefined4 **)(*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60) + 0x10),
       puVar2 != (undefined4 *)0x0)) {
      *puVar2 = 0;
    }
    (**(code **)(lVar3 + (ulonglong)*pbVar1 * 8))(param_1,param_2);
  }
  return;
}



===== FUN_0002409c @ 0002409c =====

undefined8 FUN_0002409c(int *param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  uint uVar2;
  ulonglong _Size;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined8 local_14;
  
  if (*param_1 == 5) {
    local_28 = 0x18;
    _Size = 0x18;
    if (*(uint *)(param_3 + 8) < 0x18) {
      _Size = (ulonglong)*(uint *)(param_3 + 8);
    }
    local_24 = 0x18;
    cVar1 = IoIsWdmVersionAvailable(1,0x20);
    local_1c = CONCAT22(local_1c._2_2_,0x101);
    local_20 = 2 - (uint)(cVar1 != '\0');
    memcpy(*(void **)(param_2 + 0x18),&local_28,_Size);
  }
  else {
    if (*param_1 != 6) {
      return 0xc0000002;
    }
    local_20 = 0x20;
    local_28 = 0x1c;
    uVar2 = 0x1c;
    if (*(uint *)(param_3 + 8) < 0x1c) {
      uVar2 = *(uint *)(param_3 + 8);
    }
    local_24 = 0x1c;
    _Size = (ulonglong)uVar2;
    local_1c = 0x20;
    local_18 = 0x200;
    local_14 = 0x200;
    memcpy(*(void **)(param_2 + 0x18),&local_28,(ulonglong)uVar2);
  }
  *(ulonglong *)(param_2 + 0x38) = _Size;
  return 0;
}



===== FUN_00024174 @ 00024174 =====

ulonglong FUN_00024174(undefined8 param_1,undefined8 *param_2)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 local_58 [16];
  undefined1 local_48 [16];
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined1 *local_28;
  undefined4 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  RtlInitAnsiString(local_48,param_1);
  uVar2 = RtlAnsiStringToUnicodeString(local_58,local_48,1);
  if (-1 < (int)uVar2) {
    local_30 = *param_2;
    local_18 = 0;
    local_28 = local_58;
    local_10 = 0;
    local_38[0] = 0x30;
    local_20 = 0x40;
    uVar1 = ZwCreateKey(param_2,0x2001f,local_38,0,0,1,0);
    uVar2 = (ulonglong)uVar1;
    RtlFreeUnicodeString(local_58);
    ZwClose(local_30);
  }
  return uVar2;
}



===== FUN_00024224 @ 00024224 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_00024224(longlong param_1)

{
  ushort uVar1;
  short *psVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  short *_Src;
  undefined1 auStack_108 [32];
  undefined8 local_e8;
  uint local_e0;
  undefined8 local_d8;
  ushort local_d0 [4];
  undefined8 local_c8;
  undefined1 local_c0 [24];
  char local_a8 [128];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_108;
  local_d8 = 0;
  uVar4 = FUN_00024174("\\Registry\\Machine\\Hardware\\DeviceMap\\Scsi",&local_d8);
  uVar5 = uVar4 & 0xffffffff;
  if (-1 < (int)uVar4) {
    uVar3 = RtlStringCbPrintfA(local_a8,0x80,"Scsi Port %d",(ulonglong)_ScsiPortNumber);
    uVar5 = (ulonglong)uVar3;
    if (-1 < (int)uVar3) {
      uVar4 = FUN_00024174(local_a8,&local_d8);
      uVar5 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        RtlInitUnicodeString(local_c0);
        uVar1 = *(ushort *)(param_1 + 0x38);
        psVar2 = *(short **)(param_1 + 0x40) + (uVar1 >> 1);
        do {
          _Src = psVar2;
          if (_Src == *(short **)(param_1 + 0x40)) break;
          psVar2 = _Src + -1;
        } while (_Src[-1] != 0x5c);
        memset(local_a8,0,0x80);
        memcpy(local_a8,_Src,(ulonglong)(((uint)uVar1 - (int)_Src) + *(int *)(param_1 + 0x40)));
        RtlInitUnicodeString(local_d0,local_a8);
        local_e0 = (uint)local_d0[0];
        local_e8 = local_c8;
        ZwSetValueKey(local_d8,local_c0,0);
        uVar3 = RtlStringCbPrintfA(local_a8,0x80,"Scsi Bus %d",0);
        uVar5 = (ulonglong)uVar3;
        if (-1 < (int)uVar3) {
          uVar4 = FUN_00024174(local_a8,&local_d8);
          uVar5 = uVar4 & 0xffffffff;
          if (-1 < (int)uVar4) {
            uVar4 = FUN_00024174("Initiator Id 255",&local_d8);
            uVar5 = uVar4 & 0xffffffff;
            if (-1 < (int)uVar4) {
              ZwClose(local_d8);
            }
          }
        }
      }
    }
  }
  return uVar5;
}



===== nvrScsiPortInvalidateDeviceRelations @ 000243b8 =====

undefined8 nvrScsiPortInvalidateDeviceRelations(void)

{
  longlong lVar1;
  undefined8 uVar2;
  
  if (scsiRaidController == 0) {
    uVar2 = 0xc000000e;
  }
  else {
    lVar1 = *(longlong *)(scsiRaidController + 0x40);
    if ((*(longlong *)(lVar1 + 0x328) != 0) && (*(int *)(lVar1 + 0x344) == 0)) {
      if (*(longlong *)(lVar1 + 0x328) != 0) {
        IoInvalidateDeviceState();
      }
      IoInvalidateDeviceRelations(*(undefined8 *)(lVar1 + 0x328),0);
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== FUN_00024414 @ 00024414 =====

undefined4 FUN_00024414(void)

{
  longlong lVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (scsiRaidController == 0) {
    uVar2 = 0xc000000e;
  }
  else {
    lVar1 = *(longlong *)(scsiRaidController + 0x40);
    if ((*(byte *)(lVar1 + 0x340) & 2) != 0) {
      IoStopTimer();
    }
    if (*(longlong *)(lVar1 + 0x338) != 0) {
      uVar2 = IoSetDeviceInterfaceState(lVar1 + 0x330,0);
      RtlFreeUnicodeString(lVar1 + 0x330);
    }
    if (*(longlong *)(lVar1 + 0x308) != 0) {
      IoDeleteSymbolicLink(lVar1 + 0x300);
      RtlFreeUnicodeString(lVar1 + 0x300);
    }
    if (*(longlong *)(lVar1 + 0x318) != 0) {
      IoDeleteSymbolicLink(lVar1 + 0x310);
      RtlFreeUnicodeString(lVar1 + 0x310);
    }
    if (*(longlong *)(lVar1 + 800) != 0) {
      IoDetachDevice();
    }
    IoDeleteDevice(scsiRaidController);
    scsiRaidController = 0;
  }
  return uVar2;
}



===== nvrScsiPortAddDevice @ 000244f8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int nvrScsiPortAddDevice(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined8 *puVar6;
  ulonglong uVar7;
  undefined1 auStack_138 [32];
  undefined4 local_118;
  undefined1 local_110;
  undefined8 *local_108;
  undefined1 local_f8 [8];
  longlong local_f0;
  undefined1 local_e8 [16];
  undefined4 local_d8;
  undefined4 uStack_d4;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined4 local_c0 [2];
  undefined8 local_b8;
  undefined1 *local_b0;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  char local_88 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_138;
  if (scsiRaidController == 0) {
    local_f0 = 0;
    iVar2 = RtlStringCbPrintfA(local_88,0x40,"\\Device\\Scsi",param_4);
    if (-1 < iVar2) {
      RtlInitAnsiString(local_e8,local_88);
      iVar2 = RtlAnsiStringToUnicodeString(local_f8,local_e8,1);
      if (-1 < iVar2) {
        local_b0 = local_f8;
        local_c0[0] = 0x30;
        local_b8 = 0;
        local_a8 = 0x50;
        local_a0 = 0;
        local_98 = 0;
        iVar2 = ZwCreateDirectoryObject(&local_c8,0xf000f,local_c0);
        if (-1 < iVar2) {
          ZwClose(local_c8);
        }
        RtlFreeUnicodeString(local_f8);
        lVar3 = IoGetConfigurationInformation();
        _ScsiPortNumber = *(uint *)(lVar3 + 0x10);
        uVar7 = (ulonglong)_ScsiPortNumber;
        *(uint *)(lVar3 + 0x10) = _ScsiPortNumber + 1;
        iVar2 = RtlStringCbPrintfA(local_88,0x40,"\\Device\\Scsi\\nvraid%d",uVar7);
        if (-1 < iVar2) {
          RtlInitAnsiString(local_e8,local_88);
          iVar2 = RtlAnsiStringToUnicodeString(local_f8,local_e8,1);
          if (-1 < iVar2) {
            local_108 = &scsiRaidController;
            local_110 = 1;
            local_118 = 0x100;
            iVar2 = IoCreateDevice(param_1,0x380,local_f8,4);
            if (-1 < iVar2) {
              uVar7 = (ulonglong)_ScsiPortNumber;
              lVar3 = *(longlong *)(scsiRaidController + 0x40);
              puVar6 = (undefined8 *)(lVar3 + 0x200);
              for (lVar5 = 0x1c; lVar5 != 0; lVar5 = lVar5 + -1) {
                *puVar6 = nvrScsiPortInvalidRequest;
                puVar6 = puVar6 + 1;
              }
              iVar2 = RtlStringCbPrintfA(local_88,0x40,"\\Device\\ScsiPort%d",uVar7);
              if (-1 < iVar2) {
                RtlInitAnsiString(local_e8,local_88);
                lVar5 = lVar3 + 0x300;
                iVar2 = RtlAnsiStringToUnicodeString(lVar5,local_e8,1);
                if ((-1 < iVar2) && (iVar2 = IoCreateSymbolicLink(lVar5,local_f8), iVar2 < 0)) {
                  RtlFreeUnicodeString(lVar5);
                  *(undefined8 *)(lVar3 + 0x308) = 0;
                }
                iVar2 = RtlStringCbPrintfA(local_88,0x40,"\\DosDevices\\Scsi%d:",
                                           (ulonglong)_ScsiPortNumber);
                if (-1 < iVar2) {
                  RtlInitAnsiString(local_e8,local_88);
                  lVar5 = lVar3 + 0x310;
                  iVar2 = RtlAnsiStringToUnicodeString(lVar5,local_e8,1);
                  if ((-1 < iVar2) && (iVar2 = IoCreateSymbolicLink(lVar5,local_f8), iVar2 < 0)) {
                    RtlFreeUnicodeString(lVar5);
                    *(undefined8 *)(lVar3 + 0x318) = 0;
                  }
                  *(undefined8 *)(lVar3 + 0x200) = nvrScsiPortCreateClose;
                  *(code **)(lVar3 + 0x210) = nvrScsiPortCreateClose;
                  *(code **)(lVar3 + 0x270) = nvrScsiPortDeviceControl;
                  *(code **)(lVar3 + 0x278) = nvrScsiPortDispatchScsi;
                  *(code **)(lVar3 + 0x2b0) = nvrScsiPortDispatchPower;
                  *(code **)(lVar3 + 0x2d8) = nvrScsiPortDispatchPnp;
                  *(undefined1 **)(lVar3 + 0x2b8) = &nvrScsiPortDispatchSysControl;
                  FUN_00024224(param_1);
                  puVar1 = (undefined4 *)(lVar3 + 0x330);
                  *(undefined8 *)(lVar3 + 0x338) = 0;
                  *(undefined2 *)puVar1 = 0;
                  *(undefined2 *)(lVar3 + 0x332) = 0;
                  local_118 = 0x20;
                  IoInitializeRemoveLockEx(lVar3 + 0x2e0,0x674e7652,0,0);
                  uVar4 = IoGetAttachedDeviceReference(param_2);
                  lVar5 = IoAttachDeviceToDeviceStack(scsiRaidController,param_2);
                  *(longlong *)(lVar3 + 800) = lVar5;
                  if (lVar5 == 0) {
                    iVar2 = -0x3fffffff;
                  }
                  else {
                    *(undefined8 *)(lVar3 + 0x328) = param_2;
                    ObfDereferenceObject(uVar4);
                    RtlInitUnicodeString(&local_d8,0);
                    iVar2 = IoRegisterDeviceInterface
                                      (*(undefined8 *)(lVar3 + 0x328),&GUID_DEVINTERFACE_STORAGEPORT
                                       ,0,&local_d8);
                    if (iVar2 < 0) {
                      uStack_d0 = 0;
                    }
                    else {
                      iVar2 = IoSetDeviceInterfaceState(&local_d8,1);
                      if (iVar2 < 0) {
                        RtlFreeUnicodeString(&local_d8);
                      }
                      else {
                        if (*(longlong *)(lVar3 + 0x338) != 0) {
                          RtlFreeUnicodeString(puVar1);
                        }
                        *puVar1 = local_d8;
                        *(undefined4 *)(lVar3 + 0x334) = uStack_d4;
                        *(undefined4 *)(lVar3 + 0x338) = (undefined4)uStack_d0;
                        *(undefined4 *)(lVar3 + 0x33c) = uStack_d0._4_4_;
                      }
                    }
                    if (-1 < iVar2) {
                      local_118 = 0x20;
                      IoAcquireRemoveLockEx(lVar3 + 0x2e0,0,&s_,1);
                      iVar2 = IoInitializeTimer(scsiRaidController,nvrideRaidScsiTimer,0);
                      *(byte *)(lVar3 + 0x340) = *(byte *)(lVar3 + 0x340) | 2;
                      *(uint *)(scsiRaidController + 0x30) =
                           *(uint *)(scsiRaidController + 0x30) & 0xffffff7f;
                      FUN_00023b98((byte *)(lVar3 + 0x348));
                      *(byte *)(lVar3 + 0x340) = *(byte *)(lVar3 + 0x340) & 0xfe;
                      if ((char)*(byte *)(lVar3 + 0x348) < '\0') {
                        gRaidConfig = 1;
                        *(byte *)(lVar3 + 0x340) = *(byte *)(lVar3 + 0x340) | 1;
                      }
                      FUN_00024a78();
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if (local_f0 != 0) {
      RtlFreeUnicodeString(local_f8);
    }
    if (iVar2 < 0) {
      lVar3 = IoGetConfigurationInformation();
      *(int *)(lVar3 + 0x10) = *(int *)(lVar3 + 0x10) + -1;
      FUN_00024414();
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



===== nvrScsiPortDispatchPower @ 000249a8 =====

void nvrScsiPortDispatchPower(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  PoStartNextPowerIrp(param_2);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
                    /* WARNING: Could not recover jumptable at 0x000249e1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PoCallDriver(*(undefined8 *)(lVar1 + 800),param_2);
  return;
}



===== nvrScsiPortDispatchScsi @ 000249e8 =====

undefined4 nvrScsiPortDispatchScsi(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  longlong lVar3;
  undefined4 uVar4;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  cVar1 = *(char *)(lVar3 + 2);
  if (cVar1 == '\x01') {
    *(undefined8 *)(lVar3 + 0x18) = *(undefined8 *)(lVar2 + 0x328);
    ObfReferenceObject(*(undefined8 *)(lVar2 + 0x328));
  }
  else {
    if (cVar1 != '\x06') {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar4 = IofCallDriver(*(undefined8 *)(lVar2 + 800),param_2);
      return uVar4;
    }
    ObfDereferenceObject(*(undefined8 *)(lVar2 + 0x328));
  }
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== FUN_00024a78 @ 00024a78 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_00024a78(void)

{
  undefined8 uVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined1 auStack_a8 [32];
  int *local_88;
  undefined4 local_80;
  undefined1 local_78;
  undefined1 *local_70;
  uint *local_68;
  undefined4 local_58;
  undefined4 local_54;
  uint local_50 [4];
  undefined1 local_40 [24];
  int local_28 [2];
  int local_20;
  short local_1c;
  short local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_a8;
  local_54 = 0x44495653;
  local_58 = 0x42696541;
  uVar1 = *(undefined8 *)(*(longlong *)(scsiRaidController + 0x40) + 800);
  KeInitializeEvent(local_40,1);
  local_68 = local_50;
  local_70 = local_40;
  local_88 = local_28;
  local_78 = 0;
  local_80 = 0x14;
  lVar2 = IoBuildDeviceIoControlRequest(0x32c004,uVar1,&local_58,8);
  if (lVar2 == 0) {
    uVar3 = 0xc000009a;
  }
  else {
    uVar3 = IofCallDriver(uVar1,lVar2);
    if ((int)uVar3 == 0x103) {
      local_88 = (int *)0x0;
      KeWaitForSingleObject(local_40,0,0,0);
      uVar3 = (ulonglong)local_50[0];
    }
    if ((local_28[0] != 0x426f6541) || (local_20 == 0)) {
      uVar3 = 0xc014000f;
    }
    if (-1 < (int)uVar3) {
      if (local_1c == 2) {
        if (local_18 == 0x1028) {
          gRaidConfig = 1;
        }
      }
      else {
        uVar3 = 0xc0000010;
      }
    }
  }
  return uVar3;
}



===== nvrScsiPortPassThroughEnable_worker @ 00024b98 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void nvrScsiPortPassThroughEnable_worker(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  int iVar3;
  undefined1 auStack_108 [32];
  undefined4 local_e8;
  undefined1 local_e0;
  int *local_d8;
  undefined8 local_c8;
  undefined1 local_c0 [16];
  undefined8 local_b0;
  undefined1 local_a8 [16];
  int local_98 [4];
  undefined1 local_88 [16];
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_58;
  undefined2 local_54;
  wchar_t local_50 [20];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_108;
  builtin_wcsncpy(local_50,L"\\Device\\ScsiPort00",0x13);
  local_58 = 0x300030;
  local_54 = 0;
  local_60 = 0;
  local_78 = 0x1c;
  local_70 = 0x200000000;
  local_68 = 0x1b0803;
  lVar2 = IoGetConfigurationInformation();
  iVar3 = *(int *)(lVar2 + 0x10);
  RtlInitUnicodeString(local_88,L"\\Device\\ScsiPort");
  RtlInitUnicodeString(local_c0,local_50);
  RtlInitUnicodeString(local_a8,&local_58);
  do {
    if (iVar3 == 0) {
LAB_00024d15:
      if (param_2 != 0) {
        IoFreeWorkItem(param_2);
      }
      return;
    }
    RtlCopyUnicodeString(local_c0,local_88);
    RtlIntegerToUnicodeString(iVar3 + -1,0,local_a8);
    RtlAppendUnicodeStringToString(local_c0,local_a8);
    local_98[0] = IoGetDeviceObjectPointer(local_c0,0x20000,&local_b0,&local_c8);
    if (-1 < local_98[0]) {
      local_d8 = local_98;
      local_e0 = 0;
      local_e8 = 0x1c;
      ClassSendDeviceIoControlSynchronous(0x4d008,local_c8,&local_78,0x1c);
      if (-1 < local_98[0]) {
        pbVar1 = (byte *)(*(longlong *)(param_1 + 0x40) + 0x340);
        *pbVar1 = *pbVar1 & 0xfe;
        goto LAB_00024d15;
      }
      ObfDereferenceObject(local_b0);
    }
    iVar3 = iVar3 + -1;
  } while( true );
}



===== nvrDiskDumpQueryDumpPointers @ 00024d44 =====

undefined8 nvrDiskDumpQueryDumpPointers(longlong param_1,void *param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint local_res8 [2];
  
  lVar3 = *(longlong *)(param_1 + 0x40);
  plVar1 = *(longlong **)(lVar3 + 0x60);
  if (*plVar1 == 0) {
    uVar2 = 0xc00000c0;
  }
  else {
    memset(param_2,0,0x38);
    local_res8[0] = 0;
    NvRaidVolumeSendCommandToVolumes(*plVar1,nvrDiskDumpQueryDumpDataCallBack,local_res8);
    *(longlong *)((longlong)param_2 + 0x30) = param_1;
    *(longlong *)((longlong)param_2 + 0x10) = lVar3;
    if (*(uint *)(plVar1 + 0x17) < local_res8[0]) {
      if (plVar1[0x16] != 0) {
        ExFreePoolWithTag(plVar1[0x16],0);
      }
      plVar1[0x16] = 0;
      lVar3 = ExAllocatePoolWithTag(0,local_res8[0],0x674e7652);
      plVar1[0x16] = lVar3;
      if (lVar3 == 0) {
        return 0xc000009a;
      }
      *(uint *)(plVar1 + 0x17) = local_res8[0];
    }
    plVar1[0x18] = (longlong)&gNvRaidRaidLevelMethods;
    uVar2 = 0;
  }
  return uVar2;
}



===== nvrDiskDumpQueryDumpDataCallBack @ 00024e24 =====

undefined8 nvrDiskDumpQueryDumpDataCallBack(longlong param_1,int *param_2)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  int iVar6;
  uint *_Dst;
  undefined8 *puVar7;
  undefined1 local_18 [16];
  
  if (*(longlong *)(param_1 + 0x58) == 0) {
    lVar2 = *(longlong *)(param_1 + 0x10);
    lVar3 = *(longlong *)(lVar2 + 0x40);
    lVar4 = *(longlong *)(lVar3 + 0x60);
    ClassSendDeviceIoControlSynchronous(0x41020,lVar2,lVar4 + 0x28,0x38,0x38,0,local_18);
    *(undefined8 *)(lVar4 + 0x10) = *(undefined8 *)(lVar4 + 0x38);
    *(undefined8 *)(lVar4 + 0x20) = *(undefined8 *)(lVar4 + 0x58);
    *param_2 = *param_2 + 0x28;
    _Dst = (uint *)ExAllocatePoolWithTag(0,0x6c,0x644e7652);
    if (_Dst != (uint *)0x0) {
      memset(_Dst,0,0x6c);
      *_Dst = 0x1c;
      memcpy(_Dst + 1,"SCSIDISK",8);
      uVar1 = *(uint *)(lVar3 + 0x248);
      _Dst[5] = 0;
      _Dst[3] = uVar1;
      _Dst[6] = 0x50;
      _Dst[4] = 0x1b0801;
      cVar5 = IoIsWdmVersionAvailable(1,0x10);
      if (cVar5 != '\0') {
        cVar5 = IoIsWdmVersionAvailable(1,0x20);
        if (cVar5 == '\0') {
          _Dst[5] = 1;
        }
      }
      puVar7 = (undefined8 *)((ulonglong)*_Dst + (longlong)_Dst);
      iVar6 = NvRaidOsSendSrbControl
                        (*(longlong *)(*(longlong *)(lVar2 + 0x40) + 0x10),(longlong)_Dst);
      if (-1 < iVar6) {
        *(undefined8 *)(lVar4 + 0x60) = *puVar7;
        *(undefined8 *)(lVar4 + 0x68) = puVar7[1];
        *(undefined8 *)(lVar4 + 0x70) = puVar7[2];
        *(undefined8 *)(lVar4 + 0x78) = puVar7[3];
        *(undefined8 *)(lVar4 + 0x80) = puVar7[4];
        *(undefined8 *)(lVar4 + 0x88) = puVar7[5];
        *(undefined8 *)(lVar4 + 0x90) = puVar7[6];
        *(undefined8 *)(lVar4 + 0x98) = puVar7[7];
        *(undefined8 *)(lVar4 + 0xa0) = puVar7[8];
        *(undefined8 *)(lVar4 + 0xa8) = puVar7[9];
      }
      ExFreePoolWithTag(_Dst,0);
    }
  }
  else {
    *param_2 = *param_2 + *(int *)(param_1 + 0x7c) * 8;
  }
  return 0;
}



===== nvrInitWorkThread @ 00024fc8 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int nvrInitWorkThread(void)

{
  int iVar1;
  undefined8 local_res8 [4];
  undefined4 local_38 [2];
  undefined8 local_30;
  undefined8 local_28;
  undefined4 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_30 = 0;
  local_28 = 0;
  local_18 = 0;
  local_10 = 0;
  DAT_00029270 = 0;
  DAT_00029278 = 0;
  local_38[0] = 0x30;
  local_20 = 0x200;
  KeInitializeEvent(&DAT_00029250,0,0);
  KeInitializeSpinLock(&DAT_00029268);
  _DAT_00029288 = &DAT_00029280;
  _DAT_00029280 = &DAT_00029280;
  iVar1 = PsCreateSystemThread(local_res8,0,local_38,0,0,FUN_00025194,0);
  if (-1 < iVar1) {
    iVar1 = ObReferenceObjectByHandle(local_res8[0],0x1fffff,0,0,&DAT_00029278,0);
    ZwClose(local_res8[0]);
  }
  return iVar1;
}



===== nvrAllocateWorkItem @ 000250b0 =====

void nvrAllocateWorkItem(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = ExAllocatePoolWithTag(0,0x28,0x204e7652);
  if (lVar1 != 0) {
    *(undefined8 *)(lVar1 + 0x18) = param_1;
  }
  return;
}



===== nvrFreeWorkItem @ 000250dc =====

void nvrFreeWorkItem(undefined8 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x000250de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ExFreePoolWithTag(param_1,0);
  return;
}



===== nvrQueueWorkItem @ 000250e8 =====

void nvrQueueWorkItem(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  *(undefined8 *)(param_1 + 0x10) = param_2;
  *(undefined8 *)(param_1 + 0x20) = param_4;
  ExInterlockedInsertTailList(&DAT_00029280,param_1,&DAT_00029268);
                    /* WARNING: Could not recover jumptable at 0x0002511b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  KeSetEvent(&DAT_00029250,0,0);
  return;
}



===== nvrTerminateWorkThread @ 00025124 =====

void nvrTerminateWorkThread(void)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  
  if ((DAT_00029270 & 1) == 0) {
    uVar2 = DAT_00029270 | 1;
    while( true ) {
      uVar3 = uVar2;
      LOCK();
      UNLOCK();
      uVar2 = DAT_00029270 | 1;
      DAT_00029270 = uVar3;
      if (uVar2 == uVar3) break;
    }
  }
  KeSetEvent(&DAT_00029250,0,0);
  lVar1 = DAT_00029278;
  if (DAT_00029278 != 0) {
    KeWaitForSingleObject(DAT_00029278,6,0,0,0);
    ObfDereferenceObject(lVar1);
  }
  return;
}



===== FUN_00025194 @ 00025194 =====

void FUN_00025194(void)

{
  longlong lVar1;
  
  do {
    KeWaitForSingleObject(&DAT_00029250,0,0,0,0);
    KeClearEvent(&DAT_00029250);
    while( true ) {
      lVar1 = ExInterlockedRemoveHeadList(&DAT_00029280);
      if (lVar1 == 0) break;
      (**(code **)(lVar1 + 0x10))(*(undefined8 *)(lVar1 + 0x18),*(undefined8 *)(lVar1 + 0x20));
    }
  } while (((byte)DAT_00029270 & 1) == 0);
                    /* WARNING: Could not recover jumptable at 0x000251f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  PsTerminateSystemThread(0);
  return;
}



===== entry @ 000251fc =====

void entry(longlong param_1,ushort *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_check_cookie @ 00025230 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  if ((_StackCookie == __security_cookie) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== _vsnprintf @ 00025250 =====

int __cdecl _vsnprintf(char *_Dest,size_t _Count,char *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = _vsnprintf_l(_Dest,_Count,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}



===== _vsnprintf_l @ 00025268 =====

int __cdecl
_vsnprintf_l(char *_DstBuf,size_t _MaxCount,char *_Format,_locale_t _Locale,va_list _ArgList)

{
  int iVar1;
  FILE local_38;
  
  if ((_Format == (char *)0x0) || ((_MaxCount != 0 && (_DstBuf == (char *)0x0)))) {
    _guard_check_icall();
    iVar1 = -1;
  }
  else {
    local_38._flag = 0x42;
    local_38._cnt = (int)_MaxCount;
    if (0x7fffffff < _MaxCount) {
      local_38._cnt = 0x7fffffff;
    }
    local_38._ptr = _DstBuf;
    local_38._base = _DstBuf;
    iVar1 = _output_l(&local_38,_Format,_Locale,_ArgList);
    if (_DstBuf != (char *)0x0) {
      local_38._cnt = local_38._cnt + -1;
      if (local_38._cnt < 0) {
        _flsbuf(0,&local_38);
      }
      else {
        *local_38._ptr = '\0';
      }
    }
  }
  return iVar1;
}



===== _flsbuf @ 00025310 =====

int __cdecl _flsbuf(int _Ch,FILE *_File)

{
  _File->_flag = _File->_flag | 0x20;
  return -1;
}



===== _output_l @ 00025318 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int __cdecl _output_l(FILE *_File,char *_Format,_locale_t _Locale,va_list _ArgList)

{
  byte bVar1;
  ushort uVar2;
  wchar_t _WCh;
  ushort *puVar3;
  int *piVar4;
  FILE *pFVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  errno_t eVar9;
  wchar_t *pwVar10;
  char *pcVar11;
  wchar_t *pwVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  ulonglong uVar16;
  byte bVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  undefined1 auStack_2b8 [32];
  undefined8 local_298;
  uint local_288;
  int local_284;
  uint local_280;
  byte local_27c;
  char local_27b;
  uint local_278;
  uint local_274;
  int local_270;
  int local_26c;
  int local_268;
  undefined4 local_264;
  FILE *local_260;
  wchar_t *local_258;
  int local_250 [2];
  wchar_t local_248 [255];
  undefined2 uStack_49;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_2b8;
  uVar13 = 0;
  uVar19 = 0;
  local_274 = 0;
  local_264 = 0;
  uVar7 = 0;
  local_278 = 0;
  local_288 = 0;
  local_268 = 0;
  local_270 = 0;
  local_260 = _File;
  if ((_File == (FILE *)0x0) || (_Format == (char *)0x0)) {
    local_298 = 0;
    _guard_check_icall();
    iVar20 = -1;
  }
  else {
    bVar17 = *_Format;
    iVar20 = 0;
    local_284 = 0;
    local_280 = 0;
    local_26c = 0;
    if (bVar17 != 0) {
      pcVar11 = (char *)local_258;
      uVar18 = 0;
      do {
        pwVar12 = (wchar_t *)(_Format + 1);
        if (iVar20 < 0) break;
        uVar15 = 0;
        if ((byte)(bVar17 - 0x20) < 0x59) {
          uVar14 = (int)*(char *)((longlong)&IMAGE_DEBUG_DIRECTORY_0002739c.AddressOfRawData +
                                 (longlong)(char)bVar17) & 0xf;
        }
        else {
          uVar14 = uVar15;
        }
        local_26c = (int)(char)(&__lookuptable)[(longlong)local_26c + (longlong)(int)uVar14 * 8] >>
                    4;
        uVar14 = uVar13;
        local_258 = pwVar12;
        if (local_26c == 0) {
LAB_000259d3:
          local_270 = 0;
          write_char(bVar17,local_260,&local_284);
LAB_000259ea:
          local_258 = pwVar12;
          uVar13 = uVar14;
LAB_000259f2:
          pwVar12 = local_258;
          iVar20 = local_284;
          uVar18 = local_288;
LAB_000259f7:
          uVar7 = local_278;
          uVar15 = uVar18;
        }
        else if (local_26c == 1) {
          local_268 = 0;
          local_274 = 0;
          local_288 = 0;
          uVar7 = 0xffffffff;
          local_278 = 0xffffffff;
          local_270 = 0;
          uVar13 = uVar15;
          uVar19 = uVar15;
        }
        else if (local_26c == 2) {
          if (bVar17 == 0x20) {
            uVar13 = uVar13 | 2;
            uVar15 = uVar18;
          }
          else if (bVar17 == 0x23) {
            uVar13 = uVar13 | 0x80;
            uVar15 = uVar18;
          }
          else if (bVar17 == 0x2b) {
            uVar13 = uVar13 | 1;
            uVar15 = uVar18;
          }
          else if (bVar17 == 0x2d) {
            uVar13 = uVar13 | 4;
            uVar15 = uVar18;
          }
          else {
            uVar15 = uVar18;
            if (bVar17 == 0x30) {
              uVar13 = uVar13 | 8;
            }
          }
        }
        else if (local_26c == 3) {
          if (bVar17 == 0x2a) {
            local_274 = *(uint *)_ArgList;
            _ArgList = (va_list)((longlong)_ArgList + 8);
            uVar15 = uVar18;
            uVar19 = local_274;
            if (-1 < (int)local_274) goto LAB_00025a00;
            uVar13 = uVar13 | 4;
            local_274 = -local_274;
          }
          else {
            local_274 = (int)(char)bVar17 + (uVar19 * 5 + -0x18) * 2;
          }
          uVar15 = uVar18;
          uVar19 = local_274;
        }
        else if (local_26c == 4) {
          local_278 = 0;
          uVar7 = uVar15;
          uVar15 = uVar18;
        }
        else if (local_26c == 5) {
          if (bVar17 == 0x2a) {
            local_278 = *(uint *)_ArgList;
            _ArgList = (va_list)((longlong)_ArgList + 8);
            uVar7 = local_278;
            uVar15 = uVar18;
            if ((int)local_278 < 0) {
              local_278 = 0xffffffff;
              uVar7 = 0xffffffff;
            }
          }
          else {
            local_278 = (int)(char)bVar17 + (uVar7 * 5 + -0x18) * 2;
            uVar7 = local_278;
            uVar15 = uVar18;
          }
        }
        else if (local_26c == 6) {
          if (bVar17 == 0x49) {
            bVar1 = *(byte *)pwVar12;
            uVar14 = uVar13 | 0x8000;
            if ((bVar1 == 0x36) && (_Format[2] == 0x34)) {
              pwVar12 = (wchar_t *)(_Format + 3);
              uVar13 = uVar13 | 0x8000;
              uVar15 = uVar18;
            }
            else {
              if ((bVar1 != 0x33) || (_Format[2] != 0x32)) {
                if ((byte)(bVar1 + 0xa8) < 0x21) {
                  uVar13 = uVar14;
                  uVar15 = uVar18;
                  if ((0x120821001U >> ((ulonglong)(byte)(bVar1 + 0xa8) & 0x3f) & 1) != 0)
                  goto LAB_00025a00;
                }
                local_26c = 0;
                goto LAB_000259d3;
              }
              pwVar12 = (wchar_t *)(_Format + 3);
              uVar13 = uVar13 & 0xffff7fff;
              uVar15 = uVar18;
            }
          }
          else if (bVar17 == 0x68) {
            uVar13 = uVar13 | 0x20;
            uVar15 = uVar18;
          }
          else if (bVar17 == 0x6c) {
            if (*(byte *)pwVar12 == 0x6c) {
              pwVar12 = (wchar_t *)(_Format + 2);
              uVar13 = uVar13 | 0x1000;
              uVar15 = uVar18;
            }
            else {
              uVar13 = uVar13 | 0x10;
              uVar15 = uVar18;
            }
          }
          else {
            uVar15 = uVar18;
            if (bVar17 == 0x77) {
              uVar13 = uVar13 | 0x800;
            }
          }
        }
        else {
          uVar15 = uVar18;
          if (local_26c == 7) {
            if ((char)bVar17 < 'j') {
              if (bVar17 == 0x69) {
LAB_00025499:
                uVar13 = uVar13 | 0x40;
LAB_0002549c:
                iVar8 = 10;
                goto LAB_000254a7;
              }
              if (bVar17 == 0x43) {
                if ((uVar13 & 0x830) == 0) {
                  uVar13 = uVar13 | 0x800;
                }
LAB_00025597:
                if ((uVar13 & 0x810) == 0) {
                  local_248[0]._0_1_ = (char)*(wchar_t *)_ArgList;
                  local_280 = 1;
                }
                else {
                  eVar9 = wctomb_s((int *)&local_280,(char *)local_248,0x200,*(wchar_t *)_ArgList);
                  uVar18 = local_288;
                  if (eVar9 != 0) {
                    local_268 = 1;
                  }
                }
                pcVar11 = (char *)local_248;
                _ArgList = (va_list)((longlong)_ArgList + 8);
              }
              else if (bVar17 == 0x53) {
                if ((uVar13 & 0x830) == 0) {
                  uVar13 = uVar13 | 0x800;
                }
LAB_0002554b:
                if (uVar7 == 0xffffffff) {
                  uVar7 = 0x7fffffff;
                }
                pwVar10 = *(wchar_t **)_ArgList;
                if ((uVar13 & 0x810) == 0) {
                  pcVar11 = "(null)";
                  if (pwVar10 != (wchar_t *)0x0) {
                    pcVar11 = (char *)pwVar10;
                  }
                  for (pwVar10 = (wchar_t *)pcVar11;
                      (uVar7 != 0 && (uVar7 = uVar7 - 1, (char)*pwVar10 != '\0'));
                      pwVar10 = (wchar_t *)((longlong)pwVar10 + 1)) {
                  }
                  local_280 = (int)pwVar10 - (int)pcVar11;
                }
                else {
                  local_270 = 1;
                  pcVar11 = (char *)L"(null)";
                  if (pwVar10 != (wchar_t *)0x0) {
                    pcVar11 = (char *)pwVar10;
                  }
                  for (pwVar10 = (wchar_t *)pcVar11;
                      (uVar7 != 0 && (uVar7 = uVar7 - 1, *pwVar10 != L'\0')); pwVar10 = pwVar10 + 1)
                  {
                  }
                  local_280 = (uint)((longlong)pwVar10 - (longlong)pcVar11 >> 1);
                }
LAB_0002565e:
                _ArgList = (va_list)((longlong)_ArgList + 8);
              }
              else {
                if (bVar17 == 0x58) goto LAB_00025671;
                if (bVar17 == 0x5a) {
                  puVar3 = *(ushort **)_ArgList;
                  if ((puVar3 == (ushort *)0x0) ||
                     (pcVar11 = *(char **)(puVar3 + 4), (wchar_t *)pcVar11 == (wchar_t *)0x0)) {
                    pcVar11 = "(null)";
                    local_280 = 6;
                    _ArgList = (va_list)((longlong)_ArgList + 8);
                  }
                  else {
                    uVar2 = *puVar3;
                    if (puVar3[1] < uVar2) {
LAB_00025b3a:
                      local_298 = 0;
                      _guard_check_icall();
                      return -1;
                    }
                    if ((uVar13 >> 0xb & 1) == 0) {
                      local_270 = 0;
                      local_280 = (uint)uVar2;
                      goto LAB_0002565e;
                    }
                    if (((~uVar2 & 1) == 0) || ((~(uint)pcVar11 & 1) == 0)) goto LAB_00025b3a;
                    local_270 = 1;
                    local_280 = (uint)(uVar2 >> 1);
                    _ArgList = (va_list)((longlong)_ArgList + 8);
                  }
                }
                else {
                  if (bVar17 == 99) goto LAB_00025597;
                  if (bVar17 == 100) goto LAB_00025499;
                }
              }
            }
            else if (bVar17 == 0x6e) {
              piVar4 = *(int **)_ArgList;
              _ArgList = (va_list)((longlong)_ArgList + 8);
              iVar8 = _get_printf_count_output();
              if (iVar8 == 0) goto LAB_00025b3a;
              if ((uVar13 & 0x20) == 0) {
                *piVar4 = iVar20;
              }
              else {
                *(short *)piVar4 = (short)iVar20;
              }
              local_268 = 1;
              pwVar12 = local_258;
              uVar18 = local_288;
            }
            else {
              if (bVar17 == 0x6f) {
                iVar8 = 8;
                if ((char)uVar13 < '\0') {
                  uVar13 = uVar13 | 0x200;
                }
              }
              else {
                if (bVar17 == 0x70) {
                  uVar7 = 0x10;
                  uVar13 = uVar13 | 0x8000;
LAB_00025671:
                  local_264 = 7;
                }
                else {
                  if (bVar17 == 0x73) goto LAB_0002554b;
                  if (bVar17 == 0x75) goto LAB_0002549c;
                  if (bVar17 != 0x78) goto LAB_000257eb;
                  local_264 = 0x27;
                }
                iVar8 = 0x10;
                if ((char)uVar13 < '\0') {
                  local_27b = (char)local_264 + 'Q';
                  local_27c = 0x30;
                  uVar18 = 2;
                }
              }
LAB_000254a7:
              if (((uVar13 & 0x8000) == 0) && ((uVar13 >> 0xc & 1) == 0)) {
                if ((uVar13 & 0x20) == 0) {
                  if ((uVar13 & 0x40) == 0) {
                    uVar16 = (ulonglong)*(uint *)_ArgList;
                  }
                  else {
                    uVar16 = (ulonglong)*(int *)_ArgList;
                  }
                }
                else if ((uVar13 & 0x40) == 0) {
                  uVar16 = (ulonglong)(ushort)*(wchar_t *)_ArgList;
                }
                else {
                  uVar16 = (ulonglong)*(wchar_t *)_ArgList;
                }
              }
              else {
                uVar16 = *(ulonglong *)_ArgList;
              }
              _ArgList = (va_list)((longlong)_ArgList + 8);
              if (((uVar13 & 0x40) != 0) && ((longlong)uVar16 < 0)) {
                uVar16 = -uVar16;
                uVar13 = uVar13 | 0x100;
              }
              if (((uVar13 & 0x8000) == 0) && ((uVar13 >> 0xc & 1) == 0)) {
                uVar16 = uVar16 & 0xffffffff;
              }
              if ((int)uVar7 < 0) {
                uVar7 = 1;
              }
              else {
                uVar13 = uVar13 & 0xfffffff7;
                if (0x200 < (int)uVar7) {
                  uVar7 = 0x200;
                }
              }
              pwVar10 = &uStack_49;
              local_288 = -(uint)(uVar16 != 0) & uVar18;
              for (; (local_278 = uVar7 - 1, 0 < (int)uVar7 || (uVar16 != 0));
                  uVar16 = uVar16 / (ulonglong)(longlong)iVar8) {
                uVar7 = (int)(uVar16 % (ulonglong)(longlong)iVar8) + 0x30;
                cVar6 = (char)uVar7;
                if (0x39 < uVar7) {
                  cVar6 = cVar6 + (char)local_264;
                }
                *(char *)pwVar10 = cVar6;
                pwVar10 = (wchar_t *)((longlong)pwVar10 + -1);
                uVar7 = local_278;
              }
              local_280 = (int)&uStack_49 - (int)pwVar10;
              pcVar11 = (char *)((longlong)pwVar10 + 1);
              uVar18 = local_288;
              if ((uVar13 >> 9 & 1) == 0) {
              }
              else {
                if (local_280 != 0) {
                  if (*pcVar11 == '0') goto LAB_000257eb;
                }
                local_280 = local_280 + 1;
                *(undefined1 *)pwVar10 = 0x30;
                pcVar11 = (char *)pwVar10;
              }
            }
LAB_000257eb:
            pFVar5 = local_260;
            if (local_268 == 0) {
              if ((uVar13 & 0x40) != 0) {
                if ((uVar13 >> 8 & 1) == 0) {
                  if ((uVar13 & 1) == 0) {
                    if ((uVar13 & 2) == 0) goto LAB_00025830;
                    local_27c = 0x20;
                  }
                  else {
                    local_27c = 0x2b;
                  }
                }
                else {
                  local_27c = 0x2d;
                }
                local_288 = 1;
              }
LAB_00025830:
              uVar7 = local_288;
              iVar20 = (uVar19 - local_280) - local_288;
              if ((uVar13 & 0xc) == 0) {
                write_multi_char(0x20,iVar20,local_260,&local_284);
              }
              write_string(&local_27c,uVar7,pFVar5,&local_284);
              if (((uVar13 & 8) != 0) && ((uVar13 & 4) == 0)) {
                write_multi_char(0x30,iVar20,pFVar5,&local_284);
              }
              if ((local_270 == 0) || ((int)local_280 < 1)) {
                write_string((byte *)pcVar11,local_280,pFVar5,&local_284);
              }
              else {
                pwVar12 = (wchar_t *)pcVar11;
                uVar7 = local_280;
                do {
                  _WCh = *pwVar12;
                  uVar7 = uVar7 - 1;
                  pwVar12 = pwVar12 + 1;
                  eVar9 = wctomb_s(local_250,(char *)((longlong)&uStack_49 + 1),6,_WCh);
                  if ((eVar9 != 0) || (local_250[0] == 0)) {
                    local_284 = -1;
                    break;
                  }
                  write_string((byte *)((longlong)&uStack_49 + 1),local_250[0],local_260,&local_284)
                  ;
                } while (uVar7 != 0);
              }
              if ((-1 < local_284) && ((uVar13 & 4) != 0)) {
                write_multi_char(0x20,iVar20,local_260,&local_284);
                pwVar12 = local_258;
                uVar14 = uVar13;
                uVar19 = local_274;
                goto LAB_000259ea;
              }
              uVar19 = local_274;
              goto LAB_000259f2;
            }
            goto LAB_000259f7;
          }
        }
LAB_00025a00:
        bVar17 = *(byte *)pwVar12;
        _Format = (char *)pwVar12;
        uVar18 = uVar15;
      } while (bVar17 != 0);
    }
  }
  return iVar20;
}



===== write_char @ 00025b58 =====

/* Library Function - Single Match
    write_char
   
   Library: Visual Studio 2019 Release */

void write_char(byte param_1,FILE *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  
  if (((param_2->_flag & 0x40U) == 0) || (param_2->_base != (char *)0x0)) {
    piVar1 = &param_2->_cnt;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      uVar2 = _flsbuf((int)(char)param_1,param_2);
    }
    else {
      *param_2->_ptr = param_1;
      param_2->_ptr = param_2->_ptr + 1;
      uVar2 = (uint)param_1;
    }
    if (uVar2 == 0xffffffff) {
      *param_3 = -1;
    }
    else {
      *param_3 = *param_3 + 1;
    }
  }
  else {
    *param_3 = *param_3 + 1;
  }
  return;
}



===== write_multi_char @ 00025ba0 =====

/* Library Function - Single Match
    write_multi_char
   
   Library: Visual Studio 2019 Release */

void write_multi_char(byte param_1,int param_2,FILE *param_3,int *param_4)

{
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      write_char(param_1,param_3,param_4);
      if (*param_4 == -1) {
        return;
      }
    } while (0 < param_2);
  }
  return;
}



===== write_string @ 00025bf4 =====

/* Library Function - Single Match
    write_string
   
   Library: Visual Studio 2019 Release */

void write_string(byte *param_1,int param_2,FILE *param_3,int *param_4)

{
  if (((param_3->_flag & 0x40U) == 0) || (param_3->_base != (char *)0x0)) {
    while (0 < param_2) {
      param_2 = param_2 + -1;
      write_char(*param_1,param_3,param_4);
      param_1 = param_1 + 1;
      if (*param_4 == -1) {
        if (gbl_errno != 0x2a) {
          return;
        }
        write_char(0x3f,param_3,param_4);
      }
    }
  }
  else {
    *param_4 = *param_4 + param_2;
  }
  return;
}



===== _get_printf_count_output @ 00025c74 =====

int __cdecl _get_printf_count_output(void)

{
  return (int)(DAT_000290a0 == (__security_cookie | 1));
}



===== __GSHandlerCheck @ 00025c8c =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 00025cac =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  
  bVar1 = *(byte *)((ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8) +
                    *(longlong *)(param_2 + 8) + 3);
  lVar2 = CONCAT71((int7)((ulonglong)*(longlong *)(param_2 + 0x10) >> 8),bVar1);
  if ((bVar1 & 0xf) != 0) {
    lVar2 = (longlong)(int)(bVar1 & 0xfffffff0);
  }
  return lVar2;
}



===== _wctomb_s_l @ 00025d10 =====

errno_t __cdecl
_wctomb_s_l(int *_SizeConverted,char *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale)

{
  int iVar1;
  int local_res10 [4];
  wchar_t local_res20 [4];
  
  if ((_MbCh == (char *)0x0) && (_SizeInBytes != 0)) {
    if (_SizeConverted != (int *)0x0) {
      *_SizeConverted = 0;
    }
  }
  else {
    if (_SizeConverted != (int *)0x0) {
      *_SizeConverted = -1;
    }
    local_res20[0] = _WCh;
    if (0x7fffffff < _SizeInBytes) {
      _guard_check_icall();
      return 0x16;
    }
    if (_MbCh == (char *)0x0) {
      if (_SizeConverted != (int *)0x0) {
        *_SizeConverted = __mb_cur_max;
      }
    }
    else {
      iVar1 = RtlUnicodeToMultiByteN(_MbCh,_SizeInBytes & 0xffffffff,local_res10,local_res20,2);
      if (iVar1 < 0) {
        gbl_errno = 0x2a;
        return 0x2a;
      }
      if (_SizeConverted != (int *)0x0) {
        *_SizeConverted = local_res10[0];
      }
    }
  }
  return 0;
}



===== wctomb_s @ 00025db8 =====

errno_t __cdecl wctomb_s(int *_SizeConverted,char *_MbCh,rsize_t _SizeInBytes,wchar_t _WCh)

{
  errno_t eVar1;
  
  eVar1 = _wctomb_s_l(_SizeConverted,_MbCh,_SizeInBytes,_WCh,(_locale_t)0x0);
  return eVar1;
}



===== RtlUnicodeToMultiByteN @ 00025dcc =====

void RtlUnicodeToMultiByteN(void)

{
                    /* WARNING: Could not recover jumptable at 0x00025dcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlUnicodeToMultiByteN();
  return;
}



===== __C_specific_handler @ 00025dd2 =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00025dd2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== memcpy @ 00025e00 =====

void * __cdecl memcpy(void *_Dst,void *_Src,size_t _Size)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  uint uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  
  uVar11 = (longlong)_Src - (longlong)_Dst;
  if (_Src < _Dst) {
    puVar9 = (undefined8 *)((longlong)_Dst + _Size);
    if (0x4e < _Size) {
      if (uVar11 < 0xfffffffffffffff1) {
        uVar12 = (ulonglong)((uint)puVar9 & 0xf);
        if (((ulonglong)puVar9 & 0xf) != 0) {
          _Size = _Size - uVar12;
          uVar12 = -uVar12;
          puVar10 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar9);
          uVar4 = puVar10[1];
          puVar9[-2] = *puVar10;
          puVar9[-1] = uVar4;
        }
        puVar9 = (undefined8 *)(uVar12 + (longlong)puVar9);
      }
      else {
        while (((ulonglong)puVar9 & 0xf) != 0) {
          puVar9 = (undefined8 *)((longlong)puVar9 + -1);
          _Size = _Size - 1;
          *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
        }
      }
      uVar12 = _Size >> 5;
      if ((0x2000 < uVar12) && (uVar11 < 0xfffffffffffffe01)) {
        do {
          iVar7 = 4;
          do {
            puVar10 = puVar9;
            iVar7 = iVar7 + -1;
            puVar9 = puVar10 + -0x10;
          } while (iVar7 != 0);
          iVar7 = 8;
          puVar10 = puVar10 + 0x30;
          do {
            puVar9 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar10);
            uVar4 = puVar9[1];
            puVar1 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar10);
            uVar5 = *puVar1;
            uVar6 = puVar1[1];
            puVar10[-2] = *puVar9;
            puVar10[-1] = uVar4;
            puVar10[-4] = uVar5;
            puVar10[-3] = uVar6;
            puVar9 = puVar10 + -8;
            puVar1 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar9);
            uVar4 = puVar1[1];
            uVar5 = *(undefined8 *)(uVar11 + (longlong)puVar9);
            uVar6 = ((undefined8 *)(uVar11 + (longlong)puVar9))[1];
            puVar10[-6] = *puVar1;
            puVar10[-5] = uVar4;
            *puVar9 = uVar5;
            puVar10[-7] = uVar6;
            iVar7 = iVar7 + -1;
            puVar10 = puVar9;
          } while (iVar7 != 0);
          _Size = _Size - 0x200;
        } while (0x1ff < _Size);
        LOCK();
        UNLOCK();
        uVar12 = _Size >> 5;
        if (uVar12 == 0) goto LAB_00025fb7;
      }
      _Size = _Size & 0x1f;
      puVar10 = puVar9;
      do {
        puVar1 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar10);
        uVar4 = puVar1[1];
        puVar9 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar10);
        uVar5 = *puVar9;
        uVar6 = puVar9[1];
        puVar9 = puVar10 + -4;
        puVar10[-2] = *puVar1;
        puVar10[-1] = uVar4;
        *puVar9 = uVar5;
        puVar10[-3] = uVar6;
        uVar12 = uVar12 - 1;
        puVar10 = puVar9;
      } while (uVar12 != 0);
    }
LAB_00025fb7:
    for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar10 = (undefined8 *)((uVar11 - 8) + (longlong)puVar9);
      puVar9 = puVar9 + -1;
      *puVar9 = *puVar10;
    }
    for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
      puVar3 = (undefined1 *)((uVar11 - 1) + (longlong)puVar9);
      puVar9 = (undefined8 *)((longlong)puVar9 + -1);
      *(undefined1 *)puVar9 = *puVar3;
    }
    return _Dst;
  }
  puVar9 = _Dst;
  if (0x4e < _Size) {
    if (uVar11 < 0x10) {
      for (; ((ulonglong)puVar9 & 0xf) != 0; puVar9 = (undefined8 *)((longlong)puVar9 + 1)) {
        _Size = _Size - 1;
        *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
      }
    }
    else {
      uVar8 = -(int)_Dst & 0xf;
      if (uVar8 != 0) {
        _Size = _Size - uVar8;
        uVar4 = ((undefined8 *)(uVar11 + (longlong)_Dst))[1];
        *(undefined8 *)_Dst = *(undefined8 *)(uVar11 + (longlong)_Dst);
        *(undefined8 *)((longlong)_Dst + 8) = uVar4;
      }
      puVar9 = (undefined8 *)((ulonglong)uVar8 + (longlong)_Dst);
    }
    uVar12 = _Size >> 5;
    if ((0x2000 < uVar12) && (0x1ff < uVar11)) {
      do {
        iVar7 = 4;
        do {
          puVar10 = puVar9;
          iVar7 = iVar7 + -1;
          puVar9 = puVar10 + 0x10;
        } while (iVar7 != 0);
        iVar7 = 8;
        puVar10 = puVar10 + -0x30;
        do {
          uVar4 = ((undefined8 *)(uVar11 + (longlong)puVar10))[1];
          puVar9 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar10);
          uVar5 = *puVar9;
          uVar6 = puVar9[1];
          *puVar10 = *(undefined8 *)(uVar11 + (longlong)puVar10);
          puVar10[1] = uVar4;
          puVar10[2] = uVar5;
          puVar10[3] = uVar6;
          puVar9 = puVar10 + 8;
          puVar1 = (undefined8 *)((uVar11 - 0x20) + (longlong)puVar9);
          uVar4 = puVar1[1];
          puVar2 = (undefined8 *)((uVar11 - 0x10) + (longlong)puVar9);
          uVar5 = *puVar2;
          uVar6 = puVar2[1];
          puVar10[4] = *puVar1;
          puVar10[5] = uVar4;
          puVar10[6] = uVar5;
          puVar10[7] = uVar6;
          iVar7 = iVar7 + -1;
          puVar10 = puVar9;
        } while (iVar7 != 0);
        _Size = _Size - 0x200;
      } while (0x1ff < _Size);
      LOCK();
      UNLOCK();
      uVar12 = _Size >> 5;
      if (uVar12 == 0) goto LAB_00025e12;
    }
    _Size = _Size & 0x1f;
    puVar10 = puVar9;
    do {
      uVar4 = ((undefined8 *)(uVar11 + (longlong)puVar10))[1];
      puVar9 = (undefined8 *)(uVar11 + 0x10 + (longlong)puVar10);
      uVar5 = *puVar9;
      uVar6 = puVar9[1];
      puVar9 = puVar10 + 4;
      *puVar10 = *(undefined8 *)(uVar11 + (longlong)puVar10);
      puVar10[1] = uVar4;
      puVar10[2] = uVar5;
      puVar10[3] = uVar6;
      uVar12 = uVar12 - 1;
      puVar10 = puVar9;
    } while (uVar12 != 0);
  }
LAB_00025e12:
  for (uVar12 = _Size >> 3; uVar12 != 0; uVar12 = uVar12 - 1) {
    *puVar9 = *(undefined8 *)(uVar11 + (longlong)puVar9);
    puVar9 = puVar9 + 1;
  }
  for (uVar12 = _Size & 7; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined1 *)puVar9 = *(undefined1 *)(uVar11 + (longlong)puVar9);
    puVar9 = (undefined8 *)((longlong)puVar9 + 1);
  }
  return _Dst;
}



===== memset @ 00026140 =====

void * __cdecl memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  void *pvVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  uVar4 = (ulonglong)(uint)_Val;
  pvVar2 = _Dst;
  if (7 < _Size) {
    uVar4 = (ulonglong)(byte)_Val * 0x101010101010101;
    if (0x46 < _Size) {
      uVar1 = -(int)_Dst & 7;
      if (uVar1 != 0) {
        _Size = _Size - uVar1;
        *(ulonglong *)_Dst = uVar4;
      }
      puVar3 = (ulonglong *)((ulonglong)uVar1 + (longlong)_Dst);
      uVar6 = _Size >> 6;
      uVar5 = _Size >> 3 & 7;
      if (uVar5 == 0) goto LAB_00026200;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_000261fd_caseD_2;
      case 3:
        goto switchD_000261fd_caseD_3;
      case 4:
        goto switchD_000261fd_caseD_4;
      case 5:
        goto switchD_000261fd_caseD_5;
      case 6:
        goto switchD_000261fd_caseD_6;
      case 7:
        goto switchD_000261fd_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_00026200:
        *puVar3 = uVar4;
switchD_000261fd_caseD_7:
        puVar3[1] = uVar4;
switchD_000261fd_caseD_6:
        puVar3[2] = uVar4;
switchD_000261fd_caseD_5:
        puVar3[3] = uVar4;
switchD_000261fd_caseD_4:
        puVar3[4] = uVar4;
switchD_000261fd_caseD_3:
        puVar3[5] = uVar4;
switchD_000261fd_caseD_2:
        puVar3[6] = uVar4;
      }
      for (uVar5 = _Size & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(char *)((uVar5 - 1) + (longlong)puVar3) = (char)uVar4;
      }
      return _Dst;
    }
    uVar5 = _Size & 0xfffffffffffffff8;
    pvVar2 = (void *)((longlong)_Dst + uVar5);
    do {
      *(ulonglong *)((uVar5 - 8) + (longlong)_Dst) = uVar4;
      uVar5 = uVar5 - 8;
    } while (uVar5 != 0);
  }
  for (uVar5 = _Size & 7; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(char *)((uVar5 - 1) + (longlong)pvVar2) = (char)uVar4;
  }
  return _Dst;
}



===== nvrUnload @ 0002b000 =====

void nvrUnload(void)

{
  if (gUseNvrWorkItem != '\0') {
    nvrTerminateWorkThread();
  }
  if (DAT_000299d8 != 0) {
    ExFreePoolWithTag(DAT_000299d8,0);
  }
  NvRaidApiUnloadRaidSystem();
  return;
}



===== nvrAddDevice @ 0002b030 =====

ulonglong nvrAddDevice(longlong param_1,undefined8 param_2)

{
  byte *pbVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  wchar_t *_Str;
  wchar_t *pwVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  wchar_t *pwVar9;
  byte bVar10;
  uint local_res18 [2];
  longlong local_res20;
  
  local_res20 = 0;
  _Str = (wchar_t *)0x0;
  uVar8 = 0;
  local_res18[0] = 0;
  do {
    pwVar9 = _Str;
    iVar3 = IoGetDeviceProperty(param_2,0xf,uVar8,_Str,local_res18);
    if (iVar3 != -0x3fffffdd) {
LAB_0002b0b4:
      bVar10 = 0;
      if (-1 < iVar3) {
        pwVar5 = wcsstr(_Str,L"ACPI");
        bVar10 = 0;
        if (pwVar5 != (wchar_t *)0x0) {
          bVar10 = 1;
        }
      }
      if (_Str != (wchar_t *)0x0) {
        ExFreePoolWithTag(_Str,0);
      }
      if (bVar10 != 0) {
        nvrScsiPortAddDevice(param_1,param_2,uVar8,pwVar9);
      }
      lVar6 = IoGetAttachedDeviceReference(param_2);
      uVar8 = ClassClaimDevice(lVar6,0);
      if (-1 < (int)uVar8) {
        uVar4 = ClassCreateDeviceObject(param_1,0,param_2,1,&local_res20);
        uVar8 = (ulonglong)uVar4;
        if ((int)uVar4 < 0) {
          local_res20 = 0;
        }
        else {
          *(uint *)(local_res20 + 0x30) = *(uint *)(local_res20 + 0x30) | 0x10;
          lVar2 = *(longlong *)(local_res20 + 0x40);
          pbVar1 = (byte *)(*(longlong *)(lVar2 + 0x60) + 0xe0);
          *pbVar1 = *pbVar1 ^ (*(byte *)(*(longlong *)(lVar2 + 0x60) + 0xe0) ^ bVar10) & 1;
          *(undefined4 *)(lVar2 + 600) = 0;
          if (*(uint *)(local_res20 + 0x98) < *(uint *)(lVar6 + 0x98)) {
            *(uint *)(local_res20 + 0x98) = *(uint *)(lVar6 + 0x98);
          }
          *(undefined8 *)(lVar2 + 0x200) = param_2;
          lVar7 = IoAttachDeviceToDeviceStack(local_res20,param_2);
          *(longlong *)(lVar2 + 0x10) = lVar7;
          if (lVar7 != 0) {
            *(uint *)(local_res20 + 0x30) = *(uint *)(local_res20 + 0x30) & 0xffffff7f;
            ObfDereferenceObject(lVar6);
            return 0;
          }
          uVar8 = 0xc0000001;
          if (local_res20 != 0) {
            IoDeleteDevice();
          }
        }
        ObfDereferenceObject(lVar6);
      }
      return uVar8;
    }
    if (_Str != (wchar_t *)0x0) {
      ExFreePoolWithTag(_Str,0);
    }
    uVar8 = 0x654e7652;
    _Str = (wchar_t *)ExAllocatePoolWithTag(1,local_res18[0]);
    if (_Str == (wchar_t *)0x0) {
      iVar3 = -0x3fffff66;
      goto LAB_0002b0b4;
    }
    uVar8 = (ulonglong)local_res18[0];
  } while( true );
}



===== nvrInitFdo @ 0002b1e4 =====

undefined8 nvrInitFdo(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  longlong lVar6;
  uint uVar7;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(lVar2 + 0x60);
  if ((*(byte *)(lVar3 + 0xe0) & 1) == 0) {
    ClassInitializeSrbLookasideList(lVar2,0x10);
    *(undefined4 *)(lVar2 + 0x250) = 0x200000;
    if ((*(char *)(*(longlong *)(lVar2 + 0x208) + 0xb) != '\0') &&
       (*(char *)(*(longlong *)(lVar2 + 0x210) + 0x16) != '\0')) {
      *(undefined4 *)(lVar2 + 0x250) = 2;
    }
    if ((*(uint *)(param_1 + 0x34) & 1) == 0) {
      *(ushort *)(lVar2 + 0x280) = *(ushort *)(lVar2 + 0x280) | 4;
    }
    *(undefined8 *)(lVar2 + 0x228) = 0;
    *(undefined8 *)(lVar2 + 0x230) = 0;
    *(undefined8 *)(lVar2 + 0x238) = 0;
    lVar6 = ExAllocatePoolWithTag(4,0x12,0x614e7652);
    *(longlong *)(lVar2 + 0x240) = lVar6;
    if (lVar6 == 0) {
      return 0xc000009a;
    }
    *(undefined8 *)(lVar2 + 0x98) = 0;
    iVar4 = ClassQueryTimeOutRegistryValue(param_1);
    iVar5 = 0x3c;
    if (iVar4 != 0) {
      iVar5 = iVar4;
    }
    *(int *)(lVar2 + 0x248) = iVar5;
    iVar5 = ClassReadDriveCapacity(param_1);
    if ((iVar5 < 0) && ((*(uint *)(param_1 + 0x34) & 1) == 0)) {
      if (*(char *)(*(longlong *)(lVar2 + 0x208) + 10) == '\0') {
        *(undefined4 *)(lVar2 + 0x230) = 0xc;
      }
      else {
        *(undefined4 *)(lVar2 + 0x230) = 0xb;
        *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffd;
      }
    }
    if (*(int *)(lVar2 + 0x23c) == 0) {
      *(undefined4 *)(lVar2 + 0x23c) = 0x200;
    }
    iVar5 = *(int *)(*(longlong *)(lVar2 + 0x210) + 0xc);
    if (iVar5 != 0) {
      iVar5 = iVar5 + -1;
    }
    uVar1 = *(uint *)(*(longlong *)(lVar2 + 0x210) + 8);
    *(undefined4 *)(lVar3 + 8) = 1;
    *(undefined1 *)(lVar3 + 0xd0) = 1;
    uVar7 = iVar5 << 0xc;
    if (uVar1 < (uint)(iVar5 << 0xc)) {
      uVar7 = uVar1;
    }
    *(uint *)(lVar3 + 0xb0) = uVar7;
    nvrideRegistIdeDisk(param_1);
    KeInitializeEvent(lVar3 + 0x150,1);
  }
  return 0;
}



===== nvrStartFdo @ 0002b364 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 nvrStartFdo(longlong param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  undefined1 auStack_d8 [32];
  uint local_b8;
  uint local_b0;
  undefined1 *local_a8;
  int local_98 [2];
  undefined1 local_90 [16];
  undefined1 local_80 [24];
  char local_68 [64];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_d8;
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(lVar2 + 0x60);
  if ((*(byte *)(lVar3 + 0xe0) & 1) == 0) {
    local_a8 = local_80;
    local_b0 = local_b0 & 0xffffff00;
    local_b8 = 8;
    ClassSendDeviceIoControlSynchronous(0x41018,param_1,lVar3 + 0xb4,0);
    local_a8 = (undefined1 *)CONCAT44(local_a8._4_4_,(uint)*(byte *)(lVar3 + 0xbb));
    local_b0 = (uint)*(byte *)(lVar3 + 0xba);
    local_b8 = (uint)*(byte *)(lVar3 + 0xb9);
    iVar4 = RtlStringCbPrintfA(local_68,0x40,"NvRaidDisk%d.%d.%d.%d",
                               (ulonglong)*(byte *)(lVar3 + 0xb8));
    if (-1 < iVar4) {
      RtlInitAnsiString(local_90,local_68);
      lVar1 = lVar3 + 0x130;
      iVar4 = RtlAnsiStringToUnicodeString(lVar1,local_90,1);
      if (-1 < iVar4) {
        iVar4 = IoRegisterDeviceInterface
                          (*(undefined8 *)(lVar2 + 0x200),&GUID_DEVINTERFACE_NVRAID_DISK,lVar1,
                           lVar3 + 0x140);
        if (iVar4 < 0) {
          RtlFreeUnicodeString(lVar1);
          *(undefined8 *)(lVar3 + 0x138) = 0;
          *(undefined8 *)(lVar3 + 0x148) = 0;
        }
        else {
          IoSetDeviceInterfaceState(lVar3 + 0x140,1);
        }
      }
    }
    nvrGetPCIData(param_1,local_98);
    nvrGetIdentifyData(param_1,local_98);
  }
  return 0;
}



===== nvrEnumerateDevice @ 0002b4d0 =====

undefined8 nvrEnumerateDevice(longlong param_1)

{
  nvrEnumerateRaidVolume(param_1);
  return 0;
}



===== nvrFdoDeviceControl @ 0002b4e0 =====

ulonglong nvrFdoDeviceControl(longlong param_1,longlong param_2)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  iVar1 = *(int *)(lVar2 + 0x18);
  if (iVar1 == 0x4100c) {
    uVar5 = IoctlScsiGetInquiryData(param_1,param_2);
    uVar3 = (uint)uVar5;
  }
  else if (iVar1 == 0x41010) {
    uVar5 = IoctlScsiGetCapabilities(param_1,param_2);
    uVar3 = (uint)uVar5;
  }
  else {
    if (iVar1 != 0x2d1400) {
LAB_0002b539:
      uVar4 = ClassDeviceControl(param_1,param_2);
      return uVar4;
    }
    if (*(uint *)(lVar2 + 0x10) < 0xc) {
      uVar3 = 0xc0000023;
    }
    else {
      if (**(int **)(param_2 + 0x18) != 1) goto LAB_0002b539;
      uVar5 = IoctlStorageQueryAdapterProperty((longlong)*(int **)(param_2 + 0x18),param_2,lVar2);
      uVar3 = (uint)uVar5;
    }
  }
  *(uint *)(param_2 + 0x30) = uVar3;
  ClassReleaseRemoveLock(param_1,param_2);
  ClassCompleteRequest(param_1,param_2,0);
  return (ulonglong)uVar3;
}



===== nvrCreatePdo @ 0002b590 =====

ulonglong nvrCreatePdo(longlong param_1,longlong param_2,longlong *param_3)

{
  longlong *plVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  byte bVar6;
  byte bVar7;
  longlong local_res8;
  
  lVar4 = *(longlong *)(param_1 + 0x40);
  local_res8 = 0;
  uVar3 = ClassCreateDeviceObject(*(undefined8 *)(param_1 + 8),0,param_1,0,&local_res8);
  if (-1 < (int)uVar3) {
    lVar5 = *(longlong *)(local_res8 + 0x40);
    *(uint *)(local_res8 + 0x30) = *(uint *)(local_res8 + 0x30) | 0x10;
    *(char *)(local_res8 + 0x4c) = *(char *)(*(longlong *)(lVar5 + 0x10) + 0x4c) + '\x01';
    NvRaidVolumeSendCommandToVolumes(param_2,&LAB_0001dac0,local_res8);
    if (*(uint *)(local_res8 + 0x98) < *(uint *)(param_1 + 0x98)) {
      *(uint *)(local_res8 + 0x98) = *(uint *)(param_1 + 0x98);
    }
    ClassInitializeSrbLookasideList(lVar5,(-((*(byte *)(lVar4 + 0x250) & 2) != 0) & 0x16U) + 8);
    if (*(char *)(*(longlong *)(lVar4 + 0x208) + 10) != '\0') {
      *(uint *)(local_res8 + 0x34) = *(uint *)(local_res8 + 0x34) | 1;
    }
    plVar1 = *(longlong **)(lVar5 + 0x60);
    bVar6 = 0;
    *(longlong *)(lVar5 + 8) = local_res8;
    *plVar1 = param_2;
    bVar7 = *(byte *)(*(longlong *)(param_2 + 0x58) + 0x16);
    if (bVar7 != 0) {
      do {
        lVar4 = NvRaidApiGetArrayChild(param_2,bVar6);
        if ((lVar4 == 0) || ((*(uint *)(lVar4 + 4) & 1) != 0)) {
          lVar5 = 0;
        }
        else {
          lVar5 = lVar4;
        }
        if (lVar5 != 0) {
          *(byte *)((longlong)plVar1 + 0x1c) =
               *(byte *)((longlong)plVar1 + 0x1c) ^
               (*(char *)(lVar4 + 0x70) << 4 ^ *(byte *)((longlong)plVar1 + 0x1c)) & 0x10;
          break;
        }
        bVar6 = bVar6 + 1;
      } while (bVar6 < bVar7);
    }
    nvrOsUpdateCheckDuplicateMdlPage(local_res8);
    *(undefined4 *)((longlong)plVar1 + 0x94) = 1;
    iVar2 = IoInitializeTimer(local_res8,FUN_0001e3e4,0);
    if (-1 < iVar2) {
      *(byte *)((longlong)plVar1 + 0x1c) = *(byte *)((longlong)plVar1 + 0x1c) | 0x80;
    }
    if (*(uint *)(local_res8 + 0x98) < 3) {
      *(undefined4 *)(local_res8 + 0x98) = 3;
    }
    *(uint *)(local_res8 + 0x30) = *(uint *)(local_res8 + 0x30) & 0xffffff7f;
    *param_3 = local_res8;
    uVar3 = uVar3 & 0xffffffff;
  }
  return uVar3;
}



===== nvrInitPdo @ 0002b724 =====

undefined8 nvrInitPdo(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
  *(undefined4 *)(lVar1 + 0x18) = 0;
  *(undefined4 *)(lVar1 + 8) = 1;
  nvrInitializePendingQueue(lVar1 + 0x28);
  KeInitializeSpinLock(lVar1 + 0xa0);
  return 0;
}



===== nvrStartPdo @ 0002b75c =====

undefined8 nvrStartPdo(longlong param_1)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x40) + 0x60);
  nvrScsiPortBuildPdoDeviceMap(param_1);
  uVar2 = PoRegisterDeviceForIdleDetection(param_1,0xffffffff,0xffffffff,4);
  *(undefined8 *)(lVar1 + 0x10) = uVar2;
  nvrPdoUnlockQueue(param_1);
  nvrPdoStartTimerForPnpIrp(param_1);
  return 0;
}



===== nvrQueryId @ 0002b800 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int nvrQueryId(longlong param_1,int param_2,longlong param_3)

{
  longlong lVar1;
  short sVar2;
  int iVar3;
  void *_Dst;
  char *pcVar4;
  undefined8 uVar5;
  undefined1 auStack_d8 [32];
  short local_b8 [8];
  char local_a8 [24];
  char local_90 [24];
  char local_78 [32];
  char local_58 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  lVar1 = **(longlong **)(*(longlong *)(param_1 + 0x40) + 0x60);
  if (lVar1 == 0) {
    return -0x3fffff40;
  }
  if (param_2 < 0) {
LAB_0002b9e1:
    iVar3 = -0x3ffffffe;
  }
  else {
    if (param_2 < 3) {
      builtin_strncpy(local_78,"SCSI\\Disk% 28.28s$GenDisk",0x1a);
      builtin_strncpy(local_90,"SCSI\\Disk% 28.28s",0x12);
      builtin_strncpy(local_a8,"SCSI\\Disk$SCSI\\RAW",0x13);
      if (param_2 == 1) {
        pcVar4 = local_78;
      }
      else {
        pcVar4 = local_a8;
        if (param_2 != 2) {
          pcVar4 = local_90;
        }
      }
      iVar3 = RtlStringCbPrintfA(local_58,0x40,pcVar4,lVar1 + 0x2c);
      if (iVar3 < 0) {
        return iVar3;
      }
      RtlInitAnsiString(local_b8,local_58);
      if (*NlsMbCodePageTag_exref == (code)0x0) {
        sVar2 = local_b8[0] * 2 + 2;
      }
      else {
        sVar2 = RtlxAnsiStringToUnicodeSize(local_b8);
      }
      *(short *)(param_3 + 2) = sVar2 + 2;
      _Dst = (void *)ExAllocatePoolWithTag(1,sVar2 + 2,0x654e7652);
      *(void **)(param_3 + 8) = _Dst;
      if (_Dst == (void *)0x0) {
        return -0x3fffff66;
      }
      pcVar4 = local_58;
      while (local_58[0] != '\0') {
        if (*pcVar4 == ' ') {
          *pcVar4 = '_';
        }
        if (*pcVar4 == '$') {
          *pcVar4 = '\0';
        }
        pcVar4 = pcVar4 + 1;
        local_58[0] = *pcVar4;
      }
      memset(_Dst,0,(ulonglong)*(ushort *)(param_3 + 2));
      uVar5 = 0;
    }
    else {
      if (param_2 != 3) goto LAB_0002b9e1;
      iVar3 = RtlStringCbPrintfA(local_58,0x40,"%u",(ulonglong)*(byte *)(lVar1 + 8));
      if (iVar3 < 0) {
        return iVar3;
      }
      RtlInitAnsiString(local_b8,local_58);
      uVar5 = 1;
    }
    iVar3 = RtlAnsiStringToUnicodeString(param_3,local_b8,uVar5);
  }
  return iVar3;
}



===== nvrQueryText @ 0002ba08 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 nvrQueryText(longlong param_1,int param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined1 auStack_88 [32];
  undefined1 local_68 [16];
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  undefined4 local_40;
  undefined1 local_3c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_88;
  lVar1 = **(longlong **)(*(longlong *)(param_1 + 0x40) + 0x60);
  if (lVar1 == 0) {
    uVar2 = 0xc00000c0;
  }
  else if (param_2 == 0) {
    local_58 = *(undefined4 *)(lVar1 + 0x2c);
    uStack_54 = *(undefined4 *)(lVar1 + 0x30);
    uStack_50 = *(undefined4 *)(lVar1 + 0x34);
    uStack_4c = *(undefined4 *)(lVar1 + 0x38);
    local_48 = *(undefined8 *)(lVar1 + 0x3c);
    local_40 = *(undefined4 *)(lVar1 + 0x44);
    local_3c = 0;
    RtlInitAnsiString(local_68,&local_58);
    uVar2 = RtlAnsiStringToUnicodeString(param_3,local_68,1);
  }
  else {
    uVar2 = 0xc0000002;
  }
  return uVar2;
}



===== nvrPdoPnpDeviceUsageNotification @ 0002ba9c =====

int nvrPdoPnpDeviceUsageNotification(longlong param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  longlong *plVar3;
  int iVar4;
  longlong local_48;
  undefined1 *local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined1 local_28;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  plVar3 = *(longlong **)(*(longlong *)(param_1 + 0x40) + 0x60);
  if (*plVar3 == 0) {
    iVar4 = -0x3fffff40;
    *(undefined4 *)(param_2 + 0x30) = 0xc00000c0;
  }
  else {
    local_38 = 0;
    local_30 = 0;
    local_28 = 1;
    local_40 = &LAB_0001dadc;
    local_48 = param_2;
    NvRaidVolumeSendCommandToVolumes(*plVar3,nvrPdoSendIrpSynch_Callback,&local_48);
    iVar4 = *(int *)(param_2 + 0x30);
    if (-1 < iVar4) {
      iVar4 = (*pClassDispatchPnp)(param_1,param_2);
      IoInvalidateDeviceState(param_1);
      return iVar4;
    }
    cVar1 = *(char *)(lVar2 + 8);
    *(bool *)(lVar2 + 8) = cVar1 == '\0';
    local_40 = (undefined1 *)0x0;
    NvRaidVolumeSendCommandToVolumes(*plVar3,nvrPdoSendIrpSynch_Callback,&local_48);
    *(char *)(lVar2 + 8) = cVar1;
    *(int *)(param_2 + 0x30) = iVar4;
  }
  ClassCompleteRequest(param_1,param_2,0);
  return iVar4;
}



===== nvrScsiPortInitialize @ 0002bb8c =====

int nvrScsiPortInitialize(longlong param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong lVar4;
  undefined8 *puVar5;
  undefined8 *_Src;
  undefined8 *puVar6;
  undefined8 *local_res10;
  
  local_res10 = (undefined8 *)0x0;
  iVar3 = IoAllocateDriverObjectExtension(param_1,0x4452564e,0xe0,&local_res10);
  if (-1 < iVar3) {
    _Src = (undefined8 *)(param_1 + 0x70);
    if ((((uint)_Src | (uint)local_res10) & 0xf) == 0) {
      lVar4 = 1;
      puVar2 = _Src;
      do {
        puVar6 = local_res10;
        puVar5 = puVar2;
        uVar1 = puVar5[1];
        *puVar6 = *puVar5;
        puVar6[1] = uVar1;
        uVar1 = puVar5[3];
        puVar6[2] = puVar5[2];
        puVar6[3] = uVar1;
        uVar1 = puVar5[5];
        puVar6[4] = puVar5[4];
        puVar6[5] = uVar1;
        uVar1 = puVar5[7];
        puVar6[6] = puVar5[6];
        puVar6[7] = uVar1;
        uVar1 = puVar5[9];
        puVar6[8] = puVar5[8];
        puVar6[9] = uVar1;
        uVar1 = puVar5[0xb];
        puVar6[10] = puVar5[10];
        puVar6[0xb] = uVar1;
        uVar1 = puVar5[0xd];
        puVar6[0xc] = puVar5[0xc];
        puVar6[0xd] = uVar1;
        uVar1 = puVar5[0xf];
        puVar6[0xe] = puVar5[0xe];
        puVar6[0xf] = uVar1;
        lVar4 = lVar4 + -1;
        puVar2 = puVar5 + 0x10;
        local_res10 = puVar6 + 0x10;
      } while (lVar4 != 0);
      uVar1 = puVar5[0x11];
      puVar6[0x10] = puVar5[0x10];
      puVar6[0x11] = uVar1;
      uVar1 = puVar5[0x13];
      puVar6[0x12] = puVar5[0x12];
      puVar6[0x13] = uVar1;
      uVar1 = puVar5[0x15];
      puVar6[0x14] = puVar5[0x14];
      puVar6[0x15] = uVar1;
      uVar1 = puVar5[0x17];
      puVar6[0x16] = puVar5[0x16];
      puVar6[0x17] = uVar1;
      uVar1 = puVar5[0x19];
      puVar6[0x18] = puVar5[0x18];
      puVar6[0x19] = uVar1;
      uVar1 = puVar5[0x1b];
      puVar6[0x1a] = puVar5[0x1a];
      puVar6[0x1b] = uVar1;
    }
    else {
      memcpy(local_res10,_Src,0xe0);
    }
    for (lVar4 = 0x1c; lVar4 != 0; lVar4 = lVar4 + -1) {
      *_Src = nvrScsiPortDispatch;
      _Src = _Src + 1;
    }
  }
  return iVar3;
}



===== nvrScsiPortInvalidRequest @ 0002bc90 =====

void nvrScsiPortInvalidRequest(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (**(char **)(param_2 + 0xb8) == '\x16') {
    PoStartNextPowerIrp(param_2);
  }
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
                    /* WARNING: Could not recover jumptable at 0x0002bcd5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IofCallDriver(*(undefined8 *)(lVar1 + 800),param_2);
  return;
}



===== nvrScsiPortCreateClose @ 0002bcdc =====

undefined8 nvrScsiPortCreateClose(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0;
  IofCompleteRequest(param_2,0);
  return 0;
}



===== nvrScsiPortDeviceControl @ 0002bcf8 =====

int nvrScsiPortDeviceControl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int *_Dst;
  longlong lVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong local_res8;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  undefined8 local_3c;
  undefined4 local_34;
  undefined1 local_30;
  undefined2 local_2e;
  undefined2 uStack_2c;
  undefined6 uStack_2a;
  
  lVar1 = *(longlong *)(param_2 + 0xb8);
  uVar7 = 0;
  if (*(int *)(lVar1 + 0x18) == 0x4d008) {
    lVar2 = *(longlong *)(param_2 + 0x18);
    if ((((lVar2 != 0) && (0x1b < *(uint *)(lVar1 + 0x10))) && (*(int *)(lVar2 + 4) == 0x52564e5f))
       && (*(int *)(lVar2 + 8) == 0x5f444941)) {
      local_res8 = 0x1c;
      uVar5 = nvrOsRaidIoControl(*(uint *)(lVar2 + 0x10),*(uint *)(lVar2 + 0x18),
                                 (uint *)(lVar2 + 0x1c),(int *)(lVar2 + 0x14),
                                 (longlong *)&local_res8);
      iVar4 = (int)uVar5;
      if (*(int *)(lVar2 + 0x14) == -0x3fffffdd) {
        uVar7 = 0x1c;
      }
      else {
        uVar7 = local_res8;
      }
      goto LAB_0002be91;
    }
  }
  else if (((*(int *)(lVar1 + 0x18) == 0x2d1400) &&
           (*(longlong *)(*(longlong *)(param_1 + 0x40) + 0x328) != 0)) &&
          ((_Dst = *(int **)(param_2 + 0x18), _Dst != (int *)0x0 && (0xb < *(uint *)(lVar1 + 0x10)))
          )) {
    iVar4 = *_Dst;
    if (iVar4 == 0) {
      iVar4 = _Dst[1];
      if (iVar4 == 0) {
        memset(&local_48,0,0x28);
        uVar6 = 0x28;
        if (*(uint *)(lVar1 + 8) < 0x28) {
          uVar6 = *(uint *)(lVar1 + 8);
        }
        local_48 = 0x28;
        local_44 = 0x28;
        uVar7 = (ulonglong)uVar6;
        local_40 = CONCAT31(local_40._1_3_,3);
        local_40 = local_40 & 0xffffff;
        local_3c = 0;
        local_34 = 0;
        uStack_2c = 8;
        uStack_2a = 0;
        memcpy(_Dst,&local_48,(ulonglong)uVar6);
        iVar4 = 0;
LAB_0002be84:
        if (iVar4 != -0x3ffffffe) goto LAB_0002be91;
      }
      else {
LAB_0002bdbf:
        if (iVar4 == 1) goto LAB_0002bdc7;
      }
    }
    else {
      if (iVar4 == 1) {
        iVar4 = _Dst[1];
        if (iVar4 != 0) goto LAB_0002bdbf;
        memset(&local_48,0,0x20);
        uVar6 = 0x20;
        if (*(uint *)(lVar1 + 8) < 0x20) {
          uVar6 = *(uint *)(lVar1 + 8);
        }
        local_48 = 0x20;
        local_44 = 0x20;
        uVar7 = (ulonglong)uVar6;
        local_40 = 0x40000;
        local_3c = 0x3ffffffffffff;
        local_34 = 1;
        local_30 = 8;
        local_2e = 0;
        uStack_2c = 0;
        memcpy(_Dst,&local_48,(ulonglong)uVar6);
LAB_0002bdc7:
        iVar4 = 0;
        goto LAB_0002be91;
      }
      if (iVar4 - 5U < 2) {
        cVar3 = IoIsWdmVersionAvailable(6,0);
        if (cVar3 == '\0') {
          iVar4 = -0x3ffffffe;
        }
        else {
          uVar5 = FUN_0002409c(_Dst,param_2,lVar1);
          iVar4 = (int)uVar5;
          if (-1 < iVar4) {
            uVar7 = *(ulonglong *)(param_2 + 0x38);
          }
        }
        goto LAB_0002be84;
      }
    }
  }
  iVar4 = -0x3ffffff0;
LAB_0002be91:
  *(int *)(param_2 + 0x30) = iVar4;
  if (-1 < iVar4) {
    *(ulonglong *)(param_2 + 0x38) = uVar7;
  }
  IofCompleteRequest(param_2,0);
  return iVar4;
}



===== nvrScsiPortBuildPdoDeviceMap @ 0002bf2c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int nvrScsiPortBuildPdoDeviceMap(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  ulonglong uVar4;
  undefined1 auStack_108 [32];
  undefined8 local_e8;
  uint local_e0;
  undefined8 local_d8;
  ushort local_d0 [4];
  undefined8 local_c8;
  undefined1 local_c0 [16];
  undefined1 local_b0 [24];
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined8 local_88;
  undefined4 local_80;
  undefined1 local_7c;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_108;
  local_e8 = 0;
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x40) + 0x60);
  local_d8 = 0;
  iVar3 = RtlStringCbPrintfA((char *)&local_98,0x80,
                             "\\Registry\\Machine\\Hardware\\DeviceMap\\Scsi\\Scsi Port %d\\Scsi Bus %d"
                             ,(ulonglong)_ScsiPortNumber);
  if (-1 < iVar3) {
    uVar4 = FUN_00024174(&local_98,&local_d8);
    iVar3 = (int)uVar4;
    if (-1 < iVar3) {
      iVar3 = RtlStringCbPrintfA((char *)&local_98,0x80,"Target Id %d",
                                 (ulonglong)*(byte *)(*plVar1 + 8));
      if (-1 < iVar3) {
        uVar4 = FUN_00024174(&local_98,&local_d8);
        iVar3 = (int)uVar4;
        if (-1 < iVar3) {
          iVar3 = RtlStringCbPrintfA((char *)&local_98,0x80,"Logical Unit Id %d",0);
          if (-1 < iVar3) {
            uVar4 = FUN_00024174(&local_98,&local_d8);
            iVar3 = (int)uVar4;
            if (-1 < iVar3) {
              RtlInitUnicodeString(local_c0,L"Identifier");
              lVar2 = *plVar1;
              local_98 = *(undefined4 *)(lVar2 + 0x2c);
              uStack_94 = *(undefined4 *)(lVar2 + 0x30);
              uStack_90 = *(undefined4 *)(lVar2 + 0x34);
              uStack_8c = *(undefined4 *)(lVar2 + 0x38);
              local_88 = *(undefined8 *)(lVar2 + 0x3c);
              local_80 = *(undefined4 *)(lVar2 + 0x44);
              local_7c = 0;
              RtlInitAnsiString(local_b0,&local_98);
              iVar3 = RtlAnsiStringToUnicodeString(local_d0,local_b0,1);
              if (-1 < iVar3) {
                local_e0 = (uint)local_d0[0];
                local_e8 = local_c8;
                ZwSetValueKey(local_d8,local_c0,0,1);
                RtlFreeUnicodeString(local_d0);
                RtlInitUnicodeString(local_c0,L"Type");
                RtlInitUnicodeString(local_d0,L"DiskPeripheral");
                local_e0 = (uint)local_d0[0];
                local_e8 = local_c8;
                iVar3 = ZwSetValueKey(local_d8,local_c0,0,1);
                ZwClose(local_d8);
              }
            }
          }
        }
      }
    }
  }
  return iVar3;
}



===== nvrScsiPortDispatchPnp @ 0002c124 =====

void nvrScsiPortDispatchPnp(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  bVar1 = *(byte *)(*(longlong *)(param_2 + 0xb8) + 1);
  if (bVar1 == 0) {
LAB_0002c18e:
    if ((*(byte *)(lVar2 + 0x340) & 2) != 0) {
      IoStartTimer();
    }
  }
  else {
    if (bVar1 != 2) {
      if (bVar1 < 4) goto LAB_0002c19c;
      if (bVar1 < 6) {
        if ((*(byte *)(lVar2 + 0x340) & 2) != 0) {
          IoStopTimer();
        }
        goto LAB_0002c19c;
      }
      if (bVar1 == 6) goto LAB_0002c18e;
      if (bVar1 != 0x17) goto LAB_0002c19c;
    }
    IoReleaseRemoveLockAndWaitEx(lVar2 + 0x2e0,0,0x20);
    FUN_00024414();
  }
LAB_0002c19c:
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
                    /* WARNING: Could not recover jumptable at 0x0002c1bb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  IofCallDriver(*(undefined8 *)(lVar2 + 800),param_2);
  return;
}



===== DriverEntry @ 0002d000 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(longlong param_1,ushort *param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 local_198 [2];
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_184;
  code *local_180;
  undefined1 *local_178;
  code *local_170;
  code *local_168;
  undefined8 local_160;
  code *local_158;
  code *local_150;
  code *local_148;
  code *local_140;
  code *local_138;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_dc;
  undefined8 local_d8;
  undefined1 *local_d0;
  code *local_c8;
  code *local_c0;
  undefined8 local_b8;
  code *local_b0;
  code *local_a8;
  code *local_a0;
  code *local_98;
  code *local_90;
  undefined1 *local_88;
  code *local_40;
  code *local_38;
  code *local_30;
  code *local_20;
  
  if (param_1 == 0) {
    uVar2 = nvrDiskDumpEntry((longlong)param_2);
  }
  else {
    NvRaidRegistryPath = 0;
    _DAT_000299d2 = *param_2;
    DAT_000299d8 = ExAllocatePoolWithTag(1,*param_2 + 2,0x644e7652);
    if (DAT_000299d8 == 0) {
      uVar2 = 0xc000009a;
    }
    else {
      RtlCopyUnicodeString(&NvRaidRegistryPath);
      memset(local_198,0,0x188);
      local_158 = nvrInitFdo;
      local_150 = nvrStartFdo;
      local_148 = nvrFdoPower;
      local_180 = nvrFdoProcessError;
      local_170 = nvrFdoDeviceControl;
      local_138 = nvrRemoveDevice;
      local_b0 = nvrInitPdo;
      local_90 = nvrRemoveDevice;
      local_a8 = nvrStartPdo;
      local_178 = &nvrReadWriteVerification;
      local_a0 = nvrPdoPower;
      local_168 = nvrShutdownFlush;
      local_c8 = nvrPdoDeviceControl;
      local_d0 = &nvrReadWriteVerification;
      local_88 = &nvrQueryPnpCapabilities;
      local_c0 = nvrShutdownFlush;
      local_40 = nvrAddDevice;
      local_38 = nvrEnumerateDevice;
      local_30 = nvrQueryId;
      local_198[0] = 0x188;
      local_190 = 0x628;
      local_18c = 7;
      local_20 = nvrUnload;
      local_184 = 0x100;
      local_140 = nvrStopDevice;
      local_160 = 0;
      local_e8 = 800;
      local_e4 = 7;
      local_dc = 0x180;
      local_98 = nvrStopDevice;
      local_d8 = 0;
      local_b8 = 0;
      ClassInitialize(param_1,param_2,local_198);
      nvideRaidInitialize();
      pClassDispatchPnp = *(undefined8 *)(param_1 + 0x148);
      *(undefined1 **)(param_1 + 0x148) = &nvrDispatchPnp;
      _pClassInternalIoControl = *(undefined8 *)(param_1 + 0xe8);
      *(undefined1 **)(param_1 + 0xe8) = &nvrInternalIoControl;
      iVar1 = nvrScsiPortInitialize(param_1);
      uVar2 = CONCAT44(extraout_var,iVar1);
      if (-1 < iVar1) {
        iVar1 = nvrInitWorkThread();
        uVar2 = CONCAT44(extraout_var_00,iVar1);
        if (-1 < iVar1) {
          gUseNvrWorkItem = 1;
        }
      }
    }
  }
  return uVar2;
}



===== nvrDiskDumpEntry @ 0002d24c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nvrDiskDumpEntry(longlong param_1)

{
  longlong *plVar1;
  undefined8 uVar2;
  undefined **ppuVar3;
  undefined8 local_18;
  longlong local_10;
  
  plVar1 = *(longlong **)(*(longlong *)(param_1 + 0x60) + 0x60);
  if (*plVar1 == 0) {
    uVar2 = 0xc00000c0;
  }
  else {
    DAT_00035460 = plVar1[0x18];
    gScratchBufCount = 2;
    gDiskDump = param_1;
    *(code **)(param_1 + 0x38) = nvrDiskDumpOpen;
    *(code **)(param_1 + 0x40) = nvrDiskDumpWrite;
    *(code **)(param_1 + 0x48) = nvrDiskDumpFinish;
    *(undefined1 **)(param_1 + 0x80) = &nvrDiskDumpWriteDma;
    ppuVar3 = &gNvRaidRaidLevelMethods;
    while( true ) {
      if (*ppuVar3 == &RaidLevelMethod_RAID3) {
        *ppuVar3 = &S_RaidLevelMethod_RAID3;
      }
      if (*ppuVar3 == &RaidLevelMethod_RAID5) {
        *ppuVar3 = &S_RaidLevelMethod_RAID5;
      }
      if (*ppuVar3 == &RaidLevelMethod_RAID5_SYM) {
        *ppuVar3 = (undefined *)&S_RaidLevelMethod_RAID5_SYM;
      }
      if (*(int *)*ppuVar3 == 0) break;
      ppuVar3 = ppuVar3 + 1;
    }
    NvRaidApiInitializeRaidSystem(&DAT_0002f008,0x6240,(undefined4 *)&DAT_0002f220,&DAT_0002f220);
    _DAT_0002f084 = 1;
    _DAT_0002f088 = &DAT_00035468;
    local_10 = plVar1[0x16];
    local_18 = *(undefined8 *)(*plVar1 + 0x50);
    NvRaidVolumeSendCommandToVolumes(*plVar1,nvrDiskDumpRegisterDisk,&local_18);
    if (*(int *)(param_1 + 0x108) == 3) {
      gIsCrashDump = 1;
    }
    uVar2 = 0;
  }
  return uVar2;
}



===== nvrDiskDumpRegisterDisk @ 0002d394 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 nvrDiskDumpRegisterDisk(undefined8 *param_1,longlong *param_2)

{
  void *_Dst;
  longlong *_Dst_00;
  undefined8 uVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  longlong lVar6;
  longlong lVar7;
  undefined8 *puVar8;
  int *piVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined1 auStack_1b8 [32];
  undefined8 *local_198 [2];
  undefined8 local_188 [12];
  undefined8 local_128;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1b8;
  lVar3 = param_1[10];
  if (param_1[3] == lVar3) {
    *param_2 = (longlong)&DAT_0002f008;
  }
  else {
    lVar7 = *param_2;
    while (*(longlong *)(lVar7 + 0x10) != lVar3) {
      lVar7 = *(longlong *)(lVar7 + 0x50);
      *param_2 = lVar7;
      lVar3 = param_1[10];
    }
  }
  NvRaidApiCreateVolume(0x2f008,local_198);
  if ((((uint)param_1 | (uint)local_198[0]) & 0xf) == 0) {
    lVar3 = 1;
    puVar4 = local_198[0];
    puVar5 = param_1;
    do {
      uVar1 = puVar5[1];
      *puVar4 = *puVar5;
      puVar4[1] = uVar1;
      uVar1 = puVar5[3];
      puVar4[2] = puVar5[2];
      puVar4[3] = uVar1;
      uVar1 = puVar5[5];
      puVar4[4] = puVar5[4];
      puVar4[5] = uVar1;
      uVar1 = puVar5[7];
      puVar4[6] = puVar5[6];
      puVar4[7] = uVar1;
      uVar1 = puVar5[9];
      puVar4[8] = puVar5[8];
      puVar4[9] = uVar1;
      uVar1 = puVar5[0xb];
      puVar4[10] = puVar5[10];
      puVar4[0xb] = uVar1;
      uVar1 = puVar5[0xd];
      puVar4[0xc] = puVar5[0xc];
      puVar4[0xd] = uVar1;
      puVar10 = puVar5 + 0xe;
      uVar1 = puVar5[0xf];
      puVar8 = puVar4 + 0x10;
      puVar5 = puVar5 + 0x10;
      puVar4[0xe] = *puVar10;
      puVar4[0xf] = uVar1;
      lVar3 = lVar3 + -1;
      puVar4 = puVar8;
    } while (lVar3 != 0);
    *puVar8 = *puVar5;
  }
  else {
    memcpy(local_198[0],param_1,0x88);
  }
  local_198[0][3] = &DAT_0002f008;
  local_198[0][0xf] = 0;
  local_198[0][0x10] = 0;
  *(undefined4 *)((longlong)local_198[0] + 0x7c) = *(undefined4 *)((longlong)param_1 + 0x7c);
  _Dst = (void *)param_2[1];
  local_198[0][0x10] = _Dst;
  uVar2 = *(int *)((longlong)local_198[0] + 0x7c) << 3;
  memset(_Dst,0,(ulonglong)uVar2);
  param_2[1] = param_2[1] + (ulonglong)uVar2;
  if ((undefined *)*param_2 == &DAT_0002f008) {
    DAT_0002f100 = local_198[0];
    *(undefined1 *)(local_198[0] + 1) = 0;
  }
  NvRaidExtendValueSet((int *)(*param_2 + 0x78),(uint)*(byte *)(local_198[0] + 1),local_198[0]);
  local_198[0][10] = *param_2;
  if (param_1[0xb] == 0) {
    lVar3 = param_1[2];
    lVar7 = *(longlong *)(*(longlong *)(lVar3 + 0x40) + 0x60);
    if ((((uint)gDiskDump | (uint)local_188) & 0xf) == 0) {
      lVar6 = 2;
      puVar4 = local_188;
      puVar5 = gDiskDump;
      do {
        puVar8 = puVar5;
        puVar10 = puVar4;
        uVar1 = puVar8[1];
        *puVar10 = *puVar8;
        puVar10[1] = uVar1;
        uVar1 = puVar8[3];
        puVar10[2] = puVar8[2];
        puVar10[3] = uVar1;
        uVar1 = puVar8[5];
        puVar10[4] = puVar8[4];
        puVar10[5] = uVar1;
        uVar1 = puVar8[7];
        puVar10[6] = puVar8[6];
        puVar10[7] = uVar1;
        uVar1 = puVar8[9];
        puVar10[8] = puVar8[8];
        puVar10[9] = uVar1;
        uVar1 = puVar8[0xb];
        puVar10[10] = puVar8[10];
        puVar10[0xb] = uVar1;
        uVar1 = puVar8[0xd];
        puVar10[0xc] = puVar8[0xc];
        puVar10[0xd] = uVar1;
        uVar1 = puVar8[0xf];
        puVar10[0xe] = puVar8[0xe];
        puVar10[0xf] = uVar1;
        lVar6 = lVar6 + -1;
        puVar4 = puVar10 + 0x10;
        puVar5 = puVar8 + 0x10;
      } while (lVar6 != 0);
      uVar1 = puVar8[0x11];
      puVar10[0x10] = puVar8[0x10];
      puVar10[0x11] = uVar1;
      uVar1 = puVar8[0x13];
      puVar10[0x12] = puVar8[0x12];
      puVar10[0x13] = uVar1;
      uVar1 = puVar8[0x15];
      puVar10[0x14] = puVar8[0x14];
      puVar10[0x15] = uVar1;
      uVar1 = puVar8[0x17];
      puVar10[0x16] = puVar8[0x16];
      puVar10[0x17] = uVar1;
      puVar10[0x18] = puVar8[0x18];
    }
    else {
      memcpy(local_188,gDiskDump,0x148);
    }
    local_128 = *(undefined8 *)(lVar7 + 0x10);
    _Dst_00 = (longlong *)param_2[1];
    param_2[1] = (longlong)_Dst_00 + (ulonglong)*(uint *)(lVar7 + 0x18) + 0x28;
    memset(_Dst_00,0,0x28);
    (**(code **)(lVar7 + 0x88))(lVar7 + 0x60,local_188);
    *_Dst_00 = lVar3;
    local_198[0][0xc] = &PTR_NvRaidVolumeDefaultCleanup_00027e18;
    local_198[0][2] = _Dst_00;
  }
  else {
    local_198[0][2] = param_1;
    *param_2 = (longlong)local_198[0];
    puVar4 = NvRaidResArrayAllocate(0x2f008);
    local_198[0][0xb] = puVar4;
    if (puVar4 != (undefined8 *)0x0) {
      puVar5 = (undefined8 *)param_1[0xb];
      if ((((uint)puVar5 | (uint)puVar4) & 0xf) == 0) {
        lVar3 = 7;
        puVar10 = puVar4;
        do {
          puVar11 = puVar5;
          puVar8 = puVar10;
          uVar1 = puVar11[1];
          *puVar8 = *puVar11;
          puVar8[1] = uVar1;
          uVar1 = puVar11[3];
          puVar8[2] = puVar11[2];
          puVar8[3] = uVar1;
          uVar1 = puVar11[5];
          puVar8[4] = puVar11[4];
          puVar8[5] = uVar1;
          uVar1 = puVar11[7];
          puVar8[6] = puVar11[6];
          puVar8[7] = uVar1;
          uVar1 = puVar11[9];
          puVar8[8] = puVar11[8];
          puVar8[9] = uVar1;
          uVar1 = puVar11[0xb];
          puVar8[10] = puVar11[10];
          puVar8[0xb] = uVar1;
          uVar1 = puVar11[0xd];
          puVar8[0xc] = puVar11[0xc];
          puVar8[0xd] = uVar1;
          uVar1 = puVar11[0xf];
          puVar8[0xe] = puVar11[0xe];
          puVar8[0xf] = uVar1;
          lVar3 = lVar3 + -1;
          puVar10 = puVar8 + 0x10;
          puVar5 = puVar11 + 0x10;
        } while (lVar3 != 0);
        uVar1 = puVar11[0x11];
        puVar8[0x10] = puVar11[0x10];
        puVar8[0x11] = uVar1;
        uVar1 = puVar11[0x13];
        puVar8[0x12] = puVar11[0x12];
        puVar8[0x13] = uVar1;
        uVar1 = puVar11[0x15];
        puVar8[0x14] = puVar11[0x14];
        puVar8[0x15] = uVar1;
        puVar8[0x16] = puVar11[0x16];
      }
      else {
        memcpy(puVar4,puVar5,0x3b8);
      }
      uVar2 = 0;
      piVar9 = (int *)*DAT_00035460;
      puVar5 = DAT_00035460;
      while (piVar9 != (int *)puVar4[0x11]) {
        if (*piVar9 == 0) goto LAB_0002d5db;
        puVar5 = puVar5 + 1;
        uVar2 = uVar2 + 1;
        piVar9 = (int *)*puVar5;
      }
      puVar4[0x11] = (&gNvRaidRaidLevelMethods)[uVar2];
LAB_0002d5db:
      uVar2 = 0;
      for (puVar5 = DAT_00035460; (int *)*puVar5 != (int *)puVar4[0x12]; puVar5 = puVar5 + 1) {
        if (*(int *)*puVar5 == 0) goto LAB_0002d605;
        uVar2 = uVar2 + 1;
      }
      puVar4[0x12] = (&gNvRaidRaidLevelMethods)[uVar2];
LAB_0002d605:
      local_198[0][0xc] = puVar4[0x11] + 0x18;
      if ((puVar4[0x12] != puVar4[0x11]) && (*(char *)((longlong)puVar4 + 0x14) == '\x04')) {
        local_198[0][0xc] = &morphApi;
      }
    }
  }
  return 0;
}



===== nvrDumpDiskProcess @ 0002d76c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 nvrDumpDiskProcess(longlong param_1,longlong param_2)

{
  uint *puVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  char cVar9;
  uint uVar10;
  uint uVar11;
  longlong lVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  byte bVar15;
  ulonglong uVar16;
  undefined1 auStack_148 [32];
  longlong local_128;
  uint local_120;
  undefined *local_118;
  undefined8 *local_110;
  undefined8 local_108;
  undefined4 local_100;
  undefined8 local_f8;
  short local_f0;
  undefined2 local_ee;
  ulonglong local_d8;
  uint local_d0;
  uint local_cc;
  longlong alStack_c8 [16];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_148;
  bVar15 = 0;
  lVar3 = *(longlong *)(*(longlong *)(**(longlong **)(param_1 + 0x10) + 0x40) + 0x60);
  cVar5 = *(char *)(param_2 + 0x80);
  if (cVar5 == -1) {
LAB_0002d7bb:
    uVar8 = 0xc0000010;
  }
  else {
    if (cVar5 == -2) {
      cVar9 = *(char *)(param_2 + 0x81);
    }
    else {
      cVar9 = cVar5;
    }
    if (cVar9 == '(') {
      bVar15 = 1;
    }
    else {
      if (cVar5 == -2) {
        cVar5 = *(char *)(param_2 + 0x81);
      }
      if (cVar5 != '*') goto LAB_0002d7bb;
    }
    lVar4 = *(longlong *)(param_2 + 0xa8);
    memset(&local_f8,0,0x30);
    uVar11 = 0;
    local_128 = (ulonglong)*(uint *)(param_1 + 0x28) * *(longlong *)(param_2 + 0x88);
    if (*(short *)(lVar4 + 4) != 0) {
      local_120 = (uint)bVar15;
      do {
        uVar16 = 0;
        uVar6 = (uint)*(ushort *)(lVar4 + 6);
        lVar12 = lVar4;
        uVar10 = uVar11;
        if (*(ushort *)(lVar4 + 6) <= uVar11) {
          do {
            lVar12 = *(longlong *)(lVar12 + 8);
            uVar10 = uVar10 - uVar6;
            uVar6 = (uint)*(ushort *)(lVar12 + 6);
          } while (uVar6 <= uVar10);
        }
        uVar14 = (ulonglong)uVar10;
        local_d8 = *(ulonglong *)(lVar12 + 0x18 + uVar14 * 0x10);
        local_d0 = *(uint *)(lVar12 + 0x20 + uVar14 * 0x10);
        local_f8 = 0;
        local_ee = 0;
        uVar10 = (uint)local_d8;
        local_cc = uVar10 & 0xfff;
        local_d8 = local_d8 & 0xfffffffffffff000;
        local_f0 = ((short)((ulonglong)(uVar10 & 0xfff) + 0xfff + (ulonglong)local_d0 >> 0xc) + 6) *
                   8;
        MmBuildMdlForNonPagedPool(&local_f8);
        local_118 = gSgList;
        uVar13 = uVar16;
        uVar10 = *(uint *)(lVar12 + 0x18 + uVar14 * 0x10) & 0xfff;
        for (iVar7 = *(int *)(lVar12 + 0x20 + uVar14 * 0x10); iVar7 != 0;
            iVar7 = iVar7 - *(int *)(local_118 + lVar2 + 0x18)) {
          *(ulonglong *)(local_118 + uVar13 * 0x18 + 0x10) =
               alStack_c8[uVar13] * 0x1000 + (ulonglong)uVar10;
          if (uVar10 + iVar7 < 0x1001) {
            *(int *)(local_118 + uVar13 * 0x18 + 0x18) = iVar7;
          }
          else {
            *(uint *)(local_118 + uVar13 * 0x18 + 0x18) = 0x1000 - uVar10;
          }
          lVar2 = uVar13 * 0x18;
          uVar13 = (ulonglong)((int)uVar13 + 1);
          uVar10 = 0;
        }
        *(int *)local_118 = (int)uVar13;
        local_110 = &local_f8;
        local_108 = *(undefined8 *)(lVar12 + 0x18 + uVar14 * 0x10);
        local_100 = *(undefined4 *)(lVar12 + 0x20 + uVar14 * 0x10);
        do {
          iVar7 = (**(code **)(lVar3 + 0x98))(lVar3 + 0x60,local_120,&local_128,&local_118);
          if (iVar7 == 0) goto LAB_0002d97a;
          bVar15 = (char)uVar16 + 1;
          uVar16 = (ulonglong)bVar15;
        } while (bVar15 < 5);
        *(undefined4 *)(param_2 + 0x4b) = 0x50202;
        puVar1 = (uint *)(*(longlong *)(param_2 + 0x40) + 4);
        *puVar1 = *puVar1 | 1;
LAB_0002d97a:
        uVar11 = uVar11 + 1;
        local_128 = local_128 + (ulonglong)*(uint *)(lVar12 + 0x20 + uVar14 * 0x10);
      } while (uVar11 < *(ushort *)(lVar4 + 4));
    }
    *(undefined4 *)(param_2 + 0x50) = 0;
    NvRaidPacketCompleteRequest(param_2);
    uVar8 = 0x103;
  }
  return uVar8;
}



===== nvrDiskDumpOpen @ 0002d9d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nvrDiskDumpOpen(undefined8 param_1)

{
  undefined8 uVar1;
  
  memset(&DAT_0002f108,0,0xf0);
  _DAT_0002f128 = 0;
  _DAT_0002f1d8 = 0;
  _DAT_0002f130 = &DAT_0002f128;
  _DAT_0002f1e0 = &DAT_0002f1d8;
  _DAT_0002f0f8 = param_1;
  uVar1 = NvRaidVolumeSendCommandToVolumes(DAT_0002f100,nvrDiskDumpIterateCallBack,1);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== nvrDiskDumpWrite @ 0002da44 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nvrDiskDumpWrite(longlong *param_1,longlong param_2)

{
  undefined8 uVar1;
  undefined4 uVar2;
  
  memset(&DAT_0002f108,0,0xf0);
  uVar2 = 0;
  _DAT_0002f130 = &DAT_0002f128;
  _DAT_0002f128 = 0;
  _DAT_0002f1d8 = 0;
  _DAT_0002f1e0 = &DAT_0002f1d8;
  NvRaidScsiSetupReadWrite
            (0x2f108,*(undefined1 *)(DAT_0002f100 + 8),DAT_0002f100,&nvrDiskDumpNrpComplete,0x2a,
             (ulonglong)(*param_1 + _DAT_0002f0f8) / (ulonglong)*(uint *)(DAT_0002f100 + 0x28),
             *(uint *)(param_2 + 0x28) / *(uint *)(DAT_0002f100 + 0x28));
  _DAT_0002f1f8 = 2;
  _DAT_0002f1fc = (undefined2)uVar2;
  _DAT_0002f1b0 = &DAT_0002f1f8;
  if ((*(byte *)(param_2 + 10) & 5) == 0) {
    uVar1 = MmMapLockedPagesSpecifyCache(param_2,0,1,0,uVar2,0x20);
  }
  else {
    uVar1 = *(undefined8 *)(param_2 + 0x18);
  }
  NvRaidPacketScatterGatherElementAdd(0x2f1f8,uVar1,*(undefined4 *)(param_2 + 0x28));
  NvRaidPacketSubmitRequest(0x2f108);
  return 0;
}



===== nvrDiskDumpFinish @ 0002db6c =====

undefined8 nvrDiskDumpFinish(void)

{
  NvRaidVolumeSendCommandToVolumes(DAT_0002f100,nvrDiskDumpIterateCallBack,0);
  return 0;
}



===== nvrDiskDumpIterateCallBack @ 0002db90 =====

undefined8 nvrDiskDumpIterateCallBack(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  if (*(longlong *)(param_1 + 0x58) == 0) {
    lVar1 = *(longlong *)(*(longlong *)(**(longlong **)(param_1 + 0x10) + 0x40) + 0x60);
    if (param_2 == 1) {
      (**(code **)(lVar1 + 0x90))(lVar1 + 0x60,0,gIsCrashDump);
    }
    else {
      (**(code **)(lVar1 + 0xa0))(lVar1 + 0x60);
    }
  }
  return 0;
}



===== __security_init_cookie @ 0002dbd8 =====

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


