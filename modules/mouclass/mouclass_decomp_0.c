
===== _tlgKeywordOn @ 1c0001008 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong _tlgKeywordOn(void)

{
  ulonglong in_RAX;
  
  if (((_DAT_1c000b010 & 0x400000000000) == 0) ||
     (in_RAX = DAT_1c000b018 & 0x400000000000, in_RAX != DAT_1c000b018)) {
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
  *param_6 = PTR_DAT_1c000b008;
  *(uint *)(param_6 + 1) = (uint)*(ushort *)PTR_DAT_1c000b008;
  param_6[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)param_6 + 0xc) = 2;
  *(uint *)(param_6 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)param_6 + 0x1c) = 1;
  EtwWriteTransfer(DAT_1c000b020,&local_18,0,0,param_5,param_6);
  return;
}



===== MouseClassPower @ 1c00010f0 =====

/* WARNING: Type propagation algorithm not settling */

int MouseClassPower(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  int iVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  bool bVar6;
  bool bVar7;
  undefined1 uVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined8 in_stack_ffffffffffffffa8;
  undefined8 uVar13;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  puVar4 = *(undefined8 **)(param_1 + 0x40);
  bVar6 = true;
  iVar11 = *(int *)(lVar3 + 0x10);
  iVar2 = *(int *)(lVar3 + 0x18);
  if ((puVar4 == Globals) || (*(char *)(puVar4 + 8) == '\0')) {
    PoStartNextPowerIrp(param_2);
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    IofCompleteRequest(param_2,0);
    return -0x3fffff45;
  }
  uVar13 = CONCAT44((int)((ulonglong)in_stack_ffffffffffffffa8 >> 0x20),0x20);
  iVar10 = IoAcquireRemoveLockEx(puVar4 + 4,param_2,"",1);
  if (iVar10 < 0) {
    PoStartNextPowerIrp(param_2);
    *(int *)(param_2 + 0x30) = iVar10;
    IofCompleteRequest(param_2,0);
    return iVar10;
  }
  cVar9 = *(char *)(lVar3 + 1);
  if (cVar9 == '\x02') {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqsd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    uVar12 = (undefined4)((ulonglong)uVar13 >> 0x20);
    if (iVar11 == 0) {
      if (*(int *)(puVar4 + 0x16) < iVar2) {
        iVar11 = IoAcquireRemoveLockEx(puVar4 + 4,param_2,"",1,CONCAT44(uVar12,0x20));
        if (-1 < iVar11) {
          uVar8 = KeAcquireSpinLockRaiseToDpc(puVar4 + 9);
          if ((puVar4[0x23] == 0) || (*(char *)(puVar4 + 0x24) != '\0')) {
            KeReleaseSpinLock(puVar4 + 9,uVar8);
LAB_1c0001458:
            uVar12 = 4;
          }
          else {
            KeReleaseSpinLock(puVar4 + 9,uVar8);
            if (4 < iVar2) goto LAB_1c0001458;
            uVar12 = *(undefined4 *)((longlong)puVar4 + (longlong)iVar2 * 4 + 0xf8);
          }
          pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
          *pbVar1 = *pbVar1 | 1;
          iVar11 = PoRequestPowerIrp(*puVar4,2,uVar12,MouseClassPoRequestComplete,param_2,0);
          if (iVar11 < 0) {
            IoReleaseRemoveLockEx(puVar4 + 4,param_2,0x20);
            PoStartNextPowerIrp(param_2);
            *(int *)(param_2 + 0x30) = iVar11;
            IofCompleteRequest(param_2,0);
            IoReleaseRemoveLockEx(puVar4 + 4,param_2,0x20);
            return 0x103;
          }
          iVar11 = 0x103;
          goto LAB_1c00012d1;
        }
        goto LAB_1c00012a9;
      }
      if (*(int *)(puVar4 + 0x16) <= iVar2) {
        if (((iVar2 == 1) && (1 < *(int *)((longlong)puVar4 + 0x10c))) &&
           (1 < *(int *)(puVar4 + 0x22))) {
          uVar8 = KeAcquireSpinLockRaiseToDpc(puVar4 + 9);
          if ((puVar4[0x23] == 0) || (*(char *)(puVar4 + 0x24) != '\0')) {
            KeReleaseSpinLock(puVar4 + 9,uVar8);
            cVar9 = MouseClassCheckWaitWakeEnabled((longlong)puVar4);
            if (cVar9 != '\0') {
              MouseClassCreateWaitWakeIrp((longlong)puVar4);
            }
          }
          else {
            KeReleaseSpinLock(puVar4 + 9,uVar8);
          }
        }
        *(undefined4 *)(param_2 + 0x30) = 0;
        goto LAB_1c00011f9;
      }
      *(undefined4 *)(param_2 + 0x30) = 0;
LAB_1c0001327:
      IoAcquireRemoveLockEx(puVar4 + 4,param_2,"",1,CONCAT44(uVar12,0x20));
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
      lVar3 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar3 + -0x10) = MouseClassPowerComplete;
      *(undefined8 *)(lVar3 + -8) = 0;
      *(undefined1 *)(lVar3 + -0x45) = 0xe0;
      pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      PoCallDriver(puVar4[2],param_2);
      iVar11 = 0x103;
    }
    else {
      if (iVar11 == 1) {
        *(undefined4 *)(param_2 + 0x30) = 0;
        if (*(int *)((longlong)puVar4 + 0xac) < iVar2) {
          PoSetPowerState(*puVar4,1,iVar2);
          *(int *)((longlong)puVar4 + 0xac) = iVar2;
        }
        else if (iVar2 < *(int *)((longlong)puVar4 + 0xac)) goto LAB_1c0001327;
      }
LAB_1c00011f9:
      PoStartNextPowerIrp(param_2);
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      iVar11 = PoCallDriver(puVar4[2],param_2);
    }
  }
  else {
    if (cVar9 == '\0') {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,5,0x5b,uVar13,(char)param_1,
                           (char)param_2);
      }
      uVar12 = (undefined4)((ulonglong)uVar13 >> 0x20);
      uVar8 = KeAcquireSpinLockRaiseToDpc(puVar4 + 9);
      if (puVar4[0x23] == 0) {
        puVar4[0x23] = param_2;
        *(undefined1 *)(puVar4 + 0x24) = 0;
        LOCK();
        iVar11 = *(int *)(puVar4 + 0x26);
        *(int *)(puVar4 + 0x26) = 0;
        UNLOCK();
        if (iVar11 - 1U < 2) goto LAB_1c0001283;
        iVar11 = 0;
        bVar6 = true;
      }
      else {
        puVar4[0x25] = param_2;
LAB_1c0001283:
        bVar6 = false;
        iVar11 = -0x3ffffe7c;
      }
      KeReleaseSpinLock(puVar4 + 9,uVar8);
      bVar7 = bVar6;
    }
    else {
      if (cVar9 != '\x03') goto LAB_1c00011f9;
      iVar11 = 0;
      if ((iVar2 < 5) && (*(int *)(puVar4 + 0x22) < iVar2)) {
        uVar8 = KeAcquireSpinLockRaiseToDpc(puVar4 + 9);
        uVar12 = (undefined4)((ulonglong)uVar13 >> 0x20);
        if ((puVar4[0x23] == 0) || (*(char *)(puVar4 + 0x24) != '\0')) {
          KeReleaseSpinLock(puVar4 + 9,uVar8);
          goto LAB_1c0001509;
        }
        KeReleaseSpinLock(puVar4 + 9,uVar8);
        iVar11 = -0x3ffffd2d;
        *(undefined4 *)(param_2 + 0x30) = 0xc00002d3;
        bVar7 = false;
      }
      else {
LAB_1c0001509:
        uVar12 = (undefined4)((ulonglong)uVar13 >> 0x20);
        *(undefined4 *)(param_2 + 0x30) = 0;
        bVar7 = false;
      }
    }
    if (-1 < iVar11) {
      if (bVar7) goto LAB_1c0001327;
      goto LAB_1c00011f9;
    }
LAB_1c00012a9:
    *(int *)(param_2 + 0x30) = iVar11;
    PoStartNextPowerIrp(param_2);
    IofCompleteRequest(param_2,0);
  }
  if (!bVar6) {
    return iVar11;
  }
LAB_1c00012d1:
  IoReleaseRemoveLockEx(puVar4 + 4,param_2,0x20);
  return iVar11;
}



===== WPP_RECORDER_SF_qqsd @ 1c00016e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqsd(undefined8 param_1)

{
  char *pcVar1;
  longlong lVar2;
  longlong lVar3;
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  char *in_stack_00000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    if (in_stack_00000040 == (char *)0x0) {
      lVar2 = 5;
    }
    else {
      lVar3 = -1;
      do {
        lVar2 = lVar3;
        lVar3 = lVar2 + 1;
      } while (in_stack_00000040[lVar3] != '\0');
      lVar2 = lVar2 + 2;
    }
    pcVar1 = in_stack_00000040;
    if (in_stack_00000040 == (char *)0x0) {
      pcVar1 = "NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x5a,&uStack0000000000000030,8,
               &uStack0000000000000038,8,pcVar1,lVar2,&uStack0000000000000048,4,0);
  }
  lVar2 = -1;
  if (in_stack_00000040 == (char *)0x0) {
    lVar3 = 5;
  }
  else {
    do {
      lVar3 = lVar2;
      lVar2 = lVar3 + 1;
    } while (in_stack_00000040[lVar2] != '\0');
    lVar3 = lVar3 + 2;
  }
  if (in_stack_00000040 == (char *)0x0) {
    in_stack_00000040 = "NULL";
  }
  WppAutoLogTrace(param_1,4,6,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x5a,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,in_stack_00000040,lVar3,
                  &uStack0000000000000048,4,0);
  return;
}



===== MouseClassServiceCallback @ 1c00018a0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void MouseClassServiceCallback(longlong param_1,longlong *param_2,undefined **param_3,int *param_4)

{
  undefined8 *puVar1;
  longlong lVar2;
  void *pvVar3;
  longlong *plVar4;
  ulonglong uVar5;
  code *pcVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  int iVar9;
  ulonglong uVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  undefined1 *puVar14;
  uint uVar15;
  undefined **ppuVar16;
  uint uVar17;
  longlong *plVar18;
  undefined **_Size;
  longlong lVar19;
  uint uVar20;
  undefined1 auStack_98 [40];
  longlong local_70;
  longlong *local_68;
  uint local_60;
  uint local_58;
  longlong *local_50;
  longlong local_48;
  undefined8 ****local_38;
  undefined8 ****local_30;
  
  ppuVar16 = &WPP_RECORDER_INITIALIZED;
  _Size = param_3;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    _Size = (undefined **)0x3;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x32);
  }
  puVar1 = *(undefined8 **)(param_1 + 0x40);
  uVar20 = 0;
  uVar17 = (int)param_3 - (int)param_2;
  plVar18 = (longlong *)(ulonglong)uVar17;
  *param_4 = 0;
  KeAcquireSpinLockAtDpcLevel(puVar1 + 0x12);
  local_30 = &local_38;
  plVar11 = puVar1 + 0x13;
  local_38 = &local_38;
  do {
    plVar12 = (longlong *)0x0;
LAB_1c000192d:
    plVar13 = (longlong *)*plVar11;
    if (plVar13 == plVar11) goto LAB_1c000196e;
    puVar14 = auStack_98;
    lVar19 = param_1;
    if ((longlong *)plVar13[1] != plVar11) goto LAB_1c0001d44;
    lVar2 = *plVar13;
    puVar14 = auStack_98;
    if (*(longlong **)(lVar2 + 8) != plVar13) goto LAB_1c0001d44;
    *plVar11 = lVar2;
    plVar12 = plVar13 + -0x15;
    *(longlong **)(lVar2 + 8) = plVar11;
    LOCK();
    lVar19 = plVar13[-8];
    plVar13[-8] = 0;
    UNLOCK();
    if (lVar19 != 0) break;
    plVar13[1] = (longlong)plVar13;
    *plVar13 = (longlong)plVar13;
  } while( true );
  if (plVar12 != (longlong *)0x0) {
LAB_1c000196e:
    puVar14 = auStack_98;
    if (plVar12 == (longlong *)0x0) goto LAB_1c0001a34;
    lVar19 = plVar12[0x17];
    uVar15 = *(uint *)(lVar19 + 8);
    uVar20 = uVar15;
    if (uVar17 < uVar15) {
      uVar20 = uVar17;
    }
    ppuVar16 = (undefined **)(ulonglong)uVar20;
    *param_4 = *param_4 + uVar20 / 0x18;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      local_48 = plVar12[3];
      local_70 = param_1;
      local_68 = plVar12;
      local_60 = uVar17;
      local_58 = uVar15;
      local_50 = param_2;
      WPP_RECORDER_SF_qqLLqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    uVar8 = _DAT_fffff78000000014;
    plVar13 = plVar12;
    puVar14 = auStack_98;
    puVar7 = auStack_98;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) goto LAB_1c0001d4b;
    goto LAB_1c00019d9;
  }
  goto LAB_1c000192d;
LAB_1c00019d9:
  uVar17 = (uint)plVar18;
  pvVar3 = (void *)plVar13[3];
  *(undefined8 *)(puVar14 + -8) = 0x1c00019e8;
  plVar11 = param_2;
  _Size = ppuVar16;
  memcpy(pvVar3,param_2,(size_t)ppuVar16);
  *(undefined4 *)(plVar13 + 6) = 0;
  plVar13[7] = (longlong)ppuVar16;
  plVar12 = plVar13 + 0x15;
  *(uint *)(lVar19 + 8) = uVar20;
  plVar4 = *(longlong **)(puVar14 + 0x68);
  if ((undefined1 *)*plVar4 == puVar14 + 0x60) {
    param_1 = *(longlong *)(puVar14 + 0xa0);
    *plVar12 = (longlong)(puVar14 + 0x60);
    plVar13[0x16] = (longlong)plVar4;
    *plVar4 = (longlong)plVar12;
    *(longlong **)(puVar14 + 0x68) = plVar12;
LAB_1c0001a34:
    param_2 = (longlong *)((longlong)param_2 + (ulonglong)uVar20);
    uVar17 = uVar17 - uVar20;
    plVar18 = (longlong *)(ulonglong)uVar17;
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      *(uint *)(puVar14 + 0x30) = uVar17;
      *(longlong *)(puVar14 + 0x28) = param_1;
      *(undefined8 *)(puVar14 + -8) = 0x1c0001ba4;
      WPP_RECORDER_SF_qL(uVar8);
    }
    if (uVar17 != 0) {
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        iVar9 = *(int *)((longlong)puVar1 + 0x54);
        uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        *(uint *)(puVar14 + 0x38) = uVar17;
        plVar11 = (longlong *)(ulonglong)(uint)(iVar9 * 0x18);
        *(int *)(puVar14 + 0x30) = *(int *)(puVar1 + 0x11) + iVar9 * -0x18;
        *(longlong *)(puVar14 + 0x28) = param_1;
        *(undefined8 *)(puVar14 + -8) = 0x1c0001dbb;
        WPP_RECORDER_SF_qLL(uVar8,plVar11,_Size,0x36,*(undefined8 *)(puVar14 + 0x20),puVar14[0x28],
                            puVar14[0x30],puVar14[0x38]);
      }
      uVar15 = *(uint *)(puVar1 + 0x11);
      if (uVar15 < uVar17) {
        uVar17 = uVar15;
      }
      plVar18 = (longlong *)(ulonglong)uVar17;
      uVar15 = (*(int *)(puVar1 + 0xd) - *(int *)(puVar1 + 0xe)) + uVar15;
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        *(uint *)(puVar14 + 0x38) = uVar15;
        *(uint *)(puVar14 + 0x30) = uVar17;
        *(longlong *)(puVar14 + 0x28) = param_1;
        *(undefined8 *)(puVar14 + -8) = 0x1c0001dee;
        WPP_RECORDER_SF_qLL(uVar8,plVar11,_Size,0x38,*(undefined8 *)(puVar14 + 0x20),puVar14[0x28],
                            puVar14[0x30],puVar14[0x38]);
      }
      if (uVar17 < uVar15) {
        uVar15 = uVar17;
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        *(undefined8 *)(puVar14 + 0x40) = puVar1[0xe];
        *(longlong **)(puVar14 + 0x38) = param_2;
        *(uint *)(puVar14 + 0x30) = uVar15;
        *(longlong *)(puVar14 + 0x28) = param_1;
        *(undefined8 *)(puVar14 + -8) = 0x1c0001e2b;
        WPP_RECORDER_SF_qLqq
                  (uVar8,plVar11,_Size,0x39,*(undefined8 *)(puVar14 + 0x20),puVar14[0x28],
                   puVar14[0x30],puVar14[0x38],puVar14[0x40]);
      }
      pvVar3 = (void *)puVar1[0xe];
      _Size = (undefined **)(ulonglong)uVar15;
      *(undefined8 *)(puVar14 + -8) = 0x1c0001c9e;
      memcpy(pvVar3,param_2,(size_t)_Size);
      param_2 = (longlong *)((longlong)param_2 + (ulonglong)uVar15);
      uVar5 = puVar1[0xd];
      uVar10 = puVar1[0xe] + (ulonglong)uVar15;
      puVar1[0xe] = uVar10;
      if (*(uint *)(puVar1 + 0x11) + uVar5 <= uVar10) {
        puVar1[0xe] = uVar5;
        uVar10 = uVar5;
      }
      uVar15 = uVar17 - uVar15;
      ppuVar16 = (undefined **)(ulonglong)uVar15;
      if (uVar15 != 0) {
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          *(ulonglong *)(puVar14 + 0x40) = uVar10;
          uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
          *(longlong **)(puVar14 + 0x38) = param_2;
          *(uint *)(puVar14 + 0x30) = uVar15;
          *(longlong *)(puVar14 + 0x28) = param_1;
          *(undefined8 *)(puVar14 + -8) = 0x1c0001ea2;
          WPP_RECORDER_SF_qLqq
                    (uVar8,uVar5,_Size,0x3a,*(undefined8 *)(puVar14 + 0x20),puVar14[0x28],
                     puVar14[0x30],puVar14[0x38],puVar14[0x40]);
        }
        pvVar3 = (void *)puVar1[0xe];
        *(undefined8 *)(puVar14 + -8) = 0x1c0001eb1;
        _Size = ppuVar16;
        memcpy(pvVar3,param_2,(size_t)ppuVar16);
        puVar1[0xe] = puVar1[0xe] + (longlong)ppuVar16;
      }
      *(int *)((longlong)puVar1 + 0x54) = *(int *)((longlong)puVar1 + 0x54) + uVar17 / 0x18;
      iVar9 = *param_4 + uVar17 / 0x18;
      *param_4 = iVar9;
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
        *(int *)(puVar14 + 0x48) = iVar9;
        *(undefined8 *)(puVar14 + 0x40) = puVar1[0xf];
        *(undefined8 *)(puVar14 + 0x38) = puVar1[0xe];
        *(undefined4 *)(puVar14 + 0x30) = *(undefined4 *)((longlong)puVar1 + 0x54);
        *(longlong *)(puVar14 + 0x28) = param_1;
        *(undefined8 *)(puVar14 + -8) = 0x1c0001d3f;
        WPP_RECORDER_SF_qlqqd(uVar8);
      }
    }
    ppuVar16 = &WPP_RECORDER_INITIALIZED;
    lVar19 = param_1;
    if (*(int *)((longlong)puVar1 + 0x54) != 0) {
      plVar12 = puVar1 + 0x13;
LAB_1c0001bb0:
      do {
        plVar11 = (longlong *)0x0;
        do {
          plVar13 = (longlong *)*plVar12;
          if (plVar13 == plVar12) break;
          plVar18 = plVar11;
          if (((longlong *)plVar13[1] != plVar12) ||
             (lVar2 = *plVar13, *(longlong **)(lVar2 + 8) != plVar13)) goto LAB_1c0001d44;
          *plVar12 = lVar2;
          plVar11 = plVar13 + -0x15;
          *(longlong **)(lVar2 + 8) = plVar12;
          LOCK();
          lVar2 = plVar13[-8];
          plVar13[-8] = 0;
          UNLOCK();
          if (lVar2 == 0) {
            plVar13[1] = (longlong)plVar13;
            *plVar13 = (longlong)plVar13;
            goto LAB_1c0001bb0;
          }
        } while (plVar11 == (longlong *)0x0);
        plVar18 = plVar11;
        if (plVar11 == (longlong *)0x0) break;
        *(undefined8 *)(puVar14 + -8) = 0x1c0001c07;
        uVar8 = MouseClassReadCopyData(puVar1,(longlong)plVar11,_Size);
        *(int *)(plVar11 + 6) = (int)uVar8;
        plVar13 = *(longlong **)(puVar14 + 0x68);
        plVar18 = plVar11 + 0x15;
        if ((undefined1 *)*plVar13 != puVar14 + 0x60) goto LAB_1c0001d44;
        plVar11[0x16] = (longlong)plVar13;
        *plVar18 = (longlong)(puVar14 + 0x60);
        *plVar13 = (longlong)plVar18;
        *(longlong **)(puVar14 + 0x68) = plVar18;
      } while (*(int *)((longlong)puVar1 + 0x54) != 0);
    }
    *(undefined8 *)(puVar14 + -8) = 0x1c0001a6a;
    KeReleaseSpinLockFromDpcLevel(puVar1 + 0x12);
    while( true ) {
      plVar12 = *(longlong **)(puVar14 + 0x60);
      if (plVar12 == (longlong *)(puVar14 + 0x60)) {
        if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
           (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
          uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
          *(undefined8 *)(puVar14 + -8) = 0x1c0001b32;
          WPP_RECORDER_SF_(uVar8,5,3,0x3c);
        }
        return;
      }
      if (((undefined1 *)plVar12[1] != puVar14 + 0x60) ||
         (lVar2 = *plVar12, *(longlong **)(lVar2 + 8) != plVar12)) break;
      *(longlong *)(puVar14 + 0x60) = lVar2;
      *(undefined1 **)(lVar2 + 8) = puVar14 + 0x60;
      *(undefined8 *)(puVar14 + -8) = 0x1c0001ae4;
      IofCompleteRequest(plVar12 + -0x15,6);
      *(undefined8 *)(puVar14 + -8) = 0x1c0001b01;
      IoReleaseRemoveLockEx(puVar1 + 4,plVar12 + -0x15,0x20);
    }
  }
