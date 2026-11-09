
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



===== __cpu_features_init @ 1c0001030 =====

/* WARNING: Removing unreachable block (ram,0x0001c000109a) */
/* WARNING: Removing unreachable block (ram,0x0001c0001049) */
/* WARNING: Removing unreachable block (ram,0x0001c000103a) */

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



===== DispatchCrb @ 1c00010f8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 DispatchCrb(ulonglong param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulonglong *puVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  
  puVar4 = DumpExtension;
  if ((int)DumpExtension[0xd3] != 0) {
    DumpExtension[0xca] = param_1;
    return 0x103;
  }
  *(int *)((longlong)DumpExtension + 0x694) = *(int *)(param_1 + 0x3fc) * 1000;
  uVar5 = ExpInterlockedPopEntrySList(puVar4 + 0xda);
  puVar4 = DumpExtension;
  *(ulonglong *)(param_1 + 0x408) = uVar5;
  *(undefined1 *)(param_1 + 0x3f1) = 0x18;
  uVar7 = (int)uVar5 - (int)puVar4[9];
  uVar8 = (ulonglong)uVar7;
  *(ulonglong *)(param_1 + 0x418) =
       puVar4[10] +
       ((ulonglong)(-(uint)(puVar4[9] < uVar5) & uVar7) /
       (ulonglong)*(uint *)((longlong)puVar4 + 0x5c)) * 0x18;
  if ((code *)puVar4[0x26] != (code *)0x0) {
    uVar8 = *puVar4;
    (*(code *)puVar4[0x26])(uVar8,param_1 + 1000);
  }
  if ((*(uint *)(param_1 + 0x3f8) & 0xc0) == 0) goto LAB_1c000121c;
  IdeDumpAllocateScatterGatherList(uVar8,param_1);
  uVar7 = *(uint *)(param_1 + 0x3f8);
  if ((uVar7 & 0xc0) == 0) {
    uVar7 = uVar7 & 0xfffffff9;
LAB_1c00011c9:
    *(uint *)(param_1 + 0x3f8) = uVar7;
  }
  else if ((uVar7 & 2) == 0) {
    uVar7 = uVar7 | 4;
    goto LAB_1c00011c9;
  }
  if ((uVar7 & 4) != 0) {
    lVar6 = *(longlong *)(param_1 + 0x88);
    iVar1 = *(int *)(param_1 + 0x70);
    iVar2 = *(int *)(lVar6 + 0x2c);
    iVar3 = *(int *)(lVar6 + 0x20);
    if ((*(byte *)(lVar6 + 10) & 5) == 0) {
      lVar6 = MmMapLockedPagesSpecifyCache(lVar6,0,1,0,0,0x40000020);
    }
    else {
      lVar6 = *(longlong *)(lVar6 + 0x18);
    }
    *(ulonglong *)(param_1 + 0x410) = (ulonglong)(uint)((iVar1 - iVar2) - iVar3) + lVar6;
  }
LAB_1c000121c:
  *(ushort *)(param_1 + 0x20) = *(ushort *)(param_1 + 0x20) | 1;
  if (*(char *)(param_1 + 0x3ea) == '\0') {
    (*(code *)DumpExtension[0x27])(*DumpExtension);
  }
  else {
    AtaPortCompleteRequest(*DumpExtension,param_1 + 1000);
  }
  IdeDumpCompletionDpc();
  return 0x103;
}



===== FillBufferWithDeviceTelemetryDump @ 1c0001274 =====

ulonglong FillBufferWithDeviceTelemetryDump(longlong param_1,uint *param_2)

{
  char cVar1;
  undefined1 uVar2;
  byte bVar3;
  ushort uVar4;
  ulonglong uVar5;
  char *pcVar6;
  ulonglong uVar7;
  char *pcVar8;
  undefined4 *_Dst;
  undefined8 *puVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  undefined4 *puVar15;
  ushort uVar16;
  undefined4 *puVar17;
  undefined8 *puVar18;
  ulonglong uVar19;
  undefined8 uVar20;
  longlong lVar21;
  undefined1 *puVar22;
  longlong lVar23;
  char *pcVar24;
  longlong lVar25;
  longlong lVar26;
  undefined1 *puVar27;
  ushort *puVar28;
  uint uVar29;
  uint uVar30;
  ushort uVar31;
  ushort local_res8;
  undefined4 local_res18 [2];
  uint local_res20;
  
  uVar14 = *param_2;
  if (uVar14 < 0x581) {
    *param_2 = 0x581;
    uVar5 = 0xc0000023;
  }
  else {
    pcVar24 = (char *)(param_1 + 0x1c);
    uVar30 = 0;
    puVar17 = (undefined4 *)(param_1 + 0x2c);
    puVar9 = (undefined8 *)(param_1 + 0x50);
    lVar21 = *(longlong *)(DumpExtension + 0x10);
    lVar26 = DumpExtension - (longlong)pcVar24;
    *(undefined8 *)(param_1 + 0xc) = 0x4d561aabd8e2592f;
    *(undefined8 *)(param_1 + 0x14) = 0xf440df85751f46a7;
    *pcVar24 = '\0';
    *puVar17 = 0;
    lVar23 = 0x10;
    *(undefined1 *)puVar9 = 0;
    pcVar8 = pcVar24;
    do {
      if ((lVar23 == 0xc) || (pcVar8[lVar26 + 0x744] == '\0')) break;
      *pcVar8 = pcVar8[lVar26 + 0x744];
      pcVar8 = pcVar8 + 1;
      lVar23 = lVar23 + -1;
    } while (lVar23 != 0);
    pcVar6 = pcVar8 + -1;
    if (lVar23 != 0) {
      pcVar6 = pcVar8;
    }
    lVar23 = 2;
    *pcVar6 = '\0';
    do {
      cVar1 = *pcVar24;
      *pcVar24 = pcVar24[1];
      pcVar24[1] = cVar1;
      pcVar24 = pcVar24 + 2;
      lVar23 = lVar23 + -1;
    } while (lVar23 != 0);
    lVar23 = 2;
    *puVar17 = *(undefined4 *)(DumpExtension + 0x73c);
    do {
      uVar2 = *(undefined1 *)puVar17;
      *(undefined1 *)puVar17 = *(undefined1 *)((longlong)puVar17 + 1);
      *(undefined1 *)((longlong)puVar17 + 1) = uVar2;
      lVar26 = DumpExtension;
      puVar17 = (undefined4 *)((longlong)puVar17 + 2);
      lVar23 = lVar23 + -1;
    } while (lVar23 != 0);
    puVar18 = (undefined8 *)(param_1 + 0x30);
    uVar20 = *(undefined8 *)(DumpExtension + 0x74c);
    *puVar18 = *(undefined8 *)(DumpExtension + 0x744);
    *(undefined8 *)(param_1 + 0x38) = uVar20;
    uVar20 = *(undefined8 *)(lVar26 + 0x75c);
    *(undefined8 *)(param_1 + 0x40) = *(undefined8 *)(lVar26 + 0x754);
    *(undefined8 *)(param_1 + 0x48) = uVar20;
    lVar23 = 0x10;
    do {
      lVar25 = lVar23;
      uVar2 = *(undefined1 *)puVar18;
      *(undefined1 *)puVar18 = *(undefined1 *)((longlong)puVar18 + 1);
      *(undefined1 *)((longlong)puVar18 + 1) = uVar2;
      lVar26 = DumpExtension;
      puVar18 = (undefined8 *)((longlong)puVar18 + 2);
      lVar23 = lVar25 + -1;
    } while (lVar23 != 0);
    uVar19 = (ulonglong)((int)lVar25 + 9);
    *(undefined1 *)(param_1 + 0x4f) = 0;
    uVar20 = *(undefined8 *)(lVar26 + 0x730);
    *puVar9 = *(undefined8 *)(lVar26 + 0x728);
    *(undefined8 *)(param_1 + 0x58) = uVar20;
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(lVar26 + 0x738);
    do {
      uVar2 = *(undefined1 *)puVar9;
      *(undefined1 *)puVar9 = *(undefined1 *)((longlong)puVar9 + 1);
      *(undefined1 *)((longlong)puVar9 + 1) = uVar2;
      puVar9 = (undefined8 *)((longlong)puVar9 + 2);
      uVar19 = uVar19 - 1;
    } while (uVar19 != 0);
    *(undefined1 *)(param_1 + 99) = 0;
    puVar17 = (undefined4 *)(param_1 + 0x12fU & 0xfffffffffffffffc);
    *(undefined1 *)(param_1 + 0x7c) = 0;
    iVar10 = (int)param_1;
    *(undefined4 *)(param_1 + 0x78) = 0;
    iVar13 = (int)puVar17;
    *(undefined8 *)(param_1 + 0x108) = 0;
    pcVar24 = (char *)(puVar17 + 0x11);
    *(uint *)(param_1 + 0x110) = ((uint)(param_1 + 0x12fU) & 0xfffffffc) - iVar10;
    *puVar17 = 2;
    lVar26 = (longlong)"ATAGPLogPages" - (longlong)pcVar24;
    lVar23 = 0x10;
    do {
      if ((lVar23 == -0x7fffffee) || (pcVar24[lVar26] == '\0')) break;
      *pcVar24 = pcVar24[lVar26];
      pcVar24 = pcVar24 + 1;
      lVar23 = lVar23 + -1;
    } while (lVar23 != 0);
    pcVar8 = pcVar24 + -1;
    if (lVar23 != 0) {
      pcVar8 = pcVar24;
    }
    _Dst = puVar17 + 1;
    uVar20 = 0x40;
    *pcVar8 = '\0';
    memset(_Dst,0,0x40);
    uVar11 = uVar14 + (iVar10 - iVar13) + -0x54;
    puVar15 = puVar17 + 0x15;
    uVar19 = IdeReadGeneralPurposeLog(_Dst,0,uVar20,1,(ulonglong)puVar15,0x200);
    uVar5 = uVar19 & 0xffffffff;
    if (-1 < (int)uVar19) {
      puVar28 = (ushort *)(lVar21 + 0xf0);
      uVar31 = 0;
      uVar29 = 0;
      uVar12 = uVar11;
      do {
        uVar16 = *puVar28;
        if (uVar16 == 0) break;
        uVar4 = *(ushort *)((longlong)puVar15 + (ulonglong)uVar16 * 2);
        if ((((int)(uint)uVar4 < (int)(0x40 - (uint)uVar31)) && ((uint)uVar4 * 0x200 < uVar12)) &&
           (uVar4 != 0)) {
          *(ushort *)(puVar17 + (ulonglong)uVar29 + 1) = uVar16;
          uVar16 = uVar4;
          if ((ushort)((ushort)uVar12 >> 9) < uVar4) {
            uVar16 = (ushort)((uVar12 & 0xffff) >> 9);
          }
          uVar12 = uVar12 + (uint)uVar4 * -0x200;
          *(ushort *)((longlong)puVar17 + (ulonglong)uVar29 * 4 + 6) = uVar16;
          uVar29 = uVar29 + 1;
          uVar31 = uVar31 + uVar4;
        }
        uVar30 = uVar30 + 1;
        puVar28 = puVar28 + 2;
      } while (uVar30 < 0x10);
      if (*(short *)(puVar17 + 0x27) == 0) {
        local_res8 = *(ushort *)(lVar21 + 0x130);
      }
      else {
        local_res8 = 0x24;
      }
      lVar21 = lVar21 - (longlong)puVar17;
      puVar28 = (ushort *)((longlong)puVar17 + 6);
      local_res20 = 0;
      pcVar24 = (char *)(param_1 + 0x7c);
      uVar31 = *(ushort *)((longlong)puVar17 + (ulonglong)local_res8 * 2 + 0x54);
      uVar19 = (ulonglong)uVar31;
      local_res18[0] = CONCAT22(local_res18[0]._2_2_,uVar31);
      do {
        if (*(short *)((longlong)puVar28 + lVar21 + 0xea) == 0) break;
        uVar31 = *puVar28;
        uVar19 = (ulonglong)puVar28[-1];
        if (uVar31 != 0) {
          uVar16 = (ushort)(uVar11 >> 9);
          if (uVar31 <= uVar16) {
            uVar16 = uVar31;
          }
          if (uVar16 == 0) {
            uVar5 = 0xc0000023;
          }
          else {
            uVar7 = IdeReadGeneralPurposeLog
                              (uVar19,(char)puVar28[-1],lVar21,(byte)uVar16,(ulonglong)puVar15,
                               (uint)uVar16 << 9);
            uVar5 = uVar7 & 0xffffffff;
            if (-1 < (int)uVar7) {
              *puVar28 = uVar16;
              if ((uint)uVar16 * 0x200 < uVar11) {
                uVar11 = uVar11 + (uint)uVar16 * -0x200;
              }
              else {
                uVar11 = 0;
              }
              puVar15 = puVar15 + (ulonglong)uVar16 * 0x80;
              goto LAB_1c00015e5;
            }
          }
          *puVar28 = 0;
        }
LAB_1c00015e5:
        puVar28 = puVar28 + 2;
        local_res20 = local_res20 + 1;
      } while (local_res20 < 0x10);
      uVar30 = (int)puVar15 - iVar13;
      *(uint *)(param_1 + 0x108) = uVar30;
      if ((int)uVar5 == -0x3fffffdd) {
        *param_2 = (uVar30 - iVar10) + iVar13;
      }
      else {
        *(undefined8 *)(param_1 + 0x120) = 0;
        lVar23 = (longlong)puVar17 + (ulonglong)uVar30;
        iVar13 = (int)lVar23;
        *(int *)(param_1 + 0x128) = iVar13 - iVar10;
        uVar14 = (uVar14 - 8) + (iVar10 - iVar13);
        if (0x1ff < uVar14) {
          uVar31 = (ushort)(uVar14 >> 9);
          if ((ushort)local_res18[0] <= uVar31) {
            uVar31 = (ushort)local_res18[0];
          }
          uVar14 = (uint)uVar31 << 9;
          if ((-1 < (int)uVar5) && (uVar31 != 0)) {
            uVar19 = IdeReadGeneralPurposeLog
                               (uVar19,(char)local_res8,lVar21,(byte)uVar31,lVar23 + 8,uVar14);
            uVar5 = uVar19 & 0xffffffff;
            if ((int)uVar19 < 0) {
              uVar14 = 0;
            }
            else {
              if (local_res8 == 0x24) {
                local_res18[0] = *(undefined4 *)(lVar23 + 0xc);
                puVar22 = (undefined1 *)(param_1 + 0x1c);
                *puVar22 = 0;
                puVar27 = (undefined1 *)(param_1 + 0x1d);
                lVar21 = (longlong)local_res18 - (longlong)puVar22;
                lVar26 = 4;
                do {
                  bVar3 = puVar22[lVar21];
                  *puVar22 = (&DAT_1c0007170)[bVar3 >> 4];
                  puVar22 = puVar22 + 1;
                  *puVar27 = (&DAT_1c0007170)[bVar3 & 0xf];
                  puVar27 = puVar27 + 1;
                  lVar26 = lVar26 + -1;
                } while (lVar26 != 0);
                *(undefined1 *)(param_1 + 0x24) = 0;
                lVar26 = lVar23 - (longlong)pcVar24;
                lVar21 = 0x84;
                do {
                  if ((lVar21 == 4) || (pcVar24[lVar26 + 0x188] == '\0')) break;
                  *pcVar24 = pcVar24[lVar26 + 0x188];
                  pcVar24 = pcVar24 + 1;
                  lVar21 = lVar21 + -1;
                } while (lVar21 != 0);
                pcVar8 = pcVar24 + -1;
                if (lVar21 != 0) {
                  pcVar8 = pcVar24;
                }
                *pcVar8 = '\0';
              }
              *(ushort *)(lVar23 + 4) = local_res8;
              *(ushort *)(lVar23 + 6) = uVar31;
            }
          }
        }
        *(uint *)(param_1 + 0x120) = uVar14 + 8;
        *param_2 = ((uVar14 + 8) - iVar10) + iVar13;
        if ((int)uVar5 != -0x3fffffdd) {
          uVar5 = 0;
        }
      }
    }
  }
  return uVar5;
}



