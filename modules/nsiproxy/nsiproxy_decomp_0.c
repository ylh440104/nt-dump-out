
===== NsippCancelChangeNotificationRoutine @ 140001010 =====

void NsippCancelChangeNotificationRoutine(undefined8 param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  bool bVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong local_48;
  longlong lStack_40;
  longlong local_38;
  longlong lStack_30;
  undefined4 local_28;
  
  bVar4 = false;
  local_28 = 0;
  local_48 = 0;
  lStack_40 = 0;
  local_38 = 0;
  lStack_30 = 0;
  KeAcquireSpinLockAtDpcLevel(&NsippNotificationHandleListLock);
  plVar6 = NsippNotificationHandleList;
  plVar7 = (longlong *)0x0;
  do {
    if ((longlong **)plVar6 == &NsippNotificationHandleList) {
LAB_140001094:
      KeReleaseSpinLockFromDpcLevel(&NsippNotificationHandleListLock);
      IoReleaseCancelSpinLock(*(undefined1 *)((longlong)param_2 + 0x45));
      IofCompleteRequest(param_2,0);
      if (bVar4) {
        local_48 = plVar7[3];
        lStack_40 = plVar7[4];
        local_38 = plVar7[5];
        lStack_30 = plVar7[6];
        NsiDeregisterChangeNotificationEx(&local_48);
        ExFreePoolWithTag(plVar7,0);
      }
      return;
    }
    plVar2 = plVar6 + 0xc;
    puVar5 = NsippFindIrp(plVar2,0,plVar6 + 0xb,param_2);
    plVar7 = plVar6;
    if (puVar5 != (undefined8 *)0x0) {
      if (((longlong *)*plVar2 == plVar2) && ((int)plVar6[2] == 0)) {
        lVar1 = *plVar6;
        if ((*(longlong **)(lVar1 + 8) != plVar6) ||
           (plVar2 = (longlong *)plVar6[1], (longlong *)*plVar2 != plVar6)) {
          pcVar3 = (code *)swi(0x29);
          (*pcVar3)(3);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        *plVar2 = lVar1;
        bVar4 = true;
        *(longlong **)(lVar1 + 8) = plVar2;
      }
      goto LAB_140001094;
    }
    plVar6 = (longlong *)*plVar6;
  } while( true );
}



===== NsippCleanup @ 140001170 =====

undefined8 NsippCleanup(undefined8 param_1,longlong param_2)

{
  longlong ****pppplVar1;
  longlong ***ppplVar2;
  longlong ***ppplVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  longlong ****local_98;
  longlong ****local_90;
  longlong ***local_88;
  longlong ***ppplStack_80;
  longlong ***local_78;
  longlong ***ppplStack_70;
  undefined4 local_68;
  undefined8 local_58;
  longlong ***ppplStack_50;
  longlong ***local_48;
  longlong ***ppplStack_40;
  undefined8 local_38;
  longlong ***ppplStack_30;
  longlong ***local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = 0;
  local_68 = 0;
  local_90 = (longlong ****)&local_98;
  local_98 = (longlong ****)&local_98;
  local_58 = 0;
  ppplStack_50 = (longlong ***)0x0;
  local_48 = (longlong ***)0x0;
  ppplStack_40 = (longlong ***)0x0;
  local_38 = 0;
  ppplStack_30 = (longlong ***)0x0;
  local_28 = (longlong ***)0x0;
  uStack_20 = 0;
  local_88 = (longlong ***)0x0;
  ppplStack_80 = (longlong ***)0x0;
  local_78 = (longlong ***)0x0;
  ppplStack_70 = (longlong ***)0x0;
  pppplVar1 = *(longlong *****)(*(longlong *)(param_2 + 0x30) + 0x18);
  uVar5 = KeAcquireSpinLockRaiseToDpc(pppplVar1 + 3);
  *(undefined1 *)(pppplVar1 + 2) = 1;
  local_98 = (longlong ****)*pppplVar1;
  if (local_98 == pppplVar1) {
    local_90 = (longlong ****)&local_98;
    local_98 = (longlong ****)&local_98;
  }
  else {
    local_90 = (longlong ****)pppplVar1[1];
    local_98[1] = (longlong ***)&local_98;
    *local_90 = (longlong ***)&local_98;
    pppplVar1[1] = (longlong ***)pppplVar1;
    *pppplVar1 = (longlong ***)pppplVar1;
  }
  KeReleaseSpinLock(pppplVar1 + 3,uVar5);
  while( true ) {
    do {
      while( true ) {
        pppplVar1 = local_98;
        if ((longlong *****)local_98 == &local_98) {
          return 0;
        }
        if (*(int *)(local_98 + 2) != 0) break;
        local_88 = local_98[3];
        ppplStack_80 = local_98[4];
        local_78 = local_98[5];
        ppplStack_70 = local_98[6];
        NsiDeregisterChangeNotificationEx(&local_88);
        ppplVar2 = *pppplVar1;
        if (((longlong ****)ppplVar2[1] != pppplVar1) ||
           (ppplVar3 = pppplVar1[1], (longlong ****)*ppplVar3 != pppplVar1)) goto LAB_140001345;
        *ppplVar3 = (longlong **)ppplVar2;
        ppplVar2[1] = (longlong **)ppplVar3;
        ExFreePoolWithTag(pppplVar1,0);
      }
    } while (*(int *)(local_98 + 2) != 1);
    ppplStack_30 = local_98[6];
    local_28 = local_98[7];
    ppplStack_50 = local_98[3];
    local_48 = local_98[4];
    ppplStack_40 = local_98[5];
    local_38 = 0x700000001;
    local_58 = 0;
    uStack_20 = 0;
    local_18 = local_18 & 0xffffffff00000000;
    NsiSetAllParametersEx(&local_58);
    ppplVar2 = *pppplVar1;
    if (((longlong ****)ppplVar2[1] != pppplVar1) ||
       (ppplVar3 = pppplVar1[1], (longlong ****)*ppplVar3 != pppplVar1)) break;
    *ppplVar3 = (longlong **)ppplVar2;
    ppplVar2[1] = (longlong **)ppplVar3;
    ExFreePoolWithTag(pppplVar1);
  }
LAB_140001345:
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  uVar6 = (*pcVar4)();
  return uVar6;
}



===== NsippFindNotificationHandle @ 140001360 =====

undefined8 * NsippFindNotificationHandle(int *param_1,int param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  puVar2 = NsippNotificationHandleList;
  while( true ) {
    if ((undefined8 **)puVar2 == &NsippNotificationHandleList) {
      return (undefined8 *)0x0;
    }
    if ((*(int *)(puVar2 + 10) == param_2) &&
       (uVar1 = NsippIsMatchingObject((int *)(puVar2 + 3),param_1), (char)uVar1 != '\0')) break;
    puVar2 = (undefined8 *)*puVar2;
  }
  return puVar2;
}



===== NsippIsMatchingObject @ 1400013d0 =====

ulonglong NsippIsMatchingObject(int *param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  longlong *plVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong *local_18;
  undefined8 local_10;
  
  uVar5 = (ulonglong)(uint)param_2[4];
  local_10 = 0;
  if (param_1[4] == param_2[4]) {
    uVar1 = *param_1;
    if (uVar1 != 0) {
      uVar2 = *param_2;
      uVar5 = (ulonglong)uVar2;
      if (uVar2 != 0) {
        if (uVar1 != uVar2) goto LAB_140001436;
        goto LAB_14000145a;
      }
    }
    plVar3 = *(longlong **)(param_1 + 2);
    local_18 = *(longlong **)(param_2 + 2);
    if (plVar3 == (longlong *)0x0) {
      if (local_18 == (longlong *)0x0) goto LAB_140001436;
    }
    else {
      if (local_18 != (longlong *)0x0) {
        uVar4 = *plVar3 - *local_18;
        if ((uVar4 == 0) && (uVar4 = plVar3[1] - local_18[1], uVar4 == 0)) {
          uVar4 = plVar3[2] - local_18[2];
        }
        uVar5 = 0;
        if (uVar4 != 0) {
          return uVar4 & 0xffffffffffffff00;
        }
        goto LAB_14000145a;
      }
      uVar1 = *param_2;
      local_18 = plVar3;
    }
    if (((uVar1 != 0) && (uVar5 = NsiGetModuleHandle(&local_18), -1 < (int)uVar5)) &&
       (uVar1 == (uint)local_10)) {
LAB_14000145a:
      return CONCAT71((int7)(uVar5 >> 8),1);
    }
  }
LAB_140001436:
  return uVar5 & 0xffffffffffffff00;
}



===== NsippCancelChangeNotification @ 140001490 =====

ulonglong NsippCancelChangeNotification(ulonglong *param_1,uint param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  uint uVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  longlong *plVar10;
  longlong *plVar11;
  ulonglong uVar12;
  undefined1 local_res18 [8];
  longlong local_58;
  longlong lStack_50;
  longlong local_48;
  longlong lStack_40;
  undefined4 local_38;
  
  uVar9 = 0;
  puVar8 = (undefined8 *)0x0;
  local_38 = 0;
  local_res18[0] = 0;
  bVar5 = false;
  bVar4 = false;
  local_58 = 0;
  lStack_50 = 0;
  local_48 = 0;
  lStack_40 = 0;
  cVar6 = IoIs32bitProcess(0);
  if (param_1 == (ulonglong *)0x0) {
LAB_140001602:
    uVar9 = 0xc000000d;
  }
  else {
    if (cVar6 == '\0') {
      if (param_2 < 8) goto LAB_140001602;
      uVar12 = *param_1;
    }
    else {
      if (param_2 < 4) goto LAB_140001602;
      uVar12 = (ulonglong)(uint)*param_1;
    }
    IoAcquireCancelSpinLock(local_res18);
    KeAcquireSpinLockAtDpcLevel(&NsippNotificationHandleListLock);
    plVar10 = NsippNotificationHandleList;
    plVar11 = (longlong *)0x0;
    while( true ) {
      if ((longlong **)plVar10 == &NsippNotificationHandleList) break;
      plVar2 = plVar10 + 0xc;
      puVar8 = NsippFindIrp(plVar2,uVar12,plVar10 + 0xb,(undefined8 *)0x0);
      plVar11 = plVar10;
      if (puVar8 != (undefined8 *)0x0) {
        if ((longlong *)*plVar2 == plVar2) {
          if ((int)plVar10[2] != 0) break;
          lVar1 = *plVar10;
          if ((*(longlong **)(lVar1 + 8) != plVar10) ||
             (plVar2 = (longlong *)plVar10[1], (longlong *)*plVar2 != plVar10)) {
            pcVar3 = (code *)swi(0x29);
            (*pcVar3)(3);
            pcVar3 = (code *)swi(3);
            uVar9 = (*pcVar3)();
            return uVar9;
          }
          *plVar2 = lVar1;
          bVar5 = true;
          *(longlong **)(lVar1 + 8) = plVar2;
        }
        KeReleaseSpinLockFromDpcLevel(&NsippNotificationHandleListLock);
        IoReleaseCancelSpinLock(local_res18[0]);
        goto LAB_1400015bf;
      }
      plVar10 = (longlong *)*plVar10;
    }
    KeReleaseSpinLockFromDpcLevel(&NsippNotificationHandleListLock);
    IoReleaseCancelSpinLock(local_res18[0]);
    bVar5 = false;
    if (puVar8 == (undefined8 *)0x0) {
      uVar9 = 0xc0000225;
    }
    else {
LAB_1400015bf:
      bVar4 = bVar5;
      IofCompleteRequest(puVar8,0);
    }
    if (bVar4) {
      local_58 = plVar11[3];
      lStack_50 = plVar11[4];
      local_48 = plVar11[5];
      lStack_40 = plVar11[6];
      uVar7 = NsiDeregisterChangeNotificationEx(&local_58);
      uVar9 = (ulonglong)uVar7;
      ExFreePoolWithTag(plVar11,0);
    }
  }
  return uVar9;
}



===== NsippFindIrp @ 1400016a0 =====

undefined8 *
NsippFindIrp(undefined8 *param_1,longlong param_2,undefined8 param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  puVar5 = (undefined8 *)0x0;
  uVar4 = KeAcquireSpinLockRaiseToDpc(param_3);
  puVar6 = (undefined8 *)*param_1;
  do {
    if (puVar6 == param_1) {
LAB_140001733:
      KeReleaseSpinLock(param_3);
      if (puVar6 == param_1) {
        puVar5 = (undefined8 *)0x0;
      }
LAB_14000175d:
      return puVar5;
    }
    puVar5 = puVar6 + -0x15;
    if (((param_2 != 0) && (puVar6[-9] == param_2)) ||
       ((param_4 != (undefined8 *)0x0 && (param_4 == puVar5)))) {
      *(undefined4 *)(puVar6 + -0xf) = 0xc0000120;
      puVar6[-0xe] = 0;
      LOCK();
      puVar6[-8] = 0;
      UNLOCK();
      puVar1 = (undefined8 *)*puVar6;
      if (((undefined8 *)puVar1[1] != puVar6) ||
         (puVar2 = (undefined8 *)puVar6[1], (undefined8 *)*puVar2 != puVar6)) {
        pcVar3 = (code *)swi(0x29);
        (*pcVar3)(3,uVar4);
        pcVar3 = (code *)swi(3);
        puVar5 = (undefined8 *)(*pcVar3)();
        return puVar5;
      }
      *puVar2 = puVar1;
      puVar1[1] = puVar2;
      if (puVar2 != puVar1) {
        KeReleaseSpinLock(param_3);
        goto LAB_14000175d;
      }
      goto LAB_140001733;
    }
    puVar6 = (undefined8 *)*puVar6;
  } while( true );
}



===== NsippSetAllParameters @ 1400017a0 =====

ulonglong NsippSetAllParameters(longlong *param_1,uint param_2,char param_3,longlong param_4)

{
  ulonglong uVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  char cVar9;
  undefined1 uVar10;
  uint uVar11;
  int iVar12;
  longlong *plVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong local_d8;
  longlong local_d0;
  longlong local_c8;
  undefined8 local_c0;
  longlong local_b8;
  undefined8 uStack_b0;
  ulonglong local_a8;
  undefined8 uStack_a0;
  longlong local_98;
  ulonglong uStack_90;
  undefined8 local_88;
  ulonglong uStack_80;
  undefined8 local_78;
  undefined8 local_68;
  ulonglong uStack_60;
  longlong *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  plVar13 = (longlong *)0x0;
  local_d8 = 0;
  plVar17 = (longlong *)0x0;
  local_68 = 0;
  uStack_60 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_d0 = 0;
  local_c0 = 0;
  local_c8 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  cVar9 = IoIs32bitProcess(0);
  if (param_1 == (longlong *)0x0) {
    return 0xc000000d;
  }
  if (cVar9 == '\0') {
    if (param_2 < 0x48) {
      return 0xc000000d;
    }
  }
  else {
    if (param_2 < 0x28) {
      return 0xc000000d;
    }
    NsippProbeForRead((longlong)param_1,(ulonglong)param_2);
    uStack_90 = (ulonglong)*(uint *)(param_1 + 3);
    local_88 = CONCAT44(local_88._4_4_,*(undefined4 *)((longlong)param_1 + 0x1c));
    local_a8 = (ulonglong)*(uint *)(param_1 + 1);
    uStack_b0 = CONCAT44(uStack_b0._4_4_,*(undefined4 *)((longlong)param_1 + 4));
    uStack_a0 = CONCAT44(uStack_a0._4_4_,*(undefined4 *)((longlong)param_1 + 0xc));
    uStack_80 = (ulonglong)*(uint *)(param_1 + 4);
    local_78 = CONCAT44(local_78._4_4_,*(undefined4 *)((longlong)param_1 + 0x24));
    local_98 = param_1[2];
    local_b8 = (longlong)(int)*param_1;
    param_1 = &local_b8;
    local_58 = param_1;
  }
  plVar2 = *(longlong **)(*(longlong *)(param_4 + 0x30) + 0x18);
  uVar11 = NsippProbeAndAllocateParameters
                     (param_1,0x48,(longlong)(param_1 + 1),(undefined4 *)(param_1 + 5),0,
                      (undefined4 *)0x0,param_1 + 7,(undefined8 *)0x0,param_3,1,'\x01',&local_68,
                      &local_d0,(undefined8 *)0x0,(uint *)0x0,(undefined8 *)0x0,&local_50,&local_c0,
                      (undefined8 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,
                      (undefined8 *)0x0,&local_c8,&local_d8);
  lVar7 = local_c8;
  lVar3 = local_d0;
  lVar8 = local_d8;
  if ((int)uVar11 < 0) goto LAB_140001a91;
  *(longlong *)(local_d8 + 0x28) = local_d0;
  uVar15 = uStack_60 & 0xffffffff;
  *(undefined4 *)(local_d8 + 0x30) = (undefined4)uStack_60;
  *(longlong *)(local_d8 + 0x10) = local_c8;
  *(undefined8 *)(local_d8 + 0x38) = local_c0;
  *(undefined4 *)(local_d8 + 0x40) = (undefined4)uStack_48;
  if (*(int *)(local_d8 + 0x24) == 6) {
    uVar1 = uVar15 + 0x70;
    if (0xffffffff < uVar1) {
      uVar11 = 0xc000000d;
      goto LAB_140001a91;
    }
    plVar13 = (longlong *)ExAllocatePool2(0x41,uVar1 & 0xffffffff,0x6370534e);
    if (plVar13 == (longlong *)0x0) {
      uVar11 = 0xc000009a;
      goto LAB_140001a91;
    }
    *(undefined4 *)(plVar13 + 2) = 1;
    lVar6 = *(longlong *)(lVar8 + 0x30);
    plVar13[6] = *(longlong *)(lVar8 + 0x28);
    plVar13[7] = lVar6;
    lVar6 = *(longlong *)(lVar8 + 0x10);
    plVar13[3] = *(longlong *)(lVar8 + 8);
    plVar13[4] = lVar6;
    plVar13[5] = *(longlong *)(lVar8 + 0x18);
    if (lVar7 != 0) {
      plVar16 = *(longlong **)(lVar8 + 0x10);
      lVar7 = plVar16[1];
      plVar13[8] = *plVar16;
      plVar13[9] = lVar7;
      plVar13[10] = plVar16[2];
      plVar13[4] = (longlong)(plVar13 + 8);
    }
    if (lVar3 != 0) {
      plVar13[6] = (longlong)(plVar13 + 0xb);
      memmove(plVar13 + 0xb,*(void **)(lVar8 + 0x28),uVar15);
    }
  }
  if (*(int *)(lVar8 + 0x24) == 7) {
    uVar10 = KeAcquireSpinLockRaiseToDpc(plVar2 + 3);
    for (plVar16 = (longlong *)*plVar2; plVar16 != plVar2; plVar16 = (longlong *)*plVar16) {
      if (((((int)plVar16[2] == 1) &&
           (plVar17 = plVar16, *(uint *)(plVar16 + 7) == *(uint *)(lVar8 + 0x30))) &&
          (iVar12 = memcmp((void *)plVar16[6],*(void **)(lVar8 + 0x28),
                           (ulonglong)*(uint *)(plVar16 + 7)), iVar12 == 0)) &&
         (uVar14 = NsippIsMatchingObject((int *)(plVar16 + 3),(int *)(lVar8 + 8)),
         (char)uVar14 != '\0')) {
        lVar3 = *plVar16;
        plVar4 = (longlong *)plVar16[1];
        if ((*(longlong **)(lVar3 + 8) != plVar16) || ((longlong *)*plVar4 != plVar16))
        goto LAB_140001c7e;
        *plVar4 = lVar3;
        *(longlong **)(lVar3 + 8) = plVar4;
        break;
      }
    }
    KeReleaseSpinLock(plVar2 + 3,uVar10);
    if (plVar16 == plVar2) {
      uVar11 = 0xc000000d;
      goto LAB_140001a91;
    }
  }
  uVar11 = NsiSetAllParametersEx(lVar8);
  if ((-1 < (int)uVar11) && (plVar13 != (longlong *)0x0)) {
    uVar10 = KeAcquireSpinLockRaiseToDpc(plVar2 + 3);
    if ((char)plVar2[2] != '\0') {
      KeReleaseSpinLock(plVar2 + 3,uVar10);
      *(undefined4 *)(lVar8 + 0x24) = 7;
      NsiSetAllParametersEx(lVar8);
      uVar11 = 0xc0000056;
      goto LAB_140001a91;
    }
    plVar16 = (longlong *)plVar2[1];
    if ((longlong *)*plVar16 != plVar2) {
LAB_140001c7e:
      pcVar5 = (code *)swi(0x29);
      (*pcVar5)(3);
      pcVar5 = (code *)swi(3);
      uVar15 = (*pcVar5)();
      return uVar15;
    }
    *plVar13 = (longlong)plVar2;
    plVar13[1] = (longlong)plVar16;
    *plVar16 = (longlong)plVar13;
    plVar2[1] = (longlong)plVar13;
    KeReleaseSpinLock(plVar2 + 3,uVar10);
  }
  if (*(int *)(lVar8 + 0x24) == 7) {
    ExFreePoolWithTag(plVar17,0);
  }
LAB_140001a91:
  if (lVar8 != 0) {
    ExFreePoolWithTag(lVar8,0);
  }
  if (((int)uVar11 < 0) && (plVar13 != (longlong *)0x0)) {
    ExFreePoolWithTag(plVar13,0);
  }
  return (ulonglong)uVar11;
}



===== NsippRequestChangeNotification @ 140001c90 =====

int NsippRequestChangeNotification(longlong param_1,undefined8 *param_2,uint param_3,char param_4)

{
  byte *pbVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined8 uVar4;
  int *piVar5;
  char cVar6;
  undefined1 uVar7;
  int iVar8;
  uint uVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  undefined1 *puVar12;
  undefined8 *puVar13;
  int *piVar14;
  undefined1 local_res8 [8];
  undefined1 auStackY_1b8 [8];
  undefined1 auStackY_1b0 [24];
  int *local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  code *pcStack_c0;
  undefined8 local_b8;
  undefined8 *puStack_b0;
  longlong local_a8;
  undefined8 uStack_a0;
  undefined8 *local_98;
  undefined8 *local_88;
  undefined8 local_80;
  ulonglong uStack_78;
  undefined8 local_70;
  ulonglong uStack_68;
  ulonglong local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined4 local_38;
  
  local_res8[0] = 0;
  local_e8 = (int *)0x0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_c8 = 0;
  pcStack_c0 = (code *)0x0;
  local_b8 = 0;
  puStack_b0 = (undefined8 *)0x0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = (undefined8 *)((ulonglong)local_98 & 0xffffffff00000000);
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  puVar11 = (undefined8 *)0x0;
  local_e0 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = local_60 & 0xffffffff00000000;
  *(undefined8 *)(param_1 + 0x38) = 0;
  cVar6 = IoIs32bitProcess(0);
  if (param_2 == (undefined8 *)0x0) {
    return -0x3ffffff3;
  }
  if (cVar6 == '\0') {
    if (param_3 < 0x28) {
      return -0x3ffffff3;
    }
    local_88 = param_2;
  }
  else {
    if (param_3 < 0x14) {
      return -0x3ffffff3;
    }
    NsippProbeForRead((longlong)param_2,(ulonglong)param_3);
    uStack_78 = (ulonglong)*(uint *)((longlong)param_2 + 4);
    local_80 = CONCAT44(local_80._4_4_,*(undefined4 *)param_2);
    local_70 = CONCAT44(local_70._4_4_,*(undefined4 *)(param_2 + 1));
    local_60 = (ulonglong)*(uint *)(param_2 + 2);
    uStack_68 = (ulonglong)*(uint *)((longlong)param_2 + 0xc);
    local_88 = &local_80;
  }
  iVar8 = NsippProbeAndAllocateParameters
                    (local_88,0x28,(longlong)local_88,(undefined4 *)0x0,0,(undefined4 *)0x0,
                     (undefined8 *)0x0,(undefined8 *)0x0,param_4,1,'\0',(undefined8 *)0x0,
                     (undefined8 *)0x0,(undefined8 *)0x0,(uint *)0x0,(undefined8 *)0x0,
                     (undefined8 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,
                     (undefined8 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,&local_e0,&local_e8);
  piVar5 = local_e8;
  puVar12 = auStackY_1b8;
  if (iVar8 < 0) {
    piVar14 = local_e8;
    goto LAB_140001f95;
  }
  *(undefined8 *)(local_e8 + 2) = local_e0;
  uVar9 = NdisGetThreadObjectCompartmentId(SystemReserved1[0xf]);
  uVar7 = KeAcquireSpinLockRaiseToDpc(&NsippNotificationHandleListLock);
  piVar14 = local_e8;
  puVar10 = NsippFindNotificationHandle(local_e8,uVar9);
  if (puVar10 != (undefined8 *)0x0) {
    *(int *)(puVar10 + 2) = *(int *)(puVar10 + 2) + 1;
  }
  KeReleaseSpinLock(&NsippNotificationHandleListLock,uVar7);
  if (puVar10 != (undefined8 *)0x0) goto LAB_140001ed1;
  puVar11 = (undefined8 *)ExAllocatePool2(0x41,0x78,0x6370534e);
  puVar12 = auStackY_1b8;
  if (puVar11 != (undefined8 *)0x0) {
    puVar10 = puVar11 + 0xc;
    puVar11[0xd] = puVar10;
    *puVar10 = puVar10;
    KeInitializeSpinLock(puVar11 + 0xb);
    *(int *)(puVar11 + 3) = *piVar14;
    *(int *)(puVar11 + 5) = piVar14[4];
    puVar11[4] = puVar11 + 7;
    puVar10 = *(undefined8 **)(piVar5 + 2);
    uVar4 = puVar10[1];
    puVar11[7] = *puVar10;
    puVar11[8] = uVar4;
    puVar11[9] = puVar10[2];
    *(uint *)(puVar11 + 10) = uVar9;
    puVar2 = puVar11 + 6;
    *puVar2 = 0;
    uStack_a0 = 0;
    local_d8 = *(undefined8 *)piVar14;
    uStack_d0 = *(undefined8 *)(piVar14 + 2);
    local_c8 = *(undefined8 *)(piVar14 + 4);
    pcStack_c0 = NsippChangeNotificationCallback;
    local_b8 = 0;
    local_a8 = (ulonglong)uVar9 << 0x20;
    puStack_b0 = puVar11;
    local_98 = puVar2;
    iVar8 = NsiRegisterChangeNotificationEx(&local_d8);
    puVar12 = auStackY_1b8;
    if (iVar8 < 0) goto LAB_140001f95;
    uVar7 = KeAcquireSpinLockRaiseToDpc(&NsippNotificationHandleListLock);
    puVar10 = NsippFindNotificationHandle(piVar14,uVar9);
    if (puVar10 != (undefined8 *)0x0) {
      *(int *)(puVar10 + 2) = *(int *)(puVar10 + 2) + 1;
      KeReleaseSpinLock(&NsippNotificationHandleListLock,uVar7);
      local_58 = *(undefined8 *)piVar14;
      uStack_50 = *(undefined8 *)(piVar14 + 2);
      local_48 = *(undefined8 *)(piVar14 + 4);
      uStack_40 = *puVar2;
      NsiDeregisterChangeNotificationEx(&local_58);
      ExFreePoolWithTag(puVar11,0);
LAB_140001ed1:
      puVar12 = auStackY_1b8;
      IoAcquireCancelSpinLock(local_res8);
      KeAcquireSpinLockAtDpcLevel(&NsippNotificationHandleListLock);
      KeAcquireSpinLockAtDpcLevel(puVar10 + 0xb);
      if (*(char *)(param_1 + 0x44) == '\0') {
        pbVar1 = (byte *)(*(longlong *)(param_1 + 0xb8) + 3);
        *pbVar1 = *pbVar1 | 1;
        LOCK();
        *(code **)(param_1 + 0x68) = NsippCancelChangeNotificationRoutine;
        UNLOCK();
        puVar13 = (undefined8 *)(param_1 + 0xa8);
        puVar2 = (undefined8 *)puVar10[0xd];
        if ((undefined8 *)*puVar2 != puVar10 + 0xc) goto LAB_1400021fa;
        *puVar13 = puVar10 + 0xc;
        *(undefined8 **)(param_1 + 0xb0) = puVar2;
        *puVar2 = puVar13;
        puVar10[0xd] = puVar13;
        iVar8 = 0x103;
        piVar14 = local_e8;
      }
      else {
        iVar8 = -0x3ffffee0;
      }
      *(int *)(puVar10 + 2) = *(int *)(puVar10 + 2) + -1;
      KeReleaseSpinLockFromDpcLevel(puVar10 + 0xb);
      KeReleaseSpinLockFromDpcLevel(&NsippNotificationHandleListLock);
      IoReleaseCancelSpinLock(local_res8[0]);
      goto LAB_140001f95;
    }
    if ((undefined8 *)*DAT_14000a2a8 == &NsippNotificationHandleList) {
      *puVar11 = &NsippNotificationHandleList;
      puVar11[1] = DAT_14000a2a8;
      *DAT_14000a2a8 = puVar11;
      DAT_14000a2a8 = puVar11;
      *(int *)(puVar11 + 2) = *(int *)(puVar11 + 2) + 1;
      KeReleaseSpinLock(&NsippNotificationHandleListLock,uVar7);
      puVar10 = puVar11;
      goto LAB_140001ed1;
    }
LAB_1400021fa:
    pcVar3 = (code *)swi(0x29);
    (*pcVar3)(3);
    puVar12 = auStackY_1b0;
  }
  iVar8 = -0x3fffff66;
LAB_140001f95:
  if (piVar14 != (int *)0x0) {
    *(undefined8 *)(puVar12 + -8) = 0x140001fa6;
    ExFreePoolWithTag(piVar14,0);
  }
  if (((iVar8 != 0x103) && (iVar8 != -0x3ffffee0)) && (puVar11 != (undefined8 *)0x0)) {
    *(undefined8 *)(puVar12 + -8) = 0x140002236;
    ExFreePoolWithTag(puVar11,0);
  }
  return iVar8;
}



===== NsippSetParameter @ 140002250 =====

int NsippSetParameter(longlong *param_1,uint param_2,char param_3)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  uint local_res20 [2];
  longlong local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  longlong local_78;
  undefined8 uStack_70;
  ulonglong local_68;
  undefined8 uStack_60;
  longlong local_58;
  ulonglong uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  longlong lStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  longlong *local_18;
  undefined8 local_10;
  
  local_98 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_res20[0] = 0;
  local_90 = 0;
  local_80 = 0;
  local_88 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  lStack_30 = 0;
  cVar2 = IoIs32bitProcess(0);
  if (param_1 == (longlong *)0x0) {
LAB_1400024e4:
    iVar3 = -0x3ffffff3;
  }
  else {
    if (cVar2 == '\0') {
      if (param_2 < 0x50) goto LAB_1400024e4;
    }
    else {
      if (param_2 < 0x30) goto LAB_1400024e4;
      NsippProbeForRead((longlong)param_1,(ulonglong)param_2);
      uStack_50 = (ulonglong)*(uint *)(param_1 + 3);
      local_48 = CONCAT44(local_48._4_4_,*(undefined4 *)((longlong)param_1 + 0x1c));
      local_68 = (ulonglong)*(uint *)(param_1 + 1);
      uStack_70 = CONCAT44(uStack_70._4_4_,*(undefined4 *)((longlong)param_1 + 4));
      uStack_60 = CONCAT44(uStack_60._4_4_,*(undefined4 *)((longlong)param_1 + 0xc));
      local_38 = (ulonglong)*(uint *)((longlong)param_1 + 0x24);
      lStack_30 = param_1[5];
      uStack_40 = CONCAT44(uStack_40._4_4_,(int)param_1[4]);
      local_58 = param_1[2];
      local_78 = (longlong)(int)*param_1;
      param_1 = &local_78;
      local_18 = param_1;
    }
    iVar3 = NsippProbeAndAllocateParameters
                      (param_1,0x50,(longlong)(param_1 + 1),(undefined4 *)(param_1 + 5),
                       (longlong)(param_1 + 7),(undefined4 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0
                       ,param_3,1,'\x01',&local_28,&local_90,&local_10,local_res20,&local_80,
                       (undefined8 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,
                       (undefined8 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,&local_88,&local_98);
    lVar1 = local_98;
    if (-1 < iVar3) {
      *(undefined8 *)(local_98 + 0x28) = local_90;
      *(undefined4 *)(local_98 + 0x30) = (undefined4)uStack_20;
      *(undefined8 *)(local_98 + 0x10) = local_88;
      *(undefined8 *)(local_98 + 0x40) = local_80;
      *(uint *)(local_98 + 0x48) = local_res20[0];
      iVar3 = NsiSetParameterEx(local_98);
    }
    if (lVar1 != 0) {
      ExFreePoolWithTag(lVar1,0);
    }
  }
  return iVar3;
}



===== NsippDeregisterChangeNotification @ 140002500 =====

ulonglong NsippDeregisterChangeNotification
                    (undefined8 *param_1,uint param_2,char param_3,longlong param_4)

{
  int iVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  code *pcVar5;
  int *piVar6;
  char cVar7;
  undefined1 uVar8;
  uint uVar9;
  int iVar10;
  ulonglong uVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  int *local_68;
  longlong *local_60;
  undefined8 uStack_58;
  undefined8 *local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  longlong lStack_30;
  undefined4 local_28;
  
  local_68 = (int *)0x0;
  local_60 = (longlong *)0x0;
  plVar14 = (longlong *)0x0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  lStack_30 = 0;
  local_28 = 0;
  cVar7 = IoIs32bitProcess(0);
  if (param_1 == (undefined8 *)0x0) {
LAB_1400027eb:
    uVar11 = 0xc000000d;
  }
  else {
    if (cVar7 == '\0') {
      if (param_2 < 0x28) goto LAB_1400027eb;
    }
    else {
      if (param_2 < 0x20) goto LAB_1400027eb;
      NsippProbeForRead((longlong)param_1,(ulonglong)param_2);
      uStack_40 = param_1[1];
      local_48 = CONCAT44(local_48._4_4_,*(undefined4 *)param_1);
      local_38 = CONCAT44(local_38._4_4_,*(undefined4 *)(param_1 + 2));
      lStack_30 = (longlong)*(int *)(param_1 + 3);
      param_1 = &local_48;
      local_50 = param_1;
    }
    uVar9 = NsippProbeAndAllocateParameters
                      (param_1,0x28,(longlong)param_1,(undefined4 *)0x0,0,(undefined4 *)0x0,
                       (undefined8 *)0x0,(undefined8 *)0x0,param_3,1,'\0',(undefined8 *)0x0,
                       (undefined8 *)0x0,(undefined8 *)0x0,(uint *)0x0,(undefined8 *)0x0,
                       (undefined8 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,
                       (undefined8 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,&local_60,&local_68);
    piVar6 = local_68;
    if (-1 < (int)uVar9) {
      *(longlong **)(local_68 + 2) = local_60;
      plVar2 = *(longlong **)(*(longlong *)(param_4 + 0x30) + 0x18);
      uVar8 = KeAcquireSpinLockRaiseToDpc(plVar2 + 3);
      for (plVar13 = (longlong *)*plVar2; plVar13 != plVar2; plVar13 = (longlong *)*plVar13) {
        if ((int)plVar13[2] == 0) {
          local_60 = (longlong *)0x0;
          uStack_58 = 0;
          plVar14 = plVar13;
          if ((int)plVar13[5] == piVar6[4]) {
            iVar1 = (int)plVar13[3];
            if ((iVar1 == 0) || (*piVar6 == 0)) {
              plVar3 = (longlong *)plVar13[4];
              if (plVar3 == (longlong *)0x0) {
LAB_1400027fc:
                plVar3 = *(longlong **)(piVar6 + 2);
                if (*(longlong **)(piVar6 + 2) == (longlong *)0x0) goto LAB_14000266f;
              }
              else {
                plVar4 = *(longlong **)(piVar6 + 2);
                if (plVar4 != (longlong *)0x0) {
                  lVar12 = *plVar3 - *plVar4;
                  if ((lVar12 == 0) && (lVar12 = plVar3[1] - plVar4[1], lVar12 == 0)) {
                    lVar12 = plVar3[2] - plVar4[2];
                  }
                  if (lVar12 == 0) goto LAB_1400026cf;
                  goto LAB_14000266f;
                }
                if (plVar3 == (longlong *)0x0) goto LAB_1400027fc;
                iVar1 = *piVar6;
              }
              local_60 = plVar3;
              if (((iVar1 != 0) && (iVar10 = NsiGetModuleHandle(&local_60), -1 < iVar10)) &&
                 (iVar1 == (int)uStack_58)) goto LAB_1400026cf;
            }
            else if (iVar1 == *piVar6) {
LAB_1400026cf:
              if (((param_3 == '\0') && (plVar13[6] == *(longlong *)(piVar6 + 6))) ||
                 ((param_3 == '\x01' && (plVar13 == *(longlong **)(piVar6 + 6))))) {
                lVar12 = *plVar13;
                plVar3 = (longlong *)plVar13[1];
                if ((*(longlong **)(lVar12 + 8) != plVar13) || ((longlong *)*plVar3 != plVar13)) {
                  pcVar5 = (code *)swi(0x29);
                  (*pcVar5)(3);
                  pcVar5 = (code *)swi(3);
                  uVar11 = (*pcVar5)();
                  return uVar11;
                }
                *plVar3 = lVar12;
                *(longlong **)(lVar12 + 8) = plVar3;
                break;
              }
            }
          }
        }
LAB_14000266f:
      }
      KeReleaseSpinLock(plVar2 + 3,uVar8);
      if (plVar13 == plVar2) {
        uVar9 = 0xc000000d;
      }
      else {
        if (param_3 == '\x01') {
          piVar6[6] = 0;
          piVar6[7] = 0;
        }
        uVar9 = NsiDeregisterChangeNotificationEx(piVar6);
        ExFreePoolWithTag(plVar14,0);
      }
    }
    if (piVar6 != (int *)0x0) {
      ExFreePoolWithTag(piVar6,0);
    }
    uVar11 = (ulonglong)uVar9;
  }
  return uVar11;
}



===== NsippDispatch @ 140002890 =====

ulonglong NsippDispatch(undefined8 param_1,longlong param_2)

{
  undefined8 *puVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  longlong *plVar5;
  uint uVar6;
  uint uVar7;
  uint extraout_EAX;
  longlong lVar8;
  ulonglong uVar9;
  
  pcVar4 = *(char **)(param_2 + 0xb8);
  cVar2 = *pcVar4;
  if (cVar2 != '\x0f') {
    if (cVar2 == '\0') {
      lVar8 = ExAllocatePool2(0x41,0x20,0x6370534e);
      if (lVar8 == 0) {
        uVar9 = 0xc000009a;
      }
      else {
        *(longlong *)(lVar8 + 8) = lVar8;
        *(longlong *)lVar8 = lVar8;
        KeInitializeSpinLock(lVar8 + 0x18);
        *(undefined1 *)(lVar8 + 0x10) = 0;
        *(longlong *)(*(longlong *)(pcVar4 + 0x30) + 0x18) = lVar8;
        uVar9 = 0;
      }
      goto LAB_140002930;
    }
    if (cVar2 == '\x02') {
      ExFreePoolWithTag(*(undefined8 *)(*(longlong *)(pcVar4 + 0x30) + 0x18),0);
      uVar9 = 0;
      goto LAB_140002930;
    }
    if (cVar2 != '\x12') {
      if (cVar2 != '\x0e') {
        uVar9 = 0xc0000002;
        goto LAB_140002930;
      }
      goto LAB_1400028ad;
    }
    uVar9 = NsippCleanup(param_1,(longlong)pcVar4);
    uVar9 = uVar9 & 0xffffffff;
    goto LAB_140002928;
  }
LAB_1400028ad:
  cVar2 = *(char *)(param_2 + 0x40);
  *(undefined8 *)(param_2 + 0x38) = 0;
  iVar3 = *(int *)(pcVar4 + 0x18);
  plVar5 = *(longlong **)(pcVar4 + 0x20);
  puVar1 = (undefined8 *)(param_2 + 0x38);
  uVar6 = *(uint *)(pcVar4 + 0x10);
  if (iVar3 == 0x12000f) {
    uVar6 = NsippGetAllParameters(plVar5,uVar6,cVar2,puVar1);
    goto LAB_140002912;
  }
  if (iVar3 == 0x12001b) {
    uVar6 = NsippEnumerateObjectsAllParameters(plVar5,uVar6,cVar2,puVar1);
    goto LAB_140002912;
  }
  if (iVar3 == 0x120007) {
    uVar6 = NsippGetParameter(plVar5,uVar6,cVar2,puVar1);
    goto LAB_140002912;
  }
  switch(iVar3) {
  case 0x12000b:
    uVar6 = NsippSetParameter(plVar5,uVar6,cVar2);
    break;
  default:
    uVar9 = 0xc0000002;
    goto LAB_140002928;
  case 0x120013:
    uVar9 = NsippSetAllParameters(plVar5,uVar6,cVar2,(longlong)pcVar4);
    uVar6 = (uint)uVar9;
    break;
  case 0x12001f:
    if (cVar2 == '\x01') {
      uVar7 = NsippIsCallerNsiService();
      uVar9 = (ulonglong)uVar7;
      if ((int)uVar7 < 0) goto LAB_140002928;
    }
    NsippRegisterChangeNotification(plVar5,uVar6,cVar2,(longlong)pcVar4,puVar1);
    uVar6 = extraout_EAX;
    break;
  case 0x120023:
    if (cVar2 == '\x01') {
      uVar7 = NsippIsCallerNsiService();
      uVar9 = (ulonglong)uVar7;
      if ((int)uVar7 < 0) goto LAB_140002928;
    }
    uVar9 = NsippDeregisterChangeNotification(plVar5,uVar6,cVar2,(longlong)pcVar4);
    uVar6 = (uint)uVar9;
    break;
  case 0x12003f:
    uVar6 = NsippRequestChangeNotification(param_2,plVar5,uVar6,cVar2);
    break;
  case 0x120040:
    uVar9 = NsippCancelChangeNotification(*(ulonglong **)(param_2 + 0x18),uVar6);
    uVar6 = (uint)uVar9;
    break;
  case 0x120047:
    uVar6 = NsippEnumerateObjectsAllPersistentParametersWithMask(plVar5,uVar6,cVar2,puVar1);
    break;
  case 0x12004b:
    uVar6 = NsippGetAllPersistentParametersWithMask(plVar5,uVar6,cVar2,puVar1);
    break;
  case 0x12004f:
    uVar6 = NsippSetAllPersistentParametersWithMask(plVar5,uVar6,cVar2);
  }
LAB_140002912:
  uVar9 = (ulonglong)uVar6;
LAB_140002928:
  if ((int)uVar9 == 0x103) {
    return uVar9;
  }
LAB_140002930:
  *(int *)(param_2 + 0x30) = (int)uVar9;
  IofCompleteRequest(param_2,2);
  return uVar9;
}



===== NsippDispatchDeviceControl @ 140002b40 =====

void NsippDispatchDeviceControl(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  char cVar2;
  uint uVar3;
  longlong *plVar4;
  int iVar5;
  
  puVar1 = (undefined8 *)(param_1 + 0x38);
  cVar2 = *(char *)(param_1 + 0x40);
  *puVar1 = 0;
  iVar5 = *(int *)(param_2 + 0x18);
  uVar3 = *(uint *)(param_2 + 0x10);
  plVar4 = *(longlong **)(param_2 + 0x20);
  if (iVar5 == 0x12000f) {
    NsippGetAllParameters(plVar4,uVar3,cVar2,puVar1);
  }
  else if (iVar5 == 0x12001b) {
    NsippEnumerateObjectsAllParameters(plVar4,uVar3,cVar2,puVar1);
  }
  else if (iVar5 == 0x120007) {
    NsippGetParameter(plVar4,uVar3,cVar2,puVar1);
  }
  else {
    switch(iVar5) {
    case 0x12000b:
      NsippSetParameter(plVar4,uVar3,cVar2);
      break;
    default:
      break;
    case 0x120013:
      NsippSetAllParameters(plVar4,uVar3,cVar2,param_2);
      break;
    case 0x12001f:
      if ((cVar2 != '\x01') || (iVar5 = NsippIsCallerNsiService(), -1 < iVar5)) {
        NsippRegisterChangeNotification(plVar4,uVar3,cVar2,param_2,puVar1);
      }
      break;
    case 0x120023:
      if ((cVar2 != '\x01') || (iVar5 = NsippIsCallerNsiService(), -1 < iVar5)) {
        NsippDeregisterChangeNotification(plVar4,uVar3,cVar2,param_2);
      }
      break;
    case 0x12003f:
      NsippRequestChangeNotification(param_1,plVar4,uVar3,cVar2);
      break;
    case 0x120040:
      NsippCancelChangeNotification(*(ulonglong **)(param_1 + 0x18),uVar3);
      break;
    case 0x120047:
      NsippEnumerateObjectsAllPersistentParametersWithMask(plVar4,uVar3,cVar2,puVar1);
      break;
    case 0x12004b:
      NsippGetAllPersistentParametersWithMask(plVar4,uVar3,cVar2,puVar1);
      break;
    case 0x12004f:
      NsippSetAllPersistentParametersWithMask(plVar4,uVar3,cVar2);
    }
  }
  return;
}



===== NsippGetParameter @ 140002d00 =====

int NsippGetParameter(longlong *param_1,uint param_2,char param_3,undefined8 *param_4)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  longlong lVar4;
  longlong *plVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  uint local_b8 [2];
  longlong local_b0;
  longlong *local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  void *local_88;
  void *local_80;
  undefined8 uStack_78;
  longlong local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  undefined8 uStack_50;
  longlong local_48;
  ulonglong uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  ulonglong local_28;
  longlong lStack_20;
  
  local_a8 = (longlong *)0x0;
  local_b0 = 0;
  plVar8 = (longlong *)0x0;
  bVar2 = false;
  local_80 = (void *)0x0;
  uStack_78 = 0;
  local_88 = (void *)0x0;
  local_b8[0] = 0;
  local_a0 = 0;
  local_90 = 0;
  local_98 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  lStack_20 = 0;
  cVar6 = IoIs32bitProcess(0);
  if (param_1 == (longlong *)0x0) {
LAB_14000305a:
    iVar7 = -0x3ffffff3;
  }
  else {
    if (cVar6 == '\0') {
      if (param_2 < 0x50) goto LAB_14000305a;
      local_a8 = param_1;
    }
    else {
      if (param_2 < 0x30) goto LAB_14000305a;
      bVar2 = true;
      uStack_40 = (ulonglong)*(uint *)(param_1 + 3);
      local_38 = CONCAT44(local_38._4_4_,*(undefined4 *)((longlong)param_1 + 0x1c));
      local_58 = (ulonglong)*(uint *)(param_1 + 1);
      uStack_60 = CONCAT44(uStack_60._4_4_,*(undefined4 *)((longlong)param_1 + 4));
      uStack_50 = CONCAT44(uStack_50._4_4_,*(undefined4 *)((longlong)param_1 + 0xc));
      local_28 = (ulonglong)*(uint *)((longlong)param_1 + 0x24);
      lStack_20 = param_1[5];
      uStack_30 = CONCAT44(uStack_30._4_4_,(int)param_1[4]);
      local_48 = param_1[2];
      local_68 = (longlong)(int)*param_1;
      local_a8 = &local_68;
      plVar8 = param_1;
    }
    plVar5 = local_a8;
    iVar7 = NsippProbeAndAllocateParameters
                      (local_a8,0x50,(longlong)(local_a8 + 1),(undefined4 *)(local_a8 + 5),
                       (longlong)(local_a8 + 7),(undefined4 *)0x0,(undefined8 *)0x0,
                       (undefined8 *)0x0,param_3,1,'\0',&local_80,&local_a0,&local_88,local_b8,
                       &local_90,(undefined8 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,
                       (undefined8 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,
                       &local_98,&local_b0);
    lVar4 = local_b0;
    uVar3 = local_b8[0];
    if (-1 < iVar7) {
      *(undefined8 *)(local_b0 + 0x28) = local_a0;
      *(undefined4 *)(local_b0 + 0x30) = (undefined4)uStack_78;
      *(undefined8 *)(local_b0 + 0x10) = local_98;
      *(undefined8 *)(local_b0 + 0x40) = local_90;
      *(uint *)(local_b0 + 0x48) = local_b8[0];
      iVar7 = NsiGetParameterEx(local_b0);
      if (-1 < iVar7) {
        *param_4 = 0x50;
        if ((*(void **)(lVar4 + 0x28) != (void *)0x0) && (*(uint *)(lVar4 + 0x30) != 0)) {
          memmove(local_80,*(void **)(lVar4 + 0x28),(ulonglong)*(uint *)(lVar4 + 0x30));
        }
        if ((*(void **)(lVar4 + 0x40) != (void *)0x0) && (*(uint *)(lVar4 + 0x48) != 0)) {
          memmove(local_88,*(void **)(lVar4 + 0x40),(ulonglong)*(uint *)(lVar4 + 0x48));
        }
        uVar1 = *(uint *)(lVar4 + 0x48);
        if (bVar2) {
          if (uVar3 != uVar1) {
            *(uint *)(plVar8 + 5) = uVar1;
          }
        }
        else if (uVar3 != uVar1) {
          *(uint *)(plVar5 + 9) = uVar1;
        }
      }
    }
    if (lVar4 != 0) {
      ExFreePoolWithTag(lVar4,0);
    }
  }
  return iVar7;
}



===== NsippGetAllParameters @ 140003070 =====

int NsippGetAllParameters(longlong *param_1,uint param_2,char param_3,undefined8 *param_4)

{
  int iVar1;
  bool bVar2;
  longlong lVar3;
  longlong *plVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong local_108;
  longlong *local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  void *local_d0;
  undefined8 uStack_c8;
  void *local_c0;
  undefined8 uStack_b8;
  void *local_b0;
  undefined8 uStack_a8;
  void *local_a0;
  undefined8 uStack_98;
  longlong local_88;
  undefined8 uStack_80;
  ulonglong local_78;
  undefined8 uStack_70;
  longlong local_68;
  ulonglong uStack_60;
  undefined8 local_58;
  ulonglong uStack_50;
  undefined8 local_48;
  ulonglong uStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  undefined8 local_28;
  
  bVar2 = false;
  local_a0 = (void *)0x0;
  uStack_98 = 0;
  local_d0 = (void *)0x0;
  uStack_c8 = 0;
  local_c0 = (void *)0x0;
  uStack_b8 = 0;
  local_b0 = (void *)0x0;
  uStack_a8 = 0;
  local_f8 = 0;
  local_e8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_f0 = 0;
  plVar8 = (longlong *)0x0;
  local_100 = (longlong *)0x0;
  local_108 = 0;
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
  cVar6 = IoIs32bitProcess(0);
  if (param_1 == (longlong *)0x0) {
LAB_1400034d6:
    iVar7 = -0x3ffffff3;
  }
  else {
    if (cVar6 == '\0') {
      if (param_2 < 0x68) goto LAB_1400034d6;
      local_100 = param_1;
    }
    else {
      if (param_2 < 0x38) goto LAB_1400034d6;
      bVar2 = true;
      uStack_60 = (ulonglong)*(uint *)(param_1 + 3);
      local_58 = CONCAT44(local_58._4_4_,*(undefined4 *)((longlong)param_1 + 0x1c));
      local_78 = (ulonglong)*(uint *)(param_1 + 1);
      uStack_80 = CONCAT44(uStack_80._4_4_,*(undefined4 *)((longlong)param_1 + 4));
      uStack_70 = CONCAT44(uStack_70._4_4_,*(undefined4 *)((longlong)param_1 + 0xc));
      uStack_40 = (ulonglong)*(uint *)(param_1 + 5);
      local_38 = CONCAT44(local_38._4_4_,*(undefined4 *)((longlong)param_1 + 0x2c));
      uStack_30 = (ulonglong)*(uint *)(param_1 + 6);
      local_28 = CONCAT44(local_28._4_4_,*(undefined4 *)((longlong)param_1 + 0x34));
      uStack_50 = (ulonglong)*(uint *)(param_1 + 4);
      local_48 = CONCAT44(local_48._4_4_,*(undefined4 *)((longlong)param_1 + 0x24));
      local_68 = param_1[2];
      local_88 = (longlong)(int)*param_1;
      local_100 = &local_88;
      plVar8 = param_1;
    }
    plVar4 = local_100;
    iVar7 = NsippProbeAndAllocateParameters
                      (local_100,0x68,(longlong)(local_100 + 1),(undefined4 *)(local_100 + 5),0,
                       (undefined4 *)(local_100 + 7),(undefined8 *)0x0,(undefined8 *)0x0,param_3,1,
                       '\x01',&local_a0,&local_f8,(undefined8 *)0x0,(uint *)0x0,(undefined8 *)0x0,
                       &local_d0,&local_d8,(undefined8 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,
                       &local_e8,&local_e0,&local_f0,&local_108);
    lVar3 = local_108;
    if (-1 < iVar7) {
      *(undefined8 *)(local_108 + 0x28) = local_f8;
      *(undefined4 *)(local_108 + 0x30) = (undefined4)uStack_98;
      *(undefined8 *)(local_108 + 0x10) = local_f0;
      *(undefined8 *)(local_108 + 0x48) = local_e8;
      *(int *)(local_108 + 0x50) = (int)uStack_b8;
      *(undefined8 *)(local_108 + 0x58) = local_e0;
      *(int *)(local_108 + 0x60) = (int)uStack_a8;
      *(undefined8 *)(local_108 + 0x38) = local_d8;
      iVar5 = (int)uStack_c8;
      *(int *)(local_108 + 0x40) = (int)uStack_c8;
      iVar7 = NsiGetAllParametersEx(local_108);
      if (-1 < iVar7) {
        *param_4 = 0x68;
        if ((*(void **)(lVar3 + 0x28) != (void *)0x0) && (*(uint *)(lVar3 + 0x30) != 0)) {
          memmove(local_a0,*(void **)(lVar3 + 0x28),(ulonglong)*(uint *)(lVar3 + 0x30));
        }
        if ((*(void **)(lVar3 + 0x48) != (void *)0x0) && (*(uint *)(lVar3 + 0x50) != 0)) {
          memmove(local_c0,*(void **)(lVar3 + 0x48),(ulonglong)*(uint *)(lVar3 + 0x50));
        }
        if ((*(void **)(lVar3 + 0x58) != (void *)0x0) && (*(uint *)(lVar3 + 0x60) != 0)) {
          memmove(local_b0,*(void **)(lVar3 + 0x58),(ulonglong)*(uint *)(lVar3 + 0x60));
        }
        if ((*(void **)(lVar3 + 0x38) != (void *)0x0) && (*(uint *)(lVar3 + 0x40) != 0)) {
          memmove(local_d0,*(void **)(lVar3 + 0x38),(ulonglong)*(uint *)(lVar3 + 0x40));
        }
        iVar1 = *(int *)(lVar3 + 0x50);
        if (bVar2) {
          if (iVar1 != (int)uStack_b8) {
            *(int *)((longlong)plVar8 + 0x2c) = iVar1;
          }
          if (*(int *)(lVar3 + 0x60) != (int)uStack_a8) {
            *(int *)((longlong)plVar8 + 0x34) = *(int *)(lVar3 + 0x60);
          }
          if (*(int *)(lVar3 + 0x40) != iVar5) {
            *(int *)((longlong)plVar8 + 0x24) = *(int *)(lVar3 + 0x40);
          }
        }
        else {
          if (iVar1 != (int)uStack_b8) {
            *(int *)(plVar4 + 10) = iVar1;
          }
          if (*(int *)(lVar3 + 0x60) != (int)uStack_a8) {
            *(int *)(plVar4 + 0xc) = *(int *)(lVar3 + 0x60);
          }
          if (*(int *)(lVar3 + 0x40) != iVar5) {
            *(int *)(plVar4 + 8) = *(int *)(lVar3 + 0x40);
          }
        }
      }
    }
    if (lVar3 != 0) {
      ExFreePoolWithTag(lVar3,0);
    }
  }
  return iVar7;
}



===== NsippEnumerateObjectsAllParameters @ 1400034f0 =====

int NsippEnumerateObjectsAllParameters
              (longlong *param_1,uint param_2,char param_3,undefined8 *param_4)

{
  int iVar1;
  bool bVar2;
  longlong lVar3;
  longlong *plVar4;
  char cVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  bool bVar9;
  longlong local_110;
  longlong *local_108;
  longlong *local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  void *local_d0;
  undefined8 uStack_c8;
  void *local_c0;
  undefined8 uStack_b8;
  void *local_b0;
  undefined8 uStack_a8;
  void *local_a0;
  undefined8 uStack_98;
  longlong local_88;
  undefined8 uStack_80;
  ulonglong local_78;
  undefined8 uStack_70;
  longlong local_68;
  ulonglong uStack_60;
  undefined8 local_58;
  ulonglong uStack_50;
  undefined8 local_48;
  ulonglong uStack_40;
  undefined8 local_38;
  ulonglong uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  
  bVar2 = false;
  local_a0 = (void *)0x0;
  uStack_98 = 0;
  local_d0 = (void *)0x0;
  uStack_c8 = 0;
  local_c0 = (void *)0x0;
  uStack_b8 = 0;
  local_b0 = (void *)0x0;
  uStack_a8 = 0;
  local_f8 = 0;
  local_e8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_f0 = 0;
  local_100 = (longlong *)0x0;
  local_110 = 0;
  local_108 = (longlong *)0x0;
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
  cVar5 = IoIs32bitProcess(0);
  if (param_1 == (longlong *)0x0) {
LAB_140003a2a:
    iVar6 = -0x3ffffff3;
  }
  else {
    if (cVar5 == '\0') {
      if (param_2 < 0x70) goto LAB_140003a2a;
      local_100 = param_1;
      if (param_3 != '\0') {
        ProbeForWrite(param_1,param_2,1);
      }
      uVar8 = *(uint *)(param_1 + 0xd);
    }
    else {
      if (param_2 < 0x3c) goto LAB_140003a2a;
      bVar2 = true;
      local_108 = param_1;
      if (param_3 != '\0') {
        ProbeForWrite(param_1,param_2,1);
      }
      uStack_60 = (ulonglong)*(uint *)(param_1 + 3);
      local_58 = CONCAT44(local_58._4_4_,*(undefined4 *)((longlong)param_1 + 0x1c));
      local_78 = (ulonglong)*(uint *)(param_1 + 1);
      uStack_80 = CONCAT44(uStack_80._4_4_,*(undefined4 *)((longlong)param_1 + 4));
      uStack_70 = CONCAT44(uStack_70._4_4_,*(undefined4 *)((longlong)param_1 + 0xc));
      uStack_40 = (ulonglong)*(uint *)(param_1 + 5);
      local_38 = CONCAT44(local_38._4_4_,*(undefined4 *)((longlong)param_1 + 0x2c));
      uStack_30 = (ulonglong)*(uint *)(param_1 + 6);
      local_28 = CONCAT44(local_28._4_4_,*(undefined4 *)((longlong)param_1 + 0x34));
      uStack_50 = (ulonglong)*(uint *)(param_1 + 4);
      local_48 = CONCAT44(local_48._4_4_,*(undefined4 *)((longlong)param_1 + 0x24));
      local_68 = param_1[2];
      local_88 = (longlong)(int)*param_1;
      uVar8 = *(uint *)(param_1 + 7);
      uStack_20 = CONCAT44(uStack_20._4_4_,uVar8);
      param_1 = &local_88;
      local_100 = param_1;
    }
    iVar6 = NsippProbeAndAllocateParameters
                      (param_1,0x70,(longlong)(param_1 + 1),(undefined4 *)(param_1 + 5),0,
                       (undefined4 *)(param_1 + 7),(undefined8 *)0x0,(undefined8 *)0x0,param_3,uVar8
                       ,'\0',&local_a0,&local_f8,(undefined8 *)0x0,(uint *)0x0,(undefined8 *)0x0,
                       &local_d0,&local_d8,(undefined8 *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,
                       &local_e8,&local_e0,&local_f0,&local_110);
    lVar3 = local_110;
    if (-1 < iVar6) {
      *(uint *)(local_110 + 0x68) = uVar8;
      *(undefined8 *)(local_110 + 0x28) = local_f8;
      bVar9 = uVar8 != 0;
      uVar7 = 0;
      if (bVar9) {
        uVar7 = (undefined4)uStack_98;
      }
      *(undefined4 *)(local_110 + 0x30) = uVar7;
      *(undefined8 *)(local_110 + 0x10) = local_f0;
      *(undefined8 *)(local_110 + 0x48) = local_e8;
      uVar7 = 0;
      if (bVar9) {
        uVar7 = (int)uStack_b8;
      }
      *(undefined4 *)(local_110 + 0x50) = uVar7;
      *(undefined8 *)(local_110 + 0x58) = local_e0;
      uVar7 = 0;
      if (bVar9) {
        uVar7 = (int)uStack_a8;
      }
      *(undefined4 *)(local_110 + 0x60) = uVar7;
      *(undefined8 *)(local_110 + 0x38) = local_d8;
      uVar7 = 0;
      if (bVar9) {
        uVar7 = (int)uStack_c8;
      }
      *(undefined4 *)(local_110 + 0x40) = uVar7;
      iVar6 = NsiEnumerateObjectsAllParametersEx(local_110);
      plVar4 = local_108;
      if (bVar2) {
        *(undefined4 *)(local_108 + 7) = *(undefined4 *)(lVar3 + 0x68);
      }
      else {
        *(undefined4 *)(param_1 + 0xd) = *(undefined4 *)(lVar3 + 0x68);
      }
      if (-1 < iVar6) {
        *param_4 = 0x70;
        if ((*(void **)(lVar3 + 0x28) != (void *)0x0) && (*(int *)(lVar3 + 0x30) != 0)) {
          memmove(local_a0,*(void **)(lVar3 + 0x28),(ulonglong)(*(int *)(lVar3 + 0x30) * uVar8));
        }
        if ((*(void **)(lVar3 + 0x48) != (void *)0x0) && (*(int *)(lVar3 + 0x50) != 0)) {
          memmove(local_c0,*(void **)(lVar3 + 0x48),(ulonglong)(*(int *)(lVar3 + 0x50) * uVar8));
        }
        if ((local_b0 != (void *)0x0) && ((int)uStack_a8 != 0)) {
          memmove(local_b0,*(void **)(lVar3 + 0x58),(ulonglong)(uVar8 * *(int *)(lVar3 + 0x60)));
        }
        if ((local_d0 != (void *)0x0) && ((int)uStack_c8 != 0)) {
          memmove(local_d0,*(void **)(lVar3 + 0x38),(ulonglong)(uVar8 * *(int *)(lVar3 + 0x40)));
        }
        if (uVar8 != 0) {
          iVar1 = *(int *)(lVar3 + 0x50);
          if (bVar2) {
            if (iVar1 != (int)uStack_b8) {
              *(int *)((longlong)plVar4 + 0x2c) = iVar1;
            }
            if (*(int *)(lVar3 + 0x60) != (int)uStack_a8) {
              *(int *)((longlong)plVar4 + 0x34) = *(int *)(lVar3 + 0x60);
            }
            if (*(int *)(lVar3 + 0x40) != (int)uStack_c8) {
              *(int *)((longlong)plVar4 + 0x24) = *(int *)(lVar3 + 0x40);
            }
          }
          else {
            if (iVar1 != (int)uStack_b8) {
              *(int *)(param_1 + 10) = iVar1;
            }
            if (*(int *)(lVar3 + 0x60) != (int)uStack_a8) {
              *(int *)(param_1 + 0xc) = *(int *)(lVar3 + 0x60);
            }
            if (*(int *)(lVar3 + 0x40) != (int)uStack_c8) {
              *(int *)(param_1 + 8) = *(int *)(lVar3 + 0x40);
            }
          }
        }
      }
    }
    if (lVar3 != 0) {
      ExFreePoolWithTag(lVar3,0);
    }
  }
  return iVar6;
}



===== NsippProbeAndAllocateParameters @ 140003a40 =====

int NsippProbeAndAllocateParameters
              (void *param_1,uint param_2,longlong param_3,undefined4 *param_4,longlong param_5,
              undefined4 *param_6,undefined8 *param_7,undefined8 *param_8,char param_9,uint param_10
              ,char param_11,undefined8 *param_12,undefined8 *param_13,undefined8 *param_14,
              uint *param_15,undefined8 *param_16,undefined8 *param_17,undefined8 *param_18,
              undefined8 *param_19,undefined8 *param_20,undefined8 *param_21,undefined8 *param_22,
              undefined8 *param_23,undefined8 *param_24,undefined8 *param_25)

{
  void *_Src;
  void *_Src_00;
  undefined8 uVar1;
  char cVar2;
  ulonglong uVar3;
  ulonglong _Size;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined8 *_Dst;
  undefined8 *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  ulonglong _Size_00;
  undefined8 *_Dst_00;
  ulonglong uVar15;
  longlong lVar16;
  undefined8 *puVar17;
  undefined8 *puVar18;
  undefined8 *_Dst_01;
  undefined8 *_Dst_02;
  ulonglong _Size_01;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  uint uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  uint uVar28;
  undefined4 uVar29;
  int iVar30;
  int local_1a8;
  uint local_1a4;
  uint local_198;
  void *local_188;
  undefined8 *local_180;
  undefined8 *local_178;
  undefined8 *local_170;
  void *local_168;
  void *local_138;
  void *pvStack_130;
  void *local_128;
  ulonglong uStack_120;
  ulonglong uStack_110;
  void *local_f8;
  ulonglong uStack_f0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  void *local_c8;
  void *pvStack_c0;
  undefined8 *local_b8;
  
  local_1a8 = 0;
  iVar30 = 0;
  if (param_25 == (undefined8 *)0x0) {
    return -0x3ffffff3;
  }
  *param_25 = 0;
  uVar3 = (ulonglong)param_2;
  cVar2 = IoIs32bitProcess(0);
  if (cVar2 == '\0') {
    if (param_1 == (void *)0x0) {
      if (uVar3 != 0) goto LAB_1400041a5;
      uVar3 = 0;
    }
    else {
      if (((param_9 != '\0') && (uVar3 != 0)) &&
         ((*(void **)MmUserProbeAddress_exref < (void *)(uVar3 + (longlong)param_1) ||
          ((void *)(uVar3 + (longlong)param_1) < param_1)))) {
        local_1a8 = iVar30;
      }
      uVar3 = uVar3 + 7 & 0xfffffffffffffff8;
    }
  }
  else {
    uVar3 = uVar3 + 7 & 0xfffffffffffffff8;
  }
  if (param_3 == 0) {
    puVar11 = (undefined8 *)0x0;
  }
  else {
    puVar11 = *(undefined8 **)(param_3 + 8);
  }
  if (param_4 == (undefined4 *)0x0) {
    uVar26 = 0;
    uVar27 = 0;
    uVar28 = 0;
    uVar29 = 0;
  }
  else {
    uVar26 = *param_4;
    uVar27 = param_4[1];
    uVar28 = param_4[2];
    uVar29 = param_4[3];
  }
  if (param_5 == 0) {
    local_168 = (void *)0x0;
    uVar5 = 0;
    local_198 = 0;
  }
  else {
    local_168 = *(void **)(param_5 + 8);
    local_198 = *(uint *)(param_5 + 0x10);
    uVar5 = (ulonglong)local_198;
  }
  if (param_6 == (undefined4 *)0x0) {
    uVar22 = 0;
    uVar23 = 0;
    uVar24 = 0;
    uVar25 = 0;
    uVar19 = 0;
    uVar20 = 0;
    uVar12 = 0;
    uVar21 = 0;
    local_f8 = (void *)0x0;
    uStack_f0 = 0;
    if (param_7 == (undefined8 *)0x0) goto LAB_140003b8e;
    local_d8 = (void *)*param_7;
    uVar12 = *(uint *)(param_7 + 1);
    uStack_110 = (ulonglong)uVar12;
    uStack_d0 = uStack_110;
  }
  else {
    uVar19 = *param_6;
    uVar20 = param_6[1];
    uVar12 = param_6[2];
    uVar21 = param_6[3];
    uVar22 = param_6[4];
    uVar23 = param_6[5];
    uVar24 = param_6[6];
    uVar25 = param_6[7];
    local_f8 = *(void **)(param_6 + 8);
    uStack_f0 = *(ulonglong *)(param_6 + 10);
LAB_140003b8e:
    local_d8 = (void *)CONCAT44(uVar20,uVar19);
    uStack_d0 = CONCAT44(uVar21,uVar12);
  }
  if (param_8 == (undefined8 *)0x0) {
    local_c8 = (void *)0x0;
    pvStack_c0 = (void *)0x0;
    local_b8 = param_8;
  }
  else {
    local_c8 = (void *)*param_8;
    pvStack_c0 = (void *)param_8[1];
    local_b8 = (undefined8 *)param_8[2];
  }
  if (puVar11 == (undefined8 *)0x0) {
LAB_1400041a5:
                    /* WARNING: Subroutine does not return */
    ExRaiseAccessViolation();
  }
  uStack_110._0_4_ = uVar12;
  local_1a4 = local_198;
  local_188 = local_168;
  local_138 = local_c8;
  pvStack_130 = pvStack_c0;
  local_128 = local_f8;
  uStack_120 = uStack_f0;
  if ((param_9 != '\0') &&
     ((*(undefined8 **)MmUserProbeAddress_exref < puVar11 + 3 || (puVar11 + 3 < puVar11)))) {
    uVar5 = (ulonglong)local_198;
    uStack_110._0_4_ = (uint)uStack_d0;
    local_1a8 = iVar30;
  }
  uVar15 = (ulonglong)param_10;
  if ((ulonglong)uVar28 * (ulonglong)param_10 < 0x100000000) {
    _Size = (ulonglong)(uVar28 * param_10);
    _Src_00 = (void *)CONCAT44(uVar27,uVar26);
    if (_Src_00 == (void *)0x0) {
      if (_Size != 0) goto LAB_1400041a5;
      uVar4 = 0;
    }
    else {
      if (param_9 != '\0') {
        ProbeForWrite(_Src_00,_Size,1,uVar5,iVar30,uVar3 + 0x18);
      }
      uVar4 = _Size + 7 & 0xfffffffffffffff8;
      uVar5 = (ulonglong)local_1a4;
    }
    lVar16 = uVar3 + 0x18 + uVar4;
    if (0xffffffff < uVar5 * uVar15) {
      local_1a8 = -0x3ffffff3;
      _Dst = (undefined8 *)0x0;
      goto LAB_14000463a;
    }
    uVar12 = (int)uVar5 * param_10;
    uVar3 = (ulonglong)uVar12;
    if (local_188 == (void *)0x0) {
      if (uVar3 != 0) goto LAB_1400041a5;
      uVar5 = 0;
    }
    else {
      if (param_9 != '\0') {
        ProbeForWrite(local_188,uVar3,1,uVar5,iVar30,lVar16);
      }
      uVar5 = uVar3 + 7 & 0xfffffffffffffff8;
    }
    if (0xffffffff < uVar24 * uVar15) {
      local_1a8 = -0x3ffffff3;
      _Dst = (undefined8 *)0x0;
      goto LAB_14000463a;
    }
    uVar4 = (ulonglong)(uVar24 * param_10);
    _Src = (void *)CONCAT44(uVar23,uVar22);
    if (_Src == (void *)0x0) {
      if (uVar4 != 0) goto LAB_1400041a5;
      uVar6 = 0;
    }
    else {
      if (param_9 != '\0') {
        ProbeForWrite(_Src,uVar4,1);
      }
      uVar6 = uVar4 + 7 & 0xfffffffffffffff8;
    }
    if (0xffffffff < (uStack_120 & 0xffffffff) * uVar15) {
      local_1a8 = -0x3ffffff3;
      _Dst = (undefined8 *)0x0;
      goto LAB_14000463a;
    }
    uVar13 = (int)uStack_120 * param_10;
    _Size_00 = (ulonglong)uVar13;
    if (local_128 == (void *)0x0) {
      if (_Size_00 != 0) goto LAB_1400041a5;
      uVar7 = 0;
    }
    else {
      if (param_9 != '\0') {
        ProbeForWrite(local_128,_Size_00,1);
      }
      uVar7 = _Size_00 + 7 & 0xfffffffffffffff8;
    }
    if (0xffffffff < (uint)uStack_110 * uVar15) {
      local_1a8 = -0x3ffffff3;
      _Dst = (undefined8 *)0x0;
      goto LAB_14000463a;
    }
    _Size_01 = (ulonglong)((uint)uStack_110 * param_10);
    if (local_d8 == (void *)0x0) {
      if (_Size_01 != 0) goto LAB_1400041a5;
      uVar8 = 0;
    }
    else {
      if (param_9 != '\0') {
        ProbeForWrite(local_d8,_Size_01,1);
      }
      uVar8 = _Size_01 + 7 & 0xfffffffffffffff8;
    }
    if (0xffffffff < ((ulonglong)local_b8 & 0xffffffff) * uVar15) {
      local_1a8 = -0x3ffffff3;
      _Dst = (undefined8 *)0x0;
      goto LAB_14000463a;
    }
    uVar14 = (int)local_b8 * param_10;
    uVar15 = (ulonglong)uVar14;
    if (local_138 == (void *)0x0) {
      if (uVar14 != 0) goto LAB_1400041a5;
      uVar9 = 0;
    }
    else {
      if (param_9 != '\0') {
        ProbeForWrite(local_138,uVar15,1);
      }
      uVar9 = uVar15 + 7 & 0xfffffffffffffff8;
    }
    if (pvStack_130 == (void *)0x0) {
      if (uVar15 != 0) goto LAB_1400041a5;
      uVar10 = 0;
    }
    else {
      if (param_9 != '\0') {
        ProbeForWrite(pvStack_130,uVar15,1);
      }
      uVar10 = uVar15 + 7 & 0xfffffffffffffff8;
    }
    uVar10 = lVar16 + uVar5 + uVar6 + uVar7 + uVar8 + uVar9 + uVar10;
    if (uVar10 < 0x100000000) {
      _Dst = (undefined8 *)ExAllocatePool2(0x41,uVar10 & 0xffffffff,0x6770534e);
      if (_Dst != (undefined8 *)0x0) {
        puVar17 = _Dst;
        if ((param_1 != (void *)0x0) && (param_2 != 0)) {
          memmove(_Dst,param_1,(ulonglong)param_2);
          puVar17 = (undefined8 *)(((ulonglong)param_2 + 7 & 0xfffffffffffffff8) + (longlong)_Dst);
        }
        uVar1 = puVar11[1];
        *puVar17 = *puVar11;
        puVar17[1] = uVar1;
        puVar17[2] = puVar11[2];
        puVar11 = puVar17 + 3;
        if ((_Src_00 == (void *)0x0) || (uVar28 * param_10 == 0)) {
          local_180 = (undefined8 *)0x0;
          puVar18 = puVar11;
        }
        else {
          memmove(puVar11,_Src_00,_Size);
          puVar18 = (undefined8 *)((longlong)puVar11 + (_Size + 7 & 0xfffffffffffffff8));
          local_180 = puVar11;
        }
        if ((local_188 == (void *)0x0) || (uVar12 == 0)) {
          local_178 = (undefined8 *)0x0;
          puVar11 = puVar18;
        }
        else {
          if (param_11 == '\x01') {
            memmove(puVar18,local_188,uVar3);
          }
          puVar11 = (undefined8 *)((longlong)puVar18 + (uVar3 + 7 & 0xfffffffffffffff8));
          local_178 = puVar18;
        }
        if ((_Src == (void *)0x0) || (uVar24 * param_10 == 0)) {
          puVar18 = puVar11;
          puVar11 = (undefined8 *)0x0;
        }
        else {
          if (param_11 == '\x01') {
            memmove(puVar11,_Src,uVar4);
          }
          puVar18 = (undefined8 *)((longlong)puVar11 + (uVar4 + 7 & 0xfffffffffffffff8));
        }
        if ((local_128 == (void *)0x0) || (uVar13 == 0)) {
          _Dst_01 = puVar18;
          puVar18 = (undefined8 *)0x0;
        }
        else {
          if (param_11 == '\x01') {
            memmove(puVar18,local_128,_Size_00);
          }
          _Dst_01 = (undefined8 *)((longlong)puVar18 + (_Size_00 + 7 & 0xfffffffffffffff8));
        }
        if ((local_d8 == (void *)0x0) || ((uint)uStack_110 * param_10 == 0)) {
          _Dst_02 = _Dst_01;
          _Dst_01 = (undefined8 *)0x0;
        }
        else {
          if (param_11 == '\x01') {
            memmove(_Dst_01,local_d8,_Size_01);
          }
          _Dst_02 = (undefined8 *)((longlong)_Dst_01 + (_Size_01 + 7 & 0xfffffffffffffff8));
        }
        if ((local_138 == (void *)0x0) || (uVar14 == 0)) {
          local_170 = (undefined8 *)0x0;
          _Dst_00 = _Dst_02;
        }
        else {
          if (param_11 == '\x01') {
            memmove(_Dst_02,local_138,uVar15);
          }
          _Dst_00 = (undefined8 *)((longlong)_Dst_02 + (uVar15 + 7 & 0xfffffffffffffff8));
          local_170 = _Dst_02;
        }
        if ((pvStack_130 == (void *)0x0) || (uVar14 == 0)) {
          _Dst_00 = (undefined8 *)0x0;
        }
        else if (param_11 == '\x01') {
          memmove(_Dst_00,pvStack_130,uVar15);
        }
        if (param_15 != (uint *)0x0) {
          *param_15 = local_1a4;
        }
        if (param_14 != (undefined8 *)0x0) {
          *param_14 = local_188;
        }
        if (param_17 != (undefined8 *)0x0) {
          *param_17 = local_d8;
          param_17[1] = uStack_d0;
          param_17[2] = CONCAT44(uVar23,uVar22);
          param_17[3] = CONCAT44(uVar25,uVar24);
          param_17[4] = local_128;
          param_17[5] = uStack_120;
        }
        if (param_12 != (undefined8 *)0x0) {
          *param_12 = CONCAT44(uVar27,uVar26);
          param_12[1] = CONCAT44(uVar29,uVar28);
        }
        if (param_19 != (undefined8 *)0x0) {
          *param_19 = local_138;
          param_19[1] = pvStack_130;
          param_19[2] = local_b8;
        }
        if (param_13 != (undefined8 *)0x0) {
          *param_13 = local_180;
        }
        if (param_24 != (undefined8 *)0x0) {
          *param_24 = puVar17;
        }
        if (param_16 != (undefined8 *)0x0) {
          *param_16 = local_178;
        }
        if (param_22 != (undefined8 *)0x0) {
          *param_22 = puVar11;
        }
        if (param_23 != (undefined8 *)0x0) {
          *param_23 = puVar18;
        }
        if (param_18 != (undefined8 *)0x0) {
          *param_18 = _Dst_01;
        }
        if (param_20 != (undefined8 *)0x0) {
          *param_20 = local_170;
        }
        if (param_21 != (undefined8 *)0x0) {
          *param_21 = _Dst_00;
        }
        goto LAB_14000463a;
      }
      local_1a8 = -0x3fffff66;
    }
    else {
      local_1a8 = -0x3ffffff3;
      _Dst = (undefined8 *)0x0;
    }
  }
  else {
    local_1a8 = -0x3ffffff3;
    _Dst = (undefined8 *)0x0;
LAB_14000463a:
    puVar11 = _Dst;
    if (-1 < local_1a8) goto LAB_14000463e;
  }
  puVar11 = (undefined8 *)0x0;
  if (_Dst != (undefined8 *)0x0) {
    ExFreePoolWithTag(_Dst,0);
    puVar11 = (undefined8 *)0x0;
  }
LAB_14000463e:
  *param_25 = puVar11;
  return local_1a8;
}



===== NsippIsCallerNsiService @ 1400046d0 =====

undefined4 NsippIsCallerNsiService(void)

{
  char cVar1;
  undefined8 uVar2;
  undefined4 local_res8 [2];
  undefined4 local_res10 [6];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_res8[0] = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_res10[0] = 0;
  local_18 = 0;
  uStack_10 = 0;
  uVar2 = PsGetCurrentProcess();
  SeCaptureSubjectContextEx(0,uVar2,&local_28);
  SeLockSubjectContext(&local_28);
  uVar2 = IoGetFileObjectGenericMapping();
  cVar1 = SeAccessCheck(NsiServiceSecurityDescriptor,&local_28,1,0x1f01ff,0,0,uVar2,1,local_res10,
                        local_res8);
  SeUnlockSubjectContext(&local_28);
  SeReleaseSubjectContext(&local_28);
  if (cVar1 != '\0') {
    local_res8[0] = 0;
  }
  return local_res8[0];
}



===== NsippRegisterChangeNotification @ 1400047c0 =====

int NsippRegisterChangeNotification
              (longlong *param_1,uint param_2,char param_3,longlong param_4,undefined8 *param_5)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  longlong lVar9;
  char cVar10;
  undefined1 uVar11;
  int iVar12;
  longlong *plVar13;
  longlong *plVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 auStack_f8 [8];
  undefined1 auStack_f0 [24];
  longlong *local_d8;
  longlong *local_d0;
  undefined8 local_c8;
  longlong *local_c0;
  longlong *local_b8;
  undefined8 *local_b0;
  undefined4 *local_a8;
  longlong local_98;
  ulonglong uStack_90;
  undefined8 local_88;
  ulonglong uStack_80;
  undefined8 local_78;
  ulonglong uStack_70;
  longlong local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  longlong local_48;
  longlong lStack_40;
  longlong lStack_38;
  undefined8 local_30;
  undefined4 local_28;
  
  local_b8 = (longlong *)0x0;
  local_d8 = (longlong *)0x0;
  local_a8 = (undefined4 *)0x0;
  local_b0 = (undefined8 *)0x0;
  plVar14 = (longlong *)0x0;
  local_d0 = (longlong *)0x0;
  local_98 = 0;
  uStack_90 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = local_58 & 0xffffffff00000000;
  cVar10 = IoIs32bitProcess(0);
  puVar15 = auStack_f8;
  if (param_1 == (longlong *)0x0) goto LAB_140004b19;
  if (cVar10 == '\0') {
    puVar15 = auStack_f8;
    if (param_2 < 0x48) goto LAB_140004b19;
    local_b8 = param_1;
  }
  else {
    puVar15 = auStack_f8;
    if (param_2 < 0x28) goto LAB_140004b19;
    NsippProbeForRead((longlong)param_1,(ulonglong)param_2);
    uStack_90 = (ulonglong)*(uint *)((longlong)param_1 + 4);
    local_98 = CONCAT44(local_98._4_4_,(int)*param_1);
    local_88 = CONCAT44(local_88._4_4_,(int)param_1[1]);
    uStack_80 = (ulonglong)*(uint *)((longlong)param_1 + 0xc);
    local_78 = CONCAT71(local_78._1_7_,(char)param_1[2]);
    uStack_70 = (ulonglong)*(uint *)((longlong)param_1 + 0x14);
    local_68 = param_1[3];
    local_58 = (ulonglong)*(uint *)((longlong)param_1 + 0x24);
    local_b8 = &local_98;
  }
  plVar4 = local_b8;
  puVar16 = auStack_f8;
  cVar10 = IoIs32bitProcess(0);
  if (cVar10 == '\0') {
    if (plVar4 == (longlong *)0x0) goto LAB_140004906;
    if (param_3 != '\0') {
      ProbeForWrite(plVar4,0x48,1);
    }
  }
  local_c8 = 0x48;
  puVar1 = (undefined4 *)plVar4[1];
  puVar2 = (undefined8 *)plVar4[8];
  local_b0 = puVar2;
  local_a8 = puVar1;
  if ((puVar1 == (undefined4 *)0x0) || (local_c8 = 0x60, puVar2 == (undefined8 *)0x0)) {
LAB_140004906:
                    /* WARNING: Subroutine does not return */
    ExRaiseAccessViolation();
  }
  if (param_3 != '\0') {
    ProbeForWrite(puVar2,8,1);
  }
  local_c8 = 0x68;
  plVar13 = (longlong *)ExAllocatePool2(0x41,0x68,0x6770534e);
  local_d8 = plVar13;
  if (plVar13 == (longlong *)0x0) {
LAB_140004bc5:
    puVar15 = puVar16;
    if (plVar14 != (longlong *)0x0) {
      *(undefined8 *)(puVar16 + -8) = 0x140004bda;
      ExFreePoolWithTag(plVar14,0);
    }
  }
  else {
    lVar3 = plVar4[1];
    *plVar13 = *plVar4;
    plVar13[1] = lVar3;
    lVar3 = plVar4[3];
    plVar13[2] = plVar4[2];
    plVar13[3] = lVar3;
    lVar3 = plVar4[5];
    plVar13[4] = plVar4[4];
    plVar13[5] = lVar3;
    lVar3 = plVar4[7];
    plVar13[6] = plVar4[6];
    plVar13[7] = lVar3;
    plVar13[8] = plVar4[8];
    uVar6 = puVar1[1];
    uVar7 = puVar1[2];
    uVar8 = puVar1[3];
    *(undefined4 *)(plVar13 + 9) = *puVar1;
    *(undefined4 *)((longlong)plVar13 + 0x4c) = uVar6;
    *(undefined4 *)(plVar13 + 10) = uVar7;
    *(undefined4 *)((longlong)plVar13 + 0x54) = uVar8;
    plVar13[0xb] = *(longlong *)(puVar1 + 4);
    plVar13[1] = (longlong)(plVar13 + 9);
    local_c0 = plVar13 + 0xd;
    plVar13[8] = (longlong)(plVar13 + 0xc);
    if (((param_3 == '\x01') && (puVar16 = auStack_f8, plVar13[3] != 0)) ||
       ((param_3 == '\0' && (puVar16 = auStack_f8, plVar13[3] == 0)))) goto LAB_140004bc5;
    lVar3 = *(longlong *)(*(longlong *)(param_4 + 0x30) + 0x18);
    plVar14 = (longlong *)ExAllocatePool2(0x41,0x50,0x6370534e);
    puVar16 = auStack_f8;
    local_d0 = plVar14;
    if (plVar14 == (longlong *)0x0) goto LAB_140004bc5;
    plVar14[1] = (longlong)plVar14;
    *plVar14 = (longlong)plVar14;
    *(undefined4 *)(plVar14 + 2) = 0;
    lVar9 = plVar13[1];
    plVar14[3] = *plVar13;
    plVar14[4] = lVar9;
    plVar14[5] = plVar13[2];
    plVar14[4] = (longlong)(plVar14 + 7);
    puVar1 = (undefined4 *)plVar13[1];
    uVar6 = puVar1[1];
    uVar7 = puVar1[2];
    uVar8 = puVar1[3];
    *(undefined4 *)(plVar14 + 7) = *puVar1;
    *(undefined4 *)((longlong)plVar14 + 0x3c) = uVar6;
    *(undefined4 *)(plVar14 + 8) = uVar7;
    *(undefined4 *)((longlong)plVar14 + 0x44) = uVar8;
    plVar14[9] = *(longlong *)(puVar1 + 4);
    iVar12 = NsiRegisterChangeNotificationEx(plVar13);
    if (-1 < iVar12) {
      if (param_3 == '\0') {
        *puVar2 = *(undefined8 *)plVar13[8];
      }
      else {
        *puVar2 = plVar14;
      }
      *param_5 = 0x48;
      plVar14[6] = *(longlong *)plVar13[8];
      uVar11 = KeAcquireSpinLockRaiseToDpc(lVar3 + 0x18);
      if (*(char *)(lVar3 + 0x10) == '\0') {
        plVar4 = *(longlong **)(lVar3 + 8);
        if (*plVar4 != lVar3) {
          pcVar5 = (code *)swi(0x29);
          (*pcVar5)(3);
          puVar16 = auStack_f0;
          goto LAB_140004bc5;
        }
        *plVar14 = lVar3;
        plVar14[1] = (longlong)plVar4;
        *plVar4 = (longlong)plVar14;
        *(longlong **)(lVar3 + 8) = plVar14;
        KeReleaseSpinLock(lVar3 + 0x18,uVar11);
      }
      else {
        local_48 = 0;
        lStack_40 = 0;
        lStack_38 = 0;
        local_28 = 0;
        KeReleaseSpinLock(lVar3 + 0x18,uVar11);
        local_48 = *plVar13;
        lStack_40 = plVar13[1];
        lStack_38 = plVar13[2];
        local_30 = *(undefined8 *)plVar13[8];
        NsiDeregisterChangeNotificationEx(&local_48);
        iVar12 = -0x3fffffaa;
      }
    }
    puVar16 = auStack_f8;
    puVar15 = auStack_f8;
    if (iVar12 < 0) goto LAB_140004bc5;
  }
  if (plVar13 != (longlong *)0x0) {
    *(undefined8 *)(puVar15 + -8) = 0x140004b11;
    ExFreePoolWithTag(plVar13,0);
  }
LAB_140004b19:
  return (int)*(undefined8 *)(puVar15 + 0xe8);
}



===== NsippProbeForRead @ 140004c90 =====

ulonglong NsippProbeForRead(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  
  if (param_1 == 0) {
    if (param_2 != 0) {
                    /* WARNING: Subroutine does not return */
      ExRaiseAccessViolation();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = param_2 + 7U & 0xfffffffffffffff8;
  }
  return uVar1;
}



===== NsippGetAllPersistentParametersWithMask @ 140004cf0 =====

int NsippGetAllPersistentParametersWithMask
              (longlong *param_1,uint param_2,char param_3,undefined8 *param_4)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  longlong local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  void *local_90;
  undefined8 uStack_88;
  void *local_80;
  void *pvStack_78;
  ulonglong local_70;
  longlong local_68;
  undefined8 uStack_60;
  ulonglong local_58;
  undefined8 uStack_50;
  ulonglong local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  ulonglong uStack_30;
  undefined8 local_28;
  longlong *local_18;
  
  local_b8 = 0;
  local_90 = (void *)0x0;
  uStack_88 = 0;
  local_98 = 0;
  local_a0 = 0;
  local_b0 = 0;
  local_80 = (void *)0x0;
  pvStack_78 = (void *)0x0;
  local_70 = 0;
  local_a8 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  cVar2 = IoIs32bitProcess(0);
  if (param_1 == (longlong *)0x0) {
LAB_140004fad:
    iVar3 = -0x3ffffff3;
  }
  else {
    if (cVar2 == '\0') {
      if (param_2 < 0x48) goto LAB_140004fad;
    }
    else {
      if (param_2 < 0x24) goto LAB_140004fad;
      NsippProbeForRead((longlong)param_1,(ulonglong)param_2);
      local_48 = (ulonglong)*(uint *)(param_1 + 2);
      uStack_40 = CONCAT44(uStack_40._4_4_,*(undefined4 *)((longlong)param_1 + 0x14));
      local_58 = (ulonglong)*(uint *)(param_1 + 1);
      uStack_60 = CONCAT44(uStack_60._4_4_,*(undefined4 *)((longlong)param_1 + 4));
      uStack_50 = CONCAT44(uStack_50._4_4_,*(undefined4 *)((longlong)param_1 + 0xc));
      uStack_30 = (ulonglong)*(uint *)((longlong)param_1 + 0x1c);
      local_38 = (ulonglong)*(uint *)(param_1 + 3);
      local_28 = CONCAT44(local_28._4_4_,(int)param_1[4]);
      local_68 = (longlong)(int)*param_1;
      param_1 = &local_68;
      local_18 = param_1;
    }
    iVar3 = NsippProbeAndAllocateParameters
                      (param_1,0x48,(longlong)(param_1 + 1),(undefined4 *)(param_1 + 4),0,
                       (undefined4 *)0x0,(undefined8 *)0x0,param_1 + 6,param_3,1,'\0',&local_90,
                       &local_b0,(undefined8 *)0x0,(uint *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,
                       (undefined8 *)0x0,&local_80,&local_98,&local_a0,(undefined8 *)0x0,
                       (undefined8 *)0x0,&local_a8,&local_b8);
    lVar1 = local_b8;
    if (-1 < iVar3) {
      *(undefined8 *)(local_b8 + 0x20) = local_b0;
      *(undefined4 *)(local_b8 + 0x28) = (undefined4)uStack_88;
      *(undefined8 *)(local_b8 + 0x10) = local_a8;
      *(undefined8 *)(local_b8 + 0x38) = local_a0;
      *(undefined8 *)(local_b8 + 0x30) = local_98;
      *(int *)(local_b8 + 0x40) = (int)local_70;
      iVar3 = NsiGetAllPersistentParametersWithMask
                        (*(undefined8 *)(local_b8 + 0x10),*(undefined4 *)(local_b8 + 0x18),
                         *(undefined8 *)(local_b8 + 0x20),*(undefined4 *)(local_b8 + 0x28),
                         *(undefined8 *)(local_b8 + 0x30),*(undefined8 *)(local_b8 + 0x38),
                         local_70 & 0xffffffff);
      if (-1 < iVar3) {
        *param_4 = 0x48;
        if ((*(void **)(lVar1 + 0x20) != (void *)0x0) && (*(uint *)(lVar1 + 0x28) != 0)) {
          memmove(local_90,*(void **)(lVar1 + 0x20),(ulonglong)*(uint *)(lVar1 + 0x28));
        }
        if ((*(void **)(lVar1 + 0x30) != (void *)0x0) && (*(uint *)(lVar1 + 0x40) != 0)) {
          memmove(local_80,*(void **)(lVar1 + 0x30),(ulonglong)*(uint *)(lVar1 + 0x40));
        }
        if ((*(void **)(lVar1 + 0x38) != (void *)0x0) && (*(uint *)(lVar1 + 0x40) != 0)) {
          memmove(pvStack_78,*(void **)(lVar1 + 0x38),(ulonglong)*(uint *)(lVar1 + 0x40));
        }
      }
    }
    if (lVar1 != 0) {
      ExFreePoolWithTag(lVar1,0);
    }
  }
  return iVar3;
}



===== NsippProbeForWrite @ 140005050 =====

ulonglong NsippProbeForWrite(longlong param_1,longlong param_2,undefined8 param_3,char param_4)

{
  ulonglong uVar1;
  
  if (param_1 == 0) {
    if (param_2 != 0) {
                    /* WARNING: Subroutine does not return */
      ExRaiseAccessViolation();
    }
    uVar1 = 0;
  }
  else {
    if (param_4 != '\0') {
      ProbeForWrite(param_1,param_2,1);
    }
    uVar1 = param_2 + 7U & 0xfffffffffffffff8;
  }
  return uVar1;
}



===== NsippChangeNotificationCallback @ 1400050a0 =====

void NsippChangeNotificationCallback(longlong *param_1)

{
  longlong *plVar1;
  code *pcVar2;
  bool bVar3;
  longlong lVar4;
  longlong ***ppplVar5;
  longlong ***ppplVar6;
  undefined1 local_res8 [8];
  longlong ***local_18;
  longlong ***ppplStack_10;
  
  local_res8[0] = 0;
  local_18 = (longlong ***)0x0;
  ppplStack_10 = (longlong ***)0x0;
  bVar3 = false;
  IoAcquireCancelSpinLock(local_res8);
  KeAcquireSpinLockAtDpcLevel(&NsippNotificationHandleListLock);
  plVar1 = NsippNotificationHandleList;
  while( true ) {
    if ((longlong **)plVar1 == &NsippNotificationHandleList) {
      KeReleaseSpinLockFromDpcLevel(&NsippNotificationHandleListLock);
      IoReleaseCancelSpinLock(local_res8[0]);
      return;
    }
    if (param_1 == plVar1) break;
    plVar1 = (longlong *)*plVar1;
  }
  KeAcquireSpinLockAtDpcLevel(param_1 + 0xb);
  local_18 = (longlong ***)param_1[0xc];
  ppplVar5 = (longlong ***)(param_1 + 0xc);
  if (local_18 == ppplVar5) {
    ppplStack_10 = (longlong ***)&local_18;
    local_18 = (longlong ***)&local_18;
  }
  else {
    ppplStack_10 = (longlong ***)param_1[0xd];
    local_18[1] = (longlong **)&local_18;
    *ppplStack_10 = (longlong **)&local_18;
    param_1[0xd] = (longlong)ppplVar5;
    *ppplVar5 = (longlong **)ppplVar5;
  }
  if (((int)param_1[2] == 0) && (lVar4 = IoAllocateWorkItem(NsiProxyDeviceObject), lVar4 != 0)) {
    param_1[0xe] = lVar4;
    lVar4 = *param_1;
    if ((*(longlong **)(lVar4 + 8) != param_1) ||
       (plVar1 = (longlong *)param_1[1], (longlong *)*plVar1 != param_1)) goto LAB_1400052c8;
    *plVar1 = lVar4;
    bVar3 = true;
    *(longlong **)(lVar4 + 8) = plVar1;
  }
  KeReleaseSpinLockFromDpcLevel(param_1 + 0xb);
  KeReleaseSpinLockFromDpcLevel(&NsippNotificationHandleListLock);
  ppplVar5 = local_18;
  if ((longlong ****)local_18 != &local_18) {
    do {
      *(undefined4 *)(ppplVar5 + -0xf) = 0;
      ppplVar5[-0xe] = (longlong **)0x0;
      LOCK();
      ppplVar5[-8] = (longlong **)0x0;
      UNLOCK();
      ppplVar5 = (longlong ***)*ppplVar5;
    } while ((longlong ****)ppplVar5 != &local_18);
  }
  IoReleaseCancelSpinLock(local_res8[0]);
  while( true ) {
    if ((longlong ****)local_18 == &local_18) {
      if (bVar3) {
        IoQueueWorkItem(param_1[0xe],NsippDeregisterWorker,1,param_1);
      }
      return;
    }
    if (((longlong ****)local_18[1] != &local_18) ||
       (ppplVar5 = (longlong ***)*local_18, (longlong ***)ppplVar5[1] != local_18)) break;
    ppplVar5[1] = (longlong **)&local_18;
    ppplVar6 = local_18 + -0x15;
    local_18 = ppplVar5;
    IofCompleteRequest(ppplVar6,0);
  }
LAB_1400052c8:
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}



===== NsippDeregisterWorker @ 1400052e0 =====

void NsippDeregisterWorker(undefined8 param_1,longlong param_2)

{
  undefined4 local_38;
  undefined4 uStack_34;
  undefined8 uStack_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined4 local_18;
  
  uStack_28 = *(undefined8 *)(param_2 + 0x28);
  local_18 = 0;
  local_38 = *(undefined4 *)(param_2 + 0x18);
  uStack_34 = *(undefined4 *)(param_2 + 0x1c);
  uStack_30 = *(undefined8 *)(param_2 + 0x20);
  local_20 = *(undefined8 *)(param_2 + 0x30);
  NsiDeregisterChangeNotificationEx(&local_38);
  IoFreeWorkItem(*(undefined8 *)(param_2 + 0x70));
  ExFreePoolWithTag(param_2,0);
  return;
}



===== NsippCreateDevice @ 140005360 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int NsippCreateDevice(longlong param_1)

{
  undefined8 *puVar1;
  int iVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auStack_158 [48];
  undefined8 *local_128;
  undefined4 local_108 [2];
  undefined8 local_100;
  wchar_t *local_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  longlong local_c0 [5];
  wchar_t local_98 [64];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  local_100 = 0x80007e;
  local_f0 = 0;
  uStack_e8 = 0;
  local_f8 = local_98;
  builtin_wcsncpy(local_98,L"D:P(A;;GX;;;WD)(A;;GA;;;SY)(A;;GA;;;BA)(A;;GX;;;RC)(A;;GX;;;AC)",0x40);
  local_e0 = 0;
  uStack_d8 = 0;
  local_c0[1] = 0;
  local_c0[2] = 0;
  local_c0[3] = 0;
  local_108[0] = 1;
  local_c0[0] = AllocateCapabilitySid(1,local_108);
  if (local_c0[0] == 0) {
LAB_1400055b4:
    iVar2 = -0x3fffff66;
  }
  else {
    local_108[0] = 2;
    local_c0[1] = AllocateCapabilitySid(1,local_108);
    if (local_c0[1] == 0) goto LAB_1400055b4;
    lVar4 = 3;
    local_108[0] = 3;
    local_c0[2] = AllocateCapabilitySid(1,local_108);
    if (local_c0[2] == 0) goto LAB_1400055b4;
    local_d0 = 0xfb3842cd;
    local_cc = 0x4f839e2a;
    local_c8 = 0x74bcc8f;
    local_c4 = 0xe99a1361;
    local_c0[3] = AllocateCapabilitySid(4,&local_d0);
    if (local_c0[3] == 0) goto LAB_1400055b4;
    pwVar3 = L"\\Device\\Nsi";
    RtlInitUnicodeString(&local_f0);
    local_128 = &local_100;
    iVar2 = WdmlibIoCreateDeviceSecure(param_1,pwVar3,&local_f0);
    if (iVar2 < 0) goto LAB_1400055dc;
    uVar8 = 0;
    NsiServiceSecurityDescriptor = 0;
    uVar7 = 0x4000a280;
    pwVar3 = L"D:P(A;;FA;;;S-1-5-80-2310782386-4237065203-3688974353-390202159-3511571085)";
    iVar2 = SeConvertStringSecurityDescriptorToSecurityDescriptor
                      (L"D:P(A;;FA;;;S-1-5-80-2310782386-4237065203-3688974353-390202159-3511571085)"
                       ,1);
    if (-1 < iVar2) {
      iVar2 = ApplySecurityToDeviceObject((ulonglong)pwVar3,local_c0,uVar7,uVar8);
      if (-1 < iVar2) {
        RtlInitUnicodeString(&local_e0,L"\\??\\Nsi");
        iVar2 = IoCreateSymbolicLink(&local_e0,&local_f0);
        if (-1 < iVar2) {
          *(uint *)(NsiProxyDeviceObject + 0x30) = *(uint *)(NsiProxyDeviceObject + 0x30) | 0x10;
          puVar1 = (undefined8 *)(param_1 + 0x70);
          do {
            puVar6 = puVar1;
            *puVar6 = NsippDispatch;
            puVar6[1] = NsippDispatch;
            puVar6[2] = NsippDispatch;
            puVar6[3] = NsippDispatch;
            puVar6[4] = NsippDispatch;
            puVar6[5] = NsippDispatch;
            puVar6[6] = NsippDispatch;
            puVar6[7] = NsippDispatch;
            lVar4 = lVar4 + -1;
            puVar1 = puVar6 + 8;
          } while (lVar4 != 0);
          puVar6[8] = NsippDispatch;
          puVar6[9] = NsippDispatch;
          puVar6[10] = NsippDispatch;
          puVar6[0xb] = NsippDispatch;
          goto LAB_1400055dc;
        }
      }
    }
  }
  if (NsiProxyDeviceObject != 0) {
    IoDeleteDevice();
    NsiProxyDeviceObject = 0;
  }
LAB_1400055dc:
  plVar5 = local_c0;
  lVar4 = 4;
  do {
    if (*plVar5 != 0) {
      ExFreePoolWithTag(*plVar5,0x6770534e);
    }
    plVar5 = plVar5 + 1;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  return iVar2;
}



===== AllocateCapabilitySid @ 140005640 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong AllocateCapabilitySid(byte param_1,void *param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined1 auStack_68 [32];
  undefined4 local_48;
  undefined2 local_44;
  undefined4 local_40;
  undefined1 local_3c [20];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  local_48 = 0;
  local_44 = 0xf00;
  uVar4 = (uint)(byte)(param_1 + 1);
  uVar1 = RtlLengthRequiredSid(uVar4);
  lVar2 = ExAllocatePool2(0x100,uVar1,0x6770534e);
  if (lVar2 != 0) {
    RtlInitializeSid(lVar2,&local_48,param_1 + 1);
    local_40 = 3;
    if (param_1 != 0) {
      memmove(local_3c,param_2,(ulonglong)param_1 << 2);
    }
    uVar5 = 0;
    if (uVar4 != 0) {
      puVar6 = &local_40;
      do {
        puVar3 = (undefined4 *)RtlSubAuthoritySid(lVar2,uVar5);
        uVar1 = *puVar6;
        puVar6 = puVar6 + 1;
        uVar5 = uVar5 + 1;
        *puVar3 = uVar1;
      } while (uVar5 < uVar4);
    }
  }
  return lVar2;
}



===== __report_gsfailure @ 140005750 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== __C_specific_handler @ 14000575d =====

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00014000575d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



===== DrvDereferenceDriver @ 140005770 =====

void DrvDereferenceDriver(void)

{
  int iVar1;
  bool bVar2;
  
  LOCK();
  iVar1 = DrvpReferenceCount + -1;
  UNLOCK();
  bVar2 = DrvpReferenceCount == 1;
  DrvpReferenceCount = iVar1;
  if (bVar2) {
    KeSetEvent(&DrvpAllowUnloadEvent,0,0);
  }
  return;
}



===== DrvInitializeAllowUnloadEvent @ 1400057a8 =====

void DrvInitializeAllowUnloadEvent(void)

{
  KeInitializeEvent(&DrvpAllowUnloadEvent,0,0);
  return;
}



===== DrvWaitForAllowUnloadEvent @ 1400057d0 =====

void DrvWaitForAllowUnloadEvent(void)

{
  KeWaitForSingleObject(&DrvpAllowUnloadEvent,6,0,0,0);
  return;
}



===== ApplySecurityToDeviceObject @ 140005804 =====

int ApplySecurityToDeviceObject(ulonglong param_1,undefined8 *param_2,uint param_3,uint param_4)

{
  undefined8 uVar1;
  int iVar2;
  void *_Dst;
  uint uVar3;
  longlong lVar4;
  ulonglong local_res8 [2];
  uint local_res18 [2];
  uint local_res20 [2];
  undefined8 local_68;
  void *local_60;
  longlong local_58 [6];
  
  uVar1 = NsiProxyDeviceObject;
  local_68 = 0;
  local_60 = (void *)0x0;
  _Dst = (void *)0x0;
  local_58[0] = 0;
  local_58[5] = 0;
  local_res8[0] = param_1 & 0xffffffffffffff00;
  local_res18[0] = param_3 & 0xffffff00;
  local_res20[0] = param_4 & 0xffffff00;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  local_58[4] = 0;
  iVar2 = ObOpenObjectByPointer(NsiProxyDeviceObject,0x200,0,0x40000,0,0,&local_68);
  if (-1 < iVar2) {
    iVar2 = ObGetObjectSecurity(uVar1,local_58,local_res20);
    if (-1 < iVar2) {
      iVar2 = RtlGetDaclSecurityDescriptor(local_58[0],local_res8,&local_60,local_res18);
      if (-1 < iVar2) {
        lVar4 = 4;
        uVar3 = (uint)*(ushort *)((longlong)local_60 + 2);
        do {
          iVar2 = RtlLengthSid(*param_2);
          param_2 = param_2 + 1;
          uVar3 = uVar3 + 8 + iVar2;
          lVar4 = lVar4 + -1;
        } while (lVar4 != 0);
        _Dst = (void *)ExAllocatePool2(0x100,uVar3,0x41636c);
        if (_Dst == (void *)0x0) {
          iVar2 = -0x3fffff66;
        }
        else {
          iVar2 = RtlCreateAcl(_Dst,uVar3,2);
          if (-1 < iVar2) {
            memmove(_Dst,local_60,(ulonglong)*(ushort *)((longlong)local_60 + 2));
            *(short *)((longlong)_Dst + 2) = (short)uVar3;
            for (uVar3 = 0; uVar3 < 4; uVar3 = uVar3 + 1) {
              iVar2 = RtlAddAccessAllowedAce(_Dst,2,0x20000000);
              if (iVar2 < 0) goto LAB_1400059e9;
            }
            iVar2 = RtlCreateSecurityDescriptor(local_58 + 1,1);
            if (-1 < iVar2) {
              iVar2 = RtlSetDaclSecurityDescriptor(local_58 + 1,1,_Dst,0);
              if (-1 < iVar2) {
                iVar2 = ZwSetSecurityObject(local_68,4,local_58 + 1);
              }
            }
          }
        }
      }
    }
  }
LAB_1400059e9:
  ZwClose(local_68);
  local_68 = 0;
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0x41636c);
  }
  if (local_58[0] != 0) {
    ObReleaseObjectSecurity(local_58[0],(undefined1)local_res20[0]);
  }
  return iVar2;
}



===== NsippCleanupNotification @ 140005a48 =====

undefined4 NsippCleanupNotification(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  longlong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
  local_18 = 0;
  local_38 = 0;
  uStack_30 = 0;
  uVar4 = 0;
  local_28 = 0;
  uStack_20 = 0;
  while( true ) {
    puVar3 = NsippNotificationHandleList;
    if ((undefined8 **)NsippNotificationHandleList == &NsippNotificationHandleList) {
      return uVar4;
    }
    if (((undefined8 **)NsippNotificationHandleList[1] != &NsippNotificationHandleList) ||
       (puVar1 = (undefined8 *)*NsippNotificationHandleList,
       (undefined8 *)puVar1[1] != NsippNotificationHandleList)) break;
    NsippNotificationHandleList = puVar1;
    puVar1[1] = &NsippNotificationHandleList;
    local_38 = puVar3[3];
    uStack_30 = puVar3[4];
    local_28 = puVar3[5];
    uStack_20 = puVar3[6];
    uVar4 = NsiDeregisterChangeNotificationEx(&local_38);
    ExFreePoolWithTag(puVar3,0);
  }
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  return uVar4;
}



===== NsippDeleteDevice @ 140005afc =====

void NsippDeleteDevice(void)

{
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18,L"\\??\\Nsi");
  IoDeleteSymbolicLink(&local_18);
  IoDeleteDevice(NsiProxyDeviceObject);
  NsiProxyDeviceObject = 0;
  if (NsiServiceSecurityDescriptor != 0) {
    ExFreePoolWithTag(NsiServiceSecurityDescriptor,0);
  }
  NsiServiceSecurityDescriptor = 0;
  return;
}



===== NsippEnumerateObjectsAllPersistentParametersWithMask @ 140005b7c =====

int NsippEnumerateObjectsAllPersistentParametersWithMask
              (longlong *param_1,uint param_2,char param_3,undefined8 *param_4)

{
  uint *puVar1;
  bool bVar2;
  longlong lVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  longlong *plVar7;
  undefined8 uVar8;
  longlong *plVar9;
  uint uVar10;
  longlong local_e0;
  longlong *local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  void *local_b0;
  undefined8 uStack_a8;
  void *local_a0;
  void *pvStack_98;
  undefined8 local_90;
  longlong local_88;
  undefined4 local_80;
  ulonglong local_78;
  undefined4 local_70;
  undefined4 local_68;
  ulonglong local_60;
  undefined4 local_58;
  ulonglong local_50;
  ulonglong local_48;
  undefined4 local_40;
  uint local_38;
  
  local_d8 = (longlong *)0x0;
  local_e0 = 0;
  plVar9 = (longlong *)0x0;
  bVar2 = false;
  local_b0 = (void *)0x0;
  uStack_a8 = 0;
  local_b8 = 0;
  local_c0 = 0;
  local_d0 = 0;
  local_a0 = (void *)0x0;
  pvStack_98 = (void *)0x0;
  local_90 = 0;
  local_c8 = 0;
  uVar8 = 0x58;
  memset(&local_88,0,0x58);
  cVar4 = IoIs32bitProcess(0);
  if (param_1 == (longlong *)0x0) {
LAB_140005f61:
    iVar5 = -0x3ffffff3;
  }
  else {
    if (cVar4 == '\0') {
      if (param_2 < 0x58) goto LAB_140005f61;
      local_d8 = param_1;
      NsippProbeForWrite((longlong)param_1,(ulonglong)param_2,uVar8,param_3);
      uVar10 = *(uint *)(param_1 + 10);
      plVar7 = param_1;
    }
    else {
      if (param_2 < 0x2c) goto LAB_140005f61;
      bVar2 = true;
      NsippProbeForWrite((longlong)param_1,(ulonglong)param_2,uVar8,param_3);
      local_68 = (undefined4)param_1[2];
      uVar10 = *(uint *)(param_1 + 5);
      local_60 = (ulonglong)*(uint *)((longlong)param_1 + 0x14);
      local_58 = (undefined4)param_1[3];
      local_78 = (ulonglong)*(uint *)(param_1 + 1);
      local_80 = *(undefined4 *)((longlong)param_1 + 4);
      local_70 = *(undefined4 *)((longlong)param_1 + 0xc);
      local_48 = (ulonglong)*(uint *)(param_1 + 4);
      local_50 = (ulonglong)*(uint *)((longlong)param_1 + 0x1c);
      local_40 = *(undefined4 *)((longlong)param_1 + 0x24);
      local_88 = (longlong)(int)*param_1;
      local_d8 = &local_88;
      plVar7 = local_d8;
      plVar9 = param_1;
      local_38 = uVar10;
    }
    iVar5 = NsippProbeAndAllocateParameters
                      (plVar7,0x58,(longlong)(plVar7 + 1),(undefined4 *)(plVar7 + 5),0,
                       (undefined4 *)0x0,(undefined8 *)0x0,plVar7 + 7,param_3,uVar10,'\0',&local_b0,
                       &local_d0,(undefined8 *)0x0,(uint *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,
                       (undefined8 *)0x0,&local_a0,&local_b8,&local_c0,(undefined8 *)0x0,
                       (undefined8 *)0x0,&local_c8,&local_e0);
    lVar3 = local_e0;
    if (-1 < iVar5) {
      puVar1 = (uint *)(local_e0 + 0x50);
      *puVar1 = uVar10;
      *(undefined8 *)(local_e0 + 0x28) = local_d0;
      *(uint *)(local_e0 + 0x30) = -(uint)(uVar10 != 0) & (uint)uStack_a8;
      *(undefined8 *)(local_e0 + 0x10) = local_c8;
      *(undefined8 *)(local_e0 + 0x40) = local_c0;
      *(undefined8 *)(local_e0 + 0x38) = local_b8;
      uVar6 = -(uint)(uVar10 != 0) & (uint)local_90;
      *(uint *)(local_e0 + 0x48) = uVar6;
      iVar5 = NsiEnumerateObjectsAllPersistentParametersWithMask
                        (*(undefined4 *)(local_e0 + 0x20),*(undefined8 *)(local_e0 + 0x10),
                         *(undefined4 *)(local_e0 + 0x18),*(undefined8 *)(local_e0 + 0x28),
                         *(undefined4 *)(local_e0 + 0x30),*(undefined8 *)(local_e0 + 0x38),
                         *(undefined8 *)(local_e0 + 0x40),uVar6,puVar1);
      if (bVar2) {
        *(uint *)(plVar9 + 5) = *puVar1;
      }
      else {
        *(uint *)(plVar7 + 10) = *puVar1;
      }
      if (-1 < iVar5) {
        *param_4 = 0x58;
        if ((*(void **)(lVar3 + 0x28) != (void *)0x0) && (*(int *)(lVar3 + 0x30) != 0)) {
          memmove(local_b0,*(void **)(lVar3 + 0x28),(ulonglong)(*(int *)(lVar3 + 0x30) * uVar10));
        }
        if ((*(void **)(lVar3 + 0x38) != (void *)0x0) && (*(int *)(lVar3 + 0x48) != 0)) {
          memmove(local_a0,*(void **)(lVar3 + 0x38),(ulonglong)(*(int *)(lVar3 + 0x48) * uVar10));
        }
        if ((*(void **)(lVar3 + 0x40) != (void *)0x0) && (*(int *)(lVar3 + 0x48) != 0)) {
          memmove(pvStack_98,*(void **)(lVar3 + 0x40),(ulonglong)(*(int *)(lVar3 + 0x48) * uVar10));
        }
      }
    }
    if (lVar3 != 0) {
      ExFreePoolWithTag(lVar3,0);
    }
  }
  return iVar5;
}



===== NsippSetAllPersistentParametersWithMask @ 140005f8c =====

int NsippSetAllPersistentParametersWithMask(longlong *param_1,uint param_2,char param_3)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  longlong local_res20;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88 [2];
  ulonglong local_78;
  longlong local_68;
  undefined4 local_60;
  ulonglong local_58;
  undefined4 local_50;
  undefined4 local_48;
  ulonglong local_40;
  undefined4 local_38;
  ulonglong local_30;
  ulonglong local_28;
  undefined4 local_20;
  longlong *local_18;
  
  local_res20 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = 0;
  local_a8 = 0;
  local_b8 = 0;
  local_78 = 0;
  local_b0 = 0;
  memset(&local_68,0,0x50);
  cVar2 = IoIs32bitProcess(0);
  if (param_1 == (longlong *)0x0) {
LAB_140006230:
    iVar3 = -0x3ffffff3;
  }
  else {
    if (cVar2 == '\0') {
      if (param_2 < 0x50) goto LAB_140006230;
    }
    else {
      if (param_2 < 0x28) goto LAB_140006230;
      NsippProbeForRead((longlong)param_1,(ulonglong)param_2);
      local_48 = (undefined4)param_1[2];
      local_40 = (ulonglong)*(uint *)((longlong)param_1 + 0x14);
      local_38 = (undefined4)param_1[3];
      local_58 = (ulonglong)*(uint *)(param_1 + 1);
      local_60 = *(undefined4 *)((longlong)param_1 + 4);
      local_50 = *(undefined4 *)((longlong)param_1 + 0xc);
      local_28 = (ulonglong)*(uint *)(param_1 + 4);
      local_30 = (ulonglong)*(uint *)((longlong)param_1 + 0x1c);
      local_20 = *(undefined4 *)((longlong)param_1 + 0x24);
      local_68 = (longlong)(int)*param_1;
      param_1 = &local_68;
      local_18 = param_1;
    }
    iVar3 = NsippProbeAndAllocateParameters
                      (param_1,0x50,(longlong)(param_1 + 1),(undefined4 *)(param_1 + 5),0,
                       (undefined4 *)0x0,(undefined8 *)0x0,param_1 + 7,param_3,1,'\x01',&local_98,
                       &local_b8,(undefined8 *)0x0,(uint *)0x0,(undefined8 *)0x0,(undefined8 *)0x0,
                       (undefined8 *)0x0,local_88,&local_a0,&local_a8,(undefined8 *)0x0,
                       (undefined8 *)0x0,&local_b0,&local_res20);
    lVar1 = local_res20;
    if (-1 < iVar3) {
      *(undefined8 *)(local_res20 + 0x28) = local_b8;
      *(undefined4 *)(local_res20 + 0x30) = (undefined4)uStack_90;
      *(undefined8 *)(local_res20 + 0x10) = local_b0;
      *(undefined8 *)(local_res20 + 0x40) = local_a8;
      *(undefined8 *)(local_res20 + 0x38) = local_a0;
      *(int *)(local_res20 + 0x48) = (int)local_78;
      iVar3 = NsiSetAllPersistentParametersWithMask
                        (*(undefined4 *)(local_res20 + 0x20),*(undefined8 *)(local_res20 + 0x10),
                         *(undefined4 *)(local_res20 + 0x18),*(undefined8 *)(local_res20 + 0x28),
                         *(undefined4 *)(local_res20 + 0x30),*(undefined8 *)(local_res20 + 0x38),
                         *(undefined8 *)(local_res20 + 0x40),local_78 & 0xffffffff);
    }
    if (lVar1 != 0) {
      ExFreePoolWithTag(lVar1,0);
    }
  }
  return iVar3;
}



===== WdmlibRtlInitUnicodeStringEx @ 140006258 =====

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



===== _guard_check_icall @ 1400062b0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1400062c8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1400062ec =====

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



===== __cpu_features_init @ 140006360 =====

/* WARNING: Removing unreachable block (ram,0x0001400063ca) */
/* WARNING: Removing unreachable block (ram,0x000140006379) */
/* WARNING: Removing unreachable block (ram,0x00014000636a) */

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



===== __security_check_cookie @ 140006430 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 140006470 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1400064a0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001400064a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1400064d0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 140006520 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_140006563;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_1400065d4;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_1400065d0:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400065d4;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_1400065cc:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400065d0;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_1400065cc;
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
LAB_1400065d4:
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
LAB_140006563:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 140006640 =====

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



===== memset @ 140006940 =====

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



===== __memset_repmovs @ 140006a80 =====

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



===== __memset_query @ 140006b00 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 140006b80 =====

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



===== __memset_spec_ermsb_repmovsb @ 140006cc0 =====

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



===== __memset_spec_plain @ 140006d40 =====

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



===== WdmlibIoCreateDeviceSecure @ 14000d010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WdmlibIoCreateDeviceSecure(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 in_stack_00000038;
  
  if (WdmlibInitialized == '\0') {
    WdmlibInit();
  }
  (*PfnIoCreateDeviceSecure)
            (param_1,0,param_3,0x12,0x100,0,in_stack_00000038,0,&NsiProxyDeviceObject);
  return;
}



===== NsippUnload @ 14000d090 =====

void NsippUnload(void)

{
  DrvInitializeAllowUnloadEvent();
  DrvDereferenceDriver();
  NsippCleanupNotification();
  DrvWaitForAllowUnloadEvent();
  NsippDeleteDevice();
  return;
}



===== WdmlibInit @ 14000d0bc =====

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



===== IoDevObjCreateDeviceSecure @ 14000d150 =====

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
    if ((int)uVar5 < 0) goto LAB_14000d2b0;
    uVar6 = 2;
    local_68 = CONCAT44(local_68._4_4_,2);
    lStack_60 = local_res18;
    if (param_8 != (uint *)0x0) {
      local_50 = 2;
      local_40 = 0;
      local_48 = local_res18;
      uVar5 = PpRegStateUpdateStackCreationSettings(param_8,(longlong)&local_50);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 < 0) goto LAB_14000d2b0;
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
LAB_14000d2b0:
  if ((uVar6 & 2) != 0) {
    ExFreePoolWithTag(lStack_60,0);
  }
  return uVar4;
}



===== IopDevObjApplyPostCreationSettings @ 14000d2e4 =====

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



===== SeSddlSecurityDescriptorFromSDDL @ 14000d3d4 =====

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
    memmove(_Dst,_Src,(ulonglong)*param_1);
    _Dst[*param_1 >> 1] = 0;
    uVar2 = SepSddlSecurityDescriptorFromSDDLString(_Dst,(uint)_Src,param_3);
    uVar2 = uVar2 & 0xffffffff;
    ExFreePoolWithTag(_Dst,0);
  }
  return uVar2;
}



===== SepSddlAddAceToAcl @ 14000d4b4 =====

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
    memmove(_Dst,(void *)*param_1,(ulonglong)uVar1);
    *(short *)((longlong)_Dst + 2) = (short)uVar5;
    ExFreePoolWithTag(pvVar2,0);
    *param_1 = (longlong)_Dst;
  }
  *param_2 = uVar6;
  uVar4 = RtlAddAccessAllowedAce(_Dst,2,param_5,param_7);
  return uVar4;
}



===== SepSddlDaclFromSDDLString @ 14000d5b4 =====

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



===== SepSddlGetAclForString @ 14000d6a0 =====

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
LAB_14000d9c4:
            iVar5 = -0x3ffffff3;
LAB_14000d9c6:
            lVar7 = *param_2;
            goto LAB_14000d9d2;
          }
          for (pwVar6 = param_1 + 2; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
          }
          if (*pwVar6 != L';') goto LAB_14000d9c4;
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
              if (local_58 == pwVar6) goto LAB_14000d9c4;
              uVar11 = (uint)local_res8;
            }
            else {
              local_res8 = (short *)CONCAT44(local_res8._4_4_,uVar11 | local_res18[0]);
              uVar11 = uVar11 | local_res18[0];
            }
            pwVar6 = local_58;
          }
          pwVar6 = pwVar6 + 1;
          if (iVar5 != 0) goto LAB_14000d9c6;
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
          if (iVar5 != 0) goto LAB_14000d9c6;
          for (; *pwVar6 == L' '; pwVar6 = pwVar6 + 1) {
          }
          local_res8 = (short *)0x0;
          ppsVar13 = &local_res8;
          uVar9 = SepSddlGetSidForString(pwVar6,local_50,(longlong *)ppsVar13);
          iVar5 = (int)uVar9;
          if (iVar5 != 0) break;
          psVar12 = local_res8;
          if (local_res8 == (short *)0x0) {
LAB_14000d95e:
            iVar5 = -0x3fffff89;
            goto LAB_14000d9c6;
          }
          for (; *psVar12 == 0x20; psVar12 = psVar12 + 1) {
          }
          if (*psVar12 != 0x29) goto LAB_14000d95e;
          param_1 = psVar12 + 1;
          if (local_50[0] != 0) {
            uVar9 = SepSddlAddAceToAcl(param_2,local_res20,ppsVar13,uVar14,uVar11,
                                       uVar15 - local_res10,local_50[0]);
            iVar5 = (int)uVar9;
            if (iVar5 != 0) goto LAB_14000d9c6;
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
LAB_14000d9d2:
        ExFreePoolWithTag(lVar7,0);
        *param_2 = 0;
        return iVar5;
      }
    }
    iVar5 = -0x3fffff66;
  }
  return iVar5;
}



