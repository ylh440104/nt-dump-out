
===== MegaSASFindAdapter @ 1c0001000 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
MegaSASFindAdapter(longlong param_1,undefined8 param_2,undefined8 param_3,char *param_4,
                  longlong param_5,undefined1 *param_6)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  undefined **ppuVar4;
  bool bVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined8 uVar11;
  void *pvVar12;
  undefined8 uVar13;
  byte bVar14;
  uint uVar15;
  longlong lVar16;
  undefined8 *puVar17;
  undefined1 uVar18;
  ulonglong uVar19;
  uint uVar20;
  bool bVar21;
  ulonglong uVar22;
  ulonglong uVar23;
  ulonglong *puVar24;
  byte *pbVar25;
  int iVar26;
  longlong lVar27;
  undefined1 auStack_1a8 [32];
  undefined2 *local_188;
  uint local_180;
  undefined4 local_178;
  undefined1 local_168 [4];
  uint local_164;
  longlong local_160;
  undefined1 *local_158;
  undefined2 local_148;
  undefined2 local_146;
  byte abStack_144 [252];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_158 = param_6;
  local_160 = param_5;
  local_164 = 0;
  *param_6 = 0;
  uVar10 = 0;
  MemFastZero(&local_148,0x100);
  local_188 = &local_148;
  local_180 = 0x100;
  StorPortGetBusData(param_1,4,*(undefined4 *)(param_5 + 4),*(undefined4 *)(param_5 + 100));
  bVar14 = 0;
  do {
    if (((uint)local_148 == (&DAT_1c000c158)[(ulonglong)bVar14 * 8]) &&
       ((uint)local_146 == (&DAT_1c000c15c)[(ulonglong)bVar14 * 8])) {
      lVar16 = (ulonglong)bVar14 * 0x20;
      cVar1 = *(char *)(lVar16 + 0x1c000c168);
      *(undefined1 *)(param_1 + 0x7be1) = *(undefined1 *)(lVar16 + 0x1c000c16a);
      *(undefined1 *)(param_1 + 0x21e7) = *(undefined1 *)(lVar16 + 0x1c000c169);
      *(short *)(param_1 + 0x21e8) = *(short *)(lVar16 + 0x1c000c16c) + -1;
      ppuVar4 = *(undefined ***)(lVar16 + 0x1c000c160);
      *(undefined ***)(param_1 + 0x188) = ppuVar4;
      *(bool *)(param_1 + 0x7be0) = ppuVar4 == &PTR_MPT_InitializeQueues_1c000c360;
      if (*(char *)(*(longlong *)(param_5 + 0x38) + 0xc) == '\0') {
        uVar7 = 0;
        if (*(char *)(*(longlong *)(param_5 + 0x38) + 0x1c) != '\0') {
          uVar7 = 1;
        }
      }
      else {
        uVar7 = 0;
      }
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_5 + 4);
      *(byte *)(param_1 + 8) = *(byte *)(param_5 + 100) & 0x1f;
      *(byte *)(param_1 + 9) = (byte)(*(uint *)(param_5 + 100) >> 5) & 7;
      *(byte *)(param_1 + 10) = abStack_144[0x38];
      pbVar25 = abStack_144 + ((ulonglong)abStack_144[0x30] - 4);
      MemFastMove((undefined8 *)(param_1 + 0xc),(undefined8 *)&local_148,0x40);
      MemFastMove((undefined8 *)(param_1 + 0x4c),(undefined8 *)pbVar25,8);
      MemFastMove((undefined8 *)(param_1 + 0x50),(undefined8 *)(pbVar25 + 4),4);
      uVar20 = 0;
      bVar5 = false;
      local_180 = local_180 & 0xffffff00;
      local_188 = (undefined2 *)CONCAT44(local_188._4_4_,0x2000);
      lVar16 = StorPortGetDeviceBase
                         (param_1,*(undefined4 *)(param_5 + 8),*(undefined4 *)(param_5 + 4),
                          *(undefined8 *)((ulonglong)uVar7 * 0x10 + *(longlong *)(param_5 + 0x38)));
      if (lVar16 != 0) {
        *(longlong *)(param_1 + 0x80) = lVar16;
        bVar21 = false;
        if (abStack_144[0x30] != 0) goto LAB_1c0001265;
        goto LAB_1c00012a4;
      }
      local_178 = 1;
      local_180 = 6;
      local_188 = (undefined2 *)CONCAT71(local_188._1_7_,0xff);
      StorPortLogError(param_1,0,0xff);
      uVar11 = 2;
      goto LAB_1c00010ec;
    }
    bVar14 = bVar14 + 1;
  } while (bVar14 < 0xd);
  local_178 = 0x10;
  local_180 = 6;
  local_188 = (undefined2 *)CONCAT71(local_188._1_7_,0xff);
  StorPortLogError(param_1,0,0xff);
  uVar11 = 0;
  goto LAB_1c00010ec;
LAB_1c0001265:
  do {
    uVar22 = (ulonglong)abStack_144[0x30];
    if (abStack_144[uVar22 - 4] == 5) {
      if ((abStack_144[uVar22 - 2] & 1) != 0) {
        bVar21 = true;
      }
    }
    else if (abStack_144[uVar22 - 4] == 0x11) {
      if ((abStack_144[uVar22 - 1] & 0x80) != 0) {
        bVar5 = true;
      }
    }
    abStack_144[0x30] = abStack_144[uVar22 - 3];
  } while (abStack_144[0x30] != 0);
  param_5 = local_160;
  if ((!bVar21) && (!bVar5)) {
LAB_1c00012a4:
    *(undefined1 *)(param_1 + 0x21f0) = 1;
  }
  *(undefined1 *)(param_1 + 0x76eb) = 1;
  GetRegistrySettings(param_4,param_1);
  if (*(int *)(param_1 + 0x8c) == 0) {
    *(undefined4 *)(param_1 + 0x8c) = 4;
  }
  if ((*(char *)(param_1 + 0x88) == '\0') &&
     (DAT_1c000c5c0 = DAT_1c000c5c0 + 1, 0x20 < DAT_1c000c5c0)) {
    local_178 = 10;
    local_180 = 6;
    local_188 = (undefined2 *)CONCAT71(local_188._1_7_,0xff);
    StorPortLogError(param_1,0,0xff);
    uVar11 = 0;
    goto LAB_1c00010ec;
  }
  *(undefined1 *)(param_1 + 0x7bbe) = 1;
  *(uint *)(param_1 + 0x74) =
       (*(byte *)(param_1 + 9) & 7 | *(int *)(param_1 + 4) << 3) << 5 |
       *(byte *)(param_1 + 8) & 0x1f;
  (**(code **)(*(longlong *)(param_1 + 0x188) + 0x28))(param_1);
  StorPortQuerySystemTime(param_1 + 0x6608);
  *(undefined2 *)(param_1 + 0x7bd0) = 0x200;
  *(undefined4 *)(param_1 + 0x21c8) = 0xff;
  uVar11 = WaitForFwareReadyWithRetry(param_1);
  if ((char)uVar11 == '\0') {
    local_178 = 0x12;
  }
  else {
    uVar7 = *(uint *)(param_1 + 0x21c4) & 0xffff;
    if (0x400 < uVar7) {
      uVar7 = 0x400;
    }
    *(uint *)(param_1 + 0x66bc) = uVar7;
    if (*(char *)(param_1 + 0x88) != '\0') {
      *(undefined1 *)(param_1 + 0x7be2) = 0;
      uVar8 = 0x12;
      if (uVar7 < 0x12) {
        uVar8 = uVar7;
      }
      *(uint *)(param_1 + 0x66bc) = uVar8;
    }
    if ((*(char *)(param_1 + 0x7be0) != '\0') && ((*(uint *)(param_1 + 0x66bc) & 0xf) != 0)) {
      *(uint *)(param_1 + 0x66bc) = *(uint *)(param_1 + 0x66bc) & 0xfffffff0;
    }
    uVar7 = *(uint *)(param_1 + 0x98);
    uVar8 = *(int *)(param_1 + 0x66bc) - 5;
    if (0x400 < uVar8) {
      uVar8 = 0x400;
    }
    *(uint *)(param_1 + 0x66c0) = uVar8;
    if (0x14 < uVar7) {
      if (uVar7 < uVar8) {
        uVar8 = uVar7;
      }
      *(uint *)(param_1 + 0x66c0) = uVar8;
    }
    uVar7 = *(uint *)(param_1 + 0x94);
    uVar15 = *(uint *)(param_1 + 0x66c0) >> 2;
    *(undefined4 *)(param_1 + 0x21a0) = 10;
    uVar8 = *(uint *)(param_1 + 0x21a0);
    if (uVar15 < 10) {
      uVar8 = uVar15;
    }
    *(uint *)(param_1 + 0x21a0) = uVar8;
    if (uVar7 != 0) {
      if (uVar7 <= uVar15) {
        uVar8 = uVar7;
      }
      *(uint *)(param_1 + 0x21a0) = uVar8;
    }
    *(undefined2 *)(param_5 + 0x51) = 0x101;
    *(undefined1 *)(param_5 + 0x53) = 1;
    if (*(char *)(param_5 + 0x90) < '\0') {
      *(undefined1 *)(param_1 + 0x21eb) = 1;
      *(undefined1 *)(param_5 + 0x57) = 0;
      *(undefined1 *)(param_5 + 0x90) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x21eb) = 0;
      *(undefined1 *)(param_5 + 0x57) = 1;
    }
    *(undefined1 *)(param_1 + 0x76ea) = 1;
    if ((cVar1 != '\0') && ((*(uint *)(param_1 + 0x21c4) & 0x6000000) != 0)) {
      *(undefined1 *)(param_1 + 0x76e9) = 1;
    }
    if ((*(char *)(param_1 + 0x88) == '\0') &&
       (cVar6 = RtlIsNtDdiVersionAvailable(0x6000000), cVar6 == '\0')) {
      *(undefined1 *)(param_1 + 0x76e9) = 0;
      *(undefined1 *)(param_1 + 0x76eb) = 0;
    }
    if (*(char *)(param_1 + 0x76e9) == '\0') {
      *(undefined1 *)(param_1 + 0x76eb) = 0;
    }
    else {
      *(undefined4 *)(param_5 + 0xa0) = 2;
      *(code **)(param_5 + 0x98) = MessageInterrupts;
      if (*(char *)(param_1 + 0x88) == '\0') {
        *(char *)(param_1 + 0x76ea) = cVar1;
        if (*(char *)(param_1 + 0x7be0) != '\0') {
          uVar7 = (*(uint *)(*(longlong *)(param_1 + 0x80) + 0xb4) & 0x1f) + 1;
          uVar18 = *(undefined1 *)(param_1 + 0x76ea);
          if (uVar7 < *(byte *)(param_1 + 0x76ea)) {
            uVar18 = (char)uVar7;
          }
          *(undefined1 *)(param_1 + 0x76ea) = uVar18;
        }
        bVar14 = *(byte *)(param_1 + 0x90);
        if ((bVar14 != 0) && (bVar14 < *(byte *)(param_1 + 0x76ea))) {
          *(byte *)(param_1 + 0x76ea) = bVar14;
        }
      }
    }
    iVar9 = *(int *)(param_1 + 0x66c0);
    uVar2 = *(ushort *)(param_1 + 0x21e8);
    if (*(char *)(param_1 + 0x7be0) == '\0') {
      uVar20 = ((uint)uVar2 + (*(int *)(param_1 + 0x66bc) + 4) * 4) *
               (uint)*(byte *)(param_1 + 0x76ea) + 0x100 + (uint)uVar2;
      local_164 = uVar20;
    }
    else {
      uVar10 = ((uint)uVar2 +
               ((*(byte *)(param_1 + 0x76ea) + 0x20) * *(int *)(param_1 + 0x66bc) + 0x20) * 4) * 2;
      if (*(char *)(param_1 + 0x7be2) != '\0') {
        uVar10 = uVar10 + (uint)uVar2 * 2 + 0x54150;
      }
    }
    uVar7 = 0x40;
    if (*(char *)(param_1 + 0x7be0) == '\0') {
      uVar7 = (uint)*(byte *)(param_1 + 0x21c6);
    }
    *(uint *)(param_5 + 0x1c) = uVar7;
    uVar20 = (uint)uVar2 * 0xb + iVar9 * 0x12 + 0x5420 + uVar10 + uVar20;
    *(undefined4 *)(param_5 + 0x18) = 0x3fffff;
    pvVar12 = (void *)StorPortGetUncachedExtension(param_1,param_5,uVar20);
    if (pvVar12 == (void *)0x0) {
      local_178 = 2;
    }
    else {
      MemFastZero(pvVar12,(ulonglong)uVar20);
      uVar2 = *(ushort *)(param_1 + 0x21e8);
      puVar17 = (undefined8 *)((ulonglong)uVar2 + (longlong)pvVar12 & (longlong)(int)~(uint)uVar2);
      *(undefined8 **)(param_1 + 0xd0) = puVar17;
      MemFastMove(puVar17,(undefined8 *)"percsas2i.sys",0xd);
      *(undefined1 *)(*(longlong *)(param_1 + 0xd0) + 0xd) = 0x20;
      MemFastMove((undefined8 *)(*(longlong *)(param_1 + 0xd0) + 0xe),(undefined8 *)&s_6_805_03_00,
                  0xc);
      *(undefined1 *)(*(longlong *)(param_1 + 0xd0) + 0x19) = 0;
      uVar22 = (longlong)pvVar12 +
               (ulonglong)*(ushort *)(param_1 + 0x21e8) + (longlong)(int)(uVar2 + 0x80) &
               (longlong)(int)~(uint)*(ushort *)(param_1 + 0x21e8);
      *(ulonglong *)(param_1 + 0x128) = uVar22;
      uVar11 = StorPortGetPhysicalAddress(param_1,0,uVar22,local_168);
      *(undefined8 *)(param_1 + 0x130) = uVar11;
      uVar3 = *(ushort *)(param_1 + 0x21e8);
      lVar16 = (ulonglong)uVar3 + 0x1808 + (longlong)(int)(uVar2 + 0x80);
      uVar22 = (longlong)pvVar12 + (ulonglong)uVar3 + lVar16 & (longlong)(int)~(uint)uVar3;
      *(ulonglong *)(param_1 + 0x138) = uVar22;
      uVar11 = StorPortGetPhysicalAddress(param_1,0,uVar22,local_168);
      *(undefined8 *)(param_1 + 0x140) = uVar11;
      uVar2 = *(ushort *)(param_1 + 0x21e8);
      lVar16 = (ulonglong)uVar2 + lVar16 + 0x100;
      uVar22 = (longlong)pvVar12 + (ulonglong)uVar2 + lVar16 & (longlong)(int)~(uint)uVar2;
      *(ulonglong *)(param_1 + 0x148) = uVar22;
      uVar11 = StorPortGetPhysicalAddress(param_1,0,uVar22,local_168);
      uVar2 = *(ushort *)(param_1 + 0x21e8);
      *(undefined8 *)(param_1 + 0x150) = uVar11;
      lVar16 = (int)(uVar2 + 0xa00) + lVar16;
      uVar22 = (longlong)pvVar12 + (ulonglong)uVar2 + lVar16 & (longlong)(int)~(uint)uVar2;
      *(ulonglong *)(param_1 + 0x168) = uVar22;
      uVar11 = StorPortGetPhysicalAddress(param_1,0,uVar22,local_168);
      *(undefined8 *)(param_1 + 0x170) = uVar11;
      uVar2 = *(ushort *)(param_1 + 0x21e8);
      uVar22 = (ulonglong)uVar2;
      puVar17 = (undefined8 *)(param_1 + 0x100);
      lVar16 = (longlong)pvVar12 + uVar22 + lVar16 + 0x400;
      lVar27 = 5;
      do {
        uVar22 = (ulonglong)uVar2 + lVar16 & (longlong)(int)~(uint)uVar22;
        puVar17[-5] = uVar22;
        uVar11 = StorPortGetPhysicalAddress(param_1,0,uVar22,local_168);
        *puVar17 = uVar11;
        uVar2 = *(ushort *)(param_1 + 0x21e8);
        uVar22 = (ulonglong)uVar2;
        puVar17 = puVar17 + 1;
        lVar16 = lVar16 + 0x578 + uVar22;
        lVar27 = lVar27 + -1;
      } while (lVar27 != 0);
      *(longlong *)(param_1 + 0x158) = lVar16;
      uVar11 = StorPortGetPhysicalAddress(param_1,0,lVar16,local_168);
      *(undefined8 *)(param_1 + 0x160) = uVar11;
      lVar16 = lVar16 + (ulonglong)*(uint *)(param_1 + 0x66c0) * 0x12;
      uVar22 = lVar16 + (ulonglong)*(ushort *)(param_1 + 0x21e8) &
               (longlong)(int)~(uint)*(ushort *)(param_1 + 0x21e8);
      *(ulonglong *)(param_1 + 0x178) = uVar22;
      uVar11 = StorPortGetPhysicalAddress(param_1,0,uVar22,local_168);
      *(undefined8 *)(param_1 + 0x180) = uVar11;
      uVar2 = *(ushort *)(param_1 + 0x21e8);
      lVar16 = lVar16 + 0x820 + (ulonglong)uVar2;
      uVar22 = (ulonglong)uVar2 + lVar16 & (longlong)(int)~(uint)uVar2;
      *(ulonglong *)(param_1 + 0xc0) = uVar22;
      uVar11 = StorPortGetPhysicalAddress(param_1,0,uVar22,local_168);
      uVar22 = (ulonglong)*(ushort *)(param_1 + 0x21e8);
      *(undefined8 *)(param_1 + 200) = uVar11;
      lVar16 = uVar22 + 0x820 + lVar16;
      uVar11 = 2;
      if (*(char *)(param_1 + 0x7be0) == '\0') {
        bVar14 = 0;
        uVar23 = uVar22 + lVar16 & (longlong)(int)~(uint)*(ushort *)(param_1 + 0x21e8);
        *(ulonglong *)(param_1 + 0x7bd8) = uVar23;
        uVar19 = lVar16 + (ulonglong)*(byte *)(param_1 + 0x76ea) * 0x10 + uVar22;
        if (*(byte *)(param_1 + 0x76ea) != 0) {
          puVar24 = (ulonglong *)(uVar23 + 8);
          do {
            bVar14 = bVar14 + 1;
            *puVar24 = uVar22 + uVar19 & (longlong)(int)~(uint)uVar22;
            puVar24 = puVar24 + 2;
            uVar22 = (ulonglong)*(ushort *)(param_1 + 0x21e8);
            uVar19 = uVar19 + uVar22 + (ulonglong)*(uint *)(param_1 + 0x66bc) * 4;
          } while (bVar14 < *(byte *)(param_1 + 0x76ea));
          param_5 = local_160;
        }
        if (uVar19 <= (ulonglong)local_164 + lVar16) goto LAB_1c0001949;
      }
      else {
        uVar13 = MPT_InitMessageMem(param_1,lVar16,uVar10);
        if ((char)uVar13 != '\0') {
LAB_1c0001949:
          iVar9 = 0x10;
          if (*(int *)(param_1 + 0xa8) != 0) {
            iVar9 = *(int *)(param_1 + 0xa8);
          }
          *(int *)(param_1 + 0x76e0) = iVar9;
          iVar9 = *(int *)(param_1 + 0xa4);
          iVar26 = 4;
          if (iVar9 != 0) {
            iVar26 = iVar9;
          }
          *(int *)(param_1 + 0x76e4) = iVar26;
          if (iVar9 == 0) {
            *(undefined4 *)(param_1 + 0xb0) = 0x10;
          }
          else {
            *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0xac);
          }
          do {
            uVar13 = InitializeAdapter(param_1);
            if ((char)uVar13 != '\0') {
              if (((*(char *)(param_1 + 0x89) == '\0') || (*(char *)(param_1 + 0x21f0) == '\0')) ||
                 (*(char *)(param_1 + 0x88) != '\0')) {
                if (*(char *)(param_1 + 0x7be0) == '\0') {
                  if ((*(uint *)(param_1 + 0x21c4) >> 0x1a & 1) != 0) {
                    *(undefined1 *)(param_1 + 0x21ea) = 1;
                  }
                  if ((*(uint *)(param_1 + 0x21c4) >> 0x19 & 1) != 0) {
                    *(undefined1 *)(param_1 + 0x21e6) = 1;
                  }
                  bVar14 = *(byte *)(param_1 + 0x21c6);
                  if (*(char *)(param_1 + 0x21ea) == '\0') {
                    uVar10 = 0x50;
                    if (*(char *)(param_1 + 0x21eb) == '\0') {
                      uVar10 = 0x78;
                    }
                    if (bVar14 <= (byte)uVar10) {
                      uVar10 = (uint)bVar14;
                    }
                    *(undefined4 *)(param_1 + 0x66b0) = 0x80000;
                  }
                  else {
                    uVar10 = 0x3c;
                    if (bVar14 < 0x3d) {
                      uVar10 = (uint)bVar14;
                    }
                    *(undefined4 *)(param_1 + 0x66b0) = 0x20000;
                  }
                  *(uint *)(param_1 + 0x66b4) = uVar10;
                }
                else {
                  uVar10 = (uint)*(byte *)(param_1 + 0x21c6);
                  *(undefined1 *)(param_1 + 0x21ea) = 1;
                  *(undefined4 *)(param_1 + 0x66b4) = 0x40;
                  if (0x40 < *(byte *)(param_1 + 0x21c6)) {
                    uVar10 = 0x40;
                  }
                  *(undefined4 *)(param_1 + 0x66b0) = 0x40000;
                }
                uVar7 = *(uint *)(param_1 + 0x9c);
                *(uint *)(param_1 + 0x66b8) = uVar10;
                if (uVar7 != 0) {
                  uVar10 = uVar7 >> 0xc;
                  if (*(uint *)(param_1 + 0x66b4) < uVar7 >> 0xc) {
                    uVar10 = *(uint *)(param_1 + 0x66b4);
                  }
                  uVar20 = *(uint *)(param_1 + 0x66b0);
                  if (uVar7 <= uVar10 * 0x1000) {
                    uVar20 = uVar7;
                  }
                  *(uint *)(param_1 + 0x66b0) = uVar20;
                }
                *(undefined4 *)(param_5 + 0x18) = *(undefined4 *)(param_1 + 0x66b0);
                *(undefined4 *)(param_5 + 0x1c) = *(undefined4 *)(param_1 + 0x66b4);
                *(undefined2 *)(param_5 + 0x48) = 0x702;
                *(undefined1 *)(param_5 + 0x61) = 0xff;
                *(undefined1 *)(param_5 + 0x92) = 8;
                *(undefined4 *)(param_5 + 0x94) = 1;
                if (*(char *)(param_1 + 0x88) == '\0') {
                  *(undefined4 *)(param_1 + 0x666c) = 0xfe000072;
                  *(undefined1 *)(param_5 + 0x93) = 1;
                  *(undefined ***)(param_1 + 0x6678) = &MegaSASGuidList;
                  *(code **)(param_1 + 0x6680) = MegaSASQueryWmiRegInfo;
                  *(code **)(param_1 + 0x6688) = MegaSASQueryWmiDataBlock;
                  *(code **)(param_1 + 0x66a8) = FunctionControl;
                  *(undefined4 *)(param_1 + 0x6670) = 1;
                  *(undefined8 *)(param_1 + 0x6698) = 0;
                  *(undefined8 *)(param_1 + 0x6690) = 0;
                  *(undefined8 *)(param_1 + 0x66a0) = 0;
                }
                *local_158 = 1;
                return 1;
              }
              *(undefined4 *)(param_1 + 0x7bcc) = 30000000;
              SendAndWaitDCMD(param_1,0x1050000);
              goto LAB_1c00010ec;
            }
            uVar13 = CheckResetRetries(param_1);
          } while (((char)uVar13 != '\0') &&
                  (uVar13 = WaitForFwareReadyWithRetry(param_1), (char)uVar13 != '\0'));
          local_178 = 9;
          goto LAB_1c000138b;
        }
      }
      local_178 = 0x11;
    }
  }
LAB_1c000138b:
  uVar11 = 2;
  local_180 = 6;
  local_188 = (undefined2 *)CONCAT71(local_188._1_7_,0xff);
  StorPortLogError(param_1,0,0xff);
LAB_1c00010ec:
  *(undefined1 *)(param_1 + 0x7bbf) = 1;
  return uVar11;
}



===== MegaSASPnPControl @ 1c0001b90 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 MegaSASPnPControl(longlong param_1,int param_2,uint *param_3)

{
  bool bVar1;
  ulonglong uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined1 auStack_68 [32];
  undefined1 local_48;
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_28;
  undefined1 local_24;
  undefined8 local_23;
  undefined4 local_1b;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_68;
  uVar4 = 0;
  if (param_2 == 0) {
    if (param_3 != (uint *)0x0) {
      uVar2 = 0;
      local_28 = 0x10101;
      local_24 = 0;
      local_23 = 0;
      local_1b = 0;
      if (*param_3 != 0) {
        do {
          *(undefined1 *)(uVar2 + 4 + (longlong)param_3) =
               *(undefined1 *)((longlong)&local_28 + uVar2);
          uVar3 = (int)uVar2 + 1;
          uVar2 = (ulonglong)uVar3;
        } while (uVar3 < *param_3);
      }
    }
  }
  else if (param_2 == 1) {
    DAT_1c000c5c0 = DAT_1c000c5c0 + -1;
    if (*(char *)(param_1 + 0x89) != '\0') {
      StorPortNotification(6,param_1,VFheartbeatTimer);
    }
    if (*(int *)(param_1 + 0x8a18) != 1) {
      *(undefined1 *)(param_1 + 0x7bbe) = 1;
      (**(code **)(*(longlong *)(param_1 + 0x188) + 0x28))(param_1);
      if (*(char *)(param_1 + 0x7bbf) == '\0') {
        *(undefined2 *)(param_1 + 0x7bd0) = 0;
        AbortPendedCommands(param_1);
        *(undefined4 *)(param_1 + 0x7bcc) = 30000000;
        bVar1 = SendAndWaitDCMD(param_1,0x1101000);
        if (!bVar1) {
          local_38 = 0x13;
          local_40 = 6;
          local_48 = 0xff;
          StorPortLogError(param_1,0,0xff);
        }
        *(undefined4 *)(param_1 + 0x7bcc) = 30000000;
        bVar1 = SendAndWaitDCMD(param_1,(-(uint)(*(char *)(param_1 + 0x21ef) != '\0') & 0xffff0000)
                                        + 0x1060000);
        if (!bVar1) {
          local_38 = 0x13;
          local_40 = 6;
          local_48 = 0xff;
          StorPortLogError(param_1,0,0xff);
        }
      }
    }
  }
  else if (param_2 == 2) {
    *(undefined1 *)(param_1 + 0x7bbe) = 1;
    (**(code **)(*(longlong *)(param_1 + 0x188) + 0x28))();
    StorPortPause(param_1,0xe10);
    DAT_1c000c5c0 = DAT_1c000c5c0 + '\x01';
    uVar3 = 0;
    *(undefined1 *)(param_1 + 0x21ef) = 0;
    *(undefined2 *)(param_1 + 0x7bd0) = 0x200;
    *(undefined2 *)(param_1 + 0x21cc) = 0;
    *(undefined4 *)(param_1 + 0x21c0) = 0;
    if (*(int *)(param_1 + 0x66c0) != 0) {
      do {
        uVar2 = (ulonglong)uVar3;
        uVar3 = uVar3 + 1;
        *(undefined8 *)(param_1 + 400 + uVar2 * 8) = 0;
      } while (uVar3 < *(uint *)(param_1 + 0x66c0));
    }
    *(undefined4 *)(param_1 + 0x7bcc) = 600000000;
    StorPortNotification(6,param_1,TimeForFwareReadyInitWithRetry,250000);
  }
  else {
    uVar4 = 1;
  }
  return uVar4;
}



===== AbortPendedCommands @ 1c0001dac =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void AbortPendedCommands(longlong param_1)

{
  longlong lVar1;
  bool bVar2;
  
  lVar1 = *(longlong *)(param_1 + 0xd8);
  if (*(char *)(param_1 + 0x7be3) != '\0') {
    PrepareAbortFrame(param_1,3);
    (**(code **)(*(longlong *)(param_1 + 0x188) + 0x58))(param_1,lVar1);
    bVar2 = WaitForCmdStatus(param_1,lVar1);
    if (bVar2) {
      *(undefined1 *)(param_1 + 0x7be3) = 0;
    }
    else {
      StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x13);
    }
  }
  if (*(char *)(param_1 + 0x21ee) != '\0') {
    PrepareAbortFrame(param_1,2);
    (**(code **)(*(longlong *)(param_1 + 0x188) + 0x58))(param_1,lVar1);
    bVar2 = WaitForCmdStatus(param_1,lVar1);
    if (bVar2) {
      *(undefined1 *)(param_1 + 0x21ee) = 0;
    }
    else {
      StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x13);
    }
  }
  return;
}



===== MegaSASInitialize @ 1c0001ea0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 MegaSASInitialize(longlong param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_res8 [2];
  
  if (*(char *)(param_1 + 0x88) == '\0') {
    if ((*(char *)(param_1 + 0x76e9) != '\0') && (*(char *)(param_1 + 0x76eb) != '\0')) {
      puVar1 = (undefined4 *)(param_1 + 0x76f0);
      MemFastZero(puVar1,0x28);
      *puVar1 = 4;
      iVar2 = StorPortExtendedFunction(0xe,param_1,1,puVar1);
      if (iVar2 != 0) {
        *(undefined1 *)(param_1 + 0x76eb) = 0;
      }
      if (*(char *)(param_1 + 0x76eb) != '\0') {
        *(uint *)(param_1 + 0x76f8) = (uint)((*(byte *)(param_1 + 0x76f8) & 1) != 0);
        iVar2 = StorPortExtendedFunction(0xe,param_1,0,puVar1);
        if (iVar2 != 0) {
          *(undefined1 *)(param_1 + 0x76eb) = 0;
        }
      }
    }
    local_res8[0] = 0;
    uVar3 = StorPortNotification(0x1000,param_1,InitDPC,local_res8);
  }
  else {
    *(undefined1 *)(param_1 + 0x7bbe) = 0;
    uVar3 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x20))(param_1);
  }
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



===== WaitForFwareReadyWithRetry @ 1c0001f98 =====

undefined8 WaitForFwareReadyWithRetry(longlong param_1)

{
  ulonglong uVar1;
  
  *(undefined4 *)(param_1 + 0x7bcc) = 600000000;
  while( true ) {
    while( true ) {
      uVar1 = CheckFirmwareReady(param_1);
      if ((char)uVar1 != '\0') {
        return CONCAT71((int7)(uVar1 >> 8),1);
      }
      if ((*(int *)(param_1 + 0x7bcc) < 0) ||
         ((*(uint *)(param_1 + 0x21c4) & 0xf0000000) == 0xf0000000)) break;
      StorPortStallExecution(1000);
      *(int *)(param_1 + 0x7bcc) = *(int *)(param_1 + 0x7bcc) + -1000;
    }
    uVar1 = CheckResetRetries(param_1);
    if ((char)uVar1 == '\0') break;
    *(undefined4 *)(param_1 + 0x7bcc) = 600000000;
  }
  return uVar1 & 0xffffffffffffff00;
}