LAB_1c0001d44:
  pcVar6 = (code *)swi(0x29);
  uVar8 = (*pcVar6)(3);
  plVar13 = plVar12;
  puVar7 = puVar14 + 8;
LAB_1c0001d4b:
  puVar14 = puVar7;
  *(uint *)(puVar14 + 0x40) = uVar20;
  *(undefined8 *)(puVar14 + 0x38) = uVar8;
  uVar8 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
  *(longlong **)(puVar14 + 0x30) = plVar13;
  *(undefined8 *)(puVar14 + 0x28) = *(undefined8 *)(puVar14 + 0xa0);
  *(undefined8 *)(puVar14 + -8) = 0x1c0001d77;
  WPP_RECORDER_SF_qqiL(uVar8);
  goto LAB_1c00019d9;
}



===== MouseClassRead @ 1c0001ed0 =====

ulonglong MouseClassRead(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  undefined8 uVar7;
  code *pcVar8;
  bool bVar9;
  undefined1 uVar10;
  uint uVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  char *pcVar17;
  undefined1 auStackY_68 [8];
  undefined1 auStackY_60 [24];
  undefined4 uVar18;
  undefined4 in_stack_ffffffffffffffbc;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x30);
  }
  puVar13 = auStackY_68;
  puVar14 = auStackY_68;
  puVar12 = auStackY_68;
  puVar4 = *(undefined8 **)(param_1 + 0x40);
  uVar11 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (uVar11 == 0) {
    uVar16 = 0;
    *(undefined4 *)(param_2 + 0x30) = 0;
    puVar12 = auStackY_68;
  }
  else if ((ulonglong)uVar11 == ((ulonglong)uVar11 / 0x18) * 0x18) {
    if (*(char *)((longlong)puVar4 + 0x15a) == '\0') {
      if (*(code **)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x20) == DriverEntry) {
        uVar18 = 0x20;
        pcVar17 = "";
        uVar11 = IoAcquireRemoveLockEx(puVar4 + 4,param_2,"",1);
        uVar16 = (ulonglong)uVar11;
        uVar15 = 0x103;
        if (-1 < (int)uVar11) {
          uVar16 = 0x103;
        }
        *(int *)(param_2 + 0x30) = (int)uVar16;
        *(undefined8 *)(param_2 + 0x38) = 0;
        if ((int)uVar16 != 0x103) goto LAB_1c00020cd;
        bVar9 = false;
        uVar10 = KeAcquireSpinLockRaiseToDpc(puVar4 + 0x12);
        if (*(int *)((longlong)puVar4 + 0x54) != 0) {
          uVar15 = MouseClassReadCopyData(puVar4,param_2,pcVar17);
          *(int *)(param_2 + 0x30) = (int)uVar15;
          uVar15 = uVar15 & 0xffffffff;
          KeReleaseSpinLock(puVar4 + 0x12,uVar10);
          goto LAB_1c00020a1;
        }
        puVar5 = (undefined8 *)puVar4[0x14];
        plVar2 = (longlong *)(param_2 + 0xa8);
        if ((undefined8 *)*puVar5 != puVar4 + 0x13) {
LAB_1c00021e3:
          pcVar8 = (code *)swi(0x29);
          (*pcVar8)(3);
          puVar14 = auStackY_60;
          goto LAB_1c00021ea;
        }
        *plVar2 = (longlong)(puVar4 + 0x13);
        *(undefined8 **)(param_2 + 0xb0) = puVar5;
        *puVar5 = plVar2;
        puVar4[0x14] = plVar2;
        LOCK();
        *(code **)(param_2 + 0x68) = MouseClassCancel;
        UNLOCK();
        if (*(char *)(param_2 + 0x44) == '\0') {
LAB_1c0002027:
          pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
          *pbVar1 = *pbVar1 | 1;
        }
        else {
          LOCK();
          lVar3 = *(longlong *)(param_2 + 0x68);
          *(longlong *)(param_2 + 0x68) = 0;
          UNLOCK();
          if (lVar3 == 0) {
            if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
              WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,3,0x2f,
                                 CONCAT44(in_stack_ffffffffffffffbc,uVar18),(char)*puVar4,
                                 (char)param_2);
            }
            goto LAB_1c0002027;
          }
          lVar3 = *plVar2;
          if ((*(longlong **)(lVar3 + 8) != plVar2) ||
             (plVar6 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar6 != plVar2))
          goto LAB_1c00021e3;
          *plVar6 = lVar3;
          uVar15 = 0xc0000120;
          *(longlong **)(lVar3 + 8) = plVar6;
          *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
          if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
            WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,3,0x2e,
                               CONCAT44(in_stack_ffffffffffffffbc,uVar18),(char)*puVar4,
                               (char)param_2);
          }
          bVar9 = true;
        }
        KeReleaseSpinLock(puVar4 + 0x12,uVar10);
        if (!bVar9) {
          return uVar15;
        }
LAB_1c00020a1:
        IoReleaseRemoveLockEx(puVar4 + 4,param_2,0x20);
        IofCompleteRequest(param_2,0);
        return uVar15;
      }
LAB_1c00021ea:
      uVar16 = 0xc0000061;
      puVar13 = puVar14;
    }
    else {
      uVar16 = 0xc000009d;
    }
    *(int *)(param_2 + 0x30) = (int)uVar16;
    puVar12 = puVar13;
  }
  else {
    uVar16 = 0xc0000023;
    *(undefined4 *)(param_2 + 0x30) = 0xc0000023;
    puVar12 = auStackY_68;
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
LAB_1c00020cd:
  *(undefined8 *)(puVar12 + -8) = 0x1c00020d9;
  IofCompleteRequest(param_2,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar7 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
    *(undefined8 *)(puVar12 + -8) = 0x1c000221b;
    WPP_RECORDER_SF_(uVar7,5,3,0x31);
  }
  return uVar16;
}



===== MouseClassReadCopyData @ 1c0002230 =====

undefined8 MouseClassReadCopyData(undefined8 *param_1,longlong param_2,undefined8 param_3)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  void *_Src;
  ulonglong uVar4;
  void *pvVar5;
  uint uVar6;
  uint uVar7;
  undefined8 in_stack_ffffffffffffffa8;
  undefined1 uVar8;
  
  *(int *)(param_1 + 0x15) = *(int *)(param_1 + 0x15) + 1;
  lVar2 = *(longlong *)(param_2 + 0xb8);
  uVar7 = *(uint *)(lVar2 + 8);
  uVar6 = *(int *)((longlong)param_1 + 0x54) * 0x18;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qqLL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  if (uVar7 <= uVar6) {
    uVar6 = uVar7;
  }
  uVar3 = (*(int *)(param_1 + 0x11) - *(int *)(param_1 + 0xf)) + *(int *)(param_1 + 0xd);
  uVar4 = (ulonglong)uVar3;
  uVar7 = uVar3;
  if (uVar6 < uVar3) {
    uVar7 = uVar6;
  }
  uVar8 = (undefined1)param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar4 = CONCAT71((uint7)(uint3)(uVar3 >> 8),5);
    param_3 = 3;
    WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x29,
                        in_stack_ffffffffffffffa8,(char)*param_1,uVar8,(char)uVar3);
  }
  pvVar5 = *(void **)(param_2 + 0x18);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qqLqq
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,param_3,0x2a,
               in_stack_ffffffffffffffa8,(char)*param_1,uVar8,(char)uVar7,(char)param_1[0xf],
               (char)pvVar5);
  }
  _Src = (void *)param_1[0xf];
  uVar4 = (ulonglong)uVar7;
  memcpy(pvVar5,_Src,uVar4);
  pvVar5 = (void *)((longlong)pvVar5 + (ulonglong)uVar7);
  uVar3 = uVar6 - uVar7;
  if (uVar3 == 0) {
    param_1[0xf] = param_1[0xf] + (ulonglong)uVar7;
  }
  else {
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      WPP_RECORDER_SF_qqLqq
                (*(undefined8 *)(WPP_GLOBAL_Control + 0x40),_Src,uVar4,0x2b,
                 in_stack_ffffffffffffffa8,(char)*param_1,uVar8,(char)uVar3,(char)param_1[0xd],
                 (char)pvVar5);
    }
    memcpy(pvVar5,(void *)param_1[0xd],(ulonglong)uVar3);
    param_1[0xf] = param_1[0xd] + (ulonglong)uVar3;
  }
  piVar1 = (int *)((longlong)param_1 + 0x54);
  *piVar1 = *piVar1 - uVar6 / 0x18;
  if (*piVar1 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,3,0x2c,
                         in_stack_ffffffffffffffa8,(char)*param_1,uVar8);
    }
    *(undefined1 *)((longlong)param_1 + 0x42) = 1;
  }
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_qqqql(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  *(ulonglong *)(param_2 + 0x38) = (ulonglong)uVar6;
  *(uint *)(lVar2 + 8) = uVar6;
  return 0;
}



===== WPP_RECORDER_SF_qqiL @ 1c00024e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqiL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x34,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,4,3,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x34,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qq @ 1c0002630 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qq(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                       undefined8 param_5,undefined1 param_6,undefined1 param_7)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,&param_6,8,&param_7,8,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,
                  &param_6,8,&param_7,8,0);
  return;
}



===== WPP_RECORDER_SF_ @ 1c0002770 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,0
                 );
  return;
}



===== WPP_RECORDER_SF_qqLLqq @ 1c0002850 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqLLqq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x33,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,8,&uStack0000000000000058,8,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x33,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,8,&uStack0000000000000058,8,0);
  return;
}



===== WPP_RECORDER_SF_qL @ 1c00029e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x35,&uStack0000000000000030,8,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x35,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,0);
  return;
}



===== MouseStartWorker @ 1c0002ac0 =====

void MouseStartWorker(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  
  lVar1 = param_2[1];
  lVar2 = *(longlong *)(param_1 + 0x40);
  iVar3 = MouseStart(param_1,(longlong)param_2);
  *(int *)(lVar1 + 0x30) = iVar3;
  *(undefined8 *)(lVar1 + 0x38) = 0;
  IofCompleteRequest(lVar1,0);
  IoFreeWorkItem(*param_2);
  ExFreePoolWithTag(param_2,0);
  IoReleaseRemoveLockEx(lVar2 + 0x20,MouseStartWorker,0x20);
  return;
}



===== MousePnP @ 1c0002b50 =====

int MousePnP(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  char cVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  int iVar5;
  longlong *plVar6;
  longlong lVar7;
  undefined8 local_28;
  longlong local_20;
  
  plVar3 = *(longlong **)(param_1 + 0x40);
  lVar7 = *(longlong *)(param_2 + 0xb8);
  if ((char)plVar3[8] == '\0') {
    *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    return -0x3fffff45;
  }
  iVar5 = IoAcquireRemoveLockEx(plVar3 + 4,param_2,"",1,0x20);
  if (iVar5 < 0) {
    *(int *)(param_2 + 0x30) = iVar5;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    return iVar5;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqc(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
  }
  cVar2 = *(char *)(lVar7 + 1);
  if (cVar2 == '\x17') {
    MouseClassRemoveDevice(plVar3,'\x01');
LAB_1c0002c90:
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  }
  else {
    switch(cVar2) {
    case '\0':
      plVar6 = (longlong *)ExAllocatePool2(0x40,0x10,0x43756f4d);
      if (plVar6 != (longlong *)0x0) {
        lVar7 = IoAllocateWorkItem(param_1);
        *plVar6 = lVar7;
        if (lVar7 != 0) {
          plVar6[1] = param_2;
          IoAcquireRemoveLockEx(plVar3 + 4,MouseStartWorker,"",1,0x20);
          puVar4 = *(undefined8 **)(param_2 + 0xb8);
          iVar5 = 0x103;
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
          lVar7 = *(longlong *)(param_2 + 0xb8);
          *(code **)(lVar7 + -0x10) = MousePnpStartCompletion;
          *(longlong **)(lVar7 + -8) = plVar6;
          *(undefined1 *)(lVar7 + -0x45) = 0xe0;
          pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
          *pbVar1 = *pbVar1 | 1;
          IofCallDriver(plVar3[2],param_2);
          goto LAB_1c0002c1c;
        }
        ExFreePoolWithTag(plVar6,0);
      }
      MouseSendIrpSynchronously(plVar3[2],param_2,'\x01');
      local_28 = 0;
      local_20 = param_2;
      iVar5 = MouseStart(param_1,(longlong)&local_28);
      *(int *)(param_2 + 0x30) = iVar5;
      *(undefined8 *)(param_2 + 0x38) = 0;
      IofCompleteRequest(param_2,0);
      goto LAB_1c0002c1c;
    default:
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
      break;
    case '\x02':
      MouseClassRemoveDevice(plVar3,'\0');
      IoReleaseRemoveLockAndWaitEx(plVar3 + 4,param_2,0x20);
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
      iVar5 = IofCallDriver(plVar3[2],param_2);
      ExAcquireFastMutex(&DAT_1c000b1c0);
      if (Globals != 0) {
        if (DAT_1c000b1b0 < 2) {
          DAT_1c000b1b0 = 0;
          if (DAT_1c000b1a8 != 0) {
            ExFreePoolWithTag(DAT_1c000b1a8,0);
            DAT_1c000b1a8 = 0;
          }
        }
        else {
          *(undefined1 *)
           (DAT_1c000b1a8 + 0x13 + (ulonglong)*(uint *)((longlong)plVar3 + 0xb4) * 0x18) = 1;
          *(undefined8 *)(DAT_1c000b1a8 + (ulonglong)*(uint *)((longlong)plVar3 + 0xb4) * 0x18) = 0;
          *(undefined8 *)(DAT_1c000b1a8 + 8 + (ulonglong)*(uint *)((longlong)plVar3 + 0xb4) * 0x18)
               = 0;
        }
      }
      ExReleaseFastMutex(&DAT_1c000b1c0);
      IoDetachDevice(plVar3[2]);
      RtlFreeUnicodeString(plVar3 + 0xb);
      ExFreePoolWithTag(plVar3[0xd],0);
      IoDeleteDevice(param_1);
      return iVar5;
    case '\x04':
      if (*(char *)((longlong)plVar3 + 0x41) != '\0') {
        ExAcquireFastMutex(&DAT_1c000b1c0);
        if ((Globals == 0) || (DAT_1c000b1b4 < 1)) {
          ExReleaseFastMutex();
        }
        else {
          cVar2 = *(char *)(DAT_1c000b1a8 + 0x10 +
                           (ulonglong)*(uint *)((longlong)plVar3 + 0xb4) * 0x18);
          puVar4 = (undefined8 *)
                   (DAT_1c000b1a8 + (ulonglong)*(uint *)((longlong)plVar3 + 0xb4) * 0x18);
          *(undefined1 *)(puVar4 + 2) = 0;
          ExReleaseFastMutex();
          if (cVar2 != '\0') {
            LOCK();
            lVar7 = plVar3[0x27];
            plVar3[0x27] = 0;
            UNLOCK();
            if (lVar7 != 0) {
              IoUnregisterPlugPlayNotification();
            }
            MouEnableDisablePort('\0',0,plVar3,puVar4);
          }
        }
      }
      *(undefined1 *)((longlong)plVar3 + 0x41) = 0;
      goto LAB_1c0002c90;
    }
  }
  iVar5 = IofCallDriver(plVar3[2],param_2);
LAB_1c0002c1c:
  IoReleaseRemoveLockEx(plVar3 + 4,param_2,0x20);
  return iVar5;
}



===== MouseClassRemoveDevice @ 1c0003050 =====

void MouseClassRemoveDevice(undefined8 *param_1,char param_2)

{
  int iVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined8 *puVar4;
  
  if (param_2 == '\0') {
    puVar4 = param_1;
    if (*(char *)((longlong)param_1 + 0x15a) != '\0') goto LAB_1c00031e5;
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x15a) = 1;
  }
  LOCK();
  iVar1 = *(int *)(param_1 + 0x26);
  *(int *)(param_1 + 0x26) = 1;
  UNLOCK();
  if (iVar1 == 0) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(param_1 + 9);
    lVar2 = param_1[0x23];
    if ((lVar2 == 0) || (*(char *)(param_1 + 0x24) != '\0')) {
      KeReleaseSpinLock(param_1 + 9,uVar3);
      LOCK();
      *(undefined4 *)(param_1 + 0x26) = 2;
      UNLOCK();
    }
    else {
      *(undefined1 *)(param_1 + 0x24) = 1;
      KeReleaseSpinLock(param_1 + 9,uVar3);
      IoCancelIrp(lVar2);
      LOCK();
      iVar1 = *(int *)(param_1 + 0x26);
      *(int *)(param_1 + 0x26) = 2;
      UNLOCK();
      if (iVar1 == 3) {
        IofCompleteRequest(lVar2,0);
      }
    }
  }
  puVar4 = (undefined8 *)*param_1;
  IoWMIRegistrationControl(puVar4,2);
  if (*(char *)((longlong)param_1 + 0x41) != '\0') {
    ExAcquireFastMutex(&DAT_1c000b1c0);
    puVar4 = (undefined8 *)&DAT_1c000b1c0;
    if (Globals == 0) {
      ExReleaseFastMutex();
      if (param_1[0xc] != 0) {
        puVar4 = param_1 + 0xb;
        IoSetDeviceInterfaceState(puVar4,0);
      }
    }
    else if (DAT_1c000b1b4 < 1) {
      ExReleaseFastMutex();
    }
    else {
      *(undefined1 *)(DAT_1c000b1a8 + 0x10 + (ulonglong)*(uint *)((longlong)param_1 + 0xb4) * 0x18)
           = 0;
      ExReleaseFastMutex();
      LOCK();
      puVar4 = (undefined8 *)param_1[0x27];
      param_1[0x27] = 0;
      UNLOCK();
      if (puVar4 != (undefined8 *)0x0) {
        IoUnregisterPlugPlayNotification();
      }
    }
  }
LAB_1c00031e5:
  if (*(char *)(param_1 + 8) != '\0') {
    MouseClassCleanupQueue(puVar4,(longlong)param_1,(longlong *)0x0);
  }
  return;
}