===== IdeDumpAllocateScatterGatherList @ 1c00017b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IdeDumpAllocateScatterGatherList(undefined8 param_1,longlong param_2)

{
  int *piVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined8 *puVar7;
  
  uVar6 = 0;
  if (*(longlong *)(DumpExtension + 0x18) != 0) {
    *(undefined4 **)(param_2 + 0x3e0) = (undefined4 *)(param_2 + 0xa0);
    puVar7 = (undefined8 *)(param_2 + 0xb0);
    *(undefined4 *)(param_2 + 0xa0) = 0;
    uVar2 = *(uint *)(param_2 + 0x3f8);
    uVar4 = *(uint *)(param_2 + 0x400);
    lVar3 = *(longlong *)(param_2 + 0x70);
    if (uVar4 != 0) {
      do {
        piVar1 = (int *)(puVar7 + 1);
        *piVar1 = uVar4 - uVar6;
        uVar5 = (**(code **)(*(longlong *)(*(longlong *)(DumpExtension + 0x18) + 8) + 0x40))
                          (*(longlong *)(DumpExtension + 0x18),*(undefined8 *)(param_2 + 0x88),
                           *(undefined8 *)(DumpExtension + 0x20),(ulonglong)uVar6 + lVar3,piVar1,
                           (byte)(uVar2 >> 7) & 1);
        uVar6 = uVar6 + *piVar1;
        *puVar7 = uVar5;
        puVar7 = puVar7 + 3;
        **(int **)(param_2 + 0x3e0) = **(int **)(param_2 + 0x3e0) + 1;
        uVar4 = *(uint *)(param_2 + 0x400);
      } while (uVar6 < uVar4);
    }
  }
  return;
}



===== IdeDumpCompletionDpc @ 1c0001884 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong IdeDumpCompletionDpc(void)

{
  code *pcVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  
  puVar2 = DumpExtension;
  uVar7 = *(uint *)(DumpExtension + 0xcb);
  uVar5 = (ulonglong)uVar7;
  if ((uVar7 & 1) != 0) {
    if ((uVar7 & 4) != 0) {
      uVar7 = 0;
      puVar9 = DumpExtension + 0xcd;
      do {
        pcVar1 = (code *)*puVar9;
        *puVar9 = 0;
        puVar3 = DumpExtension;
        if (pcVar1 != (code *)0x0) {
          if (uVar7 == 0) {
            DumpExtension[0xd1] = pcVar1;
            *(undefined4 *)(puVar3 + 0xd2) = *(undefined4 *)((longlong)puVar2 + 0x664);
            *(undefined4 *)((longlong)puVar2 + 0x664) = 0;
          }
          else if (((uVar7 == 1) || (uVar7 == 2)) || (uVar7 == 3)) {
            (*pcVar1)(*DumpExtension);
          }
        }
        uVar7 = uVar7 + 1;
        puVar9 = puVar9 + 1;
      } while (uVar7 < 4);
    }
    puVar2 = DumpExtension;
    *(undefined4 *)(DumpExtension + 0xcb) = 0;
    lVar4 = ExpInterlockedPopEntrySList(puVar2 + 0xd8);
    puVar2 = DumpExtension;
    uVar5 = -lVar4;
    uVar8 = -(ulonglong)(lVar4 != 0) & lVar4 - 0x50U;
    if (uVar8 != 0) {
      *(undefined4 *)((longlong)DumpExtension + 0x694) = 0xffffffff;
      if ((*(uint *)(uVar8 + 0x3f8) & 0xc0) != 0) {
        lVar4 = puVar2[3];
        if (lVar4 != 0) {
          (**(code **)(*(longlong *)(lVar4 + 8) + 0x28))
                    (lVar4,*(longlong *)(uVar8 + 0x88),puVar2[4],*(undefined8 *)(uVar8 + 0x70),
                     *(int *)(*(longlong *)(uVar8 + 0x88) + 0x28) - *(int *)(uVar8 + 0x488),
                     (byte)(*(uint *)(uVar8 + 0x3f8) >> 7) & 1);
        }
        *(undefined8 *)(uVar8 + 0x3e0) = 0;
      }
      uVar6 = ExpInterlockedPushEntrySList(DumpExtension + 0xda,*(undefined8 *)(uVar8 + 0x408));
      uVar5 = CONCAT71((int7)((ulonglong)uVar6 >> 8),*(undefined1 *)(uVar8 + 0x3ea)) &
              0xffffffffffffff5f;
      if (((char)uVar5 != '\a') && ((char)uVar5 != 'D')) {
        uVar5 = (**(code **)(uVar8 + 8))(uVar8);
      }
    }
  }
  return uVar5;
}



===== IdeDumpFinish @ 1c0001a10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IdeDumpFinish(void)

{
  undefined4 *puVar1;
  longlong lVar2;
  
  lVar2 = DumpExtension;
  if (*(char *)(DumpExtension + 0x783) == '\0') {
    puVar1 = (undefined4 *)(DumpExtension + 0x1c0);
    memset(puVar1,0,0x480);
    *puVar1 = 0x627249;
    *(uint *)(lVar2 + 0x64c) = *(uint *)(lVar2 + 0x64c) | 1;
    *(undefined4 *)(lVar2 + 0x648) = 0;
    *(undefined8 *)(lVar2 + 0x1d0) = 0;
    *(code **)(lVar2 + 0x1c8) = _guard_check_icall;
    *(undefined2 *)(lVar2 + 0x5a8) = 0x104;
    *(undefined1 *)(lVar2 + 0x5ad) = *(undefined1 *)(lVar2 + 0xea);
    *(char *)(lVar2 + 0x5ae) = *(char *)(lVar2 + 0x6a9);
    *(uint *)(lVar2 + 0x5b8) = *(uint *)(lVar2 + 0x5b8) & 0xfffffffd;
    *(undefined8 *)(lVar2 + 0x5d0) = 0;
    *(undefined4 *)(lVar2 + 0x5c0) = 0;
    *(undefined1 *)(lVar2 + 0x5af) = *(undefined1 *)(lVar2 + 0x6aa);
    *(undefined4 *)(lVar2 + 0x5bc) = 1;
    *(undefined1 *)(lVar2 + 0x5f6) = 0xe7;
    *(byte *)(lVar2 + 0x5f5) = (-(*(char *)(lVar2 + 0x6a9) != '\0') & 0x10U) + 0xa0;
    DispatchCrb((ulonglong)puVar1);
    IdeDumpWaitOnRequest((ulonglong)puVar1,-1);
    (**(code **)(DumpExtension + 0x6a0))(10000);
    lVar2 = DumpExtension;
    if ((*(byte *)(DumpExtension + 0x780) & 8) != 0) {
      puVar1 = (undefined4 *)(DumpExtension + 0x1c0);
      memset(puVar1,0,0x480);
      *puVar1 = 0x627249;
      *(uint *)(lVar2 + 0x64c) = *(uint *)(lVar2 + 0x64c) | 1;
      *(undefined4 *)(lVar2 + 0x648) = 0;
      *(undefined8 *)(lVar2 + 0x1d0) = 0;
      *(code **)(lVar2 + 0x1c8) = _guard_check_icall;
      *(undefined2 *)(lVar2 + 0x5a8) = 0x100;
      *(undefined1 *)(lVar2 + 0x5ad) = *(undefined1 *)(lVar2 + 0xea);
      *(char *)(lVar2 + 0x5ae) = *(char *)(lVar2 + 0x6a9);
      *(uint *)(lVar2 + 0x5b8) = *(uint *)(lVar2 + 0x5b8) & 0xfffffffd;
      *(undefined8 *)(lVar2 + 0x5d0) = 0;
      *(undefined4 *)(lVar2 + 0x5c0) = 0;
      *(undefined1 *)(lVar2 + 0x5af) = *(undefined1 *)(lVar2 + 0x6aa);
      *(undefined4 *)(lVar2 + 0x5bc) = 1;
      *(undefined1 *)(lVar2 + 0x5f6) = 0xe0;
      *(byte *)(lVar2 + 0x5f5) = (-(*(char *)(lVar2 + 0x6a9) != '\0') & 0x10U) + 0xa0;
      DispatchCrb((ulonglong)puVar1);
      IdeDumpWaitOnRequest((ulonglong)puVar1,-1);
    }
    if ((*(char *)(DumpExtension + 0x782) != '\0') && (*(char *)(DumpExtension + 0x785) != '\0')) {
      HalDmaFreeCrashDumpRegistersEx(*(undefined8 *)(DumpExtension + 0x18),0);
    }
  }
  return;
}



===== _guard_check_icall @ 1c0001c00 =====

void _guard_check_icall(void)

{
  return;
}



===== IdeDumpGetPhysicalAddress @ 1c0001c0c =====

void IdeDumpGetPhysicalAddress(longlong param_1,longlong param_2)

{
  uint *puVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  int iVar8;
  uint uVar9;
  
  uVar6 = *(ulonglong *)(param_2 + 0x18);
  lVar4 = 0;
  uVar7 = *(ulonglong *)(param_1 + -0x768);
  uVar9 = 0;
  puVar1 = *(uint **)(param_2 + 0x20);
  lVar2 = *(longlong *)(param_2 + 0x10);
  iVar8 = (int)uVar6;
  if ((uVar6 < uVar7) || (*(uint *)(param_1 + -0x738) + uVar7 <= uVar6)) {
    if ((lVar2 != 0) &&
       ((uVar7 = *(ulonglong *)(lVar2 + 0x28), uVar7 <= uVar6 &&
        (uVar6 < *(uint *)(lVar2 + 0x18) + uVar7)))) {
      if (uVar7 < uVar6) {
        uVar5 = iVar8 - (int)uVar7;
      }
      else {
        uVar5 = 0;
      }
      if ((*(uint *)(lVar2 + 0x10) & 0xc0) != 0) {
        lVar3 = *(longlong *)(lVar2 + -8);
        if (lVar3 == 0) {
          lVar4 = MmGetPhysicalAddress(uVar6);
          iVar8 = *(int *)(lVar2 + 0x18);
        }
        else {
          uVar6 = 0;
          uVar9 = *(uint *)(lVar3 + 0x18);
          while (uVar9 <= uVar5) {
            uVar5 = uVar5 - uVar9;
            uVar6 = (ulonglong)((int)uVar6 + 1);
            uVar9 = *(uint *)(lVar3 + (uVar6 + 1) * 0x18);
          }
          lVar4 = (ulonglong)uVar5 + *(longlong *)(lVar3 + 0x10 + uVar6 * 0x18);
          iVar8 = *(int *)(lVar3 + 0x18 + uVar6 * 0x18);
        }
        uVar9 = iVar8 - uVar5;
      }
    }
    if (puVar1 == (uint *)0x0) goto LAB_1c0001da7;
    goto LAB_1c0001da4;
  }
  if (uVar7 < uVar6) {
    uVar5 = iVar8 - (int)uVar7;
  }
  else {
    uVar5 = 0;
  }
  lVar4 = (ulonglong)uVar5 + *(longlong *)(param_1 + -0x758);
  if (puVar1 == (uint *)0x0) goto LAB_1c0001da7;
  if (uVar5 < *(uint *)(param_1 + -0x730)) {
    uVar9 = *(uint *)(param_1 + -0x730) - uVar5;
  }
  else if (lVar2 != 0) {
    uVar7 = *(ulonglong *)(lVar2 + 0x20);
    if (((uVar7 == 0) || (uVar6 < uVar7)) || (*(uint *)(param_1 + -0x734) + uVar7 <= uVar6)) {
      uVar7 = *(ulonglong *)(lVar2 + 0x30);
      if (((uVar7 != 0) && (uVar7 <= uVar6)) && (uVar6 < *(byte *)(lVar2 + 9) + uVar7)) {
        uVar9 = (uint)*(byte *)(lVar2 + 9);
        goto LAB_1c0001cfd;
      }
      uVar7 = *(ulonglong *)(lVar2 + 0x28);
      if (((uVar7 != 0) && (uVar7 <= uVar6)) && (uVar6 < *(uint *)(lVar2 + 0x18) + uVar7)) {
        uVar9 = *(uint *)(lVar2 + 0x18);
        goto LAB_1c0001cfd;
      }
    }
    else {
      uVar9 = *(uint *)(param_1 + -0x734);
LAB_1c0001cfd:
      uVar9 = uVar9 - (-(uint)(uVar7 < uVar6) & iVar8 - (int)uVar7);
      if (uVar9 < *(uint *)(param_1 + -0x738)) goto LAB_1c0001da4;
    }
    uVar9 = 0;
  }
LAB_1c0001da4:
  *puVar1 = uVar9;
LAB_1c0001da7:
  *(longlong *)(param_2 + 0x10) = lVar4;
  return;
}



===== IdeDumpGetTransferSizes @ 1c0001dd0 =====

void IdeDumpGetTransferSizes(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *(undefined4 *)(DumpExtension + 0x1a8);
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(DumpExtension + 0x69c);
  }
  return;
}



===== IdeDumpIdentifyCompletion @ 1c0001e10 =====

void IdeDumpIdentifyCompletion(longlong param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  longlong lVar5;
  
  if (*(char *)(param_1 + 0x3ea) == '\x01') {
    puVar3 = *(undefined8 **)(param_1 + 0x410);
    lVar5 = 4;
    puVar4 = *(undefined8 **)(param_1 + 0x10);
    do {
      uVar2 = puVar3[1];
      *puVar4 = *puVar3;
      puVar4[1] = uVar2;
      uVar2 = puVar3[3];
      puVar4[2] = puVar3[2];
      puVar4[3] = uVar2;
      uVar2 = puVar3[5];
      puVar4[4] = puVar3[4];
      puVar4[5] = uVar2;
      uVar2 = puVar3[7];
      puVar4[6] = puVar3[6];
      puVar4[7] = uVar2;
      uVar2 = puVar3[9];
      puVar4[8] = puVar3[8];
      puVar4[9] = uVar2;
      uVar2 = puVar3[0xb];
      puVar4[10] = puVar3[10];
      puVar4[0xb] = uVar2;
      uVar2 = puVar3[0xd];
      puVar4[0xc] = puVar3[0xc];
      puVar4[0xd] = uVar2;
      puVar1 = puVar3 + 0xe;
      uVar2 = puVar3[0xf];
      puVar3 = puVar3 + 0x10;
      puVar4[0xe] = *puVar1;
      puVar4[0xf] = uVar2;
      lVar5 = lVar5 + -1;
      puVar4 = puVar4 + 0x10;
    } while (lVar5 != 0);
  }
  return;
}



