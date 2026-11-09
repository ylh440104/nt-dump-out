
===== __report_gsfailure @ 1c0001010 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== BttFltAlignOffsets @ 1c0001020 =====

undefined8
BttFltAlignOffsets(longlong param_1,ulonglong param_2,longlong param_3,ulonglong *param_4,
                  longlong *param_5)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)(int)-*(uint *)(param_1 + 0x20);
  uVar1 = uVar2 & param_2;
  uVar2 = (param_2 - 1) + (ulonglong)*(uint *)(param_1 + 0x20) + param_3 & uVar2;
  if (uVar1 < uVar2) {
    *param_4 = uVar1;
    *param_5 = uVar2 - uVar1;
    return 0;
  }
  return 0xc0000095;
}



===== BttFltCompleteIoOperation @ 1c0001064 =====

void BttFltCompleteIoOperation(longlong param_1,undefined4 param_2,undefined8 param_3)

{
  longlong lVar1;
  
  BttFltSetReadWriteOffsets
            (*(longlong *)(param_1 + 0x20),*(ulonglong *)(param_1 + 0x30),
             *(ulonglong *)(param_1 + 0x38));
  lVar1 = *(longlong *)(param_1 + 8);
  if (*(longlong *)(param_1 + 0x10) != 0) {
    *(longlong *)(lVar1 + 8) = *(longlong *)(param_1 + 0x10);
  }
  if (*(longlong *)(param_1 + 0x18) != 0) {
    IoFreeMdl();
  }
  ExFreeToLookasideListEx(&DAT_1c00080f0,param_1);
  *(undefined4 *)(lVar1 + 0x30) = param_2;
  *(undefined8 *)(lVar1 + 0x38) = param_3;
  IofCompleteRequest(lVar1,0);
  return;
}



===== BttFltContinueIoOperation @ 1c0001110 =====

undefined8 BttFltContinueIoOperation(undefined8 param_1,longlong param_2,longlong *param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_2 + 0x30);
  uVar2 = 0;
  if (iVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x15,param_3,param_3,(char)iVar1);
    }
  }
  else {
    param_3[5] = param_3[5] + param_3[9];
    if ((ulonglong)param_3[5] < (ulonglong)param_3[7]) {
      BttFltStartNextIoOperation(param_3);
      return 0xc0000016;
    }
    uVar2 = *(int *)(*param_3 + 0x20) * (int)param_3[7];
    iVar1 = 0;
  }
  BttFltCompleteIoOperation((longlong)param_3,iVar1,(ulonglong)uVar2);
  return 0xc0000016;
}



===== BttFltFreeSrbContext @ 1c00011b4 =====

void BttFltFreeSrbContext(longlong *param_1)

{
  if (*param_1 != 0) {
    if (*(longlong *)(*param_1 + 8) != 0) {
      IoFreeMdl();
    }
    IoFreeIrp(*param_1);
  }
  ExFreeToLookasideListEx(&DAT_1c0008150,param_1);
  return;
}



===== BttFltGetBadMemoryRangeCount @ 1c0001210 =====

undefined8 BttFltGetBadMemoryRangeCount(void)

{
  return 0;
}



===== BttFltIsPhysicalMemoryRangeGood @ 1c0001220 =====

undefined1 BttFltIsPhysicalMemoryRangeGood(void)

{
  return 1;
}



===== BttFltLinkDevice @ 1c000122c =====

void BttFltLinkDevice(undefined8 *param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  undefined1 *puVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [24];
  
  uVar2 = KeAcquireSpinLockRaiseToDpc(&DAT_1c00081b0);
  puVar5 = auStack_28;
  puVar4 = &DAT_1c00081b8;
  puVar3 = DAT_1c00081c0;
  if ((undefined *)*DAT_1c00081c0 != &DAT_1c00081b8) {
    puVar3 = (undefined8 *)0x3;
    pcVar1 = (code *)swi(0x29);
    uVar2 = (*pcVar1)();
    puVar5 = auStack_20;
  }
  *param_1 = puVar4;
  param_1[1] = puVar3;
  *puVar3 = param_1;
  *(undefined8 *)(puVar5 + -8) = 0x1c0001283;
  DAT_1c00081c0 = param_1;
  KeReleaseSpinLock(&DAT_1c00081b0,uVar2);
  return;
}



===== BttFltNsReadMapped @ 1c00012a0 =====

undefined8
BttFltNsReadMapped(undefined8 param_1,undefined8 param_2,longlong param_3,void *param_4,
                  size_t param_5,longlong param_6)

{
  memcpy(param_4,(void *)(param_6 + param_3),param_5);
  return 0;
}



===== BttFltNsUnmap @ 1c00012d0 =====

void BttFltNsUnmap(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  ExFreePoolWithTag(param_3,0x63545442);
  return;
}



===== BttFltNsWriteMapped @ 1c0001300 =====

undefined8 BttFltNsWriteMapped(void)

{
  return 0xffffffff;
}



===== BttFltPassThrough @ 1c0001310 =====

void BttFltPassThrough(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
  *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
  IofCallDriver(*(undefined8 *)(lVar1 + 0x10));
  return;
}



===== BttFltProcessReadWrite @ 1c0001340 =====

undefined4 BttFltProcessReadWrite(longlong param_1,longlong param_2,longlong param_3)

{
  char cVar1;
  uint uVar2;
  longlong *_Dst;
  longlong lVar3;
  ulonglong uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  uint uVar8;
  ulonglong uVar9;
  
  if (*(longlong *)(param_2 + 8) == 0) {
    uVar5 = 0xc000000d;
    goto LAB_1c00014a3;
  }
  _Dst = (longlong *)ExAllocateFromLookasideListEx(&DAT_1c00080f0);
  if (_Dst == (longlong *)0x0) {
    uVar5 = 0xc000009a;
    goto LAB_1c00014a3;
  }
  uVar4 = 0;
  uVar7 = 0x50;
  memset(_Dst,0,0x50);
  cVar1 = *(char *)(param_3 + 0x48);
  if ((cVar1 == '\b') || (cVar1 == '\n')) {
    uVar8 = *(uint *)(param_3 + 0x48);
    uVar9 = (ulonglong)*(byte *)(param_3 + 0x4c);
    uVar6 = (ulonglong)(uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0x1f00) << 8);
LAB_1c0001416:
    if (uVar9 == 0) goto LAB_1c000141b;
    _Dst[5] = 0;
    *_Dst = param_1;
    _Dst[1] = param_2;
    _Dst[4] = param_3;
    _Dst[6] = uVar6;
    _Dst[7] = uVar9;
    if (uVar9 < 2) {
LAB_1c00014cf:
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qDII(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar4,uVar7,_Dst,
                    *(undefined1 *)(param_3 + 0x48),(char)uVar6,(char)uVar9);
      }
      uVar4 = BttFltStartNextIoOperation(_Dst);
      return (int)uVar4;
    }
    lVar3 = *(longlong *)(param_2 + 8);
    uVar7 = 0;
    uVar4 = (ulonglong)*(uint *)(lVar3 + 0x28);
    lVar3 = IoAllocateMdl((ulonglong)*(uint *)(lVar3 + 0x2c) + *(longlong *)(lVar3 + 0x20),uVar4,0,0
                          ,0);
    _Dst[3] = lVar3;
    if (lVar3 != 0) {
      _Dst[2] = *(longlong *)(param_2 + 8);
      *(longlong *)(param_2 + 8) = lVar3;
      goto LAB_1c00014cf;
    }
    uVar5 = 0xc000009a;
  }
  else {
    if ((cVar1 == '(') || (cVar1 == '*')) {
      uVar8 = *(uint *)(param_3 + 0x4a);
      uVar6 = (ulonglong)
              (uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18);
      uVar9 = (ulonglong)
              (ushort)(*(ushort *)(param_3 + 0x4f) >> 8 | *(ushort *)(param_3 + 0x4f) << 8);
      goto LAB_1c0001416;
    }
    if ((cVar1 == -0x78) || (cVar1 == -0x76)) {
      uVar6 = *(ulonglong *)(param_3 + 0x4a);
      uVar8 = *(uint *)(param_3 + 0x52);
      uVar6 = uVar6 >> 0x38 | (uVar6 & 0xff000000000000) >> 0x28 | (uVar6 & 0xff0000000000) >> 0x18
              | (uVar6 & 0xff00000000) >> 8 | (uVar6 & 0xff000000) << 8 | (uVar6 & 0xff0000) << 0x18
              | (uVar6 & 0xff00) << 0x28 | uVar6 << 0x38;
LAB_1c00013dc:
      uVar9 = (ulonglong)
              (uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18);
      goto LAB_1c0001416;
    }
    if ((cVar1 == -0x58) || (cVar1 == -0x56)) {
      uVar2 = *(uint *)(param_3 + 0x4a);
      uVar8 = *(uint *)(param_3 + 0x4e);
      uVar6 = (ulonglong)
              (uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18);
      goto LAB_1c00013dc;
    }
LAB_1c000141b:
    uVar5 = 0;
  }
  if (_Dst[3] != 0) {
    IoFreeMdl();
  }
  ExFreeToLookasideListEx(&DAT_1c00080f0,_Dst);
LAB_1c00014a3:
  if (param_2 != 0) {
    *(undefined8 *)(param_2 + 0x38) = 0;
    *(undefined4 *)(param_2 + 0x30) = uVar5;
    IofCompleteRequest(param_2,0);
  }
  return uVar5;
}



===== BttFltProcessScsi @ 1c0001540 =====

undefined4 BttFltProcessScsi(longlong param_1,longlong param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  uint *puVar4;
  ulonglong *puVar5;
  undefined4 uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined1 uVar9;
  bool bVar10;
  
  lVar2 = *(longlong *)(param_1 + 0x40);
  lVar3 = *(longlong *)(*(longlong *)(param_2 + 0xb8) + 8);
  if (*(char *)(lVar3 + 2) != '\0') goto LAB_1c00015c7;
  bVar1 = *(byte *)(lVar3 + 0x48);
  if (bVar1 < 0x89) {
    if (((bVar1 - 8 & 0xffffff7d) == 0) && (bVar1 != 0x8a)) goto LAB_1c000166b;
    if (bVar1 == 0x25) {
LAB_1c00015dc:
      uVar9 = 1;
      uVar8 = *(longlong *)(lVar2 + 0x30) - 1;
      if (bVar1 == 0x25) {
        if (7 < *(uint *)(lVar3 + 0x10)) {
          uVar7 = *(uint *)(lVar2 + 0x20);
          puVar4 = *(uint **)(lVar3 + 0x18);
          puVar4[1] = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 |
                      uVar7 << 0x18;
          uVar7 = 0xffffffff;
          if (uVar8 < 0x100000000) {
            uVar7 = (uint)uVar8;
          }
          *puVar4 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
          *(undefined4 *)(lVar3 + 0x10) = 8;
          goto LAB_1c000164d;
        }
      }
      else if (0xb < *(uint *)(lVar3 + 0x10)) {
        uVar7 = *(uint *)(lVar2 + 0x20);
        puVar5 = *(ulonglong **)(lVar3 + 0x18);
        *(undefined4 *)(lVar3 + 0x10) = 0xc;
        *puVar5 = uVar8 >> 0x38 | (uVar8 & 0xff000000000000) >> 0x28 |
                  (uVar8 & 0xff0000000000) >> 0x18 | (uVar8 & 0xff00000000) >> 8 |
                  (uVar8 & 0xff000000) << 8 | (uVar8 & 0xff0000) << 0x18 | (uVar8 & 0xff00) << 0x28
                  | uVar8 << 0x38;
        *(uint *)(puVar5 + 1) =
             uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
        goto LAB_1c000164d;
      }
      uVar9 = 0x12;
LAB_1c000164d:
      *(undefined1 *)(lVar3 + 3) = uVar9;
      *(undefined4 *)(param_2 + 0x30) = 0;
      IofCompleteRequest(param_2,0);
      return 0;
    }
    bVar10 = (bVar1 - 0x28 & 0xfffffffd) == 0;
  }
  else {
    if (bVar1 == 0x8a) goto LAB_1c000166b;
    if (bVar1 == 0x9e) goto LAB_1c00015dc;
    if (bVar1 == 0xa8) goto LAB_1c000166b;
    bVar10 = bVar1 == 0xaa;
  }
  if (bVar10) {
LAB_1c000166b:
    uVar6 = BttFltProcessReadWrite(lVar2,param_2,lVar3);
    return uVar6;
  }
LAB_1c00015c7:
  uVar6 = BttFltPassThrough(param_1,param_2);
  return uVar6;
}



===== BttFltSetReadWriteOffsets @ 1c0001684 =====

undefined8 BttFltSetReadWriteOffsets(longlong param_1,ulonglong param_2,ulonglong param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((0xffffffff < param_2) || (0xffffffff < param_3)) {
    return 0xc000000d;
  }
  bVar1 = *(byte *)(param_1 + 0x48);
  uVar2 = (uint)bVar1;
  uVar4 = (uint)param_2;
  uVar3 = (uint)param_3;
  if (bVar1 < 0x89) {
    if (bVar1 != 0x88) {
      if ((bVar1 - 8 & 0xfffffffd) == 0) {
        *(char *)(param_1 + 0x4b) = (char)param_2;
        *(char *)(param_1 + 0x4c) = (char)param_3;
        *(char *)(param_1 + 0x4a) = (char)(param_2 >> 8);
        *(byte *)(param_1 + 0x49) =
             ((byte)(param_2 >> 0x10) ^ *(byte *)(param_1 + 0x49)) & 0x1f ^
             *(byte *)(param_1 + 0x49);
        return 0;
      }
      if (0x19 < uVar2 - 0x28) {
        return 0xc000000d;
      }
      if ((0x2000005U >> (uVar2 - 0x28 & 0x1f) & 1) == 0) {
        return 0xc000000d;
      }
      *(uint *)(param_1 + 0x4a) =
           uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
      *(ushort *)(param_1 + 0x4f) = (ushort)param_3 >> 8 | (ushort)param_3 << 8;
      return 0;
    }
  }
  else if ((uVar2 != 0x8a) && (uVar2 != 0x93)) {
    if ((uVar2 == 0xa8) || (uVar2 == 0xaa)) {
      *(uint *)(param_1 + 0x4a) =
           uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
      *(uint *)(param_1 + 0x4e) =
           uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      return 0;
    }
    return 0xc000000d;
  }
  *(ulonglong *)(param_1 + 0x4a) =
       param_2 >> 0x38 | (param_2 & 0xff000000000000) >> 0x28 | (param_2 & 0xff0000000000) >> 0x18 |
       (param_2 & 0xff00000000) >> 8 | (param_2 & 0xff000000) << 8 | (param_2 & 0xff0000) << 0x18 |
       (param_2 & 0xff00) << 0x28 | param_2 << 0x38;
  *(uint *)(param_1 + 0x52) =
       uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  return 0;
}



===== BttFltSetSrbOpCode @ 1c0001758 =====

void BttFltSetSrbOpCode(longlong param_1,char param_2)