===== WPP_RECORDER_SF_qqc @ 1c0003210 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqc(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x20) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x53,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,1,0);
  }
  WppAutoLogTrace(param_1,4,6,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x53,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,1,0);
  return;
}



===== MouseClassCleanupQueue @ 1c0003330 =====

void MouseClassCleanupQueue(undefined8 param_1,longlong param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 *puVar5;
  byte bVar6;
  longlong *plVar7;
  longlong *plVar8;
  undefined1 *puVar9;
  longlong *plVar10;
  ulonglong uVar11;
  undefined8 uStack_40;
  undefined1 auStack_38 [32];
  undefined8 ***local_18 [2];
  
  local_18[1] = local_18;
  local_18[0] = local_18;
  bVar6 = KeAcquireSpinLockRaiseToDpc(param_2 + 0x90);
  puVar9 = auStack_38;
  plVar10 = (longlong *)(param_2 + 0x98);
  uVar11 = (ulonglong)bVar6;
  plVar7 = (longlong *)*plVar10;
  puVar5 = auStack_38;
  if (plVar7 == plVar10) goto LAB_1c00033a1;
  do {
    plVar8 = (longlong *)*plVar7;
    if ((param_3 == (longlong *)0x0) || (*(longlong **)(plVar7[2] + 0x30) == param_3)) {
      if ((longlong *)plVar8[1] != plVar7) goto LAB_1c000348e;
      puVar2 = (undefined8 *)plVar7[1];
      if ((longlong *)*puVar2 != plVar7) goto LAB_1c000348e;
      *puVar2 = plVar8;
      plVar8[1] = (longlong)puVar2;
      LOCK();
      lVar1 = plVar7[-8];
      plVar7[-8] = 0;
      UNLOCK();
      if (lVar1 == 0) goto LAB_1c0003495;
      *(undefined4 *)(plVar7 + -0xf) = 0xc0000120;
      plVar7[-0xe] = 0;
      plVar3 = *(longlong **)(puVar9 + 0x28);
      if ((undefined1 *)*plVar3 != puVar9 + 0x20) goto LAB_1c000348e;
      plVar7[1] = (longlong)plVar3;
      *plVar7 = (longlong)(puVar9 + 0x20);
      *plVar3 = (longlong)plVar7;
      *(longlong **)(puVar9 + 0x28) = plVar7;
    }
    while (plVar7 = plVar8, puVar5 = puVar9, plVar7 == plVar10) {
LAB_1c00033a1:
      puVar9 = puVar5;
      plVar8 = (longlong *)(uVar11 & 0xff);
      *(undefined8 *)(puVar9 + -8) = 0x1c00033b3;
      KeReleaseSpinLock(param_2 + 0x90);
      while( true ) {
        param_3 = *(longlong **)(puVar9 + 0x20);
        if (param_3 == (longlong *)(puVar9 + 0x20)) {
          return;
        }
        if (((undefined1 *)param_3[1] != puVar9 + 0x20) ||
           (lVar1 = *param_3, *(longlong **)(lVar1 + 8) != param_3)) break;
        *(longlong *)(puVar9 + 0x20) = lVar1;
        *(undefined1 **)(lVar1 + 8) = puVar9 + 0x20;
        *(undefined8 *)(puVar9 + -8) = 0x1c0003401;
        IofCompleteRequest(param_3 + -0x15,0);
        plVar10 = (longlong *)0x20;
        plVar8 = param_3 + -0x15;
        *(undefined8 *)(puVar9 + -8) = 0x1c000341e;
        IoReleaseRemoveLockEx(param_2 + 0x20);
      }
LAB_1c000348e:
      plVar7 = (longlong *)0x3;
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)();
      puVar9 = puVar9 + 8;
LAB_1c0003495:
      plVar7[1] = (longlong)plVar7;
      *plVar7 = (longlong)plVar7;
    }
  } while( true );
}



===== MouseStart @ 1c00034b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int MouseStart(longlong param_1,longlong param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined1 uVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  undefined1 auStack_98 [32];
  undefined8 local_78;
  undefined8 local_70;
  longlong local_68;
  longlong lStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_98;
  lVar2 = *(longlong *)(param_2 + 8);
  plVar3 = *(longlong **)(param_1 + 0x40);
  iVar9 = *(int *)(lVar2 + 0x30);
  if (-1 < iVar9) {
    *(undefined4 *)(lVar2 + 0x30) = 0xc00000bb;
    uVar4 = *(undefined8 *)(lVar2 + 0x38);
    *(undefined8 *)(lVar2 + 0x38) = 0;
    local_78 = 0x10040;
    local_68 = 0;
    lStack_60 = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_48 = 0;
    uStack_40 = 0;
    local_70 = 0xffffffffffffffff;
    lVar5 = *(longlong *)(lVar2 + 0xb8);
    *(undefined1 *)(lVar5 + -0x47) = 9;
    *(undefined8 **)(lVar5 + -0x40) = &local_78;
    iVar8 = MouseSendIrpSynchronously(plVar3[2],lVar2,'\0');
    if ((-1 < iVar8) && (-1 < *(int *)(lVar2 + 0x30))) {
      *(undefined4 *)((longlong)plVar3 + 0x10c) = (undefined4)local_48;
      *(undefined4 *)(plVar3 + 0x22) = uStack_50._4_4_;
      plVar3[0x1f] = local_68;
      plVar3[0x20] = lStack_60;
      *(undefined4 *)(plVar3 + 0x21) = (undefined4)local_58;
    }
    *(undefined8 *)(lVar2 + 0x38) = uVar4;
    *(int *)(lVar2 + 0x30) = iVar9;
    *(undefined1 *)((longlong)plVar3 + 0x41) = 1;
    if ((*(int *)((longlong)plVar3 + 0x10c) < 2) || ((int)plVar3[0x22] < 2)) {
      *(undefined4 *)(plVar3 + 0x17) = 1;
    }
    else {
      *(undefined4 *)(plVar3 + 0x17) = 2;
      MouseClassGetWaitWakeEnableState((longlong)plVar3);
    }
    plVar3[0x18] = (longlong)&MouseClassWmiGuidList;
    plVar3[0x1d] = 0;
    plVar3[0x19] = (longlong)MouseClassQueryWmiRegInfo;
    plVar3[0x1a] = (longlong)MouseClassQueryWmiDataBlock;
    plVar3[0x1b] = (longlong)MouseClassSetWmiDataBlock;
    plVar3[0x1c] = (longlong)MouseClassSetWmiDataItem;
    plVar3[0x1e] = 0;
    IoWMIRegistrationControl(*plVar3,1);
    ExAcquireFastMutex(&DAT_1c000b1c0);
    if (Globals == 0) {
      ExReleaseFastMutex();
      iVar9 = IoSetDeviceInterfaceState(plVar3 + 0xb,1);
    }
    else {
      iVar9 = 0;
      if (DAT_1c000b1b4 < 1) {
        ExReleaseFastMutex(&DAT_1c000b1c0);
      }
      else {
        cVar7 = *(char *)(DAT_1c000b1a8 + 0x10 +
                         (ulonglong)*(uint *)((longlong)plVar3 + 0xb4) * 0x18);
        puVar1 = (undefined8 *)
                 (DAT_1c000b1a8 + (ulonglong)*(uint *)((longlong)plVar3 + 0xb4) * 0x18);
        *(undefined1 *)(puVar1 + 2) = 1;
        ExReleaseFastMutex();
        if (cVar7 == '\0') {
          iVar9 = MouEnableDisablePort('\x01',0,plVar3,puVar1);
          if (iVar9 < 0) {
            *(undefined1 *)(puVar1 + 2) = 0;
          }
        }
      }
    }
    if ((1 < *(int *)((longlong)plVar3 + 0x10c)) && (1 < (int)plVar3[0x22])) {
      uVar6 = KeAcquireSpinLockRaiseToDpc(plVar3 + 9);
      if ((plVar3[0x23] == 0) || ((char)plVar3[0x24] != '\0')) {
        KeReleaseSpinLock(plVar3 + 9,uVar6);
        cVar7 = MouseClassCheckWaitWakeEnabled((longlong)plVar3);
        if (cVar7 != '\0') {
          MouseClassCreateWaitWakeIrp((longlong)plVar3);
        }
      }
      else {
        KeReleaseSpinLock(plVar3 + 9,uVar6);
      }
    }
  }
  return iVar9;
}



===== MouseClassCheckWaitWakeEnabled @ 1c00037a0 =====

undefined1 MouseClassCheckWaitWakeEnabled(longlong param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x48);
  uVar1 = *(undefined1 *)(param_1 + 0x159);
  KeReleaseSpinLock(param_1 + 0x48,uVar2);
  return uVar1;
}



===== MouseClassCreate @ 1c00037f0 =====

int MouseClassCreate(longlong param_1,ulonglong param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined1 *puVar2;
  longlong *plVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  byte bVar10;
  char *pcVar11;
  undefined **ppuVar12;
  undefined4 uVar13;
  undefined4 in_stack_ffffffffffffff9c;
  
  bVar4 = false;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    param_4 = 0x1d;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x1d);
  }
  ppuVar12 = &WPP_RECORDER_INITIALIZED;
  puVar2 = *(undefined1 **)(param_2 + 0xb8);
  plVar3 = *(longlong **)(param_1 + 0x40);
  bVar10 = puVar2[2] & 1;
  if (((*(char *)(param_2 + 0x40) == '\x01') || (bVar10 != 0)) &&
     (uVar9 = (ulonglong)*(uint *)(*(longlong *)(puVar2 + 8) + 0x10),
     (*(uint *)(*(longlong *)(puVar2 + 8) + 0x10) & 1) != 0)) {
    iVar6 = -0x3fffffde;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqdDdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    if ((*(char *)(param_2 + 0x40) == '\0') && (bVar10 != 0)) {
      MouClassTraceLoggingDeniedCreateForReadWithSFAC
                ((ulonglong)*(uint *)(*(longlong *)(puVar2 + 8) + 0x10),uVar9,ppuVar12,param_4);
    }
    goto LAB_1c000399c;
  }
  uVar13 = 0x20;
  pcVar11 = "";
  uVar9 = param_2;
  iVar6 = IoAcquireRemoveLockEx(plVar3 + 4,param_2,"",1);
  if (iVar6 < 0) goto LAB_1c000399c;
  if (((char)plVar3[8] == '\0') || (*(char *)((longlong)plVar3 + 0x41) != '\0')) {
    if (*plVar3 == plVar3[1]) {
      if (bVar10 == 0) {
        uVar9 = (ulonglong)*(byte *)(param_2 + 0x40);
      }
      else {
        uVar9 = CONCAT71((int7)(uVar9 >> 8),1);
      }
      cVar5 = SeSinglePrivilegeCheck(7);
      if (cVar5 == '\0') {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar9 = *(ulonglong *)(puVar2 + 8);
          WPP_RECORDER_SF_qqDdd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
        }
      }
      else {
        bVar10 = KeAcquireSpinLockRaiseToDpc(plVar3 + 0x12);
        *(code **)(*(longlong *)(puVar2 + 0x30) + 0x20) = DriverEntry;
        uVar9 = (ulonglong)bVar10;
        *(int *)(plVar3 + 10) = (int)plVar3[10] + 1;
        KeReleaseSpinLock(plVar3 + 0x12);
      }
    }
    ExAcquireFastMutex();
    if (Globals == plVar3) {
      DAT_1c000b1b4 = DAT_1c000b1b4 + 1;
      if (DAT_1c000b1b4 == 1) {
        uVar8 = 0;
        uVar7 = 0;
        if (DAT_1c000b1b0 != 0) {
          do {
            puVar1 = (undefined8 *)(DAT_1c000b1a8 + uVar8 * 0x18);
            if (*(char *)(DAT_1c000b1a8 + 0x13 + uVar8 * 0x18) == '\0') {
              cVar5 = *(char *)(puVar1 + 2);
              *(undefined1 *)(puVar1 + 2) = 1;
              ExReleaseFastMutex(&DAT_1c000b1c0);
              if (cVar5 == '\0') {
                pcVar11 = (char *)puVar1[1];
                uVar9 = param_2;
                iVar6 = MouEnableDisablePort('\x01',param_2,(longlong *)pcVar11,puVar1);
              }
              if (iVar6 == 0) {
                bVar4 = true;
              }
              else {
                if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                  WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,pcVar11,0x21,
                                      CONCAT44(in_stack_ffffffffffffff9c,uVar13),(char)param_1,
                                      (char)param_2,(char)plVar3[2]);
                }
                uVar9 = 0xc0050009;
                pcVar11 = (char *)0x4e98;
                uVar13 = 0;
                MouseClassLogError(param_1,0xc0050009,0x4e98,iVar6,0,(undefined4 *)0x0,*puVar2);
                *(undefined1 *)(puVar1 + 2) = 0;
              }
              ExAcquireFastMutex(&DAT_1c000b1c0);
            }
            uVar7 = uVar7 + 1;
            uVar8 = (ulonglong)uVar7;
          } while (uVar7 < DAT_1c000b1b0);
        }
        ExReleaseFastMutex(&DAT_1c000b1c0);
        if (bVar4) goto LAB_1c0003981;
      }
      else {
        ExReleaseFastMutex(&DAT_1c000b1c0);
      }
    }
    else {
      ExReleaseFastMutex(&DAT_1c000b1c0);
      if (plVar3[1] != param_1) {
        *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
        *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
        iVar6 = IofCallDriver(plVar3[2]);
        IoReleaseRemoveLockEx(plVar3 + 4,param_2,0x20);
        return iVar6;
      }
      iVar6 = MouEnableDisablePort('\x01',param_2,plVar3,(undefined8 *)(puVar2 + 0x30));
      if (iVar6 == 0) {
LAB_1c0003981:
        iVar6 = 0;
      }
      else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqdq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
    }
  }
  else {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x1f,
                         CONCAT44(in_stack_ffffffffffffff9c,uVar13),(char)param_1,(char)param_2);
    }
    iVar6 = -0x3fffffff;
  }
  IoReleaseRemoveLockEx(plVar3 + 4,param_2,0x20);
LAB_1c000399c:
  *(int *)(param_2 + 0x30) = iVar6;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x23);
  }
  return iVar6;
}



===== WPP_RECORDER_SF_qqdDdd @ 1c0003d30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqdDdd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  undefined1 uStack0000000000000058;
  undefined4 local_18 [4];
  
  local_18[0] = 0xc0000022;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x1e,&uStack0000000000000030,8,
               &uStack0000000000000038,8,local_18,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,&uStack0000000000000058,4,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x1e,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,local_18,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,&uStack0000000000000058,4,0);
  return;
}



===== WPP_RECORDER_SF_qqDdd @ 1c0003ef0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqDdd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (2 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x20,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,3,2,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x20,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,&uStack0000000000000050,4,0);
  return;
}



===== MouseClassCleanup @ 1c0004070 =====

undefined8 MouseClassCleanup(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  undefined8 uVar5;
  code *pcVar6;
  undefined1 *puVar7;
  byte bVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  undefined1 *puVar12;
  longlong *plVar13;
  ulonglong uVar14;
  undefined8 uStack_60;
  undefined1 auStack_58 [48];
  undefined8 ***local_28 [2];
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x15);
  }
  puVar12 = auStack_58;
  lVar1 = *(longlong *)(param_1 + 0x40);
  plVar11 = *(longlong **)(*(longlong *)(param_2 + 0xb8) + 0x30);
  if ((code *)plVar11[4] != DriverEntry) {
LAB_1c0004155:
    *(undefined4 *)(param_2 + 0x30) = 0;
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined8 *)(puVar12 + -8) = 0x1c0004169;
    IofCompleteRequest(param_2,0);
    if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
       (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
      uVar5 = *(undefined8 *)(WPP_GLOBAL_Control + 0x40);
      *(undefined8 *)(puVar12 + -8) = 0x1c000429d;
      WPP_RECORDER_SF_(uVar5,5,2,0x16);
    }
    return 0;
  }
  local_28[1] = local_28;
  local_28[0] = local_28;
  bVar8 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x90);
  plVar13 = (longlong *)(lVar1 + 0x98);
  uVar14 = (ulonglong)bVar8;
  plVar9 = (longlong *)*plVar13;
  puVar12 = auStack_58;
  puVar7 = auStack_58;
  if (plVar9 == plVar13) goto LAB_1c000412f;
  do {
    plVar10 = (longlong *)*plVar9;
    if ((plVar11 == (longlong *)0x0) || (*(longlong **)(plVar9[2] + 0x30) == plVar11)) {
      if ((longlong *)plVar10[1] != plVar9) goto LAB_1c000425b;
      puVar3 = (undefined8 *)plVar9[1];
      if ((longlong *)*puVar3 != plVar9) goto LAB_1c000425b;
      *puVar3 = plVar10;
      plVar10[1] = (longlong)puVar3;
      LOCK();
      lVar2 = plVar9[-8];
      plVar9[-8] = 0;
      UNLOCK();
      if (lVar2 == 0) goto LAB_1c0004262;
      *(undefined4 *)(plVar9 + -0xf) = 0xc0000120;
      plVar9[-0xe] = 0;
      plVar4 = *(longlong **)(puVar12 + 0x38);
      if ((undefined1 *)*plVar4 != puVar12 + 0x30) goto LAB_1c000425b;
      plVar9[1] = (longlong)plVar4;
      *plVar9 = (longlong)(puVar12 + 0x30);
      *plVar4 = (longlong)plVar9;
      *(longlong **)(puVar12 + 0x38) = plVar9;
    }
    while (plVar9 = plVar10, puVar7 = puVar12, plVar9 == plVar13) {
LAB_1c000412f:
      puVar12 = puVar7;
      plVar10 = (longlong *)(uVar14 & 0xff);
      *(undefined8 *)(puVar12 + -8) = 0x1c0004141;
      KeReleaseSpinLock(lVar1 + 0x90);
      while( true ) {
        plVar11 = *(longlong **)(puVar12 + 0x30);
        if (plVar11 == (longlong *)(puVar12 + 0x30)) goto LAB_1c0004155;
        if (((undefined1 *)plVar11[1] != puVar12 + 0x30) ||
           (lVar2 = *plVar11, *(longlong **)(lVar2 + 8) != plVar11)) break;
        *(longlong *)(puVar12 + 0x30) = lVar2;
        *(undefined1 **)(lVar2 + 8) = puVar12 + 0x30;
        *(undefined8 *)(puVar12 + -8) = 0x1c00041df;
        IofCompleteRequest(plVar11 + -0x15,0);
        plVar13 = (longlong *)0x20;
        plVar10 = plVar11 + -0x15;
        *(undefined8 *)(puVar12 + -8) = 0x1c00041fc;
        IoReleaseRemoveLockEx(lVar1 + 0x20);
      }
LAB_1c000425b:
      plVar9 = (longlong *)0x3;
      pcVar6 = (code *)swi(0x29);
      (*pcVar6)();
      puVar12 = puVar12 + 8;
LAB_1c0004262:
      plVar9[1] = (longlong)plVar9;
      *plVar9 = (longlong)plVar9;
    }
  } while( true );
}



===== MouseClassClose @ 1c00042b0 =====