===== IdeDumpInitDma @ 1c0001e80 =====

void IdeDumpInitDma(ulonglong param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  uint *puVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  ulonglong local_res8 [4];
  
  lVar4 = DumpExtension;
  plVar1 = (longlong *)(DumpExtension + 0x18);
  if (*plVar1 == 0) {
    lVar5 = *(longlong *)(DumpExtension + 0x10);
    *(undefined8 *)(DumpExtension + 0x20) = 0;
    *(undefined1 *)(lVar4 + 0x785) = 0;
    puVar3 = (uint *)(lVar5 + 0xd4);
    *puVar3 = *puVar3 & 0x1f;
    puVar3 = (uint *)(lVar5 + 0xd8);
    *puVar3 = *puVar3 & 0x1f;
  }
  else {
    local_res8[0] = param_1 & 0xffffffff00000000;
    if (*(char *)(DumpExtension + 0x785) == '\0') {
      puVar3 = (uint *)(DumpExtension + 0x69c);
      puVar2 = (undefined8 *)(DumpExtension + 0x20);
      *puVar2 = 0;
      iVar6 = HalDmaAllocateCrashDumpRegistersEx
                        (*plVar1,(uint)((*puVar3 & 0xfff) != 0) + (*puVar3 >> 0xc),0,puVar2,
                         local_res8);
      if (iVar6 < 0) {
        lVar4 = *(longlong *)(DumpExtension + 0x10);
        *(undefined1 *)(DumpExtension + 0x785) = 0;
        puVar3 = (uint *)(lVar4 + 0xd4);
        *puVar3 = *puVar3 & 0x1f;
        puVar3 = (uint *)(lVar4 + 0xd8);
        *puVar3 = *puVar3 & 0x1f;
      }
      else {
        *(undefined1 *)(DumpExtension + 0x785) = 1;
      }
    }
  }
  return;
}



===== IdeDumpIoIssue @ 1c0001f40 =====

undefined8
IdeDumpIoIssue(uint param_1,longlong *param_2,longlong param_3,undefined8 param_4,short param_5)

{
  undefined4 *_Dst;
  uint uVar1;
  longlong lVar2;
  undefined8 uVar3;
  int iVar4;
  
  lVar2 = DumpExtension;
  if (param_1 == 4) {
    uVar3 = KeQueryPerformanceCounter(0);
    *(undefined8 *)(DumpExtension + 0x718) = uVar3;
    return 0;
  }
  iVar4 = 0;
  if (param_1 < 2) {
    _Dst = (undefined4 *)(DumpExtension + 0x1c0);
    memset(_Dst,0,0x480);
    *_Dst = 0x627249;
    *(uint *)(lVar2 + 0x64c) = *(uint *)(lVar2 + 0x64c) | 1;
    uVar1 = *(uint *)(lVar2 + 0x1a8);
    *(undefined4 *)(lVar2 + 0x648) = 0;
    *(undefined4 *)(lVar2 + 0x648) = 0;
    *(longlong *)(lVar2 + 0x640) =
         (*(longlong *)(lVar2 + 0x6b0) + *param_2) / (longlong)(ulonglong)uVar1;
    *(ulonglong *)(param_3 + 0x20) = *(ulonglong *)(param_3 + 0x18) & 0xfffffffffffff000;
    IdeDumpSetupCrb((ulonglong)uVar1,*(ulonglong *)(lVar2 + 0x640),param_3,*(uint *)(lVar2 + 0x648),
                    (longlong)_Dst,param_5);
    DispatchCrb((ulonglong)_Dst);
    if (param_1 != 0) goto LAB_1c0002036;
  }
  else {
LAB_1c0002036:
    if (param_1 != 3) goto LAB_1c000203e;
  }
  iVar4 = -1;
LAB_1c000203e:
  uVar3 = IdeDumpWaitOnRequest(lVar2 + 0x1c0,iVar4);
  return uVar3;
}



===== IdeDumpIssueIdentify @ 1c0002068 =====

byte IdeDumpIssueIdentify(undefined8 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined4 *_Dst;
  char cVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  
  lVar3 = DumpExtension;
  _Dst = (undefined4 *)(DumpExtension + 0x1c0);
  memset(_Dst,0,0x480);
  *_Dst = 0x627249;
  puVar1 = (undefined8 *)(lVar3 + 0x68);
  uVar5 = *(ulonglong *)(lVar3 + 0x30);
  *(uint *)(lVar3 + 0x64c) = *(uint *)(lVar3 + 0x64c) | 1;
  *(undefined4 *)(lVar3 + 0x648) = 0;
  *(undefined4 *)(lVar3 + 0x90) = 0x200;
  *puVar1 = 0;
  *(undefined2 *)(lVar3 + 0x72) = 0;
  *(ushort *)(lVar3 + 0x70) = (((ushort)(((ushort)uVar5 & 0xfff) + 0x11ff) >> 0xc) + 6) * 8;
  *(ulonglong *)(lVar3 + 0x88) = uVar5 & 0xfffffffffffff000;
  *(uint *)(lVar3 + 0x94) = (uint)uVar5 & 0xfff;
  *(longlong *)(lVar3 + 0x98) = *(longlong *)(lVar3 + 0x40) >> 0xc;
  MmMapMemoryDumpMdl(puVar1);
  lVar4 = DumpExtension;
  *(undefined8 **)(lVar3 + 0x248) = puVar1;
  *(ulonglong *)(lVar3 + 0x230) = (ulonglong)*(uint *)(lVar3 + 0x94) + *(longlong *)(lVar3 + 0x88);
  *(undefined4 *)(lVar3 + 0x5c0) = *(undefined4 *)(lVar3 + 0x90);
  *(code **)(lVar3 + 0x1c8) = IdeDumpIdentifyCompletion;
  *(undefined8 *)(lVar3 + 0x1d0) = param_2;
  *(undefined2 *)(lVar3 + 0x5a8) = 0x101;
  *(undefined1 *)(lVar3 + 0x5ad) = *(undefined1 *)(lVar4 + 0xea);
  cVar2 = *(char *)(lVar4 + 0x6a9);
  *(char *)(lVar3 + 0x5ae) = cVar2;
  *(undefined1 *)(lVar3 + 0x5af) = *(undefined1 *)(lVar4 + 0x6aa);
  *(undefined4 *)(lVar3 + 0x5bc) = 1;
  *(undefined1 *)(lVar3 + 0x5f6) = 0xec;
  *(uint *)(lVar3 + 0x5b8) = *(uint *)(lVar3 + 0x5b8) & 0xfffffffd | 0x40;
  *(byte *)(lVar3 + 0x5f5) = (-(cVar2 != '\0') & 0x10U) + 0xa0;
  DispatchCrb((ulonglong)_Dst);
  uVar5 = IdeDumpWaitOnRequest((ulonglong)_Dst,-1);
  return (byte)(uVar5 >> 0x1f) & 1 ^ 1;
}



===== IdeDumpMiniportChannelInitialize @ 1c00021f0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
IdeDumpMiniportChannelInitialize
          (undefined8 param_1,undefined8 param_2,undefined *param_3,int param_4)

{
  undefined8 *puVar1;
  PSLIST_HEADER ListHead;
  uint uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  longlong lVar5;
  char cVar6;
  byte bVar7;
  ushort uVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  undefined1 auStack_288 [32];
  undefined8 local_268;
  undefined8 uStack_260;
  undefined8 local_258;
  undefined8 uStack_250;
  undefined8 local_248;
  undefined8 uStack_240;
  undefined8 local_238;
  undefined1 local_228 [20];
  undefined8 local_214;
  undefined8 uStack_20c;
  undefined4 local_204;
  undefined8 local_1fa;
  undefined8 local_1f2;
  undefined8 uStack_1ea;
  undefined8 local_1e2;
  undefined8 uStack_1da;
  undefined8 local_1d2;
  undefined2 local_188;
  undefined2 local_186;
  ushort local_184;
  ushort local_182;
  undefined8 local_150;
  undefined8 local_148;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_288;
  memset(local_228,0,0x200);
  puVar9 = DumpExtension;
  local_238 = (ulonglong)local_238._6_2_ << 0x30;
  local_268 = 0;
  uStack_260 = 0;
  puVar3 = (undefined1 *)DumpExtension[2];
  local_258 = 0;
  uStack_250 = 0;
  local_248 = 0;
  uStack_240 = 0;
  if (param_4 + 0x798U < 0x8001) {
    uVar10 = DumpExtension[1];
    puVar1 = DumpExtension + 0x24;
    *(undefined2 *)puVar1 = 0x38;
    *(undefined1 *)((longlong)puVar9 + 0x122) = *puVar3;
    cVar6 = (*(code *)param_3)(*puVar9,puVar1,uVar10);
    puVar9 = DumpExtension;
    if (cVar6 != '\0') {
      if ((((DumpExtension[0x27] == 0) || (DumpExtension[0x28] == 0)) || (DumpExtension[0x29] == 0))
         || ((DumpExtension[0x25] == 0 || (DumpExtension[0x2a] == 0)))) {
        uVar10 = 0xc0000059;
        goto LAB_1c000254d;
      }
      puVar4 = (undefined1 *)DumpExtension[2];
      *(undefined2 *)(DumpExtension + 0x1d) = 0x28;
      *(undefined1 *)((longlong)puVar9 + 0xea) = *puVar4;
      *(ushort *)((longlong)puVar9 + 0xec) = *(ushort *)((longlong)puVar9 + 0xec) & 0xfffe;
      *(undefined4 *)(puVar9 + 0x1e) = 1;
      *(undefined4 *)(puVar9 + 0x20) = 0x1010101;
      puVar9[0x21] = (ulonglong)*(uint *)(puVar4 + 4);
      puVar9[0x1f] = puVar9 + 0x22;
      cVar6 = (*(code *)puVar9[0x2a])(*puVar9,0);
      if (cVar6 != '\0') {
        uVar2 = *(uint *)(DumpExtension + 0xc);
        ListHead = (PSLIST_HEADER)(DumpExtension + 0xda);
        lVar5 = DumpExtension[5];
        DumpExtension[9] = (ulonglong)uVar2 + lVar5;
        InitializeSListHead(ListHead);
        ExpInterlockedPushEntrySList(ListHead,(ulonglong)uVar2 + lVar5);
        puVar9 = DumpExtension;
        DumpExtension[10] = (ulonglong)*(uint *)((longlong)DumpExtension + 0x5c) + DumpExtension[9];
        IdeDumpInitDma((ulonglong)puVar9);
        if ((*(char *)((longlong)DumpExtension + 0x784) != '\0') &&
           (*(char *)((longlong)DumpExtension + 0x782) != '\0')) {
          return 0;
        }
        bVar7 = IdeDumpIssueIdentify(puVar9,local_228);
        if (bVar7 != 0) {
          local_268 = *(undefined8 *)(puVar3 + 0xa8);
          uStack_260 = *(undefined8 *)(puVar3 + 0xb0);
          local_258 = *(undefined8 *)(puVar3 + 0xb8);
          uStack_250 = *(undefined8 *)(puVar3 + 0xc0);
          local_248 = *(undefined8 *)(puVar3 + 200);
          uStack_240 = *(undefined8 *)(puVar3 + 0xd0);
          local_238 = *(longlong *)(puVar3 + 0xd8);
          cVar6 = (*(code *)DumpExtension[0x25])(*DumpExtension,&local_268,local_228);
          puVar9 = DumpExtension;
          if (cVar6 != '\0') {
            DumpExtension[0x31] = local_268;
            puVar9[0x32] = uStack_260;
            puVar9[0x33] = local_258;
            puVar9[0x34] = uStack_250;
            puVar9[0x35] = local_248;
            puVar9[0x36] = uStack_240;
            puVar9[0x37] = local_238;
            puVar9[0xe5] = local_214;
            puVar9[0xe6] = uStack_20c;
            *(undefined4 *)(puVar9 + 0xe7) = local_204;
            *(undefined8 *)((longlong)puVar9 + 0x73c) = local_1fa;
            *(undefined8 *)((longlong)puVar9 + 0x744) = local_1f2;
            *(undefined8 *)((longlong)puVar9 + 0x74c) = uStack_1ea;
            *(undefined8 *)((longlong)puVar9 + 0x754) = local_1e2;
            *(undefined8 *)((longlong)puVar9 + 0x75c) = uStack_1da;
            *(undefined8 *)((longlong)puVar9 + 0x764) = local_1d2;
            puVar9[0xee] = local_150;
            puVar9[0xef] = local_148;
            *(undefined2 *)((longlong)puVar9 + 0x76c) = local_188;
            *(undefined2 *)((longlong)puVar9 + 0x76e) = local_186;
            uVar8 = (local_182 >> 0xc ^ *(ushort *)(puVar9 + 0xf0)) & 1 ^ *(ushort *)(puVar9 + 0xf0)
            ;
            *(ushort *)(puVar9 + 0xf0) = uVar8;
            uVar8 = (local_182 >> 0xc ^ uVar8) & 2 ^ uVar8;
            *(ushort *)(puVar9 + 0xf0) = uVar8;
            uVar8 = (local_184 >> 3 ^ uVar8) & 4 ^ uVar8;
            *(ushort *)(puVar9 + 0xf0) = uVar8;
            *(ushort *)(puVar9 + 0xf0) = uVar8 & 0xfff7 | local_184 & 8;
            return 0;
          }
        }
      }
    }
    uVar10 = 0xc0000001;
  }
  else {
    uVar10 = 0xc000009a;
  }
LAB_1c000254d:
  if (*(char *)((longlong)DumpExtension + 0x785) != '\0') {
    HalDmaFreeCrashDumpRegistersEx(DumpExtension[3],0);
    *(undefined1 *)((longlong)DumpExtension + 0x785) = 0;
  }
  return uVar10;
}



===== IdeDumpNotification @ 1c00025b0 =====