===== SepSddlGetSidForString @ 14000da10 =====

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
LAB_14000dab8:
      *param_2 = uVar5;
      return uVar4;
    }
    uVar3 = (ulonglong)uVar6;
    iVar2 = _wcsnicmp(param_1,(wchar_t *)(&DAT_14000a09c + uVar3 * 0x18),
                      (ulonglong)*(uint *)(&DAT_14000a0a4 + uVar3 * 0x18));
    if (iVar2 == 0) {
      iVar2 = *(int *)(&DAT_14000a098 + uVar3 * 0x18);
      uVar6 = *(uint *)(&DAT_14000a0a4 + uVar3 * 0x18);
      *param_3 = (longlong)(param_1 + uVar6);
      if (iVar2 == 1) {
        cVar1 = IoIsWdmVersionAvailable(1,CONCAT71((int7)((ulonglong)(param_1 + uVar6) >> 8),0x20));
        if (cVar1 != '\0') goto code_r0x00014000da9d;
      }
      else {
code_r0x00014000da9d:
        uVar5 = *(undefined8 *)
                 (*(longlong *)(&DAT_14000a090 + uVar3 * 0x18) + *(longlong *)SeExports_exref);
      }
      uVar4 = 0;
      goto LAB_14000dab8;
    }
    uVar6 = uVar6 + 1;
  } while( true );
}