ulonglong MouseClassClose(longlong param_1,ulonglong param_2,longlong *param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  char cVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  bool bVar6;
  byte bVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  uint uVar11;
  longlong *plVar12;
  uint local_res8;
  undefined4 in_stack_ffffffffffffffb8;
  undefined4 in_stack_ffffffffffffffbc;
  
  uVar8 = 0;
  bVar6 = false;
  uVar9 = param_2;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    uVar9 = CONCAT71((int7)(param_2 >> 8),5);
    param_3 = (longlong *)0x2;
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x24);
  }
  plVar4 = *(longlong **)(param_1 + 0x40);
  puVar5 = *(undefined1 **)(param_2 + 0xb8);
  if (*plVar4 == plVar4[1]) {
    bVar7 = KeAcquireSpinLockRaiseToDpc(plVar4 + 0x12);
    uVar9 = (ulonglong)bVar7;
    if (*(code **)(*(longlong *)(puVar5 + 0x30) + 0x20) == DriverEntry) {
      *(int *)(plVar4 + 10) = (int)plVar4[10] + -1;
      *(undefined8 *)(*(longlong *)(puVar5 + 0x30) + 0x20) = 0;
    }
    KeReleaseSpinLock(plVar4 + 0x12);
  }
  ExAcquireFastMutex();
  if (Globals == plVar4) {
    DAT_1c000b1b4 = DAT_1c000b1b4 + -1;
    if (DAT_1c000b1b4 == 0) {
      uVar10 = 0;
      local_res8 = 0;
      if (DAT_1c000b1b0 != 0) {
        do {
          puVar1 = (undefined8 *)(DAT_1c000b1a8 + uVar10 * 0x18);
          if (*(char *)(DAT_1c000b1a8 + 0x13 + uVar10 * 0x18) == '\0') {
            cVar3 = *(char *)(puVar1 + 2);
            *(undefined1 *)(puVar1 + 2) = 0;
            ExReleaseFastMutex();
            if (cVar3 != '\0') {
              LOCK();
              lVar2 = *(longlong *)(puVar1[1] + 0x138);
              *(longlong *)(puVar1[1] + 0x138) = 0;
              UNLOCK();
              if (lVar2 != 0) {
                IoUnregisterPlugPlayNotification();
              }
              param_3 = (longlong *)puVar1[1];
              uVar9 = param_2;
              uVar8 = MouEnableDisablePort('\0',param_2,param_3,puVar1);
            }
            if (uVar8 == 0) {
              bVar6 = true;
            }
            else {
              if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
                WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,param_3,0x25,
                                    CONCAT44(in_stack_ffffffffffffffbc,in_stack_ffffffffffffffb8),
                                    (char)param_1,(char)param_2,
                                    (char)*(undefined8 *)(puVar1[1] + 0x10));
              }
              uVar9 = 0xc005000a;
              param_3 = (longlong *)0x4e98;
              in_stack_ffffffffffffffb8 = 0;
              MouseClassLogError(param_1,0xc005000a,0x4e98,uVar8,0,(undefined4 *)0x0,*puVar5);
            }
            ExAcquireFastMutex(&DAT_1c000b1c0);
          }
          local_res8 = local_res8 + 1;
          uVar10 = (ulonglong)local_res8;
        } while (local_res8 < DAT_1c000b1b0);
      }
    }
    ExReleaseFastMutex(&DAT_1c000b1c0);
  }
  else {
    ExReleaseFastMutex();
    if (plVar4[1] != param_1) {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar9 = IofCallDriver(plVar4[2]);
      return uVar9;
    }
    uVar9 = param_2;
    plVar12 = plVar4;
    uVar8 = MouEnableDisablePort('\0',param_2,plVar4,(undefined8 *)(puVar5 + 0x30));
    if (uVar8 == 0) {
      bVar6 = true;
    }
    else {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar9,plVar12,0x26,
                            CONCAT44(in_stack_ffffffffffffffbc,in_stack_ffffffffffffffb8),
                            (char)param_1,(char)param_2,(char)plVar4[2]);
      }
      MouseClassLogError(param_1,0xc005000a,0x4e98,uVar8,0,(undefined4 *)0x0,*puVar5);
    }
  }
  *(undefined8 *)(param_2 + 0x38) = 0;
  uVar11 = 0;
  if (!bVar6) {
    uVar11 = uVar8;
  }
  *(uint *)(param_2 + 0x30) = uVar11;
  IofCompleteRequest(param_2,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x27);
  }
  return (ulonglong)uVar11;
}



===== WPP_RECORDER_SF_qqL @ 1c0004620 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqL(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  ulonglong uVar1;
  
  uVar1 = (ulonglong)(param_3 >> 0x10);
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar1 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar1 * 0x50 + 0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar1 * 0x50 + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,
                  &param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== MouSyncComplete @ 1c00047a0 =====

undefined8 MouSyncComplete(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  KeSetEvent(param_3,0,0);
  return 0xc0000016;
}



===== WPP_RECORDER_SF_S @ 1c00047d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_S(undefined8 param_1,byte param_2,uint param_3,undefined2 param_4,
                      undefined8 param_5,wchar_t *param_6)

{
  longlong lVar1;
  longlong lVar2;
  wchar_t *pwVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  lVar4 = -1;
  uVar6 = (ulonglong)(param_3 >> 0x10);
  lVar5 = 10;
  if (((*(uint *)(WPP_GLOBAL_Control +
                 ((ulonglong)(param_3 - 1 >> 5 & 0x7ff) + uVar6 * 0x14) * 4 + 0x2c) >>
        (param_3 - 1 & 0x1f) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[uVar6 * 0x50 + 0x29])) {
    if (param_6 == (wchar_t *)0x0) {
      lVar2 = 10;
    }
    else {
      lVar2 = -1;
      do {
        lVar1 = lVar2 + 1;
        lVar2 = lVar2 + 1;
      } while (param_6[lVar1] != L'\0');
      lVar2 = lVar2 * 2 + 2;
    }
    pwVar3 = param_6;
    if (param_6 == (wchar_t *)0x0) {
      pwVar3 = L"NULL";
    }
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + uVar6 * 0x50 + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,pwVar3,lVar2,0);
  }
  if (param_6 != (wchar_t *)0x0) {
    do {
      lVar5 = lVar4 + 1;
      lVar4 = lVar4 + 1;
    } while (param_6[lVar5] != L'\0');
    lVar5 = lVar4 * 2 + 2;
  }
  if (param_6 == (wchar_t *)0x0) {
    param_6 = L"NULL";
  }
  WppAutoLogTrace(param_1,param_2,param_3,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,
                  param_6,lVar5,0);
  return;
}



===== MouseClassPowerComplete @ 1c0004950 =====

undefined8 MouseClassPowerComplete(longlong param_1,longlong param_2)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined8 *puVar3;
  bool bVar4;
  int iVar5;
  
  lVar2 = *(longlong *)(param_2 + 0xb8);
  puVar3 = *(undefined8 **)(param_1 + 0x40);
  bVar4 = true;
  uVar1 = *(undefined4 *)(lVar2 + 0x18);
  if (*(char *)(lVar2 + 1) == '\0') {
    bVar4 = false;
    if (param_2 == puVar3[0x23]) {
      LOCK();
      iVar5 = *(int *)(puVar3 + 0x26);
      *(int *)(puVar3 + 0x26) = 3;
      UNLOCK();
      if (iVar5 == 1) {
        PoStartNextPowerIrp(param_2);
        return 0xc0000016;
      }
    }
  }
  else if (*(char *)(lVar2 + 1) == '\x02') {
    if (*(int *)(lVar2 + 0x10) == 0) {
      PoSetPowerState(*puVar3,0,uVar1);
      *(undefined4 *)(puVar3 + 0x16) = uVar1;
      iVar5 = PoRequestPowerIrp(*puVar3,2,1,MouseClassPoRequestComplete,0,0);
      if (iVar5 < 0) {
        *(int *)(param_2 + 0x30) = iVar5;
      }
    }
    else if (*(int *)(lVar2 + 0x10) == 1) {
      *(undefined4 *)((longlong)puVar3 + 0xac) = uVar1;
      PoSetPowerState(*puVar3,1,uVar1);
    }
    PoStartNextPowerIrp(param_2);
    goto LAB_1c00049e0;
  }
  PoStartNextPowerIrp(param_2);
  if (!bVar4) {
    return 0;
  }
LAB_1c00049e0:
  IoReleaseRemoveLockEx(puVar3 + 4,param_2,0x20);
  return 0;
}



===== MouseClassWaitWakeComplete @ 1c0004ab0 =====

void MouseClassWaitWakeComplete(void)

{
  int iVar1;
  longlong lVar2;
  byte bVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  undefined8 *in_R9;
  int *in_stack_00000028;
  undefined8 *in_stack_ffffffffffffffd8;
  undefined1 uVar7;
  
  bVar3 = KeAcquireSpinLockRaiseToDpc(in_R9 + 9);
  uVar6 = (ulonglong)bVar3;
  lVar5 = in_R9[0x25];
  if ((lVar5 == 0) || (in_stack_00000028 != (int *)(lVar5 + 0x30))) {
    lVar2 = in_R9[0x23];
    lVar5 = 0;
    if ((lVar2 != 0) && (in_stack_00000028 == (int *)(lVar2 + 0x30))) {
      in_R9[0x23] = 0;
      *(undefined1 *)(in_R9 + 0x24) = 0;
      lVar5 = lVar2;
    }
  }
  else {
    in_R9[0x25] = 0;
  }
  KeReleaseSpinLock(in_R9 + 9);
  uVar7 = (undefined1)lVar5;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,uVar6,0x56,
                        in_stack_ffffffffffffffd8,(char)*in_R9,uVar7,(char)*in_stack_00000028);
  }
  iVar1 = *in_stack_00000028;
  if (iVar1 == 0) {
    uVar6 = 1;
    in_stack_ffffffffffffffd8 = in_R9;
    PoRequestPowerIrp(in_R9[3],2,1,MouseClassWWPowerUpComplete);
  }
  else if ((((iVar1 != -0x7fffffef) && (iVar1 != -0x3ffffee0)) && (iVar1 != -0x3ffffe7c)) &&
          ((iVar1 != -0x3ffffd2d && (iVar1 != -0x3febffdf)))) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar6,0x58,
                          in_stack_ffffffffffffffd8,(char)*in_R9,uVar7,(char)iVar1);
    }
    uVar4 = MouseToggleWaitWake(in_R9,0);
    if (((int)uVar4 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    goto LAB_1c0004b65;
  }
  if ((*in_stack_00000028 < 0) &&
     ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
    WPP_RECORDER_SF_qqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,uVar6,0x57,
                        in_stack_ffffffffffffffd8,(char)*in_R9,uVar7,(char)*in_stack_00000028);
  }
LAB_1c0004b65:
  IoReleaseRemoveLockEx(in_R9 + 4,lVar5,0x20);
  return;
}



===== WPP_RECORDER_SF_qqd @ 1c0004cf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqd(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                        undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,param_2,5,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,
                  &param_6,8,&param_7,8,&param_8,4,0);
  return;
}



===== RtlWideCharArrayCopyStringWorker @ 1c0004e00 =====

undefined8 RtlWideCharArrayCopyStringWorker(longlong param_1,longlong param_2,longlong *param_3)

{
  wchar_t *pwVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong lVar4;
  
  uVar2 = 0;
  pwVar1 = L"PointerClass";
  lVar3 = 0x7fff;
  lVar4 = 0;
  if (param_2 != 0) {
    do {
      if (lVar3 == 0) goto LAB_1c0004e5a;
      if (*pwVar1 == L'\0') {
        if (param_2 != 0) goto LAB_1c0004e5a;
        break;
      }
      *(wchar_t *)(param_1 + -0x1c00091e0 + (longlong)pwVar1) = *pwVar1;
      lVar3 = lVar3 + -1;
      pwVar1 = pwVar1 + 1;
      lVar4 = lVar4 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    if ((lVar3 == 0) || (*pwVar1 == L'\0')) goto LAB_1c0004e5a;
  }
  uVar2 = 0x80000005;
LAB_1c0004e5a:
  *param_3 = lVar4;
  return uVar2;
}



===== MouseClassWWPowerUpComplete @ 1c0004e70 =====

void MouseClassWWPowerUpComplete
               (undefined1 param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4)

{
  int iVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 in_stack_ffffffffffffffd8;
  undefined4 in_stack_ffffffffffffffdc;
  
  if (*(char *)((longlong)param_4 + 0x159) != '\0') {
    uVar4 = 0x20;
    uVar5 = 0x43756f4d;
    puVar2 = (undefined8 *)ExAllocatePool2(0x40);
    if (puVar2 != (undefined8 *)0x0) {
      lVar3 = IoAllocateWorkItem(*param_4);
      puVar2[2] = lVar3;
      if (lVar3 != 0) {
        puVar2[1] = param_4;
        *puVar2 = 0;
        iVar1 = IoAcquireRemoveLockEx(param_4 + 4,puVar2,"",1,0x20);
        if (iVar1 < 0) {
          IoFreeWorkItem(puVar2[2]);
          ExFreePoolWithTag(puVar2,0);
          return;
        }
        IoQueueWorkItem(puVar2[2],MouseClassCreateWaitWakeIrpWorker,1,puVar2);
        return;
      }
      uVar4 = 0;
      ExFreePoolWithTag(puVar2);
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar4,uVar5,0x55,
                        CONCAT44(in_stack_ffffffffffffffdc,in_stack_ffffffffffffffd8),param_1);
    }
    MouseClassLogError(*param_4,0x8005000e,1,0xc000009a,0,(undefined4 *)0x0,0);
  }
  return;
}



===== MouseClassPoRequestComplete @ 1c0004fd0 =====

void MouseClassPoRequestComplete
               (longlong param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  undefined4 uVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  undefined8 *puVar6;
  longlong lVar7;
  undefined8 uVar8;
  char *pcVar9;
  undefined4 in_stack_ffffffffffffffd8;
  undefined4 in_stack_ffffffffffffffdc;
  
  puVar2 = *(undefined8 **)(param_1 + 0x40);
  if (param_4 != 0) {
    uVar1 = *(undefined4 *)(*(longlong *)(param_4 + 0xb8) + 0x18);
    PoSetPowerState(*puVar2,0,uVar1);
    *(undefined4 *)(puVar2 + 0x16) = uVar1;
    PoStartNextPowerIrp(param_4);
    *(char *)(param_4 + 0x43) = *(char *)(param_4 + 0x43) + '\x01';
    *(longlong *)(param_4 + 0xb8) = *(longlong *)(param_4 + 0xb8) + 0x48;
    PoCallDriver(puVar2[2],param_4);
    IoReleaseRemoveLockEx(puVar2 + 4,param_4,0x20);
    return;
  }
  if ((1 < *(int *)((longlong)puVar2 + 0x10c)) && (1 < *(int *)(puVar2 + 0x22))) {
    uVar3 = KeAcquireSpinLockRaiseToDpc(puVar2 + 9);
    if ((puVar2[0x23] != 0) && (*(char *)(puVar2 + 0x24) == '\0')) {
      KeReleaseSpinLock(puVar2 + 9,uVar3);
      return;
    }
    KeReleaseSpinLock(puVar2 + 9,uVar3);
    cVar4 = MouseClassCheckWaitWakeEnabled((longlong)puVar2);
    if (cVar4 != '\0') {
      uVar8 = 0x20;
      pcVar9 = (char *)0x43756f4d;
      puVar6 = (undefined8 *)ExAllocatePool2(0x40);
      if (puVar6 != (undefined8 *)0x0) {
        lVar7 = IoAllocateWorkItem(*puVar2);
        puVar6[2] = lVar7;
        if (lVar7 != 0) {
          puVar6[1] = puVar2;
          *puVar6 = 0;
          pcVar9 = "";
          in_stack_ffffffffffffffd8 = 0x20;
          iVar5 = IoAcquireRemoveLockEx(puVar2 + 4,puVar6,"",1);
          if (-1 < iVar5) {
            IoQueueWorkItem(puVar6[2],MouseClassCreateWaitWakeIrpWorker,1,puVar6);
            return;
          }
          IoFreeWorkItem(puVar6[2]);
        }
        uVar8 = 0;
        ExFreePoolWithTag(puVar6);
      }
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),uVar8,pcVar9,0x5c,
                          CONCAT44(in_stack_ffffffffffffffdc,in_stack_ffffffffffffffd8),
                          (char)param_1);
      }
      MouseClassLogError(*puVar2,0x8005000e,2,0xc000009a,0,(undefined4 *)0x0,0);
    }
  }
  return;
}



===== RtlUnicodeStringPrintf @ 1c0005220 =====

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
      (uVar2 != 0xffff)) && ((*(longlong *)(param_1 + 4) != 0 || ((uVar1 == 0 && (uVar2 == 0)))))) {
    uVar5 = 0;
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



===== MousePnpStartCompletion @ 1c00052e0 =====

undefined8 MousePnpStartCompletion(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  IoQueueWorkItem(*param_3,MouseStartWorker,1,param_3);
  return 0xc0000016;
}



===== MouseClassCancel @ 1c0005320 =====

void MouseClassCancel(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *plVar4;
  code *pcVar5;
  undefined1 uVar6;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  IoReleaseCancelSpinLock(*(undefined1 *)(param_2 + 0x45));
  uVar6 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x90);
  plVar1 = (longlong *)(param_2 + 0xa8);
  lVar3 = *plVar1;
  if ((*(longlong **)(lVar3 + 8) == plVar1) &&
     (plVar4 = *(longlong **)(param_2 + 0xb0), (longlong *)*plVar4 == plVar1)) {
    *plVar4 = lVar3;
    *(longlong **)(lVar3 + 8) = plVar4;
    KeReleaseSpinLock(lVar2 + 0x90,uVar6);
    *(undefined4 *)(param_2 + 0x30) = 0xc0000120;
    IofCompleteRequest(param_2,0);
    IoReleaseRemoveLockEx(lVar2 + 0x20,param_2,0x20);
    return;
  }
  pcVar5 = (code *)swi(0x29);
  (*pcVar5)(3);
  pcVar5 = (code *)swi(3);
  (*pcVar5)();
  return;
}



===== WPP_RECORDER_SF_qqdq @ 1c00053e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqdq(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x22,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,8,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x22,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,8,0);
  return;
}



===== WPP_RECORDER_SF_d @ 1c0005510 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_d(undefined8 param_1,byte param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) &&
     (param_2 <= (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,&param_6,4,0);
  }
  WppAutoLogTrace(param_1,param_2,1,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,
                  &param_6,4,0);
  return;
}



===== MouInitializeDataQueue @ 1c00055d0 =====

void MouInitializeDataQueue(longlong param_1)

{
  undefined1 uVar1;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x4f);
  }
  uVar1 = KeAcquireSpinLockRaiseToDpc(param_1 + 0x90);
  *(undefined8 *)(param_1 + 0x70) = *(undefined8 *)(param_1 + 0x68);
  *(undefined8 *)(param_1 + 0x78) = *(undefined8 *)(param_1 + 0x68);
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined1 *)(param_1 + 0x42) = 1;
  KeReleaseSpinLock(param_1 + 0x90,uVar1);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x50);
  }
  return;
}



===== MouseClassLogError @ 1c00056a0 =====

void MouseClassLogError(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       uint param_5,undefined4 *param_6,undefined1 param_7)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  ulonglong uVar3;
  
  puVar1 = (undefined1 *)IoAllocateErrorLogEntry();
  if (puVar1 != (undefined1 *)0x0) {
    *(undefined4 *)(puVar1 + 0xc) = param_2;
    *(undefined8 *)(puVar1 + 0x18) = 0;
    *(short *)(puVar1 + 2) = (short)param_5 << 2;
    *puVar1 = param_7;
    puVar1[1] = 0;
    *(undefined4 *)(puVar1 + 0x10) = param_3;
    *(undefined4 *)(puVar1 + 0x14) = param_4;
    if (param_5 != 0) {
      uVar3 = (ulonglong)param_5;
      puVar2 = param_6;
      do {
        *(undefined4 *)(puVar1 + (0x28 - (longlong)param_6) + (longlong)puVar2) = *puVar2;
        puVar2 = puVar2 + 1;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    IoWriteErrorLogEntry(puVar1);
  }
  return;
}



===== __report_gsfailure @ 1c0005760 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== MouClassTraceLoggingDeniedCreateForReadWithSFAC @ 1c0005770 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void MouClassTraceLoggingDeniedCreateForReadWithSFAC
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined1 auStackY_78 [32];
  undefined4 local_48 [2];
  undefined8 local_40 [4];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_78;
  if (5 < DAT_1c000b000) {
    uVar1 = _tlgKeywordOn();
    if ((char)uVar1 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_48[0] = (undefined4)param_1;
      local_18 = 4;
      _tlgWriteTransfer_EtwWriteTransfer(param_1,&DAT_1c00095f1,param_3,param_4,3,local_40);
    }
  }
  return;
}



===== MouseClassFlush @ 1c00057f0 =====