{
  *(char *)(param_1 + 0x48) = param_2;
  if (param_2 != -0x78) {
    if ((param_2 == -0x76) || (param_2 == -0x6d)) {
      *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x80;
      goto LAB_1c0001788;
    }
    if (param_2 != -0x62) {
      return;
    }
    *(byte *)(param_1 + 0x49) = *(byte *)(param_1 + 0x49) & 0xf0 | 0x10;
  }
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x40;
LAB_1c0001788:
  *(undefined1 *)(param_1 + 10) = 0x10;
  return;
}



===== BttFltStartNextIoOperation @ 1c000179c =====

ulonglong BttFltStartNextIoOperation(longlong *param_1)

{
  byte *pbVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined2 uVar11;
  ulonglong uVar12;
  longlong lVar13;
  ulonglong *puVar14;
  longlong lVar15;
  ulonglong local_res8;
  
  puVar14 = &local_res8;
  uVar12 = param_1[6] + param_1[5];
  lVar13 = param_1[7] - param_1[5];
  local_res8 = 0;
  uVar8 = ScmBttGetDataOffsetForBlock(*(longlong *)(*param_1 + 0x60),uVar12,(longlong *)puVar14);
  if ((int)uVar8 != 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      uVar11 = 0x10;
LAB_1c0001806:
      WPP_SF_Iqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,puVar14,uVar12,(char)*param_1);
    }
LAB_1c000181a:
    uVar12 = 0xc0000001;
    goto LAB_1c00019d5;
  }
  lVar15 = *param_1;
  uVar2 = *(uint *)(lVar15 + 0x20);
  param_1[9] = 1;
  param_1[8] = local_res8 / uVar2;
  while (uVar8 = local_res8, lVar13 = lVar13 + -1, lVar13 != 0) {
    puVar14 = &local_res8;
    uVar12 = uVar12 + 1;
    uVar9 = ScmBttGetDataOffsetForBlock(*(longlong *)(lVar15 + 0x60),uVar12,(longlong *)puVar14);
    if ((int)uVar9 != 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c000181a;
      uVar11 = 0x11;
      goto LAB_1c0001806;
    }
    lVar15 = *param_1;
    if (local_res8 != *(uint *)(lVar15 + 0x20) + uVar8) break;
    param_1[9] = param_1[9] + 1;
  }
  uVar8 = param_1[3];
  if (uVar8 == 0) {
LAB_1c000198c:
    uVar8 = param_1[9];
    uVar9 = param_1[8];
    uVar10 = BttFltSetReadWriteOffsets(param_1[4],uVar9,uVar8);
    uVar12 = uVar10 & 0xffffffff;
    if (-1 < (int)uVar10) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (4 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_qII(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar9,uVar8,param_1,(char)param_1[8],
                   (char)param_1[9]);
      }
      pbVar1 = (byte *)(*(longlong *)(param_1[1] + 0xb8) + 3);
      *pbVar1 = *pbVar1 | 1;
      puVar3 = *(undefined8 **)(param_1[1] + 0xb8);
      puVar3[-9] = *puVar3;
      puVar3[-8] = puVar3[1];
      puVar3[-7] = puVar3[2];
      puVar3[-6] = puVar3[3];
      *(undefined4 *)(puVar3 + -5) = *(undefined4 *)(puVar3 + 4);
      *(undefined4 *)((longlong)puVar3 + -0x24) = *(undefined4 *)((longlong)puVar3 + 0x24);
      *(undefined4 *)(puVar3 + -4) = *(undefined4 *)(puVar3 + 5);
      *(undefined4 *)((longlong)puVar3 + -0x1c) = *(undefined4 *)((longlong)puVar3 + 0x2c);
      puVar3[-3] = puVar3[6];
      *(undefined1 *)((longlong)puVar3 + -0x45) = 0;
      lVar13 = *(longlong *)(param_1[1] + 0xb8);
      *(code **)(lVar13 + -0x10) = BttFltContinueIoOperation;
      *(longlong **)(lVar13 + -8) = param_1;
      *(undefined1 *)(lVar13 + -0x45) = 0xe0;
      IofCallDriver(*(undefined8 *)(*param_1 + 0x10),param_1[1]);
      return 0x103;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c00019d5;
    uVar11 = 0x13;
LAB_1c00019c9:
    WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar11,uVar8,(int)uVar12);
  }
  else {
    uVar12 = CONCAT44(0,*(uint *)(lVar15 + 0x20));
    auVar4._8_8_ = 0;
    auVar4._0_8_ = param_1[9];
    auVar6._8_8_ = 0;
    auVar6._0_8_ = uVar12;
    auVar4 = auVar4 * auVar6;
    if (auVar4._8_8_ == 0) {
      if (0xffffffff < auVar4._0_8_) {
        uVar12 = 0x80000005;
        goto LAB_1c00019d5;
      }
      auVar5._8_8_ = 0;
      auVar5._0_8_ = param_1[5];
      auVar7._8_8_ = 0;
      auVar7._0_8_ = uVar12;
      uVar12 = SUB168(auVar5 * auVar7,0);
      if ((SUB168(auVar5 * auVar7,8) == 0) && (uVar9 = uVar12 + auVar4._0_8_, uVar12 <= uVar9)) {
        if (uVar9 <= *(uint *)(param_1[2] + 0x28)) {
          if ((*(byte *)(uVar8 + 10) & 0x20) != 0) {
            MmUnmapLockedPages(*(undefined8 *)(uVar8 + 0x18),uVar8);
          }
          lVar13 = param_1[2];
          IoBuildPartialMdl(lVar13,param_1[3],
                            (ulonglong)*(uint *)(lVar13 + 0x2c) + *(longlong *)(lVar13 + 0x20) +
                            (uVar12 & 0xffffffff),auVar4._0_4_);
          goto LAB_1c000198c;
        }
        uVar12 = 0x80000005;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c00019d5;
        uVar11 = 0x12;
        goto LAB_1c00019c9;
      }
    }
    uVar12 = 0xc0000095;
  }
LAB_1c00019d5:
  BttFltCompleteIoOperation((longlong)param_1,(int)uVar12,0);
  return uVar12;
}



===== BttFltUnlinkDevice @ 1c0001ac4 =====

void BttFltUnlinkDevice(longlong *param_1)

{
  longlong lVar1;
  longlong *plVar2;
  code *pcVar3;
  undefined1 uVar4;
  
  uVar4 = KeAcquireSpinLockRaiseToDpc(&DAT_1c00081b0);
  lVar1 = *param_1;
  if ((*(longlong **)(lVar1 + 8) == param_1) &&
     (plVar2 = (longlong *)param_1[1], (longlong *)*plVar2 == param_1)) {
    *plVar2 = lVar1;
    *(longlong **)(lVar1 + 8) = plVar2;
    KeReleaseSpinLock(&DAT_1c00081b0,CONCAT71((int7)((ulonglong)plVar2 >> 8),uVar4));
    return;
  }
  pcVar3 = (code *)swi(0x29);
  (*pcVar3)(3);
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}



===== BttFltUnload @ 1c0001b30 =====

void BttFltUnload(void)

{
  ExDeleteLookasideListEx(&DAT_1c00080f0);
  ExDeleteLookasideListEx(&DAT_1c0008150);
  WppCleanupKm();
  return;
}



===== WPP_SF_Dqd @ 1c0001b6c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Dqd(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined1 param_5)

{
  undefined4 local_res20 [2];
  undefined4 local_18 [6];
  
  local_18[0] = 0xc00000bb;
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_47b6c69f5b1a3b695cff7f911cf6702a_Traceguids,0x19,local_res20,4,
             &param_5,8,local_18,4,0);
  return;
}



===== WPP_SF_IId @ 1c0001bdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_IId(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined8 local_res20;
  undefined4 local_18 [6];
  
  local_18[0] = 0xc00000bb;
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_47b6c69f5b1a3b695cff7f911cf6702a_Traceguids,0x2f,&local_res20,8,
             &param_5,8,local_18,4,0);
  return;
}



===== WPP_SF_Iq @ 1c0001c4c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Iq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_47b6c69f5b1a3b695cff7f911cf6702a_Traceguids,0x1f,&local_res20,8,
             &param_5,8,0);
  return;
}



===== WPP_SF_Iqd @ 1c0001ca4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_Iqd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5)

{
  undefined8 local_res20;
  undefined4 local_18 [6];
  
  local_18[0] = 0xc0000001;
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_47b6c69f5b1a3b695cff7f911cf6702a_Traceguids,param_2,&local_res20,8,
             &param_5,8,local_18,4,0);
  return;
}



===== WPP_SF__guid_d @ 1c0001d14 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF__guid_d(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 local_18 [6];
  
  local_18[0] = 0xc00000bb;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_47b6c69f5b1a3b695cff7f911cf6702a_Traceguids,0x25,param_4,0x10,
             local_18,4,0);
  return;
}



===== WPP_SF_d @ 1c0001d70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_d(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 local_res20 [2];
  
  local_res20[0] = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_47b6c69f5b1a3b695cff7f911cf6702a_Traceguids,param_2,local_res20,4,0);
  return;
}



===== WPP_SF_q @ 1c0001db8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_q(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_47b6c69f5b1a3b695cff7f911cf6702a_Traceguids,param_2,&local_res20,8,0)
  ;
  return;
}



===== WPP_SF_qDII @ 1c0001e00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qDII(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined1 param_5,undefined1 param_6,undefined1 param_7)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_47b6c69f5b1a3b695cff7f911cf6702a_Traceguids,0x16,&local_res20,8,
             &param_5,4,&param_6,8,&param_7,8,0);
  return;
}



===== WPP_SF_qII @ 1c0001e74 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qII(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_47b6c69f5b1a3b695cff7f911cf6702a_Traceguids,0x14,&local_res20,8,
             &param_5,8,&param_6,8,0);
  return;
}



===== WPP_SF_qd @ 1c0001ed8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qd(undefined8 param_1,undefined2 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_47b6c69f5b1a3b695cff7f911cf6702a_Traceguids,param_2,&local_res20,8,
             &param_5,4,0);
  return;
}



===== WPP_SF_qq @ 1c0001f30 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
              undefined1 param_5)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_47b6c69f5b1a3b695cff7f911cf6702a_Traceguids,0x20,&local_res20,8,
             &param_5,8,0);
  return;
}



===== WPP_SF_qqq @ 1c0001f88 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void WPP_SF_qqq(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined1 param_5,undefined1 param_6)

{
  undefined8 local_res20;
  
  local_res20 = param_4;
  (*pfnWppTraceMessage)
            (param_1,0x2b,&WPP_47b6c69f5b1a3b695cff7f911cf6702a_Traceguids,0xf,&local_res20,8,
             &param_5,8,&param_6,8,0);
  return;
}



===== WppClassicProviderCallback @ 1c0001ff0 =====

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



===== ScmBttClose @ 1c0002024 =====

void ScmBttClose(longlong param_1)

