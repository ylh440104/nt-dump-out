
===== IoRateDeviceExtensionSoftCapDpcRoutine @ 1c0001010 =====

void IoRateDeviceExtensionSoftCapDpcRoutine(undefined8 param_1,longlong param_2)

{
  ulonglong local_18;
  undefined8 uStack_10;
  
  local_18 = *(ulonglong *)(param_2 + 0x90);
  uStack_10 = *(undefined8 *)(param_2 + 0x98);
  IoRateDeviceExtensionSoftCapProcess(param_2,&local_18);
  return;
}



===== IoRateDeferredResumeIo @ 1c0001050 =====

void IoRateDeferredResumeIo(longlong *param_1,int param_2)

{
  IoRateThrottledEntryListAdd(param_1,&DAT_1c000d308,7,0);
  if (param_2 != 0) {
    KeInsertQueueDpc(&DAT_1c000d4d8,0,0);
  }
  return;
}



===== IoRateBoostThread @ 1c00010a0 =====

void IoRateBoostThread(ulonglong param_1)

{
  longlong ****pppplVar1;
  uint *puVar2;
  longlong ***ppplVar3;
  longlong ***ppplVar4;
  code *pcVar5;
  longlong lVar6;
  longlong ****pppplVar7;
  undefined1 *puVar8;
  ulonglong *puVar9;
  int iVar10;
  ulonglong uVar11;
  undefined1 *puVar12;
  longlong local_res10;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [24];
  undefined8 local_28;
  longlong ****local_20;
  longlong ****pppplStack_18;
  
  iVar10 = 0;
  local_20 = (longlong ****)0x0;
  pppplStack_18 = (longlong ****)0x0;
  puVar9 = IoRateThreadThrottleCtxThreadReference((ulonglong *)&DAT_1c000d570,param_1,0);
  puVar12 = auStack_48;
  if (puVar9 != (ulonglong *)0x0) {
    local_28 = 0;
    local_res10 = 0;
    uVar11 = 1;
    IoGetStackLimits(&local_res10,&local_28);
    pppplStack_18 = (longlong ****)&local_20;
    lVar6 = 0x18 - local_res10;
    local_20 = (longlong ****)&local_20;
    IoRateProcessingListGet(puVar9 + 4,puVar9 + 6,0x18,(longlong)&local_20);
    puVar12 = auStack_48;
    while (pppplVar7 = local_20, (longlong *****)local_20 != &local_20) {
      pppplVar1 = local_20 + -6;
      ppplVar3 = *local_20;
      if (((longlong ****)ppplVar3[1] != local_20) ||
         (ppplVar4 = local_20[1], (longlong ****)*ppplVar4 != local_20)) {
        pcVar5 = (code *)swi(0x29);
        (*pcVar5)(3);
        puVar8 = auStack_40;
        goto LAB_1c00011fb;
      }
      *ppplVar4 = (longlong **)ppplVar3;
      uVar11 = uVar11 + 1;
      ppplVar3[1] = (longlong **)ppplVar4;
      local_20[1] = (longlong ***)local_20;
      *local_20 = (longlong ***)local_20;
      pppplVar7[-1] = (longlong ***)0x0;
      if (auStack_40 + lVar6 < (undefined1 *)0x3000) {
        puVar2 = (uint *)((longlong)pppplVar7 + 0x4c);
        *puVar2 = *puVar2 | 2;
        IoRateDeferredResumeIo((longlong *)pppplVar1,0);
      }
      else {
        IoRateThrottledEntryUnthrottle((longlong)pppplVar1,1,1,0x12);
      }
    }
    puVar8 = auStack_48;
    if (auStack_40 + lVar6 < (undefined1 *)0x3000) {
LAB_1c00011fb:
      puVar12 = puVar8;
      if (1 < uVar11) {
        *(undefined8 *)(puVar12 + -8) = 0x1c0001218;
        KeInsertQueueDpc(&DAT_1c000d4d8,0,0);
      }
    }
    *(undefined8 *)(puVar12 + -8) = 0x1c000116e;
    IoRateThreadThrottleCtxThreadDereference(0x1c000d570,(longlong)puVar9,uVar11);
    iVar10 = (int)uVar11 + -1;
  }
  *(undefined8 *)(puVar12 + -8) = 0x1c000117b;
  IoRateLogBoostThread(param_1,iVar10);
  return;
}



===== IoRateLogBoostThread @ 1c0001230 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IoRateLogBoostThread(undefined8 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 auStack_a8 [48];
  undefined4 local_78;
  undefined1 *local_70;
  undefined4 local_68 [2];
  undefined8 local_60;
  undefined1 local_58 [32];
  undefined8 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  if (4 < DAT_1c000d000) {
    uVar2 = 4;
    uVar1 = _tlgKeywordOn(param_1,4);
    if ((char)uVar1 != '\0') {
      local_38 = &local_60;
      local_28 = local_68;
      local_70 = local_58;
      local_78 = (undefined4)uVar2;
      local_30 = 8;
      local_68[0] = param_2;
      local_60 = param_1;
      local_20 = uVar2;
      _tlgWriteEx_EtwWriteEx(param_1,&DAT_1c000ab9d);
    }
  }
  return;
}



===== IoRateStartRateControl @ 1c00012d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong IoRateStartRateControl
                    (undefined8 *param_1,int param_2,uint param_3,longlong param_4,
                    undefined8 *param_5,undefined8 param_6)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  uint uVar7;
  longlong lVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  char cVar11;
  ulonglong uVar12;
  char cVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  longlong lVar16;
  ulonglong uVar17;
  bool bVar18;
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [24];
  longlong local_38;
  undefined8 *local_30;
  
  puVar14 = auStack_58;
  local_38 = 0;
  lVar16 = 0;
  if ((param_2 == 0xf) && (((param_3 & 1) == 0 || (param_4 != 0)))) {
    for (lVar8 = 6; lVar8 < 9; lVar8 = lVar8 + 1) {
      if (param_1[lVar8] != 0) {
        uVar17 = 0xc0000002;
        puVar9 = (undefined8 *)0x0;
        puVar14 = auStack_58;
        goto LAB_1c00015b3;
      }
    }
    if (((((ulonglong)param_1[2] < 0x65) && ((ulonglong)param_1[0xb] < 0x65)) &&
        ((ulonglong)param_1[5] < 0x65)) && ((ulonglong)param_1[8] < 0x65)) {
      puVar9 = (undefined8 *)ExAllocatePool2(0x40,0x1d0,0x72526f69);
      puVar14 = auStack_58;
      local_30 = puVar9;
      if (puVar9 == (undefined8 *)0x0) {
        puVar9 = (undefined8 *)0x0;
        uVar17 = 0xc0000017;
        goto LAB_1c00015b3;
      }
      memset(puVar9,0,0x1d0);
      puVar9[1] = puVar9;
      puVar1 = puVar9 + 0x35;
      *puVar9 = puVar9;
      puVar9[0x36] = puVar1;
      *puVar1 = puVar1;
      puVar1 = puVar9 + 2;
      puVar9[3] = puVar1;
      *puVar1 = puVar1;
      puVar9[6] = 1;
      if (param_4 != 0) {
        uVar7 = IoRateDeviceExtensionReferenceByHandle(param_4,&local_38);
        uVar17 = (ulonglong)uVar7;
        if ((int)uVar7 < 0) {
          puVar9 = (undefined8 *)0x0;
          ExFreePoolWithTag(local_30,0);
          puVar14 = auStack_58;
          lVar16 = local_38;
          goto LAB_1c00015b3;
        }
        lVar16 = local_38;
      }
      puVar15 = auStack_58;
      uVar17 = 0;
      puVar9[0x37] = param_6;
      uVar10 = param_1[1];
      puVar9[7] = *param_1;
      puVar9[8] = uVar10;
      uVar10 = param_1[3];
      puVar9[9] = param_1[2];
      puVar9[10] = uVar10;
      uVar10 = param_1[5];
      puVar9[0xb] = param_1[4];
      puVar9[0xc] = uVar10;
      uVar10 = param_1[7];
      puVar9[0xd] = param_1[6];
      puVar9[0xe] = uVar10;
      uVar10 = param_1[9];
      puVar9[0xf] = param_1[8];
      puVar9[0x10] = uVar10;
      uVar10 = param_1[0xb];
      puVar9[0x11] = param_1[10];
      puVar9[0x12] = uVar10;
      uVar10 = param_1[0xd];
      puVar9[0x13] = param_1[0xc];
      puVar9[0x14] = uVar10;
      puVar9[0x15] = param_1[0xe];
      if (param_4 != 0) {
        puVar9[0x38] = *(undefined8 *)(lVar16 + 0x20);
      }
      *(undefined4 *)((longlong)puVar9 + 0x1cc) = DAT_1c000d130;
      uVar3 = *(undefined4 *)((longlong)param_5 + 4);
      uVar4 = *(undefined4 *)(param_5 + 1);
      uVar5 = *(undefined4 *)((longlong)param_5 + 0xc);
      *(undefined4 *)(puVar9 + 0x25) = *(undefined4 *)param_5;
      *(undefined4 *)((longlong)puVar9 + 300) = uVar3;
      *(undefined4 *)(puVar9 + 0x26) = uVar4;
      *(undefined4 *)((longlong)puVar9 + 0x134) = uVar5;
      uVar3 = *(undefined4 *)((longlong)param_5 + 0x14);
      uVar4 = *(undefined4 *)(param_5 + 3);
      uVar5 = *(undefined4 *)((longlong)param_5 + 0x1c);
      *(undefined4 *)(puVar9 + 0x27) = *(undefined4 *)(param_5 + 2);
      *(undefined4 *)((longlong)puVar9 + 0x13c) = uVar3;
      *(undefined4 *)(puVar9 + 0x28) = uVar4;
      *(undefined4 *)((longlong)puVar9 + 0x144) = uVar5;
      puVar9[0x28] = 0;
      puVar9[0x27] = 0;
      uVar10 = KeQueryUnbiasedInterruptTime();
      puVar9[0x29] = uVar10;
      *(undefined4 *)(puVar9 + 0x2a) = *(undefined4 *)(puVar9 + 0x25);
      *(undefined4 *)((longlong)puVar9 + 0x154) = *(undefined4 *)((longlong)puVar9 + 300);
      *(undefined4 *)(puVar9 + 0x2b) = *(undefined4 *)(puVar9 + 0x26);
      *(undefined4 *)((longlong)puVar9 + 0x15c) = *(undefined4 *)((longlong)puVar9 + 0x134);
      *(undefined4 *)(puVar9 + 0x2c) = *(undefined4 *)(puVar9 + 0x27);
      *(undefined4 *)((longlong)puVar9 + 0x164) = *(undefined4 *)((longlong)puVar9 + 0x13c);
      *(undefined4 *)(puVar9 + 0x2d) = *(undefined4 *)(puVar9 + 0x28);
      *(undefined4 *)((longlong)puVar9 + 0x16c) = *(undefined4 *)((longlong)puVar9 + 0x144);
      if ((param_3 & 1) != 0) {
        *(uint *)(puVar9 + 0x39) = *(uint *)(puVar9 + 0x39) | 1;
      }
      if ((param_3 & 2) != 0) {
        *(uint *)(puVar9 + 0x39) = *(uint *)(puVar9 + 0x39) | 2;
      }
      if ((param_3 & 4) != 0) {
        *(uint *)(puVar9 + 0x39) = *(uint *)(puVar9 + 0x39) | 4;
      }
      uVar6 = ExAcquireSpinLockExclusive(&DAT_1c000d110);
      bVar18 = (undefined8 **)DAT_1c000d118 == &DAT_1c000d118;
      if ((undefined8 **)*DAT_1c000d120 == &DAT_1c000d118) {
        *puVar9 = &DAT_1c000d118;
        puVar9[1] = DAT_1c000d120;
        *DAT_1c000d120 = puVar9;
        DAT_1c000d120 = puVar9;
        if (bVar18) {
          _DAT_1c000d608 = KeQueryUnbiasedInterruptTime();
          IoRateSetQuantumTimer();
        }
        ExReleaseSpinLockExclusive(&DAT_1c000d110,uVar6);
        cVar13 = (param_1[3] != 0) + '\x01';
        if (param_1[4] == 0) {
          cVar13 = param_1[3] != 0;
        }
        cVar11 = cVar13 + '\x01';
        if (param_1[5] == 0) {
          cVar11 = cVar13;
        }
        cVar13 = cVar11 + '\x01';
        if (param_1[6] == 0) {
          cVar13 = cVar11;
        }
        cVar11 = cVar13 + '\x01';
        if (param_1[7] == 0) {
          cVar11 = cVar13;
        }
        cVar13 = cVar11 + '\x01';
        if (param_1[8] == 0) {
          cVar13 = cVar11;
        }
        if (cVar13 != '\0') {
          LOCK();
          _DAT_1c000d648 = _DAT_1c000d648 + 1;
          UNLOCK();
        }
        puVar14 = auStack_58;
        if ((DAT_1c000d690 & 1) != 0) goto LAB_1c0001690;
      }
      else {
        pcVar2 = (code *)swi(0x29);
        (*pcVar2)(3);
        puVar15 = auStack_50;
LAB_1c0001690:
        LOCK();
        DAT_1c000d690 = DAT_1c000d690 & 0xfffffffe;
        UNLOCK();
        puVar14 = puVar15;
      }
      lVar16 = *(longlong *)(puVar14 + 0x20);
      if (param_4 == 0) {
        uVar12 = uVar17;
      }
      else {
        uVar12 = *(ulonglong *)(lVar16 + 0x20);
      }
      **(ulonglong **)(puVar14 + 0x98) = uVar12;
      **(undefined8 **)(puVar14 + 0x90) = puVar9;
      goto LAB_1c00015b3;
    }
  }
  puVar9 = (undefined8 *)0x0;
  uVar17 = 0xc000000d;
LAB_1c00015b3:
  if (lVar16 != 0) {
    uVar10 = *(undefined8 *)(lVar16 + 0x78);
    *(undefined8 *)(puVar14 + -8) = 0x1c00016b1;
    ExReleaseRundownProtectionCacheAware(uVar10);
  }
  *(undefined8 *)(puVar14 + -8) = 0x1c00015ca;
  IoRateLogRateControlStart((longlong)puVar9,param_5,(int)uVar17);
  return uVar17;
}



===== IoRateLogRateControlStart @ 1c00016d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IoRateLogRateControlStart(longlong param_1,undefined8 *param_2,undefined4 param_3)

{
  ulonglong uVar1;
  undefined1 auStack_288 [48];
  undefined4 local_258;
  undefined1 *local_250;
  undefined4 local_248 [2];
  undefined8 local_240;
  undefined8 local_238;
  undefined8 local_230;
  undefined8 local_228;
  undefined8 local_220;
  undefined8 local_218;
  undefined8 local_210;
  undefined8 local_208;
  undefined8 local_200;
  undefined8 local_1f8;
  undefined8 local_1f0;
  undefined8 local_1e8;
  undefined8 local_1e0;
  undefined8 local_1d8;
  undefined8 local_1d0;
  longlong local_1c8;
  undefined8 local_1c0;
  undefined8 local_1b8;
  undefined8 local_1b0;
  undefined8 local_1a8;
  undefined8 local_1a0;
  undefined1 local_198 [32];
  longlong *local_178;
  undefined8 local_170;
  undefined8 *local_168;
  undefined8 local_160;
  undefined8 *local_158;
  undefined8 local_150;
  undefined8 *local_148;
  undefined8 local_140;
  undefined8 *local_138;
  undefined8 local_130;
  undefined8 *local_128;
  undefined8 local_120;
  undefined8 *local_118;
  undefined8 local_110;
  undefined8 *local_108;
  undefined8 local_100;
  undefined8 *local_f8;
  undefined8 local_f0;
  undefined8 *local_e8;
  undefined8 local_e0;
  undefined8 *local_d8;
  undefined8 local_d0;
  undefined8 *local_c8;
  undefined8 local_c0;
  undefined8 *local_b8;
  undefined8 local_b0;
  undefined8 *local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  undefined8 *local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_288;
  if (4 < DAT_1c000d000) {
    uVar1 = _tlgKeywordOn(param_1,4);
    if ((char)uVar1 != '\0') {
      local_170 = 8;
      local_178 = &local_1c8;
      local_160 = 8;
      local_150 = 8;
      local_140 = 8;
      local_130 = 8;
      local_120 = 8;
      local_110 = 8;
      local_100 = 8;
      if (param_1 == 0) {
        local_240 = 0;
        local_1c0 = 0;
        local_238 = 0;
        local_230 = 0;
        local_228 = 0;
        local_220 = 0;
        local_218 = 0;
        local_210 = 0;
        local_208 = 0;
        local_200 = 0;
        local_1f8 = 0;
        local_1f0 = 0;
        local_1e8 = 0;
        local_1e0 = 0;
        local_1d8 = 0;
        local_1d0 = 0;
      }
      else {
        local_240 = *(undefined8 *)(param_1 + 0x38);
        local_238 = *(undefined8 *)(param_1 + 0x40);
        local_230 = *(undefined8 *)(param_1 + 0x48);
        local_228 = *(undefined8 *)(param_1 + 0x50);
        local_220 = *(undefined8 *)(param_1 + 0x58);
        local_218 = *(undefined8 *)(param_1 + 0x60);
        local_210 = *(undefined8 *)(param_1 + 0x68);
        local_208 = *(undefined8 *)(param_1 + 0x70);
        local_200 = *(undefined8 *)(param_1 + 0x78);
        local_1f8 = *(undefined8 *)(param_1 + 0x80);
        local_1f0 = *(undefined8 *)(param_1 + 0x88);
        local_1e8 = *(undefined8 *)(param_1 + 0x90);
        local_1e0 = *(undefined8 *)(param_1 + 0x98);
        local_1d8 = *(undefined8 *)(param_1 + 0xa0);
        local_1d0 = *(undefined8 *)(param_1 + 0xa8);
        local_1c0 = *(undefined8 *)(param_1 + 0x1c0);
      }
      local_88 = &local_1d0;
      local_98 = &local_1d8;
      local_a8 = &local_1e0;
      local_b8 = &local_1e8;
      local_c8 = &local_1f0;
      local_d8 = &local_1f8;
      local_e8 = &local_200;
      local_f8 = &local_208;
      local_108 = &local_210;
      local_118 = &local_218;
      local_128 = &local_220;
      local_138 = &local_228;
      local_148 = &local_230;
      local_158 = &local_238;
      local_168 = &local_240;
      local_78 = &local_1c0;
      local_f0 = 8;
      local_1b8 = param_2[1];
      local_68 = &local_1b8;
      local_1b0 = *param_2;
      local_58 = &local_1b0;
      local_1a8 = param_2[2];
      local_48 = &local_1a8;
      local_1a0 = param_2[3];
      local_38 = &local_1a0;
      local_28 = local_248;
      local_250 = local_198;
      local_258 = 0x18;
      local_e0 = 8;
      local_80 = 8;
      local_90 = 8;
      local_a0 = 8;
      local_b0 = 8;
      local_c0 = 8;
      local_d0 = 8;
      local_70 = 8;
      local_60 = 8;
      local_50 = 8;
      local_40 = 8;
      local_30 = 8;
      local_20 = 4;
      local_248[0] = param_3;
      local_1c8 = param_1;
      _tlgWriteEx_EtwWriteEx(param_1,&DAT_1c000ac60);
    }
  }
  return;
}



===== IoRateLogRateControlRefresh @ 1c0001ad0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IoRateLogRateControlRefresh(longlong param_1,undefined8 *param_2)

{
  ulonglong uVar1;
  undefined1 auStack_158 [48];
  undefined4 local_128;
  undefined1 *local_120;
  longlong local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8 [2];
  undefined1 local_c8 [32];
  longlong *local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  undefined8 *local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_158;
  if (4 < DAT_1c000d000) {
    uVar1 = _tlgKeywordOn(param_1,4);
    if ((char)uVar1 != '\0') {
      local_a8 = &local_118;
      local_110 = *(undefined8 *)(param_1 + 0x158);
      local_98 = &local_110;
      local_108 = *(undefined8 *)(param_1 + 0x150);
      local_88 = &local_108;
      local_100 = *(undefined8 *)(param_1 + 0x160);
      local_78 = &local_100;
      local_f8 = *(undefined8 *)(param_1 + 0x168);
      local_68 = &local_f8;
      local_f0 = param_2[1];
      local_58 = &local_f0;
      local_e8 = *param_2;
      local_48 = &local_e8;
      local_e0 = param_2[2];
      local_38 = &local_e0;
      local_d8[0] = param_2[3];
      local_28 = local_d8;
      local_120 = local_c8;
      local_128 = 0xb;
      local_a0 = 8;
      local_90 = 8;
      local_80 = 8;
      local_70 = 8;
      local_60 = 8;
      local_50 = 8;
      local_40 = 8;
      local_30 = 8;
      local_20 = 8;
      local_118 = param_1;
      _tlgWriteEx_EtwWriteEx(param_1,&DAT_1c000aee0);
    }
  }
  return;
}



===== IoRateSetQuantumTimer @ 1c0001c40 =====

void IoRateSetQuantumTimer(void)

{
  if (((undefined8 **)DAT_1c000d118 != &DAT_1c000d118) && ((DAT_1c000d12c & 1) == 0)) {
    KeSetTimer(&DAT_1c000d588,0xffffffffff676980,&DAT_1c000d5c8);
  }
  return;
}



===== IoRateLogRateControlsRefreshStop @ 1c0001c90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IoRateLogRateControlsRefreshStop(undefined8 param_1)

{
  ulonglong uVar1;
  undefined1 auStack_78 [48];
  undefined4 local_48;
  undefined1 *local_40;
  undefined1 local_38 [32];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_78;
  if (4 < DAT_1c000d000) {
    uVar1 = _tlgKeywordOn(param_1,4);
    if ((char)uVar1 != '\0') {
      local_40 = local_38;
      local_48 = 2;
      _tlgWriteEx_EtwWriteEx(param_1,&DAT_1c000a843);
    }
  }
  return;
}



===== IoRateLogRateControlsRefreshStart @ 1c0001d00 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IoRateLogRateControlsRefreshStart(undefined8 param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 auStack_88 [48];
  undefined4 local_58;
  undefined1 *local_50;
  undefined4 local_48 [2];
  undefined1 local_40 [32];
  undefined4 *local_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  if (4 < DAT_1c000d000) {
    uVar2 = 4;
    uVar1 = _tlgKeywordOn(param_1,4);
    if ((char)uVar1 != '\0') {
      local_20 = local_48;
      local_50 = local_40;
      local_48[0] = (undefined4)param_1;
      local_58 = 3;
      local_18 = uVar2;
      _tlgWriteEx_EtwWriteEx(param_1,&DAT_1c000ac26);
    }
  }
  return;
}



===== IoRateLogRateControlStop @ 1c0001d80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IoRateLogRateControlStop(longlong param_1)