undefined4 MouseClassFlush(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x1b);
  }
  plVar1 = *(longlong **)(param_1 + 0x40);
  if (*plVar1 == plVar1[1]) {
    if (*(code **)(*(longlong *)(*(longlong *)(param_2 + 0xb8) + 0x30) + 0x20) == DriverEntry) {
      MouInitializeDataQueue((longlong)plVar1);
    }
    else {
      uVar2 = 0xc0000061;
    }
  }
  else {
    uVar2 = 0xc00000bb;
  }
  *(undefined4 *)(param_2 + 0x30) = uVar2;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,3,0x1c);
  }
  return uVar2;
}



===== MouseClassQueryWmiDataBlock @ 1c00058f0 =====

void MouseClassQueryWmiDataBlock
               (longlong param_1,undefined8 param_2,int param_3,int param_4,int param_5,
               undefined4 *param_6,uint param_7,longlong *param_8)

{
  longlong lVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  uVar4 = 0;
  if (param_3 == 0) {
    if ((param_4 != 0) || (param_5 != 1)) {
LAB_1c00059c4:
      uVar5 = 0xc0000010;
      goto LAB_1c00059ca;
    }
    uVar4 = 8;
    if (param_7 < 8) {
LAB_1c00059a8:
      uVar5 = 0xc0000023;
      goto LAB_1c00059ca;
    }
    *param_8 = param_1;
  }
  else {
    if (param_3 != 1) {
      uVar5 = 0xc0000295;
      goto LAB_1c00059ca;
    }
    if ((param_4 != 0) || (param_5 != 1)) goto LAB_1c00059c4;
    uVar4 = 1;
    if (param_7 == 0) goto LAB_1c00059a8;
    uVar2 = KeAcquireSpinLockRaiseToDpc(lVar1 + 0x48);
    if ((*(longlong *)(lVar1 + 0x118) == 0) || (*(char *)(lVar1 + 0x120) != '\0')) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    KeReleaseSpinLock(lVar1 + 0x48,uVar2);
    *(undefined1 *)param_8 = uVar3;
  }
  uVar5 = 0;
  *param_6 = uVar4;
LAB_1c00059ca:
  WmiCompleteRequest(param_1,param_2,uVar5,uVar4,0);
  return;
}



===== MouseToggleWaitWake @ 1c0005a08 =====

undefined8 MouseToggleWaitWake(undefined8 *param_1,undefined1 param_2)

{
  undefined8 *puVar1;
  char cVar2;
  undefined8 uVar3;
  longlong lVar4;
  longlong lVar5;
  
  puVar1 = param_1 + 4;
  uVar3 = IoAcquireRemoveLockEx(puVar1,MouseToggleWaitWakeWorker,"",1,0x20);
  if (-1 < (int)uVar3) {
    lVar4 = ExAllocatePool2(0x40,0x20,0x43756f4d);
    if (lVar4 == 0) {
      IoReleaseRemoveLockEx(puVar1,MouseToggleWaitWakeWorker,0x20);
    }
    else {
      lVar5 = IoAllocateWorkItem(*param_1);
      *(longlong *)(lVar4 + 0x10) = lVar5;
      if (lVar5 == 0) {
        IoReleaseRemoveLockEx(puVar1,MouseToggleWaitWakeWorker,0x20);
        ExFreePoolWithTag(lVar4,0);
        return 0xc000009a;
      }
      *(undefined8 **)(lVar4 + 8) = param_1;
      *(undefined1 *)(lVar4 + 0x18) = param_2;
      cVar2 = KeGetCurrentIrql();
      if (cVar2 == '\0') {
        MouseToggleWaitWakeWorker(*param_1,lVar4);
      }
      else {
        IoQueueWorkItem(*(undefined8 *)(lVar4 + 0x10),MouseToggleWaitWakeWorker,1,lVar4);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



===== MouseToggleWaitWakeWorker @ 1c0005b50 =====

void MouseToggleWaitWakeWorker(undefined8 param_1,longlong param_2)

{
  char cVar1;
  longlong lVar2;
  bool bVar3;
  undefined1 uVar4;
  int iVar5;
  longlong lVar6;
  bool bVar7;
  uint local_res10 [2];
  undefined8 local_res18;
  undefined8 local_38;
  undefined8 uStack_30;
  
  lVar2 = *(longlong *)(param_2 + 8);
  lVar6 = 0;
  cVar1 = *(char *)(param_2 + 0x18);
  bVar3 = false;
  bVar7 = cVar1 != '\0';
  uVar4 = KeAcquireSpinLockRaiseToDpc(lVar2 + 0x48);
  if (bVar7 != (bool)*(char *)(lVar2 + 0x159)) {
    bVar3 = true;
    if (((*(char *)(lVar2 + 0x159) != '\0') && (*(longlong *)(lVar2 + 0x118) != 0)) &&
       (*(char *)(lVar2 + 0x120) == '\0')) {
      *(undefined1 *)(lVar2 + 0x120) = 1;
      lVar6 = *(longlong *)(lVar2 + 0x118);
    }
    *(bool *)(lVar2 + 0x159) = bVar7;
  }
  KeReleaseSpinLock(lVar2 + 0x48,uVar4);
  if (bVar3) {
    local_res18 = 0;
    local_res10[0] = (uint)bVar7;
    local_38 = 0;
    uStack_30 = 0;
    iVar5 = IoOpenDeviceRegistryKey(*(undefined8 *)(lVar2 + 0x18),1,0x1f0000,&local_res18);
    if (-1 < iVar5) {
      RtlInitUnicodeString(&local_38,L"WaitWakeEnabled");
      ZwSetValueKey(local_res18,&local_38,0,4,local_res10,4);
      ZwClose(local_res18);
    }
    if (cVar1 != '\0') {
      MouseClassCreateWaitWakeIrp(lVar2);
    }
  }
  if (lVar6 != 0) {
    IoCancelIrp(lVar6);
  }
  IoReleaseRemoveLockEx(lVar2 + 0x20,MouseToggleWaitWakeWorker,0x20);
  IoFreeWorkItem(*(undefined8 *)(param_2 + 0x10));
  ExFreePoolWithTag(param_2,0);
  return;
}



===== WPP_RECORDER_SF_D @ 1c0005cfc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_D(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x41,&uStack0000000000000030,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x41,
                  &uStack0000000000000030,4,0);
  return;
}



===== WPP_RECORDER_SF_Dd @ 1c0005da8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_Dd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0) && (3 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x42,&uStack0000000000000030,4,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,4,1,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x42,
                  &uStack0000000000000030,4,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_q @ 1c0005e78 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_q(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
                      undefined8 param_5,undefined1 param_6)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,&param_6,8,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,&param_6,8,0)
  ;
  return;
}



===== WPP_RECORDER_SF_qLL @ 1c0005f24 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLL(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,4,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,4,0);
  return;
}



===== WPP_RECORDER_SF_qLqq @ 1c000601c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qLqq
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,&param_6,8,&param_7,4,
               &param_8,8,&param_9,8,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,&param_6,8,
                  &param_7,4,&param_8,8,&param_9,8,0);
  return;
}



===== WPP_RECORDER_SF_qd @ 1c0006134 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 0x10) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
  {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x59,&uStack0000000000000030,8,
               &uStack0000000000000038,4,0);
  }
  WppAutoLogTrace(param_1,2,5,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x59,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,0);
  return;
}



===== WPP_RECORDER_SF_qlqqd @ 1c0006208 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qlqqd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x3b,&uStack0000000000000030,8,
               &uStack0000000000000038,4,&uStack0000000000000040,8,&uStack0000000000000048,8,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x3b,
                  &uStack0000000000000030,8,&uStack0000000000000038,4,&uStack0000000000000040,8,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  return;
}



===== WPP_RECORDER_SF_qqLL @ 1c0006344 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqLL(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x28,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,4,&uStack0000000000000048,4,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x28,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,4,
                  &uStack0000000000000048,4,0);
  return;
}



===== WPP_RECORDER_SF_qqLd @ 1c000645c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqLd(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined4 local_18 [2];
  undefined4 local_10 [2];
  
  local_18[0] = 0xc0000023;
  local_10[0] = 0xf0000;
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 8) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x19,&uStack0000000000000030,8,
               &uStack0000000000000038,8,local_10,4,local_18,4,0);
  }
  WppAutoLogTrace(param_1,2,4,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x19,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,local_10,4,local_18,4,0);
  return;
}



===== WPP_RECORDER_SF_qqLqq @ 1c0006584 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqLqq
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4,
               undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8,
               undefined1 param_9,undefined1 param_10)

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,4,&param_9,8,&param_10,8,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,4,&param_9,8,&param_10,8,0);
  return;
}



===== WPP_RECORDER_SF_qqq @ 1c00066c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined2 param_4
                        ,undefined8 param_5,undefined1 param_6,undefined1 param_7,undefined1 param_8
                        )

{
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 2) != 0) && (1 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,&param_6,8,&param_7,8,
               &param_8,8,0);
  }
  WppAutoLogTrace(param_1,2,2,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,param_4,&param_6,8,
                  &param_7,8,&param_8,8,0);
  return;
}



===== WPP_RECORDER_SF_qqqql @ 1c00067ac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_RECORDER_SF_qqqql(undefined8 param_1)

{
  undefined1 uStack0000000000000030;
  undefined1 uStack0000000000000038;
  undefined1 uStack0000000000000040;
  undefined1 uStack0000000000000048;
  undefined1 uStack0000000000000050;
  
  if (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 4) != 0) && (4 < (byte)WPP_GLOBAL_Control[0x29])) {
    (*pfnWppTraceMessage)
              (*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,
               &WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x2d,&uStack0000000000000030,8,
               &uStack0000000000000038,8,&uStack0000000000000040,8,&uStack0000000000000048,8,
               &uStack0000000000000050,4,0);
  }
  WppAutoLogTrace(param_1,5,3,&WPP_d07d70ae1de939905882a75eef030211_Traceguids,0x2d,
                  &uStack0000000000000030,8,&uStack0000000000000038,8,&uStack0000000000000040,8,
                  &uStack0000000000000048,8,&uStack0000000000000050,4,0);
  return;
}



===== WppClassicProviderCallback @ 1c00068f0 =====

void WppClassicProviderCallback
               (undefined8 param_1,byte param_2,undefined8 *param_3,longlong param_4)

{
  undefined8 uVar1;
  
  if (param_2 < 2) {
    if (param_2 == 0) {
      *(undefined1 *)(param_4 + 0x29) = 0;
      *(undefined4 *)(param_4 + 0x2c) = 0;
      *(undefined8 *)(param_4 + 0x18) = 0;
    }
    else {
      *(undefined4 *)(param_4 + 0x2c) = *(undefined4 *)((longlong)param_3 + 4);
      *(undefined1 *)(param_4 + 0x29) = *(undefined1 *)((longlong)param_3 + 2);
      uVar1 = *param_3;
      *(undefined8 *)(param_4 + 0x18) = uVar1;
      imp_WppRecorderReplay
                (WPP_GLOBAL_Control,uVar1,*(undefined4 *)((longlong)param_3 + 4),
                 *(undefined1 *)((longlong)param_3 + 2));
    }
  }
  return;
}



===== _tlgDefineProvider_annotation__Tlgg_TraceLoggingProviderProv @ 1c000694c =====

void _tlgDefineProvider_annotation__Tlgg_TraceLoggingProviderProv(void)

{
  return;
}



===== _guard_check_icall @ 1c0006960 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0006978 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000699c =====

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



===== __cpu_features_init @ 1c0006a10 =====

/* WARNING: Removing unreachable block (ram,0x0001c0006a7a) */
/* WARNING: Removing unreachable block (ram,0x0001c0006a29) */
/* WARNING: Removing unreachable block (ram,0x0001c0006a1a) */

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



===== __security_check_cookie @ 1c0006ae0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0006b20 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0006b50 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0006b50. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0006b80 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0006c00 =====

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



===== memset @ 1c0006f00 =====

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



===== __memset_repmovs @ 1c0007040 =====

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



===== __memset_query @ 1c00070c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0007140 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0007280 =====

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



===== __memset_spec_plain @ 1c0007300 =====

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



===== MouDeterminePortsServiced @ 1c000e010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int MouDeterminePortsServiced(ushort *param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  undefined8 local_18;
  undefined8 uStack_10;
  
  *param_2 = 0;
  if ((ulonglong)param_1[1] < (ulonglong)*param_1 + 2) {
    return -0x3fffffff;
  }
  *(undefined2 *)(*(longlong *)(param_1 + 4) + 2 + (ulonglong)(*param_1 >> 1) * 2) = 0;
  puVar3 = (undefined8 *)ExAllocatePool2(0x100,0x70,0x43756f4d);
  if (puVar3 == (undefined8 *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x4b);
    }
    iVar2 = -0x3fffffff;
  }
  else {
    puVar3[2] = 0;
    *puVar3 = MouDeviceMapQueryCallback;
    uVar1 = *(undefined8 *)(param_1 + 4);
    local_18 = 0;
    uStack_10 = 0;
    RtlInitUnicodeString(&local_18,L"RtlQueryRegistryValuesEx");
    pcVar4 = (code *)MmGetSystemRoutineAddress(&local_18);
    uVar6 = 0;
    if (pcVar4 == (code *)0x0) {
      pcVar4 = RtlQueryRegistryValues_exref;
    }
    puVar5 = puVar3;
    iVar2 = (*pcVar4)(0x80000004,uVar1,puVar3,param_2);
    if ((iVar2 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,puVar5,0x4c,uVar6,(char)iVar2);
    }
    ExFreePoolWithTag(puVar3,0);
  }
  return iVar2;
}



===== MouseClassFindMorePorts @ 1c000e190 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void MouseClassFindMorePorts(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  code *pcVar3;
  int iVar4;
  ulonglong uVar5;
  wchar_t *pwVar6;
  longlong *plVar7;
  uint uVar8;
  int iVar9;
  undefined1 auStackY_2c8 [32];
  uint local_288 [2];
  longlong local_280;
  undefined8 local_278;
  longlong lStack_270;
  ushort local_268 [4];
  undefined1 *local_260;
  longlong local_258;
  wchar_t *local_250 [3];
  undefined1 local_238 [512];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_2c8;
  local_268[0] = 0;
  local_268[1] = 0x200;
  local_268[2] = 0;
  local_268[3] = 0;
  local_258 = 0;
  local_288[0] = 0;
  pwVar6 = (wchar_t *)0x0;
  local_280 = 0;
  local_250[0] = (wchar_t *)0x0;
  local_278 = 0;
  lStack_270 = 0;
  memset(local_238,0,0x200);
  local_260 = local_238;
  RtlCopyUnicodeString(local_268,&DAT_1c000b370);
  local_268[0] = local_268[0] - 10;
  RtlAppendUnicodeToString(local_268,L"Port");
  RtlInitUnicodeString(&local_278,0);
  local_278._0_4_ = CONCAT22(local_268[0] + 0x14,(undefined2)local_278);
  lStack_270 = ExAllocatePool2(0x100,local_268[0] + 0x14,0x43756f4d);
  if (lStack_270 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x54);
    }
    local_250[0] = (wchar_t *)CONCAT44(local_250[0]._4_4_,(uint)local_278._2_2_);
    MouseClassLogError(param_1,0xc0050001,0x4e28,0xc0000001,1,(undefined4 *)local_250,0);
  }
  else {
    RtlAppendUnicodeToString(&local_278,L"\\Device\\");
    RtlAppendUnicodeToString(&local_278,local_260);
    RtlAppendUnicodeToString(&local_278,L"0");
    MouDeterminePortsServiced(local_268,local_288);
    iVar9 = 0;
    uVar8 = DAT_1c000b1b8;
    if (DAT_1c000b1b8 < DAT_1c000b1fc) {
      do {
        if (local_288[0] <= uVar8) break;
        *(short *)(lStack_270 + -2 + (local_278 >> 1 & 0x7fff) * 2) = (short)uVar8 + 0x30;
        if (pwVar6 != (wchar_t *)0x0) {
          ExFreePoolWithTag(pwVar6,0);
          local_250[0] = (wchar_t *)0x0;
        }
        uVar5 = MouCreateClassObject(param_1,(longlong *)&DAT_1c000b200,&local_258,local_250,'\x01')
        ;
        if ((int)uVar5 < 0) {
          MouseClassLogError(param_1,0xc0050001,0x4e28,(int)uVar5,0,(undefined4 *)0x0,0);
          pwVar6 = local_250[0];
        }
        else {
          plVar1 = *(longlong **)(local_258 + 0x40);
          *plVar1 = local_258;
          *(undefined1 *)(plVar1 + 8) = 0;
          iVar4 = IoGetDeviceObjectPointer(&local_278,0x80,&local_280,plVar1 + 2);
          pwVar6 = local_250[0];
          if (iVar4 == 0) {
            *(char *)(local_258 + 0x4c) = *(char *)(plVar1[2] + 0x4c) + '\x01';
            uVar5 = MouseAddDeviceEx(plVar1,local_250[0],local_280);
            *(uint *)(local_258 + 0x30) = *(uint *)(local_258 + 0x30) & 0xffffff7f;
            if (pwVar6 != (wchar_t *)0x0) {
              ExFreePoolWithTag(pwVar6,0);
              pwVar6 = (wchar_t *)0x0;
              local_250[0] = (wchar_t *)0x0;
            }
            if ((int)uVar5 < 0) {
              if (Globals == 0) {
                lVar2 = plVar1[0x2a];
                if (lVar2 != 0) {
                  plVar1[0x2a] = 0;
                  local_280 = lVar2;
                }
              }
              else {
                ExAcquireFastMutex(&DAT_1c000b1c0);
                local_280 = *(longlong *)
                             (DAT_1c000b1a8 + (ulonglong)*(uint *)((longlong)plVar1 + 0xb4) * 0x18);
                *(undefined8 *)
                 (DAT_1c000b1a8 + (ulonglong)*(uint *)((longlong)plVar1 + 0xb4) * 0x18) = 0;
                *(undefined1 *)
                 (DAT_1c000b1a8 + 0x13 + (ulonglong)*(uint *)((longlong)plVar1 + 0xb4) * 0x18) = 1;
                *(undefined8 *)
                 (DAT_1c000b1a8 + 8 + (ulonglong)*(uint *)((longlong)plVar1 + 0xb4) * 0x18) = 0;
                ExReleaseFastMutex(&DAT_1c000b1c0);
              }
              if (local_280 != 0) {
                ObfDereferenceObject();
              }
              if (plVar1[0xd] != 0) {
                ExFreePoolWithTag(plVar1[0xd],0);
                plVar1[0xf] = 0;
                plVar1[0xe] = 0;
                plVar1[0xd] = 0;
              }
              IoDeleteDevice(*plVar1);
            }
            else {
              plVar7 = plVar1 + 0x28;
              if ((undefined8 *)*DAT_1c000b588 != &DAT_1c000b580) {
                pcVar3 = (code *)swi(0x29);
                (*pcVar3)(3);
                pcVar3 = (code *)swi(3);
                (*pcVar3)();
                return;
              }
              *plVar7 = (longlong)&DAT_1c000b580;
              iVar9 = iVar9 + 1;
              plVar1[0x29] = (longlong)DAT_1c000b588;
              *DAT_1c000b588 = (longlong)plVar7;
              DAT_1c000b588 = plVar7;
            }
          }
          else {
            if (plVar1[0xd] != 0) {
              ExFreePoolWithTag(plVar1[0xd],0);
              plVar1[0xf] = 0;
              plVar1[0xe] = 0;
              plVar1[0xd] = 0;
            }
            IoDeleteDevice(*plVar1);
            pwVar6 = local_250[0];
          }
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < DAT_1c000b1fc);
    }
    DAT_1c000b1b8 = DAT_1c000b1b8 + iVar9;
  }
  if (lStack_270 != 0) {
    ExFreePoolWithTag(lStack_270,0);
  }
  if (pwVar6 != (wchar_t *)0x0) {
    ExFreePoolWithTag(pwVar6,0);
  }
  return;
}



===== MouseClassPassThrough @ 1c000e660 =====

void MouseClassPassThrough(longlong param_1,longlong param_2)

{
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x10));
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 1c000e690 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong TraceLoggingRegisterEx_EtwRegister_EtwSetInformation(void)