{
  btt_fini(*(longlong *)(param_1 + 0x30));
  if (*(longlong *)(param_1 + 0x40) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x40),0);
  }
  if (*(longlong *)(param_1 + 0x110) != 0) {
    ExFreePoolWithTag(*(longlong *)(param_1 + 0x110),0);
    *(undefined8 *)(param_1 + 0x110) = 0;
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== ScmBttOpenMappedPool @ 1c0002090 =====

void ScmBttOpenMappedPool(undefined8 param_1,undefined8 param_2)

{
  pmemblk_load_mapped_pool(param_1,param_2);
  return;
}



===== ScmBttGetDataOffsetForBlock @ 1c00020ac =====

ulonglong ScmBttGetDataOffsetForBlock(longlong param_1,ulonglong param_2,longlong *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined1 local_res8 [8];
  
  local_res8[0] = 0;
  uVar1 = lane_enter(param_1,local_res8);
  uVar2 = btt_get_data_block_offset_for_lba
                    (*(longlong *)(param_1 + 0x30),(int)uVar1,param_2,param_3);
  KeReleaseSpinLock(*(longlong *)(param_1 + 0x40) + (longlong)(int)uVar1 * 8,local_res8[0]);
  return uVar2 & 0xffffffff;
}



===== ScmBttGetPoolIoCallbackContext @ 1c0002124 =====

undefined8 ScmBttGetPoolIoCallbackContext(longlong param_1)

{
  return *(undefined8 *)(param_1 + 0x58);
}



===== ScmBttGetUsableBlockCount @ 1c0002130 =====

undefined8 ScmBttGetUsableBlockCount(longlong param_1)

{
  return *(undefined8 *)(*(longlong *)(param_1 + 0x30) + 0x48);
}



===== ScmBttInitializeLayout @ 1c0002140 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 ScmBttInitializeLayout(longlong param_1,undefined8 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_48;
  iVar1 = ExUuidCreate(&local_28);
  if ((iVar1 != 0) && (iVar1 != 0x40020056)) {
    local_28 = 0;
    uStack_20 = 0;
  }
  if (*(int *)(*(longlong *)(param_1 + 0x30) + 0x10) == 0) {
    uVar2 = write_layout(*(longlong *)(param_1 + 0x30),param_2,1,(undefined4 *)&local_28);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



===== ScmBttPopulateNsCallbacks @ 1c00021b8 =====

undefined8 ScmBttPopulateNsCallbacks(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong in_RAX;
  
  if (param_1 == (longlong *)0x0) {
    *param_2 = (longlong)nsread;
    param_2[1] = (longlong)nswrite;
    param_2[2] = (longlong)nsread_mapped;
    param_2[3] = (longlong)nswrite_mapped;
    param_2[4] = (longlong)nszero;
    param_2[5] = (longlong)nsmap;
    param_2[6] = (longlong)nsunmap;
    param_2[7] = (longlong)nsis_memory_range_good;
  }
  else {
    in_RAX = *param_1;
    if (((((in_RAX == 0) || (lVar1 = param_1[1], lVar1 == 0)) || (lVar2 = param_1[2], lVar2 == 0))
        || ((lVar3 = param_1[3], lVar3 == 0 || (lVar4 = param_1[4], lVar4 == 0)))) ||
       ((lVar5 = param_1[5], lVar5 == 0 ||
        ((lVar6 = param_1[6], lVar6 == 0 || (lVar7 = param_1[7], lVar7 == 0)))))) {
      return in_RAX & 0xffffffffffffff00;
    }
    *param_2 = in_RAX;
    param_2[1] = lVar1;
    param_2[2] = lVar2;
    param_2[3] = lVar3;
    param_2[4] = lVar4;
    param_2[5] = lVar5;
    param_2[6] = lVar6;
    param_2[7] = lVar7;
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== ScmBttWriteTraceEvent @ 1c0002274 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void ScmBttWriteTraceEvent
               (longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined8 local_res20;
  
  if (g_writeTraceEvent != (code *)0x0) {
    uVar1 = 0;
    if (param_1 != 0) {
      uVar1 = *(undefined8 *)(param_1 + 0x58);
    }
    local_res20 = param_4;
    (*g_writeTraceEvent)(uVar1,param_2,param_3,&local_res20);
  }
  return;
}



===== lane_enter @ 1c00022b4 =====

ulonglong lane_enter(longlong param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  ulonglong uVar2;
  
  uVar2 = KeGetCurrentProcessorNumberEx(0);
  uVar2 = (uVar2 & 0xffffffff) % (ulonglong)*(uint *)(param_1 + 0x38);
  uVar1 = KeAcquireSpinLockRaiseToDpc(*(longlong *)(param_1 + 0x40) + (longlong)(int)uVar2 * 8);
  *param_2 = uVar1;
  return uVar2;
}



===== nsio_callout @ 1c0002310 =====

void nsio_callout(longlong *param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((char)param_1[4] == '\0') {
    uVar2 = nsread_mapped(*param_1,(ulonglong)*(uint *)(param_1 + 3),param_2,(void *)param_1[1],
                          param_1[2],0);
    iVar1 = (int)uVar2;
  }
  else {
    iVar1 = nswrite_mapped(*param_1,(ulonglong)*(uint *)(param_1 + 3),param_2,(void *)param_1[1],
                           param_1[2],0);
  }
  *(int *)((longlong)param_1 + 0x1c) = iVar1;
  return;
}



===== nsis_memory_range_good @ 1c0002360 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong nsis_memory_range_good(longlong param_1,longlong param_2,longlong param_3)

{
  ulonglong uVar1;
  undefined8 uVar2;
  
  uVar1 = param_2 + param_3;
  if (*(ulonglong *)(param_1 + 0x20) < uVar1) {
    uVar1 = ScmBttWriteTraceEvent
                      (param_1,2,
                       "BTT: nsis_memory_range_good: offset + count (%lld) past end of data area (%zu)"
                       ,uVar1);
  }
  else {
    uVar2 = (**(code **)(param_1 + 0x68))
                      (*(undefined8 *)(param_1 + 0x58),param_2 + *(longlong *)(param_1 + 8));
    if ((char)uVar2 != '\0') {
      return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
    }
    uVar1 = ScmBttWriteTraceEvent
                      (param_1,2,
                       "BTT: nis_memory_range_good: offset + count (%lld) is in a bad memory region"
                       ,uVar1);
  }
  return uVar1 & 0xffffffffffffff00;
}



===== nsmap @ 1c00023e0 =====

ulonglong nsmap(longlong param_1,undefined8 param_2,longlong *param_3,ulonglong param_4,
               longlong param_5)

{
  ulonglong uVar1;
  longlong lVar2;
  
  if (*(ulonglong *)(param_1 + 0x20) < param_4 + param_5) {
    ScmBttWriteTraceEvent
              (param_1,2,"BTT: nsmap: offset + count (%lld) past end of data area (%zu)",
               param_4 + param_5);
    uVar1 = 0xffffffffffffffff;
  }
  else {
    if (*(int *)(param_1 + 0x48) == 1) {
      lVar2 = *(longlong *)(param_1 + 0x50) + param_5;
    }
    else {
      lVar2 = MmMapIoSpaceEx(*(longlong *)(param_1 + 8) + param_5,param_4,4);
    }
    *param_3 = lVar2;
    uVar1 = -(ulonglong)(lVar2 != 0) & param_4;
  }
  return uVar1;
}



===== nsread @ 1c0002470 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
nsread(longlong param_1,undefined4 param_2,undefined8 param_3,ulonglong param_4,longlong param_5)

{
  int iVar1;
  longlong local_38;
  undefined8 local_30;
  ulonglong local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  undefined4 local_17;
  undefined2 local_13;
  undefined1 local_11;
  
  if (*(ulonglong *)(param_1 + 0x20) < param_4 + param_5) {
    ScmBttWriteTraceEvent
              (param_1,2,"BTT: nsread: offset + count (%lld) past end of data area (%zu)",
               param_4 + param_5);
    local_1c = 0xffffffff;
  }
  else {
    local_1c = 0;
    local_17 = 0;
    local_13 = 0;
    local_11 = 0;
    local_18 = 0;
    local_38 = param_1;
    local_30 = param_3;
    local_28 = param_4;
    local_20 = param_2;
    iVar1 = (**(code **)(param_1 + 0x60))
                      (*(undefined8 *)(param_1 + 0x58),*(longlong *)(param_1 + 8) + param_5,
                       param_4 & 0xffffffff,nsio_callout,&local_38);
    if (iVar1 < 0) {
      if (iVar1 == -0x3fffffc2) {
        local_1c = 0xfffffffe;
      }
      else {
        local_1c = 0xffffffff;
        if (iVar1 == -0x3fffff66) {
          local_1c = 0xfffffffd;
        }
      }
    }
  }
  return local_1c;
}



===== nsread_mapped @ 1c0002540 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
nsread_mapped(longlong param_1,undefined8 param_2,longlong param_3,void *param_4,size_t param_5,
             longlong param_6)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (param_3 == 0) {
LAB_1c00025af:
    uVar3 = 0xfffffffe;
  }
  else {
    iVar2 = (**(code **)(param_1 + 0x70))(*(undefined8 *)(param_1 + 0x58));
    if (iVar2 != 0) {
      uVar3 = MmGetPhysicalAddress((void *)(param_6 + param_3));
      cVar1 = (**(code **)(param_1 + 0x68))(*(undefined8 *)(param_1 + 0x58),uVar3,param_5);
      if (cVar1 == '\0') goto LAB_1c00025af;
    }
    memcpy(param_4,(void *)(param_6 + param_3),param_5);
    uVar3 = 0;
  }
  return uVar3;
}



===== nsunmap @ 1c00025d0 =====

void nsunmap(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  if (*(int *)(param_1 + 0x48) != 1) {
    MmUnmapIoSpace(param_3,param_4);
  }
  return;
}



===== nswrite @ 1c0002600 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
nswrite(longlong param_1,undefined4 param_2,undefined8 param_3,ulonglong param_4,longlong param_5)

{
  int iVar1;
  longlong local_38;
  undefined8 local_30;
  ulonglong local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  undefined4 local_17;
  undefined2 local_13;
  undefined1 local_11;
  
  if (*(ulonglong *)(param_1 + 0x20) < param_4 + param_5) {
    ScmBttWriteTraceEvent
              (param_1,2,"BTT: nswrite: offset + count (%lld) past end of data area (%zu)",
               param_4 + param_5);
    local_1c = 0xffffffff;
  }
  else {
    local_1c = 0;
    local_17 = 0;
    local_13 = 0;
    local_11 = 0;
    local_18 = 1;
    local_38 = param_1;
    local_30 = param_3;
    local_28 = param_4;
    local_20 = param_2;
    iVar1 = (**(code **)(param_1 + 0x60))
                      (*(undefined8 *)(param_1 + 0x58),*(longlong *)(param_1 + 8) + param_5,
                       param_4 & 0xffffffff,nsio_callout,&local_38);
    if (iVar1 < 0) {
      if (iVar1 == -0x3fffffc2) {
        local_1c = 0xfffffffe;
      }
      else {
        local_1c = 0xffffffff;
        if (iVar1 == -0x3fffff66) {
          local_1c = 0xfffffffd;
        }
      }
    }
  }
  return local_1c;
}



===== nswrite_mapped @ 1c00026d0 =====

int nswrite_mapped(longlong param_1,undefined8 param_2,longlong param_3,undefined8 param_4,
                  undefined8 param_5,longlong param_6)

{
  int iVar1;
  
  if (param_3 == 0) {
    iVar1 = -2;
  }
  else {
    iVar1 = RtlWriteNonVolatileMemory
                      (*(undefined8 *)(param_1 + 0xa0),param_6 + param_3,param_4,param_5,2);
    iVar1 = (-1 < iVar1) - 1;
  }
  return iVar1;
}



===== nszero @ 1c0002730 =====

undefined8 nszero(longlong param_1,undefined8 param_2,ulonglong param_3,longlong param_4)

{
  undefined8 uVar1;
  void *local_res8;
  
  if (*(ulonglong *)(param_1 + 0x20) < param_4 + param_3) {
    ScmBttWriteTraceEvent
              (param_1,2,"BTT: nszero: offset + count (%lld) past end of data area (%zu)",
               param_4 + param_3);
    uVar1 = 0xffffffff;
  }
  else {
    local_res8 = (void *)0x0;
    nsmap(param_1,param_2,(longlong *)&local_res8,param_3,param_4);
    if (local_res8 == (void *)0x0) {
      uVar1 = 0xfffffffd;
    }
    else {
      memset(local_res8,0,param_3);
      RtlFlushNonVolatileMemory(*(undefined8 *)(param_1 + 0xa0),local_res8,param_3,0);
      uVar1 = 0;
    }
  }
  return uVar1;
}



===== pmemblk_load_mapped_pool @ 1c00027d4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Removing unreachable block (ram,0x0001c000293f) */

longlong pmemblk_load_mapped_pool(undefined8 param_1,undefined8 param_2)

{
  ulonglong uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  undefined8 uVar8;
  longlong *plVar9;
  int *piVar10;
  longlong lVar11;
  int iVar12;
  char *pcVar13;
  ulonglong uVar14;
  undefined8 *in_stack_00000038;
  longlong local_68 [8];
  
  iVar12 = 0;
  piVar10 = (int *)0x0;
  lVar7 = ExAllocatePool2(0x40,0x118,0x20545442);
  if (lVar7 == 0) goto LAB_1c0002919;
  *(undefined8 *)(lVar7 + 0x10) = param_2;
  *(undefined8 *)(lVar7 + 0x20) = param_2;
  *(undefined8 *)(lVar7 + 8) = 0;
  *(undefined4 *)(lVar7 + 0x18) = 0;
  uVar8 = in_stack_00000038[1];
  *(undefined8 *)(lVar7 + 0x48) = *in_stack_00000038;
  *(undefined8 *)(lVar7 + 0x50) = uVar8;
  uVar8 = in_stack_00000038[3];
  *(undefined8 *)(lVar7 + 0x58) = in_stack_00000038[2];
  *(undefined8 *)(lVar7 + 0x60) = uVar8;
  uVar8 = in_stack_00000038[5];
  *(undefined8 *)(lVar7 + 0x68) = in_stack_00000038[4];
  *(undefined8 *)(lVar7 + 0x70) = uVar8;
  uVar8 = in_stack_00000038[7];
  *(undefined8 *)(lVar7 + 0x78) = in_stack_00000038[6];
  *(undefined8 *)(lVar7 + 0x80) = uVar8;
  uVar2 = *(undefined4 *)((longlong)in_stack_00000038 + 0x44);
  uVar3 = *(undefined4 *)(in_stack_00000038 + 9);
  uVar4 = *(undefined4 *)((longlong)in_stack_00000038 + 0x4c);
  *(undefined4 *)(lVar7 + 0x88) = *(undefined4 *)(in_stack_00000038 + 8);
  *(undefined4 *)(lVar7 + 0x8c) = uVar2;
  *(undefined4 *)(lVar7 + 0x90) = uVar3;
  *(undefined4 *)(lVar7 + 0x94) = uVar4;
  uVar2 = *(undefined4 *)((longlong)in_stack_00000038 + 0x54);
  uVar3 = *(undefined4 *)(in_stack_00000038 + 0xb);
  uVar4 = *(undefined4 *)((longlong)in_stack_00000038 + 0x5c);
  *(undefined4 *)(lVar7 + 0x98) = *(undefined4 *)(in_stack_00000038 + 10);
  *(undefined4 *)(lVar7 + 0x9c) = uVar2;
  *(undefined4 *)(lVar7 + 0xa0) = uVar3;
  *(undefined4 *)(lVar7 + 0xa4) = uVar4;
  iVar5 = KeQueryActiveProcessorCountEx(0xffff);
  if (iVar5 < 1) {
    iVar5 = 1;
  }
  memset(local_68,0,0x40);
  plVar9 = local_68;
  uVar8 = ScmBttPopulateNsCallbacks(*(longlong **)(lVar7 + 0x80),plVar9);
  if ((char)uVar8 == '\0') goto LAB_1c0002919;
  uVar6 = (*(code *)in_stack_00000038[5])(in_stack_00000038[2]);
  if (uVar6 == 0) {
    *(undefined8 *)(lVar7 + 0x110) = 0;
  }
  else {
    plVar9 = (longlong *)ExAllocatePool2(0x40,(ulonglong)uVar6 << 4,0x20545442);
    *(longlong **)(lVar7 + 0x110) = plVar9;
    if ((plVar9 == (longlong *)0x0) ||
       ((**(code **)(lVar7 + 0x78))
                  (*(undefined8 *)(lVar7 + 0x58),plVar9,uVar6,(uint *)(lVar7 + 0x108)),
       uVar6 < *(uint *)(lVar7 + 0x108))) goto LAB_1c0002919;
  }
  uVar1 = *(ulonglong *)(lVar7 + 0x98);
  uVar14 = 0x8000000000;
  if (uVar1 == 0) {
LAB_1c00029e2:
    piVar10 = btt_init(*(ulonglong *)(lVar7 + 0x20),plVar9,uVar14,(undefined8 *)(lVar7 + 0x88),
                       iVar5 * 2,lVar7,local_68,*(undefined8 *)(lVar7 + 8),*(int *)(lVar7 + 0x48));
    if (piVar10 != (int *)0x0) {
      *(int **)(lVar7 + 0x30) = piVar10;
      iVar5 = *piVar10;
      *(int *)(lVar7 + 0x38) = iVar5;
      *(undefined4 *)(lVar7 + 0x3c) = 0;
      lVar11 = ExAllocatePool2(0x40,(longlong)iVar5 << 3,0x20545442);
      if (lVar11 != 0) {
        if (0 < *(int *)(lVar7 + 0x38)) {
          do {
            KeInitializeSpinLock(lVar11 + (longlong)iVar12 * 8);
            iVar12 = iVar12 + 1;
          } while (iVar12 < *(int *)(lVar7 + 0x38));
        }
        *(longlong *)(lVar7 + 0x40) = lVar11;
        return lVar7;
      }
    }
  }
  else {
    if (uVar1 < 0x8000000001) {
      uVar14 = uVar1;
      if (0xffffff < uVar1) goto LAB_1c00029e2;
      pcVar13 = "BTT: pmemblk_load_mapped_pool: maxarenasize too small (%llu)";
    }
    else {
      pcVar13 = "BTT: pmemblk_load_mapped_pool: maxarenasize too large (%llu)";
    }
    ScmBttWriteTraceEvent(lVar7,2,pcVar13,uVar1);
  }
LAB_1c0002919:
  if (*(longlong *)(lVar7 + 0x110) != 0) {
    ExFreePoolWithTag(*(longlong *)(lVar7 + 0x110),0);
    *(undefined8 *)(lVar7 + 0x110) = 0;
  }
  if (piVar10 != (int *)0x0) {
    btt_fini((longlong)piVar10);
  }
  ExFreePoolWithTag(lVar7,0);
  return 0;
}



===== btt_fini @ 1c0002a88 =====

void btt_fini(longlong param_1)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  
  if (*(longlong *)(param_1 + 0x70) != 0) {
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x50)) {
      lVar3 = 0;
      do {
        lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x70) + 0x60 + lVar3);
        if (lVar1 != 0) {
          ExFreePoolWithTag(lVar1,0);
        }
        lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x70) + 0x68 + lVar3);
        if (lVar1 != 0) {
          ExFreePoolWithTag(lVar1,0);
        }
        lVar1 = *(longlong *)(*(longlong *)(param_1 + 0x70) + 0x70 + lVar3);
        if (lVar1 != 0) {
          ExFreePoolWithTag(lVar1,0);
        }
        FreePremappedVirtualAddresses
                  (param_1,(longlong *)
                           (*(longlong *)(param_1 + 0x70) + 0x48 + (longlong)iVar2 * 0x80),
                   *(uint *)(lVar3 + 0x58 + *(longlong *)(param_1 + 0x70)));
        FreePremappedVirtualAddresses
                  (param_1,(longlong *)
                           (*(longlong *)(param_1 + 0x70) + 0x50 + (longlong)iVar2 * 0x80),
                   *(uint *)(lVar3 + 0x5c + *(longlong *)(param_1 + 0x70)));
        iVar2 = iVar2 + 1;
        lVar3 = lVar3 + 0x80;
      } while (iVar2 < *(int *)(param_1 + 0x50));
    }
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x70),0);
  }
  ExFreePoolWithTag(param_1,0);
  return;
}