{
  ulonglong uVar1;
  undefined1 auStack_308 [48];
  undefined4 local_2d8;
  undefined1 *local_2d0;
  longlong local_2c8;
  undefined8 local_2c0;
  undefined8 local_2b8;
  undefined8 local_2b0;
  undefined8 local_2a8;
  undefined8 local_2a0;
  undefined8 local_298;
  undefined8 local_290;
  undefined8 local_288;
  undefined8 local_280;
  undefined8 local_278;
  undefined8 local_270;
  undefined8 local_268;
  undefined8 local_260;
  undefined8 local_258;
  undefined8 local_250;
  undefined8 local_248;
  undefined8 local_240;
  undefined8 local_238;
  undefined8 local_230;
  undefined8 local_228;
  undefined8 local_220;
  undefined8 local_218;
  undefined8 local_210;
  undefined8 local_208;
  undefined8 local_200;
  undefined8 local_1f8 [2];
  undefined1 local_1e8 [32];
  longlong *local_1c8;
  undefined8 local_1c0;
  undefined8 *local_1b8;
  undefined8 local_1b0;
  undefined8 *local_1a8;
  undefined8 local_1a0;
  undefined8 *local_198;
  undefined8 local_190;
  undefined8 *local_188;
  undefined8 local_180;
  undefined8 *local_178;
  undefined8 local_170;
  undefined8 *local_168;
  undefined8 local_160;
  undefined8 *local_158;
  undefined8 local_150;
  undefined8 *local_148;
  undefined8 local_140;
  undefined8 *local_138;
  undefined8 local_130;
  undefined8 *local_128;
  undefined8 local_120;
  undefined8 *local_118;
  undefined8 local_110;
  undefined8 *local_108;
  undefined8 local_100;
  undefined8 *local_f8;
  undefined8 local_f0;
  undefined8 *local_e8;
  undefined8 local_e0;
  undefined8 *local_d8;
  undefined8 local_d0;
  undefined8 *local_c8;
  undefined8 local_c0;
  undefined8 *local_b8;
  undefined8 local_b0;
  undefined8 *local_a8;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  undefined8 *local_78;
  undefined8 local_70;
  undefined8 *local_68;
  undefined8 local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 *local_48;
  undefined8 local_40;
  undefined8 *local_38;
  undefined8 local_30;
  undefined8 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_308;
  if (4 < DAT_1c000d000) {
    uVar1 = _tlgKeywordOn(param_1,4);
    if ((char)uVar1 != '\0') {
      local_1c8 = &local_2c8;
      local_2c0 = *(undefined8 *)(param_1 + 0x38);
      local_1b8 = &local_2c0;
      local_2b8 = *(undefined8 *)(param_1 + 0x40);
      local_1a8 = &local_2b8;
      local_2b0 = *(undefined8 *)(param_1 + 0x48);
      local_198 = &local_2b0;
      local_2a8 = *(undefined8 *)(param_1 + 0x50);
      local_188 = &local_2a8;
      local_2a0 = *(undefined8 *)(param_1 + 0x58);
      local_178 = &local_2a0;
      local_298 = *(undefined8 *)(param_1 + 0x60);
      local_168 = &local_298;
      local_290 = *(undefined8 *)(param_1 + 0x68);
      local_158 = &local_290;
      local_288 = *(undefined8 *)(param_1 + 0x70);
      local_148 = &local_288;
      local_280 = *(undefined8 *)(param_1 + 0x78);
      local_138 = &local_280;
      local_278 = *(undefined8 *)(param_1 + 0x80);
      local_128 = &local_278;
      local_270 = *(undefined8 *)(param_1 + 0x88);
      local_118 = &local_270;
      local_268 = *(undefined8 *)(param_1 + 0x90);
      local_108 = &local_268;
      local_260 = *(undefined8 *)(param_1 + 0x98);
      local_f8 = &local_260;
      local_258 = *(undefined8 *)(param_1 + 0xa0);
      local_e8 = &local_258;
      local_250 = *(undefined8 *)(param_1 + 0xa8);
      local_d8 = &local_250;
      local_248 = *(undefined8 *)(param_1 + 0x1c0);
      local_1c0 = 8;
      local_1b0 = 8;
      local_1a0 = 8;
      local_190 = 8;
      local_180 = 8;
      local_170 = 8;
      local_160 = 8;
      local_150 = 8;
      local_140 = 8;
      local_130 = 8;
      local_120 = 8;
      local_110 = 8;
      local_100 = 8;
      local_f0 = 8;
      local_e0 = 8;
      local_d0 = 8;
      local_c8 = &local_248;
      local_c0 = 8;
      local_240 = *(undefined8 *)(param_1 + 0x130);
      local_b8 = &local_240;
      local_238 = *(undefined8 *)(param_1 + 0x128);
      local_a8 = &local_238;
      local_230 = *(undefined8 *)(param_1 + 0x138);
      local_98 = &local_230;
      local_228 = *(undefined8 *)(param_1 + 0x140);
      local_88 = &local_228;
      local_220 = *(undefined8 *)(param_1 + 0x148);
      local_78 = &local_220;
      local_218 = *(undefined8 *)(param_1 + 0x158);
      local_68 = &local_218;
      local_210 = *(undefined8 *)(param_1 + 0x150);
      local_58 = &local_210;
      local_208 = *(undefined8 *)(param_1 + 0x160);
      local_200 = *(undefined8 *)(param_1 + 0x168);
      local_38 = &local_200;
      local_1f8[0] = *(undefined8 *)(param_1 + 0x170);
      local_28 = local_1f8;
      local_2d0 = local_1e8;
      local_2d8 = 0x1d;
      local_b0 = 8;
      local_a0 = 8;
      local_90 = 8;
      local_80 = 8;
      local_70 = 8;
      local_60 = 8;
      local_50 = 8;
      local_40 = 8;
      local_30 = 8;
      local_20 = 8;
      local_2c8 = param_1;
      local_48 = &local_208;
      _tlgWriteEx_EtwWriteEx(param_1,&DAT_1c000a8a4);
    }
  }
  return;
}



===== IoRateStopRateControl @ 1c0002150 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void IoRateStopRateControl(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  longlong ***ppplVar3;
  code *pcVar4;
  longlong ***ppplVar5;
  undefined1 uVar6;
  char cVar7;
  char cVar8;
  longlong ***local_18;
  longlong ***ppplStack_10;
  
  local_18 = (longlong ***)0x0;
  ppplStack_10 = (longlong ***)0x0;
  uVar6 = ExAcquireSpinLockExclusive(&DAT_1c000d110);
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) == param_1) &&
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 == param_1)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    DAT_1c000d128 = DAT_1c000d128 + 1;
    if (DAT_1c000d128 == 0) {
      DAT_1c000d128 = 1;
    }
    if ((undefined8 **)DAT_1c000d118 == &DAT_1c000d118) {
      KeCancelTimer(&DAT_1c000d588);
    }
    if (param_1[4] == 0) {
      while (plVar2 = (longlong *)param_1[2], plVar2 != param_1 + 2) {
        IoRateControlRemoveStandaloneVolumeControl((longlong)(plVar2 + -2),1);
      }
    }
    if ((*(uint *)(param_1 + 0x39) & 1) != 0) {
      IoRateControlRemoveStandaloneVolumeControl((longlong)param_1,0);
    }
    ExReleaseSpinLockExclusive(&DAT_1c000d110,uVar6);
    ppplStack_10 = (longlong ***)&local_18;
    local_18 = (longlong ***)&local_18;
    IoRateProcessingListGet(param_1 + 0x35,param_1 + 5,0,(longlong)&local_18);
    while( true ) {
      ppplVar5 = local_18;
      if ((longlong ****)local_18 == &local_18) {
        cVar8 = (param_1[10] != 0) + '\x01';
        if (param_1[0xb] == 0) {
          cVar8 = param_1[10] != 0;
        }
        cVar7 = cVar8 + '\x01';
        if (param_1[0xc] == 0) {
          cVar7 = cVar8;
        }
        cVar8 = cVar7 + '\x01';
        if (param_1[0xd] == 0) {
          cVar8 = cVar7;
        }
        cVar7 = cVar8 + '\x01';
        if (param_1[0xe] == 0) {
          cVar7 = cVar8;
        }
        cVar8 = cVar7 + '\x01';
        if (param_1[0xf] == 0) {
          cVar8 = cVar7;
        }
        if (cVar8 != '\0') {
          LOCK();
          _DAT_1c000d648 = _DAT_1c000d648 + -1;
          UNLOCK();
        }
        IoRateLogRateControlStop((longlong)param_1);
        IoRateControlDereference((longlong)param_1);
        return;
      }
      if (((longlong ****)local_18[1] != &local_18) ||
         (ppplVar3 = (longlong ***)*local_18, (longlong ***)ppplVar3[1] != local_18)) break;
      ppplVar3[1] = (longlong **)&local_18;
      local_18[1] = (longlong **)local_18;
      *local_18 = (longlong **)local_18;
      local_18 = ppplVar3;
      IoRateThrottledEntryUnthrottle((longlong)(ppplVar5 + -6),1,0,0x12);
    }
  }
  pcVar4 = (code *)swi(0x29);
  (*pcVar4)(3);
  pcVar4 = (code *)swi(3);
  (*pcVar4)();
  return;
}



===== IoRateControlsGetNext @ 1c0002340 =====

undefined8 * IoRateControlsGetNext(undefined8 *param_1,int *param_2)

{
  undefined1 uVar1;
  undefined8 *puVar2;
  
  uVar1 = ExAcquireSpinLockShared(&DAT_1c000d110);
  puVar2 = param_1;
  if (param_1 == (undefined8 *)0x0) {
    puVar2 = &DAT_1c000d118;
  }
  if (*param_2 != DAT_1c000d128) {
    *param_2 = DAT_1c000d128;
    puVar2 = &DAT_1c000d118;
  }
  puVar2 = (undefined8 *)*puVar2;
  if (puVar2 == &DAT_1c000d118) {
    puVar2 = (undefined8 *)0x0;
  }
  else {
    LOCK();
    puVar2[6] = puVar2[6] + 1;
    UNLOCK();
  }
  ExReleaseSpinLockShared(&DAT_1c000d110,uVar1);
  if (param_1 != (undefined8 *)0x0) {
    IoRateControlDereference((longlong)param_1);
  }
  return puVar2;
}



===== IoRateControlDereference @ 1c00023e0 =====

void IoRateControlDereference(longlong param_1)

{
  longlong *plVar1;
  longlong lVar2;
  
  LOCK();
  plVar1 = (longlong *)(param_1 + 0x30);
  lVar2 = *plVar1;
  *plVar1 = *plVar1 + -1;
  UNLOCK();
  if (lVar2 == 1) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== IoRateRecordIoAttributionQueueTime @ 1c0002420 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 IoRateRecordIoAttributionQueueTime(longlong param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  uint uStack_34;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  uVar1 = 0x200;
  if (param_3 != 0) {
    uVar1 = 0x300;
  }
  _local_38 = CONCAT44(**(byte **)(param_1 + 0xb8) | uVar1,1);
  uStack_20 = KeQueryUnbiasedInterruptTimePrecise(&uStack_20);
  IoRecordIoAttribution(param_2,&local_38);
  return 1;
}



===== IoRateQuantumDpcRoutine @ 1c00024d0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void IoRateQuantumDpcRoutine(void)

{
  _DAT_1c000d608 = KeQueryUnbiasedInterruptTime();
  IoRateControlsRefresh();
  return;
}



===== IoRateControlsRefresh @ 1c0002500 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IoRateControlsRefresh(void)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  int iVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 uVar8;
  undefined *puVar9;
  longlong *plVar10;
  uint uVar11;
  longlong *plVar12;
  longlong lVar13;
  uint uVar14;
  int iVar15;
  undefined1 auStack_118 [32];
  longlong *local_f8;
  longlong *local_f0;
  longlong *local_e8;
  undefined8 local_e0;
  int local_c8 [2];
  undefined8 *******local_c0;
  undefined8 *******local_b8;
  undefined8 *******local_b0;
  undefined8 *******local_a8;
  longlong local_a0 [7];
  longlong local_68 [6];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_118;
  uVar11 = DAT_1c000d130 + 1;
  local_a0[2] = 0;
  local_a0[0] = 0;
  local_a0[1] = 0;
  local_a0[3] = 0;
  local_a0[4] = 0;
  DAT_1c000d130 = uVar11;
  IoRateLogRateControlsRefreshStart((ulonglong)uVar11);
  local_a8 = &local_b0;
  local_c8[0] = 0;
  local_b0 = &local_b0;
  uVar14 = 0;
  puVar6 = IoRateControlsGetNext((undefined8 *)0x0,local_c8);
  if (puVar6 != (undefined8 *)0x0) {
    iVar15 = 0;
    do {
      if (local_c8[0] != iVar15) {
        uVar14 = uVar14 + 1;
        if (4 < uVar14) break;
        iVar15 = local_c8[0];
      }
      local_e8 = local_a0 + 2;
      local_e0 = 0;
      local_f0 = local_a0 + 5;
      local_f8 = local_a0 + 3;
      iVar5 = (*(code *)*DAT_1c000d0e8)(puVar6[0x37],puVar6[0x38],0,local_a0);
      if (iVar5 != 0) {
        plVar10 = local_68;
        lVar13 = 2;
        plVar12 = local_a0;
        do {
          lVar1 = *plVar12;
          if (lVar1 != 0) {
            plVar10[1] = *(longlong *)(lVar1 + 0x1a0);
            *plVar10 = *(longlong *)(lVar1 + 0x198);
          }
          plVar12 = plVar12 + 1;
          plVar10 = plVar10 + 4;
          lVar13 = lVar13 + -1;
        } while (lVar13 != 0);
        plVar10 = local_68 + 2;
        lVar13 = local_a0[1];
        if (puVar6[0x38] == 0) {
          plVar10 = local_a0 + 5;
          lVar13 = local_a0[0];
        }
        if (lVar13 != 0) {
          puVar7 = (undefined8 *)(lVar13 + 0x1a8);
          if (*(uint *)(lVar13 + 0x1cc) != uVar11) {
            iVar5 = IoRateControlStateGet(lVar13,(longlong)plVar10,0xc,(undefined4 *)0x0);
            local_f8 = (longlong *)CONCAT44(local_f8._4_4_,(uint)((undefined8 *)*puVar7 != puVar7));
            (*(code *)DAT_1c000d0e8[6])(*(undefined8 *)(lVar13 + 0x1b8),iVar5 == 0,1000,uVar11);
            *(uint *)(lVar13 + 0x1cc) = uVar11;
          }
          IoRateLogRateControlRefresh(lVar13,plVar10);
          lVar1 = plVar10[1];
          *(longlong *)(lVar13 + 0x150) = *plVar10;
          *(longlong *)(lVar13 + 0x158) = lVar1;
          lVar1 = plVar10[3];
          *(longlong *)(lVar13 + 0x160) = plVar10[2];
          *(longlong *)(lVar13 + 0x168) = lVar1;
          uVar2 = *(undefined4 *)((longlong)plVar10 + 4);
          lVar1 = plVar10[1];
          uVar3 = *(undefined4 *)((longlong)plVar10 + 0xc);
          *(int *)(lVar13 + 0x178) = (int)*plVar10;
          *(undefined4 *)(lVar13 + 0x17c) = uVar2;
          *(int *)(lVar13 + 0x180) = (int)lVar1;
          *(undefined4 *)(lVar13 + 0x184) = uVar3;
          uVar2 = *(undefined4 *)((longlong)plVar10 + 0x14);
          lVar1 = plVar10[3];
          uVar3 = *(undefined4 *)((longlong)plVar10 + 0x1c);
          *(int *)(lVar13 + 0x188) = (int)plVar10[2];
          *(undefined4 *)(lVar13 + 0x18c) = uVar2;
          *(int *)(lVar13 + 400) = (int)lVar1;
          *(undefined4 *)(lVar13 + 0x194) = uVar3;
          uVar8 = KeQueryUnbiasedInterruptTime();
          *(undefined8 *)(lVar13 + 0x170) = uVar8;
          IoRateProcessingListGet(puVar7,lVar13 + 0x28,0,(longlong)&local_b0);
        }
        (*(code *)DAT_1c000d0e8[1])(local_a0 + 3);
      }
      puVar6 = IoRateControlsGetNext(puVar6,local_c8);
    } while (puVar6 != (undefined8 *)0x0);
  }
  local_b8 = &local_c0;
  local_c0 = &local_c0;
  for (puVar7 = IoRateDeviceExtensionGetNext((undefined8 *)0x0); puVar7 != (undefined8 *)0x0;
      puVar7 = IoRateDeviceExtensionGetNext(puVar7)) {
    IoRateProcessingListGet
              ((undefined8 *)(puVar7[6] + 0x1a8),puVar7[6] + 0x28,0,(longlong)&local_c0);
  }
  IoRateThrottledIosRecheck(&local_c0,4);
  IoRateThrottledIosRecheck(&local_b0,4);
  IoRateThrottledIosRecheck((undefined8 ****)&DAT_1c000d138,2);
  uVar4 = ExAcquireSpinLockShared(&DAT_1c000d110);
  if ((undefined8 **)DAT_1c000d118 != &DAT_1c000d118) {
    IoRateSetQuantumTimer();
  }
  puVar9 = &DAT_1c000d110;
  ExReleaseSpinLockShared(&DAT_1c000d110,uVar4);
  IoRateLogRateControlsRefreshStop(puVar9);
  if (puVar6 != (undefined8 *)0x0) {
    IoRateControlDereference((longlong)puVar6);
  }
  return;
}



===== IoRateDeviceExtensionGetNext @ 1c00028a0 =====

undefined8 * IoRateDeviceExtensionGetNext(undefined8 *param_1)

{
  undefined1 uVar1;
  char cVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  
  uVar1 = ExAcquireSpinLockShared(&DAT_1c000d0f0);
  puVar3 = &DAT_1c000d0f8;
  if (param_1 != (undefined8 *)0x0) {
    puVar3 = param_1;
  }
  do {
    puVar3 = (undefined8 *)*puVar3;
    puVar4 = (undefined8 *)0x0;
    if (puVar3 == &DAT_1c000d0f8) goto LAB_1c0002905;
    cVar2 = ExAcquireRundownProtectionCacheAware(puVar3[0xf]);
  } while (cVar2 == '\0');
  puVar4 = puVar3;
LAB_1c0002905:
  ExReleaseSpinLockShared(&DAT_1c000d0f0,uVar1);
  if (param_1 != (undefined8 *)0x0) {
    ExReleaseRundownProtectionCacheAware(param_1[0xf]);
  }
  return puVar4;
}



===== IoRateThreadThrottleCtxThreadReference @ 1c0002960 =====

ulonglong * IoRateThreadThrottleCtxThreadReference(ulonglong *param_1,ulonglong param_2,int param_3)

{
  undefined1 uVar1;
  ulonglong *puVar2;
  ulonglong *puVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  undefined4 uVar6;
  
  uVar1 = ExAcquireSpinLockShared(param_1 + 2);
  puVar3 = (ulonglong *)*param_1;
  uVar4 = param_1[1];
  if ((uVar4 & 1) == 0) {
LAB_1c00029a5:
    if (puVar3 != (ulonglong *)0x0) {
      do {
        if (param_2 < puVar3[3]) {
          puVar2 = (ulonglong *)*puVar3;
          puVar5 = puVar2;
          if ((uVar4 & 1) != 0) goto LAB_1c00029c4;
        }
        else {
          puVar5 = puVar3;
          if (param_2 <= puVar3[3]) break;
          puVar2 = (ulonglong *)puVar3[1];
          puVar5 = puVar2;
          if ((uVar4 & 1) != 0) {
LAB_1c00029c4:
            puVar5 = (ulonglong *)0x0;
            if (puVar2 != (ulonglong *)0x0) {
              puVar5 = (ulonglong *)((ulonglong)puVar3 ^ (ulonglong)puVar2);
            }
          }
        }
        puVar3 = puVar5;
      } while (puVar5 != (ulonglong *)0x0);
      if (puVar5 != (ulonglong *)0x0) {
        LOCK();
        puVar5[7] = puVar5[7] + 1;
        UNLOCK();
        ExReleaseSpinLockShared(param_1 + 2);
        return puVar5;
      }
    }
  }
  else if (puVar3 != (ulonglong *)0x0) {
    puVar3 = (ulonglong *)((ulonglong)puVar3 ^ (ulonglong)param_1);
    goto LAB_1c00029a5;
  }
  ExReleaseSpinLockShared(param_1 + 2,uVar1);
  if ((param_3 == 0) ||
     (puVar3 = (ulonglong *)ExAllocateFromLookasideListEx(&DAT_1c000d710),
     puVar3 == (ulonglong *)0x0)) {
    return (ulonglong *)0x0;
  }
  IoRateThreadThrottleEntryInitialize(puVar3,param_2);
  uVar1 = ExAcquireSpinLockExclusive(param_1 + 2);
  puVar2 = (ulonglong *)*param_1;
  uVar6 = 0;
  if (puVar2 != (ulonglong *)0x0) {
    do {
      uVar4 = IoRateThreadThrottleTreeCompare(param_2,(longlong)puVar2);
      if ((int)uVar4 < 1) {
        if (-1 < (int)uVar4) {
          LOCK();
          puVar2[7] = puVar2[7] + 1;
          UNLOCK();
          ExReleaseSpinLockExclusive(param_1 + 2,uVar1);
          puVar3[7] = 0;
          IoRateThreadThrottleEntryDelete((longlong)puVar3);
          return puVar2;
        }
        puVar5 = (ulonglong *)*puVar2;
        if (puVar5 == (ulonglong *)0x0) {
          uVar6 = 0;
          break;
        }
      }
      else {
        puVar5 = (ulonglong *)puVar2[1];
        if (puVar5 == (ulonglong *)0x0) goto LAB_1c00029fc;
      }
      puVar2 = puVar5;
    } while( true );
  }
LAB_1c00029ff:
  RtlRbInsertNodeEx(param_1,puVar2,uVar6,puVar3);
  ExReleaseSpinLockExclusive(param_1 + 2,uVar1);
  return puVar3;
LAB_1c00029fc:
  uVar6 = 1;
  goto LAB_1c00029ff;
}



===== IoRateThreadThrottleTreeCompare @ 1c0002b40 =====

ulonglong IoRateThreadThrottleTreeCompare(ulonglong param_1,longlong param_2)

{
  if (param_1 < *(ulonglong *)(param_2 + 0x18)) {
    return 0xffffffff;
  }
  return (ulonglong)(*(ulonglong *)(param_2 + 0x18) < param_1);
}



===== IoRateThreadThrottleEntryInitialize @ 1c0002b70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IoRateThreadThrottleEntryInitialize(undefined8 *param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  puVar1 = param_1 + 4;
  param_1[5] = puVar1;
  *puVar1 = puVar1;
  param_1[7] = 1;
  param_1[3] = param_2;
  ObfReferenceObject(param_2);
  (**(code **)(DAT_1c000d0e8 + 0x20))(param_2,1);
  return;
}



===== IoRateThrottledEntryReleaseListLocks @ 1c0002bf0 =====

void IoRateThrottledEntryReleaseListLocks(longlong param_1,longlong param_2,uint *param_3)

{
  byte bVar1;
  
  bVar1 = (byte)*param_3;
  if ((bVar1 & 0xc) == 8) {
    ExReleaseSpinLockExclusiveFromDpcLevel(*(longlong *)(param_1 + 0x28) + 0x30);
    *param_3 = *param_3 & 0xfffffff3;
    bVar1 = (byte)*param_3;
  }
  if ((bVar1 & 3) == 2) {
    if (param_2 == 0) {
      param_2 = *(longlong *)(param_1 + 0x10);
    }
    ExReleaseSpinLockExclusiveFromDpcLevel(param_2 + 0x28);
    *param_3 = *param_3 & 0xfffffffc;
  }
  return;
}



===== IoRateThreadThrottleEntryDelete @ 1c0002c70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IoRateThreadThrottleEntryDelete(longlong param_1)

{
  (**(code **)(DAT_1c000d0e8 + 0x20))(*(undefined8 *)(param_1 + 0x18),0xffffffff);
  ObDereferenceObjectDeferDelete(*(undefined8 *)(param_1 + 0x18));
  ExFreeToLookasideListEx(&DAT_1c000d710,param_1);
  return;
}



===== IoRateThrottledEntryListAdd @ 1c0002cd0 =====

void IoRateThrottledEntryListAdd
               (longlong *param_1,undefined *param_2,undefined4 param_3,ulonglong param_4)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  code *pcVar4;
  undefined1 uVar5;
  byte bVar6;
  uint local_res18 [4];
  
  uVar5 = 0;
  *(undefined4 *)(param_1 + 0x11) = param_3;
  local_res18[0] = 0;
  if ((param_4 & 1) == 0) {
    uVar5 = KfRaiseIrql(2);
  }
  else {
    local_res18[0] = 1;
  }
  IoRateThrottledEntryAcquireListLocks((longlong)param_1,param_2,local_res18,0);
  plVar1 = (longlong *)(param_2 + 0x1a8);
  if ((param_4 & 4) == 0) {
    plVar2 = *(longlong **)(param_2 + 0x1b0);
    if ((longlong *)*plVar2 != plVar1) goto LAB_1c0002e28;
    *param_1 = (longlong)plVar1;
    param_1[1] = (longlong)plVar2;
    *plVar2 = (longlong)param_1;
    *(longlong **)(param_2 + 0x1b0) = param_1;
  }
  else {
    lVar3 = *plVar1;
    if (*(longlong **)(lVar3 + 8) != plVar1) goto LAB_1c0002e28;
    *param_1 = lVar3;
    param_1[1] = (longlong)plVar1;
    *(longlong **)(lVar3 + 8) = param_1;
    *plVar1 = (longlong)param_1;
  }
  param_1[2] = (longlong)param_2;
  if ((param_2 != &DAT_1c000d308) && (lVar3 = param_1[5], lVar3 != 0)) {
    plVar2 = *(longlong **)(lVar3 + 0x28);
    plVar1 = param_1 + 3;
    if (*plVar2 != lVar3 + 0x20) {
LAB_1c0002e28:
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *plVar1 = lVar3 + 0x20;
    param_1[4] = (longlong)plVar2;
    *plVar2 = (longlong)plVar1;
    *(longlong **)(lVar3 + 0x28) = plVar1;
  }
  bVar6 = (byte)local_res18[0];
  if ((bVar6 & 0xc) == 8) {
    ExReleaseSpinLockExclusiveFromDpcLevel(param_1[5] + 0x30);
    bVar6 = bVar6 & 0xf3;
  }
  if ((bVar6 & 3) == 2) {
    ExReleaseSpinLockExclusiveFromDpcLevel(param_1[2] + 0x28);
  }
  if ((param_4 & 1) == 0) {
    KeLowerIrql(uVar5);
  }
  return;
}



===== IoRateThrottledEntryAcquireListLocks @ 1c0002e40 =====

undefined8
IoRateThrottledEntryAcquireListLocks(longlong param_1,undefined *param_2,uint *param_3,int param_4)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *param_3;
  if (((byte)uVar1 & 3) != 1) {
    if (((byte)uVar1 & 0xc) == 4) {
      uVar2 = ExTryAcquireSpinLockExclusiveAtDpcLevel(param_2 + 0x28);
      if ((int)uVar2 == 0) {
        return uVar2;
      }
    }
    else {
      ExAcquireSpinLockExclusiveAtDpcLevel();
      if ((param_4 != 0) && (*(undefined **)(param_1 + 0x10) != param_2)) {
        ExReleaseSpinLockExclusiveFromDpcLevel(param_2 + 0x28);
        return 1;
      }
    }
    uVar1 = *param_3 & 0xfffffffe | 2;
    *param_3 = uVar1;
  }
  if (((param_2 != &DAT_1c000d308) && (((byte)uVar1 & 0xc) != 4)) &&
     (*(longlong *)(param_1 + 0x28) != 0)) {
    ExAcquireSpinLockExclusiveAtDpcLevel(*(longlong *)(param_1 + 0x28) + 0x30);
    *param_3 = *param_3 & 0xfffffffb | 8;
  }
  return 2;
}