{
  undefined2 uVar1;
  code *pcVar2;
  ulonglong uVar3;
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
  local_28 = *(undefined4 *)(PTR_DAT_1c000b008 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_1c000b008 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_1c000b008 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_1c000b008 + -4);
  if (DAT_1c000b020 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_1c000b028 = 0;
  uRam00000001c000b030 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x1c000e6f2;
  uVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_1c000b000,&DAT_1c000b020);
  if ((int)uVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_1c000b008;
    *(undefined8 *)(puVar4 + -8) = 0x1c000e719;
    EtwSetInformation(DAT_1c000b020,2,PTR_DAT_1c000b008,uVar1);
    uVar3 = uVar3 & 0xffffffff;
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c000e72d;
  return uVar3;
}



===== WppLoadTracingSupport @ 1c000e740 =====

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



===== WppInitKm @ 1c000e890 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WppInitKm(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined *puVar2;
  
  if (WPP_GLOBAL_Control != &WPP_MAIN_CB) {
    WPP_GLOBAL_Control = &WPP_MAIN_CB;
    if (WPPTraceSuite == 4) {
      puVar2 = &WPP_MAIN_CB;
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
    WppAutoLogStart(WPP_GLOBAL_Control,param_1,param_2);
    WPP_RECORDER_INITIALIZED = &WPP_MAIN_CB;
  }
  return;
}



===== MouDeviceMapQueryCallback @ 1c000e970 =====

undefined8 MouDeviceMapQueryCallback(void)

{
  int *in_stack_00000028;
  
  *in_stack_00000028 = *in_stack_00000028 + 1;
  return 0;
}



===== MouseClassEnableGlobalPort @ 1c000e984 =====

int MouseClassEnableGlobalPort(longlong *param_1,char param_2)

{
  undefined8 *puVar1;
  char cVar2;
  int iVar3;
  ulonglong uVar4;
  
  iVar3 = 0;
  ExAcquireFastMutex(&DAT_1c000b1c0);
  if (DAT_1c000b1b4 < 1) {
    ExReleaseFastMutex(&DAT_1c000b1c0);
  }
  else {
    for (uVar4 = 0; (uint)uVar4 < DAT_1c000b1b0; uVar4 = (ulonglong)((uint)uVar4 + 1)) {
      puVar1 = (undefined8 *)(DAT_1c000b1a8 + uVar4 * 0x18);
      if ((*(char *)((longlong)puVar1 + 0x13) == '\0') && ((longlong *)puVar1[1] == param_1)) {
        if (puVar1 != (undefined8 *)0x0) {
          cVar2 = *(char *)(puVar1 + 2);
          *(char *)(puVar1 + 2) = param_2;
          ExReleaseFastMutex(&DAT_1c000b1c0);
          if (param_2 != cVar2) {
            iVar3 = MouEnableDisablePort(param_2,0,param_1,puVar1);
          }
          goto LAB_1c000ea5a;
        }
        break;
      }
    }
    ExReleaseFastMutex(&DAT_1c000b1c0);
    iVar3 = -0x3ffffff2;
  }
LAB_1c000ea5a:
  return iVar3;
}



===== MouseClassPlugPlayNotification @ 1c000ea80 =====

void MouseClassPlugPlayNotification(longlong param_1,longlong *param_2)

{
  char cVar1;
  longlong lVar2;
  
  lVar2 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4006;
  if (lVar2 == 0) {
    lVar2 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
  }
  if (lVar2 != 0) {
    lVar2 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4008;
    if (lVar2 == 0) {
      lVar2 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
    }
    if (lVar2 != 0) {
      lVar2 = *(longlong *)(param_1 + 4) + -0x11d046f0cb3a4007;
      if (lVar2 == 0) {
        lVar2 = *(longlong *)(param_1 + 0xc) + -0x3f05139760008fb0;
      }
      if (lVar2 != 0) {
        return;
      }
      LOCK();
      lVar2 = param_2[0x27];
      param_2[0x27] = 0;
      UNLOCK();
      if (lVar2 == 0) {
        return;
      }
      IoUnregisterPlugPlayNotification();
      cVar1 = '\x01';
      goto LAB_1c000eb23;
    }
    LOCK();
    lVar2 = param_2[0x27];
    param_2[0x27] = 0;
    UNLOCK();
    if (lVar2 == 0) {
      return;
    }
    IoUnregisterPlugPlayNotification();
  }
  cVar1 = '\0';
LAB_1c000eb23:
  MouseClassEnableGlobalPort(param_2,cVar1);
  return;
}



===== MouseClassSetWmiDataBlock @ 1c000eb40 =====

void MouseClassSetWmiDataBlock
               (longlong param_1,undefined8 param_2,int param_3,int param_4,int param_5,
               undefined1 *param_6)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_3 == 0) {
    uVar1 = 0xc00002c6;
  }
  else if (param_3 == 1) {
    uVar3 = 1;
    if (param_5 == 0) {
      uVar1 = 0xc0000023;
    }
    else if (param_4 == 0) {
      uVar2 = MouseToggleWaitWake(*(undefined8 **)(param_1 + 0x40),*param_6);
      uVar1 = (undefined4)uVar2;
    }
    else {
      uVar1 = 0xc0000010;
    }
  }
  else {
    uVar1 = 0xc0000295;
  }
  WmiCompleteRequest(param_1,param_2,uVar1,uVar3,0);
  return;
}



===== MouseClassSetWmiDataItem @ 1c000ebe0 =====

void MouseClassSetWmiDataItem
               (longlong param_1,undefined8 param_2,int param_3,int param_4,int param_5,int param_6,
               undefined1 *param_7)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  if (param_3 == 0) {
    uVar1 = 0xc00002c6;
  }
  else if (param_3 == 1) {
    if (param_6 == 0) {
      uVar1 = 0xc0000023;
    }
    else if ((param_5 == 1) && (param_4 == 0)) {
      uVar2 = MouseToggleWaitWake(*(undefined8 **)(param_1 + 0x40),*param_7);
      uVar1 = (undefined4)uVar2;
    }
    else {
      uVar1 = 0xc0000010;
    }
  }
  else {
    uVar1 = 0xc0000295;
  }
  WmiCompleteRequest(param_1,param_2,uVar1,0,0);
  return;
}



===== WppCleanupKm @ 1c000ec6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WppCleanupKm(undefined8 param_1)

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
    WppAutoLogStop(WPP_GLOBAL_Control,param_1);
    WPP_GLOBAL_Control = (undefined *)&WPP_GLOBAL_Control;
    WPP_RECORDER_INITIALIZED = (undefined *)&WPP_RECORDER_INITIALIZED;
  }
  return;
}



===== WppTraceCallback @ 1c000ed20 =====

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



===== MouEnableDisablePort @ 1c000efb0 =====

int MouEnableDisablePort(char param_1,longlong param_2,longlong *param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  longlong lVar2;
  undefined4 uVar3;
  int iVar4;
  longlong lVar5;
  undefined4 local_res18 [2];
  undefined8 local_48;
  undefined8 local_40;
  longlong local_38;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  
  iVar4 = 0;
  local_40 = 0;
  local_38 = 0;
  local_48 = 0;
  local_res18[0] = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x4d);
  }
  if (param_3[1] == *param_3) {
    if ((char)param_3[8] != '\0') {
      puVar1 = *(undefined8 **)(param_2 + 0xb8);
      puVar1[-9] = *puVar1;
      puVar1[-8] = puVar1[1];
      puVar1[-7] = puVar1[2];
      puVar1[-6] = puVar1[3];
      puVar1[-5] = puVar1[4];
      puVar1[-4] = puVar1[5];
      puVar1[-3] = puVar1[6];
      *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
      if ((param_1 == '\0') && (*(char *)(*(longlong *)(param_2 + 0xb8) + -0x48) != '\x02')) {
        *(undefined1 *)(*(longlong *)(param_2 + 0xb8) + -0x48) = 2;
      }
      lVar5 = param_3[2];
      local_20 = 0;
      local_30 = 0;
      uStack_28 = 0;
      KeInitializeEvent(&local_30,1,0);
      lVar2 = *(longlong *)(param_2 + 0xb8);
      *(code **)(lVar2 + -0x10) = MouSyncComplete;
      *(undefined8 **)(lVar2 + -8) = &local_30;
      *(undefined1 *)(lVar2 + -0x45) = 0xe0;
      IofCallDriver(lVar5,param_2);
      KeWaitForSingleObject(&local_30,0,0,0,0);
      iVar4 = *(int *)(param_2 + 0x30);
      goto LAB_1c000f0cc;
    }
  }
  else if ((char)param_3[8] != '\0') {
    if (param_1 == '\0') {
      ObfDereferenceObject(*param_4);
      *param_4 = 0;
    }
    else {
      IoGetDeviceProperty(param_3[3],0xb,0,0,local_res18);
      lVar5 = ExAllocatePool2(0x100,local_res18[0],0x43756f4d);
      if (lVar5 == 0) {
        return -0x3fffff66;
      }
      IoGetDeviceProperty(param_3[3],0xb,local_res18[0],lVar5,local_res18);
      local_40 = CONCAT62(CONCAT42(local_40._4_4_,(short)local_res18[0]),(short)local_res18[0] + -2)
      ;
      local_38 = lVar5;
      iVar4 = IoGetDeviceObjectPointer(&local_40,0x1f01ff,param_4,&local_48);
      ExFreePoolWithTag(lVar5,0);
      if (-1 < iVar4) {
        iVar4 = IoRegisterPlugPlayNotification
                          (3,0,*param_4,*(undefined8 *)(*param_3 + 8),MouseClassPlugPlayNotification
                           ,param_3,param_3 + 0x27);
      }
    }
    goto LAB_1c000f0cc;
  }
  *(char *)(param_3 + 0x2b) = param_1;
  puVar1 = *(undefined8 **)(param_2 + 0xb8);
  puVar1[-9] = *puVar1;
  puVar1[-8] = puVar1[1];
  puVar1[-7] = puVar1[2];
  puVar1[-6] = puVar1[3];
  puVar1[-5] = puVar1[4];
  puVar1[-4] = puVar1[5];
  puVar1[-3] = puVar1[6];
  *(undefined1 *)((longlong)puVar1 + -0x45) = 0;
  lVar5 = *(longlong *)(param_2 + 0xb8);
  uVar3 = 0xf0803;
  if (param_1 == '\0') {
    uVar3 = 0xf1003;
  }
  *(undefined4 *)(lVar5 + -0x40) = 0;
  *(undefined4 *)(lVar5 + -0x38) = 0;
  *(undefined4 *)(lVar5 + -0x30) = uVar3;
  *(undefined8 *)(lVar5 + -0x28) = 0;
  *(undefined1 *)(lVar5 + -0x48) = 0xf;
  iVar4 = MouseSendIrpSynchronously(param_3[2],param_2,'\0');
LAB_1c000f0cc:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x4e);
  }
  return iVar4;
}



===== MouseClassDeviceControl @ 1c000f310 =====

int MouseClassDeviceControl(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  uint uVar2;
  longlong lVar3;
  undefined8 *puVar4;
  int iVar5;
  ulonglong uVar6;
  longlong *plVar7;
  undefined4 uVar8;
  undefined4 in_stack_ffffffffffffffac;
  
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x17);
  }
  plVar7 = *(longlong **)(param_1 + 0x40);
  lVar3 = *(longlong *)(param_2 + 0xb8);
  uVar8 = 0x20;
  plVar1 = plVar7 + 4;
  iVar5 = IoAcquireRemoveLockEx(plVar1,param_2,"",1);
  if (iVar5 < 0) {
    *(int *)(param_2 + 0x30) = iVar5;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
    return iVar5;
  }
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_qqL(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,4,0x18,
                        CONCAT44(in_stack_ffffffffffffffac,uVar8),(char)param_1,(char)param_2,
                        (char)*(undefined4 *)(lVar3 + 0x18));
  }
  uVar2 = *(uint *)(lVar3 + 0x18);
  if (uVar2 == 0xb0268) {
switchD_1c000f5cc_caseD_b0190:
    if (((char)plVar7[8] == '\0') || (plVar7 == Globals)) goto switchD_1c000f5cc_caseD_b0195;
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
LAB_1c000f3dc:
    iVar5 = IofCallDriver(plVar7[2],param_2);
    goto LAB_1c000f3f1;
  }
  if (uVar2 < 0xf0001) {
    if (uVar2 != 0xf0000) {
      switch(uVar2) {
      case 0xb0190:
      case 0xb0191:
      case 0xb0192:
      case 0xb0193:
      case 0xb0194:
      case 0xb0197:
      case 0xb0198:
      case 0xb019a:
      case 0xb019c:
      case 0xb019e:
      case 0xb01a0:
      case 0xb01a4:
      case 0xb01a8:
      case 0xb01ba:
      case 0xb01be:
      case 0xb01c2:
      case 0xb01e2:
        goto switchD_1c000f5cc_caseD_b0190;
      }
      goto switchD_1c000f5cc_caseD_b0195;
    }
    if (*(uint *)(lVar3 + 0x10) == 0) {
      uVar6 = 0;
LAB_1c000f4c0:
      if (*plVar7 == plVar7[1]) {
        if (plVar7 != Globals) {
LAB_1c000f4da:
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
          *(undefined1 *)(*(longlong *)(param_2 + 0xb8) + -0x48) = 0xf;
          goto LAB_1c000f3dc;
        }
        ExAcquireFastMutex(&DAT_1c000b1c0);
        if ((uint)uVar6 < DAT_1c000b1b0) {
          if (DAT_1c000b1b0 == 0) {
LAB_1c000f649:
            if ((uint)uVar6 < DAT_1c000b1b0) {
              plVar7 = *(longlong **)(DAT_1c000b1a8 + 8 + uVar6 * 0x18);
              *(undefined8 *)(lVar3 + 0x30) = *(undefined8 *)(DAT_1c000b1a8 + uVar6 * 0x18);
              ExReleaseFastMutex(&DAT_1c000b1c0);
              goto LAB_1c000f4da;
            }
          }
          else {
            if ((*(char *)(DAT_1c000b1a8 + 0x10 + uVar6 * 0x18) == '\0') ||
               (*(char *)(DAT_1c000b1a8 + 0x13 + uVar6 * 0x18) != '\0')) {
              uVar6 = 0;
            }
            while( true ) {
              if ((*(char *)(DAT_1c000b1a8 + 0x10 + uVar6 * 0x18) != '\0') &&
                 (*(char *)(DAT_1c000b1a8 + 0x13 + uVar6 * 0x18) == '\0')) goto LAB_1c000f649;
              if (DAT_1c000b1b0 <= (uint)uVar6) break;
              uVar6 = (ulonglong)((uint)uVar6 + 1);
            }
          }
        }
        ExReleaseFastMutex(&DAT_1c000b1c0);
        iVar5 = -0x3ffffff3;
      }
      else {
        iVar5 = -0x3fffff45;
      }
    }
    else {
      if (1 < *(uint *)(lVar3 + 0x10)) {
        uVar6 = (ulonglong)**(ushort **)(param_2 + 0x18);
        goto LAB_1c000f4c0;
      }
      iVar5 = -0x3fffffdd;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_qqLd(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
      }
    }
  }
  else {
    if ((uVar2 == 0x294140) || (uVar2 == 0x294144)) goto switchD_1c000f5cc_caseD_b0190;
switchD_1c000f5cc_caseD_b0195:
    iVar5 = -0x3ffffff0;
  }
  *(int *)(param_2 + 0x30) = iVar5;
  *(undefined8 *)(param_2 + 0x38) = 0;
  IofCompleteRequest(param_2,0);
LAB_1c000f3f1:
  IoReleaseRemoveLockEx(plVar1,param_2,0x20);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,4,0x1a);
  }
  return iVar5;
}



===== MouseSendIrpSynchronously @ 1c000f6a0 =====

undefined4 MouseSendIrpSynchronously(undefined8 param_1,longlong param_2,char param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  KeInitializeEvent(&local_28,1,0);
  if (param_3 != '\0') {
    puVar2 = *(undefined8 **)(param_2 + 0xb8);
    puVar2[-9] = *puVar2;
    puVar2[-8] = puVar2[1];
    puVar2[-7] = puVar2[2];
    puVar2[-6] = puVar2[3];
    *(undefined4 *)(puVar2 + -5) = *(undefined4 *)(puVar2 + 4);
    *(undefined4 *)((longlong)puVar2 + -0x24) = *(undefined4 *)((longlong)puVar2 + 0x24);
    *(undefined4 *)(puVar2 + -4) = *(undefined4 *)(puVar2 + 5);
    *(undefined4 *)((longlong)puVar2 + -0x1c) = *(undefined4 *)((longlong)puVar2 + 0x2c);
    puVar2[-3] = puVar2[6];
    *(undefined1 *)((longlong)puVar2 + -0x45) = 0;
  }
  lVar1 = *(longlong *)(param_2 + 0xb8);
  *(code **)(lVar1 + -0x10) = MouSyncComplete;
  *(undefined8 **)(lVar1 + -8) = &local_28;
  *(undefined1 *)(lVar1 + -0x45) = 0xe0;
  IofCallDriver(param_1,param_2);
  KeWaitForSingleObject(&local_28,0,0,0,0);
  return *(undefined4 *)(param_2 + 0x30);
}



===== MouseAddDevice @ 1c000f790 =====

ulonglong MouseAddDevice(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  wchar_t *pwVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined4 *puVar6;
  longlong local_res18;
  wchar_t *local_res20;
  
  local_res18 = 0;
  local_res20 = (wchar_t *)0x0;
  uVar4 = MouCreateClassObject(param_1,(longlong *)&DAT_1c000b200,&local_res18,&local_res20,'\0');
  if (-1 < (int)uVar4) {
    plVar1 = *(longlong **)(local_res18 + 0x40);
    lVar5 = IoAttachDeviceToDeviceStack(local_res18,param_2);
    plVar1[2] = lVar5;
    if (lVar5 == 0) {
      puVar6 = (undefined4 *)IoAllocateErrorLogEntry(param_1,0x30);
      if (puVar6 != (undefined4 *)0x0) {
        puVar6[3] = 0xc005000f;
        *puVar6 = 0;
        *(undefined8 *)(puVar6 + 6) = 0;
        puVar6[4] = 0;
        puVar6[5] = 0xc000009d;
        IoWriteErrorLogEntry(puVar6);
      }
      IoDeleteDevice(local_res18);
      uVar4 = 0xc000009d;
    }
    else {
      plVar1[3] = param_2;
      *(undefined2 *)(plVar1 + 8) = 1;
      *(undefined4 *)((longlong)plVar1 + 0xac) = 1;
      *(undefined4 *)(plVar1 + 0x16) = 1;
      PoSetPowerState(local_res18);
      *(undefined8 *)((longlong)plVar1 + 0x10c) = 0;
      *(undefined1 *)((longlong)plVar1 + 0x159) = 0;
      plVar1[0x23] = 0;
      *(undefined1 *)(plVar1 + 0x24) = 0;
      plVar1[0x25] = 0;
      *(undefined4 *)(plVar1 + 0x26) = 0;
      *(uint *)(local_res18 + 0x30) = *(uint *)(local_res18 + 0x30) | 0x2000;
      *(uint *)(local_res18 + 0x30) = *(uint *)(local_res18 + 0x30) & 0xffffff7f;
      uVar3 = IoRegisterDeviceInterface(param_2,&GUID_DEVINTERFACE_MOUSE,0,plVar1 + 0xb);
      pwVar2 = local_res20;
      uVar4 = (ulonglong)uVar3;
      if ((int)uVar3 < 0) {
        IoDetachDevice(plVar1[2]);
        plVar1[2] = 0;
        IoDeleteDevice(local_res18);
      }
      else {
        uVar4 = MouseAddDeviceEx(plVar1,local_res20,0);
        uVar4 = uVar4 & 0xffffffff;
      }
      if (pwVar2 != (wchar_t *)0x0) {
        ExFreePoolWithTag(pwVar2,0);
      }
    }
  }
  return uVar4;
}