===== btt_get_data_block_offset_for_lba @ 1c0002b90 =====

undefined8
btt_get_data_block_offset_for_lba
          (longlong param_1,undefined4 param_2,ulonglong param_3,longlong *param_4)

{
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint local_res8 [2];
  uint local_res18 [2];
  longlong local_18 [2];
  
  if (param_3 < *(ulonglong *)(param_1 + 0x48)) {
    if (*(int *)(param_1 + 0x10) != 0) {
      local_18[0] = 0;
      local_res18[0] = 0;
      uVar3 = lba_to_arena_lba(param_1,param_3,local_18,local_res18);
      lVar2 = local_18[0];
      uVar1 = local_res18[0];
      if (-1 < (int)uVar3) {
        local_res8[0] = 0;
        uVar3 = read_map_entry(param_1,local_18[0],param_2,(ulonglong)(local_res18[0] * 4),
                               local_res8);
        if ((int)uVar3 < 0) {
          return uVar3;
        }
        if ((local_res8[0] & 0xc0000000) == 0) {
          local_res8[0] = uVar1;
        }
        *param_4 = (ulonglong)(local_res8[0] & 0x3fffffff) * (ulonglong)*(uint *)(lVar2 + 8) +
                   *(longlong *)(lVar2 + 0x18);
        return 0;
      }
    }
  }
  else {
    ScmBttWriteTraceEvent
              (*(longlong *)(param_1 + 0x78),2,"BTT: invalid_lba: lba out of range (nlba %ju)",
               *(ulonglong *)(param_1 + 0x48));
  }
  return 0xffffffff;
}



===== btt_init @ 1c0002c6c =====

int * btt_init(ulonglong param_1,undefined8 param_2,undefined8 param_3,undefined8 *param_4,
              int param_5,longlong param_6,undefined8 *param_7,undefined8 param_8,int param_9)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int *piVar4;
  undefined8 uVar5;
  longlong lVar6;
  
  if (param_1 < 0x1000000) {
    ScmBttWriteTraceEvent(param_6,2,"BTT: btt_init: rawsize smaller than BTT_MIN_SIZE %u",0x1000000)
    ;
  }
  else {
    lVar6 = 0x100;
    piVar4 = (int *)ExAllocatePool2(0x40,0x100,0x20545442);
    if (piVar4 != (int *)0x0) {
      KeInitializeSpinLock(piVar4 + 2);
      uVar5 = *param_4;
      uVar1 = param_4[1];
      *(longlong *)(piVar4 + 0x1e) = param_6;
      *(undefined8 *)(piVar4 + 9) = uVar5;
      *(undefined8 *)(piVar4 + 0xb) = uVar1;
      *(ulonglong *)(piVar4 + 0xe) = param_1;
      piVar4[0x10] = 0x1000;
      uVar5 = param_7[1];
      uVar1 = param_7[2];
      uVar2 = param_7[3];
      *(undefined8 *)(piVar4 + 0x20) = *param_7;
      *(undefined8 *)(piVar4 + 0x22) = uVar5;
      *(undefined8 *)(piVar4 + 0x16) = param_3;
      uVar5 = param_7[4];
      uVar3 = param_7[5];
      *(undefined8 *)(piVar4 + 0x24) = uVar1;
      *(undefined8 *)(piVar4 + 0x26) = uVar2;
      uVar1 = param_7[6];
      uVar2 = param_7[7];
      *(undefined8 *)(piVar4 + 0x18) = param_8;
      *(undefined8 *)(piVar4 + 0x28) = uVar5;
      *(undefined8 *)(piVar4 + 0x2a) = uVar3;
      piVar4[0x1a] = param_9;
      *(undefined8 *)(piVar4 + 0x2c) = uVar1;
      *(undefined8 *)(piVar4 + 0x2e) = uVar2;
      uVar5 = read_layout((longlong)piVar4,lVar6);
      if (-1 < (int)uVar5) {
        *piVar4 = piVar4[0x11];
        if ((param_5 != 0) && (param_5 < piVar4[0x11])) {
          *piVar4 = param_5;
        }
        return piVar4;
      }
      btt_fini((longlong)piVar4);
    }
  }
  return (int *)0x0;
}



===== lba_to_arena_lba @ 1c0002d90 =====

undefined8
lba_to_arena_lba(longlong param_1,ulonglong param_2,longlong *param_3,undefined4 *param_4)

{
  uint *puVar1;
  int iVar2;
  longlong lVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x50)) {
    puVar1 = (uint *)(*(longlong *)(param_1 + 0x70) + 4);
    lVar3 = 0;
    do {
      if (param_2 < *puVar1) break;
      param_2 = param_2 - *puVar1;
      iVar2 = iVar2 + 1;
      lVar3 = lVar3 + 1;
      puVar1 = puVar1 + 0x20;
    } while (lVar3 < *(int *)(param_1 + 0x50));
  }
  *param_3 = (longlong)iVar2 * 0x80 + *(longlong *)(param_1 + 0x70);
  *param_4 = (int)param_2;
  return 0;
}



===== read_arena @ 1c0002df8 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 read_arena(longlong param_1,undefined8 param_2,longlong param_3,uint *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined1 local_1078 [32];
  undefined1 local_1038 [48];
  uint local_1008;
  uint local_ffc;
  uint local_ff8;
  uint local_ff4;
  longlong local_fe8;
  longlong local_fe0;
  longlong local_fd8;
  longlong local_fd0;
  longlong local_fc8;
  ulonglong local_38;
  undefined8 uStack_30;
  
  uStack_30 = 0x1c0002e0e;
  local_38 = __security_cookie ^ (ulonglong)local_1078;
  memset(local_1038,0,0x1000);
  uVar2 = (**(code **)(param_1 + 0x80))(*(undefined8 *)(param_1 + 0x78),0,local_1038,0x1000);
  uVar6 = 0;
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  uVar9 = local_fe0 + param_3;
  uVar8 = local_fd8 + param_3;
  uVar5 = local_fd0 + param_3;
  *(longlong *)(param_4 + 0xc) = local_fe8 + param_3;
  *param_4 = local_1008;
  param_4[1] = local_ffc;
  param_4[2] = local_ff8;
  param_4[3] = local_ff4;
  *(longlong *)(param_4 + 4) = param_3;
  *(ulonglong *)(param_4 + 6) = uVar9;
  *(ulonglong *)(param_4 + 8) = uVar8;
  *(ulonglong *)(param_4 + 10) = uVar5;
  if ((uVar9 < uVar8) && (uVar8 < uVar5)) {
    uVar7 = uVar5 - uVar8;
    *(ulonglong *)(param_4 + 0xe) = uVar7;
    if (((uVar5 < (ulonglong)(local_fc8 + param_3)) &&
        (((*(ulonglong *)(param_4 + 0x10) = (local_fc8 + param_3) - uVar5, local_ff8 != 0 &&
          (uVar5 = (uVar8 - uVar9) % (ulonglong)local_ff8,
          (ulonglong)local_ff4 <= (uVar8 - uVar9) / (ulonglong)local_ff8)) &&
         (local_ffc <= local_ff4)))) && ((ulonglong)local_ffc <= uVar7 >> 2)) {
      if (*(int *)(param_1 + 0x68) == 3) {
        lVar3 = *(longlong *)(param_1 + 0x78);
        lVar1 = *(longlong *)(lVar3 + 8);
        uVar5 = AllocateAndFillInPremappedVirtualAddresses
                          (param_1,uVar8 + lVar1,uVar7,*(ulonglong **)(lVar3 + 0x110),
                           *(uint *)(lVar3 + 0x108),(longlong *)(param_4 + 0x12),param_4 + 0x16);
        if ((int)uVar5 < 0) goto LAB_1c0003074;
        uVar5 = *(longlong *)(param_4 + 10) + lVar1;
        uVar8 = AllocateAndFillInPremappedVirtualAddresses
                          (param_1,uVar5,*(longlong *)(param_4 + 0x10),
                           *(ulonglong **)(lVar3 + 0x110),*(uint *)(lVar3 + 0x108),
                           (longlong *)(param_4 + 0x14),param_4 + 0x17);
        if ((int)uVar8 < 0) goto LAB_1c0003074;
      }
      uVar2 = read_flogs(param_1,uVar5,param_4);
      if (-1 < (int)uVar2) {
        lVar3 = ExAllocatePool2(0x40,(ulonglong)*(uint *)(param_1 + 0x44) << 2,0x20545442);
        *(longlong *)(param_4 + 0x1a) = lVar3;
        if (lVar3 != 0) {
          uVar4 = 0;
          if (*(int *)(param_1 + 0x44) != 0) {
            do {
              uVar5 = (ulonglong)uVar4;
              uVar4 = uVar4 + 1;
              *(undefined4 *)(*(longlong *)(param_4 + 0x1a) + uVar5 * 4) = 0x40000000;
            } while (uVar4 < *(uint *)(param_1 + 0x44));
          }
          LOCK();
          UNLOCK();
          lVar3 = ExAllocatePool2(0x40,(ulonglong)*(uint *)(param_1 + 0x44) << 3,0x20545442);
          *(longlong *)(param_4 + 0x1c) = lVar3;
          if (lVar3 != 0) {
            if (*(int *)(param_1 + 0x44) != 0) {
              do {
                KeInitializeSpinLock(*(longlong *)(param_4 + 0x1c) + uVar6 * 8);
                uVar4 = (int)uVar6 + 1;
                uVar6 = (ulonglong)uVar4;
              } while (uVar4 < *(uint *)(param_1 + 0x44));
            }
            KeInitializeSpinLock(param_4 + 0x1e);
            return 0;
          }
        }
      }
    }
  }
LAB_1c0003074:
  ScmBttWriteTraceEvent
            (*(longlong *)(param_1 + 0x78),2,"Failed to read arena starting at offset 0x%llx",
             param_3);
  FreePremappedVirtualAddresses(param_1,(longlong *)(param_4 + 0x12),param_4[0x16]);
  FreePremappedVirtualAddresses(param_1,(longlong *)(param_4 + 0x14),param_4[0x17]);
  return 0xffffffff;
}



===== read_arenas @ 1c00030e0 =====

undefined8 read_arenas(longlong param_1,undefined8 param_2,uint param_3)

{
  uint *puVar1;
  undefined8 uVar2;
  longlong lVar3;
  int iVar4;
  longlong *plVar5;
  longlong lVar6;
  
  ScmBttWriteTraceEvent
            (*(longlong *)(param_1 + 0x78),4,"Reading %d arenas on lane %d",(ulonglong)param_3);
  lVar3 = (longlong)(int)param_3 << 7;
  puVar1 = (uint *)ExAllocatePool2(0x40);
  *(longlong *)(param_1 + 0x70) = (longlong)puVar1;
  if (puVar1 == (uint *)0x0) {
LAB_1c0003183:
    plVar5 = (longlong *)(param_1 + 0x70);
    if (*(longlong *)(param_1 + 0x70) != 0) {
      iVar4 = 0;
      if (0 < *(int *)(param_1 + 0x50)) {
        lVar3 = 0;
        do {
          lVar6 = *(longlong *)(*plVar5 + 0x60 + lVar3);
          if (lVar6 != 0) {
            ExFreePoolWithTag(lVar6,0);
          }
          lVar6 = *(longlong *)(*plVar5 + 0x68 + lVar3);
          if (lVar6 != 0) {
            ExFreePoolWithTag(lVar6,0);
          }
          lVar6 = *(longlong *)(*plVar5 + 0x70 + lVar3);
          if (lVar6 != 0) {
            ExFreePoolWithTag(lVar6,0);
          }
          FreePremappedVirtualAddresses
                    (param_1,(longlong *)(*plVar5 + 0x48 + (longlong)iVar4 * 0x80),
                     *(uint *)(*plVar5 + 0x58 + lVar3));
          FreePremappedVirtualAddresses
                    (param_1,(longlong *)(*plVar5 + 0x50 + (longlong)iVar4 * 0x80),
                     *(uint *)(*plVar5 + 0x5c + lVar3));
          iVar4 = iVar4 + 1;
          lVar3 = lVar3 + 0x80;
        } while (iVar4 < *(int *)(param_1 + 0x50));
      }
      ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x70),0);
      *(undefined8 *)(param_1 + 0x70) = 0;
    }
    uVar2 = 0xffffffff;
  }
  else {
    lVar6 = 0;
    iVar4 = 0;
    if (0 < (int)param_3) {
      do {
        uVar2 = read_arena(param_1,lVar3,lVar6,puVar1);
        if ((int)uVar2 < 0) goto LAB_1c0003183;
        lVar6 = *(longlong *)(puVar1 + 0xc);
        iVar4 = iVar4 + 1;
        puVar1 = puVar1 + 0x20;
      } while (iVar4 < (int)param_3);
    }
    *(undefined4 *)(param_1 + 0x10) = 1;
    uVar2 = 0;
  }
  return uVar2;
}



===== read_flog_pair @ 1c0003274 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong read_flog_pair(longlong param_1,undefined8 param_2,uint *param_3,longlong param_4,
                        undefined8 *param_5)