===== SepSddlLookupAccessMaskInTable @ 14000dae4 =====

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
    iVar1 = _wcsnicmp(param_1,(wchar_t *)(&PTR_u_RC_14000a000)[uVar3 * 2],
                      (ulonglong)(uint)(&DAT_14000a008)[uVar3 * 4]);
    if (iVar1 == 0) break;
    uVar2 = uVar2 + 1;
  }
  *param_2 = (&DAT_14000a00c)[uVar3 * 4];
  *param_3 = (longlong)(param_1 + (uint)(&DAT_14000a008)[uVar3 * 4]);
  return 1;
}



===== SepSddlParseWideStringUlong @ 14000db7c =====

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
LAB_14000dbe9:
      iVar6 = 10;
      goto LAB_14000dbc0;
    }
    param_1 = param_1 + 2;
  }
  else if ((ushort)(uVar1 - 0x30) < 10) goto LAB_14000dbe9;
  iVar6 = 0x10;
LAB_14000dbc0:
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
    if (uVar5 < uVar7) goto LAB_14000dc2d;
    uVar7 = uVar5;
  }
  if (puVar4 == param_1) {
LAB_14000dc2d:
    uVar3 = 0;
  }
  else {
    *param_2 = puVar4;
    uVar3 = 1;
    *param_3 = uVar7;
  }
  return uVar3;
}