===== _tlgWriteEx_EtwWriteEx @ 1c0002f30 =====

void _tlgWriteEx_EtwWriteEx(undefined8 param_1,byte *param_2)

{
  undefined8 *in_stack_00000040;
  int local_18;
  uint local_14;
  undefined8 local_10;
  
  local_18 = (uint)*param_2 << 0x18;
  local_14 = (uint)*(ushort *)(param_2 + 1);
  local_10 = *(undefined8 *)(param_2 + 3);
  *in_stack_00000040 = PTR_DAT_1c000d008;
  *(uint *)(in_stack_00000040 + 1) = (uint)*(ushort *)PTR_DAT_1c000d008;
  in_stack_00000040[2] = param_2 + 0xb;
  *(undefined4 *)((longlong)in_stack_00000040 + 0xc) = 2;
  *(uint *)(in_stack_00000040 + 3) = (uint)*(ushort *)(param_2 + 0xb);
  *(undefined4 *)((longlong)in_stack_00000040 + 0x1c) = 1;
  EtwWriteEx(DAT_1c000d020,&local_18,0,1,0,0);
  return;
}



===== IoRateDeviceExtensionSoftCapProcess @ 1c0003000 =====

void IoRateDeviceExtensionSoftCapProcess(longlong param_1,ulonglong *param_2)

{
  longlong *plVar1;
  undefined *puVar2;
  longlong *plVar3;
  undefined1 uVar4;
  ulonglong local_28;
  ulonglong uStack_20;
  
  puVar2 = *(undefined **)(param_1 + 0x30);
  local_28 = *param_2;
  plVar1 = (longlong *)(puVar2 + 0x1a8);
  uStack_20 = param_2[1];
  while ((((longlong *)*plVar1 != plVar1 && (local_28 < DAT_1c000d698)) &&
         (uStack_20 < DAT_1c000d6a0))) {
    uVar4 = ExAcquireSpinLockExclusive(puVar2 + 0x28);
    plVar3 = (longlong *)*plVar1;
    if (plVar3 == plVar1) {
      ExReleaseSpinLockExclusive(puVar2 + 0x28,uVar4);
    }
    else {
      IoRateThrottledEntryListRemove(plVar3,puVar2,1);
      ExReleaseSpinLockExclusive(puVar2 + 0x28,uVar4);
      if (plVar3 != (longlong *)0x0) {
        IoRateThrottledEntryUnthrottle((longlong)plVar3,1,0,0);
      }
    }
    local_28 = *(ulonglong *)(param_1 + 0x90);
    uStack_20 = *(ulonglong *)(param_1 + 0x98);
  }
  return;
}



===== IoRateReadWriteCompletion @ 1c0003100 =====

undefined8 IoRateReadWriteCompletion(longlong param_1,longlong param_2,ulonglong param_3)

{
  byte *pbVar1;
  longlong *plVar2;
  int *piVar3;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  undefined *puVar7;
  longlong *plVar8;
  uint uVar9;
  longlong lVar10;
  ulonglong uVar11;
  longlong local_res8;
  undefined8 local_58 [2];
  ulonglong local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  ulonglong uStack_30;
  
  lVar6 = *(longlong *)(param_1 + 0x40);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  if ((param_3 & 2) == 0) {
    local_38 = 0;
    uStack_30 = 0;
    local_58[0] = 0;
    local_res8 = 0;
    IoGetStackLimits(&local_res8);
    uVar11 = (longlong)local_58 - local_res8;
    iVar5 = *(int *)(*(longlong *)(param_2 + 0xb8) + 8);
    uVar9 = ((DAT_1c000d694 - 1) + iVar5) / DAT_1c000d694;
    LOCK();
    plVar2 = (longlong *)(lVar6 + 0x90);
    lVar4 = *plVar2;
    *plVar2 = *plVar2 + (longlong)(int)-uVar9;
    UNLOCK();
    local_38 = lVar4 - (int)uVar9;
    lVar10 = (longlong)-iVar5;
    LOCK();
    plVar2 = (longlong *)(lVar6 + 0x98);
    lVar4 = *plVar2;
    *plVar2 = *plVar2 + lVar10;
    UNLOCK();
    uStack_30 = lVar4 + lVar10;
    if (uVar11 < 0x3000) {
      KeInsertQueueDpc(lVar6 + 0x38,0,0);
    }
    else {
      puVar7 = *(undefined **)(lVar6 + 0x30);
      plVar2 = (longlong *)(puVar7 + 0x1a8);
      local_48 = local_38;
      uStack_40 = uStack_30;
      while ((((longlong *)*plVar2 != plVar2 && (local_48 < DAT_1c000d698)) &&
             (uStack_40 < DAT_1c000d6a0))) {
        ExAcquireSpinLockExclusive(puVar7 + 0x28);
        plVar8 = (longlong *)*plVar2;
        if (plVar8 == plVar2) {
          ExReleaseSpinLockExclusive(puVar7 + 0x28);
        }
        else {
          IoRateThrottledEntryListRemove(plVar8,puVar7,1);
          ExReleaseSpinLockExclusive(puVar7 + 0x28);
          if (plVar8 != (longlong *)0x0) {
            IoRateThrottledEntryUnthrottle((longlong)plVar8,1,0,0);
          }
        }
        local_48 = *(ulonglong *)(lVar6 + 0x90);
        uStack_40 = *(ulonglong *)(lVar6 + 0x98);
      }
    }
    if (*(int *)(lVar6 + 0x84) != -1) {
      puVar7 = *(undefined **)(lVar6 + 0x28);
      ExAcquireSpinLockExclusive(puVar7 + 0x28);
      plVar2 = *(longlong **)(puVar7 + 0x1a8);
      if ((plVar2 == (longlong *)(puVar7 + 0x1a8)) ||
         (*(int *)(lVar6 + 0x88) != *(int *)(lVar6 + 0x84))) {
        *(int *)(lVar6 + 0x88) = *(int *)(lVar6 + 0x88) + -1;
        ExReleaseSpinLockExclusive(puVar7 + 0x28);
      }
      else {
        IoRateThrottledEntryListRemove(plVar2,puVar7,1);
        ExReleaseSpinLockExclusive(puVar7 + 0x28);
        if (plVar2 != (longlong *)0x0) {
          if (uVar11 < 0x3000) {
            *(uint *)((longlong)plVar2 + 0x7c) = *(uint *)((longlong)plVar2 + 0x7c) | 1;
            IoRateDeferredResumeIo(plVar2,1);
          }
          else {
            IoRateThrottledEntryUnthrottle((longlong)plVar2,0,0,6);
          }
        }
      }
    }
  }
  if ((param_3 & 1) != 0) {
    LOCK();
    piVar3 = (int *)(lVar6 + 0x80);
    iVar5 = *piVar3;
    *piVar3 = *piVar3 + -1;
    UNLOCK();
    if (iVar5 == 1) {
      IoRateThrottledIosRecheck((undefined8 ****)&DAT_1c000d138,0);
    }
  }
  return 0;
}



===== IoRateThrottledEntryListRemove @ 1c0003400 =====

undefined8 IoRateThrottledEntryListRemove(longlong *param_1,undefined *param_2,ulonglong param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint local_res18 [4];
  
  uVar7 = 0;
  uVar5 = 0;
  local_res18[0] = 0;
  if ((param_3 & 2) == 0) {
    if ((param_3 & 1) == 0) {
      uVar5 = KfRaiseIrql(2);
    }
    else {
      local_res18[0] = 1;
    }
    uVar6 = IoRateThrottledEntryAcquireListLocks((longlong)param_1,param_2,local_res18,1);
    if ((int)uVar6 == 1) goto LAB_1c00034f6;
  }
  param_1[2] = 0;
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) != param_1) ||
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 != param_1)) {
LAB_1c0003530:
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    pcVar4 = (code *)swi(3);
    uVar7 = (*pcVar4)();
    return uVar7;
  }
  *plVar2 = lVar1;
  *(longlong **)(lVar1 + 8) = plVar2;
  param_1[1] = (longlong)param_1;
  *param_1 = (longlong)param_1;
  if ((param_2 != &DAT_1c000d308) && (param_1[5] != 0)) {
    lVar1 = param_1[3];
    plVar2 = param_1 + 3;
    if ((*(longlong **)(lVar1 + 8) != plVar2) ||
       (plVar3 = (longlong *)param_1[4], (longlong *)*plVar3 != plVar2)) goto LAB_1c0003530;
    *plVar3 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar3;
    param_1[4] = (longlong)plVar2;
    *plVar2 = (longlong)plVar2;
  }
  uVar7 = 1;
  if ((param_3 & 2) != 0) {
    return 1;
  }
LAB_1c00034f6:
  IoRateThrottledEntryReleaseListLocks((longlong)param_1,(longlong)param_2,local_res18);
  if ((param_3 & 1) == 0) {
    KeLowerIrql(uVar5);
  }
  return uVar7;
}



===== IoRateThrottledIosRecheck @ 1c0003540 =====

void IoRateThrottledIosRecheck(undefined8 ****param_1,uint param_2)

{
  undefined8 ******ppppppuVar1;
  undefined8 *****pppppuVar2;
  undefined8 *****pppppuVar3;
  code *pcVar4;
  undefined1 *puVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  undefined8 ******ppppppuVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined8 *****pppppuVar11;
  int iVar12;
  longlong local_res18;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [24];
  undefined8 local_48;
  undefined8 ******local_40;
  undefined8 ******ppppppuStack_38;
  
  local_40 = (undefined8 ******)0x0;
  ppppppuStack_38 = (undefined8 ******)0x0;
  IoRateLogThrottledIosRecheckStart(param_1,param_2);
  iVar12 = 0;
  uVar6 = KeQueryUnbiasedInterruptTime();
  local_48 = 0;
  local_res18 = 0;
  pppppuVar11 = (undefined8 *****)(uVar6 - 5000000);
  if (uVar6 < 5000000) {
    pppppuVar11 = (undefined8 *****)0x0;
  }
  IoGetStackLimits(&local_res18,&local_48);
  puVar9 = auStack_60 + (0x18 - local_res18);
  if ((param_2 & 4) == 0) {
    ppppppuStack_38 = &local_40;
    local_40 = &local_40;
    IoRateProcessingListGet(param_1 + 0x35,param_1 + 5,0,(longlong)&local_40);
    ppppppuVar8 = &local_40;
  }
  else {
    ppppppuVar8 = (undefined8 ******)param_1;
  }
  do {
    puVar7 = auStack_68;
    ppppppuVar1 = (undefined8 ******)*ppppppuVar8;
    if (ppppppuVar1 == ppppppuVar8) {
      puVar5 = auStack_68;
      if (puVar9 < (undefined1 *)0x3000) {
LAB_1c00036fa:
        puVar7 = puVar5;
        if (iVar12 != 0) {
          *(undefined8 *)(puVar7 + -8) = 0x1c0003716;
          KeInsertQueueDpc(&DAT_1c000d4d8,0,0);
        }
      }
      *(undefined8 *)(puVar7 + -8) = 0x1c0003631;
      IoRateLogThrottledIosRecheckStop(param_1,iVar12,(uint)(puVar9 < (undefined1 *)0x3000));
      return;
    }
    pppppuVar2 = *ppppppuVar1;
    iVar12 = iVar12 + 1;
    if (((undefined8 ******)pppppuVar2[1] != ppppppuVar1) ||
       (pppppuVar3 = ppppppuVar1[1], (undefined8 ******)*pppppuVar3 != ppppppuVar1)) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      puVar5 = auStack_60;
      goto LAB_1c00036fa;
    }
    *pppppuVar3 = pppppuVar2;
    pppppuVar2[1] = pppppuVar3;
    ppppppuVar1[1] = ppppppuVar1;
    *ppppppuVar1 = ppppppuVar1;
    if ((param_2 & 1) == 0) {
      if (((param_2 & 2) == 0) || (pppppuVar11 < ppppppuVar1[4])) {
        uVar10 = 0;
      }
      else {
        uVar10 = 1;
        param_2 = param_2 & 0xfffffffd;
      }
    }
    else {
      uVar10 = 1;
    }
    if (puVar9 < (undefined1 *)0x3000) {
      if (uVar10 != 0) {
        *(uint *)((longlong)ppppppuVar1 + 0x4c) = *(uint *)((longlong)ppppppuVar1 + 0x4c) | 2;
      }
      IoRateThrottledEntryListAdd((longlong *)(ppppppuVar1 + -6),&DAT_1c000d308,7,0);
    }
    else {
      IoRateThrottledEntryUnthrottle((longlong)(ppppppuVar1 + -6),1,uVar10,0x12);
    }
  } while( true );
}



===== IoRateLogThrottledIosRecheckStart @ 1c0003730 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IoRateLogThrottledIosRecheckStart(undefined8 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 auStack_a8 [48];
  undefined4 local_78;
  undefined1 *local_70;
  undefined4 local_68 [2];
  undefined8 local_60;
  undefined1 local_58 [32];
  undefined8 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  if (4 < DAT_1c000d000) {
    uVar2 = 4;
    uVar1 = _tlgKeywordOn(param_1,4);
    if ((char)uVar1 != '\0') {
      local_38 = &local_60;
      local_28 = local_68;
      local_70 = local_58;
      local_78 = (undefined4)uVar2;
      local_30 = 8;
      local_68[0] = param_2;
      local_60 = param_1;
      local_20 = uVar2;
      _tlgWriteEx_EtwWriteEx(param_1,&DAT_1c000a867);
    }
  }
  return;
}



===== IoRateLogThrottledIosRecheckStop @ 1c00037d0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IoRateLogThrottledIosRecheckStop(undefined8 param_1,undefined4 param_2,int param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 auStack_b8 [48];
  undefined4 local_88;
  undefined1 *local_80;
  undefined1 local_78 [4];
  undefined4 local_74;
  undefined8 local_70;
  undefined1 local_68 [32];
  undefined8 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined1 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_b8;
  if (4 < DAT_1c000d000) {
    uVar2 = 4;
    uVar1 = _tlgKeywordOn(param_1,4);
    if ((char)uVar1 != '\0') {
      local_48 = &local_70;
      local_38 = &local_74;
      local_78[0] = param_3 != 0;
      local_28 = local_78;
      local_40 = 8;
      local_80 = local_68;
      local_88 = 5;
      local_20 = 1;
      local_74 = param_2;
      local_70 = param_1;
      local_30 = uVar2;
      _tlgWriteEx_EtwWriteEx(param_1,&DAT_1c000abd1);
    }
  }
  return;
}



===== IoRateProcessingListGet @ 1c00038a0 =====

void IoRateProcessingListGet(undefined8 *param_1,undefined8 param_2,int param_3,longlong param_4)

{
  longlong *plVar1;
  undefined *puVar2;
  longlong *plVar3;
  code *pcVar4;
  uint uVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  longlong *plVar8;
  uint uVar9;
  undefined8 *puVar10;
  uint local_res18 [2];
  longlong local_res20;
  
  uVar9 = 1;
  local_res20 = param_4;
  if (param_3 != 0) {
    uVar9 = 4;
  }
LAB_1c00038d2:
  local_res18[0] = uVar9;
  uVar6 = ExAcquireSpinLockExclusive(param_2);
  puVar10 = (undefined8 *)*param_1;
  do {
    if (puVar10 == param_1) {
      ExReleaseSpinLockExclusive(param_2,uVar6);
      return;
    }
    plVar8 = (longlong *)((longlong)puVar10 - (longlong)param_3);
    uVar7 = IoRateThrottledEntryAcquireListLocks
                      ((longlong)plVar8,(undefined *)plVar8[2],local_res18,0);
    uVar5 = local_res18[0];
    if ((int)uVar7 == 0) {
      if (((byte)local_res18[0] & 0xc) == 8) {
        ExReleaseSpinLockExclusiveFromDpcLevel(plVar8[5] + 0x30);
        local_res18[0] = uVar5 & 0xfffffff3;
      }
      if (((byte)local_res18[0] & 3) == 2) {
        ExReleaseSpinLockExclusiveFromDpcLevel(plVar8[2] + 0x28);
      }
      puVar2 = (undefined *)plVar8[2];
      LOCK();
      *(int *)(plVar8 + 0xf) = (int)plVar8[0xf] + 1;
      UNLOCK();
      LOCK();
      *(longlong *)(puVar2 + 0x30) = *(longlong *)(puVar2 + 0x30) + 1;
      UNLOCK();
      ExReleaseSpinLockExclusiveFromDpcLevel(param_2);
      local_res18[0] = 0;
      uVar7 = IoRateThrottledEntryAcquireListLocks((longlong)plVar8,puVar2,local_res18,1);
      IoRateControlDereference((longlong)puVar2);
      IoRateThrottledEntryDereference((longlong)plVar8);
      if ((int)uVar7 == 1) goto LAB_1c0003a19;
      if (puVar10 != (undefined8 *)*param_1) break;
      if (((byte)uVar9 & 3) == 1) {
        local_res18[0] = local_res18[0] & 0xfffffffd | 1;
      }
      else {
        local_res18[0] = local_res18[0] & 0xfffffff7 | 4;
      }
    }
    puVar2 = (undefined *)plVar8[2];
    puVar10 = (undefined8 *)*puVar10;
    IoRateThrottledEntryListRemove(plVar8,puVar2,2);
    IoRateThrottledEntryReleaseListLocks((longlong)plVar8,(longlong)puVar2,local_res18);
    plVar1 = plVar8 + 6;
    plVar3 = *(longlong **)(local_res20 + 8);
    if (*plVar3 != local_res20) {
      pcVar4 = (code *)swi(0x29);
      (*pcVar4)(3);
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    *plVar1 = local_res20;
    plVar8[7] = (longlong)plVar3;
    *plVar3 = (longlong)plVar1;
    *(longlong **)(local_res20 + 8) = plVar1;
  } while( true );
  IoRateThrottledEntryReleaseListLocks((longlong)plVar8,0,local_res18);
LAB_1c0003a19:
  KeLowerIrql(uVar6);
  goto LAB_1c00038d2;
}



===== IoRateThrottledEntryUnthrottle @ 1c0003a90 =====

void IoRateThrottledEntryUnthrottle(longlong param_1,int param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  longlong local_48;
  longlong local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined4 local_28;
  undefined8 local_24;
  undefined4 local_1c;
  
  if (*(longlong *)(param_1 + 0x28) != 0) {
    IoRateThreadThrottleCtxThreadDereference(0x1c000d570,*(longlong *)(param_1 + 0x28),1);
    *(undefined8 *)(param_1 + 0x28) = 0;
  }
  if (*(longlong *)(param_1 + 0x60) != 0) {
    IoRateRecordIoAttributionQueueTime
              (*(longlong *)(param_1 + 0x48),*(longlong *)(param_1 + 0x60),0);
  }
  uVar1 = *(uint *)(param_1 + 0x7c);
  if (param_2 == 0) {
    if ((uVar1 & 4) != 0) {
      uVar1 = uVar1 & 0xfffffffb;
      *(uint *)(param_1 + 0x7c) = uVar1;
    }
    local_48 = 0;
    local_40 = 0;
    local_34 = 0;
    local_24 = 0;
    local_1c = 0;
    if ((uVar1 & 0x10) == 0) {
      bVar3 = *(longlong *)(param_1 + 0x68) != 0;
      if (bVar3) {
        local_48 = *(longlong *)(param_1 + 0x68);
      }
      local_24 = (ulonglong)bVar3;
      if (*(longlong *)(param_1 + 0x70) != 0) {
        local_24 = (ulonglong)(bVar3 + 1);
        local_40 = *(longlong *)(param_1 + 0x70);
      }
      if ((*(byte *)(param_1 + 0x58) & 2) == 0) {
        local_24 = CONCAT44(1,(undefined4)local_24);
      }
    }
    local_28 = *(undefined4 *)(param_1 + 0x80);
    local_30 = *(undefined8 *)(param_1 + 0x50);
    local_38 = param_4;
    IoRateIssueAndRecordIo
              (*(longlong *)(param_1 + 0x48),*(longlong *)(param_1 + 0x40),
               *(undefined8 *)(param_1 + 0x58),&local_48);
  }
  else {
    uVar2 = param_3 | 0x10;
    if ((uVar1 & 0x10) == 0) {
      uVar2 = param_3;
    }
    IoRateProcessIrpWrapper
              (*(undefined8 **)(param_1 + 0x48),uVar2,*(longlong **)(param_1 + 0x50),
               *(undefined4 *)(param_1 + 0x80),*(longlong *)(param_1 + 0x40));
  }
  IoRateThrottledEntryDereference(param_1);
  return;
}



===== _tlgKeywordOn @ 1c0003c00 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong _tlgKeywordOn(undefined8 param_1,ulonglong param_2)

{
  ulonglong in_RAX;
  
  if (((_DAT_1c000d010 & param_2) == 0) ||
     (in_RAX = DAT_1c000d018 & param_2, in_RAX != DAT_1c000d018)) {
    return in_RAX & 0xffffffffffffff00;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== IoRateThrottleIrp @ 1c0003c30 =====

int IoRateThrottleIrp(longlong param_1,longlong param_2,int param_3,longlong *param_4,
                     undefined8 *param_5,undefined8 param_6,uint param_7,longlong param_8,
                     int param_9,int param_10,undefined *param_11,undefined8 param_12,int param_13,
                     uint *param_14,undefined4 *param_15)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  longlong lVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  longlong *plVar8;
  ulonglong *puVar9;
  ulonglong uVar10;
  uint uVar11;
  undefined1 local_res10;
  
  local_res10 = 0;
  cVar5 = ExAcquireRundownProtectionCacheAware(*(undefined8 *)(param_2 + 0x78));
  if (cVar5 == '\0') {
    return 5;
  }
  uVar7 = 1;
  plVar8 = (longlong *)ExAllocateFromLookasideListEx(&DAT_1c000d6b0);
  if (plVar8 == (longlong *)0x0) {
    param_9 = 5;
    goto LAB_1c0003f1c;
  }
  if (param_8 == 0) {
    param_8 = KeQueryUnbiasedInterruptTime();
  }
  IoRateThrottledEntryInitialize
            (plVar8,param_8,param_2,param_3,param_4,param_1,param_12,param_6,param_9);
  if ((*(ulonglong *)(param_1 + 0x98) == 0) || (param_10 == 0xd)) {
LAB_1c0003d52:
    LOCK();
    *(int *)(plVar8 + 0xf) = (int)plVar8[0xf] + 1;
    UNLOCK();
    uVar11 = uVar7 | 2;
    if (plVar8[0xc] != 0) {
      IoRateRecordIoAttributionQueueTime(param_1,plVar8[0xc],1);
    }
    pcVar3 = *(char **)(param_1 + 0xb8);
    cVar5 = *pcVar3;
    uVar1 = *(uint *)(param_1 + 0x10);
    iVar6 = IoGetIoPriorityHint(param_1);
    uVar2 = *(uint *)(pcVar3 + 8);
    lVar4 = *(longlong *)(param_1 + 0x98);
    if (lVar4 != 0) {
      ObfReferenceObject(lVar4);
    }
    if ((param_7 & 0x10) != 0) {
      *(uint *)((longlong)plVar8 + 0x7c) = *(uint *)((longlong)plVar8 + 0x7c) | 0x10;
    }
    if (param_10 == 0xd) {
      param_11 = *(undefined **)(param_2 + 0x28);
      uVar11 = uVar7 | 0x12;
      local_res10 = ExAcquireSpinLockExclusive(param_11 + 0x28);
      if (*(uint *)(param_2 + 0x84) <= *(uint *)(param_2 + 0x88)) {
        uVar7 = param_7 | 2;
        if (param_9 != 0) {
          uVar7 = param_7 | 6;
        }
        param_7 = uVar7;
        goto LAB_1c0003dfc;
      }
      ExReleaseSpinLockExclusive(param_11 + 0x28,local_res10);
      if ((*(uint *)((longlong)plVar8 + 0x7c) & 4) != 0) {
        *(uint *)((longlong)plVar8 + 0x7c) = *(uint *)((longlong)plVar8 + 0x7c) & 0xfffffffb;
      }
    }
    else {
      if (param_10 != 0xb) {
        if (param_10 == 0x10) {
          param_11 = *(undefined **)(param_2 + 0x30);
        }
        else {
          param_11 = &DAT_1c000d138;
        }
      }
LAB_1c0003dfc:
      uVar10 = (ulonglong)(uint)(0xf < uVar11);
      if (((param_7 & 8) != 0) && (param_10 != 0xd)) {
        uVar10 = (ulonglong)(0xf < uVar11 | 4);
      }
      IoRateThrottledEntryListAdd(plVar8,param_11,param_10,uVar10);
      if (0xf < uVar11) {
        ExReleaseSpinLockExclusive(param_11 + 0x28,local_res10);
        uVar11 = uVar11 & 0xffffffef;
      }
      param_9 = IoRateGetReason(uVar1,cVar5,lVar4,iVar6,param_2,param_3,param_4,param_5,uVar2,
                                param_7,param_13,(longlong *)0x0,(ulonglong *)0x0,param_14,param_15)
      ;
      if (param_10 != param_9) {
        uVar10 = IoRateThrottledEntryListRemove(plVar8,param_11,0);
        uVar7 = (uint)uVar10 & 1;
        uVar11 = uVar11 | uVar7 * 8;
        if ((uVar10 & 1) != 0) goto LAB_1c0003ed4;
        param_9 = uVar7 + 0xe;
      }
      uVar11 = uVar11 & 0xfffffff9;
    }
LAB_1c0003ed4:
    if (lVar4 != 0) {
      ObDereferenceObjectDeferDelete(lVar4);
    }
    if (((uVar11 & 8) != 0) && (plVar8[0xc] != 0)) {
      IoRateRecordIoAttributionQueueTime(param_1,plVar8[0xc],0);
    }
    if ((uVar11 & 4) != 0) {
      IoRateThreadThrottleCtxThreadDereference(0x1c000d570,plVar8[5],1);
      plVar8[5] = 0;
    }
    uVar7 = uVar11;
    if ((uVar11 & 2) != 0) {
      IoRateThrottledEntryDereference((longlong)plVar8);
    }
  }
  else {
    puVar9 = IoRateThreadThrottleCtxThreadReference
                       ((ulonglong *)&DAT_1c000d570,*(ulonglong *)(param_1 + 0x98),1);
    plVar8[5] = (longlong)puVar9;
    if (puVar9 != (ulonglong *)0x0) {
      uVar7 = 5;
      goto LAB_1c0003d52;
    }
    param_9 = 5;
  }
  IoRateThrottledEntryDereference((longlong)plVar8);
  if ((uVar7 & 1) == 0) {
    return param_9;
  }
LAB_1c0003f1c:
  ExReleaseRundownProtectionCacheAware(*(undefined8 *)(param_2 + 0x78));
  return param_9;
}



===== IoRateThrottledEntryDereference @ 1c00040d0 =====

void IoRateThrottledEntryDereference(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 0x78);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    if (*(longlong *)(param_1 + 0x68) != 0) {
      IoRateControlDereference(*(longlong *)(param_1 + 0x68));
    }
    if (*(longlong *)(param_1 + 0x70) != 0) {
      IoRateControlDereference(*(longlong *)(param_1 + 0x70));
    }
    ExFreeToLookasideListEx(&DAT_1c000d6b0,param_1);
  }
  return;
}