{
  undefined8 uVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint *puVar7;
  char *pcVar8;
  undefined1 auStackY_a8 [32];
  uint local_68 [2];
  longlong local_60;
  longlong local_58;
  uint local_50 [3];
  uint local_44;
  uint local_40 [3];
  uint uStack_34;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_a8;
  param_5[2] = param_4;
  param_5[3] = param_4 + 0x10;
  if (*(int *)(param_1 + 0x44) == 0) {
    ScmBttWriteTraceEvent
              (*(longlong *)(param_1 + 0x78),2,"BTT: read_flog_pair: invalid lane %d among nfree %d"
               ,0);
    return 0xffffffff;
  }
  if (param_4 == 0) {
    lVar6 = *(longlong *)(param_1 + 0x78);
    pcVar8 = "BTT: read_flog_pair: invalid flog offset %lu";
    uVar4 = 0;
LAB_1c00032c7:
    ScmBttWriteTraceEvent(lVar6,2,pcVar8,uVar4);
  }
  else {
    if (*(longlong *)(param_3 + 0x14) == 0) {
      uVar2 = (**(code **)(param_1 + 0x80))(*(undefined8 *)(param_1 + 0x78),0,local_50,0x20);
LAB_1c0003384:
      if ((int)uVar2 < 0) {
        ScmBttWriteTraceEvent
                  (*(longlong *)(param_1 + 0x78),2,
                   "BTT: read_flog_pair: failed to read flog pair (%d)",(ulonglong)uVar2);
        return (ulonglong)uVar2;
      }
      uVar2 = param_3[1];
      if (local_50[0] < uVar2) {
        if (local_40[0] < uVar2) {
          if (local_44 == uStack_34) {
            ScmBttWriteTraceEvent
                      (*(longlong *)(param_1 + 0x78),2,
                       "BTT: read_flog_pair: flog layout error: bad seq numbers %d %d",
                       (ulonglong)local_44);
            *param_3 = *param_3 | 1;
            return 0;
          }
          if ((local_44 == 0) ||
             ((uStack_34 != 0 &&
              (*(uint *)(&DAT_1c00069d8 + (ulonglong)(local_44 & 3) * 4) == uStack_34)))) {
            *(undefined4 *)(param_5 + 4) = 0;
            puVar7 = local_40;
          }
          else {
            *(undefined4 *)(param_5 + 4) = 1;
            puVar7 = local_50;
            local_40[0] = local_50[0];
          }
          uVar1 = *(undefined8 *)(puVar7 + 2);
          uVar2 = puVar7[2];
          *param_5 = *(undefined8 *)puVar7;
          param_5[1] = uVar1;
          if (puVar7[1] == uVar2) {
            return 0;
          }
          local_68[0] = 0;
          uVar4 = (ulonglong)(local_40[0] * 4);
          uVar5 = read_map_entry(param_1,(longlong)param_3,0,uVar4,local_68);
          if ((int)uVar5 < 0) {
            ScmBttWriteTraceEvent
                      (*(longlong *)(param_1 + 0x78),2,
                       "BTT: read_flog_pair() failed (%d) when reading the map entry for pre-map LBA 0x%x at 0x%llx"
                       ,uVar5 & 0xffffffff);
            return uVar5 & 0xffffffff;
          }
          if ((local_68[0] & 0xc0000000) == 0) {
            local_68[0] = *puVar7 | 0xc0000000;
          }
          if (puVar7[2] == local_68[0]) {
            return 0;
          }
          if (puVar7[1] != local_68[0]) {
            return 0;
          }
          local_68[0] = puVar7[2];
          iVar3 = (**(code **)(param_1 + 0x88))(*(undefined8 *)(param_1 + 0x78),0,local_68,4);
          if (-1 < iVar3) {
            return 0;
          }
          lVar6 = *(longlong *)(param_1 + 0x78);
          pcVar8 = 
          "BTT: nswrite() failed when recovering a transaction by updating the map entry at 0x%llx";
          goto LAB_1c00032c7;
        }
        ScmBttWriteTraceEvent
                  (0,2,"BTT: invalid_arena_lba: arena lba out of range (nlba %ju)",(ulonglong)uVar2)
        ;
        pcVar8 = "BTT: flog pair[1] specifies an invalid LBA (0x%x)";
      }
      else {
        ScmBttWriteTraceEvent
                  (0,2,"BTT: invalid_arena_lba: arena lba out of range (nlba %ju)",(ulonglong)uVar2)
        ;
        pcVar8 = "BTT: flog pair[0] specifies an invalid LBA (0x%x)";
      }
      uVar4 = (ulonglong)local_50[0];
      lVar6 = *(longlong *)(param_1 + 0x78);
    }
    else {
      local_58 = 0;
      local_60 = 0;
      uVar4 = GetPremappedAreaAddress
                        (*(longlong *)(param_3 + 0x14),param_3[0x17],
                         param_4 - *(longlong *)(param_3 + 10),0x20,&local_58,&local_60);
      lVar6 = *(longlong *)(param_1 + 0x78);
      if (-1 < (int)uVar4) {
        uVar2 = (**(code **)(param_1 + 0x90))(lVar6,0,local_58,local_50);
        goto LAB_1c0003384;
      }
      uVar4 = uVar4 & 0xffffffff;
      pcVar8 = "BTT: failed to get premapped flog address (0x%x)";
    }
    ScmBttWriteTraceEvent(lVar6,2,pcVar8,uVar4);
  }
  return 0xffffffff;
}



===== read_flogs @ 1c0003570 =====

undefined8 read_flogs(longlong param_1,undefined8 param_2,uint *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  size_t _Size;
  size_t sVar3;
  uint uVar4;
  undefined8 *puVar5;
  
  _Size = (ulonglong)*(uint *)(param_1 + 0x44) * 0x28;
  if (*(void **)(param_3 + 0x18) == (void *)0x0) {
    lVar1 = ExAllocatePool2(0x40,_Size,0x20545442);
    *(longlong *)(param_3 + 0x18) = lVar1;
    sVar3 = _Size;
    if (lVar1 == 0) {
      return 0xffffffff;
    }
  }
  else {
    sVar3 = 0;
    memset(*(void **)(param_3 + 0x18),0,_Size);
  }
  lVar1 = *(longlong *)(param_3 + 10);
  uVar4 = 0;
  puVar5 = *(undefined8 **)(param_3 + 0x18);
  if (*(int *)(param_1 + 0x44) != 0) {
    do {
      uVar2 = read_flog_pair(param_1,sVar3,param_3,lVar1,puVar5);
      if ((int)uVar2 < 0) {
        set_arena_error(param_1,param_3);
        ScmBttWriteTraceEvent
                  (*(longlong *)(param_1 + 0x78),2,
                   "Error reading flog pair 0x%x on arena starting at offset 0x%llx",
                   (ulonglong)uVar4);
        return 0xffffffff;
      }
      lVar1 = lVar1 + 0x40;
      puVar5 = puVar5 + 5;
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0x44));
  }
  return 0;
}



===== read_layout @ 1c0003664 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 read_layout(longlong param_1,longlong param_2)

{
  bool bVar1;
  undefined7 extraout_var;
  undefined8 uVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong uVar5;
  char *pcVar6;
  longlong lVar7;
  uint uVar8;
  longlong lVar9;
  undefined1 auStack_1068 [32];
  ulonglong local_1048;
  longlong local_1038;
  longlong local_1030;
  longlong local_1018;
  longlong local_1010;
  short local_1004;
  uint local_1000;
  uint local_ffc;
  uint local_ff0;
  ulonglong local_fe8;
  longlong local_40;
  ulonglong local_38;
  undefined8 local_30;
  
  local_30 = 0x1c000368d;
  local_38 = __security_cookie ^ (ulonglong)auStack_1068;
  uVar5 = *(ulonglong *)(param_1 + 0x38);
  uVar8 = 0;
  *(undefined4 *)(param_1 + 0x44) = 0x100;
  uVar4 = 0xffffffff;
  lVar9 = 0;
  lVar7 = 0;
  for (; 0xffffff < uVar5; uVar5 = uVar5 - local_fe8) {
    uVar8 = uVar8 + 1;
    memset(&local_1038,0,0x1000);
    lVar3 = 0;
    local_1048 = lVar7;
    uVar2 = (**(code **)(param_1 + 0x80))(*(undefined8 *)(param_1 + 0x78));
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    if (((((local_1038 != 0x4e4552415f545442) || (local_1030 != 0x4f464e495f41)) ||
         (bVar1 = util_checksum(&local_1038,lVar3,&local_40,0),
         (int)CONCAT71(extraout_var,bVar1) == 0)) || (local_1004 == 0)) ||
       ((((local_1018 != 0 || (local_1010 != 0)) &&
         ((*(longlong *)(param_1 + 0x24) != 0 || (*(longlong *)(param_1 + 0x2c) != 0)))) &&
        ((lVar3 = local_1010, local_1018 != *(longlong *)(param_1 + 0x24) ||
         (local_1010 != *(longlong *)(param_1 + 0x2c))))))) {
      uVar2 = write_layout(param_1,lVar3,0,(undefined4 *)0x0);
      return uVar2;
    }
    if (local_1000 != *(uint *)(param_1 + 0x40)) {
      local_1048 = CONCAT44(local_1048._4_4_,*(uint *)(param_1 + 0x40));
      ScmBttWriteTraceEvent
                (*(longlong *)(param_1 + 0x78),2,
                 "BTT: read_layout: inconsistent lbasize. info.external_lbasize = %d; bttp->lbasize = %d"
                 ,(ulonglong)local_1000);
      return 0xffffffff;
    }
    if (local_ff0 == 0) {
      pcVar6 = "BTT: read_layout: nfree can\'t be 0";
LAB_1c0003863:
      ScmBttWriteTraceEvent(*(longlong *)(param_1 + 0x78),2,pcVar6,(ulonglong)local_1000);
      return 0xffffffff;
    }
    if (local_ffc == 0) {
      pcVar6 = "BTT: read_layout: external_nlba can\'t be 0";
      goto LAB_1c0003863;
    }
    if (local_ff0 < uVar4) {
      uVar4 = local_ff0;
    }
    lVar9 = lVar9 + (ulonglong)local_ffc;
    lVar7 = lVar7 + local_fe8;
    param_2 = local_1010;
    if (local_fe8 == 0) break;
    if (uVar5 < local_fe8) {
      local_1048 = uVar5;
      ScmBttWriteTraceEvent
                (*(longlong *)(param_1 + 0x78),2,
                 "BTT: read_layout: next arena offset > rawsize (%llu, %llu)",local_fe8);
      return 0xffffffff;
    }
  }
  *(uint *)(param_1 + 0x50) = uVar8;
  *(longlong *)(param_1 + 0x48) = lVar9;
  if (uVar4 < *(uint *)(param_1 + 0x44)) {
    *(uint *)(param_1 + 0x44) = uVar4;
  }
  uVar2 = read_arenas(param_1,param_2,uVar8);
  return uVar2;
}



===== read_map_entry @ 1c00038b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
read_map_entry(longlong param_1,longlong param_2,undefined4 param_3,ulonglong param_4,
              undefined8 param_5)

{
  undefined8 uVar1;
  longlong local_res10 [3];
  longlong local_18 [2];
  
  if (*(longlong *)(param_2 + 0x48) == 0) {
    uVar1 = (**(code **)(param_1 + 0x80))
                      (*(undefined8 *)(param_1 + 0x78),param_3,param_5,4,
                       *(longlong *)(param_2 + 0x20) + param_4);
  }
  else {
    local_18[0] = 0;
    local_res10[0] = 0;
    uVar1 = GetPremappedAreaAddress
                      (*(longlong *)(param_2 + 0x48),*(uint *)(param_2 + 0x58),param_4,4,local_18,
                       local_res10);
    if ((int)uVar1 < 0) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = (**(code **)(param_1 + 0x90))
                        (*(undefined8 *)(param_1 + 0x78),param_3,local_18[0],param_5,4,
                         local_res10[0]);
    }
  }
  return uVar1;
}



===== set_arena_error @ 1c0003970 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 set_arena_error(longlong param_1,uint *param_2)

{
  longlong lVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined1 auStack_1068 [32];
  longlong local_1048;
  longlong local_1038 [6];
  uint local_1008;
  longlong local_fc8;
  longlong local_40;
  ulonglong local_38;
  undefined8 local_30;
  
  local_30 = 0x1c000398c;
  local_38 = __security_cookie ^ (ulonglong)auStack_1068;
  LOCK();
  *param_2 = *param_2 | 1;
  UNLOCK();
  uVar4 = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    lVar1 = *(longlong *)(param_2 + 4);
    memset(local_1038,0,0x1000);
    puVar5 = param_2 + 0x1e;
    uVar2 = KeAcquireSpinLockRaiseToDpc(puVar5);
    uVar4 = 0;
    local_1048 = lVar1;
    iVar3 = (**(code **)(param_1 + 0x80))(*(undefined8 *)(param_1 + 0x78),0,local_1038,0x1000);
    if (-1 < iVar3) {
      local_1008 = local_1008 | 1;
      util_checksum(local_1038,uVar4,&local_40,1);
      local_1048 = lVar1;
      iVar3 = (**(code **)(param_1 + 0x88))(*(undefined8 *)(param_1 + 0x78),0,local_1038,0x1000);
      if (-1 < iVar3) {
        local_1048 = local_fc8 + lVar1;
        iVar3 = (**(code **)(param_1 + 0x88))(*(undefined8 *)(param_1 + 0x78),0,local_1038,0x1000);
        if (-1 < iVar3) {
          KeReleaseSpinLock(puVar5,uVar2);
          return 0;
        }
      }
    }
    KeReleaseSpinLock(puVar5,uVar2);
    uVar4 = 0xffffffff;
  }
  return uVar4;
}