void IdeDumpNotification(longlong param_1,int *param_2)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  longlong *plVar4;
  uint uVar5;
  uint uVar6;
  
  plVar4 = DumpExtension;
  iVar2 = *param_2;
  uVar5 = 0;
  if (iVar2 < 7) {
    if (iVar2 != 6) {
      if (iVar2 == 0) {
        lVar3 = *(longlong *)(param_2 + 4);
        if ((*(ushort *)(lVar3 + -0x3c8) & 1) != 0) {
          plVar1 = DumpExtension + 0xd8;
          *(ushort *)(lVar3 + -0x3c8) = *(ushort *)(lVar3 + -0x3c8) & 0xfffe;
          ExpInterlockedPushEntrySList(plVar1,lVar3 + -0x398);
        }
        *(uint *)(plVar4 + 0xcb) = *(uint *)(plVar4 + 0xcb) | 1;
        return;
      }
      if (iVar2 == 1) {
        if ((*(uint *)((longlong)DumpExtension + 0x64c) & 1) == 0) {
          return;
        }
        if ((*(byte *)(DumpExtension + 0x3c) & 1) == 0) {
          return;
        }
        plVar1 = DumpExtension + 0xb5;
        *(char *)((longlong)DumpExtension + 0x5aa) = (char)param_2[5];
        AtaPortCompleteRequest(*plVar4,plVar1);
        return;
      }
      if (iVar2 == 2) {
        DumpExtension[(longlong)param_2[4] + 0xcd] = *(longlong *)(param_2 + 6);
        iVar2 = param_2[8];
        *(uint *)(plVar4 + 0xcb) = *(uint *)(plVar4 + 0xcb) | 5;
        *(int *)((longlong)plVar4 + 0x664) = iVar2;
LAB_1c00026d9:
        *(undefined1 *)(param_2 + 4) = 1;
        return;
      }
      if (iVar2 == 3) {
        if ((*(char *)((longlong)param_2 + 0x11) != -1) &&
           (*(char *)((longlong)param_2 + 0x11) != *(char *)((longlong)DumpExtension + 0x6a9))) {
          return;
        }
        if (param_2[5] != 0) {
          *(int *)(DumpExtension + 0xd3) = param_2[5] * 1000;
          return;
        }
        if ((int)DumpExtension[0xd3] == 0) {
          return;
        }
        *(undefined4 *)(DumpExtension + 0xd3) = 1;
        return;
      }
      if ((iVar2 != 4) && (iVar2 == 5)) {
        uVar5 = param_2[5];
        uVar6 = param_2[4] + 0xfffU & 0xfffff000;
        if ((uVar5 & 0xf) != 0) {
          uVar5 = uVar5 + 0xf & 0xfffffff0;
        }
        *(uint *)(param_1 + -0x730) = uVar6;
        *(uint *)(param_1 + -0x734) = uVar5;
        *(uint *)(param_1 + -0x738) = uVar6 + 0x18 + uVar5;
        *(undefined8 *)(param_2 + 4) = *(undefined8 *)(param_1 + -0x768);
        return;
      }
    }
  }
  else if (iVar2 != 7) {
    if (iVar2 == 8) {
      iVar2 = param_2[5];
      RtlClearBits(DumpExtension + 0xdd,1,(char)iVar2);
      *(char *)(plVar4 + 0xdc) = (char)iVar2;
      *(undefined4 *)((longlong)plVar4 + 0x6e4) = 1;
      goto LAB_1c00026d9;
    }
    if (iVar2 == 9) {
      uVar6 = RtlFindClearBitsAndSet
                        (DumpExtension + 0xdd,1,*(undefined4 *)((longlong)DumpExtension + 0x6e4));
      if (uVar6 != 0xffffffff) {
        uVar5 = uVar6 & 0xff;
        *(uint *)((longlong)plVar4 + 0x6e4) = (uVar5 + 1) % (*(byte *)(plVar4 + 0xdc) + 1);
      }
      *(char *)(param_2 + 4) = (char)uVar5;
      return;
    }
    if (iVar2 == 10) {
      RtlClearBit(DumpExtension + 0xdd,(char)param_2[5]);
      return;
    }
    if ((iVar2 != 0xb) && (iVar2 == 0xc)) {
      IdeDumpGetPhysicalAddress(param_1,(longlong)param_2);
      return;
    }
  }
  param_2[4] = 0;
  param_2[5] = 0;
  return;
}



===== IdeDumpNotify @ 1c0002870 =====

void IdeDumpNotify(int param_1)

{
  char *pcVar1;
  longlong lVar2;
  
  lVar2 = DumpExtension;
  if (param_1 == 2) {
    pcVar1 = (char *)(DumpExtension + 0x782);
    *(undefined1 *)(DumpExtension + 0x783) = 0;
    if (((*pcVar1 == '\0') || (*(char *)(lVar2 + 0x784) != '\0')) &&
       (*(char *)(lVar2 + 0x785) != '\0')) {
      HalDmaFreeCrashDumpRegistersEx(*(undefined8 *)(lVar2 + 0x18),0);
      *(undefined1 *)(DumpExtension + 0x785) = 0;
    }
  }
  return;
}



===== IdeDumpOpen @ 1c00028d0 =====

undefined8 IdeDumpOpen(undefined8 param_1)

{
  longlong lVar1;
  
  lVar1 = DumpExtension;
  *(undefined8 *)(DumpExtension + 0x6b0) = param_1;
  return CONCAT71((int7)((ulonglong)lVar1 >> 8),1);
}



===== IdeDumpPollInterrupt @ 1c00028e8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool IdeDumpPollInterrupt(int param_1)

{
  char cVar1;
  bool bVar2;
  
  if (param_1 == 0) {
    cVar1 = (*(code *)DumpExtension[0x28])(*DumpExtension);
    bVar2 = false;
    if (cVar1 != '\0') {
      bVar2 = true;
    }
  }
  else {
    do {
      (*(code *)DumpExtension[0xd4])(10);
      param_1 = param_1 + -10;
      cVar1 = (*(code *)DumpExtension[0x28])(*DumpExtension);
      if (cVar1 != '\0') break;
    } while (param_1 != 0);
    bVar2 = cVar1 != '\0';
  }
  IdeDumpCompletionDpc();
  return bVar2;
}



===== IdeDumpPortInitialize @ 1c0002978 =====

undefined8 IdeDumpPortInitialize(undefined8 param_1,uint *param_2)

{
  uint uVar1;
  undefined1 *puVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined1 uVar5;
  longlong lVar6;
  
  puVar2 = *(undefined1 **)(param_2 + 0x18);
  uVar5 = 0;
  lVar6 = 0;
  PoSetHiberRange(0,0x10000,puVar2,0x140,0x74647344);
  *(code **)(param_2 + 0xe) = IdeDumpOpen;
  *(code **)(param_2 + 0x10) = IdeDumpWrite;
  *(code **)(param_2 + 0x12) = IdeDumpFinish;
  *(code **)(param_2 + 0x20) = IdeDumpWritePending;
  uVar1 = *param_2;
  if (0xa7 < uVar1) {
    *(code **)(param_2 + 0x28) = IdeDumpRead;
    if (0xaf < uVar1) {
      *(code **)(param_2 + 0x2a) = IdeGetDriveTelemetry;
    }
    if (0xff < uVar1) {
      *(code **)(param_2 + 0x3e) = IdeDumpGetTransferSizes;
    }
    if (0x107 < uVar1) {
      *(code **)(param_2 + 0x40) = IdeDumpNotify;
    }
  }
  param_2[0x1b] = *(uint *)(puVar2 + 8);
  PoSetHiberRange(0,0x10000,*(undefined8 *)(param_2 + 2),0x2000,0x74647344);
  plVar3 = *(longlong **)(param_2 + 2);
  if (*(char *)((longlong)param_2 + 0x6a) == '\x01') {
    lVar6 = plVar3[4];
    uVar5 = *(undefined1 *)((longlong)plVar3 + 0x785);
  }
  DumpExtension = plVar3;
  memset(plVar3,0,0x8000);
  if (*(char *)((longlong)param_2 + 0x6a) == '\x01') {
    plVar3[4] = lVar6;
    *(undefined1 *)((longlong)plVar3 + 0x785) = uVar5;
  }
  plVar3[0xf2] = (longlong)IdeDumpNotification;
  *plVar3 = (longlong)(plVar3 + 0xf3);
  plVar3[0xd4] = *(longlong *)(param_2 + 0xc);
  plVar3[5] = *(longlong *)(param_2 + 4);
  plVar3[6] = *(longlong *)(param_2 + 6);
  plVar3[7] = *(longlong *)(param_2 + 8);
  plVar3[8] = *(longlong *)(param_2 + 10);
  *(uint *)(plVar3 + 0xb) = param_2[0x1c];
  *(undefined1 *)(plVar3 + 0xd5) = *puVar2;
  *(undefined1 *)((longlong)plVar3 + 0x6a9) = puVar2[1];
  *(undefined1 *)((longlong)plVar3 + 0x6aa) = puVar2[2];
  *(undefined4 *)((longlong)plVar3 + 0x69c) = *(undefined4 *)(puVar2 + 8);
  lVar6 = *(longlong *)(puVar2 + 0xe0);
  *(undefined4 *)((longlong)plVar3 + 0x694) = 0xffffffff;
  plVar3[3] = lVar6;
  plVar3[2] = (longlong)puVar2;
  *(undefined4 *)(plVar3 + 0x22) = *(undefined4 *)(puVar2 + 0x10);
  plVar3[0x23] = (longlong)(puVar2 + 0x18);
  InitializeSListHead((PSLIST_HEADER)(plVar3 + 0xd8));
  plVar4 = DumpExtension;
  plVar3 = DumpExtension + 0xdd;
  *(undefined1 *)(DumpExtension + 0xdc) = 0xff;
  *(undefined4 *)plVar3 = 0x100;
  plVar4[0xde] = (longlong)(plVar4 + 0xdf);
  RtlSetAllBits();
  plVar3 = DumpExtension;
  *(undefined4 *)((longlong)plVar4 + 0x6e4) = 0;
  KeQueryPerformanceCounter(plVar3 + 0xe4);
  plVar3 = DumpExtension;
  *(char *)((longlong)DumpExtension + 0x782) = (char)param_2[0x1a];
  *(undefined1 *)((longlong)plVar3 + 0x784) = *(undefined1 *)((longlong)param_2 + 0x69);
  *(undefined1 *)((longlong)plVar3 + 0x783) = *(undefined1 *)((longlong)param_2 + 0x6a);
  return 0;
}



===== IdeDumpRead @ 1c0002bf0 =====

void IdeDumpRead(uint param_1,longlong *param_2,longlong param_3,undefined8 param_4)

{
  IdeDumpIoIssue(param_1,param_2,param_3,param_4,0x102);
  return;
}



===== IdeDumpReadGPLog @ 1c0002c0c =====

undefined8
IdeDumpReadGPLog(undefined8 param_1,undefined1 param_2,undefined8 param_3,byte param_4,
                longlong param_5)

{
  undefined4 *_Dst;
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = DumpExtension;
  if (*(int *)(DumpExtension + 0x198) == 3) {
    _Dst = (undefined4 *)(DumpExtension + 0x1c0);
    memset(_Dst,0,0x480);
    *_Dst = 0x627249;
    *(uint *)(lVar1 + 0x64c) = *(uint *)(lVar1 + 0x64c) | 1;
    *(undefined4 *)(lVar1 + 0x648) = 0;
    *(longlong *)(lVar1 + 0x248) = param_5;
    *(ulonglong *)(lVar1 + 0x230) =
         (ulonglong)*(uint *)(param_5 + 0x2c) + *(longlong *)(param_5 + 0x20);
    *(undefined4 *)(lVar1 + 0x5c0) = *(undefined4 *)(param_5 + 0x28);
    *(code **)(lVar1 + 0x1c8) = _guard_check_icall;
    *(longlong *)(lVar1 + 0x1d0) = param_5;
    *(undefined2 *)(lVar1 + 0x5a8) = 0x100;
    *(undefined1 *)(lVar1 + 0x5ad) = *(undefined1 *)(lVar1 + 0xea);
    *(char *)(lVar1 + 0x5ae) = *(char *)(lVar1 + 0x6a9);
    *(uint *)(lVar1 + 0x5b8) = *(uint *)(lVar1 + 0x5b8) | 0x48;
    *(undefined1 *)(lVar1 + 0x5af) = *(undefined1 *)(lVar1 + 0x6aa);
    *(uint *)(lVar1 + 0x5c0) = (uint)param_4 << 9;
    *(byte *)(lVar1 + 0x5f1) = param_4;
    *(undefined1 *)(lVar1 + 0x5f2) = param_2;
    *(undefined2 *)(lVar1 + 0x5f3) = 0;
    *(undefined4 *)(lVar1 + 0x5bc) = 0x100;
    *(byte *)(lVar1 + 0x5f5) = (-(*(char *)(lVar1 + 0x6a9) != '\0') & 0x10U) + 0xa0;
    *(undefined1 *)(lVar1 + 0x5f6) = 0x2f;
    DispatchCrb((ulonglong)_Dst);
    uVar2 = IdeDumpWaitOnRequest((ulonglong)_Dst,1000);
  }
  else {
    uVar2 = 0xc00000bb;
  }
  return uVar2;
}



===== IdeDumpReadWriteCompletion @ 1c0002d50 =====

void IdeDumpReadWriteCompletion(ulonglong param_1)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  
  lVar3 = DumpExtension;
  lVar2 = *(longlong *)(param_1 + 0x88);
  uVar1 = *(uint *)(DumpExtension + 0x1a8);
  if ((*(char *)(param_1 + 0x3ea) == '\x01') && ((*(byte *)(param_1 + 0x3eb) & 1) == 0)) {
    *(undefined1 *)(param_1 + 0x23) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x400) = 0;
    if ((*(char *)(param_1 + 0x23) == '\0') &&
       ((*(char *)(param_1 + 0x3ea) == '\x05' ||
        (((*(byte *)(param_1 + 0x3eb) & 1) != 0 && (*(char *)(param_1 + 0x3ec) < '\0')))))) {
      *(undefined1 *)(param_1 + 0x23) = 1;
    }
    else {
      if ((*(uint *)(lVar3 + 0x1b8) & 0x7fffffe0) == 0) {
        return;
      }
      *(uint *)(lVar3 + 0x1b8) = *(uint *)(lVar3 + 0x1b8) & 0x1f;
      *(char *)(param_1 + 0x23) = *(char *)(param_1 + 0x23) + '\x01';
    }
  }
  uVar4 = *(int *)(param_1 + 0x400) + *(int *)(param_1 + 0x488);
  *(uint *)(param_1 + 0x488) = uVar4;
  *(int *)(param_1 + 0x480) =
       *(int *)(param_1 + 0x480) + ((uVar1 - 1) + *(int *)(param_1 + 0x400)) / uVar1;
  if (uVar4 < *(uint *)(lVar2 + 0x28)) {
    IdeDumpSetupCrb(lVar3,*(ulonglong *)(param_1 + 0x480),lVar2,uVar4,param_1,
                    *(short *)(param_1 + 1000));
    DispatchCrb(param_1);
  }
  return;
}



===== IdeDumpSetupCrb @ 1c0002e3c =====

void IdeDumpSetupCrb(undefined8 param_1,ulonglong param_2,longlong param_3,uint param_4,
                    longlong param_5,short param_6)