===== MouCreateClassObject @ 1c000f950 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong MouCreateClassObject
                    (longlong param_1,longlong *param_2,longlong *param_3,undefined8 *param_4,
                    char param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  longlong lVar4;
  longlong *plVar5;
  short sVar6;
  uint uVar7;
  ulonglong uVar8;
  longlong *plVar9;
  longlong lVar10;
  wchar_t *pwVar11;
  ulonglong uVar12;
  uint uVar13;
  longlong *plVar14;
  longlong *plVar15;
  undefined4 uVar16;
  int iVar17;
  undefined1 auStackY_b8 [32];
  undefined4 in_stack_ffffffffffffff68;
  undefined4 uVar18;
  undefined4 in_stack_ffffffffffffff6c;
  undefined8 local_78;
  wchar_t *local_70;
  undefined8 *local_68;
  longlong local_60;
  uint local_58 [4];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_b8;
  plVar14 = (longlong *)0x0;
  local_78 = 0;
  iVar17 = 0;
  local_70 = (wchar_t *)0x0;
  uVar13 = 0;
  uVar16 = 20000;
  local_68 = param_4;
  local_60 = param_1;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x44);
  }
  ExAcquireFastMutex(&DAT_1c000b1c0);
  *param_3 = 0;
  if (Globals == 0) {
    ExReleaseFastMutex();
    sVar6 = DAT_1c000b370 + 0x1e;
    local_78._0_4_ = CONCAT22(sVar6,(ushort)local_78);
    if ((DAT_1c000b1f8 != 0) && (param_5 != '\0')) {
      sVar6 = DAT_1c000b370 + 0x2c;
      local_78._0_4_ = CONCAT22(sVar6,(ushort)local_78);
    }
    local_70 = (wchar_t *)ExAllocatePool2(0x100,sVar6,0x43756f4d);
    if (local_70 == (wchar_t *)0x0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x45);
      }
      uVar12 = 0xc0000001;
      iVar17 = -0x3ffaffff;
LAB_1c000fa8d:
      local_58[0] = (uint)local_78._2_2_;
      uVar16 = 0x4e26;
      uVar13 = 1;
      RtlFreeUnicodeString(&local_78);
      *local_68 = 0;
LAB_1c000fe6d:
      lVar10 = *param_3;
      if (*param_3 == 0) {
        lVar10 = local_60;
      }
      MouseClassLogError(lVar10,iVar17,uVar16,(int)uVar12,uVar13,local_58,0);
      goto LAB_1c000fe99;
    }
    do {
      if ((DAT_1c000b1f8 == 0) || (pwVar11 = L"\\Device\\%wZLegacy%d", param_5 == '\0')) {
        pwVar11 = L"\\Device\\%wZ%d";
      }
      uVar8 = (ulonglong)DAT_1c000b118;
      DAT_1c000b118 = DAT_1c000b118 + 1;
      uVar8 = RtlUnicodeStringPrintf((ushort *)&local_78,pwVar11,&DAT_1c000b370,uVar8);
      uVar12 = uVar8 & 0xffffffff;
      if ((int)uVar8 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x46,
                            CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),local_70);
        }
        iVar17 = -0x3ffafff3;
        goto LAB_1c000fa8d;
      }
      if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
         (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
        WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x47,
                          CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),local_70);
      }
      in_stack_ffffffffffffff68 = 0;
      uVar7 = IoCreateDevice(local_60,0x160,&local_78,0xf);
    } while (uVar7 == 0xc0000035);
    if ((local_78 & 0xffff) + 2 <= (local_78 >> 0x10 & 0xffff)) {
      local_70[(local_78 >> 1 & 0x7fff) + 1] = L'\0';
      *local_68 = local_70;
      goto LAB_1c000fc5d;
    }
    uVar12 = 0xc0000001;
    RtlFreeUnicodeString(&local_78);
    *local_68 = 0;
  }
  else {
    ExReleaseFastMutex(&DAT_1c000b1c0);
    in_stack_ffffffffffffff68 = 0;
    uVar7 = IoCreateDevice(param_1,0x160,0,0xf);
    *local_68 = 0;
LAB_1c000fc5d:
    uVar12 = (ulonglong)uVar7;
    if (((int)uVar7 < 0) || (*param_3 == 0)) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x48,
                          CONCAT44(in_stack_ffffffffffffff6c,in_stack_ffffffffffffff68),local_70);
      }
      iVar17 = -0x3ffafff3;
      local_58[0] = (uint)local_78._2_2_;
      uVar16 = 0x4e26;
      uVar13 = 1;
    }
    else {
      puVar1 = (uint *)(*param_3 + 0x30);
      *puVar1 = *puVar1 | 4;
      lVar10 = 2;
      plVar14 = *(longlong **)(*param_3 + 0x40);
      plVar5 = plVar14;
      do {
        plVar15 = param_2;
        plVar9 = plVar5;
        lVar4 = plVar15[1];
        *plVar9 = *plVar15;
        plVar9[1] = lVar4;
        lVar4 = plVar15[3];
        plVar9[2] = plVar15[2];
        plVar9[3] = lVar4;
        lVar4 = plVar15[5];
        plVar9[4] = plVar15[4];
        plVar9[5] = lVar4;
        lVar4 = plVar15[7];
        plVar9[6] = plVar15[6];
        plVar9[7] = lVar4;
        lVar4 = plVar15[9];
        plVar9[8] = plVar15[8];
        plVar9[9] = lVar4;
        lVar4 = plVar15[0xb];
        plVar9[10] = plVar15[10];
        plVar9[0xb] = lVar4;
        lVar4 = plVar15[0xd];
        plVar9[0xc] = plVar15[0xc];
        plVar9[0xd] = lVar4;
        lVar4 = plVar15[0xf];
        plVar9[0xe] = plVar15[0xe];
        plVar9[0xf] = lVar4;
        lVar10 = lVar10 + -1;
        plVar5 = plVar9 + 0x10;
        param_2 = plVar15 + 0x10;
      } while (lVar10 != 0);
      lVar10 = plVar15[0x11];
      uVar18 = 0x20;
      plVar9[0x10] = plVar15[0x10];
      plVar9[0x11] = lVar10;
      lVar10 = plVar15[0x13];
      plVar9[0x12] = plVar15[0x12];
      plVar9[0x13] = lVar10;
      lVar10 = plVar15[0x15];
      plVar9[0x14] = plVar15[0x14];
      plVar9[0x15] = lVar10;
      lVar10 = plVar15[0x17];
      plVar9[0x16] = plVar15[0x16];
      plVar9[0x17] = lVar10;
      uVar2 = *(undefined4 *)((longlong)plVar15 + 0xc4);
      lVar10 = plVar15[0x19];
      uVar3 = *(undefined4 *)((longlong)plVar15 + 0xcc);
      *(int *)(plVar9 + 0x18) = (int)plVar15[0x18];
      *(undefined4 *)((longlong)plVar9 + 0xc4) = uVar2;
      *(int *)(plVar9 + 0x19) = (int)lVar10;
      *(undefined4 *)((longlong)plVar9 + 0xcc) = uVar3;
      uVar2 = *(undefined4 *)((longlong)plVar15 + 0xd4);
      lVar10 = plVar15[0x1b];
      uVar3 = *(undefined4 *)((longlong)plVar15 + 0xdc);
      *(int *)(plVar9 + 0x1a) = (int)plVar15[0x1a];
      *(undefined4 *)((longlong)plVar9 + 0xd4) = uVar2;
      *(int *)(plVar9 + 0x1b) = (int)lVar10;
      *(undefined4 *)((longlong)plVar9 + 0xdc) = uVar3;
      *plVar14 = *param_3;
      IoInitializeRemoveLockEx(plVar14 + 4,0x43756f4d,0,0);
      KeInitializeSpinLock(plVar14 + 0x12);
      plVar5 = plVar14 + 0x13;
      plVar14[0x14] = (longlong)plVar5;
      *plVar5 = (longlong)plVar5;
      *(undefined4 *)(plVar14 + 10) = 0;
      lVar10 = ExAllocatePool2(0x40,(int)plVar14[0x11],0x43756f4d);
      plVar14[0xd] = lVar10;
      if (lVar10 == 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,2,0x49,
                            CONCAT44(in_stack_ffffffffffffff6c,uVar18),local_70);
        }
        uVar12 = 0xc000009a;
        iVar17 = -0x3ffafffe;
        uVar16 = 0x4e34;
        RtlFreeUnicodeString(&local_78);
        *local_68 = 0;
        goto LAB_1c000fe6d;
      }
      MouInitializeDataQueue((longlong)plVar14);
      uVar13 = 0;
    }
    if (uVar7 == 0) goto LAB_1c000fed2;
    RtlFreeUnicodeString(&local_78);
    *local_68 = 0;
    if (iVar17 != 0) goto LAB_1c000fe6d;
LAB_1c000fe99:
    if ((plVar14 != (longlong *)0x0) && (plVar14[0xd] != 0)) {
      ExFreePoolWithTag(plVar14[0xd],0);
      plVar14[0xd] = 0;
    }
  }
  if (*param_3 != 0) {
    IoDeleteDevice();
    *param_3 = 0;
  }
LAB_1c000fed2:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x4a);
  }
  return uVar12;
}



===== MouseAddDeviceEx @ 1c000ff40 =====

ulonglong MouseAddDeviceEx(longlong *param_1,wchar_t *param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  ulonglong uVar3;
  void *_Dst;
  char cVar4;
  longlong *plVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  undefined8 in_stack_ffffffffffffffa0;
  undefined4 uVar8;
  
  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffffa0 >> 0x20);
  uVar3 = 0;
  KeInitializeSpinLock(param_1 + 9);
  plVar5 = Globals;
  if (DAT_1c000b1f8 != 0) {
    plVar5 = param_1;
  }
  param_1[1] = *plVar5;
  if (Globals != param_1) {
    if (Globals != plVar5) {
      if (param_1 != plVar5) {
        return 0;
      }
      MouSendConnectRequest((longlong)param_1);
      goto LAB_1c00100de;
    }
    uVar3 = MouSendConnectRequest((longlong)param_1);
    uVar3 = uVar3 & 0xffffffff;
    ExAcquireFastMutex(&DAT_1c000b1c0);
    uVar6 = 0;
    while (uVar2 = (uint)uVar6, uVar2 < DAT_1c000b1b0) {
      if (*(char *)((longlong)DAT_1c000b1a8 + uVar6 * 0x18 + 0x13) != '\0') {
        *(undefined1 *)((longlong)DAT_1c000b1a8 + uVar6 * 0x18 + 0x13) = 0;
        break;
      }
      uVar6 = (ulonglong)(uVar2 + 1);
    }
    if (uVar2 == DAT_1c000b1b0) {
      _Dst = (void *)ExAllocatePool2(0x40,(ulonglong)(DAT_1c000b1b0 + 1) * 0x18,0x43756f4d);
      if (_Dst == (void *)0x0) {
        ExReleaseFastMutex(&DAT_1c000b1c0);
        return 0xc000009a;
      }
      if (DAT_1c000b1b0 != 0) {
        memcpy(_Dst,DAT_1c000b1a8,(ulonglong)DAT_1c000b1b0 * 0x18);
        ExFreePoolWithTag(DAT_1c000b1a8,0);
      }
      DAT_1c000b1b0 = DAT_1c000b1b0 + 1;
      DAT_1c000b1a8 = _Dst;
    }
    *(uint *)((longlong)param_1 + 0xb4) = uVar2;
    *(longlong **)(uVar6 * 0x18 + 8 + (longlong)DAT_1c000b1a8) = param_1;
    *(undefined8 *)(uVar6 * 0x18 + (longlong)DAT_1c000b1a8) = param_3;
    cVar1 = *(char *)(*plVar5 + 0x4c);
    cVar4 = *(char *)(*param_1 + 0x4c);
    if (*(char *)(*param_1 + 0x4c) <= cVar1) {
      cVar4 = cVar1;
    }
    *(char *)(*plVar5 + 0x4c) = cVar4;
    ExReleaseFastMutex(&DAT_1c000b1c0);
  }
  if (param_1 != plVar5) {
    return uVar3;
  }
LAB_1c00100de:
  uVar7 = DAT_1c000b368;
  uVar2 = RtlWriteRegistryValue
                    (4,DAT_1c000b378,param_2,1,DAT_1c000b368,CONCAT44(uVar8,DAT_1c000b360 + 2));
  if ((int)uVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x13,uVar7,param_2);
    }
    MouseClassLogError(param_1,0x80050005,0x4e2e,uVar2,0,(undefined4 *)0x0,0);
  }
  else if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x14,uVar7,param_2);
  }
  return (ulonglong)uVar2;
}



===== MouSendConnectRequest @ 1c00101f0 =====

ulonglong MouSendConnectRequest(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_48 [3];
  code *local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  
  local_48[0] = 0;
  local_48[1] = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x51);
  }
  KeInitializeEvent(&local_28,0,0);
  local_48[2] = *(undefined8 *)(param_1 + 8);
  local_30 = MouseClassServiceCallback;
  lVar1 = IoBuildDeviceIoControlRequest
                    (0xf0203,*(undefined8 *)(param_1 + 0x10),local_48 + 2,0x10,0,0,1,&local_28,
                     local_48);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = IofCallDriver(*(undefined8 *)(param_1 + 0x10),lVar1);
    if ((int)uVar2 == 0x103) {
      KeWaitForSingleObject(&local_28,0,0,0,0);
      uVar2 = local_48[0] & 0xffffffff;
      goto LAB_1c0010308;
    }
  }
  local_48[0] = CONCAT44(local_48[0]._4_4_,(int)uVar2);
LAB_1c0010308:
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,2,0x52);
    uVar2 = local_48[0] & 0xffffffff;
  }
  return uVar2;
}



===== MouseClassGetWaitWakeEnableState @ 1c0010360 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong MouseClassGetWaitWakeEnableState(longlong param_1)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined1 auStack_1c8 [32];
  undefined4 local_1a8;
  undefined8 local_198;
  int local_190 [2];
  undefined1 local_188 [3];
  char local_185;
  char local_184;
  char local_183;
  undefined4 local_138 [70];
  undefined1 local_1e;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_1c8;
  uVar4 = (uint)&local_198;
  local_198 = 0;
  local_190[0] = 0;
  uVar3 = 1;
  uVar2 = IoOpenDeviceRegistryKey(*(undefined8 *)(param_1 + 0x18),1,0x1f0000);
  if (-1 < (int)uVar2) {
    iVar1 = MouseQueryDeviceKey(local_198,uVar3,local_190,uVar4);
    if (-1 < iVar1) {
      *(bool *)(param_1 + 0x159) = local_190[0] != 0;
      uVar2 = ZwClose(local_198);
      return uVar2;
    }
    uVar2 = ZwClose();
    local_198 = 0;
  }
  if (*(char *)(param_1 + 0x159) == '\0') {
    memset(local_138,0,0x11c);
    local_138[0] = 0x11c;
    local_1e = 1;
    uVar3 = VerSetConditionMask(0,0x80,1);
    uVar2 = RtlVerifyVersionInfo(local_138,0x80,uVar3);
    if (-1 < (int)uVar2) {
      memset(local_188,0,0x4c);
      uVar4 = 4;
      local_1a8 = 0x4c;
      uVar2 = ZwPowerInformation(4,0,0,local_188);
      if (-1 < (int)uVar2) {
        if (local_183 == '\0') {
          if (local_184 == '\0') {
            uVar2 = (ulonglong)(byte)-local_185;
            uVar4 = -(uint)(local_185 != '\0') & 2;
          }
          else {
            uVar4 = 3;
          }
        }
        if ((int)uVar4 <= *(int *)(param_1 + 0x110)) {
          *(undefined1 *)(param_1 + 0x159) = 1;
        }
      }
    }
  }
  return uVar2;
}



===== MouseQueryDeviceKey @ 1c0010500 =====

int MouseQueryDeviceKey(undefined8 param_1,undefined8 param_2,void *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  uint local_res20 [2];
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_18 = 0;
  uStack_10 = 0;
  local_res20[0] = param_4;
  RtlInitUnicodeString(&local_18,L"WaitWakeEnabled");
  uVar1 = local_18._2_2_ + 0x18;
  if ((uVar1 < 0x18) || (local_res20[0] = local_18._2_2_ + 0x1c, local_res20[0] < uVar1)) {
    return -0x3fffff6b;
  }
  lVar3 = ExAllocatePool2(0x100,local_res20[0],0x43756f4d);
  if (lVar3 == 0) {
    iVar2 = -0x3fffffe9;
  }
  else {
    iVar2 = ZwQueryValueKey(param_1,&local_18,1,lVar3,local_res20[0],local_res20);
    if (-1 < iVar2) {
      if (*(uint *)(lVar3 + 0xc) < 5) {
        memcpy(param_3,(void *)((ulonglong)*(uint *)(lVar3 + 8) + lVar3),
               (ulonglong)*(uint *)(lVar3 + 0xc));
      }
      else {
        iVar2 = -0x3fffffdd;
      }
    }
    ExFreePoolWithTag(lVar3,0);
  }
  return iVar2;
}



===== _tlgEnableCallback @ 1c0010620 =====

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



===== MouseClassCreateWaitWakeIrpWorker @ 1c00106b0 =====

void MouseClassCreateWaitWakeIrpWorker(undefined8 param_1,longlong param_2)

{
  MouseClassCreateWaitWakeIrp(*(longlong *)(param_2 + 8));
  IoReleaseRemoveLockEx(*(longlong *)(param_2 + 8) + 0x20,param_2,0x20);
  IoFreeWorkItem(*(undefined8 *)(param_2 + 0x10));
  ExFreePoolWithTag(param_2,0);
  return;
}



===== MouseClassCreateWaitWakeIrp @ 1c0010710 =====

bool MouseClassCreateWaitWakeIrp(longlong param_1)

{
  int iVar1;
  
  iVar1 = PoRequestPowerIrp(*(undefined8 *)(param_1 + 0x18),0,*(undefined4 *)(param_1 + 0x110),
                            MouseClassWaitWakeComplete,param_1,0);
  return iVar1 == 0x103;
}



===== MouseClassSystemControl @ 1c0010760 =====

int MouseClassSystemControl(longlong param_1,longlong param_2)

{
  longlong lVar1;
  int iVar2;
  int local_res8 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  local_res8[0] = 0;
  iVar2 = IoAcquireRemoveLockEx(lVar1 + 0x20,param_2,"",1,0x20);
  if (iVar2 < 0) {
    *(int *)(param_2 + 0x30) = iVar2;
    *(undefined8 *)(param_2 + 0x38) = 0;
    IofCompleteRequest(param_2,0);
  }
  else {
    iVar2 = WmiSystemControl(lVar1 + 0xb8,param_1,param_2,local_res8);
    if (local_res8[0] == 1) {
      IofCompleteRequest(param_2,0);
    }
    else if (local_res8[0] != 0) {
      iVar2 = MouseClassPassThrough(param_1,param_2);
    }
    IoReleaseRemoveLockEx(lVar1 + 0x20,param_2,0x20);
  }
  return iVar2;
}



===== MouseClassQueryWmiRegInfo @ 1c0010860 =====

undefined8
MouseClassQueryWmiRegInfo
          (longlong param_1,undefined4 *param_2,undefined8 param_3,undefined8 *param_4,
          undefined8 param_5,undefined8 *param_6)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *param_2 = 0x20;
  *param_4 = &DAT_1c000b360;
  *param_6 = *(undefined8 *)(lVar1 + 0x18);
  return 0;
}



===== entry @ 1c0011010 =====

void entry(longlong param_1,ushort *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
  return;
}



===== __security_init_cookie @ 1c0011044 =====

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



===== DriverEntry @ 1c0011080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong DriverEntry(longlong param_1,ushort *param_2)