===== IoRateThrottledEntryInitialize @ 1c0004130 =====

void IoRateThrottledEntryInitialize
               (void *param_1,undefined8 param_2,longlong param_3,int param_4,longlong *param_5,
               undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined4 param_9)

{
  longlong lVar1;
  longlong *plVar2;
  
  memset(param_1,0,0x90);
  lVar1 = (longlong)param_1 + 0x18;
  *(void **)((longlong)param_1 + 8) = param_1;
  *(void **)param_1 = param_1;
  *(longlong *)((longlong)param_1 + 0x20) = lVar1;
  *(longlong *)lVar1 = lVar1;
  lVar1 = (longlong)param_1 + 0x30;
  *(longlong *)((longlong)param_1 + 0x38) = lVar1;
  *(longlong *)lVar1 = lVar1;
  *(undefined8 *)((longlong)param_1 + 0x48) = param_6;
  *(undefined8 *)((longlong)param_1 + 0x58) = param_7;
  *(undefined8 *)((longlong)param_1 + 0x60) = param_8;
  *(undefined4 *)((longlong)param_1 + 0x78) = 1;
  *(undefined8 *)((longlong)param_1 + 0x50) = param_2;
  *(longlong *)((longlong)param_1 + 0x40) = param_3;
  *(undefined4 *)((longlong)param_1 + 0x80) = *(undefined4 *)(param_3 + 0x88);
  *(uint *)((longlong)param_1 + 0x7c) =
       ((uint)param_7 & 1) << 2 | *(uint *)((longlong)param_1 + 0x7c) & 0xfffffffb;
  *(undefined4 *)((longlong)param_1 + 0x84) = param_9;
  if (param_4 != 0) {
    if (*param_5 != 0) {
      LOCK();
      plVar2 = (longlong *)(*param_5 + 0x30);
      *plVar2 = *plVar2 + 1;
      UNLOCK();
      *(longlong *)((longlong)param_1 + 0x68) = *param_5;
    }
    if (param_5[1] != 0) {
      LOCK();
      plVar2 = (longlong *)(param_5[1] + 0x30);
      *plVar2 = *plVar2 + 1;
      UNLOCK();
      *(longlong *)((longlong)param_1 + 0x70) = param_5[1];
    }
  }
  return;
}



===== IoRateThreadThrottleCtxThreadDereference @ 1c0004220 =====

void IoRateThreadThrottleCtxThreadDereference(longlong param_1,longlong param_2,longlong param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined1 uVar3;
  longlong lVar4;
  bool bVar5;
  
  lVar4 = *(longlong *)(param_2 + 0x38);
  do {
    if (lVar4 == param_3) {
      uVar3 = ExAcquireSpinLockExclusive(param_1 + 0x10);
      LOCK();
      plVar1 = (longlong *)(param_2 + 0x38);
      lVar4 = *plVar1;
      *plVar1 = *plVar1 - param_3;
      UNLOCK();
      if (lVar4 == param_3) {
        RtlRbRemoveNode(param_1,param_2);
        ExReleaseSpinLockExclusive(param_1 + 0x10,uVar3);
        IoRateThreadThrottleEntryDelete(param_2);
        return;
      }
      ExReleaseSpinLockExclusive(param_1 + 0x10,uVar3);
      return;
    }
    LOCK();
    lVar2 = *(longlong *)(param_2 + 0x38);
    bVar5 = lVar4 == lVar2;
    if (bVar5) {
      *(longlong *)(param_2 + 0x38) = lVar4 - param_3;
    }
    else {
      lVar4 = lVar2;
    }
    UNLOCK();
  } while (!bVar5);
  return;
}



===== IoRateIssueAndRecordIo @ 1c00042f0 =====

void IoRateIssueAndRecordIo(longlong param_1,longlong param_2,undefined8 param_3,longlong *param_4)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  if (param_4[3] != 0) {
    IoRateLogUnblockIo(param_1,(longlong)param_4,*(undefined4 *)(param_2 + 0x88));
  }
  uVar1 = *(uint *)(param_4 + 5);
  uVar2 = *(uint *)(*(longlong *)(param_1 + 0xb8) + 8);
  uVar6 = (ulonglong)uVar2;
  if (*(int *)((longlong)param_4 + 0x24) != 0) {
    lVar3 = *param_4;
    lVar4 = param_4[1];
    uVar5 = (ulonglong)((DAT_1c000d694 - 1) + uVar2) / (ulonglong)DAT_1c000d694;
    if ((lVar3 != 0) && ((*(uint *)(param_2 + 0xa0) & 1) == 0)) {
      LOCK();
      *(longlong *)(lVar3 + 0x1a0) = *(longlong *)(lVar3 + 0x1a0) + uVar5;
      UNLOCK();
      LOCK();
      *(longlong *)(lVar3 + 0x198) = *(longlong *)(lVar3 + 0x198) + uVar6;
      UNLOCK();
    }
    if (lVar4 != 0) {
      LOCK();
      *(longlong *)(lVar4 + 0x1a0) = *(longlong *)(lVar4 + 0x1a0) + uVar5;
      UNLOCK();
      LOCK();
      *(longlong *)(lVar4 + 0x198) = *(longlong *)(lVar4 + 0x198) + uVar6;
      UNLOCK();
    }
  }
  if ((uVar1 & 1) != 0) {
    LOCK();
    *(longlong *)(param_2 + 0x90) =
         *(longlong *)(param_2 + 0x90) +
         (longlong)(int)(((DAT_1c000d694 - 1) + uVar2) / DAT_1c000d694);
    UNLOCK();
    LOCK();
    *(longlong *)(param_2 + 0x98) = *(longlong *)(param_2 + 0x98) + uVar6;
    UNLOCK();
  }
  lVar3 = *(longlong *)(param_1 + 0xb8);
  *(code **)(lVar3 + -0x10) = IoRateReadWriteCompletion;
  *(undefined8 *)(lVar3 + -8) = param_3;
  *(undefined1 *)(lVar3 + -0x45) = 0xe0;
  IofCallDriver(*(undefined8 *)(param_2 + 0x18),param_1);
  return;
}



===== IoRateProcessIrpWrapper @ 1c0004420 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
IoRateProcessIrpWrapper
          (undefined8 *param_1,uint param_2,longlong *param_3,undefined4 param_4,longlong param_5)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  longlong *plVar7;
  longlong lVar8;
  undefined1 auStackY_148 [32];
  longlong local_f0;
  int local_e8 [2];
  longlong local_e0;
  ulonglong local_d8 [3];
  int local_c0;
  undefined4 local_bc;
  longlong *local_b8;
  undefined4 local_b0;
  ulonglong local_ac;
  undefined4 local_a4;
  longlong local_a0 [5];
  undefined8 local_78 [2];
  undefined8 local_68 [6];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_148;
  local_d8[2] = 0;
  local_bc = 0;
  local_ac = 0;
  local_a4 = 0;
  local_d8[0] = 0;
  uVar4 = 0;
  local_f0 = 0;
  local_e0 = 0;
  local_a0[0] = 0;
  local_a0[1] = 0;
  local_a0[2] = 0;
  local_a0[3] = 0;
  local_e8[0] = 0;
  iVar2 = IoGetIoAttributionHandle(0,&local_f0);
  if (iVar2 < 0) {
    local_f0 = 0;
  }
  else {
    uVar4 = (*(code *)*DAT_1c000d0e8)
                      (local_f0,*(undefined8 *)(param_5 + 0x20),param_1[0x13],local_a0);
    if (uVar4 != 0) {
      puVar6 = local_68;
      lVar8 = 2;
      plVar7 = local_a0;
      do {
        lVar1 = *plVar7;
        if (lVar1 != 0) {
          puVar6[1] = *(undefined8 *)(lVar1 + 0x1a0);
          *puVar6 = *(undefined8 *)(lVar1 + 0x198);
        }
        plVar7 = plVar7 + 1;
        puVar6 = puVar6 + 4;
        lVar8 = lVar8 + -1;
      } while (lVar8 != 0);
      if (local_a0[1] != 0) {
        local_f0 = *(longlong *)(local_a0[1] + 0x1b8);
      }
    }
    if ((local_e0 != local_f0) && (local_e0 != 0)) {
      (*(code *)DAT_1c000d0e8[5])(param_1);
    }
  }
  uVar3 = IoRateProcessIrpHelper
                    (param_1,param_5,uVar4,local_a0,local_78,local_f0,param_2,param_3,local_d8,
                     local_e8);
  if (uVar4 != 0) {
    (*(code *)DAT_1c000d0e8[1])(local_a0 + 2);
  }
  if ((uVar3 & 2) != 0) {
    local_c0 = local_e8[0];
    local_d8[1] = 0;
    local_d8[2] = 0;
    local_bc = 0;
    local_ac = 0;
    local_a4 = 0;
    local_b8 = param_3;
    local_b0 = param_4;
    if (param_3 != (longlong *)0x0) {
      IoRateLogUnblockIo((longlong)param_1,(longlong)(local_d8 + 1),*(undefined4 *)(param_5 + 0x88))
      ;
    }
    uVar4 = *(uint *)(param_1[0x17] + 8);
    if ((local_ac & 0x100000000) != 0) {
      LOCK();
      *(longlong *)(param_5 + 0x90) =
           *(longlong *)(param_5 + 0x90) +
           (longlong)(int)(((DAT_1c000d694 - 1) + uVar4) / DAT_1c000d694);
      UNLOCK();
      LOCK();
      *(longlong *)(param_5 + 0x98) = *(longlong *)(param_5 + 0x98) + (ulonglong)uVar4;
      UNLOCK();
    }
    lVar8 = param_1[0x17];
    *(code **)(lVar8 + -0x10) = IoRateReadWriteCompletion;
    *(ulonglong *)(lVar8 + -8) = local_d8[0];
    *(undefined1 *)(lVar8 + -0x45) = 0xe0;
    uVar5 = IofCallDriver(*(undefined8 *)(param_5 + 0x18),param_1);
    if ((uVar3 & 1) == 0) {
      return uVar5;
    }
  }
  return 0x103;
}



===== IoRateDispatchReadWrite @ 1c0004710 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c0004871) */

undefined8 IoRateDispatchReadWrite(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  longlong *plVar8;
  longlong lVar9;
  undefined1 auStackY_148 [32];
  longlong local_f0;
  int local_e8 [2];
  longlong local_e0;
  ulonglong local_d8 [3];
  int local_c0;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined4 local_b0;
  undefined8 local_ac;
  undefined4 local_a4;
  longlong local_a0 [5];
  undefined8 local_78 [2];
  undefined8 local_68 [6];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_148;
  if ((DAT_1c000d690 & 1) == 0) {
    puVar7 = (undefined8 *)param_2[0x17];
    uVar5 = 0;
    local_d8[2] = 0;
    puVar7[-9] = *puVar7;
    puVar7[-8] = puVar7[1];
    local_bc = 0;
    local_ac = 0;
    local_a4 = 0;
    puVar7[-7] = puVar7[2];
    puVar7[-6] = puVar7[3];
    local_d8[0] = 0;
    local_f0 = 0;
    local_e0 = 0;
    puVar7[-5] = puVar7[4];
    puVar7[-4] = puVar7[5];
    puVar7[-3] = puVar7[6];
    *(undefined1 *)((longlong)puVar7 + -0x45) = 0;
    lVar1 = *(longlong *)(param_1 + 0x40);
    local_a0[0] = 0;
    local_a0[1] = 0;
    local_e8[0] = 0;
    local_a0[2] = 0;
    local_a0[3] = 0;
    iVar3 = IoGetIoAttributionHandle(param_2,&local_f0);
    if (iVar3 < 0) {
      local_f0 = 0;
    }
    else {
      uVar5 = (*(code *)*DAT_1c000d0e8)
                        (local_f0,*(undefined8 *)(lVar1 + 0x20),param_2[0x13],local_a0);
      if (uVar5 != 0) {
        puVar7 = local_68;
        lVar9 = 2;
        plVar8 = local_a0;
        do {
          lVar2 = *plVar8;
          if (lVar2 != 0) {
            puVar7[1] = *(undefined8 *)(lVar2 + 0x1a0);
            *puVar7 = *(undefined8 *)(lVar2 + 0x198);
          }
          plVar8 = plVar8 + 1;
          puVar7 = puVar7 + 4;
          lVar9 = lVar9 + -1;
        } while (lVar9 != 0);
        if (local_a0[1] != 0) {
          local_f0 = *(longlong *)(local_a0[1] + 0x1b8);
        }
      }
      if ((local_e0 != local_f0) && (local_e0 != 0)) {
        (*(code *)DAT_1c000d0e8[5])(param_2);
      }
    }
    uVar4 = IoRateProcessIrpHelper
                      (param_2,lVar1,uVar5,local_a0,local_78,local_f0,0,(longlong *)0x0,local_d8,
                       local_e8);
    if (uVar5 != 0) {
      (*(code *)DAT_1c000d0e8[1])(local_a0 + 2);
    }
    if ((uVar4 & 2) != 0) {
      local_c0 = local_e8[0];
      local_ac = 0;
      local_d8[1] = 0;
      local_d8[2] = 0;
      local_bc = 0;
      local_a4 = 0;
      local_b0 = 0;
      local_b8 = 0;
      lVar9 = param_2[0x17];
      *(code **)(lVar9 + -0x10) = IoRateReadWriteCompletion;
      *(ulonglong *)(lVar9 + -8) = local_d8[0];
      *(undefined1 *)(lVar9 + -0x45) = 0xe0;
      uVar6 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18),param_2);
      if ((uVar4 & 1) == 0) {
        return uVar6;
      }
    }
    uVar6 = 0x103;
  }
  else {
    uVar6 = IoRateDispatchPassthrough(param_1,(longlong)param_2);
  }
  return uVar6;
}



===== IoRateProcessIrpHelper @ 1c0004a20 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint IoRateProcessIrpHelper
               (undefined8 *param_1,longlong param_2,uint param_3,longlong *param_4,
               undefined8 *param_5,undefined8 param_6,uint param_7,longlong *param_8,
               ulonglong *param_9,int *param_10)

{
  uint uVar1;
  char *pcVar2;
  longlong lVar3;
  ulonglong uVar4;
  bool bVar5;
  int iVar6;
  ulonglong uVar7;
  int iVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  int iVar12;
  undefined1 auStackY_198 [32];
  int local_114;
  uint local_110;
  int local_10c;
  uint local_108 [2];
  longlong *local_100;
  ulonglong local_f8;
  undefined *local_f0;
  undefined8 *local_e8;
  longlong local_e0;
  undefined *puStack_d8;
  longlong local_d0;
  ulonglong *local_c8;
  int *local_c0;
  undefined *local_b8;
  uint local_b0;
  undefined4 local_ac;
  undefined *local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined8 **local_98;
  undefined8 local_90;
  uint *local_88;
  undefined8 local_80;
  longlong **local_78;
  undefined8 local_70;
  int *local_68;
  undefined8 local_60;
  undefined **local_58;
  undefined8 local_50;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_198;
  pcVar2 = (char *)param_1[0x17];
  local_e8 = param_5;
  local_c8 = param_9;
  uVar9 = 0;
  local_c0 = param_10;
  local_e0 = 0;
  puStack_d8 = (undefined *)0x0;
  local_f8 = 0;
  local_10c = 0;
  local_108[0] = 0;
  local_110 = param_3;
  local_100 = param_4;
  iVar6 = IoGetIoPriorityHint();
  local_114 = 0;
  local_f0 = (undefined *)CONCAT44(local_f0._4_4_,*(undefined4 *)(pcVar2 + 8));
  if ((*pcVar2 != '\x04') && ((*(uint *)(param_1 + 2) & 2) != 0)) {
    local_114 = (**(code **)(DAT_1c000d0e8 + 0x38))(param_1);
  }
  iVar6 = IoRateGetReason(*(uint *)(param_1 + 2),*pcVar2,param_1[0x13],iVar6,param_2,param_3,
                          local_100,local_e8,(uint)local_f0,param_7,local_114,&local_e0,&local_f8,
                          local_108,&local_10c);
  uVar7 = local_f8;
  if ((*pcVar2 == '\x04') &&
     (((param_3 != 0 &&
       (((*local_100 != 0 && ((*(uint *)(*local_100 + 0x1c8) & 2) != 0)) ||
        ((local_100[1] != 0 && ((*(uint *)(local_100[1] + 0x1c8) & 2) != 0)))))) ||
      ((local_10c != 0 &&
       (((*local_100 != 0 && ((*(uint *)(*local_100 + 0x1c8) & 4) != 0)) ||
        ((local_100[1] != 0 && ((*(uint *)(local_100[1] + 0x1c8) & 4) != 0)))))))))) {
    *(byte *)(param_1[0x17] + -0x46) = *(byte *)(param_1[0x17] + -0x46) | 4;
  }
  iVar12 = iVar6;
  if (10 < iVar6) {
    iVar12 = 0;
  }
  if ((local_f8 & 1) != 0) {
    IoRateReservationIoCountIncrement(param_2);
    IoRatePreventNonReservationStarvation();
  }
LAB_1c0004b7d:
  iVar8 = iVar6;
  if (10 < iVar6) goto LAB_1c0004cd7;
  do {
    if ((param_7 & 0x10) == 0) {
      uVar10 = uVar7 >> 1;
      uVar1 = *(uint *)(param_1[0x17] + 8);
      uVar11 = (ulonglong)uVar1;
      if (local_110 != 0) {
        local_d0 = local_100[1];
        lVar3 = *local_100;
        uVar4 = (ulonglong)((DAT_1c000d694 - 1) + uVar1) / (ulonglong)DAT_1c000d694;
        if ((lVar3 != 0) && ((*(uint *)(param_2 + 0xa0) & 1) == 0)) {
          LOCK();
          *(longlong *)(lVar3 + 0x1a0) = *(longlong *)(lVar3 + 0x1a0) + uVar4;
          UNLOCK();
          LOCK();
          *(longlong *)(lVar3 + 0x198) = *(longlong *)(lVar3 + 0x198) + uVar11;
          UNLOCK();
          uVar7 = local_f8;
        }
        if (local_d0 != 0) {
          LOCK();
          *(longlong *)(local_d0 + 0x1a0) = *(longlong *)(local_d0 + 0x1a0) + uVar4;
          UNLOCK();
          LOCK();
          *(longlong *)(local_d0 + 0x198) = *(longlong *)(local_d0 + 0x198) + uVar11;
          UNLOCK();
          uVar7 = local_f8;
        }
      }
      if ((uVar10 & 1) == 0) {
        LOCK();
        *(longlong *)(param_2 + 0x90) =
             *(longlong *)(param_2 + 0x90) +
             (longlong)(int)(((DAT_1c000d694 - 1) + uVar1) / DAT_1c000d694);
        UNLOCK();
        LOCK();
        *(longlong *)(param_2 + 0x98) = *(longlong *)(param_2 + 0x98) + uVar11;
        UNLOCK();
        uVar7 = local_f8;
      }
      param_7 = param_7 | 0x10;
    }
    if ((iVar6 != 5) && (iVar6 != iVar12)) {
      iVar12 = iVar6;
    }
    if (local_e0 != 0) {
      (**(code **)(DAT_1c000d0e8 + 0x28))(param_1);
    }
    if ((iVar6 == 5) || ((uVar7 & 4) != 0)) {
      bVar5 = true;
    }
    else {
      bVar5 = false;
    }
    if (iVar6 == 8) {
      bVar5 = true;
    }
    if ((*(int *)(param_2 + 0x84) == -1) || ((uVar7 & 2) != 0)) {
LAB_1c0004c7d:
      uVar9 = uVar9 | 2;
      iVar8 = iVar6;
      goto LAB_1c0004c80;
    }
    ExAcquireSpinLockExclusive(*(longlong *)(param_2 + 0x28) + 0x28);
    if ((*(uint *)(param_2 + 0x88) < *(uint *)(param_2 + 0x84)) || (bVar5)) {
      *(uint *)(param_2 + 0x88) = *(uint *)(param_2 + 0x88) + 1;
      ExReleaseSpinLockExclusive(*(longlong *)(param_2 + 0x28) + 0x28);
      goto LAB_1c0004c7d;
    }
    ExReleaseSpinLockExclusive(*(longlong *)(param_2 + 0x28) + 0x28);
    iVar8 = 0xd;
LAB_1c0004cd7:
    if (uVar9 == 0) {
      *(byte *)(param_1[0x17] + 3) = *(byte *)(param_1[0x17] + 3) | 1;
      uVar9 = 1;
    }
    if (iVar8 != 0x11) break;
    iVar6 = IoRateSplitAndIssueIrp
                      (param_2,(longlong)param_1,(undefined8 *)pcVar2,(uint)local_f0,local_108[0]);
    if (-1 < iVar6) goto LAB_1c0004c80;
    iVar6 = 5;
  } while( true );
  iVar6 = IoRateThrottleIrp((longlong)param_1,param_2,local_110,local_100,local_e8,param_6,param_7,
                            (longlong)param_8,iVar12,iVar8,puStack_d8,uVar7,local_114,local_108,
                            &local_10c);
  if ((iVar8 == iVar6) || (iVar6 == 0xe)) {
LAB_1c0004c80:
    if (5 < DAT_1c000d000) {
      if (((DAT_1c000d010 & 1) == 0) || (((uint)DAT_1c000d018 & 1) != DAT_1c000d018)) {
        bVar5 = false;
      }
      else {
        bVar5 = true;
      }
      if (bVar5) {
        local_98 = &local_e8;
        local_90 = 8;
        local_110 = param_7;
        local_80 = 4;
        local_88 = &local_110;
        local_100 = param_8;
        local_78 = &local_100;
        local_68 = &local_114;
        local_f0 = puStack_d8;
        local_58 = &local_f0;
        local_b8 = PTR_DAT_1c000d008;
        puStack_d8 = (undefined *)0x1;
        local_70 = 8;
        local_60 = 4;
        local_50 = 8;
        local_e0 = 0x50b000000;
        local_b0 = (uint)*(ushort *)PTR_DAT_1c000d008;
        local_a8 = &DAT_1c000ae9f;
        local_9c = 1;
        local_ac = 2;
        local_a0 = 0x40;
        local_114 = iVar8;
        local_e8 = param_1;
        EtwWriteEx(DAT_1c000d020,&local_e0,0,1);
        uVar7 = local_f8;
      }
    }
    *local_c8 = uVar7;
    *local_c0 = iVar8;
    return uVar9;
  }
  goto LAB_1c0004b7d;
}



===== IoRateDispatchPassthrough @ 1c0005030 =====

void IoRateDispatchPassthrough(longlong param_1,longlong param_2)

{
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver(*(undefined8 *)(*(longlong *)(param_1 + 0x40) + 0x18));
  return;
}