===== SepSddlSecurityDescriptorFromSDDLString @ 14000dc54 =====

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
        goto LAB_14000dd99;
      }
    }
  }
  if (local_58[0] != 0) {
    ExFreePoolWithTag(local_58[0],0);
  }
  if (_Dst != (void *)0x0) {
    ExFreePoolWithTag(_Dst,0);
  }
LAB_14000dd99:
  return (ulonglong)uVar2;
}



===== PiRegStateOpenClassKey @ 14000ddf8 =====

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
  uVar3 = CmRegUtilOpenExistingWstrKey(0,0x140008500,0x20019,&local_b0);
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



===== PiRegStateReadStackCreationSettingsFromKey @ 14000df94 =====

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
  uVar2 = WdmlibRtlInitUnicodeStringEx((short *)local_50,0x140008480);
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
      if ((int)uVar3 < 0) goto LAB_14000e113;
      if (local_res10[0] == '\0') {
        *param_2 = *param_2 | 2;
        *(longlong *)(param_2 + 2) = local_res20;
      }
      else {
        ExFreePoolWithTag(local_res20,0);
      }
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x140008498,param_3,param_2 + 1);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_14000e113;
    }
    else {
      *param_2 = *param_2 | 1;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1400084b0,param_3,param_2 + 4);
    uVar5 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) {
      if ((int)uVar3 != -0x3fffffcc) goto LAB_14000e113;
    }
    else {
      *param_2 = *param_2 | 4;
    }
    uVar3 = CmRegUtilWstrValueGetDword(param_1,0x1400084e0,param_3,param_2 + 5);
    uVar5 = uVar3 & 0xffffffff;
    if (-1 < (int)uVar3) {
      *param_2 = *param_2 | 8;
      return uVar5;
    }
    if ((int)uVar3 == -0x3fffffcc) {
      return 0;
    }
  }