{
  longlong **pplVar1;
  longlong ****pppplVar2;
  undefined8 *puVar3;
  code *pcVar4;
  undefined8 uVar5;
  wchar_t *pwVar6;
  int iVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  longlong **pplVar10;
  longlong ****_Size;
  wchar_t *pwVar11;
  uint uVar12;
  undefined1 auStackY_2d8 [32];
  undefined4 in_stack_fffffffffffffd48;
  undefined4 in_stack_fffffffffffffd4c;
  undefined8 local_298;
  longlong lStack_290;
  uint local_288 [2];
  longlong ***local_280;
  longlong ****local_278;
  ushort local_270 [4];
  undefined1 *local_268;
  wchar_t *local_260 [3];
  undefined1 local_248 [512];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_2d8;
  _DAT_1c000b168 = 1;
  local_280 = (longlong ***)0x0;
  local_288[0] = 0;
  local_270[2] = 0;
  local_270[3] = 0;
  pwVar11 = (wchar_t *)0x0;
  local_298 = 0;
  lStack_290 = 0;
  local_260[0] = (wchar_t *)0x0;
  local_278 = (longlong ****)0x0;
  _WPP_MAIN_CB = 0;
  DAT_1c000b148 = &WPP_ThisDir_CTLGUID_MouClassTraceGuid;
  DAT_1c000b150 = 0;
  _DAT_1c000b160 = 0;
  _DAT_1c000b180 = 0;
  _DAT_1c000b188 = 0;
  WppLoadTracingSupport();
  _DAT_1c000b160 = 0;
  WppInitKm(param_1,param_2);
  if (((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,10);
  }
  TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
  memset(&Globals,0,0x3e0);
  DAT_1c000b588 = &DAT_1c000b580;
  DAT_1c000b580 = &DAT_1c000b580;
  RtlInitUnicodeString(&local_298,0);
  _DAT_1c000b1c0 = 1;
  _DAT_1c000b1c8 = 0;
  _DAT_1c000b1d0 = 0;
  KeInitializeEvent(&DAT_1c000b1d8);
  _DAT_1c000b370 = 0x2000000;
  DAT_1c000b378 = &DAT_1c000b380;
  memset(local_248,0,0x200);
  local_268 = local_248;
  local_270[0] = 0;
  local_270[1] = 0x200;
  DAT_1c000b360 = *param_2;
  _DAT_1c000b362 = *param_2 + 2;
  DAT_1c000b368 = (void *)ExAllocatePool2(0x40,_DAT_1c000b362,0x43756f4d);
  if (DAT_1c000b368 == (void *)0x0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0xb);
    }
    uVar9 = 0xc0000001;
    local_260[0] = (wchar_t *)CONCAT44(local_260[0]._4_4_,*param_2 + 2);
    _Size = (longlong ****)0x4e22;
    in_stack_fffffffffffffd48 = 1;
    MouseClassLogError(param_1,0xc0050001,0x4e22,0xc0000001,1,(undefined4 *)local_260,0);
LAB_1c0011983:
    if (local_298._2_2_ != 0) {
      ExFreePoolWithTag(lStack_290,0);
    }
    if (pwVar11 != (wchar_t *)0x0) {
      ExFreePoolWithTag(pwVar11,0);
    }
    if (-1 < (int)uVar9) {
      _Size = (longlong ****)0x0;
      IoRegisterDriverReinitialization(param_1,MouseClassFindMorePorts);
      uVar9 = 0;
      *(code **)(param_1 + 0x70) = MouseClassCreate;
      *(code **)(param_1 + 0x80) = MouseClassClose;
      *(code **)(param_1 + 0x88) = MouseClassRead;
      *(code **)(param_1 + 0xb8) = MouseClassFlush;
      *(code **)(param_1 + 0xe0) = MouseClassDeviceControl;
      *(code **)(param_1 + 0xe8) = MouseClassPassThrough;
      *(code **)(param_1 + 0x100) = MouseClassCleanup;
      *(code **)(param_1 + 0x148) = MousePnP;
      *(code **)(param_1 + 0x128) = MouseClassSystemControl;
      *(code **)(param_1 + 0x120) = MouseClassPower;
      *(code **)(*(longlong *)(param_1 + 0x30) + 8) = MouseAddDevice;
      goto LAB_1c00115af;
    }
  }
  else {
    _Size = (longlong ****)(ulonglong)*param_2;
    memcpy(DAT_1c000b368,*(void **)(param_2 + 4),(size_t)_Size);
    *(undefined2 *)((longlong)DAT_1c000b368 + (ulonglong)(*param_2 >> 1) * 2) = 0;
    MouConfiguration(param_1);
    if (DAT_1c000b1f8 == 0) {
      in_stack_fffffffffffffd48 = CONCAT31((int3)((uint)in_stack_fffffffffffffd48 >> 8),1);
      _Size = &local_280;
      uVar8 = MouCreateClassObject
                        (param_1,(longlong *)&DAT_1c000b200,(longlong *)_Size,local_260,'\x01');
      pwVar6 = local_260[0];
      uVar9 = uVar8 & 0xffffffff;
      if ((int)uVar8 < 0) {
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,_Size,0xc,
                            CONCAT44(in_stack_fffffffffffffd4c,in_stack_fffffffffffffd48),
                            (char)uVar8);
        }
        pwVar11 = local_260[0];
        goto LAB_1c0011983;
      }
      _Size = (longlong ****)0x0;
      pplVar1 = local_280[8];
      *pplVar1 = (longlong *)local_280;
      Globals = pplVar1;
      *(undefined1 *)(pplVar1 + 8) = 0;
      uVar8 = MouseAddDeviceEx((longlong *)pplVar1,local_260[0],0);
      if (((int)uVar8 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED))
      {
        WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,_Size,0xd,
                          CONCAT44(in_stack_fffffffffffffd4c,in_stack_fffffffffffffd48),(char)uVar8)
        ;
      }
      ExFreePoolWithTag(pwVar6,0);
      local_260[0] = (wchar_t *)0x0;
      *(uint *)(local_280 + 6) = *(uint *)(local_280 + 6) & 0xffffff7f;
    }
    RtlCopyUnicodeString(local_270,&DAT_1c000b370);
    local_270[0] = local_270[0] - 10;
    RtlAppendUnicodeToString(local_270,L"Port");
    iVar7 = MouDeterminePortsServiced(local_270,local_288);
    if ((iVar7 < 0) && ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,_Size,0xe,
                        CONCAT44(in_stack_fffffffffffffd4c,in_stack_fffffffffffffd48),(char)iVar7);
    }
    if ((ulonglong)local_270[1] < (ulonglong)local_270[0] + 2) {
      uVar9 = 0xc0000001;
      goto LAB_1c0011983;
    }
    *(undefined2 *)(local_268 + (ulonglong)(local_270[0] >> 1) * 2 + 2) = 0;
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,_Size,0xf,
                        CONCAT44(in_stack_fffffffffffffd4c,in_stack_fffffffffffffd48),
                        (char)local_288[0]);
    }
    _Size = (longlong ****)0x43756f4d;
    local_298._0_4_ = CONCAT22(local_270[0] + 0x18,(ushort)local_298);
    lStack_290 = ExAllocatePool2(0x100);
    if (lStack_290 != 0) {
      RtlAppendUnicodeToString(&local_298,L"\\Device\\");
      RtlAppendUnicodeToString(&local_298,local_268);
      RtlAppendUnicodeToString(&local_298,L"0");
      if ((local_298 >> 0x10 & 0xffff) < (local_298 & 0xffff) + 2) {
        uVar9 = 0xc0000001;
      }
      else {
        uVar12 = 0;
        *(undefined2 *)(lStack_290 + 2 + (local_298 >> 1 & 0x7fff) * 2) = 0;
        if (DAT_1c000b1fc != 0) {
          do {
            if (local_288[0] <= uVar12) break;
            in_stack_fffffffffffffd48 = CONCAT31((int3)((uint)in_stack_fffffffffffffd48 >> 8),1);
            *(short *)(lStack_290 + -2 + (local_298 >> 1 & 0x7fff) * 2) = (short)uVar12 + 0x30;
            uVar8 = MouCreateClassObject
                              (param_1,(longlong *)&DAT_1c000b200,(longlong *)&local_280,local_260,
                               '\x01');
            if ((int)uVar8 < 0) {
              _Size = (longlong ****)0x4e28;
              in_stack_fffffffffffffd48 = 0;
              MouseClassLogError(param_1,0xc0050001,0x4e28,(int)uVar8,0,(undefined4 *)0x0,0);
              pwVar11 = local_260[0];
            }
            else {
              _Size = (longlong ****)&local_278;
              pplVar1 = local_280[8];
              *pplVar1 = (longlong *)local_280;
              *(undefined1 *)(pplVar1 + 8) = 0;
              *(uint *)(local_280 + 6) = *(uint *)(local_280 + 6) & 0xffffff7f;
              iVar7 = IoGetDeviceObjectPointer(&local_298,0x80,_Size,pplVar1 + 2);
              pwVar11 = local_260[0];
              if (iVar7 == 0) {
                *(char *)((longlong)local_280 + 0x4c) =
                     *(char *)((longlong)pplVar1[2] + 0x4c) + '\x01';
                _Size = local_278;
                uVar8 = MouseAddDeviceEx((longlong *)pplVar1,local_260[0],local_278);
                if (Globals == (longlong **)0x0) {
                  pplVar1[0x2a] = (longlong *)local_278;
                }
                if (pwVar11 != (wchar_t *)0x0) {
                  ExFreePoolWithTag(pwVar11,0);
                  pwVar11 = (wchar_t *)0x0;
                  local_260[0] = (wchar_t *)0x0;
                }
                if ((int)uVar8 < 0) {
                  if (Globals == (longlong **)0x0) {
                    pppplVar2 = (longlong ****)pplVar1[0x2a];
                    if (pppplVar2 != (longlong ****)0x0) {
                      pplVar1[0x2a] = (longlong *)0x0;
                      local_278 = pppplVar2;
                    }
                  }
                  else {
                    ExAcquireFastMutex(&DAT_1c000b1c0);
                    local_278 = *(longlong *****)
                                 (DAT_1c000b1a8 +
                                 (ulonglong)*(uint *)((longlong)pplVar1 + 0xb4) * 0x18);
                    *(undefined8 *)
                     (DAT_1c000b1a8 + (ulonglong)*(uint *)((longlong)pplVar1 + 0xb4) * 0x18) = 0;
                    *(undefined1 *)
                     (DAT_1c000b1a8 + 0x13 + (ulonglong)*(uint *)((longlong)pplVar1 + 0xb4) * 0x18)
                         = 1;
                    *(undefined8 *)
                     (DAT_1c000b1a8 + 8 + (ulonglong)*(uint *)((longlong)pplVar1 + 0xb4) * 0x18) = 0
                    ;
                    ExReleaseFastMutex(&DAT_1c000b1c0);
                  }
                  if (local_278 != (longlong ****)0x0) {
                    ObfDereferenceObject();
                  }
                  if (pplVar1[0xd] != (longlong *)0x0) {
                    ExFreePoolWithTag(pplVar1[0xd],0);
                    pplVar1[0xf] = (longlong *)0x0;
                    pplVar1[0xe] = (longlong *)0x0;
                    pplVar1[0xd] = (longlong *)0x0;
                  }
                  IoDeleteDevice(*pplVar1);
                }
                else {
                  pplVar10 = pplVar1 + 0x28;
                  if ((undefined8 **)*DAT_1c000b588 != &DAT_1c000b580) {
                    pcVar4 = (code *)swi(0x29);
                    (*pcVar4)(3);
                    pcVar4 = (code *)swi(3);
                    uVar8 = (*pcVar4)();
                    return uVar8;
                  }
                  *pplVar10 = (longlong *)&DAT_1c000b580;
                  pplVar1[0x29] = (longlong *)DAT_1c000b588;
                  *DAT_1c000b588 = (longlong *)pplVar10;
                  DAT_1c000b588 = pplVar10;
                }
              }
              else {
                if (pplVar1[0xd] != (longlong *)0x0) {
                  ExFreePoolWithTag(pplVar1[0xd],0);
                  pplVar1[0xf] = (longlong *)0x0;
                  pplVar1[0xe] = (longlong *)0x0;
                  pplVar1[0xd] = (longlong *)0x0;
                }
                IoDeleteDevice(*pplVar1);
                pwVar11 = local_260[0];
              }
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 < DAT_1c000b1fc);
        }
        uVar9 = 0;
        for (puVar3 = DAT_1c000b580; (undefined8 **)puVar3 != &DAT_1c000b580;
            puVar3 = (undefined8 *)*puVar3) {
          DAT_1c000b1b8 = DAT_1c000b1b8 + 1;
        }
      }
      goto LAB_1c0011983;
    }
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x10);
    }
    uVar9 = 0xc0000001;
    local_260[0] = (wchar_t *)CONCAT44(local_260[0]._4_4_,(uint)local_298._2_2_);
    _Size = (longlong ****)0x4e28;
    in_stack_fffffffffffffd48 = 1;
    MouseClassLogError(param_1,0xc0050001,0x4e28,0xc0000001,1,(undefined4 *)local_260,0);
    local_298._0_4_ = (uint)(ushort)local_298;
  }
  if (DAT_1c000b368 != (void *)0x0) {
    ExFreePoolWithTag(DAT_1c000b368,0);
    DAT_1c000b368 = (void *)0x0;
  }
  if (DAT_1c000b1a8 != 0) {
    ExFreePoolWithTag(DAT_1c000b1a8,0);
    DAT_1c000b1a8 = 0;
  }
  if (Globals != (longlong **)0x0) {
    if (Globals[0xd] != (longlong *)0x0) {
      ExFreePoolWithTag(Globals[0xd],0);
      Globals[0xf] = (longlong *)0x0;
      Globals[0xe] = (longlong *)0x0;
      Globals[0xd] = (longlong *)0x0;
    }
    IoDeleteDevice(*Globals);
    Globals = (longlong **)0x0;
  }
LAB_1c00115af:
  if ((((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) &&
      (WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,_Size,0x11,
                         CONCAT44(in_stack_fffffffffffffd4c,in_stack_fffffffffffffd48),(char)uVar9),
      (undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED)) &&
     (*(short *)(WPP_GLOBAL_Control + 0x48) != 0)) {
    WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),5,1,0x12);
  }
  uVar5 = DAT_1c000b020;
  if ((int)uVar9 < 0) {
    DAT_1c000b020 = 0;
    DAT_1c000b000 = 0;
    EtwUnregister(uVar5);
    WppCleanupKm(param_1);
  }
  return uVar9;
}



===== MouConfiguration @ 1c0011a90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MouConfiguration(undefined8 param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  code *pcVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined8 uVar8;
  bool bVar9;
  undefined1 auStackY_e8 [32];
  longlong *plVar10;
  undefined4 local_a8;
  undefined4 local_a4;
  longlong local_a0 [7];
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  uint *local_48;
  undefined8 local_40;
  wchar_t *local_38;
  uint local_30 [2];
  longlong *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_e8;
  DAT_1c000b288 = 100;
  local_a0[2] = 0;
  lVar3 = 0;
  DAT_1c000b1fc = 1;
  DAT_1c000b1f8 = 0;
  if ((((((DAT_1c000b370 & 1) == 0) && ((DAT_1c000b372 & 1) == 0)) &&
       (DAT_1c000b370 <= DAT_1c000b372)) && (DAT_1c000b372 != 0xffff)) &&
     ((DAT_1c000b378 != (wchar_t *)0x0 || ((DAT_1c000b370 == 0 && (DAT_1c000b372 == 0)))))) {
    local_a0[0] = 0;
    RtlWideCharArrayCopyStringWorker
              ((longlong)DAT_1c000b378,(ulonglong)(DAT_1c000b372 >> 1),local_a0);
    DAT_1c000b370 = (short)local_a0[0] * 2;
  }
  plVar10 = local_a0 + 2;
  uVar8 = 0;
  lVar7 = 0x20019;
  iVar2 = IoOpenDriverRegistryKey(param_1,0);
  if (iVar2 < 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      uVar8 = 0x3d;
LAB_1c0011b83:
      WPP_RECORDER_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),3,lVar7,(short)uVar8,plVar10,
                        (char)iVar2);
      goto LAB_1c0011d13;
    }
  }
  else {
    lVar7 = 0x43756f4d;
    lVar3 = ExAllocatePool2(0x100);
    lVar1 = local_a0[2];
    if (lVar3 == 0) {
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar8 = 0x3e;
        lVar7 = 1;
        WPP_RECORDER_SF_(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),2,1,0x3e);
LAB_1c0011d13:
        if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
          uVar8 = 0x40;
          lVar7 = 1;
          WPP_RECORDER_SF_S(*(undefined8 *)(WPP_GLOBAL_Control + 0x40),4,1,0x40,plVar10,
                            DAT_1c000b378);
        }
      }
    }
    else {
      *(undefined4 *)(lVar3 + 8) = 0x120;
      *(undefined4 *)(lVar3 + 0x20) = 0x4000004;
      *(wchar_t **)(lVar3 + 0x10) = L"MouseDataQueueSize";
      *(undefined4 *)(lVar3 + 0x40) = 0x120;
      *(uint **)(lVar3 + 0x18) = &DAT_1c000b288;
      *(undefined4 *)(lVar3 + 0x58) = 0x4000004;
      *(wchar_t **)(lVar3 + 0x48) = L"MaximumPortsServiced";
      *(undefined4 **)(lVar3 + 0x50) = &DAT_1c000b1fc;
      *(wchar_t **)(lVar3 + 0x80) = L"PointerDeviceBaseName";
      *(ushort **)(lVar3 + 0x88) = &DAT_1c000b370;
      *(wchar_t **)(lVar3 + 0xb8) = L"ConnectMultiplePorts";
      *(uint **)(lVar3 + 0xc0) = &DAT_1c000b1f8;
      *(undefined4 *)(lVar3 + 0x78) = 0x120;
      *(undefined4 *)(lVar3 + 0x90) = 0x1000001;
      *(undefined4 *)(lVar3 + 0xb0) = 0x120;
      *(undefined4 *)(lVar3 + 200) = 0x4000004;
      local_a0[0] = 0;
      local_a0[1] = 0;
      RtlInitUnicodeString(local_a0,L"RtlQueryRegistryValuesEx");
      pcVar4 = (code *)MmGetSystemRoutineAddress(local_a0);
      plVar10 = (longlong *)0x0;
      if (pcVar4 == (code *)0x0) {
        pcVar4 = RtlQueryRegistryValues_exref;
      }
      uVar8 = 0;
      lVar7 = lVar3;
      iVar2 = (*pcVar4)(0xc0000000,lVar1);
      if (-1 < iVar2) goto LAB_1c0011d13;
      if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
        uVar8 = 0x3f;
        goto LAB_1c0011b83;
      }
    }
  }
  if (DAT_1c000b288 == 0) {
    if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
      WPP_RECORDER_SF_D(*(undefined8 *)(WPP_GLOBAL_Control + 0x40));
    }
    DAT_1c000b288 = 100;
  }
  else if (0xaaaaaaa < DAT_1c000b288) {
    uVar6 = 0x960;
    goto LAB_1c0011d7a;
  }
  uVar6 = (ulonglong)(DAT_1c000b288 * 0x18);
LAB_1c0011d7a:
  DAT_1c000b288 = (uint)uVar6;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar6 = *(ulonglong *)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_Dd(uVar6);
  }
  bVar9 = DAT_1c000b1f8 == 0;
  DAT_1c000b1f8 = (uint)bVar9;
  if ((undefined **)WPP_RECORDER_INITIALIZED != &WPP_RECORDER_INITIALIZED) {
    uVar8 = 0x43;
    uVar6 = *(ulonglong *)(WPP_GLOBAL_Control + 0x40);
    WPP_RECORDER_SF_d(uVar6,4,lVar7,0x43,plVar10,bVar9);
  }
  if ((5 < DAT_1c000b000) && (uVar5 = _tlgKeywordOn(), (char)uVar5 != '\0')) {
    local_a8 = DAT_1c000b288;
    local_68 = &local_a8;
    local_a4 = DAT_1c000b1fc;
    local_58 = &local_a4;
    local_48 = local_30;
    local_38 = DAT_1c000b378;
    local_30[0] = (uint)DAT_1c000b370;
    local_a0[0] = CONCAT44(local_a0[0]._4_4_,DAT_1c000b1f8);
    local_28 = local_a0;
    local_60 = 4;
    local_50 = 4;
    local_40 = 2;
    local_30[1] = 0;
    local_20 = 4;
    _tlgWriteTransfer_EtwWriteTransfer(uVar6,&DAT_1c000962c,lVar7,uVar8,7,local_a0 + 3);
  }
  if (lVar3 != 0) {
    ExFreePoolWithTag(lVar3,0);
  }
  if (local_a0[2] != 0) {
    ZwClose();
  }
  return;
}