===== write_layout @ 1c0003ad8 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 write_layout(longlong param_1,undefined8 param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  undefined1 auStack_10d8 [32];
  ulonglong local_10b8;
  uint local_10a8;
  uint local_10a4;
  int local_10a0;
  longlong local_1098;
  longlong local_1090;
  ulonglong local_1088;
  ulonglong local_1080;
  longlong local_1078;
  longlong local_1070;
  longlong local_1068;
  longlong local_1060;
  ulonglong local_1058;
  undefined4 local_1050;
  uint local_104c;
  uint local_1048;
  undefined4 local_1044;
  longlong local_1038;
  char acStack_1030 [8];
  undefined8 local_1028;
  undefined8 uStack_1020;
  undefined8 local_1018;
  undefined8 uStack_1010;
  undefined4 local_1004;
  undefined4 local_1000;
  undefined4 local_ffc;
  uint local_ff8;
  undefined4 local_ff4;
  uint local_ff0;
  undefined4 local_fec;
  ulonglong local_fe8;
  undefined8 local_fe0;
  longlong local_fd8;
  longlong local_fd0;
  longlong local_fc8;
  longlong local_40;
  ulonglong local_38;
  undefined8 local_30;
  
  local_30 = 0x1c0003b01;
  local_38 = __security_cookie ^ (ulonglong)auStack_10d8;
  if (param_3 != 0) {
    uVar2 = *(undefined8 *)(param_4 + 2);
    *(undefined8 *)(param_1 + 0x14) = *(undefined8 *)param_4;
    *(undefined8 *)(param_1 + 0x1c) = uVar2;
  }
  uVar4 = *(ulonglong *)(param_1 + 0x38);
  iVar1 = (int)(uVar4 / *(ulonglong *)(param_1 + 0x58));
  *(int *)(param_1 + 0x50) = iVar1;
  if (0xffffff < uVar4 % *(ulonglong *)(param_1 + 0x58)) {
    *(int *)(param_1 + 0x50) = iVar1 + 1;
  }
  uVar5 = 0x200;
  iVar1 = *(int *)(param_1 + 0x44) * 0x40 + 0xfff;
  uVar3 = iVar1 >> 0x1f & 0xfff;
  uVar6 = (ulonglong)uVar3;
  local_10a0 = param_3;
  if ((*(uint *)(param_1 + 0x40) < 0x200) ||
     (uVar5 = *(uint *)(param_1 + 0x40) + 0xff & 0xffffff00, 0xff < uVar5)) {
    lVar8 = 0;
    lVar9 = 0;
    if (0xffffff < uVar4) {
      local_1090 = (longlong)(int)(iVar1 + uVar3 & 0xfffff000);
      local_1058 = (ulonglong)(uVar5 + 4);
      while( true ) {
        uVar7 = *(ulonglong *)(param_1 + 0x58);
        if (uVar4 <= *(ulonglong *)(param_1 + 0x58)) {
          uVar7 = uVar4;
        }
        uVar4 = uVar4 - uVar7;
        local_1088 = ((uVar7 - local_1090) - 0x3000) / local_1058;
        uVar3 = *(uint *)(param_1 + 0x44) * 2;
        uVar6 = (ulonglong)uVar3;
        if (local_1088 < uVar6) {
          local_10b8 = CONCAT44(local_10b8._4_4_,uVar3);
          ScmBttWriteTraceEvent
                    (*(longlong *)(param_1 + 0x78),2,
                     "BTT: write_layout: number of internal blocks: %lu expected at least %u",
                     local_1088);
          goto LAB_1c0003b9d;
        }
        lVar10 = local_1088 - *(uint *)(param_1 + 0x44);
        local_1060 = lVar9 + lVar10;
        if (param_3 != 0) {
          uVar6 = lVar10 * 4 + 0xfffU & 0xfffffffffffff000;
          local_1080 = 0;
          if (0xffffff < uVar4) {
            local_1080 = uVar7;
          }
          local_1068 = uVar7 - 0x1000;
          lVar9 = local_1068 - local_1090;
          local_1078 = lVar9 - uVar6;
          local_1070 = lVar9;
          iVar1 = (**(code **)(param_1 + 0xa0))
                            (*(undefined8 *)(param_1 + 0x78),0,uVar6,local_1078 + lVar8);
          if (iVar1 < 0) goto LAB_1c0003b9d;
          local_10a4 = *(uint *)(param_1 + 0x44);
          uVar6 = lVar9 + lVar8;
          local_10a8 = 0;
          local_1098 = lVar10;
          if (local_10a4 != 0) {
            do {
              local_1050 = 0;
              local_104c = (uint)local_1098 | 0x80000000;
              local_1044 = 1;
              local_10b8 = uVar6;
              local_1048 = local_104c;
              iVar1 = (**(code **)(param_1 + 0x88))
                                (*(undefined8 *)(param_1 + 0x78),0,&local_1050,0x10);
              if (iVar1 < 0) goto LAB_1c0003b9d;
              local_10b8 = uVar6 + 0x10;
              iVar1 = (**(code **)(param_1 + 0x88))
                                (*(undefined8 *)(param_1 + 0x78),0,&DAT_1c00069c8,0x10);
              if (iVar1 < 0) goto LAB_1c0003b9d;
              local_1098 = local_1098 + 1;
              local_10a4 = *(uint *)(param_1 + 0x44);
              local_10a8 = local_10a8 + 1;
              uVar6 = uVar6 + 0x5f & 0xffffffffffffffc0;
            } while (local_10a8 < local_10a4);
          }
          uVar2 = 0;
          memset(&local_1038,0,0x1000);
          lVar9 = local_1068;
          uVar7 = local_1080;
          local_1000 = *(undefined4 *)(param_1 + 0x40);
          local_1018 = *(undefined8 *)(param_1 + 0x24);
          uStack_1010 = *(undefined8 *)(param_1 + 0x2c);
          local_ff4 = (undefined4)local_1088;
          local_ff0 = local_10a4;
          local_fec = 0x1000;
          local_fe0 = 0x1000;
          local_1038._0_1_ = 'B';
          local_1038._1_1_ = 'T';
          local_1038._2_1_ = 'T';
          local_1038._3_1_ = '_';
          local_1038._4_1_ = 'A';
          local_1038._5_1_ = 'R';
          local_1038._6_1_ = 'E';
          local_1038._7_1_ = 'N';
          builtin_strncpy(acStack_1030,"A_INFO",7);
          acStack_1030[7] = '\0';
          local_fd8 = local_1078;
          local_1028 = *(undefined8 *)(param_1 + 0x14);
          uStack_1020 = *(undefined8 *)(param_1 + 0x1c);
          local_ffc = (undefined4)lVar10;
          local_fd0 = local_1070;
          local_1004 = 2;
          local_fe8 = local_1080;
          local_fc8 = local_1068;
          local_ff8 = uVar5;
          util_checksum(&local_1038,uVar2,&local_40,1);
          local_10b8 = lVar8;
          iVar1 = (**(code **)(param_1 + 0x88))
                            (*(undefined8 *)(param_1 + 0x78),0,&local_1038,0x1000);
          if (iVar1 < 0) goto LAB_1c0003b9d;
          local_10b8 = lVar9 + lVar8;
          uVar6 = 0;
          iVar1 = (**(code **)(param_1 + 0x88))
                            (*(undefined8 *)(param_1 + 0x78),0,&local_1038,0x1000);
          if (iVar1 < 0) goto LAB_1c0003b9d;
          lVar8 = lVar8 + uVar7;
          param_3 = local_10a0;
        }
        lVar9 = local_1060;
        if (uVar4 < 0x1000000) break;
      }
    }
    *(longlong *)(param_1 + 0x48) = lVar9;
    if (param_3 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = read_arenas(param_1,uVar6,*(uint *)(param_1 + 0x50));
    }
  }
  else {
    ScmBttWriteTraceEvent
              (*(longlong *)(param_1 + 0x78),2,
               "BTT: write_layout: Invalid lba size after alignment: %u ",(ulonglong)uVar5);
LAB_1c0003b9d:
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



===== util_checksum @ 1c0003ec0 =====

bool util_checksum(longlong *param_1,undefined8 param_2,longlong *param_3,int param_4)

{
  longlong *plVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  plVar1 = param_1 + 0x200;
  iVar4 = 0;
  iVar5 = 0;
  for (; param_1 < plVar1; param_1 = (longlong *)((longlong)param_1 + lVar2)) {
    if (param_1 == param_3) {
      iVar3 = iVar4 * 2;
    }
    else {
      iVar3 = iVar4 + (int)*param_1;
      iVar4 = iVar3;
    }
    iVar5 = iVar5 + iVar3;
    lVar2 = 8;
    if (param_1 != param_3) {
      lVar2 = 4;
    }
  }
  if (param_4 == 0) {
    bVar6 = *param_3 == CONCAT44(iVar5,iVar4);
  }
  else {
    *param_3 = CONCAT44(iVar5,iVar4);
    bVar6 = true;
  }
  return bVar6;
}



===== AllocateAndFillInPremappedVirtualAddresses @ 1c0003f3c =====

ulonglong AllocateAndFillInPremappedVirtualAddresses
                    (longlong param_1,ulonglong param_2,longlong param_3,ulonglong *param_4,
                    uint param_5,longlong *param_6,uint *param_7)

{
  uint uVar1;
  longlong *plVar2;
  uint *puVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  puVar3 = param_7;
  plVar2 = param_6;
  *param_6 = 0;
  *param_7 = 0;
  param_6._0_4_ = 0;
  uVar4 = FillInPremappedVirtualAddresses
                    (param_1,param_2,param_3,param_4,param_5,(longlong *)0x0,(uint *)&param_6);
  uVar1 = (uint)param_6;
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  lVar5 = ExAllocatePool2(0x40,(ulonglong)(uint)param_6 << 4,0x20545442);
  *plVar2 = lVar5;
  if (lVar5 == 0) {
    return 0xc000009a;
  }
  *puVar3 = uVar1;
  uVar4 = FillInPremappedVirtualAddresses
                    (param_1,param_2,param_3,param_4,param_5,(longlong *)*plVar2,puVar3);
  uVar6 = uVar4 & 0xffffffff;
  if (-1 < (int)uVar4) {
    if (*puVar3 == uVar1) {
      return uVar6;
    }
    uVar6 = 0xc0000001;
  }
  if (*plVar2 != 0) {
    ExFreePoolWithTag(*plVar2,0);
    *plVar2 = 0;
  }
  return uVar6;
}



===== FillInPremappedVirtualAddresses @ 1c0004050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
FillInPremappedVirtualAddresses
          (longlong param_1,ulonglong param_2,longlong param_3,ulonglong *param_4,uint param_5,
          longlong *param_6,uint *param_7)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  bool bVar4;
  uint *puVar5;
  uint uVar6;
  longlong *plVar7;
  undefined8 uVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  uint uVar12;
  ulonglong *puVar13;
  ulonglong uVar14;
  
  puVar5 = param_7;
  uVar1 = param_2 + param_3;
  uVar10 = 0;
  uVar9 = 0;
  param_7._0_4_ = 0;
  uVar2 = *puVar5;
  uVar11 = (ulonglong)uVar2;
  *puVar5 = 0;
  if (param_2 < uVar1) {
    if (param_5 == 0) {
LAB_1c0004234:
      if (uVar9 < uVar2) {
        plVar7 = param_6 + (ulonglong)uVar9 * 2;
        (**(code **)(param_1 + 0xa8))
                  (*(longlong *)(param_1 + 0x78),0,plVar7,uVar1 - param_2,
                   param_2 - *(longlong *)(*(longlong *)(param_1 + 0x78) + 8));
        plVar7[1] = uVar1 - param_2;
        if (*plVar7 == 0) {
LAB_1c0004270:
          uVar8 = 0xc000009a;
LAB_1c0004275:
          if (uVar2 == 0) {
            return uVar8;
          }
          do {
            if (*param_6 != 0) {
              MmUnmapIoSpace(*param_6,param_6[1]);
              *param_6 = 0;
            }
            param_6 = param_6 + 2;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
          return uVar8;
        }
      }
      uVar9 = uVar9 + 1;
    }
    else {
      do {
        uVar12 = 0;
        uVar14 = 0xffffffffffffffff;
        bVar4 = false;
        uVar9 = (uint)uVar10;
        puVar13 = param_4;
        uVar6 = (uint)param_7;
        do {
          uVar3 = *puVar13;
          if (param_2 < uVar3) {
            if (uVar14 <= uVar3 - param_2) {
              if (bVar4) goto LAB_1c00040fb;
            }
            bVar4 = true;
            uVar14 = uVar3 - param_2;
            uVar6 = uVar12;
            param_7._0_4_ = uVar12;
          }
          else {
            if (param_2 < uVar3 + puVar13[1]) {
              param_7._0_4_ = uVar12;
              goto LAB_1c000411e;
            }
            uVar6 = (uint)param_7;
          }
LAB_1c00040fb:
          uVar12 = uVar12 + 1;
          puVar13 = puVar13 + 2;
        } while (uVar12 < param_5);
        param_7._0_4_ = uVar6;
        if (!bVar4) {
          if (param_2 < uVar1) goto LAB_1c0004234;
          break;
        }
LAB_1c000411e:
        puVar13 = param_4 + (ulonglong)(uint)param_7 * 2;
        uVar3 = *puVar13;
        uVar14 = uVar3 + puVar13[1];
        if (uVar14 < uVar3) {
          ScmBttWriteTraceEvent
                    (*(longlong *)(param_1 + 0x78),2,
                     "Bad range length overflows: 0x%llx for 0x%llx bytes",uVar3);
          uVar8 = 0xc0000001;
          goto LAB_1c0004275;
        }
        if (param_2 < uVar3) {
          if (uVar9 < uVar2) {
            plVar7 = param_6 + uVar10 * 2;
            (**(code **)(param_1 + 0xa8))
                      (*(longlong *)(param_1 + 0x78),0,plVar7,uVar3 - param_2,
                       param_2 - *(longlong *)(*(longlong *)(param_1 + 0x78) + 8));
            plVar7[1] = uVar3 - param_2;
            if (*plVar7 == 0) goto LAB_1c0004270;
          }
          uVar10 = puVar13[1];
          uVar9 = uVar9 + 1;
          if (uVar9 < uVar2) {
            param_6[(ulonglong)uVar9 * 2] = 0;
            param_6[(ulonglong)uVar9 * 2 + 1] = uVar10;
          }
        }
        else if (uVar9 < uVar2) {
          param_6[uVar10 * 2] = 0;
          param_6[uVar10 * 2 + 1] = uVar14 - param_2;
        }
        uVar9 = uVar9 + 1;
        uVar10 = (ulonglong)uVar9;
        param_2 = uVar14;
      } while (uVar14 < uVar1);
    }
  }
  *puVar5 = uVar9;
  return 0;
}



===== FreePremappedVirtualAddresses @ 1c00042d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FreePremappedVirtualAddresses(longlong param_1,longlong *param_2,uint param_3)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  if (*param_2 != 0) {
    if (param_3 != 0) {
      lVar2 = 0;
      uVar3 = (ulonglong)param_3;
      do {
        lVar1 = *param_2;
        if (*(longlong *)(lVar2 + lVar1) != 0) {
          (**(code **)(param_1 + 0xb0))
                    (*(undefined8 *)(param_1 + 0x78),0,*(longlong *)(lVar2 + lVar1),
                     *(undefined8 *)(lVar2 + 8 + lVar1));
          *(undefined8 *)(lVar2 + lVar1) = 0;
          *(undefined8 *)(lVar2 + 8 + lVar1) = 0;
        }
        lVar2 = lVar2 + 0x10;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    ExFreePoolWithTag(*param_2,0);
    *param_2 = 0;
  }
  return;
}



===== GetPremappedAreaAddress @ 1c0004370 =====

undefined8
GetPremappedAreaAddress
          (longlong param_1,uint param_2,ulonglong param_3,longlong param_4,longlong *param_5,
          longlong *param_6)

{
  longlong *plVar1;
  ulonglong uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  if (param_2 != 0) {
    plVar1 = (longlong *)(param_1 + 8);
    do {
      if ((uVar2 <= param_3) && (param_3 + param_4 <= *plVar1 + uVar2)) {
        *param_5 = plVar1[-1];
        *param_6 = param_3 - uVar2;
        return 0;
      }
      uVar2 = uVar2 + *plVar1;
      uVar3 = uVar3 + 1;
      plVar1 = plVar1 + 2;
    } while (uVar3 < param_2);
  }
  *param_5 = 0;
  *param_6 = 0;
  return 0;
}



===== _guard_check_icall @ 1c00043f0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0004408 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c000442c =====

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



===== __chkstk @ 1c0004492 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __chkstk(void)

{
                    /* WARNING: Could not recover jumptable at 0x0001c0004492. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  return;
}



===== __cpu_features_init @ 1c00044b0 =====

/* WARNING: Removing unreachable block (ram,0x0001c000451a) */
/* WARNING: Removing unreachable block (ram,0x0001c00044c9) */
/* WARNING: Removing unreachable block (ram,0x0001c00044ba) */

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



===== __security_check_cookie @ 1c0004580 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c00045c0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c00045f0 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c00045f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0004620 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0004680 =====

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



===== memset @ 1c0004980 =====

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



===== __memset_repmovs @ 1c0004ac0 =====

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



===== __memset_query @ 1c0004b40 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0004bc0 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0004d00 =====

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



===== __memset_spec_plain @ 1c0004d80 =====

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



===== BttFltAddDevice @ 1c000b010 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BttFltAddDevice(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  ulonglong uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined2 uVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined8 *_Dst;
  undefined1 auStackY_b8 [32];
  char local_78 [8];
  longlong local_70;
  undefined8 local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStackY_b8;
  local_70 = 0;
  _Dst = (undefined8 *)0x0;
  local_58 = 0;
  puVar6 = &local_60;
  local_68 = 0;
  local_5c = 0;
  local_78[0] = '\0';
  local_60 = 1;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_38 = 0;
  uVar2 = BttFltInvokeIoctl(param_2,0x2d1400,puVar6,0xc,&local_50,0x20);
  uVar1 = (uint)uVar2;
  uVar2 = uVar2 & 0xffffffff;
  if ((int)uVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x26,puVar6,uVar1);
    }
LAB_1c000b12a:
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000b2e4;
    uVar5 = 10;
LAB_1c000b157:
    uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
  }
  else {
    puVar6 = (undefined4 *)0x0;
    uVar2 = BttFltInvokeIoctl(param_2,0x41018,0,0,&local_68,8);
    uVar4 = local_68;
    uVar1 = (uint)uVar2;
    uVar2 = uVar2 & 0xffffffff;
    if ((int)uVar1 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x27,puVar6,uVar1);
      }
      goto LAB_1c000b12a;
    }
    if ((char)uStack_38 != '\x0f') {
      if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
        return 0;
      }
      if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
        return 0;
      }
      if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
        return 0;
      }
      uVar5 = 0xb;