===== IoRateGetReason @ 1c0005060 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int IoRateGetReason(uint param_1,char param_2,longlong param_3,int param_4,longlong param_5,
                   int param_6,longlong *param_7,undefined8 *param_8,uint param_9,uint param_10,
                   int param_11,longlong *param_12,ulonglong *param_13,uint *param_14,
                   undefined4 *param_15)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  bool bVar3;
  bool bVar4;
  undefined8 *puVar5;
  char cVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong local_50;
  longlong local_48;
  longlong lStack_40;
  ulonglong local_38;
  ulonglong uStack_30;
  
  local_50 = 0;
  bVar4 = false;
  bVar3 = false;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  lStack_40 = 0;
  if ((param_10 & 2) != 0) {
    local_50 = 0;
    if ((*(int *)(param_5 + 0x80) < 1) || ((param_10 & 4) != 0)) {
      iVar8 = 0xd;
    }
    else {
      iVar8 = 0xc;
    }
    goto LAB_1c000528a;
  }
  iVar8 = IoRateGetRateControlsReason
                    (param_6,param_7,param_8,param_9,param_10 >> 4 & 1,&local_48,&local_50,param_14)
  ;
  local_38 = *(ulonglong *)(param_5 + 0x90);
  uStack_30 = *(ulonglong *)(param_5 + 0x98);
  bVar3 = bVar4;
  if (((iVar8 == 0x10) && (local_38 < DAT_1c000d698)) && (uStack_30 < DAT_1c000d6a0)) {
    uVar12 = (ulonglong)DAT_1c000d694 * (DAT_1c000d698 - local_38);
    uVar11 = DAT_1c000d6a0 - uStack_30;
    if (uVar12 <= DAT_1c000d6a0 - uStack_30) {
      uVar11 = uVar12;
    }
    if (uVar11 < param_9) {
      *param_14 = (uint)uVar11;
      iVar8 = 0x11;
    }
    else {
      iVar8 = 0;
      bVar3 = true;
    }
  }
  if ((0 < *(int *)(param_5 + 0x80)) && (iVar8 == 0)) {
    iVar8 = 0xc;
  }
  if (param_11 != 0) {
    iVar8 = 8;
    lStack_40 = 0;
    goto LAB_1c000528a;
  }
  if ((param_10 & 1) != 0) {
    iVar8 = 1;
    lStack_40 = 0;
    goto LAB_1c000528a;
  }
  if (((param_1 & 2) == 0) || (param_2 != '\x04')) {
LAB_1c00051a6:
    if (param_3 != 0) goto LAB_1c00051ab;
LAB_1c00051c6:
    if ((param_6 != 0) || (param_3 == 0)) goto LAB_1c000528a;
    cVar6 = PsIsSystemThread(param_3);
    if (cVar6 == '\0') {
      uVar11 = PsGetThreadProcess(param_3);
      uVar7 = ExAcquireSpinLockShared(&DAT_1c000d620);
      puVar5 = DAT_1c000d610;
      if ((DAT_1c000d618 & 1) != 0) {
        if (DAT_1c000d610 == (undefined8 *)0x0) {
          ExReleaseSpinLockShared(&DAT_1c000d620,uVar7);
          goto LAB_1c000528a;
        }
        puVar5 = (undefined8 *)((ulonglong)DAT_1c000d610 ^ 0x1c000d610);
      }
      while (puVar2 = puVar5, puVar2 != (undefined8 *)0x0) {
        if (uVar11 < (ulonglong)puVar2[3]) {
          puVar1 = (undefined8 *)*puVar2;
        }
        else {
          if (uVar11 <= (ulonglong)puVar2[3]) break;
          puVar1 = (undefined8 *)puVar2[1];
        }
        puVar5 = puVar1;
        if (((DAT_1c000d618 & 1) != 0) && (puVar5 = (undefined8 *)0x0, puVar1 != (undefined8 *)0x0))
        {
          puVar5 = (undefined8 *)((ulonglong)puVar2 ^ (ulonglong)puVar1);
        }
      }
      ExReleaseSpinLockShared(&DAT_1c000d620);
      if (puVar2 == (undefined8 *)0x0) goto LAB_1c000528a;
    }
    iVar8 = 2;
  }
  else {
    if (param_3 == 0) {
LAB_1c0005185:
      if ((param_10 & 0x20) == 0) {
        iVar8 = 3;
        local_50 = local_50 & 0xfffffffffffffffe;
        lStack_40 = 0;
        goto LAB_1c000528a;
      }
      goto LAB_1c00051a6;
    }
    uVar10 = PsGetThreadProcess(param_3);
    cVar6 = PsIsSystemProcess(uVar10);
    if (cVar6 != '\0') goto LAB_1c0005185;
LAB_1c00051ab:
    iVar9 = (**(code **)(DAT_1c000d0e8 + 0x18))(param_3);
    if (iVar9 == 0) goto LAB_1c00051c6;
    iVar8 = 4;
  }
  lStack_40 = 0;
LAB_1c000528a:
  if (param_12 != (longlong *)0x0) {
    *param_12 = local_48;
    param_12[1] = lStack_40;
  }
  if (param_13 != (ulonglong *)0x0) {
    if (param_4 < 2) {
      local_50 = local_50 & 0xfffffffffffffffe | 2;
    }
    else if (2 < param_4) {
      local_50 = local_50 | 4;
    }
    *param_13 = local_50;
  }
  if ((bVar3) && (iVar8 == 0)) {
    *param_15 = 1;
    return 0;
  }
  *param_15 = 0;
  return iVar8;
}



===== IoRateGetRateControlsReason @ 1c0005480 =====

undefined4
IoRateGetRateControlsReason
          (int param_1,longlong *param_2,undefined8 *param_3,uint param_4,int param_5,
          longlong *param_6,undefined8 *param_7,uint *param_8)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  undefined4 uVar6;
  uint local_res8;
  uint local_68;
  uint local_64;
  longlong local_60;
  uint local_58;
  uint local_54;
  int local_50;
  uint local_4c;
  ulonglong local_48 [4];
  
  uVar6 = 0;
  lVar3 = 0;
  uVar4 = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  if (param_1 == 0) {
    lVar5 = 0;
    goto LAB_1c00054be;
  }
  local_60 = *param_2;
  lVar5 = param_2[1];
  if ((param_1 == 2) && ((*(uint *)(lVar5 + 0x1c8) & 1) != 0)) {
    IoRateControlAddStandaloneVolumeControl(local_60,lVar5);
  }
  iVar2 = 4;
  local_64 = 0xffffffff;
  local_50 = 4;
  local_res8 = -(uint)(param_5 != 0) & 2;
  local_58 = 0xffffffff;
  local_54 = 0xffffffff;
  local_68 = 0xffffffff;
  local_4c = local_res8;
  if (lVar5 != 0) {
    *(undefined8 *)(lVar5 + 400) = param_3[7];
    *(undefined8 *)(lVar5 + 0x188) = param_3[6];
    *(undefined8 *)(lVar5 + 0x180) = param_3[5];
    *(undefined8 *)(lVar5 + 0x178) = param_3[4];
    iVar2 = IoRateControlStateGet(lVar5,(longlong)(param_3 + 4),local_res8,&local_58);
    local_res8 = local_4c;
    if ((*(uint *)(lVar5 + 0x1c8) & 1) != 0) {
      local_res8 = local_4c | 1;
    }
  }
  if (local_60 != 0) {
    *(undefined8 *)(local_60 + 400) = param_3[3];
    *(undefined8 *)(local_60 + 0x188) = param_3[2];
    *(undefined8 *)(local_60 + 0x180) = param_3[1];
    *(undefined8 *)(local_60 + 0x178) = *param_3;
    local_64 = local_58;
    iVar1 = IoRateControlStateGet(local_60,(longlong)param_3,local_res8,&local_68);
    if (((iVar1 == 0) && ((local_res8 & 1) == 0)) &&
       (*(longlong **)(local_60 + 0x10) != (longlong *)(local_60 + 0x10))) {
      IoRateControlGetStatsWithoutStandaloneVolumes(local_60,(undefined4 *)param_3,local_48);
      iVar1 = IoRateControlStateGet(local_60,(longlong)local_48,local_res8,&local_68);
    }
    local_50 = iVar1;
    local_54 = local_68;
    local_58 = local_64;
  }
  if (param_1 == 1) {
    if (lVar5 == 0) {
      lVar5 = local_60;
      local_58 = local_54;
    }
    else {
      local_50 = iVar2;
    }
    if (local_50 == 0) {
      uVar6 = 0xb;
      lVar3 = lVar5;
      goto LAB_1c00054be;
    }
    if (local_50 != 1) {
      if (local_58 < param_4) {
        uVar6 = 0x11;
        *param_8 = local_58;
      }
      else if (local_50 - 2U < 2) {
        uVar4 = 1;
        uVar6 = 9;
      }
      goto LAB_1c00054be;
    }
  }
  else {
    lVar3 = lVar5;
    if (iVar2 != 0) {
      lVar3 = 0;
    }
    uVar6 = 0xb;
    if (iVar2 != 0) {
      uVar6 = 0;
    }
    if (local_50 == 0) {
      uVar6 = 0xb;
      lVar3 = local_60;
      goto LAB_1c00054be;
    }
    if (iVar2 == 0) goto LAB_1c00054be;
    if ((iVar2 != 1) && (local_50 != 1)) {
      if (local_54 < local_58) {
        local_58 = local_54;
      }
      if (local_58 < param_4) {
        uVar6 = 0x11;
        *param_8 = local_58;
      }
      else if (((iVar2 - 2U < 2) || (local_50 == 2)) || (local_50 == 3)) {
        uVar4 = 1;
        uVar6 = 9;
        if ((iVar2 - 2U < 2) && (local_50 - 2U < 2)) {
          lVar5 = local_60;
        }
      }
      goto LAB_1c00054be;
    }
  }
  uVar6 = 0x10;
LAB_1c00054be:
  param_6[1] = lVar3;
  *param_6 = lVar5;
  *param_7 = uVar4;
  return uVar6;
}



===== IoRateSplitAndIssueIrp @ 1c00057d0 =====

int IoRateSplitAndIssueIrp
              (longlong param_1,longlong param_2,undefined8 *param_3,uint param_4,uint param_5)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  int iVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong lVar10;
  undefined8 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  uint uVar14;
  longlong *plVar15;
  ulonglong uVar16;
  uint uVar17;
  uint uVar18;
  longlong lVar19;
  uint local_res10;
  undefined1 auStack_c8 [8];
  undefined1 auStack_c0 [24];
  undefined8 local_a8;
  uint local_98;
  longlong local_90;
  undefined8 local_88;
  longlong local_80;
  longlong local_78;
  longlong local_70 [6];
  
  uVar14 = 0;
  local_res10 = 0;
  uVar18 = 0;
  local_70[0] = 0;
  local_70[1] = 0;
  local_70[2] = 0;
  local_70[3] = 0;
  plVar8 = (longlong *)ExAllocatePool2(0x40,0x18,0x73526f69);
  puVar12 = auStack_c8;
  puVar13 = auStack_c8;
  if (plVar8 == (longlong *)0x0) {
    iVar7 = -0x3fffff66;
    goto LAB_1c0005a7b;
  }
  plVar8[1] = 1;
  *(undefined4 *)((longlong)plVar8 + 0x14) = 0;
  *plVar8 = param_2;
  *(uint *)(plVar8 + 2) = param_4;
  lVar19 = (ulonglong)*(uint *)(*(longlong *)(param_2 + 8) + 0x2c) +
           *(longlong *)(*(longlong *)(param_2 + 8) + 0x20);
  local_90 = param_3[3];
  for (; local_98 = param_4, uVar14 < 2; uVar14 = uVar14 + 1) {
    uVar17 = param_5;
    if (uVar14 == 1) {
      uVar17 = param_4;
    }
    lVar9 = IoAllocateIrp(*(char *)(*(longlong *)(param_1 + 0x10) + 0x4c) + '\x01',0);
    local_78 = (ulonglong)uVar14 * 8;
    local_70[uVar14] = lVar9;
    if (lVar9 == 0) {
LAB_1c0005a4e:
      iVar7 = -0x3fffff66;
LAB_1c0005a54:
      plVar15 = (longlong *)(ulonglong)local_res10;
      goto LAB_1c0005a5b;
    }
    local_res10 = local_res10 + 1;
    LOCK();
    *(int *)(plVar8 + 1) = (int)plVar8[1] + 1;
    UNLOCK();
    *(uint *)(lVar9 + 0x10) = *(uint *)(lVar9 + 0x10) | *(uint *)(param_2 + 0x10) & 2;
    uVar6 = IoGetIoPriorityHint(param_2);
    IoSetIoPriorityHint(lVar9,uVar6);
    *(undefined8 *)(lVar9 + 0x98) = *(undefined8 *)(param_2 + 0x98);
    *(undefined8 *)(lVar9 + 0xc0) = *(undefined8 *)(param_2 + 0xc0);
    iVar7 = IoPropagateIrpExtension(param_2,lVar9,0xffffffff);
    if (iVar7 < 0) goto LAB_1c0005a54;
    *(char *)(lVar9 + 0x43) = *(char *)(lVar9 + 0x43) + -1;
    lVar10 = *(longlong *)(lVar9 + 0xb8);
    *(undefined8 **)(lVar9 + 0xb8) = (undefined8 *)(lVar10 + -0x48);
    local_a8 = 0;
    uVar3 = param_3[1];
    *(undefined8 *)(lVar10 + -0x48) = *param_3;
    *(undefined8 *)(lVar10 + -0x40) = uVar3;
    uVar3 = param_3[3];
    *(undefined8 *)(lVar10 + -0x38) = param_3[2];
    *(undefined8 *)(lVar10 + -0x30) = uVar3;
    uVar3 = param_3[5];
    *(undefined8 *)(lVar10 + -0x28) = param_3[4];
    *(undefined8 *)(lVar10 + -0x20) = uVar3;
    uVar3 = param_3[7];
    *(undefined8 *)(lVar10 + -0x18) = param_3[6];
    *(undefined8 *)(lVar10 + -0x10) = uVar3;
    *(undefined8 *)(lVar10 + -8) = param_3[8];
    *(undefined1 *)(lVar10 + -0x45) = 0;
    *(uint *)(lVar10 + -0x40) = uVar17;
    *(longlong *)(lVar10 + -0x30) = local_90;
    puVar11 = *(undefined8 **)(lVar9 + 0xb8);
    puVar11[-9] = *puVar11;
    puVar11[-8] = puVar11[1];
    puVar11[-7] = puVar11[2];
    puVar11[-6] = puVar11[3];
    *(undefined4 *)(puVar11 + -5) = *(undefined4 *)(puVar11 + 4);
    *(undefined4 *)((longlong)puVar11 + -0x24) = *(undefined4 *)((longlong)puVar11 + 0x24);
    *(undefined4 *)(puVar11 + -4) = *(undefined4 *)(puVar11 + 5);
    *(undefined4 *)((longlong)puVar11 + -0x1c) = *(undefined4 *)((longlong)puVar11 + 0x2c);
    puVar11[-3] = puVar11[6];
    *(undefined1 *)((longlong)puVar11 + -0x45) = 0;
    lVar10 = *(longlong *)(lVar9 + 0xb8);
    *(code **)(lVar10 + -0x10) = IoRateSplitContextCompletion;
    *(longlong **)(lVar10 + -8) = plVar8;
    *(undefined1 *)(lVar10 + -0x45) = 0xe0;
    lVar10 = IoAllocateMdl(lVar19,uVar17,0,0);
    *(longlong *)((longlong)local_70 + local_78 + 0x10) = lVar10;
    if (lVar10 == 0) goto LAB_1c0005a4e;
    uVar18 = uVar18 + 1;
    IoBuildPartialMdl(*(undefined8 *)(param_2 + 8),lVar10,lVar19);
    param_4 = local_98 - uVar17;
    local_90 = local_90 + (ulonglong)uVar17;
    lVar19 = lVar19 + (ulonglong)uVar17;
    *(longlong *)(lVar9 + 8) = lVar10;
  }
  iVar7 = 0;
  *(undefined4 *)(param_2 + 0x30) = 0;
  local_88 = 0;
  local_80 = 0;
  IoGetStackLimits(&local_80,&local_88);
  lVar19 = local_70[0];
  if ((ulonglong)((longlong)local_70 + (-0x18 - local_80)) < 0x3000) {
    uVar16 = 1;
    plVar15 = (longlong *)(local_70[0] + 0x78);
    *(longlong **)(local_70[0] + 0x80) = plVar15;
    *plVar15 = (longlong)plVar15;
    *(undefined8 *)(local_70[0] + 0x88) = 0;
    do {
      plVar2 = *(longlong **)(local_70[0] + 0x80);
      lVar9 = local_70[uVar16];
      plVar1 = (longlong *)(lVar9 + 0x78);
      if ((longlong *)*plVar2 != plVar15) goto LAB_1c0005c10;
      *plVar1 = (longlong)plVar15;
      uVar14 = (int)uVar16 + 1;
      uVar16 = (ulonglong)uVar14;
      *(longlong **)(lVar9 + 0x80) = plVar2;
      *plVar2 = (longlong)plVar1;
      *(longlong **)(local_70[0] + 0x80) = plVar1;
      *(undefined8 *)(lVar9 + 0x88) = 0;
    } while (uVar14 < 2);
    uVar5 = ExAcquireSpinLockExclusive(&DAT_1c000d568);
    plVar1 = DAT_1c000d560;
    if ((((*(undefined8 **)(DAT_1c000d558 + 8) == &DAT_1c000d558) &&
         ((undefined8 *)*DAT_1c000d560 == &DAT_1c000d558)) &&
        (*(longlong **)(*plVar15 + 8) == plVar15)) &&
       ((longlong *)**(undefined8 **)(lVar19 + 0x80) == plVar15)) {
      *DAT_1c000d560 = (longlong)plVar15;
      DAT_1c000d560 = *(longlong **)(lVar19 + 0x80);
      **(undefined8 **)(lVar19 + 0x80) = &DAT_1c000d558;
      *(longlong **)(lVar19 + 0x80) = plVar1;
      ExReleaseSpinLockExclusive(&DAT_1c000d568,uVar5);
      KeInsertQueueDpc(&DAT_1c000d518,0,0);
      goto LAB_1c0005b10;
    }
LAB_1c0005c10:
    pcVar4 = (code *)swi(0x29);
    (*pcVar4)(3);
    puVar13 = auStack_c0;
LAB_1c0005c17:
    puVar11 = (undefined8 *)(puVar13 + 0x58);
    do {
      uVar3 = *puVar11;
      *(undefined8 *)(puVar13 + -8) = 0x1c0005c26;
      IoFreeIrp(uVar3);
      *(undefined8 *)(puVar13 + -8) = 0x1c0005c33;
      IoRateSplitContextDereference((longlong)plVar8);
      puVar11 = puVar11 + 1;
      plVar15 = (longlong *)((longlong)plVar15 + -1);
      puVar12 = puVar13;
    } while (plVar15 != (longlong *)0x0);
  }
  else {
    plVar15 = local_70;
    lVar19 = 2;
    do {
      IofCallDriver(*(undefined8 *)(param_1 + 0x10),*plVar15);
      plVar15 = plVar15 + 1;
      lVar19 = lVar19 + -1;
    } while (lVar19 != 0);
LAB_1c0005b10:
    plVar15 = (longlong *)0x0;
    uVar18 = 0;
    iVar7 = 0;
LAB_1c0005a5b:
    IoRateSplitContextDereference((longlong)plVar8);
    puVar12 = auStack_c8;
    if ((int)plVar15 != 0) goto LAB_1c0005c17;
  }
  if (uVar18 != 0) {
    puVar11 = (undefined8 *)(puVar12 + 0x68);
    uVar16 = (ulonglong)uVar18;
    do {
      uVar3 = *puVar11;
      *(undefined8 *)(puVar12 + -8) = 0x1c0005c54;
      IoFreeMdl(uVar3);
      puVar11 = puVar11 + 1;
      uVar16 = uVar16 - 1;
    } while (uVar16 != 0);
  }
  param_4 = *(uint *)(puVar12 + 0xe8);
LAB_1c0005a7b:
  *(undefined8 *)(puVar12 + -8) = 0x1c0005a90;
  IoRateLogSplitIo(param_2,param_4,*(undefined4 *)(puVar12 + 0xf0),iVar7);
  return iVar7;
}



===== IoRateReservationIoCountIncrement @ 1c0005c70 =====

void IoRateReservationIoCountIncrement(longlong param_1)

{
  undefined8 ***pppuVar1;
  int *piVar2;
  undefined8 ***pppuVar3;
  code *pcVar4;
  undefined8 ***pppuVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [24];
  undefined8 ***local_18;
  undefined8 ***local_10;
  
  LOCK();
  piVar2 = (int *)(param_1 + 0x80);
  iVar6 = *piVar2;
  *piVar2 = *piVar2 + 1;
  UNLOCK();
  if (iVar6 == 0) {
    local_10 = &local_18;
    local_18 = &local_18;
    IoRateControlEnumerateThrottledEntries
              (*(longlong *)(param_1 + 0x28),IoRateGetBlockingIosCallback,&local_18);
    puVar7 = auStack_38;
    iVar6 = 0;
    while (pppuVar5 = local_10, (undefined8 ****)local_18 != &local_18) {
      if (((undefined8 ****)*local_10 != &local_18) ||
         (pppuVar3 = (undefined8 ***)local_10[1], (undefined8 ***)*pppuVar3 != local_10)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        puVar7 = auStack_30;
        goto LAB_1c0005d25;
      }
      *pppuVar3 = &local_18;
      pppuVar1 = local_10 + -6;
      local_10[1] = local_10;
      local_10 = pppuVar3;
      *pppuVar5 = pppuVar5;
      *(uint *)((longlong)pppuVar5 + 0x4c) = *(uint *)((longlong)pppuVar5 + 0x4c) | 8;
      IoRateThrottledEntryListAdd((longlong *)pppuVar1,&DAT_1c000d308,7,0);
      iVar6 = iVar6 + 1;
    }
    if (iVar6 != 0) {
LAB_1c0005d25:
      *(undefined8 *)(puVar7 + -8) = 0x1c0005d38;
      KeInsertQueueDpc(&DAT_1c000d4d8,0,0);
    }
  }
  return;
}



===== IoRatePreventNonReservationStarvation @ 1c0005d50 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void IoRatePreventNonReservationStarvation(void)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  longlong lVar3;
  longlong *plVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  
  lVar6 = 0;
  lVar5 = 0;
  uVar2 = ExAcquireSpinLockShared(&DAT_1c000d110);
  for (puVar1 = DAT_1c000d118; (undefined8 **)puVar1 != &DAT_1c000d118;
      puVar1 = (undefined8 *)*puVar1) {
    if ((puVar1[0xf] != 0) || (puVar1[0xc] != 0)) {
      lVar6 = lVar6 + (puVar1[0x30] - puVar1[0x2b]);
      lVar5 = lVar5 + puVar1[0xc] + puVar1[0xf];
    }
  }
  ExReleaseSpinLockShared(&DAT_1c000d110,uVar2);
  lVar3 = KeQueryUnbiasedInterruptTime();
  if ((ulonglong)((lVar3 - _DAT_1c000d608) * (lVar5 + 10) * 100000) < (ulonglong)(lVar6 * 10000000))
  {
    uVar2 = ExAcquireSpinLockExclusive(&DAT_1c000d160);
    for (plVar7 = DAT_1c000d2e0; plVar4 = (longlong *)0x0, (longlong **)plVar7 != &DAT_1c000d2e0;
        plVar7 = (longlong *)*plVar7) {
      if ((int)plVar7[0x11] == 0xc) {
        IoRateThrottledEntryListRemove(plVar7,&DAT_1c000d138,1);
        plVar4 = plVar7;
        break;
      }
    }
    ExReleaseSpinLockExclusive(&DAT_1c000d160,uVar2);
    if (plVar4 != (longlong *)0x0) {
      IoRateOutstandingCountIncrement(plVar4[8],plVar4[0xb],1);
      *(uint *)((longlong)plVar4 + 0x7c) = *(uint *)((longlong)plVar4 + 0x7c) | 1;
      IoRateThrottledEntryListAdd(plVar4,&DAT_1c000d308,7,0);
      KeInsertQueueDpc(&DAT_1c000d4d8,0,0);
    }
  }
  return;
}



===== IoRateLogUnblockIo @ 1c0005ef0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IoRateLogUnblockIo(longlong param_1,longlong param_2,undefined4 param_3)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined1 auStack_118 [48];
  undefined4 local_e8;
  undefined1 *local_e0;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  longlong local_c8;
  longlong local_c0;
  longlong local_b8 [2];
  undefined1 local_a8 [32];
  longlong *local_88;
  undefined8 local_80;
  longlong *local_78;
  undefined8 local_70;
  undefined4 *local_68;
  undefined8 local_60;
  undefined4 *local_58;
  undefined8 local_50;
  longlong *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_118;
  if (4 < DAT_1c000d000) {
    uVar1 = _tlgKeywordOn(param_1,2);
    if ((char)uVar1 != '\0') {
      local_88 = &local_c8;
      lVar2 = *(longlong *)(param_1 + 0x98);
      local_78 = &local_c0;
      local_80 = 8;
      local_70 = 8;
      local_c8 = param_1;
      local_c0 = lVar2;
      if (lVar2 == 0) {
        local_d8 = 0;
      }
      else {
        local_d8 = PsGetThreadId();
      }
      local_68 = &local_d8;
      local_d4 = *(undefined4 *)(param_2 + 0x10);
      local_58 = &local_d4;
      local_60 = 4;
      local_50 = 4;
      local_b8[0] = KeQueryUnbiasedInterruptTime();
      local_40 = 8;
      local_b8[0] = local_b8[0] - *(longlong *)(param_2 + 0x18);
      local_48 = local_b8;
      local_d0 = *(undefined4 *)(param_2 + 0x20);
      local_38 = &local_d0;
      local_28 = &local_cc;
      local_e0 = local_a8;
      local_e8 = 9;
      local_30 = 4;
      local_20 = 4;
      local_cc = param_3;
      _tlgWriteEx_EtwWriteEx(lVar2,&DAT_1c000ab0f);
    }
  }
  return;
}