{
  char cVar1;
  ushort uVar2;
  ulonglong uVar3;
  undefined1 uVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  longlong lVar8;
  
  memset((short *)(param_5 + 1000),0,0x58);
  *(undefined8 *)(param_5 + 0x80) = 0;
  *(longlong *)(param_5 + 0x88) = param_3;
  lVar8 = (ulonglong)*(uint *)(param_3 + 0x2c) + *(longlong *)(param_3 + 0x20);
  *(longlong *)(param_5 + 0x70) = lVar8;
  *(uint *)(param_5 + 0x400) = *(int *)(param_3 + 0x28) - param_4;
  *(ulonglong *)(param_5 + 0x70) = lVar8 + (ulonglong)param_4;
  uVar7 = 0x80;
  if (param_6 != 0x103) {
    uVar7 = 0x40;
  }
  *(uint *)(param_5 + 0x3f8) = *(uint *)(param_5 + 0x3f8) | uVar7;
  *(short *)(param_5 + 1000) = 0x103 - (ushort)(param_6 != 0x103);
  *(undefined8 *)(param_5 + 0x10) = 0;
  lVar8 = DumpExtension;
  *(code **)(param_5 + 8) = IdeDumpReadWriteCompletion;
  *(undefined1 *)(param_5 + 0x3ed) = *(undefined1 *)(lVar8 + 0xea);
  cVar1 = *(char *)(lVar8 + 0x6a9);
  *(char *)(param_5 + 0x3ee) = cVar1;
  *(undefined1 *)(param_5 + 0x3ef) = *(undefined1 *)(lVar8 + 0x6aa);
  *(undefined4 *)(param_5 + 0x3fc) = 10;
  if ((*(uint *)(lVar8 + 0x1b8) & 0x7fffffe0) != 0) {
    *(uint *)(param_5 + 0x3f8) = *(uint *)(param_5 + 0x3f8) | 2;
  }
  uVar3 = (ulonglong)(*(int *)(param_5 + 0x400) + -1 + *(uint *)(lVar8 + 0x1a8)) /
          (ulonglong)*(uint *)(lVar8 + 0x1a8);
  uVar4 = (undefined1)uVar3;
  bVar5 = (byte)(param_2 >> 0x18);
  if (*(int *)(lVar8 + 0x198) == 2) {
    if (cVar1 == '\0') {
      bVar5 = bVar5 & 0xf | 0xe0;
    }
    else {
      bVar5 = bVar5 | 0xf0;
    }
    *(byte *)(param_5 + 0x435) = bVar5;
LAB_1c000301d:
    *(char *)(param_5 + 0x432) = (char)param_2;
    *(char *)(param_5 + 0x434) = (char)(param_2 >> 0x10);
    *(undefined1 *)(param_5 + 0x431) = uVar4;
    *(char *)(param_5 + 0x433) = (char)(param_2 >> 8);
  }
  else {
    if (*(int *)(lVar8 + 0x198) == 3) {
      *(uint *)(param_5 + 0x3f8) = *(uint *)(param_5 + 0x3f8) | 8;
      *(byte *)(param_5 + 0x435) = (-(cVar1 != '\0') & 0x10U) - 0x20;
      *(char *)(param_5 + 0x439) = (char)(uVar3 >> 8);
      *(byte *)(param_5 + 0x43a) = bVar5;
      *(char *)(param_5 + 0x43b) = (char)(param_2 >> 0x20);
      *(char *)(param_5 + 0x43c) = (char)(param_2 >> 0x28);
      goto LAB_1c000301d;
    }
    uVar2 = *(ushort *)(lVar8 + 0x1a2);
    uVar7 = (uint)*(ushort *)(lVar8 + 0x1a4);
    *(undefined1 *)(param_5 + 0x431) = uVar4;
    *(char *)(param_5 + 0x432) = (char)((param_2 & 0xffffffff) % (ulonglong)uVar7) + '\x01';
    uVar3 = (param_2 & 0xffffffff) / (ulonglong)(uVar2 * uVar7);
    *(char *)(param_5 + 0x433) = (char)uVar3;
    *(char *)(param_5 + 0x434) = (char)(uVar3 >> 8);
    bVar5 = (byte)(((param_2 & 0xffffffff) / (ulonglong)uVar7) % (ulonglong)uVar2);
    if (cVar1 == '\0') {
      bVar5 = bVar5 | 0xa0;
    }
    else {
      bVar5 = bVar5 | 0xb0;
    }
    *(byte *)(param_5 + 0x435) = bVar5;
  }
  if ((*(uint *)(param_5 + 0x3f8) & 2) == 0) {
    if (*(byte *)(lVar8 + 0x193) < 2) {
      if (param_6 == 0x103) {
        bVar5 = 0x30;
      }
      else {
        bVar5 = (param_6 != 0x102) - 1U & 0x20;
      }
      goto LAB_1c00030fc;
    }
    if (param_6 == 0x103) {
      bVar5 = 0x39;
      bVar6 = 0xc5;
    }
    else {
      if (param_6 != 0x102) {
        if (param_6 == 0x106) {
          bVar5 = (*(int *)(lVar8 + 0x198) != 3) - 1U & 0x2f;
          goto LAB_1c00030fc;
        }
        goto LAB_1c00030dd;
      }
      bVar5 = 0x29;
      bVar6 = 0xc4;
    }
  }
  else if (param_6 == 0x103) {
    bVar5 = 0x35;
    bVar6 = 0xca;
  }
  else {
    if (param_6 != 0x102) {
      if (param_6 == 0x106) {
        bVar5 = (*(int *)(lVar8 + 0x198) != 3) - 1U & 0xb1;
        goto LAB_1c00030fc;
      }
LAB_1c00030dd:
      bVar5 = 0;
      goto LAB_1c00030fc;
    }
    bVar5 = 0x25;
    bVar6 = 200;
  }
  if (*(int *)(lVar8 + 0x198) != 3) {
    bVar5 = bVar6;
  }
LAB_1c00030fc:
  *(byte *)(param_5 + 0x436) = bVar5;
  return;
}



===== IdeDumpTimerTick @ 1c0003128 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void IdeDumpTimerTick(void)

{
  undefined8 *puVar1;
  int *piVar2;
  ulonglong uVar3;
  undefined8 *puVar4;
  int iVar5;
  
  puVar1 = DumpExtension;
  if (((*(int *)(DumpExtension + 0xd3) != 0) &&
      (iVar5 = *(int *)(DumpExtension + 0xd3) + -1, *(int *)(DumpExtension + 0xd3) = iVar5,
      iVar5 == 0)) && (uVar3 = puVar1[0xca], uVar3 != 0)) {
    puVar1[0xca] = 0;
    DispatchCrb(uVar3);
  }
  puVar4 = DumpExtension;
  puVar1 = DumpExtension + 0xd1;
  if ((code *)*puVar1 != (code *)0x0) {
    piVar2 = (int *)(DumpExtension + 0xd2);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      (*(code *)*puVar1)(*puVar4);
      DumpExtension[0xd1] = 0;
      IdeDumpCompletionDpc();
    }
  }
  puVar1 = DumpExtension;
  if ((0 < *(int *)((longlong)DumpExtension + 0x694)) &&
     (iVar5 = *(int *)((longlong)DumpExtension + 0x694) + -1,
     *(int *)((longlong)DumpExtension + 0x694) = iVar5, iVar5 == 0)) {
    *(undefined4 *)((longlong)puVar1 + 0x694) = 0xffffffff;
    (*(code *)puVar1[0x29])(*puVar1);
    IdeDumpCompletionDpc();
  }
  return;
}



===== IdeDumpWaitOnRequest @ 1c00031dc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 IdeDumpWaitOnRequest(ulonglong param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  undefined8 *puVar3;
  byte bVar4;
  longlong lVar5;
  longlong lVar6;
  undefined8 uVar7;
  byte bVar8;
  int local_res8;
  
  (*(code *)DumpExtension[0x28])(*DumpExtension);
  IdeDumpCompletionDpc();
  if ((DumpExtension[0xe3] != 0) && (DumpExtension[0xe4] != 0)) {
    lVar5 = KeQueryPerformanceCounter(0);
    lVar6 = ((lVar5 - DumpExtension[0xe3]) * 1000) / (longlong)DumpExtension[0xe4];
    if (1000 < lVar6) {
      lVar6 = 1000;
    }
    if (lVar6 != 0) {
      for (local_res8 = (int)lVar6; local_res8 != 0; local_res8 = local_res8 + -1) {
        IdeDumpTimerTick();
      }
      DumpExtension[0xe3] = lVar5;
    }
  }
  bVar2 = false;
  while (((cVar1 = *(char *)(param_1 + 0x3ea), cVar1 == '\0' || (cVar1 == 'D')) || (cVar1 == '\a')))
  {
    if (param_2 != 0) {
      IdeDumpPollInterrupt(1000);
      IdeDumpTimerTick();
      bVar2 = true;
    }
    bVar4 = *(byte *)(param_1 + 0x3ea) & 0x5f;
    if ((bVar4 == 7) || (bVar4 == 0x44)) {
      *(undefined2 *)(param_1 + 0x3ea) = 0;
      *(undefined8 *)(param_1 + 0x428) = 0;
      *(undefined8 *)(param_1 + 0x420) = 0;
      *(undefined1 *)(param_1 + 0x3ec) = 0;
      *(undefined1 *)(param_1 + 0x3f3) = 0;
      if ((*(uint *)(param_1 + 0x3f8) & 0xc0) != 0) {
        *(int *)(param_1 + 0x400) =
             *(int *)(*(longlong *)(param_1 + 0x88) + 0x28) - *(int *)(param_1 + 0x488);
      }
      DispatchCrb(param_1);
    }
    if ((param_2 != -1) && ((param_2 == 0 || (param_2 = param_2 + -1, param_2 == 0)))) break;
  }
  if (bVar2) {
    uVar7 = KeQueryPerformanceCounter(0);
    DumpExtension[0xe3] = uVar7;
  }
  puVar3 = DumpExtension;
  bVar4 = *(byte *)(param_1 + 0x3ea);
  if (((bVar4 == 0) || (bVar4 == 0x44)) || (bVar4 == 7)) {
    return 0x103;
  }
  bVar8 = bVar4 & 0x5f;
  if ((bVar4 & 0x5f) == 0) {
    uVar7 = 0x103;
  }
  else if (bVar8 == 1) {
    uVar7 = 0;
  }
  else if (bVar8 == 2) {
    uVar7 = 0x80000005;
  }
  else {
    if (bVar8 != 3) {
      if (bVar8 == 4) {
        uVar7 = 0xc0000010;
        goto LAB_1c00033b8;
      }
      if (bVar8 == 5) {
        uVar7 = 0xc00000b5;
        goto LAB_1c00033b8;
      }
      if (bVar8 == 6) {
        uVar7 = 0xc000009d;
        goto LAB_1c00033b8;
      }
    }
    uVar7 = 0xc0000185;
  }
LAB_1c00033b8:
  *(uint *)(param_1 + 0x48c) = *(uint *)(param_1 + 0x48c) & 0xfffffffe;
  puVar3[0xe3] = 0;
  return uVar7;
}



===== IdeDumpWrite @ 1c0003400 =====

void IdeDumpWrite(longlong *param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  IdeDumpIoIssue(0,param_1,param_2,param_4,0x103);
  return;
}



===== IdeDumpWritePending @ 1c0003430 =====

void IdeDumpWritePending(uint param_1,longlong *param_2,longlong param_3,undefined8 param_4)

{
  IdeDumpIoIssue(param_1,param_2,param_3,param_4,0x103);
  return;
}



===== IdeGetDriveTelemetry @ 1c0003450 =====

ulonglong IdeGetDriveTelemetry
                    (undefined8 param_1,undefined8 param_2,undefined4 *param_3,uint param_4)

{
  ulonglong uVar1;
  uint local_res20 [2];
  
  if (param_4 < 300) {
    uVar1 = 0xc0000023;
  }
  else {
    param_3[2] = 300;
    param_3[0x40] = 300;
    param_3[1] = 1;
    param_3[0x41] = 1;
    *param_3 = 0x53445443;
    local_res20[0] = param_4;
    uVar1 = FillBufferWithDeviceTelemetryDump((longlong)param_3,local_res20);
    if (-1 < (int)uVar1) {
      param_3[0x40] = local_res20[0];
    }
  }
  return uVar1;
}



===== IdeReadGeneralPurposeLog @ 1c00034bc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
IdeReadGeneralPurposeLog
          (undefined8 param_1,undefined1 param_2,undefined8 param_3,byte param_4,ulonglong param_5,
          uint param_6)

{
  undefined8 uVar1;
  undefined1 *puVar2;
  ulonglong uVar3;
  undefined1 auStackY_108 [32];
  undefined1 local_d8 [8];
  short local_d0;
  undefined2 local_ce;
  ulonglong local_b8;
  uint local_b0;
  uint local_ac;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_108;
  memset(local_d8,0,0xb8);
  if (param_6 < 0x10001) {
    local_b0 = param_6;
    local_ce = 0;
    puVar2 = local_d8;
    uVar3 = param_5 & 0xfffffffffffff000;
    local_d0 = ((short)((ulonglong)param_6 + 0xfff + (param_5 & 0xfff) >> 0xc) + 6) * 8;
    local_ac = (uint)param_5 & 0xfff;
    local_b8 = uVar3;
    MmBuildMdlForNonPagedPool();
    uVar1 = IdeDumpReadGPLog(puVar2,param_2,uVar3,param_4,(longlong)local_d8);
  }
  else {
    uVar1 = 0xc000000d;
  }
  return uVar1;
}



===== AtaPortAllocateQueueTag @ 1c00035b0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AtaPortAllocateQueueTag(longlong param_1,undefined1 param_2,undefined1 param_3)

{
  undefined8 uVar1;
  undefined8 local_48;
  longlong lStack_40;
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x35b0  1  AtaPortAllocateQueueTag */
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 9;
  local_38 = (ulonglong)CONCAT11(param_2,param_3);
  lStack_40 = param_1;
  uVar1 = (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),(undefined1)local_38);
}



===== AtaPortBuildRequestSenseIrb @ 1c0003610 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AtaPortBuildRequestSenseIrb(longlong param_1,undefined8 param_2)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x3610  2  AtaPortBuildRequestSenseIrb */
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 7;
  uStack_30 = 1;
  lStack_40 = param_1;
  local_38 = param_2;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return local_38;
}



===== AtaPortCompleteAllActiveRequests @ 1c0003670 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtaPortCompleteAllActiveRequests
               (longlong param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x3670  3  AtaPortCompleteAllActiveRequests */
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 1;
  local_38 = (ulonglong)CONCAT14(param_4,(uint)CONCAT11(param_2,param_3));
  lStack_40 = param_1;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return;
}



===== AtaPortCompleteRequest @ 1c00036d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtaPortCompleteRequest(longlong param_1,undefined8 param_2)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x36d0  4  AtaPortCompleteRequest */
  local_48 = 0;
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  lStack_40 = param_1;
  local_38 = param_2;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return;
}



===== AtaPortConvertPhysicalAddressToUlong @ 1c0003720 =====

undefined4 AtaPortConvertPhysicalAddressToUlong(undefined4 param_1)

{
                    /* 0x3720  5  AtaPortConvertPhysicalAddressToUlong */
  return param_1;
}



===== AtaPortConvertUlongToPhysicalAddress @ 1c0003730 =====

undefined8 AtaPortConvertUlongToPhysicalAddress(undefined8 param_1)

{
                    /* 0x3730  6  AtaPortConvertUlongToPhysicalAddress */
  return param_1;
}



===== AtaPortCopyMemory @ 1c0003740 =====

void AtaPortCopyMemory(void *param_1,void *param_2,uint param_3)

{
                    /* 0x3740  7  AtaPortCopyMemory
                       0x3740  22  AtaPortMoveMemory */
  memcpy(param_1,param_2,(ulonglong)param_3);
  return;
}



===== AtaPortDebugBreak @ 1c0003760 =====