LAB_1c000b1a0:
      WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,puVar6,param_2);
      return 0;
    }
    uVar2 = BttFltContainsBttAddressAbstraction(param_2,local_78);
    uVar1 = (uint)uVar2;
    uVar2 = uVar2 & 0xffffffff;
    if (-1 < (int)uVar1) {
      if (local_78[0] == '\0') {
        if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
          return 0;
        }
        if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
          return 0;
        }
        if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
          return 0;
        }
        uVar5 = 0xd;
        goto LAB_1c000b1a0;
      }
      puVar6 = (undefined4 *)0x0;
      uVar1 = IoCreateDevice(param_1);
      uVar2 = (ulonglong)uVar1;
      if (-1 < (int)uVar1) {
        uVar7 = 0x70;
        _Dst = *(undefined8 **)(local_70 + 0x40);
        memset(_Dst,0,0x70);
        lVar3 = IoAttachDeviceToDeviceStack(local_70);
        _Dst[2] = lVar3;
        _Dst[3] = local_70;
        _Dst[0xb] = uVar4;
        if (lVar3 != 0) {
          *(undefined4 *)(local_70 + 0x48) = *(undefined4 *)(lVar3 + 0x48);
          *(undefined4 *)(local_70 + 0x34) = *(undefined4 *)(_Dst[2] + 0x34);
          *(uint *)(local_70 + 0x30) = *(uint *)(local_70 + 0x30) & 0xffffff7f;
          BttFltLinkDevice(_Dst);
          if ((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) {
            return 0;
          }
          if ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0) {
            return 0;
          }
          if ((byte)WPP_GLOBAL_Control[0x29] < 4) {
            return 0;
          }
          WPP_SF_qqq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,uVar7,_Dst[2],(char)_Dst[3],
                     (char)_Dst);
          return 0;
        }
        uVar2 = 0xc000000e;
        goto LAB_1c000b2e4;
      }
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c000b2e4;
      uVar5 = 0xe;
      goto LAB_1c000b157;
    }
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000b2e4;
    uVar4 = *(undefined8 *)(WPP_GLOBAL_Control + 0x18);
    uVar5 = 0xc;
  }
  WPP_SF_d(uVar4,uVar5,puVar6,uVar1);
LAB_1c000b2e4:
  if (local_70 != 0) {
    if (_Dst[2] != 0) {
      IoDetachDevice(_Dst[2]);
    }
    IoDeleteDevice(local_70);
  }
  return uVar2;
}



===== BttFltAllocateAndInitializeSrbContext @ 1c000b3b4 =====

longlong *
BttFltAllocateAndInitializeSrbContext(longlong param_1,longlong param_2,undefined4 param_3)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  longlong *_Dst;
  
  lVar2 = IoAllocateIrpEx(*(longlong *)(param_1 + 0x10),
                          *(undefined1 *)(*(longlong *)(param_1 + 0x10) + 0x4c),0);
  if (lVar2 != 0) {
    lVar3 = IoAllocateMdl(param_2,param_3,0,0,lVar2);
    if ((lVar3 != 0) &&
       (_Dst = (longlong *)ExAllocateFromLookasideListEx(&DAT_1c0008150), _Dst != (longlong *)0x0))
    {
      memset(_Dst,0,0x78);
      MmBuildMdlForNonPagedPool(lVar3);
      lVar1 = *(longlong *)(lVar2 + 0xb8);
      *(longlong *)(lVar2 + 8) = lVar3;
      *(longlong **)(lVar1 + -0x40) = _Dst + 1;
      *(undefined1 *)(lVar1 + -0x48) = 0xf;
      *(undefined8 *)(lVar1 + -0x20) = *(undefined8 *)(param_1 + 0x10);
      *_Dst = lVar2;
      *(undefined1 *)((longlong)_Dst + 0xf) = *(undefined1 *)(param_1 + 0x5f);
      _Dst[5] = (longlong)(_Dst + 0xc);
      *(undefined1 *)((longlong)_Dst + 0x13) = 0x12;
      *(undefined4 *)(_Dst + 3) = param_3;
      _Dst[4] = param_2;
      _Dst[7] = lVar2;
      return _Dst;
    }
    IoFreeIrp(lVar2);
    if (lVar3 != 0) {
      IoFreeMdl(lVar3);
    }
  }
  return (longlong *)0x0;
}



===== BttFltContainsBttAddressAbstraction @ 1c000b4e0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong BttFltContainsBttAddressAbstraction(undefined8 param_1,undefined1 *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  undefined1 auStackY_58 [32];
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStackY_58;
  *param_2 = 0;
  uStack_18 = uStack_18 & 0xffffff00;
  uVar3 = 0;
  local_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uVar1 = BttFltInvokeIoctl(param_1,0x2d19f0,0,0,&local_28,0x14);
  uVar2 = uVar1 & 0xffffffff;
  if ((int)uVar1 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x24,uVar3,(int)uVar1);
    }
  }
  else if ((char)local_28 != '\0') {
    if ((CONCAT44(uStack_20,uStack_24) != 0) || (CONCAT44(uStack_18,uStack_1c) != 0)) {
      if ((CONCAT44(uStack_20,uStack_24) == 0x4217173518633bfc) &&
         (CONCAT44(uStack_18,uStack_1c) == -0x72c7d6ddce83676)) {
        *param_2 = 1;
      }
      else {
        uVar2 = 0xc00000bb;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF__guid_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),&WPP_GLOBAL_Control,uVar3,
                         &uStack_24);
        }
      }
    }
  }
  return uVar2;
}



===== BttFltInvokeIoctl @ 1c000b604 =====

ulonglong BttFltInvokeIoctl(undefined8 param_1,undefined4 param_2,undefined8 param_3,
                           undefined4 param_4,undefined8 param_5,undefined4 param_6)

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



===== BttFltIoctl @ 1c000b700 =====

undefined4 BttFltIoctl(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined4 uVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  if (*(int *)(*(longlong *)(param_2 + 0xb8) + 0x18) == 0x700a0) {
    IoForwardIrpSynchronously(*(undefined8 *)(lVar1 + 0x10));
    if (*(int *)(param_2 + 0x30) < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x21,param_3,*(int *)(param_2 + 0x30));
      }
    }
    else if (0x27 < *(uint *)(*(longlong *)(param_2 + 0xb8) + 8)) {
      *(ulonglong *)(*(longlong *)(param_2 + 0x18) + 0x18) =
           (ulonglong)*(uint *)(lVar1 + 0x20) * *(longlong *)(lVar1 + 0x30);
    }
    uVar2 = *(undefined4 *)(param_2 + 0x30);
    *(undefined4 *)(param_2 + 0x30) = uVar2;
    IofCompleteRequest(param_2,0);
  }
  else {
    uVar2 = BttFltPassThrough(param_1,param_2);
  }
  return uVar2;
}



===== BttFltIsBttMetadataPresent @ 1c000b7bc =====

bool BttFltIsBttMetadataPresent(longlong param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  bool bVar4;
  
  bVar4 = false;
  lVar1 = ExAllocatePool2(0x40,*(undefined4 *)(param_1 + 0x20),0x63545442);
  if (lVar1 != 0) {
    lVar3 = lVar1;
    uVar2 = BttFltSynchronousReadWrite
                      (param_1,-0x78,lVar1,(ulonglong)*(uint *)(param_1 + 0x20),0,
                       (ulonglong)*(uint *)(param_1 + 0x20));
    if ((int)uVar2 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29])
         ) {
        WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x28,lVar3,(int)uVar2);
      }
    }
    else {
      lVar3 = RtlCompareMemory(lVar1,"BTT_ARENA_INFO",0x10);
      bVar4 = lVar3 == 0x10;
    }
    ExFreePoolWithTag(lVar1,0x63545442);
  }
  return bVar4;
}



===== BttFltNsMap @ 1c000b8a0 =====

ulonglong BttFltNsMap(longlong param_1,undefined8 param_2,longlong *param_3,ulonglong param_4,
                     ulonglong param_5)

{
  int iVar1;
  longlong lVar2;
  longlong lVar3;
  ulonglong uVar4;
  undefined2 uVar5;
  longlong *plVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  
  plVar6 = param_3;
  uVar7 = param_4;
  lVar2 = ScmBttGetPoolIoCallbackContext(param_1);
  if (*(char *)(lVar2 + 0x68) == '\0') {
    if (param_4 < 0x20000001) {
      if (param_5 <= uVar7 + param_5) {
        iVar1 = 0;
        uVar7 = (ulonglong)(*(int *)(lVar2 + 0x20) - 1);
        if (((param_5 & uVar7) == 0) && ((param_4 & uVar7) == 0)) {
          lVar3 = ExAllocatePool2(0x40,param_4,0x63545442);
          if (lVar3 != 0) {
            uVar7 = 0;
            if (param_4 != 0) {
              do {
                uVar8 = param_4 - uVar7;
                if (0x800000 < uVar8) {
                  uVar8 = 0x800000;
                }
                uVar4 = BttFltSynchronousReadWrite
                                  (lVar2,-0x78,uVar7 + lVar3,uVar8,uVar7 + param_5,uVar8);
                iVar1 = (int)uVar4;
                if (iVar1 < 0) {
                  ExFreePoolWithTag(lVar3,0x63545442);
                  goto LAB_1c000ba80;
                }
                uVar7 = uVar7 + uVar8;
              } while (uVar7 < param_4);
            }
            *param_3 = lVar3;
          }
        }
        else {
          iVar1 = -0x3fffff45;
          if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
             (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 &&
              (1 < (byte)WPP_GLOBAL_Control[0x29])))) {
            WPP_SF_IId(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,plVar6,param_5,
                       (char)param_4);
          }
        }
        goto LAB_1c000ba80;
      }
      iVar1 = -0x3fffff6b;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c000ba80;
      uVar5 = 0x2e;
    }
    else {
      iVar1 = -0x3ffffff3;
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c000ba80;
      uVar5 = 0x2d;
    }
  }
  else {
    iVar1 = -0x3fffff17;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000ba80;
    uVar5 = 0x2b;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar5,plVar6,iVar1);
LAB_1c000ba80:
  if (iVar1 < 0) {
    param_4 = 0;
  }
  return param_4;
}



===== BttFltNsRead @ 1c000bab0 =====

int BttFltNsRead(longlong param_1,undefined8 param_2,void *param_3,size_t param_4,ulonglong param_5)

{
  ulonglong uVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  void *pvVar7;
  ulonglong local_28;
  ulonglong local_20;
  
  local_20 = 0;
  local_28 = 0;
  pvVar7 = param_3;
  lVar3 = ScmBttGetPoolIoCallbackContext(param_1);
  if (*(char *)(lVar3 + 0x68) == '\0') {
    uVar4 = BttFltAlignOffsets(lVar3,param_5,param_4,&local_20,(longlong *)&local_28);
    uVar6 = local_28;
    iVar2 = (int)uVar4;
    if (-1 < iVar2) {
      lVar5 = ExAllocatePool2(0x40,local_28,0x69545442);
      uVar1 = local_20;
      if (lVar5 == 0) {
        iVar2 = -0x3fffff66;
      }
      else {
        uVar6 = BttFltSynchronousReadWrite(lVar3,-0x78,lVar5,uVar6,local_20,uVar6);
        iVar2 = (int)uVar6;
        if (-1 < iVar2) {
          memcpy(param_3,(void *)((lVar5 - uVar1) + param_5),param_4);
        }
        ExFreePoolWithTag(lVar5,0x69545442);
      }
    }
  }
  else {
    iVar2 = -0x3fffff17;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,pvVar7,0xc00000e9);
    }
  }
  return iVar2 >> 0x1f;
}



===== BttFltNsWrite @ 1c000bc00 =====

int BttFltNsWrite(longlong param_1,undefined8 param_2,void *param_3,size_t param_4,ulonglong param_5
                 )

{
  ulonglong uVar1;
  int iVar2;
  longlong lVar3;
  undefined8 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  void *pvVar8;
  ulonglong local_38;
  ulonglong local_30;
  
  local_30 = 0;
  local_38 = 0;
  pvVar8 = param_3;
  lVar3 = ScmBttGetPoolIoCallbackContext(param_1);
  if (*(char *)(lVar3 + 0x68) != '\0') {
    iVar2 = -0x3fffff17;
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (1 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2b,pvVar8,0xc00000e9);
    }
    goto LAB_1c000bd65;
  }
  uVar4 = BttFltAlignOffsets(lVar3,param_5,param_4,&local_30,(longlong *)&local_38);
  uVar7 = local_38;
  iVar2 = (int)uVar4;
  if (iVar2 < 0) goto LAB_1c000bd65;
  lVar5 = ExAllocatePool2(0x40,local_38,0x69545442);
  uVar1 = local_30;
  if (lVar5 == 0) {
    iVar2 = -0x3fffff66;
    goto LAB_1c000bd65;
  }
  if ((param_5 == local_30) && (param_4 == uVar7)) {
LAB_1c000bd0f:
    memcpy((void *)((lVar5 - uVar1) + param_5),param_3,param_4);
    lVar3 = ScmBttGetPoolIoCallbackContext(param_1);
    uVar7 = BttFltSynchronousReadWrite(lVar3,-0x76,lVar5,uVar7,uVar1,uVar7);
    iVar2 = (int)uVar7;
  }
  else {
    uVar6 = BttFltSynchronousReadWrite(lVar3,-0x78,lVar5,uVar7,local_30,uVar7);
    iVar2 = (int)uVar6;
    if (-1 < iVar2) goto LAB_1c000bd0f;
  }
  ExFreePoolWithTag(lVar5,0x69545442);
LAB_1c000bd65:
  return iVar2 >> 0x1f;
}



===== BttFltNsZero @ 1c000bd90 =====