LAB_14000e113:
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



===== PpRegStateReadCreateClassCreationSettings @ 14000e158 =====

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
    uVar1 = CmRegUtilOpenExistingWstrKey(local_res20,0x140008420,0x20019,puVar6);
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
      uVar3 = WdmlibRtlInitUnicodeStringEx((short *)&local_18,0x140008438);
      uVar2 = uVar3 & 0xffffffff;
      if (-1 < (int)uVar3) {
        uVar1 = CmRegUtilUcValueSetUcString(uVar4,&local_18,puVar7);
        uVar2 = (ulonglong)uVar1;
        if (-1 < (int)uVar1) {
          local_res18[0] = 0x31;
          uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x140008448,(longlong)local_res18);
          uVar2 = (ulonglong)uVar1;
          if (-1 < (int)uVar1) {
            uVar1 = CmRegUtilWstrValueSetWstrString(uVar4,0x140008468,(longlong)local_res18);
            uVar2 = (ulonglong)uVar1;
          }
        }
      }
    }
  }
  ZwClose(uVar4);
  return uVar2;
}



===== PpRegStateUpdateStackCreationSettings @ 14000e2bc =====

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
                      (local_res20,0x140008420,uVar7,uVar8,puVar6,(undefined4 *)0x0,&local_38);
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
      uVar5 = WdmlibRtlInitUnicodeStringEx(local_30,0x140008480);
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