===== IoRateControlStateGet @ 1c0006060 =====

/* WARNING: Removing unreachable block (ram,0x0001c0006198) */
/* WARNING: Removing unreachable block (ram,0x0001c00060d1) */
/* WARNING: Removing unreachable block (ram,0x0001c0006121) */

undefined4 IoRateControlStateGet(longlong param_1,longlong param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  ulonglong uVar2;
  longlong *plVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  
  uVar1 = param_3 & 2;
  uVar4 = (ulonglong)param_3;
  plVar3 = (longlong *)(param_1 + 0x38 + (ulonglong)uVar1 * 8);
  for (; (int)uVar1 < 3; uVar1 = uVar1 + 1) {
    if ((*plVar3 != 0) &&
       (uVar2 = IoRateIsRateAmountDepleted(param_1,uVar1,param_2,(byte)uVar4), (int)uVar2 != 0)) {
      uVar5 = 0;
      goto LAB_1c000618b;
    }
    plVar3 = plVar3 + 1;
  }
  if ((uVar4 & 8) == 0) {
    uVar1 = (uint)uVar4 & 2 | 9;
    plVar3 = (longlong *)(param_1 + 0x38 + (ulonglong)uVar1 * 8);
    for (; (int)uVar1 < 0xc; uVar1 = uVar1 + 1) {
      if ((*plVar3 != 0) &&
         (uVar2 = IoRateIsRateAmountDepleted(param_1,uVar1,param_2,(byte)uVar4), (int)uVar2 != 0)) {
        uVar5 = 1;
        goto LAB_1c000618b;
      }
      plVar3 = plVar3 + 1;
    }
    plVar3 = (longlong *)(param_1 + 0x68);
    for (uVar1 = 6; (int)uVar1 < 9; uVar1 = uVar1 + 1) {
      if ((*plVar3 != 0) &&
         (uVar2 = IoRateIsRateAmountDepleted(param_1,uVar1,param_2,(byte)uVar4), (int)uVar2 == 0)) {
        uVar5 = 2;
        goto LAB_1c000618b;
      }
      plVar3 = plVar3 + 1;
    }
    plVar3 = (longlong *)(param_1 + 0x50);
    for (uVar1 = 3; (int)uVar1 < 6; uVar1 = uVar1 + 1) {
      if ((*plVar3 != 0) &&
         (uVar2 = IoRateIsRateAmountDepleted(param_1,uVar1,param_2,(byte)uVar4), (int)uVar2 == 0)) {
        uVar5 = 3;
        goto LAB_1c000618b;
      }
      plVar3 = plVar3 + 1;
    }
  }
  uVar5 = 4;
LAB_1c000618b:
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0xffffffff;
  }
  return uVar5;
}



===== IoRateIsRateAmountDepleted @ 1c0006250 =====

ulonglong IoRateIsRateAmountDepleted(longlong param_1,uint param_2,longlong param_3,byte param_4)

{
  code *pcVar1;
  undefined1 auVar2 [16];
  undefined1 auVar3 [16];
  ulonglong uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined1 *puVar8;
  ulonglong uVar9;
  longlong lVar10;
  bool bVar11;
  longlong local_res8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar8 = auStack_28;
  uVar9 = 0;
  local_res8 = 0;
  lVar10 = 0;
  uVar6 = *(ulonglong *)(param_1 + 0x38 + (longlong)(int)param_2 * 8);
  if ((param_4 & 1) != 0) {
    uVar4 = *(longlong *)(param_1 + 0xb0 + (longlong)(int)param_2 * 8) + uVar6;
    bVar11 = uVar6 <= uVar4;
    uVar6 = 0xffffffffffffffff;
    if (bVar11) {
      uVar6 = uVar4;
    }
  }
  if ((param_4 & 4) != 0) {
    if (param_2 == 0) {
      lVar7 = *(longlong *)(param_1 + 0x98);
    }
    else if (param_2 == 1) {
      lVar7 = *(longlong *)(param_1 + 0xa0);
    }
    else if (param_2 == 2) {
      lVar7 = *(longlong *)(param_1 + 0xa8);
    }
    else {
      lVar7 = 0;
    }
    uVar4 = lVar7 + uVar6;
    bVar11 = uVar6 <= uVar4;
    uVar6 = 0xffffffffffffffff;
    if (bVar11) {
      uVar6 = uVar4;
    }
  }
  if ((param_2 < 0xc) && ((0x924U >> (param_2 & 0x1f) & 1) != 0)) {
    lVar10 = 0xffffffff;
    uVar4 = 0;
    if (*(ulonglong *)(param_1 + 0x158) <= *(ulonglong *)(param_3 + 8)) {
      uVar4 = *(ulonglong *)(param_3 + 8) - *(ulonglong *)(param_1 + 0x158);
    }
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar6;
    uVar6 = 1000000000;
    if (SUB168(ZEXT816(10000000) * auVar2,8) == 0) {
      uVar6 = SUB168(ZEXT816(10000000) * auVar2,0);
    }
    auVar3._8_8_ = 0;
    auVar3._0_8_ = uVar6;
    lVar7 = SUB168(ZEXT816(0x47ae147ae147ae15) * auVar3,8);
    if ((uVar6 - lVar7 >> 1) + lVar7 >> 6 <= uVar4) {
      uVar9 = 1;
      puVar8 = auStack_28;
      goto LAB_1c00062ff;
    }
  }
  else if ((param_2 < 10) && ((0x249U >> (param_2 & 0x1f) & 1) != 0)) {
    uVar4 = 0;
    if (*(ulonglong *)(param_1 + 0x168) <= *(ulonglong *)(param_3 + 0x18)) {
      uVar4 = *(ulonglong *)(param_3 + 0x18) - *(ulonglong *)(param_1 + 0x168);
    }
    if (uVar6 <= uVar4) {
      uVar9 = 1;
      puVar8 = auStack_28;
      goto LAB_1c00062ff;
    }
    uVar5 = RtlULongLongMult(uVar6 - uVar4,(ulonglong)DAT_1c000d694,&local_res8);
    if ((int)uVar5 < 0) {
      lVar10 = 0xffffffff;
    }
    else {
      lVar10 = local_res8;
    }
  }
  else if ((param_2 < 0xb) && ((0x492U >> (param_2 & 0x1f) & 1) != 0)) {
    uVar4 = 0;
    if (*(ulonglong *)(param_1 + 0x160) <= *(ulonglong *)(param_3 + 0x10)) {
      uVar4 = *(ulonglong *)(param_3 + 0x10) - *(ulonglong *)(param_1 + 0x160);
    }
    if (uVar6 <= uVar4) {
      uVar9 = 1;
      goto LAB_1c00062ff;
    }
    lVar10 = uVar6 - uVar4;
  }
  puVar8 = auStack_28;
  if (lVar10 == 0) {
    pcVar1 = (code *)swi(0x2c);
    (*pcVar1)();
    puVar8 = auStack_20;
  }
LAB_1c00062ff:
  if (*(longlong **)(puVar8 + 0x50) != (longlong *)0x0) {
    **(longlong **)(puVar8 + 0x50) = lVar10;
  }
  return uVar9 & 0xffffffff;
}



===== IoRateControlEnumerateThrottledEntries @ 1c0006450 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IoRateControlEnumerateThrottledEntries(longlong param_1,undefined *param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined1 uVar3;
  
  uVar3 = ExAcquireSpinLockExclusive(param_1 + 0x28);
  puVar2 = *(undefined8 **)(param_1 + 0x1a8);
  while (puVar2 != (undefined8 *)(param_1 + 0x1a8)) {
    puVar1 = (undefined8 *)*puVar2;
    (*(code *)param_2)(param_1,puVar2,param_3);
    puVar2 = puVar1;
  }
  ExReleaseSpinLockExclusive(param_1 + 0x28,uVar3);
  return;
}



===== IoRateLogSplitIo @ 1c0006500 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IoRateLogSplitIo(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 auStack_d8 [48];
  undefined4 local_a8;
  undefined1 *local_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90 [2];
  undefined8 local_88 [2];
  undefined1 local_78 [32];
  undefined8 *local_58;
  undefined8 local_50;
  undefined4 *local_48;
  undefined8 local_40;
  undefined4 *local_38;
  undefined8 local_30;
  undefined4 *local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_d8;
  if (4 < DAT_1c000d000) {
    uVar2 = 4;
    uVar1 = _tlgKeywordOn(param_1,4);
    if ((char)uVar1 != '\0') {
      local_58 = local_88;
      local_48 = &local_98;
      local_38 = &local_94;
      local_28 = local_90;
      local_a0 = local_78;
      local_a8 = 6;
      local_50 = 8;
      local_98 = param_2;
      local_94 = param_3;
      local_90[0] = param_4;
      local_88[0] = param_1;
      local_40 = uVar2;
      local_30 = uVar2;
      local_20 = uVar2;
      _tlgWriteEx_EtwWriteEx(param_1,&DAT_1c000ae4b);
    }
  }
  return;
}



===== IoRateSplitContextCompletion @ 1c00065f0 =====

undefined8 IoRateSplitContextCompletion(undefined8 param_1,longlong param_2,longlong *param_3)

{
  int *piVar1;
  uint uVar2;
  longlong lVar3;
  code *pcVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  int iVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  longlong local_res10;
  undefined8 local_18 [2];
  
  iVar7 = *(int *)(param_2 + 0x30);
  if (iVar7 < 0) {
    IoSetMasterIrpStatus(*param_3);
    iVar7 = *(int *)(param_2 + 0x30);
  }
  uVar2 = *(uint *)(*(longlong *)(param_2 + 0xb8) + 8);
  if ((-1 < iVar7) && (*(ulonglong *)(param_2 + 0x38) != (ulonglong)uVar2)) {
    LOCK();
    *(uint *)((longlong)param_3 + 0x14) = *(uint *)((longlong)param_3 + 0x14) | 1;
    UNLOCK();
  }
  IoFreeMdl(*(undefined8 *)(param_2 + 8));
  IoFreeIrp(param_2);
  LOCK();
  piVar1 = (int *)((longlong)param_3 + 0xc);
  iVar7 = *piVar1;
  *piVar1 = *piVar1 + uVar2;
  UNLOCK();
  if (*(uint *)(param_3 + 2) <= iVar7 + uVar2) {
    if ((*(uint *)((longlong)param_3 + 0x14) & 1) != 0) {
      IoSetMasterIrpStatus(*param_3);
    }
    if (*(int *)(*param_3 + 0x30) < 0) {
      uVar8 = 0;
    }
    else {
      uVar8 = (ulonglong)*(uint *)(param_3 + 2);
    }
    *(ulonglong *)(*param_3 + 0x38) = uVar8;
    lVar3 = *param_3;
    local_18[0] = 0;
    local_res10 = 0;
    IoGetStackLimits(&local_res10,local_18);
    if ((ulonglong)((longlong)local_18 - local_res10) < 0x3000) {
      *(undefined8 *)(lVar3 + 0x88) = 1;
      uVar5 = ExAcquireSpinLockExclusive(&DAT_1c000d568);
      puVar9 = (undefined8 *)(lVar3 + 0x78);
      if ((undefined8 *)*DAT_1c000d560 != &DAT_1c000d558) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        pcVar4 = (code *)swi(3);
        uVar6 = (*pcVar4)();
        return uVar6;
      }
      *puVar9 = &DAT_1c000d558;
      *(undefined8 **)(lVar3 + 0x80) = DAT_1c000d560;
      *DAT_1c000d560 = puVar9;
      DAT_1c000d560 = puVar9;
      ExReleaseSpinLockExclusive(&DAT_1c000d568,uVar5);
      KeInsertQueueDpc(&DAT_1c000d518,0,0);
    }
    else {
      IofCompleteRequest(lVar3,0);
    }
  }
  IoRateSplitContextDereference((longlong)param_3);
  return 0xc0000016;
}



===== IoRateSplitContextDereference @ 1c00067b0 =====

void IoRateSplitContextDereference(longlong param_1)

{
  int *piVar1;
  int iVar2;
  
  LOCK();
  piVar1 = (int *)(param_1 + 8);
  iVar2 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar2 == 1) {
    ExFreePoolWithTag(param_1,0);
  }
  return;
}



===== IoRateOutstandingCountIncrement @ 1c00067e0 =====

undefined4 IoRateOutstandingCountIncrement(longlong param_1,ulonglong param_2,int param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x84) == -1) || ((param_2 & 2) != 0)) {
    return 1;
  }
  uVar1 = ExAcquireSpinLockExclusive(*(longlong *)(param_1 + 0x28) + 0x28);
  if ((*(uint *)(param_1 + 0x88) < *(uint *)(param_1 + 0x84)) || (param_3 != 0)) {
    uVar2 = 1;
    *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) + 1;
  }
  else {
    uVar2 = 0;
  }
  ExReleaseSpinLockExclusive(*(longlong *)(param_1 + 0x28) + 0x28,uVar1);
  return uVar2;
}



===== IoRateExemptionCtxAdd @ 1c0006870 =====

undefined8 IoRateExemptionCtxAdd(longlong *param_1,ulonglong param_2)

{
  undefined1 uVar1;
  undefined8 *puVar2;
  ulonglong uVar3;
  longlong *plVar4;
  longlong *plVar5;
  undefined8 uVar6;
  
  puVar2 = (undefined8 *)ExAllocatePool2(0x40,0x20,0x65526f69);
  if (puVar2 == (undefined8 *)0x0) {
    return 0xc000009a;
  }
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = param_2;
  uVar1 = ExAcquireSpinLockExclusive(param_1 + 2);
  plVar5 = (longlong *)*param_1;
  uVar6 = 0;
  if (plVar5 != (longlong *)0x0) {
    do {
      uVar3 = IoRateExemptionCtxTreeCompare(param_2,(longlong)plVar5);
      if ((int)uVar3 < 1) {
        if (-1 < (int)uVar3) {
          ExReleaseSpinLockExclusive(param_1 + 2,uVar1);
          ExFreePoolWithTag(puVar2,0);
          return 0;
        }
        plVar4 = (longlong *)*plVar5;
        if (plVar4 == (longlong *)0x0) {
          uVar6 = 0;
          break;
        }
      }
      else {
        plVar4 = (longlong *)plVar5[1];
        if (plVar4 == (longlong *)0x0) goto LAB_1c0006901;
      }
      plVar5 = plVar4;
    } while( true );
  }
LAB_1c0006904:
  RtlRbInsertNodeEx(param_1,plVar5,uVar6,puVar2);
  ExReleaseSpinLockExclusive(param_1 + 2,uVar1);
  return 0;
LAB_1c0006901:
  uVar6 = 1;
  goto LAB_1c0006904;
}



===== IoRateExemptionCtxTreeCompare @ 1c00069a0 =====

ulonglong IoRateExemptionCtxTreeCompare(ulonglong param_1,longlong param_2)

{
  if (param_1 < *(ulonglong *)(param_2 + 0x18)) {
    return 0xffffffff;
  }
  return (ulonglong)(*(ulonglong *)(param_2 + 0x18) < param_1);
}



===== IoRateExemptionCtxRemove @ 1c00069d0 =====

void IoRateExemptionCtxRemove(ulonglong *param_1,ulonglong param_2)

{
  ulonglong uVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  
  uVar2 = ExAcquireSpinLockExclusive(param_1 + 2);
  uVar1 = param_1[1];
  puVar5 = (undefined8 *)*param_1;
  if ((uVar1 & 1) != 0) {
    if (puVar5 == (undefined8 *)0x0) goto LAB_1c0006a3a;
    puVar5 = (undefined8 *)((ulonglong)puVar5 ^ (ulonglong)param_1);
  }
  if (puVar5 != (undefined8 *)0x0) {
    do {
      if (param_2 < (ulonglong)puVar5[3]) {
        puVar3 = (undefined8 *)*puVar5;
        puVar4 = puVar3;
        if ((uVar1 & 1) != 0) goto LAB_1c0006a74;
      }
      else {
        if (param_2 <= (ulonglong)puVar5[3]) break;
        puVar3 = (undefined8 *)puVar5[1];
        puVar4 = puVar3;
        if ((uVar1 & 1) != 0) {
LAB_1c0006a74:
          puVar4 = (undefined8 *)0x0;
          if (puVar3 != (undefined8 *)0x0) {
            puVar4 = (undefined8 *)((ulonglong)puVar5 ^ (ulonglong)puVar3);
          }
        }
      }
      puVar5 = puVar4;
    } while (puVar4 != (undefined8 *)0x0);
    if (puVar5 != (undefined8 *)0x0) {
      RtlRbRemoveNode(param_1,puVar5);
      ExReleaseSpinLockExclusive(param_1 + 2,uVar2);
      ExFreePoolWithTag(puVar5,0);
      return;
    }
  }
LAB_1c0006a3a:
  ExReleaseSpinLockExclusive(param_1 + 2,uVar2);
  return;
}



===== RtlULongLongMult @ 1c0006ad0 =====

undefined8 RtlULongLongMult(ulonglong param_1,ulonglong param_2,undefined8 *param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_2;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = param_1;
  if (SUB168(auVar1 * auVar2,8) == 0) {
    *param_3 = SUB168(auVar1 * auVar2,0);
    return 0;
  }
  *param_3 = 0xffffffffffffffff;
  return 0xc0000095;
}



===== IoRateDpcProcessRoutine @ 1c0006b00 =====

void IoRateDpcProcessRoutine(void)

{
  longlong ***ppplVar1;
  uint uVar2;
  longlong ***ppplVar3;
  code *pcVar4;
  uint uVar5;
  uint uVar6;
  longlong ***local_18;
  longlong ***local_10;
  
  do {
    local_10 = (longlong ***)&local_18;
    local_18 = (longlong ***)&local_18;
    IoRateProcessingListGet((undefined8 *)&DAT_1c000d4b0,&DAT_1c000d330,0,(longlong)&local_18);
    if ((longlong ****)local_18 == &local_18) {
      return;
    }
    while ((longlong ****)local_18 != &local_18) {
      if (((longlong ****)local_18[1] != &local_18) ||
         (ppplVar3 = (longlong ***)*local_18, (longlong ***)ppplVar3[1] != local_18)) {
        pcVar4 = (code *)swi(0x29);
        (*pcVar4)(3);
        return;
      }
      ppplVar3[1] = (longlong **)&local_18;
      ppplVar1 = local_18 + -6;
      local_18[1] = (longlong **)local_18;
      *local_18 = (longlong **)local_18;
      uVar2 = *(uint *)((longlong)local_18 + 0x4c);
      uVar6 = uVar2 >> 1 & 1;
      uVar5 = uVar6 | 8;
      if ((uVar2 & 8) == 0) {
        uVar5 = uVar6;
      }
      local_18 = ppplVar3;
      IoRateThrottledEntryUnthrottle((longlong)ppplVar1,~uVar2 & 1,uVar5,7);
    }
  } while( true );
}



===== IoRateDeviceExtensionCleanup @ 1c0006bc0 =====