int BttFltNsZero(longlong param_1,undefined8 param_2,ulonglong param_3,ulonglong param_4)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined2 uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong local_28;
  ulonglong local_20;
  
  local_20 = 0;
  local_28 = 0;
  uVar7 = param_3;
  uVar8 = param_4;
  lVar2 = ScmBttGetPoolIoCallbackContext(param_1);
  if (*(char *)(lVar2 + 0x68) == '\0') {
    if (param_4 <= uVar7 + uVar8) {
      uVar3 = BttFltAlignOffsets(lVar2,param_4,uVar7,&local_20,(longlong *)&local_28);
      uVar8 = local_20;
      uVar7 = local_28;
      iVar1 = (int)uVar3;
      if (-1 < iVar1) {
        if ((param_4 == local_20) && (param_3 == local_28)) {
          uVar7 = 0;
          lVar4 = ExAllocatePool2(0x40,*(undefined4 *)(lVar2 + 0x20),0x69545442);
          if (lVar4 == 0) {
            return -1;
          }
          if (param_3 != 0) {
            do {
              uVar8 = param_3 - uVar7;
              if (0x800000 < uVar8) {
                uVar8 = 0x800000;
              }
              uVar5 = BttFltSynchronousReadWrite
                                (lVar2,-0x6d,lVar4,(ulonglong)*(uint *)(lVar2 + 0x20),
                                 uVar7 + param_4,uVar8);
              iVar1 = (int)uVar5;
            } while ((-1 < iVar1) && (uVar7 = uVar7 + uVar8, uVar7 < param_3));
          }
        }
        else {
          lVar4 = ExAllocatePool2(0x40,local_28,0x69545442);
          if (lVar4 == 0) {
            iVar1 = -0x3fffff66;
            goto LAB_1c000bf79;
          }
          uVar5 = BttFltSynchronousReadWrite(lVar2,-0x78,lVar4,uVar7,uVar8,uVar7);
          iVar1 = (int)uVar5;
          if (-1 < iVar1) {
            uVar7 = BttFltSynchronousReadWrite(lVar2,-0x76,lVar4,uVar7,uVar8,uVar7);
            iVar1 = (int)uVar7;
          }
        }
        ExFreePoolWithTag(lVar4,0x63545442);
      }
      goto LAB_1c000bf79;
    }
    iVar1 = -0x3fffff6b;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000bf79;
    uVar6 = 0x2c;
    iVar1 = -0x3fffff6b;
  }
  else {
    iVar1 = -0x3fffff17;
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000bf79;
    uVar6 = 0x2b;
    iVar1 = -0x3fffff17;
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar6,uVar7,iVar1);
LAB_1c000bf79:
  return iVar1 >> 0x1f;
}



===== BttFltPnp @ 1c000bfb0 =====

int BttFltPnp(longlong param_1,longlong param_2)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  
  lVar3 = *(longlong *)(param_2 + 0xb8);
  if (*(char *)(lVar3 + 1) == '\0') {
    iVar2 = BttFltStartDevice(param_1,param_2,lVar3);
  }
  else if (*(char *)(lVar3 + 1) == '\x02') {
    plVar1 = *(longlong **)(param_1 + 0x40);
    *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
    *(longlong *)(param_2 + 0xb8) = lVar3 + 0x48;
    iVar2 = IofCallDriver(plVar1[2]);
    BttFltUnlinkDevice(plVar1);
    if (plVar1[0xc] != 0) {
      ScmBttClose(plVar1[0xc]);
    }
    if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) && (3 < (byte)WPP_GLOBAL_Control[0x29]))
    {
      WPP_SF_qq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),param_2,lVar3,plVar1[2],(char)plVar1);
    }
    IoDetachDevice(plVar1[2]);
    IoDeleteDevice(plVar1[3]);
  }
  else {
    iVar2 = BttFltPassThrough(param_1,param_2);
  }
  return iVar2;
}



===== BttFltQueryDiskGeometry @ 1c000c084 =====

int BttFltQueryDiskGeometry(longlong param_1)

{
  ulonglong uVar1;
  undefined1 auVar2 [16];
  undefined8 uVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong *plVar6;
  ulonglong uVar7;
  uint uVar8;
  undefined8 uVar9;
  
  puVar5 = (undefined8 *)ExAllocatePool2(0x40,0x20,0x69545442);
  if (puVar5 == (undefined8 *)0x0) {
    iVar4 = -0x3fffff66;
  }
  else {
    uVar9 = 0x20;
    plVar6 = BttFltAllocateAndInitializeSrbContext(param_1,(longlong)puVar5,0x20);
    if (plVar6 == (longlong *)0x0) {
      iVar4 = -0x3fffff66;
    }
    else {
      BttFltSetSrbOpCode((longlong)(plVar6 + 1),-0x62);
      iVar4 = IoSynchronousCallDriver(*(undefined8 *)(param_1 + 0x10),*plVar6);
      if (iVar4 < 0) {
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x22,uVar9,iVar4);
        }
      }
      else {
        uVar3 = puVar5[1];
        *(undefined8 *)(param_1 + 0x38) = *puVar5;
        *(undefined8 *)(param_1 + 0x40) = uVar3;
        uVar3 = puVar5[3];
        *(undefined8 *)(param_1 + 0x48) = puVar5[2];
        *(undefined8 *)(param_1 + 0x50) = uVar3;
      }
      BttFltFreeSrbContext(plVar6);
    }
    ExFreePoolWithTag(puVar5,0x69545442);
    if (-1 < iVar4) {
      uVar8 = *(uint *)(param_1 + 0x40);
      uVar8 = uVar8 >> 0x18 | (uVar8 & 0xff0000) >> 8 | (uVar8 & 0xff00) << 8 | uVar8 << 0x18;
      *(uint *)(param_1 + 0x20) = uVar8;
      if (uVar8 == 0x1000) {
        uVar1 = *(ulonglong *)(param_1 + 0x38);
        uVar7 = uVar1 >> 0x38 | (uVar1 & 0xff000000000000) >> 0x28 |
                (uVar1 & 0xff0000000000) >> 0x18 | (uVar1 & 0xff00000000) >> 8 |
                (uVar1 & 0xff000000) << 8 | (uVar1 & 0xff0000) << 0x18 | (uVar1 & 0xff00) << 0x28 |
                uVar1 << 0x38;
        uVar1 = uVar7 + 1;
        if (uVar7 <= uVar1) {
          auVar2._8_8_ = 0;
          auVar2._0_8_ = uVar1;
          if (SUB168(ZEXT416(0x1000) * auVar2,8) == 0) {
            *(longlong *)(param_1 + 0x28) = SUB168(ZEXT416(0x1000) * auVar2,0);
            return 0;
          }
          *(undefined8 *)(param_1 + 0x28) = 0xffffffffffffffff;
        }
        iVar4 = -0x3fffff6b;
      }
      else {
        iVar4 = -0x3fffff45;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x23,uVar9,0xc00000bb);
        }
      }
    }
  }
  return iVar4;
}



===== BttFltStartDevice @ 1c000c1f4 =====

int BttFltStartDevice(longlong param_1,longlong param_2,undefined8 param_3)

{
  longlong lVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  undefined2 uVar7;
  undefined4 local_68 [4];
  longlong local_58;
  code *local_48;
  code *local_40;
  undefined *local_30;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  lVar5 = param_2;
  cVar2 = IoForwardIrpSynchronously(*(undefined8 *)(lVar1 + 0x10));
  if (cVar2 == '\0') {
    iVar4 = -0x3fffffff;
    goto LAB_1c000c4e9;
  }
  iVar4 = *(int *)(param_2 + 0x30);
  if (iVar4 < 0) {
    if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
        ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2))
    goto LAB_1c000c4e9;
    uVar7 = 0x17;
  }
  else {
    iVar4 = BttFltQueryDiskGeometry(lVar1);
    if (iVar4 < 0) {
      if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
          ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) || ((byte)WPP_GLOBAL_Control[0x29] < 2)
         ) goto LAB_1c000c4e9;
      uVar7 = 0x18;
    }
    else {
      if (*(int *)(lVar1 + 0x20) != 0x1000) {
        iVar4 = -0x3fffff45;
        if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_Dqd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),lVar5,param_3,*(int *)(lVar1 + 0x20)
                     ,(char)lVar1);
        }
        goto LAB_1c000c4e9;
      }
      param_3 = 0x60;
      memset(local_68,0,0x60);
      local_40 = BttFltGetBadMemoryRangeCount;
      local_68[0] = 3;
      local_48 = BttFltIsPhysicalMemoryRangeGood;
      local_30 = &BttFltBttIoRoutines;
      lVar5 = lVar1;
      local_58 = lVar1;
      bVar3 = BttFltIsBttMetadataPresent(lVar1);
      uVar6 = *(undefined8 *)(lVar1 + 0x28);
      if (bVar3) {
        lVar5 = ScmBttOpenMappedPool(lVar5,uVar6);
        *(longlong *)(lVar1 + 0x60) = lVar5;
        if (lVar5 != 0) {
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            uVar7 = 0x1b;
LAB_1c000c4a1:
            WPP_SF_q(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,param_3,lVar1);
          }
LAB_1c000c4ad:
          *(undefined1 *)(lVar1 + 0x68) = 1;
          uVar6 = ScmBttGetUsableBlockCount(*(longlong *)(lVar1 + 0x60));
          *(undefined8 *)(lVar1 + 0x30) = uVar6;
          if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
             (3 < (byte)WPP_GLOBAL_Control[0x29])) {
            WPP_SF_Iq(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),
                      (ulonglong)*(uint *)(WPP_GLOBAL_Control + 0x2c),param_3,uVar6,(char)lVar1);
          }
          goto LAB_1c000c4e9;
        }
        iVar4 = -0x3fffffff;
        if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
           ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000c4e9;
        uVar7 = 0x1a;
        iVar4 = -0x3fffffff;
      }
      else {
        lVar5 = ScmBttOpenMappedPool(lVar5,uVar6);
        *(longlong *)(lVar1 + 0x60) = lVar5;
        if (lVar5 == 0) {
          iVar4 = -0x3fffffff;
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000c4e9;
          uVar7 = 0x1c;
          iVar4 = -0x3fffffff;
        }
        else {
          uVar6 = ScmBttInitializeLayout(lVar5,uVar6);
          if ((int)uVar6 == 0) {
            if ((((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
                ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
               (3 < (byte)WPP_GLOBAL_Control[0x29])) {
              uVar7 = 0x1e;
              goto LAB_1c000c4a1;
            }
            goto LAB_1c000c4ad;
          }
          iVar4 = -0x3fffffff;
          if ((((undefined **)WPP_GLOBAL_Control == &WPP_GLOBAL_Control) ||
              ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) == 0)) ||
             ((byte)WPP_GLOBAL_Control[0x29] < 2)) goto LAB_1c000c4e9;
          uVar7 = 0x1d;
          iVar4 = -0x3fffffff;
        }
      }
    }
  }
  WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),uVar7,param_3,iVar4);
LAB_1c000c4e9:
  *(int *)(param_2 + 0x30) = iVar4;
  IofCompleteRequest(param_2,0);
  return iVar4;
}



===== BttFltSynchronousReadWrite @ 1c000c520 =====

ulonglong BttFltSynchronousReadWrite
                    (longlong param_1,char param_2,longlong param_3,ulonglong param_4,
                    ulonglong param_5,ulonglong param_6)

{
  uint uVar1;
  longlong *plVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  ulonglong uVar6;
  
  if ((param_6 < 0x800001) && (param_4 < 0x100000000)) {
    plVar2 = BttFltAllocateAndInitializeSrbContext(param_1,param_3,(int)param_4);
    if (plVar2 == (longlong *)0x0) {
      uVar6 = 0xc000009a;
    }
    else {
      plVar5 = plVar2 + 1;
      BttFltSetSrbOpCode((longlong)plVar5,param_2);
      uVar3 = param_6 / *(uint *)(param_1 + 0x20);
      uVar4 = BttFltSetReadWriteOffsets((longlong)plVar5,param_5 / *(uint *)(param_1 + 0x20),uVar3);
      uVar6 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        uVar1 = IoSynchronousCallDriver(*(undefined8 *)(param_1 + 0x10),*plVar2);
        uVar6 = (ulonglong)uVar1;
        if (((((int)uVar1 < 0) && ((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control)) &&
            ((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0)) &&
           (1 < (byte)WPP_GLOBAL_Control[0x29])) {
          WPP_SF_qd(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x2a,uVar3,param_1,(char)uVar1);
        }
      }
      BttFltFreeSrbContext(plVar2);
    }
  }
  else {
    uVar6 = 0xc000000d;
    if (((undefined **)WPP_GLOBAL_Control != &WPP_GLOBAL_Control) &&
       (((*(uint *)(WPP_GLOBAL_Control + 0x2c) & 1) != 0 && (1 < (byte)WPP_GLOBAL_Control[0x29]))))
    {
      WPP_SF_d(*(undefined8 *)(WPP_GLOBAL_Control + 0x18),0x29,param_3,0xc000000d);
    }
  }
  return uVar6;
}



===== WppCleanupKm @ 1c000c650 =====

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



===== WppInitKm @ 1c000c6d0 =====

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



===== WppLoadTracingSupport @ 1c000c760 =====

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



===== WppTraceCallback @ 1c000c8b0 =====

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



===== entry @ 1c000d010 =====

void entry(longlong param_1)

{
  __security_init_cookie();
  DriverEntry(param_1);
  return;
}



===== __security_init_cookie @ 1c000d044 =====

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



===== DriverEntry @ 1c000d078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 DriverEntry(longlong param_1)

{
  longlong lVar1;
  undefined8 *puVar2;
  
  _DAT_1c0008228 = 1;
  _WPP_MAIN_CB = 0;
  DAT_1c0008208 = &WPP_ThisDir_CTLGUID_BttFltTraceGuid;
  DAT_1c0008210 = 0;
  _DAT_1c0008220 = 0;
  WppLoadTracingSupport();
  _DAT_1c0008220 = 0;
  WppInitKm();
  memset(&DAT_1c00080e8,0,0xe8);
  _BttFltGlobalData = param_1;
  KeInitializeSpinLock(&DAT_1c00081b0);
  DAT_1c00081c0 = &DAT_1c00081b8;
  _DAT_1c00081b8 = &DAT_1c00081b8;
  ExInitializeLookasideListEx(&DAT_1c00080f0,0,0,0x200,0,0x50,0x69545442,0);
  ExInitializeLookasideListEx(&DAT_1c0008150,0,0,0x200,0,0x78,0x69545442,0);
  *(code **)(*(longlong *)(param_1 + 0x30) + 8) = BttFltAddDevice;
  *(code **)(param_1 + 0x68) = BttFltUnload;
  puVar2 = (undefined8 *)(param_1 + 0x70);
  for (lVar1 = 0x1b; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = BttFltPassThrough;
    puVar2 = puVar2 + 1;
  }
  *(code **)(param_1 + 0x148) = BttFltPnp;
  *(code **)(param_1 + 0xe0) = BttFltIoctl;
  *(code **)(param_1 + 0xe8) = BttFltProcessScsi;
  _BttFltBttIoRoutines = BttFltNsRead;
  _DAT_1c0008248 = BttFltNsWrite;
  _DAT_1c0008250 = BttFltNsReadMapped;
  _DAT_1c0008258 = BttFltNsWriteMapped;
  _DAT_1c0008260 = BttFltNsZero;
  _DAT_1c0008268 = BttFltNsMap;
  _DAT_1c0008270 = BttFltNsUnmap;
  _DAT_1c0008278 = BttFltIsPhysicalMemoryRangeGood;
  return 0;
}