===== SeUtilSecurityInfoFromSecurityDescriptor @ 14000e424 =====

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



===== CmRegUtilCreateUcKey @ 14000e520 =====

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



===== CmRegUtilCreateWstrKey @ 14000e5c8 =====

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



===== CmRegUtilOpenExistingWstrKey @ 14000e628 =====

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



===== CmRegUtilUcValueGetFullBuffer @ 14000e6bc =====

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
    if (iVar1 < 0) goto LAB_14000e7f4;
  }
  if (*(int *)((longlong)_Dst + 4) == 3) {
    *param_5 = _Dst;
    return 0;
  }
  iVar1 = -0x3fffffdc;
LAB_14000e7f4:
  ExFreePoolWithTag(_Dst,0);
  return iVar1;
}



===== CmRegUtilUcValueSetUcString @ 14000e838 =====

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
      memmove(local_20,*(void **)(param_3 + 4),(ulonglong)local_28);
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



===== CmRegUtilWstrValueGetDword @ 14000e984 =====

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



===== CmRegUtilWstrValueSetWstrString @ 14000ea28 =====

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



===== entry @ 14000f010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 14000f044 =====

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



===== DriverEntry @ 14000f078 =====

int DriverEntry(longlong param_1)

{
  int iVar1;
  
  *(code **)(param_1 + 0x68) = NsippUnload;
  iVar1 = NsippCreateDevice(param_1);
  if (-1 < iVar1) {
    LOCK();
    DrvpReferenceCount = DrvpReferenceCount + 1;
    UNLOCK();
    DAT_14000a2a8 = &NsippNotificationHandleList;
    NsippNotificationHandleList = &NsippNotificationHandleList;
    KeInitializeSpinLock(&NsippNotificationHandleListLock);
  }
  return iVar1;
}