void IoRateDeviceExtensionCleanup(longlong *param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  
  ExWaitForRundownProtectionReleaseCacheAware(param_1[0xf]);
  uVar4 = ExAcquireSpinLockExclusive(&DAT_1c000d0f0);
  plVar1 = (longlong *)*param_1;
  if (plVar1 != param_1) {
    if (((longlong *)plVar1[1] != param_1) ||
       (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 != param_1)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    *plVar2 = (longlong)plVar1;
    plVar1[1] = (longlong)plVar2;
    param_1[1] = (longlong)param_1;
    *param_1 = (longlong)param_1;
  }
  ExReleaseSpinLockExclusive(&DAT_1c000d0f0,uVar4);
  KeFlushQueuedDpcs();
  if (param_1[3] != 0) {
    IoDetachDevice();
  }
  if (param_1[2] != 0) {
    IoDeleteDevice();
  }
  if (param_1[5] != 0) {
    IoRateControlDereference(param_1[5]);
  }
  if (param_1[6] != 0) {
    IoRateControlDereference(param_1[6]);
  }
  return;
}



===== IoRateUpdateRateControlListGeneration @ 1c0006ca0 =====

void IoRateUpdateRateControlListGeneration(void)

{
  DAT_1c000d128 = DAT_1c000d128 + 1;
  if (DAT_1c000d128 == 0) {
    DAT_1c000d128 = 1;
    return;
  }
  return;
}



===== IoRateCallDriverSync @ 1c0006cc0 =====

ulonglong IoRateCallDriverSync
                    (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
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
  KeInitializeEvent(local_38 + 2,1,0);
  lVar1 = IoBuildDeviceIoControlRequest
                    (0x2d1400,param_1,param_3,0xc,param_5,param_6,0,local_38 + 2,local_38);
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



===== IoRateDeviceStartCompletion @ 1c0006db0 =====

undefined8
IoRateDeviceStartCompletion(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  byte *pbVar1;
  longlong lVar2;
  undefined8 uVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  if (*(char *)(param_2 + 0x41) != '\0') {
    pbVar1 = (byte *)(*(longlong *)(param_2 + 0xb8) + 3);
    *pbVar1 = *pbVar1 | 1;
  }
  if (*(int *)(lVar2 + 0x84) != -1) {
    IoRateDeviceExtensionUpdateMaxIoCount(lVar2,param_2,param_3,param_4);
  }
  uVar3 = IoRateDeviceExtensionIsVirtualDevice(lVar2,param_2,param_3,param_4);
  if ((int)uVar3 != 0) {
    LOCK();
    *(uint *)(lVar2 + 0xa0) = *(uint *)(lVar2 + 0xa0) | 1;
    UNLOCK();
  }
  return 0;
}



===== IoRateGetBlockingIosCallback @ 1c0006e00 =====

void IoRateGetBlockingIosCallback(undefined *param_1,longlong *param_2,longlong param_3)

{
  code *pcVar1;
  longlong *plVar2;
  longlong *plVar3;
  
  if (*(int *)((longlong)param_2 + 0x84) == 0) {
    IoRateThrottledEntryListRemove(param_2,param_1,1);
    plVar2 = *(longlong **)(param_3 + 8);
    plVar3 = param_2 + 6;
    if (*plVar2 != param_3) {
      pcVar1 = (code *)swi(0x29);
      plVar2 = (longlong *)(*pcVar1)(3);
    }
    *plVar3 = param_3;
    param_2[7] = (longlong)plVar2;
    *plVar2 = (longlong)plVar3;
    *(longlong **)(param_3 + 8) = plVar3;
  }
  return;
}



===== IoRateDeviceExtensionStart @ 1c0006e60 =====

undefined8 IoRateDeviceExtensionStart(undefined8 *param_1,longlong param_2,undefined8 param_3)

{
  code *pcVar1;
  undefined1 uVar2;
  longlong lVar3;
  void *pvVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined1 *puVar7;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  param_1[3] = param_3;
  param_1[2] = param_2;
  *(undefined4 *)((longlong)param_1 + 0x84) = DAT_1c000d68c;
  do {
    LOCK();
    UNLOCK();
    lVar3 = DAT_1c000d108 + 1;
    DAT_1c000d108 = DAT_1c000d108 + 1;
    param_1[4] = lVar3;
  } while (lVar3 == 0);
  pvVar4 = (void *)ExAllocatePool2(0x40,0x1d0,0x72526f69);
  param_1[5] = pvVar4;
  if (pvVar4 != (void *)0x0) {
    memset(pvVar4,0,0x1d0);
    *(void **)((longlong)pvVar4 + 8) = pvVar4;
    lVar3 = (longlong)pvVar4 + 0x1a8;
    *(void **)pvVar4 = pvVar4;
    *(longlong *)((longlong)pvVar4 + 0x1b0) = lVar3;
    *(longlong *)lVar3 = lVar3;
    lVar3 = (longlong)pvVar4 + 0x10;
    *(longlong *)((longlong)pvVar4 + 0x18) = lVar3;
    *(longlong *)lVar3 = lVar3;
    *(undefined8 *)((longlong)pvVar4 + 0x30) = 1;
    pvVar4 = (void *)ExAllocatePool2(0x40,0x1d0,0x72526f69);
    param_1[6] = pvVar4;
    if (pvVar4 != (void *)0x0) {
      memset(pvVar4,0,0x1d0);
      *(void **)((longlong)pvVar4 + 8) = pvVar4;
      lVar3 = (longlong)pvVar4 + 0x1a8;
      *(void **)pvVar4 = pvVar4;
      *(longlong *)((longlong)pvVar4 + 0x1b0) = lVar3;
      *(longlong *)lVar3 = lVar3;
      lVar3 = (longlong)pvVar4 + 0x10;
      *(longlong *)((longlong)pvVar4 + 0x18) = lVar3;
      *(longlong *)lVar3 = lVar3;
      *(undefined8 *)((longlong)pvVar4 + 0x30) = 1;
      uVar2 = ExAcquireSpinLockExclusive(&DAT_1c000d0f0);
      puVar7 = auStack_28;
      puVar6 = &DAT_1c000d0f8;
      puVar5 = DAT_1c000d100;
      if ((undefined8 *)*DAT_1c000d100 != &DAT_1c000d0f8) {
        puVar5 = (undefined8 *)0x3;
        pcVar1 = (code *)swi(0x29);
        uVar2 = (*pcVar1)();
        puVar7 = auStack_20;
      }
      *param_1 = puVar6;
      param_1[1] = puVar5;
      *puVar5 = param_1;
      *(undefined8 *)(puVar7 + -8) = 0x1c0006fcd;
      DAT_1c000d100 = param_1;
      ExReleaseSpinLockExclusive(&DAT_1c000d0f0,uVar2);
      *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) & 0xffffff7f;
      return 0;
    }
  }
  return 0xc0000017;
}



===== IoRateDeviceExtensionIsVirtualDevice @ 1c0007000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
IoRateDeviceExtensionIsVirtualDevice
          (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 auStackY_78 [32];
  undefined4 local_48;
  undefined8 local_44;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_78;
  local_44 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 1;
  local_28 = 0;
  uStack_20 = 0;
  uVar1 = IoRateCallDriverSync
                    (*(undefined8 *)(param_1 + 0x18),param_2,&local_48,param_4,&local_38,0x20);
  if (((int)uVar1 < 0) || (uVar2 = 1, (char)uStack_20 != '\x0f')) {
    uVar2 = 0;
  }
  return uVar2;
}



===== __report_gsfailure @ 1c0007090 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== IoRateCleanupGlobalData @ 1c00070a0 =====

void IoRateCleanupGlobalData(void)

{
  undefined1 uVar1;
  
  if (DAT_1c000d0c8 != 0) {
    ExUnregisterExtension();
  }
  uVar1 = ExAcquireSpinLockExclusive(&DAT_1c000d110);
  DAT_1c000d12c = DAT_1c000d12c | 1;
  KeCancelTimer(&DAT_1c000d588);
  ExReleaseSpinLockExclusive(&DAT_1c000d110,uVar1);
  KeFlushQueuedDpcs();
  IoRateExemptionCtxCleanup(&DAT_1c000d610);
  ExDeleteLookasideListEx(&DAT_1c000d6b0);
  ExDeleteLookasideListEx(&DAT_1c000d710);
  return;
}



===== IoRateControlAddStandaloneVolumeControl @ 1c0007150 =====

void IoRateControlAddStandaloneVolumeControl(longlong param_1,longlong param_2)

{
  code *pcVar1;
  undefined1 uVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  longlong lVar7;
  longlong lVar8;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  if (*(longlong *)(param_2 + 0x20) == 0) {
    uVar2 = ExAcquireSpinLockExclusive(param_1 + 0x28);
    puVar5 = auStack_28;
    puVar6 = auStack_28;
    if (*(longlong *)(param_2 + 0x20) == 0) {
      plVar3 = (longlong *)(param_1 + 0xb0);
      lVar8 = 0xf;
      do {
        lVar7 = lVar8;
        *plVar3 = *plVar3 + *(longlong *)((param_2 - param_1) + -0x78 + (longlong)plVar3);
        plVar3 = plVar3 + 1;
        lVar8 = lVar7 + -1;
      } while (lVar8 != 0);
      lVar8 = param_1 + 0x10;
      plVar4 = *(longlong **)(param_1 + 0x18);
      plVar3 = (longlong *)(param_2 + 0x10);
      if (*plVar4 != lVar8) {
        plVar3 = (longlong *)(ulonglong)((int)lVar7 + 2);
        pcVar1 = (code *)swi(0x29);
        lVar8 = (*pcVar1)();
        puVar5 = auStack_20;
      }
      *plVar3 = lVar8;
      plVar3[1] = (longlong)plVar4;
      *plVar4 = (longlong)plVar3;
      *(longlong **)(lVar8 + 8) = plVar3;
      *(longlong *)(param_2 + 0x20) = param_1;
      puVar6 = puVar5;
    }
    *(undefined8 *)(puVar6 + -8) = 0x1c00071e6;
    ExReleaseSpinLockExclusive(param_1 + 0x28,uVar2);
  }
  return;
}



===== IoRateControlGetStatsWithoutStandaloneVolumes @ 1c0007204 =====

void IoRateControlGetStatsWithoutStandaloneVolumes
               (longlong param_1,undefined4 *param_2,ulonglong *param_3)

{
  ulonglong *puVar1;
  ulonglong *puVar2;
  ulonglong *puVar3;
  ulonglong *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined1 uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  longlong *plVar15;
  ulonglong uVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  ulonglong uVar20;
  longlong *plVar21;
  ulonglong uVar22;
  
  uVar5 = param_2[1];
  uVar6 = param_2[2];
  uVar7 = param_2[3];
  uVar8 = param_2[4];
  uVar9 = param_2[5];
  uVar10 = param_2[6];
  uVar11 = param_2[7];
  *(undefined4 *)param_3 = *param_2;
  *(undefined4 *)((longlong)param_3 + 4) = uVar5;
  *(undefined4 *)(param_3 + 1) = uVar6;
  *(undefined4 *)((longlong)param_3 + 0xc) = uVar7;
  *(undefined4 *)(param_3 + 2) = uVar8;
  *(undefined4 *)((longlong)param_3 + 0x14) = uVar9;
  *(undefined4 *)(param_3 + 3) = uVar10;
  *(undefined4 *)((longlong)param_3 + 0x1c) = uVar11;
  uVar12 = ExAcquireSpinLockShared(param_1 + 0x28);
  plVar15 = (longlong *)(param_1 + 0x10);
  plVar21 = (longlong *)*plVar15;
  if (plVar21 != plVar15) {
    uVar16 = param_3[3];
    uVar22 = param_3[1];
    uVar19 = *param_3;
    uVar20 = param_3[2];
    do {
      puVar1 = (ulonglong *)(plVar21 + 0x2f);
      puVar2 = (ulonglong *)(plVar21 + 0x2d);
      uVar18 = -(ulonglong)((ulonglong)plVar21[0x2b] < (ulonglong)plVar21[0x30]) &
               plVar21[0x30] - plVar21[0x2b];
      puVar3 = (ulonglong *)(plVar21 + 0x28);
      uVar17 = -(ulonglong)((ulonglong)plVar21[0x29] < (ulonglong)plVar21[0x2e]) &
               plVar21[0x2e] - plVar21[0x29];
      puVar4 = (ulonglong *)(plVar21 + 0x2a);
      plVar21 = (longlong *)*plVar21;
      uVar14 = -(ulonglong)(*puVar3 < *puVar2) & *puVar2 - *puVar3;
      uVar13 = -(ulonglong)(*puVar4 < *puVar1) & *puVar1 - *puVar4;
      uVar16 = -(ulonglong)(uVar18 < uVar16) & uVar16 - uVar18;
      uVar22 = -(ulonglong)(uVar17 < uVar22) & uVar22 - uVar17;
      uVar19 = -(ulonglong)(uVar14 < uVar19) & uVar19 - uVar14;
      uVar20 = -(ulonglong)(uVar13 < uVar20) & uVar20 - uVar13;
    } while (plVar21 != plVar15);
    param_3[3] = uVar16;
    param_3[1] = uVar22;
    *param_3 = uVar19;
    param_3[2] = uVar20;
  }
  ExReleaseSpinLockShared(param_1 + 0x28,uVar12);
  return;
}



===== IoRateControlRemoveStandaloneVolumeControl @ 1c0007370 =====

void IoRateControlRemoveStandaloneVolumeControl(longlong param_1,int param_2)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  longlong *plVar5;
  longlong lVar6;
  
  lVar1 = *(longlong *)(param_1 + 0x20);
  uVar4 = 0;
  if (lVar1 != 0) {
    if (param_2 == 0) {
      uVar4 = ExAcquireSpinLockExclusive(lVar1 + 0x28,0);
    }
    plVar5 = (longlong *)(param_1 + 0x10);
    lVar6 = *plVar5;
    if ((*(longlong **)(lVar6 + 8) != plVar5) ||
       (plVar2 = *(longlong **)(param_1 + 0x18), (longlong *)*plVar2 != plVar5)) {
      pcVar3 = (code *)swi(0x29);
      (*pcVar3)(3,uVar4);
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    *plVar2 = lVar6;
    *(longlong **)(lVar6 + 8) = plVar2;
    lVar6 = 0xf;
    *(longlong **)(param_1 + 0x18) = plVar5;
    *plVar5 = (longlong)plVar5;
    plVar5 = (longlong *)(lVar1 + 0xb0);
    *(undefined8 *)(param_1 + 0x20) = 0;
    do {
      *plVar5 = *plVar5 - *(longlong *)((param_1 - lVar1) + -0x78 + (longlong)plVar5);
      plVar5 = plVar5 + 1;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    if ((param_2 == 0) || (param_2 == 0)) {
      ExReleaseSpinLockExclusive(lVar1 + 0x28);
    }
  }
  return;
}



===== IoRateDeviceExtensionGetEntriesCallback @ 1c0007440 =====

void IoRateDeviceExtensionGetEntriesCallback(undefined *param_1,longlong *param_2,longlong *param_3)

{
  longlong lVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong *plVar4;
  
  lVar1 = param_3[1];
  if (param_2[8] == *param_3) {
    IoRateThrottledEntryListRemove(param_2,param_1,1);
    plVar4 = *(longlong **)(lVar1 + 8);
    plVar3 = param_2 + 6;
    if (*plVar4 != lVar1) {
      plVar4 = (longlong *)0x3;
      pcVar2 = (code *)swi(0x29);
      plVar3 = (longlong *)(*pcVar2)();
    }
    *plVar3 = lVar1;
    plVar3[1] = (longlong)plVar4;
    *plVar4 = (longlong)plVar3;
    *(longlong **)(lVar1 + 8) = plVar3;
  }
  return;
}



===== IoRateDeviceExtensionProcessQueryRemove @ 1c00074a0 =====

void IoRateDeviceExtensionProcessQueryRemove(longlong param_1)

{
  IoRateDeviceExtensionReprocessIos(param_1,1);
  return;
}



===== IoRateDeviceExtensionReprocessIos @ 1c00074bc =====

int IoRateDeviceExtensionReprocessIos(longlong param_1,uint param_2)

{
  longlong ***ppplVar1;
  code *pcVar2;
  longlong ***ppplVar3;
  undefined8 *puVar4;
  int iVar5;
  int local_res18 [4];
  longlong ***local_48;
  longlong ***local_40;
  longlong local_38;
  longlong ***local_30;
  undefined8 local_28;
  
  iVar5 = 0;
  local_40 = (longlong ***)&local_48;
  local_28 = 0;
  local_48 = (longlong ***)&local_48;
  local_res18[0] = 0;
  local_30 = (longlong ***)&local_48;
  puVar4 = (undefined8 *)0x0;
  local_38 = param_1;
  while( true ) {
    puVar4 = IoRateControlsGetNext(puVar4,local_res18);
    if (puVar4 == (undefined8 *)0x0) break;
    IoRateControlEnumerateThrottledEntries
              ((longlong)puVar4,IoRateDeviceExtensionGetEntriesCallback,&local_38);
  }
  IoRateControlEnumerateThrottledEntries
            (0x1c000d138,IoRateDeviceExtensionGetEntriesCallback,&local_38);
  IoRateControlEnumerateThrottledEntries
            (*(longlong *)(param_1 + 0x30),IoRateDeviceExtensionGetEntriesCallback,&local_38);
  while( true ) {
    ppplVar3 = local_48;
    if ((longlong ****)local_48 == &local_48) {
      return iVar5;
    }
    if (((longlong ****)local_48[1] != &local_48) ||
       (ppplVar1 = (longlong ***)*local_48, (longlong ***)ppplVar1[1] != local_48)) break;
    ppplVar1[1] = (longlong **)&local_48;
    local_48[1] = (longlong **)local_48;
    *local_48 = (longlong **)local_48;
    local_48 = ppplVar1;
    IoRateThrottledEntryUnthrottle((longlong)(ppplVar3 + -6),1,param_2,0x12);
    iVar5 = iVar5 + 1;
  }
  pcVar2 = (code *)swi(0x29);
  (*pcVar2)(3);
  return iVar5;
}



===== IoRateDeviceExtensionUpdateMaxIoCount @ 1c00075bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IoRateDeviceExtensionUpdateMaxIoCount
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined1 auStackY_68 [32];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_68;
  local_30 = 0;
  local_34 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0x30;
  uVar2 = IoRateCallDriverSync
                    (*(undefined8 *)(param_1 + 0x18),param_2,&local_38,param_4,&local_28,0x10);
  if (-1 < (int)uVar2) {
    uVar1 = 0x20;
    if (0x20 < (uint)uStack_20) {
      uVar1 = (uint)uStack_20;
    }
    *(uint *)(param_1 + 0x84) = uVar1;
  }
  return;
}



===== IoRateExemptionCtxTreeDelete @ 1c0007640 =====

void IoRateExemptionCtxTreeDelete(undefined8 param_1)

{
  ExFreePoolWithTag(param_1,0);
  return;
}



===== IoRateLogParametersWatchFailure @ 1c0007660 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IoRateLogParametersWatchFailure(undefined8 param_1)

{
  ulonglong uVar1;
  undefined1 auStack_88 [48];
  undefined4 local_58;
  undefined1 *local_50;
  undefined4 local_48 [2];
  undefined1 local_40 [32];
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_88;
  if (4 < DAT_1c000d000) {
    uVar1 = _tlgKeywordOn(param_1,0x400000000004);
    if ((char)uVar1 != '\0') {
      local_14 = 0;
      local_20 = local_48;
      local_50 = local_40;
      local_48[0] = (undefined4)param_1;
      local_58 = 3;
      local_18 = 4;
      _tlgWriteEx_EtwWriteEx(param_1,&DAT_1c000a811);
    }
  }
  return;
}



===== IoRateParametersWatcher @ 1c00076f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void IoRateParametersWatcher(longlong *param_1)

{
  bool bVar1;
  undefined8 *puVar2;
  undefined1 auStackY_d8 [32];
  undefined1 in_stack_ffffffffffffff58;
  undefined8 ******local_98;
  undefined8 ******ppppppuStack_90;
  undefined1 local_88 [72];
  ulonglong local_40;
  ulonglong local_38 [2];
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_d8;
  local_18 = 0;
  local_98 = (undefined8 ******)0x0;
  ppppppuStack_90 = (undefined8 ******)0x0;
  local_28 = 0;
  uStack_20 = 0;
  memset(local_88,0,0x58);
  IoRateGetParameter(*param_1,L"VolumeIdleIoCount",0xb,&local_40,8,(longlong)&local_28,
                     in_stack_ffffffffffffff58);
  IoRateGetParameter(*param_1,L"VolumeIdleIoSize",0xb,local_38,8,(longlong)&local_28,
                     in_stack_ffffffffffffff58);
  IoRateFixParameters((longlong)local_88);
  bVar1 = false;
  if ((local_40 != param_1[9]) || (local_38[0] != param_1[10])) {
    if (((ulonglong)param_1[9] < local_40) || ((ulonglong)param_1[10] < local_38[0])) {
      bVar1 = true;
    }
    LOCK();
    param_1[9] = local_40;
    UNLOCK();
    LOCK();
    param_1[10] = local_38[0];
    UNLOCK();
    if (bVar1) {
      ppppppuStack_90 = &local_98;
      puVar2 = (undefined8 *)0x0;
      local_98 = &local_98;
      while (puVar2 = IoRateDeviceExtensionGetNext(puVar2), puVar2 != (undefined8 *)0x0) {
        IoRateProcessingListGet
                  ((undefined8 *)(puVar2[6] + 0x1a8),puVar2[6] + 0x28,0,(longlong)&local_98);
      }
      IoRateThrottledIosRecheck(&local_98,4);
    }
  }
  IoRateStartParametersWatch(param_1);
  return;
}



===== IoRateSplitContextDpcRoutine @ 1c0007850 =====

void IoRateSplitContextDpcRoutine(void)

{
  undefined8 *puVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  puVar5 = auStack_28;
  do {
    uVar4 = ExAcquireSpinLockExclusive(&DAT_1c000d568);
    puVar3 = DAT_1c000d558;
    if ((undefined8 **)DAT_1c000d558 == &DAT_1c000d558) {
LAB_1c00078f3:
      *(undefined8 *)(puVar5 + -8) = 0x1c0007903;
      ExReleaseSpinLockExclusive(&DAT_1c000d568,uVar4);
      return;
    }
    if (((undefined8 **)DAT_1c000d558[1] != &DAT_1c000d558) ||
       (puVar1 = (undefined8 *)*DAT_1c000d558, (undefined8 *)puVar1[1] != DAT_1c000d558)) {
      pcVar2 = (code *)swi(0x29);
      uVar4 = (*pcVar2)(3);
      puVar5 = auStack_20;
      goto LAB_1c00078f3;
    }
    DAT_1c000d558 = puVar1;
    puVar1[1] = &DAT_1c000d558;
    ExReleaseSpinLockExclusive(&DAT_1c000d568,uVar4);
    if (*(int *)(puVar3 + 2) == 0) {
      IofCallDriver(*(undefined8 *)(puVar3[8] + 0x28),puVar3 + -0xf);
    }
    else if (*(int *)(puVar3 + 2) == 1) {
      IofCompleteRequest(puVar3 + -0xf,0);
    }
  } while( true );
}



===== IoRateStartParametersWatch @ 1c000791c =====

uint IoRateStartParametersWatch(longlong *param_1)

{
  uint uVar1;
  
  if (*param_1 == 0) {
    uVar1 = 0xc0000008;
  }
  else {
    uVar1 = ZwNotifyChangeKey(*param_1,0,param_1 + 3,1,param_1 + 1,0x1000000f,0,param_1 + 7,4,1);
    if ((int)uVar1 < 0) {
      IoRateLogParametersWatchFailure((ulonglong)uVar1);
    }
  }
  return uVar1;
}



===== _tlgDefineProvider_annotation__TlgIoRateTlgProvRegHandleProv @ 1c0007994 =====

void _tlgDefineProvider_annotation__TlgIoRateTlgProvRegHandleProv(void)

{
  return;
}



===== _guard_check_icall @ 1c00079b0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c00079c8 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c00079ec =====

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



===== __cpu_features_init @ 1c0007a60 =====

/* WARNING: Removing unreachable block (ram,0x0001c0007aca) */
/* WARNING: Removing unreachable block (ram,0x0001c0007a79) */
/* WARNING: Removing unreachable block (ram,0x0001c0007a6a) */

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



===== __security_check_cookie @ 1c0007b30 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0007b70 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0007ba0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0007ba0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0007bd0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0007c40 =====

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



===== memset @ 1c0007f40 =====

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



===== __memset_repmovs @ 1c0008080 =====

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



===== __memset_query @ 1c0008100 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0008180 =====

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
    if (param_3 < &DAT_00000010) {
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



===== __memset_spec_ermsb_repmovsb @ 1c00082c0 =====

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



===== __memset_spec_plain @ 1c0008340 =====

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
    if (param_3 < &DAT_00000010) {
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



===== IoRateDeviceExtensionInitialize @ 1c0010010 =====

void IoRateDeviceExtensionInitialize(void *param_1,undefined8 param_2)

{
  memset(param_1,0,0xa8);
  *(longlong *)((longlong)param_1 + 0x78) = (longlong)param_1 + 0xa8;
  ExInitializeRundownProtectionCacheAware((longlong)param_1 + 0xa8,param_2);
  KeInitializeDpc((longlong)param_1 + 0x38,IoRateDeviceExtensionSoftCapDpcRoutine,param_1);
  *(void **)((longlong)param_1 + 8) = param_1;
  *(void **)param_1 = param_1;
  return;
}



===== IoRateDeviceExtensionReferenceByHandle @ 1c001007c =====

int IoRateDeviceExtensionReferenceByHandle(undefined8 param_1,longlong *param_2)

{
  longlong lVar1;
  char cVar2;
  int iVar3;
  longlong lVar4;
  longlong lVar5;
  longlong local_res18;
  
  local_res18 = 0;
  iVar3 = ObReferenceObjectByHandle
                    (param_1,0x80,*(undefined8 *)IoFileObjectType_exref,0,&local_res18,0);
  lVar1 = local_res18;
  if (-1 < iVar3) {
    if ((*(uint *)(local_res18 + 0x50) & 0x800) == 0) {
      iVar3 = -0x3fffff68;
    }
    else {
      lVar4 = IoGetRelatedDeviceObject(local_res18);
      ObfReferenceObject(lVar4);
      do {
        lVar5 = IoGetLowerDeviceObject(lVar4);
        ObfDereferenceObject(lVar4);
        if (lVar5 == 0) {
          iVar3 = -0x3fffffd8;
          goto LAB_1c0010177;
        }
        lVar4 = lVar5;
      } while (*(longlong *)(lVar5 + 8) != IoRateGlobals);
      lVar4 = *(longlong *)(lVar5 + 0x40);
      cVar2 = ExAcquireRundownProtectionCacheAware(*(undefined8 *)(lVar4 + 0x78));
      if (cVar2 == '\0') {
        iVar3 = -0x3fffffaa;
      }
      else {
        *param_2 = lVar4;
        iVar3 = 0;
      }
      ObfDereferenceObject(lVar5);
    }
  }
LAB_1c0010177:
  if (lVar1 != 0) {
    ObfDereferenceObject(lVar1);
  }
  return iVar3;
}



===== IoRateExemptionCtxCleanup @ 1c00101ac =====

void IoRateExemptionCtxCleanup(undefined8 *param_1)

{
  byte *pbVar1;
  byte bVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  
  if ((*(uint *)((longlong)param_1 + 0x34) & 1) != 0) {
    PsSetCreateProcessNotifyRoutineEx(IoRateProcessCreateNotify,1);
  }
  puVar3 = (undefined8 *)*param_1;
  pbVar1 = (byte *)(param_1 + 1);
  if (((*pbVar1 & 1) != 0) && (puVar3 != (undefined8 *)0x0)) {
    puVar3 = (undefined8 *)((ulonglong)puVar3 ^ (ulonglong)param_1);
  }
  bVar2 = *pbVar1;
  if (puVar3 == (undefined8 *)0x0) {
LAB_1c0010258:
    bVar2 = *pbVar1;
    *param_1 = 0;
    param_1[1] = 0;
    if ((bVar2 & 1) != 0) {
      *(undefined1 *)(param_1 + 1) = 1;
    }
    if ((undefined *)param_1[5] != &IoRateExemptionStringsDefault) {
      ExFreePoolWithTag((undefined *)param_1[5],0);
    }
    RtlFreeUnicodeString(param_1 + 3);
    return;
  }
  do {
    while (puVar4 = (undefined8 *)*puVar3, puVar4 != (undefined8 *)0x0) {
      puVar5 = puVar3;
LAB_1c001021d:
      if ((bVar2 & 1) != 0) {
        puVar4 = (undefined8 *)((ulonglong)puVar3 ^ (ulonglong)puVar4);
      }
      *puVar5 = 0;
      puVar3 = puVar4;
    }
    puVar5 = puVar3 + 1;
    puVar4 = (undefined8 *)*puVar5;
    if (puVar4 != (undefined8 *)0x0) goto LAB_1c001021d;
    puVar4 = (undefined8 *)(puVar3[2] & 0xfffffffffffffffc);
    if (((bVar2 & 1) != 0) && (puVar4 != (undefined8 *)0x0)) {
      puVar4 = (undefined8 *)((ulonglong)puVar4 ^ (ulonglong)puVar3);
    }
    IoRateExemptionCtxTreeDelete(puVar3);
    if (puVar4 == (undefined8 *)0x0) goto LAB_1c0010258;
    puVar3 = puVar4;
  } while( true );
}



===== IoRateFixParameters @ 1c00102c0 =====

void IoRateFixParameters(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x3c) == 0) {
    *(undefined4 *)(param_1 + 0x3c) = 0x20;
  }
  uVar1 = *(uint *)(param_1 + 0x44);
  if (uVar1 < 0x400000) {
    uVar3 = 0x1000;
    if (uVar1 < 0x1001) goto LAB_1c00102ee;
  }
  else {
    uVar1 = 0x400000;
  }
  uVar3 = uVar1;
LAB_1c00102ee:
  *(uint *)(param_1 + 0x44) = uVar3;
  uVar2 = 1;
  if (1 < *(ulonglong *)(param_1 + 0x48)) {
    uVar2 = *(ulonglong *)(param_1 + 0x48);
  }
  *(ulonglong *)(param_1 + 0x48) = uVar2;
  uVar2 = *(ulonglong *)(param_1 + 0x50);
  if (*(ulonglong *)(param_1 + 0x50) <= (ulonglong)uVar3) {
    uVar2 = (ulonglong)uVar3;
  }
  *(ulonglong *)(param_1 + 0x50) = uVar2;
  return;
}



===== IoRateGetParameter @ 1c0010320 =====

undefined8
IoRateGetParameter(undefined8 param_1,undefined8 param_2,int param_3,void *param_4,uint param_5,
                  longlong param_6,undefined1 param_7)

{
  undefined8 uVar1;
  undefined8 local_18;
  undefined8 uStack_10;
  
  _param_7 = 0x18;
  local_18 = 0;
  uStack_10 = 0;
  RtlInitUnicodeString(&local_18);
  uVar1 = ZwQueryValueKey(param_1,&local_18,2,param_6,_param_7,&param_7);
  if (-1 < (int)uVar1) {
    if (*(int *)(param_6 + 4) == param_3) {
      if (param_5 < *(uint *)(param_6 + 8)) {
        uVar1 = 0xc0000023;
      }
      else {
        memcpy(param_4,(void *)(param_6 + 0xc),(ulonglong)*(uint *)(param_6 + 8));
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0xc0000024;
    }
  }
  return uVar1;
}



===== IoRateGetParameters @ 1c00103e4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IoRateGetParameters(undefined8 *param_1,longlong *param_2)

{
  longlong lVar1;
  int iVar2;
  undefined1 auStackY_e8 [32];
  undefined1 in_stack_ffffffffffffff48;
  longlong local_a8;
  longlong local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_98 = 0x30;
  local_a8 = 0;
  local_48 = 0;
  *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xfffffffe;
  local_a0 = 0;
  local_90 = 0;
  *(undefined4 *)((longlong)param_2 + 0x3c) = 0x20;
  *(undefined4 *)((longlong)param_2 + 0x44) = 0x2000;
  param_2[9] = 1;
  param_2[10] = 0x2000;
  local_80 = 0x240;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = param_1;
  iVar2 = ZwOpenKey(&local_a8,0xf003f,&local_98);
  if (-1 < iVar2) {
    IoRateGetParameter(local_a8,L"MaxOutstandingIo",4,(void *)((longlong)param_2 + 0x3c),4,
                       (longlong)&local_58,in_stack_ffffffffffffff48);
    IoRateGetParameter(local_a8,L"IoRateFlags",4,param_2 + 8,4,(longlong)&local_58,
                       in_stack_ffffffffffffff48);
    IoRateGetParameter(local_a8,L"VolumeIdleIoCount",0xb,param_2 + 9,8,(longlong)&local_58,
                       in_stack_ffffffffffffff48);
    IoRateGetParameter(local_a8,L"VolumeIdleIoSize",0xb,param_2 + 10,8,(longlong)&local_58,
                       in_stack_ffffffffffffff48);
    RtlInitUnicodeString(&local_68,L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\QoS");
    local_90 = 0;
    local_88 = &local_68;
    local_98 = CONCAT44(local_98._4_4_,0x30);
    local_80 = CONCAT44(local_80._4_4_,0x240);
    local_78 = 0;
    uStack_70 = 0;
    iVar2 = ZwOpenKey(&local_a0,0xf003f,&local_98);
    if (-1 < iVar2) {
      IoRateGetParameter(local_a0,L"StorageBaseIOSize",4,(void *)((longlong)param_2 + 0x44),4,
                         (longlong)&local_58,in_stack_ffffffffffffff48);
    }
    IoRateFixParameters((longlong)param_2);
    lVar1 = local_a8;
    local_a8 = 0;
    iVar2 = 0;
    *param_2 = lVar1;
  }
  if (local_a8 != 0) {
    ZwClose();
  }
  if (local_a0 != 0) {
    ZwClose();
  }
  return iVar2;
}



===== IoRateUnload @ 1c0010620 =====

void IoRateUnload(void)

{
  undefined8 uVar1;
  
  uVar1 = DAT_1c000d020;
  DAT_1c000d020 = 0;
  DAT_1c000d000 = 0;
  EtwUnregister(uVar1);
  IoRateCleanupGlobalData();
  return;
}



===== TraceLoggingRegisterEx_EtwRegister_EtwSetInformation @ 1c0010658 =====

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
  local_28 = *(undefined4 *)(PTR_DAT_1c000d008 + -0x10);
  uStack_24 = *(undefined4 *)(PTR_DAT_1c000d008 + -0xc);
  uStack_20 = *(undefined4 *)(PTR_DAT_1c000d008 + -8);
  uStack_1c = *(undefined4 *)(PTR_DAT_1c000d008 + -4);
  if (DAT_1c000d020 != 0) {
    pcVar2 = (code *)swi(0x29);
    (*pcVar2)(5);
    puVar4 = auStack_40;
  }
  _DAT_1c000d028 = 0;
  uRam00000001c000d030 = 0;
  *(undefined8 *)(puVar4 + -8) = 0x1c00106bb;
  iVar3 = EtwRegister(puVar4 + 0x20,_tlgEnableCallback,&DAT_1c000d000,&DAT_1c000d020);
  if (iVar3 == 0) {
    uVar1 = *(undefined2 *)PTR_DAT_1c000d008;
    *(undefined8 *)(puVar4 + -8) = 0x1c00106e2;
    EtwSetInformation(DAT_1c000d020,2,PTR_DAT_1c000d008,uVar1);
  }
  *(undefined8 *)(puVar4 + -8) = 0x1c00106f6;
  return iVar3;
}



===== IoRateProcessCreateNotify @ 1c0010710 =====

void IoRateProcessCreateNotify(ulonglong param_1,undefined8 param_2,longlong param_3)

{
  int iVar1;
  
  if ((param_3 == 0) ||
     ((*(ushort **)(param_3 + 0x30) != (ushort *)0x0 &&
      (iVar1 = IoRateExemptionCtxCheckProcess
                         (&DAT_1c000d610,param_1,*(ushort **)(param_3 + 0x30),
                          *(ushort **)(param_3 + 0x38)), iVar1 == 0)))) {
    IoRateExemptionCtxRemove(&DAT_1c000d610,param_1);
  }
  return;
}



===== IoRateExemptionCtxCheckProcess @ 1c0010760 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int IoRateExemptionCtxCheckProcess
              (longlong *param_1,ulonglong param_2,ushort *param_3,ushort *param_4)

{
  wint_t *pwVar1;
  wint_t wVar2;
  int iVar3;
  int iVar4;
  wint_t *pwVar5;
  wint_t *pwVar6;
  wint_t *pwVar7;
  wint_t *pwVar8;
  ushort *puVar9;
  ushort *puVar10;
  
  iVar3 = (**(code **)(DAT_1c000d0e8 + 0x10))(param_2);
  if (iVar3 == 0) {
    puVar10 = (ushort *)param_1[5];
    puVar9 = puVar10 + (ulonglong)*(uint *)(param_1 + 6) * 0x10;
    for (; puVar10 < puVar9; puVar10 = puVar10 + 0x10) {
      pwVar6 = *(wint_t **)(param_3 + 4);
      pwVar5 = pwVar6 + (*param_3 >> 1);
      pwVar1 = (wint_t *)(*(longlong *)(puVar10 + 4) + (ulonglong)(*puVar10 >> 1) * 2);
      for (; pwVar6 < pwVar5; pwVar6 = pwVar6 + 1) {
        pwVar8 = *(wint_t **)(puVar10 + 4);
        pwVar7 = pwVar6;
        do {
          if (pwVar1 <= pwVar8) break;
          wVar2 = towlower(*pwVar7);
          if (wVar2 != *pwVar8) goto LAB_1c0010805;
          pwVar7 = pwVar7 + 1;
          pwVar8 = pwVar8 + 1;
        } while (pwVar7 < pwVar5);
        if (pwVar8 == pwVar1) {
          if ((pwVar6 != (wint_t *)0x0) &&
             ((puVar10[8] == 0 ||
              (((param_4 != (ushort *)0x0 &&
                (pwVar5 = IoRateFindString(param_4,puVar10 + 8), pwVar5 != (wint_t *)0x0)) &&
               (((wint_t *)(((ulonglong)*param_4 & 0xfffffffffffffffe) + *(longlong *)(param_4 + 4))
                 <= pwVar5 + (puVar10[8] >> 1) ||
                (iVar4 = iswspace(pwVar5[puVar10[8] >> 1]), iVar4 != 0)))))))) {
            iVar3 = 1;
            goto LAB_1c001086a;
          }
          break;
        }
LAB_1c0010805:
      }
    }
  }
  else {
LAB_1c001086a:
    IoRateExemptionCtxAdd(param_1,param_2);
  }
  return iVar3;
}



===== IoRateFindString @ 1c00108d0 =====

wint_t * IoRateFindString(ushort *param_1,ushort *param_2)

{
  wint_t *pwVar1;
  wint_t *pwVar2;
  wint_t wVar3;
  wint_t *pwVar4;
  wint_t *pwVar5;
  wint_t *pwVar6;
  
  pwVar4 = *(wint_t **)(param_1 + 4);
  pwVar1 = pwVar4 + (*param_1 >> 1);
  pwVar2 = (wint_t *)(*(longlong *)(param_2 + 4) + (ulonglong)(*param_2 >> 1) * 2);
  do {
    if (pwVar1 <= pwVar4) {
      return (wint_t *)0x0;
    }
    pwVar6 = *(wint_t **)(param_2 + 4);
    pwVar5 = pwVar4;
    do {
      if (pwVar2 <= pwVar6) break;
      wVar3 = towlower(*pwVar5);
      if (wVar3 != *pwVar6) goto LAB_1c001092c;
      pwVar5 = pwVar5 + 1;
      pwVar6 = pwVar6 + 1;
    } while (pwVar5 < pwVar1);
    if (pwVar6 == pwVar2) {
      return pwVar4;
    }
LAB_1c001092c:
    pwVar4 = pwVar4 + 1;
  } while( true );
}



===== IoRateDispatchPnp @ 1c0010970 =====

void IoRateDispatchPnp(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong lVar5;
  
  puVar2 = *(undefined8 **)(param_2 + 0xb8);
  plVar3 = *(longlong **)(param_1 + 0x40);
  cVar1 = *(char *)((longlong)puVar2 + 1);
  lVar4 = plVar3[3];
  if (cVar1 == '\0') {
    puVar2[-9] = *puVar2;
    puVar2[-8] = puVar2[1];
    puVar2[-7] = puVar2[2];
    puVar2[-6] = puVar2[3];
    puVar2[-5] = puVar2[4];
    puVar2[-4] = puVar2[5];
    puVar2[-3] = puVar2[6];
    *(undefined1 *)((longlong)puVar2 + -0x45) = 0;
    lVar5 = *(longlong *)(param_2 + 0xb8);
    *(code **)(lVar5 + -0x10) = IoRateDeviceStartCompletion;
    *(undefined8 *)(lVar5 + -8) = 0;
    *(undefined1 *)(lVar5 + -0x45) = 0x40;
  }
  else {
    if (cVar1 == '\x01') {
      IoRateDeviceExtensionProcessQueryRemove((longlong)plVar3);
    }
    else if (cVar1 == '\x02') {
      IoRateDeviceExtensionCleanup(plVar3);
    }
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  }
  IofCallDriver(lVar4,param_2);
  return;
}



===== _tlgEnableCallback @ 1c0010a30 =====

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



===== IoRateAddDevice @ 1c0010ac0 =====

int IoRateAddDevice(undefined8 param_1,undefined8 param_2)

{
  longlong *plVar1;
  int iVar2;
  undefined8 uVar3;
  longlong lVar4;
  int unaff_EBX;
  longlong local_res18 [2];
  
  local_res18[0] = 0;
  uVar3 = ExSizeOfRundownProtectionCacheAware();
  iVar2 = IoCreateDevice(param_1,(int)uVar3 + 0xa8,0,0x22,0,0,local_res18);
  if (-1 < iVar2) {
    plVar1 = *(longlong **)(local_res18[0] + 0x40);
    IoRateDeviceExtensionInitialize(plVar1,uVar3);
    lVar4 = IoAttachDeviceToDeviceStack(local_res18[0],param_2);
    if (lVar4 != 0) {
      *(uint *)(local_res18[0] + 0x30) = *(uint *)(local_res18[0] + 0x30) | 0x10;
      *(undefined4 *)(local_res18[0] + 0x48) = *(undefined4 *)(lVar4 + 0x48);
      *(undefined4 *)(local_res18[0] + 0x34) = *(undefined4 *)(lVar4 + 0x34);
      if ((*(int *)(lVar4 + 0x48) == 7) && ((*(uint *)(lVar4 + 0x34) & 0xf) == 0)) {
        uVar3 = IoRateDeviceExtensionStart(plVar1,local_res18[0],lVar4);
        local_res18[0] = 0;
        lVar4 = 0;
        if (-1 < (int)uVar3) {
          return unaff_EBX;
        }
      }
    }
    if (plVar1 != (longlong *)0x0) {
      IoRateDeviceExtensionCleanup(plVar1);
    }
    if (lVar4 != 0) {
      IoDetachDevice(lVar4);
    }
  }
  if (local_res18[0] != 0) {
    IoDeleteDevice();
  }
  return unaff_EBX;
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



===== DriverEntry @ 1c0011078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DriverEntry(longlong param_1,ushort *param_2)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined *local_20;
  undefined8 *local_18;
  longlong local_10;
  
  memset(&IoRateGlobals,0,0x6b0);
  DAT_1c000d120 = &DAT_1c000d118;
  DAT_1c000d118 = &DAT_1c000d118;
  DAT_1c000d100 = &DAT_1c000d0f8;
  DAT_1c000d0f8 = &DAT_1c000d0f8;
  memset(&DAT_1c000d138,0,0x1d0);
  _DAT_1c000d140 = &DAT_1c000d138;
  _DAT_1c000d2e8 = &DAT_1c000d2e0;
  DAT_1c000d2e0 = &DAT_1c000d2e0;
  _DAT_1c000d138 = &DAT_1c000d138;
  _DAT_1c000d150 = &DAT_1c000d148;
  _DAT_1c000d148 = &DAT_1c000d148;
  _DAT_1c000d168 = 1;
  _DAT_1c000d580 = 0;
  _DAT_1c000d640 = 0;
  _DAT_1c000d570 = 0;
  uRam00000001c000d578 = 0;
  _DAT_1c000d620 = 0;
  _DAT_1c000d628 = 0;
  _DAT_1c000d630 = 0;
  _DAT_1c000d638 = (undefined *)0x0;
  DAT_1c000d610 = 0;
  DAT_1c000d618 = 0;
  RtlInitUnicodeString(&DAT_1c000d628,0);
  _DAT_1c000d640 = 0xf;
  _DAT_1c000d638 = &IoRateExemptionStringsDefault;
  KeInitializeTimer(&DAT_1c000d588);
  KeInitializeDpc(&DAT_1c000d5c8,IoRateQuantumDpcRoutine,0);
  memset(&DAT_1c000d308,0,0x1d0);
  _DAT_1c000d310 = &DAT_1c000d308;
  _DAT_1c000d4b8 = &DAT_1c000d4b0;
  _DAT_1c000d4b0 = &DAT_1c000d4b0;
  _DAT_1c000d308 = &DAT_1c000d308;
  _DAT_1c000d320 = &DAT_1c000d318;
  _DAT_1c000d318 = &DAT_1c000d318;
  _DAT_1c000d338 = 1;
  KeInitializeDpc(&DAT_1c000d4d8,IoRateDpcProcessRoutine,0);
  DAT_1c000d560 = &DAT_1c000d558;
  DAT_1c000d558 = &DAT_1c000d558;
  KeInitializeDpc(&DAT_1c000d518,IoRateSplitContextDpcRoutine,0);
  IoRateUpdateRateControlListGeneration();
  IoRateGlobals = param_1;
  ExInitializeLookasideListEx(&DAT_1c000d6b0,0,0,0x200,0,0x90,0x62526f69,0);
  ExInitializeLookasideListEx(&DAT_1c000d710,0,0,0x200,0,0x40,0x6c526f69,0);
  local_28 = 0x10006;
  _DAT_1c000d0d0 = IoRateStartRateControl;
  local_24 = 0x30000;
  _DAT_1c000d0d8 = IoRateStopRateControl;
  _DAT_1c000d0e0 = IoRateBoostThread;
  local_20 = &DAT_1c000d0d0;
  local_18 = &DAT_1c000d0e8;
  local_10 = param_1;
  iVar1 = ExRegisterExtension(&DAT_1c000d0c8,0x10001,&local_28);
  if (iVar1 < 0) goto LAB_1c0011447;
  iVar1 = IoRateExemptionCtxQueryExemptionList(0x1c000d610,param_2);
  if ((iVar1 < 0) ||
     (iVar1 = PsSetCreateProcessNotifyRoutineEx(IoRateProcessCreateNotify,0), iVar1 < 0)) {
LAB_1c00113aa:
    if (iVar1 < 0) goto LAB_1c0011447;
  }
  else {
    _DAT_1c000d644 = _DAT_1c000d644 | 1;
    iVar1 = IoRateExemptionCtxCheckRunningProcesses(&DAT_1c000d610);
    if (iVar1 < 0) goto LAB_1c00113aa;
  }
  iVar1 = IoRateGetParameters((undefined8 *)param_2,(longlong *)&DAT_1c000d650);
  if (-1 < iVar1) {
    _DAT_1c000d680 = &DAT_1c000d650;
    _DAT_1c000d678 = IoRateParametersWatcher;
    _DAT_1c000d668 = 0;
    IoRateStartParametersWatch((longlong *)&DAT_1c000d650);
    TraceLoggingRegisterEx_EtwRegister_EtwSetInformation();
    puVar3 = (undefined8 *)(param_1 + 0x70);
    for (lVar2 = 0x1c; lVar2 != 0; lVar2 = lVar2 + -1) {
      *puVar3 = IoRateDispatchPassthrough;
      puVar3 = puVar3 + 1;
    }
    *(code **)(param_1 + 0x88) = IoRateDispatchReadWrite;
    *(code **)(param_1 + 0x90) = IoRateDispatchReadWrite;
    *(code **)(param_1 + 0x148) = IoRateDispatchPnp;
    *(code **)(*(longlong *)(param_1 + 0x30) + 8) = IoRateAddDevice;
    *(code **)(param_1 + 0x68) = IoRateUnload;
    return 0;
  }
LAB_1c0011447:
  IoRateCleanupGlobalData();
  return iVar1;
}



===== IoRateExemptionCtxCheckRunningProcesses @ 1c0011470 =====

int IoRateExemptionCtxCheckRunningProcesses(longlong *param_1)

{
  ulonglong uVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  longlong lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 local_res10 [2];
  longlong local_res18;
  ulonglong local_res20;
  
  local_res18 = 0;
  lVar5 = 0;
  local_res10[0] = 0;
  puVar3 = (ushort *)0x0;
  puVar4 = (ushort *)0x0;
  uVar7 = 0;
  uVar6 = 0;
  while( true ) {
    iVar2 = ZwGetNextProcess(lVar5,0x1fffff,0x200,0,&local_res18);
    if (iVar2 == -0x7fffffe6) break;
    if (iVar2 < 0) goto LAB_1c001163b;
    if (lVar5 != 0) {
      ZwClose(lVar5);
    }
    lVar5 = local_res18;
    while( true ) {
      iVar2 = ZwQueryInformationProcess(lVar5,0x1b,puVar3,uVar7,local_res10);
      if (iVar2 != -0x3ffffffc) break;
      if (puVar3 != (ushort *)0x0) {
        ExFreePoolWithTag(puVar3,0);
      }
      puVar3 = (ushort *)ExAllocatePool2(0x100,local_res10[0],0x74526f69);
      if (puVar3 == (ushort *)0x0) goto LAB_1c0011632;
      uVar7 = local_res10[0];
    }
    if (-1 < iVar2) {
      while( true ) {
        iVar2 = ZwQueryInformationProcess(lVar5,0x3c,puVar4,uVar6,local_res10);
        if (iVar2 != -0x3ffffffc) break;
        if (puVar4 != (ushort *)0x0) {
          ExFreePoolWithTag(puVar4,0);
        }
        puVar4 = (ushort *)ExAllocatePool2(0x100,local_res10[0],0x74526f69);
        if (puVar4 == (ushort *)0x0) goto LAB_1c0011632;
        uVar6 = local_res10[0];
      }
      if (-1 < iVar2) {
        local_res20 = 0;
        iVar2 = ObReferenceObjectByHandle(lVar5,0,0,0,&local_res20,0);
        uVar1 = local_res20;
        if (-1 < iVar2) {
          IoRateExemptionCtxCheckProcess(param_1,local_res20,puVar3,puVar4);
          ObfDereferenceObject(uVar1);
        }
      }
    }
  }
  iVar2 = 0;
LAB_1c001163b:
  if (lVar5 != 0) {
    ZwClose(lVar5);
  }
  if (puVar3 != (ushort *)0x0) {
    ExFreePoolWithTag(puVar3,0);
  }
  if (puVar4 != (ushort *)0x0) {
    ExFreePoolWithTag(puVar4,0);
  }
  return iVar2;
LAB_1c0011632:
  iVar2 = -0x3fffff66;
  goto LAB_1c001163b;
}



===== IoRateExemptionCtxQueryExemptionList @ 1c001169c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int IoRateExemptionCtxQueryExemptionList(longlong param_1,ushort *param_2)

{
  short sVar1;
  byte bVar2;
  wint_t wVar3;
  int iVar4;
  ulonglong uVar5;
  longlong lVar6;
  short *psVar7;
  wint_t *pwVar8;
  wint_t *pwVar9;
  short *psVar10;
  longlong lVar11;
  wint_t *pwVar12;
  uint uVar13;
  undefined1 auStack_2f8 [32];
  undefined8 local_2d8;
  undefined8 local_2c8;
  undefined8 uStack_2c0;
  longlong local_2b8;
  undefined8 local_2a8;
  undefined4 local_2a0;
  wchar_t *local_298;
  undefined8 *local_290;
  undefined4 local_288;
  undefined8 local_280;
  undefined4 local_278;
  undefined8 local_270;
  undefined4 local_268;
  undefined8 local_260;
  undefined8 local_258;
  undefined4 local_250;
  undefined8 local_248;
  undefined4 local_240;
  short local_238 [256];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_2f8;
  local_2a8 = 0;
  local_298 = L"ExemptionList";
  local_290 = &local_2c8;
  local_2a0 = 0x130;
  local_288 = 0x7000000;
  local_280 = 0;
  local_278 = 0;
  local_2c8 = 0;
  uStack_2c0 = (wint_t *)0x0;
  local_270 = 0;
  local_268 = 0;
  local_260 = 0;
  local_258 = 0;
  local_250 = 0;
  local_248 = 0;
  local_240 = 0;
  local_2b8 = param_1;
  RtlInitUnicodeString(&local_2c8,0);
  lVar6 = *(longlong *)(param_2 + 4);
  psVar7 = local_238;
  uVar5 = (ulonglong)(*param_2 >> 1);
  lVar11 = 0x100;
  do {
    if ((uVar5 == 0) ||
       (sVar1 = *(short *)((lVar6 - (longlong)local_238) + (longlong)psVar7), sVar1 == 0)) break;
    *psVar7 = sVar1;
    uVar5 = uVar5 - 1;
    psVar7 = psVar7 + 1;
    lVar11 = lVar11 + -1;
  } while (lVar11 != 0);
  local_2d8 = 0;
  psVar10 = psVar7 + -1;
  if (lVar11 != 0) {
    psVar10 = psVar7;
  }
  *psVar10 = 0;
  iVar4 = RtlQueryRegistryValuesEx(0,local_238,&local_2a8,0);
  if (-1 < iVar4) {
    if ((ushort)local_2c8 == 0) {
      iVar4 = 0x40190034;
    }
    else {
      uVar5 = 0;
      pwVar8 = uStack_2c0;
      pwVar12 = uStack_2c0;
      while( true ) {
        pwVar9 = pwVar8;
        if (uStack_2c0 + ((ushort)local_2c8 >> 1) <= pwVar8) break;
        pwVar9 = pwVar8 + 1;
        if (*pwVar8 == 0) {
          if (pwVar8 == pwVar12) break;
          uVar5 = (ulonglong)((int)uVar5 + 1);
          pwVar12 = pwVar9;
        }
        pwVar8 = pwVar9;
      }
      if ((((pwVar9 == uStack_2c0 + ((ushort)local_2c8 >> 1)) && ((int)uVar5 != 0)) &&
          ((uVar5 & 1) == 0)) && (pwVar9[-1] == 0)) {
        lVar6 = ExAllocatePool2(0x100,uVar5 << 5,0x61526f69);
        if (lVar6 == 0) {
          iVar4 = -0x3fffff66;
        }
        else {
          uVar5 = 0;
          bVar2 = 0;
          uVar13 = 0;
          pwVar8 = uStack_2c0 + (local_2c8 >> 1 & 0x7fff);
          if (uStack_2c0 < pwVar8) {
            pwVar12 = uStack_2c0;
            pwVar9 = uStack_2c0;
            do {
              uVar13 = (uint)uVar5;
              if (*pwVar12 == 0) {
                if (pwVar12 == pwVar9) break;
                psVar10 = (short *)((uVar5 >> 1) * 0x20 + lVar6);
                psVar7 = psVar10 + 8;
                if (!(bool)(bVar2 & 1)) {
                  psVar7 = psVar10;
                }
                RtlInitUnicodeString(psVar7,pwVar9);
                if ((*psVar7 == 2) && (**(short **)(psVar7 + 4) == 0x20)) {
                  *psVar7 = 0;
                }
                pwVar9 = pwVar12 + 1;
                bVar2 = bVar2 + 1;
                uVar5 = (ulonglong)(uVar13 + 1);
              }
              else {
                wVar3 = towlower(*pwVar12);
                *pwVar12 = wVar3;
              }
              uVar13 = (uint)uVar5;
              pwVar12 = pwVar12 + 1;
            } while (pwVar12 < pwVar8);
            param_1 = local_2b8;
          }
          *(longlong *)(param_1 + 0x28) = lVar6;
          *(undefined4 *)(param_1 + 0x18) = (undefined4)local_2c8;
          *(undefined4 *)(param_1 + 0x1c) = local_2c8._4_4_;
          *(undefined4 *)(param_1 + 0x20) = (undefined4)uStack_2c0;
          *(undefined4 *)(param_1 + 0x24) = uStack_2c0._4_4_;
          *(uint *)(param_1 + 0x30) = uVar13 >> 1;
          RtlInitUnicodeString(&local_2c8,0);
          iVar4 = 0;
        }
      }
      else {
        iVar4 = -0x3fffff10;
      }
    }
  }
  RtlFreeUnicodeString(&local_2c8);
  return iVar4;
}