void AtaPortDebugBreak(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== AtaPortDebugPrint @ 1c0003770 =====

void AtaPortDebugPrint(int param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_res18;
  undefined8 local_res20;
  
                    /* 0x3770  9  AtaPortDebugPrint */
  if (param_1 == 0) {
    param_1 = 1;
  }
  else if ((param_1 == 1) || (param_1 == 2)) {
    param_1 = 2;
  }
  else if (param_1 == 3) {
  }
  local_res18 = param_3;
  local_res20 = param_4;
  vDbgPrintExWithPrefix("AtaMini: ",0x39,param_1,param_2,&local_res18);
  return;
}



===== AtaPortDeviceStateChange @ 1c00037e0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtaPortDeviceStateChange
               (longlong param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4)

{
  undefined8 local_48;
  longlong lStack_40;
  uint local_38;
  undefined4 uStack_34;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x37e0  10  AtaPortDeviceStateChange */
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 3;
  _local_38 = CONCAT44(param_4,(uint)CONCAT11(param_2,param_3));
  lStack_40 = param_1;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return;
}



===== AtaPortEtwTraceLog @ 1c0003840 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AtaPortEtwTraceLog(int param_1,longlong param_2,uint param_3)

{
  uint uVar1;
  undefined *puVar2;
  char cVar3;
  undefined1 auStack_58 [32];
  ulonglong local_38;
  longlong local_28;
  ulonglong uStack_20;
  ulonglong local_18;
  
                    /* 0x3840  11  AtaPortEtwTraceLog */
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = 0;
  uStack_20 = 0;
  if (AtaEtwEnabled == '\0') {
    return;
  }
  if (param_1 == 1) {
    puVar2 = &ATAPORT_EVENT_LPM_POWERSTATE_PARTIAL;
  }
  else {
    if (param_1 != 2) {
      if (param_1 == 3) {
        puVar2 = &ATAPORT_EVENT_CHANNEL_START_INIT;
      }
      else {
        if (param_1 != 4) {
          if (param_1 == 5) {
            puVar2 = &ATAPORT_EVENT_CHANNEL_RESET_INIT;
          }
          else {
            if (param_1 != 6) {
              puVar2 = (undefined *)0x0;
              uVar1 = 0;
              goto LAB_1c00038d5;
            }
            puVar2 = &ATAPORT_EVENT_CHANNEL_RESET_COMPLETE;
          }
          uVar1 = 8;
          goto LAB_1c00038d5;
        }
        puVar2 = &ATAPORT_EVENT_CHANNEL_START_COMPLETE;
      }
      uVar1 = 2;
      goto LAB_1c00038d5;
    }
    puVar2 = &ATAPORT_EVENT_LPM_POWERSTATE_SLUMBER;
  }
  uVar1 = 0x20;
LAB_1c00038d5:
  if ((_AtaMatchAnyKeyword & uVar1) != 0) {
    if ((param_2 == 0) || (param_3 == 0)) {
      cVar3 = '\0';
    }
    else {
      cVar3 = '\x01';
      uStack_20 = (ulonglong)param_3;
      local_28 = param_2;
    }
    if (puVar2 != (undefined *)0x0) {
      local_38 = -(ulonglong)(cVar3 != '\0') & (ulonglong)&local_28;
      EtwWrite(AtaEtwHandle,puVar2,0,cVar3);
    }
  }
  return;
}



===== AtaPortGetBusData @ 1c0003950 =====

undefined8 AtaPortGetBusData(void)

{
                    /* 0x3950  12  AtaPortGetBusData
                       0x3950  14  AtaPortGetParentBusType
                       0x3950  45  AtaPortSetBusData */
  return 0;
}



===== AtaPortGetDeviceBase @ 1c0003960 =====

undefined8 AtaPortGetDeviceBase(undefined8 param_1,undefined8 param_2)

{
                    /* 0x3960  13  AtaPortGetDeviceBase */
  return param_2;
}



===== AtaPortGetPhysicalAddress @ 1c0003970 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
AtaPortGetPhysicalAddress(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 local_48;
  longlong local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  
                    /* 0x3970  15  AtaPortGetPhysicalAddress */
  local_48 = 0xc;
  local_20 = 0;
  local_18 = 0;
  local_40 = param_1;
  local_38 = param_2;
  local_30 = param_3;
  local_28 = param_4;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return local_38;
}



===== AtaPortGetScatterGatherList @ 1c00039c0 =====

undefined8 AtaPortGetScatterGatherList(undefined8 param_1,longlong param_2)

{
                    /* 0x39c0  16  AtaPortGetScatterGatherList */
  return *(undefined8 *)(param_2 + -8);
}



===== AtaPortGetUnCachedExtension @ 1c00039d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AtaPortGetUnCachedExtension(longlong param_1,undefined4 param_2,undefined4 param_3)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x39d0  17  AtaPortGetUnCachedExtension */
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 5;
  local_38 = CONCAT44(param_3,param_2);
  lStack_40 = param_1;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return local_38;
}



===== AtaPortInitialize @ 1c0003a30 =====

void AtaPortInitialize(undefined8 param_1,undefined8 param_2,undefined *param_3,int param_4)

{
                    /* 0x3a30  18  AtaPortInitialize */
  IdeDumpMiniportChannelInitialize(param_1,param_2,param_3,param_4);
  return;
}



===== AtaPortInitializeEx @ 1c0003a50 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AtaPortInitializeEx(undefined8 param_1,undefined8 param_2,longlong *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  longlong *plStack_10;
  
                    /* 0x3a50  19  AtaPortInitializeEx */
  plVar6 = DumpExtension;
  if ((uint)(*(int *)((longlong)param_3 + 4) + 0x798 + (int)param_3[1]) < 0x8001) {
    lVar5 = param_3[1];
    DumpExtension[0x2b] = *param_3;
    plVar6[0x2c] = lVar5;
    uVar1 = *(undefined4 *)((longlong)param_3 + 0x14);
    lVar5 = param_3[3];
    uVar2 = *(undefined4 *)((longlong)param_3 + 0x1c);
    *(int *)(plVar6 + 0x2d) = (int)param_3[2];
    *(undefined4 *)((longlong)plVar6 + 0x16c) = uVar1;
    *(int *)(plVar6 + 0x2e) = (int)lVar5;
    *(undefined4 *)((longlong)plVar6 + 0x174) = uVar2;
    lVar5 = param_3[5];
    plVar6[0x2f] = param_3[4];
    plVar6[0x30] = lVar5;
    lVar5 = (ulonglong)*(uint *)(param_3 + 1) + *plVar6;
    plVar6[1] = lVar5;
    local_28 = 0;
    uStack_20 = 0;
    local_18 = 0;
    plStack_10 = (longlong *)0x0;
    if ((code *)param_3[5] != (code *)0x0) {
      plStack_10 = plVar6 + 0x22;
      local_28 = 0x100020020;
      plVar6 = (longlong *)0x0;
      uStack_20 = 0x2000000000022;
      local_18 = 0x1000100;
      cVar3 = (*(code *)param_3[5])(lVar5,0,&local_28);
      if (cVar3 == '\0') {
        return 0xc0000001;
      }
    }
    uVar4 = IdeDumpMiniportChannelInitialize(lVar5,plVar6,(undefined *)param_3[2],(int)param_3[1]);
  }
  else {
    uVar4 = 0xc000009a;
  }
  return uVar4;
}



===== AtaPortInitializeQueueTag @ 1c0003b40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AtaPortInitializeQueueTag
                    (longlong param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined8 uVar1;
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x3b40  20  AtaPortInitializeQueueTag */
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 8;
  local_38 = (ulonglong)CONCAT14(param_4,(uint)CONCAT11(param_2,param_3));
  lStack_40 = param_1;
  uVar1 = (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),(undefined1)local_38);
}



===== AtaPortLogError @ 1c0003ba0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtaPortLogError(longlong param_1,undefined8 param_2)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x3ba0  21  AtaPortLogError */
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 6;
  lStack_40 = param_1;
  local_38 = param_2;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return;
}



===== AtaPortNotification @ 1c0003bf0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtaPortNotification(uint param_1,longlong param_2,undefined1 param_3,undefined1 param_4,
                        uint param_5)

{
  undefined8 local_40;
  longlong lStack_38;
  undefined8 local_30;
  ulonglong uStack_28;
  undefined8 local_20;
  undefined8 uStack_18;
  undefined4 local_10;
  
                    /* 0x3bf0  23  AtaPortNotification */
  local_10 = 0;
  local_40 = 4;
  uStack_28 = 0;
  local_30 = (ulonglong)param_1;
  local_20 = 0;
  uStack_18 = 0;
  if ((param_1 == 0) || (param_1 == 1)) {
    local_30._0_5_ = CONCAT14(param_4,param_1);
    local_30 = (ulonglong)CONCAT15(param_3,(undefined5)local_30);
  }
  else if (param_1 == 2) {
    local_30._0_5_ = CONCAT14(param_4,2);
    local_30 = (ulonglong)CONCAT15(param_3,(undefined5)local_30);
    uStack_28 = (ulonglong)param_5;
  }
  lStack_38 = param_2;
  (**(code **)(param_2 + -8))((undefined8 *)(param_2 + -8),&local_40);
  return;
}



===== AtaPortQuerySystemTime @ 1c0003c90 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AtaPortQuerySystemTime(undefined8 *param_1)

{
                    /* 0x3c90  24  AtaPortQuerySystemTime */
  *param_1 = _DAT_fffff78000000014;
  return;
}



===== AtaPortReadPortBufferUchar @ 1c0003cb0 =====

void AtaPortReadPortBufferUchar(undefined2 param_1,undefined1 *param_2,uint param_3)