===== TimeForFwareReadyInitWithRetry @ 1c0002010 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void TimeForFwareReadyInitWithRetry(longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  
  uVar1 = CheckFirmwareReady(param_1);
  if ((char)uVar1 == '\0') {
    if ((-1 < *(int *)(param_1 + 0x7bcc)) &&
       ((*(uint *)(param_1 + 0x21c4) & 0xf0000000) != 0xf0000000)) {
      *(int *)(param_1 + 0x7bcc) = *(int *)(param_1 + 0x7bcc) + -250000;
      goto LAB_1c0002073;
    }
    uVar2 = CheckResetRetries(param_1);
    if ((char)uVar2 == '\0') {
      uVar3 = 0x12;
      goto LAB_1c000205c;
    }
  }
  else {
    uVar2 = InitializeAdapter(param_1);
    if ((char)uVar2 != '\0') {
      *(undefined1 *)(param_1 + 0x7bbe) = 0;
      (**(code **)(*(longlong *)(param_1 + 0x188) + 0x20))();
      StorPortResume(param_1);
                    /* WARNING: Could not recover jumptable at 0x0001c00020dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      StorPortReady(param_1);
      return;
    }
    uVar2 = CheckResetRetries(param_1);
    if ((char)uVar2 == '\0') {
      uVar3 = 9;
LAB_1c000205c:
      SetDeadAdapter(param_1,uVar3);
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x7bcc) = 600000000;
LAB_1c0002073:
                    /* WARNING: Could not recover jumptable at 0x0001c000208d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(6,param_1,TimeForFwareReadyInitWithRetry,250000);
  return;
}



===== InitializeAdapter @ 1c00020e4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong InitializeAdapter(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  bool bVar3;
  undefined1 uVar4;
  undefined7 extraout_var;
  undefined7 extraout_var_00;
  undefined7 extraout_var_01;
  undefined7 extraout_var_02;
  undefined7 extraout_var_03;
  ulonglong uVar5;
  undefined7 extraout_var_04;
  int iVar6;
  uint uVar7;
  
  *(undefined1 *)(param_1 + 0x7be3) = 0;
  *(undefined1 *)(param_1 + 0x21ee) = 0;
  *(undefined8 *)(param_1 + 0x8a18) = 0;
  *(undefined8 *)(param_1 + 0x8a24) = 0;
  *(undefined4 *)(param_1 + 0x8a20) = 0;
  if (*(char *)(param_1 + 0x7be0) == '\0') {
    uVar5 = 0;
    if (*(char *)(param_1 + 0x76ea) != '\0') {
      do {
        uVar7 = (int)uVar5 + 1;
        *(undefined4 *)(*(longlong *)(param_1 + 0x7bd8) + 4 + uVar5 * 0x10) =
             *(undefined4 *)(*(longlong *)(param_1 + 0x7bd8) + uVar5 * 0x10);
        uVar5 = (ulonglong)uVar7;
      } while (uVar7 < *(byte *)(param_1 + 0x76ea));
    }
    *(undefined1 *)(param_1 + 0x7bd4) = 0;
  }
  *(undefined4 *)(param_1 + 0x7bcc) = 60000000;
  do {
    lVar1 = *(longlong *)(param_1 + 0xd8);
    cVar2 = (*(code *)**(undefined8 **)(param_1 + 0x188))
                      (param_1,lVar1,*(undefined8 *)(param_1 + 0x148));
    bVar3 = WaitForCmdStatus(param_1,lVar1);
    uVar5 = CONCAT71(extraout_var,bVar3);
    if (!bVar3) goto LAB_1c00022c8;
  } while (cVar2 == '\0');
  uVar7 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x30))(*(undefined8 *)(param_1 + 0x80));
  *(uint *)(param_1 + 0x21c4) = uVar7;
  uVar5 = (ulonglong)(uVar7 & 0xf0000000);
  if ((uVar7 & 0xf0000000) != 0xc0000000) goto LAB_1c00022c8;
  SendAndWaitDCMD(param_1,0x2010100);
  if (*(char *)(param_1 + 0x88) != '\0') goto LAB_1c00023c4;
  bVar3 = SendAndWaitDCMD(param_1,0x1010000);
  uVar5 = CONCAT71(extraout_var_00,bVar3);
  if (!bVar3) goto LAB_1c00022c8;
  lVar1 = *(longlong *)(param_1 + 0x148);
  if ((*(byte *)(lVar1 + 0x20) & 0x10) == 0) {
    *(undefined4 *)(param_1 + 0x8a3c) = 0;
  }
  else if ((*(uint *)(lVar1 + 0x7a4) & 0x6000000) == 0) {
    *(undefined4 *)(param_1 + 0x8a3c) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x8a3c) = 2;
  }
  if (*(int *)(param_1 + 0x8a3c) == 2) {
    uVar4 = *(undefined1 *)(lVar1 + 0x7e6);
LAB_1c0002259:
    *(undefined1 *)(param_1 + 0x7bd3) = uVar4;
  }
  else {
    if (*(int *)(param_1 + 0x8a3c) == 1) {
      uVar4 = *(undefined1 *)(lVar1 + 2000);
      goto LAB_1c0002259;
    }
    *(undefined1 *)(param_1 + 0x89) = 0;
    *(undefined1 *)(param_1 + 0x7bd3) = 0;
  }
  if (*(char *)(param_1 + 0x7bd3) != '\0') {
    *(undefined1 *)(param_1 + 0x89) = 1;
  }
  bVar3 = SendAndWaitDCMD(param_1,0x1020100);
  uVar5 = CONCAT71(extraout_var_01,bVar3);
  if (bVar3) {
    bVar3 = SendAndWaitDCMD(param_1,0x1040100);
    uVar5 = CONCAT71(extraout_var_02,bVar3);
    if (bVar3) {
      if (*(char *)(param_1 + 0x89) != '\0') {
        if (*(int *)(param_1 + 0x8a3c) == 2) {
          iVar6 = 0x3150200;
        }
        else {
          iVar6 = 0x3200200;
        }
        bVar3 = SendAndWaitDCMD(param_1,iVar6);
        uVar5 = CONCAT71(extraout_var_03,bVar3);
        if (!bVar3) goto LAB_1c00022c8;
        bVar3 = SendAndWaitDCMD(param_1,0x10e8485);
        if (!bVar3) {
          uVar5 = StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x61);
          *(undefined1 *)(param_1 + 0x89) = 0;
          *(undefined1 *)(param_1 + 0x7bd0) = 5;
          goto LAB_1c00022c8;
        }
        *(undefined4 *)(*(longlong *)(param_1 + 0x168) + 0x20) = 0xbaddaddd;
      }
      if (*(char *)(param_1 + 0x7be0) != '\0') {
        if (*(char *)(param_1 + 0x7be2) == '\0') {
          MPT_UpdateReplyQueue(param_1);
        }
        else {
          *(undefined4 *)(param_1 + 0x7be4) = 0;
          bVar3 = SendAndWaitDCMD(param_1,0x300e101);
          uVar5 = CONCAT71(extraout_var_04,bVar3);
          if (!bVar3) goto LAB_1c00022c8;
          MPT_UpdateReplyQueue(param_1);
          *(undefined4 *)(param_1 + 0x7be4) = 1;
          IssueDCMD(param_1,0x300e101);
        }
        if (0 < *(int *)(param_1 + 0x7ba4)) {
          uVar5 = SetDeadAdapter(param_1,100);
          goto LAB_1c00022c8;
        }
      }
      *(undefined1 *)(param_1 + 0x21ed) = 1;
      IssueDCMD(param_1,0x1040500);
      *(undefined1 *)(param_1 + 0x21ed) = 0;
LAB_1c00023c4:
      MemFastZero((void *)(param_1 + 0x7c08),0x800);
      uVar5 = MemFastZero((void *)(param_1 + 0x66e0),0x1000);
      if (*(char *)(param_1 + 0x89) != '\0') {
        if (*(int *)(param_1 + 0xb8) == 0) {
          *(undefined4 *)(param_1 + 0x7bb0) = 5;
        }
        else {
          *(int *)(param_1 + 0x7bb0) = *(int *)(param_1 + 0xb8);
        }
        *(int *)(param_1 + 0x7bb0) = *(int *)(param_1 + 0x7bb0) * 1000000;
        if (*(int *)(param_1 + 0xbc) == 0) {
          *(undefined4 *)(param_1 + 0x7bb4) = 0x1e;
        }
        else {
          *(int *)(param_1 + 0x7bb4) = *(int *)(param_1 + 0xbc);
        }
        uVar7 = *(int *)(param_1 + 0x7bb4) * 1000000;
        uVar5 = (ulonglong)uVar7;
        *(uint *)(param_1 + 0x7bb4) = uVar7;
        if ((*(char *)(param_1 + 0x21e5) != '\0') && (*(char *)(param_1 + 0x21f0) == '\0')) {
          uVar5 = StorPortNotification(6,param_1,VFheartbeatTimer);
        }
      }
      return CONCAT71((int7)(uVar5 >> 8),1);
    }
  }
LAB_1c00022c8:
  return uVar5 & 0xffffffffffffff00;
}



===== CheckFirmwareReady @ 1c000247c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong CheckFirmwareReady(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  uint local_res8 [2];
  uint local_res10 [2];
  uint local_res18 [4];
  
  if ((*(char *)(param_1 + 0x89) != '\0') &&
     (uVar1 = *(uint *)(*(longlong *)(param_1 + 0x80) + 8), uVar2 = (ulonglong)uVar1,
     (uVar1 & 4) != 0)) goto LAB_1c00025a0;
  uVar1 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x30))(*(undefined8 *)(param_1 + 0x80));
  *(uint *)(param_1 + 0x21c4) = uVar1;
  if (uVar1 != *(uint *)(param_1 + 0x21c8)) {
    *(uint *)(param_1 + 0x21c8) = uVar1;
    *(undefined1 *)(param_1 + 0x21cc) = 0;
  }
  uVar1 = uVar1 >> 0x1c;
  if (uVar1 == 6) {
    uVar2 = 0;
    if (*(char *)(param_1 + 0x21cc) != '\0') goto LAB_1c00025a0;
    MemFastZero(local_res18,4);
    local_res10[0] = local_res18[0] | 0x18;
  }
  else {
    if (uVar1 != 9) {
      if (uVar1 == 0xb) {
        *(undefined4 *)(param_1 + 0x21c8) = 0xff;
        return 1;
      }
      uVar2 = (ulonglong)(uVar1 - 0xc);
      if ((uVar1 - 0xc == 0) && (*(char *)(param_1 + 0x21cd) == '\0')) {
        MemFastZero(local_res8,(ulonglong)(uVar1 - 8));
        uVar2 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x40))
                          (*(undefined8 *)(param_1 + 0x80),local_res8[0] | 7);
        *(undefined1 *)(param_1 + 0x21cd) = 1;
      }
      goto LAB_1c00025a0;
    }
    uVar2 = 0;
    if (*(char *)(param_1 + 0x21cc) != '\0') goto LAB_1c00025a0;
    MemFastZero(local_res10,4);
    local_res10[0] = local_res10[0] | 0x10;
  }
  uVar2 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x40))
                    (*(undefined8 *)(param_1 + 0x80),local_res10[0]);
  *(undefined1 *)(param_1 + 0x21cc) = 1;
LAB_1c00025a0:
  return uVar2 & 0xffffffffffffff00;
}



===== MemFastZero @ 1c00025a8 =====

void MemFastZero(void *param_1,ulonglong param_2)

{
  ulonglong uVar1;
  
  uVar1 = param_2 >> 3 & 0x1fffffff;
  if ((int)uVar1 != 0) {
    memset(param_1,0,uVar1 << 3);
    param_1 = (void *)((longlong)param_1 + uVar1 * 8);
  }
  if ((param_2 & 7) != 0) {
    memset(param_1,0,(ulonglong)((uint)param_2 & 7));
  }
  return;
}



===== MemFastMove @ 1c00025fc =====

void MemFastMove(undefined8 *param_1,undefined8 *param_2,uint param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  uint uVar3;
  
  for (uVar3 = param_3 >> 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_1 = uVar1;
    param_1 = param_1 + 1;
  }
  uVar3 = param_3 & 7;
  if (uVar3 != 0) {
    lVar2 = (longlong)param_1 - (longlong)param_2;
    do {
      *(undefined1 *)(lVar2 + (longlong)param_2) = *(undefined1 *)param_2;
      param_2 = (undefined8 *)((longlong)param_2 + 1);
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return;
}



===== CDB_GetInfo @ 1c0002638 =====

void CDB_GetInfo(longlong param_1,char param_2,ulonglong *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == '\x06') {
    *param_3 = (ulonglong)
               (((*(byte *)(param_1 + 1) & 0x1f) << 8 | (uint)*(byte *)(param_1 + 2)) << 8) |
               (ulonglong)*(byte *)(param_1 + 3);
    *param_4 = (uint)*(byte *)(param_1 + 4);
    return;
  }
  if (param_2 == '\n') {
    *param_3 = (ulonglong)
               CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3))
                                 ,*(undefined1 *)(param_1 + 4)),*(undefined1 *)(param_1 + 5));
    uVar2 = (uint)*(byte *)(param_1 + 7);
    uVar1 = (uint)*(byte *)(param_1 + 8);
  }
  else if (param_2 == '\f') {
    *param_3 = (ulonglong)
               CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3))
                                 ,*(undefined1 *)(param_1 + 4)),*(undefined1 *)(param_1 + 5));
    uVar2 = (uint)CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 6),*(undefined1 *)(param_1 + 7)),
                           *(undefined1 *)(param_1 + 8));
    uVar1 = (uint)*(byte *)(param_1 + 9);
  }
  else {
    if (param_2 != '\x10') {
      return;
    }
    *param_3 = ((longlong)
                (int)((uint)CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 2),
                                              *(undefined1 *)(param_1 + 3)),
                                     *(undefined1 *)(param_1 + 4)) << 8) |
               (ulonglong)*(byte *)(param_1 + 5)) << 0x20 |
               (ulonglong)
               CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 6),*(undefined1 *)(param_1 + 7)),
                        *(undefined1 *)(param_1 + 8)) << 8 | (ulonglong)*(byte *)(param_1 + 9);
    uVar2 = (uint)CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 10),*(undefined1 *)(param_1 + 0xb)),
                           *(undefined1 *)(param_1 + 0xc));
    uVar1 = (uint)*(byte *)(param_1 + 0xd);
  }
  *param_4 = uVar2 << 8 | uVar1;
  return;
}



===== CDB_SetStartLBA @ 1c0002778 =====

void CDB_SetStartLBA(longlong param_1,char param_2,undefined8 param_3)

{
  undefined1 uVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  
  uVar3 = (undefined1)param_3;
  bVar2 = (byte)((ulonglong)param_3 >> 0x10);
  uVar1 = (undefined1)((ulonglong)param_3 >> 8);
  if (param_2 == '\x06') {
    *(undefined1 *)(param_1 + 3) = uVar3;
    *(byte *)(param_1 + 1) = *(byte *)(param_1 + 1) ^ (bVar2 ^ *(byte *)(param_1 + 1)) & 0x1f;
    *(undefined1 *)(param_1 + 2) = uVar1;
    return;
  }
  uVar4 = (undefined1)((ulonglong)param_3 >> 0x18);
  if ((param_2 == '\n') || (param_2 == '\f')) {
    *(undefined1 *)(param_1 + 5) = uVar3;
    *(undefined1 *)(param_1 + 4) = uVar1;
  }
  else {
    if (param_2 != '\x10') {
      return;
    }
    *(undefined1 *)(param_1 + 9) = uVar3;
    *(undefined1 *)(param_1 + 8) = uVar1;
    *(byte *)(param_1 + 7) = bVar2;
    *(undefined1 *)(param_1 + 6) = uVar4;
    *(char *)(param_1 + 5) = (char)((ulonglong)param_3 >> 0x20);
    *(char *)(param_1 + 4) = (char)((ulonglong)param_3 >> 0x28);
    bVar2 = (byte)((ulonglong)param_3 >> 0x30);
    uVar4 = (undefined1)((ulonglong)param_3 >> 0x38);
  }
  *(byte *)(param_1 + 3) = bVar2;
  *(undefined1 *)(param_1 + 2) = uVar4;
  return;
}



===== CDB_SetBlockCnt @ 1c0002814 =====

void CDB_SetBlockCnt(longlong param_1,undefined8 param_2,char param_3)

{
  undefined1 uVar1;
  undefined1 uVar3;
  undefined1 uVar2;
  undefined1 uVar4;
  
  uVar2 = (undefined1)param_2;
  uVar3 = (undefined1)((ulonglong)param_2 >> 8);
  if (param_3 == '\n') {
    *(undefined1 *)(param_1 + 8) = uVar2;
    *(undefined1 *)(param_1 + 7) = uVar3;
  }
  else {
    uVar1 = (undefined1)((ulonglong)param_2 >> 0x10);
    uVar4 = (undefined1)((ulonglong)param_2 >> 0x18);
    if (param_3 == '\f') {
      *(undefined1 *)(param_1 + 9) = uVar2;
      *(undefined1 *)(param_1 + 8) = uVar3;
      *(undefined1 *)(param_1 + 6) = uVar4;
      *(undefined1 *)(param_1 + 7) = uVar1;
      return;
    }
    if (param_3 == '\x10') {
      *(undefined1 *)(param_1 + 0xd) = uVar2;
      *(undefined1 *)(param_1 + 0xc) = uVar3;
      *(undefined1 *)(param_1 + 10) = uVar4;
      *(undefined1 *)(param_1 + 0xb) = uVar1;
      return;
    }
  }
  return;
}



===== GetRegistrySettings @ 1c0002870 =====

void GetRegistrySettings(char *param_1,longlong param_2)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == (char *)0x0) {
    if (*(char *)(param_2 + 0x7be0) != '\0') {
      *(undefined1 *)(param_2 + 0x7be2) = 1;
    }
    *(undefined1 *)(param_2 + 0xa1) = 1;
  }
  else {
    ParseArgumentString(param_1);
    if (DAT_1c000c428 == '\0') {
      if (*(char *)(param_2 + 0x7be0) != '\0') {
        *(bool *)(param_2 + 0x7be2) = DAT_1c000c448 == '\0';
        *(bool *)(param_2 + 0xa0) = DAT_1c000c458 != '\0';
        if (DAT_1c000c488 != '\0') {
          *(undefined1 *)(param_2 + 0x90) = DAT_1c000c48c;
        }
        if (DAT_1c000c3d8 != '\0') {
          *(undefined4 *)(param_2 + 0x8c) = DAT_1c000c3dc;
        }
      }
      if (DAT_1c000c498 != '\0') {
        *(undefined1 *)(param_2 + 0x91) = 1;
      }
      if (DAT_1c000c3e8 != '\0') {
        *(undefined4 *)(param_2 + 0x94) = DAT_1c000c3ec;
      }
      if (DAT_1c000c468 != '\0') {
        *(undefined4 *)(param_2 + 0x98) = DAT_1c000c46c;
      }
      if (DAT_1c000c478 != '\0') {
        *(undefined4 *)(param_2 + 0x9c) = DAT_1c000c47c;
      }
      if (DAT_1c000c4a8 != '\0') {
        *(undefined1 *)(param_2 + 0x76eb) = 0;
      }
      if (DAT_1c000c3f8 != '\0') {
        *(undefined4 *)(param_2 + 0xa8) = DAT_1c000c3fc;
      }
      if (DAT_1c000c408 != '\0') {
        *(undefined4 *)(param_2 + 0xa4) = DAT_1c000c40c;
      }
      if ((DAT_1c000c438 != '\0') &&
         (extendedTimeout = DAT_1c000c43c * 1000000, 179999999 < extendedTimeout - 1U)) {
        extendedTimeout = 180000000;
      }
      *(bool *)(param_2 + 0xa1) = DAT_1c000c4b8 != '\0';
      if (DAT_1c000c4c8 != '\0') {
        *(int *)(param_2 + 0x8514) = DAT_1c000c4cc;
        iVar1 = DAT_1c000c4cc;
        bVar2 = DAT_1c000c4cc == 0;
        *(undefined1 *)(param_2 + 0x8511) = 1;
        if (bVar2) {
          iVar1 = 1;
        }
        *(int *)(param_2 + 0x8514) = iVar1;
      }
      *(bool *)(param_2 + 0x8a38) = DAT_1c000c4d8 != '\0';
      if (DAT_1c000c4e8 != '\0') {
        *(undefined4 *)(param_2 + 0xb8) = DAT_1c000c4ec;
      }
      if (DAT_1c000c4f8 != '\0') {
        *(undefined4 *)(param_2 + 0xbc) = DAT_1c000c4fc;
      }
      if (DAT_1c000c508 != '\0') {
        *(undefined1 *)(param_2 + 0x7bc2) = 1;
      }
    }
    else {
      *(undefined1 *)(param_2 + 0x88) = 1;
      if (*(char *)(param_2 + 0x7be0) != '\0') {
        *(undefined1 *)(param_2 + 0x7be2) = 1;
      }
    }
  }
  return;
}



===== ParseArgumentString @ 1c0002a70 =====

void ParseArgumentString(char *param_1)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  longlong lVar4;
  int iVar5;
  longlong lVar6;
  byte *pbVar7;
  undefined **ppuVar8;
  longlong lVar9;
  
  ppuVar8 = &regSettings;
  lVar9 = 0x14;
  do {
    pcVar3 = strstr(param_1,*ppuVar8);
    if (pcVar3 != (char *)0x0) {
      lVar6 = -1;
      *(undefined1 *)(ppuVar8 + 1) = 1;
      do {
        lVar6 = lVar6 + 1;
      } while ((*ppuVar8)[lVar6] != '\0');
      if (pcVar3[lVar6] == '=') {
        lVar6 = -1;
        do {
          lVar4 = lVar6;
          lVar6 = lVar4 + 1;
        } while ((*ppuVar8)[lVar6] != '\0');
        iVar5 = 0;
        pcVar3 = pcVar3 + lVar4 + 2;
        cVar2 = *pcVar3;
        if ((cVar2 == '0') && (pcVar3[1] == 'x')) {
          pbVar7 = (byte *)(pcVar3 + 2);
          do {
            bVar1 = *pbVar7;
            if ((byte)(bVar1 - 0x30) < 10) {
              iVar5 = iVar5 * 0x10 + -0x30;
            }
            else {
              if ((char)bVar1 < 'A') goto LAB_1c0002b35;
              if ((bVar1 & 0x20) == 0) {
                iVar5 = iVar5 * 0x10 + -0x37;
              }
              else {
                iVar5 = iVar5 * 0x10 + -0x57;
              }
            }
            iVar5 = iVar5 + (char)bVar1;
            pbVar7 = pbVar7 + 1;
          } while( true );
        }
        while (('/' < cVar2 && (cVar2 < ':'))) {
          pcVar3 = pcVar3 + 1;
          iVar5 = (int)cVar2 + (iVar5 * 5 + -0x18) * 2;
          cVar2 = *pcVar3;
        }
LAB_1c0002b35:
        *(int *)((longlong)ppuVar8 + 0xc) = iVar5;
      }
    }
    ppuVar8 = ppuVar8 + 2;
    lVar9 = lVar9 + -1;
    if (lVar9 == 0) {
      return;
    }
  } while( true );
}



===== WaitForCmdStatus @ 1c0002b58 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool WaitForCmdStatus(longlong param_1,longlong param_2)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = *(char *)(param_2 + 2);
  while( true ) {
    if (cVar1 != -1) {
      return *(char *)(param_2 + 2) == '\0';
    }
    uVar2 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x30))(*(undefined8 *)(param_1 + 0x80));
    *(uint *)(param_1 + 0x21c4) = uVar2;
    if (((uVar2 & 0xf0000000) == 0xf0000000) || (*(int *)(param_1 + 0x7bcc) < 1)) break;
    StorPortStallExecution(1000);
    *(int *)(param_1 + 0x7bcc) = *(int *)(param_1 + 0x7bcc) + -1000;
    cVar1 = *(char *)(param_2 + 2);
  }
  return false;
}



===== SendAndWaitDCMD @ 1c0002bdc =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool SendAndWaitDCMD(longlong param_1,int param_2)

{
  bool bVar1;
  undefined1 *puVar2;
  
  puVar2 = SetupDCMD(param_1,param_2);
  if (*(int *)(puVar2 + 0x18) != 0x1101000) {
    LOCK();
    *(int *)(param_1 + 0x7ba4) = *(int *)(param_1 + 0x7ba4) + 1;
    UNLOCK();
  }
  *(ushort *)(puVar2 + 0x10) = *(ushort *)(puVar2 + 0x10) | 1;
  *(undefined2 *)(puVar2 + 0x12) = 0x3c;
  (**(code **)(*(longlong *)(param_1 + 0x188) + 0x58))(param_1,puVar2);
  bVar1 = WaitForCmdStatus(param_1,(longlong)puVar2);
  if (bVar1) {
    CompleteDCMD(param_1,(longlong)puVar2,'\x01');
  }
  return bVar1;
}



===== IssueDCMD @ 1c0002c60 =====

void IssueDCMD(longlong param_1,int param_2)

{
  undefined1 *puVar1;
  
  puVar1 = SetupDCMD(param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x0001c000a040. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(longlong *)(param_1 + 0x188) + 0x58))(param_1,puVar1);
  return;
}



===== SetupDCMD @ 1c0002c90 =====

undefined1 * SetupDCMD(longlong param_1,int param_2)

{
  uint uVar1;
  undefined1 *puVar2;
  longlong lVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  void *pvVar6;
  byte bVar7;
  int iVar8;
  undefined4 uVar9;
  ulonglong uVar10;
  undefined1 uVar11;
  undefined1 *puVar12;
  undefined8 local_res8;
  
  if (param_2 == 0x2010100) {
    iVar8 = 4;
  }
  else if (param_2 == 0x300e101) {
    iVar8 = 3;
  }
  else if (param_2 == 0x1040500) {
    iVar8 = 2;
  }
  else if (param_2 == 0x3150200) {
    iVar8 = 5;
  }
  else {
    iVar8 = 1;
    if (param_2 == 0x3200200) {
      iVar8 = 5;
    }
  }
  puVar2 = *(undefined1 **)(param_1 + 0xd8 + (ulonglong)(iVar8 - 1U) * 8);
  MemFastZero(puVar2,0x578);
  *(undefined8 *)(puVar2 + 0x510) = *(undefined8 *)(param_1 + 0x100 + (ulonglong)(iVar8 - 1U) * 8);
  *(int *)(puVar2 + 0x508) = *(int *)(param_1 + 0x66bc) - iVar8;
  *puVar2 = 5;
  *(int *)(puVar2 + 0x18) = param_2;
  puVar2[2] = 0xff;
  *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(puVar2 + 0x508);
  if (param_2 == 0x1040500) {
    local_res8 = *(undefined8 *)(param_1 + 0x140);
    uVar9 = 0x100;
    MemFastZero(*(void **)(param_1 + 0x138),0x100);
    *(int *)(param_1 + 0x21d0) = *(int *)(param_1 + 0x21d0) + 1;
    uVar5 = *(undefined4 *)(param_1 + 0x21d0);
    if ((*(char *)(param_1 + 0x21ed) != '\0') && (*(char *)(param_1 + 0x89) == '\0')) {
      uVar5 = *(undefined4 *)(param_1 + 0x21dc);
    }
    *(undefined4 *)(puVar2 + 0x1c) = uVar5;
    *(undefined4 *)(puVar2 + 0x20) = *(undefined4 *)(param_1 + 0x666c);
    *(undefined1 *)(param_1 + 0x21ee) = 1;
    goto LAB_1c0002f5f;
  }
  if (param_2 == 0x1050000) {
    puVar2[0x1c] = 1;
    goto LAB_1c0002f96;
  }
  if (param_2 == 0x1060000) goto LAB_1c0002f96;
  if (param_2 == 0x10e8485) {
    local_res8 = *(undefined8 *)(param_1 + 0x170);
    uVar9 = 0x400;
    MemFastZero(*(void **)(param_1 + 0x168),0x400);
    *(undefined2 *)(puVar2 + 0x1c) = 0x400;
    goto LAB_1c0002f5f;
  }
  if (param_2 == 0x1101000) {
    puVar2[0x1c] = 3;
    goto LAB_1c0002f96;
  }
  if (param_2 == 0x2010100) {
    local_res8 = *(undefined8 *)(param_1 + 0x130);
    uVar9 = 0x1808;
    MemFastZero(*(void **)(param_1 + 0x128),0x1808);
    puVar2[0x1c] = 5;
  }
  else if (param_2 == 0x300e101) {
    uVar1 = *(uint *)(param_1 + 0x7be4);
    uVar11 = 0;
    uVar4 = 0;
    uVar9 = 0x2a0a8;
    if (uVar1 == 0) {
      local_res8 = *(undefined8 *)(param_1 + 0x7bf8);
      MemFastZero(*(void **)(param_1 + 0x7be8),0x2a0a8);
    }
    else {
      puVar12 = *(undefined1 **)(param_1 + 0x7be8 + (ulonglong)(uVar1 & 1) * 8);
      lVar3 = *(longlong *)(param_1 + 0x7be8 + (ulonglong)(uVar1 - 1 & 1) * 8);
      MemFastZero(puVar12,0x2a0a8);
      if ((*(int *)(lVar3 + 0x18) != 0) && (uVar10 = 0, *(int *)(lVar3 + 0x18) != 0)) {
        do {
          bVar7 = (char)uVar10 + 1;
          *puVar12 = *(undefined1 *)(uVar10 * 0x9e0 + 0x28c0 + lVar3);
          *(undefined2 *)(puVar12 + 2) = *(undefined2 *)(uVar10 * 0x9e0 + 0x28c6 + lVar3);
          puVar12 = puVar12 + 4;
          uVar10 = (ulonglong)bVar7;
        } while ((uint)bVar7 < *(uint *)(lVar3 + 0x18));
      }
      uVar11 = *(undefined1 *)(lVar3 + 0x18);
      local_res8 = *(undefined8 *)(param_1 + 0x7bf8 + (ulonglong)(uVar1 & 1) * 8);
      uVar4 = 1;
    }
    puVar2[0x1c] = uVar11;
    puVar2[0x1d] = uVar4;
    *(undefined1 *)(param_1 + 0x7be3) = 1;
  }
  else {
    if (param_2 == 0x3150200) {
      uVar10 = 0x820;
LAB_1c0002dd5:
      local_res8 = *(undefined8 *)(param_1 + 0x180);
      pvVar6 = *(void **)(param_1 + 0x178);
    }
    else {
      if (param_2 == 0x3200200) {
        uVar10 = 0x308;
        goto LAB_1c0002dd5;
      }
      local_res8 = *(undefined8 *)(param_1 + 0x150);
      uVar10 = 0xa00;
      pvVar6 = *(void **)(param_1 + 0x148);
    }
    uVar9 = (undefined4)uVar10;
    MemFastZero(pvVar6,uVar10);
  }
LAB_1c0002f5f:
  if ((*(char *)(param_1 + 0x21eb) == '\0') && (param_2 != 0x10e8485)) {
    *(int *)(puVar2 + 0x28) = (int)local_res8;
    *(undefined4 *)(puVar2 + 0x2c) = uVar9;
  }
  else {
    *(undefined4 *)(puVar2 + 0x2c) = local_res8._4_4_;
    *(int *)(puVar2 + 0x28) = (int)local_res8;
    *(undefined4 *)(puVar2 + 0x30) = uVar9;
    *(ushort *)(puVar2 + 0x10) = *(ushort *)(puVar2 + 0x10) | 2;
  }
  puVar2[7] = 1;
  *(undefined4 *)(puVar2 + 0x14) = uVar9;
LAB_1c0002f96:
  *(undefined1 **)(param_1 + 400 + (ulonglong)*(uint *)(puVar2 + 0x508) * 8) = puVar2;
  return puVar2;
}



===== CompleteDCMD @ 1c0002fc0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CompleteDCMD(longlong param_1,longlong param_2,char param_3)

{
  char cVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  bool bVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  longlong lVar12;
  byte bVar13;
  uint *puVar14;
  byte bVar15;
  byte bVar16;
  uint *puVar17;
  uint uVar18;
  undefined7 in_register_00000081;
  uint *puVar19;
  uint *puVar20;
  uint *puVar21;
  undefined4 local_res10;
  undefined4 uStackX_14;
  undefined4 uVar22;
  
  iVar2 = *(int *)(param_2 + 0x18);
  if (*(char *)(param_2 + 2) == '\0') {
    if (iVar2 == 0x1020100) {
      *(undefined1 *)(param_1 + 0x21e4) = *(undefined1 *)(*(longlong *)(param_1 + 0x148) + 0x19);
      *(byte *)(param_1 + 0x21e5) =
           ~(byte)(*(uint *)(*(longlong *)(param_1 + 0x148) + 0x20) >> 10) & 1;
      return;
    }
    if (iVar2 == 0x1040100) {
      puVar11 = *(undefined8 **)(param_1 + 0x148);
      uVar5 = puVar11[1];
      *(undefined8 *)(param_1 + 0x21d0) = *puVar11;
      *(undefined8 *)(param_1 + 0x21d8) = uVar5;
      *(undefined4 *)(param_1 + 0x21e0) = *(undefined4 *)(puVar11 + 2);
      return;
    }
    if (iVar2 == 0x1040500) {
      puVar4 = *(undefined4 **)(param_1 + 0x138);
      *(undefined4 *)(param_1 + 0x21d0) = *puVar4;
      if ((*(char *)(param_1 + 0x6618) != '\0') &&
         ((*(char *)(param_1 + 0x89) == '\0' || (*(char *)(param_1 + 0x7bc2) != '\0')))) {
        local_res10 = 0;
        MemFastMove((undefined8 *)&local_res10,(undefined8 *)(puVar4 + 3),4);
        *(undefined4 *)(param_1 + 0x665c) = *(undefined4 *)(param_1 + 0x74);
        *(undefined4 *)(param_1 + 0x6660) = local_res10;
        *(undefined4 *)(param_1 + 0x6664) = *puVar4;
        *(undefined4 *)(param_1 + 0x6668) = puVar4[2];
        uVar9 = uRam00000001c000c59c;
        uVar8 = uRam00000001c000c598;
        uVar7 = uRam00000001c000c594;
        uVar22 = _MegaSASWmiSetupDataGuid;
        *(undefined4 *)(param_1 + 0x6648) = 0x8a;
        *(undefined4 *)(param_1 + 0x6628) = 0;
        *(undefined4 *)(param_1 + 0x6634) = uVar22;
        *(undefined4 *)(param_1 + 0x6638) = uVar7;
        *(undefined4 *)(param_1 + 0x663c) = uVar8;
        *(undefined4 *)(param_1 + 0x6640) = uVar9;
        *(undefined4 *)(param_1 + 0x6650) = 0;
        *(undefined4 *)(param_1 + 0x6658) = 0x10;
        *(undefined4 *)(param_1 + 0x6654) = 0x40;
        *(undefined4 *)(param_1 + 0x661c) = 0x50;
        ScsiPortNotification(8,param_1,(undefined4 *)(param_1 + 0x661c),0xff);
      }
      *(undefined1 *)(param_1 + 0x21ee) = 0;
      *(undefined1 *)(param_1 + 0x7b98) = 1;
      uVar18 = puVar4[2];
      if (uVar18 < 0x8c) {
        if (0x89 < uVar18) goto LAB_1c00035fa;
        if (uVar18 != 4) {
          if (uVar18 != 0x51) {
            if ((uVar18 - 0x5b < 0x18) && ((0xa00001U >> (uVar18 - 0x5b & 0x1f) & 1) != 0)) {
              if (*(char *)(param_1 + 0x89) == '\0') {
                if (*(int *)(param_1 + 0x7b9c) == 0) {
                  *(undefined4 *)(param_1 + 0x7b9c) = 1;
                }
              }
              else {
                *(undefined1 *)(param_1 + 0x7bc3) = 1;
              }
            }
            goto LAB_1c0003620;
          }
          goto LAB_1c00035fa;
        }
LAB_1c00035d2:
        if (*(char *)(param_1 + 0x89) != '\0') {
          *(undefined1 *)(param_1 + 0x7bc5) = 1;
          goto LAB_1c0003620;
        }
        StorPortNotification(7,param_1);
      }
      else {
        if (uVar18 != 0xfc) {
          if (uVar18 == 0x152) goto LAB_1c00035d2;
          if (uVar18 != 0x15a) {
            if (uVar18 < 0x15f) goto LAB_1c0003620;
            if (0x160 < uVar18) {
              if (uVar18 == 0x17e) {
                cVar1 = *(char *)((longlong)puVar4 + 0xaa);
                StorPortQuerySystemTime(&local_res10);
                if (cVar1 == '0') {
                  if (*(char *)(param_1 + 0x25f8) != '\0') {
                    FUN_1c0007fd4(param_1,CONCAT44(uStackX_14,local_res10));
                  }
                  *(ulonglong *)(param_1 + 0x6608) = CONCAT44(uStackX_14,local_res10);
                  puVar11 = (undefined8 *)(param_1 + 0x6400);
                  for (lVar12 = 0x40; lVar12 != 0; lVar12 = lVar12 + -1) {
                    *puVar11 = CONCAT44(uStackX_14,local_res10);
                    puVar11 = puVar11 + 1;
                  }
                  *(undefined1 *)(param_1 + 0x25f8) = 1;
                }
                else if ((cVar1 == '1') && (*(char *)(param_1 + 0x25f8) != '\0')) {
                  *(undefined1 *)(param_1 + 0x25f8) = 0;
                  FUN_1c0007fd4(param_1,CONCAT44(uStackX_14,local_res10));
                }
              }
              goto LAB_1c0003620;
            }
          }
        }
LAB_1c00035fa:
        if (*(char *)(param_1 + 0x89) != '\0') {
          *(undefined1 *)(param_1 + 0x7bc4) = 1;
          goto LAB_1c0003620;
        }
      }
      StorPortNotification(7,param_1,1);
LAB_1c0003620:
      if (((*(char *)(param_1 + 0x89) != '\0') && (*(char *)(param_1 + 0x7bc6) == '\0')) &&
         ((*(char *)(param_1 + 0x7bc5) != '\0' || (*(char *)(param_1 + 0x7bc4) != '\0')))) {
        *(undefined1 *)(param_1 + 0x7b9a) = 1;
      }
      return;
    }
    if (iVar2 == 0x2010100) {
      if (param_3 != '\0') {
        *(undefined4 *)(param_1 + 0x7b9c) = 0;
        CompletePDquery(param_1);
        return;
      }
      uVar22 = 4;
      if (*(int *)(param_1 + 0x7b9c) != 2) {
        uVar22 = 0;
      }
      *(undefined4 *)(param_1 + 0x7b9c) = uVar22;
      return;
    }
    if (iVar2 == 0x300e101) {
      uVar18 = *(uint *)(param_1 + 0x7be4);
      *(undefined1 *)(param_1 + 0x7be3) = 0;
      if (*(char *)(param_1 + 0x7be2) == '\0') {
        return;
      }
      uVar10 = MegaSASValidateAndProcessMapInfo
                         (param_1,*(uint **)(param_1 + 0x7be8 + (ulonglong)(uVar18 & 1) * 8));
      if ((char)uVar10 != '\0') {
        if (uVar18 == 0) {
          return;
        }
        *(int *)(param_1 + 0x7be4) = *(int *)(param_1 + 0x7be4) + 1;
        if (param_3 == '\0') {
          *(undefined1 *)(param_1 + 0x7b99) = 1;
          return;
        }
        IssueDCMD(param_1,0x300e101);
        return;
      }
      uVar22 = 0x51;
      goto LAB_1c000301c;
    }
    if (iVar2 != 0x3150200) {
      if (iVar2 != 0x3200200) {
        return;
      }
      if (*(char *)(param_1 + 0x7bc1) == '\0') {
        puVar14 = *(uint **)(param_1 + 0x178);
        uVar18 = 0x308;
        puVar11 = *(undefined8 **)(param_1 + 0xc0);
LAB_1c000317c:
        MemFastMove(puVar11,(undefined8 *)puVar14,uVar18);
        *(undefined1 *)(param_1 + 0x7bc1) = 1;
        return;
      }
      pbVar3 = *(byte **)(param_1 + 0x178);
      bVar16 = 0;
      if (*pbVar3 != 0) {
        do {
          lVar12 = (ulonglong)pbVar3[2] + (ulonglong)bVar16 * 0xc;
          if (*(byte *)(lVar12 + 0xc + (longlong)*(undefined8 **)(param_1 + 0xc0)) !=
              pbVar3[lVar12 + 0xc]) {
            MemFastMove(*(undefined8 **)(param_1 + 0xc0),(undefined8 *)pbVar3,0x308);
            goto LAB_1c0003058;
          }
          bVar16 = bVar16 + 1;
        } while (bVar16 < *pbVar3);
      }
      goto LAB_1c000328c;
    }
    puVar14 = *(uint **)(param_1 + 0x178);
    puVar11 = *(undefined8 **)(param_1 + 0xc0);
    if (*(char *)(param_1 + 0x7bc1) == '\0') {
      uVar18 = *puVar14;
      goto LAB_1c000317c;
    }
    bVar16 = (byte)puVar14[1];
    puVar21 = puVar14 + 4;
    puVar17 = (uint *)(puVar11 + 2);
    if (bVar16 != 0) {
      bVar13 = 0;
      if (bVar16 != 0) {
        uVar10 = (ulonglong)*(byte *)((longlong)puVar14 + 6);
        puVar19 = puVar21;
        puVar20 = puVar17;
        do {
          bVar6 = false;
          bVar15 = 0;
          if (*(byte *)((longlong)puVar11 + 4) == 0) {
LAB_1c000320a:
            if (*(char *)(uVar10 + 0xf + (longlong)puVar19) != '\x0f') goto LAB_1c000329b;
          }
          else {
            do {
              if (((char)puVar19[1] == (char)puVar20[1]) &&
                 (bVar6 = true,
                 *(char *)(uVar10 + 0xf + (longlong)puVar19) !=
                 *(char *)(uVar10 + 0xf + (longlong)puVar20))) goto LAB_1c000329b;
              bVar15 = bVar15 + 1;
              puVar20 = (uint *)((longlong)puVar20 + (ulonglong)*puVar20);
            } while (bVar15 < *(byte *)((longlong)puVar11 + 4));
            if (!bVar6) goto LAB_1c000320a;
          }
          bVar13 = bVar13 + 1;
          puVar19 = (uint *)((longlong)puVar19 + (ulonglong)*puVar19);
        } while (bVar13 < bVar16);
      }
      bVar13 = 0;
      if (*(byte *)((longlong)puVar11 + 4) != 0) {
        uVar10 = (ulonglong)*(byte *)((longlong)puVar14 + 6);
        do {
          bVar6 = false;
          bVar15 = 0;
          if (bVar16 == 0) {
LAB_1c0003269:
            if (*(char *)(uVar10 + 0xf + (longlong)puVar17) != '\x0f') goto LAB_1c000329b;
          }
          else {
            do {
              if (((char)puVar17[1] == (char)puVar21[1]) &&
                 (bVar6 = true,
                 *(char *)(uVar10 + 0xf + (longlong)puVar17) !=
                 *(char *)(uVar10 + 0xf + (longlong)puVar21))) goto LAB_1c000329b;
              bVar15 = bVar15 + 1;
              puVar21 = (uint *)((longlong)puVar21 + (ulonglong)*puVar21);
            } while (bVar15 < bVar16);
            if (!bVar6) goto LAB_1c0003269;
          }
          bVar13 = bVar13 + 1;
          puVar17 = (uint *)((longlong)puVar17 + (ulonglong)*puVar17);
        } while (bVar13 < *(byte *)((longlong)puVar11 + 4));
      }
      *(undefined2 *)(param_1 + 0x7bc3) = 0;
      *(undefined1 *)(param_1 + 0x7bc5) = 0;
      goto LAB_1c000328c;
    }
    MemFastMove(puVar11,(undefined8 *)puVar14,*puVar14);
    *(undefined1 *)(param_1 + 0x7bc4) = 1;
LAB_1c000329b:
    MemFastMove(*(undefined8 **)(param_1 + 0xc0),(undefined8 *)*(uint **)(param_1 + 0x178),
                **(uint **)(param_1 + 0x178));
    if (*(char *)(param_1 + 0x7bc5) != '\0') {
      StorPortNotification(7,param_1,0);
      StorPortNotification(7,param_1,1);
      *(undefined2 *)(param_1 + 0x7bc3) = 0;
      goto LAB_1c00032e4;
    }
  }
  else {
    if ((iVar2 == 0x1040500) && (*(char *)(param_2 + 2) == '#')) {
      *(undefined1 *)(param_1 + 0x7b98) = 1;
      return;
    }
    if (iVar2 == 0x300e101) {
      uVar22 = 0x50;
LAB_1c000301c:
      StorPortLogError(param_1,0,CONCAT71(in_register_00000081,0xff),0xff,0xff,6,uVar22);
      *(undefined1 *)(param_1 + 0x7be2) = 0;
      return;
    }
    if ((iVar2 != 0x3150200) && (iVar2 != 0x3200200)) {
      return;
    }
LAB_1c0003058:
    if (*(char *)(param_1 + 0x7bc5) != '\0') {
      StorPortNotification(7,param_1,0);
      StorPortNotification(7,param_1,1);
      *(undefined2 *)(param_1 + 0x7bc3) = 0;
LAB_1c00032e4:
      *(undefined1 *)(param_1 + 0x7bc5) = 0;
    }
  }
  if (*(char *)(param_1 + 0x7bc4) != '\0') {
    StorPortNotification(7,param_1,1);
    *(undefined1 *)(param_1 + 0x7bc4) = 0;
  }
  if (*(char *)(param_1 + 0x7bc3) != '\0') {
    StorPortNotification(7,param_1,0);
    *(undefined1 *)(param_1 + 0x7bc3) = 0;
  }
LAB_1c000328c:
  *(undefined1 *)(param_1 + 0x7bc6) = 0;
  return;
}



===== CompletePDquery @ 1c00036a8 =====

void CompletePDquery(longlong param_1)

{
  ushort uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  
  lVar2 = *(longlong *)(param_1 + 0x128);
  MemFastZero((undefined8 *)(param_1 + 0x22f2),0x100);
  MemFastZero((undefined8 *)(param_1 + 0x24f2),0x100);
  cVar5 = '\0';
  uVar4 = 0;
  if (*(int *)(lVar2 + 4) != 0) {
    do {
      uVar1 = *(ushort *)(lVar2 + 8 + (ulonglong)uVar4 * 0x18);
      if (uVar1 < 0x100) {
        *(undefined1 *)((ulonglong)uVar1 + 0x22f2 + param_1) = 1;
        *(undefined1 *)((ulonglong)uVar1 + 0x24f2 + param_1) = 1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(lVar2 + 4));
  }
  MemFastMove((undefined8 *)(param_1 + 0x21f2),(undefined8 *)(param_1 + 0x22f2),0x100);
  MemFastMove((undefined8 *)(param_1 + 0x23f2),(undefined8 *)(param_1 + 0x24f2),0x100);
  *(undefined1 *)(param_1 + 0x21ec) = 1;
  if (*(char *)(param_1 + 0x89) == cVar5) {
    StorPortNotification(7,param_1);
  }
  else {
    *(undefined1 *)(param_1 + 0x7bc3) = 1;
    if (*(char *)(param_1 + 0x7bc6) == cVar5) {
      *(undefined1 *)(param_1 + 0x7bc6) = 1;
      iVar3 = 0x3150200;
      if (*(int *)(param_1 + 0x8a3c) != 2) {
        iVar3 = 0x3200200;
      }
      IssueDCMD(param_1,iVar3);
    }
  }
  return;
}



===== CompleteIoctlRequest @ 1c00037c4 =====

void CompleteIoctlRequest(longlong param_1,undefined8 *param_2)

{
  longlong lVar1;
  longlong lVar2;
  
  lVar1 = param_2[0xa0];
  lVar2 = *(longlong *)(lVar1 + 0x18);
  if (*(char *)((longlong)param_2 + 2) == '\0') {
    if (*(int *)(lVar2 + 0x34) == 0x1020200) {
      if (((*(char *)(lVar2 + 0xd5) != *(char *)(param_1 + 0x21e4)) &&
          (*(char *)(param_1 + 0x21e4) = *(char *)(lVar2 + 0xd5),
          *(char *)(param_1 + 0x21ec) != '\0')) && (*(int *)(param_1 + 0x7b9c) == 0)) {
        *(undefined4 *)(param_1 + 0x7b9c) = 1;
      }
      *(byte *)(param_1 + 0x21e5) = ~(byte)(*(uint *)(lVar2 + 0xdc) >> 10) & 1;
    }
    else if (*(int *)(lVar2 + 0x34) == 0x1170200) {
      ProcessPerfMetricRequest(param_1,(uint *)(lVar2 + 0xbc),*(int *)(lVar1 + 0x10) - 0xbd);
    }
  }
  MemFastMove((undefined8 *)(lVar2 + 0x1c),param_2,0x18);
  *(undefined1 *)(lVar1 + 3) = 1;
                    /* WARNING: Could not recover jumptable at 0x0001c0003895. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(0,param_1,lVar1);
  return;
}



===== PrepareAbortFrame @ 1c000389c =====

void PrepareAbortFrame(longlong param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  longlong lVar3;
  
  puVar2 = *(undefined1 **)(param_1 + 0xd8);
  lVar3 = *(longlong *)(param_1 + 0xd8 + (ulonglong)(param_2 - 1) * 8);
  MemFastZero(puVar2,0x578);
  *(undefined8 *)(puVar2 + 0x510) = *(undefined8 *)(param_1 + 0x100);
  *(int *)(puVar2 + 0x508) = *(int *)(param_1 + 0x66bc) + -1;
  *puVar2 = 6;
  uVar1 = *(undefined4 *)(lVar3 + 0x508);
  *(ushort *)(puVar2 + 0x10) = *(ushort *)(puVar2 + 0x10) | 1;
  *(undefined4 *)(puVar2 + 0x18) = uVar1;
  puVar2[2] = 0xff;
  *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(puVar2 + 0x508);
  *(undefined8 *)(puVar2 + 0x20) = *(undefined8 *)(lVar3 + 0x510);
  *(undefined4 *)(param_1 + 0x7bcc) = 30000000;
  return;
}



===== WDTSetupAndSendDCMD @ 1c0003930 =====

void WDTSetupAndSendDCMD(longlong param_1,int param_2)

{
  undefined1 *puVar1;
  
  puVar1 = SetupDCMD(param_1,param_2);
  if (*(int *)(puVar1 + 0x18) != 0x1101000) {
    LOCK();
    *(int *)(param_1 + 0x7ba4) = *(int *)(param_1 + 0x7ba4) + 1;
    UNLOCK();
  }
  *(ushort *)(puVar1 + 0x10) = *(ushort *)(puVar1 + 0x10) | 1;
  *(undefined2 *)(puVar1 + 0x12) = 0x3c;
  *(undefined4 *)(param_1 + 0x7bcc) = 30000000;
                    /* WARNING: Could not recover jumptable at 0x0001c000a040. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(longlong *)(param_1 + 0x188) + 0x58))(param_1);
  return;
}



===== ClearSRBExtension @ 1c0003988 =====

void * ClearSRBExtension(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined8 uVar2;
  void *pvVar3;
  undefined1 local_res8 [8];
  
  pvVar3 = (void *)(*(longlong *)(param_2 + 0x38) + (ulonglong)*(ushort *)(param_1 + 0x21e8) &
                   (longlong)(int)~(uint)*(ushort *)(param_1 + 0x21e8));
  MemFastZero(pvVar3,0x578);
  *(longlong *)((longlong)pvVar3 + 0x500) = param_2;
  *(undefined1 *)((longlong)pvVar3 + 0x51b) = 0;
  cVar1 = *(char *)(param_1 + 0x21eb);
  *(char *)((longlong)pvVar3 + 0x51a) = cVar1;
  *(byte *)((longlong)pvVar3 + 0x535) = (-(cVar1 != '\0') & 4U) + 8;
  uVar2 = StorPortGetPhysicalAddress(param_1,0,pvVar3,local_res8);
  *(undefined8 *)((longlong)pvVar3 + 0x510) = uVar2;
  return pvVar3;
}



===== MegaSASBuildIo @ 1c0003a20 =====

ulonglong MegaSASBuildIo(longlong param_1,longlong param_2,undefined8 param_3)

{
  ulonglong uVar1;
  
  uVar1 = FUN_1c0003a64(param_1,param_2,param_3);
  if ((char)uVar1 == '\0') {
    if (*(char *)(param_2 + 3) == '\0') {
      *(undefined2 *)(param_2 + 3) = 1;
    }
    uVar1 = StorPortNotification(0,param_1,param_2);
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    uVar1 = CONCAT71((int7)(uVar1 >> 8),1);
  }
  return uVar1;
}



===== FUN_1c0003a64 @ 1c0003a64 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FUN_1c0003a64(longlong param_1,longlong param_2,undefined8 param_3)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  undefined1 *puVar5;
  ulonglong uVar6;
  longlong lVar7;
  byte *pbVar8;
  undefined1 auStack_58 [32];
  undefined1 local_38 [4];
  undefined4 local_34;
  byte local_30;
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_58;
  if ((((*(char *)(param_2 + 2) == '\0') && (*(char *)(param_2 + 0x48) == -0x60)) &&
      (*(char *)(param_2 + 6) == '\0')) && (*(char *)(param_2 + 5) == '\x01')) {
    *(undefined1 *)(param_1 + 0x21f1) = 0;
  }
  lVar7 = param_2;
  puVar5 = (undefined1 *)CheckForValidIO(param_1,param_2,param_3);
  if ((char)puVar5 == '\0') {
LAB_1c0003aaf:
    return (ulonglong)puVar5 & 0xffffffffffffff00;
  }
  cVar1 = *(char *)(lVar7 + 2);
  *(undefined1 *)(lVar7 + 3) = 0;
  if (cVar1 != '\0') {
    if (cVar1 == '\x02') {
      uVar6 = MegaSASIoctl(param_1,lVar7);
      return uVar6;
    }
    if (cVar1 == '\a') {
      *(undefined1 *)(param_1 + 0x21ef) = 1;
      if (*(char *)(param_1 + 0x88) != '\0') {
        AbortPendedCommands(param_1);
        *(undefined4 *)(param_1 + 0x7bcc) = 30000000;
        SendAndWaitDCMD(param_1,0x1101000);
        *(undefined4 *)(param_1 + 0x7bcc) = 30000000;
        SendAndWaitDCMD(param_1,0x1060000);
        *(undefined2 *)(param_2 + 3) = 1;
        puVar5 = (undefined1 *)StorPortNotification(0,param_1,param_2);
      }
    }
    else if (cVar1 == '\b') {
      if (*(char *)(param_1 + 0xa1) != '\0') {
        puVar5 = ClearSRBExtension(param_1,lVar7);
        *puVar5 = 5;
        *(undefined4 *)(puVar5 + 0x18) = 0x1101000;
        puVar5[2] = 0xff;
        puVar5[0x1c] = 3;
LAB_1c0003b21:
        return CONCAT71((int7)((ulonglong)puVar5 >> 8),1);
      }
    }
    else if (cVar1 == '\x17') {
      puVar5 = (undefined1 *)MegaSASWmiSrb(param_1,lVar7);
    }
    else {
      if ((cVar1 == '$') && (*(char *)(param_1 + 0x88) == '\0')) goto LAB_1c0003b21;
      *(undefined1 *)(lVar7 + 3) = 6;
    }
    goto LAB_1c0003aaf;
  }
  pbVar8 = (byte *)(*(longlong *)(lVar7 + 0x38) + (ulonglong)*(ushort *)(param_1 + 0x21e8) &
                   (longlong)(int)~(uint)*(ushort *)(param_1 + 0x21e8));
  pbVar8[0x508] = 0;
  pbVar8[0x509] = 0;
  pbVar8[0x50a] = 0;
  pbVar8[0x50b] = 0;
  pbVar8[0x518] = 0;
  pbVar8[0x519] = 0;
  pbVar8[0x530] = 0;
  pbVar8[0x531] = 0;
  pbVar8[0x532] = 0;
  pbVar8[0x533] = 0;
  pbVar8[0x520] = 0;
  pbVar8[0x521] = 0;
  pbVar8[0x522] = 0;
  pbVar8[0x523] = 0;
  pbVar8[0x524] = 0;
  pbVar8[0x525] = 0;
  pbVar8[0x526] = 0;
  pbVar8[0x527] = 0;
  pbVar8[0x534] = 0;
  pbVar8[0x54d] = 0;
  pbVar8[0x54e] = 0;
  pbVar8[0x54f] = 0;
  pbVar8[0x550] = 0;
  pbVar8[0x551] = 0;
  pbVar8[0x552] = 0;
  pbVar8[0x553] = 0;
  pbVar8[0x554] = 0;
  pbVar8[0x555] = 0;
  pbVar8[0x556] = 0;
  pbVar8[0x557] = 0;
  pbVar8[0x558] = 0;
  pbVar8[0x559] = 0;
  pbVar8[0x560] = 0;
  pbVar8[0x561] = 0;
  pbVar8[0x562] = 0;
  pbVar8[0x563] = 0;
  pbVar8[0x564] = 0;
  pbVar8[0x565] = 0;
  pbVar8[0x566] = 0;
  pbVar8[0x567] = 0;
  pbVar8[0x568] = 0;
  pbVar8[0x569] = 0;
  pbVar8[0x56c] = 0;
  pbVar8[0x56d] = 0;
  pbVar8[0x56e] = 0;
  pbVar8[0x56f] = 0;
  *(longlong *)(pbVar8 + 0x500) = lVar7;
  *(undefined4 *)(pbVar8 + 0x548) = *(undefined4 *)(lVar7 + 0x10);
  pbVar8[0x51b] = *(byte *)(param_1 + 0x21ea);
  if ((*(char *)(param_1 + 0x21ea) != '\0') || (bVar3 = 0, *(char *)(param_1 + 0x21eb) != '\0')) {
    bVar3 = 1;
  }
  pbVar8[0x51a] = bVar3;
  if (*(char *)(param_1 + 0x21ea) == '\0') {
    bVar3 = (-(bVar3 != 0) & 4U) + 8;
  }
  else {
    bVar3 = (-(bVar3 != 0) & 4U) + 0xc;
  }
  pbVar8[0x535] = bVar3;
  if (*(char *)(lVar7 + 5) == '\x01') {
    bVar3 = *(byte *)(lVar7 + 6);
    uVar6 = 0;
    if ((*(byte *)(param_1 + 0x21f1) <= bVar3) && (bVar3 < 0x40)) {
      bVar2 = *(byte *)(lVar7 + 0x48);
      uVar6 = (ulonglong)bVar2;
      if ((bVar2 != 0xa0) && (bVar2 != 0x12)) {
        *(byte *)(param_1 + 0x21f1) = bVar3 + 1;
      }
    }
    if ((*(char *)(lVar7 + 6) == '@') && (*(char *)(lVar7 + 7) == '\0')) {
      puVar5 = (undefined1 *)FUN_1c0003da4(uVar6,lVar7);
      goto LAB_1c0003aaf;
    }
    puVar5 = (undefined1 *)0x0;
    if ((*(char *)(lVar7 + 0x48) == '5') || (*(char *)(lVar7 + 0x48) == -0x6f)) goto LAB_1c0003aaf;
  }
  if (*(char *)(param_1 + 0x76e9) != '\0') {
    local_34 = 0x10;
    iVar4 = StorPortExtendedFunction(0xf,param_1,lVar7,local_38);
    if (iVar4 == 0) {
      bVar3 = (byte)((ulonglong)local_30 %
                    (ulonglong)(longlong)(int)(uint)*(byte *)(param_1 + 0x76ea));
      goto LAB_1c0003ce9;
    }
  }
  bVar3 = 0;
LAB_1c0003ce9:
  pbVar8[0x50c] = bVar3;
  if (*(char *)(param_2 + 5) == '\x01') {
    pbVar8[0x518] = (*(char *)(param_2 + 0x48) - 8U & 0x5f) == 0;
    pbVar8[0x519] = (*(char *)(param_2 + 0x48) - 10U & 0x5f) == 0;
  }
  pbVar8[0x54c] = *(byte *)(param_2 + 10);
  if (*(char *)(param_1 + 0x7be0) == '\0') {
    if ((pbVar8[0x518] == 0) && (pbVar8[0x519] == 0)) {
      uVar6 = MFI_BuildFrame_NonRW(param_1,pbVar8);
    }
    else {
      uVar6 = MFI_BuildFrame_RW(param_1,pbVar8);
    }
  }
  else {
    uVar6 = MPT_BuildCmd_Scsi(param_1,pbVar8);
  }
  if ((char)uVar6 == '\0') {
    return uVar6;
  }
  if ((pbVar8[0x518] == 0) && (pbVar8[0x519] == 0)) {
    return uVar6;
  }
  if (0x3f < *(byte *)(param_2 + 6)) {
    return uVar6;
  }
  if (*(char *)(param_1 + 0x88) == '\0') {
    pbVar8[0x54d] = 1;
    return uVar6;
  }
  return uVar6;
}



===== FUN_1c0003da4 @ 1c0003da4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1c0003da4(undefined8 param_1,longlong param_2)

{
  undefined1 auStack_a8 [32];
  byte local_88 [8];
  undefined8 local_80;
  char local_78 [16];
  undefined8 local_68 [10];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  if (*(char *)(param_2 + 0x48) == '\x12') {
    MemFastZero(*(void **)(param_2 + 0x18),(ulonglong)*(uint *)(param_2 + 0x10));
    MemFastZero(local_88,0x68);
    if ((*(byte *)(param_2 + 0x49) & 1) == 0) {
      local_88[0] = local_88[0] | 0x1f;
      MemFastMove(&local_80,(undefined8 *)s_RAID_1c000c510,8);
      builtin_strncpy(local_78," DummyDevice    ",0x10);
      MemFastMove(local_68,(undefined8 *)&s_0001,4);
      if (*(uint *)(param_2 + 0x10) < 0x68) {
        MemFastMove(*(undefined8 **)(param_2 + 0x18),(undefined8 *)local_88,
                    *(uint *)(param_2 + 0x10));
      }
      else {
        MemFastMove(*(undefined8 **)(param_2 + 0x18),(undefined8 *)local_88,0x68);
        *(undefined4 *)(param_2 + 0x10) = 0x68;
      }
    }
    else {
      *(undefined1 *)(param_2 + 3) = 6;
    }
  }
  else {
    *(undefined1 *)(param_2 + 3) = 6;
  }
  return;
}



===== BuildSGLforSRB @ 1c0003e7c =====

longlong BuildSGLforSRB(longlong param_1,longlong param_2)

{
  uint uVar1;
  uint *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  
  puVar2 = (uint *)StorPortGetScatterGatherList(param_1,*(undefined8 *)(param_2 + 0x500));
  uVar1 = *puVar2;
  uVar3 = (ulonglong)uVar1;
  if (*(uint *)(param_1 + 0x66b4) < *(byte *)(param_2 + 0x534) + uVar1) {
    lVar4 = (ulonglong)(uint3)(uVar1 >> 8) << 8;
  }
  else {
    uVar5 = 0;
    if (uVar1 != 0) {
      do {
        uVar3 = (ulonglong)uVar5;
        if (*(char *)(param_1 + 0x7be0) == '\0') {
          if (*(char *)(param_2 + 0x51b) != '\0') {
            **(undefined8 **)(param_2 + 0x540) = *(undefined8 *)(puVar2 + uVar3 * 6 + 4);
            *(uint *)(*(longlong *)(param_2 + 0x540) + 8) = puVar2[uVar3 * 6 + 6];
            uVar3 = *(ulonglong *)(param_2 + 0x540);
            *(undefined4 *)(uVar3 + 0xc) = 0;
            goto LAB_1c0003f4c;
          }
          if (*(char *)(param_2 + 0x51a) == '\0') {
            **(uint **)(param_2 + 0x540) = puVar2[uVar3 * 6 + 4];
            *(uint *)(*(longlong *)(param_2 + 0x540) + 4) = puVar2[uVar3 * 6 + 6];
            *(longlong *)(param_2 + 0x540) = *(longlong *)(param_2 + 0x540) + 8;
          }
          else {
            **(uint **)(param_2 + 0x540) = puVar2[uVar3 * 6 + 4];
            *(uint *)(*(longlong *)(param_2 + 0x540) + 4) = puVar2[uVar3 * 6 + 5];
            lVar4 = uVar3 * 6;
            uVar3 = (ulonglong)puVar2[lVar4 + 6];
            *(uint *)(*(longlong *)(param_2 + 0x540) + 8) = puVar2[lVar4 + 6];
            *(longlong *)(param_2 + 0x540) = *(longlong *)(param_2 + 0x540) + 0xc;
          }
        }
        else {
          **(undefined8 **)(param_2 + 0x540) = *(undefined8 *)(puVar2 + uVar3 * 6 + 4);
          *(uint *)(*(longlong *)(param_2 + 0x540) + 8) = puVar2[uVar3 * 6 + 6];
          *(undefined1 *)(*(longlong *)(param_2 + 0x540) + 0xf) = 0;
          *(undefined1 *)(*(longlong *)(param_2 + 0x540) + 0xe) = 0;
          uVar3 = *(ulonglong *)(param_2 + 0x540);
          *(undefined2 *)(uVar3 + 0xc) = 0;
LAB_1c0003f4c:
          *(longlong *)(param_2 + 0x540) = *(longlong *)(param_2 + 0x540) + 0x10;
        }
        *(char *)(param_2 + 0x534) = *(char *)(param_2 + 0x534) + '\x01';
        uVar5 = uVar5 + 1;
      } while (uVar5 < *puVar2);
    }
    lVar4 = CONCAT71((int7)(uVar3 >> 8),1);
  }
  return lVar4;
}



===== BuildSGLforIOCTL @ 1c0003fe4 =====

undefined8 BuildSGLforIOCTL(longlong param_1,longlong param_2,longlong param_3,uint param_4)

{
  char cVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint local_res8 [2];
  
  uVar2 = *(undefined8 *)(param_2 + 0x500);
  local_res8[0] = 0;
  do {
    if (*(uint *)(param_1 + 0x66b8) < (uint)*(byte *)(param_2 + 0x534)) {
      return 0;
    }
    uVar3 = StorPortGetPhysicalAddress(param_1,uVar2,param_3,local_res8);
    if (param_4 < local_res8[0]) {
      local_res8[0] = param_4;
    }
    cVar1 = *(char *)(param_2 + 0x51a);
    **(undefined4 **)(param_2 + 0x540) = (int)uVar3;
    if (cVar1 == '\0') {
      *(uint *)(*(longlong *)(param_2 + 0x540) + 4) = local_res8[0];
      *(longlong *)(param_2 + 0x540) = *(longlong *)(param_2 + 0x540) + 8;
    }
    else {
      *(int *)(*(longlong *)(param_2 + 0x540) + 4) = (int)(uVar3 >> 0x20);
      uVar3 = (ulonglong)local_res8[0];
      *(uint *)(*(longlong *)(param_2 + 0x540) + 8) = local_res8[0];
      *(longlong *)(param_2 + 0x540) = *(longlong *)(param_2 + 0x540) + 0xc;
    }
    *(char *)(param_2 + 0x534) = *(char *)(param_2 + 0x534) + '\x01';
    param_3 = param_3 + (ulonglong)local_res8[0];
    param_4 = param_4 - local_res8[0];
  } while (param_4 != 0);
  return CONCAT71((int7)(uVar3 >> 8),1);
}



===== MegaSASStartIo @ 1c00040c0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 MegaSASStartIo(longlong param_1,longlong param_2,undefined8 param_3)

{
  char cVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong *plVar6;
  char local_res8 [8];
  
  uVar5 = *(longlong *)(param_2 + 0x38) + (ulonglong)*(ushort *)(param_1 + 0x21e8) &
          (longlong)(int)~(uint)*(ushort *)(param_1 + 0x21e8);
  if (*(char *)(param_1 + 0x8510) == '\x01') {
    SetDeviceQueueDepths(param_1);
    *(undefined1 *)(param_1 + 0x8510) = 0;
  }
  lVar4 = param_1;
  uVar2 = CheckForValidIO(param_1,param_2,param_3);
  if ((char)uVar2 != '\0') {
    if (*(char *)(param_2 + 2) == '$') {
      if (*(int *)(param_2 + 0x40) - 4U < 3) {
        *(undefined1 *)(param_1 + 0x21ef) = 1;
      }
      if (*(int *)(param_2 + 8) == 4) {
        *(undefined1 *)(param_1 + 0x7bbe) = 1;
        (**(code **)(*(longlong *)(param_1 + 0x188) + 0x28))();
        *(undefined4 *)(param_1 + 0x8a18) = 1;
        *(longlong *)(param_1 + 0x8a30) = param_2;
        uVar2 = WatchDogTimer(param_1);
        goto LAB_1c000429a;
      }
    }
    if (((*(byte *)(param_2 + 2) & 0xf5) == 0) && (*(byte *)(param_2 + 2) != 10)) {
      if ((*(char *)(uVar5 + 0x54d) == '\0') || (*(uint *)(param_1 + 0x76e0) < 2)) {
LAB_1c0004237:
        lVar4 = *(longlong *)(param_1 + 0x2198);
        if (lVar4 != 0) {
          *(undefined8 *)(param_1 + 0x2198) = 0;
          uVar3 = FUN_1c00042b4(param_1,lVar4);
          if ((char)uVar3 == '\0') {
            *(longlong *)(param_1 + 0x2198) = lVar4;
          }
        }
        if (*(char *)(param_1 + 0x76e8) != '\0') {
          TryFlushingGroups(param_1);
        }
        uVar2 = FUN_1c00042b4(param_1,uVar5);
        if ((char)uVar2 != '\0') goto LAB_1c000429a;
      }
      else {
        plVar6 = (longlong *)(param_1 + 0x66e0 + (ulonglong)*(byte *)(param_2 + 6) * 0x40);
        local_res8[0] = '\0';
        if (((*(char *)((longlong)plVar6 + 0x11) == '\0') || (*plVar6 == 0)) ||
           (uVar3 = FUN_1c00042b4(lVar4,*plVar6), (char)uVar3 != '\0')) {
          uVar2 = FUN_1c0004484(param_1,uVar5,plVar6,local_res8);
          if ((char)uVar2 != '\0') goto LAB_1c000429a;
          if (*plVar6 != 0) {
            cVar1 = *(char *)(uVar5 + 0x54e);
            *(undefined1 *)((longlong)plVar6 + 0x11) = 1;
            uVar2 = FUN_1c00042b4(param_1,*plVar6);
            if (cVar1 != '\0') goto LAB_1c000429a;
            if ((char)uVar2 == '\0') goto LAB_1c00041c8;
            if ((local_res8[0] != '\0') &&
               (uVar2 = FUN_1c0004484(param_1,uVar5,plVar6,local_res8), (char)uVar2 != '\0'))
            goto LAB_1c000429a;
          }
          goto LAB_1c0004237;
        }
      }
LAB_1c00041c8:
      uVar2 = FUN_1c0004438(param_1,uVar5);
      goto LAB_1c000429a;
    }
    *(undefined2 *)(param_2 + 3) = 1;
  }
  uVar2 = StorPortNotification(0,param_1,param_2);
LAB_1c000429a:
  return CONCAT71((int7)(uVar2 >> 8),1);
}



===== FUN_1c00042b4 @ 1c00042b4 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong FUN_1c00042b4(longlong param_1,longlong param_2)

{
  int *piVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)*(uint *)(param_1 + 0x21c0);
  if (((*(uint *)(param_1 + 0x21c0) < *(uint *)(param_1 + 0x66c0)) &&
      (*(char *)(param_1 + 0x7bbc) == '\0')) && (*(char *)(param_1 + 0x7bbd) == '\0')) {
    if (*(char *)(param_2 + 0x54d) != '\0') {
      lVar3 = (ulonglong)*(byte *)(*(longlong *)(param_2 + 0x500) + 6) * 0x40;
      LOCK();
      piVar1 = (int *)(lVar3 + 0x6700 + param_1);
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      if (*(char *)(param_2 + 0x54e) != '\0') {
        *(undefined8 *)(lVar3 + 0x66e8 + param_1) = 0;
        *(undefined8 *)(lVar3 + 0x66e0 + param_1) = 0;
        *(undefined1 *)(lVar3 + 0x66f1 + param_1) = 0;
      }
    }
    uVar2 = *(uint *)(param_1 + 0x2190);
    do {
      if (*(longlong *)(param_1 + 400 + (ulonglong)uVar2 * 8) == 0) {
        *(longlong *)(param_1 + 400 + (ulonglong)uVar2 * 8) = param_2;
        *(uint *)(param_2 + 0x508) = uVar2;
        LOCK();
        *(int *)(param_1 + 0x21c0) = *(int *)(param_1 + 0x21c0) + 1;
        UNLOCK();
        uVar4 = (**(code **)(*(longlong *)(param_1 + 0x188) + 8))(param_1,param_2);
        goto LAB_1c00043b5;
      }
      uVar2 = -(uint)(uVar2 + 1 < *(uint *)(param_1 + 0x66c0)) & uVar2 + 1;
    } while (uVar2 != *(uint *)(param_1 + 0x2190));
    uVar4 = SetDeadAdapter(param_1,0x20);
  }
  else if ((*(char *)(*(longlong *)(param_2 + 0x500) + 2) == '\x02') &&
          (*(longlong *)(param_1 + 0x2198) == 0)) {
    *(longlong *)(param_1 + 0x2198) = param_2;
LAB_1c00043b5:
    return CONCAT71((int7)(uVar4 >> 8),1);
  }
  return uVar4 & 0xffffffffffffff00;
}



===== TryFlushingGroups @ 1c00043bc =====

void TryFlushingGroups(longlong param_1)

{
  longlong lVar1;
  byte bVar2;
  undefined8 uVar3;
  
  bVar2 = *(byte *)(param_1 + 0x66c4);
  while (((*(char *)((ulonglong)bVar2 * 0x40 + 0x66f1 + param_1) == '\0' ||
          (lVar1 = *(longlong *)((ulonglong)bVar2 * 0x40 + 0x66e0 + param_1), lVar1 == 0)) ||
         (uVar3 = FUN_1c00042b4(param_1,lVar1), (char)uVar3 != '\0'))) {
    bVar2 = -((byte)(bVar2 + 1) < *(byte *)(param_1 + 0x21f1)) & bVar2 + 1;
    if (bVar2 == *(byte *)(param_1 + 0x66c4)) {
      *(undefined1 *)(param_1 + 0x76e8) = 0;
      *(undefined1 *)(param_1 + 0x66c4) = 0;
      return;
    }
  }
  *(byte *)(param_1 + 0x66c4) = bVar2;
  return;
}



===== FUN_1c0004438 @ 1c0004438 =====

void FUN_1c0004438(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_2 + 0x500);
  if (*(char *)(param_1 + 0x91) == '\0') {
    StorPortBusy(param_1,*(undefined4 *)(param_1 + 0x21a0));
  }
  else {
    *(undefined1 *)(lVar1 + 4) = 0x28;
  }
  *(undefined1 *)(lVar1 + 3) = 5;
                    /* WARNING: Could not recover jumptable at 0x0001c000447d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortNotification(0,param_1,lVar1);
  return;
}



===== FUN_1c0004484 @ 1c0004484 =====

ulonglong FUN_1c0004484(longlong param_1,longlong param_2,longlong *param_3,undefined8 param_4)

{
  longlong lVar1;
  bool bVar2;
  ulonglong uVar3;
  
  lVar1 = *param_3;
  bVar2 = true;
  if (((param_3[5] != *(longlong *)(param_2 + 0x520)) ||
      (*(uint *)(param_3 + 4) < *(uint *)(param_1 + 0x76e4))) ||
     (0xffff < (uint)(*(int *)(param_2 + 0x530) << 9))) {
    bVar2 = false;
  }
  if (lVar1 == 0) {
    uVar3 = (ulonglong)*(uint *)(param_2 + 0x530) + *(longlong *)(param_2 + 0x520);
    param_3[5] = uVar3;
    if (bVar2) {
      *(undefined1 *)(param_2 + 0x54e) = 1;
      param_3[1] = param_2;
      *param_3 = param_2;
      *(undefined1 *)(param_2 + 0x54f) = 1;
      *(undefined1 *)(param_3 + 2) = 1;
LAB_1c0004635:
      return CONCAT71((int7)(uVar3 >> 8),1);
    }
  }
  else if (((bVar2) &&
           ((uint)*(byte *)(lVar1 + 0x534) + (uint)*(byte *)(param_2 + 0x534) <=
            (uint)*(byte *)(param_1 + 0x66b4))) &&
          ((*(char *)(*(longlong *)(param_2 + 0x500) + 0x48) ==
            *(char *)(*(longlong *)(lVar1 + 0x500) + 0x48) &&
           ((*(char *)(lVar1 + 0x50c) == *(char *)(param_2 + 0x50c) &&
            ((uint)((*(int *)(param_2 + 0x530) + *(int *)(lVar1 + 0x530)) * 0x200) < 0x10000)))))) {
    *(longlong *)(param_3[1] + 0x550) = param_2;
    *(char *)(param_3 + 2) = (char)param_3[2] + '\x01';
    param_3[1] = param_2;
    MemFastMove(*(undefined8 **)(lVar1 + 0x540),*(undefined8 **)(param_2 + 0x538),
                (uint)*(byte *)(param_2 + 0x535) * (uint)*(byte *)(param_2 + 0x534));
    *(longlong *)(lVar1 + 0x540) =
         *(longlong *)(lVar1 + 0x540) +
         (longlong)(int)((uint)*(byte *)(param_2 + 0x534) * (uint)*(byte *)(param_2 + 0x535));
    *(int *)(lVar1 + 0x530) = *(int *)(lVar1 + 0x530) + *(int *)(param_2 + 0x530);
    *(char *)(lVar1 + 0x534) = *(char *)(lVar1 + 0x534) + *(char *)(param_2 + 0x534);
    *(char *)(lVar1 + 0x54f) = *(char *)(lVar1 + 0x54f) + '\x01';
    *(undefined1 *)(param_2 + 0x54e) = 1;
    uVar3 = 0;
    if (((uint)*(byte *)(lVar1 + 0x54f) < *(uint *)(param_1 + 0x76e0)) &&
       (uVar3 = 0, (uint)*(byte *)(lVar1 + 0x534) < *(uint *)(param_1 + 0x66b4))) {
      uVar3 = (ulonglong)*(uint *)(param_2 + 0x530) + *(longlong *)(param_2 + 0x520);
      param_3[5] = uVar3;
      goto LAB_1c0004635;
    }
  }
  else {
    lVar1 = *(longlong *)(param_2 + 0x520);
    uVar3 = CONCAT71((int7)((ulonglong)lVar1 >> 8),param_3[5] == lVar1);
    *(bool *)param_4 = param_3[5] == lVar1;
  }
  return uVar3 & 0xffffffffffffff00;
}



===== CheckForValidIO @ 1c000464c =====

ulonglong CheckForValidIO(longlong param_1,longlong param_2,undefined8 param_3)

{
  byte bVar1;
  char cVar2;
  uint uVar3;
  ulonglong in_RAX;
  
  if (*(char *)(param_1 + 0x7bbf) == '\0') {
    bVar1 = *(byte *)(param_2 + 6);
    in_RAX = CONCAT71((int7)(in_RAX >> 8),bVar1);
    if (((bVar1 == 0xff) || (*(char *)(param_2 + 7) != '\0')) ||
       ((*(char *)(param_2 + 5) == '\0' &&
        ((*(char *)(param_2 + 2) == '\0' &&
         (in_RAX = (ulonglong)bVar1, *(char *)(in_RAX + 0x21f2 + param_1) == '\0')))))) {
      *(undefined1 *)(param_2 + 3) = 0x20;
    }
    else {
      if ((*(char *)(param_1 + 0x7bbc) == '\0') && (*(char *)(param_1 + 0x7bbd) == '\0')) {
LAB_1c00046bd:
        return CONCAT71((int7)(in_RAX >> 8),1);
      }
      cVar2 = *(char *)(param_2 + 2);
      if (cVar2 == '\x02') {
        if (*(longlong *)(param_1 + 0x2198) == 0) goto LAB_1c00046bd;
      }
      else {
        uVar3 = (int)CONCAT71((int7)((ulonglong)param_3 >> 8),cVar2) - 0x12;
        in_RAX = (ulonglong)uVar3;
        if (((byte)uVar3 < 2) || (cVar2 == ' ')) {
          *(undefined1 *)(param_2 + 3) = 6;
          goto LAB_1c00046ca;
        }
      }
      *(undefined1 *)(param_2 + 3) = 5;
    }
  }
  else {
    *(undefined1 *)(param_2 + 3) = 0x11;
  }
LAB_1c00046ca:
  return in_RAX & 0xffffffffffffff00;
}



===== WatchDogTimer @ 1c00046d0 =====

void WatchDogTimer(longlong param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = *(int *)(param_1 + 0x8a18);
  if (iVar1 == 0) {
    StorPortNotification(6,param_1,WatchDogTimer);
    return;
  }
  if (iVar1 == 1) {
    pcVar2 = SyncronizeProcessShutdown;
  }
  else {
    if (iVar1 != 2) {
      return;
    }
    pcVar2 = SyncronizeInitializeAdapter;
  }
                    /* WARNING: Could not recover jumptable at 0x0001c00046ff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  StorPortSynchronizeAccess(param_1,pcVar2,0);
  return;
}



===== SyncronizeProcessShutdown @ 1c0004730 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SyncronizeProcessShutdown(longlong param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  ulonglong in_RAX;
  undefined1 *puVar4;
  
  while( true ) {
    iVar2 = *(int *)(param_1 + 0x8a1c);
    if (5 < iVar2) break;
    if (iVar2 == 5) {
      puVar4 = SetupDCMD(param_1,0x1101000);
      *(ushort *)(puVar4 + 0x10) = *(ushort *)(puVar4 + 0x10) | 1;
      *(undefined2 *)(puVar4 + 0x12) = 0x3c;
      *(undefined4 *)(param_1 + 0x8a1c) = 6;
      *(undefined4 *)(param_1 + 0x8a20) = 7;
LAB_1c0004920:
      *(undefined4 *)(param_1 + 0x7bcc) = 30000000;
LAB_1c000492a:
      in_RAX = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x58))(param_1);
    }
    else {
      if (iVar2 < 0) goto LAB_1c00049e7;
      if (iVar2 < 2) {
        if (*(char *)(param_1 + 0x7be3) != '\0') {
          PrepareAbortFrame(param_1,3);
          *(undefined4 *)(param_1 + 0x8a1c) = 2;
          *(undefined4 *)(param_1 + 0x8a20) = 3;
          goto LAB_1c000492a;
        }
        *(undefined4 *)(param_1 + 0x8a1c) = 3;
      }
      else if (iVar2 == 2) {
LAB_1c0004791:
        cVar1 = *(char *)(*(longlong *)(param_1 + 0xd8) + 2);
        if (cVar1 == -1) {
          uVar3 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x30))
                            (*(undefined8 *)(param_1 + 0x80));
          *(uint *)(param_1 + 0x21c4) = uVar3;
          if ((uVar3 & 0xf0000000) == 0xf0000000) {
            in_RAX = StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x13);
            goto LAB_1c00047eb;
          }
          if (0 < *(int *)(param_1 + 0x7bcc)) {
            *(int *)(param_1 + 0x7bcc) = *(int *)(param_1 + 0x7bcc) + -10000;
            in_RAX = StorPortNotification(6,param_1,WatchDogTimer,10000);
LAB_1c00049e7:
            return CONCAT71((int7)(in_RAX >> 8),1);
          }
          StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x13);
        }
        else {
          if (cVar1 != '\0') {
            StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x13);
          }
          if (*(int *)(param_1 + 0x8a1c) == 2) {
            *(undefined1 *)(param_1 + 0x7be3) = 0;
          }
          if (*(int *)(param_1 + 0x8a1c) == 4) {
            *(undefined1 *)(param_1 + 0x21ee) = 0;
          }
        }
        in_RAX = (ulonglong)*(uint *)(param_1 + 0x8a20);
        *(uint *)(param_1 + 0x8a1c) = *(uint *)(param_1 + 0x8a20);
      }
      else {
        if (iVar2 != 3) {
          if (iVar2 == 4) goto LAB_1c0004791;
          goto LAB_1c00049e7;
        }
        if (*(char *)(param_1 + 0x21ee) != '\0') {
          PrepareAbortFrame(param_1,2);
          *(undefined4 *)(param_1 + 0x8a1c) = 4;
          *(undefined4 *)(param_1 + 0x8a20) = 5;
          goto LAB_1c000492a;
        }
LAB_1c00047eb:
        *(undefined4 *)(param_1 + 0x8a1c) = 9;
      }
    }
  }
  if (iVar2 == 6) goto LAB_1c0004791;
  if (iVar2 == 7) {
    puVar4 = SetupDCMD(param_1,(-(uint)(*(char *)(param_1 + 0x21ef) != '\0') & 0xffff0000) +
                               0x1060000);
    *(ushort *)(puVar4 + 0x10) = *(ushort *)(puVar4 + 0x10) | 1;
    *(undefined2 *)(puVar4 + 0x12) = 0x3c;
    *(undefined4 *)(param_1 + 0x8a1c) = 8;
    *(undefined4 *)(param_1 + 0x8a20) = 9;
    goto LAB_1c0004920;
  }
  if (iVar2 != 8) {
    if (iVar2 == 9) {
      *(undefined2 *)(param_1 + 0x7bd0) = 0;
      *(undefined2 *)(*(longlong *)(param_1 + 0x8a30) + 3) = 1;
      in_RAX = StorPortNotification(0,param_1);
    }
    goto LAB_1c00049e7;
  }
  goto LAB_1c0004791;
}



===== MFI_InitializeQueue @ 1c0004a00 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

bool MFI_InitializeQueue(longlong param_1,undefined1 *param_2,uint *param_3)

{
  undefined1 uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined1 local_res8 [8];
  
  MemFastZero(param_2,0x40);
  MemFastZero(param_3,0x40);
  uVar2 = *(uint *)(param_1 + 0x66bc);
  *param_3 = *param_3 & 0xfffffffd;
  param_3[1] = uVar2;
  uVar3 = StorPortGetPhysicalAddress
                    (param_1,0,
                     *(undefined8 *)
                      (*(longlong *)(param_1 + 0x7bd8) + 8 +
                      (ulonglong)*(byte *)(param_1 + 0x7bd4) * 0x10),local_res8);
  if (0 < (int)((ulonglong)uVar3 >> 0x20)) {
    *param_3 = *param_3 | 1;
  }
  *(undefined8 *)(param_3 + 2) = uVar3;
  uVar3 = StorPortGetPhysicalAddress
                    (param_1,0,
                     (ulonglong)*(byte *)(param_1 + 0x7bd4) * 0x10 + *(longlong *)(param_1 + 0x7bd8)
                     ,local_res8);
  if (0 < (int)((ulonglong)uVar3 >> 0x20)) {
    *param_3 = *param_3 | 1;
  }
  *(undefined8 *)(param_3 + 4) = uVar3;
  uVar3 = StorPortGetPhysicalAddress
                    (param_1,0,
                     *(longlong *)(param_1 + 0x7bd8) + 4 +
                     (ulonglong)*(byte *)(param_1 + 0x7bd4) * 0x10,local_res8);
  if (0 < (int)((ulonglong)uVar3 >> 0x20)) {
    *param_3 = *param_3 | 1;
  }
  *(undefined8 *)(param_3 + 6) = uVar3;
  uVar3 = StorPortGetPhysicalAddress(param_1,0,param_3,local_res8);
  *(undefined8 *)(param_2 + 0x18) = uVar3;
  uVar3 = StorPortGetPhysicalAddress(param_1,0,*(undefined8 *)(param_1 + 0xd0),local_res8);
  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 1;
  *(undefined8 *)(param_2 + 0x28) = uVar3;
  *param_2 = 0;
  *(undefined4 *)(param_2 + 0x14) = 0x40;
  param_2[3] = *(undefined1 *)(param_1 + 0x7bd4);
  uVar1 = *(undefined1 *)(param_1 + 0x7bd4);
  *(ushort *)(param_2 + 0x10) = *(ushort *)(param_2 + 0x10) | 1;
  param_2[0xd] = uVar1;
  param_2[2] = 0xff;
  uVar3 = StorPortGetPhysicalAddress(param_1,0,param_2,local_res8);
  (**(code **)(*(longlong *)(param_1 + 0x188) + 0x60))(param_1,uVar3,0);
  *(char *)(param_1 + 0x7bd4) = *(char *)(param_1 + 0x7bd4) + '\x01';
  return *(byte *)(param_1 + 0x76ea) <= *(byte *)(param_1 + 0x7bd4);
}



===== MFI_BuildFrame_NonRW @ 1c0004ba8 =====

longlong MFI_BuildFrame_NonRW(longlong param_1,byte *param_2)

{
  ushort uVar1;
  longlong lVar2;
  ushort uVar3;
  longlong lVar4;
  undefined8 uVar5;
  byte bVar6;
  uint uVar7;
  undefined1 local_res10 [8];
  
  lVar2 = *(longlong *)(param_2 + 0x500);
  param_2[0x558] = 1;
  param_2[8] = 0;
  param_2[9] = 0;
  param_2[10] = 0;
  param_2[0xb] = 0;
  param_2[0xc] = 0;
  param_2[0xd] = 0;
  param_2[0xe] = 0;
  param_2[0xf] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[0x10] = 0;
  param_2[0x11] = 0;
  param_2[0x18] = 0;
  param_2[0x19] = 0;
  param_2[0x1a] = 0;
  param_2[0x1b] = 0;
  param_2[0x1c] = 0;
  param_2[0x1d] = 0;
  param_2[0x1e] = 0;
  param_2[0x1f] = 0;
  param_2[8] = 0;
  param_2[9] = 0;
  param_2[10] = 0;
  param_2[0xb] = 0;
  param_2[3] = 0;
  if (*(char *)(lVar2 + 5) == '\0') {
    *param_2 = 4;
    param_2[5] = *(byte *)(lVar2 + 7);
  }
  else {
    *param_2 = 3;
    param_2[5] = 0;
  }
  param_2[4] = *(byte *)(lVar2 + 6);
  if ((*(uint *)(lVar2 + 0xc) & 0xc0) == 0) {
    param_2[0x10] = 0;
    param_2[0x11] = 0;
  }
  if ((char)*(undefined4 *)(lVar2 + 0xc) < '\0') {
    param_2[0x10] = 8;
    param_2[0x11] = 0;
  }
  if ((*(uint *)(lVar2 + 0xc) & 0x40) != 0) {
    *(ushort *)(param_2 + 0x10) = *(ushort *)(param_2 + 0x10) | 0x10;
  }
  *(byte **)(param_2 + 0x540) = param_2 + 0x30;
  *(byte **)(param_2 + 0x538) = param_2 + 0x30;
  if ((*(int *)(lVar2 + 0x10) != 0) &&
     (lVar4 = BuildSGLforSRB(param_1,(longlong)param_2), (char)lVar4 == '\0')) {
    *(undefined1 *)(lVar2 + 3) = 4;
    return lVar4;
  }
  param_2[7] = param_2[0x534];
  if (param_2[0x534] != 0) {
    uVar7 = *(int *)(&DAT_1c000b230 + (ulonglong)*param_2 * 4) +
            (uint)param_2[0x535] * (uint)param_2[0x534] + 0x3f >> 6;
    bVar6 = 7;
    if ((int)((uVar7 & 0xff) - 1) < 7) {
      bVar6 = (char)uVar7 - 1;
    }
    param_2[0x559] = bVar6;
  }
  param_2[6] = param_2[0x54c];
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(lVar2 + 0x10);
  uVar1 = *(ushort *)(param_2 + 0x10);
  uVar3 = (ushort)(param_2[0x51a] & 1) * 2;
  *(ushort *)(param_2 + 0x10) = uVar3 | uVar1 & 0xfffd;
  *(ushort *)(param_2 + 0x10) =
       (ushort)(*(byte *)(param_1 + 0x21ea) & 1) << 5 | uVar3 | uVar1 & 0xffdd;
  *(undefined2 *)(param_2 + 0x12) = *(undefined2 *)(lVar2 + 0x14);
  MemFastMove((undefined8 *)(param_2 + 0x20),(undefined8 *)(lVar2 + 0x48),(uint)param_2[0x54c]);
  uVar5 = StorPortGetPhysicalAddress(param_1,0,param_2,local_res10);
  *(undefined8 *)(param_2 + 0x510) = uVar5;
  return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
}



===== MFI_BuildFrame_RW @ 1c0004d48 =====

longlong MFI_BuildFrame_RW(longlong param_1,byte *param_2)

{
  ushort uVar1;
  longlong lVar2;
  ushort uVar3;
  longlong lVar4;
  undefined8 uVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  undefined1 local_res10 [8];
  
  lVar2 = *(longlong *)(param_2 + 0x500);
  bVar7 = 0;
  param_2[0x558] = 1;
  param_2[8] = 0;
  param_2[9] = 0;
  param_2[10] = 0;
  param_2[0xb] = 0;
  param_2[0xc] = 0;
  param_2[0xd] = 0;
  param_2[0xe] = 0;
  param_2[0xf] = 0;
  param_2[8] = 0;
  param_2[9] = 0;
  param_2[10] = 0;
  param_2[0xb] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[0x10] = 0;
  param_2[0x11] = 0;
  param_2[0x18] = 0;
  param_2[0x19] = 0;
  param_2[0x1a] = 0;
  param_2[0x1b] = 0;
  param_2[0x1c] = 0;
  param_2[0x1d] = 0;
  param_2[0x1e] = 0;
  param_2[0x1f] = 0;
  param_2[3] = 0;
  *param_2 = 2 - (param_2[0x518] != 0);
  param_2[4] = *(byte *)(lVar2 + 6);
  if ((*(uint *)(lVar2 + 0xc) & 0xc0) == 0) {
    param_2[0x10] = 0;
    param_2[0x11] = 0;
  }
  if ((char)*(undefined4 *)(lVar2 + 0xc) < '\0') {
    param_2[0x10] = 8;
    param_2[0x11] = 0;
  }
  if ((*(uint *)(lVar2 + 0xc) & 0x40) != 0) {
    *(ushort *)(param_2 + 0x10) = *(ushort *)(param_2 + 0x10) | 0x10;
  }
  *(byte **)(param_2 + 0x540) = param_2 + 0x28;
  *(byte **)(param_2 + 0x538) = param_2 + 0x28;
  if ((*(int *)(lVar2 + 0x10) != 0) &&
     (lVar4 = BuildSGLforSRB(param_1,(longlong)param_2), (char)lVar4 == '\0')) {
    *(undefined1 *)(lVar2 + 3) = 4;
    return lVar4;
  }
  param_2[7] = param_2[0x534];
  if (param_2[0x534] != 0) {
    uVar8 = *(int *)(&DAT_1c000b230 + (ulonglong)*param_2 * 4) +
            (uint)param_2[0x535] * (uint)param_2[0x534] + 0x3f >> 6;
    bVar6 = 7;
    if ((int)((uVar8 & 0xff) - 1) < 7) {
      bVar6 = (char)uVar8 - 1;
    }
    param_2[0x559] = bVar6;
  }
  CDB_GetInfo(lVar2 + 0x48,param_2[0x54c],(ulonglong *)(param_2 + 0x520),(uint *)(param_2 + 0x530));
  *(ulonglong *)(param_2 + 0x20) = *(ulonglong *)(param_2 + 0x520);
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x530);
  uVar1 = *(ushort *)(param_2 + 0x10);
  uVar3 = (ushort)(param_2[0x51a] & 1) * 2;
  *(ushort *)(param_2 + 0x10) = uVar3 | uVar1 & 0xfffd;
  *(ushort *)(param_2 + 0x10) =
       (ushort)(*(byte *)(param_1 + 0x21ea) & 1) << 5 | uVar3 | uVar1 & 0xffdd;
  if (param_2[0x54c] != 6) {
    bVar7 = *(byte *)(lVar2 + 0x49);
  }
  param_2[5] = bVar7;
  *(undefined2 *)(param_2 + 0x12) = *(undefined2 *)(lVar2 + 0x14);
  uVar5 = StorPortGetPhysicalAddress(param_1,0,param_2,local_res10);
  *(undefined8 *)(param_2 + 0x510) = uVar5;
  return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
}



===== MFI_SendRequestToFW @ 1c0004f10 =====

void MFI_SendRequestToFW(longlong param_1,byte *param_2)

{
  longlong lVar1;
  byte bVar2;
  uint uVar3;
  
  lVar1 = *(longlong *)(param_2 + 0x500);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_2 + 0x508);
  if (*(char *)(param_1 + 0x21e6) == '\0') {
    param_2[3] = param_2[0x50c];
  }
  else {
    param_2[0xd] = param_2[0x50c];
  }
  if (*(char *)(lVar1 + 2) == '\0') {
    if (*(char *)(lVar1 + 0xb) != '\0') {
      if (0 < *(int *)(param_1 + 0x164)) {
        *(ushort *)(param_2 + 0x10) = *(ushort *)(param_2 + 0x10) | 4;
      }
      *(ulonglong *)(param_2 + 0x18) =
           *(longlong *)(param_1 + 0x160) + (ulonglong)*(uint *)(param_2 + 0x508) * 0x12;
      bVar2 = 0x12;
      if (*(byte *)(lVar1 + 0xb) < 0x12) {
        bVar2 = *(byte *)(lVar1 + 0xb);
      }
      param_2[1] = bVar2;
    }
    if (((param_2[0x54d] != 0) &&
        (UpdateIOMetric(param_1,*(byte *)(lVar1 + 6),param_2[0x518],*(ulonglong *)(param_2 + 0x20),
                        *(uint *)(param_2 + 0x14)), param_2[0x54e] != 0)) && (1 < param_2[0x54f])) {
      param_2[7] = param_2[0x534];
      *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_2 + 0x530);
      uVar3 = *(int *)(&DAT_1c000b230 + (ulonglong)*param_2 * 4) +
              (uint)param_2[0x535] * (uint)param_2[0x534] + 0x3f >> 6;
      bVar2 = 7;
      if ((int)((uVar3 & 0xff) - 1) < 7) {
        bVar2 = (char)uVar3 - 1;
      }
      param_2[0x559] = bVar2;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0001c000a040. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(longlong *)(param_1 + 0x188) + 0x50))(param_1,param_2);
  return;
}



===== MFI_CompleteRequests @ 1c0005050 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 MFI_CompleteRequests(longlong param_1,ulonglong param_2,undefined8 param_3)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  longlong lVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint *puVar9;
  
  puVar9 = (uint *)((param_2 & 0xffffffff) * 0x10 + *(longlong *)(param_1 + 0x7bd8));
  if (puVar9[1] == *puVar9) {
    (**(code **)(*(longlong *)(param_1 + 0x188) + 0x18))();
    uVar6 = CheckFirmwareFault(param_1,param_2,param_3);
    if ((char)uVar6 != '\0') {
LAB_1c00051a0:
      return uVar6 & 0xffffffffffffff00;
    }
  }
  else {
    do {
      uVar7 = puVar9[1] + 1;
      iVar3 = *(int *)(*(longlong *)(puVar9 + 2) + (ulonglong)puVar9[1] * 4);
      puVar9[1] = uVar7;
      puVar9[1] = -(uint)(uVar7 < *(uint *)(param_1 + 0x66bc)) & uVar7;
      if (0x3ff < iVar3) {
        uVar8 = 0x22;
LAB_1c0005198:
        uVar6 = SetDeadAdapter(param_1,uVar8);
        goto LAB_1c00051a0;
      }
      pcVar4 = *(char **)(param_1 + 400 + (longlong)iVar3 * 8);
      if (pcVar4 == (char *)0x0) {
        uVar8 = 6;
        goto LAB_1c0005198;
      }
      lVar5 = *(longlong *)(pcVar4 + 0x500);
      if (lVar5 != 0) {
        uVar7 = *(uint *)(pcVar4 + 0x508);
        if (*(char **)(param_1 + 400 + (ulonglong)uVar7 * 8) == pcVar4) {
          *(undefined8 *)(param_1 + 400 + (ulonglong)uVar7 * 8) = 0;
          *(uint *)(param_1 + 0x2190) = uVar7;
          LOCK();
          piVar1 = (int *)(param_1 + 0x21c0);
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (-1 < *piVar1) {
            cVar2 = *(char *)(lVar5 + 2);
            if (cVar2 == '\0') {
              *(undefined4 *)(pcVar4 + 0x548) = *(undefined4 *)(pcVar4 + 0x14);
              CompleteScsiRequest(param_1,(longlong)pcVar4,pcVar4[2],pcVar4[3]);
            }
            else if (cVar2 == '\b') {
              if (pcVar4[2] == '\0') {
                *(undefined2 *)(lVar5 + 3) = 1;
              }
              else {
                *(undefined1 *)(lVar5 + 3) = 4;
              }
              StorPortNotification(0,param_1);
            }
            else if (cVar2 == '\x02') {
              CompleteIoctlRequest(param_1,(undefined8 *)pcVar4);
            }
            goto LAB_1c000516b;
          }
          uVar8 = 0x25;
        }
        else {
          uVar8 = 0x21;
        }
        goto LAB_1c0005198;
      }
      if ((*pcVar4 != '\x05') || (*(uint *)(pcVar4 + 8) < *(uint *)(param_1 + 0x66c0))) {
        uVar8 = 7;
        goto LAB_1c0005198;
      }
      CompleteDCMD(param_1,(longlong)pcVar4,'\0');
LAB_1c000516b:
      uVar6 = (ulonglong)*puVar9;
    } while (puVar9[1] != *puVar9);
  }
  return CONCAT71((int7)(uVar6 >> 8),1);
}



===== MPT_InitMessageMem @ 1c00051d0 =====

undefined8 MPT_InitMessageMem(longlong param_1,longlong param_2,uint param_3)

{
  ushort uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined1 local_res18 [16];
  
  uVar1 = *(ushort *)(param_1 + 0x21e8);
  uVar5 = 0;
  uVar6 = (ulonglong)uVar1 + param_2 & (longlong)(int)~(uint)uVar1;
  *(ulonglong *)(param_1 + 0x8408) = uVar6;
  uVar6 = (ulonglong)(*(int *)(param_1 + 0x66bc) + 1) * 0x100 + (ulonglong)uVar1 + uVar6 &
          (longlong)(int)~(uint)uVar1;
  if (*(char *)(param_1 + 0x76ea) != '\0') {
    do {
      uVar2 = (ulonglong)uVar5;
      uVar4 = (ulonglong)uVar5;
      uVar5 = uVar5 + 1;
      *(ulonglong *)(param_1 + 0x8418 + uVar2 * 0x10) = uVar6;
      *(undefined2 *)(param_1 + (uVar4 + 0x841) * 0x10) = 0;
      uVar6 = uVar6 + (uint)(*(int *)(param_1 + 0x66bc) << 3);
    } while (uVar5 < *(byte *)(param_1 + 0x76ea));
  }
  if (*(char *)(param_1 + 0x7be2) != '\0') {
    uVar6 = uVar6 + *(ushort *)(param_1 + 0x21e8) &
            (longlong)(int)~(uint)*(ushort *)(param_1 + 0x21e8);
    *(ulonglong *)(param_1 + 0x7be8) = uVar6;
    uVar3 = StorPortGetPhysicalAddress(param_1,0,uVar6,local_res18);
    *(undefined8 *)(param_1 + 0x7bf8) = uVar3;
    uVar6 = (ulonglong)*(ushort *)(param_1 + 0x21e8) + 0x2a0a8 + uVar6 &
            (longlong)(int)~(uint)*(ushort *)(param_1 + 0x21e8);
    *(ulonglong *)(param_1 + 0x7bf0) = uVar6;
    uVar3 = StorPortGetPhysicalAddress(param_1,0,uVar6,local_res18);
    *(undefined8 *)(param_1 + 0x7c00) = uVar3;
    uVar6 = uVar6 + 0x2a0a8;
  }
  return CONCAT71((int7)((ulonglong)param_3 + param_2 >> 8),uVar6 <= (ulonglong)param_3 + param_2);
}



===== MPT_InitializeQueues @ 1c0005300 =====

undefined8 MPT_InitializeQueues(longlong param_1,undefined1 *param_2,undefined1 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 local_res8 [16];
  ulonglong local_res18;
  
  uVar5 = 0;
  if (*(char *)(param_1 + 0x76ea) != '\0') {
    do {
      uVar4 = 0;
      *(undefined2 *)(param_1 + ((ulonglong)uVar5 + 0x841) * 0x10) = 0;
      if (*(int *)(param_1 + 0x66bc) != 0) {
        do {
          uVar3 = (ulonglong)uVar4;
          uVar4 = uVar4 + 1;
          *(undefined8 *)(*(longlong *)(param_1 + 0x8418 + (ulonglong)uVar5 * 0x10) + uVar3 * 8) =
               0xffffffffffffffff;
        } while (uVar4 < *(uint *)(param_1 + 0x66bc));
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(byte *)(param_1 + 0x76ea));
  }
  MemFastZero(param_2,0x40);
  MemFastZero(param_3,0x48);
  param_3[3] = 2;
  *param_3 = 4;
  *(undefined4 *)(param_3 + 0xc) = 0x10000200;
  if ((*(char *)(param_1 + 0x76e9) == '\0') || (*(byte *)(param_1 + 0x76ea) < 2)) {
    param_3[0x17] = 0;
  }
  else {
    param_3[0x17] = *(byte *)(param_1 + 0x76ea);
  }
  *(undefined2 *)(param_3 + 0x1a) = 0x40;
  *(undefined2 *)(param_3 + 0x1c) = *(undefined2 *)(param_1 + 0x66bc);
  *(undefined2 *)(param_3 + 0x1e) = 0;
  uVar2 = StorPortGetPhysicalAddress(param_1,0,*(undefined8 *)(param_1 + 0x8418),local_res8);
  *(undefined8 *)(param_3 + 0x30) = uVar2;
  uVar2 = StorPortGetPhysicalAddress(param_1,0,*(undefined8 *)(param_1 + 0x8408),local_res8);
  *(undefined8 *)(param_3 + 0x28) = uVar2;
  *(undefined4 *)(param_3 + 0x20) = *(undefined4 *)(param_1 + 0x164);
  *(undefined8 *)(param_3 + 0x38) = 0;
  StorPortQuerySystemTime(&local_res18);
  local_res18 = (longlong)(local_res18 + 0xfe624e212ac18000) / 10000;
  if (((local_res18 >> 0x20 & 0xfffffff0) != 0) || (iVar1 = 0, (int)local_res18 != 0)) {
    iVar1 = 1;
  }
  *(longlong *)(param_3 + 0x40) = (longlong)iVar1;
  uVar2 = StorPortGetPhysicalAddress(param_1,0,param_3,local_res8);
  *(undefined8 *)(param_2 + 0x18) = uVar2;
  uVar2 = StorPortGetPhysicalAddress(param_1,0,*(undefined8 *)(param_1 + 0xd0),local_res8);
  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 1;
  *(ushort *)(param_2 + 0x10) = *(ushort *)(param_2 + 0x10) | 1;
  *(undefined8 *)(param_2 + 0x28) = uVar2;
  *param_2 = 0;
  *(undefined4 *)(param_2 + 0x14) = 8;
  param_2[2] = 0xff;
  uVar2 = StorPortGetPhysicalAddress(param_1,0,param_2,local_res8);
  *(uint *)(*(longlong *)(param_1 + 0x80) + 0xc0) = (uint)uVar2 & 0xffffff02 | 2;
  LOCK();
  UNLOCK();
  *(int *)(*(longlong *)(param_1 + 0x80) + 0xc4) = (int)((ulonglong)uVar2 >> 0x20);
  LOCK();
  UNLOCK();
  return CONCAT71((uint7)((ulonglong)uVar2 >> 0x28),1);
}



===== FUN_1c0005524 @ 1c0005524 =====

undefined8 FUN_1c0005524(longlong param_1,longlong param_2,ushort *param_3,longlong param_4)

{
  ushort *puVar1;
  ushort *puVar2;
  ulonglong *puVar3;
  byte bVar4;
  byte bVar5;
  undefined1 uVar6;
  char cVar7;
  ushort uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  ushort *puVar11;
  undefined1 uVar12;
  char local_res10 [8];
  char local_38 [4];
  ushort local_34 [2];
  undefined8 *local_30;
  
  local_res10[0] = '\0';
  bVar4 = *(byte *)(*(longlong *)(param_2 + 0x500) + 6);
  local_38[0] = '\0';
  if (*(char *)(param_2 + 0x568) != '\0') {
    puVar1 = param_3 + 0x30;
    puVar3 = (ulonglong *)(param_2 + 0x528);
    uVar9 = MegaSASBuildRaidContext
                      ((ulonglong)bVar4,param_4,*(ulonglong *)(param_2 + 0x520),
                       *(uint *)(param_2 + 0x530),(uint)bVar4,*(char *)(param_2 + 0x518),
                       *(char *)(param_1 + 0x7be1),(longlong *)puVar3,(longlong)puVar1,
                       (short *)local_34,local_res10,local_38,(longlong *)&local_30);
    if ((char)uVar9 != '\0') {
      bVar5 = *(byte *)(param_2 + 0x54c);
      if (local_res10[0] == '\0') {
        CDB_SetStartLBA((longlong)(param_3 + 0x20),bVar5,*(undefined8 *)(param_2 + 0x520));
        *(undefined1 *)(param_2 + 0x570) = 0xe;
        uVar10 = 0;
        *param_3 = (ushort)bVar4;
        *(undefined1 *)((longlong)param_3 + 3) = 0xf1;
        if (*(char *)(param_1 + 0x7be1) != '\0') {
          *puVar1 = *puVar1 & 0xff12 | 0x12;
          uVar10 = (ulonglong)*(byte *)(param_2 + 0x570);
          if ((char)param_3[0x32] == '\0') {
            uVar10 = 4;
          }
          *(char *)(param_2 + 0x570) = (char)uVar10;
          *(byte *)(param_3 + 0x32) = (byte)param_3[0x32] | 8;
        }
      }
      else {
        if ((bVar5 < 0x10) && (0xffffffff < *puVar3)) {
          puVar2 = param_3 + 0x20;
          uVar6 = *(undefined1 *)((longlong)param_3 + 0x41);
          if (bVar5 == 0xc) {
            uVar12 = (undefined1)param_3[0x25];
            local_res10[0] = *(char *)((longlong)param_3 + 0x4b);
          }
          else {
            uVar12 = (undefined1)param_3[0x23];
            local_res10[0] = *(char *)((longlong)param_3 + 0x49);
          }
          MemFastZero(puVar2,0x20);
          uVar8 = 0x10;
          puVar11 = puVar2;
          CDB_SetBlockCnt((longlong)puVar2,(ulonglong)*(uint *)(param_2 + 0x530),'\x10');
          CDB_SetStartLBA((longlong)puVar11,(char)uVar8,*puVar3);
          *(char *)(param_2 + 0x54c) = (char)uVar8;
          param_3[0x12] = uVar8;
          cVar7 = *(char *)(param_2 + 0x518);
          *(undefined1 *)((longlong)param_3 + 0x41) = uVar6;
          *(undefined1 *)(param_3 + 0x27) = uVar12;
          *(char *)((longlong)param_3 + 0x4f) = local_res10[0];
          *(byte *)puVar2 = (-(cVar7 != '\0') & 0xfeU) + 0x8a;
        }
        else {
          CDB_SetStartLBA((longlong)(param_3 + 0x20),bVar5,*puVar3);
        }
        *(ushort *)(param_2 + 0x576) = local_34[0];
        *(undefined1 *)(param_2 + 0x570) = 0xc;
        *(undefined1 *)((longlong)param_3 + 3) = 0;
        *param_3 = local_34[0];
        uVar10 = MemFastMove((undefined8 *)(param_3 + 0x1a),local_30,8);
        if (*(char *)(param_1 + 0x7be1) != '\0') {
          uVar8 = *puVar1 & 0xff12 | 0x12;
          uVar10 = (ulonglong)uVar8;
          *(byte *)(param_3 + 0x32) = (byte)param_3[0x32] | 0x88;
          *puVar1 = uVar8;
        }
      }
      goto LAB_1c0005660;
    }
  }
  CDB_SetStartLBA((longlong)(param_3 + 0x20),*(char *)(param_2 + 0x54c),
                  *(undefined8 *)(param_2 + 0x520));
  *(undefined1 *)(param_2 + 0x570) = 0xe;
  uVar10 = 0;
  *param_3 = (ushort)bVar4;
  param_3[0x33] = (ushort)bVar4;
  *(undefined1 *)((longlong)param_3 + 3) = 0xf1;
  *(undefined1 *)(param_3 + 0x32) = 0;
  param_3[0x31] = 0x14;
  if (*(char *)(param_1 + 0x7be1) != '\0') {
    uVar8 = param_3[0x30] & 0xfff2 | 2;
    uVar10 = (ulonglong)uVar8;
    param_3[0x30] = uVar8;
    *(undefined1 *)(param_2 + 0x570) = 4;
  }
  *(undefined1 *)(param_2 + 0x569) = 1;
  if (local_38[0] == '\0') {
    return uVar10 & 0xffffffffffffff00;
  }
LAB_1c0005660:
  return CONCAT71((int7)(uVar10 >> 8),1);
}



===== FUN_1c0005804 @ 1c0005804 =====

void FUN_1c0005804(longlong param_1,longlong param_2,longlong param_3)

{
  char *pcVar1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  uint uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined1 uVar10;
  undefined1 uVar9;
  undefined1 uVar8;
  undefined1 uVar11;
  undefined2 uVar12;
  undefined1 uVar13;
  
  pcVar1 = (char *)(param_3 + 0x40);
  uVar6 = *(ulonglong *)(param_2 + 0x528);
  uVar5 = *(uint *)(param_2 + 0x530);
  lVar7 = *(longlong *)(param_1 + 0x7be8 + (ulonglong)(*(uint *)(param_2 + 0x56c) & 1) * 8);
  bVar2 = *(byte *)((ulonglong)*(byte *)(*(longlong *)(param_2 + 0x500) + 6) + 0x20 + lVar7);
  uVar8 = (undefined1)(uVar6 >> 8);
  uVar9 = (undefined1)(uVar6 >> 0x10);
  uVar10 = (undefined1)(uVar6 >> 0x18);
  if ((bVar2 < 0x40) &&
     (((byte)*(undefined4 *)((ulonglong)bVar2 * 0x9e0 + 0x28a8 + lVar7) & 0xf0) == 0x80)) {
    MemFastZero(pcVar1,0x20);
    *pcVar1 = '\x7f';
    *(undefined1 *)(param_3 + 0x47) = 0x18;
    cVar3 = *(char *)(param_2 + 0x518);
    *(undefined1 *)(param_3 + 0x4a) = 0x20;
    *(char *)(param_3 + 0x53) = (char)uVar6;
    *(char *)(param_3 + 0x5f) = (char)uVar5;
    *(char *)(param_3 + 0x4c) = (char)(uVar6 >> 0x38);
    *(byte *)(param_3 + 0x49) = (-(cVar3 != '\0') & 0xfeU) + 0xb;
    *(char *)(param_3 + 0x4d) = (char)(uVar6 >> 0x30);
    *(char *)(param_3 + 0x4e) = (char)(uVar6 >> 0x28);
    *(char *)(param_3 + 0x4f) = (char)(uVar6 >> 0x20);
    *(undefined1 *)(param_3 + 0x50) = uVar10;
    *(undefined1 *)(param_3 + 0x51) = uVar9;
    *(undefined1 *)(param_3 + 0x52) = uVar8;
    *(char *)(param_3 + 0x5c) = (char)(uVar5 >> 0x18);
    *(char *)(param_3 + 0x5d) = (char)(uVar5 >> 0x10);
    *(char *)(param_3 + 0x5e) = (char)(uVar5 >> 8);
    uVar12 = 0x8703;
    *(uint *)(param_3 + 0x54) =
         ((*(int *)(param_2 + 0x520) << 8 | (uint)*(byte *)(param_2 + 0x521)) << 8 |
         (uint)*(byte *)(param_2 + 0x522)) << 8 | (uint)*(byte *)(param_2 + 0x523);
    *(undefined2 *)(param_3 + 0x5a) = 0xffff;
    if (*(char *)(param_2 + 0x518) == '\0') {
      uVar12 = 0x8004;
    }
    *(uint *)(param_3 + 0x3c) = *(uint *)(param_3 + 0x3c) | 0x10000000;
    *(undefined2 *)(param_3 + 0x26) = uVar12;
    *(undefined4 *)(param_3 + 0x28) = 0x200;
    *(undefined1 *)(param_2 + 0x54c) = 0x20;
    *(undefined2 *)(param_3 + 0x24) = 0x20;
  }
  else if ((0xb < *(byte *)(param_2 + 0x54c)) && ((uVar6 < 0x100000000 && (uVar5 < 0x10000)))) {
    uVar4 = *(undefined1 *)(param_3 + 0x41);
    if (*(byte *)(param_2 + 0x54c) == 0x10) {
      uVar13 = *(undefined1 *)(param_3 + 0x4e);
      uVar11 = *(undefined1 *)(param_3 + 0x4f);
    }
    else {
      uVar13 = *(undefined1 *)(param_3 + 0x4a);
      uVar11 = *(undefined1 *)(param_3 + 0x4b);
    }
    MemFastZero(pcVar1,0x20);
    uVar12 = 10;
    CDB_SetBlockCnt((longlong)pcVar1,(ulonglong)uVar5,'\n');
    *(char *)(param_3 + 0x45) = (char)uVar6;
    *(undefined1 *)(param_3 + 0x44) = uVar8;
    *(undefined1 *)(param_3 + 0x43) = uVar9;
    *(undefined1 *)(param_3 + 0x42) = uVar10;
    *(char *)(param_2 + 0x54c) = (char)uVar12;
    *(undefined2 *)(param_3 + 0x24) = uVar12;
    cVar3 = *(char *)(param_2 + 0x518);
    *(undefined1 *)(param_3 + 0x41) = uVar4;
    *(undefined1 *)(param_3 + 0x46) = uVar13;
    *(undefined1 *)(param_3 + 0x49) = uVar11;
    *pcVar1 = (-(cVar3 != '\0') & 0xfeU) + 0x2a;
  }
  return;
}



===== FUN_1c0005a54 @ 1c0005a54 =====

void FUN_1c0005a54(longlong param_1,longlong param_2,ushort *param_3,longlong param_4)

{
  byte bVar1;
  byte bVar2;
  longlong lVar3;
  ushort uVar4;
  
  bVar1 = *(byte *)(*(longlong *)(param_2 + 0x500) + 6);
  if ((((bVar1 < 0x40) && (*(char *)(param_1 + 0x88) == '\0')) &&
      (bVar2 = *(byte *)((ulonglong)bVar1 + 0x20 + param_4), bVar2 < 0x40)) &&
     (lVar3 = (ulonglong)bVar2 * 0x9e0, (*(byte *)(lVar3 + 0x28ab + param_4) & 1) != 0)) {
    *(undefined1 *)(param_3 + 0x32) = 1;
    bVar2 = *(byte *)(lVar3 + 0x28d4 + param_4);
    param_3[0x34] = 0;
    param_3[0x35] = 0;
    param_3[0x36] = 0;
    param_3[0x37] = 0;
    param_3[0x38] = 0;
    param_3[0x39] = 0;
    param_3[0x31] = (ushort)bVar2;
    param_3[0x33] = (ushort)bVar1;
    uVar4 = *(ushort *)
             (param_4 + 0x20a8 +
             (ulonglong)
             *(ushort *)((ulonglong)*(ushort *)(lVar3 + 0x2960 + param_4) * 0x40 + 0xa8 + param_4) *
             8);
    *(ushort *)(param_2 + 0x576) = uVar4;
    *(undefined1 *)(param_2 + 0x570) = 0xc;
    MemFastMove((undefined8 *)(param_3 + 0x1a),(undefined8 *)(param_4 + 0x28cc + lVar3),8);
    *(undefined1 *)((longlong)param_3 + 3) = 0;
    *param_3 = uVar4;
  }
  else {
    *(undefined1 *)(param_2 + 0x570) = 0;
    *param_3 = (ushort)bVar1;
    param_3[0x31] = 0x14;
    param_3[0x33] = (ushort)bVar1;
    *(undefined1 *)((longlong)param_3 + 3) = 0xf1;
    *(undefined1 *)(param_3 + 0x32) = 0;
  }
  return;
}



===== MPT_BuildPassthrough @ 1c0005b40 =====

void MPT_BuildPassthrough(longlong param_1,void *param_2,undefined8 param_3)

{
  MemFastZero(param_2,0x100);
  *(undefined2 *)((longlong)param_2 + 2) = 0xf008;
  *(undefined1 *)((longlong)param_2 + 0x14) = 0x20;
  *(undefined8 *)((longlong)param_2 + 0x80) = param_3;
  *(undefined4 *)((longlong)param_2 + 0x8c) = 0x83000000;
  *(undefined4 *)((longlong)param_2 + 0x88) = 0x400;
  if (*(char *)(param_1 + 0x7be1) != '\0') {
    *(undefined1 *)((longlong)param_2 + 0xff) = 0;
  }
  return;
}



===== MPT_BuildCmd_Scsi @ 1c0005ba8 =====

longlong MPT_BuildCmd_Scsi(longlong param_1,byte *param_2)

{
  byte bVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  
  lVar3 = *(longlong *)(param_2 + 0x500);
  MemFastZero(param_2,0x80);
  param_2[0x570] = 0;
  param_2[0x571] = 0;
  param_2[0x572] = 0;
  param_2[0x573] = 0;
  param_2[0x574] = 0;
  param_2[0x575] = 0;
  param_2[0x576] = 0;
  param_2[0x577] = 0;
  MemFastMove((undefined8 *)(param_2 + 0x40),(undefined8 *)(lVar3 + 0x48),(uint)param_2[0x54c]);
  CDB_GetInfo(lVar3 + 0x48,param_2[0x54c],(ulonglong *)(param_2 + 0x520),(uint *)(param_2 + 0x530));
  param_2[0x571] = param_2[0x50c];
  if (*(char *)(lVar3 + 5) == '\x01') {
    uVar4 = *(int *)(param_1 + 0x7be4) - 1;
    *(uint *)(param_2 + 0x56c) = uVar4;
    if ((param_2[0x518] == 0) && (param_2[0x519] == 0)) {
      FUN_1c0005a54(param_1,(longlong)param_2,(ushort *)param_2,
                    *(longlong *)(param_1 + 0x7be8 + (ulonglong)(uVar4 & 1) * 8));
    }
    else {
      bVar1 = *(byte *)(param_1 + 0x7be2);
      param_2[0x568] = bVar1;
      param_2[0x568] = -(*(byte *)(lVar3 + 6) < 0x40) & bVar1;
      FUN_1c0005524(param_1,(longlong)param_2,(ushort *)param_2,
                    *(longlong *)(param_1 + 0x7be8 + (ulonglong)(uVar4 & 1) * 8));
    }
  }
  else {
    if (*(char *)((ulonglong)*(byte *)(lVar3 + 6) + 0x23f2 + param_1) == '\0') {
      param_2[0x570] = 0;
      lVar3 = MFI_BuildFrame_NonRW(param_1,param_2);
      return lVar3;
    }
    param_2[0x570] = 0xc;
    param_2[3] = 0;
    bVar1 = *(byte *)(param_1 + 0x7be2);
    param_2[0x568] = bVar1;
    uVar4 = *(int *)(param_1 + 0x7be4) - 1;
    *(uint *)(param_2 + 0x56c) = uVar4;
    if (bVar1 == 0) {
      param_2[0] = 0xff;
      param_2[1] = 0xff;
    }
    else {
      *(undefined2 *)param_2 =
           *(undefined2 *)
            (*(longlong *)(param_1 + 0x7be8 + (ulonglong)(uVar4 & 1) * 8) + 0x20a8 +
            (ulonglong)*(byte *)(*(longlong *)(param_2 + 0x500) + 6) * 8);
    }
    *(undefined2 *)(param_2 + 0x576) = *(undefined2 *)param_2;
    param_2[0x62] = 0x14;
    param_2[99] = 0;
    param_2[100] = 0;
    bVar1 = *(byte *)(*(longlong *)(param_2 + 0x500) + 6);
    param_2[0x68] = 0;
    param_2[0x69] = 0;
    param_2[0x6a] = 0;
    param_2[0x6b] = 0;
    param_2[0x6c] = 0;
    param_2[0x6d] = 0;
    param_2[0x6e] = 0;
    param_2[0x6f] = 0;
    param_2[0x70] = 0;
    param_2[0x71] = 0;
    param_2[0x72] = 0;
    param_2[0x73] = 0;
    *(ushort *)(param_2 + 0x66) = (ushort)bVar1;
    param_2[0x78] = 0x10;
  }
  param_2[0x14] = 0x20;
  *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(lVar3 + 0x10);
  lVar2 = 0;
  *(ushort *)(param_2 + 0x24) = (ushort)param_2[0x54c];
  if (*(int *)(lVar3 + 0x10) != 0) {
    param_2[0x10] = 2;
    param_2[0x11] = 0;
    if ((char)*(undefined4 *)(lVar3 + 0xc) < '\0') {
      *(uint *)(param_2 + 0x3c) = *(uint *)(param_2 + 0x3c) | 0x1000000;
    }
    else {
      *(uint *)(param_2 + 0x3c) = *(uint *)(param_2 + 0x3c) | 0x2000000;
    }
    *(byte **)(param_2 + 0x540) = param_2 + 0x100;
    *(byte **)(param_2 + 0x538) = param_2 + 0x100;
    lVar2 = BuildSGLforSRB(param_1,(longlong)param_2);
    if ((char)lVar2 == '\0') {
      *(undefined1 *)(lVar3 + 3) = 4;
      return lVar2;
    }
    param_2[0x79] = param_2[0x534];
  }
  return CONCAT71((int7)((ulonglong)lVar2 >> 8),1);
}



===== MPT_SendRequestToFW @ 1c0005dd0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void MPT_SendRequestToFW(longlong param_1,byte *param_2)

{
  int *piVar1;
  byte bVar2;
  short sVar3;
  undefined2 uVar4;
  longlong lVar5;
  ulonglong uVar6;
  byte bVar7;
  uint uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  bool bVar12;
  char *pcVar13;
  uint uVar14;
  uint uVar15;
  byte bVar16;
  byte *pbVar17;
  undefined1 local_res10 [8];
  
  lVar5 = *(longlong *)(param_2 + 0x500);
  *(ushort *)(param_2 + 0x572) = *(short *)(param_2 + 0x508) + 1U;
  if ((*(char *)(lVar5 + 2) != '\0') ||
     ((*(char *)(lVar5 + 5) != '\x01' &&
      (*(char *)((ulonglong)*(byte *)(lVar5 + 6) + 0x23f2 + param_1) == '\0')))) {
    MPT_BuildPassthrough
              (param_1,(void *)((ulonglong)(ushort)(*(short *)(param_2 + 0x508) + 1U) * 0x100 +
                               *(longlong *)(param_1 + 0x8408)),*(undefined8 *)(param_2 + 0x510));
    MFI_SendRequestToFW(param_1,param_2);
    return;
  }
  uVar15 = 0x80;
  bVar16 = *(byte *)(param_1 + 0x7be1);
  if (*(char *)(lVar5 + 0xb) != '\0') {
    *(int *)(param_2 + 0xc) = *(int *)(param_1 + 0x160) + *(int *)(param_2 + 0x508) * 0x12;
    bVar7 = 0x12;
    if (*(byte *)(lVar5 + 0xb) < 0x12) {
      bVar7 = *(byte *)(lVar5 + 0xb);
    }
    param_2[0x12] = bVar7;
  }
  if (*(int *)(lVar5 + 0x10) != 0) {
    bVar7 = param_2[0x534];
    uVar8 = (uint)bVar7;
    if (bVar7 >= 9) {
      uVar8 = 7;
    }
    uVar14 = param_2[0x535] * uVar8;
    MemFastMove((undefined8 *)(param_2 + 0x80),*(undefined8 **)(param_2 + 0x538),uVar14);
    uVar15 = uVar14 + 0x80;
    if (bVar7 < 9) {
      if (*(char *)(param_1 + 0x7be1) != '\0') {
        bVar16 = bVar16 & -(uVar8 < 8);
        param_2[(ulonglong)(uVar8 - 1) * 0x10 + 0x8f] = 0x40;
      }
    }
    else {
      uVar9 = StorPortGetPhysicalAddress
                        (param_1,lVar5,(ulonglong)uVar14 + *(longlong *)(param_2 + 0x538),
                         local_res10);
      pbVar17 = param_2 + 0x80 + (ulonglong)uVar8 * 0x10;
      pbVar17[0xf] = 0x80;
      bVar7 = param_2[0x534];
      bVar2 = param_2[0x535];
      *(undefined8 *)pbVar17 = uVar9;
      pbVar17[0xe] = 0;
      pbVar17[0xc] = 0;
      pbVar17[0xd] = 0;
      *(uint *)(pbVar17 + 8) = (bVar7 - uVar8) * (uint)bVar2;
      param_2[2] = 0xf;
      if (*(char *)(param_1 + 0x7be1) == '\0') {
        pbVar17[0xf] = pbVar17[0xf] | 3;
      }
      else {
        bVar16 = 0;
        *(undefined1 *)(*(longlong *)(param_2 + 0x538) + -1 + (ulonglong)param_2[0x534] * 0x10) =
             0x40;
      }
      uVar15 = uVar15 + param_2[0x535];
    }
  }
  if (param_2[0x54d] != 0) {
    UpdateIOMetric(param_1,*(byte *)(lVar5 + 6),param_2[0x518],*(ulonglong *)(param_2 + 0x520),
                   *(uint *)(param_2 + 0x530));
  }
  if ((param_2[0x54e] != 0) && (1 < param_2[0x54f])) {
    if (param_2[0x54c] == 6) {
      param_2[0x44] = (byte)*(uint *)(param_2 + 0x530);
    }
    else {
      CDB_SetBlockCnt((longlong)(param_2 + 0x40),(ulonglong)*(uint *)(param_2 + 0x530),
                      param_2[0x54c]);
    }
    *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x530) << 9;
    param_2[0x79] = param_2[0x534];
  }
  if ((*(char *)(param_1 + 0x7be2) == '\0') || (*(char *)(lVar5 + 5) != '\x01')) {
    if ((*(char *)((ulonglong)*(byte *)(lVar5 + 6) + 0x23f2 + param_1) != '\0') &&
       (param_2[0x568] != 0)) {
      uVar8 = *(int *)(param_1 + 0x7be4) - 1;
      if (uVar8 != *(uint *)(param_2 + 0x56c)) {
        *(uint *)(param_2 + 0x56c) = uVar8;
        uVar4 = *(undefined2 *)
                 (*(longlong *)(param_1 + 0x7be8 + ((ulonglong)uVar8 & 1) * 8) + 0x20a8 +
                 (ulonglong)*(byte *)(lVar5 + 6) * 8);
        *(undefined2 *)param_2 = uVar4;
        *(undefined2 *)(param_2 + 0x576) = uVar4;
        *(undefined2 *)(param_2 + 0x62) = *(undefined2 *)(lVar5 + 0x14);
      }
    }
    goto LAB_1c00061d2;
  }
  if ((param_2[0x568] != 0) &&
     (((uVar8 = *(int *)(param_1 + 0x7be4) - 1, param_2[0x54e] != 0 || (param_2[0x569] != 0)) ||
      (uVar8 != *(uint *)(param_2 + 0x56c))))) {
    *(uint *)(param_2 + 0x56c) = uVar8;
    uVar9 = FUN_1c0005524(param_1,(longlong)param_2,(ushort *)param_2,
                          *(longlong *)(param_1 + 0x7be8 + ((ulonglong)uVar8 & 1) * 8));
    if ((char)uVar9 == '\0') {
      StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x52);
      *(undefined1 *)(param_1 + 0x7be2) = 0;
    }
  }
  if (param_2[3] != 0) goto LAB_1c00061d2;
  if (param_2[0x518] == 0) {
LAB_1c0006162:
    if (param_2[0x519] == 0) goto LAB_1c00061d2;
  }
  else {
    pcVar13 = (char *)(param_1 + 0x7c08 + (ulonglong)*(byte *)(lVar5 + 6) * 0x20);
    if (*pcVar13 != '\0') {
      uVar11 = *(ulonglong *)(pcVar13 + 0x10);
      uVar6 = *(ulonglong *)(param_2 + 0x528);
      if (uVar11 < uVar6) {
        uVar11 = uVar6 - uVar11;
      }
      else {
        uVar11 = uVar11 - uVar6;
      }
      uVar10 = *(ulonglong *)(pcVar13 + 0x18);
      if (uVar10 < uVar6) {
        uVar10 = uVar6 - uVar10;
      }
      else {
        uVar10 = uVar10 - uVar6;
      }
      bVar12 = uVar10 < uVar11;
      if (((!bVar12) &&
          (*(int *)(param_1 + 0x8c) + *(uint *)(pcVar13 + 0xc) < *(uint *)(pcVar13 + 8))) ||
         ((bVar12 && (*(int *)(param_1 + 0x8c) + *(uint *)(pcVar13 + 8) < *(uint *)(pcVar13 + 0xc)))
         )) {
        bVar12 = !bVar12;
      }
      uVar11 = (ulonglong)bVar12;
      *(ulonglong *)(pcVar13 + uVar11 * 8 + 0x10) =
           (uVar6 - 1) + (ulonglong)*(uint *)(param_2 + 0x530);
      piVar1 = (int *)(pcVar13 + uVar11 * 4 + 8);
      sVar3 = *(short *)(pcVar13 + uVar11 * 2 + 2);
      *(int **)(param_2 + 0x560) = piVar1;
      LOCK();
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      if (*(short *)param_2 != sVar3) {
        *(short *)(param_2 + 0x576) = sVar3;
        *(short *)param_2 = sVar3;
      }
    }
    if (param_2[0x518] == 0) goto LAB_1c0006162;
  }
  FUN_1c0005804(param_1,(longlong)param_2,(longlong)param_2);
LAB_1c00061d2:
  if ((*(char *)(param_1 + 0x7be1) != '\0') && (param_2[3] == 0)) {
    param_2[2] = 0;
    *(ushort *)(param_2 + 0x24) = *(ushort *)(param_2 + 0x24) | 0x4000;
  }
  MemFastMove((undefined8 *)
              ((ulonglong)*(ushort *)(param_2 + 0x572) * 0x100 + *(longlong *)(param_1 + 0x8408)),
              (undefined8 *)param_2,uVar15);
  if (bVar16 != 0) {
    *(undefined1 *)
     ((ulonglong)*(ushort *)(param_2 + 0x572) * 0x100 + 0xff + *(longlong *)(param_1 + 0x8408)) = 0;
  }
  (**(code **)(*(longlong *)(param_1 + 0x188) + 0x50))(param_1,param_2);
  return;
}



===== MPT_CompleteRequests @ 1c0006290 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 MPT_CompleteRequests(longlong param_1,ulonglong param_2)

{
  ushort uVar1;
  uint uVar2;
  char *pcVar3;
  longlong lVar4;
  int *piVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined4 uVar8;
  byte bVar9;
  char cVar10;
  ushort *puVar11;
  longlong *plVar12;
  
  puVar11 = (ushort *)(((param_2 & 0xffffffff) + 0x841) * 0x10 + param_1);
  uVar6 = (ulonglong)*puVar11;
  plVar12 = (longlong *)(*(longlong *)(puVar11 + 4) + uVar6 * 8);
  if (*plVar12 == -1) {
    (**(code **)(*(longlong *)(param_1 + 0x188) + 0x18))();
    uVar6 = CheckFirmwareFault(param_1,param_2,uVar6);
    if ((char)uVar6 != '\0') {
LAB_1c000646e:
      return uVar6 & 0xffffffffffffff00;
    }
  }
  else {
    do {
      uVar1 = *(ushort *)((longlong)plVar12 + 2);
      *plVar12 = -1;
      *puVar11 = *puVar11 + 1;
      if ((uint)*puVar11 < *(uint *)(param_1 + 0x66bc)) {
        plVar12 = plVar12 + 1;
      }
      else {
        plVar12 = *(longlong **)(puVar11 + 4);
        *puVar11 = 0;
      }
      if ((uVar1 == 0) || (*(uint *)(param_1 + 0x66bc) < (uint)uVar1)) {
        uVar8 = 0x22;
LAB_1c0006466:
        uVar6 = SetDeadAdapter(param_1,uVar8);
        goto LAB_1c000646e;
      }
      pcVar3 = *(char **)(param_1 + 0x188 + (ulonglong)uVar1 * 8);
      if (pcVar3 == (char *)0x0) {
        uVar8 = 6;
        goto LAB_1c0006466;
      }
      lVar4 = *(longlong *)(pcVar3 + 0x500);
      if (lVar4 != 0) {
        uVar2 = *(uint *)(pcVar3 + 0x508);
        lVar7 = (ulonglong)uVar1 * 0x100 + *(longlong *)(param_1 + 0x8408);
        if ((*(char *)(lVar7 + 3) == '\0') || (*(char *)(lVar7 + 3) == -0xf)) {
          piVar5 = *(int **)(pcVar3 + 0x560);
          if (piVar5 != (int *)0x0) {
            LOCK();
            *piVar5 = *piVar5 + -1;
            UNLOCK();
          }
          *(undefined4 *)(pcVar3 + 0x548) = *(undefined4 *)(lVar7 + 0x1c);
          cVar10 = *(char *)(lVar7 + 0x76);
          bVar9 = *(byte *)(lVar7 + 0x77);
LAB_1c00063ea:
          CompleteScsiRequest(param_1,(longlong)pcVar3,bVar9,cVar10);
        }
        else {
          cVar10 = *(char *)(lVar4 + 2);
          if (cVar10 == '\0') {
            *(undefined4 *)(pcVar3 + 0x548) = *(undefined4 *)(pcVar3 + 0x14);
            cVar10 = pcVar3[3];
            bVar9 = pcVar3[2];
            goto LAB_1c00063ea;
          }
          if (cVar10 == '\b') {
            if (pcVar3[2] == '\0') {
              *(undefined2 *)(lVar4 + 3) = 1;
            }
            else {
              *(undefined1 *)(lVar4 + 3) = 4;
            }
            StorPortNotification(0,param_1);
          }
          else if (cVar10 == '\x02') {
            CompleteIoctlRequest(param_1,(undefined8 *)pcVar3);
          }
        }
        if (*(char **)(param_1 + 400 + (ulonglong)uVar2 * 8) == pcVar3) {
          *(undefined8 *)(param_1 + 400 + (ulonglong)uVar2 * 8) = 0;
          *(uint *)(param_1 + 0x2190) = uVar2;
          LOCK();
          *(int *)(param_1 + 0x21c0) = *(int *)(param_1 + 0x21c0) + -1;
          UNLOCK();
          if (-1 < *(int *)(param_1 + 0x21c0)) goto LAB_1c0006422;
          uVar8 = 0x25;
        }
        else {
          uVar8 = 0x21;
        }
        goto LAB_1c0006466;
      }
      if ((*pcVar3 != '\x05') || ((uint)uVar1 <= *(uint *)(param_1 + 0x66c0))) {
        uVar8 = 7;
        goto LAB_1c0006466;
      }
      CompleteDCMD(param_1,(longlong)pcVar3,'\0');
LAB_1c0006422:
    } while (*plVar12 != -1);
    uVar6 = *(ulonglong *)(param_1 + 0x80);
    *(uint *)(uVar6 + 0x6c) = (int)param_2 << 0x18 | (uint)*puVar11;
    LOCK();
    UNLOCK();
  }
  return CONCAT71((int7)(uVar6 >> 8),1);
}



===== MPT_UpdateReplyQueue @ 1c00064b0 =====

void MPT_UpdateReplyQueue(longlong param_1)

{
  bool bVar1;
  longlong *plVar2;
  ushort uVar3;
  ulonglong uVar4;
  ushort *puVar5;
  int iVar6;
  
  bVar1 = true;
  while( true ) {
    iVar6 = 0;
    if (*(char *)(param_1 + 0x76ea) != '\0') {
      puVar5 = (ushort *)(param_1 + 0x8410);
      do {
        uVar4 = (ulonglong)*puVar5;
        plVar2 = (longlong *)(*(longlong *)(puVar5 + 4) + uVar4 * 8);
        while (*plVar2 != -1) {
          LOCK();
          *(int *)(param_1 + 0x7ba4) = *(int *)(param_1 + 0x7ba4) + -1;
          UNLOCK();
          uVar3 = (ushort)uVar4 + 1;
          uVar4 = (ulonglong)uVar3;
          *plVar2 = -1;
          if ((uint)uVar3 < *(uint *)(param_1 + 0x66bc)) {
            plVar2 = plVar2 + 1;
          }
          else {
            plVar2 = *(longlong **)(puVar5 + 4);
            uVar4 = 0;
          }
        }
        *puVar5 = (ushort)uVar4;
        *(uint *)(*(longlong *)(param_1 + 0x80) + 0x6c) = iVar6 << 0x18 | (uint)uVar4;
        LOCK();
        UNLOCK();
        iVar6 = iVar6 + 1;
        puVar5 = puVar5 + 8;
      } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x76ea));
    }
    if ((*(int *)(param_1 + 0x7ba4) < 1) || (!bVar1)) break;
    bVar1 = false;
    StorPortStallExecution(1000);
  }
  return;
}



===== FireRequest_SrbExt @ 1c0006580 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FireRequest_SrbExt(longlong param_1,longlong param_2)

{
  (**(code **)(*(longlong *)(param_1 + 0x188) + 0x60))
            (param_1,*(undefined8 *)(param_2 + 0x510),*(undefined1 *)(param_2 + 0x559));
  return;
}



===== Xscale_CheckInterrupt @ 1c00065a0 =====

undefined8 Xscale_CheckInterrupt(longlong param_1)

{
  uint uVar1;
  ulonglong uVar2;
  byte bVar3;
  
  bVar3 = 0;
  if ((*(char *)(param_1 + 0x7bbd) == '\0') ||
     (uVar2 = *(ulonglong *)(param_1 + 0x7bd8), *(int *)(uVar2 + 4) != -0x21522153)) {
    uVar1 = *(uint *)(*(ulonglong *)(param_1 + 0x80) + 0x30);
    uVar2 = *(ulonglong *)(param_1 + 0x80) & 0xffffffffffffff00;
    bVar3 = (uVar1 & 2) != 0;
    if ((uVar1 & 1) != 0) {
      bVar3 = bVar3 | 2;
    }
    if (bVar3 != 0) {
      *(uint *)(*(longlong *)(param_1 + 0x80) + 0x30) = uVar1;
      LOCK();
      UNLOCK();
    }
  }
  return CONCAT71((int7)(uVar2 >> 8),bVar3);
}



===== Xscale_EnableInterrupt @ 1c0006600 =====

undefined4 Xscale_EnableInterrupt(longlong param_1)

{
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34) = 0xfffffffc;
  LOCK();
  UNLOCK();
  return *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34);
}



===== Xscale_DisableInterrupt @ 1c0006620 =====

undefined4 Xscale_DisableInterrupt(longlong param_1)

{
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34) = 0x1f;
  LOCK();
  UNLOCK();
  return *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34);
}



===== Xscale_ReadRegister @ 1c0006640 =====

undefined4 Xscale_ReadRegister(longlong param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}



===== Xscale_ReadDoorbell @ 1c0006650 =====

undefined4 Xscale_ReadDoorbell(longlong param_1)

{
  return *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x20);
}



===== Xscale_WriteDoorbell @ 1c0006660 =====

void Xscale_WriteDoorbell(longlong param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x20) = param_2;
  LOCK();
  UNLOCK();
  return;
}



===== Xscale_FireCmd @ 1c0006670 =====

void Xscale_FireCmd(longlong param_1,longlong param_2,byte param_3)

{
  uint local_res10;
  
  local_res10 = (uint)param_2;
  if (param_2 < 0x800000000) {
    local_res10 = local_res10 >> 3;
  }
  *(uint *)(*(longlong *)(param_1 + 0x80) + 0x40) = local_res10 | param_3;
  LOCK();
  UNLOCK();
  return;
}



===== PPC_CheckInterrupt @ 1c00066a0 =====

undefined4 PPC_CheckInterrupt(longlong param_1)

{
  uint uVar1;
  byte bVar2;
  
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x80) + 0x30);
  bVar2 = (uVar1 & 0x80000000) != 0;
  if ((uVar1 & 4) != 0) {
    bVar2 = bVar2 | 2;
  }
  if (bVar2 != 0) {
    *(uint *)(*(longlong *)(param_1 + 0x80) + 0xa0) = uVar1;
    LOCK();
    UNLOCK();
  }
  return CONCAT31((int3)((uVar1 & 0x80000000) >> 8),bVar2);
}



===== PPC_EnableInterrupt @ 1c00066f0 =====

undefined4 PPC_EnableInterrupt(longlong param_1)

{
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0xa0) = 0xffffffff;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34) = 0x7ffffffb;
  LOCK();
  UNLOCK();
  return *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34);
}



===== Fusion_DisableInterrupt @ 1c0006730 =====

undefined4 Fusion_DisableInterrupt(longlong param_1)

{
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34) = 0xffffffff;
  LOCK();
  UNLOCK();
  return *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34);
}



===== PPC_ReadRegister @ 1c0006750 =====

undefined4 PPC_ReadRegister(longlong param_1)

{
  return *(undefined4 *)(param_1 + 0xb0);
}



===== Falcon_FireCmd @ 1c0006760 =====

void Falcon_FireCmd(longlong param_1,undefined8 param_2,byte param_3)

{
  uint local_res10;
  undefined4 uStackX_14;
  
  local_res10 = (uint)param_2;
  uStackX_14 = (undefined4)((ulonglong)param_2 >> 0x20);
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0xc4) = uStackX_14;
  LOCK();
  UNLOCK();
  *(uint *)(*(longlong *)(param_1 + 0x80) + 0xc0) = local_res10 | (uint)param_3 * 2 | 1;
  LOCK();
  UNLOCK();
  return;
}



===== Falcon_CheckInterrupt @ 1c00067a0 =====

ulonglong Falcon_CheckInterrupt(longlong param_1)

{
  uint *puVar1;
  ulonglong uVar2;
  
  puVar1 = (uint *)(*(longlong *)(param_1 + 0x80) + 0x30);
  uVar2 = (ulonglong)puVar1 & 0xffffffffffffff00;
  if ((*puVar1 & 1) != 0) {
    uVar2 = CONCAT71((int7)((ulonglong)puVar1 >> 8),1);
    *(uint *)(*(longlong *)(param_1 + 0x80) + 0x30) = *puVar1;
    LOCK();
    UNLOCK();
  }
  return uVar2;
}



===== Falcon_EnableInterrupt @ 1c00067d0 =====

undefined4 Falcon_EnableInterrupt(longlong param_1)

{
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x30) = 0xffffffff;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34) = 0xfffffffe;
  LOCK();
  UNLOCK();
  return *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34);
}



===== Falcon_ReadDoorbell @ 1c0006810 =====

undefined4 Falcon_ReadDoorbell(longlong param_1)

{
  return **(undefined4 **)(param_1 + 0x80);
}



===== Falcon_WriteDoorbell @ 1c0006820 =====

void Falcon_WriteDoorbell(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  LOCK();
  UNLOCK();
  return;
}



===== Liber_CheckInterrupt @ 1c0006830 =====

undefined8 Liber_CheckInterrupt(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  byte bVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x80);
  uVar1 = *(uint *)(lVar2 + 0x30);
  bVar3 = (uVar1 & 1) != 0;
  if ((uVar1 & 4) != 0) {
    bVar3 = bVar3 | 2;
  }
  if (bVar3 != 0) {
    *(uint *)(*(longlong *)(param_1 + 0x80) + 0xa0) = uVar1;
    LOCK();
    UNLOCK();
  }
  return CONCAT71((int7)((ulonglong)lVar2 >> 8),bVar3);
}



===== Liber_EnableInterrupt @ 1c0006880 =====

undefined4 Liber_EnableInterrupt(longlong param_1)

{
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0xa0) = 0xffffffff;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34) = 0xfffffffa;
  LOCK();
  UNLOCK();
  return *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34);
}



===== Fusion_CheckInterrupt @ 1c00068c0 =====

undefined8 Fusion_CheckInterrupt(longlong param_1)

{
  uint uVar1;
  longlong lVar2;
  byte bVar3;
  
  lVar2 = *(longlong *)(param_1 + 0x80);
  uVar1 = *(uint *)(lVar2 + 0x30);
  bVar3 = (uVar1 & 8) != 0;
  if ((uVar1 & 1) != 0) {
    bVar3 = bVar3 | 2;
    *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x30) = 1;
    LOCK();
    UNLOCK();
  }
  return CONCAT71((int7)((ulonglong)lVar2 >> 8),bVar3);
}



===== Fusion_EnableInterrupt @ 1c0006910 =====

undefined4 Fusion_EnableInterrupt(longlong param_1)

{
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x30) = 0xffffffff;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34) = 0xfffffff6;
  LOCK();
  UNLOCK();
  return *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x34);
}



===== Fusion_FireCmd @ 1c0006950 =====

void Fusion_FireCmd(longlong param_1,undefined8 param_2)

{
  *(int *)(*(longlong *)(param_1 + 0x80) + 0xc0) = (int)param_2;
  LOCK();
  UNLOCK();
  *(int *)(*(longlong *)(param_1 + 0x80) + 0xc4) = (int)((ulonglong)param_2 >> 0x20);
  LOCK();
  UNLOCK();
  return;
}



===== Fusion_FireRequest_SRB @ 1c0006990 =====

void Fusion_FireRequest_SRB(longlong param_1,longlong param_2)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(param_2 + 0x570);
  *(int *)(*(longlong *)(param_1 + 0x80) + 0xc0) = (int)uVar1;
  LOCK();
  UNLOCK();
  *(int *)(*(longlong *)(param_1 + 0x80) + 0xc4) = (int)((ulonglong)uVar1 >> 0x20);
  LOCK();
  UNLOCK();
  return;
}



===== Fusion_FireRequest_MFI @ 1c00069c0 =====

void Fusion_FireRequest_MFI(longlong param_1,longlong param_2)

{
  ushort uVar1;
  int local_res8;
  
  uVar1 = *(short *)(param_2 + 0x508) + 1;
  local_res8 = (uint)uVar1 << 0x10;
  MPT_BuildPassthrough
            (param_1,(void *)((ulonglong)uVar1 * 0x100 + *(longlong *)(param_1 + 0x8408)),
             *(undefined8 *)(param_2 + 0x510));
  *(int *)(*(longlong *)(param_1 + 0x80) + 0xc0) = local_res8;
  LOCK();
  UNLOCK();
  *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0xc4) = 0;
  LOCK();
  UNLOCK();
  return;
}



===== MegaSASValidateAndProcessMapInfo @ 1c0006a34 =====

ulonglong MegaSASValidateAndProcessMapInfo(longlong param_1,uint *param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined1 *puVar9;
  uint *puVar10;
  
  uVar8 = param_2[6];
  uVar5 = (ulonglong)uVar8;
  if (uVar8 != 0) {
    uVar5 = (ulonglong)*param_2;
    if (uVar5 != (ulonglong)(uVar8 - 1) * 0x9e0 + 0x3288) {
LAB_1c0006a63:
      return uVar5 & 0xffffffffffffff00;
    }
    uVar8 = 0;
    puVar7 = (undefined1 *)(param_1 + 0x7c08);
    puVar9 = (undefined1 *)(param_1 + 0x6711);
    puVar10 = param_2 + 8;
    do {
      uVar4 = (ulonglong)(byte)*puVar10;
      uVar5 = uVar4;
      if ((byte)*puVar10 < 0x40) {
        lVar6 = uVar4 * 0x9e0;
        if ((param_2[uVar4 * 0x278 + 0xa2a] & 0x800000) != 0) {
          puVar9[-1] = 1;
        }
        uVar3 = param_2[uVar4 * 0x278 + 0xa2a];
        if ((uVar3 & 0x400000) != 0) {
          *puVar9 = 1;
        }
        uVar1 = *(undefined1 *)(lVar6 + 0x28ba + (longlong)param_2);
        uVar5 = (ulonglong)CONCAT31((int3)(uVar3 >> 8),uVar1);
        puVar9[1] = uVar1;
        if ((((*(char *)(lVar6 + 0x28b9 + (longlong)param_2) == '\x01') &&
             (*(char *)(lVar6 + 0x28bb + (longlong)param_2) == '\x02')) &&
            ((char)param_2[uVar4 * 0x278 + 0xa2e] == '\x01')) &&
           (*(char *)(lVar6 + 0x28c2 + (longlong)param_2) == '\x03')) {
          uVar3 = param_2[uVar4 * 0x278 + 0xa58];
          uVar5 = (ulonglong)(ushort)param_2[(ulonglong)(ushort)uVar3 * 0x10 + 0x2a];
          if ((ushort)param_2[(ulonglong)(ushort)uVar3 * 0x10 + 0x2a] == 0xffff) goto LAB_1c0006a63;
          *(short *)(puVar7 + 2) = (short)param_2[uVar5 * 2 + 0x82a];
          uVar2 = *(ushort *)((ulonglong)(ushort)uVar3 * 0x40 + 0xaa + (longlong)param_2);
          uVar5 = (ulonglong)uVar2;
          if (uVar2 == 0xffff) goto LAB_1c0006a63;
          *(short *)(puVar7 + 4) = (short)param_2[uVar5 * 2 + 0x82a];
          *puVar7 = 1;
        }
        else {
          *puVar7 = 0;
        }
      }
      uVar8 = uVar8 + 1;
      puVar9 = puVar9 + 0x40;
      puVar7 = puVar7 + 0x20;
      puVar10 = (uint *)((longlong)puVar10 + 1);
    } while (uVar8 < 0x40);
  }
  return CONCAT71((int7)(uVar5 >> 8),1);
}



===== FUN_1c0006b68 @ 1c0006b68 =====

ulonglong FUN_1c0006b68(longlong param_1,ulonglong param_2,ulonglong param_3,longlong *param_4,
                       byte *param_5)

{
  byte bVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  ulonglong *puVar6;
  ulonglong *puVar7;
  byte bVar8;
  longlong lVar9;
  
  uVar3 = param_2 & 0xffffffff;
  bVar8 = 0;
  lVar9 = uVar3 * 0x9e0;
  bVar1 = *(byte *)(lVar9 + 0x28b8 + param_1);
  if (bVar1 != 0) {
    puVar7 = (ulonglong *)(param_1 + 0x2970 + lVar9);
    do {
      uVar4 = 0;
      if ((uint)puVar7[-1] != 0) {
        puVar6 = puVar7;
        do {
          uVar5 = (ulonglong)(uint)puVar6[3];
          if ((uint)puVar6[3] == 0) goto LAB_1c0006bf9;
          uVar2 = *puVar6;
          if (((uVar2 <= param_3) && (param_3 <= puVar6[1])) &&
             (uVar3 = (param_3 - uVar2) / uVar5, (param_3 - uVar2) % uVar5 == 0)) {
            lVar9 = (param_3 - uVar2) / uVar5 + puVar6[2] <<
                    (*(byte *)(lVar9 + 0x28ba + param_1) & 0x3f);
            *param_4 = lVar9;
            *param_5 = bVar8;
            return CONCAT71((int7)((ulonglong)lVar9 >> 8),1);
          }
          uVar4 = uVar4 + 1;
          puVar6 = puVar6 + 4;
        } while (uVar4 < (uint)puVar7[-1]);
      }
      bVar8 = bVar8 + 1;
      puVar7 = puVar7 + 0x25;
    } while (bVar8 < bVar1);
  }
LAB_1c0006bf9:
  return uVar3 & 0xffffffffffffff00;
}



===== FUN_1c0006c40 @ 1c0006c40 =====

ulonglong FUN_1c0006c40(longlong param_1,uint param_2,ulonglong param_3,ushort param_4,
                       longlong *param_5,undefined2 *param_6,longlong param_7)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  ulonglong uVar5;
  longlong lVar6;
  undefined2 *puVar7;
  longlong lVar8;
  uint uVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong lVar12;
  byte local_res10 [8];
  
  lVar11 = (ulonglong)param_2 * 0x9e0;
  bVar1 = *(byte *)(lVar11 + 0x28bc + param_1);
  uVar5 = (ulonglong)CONCAT31((int3)(param_2 >> 8),bVar1);
  bVar2 = *(byte *)(lVar11 + 0x28bb + param_1);
  bVar3 = *(byte *)(lVar11 + 0x28c4 + param_1);
  if (((bVar1 == 0) || (bVar2 == 0)) || (bVar3 == 0)) {
LAB_1c0006df1:
    uVar5 = uVar5 & 0xffffffffffffff00;
  }
  else {
    uVar5 = param_3 / bVar1;
    if (*(char *)(lVar11 + 0x28b9 + param_1) == '\x06') {
      uVar9 = ((uint)bVar2 - (int)(uVar5 % (ulonglong)bVar2)) + (int)(param_3 % (ulonglong)bVar1);
      uVar10 = (ulonglong)uVar9;
      if (bVar2 <= uVar9) {
        uVar10 = (ulonglong)(uVar9 - bVar2);
      }
    }
    else {
      uVar10 = (ulonglong)*(byte *)(param_3 % (ulonglong)bVar3 + lVar11 + 0x2928 + param_1);
    }
    if (*(char *)(lVar11 + 0x28b8 + param_1) == '\x01') {
      *param_5 = uVar5 << (*(byte *)(lVar11 + 0x28ba + param_1) & 0x3f);
      local_res10[0] = 0;
    }
    else {
      uVar5 = FUN_1c0006b68(param_1,(ulonglong)param_2,uVar5,param_5,local_res10);
      if ((char)uVar5 == '\0') goto LAB_1c0006df1;
    }
    lVar12 = (ulonglong)local_res10[0] * 0x128 + lVar11;
    lVar8 = (ulonglong)*(ushort *)(lVar12 + 0x2960 + param_1) * 0x20;
    lVar6 = (uVar10 & 0xff) + lVar8;
    uVar4 = *(ushort *)(param_1 + 0xa8 + lVar6 * 2);
    if (uVar4 == 0xffff) {
      bVar1 = *(byte *)(lVar11 + 0x28b9 + param_1);
      puVar7 = (undefined2 *)CONCAT71((int7)((ulonglong)lVar6 >> 8),bVar1);
      *param_6 = 0xffff;
      if (bVar1 < 5) {
        if (bVar1 == 1) {
          uVar9 = ((uint)uVar10 & 0xff) + 1;
          puVar7 = (undefined2 *)(ulonglong)uVar9;
          uVar4 = *(ushort *)(param_1 + 0xa8 + ((ulonglong)uVar9 + lVar8) * 2);
          if (uVar4 != 0xffff) {
            *param_6 = *(undefined2 *)(param_1 + 0x20a8 + (ulonglong)uVar4 * 8);
          }
        }
      }
      else {
        *(undefined1 *)(param_7 + 4) = 3;
      }
    }
    else {
      *param_6 = *(undefined2 *)(param_1 + 0x20a8 + (ulonglong)uVar4 * 8);
      puVar7 = param_6;
    }
    uVar5 = CONCAT71((int7)((ulonglong)puVar7 >> 8),1);
    *param_5 = *param_5 + *(longlong *)(lVar12 + 0x2950 + param_1) + (ulonglong)param_4;
    *(byte *)(param_7 + 0x1c) = local_res10[0] << 5 | (byte)uVar10;
  }
  return uVar5;
}



===== MegaSASBuildRaidContext @ 1c0006e0c =====

ulonglong MegaSASBuildRaidContext
                    (undefined8 param_1,longlong param_2,ulonglong param_3,uint param_4,uint param_5
                    ,char param_6,char param_7,longlong *param_8,longlong param_9,short *param_10,
                    char *param_11,undefined1 *param_12,longlong *param_13)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  uint uVar7;
  byte bVar8;
  ulonglong uVar9;
  longlong lVar10;
  uint uVar11;
  longlong lVar12;
  ushort uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  byte bVar17;
  ushort uVar18;
  
  bVar1 = *(byte *)((ulonglong)param_5 + 0x20 + param_2);
  puVar6 = (undefined1 *)(ulonglong)bVar1;
  if (0x3f < bVar1) {
    *param_12 = 1;
    puVar6 = param_12;
    goto LAB_1c0006e50;
  }
  lVar10 = (longlong)puVar6 * 0x9e0;
  *param_12 = 0;
  bVar2 = *(byte *)(lVar10 + 0x28ba + param_2);
  bVar8 = *(byte *)(lVar10 + 0x28bc + param_2);
  uVar11 = 1 << (bVar2 & 0x1f);
  uVar13 = (short)uVar11 - 1;
  if (bVar8 == 0) goto LAB_1c0006e50;
  uVar9 = param_3 >> (bVar2 & 0x3f);
  uVar15 = (param_3 - 1) + (ulonglong)param_4;
  uVar16 = uVar15 >> (bVar2 & 0x3f);
  uVar14 = (ulonglong)bVar8;
  uVar18 = uVar13 & (ushort)param_3;
  uVar4 = uVar9 / uVar14;
  bVar17 = ((char)uVar16 - (char)uVar9) + 1;
  lVar12 = uVar4 << (bVar2 & 0x3f);
  bVar8 = ((char)(uVar16 / uVar14) - (char)uVar4) + 1;
  if (bVar8 == 1) {
    if (bVar17 == 1) {
      lVar12 = lVar12 + (ulonglong)uVar18;
      uVar11 = param_4;
    }
  }
  else {
    uVar7 = uVar11;
    if (uVar9 == (uVar4 + 1) * uVar14 - 1) {
      lVar12 = lVar12 + (ulonglong)uVar18;
      uVar7 = uVar11 - uVar18;
    }
    if (2 < bVar8) {
      uVar7 = uVar7 + (bVar8 - 2 << (bVar2 & 0x1f));
    }
    if (uVar16 == uVar14 * (uVar16 / uVar14)) {
      uVar11 = uVar7 + ((ushort)uVar15 & uVar13) + 1;
    }
    else {
      uVar11 = uVar7 + uVar11;
    }
  }
  if (param_7 == '\0') {
    uVar3 = 1;
    if (param_6 == '\0') goto LAB_1c0006f80;
  }
  else if (param_6 == '\0') {
LAB_1c0006f80:
    uVar3 = *(undefined1 *)(lVar10 + 0x28c3 + param_2);
  }
  else {
    uVar3 = *(undefined1 *)(lVar10 + 0x28c5 + param_2);
  }
  *(undefined1 *)(param_9 + 4) = uVar3;
  bVar2 = *(byte *)(lVar10 + 0x28d4 + param_2);
  if (bVar2 == 0) {
    bVar2 = *(byte *)(param_2 + 0xa0);
  }
  *(ushort *)(param_9 + 2) = (ushort)bVar2;
  *(undefined2 *)(param_9 + 6) = *(undefined2 *)(lVar10 + 0x28c0 + param_2);
  *(longlong *)(param_9 + 8) = lVar12;
  *(uint *)(param_9 + 0x10) = uVar11;
  *(undefined2 *)(param_9 + 0x1a) = *(undefined2 *)(lVar10 + 0x28c6 + param_2);
  *param_13 = param_2 + 0x28cc + lVar10;
  uVar13 = *(ushort *)(lVar10 + 0x28c0 + param_2);
  puVar6 = (undefined1 *)(ulonglong)uVar13;
  if (uVar13 != param_5) {
LAB_1c0006e50:
    return (ulonglong)puVar6 & 0xffffffffffffff00;
  }
  uVar11 = *(uint *)(lVar10 + 0x28a8 + param_2);
  puVar6 = (undefined1 *)(ulonglong)uVar11;
  if ((uVar11 & 1) == 0) {
    *param_11 = '\0';
    goto LAB_1c000704d;
  }
  if (param_6 == '\0') {
    if ((uVar11 >> 0x14 & 1) != 0) {
      if (bVar17 != 1) {
        uVar4 = (ulonglong)puVar6 & 0x400000;
        goto LAB_1c000702d;
      }
      goto LAB_1c000702f;
    }
LAB_1c0007033:
    puVar6 = (undefined1 *)0x0;
  }
  else {
    if ((uVar11 >> 0x15 & 1) == 0) goto LAB_1c0007033;
    if (bVar17 != 1) {
      uVar4 = (ulonglong)puVar6 & 0x800000;
LAB_1c000702d:
      if (uVar4 == 0) goto LAB_1c0007033;
    }
LAB_1c000702f:
    puVar6 = (undefined1 *)0x1;
  }
  *param_11 = (char)puVar6;
LAB_1c000704d:
  if (*param_11 != '\0') {
    uVar5 = FUN_1c0006c40(param_2,(uint)bVar1,uVar9,uVar18,param_8,param_10,param_9);
    if (*param_10 == -1) {
      *param_11 = '\0';
      return uVar5;
    }
    return uVar5;
  }
  if ((param_6 != '\0') && (uVar11 = 0, bVar17 != 0)) {
    do {
      puVar6 = (undefined1 *)
               FUN_1c0006c40(param_2,(uint)bVar1,uVar11 + uVar9,uVar18,param_8,param_10,param_9);
      if ((char)puVar6 == '\0') goto LAB_1c0006e50;
      uVar11 = uVar11 + 1;
    } while (uVar11 < bVar17);
  }
  return CONCAT71((int7)((ulonglong)puVar6 >> 8),1);
}



===== InitDPC @ 1c0007110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 InitDPC(longlong param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  
  lVar3 = param_1 + 0x7718;
  lVar2 = 0x10;
  do {
    StorPortNotification(0x1001,param_1,lVar3,FUN_1c0007320);
    lVar3 = lVar3 + 0x48;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  *(undefined1 *)(param_1 + 0x7bbe) = 0;
  uVar1 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x20))(param_1);
  return CONCAT71((int7)((ulonglong)uVar1 >> 8),1);
}



===== LegacyInterrupts @ 1c0007180 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined1 LegacyInterrupts(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  byte bVar1;
  char cVar2;
  undefined8 uVar3;
  
  if ((*(char *)(param_1 + 0x76e9) == '\0') || (*(char *)(param_1 + 0x88) == '\0')) {
    bVar1 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x18))();
    if (bVar1 == 0) {
      return 0;
    }
    if (*(char *)(param_1 + 0x7bbe) != '\0') {
      return 1;
    }
    if (*(char *)(param_1 + 0x7bbd) != '\0') {
      return 1;
    }
    if ((bVar1 & 2) == 0) goto LAB_1c00071e9;
    uVar3 = CheckFirmwareFault(param_1,param_2,param_3);
    cVar2 = (char)uVar3;
  }
  else {
    if (*(char *)(param_1 + 0x7bbe) != '\0') {
      return 1;
    }
    cVar2 = *(char *)(param_1 + 0x7bbd);
  }
  if (cVar2 != '\0') {
    return 1;
  }
LAB_1c00071e9:
  FUN_1c0007228(param_1,0);
  return 1;
}



===== MessageInterrupts @ 1c0007200 =====

undefined1 MessageInterrupts(longlong param_1,byte param_2)

{
  if ((*(char *)(param_1 + 0x7bbe) == '\0') && (*(char *)(param_1 + 0x7bbd) == '\0')) {
    FUN_1c0007228(param_1,(ulonglong)param_2);
  }
  return 1;
}



===== FUN_1c0007228 @ 1c0007228 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FUN_1c0007228(longlong param_1,ulonglong param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 local_res8 [2];
  
  cVar3 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x10))();
  if ((cVar3 != '\0') && (*(char *)(param_1 + 0x88) == '\0')) {
    if (*(char *)(param_1 + 0x7bbc) != '\0') {
      if (*(int *)(param_1 + 0x21c0) == 0) {
        *(undefined1 *)(param_1 + 0x7bbc) = 0;
        StorPortResume(param_1);
        StorPortReady(param_1);
      }
      if (*(char *)(param_1 + 0x7bbc) != '\0') {
        return;
      }
    }
    if ((((*(longlong *)(param_1 + 0x2198) != 0) || (*(char *)(param_1 + 0x76e8) != '\0')) ||
        (*(char *)(param_1 + 0x7b98) != '\0')) ||
       ((*(char *)(param_1 + 0x7b99) != '\0' || ((*(uint *)(param_1 + 0x7b9c) & 5) != 0)))) {
      LOCK();
      piVar1 = (int *)(param_1 + 0x7ba0);
      iVar2 = *piVar1;
      *piVar1 = *piVar1 + 1;
      UNLOCK();
      if (iVar2 == 0) {
        local_res8[0] = 0;
        StorPortNotification
                  (0x1002,param_1,param_1 + ((param_2 & 0xffffffff) * 9 + 0xee3) * 8,param_1,param_1
                   ,local_res8);
      }
    }
  }
  return;
}



===== FUN_1c0007320 @ 1c0007320 =====

void FUN_1c0007320(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined1 local_28 [32];
  
  *(undefined4 *)(param_2 + 0x7ba0) = 0;
  MemFastZero(local_28,0x20);
  StorPortNotification(0x1003,param_2,2,0,local_28);
  if (*(char *)(param_2 + 0x7b99) != '\0') {
    *(undefined1 *)(param_2 + 0x7b99) = 0;
    IssueDCMD(param_2,0x300e101);
  }
  if (*(char *)(param_2 + 0x7b98) != '\0') {
    if ((((*(char *)(param_2 + 0x89) != '\0') && (*(char *)(param_2 + 0x7b9a) != '\0')) &&
        ((*(char *)(param_2 + 0x7bc5) != '\0' || (*(char *)(param_2 + 0x7bc4) != '\0')))) &&
       (*(undefined1 *)(param_2 + 0x7b9a) = 0, *(char *)(param_2 + 0x7bc6) == '\0')) {
      *(undefined1 *)(param_2 + 0x7bc6) = 1;
      iVar3 = 0x3150200;
      if (*(int *)(param_2 + 0x8a3c) != 2) {
        iVar3 = 0x3200200;
      }
      IssueDCMD(param_2,iVar3);
    }
    *(undefined1 *)(param_2 + 0x7b98) = 0;
    IssueDCMD(param_2,0x1040500);
  }
  if (*(int *)(param_2 + 0x7b9c) == 1) {
    *(undefined4 *)(param_2 + 0x7b9c) = 2;
    IssueDCMD(param_2,0x2010100);
  }
  if (*(int *)(param_2 + 0x7b9c) == 4) {
    *(undefined4 *)(param_2 + 0x7b9c) = 0;
    CompletePDquery(param_2);
  }
  lVar1 = *(longlong *)(param_2 + 0x2198);
  if (lVar1 != 0) {
    *(undefined8 *)(param_2 + 0x2198) = 0;
    uVar2 = FUN_1c00042b4(param_2,lVar1);
    if ((char)uVar2 == '\0') {
      *(longlong *)(param_2 + 0x2198) = lVar1;
    }
  }
  if (*(char *)(param_2 + 0x76e8) != '\0') {
    TryFlushingGroups(param_2);
  }
  StorPortNotification(0x1004,param_2,local_28);
  return;
}



===== CompleteScsiRequest @ 1c0007488 =====

void CompleteScsiRequest(longlong param_1,longlong param_2,byte param_3,char param_4)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  
  lVar5 = *(longlong *)(param_2 + 0x500);
  if ((((*(char *)(lVar5 + 0x48) == '\x12') && (*(char *)(lVar5 + 5) == '\x01')) &&
      (*(char *)(lVar5 + 0x49) == '\0')) &&
     ((*(char *)(lVar5 + 0x4a) == '\0' && (*(char *)(lVar5 + 0x4d) == '\0')))) {
    if (param_3 == 0) {
      *(undefined1 *)((ulonglong)*(byte *)(lVar5 + 6) + 0x8518 + param_1) = 1;
    }
    else {
      *(undefined1 *)((ulonglong)*(byte *)(lVar5 + 6) + 0x8518 + param_1) = 0;
    }
    if (*(char *)(lVar5 + 6) == -2) {
      *(undefined1 *)(param_1 + 0x8510) = 1;
    }
  }
  if (*(char *)(param_2 + 0x54d) != '\0') {
    lVar5 = (ulonglong)*(byte *)(lVar5 + 6) * 0x40;
    LOCK();
    piVar2 = (int *)(lVar5 + 0x6700 + param_1);
    iVar3 = *piVar2;
    *piVar2 = *piVar2 + -1;
    UNLOCK();
    if (iVar3 + -1 < 1) {
      *(undefined1 *)(lVar5 + 0x66f1 + param_1) = 1;
      *(undefined1 *)(param_1 + 0x76e8) = 1;
    }
  }
  puVar1 = (undefined8 *)
           (*(longlong *)(param_1 + 0x158) + (ulonglong)*(uint *)(param_2 + 0x508) * 0x12);
  do {
    lVar5 = *(longlong *)(param_2 + 0x500);
    if (((*(char *)(param_2 + 0x518) == '\0') && (*(char *)(param_2 + 0x519) == '\0')) &&
       ((param_3 == 0 &&
        ((uVar4 = *(uint *)(param_2 + 0x548), uVar4 != 0 && (*(uint *)(lVar5 + 0x10) != uVar4))))))
    {
      if (uVar4 < *(uint *)(lVar5 + 0x10)) {
        *(uint *)(lVar5 + 0x10) = uVar4;
      }
      *(undefined1 *)(lVar5 + 3) = 0x12;
    }
    else if (param_3 < 0x23) {
      if (param_3 == 0x22) {
LAB_1c0007602:
        *(undefined1 *)(lVar5 + 3) = 8;
      }
      else if (param_3 == 0) {
        *(undefined1 *)(lVar5 + 3) = 1;
      }
      else if (param_3 == 0) {
LAB_1c00075f0:
        *(undefined1 *)(lVar5 + 3) = 4;
      }
      else {
        if (4 < param_3) {
          if (param_3 == 0xc) goto LAB_1c0007602;
          if (param_3 == 0x18) {
            *(undefined2 *)(lVar5 + 3) = 0x204;
            goto LAB_1c000768d;
          }
          if (param_3 != 0x19) goto LAB_1c00075f0;
        }
LAB_1c00075b6:
        *(undefined1 *)(lVar5 + 3) = 6;
        *(char *)(lVar5 + 4) = param_4;
      }
    }
    else if (param_3 == 0x2d) {
      *(undefined1 *)(lVar5 + 3) = 4;
      *(char *)(lVar5 + 4) = param_4;
      if (((*(char *)(param_1 + 0x88) == '\0') && (param_4 == '\x02')) &&
         (*(undefined8 **)(lVar5 + 0x20) != (undefined8 *)0x0)) {
        if ((*(uint *)(lVar5 + 0xc) & 0x20) == 0) {
          uVar4 = (uint)*(byte *)(lVar5 + 0xb);
          if (0x11 < *(byte *)(lVar5 + 0xb)) {
            uVar4 = 0x12;
          }
          MemFastMove(*(undefined8 **)(lVar5 + 0x20),puVar1,uVar4);
          *(byte *)(lVar5 + 3) = *(byte *)(lVar5 + 3) | 0x80;
        }
        if (((*(byte *)((longlong)puVar1 + 2) & 0xf) == 6) &&
           (*(char *)((longlong)puVar1 + 0xc) == ')')) {
          StorPortNotification(7,param_1);
          StorPortNotification(7,param_1);
        }
      }
    }
    else {
      if (param_3 == 0x2e) goto LAB_1c00075b6;
      if (param_3 == 0x2f) {
        *(undefined2 *)(lVar5 + 3) = 0x1804;
      }
      else {
        if (param_3 == 0x33) goto LAB_1c0007602;
        if (param_3 != 0x67) goto LAB_1c00075f0;
        *(undefined1 *)(lVar5 + 3) = 5;
      }
    }
LAB_1c000768d:
    param_2 = *(longlong *)(param_2 + 0x550);
    StorPortNotification(0,param_1);
    if (param_2 == 0) {
      return;
    }
  } while( true );
}



===== SetDeviceQueueDepths @ 1c00076c4 =====

void SetDeviceQueueDepths(longlong param_1)

{
  undefined4 uVar1;
  char cVar2;
  char *pcVar3;
  longlong lVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint *puVar9;
  
  if (*(char *)(param_1 + 0x8511) == '\0') {
    pcVar6 = (char *)(param_1 + 0x8518);
    uVar7 = 0;
    lVar4 = 0xff;
    pcVar3 = pcVar6;
    do {
      if (*pcVar3 != '\0') {
        uVar7 = uVar7 + 1;
      }
      pcVar3 = pcVar3 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    if (uVar7 != 0) {
      puVar9 = (uint *)(param_1 + 0x8618);
      uVar7 = *(uint *)(param_1 + 0x66c0) / uVar7;
      if (0xfe < uVar7) {
        uVar7 = 0xfe;
      }
      uVar5 = 0;
      *(uint *)(param_1 + 0x8514) = uVar7;
      do {
        if (*pcVar6 != '\0') {
          cVar2 = StorPortSetDeviceQueueDepth(param_1,1,(char)uVar5,0,uVar7);
          if (cVar2 != '\0') {
            *puVar9 = uVar7;
          }
        }
        uVar5 = uVar5 + 1;
        puVar9 = puVar9 + 1;
        pcVar6 = pcVar6 + 1;
      } while (uVar5 < 0xff);
    }
  }
  else if (*(char *)(param_1 + 0x8511) == '\x01') {
    uVar7 = 0;
    pcVar6 = (char *)(param_1 + 0x8518);
    puVar8 = (undefined4 *)(param_1 + 0x8618);
    do {
      if (*pcVar6 != '\0') {
        uVar1 = *(undefined4 *)(param_1 + 0x8514);
        cVar2 = StorPortSetDeviceQueueDepth(param_1,1,(char)uVar7,0,uVar1);
        if (cVar2 != '\0') {
          *puVar8 = uVar1;
        }
      }
      uVar7 = uVar7 + 1;
      puVar8 = puVar8 + 1;
      pcVar6 = pcVar6 + 1;
    } while (uVar7 < 0xff);
  }
  return;
}



===== MegaSASIoctl @ 1c00077d4 =====

ulonglong MegaSASIoctl(longlong param_1,longlong param_2)

{
  uint uVar1;
  ulonglong in_RAX;
  ulonglong uVar2;
  char *pcVar3;
  longlong lVar4;
  
  lVar4 = *(longlong *)(param_2 + 0x18);
  if (((*(char *)(param_1 + 0x89) != '\0') && (*(char *)(param_1 + 0x7bc2) == '\0')) ||
     (*(uint *)(param_2 + 0x10) < 0xbc)) {
    *(undefined1 *)(param_2 + 3) = 6;
    *(undefined4 *)(lVar4 + 0x14) = 1;
    goto LAB_1c0007964;
  }
  pcVar3 = (char *)(lVar4 + 4);
  if (((((*pcVar3 != 'L') || (*(char *)(lVar4 + 5) != 'S')) ||
       ((*(char *)(lVar4 + 6) != 'I' ||
        ((*(char *)(lVar4 + 7) != 'L' || (*(char *)(lVar4 + 8) != 'O')))))) ||
      (*(char *)(lVar4 + 9) != 'G')) ||
     ((*(char *)(lVar4 + 10) != 'I' || (*(char *)(lVar4 + 0xb) != 'C')))) {
    *(undefined1 *)(param_2 + 3) = 6;
    *(undefined4 *)(lVar4 + 0x14) = 1;
    in_RAX = MemFastZero(pcVar3,8);
    goto LAB_1c0007964;
  }
  MemFastZero(pcVar3,8);
  if ((*(int *)(lVar4 + 0x10) + 0xfff0000U & 0xfffeffff) != 0) {
LAB_1c00078ba:
    uVar2 = FUN_1c0007a60(param_1,param_2);
    return uVar2;
  }
  lVar4 = *(longlong *)(param_2 + 0x18);
  uVar1 = *(uint *)(lVar4 + 0x34);
  in_RAX = (ulonglong)uVar1;
  if (uVar1 == 0xf0010100) {
    if (299 < *(uint *)(param_2 + 0x10)) {
      pcVar3 = s_LSILOGIC_1c000c520;
LAB_1c0007929:
      in_RAX = MemFastMove((undefined8 *)(lVar4 + 0xbc),(undefined8 *)pcVar3,0x70);
LAB_1c00078ee:
      *(undefined1 *)(lVar4 + 0x1e) = 0;
      goto LAB_1c0007964;
    }
  }
  else if (uVar1 == 0xf0010200) {
    if (299 < *(uint *)(param_2 + 0x10)) {
      pcVar3 = (char *)(param_1 + 4);
      goto LAB_1c0007929;
    }
  }
  else if (uVar1 != 0xf0010300) {
    if (uVar1 == 0xf0020100) {
      *(undefined1 *)(lVar4 + 0x1e) = 0;
      in_RAX = StorPortNotification(7,param_1,*(undefined1 *)(lVar4 + 0x38));
      goto LAB_1c0007964;
    }
    if (uVar1 == 0xf0020200) {
      uVar2 = FUN_1c0007978(param_1,param_2);
      return uVar2;
    }
    if (uVar1 != 0xf0020300) goto LAB_1c00078ba;
    if (*(uint *)(param_2 + 0x10) < 0xc0) goto LAB_1c00078d3;
    in_RAX = (ulonglong)*(uint *)(param_1 + 0x74);
    *(uint *)(lVar4 + 0xbc) = *(uint *)(param_1 + 0x74);
    goto LAB_1c00078ee;
  }
LAB_1c00078d3:
  *(undefined1 *)(param_2 + 3) = 6;
  *(undefined4 *)(lVar4 + 0x14) = 1;
LAB_1c0007964:
  return in_RAX & 0xffffffffffffff00;
}



===== FUN_1c0007978 @ 1c0007978 =====

ulonglong FUN_1c0007978(longlong param_1,longlong param_2)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  ushort uVar7;
  ulonglong in_RAX;
  undefined1 *puVar8;
  undefined8 uVar9;
  undefined4 local_res10;
  
  lVar5 = *(longlong *)(param_2 + 0x18);
  if (*(uint *)(param_2 + 0x10) < 0xc0) {
    *(undefined1 *)(param_2 + 3) = 6;
    *(undefined4 *)(lVar5 + 0x14) = 1;
  }
  else {
    uVar3 = *(ushort *)(param_1 + 0x666c);
    cVar1 = *(char *)(param_1 + 0x666f);
    uVar7 = *(ushort *)(lVar5 + 0xbc) ^ uVar3;
    in_RAX = (ulonglong)uVar7;
    cVar2 = *(char *)(lVar5 + 0xbf);
    local_res10._0_3_ = (uint3)uVar3;
    local_res10 = CONCAT13(cVar1,(uint3)local_res10);
    if (uVar7 != 0) {
      local_res10 = CONCAT22(local_res10._2_2_,uVar3 | *(ushort *)(lVar5 + 0xbc));
      in_RAX = (ulonglong)local_res10;
      *(uint *)(param_1 + 0x666c) = local_res10;
    }
    if (cVar2 < cVar1) {
      local_res10 = CONCAT13(cVar2,(uint3)local_res10);
      in_RAX = (ulonglong)local_res10;
      *(uint *)(param_1 + 0x666c) = local_res10;
    }
    if (cVar2 < cVar1 || uVar7 != 0) {
      uVar6 = *(undefined8 *)(param_1 + 0x108);
      puVar8 = ClearSRBExtension(param_1,param_2);
      uVar9 = MemFastZero(puVar8,0x28);
      *puVar8 = 6;
      iVar4 = *(int *)(param_1 + 0x66bc);
      *(undefined8 *)(puVar8 + 0x20) = uVar6;
      *(int *)(puVar8 + 0x18) = iVar4 + -2;
      return CONCAT71((int7)((ulonglong)uVar9 >> 8),1);
    }
    *(undefined1 *)(lVar5 + 0x1e) = 0;
  }
  return in_RAX & 0xffffffffffffff00;
}



===== FUN_1c0007a60 @ 1c0007a60 =====

ulonglong FUN_1c0007a60(longlong param_1,longlong param_2)

{
  byte *pbVar1;
  longlong lVar2;
  byte *pbVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  longlong lVar9;
  undefined1 local_res18 [16];
  
  pbVar3 = ClearSRBExtension(param_1,param_2);
  lVar2 = *(longlong *)(param_2 + 0x18);
  pbVar1 = (byte *)(lVar2 + 0x1c);
  bVar8 = *pbVar1;
  uVar4 = CONCAT71((int7)((ulonglong)pbVar3 >> 8),bVar8);
  lVar9 = lVar2 + 0xbc;
  if ((byte)(bVar8 - 3) < 2) {
    MemFastMove((undefined8 *)pbVar3,(undefined8 *)pbVar1,0x40);
    pbVar3[0x10] = 0;
    pbVar3[0x11] = 0;
    pbVar3[8] = 0;
    pbVar3[9] = 0;
    pbVar3[10] = 0;
    pbVar3[0xb] = 0;
    pbVar3[0xc] = 0;
    pbVar3[0xd] = 0;
    pbVar3[0xe] = 0;
    pbVar3[0xf] = 0;
    *(byte **)(pbVar3 + 0x540) = pbVar3 + 0x30;
    *(byte **)(pbVar3 + 0x538) = pbVar3 + 0x30;
    uVar4 = BuildSGLforIOCTL(param_1,(longlong)pbVar3,lVar9,*(uint *)(lVar2 + 0x30));
    if ((char)uVar4 != '\0') {
      *(ushort *)(pbVar3 + 0x10) =
           *(ushort *)(pbVar3 + 0x10) ^
           ((ushort)(pbVar3[0x51a] != 0) * 2 ^ *(ushort *)(pbVar3 + 0x10)) & 2;
      pbVar3[7] = pbVar3[0x534];
      if (pbVar3[0x534] != 0) {
        uVar7 = *(int *)(&DAT_1c000b230 + (ulonglong)*pbVar1 * 4) + 0x3f +
                (uint)pbVar3[0x535] * (uint)pbVar3[0x534] >> 6;
        bVar8 = 7;
        if ((int)((uVar7 & 0xff) - 1) < 7) {
          bVar8 = (char)uVar7 - 1;
        }
        pbVar3[0x559] = bVar8;
      }
      uVar5 = 0;
      if (*(char *)(lVar2 + 0x1d) != '\0') {
        uVar5 = StorPortGetPhysicalAddress(param_1,param_2,lVar2 + 0x9c,local_res18);
        if (0 < (int)((ulonglong)uVar5 >> 0x20)) {
          *(ushort *)(pbVar3 + 0x10) = *(ushort *)(pbVar3 + 0x10) | 4;
        }
        *(undefined8 *)(pbVar3 + 0x18) = uVar5;
      }
      goto LAB_1c0007d99;
    }
  }
  else if (bVar8 == 5) {
    MemFastMove((undefined8 *)pbVar3,(undefined8 *)pbVar1,0x40);
    *(undefined4 *)(pbVar3 + 0x18) = *(undefined4 *)(lVar2 + 0x34);
    *(undefined4 *)(pbVar3 + 0x1c) = *(undefined4 *)(lVar2 + 0x38);
    *(undefined4 *)(pbVar3 + 0x20) = *(undefined4 *)(lVar2 + 0x3c);
    *(undefined4 *)(pbVar3 + 0x24) = *(undefined4 *)(lVar2 + 0x40);
    pbVar3[0x10] = 0;
    pbVar3[0x11] = 0;
    pbVar3[8] = 0;
    pbVar3[9] = 0;
    pbVar3[10] = 0;
    pbVar3[0xb] = 0;
    *(byte **)(pbVar3 + 0x540) = pbVar3 + 0x28;
    *(byte **)(pbVar3 + 0x538) = pbVar3 + 0x28;
    uVar4 = BuildSGLforIOCTL(param_1,(longlong)pbVar3,lVar9,*(uint *)(lVar2 + 0x30));
    if ((char)uVar4 != '\0') {
      *(ushort *)(pbVar3 + 0x10) =
           *(ushort *)(pbVar3 + 0x10) ^
           ((ushort)(pbVar3[0x51a] != 0) * 2 ^ *(ushort *)(pbVar3 + 0x10)) & 2;
      bVar8 = pbVar3[0x534];
      pbVar3[7] = bVar8;
joined_r0x0001c0007b33:
      uVar5 = 0;
      if (bVar8 != 0) {
        uVar7 = *(int *)(&DAT_1c000b230 + (ulonglong)*pbVar3 * 4) +
                (uint)pbVar3[0x535] * (uint)pbVar3[0x534] + 0x3f >> 6;
        uVar5 = 0;
        bVar8 = 7;
        if ((int)((uVar7 & 0xff) - 1) < 7) {
          bVar8 = (char)uVar7 - 1;
        }
        pbVar3[0x559] = bVar8;
      }
LAB_1c0007d99:
      pbVar3[0x558] = 1;
      return CONCAT71((int7)((ulonglong)uVar5 >> 8),1);
    }
  }
  else if (bVar8 == 7) {
    MemFastMove((undefined8 *)pbVar3,(undefined8 *)pbVar1,0x38);
    *(undefined2 *)(lVar2 + 0x2c) = 0;
    *(undefined8 *)(lVar2 + 0x24) = 0;
    *(byte **)(pbVar3 + 0x540) = pbVar3 + 0x20;
    *(byte **)(pbVar3 + 0x538) = pbVar3 + 0x20;
    uVar4 = BuildSGLforIOCTL(param_1,(longlong)pbVar3,lVar9,*(uint *)(lVar2 + 0x30));
    if ((char)uVar4 != '\0') {
      lVar9 = lVar2 + 0xbc + (ulonglong)*(uint *)(lVar2 + 0x30);
      uVar7 = (*(int *)(param_2 + 0x10) - *(uint *)(lVar2 + 0x30)) - 0xbc;
LAB_1c0007bb1:
      uVar4 = BuildSGLforIOCTL(param_1,(longlong)pbVar3,lVar9,uVar7);
      if ((char)uVar4 != '\0') {
        *(ushort *)(pbVar3 + 0x10) =
             *(ushort *)(pbVar3 + 0x10) ^
             ((ushort)(pbVar3[0x51a] != 0) * 2 ^ *(ushort *)(pbVar3 + 0x10)) & 2;
        bVar8 = pbVar3[0x534];
        pbVar3[7] = bVar8;
        goto joined_r0x0001c0007b33;
      }
    }
  }
  else {
    if (bVar8 != 8) {
      *(undefined1 *)(param_2 + 3) = 6;
      *(undefined4 *)(lVar2 + 0x14) = 1;
      goto LAB_1c0007cf6;
    }
    MemFastMove((undefined8 *)pbVar3,(undefined8 *)pbVar1,0x40);
    *(undefined2 *)(lVar2 + 0x2c) = 0;
    *(undefined8 *)(lVar2 + 0x24) = 0;
    *(byte **)(pbVar3 + 0x540) = pbVar3 + 0x30;
    *(byte **)(pbVar3 + 0x538) = pbVar3 + 0x30;
    uVar6 = (*(int *)(param_2 + 0x10) - *(int *)(lVar2 + 0x30)) - 0xbc;
    uVar4 = BuildSGLforIOCTL(param_1,(longlong)pbVar3,lVar9,uVar6);
    if ((char)uVar4 != '\0') {
      uVar7 = *(uint *)(lVar2 + 0x30);
      lVar9 = (ulonglong)uVar6 + 0xbc + lVar2;
      goto LAB_1c0007bb1;
    }
  }
  *(undefined1 *)(param_2 + 3) = 0x12;
LAB_1c0007cf6:
  return uVar4 & 0xffffffffffffff00;
}



===== UpdateIOMetric @ 1c0007db8 =====

void UpdateIOMetric(longlong param_1,byte param_2,char param_3,ulonglong param_4,uint param_5)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  int *piVar4;
  int *piVar5;
  ulonglong uVar6;
  
  if ((*(char *)(param_1 + 0x25f8) != '\0') && (param_2 < 0x40)) {
    uVar6 = (ulonglong)param_2;
    lVar3 = uVar6 * 0x78;
    if (param_3 == '\0') {
      lVar1 = param_1 + 0x2624;
      lVar2 = param_1 + 0x2658;
      piVar4 = (int *)(lVar3 + 0x2608 + param_1);
      *piVar4 = *piVar4 + param_5;
    }
    else {
      lVar1 = param_1 + 0x260c;
      lVar2 = param_1 + 0x263c;
      piVar4 = (int *)(lVar3 + 0x2604 + param_1);
      *piVar4 = *piVar4 + param_5;
    }
    piVar5 = (int *)(lVar1 + lVar3);
    piVar4 = (int *)(lVar2 + lVar3);
    StorPortQuerySystemTime(param_1 + 0x6400 + uVar6 * 8);
    if (param_5 < 2) {
      *piVar5 = *piVar5 + 1;
    }
    else if (param_5 < 9) {
      piVar5[1] = piVar5[1] + 1;
    }
    else if (param_5 < 0x21) {
      piVar5[2] = piVar5[2] + 1;
    }
    else if (param_5 < 0x81) {
      piVar5[3] = piVar5[3] + 1;
    }
    else if (param_5 < 0x101) {
      piVar5[4] = piVar5[4] + 1;
    }
    else {
      piVar5[5] = piVar5[5] + 1;
    }
    uVar6 = *(ulonglong *)(param_1 + 0x6200 + uVar6 * 8);
    if (uVar6 == param_4) {
      *piVar4 = *piVar4 + 1;
    }
    else if (param_4 < uVar6 + 0x80) {
      if (param_4 < uVar6 + 0x400) {
        if (param_4 < uVar6 + 0x8000) {
          if (param_4 < uVar6 + 0x80000) {
            if (param_4 < uVar6 + 0x200000) {
              piVar4[6] = piVar4[6] + 1;
            }
            else {
              piVar4[5] = piVar4[5] + 1;
            }
          }
          else {
            piVar4[4] = piVar4[4] + 1;
          }
        }
        else {
          piVar4[3] = piVar4[3] + 1;
        }
      }
      else {
        piVar4[2] = piVar4[2] + 1;
      }
    }
    else {
      piVar4[1] = piVar4[1] + 1;
    }
  }
  return;
}



===== ProcessPerfMetricRequest @ 1c0007f08 =====

void ProcessPerfMetricRequest(longlong param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 in_register_00000084;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_3 < 0x184) {
    uVar5 = 0x40;
  }
  else {
    uVar2 = *param_2;
    if (0x103 < uVar2) {
      uVar3 = 0x40;
      if (*(byte *)(param_1 + 0x21f1) < 0x41) {
        uVar3 = (uint)*(byte *)(param_1 + 0x21f1);
      }
      uVar3 = uVar3 * 0x78;
      uVar4 = -(uint)(uVar3 != 0) & uVar3 + 8;
      if (param_3 < uVar2 + 8 + uVar3) {
        param_2[0x41] = uVar4;
        param_2[0x42] = *(uint *)(param_1 + 0x6610);
        return;
      }
      puVar1 = (uint *)((longlong)param_2 + (ulonglong)uVar2);
      *puVar1 = uVar4;
      puVar1[1] = *(uint *)(param_1 + 0x6610);
      if (uVar3 != 0) {
        MemFastMove((undefined8 *)(puVar1 + 2),(undefined8 *)(param_1 + 0x43fc),uVar3);
      }
      return;
    }
    uVar5 = 0x41;
  }
  StorPortLogError(param_1,0,CONCAT71((int7)(CONCAT44(in_register_00000084,param_3) >> 8),0xff),0xff
                   ,0xff,6,uVar5);
  return;
}



===== FUN_1c0007fd4 @ 1c0007fd4 =====

ulonglong FUN_1c0007fd4(longlong param_1,longlong param_2)

{
  byte bVar1;
  ulonglong uVar2;
  longlong lVar3;
  byte bVar4;
  longlong *plVar5;
  uint uVar6;
  byte bVar7;
  uint *puVar8;
  
  bVar1 = *(byte *)(param_1 + 0x21f1);
  bVar4 = 0;
  bVar7 = 0x40;
  if ((0x40 < bVar1) || (bVar7 = bVar1, bVar1 != 0)) {
    plVar5 = (longlong *)(param_1 + 0x6400);
    puVar8 = (uint *)(param_1 + 0x2608);
    do {
      puVar8[-1] = puVar8[-1] >> 0xb;
      *puVar8 = *puVar8 >> 0xb;
      *(byte *)(puVar8 + -3) = bVar4;
      lVar3 = *plVar5;
      bVar4 = bVar4 + 1;
      plVar5 = plVar5 + 1;
      lVar3 = SUB168(SEXT816(-0x29406b2a1a85bd43) * SEXT816(param_2 - lVar3),8) + (param_2 - lVar3);
      *(short *)((longlong)puVar8 + -10) =
           *(short *)((longlong)puVar8 + -10) + ((short)(lVar3 >> 0x17) - (short)(lVar3 >> 0x3f));
      puVar8 = puVar8 + 0x1e;
    } while (bVar4 < bVar7);
  }
  uVar6 = (int)param_2 - *(int *)(param_1 + 0x6608);
  uVar2 = (ulonglong)uVar6 * 0x6b5fca6b & 0xffffffff;
  *(uint *)(param_1 + 0x6610) = uVar6 / 10000000;
  if (*(char *)(param_1 + 0x21f1) != '\0') {
    uVar2 = (ulonglong)((uint)bVar7 * 0x78);
    MemFastMove((undefined8 *)(param_1 + 0x43fc),(undefined8 *)(param_1 + 0x25fc),(uint)bVar7 * 0x78
               );
    uVar2 = MemFastZero((undefined8 *)(param_1 + 0x25fc),uVar2 & 0xffffffff);
  }
  return uVar2;
}



===== MegaSASQueryWmiRegInfo @ 1c00080b0 =====

undefined8 MegaSASQueryWmiRegInfo(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  *param_3 = L"MofResource";
  return 0x1c000a401;
}



===== MegaSASWmiSrb @ 1c00080c0 =====

ulonglong MegaSASWmiSrb(longlong param_1,longlong param_2)

{
  char cVar1;
  undefined8 in_RAX;
  ulonglong uVar2;
  uint local_res10 [2];
  int local_res18 [4];
  undefined1 local_38 [8];
  uint local_30;
  uint *local_28;
  byte local_20;
  char local_1f;
  uint local_1c;
  
  uVar2 = CONCAT71((int7)((ulonglong)in_RAX >> 8),*(byte *)(param_2 + 9));
  if ((*(byte *)(param_2 + 9) & 1) == 0) {
    *(undefined1 *)(param_2 + 3) = 1;
    *(undefined4 *)(param_2 + 0x10) = 0;
  }
  else {
    MemFastZero(local_38,0x20);
    local_20 = *(byte *)(param_2 + 4);
    local_28 = *(uint **)(param_2 + 0x18);
    local_30 = *(uint *)(param_2 + 0x10);
    local_res10[0] = 0;
    if (local_20 < 10) {
      local_1c = 0;
      cVar1 = ScsiWmipProcessRequest
                        ((uint *)(param_1 + 0x6670),local_20,param_1,local_38,
                         *(longlong **)(param_2 + 0x20),local_30,local_28,local_res10,local_res18);
      if (local_res18[0] == 1) {
        uVar2 = (ulonglong)local_res10[0];
        local_1f = cVar1;
        if (cVar1 != '\x01') {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = (ulonglong)local_1c;
      }
      if (cVar1 == '\0') {
        return CONCAT71((int7)(uVar2 >> 8),1);
      }
    }
    else {
      uVar2 = 0;
      local_1f = '\x04';
    }
    *(int *)(param_2 + 0x10) = (int)uVar2;
    *(char *)(param_2 + 3) = local_1f;
  }
  return uVar2 & 0xffffffffffffff00;
}



===== MegaSASQueryWmiDataBlock @ 1c0008190 =====

ulonglong MegaSASQueryWmiDataBlock
                    (undefined8 param_1,longlong param_2,int param_3,undefined8 param_4,uint param_5
                    ,uint *param_6,uint param_7)

{
  int iVar1;
  ulonglong uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar2 = (ulonglong)param_5;
  cVar3 = '\x04';
  if (param_5 == 1) {
    if (param_3 == 0) {
      uVar6 = 4;
      cVar3 = '\x12';
      if (3 < param_7) {
        cVar3 = '\x01';
      }
    }
    else {
      uVar6 = 0;
    }
    if ((param_6 != (uint *)0x0) && (cVar3 != '\x12')) {
      *param_6 = uVar6;
    }
  }
  else {
    uVar6 = 0;
    if (param_5 != 0) {
      puVar5 = param_6;
      do {
        if (param_3 == 0) {
          uVar4 = 4;
          cVar3 = '\x12';
        }
        else {
          uVar4 = 0;
          cVar3 = '\x04';
        }
        uVar6 = uVar6 + (uVar4 + 7 & 0xfffffff8);
        if (param_6 != (uint *)0x0) {
          *puVar5 = uVar4;
        }
        puVar5 = puVar5 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    if ((param_6 == (uint *)0x0) || (param_7 < uVar6)) {
      cVar3 = '\x12';
    }
    else {
      uVar6 = 0;
      uVar4 = 0;
      if (param_5 != 0) {
        do {
          if (param_3 == 0) {
            iVar1 = 4;
            cVar3 = '\x12';
            if (3 < *param_6) {
              cVar3 = '\x01';
            }
          }
          else {
            iVar1 = 0;
            cVar3 = '\x04';
          }
          uVar6 = uVar6 + (iVar1 + 7U & 0xfffffff8);
          if (cVar3 != '\x01') break;
          uVar4 = uVar4 + 1;
          param_6 = param_6 + 1;
        } while (uVar4 < param_5);
      }
    }
  }
  uVar2 = ScsiPortWmiPostProcess(param_2,cVar3,uVar6);
  return uVar2 & 0xffffffffffffff00;
}



===== FunctionControl @ 1c00082c0 =====

undefined1
FunctionControl(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4,char param_5
               )

{
  *(bool *)(param_1 + 0x6618) = param_5 != '\0';
  ScsiPortWmiPostProcess(param_2,'\x01',0);
  return 1;
}



===== MegaSASResetBus @ 1c00082f0 =====

undefined8 MegaSASResetBus(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  uint uVar2;
  ulonglong in_RAX;
  longlong lVar3;
  undefined8 local_res8 [4];
  
  if ((((*(char *)(param_1 + 0x7bbf) == '\0') && (*(char *)(param_1 + 0x7bbd) == '\0')) &&
      (*(char *)(param_1 + 0x7bc0) == '\0')) && (*(char *)(param_1 + 0x7bbe) == '\0')) {
    lVar3 = param_1;
    in_RAX = CheckFirmwareFault(param_1,param_2,param_3);
    if ((char)in_RAX == '\0') {
      if (*(char *)(param_1 + 0x88) == '\0') {
        in_RAX = (ulonglong)*(uint *)(param_1 + 0x21c0);
        if (*(uint *)(param_1 + 0x21c0) == 0) {
          StorPortResume(param_1);
          in_RAX = StorPortReady(param_1);
        }
        else if (*(char *)(param_1 + 0x7bbc) == '\0') {
          *(undefined1 *)(param_1 + 0x7bbc) = 1;
          StorPortPause(param_1,0xe10);
          if ((*(char *)(param_1 + 0x89) != '\0') && (*(char *)(param_1 + 0x21e5) != '\0')) {
            *(uint *)(param_1 + 0x7bb8) = *(uint *)(param_1 + 0x7bb0) / 1000000;
          }
          StorPortQuerySystemTime(local_res8);
          *(undefined8 *)(param_1 + 0x7ba8) = local_res8[0];
          in_RAX = StorPortNotification(6,param_1,FUN_1c0008410,1000000);
        }
      }
      else {
        cVar1 = *(char *)(param_1 + 0x7bd2);
        uVar2 = (int)CONCAT71((int7)((ulonglong)lVar3 >> 8),cVar1) + 1;
        in_RAX = (ulonglong)uVar2;
        *(char *)(param_1 + 0x7bd2) = (char)uVar2;
        if (cVar1 != '\0') {
          in_RAX = SetDeadAdapter(param_1,0x37);
        }
      }
    }
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== FUN_1c0008410 @ 1c0008410 =====

void FUN_1c0008410(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  code *pcVar4;
  undefined4 uVar5;
  longlong local_res8;
  
  iVar1 = extendedTimeout;
  if (*(char *)(param_1 + 0x7bbc) == '\0') {
    if (*(char *)(param_1 + 0x89) == '\0') {
      return;
    }
    if (*(char *)(param_1 + 0x21e5) == '\0') {
      return;
    }
    uVar5 = *(undefined4 *)(param_1 + 0x7bb0);
    pcVar4 = VFheartbeatTimer;
  }
  else {
    StorPortQuerySystemTime(&local_res8);
    uVar3 = (ulonglong)(uint)(iVar1 * 10) + *(longlong *)(param_1 + 0x7ba8);
    if ((longlong)uVar3 <= local_res8) {
      if (*(char *)(param_1 + 0x89) != '\0') {
        *(undefined1 *)(param_1 + 0x7bc0) = 1;
      }
      FUN_1c0008680(param_1,uVar3,param_3);
      return;
    }
    if ((*(char *)(param_1 + 0x89) != '\0') && (*(char *)(param_1 + 0x21e5) != '\0')) {
      if (*(int *)(param_1 + 0x7bb8) == 0) {
        uVar3 = (ulonglong)*(uint *)(param_1 + 0x7bb0) / 1000000;
        *(int *)(param_1 + 0x7bb8) = (int)uVar3;
        VFheartbeatTimer(param_1,uVar3,param_3);
      }
      else {
        *(int *)(param_1 + 0x7bb8) = *(int *)(param_1 + 0x7bb8) + -1;
      }
      if (*(char *)(param_1 + 0x7bbd) != '\0') {
        return;
      }
      if ((*(char *)(param_1 + 0x7bbf) == '\0') &&
         (uVar2 = CheckFirmwareFault(param_1,uVar3,param_3), (char)uVar2 != '\0')) {
        return;
      }
    }
    if (*(char *)(param_1 + 0x7bbd) != '\0') {
      return;
    }
    if (*(char *)(param_1 + 0x7bbf) != '\0') {
      return;
    }
    uVar5 = 1000000;
    pcVar4 = FUN_1c0008410;
  }
  StorPortNotification(6,param_1,pcVar4,uVar5);
  return;
}



===== CheckFirmwareFault @ 1c000852c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 CheckFirmwareFault(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined8 in_RAX;
  undefined4 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  
  if ((*(char *)(param_1 + 0x7bbf) == '\0') && (*(char *)(param_1 + 0x7bc7) == '\0')) {
    uVar1 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x30))(*(undefined8 *)(param_1 + 0x80));
    *(uint *)(param_1 + 0x21c4) = uVar1;
    if ((*(char *)(param_1 + 0x89) == '\0') && ((uVar1 & 0xf0000000) == 0)) {
      *(uint *)(param_1 + 0x21c4) = uVar1 | 0xf0000000;
    }
    uVar1 = *(uint *)(param_1 + 0x21c4) & 0xf0000000;
    if (uVar1 != 0xf0000000) {
      return (ulonglong)(uint3)(uVar1 >> 8) << 8;
    }
    if (*(char *)(param_1 + 0x88) == '\0') {
      if ((*(uint *)(param_1 + 0x21c4) & 2) == 0) {
        uVar2 = 0x32;
      }
      else {
        if (*(char *)(param_1 + 0x21e5) != '\0') {
          uVar3 = CONCAT71((int7)((ulonglong)param_3 >> 8),0xff);
          StorPortLogError(param_1,0,uVar3,0xff,0xff,6,3);
          (**(code **)(*(longlong *)(param_1 + 0x188) + 0x28))(param_1);
          StorPortPause(param_1);
          *(undefined2 *)(param_1 + 0x7bbc) = 0x100;
          if (*(char *)(param_1 + 0x89) == '\0') {
            uVar2 = 1000000;
            pcVar4 = FUN_1c0008680;
          }
          else {
            *(undefined1 *)(param_1 + 0x7bc7) = 1;
            FUN_1c0008b0c(param_1,'\0',uVar3);
            uVar2 = *(undefined4 *)(param_1 + 0x7bb4);
            pcVar4 = VfRestartWhenReady;
            *(undefined4 *)(param_1 + 0x7bcc) = 180000000;
          }
          in_RAX = StorPortNotification(6,param_1,pcVar4,uVar2);
          goto LAB_1c0008673;
        }
        uVar2 = 0x31;
      }
    }
    else {
      uVar2 = 0x36;
    }
    in_RAX = SetDeadAdapter(param_1,uVar2);
  }
LAB_1c0008673:
  return CONCAT71((int7)((ulonglong)in_RAX >> 8),1);
}



===== FUN_1c0008680 @ 1c0008680 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FUN_1c0008680(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  ulonglong uVar2;
  char cVar3;
  undefined8 local_res8;
  
  cVar3 = '\x03';
  uVar2 = FUN_1c0008b0c(param_1,'\0',param_3);
  if ((char)uVar2 != '\0') {
    StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x30);
    do {
      cVar1 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x48))(param_1);
      if (cVar1 != '\0') {
        *(undefined2 *)(param_1 + 0x7bd0) = 0x200;
        StorPortQuerySystemTime(&local_res8);
        *(undefined8 *)(param_1 + 0x7ba8) = local_res8;
        StorPortNotification(6,param_1,FUN_1c0008740,1000000);
        return;
      }
    } while ((*(char *)(param_1 + 0x89) != '\0') && (cVar3 = cVar3 + -1, cVar3 != '\0'));
    SetDeadAdapter(param_1,0x33);
  }
  return;
}



===== FUN_1c0008740 @ 1c0008740 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void FUN_1c0008740(longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  longlong local_res8;
  undefined4 uVar3;
  
  if (*(char *)(param_1 + 0x7bbf) != '\0') {
    return;
  }
  uVar1 = CheckFirmwareReady(param_1);
  if ((char)uVar1 == '\0') {
    if ((*(uint *)(param_1 + 0x21c4) & 0xf0000000) == 0xf0000000) {
      uVar3 = 3;
    }
    else {
      StorPortQuerySystemTime(&local_res8);
      if (local_res8 < *(longlong *)(param_1 + 0x7ba8) + 3000000000) goto LAB_1c0008884;
      uVar3 = 0x34;
    }
    StorPortLogError(param_1,0,0xff,0xff,0xff,6,uVar3);
    uVar2 = CheckResetRetries(param_1);
    if ((char)uVar2 == '\0') {
      return;
    }
  }
  else {
    if (*(char *)(param_1 + 0x8a38) == '\0') {
      *(undefined4 *)(param_1 + 0x8a18) = 2;
      *(undefined8 *)(param_1 + 0x8a24) = 0;
      WatchDogTimer(param_1);
      return;
    }
    uVar2 = InitializeAdapter(param_1);
    if ((char)uVar2 == '\0') {
      uVar2 = CheckResetRetries(param_1);
      if ((char)uVar2 != '\0') {
        StorPortQuerySystemTime(&local_res8);
        *(longlong *)(param_1 + 0x7ba8) = local_res8;
        StorPortNotification(6,param_1,FUN_1c0008740,1000000);
      }
    }
    else {
      uVar2 = FUN_1c0008c38(param_1);
      if ((char)uVar2 != '\0') {
        *(undefined1 *)(param_1 + 0x7bbd) = 0;
        if (*(char *)(param_1 + 0x89) != '\0') {
          *(undefined1 *)(param_1 + 0x7bc0) = 0;
          *(undefined1 *)(param_1 + 0x7bc7) = 0;
        }
        *(undefined1 *)(param_1 + 0x7bbc) = 0;
        *(undefined1 *)(param_1 + 0x7bbe) = 0;
        *(undefined1 *)(param_1 + 0x7bd0) = 0;
        (**(code **)(*(longlong *)(param_1 + 0x188) + 0x20))(param_1);
        StorPortResume(param_1);
        StorPortReady(param_1);
        return;
      }
    }
    if (*(char *)(param_1 + 0x89) == '\0') {
      return;
    }
    if (*(char *)(param_1 + 0x7bbf) != '\0') {
      return;
    }
    *(undefined2 *)(param_1 + 0x7bd0) = 0x200;
  }
  StorPortQuerySystemTime(&local_res8);
  *(longlong *)(param_1 + 0x7ba8) = local_res8;
LAB_1c0008884:
  StorPortNotification(6,param_1,FUN_1c0008740,1000000);
  return;
}



===== CheckResetRetries @ 1c0008910 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong CheckResetRetries(longlong param_1)

{
  undefined4 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  
  *(char *)(param_1 + 0x7bd0) = *(char *)(param_1 + 0x7bd0) + '\x01';
  if (*(byte *)(param_1 + 0x7bd1) < *(byte *)(param_1 + 0x7bd0)) {
    uVar1 = 0x35;
  }
  else {
    uVar1 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x30))(*(undefined8 *)(param_1 + 0x80));
    *(undefined4 *)(param_1 + 0x21c4) = uVar1;
    uVar3 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x48))(param_1);
    if ((char)uVar3 != '\0') {
      return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
    }
    uVar1 = 0x33;
  }
  uVar2 = SetDeadAdapter(param_1,uVar1);
  return uVar2 & 0xffffffffffffff00;
}



===== SetDeadAdapter @ 1c0008984 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void SetDeadAdapter(longlong param_1,undefined4 param_2)

{
  code *pcVar1;
  uint local_res8 [2];
  
  if (*(char *)(param_1 + 0x7bbf) == '\0') {
    MemFastZero(local_res8,4);
    *(undefined2 *)(param_1 + 0x7bbc) = 0;
    *(undefined8 *)(param_1 + 0x2198) = 0;
    *(undefined1 *)(param_1 + 0x7bbf) = 1;
    StorPortLogError(param_1,0,0xff,0xff,0xff,6,param_2);
    pcVar1 = FUN_1c0008740;
    StorPortNotification(6,param_1);
    if (*(char *)(param_1 + 0x89) == '\0') {
      (**(code **)(*(longlong *)(param_1 + 0x188) + 0x28))(param_1);
      (**(code **)(*(longlong *)(param_1 + 0x188) + 0x40))
                (*(undefined8 *)(param_1 + 0x80),local_res8[0] | 0x20);
    }
    FUN_1c0008b0c(param_1,'\x01',pcVar1);
    StorPortNotification(7,param_1);
    StorPortNotification(7,param_1,1);
    StorPortResume(param_1);
    StorPortReady(param_1);
  }
  else {
    StorPortLogError(param_1,0,0xff,0xff,0xff,6,param_2);
  }
  return;
}



===== FUN_1c0008ab0 @ 1c0008ab0 =====

void FUN_1c0008ab0(undefined8 param_1,longlong param_2,undefined8 param_3,char param_4)

{
  longlong lVar1;
  
  if (param_2 != 0) {
    do {
      lVar1 = *(longlong *)(param_2 + 0x500);
      *(byte *)(lVar1 + 3) = (-(param_4 != '\0') & 6U) + 0xb;
      *(undefined1 *)(lVar1 + 4) = 2;
      param_2 = *(longlong *)(param_2 + 0x550);
      StorPortNotification(0,param_1);
    } while (param_2 != 0);
  }
  return;
}



===== FUN_1c0008b0c @ 1c0008b0c =====

ulonglong FUN_1c0008b0c(longlong param_1,char param_2,undefined8 param_3)

{
  int *piVar1;
  longlong lVar2;
  ulonglong uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  longlong *plVar7;
  
  iVar5 = 0;
  plVar7 = (longlong *)(param_1 + 0x66e0);
  uVar6 = 0;
  do {
    lVar2 = *plVar7;
    *plVar7 = 0;
    plVar7[1] = 0;
    *(undefined1 *)((longlong)plVar7 + 0x11) = 0;
    if (lVar2 != 0) {
      if (*(longlong *)(lVar2 + 0x500) == 0) {
        if (param_2 == '\0') goto LAB_1c0008b57;
      }
      else {
        FUN_1c0008ab0(param_1,lVar2,param_3,param_2);
      }
    }
    uVar6 = uVar6 + 1;
    plVar7 = plVar7 + 8;
  } while (uVar6 < 0x40);
  uVar3 = 0;
  if (*(int *)(param_1 + 0x66c0) != 0) {
    do {
      lVar2 = *(longlong *)(param_1 + 400 + uVar3 * 8);
      if (lVar2 != 0) {
        if (*(longlong *)(lVar2 + 0x500) == 0) goto LAB_1c0008b57;
        if ((param_2 == '\0') && (*(char *)(*(longlong *)(lVar2 + 0x500) + 2) == '\x02')) {
          iVar5 = iVar5 + 1;
        }
        else {
          uVar6 = *(uint *)(lVar2 + 0x508);
          if (*(longlong *)(param_1 + 400 + (ulonglong)uVar6 * 8) != lVar2) {
            uVar4 = 0x21;
            goto LAB_1c0008b5f;
          }
          *(undefined8 *)(param_1 + 400 + (ulonglong)uVar6 * 8) = 0;
          *(uint *)(param_1 + 0x2190) = uVar6;
          LOCK();
          piVar1 = (int *)(param_1 + 0x21c0);
          *piVar1 = *piVar1 + -1;
          UNLOCK();
          if (*piVar1 < 0) {
            uVar4 = 0x25;
            goto LAB_1c0008b5f;
          }
          FUN_1c0008ab0(param_1,lVar2,param_3,param_2);
        }
      }
      uVar6 = (int)uVar3 + 1;
      uVar3 = (ulonglong)uVar6;
    } while (uVar6 < *(uint *)(param_1 + 0x66c0));
  }
  if (iVar5 == *(int *)(param_1 + 0x21c0)) {
    uVar3 = CONCAT71((uint7)(uint3)((uint)*(int *)(param_1 + 0x21c0) >> 8),1);
  }
  else {
LAB_1c0008b57:
    uVar4 = 0x23;
LAB_1c0008b5f:
    uVar3 = SetDeadAdapter(param_1,uVar4);
    uVar3 = uVar3 & 0xffffffffffffff00;
  }
  return uVar3;
}



===== FUN_1c0008c38 @ 1c0008c38 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 FUN_1c0008c38(longlong param_1)

{
  longlong lVar1;
  ulonglong in_RAX;
  ulonglong uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x66c0) != 0) {
    do {
      in_RAX = uVar2;
      lVar1 = *(longlong *)(param_1 + 400 + in_RAX * 8);
      iVar3 = (int)in_RAX;
      if (lVar1 != 0) {
        if (*(longlong *)(lVar1 + 0x500) == 0) {
          uVar2 = SetDeadAdapter(param_1,0x23);
          return uVar2 & 0xffffffffffffff00;
        }
        *(undefined2 *)(lVar1 + 2) = 0xff;
        in_RAX = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x50))();
      }
      uVar4 = iVar3 + 1;
      uVar2 = (ulonglong)uVar4;
    } while (uVar4 < *(uint *)(param_1 + 0x66c0));
  }
  return CONCAT71((int7)(in_RAX >> 8),1);
}



===== VFheartbeatTimer @ 1c0008cb0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VFheartbeatTimer(longlong param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  int *piVar2;
  ulonglong uVar3;
  code *pcVar4;
  undefined8 uVar5;
  
  piVar2 = *(int **)(param_1 + 0x168);
  if (*piVar2 == piVar2[8]) {
    StorPortPause(param_1);
    (**(code **)(*(longlong *)(param_1 + 0x188) + 0x28))(param_1);
    uVar5 = CONCAT71((int7)((ulonglong)param_3 >> 8),0xff);
    *(undefined2 *)(param_1 + 0x7bbc) = 0x100;
    StorPortLogError(param_1);
    *(undefined1 *)(param_1 + 0x7bc7) = 1;
    uVar3 = FUN_1c0008b0c(param_1,'\0',uVar5);
    if ((char)uVar3 == '\0') {
      return;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x7bb4);
    pcVar4 = VfRestartWhenReady;
    *(undefined4 *)(param_1 + 0x7bcc) = 180000000;
  }
  else {
    piVar2[8] = *piVar2;
    if (*(char *)(param_1 + 0x7bbc) != '\0') {
      return;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x7bb0);
    pcVar4 = VFheartbeatTimer;
  }
  StorPortNotification(6,param_1,pcVar4,uVar1);
  return;
}



===== VfRestartWhenReady @ 1c0008d80 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void VfRestartWhenReady(longlong param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  
  if (*(char *)(param_1 + 0x7bbf) != '\0') {
    return;
  }
  uVar1 = CheckFirmwareReady(param_1);
  if ((char)uVar1 == '\0') {
    if ((*(uint *)(param_1 + 0x21c4) & 0xf0000000) == 0xf0000000) {
      uVar3 = 0x62;
    }
    else {
      if (-1 < *(int *)(param_1 + 0x7bcc)) {
        *(int *)(param_1 + 0x7bcc) = *(int *)(param_1 + 0x7bcc) + -1000000;
                    /* WARNING: Could not recover jumptable at 0x0001c0008df0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        StorPortNotification(6,param_1,VfRestartWhenReady,1000000);
        return;
      }
      uVar3 = 99;
    }
  }
  else {
    if (*(char *)(param_1 + 0x8a38) == '\0') {
      *(undefined4 *)(param_1 + 0x8a24) = 0;
      *(undefined4 *)(param_1 + 0x8a18) = 2;
      WatchDogTimer(param_1);
      return;
    }
    uVar2 = InitializeAdapter(param_1);
    if ((char)uVar2 != '\0') {
      uVar2 = FUN_1c0008c38(param_1);
      if ((char)uVar2 == '\0') {
        return;
      }
      *(undefined2 *)(param_1 + 0x7bbc) = 0;
      *(undefined1 *)(param_1 + 0x7bc0) = 0;
      *(undefined1 *)(param_1 + 0x7bc7) = 0;
      (**(code **)(*(longlong *)(param_1 + 0x188) + 0x20))(param_1);
      StorPortResume(param_1);
      StorPortReady(param_1);
      return;
    }
    uVar3 = 9;
  }
  SetDeadAdapter(param_1,uVar3);
  return;
}



===== SyncronizeInitializeAdapter @ 1c0008e90 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8 SyncronizeInitializeAdapter(longlong param_1)

{
  longlong lVar1;
  undefined1 uVar2;
  ulonglong uVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  longlong lVar7;
  undefined7 uVar9;
  undefined8 uVar8;
  undefined8 local_res8;
  undefined8 local_res18;
  
LAB_1c0008eb3:
  iVar4 = *(int *)(param_1 + 0x8a24);
  uVar3 = (ulonglong)(iVar4 - 3U);
  if (iVar4 - 3U < 2) {
    lVar7 = *(longlong *)(param_1 + 0xf0);
  }
  else {
    uVar3 = (ulonglong)(iVar4 - 0xfU);
    if (iVar4 - 0xfU < 2) {
      lVar7 = *(longlong *)(param_1 + 0xe8);
    }
    else {
      uVar3 = (ulonglong)(iVar4 - 0xbU);
      if (iVar4 - 0xbU < 2) {
        lVar7 = *(longlong *)(param_1 + 0xf8);
      }
      else {
        lVar7 = *(longlong *)(param_1 + 0xd8);
      }
    }
  }
  uVar9 = (undefined7)((ulonglong)lVar7 >> 8);
  if (10 < iVar4) {
    if (iVar4 == 0xb) {
      if (*(char *)(param_1 + 0x88) == '\0') {
        if (*(char *)(param_1 + 0x89) != '\0') {
          *(undefined4 *)(param_1 + 0x8a24) = 0xc;
          *(undefined4 *)(param_1 + 0x8a28) = 0xd;
          if (*(int *)(param_1 + 0x8a3c) == 2) {
            iVar4 = 0x3150200;
          }
          else {
            iVar4 = 0x3200200;
          }
          goto LAB_1c0009239;
        }
LAB_1c0009168:
        *(undefined4 *)(param_1 + 0x8a24) = 0xf;
        goto LAB_1c0008eb3;
      }
    }
    else {
      if (iVar4 == 0xc) goto LAB_1c0008f2c;
      if (iVar4 == 0xd) {
        if (*(char *)(param_1 + 0x88) == '\0') {
          if (*(char *)(param_1 + 0x89) == '\0') goto LAB_1c0009168;
          *(undefined4 *)(param_1 + 0x8a24) = 0xe;
          iVar4 = 0x10e8485;
          *(undefined4 *)(param_1 + 0x8a28) = 0xf;
          goto LAB_1c0009239;
        }
      }
      else {
        if (iVar4 == 0xe) goto LAB_1c0008f2c;
        if (iVar4 == 0xf) {
          if (*(char *)(param_1 + 0x88) == '\0') {
            if ((*(char *)(param_1 + 0x7be0) != '\0') && (*(char *)(param_1 + 0x7be2) != '\0')) {
              *(undefined4 *)(param_1 + 0x7be4) = 0;
              iVar4 = 0x300e101;
              *(undefined4 *)(param_1 + 0x8a24) = 0x10;
              *(undefined4 *)(param_1 + 0x8a28) = 0x11;
              goto LAB_1c0009239;
            }
            *(undefined4 *)(param_1 + 0x8a24) = 0x11;
            goto LAB_1c0008eb3;
          }
        }
        else {
          if (iVar4 == 0x10) goto LAB_1c0008f2c;
          if (iVar4 != 0x11) {
            if (iVar4 != 0x12) {
              if (iVar4 != 0x13) goto LAB_1c00095d4;
              MemFastZero((void *)(param_1 + 0x7c08),0x800);
              MemFastZero((void *)(param_1 + 0x66e0),0x1000);
              if (*(char *)(param_1 + 0x89) != '\0') {
                if (*(int *)(param_1 + 0xb8) == 0) {
                  *(undefined4 *)(param_1 + 0x7bb0) = 5;
                }
                else {
                  *(int *)(param_1 + 0x7bb0) = *(int *)(param_1 + 0xb8);
                }
                *(int *)(param_1 + 0x7bb0) = *(int *)(param_1 + 0x7bb0) * 1000000;
                if (*(int *)(param_1 + 0xbc) == 0) {
                  *(undefined4 *)(param_1 + 0x7bb4) = 0x1e;
                }
                else {
                  *(int *)(param_1 + 0x7bb4) = *(int *)(param_1 + 0xbc);
                }
                *(int *)(param_1 + 0x7bb4) = *(int *)(param_1 + 0x7bb4) * 1000000;
                if ((*(char *)(param_1 + 0x21e5) != '\0') && (*(char *)(param_1 + 0x21f0) == '\0'))
                {
                  StorPortNotification(6,param_1,VFheartbeatTimer);
                }
              }
              uVar3 = FUN_1c0008c38(param_1);
              if ((char)uVar3 == '\0') {
                if ((*(char *)(param_1 + 0x89) == '\0') || (*(char *)(param_1 + 0x7bbf) != '\0'))
                goto LAB_1c00095d4;
                *(undefined2 *)(param_1 + 0x7bd0) = 0x200;
                StorPortQuerySystemTime(&local_res18);
                local_res8 = local_res18;
                goto LAB_1c000944b;
              }
              *(undefined1 *)(param_1 + 0x7bbd) = 0;
              if (*(char *)(param_1 + 0x89) != '\0') {
                *(undefined1 *)(param_1 + 0x7bc0) = 0;
                *(undefined1 *)(param_1 + 0x7bc7) = 0;
              }
              (**(code **)(*(longlong *)(param_1 + 0x188) + 0x20))(param_1);
              *(undefined1 *)(param_1 + 0x7bbc) = 0;
              *(undefined1 *)(param_1 + 0x7bbe) = 0;
              *(undefined1 *)(param_1 + 0x7bd0) = 0;
              *(undefined4 *)(param_1 + 0x8a18) = 0;
              StorPortResume(param_1);
              uVar3 = StorPortReady(param_1);
              goto LAB_1c00095d4;
            }
            if (*(int *)(param_1 + 0x8a28) != 4) {
              if (*(int *)(param_1 + 0x8a28) == 0xc) goto LAB_1c0009168;
              if (*(int *)(param_1 + 0x8a24) == 0xe) {
                StorPortLogError(param_1,0,0xff,CONCAT71(uVar9,0xff),0xff,6,0x61);
                uVar3 = SetDeadAdapter(param_1,0x35);
              }
              else {
                uVar3 = CheckResetRetries(param_1);
                if ((char)uVar3 != '\0') {
                  StorPortQuerySystemTime(&local_res8);
LAB_1c000944b:
                  *(undefined8 *)(param_1 + 0x7ba8) = local_res8;
                  pcVar6 = FUN_1c0008740;
                  uVar8 = 1000000;
LAB_1c00095c9:
                  uVar3 = StorPortNotification(6,param_1,pcVar6,uVar8);
                }
              }
LAB_1c00095d4:
              return CONCAT71((int7)(uVar3 >> 8),1);
            }
            *(undefined4 *)(param_1 + 0x8a24) = 5;
            goto LAB_1c0008eb3;
          }
          if (*(char *)(param_1 + 0x7be0) != '\0') {
            MPT_UpdateReplyQueue(param_1);
            if (0 < *(int *)(param_1 + 0x7ba4)) {
              *(undefined4 *)(param_1 + 0x8a24) = 0x12;
              StorPortLogError(param_1,0,0xff,0xff,0xff,6,100);
              goto LAB_1c0008eb3;
            }
            if (*(char *)(param_1 + 0x7be2) != '\0') {
              *(undefined4 *)(param_1 + 0x7be4) = 1;
              IssueDCMD(param_1,0x300e101);
            }
          }
          *(undefined1 *)(param_1 + 0x21ed) = 0;
          IssueDCMD(param_1,0x1040500);
        }
      }
    }
LAB_1c00091f3:
    *(undefined4 *)(param_1 + 0x8a24) = 0x13;
    goto LAB_1c0008eb3;
  }
  if (iVar4 != 10) {
    if (5 < iVar4) {
      if (iVar4 == 6) goto LAB_1c0008f2c;
      if (iVar4 == 7) {
        if (*(char *)(param_1 + 0x88) != '\0') goto LAB_1c00091f3;
        *(undefined4 *)(param_1 + 0x8a24) = 8;
        iVar4 = 0x1020100;
        *(undefined4 *)(param_1 + 0x8a28) = 9;
      }
      else {
        if (iVar4 == 8) goto LAB_1c0008f2c;
        if (iVar4 != 9) goto LAB_1c00095d4;
        if (*(char *)(param_1 + 0x88) != '\0') goto LAB_1c00091f3;
        iVar4 = 0x1040100;
        *(undefined4 *)(param_1 + 0x8a24) = 10;
        *(uint *)(param_1 + 0x8a28) =
             (-(uint)(*(char *)(param_1 + 0x89) != '\0') & 0xfffffffc) + 0xf;
      }
LAB_1c0009239:
      WDTSetupAndSendDCMD(param_1,iVar4);
      goto LAB_1c0008eb3;
    }
    if (iVar4 == 5) {
      if (*(char *)(param_1 + 0x88) != '\0') goto LAB_1c00091f3;
      *(undefined4 *)(param_1 + 0x8a24) = 6;
      iVar4 = 0x1010000;
      *(undefined4 *)(param_1 + 0x8a28) = 7;
      goto LAB_1c0009239;
    }
    if (iVar4 == 0) {
      *(undefined1 *)(param_1 + 0x7be3) = 0;
      *(undefined1 *)(param_1 + 0x21ee) = 0;
      *(undefined4 *)(param_1 + 0x8a28) = 0;
      if (*(char *)(param_1 + 0x7be0) == '\0') {
        uVar3 = 0;
        if (*(char *)(param_1 + 0x76ea) != '\0') {
          do {
            uVar5 = (int)uVar3 + 1;
            *(undefined4 *)(*(longlong *)(param_1 + 0x7bd8) + 4 + uVar3 * 0x10) =
                 *(undefined4 *)(*(longlong *)(param_1 + 0x7bd8) + uVar3 * 0x10);
            uVar3 = (ulonglong)uVar5;
          } while (uVar5 < *(byte *)(param_1 + 0x76ea));
        }
        *(undefined1 *)(param_1 + 0x7bd4) = 0;
      }
LAB_1c0009054:
      *(undefined4 *)(param_1 + 0x8a24) = 1;
      goto LAB_1c0008eb3;
    }
    if (iVar4 == 1) {
      uVar2 = (*(code *)**(undefined8 **)(param_1 + 0x188))
                        (param_1,lVar7,*(undefined8 *)(param_1 + 0x148));
      *(undefined1 *)(param_1 + 0x8a39) = uVar2;
      *(undefined4 *)(param_1 + 0x7bcc) = 60000000;
      *(undefined4 *)(param_1 + 0x8a24) = 2;
      *(undefined4 *)(param_1 + 0x8a28) = 3;
      goto LAB_1c0008eb3;
    }
    if (iVar4 == 2) goto LAB_1c0008f2c;
    if (iVar4 == 3) {
      *(undefined4 *)(param_1 + 0x8a24) = 4;
      iVar4 = 0x2010100;
      *(undefined4 *)(param_1 + 0x8a28) = 5;
      goto LAB_1c0009239;
    }
    if (iVar4 != 4) goto LAB_1c00095d4;
  }
LAB_1c0008f2c:
  if (*(char *)(lVar7 + 2) == -1) {
    uVar5 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x30))(*(undefined8 *)(param_1 + 0x80));
    *(uint *)(param_1 + 0x21c4) = uVar5;
    if (((uVar5 & 0xf0000000) != 0xf0000000) && (0 < *(int *)(param_1 + 0x7bcc))) {
      *(int *)(param_1 + 0x7bcc) = *(int *)(param_1 + 0x7bcc) + -100000;
      pcVar6 = WatchDogTimer;
      uVar8 = 100000;
      goto LAB_1c00095c9;
    }
    StorPortLogError(param_1,0,0xff,0xff,0xff,6,0x13);
    *(undefined4 *)(param_1 + 0x8a28) = *(undefined4 *)(param_1 + 0x8a24);
  }
  else {
    if (*(char *)(lVar7 + 2) == '\0') {
      if (iVar4 == 2) {
        if (*(char *)(param_1 + 0x8a39) == '\0') goto LAB_1c0009054;
        uVar5 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x30))
                          (*(undefined8 *)(param_1 + 0x80));
        *(uint *)(param_1 + 0x21c4) = uVar5;
        if ((uVar5 & 0xf0000000) != 0xc0000000) goto LAB_1c00092a9;
      }
      else {
        if (iVar4 == 6) {
          lVar1 = *(longlong *)(param_1 + 0x148);
          if ((*(byte *)(lVar1 + 0x20) & 0x10) == 0) {
            *(undefined4 *)(param_1 + 0x8a3c) = 0;
          }
          else if ((*(uint *)(lVar1 + 0x7a4) & 0x6000000) == 0) {
            *(undefined4 *)(param_1 + 0x8a3c) = 1;
          }
          else {
            *(undefined4 *)(param_1 + 0x8a3c) = 2;
          }
          if (*(int *)(param_1 + 0x8a3c) == 2) {
            uVar2 = *(undefined1 *)(lVar1 + 0x7e6);
LAB_1c000934e:
            *(undefined1 *)(param_1 + 0x7bd3) = uVar2;
          }
          else {
            if (*(int *)(param_1 + 0x8a3c) == 1) {
              uVar2 = *(undefined1 *)(lVar1 + 2000);
              goto LAB_1c000934e;
            }
            *(undefined1 *)(param_1 + 0x89) = 0;
            *(undefined1 *)(param_1 + 0x7bd3) = 0;
          }
          if (*(char *)(param_1 + 0x7bd3) != '\0') {
            *(undefined1 *)(param_1 + 0x89) = 1;
          }
        }
        if (iVar4 == 0xe) {
          *(undefined4 *)(*(longlong *)(param_1 + 0x168) + 0x20) = 0xbaddaddd;
        }
        CompleteDCMD(param_1,lVar7,'\x01');
      }
      *(undefined4 *)(param_1 + 0x8a24) = *(undefined4 *)(param_1 + 0x8a28);
      goto LAB_1c0008eb3;
    }
    StorPortLogError(param_1,0,0xff,CONCAT71(uVar9,0xff),0xff,6,0x13);
  }
LAB_1c00092a9:
  *(undefined4 *)(param_1 + 0x8a24) = 0x12;
  goto LAB_1c0008eb3;
}



===== Xscale_ResetController @ 1c00095f0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong Xscale_ResetController(longlong param_1)

{
  ulonglong uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  undefined1 local_158 [32];
  uint *local_138;
  undefined4 local_130;
  int local_128;
  undefined1 local_118 [102];
  int local_b2 [7];
  uint local_94 [31];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)local_158;
  MemFastZero(local_118,0x100);
  uVar1 = (**(code **)(*(longlong *)(param_1 + 0x188) + 0x30))(*(undefined8 *)(param_1 + 0x80));
  *(uint *)(param_1 + 0x21c4) = (uint)uVar1;
  if ((((uint)uVar1 & 0xf0000000) == 0xf0000000) && ((uVar1 & 1) == 0)) {
    uVar1 = uVar1 & 0xffffffffffffff00;
  }
  else {
    *(undefined1 *)(param_1 + 0x7bbe) = 1;
    *(undefined4 *)(*(longlong *)(param_1 + 0x7bd8) + 4) = 0xdeaddead;
    *(undefined4 *)(*(longlong *)(param_1 + 0x80) + 0x20) = 0x40;
    LOCK();
    UNLOCK();
    lVar4 = 30000;
    do {
      lVar3 = lVar4;
      StorPortStallExecution(100);
      lVar4 = lVar3 + -1;
    } while (lVar4 != 0);
    local_138 = (uint *)local_118;
    iVar2 = (int)lVar3 + 3;
    local_130 = 0x100;
    StorPortGetBusData(param_1,iVar2,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x78));
    uVar1 = (ulonglong)local_94[0];
    if ((local_94[0] & 2) != 0) {
      local_94[0] = local_94[0] & 0xfffffffd;
      local_138 = local_94;
      local_130 = 0x84;
      local_128 = iVar2;
      StorPortSetBusDataByOffset
                (param_1,iVar2,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x78));
      lVar4 = 20000;
      do {
        StorPortStallExecution(100);
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
      local_138 = (uint *)local_118;
      local_130 = 0x100;
      uVar1 = StorPortGetBusData(param_1,iVar2,*(undefined4 *)(param_1 + 4),
                                 *(undefined4 *)(param_1 + 0x78));
      if (local_b2[0] == 0xdddd) {
        local_b2[0] = 0;
        local_138 = (uint *)local_b2;
        local_130 = 0x66;
        local_128 = iVar2;
        uVar1 = StorPortSetBusDataByOffset
                          (param_1,iVar2,*(undefined4 *)(param_1 + 4),
                           *(undefined4 *)(param_1 + 0x78));
      }
    }
    *(undefined1 *)(param_1 + 0x7bbe) = 0;
    uVar1 = CONCAT71((int7)(uVar1 >> 8),1);
  }
  return uVar1;
}



===== PPC_ResetController @ 1c00097b0 =====

undefined8 PPC_ResetController(longlong param_1)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  *(undefined1 *)(param_1 + 0x7bbe) = 1;
  lVar5 = 30000;
  do {
    lVar4 = lVar5;
    StorPortStallExecution(100);
    lVar5 = lVar4 + -1;
  } while (lVar5 != 0);
  if (*(char *)(param_1 + 0x21e7) == '\0') {
    uVar2 = 0xfc;
    uVar6 = 0xf8;
  }
  else {
    iVar1 = (int)lVar4;
    uVar2 = iVar1 + 3;
    uVar6 = (ulonglong)(iVar1 + 7);
  }
  uVar3 = (ulonglong)uVar2;
  *(undefined4 *)(uVar3 + *(longlong *)(param_1 + 0x80)) = 0;
  LOCK();
  UNLOCK();
  if (*(char *)(param_1 + 0x7be0) != '\0') {
    *(undefined4 *)(uVar3 + *(longlong *)(param_1 + 0x80)) = 0xf;
    LOCK();
    UNLOCK();
  }
  *(undefined4 *)(uVar3 + *(longlong *)(param_1 + 0x80)) = 4;
  LOCK();
  UNLOCK();
  *(undefined4 *)(uVar3 + *(longlong *)(param_1 + 0x80)) = 0xb;
  LOCK();
  UNLOCK();
  *(undefined4 *)(uVar3 + *(longlong *)(param_1 + 0x80)) = 2;
  LOCK();
  UNLOCK();
  *(undefined4 *)(uVar3 + *(longlong *)(param_1 + 0x80)) = 7;
  LOCK();
  UNLOCK();
  *(undefined4 *)(uVar3 + *(longlong *)(param_1 + 0x80)) = 0xd;
  LOCK();
  UNLOCK();
  StorPortStallExecution(100);
  StorPortStallExecution(100);
  lVar5 = *(longlong *)(param_1 + 0x80);
  uVar2 = 0;
  while (-1 < (char)*(uint *)(uVar6 + lVar5)) {
    if (99 < uVar2) goto LAB_1c0009968;
    StorPortStallExecution(100);
    uVar2 = uVar2 + 1;
    lVar5 = *(longlong *)(param_1 + 0x80);
  }
  *(uint *)(uVar6 + *(longlong *)(param_1 + 0x80)) = *(uint *)(uVar6 + lVar5) | 4;
  LOCK();
  UNLOCK();
  lVar5 = 6000;
  do {
    uVar3 = StorPortStallExecution(500);
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  if (*(char *)(param_1 + 0x89) == '\0') {
    StorPortStallExecution(500);
    lVar5 = *(longlong *)(param_1 + 0x80);
    uVar2 = 0;
    while (uVar3 = (ulonglong)*(uint *)(uVar6 + lVar5), (*(uint *)(uVar6 + lVar5) & 4) != 0) {
      if (199999 < uVar2) {
LAB_1c0009968:
        return (ulonglong)(uVar2 >> 8) << 8;
      }
      StorPortStallExecution(500);
      uVar2 = uVar2 + 1;
      lVar5 = *(longlong *)(param_1 + 0x80);
    }
  }
  *(undefined1 *)(param_1 + 0x7bbe) = 0;
  return CONCAT71((int7)(uVar3 >> 8),1);
}



===== __report_gsfailure @ 1c0009970 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== ScsiPortWmiPostProcess @ 1c0009978 =====

void ScsiPortWmiPostProcess(longlong param_1,char param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  ulonglong uVar10;
  
  cVar1 = *(char *)(param_1 + 0x18);
  uVar9 = 0;
  uVar2 = *(uint *)(param_1 + 8);
  puVar4 = *(uint **)(param_1 + 0x10);
  if (cVar1 == '\0') {
    uVar7 = puVar4[0xc];
    uVar3 = puVar4[0xd];
    uVar10 = (ulonglong)uVar3;
    uVar5 = uVar7 + param_3;
    if (param_2 == '\x01') {
      if (uVar5 <= uVar2) {
        if (((0x2f < uVar2) && (*puVar4 = uVar5, uVar9 = uVar5, (char)puVar4[0xb] < '\0')) &&
           (puVar8 = puVar4 + 0xf, uVar6 = uVar10, uVar3 != 0)) {
          do {
            uVar5 = (int)uVar6 - 1;
            uVar6 = (ulonglong)uVar5;
            if (uVar6 * 8 + 0x48 <= (ulonglong)uVar2) {
              puVar4[uVar6 * 2 + 0x10] = puVar8[uVar6];
            }
          } while (uVar5 != 0);
          if (uVar3 != 0) {
            uVar6 = 0x48;
            do {
              if (uVar6 <= uVar2) {
                *puVar8 = uVar7;
                uVar7 = uVar7 + 7 + puVar8[1] & 0xfffffff8;
              }
              uVar6 = uVar6 + 8;
              puVar8 = puVar8 + 2;
              uVar10 = uVar10 - 1;
            } while (uVar10 != 0);
          }
        }
        goto LAB_1c0009a3b;
      }
      param_2 = '\x12';
    }
LAB_1c0009a18:
    if ((param_2 != '\x12') || (uVar2 < 0x38)) goto LAB_1c0009a3b;
    puVar4[0xc] = uVar5;
  }
  else {
    if (cVar1 == '\x01') {
      uVar5 = puVar4[0xe] + param_3;
      if (param_2 == '\x01') {
        if (0x2f < uVar2) {
          *puVar4 = uVar5;
          uVar9 = uVar5;
        }
        goto LAB_1c0009a3b;
      }
      goto LAB_1c0009a18;
    }
    if (cVar1 != '\t') goto LAB_1c0009a3b;
    uVar7 = puVar4[0xf] + param_3;
    if (param_2 == '\x01') {
      if (0x47 < uVar2) {
        *puVar4 = uVar7;
        puVar4[0x10] = param_3;
        uVar9 = uVar7;
      }
      goto LAB_1c0009a3b;
    }
    if ((param_2 != '\x12') || (uVar2 < 0x38)) goto LAB_1c0009a3b;
    puVar4[0xc] = uVar7;
  }
  *puVar4 = 0x38;
  puVar4[0xb] = 0x20;
  param_2 = '\x01';
  uVar9 = 0x38;
LAB_1c0009a3b:
  *(uint *)(param_1 + 0x1c) = uVar9;
  *(char *)(param_1 + 0x19) = param_2;
  return;
}



===== ScsiWmipProcessRequest @ 1c0009ac8 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

char ScsiWmipProcessRequest
               (uint *param_1,byte param_2,undefined8 param_3,undefined8 param_4,longlong *param_5,
               uint param_6,uint *param_7,uint *param_8,undefined4 *param_9)

{
  uint uVar1;
  short sVar2;
  ulonglong uVar3;
  char cVar4;
  uint uVar5;
  code *pcVar6;
  uint uVar7;
  longlong *plVar8;
  ulonglong *puVar9;
  undefined2 *puVar10;
  int iVar11;
  longlong lVar12;
  uint *puVar13;
  ushort uVar14;
  uint uVar15;
  uint uVar16;
  undefined8 uVar17;
  ulonglong uVar18;
  undefined4 uVar19;
  short *local_38 [2];
  
  puVar13 = (uint *)0x0;
  uVar18 = 0;
  uVar15 = 0;
  *param_9 = 0;
  uVar5 = 0;
  if (param_2 != 8) {
    if (*param_1 != 0) {
      plVar8 = *(longlong **)(param_1 + 2);
      do {
        if ((*param_5 == *(longlong *)*plVar8) && (param_5[1] == ((longlong *)*plVar8)[1])) {
          uVar15 = *(uint *)(*(longlong **)(param_1 + 2) + uVar18 * 2 + 1);
          if (((2 < (byte)(param_2 - 1)) && (param_2 != 9)) ||
             ((uVar5 = param_7[0xd], -1 < (char)param_7[0xb] || (uVar5 < uVar15))))
          goto LAB_1c0009b9b;
          break;
        }
        uVar15 = (int)uVar18 + 1;
        uVar18 = (ulonglong)uVar15;
        plVar8 = plVar8 + 2;
      } while (uVar15 < *param_1);
    }
    *param_8 = 0;
    cVar4 = '\x04';
    goto LAB_1c0009f0d;
  }
LAB_1c0009b9b:
  if (param_2 < 6) {
    if (param_2 != 5) {
      if (param_2 == 0) {
        if (param_6 < 0x48) goto LAB_1c0009c1b;
        param_7[0xb] = param_7[0xb] & 0xffffffef;
        uVar5 = uVar15 * 8 + 0x40;
        param_7[0xd] = uVar15;
        param_7[0xc] = uVar5;
        if (param_6 < uVar5) {
          lVar12 = 0;
          iVar11 = 0;
        }
        else {
          puVar13 = param_7 + 0xf;
          lVar12 = (ulonglong)uVar5 + (longlong)param_7;
          iVar11 = param_6 - uVar5;
        }
        uVar5 = 0;
      }
      else {
        if (param_2 != 1) {
          if (param_2 == 2) {
            if (*(code **)(param_1 + 8) != (code *)0x0) {
              cVar4 = (**(code **)(param_1 + 8))
                                (param_3,param_4,uVar18,uVar5,param_7[0xf],
                                 (ulonglong)param_7[0xe] + (longlong)param_7);
              return cVar4;
            }
          }
          else if (param_2 == 3) {
            if (*(code **)(param_1 + 10) != (code *)0x0) {
              cVar4 = (**(code **)(param_1 + 10))
                                (param_3,param_4,uVar18,uVar5,param_7[0xe],param_7[0x10],
                                 (ulonglong)param_7[0xf] + (longlong)param_7);
              return cVar4;
            }
          }
          else if (param_2 == 4) {
            pcVar6 = *(code **)(param_1 + 0xe);
            if (pcVar6 != (code *)0x0) {
              uVar17 = 0;
              goto LAB_1c0009f30;
            }
            goto LAB_1c0009f45;
          }
LAB_1c0009c1b:
          cVar4 = '\x04';
          goto LAB_1c0009f48;
        }
        if (param_6 < 0x40) {
          if (param_6 < 4) {
            *(undefined1 *)param_7 = 8;
            return '\x12';
          }
          *param_7 = 0x40;
          return '\x12';
        }
        iVar11 = param_6 - param_7[0xe];
        lVar12 = (longlong)param_7 + (ulonglong)param_7[0xe];
        puVar13 = param_7 + 0xf;
        uVar15 = 1;
      }
      pcVar6 = *(code **)(param_1 + 6);
LAB_1c0009cfe:
      cVar4 = (*pcVar6)(param_3,param_4,uVar18,uVar5,uVar15,puVar13,iVar11,lVar12);
      return cVar4;
    }
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar19 = 0;
      uVar17 = 0;
      goto LAB_1c0009f35;
    }
  }
  else if (param_2 == 6) {
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar17 = 1;
LAB_1c0009f30:
      uVar19 = 1;
LAB_1c0009f35:
      cVar4 = (*pcVar6)(param_3,param_4,uVar18,uVar17,uVar19);
      return cVar4;
    }
  }
  else {
    if (param_2 != 7) {
      if (param_2 != 8) {
        if (((param_2 == 9) && (pcVar6 = *(code **)(param_1 + 0xc), pcVar6 != (code *)0x0)) &&
           (0x47 < param_6)) {
          uVar15 = param_7[0xf];
          if (uVar15 <= param_6) {
            lVar12 = (longlong)param_7 + (ulonglong)uVar15;
            iVar11 = param_6 - uVar15;
            puVar13 = (uint *)(ulonglong)param_7[0x10];
            uVar15 = param_7[0xe];
            goto LAB_1c0009cfe;
          }
        }
        goto LAB_1c0009c1b;
      }
      cVar4 = (**(code **)(param_1 + 4))(param_3,param_4,local_38);
      if (cVar4 == '\x01') {
        uVar15 = *param_1;
        uVar18 = (ulonglong)uVar15;
        lVar12 = *(longlong *)(param_1 + 2);
        uVar16 = uVar15 * 0x20 + 0x18;
        uVar5 = uVar15 * 0x20 + 0x34;
        if (local_38[0] == (short *)0x0) {
          uVar14 = 0;
        }
        else {
          uVar14 = 0;
          sVar2 = *local_38[0];
          while (sVar2 != 0) {
            uVar14 = uVar14 + 1;
            sVar2 = local_38[0][uVar14];
          }
          uVar14 = uVar14 * 2;
        }
        uVar7 = uVar14 + uVar5;
        if ((uVar7 < uVar5) || (uVar1 = uVar7 + 2, uVar1 < uVar7)) {
          cVar4 = '\x04';
          goto LAB_1c0009efe;
        }
        if (param_6 < uVar1) {
          if (param_6 < 4) {
            *(undefined1 *)param_7 = 8;
          }
          else {
            *param_7 = uVar1;
            param_6 = 4;
          }
        }
        else {
          *param_7 = uVar1;
          param_7[1] = 0;
          param_7[2] = 0;
          param_7[3] = uVar5;
          param_7[4] = uVar15;
          if (uVar15 != 0) {
            puVar13 = (uint *)(lVar12 + 0xc);
            puVar9 = (ulonglong *)(param_7 + 0xc);
            do {
              uVar3 = (*(ulonglong **)(puVar13 + -3))[1];
              puVar9[-3] = **(ulonglong **)(puVar13 + -3);
              puVar9[-2] = uVar3;
              if (puVar13[-1] == 0xffffffff) {
                *(uint *)(puVar9 + -1) = *puVar13;
                *puVar9 = 0;
                *(undefined4 *)((longlong)puVar9 + -4) = 0;
              }
              else {
                *(uint *)(puVar9 + -1) = *puVar13 | 8;
                *puVar9 = (ulonglong)uVar16;
                *(uint *)((longlong)puVar9 + -4) = puVar13[-1];
              }
              puVar9 = puVar9 + 4;
              puVar13 = puVar13 + 4;
              uVar18 = uVar18 - 1;
            } while (uVar18 != 0);
          }
          puVar10 = (undefined2 *)((ulonglong)uVar16 + (longlong)param_7);
          *puVar10 = 0x1a;
          memcpy(puVar10 + 1,L"ScsiMiniPort",0x1a);
          *(ushort *)((ulonglong)uVar5 + (longlong)param_7) = uVar14;
          memcpy((ushort *)((ulonglong)uVar5 + (longlong)param_7) + 1,local_38[0],(ulonglong)uVar14)
          ;
          param_6 = uVar1;
        }
      }
      else {
LAB_1c0009efe:
        param_6 = 0;
      }
      *param_8 = param_6;
LAB_1c0009f0d:
      *param_9 = 1;
      return cVar4;
    }
    pcVar6 = *(code **)(param_1 + 0xe);
    if (pcVar6 != (code *)0x0) {
      uVar19 = 0;
      uVar17 = 1;
      goto LAB_1c0009f35;
    }
  }
LAB_1c0009f45:
  cVar4 = '\x01';
LAB_1c0009f48:
  *param_9 = 1;
  return cVar4;
}



===== __security_check_cookie @ 1c0009f80 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_check_icall @ 1c0009fa0 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 1c0009fb0 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 1c0009fd0 =====

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



===== _guard_dispatch_icall @ 1c000a040 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x0001c000a040. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== memcpy @ 1c000a080 =====

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
        if (uVar12 == 0) goto LAB_1c000a237;
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
LAB_1c000a237:
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
      if (uVar12 == 0) goto LAB_1c000a092;
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
LAB_1c000a092:
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



===== memset @ 1c000a3c0 =====

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
      if (uVar5 == 0) goto LAB_1c000a480;
      puVar3 = puVar3 + (uVar5 - 8);
      uVar6 = uVar6 + 1;
      switch(uVar5) {
      case 2:
        goto switchD_1c000a47d_caseD_2;
      case 3:
        goto switchD_1c000a47d_caseD_3;
      case 4:
        goto switchD_1c000a47d_caseD_4;
      case 5:
        goto switchD_1c000a47d_caseD_5;
      case 6:
        goto switchD_1c000a47d_caseD_6;
      case 7:
        goto switchD_1c000a47d_caseD_7;
      }
      while( true ) {
        puVar3[7] = uVar4;
        puVar3 = puVar3 + 8;
        uVar6 = uVar6 - 1;
        if (uVar6 == 0) break;
LAB_1c000a480:
        *puVar3 = uVar4;
switchD_1c000a47d_caseD_7:
        puVar3[1] = uVar4;
switchD_1c000a47d_caseD_6:
        puVar3[2] = uVar4;
switchD_1c000a47d_caseD_5:
        puVar3[3] = uVar4;
switchD_1c000a47d_caseD_4:
        puVar3[4] = uVar4;
switchD_1c000a47d_caseD_3:
        puVar3[5] = uVar4;
switchD_1c000a47d_caseD_2:
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



===== entry @ 1c000f000 =====

void entry(undefined8 param_1,undefined8 param_2)

{
  undefined4 local_d8;
  undefined4 local_d4;
  code *local_d0;
  code *local_c8;
  code *local_c0;
  code *local_b8;
  code *local_b0;
  undefined4 local_98;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_80;
  undefined1 local_7c;
  undefined2 local_7a;
  undefined2 local_6e;
  code *local_60;
  code *local_58;
  undefined4 local_20;
  
  __security_init_cookie();
  MemFastZero(&local_d8,0xd0);
  local_d8 = 0xd0;
  local_d0 = MegaSASInitialize;
  local_80 = 0x1010101;
  local_b8 = MegaSASFindAdapter;
  local_8c = 2;
  local_c8 = MegaSASStartIo;
  local_d4 = 5;
  local_58 = MegaSASBuildIo;
  local_7c = 1;
  local_c0 = LegacyInterrupts;
  local_b0 = MegaSASResetBus;
  local_60 = MegaSASPnPControl;
  local_6e = 4;
  local_7a = 4;
  local_20 = 0x20;
  local_98 = 0x8a40;
  local_90 = 0x678;
  StorPortInitialize(param_1,param_2,&local_d8,0);
  return;
}



===== __security_init_cookie @ 1c000f0e8 =====

void __cdecl __security_init_cookie(void)

{
  code *pcVar1;
  
  if ((__security_cookie == 0) || (__security_cookie == 0x2b992ddfa232)) {
    pcVar1 = (code *)swi(0x29);
    (*pcVar1)(6);
  }
  return;
}