{
  undefined1 uVar1;
  ulonglong uVar2;
  
                    /* 0x3cb0  25  AtaPortReadPortBufferUchar */
  uVar2 = (ulonglong)param_3;
  while (uVar2 != 0) {
    uVar2 = uVar2 - 1;
    uVar1 = in(param_1);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortReadPortBufferUlong @ 1c0003cd0 =====

void AtaPortReadPortBufferUlong(undefined2 param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  ulonglong uVar2;
  
                    /* 0x3cd0  26  AtaPortReadPortBufferUlong */
  uVar2 = (ulonglong)param_3;
  while (uVar2 != 0) {
    uVar2 = uVar2 - 1;
    uVar1 = in(param_1);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortReadPortBufferUshort @ 1c0003cf0 =====

void AtaPortReadPortBufferUshort(undefined2 param_1,undefined2 *param_2,uint param_3)

{
  undefined2 uVar1;
  ulonglong uVar2;
  
                    /* 0x3cf0  27  AtaPortReadPortBufferUshort */
  uVar2 = (ulonglong)param_3;
  while (uVar2 != 0) {
    uVar2 = uVar2 - 1;
    uVar1 = in(param_1);
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortReadPortUchar @ 1c0003d10 =====

undefined1 AtaPortReadPortUchar(undefined2 param_1)

{
  undefined1 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}



===== AtaPortReadPortUlong @ 1c0003d20 =====

undefined4 AtaPortReadPortUlong(undefined2 param_1)

{
  undefined4 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}



===== AtaPortReadPortUshort @ 1c0003d30 =====

undefined2 AtaPortReadPortUshort(undefined2 param_1)

{
  undefined2 uVar1;
  
  uVar1 = in(param_1);
  return uVar1;
}



===== AtaPortReadRegisterBufferUchar @ 1c0003d50 =====

void AtaPortReadRegisterBufferUchar(undefined1 *param_1,undefined1 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x3d50  31  AtaPortReadRegisterBufferUchar */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortReadRegisterBufferUlong @ 1c0003d80 =====

void AtaPortReadRegisterBufferUlong(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x3d80  32  AtaPortReadRegisterBufferUlong */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortReadRegisterBufferUshort @ 1c0003db0 =====

void AtaPortReadRegisterBufferUshort(undefined2 *param_1,undefined2 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x3db0  33  AtaPortReadRegisterBufferUshort */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortReadRegisterUchar @ 1c0003de0 =====

undefined1 AtaPortReadRegisterUchar(undefined1 *param_1)

{
  return *param_1;
}



===== AtaPortReadRegisterUlong @ 1c0003df0 =====

undefined4 AtaPortReadRegisterUlong(undefined4 *param_1)

{
  return *param_1;
}



===== AtaPortReadRegisterUshort @ 1c0003e00 =====

undefined2 AtaPortReadRegisterUshort(undefined2 *param_1)

{
  return *param_1;
}



===== AtaPortRegistryAllocateBuffer @ 1c0003e10 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 AtaPortRegistryAllocateBuffer(longlong param_1,uint param_2)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong uStack_20;
  undefined4 local_18;
  
                    /* 0x3e10  37  AtaPortRegistryAllocateBuffer */
  uStack_30 = 0;
  local_38 = 0;
  local_28 = 0;
  local_18 = 0;
  uStack_20 = (ulonglong)param_2;
  local_48 = 0xb;
  lStack_40 = param_1;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return local_38;
}



===== AtaPortRegistryFreeBuffer @ 1c0003e70 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtaPortRegistryFreeBuffer(longlong param_1,undefined8 param_2)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x3e70  38  AtaPortRegistryFreeBuffer */
  uStack_20 = 0;
  local_18 = 0;
  uStack_30 = 0;
  local_48 = 0xb;
  local_38 = 1;
  lStack_40 = param_1;
  local_28 = param_2;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return;
}



===== AtaPortRegistryRead @ 1c0003ed0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AtaPortRegistryRead(longlong param_1,undefined1 param_2,undefined1 param_3,
                             undefined8 param_4,undefined1 param_5,undefined8 param_6,
                             undefined8 param_7)

{
  undefined8 uVar1;
  undefined8 local_48;
  longlong local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  
                    /* 0x3ed0  39  AtaPortRegistryRead */
  local_15 = 0;
  local_16 = param_5;
  local_28 = param_6;
  local_20 = param_7;
  local_48 = 0xb;
  local_38 = 2;
  local_40 = param_1;
  local_30 = param_4;
  local_18 = param_3;
  local_17 = param_2;
  uVar1 = (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),(undefined1)local_38);
}



===== AtaPortRegistryWrite @ 1c0003f40 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AtaPortRegistryWrite
                    (longlong param_1,undefined1 param_2,undefined1 param_3,undefined8 param_4,
                    undefined1 param_5,undefined8 param_6,undefined8 param_7)

{
  undefined8 uVar1;
  undefined8 local_48;
  longlong local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  
                    /* 0x3f40  40  AtaPortRegistryWrite */
  local_15 = 0;
  local_16 = param_5;
  local_28 = param_6;
  local_20 = param_7;
  local_48 = 0xb;
  local_38 = 3;
  local_40 = param_1;
  local_30 = param_4;
  local_18 = param_3;
  local_17 = param_2;
  uVar1 = (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),(undefined1)local_38);
}



===== AtaPortRegistryWriteDeferred @ 1c0003fb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AtaPortRegistryWriteDeferred
                    (longlong param_1,undefined1 param_2,undefined1 param_3,undefined8 param_4,
                    undefined1 param_5,undefined8 param_6,undefined8 param_7)

{
  undefined8 uVar1;
  undefined8 local_48;
  longlong local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  
                    /* 0x3fb0  41  AtaPortRegistryWriteDeferred */
  local_15 = 0;
  local_16 = param_5;
  local_28 = param_6;
  local_20 = param_7;
  local_48 = 0xb;
  local_38 = 4;
  local_40 = param_1;
  local_30 = param_4;
  local_18 = param_3;
  local_17 = param_2;
  uVar1 = (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),(undefined1)local_38);
}



===== AtaPortReleaseQueueTag @ 1c0004020 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtaPortReleaseQueueTag
               (longlong param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x4020  42  AtaPortReleaseQueueTag */
  uStack_30 = 0;
  local_18 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 10;
  local_38 = (ulonglong)CONCAT14(param_4,(uint)CONCAT11(param_2,param_3));
  lStack_40 = param_1;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return;
}



===== AtaPortReleaseRequestSenseIrb @ 1c0004080 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AtaPortReleaseRequestSenseIrb(longlong param_1,undefined8 param_2)

{
  undefined8 local_48;
  longlong lStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  undefined4 local_18;
  
                    /* 0x4080  43  AtaPortReleaseRequestSenseIrb */
  local_18 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_48 = 7;
  lStack_40 = param_1;
  local_38 = param_2;
  (**(code **)(param_1 + -8))((undefined8 *)(param_1 + -8),&local_48);
  return;
}



===== AtaPortRequestCallback @ 1c00040d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1
AtaPortRequestCallback(undefined4 param_1,longlong param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 local_48;
  longlong local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined8 local_30;
  undefined4 local_28;
  undefined8 local_24;
  undefined8 uStack_1c;
  
                    /* 0x40d0  44  AtaPortRequestCallback */
  local_34 = 0;
  local_48 = 2;
  local_24 = 0;
  uStack_1c = 0;
  local_40 = param_2;
  local_38 = param_1;
  local_30 = param_3;
  local_28 = param_4;
  (**(code **)(param_2 + -8))((undefined8 *)(param_2 + -8),&local_48);
  return (undefined1)local_38;
}



===== AtaPortStallExecution @ 1c0004120 =====

void AtaPortStallExecution(void)

{
                    /* 0x4120  46  AtaPortStallExecution */
  KeStallExecutionProcessor();
  return;
}



===== AtaPortTraceNotification @ 1c0004140 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong AtaPortTraceNotification
                    (undefined8 param_1,undefined8 param_2,uint param_3,longlong *param_4)

{
  longlong lVar1;
  longlong lVar2;
  byte bVar3;
  uint uVar4;
  ulonglong uVar5;
  longlong lVar6;
  uint uVar7;
  ulonglong uVar8;
  
                    /* 0x4140  47  AtaPortTraceNotification */
  lVar6 = 0;
  if (param_3 < 0x7d4) {
    if (param_3 == 0x7d3) {
      uVar5 = WmiQueryTraceInformation
                        ((int)*param_4,param_4[1],(int)param_4[2],param_4[3],param_4[4]);
    }
    else {
      if (param_3 == 1000) {
        uVar5 = PortTraceInitTracing(param_4);
        return uVar5;
      }
      if (param_3 == 0x3e9) {
        lVar6 = *param_4;
        PortTraceErrorFreeDriver(lVar6);
        if (*(code **)(lVar6 + 0x10) != (code *)0x0) {
          (**(code **)(lVar6 + 0x10))(*(undefined8 *)(lVar6 + 8));
        }
        uVar5 = ExFreePoolWithTag(lVar6,0);
        return uVar5;
      }
      if (param_3 != 2000) {
        uVar4 = param_3 - 0x7d1;
        if (uVar4 == 0) {
          uVar5 = PortTraceInitGlobalLogger(param_4);
          return uVar5;
        }
        if (uVar4 == 1) {
          uVar5 = IoWMIRegistrationControl(*param_4,(int)param_4[1]);
          *(int *)((longlong)param_4 + 0xc) = (int)uVar5;
          return uVar5;
        }
        return (ulonglong)uVar4;
      }
      uVar5 = WmiTraceMessageVa(*param_4,(int)param_4[1],param_4[2],(short)param_4[3],param_4[4]);
    }
    *(int *)(param_4 + 5) = (int)uVar5;
    return uVar5;
  }
  if (param_3 == 0x7d4) {
    uVar5 = RtlInitUnicodeString(*param_4,param_4[1]);
    return uVar5;
  }
  if (param_3 == 4000) {
    lVar6 = *param_4;
    ExpInterlockedPushEntrySList(lVar6 + 0x40,param_4[1] + -0x20);
    bVar3 = KeGetCurrentIrql();
    if (bVar3 < 3) {
      uVar5 = PortTraceErrorDrainList(*(undefined8 *)(lVar6 + 8),lVar6 + 0x40);
      return uVar5;
    }
    LOCK();
    *(int *)(lVar6 + 0x54) = *(int *)(lVar6 + 0x54) + 1;
    UNLOCK();
    uVar5 = KeInsertQueueDpc(lVar6 + 0x58,0,0);
    return uVar5;
  }
  uVar4 = param_3 - 0xfa1;
  if (uVar4 != 0) {
    if (uVar4 == 1) {
      uVar5 = param_4[1];
      LOCK();
      *(undefined4 *)(uVar5 - 0x10) = 0;
      UNLOCK();
      return uVar5;
    }
    return (ulonglong)uVar4;
  }
  uVar4 = *(uint *)(param_4 + 1);
  lVar1 = *param_4;
  uVar5 = 0;
  if ((uVar4 < 0xf1) && (uVar8 = 0, *(int *)(lVar1 + 0x50) != 0)) {
    do {
      uVar5 = *(ulonglong *)(lVar1 + 0x38);
      lVar2 = *(longlong *)(uVar5 + uVar8 * 8);
      if (*(int *)(lVar2 + 0x10) == 0) {
        uVar5 = 0;
        LOCK();
        uVar7 = *(uint *)(lVar2 + 0x10);
        if (uVar7 == 0) {
          *(uint *)(lVar2 + 0x10) = 1;
        }
        else {
          uVar5 = (ulonglong)uVar7;
        }
        UNLOCK();
        if (uVar7 == 0) {
          *(uint *)(lVar2 + 0x14) = uVar4;
          lVar6 = lVar2 + 0x20;
          break;
        }
      }
      uVar7 = (int)uVar8 + 1;
      uVar8 = (ulonglong)uVar7;
    } while (uVar7 < *(uint *)(lVar1 + 0x50));
  }
  param_4[2] = lVar6;
  return uVar5;
}



===== AtaPortWritePortBufferUchar @ 1c0004360 =====

void AtaPortWritePortBufferUchar(undefined2 param_1,undefined1 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x4360  48  AtaPortWritePortBufferUchar */
  uVar1 = (ulonglong)param_3;
  while (uVar1 != 0) {
    uVar1 = uVar1 - 1;
    out(*param_2,param_1);
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortWritePortBufferUlong @ 1c0004380 =====

void AtaPortWritePortBufferUlong(undefined2 param_1,undefined4 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x4380  49  AtaPortWritePortBufferUlong */
  uVar1 = (ulonglong)param_3;
  while (uVar1 != 0) {
    uVar1 = uVar1 - 1;
    out(*param_2,param_1);
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortWritePortBufferUshort @ 1c00043a0 =====

void AtaPortWritePortBufferUshort(undefined2 param_1,undefined2 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x43a0  50  AtaPortWritePortBufferUshort */
  uVar1 = (ulonglong)param_3;
  while (uVar1 != 0) {
    uVar1 = uVar1 - 1;
    out(*param_2,param_1);
    param_2 = param_2 + 1;
  }
  return;
}



===== AtaPortWritePortUchar @ 1c00043c0 =====

undefined1 AtaPortWritePortUchar(undefined2 param_1,undefined1 param_2)

{
                    /* 0x43c0  51  AtaPortWritePortUchar */
  out(param_1,param_2);
  return param_2;
}



===== AtaPortWritePortUlong @ 1c00043d0 =====

undefined4 AtaPortWritePortUlong(undefined2 param_1,undefined4 param_2)

{
                    /* 0x43d0  52  AtaPortWritePortUlong */
  out(param_1,param_2);
  return param_2;
}



===== AtaPortWritePortUshort @ 1c00043e0 =====

undefined2 AtaPortWritePortUshort(undefined2 param_1,undefined2 param_2)

{
                    /* 0x43e0  53  AtaPortWritePortUshort */
  out(param_1,param_2);
  return param_2;
}



===== AtaPortWriteRegisterBufferUchar @ 1c0004400 =====

void AtaPortWriteRegisterBufferUchar(undefined1 *param_1,undefined1 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x4400  54  AtaPortWriteRegisterBufferUchar */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== AtaPortWriteRegisterBufferUlong @ 1c0004430 =====

void AtaPortWriteRegisterBufferUlong(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x4430  55  AtaPortWriteRegisterBufferUlong */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== AtaPortWriteRegisterBufferUshort @ 1c0004460 =====

void AtaPortWriteRegisterBufferUshort(undefined2 *param_1,undefined2 *param_2,uint param_3)

{
  ulonglong uVar1;
  
                    /* 0x4460  56  AtaPortWriteRegisterBufferUshort */
  for (uVar1 = (ulonglong)param_3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  LOCK();
  UNLOCK();
  return;
}



===== AtaPortWriteRegisterUchar @ 1c0004490 =====

void AtaPortWriteRegisterUchar(undefined1 *param_1,undefined1 param_2)

{
                    /* 0x4490  57  AtaPortWriteRegisterUchar */
  *param_1 = param_2;
  LOCK();
  UNLOCK();
  return;
}



===== AtaPortWriteRegisterUlong @ 1c00044a0 =====

void AtaPortWriteRegisterUlong(undefined4 *param_1,undefined4 param_2)

{
                    /* 0x44a0  58  AtaPortWriteRegisterUlong */
  *param_1 = param_2;
  LOCK();
  UNLOCK();
  return;
}



===== AtaPortWriteRegisterUshort @ 1c00044b0 =====

void AtaPortWriteRegisterUshort(undefined2 *param_1,undefined2 param_2)

{
                    /* 0x44b0  59  AtaPortWriteRegisterUshort */
  *param_1 = param_2;
  LOCK();
  UNLOCK();
  return;
}



===== DriverEntry @ 1c00044c0 =====

void DriverEntry(undefined8 param_1,uint *param_2)

{
  IdeDumpPortInitialize(param_1,param_2);
  return;
}



===== DumpPreInitialize @ 1c00044e0 =====

void DumpPreInitialize(void)

{
                    /* 0x44e0  60  DumpPreInitialize */
  wil_InitializeFeatureStaging();
  return;
}



===== DumpUninitialize @ 1c0004500 =====

void DumpUninitialize(void)

{
                    /* 0x4500  61  DumpUninitialize */
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



===== wil_details_RecordCachedUsage @ 1c0004558 =====

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



===== wil_details_RecordFeatureUsageReporting @ 1c00046b0 =====

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



===== PortTraceErrorDrainList @ 1c0004734 =====

void PortTraceErrorDrainList(undefined8 param_1,undefined8 param_2)

{
  void *_Dst;
  longlong lVar1;
  
  while( true ) {
    lVar1 = ExpInterlockedPopEntrySList(param_2);
    if (lVar1 == 0) break;
    _Dst = (void *)IoAllocateErrorLogEntry(param_1,*(undefined1 *)(lVar1 + 0x14));
    if (_Dst != (void *)0x0) {
      memcpy(_Dst,(void *)(lVar1 + 0x20),(ulonglong)*(uint *)(lVar1 + 0x14));
      IoWriteErrorLogEntry(_Dst);
    }
    LOCK();
    *(undefined4 *)(lVar1 + 0x10) = 0;
    UNLOCK();
  }
  return;
}



===== PortpErrorDrainListDpc @ 1c00047d0 =====

void PortpErrorDrainListDpc(undefined8 param_1,longlong param_2)

{
  PortTraceErrorDrainList(*(undefined8 *)(param_2 + 8),param_2 + 0x40);
  LOCK();
  *(int *)(param_2 + 0x54) = *(int *)(param_2 + 0x54) + -1;
  UNLOCK();
  return;
}



===== PortpErrorInitDpc @ 1c00047f8 =====

void PortpErrorInitDpc(longlong param_1)

{
  KeInitializeDpc(param_1 + 0x58,PortpErrorDrainListDpc,param_1);
  return;
}



===== PortTraceInitGlobalLogger @ 1c0004824 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void PortTraceInitGlobalLogger(undefined8 *param_1)

{
  uint *puVar1;
  undefined8 *puVar2;
  uint *puVar3;
  undefined1 *puVar4;
  int iVar5;
  code *pcVar6;
  longlong lVar7;
  undefined1 auStack_198 [32];
  undefined8 local_178;
  undefined4 local_168;
  int local_164;
  uint local_160;
  undefined4 local_15c;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined4 local_140;
  wchar_t *local_138;
  uint *local_130;
  undefined4 local_128;
  undefined4 *local_120;
  undefined4 local_118;
  undefined8 local_110;
  undefined4 local_108;
  wchar_t *local_100;
  undefined4 *local_f8;
  undefined4 local_f0;
  undefined4 *local_e8;
  undefined4 local_e0;
  undefined8 local_d8;
  undefined4 local_d0;
  wchar_t local_98 [56];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_198;
  puVar1 = (uint *)*param_1;
  puVar2 = (undefined8 *)param_1[1];
  puVar3 = (uint *)param_1[2];
  puVar4 = (undefined1 *)param_1[3];
  builtin_wcsncpy(local_98 + 8,L"alLogger\\",10);
  local_138 = L"Start";
  local_130 = (uint *)&local_164;
  local_120 = &local_168;
  local_160 = 0;
  local_15c = 0;
  local_164 = 0;
  local_168 = 0;
  local_98[0x12] = 0;
  builtin_wcsncpy(local_98,L"WMI\\Glob",8);
  local_148 = 0;
  local_140 = 0x120;
  local_128 = 0x4000004;
  local_118 = 4;
  local_110 = 0;
  local_108 = 0;
  local_158 = 0;
  uStack_150 = 0;
  RtlInitUnicodeString(&local_158,L"RtlQueryRegistryValuesEx");
  pcVar6 = (code *)MmGetSystemRoutineAddress(&local_158);
  local_178 = 0;
  if (pcVar6 == (code *)0x0) {
    pcVar6 = RtlQueryRegistryValues_exref;
  }
  iVar5 = (*pcVar6)(0x80000002,local_98,&local_148,0);
  if ((-1 < iVar5) && (local_164 != 0)) {
    local_148 = 0;
    local_138 = L"Flags";
    local_130 = &local_160;
    local_140 = 0x120;
    local_120 = &local_168;
    local_100 = L"Level";
    local_f8 = &local_15c;
    local_e8 = &local_168;
    lVar7 = -1;
    local_128 = 0x4000004;
    local_118 = 4;
    local_110 = 0;
    local_108 = 0x120;
    local_f0 = 0x4000004;
    local_e0 = 1;
    local_d8 = 0;
    local_d0 = 0;
    do {
      lVar7 = lVar7 + 1;
    } while (local_98[lVar7] != L'\0');
    WppGuidToStr((longlong)(local_98 + lVar7),puVar1);
    local_158 = 0;
    uStack_150 = 0;
    RtlInitUnicodeString(&local_158,L"RtlQueryRegistryValuesEx");
    pcVar6 = (code *)MmGetSystemRoutineAddress(&local_158);
    local_178 = 0;
    if (pcVar6 == (code *)0x0) {
      pcVar6 = RtlQueryRegistryValues_exref;
    }
    iVar5 = (*pcVar6)(0x80000002,local_98,&local_148,0);
    if ((-1 < iVar5) && (local_164 == 1)) {
      *puVar2 = 1;
      *puVar3 = local_160 & 0x7fffffff;
      *puVar4 = (undefined1)local_15c;
    }
  }
  return;
}



===== PortTraceInitTracing @ 1c0004a90 =====

void PortTraceInitTracing(undefined8 *param_1)

{
  int *piVar1;
  longlong lVar2;
  undefined4 *puVar3;
  
  piVar1 = (int *)*param_1;
  if (*piVar1 == 0x38) {
    piVar1[0xc] = 0;
    piVar1[0xd] = 0;
    if (*(longlong *)(piVar1 + 10) == 0) {
      *(undefined4 *)(param_1 + 1) = 0;
    }
    else {
      puVar3 = (undefined4 *)ExAllocatePool2(0x40,0xa0,0x63546c50);
      if (puVar3 == (undefined4 *)0x0) {
        *(undefined4 *)(param_1 + 1) = 0xc000009a;
      }
      else {
        *puVar3 = 0xa0;
        lVar2 = *(longlong *)(piVar1 + 10);
        *(longlong *)(puVar3 + 2) = lVar2;
        *(undefined8 *)(puVar3 + 4) = *(undefined8 *)(lVar2 + 0x68);
        *(undefined8 *)(lVar2 + 0x68) = *(undefined8 *)(piVar1 + 8);
        PortTraceErrorRegisterDriver((longlong)puVar3,(longlong)piVar1);
        *(undefined4 **)(piVar1 + 0xc) = puVar3;
        *(undefined4 *)(param_1 + 1) = 0;
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 1) = 0xc000000d;
  }
  return;
}



===== WppGuidToStr @ 1c0004b38 =====

void WppGuidToStr(longlong param_1,uint *param_2)

{
  longlong lVar1;
  
  lVar1 = param_1;
  WppIntToHex(param_1,*param_2,8);
  *(undefined2 *)(param_1 + 0x10) = 0x2d;
  WppIntToHex(param_1 + 0x12,(uint)(ushort)param_2[1],4);
  *(undefined2 *)(lVar1 + 0x1a) = 0x2d;
  WppIntToHex(lVar1 + 0x1c,(uint)*(ushort *)((longlong)param_2 + 6),4);
  *(undefined2 *)(lVar1 + 0x24) = 0x2d;
  WppIntToHex(lVar1 + 0x26,(uint)(byte)param_2[2],2);
  WppIntToHex(lVar1 + 0x2a,(uint)*(byte *)((longlong)param_2 + 9),2);
  *(undefined2 *)(lVar1 + 0x2e) = 0x2d;
  WppIntToHex(lVar1 + 0x30,(uint)*(byte *)((longlong)param_2 + 10),2);
  WppIntToHex(lVar1 + 0x34,(uint)*(byte *)((longlong)param_2 + 0xb),2);
  WppIntToHex(lVar1 + 0x38,(uint)(byte)param_2[3],2);
  WppIntToHex(lVar1 + 0x3c,(uint)*(byte *)((longlong)param_2 + 0xd),2);
  WppIntToHex(lVar1 + 0x40,(uint)*(byte *)((longlong)param_2 + 0xe),2);
  WppIntToHex(lVar1 + 0x44,(uint)*(byte *)((longlong)param_2 + 0xf),2);
  *(undefined2 *)(lVar1 + 0x48) = 0;
  return;
}



===== WppIntToHex @ 1c0004c38 =====

void WppIntToHex(longlong param_1,uint param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  
  lVar2 = (longlong)(param_3 + -1);
  if (-1 < param_3 + -1) {
    do {
      uVar1 = param_2 & 0xf;
      param_2 = param_2 >> 4;
      *(wchar_t *)(param_1 + lVar2 * 2) = L"0123456789abcdef"[uVar1];
      lVar2 = lVar2 + -1;
    } while (-1 < lVar2);
  }
  return;
}



===== __GSHandlerCheck @ 1c0004c78 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0004c9c =====

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



===== __security_check_cookie @ 1c0004d10 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 1c0004d50 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 1c0004d80 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c0004d80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 1c0004db0 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcpy @ 1c0004e00 =====

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
  
                    /* 0x4e00  62  memcpy
                       0x4e00  63  memmove */
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



===== memset @ 1c0005100 =====

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



===== __memset_repmovs @ 1c0005240 =====

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



===== __memset_query @ 1c00052c0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 1c0005340 =====

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



===== __memset_spec_ermsb_repmovsb @ 1c0005480 =====

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



===== __memset_spec_plain @ 1c0005500 =====

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



===== memset @ 1c0006020 =====

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



===== wil_details_EvaluateFeatureDependencies @ 1c000b008 =====

/* WARNING: Removing unreachable block (ram,0x0001c000b030) */
/* WARNING: Removing unreachable block (ram,0x0001c000b040) */
/* WARNING: Removing unreachable block (ram,0x0001c000b045) */
/* WARNING: Removing unreachable block (ram,0x0001c000b04a) */
/* WARNING: Removing unreachable block (ram,0x0001c000b055) */
/* WARNING: Removing unreachable block (ram,0x0001c000b06a) */
/* WARNING: Removing unreachable block (ram,0x0001c000b060) */
/* WARNING: Removing unreachable block (ram,0x0001c000b07a) */
/* WARNING: Removing unreachable block (ram,0x0001c000b097) */
/* WARNING: Removing unreachable block (ram,0x0001c000b0a6) */
/* WARNING: Removing unreachable block (ram,0x0001c000b0ab) */
/* WARNING: Removing unreachable block (ram,0x0001c000b09d) */
/* WARNING: Removing unreachable block (ram,0x0001c000b0ad) */
/* WARNING: Removing unreachable block (ram,0x0001c000b0b2) */
/* WARNING: Removing unreachable block (ram,0x0001c000b0a2) */
/* WARNING: Removing unreachable block (ram,0x0001c000b035) */
/* WARNING: Removing unreachable block (ram,0x0001c000b03e) */
/* WARNING: Removing unreachable block (ram,0x0001c000b0bd) */
/* WARNING: Removing unreachable block (ram,0x0001c000b0c2) */
/* WARNING: Removing unreachable block (ram,0x0001c000b0b4) */
/* WARNING: Removing unreachable block (ram,0x0001c000b0e5) */
/* WARNING: Removing unreachable block (ram,0x0001c000b0c4) */
/* WARNING: Removing unreachable block (ram,0x0001c000b0de) */
/* WARNING: Removing unreachable block (ram,0x0001c000b0e3) */
/* WARNING: Removing unreachable block (ram,0x0001c000b0d5) */
/* WARNING: Removing unreachable block (ram,0x0001c000b0da) */
/* WARNING: Removing unreachable block (ram,0x0001c000b0b9) */

void wil_details_EvaluateFeatureDependencies(void)

{
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 1c000b0f8 =====

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
          if (puVar1 == (undefined8 *)0x0) goto LAB_1c000b190;
          if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
             (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
          if ((uVar4 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
            uVar4 = 0;
            goto LAB_1c000b190;
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
LAB_1c000b190:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 1c000b1e0 =====

void wil_details_OnFeatureUsageProviderFlushNotification(int param_1)

{
  int iVar1;
  longlong *plVar2;
  
  iVar1 = g_wil_details_featureUsageCached;
  if (param_1 == 1) {
    LOCK();
    g_wil_details_featureUsageCached = 0;
    UNLOCK();
    if (iVar1 != 0) {
      for (plVar2 = &wil_details_featureDescriptors_z; plVar2 < &wil_details_featureDescriptors_z;
          plVar2 = plVar2 + 1) {
        if (*plVar2 != 0) {
          do {
            if (plVar2 == (longlong *)0x0) {
              return;
            }
            if ((*(uint *)plVar2[1] & 1) != 0) {
              wil_details_RecordCachedUsage((int)plVar2[3],(uint *)plVar2[1]);
            }
            plVar2 = plVar2 + 7;
            while( true ) {
              if (&UNK_1c0007947 < plVar2) {
                return;
              }
              if (*plVar2 != 0) break;
              plVar2 = plVar2 + 1;
            }
          } while( true );
        }
      }
    }
  }
  return;
}



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 1c000b260 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  int iVar1;
  uint uVar2;
  longlong *plVar3;
  undefined1 auStack_48 [32];
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  for (plVar3 = &wil_details_featureDescriptors_z; plVar3 < &wil_details_featureDescriptors_z;
      plVar3 = plVar3 + 1) {
    if (*plVar3 != 0) goto LAB_1c000b35d;
  }
LAB_1c000b366:
  wil_details_EvaluateFeatureDependencies();
  return;
LAB_1c000b35d:
  if (plVar3 == (longlong *)0x0) goto LAB_1c000b366;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    iVar1 = RtlQueryFeatureConfiguration((int)plVar3[3],1,&local_28,&local_20);
    if ((iVar1 == -0x7fffffde) || (iVar1 == -0x3ffffddb)) {
LAB_1c000b32e:
      uVar2 = 0x206;
    }
    else {
      if (iVar1 == 0) {
        uVar2 = (local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0;
      }
      else {
        if (iVar1 != 0x117) goto LAB_1c000b32e;
        uVar2 = local_20._4_4_ & 0x80;
      }
      uVar2 = uVar2 << 3 | 0x206;
    }
    LOCK();
    *(uint *)*plVar3 = *(uint *)*plVar3 ^ (*(uint *)*plVar3 ^ uVar2) & 0xf80;
    UNLOCK();
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_1c0007947 < plVar3) goto LAB_1c000b366;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_1c000b35d;
}



===== PortTraceErrorFreeDriver @ 1c000b38c =====

void PortTraceErrorFreeDriver(longlong param_1)

{
  uint *puVar1;
  uint uVar2;
  ulonglong uVar3;
  
  LOCK();
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + -1;
  UNLOCK();
  puVar1 = (uint *)(param_1 + 0x50);
  if (*(longlong *)(param_1 + 0x38) != 0) {
    uVar3 = 0;
    if (*puVar1 != 0) {
      do {
        ExFreePoolWithTag(*(undefined8 *)(*(longlong *)(param_1 + 0x38) + uVar3 * 8),0);
        uVar2 = (int)uVar3 + 1;
        uVar3 = (ulonglong)uVar2;
      } while (uVar2 < *puVar1);
    }
    ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x38),0);
    *(undefined8 *)(param_1 + 0x38) = 0;
  }
  *puVar1 = 0;
  return;
}



===== PortTraceErrorRegisterDriver @ 1c000b400 =====

void PortTraceErrorRegisterDriver(longlong param_1,longlong param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(param_2 + 0xc);
  uVar4 = 10;
  if ((10 < uVar3) || (uVar4 = uVar3, uVar3 != 0)) {
    lVar1 = ExAllocatePool2(0x40,uVar4 * 8,0x6c456c50);
    *(longlong *)(param_1 + 0x38) = lVar1;
    if (lVar1 != 0) {
      uVar3 = 0;
      if (uVar4 != 0) {
        lVar1 = 0;
        do {
          lVar2 = ExAllocatePool2(0x40,0x110,0x6c456c50);
          if (lVar2 == 0) break;
          uVar3 = uVar3 + 1;
          *(longlong *)(lVar1 + *(longlong *)(param_1 + 0x38)) = lVar2;
          lVar1 = lVar1 + 8;
        } while (uVar3 < uVar4);
      }
      *(uint *)(param_1 + 0x50) = uVar3;
    }
  }
  InitializeSListHead((PSLIST_HEADER)(param_1 + 0x40));
  *(undefined4 *)(param_1 + 0x54) = 0;
  LOCK();
  *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
  UNLOCK();
  PortpErrorInitDpc(param_1);
  return;
}



===== entry @ 1c000d010 =====

void entry(undefined8 param_1,uint *param_2)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2);
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



===== wil_InitializeFeatureStaging @ 1c000d078 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wil_InitializeFeatureStaging(void)

{
  bool bVar1;
  int iVar2;
  longlong *plVar3;
  undefined8 local_res8;
  
  bVar1 = false;
  if (g_wil_details_isFeatureStagingInitialized == 0) {
    g_wil_details_isFeatureStagingInitialized = 1;
    local_res8 = RtlQueryFeatureConfigurationChangeStamp();
    wil_details_PopulateInitialConfiguredFeatureStates();
    wil_details_EvaluateFeatureDependencies();
    for (plVar3 = &wil_details_featureDescriptors_z; plVar3 < &wil_details_featureDescriptors_z;
        plVar3 = plVar3 + 1) {
      if (*plVar3 != 0) goto LAB_1c000d0ff;
    }
LAB_1c000d139:
    _g_wil_details_recordFeatureUsage = wil_details_RecordFeatureUsageReporting;
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
LAB_1c000d0ff:
  if (plVar3 == (longlong *)0x0) goto LAB_1c000d139;
  if (((*(char *)((longlong)plVar3 + 0x1d) == '\0') && (*(char *)((longlong)plVar3 + 0x1e) == '\0'))
     && (*(char *)((longlong)plVar3 + 0x1c) == '\0')) {
    iVar2 = RtlRegisterFeatureConfigurationChangeNotification
                      (wil_details_ReevaluateOnFeatureConfigurationChange,0,&local_res8,
                       &g_wil_details_featureChangeNotification);
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      g_wil_details_featureChangeNotification = 0;
    }
    goto LAB_1c000d139;
  }
  plVar3 = plVar3 + 7;
  while( true ) {
    if (&UNK_1c0007947 < plVar3) goto LAB_1c000d139;
    if (*plVar3 != 0) break;
    plVar3 = plVar3 + 1;
  }
  goto LAB_1c000d0ff;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 1c000d18c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void wil_details_PopulateInitialConfiguredFeatureStates(void)

{
  ulonglong *puVar1;
  undefined8 *puVar2;
  int iVar3;
  longlong *plVar4;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 local_20;
  undefined4 local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  plVar4 = &wil_details_featureDescriptors_z;
  while( true ) {
    if (&wil_details_featureDescriptors_z <= plVar4) {
      return;
    }
    if (*plVar4 != 0) break;
    plVar4 = plVar4 + 1;
  }
  do {
    if (plVar4 == (longlong *)0x0) {
      return;
    }
    local_28 = 0;
    local_20 = 0;
    local_18 = 0;
    if ((*(char *)((longlong)plVar4 + 0x1d) == '\0') && (*(char *)((longlong)plVar4 + 0x1e) == '\0')
       ) {
      iVar3 = RtlQueryFeatureConfiguration
                        ((int)plVar4[3],1 < (byte)(*(char *)((longlong)plVar4 + 0x1c) - 2U),
                         &local_28,&local_20);
      if (iVar3 == -0x7fffffde) {
        do {
          puVar2 = (undefined8 *)*plVar4;
          plVar4 = plVar4 + 7;
          *puVar2 = 0x206;
          while( true ) {
            if (&UNK_1c0007947 < plVar4) {
              return;
            }
            if (*plVar4 != 0) break;
            plVar4 = plVar4 + 1;
          }
        } while (plVar4 != (longlong *)0x0);
        return;
      }
      if (iVar3 == -0x3ffffddb) goto LAB_1c000d276;
      if (iVar3 == 0) {
        local_28 = (ulonglong)(((local_20._4_4_ & 0x40) << 2 | local_20._4_4_ & 0xb0) << 3 | 0x206);
      }
      else {
        if (iVar3 != 0x117) goto LAB_1c000d276;
        local_28 = (ulonglong)((local_20._4_4_ & 0x80) << 3 | 0x206);
      }
    }
    else {
LAB_1c000d276:
      local_28 = 0x206;
    }
    puVar1 = (ulonglong *)*plVar4;
    plVar4 = plVar4 + 7;
    *puVar1 = local_28;
    while( true ) {
      if (&UNK_1c0007947 < plVar4) {
        return;
      }
      if (*plVar4 != 0) break;
      plVar4 = plVar4 + 1;
    }
  } while( true );
}


