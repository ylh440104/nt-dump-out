
===== SymCryptXtsAesDecryptDataUnitXmm @ 180001010 =====

/* WARNING: Removing unreachable block (ram,0x0001800010bf) */

void SymCryptXtsAesDecryptDataUnitXmm
               (longlong param_1,uint *param_2,uint *param_3,uint *param_4,
               undefined1 (*param_5) [16],longlong param_6)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  longlong lVar5;
  undefined1 (*pauVar6) [16];
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  longlong lVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong *puVar15;
  undefined1 (*pauVar16) [16];
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  undefined1 auVar20 [16];
  uint uVar24;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  undefined1 auVar25 [16];
  uint uVar30;
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  uint uVar33;
  uint uVar34;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  undefined1 auVar35 [16];
  uint uVar41;
  uint uVar42;
  uint uVar44;
  uint uVar45;
  uint uVar46;
  undefined1 auVar43 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  
  pauVar6 = *(undefined1 (**) [16])(param_1 + 0x1d8);
  uVar11 = (ulonglong)((uint)param_6 & 0x7f);
  uVar34 = *param_2;
  uVar37 = param_2[1];
  uVar39 = param_2[2];
  uVar41 = param_2[3];
  lVar5 = 0;
  if (uVar11 - 1 < 0xf) {
    lVar5 = 0x80;
  }
  uVar28 = uVar41 >> 0x1c;
  uVar42 = (int)uVar41 >> 0x1f & 0x87U ^ uVar34 << 1;
  uVar44 = (int)uVar34 >> 0x1f & 1U ^ uVar37 << 1;
  uVar45 = (int)uVar37 >> 0x1f & 1U ^ uVar39 << 1;
  uVar46 = (int)uVar39 >> 0x1f & 1U ^ uVar41 << 1;
  uVar11 = uVar11 + lVar5;
  uVar33 = (int)uVar46 >> 0x1f & 0x87U ^ uVar42 << 1;
  uVar36 = (int)uVar42 >> 0x1f & 1U ^ uVar44 << 1;
  uVar38 = (int)uVar44 >> 0x1f & 1U ^ uVar45 << 1;
  uVar40 = (int)uVar45 >> 0x1f & 1U ^ uVar46 << 1;
  uVar17 = uVar37 << 4 ^ uVar34 >> 0x1c;
  uVar18 = uVar39 << 4 ^ uVar37 >> 0x1c;
  uVar19 = uVar41 << 4 ^ uVar39 >> 0x1c;
  uVar30 = uVar28 << 7 ^ uVar28 << 2 ^ uVar28 << 1 ^ uVar28 ^ uVar34 << 4;
  uVar24 = (int)uVar19 >> 0x1f & 0x87U ^ uVar30 << 1;
  uVar26 = (int)uVar30 >> 0x1f & 1U ^ uVar17 << 1;
  uVar27 = (int)uVar17 >> 0x1f & 1U ^ uVar18 << 1;
  uVar29 = (int)uVar18 >> 0x1f & 1U ^ uVar19 << 1;
  uVar28 = (int)uVar29 >> 0x1f & 0x87U ^ uVar24 << 1;
  uVar21 = (int)uVar24 >> 0x1f & 1U ^ uVar26 << 1;
  uVar22 = (int)uVar26 >> 0x1f & 1U ^ uVar27 << 1;
  uVar23 = (int)uVar27 >> 0x1f & 1U ^ uVar29 << 1;
  *param_3 = uVar34;
  param_3[1] = uVar37;
  param_3[2] = uVar39;
  param_3[3] = uVar41;
  param_3[4] = uVar42;
  param_3[5] = uVar44;
  param_3[6] = uVar45;
  param_3[7] = uVar46;
  param_3[8] = uVar33;
  param_3[9] = uVar36;
  param_3[10] = uVar38;
  param_3[0xb] = uVar40;
  param_3[0xc] = (int)uVar40 >> 0x1f & 0x87U ^ uVar33 << 1;
  param_3[0xd] = (int)uVar33 >> 0x1f & 1U ^ uVar36 << 1;
  param_3[0xe] = (int)uVar36 >> 0x1f & 1U ^ uVar38 << 1;
  param_3[0xf] = (int)uVar38 >> 0x1f & 1U ^ uVar40 << 1;
  param_3[0x10] = uVar30;
  param_3[0x11] = uVar17;
  param_3[0x12] = uVar18;
  param_3[0x13] = uVar19;
  param_3[0x14] = uVar24;
  param_3[0x15] = uVar26;
  param_3[0x16] = uVar27;
  param_3[0x17] = uVar29;
  param_3[0x18] = uVar28;
  param_3[0x19] = uVar21;
  param_3[0x1a] = uVar22;
  param_3[0x1b] = uVar23;
  param_3[0x1c] = (int)uVar23 >> 0x1f & 0x87U ^ uVar28 << 1;
  param_3[0x1d] = (int)uVar28 >> 0x1f & 1U ^ uVar21 << 1;
  param_3[0x1e] = (int)uVar21 >> 0x1f & 1U ^ uVar22 << 1;
  param_3[0x1f] = (int)uVar22 >> 0x1f & 1U ^ uVar23 << 1;
  puVar1 = *(uint **)(param_1 + 0x1d0);
  uVar10 = *(ulonglong *)(param_3 + 0x1c);
  uVar8 = *(ulonglong *)(param_3 + 0x1e);
  uVar34 = *puVar1;
  uVar37 = puVar1[1];
  uVar39 = puVar1[2];
  uVar41 = puVar1[3];
  puVar1 = *(uint **)(param_1 + 0x1d8);
  uVar17 = *puVar1;
  uVar18 = puVar1[1];
  uVar19 = puVar1[2];
  uVar28 = puVar1[3];
  if (param_6 - uVar11 != 0) {
    lVar5 = ((param_6 - uVar11) - 1 >> 7) + 1;
    do {
      auVar31._0_4_ = uVar34 ^ *param_3 ^ *param_4;
      auVar31._4_4_ = uVar37 ^ param_3[1] ^ param_4[1];
      auVar31._8_4_ = uVar39 ^ param_3[2] ^ param_4[2];
      auVar31._12_4_ = uVar41 ^ param_3[3] ^ param_4[3];
      pauVar16 = (undefined1 (*) [16])(*(longlong *)(param_1 + 0x1d0) + 0x10);
      lVar12 = 2;
      auVar32._0_4_ = uVar34 ^ param_3[4] ^ param_4[4];
      auVar32._4_4_ = uVar37 ^ param_3[5] ^ param_4[5];
      auVar32._8_4_ = uVar39 ^ param_3[6] ^ param_4[6];
      auVar32._12_4_ = uVar41 ^ param_3[7] ^ param_4[7];
      auVar35._0_4_ = uVar34 ^ param_3[8] ^ param_4[8];
      auVar35._4_4_ = uVar37 ^ param_3[9] ^ param_4[9];
      auVar35._8_4_ = uVar39 ^ param_3[10] ^ param_4[10];
      auVar35._12_4_ = uVar41 ^ param_3[0xb] ^ param_4[0xb];
      auVar43._0_4_ = uVar34 ^ param_3[0xc] ^ param_4[0xc];
      auVar43._4_4_ = uVar37 ^ param_3[0xd] ^ param_4[0xd];
      auVar43._8_4_ = uVar39 ^ param_3[0xe] ^ param_4[0xe];
      auVar43._12_4_ = uVar41 ^ param_3[0xf] ^ param_4[0xf];
      auVar47._0_4_ = uVar34 ^ param_3[0x10] ^ param_4[0x10];
      auVar47._4_4_ = uVar37 ^ param_3[0x11] ^ param_4[0x11];
      auVar47._8_4_ = uVar39 ^ param_3[0x12] ^ param_4[0x12];
      auVar47._12_4_ = uVar41 ^ param_3[0x13] ^ param_4[0x13];
      auVar48._0_4_ = uVar34 ^ param_3[0x14] ^ param_4[0x14];
      auVar48._4_4_ = uVar37 ^ param_3[0x15] ^ param_4[0x15];
      auVar48._8_4_ = uVar39 ^ param_3[0x16] ^ param_4[0x16];
      auVar48._12_4_ = uVar41 ^ param_3[0x17] ^ param_4[0x17];
      auVar49._0_4_ = uVar34 ^ param_3[0x18] ^ param_4[0x18];
      auVar49._4_4_ = uVar37 ^ param_3[0x19] ^ param_4[0x19];
      auVar49._8_4_ = uVar39 ^ param_3[0x1a] ^ param_4[0x1a];
      auVar49._12_4_ = uVar41 ^ param_3[0x1b] ^ param_4[0x1b];
      auVar50._0_4_ = uVar34 ^ param_3[0x1c] ^ param_4[0x1c];
      auVar50._4_4_ = uVar37 ^ param_3[0x1d] ^ param_4[0x1d];
      auVar50._8_4_ = uVar39 ^ param_3[0x1e] ^ param_4[0x1e];
      auVar50._12_4_ = uVar41 ^ param_3[0x1f] ^ param_4[0x1f];
      puVar15 = (ulonglong *)(param_3 + 10);
      do {
        auVar51 = *pauVar16;
        uVar7 = uVar10 >> 0x3f ^ uVar8 * 2;
        *(uint *)(puVar15 + 0xb) = uVar17 ^ (uint)puVar15[-5];
        *(uint *)((longlong)puVar15 + 0x5c) = uVar18 ^ *(uint *)((longlong)puVar15 + -0x24);
        *(uint *)(puVar15 + 0xc) = uVar19 ^ (uint)puVar15[-4];
        *(uint *)((longlong)puVar15 + 100) = uVar28 ^ *(uint *)((longlong)puVar15 + -0x1c);
        uVar13 = (ulonglong)((uint)((longlong)uVar8 >> 0x3f) & 0x87) ^ uVar10 * 2;
        puVar15[-5] = uVar13;
        puVar15[-4] = uVar7;
        uVar7 = uVar7 * 2;
        auVar25 = pauVar16[1];
        uVar9 = (uVar10 & 0x7fffffffffffffff) >> 0x3e ^ uVar7;
        uVar14 = (ulonglong)((uint)((longlong)(uVar8 * 2) >> 0x3f) & 0x87) ^ uVar13 * 2;
        *(uint *)(puVar15 + 0xd) = uVar17 ^ (uint)puVar15[-3];
        *(uint *)((longlong)puVar15 + 0x6c) = uVar18 ^ *(uint *)((longlong)puVar15 + -0x14);
        *(uint *)(puVar15 + 0xe) = uVar19 ^ (uint)puVar15[-2];
        *(uint *)((longlong)puVar15 + 0x74) = uVar28 ^ *(uint *)((longlong)puVar15 + -0xc);
        uVar10 = uVar9 * 2;
        puVar15[-3] = uVar14;
        puVar15[-2] = uVar9;
        auVar20 = pauVar16[2];
        uVar8 = (uVar13 & 0x7fffffffffffffff) >> 0x3e ^ uVar10;
        *(uint *)(puVar15 + 0xf) = uVar17 ^ (uint)puVar15[-1];
        *(uint *)((longlong)puVar15 + 0x7c) = uVar18 ^ *(uint *)((longlong)puVar15 + -4);
        *(uint *)(puVar15 + 0x10) = uVar19 ^ (uint)*puVar15;
        *(uint *)((longlong)puVar15 + 0x84) = uVar28 ^ *(uint *)((longlong)puVar15 + 4);
        auVar31 = aesdec(auVar31,auVar51);
        auVar32 = aesdec(auVar32,auVar51);
        auVar35 = aesdec(auVar35,auVar51);
        auVar43 = aesdec(auVar43,auVar51);
        auVar47 = aesdec(auVar47,auVar51);
        auVar48 = aesdec(auVar48,auVar51);
        auVar49 = aesdec(auVar49,auVar51);
        auVar50 = aesdec(auVar50,auVar51);
        *puVar15 = uVar8;
        auVar31 = aesdec(auVar31,auVar25);
        auVar32 = aesdec(auVar32,auVar25);
        auVar35 = aesdec(auVar35,auVar25);
        auVar43 = aesdec(auVar43,auVar25);
        auVar47 = aesdec(auVar47,auVar25);
        auVar48 = aesdec(auVar48,auVar25);
        auVar49 = aesdec(auVar49,auVar25);
        auVar51 = aesdec(auVar50,auVar25);
        uVar7 = (ulonglong)((uint)((longlong)uVar7 >> 0x3f) & 0x87) ^ uVar14 * 2;
        puVar15[-1] = uVar7;
        auVar50 = pauVar16[3];
        auVar31 = aesdec(auVar31,auVar20);
        auVar31 = aesdec(auVar31,auVar50);
        auVar32 = aesdec(auVar32,auVar20);
        auVar32 = aesdec(auVar32,auVar50);
        auVar35 = aesdec(auVar35,auVar20);
        auVar35 = aesdec(auVar35,auVar50);
        auVar43 = aesdec(auVar43,auVar20);
        auVar43 = aesdec(auVar43,auVar50);
        auVar47 = aesdec(auVar47,auVar20);
        auVar47 = aesdec(auVar47,auVar50);
        auVar48 = aesdec(auVar48,auVar20);
        auVar48 = aesdec(auVar48,auVar50);
        auVar49 = aesdec(auVar49,auVar20);
        auVar49 = aesdec(auVar49,auVar50);
        auVar51 = aesdec(auVar51,auVar20);
        auVar50 = aesdec(auVar51,auVar50);
        *(uint *)(puVar15 + 0x11) = uVar17 ^ (uint)puVar15[1];
        *(uint *)((longlong)puVar15 + 0x8c) = uVar18 ^ *(uint *)((longlong)puVar15 + 0xc);
        *(uint *)(puVar15 + 0x12) = uVar19 ^ (uint)puVar15[2];
        *(uint *)((longlong)puVar15 + 0x94) = uVar28 ^ *(uint *)((longlong)puVar15 + 0x14);
        uVar8 = (uVar14 & 0x7fffffffffffffff) >> 0x3e ^ uVar8 * 2;
        puVar15[2] = uVar8;
        uVar10 = (ulonglong)((uint)((longlong)uVar10 >> 0x3f) & 0x87) ^ uVar7 * 2;
        pauVar16 = pauVar16 + 4;
        puVar15[1] = uVar10;
        lVar12 = lVar12 + -1;
        puVar15 = puVar15 + 8;
      } while (lVar12 != 0);
      do {
        auVar51 = *pauVar16;
        pauVar16 = pauVar16 + 1;
        auVar31 = aesdec(auVar31,auVar51);
        auVar32 = aesdec(auVar32,auVar51);
        auVar35 = aesdec(auVar35,auVar51);
        auVar43 = aesdec(auVar43,auVar51);
        auVar47 = aesdec(auVar47,auVar51);
        auVar48 = aesdec(auVar48,auVar51);
        auVar49 = aesdec(auVar49,auVar51);
        auVar50 = aesdec(auVar50,auVar51);
      } while (pauVar16 < pauVar6);
      auVar31 = aesdeclast(auVar31,*(undefined1 (*) [16])(param_3 + 0x20));
      *param_5 = auVar31;
      auVar31 = aesdeclast(auVar32,*(undefined1 (*) [16])(param_3 + 0x24));
      param_5[1] = auVar31;
      param_4 = param_4 + 0x20;
      auVar31 = aesdeclast(auVar35,*(undefined1 (*) [16])(param_3 + 0x28));
      param_5[2] = auVar31;
      auVar31 = aesdeclast(auVar43,*(undefined1 (*) [16])(param_3 + 0x2c));
      param_5[3] = auVar31;
      auVar31 = aesdeclast(auVar47,*(undefined1 (*) [16])(param_3 + 0x30));
      param_5[4] = auVar31;
      auVar31 = aesdeclast(auVar48,*(undefined1 (*) [16])(param_3 + 0x34));
      param_5[5] = auVar31;
      auVar31 = aesdeclast(auVar49,*(undefined1 (*) [16])(param_3 + 0x38));
      param_5[6] = auVar31;
      auVar31 = aesdeclast(auVar50,*(undefined1 (*) [16])(param_3 + 0x3c));
      param_5[7] = auVar31;
      param_5 = param_5 + 8;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  if (uVar11 != 0) {
    uVar34 = *param_3;
    uVar37 = param_3[1];
    uVar39 = param_3[2];
    uVar41 = param_3[3];
    if (0x1f < uVar11) {
      uVar10 = uVar11 - 0x10 >> 4;
      uVar11 = uVar11 + uVar10 * -0x10;
      do {
        puVar1 = *(uint **)(param_1 + 0x1d0);
        uVar17 = *param_4;
        puVar2 = param_4 + 1;
        puVar3 = param_4 + 2;
        puVar4 = param_4 + 3;
        param_4 = param_4 + 4;
        pauVar6 = (undefined1 (*) [16])(puVar1 + 8);
        auVar51._0_4_ = uVar17 ^ uVar34 ^ *puVar1;
        auVar51._4_4_ = *puVar2 ^ uVar37 ^ puVar1[1];
        auVar51._8_4_ = *puVar3 ^ uVar39 ^ puVar1[2];
        auVar51._12_4_ = *puVar4 ^ uVar41 ^ puVar1[3];
        auVar31 = aesdec(auVar51,*(undefined1 (*) [16])(puVar1 + 4));
        do {
          auVar32 = *pauVar6;
          pauVar16 = pauVar6 + 1;
          pauVar6 = pauVar6 + 2;
          auVar31 = aesdec(auVar31,auVar32);
          auVar31 = aesdec(auVar31,*pauVar16);
        } while (pauVar6 < *(undefined1 (**) [16])(param_1 + 0x1d8));
        auVar31 = aesdeclast(auVar31,*pauVar6);
        uVar17 = (int)uVar34 >> 0x1f;
        uVar18 = (int)uVar37 >> 0x1f;
        uVar19 = (int)uVar39 >> 0x1f;
        *(uint *)*param_5 = auVar31._0_4_ ^ uVar34;
        *(uint *)(*param_5 + 4) = auVar31._4_4_ ^ uVar37;
        *(uint *)(*param_5 + 8) = auVar31._8_4_ ^ uVar39;
        *(uint *)(*param_5 + 0xc) = auVar31._12_4_ ^ uVar41;
        param_5 = param_5 + 1;
        uVar34 = (int)uVar41 >> 0x1f & 0x87U ^ uVar34 << 1;
        uVar37 = uVar17 & 1 ^ uVar37 << 1;
        uVar39 = uVar18 & 1 ^ uVar39 << 1;
        uVar41 = uVar19 & 1 ^ uVar41 << 1;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
    if (0x10 < uVar11) {
      puVar1 = *(uint **)(param_1 + 0x1d0);
      pauVar6 = (undefined1 (*) [16])(puVar1 + 8);
      uVar17 = (int)uVar41 >> 0x1f & 0x87U ^ uVar34 << 1;
      uVar18 = (int)uVar34 >> 0x1f & 1U ^ uVar37 << 1;
      uVar19 = (int)uVar37 >> 0x1f & 1U ^ uVar39 << 1;
      uVar28 = (int)uVar39 >> 0x1f & 1U ^ uVar41 << 1;
      auVar25._0_4_ = uVar17 ^ *param_4 ^ *puVar1;
      auVar25._4_4_ = uVar18 ^ param_4[1] ^ puVar1[1];
      auVar25._8_4_ = uVar19 ^ param_4[2] ^ puVar1[2];
      auVar25._12_4_ = uVar28 ^ param_4[3] ^ puVar1[3];
      auVar31 = aesdec(auVar25,*(undefined1 (*) [16])(puVar1 + 4));
      do {
        auVar32 = *pauVar6;
        pauVar16 = pauVar6 + 1;
        pauVar6 = pauVar6 + 2;
        auVar31 = aesdec(auVar31,auVar32);
        auVar31 = aesdec(auVar31,*pauVar16);
      } while (pauVar6 < *(undefined1 (**) [16])(param_1 + 0x1d8));
      auVar31 = aesdeclast(auVar31,*pauVar6);
      uVar17 = auVar31._0_4_ ^ uVar17;
      uVar18 = auVar31._4_4_ ^ uVar18;
      uVar19 = auVar31._8_4_ ^ uVar19;
      uVar28 = auVar31._12_4_ ^ uVar28;
      *param_3 = uVar17;
      param_3[1] = uVar18;
      param_3[2] = uVar19;
      param_3[3] = uVar28;
      param_3[4] = uVar17;
      param_3[5] = uVar18;
      param_3[6] = uVar19;
      param_3[7] = uVar28;
      memmove(param_3,param_4 + 4,uVar11 - 0x10);
      memmove(param_5 + 1,param_3 + 4,uVar11 - 0x10);
      param_4 = param_3;
    }
    puVar1 = *(uint **)(param_1 + 0x1d0);
    pauVar6 = (undefined1 (*) [16])(puVar1 + 8);
    auVar20._0_4_ = *param_4 ^ uVar34 ^ *puVar1;
    auVar20._4_4_ = param_4[1] ^ uVar37 ^ puVar1[1];
    auVar20._8_4_ = param_4[2] ^ uVar39 ^ puVar1[2];
    auVar20._12_4_ = param_4[3] ^ uVar41 ^ puVar1[3];
    auVar31 = aesdec(auVar20,*(undefined1 (*) [16])(puVar1 + 4));
    do {
      auVar32 = *pauVar6;
      pauVar16 = pauVar6 + 1;
      pauVar6 = pauVar6 + 2;
      auVar31 = aesdec(auVar31,auVar32);
      auVar31 = aesdec(auVar31,*pauVar16);
    } while (pauVar6 < *(undefined1 (**) [16])(param_1 + 0x1d8));
    auVar31 = aesdeclast(auVar31,*pauVar6);
    *(uint *)*param_5 = auVar31._0_4_ ^ uVar34;
    *(uint *)(*param_5 + 4) = auVar31._4_4_ ^ uVar37;
    *(uint *)(*param_5 + 8) = auVar31._8_4_ ^ uVar39;
    *(uint *)(*param_5 + 0xc) = auVar31._12_4_ ^ uVar41;
  }
  return;
}



===== SymCryptAesCbcDecrypt @ 18000178c =====

void SymCryptAesCbcDecrypt
               (longlong param_1,uint *param_2,uint *param_3,uint *param_4,ulonglong param_5)

{
  if ((g_SymCryptCpuFeaturesNotPresent & 6) == 0) {
    SymCryptAesCbcDecryptXmm(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    SymCryptAesCbcDecryptAsm(param_1,param_2,(undefined8 *)param_3,(longlong)param_4,param_5);
  }
  return;
}



===== FveAesCbcDecryptSectorsNormal @ 1800017c0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FveAesCbcDecryptSectorsNormal
          (uint *param_1,ulonglong param_2,uint *param_3,uint param_4,ulonglong *param_5,
          uint param_6,uint *param_7)

{
  ulonglong *puVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  ulonglong *puVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  ulonglong uVar9;
  undefined1 auStackY_488 [32];
  ulonglong local_450;
  ulonglong local_448 [128];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_488;
  uVar7 = (ulonglong)param_6;
  uVar9 = param_4 / uVar7;
  if ((param_7 == (uint *)0x0) || ((*param_7 & 0x800) == 0)) {
    uVar8 = g_chunkedDecryptionMaxSize;
  }
  else {
    uVar8 = param_7[4];
  }
  if (param_6 < uVar8) {
    uVar2 = 0x40;
    if (uVar8 / param_6 < 0x40) {
      uVar2 = uVar8 / param_6;
    }
  }
  else {
    uVar2 = 1;
  }
  uVar8 = (uint)uVar9;
  local_450 = param_2;
  while (uVar8 != 0) {
    uVar6 = (ulonglong)uVar2;
    if ((uint)uVar9 < uVar2) {
      uVar6 = uVar9;
    }
    uVar8 = (uint)uVar6;
    if (uVar8 != 0) {
      puVar4 = local_448 + 1;
      uVar3 = uVar6;
      do {
        puVar4[-1] = local_450;
        local_450 = local_450 + uVar7;
        *puVar4 = 0;
        puVar4 = puVar4 + 2;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    puVar4 = local_448;
    if (0xf < uVar6 << 4) {
      do {
        SymCryptAesEncrypt(param_1,(uint *)puVar4,(undefined1 (*) [16])puVar4);
        puVar4 = puVar4 + 2;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    puVar4 = (ulonglong *)((uVar7 - 0x10) + (longlong)param_3);
    if (1 < uVar8) {
      puVar5 = local_448;
      uVar6 = (ulonglong)(uVar8 - 1);
      do {
        puVar5 = puVar5 + 2;
        *puVar5 = *puVar5 ^ *puVar4;
        puVar1 = puVar4 + 1;
        puVar4 = (ulonglong *)((longlong)puVar4 + uVar7);
        puVar5[1] = puVar5[1] ^ *puVar1;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    if ((g_SymCryptCpuFeaturesNotPresent & 6) == 0) {
      SymCryptAesCbcDecryptXmm
                ((longlong)param_1,(uint *)local_448,param_3,(uint *)param_5,
                 (ulonglong)(param_6 * uVar8));
    }
    else {
      SymCryptAesCbcDecryptAsm
                ((longlong)param_1,(uint *)local_448,(undefined8 *)param_3,(longlong)param_5,
                 (ulonglong)(param_6 * uVar8));
    }
    param_5 = (ulonglong *)((longlong)param_5 + uVar7);
    param_3 = (uint *)((longlong)param_3 + uVar7);
    if (1 < uVar8) {
      uVar6 = (ulonglong)(uVar8 - 1);
      puVar4 = local_448;
      param_3 = (uint *)((longlong)param_3 + (uVar8 - 1) * uVar7);
      do {
        puVar4 = puVar4 + 2;
        *param_5 = *param_5 ^ *puVar4;
        param_5[1] = param_5[1] ^ puVar4[1];
        param_5 = (ulonglong *)((longlong)param_5 + uVar7);
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    uVar8 = (uint)uVar9 - uVar8;
    uVar9 = (ulonglong)uVar8;
  }
  return 0;
}



===== SymCryptAesEncrypt @ 1800019e0 =====

void SymCryptAesEncrypt(uint *param_1,uint *param_2,undefined1 (*param_3) [16])

{
  undefined1 (*pauVar1) [16];
  undefined1 auVar2 [16];
  undefined1 (*pauVar3) [16];
  undefined1 auVar4 [16];
  
  if ((g_SymCryptCpuFeaturesNotPresent & 6) == 0) {
    pauVar3 = (undefined1 (*) [16])(param_1 + 8);
    auVar4._0_4_ = *param_1 ^ *param_2;
    auVar4._4_4_ = param_1[1] ^ param_2[1];
    auVar4._8_4_ = param_1[2] ^ param_2[2];
    auVar4._12_4_ = param_1[3] ^ param_2[3];
    auVar4 = aesenc(auVar4,*(undefined1 (*) [16])(param_1 + 4));
    do {
      auVar2 = *pauVar3;
      pauVar1 = pauVar3 + 1;
      pauVar3 = pauVar3 + 2;
      auVar4 = aesenc(auVar4,auVar2);
      auVar4 = aesenc(auVar4,*pauVar1);
    } while (pauVar3 < *(undefined1 (**) [16])(param_1 + 0x74));
    auVar4 = aesenclast(auVar4,*pauVar3);
    *param_3 = auVar4;
  }
  else {
    SymCryptAesEncryptAsm(param_1,(longlong)param_2,(undefined4 *)param_3);
  }
  return;
}



===== SymCryptAesCbcDecryptXmm @ 180001a50 =====

void SymCryptAesCbcDecryptXmm
               (longlong param_1,uint *param_2,uint *param_3,uint *param_4,ulonglong param_5)

{
  undefined1 (*pauVar1) [16];
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  undefined1 (*pauVar9) [16];
  ulonglong uVar10;
  uint uVar11;
  uint uVar15;
  uint uVar16;
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  uint uVar17;
  undefined1 auVar14 [16];
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  undefined1 auVar22 [16];
  uint uVar29;
  undefined1 auVar23 [16];
  uint uVar30;
  uint uVar31;
  uint uVar35;
  uint uVar36;
  undefined1 auVar32 [16];
  uint uVar37;
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  uint uVar38;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  undefined1 auVar39 [16];
  uint uVar43;
  uint uVar46;
  uint uVar47;
  undefined1 auVar44 [16];
  uint uVar48;
  undefined1 auVar45 [16];
  uint uVar49;
  uint uVar52;
  uint uVar53;
  undefined1 auVar50 [16];
  uint uVar54;
  undefined1 auVar51 [16];
  uint uVar55;
  uint uVar56;
  uint uVar57;
  uint uVar58;
  uint uVar59;
  uint uVar60;
  uint uVar63;
  uint uVar64;
  undefined1 auVar61 [16];
  uint uVar65;
  undefined1 auVar62 [16];
  uint uVar66;
  uint uVar69;
  uint uVar70;
  undefined1 auVar67 [16];
  uint uVar71;
  undefined1 auVar68 [16];
  uint uVar72;
  uint uVar75;
  uint uVar76;
  undefined1 auVar73 [16];
  uint uVar77;
  undefined1 auVar74 [16];
  undefined1 auVar78 [16];
  uint local_118;
  uint uStack_114;
  uint uStack_110;
  uint uStack_10c;
  
  uVar31 = 0;
  uVar35 = 0;
  uVar36 = 0;
  uVar37 = 0;
  uVar43 = 0;
  uVar46 = 0;
  uVar47 = 0;
  uVar48 = 0;
  uVar49 = 0;
  uVar52 = 0;
  uVar53 = 0;
  uVar54 = 0;
  uVar25 = 0;
  uVar27 = 0;
  uVar30 = 0;
  uVar55 = 0;
  uVar60 = 0;
  uVar63 = 0;
  uVar64 = 0;
  uVar65 = 0;
  uVar66 = 0;
  uVar69 = 0;
  uVar70 = 0;
  uVar71 = 0;
  uVar72 = 0;
  uVar75 = 0;
  uVar76 = 0;
  uVar77 = 0;
  uVar11 = 0;
  uVar15 = 0;
  uVar16 = 0;
  uVar17 = 0;
  uVar24 = 0;
  uVar26 = 0;
  uVar29 = 0;
  uVar28 = 0;
  uVar38 = 0;
  uVar40 = 0;
  uVar41 = 0;
  uVar42 = 0;
  uVar56 = 0;
  uVar57 = 0;
  uVar58 = 0;
  uVar59 = 0;
  if (param_5 < 0x10) {
    return;
  }
  local_118 = *param_2;
  uStack_114 = param_2[1];
  uStack_110 = param_2[2];
  uStack_10c = param_2[3];
  if (0x7f < param_5) {
    uVar10 = param_5 >> 7;
    param_5 = param_5 + uVar10 * -0x80;
    uVar18 = local_118;
    uVar19 = uStack_114;
    uVar20 = uStack_110;
    uVar21 = uStack_10c;
    do {
      puVar2 = *(uint **)(param_1 + 0x1d0);
      uVar3 = param_3[0x18];
      uVar4 = param_3[0x19];
      uVar5 = param_3[0x1a];
      uVar6 = param_3[0x1b];
      local_118 = param_3[0x1c];
      uStack_114 = param_3[0x1d];
      uStack_110 = param_3[0x1e];
      uStack_10c = param_3[0x1f];
      uVar72 = *puVar2;
      uVar75 = puVar2[1];
      uVar76 = puVar2[2];
      uVar77 = puVar2[3];
      pauVar9 = (undefined1 (*) [16])(puVar2 + 4);
      uVar31 = *param_3;
      puVar2 = param_3 + 1;
      puVar7 = param_3 + 2;
      puVar8 = param_3 + 3;
      uVar25 = param_3[4];
      uVar27 = param_3[5];
      uVar30 = param_3[6];
      uVar55 = param_3[7];
      uVar11 = param_3[8];
      uVar15 = param_3[9];
      uVar16 = param_3[10];
      uVar17 = param_3[0xb];
      uVar24 = param_3[0xc];
      uVar26 = param_3[0xd];
      uVar29 = param_3[0xe];
      uVar28 = param_3[0xf];
      uVar38 = param_3[0x10];
      uVar40 = param_3[0x11];
      uVar41 = param_3[0x12];
      uVar42 = param_3[0x13];
      uVar56 = param_3[0x14];
      uVar57 = param_3[0x15];
      uVar58 = param_3[0x16];
      uVar59 = param_3[0x17];
      auVar12._0_4_ = uVar72 ^ uVar31;
      auVar12._4_4_ = uVar75 ^ *puVar2;
      auVar12._8_4_ = uVar76 ^ *puVar7;
      auVar12._12_4_ = uVar77 ^ *puVar8;
      auVar32._0_4_ = uVar72 ^ uVar25;
      auVar32._4_4_ = uVar75 ^ uVar27;
      auVar32._8_4_ = uVar76 ^ uVar30;
      auVar32._12_4_ = uVar77 ^ uVar55;
      auVar44._0_4_ = uVar72 ^ uVar11;
      auVar44._4_4_ = uVar75 ^ uVar15;
      auVar44._8_4_ = uVar76 ^ uVar16;
      auVar44._12_4_ = uVar77 ^ uVar17;
      auVar50._0_4_ = uVar72 ^ uVar24;
      auVar50._4_4_ = uVar75 ^ uVar26;
      auVar50._8_4_ = uVar76 ^ uVar29;
      auVar50._12_4_ = uVar77 ^ uVar28;
      auVar67._0_4_ = uVar72 ^ uVar38;
      auVar67._4_4_ = uVar75 ^ uVar40;
      auVar67._8_4_ = uVar76 ^ uVar41;
      auVar67._12_4_ = uVar77 ^ uVar42;
      auVar61._0_4_ = uVar72 ^ uVar56;
      auVar61._4_4_ = uVar75 ^ uVar57;
      auVar61._8_4_ = uVar76 ^ uVar58;
      auVar61._12_4_ = uVar77 ^ uVar59;
      auVar73._0_4_ = uVar3 ^ uVar72;
      auVar73._4_4_ = uVar4 ^ uVar75;
      auVar73._8_4_ = uVar5 ^ uVar76;
      auVar73._12_4_ = uVar6 ^ uVar77;
      auVar78._0_4_ = local_118 ^ uVar72;
      auVar78._4_4_ = uStack_114 ^ uVar75;
      auVar78._8_4_ = uStack_110 ^ uVar76;
      auVar78._12_4_ = uStack_10c ^ uVar77;
      do {
        auVar14 = *pauVar9;
        pauVar9 = pauVar9 + 1;
        auVar12 = aesdec(auVar12,auVar14);
        auVar32 = aesdec(auVar32,auVar14);
        auVar44 = aesdec(auVar44,auVar14);
        auVar50 = aesdec(auVar50,auVar14);
        auVar67 = aesdec(auVar67,auVar14);
        auVar61 = aesdec(auVar61,auVar14);
        auVar73 = aesdec(auVar73,auVar14);
        auVar78 = aesdec(auVar78,auVar14);
      } while (pauVar9 < *(undefined1 (**) [16])(param_1 + 0x1d8));
      auVar14 = *pauVar9;
      param_3 = param_3 + 0x20;
      auVar12 = aesdeclast(auVar12,auVar14);
      auVar32 = aesdeclast(auVar32,auVar14);
      auVar44 = aesdeclast(auVar44,auVar14);
      auVar50 = aesdeclast(auVar50,auVar14);
      auVar67 = aesdeclast(auVar67,auVar14);
      auVar61 = aesdeclast(auVar61,auVar14);
      auVar73 = aesdeclast(auVar73,auVar14);
      auVar78 = aesdeclast(auVar78,auVar14);
      uVar31 = auVar32._0_4_ ^ uVar31;
      uVar35 = auVar32._4_4_ ^ *puVar2;
      uVar36 = auVar32._8_4_ ^ *puVar7;
      uVar37 = auVar32._12_4_ ^ *puVar8;
      uVar43 = auVar44._0_4_ ^ uVar25;
      uVar46 = auVar44._4_4_ ^ uVar27;
      uVar47 = auVar44._8_4_ ^ uVar30;
      uVar48 = auVar44._12_4_ ^ uVar55;
      uVar49 = auVar50._0_4_ ^ uVar11;
      uVar52 = auVar50._4_4_ ^ uVar15;
      uVar53 = auVar50._8_4_ ^ uVar16;
      uVar54 = auVar50._12_4_ ^ uVar17;
      uVar66 = auVar67._0_4_ ^ uVar24;
      uVar69 = auVar67._4_4_ ^ uVar26;
      uVar70 = auVar67._8_4_ ^ uVar29;
      uVar71 = auVar67._12_4_ ^ uVar28;
      uVar60 = auVar61._0_4_ ^ uVar38;
      uVar63 = auVar61._4_4_ ^ uVar40;
      uVar64 = auVar61._8_4_ ^ uVar41;
      uVar65 = auVar61._12_4_ ^ uVar42;
      uVar72 = auVar73._0_4_ ^ uVar56;
      uVar75 = auVar73._4_4_ ^ uVar57;
      uVar76 = auVar73._8_4_ ^ uVar58;
      uVar77 = auVar73._12_4_ ^ uVar59;
      *param_4 = auVar12._0_4_ ^ uVar18;
      param_4[1] = auVar12._4_4_ ^ uVar19;
      param_4[2] = auVar12._8_4_ ^ uVar20;
      param_4[3] = auVar12._12_4_ ^ uVar21;
      param_4[4] = uVar31;
      param_4[5] = uVar35;
      param_4[6] = uVar36;
      param_4[7] = uVar37;
      param_4[8] = uVar43;
      param_4[9] = uVar46;
      param_4[10] = uVar47;
      param_4[0xb] = uVar48;
      param_4[0xc] = uVar49;
      param_4[0xd] = uVar52;
      param_4[0xe] = uVar53;
      param_4[0xf] = uVar54;
      param_4[0x10] = uVar66;
      param_4[0x11] = uVar69;
      param_4[0x12] = uVar70;
      param_4[0x13] = uVar71;
      param_4[0x14] = uVar60;
      param_4[0x15] = uVar63;
      param_4[0x16] = uVar64;
      param_4[0x17] = uVar65;
      param_4[0x18] = uVar72;
      param_4[0x19] = uVar75;
      param_4[0x1a] = uVar76;
      param_4[0x1b] = uVar77;
      param_4[0x1c] = auVar78._0_4_ ^ uVar3;
      param_4[0x1d] = auVar78._4_4_ ^ uVar4;
      param_4[0x1e] = auVar78._8_4_ ^ uVar5;
      param_4[0x1f] = auVar78._12_4_ ^ uVar6;
      param_4 = param_4 + 0x20;
      uVar10 = uVar10 - 1;
      uVar18 = local_118;
      uVar19 = uStack_114;
      uVar20 = uStack_110;
      uVar21 = uStack_10c;
    } while (uVar10 != 0);
  }
  if (param_5 < 0x10) goto LAB_180001f53;
  uVar18 = *param_3;
  uVar19 = param_3[1];
  uVar20 = param_3[2];
  uVar21 = param_3[3];
  if (param_5 < 0x20) {
LAB_180001ce2:
    if (0x40 < param_5) goto LAB_180001cec;
LAB_180001e2a:
    puVar2 = *(uint **)(param_1 + 0x1d0);
    if (param_5 < 0x11) {
      pauVar9 = (undefined1 (*) [16])(puVar2 + 8);
      auVar23._0_4_ = *puVar2 ^ uVar18;
      auVar23._4_4_ = puVar2[1] ^ uVar19;
      auVar23._8_4_ = puVar2[2] ^ uVar20;
      auVar23._12_4_ = puVar2[3] ^ uVar21;
      auVar12 = aesdec(auVar23,*(undefined1 (*) [16])(puVar2 + 4));
      do {
        auVar32 = *pauVar9;
        pauVar1 = pauVar9 + 1;
        pauVar9 = pauVar9 + 2;
        auVar12 = aesdec(auVar12,auVar32);
        auVar12 = aesdec(auVar12,*pauVar1);
      } while (pauVar9 < *(undefined1 (**) [16])(param_1 + 0x1d8));
      auVar12 = aesdeclast(auVar12,*pauVar9);
      uVar31 = auVar12._0_4_ ^ local_118;
      uVar25 = auVar12._4_4_ ^ uStack_114;
      uVar27 = auVar12._8_4_ ^ uStack_110;
      uVar30 = auVar12._12_4_ ^ uStack_10c;
      puVar2 = (uint *)((param_5 - 0x10) + (longlong)param_3);
      local_118 = *puVar2;
      uStack_114 = puVar2[1];
      uStack_110 = puVar2[2];
      uStack_10c = puVar2[3];
      *param_4 = uVar31;
      param_4[1] = uVar25;
      param_4[2] = uVar27;
      param_4[3] = uVar30;
      goto LAB_180001f53;
    }
    uVar24 = *puVar2;
    uVar26 = puVar2[1];
    uVar29 = puVar2[2];
    uVar28 = puVar2[3];
    pauVar9 = (undefined1 (*) [16])(puVar2 + 4);
    auVar39._0_4_ = uVar24 ^ uVar31;
    auVar39._4_4_ = uVar26 ^ uVar35;
    auVar39._8_4_ = uVar29 ^ uVar36;
    auVar39._12_4_ = uVar28 ^ uVar37;
    auVar22._0_4_ = uVar24 ^ uVar18;
    auVar22._4_4_ = uVar26 ^ uVar19;
    auVar22._8_4_ = uVar29 ^ uVar20;
    auVar22._12_4_ = uVar28 ^ uVar21;
    auVar14._0_4_ = uVar24 ^ uVar49;
    auVar14._4_4_ = uVar26 ^ uVar52;
    auVar14._8_4_ = uVar29 ^ uVar53;
    auVar14._12_4_ = uVar28 ^ uVar54;
    auVar34._0_4_ = uVar24 ^ uVar43;
    auVar34._4_4_ = uVar26 ^ uVar46;
    auVar34._8_4_ = uVar29 ^ uVar47;
    auVar34._12_4_ = uVar28 ^ uVar48;
    do {
      auVar12 = *pauVar9;
      pauVar9 = pauVar9 + 1;
      auVar22 = aesdec(auVar22,auVar12);
      auVar39 = aesdec(auVar39,auVar12);
      auVar34 = aesdec(auVar34,auVar12);
      auVar14 = aesdec(auVar14,auVar12);
    } while (pauVar9 < *(undefined1 (**) [16])(param_1 + 0x1d8));
    auVar12 = *pauVar9;
    auVar32 = aesdeclast(auVar22,auVar12);
    uVar31 = auVar32._0_4_ ^ local_118;
    uVar24 = auVar32._4_4_ ^ uStack_114;
    uVar26 = auVar32._8_4_ ^ uStack_110;
    uVar29 = auVar32._12_4_ ^ uStack_10c;
    puVar2 = (uint *)((longlong)param_3 + (param_5 - 0x10));
    local_118 = *puVar2;
    uStack_114 = puVar2[1];
    uStack_110 = puVar2[2];
    uStack_10c = puVar2[3];
    auVar44 = aesdeclast(auVar39,auVar12);
    auVar32 = aesdeclast(auVar34,auVar12);
    auVar12 = aesdeclast(auVar14,auVar12);
    uVar11 = auVar12._0_4_ ^ uVar11;
    uVar15 = auVar12._4_4_ ^ uVar15;
    uVar16 = auVar12._8_4_ ^ uVar16;
    uVar17 = auVar12._12_4_ ^ uVar17;
    *param_4 = uVar31;
    param_4[1] = uVar24;
    param_4[2] = uVar26;
    param_4[3] = uVar29;
    if (param_5 < 0x20) goto LAB_180001f53;
    param_4[4] = auVar44._0_4_ ^ uVar18;
    param_4[5] = auVar44._4_4_ ^ uVar19;
    param_4[6] = auVar44._8_4_ ^ uVar20;
    param_4[7] = auVar44._12_4_ ^ uVar21;
    if (param_5 < 0x30) goto LAB_180001f53;
    param_4[8] = auVar32._0_4_ ^ uVar25;
    param_4[9] = auVar32._4_4_ ^ uVar27;
    param_4[10] = auVar32._8_4_ ^ uVar30;
    param_4[0xb] = auVar32._12_4_ ^ uVar55;
    if (param_5 < 0x40) goto LAB_180001f53;
  }
  else {
    uVar25 = param_3[4];
    uVar27 = param_3[5];
    uVar30 = param_3[6];
    uVar55 = param_3[7];
    uVar31 = uVar25;
    uVar35 = uVar27;
    uVar36 = uVar30;
    uVar37 = uVar55;
    if (param_5 < 0x30) goto LAB_180001ce2;
    uVar11 = param_3[8];
    uVar15 = param_3[9];
    uVar16 = param_3[10];
    uVar17 = param_3[0xb];
    uVar43 = uVar11;
    uVar46 = uVar15;
    uVar47 = uVar16;
    uVar48 = uVar17;
    if (param_5 < 0x40) goto LAB_180001e2a;
    uVar24 = param_3[0xc];
    uVar26 = param_3[0xd];
    uVar29 = param_3[0xe];
    uVar28 = param_3[0xf];
    uVar49 = uVar24;
    uVar52 = uVar26;
    uVar53 = uVar29;
    uVar54 = uVar28;
    if (param_5 < 0x50) goto LAB_180001ce2;
    uVar38 = param_3[0x10];
    uVar40 = param_3[0x11];
    uVar41 = param_3[0x12];
    uVar42 = param_3[0x13];
    uVar66 = uVar38;
    uVar69 = uVar40;
    uVar70 = uVar41;
    uVar71 = uVar42;
    if (param_5 < 0x60) goto LAB_180001ce2;
    uVar56 = param_3[0x14];
    uVar57 = param_3[0x15];
    uVar58 = param_3[0x16];
    uVar59 = param_3[0x17];
    uVar60 = uVar56;
    uVar63 = uVar57;
    uVar64 = uVar58;
    uVar65 = uVar59;
    if (param_5 < 0x70) goto LAB_180001ce2;
    uVar72 = param_3[0x18];
    uVar75 = param_3[0x19];
    uVar76 = param_3[0x1a];
    uVar77 = param_3[0x1b];
LAB_180001cec:
    puVar2 = *(uint **)(param_1 + 0x1d0);
    uVar3 = *puVar2;
    uVar4 = puVar2[1];
    uVar5 = puVar2[2];
    uVar6 = puVar2[3];
    pauVar9 = (undefined1 (*) [16])(puVar2 + 4);
    auVar33._4_4_ = uVar4 ^ uVar19;
    auVar33._0_4_ = uVar3 ^ uVar18;
    auVar33._8_4_ = uVar5 ^ uVar20;
    auVar33._12_4_ = uVar6 ^ uVar21;
    auVar45._4_4_ = uVar4 ^ uVar35;
    auVar45._0_4_ = uVar3 ^ uVar31;
    auVar45._8_4_ = uVar5 ^ uVar36;
    auVar45._12_4_ = uVar6 ^ uVar37;
    auVar13._0_4_ = uVar3 ^ uVar49;
    auVar13._4_4_ = uVar4 ^ uVar52;
    auVar13._8_4_ = uVar5 ^ uVar53;
    auVar13._12_4_ = uVar6 ^ uVar54;
    auVar51._4_4_ = uVar4 ^ uVar46;
    auVar51._0_4_ = uVar3 ^ uVar43;
    auVar51._8_4_ = uVar5 ^ uVar47;
    auVar51._12_4_ = uVar6 ^ uVar48;
    auVar68._4_4_ = uVar4 ^ uVar69;
    auVar68._0_4_ = uVar3 ^ uVar66;
    auVar68._8_4_ = uVar5 ^ uVar70;
    auVar68._12_4_ = uVar6 ^ uVar71;
    auVar62._0_4_ = uVar3 ^ uVar60;
    auVar62._4_4_ = uVar4 ^ uVar63;
    auVar62._8_4_ = uVar5 ^ uVar64;
    auVar62._12_4_ = uVar6 ^ uVar65;
    auVar74._0_4_ = uVar3 ^ uVar72;
    auVar74._4_4_ = uVar4 ^ uVar75;
    auVar74._8_4_ = uVar5 ^ uVar76;
    auVar74._12_4_ = uVar6 ^ uVar77;
    do {
      auVar12 = *pauVar9;
      pauVar9 = pauVar9 + 1;
      auVar68 = aesdec(auVar68,auVar12);
      auVar62 = aesdec(auVar62,auVar12);
      auVar74 = aesdec(auVar74,auVar12);
      auVar33 = aesdec(auVar33,auVar12);
      auVar45 = aesdec(auVar45,auVar12);
      auVar51 = aesdec(auVar51,auVar12);
      auVar13 = aesdec(auVar13,auVar12);
    } while (pauVar9 < *(undefined1 (**) [16])(param_1 + 0x1d8));
    auVar12 = *pauVar9;
    puVar2 = (uint *)((param_5 - 0x10) + (longlong)param_3);
    uVar31 = *puVar2;
    uVar35 = puVar2[1];
    uVar36 = puVar2[2];
    uVar37 = puVar2[3];
    auVar32 = aesdeclast(auVar33,auVar12);
    *param_4 = auVar32._0_4_ ^ local_118;
    param_4[1] = auVar32._4_4_ ^ uStack_114;
    param_4[2] = auVar32._8_4_ ^ uStack_110;
    param_4[3] = auVar32._12_4_ ^ uStack_10c;
    auVar44 = aesdeclast(auVar45,auVar12);
    auVar50 = aesdeclast(auVar51,auVar12);
    auVar32 = aesdeclast(auVar13,auVar12);
    auVar67 = aesdeclast(auVar68,auVar12);
    auVar61 = aesdeclast(auVar62,auVar12);
    auVar12 = aesdeclast(auVar74,auVar12);
    param_4[4] = auVar44._0_4_ ^ uVar18;
    param_4[5] = auVar44._4_4_ ^ uVar19;
    param_4[6] = auVar44._8_4_ ^ uVar20;
    param_4[7] = auVar44._12_4_ ^ uVar21;
    param_4[8] = auVar50._0_4_ ^ uVar25;
    param_4[9] = auVar50._4_4_ ^ uVar27;
    param_4[10] = auVar50._8_4_ ^ uVar30;
    param_4[0xb] = auVar50._12_4_ ^ uVar55;
    uVar11 = auVar32._0_4_ ^ uVar11;
    uVar15 = auVar32._4_4_ ^ uVar15;
    uVar16 = auVar32._8_4_ ^ uVar16;
    uVar17 = auVar32._12_4_ ^ uVar17;
    uVar66 = auVar67._0_4_ ^ uVar24;
    uVar69 = auVar67._4_4_ ^ uVar26;
    uVar70 = auVar67._8_4_ ^ uVar29;
    uVar71 = auVar67._12_4_ ^ uVar28;
    uVar60 = auVar61._0_4_ ^ uVar38;
    uVar63 = auVar61._4_4_ ^ uVar40;
    uVar64 = auVar61._8_4_ ^ uVar41;
    uVar65 = auVar61._12_4_ ^ uVar42;
    uVar72 = auVar12._0_4_ ^ uVar56;
    uVar75 = auVar12._4_4_ ^ uVar57;
    uVar76 = auVar12._8_4_ ^ uVar58;
    uVar77 = auVar12._12_4_ ^ uVar59;
    local_118 = uVar31;
    uStack_114 = uVar35;
    uStack_110 = uVar36;
    uStack_10c = uVar37;
  }
  param_4[0xc] = uVar11;
  param_4[0xd] = uVar15;
  param_4[0xe] = uVar16;
  param_4[0xf] = uVar17;
  if (0x4f < param_5) {
    param_4[0x10] = uVar66;
    param_4[0x11] = uVar69;
    param_4[0x12] = uVar70;
    param_4[0x13] = uVar71;
    if (0x5f < param_5) {
      param_4[0x14] = uVar60;
      param_4[0x15] = uVar63;
      param_4[0x16] = uVar64;
      param_4[0x17] = uVar65;
      if (0x6f < param_5) {
        param_4[0x18] = uVar72;
        param_4[0x19] = uVar75;
        param_4[0x1a] = uVar76;
        param_4[0x1b] = uVar77;
      }
    }
  }
LAB_180001f53:
  *param_2 = local_118;
  param_2[1] = uStack_114;
  param_2[2] = uStack_110;
  param_2[3] = uStack_10c;
  return;
}



===== SymCryptAesCreateDecryptionRoundKey @ 180001fb0 =====

void SymCryptAesCreateDecryptionRoundKey
               (undefined1 (*param_1) [16],undefined1 (*param_2) [16],int param_3)

{
  undefined1 auVar1 [16];
  
  if (param_3 == 0) {
    *(uint *)*param_2 =
         *(uint *)(&DAT_180015000 + (ulonglong)(byte)(*param_1)[2] * 4) ^
         *(uint *)(&DAT_180014c00 + (ulonglong)(byte)(*param_1)[1] * 4) ^
         *(uint *)(&DAT_180015400 + (ulonglong)(byte)(*param_1)[3] * 4) ^
         *(uint *)(&SymCryptAesInvMatrixMult + (ulonglong)(byte)(*param_1)[0] * 4);
    *(uint *)(*param_2 + 4) =
         *(uint *)(&DAT_180015000 + (ulonglong)(byte)(*param_1)[6] * 4) ^
         *(uint *)(&DAT_180014c00 + (ulonglong)(byte)(*param_1)[5] * 4) ^
         *(uint *)(&DAT_180015400 + (ulonglong)(byte)(*param_1)[7] * 4) ^
         *(uint *)(&SymCryptAesInvMatrixMult + (ulonglong)(byte)(*param_1)[4] * 4);
    *(uint *)(*param_2 + 8) =
         *(uint *)(&DAT_180015000 + (ulonglong)(byte)(*param_1)[10] * 4) ^
         *(uint *)(&DAT_180014c00 + (ulonglong)(byte)(*param_1)[9] * 4) ^
         *(uint *)(&DAT_180015400 + (ulonglong)(byte)(*param_1)[0xb] * 4) ^
         *(uint *)(&SymCryptAesInvMatrixMult + (ulonglong)(byte)(*param_1)[8] * 4);
    *(uint *)(*param_2 + 0xc) =
         *(uint *)(&DAT_180015000 + (ulonglong)(byte)(*param_1)[0xe] * 4) ^
         *(uint *)(&DAT_180014c00 + (ulonglong)(byte)(*param_1)[0xd] * 4) ^
         *(uint *)(&DAT_180015400 + (ulonglong)(byte)(*param_1)[0xf] * 4) ^
         *(uint *)(&SymCryptAesInvMatrixMult + (ulonglong)(byte)(*param_1)[0xc] * 4);
    return;
  }
  auVar1 = aesimc(*param_1);
  *param_2 = auVar1;
  return;
}



===== SymCryptXtsAesExpandKey @ 1800020a0 =====

void SymCryptXtsAesExpandKey
               (undefined1 (*param_1) [16],undefined1 (*param_2) [16],ulonglong param_3)

{
  undefined8 uVar1;
  ulonglong uVar2;
  
  uVar2 = param_3 >> 1;
  uVar1 = SymCryptAesExpandKeyInternal(param_1,param_2,uVar2,'\x01');
  if ((int)uVar1 == 0) {
    SymCryptAesExpandKeyInternal
              (param_1 + 0x1f,(undefined1 (*) [16])(*param_2 + uVar2),param_3 - uVar2,'\0');
  }
  return;
}



===== FveLibInitEx @ 180002110 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

ulonglong FveLibInitEx(void)

{
  ulonglong uVar1;
  int iVar2;
  ulonglong uVar3;
  undefined8 local_res10 [3];
  
  local_res10[0] = 0;
  if (((DAT_18001a168 != (undefined *)0x0) && (DAT_18001a168 != &FveCallbacks)) ||
     (DAT_18001a170 != 0)) {
    return 0xc000000d;
  }
  if (DAT_18001a168 == (undefined *)0x0) {
    DAT_18001a168 = &FveCallbacks;
  }
  if (((DAT_18001a168 != (undefined *)0x0) && (*(code **)(DAT_18001a168 + 0x38) != (code *)0x0)) &&
     (*(longlong *)(DAT_18001a168 + 0x40) != 0)) {
    (**(code **)(DAT_18001a168 + 0x38))(0,local_res10);
  }
  iVar2 = DAT_18001a178 + 1;
  DAT_18001a178 = iVar2;
  if (((DAT_18001a168 != (undefined *)0x0) && (*(longlong *)(DAT_18001a168 + 0x38) != 0)) &&
     (*(code **)(DAT_18001a168 + 0x40) != (code *)0x0)) {
    (**(code **)(DAT_18001a168 + 0x40))(DAT_18001a170,local_res10);
  }
  if (1 < iVar2) {
    return 0;
  }
  SymCryptInitEnvWindowsKernelmodeWin8_1nLater();
  uVar1 = FveAesCcmFipsKat();
  uVar3 = uVar1 & 0xffffffff;
  if (-1 < (int)uVar1) {
    uVar1 = FveAesCbcFipsKat();
    uVar3 = uVar1 & 0xffffffff;
    if (-1 < (int)uVar1) {
      SymCryptHmacSha256Selftest();
      SymCryptHmacSha1Selftest();
      SymCryptXtsAesSelftest();
      SymCryptPbkdf2_HmacSha256SelfTest();
    }
  }
  return uVar3;
}



===== FveAesCcmFipsKat @ 180002228 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FveAesCcmFipsKat(void)

{
  ulonglong uVar1;
  longlong lVar2;
  char *pcVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  undefined8 uVar6;
  undefined1 uVar7;
  undefined7 in_register_00000089;
  undefined1 auStackY_268 [32];
  undefined8 in_stack_fffffffffffffdb8;
  undefined8 in_stack_fffffffffffffdc8;
  int local_218;
  int local_214 [3];
  ulonglong local_208 [62];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_268;
  memset(local_208,0,0x1f0);
  uVar7 = 1;
  pcVar3 = "@ABCDEFGHIJKLMNOabc";
  uVar6 = 0x10;
  SymCryptAesExpandKeyInternal
            ((undefined1 (*) [16])local_208,(undefined1 (*) [16])"@ABCDEFGHIJKLMNOabc",0x10,'\x01');
  local_218 = 0x23222120;
  uVar1 = FveAesCcmEncrypt(local_208,pcVar3,uVar6,CONCAT71(in_register_00000089,uVar7),
                           in_stack_fffffffffffffdb8,(ulonglong)&local_218,in_stack_fffffffffffffdc8
                           ,(ulonglong)local_214);
  uVar4 = uVar1 & 0xffffffff;
  if (-1 < (int)uVar1) {
    if ((local_218 == 0x5b016271) && (local_214[0] == 0x5d25ac4d)) {
      uVar1 = FveAesCcmDecrypt(local_208,pcVar3,uVar6,CONCAT71(in_register_00000089,uVar7),
                               in_stack_fffffffffffffdb8,(undefined1 *)&local_218,
                               in_stack_fffffffffffffdc8,local_214);
      uVar4 = uVar1 & 0xffffffff;
      if (((int)uVar1 < 0) || (local_218 == 0x23222120)) goto LAB_180002300;
    }
    uVar4 = 0xc0000229;
  }
LAB_180002300:
  SymCryptWipeAsm(local_208,0x1f0);
  puVar5 = local_208;
  for (lVar2 = 0x1f0; lVar2 != 0; lVar2 = lVar2 + -1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (ulonglong *)((longlong)puVar5 + 1);
  }
  return uVar4;
}



===== FveAesCbcFipsKat @ 18000234c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FveAesCbcFipsKat(void)

{
  int iVar1;
  longlong *plVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  uint uVar5;
  uint uVar6;
  ulonglong *puVar7;
  longlong lVar8;
  undefined1 (*pauVar9) [16];
  undefined1 auStackY_388 [32];
  uint local_348 [124];
  ulonglong local_158 [4];
  longlong local_138 [32];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_388;
  memset(local_348,0,0x1f0);
  SymCryptAesExpandKeyInternal
            ((undefined1 (*) [16])local_348,(undefined1 (*) [16])&DAT_180015a68,0x10,'\x01');
  uVar5 = 1;
  pauVar9 = (undefined1 (*) [16])local_158;
  puVar7 = local_158;
  lVar8 = 0x440c;
  local_158[2] = 0x600000005;
  local_158[3] = 0x800000007;
  local_158[0] = 0x200000001;
  local_158[1] = 0x400000003;
  do {
    if (uVar5 < 0x10) {
      uVar3 = (ulonglong)uVar5;
      if (uVar5 != 0) goto LAB_1800023fd;
      uVar3 = 0;
      uVar6 = 0;
    }
    else {
      uVar3 = 0x10;
LAB_1800023fd:
      plVar2 = local_138 + 1;
      uVar6 = (uint)uVar3;
      uVar4 = uVar3;
      do {
        *plVar2 = 0;
        plVar2[-1] = lVar8;
        plVar2 = plVar2 + 2;
        lVar8 = lVar8 + 0x20;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    uVar3 = FveAesEcbEncrypt(local_348,(longlong)local_138,uVar3 << 4,(undefined1 (*) [16])local_138
                            );
    uVar4 = uVar3 & 0xffffffff;
    if ((int)uVar3 < 0) break;
    for (uVar3 = 0; (uint)uVar3 < uVar6; uVar3 = (ulonglong)((uint)uVar3 + 1)) {
      SymCryptAesCbcEncrypt
                (local_348,(undefined1 (*) [16])(local_138 + uVar3 * 2),(uint *)puVar7,pauVar9,0x20)
      ;
      uVar4 = 0;
      puVar7 = puVar7 + 4;
      pauVar9 = pauVar9 + 2;
    }
    uVar5 = uVar5 - uVar6;
  } while (uVar5 != 0);
  if (-1 < (int)uVar4) {
    iVar1 = memcmp(local_158,&DAT_180015a98,0x20);
    if (iVar1 == 0) {
      uVar4 = FveAesCbcDecryptSectorsNormal
                        (local_348,0x440c,(uint *)local_158,0x20,local_158,0x20,(uint *)0x0);
      uVar4 = uVar4 & 0xffffffff;
      iVar1 = memcmp(local_158,&DAT_180015a78,0x20);
      if (iVar1 != 0) {
        uVar4 = 0xc0000229;
      }
    }
    else {
      uVar4 = 0xc0000229;
    }
  }
  return uVar4;
}



===== SymCryptXtsAesSelftest @ 180002534 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptXtsAesSelftest(void)

{
  bool bVar1;
  int iVar2;
  undefined1 auStackY_498 [32];
  longlong local_458 [4];
  uint local_438 [248];
  ulonglong local_58 [2];
  uint local_48 [4];
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_498;
  memset(local_438,0,0x3e0);
  local_58[1] = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_58[0] = 1;
  bVar1 = SymCryptEqual((uint *)local_58,local_48,0x10);
  if (!bVar1) {
    iVar2 = SymCryptXtsAesExpandKey
                      ((undefined1 (*) [16])local_438,(undefined1 (*) [16])local_58,0x20);
    if (iVar2 == 0) {
      local_458[0] = 0;
      local_458[1] = 0;
      SymCryptXtsAesEncryptInternal
                (local_438,0x20,local_458,local_58,(undefined1 (*) [16])local_58,0x20);
      iVar2 = memcmp(local_58,&DAT_180015ab8,0x20);
      if (iVar2 == 0) {
        local_458[2] = 0;
        local_458[3] = 0;
        SymCryptXtsAesDecryptInternal
                  ((longlong)local_438,0x20,local_458 + 2,local_58,(undefined1 (*) [16])local_58,
                   0x20);
        local_30 = 0;
        local_28 = 0;
        local_20 = 0;
        local_38 = 1;
        iVar2 = memcmp(local_58,&local_38,0x20);
        if (iVar2 == 0) {
          return;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  SymCryptFatal(0x78747361);
}



===== SymCryptHmacSha1Selftest @ 1800026c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptHmacSha1Selftest(void)

{
  longlong lVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined1 auStack_98 [32];
  uint local_78 [5];
  undefined8 local_64;
  undefined4 local_5c;
  ulonglong local_28;
  longlong local_20;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_98;
  local_64 = 0;
  local_5c = 0;
  memset(local_78,0,0x44);
  uVar3 = 0x10;
  puVar2 = &SymCryptTestKey32;
  SymCryptHmacSha1ExpandKey(local_78,&SymCryptTestKey32,0x10);
  SymCryptHmacSha1((undefined8 *)local_78,puVar2,uVar3,&local_28);
  lVar1 = local_28 + 0xed145dcbf7ad6d6;
  if ((lVar1 == 0) && (lVar1 = local_20 + -0x6bcca897d88c0f49, lVar1 == 0)) {
    lVar1 = (ulonglong)local_18 - 0x122a7b55;
  }
  if (lVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    SymCryptFatal(0x68536831);
  }
  return;
}



===== SymCryptPbkdf2_HmacSha256SelfTest @ 180002780 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptPbkdf2_HmacSha256SelfTest(void)

{
  undefined1 auStack_58 [48];
  longlong *local_28;
  longlong local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_58;
  local_28 = &local_18;
  SymCryptPbkdf2();
  if (local_18 != 0x6184d248891e9805) {
                    /* WARNING: Subroutine does not return */
    SymCryptFatal(0x50626b32);
  }
  return;
}



===== SymCryptHmacSha256Selftest @ 1800027dc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptHmacSha256Selftest(void)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  undefined1 auStack_a8 [32];
  uint local_88 [20];
  ulonglong local_38 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_a8;
  memset(local_88,0,0x50);
  uVar3 = 0x10;
  puVar2 = &SymCryptTestKey32;
  SymCryptHmacSha256ExpandKey(local_88,(undefined1 (*) [16])&SymCryptTestKey32,0x10);
  SymCryptHmacSha256((undefined8 *)local_88,puVar2,uVar3,local_38);
  iVar1 = memcmp(local_38,&DAT_180015a10,0x20);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    SymCryptFatal(0x68736832);
  }
  return;
}



===== FveAesCcmDecrypt @ 180002870 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8
FveAesCcmDecrypt(ulonglong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5,undefined1 *param_6,undefined8 param_7,int *param_8)

{
  longlong lVar1;
  undefined8 uVar2;
  int *piVar3;
  undefined1 auStackY_88 [32];
  undefined8 in_stack_ffffffffffffff98;
  int local_38 [4];
  int local_28 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStackY_88;
  uVar2 = 0;
  local_38[0] = *param_8;
  FvepAesCcmEncryptDecrypt
            (param_1,param_2,param_3,(ulonglong)param_6,in_stack_ffffffffffffff98,
             (ulonglong)local_38);
  FvepAesCcmComputeUnencryptedTag((uint *)param_1);
  if (local_38[0] != local_28[0]) {
    for (lVar1 = 4; lVar1 != 0; lVar1 = lVar1 + -1) {
      *param_6 = 0;
      param_6 = param_6 + 1;
    }
    uVar2 = 0xc000003f;
  }
  piVar3 = local_38;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *(undefined1 *)piVar3 = 0;
    piVar3 = (int *)((longlong)piVar3 + 1);
  }
  piVar3 = local_28;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *(undefined1 *)piVar3 = 0;
    piVar3 = (int *)((longlong)piVar3 + 1);
  }
  return uVar2;
}



===== FveAesCcmEncrypt @ 18000292c =====

undefined8
FveAesCcmEncrypt(ulonglong *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5,ulonglong param_6,undefined8 param_7,ulonglong param_8)

{
  undefined8 in_stack_ffffffffffffffc8;
  
  FvepAesCcmComputeUnencryptedTag((uint *)param_1);
  FvepAesCcmEncryptDecrypt(param_1,param_2,param_3,param_6,in_stack_ffffffffffffffc8,param_8);
  return 0;
}



===== FvepAesCcmComputeUnencryptedTag @ 180002990 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x000180002b4a) */
/* WARNING: Removing unreachable block (ram,0x000180002b81) */
/* WARNING: Removing unreachable block (ram,0x000180002a98) */
/* WARNING: Removing unreachable block (ram,0x000180002ac6) */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffffd1 : 0x000180002adb */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FvepAesCcmComputeUnencryptedTag(uint *param_1)

{
  undefined1 (*pauVar1) [16];
  undefined8 uVar2;
  byte bVar3;
  undefined1 (*pauVar4) [16];
  longlong lVar5;
  undefined1 *puVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  ulonglong in_stack_00000030;
  undefined4 *in_stack_00000040;
  undefined1 auStack_58 [32];
  undefined1 local_38 [16];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_58;
  local_38._0_8_ = 0x1615141312111000;
  local_38[0] = 0x4f;
  auVar7 = local_38;
  local_38._8_4_ = 0;
  local_38._12_4_ = 0x4000000;
  if ((g_SymCryptCpuFeaturesNotPresent & 6) == 0) {
    pauVar4 = (undefined1 (*) [16])(param_1 + 8);
    local_38._0_4_ = auVar7._0_4_;
    auVar7._0_8_ = CONCAT44(param_1[1],*param_1 ^ local_38._0_4_) ^ 0x1615141300000000;
    auVar7._8_4_ = param_1[2];
    auVar7._12_4_ = param_1[3] ^ 0x4000000;
    auVar7 = aesenc(auVar7,*(undefined1 (*) [16])(param_1 + 4));
    do {
      auVar8 = *pauVar4;
      pauVar1 = pauVar4 + 1;
      pauVar4 = pauVar4 + 2;
      auVar7 = aesenc(auVar7,auVar8);
      auVar7 = aesenc(auVar7,*pauVar1);
    } while (pauVar4 < *(undefined1 (**) [16])(param_1 + 0x74));
    local_38 = aesenclast(auVar7,*pauVar4);
  }
  else {
    SymCryptAesEncryptAsm(param_1,(longlong)local_38,(undefined4 *)local_38);
  }
  bVar3 = 8;
  lVar5 = 1;
  do {
    local_38[lVar5] = local_38[lVar5] ^ bVar3;
    auVar7 = local_38;
    bVar3 = 0;
    lVar5 = lVar5 + -1;
  } while (-1 < lVar5);
  local_38._0_8_ = local_38._0_8_ ^ 0x504030201000000;
  uVar2 = local_38._0_8_;
  local_38[9] = auVar7[9];
  local_38._10_6_ = auVar7._10_6_;
  local_38._0_7_ = CONCAT16(local_38[9],local_38._0_6_) ^ 0x7000000000000;
  local_38._7_6_ = local_38._10_6_;
  auVar8 = local_38;
  if ((g_SymCryptCpuFeaturesNotPresent & 6) == 0) {
    local_38._0_4_ = SUB84(uVar2,0);
    local_38._4_4_ = auVar8._4_4_;
    local_38._8_4_ = auVar7._11_4_;
    local_38._12_4_ = auVar7._15_4_;
    pauVar4 = (undefined1 (*) [16])(param_1 + 8);
    auVar8._0_4_ = *param_1 ^ local_38._0_4_;
    auVar8._4_4_ = param_1[1] ^ local_38._4_4_;
    auVar8._8_4_ = param_1[2] ^ local_38._8_4_;
    auVar8._12_4_ = param_1[3] ^ local_38._12_4_;
    auVar7 = aesenc(auVar8,*(undefined1 (*) [16])(param_1 + 4));
    do {
      auVar8 = *pauVar4;
      pauVar1 = pauVar4 + 1;
      pauVar4 = pauVar4 + 2;
      auVar7 = aesenc(auVar7,auVar8);
      auVar7 = aesenc(auVar7,*pauVar1);
    } while (pauVar4 < *(undefined1 (**) [16])(param_1 + 0x74));
    local_38 = aesenclast(auVar7,*pauVar4);
  }
  else {
    SymCryptAesEncryptAsm(param_1,(longlong)local_38,(undefined4 *)local_38);
  }
  FvepAesCcmXorBytes((ulonglong)local_38,in_stack_00000030,4);
  if ((g_SymCryptCpuFeaturesNotPresent & 6) == 0) {
    pauVar4 = (undefined1 (*) [16])(param_1 + 8);
    auVar9._0_4_ = *param_1 ^ local_38._0_4_;
    auVar9._4_4_ = param_1[1] ^ local_38._4_4_;
    auVar9._8_4_ = param_1[2] ^ local_38._8_4_;
    auVar9._12_4_ = param_1[3] ^ local_38._12_4_;
    auVar7 = aesenc(auVar9,*(undefined1 (*) [16])(param_1 + 4));
    do {
      auVar8 = *pauVar4;
      pauVar1 = pauVar4 + 1;
      pauVar4 = pauVar4 + 2;
      auVar7 = aesenc(auVar7,auVar8);
      auVar7 = aesenc(auVar7,*pauVar1);
    } while (pauVar4 < *(undefined1 (**) [16])(param_1 + 0x74));
    local_38 = aesenclast(auVar7,*pauVar4);
  }
  else {
    SymCryptAesEncryptAsm(param_1,(longlong)local_38,(undefined4 *)local_38);
  }
  *in_stack_00000040 = local_38._0_4_;
  puVar6 = local_38;
  for (lVar5 = 0x10; lVar5 != 0; lVar5 = lVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  return;
}



===== FvepAesCcmEncryptDecrypt @ 180002c70 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FvepAesCcmEncryptDecrypt
               (ulonglong *param_1,undefined8 param_2,undefined8 param_3,ulonglong param_4,
               undefined8 param_5,ulonglong param_6)

{
  undefined1 (*pauVar1) [16];
  undefined1 (*pauVar2) [16];
  longlong lVar3;
  undefined1 *puVar4;
  uint *puVar5;
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auStack_68 [32];
  uint local_48;
  undefined1 uStack_44;
  undefined2 uStack_43;
  undefined1 uStack_41;
  uint uStack_40;
  undefined4 uStack_3c;
  undefined1 local_38 [16];
  ulonglong local_28;
  
  local_28 = __security_cookie ^ (ulonglong)auStack_68;
  uStack_44 = 0x13;
  uStack_43 = 0x1514;
  uStack_41 = 0x16;
  local_48 = 0x12111007;
  puVar5 = &uStack_40;
  for (lVar3 = 8; lVar3 != 0; lVar3 = lVar3 + -1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (uint *)((longlong)puVar5 + 1);
  }
  if ((g_SymCryptCpuFeaturesNotPresent & 6) == 0) {
    pauVar2 = (undefined1 (*) [16])(param_1 + 4);
    auVar6._0_8_ = *param_1 ^ 0x1615141312111007;
    auVar6._8_4_ = (uint)param_1[1] ^ uStack_40;
    auVar6._12_4_ = *(uint *)((longlong)param_1 + 0xc) ^ uStack_3c;
    auVar6 = aesenc(auVar6,*(undefined1 (*) [16])(param_1 + 2));
    do {
      auVar7 = *pauVar2;
      pauVar1 = pauVar2 + 1;
      pauVar2 = pauVar2 + 2;
      auVar6 = aesenc(auVar6,auVar7);
      auVar6 = aesenc(auVar6,*pauVar1);
    } while (pauVar2 < (undefined1 (*) [16])param_1[0x3a]);
    local_38 = aesenclast(auVar6,*pauVar2);
  }
  else {
    SymCryptAesEncryptAsm((uint *)param_1,(longlong)&local_48,(undefined4 *)local_38);
  }
  FvepAesCcmXorBytes(param_6,(ulonglong)local_38,4);
  uStack_3c = CONCAT13(1,(undefined3)uStack_3c);
  if ((g_SymCryptCpuFeaturesNotPresent & 6) == 0) {
    pauVar2 = (undefined1 (*) [16])(param_1 + 4);
    auVar7._0_4_ = (uint)*param_1 ^ local_48;
    auVar7._4_4_ = *(uint *)((longlong)param_1 + 4) ^
                   CONCAT13(uStack_41,CONCAT21(uStack_43,uStack_44));
    auVar7._8_4_ = (uint)param_1[1] ^ uStack_40;
    auVar7._12_4_ = *(uint *)((longlong)param_1 + 0xc) ^ uStack_3c;
    auVar6 = aesenc(auVar7,*(undefined1 (*) [16])(param_1 + 2));
    do {
      auVar7 = *pauVar2;
      pauVar1 = pauVar2 + 1;
      pauVar2 = pauVar2 + 2;
      auVar6 = aesenc(auVar6,auVar7);
      auVar6 = aesenc(auVar6,*pauVar1);
    } while (pauVar2 < (undefined1 (*) [16])param_1[0x3a]);
    local_38 = aesenclast(auVar6,*pauVar2);
  }
  else {
    SymCryptAesEncryptAsm((uint *)param_1,(longlong)&local_48,(undefined4 *)local_38);
  }
  FvepAesCcmXorBytes(param_4,(ulonglong)local_38,4);
  puVar4 = local_38;
  for (lVar3 = 0x10; lVar3 != 0; lVar3 = lVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar5 = &local_48;
  for (lVar3 = 0x10; lVar3 != 0; lVar3 = lVar3 + -1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (uint *)((longlong)puVar5 + 1);
  }
  return;
}



===== FvepAesCcmXorBytes @ 180002e10 =====

void FvepAesCcmXorBytes(ulonglong param_1,ulonglong param_2,ulonglong param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  undefined8 *puVar12;
  longlong lVar13;
  byte *pbVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  
  uVar16 = 0;
  if (param_3 == 0) {
    return;
  }
  if ((param_3 < 8) ||
     ((param_1 <= (param_3 - 1) + param_2 && (param_2 <= (param_3 - 1) + param_1))))
  goto LAB_180002f03;
  if (param_3 < 0x40) {
    lVar13 = param_2 - param_1;
LAB_180002ed2:
    puVar12 = (undefined8 *)(uVar16 + param_1);
    do {
      uVar16 = uVar16 + 8;
      *puVar12 = CONCAT44((uint)((ulonglong)*(undefined8 *)(lVar13 + (longlong)puVar12) >> 0x20) ^
                          (uint)((ulonglong)*puVar12 >> 0x20),
                          (uint)*(undefined8 *)(lVar13 + (longlong)puVar12) ^ (uint)*puVar12);
      puVar12 = puVar12 + 1;
    } while (uVar16 < (param_3 & 0xfffffffffffffff8));
  }
  else {
    uVar15 = (ulonglong)((uint)param_3 & 0x3f);
    lVar13 = param_2 - param_1;
    puVar11 = (uint *)(param_1 + 0x10);
    do {
      uVar16 = uVar16 + 0x40;
      puVar2 = (uint *)(lVar13 + -0x10 + (longlong)puVar11);
      uVar3 = puVar2[1];
      uVar4 = puVar2[2];
      uVar5 = puVar2[3];
      puVar1 = (uint *)(lVar13 + (longlong)puVar11);
      uVar6 = *puVar1;
      uVar7 = puVar1[1];
      uVar8 = puVar1[2];
      uVar9 = puVar1[3];
      puVar1 = puVar11 + 0x10;
      puVar11[-4] = *puVar2 ^ puVar11[-4];
      puVar11[-3] = uVar3 ^ puVar11[-3];
      puVar11[-2] = uVar4 ^ puVar11[-2];
      puVar11[-1] = uVar5 ^ puVar11[-1];
      puVar2 = (uint *)(lVar13 + -0x30 + (longlong)puVar1);
      uVar3 = *puVar2;
      uVar4 = puVar2[1];
      uVar5 = puVar2[2];
      uVar10 = puVar2[3];
      *puVar11 = uVar6 ^ *puVar11;
      puVar11[1] = uVar7 ^ puVar11[1];
      puVar11[2] = uVar8 ^ puVar11[2];
      puVar11[3] = uVar9 ^ puVar11[3];
      puVar11[4] = uVar3 ^ puVar11[4];
      puVar11[5] = uVar4 ^ puVar11[5];
      puVar11[6] = uVar5 ^ puVar11[6];
      puVar11[7] = uVar10 ^ puVar11[7];
      puVar2 = (uint *)(lVar13 + -0x20 + (longlong)puVar1);
      uVar3 = puVar2[1];
      uVar4 = puVar2[2];
      uVar5 = puVar2[3];
      puVar11[8] = *puVar2 ^ puVar11[8];
      puVar11[9] = uVar3 ^ puVar11[9];
      puVar11[10] = uVar4 ^ puVar11[10];
      puVar11[0xb] = uVar5 ^ puVar11[0xb];
      puVar11 = puVar1;
    } while (uVar16 < param_3 - uVar15);
    if (7 < uVar15) goto LAB_180002ed2;
  }
  if (param_3 <= uVar16) {
    return;
  }
LAB_180002f03:
  pbVar14 = (byte *)(uVar16 + param_1);
  lVar13 = param_3 - uVar16;
  do {
    *pbVar14 = *pbVar14 ^ pbVar14[param_2 - param_1];
    pbVar14 = pbVar14 + 1;
    lVar13 = lVar13 + -1;
  } while (lVar13 != 0);
  return;
}



===== SymCryptAesExpandKeyInternal @ 180002f40 =====

undefined8
SymCryptAesExpandKeyInternal
          (undefined1 (*param_1) [16],undefined1 (*param_2) [16],longlong param_3,char param_4)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  byte *pbVar4;
  undefined1 (*pauVar5) [16];
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined1 (*pauVar13) [16];
  bool bVar14;
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  longlong local_res18;
  
  uVar11 = g_SymCryptCpuFeaturesNotPresent & 6;
  bVar14 = uVar11 == 0;
  uVar7 = (uint)bVar14;
  if (param_3 == 0x10) {
    local_res18 = 2;
    *(undefined1 (**) [16])param_1[0x1d] = param_1 + 10;
    pauVar5 = param_1 + 1;
    *(undefined1 (**) [16])(param_1[0x1d] + 8) = param_1 + 0x14;
    pbVar8 = &DAT_180016dd3;
    pbVar4 = *param_1 + 0xe;
    *param_1 = *param_2;
    do {
      if (uVar11 == 0) {
        uVar2 = *(undefined4 *)(pbVar4 + -2);
        auVar19._4_4_ = uVar2;
        auVar19._0_4_ = uVar2;
        auVar19._8_4_ = uVar2;
        auVar19._12_4_ = uVar2;
        auVar19 = aeskeygenassist(auVar19,0);
        *(int *)*pauVar5 = auVar19._0_4_;
      }
      else {
        (*pauVar5)[0] = (&DAT_180015c01)[(ulonglong)pbVar4[-2] * 4];
        pbVar4[3] = (&DAT_180015c01)[(ulonglong)pbVar4[-1] * 4];
        pbVar4[4] = (&DAT_180015c01)[(ulonglong)*pbVar4 * 4];
        pbVar4[5] = (&DAT_180015c01)[(ulonglong)pbVar4[1] * 4];
      }
      uVar6 = (*(uint *)*pauVar5 >> 8 | *(uint *)*pauVar5 << 0x18) ^ (uint)pbVar8[-2] ^
              *(uint *)(pbVar4 + -0xe);
      *(uint *)*pauVar5 = uVar6;
      uVar10 = uVar6 ^ *(uint *)(pbVar4 + -10);
      *(uint *)(pbVar4 + 6) = uVar10;
      uVar12 = uVar10 ^ *(uint *)(pbVar4 + -6);
      *(uint *)(pbVar4 + 10) = uVar12;
      uVar9 = uVar12 ^ *(uint *)(pbVar4 + -2);
      *(uint *)(pbVar4 + 0xe) = uVar9;
      if (uVar11 == 0) {
        auVar15._4_4_ = uVar9;
        auVar15._0_4_ = uVar9;
        auVar15._8_4_ = uVar9;
        auVar15._12_4_ = uVar9;
        auVar19 = aeskeygenassist(auVar15,0);
        *(int *)(pbVar4 + 0x12) = auVar19._0_4_;
      }
      else {
        pbVar4[0x12] = (&DAT_180015c01)[(ulonglong)(uVar9 & 0xff) * 4];
        pbVar4[0x13] = (&DAT_180015c01)[(ulonglong)(uVar9 >> 8 & 0xff) * 4];
        pbVar4[0x14] = (&DAT_180015c01)[(ulonglong)(uVar9 >> 0x10 & 0xff) * 4];
        pbVar4[0x15] = (&DAT_180015c01)[(ulonglong)(uVar9 >> 0x18) * 4];
      }
      uVar6 = (*(uint *)(pbVar4 + 0x12) >> 8 | *(uint *)(pbVar4 + 0x12) << 0x18) ^ (uint)pbVar8[-1]
              ^ uVar6;
      uVar10 = uVar10 ^ uVar6;
      *(uint *)(pbVar4 + 0x12) = uVar6;
      uVar12 = uVar12 ^ uVar10;
      *(uint *)(pbVar4 + 0x16) = uVar10;
      uVar9 = uVar9 ^ uVar12;
      *(uint *)(pbVar4 + 0x1a) = uVar12;
      *(uint *)(pbVar4 + 0x1e) = uVar9;
      if (uVar11 == 0) {
        auVar16._4_4_ = uVar9;
        auVar16._0_4_ = uVar9;
        auVar16._8_4_ = uVar9;
        auVar16._12_4_ = uVar9;
        auVar19 = aeskeygenassist(auVar16,0);
        *(int *)(pbVar4 + 0x22) = auVar19._0_4_;
      }
      else {
        pbVar4[0x22] = (&DAT_180015c01)[(ulonglong)(uVar9 & 0xff) * 4];
        pbVar4[0x23] = (&DAT_180015c01)[(ulonglong)(uVar9 >> 8 & 0xff) * 4];
        pbVar4[0x24] = (&DAT_180015c01)[(ulonglong)(uVar9 >> 0x10 & 0xff) * 4];
        pbVar4[0x25] = (&DAT_180015c01)[(ulonglong)(uVar9 >> 0x18) * 4];
      }
      uVar6 = (*(uint *)(pbVar4 + 0x22) >> 8 | *(uint *)(pbVar4 + 0x22) << 0x18) ^ (uint)*pbVar8 ^
              uVar6;
      *(uint *)(pbVar4 + 0x22) = uVar6;
      uVar10 = uVar6 ^ uVar10;
      *(uint *)(pbVar4 + 0x26) = uVar10;
      uVar12 = uVar10 ^ uVar12;
      uVar9 = uVar9 ^ uVar12;
      *(uint *)(pbVar4 + 0x2a) = uVar12;
      *(uint *)(pbVar4 + 0x2e) = uVar9;
      if (uVar11 == 0) {
        auVar17._4_4_ = uVar9;
        auVar17._0_4_ = uVar9;
        auVar17._8_4_ = uVar9;
        auVar17._12_4_ = uVar9;
        auVar19 = aeskeygenassist(auVar17,0);
        *(int *)(pbVar4 + 0x32) = auVar19._0_4_;
      }
      else {
        pbVar4[0x32] = (&DAT_180015c01)[(ulonglong)(uVar9 & 0xff) * 4];
        pbVar4[0x33] = (&DAT_180015c01)[(ulonglong)(uVar9 >> 8 & 0xff) * 4];
        pbVar4[0x34] = (&DAT_180015c01)[(ulonglong)(uVar9 >> 0x10 & 0xff) * 4];
        pbVar4[0x35] = (&DAT_180015c01)[(ulonglong)(uVar9 >> 0x18) * 4];
      }
      uVar6 = (*(uint *)(pbVar4 + 0x32) >> 8 | *(uint *)(pbVar4 + 0x32) << 0x18) ^ (uint)pbVar8[1] ^
              uVar6;
      *(uint *)(pbVar4 + 0x32) = uVar6;
      uVar10 = uVar6 ^ uVar10;
      *(uint *)(pbVar4 + 0x36) = uVar10;
      uVar12 = uVar10 ^ uVar12;
      uVar9 = uVar9 ^ uVar12;
      *(uint *)(pbVar4 + 0x3a) = uVar12;
      *(uint *)(pbVar4 + 0x3e) = uVar9;
      if (uVar11 == 0) {
        auVar18._4_4_ = uVar9;
        auVar18._0_4_ = uVar9;
        auVar18._8_4_ = uVar9;
        auVar18._12_4_ = uVar9;
        auVar19 = aeskeygenassist(auVar18,0);
        *(int *)(pbVar4 + 0x42) = auVar19._0_4_;
      }
      else {
        pbVar4[0x42] = (&DAT_180015c01)[(ulonglong)(uVar9 & 0xff) * 4];
        pbVar4[0x43] = (&DAT_180015c01)[(ulonglong)(uVar9 >> 8 & 0xff) * 4];
        pbVar4[0x44] = (&DAT_180015c01)[(ulonglong)(uVar9 >> 0x10 & 0xff) * 4];
        pbVar4[0x45] = (&DAT_180015c01)[(ulonglong)(uVar9 >> 0x18) * 4];
      }
      pauVar5 = pauVar5 + 5;
      pbVar1 = pbVar8 + 2;
      pbVar8 = pbVar8 + 5;
      uVar6 = (*(uint *)(pbVar4 + 0x42) >> 8 | *(uint *)(pbVar4 + 0x42) << 0x18) ^ (uint)*pbVar1 ^
              uVar6;
      *(uint *)(pbVar4 + 0x42) = uVar6;
      uVar6 = uVar6 ^ uVar10;
      *(uint *)(pbVar4 + 0x46) = uVar6;
      uVar6 = uVar6 ^ uVar12;
      *(uint *)(pbVar4 + 0x4a) = uVar6;
      *(uint *)(pbVar4 + 0x4e) = uVar9 ^ uVar6;
      pbVar4 = pbVar4 + 0x50;
      local_res18 = local_res18 + -1;
    } while (local_res18 != 0);
  }
  else if (param_3 == 0x18) {
    *(undefined1 (**) [16])param_1[0x1d] = param_1 + 0xc;
    *(undefined1 (**) [16])(param_1[0x1d] + 8) = param_1 + 0x18;
    uVar3 = *(undefined8 *)(*param_2 + 8);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar3;
    *(undefined8 *)param_1[1] = *(undefined8 *)param_2[1];
    SymCryptAes4Sbox(param_1[1] + 4,(undefined4 *)(param_1[1] + 8),uVar7);
    uVar11 = (*(uint *)(param_1[1] + 8) >> 8 | *(uint *)(param_1[1] + 8) << 0x18) ^
             *(uint *)*param_1 ^ 1;
    *(uint *)(param_1[1] + 8) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(*param_1 + 4);
    *(uint *)(param_1[1] + 0xc) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(*param_1 + 8);
    *(uint *)param_1[2] = uVar11;
    uVar11 = uVar11 ^ *(uint *)(*param_1 + 0xc);
    *(uint *)(param_1[2] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)param_1[1];
    *(uint *)(param_1[2] + 8) = uVar11;
    *(uint *)(param_1[2] + 0xc) = uVar11 ^ *(uint *)(param_1[1] + 4);
    SymCryptAes4Sbox(param_1[2] + 0xc,(undefined4 *)(param_1 + 3),uVar7);
    uVar11 = (*(uint *)param_1[3] >> 8 | *(uint *)param_1[3] << 0x18) ^ *(uint *)(param_1[1] + 8) ^
             2;
    *(uint *)param_1[3] = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[1] + 0xc);
    *(uint *)(param_1[3] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)param_1[2];
    *(uint *)(param_1[3] + 8) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[2] + 4);
    *(uint *)(param_1[3] + 0xc) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[2] + 8);
    *(uint *)param_1[4] = uVar11;
    *(uint *)(param_1[4] + 4) = uVar11 ^ *(uint *)(param_1[2] + 0xc);
    SymCryptAes4Sbox(param_1[4] + 4,(undefined4 *)(param_1[4] + 8),uVar7);
    uVar11 = (*(uint *)(param_1[4] + 8) >> 8 | *(uint *)(param_1[4] + 8) << 0x18) ^
             *(uint *)param_1[3] ^ 4;
    *(uint *)(param_1[4] + 8) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[3] + 4);
    *(uint *)(param_1[4] + 0xc) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[3] + 8);
    *(uint *)param_1[5] = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[3] + 0xc);
    *(uint *)(param_1[5] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)param_1[4];
    *(uint *)(param_1[5] + 8) = uVar11;
    *(uint *)(param_1[5] + 0xc) = uVar11 ^ *(uint *)(param_1[4] + 4);
    SymCryptAes4Sbox(param_1[5] + 0xc,(undefined4 *)(param_1 + 6),uVar7);
    uVar11 = (*(uint *)param_1[6] >> 8 | *(uint *)param_1[6] << 0x18) ^ *(uint *)(param_1[4] + 8) ^
             8;
    *(uint *)param_1[6] = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[4] + 0xc);
    *(uint *)(param_1[6] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)param_1[5];
    *(uint *)(param_1[6] + 8) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[5] + 4);
    *(uint *)(param_1[6] + 0xc) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[5] + 8);
    *(uint *)param_1[7] = uVar11;
    *(uint *)(param_1[7] + 4) = uVar11 ^ *(uint *)(param_1[5] + 0xc);
    SymCryptAes4Sbox(param_1[7] + 4,(undefined4 *)(param_1[7] + 8),uVar7);
    uVar11 = (*(uint *)(param_1[7] + 8) >> 8 | *(uint *)(param_1[7] + 8) << 0x18) ^
             *(uint *)param_1[6] ^ 0x10;
    *(uint *)(param_1[7] + 8) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[6] + 4);
    *(uint *)(param_1[7] + 0xc) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[6] + 8);
    *(uint *)param_1[8] = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[6] + 0xc);
    *(uint *)(param_1[8] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)param_1[7];
    *(uint *)(param_1[8] + 8) = uVar11;
    *(uint *)(param_1[8] + 0xc) = uVar11 ^ *(uint *)(param_1[7] + 4);
    SymCryptAes4Sbox(param_1[8] + 0xc,(undefined4 *)(param_1 + 9),uVar7);
    uVar11 = (*(uint *)param_1[9] >> 8 | *(uint *)param_1[9] << 0x18) ^ *(uint *)(param_1[7] + 8) ^
             0x20;
    *(uint *)param_1[9] = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[7] + 0xc);
    *(uint *)(param_1[9] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)param_1[8];
    *(uint *)(param_1[9] + 8) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[8] + 4);
    *(uint *)(param_1[9] + 0xc) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[8] + 8);
    *(uint *)param_1[10] = uVar11;
    *(uint *)(param_1[10] + 4) = uVar11 ^ *(uint *)(param_1[8] + 0xc);
    SymCryptAes4Sbox(param_1[10] + 4,(undefined4 *)(param_1[10] + 8),uVar7);
    pauVar5 = param_1 + 0xc;
    uVar11 = (*(uint *)(param_1[10] + 8) >> 8 | *(uint *)(param_1[10] + 8) << 0x18) ^
             *(uint *)param_1[9] ^ 0x40;
    *(uint *)(param_1[10] + 8) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[9] + 4);
    *(uint *)(param_1[10] + 0xc) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[9] + 8);
    *(uint *)param_1[0xb] = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[9] + 0xc);
    *(uint *)(param_1[0xb] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)param_1[10];
    *(uint *)(param_1[0xb] + 8) = uVar11;
    *(uint *)(param_1[0xb] + 0xc) = uVar11 ^ *(uint *)(param_1[10] + 4);
    SymCryptAes4Sbox(param_1[0xb] + 0xc,(undefined4 *)pauVar5,uVar7);
    uVar11 = (*(uint *)*pauVar5 >> 8 | *(uint *)*pauVar5 << 0x18) ^ *(uint *)(param_1[10] + 8) ^
             0x80;
    *(uint *)*pauVar5 = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[10] + 0xc);
    *(uint *)(param_1[0xc] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)param_1[0xb];
    *(uint *)(param_1[0xc] + 8) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[0xb] + 4);
    *(uint *)(param_1[0xc] + 0xc) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[0xb] + 8);
    *(uint *)param_1[0xd] = uVar11;
    *(uint *)(param_1[0xd] + 4) = uVar11 ^ *(uint *)(param_1[0xb] + 0xc);
  }
  else {
    if (param_3 != 0x20) {
      return 0x8001;
    }
    *(undefined1 (**) [16])param_1[0x1d] = param_1 + 0xe;
    pauVar5 = param_1 + 2;
    *(undefined1 (**) [16])(param_1[0x1d] + 8) = param_1 + 0x1c;
    uVar3 = *(undefined8 *)(*param_2 + 8);
    *(undefined8 *)*param_1 = *(undefined8 *)*param_2;
    *(undefined8 *)(*param_1 + 8) = uVar3;
    uVar3 = *(undefined8 *)(param_2[1] + 8);
    *(undefined8 *)param_1[1] = *(undefined8 *)param_2[1];
    *(undefined8 *)(param_1[1] + 8) = uVar3;
    SymCryptAes4Sbox(param_1[1] + 0xc,(undefined4 *)pauVar5,(uint)bVar14);
    uVar11 = (*(uint *)*pauVar5 >> 8 | *(uint *)*pauVar5 << 0x18) ^ *(uint *)*param_1 ^ 1;
    *(uint *)*pauVar5 = uVar11;
    uVar11 = uVar11 ^ *(uint *)(*param_1 + 4);
    *(uint *)(param_1[2] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(*param_1 + 8);
    *(uint *)(param_1[2] + 8) = uVar11;
    *(uint *)(param_1[2] + 0xc) = uVar11 ^ *(uint *)(*param_1 + 0xc);
    SymCryptAes4Sbox(param_1[2] + 0xc,(undefined4 *)(param_1 + 3),(uint)bVar14);
    *(uint *)param_1[3] = *(uint *)param_1[3] ^ *(uint *)param_1[1];
    uVar6 = (uint)bVar14;
    uVar11 = *(uint *)param_1[3] ^ *(uint *)(param_1[1] + 4);
    *(uint *)(param_1[3] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[1] + 8);
    *(uint *)(param_1[3] + 8) = uVar11;
    *(uint *)(param_1[3] + 0xc) = uVar11 ^ *(uint *)(param_1[1] + 0xc);
    SymCryptAes4Sbox(param_1[3] + 0xc,(undefined4 *)(param_1 + 4),uVar6);
    uVar11 = (*(uint *)param_1[4] >> 8 | *(uint *)param_1[4] << 0x18) ^ *(uint *)*pauVar5 ^ 2;
    *(uint *)param_1[4] = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[2] + 4);
    *(uint *)(param_1[4] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[2] + 8);
    *(uint *)(param_1[4] + 8) = uVar11;
    *(uint *)(param_1[4] + 0xc) = uVar11 ^ *(uint *)(param_1[2] + 0xc);
    SymCryptAes4Sbox(param_1[4] + 0xc,(undefined4 *)(param_1 + 5),uVar6);
    *(uint *)param_1[5] = *(uint *)param_1[5] ^ *(uint *)param_1[3];
    uVar11 = *(uint *)param_1[5] ^ *(uint *)(param_1[3] + 4);
    *(uint *)(param_1[5] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[3] + 8);
    *(uint *)(param_1[5] + 8) = uVar11;
    *(uint *)(param_1[5] + 0xc) = uVar11 ^ *(uint *)(param_1[3] + 0xc);
    SymCryptAes4Sbox(param_1[5] + 0xc,(undefined4 *)(param_1 + 6),uVar6);
    uVar11 = (*(uint *)param_1[6] >> 8 | *(uint *)param_1[6] << 0x18) ^ *(uint *)param_1[4] ^ 4;
    *(uint *)param_1[6] = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[4] + 4);
    *(uint *)(param_1[6] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[4] + 8);
    *(uint *)(param_1[6] + 8) = uVar11;
    *(uint *)(param_1[6] + 0xc) = uVar11 ^ *(uint *)(param_1[4] + 0xc);
    SymCryptAes4Sbox(param_1[6] + 0xc,(undefined4 *)(param_1 + 7),uVar6);
    *(uint *)param_1[7] = *(uint *)param_1[7] ^ *(uint *)param_1[5];
    uVar11 = *(uint *)param_1[7] ^ *(uint *)(param_1[5] + 4);
    *(uint *)(param_1[7] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[5] + 8);
    *(uint *)(param_1[7] + 8) = uVar11;
    *(uint *)(param_1[7] + 0xc) = uVar11 ^ *(uint *)(param_1[5] + 0xc);
    SymCryptAes4Sbox(param_1[7] + 0xc,(undefined4 *)(param_1 + 8),uVar7);
    uVar11 = (*(uint *)param_1[8] >> 8 | *(uint *)param_1[8] << 0x18) ^ *(uint *)param_1[6] ^ 8;
    *(uint *)param_1[8] = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[6] + 4);
    *(uint *)(param_1[8] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[6] + 8);
    *(uint *)(param_1[8] + 8) = uVar11;
    *(uint *)(param_1[8] + 0xc) = uVar11 ^ *(uint *)(param_1[6] + 0xc);
    SymCryptAes4Sbox(param_1[8] + 0xc,(undefined4 *)(param_1 + 9),uVar7);
    *(uint *)param_1[9] = *(uint *)param_1[9] ^ *(uint *)param_1[7];
    uVar11 = *(uint *)param_1[9] ^ *(uint *)(param_1[7] + 4);
    *(uint *)(param_1[9] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[7] + 8);
    *(uint *)(param_1[9] + 8) = uVar11;
    *(uint *)(param_1[9] + 0xc) = uVar11 ^ *(uint *)(param_1[7] + 0xc);
    SymCryptAes4Sbox(param_1[9] + 0xc,(undefined4 *)(param_1 + 10),uVar7);
    uVar11 = (*(uint *)param_1[10] >> 8 | *(uint *)param_1[10] << 0x18) ^ *(uint *)param_1[8] ^ 0x10
    ;
    *(uint *)param_1[10] = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[8] + 4);
    *(uint *)(param_1[10] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[8] + 8);
    *(uint *)(param_1[10] + 8) = uVar11;
    *(uint *)(param_1[10] + 0xc) = uVar11 ^ *(uint *)(param_1[8] + 0xc);
    SymCryptAes4Sbox(param_1[10] + 0xc,(undefined4 *)(param_1 + 0xb),uVar7);
    pauVar5 = param_1 + 0xc;
    *(uint *)param_1[0xb] = *(uint *)param_1[0xb] ^ *(uint *)param_1[9];
    uVar11 = *(uint *)param_1[0xb] ^ *(uint *)(param_1[9] + 4);
    *(uint *)(param_1[0xb] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[9] + 8);
    *(uint *)(param_1[0xb] + 8) = uVar11;
    *(uint *)(param_1[0xb] + 0xc) = uVar11 ^ *(uint *)(param_1[9] + 0xc);
    SymCryptAes4Sbox(param_1[0xb] + 0xc,(undefined4 *)pauVar5,uVar7);
    uVar11 = (*(uint *)*pauVar5 >> 8 | *(uint *)*pauVar5 << 0x18) ^ *(uint *)param_1[10] ^ 0x20;
    *(uint *)*pauVar5 = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[10] + 4);
    *(uint *)(param_1[0xc] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[10] + 8);
    *(uint *)(param_1[0xc] + 8) = uVar11;
    pauVar5 = param_1 + 0xd;
    *(uint *)(param_1[0xc] + 0xc) = uVar11 ^ *(uint *)(param_1[10] + 0xc);
    SymCryptAes4Sbox(param_1[0xc] + 0xc,(undefined4 *)pauVar5,uVar7);
    *(uint *)*pauVar5 = *(uint *)*pauVar5 ^ *(uint *)param_1[0xb];
    uVar11 = *(uint *)*pauVar5 ^ *(uint *)(param_1[0xb] + 4);
    *(uint *)(param_1[0xd] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[0xb] + 8);
    *(uint *)(param_1[0xd] + 8) = uVar11;
    *(uint *)(param_1[0xd] + 0xc) = uVar11 ^ *(uint *)(param_1[0xb] + 0xc);
    pauVar5 = param_1 + 0xe;
    SymCryptAes4Sbox(param_1[0xd] + 0xc,(undefined4 *)pauVar5,uVar7);
    uVar11 = (*(uint *)*pauVar5 >> 8 | *(uint *)*pauVar5 << 0x18) ^ *(uint *)param_1[0xc] ^ 0x40;
    *(uint *)*pauVar5 = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[0xc] + 4);
    *(uint *)(param_1[0xe] + 4) = uVar11;
    uVar11 = uVar11 ^ *(uint *)(param_1[0xc] + 8);
    *(uint *)(param_1[0xe] + 8) = uVar11;
    *(uint *)(param_1[0xe] + 0xc) = uVar11 ^ *(uint *)(param_1[0xc] + 0xc);
  }
  if (param_4 != '\0') {
    pauVar13 = *(undefined1 (**) [16])(param_1[0x1d] + 8);
    pauVar5 = param_1 + 1;
    uVar3 = *(undefined8 *)(*param_1 + 8);
    *(undefined8 *)*pauVar13 = *(undefined8 *)*param_1;
    *(undefined8 *)(*pauVar13 + 8) = uVar3;
    if (pauVar5 < *(undefined1 (**) [16])param_1[0x1d]) {
      do {
        pauVar13 = pauVar13 + -1;
        SymCryptAesCreateDecryptionRoundKey(pauVar5,pauVar13,uVar7);
        pauVar5 = pauVar5 + 1;
      } while (pauVar5 < *(undefined1 (**) [16])param_1[0x1d]);
    }
  }
  return 0;
}



===== SymCryptHmacSha256 @ 18000398c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptHmacSha256(undefined8 *param_1,undefined8 param_2,undefined8 param_3,ulonglong *param_4
                       )

{
  undefined1 auStack_c8 [32];
  uint local_a8 [36];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  local_a8[1] = 0;
  memset(local_a8,0,0x8c);
  SymCryptHmacSha256Init(local_a8,param_1);
  SymCryptSha256Append(local_a8,(undefined1 (*) [16])0x180015820,3);
  SymCryptHmacSha256Result(local_a8,param_4);
  return;
}



===== SymCryptPbkdf2 @ 180003a30 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Type propagation algorithm not settling */

ulonglong SymCryptPbkdf2(void)

{
  undefined *_Size;
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong *puVar7;
  longlong lVar8;
  ulonglong *puVar9;
  longlong lVar10;
  undefined *puVar11;
  uint uVar12;
  undefined *puVar13;
  void *in_stack_00000038;
  undefined1 auStack_418 [32];
  undefined1 local_3f8 [4];
  undefined4 local_3f4;
  uint local_2e8 [136];
  undefined **local_c8;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_418;
  memset(local_2e8,0,0x230);
  puVar13 = (undefined *)0x8;
  local_c8 = &SymCryptHmacSha256Algorithm_default;
  uVar3 = SymCryptHmacSha256ExpandKey(local_2e8,(undefined1 (*) [16])&SymCryptTestKey32,8);
  uVar6 = uVar3 & 0xffffffff;
  if ((int)uVar3 == 0) {
    local_3f4 = 0;
    memset(local_3f8,0,0x10c);
    uVar6 = 0;
    uVar12 = 0;
    _Size = local_c8[6];
    do {
      uVar12 = uVar12 + 1;
      local_b8 = CONCAT44(local_b8._4_4_,
                          uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 |
                          uVar12 * 0x1000000);
      (*(code *)local_c8[1])(local_3f8,local_2e8);
      (*(code *)local_c8[2])(local_3f8);
      (*(code *)local_c8[2])(local_3f8,&local_b8,4);
      (*(code *)local_c8[3])(local_3f8,&local_78);
      memmove(&local_b8,&local_78,(size_t)_Size);
      lVar5 = 4;
      do {
        (*(code *)local_c8[1])(local_3f8,local_2e8);
        (*(code *)local_c8[2])(local_3f8,&local_78,_Size);
        (*(code *)local_c8[3])(local_3f8,&local_78);
        puVar7 = &local_b8;
        puVar4 = &local_b8;
        puVar9 = &local_78;
        if (_Size == (undefined *)0x10) {
          local_b8 = CONCAT44(local_b8._4_4_ ^ local_78._4_4_,(uint)local_b8 ^ (uint)local_78);
          uStack_b0 = CONCAT44(uStack_b0._4_4_ ^ uStack_70._4_4_,(uint)uStack_b0 ^ (uint)uStack_70);
        }
        else {
          puVar11 = _Size;
          if ((undefined *)0x7 < _Size) {
            uVar3 = (ulonglong)_Size >> 3;
            puVar11 = _Size + uVar3 * -8;
            do {
              uVar1 = *puVar9;
              puVar9 = puVar9 + 1;
              uVar2 = *puVar4;
              puVar4 = puVar4 + 1;
              *puVar7 = uVar1 ^ uVar2;
              puVar7 = puVar7 + 1;
              uVar3 = uVar3 - 1;
            } while (uVar3 != 0);
          }
          if (puVar11 != (undefined *)0x0) {
            lVar10 = (longlong)puVar9 - (longlong)puVar4;
            lVar8 = (longlong)puVar7 - (longlong)puVar4;
            do {
              *(byte *)(lVar8 + (longlong)puVar4) =
                   *(byte *)(lVar10 + (longlong)puVar4) ^ (byte)*puVar4;
              puVar4 = (ulonglong *)((longlong)puVar4 + 1);
              puVar11 = puVar11 + -1;
            } while (puVar11 != (undefined *)0x0);
          }
        }
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
      puVar11 = puVar13;
      if (_Size <= puVar13) {
        puVar11 = _Size;
      }
      memmove(in_stack_00000038,&local_b8,(size_t)puVar11);
      in_stack_00000038 = (void *)((longlong)in_stack_00000038 + (longlong)puVar11);
      puVar13 = puVar13 + -(longlong)puVar11;
    } while (puVar13 != (undefined *)0x0);
    local_78 = 0;
    uStack_70 = 0;
    local_68 = 0;
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    local_48 = 0;
    local_40 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    local_a8 = 0;
    local_a0 = 0;
    local_98 = 0;
    local_90 = 0;
    local_88 = 0;
    local_80 = 0;
  }
  SymCryptWipeAsm((undefined8 *)local_2e8,0x230);
  return uVar6;
}



===== SymCryptHmacSha256ExpandKey @ 180003d60 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SymCryptHmacSha256ExpandKey(uint *param_1,undefined1 (*param_2) [16],ulonglong param_3)

{
  uint *puVar1;
  undefined1 auStack_1a8 [32];
  undefined1 local_188 [64];
  undefined1 local_148 [64];
  ulonglong local_108 [2];
  uint local_f8 [24];
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  ulonglong local_78;
  ulonglong uStack_70;
  ulonglong local_68;
  ulonglong uStack_60;
  ulonglong local_58;
  ulonglong uStack_50;
  ulonglong local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_1a8;
  local_f8[1] = 0;
  memset(local_f8,0,0x7c);
  local_108[0] = 0;
  SymCryptSha256Init(local_f8);
  memset(&local_78,0,0x40);
  if (param_3 < 0x41) {
    if (param_3 != 0) {
      memmove(&local_78,param_2,param_3);
    }
  }
  else {
    SymCryptSha256Append(local_f8,param_2,param_3);
    SymCryptSha256Result(local_f8,&local_78);
  }
  local_78 = local_78 ^ 0x3636363636363636;
  uStack_70 = uStack_70 ^ 0x3636363636363636;
  local_68 = local_68 ^ 0x3636363636363636;
  uStack_60 = uStack_60 ^ 0x3636363636363636;
  local_58 = local_58 ^ 0x3636363636363636;
  uStack_50 = uStack_50 ^ 0x3636363636363636;
  *(undefined8 *)param_1 = local_98;
  *(undefined8 *)(param_1 + 2) = uStack_90;
  *(undefined8 *)(param_1 + 8) = local_98;
  *(undefined8 *)(param_1 + 10) = uStack_90;
  *(undefined8 *)(param_1 + 4) = local_88;
  *(undefined8 *)(param_1 + 6) = uStack_80;
  *(undefined8 *)(param_1 + 0xc) = local_88;
  *(undefined8 *)(param_1 + 0xe) = uStack_80;
  local_48 = local_48 ^ 0x3636363636363636;
  uStack_40 = uStack_40 ^ 0x3636363636363636;
  memset(local_188,0,0x40);
  if ((g_SymCryptCpuFeaturesNotPresent & 0x42) == 0) {
    SymCryptSha256AppendBlocks_shani(param_1,(undefined1 (*) [16])&local_78,0x40,local_108);
  }
  else if ((g_SymCryptCpuFeaturesNotPresent & 0x82) == 0) {
    SymCryptSha256AppendBlocks_xmm_ssse3_asm(param_1,(undefined1 (*) [16])&local_78,0x40,local_108);
  }
  else {
    SymCryptSha256AppendBlocks_ul1(param_1,(longlong)&local_78,0x40,local_108);
  }
  local_78 = local_78 ^ 0x6a6a6a6a6a6a6a6a;
  uStack_70 = uStack_70 ^ 0x6a6a6a6a6a6a6a6a;
  local_68 = local_68 ^ 0x6a6a6a6a6a6a6a6a;
  uStack_60 = uStack_60 ^ 0x6a6a6a6a6a6a6a6a;
  local_58 = local_58 ^ 0x6a6a6a6a6a6a6a6a;
  uStack_50 = uStack_50 ^ 0x6a6a6a6a6a6a6a6a;
  local_48 = local_48 ^ 0x6a6a6a6a6a6a6a6a;
  uStack_40 = uStack_40 ^ 0x6a6a6a6a6a6a6a6a;
  memset(local_148,0,0x40);
  puVar1 = param_1 + 8;
  if ((g_SymCryptCpuFeaturesNotPresent & 0x42) == 0) {
    SymCryptSha256AppendBlocks_shani(puVar1,(undefined1 (*) [16])&local_78,0x40,local_108);
  }
  else if ((g_SymCryptCpuFeaturesNotPresent & 0x82) == 0) {
    SymCryptSha256AppendBlocks_xmm_ssse3_asm(puVar1,(undefined1 (*) [16])&local_78,0x40,local_108);
  }
  else {
    SymCryptSha256AppendBlocks_ul1(puVar1,(longlong)&local_78,0x40,local_108);
  }
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  SymCryptWipeAsm((undefined8 *)local_f8,0x80);
  return 0;
}



===== SymCryptSha256Init @ 180003f60 =====

void SymCryptSha256Init(undefined4 *param_1)

{
  *(undefined8 *)(param_1 + 4) = 0;
  *param_1 = 0;
  *(undefined8 *)(param_1 + 0x18) = 0xbb67ae856a09e667;
  *(undefined8 *)(param_1 + 0x1a) = 0xa54ff53a3c6ef372;
  *(undefined8 *)(param_1 + 0x1c) = 0x9b05688c510e527f;
  *(undefined8 *)(param_1 + 0x1e) = 0x5be0cd191f83d9ab;
  return;
}



===== SymCryptSha256AppendBlocks @ 180003f90 =====

void SymCryptSha256AppendBlocks
               (uint *param_1,undefined1 (*param_2) [16],ulonglong param_3,ulonglong *param_4)

{
  if ((g_SymCryptCpuFeaturesNotPresent & 0x42) == 0) {
    SymCryptSha256AppendBlocks_shani(param_1,param_2,param_3,param_4);
  }
  else {
    if ((g_SymCryptCpuFeaturesNotPresent & 0x82) == 0) {
      SymCryptSha256AppendBlocks_xmm_ssse3_asm(param_1,param_2,param_3,param_4);
      return;
    }
    SymCryptSha256AppendBlocks_ul1(param_1,(longlong)param_2,param_3,param_4);
  }
  return;
}



===== SymCryptHmacSha256Result @ 180003fd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptHmacSha256Result(uint *param_1,ulonglong *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auStack_58 [32];
  ulonglong local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_58;
  SymCryptSha256Result(param_1,&local_38);
  lVar1 = *(longlong *)(param_1 + 0x20);
  uVar2 = *(undefined8 *)(lVar1 + 0x28);
  *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(lVar1 + 0x20);
  *(undefined8 *)(param_1 + 0x1a) = uVar2;
  uVar2 = *(undefined8 *)(lVar1 + 0x30);
  uVar3 = *(undefined8 *)(lVar1 + 0x38);
  param_1[4] = 0x60;
  param_1[5] = 0;
  *(undefined8 *)(param_1 + 0x1c) = uVar2;
  *(undefined8 *)(param_1 + 0x1e) = uVar3;
  *param_1 = 0x20;
  *(ulonglong *)(param_1 + 8) = local_38;
  *(undefined8 *)(param_1 + 10) = uStack_30;
  *(undefined8 *)(param_1 + 0xc) = local_28;
  *(undefined8 *)(param_1 + 0xe) = uStack_20;
  SymCryptSha256Result(param_1,param_2);
  SymCryptWipeAsm(&local_38,0x20);
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  return;
}



===== SymCryptSha256Result @ 180004080 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptSha256Result(uint *param_1,ulonglong *param_2)

{
  undefined1 (*pauVar1) [16];
  uint *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  uint uVar6;
  ulonglong uVar7;
  longlong lVar8;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uVar6 = *param_1;
  *(undefined1 *)((ulonglong)uVar6 + 0x20 + (longlong)param_1) = 0x80;
  uVar6 = uVar6 + 1;
  uVar7 = (ulonglong)uVar6;
  if (0x38 < uVar6) {
    SymCryptWipeAsm((undefined8 *)(uVar7 + 0x20 + (longlong)param_1),(ulonglong)(0x40 - uVar6));
    SymCryptSha256AppendBlocks(param_1 + 0x18,(undefined1 (*) [16])(param_1 + 8),0x40,&local_28);
    uVar7 = 0;
  }
  SymCryptWipeAsm((undefined8 *)(uVar7 + 0x20 + (longlong)param_1),(ulonglong)(0x40 - (int)uVar7));
  uVar7 = *(ulonglong *)(param_1 + 4);
  uVar4 = uVar7 << 3;
  pauVar1 = (undefined1 (*) [16])(param_1 + 8);
  *(ulonglong *)(param_1 + 0x16) =
       (uVar7 & 0x1fffffffffffffff) >> 0x35 | (uVar4 & 0xff000000000000) >> 0x28 |
       (uVar4 & 0xff0000000000) >> 0x18 | (uVar4 & 0xff00000000) >> 8 | (uVar4 & 0xff000000) << 8 |
       (uVar4 & 0xff0000) << 0x18 | (uVar4 & 0xff00) << 0x28 | uVar7 << 0x3b;
  puVar2 = param_1 + 0x18;
  if ((g_SymCryptCpuFeaturesNotPresent & 0x42) == 0) {
    SymCryptSha256AppendBlocks_shani(puVar2,pauVar1,0x40,&local_28);
  }
  else if ((g_SymCryptCpuFeaturesNotPresent & 0x82) == 0) {
    SymCryptSha256AppendBlocks_xmm_ssse3_asm(puVar2,pauVar1,0x40,&local_28);
  }
  else {
    SymCryptSha256AppendBlocks_ul1(puVar2,(longlong)pauVar1,0x40,&local_28);
  }
  puVar5 = (ulonglong *)(param_1 + 0x18);
  lVar8 = 4;
  do {
    uVar7 = *puVar5;
    uVar4 = uVar7 << 0x20;
    uVar3 = uVar7 >> 0x20;
    puVar5 = puVar5 + 1;
    *param_2 = (uVar7 & 0xffffffff) >> 0x18 | (uVar4 & 0xff000000000000) >> 0x28 |
               (uVar4 & 0xff0000000000) >> 0x18 | (uVar4 & 0xff00000000) >> 8 |
               (uVar3 & 0xff000000) << 8 | (uVar3 & 0xff0000) << 0x18 | (uVar3 & 0xff00) << 0x28 |
               uVar3 << 0x38;
    lVar8 = lVar8 + -1;
    param_2 = param_2 + 1;
  } while (lVar8 != 0);
  SymCryptWipeAsm((undefined8 *)param_1,0x80);
  param_1[0x18] = 0x6a09e667;
  param_1[0x19] = 0xbb67ae85;
  param_1[0x1a] = 0x3c6ef372;
  param_1[0x1b] = 0xa54ff53a;
  param_1[0x1c] = 0x510e527f;
  param_1[0x1d] = 0x9b05688c;
  param_1[0x1e] = 0x1f83d9ab;
  param_1[0x1f] = 0x5be0cd19;
  return;
}



===== SymCryptSha256AppendBlocks_shani @ 1800041c0 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SymCryptSha256AppendBlocks_shani
               (undefined4 *param_1,undefined1 (*param_2) [16],ulonglong param_3,ulonglong *param_4)

{
  undefined1 (*pauVar1) [16];
  undefined1 (*pauVar2) [16];
  ulonglong uVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  int iVar51;
  int iVar52;
  int iVar53;
  int iVar54;
  
  iVar54 = param_1[2];
  iVar53 = param_1[3];
  iVar52 = param_1[6];
  iVar51 = param_1[7];
  auVar28._4_4_ = param_1[4];
  auVar28._0_4_ = param_1[5];
  auVar28._8_4_ = param_1[1];
  auVar28._12_4_ = *param_1;
  if (0x3f < param_3) {
    uVar3 = param_3 >> 6;
    param_3 = param_3 + uVar3 * -0x40;
    auVar47 = auVar28;
    do {
      auVar28 = pshufb(*param_2,___xmm_0c0d0e0f08090a0b0405060700010203);
      auVar31 = pshufb(param_2[1],___xmm_0c0d0e0f08090a0b0405060700010203);
      pauVar1 = param_2 + 2;
      pauVar2 = param_2 + 3;
      param_2 = param_2 + 4;
      auVar34 = pshufb(*pauVar1,___xmm_0c0d0e0f08090a0b0405060700010203);
      auVar37 = pshufb(*pauVar2,___xmm_0c0d0e0f08090a0b0405060700010203);
      auVar48._0_4_ = auVar28._0_4_ + 0x428a2f98;
      auVar48._4_4_ = auVar28._4_4_ + 0x71374491;
      auVar48._8_4_ = auVar28._8_4_ + -0x4a3f0431;
      auVar48._12_4_ = auVar28._12_4_ + -0x164a245b;
      auVar28 = sha256msg1_sha(auVar28,auVar31);
      auVar44._4_4_ = iVar52;
      auVar44._0_4_ = iVar51;
      auVar44._8_4_ = iVar53;
      auVar44._12_4_ = iVar54;
      auVar44 = sha256rnds2_sha(auVar44,auVar47,auVar48);
      auVar40._4_4_ = auVar48._12_4_;
      auVar40._0_4_ = auVar48._8_4_;
      auVar40._8_4_ = auVar48._0_4_;
      auVar40._12_4_ = auVar48._0_4_;
      auVar39._0_4_ = auVar34._4_4_ + auVar28._0_4_;
      auVar39._4_4_ = auVar34._8_4_ + auVar28._4_4_;
      auVar39._8_4_ = auVar34._12_4_ + auVar28._8_4_;
      auVar39._12_4_ = auVar37._0_4_ + auVar28._12_4_;
      auVar48 = sha256rnds2_sha(auVar47,auVar44,auVar40);
      auVar45._0_4_ = auVar31._0_4_ + 0x3956c25b;
      auVar45._4_4_ = auVar31._4_4_ + 0x59f111f1;
      auVar45._8_4_ = auVar31._8_4_ + -0x6dc07d5c;
      auVar45._12_4_ = auVar31._12_4_ + -0x54e3a12b;
      auVar28 = sha256rnds2_sha(auVar44,auVar48,auVar45);
      auVar49._4_4_ = auVar45._12_4_;
      auVar49._0_4_ = auVar45._8_4_;
      auVar49._8_4_ = auVar45._0_4_;
      auVar49._12_4_ = auVar45._0_4_;
      auVar44 = sha256rnds2_sha(auVar48,auVar28,auVar49);
      auVar46._0_4_ = auVar34._0_4_ + -0x27f85568;
      auVar46._4_4_ = auVar34._4_4_ + 0x12835b01;
      auVar46._8_4_ = auVar34._8_4_ + 0x243185be;
      auVar46._12_4_ = auVar34._12_4_ + 0x550c7dc3;
      auVar28 = sha256rnds2_sha(auVar28,auVar44,auVar46);
      auVar50._4_4_ = auVar46._12_4_;
      auVar50._0_4_ = auVar46._8_4_;
      auVar50._8_4_ = auVar46._0_4_;
      auVar50._12_4_ = auVar46._0_4_;
      auVar44 = sha256rnds2_sha(auVar44,auVar28,auVar50);
      auVar4._0_4_ = auVar37._0_4_ + 0x72be5d74;
      auVar4._4_4_ = auVar37._4_4_ + -0x7f214e02;
      auVar4._8_4_ = auVar37._8_4_ + -0x6423f959;
      auVar4._12_4_ = auVar37._12_4_ + -0x3e640e8c;
      auVar28 = sha256rnds2_sha(auVar28,auVar44,auVar4);
      auVar5._4_4_ = auVar4._12_4_;
      auVar5._0_4_ = auVar4._8_4_;
      auVar5._8_4_ = auVar4._0_4_;
      auVar5._12_4_ = auVar4._0_4_;
      auVar44 = sha256rnds2_sha(auVar44,auVar28,auVar5);
      auVar40 = sha256msg2_sha(auVar39,auVar37);
      auVar6._0_4_ = auVar40._0_4_ + -0x1b64963f;
      auVar6._4_4_ = auVar40._4_4_ + -0x1041b87a;
      auVar6._8_4_ = auVar40._8_4_ + 0xfc19dc6;
      auVar6._12_4_ = auVar40._12_4_ + 0x240ca1cc;
      auVar45 = sha256rnds2_sha(auVar28,auVar44,auVar6);
      auVar7._4_4_ = auVar6._12_4_;
      auVar7._0_4_ = auVar6._8_4_;
      auVar7._8_4_ = auVar6._0_4_;
      auVar7._12_4_ = auVar6._0_4_;
      auVar49 = sha256rnds2_sha(auVar44,auVar45,auVar7);
      auVar28 = sha256msg1_sha(auVar31,auVar34);
      auVar44 = sha256msg1_sha(auVar34,auVar37);
      auVar48 = sha256msg1_sha(auVar37,auVar40);
      auVar29._0_4_ = auVar37._4_4_ + auVar28._0_4_;
      auVar29._4_4_ = auVar37._8_4_ + auVar28._4_4_;
      auVar29._8_4_ = auVar37._12_4_ + auVar28._8_4_;
      auVar29._12_4_ = auVar40._0_4_ + auVar28._12_4_;
      auVar28 = sha256msg2_sha(auVar29,auVar40);
      auVar31._0_4_ = auVar28._0_4_ + 0x2de92c6f;
      auVar31._4_4_ = auVar28._4_4_ + 0x4a7484aa;
      auVar31._8_4_ = auVar28._8_4_ + 0x5cb0a9dc;
      auVar31._12_4_ = auVar28._12_4_ + 0x76f988da;
      auVar45 = sha256rnds2_sha(auVar45,auVar49,auVar31);
      auVar34._4_4_ = auVar31._12_4_;
      auVar34._0_4_ = auVar31._8_4_;
      auVar34._8_4_ = auVar31._0_4_;
      auVar34._12_4_ = auVar31._0_4_;
      auVar49 = sha256rnds2_sha(auVar49,auVar45,auVar34);
      auVar32._0_4_ = auVar40._4_4_ + auVar44._0_4_;
      auVar32._4_4_ = auVar40._8_4_ + auVar44._4_4_;
      auVar32._8_4_ = auVar40._12_4_ + auVar44._8_4_;
      auVar32._12_4_ = auVar28._0_4_ + auVar44._12_4_;
      auVar44 = sha256msg2_sha(auVar32,auVar28);
      auVar37._0_4_ = auVar44._0_4_ + -0x67c1aeae;
      auVar37._4_4_ = auVar44._4_4_ + -0x57ce3993;
      auVar37._8_4_ = auVar44._8_4_ + -0x4ffcd838;
      auVar37._12_4_ = auVar44._12_4_ + -0x40a68039;
      auVar45 = sha256rnds2_sha(auVar45,auVar49,auVar37);
      auVar8._4_4_ = auVar37._12_4_;
      auVar8._0_4_ = auVar37._8_4_;
      auVar8._8_4_ = auVar37._0_4_;
      auVar8._12_4_ = auVar37._0_4_;
      auVar49 = sha256rnds2_sha(auVar49,auVar45,auVar8);
      auVar35._0_4_ = auVar28._4_4_ + auVar48._0_4_;
      auVar35._4_4_ = auVar28._8_4_ + auVar48._4_4_;
      auVar35._8_4_ = auVar28._12_4_ + auVar48._8_4_;
      auVar35._12_4_ = auVar44._0_4_ + auVar48._12_4_;
      auVar48 = sha256msg2_sha(auVar35,auVar44);
      auVar9._0_4_ = auVar48._0_4_ + -0x391ff40d;
      auVar9._4_4_ = auVar48._4_4_ + -0x2a586eb9;
      auVar9._8_4_ = auVar48._8_4_ + 0x6ca6351;
      auVar9._12_4_ = auVar48._12_4_ + 0x14292967;
      auVar45 = sha256rnds2_sha(auVar45,auVar49,auVar9);
      auVar10._4_4_ = auVar9._12_4_;
      auVar10._0_4_ = auVar9._8_4_;
      auVar10._8_4_ = auVar9._0_4_;
      auVar10._12_4_ = auVar9._0_4_;
      auVar49 = sha256rnds2_sha(auVar49,auVar45,auVar10);
      auVar40 = sha256msg1_sha(auVar40,auVar28);
      auVar38._0_4_ = auVar44._4_4_ + auVar40._0_4_;
      auVar38._4_4_ = auVar44._8_4_ + auVar40._4_4_;
      auVar38._8_4_ = auVar44._12_4_ + auVar40._8_4_;
      auVar38._12_4_ = auVar48._0_4_ + auVar40._12_4_;
      auVar40 = sha256msg2_sha(auVar38,auVar48);
      auVar11._0_4_ = auVar40._0_4_ + 0x27b70a85;
      auVar11._4_4_ = auVar40._4_4_ + 0x2e1b2138;
      auVar11._8_4_ = auVar40._8_4_ + 0x4d2c6dfc;
      auVar11._12_4_ = auVar40._12_4_ + 0x53380d13;
      auVar45 = sha256rnds2_sha(auVar45,auVar49,auVar11);
      auVar12._4_4_ = auVar11._12_4_;
      auVar12._0_4_ = auVar11._8_4_;
      auVar12._8_4_ = auVar11._0_4_;
      auVar12._12_4_ = auVar11._0_4_;
      auVar49 = sha256rnds2_sha(auVar49,auVar45,auVar12);
      auVar28 = sha256msg1_sha(auVar28,auVar44);
      auVar41._0_4_ = auVar48._4_4_ + auVar28._0_4_;
      auVar41._4_4_ = auVar48._8_4_ + auVar28._4_4_;
      auVar41._8_4_ = auVar48._12_4_ + auVar28._8_4_;
      auVar41._12_4_ = auVar40._0_4_ + auVar28._12_4_;
      auVar28 = sha256msg1_sha(auVar44,auVar48);
      auVar44 = sha256msg2_sha(auVar41,auVar40);
      auVar13._0_4_ = auVar44._0_4_ + 0x650a7354;
      auVar13._4_4_ = auVar44._4_4_ + 0x766a0abb;
      auVar13._8_4_ = auVar44._8_4_ + -0x7e3d36d2;
      auVar13._12_4_ = auVar44._12_4_ + -0x6d8dd37b;
      auVar42._0_4_ = auVar40._4_4_ + auVar28._0_4_;
      auVar42._4_4_ = auVar40._8_4_ + auVar28._4_4_;
      auVar42._8_4_ = auVar40._12_4_ + auVar28._8_4_;
      auVar42._12_4_ = auVar44._0_4_ + auVar28._12_4_;
      auVar28 = sha256rnds2_sha(auVar45,auVar49,auVar13);
      auVar14._4_4_ = auVar13._12_4_;
      auVar14._0_4_ = auVar13._8_4_;
      auVar14._8_4_ = auVar13._0_4_;
      auVar14._12_4_ = auVar13._0_4_;
      auVar49 = sha256rnds2_sha(auVar49,auVar28,auVar14);
      auVar45 = sha256msg2_sha(auVar42,auVar44);
      auVar15._0_4_ = auVar45._0_4_ + -0x5d40175f;
      auVar15._4_4_ = auVar45._4_4_ + -0x57e599b5;
      auVar15._8_4_ = auVar45._8_4_ + -0x3db47490;
      auVar15._12_4_ = auVar45._12_4_ + -0x3893ae5d;
      auVar46 = sha256rnds2_sha(auVar28,auVar49,auVar15);
      auVar16._4_4_ = auVar15._12_4_;
      auVar16._0_4_ = auVar15._8_4_;
      auVar16._8_4_ = auVar15._0_4_;
      auVar16._12_4_ = auVar15._0_4_;
      auVar50 = sha256rnds2_sha(auVar49,auVar46,auVar16);
      auVar28 = sha256msg1_sha(auVar48,auVar40);
      auVar43._0_4_ = auVar44._4_4_ + auVar28._0_4_;
      auVar43._4_4_ = auVar44._8_4_ + auVar28._4_4_;
      auVar43._8_4_ = auVar44._12_4_ + auVar28._8_4_;
      auVar43._12_4_ = auVar45._0_4_ + auVar28._12_4_;
      auVar49 = sha256msg2_sha(auVar43,auVar45);
      auVar17._0_4_ = auVar49._0_4_ + -0x2e6d17e7;
      auVar17._4_4_ = auVar49._4_4_ + -0x2966f9dc;
      auVar17._8_4_ = auVar49._8_4_ + -0xbf1ca7b;
      auVar17._12_4_ = auVar49._12_4_ + 0x106aa070;
      auVar46 = sha256rnds2_sha(auVar46,auVar50,auVar17);
      auVar18._4_4_ = auVar17._12_4_;
      auVar18._0_4_ = auVar17._8_4_;
      auVar18._8_4_ = auVar17._0_4_;
      auVar18._12_4_ = auVar17._0_4_;
      auVar50 = sha256rnds2_sha(auVar50,auVar46,auVar18);
      auVar28 = sha256msg1_sha(auVar40,auVar44);
      auVar36._0_4_ = auVar45._4_4_ + auVar28._0_4_;
      auVar36._4_4_ = auVar45._8_4_ + auVar28._4_4_;
      auVar36._8_4_ = auVar45._12_4_ + auVar28._8_4_;
      auVar36._12_4_ = auVar49._0_4_ + auVar28._12_4_;
      auVar48 = sha256msg2_sha(auVar36,auVar49);
      auVar19._0_4_ = auVar48._0_4_ + 0x19a4c116;
      auVar19._4_4_ = auVar48._4_4_ + 0x1e376c08;
      auVar19._8_4_ = auVar48._8_4_ + 0x2748774c;
      auVar19._12_4_ = auVar48._12_4_ + 0x34b0bcb5;
      auVar40 = sha256rnds2_sha(auVar46,auVar50,auVar19);
      auVar20._4_4_ = auVar19._12_4_;
      auVar20._0_4_ = auVar19._8_4_;
      auVar20._8_4_ = auVar19._0_4_;
      auVar20._12_4_ = auVar19._0_4_;
      auVar46 = sha256rnds2_sha(auVar50,auVar40,auVar20);
      auVar28 = sha256msg1_sha(auVar44,auVar45);
      auVar33._0_4_ = auVar49._4_4_ + auVar28._0_4_;
      auVar33._4_4_ = auVar49._8_4_ + auVar28._4_4_;
      auVar33._8_4_ = auVar49._12_4_ + auVar28._8_4_;
      auVar33._12_4_ = auVar48._0_4_ + auVar28._12_4_;
      auVar44 = sha256msg2_sha(auVar33,auVar48);
      auVar21._0_4_ = auVar44._0_4_ + 0x391c0cb3;
      auVar21._4_4_ = auVar44._4_4_ + 0x4ed8aa4a;
      auVar21._8_4_ = auVar44._8_4_ + 0x5b9cca4f;
      auVar21._12_4_ = auVar44._12_4_ + 0x682e6ff3;
      auVar40 = sha256rnds2_sha(auVar40,auVar46,auVar21);
      auVar22._4_4_ = auVar21._12_4_;
      auVar22._0_4_ = auVar21._8_4_;
      auVar22._8_4_ = auVar21._0_4_;
      auVar22._12_4_ = auVar21._0_4_;
      auVar46 = sha256rnds2_sha(auVar46,auVar40,auVar22);
      auVar28 = sha256msg1_sha(auVar45,auVar49);
      auVar30._0_4_ = auVar48._4_4_ + auVar28._0_4_;
      auVar30._4_4_ = auVar48._8_4_ + auVar28._4_4_;
      auVar30._8_4_ = auVar48._12_4_ + auVar28._8_4_;
      auVar30._12_4_ = auVar44._0_4_ + auVar28._12_4_;
      auVar28 = sha256msg2_sha(auVar30,auVar44);
      auVar23._0_4_ = auVar28._0_4_ + 0x748f82ee;
      auVar23._4_4_ = auVar28._4_4_ + 0x78a5636f;
      auVar23._8_4_ = auVar28._8_4_ + -0x7b3787ec;
      auVar23._12_4_ = auVar28._12_4_ + -0x7338fdf8;
      auVar40 = sha256rnds2_sha(auVar40,auVar46,auVar23);
      auVar24._4_4_ = auVar23._12_4_;
      auVar24._0_4_ = auVar23._8_4_;
      auVar24._8_4_ = auVar23._0_4_;
      auVar24._12_4_ = auVar23._0_4_;
      auVar45 = sha256rnds2_sha(auVar46,auVar40,auVar24);
      auVar48 = sha256msg1_sha(auVar49,auVar48);
      auVar25._0_4_ = auVar44._4_4_ + auVar48._0_4_;
      auVar25._4_4_ = auVar44._8_4_ + auVar48._4_4_;
      auVar25._8_4_ = auVar44._12_4_ + auVar48._8_4_;
      auVar25._12_4_ = auVar28._0_4_ + auVar48._12_4_;
      auVar28 = sha256msg2_sha(auVar25,auVar28);
      auVar26._0_4_ = auVar28._0_4_ + -0x6f410006;
      auVar26._4_4_ = auVar28._4_4_ + -0x5baf9315;
      auVar26._8_4_ = auVar28._8_4_ + -0x41065c09;
      auVar26._12_4_ = auVar28._12_4_ + -0x398e870e;
      auVar28 = sha256rnds2_sha(auVar40,auVar45,auVar26);
      auVar27._4_4_ = auVar26._12_4_;
      auVar27._0_4_ = auVar26._8_4_;
      auVar27._8_4_ = auVar26._0_4_;
      auVar27._12_4_ = auVar26._0_4_;
      iVar51 = iVar51 + auVar28._0_4_;
      iVar52 = iVar52 + auVar28._4_4_;
      iVar53 = iVar53 + auVar28._8_4_;
      iVar54 = iVar54 + auVar28._12_4_;
      auVar44 = sha256rnds2_sha(auVar45,auVar28,auVar27);
      auVar28._0_4_ = auVar44._0_4_ + auVar47._0_4_;
      auVar28._4_4_ = auVar44._4_4_ + auVar47._4_4_;
      auVar28._8_4_ = auVar44._8_4_ + auVar47._8_4_;
      auVar28._12_4_ = auVar44._12_4_ + auVar47._12_4_;
      uVar3 = uVar3 - 1;
      auVar47 = auVar28;
    } while (uVar3 != 0);
  }
  *param_1 = auVar28._12_4_;
  param_1[1] = auVar28._8_4_;
  param_1[2] = iVar54;
  param_1[3] = iVar53;
  param_1[4] = auVar28._4_4_;
  param_1[5] = auVar28._0_4_;
  param_1[6] = iVar52;
  param_1[7] = iVar51;
  *param_4 = param_3;
  return;
}



===== SymCryptHmacSha256Append @ 180004580 =====

void SymCryptHmacSha256Append(uint *param_1,undefined1 (*param_2) [16],ulonglong param_3)

{
  SymCryptSha256Append(param_1,param_2,param_3);
  return;
}



===== SymCryptSha256Append @ 1800045a0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptSha256Append(uint *param_1,undefined1 (*param_2) [16],ulonglong param_3)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong _Size;
  undefined1 auStack_58 [32];
  ulonglong local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_58;
  uVar1 = *param_1;
  uVar2 = (ulonglong)uVar1;
  *(ulonglong *)(param_1 + 4) = *(longlong *)(param_1 + 4) + param_3;
  local_38 = 0;
  if ((uVar1 != 0) && (_Size = (ulonglong)(0x40 - uVar1), _Size <= param_3)) {
    memmove((void *)(uVar2 + 0x20 + (longlong)param_1),param_2,_Size);
    param_2 = (undefined1 (*) [16])(*param_2 + _Size);
    param_3 = param_3 - _Size;
    SymCryptSha256AppendBlocks(param_1 + 0x18,(undefined1 (*) [16])(param_1 + 8),0x40,&local_38);
    uVar2 = 0;
  }
  uVar1 = (uint)uVar2;
  if (0x3f < param_3) {
    SymCryptSha256AppendBlocks(param_1 + 0x18,param_2,param_3,&local_38);
    param_2 = (undefined1 (*) [16])((longlong)param_2 + (param_3 - local_38));
    param_3 = local_38;
  }
  if (param_3 != 0) {
    memmove((void *)(uVar2 + 0x20 + (longlong)param_1),param_2,param_3);
    uVar1 = uVar1 + (int)param_3;
  }
  *param_1 = uVar1;
  return;
}



===== SymCryptHmacSha256Init @ 180004680 =====

void SymCryptHmacSha256Init(undefined4 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *(undefined8 *)(param_1 + 0x18) = *param_2;
  *(undefined8 *)(param_1 + 0x1a) = uVar1;
  uVar1 = param_2[3];
  *(undefined8 *)(param_1 + 0x1c) = param_2[2];
  *(undefined8 *)(param_1 + 0x1e) = uVar1;
  *(undefined8 *)(param_1 + 4) = 0x40;
  *param_1 = 0;
  *(undefined8 **)(param_1 + 0x20) = param_2;
  return;
}



===== SymCryptHmacSha1ExpandKey @ 1800046b0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 SymCryptHmacSha1ExpandKey(uint *param_1,void *param_2,ulonglong param_3)

{
  undefined1 auStack_128 [32];
  ulonglong local_108 [2];
  uint local_f8 [24];
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  ulonglong local_78;
  ulonglong uStack_70;
  ulonglong local_68;
  ulonglong uStack_60;
  ulonglong local_58;
  ulonglong uStack_50;
  ulonglong local_48;
  ulonglong uStack_40;
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStack_128;
  local_f8[1] = 0;
  memset(local_f8,0,0x7c);
  local_108[0] = 0;
  SymCryptSha1Init(local_f8);
  memset(&local_78,0,0x40);
  if (param_3 < 0x41) {
    if (param_3 != 0) {
      memmove(&local_78,param_2,param_3);
    }
  }
  else {
    SymCryptSha1Append(local_f8,param_2,param_3);
    SymCryptSha1Result(local_f8,&local_78);
  }
  local_78 = local_78 ^ 0x3636363636363636;
  uStack_70 = uStack_70 ^ 0x3636363636363636;
  local_68 = local_68 ^ 0x3636363636363636;
  uStack_60 = uStack_60 ^ 0x3636363636363636;
  local_58 = local_58 ^ 0x3636363636363636;
  uStack_50 = uStack_50 ^ 0x3636363636363636;
  *(undefined8 *)param_1 = local_98;
  *(undefined8 *)(param_1 + 2) = uStack_90;
  *(undefined8 *)(param_1 + 8) = local_98;
  *(undefined8 *)(param_1 + 10) = uStack_90;
  *(undefined8 *)(param_1 + 4) = local_88;
  *(undefined8 *)(param_1 + 6) = uStack_80;
  *(undefined8 *)(param_1 + 0xc) = local_88;
  *(undefined8 *)(param_1 + 0xe) = uStack_80;
  local_48 = local_48 ^ 0x3636363636363636;
  uStack_40 = uStack_40 ^ 0x3636363636363636;
  SymCryptSha1AppendBlocks(param_1,(longlong)&local_78,0x40,local_108);
  local_78 = local_78 ^ 0x6a6a6a6a6a6a6a6a;
  uStack_70 = uStack_70 ^ 0x6a6a6a6a6a6a6a6a;
  local_68 = local_68 ^ 0x6a6a6a6a6a6a6a6a;
  uStack_60 = uStack_60 ^ 0x6a6a6a6a6a6a6a6a;
  local_58 = local_58 ^ 0x6a6a6a6a6a6a6a6a;
  uStack_50 = uStack_50 ^ 0x6a6a6a6a6a6a6a6a;
  local_48 = local_48 ^ 0x6a6a6a6a6a6a6a6a;
  uStack_40 = uStack_40 ^ 0x6a6a6a6a6a6a6a6a;
  SymCryptSha1AppendBlocks(param_1 + 8,(longlong)&local_78,0x40,local_108);
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  SymCryptWipeAsm((undefined8 *)local_f8,0x80);
  return 0;
}



===== SymCryptSha1AppendBlocks @ 180004860 =====

void SymCryptSha1AppendBlocks(uint *param_1,longlong param_2,ulonglong param_3,ulonglong *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint *local_98;
  ulonglong local_90;
  
  local_b8 = *param_1;
  local_b4 = param_1[1];
  local_b0 = param_1[2];
  local_ac = param_1[3];
  local_a8 = param_1[4];
  if (0x3f < param_3) {
    local_90 = param_3 >> 6;
    param_3 = param_3 + local_90 * -0x40;
    local_98 = (uint *)(param_2 + 8);
    do {
      uVar3 = local_98[-2];
      uVar16 = local_98[-1];
      uVar2 = local_98[2];
      uVar5 = local_b4 >> 2 | local_b4 << 0x1e;
      uVar12 = uVar16 >> 0x18 | (uVar16 & 0xff0000) >> 8 | (uVar16 & 0xff00) << 8 | uVar16 << 0x18;
      uVar1 = local_b8 >> 2 | local_b8 << 0x1e;
      uVar4 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      uVar10 = ((local_ac ^ local_b0) & local_b4 ^ local_ac) +
               (local_b8 << 5 | local_b8 >> 0x1b) + uVar4 + local_a8 + 0x5a827999;
      uVar3 = local_98[1];
      uVar11 = uVar10 >> 2 | uVar10 * 0x40000000;
      uVar13 = uVar12 + (uVar10 * 0x20 | uVar10 >> 0x1b) +
               ((local_b0 ^ uVar5) & local_b8 ^ local_b0) + local_ac + 0x5a827999;
      uVar16 = *local_98;
      uVar26 = uVar16 >> 0x18 | (uVar16 & 0xff0000) >> 8 | (uVar16 & 0xff00) << 8 | uVar16 << 0x18;
      uVar16 = ((uVar5 ^ uVar1) & uVar10 ^ uVar5) + (uVar13 * 0x20 | uVar13 >> 0x1b) + uVar26 +
               local_b0 + 0x5a827999;
      uVar10 = uVar13 >> 2 | uVar13 * 0x40000000;
      uVar17 = uVar16 >> 2 | uVar16 * 0x40000000;
      uVar22 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      uVar5 = ((uVar11 ^ uVar1) & uVar13 ^ uVar1) +
              (uVar16 * 0x20 | uVar16 >> 0x1b) + 0x5a827999 + uVar22 + uVar5;
      uVar3 = local_98[3];
      uVar13 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      uVar23 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      uVar1 = uVar1 + ((uVar11 ^ uVar10) & uVar16 ^ uVar11) +
                      (uVar5 * 0x20 | uVar5 >> 0x1b) + 0x5a827999 + uVar23;
      uVar3 = local_98[4];
      uVar11 = uVar11 + ((uVar10 ^ uVar17) & uVar5 ^ uVar10) +
                        (uVar1 * 0x20 | uVar1 >> 0x1b) + uVar13 + 0x5a827999;
      uVar19 = uVar5 >> 2 | uVar5 * 0x40000000;
      uVar16 = local_98[6];
      uVar2 = uVar1 >> 2 | uVar1 * 0x40000000;
      uVar6 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      uVar3 = local_98[5];
      uVar10 = uVar10 + ((uVar17 ^ uVar19) & uVar1 ^ uVar17) +
                        (uVar11 * 0x20 | uVar11 >> 0x1b) + 0x5a827999 + uVar6;
      uVar1 = uVar11 >> 2 | uVar11 * 0x40000000;
      uVar7 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      uVar3 = local_98[7];
      uVar17 = uVar17 + ((uVar19 ^ uVar2) & uVar11 ^ uVar19) +
                        (uVar10 * 0x20 | uVar10 >> 0x1b) + 0x5a827999 + uVar7;
      uVar14 = uVar10 >> 2 | uVar10 * 0x40000000;
      uVar11 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      uVar5 = uVar16 >> 0x18 | (uVar16 & 0xff0000) >> 8 | (uVar16 & 0xff00) << 8 | uVar16 << 0x18;
      uVar19 = uVar19 + ((uVar1 ^ uVar2) & uVar10 ^ uVar2) +
                        (uVar17 * 0x20 | uVar17 >> 0x1b) + 0x5a827999 + uVar5;
      uVar18 = uVar17 >> 2 | uVar17 * 0x40000000;
      uVar3 = local_98[8];
      uVar2 = uVar2 + ((uVar1 ^ uVar14) & uVar17 ^ uVar1) +
                      (uVar19 * 0x20 | uVar19 >> 0x1b) + uVar11 + 0x5a827999;
      uVar20 = uVar19 >> 2 | uVar19 * 0x40000000;
      uVar17 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      uVar3 = local_98[9];
      uVar1 = uVar1 + ((uVar14 ^ uVar18) & uVar19 ^ uVar14) +
                      (uVar2 * 0x20 | uVar2 >> 0x1b) + uVar17 + 0x5a827999;
      uVar19 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      uVar3 = local_98[10];
      uVar14 = uVar14 + ((uVar18 ^ uVar20) & uVar2 ^ uVar18) +
                        (uVar1 * 0x20 | uVar1 >> 0x1b) + 0x5a827999 + uVar19;
      uVar8 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      uVar16 = uVar2 >> 2 | uVar2 * 0x40000000;
      uVar3 = local_98[0xb];
      uVar10 = uVar1 >> 2 | uVar1 * 0x40000000;
      uVar18 = uVar18 + ((uVar20 ^ uVar16) & uVar1 ^ uVar20) +
                        (uVar14 * 0x20 | uVar14 >> 0x1b) + 0x5a827999 + uVar8;
      uVar15 = uVar14 >> 2 | uVar14 * 0x40000000;
      uVar9 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      uVar3 = local_98[0xc];
      uVar20 = uVar20 + ((uVar10 ^ uVar16) & uVar14 ^ uVar16) +
                        (uVar18 * 0x20 | uVar18 >> 0x1b) + 0x5a827999 + uVar9;
      uVar2 = uVar18 >> 2 | uVar18 * 0x40000000;
      uVar14 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      uVar16 = uVar14 + (uVar20 * 0x20 | uVar20 >> 0x1b) + ((uVar10 ^ uVar15) & uVar18 ^ uVar10) +
               uVar16 + 0x5a827999;
      uVar3 = local_98[0xd];
      uVar21 = uVar20 >> 2 | uVar20 * 0x40000000;
      uVar4 = uVar26 ^ uVar9 ^ uVar5 ^ uVar4;
      uVar18 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      uVar4 = uVar12 ^ uVar11 ^ uVar14 ^ uVar22;
      uVar1 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      uVar10 = uVar10 + 0x5a827999 +
               ((uVar15 ^ uVar2) & uVar20 ^ uVar15) + (uVar16 * 0x20 | uVar16 >> 0x1b) + uVar1;
      uVar12 = uVar16 >> 2 | uVar16 * 0x40000000;
      uVar3 = uVar15 + 0x5a827999 +
              ((uVar2 ^ uVar21) & uVar16 ^ uVar2) + (uVar10 * 0x20 | uVar10 >> 0x1b) + uVar18;
      uVar20 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      uVar24 = uVar10 >> 2 | uVar10 * 0x40000000;
      uVar2 = ((uVar21 ^ uVar12) & uVar10 ^ uVar21) +
              (uVar3 * 0x20 | uVar3 >> 0x1b) + 0x5a827999 + uVar20 + uVar2;
      uVar16 = uVar3 >> 2 | uVar3 * 0x40000000;
      uVar4 = uVar23 ^ uVar26 ^ uVar1 ^ uVar17;
      uVar15 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      uVar3 = uVar21 + 0x5a827999 +
              ((uVar24 ^ uVar12) & uVar3 ^ uVar12) + (uVar2 * 0x20 | uVar2 >> 0x1b) + uVar15;
      uVar22 = uVar19 ^ uVar18 ^ uVar13 ^ uVar22;
      uVar22 = uVar22 << 1 | (uint)((int)uVar22 < 0);
      uVar10 = uVar2 >> 2 | uVar2 * 0x40000000;
      uVar23 = uVar20 ^ uVar6 ^ uVar8 ^ uVar23;
      uVar21 = uVar23 << 1 | (uint)((int)uVar23 < 0);
      uVar12 = uVar22 + (uVar3 * 0x20 | uVar3 >> 0x1b) +
               ((uVar24 ^ uVar16) & uVar2 ^ uVar24) + 0x5a827999 + uVar12;
      uVar4 = uVar3 >> 2 | uVar3 * 0x40000000;
      uVar2 = uVar24 + 0x6ed9eba1 +
              (uVar16 ^ uVar10 ^ uVar3) + (uVar12 * 0x20 | uVar12 >> 0x1b) + uVar21;
      uVar3 = uVar15 ^ uVar7 ^ uVar13 ^ uVar9;
      uVar26 = uVar3 << 1 | (uint)((int)uVar3 < 0);
      uVar23 = uVar12 >> 2 | uVar12 * 0x40000000;
      uVar13 = uVar16 + 0x6ed9eba1 +
               (uVar10 ^ uVar4 ^ uVar12) + (uVar2 * 0x20 | uVar2 >> 0x1b) + uVar26;
      uVar3 = uVar22 ^ uVar6 ^ uVar14 ^ uVar5;
      uVar3 = uVar3 << 1 | (uint)((int)uVar3 < 0);
      uVar6 = uVar2 >> 2 | uVar2 * 0x40000000;
      uVar12 = uVar10 + 0x6ed9eba1 +
               (uVar2 ^ uVar4 ^ uVar23) + (uVar13 * 0x20 | uVar13 >> 0x1b) + uVar3;
      uVar16 = uVar21 ^ uVar7 ^ uVar11 ^ uVar1;
      uVar10 = uVar13 >> 2 | uVar13 * 0x40000000;
      uVar16 = uVar16 << 1 | (uint)((int)uVar16 < 0);
      uVar4 = uVar4 + (uVar6 ^ uVar13 ^ uVar23) +
                      (uVar12 * 0x20 | uVar12 >> 0x1b) + uVar16 + 0x6ed9eba1;
      uVar2 = uVar18 ^ uVar26 ^ uVar5 ^ uVar17;
      uVar2 = uVar2 << 1 | (uint)((int)uVar2 < 0);
      uVar7 = uVar12 >> 2 | uVar12 * 0x40000000;
      uVar23 = uVar23 + (uVar6 ^ uVar10 ^ uVar12) +
                        (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar2 + 0x6ed9eba1;
      uVar5 = uVar19 ^ uVar20 ^ uVar11 ^ uVar3;
      uVar25 = uVar5 << 1 | (uint)((int)uVar5 < 0);
      uVar5 = uVar4 >> 2 | uVar4 * 0x40000000;
      uVar6 = uVar6 + (uVar10 ^ uVar7 ^ uVar4) +
                      (uVar23 * 0x20 | uVar23 >> 0x1b) + uVar25 + 0x6ed9eba1;
      uVar17 = uVar15 ^ uVar8 ^ uVar16 ^ uVar17;
      uVar13 = uVar17 << 1 | (uint)((int)uVar17 < 0);
      uVar10 = uVar10 + (uVar7 ^ uVar5 ^ uVar23) +
                        (uVar6 * 0x20 | uVar6 >> 0x1b) + 0x6ed9eba1 + uVar13;
      uVar4 = uVar19 ^ uVar22 ^ uVar2 ^ uVar9;
      uVar27 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      uVar4 = uVar23 >> 2 | uVar23 * 0x40000000;
      uVar11 = uVar6 >> 2 | uVar6 * 0x40000000;
      uVar7 = uVar7 + (uVar6 ^ uVar5 ^ uVar4) +
                      (uVar10 * 0x20 | uVar10 >> 0x1b) + uVar27 + 0x6ed9eba1;
      uVar17 = uVar21 ^ uVar8 ^ uVar14 ^ uVar25;
      uVar6 = uVar18 ^ uVar3 ^ uVar14 ^ uVar27;
      uVar28 = uVar17 << 1 | (uint)((int)uVar17 < 0);
      uVar24 = uVar6 << 1 | (uint)((int)uVar6 < 0);
      uVar17 = uVar10 >> 2 | uVar10 * 0x40000000;
      uVar5 = uVar5 + (uVar11 ^ uVar10 ^ uVar4) +
                      (uVar7 * 0x20 | uVar7 >> 0x1b) + 0x6ed9eba1 + uVar28;
      uVar10 = uVar26 ^ uVar9 ^ uVar13 ^ uVar1;
      uVar23 = uVar10 << 1 | (uint)((int)uVar10 < 0);
      uVar9 = uVar7 >> 2 | uVar7 * 0x40000000;
      uVar4 = uVar4 + (uVar11 ^ uVar17 ^ uVar7) +
                      (uVar5 * 0x20 | uVar5 >> 0x1b) + 0x6ed9eba1 + uVar23;
      uVar1 = uVar20 ^ uVar16 ^ uVar28 ^ uVar1;
      uVar10 = uVar1 << 1 | (uint)((int)uVar1 < 0);
      uVar1 = uVar5 >> 2 | uVar5 * 0x40000000;
      uVar11 = uVar11 + (uVar17 ^ uVar9 ^ uVar5) +
                        (uVar4 * 0x20 | uVar4 >> 0x1b) + 0x6ed9eba1 + uVar24;
      uVar17 = uVar17 + (uVar9 ^ uVar1 ^ uVar4) +
                        (uVar11 * 0x20 | uVar11 >> 0x1b) + 0x6ed9eba1 + uVar10;
      uVar5 = uVar4 >> 2 | uVar4 * 0x40000000;
      uVar4 = uVar18 ^ uVar15 ^ uVar2 ^ uVar23;
      uVar6 = uVar11 >> 2 | uVar11 * 0x40000000;
      uVar7 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      uVar9 = uVar9 + (uVar11 ^ uVar1 ^ uVar5) +
                      (uVar17 * 0x20 | uVar17 >> 0x1b) + uVar7 + 0x6ed9eba1;
      uVar4 = uVar22 ^ uVar20 ^ uVar25 ^ uVar24;
      uVar11 = uVar22 ^ uVar26 ^ uVar27 ^ uVar7;
      uVar19 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      uVar14 = uVar17 >> 2 | uVar17 * 0x40000000;
      uVar22 = uVar11 << 1 | (uint)((int)uVar11 < 0);
      uVar1 = uVar1 + (uVar6 ^ uVar17 ^ uVar5) +
                      (uVar9 * 0x20 | uVar9 >> 0x1b) + uVar19 + 0x6ed9eba1;
      uVar4 = uVar21 ^ uVar15 ^ uVar10 ^ uVar13;
      uVar11 = uVar21 ^ uVar3 ^ uVar28 ^ uVar19;
      uVar8 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      uVar20 = uVar11 << 1 | (uint)((int)uVar11 < 0);
      uVar18 = uVar9 >> 2 | uVar9 * 0x40000000;
      uVar5 = uVar5 + (uVar6 ^ uVar14 ^ uVar9) + (uVar1 * 0x20 | uVar1 >> 0x1b) + 0x6ed9eba1 + uVar8
      ;
      uVar4 = uVar1 >> 2 | uVar1 * 0x40000000;
      uVar6 = uVar6 + (uVar14 ^ uVar18 ^ uVar1) +
                      (uVar5 * 0x20 | uVar5 >> 0x1b) + 0x6ed9eba1 + uVar22;
      uVar14 = uVar14 + (uVar18 ^ uVar4 ^ uVar5) +
                        (uVar6 * 0x20 | uVar6 >> 0x1b) + 0x6ed9eba1 + uVar20;
      uVar5 = uVar5 >> 2 | uVar5 * 0x40000000;
      uVar1 = uVar16 ^ uVar25 ^ uVar10 ^ uVar20;
      uVar17 = uVar6 >> 2 | uVar6 * 0x40000000;
      uVar16 = uVar26 ^ uVar16 ^ uVar23 ^ uVar8;
      uVar9 = uVar1 << 1 | (uint)((int)uVar1 < 0);
      uVar26 = uVar16 << 1 | (uint)((int)uVar16 < 0);
      uVar3 = uVar3 ^ uVar2 ^ uVar24 ^ uVar22;
      uVar11 = uVar3 << 1 | (uint)((int)uVar3 < 0);
      uVar18 = uVar18 + (uVar6 ^ uVar4 ^ uVar5) +
                        (uVar14 * 0x20 | uVar14 >> 0x1b) + 0x6ed9eba1 + uVar26;
      uVar12 = uVar14 >> 2 | uVar14 * 0x40000000;
      uVar4 = uVar4 + (uVar17 ^ uVar14 ^ uVar5) +
                      (uVar18 * 0x20 | uVar18 >> 0x1b) + 0x6ed9eba1 + uVar11;
      uVar15 = uVar18 >> 2 | uVar18 * 0x40000000;
      uVar1 = uVar5 + 0x6ed9eba1 +
              (uVar17 ^ uVar12 ^ uVar18) + (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar9;
      uVar3 = uVar2 ^ uVar7 ^ uVar26 ^ uVar13;
      uVar3 = uVar3 << 1 | (uint)((int)uVar3 < 0);
      uVar5 = uVar4 >> 2 | uVar4 * 0x40000000;
      uVar6 = uVar17 + (uVar1 * 0x20 | uVar1 >> 0x1b) +
              ((uVar15 | uVar4) & uVar12 | uVar15 & uVar4) + 0x8f1bbcdc + uVar3;
      uVar16 = uVar25 ^ uVar27 ^ uVar19 ^ uVar11;
      uVar16 = uVar16 << 1 | (uint)((int)uVar16 < 0);
      uVar12 = uVar12 + (uVar6 * 0x20 | uVar6 >> 0x1b) +
               ((uVar5 | uVar1) & uVar15 | uVar5 & uVar1) + 0x8f1bbcdc + uVar16;
      uVar4 = uVar1 >> 2 | uVar1 * 0x40000000;
      uVar14 = uVar6 >> 2 | uVar6 * 0x40000000;
      uVar13 = uVar28 ^ uVar8 ^ uVar9 ^ uVar13;
      uVar17 = uVar13 << 1 | (uint)((int)uVar13 < 0);
      uVar2 = uVar27 ^ uVar23 ^ uVar22 ^ uVar3;
      uVar2 = uVar2 << 1 | (uint)((int)uVar2 < 0);
      uVar13 = uVar15 + (uVar12 * 0x20 | uVar12 >> 0x1b) +
               ((uVar6 | uVar4) & uVar5 | uVar6 & uVar4) + 0x8f1bbcdc + uVar17;
      uVar18 = uVar12 >> 2 | uVar12 * 0x40000000;
      uVar1 = uVar28 ^ uVar24 ^ uVar20 ^ uVar16;
      uVar5 = uVar5 + (uVar13 * 0x20 | uVar13 >> 0x1b) +
              ((uVar14 | uVar12) & uVar4 | uVar14 & uVar12) + 0x8f1bbcdc + uVar2;
      uVar1 = uVar1 << 1 | (uint)((int)uVar1 < 0);
      uVar15 = uVar13 >> 2 | uVar13 * 0x40000000;
      uVar13 = uVar4 + (uVar5 * 0x20 | uVar5 >> 0x1b) +
               ((uVar18 | uVar13) & uVar14 | uVar18 & uVar13) + 0x8f1bbcdc + uVar1;
      uVar4 = uVar23 ^ uVar10 ^ uVar17 ^ uVar26;
      uVar4 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      uVar12 = uVar14 + (uVar13 * 0x20 | uVar13 >> 0x1b) +
               ((uVar15 | uVar5) & uVar18 | uVar15 & uVar5) + 0x8f1bbcdc + uVar4;
      uVar6 = uVar5 >> 2 | uVar5 * 0x40000000;
      uVar5 = uVar24 ^ uVar7 ^ uVar11 ^ uVar2;
      uVar5 = uVar5 << 1 | (uint)((int)uVar5 < 0);
      uVar23 = uVar19 ^ uVar22 ^ uVar16 ^ uVar5;
      uVar14 = uVar13 >> 2 | uVar13 * 0x40000000;
      uVar10 = uVar10 ^ uVar19 ^ uVar9 ^ uVar1;
      uVar10 = uVar10 << 1 | (uint)((int)uVar10 < 0);
      uVar24 = uVar17 ^ uVar8 ^ uVar20 ^ uVar10;
      uVar21 = uVar23 << 1 | (uint)((int)uVar23 < 0);
      uVar19 = uVar18 + (uVar12 * 0x20 | uVar12 >> 0x1b) +
               ((uVar6 | uVar13) & uVar15 | uVar6 & uVar13) + 0x8f1bbcdc + uVar5;
      uVar25 = uVar24 << 1 | (uint)((int)uVar24 < 0);
      uVar18 = uVar12 >> 2 | uVar12 * 0x40000000;
      uVar13 = uVar7 ^ uVar8 ^ uVar3 ^ uVar4;
      uVar13 = uVar13 << 1 | (uint)((int)uVar13 < 0);
      uVar7 = uVar15 + (uVar19 * 0x20 | uVar19 >> 0x1b) +
              ((uVar12 | uVar14) & uVar6 | uVar12 & uVar14) + 0x8f1bbcdc + uVar10;
      uVar12 = uVar19 >> 2 | uVar19 * 0x40000000;
      uVar6 = uVar6 + (uVar7 * 0x20 | uVar7 >> 0x1b) +
              ((uVar18 | uVar19) & uVar14 | uVar18 & uVar19) + 0x8f1bbcdc + uVar13;
      uVar15 = uVar7 >> 2 | uVar7 * 0x40000000;
      uVar8 = uVar14 + (uVar6 * 0x20 | uVar6 >> 0x1b) +
              ((uVar12 | uVar7) & uVar18 | uVar12 & uVar7) + uVar21 + 0x8f1bbcdc;
      uVar19 = uVar13 ^ uVar22 ^ uVar26 ^ uVar2;
      uVar7 = uVar21 ^ uVar20 ^ uVar11 ^ uVar1;
      uVar14 = uVar25 ^ uVar26 ^ uVar9 ^ uVar4;
      uVar22 = uVar19 << 1 | (uint)((int)uVar19 < 0);
      uVar19 = uVar7 << 1 | (uint)((int)uVar7 < 0);
      uVar23 = uVar14 << 1 | (uint)((int)uVar14 < 0);
      uVar7 = uVar6 >> 2 | uVar6 * 0x40000000;
      uVar6 = (uVar8 * 0x20 | uVar8 >> 0x1b) + uVar18 +
              ((uVar15 | uVar6) & uVar12 | uVar15 & uVar6) + 0x8f1bbcdc + uVar25;
      uVar14 = uVar8 >> 2 | uVar8 * 0x40000000;
      uVar12 = uVar12 + (uVar6 * 0x20 | uVar6 >> 0x1b) +
               ((uVar7 | uVar8) & uVar15 | uVar7 & uVar8) + 0x8f1bbcdc + uVar22;
      uVar8 = uVar6 >> 2 | uVar6 * 0x40000000;
      uVar15 = uVar15 + (uVar12 * 0x20 | uVar12 >> 0x1b) +
               ((uVar6 | uVar14) & uVar7 | uVar6 & uVar14) + 0x8f1bbcdc + uVar19;
      uVar18 = uVar12 >> 2 | uVar12 * 0x40000000;
      uVar6 = uVar7 + (uVar15 * 0x20 | uVar15 >> 0x1b) +
              ((uVar8 | uVar12) & uVar14 | uVar8 & uVar12) + 0x8f1bbcdc + uVar23;
      uVar7 = uVar22 ^ uVar11 ^ uVar3 ^ uVar5;
      uVar26 = uVar7 << 1 | (uint)((int)uVar7 < 0);
      uVar7 = uVar19 ^ uVar9 ^ uVar16 ^ uVar10;
      uVar12 = uVar15 >> 2 | uVar15 * 0x40000000;
      uVar11 = uVar7 << 1 | (uint)((int)uVar7 < 0);
      uVar9 = (uVar6 * 0x20 | uVar6 >> 0x1b) + uVar14 +
              ((uVar18 | uVar15) & uVar8 | uVar18 & uVar15) + 0x8f1bbcdc + uVar26;
      uVar7 = uVar6 >> 2 | uVar6 * 0x40000000;
      uVar6 = (uVar9 * 0x20 | uVar9 >> 0x1b) + uVar8 +
              ((uVar12 | uVar6) & uVar18 | uVar12 & uVar6) + 0x8f1bbcdc + uVar11;
      uVar14 = uVar9 >> 2 | uVar9 * 0x40000000;
      uVar16 = uVar26 ^ uVar21 ^ uVar16 ^ uVar2;
      uVar3 = uVar23 ^ uVar13 ^ uVar17 ^ uVar3;
      uVar16 = uVar16 << 1 | (uint)((int)uVar16 < 0);
      uVar20 = uVar3 << 1 | (uint)((int)uVar3 < 0);
      uVar9 = uVar18 + (uVar6 * 0x20 | uVar6 >> 0x1b) +
              ((uVar7 | uVar9) & uVar12 | uVar7 & uVar9) + 0x8f1bbcdc + uVar20;
      uVar8 = uVar6 >> 2 | uVar6 * 0x40000000;
      uVar18 = uVar12 + (uVar9 * 0x20 | uVar9 >> 0x1b) +
               ((uVar6 | uVar14) & uVar7 | uVar6 & uVar14) + 0x8f1bbcdc + uVar16;
      uVar3 = uVar11 ^ uVar25 ^ uVar17 ^ uVar1;
      uVar3 = uVar3 << 1 | (uint)((int)uVar3 < 0);
      uVar6 = uVar7 + (uVar18 * 0x20 | uVar18 >> 0x1b) +
              ((uVar8 | uVar9) & uVar14 | uVar8 & uVar9) + 0x8f1bbcdc + uVar3;
      uVar12 = uVar9 >> 2 | uVar9 * 0x40000000;
      uVar2 = uVar20 ^ uVar22 ^ uVar2 ^ uVar4;
      uVar1 = uVar16 ^ uVar19 ^ uVar1 ^ uVar5;
      uVar7 = uVar2 << 1 | (uint)((int)uVar2 < 0);
      uVar15 = uVar18 >> 2 | uVar18 * 0x40000000;
      uVar5 = uVar26 ^ uVar7 ^ uVar13 ^ uVar5;
      uVar9 = uVar7 + (uVar6 * 0x20 | uVar6 >> 0x1b) +
              ((uVar12 | uVar18) & uVar8 | uVar12 & uVar18) + uVar14 + -0x70e44324;
      uVar2 = uVar6 >> 2 | uVar6 * 0x40000000;
      uVar24 = uVar1 << 1 | (uint)((int)uVar1 < 0);
      uVar1 = uVar3 ^ uVar23 ^ uVar4 ^ uVar10;
      uVar27 = uVar5 << 1 | (uint)((int)uVar5 < 0);
      uVar17 = uVar1 << 1 | (uint)((int)uVar1 < 0);
      uVar10 = uVar11 ^ uVar21 ^ uVar24 ^ uVar10;
      uVar10 = uVar10 << 1 | (uint)((int)uVar10 < 0);
      uVar1 = (uVar9 * 0x20 | uVar9 >> 0x1b) + uVar24 +
              (uVar12 ^ uVar15 ^ uVar6) + uVar8 + 0xca62c1d6;
      uVar5 = uVar9 >> 2 | uVar9 * 0x40000000;
      uVar6 = uVar17 + (uVar1 * 0x20 | uVar1 >> 0x1b) +
              (uVar15 ^ uVar2 ^ uVar9) + uVar12 + -0x359d3e2a;
      uVar9 = uVar1 >> 2 | uVar1 * 0x40000000;
      uVar14 = uVar27 + (uVar6 * 0x20 | uVar6 >> 0x1b) +
               (uVar1 ^ uVar2 ^ uVar5) + uVar15 + -0x359d3e2a;
      uVar4 = (uVar14 * 0x20 | uVar14 >> 0x1b) + uVar10 +
              (uVar9 ^ uVar6 ^ uVar5) + uVar2 + -0x359d3e2a;
      uVar1 = uVar20 ^ uVar25 ^ uVar13 ^ uVar17;
      uVar13 = uVar3 ^ uVar19 ^ uVar25 ^ uVar10;
      uVar2 = uVar16 ^ uVar22 ^ uVar21 ^ uVar27;
      uVar8 = uVar1 << 1 | (uint)((int)uVar1 < 0);
      uVar1 = uVar23 ^ uVar22 ^ uVar7 ^ uVar8;
      uVar12 = uVar6 >> 2 | uVar6 * 0x40000000;
      uVar6 = uVar2 << 1 | (uint)((int)uVar2 < 0);
      uVar15 = uVar14 >> 2 | uVar14 * 0x40000000;
      uVar2 = uVar13 << 1 | (uint)((int)uVar13 < 0);
      uVar1 = uVar1 << 1 | (uint)((int)uVar1 < 0);
      uVar14 = uVar8 + (uVar4 * 0x20 | uVar4 >> 0x1b) +
               (uVar9 ^ uVar12 ^ uVar14) + uVar5 + -0x359d3e2a;
      uVar5 = uVar4 >> 2 | uVar4 * 0x40000000;
      uVar13 = uVar6 + (uVar14 * 0x20 | uVar14 >> 0x1b) +
               (uVar12 ^ uVar15 ^ uVar4) + uVar9 + -0x359d3e2a;
      uVar4 = uVar26 ^ uVar19 ^ uVar24 ^ uVar6;
      uVar19 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      uVar18 = uVar14 >> 2 | uVar14 * 0x40000000;
      uVar4 = uVar2 + (uVar13 * 0x20 | uVar13 >> 0x1b) +
              (uVar15 ^ uVar5 ^ uVar14) + uVar12 + -0x359d3e2a;
      uVar12 = uVar13 >> 2 | uVar13 * 0x40000000;
      uVar22 = (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar1 +
               (uVar13 ^ uVar5 ^ uVar18) + uVar15 + -0x359d3e2a;
      uVar15 = uVar4 >> 2 | uVar4 * 0x40000000;
      uVar9 = uVar19 + (uVar22 * 0x20 | uVar22 >> 0x1b) +
              (uVar12 ^ uVar4 ^ uVar18) + 0xca62c1d6 + uVar5;
      uVar4 = uVar16 ^ uVar11 ^ uVar10 ^ uVar19;
      uVar13 = uVar11 ^ uVar23 ^ uVar17 ^ uVar2;
      uVar5 = uVar20 ^ uVar26 ^ uVar27 ^ uVar1;
      uVar23 = uVar22 >> 2 | uVar22 * 0x40000000;
      uVar21 = uVar13 << 1 | (uint)((int)uVar13 < 0);
      uVar14 = uVar5 << 1 | (uint)((int)uVar5 < 0);
      uVar13 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      uVar11 = uVar21 + (uVar9 * 0x20 | uVar9 >> 0x1b) +
               (uVar12 ^ uVar15 ^ uVar22) + uVar18 + -0x359d3e2a;
      uVar5 = (uVar11 * 0x20 | uVar11 >> 0x1b) + uVar14 +
              (uVar15 ^ uVar23 ^ uVar9) + uVar12 + 0xca62c1d6;
      uVar9 = uVar9 >> 2 | uVar9 * 0x40000000;
      uVar4 = uVar3 ^ uVar20 ^ uVar21 ^ uVar8;
      uVar12 = uVar4 << 1 | (uint)((int)uVar4 < 0);
      uVar4 = (uVar5 * 0x20 | uVar5 >> 0x1b) + uVar13 +
              (uVar23 ^ uVar9 ^ uVar11) + uVar15 + 0xca62c1d6;
      uVar16 = uVar16 ^ uVar7 ^ uVar6 ^ uVar14;
      uVar18 = uVar16 << 1 | (uint)((int)uVar16 < 0);
      uVar16 = uVar11 >> 2 | uVar11 * 0x40000000;
      uVar11 = uVar5 >> 2 | uVar5 * 0x40000000;
      uVar15 = uVar12 + (uVar4 * 0x20 | uVar4 >> 0x1b) +
               (uVar5 ^ uVar9 ^ uVar16) + uVar23 + -0x359d3e2a;
      uVar5 = uVar4 >> 2 | uVar4 * 0x40000000;
      uVar9 = uVar18 + (uVar15 * 0x20 | uVar15 >> 0x1b) +
              (uVar11 ^ uVar4 ^ uVar16) + 0xca62c1d6 + uVar9;
      uVar2 = uVar3 ^ uVar24 ^ uVar13 ^ uVar2;
      uVar3 = uVar2 << 1 | (uint)((int)uVar2 < 0);
      uVar22 = uVar15 >> 2 | uVar15 * 0x40000000;
      uVar4 = (uVar9 * 0x20 | uVar9 >> 0x1b) + uVar3 + -0x359d3e2a +
              (uVar11 ^ uVar5 ^ uVar15) + uVar16;
      uVar1 = uVar7 ^ uVar12 ^ uVar17 ^ uVar1;
      uVar16 = uVar1 << 1 | (uint)((int)uVar1 < 0);
      uVar19 = uVar18 ^ uVar24 ^ uVar27 ^ uVar19;
      uVar7 = uVar9 >> 2 | uVar9 * 0x40000000;
      uVar2 = (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar16 +
              (uVar5 ^ uVar22 ^ uVar9) + 0xca62c1d6 + uVar11;
      uVar1 = uVar19 << 1 | (uint)((int)uVar19 < 0);
      uVar14 = uVar27 ^ uVar16 ^ uVar8 ^ uVar14;
      uVar16 = uVar4 >> 2 | uVar4 * 0x40000000;
      uVar3 = uVar17 ^ uVar10 ^ uVar21 ^ uVar3;
      uVar5 = (uVar2 * 0x20 | uVar2 >> 0x1b) + 0xca62c1d6 + uVar1 + (uVar22 ^ uVar7 ^ uVar4) + uVar5
      ;
      uVar1 = uVar10 ^ uVar13 ^ uVar6 ^ uVar1;
      uVar4 = uVar2 >> 2 | uVar2 * 0x40000000;
      uVar2 = uVar22 + (uVar3 << 1 | (uint)((int)uVar3 < 0)) + (uVar5 * 0x20 | uVar5 >> 0x1b) +
              (uVar2 ^ uVar7 ^ uVar16) + 0xca62c1d6;
      uVar10 = uVar5 >> 2 | uVar5 * 0x40000000;
      uVar3 = (uVar14 << 1 | (uint)((int)uVar14 < 0)) + uVar7 + (uVar2 * 0x20 | uVar2 >> 0x1b) +
              (uVar4 ^ uVar5 ^ uVar16) + 0xca62c1d6;
      local_b4 = uVar3 + local_b4;
      local_ac = uVar10 + local_ac;
      local_a8 = uVar4 + local_a8;
      local_b8 = (uVar1 << 1 | (uint)((int)uVar1 < 0)) + 0xca62c1d6 + uVar16 +
                 (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar4 ^ uVar10 ^ uVar2) + local_b8;
      local_98 = local_98 + 0x10;
      local_b0 = (uVar2 >> 2 | uVar2 * 0x40000000) + local_b0;
      local_90 = local_90 - 1;
      *param_1 = local_b8;
      param_1[1] = local_b4;
      param_1[2] = local_b0;
      param_1[3] = local_ac;
      param_1[4] = local_a8;
    } while (local_90 != 0);
  }
  *param_4 = param_3;
  return;
}



===== SymCryptSha1Init @ 180005aa0 =====

void SymCryptSha1Init(undefined4 *param_1)

{
  *(undefined8 *)(param_1 + 4) = 0;
  *(undefined8 *)(param_1 + 6) = 0;
  *param_1 = 0;
  *(undefined8 *)(param_1 + 0x18) = 0xefcdab8967452301;
  *(undefined8 *)(param_1 + 0x1a) = 0x1032547698badcfe;
  param_1[0x1c] = 0xc3d2e1f0;
  return;
}



===== SymCryptSha1Result @ 180005ac8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptSha1Result(uint *param_1,ulonglong *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong *puVar6;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  ulonglong local_20;
  
  local_20 = __security_cookie ^ (ulonglong)auStack_48;
  local_28 = 0;
  uVar3 = *param_1;
  puVar6 = (ulonglong *)(param_1 + 0x18);
  *(undefined1 *)((ulonglong)uVar3 + 0x20 + (longlong)param_1) = 0x80;
  uVar3 = uVar3 + 1;
  uVar4 = (ulonglong)uVar3;
  if (0x38 < uVar3) {
    memset((void *)(uVar4 + 0x20 + (longlong)param_1),0,(ulonglong)(0x40 - uVar3));
    SymCryptSha1AppendBlocks((uint *)puVar6,(longlong)(param_1 + 8),0x40,&local_28);
    uVar4 = 0;
  }
  memset((void *)(uVar4 + 0x20 + (longlong)param_1),0,(ulonglong)(0x40 - (int)uVar4));
  uVar4 = *(ulonglong *)(param_1 + 4);
  uVar2 = uVar4 << 3;
  *(ulonglong *)(param_1 + 0x16) =
       (uVar4 & 0x1fffffffffffffff) >> 0x35 | (uVar2 & 0xff000000000000) >> 0x28 |
       (uVar2 & 0xff0000000000) >> 0x18 | (uVar2 & 0xff00000000) >> 8 | (uVar2 & 0xff000000) << 8 |
       (uVar2 & 0xff0000) << 0x18 | (uVar2 & 0xff00) << 0x28 | uVar4 << 0x3b;
  SymCryptSha1AppendBlocks((uint *)puVar6,(longlong)(param_1 + 8),0x40,&local_28);
  lVar5 = 2;
  do {
    uVar4 = *puVar6;
    puVar6 = puVar6 + 1;
    uVar2 = uVar4 << 0x20;
    uVar1 = uVar4 >> 0x20;
    *param_2 = (uVar4 & 0xffffffff) >> 0x18 | (uVar2 & 0xff000000000000) >> 0x28 |
               (uVar2 & 0xff0000000000) >> 0x18 | (uVar2 & 0xff00000000) >> 8 |
               (uVar1 & 0xff000000) << 8 | (uVar1 & 0xff0000) << 0x18 | (uVar1 & 0xff00) << 0x28 |
               uVar1 << 0x38;
    param_2 = param_2 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  uVar3 = (uint)*puVar6;
  *(uint *)param_2 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18
  ;
  SymCryptWipeAsm((undefined8 *)param_1,0x80);
  SymCryptSha1Init(param_1);
  return;
}



===== SymCryptHmacSha1Result @ 180005bd0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptHmacSha1Result(uint *param_1,ulonglong *param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined1 auStack_48 [32];
  ulonglong local_28;
  undefined8 uStack_20;
  uint local_18;
  ulonglong local_10;
  
  local_10 = __security_cookie ^ (ulonglong)auStack_48;
  SymCryptSha1Result(param_1,&local_28);
  lVar1 = *(longlong *)(param_1 + 0x20);
  uVar2 = *(undefined8 *)(lVar1 + 0x28);
  *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(lVar1 + 0x20);
  *(undefined8 *)(param_1 + 0x1a) = uVar2;
  uVar2 = *(undefined8 *)(lVar1 + 0x30);
  uVar3 = *(undefined8 *)(lVar1 + 0x38);
  param_1[4] = 0x54;
  param_1[5] = 0;
  *(undefined8 *)(param_1 + 0x1c) = uVar2;
  *(undefined8 *)(param_1 + 0x1e) = uVar3;
  *param_1 = 0x14;
  *(ulonglong *)(param_1 + 8) = local_28;
  *(undefined8 *)(param_1 + 10) = uStack_20;
  param_1[0xc] = local_18;
  SymCryptSha1Result(param_1,param_2);
  SymCryptWipeAsm(&local_28,0x14);
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  return;
}



===== FveDmpSecureZeroAndFlush @ 180005c70 =====

void FveDmpSecureZeroAndFlush(undefined1 *param_1,uint param_2)

{
  byte bVar1;
  ulonglong uVar2;
  
  uVar2 = (ulonglong)param_2;
  bVar1 = KeGetCurrentIrql();
  if (bVar1 < 2) {
    bVar1 = KfRaiseIrql(2);
  }
  if ((param_1 != (undefined1 *)0x0) && (param_2 != 0)) {
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      *param_1 = 0;
      param_1 = param_1 + 1;
    }
  }
  KeSweepLocalCaches();
  if (bVar1 < 2) {
    KeLowerIrql(bVar1);
  }
  return;
}



===== SymCryptSha256AppendBlocks_ul1 @ 180005d00 =====

void SymCryptSha256AppendBlocks_ul1
               (uint *param_1,longlong param_2,ulonglong param_3,ulonglong *param_4)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int *local_128;
  uint local_120;
  uint local_11c;
  uint local_118;
  uint local_108;
  uint local_100;
  uint local_f8;
  uint local_f4;
  uint local_f0;
  uint local_e8;
  uint local_e4;
  uint local_e0;
  uint local_d8;
  uint local_c8;
  uint local_b8;
  uint local_b4;
  uint *local_a8;
  ulonglong local_98;
  
  if (0x3f < param_3) {
    uVar14 = *param_1;
    uVar16 = param_1[1];
    uVar18 = param_1[2];
    uVar20 = param_1[3];
    uVar15 = param_1[4];
    uVar17 = param_1[5];
    uVar19 = param_1[6];
    uVar21 = param_1[7];
    local_98 = param_3 >> 6;
    local_a8 = (uint *)(param_2 + 8);
    param_3 = param_3 + local_98 * -0x40;
    do {
      uVar3 = *param_1;
      uVar2 = param_1[4];
      uVar9 = param_1[6];
      uVar12 = param_1[1];
      uVar11 = param_1[5];
      uVar10 = param_1[2];
      uVar4 = local_a8[-2];
      local_c8 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
      uVar4 = local_a8[-1];
      iVar7 = param_1[7] +
              ((uVar9 ^ uVar11) & uVar2 ^ uVar9) +
              ((uVar2 >> 6 | uVar2 << 0x1a) ^
              (uVar2 >> 0x19 | uVar2 << 7) ^ (uVar2 >> 0xb | uVar2 << 0x15)) + local_c8 + 0x428a2f98
      ;
      uVar13 = param_1[3] + iVar7;
      local_e0 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
      uVar4 = ((uVar10 | uVar12) & uVar3 | uVar10 & uVar12) +
              iVar7 + ((uVar3 >> 0x16 | uVar3 << 10) ^ (uVar3 >> 0xd | uVar3 << 0x13) ^
                      (uVar3 >> 2 | uVar3 << 0x1e));
      uVar5 = *local_a8;
      iVar7 = uVar9 + 0x71374491 +
              ((uVar11 ^ uVar2) & uVar13 ^ uVar11) +
              ((uVar13 >> 6 | uVar13 * 0x4000000) ^
              (uVar13 >> 0x19 | uVar13 * 0x80) ^ (uVar13 >> 0xb | uVar13 * 0x200000)) + local_e0;
      uVar10 = iVar7 + uVar10;
      uVar9 = ((uVar12 | uVar3) & uVar4 | uVar12 & uVar3) +
              iVar7 + ((uVar4 >> 0x16 | uVar4 * 0x400) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
                      (uVar4 >> 2 | uVar4 * 0x40000000));
      local_100 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      iVar7 = ((uVar13 ^ uVar2) & uVar10 ^ uVar2) +
              ((uVar10 >> 6 | uVar10 * 0x4000000) ^
              (uVar10 >> 0x19 | uVar10 * 0x80) ^ (uVar10 >> 0xb | uVar10 * 0x200000)) +
              local_100 + 0xb5c0fbcf + uVar11;
      uVar12 = iVar7 + uVar12;
      uVar11 = ((uVar4 | uVar3) & uVar9 | uVar4 & uVar3) +
               iVar7 + ((uVar9 >> 0x16 | uVar9 * 0x400) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
                       (uVar9 >> 2 | uVar9 * 0x40000000));
      uVar5 = local_a8[1];
      local_11c = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      iVar7 = ((uVar10 ^ uVar13) & uVar12 ^ uVar13) +
              ((uVar12 >> 6 | uVar12 * 0x4000000) ^
              (uVar12 >> 0x19 | uVar12 * 0x80) ^ (uVar12 >> 0xb | uVar12 * 0x200000)) +
              local_11c + 0xe9b5dba5 + uVar2;
      uVar3 = iVar7 + uVar3;
      uVar2 = ((uVar9 | uVar4) & uVar11 | uVar9 & uVar4) +
              iVar7 + ((uVar11 >> 0x16 | uVar11 * 0x400) ^ (uVar11 >> 0xd | uVar11 * 0x80000) ^
                      (uVar11 >> 2 | uVar11 * 0x40000000));
      uVar5 = local_a8[2];
      local_118 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      uVar5 = local_a8[3];
      iVar7 = ((uVar12 ^ uVar10) & uVar3 ^ uVar10) +
              ((uVar3 >> 6 | uVar3 * 0x4000000) ^
              (uVar3 >> 0x19 | uVar3 * 0x80) ^ (uVar3 >> 0xb | uVar3 * 0x200000)) +
              local_118 + 0x3956c25b + uVar13;
      local_120 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      uVar4 = iVar7 + uVar4;
      uVar5 = ((uVar11 | uVar9) & uVar2 | uVar11 & uVar9) +
              iVar7 + ((uVar2 >> 0x16 | uVar2 * 0x400) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^
                      (uVar2 >> 2 | uVar2 * 0x40000000));
      uVar13 = local_a8[4];
      iVar7 = ((uVar3 ^ uVar12) & uVar4 ^ uVar12) +
              ((uVar4 >> 6 | uVar4 * 0x4000000) ^
              (uVar4 >> 0x19 | uVar4 * 0x80) ^ (uVar4 >> 0xb | uVar4 * 0x200000)) +
              local_120 + 0x59f111f1 + uVar10;
      uVar9 = iVar7 + uVar9;
      uVar10 = ((uVar2 | uVar11) & uVar5 | uVar2 & uVar11) +
               iVar7 + ((uVar5 >> 0x16 | uVar5 * 0x400) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
                       (uVar5 >> 2 | uVar5 * 0x40000000));
      local_108 = uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8 |
                  uVar13 << 0x18;
      iVar7 = uVar12 + 0x923f82a4 +
              ((uVar4 ^ uVar3) & uVar9 ^ uVar3) +
              ((uVar9 >> 6 | uVar9 * 0x4000000) ^
              (uVar9 >> 0x19 | uVar9 * 0x80) ^ (uVar9 >> 0xb | uVar9 * 0x200000)) + local_108;
      uVar12 = local_a8[5];
      uVar11 = iVar7 + uVar11;
      local_f4 = uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 | uVar12 << 0x18
      ;
      uVar12 = ((uVar5 | uVar2) & uVar10 | uVar5 & uVar2) +
               iVar7 + ((uVar10 >> 0x16 | uVar10 * 0x400) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
                       (uVar10 >> 2 | uVar10 * 0x40000000));
      uVar13 = local_a8[6];
      iVar7 = ((uVar9 ^ uVar4) & uVar11 ^ uVar4) +
              ((uVar11 >> 6 | uVar11 * 0x4000000) ^
              (uVar11 >> 0x19 | uVar11 * 0x80) ^ (uVar11 >> 0xb | uVar11 * 0x200000)) +
              local_f4 + 0xab1c5ed5 + uVar3;
      uVar2 = iVar7 + uVar2;
      uVar3 = ((uVar10 | uVar5) & uVar12 | uVar10 & uVar5) +
              iVar7 + ((uVar12 >> 0x16 | uVar12 * 0x400) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
                      (uVar12 >> 2 | uVar12 * 0x40000000));
      uVar6 = uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8 | uVar13 << 0x18;
      iVar7 = uVar4 + 0xd807aa98 +
              ((uVar11 ^ uVar9) & uVar2 ^ uVar9) +
              ((uVar2 >> 6 | uVar2 * 0x4000000) ^
              (uVar2 >> 0x19 | uVar2 * 0x80) ^ (uVar2 >> 0xb | uVar2 * 0x200000)) + uVar6;
      uVar5 = iVar7 + uVar5;
      uVar13 = local_a8[7];
      uVar4 = ((uVar12 | uVar10) & uVar3 | uVar12 & uVar10) +
              iVar7 + ((uVar3 >> 0x16 | uVar3 * 0x400) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
                      (uVar3 >> 2 | uVar3 * 0x40000000));
      local_f8 = uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8 | uVar13 << 0x18
      ;
      iVar7 = local_f8 + 0x12835b01 +
              ((uVar2 ^ uVar11) & uVar5 ^ uVar11) +
              ((uVar5 >> 6 | uVar5 * 0x4000000) ^
              (uVar5 >> 0x19 | uVar5 * 0x80) ^ (uVar5 >> 0xb | uVar5 * 0x200000)) + uVar9;
      uVar10 = uVar10 + iVar7;
      uVar9 = local_a8[8];
      uVar13 = ((uVar3 | uVar12) & uVar4 | uVar3 & uVar12) +
               iVar7 + ((uVar4 >> 0x16 | uVar4 * 0x400) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
                       (uVar4 >> 2 | uVar4 * 0x40000000));
      uVar8 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
      iVar7 = uVar8 + 0x243185be +
              ((uVar5 ^ uVar2) & uVar10 ^ uVar2) +
              ((uVar10 >> 6 | uVar10 * 0x4000000) ^
              (uVar10 >> 0x19 | uVar10 * 0x80) ^ (uVar10 >> 0xb | uVar10 * 0x200000)) + uVar11;
      uVar12 = uVar12 + iVar7;
      uVar11 = local_a8[9];
      uVar9 = ((uVar3 | uVar4) & uVar13 | uVar3 & uVar4) +
              iVar7 + ((uVar13 >> 0x16 | uVar13 * 0x400) ^ (uVar13 >> 0xd | uVar13 * 0x80000) ^
                      (uVar13 >> 2 | uVar13 * 0x40000000));
      local_b4 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 | uVar11 << 0x18
      ;
      uVar11 = local_a8[10];
      iVar7 = local_b4 + 0x550c7dc3 +
              ((uVar5 ^ uVar10) & uVar12 ^ uVar5) +
              ((uVar12 >> 6 | uVar12 * 0x4000000) ^
              (uVar12 >> 0x19 | uVar12 * 0x80) ^ (uVar12 >> 0xb | uVar12 * 0x200000)) + uVar2;
      local_d8 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 | uVar11 << 0x18
      ;
      uVar3 = uVar3 + iVar7;
      local_b8 = ((uVar13 | uVar4) & uVar9 | uVar13 & uVar4) +
                 iVar7 + ((uVar9 >> 0x16 | uVar9 * 0x400) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
                         (uVar9 >> 2 | uVar9 * 0x40000000));
      iVar7 = local_d8 + 0x72be5d74 +
              ((uVar12 ^ uVar10) & uVar3 ^ uVar10) +
              ((uVar3 >> 6 | uVar3 * 0x4000000) ^
              (uVar3 >> 0x19 | uVar3 * 0x80) ^ (uVar3 >> 0xb | uVar3 * 0x200000)) + uVar5;
      uVar4 = iVar7 + uVar4;
      uVar11 = local_a8[0xb];
      uVar2 = ((uVar9 | uVar13) & local_b8 | uVar9 & uVar13) +
              iVar7 + ((local_b8 >> 0x16 | local_b8 * 0x400) ^
                       (local_b8 >> 0xd | local_b8 * 0x80000) ^
                      (local_b8 >> 2 | local_b8 * 0x40000000));
      local_e8 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 | uVar11 << 0x18
      ;
      iVar7 = uVar10 + 0x80deb1fe +
              ((uVar3 ^ uVar12) & uVar4 ^ uVar12) +
              ((uVar4 >> 6 | uVar4 * 0x4000000) ^
              (uVar4 >> 0x19 | uVar4 * 0x80) ^ (uVar4 >> 0xb | uVar4 * 0x200000)) + local_e8;
      uVar13 = iVar7 + uVar13;
      uVar11 = local_a8[0xc];
      uVar10 = ((local_b8 | uVar9) & uVar2 | local_b8 & uVar9) +
               iVar7 + ((uVar2 >> 0x16 | uVar2 * 0x400) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^
                       (uVar2 >> 2 | uVar2 * 0x40000000));
      local_f0 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 | uVar11 << 0x18
      ;
      iVar7 = local_f0 +
              ((uVar13 >> 0x19 | uVar13 * 0x80) ^ (uVar13 >> 0xb | uVar13 * 0x200000) ^
              (uVar13 >> 6 | uVar13 * 0x4000000)) + ((uVar4 ^ uVar3) & uVar13 ^ uVar3) + 0x9bdc06a7
              + uVar12;
      uVar9 = iVar7 + uVar9;
      uVar11 = local_a8[0xd];
      uVar12 = ((uVar2 | local_b8) & uVar10 | uVar2 & local_b8) +
               iVar7 + ((uVar10 >> 0x16 | uVar10 * 0x400) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
                       (uVar10 >> 2 | uVar10 * 0x40000000));
      local_e4 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 | uVar11 << 0x18
      ;
      iVar7 = ((uVar9 >> 0x19 | uVar9 * 0x80) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
              (uVar9 >> 6 | uVar9 * 0x4000000)) + local_e4 +
              ((uVar13 ^ uVar4) & uVar9 ^ uVar4) + 0xc19bf174 + uVar3;
      local_b8 = iVar7 + local_b8;
      uVar3 = ((uVar10 | uVar2) & uVar12 | uVar10 & uVar2) +
              iVar7 + ((uVar12 >> 0x16 | uVar12 * 0x400) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
                      (uVar12 >> 2 | uVar12 * 0x40000000));
      local_128 = &DAT_180015948;
      do {
        local_c8 = ((local_e0 >> 0x12 | local_e0 << 0xe) ^ (local_e0 >> 7 | local_e0 << 0x19) ^
                   local_e0 >> 3) +
                   local_f8 +
                   ((local_f0 >> 0x13 | local_f0 << 0xd) ^ (local_f0 >> 0x11 | local_f0 << 0xf) ^
                   local_f0 >> 10) + local_c8;
        iVar7 = ((local_b8 >> 0x19 | local_b8 << 7) ^ (local_b8 >> 0xb | local_b8 << 0x15) ^
                (local_b8 >> 6 | local_b8 << 0x1a)) + ((uVar13 ^ uVar9) & local_b8 ^ uVar13) +
                local_128[-2] + uVar4 + local_c8;
        uVar2 = uVar2 + iVar7;
        uVar4 = ((uVar10 | uVar12) & uVar3 | uVar10 & uVar12) +
                iVar7 + ((uVar3 >> 0x16 | uVar3 << 10) ^ (uVar3 >> 0xd | uVar3 << 0x13) ^
                        (uVar3 >> 2 | uVar3 << 0x1e));
        local_e0 = ((local_e4 >> 0x13 | local_e4 << 0xd) ^ (local_e4 >> 0x11 | local_e4 << 0xf) ^
                   local_e4 >> 10) + uVar8 +
                   ((local_100 >> 0x12 | local_100 << 0xe) ^ (local_100 >> 7 | local_100 << 0x19) ^
                   local_100 >> 3) + local_e0;
        iVar7 = local_e0 +
                ((uVar2 >> 0x19 | uVar2 * 0x80) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^
                (uVar2 >> 6 | uVar2 * 0x4000000)) + ((uVar9 ^ local_b8) & uVar2 ^ uVar9) +
                local_128[-1] + uVar13;
        uVar10 = iVar7 + uVar10;
        uVar11 = ((uVar12 | uVar3) & uVar4 | uVar12 & uVar3) +
                 iVar7 + ((uVar4 >> 0x16 | uVar4 * 0x400) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
                         (uVar4 >> 2 | uVar4 * 0x40000000));
        local_100 = (local_c8 >> 10 ^
                    (local_c8 >> 0x13 | local_c8 * 0x2000) ^ (local_c8 >> 0x11 | local_c8 * 0x8000))
                    + local_b4 +
                      ((local_11c >> 0x12 | local_11c << 0xe) ^ (local_11c >> 7 | local_11c << 0x19)
                      ^ local_11c >> 3) + local_100;
        iVar7 = ((uVar10 >> 0x19 | uVar10 * 0x80) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^
                (uVar10 >> 6 | uVar10 * 0x4000000)) + uVar9 +
                ((uVar2 ^ local_b8) & uVar10 ^ local_b8) + local_100 + *local_128;
        uVar12 = iVar7 + uVar12;
        uVar9 = ((uVar4 | uVar3) & uVar11 | uVar4 & uVar3) +
                iVar7 + ((uVar11 >> 0x16 | uVar11 * 0x400) ^ (uVar11 >> 0xd | uVar11 * 0x80000) ^
                        (uVar11 >> 2 | uVar11 * 0x40000000));
        local_11c = ((local_118 >> 0x12 | local_118 << 0xe) ^ (local_118 >> 7 | local_118 << 0x19) ^
                    local_118 >> 3) + local_d8 +
                    ((local_e0 >> 0x13 | local_e0 * 0x2000) ^ (local_e0 >> 0x11 | local_e0 * 0x8000)
                    ^ local_e0 >> 10) + local_11c;
        iVar7 = local_11c +
                ((uVar12 >> 0x19 | uVar12 * 0x80) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^
                (uVar12 >> 6 | uVar12 * 0x4000000)) + ((uVar2 ^ uVar10) & uVar12 ^ uVar2) +
                local_128[1] + local_b8;
        uVar3 = iVar7 + uVar3;
        uVar5 = ((uVar4 | uVar11) & uVar9 | uVar4 & uVar11) +
                iVar7 + ((uVar9 >> 0x16 | uVar9 * 0x400) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
                        (uVar9 >> 2 | uVar9 * 0x40000000));
        local_118 = ((local_100 >> 0x13 | local_100 * 0x2000) ^
                     (local_100 >> 0x11 | local_100 * 0x8000) ^ local_100 >> 10) + local_e8 +
                    ((local_120 >> 0x12 | local_120 << 0xe) ^ (local_120 >> 7 | local_120 << 0x19) ^
                    local_120 >> 3) + local_118;
        iVar7 = local_118 +
                ((uVar3 >> 0x19 | uVar3 * 0x80) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
                (uVar3 >> 6 | uVar3 * 0x4000000)) + ((uVar10 ^ uVar12) & uVar3 ^ uVar10) +
                local_128[2] + uVar2;
        uVar4 = iVar7 + uVar4;
        uVar2 = ((uVar11 | uVar9) & uVar5 | uVar11 & uVar9) +
                iVar7 + ((uVar5 >> 0x16 | uVar5 * 0x400) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
                        (uVar5 >> 2 | uVar5 * 0x40000000));
        local_120 = ((local_108 >> 0x12 | local_108 << 0xe) ^ (local_108 >> 7 | local_108 << 0x19) ^
                    local_108 >> 3) + local_f0 +
                    ((local_11c >> 0x13 | local_11c * 0x2000) ^
                     (local_11c >> 0x11 | local_11c * 0x8000) ^ local_11c >> 10) + local_120;
        iVar7 = local_120 +
                ((uVar4 >> 0x19 | uVar4 * 0x80) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
                (uVar4 >> 6 | uVar4 * 0x4000000)) + ((uVar12 ^ uVar3) & uVar4 ^ uVar12) +
                local_128[3] + uVar10;
        uVar11 = iVar7 + uVar11;
        uVar10 = ((uVar9 | uVar5) & uVar2 | uVar9 & uVar5) +
                 iVar7 + ((uVar2 >> 0x16 | uVar2 * 0x400) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^
                         (uVar2 >> 2 | uVar2 * 0x40000000));
        local_108 = ((local_f4 >> 0x12 | local_f4 << 0xe) ^ (local_f4 >> 7 | local_f4 << 0x19) ^
                    local_f4 >> 3) + local_e4 +
                    ((local_118 >> 0x13 | local_118 * 0x2000) ^
                     (local_118 >> 0x11 | local_118 * 0x8000) ^ local_118 >> 10) + local_108;
        iVar7 = local_108 +
                ((uVar11 >> 0x19 | uVar11 * 0x80) ^ (uVar11 >> 0xb | uVar11 * 0x200000) ^
                (uVar11 >> 6 | uVar11 * 0x4000000)) + ((uVar3 ^ uVar4) & uVar11 ^ uVar3) +
                local_128[4] + uVar12;
        uVar9 = iVar7 + uVar9;
        uVar12 = ((uVar5 | uVar2) & uVar10 | uVar5 & uVar2) +
                 iVar7 + ((uVar10 >> 0x16 | uVar10 * 0x400) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
                         (uVar10 >> 2 | uVar10 * 0x40000000));
        local_f4 = ((uVar6 >> 0x12 | uVar6 << 0xe) ^ (uVar6 >> 7 | uVar6 << 0x19) ^ uVar6 >> 3) +
                   local_c8 +
                   ((local_120 >> 0x13 | local_120 * 0x2000) ^
                    (local_120 >> 0x11 | local_120 * 0x8000) ^ local_120 >> 10) + local_f4;
        iVar7 = local_f4 +
                ((uVar9 >> 0x19 | uVar9 * 0x80) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
                (uVar9 >> 6 | uVar9 * 0x4000000)) + ((uVar4 ^ uVar11) & uVar9 ^ uVar4) +
                local_128[5] + uVar3;
        uVar5 = iVar7 + uVar5;
        uVar3 = ((uVar2 | uVar10) & uVar12 | uVar2 & uVar10) +
                iVar7 + ((uVar12 >> 0x16 | uVar12 * 0x400) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
                        (uVar12 >> 2 | uVar12 * 0x40000000));
        uVar6 = uVar6 + ((local_f8 >> 0x12 | local_f8 << 0xe) ^ (local_f8 >> 7 | local_f8 << 0x19) ^
                        local_f8 >> 3) +
                ((local_108 >> 0x13 | local_108 * 0x2000) ^ (local_108 >> 0x11 | local_108 * 0x8000)
                ^ local_108 >> 10) + local_e0;
        iVar7 = ((uVar5 >> 0x19 | uVar5 * 0x80) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
                (uVar5 >> 6 | uVar5 * 0x4000000)) + ((uVar11 ^ uVar9) & uVar5 ^ uVar11) +
                local_128[6] + uVar4 + uVar6;
        uVar2 = uVar2 + iVar7;
        uVar4 = ((uVar10 | uVar12) & uVar3 | uVar10 & uVar12) +
                iVar7 + ((uVar3 >> 0x16 | uVar3 * 0x400) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
                        (uVar3 >> 2 | uVar3 * 0x40000000));
        local_f8 = ((local_f4 >> 0x13 | local_f4 * 0x2000) ^ (local_f4 >> 0x11 | local_f4 * 0x8000)
                   ^ local_f4 >> 10) + local_100 +
                   ((uVar8 >> 0x12 | uVar8 << 0xe) ^ (uVar8 >> 7 | uVar8 << 0x19) ^ uVar8 >> 3) +
                   local_f8;
        iVar7 = local_f8 +
                ((uVar2 >> 0x19 | uVar2 * 0x80) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^
                (uVar2 >> 6 | uVar2 * 0x4000000)) + ((uVar9 ^ uVar5) & uVar2 ^ uVar9) + local_128[7]
                + uVar11;
        uVar10 = iVar7 + uVar10;
        uVar13 = ((uVar3 | uVar12) & uVar4 | uVar3 & uVar12) +
                 iVar7 + ((uVar4 >> 0x16 | uVar4 * 0x400) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
                         (uVar4 >> 2 | uVar4 * 0x40000000));
        uVar8 = uVar8 + ((local_b4 >> 0x12 | local_b4 << 0xe) ^ (local_b4 >> 7 | local_b4 << 0x19) ^
                        local_b4 >> 3) +
                ((uVar6 >> 0x13 | uVar6 * 0x2000) ^ (uVar6 >> 0x11 | uVar6 * 0x8000) ^ uVar6 >> 10)
                + local_11c;
        iVar7 = ((uVar10 >> 0x19 | uVar10 * 0x80) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^
                (uVar10 >> 6 | uVar10 * 0x4000000)) + ((uVar2 ^ uVar5) & uVar10 ^ uVar5) +
                local_128[8] + uVar9 + uVar8;
        uVar12 = iVar7 + uVar12;
        uVar9 = ((uVar3 | uVar4) & uVar13 | uVar3 & uVar4) +
                iVar7 + ((uVar13 >> 0x16 | uVar13 * 0x400) ^ (uVar13 >> 0xd | uVar13 * 0x80000) ^
                        (uVar13 >> 2 | uVar13 * 0x40000000));
        local_b4 = local_b4 +
                   ((local_f8 >> 0x13 | local_f8 * 0x2000) ^ (local_f8 >> 0x11 | local_f8 * 0x8000)
                   ^ local_f8 >> 10) +
                   ((local_d8 >> 0x12 | local_d8 << 0xe) ^ (local_d8 >> 7 | local_d8 << 0x19) ^
                   local_d8 >> 3) + local_118;
        iVar7 = ((uVar12 >> 0x19 | uVar12 * 0x80) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^
                (uVar12 >> 6 | uVar12 * 0x4000000)) + ((uVar10 ^ uVar2) & uVar12 ^ uVar2) +
                local_128[9] + uVar5 + local_b4;
        uVar3 = uVar3 + iVar7;
        local_b8 = ((uVar4 | uVar13) & uVar9 | uVar4 & uVar13) +
                   iVar7 + ((uVar9 >> 0x16 | uVar9 * 0x400) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
                           (uVar9 >> 2 | uVar9 * 0x40000000));
        local_d8 = ((local_e8 >> 0x12 | local_e8 << 0xe) ^ (local_e8 >> 7 | local_e8 << 0x19) ^
                   local_e8 >> 3) + local_d8 +
                   ((uVar8 >> 0x13 | uVar8 * 0x2000) ^ (uVar8 >> 0x11 | uVar8 * 0x8000) ^
                   uVar8 >> 10) + local_120;
        iVar7 = uVar2 + ((uVar3 >> 0x19 | uVar3 * 0x80) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
                        (uVar3 >> 6 | uVar3 * 0x4000000)) + ((uVar10 ^ uVar12) & uVar3 ^ uVar10) +
                        local_128[10] + local_d8;
        uVar4 = uVar4 + iVar7;
        uVar2 = ((uVar13 | uVar9) & local_b8 | uVar13 & uVar9) +
                iVar7 + ((local_b8 >> 0x16 | local_b8 * 0x400) ^
                         (local_b8 >> 0xd | local_b8 * 0x80000) ^
                        (local_b8 >> 2 | local_b8 * 0x40000000));
        local_e8 = ((local_f0 >> 0x12 | local_f0 << 0xe) ^ (local_f0 >> 7 | local_f0 << 0x19) ^
                   local_f0 >> 3) + local_e8 +
                   ((local_b4 >> 0x13 | local_b4 * 0x2000) ^ (local_b4 >> 0x11 | local_b4 * 0x8000)
                   ^ local_b4 >> 10) + local_108;
        iVar7 = ((uVar4 >> 0x19 | uVar4 * 0x80) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
                (uVar4 >> 6 | uVar4 * 0x4000000)) + ((uVar12 ^ uVar3) & uVar4 ^ uVar12) +
                local_128[0xb] + uVar10 + local_e8;
        uVar13 = uVar13 + iVar7;
        uVar10 = ((uVar9 | local_b8) & uVar2 | uVar9 & local_b8) +
                 iVar7 + ((uVar2 >> 0x16 | uVar2 * 0x400) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^
                         (uVar2 >> 2 | uVar2 * 0x40000000));
        local_f0 = ((local_d8 >> 0x13 | local_d8 * 0x2000) ^ (local_d8 >> 0x11 | local_d8 * 0x8000)
                   ^ local_d8 >> 10) +
                   local_f4 +
                   ((local_e4 >> 0x12 | local_e4 << 0xe) ^ (local_e4 >> 7 | local_e4 << 0x19) ^
                   local_e4 >> 3) + local_f0;
        iVar7 = ((uVar13 >> 0x19 | uVar13 * 0x80) ^ (uVar13 >> 0xb | uVar13 * 0x200000) ^
                (uVar13 >> 6 | uVar13 * 0x4000000)) + ((uVar3 ^ uVar4) & uVar13 ^ uVar3) +
                local_128[0xc] + uVar12 + local_f0;
        uVar9 = uVar9 + iVar7;
        uVar12 = ((local_b8 | uVar2) & uVar10 | local_b8 & uVar2) +
                 iVar7 + ((uVar10 >> 0x16 | uVar10 * 0x400) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
                         (uVar10 >> 2 | uVar10 * 0x40000000));
        local_e4 = ((local_e8 >> 0x13 | local_e8 * 0x2000) ^ (local_e8 >> 0x11 | local_e8 * 0x8000)
                   ^ local_e8 >> 10) +
                   uVar6 + ((local_c8 >> 0x12 | local_c8 * 0x4000) ^
                            (local_c8 >> 7 | local_c8 * 0x2000000) ^ local_c8 >> 3) + local_e4;
        piVar1 = local_128 + 0xd;
        local_128 = local_128 + 0x10;
        iVar7 = ((uVar9 >> 0x19 | uVar9 * 0x80) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
                (uVar9 >> 6 | uVar9 * 0x4000000)) + ((uVar4 ^ uVar13) & uVar9 ^ uVar4) + *piVar1 +
                uVar3 + local_e4;
        local_b8 = local_b8 + iVar7;
        uVar3 = ((uVar2 | uVar10) & uVar12 | uVar2 & uVar10) +
                iVar7 + ((uVar12 >> 0x16 | uVar12 * 0x400) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
                        (uVar12 >> 2 | uVar12 * 0x40000000));
      } while ((longlong)local_128 < 0x180015a08);
      local_a8 = local_a8 + 0x10;
      local_98 = local_98 - 1;
      uVar14 = uVar3 + uVar14;
      uVar16 = uVar12 + uVar16;
      uVar18 = uVar10 + uVar18;
      uVar20 = uVar2 + uVar20;
      *param_1 = uVar14;
      param_1[1] = uVar16;
      param_1[2] = uVar18;
      param_1[3] = uVar20;
      uVar15 = local_b8 + uVar15;
      uVar17 = uVar9 + uVar17;
      uVar19 = uVar13 + uVar19;
      uVar21 = uVar4 + uVar21;
      param_1[4] = uVar15;
      param_1[5] = uVar17;
      param_1[6] = uVar19;
      param_1[7] = uVar21;
    } while (local_98 != 0);
  }
  *param_4 = param_3;
  return;
}



===== SymCryptAesEcbEncryptXmm @ 180006f80 =====

void SymCryptAesEcbEncryptXmm
               (uint *param_1,uint *param_2,undefined1 (*param_3) [16],ulonglong param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 (*pauVar9) [16];
  undefined1 (*pauVar10) [16];
  ulonglong uVar11;
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  undefined1 auVar20 [16];
  undefined1 auVar21 [16];
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  undefined1 auVar25 [16];
  undefined1 auVar26 [16];
  undefined1 auVar27 [16];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  
  auVar24 = ZEXT816(0);
  auVar12 = ZEXT816(0);
  auVar22 = ZEXT816(0);
  auVar15 = ZEXT816(0);
  auVar18 = ZEXT816(0);
  auVar20 = ZEXT816(0);
  if (0x7f < param_4) {
    uVar11 = param_4 >> 7;
    param_4 = param_4 + uVar11 * -0x80;
    do {
      uVar1 = *param_1;
      uVar2 = param_1[1];
      uVar3 = param_1[2];
      uVar4 = param_1[3];
      pauVar9 = (undefined1 (*) [16])(param_1 + 4);
      auVar12._0_4_ = *param_2 ^ uVar1;
      auVar12._4_4_ = param_2[1] ^ uVar2;
      auVar12._8_4_ = param_2[2] ^ uVar3;
      auVar12._12_4_ = param_2[3] ^ uVar4;
      auVar22._0_4_ = param_2[4] ^ uVar1;
      auVar22._4_4_ = param_2[5] ^ uVar2;
      auVar22._8_4_ = param_2[6] ^ uVar3;
      auVar22._12_4_ = param_2[7] ^ uVar4;
      auVar24._0_4_ = param_2[8] ^ uVar1;
      auVar24._4_4_ = param_2[9] ^ uVar2;
      auVar24._8_4_ = param_2[10] ^ uVar3;
      auVar24._12_4_ = param_2[0xb] ^ uVar4;
      auVar26._0_4_ = param_2[0xc] ^ uVar1;
      auVar26._4_4_ = param_2[0xd] ^ uVar2;
      auVar26._8_4_ = param_2[0xe] ^ uVar3;
      auVar26._12_4_ = param_2[0xf] ^ uVar4;
      auVar15._0_4_ = param_2[0x10] ^ uVar1;
      auVar15._4_4_ = param_2[0x11] ^ uVar2;
      auVar15._8_4_ = param_2[0x12] ^ uVar3;
      auVar15._12_4_ = param_2[0x13] ^ uVar4;
      auVar18._0_4_ = param_2[0x14] ^ uVar1;
      auVar18._4_4_ = param_2[0x15] ^ uVar2;
      auVar18._8_4_ = param_2[0x16] ^ uVar3;
      auVar18._12_4_ = param_2[0x17] ^ uVar4;
      auVar20._0_4_ = param_2[0x18] ^ uVar1;
      auVar20._4_4_ = param_2[0x19] ^ uVar2;
      auVar20._8_4_ = param_2[0x1a] ^ uVar3;
      auVar20._12_4_ = param_2[0x1b] ^ uVar4;
      auVar28._0_4_ = param_2[0x1c] ^ uVar1;
      auVar28._4_4_ = param_2[0x1d] ^ uVar2;
      auVar28._8_4_ = param_2[0x1e] ^ uVar3;
      auVar28._12_4_ = param_2[0x1f] ^ uVar4;
      do {
        auVar17 = *pauVar9;
        pauVar9 = pauVar9 + 1;
        auVar12 = aesenc(auVar12,auVar17);
        auVar22 = aesenc(auVar22,auVar17);
        auVar24 = aesenc(auVar24,auVar17);
        auVar26 = aesenc(auVar26,auVar17);
        auVar15 = aesenc(auVar15,auVar17);
        auVar18 = aesenc(auVar18,auVar17);
        auVar20 = aesenc(auVar20,auVar17);
        auVar28 = aesenc(auVar28,auVar17);
      } while (pauVar9 < *(undefined1 (**) [16])(param_1 + 0x74));
      auVar17 = *pauVar9;
      param_2 = param_2 + 0x20;
      auVar13 = aesenclast(auVar12,auVar17);
      auVar12 = aesenclast(auVar22,auVar17);
      auVar22 = aesenclast(auVar24,auVar17);
      auVar24 = aesenclast(auVar26,auVar17);
      auVar15 = aesenclast(auVar15,auVar17);
      auVar18 = aesenclast(auVar18,auVar17);
      auVar20 = aesenclast(auVar20,auVar17);
      auVar26 = aesenclast(auVar28,auVar17);
      *param_3 = auVar13;
      param_3[1] = auVar12;
      param_3[2] = auVar22;
      param_3[3] = auVar24;
      param_3[4] = auVar15;
      param_3[5] = auVar18;
      param_3[6] = auVar20;
      param_3[7] = auVar26;
      param_3 = param_3 + 8;
      uVar11 = uVar11 - 1;
    } while (uVar11 != 0);
  }
  if (0xf < param_4) {
    uVar1 = *param_2;
    uVar2 = param_2[1];
    uVar3 = param_2[2];
    uVar4 = param_2[3];
    if (((((param_4 < 0x20) || (auVar12 = *(undefined1 (*) [16])(param_2 + 4), param_4 < 0x30)) ||
         (auVar22 = *(undefined1 (*) [16])(param_2 + 8), param_4 < 0x40)) ||
        ((auVar24 = *(undefined1 (*) [16])(param_2 + 0xc), param_4 < 0x50 ||
         (auVar15 = *(undefined1 (*) [16])(param_2 + 0x10), param_4 < 0x60)))) ||
       (auVar18 = *(undefined1 (*) [16])(param_2 + 0x14), param_4 < 0x70)) {
      pauVar9 = (undefined1 (*) [16])(param_1 + 4);
      if (param_4 < 0x50) {
        uVar5 = *param_1;
        uVar6 = param_1[1];
        uVar7 = param_1[2];
        uVar8 = param_1[3];
        if (param_4 < 0x20) {
          pauVar10 = (undefined1 (*) [16])(param_1 + 8);
          auVar17._0_4_ = uVar5 ^ uVar1;
          auVar17._4_4_ = uVar6 ^ uVar2;
          auVar17._8_4_ = uVar7 ^ uVar3;
          auVar17._12_4_ = uVar8 ^ uVar4;
          auVar12 = aesenc(auVar17,*pauVar9);
          do {
            auVar22 = *pauVar10;
            pauVar9 = pauVar10 + 1;
            pauVar10 = pauVar10 + 2;
            auVar12 = aesenc(auVar12,auVar22);
            auVar12 = aesenc(auVar12,*pauVar9);
          } while (pauVar10 < *(undefined1 (**) [16])(param_1 + 0x74));
          auVar12 = aesenclast(auVar12,*pauVar10);
          *param_3 = auVar12;
          return;
        }
        auVar19._0_4_ = uVar5 ^ uVar1;
        auVar19._4_4_ = uVar6 ^ uVar2;
        auVar19._8_4_ = uVar7 ^ uVar3;
        auVar19._12_4_ = uVar8 ^ uVar4;
        auVar21._0_4_ = uVar5 ^ auVar12._0_4_;
        auVar21._4_4_ = uVar6 ^ auVar12._4_4_;
        auVar21._8_4_ = uVar7 ^ auVar12._8_4_;
        auVar21._12_4_ = uVar8 ^ auVar12._12_4_;
        auVar16._0_4_ = uVar5 ^ auVar24._0_4_;
        auVar16._4_4_ = uVar6 ^ auVar24._4_4_;
        auVar16._8_4_ = uVar7 ^ auVar24._8_4_;
        auVar16._12_4_ = uVar8 ^ auVar24._12_4_;
        auVar13._0_4_ = uVar5 ^ auVar22._0_4_;
        auVar13._4_4_ = uVar6 ^ auVar22._4_4_;
        auVar13._8_4_ = uVar7 ^ auVar22._8_4_;
        auVar13._12_4_ = uVar8 ^ auVar22._12_4_;
        do {
          auVar12 = *pauVar9;
          pauVar9 = pauVar9 + 1;
          auVar19 = aesenc(auVar19,auVar12);
          auVar21 = aesenc(auVar21,auVar12);
          auVar13 = aesenc(auVar13,auVar12);
          auVar16 = aesenc(auVar16,auVar12);
        } while (pauVar9 < *(undefined1 (**) [16])(param_1 + 0x74));
        auVar12 = *pauVar9;
        auVar22 = aesenclast(auVar19,auVar12);
        auVar24 = aesenclast(auVar21,auVar12);
        *param_3 = auVar22;
        param_3[1] = auVar24;
        auVar22 = aesenclast(auVar13,auVar12);
        auVar12 = aesenclast(auVar16,auVar12);
        if (param_4 < 0x30) {
          return;
        }
        param_3[2] = auVar22;
        if (param_4 < 0x40) {
          return;
        }
        param_3[3] = auVar12;
        return;
      }
    }
    else {
      auVar20 = *(undefined1 (*) [16])(param_2 + 0x18);
    }
    pauVar9 = (undefined1 (*) [16])(param_1 + 4);
    uVar5 = *param_1;
    uVar6 = param_1[1];
    uVar7 = param_1[2];
    uVar8 = param_1[3];
    auVar30._0_4_ = uVar5 ^ uVar1;
    auVar30._4_4_ = uVar6 ^ uVar2;
    auVar30._8_4_ = uVar7 ^ uVar3;
    auVar30._12_4_ = uVar8 ^ uVar4;
    auVar31._0_4_ = uVar5 ^ auVar12._0_4_;
    auVar31._4_4_ = uVar6 ^ auVar12._4_4_;
    auVar31._8_4_ = uVar7 ^ auVar12._8_4_;
    auVar31._12_4_ = uVar8 ^ auVar12._12_4_;
    auVar14._0_4_ = uVar5 ^ auVar18._0_4_;
    auVar14._4_4_ = uVar6 ^ auVar18._4_4_;
    auVar14._8_4_ = uVar7 ^ auVar18._8_4_;
    auVar14._12_4_ = uVar8 ^ auVar18._12_4_;
    auVar23._0_4_ = uVar5 ^ auVar22._0_4_;
    auVar23._4_4_ = uVar6 ^ auVar22._4_4_;
    auVar23._8_4_ = uVar7 ^ auVar22._8_4_;
    auVar23._12_4_ = uVar8 ^ auVar22._12_4_;
    auVar25._0_4_ = uVar5 ^ auVar24._0_4_;
    auVar25._4_4_ = uVar6 ^ auVar24._4_4_;
    auVar25._8_4_ = uVar7 ^ auVar24._8_4_;
    auVar25._12_4_ = uVar8 ^ auVar24._12_4_;
    auVar27._0_4_ = uVar5 ^ auVar15._0_4_;
    auVar27._4_4_ = uVar6 ^ auVar15._4_4_;
    auVar27._8_4_ = uVar7 ^ auVar15._8_4_;
    auVar27._12_4_ = uVar8 ^ auVar15._12_4_;
    auVar29._0_4_ = uVar5 ^ auVar20._0_4_;
    auVar29._4_4_ = uVar6 ^ auVar20._4_4_;
    auVar29._8_4_ = uVar7 ^ auVar20._8_4_;
    auVar29._12_4_ = uVar8 ^ auVar20._12_4_;
    do {
      auVar12 = *pauVar9;
      pauVar9 = pauVar9 + 1;
      auVar30 = aesenc(auVar30,auVar12);
      auVar31 = aesenc(auVar31,auVar12);
      auVar23 = aesenc(auVar23,auVar12);
      auVar25 = aesenc(auVar25,auVar12);
      auVar27 = aesenc(auVar27,auVar12);
      auVar14 = aesenc(auVar14,auVar12);
      auVar29 = aesenc(auVar29,auVar12);
    } while (pauVar9 < *(undefined1 (**) [16])(param_1 + 0x74));
    auVar12 = *pauVar9;
    auVar22 = aesenclast(auVar30,auVar12);
    *param_3 = auVar22;
    auVar22 = aesenclast(auVar31,auVar12);
    param_3[1] = auVar22;
    auVar22 = aesenclast(auVar23,auVar12);
    param_3[2] = auVar22;
    auVar22 = aesenclast(auVar25,auVar12);
    auVar24 = aesenclast(auVar27,auVar12);
    param_3[3] = auVar22;
    param_3[4] = auVar24;
    auVar22 = aesenclast(auVar14,auVar12);
    auVar12 = aesenclast(auVar29,auVar12);
    if ((0x5f < param_4) && (param_3[5] = auVar22, 0x6f < param_4)) {
      param_3[6] = auVar12;
    }
  }
  return;
}



===== SymCryptDetectCpuFeaturesByCpuid @ 180007300 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00018000763a) */
/* WARNING: Removing unreachable block (ram,0x00018000760c) */
/* WARNING: Removing unreachable block (ram,0x0001800075eb) */
/* WARNING: Removing unreachable block (ram,0x0001800075b1) */
/* WARNING: Removing unreachable block (ram,0x00018000733c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SymCryptDetectCpuFeaturesByCpuid(void)

{
  byte bVar1;
  uint *puVar2;
  longlong lVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  uint uVar11;
  byte in_XCR0;
  uint local_28 [4];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)local_28;
  uVar11 = 0;
  pbVar10 = &DAT_180015aea;
  g_SymCryptCpuFeaturesNotPresent = 0xffffc020;
  uVar8 = 0;
  puVar2 = (uint *)cpuid_basic_info(0);
  uVar7 = *puVar2;
  local_28[0] = uVar7;
  local_28[1] = puVar2[1];
  local_28[2] = puVar2[3];
  local_28[3] = puVar2[2];
  do {
    bVar1 = pbVar10[-10];
    uVar9 = (uint)bVar1;
    if (uVar9 != uVar11) {
      if (uVar9 == 0) {
        puVar2 = (uint *)cpuid_basic_info(0);
      }
      else if (uVar9 == 1) {
        puVar2 = (uint *)cpuid_Version_info(1);
      }
      else if (uVar9 == 2) {
        puVar2 = (uint *)cpuid_cache_tlb_info(2);
      }
      else if (uVar9 == 3) {
        puVar2 = (uint *)cpuid_serial_info(3);
      }
      else if (uVar9 == 4) {
        puVar2 = (uint *)cpuid_Deterministic_Cache_Parameters_info(4);
      }
      else if (uVar9 == 5) {
        puVar2 = (uint *)cpuid_MONITOR_MWAIT_Features_info(5);
      }
      else if (uVar9 == 6) {
        puVar2 = (uint *)cpuid_Thermal_Power_Management_info(6);
      }
      else if (uVar9 == 7) {
        puVar2 = (uint *)cpuid_Extended_Feature_Enumeration_info(7);
      }
      else if (uVar9 == 9) {
        puVar2 = (uint *)cpuid_Direct_Cache_Access_info(9);
      }
      else if (uVar9 == 10) {
        puVar2 = (uint *)cpuid_Architectural_Performance_Monitoring_info(10);
      }
      else if (uVar9 == 0xb) {
        puVar2 = (uint *)cpuid_Extended_Topology_info(0xb);
      }
      else if (uVar9 == 0xd) {
        puVar2 = (uint *)cpuid_Processor_Extended_States_info(0xd);
      }
      else if (uVar9 == 0xf) {
        puVar2 = (uint *)cpuid_Quality_of_Service_info(0xf);
      }
      else if (uVar9 == 0x80000002) {
        puVar2 = (uint *)cpuid_brand_part1_info(0x80000002);
      }
      else if (uVar9 == 0x80000003) {
        puVar2 = (uint *)cpuid_brand_part2_info(0x80000003);
      }
      else if (uVar9 == 0x80000004) {
        puVar2 = (uint *)cpuid_brand_part3_info(0x80000004);
      }
      else {
        puVar2 = (uint *)cpuid(uVar9);
      }
      local_28[0] = *puVar2;
      local_28[1] = puVar2[1];
      local_28[2] = puVar2[3];
      local_28[3] = puVar2[2];
      uVar11 = (uint)bVar1;
    }
    if (((int)uVar7 < (int)(uint)bVar1) ||
       ((local_28[pbVar10[-9]] >> (pbVar10[-8] & 0x1f) & 1) == 0)) {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | *(uint *)(pbVar10 + -6);
    }
    bVar1 = pbVar10[-2];
    uVar9 = (uint)bVar1;
    if (uVar9 != uVar11) {
      if (uVar9 == 0) {
        puVar2 = (uint *)cpuid_basic_info(0);
      }
      else if (uVar9 == 1) {
        puVar2 = (uint *)cpuid_Version_info(1);
      }
      else if (uVar9 == 2) {
        puVar2 = (uint *)cpuid_cache_tlb_info(2);
      }
      else if (uVar9 == 3) {
        puVar2 = (uint *)cpuid_serial_info(3);
      }
      else if (uVar9 == 4) {
        puVar2 = (uint *)cpuid_Deterministic_Cache_Parameters_info(4);
      }
      else if (uVar9 == 5) {
        puVar2 = (uint *)cpuid_MONITOR_MWAIT_Features_info(5);
      }
      else if (uVar9 == 6) {
        puVar2 = (uint *)cpuid_Thermal_Power_Management_info(6);
      }
      else if (uVar9 == 7) {
        puVar2 = (uint *)cpuid_Extended_Feature_Enumeration_info(7);
      }
      else if (uVar9 == 9) {
        puVar2 = (uint *)cpuid_Direct_Cache_Access_info(9);
      }
      else if (uVar9 == 10) {
        puVar2 = (uint *)cpuid_Architectural_Performance_Monitoring_info(10);
      }
      else if (uVar9 == 0xb) {
        puVar2 = (uint *)cpuid_Extended_Topology_info(0xb);
      }
      else if (uVar9 == 0xd) {
        puVar2 = (uint *)cpuid_Processor_Extended_States_info(0xd);
      }
      else if (uVar9 == 0xf) {
        puVar2 = (uint *)cpuid_Quality_of_Service_info(0xf);
      }
      else if (uVar9 == 0x80000002) {
        puVar2 = (uint *)cpuid_brand_part1_info(0x80000002);
      }
      else if (uVar9 == 0x80000003) {
        puVar2 = (uint *)cpuid_brand_part2_info(0x80000003);
      }
      else if (uVar9 == 0x80000004) {
        puVar2 = (uint *)cpuid_brand_part3_info(0x80000004);
      }
      else {
        puVar2 = (uint *)cpuid(uVar9);
      }
      local_28[0] = *puVar2;
      local_28[1] = puVar2[1];
      local_28[2] = puVar2[3];
      local_28[3] = puVar2[2];
      uVar11 = (uint)bVar1;
    }
    if (((int)uVar7 < (int)(uint)bVar1) || ((local_28[pbVar10[-1]] >> (*pbVar10 & 0x1f) & 1) == 0))
    {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | *(uint *)(pbVar10 + 2);
    }
    bVar1 = pbVar10[6];
    uVar9 = (uint)bVar1;
    if (uVar9 != uVar11) {
      if (uVar9 == 0) {
        puVar2 = (uint *)cpuid_basic_info(0);
      }
      else if (uVar9 == 1) {
        puVar2 = (uint *)cpuid_Version_info(1);
      }
      else if (uVar9 == 2) {
        puVar2 = (uint *)cpuid_cache_tlb_info(2);
      }
      else if (uVar9 == 3) {
        puVar2 = (uint *)cpuid_serial_info(3);
      }
      else if (uVar9 == 4) {
        puVar2 = (uint *)cpuid_Deterministic_Cache_Parameters_info(4);
      }
      else if (uVar9 == 5) {
        puVar2 = (uint *)cpuid_MONITOR_MWAIT_Features_info(5);
      }
      else if (uVar9 == 6) {
        puVar2 = (uint *)cpuid_Thermal_Power_Management_info(6);
      }
      else if (uVar9 == 7) {
        puVar2 = (uint *)cpuid_Extended_Feature_Enumeration_info(7);
      }
      else if (uVar9 == 9) {
        puVar2 = (uint *)cpuid_Direct_Cache_Access_info(9);
      }
      else if (uVar9 == 10) {
        puVar2 = (uint *)cpuid_Architectural_Performance_Monitoring_info(10);
      }
      else if (uVar9 == 0xb) {
        puVar2 = (uint *)cpuid_Extended_Topology_info(0xb);
      }
      else if (uVar9 == 0xd) {
        puVar2 = (uint *)cpuid_Processor_Extended_States_info(0xd);
      }
      else if (uVar9 == 0xf) {
        puVar2 = (uint *)cpuid_Quality_of_Service_info(0xf);
      }
      else if (uVar9 == 0x80000002) {
        puVar2 = (uint *)cpuid_brand_part1_info(0x80000002);
      }
      else if (uVar9 == 0x80000003) {
        puVar2 = (uint *)cpuid_brand_part2_info(0x80000003);
      }
      else if (uVar9 == 0x80000004) {
        puVar2 = (uint *)cpuid_brand_part3_info(0x80000004);
      }
      else {
        puVar2 = (uint *)cpuid(uVar9);
      }
      local_28[0] = *puVar2;
      local_28[1] = puVar2[1];
      local_28[2] = puVar2[3];
      local_28[3] = puVar2[2];
      uVar11 = (uint)bVar1;
    }
    if (((int)uVar7 < (int)(uint)bVar1) || ((local_28[pbVar10[7]] >> (pbVar10[8] & 0x1f) & 1) == 0))
    {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | *(uint *)(pbVar10 + 10);
    }
    bVar1 = pbVar10[0xe];
    uVar9 = (uint)bVar1;
    if (uVar9 != uVar11) {
      if (uVar9 == 0) {
        puVar2 = (uint *)cpuid_basic_info(0);
      }
      else if (uVar9 == 1) {
        puVar2 = (uint *)cpuid_Version_info(1);
      }
      else if (uVar9 == 2) {
        puVar2 = (uint *)cpuid_cache_tlb_info(2);
      }
      else if (uVar9 == 3) {
        puVar2 = (uint *)cpuid_serial_info(3);
      }
      else if (uVar9 == 4) {
        puVar2 = (uint *)cpuid_Deterministic_Cache_Parameters_info(4);
      }
      else if (uVar9 == 5) {
        puVar2 = (uint *)cpuid_MONITOR_MWAIT_Features_info(5);
      }
      else if (uVar9 == 6) {
        puVar2 = (uint *)cpuid_Thermal_Power_Management_info(6);
      }
      else if (uVar9 == 7) {
        puVar2 = (uint *)cpuid_Extended_Feature_Enumeration_info(7);
      }
      else if (uVar9 == 9) {
        puVar2 = (uint *)cpuid_Direct_Cache_Access_info(9);
      }
      else if (uVar9 == 10) {
        puVar2 = (uint *)cpuid_Architectural_Performance_Monitoring_info(10);
      }
      else if (uVar9 == 0xb) {
        puVar2 = (uint *)cpuid_Extended_Topology_info(0xb);
      }
      else if (uVar9 == 0xd) {
        puVar2 = (uint *)cpuid_Processor_Extended_States_info(0xd);
      }
      else if (uVar9 == 0xf) {
        puVar2 = (uint *)cpuid_Quality_of_Service_info(0xf);
      }
      else if (uVar9 == 0x80000002) {
        puVar2 = (uint *)cpuid_brand_part1_info(0x80000002);
      }
      else if (uVar9 == 0x80000003) {
        puVar2 = (uint *)cpuid_brand_part2_info(0x80000003);
      }
      else if (uVar9 == 0x80000004) {
        puVar2 = (uint *)cpuid_brand_part3_info(0x80000004);
      }
      else {
        puVar2 = (uint *)cpuid(uVar9);
      }
      local_28[0] = *puVar2;
      local_28[1] = puVar2[1];
      local_28[2] = puVar2[3];
      local_28[3] = puVar2[2];
      uVar11 = (uint)bVar1;
    }
    if (((int)uVar7 < (int)(uint)bVar1) ||
       ((local_28[pbVar10[0xf]] >> (pbVar10[0x10] & 0x1f) & 1) == 0)) {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | *(uint *)(pbVar10 + 0x12);
    }
    bVar1 = pbVar10[0x16];
    uVar9 = (uint)bVar1;
    if (uVar9 != uVar11) {
      if (uVar9 == 0) {
        puVar2 = (uint *)cpuid_basic_info(0);
      }
      else if (uVar9 == 1) {
        puVar2 = (uint *)cpuid_Version_info(1);
      }
      else if (uVar9 == 2) {
        puVar2 = (uint *)cpuid_cache_tlb_info(2);
      }
      else if (uVar9 == 3) {
        puVar2 = (uint *)cpuid_serial_info(3);
      }
      else if (uVar9 == 4) {
        puVar2 = (uint *)cpuid_Deterministic_Cache_Parameters_info(4);
      }
      else if (uVar9 == 5) {
        puVar2 = (uint *)cpuid_MONITOR_MWAIT_Features_info(5);
      }
      else if (uVar9 == 6) {
        puVar2 = (uint *)cpuid_Thermal_Power_Management_info(6);
      }
      else if (uVar9 == 7) {
        puVar2 = (uint *)cpuid_Extended_Feature_Enumeration_info(7);
      }
      else if (uVar9 == 9) {
        puVar2 = (uint *)cpuid_Direct_Cache_Access_info(9);
      }
      else if (uVar9 == 10) {
        puVar2 = (uint *)cpuid_Architectural_Performance_Monitoring_info(10);
      }
      else if (uVar9 == 0xb) {
        puVar2 = (uint *)cpuid_Extended_Topology_info(0xb);
      }
      else if (uVar9 == 0xd) {
        puVar2 = (uint *)cpuid_Processor_Extended_States_info(0xd);
      }
      else if (uVar9 == 0xf) {
        puVar2 = (uint *)cpuid_Quality_of_Service_info(0xf);
      }
      else if (uVar9 == 0x80000002) {
        puVar2 = (uint *)cpuid_brand_part1_info(0x80000002);
      }
      else if (uVar9 == 0x80000003) {
        puVar2 = (uint *)cpuid_brand_part2_info(0x80000003);
      }
      else if (uVar9 == 0x80000004) {
        puVar2 = (uint *)cpuid_brand_part3_info(0x80000004);
      }
      else {
        puVar2 = (uint *)cpuid(uVar9);
      }
      local_28[0] = *puVar2;
      local_28[1] = puVar2[1];
      local_28[2] = puVar2[3];
      local_28[3] = puVar2[2];
      uVar11 = (uint)bVar1;
    }
    if (((int)uVar7 < (int)(uint)bVar1) ||
       ((local_28[pbVar10[0x17]] >> (pbVar10[0x18] & 0x1f) & 1) == 0)) {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | *(uint *)(pbVar10 + 0x1a);
    }
    bVar1 = pbVar10[0x1e];
    uVar9 = (uint)bVar1;
    if (uVar9 != uVar11) {
      if (uVar9 == 0) {
        puVar2 = (uint *)cpuid_basic_info(0);
      }
      else if (uVar9 == 1) {
        puVar2 = (uint *)cpuid_Version_info(1);
      }
      else if (uVar9 == 2) {
        puVar2 = (uint *)cpuid_cache_tlb_info(2);
      }
      else if (uVar9 == 3) {
        puVar2 = (uint *)cpuid_serial_info(3);
      }
      else if (uVar9 == 4) {
        puVar2 = (uint *)cpuid_Deterministic_Cache_Parameters_info(4);
      }
      else if (uVar9 == 5) {
        puVar2 = (uint *)cpuid_MONITOR_MWAIT_Features_info(5);
      }
      else if (uVar9 == 6) {
        puVar2 = (uint *)cpuid_Thermal_Power_Management_info(6);
      }
      else if (uVar9 == 7) {
        puVar2 = (uint *)cpuid_Extended_Feature_Enumeration_info(7);
      }
      else if (uVar9 == 9) {
        puVar2 = (uint *)cpuid_Direct_Cache_Access_info(9);
      }
      else if (uVar9 == 10) {
        puVar2 = (uint *)cpuid_Architectural_Performance_Monitoring_info(10);
      }
      else if (uVar9 == 0xb) {
        puVar2 = (uint *)cpuid_Extended_Topology_info(0xb);
      }
      else if (uVar9 == 0xd) {
        puVar2 = (uint *)cpuid_Processor_Extended_States_info(0xd);
      }
      else if (uVar9 == 0xf) {
        puVar2 = (uint *)cpuid_Quality_of_Service_info(0xf);
      }
      else if (uVar9 == 0x80000002) {
        puVar2 = (uint *)cpuid_brand_part1_info(0x80000002);
      }
      else if (uVar9 == 0x80000003) {
        puVar2 = (uint *)cpuid_brand_part2_info(0x80000003);
      }
      else if (uVar9 == 0x80000004) {
        puVar2 = (uint *)cpuid_brand_part3_info(0x80000004);
      }
      else {
        puVar2 = (uint *)cpuid(uVar9);
      }
      local_28[0] = *puVar2;
      local_28[1] = puVar2[1];
      local_28[2] = puVar2[3];
      local_28[3] = puVar2[2];
      uVar11 = (uint)bVar1;
    }
    if (((int)uVar7 < (int)(uint)bVar1) ||
       ((local_28[pbVar10[0x1f]] >> (pbVar10[0x20] & 0x1f) & 1) == 0)) {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | *(uint *)(pbVar10 + 0x22);
    }
    bVar1 = pbVar10[0x26];
    uVar9 = (uint)bVar1;
    if (uVar9 != uVar11) {
      if (uVar9 == 0) {
        puVar2 = (uint *)cpuid_basic_info(0);
      }
      else if (uVar9 == 1) {
        puVar2 = (uint *)cpuid_Version_info(1);
      }
      else if (uVar9 == 2) {
        puVar2 = (uint *)cpuid_cache_tlb_info(2);
      }
      else if (uVar9 == 3) {
        puVar2 = (uint *)cpuid_serial_info(3);
      }
      else if (uVar9 == 4) {
        puVar2 = (uint *)cpuid_Deterministic_Cache_Parameters_info(4);
      }
      else if (uVar9 == 5) {
        puVar2 = (uint *)cpuid_MONITOR_MWAIT_Features_info(5);
      }
      else if (uVar9 == 6) {
        puVar2 = (uint *)cpuid_Thermal_Power_Management_info(6);
      }
      else if (uVar9 == 7) {
        puVar2 = (uint *)cpuid_Extended_Feature_Enumeration_info(7);
      }
      else if (uVar9 == 9) {
        puVar2 = (uint *)cpuid_Direct_Cache_Access_info(9);
      }
      else if (uVar9 == 10) {
        puVar2 = (uint *)cpuid_Architectural_Performance_Monitoring_info(10);
      }
      else if (uVar9 == 0xb) {
        puVar2 = (uint *)cpuid_Extended_Topology_info(0xb);
      }
      else if (uVar9 == 0xd) {
        puVar2 = (uint *)cpuid_Processor_Extended_States_info(0xd);
      }
      else if (uVar9 == 0xf) {
        puVar2 = (uint *)cpuid_Quality_of_Service_info(0xf);
      }
      else if (uVar9 == 0x80000002) {
        puVar2 = (uint *)cpuid_brand_part1_info(0x80000002);
      }
      else if (uVar9 == 0x80000003) {
        puVar2 = (uint *)cpuid_brand_part2_info(0x80000003);
      }
      else if (uVar9 == 0x80000004) {
        puVar2 = (uint *)cpuid_brand_part3_info(0x80000004);
      }
      else {
        puVar2 = (uint *)cpuid(uVar9);
      }
      local_28[0] = *puVar2;
      local_28[1] = puVar2[1];
      local_28[2] = puVar2[3];
      local_28[3] = puVar2[2];
      uVar11 = (uint)bVar1;
    }
    if (((int)uVar7 < (int)(uint)bVar1) ||
       ((local_28[pbVar10[0x27]] >> (pbVar10[0x28] & 0x1f) & 1) == 0)) {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | *(uint *)(pbVar10 + 0x2a);
    }
    bVar1 = pbVar10[0x2e];
    uVar9 = (uint)bVar1;
    if (uVar9 != uVar11) {
      if (uVar9 == 0) {
        puVar2 = (uint *)cpuid_basic_info(0);
      }
      else if (uVar9 == 1) {
        puVar2 = (uint *)cpuid_Version_info(1);
      }
      else if (uVar9 == 2) {
        puVar2 = (uint *)cpuid_cache_tlb_info(2);
      }
      else if (uVar9 == 3) {
        puVar2 = (uint *)cpuid_serial_info(3);
      }
      else if (uVar9 == 4) {
        puVar2 = (uint *)cpuid_Deterministic_Cache_Parameters_info(4);
      }
      else if (uVar9 == 5) {
        puVar2 = (uint *)cpuid_MONITOR_MWAIT_Features_info(5);
      }
      else if (uVar9 == 6) {
        puVar2 = (uint *)cpuid_Thermal_Power_Management_info(6);
      }
      else if (uVar9 == 7) {
        puVar2 = (uint *)cpuid_Extended_Feature_Enumeration_info(7);
      }
      else if (uVar9 == 9) {
        puVar2 = (uint *)cpuid_Direct_Cache_Access_info(9);
      }
      else if (uVar9 == 10) {
        puVar2 = (uint *)cpuid_Architectural_Performance_Monitoring_info(10);
      }
      else if (uVar9 == 0xb) {
        puVar2 = (uint *)cpuid_Extended_Topology_info(0xb);
      }
      else if (uVar9 == 0xd) {
        puVar2 = (uint *)cpuid_Processor_Extended_States_info(0xd);
      }
      else if (uVar9 == 0xf) {
        puVar2 = (uint *)cpuid_Quality_of_Service_info(0xf);
      }
      else if (uVar9 == 0x80000002) {
        puVar2 = (uint *)cpuid_brand_part1_info(0x80000002);
      }
      else if (uVar9 == 0x80000003) {
        puVar2 = (uint *)cpuid_brand_part2_info(0x80000003);
      }
      else if (uVar9 == 0x80000004) {
        puVar2 = (uint *)cpuid_brand_part3_info(0x80000004);
      }
      else {
        puVar2 = (uint *)cpuid(uVar9);
      }
      local_28[0] = *puVar2;
      local_28[1] = puVar2[1];
      local_28[2] = puVar2[3];
      local_28[3] = puVar2[2];
      uVar11 = (uint)bVar1;
    }
    if (((int)uVar7 < (int)(uint)bVar1) ||
       ((local_28[pbVar10[0x2f]] >> (pbVar10[0x30] & 0x1f) & 1) == 0)) {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | *(uint *)(pbVar10 + 0x32);
    }
    bVar1 = pbVar10[0x36];
    uVar9 = (uint)bVar1;
    if (uVar9 != uVar11) {
      if (uVar9 == 0) {
        puVar2 = (uint *)cpuid_basic_info(0);
      }
      else if (uVar9 == 1) {
        puVar2 = (uint *)cpuid_Version_info(1);
      }
      else if (uVar9 == 2) {
        puVar2 = (uint *)cpuid_cache_tlb_info(2);
      }
      else if (uVar9 == 3) {
        puVar2 = (uint *)cpuid_serial_info(3);
      }
      else if (uVar9 == 4) {
        puVar2 = (uint *)cpuid_Deterministic_Cache_Parameters_info(4);
      }
      else if (uVar9 == 5) {
        puVar2 = (uint *)cpuid_MONITOR_MWAIT_Features_info(5);
      }
      else if (uVar9 == 6) {
        puVar2 = (uint *)cpuid_Thermal_Power_Management_info(6);
      }
      else if (uVar9 == 7) {
        puVar2 = (uint *)cpuid_Extended_Feature_Enumeration_info(7);
      }
      else if (uVar9 == 9) {
        puVar2 = (uint *)cpuid_Direct_Cache_Access_info(9);
      }
      else if (uVar9 == 10) {
        puVar2 = (uint *)cpuid_Architectural_Performance_Monitoring_info(10);
      }
      else if (uVar9 == 0xb) {
        puVar2 = (uint *)cpuid_Extended_Topology_info(0xb);
      }
      else if (uVar9 == 0xd) {
        puVar2 = (uint *)cpuid_Processor_Extended_States_info(0xd);
      }
      else if (uVar9 == 0xf) {
        puVar2 = (uint *)cpuid_Quality_of_Service_info(0xf);
      }
      else if (uVar9 == 0x80000002) {
        puVar2 = (uint *)cpuid_brand_part1_info(0x80000002);
      }
      else if (uVar9 == 0x80000003) {
        puVar2 = (uint *)cpuid_brand_part2_info(0x80000003);
      }
      else if (uVar9 == 0x80000004) {
        puVar2 = (uint *)cpuid_brand_part3_info(0x80000004);
      }
      else {
        puVar2 = (uint *)cpuid(uVar9);
      }
      local_28[0] = *puVar2;
      local_28[1] = puVar2[1];
      local_28[2] = puVar2[3];
      local_28[3] = puVar2[2];
      uVar11 = (uint)bVar1;
    }
    if (((int)uVar7 < (int)(uint)bVar1) ||
       ((local_28[pbVar10[0x37]] >> (pbVar10[0x38] & 0x1f) & 1) == 0)) {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | *(uint *)(pbVar10 + 0x3a);
    }
    bVar1 = pbVar10[0x3e];
    uVar9 = (uint)bVar1;
    if (uVar9 != uVar11) {
      if (uVar9 == 0) {
        puVar2 = (uint *)cpuid_basic_info(0);
      }
      else if (uVar9 == 1) {
        puVar2 = (uint *)cpuid_Version_info(1);
      }
      else if (uVar9 == 2) {
        puVar2 = (uint *)cpuid_cache_tlb_info(2);
      }
      else if (uVar9 == 3) {
        puVar2 = (uint *)cpuid_serial_info(3);
      }
      else if (uVar9 == 4) {
        puVar2 = (uint *)cpuid_Deterministic_Cache_Parameters_info(4);
      }
      else if (uVar9 == 5) {
        puVar2 = (uint *)cpuid_MONITOR_MWAIT_Features_info(5);
      }
      else if (uVar9 == 6) {
        puVar2 = (uint *)cpuid_Thermal_Power_Management_info(6);
      }
      else if (uVar9 == 7) {
        puVar2 = (uint *)cpuid_Extended_Feature_Enumeration_info(7);
      }
      else if (uVar9 == 9) {
        puVar2 = (uint *)cpuid_Direct_Cache_Access_info(9);
      }
      else if (uVar9 == 10) {
        puVar2 = (uint *)cpuid_Architectural_Performance_Monitoring_info(10);
      }
      else if (uVar9 == 0xb) {
        puVar2 = (uint *)cpuid_Extended_Topology_info(0xb);
      }
      else if (uVar9 == 0xd) {
        puVar2 = (uint *)cpuid_Processor_Extended_States_info(0xd);
      }
      else if (uVar9 == 0xf) {
        puVar2 = (uint *)cpuid_Quality_of_Service_info(0xf);
      }
      else if (uVar9 == 0x80000002) {
        puVar2 = (uint *)cpuid_brand_part1_info(0x80000002);
      }
      else if (uVar9 == 0x80000003) {
        puVar2 = (uint *)cpuid_brand_part2_info(0x80000003);
      }
      else if (uVar9 == 0x80000004) {
        puVar2 = (uint *)cpuid_brand_part3_info(0x80000004);
      }
      else {
        puVar2 = (uint *)cpuid(uVar9);
      }
      local_28[0] = *puVar2;
      local_28[1] = puVar2[1];
      local_28[2] = puVar2[3];
      local_28[3] = puVar2[2];
      uVar11 = (uint)bVar1;
    }
    if (((int)uVar7 < (int)(uint)bVar1) ||
       ((local_28[pbVar10[0x3f]] >> (pbVar10[0x40] & 0x1f) & 1) == 0)) {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | *(uint *)(pbVar10 + 0x42);
    }
    uVar8 = uVar8 + 10;
    pbVar10 = pbVar10 + 0x50;
  } while (uVar8 < 0x14);
  lVar3 = cpuid_Version_info(1);
  if ((*(uint *)(lVar3 + 0xc) >> 0x1b & 1) == 0) {
LAB_1800075d8:
    g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 0x10;
  }
  else {
    uVar6 = xinuse(0);
    bVar1 = in_XCR0 & (byte)uVar6;
    if ((bVar1 & 6) != 6) goto LAB_1800075d8;
    if ((bVar1 & 0xe0) == 0xe0) goto LAB_1800075e1;
  }
  g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 0x1000;
LAB_1800075e1:
  if ((g_SymCryptCpuFeaturesNotPresent & 4) == 0) {
    lVar3 = cpuid_basic_info(0);
    if (((*(int *)(lVar3 + 4) == 0x68747541) && (*(int *)(lVar3 + 0xc) == 0x444d4163)) &&
       (*(int *)(lVar3 + 8) == 0x69746e65)) {
      piVar4 = (int *)cpuid_Version_info(1);
      uVar7 = *piVar4 >> 8 & 0xf;
      if ((uVar7 < 0xf) || ((*piVar4 >> 0x14 & 0xffU) + uVar7 < 0x15)) {
        g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 4;
      }
    }
  }
  puVar5 = (undefined4 *)cpuid_Version_info(1);
  _g_SymCryptCpuid1 = *puVar5;
  _DAT_18001a194 = puVar5[1];
  _DAT_18001a198 = puVar5[3];
  _DAT_18001a19c = puVar5[2];
  return;
}



===== SymCryptAes4Sbox @ 180007680 =====

void SymCryptAes4Sbox(byte *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 auVar2 [16];
  
  if (param_3 == 0) {
    *(undefined *)param_2 = (&DAT_180015c01)[(ulonglong)*param_1 * 4];
    *(undefined *)((longlong)param_2 + 1) = (&DAT_180015c01)[(ulonglong)param_1[1] * 4];
    *(undefined *)((longlong)param_2 + 2) = (&DAT_180015c01)[(ulonglong)param_1[2] * 4];
    *(undefined *)((longlong)param_2 + 3) = (&DAT_180015c01)[(ulonglong)param_1[3] * 4];
    return;
  }
  uVar1 = *(undefined4 *)param_1;
  auVar2._4_4_ = uVar1;
  auVar2._0_4_ = uVar1;
  auVar2._8_4_ = uVar1;
  auVar2._12_4_ = uVar1;
  auVar2 = aeskeygenassist(auVar2,0);
  *param_2 = auVar2._0_4_;
  return;
}



===== SymCryptAesCbcEncryptXmm @ 1800076e0 =====

void SymCryptAesCbcEncryptXmm
               (uint *param_1,undefined1 (*param_2) [16],uint *param_3,undefined1 (*param_4) [16],
               ulonglong param_5)

{
  undefined1 (*pauVar1) [16];
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 (*pauVar6) [16];
  ulonglong uVar7;
  undefined1 auVar8 [16];
  undefined1 auVar9 [16];
  undefined1 auVar10 [16];
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  uVar2 = *param_1;
  uVar3 = param_1[1];
  uVar4 = param_1[2];
  uVar5 = param_1[3];
  auVar10 = **(undefined1 (**) [16])(param_1 + 0x74);
  if (0xf < param_5) {
    auVar9._0_4_ = *param_3 ^ uVar2 ^ *(uint *)*param_2;
    auVar9._4_4_ = param_3[1] ^ uVar3 ^ *(uint *)(*param_2 + 4);
    auVar9._8_4_ = param_3[2] ^ uVar4 ^ *(uint *)(*param_2 + 8);
    auVar9._12_4_ = param_3[3] ^ uVar5 ^ *(uint *)(*param_2 + 0xc);
    if (0xf < param_5 - 0x10) {
      uVar7 = param_5 - 0x10 >> 4;
      do {
        pauVar6 = (undefined1 (*) [16])(param_1 + 8);
        uVar11 = param_3[4] ^ uVar2;
        uVar12 = param_3[5] ^ uVar3;
        uVar13 = param_3[6] ^ uVar4;
        uVar14 = param_3[7] ^ uVar5;
        auVar9 = aesenc(auVar9,*(undefined1 (*) [16])(param_1 + 4));
        do {
          auVar8 = *pauVar6;
          pauVar1 = pauVar6 + 1;
          pauVar6 = pauVar6 + 2;
          auVar9 = aesenc(auVar9,auVar8);
          auVar9 = aesenc(auVar9,*pauVar1);
        } while (pauVar6 < *(undefined1 (**) [16])(param_1 + 0x74));
        auVar8._0_4_ = uVar11 ^ auVar10._0_4_;
        auVar8._4_4_ = uVar12 ^ auVar10._4_4_;
        auVar8._8_4_ = uVar13 ^ auVar10._8_4_;
        auVar8._12_4_ = uVar14 ^ auVar10._12_4_;
        auVar9 = aesenclast(auVar9,auVar8);
        *(uint *)*param_4 = uVar11 ^ auVar9._0_4_;
        *(uint *)(*param_4 + 4) = uVar12 ^ auVar9._4_4_;
        *(uint *)(*param_4 + 8) = uVar13 ^ auVar9._8_4_;
        *(uint *)(*param_4 + 0xc) = uVar14 ^ auVar9._12_4_;
        param_4 = param_4 + 1;
        uVar7 = uVar7 - 1;
        param_3 = param_3 + 4;
      } while (uVar7 != 0);
    }
    pauVar6 = (undefined1 (*) [16])(param_1 + 8);
    auVar9 = aesenc(auVar9,*(undefined1 (*) [16])(param_1 + 4));
    do {
      auVar8 = *pauVar6;
      pauVar1 = pauVar6 + 1;
      pauVar6 = pauVar6 + 2;
      auVar9 = aesenc(auVar9,auVar8);
      auVar9 = aesenc(auVar9,*pauVar1);
    } while (pauVar6 < *(undefined1 (**) [16])(param_1 + 0x74));
    auVar10 = aesenclast(auVar9,auVar10);
    *param_4 = auVar10;
    *param_2 = auVar10;
  }
  return;
}



===== FveCryptInitialize @ 1800077e0 =====

undefined8
FveCryptInitialize(ushort *param_1,longlong param_2,uint param_3,uint *param_4,short param_5,
                  ushort param_6,uint param_7)

{
  undefined8 uVar1;
  short sVar2;
  
  uVar1 = 0;
  if (param_2 != 0) {
    if ((*(longlong *)(param_2 + 0x10) == 0) || (*(uint *)(param_2 + 0x18) < param_7)) {
      uVar1 = 0xc0000023;
    }
    else if (param_1[4] == param_6) {
      if ((0xe00 < param_3 - 0x200) || ((param_3 & param_3 - 1) != 0)) {
        *param_4 = param_7;
        return 0xc0210010;
      }
      uVar1 = 0;
      sVar2 = 0;
      if (0xb < *param_1) {
        sVar2 = *param_1 - 0xc;
      }
      if (sVar2 != param_5) {
        uVar1 = 0xc00000e4;
      }
    }
    else {
      uVar1 = 0xc0000024;
    }
  }
  *param_4 = param_7;
  return uVar1;
}



===== DumpPreInitialize @ 180007860 =====

void DumpPreInitialize(void)

{
                    /* 0x7860  1  DumpPreInitialize */
  wil_InitializeFeatureStaging();
  return;
}



===== ext_ms_win_ntos_ksr_l1_1_1_KsrFreePersistedMemory @ 180007880 =====

undefined8 ext_ms_win_ntos_ksr_l1_1_1_KsrFreePersistedMemory(void)

{
  return 0;
}



===== SymCryptXtsAesEncryptDataUnitXmm @ 18000788c =====

/* WARNING: Removing unreachable block (ram,0x00018000794e) */

void SymCryptXtsAesEncryptDataUnitXmm
               (uint *param_1,uint *param_2,ulonglong *param_3,ulonglong *param_4,
               undefined1 (*param_5) [16],longlong param_6)

{
  uint *puVar1;
  uint *puVar2;
  undefined1 (*pauVar3) [16];
  longlong lVar4;
  ulonglong uVar5;
  undefined1 (*pauVar6) [16];
  ulonglong *puVar7;
  longlong lVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined1 auVar12 [16];
  uint uVar13;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  undefined1 auVar14 [16];
  undefined1 auVar15 [16];
  undefined1 auVar16 [16];
  undefined1 auVar17 [16];
  uint uVar21;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  undefined1 auVar22 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  uint uVar32;
  uint uVar33;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  undefined1 auVar34 [16];
  uint uVar40;
  uint uVar41;
  uint uVar43;
  uint uVar44;
  uint uVar45;
  undefined1 auVar42 [16];
  undefined1 auVar46 [16];
  
  uVar5 = (ulonglong)((uint)param_6 & 0x7f);
  uVar33 = *param_2;
  uVar36 = param_2[1];
  uVar38 = param_2[2];
  uVar40 = param_2[3];
  pauVar3 = *(undefined1 (**) [16])(param_1 + 0x74);
  uVar41 = (int)uVar40 >> 0x1f & 0x87U ^ uVar33 << 1;
  uVar43 = (int)uVar33 >> 0x1f & 1U ^ uVar36 << 1;
  uVar44 = (int)uVar36 >> 0x1f & 1U ^ uVar38 << 1;
  uVar45 = (int)uVar38 >> 0x1f & 1U ^ uVar40 << 1;
  uVar27 = uVar40 >> 0x1c;
  uVar32 = (int)uVar45 >> 0x1f & 0x87U ^ uVar41 << 1;
  uVar35 = (int)uVar41 >> 0x1f & 1U ^ uVar43 << 1;
  uVar37 = (int)uVar43 >> 0x1f & 1U ^ uVar44 << 1;
  uVar39 = (int)uVar44 >> 0x1f & 1U ^ uVar45 << 1;
  uVar23 = uVar33 >> 0x1c ^ uVar36 << 4;
  uVar25 = uVar36 >> 0x1c ^ uVar38 << 4;
  uVar28 = uVar38 >> 0x1c ^ uVar40 << 4;
  uVar27 = uVar27 << 7 ^ uVar27 << 2 ^ uVar27 << 1 ^ uVar27 ^ uVar33 << 4;
  lVar4 = 0;
  if (uVar5 - 1 < 0xf) {
    lVar4 = 0x80;
  }
  uVar5 = uVar5 + lVar4;
  uVar21 = (int)uVar28 >> 0x1f & 0x87U ^ uVar27 << 1;
  uVar24 = (int)uVar27 >> 0x1f & 1U ^ uVar23 << 1;
  uVar26 = (int)uVar23 >> 0x1f & 1U ^ uVar25 << 1;
  uVar29 = (int)uVar25 >> 0x1f & 1U ^ uVar28 << 1;
  uVar13 = (int)uVar29 >> 0x1f & 0x87U ^ uVar21 << 1;
  uVar18 = (int)uVar21 >> 0x1f & 1U ^ uVar24 << 1;
  uVar19 = (int)uVar24 >> 0x1f & 1U ^ uVar26 << 1;
  uVar20 = (int)uVar26 >> 0x1f & 1U ^ uVar29 << 1;
  *(uint *)(param_3 + 0xe) = (int)uVar20 >> 0x1f & 0x87U ^ uVar13 << 1;
  *(uint *)((longlong)param_3 + 0x74) = (int)uVar13 >> 0x1f & 1U ^ uVar18 << 1;
  *(uint *)(param_3 + 0xf) = (int)uVar18 >> 0x1f & 1U ^ uVar19 << 1;
  *(uint *)((longlong)param_3 + 0x7c) = (int)uVar19 >> 0x1f & 1U ^ uVar20 << 1;
  *(uint *)param_3 = uVar33;
  *(uint *)((longlong)param_3 + 4) = uVar36;
  *(uint *)(param_3 + 1) = uVar38;
  *(uint *)((longlong)param_3 + 0xc) = uVar40;
  *(uint *)(param_3 + 2) = uVar41;
  *(uint *)((longlong)param_3 + 0x14) = uVar43;
  *(uint *)(param_3 + 3) = uVar44;
  *(uint *)((longlong)param_3 + 0x1c) = uVar45;
  *(uint *)(param_3 + 4) = uVar32;
  *(uint *)((longlong)param_3 + 0x24) = uVar35;
  *(uint *)(param_3 + 5) = uVar37;
  *(uint *)((longlong)param_3 + 0x2c) = uVar39;
  *(uint *)(param_3 + 6) = (int)uVar39 >> 0x1f & 0x87U ^ uVar32 << 1;
  *(uint *)((longlong)param_3 + 0x34) = (int)uVar32 >> 0x1f & 1U ^ uVar35 << 1;
  *(uint *)(param_3 + 7) = (int)uVar35 >> 0x1f & 1U ^ uVar37 << 1;
  *(uint *)((longlong)param_3 + 0x3c) = (int)uVar37 >> 0x1f & 1U ^ uVar39 << 1;
  *(uint *)(param_3 + 8) = uVar27;
  *(uint *)((longlong)param_3 + 0x44) = uVar23;
  *(uint *)(param_3 + 9) = uVar25;
  *(uint *)((longlong)param_3 + 0x4c) = uVar28;
  *(uint *)(param_3 + 10) = uVar21;
  *(uint *)((longlong)param_3 + 0x54) = uVar24;
  *(uint *)(param_3 + 0xb) = uVar26;
  *(uint *)((longlong)param_3 + 0x5c) = uVar29;
  *(uint *)(param_3 + 0xc) = uVar13;
  *(uint *)((longlong)param_3 + 100) = uVar18;
  *(uint *)(param_3 + 0xd) = uVar19;
  *(uint *)((longlong)param_3 + 0x6c) = uVar20;
  puVar1 = *(uint **)(param_1 + 0x74);
  uVar9 = param_3[0xe];
  uVar11 = param_3[0xf];
  uVar33 = *param_1;
  uVar36 = param_1[1];
  uVar38 = param_1[2];
  uVar40 = param_1[3];
  uVar23 = *puVar1;
  uVar25 = puVar1[1];
  uVar27 = puVar1[2];
  uVar28 = puVar1[3];
  if (param_6 - uVar5 != 0) {
    lVar4 = ((param_6 - uVar5) - 1 >> 7) + 1;
    do {
      pauVar6 = (undefined1 (*) [16])(param_1 + 4);
      auVar12._0_4_ = uVar33 ^ (uint)*param_3 ^ (uint)*param_4;
      auVar12._4_4_ = uVar36 ^ *(uint *)((longlong)param_3 + 4) ^ *(uint *)((longlong)param_4 + 4);
      auVar12._8_4_ = uVar38 ^ (uint)param_3[1] ^ (uint)param_4[1];
      auVar12._12_4_ =
           uVar40 ^ *(uint *)((longlong)param_3 + 0xc) ^ *(uint *)((longlong)param_4 + 0xc);
      lVar8 = 8;
      auVar14._0_4_ = uVar33 ^ (uint)param_3[2] ^ (uint)param_4[2];
      auVar14._4_4_ =
           uVar36 ^ *(uint *)((longlong)param_3 + 0x14) ^ *(uint *)((longlong)param_4 + 0x14);
      auVar14._8_4_ = uVar38 ^ (uint)param_3[3] ^ (uint)param_4[3];
      auVar14._12_4_ =
           uVar40 ^ *(uint *)((longlong)param_3 + 0x1c) ^ *(uint *)((longlong)param_4 + 0x1c);
      auVar22._0_4_ = uVar33 ^ (uint)param_3[4] ^ (uint)param_4[4];
      auVar22._4_4_ =
           uVar36 ^ *(uint *)((longlong)param_3 + 0x24) ^ *(uint *)((longlong)param_4 + 0x24);
      auVar22._8_4_ = uVar38 ^ (uint)param_3[5] ^ (uint)param_4[5];
      auVar22._12_4_ =
           uVar40 ^ *(uint *)((longlong)param_3 + 0x2c) ^ *(uint *)((longlong)param_4 + 0x2c);
      auVar30._0_4_ = uVar33 ^ (uint)param_3[6] ^ (uint)param_4[6];
      auVar30._4_4_ =
           uVar36 ^ *(uint *)((longlong)param_3 + 0x34) ^ *(uint *)((longlong)param_4 + 0x34);
      auVar30._8_4_ = uVar38 ^ (uint)param_3[7] ^ (uint)param_4[7];
      auVar30._12_4_ =
           uVar40 ^ *(uint *)((longlong)param_3 + 0x3c) ^ *(uint *)((longlong)param_4 + 0x3c);
      auVar31._0_4_ = uVar33 ^ (uint)param_3[8] ^ (uint)param_4[8];
      auVar31._4_4_ =
           uVar36 ^ *(uint *)((longlong)param_3 + 0x44) ^ *(uint *)((longlong)param_4 + 0x44);
      auVar31._8_4_ = uVar38 ^ (uint)param_3[9] ^ (uint)param_4[9];
      auVar31._12_4_ =
           uVar40 ^ *(uint *)((longlong)param_3 + 0x4c) ^ *(uint *)((longlong)param_4 + 0x4c);
      auVar34._0_4_ = uVar33 ^ (uint)param_3[10] ^ (uint)param_4[10];
      auVar34._4_4_ =
           uVar36 ^ *(uint *)((longlong)param_3 + 0x54) ^ *(uint *)((longlong)param_4 + 0x54);
      auVar34._8_4_ = uVar38 ^ (uint)param_3[0xb] ^ (uint)param_4[0xb];
      auVar34._12_4_ =
           uVar40 ^ *(uint *)((longlong)param_3 + 0x5c) ^ *(uint *)((longlong)param_4 + 0x5c);
      auVar42._0_4_ = uVar33 ^ (uint)param_3[0xc] ^ (uint)param_4[0xc];
      auVar42._4_4_ =
           uVar36 ^ *(uint *)((longlong)param_3 + 100) ^ *(uint *)((longlong)param_4 + 100);
      auVar42._8_4_ = uVar38 ^ (uint)param_3[0xd] ^ (uint)param_4[0xd];
      auVar42._12_4_ =
           uVar40 ^ *(uint *)((longlong)param_3 + 0x6c) ^ *(uint *)((longlong)param_4 + 0x6c);
      auVar46._0_4_ = uVar33 ^ (uint)param_3[0xe] ^ (uint)param_4[0xe];
      auVar46._4_4_ =
           uVar36 ^ *(uint *)((longlong)param_3 + 0x74) ^ *(uint *)((longlong)param_4 + 0x74);
      auVar46._8_4_ = uVar38 ^ (uint)param_3[0xf] ^ (uint)param_4[0xf];
      auVar46._12_4_ =
           uVar40 ^ *(uint *)((longlong)param_3 + 0x7c) ^ *(uint *)((longlong)param_4 + 0x7c);
      puVar7 = param_3;
      uVar10 = uVar11;
      do {
        auVar15 = *pauVar6;
        uVar11 = uVar9 >> 0x3f ^ uVar10 * 2;
        auVar12 = aesenc(auVar12,auVar15);
        auVar14 = aesenc(auVar14,auVar15);
        auVar22 = aesenc(auVar22,auVar15);
        auVar30 = aesenc(auVar30,auVar15);
        auVar31 = aesenc(auVar31,auVar15);
        auVar34 = aesenc(auVar34,auVar15);
        auVar42 = aesenc(auVar42,auVar15);
        auVar46 = aesenc(auVar46,auVar15);
        *(uint *)(puVar7 + 0x10) = uVar23 ^ (uint)*puVar7;
        *(uint *)((longlong)puVar7 + 0x84) = uVar25 ^ *(uint *)((longlong)puVar7 + 4);
        *(uint *)(puVar7 + 0x11) = uVar27 ^ (uint)puVar7[1];
        *(uint *)((longlong)puVar7 + 0x8c) = uVar28 ^ *(uint *)((longlong)puVar7 + 0xc);
        uVar9 = (ulonglong)((uint)((longlong)uVar10 >> 0x3f) & 0x87) ^ uVar9 * 2;
        pauVar6 = pauVar6 + 1;
        *puVar7 = uVar9;
        puVar7[1] = uVar11;
        puVar7 = puVar7 + 2;
        lVar8 = lVar8 + -1;
        uVar10 = uVar11;
      } while (lVar8 != 0);
      do {
        auVar15 = *pauVar6;
        pauVar6 = pauVar6 + 1;
        auVar12 = aesenc(auVar12,auVar15);
        auVar14 = aesenc(auVar14,auVar15);
        auVar22 = aesenc(auVar22,auVar15);
        auVar30 = aesenc(auVar30,auVar15);
        auVar31 = aesenc(auVar31,auVar15);
        auVar34 = aesenc(auVar34,auVar15);
        auVar42 = aesenc(auVar42,auVar15);
        auVar46 = aesenc(auVar46,auVar15);
      } while (pauVar6 < pauVar3);
      auVar12 = aesenclast(auVar12,*(undefined1 (*) [16])(param_3 + 0x10));
      *param_5 = auVar12;
      auVar12 = aesenclast(auVar14,*(undefined1 (*) [16])(param_3 + 0x12));
      param_5[1] = auVar12;
      param_4 = param_4 + 0x10;
      auVar12 = aesenclast(auVar22,*(undefined1 (*) [16])(param_3 + 0x14));
      param_5[2] = auVar12;
      auVar12 = aesenclast(auVar30,*(undefined1 (*) [16])(param_3 + 0x16));
      param_5[3] = auVar12;
      auVar12 = aesenclast(auVar31,*(undefined1 (*) [16])(param_3 + 0x18));
      param_5[4] = auVar12;
      auVar12 = aesenclast(auVar34,*(undefined1 (*) [16])(param_3 + 0x1a));
      param_5[5] = auVar12;
      auVar12 = aesenclast(auVar42,*(undefined1 (*) [16])(param_3 + 0x1c));
      param_5[6] = auVar12;
      auVar12 = aesenclast(auVar46,*(undefined1 (*) [16])(param_3 + 0x1e));
      param_5[7] = auVar12;
      param_5 = param_5 + 8;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
  }
  if (uVar5 != 0) {
    uVar33 = (uint)*param_3;
    uVar36 = *(uint *)((longlong)param_3 + 4);
    uVar38 = (uint)param_3[1];
    uVar40 = *(uint *)((longlong)param_3 + 0xc);
    if (0x1f < uVar5) {
      uVar9 = uVar5 - 0x10 >> 4;
      uVar5 = uVar5 + uVar9 * -0x10;
      do {
        uVar11 = *param_4;
        puVar1 = (uint *)((longlong)param_4 + 4);
        puVar7 = param_4 + 1;
        puVar2 = (uint *)((longlong)param_4 + 0xc);
        param_4 = param_4 + 2;
        pauVar3 = (undefined1 (*) [16])(param_1 + 8);
        auVar15._0_4_ = (uint)uVar11 ^ uVar33 ^ *param_1;
        auVar15._4_4_ = *puVar1 ^ uVar36 ^ param_1[1];
        auVar15._8_4_ = (uint)*puVar7 ^ uVar38 ^ param_1[2];
        auVar15._12_4_ = *puVar2 ^ uVar40 ^ param_1[3];
        auVar12 = aesenc(auVar15,*(undefined1 (*) [16])(param_1 + 4));
        do {
          auVar14 = *pauVar3;
          pauVar6 = pauVar3 + 1;
          pauVar3 = pauVar3 + 2;
          auVar12 = aesenc(auVar12,auVar14);
          auVar12 = aesenc(auVar12,*pauVar6);
        } while (pauVar3 < *(undefined1 (**) [16])(param_1 + 0x74));
        auVar12 = aesenclast(auVar12,*pauVar3);
        uVar23 = (int)uVar33 >> 0x1f;
        uVar25 = (int)uVar36 >> 0x1f;
        uVar27 = (int)uVar38 >> 0x1f;
        *(uint *)*param_5 = auVar12._0_4_ ^ uVar33;
        *(uint *)(*param_5 + 4) = auVar12._4_4_ ^ uVar36;
        *(uint *)(*param_5 + 8) = auVar12._8_4_ ^ uVar38;
        *(uint *)(*param_5 + 0xc) = auVar12._12_4_ ^ uVar40;
        param_5 = param_5 + 1;
        uVar33 = (int)uVar40 >> 0x1f & 0x87U ^ uVar33 << 1;
        uVar36 = uVar23 & 1 ^ uVar36 << 1;
        uVar38 = uVar25 & 1 ^ uVar38 << 1;
        uVar40 = uVar27 & 1 ^ uVar40 << 1;
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
    }
    if (0x10 < uVar5) {
      pauVar3 = (undefined1 (*) [16])(param_1 + 8);
      auVar16._0_4_ = (uint)*param_4 ^ uVar33 ^ *param_1;
      auVar16._4_4_ = *(uint *)((longlong)param_4 + 4) ^ uVar36 ^ param_1[1];
      auVar16._8_4_ = (uint)param_4[1] ^ uVar38 ^ param_1[2];
      auVar16._12_4_ = *(uint *)((longlong)param_4 + 0xc) ^ uVar40 ^ param_1[3];
      auVar12 = aesenc(auVar16,*(undefined1 (*) [16])(param_1 + 4));
      do {
        auVar14 = *pauVar3;
        pauVar6 = pauVar3 + 1;
        pauVar3 = pauVar3 + 2;
        auVar12 = aesenc(auVar12,auVar14);
        auVar12 = aesenc(auVar12,*pauVar6);
      } while (pauVar3 < *(undefined1 (**) [16])(param_1 + 0x74));
      auVar12 = aesenclast(auVar12,*pauVar3);
      uVar23 = auVar12._0_4_ ^ uVar33;
      uVar25 = auVar12._4_4_ ^ uVar36;
      uVar27 = auVar12._8_4_ ^ uVar38;
      uVar28 = auVar12._12_4_ ^ uVar40;
      *(uint *)param_3 = uVar23;
      *(uint *)((longlong)param_3 + 4) = uVar25;
      *(uint *)(param_3 + 1) = uVar27;
      *(uint *)((longlong)param_3 + 0xc) = uVar28;
      *(uint *)(param_3 + 2) = uVar23;
      *(uint *)((longlong)param_3 + 0x14) = uVar25;
      *(uint *)(param_3 + 3) = uVar27;
      *(uint *)((longlong)param_3 + 0x1c) = uVar28;
      memmove(param_3,param_4 + 2,uVar5 - 0x10);
      memmove(param_5 + 1,param_3 + 2,uVar5 - 0x10);
      uVar23 = (int)uVar33 >> 0x1f;
      uVar25 = (int)uVar36 >> 0x1f;
      uVar27 = (int)uVar38 >> 0x1f;
      uVar33 = (int)uVar40 >> 0x1f & 0x87U ^ uVar33 << 1;
      uVar36 = uVar23 & 1 ^ uVar36 << 1;
      uVar38 = uVar25 & 1 ^ uVar38 << 1;
      uVar40 = uVar27 & 1 ^ uVar40 << 1;
      param_4 = param_3;
    }
    pauVar3 = (undefined1 (*) [16])(param_1 + 8);
    auVar17._0_4_ = (uint)*param_4 ^ uVar33 ^ *param_1;
    auVar17._4_4_ = *(uint *)((longlong)param_4 + 4) ^ uVar36 ^ param_1[1];
    auVar17._8_4_ = (uint)param_4[1] ^ uVar38 ^ param_1[2];
    auVar17._12_4_ = *(uint *)((longlong)param_4 + 0xc) ^ uVar40 ^ param_1[3];
    auVar12 = aesenc(auVar17,*(undefined1 (*) [16])(param_1 + 4));
    do {
      auVar14 = *pauVar3;
      pauVar6 = pauVar3 + 1;
      pauVar3 = pauVar3 + 2;
      auVar12 = aesenc(auVar12,auVar14);
      auVar12 = aesenc(auVar12,*pauVar6);
    } while (pauVar3 < *(undefined1 (**) [16])(param_1 + 0x74));
    auVar12 = aesenclast(auVar12,*pauVar3);
    *(uint *)*param_5 = auVar12._0_4_ ^ uVar33;
    *(uint *)(*param_5 + 4) = auVar12._4_4_ ^ uVar36;
    *(uint *)(*param_5 + 8) = auVar12._8_4_ ^ uVar38;
    *(uint *)(*param_5 + 0xc) = auVar12._12_4_ ^ uVar40;
  }
  return;
}



===== DumpUninitialize @ 180007e40 =====

void DumpUninitialize(void)

{
                    /* 0x7e40  2  DumpUninitialize */
  wil_UninitializeFeatureStaging();
  return;
}



===== wil_details_FeatureDescriptors_SkipPadding @ 180007e58 =====

longlong * wil_details_FeatureDescriptors_SkipPadding(longlong *param_1)

{
  while( true ) {
    if (&UNK_18001954f < param_1) {
      return (longlong *)0x0;
    }
    if (*param_1 != 0) break;
    param_1 = param_1 + 1;
  }
  return param_1;
}



===== FveAesDestroyKey @ 180007e84 =====

undefined8 FveAesDestroyKey(undefined8 *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  
  if (param_1 == (undefined8 *)0x0) {
    uVar1 = 0xc000000d;
  }
  else {
    SymCryptWipeAsm(param_1,0x1f0);
    uVar1 = 0;
    for (lVar2 = 0x1f0; lVar2 != 0; lVar2 = lVar2 + -1) {
      *(undefined1 *)param_1 = 0;
      param_1 = (undefined8 *)((longlong)param_1 + 1);
    }
  }
  return uVar1;
}



===== FveInitializeCrypto @ 180007ebc =====

undefined8 FveInitializeCrypto(ulonglong *param_1,undefined8 *param_2,uint param_3,uint *param_4)

{
  undefined8 uVar1;
  int iVar2;
  short sVar3;
  ushort uVar4;
  
  uVar1 = FveDatumMustBe(param_1,param_2);
  if (-1 < (int)uVar1) {
    sVar3 = (short)param_1[1];
    if (sVar3 == -0x8000) {
      uVar4 = 0x8000;
      iVar2 = 0x10;
    }
    else {
      if (sVar3 != -0x7fff) {
        if (sVar3 == -0x7ffe) {
          iVar2 = 0x10;
          uVar4 = 0x8002;
        }
        else {
          if (sVar3 != -0x7ffd) {
            if (sVar3 == -0x7ffc) {
              uVar4 = 0x8004;
              sVar3 = 0x20;
              iVar2 = 0x20;
            }
            else {
              if (sVar3 != -0x7ffb) {
                return 0xc00000e4;
              }
              uVar4 = 0x8005;
              sVar3 = 0x40;
              iVar2 = 0x40;
            }
            uVar1 = FveCryptInitializeXtsAes
                              ((ushort *)param_1,param_2,param_3,param_4,iVar2,sVar3,uVar4);
            return uVar1;
          }
          iVar2 = 0x20;
          uVar4 = 0x8003;
        }
        uVar1 = FveCryptInitializeAes
                          ((ushort *)param_1,param_2,param_3,param_4,iVar2,(short)iVar2,uVar4);
        return uVar1;
      }
      uVar4 = 0x8001;
      iVar2 = 0x20;
    }
    uVar1 = FveCryptInitializeElephant((ushort *)param_1,param_2,param_3,param_4,iVar2,iVar2,uVar4);
  }
  return uVar1;
}



===== FveAesCbcEncryptSectors @ 180007fe4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FveAesCbcEncryptSectors
                    (uint *param_1,longlong param_2,uint *param_3,uint param_4,
                    undefined1 (*param_5) [16],uint param_6)

{
  longlong *plVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined1 auStackY_188 [32];
  longlong local_148 [32];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_188;
  uVar6 = (ulonglong)param_6;
  uVar2 = param_4 / uVar6;
  uVar3 = 0;
  uVar5 = (uint)uVar2;
  do {
    if (uVar5 == 0) {
      return uVar3;
    }
    if ((uint)uVar2 < 0x10) {
      if ((uint)uVar2 != 0) goto LAB_180008059;
      uVar4 = 0;
    }
    else {
      uVar2 = 0x10;
LAB_180008059:
      plVar1 = local_148 + 1;
      uVar4 = (uint)uVar2;
      uVar3 = uVar2;
      do {
        *plVar1 = 0;
        plVar1[-1] = param_2;
        plVar1 = plVar1 + 2;
        param_2 = param_2 + uVar6;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    uVar2 = FveAesEcbEncrypt(param_1,(longlong)local_148,uVar2 << 4,(undefined1 (*) [16])local_148);
    uVar3 = uVar2 & 0xffffffff;
    if ((int)uVar2 < 0) {
      return uVar3;
    }
    for (uVar2 = 0; (uint)uVar2 < uVar4; uVar2 = (ulonglong)((uint)uVar2 + 1)) {
      SymCryptAesCbcEncrypt
                (param_1,(undefined1 (*) [16])(local_148 + uVar2 * 2),param_3,param_5,uVar6);
      uVar3 = 0;
      param_3 = (uint *)((longlong)param_3 + uVar6);
      param_5 = (undefined1 (*) [16])(*param_5 + uVar6);
    }
    uVar5 = uVar5 - uVar4;
    uVar2 = (ulonglong)uVar5;
  } while( true );
}



===== SymCryptHashAppendInternal @ 180008118 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptHashAppendInternal(undefined8 param_1,uint *param_2,void *param_3,ulonglong param_4)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong _Size;
  undefined1 auStack_58 [32];
  ulonglong local_38;
  ulonglong local_30;
  
  local_30 = __security_cookie ^ (ulonglong)auStack_58;
  local_38 = 0;
  *(ulonglong *)(param_2 + 4) = *(longlong *)(param_2 + 4) + param_4;
  if (*(ulonglong *)(param_2 + 4) < param_4) {
    *(longlong *)(param_2 + 6) = *(longlong *)(param_2 + 6) + 1;
  }
  uVar1 = *param_2;
  uVar2 = (ulonglong)uVar1;
  if ((uVar1 != 0) && (_Size = (ulonglong)(0x40 - uVar1), _Size <= param_4)) {
    memmove((void *)(uVar2 + 0x20 + (longlong)param_2),param_3,_Size);
    param_3 = (void *)((longlong)param_3 + _Size);
    param_4 = param_4 - _Size;
    SymCryptSha1AppendBlocks(param_2 + 0x18,(longlong)(param_2 + 8),0x40,&local_38);
    uVar2 = 0;
  }
  uVar1 = (uint)uVar2;
  if (0x3f < param_4) {
    SymCryptSha1AppendBlocks(param_2 + 0x18,(longlong)param_3,param_4,&local_38);
    param_3 = (void *)((longlong)param_3 + (param_4 - local_38));
    param_4 = local_38;
  }
  if (param_4 != 0) {
    memmove((void *)(uVar2 + 0x20 + (longlong)param_2),param_3,param_4);
    uVar1 = uVar1 + (int)param_4;
  }
  *param_2 = uVar1;
  return;
}



===== DriverEntry @ 180008200 =====

int DriverEntry(uint *param_1,undefined4 *param_2,undefined8 param_3,uint param_4)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  uint *puVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  code *pcVar7;
  undefined1 **ppuVar8;
  undefined1 *puVar9;
  undefined1 **ppuVar10;
  char local_res8 [8];
  undefined1 **local_res10;
  undefined1 *local_res18;
  undefined8 local_res20;
  undefined8 local_98;
  undefined8 local_90;
  wchar_t *local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 *local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulonglong uStack_58;
  
  local_90 = 0x2c002a;
  local_res20 = 0;
  param_2[0xd] = param_2[0xd] | 1;
  local_60 = 0;
  uStack_58 = uStack_58 & 0xffffffff00000000;
  local_98 = 0;
  local_88 = L"\\Callback\\SoftRestart";
  ppuVar10 = (undefined1 **)0x0;
  local_80 = 0;
  uStack_78 = 0;
  local_res8[0] = '\0';
  local_70 = (undefined8 *)0x0;
  uStack_68 = 0;
  local_res10 = (undefined1 **)0x0;
  local_res18 = (undefined1 *)0x0;
  Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledDeviceUsageNoInline();
  if (0x10000 < (uint)param_2[0xc]) {
    return -0x3ffffff3;
  }
  puVar4 = (uint *)ExAllocatePool2(0x40,0x4000,0x45564664);
  if (puVar4 == (uint *)0x0) {
    return -0x3fffff66;
  }
  memset(puVar4 + 1,0,0xc0);
  ppuVar8 = (undefined1 **)0x0;
  memset(puVar4 + 0x35,0,0x3f2c);
  *puVar4 = 0x4000;
  puVar4[0x31] = 0x45564664;
  *(uint **)(puVar4 + 0x32) = puVar4;
  puVar4[0x34] = 0x4000;
  puVar4[4] = *param_1;
  uVar5 = Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline();
  pcVar7 = DumpUpdateKeyMaterialCallback;
  if ((int)uVar5 == 0) {
    pcVar7 = (code *)0x0;
  }
  *(code **)(puVar4 + 0x50) = pcVar7;
  *(undefined1 *)((longlong)puVar4 + 0x13d) = 0;
  iVar3 = KsrGetFirmwareInformation(&local_98);
  if (-1 < iVar3) {
    puVar4[3] = puVar4[3] | 1;
    cVar2 = ExIsSoftBoot();
    if (cVar2 != '\0') {
      uVar1 = puVar4[3];
      puVar4[3] = uVar1 | 2;
      if (*param_1 != 1) goto LAB_180008383;
      if ((param_2[0xd] & 8) != 0) {
        puVar4[3] = uVar1 | 6;
      }
    }
    if ((*param_1 == 1) && ((param_2[0xd] & 0x10) != 0)) {
      puVar4[3] = puVar4[3] | 0x40;
    }
  }
LAB_180008383:
  if ((puVar4[3] & 4) == 0) {
    puVar9 = (undefined1 *)0x0;
    if ((puVar4[3] & 2) != 0) {
      ppuVar8 = &local_res18;
      iVar3 = DumpKsrGetContextFromKsrMemory(&local_res10,ppuVar8);
      puVar9 = local_res18;
      ppuVar10 = local_res10;
      if (-1 < iVar3) {
        if (local_res18 != (undefined1 *)0x0) {
          FveDmpSecureZeroAndFlush(local_res18,*(uint *)(local_res18 + 8));
          ppuVar8 = ppuVar10;
          MmUnmapLockedPages(puVar9);
          local_res18 = (undefined1 *)0x0;
        }
        puVar9 = local_res18;
        if (ppuVar10 != (undefined1 **)0x0) {
          ppuVar8 = (undefined1 **)0x45564664;
          ExFreePoolWithTag(ppuVar10);
          ppuVar10 = (undefined1 **)0x0;
          local_res10 = (undefined1 **)0x0;
        }
      }
    }
    if ((puVar4[3] & 0x40) == 0) {
LAB_1800085a8:
      iVar3 = GetFveContext((int *)param_1,(longlong)param_2,param_2[0xc],
                            (int *)((ulonglong)
                                    CONCAT31((uint3)((uint)param_2[0xd] >> 10),
                                             (char)((uint)param_2[0xd] >> 2)) & 0xffffffffffffff01),
                            puVar4);
      if (-1 < iVar3) {
LAB_1800085d3:
        puVar4[2] = param_2[0xd];
        *(code **)(param_2 + 2) = DumpStart;
        *(code **)(param_2 + 4) = DumpWrite;
        *(code **)(param_2 + 6) = ext_ms_win_ntos_ksr_l1_1_1_KsrFreePersistedMemory;
        *(code **)(param_2 + 8) = DumpUnload;
        *(uint **)(param_2 + 10) = puVar4;
        if ((param_2[0xd] & 1) != 0) {
          *param_2 = 2;
          *(code **)(param_2 + 0xe) = DumpRead;
        }
        uVar5 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar5 != 0) {
          *(undefined8 *)(param_2 + 4) = 0;
          *(code **)(param_2 + 0x10) = DumpPreReadWrite;
        }
        goto LAB_1800083fe;
      }
    }
    else {
      iVar3 = DumpGetKsrAllowedForVolume((longlong)puVar4,(ulonglong)ppuVar8,local_res8,param_4);
      if ((-1 < iVar3) && (local_res8[0] != '\0')) {
        puVar4[3] = puVar4[3] | 8;
      }
      local_70 = &local_90;
      local_80 = CONCAT44(local_80._4_4_,0x30);
      uStack_78 = 0;
      uStack_68 = CONCAT44(uStack_68._4_4_,0x240);
      local_60 = 0;
      uStack_58 = 0;
      iVar3 = ExCreateCallback(&local_res20,&local_80,0,0);
      if (-1 < iVar3) {
        uVar6 = ExRegisterCallback(local_res20,DumpKsrNotifyCallbackRoutine,puVar4);
        *(undefined8 *)(puVar4 + 6) = uVar6;
        ObfDereferenceObject(local_res20);
        if (*(longlong *)(puVar4 + 6) != 0) goto LAB_1800085a8;
        iVar3 = -0x3fffffff;
      }
    }
  }
  else {
    iVar3 = DumpKsrGetContextFromKsrMemory(&local_res10,&local_res18);
    puVar9 = local_res18;
    if (-1 < iVar3) {
      if ((*(uint *)(local_res18 + 0xc) & 4) == 0) {
        uVar5 = GetFveContextFromKsrForEarlyCrashDump
                          ((longlong)param_1,(longlong)param_2,param_2[0xc],
                           (byte)((uint)param_2[0xd] >> 2) & 1,puVar4,(longlong)local_res18);
        iVar3 = (int)uVar5;
        if (-1 < iVar3) {
          ppuVar10 = local_res10;
          goto LAB_1800085d3;
        }
      }
      else {
        iVar3 = -0x3fffff45;
      }
    }
  }
  if (*(longlong *)(puVar4 + 6) != 0) {
    ExUnregisterCallback();
    puVar4[6] = 0;
    puVar4[7] = 0;
  }
  if ((puVar4[0x30] & 2) == 0) {
    ExFreePoolWithTag(puVar4,0x45564664);
  }
  puVar9 = local_res18;
  ppuVar10 = local_res10;
LAB_1800083fe:
  if (puVar9 != (undefined1 *)0x0) {
    FveDmpSecureZeroAndFlush(puVar9,*(uint *)(puVar9 + 8));
    MmUnmapLockedPages(puVar9,ppuVar10);
  }
  if (ppuVar10 != (undefined1 **)0x0) {
    ExFreePoolWithTag(ppuVar10,0x45564664);
  }
  return iVar3;
}



===== DumpUnload @ 180008650 =====

undefined8 DumpUnload(longlong param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 *puVar1;
  byte bVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined1 *puVar5;
  
  LOCK();
  puVar1 = *(undefined1 **)(param_1 + 0x48);
  *(undefined8 *)(param_1 + 0x48) = 0;
  UNLOCK();
  if (puVar1 != (undefined1 *)0x0) {
    if (*(longlong *)(puVar1 + 0x18) != 0) {
      ExUnregisterCallback();
      *(undefined8 *)(puVar1 + 0x18) = 0;
    }
    if ((*(uint *)(puVar1 + 0xc) & 0x20) == 0) {
      puVar5 = *(undefined1 **)(puVar1 + 0x28);
      if (puVar5 != (undefined1 *)0x0) {
        bVar2 = KeGetCurrentIrql();
        if (bVar2 < 2) {
          bVar2 = KfRaiseIrql(2);
        }
        for (lVar4 = 0x88; lVar4 != 0; lVar4 = lVar4 + -1) {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
        }
        KeSweepLocalCaches();
        if (bVar2 < 2) {
          KeLowerIrql(bVar2);
        }
        if (*(longlong *)(puVar1 + 0x20) != 0) {
          MmUnmapLockedPages(*(undefined8 *)(puVar1 + 0x28));
        }
        *(undefined8 *)(puVar1 + 0x28) = 0;
      }
      KsrFreePersistedMemory(&DAT_180015bc8,*(longlong *)(puVar1 + 0x20) == 0);
      if (*(longlong *)(puVar1 + 0x20) != 0) {
        MmFreePagesFromMdl();
        ExFreePoolWithTag(*(undefined8 *)(puVar1 + 0x20),0);
        *(undefined8 *)(puVar1 + 0x20) = 0;
      }
    }
    if (((*(uint *)(puVar1 + 0xc) & 4) == 0) && (*(longlong *)(param_1 + 8) != 0)) {
      uVar3 = SendDeviceIoControl(0x4556d0c7,*(longlong *)(param_1 + 8),param_3,param_4,
                                  puVar1 + 0x30);
      if ((int)uVar3 < 0) {
        FveDestroyCryptoKeyData((longlong)(puVar1 + 0x198));
        uVar3 = Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline();
        if ((int)uVar3 != 0) {
          FveDestroyCryptoKeyData((longlong)(puVar1 + 0x218));
          FveDmpSecureZeroAndFlush(puVar1 + 0x1c8,0x4d);
          FveDmpSecureZeroAndFlush(puVar1 + 0x218,0x20);
        }
        FveDmpSecureZeroAndFlush(puVar1 + 0x58,0x4d);
        FveDmpSecureZeroAndFlush(puVar1 + 0x148,0x4d);
        FveDmpSecureZeroAndFlush(puVar1 + 0x198,0x20);
        FveDmpSecureZeroAndFlush(puVar1 + 0x240,0x3be1);
        *(uint *)(puVar1 + 0xc0) = *(uint *)(puVar1 + 0xc0) | 2;
        return 0;
      }
      if (*(undefined1 **)(puVar1 + 0x48) != (undefined1 *)0x0) {
        FveDmpSecureZeroAndFlush(*(undefined1 **)(puVar1 + 0x48),*(uint *)(puVar1 + 0x44));
        MmFreeContiguousMemory(*(undefined8 *)(puVar1 + 0x48));
        *(undefined8 *)(puVar1 + 0x48) = 0;
      }
      FveDmpSecureZeroAndFlush(puVar1,0x4000);
    }
    else {
      if (*(undefined1 **)(puVar1 + 0x48) != (undefined1 *)0x0) {
        FveDmpSecureZeroAndFlush(*(undefined1 **)(puVar1 + 0x48),*(uint *)(puVar1 + 0x44));
        MmFreeContiguousMemory(*(undefined8 *)(puVar1 + 0x48));
        *(undefined8 *)(puVar1 + 0x48) = 0;
      }
      bVar2 = KeGetCurrentIrql();
      if (bVar2 < 2) {
        bVar2 = KfRaiseIrql(2);
      }
      puVar5 = puVar1;
      for (lVar4 = 0x4000; lVar4 != 0; lVar4 = lVar4 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      KeSweepLocalCaches();
      if (bVar2 < 2) {
        KeLowerIrql(bVar2);
      }
    }
    ExFreePoolWithTag(puVar1,0x45564664);
  }
  return 0;
}



===== FveInitCrypto @ 18000890c =====

ulonglong FveInitCrypto(int *param_1)

{
  int *piVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  int *piVar6;
  ulonglong *puVar7;
  uint *puVar8;
  
  piVar1 = param_1 + 0x66;
  piVar6 = param_1 + 0x86;
  uVar5 = 0;
  puVar7 = (ulonglong *)(param_1 + 0x52);
  uVar3 = Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 == 0) {
    lVar4 = RtlCompareMemory(puVar7,param_1 + 0x16,0x4d);
    if (lVar4 == 0x4d) {
      return 0;
    }
    puVar8 = (uint *)(param_1 + 0x6c);
    *puVar7 = *(ulonglong *)(param_1 + 0x16);
    *(undefined8 *)(param_1 + 0x54) = *(undefined8 *)(param_1 + 0x18);
    *(undefined8 *)(param_1 + 0x56) = *(undefined8 *)(param_1 + 0x1a);
    *(undefined8 *)(param_1 + 0x58) = *(undefined8 *)(param_1 + 0x1c);
    *(undefined8 *)(param_1 + 0x5a) = *(undefined8 *)(param_1 + 0x1e);
    *(undefined8 *)(param_1 + 0x5c) = *(undefined8 *)(param_1 + 0x20);
    *(undefined8 *)(param_1 + 0x5e) = *(undefined8 *)(param_1 + 0x22);
    *(undefined8 *)(param_1 + 0x60) = *(undefined8 *)(param_1 + 0x24);
    *(undefined8 *)(param_1 + 0x62) = *(undefined8 *)(param_1 + 0x26);
    param_1[100] = param_1[0x28];
    *(char *)(param_1 + 0x65) = (char)param_1[0x29];
    iVar2 = param_1[0x54];
    piVar1[0] = 0;
    piVar1[1] = 0;
    param_1[0x68] = 0;
    param_1[0x69] = 0;
    *(short *)(param_1 + 0x6d) = (short)iVar2;
    *(int **)(param_1 + 0x6a) = param_1 + 0x90;
    piVar6 = piVar1;
  }
  else {
    if (*(char *)((longlong)param_1 + 0x13d) == '\0') {
      FveDestroyCryptoKeyData((longlong)piVar1);
      FveDmpSecureZeroAndFlush((undefined1 *)piVar1,0x20);
      FveDmpSecureZeroAndFlush((undefined1 *)puVar7,0x4d);
    }
    else {
      lVar4 = RtlCompareMemory(puVar7,param_1 + 0x16,0x4d);
      if (lVar4 != 0x4d) {
        *puVar7 = *(ulonglong *)(param_1 + 0x16);
        *(undefined8 *)(param_1 + 0x54) = *(undefined8 *)(param_1 + 0x18);
        *(undefined8 *)(param_1 + 0x56) = *(undefined8 *)(param_1 + 0x1a);
        *(undefined8 *)(param_1 + 0x58) = *(undefined8 *)(param_1 + 0x1c);
        *(undefined8 *)(param_1 + 0x5a) = *(undefined8 *)(param_1 + 0x1e);
        *(undefined8 *)(param_1 + 0x5c) = *(undefined8 *)(param_1 + 0x20);
        *(undefined8 *)(param_1 + 0x5e) = *(undefined8 *)(param_1 + 0x22);
        *(undefined8 *)(param_1 + 0x60) = *(undefined8 *)(param_1 + 0x24);
        *(undefined8 *)(param_1 + 0x62) = *(undefined8 *)(param_1 + 0x26);
        param_1[100] = param_1[0x28];
        *(char *)(param_1 + 0x65) = (char)param_1[0x29];
        iVar2 = param_1[0x54];
        piVar1[0] = 0;
        piVar1[1] = 0;
        param_1[0x68] = 0;
        param_1[0x69] = 0;
        *(short *)(param_1 + 0x6d) = (short)iVar2;
        *(int **)(param_1 + 0x6a) = param_1 + 0x90;
        param_1[0x6c] = *param_1 - 0x240;
        uVar5 = FveInitializeCrypto(puVar7,(undefined8 *)piVar1,param_1[1],(uint *)(param_1 + 0x6c))
        ;
        uVar5 = uVar5 & 0xffffffff;
      }
    }
    if ((param_1[0x30] & 0x20U) == 0) {
      return uVar5;
    }
    puVar7 = (ulonglong *)(param_1 + 0x72);
    lVar4 = RtlCompareMemory(puVar7,param_1 + 0x3c,0x4d);
    if (lVar4 == 0x4d) {
      return uVar5;
    }
    puVar8 = (uint *)(param_1 + 0x8c);
    *puVar7 = *(ulonglong *)(param_1 + 0x3c);
    *(undefined8 *)(param_1 + 0x74) = *(undefined8 *)(param_1 + 0x3e);
    *(undefined8 *)(param_1 + 0x76) = *(undefined8 *)(param_1 + 0x40);
    *(undefined8 *)(param_1 + 0x78) = *(undefined8 *)(param_1 + 0x42);
    *(undefined8 *)(param_1 + 0x7a) = *(undefined8 *)(param_1 + 0x44);
    *(undefined8 *)(param_1 + 0x7c) = *(undefined8 *)(param_1 + 0x46);
    *(undefined8 *)(param_1 + 0x7e) = *(undefined8 *)(param_1 + 0x48);
    *(undefined8 *)(param_1 + 0x80) = *(undefined8 *)(param_1 + 0x4a);
    *(undefined8 *)(param_1 + 0x82) = *(undefined8 *)(param_1 + 0x4c);
    param_1[0x84] = param_1[0x4e];
    *(char *)(param_1 + 0x85) = (char)param_1[0x4f];
    iVar2 = param_1[0x74];
    piVar6[0] = 0;
    piVar6[1] = 0;
    param_1[0x88] = 0;
    param_1[0x89] = 0;
    *(short *)(param_1 + 0x8d) = (short)iVar2;
    *(int **)(param_1 + 0x8a) = param_1 + 0x90;
  }
  *puVar8 = *param_1 - 0x240;
  uVar3 = FveInitializeCrypto(puVar7,(undefined8 *)piVar6,param_1[1],puVar8);
  return uVar3 & 0xffffffff;
}



===== GetFveContext @ 180008b80 =====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int GetFveContext(int *param_1,longlong param_2,int param_3,int *param_4,uint *param_5)

{
  uint *puVar1;
  uint uVar2;
  undefined1 *puVar3;
  bool bVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  char *pcVar8;
  longlong lVar9;
  undefined1 (*pauVar10) [16];
  ulonglong *puVar11;
  undefined *puVar12;
  ulonglong *puVar13;
  ulonglong *puVar14;
  int iVar15;
  int *piVar16;
  uint *puVar17;
  uint uVar18;
  undefined8 uVar19;
  uint uVar20;
  int *piVar21;
  byte bVar22;
  ulonglong uVar23;
  undefined1 (*pauVar24) [16];
  undefined8 in_CR8;
  undefined1 auStackY_1388 [32];
  undefined8 in_stack_ffffffffffffec98;
  undefined1 (*local_1328) [16];
  int local_12f8;
  int local_12f4 [3];
  uint local_12e8 [20];
  undefined8 local_1298;
  undefined8 uStack_1290;
  undefined8 local_1288;
  undefined8 uStack_1280;
  undefined8 local_1278;
  undefined8 uStack_1270;
  undefined8 local_1268;
  undefined8 uStack_1260;
  undefined8 local_1258;
  undefined8 uStack_1250;
  undefined8 local_1248;
  undefined8 uStack_1240;
  undefined8 local_1238;
  undefined8 uStack_1230;
  undefined8 local_1228;
  undefined8 uStack_1220;
  uint local_1218 [20];
  ulonglong local_11c8 [62];
  uint local_fd8 [124];
  ulonglong local_de8 [62];
  undefined4 local_bf8;
  uint local_bf4;
  uint local_bf0;
  uint local_ad8 [2];
  ulonglong auStack_ad0 [63];
  ulonglong local_8d8 [64];
  uint local_6d8 [2];
  undefined8 auStack_6d0 [31];
  uint local_5d8 [64];
  ulonglong local_4d8 [32];
  uint local_3d8 [64];
  ulonglong local_2d8 [2];
  uint local_2c8 [4];
  longlong local_2b8;
  int local_2b0 [4];
  ulonglong local_2a0;
  longlong local_298;
  int local_290;
  int local_288 [4];
  undefined8 local_278;
  undefined8 local_270;
  undefined8 local_268;
  undefined8 local_260;
  ulonglong local_258 [4];
  ulonglong local_238 [65];
  undefined8 local_30;
  
  local_30 = 0x180008baa;
  local_238[0x40] = __security_cookie ^ (ulonglong)auStackY_1388;
  if ((param_1 == (int *)0x0) || (param_5 == (uint *)0x0)) {
    return -0x3ffffff3;
  }
  puVar1 = param_5 + 0xc;
  uVar18 = param_3 << 0xc;
  uVar7 = (ulonglong)uVar18;
  iVar5 = 0;
  bVar4 = false;
  piVar21 = param_4;
  if (((DAT_18001a168 != (undefined *)0x0) && (DAT_18001a168 != &FveCallbacks)) ||
     (DAT_18001a170 != 0)) {
    iVar5 = -0x3ffffff3;
    goto LAB_180009962;
  }
  if (DAT_18001a168 == (undefined *)0x0) {
    DAT_18001a168 = &FveCallbacks;
  }
  DAT_18001a170 = 0;
  if (((DAT_18001a168 != (undefined *)0x0) && (*(code **)(DAT_18001a168 + 0x38) != (code *)0x0)) &&
     (*(longlong *)(DAT_18001a168 + 0x40) != 0)) {
    (**(code **)(DAT_18001a168 + 0x38))(0);
  }
  iVar15 = DAT_18001a178 + 1;
  DAT_18001a178 = iVar15;
  if (((DAT_18001a168 != (undefined *)0x0) && (*(longlong *)(DAT_18001a168 + 0x38) != 0)) &&
     (*(code **)(DAT_18001a168 + 0x40) != (code *)0x0)) {
    (**(code **)(DAT_18001a168 + 0x40))(DAT_18001a170);
  }
  if (iVar15 < 2) {
    if ((g_SymCryptFlags & 1) == 0) {
      local_bf8 = 0x114;
      iVar15 = RtlGetVersion(&local_bf8);
      if (((iVar15 < 0) || (local_bf4 < 6)) || ((local_bf4 == 6 && (local_bf0 < 3)))) {
                    /* WARNING: Subroutine does not return */
        SymCryptFatal(0x6e737276);
      }
      SymCryptDetectCpuFeaturesByCpuid();
      uVar7 = RtlGetEnabledExtendedFeatures(0xffffffffffffffff);
      if ((uVar7 & 4) == 0) {
        g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 0x10;
      }
      if ((uVar7 & 0xe0) == 0) {
        g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 0x1000;
      }
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent & 0xffffffdf;
      LOCK();
      g_SymCryptFlags = g_SymCryptFlags | 1;
      UNLOCK();
      pcVar8 = "v103.12.0__2026-05-07T00:16:03+00:00_0df2f18_2026-05-07T21:50:22";
      do {
        pcVar8 = pcVar8 + 1;
      } while (*pcVar8 != '\0');
      _g_SymCryptCpuFeaturesPresentCheck = ~g_SymCryptCpuFeaturesNotPresent;
    }
    memset(local_11c8,0,0x1f0);
    pcVar8 = "@ABCDEFGHIJKLMNOabc";
    uVar7 = 0x10;
    SymCryptAesExpandKeyInternal
              ((undefined1 (*) [16])local_11c8,(undefined1 (*) [16])"@ABCDEFGHIJKLMNOabc",0x10,
               '\x01');
    local_12f8 = 0x23222120;
    FvepAesCcmComputeUnencryptedTag((uint *)local_11c8);
    piVar21 = &local_12f8;
    FvepAesCcmEncryptDecrypt
              (local_11c8,pcVar8,uVar7,(ulonglong)piVar21,in_stack_ffffffffffffec98,
               (ulonglong)local_12f4);
    if ((local_12f8 == 0x5b016271) && (local_12f4[0] == 0x5d25ac4d)) {
      local_2b0[0] = local_12f4[0];
      piVar21 = &local_12f8;
      FvepAesCcmEncryptDecrypt
                (local_11c8,pcVar8,uVar7,(ulonglong)piVar21,in_stack_ffffffffffffec98,
                 (ulonglong)local_2b0);
      FvepAesCcmComputeUnencryptedTag((uint *)local_11c8);
      if (local_2b0[0] != local_288[0]) {
        iVar5 = -0x3fffffc1;
        piVar16 = &local_12f8;
        for (lVar9 = 4; lVar9 != 0; lVar9 = lVar9 + -1) {
          *(undefined1 *)piVar16 = 0;
          piVar16 = (int *)((longlong)piVar16 + 1);
        }
      }
      piVar16 = local_2b0;
      for (lVar9 = 0x10; lVar9 != 0; lVar9 = lVar9 + -1) {
        *(undefined1 *)piVar16 = 0;
        piVar16 = (int *)((longlong)piVar16 + 1);
      }
      piVar16 = local_288;
      for (lVar9 = 0x10; lVar9 != 0; lVar9 = lVar9 + -1) {
        *(undefined1 *)piVar16 = 0;
        piVar16 = (int *)((longlong)piVar16 + 1);
      }
      if ((-1 < iVar5) && (local_12f8 != 0x23222120)) goto LAB_180008e9c;
    }
    else {
LAB_180008e9c:
      iVar5 = -0x3ffffdd7;
    }
    SymCryptWipeAsm(local_11c8,0x1f0);
    puVar11 = local_11c8;
    for (lVar9 = 0x1f0; lVar9 != 0; lVar9 = lVar9 + -1) {
      *(undefined1 *)puVar11 = 0;
      puVar11 = (ulonglong *)((longlong)puVar11 + 1);
    }
    if (iVar5 < 0) goto LAB_180009962;
    uVar6 = FveAesCbcFipsKat();
    iVar5 = (int)uVar6;
    if (iVar5 < 0) goto LAB_180009776;
    puVar12 = &SymCryptTestKey32;
    uVar19 = 0x10;
    local_1218[0] = 0;
    local_1218[1] = 0;
    local_1218[2] = 0;
    local_1218[3] = 0;
    local_1218[4] = 0;
    local_1218[5] = 0;
    local_1218[6] = 0;
    local_1218[7] = 0;
    local_1218[8] = 0;
    local_1218[9] = 0;
    local_1218[10] = 0;
    local_1218[0xb] = 0;
    local_1218[0xc] = 0;
    local_1218[0xd] = 0;
    local_1218[0xe] = 0;
    local_1218[0xf] = 0;
    local_1218[0x10] = 0;
    local_1218[0x11] = 0;
    local_1218[0x12] = 0;
    local_1218[0x13] = 0;
    SymCryptHmacSha256ExpandKey(local_1218,(undefined1 (*) [16])&SymCryptTestKey32,0x10);
    SymCryptHmacSha256((undefined8 *)local_1218,puVar12,uVar19,local_258);
    iVar15 = memcmp(local_258,&DAT_180015a10,0x20);
    if (iVar15 != 0) {
                    /* WARNING: Subroutine does not return */
      SymCryptFatal(0x68736832);
    }
    puVar12 = &SymCryptTestKey32;
    local_12e8[0] = 0;
    local_12e8[1] = 0;
    local_12e8[2] = 0;
    local_12e8[3] = 0;
    local_12e8[0x10] = 0;
    local_12e8[4] = 0;
    local_12e8[5] = 0;
    local_12e8[6] = 0;
    local_12e8[7] = 0;
    uVar19 = 0x10;
    local_12e8[8] = 0;
    local_12e8[9] = 0;
    local_12e8[10] = 0;
    local_12e8[0xb] = 0;
    local_12e8[0xc] = 0;
    local_12e8[0xd] = 0;
    local_12e8[0xe] = 0;
    local_12e8[0xf] = 0;
    SymCryptHmacSha1ExpandKey(local_12e8,&SymCryptTestKey32,0x10);
    SymCryptHmacSha1((undefined8 *)local_12e8,puVar12,uVar19,&local_2a0);
    if (((local_2a0 != 0xf12eba234085292a) || (local_298 != 0x6bcca897d88c0f49)) ||
       (local_290 != 0x122a7b55)) {
                    /* WARNING: Subroutine does not return */
      SymCryptFatal(0x68536831);
    }
    memset(local_fd8,0,0x3e0);
    puVar11 = local_2d8;
    local_2d8[1] = 0;
    puVar17 = local_2c8;
    local_2c8[0] = 0;
    local_2c8[1] = 0;
    uVar20 = 0;
    local_2c8[2] = 0;
    local_2c8[3] = 0;
    lVar9 = 4;
    local_2d8[0] = 1;
    do {
      uVar2 = *puVar17;
      puVar17 = puVar17 + 1;
      uVar7 = *puVar11;
      puVar11 = (ulonglong *)((longlong)puVar11 + 4);
      uVar20 = uVar20 | uVar2 ^ (uint)uVar7;
      lVar9 = lVar9 + -1;
    } while (lVar9 != 0);
    if ((uVar20 == 0) ||
       (uVar19 = SymCryptAesExpandKeyInternal
                           ((undefined1 (*) [16])local_fd8,(undefined1 (*) [16])local_2d8,0x10,
                            '\x01'), (int)uVar19 != 0)) {
LAB_180009ae6:
                    /* WARNING: Subroutine does not return */
      SymCryptFatal(0x78747361);
    }
    pauVar10 = (undefined1 (*) [16])local_de8;
    uVar19 = SymCryptAesExpandKeyInternal(pauVar10,(undefined1 (*) [16])local_2c8,0x10,'\0');
    if ((int)uVar19 != 0) goto LAB_180009ae6;
    local_1298 = 0;
    uStack_1290 = 0;
    local_1288 = 0;
    uStack_1280 = 0;
    local_1278 = 0;
    uStack_1270 = 0;
    local_1268 = 0;
    uStack_1260 = 0;
    if ((g_SymCryptCpuFeaturesNotPresent & 0x816) == 0) {
      if ((g_SymCryptCpuFeaturesNotPresent & 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
        SymCryptFatal(0x206d6d79);
      }
      if (2 < (byte)in_CR8) goto LAB_1800091c6;
      pauVar10 = (undefined1 (*) [16])0x4;
      iVar15 = KeSaveExtendedProcessorState(4,&local_1298);
      if (iVar15 < 0) goto LAB_1800091c6;
      uVar7 = 0x20;
      pauVar10 = (undefined1 (*) [16])local_2d8;
      puVar11 = local_2d8;
      lVar9 = 0;
      do {
        uVar6 = 0;
        do {
          *(longlong *)((longlong)local_ad8 + uVar6) = lVar9;
          uVar7 = uVar7 - 0x20;
          *(undefined8 *)((longlong)auStack_ad0 + uVar6) = 0;
          lVar9 = lVar9 + 1;
          uVar6 = uVar6 + 0x10;
          if (uVar7 < 0x20) break;
        } while (uVar6 < 0x100);
        SymCryptAesEcbEncryptXmm((uint *)local_de8,local_ad8,(undefined1 (*) [16])local_ad8,uVar6);
        uVar23 = 0;
        if (uVar6 != 0) {
          do {
            SymCryptXtsAesEncryptDataUnitYmm_2048
                      (local_fd8,(undefined1 (*) [16])((longlong)local_ad8 + uVar23),
                       auStack_ad0 + 0x1f,puVar11,pauVar10,0x20);
            puVar11 = puVar11 + 4;
            pauVar10 = pauVar10 + 2;
            uVar23 = uVar23 + 0x10;
          } while (uVar23 < uVar6);
        }
        bVar22 = (byte)in_CR8;
      } while (0x1f < uVar7);
      SymCryptWipeAsm((undefined8 *)local_ad8,0x200);
      KeRestoreExtendedProcessorState(&local_1298);
    }
    else {
LAB_1800091c6:
      puVar11 = local_2d8;
      if ((g_SymCryptCpuFeaturesNotPresent & 6) == 0) {
        uVar7 = 0x20;
        pauVar10 = (undefined1 (*) [16])local_2d8;
        lVar9 = 0;
        do {
          uVar6 = 0;
          do {
            *(longlong *)((longlong)local_8d8 + uVar6) = lVar9;
            uVar7 = uVar7 - 0x20;
            *(undefined8 *)((longlong)local_8d8 + uVar6 + 8) = 0;
            lVar9 = lVar9 + 1;
            uVar6 = uVar6 + 0x10;
            if (uVar7 < 0x20) break;
          } while (uVar6 < 0x100);
          SymCryptAesEcbEncryptXmm
                    ((uint *)local_de8,(uint *)local_8d8,(undefined1 (*) [16])local_8d8,uVar6);
          uVar23 = 0;
          if (uVar6 != 0) {
            do {
              SymCryptXtsAesEncryptDataUnitXmm
                        (local_fd8,(uint *)((longlong)local_8d8 + uVar23),local_8d8 + 0x20,puVar11,
                         pauVar10,0x20);
              puVar11 = puVar11 + 4;
              pauVar10 = pauVar10 + 2;
              uVar23 = uVar23 + 0x10;
            } while (uVar23 < uVar6);
          }
          bVar22 = (byte)in_CR8;
        } while (0x1f < uVar7);
        uVar7 = 0x200;
        puVar11 = local_8d8;
      }
      else {
        pauVar24 = (undefined1 (*) [16])local_2d8;
        uVar7 = 0x20;
        lVar9 = 0;
        local_1328 = pauVar24;
        do {
          uVar6 = 0;
          do {
            *(longlong *)((longlong)local_238 + uVar6) = lVar9;
            uVar7 = uVar7 - 0x20;
            *(undefined8 *)((longlong)local_238 + uVar6 + 8) = 0;
            lVar9 = lVar9 + 1;
            uVar6 = uVar6 + 0x10;
            if (uVar7 < 0x20) break;
          } while (uVar6 < 0x100);
          puVar13 = local_238;
          if (uVar6 < 0x10) {
            uVar23 = 0;
            if (uVar6 != 0) goto LAB_180009350;
          }
          else {
            uVar23 = uVar6 >> 4;
            do {
              pauVar10 = (undefined1 (*) [16])local_de8;
              SymCryptAesEncryptAsm((uint *)pauVar10,(longlong)puVar13,(undefined4 *)puVar13);
              puVar13 = puVar13 + 2;
              uVar23 = uVar23 - 1;
            } while (uVar23 != 0);
            uVar23 = 0;
            pauVar24 = local_1328;
LAB_180009350:
            do {
              SymCryptXtsEncryptDataUnit
                        (pauVar10,local_fd8,(ulonglong *)((longlong)local_238 + uVar23),
                         (ulonglong *)pauVar24,(longlong)puVar11,0x20);
              pauVar24 = (undefined1 (*) [16])((longlong)pauVar24 + 0x20);
              puVar11 = puVar11 + 4;
              uVar23 = uVar23 + 0x10;
            } while (uVar23 < uVar6);
            local_1328 = pauVar24;
          }
          bVar22 = (byte)in_CR8;
        } while (0x1f < uVar7);
        uVar7 = 0x100;
        puVar11 = local_238;
      }
      SymCryptWipeAsm(puVar11,uVar7);
    }
    puVar11 = local_2d8;
    iVar15 = memcmp(puVar11,&DAT_180015ab8,0x20);
    if (iVar15 != 0) {
                    /* WARNING: Subroutine does not return */
      SymCryptFatal(0x78747361);
    }
    local_1258 = 0;
    uStack_1250 = 0;
    local_1248 = 0;
    uStack_1240 = 0;
    local_1238 = 0;
    uStack_1230 = 0;
    local_1228 = 0;
    uStack_1220 = 0;
    if ((g_SymCryptCpuFeaturesNotPresent & 0x816) == 0) {
      if ((g_SymCryptCpuFeaturesNotPresent & 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
        SymCryptFatal(0x206d6d79);
      }
      if (2 < bVar22) goto LAB_180009516;
      puVar11 = (ulonglong *)0x4;
      iVar15 = KeSaveExtendedProcessorState(4,&local_1258);
      if (iVar15 < 0) goto LAB_180009516;
      uVar7 = 0x20;
      pauVar10 = (undefined1 (*) [16])local_2d8;
      puVar11 = local_2d8;
      lVar9 = 0;
      do {
        uVar6 = 0;
        do {
          *(longlong *)((longlong)local_6d8 + uVar6) = lVar9;
          uVar7 = uVar7 - 0x20;
          *(undefined8 *)((longlong)auStack_6d0 + uVar6) = 0;
          lVar9 = lVar9 + 1;
          uVar6 = uVar6 + 0x10;
          if (uVar7 < 0x20) break;
        } while (uVar6 < 0x100);
        SymCryptAesEcbEncryptXmm((uint *)local_de8,local_6d8,(undefined1 (*) [16])local_6d8,uVar6);
        uVar23 = 0;
        if (uVar6 != 0) {
          do {
            SymCryptXtsAesDecryptDataUnitYmm_2048
                      ((longlong)local_fd8,(undefined1 (*) [16])((longlong)local_6d8 + uVar23),
                       local_5d8,(uint *)puVar11,pauVar10,0x20);
            puVar11 = puVar11 + 4;
            pauVar10 = pauVar10 + 2;
            uVar23 = uVar23 + 0x10;
          } while (uVar23 < uVar6);
        }
      } while (0x1f < uVar7);
      SymCryptWipeAsm((undefined8 *)local_6d8,0x200);
      KeRestoreExtendedProcessorState(&local_1258);
    }
    else {
LAB_180009516:
      pauVar10 = (undefined1 (*) [16])local_2d8;
      puVar13 = local_2d8;
      lVar9 = 0;
      if ((g_SymCryptCpuFeaturesNotPresent & 6) == 0) {
        uVar7 = 0x20;
        do {
          uVar6 = 0;
          do {
            *(longlong *)((longlong)local_4d8 + uVar6) = lVar9;
            uVar7 = uVar7 - 0x20;
            *(undefined8 *)((longlong)local_4d8 + uVar6 + 8) = 0;
            lVar9 = lVar9 + 1;
            uVar6 = uVar6 + 0x10;
            if (uVar7 < 0x20) break;
          } while (uVar6 < 0x100);
          SymCryptAesEcbEncryptXmm
                    ((uint *)local_de8,(uint *)local_4d8,(undefined1 (*) [16])local_4d8,uVar6);
          uVar23 = 0;
          if (uVar6 != 0) {
            do {
              SymCryptXtsAesDecryptDataUnitXmm
                        ((longlong)local_fd8,(uint *)((longlong)local_4d8 + uVar23),local_3d8,
                         (uint *)puVar13,pauVar10,0x20);
              puVar13 = puVar13 + 4;
              pauVar10 = pauVar10 + 2;
              uVar23 = uVar23 + 0x10;
            } while (uVar23 < uVar6);
          }
        } while (0x1f < uVar7);
        uVar7 = 0x200;
        puVar11 = local_4d8;
      }
      else {
        uVar7 = 0x20;
        local_1328 = pauVar10;
        do {
          uVar6 = 0;
          do {
            *(longlong *)((longlong)local_238 + uVar6 + 0x100) = lVar9;
            uVar7 = uVar7 - 0x20;
            *(undefined8 *)((longlong)local_238 + uVar6 + 0x108) = 0;
            lVar9 = lVar9 + 1;
            uVar6 = uVar6 + 0x10;
            if (uVar7 < 0x20) break;
          } while (uVar6 < 0x100);
          puVar14 = local_238 + 0x20;
          if (uVar6 < 0x10) {
            uVar23 = 0;
            if (uVar6 != 0) goto LAB_180009690;
          }
          else {
            uVar23 = uVar6 >> 4;
            do {
              puVar11 = local_de8;
              SymCryptAesEncryptAsm((uint *)puVar11,(longlong)puVar14,(undefined4 *)puVar14);
              puVar14 = puVar14 + 2;
              uVar23 = uVar23 - 1;
            } while (uVar23 != 0);
            uVar23 = 0;
            pauVar10 = local_1328;
LAB_180009690:
            do {
              SymCryptXtsDecryptDataUnit
                        (puVar11,(longlong)local_fd8,
                         (ulonglong *)((longlong)local_238 + uVar23 + 0x100),(ulonglong *)pauVar10,
                         (longlong)puVar13,0x20);
              pauVar10 = pauVar10 + 2;
              puVar13 = puVar13 + 4;
              uVar23 = uVar23 + 0x10;
            } while (uVar23 < uVar6);
            local_1328 = pauVar10;
          }
        } while (0x1f < uVar7);
        uVar7 = 0x100;
        puVar11 = local_238 + 0x20;
      }
      SymCryptWipeAsm(puVar11,uVar7);
    }
    local_270 = 0;
    local_268 = 0;
    uVar7 = 0x20;
    local_260 = 0;
    local_278 = 1;
    iVar15 = memcmp(local_2d8,&local_278,0x20);
    if (iVar15 != 0) {
                    /* WARNING: Subroutine does not return */
      SymCryptFatal(0x78747361);
    }
    piVar21 = (int *)&DAT_180015838;
    SymCryptPbkdf2();
    if (local_2b8 != 0x6184d248891e9805) {
                    /* WARNING: Subroutine does not return */
      SymCryptFatal(0x50626b32);
    }
  }
LAB_180009776:
  bVar22 = (byte)param_4;
  if (iVar5 < 0) goto LAB_180009962;
  param_5[1] = param_1[9];
  uVar6 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar6 != 0) {
    bVar22 = (byte)(*(uint *)(param_2 + 0x34) >> 2) & 1;
    if ((*(uint *)(param_2 + 0x34) & 0x20) == 0) {
      uVar20 = param_5[0x30] & 0xffffffef;
    }
    else {
      uVar20 = param_5[0x30] | 0x10;
    }
    param_5[0x30] = uVar20;
  }
  if (*param_1 == 1) {
    uVar7 = 0xffffffffffffffff;
    param_5[0x30] = param_5[0x30] | 4;
    param_5[0x11] = uVar18;
    piVar21 = (int *)(-(ulonglong)(bVar22 != 0) & 0x100000000);
    if (bVar22 == 0) {
      uVar7 = 0xffffffff;
    }
    lVar9 = MmAllocateContiguousNodeMemory(uVar18,0);
    *(longlong *)(param_5 + 0x12) = lVar9;
    if (lVar9 != 0) goto LAB_18000983c;
LAB_18000982e:
    iVar5 = -0x3fffff66;
    goto LAB_180009962;
  }
LAB_18000983c:
  uVar6 = SendDeviceIoControl(0x4556d0c3,*(undefined8 *)(param_1 + 2),uVar7,piVar21,puVar1);
  iVar5 = (int)uVar6;
  if (iVar5 < 0) goto LAB_180009962;
  bVar4 = true;
  if ((*param_1 != 1) && (param_5[0x10] == 0)) {
    return iVar5;
  }
  if (param_5[0x11] < uVar18) {
    if (*(longlong *)(param_5 + 0x12) != 0) goto LAB_18000982e;
    uVar6 = SendDeviceIoControl(0x4556d0c7,*(undefined8 *)(param_1 + 2),uVar7,piVar21,puVar1);
    iVar5 = (int)uVar6;
    if (iVar5 < 0) goto LAB_180009962;
    puVar3 = *(undefined1 **)(param_5 + 0x12);
    bVar4 = false;
    if ((puVar3 == (undefined1 *)0x0) || (uVar18 <= param_5[0x11])) {
      if (puVar3 == (undefined1 *)0x0) goto LAB_1800098d4;
    }
    else {
      FveDmpSecureZeroAndFlush(puVar3,param_5[0x11]);
      MmFreeContiguousMemory(*(undefined8 *)(param_5 + 0x12));
      param_5[0x12] = 0;
      param_5[0x13] = 0;
LAB_1800098d4:
      param_5[0x11] = uVar18;
      piVar21 = (int *)(-(ulonglong)(bVar22 != 0) & 0x100000000);
      uVar7 = 0xffffffffffffffff;
      if (bVar22 == 0) {
        uVar7 = 0xffffffff;
      }
      lVar9 = MmAllocateContiguousNodeMemory(uVar18,0);
      *(longlong *)(param_5 + 0x12) = lVar9;
      if (lVar9 == 0) {
        iVar5 = -0x3fffff66;
        goto LAB_180009962;
      }
    }
    uVar6 = SendDeviceIoControl(0x4556d0c3,*(undefined8 *)(param_1 + 2),uVar7,piVar21,puVar1);
    iVar5 = (int)uVar6;
    if (iVar5 < 0) goto LAB_180009962;
  }
  bVar4 = true;
  uVar6 = FveInitCrypto((int *)param_5);
  iVar5 = (int)uVar6;
  if (-1 < iVar5) {
    return iVar5;
  }
LAB_180009962:
  FveDmpSecureZeroAndFlush((undefined1 *)(param_5 + 0x52),0x4d);
  FveDestroyCryptoKeyData((longlong)(param_5 + 0x66));
  uVar6 = Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar6 != 0) {
    FveDestroyCryptoKeyData((longlong)(param_5 + 0x86));
    FveDmpSecureZeroAndFlush((undefined1 *)(param_5 + 0x72),0x4d);
    FveDmpSecureZeroAndFlush((undefined1 *)(param_5 + 0x86),0x20);
  }
  if (0x23f < *param_5) {
    FveDmpSecureZeroAndFlush((undefined1 *)(param_5 + 0x90),*param_5 - 0x240);
  }
  FveDmpSecureZeroAndFlush((undefined1 *)(param_5 + 0x66),0x20);
  if ((!bVar4) ||
     (uVar7 = SendDeviceIoControl(0x4556d0c7,*(undefined8 *)(param_1 + 2),uVar7,piVar21,puVar1),
     -1 < (int)uVar7)) {
    if (*(undefined1 **)(param_5 + 0x12) != (undefined1 *)0x0) {
      FveDmpSecureZeroAndFlush(*(undefined1 **)(param_5 + 0x12),param_5[0x11]);
      MmFreeContiguousMemory(*(undefined8 *)(param_5 + 0x12));
    }
    FveDmpSecureZeroAndFlush((undefined1 *)puVar1,0x118);
  }
  else {
    FveDmpSecureZeroAndFlush((undefined1 *)(param_5 + 0x16),0x4d);
    param_5[0x30] = param_5[0x30] | 2;
  }
  if (iVar5 == -0x3ffffffe) {
    param_5[0x10] = 0;
    iVar5 = 0;
  }
  return iVar5;
}



===== FveDatumHeaderSafe @ 180009b10 =====

undefined8 FveDatumHeaderSafe(ulonglong *param_1,undefined8 param_2,ulonglong *param_3)

{
  ulonglong uVar1;
  ushort uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong *puVar5;
  
  uVar4 = 8;
  puVar5 = param_3;
  for (lVar3 = 8; lVar3 != 0; lVar3 = lVar3 + -1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (ulonglong *)((longlong)puVar5 + 1);
  }
  if ((param_1 != (ulonglong *)0x0) && (uVar1 = *param_1, 7 < (ushort)uVar1)) {
    uVar2 = (ushort)(uVar1 >> 0x20);
    if ((uVar2 < 0x23) &&
       ((ushort *)(&PTR_FveDatumErasedTypeProp_180014100)[uVar2] != (ushort *)0x0)) {
      uVar4 = (ulonglong)*(ushort *)(&PTR_FveDatumErasedTypeProp_180014100)[uVar2];
    }
    if (uVar4 <= (uVar1 & 0xffff)) {
      *param_3 = uVar1;
      return 0;
    }
  }
  return 0xc000000d;
}



===== SymCryptXtsAesDecryptInternalXmm @ 180009b80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptXtsAesDecryptInternalXmm
               (longlong param_1,ulonglong param_2,longlong *param_3,uint *param_4,
               undefined1 (*param_5) [16],ulonglong param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined1 auStackY_288 [32];
  uint local_248 [2];
  longlong alStack_240 [31];
  uint local_148 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_288;
  lVar1 = param_3[1];
  lVar4 = *param_3;
  do {
    if (param_6 < param_2) {
      SymCryptWipeAsm((undefined8 *)local_248,0x200);
      return;
    }
    uVar2 = 0;
    do {
      *(longlong *)((longlong)local_248 + uVar2) = lVar4;
      param_6 = param_6 - param_2;
      *(longlong *)((longlong)alStack_240 + uVar2) = lVar1;
      lVar4 = lVar4 + 1;
      uVar2 = uVar2 + 0x10;
      if (0xff < uVar2) break;
    } while (param_2 <= param_6);
    SymCryptAesEcbEncryptXmm
              ((uint *)(param_1 + 0x1f0),local_248,(undefined1 (*) [16])local_248,uVar2);
    uVar3 = 0;
    if (uVar2 != 0) {
      do {
        SymCryptXtsAesDecryptDataUnitXmm
                  (param_1,(uint *)((longlong)local_248 + uVar3),local_148,param_4,param_5,param_2);
        param_4 = (uint *)((longlong)param_4 + param_2);
        param_5 = (undefined1 (*) [16])(*param_5 + param_2);
        uVar3 = uVar3 + 0x10;
      } while (uVar3 < uVar2);
    }
  } while( true );
}



===== SymCryptHmacSha1 @ 180009cb4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptHmacSha1(undefined8 *param_1,undefined8 param_2,undefined8 param_3,ulonglong *param_4)

{
  undefined1 auStack_c8 [32];
  uint local_a8 [36];
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_c8;
  local_a8[1] = 0;
  memset(local_a8,0,0x8c);
  SymCryptHmacSha1Init(local_a8,param_1);
  SymCryptSha1Append(local_a8,"abc",3);
  SymCryptHmacSha1Result(local_a8,param_4);
  return;
}



===== SymCryptHmacSha1Init @ 180009d4c =====

void SymCryptHmacSha1Init(undefined4 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  uVar1 = param_2[1];
  *(undefined8 *)(param_1 + 0x18) = *param_2;
  *(undefined8 *)(param_1 + 0x1a) = uVar1;
  uVar1 = param_2[2];
  uVar2 = param_2[3];
  *param_1 = 0;
  *(undefined8 *)(param_1 + 4) = 0x40;
  *(undefined8 *)(param_1 + 0x1c) = uVar1;
  *(undefined8 *)(param_1 + 0x1e) = uVar2;
  *(undefined8 **)(param_1 + 0x20) = param_2;
  return;
}



===== SymCryptSha1Append @ 180009d78 =====

void SymCryptSha1Append(undefined8 param_1,void *param_2,ulonglong param_3)

{
  SymCryptHashAppendInternal(param_1,(uint *)param_1,param_2,param_3);
  return;
}



===== DumpKsrGetContextFromKsrMemory @ 180009d98 =====

int DumpKsrGetContextFromKsrMemory(undefined8 *param_1,undefined8 *param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 *puVar3;
  int *piVar4;
  uint uVar5;
  int local_res18 [2];
  ulonglong local_res20;
  undefined4 uVar6;
  longlong local_38 [2];
  
  local_res18[0] = 0;
  local_res20 = 0;
  local_38[0] = 0;
  iVar1 = KsrEnumeratePersistedMemory(&DAT_180015bc8,DumpKsrMemoryEnumerate,local_38);
  if (iVar1 < 0) {
    return iVar1;
  }
  if (local_38[0] != 0) {
    piVar4 = local_res18;
    iVar1 = KsrClaimPersistedMemory(&DAT_180015bc8,local_38[0],&local_res20,1,1,piVar4);
    uVar6 = (undefined4)((ulonglong)piVar4 >> 0x20);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (local_res18[0] == 1) {
      uVar2 = (local_res20 >> 0x28) * 8;
      if (uVar2 + 0x30 < uVar2) {
        return -0x3fffff6b;
      }
      puVar3 = (undefined8 *)ExAllocatePool2(0x40);
      if (puVar3 == (undefined8 *)0x0) {
        return -0x3fffff66;
      }
      *puVar3 = 0;
      uVar5 = 0;
      puVar3[4] = 0;
      *(undefined4 *)((longlong)puVar3 + 0x2c) = 0;
      *(undefined2 *)((longlong)puVar3 + 10) = 2;
      *(uint *)(puVar3 + 5) = (uint)(local_res20 >> 0x1c) & 0xfffff000;
      *(short *)(puVar3 + 1) = ((short)(local_res20 >> 0x28) + 6) * 8;
      if ((local_res20 & 0xffffff0000000000) != 0) {
        uVar2 = 0;
        do {
          uVar5 = uVar5 + 1;
          puVar3[uVar2 + 6] = (local_res20 & 0xffffffffff) + uVar2;
          uVar2 = (ulonglong)uVar5;
        } while (uVar2 < local_res20 >> 0x28);
      }
      if ((*(byte *)((longlong)puVar3 + 10) & 5) == 0) {
        piVar4 = (int *)MmMapLockedPagesSpecifyCache(puVar3,0,1,0,0,CONCAT44(uVar6,0x40000010));
      }
      else {
        piVar4 = (int *)puVar3[3];
      }
      if (piVar4 == (int *)0x0) {
        iVar1 = -0x3fffff66;
      }
      else {
        if ((((*piVar4 == 0x6b564644) && (0x87 < (uint)piVar4[2])) && (0x87 < (uint)piVar4[1])) &&
           ((piVar4[3] & 1U) != 0)) {
          *param_1 = puVar3;
          *param_2 = piVar4;
          return 0;
        }
        iVar1 = -0x3ffffff3;
        FveDmpSecureZeroAndFlush((undefined1 *)piVar4,piVar4[2]);
        MmUnmapLockedPages(piVar4,puVar3);
      }
      ExFreePoolWithTag(puVar3,0x45564664);
      return iVar1;
    }
  }
  return -0x3fffff45;
}



===== SymCryptInitEnvWindowsKernelmodeWin8_1nLater @ 180009fb4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SymCryptInitEnvWindowsKernelmodeWin8_1nLater(void)

{
  char cVar1;
  int iVar2;
  ulonglong uVar3;
  char *pcVar4;
  undefined1 auStack_168 [48];
  undefined4 local_138;
  uint local_134;
  uint local_130;
  ulonglong local_18;
  
  local_18 = __security_cookie ^ (ulonglong)auStack_168;
  if ((g_SymCryptFlags & 1) == 0) {
    local_138 = 0x114;
    iVar2 = RtlGetVersion(&local_138);
    if (((iVar2 < 0) || (local_134 < 6)) || ((local_134 == 6 && (local_130 < 3)))) {
                    /* WARNING: Subroutine does not return */
      SymCryptFatal(0x6e737276);
    }
    SymCryptDetectCpuFeaturesByCpuid();
    uVar3 = RtlGetEnabledExtendedFeatures(0xffffffffffffffff);
    if ((uVar3 & 4) == 0) {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 0x10;
    }
    if ((uVar3 & 0xe0) == 0) {
      g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent | 0x1000;
    }
    g_SymCryptCpuFeaturesNotPresent = g_SymCryptCpuFeaturesNotPresent & 0xffffffdf;
    LOCK();
    g_SymCryptFlags = g_SymCryptFlags | 1;
    UNLOCK();
    pcVar4 = "v103.12.0__2026-05-07T00:16:03+00:00_0df2f18_2026-05-07T21:50:22";
    cVar1 = 'v';
    while (cVar1 != '\0') {
      pcVar4 = pcVar4 + 1;
      cVar1 = *pcVar4;
    }
    _g_SymCryptCpuFeaturesPresentCheck = ~g_SymCryptCpuFeaturesNotPresent;
  }
  return;
}



===== SymCryptXtsAesExpandKeyEx @ 18000a0ac =====

undefined8
SymCryptXtsAesExpandKeyEx(undefined1 (*param_1) [16],undefined1 (*param_2) [16],ulonglong param_3)

{
  bool bVar1;
  undefined8 uVar2;
  
  if (param_3 < 0x41) {
    bVar1 = SymCryptEqual((uint *)param_2,(uint *)(*param_2 + (param_3 >> 1)),param_3 >> 1);
    if (bVar1) {
      uVar2 = 0x8009;
    }
    else {
      uVar2 = SymCryptXtsAesExpandKey(param_1,param_2,param_3);
    }
  }
  else {
    uVar2 = 0x8001;
  }
  return uVar2;
}



===== FveAesEcbEncrypt @ 18000a110 =====

undefined8
FveAesEcbEncrypt(uint *param_1,longlong param_2,ulonglong param_3,undefined1 (*param_4) [16])

{
  longlong lVar1;
  ulonglong uVar2;
  
  if (0xf < param_3) {
    lVar1 = param_2 - (longlong)param_4;
    uVar2 = param_3 >> 4;
    do {
      SymCryptAesEncrypt(param_1,(uint *)(lVar1 + (longlong)param_4),param_4);
      param_4 = param_4 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return 0;
}



===== SymCryptFatal @ 18000a174 =====

void SymCryptFatal(undefined4 param_1)

{
                    /* WARNING: Subroutine does not return */
  KeBugCheckEx(0x171,param_1,0,0,0);
}



===== FveAesCbcDecryptSectors @ 18000a1a0 =====

void FveAesCbcDecryptSectors
               (uint *param_1,ulonglong param_2,ulonglong *param_3,uint param_4,ulonglong *param_5,
               uint param_6,uint *param_7)

{
  if ((param_7 == (uint *)0x0) || ((*param_7 & 0x40) == 0)) {
    FveAesCbcDecryptSectorsNormal(param_1,param_2,(uint *)param_3,param_4,param_5,param_6,param_7);
  }
  else {
    FveAesCbcDecryptSectorsPageIsolation(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}



===== FveDestroyCryptoKeyData @ 18000a200 =====

void FveDestroyCryptoKeyData(longlong param_1)

{
  short sVar1;
  longlong lVar2;
  undefined8 *puVar3;
  ulonglong uVar4;
  undefined1 *puVar5;
  
  if (param_1 == 0) {
    return;
  }
  sVar1 = *(short *)(param_1 + 0x1c);
  if ((sVar1 == -0x8000) || (sVar1 == -0x7fff)) {
    FveAesDestroyKey(*(undefined8 **)(param_1 + 0x10));
    puVar3 = (undefined8 *)(*(longlong *)(param_1 + 0x10) + 0x1f0);
  }
  else {
    if ((sVar1 != -0x7ffe) && (sVar1 != -0x7ffd)) {
      if (((sVar1 == -0x7ffc) || (sVar1 == -0x7ffb)) &&
         (puVar3 = *(undefined8 **)(param_1 + 0x10), puVar3 != (undefined8 *)0x0)) {
        SymCryptWipeAsm(puVar3,0x3e0);
        for (lVar2 = 0x3e0; lVar2 != 0; lVar2 = lVar2 + -1) {
          *(undefined1 *)puVar3 = 0;
          puVar3 = (undefined8 *)((longlong)puVar3 + 1);
        }
      }
      goto LAB_18000a27b;
    }
    puVar3 = *(undefined8 **)(param_1 + 0x10);
  }
  FveAesDestroyKey(puVar3);
LAB_18000a27b:
  puVar5 = *(undefined1 **)(param_1 + 0x10);
  for (uVar4 = (ulonglong)*(uint *)(param_1 + 0x18); uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  return;
}



===== SymCryptXtsAesDecrypt @ 18000a298 =====

void SymCryptXtsAesDecrypt
               (longlong param_1,ulonglong param_2,longlong param_3,ulonglong *param_4,
               undefined1 (*param_5) [16],ulonglong param_6)

{
  longlong local_18 [3];
  
  if (0xf < param_2) {
    local_18[1] = 0;
    local_18[0] = param_3;
    SymCryptXtsAesDecryptInternal(param_1,param_2,local_18,param_4,param_5,param_6);
  }
  return;
}



===== SymCryptXtsAesEncrypt @ 18000a2dc =====

void SymCryptXtsAesEncrypt
               (uint *param_1,ulonglong param_2,longlong param_3,ulonglong *param_4,
               undefined1 (*param_5) [16],ulonglong param_6)

{
  longlong local_18 [3];
  
  if (0xf < param_2) {
    local_18[1] = 0;
    local_18[0] = param_3;
    SymCryptXtsAesEncryptInternal(param_1,param_2,local_18,param_4,param_5,param_6);
  }
  return;
}



===== __report_gsfailure @ 18000a330 =====

void __cdecl __report_gsfailure(uintptr_t _StackCookie)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



===== RtlCompareMemory @ 18000a33d =====

void RtlCompareMemory(void)

{
                    /* WARNING: Could not recover jumptable at 0x00018000a33d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  RtlCompareMemory();
  return;
}



===== SymCryptSha256AppendBlocks_xmm_ssse3_asm @ 18000a370 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SymCryptSha256AppendBlocks_xmm_ssse3_asm
               (uint *param_1,undefined1 (*param_2) [16],ulonglong param_3,ulonglong *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined8 *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  longlong lVar13;
  int *piVar14;
  int *piVar15;
  uint uVar16;
  uint uVar20;
  uint uVar21;
  undefined1 auVar17 [16];
  undefined1 auVar18 [16];
  undefined1 auVar19 [16];
  uint uVar25;
  undefined1 auVar22 [16];
  undefined1 auVar23 [16];
  undefined1 auVar24 [16];
  uint uVar26;
  uint uVar27;
  uint uVar31;
  uint uVar33;
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  uint uVar32;
  uint uVar34;
  undefined1 auVar30 [16];
  uint uVar35;
  uint uVar36;
  uint uVar40;
  uint uVar42;
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  uint uVar41;
  uint uVar43;
  undefined1 auVar39 [16];
  uint uVar44;
  uint uVar61;
  uint uVar62;
  uint uVar63;
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  undefined1 auVar51 [16];
  undefined1 auVar52 [16];
  undefined1 auVar53 [16];
  undefined1 auVar54 [16];
  undefined1 auVar55 [16];
  undefined1 auVar56 [16];
  undefined1 auVar57 [16];
  undefined1 auVar58 [16];
  undefined1 auVar59 [16];
  undefined1 auVar60 [16];
  uint uVar64;
  uint uVar69;
  uint uVar70;
  uint uVar71;
  undefined1 auVar65 [16];
  undefined1 auVar66 [16];
  undefined1 auVar67 [16];
  undefined1 auVar68 [16];
  uint uVar72;
  uint uVar81;
  uint uVar82;
  uint uVar83;
  undefined1 auVar73 [16];
  undefined1 auVar74 [16];
  undefined1 auVar75 [16];
  undefined1 auVar76 [16];
  undefined1 auVar77 [16];
  undefined1 auVar78 [16];
  undefined1 auVar79 [16];
  undefined1 auVar80 [16];
  uint uVar84;
  uint uVar85;
  uint uVar86;
  uint uVar87;
  uint uVar88;
  uint uVar93;
  uint uVar94;
  uint uVar95;
  undefined1 auVar89 [16];
  undefined1 auVar90 [16];
  undefined1 auVar91 [16];
  undefined1 auVar92 [16];
  uint uVar96;
  uint uVar97;
  uint uVar98;
  uint uVar99;
  undefined8 local_4f8;
  undefined8 uStack_4f0;
  undefined8 local_4e8;
  undefined8 uStack_4e0;
  int local_4d8;
  int iStack_4d4;
  int iStack_4d0;
  int iStack_4cc;
  int local_4c8;
  int iStack_4c4;
  int iStack_4c0;
  int iStack_4bc;
  undefined8 local_4b8;
  undefined8 uStack_4b0;
  undefined8 local_4a8;
  undefined8 uStack_4a0;
  undefined4 local_498;
  undefined4 uStack_494;
  undefined4 uStack_490;
  undefined4 uStack_48c;
  undefined4 local_488;
  undefined4 uStack_484;
  undefined4 uStack_480;
  undefined4 uStack_47c;
  undefined8 local_478;
  undefined8 uStack_470;
  undefined8 local_468;
  undefined8 uStack_460;
  uint local_458;
  uint uStack_454;
  uint uStack_450;
  uint uStack_44c;
  uint local_448;
  uint uStack_444;
  uint uStack_440;
  uint uStack_43c;
  undefined8 local_438;
  undefined8 uStack_430;
  undefined8 local_428;
  undefined8 uStack_420;
  uint local_418;
  uint uStack_414;
  uint uStack_410;
  uint uStack_40c;
  uint local_408;
  uint uStack_404;
  uint uStack_400;
  uint uStack_3fc;
  ulonglong local_f8;
  int local_f0;
  
  local_f0 = 0x40;
  if (0xbf < param_3) {
    local_f0 = 0x400;
  }
  uVar1 = *param_1;
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar9 = param_1[3];
  uVar10 = param_1[4];
  uVar11 = param_1[5];
  uVar12 = param_1[6];
  uVar6 = param_1[7];
  auVar18 = _BYTE_REVERSE_32;
  auVar17 = _XMM_PACKLOW;
  auVar23 = _XMM_PACKHIGH;
  while( true ) {
    _XMM_PACKHIGH = auVar23;
    _XMM_PACKLOW = auVar17;
    _BYTE_REVERSE_32 = auVar18;
    if (param_3 < 0xc0) break;
    local_f8 = param_3 >> 6;
    if (4 < local_f8) {
      local_f8 = 4;
    }
    lVar13 = 0x80;
    if (local_f8 == 4) {
      lVar13 = 0xc0;
    }
    auVar17 = pshufb(*param_2,auVar18);
    auVar22 = pshufb(param_2[4],auVar18);
    auVar28 = pshufb(param_2[8],auVar18);
    auVar37 = pshufb(*(undefined1 (*) [16])(*param_2 + lVar13),auVar18);
    uVar25 = auVar22._4_4_;
    uVar20 = auVar17._4_4_;
    auVar23._0_8_ = auVar17._0_8_;
    auVar23._8_4_ = uVar20;
    auVar23._12_4_ = uVar25;
    uVar16 = auVar17._0_4_;
    uVar21 = auVar22._0_4_;
    local_4f8._4_4_ = uVar21;
    local_4f8._0_4_ = uVar16;
    uVar40 = auVar37._4_4_;
    uVar31 = auVar28._4_4_;
    auVar38._0_8_ = auVar28._0_8_;
    auVar38._8_4_ = uVar31;
    auVar38._12_4_ = uVar40;
    uVar26 = auVar28._0_4_;
    uVar35 = auVar37._0_4_;
    uStack_4f0._4_4_ = uVar35;
    uStack_4f0._0_4_ = uVar26;
    uStack_4e0 = auVar38._8_8_;
    local_4e8 = auVar23._8_8_;
    iStack_4d4 = auVar22._8_4_;
    local_4d8 = auVar17._8_4_;
    iStack_4d0 = auVar28._8_4_;
    iStack_4cc = auVar37._8_4_;
    iStack_4c4 = auVar22._12_4_;
    local_4c8 = auVar17._12_4_;
    iStack_4c0 = auVar28._12_4_;
    iStack_4bc = auVar37._12_4_;
    lVar13 = 0x90;
    if (local_f8 == 4) {
      lVar13 = 0xd0;
    }
    auVar17 = pshufb(param_2[1],auVar18);
    auVar23 = pshufb(param_2[5],auVar18);
    auVar28 = pshufb(param_2[9],auVar18);
    auVar38 = pshufb(*(undefined1 (*) [16])(*param_2 + lVar13),auVar18);
    auVar22._0_8_ = auVar17._0_8_;
    auVar22._8_4_ = auVar17._4_4_;
    auVar22._12_4_ = auVar23._4_4_;
    auVar37._0_8_ = auVar28._0_8_;
    auVar37._8_4_ = auVar28._4_4_;
    auVar37._12_4_ = auVar38._4_4_;
    local_4b8 = CONCAT44(auVar23._0_4_,auVar17._0_4_);
    uStack_4b0 = CONCAT44(auVar38._0_4_,auVar28._0_4_);
    local_4a8 = auVar22._8_8_;
    uStack_4a0 = auVar37._8_8_;
    local_498 = auVar17._8_4_;
    uStack_494 = auVar23._8_4_;
    uStack_490 = auVar28._8_4_;
    uStack_48c = auVar38._8_4_;
    local_488 = auVar17._12_4_;
    uStack_484 = auVar23._12_4_;
    uStack_480 = auVar28._12_4_;
    uStack_47c = auVar38._12_4_;
    lVar13 = 0xa0;
    if (local_f8 == 4) {
      lVar13 = 0xe0;
    }
    auVar17 = pshufb(param_2[2],auVar18);
    auVar23 = pshufb(param_2[6],auVar18);
    auVar22 = pshufb(param_2[10],auVar18);
    auVar38 = pshufb(*(undefined1 (*) [16])(*param_2 + lVar13),auVar18);
    uVar36 = auVar17._8_4_;
    uVar41 = auVar23._8_4_;
    uVar44 = auVar17._12_4_;
    uVar61 = auVar23._12_4_;
    uVar32 = auVar23._4_4_;
    uVar27 = auVar17._4_4_;
    auVar28._0_8_ = auVar17._0_8_;
    auVar28._8_4_ = uVar27;
    auVar28._12_4_ = uVar32;
    uVar42 = auVar22._8_4_;
    uVar43 = auVar38._8_4_;
    uVar62 = auVar22._12_4_;
    uVar63 = auVar38._12_4_;
    uVar34 = auVar38._4_4_;
    uVar33 = auVar22._4_4_;
    auVar29._0_8_ = auVar22._0_8_;
    auVar29._8_4_ = uVar33;
    auVar29._12_4_ = uVar34;
    local_478 = CONCAT44(auVar23._0_4_,auVar17._0_4_);
    uStack_470 = CONCAT44(auVar38._0_4_,auVar22._0_4_);
    local_468 = auVar28._8_8_;
    uStack_460 = auVar29._8_8_;
    local_458 = uVar36;
    uStack_454 = uVar41;
    uStack_450 = uVar42;
    uStack_44c = uVar43;
    local_448 = uVar44;
    uStack_444 = uVar61;
    uStack_440 = uVar62;
    uStack_43c = uVar63;
    lVar13 = 0xb0;
    if (local_f8 == 4) {
      lVar13 = 0xf0;
    }
    auVar17 = pshufb(param_2[3],auVar18);
    auVar23 = pshufb(param_2[7],auVar18);
    auVar22 = pshufb(param_2[0xb],auVar18);
    auVar28 = pshufb(*(undefined1 (*) [16])(*param_2 + lVar13),auVar18);
    uVar84 = auVar17._8_4_;
    uVar85 = auVar23._8_4_;
    uVar88 = auVar17._12_4_;
    uVar93 = auVar23._12_4_;
    uVar81 = auVar23._4_4_;
    uVar72 = auVar17._4_4_;
    auVar18._0_8_ = auVar17._0_8_;
    auVar18._8_4_ = uVar72;
    auVar18._12_4_ = uVar81;
    uVar64 = auVar17._0_4_;
    uVar69 = auVar23._0_4_;
    uVar86 = auVar22._8_4_;
    uVar87 = auVar28._8_4_;
    uVar94 = auVar22._12_4_;
    uVar95 = auVar28._12_4_;
    uVar83 = auVar28._4_4_;
    uVar82 = auVar22._4_4_;
    auVar17._0_8_ = auVar22._0_8_;
    auVar17._8_4_ = uVar82;
    auVar17._12_4_ = uVar83;
    uVar70 = auVar22._0_4_;
    uVar71 = auVar28._0_4_;
    local_438 = CONCAT44(uVar69,uVar64);
    uStack_430 = CONCAT44(uVar71,uVar70);
    local_428 = auVar18._8_8_;
    uStack_420 = auVar17._8_8_;
    local_418 = uVar84;
    uStack_414 = uVar85;
    uStack_410 = uVar86;
    uStack_40c = uVar87;
    local_408 = uVar88;
    uStack_404 = uVar93;
    uStack_400 = uVar94;
    uStack_3fc = uVar95;
    piVar15 = &SymCryptSha256K;
    piVar14 = (int *)&local_4f8;
    do {
      iVar5 = *piVar15;
      *piVar14 = iVar5 + uVar16;
      piVar14[1] = iVar5 + uVar21;
      piVar14[2] = iVar5 + uVar26;
      piVar14[3] = iVar5 + uVar35;
      uVar96 = (uVar20 >> 7 ^ uVar20 << 0x19 ^ uVar20 >> 0x12 ^ uVar20 << 0xe ^ uVar20 >> 3) +
               uVar16 + uVar27 +
               (uVar84 >> 0x11 ^ uVar84 << 0xf ^ uVar84 >> 0x13 ^ uVar84 << 0xd ^ uVar84 >> 10);
      uVar97 = (uVar25 >> 7 ^ uVar25 << 0x19 ^ uVar25 >> 0x12 ^ uVar25 << 0xe ^ uVar25 >> 3) +
               uVar21 + uVar32 +
               (uVar85 >> 0x11 ^ uVar85 << 0xf ^ uVar85 >> 0x13 ^ uVar85 << 0xd ^ uVar85 >> 10);
      uVar98 = (uVar31 >> 7 ^ uVar31 << 0x19 ^ uVar31 >> 0x12 ^ uVar31 << 0xe ^ uVar31 >> 3) +
               uVar26 + uVar33 +
               (uVar86 >> 0x11 ^ uVar86 << 0xf ^ uVar86 >> 0x13 ^ uVar86 << 0xd ^ uVar86 >> 10);
      uVar99 = (uVar40 >> 7 ^ uVar40 << 0x19 ^ uVar40 >> 0x12 ^ uVar40 << 0xe ^ uVar40 >> 3) +
               uVar35 + uVar34 +
               (uVar87 >> 0x11 ^ uVar87 << 0xf ^ uVar87 >> 0x13 ^ uVar87 << 0xd ^ uVar87 >> 10);
      uVar16 = piVar14[8];
      uVar21 = piVar14[9];
      uVar26 = piVar14[10];
      uVar35 = piVar14[0xb];
      piVar14[0x40] = uVar96;
      piVar14[0x41] = uVar97;
      piVar14[0x42] = uVar98;
      piVar14[0x43] = uVar99;
      iVar5 = piVar15[1];
      piVar14[4] = iVar5 + uVar20;
      piVar14[5] = iVar5 + uVar25;
      piVar14[6] = iVar5 + uVar31;
      piVar14[7] = iVar5 + uVar40;
      uVar27 = (uVar16 >> 7 ^ uVar16 << 0x19 ^ uVar16 >> 0x12 ^ uVar16 << 0xe ^ uVar16 >> 3) +
               uVar20 + uVar36 +
               (uVar88 >> 0x11 ^ uVar88 << 0xf ^ uVar88 >> 0x13 ^ uVar88 << 0xd ^ uVar88 >> 10);
      uVar32 = (uVar21 >> 7 ^ uVar21 << 0x19 ^ uVar21 >> 0x12 ^ uVar21 << 0xe ^ uVar21 >> 3) +
               uVar25 + uVar41 +
               (uVar93 >> 0x11 ^ uVar93 << 0xf ^ uVar93 >> 0x13 ^ uVar93 << 0xd ^ uVar93 >> 10);
      uVar33 = (uVar26 >> 7 ^ uVar26 << 0x19 ^ uVar26 >> 0x12 ^ uVar26 << 0xe ^ uVar26 >> 3) +
               uVar31 + uVar42 +
               (uVar94 >> 0x11 ^ uVar94 << 0xf ^ uVar94 >> 0x13 ^ uVar94 << 0xd ^ uVar94 >> 10);
      uVar34 = (uVar35 >> 7 ^ uVar35 << 0x19 ^ uVar35 >> 0x12 ^ uVar35 << 0xe ^ uVar35 >> 3) +
               uVar40 + uVar43 +
               (uVar95 >> 0x11 ^ uVar95 << 0xf ^ uVar95 >> 0x13 ^ uVar95 << 0xd ^ uVar95 >> 10);
      uVar20 = piVar14[0xc];
      uVar25 = piVar14[0xd];
      uVar31 = piVar14[0xe];
      uVar40 = piVar14[0xf];
      piVar14[0x44] = uVar27;
      piVar14[0x45] = uVar32;
      piVar14[0x46] = uVar33;
      piVar14[0x47] = uVar34;
      iVar5 = piVar15[2];
      piVar14[8] = iVar5 + uVar16;
      piVar14[9] = iVar5 + uVar21;
      piVar14[10] = iVar5 + uVar26;
      piVar14[0xb] = iVar5 + uVar35;
      uVar36 = (uVar20 >> 7 ^ uVar20 << 0x19 ^ uVar20 >> 0x12 ^ uVar20 << 0xe ^ uVar20 >> 3) +
               uVar16 + uVar44 +
               (uVar96 >> 0x11 ^ uVar96 * 0x8000 ^ uVar96 >> 0x13 ^ uVar96 * 0x2000 ^ uVar96 >> 10);
      uVar41 = (uVar25 >> 7 ^ uVar25 << 0x19 ^ uVar25 >> 0x12 ^ uVar25 << 0xe ^ uVar25 >> 3) +
               uVar21 + uVar61 +
               (uVar97 >> 0x11 ^ uVar97 * 0x8000 ^ uVar97 >> 0x13 ^ uVar97 * 0x2000 ^ uVar97 >> 10);
      uVar42 = (uVar31 >> 7 ^ uVar31 << 0x19 ^ uVar31 >> 0x12 ^ uVar31 << 0xe ^ uVar31 >> 3) +
               uVar26 + uVar62 +
               (uVar98 >> 0x11 ^ uVar98 * 0x8000 ^ uVar98 >> 0x13 ^ uVar98 * 0x2000 ^ uVar98 >> 10);
      uVar43 = (uVar40 >> 7 ^ uVar40 << 0x19 ^ uVar40 >> 0x12 ^ uVar40 << 0xe ^ uVar40 >> 3) +
               uVar35 + uVar63 +
               (uVar99 >> 0x11 ^ uVar99 * 0x8000 ^ uVar99 >> 0x13 ^ uVar99 * 0x2000 ^ uVar99 >> 10);
      uVar16 = piVar14[0x10];
      uVar21 = piVar14[0x11];
      uVar26 = piVar14[0x12];
      uVar35 = piVar14[0x13];
      piVar14[0x48] = uVar36;
      piVar14[0x49] = uVar41;
      piVar14[0x4a] = uVar42;
      piVar14[0x4b] = uVar43;
      iVar5 = piVar15[3];
      piVar14[0xc] = iVar5 + uVar20;
      piVar14[0xd] = iVar5 + uVar25;
      piVar14[0xe] = iVar5 + uVar31;
      piVar14[0xf] = iVar5 + uVar40;
      uVar44 = (uVar16 >> 7 ^ uVar16 << 0x19 ^ uVar16 >> 0x12 ^ uVar16 << 0xe ^ uVar16 >> 3) +
               uVar20 + uVar64 +
               (uVar27 >> 0x11 ^ uVar27 * 0x8000 ^ uVar27 >> 0x13 ^ uVar27 * 0x2000 ^ uVar27 >> 10);
      uVar61 = (uVar21 >> 7 ^ uVar21 << 0x19 ^ uVar21 >> 0x12 ^ uVar21 << 0xe ^ uVar21 >> 3) +
               uVar25 + uVar69 +
               (uVar32 >> 0x11 ^ uVar32 * 0x8000 ^ uVar32 >> 0x13 ^ uVar32 * 0x2000 ^ uVar32 >> 10);
      uVar62 = (uVar26 >> 7 ^ uVar26 << 0x19 ^ uVar26 >> 0x12 ^ uVar26 << 0xe ^ uVar26 >> 3) +
               uVar31 + uVar70 +
               (uVar33 >> 0x11 ^ uVar33 * 0x8000 ^ uVar33 >> 0x13 ^ uVar33 * 0x2000 ^ uVar33 >> 10);
      uVar63 = (uVar35 >> 7 ^ uVar35 << 0x19 ^ uVar35 >> 0x12 ^ uVar35 << 0xe ^ uVar35 >> 3) +
               uVar40 + uVar71 +
               (uVar34 >> 0x11 ^ uVar34 * 0x8000 ^ uVar34 >> 0x13 ^ uVar34 * 0x2000 ^ uVar34 >> 10);
      uVar20 = piVar14[0x14];
      uVar25 = piVar14[0x15];
      uVar31 = piVar14[0x16];
      uVar40 = piVar14[0x17];
      piVar14[0x4c] = uVar44;
      piVar14[0x4d] = uVar61;
      piVar14[0x4e] = uVar62;
      piVar14[0x4f] = uVar63;
      iVar5 = piVar15[4];
      piVar14[0x10] = iVar5 + uVar16;
      piVar14[0x11] = iVar5 + uVar21;
      piVar14[0x12] = iVar5 + uVar26;
      piVar14[0x13] = iVar5 + uVar35;
      uVar64 = (uVar20 >> 7 ^ uVar20 << 0x19 ^ uVar20 >> 0x12 ^ uVar20 << 0xe ^ uVar20 >> 3) +
               uVar16 + uVar72 +
               (uVar36 >> 0x11 ^ uVar36 * 0x8000 ^ uVar36 >> 0x13 ^ uVar36 * 0x2000 ^ uVar36 >> 10);
      uVar69 = (uVar25 >> 7 ^ uVar25 << 0x19 ^ uVar25 >> 0x12 ^ uVar25 << 0xe ^ uVar25 >> 3) +
               uVar21 + uVar81 +
               (uVar41 >> 0x11 ^ uVar41 * 0x8000 ^ uVar41 >> 0x13 ^ uVar41 * 0x2000 ^ uVar41 >> 10);
      uVar70 = (uVar31 >> 7 ^ uVar31 << 0x19 ^ uVar31 >> 0x12 ^ uVar31 << 0xe ^ uVar31 >> 3) +
               uVar26 + uVar82 +
               (uVar42 >> 0x11 ^ uVar42 * 0x8000 ^ uVar42 >> 0x13 ^ uVar42 * 0x2000 ^ uVar42 >> 10);
      uVar71 = (uVar40 >> 7 ^ uVar40 << 0x19 ^ uVar40 >> 0x12 ^ uVar40 << 0xe ^ uVar40 >> 3) +
               uVar35 + uVar83 +
               (uVar43 >> 0x11 ^ uVar43 * 0x8000 ^ uVar43 >> 0x13 ^ uVar43 * 0x2000 ^ uVar43 >> 10);
      uVar16 = piVar14[0x18];
      uVar21 = piVar14[0x19];
      uVar26 = piVar14[0x1a];
      uVar35 = piVar14[0x1b];
      piVar14[0x50] = uVar64;
      piVar14[0x51] = uVar69;
      piVar14[0x52] = uVar70;
      piVar14[0x53] = uVar71;
      iVar5 = piVar15[5];
      piVar14[0x14] = iVar5 + uVar20;
      piVar14[0x15] = iVar5 + uVar25;
      piVar14[0x16] = iVar5 + uVar31;
      piVar14[0x17] = iVar5 + uVar40;
      uVar72 = (uVar16 >> 7 ^ uVar16 << 0x19 ^ uVar16 >> 0x12 ^ uVar16 << 0xe ^ uVar16 >> 3) +
               uVar20 + uVar84 +
               (uVar44 >> 0x11 ^ uVar44 * 0x8000 ^ uVar44 >> 0x13 ^ uVar44 * 0x2000 ^ uVar44 >> 10);
      uVar81 = (uVar21 >> 7 ^ uVar21 << 0x19 ^ uVar21 >> 0x12 ^ uVar21 << 0xe ^ uVar21 >> 3) +
               uVar25 + uVar85 +
               (uVar61 >> 0x11 ^ uVar61 * 0x8000 ^ uVar61 >> 0x13 ^ uVar61 * 0x2000 ^ uVar61 >> 10);
      uVar82 = (uVar26 >> 7 ^ uVar26 << 0x19 ^ uVar26 >> 0x12 ^ uVar26 << 0xe ^ uVar26 >> 3) +
               uVar31 + uVar86 +
               (uVar62 >> 0x11 ^ uVar62 * 0x8000 ^ uVar62 >> 0x13 ^ uVar62 * 0x2000 ^ uVar62 >> 10);
      uVar83 = (uVar35 >> 7 ^ uVar35 << 0x19 ^ uVar35 >> 0x12 ^ uVar35 << 0xe ^ uVar35 >> 3) +
               uVar40 + uVar87 +
               (uVar63 >> 0x11 ^ uVar63 * 0x8000 ^ uVar63 >> 0x13 ^ uVar63 * 0x2000 ^ uVar63 >> 10);
      uVar20 = piVar14[0x1c];
      uVar25 = piVar14[0x1d];
      uVar31 = piVar14[0x1e];
      uVar40 = piVar14[0x1f];
      piVar14[0x54] = uVar72;
      piVar14[0x55] = uVar81;
      piVar14[0x56] = uVar82;
      piVar14[0x57] = uVar83;
      iVar5 = piVar15[6];
      piVar14[0x18] = iVar5 + uVar16;
      piVar14[0x19] = iVar5 + uVar21;
      piVar14[0x1a] = iVar5 + uVar26;
      piVar14[0x1b] = iVar5 + uVar35;
      uVar84 = (uVar20 >> 7 ^ uVar20 << 0x19 ^ uVar20 >> 0x12 ^ uVar20 << 0xe ^ uVar20 >> 3) +
               uVar16 + uVar88 +
               (uVar64 >> 0x11 ^ uVar64 * 0x8000 ^ uVar64 >> 0x13 ^ uVar64 * 0x2000 ^ uVar64 >> 10);
      uVar85 = (uVar25 >> 7 ^ uVar25 << 0x19 ^ uVar25 >> 0x12 ^ uVar25 << 0xe ^ uVar25 >> 3) +
               uVar21 + uVar93 +
               (uVar69 >> 0x11 ^ uVar69 * 0x8000 ^ uVar69 >> 0x13 ^ uVar69 * 0x2000 ^ uVar69 >> 10);
      uVar86 = (uVar31 >> 7 ^ uVar31 << 0x19 ^ uVar31 >> 0x12 ^ uVar31 << 0xe ^ uVar31 >> 3) +
               uVar26 + uVar94 +
               (uVar70 >> 0x11 ^ uVar70 * 0x8000 ^ uVar70 >> 0x13 ^ uVar70 * 0x2000 ^ uVar70 >> 10);
      uVar87 = (uVar40 >> 7 ^ uVar40 << 0x19 ^ uVar40 >> 0x12 ^ uVar40 << 0xe ^ uVar40 >> 3) +
               uVar35 + uVar95 +
               (uVar71 >> 0x11 ^ uVar71 * 0x8000 ^ uVar71 >> 0x13 ^ uVar71 * 0x2000 ^ uVar71 >> 10);
      uVar16 = piVar14[0x20];
      uVar21 = piVar14[0x21];
      uVar26 = piVar14[0x22];
      uVar35 = piVar14[0x23];
      piVar14[0x58] = uVar84;
      piVar14[0x59] = uVar85;
      piVar14[0x5a] = uVar86;
      piVar14[0x5b] = uVar87;
      iVar5 = piVar15[7];
      piVar14[0x1c] = iVar5 + uVar20;
      piVar14[0x1d] = iVar5 + uVar25;
      piVar14[0x1e] = iVar5 + uVar31;
      piVar14[0x1f] = iVar5 + uVar40;
      uVar88 = (uVar16 >> 7 ^ uVar16 << 0x19 ^ uVar16 >> 0x12 ^ uVar16 << 0xe ^ uVar16 >> 3) +
               uVar20 + uVar96 +
               (uVar72 >> 0x11 ^ uVar72 * 0x8000 ^ uVar72 >> 0x13 ^ uVar72 * 0x2000 ^ uVar72 >> 10);
      uVar93 = (uVar21 >> 7 ^ uVar21 << 0x19 ^ uVar21 >> 0x12 ^ uVar21 << 0xe ^ uVar21 >> 3) +
               uVar25 + uVar97 +
               (uVar81 >> 0x11 ^ uVar81 * 0x8000 ^ uVar81 >> 0x13 ^ uVar81 * 0x2000 ^ uVar81 >> 10);
      uVar94 = (uVar26 >> 7 ^ uVar26 << 0x19 ^ uVar26 >> 0x12 ^ uVar26 << 0xe ^ uVar26 >> 3) +
               uVar31 + uVar98 +
               (uVar82 >> 0x11 ^ uVar82 * 0x8000 ^ uVar82 >> 0x13 ^ uVar82 * 0x2000 ^ uVar82 >> 10);
      uVar95 = (uVar35 >> 7 ^ uVar35 << 0x19 ^ uVar35 >> 0x12 ^ uVar35 << 0xe ^ uVar35 >> 3) +
               uVar40 + uVar99 +
               (uVar83 >> 0x11 ^ uVar83 * 0x8000 ^ uVar83 >> 0x13 ^ uVar83 * 0x2000 ^ uVar83 >> 10);
      uVar20 = piVar14[0x24];
      uVar25 = piVar14[0x25];
      uVar31 = piVar14[0x26];
      uVar40 = piVar14[0x27];
      piVar14[0x5c] = uVar88;
      piVar14[0x5d] = uVar93;
      piVar14[0x5e] = uVar94;
      piVar14[0x5f] = uVar95;
      iVar5 = uVar6 + *piVar14 + (uVar11 & uVar10 ^ ~uVar10 & uVar12) +
              ((uVar10 >> 6 | uVar10 << 0x1a) ^ (uVar10 >> 0xb | uVar10 << 0x15) ^
              (uVar10 >> 0x19 | uVar10 << 7));
      uVar9 = uVar9 + iVar5;
      uVar6 = iVar5 + (uVar2 & uVar3 | (uVar2 | uVar3) & uVar1) +
              ((uVar1 >> 2 | uVar1 << 0x1e) ^ (uVar1 >> 0xd | uVar1 << 0x13) ^
              (uVar1 >> 0x16 | uVar1 << 10));
      iVar5 = uVar12 + piVar14[4] + (uVar10 & uVar9 ^ ~uVar9 & uVar11) +
              ((uVar9 >> 6 | uVar9 * 0x4000000) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
              (uVar9 >> 0x19 | uVar9 * 0x80));
      uVar3 = uVar3 + iVar5;
      uVar12 = iVar5 + (uVar1 & uVar2 | (uVar1 | uVar2) & uVar6) +
               ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
               (uVar6 >> 0x16 | uVar6 * 0x400));
      iVar5 = uVar11 + piVar14[8] + (uVar9 & uVar3 ^ ~uVar3 & uVar10) +
              ((uVar3 >> 6 | uVar3 * 0x4000000) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
              (uVar3 >> 0x19 | uVar3 * 0x80));
      uVar2 = uVar2 + iVar5;
      uVar11 = iVar5 + (uVar6 & uVar1 | (uVar6 | uVar1) & uVar12) +
               ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
               (uVar12 >> 0x16 | uVar12 * 0x400));
      iVar5 = uVar10 + piVar14[0xc] + (uVar3 & uVar2 ^ ~uVar2 & uVar9) +
              ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^
              (uVar2 >> 0x19 | uVar2 * 0x80));
      uVar1 = uVar1 + iVar5;
      uVar10 = iVar5 + (uVar12 & uVar6 | (uVar12 | uVar6) & uVar11) +
               ((uVar11 >> 2 | uVar11 * 0x40000000) ^ (uVar11 >> 0xd | uVar11 * 0x80000) ^
               (uVar11 >> 0x16 | uVar11 * 0x400));
      iVar5 = uVar9 + piVar14[0x10] + (uVar2 & uVar1 ^ ~uVar1 & uVar3) +
              ((uVar1 >> 6 | uVar1 * 0x4000000) ^ (uVar1 >> 0xb | uVar1 * 0x200000) ^
              (uVar1 >> 0x19 | uVar1 * 0x80));
      uVar6 = uVar6 + iVar5;
      uVar9 = iVar5 + (uVar11 & uVar12 | (uVar11 | uVar12) & uVar10) +
              ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
              (uVar10 >> 0x16 | uVar10 * 0x400));
      iVar5 = uVar3 + piVar14[0x14] + (uVar1 & uVar6 ^ ~uVar6 & uVar2) +
              ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
              (uVar6 >> 0x19 | uVar6 * 0x80));
      uVar12 = uVar12 + iVar5;
      uVar3 = iVar5 + (uVar10 & uVar11 | (uVar10 | uVar11) & uVar9) +
              ((uVar9 >> 2 | uVar9 * 0x40000000) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
              (uVar9 >> 0x16 | uVar9 * 0x400));
      iVar5 = uVar2 + piVar14[0x18] + (uVar6 & uVar12 ^ ~uVar12 & uVar1) +
              ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^
              (uVar12 >> 0x19 | uVar12 * 0x80));
      uVar11 = uVar11 + iVar5;
      uVar2 = iVar5 + (uVar9 & uVar10 | (uVar9 | uVar10) & uVar3) +
              ((uVar3 >> 2 | uVar3 * 0x40000000) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
              (uVar3 >> 0x16 | uVar3 * 0x400));
      iVar5 = uVar1 + piVar14[0x1c] + (uVar12 & uVar11 ^ ~uVar11 & uVar6) +
              ((uVar11 >> 6 | uVar11 * 0x4000000) ^ (uVar11 >> 0xb | uVar11 * 0x200000) ^
              (uVar11 >> 0x19 | uVar11 * 0x80));
      uVar10 = uVar10 + iVar5;
      uVar1 = iVar5 + (uVar3 & uVar9 | (uVar3 | uVar9) & uVar2) +
              ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^
              (uVar2 >> 0x16 | uVar2 * 0x400));
      piVar14 = piVar14 + 0x20;
      piVar15 = piVar15 + 8;
    } while (piVar15 < &DAT_1800159c0);
    do {
      iVar5 = *piVar15;
      *piVar14 = iVar5 + *piVar14;
      piVar14[1] = iVar5 + piVar14[1];
      piVar14[2] = iVar5 + piVar14[2];
      piVar14[3] = iVar5 + piVar14[3];
      iVar5 = piVar15[1];
      piVar14[4] = iVar5 + piVar14[4];
      piVar14[5] = iVar5 + piVar14[5];
      piVar14[6] = iVar5 + piVar14[6];
      piVar14[7] = iVar5 + piVar14[7];
      iVar5 = piVar15[2];
      piVar14[8] = iVar5 + piVar14[8];
      piVar14[9] = iVar5 + piVar14[9];
      piVar14[10] = iVar5 + piVar14[10];
      piVar14[0xb] = iVar5 + piVar14[0xb];
      iVar5 = piVar15[3];
      piVar14[0xc] = iVar5 + piVar14[0xc];
      piVar14[0xd] = iVar5 + piVar14[0xd];
      piVar14[0xe] = iVar5 + piVar14[0xe];
      piVar14[0xf] = iVar5 + piVar14[0xf];
      iVar5 = piVar15[4];
      piVar14[0x10] = iVar5 + piVar14[0x10];
      piVar14[0x11] = iVar5 + piVar14[0x11];
      piVar14[0x12] = iVar5 + piVar14[0x12];
      piVar14[0x13] = iVar5 + piVar14[0x13];
      iVar5 = piVar15[5];
      piVar14[0x14] = iVar5 + piVar14[0x14];
      piVar14[0x15] = iVar5 + piVar14[0x15];
      piVar14[0x16] = iVar5 + piVar14[0x16];
      piVar14[0x17] = iVar5 + piVar14[0x17];
      iVar5 = piVar15[6];
      piVar14[0x18] = iVar5 + piVar14[0x18];
      piVar14[0x19] = iVar5 + piVar14[0x19];
      piVar14[0x1a] = iVar5 + piVar14[0x1a];
      piVar14[0x1b] = iVar5 + piVar14[0x1b];
      iVar5 = piVar15[7];
      piVar14[0x1c] = iVar5 + piVar14[0x1c];
      piVar14[0x1d] = iVar5 + piVar14[0x1d];
      piVar14[0x1e] = iVar5 + piVar14[0x1e];
      piVar14[0x1f] = iVar5 + piVar14[0x1f];
      iVar5 = uVar6 + *piVar14 + (uVar11 & uVar10 ^ ~uVar10 & uVar12) +
              ((uVar10 >> 6 | uVar10 << 0x1a) ^ (uVar10 >> 0xb | uVar10 << 0x15) ^
              (uVar10 >> 0x19 | uVar10 << 7));
      uVar9 = uVar9 + iVar5;
      uVar6 = iVar5 + (uVar2 & uVar3 | (uVar2 | uVar3) & uVar1) +
              ((uVar1 >> 2 | uVar1 << 0x1e) ^ (uVar1 >> 0xd | uVar1 << 0x13) ^
              (uVar1 >> 0x16 | uVar1 << 10));
      iVar5 = uVar12 + piVar14[4] + (uVar10 & uVar9 ^ ~uVar9 & uVar11) +
              ((uVar9 >> 6 | uVar9 * 0x4000000) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
              (uVar9 >> 0x19 | uVar9 * 0x80));
      uVar3 = uVar3 + iVar5;
      uVar12 = iVar5 + (uVar1 & uVar2 | (uVar1 | uVar2) & uVar6) +
               ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
               (uVar6 >> 0x16 | uVar6 * 0x400));
      iVar5 = uVar11 + piVar14[8] + (uVar9 & uVar3 ^ ~uVar3 & uVar10) +
              ((uVar3 >> 6 | uVar3 * 0x4000000) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
              (uVar3 >> 0x19 | uVar3 * 0x80));
      uVar2 = uVar2 + iVar5;
      uVar11 = iVar5 + (uVar6 & uVar1 | (uVar6 | uVar1) & uVar12) +
               ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
               (uVar12 >> 0x16 | uVar12 * 0x400));
      iVar5 = uVar10 + piVar14[0xc] + (uVar3 & uVar2 ^ ~uVar2 & uVar9) +
              ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^
              (uVar2 >> 0x19 | uVar2 * 0x80));
      uVar1 = uVar1 + iVar5;
      uVar10 = iVar5 + (uVar12 & uVar6 | (uVar12 | uVar6) & uVar11) +
               ((uVar11 >> 2 | uVar11 * 0x40000000) ^ (uVar11 >> 0xd | uVar11 * 0x80000) ^
               (uVar11 >> 0x16 | uVar11 * 0x400));
      iVar5 = uVar9 + piVar14[0x10] + (uVar2 & uVar1 ^ ~uVar1 & uVar3) +
              ((uVar1 >> 6 | uVar1 * 0x4000000) ^ (uVar1 >> 0xb | uVar1 * 0x200000) ^
              (uVar1 >> 0x19 | uVar1 * 0x80));
      uVar6 = uVar6 + iVar5;
      uVar9 = iVar5 + (uVar11 & uVar12 | (uVar11 | uVar12) & uVar10) +
              ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
              (uVar10 >> 0x16 | uVar10 * 0x400));
      iVar5 = uVar3 + piVar14[0x14] + (uVar1 & uVar6 ^ ~uVar6 & uVar2) +
              ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
              (uVar6 >> 0x19 | uVar6 * 0x80));
      uVar12 = uVar12 + iVar5;
      uVar3 = iVar5 + (uVar10 & uVar11 | (uVar10 | uVar11) & uVar9) +
              ((uVar9 >> 2 | uVar9 * 0x40000000) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
              (uVar9 >> 0x16 | uVar9 * 0x400));
      iVar5 = uVar2 + piVar14[0x18] + (uVar6 & uVar12 ^ ~uVar12 & uVar1) +
              ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^
              (uVar12 >> 0x19 | uVar12 * 0x80));
      uVar11 = uVar11 + iVar5;
      uVar2 = iVar5 + (uVar9 & uVar10 | (uVar9 | uVar10) & uVar3) +
              ((uVar3 >> 2 | uVar3 * 0x40000000) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
              (uVar3 >> 0x16 | uVar3 * 0x400));
      iVar5 = uVar1 + piVar14[0x1c] + (uVar12 & uVar11 ^ ~uVar11 & uVar6) +
              ((uVar11 >> 6 | uVar11 * 0x4000000) ^ (uVar11 >> 0xb | uVar11 * 0x200000) ^
              (uVar11 >> 0x19 | uVar11 * 0x80));
      uVar10 = uVar10 + iVar5;
      uVar1 = iVar5 + (uVar3 & uVar9 | (uVar3 | uVar9) & uVar2) +
              ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^
              (uVar2 >> 0x16 | uVar2 * 0x400));
      piVar14 = piVar14 + 0x20;
      piVar15 = piVar15 + 8;
    } while (piVar15 < &__xmm_0c0d0e0f08090a0b0405060700010203);
    uVar1 = uVar1 + *param_1;
    *param_1 = uVar1;
    uVar2 = uVar2 + param_1[1];
    param_1[1] = uVar2;
    uVar3 = uVar3 + param_1[2];
    param_1[2] = uVar3;
    uVar9 = uVar9 + param_1[3];
    param_1[3] = uVar9;
    uVar10 = uVar10 + param_1[4];
    param_1[4] = uVar10;
    uVar11 = uVar11 + param_1[5];
    param_1[5] = uVar11;
    uVar12 = uVar12 + param_1[6];
    param_1[6] = uVar12;
    uVar6 = uVar6 + param_1[7];
    param_1[7] = uVar6;
    local_f8 = local_f8 - 1;
    piVar14 = (int *)((longlong)&local_4f8 + 4);
    do {
      iVar5 = 8;
      do {
        piVar15 = piVar14;
        iVar7 = uVar6 + *piVar15 + (uVar11 & uVar10 ^ ~uVar10 & uVar12) +
                ((uVar10 >> 6 | uVar10 << 0x1a) ^ (uVar10 >> 0xb | uVar10 << 0x15) ^
                (uVar10 >> 0x19 | uVar10 << 7));
        uVar9 = uVar9 + iVar7;
        uVar6 = iVar7 + (uVar2 & uVar3 | (uVar2 | uVar3) & uVar1) +
                ((uVar1 >> 2 | uVar1 << 0x1e) ^ (uVar1 >> 0xd | uVar1 << 0x13) ^
                (uVar1 >> 0x16 | uVar1 << 10));
        iVar7 = uVar12 + piVar15[4] + (uVar10 & uVar9 ^ ~uVar9 & uVar11) +
                ((uVar9 >> 6 | uVar9 * 0x4000000) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
                (uVar9 >> 0x19 | uVar9 * 0x80));
        uVar3 = uVar3 + iVar7;
        uVar12 = iVar7 + (uVar1 & uVar2 | (uVar1 | uVar2) & uVar6) +
                 ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
                 (uVar6 >> 0x16 | uVar6 * 0x400));
        iVar7 = uVar11 + piVar15[8] + (uVar9 & uVar3 ^ ~uVar3 & uVar10) +
                ((uVar3 >> 6 | uVar3 * 0x4000000) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
                (uVar3 >> 0x19 | uVar3 * 0x80));
        uVar2 = uVar2 + iVar7;
        uVar11 = iVar7 + (uVar6 & uVar1 | (uVar6 | uVar1) & uVar12) +
                 ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
                 (uVar12 >> 0x16 | uVar12 * 0x400));
        iVar7 = uVar10 + piVar15[0xc] + (uVar3 & uVar2 ^ ~uVar2 & uVar9) +
                ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^
                (uVar2 >> 0x19 | uVar2 * 0x80));
        uVar1 = uVar1 + iVar7;
        uVar10 = iVar7 + (uVar12 & uVar6 | (uVar12 | uVar6) & uVar11) +
                 ((uVar11 >> 2 | uVar11 * 0x40000000) ^ (uVar11 >> 0xd | uVar11 * 0x80000) ^
                 (uVar11 >> 0x16 | uVar11 * 0x400));
        iVar7 = uVar9 + piVar15[0x10] + (uVar2 & uVar1 ^ ~uVar1 & uVar3) +
                ((uVar1 >> 6 | uVar1 * 0x4000000) ^ (uVar1 >> 0xb | uVar1 * 0x200000) ^
                (uVar1 >> 0x19 | uVar1 * 0x80));
        uVar6 = uVar6 + iVar7;
        uVar9 = iVar7 + (uVar11 & uVar12 | (uVar11 | uVar12) & uVar10) +
                ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
                (uVar10 >> 0x16 | uVar10 * 0x400));
        iVar7 = uVar3 + piVar15[0x14] + (uVar1 & uVar6 ^ ~uVar6 & uVar2) +
                ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
                (uVar6 >> 0x19 | uVar6 * 0x80));
        uVar12 = uVar12 + iVar7;
        uVar3 = iVar7 + (uVar10 & uVar11 | (uVar10 | uVar11) & uVar9) +
                ((uVar9 >> 2 | uVar9 * 0x40000000) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
                (uVar9 >> 0x16 | uVar9 * 0x400));
        iVar7 = uVar2 + piVar15[0x18] + (uVar6 & uVar12 ^ ~uVar12 & uVar1) +
                ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^
                (uVar12 >> 0x19 | uVar12 * 0x80));
        uVar11 = uVar11 + iVar7;
        uVar2 = iVar7 + (uVar9 & uVar10 | (uVar9 | uVar10) & uVar3) +
                ((uVar3 >> 2 | uVar3 * 0x40000000) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
                (uVar3 >> 0x16 | uVar3 * 0x400));
        iVar7 = uVar1 + piVar15[0x1c] + (uVar12 & uVar11 ^ ~uVar11 & uVar6) +
                ((uVar11 >> 6 | uVar11 * 0x4000000) ^ (uVar11 >> 0xb | uVar11 * 0x200000) ^
                (uVar11 >> 0x19 | uVar11 * 0x80));
        uVar10 = uVar10 + iVar7;
        uVar1 = iVar7 + (uVar3 & uVar9 | (uVar3 | uVar9) & uVar2) +
                ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^
                (uVar2 >> 0x16 | uVar2 * 0x400));
        iVar5 = iVar5 + -1;
        piVar14 = piVar15 + 0x20;
      } while (iVar5 != 0);
      piVar14 = piVar15 + -0xdf;
      uVar1 = uVar1 + *param_1;
      *param_1 = uVar1;
      uVar2 = uVar2 + param_1[1];
      param_1[1] = uVar2;
      uVar3 = uVar3 + param_1[2];
      param_1[2] = uVar3;
      uVar9 = uVar9 + param_1[3];
      param_1[3] = uVar9;
      uVar10 = uVar10 + param_1[4];
      param_1[4] = uVar10;
      uVar11 = uVar11 + param_1[5];
      param_1[5] = uVar11;
      uVar12 = uVar12 + param_1[6];
      param_1[6] = uVar12;
      uVar6 = uVar6 + param_1[7];
      param_1[7] = uVar6;
      local_f8 = local_f8 + -1;
    } while (local_f8 != 0);
    uVar4 = param_3;
    if (0x100 < param_3) {
      uVar4 = 0x100;
    }
    param_2 = (undefined1 (*) [16])(*param_2 + (uVar4 & 0xffffffffffffffc0));
    param_3 = param_3 - (uVar4 & 0xffffffffffffffc0);
    auVar18 = _BYTE_REVERSE_32;
    auVar17 = _XMM_PACKLOW;
    auVar23 = _XMM_PACKHIGH;
  }
  for (; 0x3f < param_3; param_3 = param_3 - 0x40) {
    auVar19 = pshufb(*param_2,auVar18);
    auVar24 = pshufb(param_2[1],auVar18);
    auVar30 = pshufb(param_2[2],auVar18);
    auVar39 = pshufb(param_2[3],auVar18);
    local_4f8._4_4_ = auVar19._4_4_ + 0x71374491;
    local_4f8._0_4_ = auVar19._0_4_ + 0x428a2f98;
    uStack_4f0._0_4_ = auVar19._8_4_ + -0x4a3f0431;
    uStack_4f0._4_4_ = auVar19._12_4_ + -0x164a245b;
    local_4e8._4_4_ = auVar24._4_4_ + 0x59f111f1;
    local_4e8._0_4_ = auVar24._0_4_ + 0x3956c25b;
    uStack_4e0._0_4_ = auVar24._8_4_ + -0x6dc07d5c;
    uStack_4e0._4_4_ = auVar24._12_4_ + -0x54e3a12b;
    iStack_4d4 = auVar30._4_4_ + 0x12835b01;
    local_4d8 = auVar30._0_4_ + -0x27f85568;
    iStack_4d0 = auVar30._8_4_ + 0x243185be;
    iStack_4cc = auVar30._12_4_ + 0x550c7dc3;
    iStack_4c4 = auVar39._4_4_ + -0x7f214e02;
    local_4c8 = auVar39._0_4_ + 0x72be5d74;
    iStack_4c0 = auVar39._8_4_ + -0x6423f959;
    iStack_4bc = auVar39._12_4_ + -0x3e640e8c;
    piVar14 = &SymCryptSha256K;
    do {
      piVar15 = piVar14 + 0x10;
      iVar5 = uVar6 + (int)local_4f8 + (uVar11 & uVar10 ^ ~uVar10 & uVar12) +
              ((uVar10 >> 6 | uVar10 << 0x1a) ^ (uVar10 >> 0xb | uVar10 << 0x15) ^
              (uVar10 >> 0x19 | uVar10 << 7));
      uVar9 = uVar9 + iVar5;
      uVar6 = iVar5 + (uVar2 & uVar3 | (uVar2 | uVar3) & uVar1) +
              ((uVar1 >> 2 | uVar1 << 0x1e) ^ (uVar1 >> 0xd | uVar1 << 0x13) ^
              (uVar1 >> 0x16 | uVar1 << 10));
      iVar5 = uVar12 + local_4f8._4_4_ + (uVar10 & uVar9 ^ ~uVar9 & uVar11) +
              ((uVar9 >> 6 | uVar9 * 0x4000000) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
              (uVar9 >> 0x19 | uVar9 * 0x80));
      uVar3 = uVar3 + iVar5;
      uVar12 = iVar5 + (uVar1 & uVar2 | (uVar1 | uVar2) & uVar6) +
               ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
               (uVar6 >> 0x16 | uVar6 * 0x400));
      iVar5 = uVar11 + (int)uStack_4f0 + (uVar9 & uVar3 ^ ~uVar3 & uVar10) +
              ((uVar3 >> 6 | uVar3 * 0x4000000) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
              (uVar3 >> 0x19 | uVar3 * 0x80));
      uVar2 = uVar2 + iVar5;
      uVar11 = iVar5 + (uVar6 & uVar1 | (uVar6 | uVar1) & uVar12) +
               ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
               (uVar12 >> 0x16 | uVar12 * 0x400));
      iVar5 = uVar10 + uStack_4f0._4_4_ + (uVar3 & uVar2 ^ ~uVar2 & uVar9) +
              ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^
              (uVar2 >> 0x19 | uVar2 * 0x80));
      uVar1 = uVar1 + iVar5;
      uVar10 = iVar5 + (uVar12 & uVar6 | (uVar12 | uVar6) & uVar11) +
               ((uVar11 >> 2 | uVar11 * 0x40000000) ^ (uVar11 >> 0xd | uVar11 * 0x80000) ^
               (uVar11 >> 0x16 | uVar11 * 0x400));
      uVar26 = auVar39._0_4_;
      uVar35 = auVar39._4_4_;
      uVar20 = auVar39._8_4_;
      uVar25 = auVar39._12_4_;
      auVar45._0_8_ = CONCAT44(uVar20,uVar20);
      auVar45._8_4_ = uVar25;
      auVar45._12_4_ = uVar25;
      auVar89._0_8_ = auVar45._0_8_ >> 0x11;
      auVar89._8_8_ = auVar45._8_8_ >> 0x11;
      auVar73._0_8_ = auVar45._0_8_ >> 0x13;
      auVar73._8_8_ = auVar45._8_8_ >> 0x13;
      auVar46._0_4_ = uVar20 >> 10;
      auVar46._4_4_ = uVar20 >> 10;
      auVar46._8_4_ = uVar25 >> 10;
      auVar46._12_4_ = uVar25 >> 10;
      auVar28 = pshufb(auVar89 ^ auVar73 ^ auVar46,auVar17);
      uVar21 = auVar19._4_4_;
      uVar31 = auVar19._8_4_;
      uVar40 = auVar19._12_4_;
      uVar27 = auVar24._0_4_;
      uVar41 = auVar30._4_4_;
      uVar61 = auVar30._8_4_;
      uVar33 = auVar30._12_4_;
      uVar16 = auVar19._0_4_ + auVar28._0_4_ +
               uVar41 + (uVar21 >> 7 ^ uVar21 << 0x19 ^ uVar21 >> 0x12 ^ uVar21 << 0xe ^ uVar21 >> 3
                        );
      uVar21 = uVar21 + auVar28._4_4_ +
               uVar61 + (uVar31 >> 7 ^ uVar31 << 0x19 ^ uVar31 >> 0x12 ^ uVar31 << 0xe ^ uVar31 >> 3
                        );
      auVar47._0_8_ = CONCAT44(uVar16,uVar16);
      auVar47._8_4_ = uVar21;
      auVar47._12_4_ = uVar21;
      auVar65._0_8_ = auVar47._0_8_ >> 0x11;
      auVar65._8_8_ = auVar47._8_8_ >> 0x11;
      auVar74._0_8_ = auVar47._0_8_ >> 0x13;
      auVar74._8_8_ = auVar47._8_8_ >> 0x13;
      auVar48._0_4_ = uVar16 >> 10;
      auVar48._4_4_ = uVar16 >> 10;
      auVar48._8_4_ = uVar21 >> 10;
      auVar48._12_4_ = uVar21 >> 10;
      auVar22 = pshufb(auVar65 ^ auVar74 ^ auVar48,auVar23);
      auVar19._0_4_ = uVar16 + auVar22._0_4_;
      auVar19._4_4_ = uVar21 + auVar22._4_4_;
      auVar19._8_4_ =
           uVar31 + auVar28._8_4_ +
           uVar33 + (uVar40 >> 7 ^ uVar40 << 0x19 ^ uVar40 >> 0x12 ^ uVar40 << 0xe ^ uVar40 >> 3) +
           auVar22._8_4_;
      auVar19._12_4_ =
           uVar40 + auVar28._12_4_ +
           uVar26 + (uVar27 >> 7 ^ uVar27 << 0x19 ^ uVar27 >> 0x12 ^ uVar27 << 0xe ^ uVar27 >> 3) +
           auVar22._12_4_;
      local_4f8._4_4_ = piVar14[0x11] + auVar19._4_4_;
      local_4f8._0_4_ = *piVar15 + auVar19._0_4_;
      uStack_4f0._0_4_ = piVar14[0x12] + auVar19._8_4_;
      uStack_4f0._4_4_ = piVar14[0x13] + auVar19._12_4_;
      iVar5 = uVar9 + (int)local_4e8 + (uVar2 & uVar1 ^ ~uVar1 & uVar3) +
              ((uVar1 >> 6 | uVar1 * 0x4000000) ^ (uVar1 >> 0xb | uVar1 * 0x200000) ^
              (uVar1 >> 0x19 | uVar1 * 0x80));
      uVar6 = uVar6 + iVar5;
      uVar9 = iVar5 + (uVar11 & uVar12 | (uVar11 | uVar12) & uVar10) +
              ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
              (uVar10 >> 0x16 | uVar10 * 0x400));
      iVar5 = uVar3 + local_4e8._4_4_ + (uVar1 & uVar6 ^ ~uVar6 & uVar2) +
              ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
              (uVar6 >> 0x19 | uVar6 * 0x80));
      uVar12 = uVar12 + iVar5;
      uVar3 = iVar5 + (uVar10 & uVar11 | (uVar10 | uVar11) & uVar9) +
              ((uVar9 >> 2 | uVar9 * 0x40000000) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
              (uVar9 >> 0x16 | uVar9 * 0x400));
      iVar5 = uVar2 + (int)uStack_4e0 + (uVar6 & uVar12 ^ ~uVar12 & uVar1) +
              ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^
              (uVar12 >> 0x19 | uVar12 * 0x80));
      uVar11 = uVar11 + iVar5;
      uVar2 = iVar5 + (uVar9 & uVar10 | (uVar9 | uVar10) & uVar3) +
              ((uVar3 >> 2 | uVar3 * 0x40000000) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
              (uVar3 >> 0x16 | uVar3 * 0x400));
      iVar5 = uVar1 + uStack_4e0._4_4_ + (uVar12 & uVar11 ^ ~uVar11 & uVar6) +
              ((uVar11 >> 6 | uVar11 * 0x4000000) ^ (uVar11 >> 0xb | uVar11 * 0x200000) ^
              (uVar11 >> 0x19 | uVar11 * 0x80));
      uVar10 = uVar10 + iVar5;
      uVar1 = iVar5 + (uVar3 & uVar9 | (uVar3 | uVar9) & uVar2) +
              ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^
              (uVar2 >> 0x16 | uVar2 * 0x400));
      auVar49._0_8_ = CONCAT44(auVar19._8_4_,auVar19._8_4_);
      auVar49._8_4_ = auVar19._12_4_;
      auVar49._12_4_ = auVar19._12_4_;
      auVar90._0_8_ = auVar49._0_8_ >> 0x11;
      auVar90._8_8_ = auVar49._8_8_ >> 0x11;
      auVar75._0_8_ = auVar49._0_8_ >> 0x13;
      auVar75._8_8_ = auVar49._8_8_ >> 0x13;
      auVar50._0_4_ = auVar19._8_4_ >> 10;
      auVar50._4_4_ = auVar19._8_4_ >> 10;
      auVar50._8_4_ = auVar19._12_4_ >> 10;
      auVar50._12_4_ = auVar19._12_4_ >> 10;
      auVar28 = pshufb(auVar90 ^ auVar75 ^ auVar50,auVar17);
      uVar21 = auVar24._4_4_;
      uVar31 = auVar24._8_4_;
      uVar40 = auVar24._12_4_;
      uVar32 = auVar30._0_4_;
      uVar16 = uVar27 + auVar28._0_4_ +
               uVar35 + (uVar21 >> 7 ^ uVar21 << 0x19 ^ uVar21 >> 0x12 ^ uVar21 << 0xe ^ uVar21 >> 3
                        );
      uVar21 = uVar21 + auVar28._4_4_ +
               uVar20 + (uVar31 >> 7 ^ uVar31 << 0x19 ^ uVar31 >> 0x12 ^ uVar31 << 0xe ^ uVar31 >> 3
                        );
      auVar51._0_8_ = CONCAT44(uVar16,uVar16);
      auVar51._8_4_ = uVar21;
      auVar51._12_4_ = uVar21;
      auVar66._0_8_ = auVar51._0_8_ >> 0x11;
      auVar66._8_8_ = auVar51._8_8_ >> 0x11;
      auVar76._0_8_ = auVar51._0_8_ >> 0x13;
      auVar76._8_8_ = auVar51._8_8_ >> 0x13;
      auVar52._0_4_ = uVar16 >> 10;
      auVar52._4_4_ = uVar16 >> 10;
      auVar52._8_4_ = uVar21 >> 10;
      auVar52._12_4_ = uVar21 >> 10;
      auVar22 = pshufb(auVar66 ^ auVar76 ^ auVar52,auVar23);
      auVar24._0_4_ = uVar16 + auVar22._0_4_;
      auVar24._4_4_ = uVar21 + auVar22._4_4_;
      auVar24._8_4_ =
           uVar31 + auVar28._8_4_ +
           uVar25 + (uVar40 >> 7 ^ uVar40 << 0x19 ^ uVar40 >> 0x12 ^ uVar40 << 0xe ^ uVar40 >> 3) +
           auVar22._8_4_;
      auVar24._12_4_ =
           uVar40 + auVar28._12_4_ +
           auVar19._0_4_ +
           (uVar32 >> 7 ^ uVar32 << 0x19 ^ uVar32 >> 0x12 ^ uVar32 << 0xe ^ uVar32 >> 3) +
           auVar22._12_4_;
      local_4e8._4_4_ = piVar14[0x15] + auVar24._4_4_;
      local_4e8._0_4_ = piVar14[0x14] + auVar24._0_4_;
      uStack_4e0._0_4_ = piVar14[0x16] + auVar24._8_4_;
      uStack_4e0._4_4_ = piVar14[0x17] + auVar24._12_4_;
      iVar5 = uVar6 + local_4d8 + (uVar11 & uVar10 ^ ~uVar10 & uVar12) +
              ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^
              (uVar10 >> 0x19 | uVar10 * 0x80));
      uVar9 = uVar9 + iVar5;
      uVar6 = iVar5 + (uVar2 & uVar3 | (uVar2 | uVar3) & uVar1) +
              ((uVar1 >> 2 | uVar1 * 0x40000000) ^ (uVar1 >> 0xd | uVar1 * 0x80000) ^
              (uVar1 >> 0x16 | uVar1 * 0x400));
      iVar5 = uVar12 + iStack_4d4 + (uVar10 & uVar9 ^ ~uVar9 & uVar11) +
              ((uVar9 >> 6 | uVar9 * 0x4000000) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
              (uVar9 >> 0x19 | uVar9 * 0x80));
      uVar3 = uVar3 + iVar5;
      uVar12 = iVar5 + (uVar1 & uVar2 | (uVar1 | uVar2) & uVar6) +
               ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
               (uVar6 >> 0x16 | uVar6 * 0x400));
      iVar5 = uVar11 + iStack_4d0 + (uVar9 & uVar3 ^ ~uVar3 & uVar10) +
              ((uVar3 >> 6 | uVar3 * 0x4000000) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
              (uVar3 >> 0x19 | uVar3 * 0x80));
      uVar2 = uVar2 + iVar5;
      uVar11 = iVar5 + (uVar6 & uVar1 | (uVar6 | uVar1) & uVar12) +
               ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
               (uVar12 >> 0x16 | uVar12 * 0x400));
      iVar5 = uVar10 + iStack_4cc + (uVar3 & uVar2 ^ ~uVar2 & uVar9) +
              ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^
              (uVar2 >> 0x19 | uVar2 * 0x80));
      uVar1 = uVar1 + iVar5;
      uVar10 = iVar5 + (uVar12 & uVar6 | (uVar12 | uVar6) & uVar11) +
               ((uVar11 >> 2 | uVar11 * 0x40000000) ^ (uVar11 >> 0xd | uVar11 * 0x80000) ^
               (uVar11 >> 0x16 | uVar11 * 0x400));
      auVar53._0_8_ = CONCAT44(auVar24._8_4_,auVar24._8_4_);
      auVar53._8_4_ = auVar24._12_4_;
      auVar53._12_4_ = auVar24._12_4_;
      auVar91._0_8_ = auVar53._0_8_ >> 0x11;
      auVar91._8_8_ = auVar53._8_8_ >> 0x11;
      auVar77._0_8_ = auVar53._0_8_ >> 0x13;
      auVar77._8_8_ = auVar53._8_8_ >> 0x13;
      auVar54._0_4_ = auVar24._8_4_ >> 10;
      auVar54._4_4_ = auVar24._8_4_ >> 10;
      auVar54._8_4_ = auVar24._12_4_ >> 10;
      auVar54._12_4_ = auVar24._12_4_ >> 10;
      auVar28 = pshufb(auVar91 ^ auVar77 ^ auVar54,auVar17);
      uVar16 = uVar32 + auVar28._0_4_ +
               auVar19._4_4_ +
               (uVar41 >> 7 ^ uVar41 << 0x19 ^ uVar41 >> 0x12 ^ uVar41 << 0xe ^ uVar41 >> 3);
      uVar21 = uVar41 + auVar28._4_4_ +
               auVar19._8_4_ +
               (uVar61 >> 7 ^ uVar61 << 0x19 ^ uVar61 >> 0x12 ^ uVar61 << 0xe ^ uVar61 >> 3);
      auVar55._0_8_ = CONCAT44(uVar16,uVar16);
      auVar55._8_4_ = uVar21;
      auVar55._12_4_ = uVar21;
      auVar67._0_8_ = auVar55._0_8_ >> 0x11;
      auVar67._8_8_ = auVar55._8_8_ >> 0x11;
      auVar78._0_8_ = auVar55._0_8_ >> 0x13;
      auVar78._8_8_ = auVar55._8_8_ >> 0x13;
      auVar56._0_4_ = uVar16 >> 10;
      auVar56._4_4_ = uVar16 >> 10;
      auVar56._8_4_ = uVar21 >> 10;
      auVar56._12_4_ = uVar21 >> 10;
      auVar22 = pshufb(auVar67 ^ auVar78 ^ auVar56,auVar23);
      auVar30._0_4_ = uVar16 + auVar22._0_4_;
      auVar30._4_4_ = uVar21 + auVar22._4_4_;
      auVar30._8_4_ =
           uVar61 + auVar28._8_4_ +
           auVar19._12_4_ +
           (uVar33 >> 7 ^ uVar33 << 0x19 ^ uVar33 >> 0x12 ^ uVar33 << 0xe ^ uVar33 >> 3) +
           auVar22._8_4_;
      auVar30._12_4_ =
           uVar33 + auVar28._12_4_ +
           auVar24._0_4_ +
           (uVar26 >> 7 ^ uVar26 << 0x19 ^ uVar26 >> 0x12 ^ uVar26 << 0xe ^ uVar26 >> 3) +
           auVar22._12_4_;
      iStack_4d4 = piVar14[0x19] + auVar30._4_4_;
      local_4d8 = piVar14[0x18] + auVar30._0_4_;
      iStack_4d0 = piVar14[0x1a] + auVar30._8_4_;
      iStack_4cc = piVar14[0x1b] + auVar30._12_4_;
      iVar5 = uVar9 + local_4c8 + (uVar2 & uVar1 ^ ~uVar1 & uVar3) +
              ((uVar1 >> 6 | uVar1 * 0x4000000) ^ (uVar1 >> 0xb | uVar1 * 0x200000) ^
              (uVar1 >> 0x19 | uVar1 * 0x80));
      uVar6 = uVar6 + iVar5;
      uVar9 = iVar5 + (uVar11 & uVar12 | (uVar11 | uVar12) & uVar10) +
              ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
              (uVar10 >> 0x16 | uVar10 * 0x400));
      iVar5 = uVar3 + iStack_4c4 + (uVar1 & uVar6 ^ ~uVar6 & uVar2) +
              ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
              (uVar6 >> 0x19 | uVar6 * 0x80));
      uVar12 = uVar12 + iVar5;
      uVar3 = iVar5 + (uVar10 & uVar11 | (uVar10 | uVar11) & uVar9) +
              ((uVar9 >> 2 | uVar9 * 0x40000000) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
              (uVar9 >> 0x16 | uVar9 * 0x400));
      iVar5 = uVar2 + iStack_4c0 + (uVar6 & uVar12 ^ ~uVar12 & uVar1) +
              ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^
              (uVar12 >> 0x19 | uVar12 * 0x80));
      uVar11 = uVar11 + iVar5;
      uVar2 = iVar5 + (uVar9 & uVar10 | (uVar9 | uVar10) & uVar3) +
              ((uVar3 >> 2 | uVar3 * 0x40000000) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
              (uVar3 >> 0x16 | uVar3 * 0x400));
      iVar5 = uVar1 + iStack_4bc + (uVar12 & uVar11 ^ ~uVar11 & uVar6) +
              ((uVar11 >> 6 | uVar11 * 0x4000000) ^ (uVar11 >> 0xb | uVar11 * 0x200000) ^
              (uVar11 >> 0x19 | uVar11 * 0x80));
      uVar10 = uVar10 + iVar5;
      uVar1 = iVar5 + (uVar3 & uVar9 | (uVar3 | uVar9) & uVar2) +
              ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^
              (uVar2 >> 0x16 | uVar2 * 0x400));
      auVar57._0_8_ = CONCAT44(auVar30._8_4_,auVar30._8_4_);
      auVar57._8_4_ = auVar30._12_4_;
      auVar57._12_4_ = auVar30._12_4_;
      auVar92._0_8_ = auVar57._0_8_ >> 0x11;
      auVar92._8_8_ = auVar57._8_8_ >> 0x11;
      auVar79._0_8_ = auVar57._0_8_ >> 0x13;
      auVar79._8_8_ = auVar57._8_8_ >> 0x13;
      auVar58._0_4_ = auVar30._8_4_ >> 10;
      auVar58._4_4_ = auVar30._8_4_ >> 10;
      auVar58._8_4_ = auVar30._12_4_ >> 10;
      auVar58._12_4_ = auVar30._12_4_ >> 10;
      auVar28 = pshufb(auVar92 ^ auVar79 ^ auVar58,auVar17);
      uVar16 = uVar26 + auVar28._0_4_ +
               auVar24._4_4_ +
               (uVar35 >> 7 ^ uVar35 << 0x19 ^ uVar35 >> 0x12 ^ uVar35 << 0xe ^ uVar35 >> 3);
      uVar21 = uVar35 + auVar28._4_4_ +
               auVar24._8_4_ +
               (uVar20 >> 7 ^ uVar20 << 0x19 ^ uVar20 >> 0x12 ^ uVar20 << 0xe ^ uVar20 >> 3);
      auVar59._0_8_ = CONCAT44(uVar16,uVar16);
      auVar59._8_4_ = uVar21;
      auVar59._12_4_ = uVar21;
      auVar68._0_8_ = auVar59._0_8_ >> 0x11;
      auVar68._8_8_ = auVar59._8_8_ >> 0x11;
      auVar80._0_8_ = auVar59._0_8_ >> 0x13;
      auVar80._8_8_ = auVar59._8_8_ >> 0x13;
      auVar60._0_4_ = uVar16 >> 10;
      auVar60._4_4_ = uVar16 >> 10;
      auVar60._8_4_ = uVar21 >> 10;
      auVar60._12_4_ = uVar21 >> 10;
      auVar22 = pshufb(auVar68 ^ auVar80 ^ auVar60,auVar23);
      auVar39._0_4_ = uVar16 + auVar22._0_4_;
      auVar39._4_4_ = uVar21 + auVar22._4_4_;
      auVar39._8_4_ =
           uVar20 + auVar28._8_4_ +
           auVar24._12_4_ +
           (uVar25 >> 7 ^ uVar25 << 0x19 ^ uVar25 >> 0x12 ^ uVar25 << 0xe ^ uVar25 >> 3) +
           auVar22._8_4_;
      auVar39._12_4_ =
           uVar25 + auVar28._12_4_ +
           auVar30._0_4_ +
           (auVar19._0_4_ >> 7 ^ auVar19._0_4_ * 0x2000000 ^
            auVar19._0_4_ >> 0x12 ^ auVar19._0_4_ * 0x4000 ^ auVar19._0_4_ >> 3) + auVar22._12_4_;
      iStack_4c4 = piVar14[0x1d] + auVar39._4_4_;
      local_4c8 = piVar14[0x1c] + auVar39._0_4_;
      iStack_4c0 = piVar14[0x1e] + auVar39._8_4_;
      iStack_4bc = piVar14[0x1f] + auVar39._12_4_;
      piVar14 = piVar15;
    } while (piVar15 < &DAT_1800159c0);
    piVar14 = (int *)&local_4f8;
    do {
      iVar5 = uVar6 + *piVar14 + (uVar11 & uVar10 ^ ~uVar10 & uVar12) +
              ((uVar10 >> 6 | uVar10 << 0x1a) ^ (uVar10 >> 0xb | uVar10 << 0x15) ^
              (uVar10 >> 0x19 | uVar10 << 7));
      uVar9 = uVar9 + iVar5;
      uVar6 = iVar5 + (uVar2 & uVar3 | (uVar2 | uVar3) & uVar1) +
              ((uVar1 >> 2 | uVar1 << 0x1e) ^ (uVar1 >> 0xd | uVar1 << 0x13) ^
              (uVar1 >> 0x16 | uVar1 << 10));
      iVar5 = uVar12 + piVar14[1] + (uVar10 & uVar9 ^ ~uVar9 & uVar11) +
              ((uVar9 >> 6 | uVar9 * 0x4000000) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
              (uVar9 >> 0x19 | uVar9 * 0x80));
      uVar3 = uVar3 + iVar5;
      uVar12 = iVar5 + (uVar1 & uVar2 | (uVar1 | uVar2) & uVar6) +
               ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
               (uVar6 >> 0x16 | uVar6 * 0x400));
      iVar5 = uVar11 + piVar14[2] + (uVar9 & uVar3 ^ ~uVar3 & uVar10) +
              ((uVar3 >> 6 | uVar3 * 0x4000000) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
              (uVar3 >> 0x19 | uVar3 * 0x80));
      uVar2 = uVar2 + iVar5;
      uVar11 = iVar5 + (uVar6 & uVar1 | (uVar6 | uVar1) & uVar12) +
               ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
               (uVar12 >> 0x16 | uVar12 * 0x400));
      iVar5 = uVar10 + piVar14[3] + (uVar3 & uVar2 ^ ~uVar2 & uVar9) +
              ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^
              (uVar2 >> 0x19 | uVar2 * 0x80));
      uVar1 = uVar1 + iVar5;
      uVar10 = iVar5 + (uVar12 & uVar6 | (uVar12 | uVar6) & uVar11) +
               ((uVar11 >> 2 | uVar11 * 0x40000000) ^ (uVar11 >> 0xd | uVar11 * 0x80000) ^
               (uVar11 >> 0x16 | uVar11 * 0x400));
      iVar5 = uVar9 + piVar14[4] + (uVar2 & uVar1 ^ ~uVar1 & uVar3) +
              ((uVar1 >> 6 | uVar1 * 0x4000000) ^ (uVar1 >> 0xb | uVar1 * 0x200000) ^
              (uVar1 >> 0x19 | uVar1 * 0x80));
      uVar6 = uVar6 + iVar5;
      uVar9 = iVar5 + (uVar11 & uVar12 | (uVar11 | uVar12) & uVar10) +
              ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
              (uVar10 >> 0x16 | uVar10 * 0x400));
      iVar5 = uVar3 + piVar14[5] + (uVar1 & uVar6 ^ ~uVar6 & uVar2) +
              ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
              (uVar6 >> 0x19 | uVar6 * 0x80));
      uVar12 = uVar12 + iVar5;
      uVar3 = iVar5 + (uVar10 & uVar11 | (uVar10 | uVar11) & uVar9) +
              ((uVar9 >> 2 | uVar9 * 0x40000000) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
              (uVar9 >> 0x16 | uVar9 * 0x400));
      iVar5 = uVar2 + piVar14[6] + (uVar6 & uVar12 ^ ~uVar12 & uVar1) +
              ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^
              (uVar12 >> 0x19 | uVar12 * 0x80));
      uVar11 = uVar11 + iVar5;
      uVar2 = iVar5 + (uVar9 & uVar10 | (uVar9 | uVar10) & uVar3) +
              ((uVar3 >> 2 | uVar3 * 0x40000000) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
              (uVar3 >> 0x16 | uVar3 * 0x400));
      iVar5 = uVar1 + piVar14[7] + (uVar12 & uVar11 ^ ~uVar11 & uVar6) +
              ((uVar11 >> 6 | uVar11 * 0x4000000) ^ (uVar11 >> 0xb | uVar11 * 0x200000) ^
              (uVar11 >> 0x19 | uVar11 * 0x80));
      uVar10 = uVar10 + iVar5;
      uVar1 = iVar5 + (uVar3 & uVar9 | (uVar3 | uVar9) & uVar2) +
              ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^
              (uVar2 >> 0x16 | uVar2 * 0x400));
      piVar14 = piVar14 + 8;
    } while (piVar14 < &local_4b8);
    uVar1 = uVar1 + *param_1;
    *param_1 = uVar1;
    uVar2 = uVar2 + param_1[1];
    param_1[1] = uVar2;
    uVar3 = uVar3 + param_1[2];
    param_1[2] = uVar3;
    uVar9 = uVar9 + param_1[3];
    param_1[3] = uVar9;
    uVar10 = uVar10 + param_1[4];
    param_1[4] = uVar10;
    uVar11 = uVar11 + param_1[5];
    param_1[5] = uVar11;
    uVar12 = uVar12 + param_1[6];
    param_1[6] = uVar12;
    uVar6 = uVar6 + param_1[7];
    param_1[7] = uVar6;
    param_2 = param_2 + 4;
  }
  *param_4 = param_3;
  uVar4 = (ulonglong)(local_f0 - 0x40U);
  puVar8 = &local_4b8;
  if (local_f0 - 0x40U != 0) {
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar8 = 0;
      puVar8 = (undefined8 *)((longlong)puVar8 + 1);
    }
  }
  return;
}



===== SymCryptWipeAsm @ 18000c630 =====

void SymCryptWipeAsm(undefined8 *param_1,ulonglong param_2)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  if (param_2 < 0x10) {
    uVar2 = (uint)param_2;
    if (7 < uVar2) {
      *param_1 = 0;
      *(undefined8 *)((longlong)param_1 + (param_2 - 8)) = 0;
      return;
    }
    if (3 < uVar2) {
      *(undefined4 *)param_1 = 0;
      *(undefined4 *)((longlong)param_1 + (param_2 - 4)) = 0;
      return;
    }
    if (1 < uVar2) {
      *(undefined2 *)param_1 = 0;
      *(undefined2 *)((longlong)param_1 + (param_2 - 2)) = 0;
      return;
    }
    if (uVar2 != 0) {
      *(undefined1 *)param_1 = 0;
    }
    return;
  }
  if (((ulonglong)param_1 & 0xf) != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    uVar1 = (ulonglong)(-(int)param_1 & 0xf);
    param_1 = (undefined8 *)((longlong)param_1 + uVar1);
    param_2 = param_2 - uVar1;
    if (param_2 < 0x10) {
      *(undefined8 *)((longlong)param_1 + (param_2 - 0x10)) = 0;
      *(undefined8 *)((longlong)param_1 + (param_2 - 8)) = 0;
      return;
    }
  }
  *param_1 = 0;
  param_1[1] = 0;
  if ((param_2 & 0x10) != 0) {
    param_1 = param_1 + 2;
  }
  while (uVar1 = param_2 - 0x20, 0x1f < param_2) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1 = param_1 + 4;
    param_2 = uVar1;
  }
  uVar3 = (ulonglong)((uint)uVar1 & 0xf);
  if ((uVar1 & 0xf) == 0) {
    return;
  }
  *(undefined8 *)((longlong)param_1 + (uVar3 - 0x10)) = 0;
  *(undefined8 *)((longlong)param_1 + (uVar3 - 8)) = 0;
  return;
}



===== SymCryptAesEncryptAsmInternal @ 18000c770 =====

longlong SymCryptAesEncryptAsmInternal(uint param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint in_EAX;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint unaff_EBX;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint *in_R10;
  longlong in_R11;
  bool bVar12;
  
  uVar5 = in_EAX ^ *param_4;
  uVar9 = unaff_EBX ^ param_4[1];
  uVar7 = param_1 ^ param_4[2];
  uVar8 = param_2 ^ param_4[3];
  puVar11 = param_4 + 8;
  do {
    uVar1 = uVar5 >> 8;
    uVar6 = uVar5 >> 0x10;
    uVar2 = uVar5 >> 0x18;
    uVar10 = uVar9 >> 0x10;
    uVar3 = uVar9 >> 0x18;
    uVar4 = uVar7 >> 0x18;
    uVar5 = puVar11[-4] ^
            *(uint *)(in_R11 + (ulonglong)(uVar5 & 0xff) * 4) ^
            *(uint *)(in_R11 + 0x400 + (ulonglong)(uVar9 >> 8 & 0xff) * 4) ^
            *(uint *)(in_R11 + 0x800 + (ulonglong)(uVar7 >> 0x10 & 0xff) * 4) ^
            *(uint *)(in_R11 + 0xc00 + (ulonglong)(uVar8 >> 0x18) * 4);
    uVar9 = puVar11[-3] ^
            *(uint *)(in_R11 + 0xc00 + (ulonglong)uVar2 * 4) ^
            *(uint *)(in_R11 + (ulonglong)(uVar9 & 0xff) * 4) ^
            *(uint *)(in_R11 + 0x400 + (ulonglong)(uVar7 >> 8 & 0xff) * 4) ^
            *(uint *)(in_R11 + 0x800 + (ulonglong)(uVar8 >> 0x10 & 0xff) * 4);
    uVar7 = puVar11[-2] ^
            *(uint *)(in_R11 + 0x800 + (ulonglong)(uVar6 & 0xff) * 4) ^
            *(uint *)(in_R11 + 0xc00 + (ulonglong)uVar3 * 4) ^
            *(uint *)(in_R11 + (ulonglong)(uVar7 & 0xff) * 4) ^
            *(uint *)(in_R11 + 0x400 + (ulonglong)(uVar8 >> 8 & 0xff) * 4);
    uVar8 = puVar11[-1] ^
            *(uint *)(in_R11 + 0x400 + (ulonglong)(uVar1 & 0xff) * 4) ^
            *(uint *)(in_R11 + 0x800 + (ulonglong)(uVar10 & 0xff) * 4) ^
            *(uint *)(in_R11 + 0xc00 + (ulonglong)uVar4 * 4) ^
            *(uint *)(in_R11 + (ulonglong)(uVar8 & 0xff) * 4);
    bVar12 = puVar11 < in_R10;
    puVar11 = puVar11 + 4;
  } while (bVar12);
  return (ulonglong)*(byte *)(in_R11 + 1 + (ulonglong)(uVar8 >> 0x10 & 0xff) * 4) << 0x10;
}



===== SymCryptAesDecryptAsmInternal @ 18000c950 =====

longlong SymCryptAesDecryptAsmInternal(uint param_1,uint param_2,undefined8 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint in_EAX;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint unaff_EBX;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint *in_R10;
  longlong in_R11;
  longlong unaff_R12;
  bool bVar12;
  
  uVar5 = in_EAX ^ *param_4;
  uVar9 = unaff_EBX ^ param_4[1];
  uVar7 = param_1 ^ param_4[2];
  uVar8 = param_2 ^ param_4[3];
  puVar11 = param_4 + 8;
  do {
    uVar1 = uVar5 >> 8;
    uVar6 = uVar5 >> 0x10;
    uVar2 = uVar5 >> 0x18;
    uVar3 = uVar9 >> 8;
    uVar10 = uVar9 >> 0x10;
    uVar4 = uVar7 >> 8;
    uVar5 = puVar11[-4] ^
            *(uint *)(in_R11 + (ulonglong)(uVar5 & 0xff) * 4) ^
            *(uint *)(in_R11 + 0xc00 + (ulonglong)(uVar9 >> 0x18) * 4) ^
            *(uint *)(in_R11 + 0x800 + (ulonglong)(uVar7 >> 0x10 & 0xff) * 4) ^
            *(uint *)(in_R11 + 0x400 + (ulonglong)(uVar8 >> 8 & 0xff) * 4);
    uVar9 = puVar11[-3] ^
            *(uint *)(in_R11 + 0x400 + (ulonglong)(uVar1 & 0xff) * 4) ^
            *(uint *)(in_R11 + (ulonglong)(uVar9 & 0xff) * 4) ^
            *(uint *)(in_R11 + 0xc00 + (ulonglong)(uVar7 >> 0x18) * 4) ^
            *(uint *)(in_R11 + 0x800 + (ulonglong)(uVar8 >> 0x10 & 0xff) * 4);
    uVar7 = puVar11[-2] ^
            *(uint *)(in_R11 + 0x800 + (ulonglong)(uVar6 & 0xff) * 4) ^
            *(uint *)(in_R11 + 0x400 + (ulonglong)(uVar3 & 0xff) * 4) ^
            *(uint *)(in_R11 + (ulonglong)(uVar7 & 0xff) * 4) ^
            *(uint *)(in_R11 + 0xc00 + (ulonglong)(uVar8 >> 0x18) * 4);
    uVar8 = puVar11[-1] ^
            *(uint *)(in_R11 + 0xc00 + (ulonglong)uVar2 * 4) ^
            *(uint *)(in_R11 + 0x800 + (ulonglong)(uVar10 & 0xff) * 4) ^
            *(uint *)(in_R11 + 0x400 + (ulonglong)(uVar4 & 0xff) * 4) ^
            *(uint *)(in_R11 + (ulonglong)(uVar8 & 0xff) * 4);
    bVar12 = puVar11 < in_R10;
    puVar11 = puVar11 + 4;
  } while (bVar12);
  return (ulonglong)*(byte *)(unaff_R12 + (ulonglong)(uVar8 >> 0x10 & 0xff)) << 0x10;
}



===== SymCryptAesEncryptAsm @ 18000cb20 =====

void SymCryptAesEncryptAsm(uint *param_1,longlong param_2,undefined4 *param_3)

{
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 uVar1;
  
  uVar1 = SUB84(param_3,0);
  SymCryptAesEncryptAsmInternal(*(uint *)(param_2 + 8),*(uint *)(param_2 + 0xc),param_3,param_1);
  *param_3 = unaff_ESI;
  param_3[1] = unaff_EDI;
  param_3[2] = unaff_EBP;
  param_3[3] = uVar1;
  return;
}



===== SymCryptAesDecryptAsm @ 18000cb80 =====

void SymCryptAesDecryptAsm(longlong param_1,longlong param_2,undefined4 *param_3)

{
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 uVar1;
  
  uVar1 = SUB84(param_3,0);
  SymCryptAesDecryptAsmInternal
            (*(uint *)(param_2 + 8),*(uint *)(param_2 + 0xc),param_3,*(uint **)(param_1 + 0x1d0));
  *param_3 = unaff_ESI;
  param_3[1] = unaff_EDI;
  param_3[2] = unaff_EBP;
  param_3[3] = uVar1;
  return;
}



===== SymCryptAesCbcEncryptAsm @ 18000cbf0 =====

void SymCryptAesCbcEncryptAsm
               (uint *param_1,undefined4 *param_2,ulonglong param_3,undefined4 *param_4,
               ulonglong param_5)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  if ((param_5 & 0xfffffffffffffff0) != 0) {
    uVar7 = (param_5 & 0xfffffffffffffff0) + param_3;
    uVar3 = *param_2;
    uVar4 = param_2[1];
    uVar5 = param_2[2];
    uVar6 = (ulonglong)(uint)param_2[3];
    do {
      puVar1 = (uint *)(param_3 + 8);
      puVar2 = (uint *)(param_3 + 0xc);
      param_3 = param_3 + 0x10;
      SymCryptAesEncryptAsmInternal(*puVar1 ^ uVar5,*puVar2 ^ (uint)uVar6,uVar6,param_1);
      *param_4 = uVar3;
      param_4[1] = uVar4;
      param_4[2] = uVar5;
      param_4[3] = (int)uVar6;
      param_4 = param_4 + 4;
    } while (param_3 < uVar7);
    *param_2 = uVar3;
    param_2[1] = uVar4;
    param_2[2] = uVar5;
    param_2[3] = (int)uVar6;
  }
  return;
}



===== SymCryptAesCbcDecryptAsm @ 18000ccc0 =====

void SymCryptAesCbcDecryptAsm
               (longlong param_1,uint *param_2,undefined8 *param_3,longlong param_4,
               ulonglong param_5)

{
  longlong lVar1;
  uint *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  uint unaff_EBP;
  uint unaff_ESI;
  uint unaff_EDI;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  uint *puVar10;
  
  if ((param_5 & 0xfffffffffffffff0) != 0) {
    lVar1 = (param_5 & 0xfffffffffffffff0) - 0x10;
    puVar10 = (uint *)(param_4 + lVar1);
    puVar9 = (undefined8 *)(lVar1 + (longlong)param_3);
    puVar2 = *(uint **)(param_1 + 0x1d0);
    uVar3 = *puVar9;
    uVar5 = *(uint *)(puVar9 + 1);
    uVar6 = *(uint *)((longlong)puVar9 + 0xc);
    uVar4 = puVar9[1];
    puVar8 = param_3;
    while( true ) {
      SymCryptAesDecryptAsmInternal(uVar5,uVar6,puVar8,puVar2);
      if (puVar9 <= param_3) break;
      unaff_ESI = unaff_ESI ^ *(uint *)(puVar9 + -2);
      uVar5 = *(uint *)(puVar9 + -1);
      unaff_EDI = unaff_EDI ^ *(uint *)((longlong)puVar9 + -0xc);
      *puVar10 = unaff_ESI;
      uVar6 = *(uint *)((longlong)puVar9 + -4);
      unaff_EBP = unaff_EBP ^ uVar5;
      puVar10[1] = unaff_EDI;
      uVar7 = (uint)puVar8 ^ uVar6;
      puVar8 = (undefined8 *)(ulonglong)uVar7;
      puVar10[2] = unaff_EBP;
      puVar10[3] = uVar7;
      puVar9 = puVar9 + -2;
      puVar10 = puVar10 + -4;
    }
    uVar5 = param_2[1];
    uVar6 = param_2[2];
    uVar7 = param_2[3];
    *puVar10 = unaff_ESI ^ *param_2;
    puVar10[1] = unaff_EDI ^ uVar5;
    puVar10[2] = unaff_EBP ^ uVar6;
    puVar10[3] = (uint)puVar8 ^ uVar7;
    *(undefined8 *)param_2 = uVar3;
    *(undefined8 *)(param_2 + 2) = uVar4;
  }
  return;
}



===== ext_ms_win_ntos_ksr_l1_1_1_KsrClaimPersistedMemory @ 18000cde0 =====

undefined8 ext_ms_win_ntos_ksr_l1_1_1_KsrClaimPersistedMemory(void)

{
  return 0xc00000bb;
}



===== DoubleBufferMdl @ 18000cdf0 =====

void DoubleBufferMdl(longlong param_1,ulonglong param_2)

{
  longlong lVar1;
  uint uVar2;
  void *_Src;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong *plVar5;
  void *_Dst;
  
  _Src = (void *)((*(ulonglong *)(param_1 + 0x18) & 0xfffffffffffff000) +
                 (ulonglong)*(uint *)(param_1 + 0x2c));
  _Dst = (void *)((param_2 & 0xfffffffffffff000) + (ulonglong)*(uint *)(param_1 + 0x2c));
  memmove(_Dst,_Src,(ulonglong)*(uint *)(param_1 + 0x28));
  *(void **)(param_1 + 0x18) = _Dst;
  uVar4 = (ulonglong)_Dst & 0xfffffffffffff000;
  uVar3 = (ulonglong)((uint)_Src & 0xfff) + (ulonglong)*(uint *)(param_1 + 0x28) + 0xfff >> 0xc;
  *(ulonglong *)(param_1 + 0x20) = uVar4;
  plVar5 = (longlong *)(param_1 + 0x30);
  uVar2 = (uint)uVar3;
  for (; (uVar2 != 0 && (uVar4 != 0)); uVar4 = uVar4 + 0x1000) {
    lVar1 = MmGetPhysicalAddress(uVar4);
    *plVar5 = lVar1 >> 0xc;
    plVar5 = plVar5 + 1;
    uVar2 = (int)uVar3 - 1;
    uVar3 = (ulonglong)uVar2;
  }
  return;
}



===== DumpPreReadWrite @ 18000cec0 =====

uint DumpPreReadWrite(int *param_1,int param_2,char param_3,ulonglong *param_4,longlong param_5,
                     longlong param_6)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  undefined1 *puVar7;
  ulonglong *puVar8;
  ulonglong local_res8;
  int local_res10;
  longlong lVar9;
  ulonglong local_48 [2];
  
  lVar1 = *(longlong *)(param_1 + 0x12);
  local_48[0] = 0;
  local_res8 = local_res8 & 0xffffffff00000000;
  if (*(int *)(lVar1 + 0x40) != 0) {
    puVar8 = param_4;
    local_res10 = param_2;
    if ((param_3 != '\0') &&
       (uVar4 = FveIsEDriveUEFICapsule(lVar1,(longlong)param_1), (char)uVar4 != '\0')) {
      puVar7 = *(undefined1 **)(param_5 + 0x18);
      for (uVar6 = (ulonglong)*(uint *)(param_5 + 0x28); uVar6 != 0; uVar6 = uVar6 - 1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      return 0;
    }
    uVar6 = *puVar8;
    uVar5 = *(ulonglong *)(lVar1 + 0xa8);
    uVar2 = FveGetRedirectedBlockOffset(uVar6,uVar5,*(longlong *)(lVar1 + 0xb0),local_48);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    uVar2 = FveGetRedirectedBlockSize
                      (uVar6,(ulonglong)*(uint *)(param_5 + 0x28),uVar5,(undefined4 *)&local_res8);
    uVar6 = local_48[0];
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    uVar2 = (uint)local_res8;
    *param_4 = local_48[0];
    *(uint *)(param_5 + 0x28) = (uint)local_res8;
    if (local_res10 - 1U < 2) {
      if (*(longlong *)(lVar1 + 0xe8) == 0) {
        if (param_3 == '\0') {
          return 0;
        }
        DoubleBufferMdl(param_5,*(ulonglong *)(lVar1 + 0x48));
        lVar9 = 0;
      }
      else {
        if (*(int *)(*(longlong *)(lVar1 + 0xe8) + 0xc) != 1) {
          return 0xc0210057;
        }
        if (*(longlong **)(lVar1 + 0xb8) == (longlong *)0x0) {
          lVar9 = 0;
        }
        else {
          lVar9 = **(longlong **)(lVar1 + 0xb8);
        }
        if (((lVar9 == 0) || (*(byte **)(lVar1 + 0xd8) == (byte *)0x0)) ||
           ((*(int *)(lVar1 + 0x10) == 2 && ((**(byte **)(lVar1 + 0xd8) & 2) == 0)))) {
          if (*(ulonglong *)(lVar1 + 0x50) <= local_48[0]) {
            return 0;
          }
        }
        else {
          uVar5 = (local_res8 & 0xffffffff) + local_48[0];
          local_res8 = uVar5;
          iVar3 = FveLibIdentifyCurrentRegionTypeAndEnd
                            (local_48[0],uVar2,*(ulonglong *)(param_1 + 10),*(uint *)(lVar1 + 4),0,0
                             ,*(ulonglong *)(lVar1 + 0x50),'\x01',0,lVar9,0,(longlong *)0x0,
                             (-(param_3 != '\0') & 0xfeU) + 0xd,&local_res8);
          if (local_res8 < uVar5) {
            *(int *)(param_5 + 0x28) = (int)local_res8 - (int)uVar6;
          }
          if (iVar3 != 3) {
            if (iVar3 == 0) {
              return 0;
            }
            return 0xc0210009;
          }
        }
        *(undefined8 *)(lVar1 + 0x1c0) = *(undefined8 *)(lVar1 + 0xe8);
        uVar5 = uVar6 / *(uint *)(lVar1 + 4);
        *(ulonglong *)(lVar1 + 0x1b8) = uVar5;
        if (uVar5 * *(uint *)(lVar1 + 4) != uVar6) {
          return 0xc0210057;
        }
        uVar6 = Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar6 == 0) || ((*(uint *)(lVar1 + 0xc0) & 0x20) == 0)) {
          *(ulonglong **)(param_6 + 8) = (ulonglong *)(lVar1 + 0x1b8);
          return 0;
        }
        *(undefined8 *)(param_6 + 8) = 0;
        if (param_3 == '\0') {
          return 0;
        }
        DoubleBufferMdl(param_5,*(ulonglong *)(lVar1 + 0x48));
        lVar9 = lVar1 + 0x218;
      }
      FveEncryptWrite(*param_1,lVar1,*(void **)(param_5 + 0x18),*param_4,*(uint *)(param_5 + 0x28),
                      *(undefined8 *)(param_1 + 10),'\x01',lVar9);
    }
  }
  return 0;
}



===== DumpRead @ 18000d170 =====

undefined8 DumpRead(longlong param_1,ulonglong *param_2,longlong param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  lVar1 = *(longlong *)(param_1 + 0x48);
  lVar3 = 0;
  if (*(int *)(lVar1 + 0x40) == 0) {
    return 0;
  }
  uVar2 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
  if ((int)uVar2 != 0) {
    uVar2 = Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar2 == 0) {
      if (*(longlong *)(lVar1 + 0x1c0) != 0) {
        return 0;
      }
    }
    else if ((*(longlong *)(lVar1 + 0x1c0) != 0) && ((*(uint *)(lVar1 + 0xc0) & 0x20) == 0)) {
      return 0;
    }
  }
  uVar2 = Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline();
  if ((((int)uVar2 != 0) && ((*(uint *)(lVar1 + 0xc0) & 0x20) != 0)) &&
     (*(longlong *)(lVar1 + 0x1c0) != 0)) {
    lVar3 = lVar1 + 0x218;
  }
  FveEncryptRead(lVar1,*(void **)(param_3 + 0x18),*param_2,*(uint *)(param_3 + 0x28),lVar3);
  return 0;
}



===== DumpRecoveryPrepareShutdownHandler @ 18000d220 =====

void DumpRecoveryPrepareShutdownHandler(longlong param_1)

{
  ulonglong uVar1;
  
  FveDestroyCryptoKeyData(param_1 + 0x198);
  uVar1 = Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar1 != 0) {
    FveDestroyCryptoKeyData(param_1 + 0x218);
    FveDmpSecureZeroAndFlush((undefined1 *)(param_1 + 0x1c8),0x4d);
    FveDmpSecureZeroAndFlush((undefined1 *)(param_1 + 0x218),0x20);
  }
  FveDmpSecureZeroAndFlush((undefined1 *)(param_1 + 0x58),0x4d);
  FveDmpSecureZeroAndFlush((undefined1 *)(param_1 + 0x148),0x4d);
  FveDmpSecureZeroAndFlush((undefined1 *)(param_1 + 0x198),0x20);
  FveDmpSecureZeroAndFlush((undefined1 *)(param_1 + 0x240),0x3be1);
  *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) | 2;
  return;
}



===== DumpStart @ 18000d2e0 =====

undefined8 DumpStart(int *param_1)

{
  int *piVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  piVar1 = *(int **)(param_1 + 0x12);
  PoSetHiberRange(0,0x10000,piVar1,*piVar1,0x63647646);
  if (piVar1[0x10] != 0) {
    PoSetHiberRange(0,0x10000,*(undefined8 *)(piVar1 + 0x12),piVar1[0x11],0x62647646);
    uVar3 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline();
    if (((int)uVar3 != 0) && (*(longlong *)(piVar1 + 0x3a) != 0)) {
      PoSetHiberRange(0,0x10000,*(longlong *)(piVar1 + 0x3a),0x70,0x6b657646);
      PoSetHiberRange(0,0x10000,*(undefined8 *)(*(longlong *)(piVar1 + 0x3a) + 0x38),
                      *(undefined4 *)(*(longlong *)(piVar1 + 0x3a) + 0x14),0x6b657646);
      if (*(longlong *)(*(longlong *)(piVar1 + 0x3a) + 0x60) != 0) {
        PoSetHiberRange(0,0x10000,*(longlong *)(*(longlong *)(piVar1 + 0x3a) + 0x60),0,0x6b657646);
      }
    }
    if (piVar1[0x10] != 0) {
      FveInitCrypto(piVar1);
      if (*param_1 != 1) {
        return 0;
      }
      if (*(longlong **)(piVar1 + 0x2e) == (longlong *)0x0) {
        return 0;
      }
      lVar2 = **(longlong **)(piVar1 + 0x2e);
      if (lVar2 == 0) {
        return 0;
      }
      *(undefined8 *)(lVar2 + 0x68) = 0;
      *(undefined8 *)(lVar2 + 0x70) = 0;
      return 0;
    }
  }
  FveDmpSecureZeroAndFlush((undefined1 *)(piVar1 + 0x52),0x4d);
  uVar3 = Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar3 != 0) {
    FveDmpSecureZeroAndFlush((undefined1 *)(piVar1 + 0x72),0x4d);
  }
  return 0;
}



===== DumpWrite @ 18000d440 =====

undefined8 DumpWrite(int *param_1,ulonglong *param_2,longlong param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined1 *puVar4;
  
  lVar1 = *(longlong *)(param_1 + 0x12);
  uVar2 = FveIsEDriveUEFICapsule(lVar1,(longlong)param_1);
  if ((char)uVar2 == '\0') {
    Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledDeviceUsageNoInline();
    if (*(int *)(lVar1 + 0x40) != 0) {
      DoubleBufferMdl(param_3,*(ulonglong *)(lVar1 + 0x48));
      Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline();
      FveEncryptWrite(*param_1,lVar1,*(void **)(param_3 + 0x18),*param_2,*(uint *)(param_3 + 0x28),
                      *(undefined8 *)(param_1 + 10),'\0',0);
    }
  }
  else {
    puVar4 = *(undefined1 **)(param_3 + 0x18);
    for (uVar3 = (ulonglong)*(uint *)(param_3 + 0x28); uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
  }
  return 0;
}



===== Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledDeviceUsageNoInline @ 18000d4e8 =====

ulonglong Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_SteelixInlineNvmeCryptoEngine__private_featureState;
  if ((Feature_SteelixInlineNvmeCryptoEngine__private_featureState & 0x10) == 0) {
    uVar1 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_SteelixInlineNvmeCryptoEngine__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledFallback @ 18000d520 =====

void Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_SteelixInlineNvmeCryptoEngine__private_descriptor);
  return;
}



===== Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline @ 18000d53c =====

ulonglong Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledNoReportingNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_SteelixInlineNvmeCryptoEngine__private_featureState;
  if ((Feature_SteelixInlineNvmeCryptoEngine__private_featureState & 2) == 0) {
    uVar1 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledFallback(local_res8,0);
  }
  else {
    uVar1 = (ulonglong)(Feature_SteelixInlineNvmeCryptoEngine__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline @ 18000d574 =====

ulonglong Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline(void)

{
  ulonglong uVar1;
  ulonglong local_res8;
  
  local_res8 = (ulonglong)Feature_SteelixRemoveFvekFromMemory__private_featureState;
  if ((Feature_SteelixRemoveFvekFromMemory__private_featureState & 0x10) == 0) {
    uVar1 = Feature_SteelixRemoveFvekFromMemory__private_IsEnabledFallback(local_res8,3);
  }
  else {
    uVar1 = (ulonglong)(Feature_SteelixRemoveFvekFromMemory__private_featureState & 1);
  }
  return uVar1;
}



===== Feature_SteelixRemoveFvekFromMemory__private_IsEnabledFallback @ 18000d5ac =====

void Feature_SteelixRemoveFvekFromMemory__private_IsEnabledFallback(ulonglong param_1,int param_2)

{
  wil_details_IsEnabledFallback
            (param_1,param_2,&Feature_SteelixRemoveFvekFromMemory__private_descriptor);
  return;
}



===== FveEncryptRead @ 18000d5c8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FveEncryptRead(longlong param_1,void *param_2,ulonglong param_3,uint param_4,longlong param_5)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  undefined1 auStackY_1d8 [32];
  uint local_198;
  uint local_194;
  ulonglong local_190;
  void *local_188;
  ulonglong local_180;
  byte *local_178;
  undefined8 local_170;
  longlong local_168;
  ulonglong local_160;
  ulonglong local_158;
  undefined8 local_150;
  ulonglong local_148;
  longlong local_140;
  longlong local_118;
  longlong local_110;
  code *local_100;
  void *local_f8;
  void *local_f0;
  uint local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_1d8;
  local_194 = param_4;
  local_188 = param_2;
  local_180 = param_3;
  memset(&local_158,0,0x100);
  local_190 = 0;
  local_198 = 0;
  local_160 = *(ulonglong *)(param_1 + 0xa8);
  local_168 = *(longlong *)(param_1 + 0xb0);
  uVar1 = *(ulonglong *)(param_1 + 0x50);
  if (*(longlong **)(param_1 + 0xb8) == (longlong *)0x0) {
    lVar7 = 0;
  }
  else {
    lVar7 = **(longlong **)(param_1 + 0xb8);
  }
  local_178 = *(byte **)(param_1 + 0xd8);
  local_170 = **(undefined8 **)(param_1 + 0xe0);
  while( true ) {
    uVar4 = local_180;
    uVar6 = local_160;
    uVar3 = FveGetRedirectedBlockOffset(local_180,local_160,local_168,&local_190);
    if ((int)uVar3 < 0) {
      return;
    }
    uVar2 = FveGetRedirectedBlockSize(uVar4,(ulonglong)param_4,uVar6,&local_198);
    uVar4 = local_190;
    uVar3 = local_198;
    if ((int)uVar2 < 0) break;
    uVar6 = (ulonglong)local_198;
    if (((lVar7 == 0) || (local_178 == (byte *)0x0)) || ((*local_178 & 2) == 0)) {
      if (local_190 < uVar1) {
        if (uVar1 < local_190 + uVar6) {
          uVar2 = (int)uVar1 - (int)local_190;
        }
        else {
          uVar2 = local_198;
        }
        memset(&local_158,0,0x100);
        uVar5 = Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar5 == 0) || (param_5 == 0)) {
          local_118 = param_1 + 0x198;
        }
        else {
          local_118 = param_5;
        }
        local_e4 = *(undefined4 *)(param_1 + 4);
        FveFilteredRead(3,(longlong)&local_158,uVar4,0xffffffffffffffff,uVar2,local_188,local_188,0)
        ;
        param_4 = local_194;
      }
      param_2 = local_188;
    }
    else {
      memset(&local_150,0,0xf8);
      local_158 = uVar1;
      uVar4 = Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar4 == 0) || (param_5 == 0)) {
        local_118 = param_1 + 0x198;
      }
      else {
        local_118 = param_5;
      }
      local_100 = FveFilteredRead;
      local_148 = local_190;
      local_150 = local_170;
      local_e4 = *(undefined4 *)(param_1 + 4);
      local_e8 = uVar3;
      local_e0 = 0xd;
      local_110 = lVar7;
      local_f8 = param_2;
      local_f0 = param_2;
      if (local_140 == 0) {
        FvepParseBlockAndFilter(&local_158);
      }
      else {
        FvepParseBlockAndFilterLegacy(&local_158);
      }
    }
    if (uVar3 == param_4) {
      return;
    }
    local_180 = local_180 + uVar6;
    param_4 = param_4 - uVar3;
    local_198 = param_4;
    local_194 = param_4;
  }
  return;
}



===== FveEncryptWrite @ 18000d840 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FveEncryptWrite(int param_1,longlong param_2,void *param_3,ulonglong param_4,uint param_5,
                    undefined8 param_6,char param_7,longlong param_8)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  undefined1 auStackY_1d8 [32];
  uint local_198 [2];
  ulonglong local_190;
  int local_188;
  ulonglong local_180;
  void *local_178;
  ulonglong local_170;
  byte *local_168;
  ulonglong local_160;
  longlong local_158;
  ulonglong local_148;
  undefined8 local_140;
  ulonglong local_138;
  longlong local_130;
  longlong local_108;
  longlong local_100;
  code *local_f0;
  void *local_e8;
  void *local_e0;
  uint local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_1d8;
  local_188 = param_1;
  local_178 = param_3;
  local_170 = param_4;
  memset(&local_148,0,0x100);
  uVar1 = 0;
  local_180 = 0;
  local_198[0] = 0;
  uVar2 = *(ulonglong *)(param_2 + 0x50);
  local_160 = *(ulonglong *)(param_2 + 0xa8);
  local_158 = *(longlong *)(param_2 + 0xb0);
  if (*(longlong **)(param_2 + 0xb8) == (longlong *)0x0) {
    lVar4 = 0;
  }
  else {
    lVar4 = **(longlong **)(param_2 + 0xb8);
  }
  local_168 = *(byte **)(param_2 + 0xd8);
  local_190 = uVar2;
  do {
    if (param_7 == '\0') {
      uVar2 = param_4;
      uVar3 = local_160;
      uVar1 = FveGetRedirectedBlockOffset(param_4,local_160,local_158,&local_180);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar1 = FveGetRedirectedBlockSize(uVar2,(ulonglong)param_5,uVar3,local_198);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = local_190;
      uVar5 = local_198[0];
    }
    else {
      uVar5 = param_5;
      local_180 = param_4;
    }
    uVar3 = local_180;
    if (((lVar4 == 0) || (local_168 == (byte *)0x0)) ||
       ((local_188 == 2 && ((*local_168 & 2) == 0)))) {
      if (local_180 < uVar2) {
        if (uVar2 < uVar5 + local_180) {
          uVar1 = (int)uVar2 - (int)local_180;
        }
        else {
          uVar1 = uVar5;
        }
        memset(&local_148,0,0x100);
        uVar2 = Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline();
        if (((int)uVar2 == 0) || (param_8 == 0)) {
          local_108 = param_2 + 0x198;
        }
        else {
          local_108 = param_8;
        }
        local_d4 = *(undefined4 *)(param_2 + 4);
        uVar1 = FveFilteredWrite(3,(longlong)&local_148,uVar3,0xffffffffffffffff,uVar1,local_178,
                                 local_178,0);
        goto LAB_18000da87;
      }
    }
    else {
      memset(&local_140,0,0xf8);
      local_148 = local_190;
      uVar2 = Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline();
      if (((int)uVar2 == 0) || (param_8 == 0)) {
        local_108 = param_2 + 0x198;
      }
      else {
        local_108 = param_8;
      }
      local_f0 = FveFilteredWrite;
      local_e8 = local_178;
      local_e0 = local_178;
      local_140 = param_6;
      local_d4 = *(undefined4 *)(param_2 + 4);
      local_d0 = 0xb;
      local_138 = uVar3;
      local_100 = lVar4;
      local_d8 = uVar5;
      if (local_130 == 0) {
        uVar1 = FvepParseBlockAndFilter(&local_148);
        local_170 = param_4;
      }
      else {
        uVar1 = FvepParseBlockAndFilterLegacy(&local_148);
        local_170 = param_4;
      }
LAB_18000da87:
      uVar2 = local_190;
      param_4 = local_170;
    }
    if (uVar5 == param_5) {
      return uVar1;
    }
    param_4 = param_4 + uVar5;
    param_5 = param_5 - uVar5;
    local_198[0] = param_5;
    local_170 = param_4;
  } while( true );
}



===== FveIsEDriveUEFICapsule @ 18000daec =====

undefined8 FveIsEDriveUEFICapsule(longlong param_1,longlong param_2)

{
  ulonglong uVar1;
  undefined1 uVar2;
  
  uVar1 = (ulonglong)*(uint *)(param_1 + 8);
  uVar2 = 0;
  if ((((*(uint *)(param_1 + 8) & 2) != 0) && (0x57 < *(uint *)(param_2 + 0x50))) &&
     (uVar1 = 0, (*(uint *)(param_2 + 0x54) & 1) != 0)) {
    uVar2 = 0;
    if ((*(uint *)(param_1 + 0xc0) & 1) != 0) {
      uVar2 = 1;
    }
  }
  return CONCAT71((int7)(uVar1 >> 8),uVar2);
}



===== wil_details_FeatureReporting_IncrementOpportunityInCache @ 18000db24 =====

void wil_details_FeatureReporting_IncrementOpportunityInCache
               (uint *param_1,uint param_2,uint param_3,uint *param_4)

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
    uVar3 = uVar2 + param_3;
    if ((0x7f < uVar3) || (uVar3 < uVar2)) {
      param_4[2] = param_2;
      param_4[1] = uVar2;
      uVar3 = param_3;
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



===== wil_details_FeatureReporting_IncrementUsageInCache @ 18000dc08 =====

void wil_details_FeatureReporting_IncrementUsageInCache
               (uint *param_1,uint param_2,uint param_3,uint *param_4)

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
    uVar4 = uVar2 + param_3;
    if ((0x1ff < uVar4) || (uVar4 < uVar2)) {
      param_4[2] = param_2;
      param_4[1] = uVar2;
      uVar4 = param_3;
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



===== wil_details_FeatureReporting_RecordUsageInCache @ 18000dcf8 =====

uint * wil_details_FeatureReporting_RecordUsageInCache
                 (uint *param_1,uint *param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  if (param_3 == 0) {
LAB_18000de5f:
    wil_details_FeatureReporting_IncrementUsageInCache(param_2,param_3,param_5,param_1);
  }
  else {
    if (param_3 == 1) {
LAB_18000de4d:
      wil_details_FeatureReporting_IncrementOpportunityInCache(param_2,param_3,param_5,param_1);
      return param_1;
    }
    if ((param_3 != 2) && (param_3 != 3)) {
      if (param_3 == 4) goto LAB_18000de5f;
      if (param_3 == 5) goto LAB_18000de4d;
      if ((param_3 != 6) && (param_3 != 7)) {
        uVar5 = param_3 - 0x140;
        if ((int)uVar5 < 0x40) {
          uVar4 = param_2[1];
          do {
            if (((uVar4 & 0x10) == 0) || ((uVar4 >> 5 & 0x3f) != uVar5)) {
              uVar3 = 0;
            }
            else {
              uVar3 = 1;
            }
            param_1[4] = uVar3;
            LOCK();
            uVar3 = param_2[1];
            bVar7 = uVar4 == uVar3;
            if (bVar7) {
              param_2[1] = (uVar5 * 0x20 ^ uVar4) & 0x7e0 ^ uVar4 | 0x10;
            }
            else {
              uVar4 = uVar3;
            }
            UNLOCK();
          } while (!bVar7);
          if (param_1[4] != 0) {
            return param_1;
          }
        }
        param_1[1] = param_5;
        param_1[2] = param_3;
        param_1[3] = param_4;
        return param_1;
      }
    }
    uVar5 = 0;
    if (param_3 == 2) {
      uVar5 = 2;
    }
    else if (param_3 == 3) {
      uVar5 = 8;
    }
    else if (param_3 == 6) {
      uVar5 = 4;
    }
    else if (param_3 == 7) {
      uVar5 = 0x10;
    }
    uVar3 = 1;
    uVar4 = *param_2;
    do {
      uVar2 = uVar4;
      uVar4 = uVar5 | uVar2;
      param_1[4] = (uint)(uVar4 == uVar2);
      uVar6 = uVar4 | 1;
      if (uVar4 == uVar2) {
        uVar6 = uVar4;
      }
      LOCK();
      uVar1 = *param_2;
      if (uVar2 == uVar1) {
        *param_2 = uVar6;
        uVar4 = uVar2;
      }
      else {
        uVar4 = uVar1;
      }
      UNLOCK();
    } while (uVar2 != uVar1);
    if (((uVar6 & 1) == 0) || ((uVar2 & 1) != 0)) {
      uVar3 = 0;
    }
    *param_1 = uVar3;
  }
  return param_1;
}



===== wil_details_FeatureReporting_ReportUsageToService @ 18000de8c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void wil_details_FeatureReporting_ReportUsageToService
               (longlong param_1,undefined8 param_2,int param_3,undefined8 param_4)

{
  bool bVar1;
  uint uVar2;
  undefined7 extraout_var;
  uint uVar3;
  undefined8 uVar4;
  int local_res18 [4];
  
  uVar3 = (uint)param_2 & 1;
  uVar4 = param_4;
  local_res18[0] = param_3;
  uVar2 = wil_details_MapReportingKind(param_3,uVar3);
  bVar1 = wil_details_FeatureReporting_ReportUsageToServiceDirect(param_1,param_2,uVar2,(uint)uVar4)
  ;
  if (((int)CONCAT71(extraout_var,bVar1) != 0) &&
     (g_wil_details_pfnFeatureLoggingHook != (code *)0x0)) {
    (*g_wil_details_pfnFeatureLoggingHook)
              (*(undefined4 *)(param_1 + 0x18),*(undefined8 *)(param_1 + 0x10),0,uVar3,local_res18,0
               ,0,param_4);
  }
  return;
}



===== wil_details_FeatureReporting_ReportUsageToServiceDirect @ 18000df1c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool wil_details_FeatureReporting_ReportUsageToServiceDirect
               (longlong param_1,undefined8 param_2,uint param_3,uint param_4)

{
  uint6 uVar1;
  uint *puVar2;
  undefined1 auStackY_a8 [32];
  undefined8 local_78;
  uint local_70 [6];
  uint local_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  undefined8 local_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStackY_a8;
  puVar2 = wil_details_FeatureReporting_RecordUsageInCache
                     (local_70,*(uint **)(param_1 + 8),param_3,(uint)((ulonglong)param_2 >> 0x20),
                      param_4);
  local_58 = *puVar2;
  uStack_54 = puVar2[1];
  uStack_50 = puVar2[2];
  uStack_4c = puVar2[3];
  local_48 = *(undefined8 *)(puVar2 + 4);
  if (g_wil_details_recordFeatureUsage != (code *)0x0) {
    (*g_wil_details_recordFeatureUsage)
              (*(undefined4 *)(param_1 + 0x18),param_3,param_4,*(undefined8 *)(param_1 + 8));
  }
  if ((((uint)param_2 >> 10 & 1) != 0) && (param_3 != 0xfe)) {
    local_78._0_6_ = CONCAT24((short)param_3,*(undefined4 *)(param_1 + 0x18));
    uVar1 = (uint6)local_78;
    local_78 = (ulonglong)(uint6)local_78;
    if (((uint)param_2 >> 0xb & 1) != 0) {
      local_78 = CONCAT26(1,uVar1);
    }
    RtlNotifyFeatureUsage(&local_78);
  }
  return (int)local_48 == 0;
}



===== wil_details_FeatureStateCache_GetCachedFeatureEnabledState @ 18000e004 =====

ulonglong wil_details_FeatureStateCache_GetCachedFeatureEnabledState(uint *param_1,longlong param_2)

{
  ulonglong local_res8;
  
  local_res8 = (ulonglong)*param_1;
  if ((*param_1 & 2) == 0) {
    local_res8 = wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState
                           (param_1,local_res8,param_2);
  }
  return local_res8;
}



===== wil_details_FeatureStateCache_ReevaluateCachedFeatureEnabledState @ 18000e038 =====

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



===== wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath @ 18000e148 =====

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



===== wil_details_GetCurrentFeatureEnabledState @ 18000e1ac =====

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
        uVar6 = wil_details_FeatureStateCache_GetCachedFeatureEnabledState((uint *)*puVar3,puVar3);
        uVar4 = local_res8 & 0xfffffffe;
        local_res8 = (uint)(((uint)uVar6 & local_res8 & 1) != 0);
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



===== wil_details_IsEnabledFallback @ 18000e2e8 =====

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
     (wil_details_FeatureReporting_ReportUsageToService((longlong)param_3,local_res8,param_2,1),
     param_2 - 3U < 2)) {
    wil_details_FeatureStateCache_TryEnableDeviceUsageFastPath((uint)local_res8,param_2,param_3);
  }
  return (uint)param_1 & 1;
}



===== wil_details_MapReportingKind @ 18000e384 =====

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



===== wil_details_RecordCachedUsage @ 18000e424 =====

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



===== wil_details_RecordFeatureUsageReporting @ 18000e580 =====

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



===== CompareOEMFields @ 18000e604 =====

undefined1 CompareOEMFields(char *param_1,char *param_2)

{
  if (((((*param_1 == *param_2) && (param_1[1] == param_2[1])) && (param_1[2] == param_2[2])) &&
      ((param_1[3] == param_2[3] && (param_1[4] == param_2[4])))) &&
     ((param_1[5] == param_2[5] && ((param_1[6] == param_2[6] && (param_1[7] == param_2[7])))))) {
    return 1;
  }
  return 0;
}



===== FveCheckVolumeTypeEx @ 18000e650 =====

undefined4 FveCheckVolumeTypeEx(longlong param_1,uint param_2,uint *param_3)

{
  undefined8 uVar1;
  char cVar2;
  longlong *plVar3;
  longlong lVar4;
  char *pcVar5;
  ulonglong uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar8 = 0;
  if (param_3 != (uint *)0x0) {
    param_3[0] = 0;
    param_3[1] = 0;
    param_3[2] = 0;
    param_3[3] = 0;
    param_3[4] = 0;
    param_3[5] = 0;
    param_3[6] = 0;
    param_3[7] = 0;
    param_3[8] = 0;
    param_3[9] = 0;
    param_3[10] = 0;
    param_3[0xb] = 0;
  }
  if (0x1ff < param_2) {
    plVar3 = FveEowFindGuidRecognition(param_1,param_2);
    if (plVar3 == (longlong *)0x0) {
      lVar4 = FveFindGuidRecognition(param_1,param_2);
      if (lVar4 == 0) {
        uVar10 = (uint)*(ushort *)(param_1 + 0xb);
        pcVar5 = (char *)(param_1 + 3);
        uVar11 = (uint)*(byte *)(param_1 + 0xd);
        cVar2 = CompareOEMFields(pcVar5,"-FVE-FS-");
        if (cVar2 == '\0') {
          cVar2 = CompareOEMFields(pcVar5,"NTFS    ");
          if (((cVar2 == '\0') && (cVar2 = CompareOEMFields(pcVar5,"ReFS"), cVar2 == '\0')) &&
             (cVar2 = CompareOEMFields(pcVar5,"EXFAT   "), cVar2 == '\0')) {
            if (*(byte *)(param_1 + 0x10) == 0) {
              return 0;
            }
            uVar9 = (uint)*(ushort *)(param_1 + 0x13);
            if (*(ushort *)(param_1 + 0x13) == 0) {
              uVar9 = *(uint *)(param_1 + 0x20);
            }
            if ((short)uVar10 == 0) {
              return 0;
            }
            if ((char)uVar11 == '\0') {
              return 0;
            }
            uVar6 = (ulonglong)*(ushort *)(param_1 + 0x11) << 5;
            if ((uVar10 & uVar10 - 1) == 0) {
              uVar6 = (ulonglong)((int)uVar6 + -1 + uVar10 & ~(uVar10 - 1));
            }
            else {
              iVar7 = (int)(uVar6 % (ulonglong)uVar10);
              if (iVar7 != 0) {
                uVar6 = (ulonglong)(((int)uVar6 - iVar7) + uVar10);
              }
            }
            if (((uVar9 - (int)(uVar6 / uVar10)) -
                ((uint)*(ushort *)(param_1 + 0x16) * (uint)*(byte *)(param_1 + 0x10) +
                (uint)*(ushort *)(param_1 + 0xe))) / uVar11 + 2 < 0xff7) {
              return 0;
            }
            return 1;
          }
          uVar8 = 1;
        }
        else {
          uVar8 = 2;
          if (param_3 != (uint *)0x0) {
            *param_3 = uVar10 * uVar11;
            lVar4 = (ulonglong)(uVar10 * uVar11) * *(longlong *)(param_1 + 0x38);
            *(longlong *)(param_3 + 6) = lVar4;
            *(longlong *)(param_3 + 4) = lVar4;
            *(longlong *)(param_3 + 2) = lVar4;
          }
        }
      }
      else {
        uVar8 = 2;
        if (param_3 != (uint *)0x0) {
          uVar1 = *(undefined8 *)(lVar4 + 0x18);
          *(undefined8 *)(param_3 + 2) = *(undefined8 *)(lVar4 + 0x10);
          *(undefined8 *)(param_3 + 4) = uVar1;
          *(undefined8 *)(param_3 + 6) = *(undefined8 *)(lVar4 + 0x20);
          *param_3 = 1;
          param_3[8] = 0;
          param_3[9] = 0;
          param_3[10] = 0;
          param_3[0xb] = 0;
        }
      }
    }
    else {
      uVar8 = 3;
      if (param_3 != (uint *)0x0) {
        lVar4 = plVar3[3];
        *(longlong *)(param_3 + 2) = plVar3[2];
        *(longlong *)(param_3 + 4) = lVar4;
        *(longlong *)(param_3 + 6) = plVar3[4];
        *param_3 = 1;
        lVar4 = plVar3[6];
        *(longlong *)(param_3 + 8) = plVar3[5];
        *(longlong *)(param_3 + 10) = lVar4;
      }
    }
  }
  return uVar8;
}



===== FveDecryptRegion @ 18000e844 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FveDecryptRegion(int param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                    undefined4 param_5,undefined8 param_6,undefined8 param_7,longlong param_8)

{
  longlong lVar1;
  bool bVar2;
  int iVar3;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_38 = *(uint *)(param_2 + 0x78);
  iVar3 = 0;
  if (((local_38 >> 0xc & 1) == 0) && (param_1 == 3)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((local_38 & 1) == 0) {
    local_38 = 0;
  }
  else {
    local_38 = local_38 & 0xfc0;
  }
  local_34 = *(undefined4 *)(param_2 + 0x7c);
  lVar1 = *(longlong *)(param_2 + 0x40);
  local_30 = *(undefined4 *)(param_2 + 0x80);
  local_2c = *(undefined4 *)(param_2 + 0x84);
  local_28 = *(undefined4 *)(param_2 + 0x88);
  local_24 = 0;
  local_20 = *(undefined8 *)(param_2 + 0x90);
  local_18 = *(undefined8 *)(param_2 + 0x98);
  local_10 = *(undefined8 *)(param_2 + 0xa0);
  if (bVar2) {
    if (lVar1 == 0) {
      iVar3 = -0x3fffff5e;
      if (((param_8 != 0) && (*(int *)(param_8 + 0x1c) == 0)) && (*(int *)(param_8 + 0x18) == 0)) {
        *(undefined4 *)(param_8 + 0x1c) = 0xc00000a2;
        *(undefined4 *)(param_8 + 0x18) = 0x103;
      }
    }
    else {
      iVar3 = (**(code **)(lVar1 + 8))
                        (lVar1,param_3,param_6,param_5,param_7,*(undefined4 *)(param_2 + 0x74),
                         &local_38);
      if ((((iVar3 < 0) && (param_8 != 0)) && (*(int *)(param_8 + 0x1c) == 0)) &&
         (*(int *)(param_8 + 0x18) == 0)) {
        *(int *)(param_8 + 0x1c) = iVar3;
        *(undefined4 *)(param_8 + 0x18) = 0x102;
      }
    }
  }
  return iVar3;
}



===== FveEncryptRegion @ 18000e96c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FveEncryptRegion(int param_1,longlong param_2,undefined8 param_3,undefined8 param_4,
                    undefined4 param_5,undefined8 param_6,undefined8 param_7,longlong param_8)

{
  undefined8 *puVar1;
  bool bVar2;
  int iVar3;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined8 local_20;
  undefined8 local_18;
  undefined8 local_10;
  
  local_38 = *(uint *)(param_2 + 0x78);
  iVar3 = 0;
  if (((local_38 >> 0xc & 1) == 0) && (param_1 == 3)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((local_38 & 1) == 0) {
    local_38 = 0;
  }
  else {
    local_38 = local_38 & 0xfc0;
  }
  local_34 = *(undefined4 *)(param_2 + 0x7c);
  puVar1 = *(undefined8 **)(param_2 + 0x40);
  local_30 = *(undefined4 *)(param_2 + 0x80);
  local_2c = *(undefined4 *)(param_2 + 0x84);
  local_28 = *(undefined4 *)(param_2 + 0x88);
  local_24 = 0;
  local_20 = *(undefined8 *)(param_2 + 0x90);
  local_18 = *(undefined8 *)(param_2 + 0x98);
  local_10 = *(undefined8 *)(param_2 + 0xa0);
  if (bVar2) {
    if (puVar1 == (undefined8 *)0x0) {
      iVar3 = -0x3fffff5e;
      if (((param_8 != 0) && (*(int *)(param_8 + 0x1c) == 0)) && (*(int *)(param_8 + 0x18) == 0)) {
        *(undefined4 *)(param_8 + 0x1c) = 0xc00000a2;
        *(undefined4 *)(param_8 + 0x18) = 0x103;
      }
    }
    else {
      iVar3 = (*(code *)*puVar1)(puVar1,param_3,param_6,param_5,param_7,
                                 *(undefined4 *)(param_2 + 0x74),&local_38);
      if ((((iVar3 < 0) && (param_8 != 0)) && (*(int *)(param_8 + 0x1c) == 0)) &&
         (*(int *)(param_8 + 0x18) == 0)) {
        *(int *)(param_8 + 0x1c) = iVar3;
        *(undefined4 *)(param_8 + 0x18) = 0x102;
      }
    }
  }
  return iVar3;
}



===== FveEowFindGuidRecognition @ 18000ea94 =====

longlong * FveEowFindGuidRecognition(longlong param_1,uint param_2)

{
  longlong *plVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  if (0x37 < param_2) {
    for (uVar3 = 0; uVar3 <= (ulonglong)param_2 - 0x38; uVar3 = (ulonglong)((int)uVar3 + 1)) {
      plVar1 = (longlong *)(uVar3 + param_1);
      lVar2 = 0x4d0edd8092a84d3b - *plVar1;
      if (lVar2 == 0) {
        lVar2 = -0x2751b1d71c4eb162 - plVar1[1];
      }
      if (lVar2 == 0) {
        return plVar1;
      }
    }
  }
  return (longlong *)0x0;
}



===== FveFilteredRead @ 18000eaf0 =====

undefined8
FveFilteredRead(int param_1,longlong param_2,undefined8 param_3,undefined8 param_4,uint param_5,
               void *param_6,void *param_7,longlong param_8)

{
  undefined8 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    if (param_6 != param_7) {
      memmove(param_7,param_6,(ulonglong)param_5);
    }
  }
  else if (param_1 == 1) {
    if (param_6 != param_7) {
      memmove(param_7,param_6,(ulonglong)param_5);
    }
    uVar1 = *(undefined8 *)(param_2 + 0x18);
    *(undefined8 *)((longlong)param_7 + 3) = 0x202020205346544e;
    *(undefined8 *)((longlong)param_7 + 0x38) = uVar1;
  }
  else if (param_1 == 2) {
    memset(param_7,0,(ulonglong)param_5);
    if (((param_8 != 0) && (*(int *)(param_8 + 0x1c) == 0)) && (*(int *)(param_8 + 0x18) == 0)) {
      *(undefined4 *)(param_8 + 0x1c) = 0;
      *(undefined4 *)(param_8 + 0x18) = 1;
    }
  }
  else if (param_1 == 3) {
    iVar2 = FveDecryptRegion(3,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    if (iVar2 != 0) {
      memset(param_7,0,(ulonglong)param_5);
    }
  }
  return 0;
}



===== FveFilteredWrite @ 18000ec20 =====

int FveFilteredWrite(int param_1,longlong param_2,undefined8 param_3,undefined8 param_4,uint param_5
                    ,void *param_6,void *param_7,longlong param_8)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = 0;
  if (param_1 == 0) {
    if (param_6 != param_7) {
      memmove(param_7,param_6,(ulonglong)param_5);
    }
  }
  else if (param_1 == 1) {
    if (param_5 < 0x200) {
      return -0x3ffffff3;
    }
    iVar3 = FveCheckVolumeTypeEx((longlong)param_6,param_5,(uint *)0x0);
    if (iVar3 != 1) {
      return -0x3fffff5e;
    }
    if (*(longlong *)((longlong)param_6 + 0x38) != *(longlong *)(param_2 + 0x18)) {
      return -0x3fffff5e;
    }
    if (param_6 != param_7) {
      memmove(param_7,param_6,(ulonglong)param_5);
    }
    uVar1 = *(undefined8 *)(param_2 + 0x20);
    *(undefined8 *)((longlong)param_7 + 3) = 0x2d53462d4556462d;
    *(undefined8 *)((longlong)param_7 + 0x38) = uVar1;
  }
  else {
    if (param_1 == 2) {
      for (uVar4 = 0; uVar4 < param_5; uVar4 = uVar4 + 1) {
        if (*(char *)((ulonglong)uVar4 + (longlong)param_6) != '\0') {
          if (((param_8 != 0) && (*(int *)(param_8 + 0x1c) == 0)) && (*(int *)(param_8 + 0x18) == 0)
             ) {
            *(undefined4 *)(param_8 + 0x1c) = 0xc00000a2;
            *(undefined4 *)(param_8 + 0x18) = 0x100;
          }
          return -0x3fffff5e;
        }
      }
      if (param_8 == 0) {
        return -0x3fdefff6;
      }
      if (*(int *)(param_8 + 0x1c) != 0) {
        return -0x3fdefff6;
      }
      if (*(int *)(param_8 + 0x18) == 0) {
        *(undefined4 *)(param_8 + 0x1c) = 0xc021000a;
        *(undefined4 *)(param_8 + 0x18) = 2;
        return -0x3fdefff6;
      }
      return -0x3fdefff6;
    }
    if (param_1 == 3) {
      iVar2 = FveEncryptRegion(3,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    }
  }
  return iVar2;
}



===== FveFindGuidRecognition @ 18000edb4 =====

longlong FveFindGuidRecognition(longlong param_1,uint param_2)

{
  longlong lVar1;
  ulonglong uVar2;
  
  if (0x27 < param_2) {
    for (uVar2 = 0; uVar2 <= (ulonglong)param_2 - 0x28; uVar2 = (ulonglong)((int)uVar2 + 1)) {
      lVar1 = RtlCompareMemory(&INFORMATION_OFFSET_GUID,uVar2 + param_1,0x10);
      if (lVar1 == 0x10) {
        return uVar2 + param_1;
      }
    }
  }
  return 0;
}



===== FveLibIdentifyCurrentRegionTypeAndEnd @ 18000ee34 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined4
FveLibIdentifyCurrentRegionTypeAndEnd
          (ulonglong param_1,uint param_2,ulonglong param_3,uint param_4,uint param_5,
          longlong param_6,ulonglong param_7,char param_8,longlong param_9,longlong param_10,
          longlong param_11,longlong *param_12,byte param_13,ulonglong *param_14)

{
  ulonglong uVar1;
  longlong lVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  int iVar6;
  uint uVar7;
  ulonglong *puVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined8 local_res8;
  uint local_res10;
  uint local_res20 [2];
  
  uVar9 = 0;
  iVar6 = -1;
  uVar7 = param_4 - 1;
  uVar10 = uVar7 & param_4;
  if ((uVar10 != 0) || (param_4 == 0)) {
    uVar7 = (uint)(0xffffffff % (ulonglong)param_4);
  }
  local_res8 = 0;
  uVar1 = ~uVar7 + param_1;
  if (param_3 <= param_1) {
    uVar1 = param_1 + param_4;
    if (param_1 + param_4 <= param_1) {
      uVar1 = param_1;
    }
    *param_14 = uVar1;
    return 0;
  }
  if (param_1 < uVar1) {
    if (uVar1 <= param_3) goto LAB_18000eeaa;
  }
  else {
    uVar1 = param_3;
LAB_18000eeaa:
    param_3 = uVar1;
  }
  local_res20[0] = (int)param_3 - (int)param_1;
  *param_14 = param_3;
  local_res10 = param_2;
  if (param_10 != 0) {
    if ((param_13 & 0x21) == 0x21) {
      *param_12 = param_11;
    }
    else {
      if ((param_11 != 0) || (param_11 = *param_12, param_11 != 0)) {
        iVar6 = *(int *)(param_11 + 0x50);
      }
      lVar2 = FveEowFindBitmap(param_10,iVar6,param_1,local_res20[0],local_res20);
      *param_12 = lVar2;
      if (lVar2 != 0) {
        *param_14 = local_res20[0] + param_1;
      }
    }
  }
  uVar1 = 0;
  while (uVar7 = (uint)uVar1, uVar7 < param_5) {
    uVar1 = FveLibInsideRegion(param_1,param_14,*(ulonglong *)(param_6 + uVar1 * 0x10),
                               *(longlong *)(param_6 + 8 + uVar1 * 0x10));
    if ((char)uVar1 != '\0') {
      return 2;
    }
    uVar1 = (ulonglong)(uVar7 + 1);
  }
  if (param_10 == 0) {
    if (param_7 <= param_1) {
      return 0;
    }
    if (param_7 < *param_14) {
      *param_14 = param_7;
      return 3;
    }
    return 3;
  }
  uVar5 = 2;
  for (uVar1 = 0; (uint)uVar1 < (uint)uVar5; uVar1 = (ulonglong)((int)uVar1 + 1)) {
    uVar7 = (uint)*(ushort *)(param_10 + 0x8a);
    if ((uVar10 == 0) && (param_4 != 0)) {
      uVar7 = (uVar7 - 1) + param_4 & -param_4;
    }
    else if (uVar7 % param_4 != 0) {
      uVar7 = (uVar7 - uVar7 % param_4) + param_4;
    }
    uVar3 = FveLibInsideRegion(param_1,param_14,*(ulonglong *)(param_10 + 0xa8 + uVar1 * 8),
                               (ulonglong)uVar7);
    if ((char)uVar3 != '\0') {
      return (int)uVar5;
    }
  }
  uVar7 = *(uint *)(param_10 + 0xa0);
  uVar1 = 0;
  while ((uint)uVar1 < uVar7) {
    lVar2 = *(longlong *)(*(longlong *)(param_10 + 0x10) + uVar1 * 8);
    uVar3 = param_1;
    puVar8 = param_14;
    uVar4 = FveLibInsideRegion(param_1,param_14,*(ulonglong *)(param_10 + 0xb8 + uVar1 * 8),
                               (ulonglong)*(uint *)(lVar2 + 0x4c));
    iVar6 = (int)uVar1;
    if ((char)uVar4 != '\0') {
      return (int)uVar5;
    }
    uVar1 = FveLibInsideRegion(uVar3,puVar8,*(ulonglong *)(lVar2 + 100),
                               (ulonglong)*(uint *)(param_10 + 0x98));
    if ((char)uVar1 != '\0') {
      return (int)uVar5;
    }
    uVar1 = (ulonglong)(iVar6 + 1);
  }
  if ((param_8 == '\0') && (param_9 == 0)) {
    return 0;
  }
  lVar2 = *param_12;
  if (lVar2 == 0) {
    return 3;
  }
  uVar1 = *(longlong *)(lVar2 + 0x5c) + *(longlong *)(lVar2 + 0x54);
  if (uVar1 < *param_14) {
    *param_14 = uVar1;
  }
  if (*(code **)(param_10 + 0x68) != (code *)0x0) {
    (**(code **)(param_10 + 0x68))(lVar2,&local_res8);
  }
  lVar2 = *param_12;
  if (*(char *)(lVar2 + 0xd) == '\0') {
    if (*(char *)(lVar2 + 0xc) == '\0') {
      if ((param_13 & 0x17) != 0x13) {
        uVar5 = FveEowEncryptedRegion(param_10,lVar2,param_1,param_14);
        uVar9 = 0;
        if ((char)uVar5 != '\0') {
          uVar9 = 3;
        }
        goto LAB_18000f0e9;
      }
      *param_14 = local_res10 + param_1;
    }
    uVar9 = 3;
  }
LAB_18000f0e9:
  if (*(longlong *)(param_10 + 0x68) != 0) {
    (**(code **)(param_10 + 0x70))(*param_12,local_res8);
  }
  return uVar9;
}



===== FveLibInsideRegion @ 18000f124 =====

ulonglong FveLibInsideRegion(ulonglong param_1,ulonglong *param_2,ulonglong param_3,longlong param_4
                            )

{
  ulonglong in_RAX;
  
  if (param_1 < param_3) {
    if (param_3 < *param_2) {
      *param_2 = param_3;
    }
  }
  else {
    in_RAX = param_3 + param_4;
    if (param_1 < in_RAX) {
      *param_2 = in_RAX;
      return CONCAT71((int7)(in_RAX >> 8),1);
    }
  }
  return in_RAX & 0xffffffffffffff00;
}



===== FvepParseBlockAndFilter @ 18000f14c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FvepParseBlockAndFilter(ulonglong *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong local_res8;
  ulonglong local_res10;
  ulonglong local_res18;
  longlong local_res20;
  
  local_res18 = param_1[6];
  iVar4 = 0;
  local_res20 = 0;
  bVar1 = false;
  local_res10 = 0;
  uVar8 = param_1[2];
  uVar7 = (ulonglong)(uint)param_1[0xe];
  uVar11 = param_1[0xd];
  local_res8 = param_1[0xc];
  if (((uVar8 == 0) || (uVar8 + uVar7 < uVar8)) || (5 < (uint)param_1[0x15])) {
LAB_18000f35a:
    iVar4 = -0x3ffffff3;
  }
  else {
    for (uVar10 = 0; (uint)uVar10 < (uint)param_1[0x15]; uVar10 = (ulonglong)((uint)uVar10 + 1)) {
      if (param_1[uVar10 * 2 + 0x17] + param_1[(uVar10 + 0xb) * 2] < param_1[(uVar10 + 0xb) * 2])
      goto LAB_18000f35a;
    }
    while (uVar6 = (uint)uVar7, uVar6 != 0) {
      uVar2 = FveLibIdentifyCurrentRegionTypeAndEnd
                        (uVar8,uVar6,param_1[1],*(uint *)((longlong)param_1 + 0x74),
                         (uint)param_1[0x15],(longlong)(param_1 + 0x16),*param_1,'\0',param_1[8],
                         param_1[9],param_1[10],&local_res20,(byte)param_1[0xf],&local_res10);
      uVar10 = local_res18;
      if (local_res10 <= uVar7 + uVar8) {
        if (local_res10 <= uVar8) goto LAB_18000f35a;
        uVar7 = (ulonglong)(uint)((int)local_res10 - (int)uVar8);
      }
      uVar9 = (uint)uVar7;
      uVar5 = param_1[0xf];
      if ((((byte)uVar5 & 0x41) == 0x41) && ((uVar11 & 0xfff) != 0)) {
        uVar3 = 0x1000 - ((uint)uVar11 & 0xfff);
        if (uVar3 <= uVar9) {
          uVar7 = (ulonglong)uVar3;
        }
        uVar9 = (uint)uVar7;
        bVar1 = true;
        local_res10 = uVar7 + uVar8;
        *(uint *)(param_1 + 0xf) = (uint)uVar5 & 0xffffffbf;
      }
      iVar4 = (*(code *)param_1[0xb])(uVar2,param_1,uVar8,local_res18,uVar9,local_res8,uVar11,0);
      if (bVar1) {
        *(uint *)(param_1 + 0xf) = (uint)param_1[0xf] | 0x40;
        bVar1 = false;
      }
      if (iVar4 < 0) {
        return iVar4;
      }
      if (uVar6 < uVar9) goto LAB_18000f35a;
      uVar5 = (ulonglong)uVar9;
      uVar7 = (ulonglong)(uVar6 - uVar9);
      local_res8 = local_res8 + uVar5;
      uVar8 = uVar8 + uVar5;
      uVar11 = uVar11 + uVar5;
      if (param_1[5] != 0) {
        local_res18 = uVar10 + uVar5;
      }
    }
  }
  return iVar4;
}



===== FvepParseBlockAndFilterLegacy @ 18000f37c =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

int FvepParseBlockAndFilterLegacy(ulonglong *param_1)

{
  ulonglong uVar1;
  int iVar2;
  ulonglong uVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  undefined1 uVar12;
  
  iVar2 = 0;
  uVar7 = param_1[2];
  uVar10 = param_1[1] - (ulonglong)*(uint *)((longlong)param_1 + 0x74);
  uVar11 = param_1[6];
  uVar6 = (uint)param_1[0xe];
  uVar8 = param_1[0xc];
  uVar9 = param_1[0xd];
  do {
    if (uVar6 == 0) {
      return iVar2;
    }
    if (uVar7 < 0x2000) {
      uVar4 = *(uint *)((longlong)param_1 + 0x74);
      uVar5 = 0x2000;
      if (uVar7 < uVar4) {
        uVar5 = (ulonglong)uVar4;
      }
      uVar12 = uVar7 < uVar4;
    }
    else if (uVar7 < uVar10) {
      uVar12 = 0;
      uVar5 = uVar10;
      for (uVar3 = 0; (uint)uVar3 < (uint)param_1[0x15]; uVar3 = (ulonglong)((uint)uVar3 + 1)) {
        uVar1 = param_1[(uVar3 + 0xb) * 2];
        if (uVar7 < uVar1) {
          if (uVar1 < uVar5) {
            uVar5 = uVar1;
          }
        }
        else if (uVar7 < param_1[uVar3 * 2 + 0x17] + uVar1) {
          uVar12 = 2;
          uVar5 = param_1[uVar3 * 2 + 0x17] + uVar1;
          goto LAB_18000f479;
        }
      }
      uVar3 = *param_1;
      if ((uVar7 < uVar3) && (uVar12 = 3, uVar3 < uVar5)) {
        uVar5 = uVar3;
      }
    }
    else {
      uVar5 = *(uint *)((longlong)param_1 + 0x74) + uVar10;
      if (uVar7 < uVar5) {
        uVar12 = 1;
      }
      else {
        if (param_1[1] <= uVar7) {
          return -0x3ffffff3;
        }
        uVar12 = 0;
        uVar5 = param_1[1];
      }
    }
LAB_18000f479:
    if (uVar6 + uVar7 < uVar5) {
      uVar4 = uVar6;
    }
    else {
      uVar4 = (int)uVar5 - (int)uVar7;
    }
    iVar2 = (*(code *)param_1[0xb])(uVar12,param_1,uVar7,uVar11,uVar4,uVar8,uVar9,0);
    if (iVar2 < 0) {
      return iVar2;
    }
    uVar5 = (ulonglong)uVar4;
    uVar6 = uVar6 - uVar4;
    uVar7 = uVar7 + uVar5;
    uVar8 = uVar8 + uVar5;
    uVar9 = uVar9 + uVar5;
    if (param_1[5] != 0) {
      uVar11 = uVar11 + uVar5;
    }
  } while( true );
}



===== FveGetRedirectedBlockOffset @ 18000f504 =====

uint FveGetRedirectedBlockOffset
               (ulonglong param_1,ulonglong param_2,longlong param_3,ulonglong *param_4)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong uVar3;
  
  uVar2 = 0;
  *param_4 = param_1;
  if (param_1 < param_2) {
    uVar1 = param_1 + param_3;
    uVar3 = 0xffffffffffffffff;
    if (uVar1 >= param_1) {
      uVar3 = uVar1;
    }
    *param_4 = uVar3;
    uVar2 = -(uint)(uVar1 < param_1) & 0xc0000095;
  }
  return uVar2;
}



===== FveGetRedirectedBlockSize @ 18000f530 =====

uint FveGetRedirectedBlockSize
               (ulonglong param_1,ulonglong param_2,ulonglong param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  ulonglong local_res10 [3];
  
  uVar3 = 0xffffffff;
  if (param_2 < 0x100000000) {
    *param_4 = (int)param_2;
    if (param_3 <= param_1) {
      return 0;
    }
    local_res10[0] = param_2 + param_1;
    if (param_1 <= local_res10[0]) {
      if (local_res10[0] <= param_3) {
        return 0;
      }
      uVar1 = RtlULongLongSub(param_3,param_1,(longlong *)local_res10);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar2 = (undefined4)uVar3;
      if (local_res10[0] <= uVar3) {
        uVar2 = (undefined4)local_res10[0];
      }
      *param_4 = uVar2;
      return -(uint)(uVar3 < local_res10[0]) & 0xc0000095;
    }
  }
  else {
    *param_4 = 0xffffffff;
  }
  return 0xc0000095;
}



===== RtlULongLongSub @ 18000f5a8 =====

uint RtlULongLongSub(ulonglong param_1,ulonglong param_2,longlong *param_3)

{
  longlong lVar1;
  
  if (param_1 < param_2) {
    lVar1 = -1;
  }
  else {
    lVar1 = param_1 - param_2;
  }
  *param_3 = lVar1;
  return -(uint)(param_1 < param_2) & 0xc0000095;
}



===== FveEowEncryptedRegion @ 18000f5d0 =====

/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

undefined8
FveEowEncryptedRegion(longlong param_1,longlong param_2,ulonglong param_3,ulonglong *param_4)

{
  ulonglong uVar1;
  uint uVar2;
  ulonglong in_RAX;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined1 uVar5;
  uint uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  int local_res10 [2];
  
  uVar8 = (ulonglong)*(uint *)(param_1 + 0x94);
  uVar1 = *(ulonglong *)(param_2 + 0x54);
  uVar7 = param_3 - uVar1;
  uVar9 = *(longlong *)(param_2 + 0x5c) + uVar1;
  uVar5 = 0;
  uVar3 = uVar8 - 1;
  if (((uVar3 & uVar8) == 0) && (uVar8 != 0)) {
    uVar7 = ~uVar3 & uVar7;
  }
  else {
    in_RAX = uVar7 / uVar8;
    uVar7 = uVar7 - uVar7 % uVar8;
  }
  uVar4 = *param_4;
  local_res10[0] = 0;
  if ((((param_3 < uVar4) && (uVar1 <= uVar9)) && (uVar1 <= param_3)) && (param_3 < uVar9)) {
    if (uVar9 < uVar4) {
      *param_4 = uVar9;
      uVar4 = uVar9;
    }
    uVar4 = uVar4 - uVar1;
    if (((uVar3 & uVar8) == 0) && (uVar8 != 0)) {
      uVar4 = (uVar4 - 1) + uVar8 & ~uVar3;
    }
    else if (uVar4 % uVar8 != 0) {
      uVar4 = (uVar4 - uVar4 % uVar8) + uVar8;
    }
    uVar3 = (uVar1 + (uVar4 - (uVar7 + uVar1))) / uVar8;
    in_RAX = (**(code **)(param_1 + 0x78))
                       (param_2,*(undefined4 *)(param_2 + 0x14),uVar7 / uVar8 & 0xffffffff,
                        local_res10);
    if ((uint)in_RAX == 0) {
      uVar5 = 1;
    }
    else {
      uVar2 = local_res10[0] - (int)(uVar7 / uVar8);
      uVar6 = (uint)uVar3;
      if (uVar2 == 0) {
        if ((uint)in_RAX < uVar6) {
          uVar3 = in_RAX;
        }
        uVar3 = uVar3 & 0xffffffff;
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
        if (uVar6 <= uVar2) {
          uVar2 = uVar6;
        }
        uVar3 = (ulonglong)uVar2;
      }
      in_RAX = uVar3 * uVar8 + uVar7 + uVar1;
      if (in_RAX < *param_4) {
        *param_4 = in_RAX;
      }
    }
  }
  return CONCAT71((int7)(in_RAX >> 8),uVar5);
}



===== FveEowFindBitmap @ 18000f728 =====

longlong FveEowFindBitmap(longlong param_1,int param_2,ulonglong param_3,uint param_4,uint *param_5)

{
  ulonglong uVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  uint uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  uint uVar10;
  char local_res8 [8];
  ulonglong local_48 [2];
  
  uVar4 = (ulonglong)param_4;
  local_48[0] = 0;
  local_res8[0] = '\0';
  if (*(ulonglong *)(param_1 + 0x28) <= param_3) {
    *param_5 = param_4;
    return 0;
  }
  *param_5 = 0;
  if (param_4 == 0) {
    return 0;
  }
  uVar1 = param_3 + uVar4;
  if (uVar1 < param_3) {
    return 0;
  }
  uVar9 = 0xffffffff;
  uVar8 = uVar1;
  if (param_2 == -1) {
    uVar6 = RtlULongLongMult(param_3,(ulonglong)*(uint *)(param_1 + 0xa0),local_48);
    if ((int)uVar6 < 0) {
      return 0;
    }
    uVar5 = local_48[0] / *(ulonglong *)(param_1 + 0x30);
    if (uVar9 < uVar5) {
      return 0;
    }
  }
  else {
    uVar5 = (ulonglong)(param_2 + 1);
  }
  uVar2 = *(uint *)(param_1 + 0xa0);
  uVar10 = uVar2;
  if ((uint)uVar5 <= uVar2) {
    uVar10 = (uint)uVar5;
  }
  uVar7 = uVar10;
  do {
    if (uVar7 < uVar2) {
      lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + (ulonglong)uVar7 * 8);
      uVar6 = FveEowOverlapBitmap(lVar3,param_3,uVar8,uVar4,local_res8,param_5);
      if ((int)uVar6 < 0) {
        return 0;
      }
      if (local_res8[0] != '\0') {
        return lVar3;
      }
      uVar7 = uVar7 + 1;
      if (uVar10 != 0) {
        uVar8 = uVar1;
        goto LAB_18000f842;
      }
    }
    else {
      if (uVar10 == 0) {
        return 0;
      }
LAB_18000f842:
      uVar10 = uVar10 - 1;
      lVar3 = *(longlong *)(*(longlong *)(param_1 + 0x10) + (ulonglong)uVar10 * 8);
      uVar6 = FveEowOverlapBitmap(lVar3,param_3,uVar8,uVar4,local_res8,param_5);
      if ((int)uVar6 < 0) {
        return 0;
      }
      if (local_res8[0] != '\0') {
        return lVar3;
      }
    }
    uVar8 = uVar1;
  } while( true );
}



===== FveEowOverlapBitmap @ 18000f8c8 =====

undefined8
FveEowOverlapBitmap(longlong param_1,ulonglong param_2,ulonglong param_3,ulonglong param_4,
                   undefined1 *param_5,undefined4 *param_6)

{
  ulonglong uVar1;
  ulonglong uVar2;
  
  *param_6 = 0;
  *param_5 = 0;
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = *(ulonglong *)(param_1 + 0x54);
  uVar2 = *(longlong *)(param_1 + 0x5c) + uVar1;
  if (uVar1 <= uVar2) {
    if (param_2 < uVar1) {
      return 0;
    }
    if (uVar2 <= param_2) {
      return 0;
    }
    if ((param_3 <= uVar2) || (param_4 = uVar2 - param_2, param_4 < 0x100000000)) {
      *param_6 = (int)param_4;
      *param_5 = 1;
      return 0;
    }
    *param_6 = 0xffffffff;
  }
  return 0xc0000095;
}



===== RtlULongLongMult @ 18000f938 =====

undefined8 RtlULongLongMult(ulonglong param_1,ulonglong param_2,undefined8 *param_3)

{
  undefined1 auVar1 [16];
  undefined1 auVar2 [16];
  undefined8 uVar3;
  
  uVar3 = 0;
  auVar1._8_8_ = 0;
  auVar1._0_8_ = param_2;
  auVar2._8_8_ = 0;
  auVar2._0_8_ = param_1;
  if (SUB168(auVar1 * auVar2,8) == 0) {
    *param_3 = SUB168(auVar1 * auVar2,0);
  }
  else {
    *param_3 = 0xffffffffffffffff;
    uVar3 = 0xc0000095;
  }
  return uVar3;
}



===== FveXtsAesExpandKey @ 18000f960 =====

undefined8
FveXtsAesExpandKey(undefined1 (*param_1) [16],undefined1 (*param_2) [16],ulonglong param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = SymCryptXtsAesExpandKeyEx(param_1,param_2,param_3);
  uVar3 = 0;
  iVar1 = (int)uVar2;
  if (iVar1 != 0) {
    if (iVar1 == 0x8001) {
      uVar3 = 0xc0000206;
    }
    else if (iVar1 == 0x8007) {
      uVar3 = 0xc000a002;
    }
    else if (iVar1 == 0x8009) {
      uVar3 = 0xc000a009;
    }
    else if (iVar1 == 0x800b) {
      uVar3 = 0xc0000002;
    }
    else if (iVar1 == 0x800d) {
      uVar3 = 0xc0000023;
    }
    else if (iVar1 == 0x800e) {
      uVar3 = 0xc000000d;
    }
    else if (iVar1 == 0x8010) {
      uVar3 = 0xc000a000;
    }
    else if (iVar1 == 0x8011) {
      uVar3 = 0xc00000bb;
    }
    else {
      uVar3 = 0xc0000001;
    }
  }
  return uVar3;
}



===== ADiffuserDecrypt @ 18000f9e4 =====

void ADiffuserDecrypt(uint *param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  
  uVar5 = param_1[param_2 - 5];
  uVar2 = param_1[param_2 - 4];
  uVar3 = param_1[param_2 - 3];
  uVar9 = param_1[param_2 - 2];
  uVar10 = param_1[param_2 - 1];
  lVar4 = 5;
  do {
    if (param_1 <= param_1 + (param_2 - 0x10)) {
      puVar8 = param_1 + 2;
      do {
        uVar2 = (uVar10 ^ uVar2) + puVar8[-1];
        uVar6 = ((uVar5 << 9 | uVar5 >> 0x17) ^ uVar9) + puVar8[-2];
        uVar7 = (uVar9 ^ uVar2) + puVar8[1];
        uVar9 = ((uVar3 << 0xd | uVar3 >> 0x13) ^ uVar6) + *puVar8;
        *puVar8 = uVar9;
        uVar3 = (uVar7 ^ uVar6) + puVar8[3];
        puVar8[1] = uVar7;
        uVar5 = ((uVar10 << 9 | uVar10 >> 0x17) ^ uVar9) + puVar8[2];
        uVar10 = (uVar9 ^ uVar3) + puVar8[5];
        puVar8[2] = uVar5;
        puVar8[-1] = uVar2;
        puVar8[-2] = uVar6;
        uVar6 = ((uVar2 * 0x2000 | uVar2 >> 0x13) ^ uVar5) + puVar8[4];
        uVar9 = (uVar5 ^ uVar10) + puVar8[7];
        uVar2 = ((uVar7 * 0x200 | uVar7 >> 0x17) ^ uVar6) + puVar8[6];
        puVar8[3] = uVar3;
        uVar5 = (uVar9 ^ uVar6) + puVar8[9];
        puVar8[5] = uVar10;
        puVar8[7] = uVar9;
        puVar8[6] = uVar2;
        uVar7 = ((uVar3 * 0x2000 | uVar3 >> 0x13) ^ uVar2) + puVar8[8];
        uVar3 = (uVar2 ^ uVar5) + puVar8[0xb];
        uVar2 = ((uVar10 * 0x200 | uVar10 >> 0x17) ^ uVar7) + puVar8[10];
        uVar10 = (uVar3 ^ uVar7) + puVar8[0xd];
        uVar9 = ((uVar9 * 0x2000 | uVar9 >> 0x13) ^ uVar2) + puVar8[0xc];
        puVar8[4] = uVar6;
        puVar8[0xd] = uVar10;
        puVar8[8] = uVar7;
        puVar8[9] = uVar5;
        puVar8[10] = uVar2;
        puVar8[0xb] = uVar3;
        puVar8[0xc] = uVar9;
        puVar1 = puVar8 + 0xe;
        puVar8 = puVar8 + 0x10;
      } while (puVar1 <= param_1 + (param_2 - 0x10));
    }
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  return;
}



===== ADiffuserEncrypt @ 18000fb38 =====

void ADiffuserEncrypt(longlong param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint local_res8;
  uint local_res10;
  longlong local_res18;
  
  local_res18 = 5;
  local_res8 = *(uint *)(param_1 + (ulonglong)(param_2 - 6) * 4);
  uVar5 = *(uint *)(param_1 + (ulonglong)(param_2 - 5) * 4);
  local_res10 = *(uint *)(param_1 + (ulonglong)(param_2 - 4) * 4);
  uVar6 = *(uint *)(param_1 + (ulonglong)(param_2 - 3) * 4);
  puVar1 = (uint *)(param_1 + (ulonglong)param_2 * 4);
  do {
    puVar8 = puVar1;
    if ((uint *)(param_1 + 0x40U) <= puVar1) {
      puVar7 = puVar1;
      do {
        uVar2 = puVar7[-7];
        puVar8 = puVar7 + -8;
        uVar3 = *puVar8;
        puVar7[-1] = puVar7[-1] - (uVar6 ^ local_res8);
        uVar6 = puVar7[-0xb];
        uVar4 = (uVar2 << 0xd | uVar2 >> 0x13) ^ local_res10;
        local_res10 = puVar7[-0xc];
        puVar7[-2] = puVar7[-2] - uVar4;
        uVar4 = puVar7[-9];
        puVar7[-3] = puVar7[-3] - (uVar3 ^ uVar5);
        uVar5 = (uVar4 << 9 | uVar4 >> 0x17) ^ local_res8;
        local_res8 = puVar7[-0xe];
        puVar7[-4] = puVar7[-4] - uVar5;
        puVar7[-5] = puVar7[-5] - (uVar2 ^ puVar7[-10]);
        puVar7[-6] = puVar7[-6] - ((uVar6 << 0xd | uVar6 >> 0x13) ^ uVar3);
        uVar5 = puVar7[-0xd];
        puVar7[-7] = uVar2 - (local_res10 ^ uVar4);
        *puVar8 = uVar3 - ((uVar5 << 9 | uVar5 >> 0x17) ^ puVar7[-10]);
        puVar7 = puVar8;
      } while ((uint *)(param_1 + 0x40U) <= puVar8);
    }
    uVar2 = puVar8[-7];
    puVar8[-1] = puVar8[-1] - (uVar6 ^ local_res8);
    uVar3 = puVar8[-8];
    puVar8[-2] = puVar8[-2] - ((uVar2 << 0xd | uVar2 >> 0x13) ^ local_res10);
    puVar8[-3] = puVar8[-3] - (uVar3 ^ uVar5);
    uVar5 = *(uint *)(param_1 + (ulonglong)(param_2 - 1) * 4);
    puVar8[-4] = puVar8[-4] - ((uVar5 << 9 | uVar5 >> 0x17) ^ local_res8);
    uVar4 = *(uint *)(param_1 + (ulonglong)(param_2 - 2) * 4);
    puVar8[-5] = puVar8[-5] - (uVar2 ^ uVar4);
    uVar6 = *(uint *)(param_1 + (ulonglong)(param_2 - 3) * 4);
    puVar8[-6] = puVar8[-6] - ((uVar6 << 0xd | uVar6 >> 0x13) ^ uVar3);
    local_res10 = *(uint *)(param_1 + (ulonglong)(param_2 - 4) * 4);
    puVar8[-7] = uVar2 - (local_res10 ^ uVar5);
    uVar5 = *(uint *)(param_1 + (ulonglong)(param_2 - 5) * 4);
    local_res18 = local_res18 + -1;
    puVar8[-8] = uVar3 - ((uVar5 << 9 | uVar5 >> 0x17) ^ uVar4);
    local_res8 = *(uint *)(param_1 + (ulonglong)(param_2 - 6) * 4);
  } while (local_res18 != 0);
  return;
}



===== BDiffuserDecrypt @ 18000fd1c =====

void BDiffuserDecrypt(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  longlong lVar9;
  uint uVar10;
  uint uVar11;
  
  uVar6 = param_1[2];
  uVar5 = param_1[3];
  uVar4 = param_1[4];
  uVar10 = param_1[5];
  lVar9 = 3;
  do {
    puVar8 = param_1;
    if (param_1 <= param_1 + (param_2 - 0x10)) {
      uVar11 = *param_1;
      puVar7 = param_1;
      do {
        uVar1 = puVar7[6];
        puVar8 = puVar7 + 8;
        uVar2 = puVar7[7];
        uVar3 = uVar10 ^ uVar6;
        uVar6 = puVar7[10];
        uVar3 = uVar3 + uVar11;
        uVar11 = *puVar8;
        puVar7[2] = puVar7[2] + (uVar4 ^ uVar2);
        uVar4 = puVar7[0xc];
        *puVar7 = uVar3;
        uVar3 = (uVar1 << 10 | uVar1 >> 0x16) ^ uVar5;
        uVar5 = puVar7[0xb];
        puVar7[1] = puVar7[1] + uVar3;
        uVar3 = (uVar11 << 0x19 | uVar11 >> 7) ^ uVar10;
        uVar10 = puVar7[0xd];
        puVar7[3] = puVar7[3] + uVar3;
        puVar7[4] = puVar7[4] + (puVar7[9] ^ uVar1);
        puVar7[5] = puVar7[5] + ((uVar6 << 10 | uVar6 >> 0x16) ^ uVar2);
        puVar7[6] = (uVar11 ^ uVar5) + uVar1;
        puVar7[7] = ((uVar4 << 0x19 | uVar4 >> 7) ^ puVar7[9]) + uVar2;
        puVar7 = puVar8;
      } while (puVar8 <= param_1 + (param_2 - 0x10));
    }
    uVar11 = puVar8[6];
    uVar1 = puVar8[7];
    *puVar8 = *puVar8 + (uVar10 ^ uVar6);
    puVar8[2] = puVar8[2] + (uVar4 ^ uVar1);
    puVar8[1] = puVar8[1] + ((uVar11 << 10 | uVar11 >> 0x16) ^ uVar5);
    uVar4 = *param_1;
    puVar8[3] = puVar8[3] + ((uVar4 << 0x19 | uVar4 >> 7) ^ uVar10);
    uVar10 = param_1[1];
    puVar8[4] = puVar8[4] + (uVar10 ^ uVar11);
    uVar6 = param_1[2];
    puVar8[5] = puVar8[5] + ((uVar6 << 10 | uVar6 >> 0x16) ^ uVar1);
    uVar5 = param_1[3];
    puVar8[6] = (uVar4 ^ uVar5) + uVar11;
    uVar4 = param_1[4];
    puVar8[7] = ((uVar4 << 0x19 | uVar4 >> 7) ^ uVar10) + uVar1;
    uVar10 = param_1[5];
    lVar9 = lVar9 + -1;
  } while (lVar9 != 0);
  return;
}



===== BDiffuserEncrypt @ 18000fe88 =====

void BDiffuserEncrypt(uint *param_1,ulonglong param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar4 = *param_1;
  uVar3 = param_1[1];
  lVar6 = 3;
  uVar5 = param_1[2];
  uVar7 = param_1[3];
  uVar9 = param_1[4];
  puVar2 = param_1 + (param_2 & 0xffffffff);
  do {
    while (param_1 + 0x10 <= puVar2) {
      uVar8 = puVar2[-2] - (uVar7 ^ uVar4);
      uVar10 = puVar2[-4] - (uVar8 ^ uVar3);
      puVar2[-2] = uVar8;
      puVar2[-4] = uVar10;
      uVar7 = puVar2[-1] - ((uVar9 << 0x19 | uVar9 >> 7) ^ uVar3);
      puVar2[-1] = uVar7;
      uVar3 = puVar2[-3] - ((uVar5 << 10 | uVar5 >> 0x16) ^ uVar7);
      uVar5 = puVar2[-5] - ((uVar4 << 0x19 | uVar4 >> 7) ^ uVar3);
      uVar9 = puVar2[-6] - (uVar7 ^ uVar10);
      puVar2[-3] = uVar3;
      puVar2[-6] = uVar9;
      uVar3 = puVar2[-8] - (uVar9 ^ uVar3);
      uVar7 = puVar2[-7] - ((uVar8 * 0x400 | uVar8 >> 0x16) ^ uVar5);
      puVar2[-8] = uVar3;
      uVar4 = puVar2[-9] - ((uVar10 * 0x2000000 | uVar10 >> 7) ^ uVar7);
      puVar2[-7] = uVar7;
      uVar10 = puVar2[-10] - (uVar3 ^ uVar5);
      puVar2[-10] = uVar10;
      puVar2[-5] = uVar5;
      uVar8 = puVar2[-0xb] - ((uVar9 * 0x400 | uVar9 >> 0x16) ^ uVar4);
      puVar2[-9] = uVar4;
      uVar9 = puVar2[-0xc] - (uVar7 ^ uVar10);
      puVar2[-0xb] = uVar8;
      puVar2[-0xc] = uVar9;
      uVar7 = puVar2[-0xd] - ((uVar3 * 0x2000000 | uVar3 >> 7) ^ uVar8);
      uVar5 = puVar2[-0xe] - (uVar9 ^ uVar4);
      puVar2[-0xd] = uVar7;
      puVar2[-0xe] = uVar5;
      puVar1 = puVar2 + -0x10;
      uVar3 = puVar2[-0xf] - ((uVar10 * 0x400 | uVar10 >> 0x16) ^ uVar7);
      uVar4 = *puVar1 - (uVar8 ^ uVar5);
      puVar2[-0xf] = uVar3;
      *puVar1 = uVar4;
      puVar2 = puVar1;
    }
    lVar6 = lVar6 + -1;
    puVar2 = param_1 + (param_2 & 0xffffffff);
  } while (lVar6 != 0);
  return;
}



===== ComputeSectorKey @ 18001000c =====

void ComputeSectorKey(uint *param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  lVar2 = 2;
  puVar1 = param_3;
  do {
    *puVar1 = param_2;
    puVar1 = puVar1 + 2;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  param_3[1] = 0;
  param_3[3] = 0x8000000000000000;
  FveAesEcbEncrypt(param_1,(longlong)param_3,0x20,(undefined1 (*) [16])param_3);
  return;
}



===== DiffuserXorKey @ 180010058 =====

void DiffuserXorKey(uint *param_1,longlong param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = *param_1;
  uVar4 = param_1[1];
  uVar5 = param_1[2];
  uVar6 = param_1[3];
  uVar7 = 2;
  do {
    puVar2 = (uint *)(param_2 + (ulonglong)(uVar7 - 2) * 4);
    *puVar2 = *puVar2 ^ uVar3;
    puVar2 = (uint *)(param_2 + (ulonglong)(uVar7 - 1) * 4);
    *puVar2 = *puVar2 ^ uVar4;
    puVar2 = (uint *)(param_2 + (ulonglong)uVar7 * 4);
    *puVar2 = *puVar2 ^ uVar5;
    puVar2 = (uint *)(param_2 + (ulonglong)(uVar7 + 1) * 4);
    *puVar2 = *puVar2 ^ uVar6;
    puVar2 = (uint *)(param_2 + (ulonglong)(uVar7 + 6) * 4);
    *puVar2 = *puVar2 ^ uVar3;
    puVar2 = (uint *)(param_2 + (ulonglong)(uVar7 + 7) * 4);
    *puVar2 = *puVar2 ^ uVar4;
    puVar2 = (uint *)(param_2 + (ulonglong)(uVar7 + 8) * 4);
    *puVar2 = *puVar2 ^ uVar5;
    puVar2 = (uint *)(param_2 + (ulonglong)(uVar7 + 9) * 4);
    *puVar2 = *puVar2 ^ uVar6;
    uVar1 = uVar7 + 0xe;
    uVar7 = uVar7 + 0x10;
  } while (uVar1 <= param_3 - 0x10U);
  uVar3 = param_1[4];
  uVar4 = param_1[5];
  uVar5 = param_1[6];
  uVar6 = param_1[7];
  if (3 < param_3 - 0xcU) {
    uVar7 = 6;
    do {
      puVar2 = (uint *)(param_2 + (ulonglong)(uVar7 - 2) * 4);
      *puVar2 = *puVar2 ^ uVar3;
      puVar2 = (uint *)(param_2 + (ulonglong)(uVar7 - 1) * 4);
      *puVar2 = *puVar2 ^ uVar4;
      puVar2 = (uint *)(param_2 + (ulonglong)uVar7 * 4);
      *puVar2 = *puVar2 ^ uVar5;
      puVar2 = (uint *)(param_2 + (ulonglong)(uVar7 + 1) * 4);
      *puVar2 = *puVar2 ^ uVar6;
      puVar2 = (uint *)(param_2 + (ulonglong)(uVar7 + 6) * 4);
      *puVar2 = *puVar2 ^ uVar3;
      puVar2 = (uint *)(param_2 + (ulonglong)(uVar7 + 7) * 4);
      *puVar2 = *puVar2 ^ uVar4;
      puVar2 = (uint *)(param_2 + (ulonglong)(uVar7 + 8) * 4);
      *puVar2 = *puVar2 ^ uVar5;
      puVar2 = (uint *)(param_2 + (ulonglong)(uVar7 + 9) * 4);
      *puVar2 = *puVar2 ^ uVar6;
      uVar1 = uVar7 + 0xe;
      uVar7 = uVar7 + 0x10;
    } while (uVar1 <= param_3 - 0xcU);
  }
  return;
}



===== FveAesCbcDecryptSectorsPageIsolation @ 180010150 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FveAesCbcDecryptSectorsPageIsolation
                    (uint *param_1,ulonglong param_2,ulonglong *param_3,uint param_4,
                    ulonglong *param_5,uint param_6,uint *param_7)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong *puVar4;
  ulonglong uVar5;
  longlong lVar6;
  ulonglong *puVar7;
  uint uVar8;
  uint uVar9;
  longlong lVar10;
  longlong lVar11;
  ulonglong uVar12;
  uint uVar13;
  ulonglong uVar14;
  undefined1 auStackY_518 [32];
  ulonglong *local_4e0;
  ulonglong *local_4d8;
  ulonglong local_4c0;
  ulonglong local_4b8 [14];
  ulonglong local_448 [128];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_518;
  uVar12 = (ulonglong)param_6;
  uVar5 = 0;
  local_4e0 = param_5;
  uVar14 = param_4 / uVar12;
  uVar1 = (uint)(0x1000 / uVar12);
  if ((param_7 == (uint *)0x0) || ((*param_7 & 0x800) == 0)) {
    uVar13 = g_chunkedDecryptionMaxSize;
  }
  else {
    uVar13 = param_7[4];
  }
  if (param_6 < uVar13) {
    uVar8 = 0x8000;
    if (uVar13 < 0x8000) {
      uVar8 = uVar13;
    }
    uVar2 = (ulonglong)uVar8 / (ulonglong)param_6;
  }
  else {
    uVar2 = 1;
  }
  if ((int)uVar14 != 0) {
    local_4d8 = param_3;
    local_4c0 = param_2;
    do {
      if ((uint)uVar14 < (uint)uVar2) {
        uVar5 = uVar14;
      }
      else {
        uVar5 = uVar2;
      }
      uVar13 = (uint)uVar5;
      uVar8 = (uVar13 - 1) * param_6 >> 0xc;
      if (uVar13 != 0) {
        puVar7 = local_448 + 1;
        uVar3 = uVar5;
        do {
          *puVar7 = 0;
          puVar7[-1] = local_4c0;
          puVar7 = puVar7 + 2;
          local_4c0 = local_4c0 + uVar12;
          uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
      }
      uVar3 = FveAesEcbEncrypt(param_1,(longlong)local_448,uVar5 << 4,(undefined1 (*) [16])local_448
                              );
      uVar5 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) break;
      if (uVar8 != 0) {
        puVar7 = local_4b8;
        uVar5 = (ulonglong)uVar8;
        puVar4 = local_4d8;
        do {
          uVar3 = puVar4[0x201];
          *puVar7 = puVar4[0x200];
          puVar7[1] = uVar3;
          puVar7 = puVar7 + 2;
          uVar5 = uVar5 - 1;
          puVar4 = puVar4 + 0x200;
        } while (uVar5 != 0);
      }
      puVar7 = local_4b8;
      uVar5 = (ulonglong)uVar8;
      if (0xf < (ulonglong)uVar8 << 4) {
        do {
          SymCryptAesDecrypt((longlong)param_1,(uint *)puVar7,(undefined1 (*) [16])puVar7);
          puVar7 = puVar7 + 2;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      if (uVar8 != 0) {
        puVar7 = local_4b8 + 1;
        uVar5 = (ulonglong)uVar8;
        uVar9 = uVar1;
        do {
          uVar3 = (ulonglong)uVar9;
          uVar9 = uVar9 + uVar1;
          puVar7[-1] = puVar7[-1] ^ local_448[uVar3 * 2];
          *puVar7 = *puVar7 ^ local_448[uVar3 * 2 + 1];
          puVar7 = puVar7 + 2;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      lVar10 = (uVar12 - 0x10) + (longlong)local_4d8;
      if (1 < uVar13) {
        lVar6 = 0x10;
        uVar5 = (ulonglong)(uVar13 - 1);
        do {
          puVar7 = (ulonglong *)((longlong)local_448 + lVar6);
          lVar11 = 2;
          do {
            *puVar7 = *puVar7 ^ *(ulonglong *)
                                 (((lVar10 - lVar6) - (longlong)local_448) + (longlong)puVar7);
            puVar7 = puVar7 + 1;
            lVar11 = lVar11 + -1;
          } while (lVar11 != 0);
          lVar10 = lVar10 + uVar12;
          lVar6 = lVar6 + 0x10;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
      SymCryptAesCbcDecrypt
                ((longlong)param_1,(uint *)local_448,(uint *)local_4d8,(uint *)local_4e0,
                 (ulonglong)(param_6 * uVar13));
      uVar5 = 0;
      if (1 < uVar13) {
        lVar10 = 0x10;
        uVar3 = (ulonglong)(uVar13 - 1);
        puVar7 = local_4e0;
        do {
          puVar7 = (ulonglong *)((longlong)puVar7 + uVar12);
          lVar6 = 2;
          puVar4 = puVar7;
          do {
            *puVar4 = *puVar4 ^ *(ulonglong *)
                                 ((longlong)puVar4 +
                                 (longlong)local_448 + (lVar10 - (longlong)puVar7));
            puVar4 = puVar4 + 1;
            lVar6 = lVar6 + -1;
          } while (lVar6 != 0);
          lVar10 = lVar10 + 0x10;
          uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
      }
      if (uVar8 != 0) {
        lVar10 = 0;
        uVar3 = (ulonglong)uVar8;
        puVar7 = local_4e0;
        do {
          puVar7 = puVar7 + 0x200;
          lVar6 = 2;
          puVar4 = puVar7;
          do {
            *puVar4 = *(ulonglong *)
                       ((longlong)local_4b8 + (lVar10 - (longlong)puVar7) + (longlong)puVar4);
            puVar4 = puVar4 + 1;
            lVar6 = lVar6 + -1;
          } while (lVar6 != 0);
          lVar10 = lVar10 + 0x10;
          uVar3 = uVar3 - 1;
        } while (uVar3 != 0);
      }
      local_4e0 = (ulonglong *)((longlong)local_4e0 + (ulonglong)(param_6 * uVar13));
      local_4d8 = (ulonglong *)((longlong)local_4d8 + (ulonglong)(param_6 * uVar13));
      uVar13 = (uint)uVar14 - uVar13;
      uVar14 = (ulonglong)uVar13;
    } while (uVar13 != 0);
  }
  puVar7 = local_4b8;
  for (lVar10 = 0x70; lVar10 != 0; lVar10 = lVar10 + -1) {
    *(undefined1 *)puVar7 = 0;
    puVar7 = (ulonglong *)((longlong)puVar7 + 1);
  }
  return uVar5;
}



===== FveCryptAesDecrypt @ 180010490 =====

void FveCryptAesDecrypt(longlong param_1,ulonglong param_2,ulonglong *param_3,uint param_4,
                       ulonglong *param_5,uint param_6,uint *param_7)

{
  FveAesCbcDecryptSectors
            (*(uint **)(param_1 + 0x10),param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



===== FveCryptAesEncrypt @ 1800104d0 =====

void FveCryptAesEncrypt(longlong param_1,longlong param_2,uint *param_3,uint param_4,
                       undefined1 (*param_5) [16],uint param_6)

{
  FveAesCbcEncryptSectors(*(uint **)(param_1 + 0x10),param_2,param_3,param_4,param_5,param_6);
  return;
}



===== FveCryptElephantDecrypt @ 180010500 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FveCryptElephantDecrypt
              (longlong param_1,ulonglong param_2,ulonglong *param_3,uint param_4,ulonglong *param_5
              ,uint param_6,uint *param_7)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  longlong lVar4;
  ulonglong uVar5;
  ulonglong *puVar6;
  undefined1 auStackY_c8 [32];
  uint local_78 [8];
  ulonglong local_58;
  
  local_58 = __security_cookie ^ (ulonglong)auStackY_c8;
  uVar3 = param_6 >> 2;
  iVar1 = FveAesCbcDecryptSectors
                    (*(uint **)(param_1 + 0x10),param_2,param_3,param_4,param_3,param_6,param_7);
  if (-1 < iVar1) {
    puVar6 = param_3;
    for (uVar5 = (ulonglong)param_4; param_6 <= (uint)uVar5;
        uVar5 = (ulonglong)((uint)uVar5 - param_6)) {
      iVar1 = ComputeSectorKey((uint *)(*(longlong *)(param_1 + 0x10) + 0x1f0),param_2,
                               (undefined8 *)local_78);
      if (iVar1 < 0) goto LAB_1800105ea;
      BDiffuserDecrypt((uint *)puVar6,uVar3);
      ADiffuserDecrypt((uint *)puVar6,uVar3);
      DiffuserXorKey(local_78,(longlong)puVar6,uVar3);
      puVar6 = (ulonglong *)((longlong)puVar6 + (ulonglong)param_6);
      param_2 = param_2 + param_6;
    }
    if (param_3 != param_5) {
      memmove(param_5,param_3,(ulonglong)param_4);
    }
  }
LAB_1800105ea:
  puVar2 = local_78;
  lVar4 = 4;
  do {
    puVar2[0] = 0;
    puVar2[1] = 0;
    puVar2 = puVar2 + 2;
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  return iVar1;
}



===== FveCryptElephantEncrypt @ 180010630 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

ulonglong FveCryptElephantEncrypt
                    (longlong param_1,longlong param_2,uint *param_3,uint param_4,uint *param_5,
                    uint param_6)

{
  uint uVar1;
  ulonglong uVar2;
  ulonglong _Size;
  longlong lVar3;
  uint *puVar4;
  uint uVar5;
  undefined1 auStackY_b8 [32];
  uint local_70 [8];
  ulonglong local_50;
  
  local_50 = __security_cookie ^ (ulonglong)auStackY_b8;
  uVar5 = param_6 >> 2;
  _Size = (ulonglong)param_4;
  if (param_3 != param_5) {
    memmove(param_5,param_3,_Size);
  }
  lVar3 = param_2;
  puVar4 = param_5;
  while( true ) {
    if ((uint)_Size < param_6) break;
    uVar1 = ComputeSectorKey(*(uint **)(param_1 + 0x10) + 0x7c,lVar3,(undefined8 *)local_70);
    uVar2 = (ulonglong)uVar1;
    if ((int)uVar1 < 0) goto LAB_180010704;
    DiffuserXorKey(local_70,(longlong)puVar4,uVar5);
    ADiffuserEncrypt((longlong)puVar4,uVar5);
    BDiffuserEncrypt(puVar4,(ulonglong)uVar5);
    puVar4 = (uint *)((longlong)puVar4 + (ulonglong)param_6);
    _Size = (ulonglong)((uint)_Size - param_6);
    lVar3 = lVar3 + (ulonglong)param_6;
  }
  uVar2 = FveAesCbcEncryptSectors
                    (*(uint **)(param_1 + 0x10),param_2,param_5,param_4,(undefined1 (*) [16])param_5
                     ,param_6);
  uVar2 = uVar2 & 0xffffffff;
LAB_180010704:
  puVar4 = local_70;
  lVar3 = 4;
  do {
    puVar4[0] = 0;
    puVar4[1] = 0;
    puVar4 = puVar4 + 2;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  return uVar2;
}



===== FveCryptInitializeAes @ 180010748 =====

undefined8
FveCryptInitializeAes
          (ushort *param_1,undefined8 *param_2,uint param_3,uint *param_4,int param_5,short param_6,
          ushort param_7)

{
  undefined8 uVar1;
  
  uVar1 = FveCryptInitialize(param_1,(longlong)param_2,param_3,param_4,param_6,param_7,0x1f0);
  if ((-1 < (int)uVar1) && (param_2 != (undefined8 *)0x0)) {
    SymCryptAesExpandKeyInternal
              ((undefined1 (*) [16])param_2[2],(undefined1 (*) [16])(param_1 + 6),(longlong)param_5,
               '\x01');
    uVar1 = 0;
    *param_2 = FveCryptAesEncrypt;
    param_2[1] = FveCryptAesDecrypt;
  }
  return uVar1;
}



===== FveCryptInitializeElephant @ 1800107c4 =====

undefined8
FveCryptInitializeElephant
          (ushort *param_1,undefined8 *param_2,uint param_3,uint *param_4,int param_5,int param_6,
          ushort param_7)

{
  undefined8 uVar1;
  
  uVar1 = FveCryptInitialize(param_1,(longlong)param_2,param_3,param_4,0x40,param_7,0x3e0);
  if ((-1 < (int)uVar1) && (param_2 != (undefined8 *)0x0)) {
    SymCryptAesExpandKeyInternal
              ((undefined1 (*) [16])param_2[2],(undefined1 (*) [16])(param_1 + 6),(longlong)param_6,
               '\x01');
    SymCryptAesExpandKeyInternal
              ((undefined1 (*) [16])(param_2[2] + 0x1f0),(undefined1 (*) [16])(param_1 + 0x16),
               (longlong)param_5,'\x01');
    uVar1 = 0;
    *param_2 = FveCryptElephantEncrypt;
    param_2[1] = FveCryptElephantDecrypt;
  }
  return uVar1;
}



===== FveCryptInitializeXtsAes @ 180010858 =====

void FveCryptInitializeXtsAes
               (ushort *param_1,undefined8 *param_2,uint param_3,uint *param_4,int param_5,
               short param_6,ushort param_7)

{
  undefined8 uVar1;
  
  uVar1 = FveCryptInitialize(param_1,(longlong)param_2,param_3,param_4,param_6,param_7,0x3e0);
  if ((-1 < (int)uVar1) && (param_2 != (undefined8 *)0x0)) {
    uVar1 = FveXtsAesExpandKey((undefined1 (*) [16])param_2[2],(undefined1 (*) [16])(param_1 + 6),
                               (longlong)param_5);
    if (-1 < (int)uVar1) {
      *param_2 = FveCryptXtsAesEncrypt;
      param_2[1] = FveCryptXtsAesDecrypt;
    }
  }
  return;
}



===== FveCryptXtsAesDecrypt @ 1800108e0 =====

undefined8
FveCryptXtsAesDecrypt
          (longlong param_1,ulonglong param_2,ulonglong *param_3,uint param_4,
          undefined1 (*param_5) [16],uint param_6)

{
  SymCryptXtsAesDecrypt
            (*(longlong *)(param_1 + 0x10),(ulonglong)param_6,param_2 / param_6,param_3,param_5,
             (ulonglong)param_4);
  return 0;
}



===== FveCryptXtsAesEncrypt @ 180010930 =====

undefined8
FveCryptXtsAesEncrypt
          (longlong param_1,ulonglong param_2,ulonglong *param_3,uint param_4,
          undefined1 (*param_5) [16],uint param_6)

{
  SymCryptXtsAesEncrypt
            (*(uint **)(param_1 + 0x10),(ulonglong)param_6,param_2 / param_6,param_3,param_5,
             (ulonglong)param_4);
  return 0;
}



===== FveDatumMustBe @ 180010978 =====

undefined8 FveDatumMustBe(ulonglong *param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined8 local_res8;
  
  local_res8 = 0;
  if (param_1 != (ulonglong *)0x0) {
    uVar1 = FveDatumHeaderSafe(param_1,param_2,&local_res8);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    if ((0x22 < local_res8._4_2_) ||
       ((&PTR_FveDatumErasedTypeProp_180014100)[local_res8._4_2_] == (undefined *)0x0)) {
      return 0xc021002a;
    }
    if (local_res8._4_2_ == 1) {
      return uVar1;
    }
  }
  return 0xc000000d;
}



===== SymCryptXtsAesDecryptInternal @ 1800109cc =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptXtsAesDecryptInternal
               (longlong param_1,ulonglong param_2,longlong *param_3,ulonglong *param_4,
               undefined1 (*param_5) [16],ulonglong param_6)

{
  int iVar1;
  byte in_CR8;
  undefined1 auStackY_b8 [32];
  undefined1 local_78 [64];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  memset(local_78,0,0x40);
  if ((g_SymCryptCpuFeaturesNotPresent & 0x816) == 0) {
    if ((g_SymCryptCpuFeaturesNotPresent & 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
      SymCryptFatal(0x206d6d79);
    }
    if ((in_CR8 < 3) && (iVar1 = KeSaveExtendedProcessorState(4,local_78), -1 < iVar1)) {
      SymCryptXtsAesDecryptInternalYmm(param_1,param_2,param_3,(uint *)param_4,param_5,param_6);
      KeRestoreExtendedProcessorState(local_78);
      return;
    }
  }
  if ((g_SymCryptCpuFeaturesNotPresent & 6) == 0) {
    SymCryptXtsAesDecryptInternalXmm(param_1,param_2,param_3,(uint *)param_4,param_5,param_6);
  }
  else {
    SymCryptXtsAesDecryptInternalAsm(param_1,param_2,param_3,param_4,(longlong)param_5,param_6);
  }
  return;
}



===== SymCryptXtsAesDecryptInternalAsm @ 180010ae0 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptXtsAesDecryptInternalAsm
               (longlong param_1,ulonglong param_2,longlong *param_3,ulonglong *param_4,
               longlong param_5,ulonglong param_6)

{
  longlong lVar1;
  uint *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined1 auStackY_188 [32];
  ulonglong local_148 [34];
  
  local_148[0x20] = __security_cookie ^ (ulonglong)auStackY_188;
  lVar1 = param_3[1];
  lVar5 = *param_3;
  do {
    if (param_6 < param_2) {
      SymCryptWipeAsm(local_148,0x100);
      return;
    }
    puVar2 = (uint *)(param_1 + 0x1f0);
    uVar3 = 0;
    do {
      *(longlong *)((longlong)local_148 + uVar3) = lVar5;
      param_6 = param_6 - param_2;
      *(longlong *)((longlong)local_148 + uVar3 + 8) = lVar1;
      lVar5 = lVar5 + 1;
      uVar3 = uVar3 + 0x10;
      if (param_6 < param_2) break;
    } while (uVar3 < 0x100);
    SymCryptAesEcbEncryptAsm(puVar2,(longlong)local_148,(undefined4 *)local_148,uVar3);
    uVar4 = 0;
    if (uVar3 != 0) {
      do {
        SymCryptXtsDecryptDataUnit
                  (puVar2,param_1,(ulonglong *)((longlong)local_148 + uVar4),param_4,param_5,param_2
                  );
        param_4 = (ulonglong *)((longlong)param_4 + param_2);
        param_5 = param_5 + param_2;
        uVar4 = uVar4 + 0x10;
      } while (uVar4 < uVar3);
    }
  } while( true );
}



===== SymCryptXtsAesDecryptInternalYmm @ 180010c0c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptXtsAesDecryptInternalYmm
               (longlong param_1,ulonglong param_2,longlong *param_3,uint *param_4,
               undefined1 (*param_5) [16],ulonglong param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined1 auStackY_288 [32];
  uint local_248 [2];
  longlong alStack_240 [31];
  uint local_148 [64];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_288;
  lVar1 = param_3[1];
  lVar4 = *param_3;
  do {
    if (param_6 < param_2) {
      SymCryptWipeAsm((undefined8 *)local_248,0x200);
      return;
    }
    uVar2 = 0;
    do {
      *(longlong *)((longlong)local_248 + uVar2) = lVar4;
      param_6 = param_6 - param_2;
      *(longlong *)((longlong)alStack_240 + uVar2) = lVar1;
      lVar4 = lVar4 + 1;
      uVar2 = uVar2 + 0x10;
      if (param_6 < param_2) break;
    } while (uVar2 < 0x100);
    SymCryptAesEcbEncryptXmm
              ((uint *)(param_1 + 0x1f0),local_248,(undefined1 (*) [16])local_248,uVar2);
    uVar3 = 0;
    if (uVar2 != 0) {
      do {
        SymCryptXtsAesDecryptDataUnitYmm_2048
                  (param_1,(undefined1 (*) [16])((longlong)local_248 + uVar3),local_148,param_4,
                   param_5,param_2);
        param_4 = (uint *)((longlong)param_4 + param_2);
        param_5 = (undefined1 (*) [16])(*param_5 + param_2);
        uVar3 = uVar3 + 0x10;
      } while (uVar3 < uVar2);
    }
  } while( true );
}



===== SymCryptXtsAesEncryptInternal @ 180010d40 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptXtsAesEncryptInternal
               (uint *param_1,ulonglong param_2,longlong *param_3,ulonglong *param_4,
               undefined1 (*param_5) [16],ulonglong param_6)

{
  int iVar1;
  byte in_CR8;
  undefined1 auStackY_b8 [32];
  undefined1 local_78 [64];
  ulonglong local_38;
  
  local_38 = __security_cookie ^ (ulonglong)auStackY_b8;
  memset(local_78,0,0x40);
  if ((g_SymCryptCpuFeaturesNotPresent & 0x816) == 0) {
    if ((g_SymCryptCpuFeaturesNotPresent & 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
      SymCryptFatal(0x206d6d79);
    }
    if ((in_CR8 < 3) && (iVar1 = KeSaveExtendedProcessorState(4,local_78), -1 < iVar1)) {
      SymCryptXtsAesEncryptInternalYmm(param_1,param_2,param_3,param_4,param_5,param_6);
      KeRestoreExtendedProcessorState(local_78);
      return;
    }
  }
  if ((g_SymCryptCpuFeaturesNotPresent & 6) == 0) {
    SymCryptXtsAesEncryptInternalXmm(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    SymCryptXtsAesEncryptInternalAsm(param_1,param_2,param_3,param_4,(longlong)param_5,param_6);
  }
  return;
}



===== SymCryptXtsAesEncryptInternalAsm @ 180010e54 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptXtsAesEncryptInternalAsm
               (uint *param_1,ulonglong param_2,longlong *param_3,ulonglong *param_4,
               longlong param_5,ulonglong param_6)

{
  longlong lVar1;
  uint *puVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined1 auStackY_188 [32];
  ulonglong local_148 [34];
  
  local_148[0x20] = __security_cookie ^ (ulonglong)auStackY_188;
  lVar1 = param_3[1];
  lVar5 = *param_3;
  do {
    if (param_6 < param_2) {
      SymCryptWipeAsm(local_148,0x100);
      return;
    }
    puVar2 = param_1 + 0x7c;
    uVar3 = 0;
    do {
      *(longlong *)((longlong)local_148 + uVar3) = lVar5;
      param_6 = param_6 - param_2;
      *(longlong *)((longlong)local_148 + uVar3 + 8) = lVar1;
      lVar5 = lVar5 + 1;
      uVar3 = uVar3 + 0x10;
      if (param_6 < param_2) break;
    } while (uVar3 < 0x100);
    SymCryptAesEcbEncryptAsm(puVar2,(longlong)local_148,(undefined4 *)local_148,uVar3);
    uVar4 = 0;
    if (uVar3 != 0) {
      do {
        SymCryptXtsEncryptDataUnit
                  (puVar2,param_1,(ulonglong *)((longlong)local_148 + uVar4),param_4,param_5,param_2
                  );
        param_4 = (ulonglong *)((longlong)param_4 + param_2);
        param_5 = param_5 + param_2;
        uVar4 = uVar4 + 0x10;
      } while (uVar4 < uVar3);
    }
  } while( true );
}



===== SymCryptXtsAesEncryptInternalXmm @ 180010f80 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptXtsAesEncryptInternalXmm
               (uint *param_1,ulonglong param_2,longlong *param_3,ulonglong *param_4,
               undefined1 (*param_5) [16],ulonglong param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined1 auStackY_288 [32];
  uint local_248 [2];
  longlong alStack_240 [63];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_288;
  lVar1 = param_3[1];
  lVar4 = *param_3;
  do {
    if (param_6 < param_2) {
      SymCryptWipeAsm((undefined8 *)local_248,0x200);
      return;
    }
    uVar2 = 0;
    do {
      *(longlong *)((longlong)local_248 + uVar2) = lVar4;
      param_6 = param_6 - param_2;
      *(longlong *)((longlong)alStack_240 + uVar2) = lVar1;
      lVar4 = lVar4 + 1;
      uVar2 = uVar2 + 0x10;
      if (param_6 < param_2) break;
    } while (uVar2 < 0x100);
    SymCryptAesEcbEncryptXmm(param_1 + 0x7c,local_248,(undefined1 (*) [16])local_248,uVar2);
    uVar3 = 0;
    if (uVar2 != 0) {
      do {
        SymCryptXtsAesEncryptDataUnitXmm
                  (param_1,(uint *)((longlong)local_248 + uVar3),(ulonglong *)(alStack_240 + 0x1f),
                   param_4,param_5,param_2);
        param_4 = (ulonglong *)((longlong)param_4 + param_2);
        param_5 = (undefined1 (*) [16])(*param_5 + param_2);
        uVar3 = uVar3 + 0x10;
      } while (uVar3 < uVar2);
    }
  } while( true );
}



===== SymCryptXtsAesEncryptInternalYmm @ 1800110b4 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptXtsAesEncryptInternalYmm
               (uint *param_1,ulonglong param_2,longlong *param_3,ulonglong *param_4,
               undefined1 (*param_5) [16],ulonglong param_6)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  undefined1 auStackY_288 [32];
  uint local_248 [2];
  longlong alStack_240 [63];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_288;
  lVar1 = param_3[1];
  lVar4 = *param_3;
  do {
    if (param_6 < param_2) {
      SymCryptWipeAsm((undefined8 *)local_248,0x200);
      return;
    }
    uVar2 = 0;
    do {
      *(longlong *)((longlong)local_248 + uVar2) = lVar4;
      param_6 = param_6 - param_2;
      *(longlong *)((longlong)alStack_240 + uVar2) = lVar1;
      lVar4 = lVar4 + 1;
      uVar2 = uVar2 + 0x10;
      if (param_6 < param_2) break;
    } while (uVar2 < 0x100);
    SymCryptAesEcbEncryptXmm(param_1 + 0x7c,local_248,(undefined1 (*) [16])local_248,uVar2);
    uVar3 = 0;
    if (uVar2 != 0) {
      do {
        SymCryptXtsAesEncryptDataUnitYmm_2048
                  (param_1,(undefined1 (*) [16])((longlong)local_248 + uVar3),
                   (ulonglong *)(alStack_240 + 0x1f),param_4,param_5,param_2);
        param_4 = (ulonglong *)((longlong)param_4 + param_2);
        param_5 = (undefined1 (*) [16])(*param_5 + param_2);
        uVar3 = uVar3 + 0x10;
      } while (uVar3 < uVar2);
    }
  } while( true );
}



===== SymCryptXtsDecryptDataUnit @ 1800111e8 =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptXtsDecryptDataUnit
               (undefined8 param_1,longlong param_2,ulonglong *param_3,ulonglong *param_4,
               longlong param_5,ulonglong param_6)

{
  ulonglong uVar1;
  ulonglong *puVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  undefined1 auStack_a8 [32];
  longlong local_88;
  longlong local_80;
  longlong local_78;
  ulonglong local_70 [4];
  ulonglong local_50;
  ulonglong uStack_48;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar6 = 2;
  local_80 = param_2;
  if (0x1f < param_6) {
    local_88 = param_5;
    uVar4 = param_6 - 0x10 >> 4;
    local_78 = (longlong)local_70 - (longlong)param_3;
    param_6 = param_6 + uVar4 * -0x10;
    lVar5 = (longlong)param_4 - (longlong)param_3;
    param_4 = param_4 + uVar4 * 2;
    param_5 = param_5 + uVar4 * 0x10;
    do {
      lVar3 = 2;
      puVar2 = param_3;
      do {
        *(ulonglong *)(local_78 + (longlong)puVar2) =
             *(ulonglong *)((longlong)puVar2 + lVar5) ^ *puVar2;
        puVar2 = puVar2 + 1;
        lVar3 = lVar3 + -1;
      } while (lVar3 != 0);
      SymCryptAesDecryptAsm(param_2,(longlong)local_70,(undefined4 *)local_70);
      lVar3 = 0;
      do {
        *(ulonglong *)(local_88 + lVar3 * 8) = local_70[lVar3] ^ param_3[lVar3];
        lVar3 = lVar3 + 1;
      } while (lVar3 < 2);
      local_88 = local_88 + 0x10;
      uVar1 = *param_3;
      lVar5 = lVar5 + 0x10;
      *param_3 = (ulonglong)((uint)((longlong)param_3[1] >> 0x3f) & 0x87) ^ uVar1 * 2;
      param_3[1] = uVar1 >> 0x3f | param_3[1] * 2;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  lVar5 = local_80;
  if (0x10 < param_6) {
    uVar4 = *param_3;
    local_50 = *param_3;
    uStack_48 = param_3[1];
    *param_3 = (ulonglong)((uint)((longlong)param_3[1] >> 0x3f) & 0x87) ^ uVar4 * 2;
    param_3[1] = param_3[1] * 2 | uVar4 >> 0x3f;
    lVar3 = 2;
    puVar2 = param_3;
    do {
      *(ulonglong *)((longlong)puVar2 + ((longlong)local_70 - (longlong)param_3)) =
           *(ulonglong *)((longlong)puVar2 + ((longlong)param_4 - (longlong)param_3)) ^ *puVar2;
      puVar2 = puVar2 + 1;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    SymCryptAesDecryptAsm(local_80,(longlong)local_70,(undefined4 *)local_70);
    lVar3 = 0;
    do {
      local_70[lVar3] = local_70[lVar3] ^ param_3[lVar3];
      lVar3 = lVar3 + 1;
    } while (lVar3 < 2);
    local_70[2] = local_70[0];
    local_70[3] = local_70[1];
    memmove(local_70,param_4 + 2,param_6 - 0x10);
    memmove((void *)(param_5 + 0x10),local_70 + 2,param_6 - 0x10);
    param_4 = local_70;
    param_3 = &local_50;
  }
  lVar3 = 2;
  puVar2 = param_3;
  do {
    *(ulonglong *)((longlong)puVar2 + ((longlong)local_70 - (longlong)param_3)) =
         *(ulonglong *)((longlong)puVar2 + ((longlong)param_4 - (longlong)param_3)) ^ *puVar2;
    puVar2 = puVar2 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  SymCryptAesDecryptAsm(lVar5,(longlong)local_70,(undefined4 *)local_70);
  lVar5 = (longlong)local_70 - (longlong)param_3;
  lVar3 = param_5 - (longlong)param_3;
  do {
    *(ulonglong *)(lVar3 + (longlong)param_3) = *(ulonglong *)((longlong)param_3 + lVar5) ^ *param_3
    ;
    param_3 = param_3 + 1;
    lVar6 = lVar6 + -1;
  } while (lVar6 != 0);
  return;
}



===== SymCryptXtsEncryptDataUnit @ 18001145c =====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void SymCryptXtsEncryptDataUnit
               (undefined8 param_1,uint *param_2,ulonglong *param_3,ulonglong *param_4,
               longlong param_5,ulonglong param_6)

{
  ulonglong uVar1;
  uint *puVar2;
  longlong lVar3;
  ulonglong *puVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  undefined1 auStack_a8 [32];
  longlong local_88;
  uint *local_80;
  longlong local_78;
  longlong local_70;
  ulonglong local_68 [4];
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStack_a8;
  lVar5 = 2;
  local_80 = param_2;
  if (0x1f < param_6) {
    local_88 = param_5;
    uVar7 = param_6 - 0x10 >> 4;
    lVar3 = (longlong)param_4 - (longlong)param_3;
    param_6 = param_6 + uVar7 * -0x10;
    param_4 = param_4 + uVar7 * 2;
    local_70 = param_5 + uVar7 * 0x10;
    local_78 = lVar3;
    do {
      lVar6 = 2;
      puVar4 = param_3;
      do {
        *(ulonglong *)(((longlong)local_68 - (longlong)param_3) + (longlong)puVar4) =
             *(ulonglong *)((longlong)puVar4 + lVar3) ^ *puVar4;
        puVar4 = puVar4 + 1;
        lVar6 = lVar6 + -1;
      } while (lVar6 != 0);
      SymCryptAesEncryptAsm(param_2,(longlong)local_68,(undefined4 *)local_68);
      lVar6 = 0;
      do {
        *(ulonglong *)(local_88 + lVar6 * 8) = local_68[lVar6] ^ param_3[lVar6];
        lVar6 = lVar6 + 1;
      } while (lVar6 < 2);
      local_88 = local_88 + 0x10;
      uVar1 = *param_3;
      lVar3 = lVar3 + 0x10;
      *param_3 = (ulonglong)((uint)((longlong)param_3[1] >> 0x3f) & 0x87) ^ uVar1 * 2;
      param_3[1] = uVar1 >> 0x3f | param_3[1] * 2;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
    param_5 = local_70;
  }
  puVar2 = local_80;
  if (0x10 < param_6) {
    lVar3 = 2;
    puVar4 = param_3;
    do {
      *(ulonglong *)(((longlong)local_68 - (longlong)param_3) + (longlong)puVar4) =
           *(ulonglong *)((longlong)puVar4 + ((longlong)param_4 - (longlong)param_3)) ^ *puVar4;
      puVar4 = puVar4 + 1;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
    SymCryptAesEncryptAsm(local_80,(longlong)local_68,(undefined4 *)local_68);
    lVar3 = 0;
    do {
      local_68[lVar3] = local_68[lVar3] ^ param_3[lVar3];
      lVar3 = lVar3 + 1;
    } while (lVar3 < 2);
    local_68[2] = local_68[0];
    local_68[3] = local_68[1];
    memmove(local_68,param_4 + 2,param_6 - 0x10);
    memmove((void *)(param_5 + 0x10),local_68 + 2,param_6 - 0x10);
    param_4 = local_68;
    uVar7 = *param_3;
    *param_3 = (ulonglong)((uint)((longlong)param_3[1] >> 0x3f) & 0x87) ^ uVar7 * 2;
    param_3[1] = uVar7 >> 0x3f | param_3[1] * 2;
  }
  lVar3 = 2;
  puVar4 = param_3;
  do {
    *(ulonglong *)((longlong)puVar4 + ((longlong)local_68 - (longlong)param_3)) =
         *(ulonglong *)((longlong)puVar4 + ((longlong)param_4 - (longlong)param_3)) ^ *puVar4;
    puVar4 = puVar4 + 1;
    lVar3 = lVar3 + -1;
  } while (lVar3 != 0);
  SymCryptAesEncryptAsm(puVar2,(longlong)local_68,(undefined4 *)local_68);
  lVar3 = (longlong)local_68 - (longlong)param_3;
  lVar6 = param_5 - (longlong)param_3;
  do {
    *(ulonglong *)(lVar6 + (longlong)param_3) = *(ulonglong *)((longlong)param_3 + lVar3) ^ *param_3
    ;
    param_3 = param_3 + 1;
    lVar5 = lVar5 + -1;
  } while (lVar5 != 0);
  return;
}



===== SymCryptSha256StateCopy @ 1800116c0 =====

void SymCryptSha256StateCopy(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_1[1];
  *param_2 = *param_1;
  param_2[1] = uVar1;
  uVar1 = param_1[3];
  param_2[2] = param_1[2];
  param_2[3] = uVar1;
  uVar1 = param_1[5];
  param_2[4] = param_1[4];
  param_2[5] = uVar1;
  uVar1 = param_1[7];
  param_2[6] = param_1[6];
  param_2[7] = uVar1;
  uVar1 = param_1[9];
  param_2[8] = param_1[8];
  param_2[9] = uVar1;
  uVar1 = param_1[0xb];
  param_2[10] = param_1[10];
  param_2[0xb] = uVar1;
  uVar1 = param_1[0xd];
  param_2[0xc] = param_1[0xc];
  param_2[0xd] = uVar1;
  uVar1 = param_1[0xf];
  param_2[0xe] = param_1[0xe];
  param_2[0xf] = uVar1;
  return;
}



===== SymCryptAesCbcEncrypt @ 180011708 =====

void SymCryptAesCbcEncrypt
               (uint *param_1,undefined1 (*param_2) [16],uint *param_3,undefined1 (*param_4) [16],
               ulonglong param_5)

{
  if ((g_SymCryptCpuFeaturesNotPresent & 6) == 0) {
    SymCryptAesCbcEncryptXmm(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    SymCryptAesCbcEncryptAsm
              (param_1,(undefined4 *)param_2,(ulonglong)param_3,(undefined4 *)param_4,param_5);
  }
  return;
}



===== SymCryptAesDecrypt @ 180011738 =====

void SymCryptAesDecrypt(longlong param_1,uint *param_2,undefined1 (*param_3) [16])

{
  undefined1 (*pauVar1) [16];
  undefined1 auVar2 [16];
  uint *puVar3;
  undefined1 (*pauVar4) [16];
  undefined1 auVar5 [16];
  
  if ((g_SymCryptCpuFeaturesNotPresent & 6) == 0) {
    puVar3 = *(uint **)(param_1 + 0x1d0);
    pauVar4 = (undefined1 (*) [16])(puVar3 + 8);
    auVar5._0_4_ = *param_2 ^ *puVar3;
    auVar5._4_4_ = param_2[1] ^ puVar3[1];
    auVar5._8_4_ = param_2[2] ^ puVar3[2];
    auVar5._12_4_ = param_2[3] ^ puVar3[3];
    auVar5 = aesdec(auVar5,*(undefined1 (*) [16])(puVar3 + 4));
    do {
      auVar2 = *pauVar4;
      pauVar1 = pauVar4 + 1;
      pauVar4 = pauVar4 + 2;
      auVar5 = aesdec(auVar5,auVar2);
      auVar5 = aesdec(auVar5,*pauVar1);
    } while (pauVar4 < *(undefined1 (**) [16])(param_1 + 0x1d8));
    auVar5 = aesdeclast(auVar5,*pauVar4);
    *param_3 = auVar5;
  }
  else {
    SymCryptAesDecryptAsm(param_1,(longlong)param_2,(undefined4 *)param_3);
  }
  return;
}



===== SymCryptEqual @ 1800117ac =====

bool SymCryptEqual(uint *param_1,uint *param_2,ulonglong param_3)

{
  byte *pbVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  byte bVar5;
  ulonglong uVar6;
  
  uVar4 = 0;
  if (3 < param_3) {
    uVar6 = param_3 >> 2;
    param_3 = param_3 + uVar6 * -4;
    do {
      uVar2 = *param_2;
      param_2 = param_2 + 1;
      uVar4 = uVar4 | uVar2 ^ *param_1;
      param_1 = param_1 + 1;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  if (param_3 != 0) {
    bVar5 = 0;
    lVar3 = (longlong)param_2 - (longlong)param_1;
    do {
      pbVar1 = (byte *)(lVar3 + (longlong)param_1);
      uVar2 = *param_1;
      param_1 = (uint *)((longlong)param_1 + 1);
      bVar5 = bVar5 | *pbVar1 ^ (byte)uVar2;
      param_3 = param_3 - 1;
    } while (param_3 != 0);
    uVar4 = uVar4 | bVar5;
  }
  return uVar4 == 0;
}



===== SymCryptXtsAesDecryptDataUnitYmm_2048 @ 180011814 =====

/* WARNING: Control flow encountered bad instruction data */

void SymCryptXtsAesDecryptDataUnitYmm_2048
               (longlong param_1,undefined1 (*param_2) [16],uint *param_3,uint *param_4,
               undefined1 (*param_5) [16],ulonglong param_6)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [32];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  
  lVar2 = 0x100;
  if (0xe < (param_6 & 0xff) - 1) {
    lVar2 = 0;
  }
  uVar1 = (param_6 & 0xff) + lVar2;
  if (param_6 != uVar1) {
    auVar4 = *param_2;
    auVar7 = vpsrld_avx(auVar4,0x1c);
    auVar8 = vpslldq_avx(auVar7,4);
    auVar6 = vpsrldq_avx(auVar7,0xc);
    auVar7 = vpslld_avx(auVar6,2);
    auVar5 = vpslld_avx(auVar6,1);
    auVar10 = vpslld_avx(auVar6,7);
    auVar3 = vpslld_avx(auVar4,4);
    auVar11._0_4_ =
         auVar10._0_4_ ^ auVar7._0_4_ ^ auVar5._0_4_ ^ auVar6._0_4_ ^ auVar8._0_4_ ^ auVar3._0_4_;
    auVar11._4_4_ =
         auVar10._4_4_ ^ auVar7._4_4_ ^ auVar5._4_4_ ^ auVar6._4_4_ ^ auVar8._4_4_ ^ auVar3._4_4_;
    auVar11._8_4_ =
         auVar10._8_4_ ^ auVar7._8_4_ ^ auVar5._8_4_ ^ auVar6._8_4_ ^ auVar8._8_4_ ^ auVar3._8_4_;
    auVar11._12_4_ =
         auVar10._12_4_ ^ auVar7._12_4_ ^ auVar5._12_4_ ^ auVar6._12_4_ ^
         auVar8._12_4_ ^ auVar3._12_4_;
    auVar7 = vpsrad_avx(auVar4,0x1f);
    auVar7 = vpshufd_avx(auVar7,0x93);
    auVar3 = vpslld_avx(auVar4,1);
    auVar5._0_4_ = auVar7._0_4_ & 0x87 ^ auVar3._0_4_;
    auVar5._4_4_ = auVar7._4_4_ & 1 ^ auVar3._4_4_;
    auVar5._8_4_ = auVar7._8_4_ & 1 ^ auVar3._8_4_;
    auVar5._12_4_ = auVar7._12_4_ & 1 ^ auVar3._12_4_;
    auVar7 = vpsrad_avx(auVar11,0x1f);
    auVar7 = vpshufd_avx(auVar7,0x93);
    auVar3 = vpslld_avx(auVar11,1);
    auVar10._0_4_ = auVar7._0_4_ & 0x87 ^ auVar3._0_4_;
    auVar10._4_4_ = auVar7._4_4_ & 1 ^ auVar3._4_4_;
    auVar10._8_4_ = auVar7._8_4_ & 1 ^ auVar3._8_4_;
    auVar10._12_4_ = auVar7._12_4_ & 1 ^ auVar3._12_4_;
    auVar7 = vpsrad_avx(auVar5,0x1f);
    auVar7 = vpshufd_avx(auVar7,0x93);
    auVar3 = vpslld_avx(auVar5,1);
    auVar6._0_4_ = auVar7._0_4_ & 0x87 ^ auVar3._0_4_;
    auVar6._4_4_ = auVar7._4_4_ & 1 ^ auVar3._4_4_;
    auVar6._8_4_ = auVar7._8_4_ & 1 ^ auVar3._8_4_;
    auVar6._12_4_ = auVar7._12_4_ & 1 ^ auVar3._12_4_;
    auVar7 = vpsrad_avx(auVar10,0x1f);
    auVar7 = vpshufd_avx(auVar7,0x93);
    auVar3 = vpslld_avx(auVar10,1);
    auVar8._0_4_ = auVar7._0_4_ & 0x87 ^ auVar3._0_4_;
    auVar8._4_4_ = auVar7._4_4_ & 1 ^ auVar3._4_4_;
    auVar8._8_4_ = auVar7._8_4_ & 1 ^ auVar3._8_4_;
    auVar8._12_4_ = auVar7._12_4_ & 1 ^ auVar3._12_4_;
    auVar9._16_16_ = auVar5;
    auVar9._0_16_ = auVar4;
    auVar4 = vpsrad_avx(auVar6,0x1f);
    vpshufd_avx(auVar4,0x93);
    vpslld_avx(auVar6,1);
    auVar4 = vpsrad_avx(auVar8,0x1f);
    vpshufd_avx(auVar4,0x93);
    vpslld_avx(auVar8,1);
    vpsrldq_avx2(auVar9,0xf);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  SymCryptXtsAesDecryptDataUnitXmm(param_1,(uint *)param_2,param_3,param_4,param_5,uVar1);
  return;
}



===== SymCryptXtsAesEncryptDataUnitYmm_2048 @ 180011d7c =====

/* WARNING: Control flow encountered bad instruction data */

void SymCryptXtsAesEncryptDataUnitYmm_2048
               (uint *param_1,undefined1 (*param_2) [16],ulonglong *param_3,ulonglong *param_4,
               undefined1 (*param_5) [16],ulonglong param_6)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  undefined1 auVar9 [32];
  undefined1 auVar10 [16];
  undefined1 auVar11 [16];
  
  lVar2 = 0x100;
  if (0xe < (param_6 & 0xff) - 1) {
    lVar2 = 0;
  }
  uVar1 = (param_6 & 0xff) + lVar2;
  if (param_6 != uVar1) {
    auVar4 = *param_2;
    auVar7 = vpsrld_avx(auVar4,0x1c);
    auVar8 = vpslldq_avx(auVar7,4);
    auVar6 = vpsrldq_avx(auVar7,0xc);
    auVar7 = vpslld_avx(auVar6,2);
    auVar5 = vpslld_avx(auVar6,1);
    auVar10 = vpslld_avx(auVar6,7);
    auVar3 = vpslld_avx(auVar4,4);
    auVar11._0_4_ =
         auVar10._0_4_ ^ auVar7._0_4_ ^ auVar5._0_4_ ^ auVar6._0_4_ ^ auVar8._0_4_ ^ auVar3._0_4_;
    auVar11._4_4_ =
         auVar10._4_4_ ^ auVar7._4_4_ ^ auVar5._4_4_ ^ auVar6._4_4_ ^ auVar8._4_4_ ^ auVar3._4_4_;
    auVar11._8_4_ =
         auVar10._8_4_ ^ auVar7._8_4_ ^ auVar5._8_4_ ^ auVar6._8_4_ ^ auVar8._8_4_ ^ auVar3._8_4_;
    auVar11._12_4_ =
         auVar10._12_4_ ^ auVar7._12_4_ ^ auVar5._12_4_ ^ auVar6._12_4_ ^
         auVar8._12_4_ ^ auVar3._12_4_;
    auVar7 = vpsrad_avx(auVar4,0x1f);
    auVar7 = vpshufd_avx(auVar7,0x93);
    auVar3 = vpslld_avx(auVar4,1);
    auVar5._0_4_ = auVar7._0_4_ & 0x87 ^ auVar3._0_4_;
    auVar5._4_4_ = auVar7._4_4_ & 1 ^ auVar3._4_4_;
    auVar5._8_4_ = auVar7._8_4_ & 1 ^ auVar3._8_4_;
    auVar5._12_4_ = auVar7._12_4_ & 1 ^ auVar3._12_4_;
    auVar7 = vpsrad_avx(auVar11,0x1f);
    auVar7 = vpshufd_avx(auVar7,0x93);
    auVar3 = vpslld_avx(auVar11,1);
    auVar10._0_4_ = auVar7._0_4_ & 0x87 ^ auVar3._0_4_;
    auVar10._4_4_ = auVar7._4_4_ & 1 ^ auVar3._4_4_;
    auVar10._8_4_ = auVar7._8_4_ & 1 ^ auVar3._8_4_;
    auVar10._12_4_ = auVar7._12_4_ & 1 ^ auVar3._12_4_;
    auVar7 = vpsrad_avx(auVar5,0x1f);
    auVar7 = vpshufd_avx(auVar7,0x93);
    auVar3 = vpslld_avx(auVar5,1);
    auVar6._0_4_ = auVar7._0_4_ & 0x87 ^ auVar3._0_4_;
    auVar6._4_4_ = auVar7._4_4_ & 1 ^ auVar3._4_4_;
    auVar6._8_4_ = auVar7._8_4_ & 1 ^ auVar3._8_4_;
    auVar6._12_4_ = auVar7._12_4_ & 1 ^ auVar3._12_4_;
    auVar7 = vpsrad_avx(auVar10,0x1f);
    auVar7 = vpshufd_avx(auVar7,0x93);
    auVar3 = vpslld_avx(auVar10,1);
    auVar8._0_4_ = auVar7._0_4_ & 0x87 ^ auVar3._0_4_;
    auVar8._4_4_ = auVar7._4_4_ & 1 ^ auVar3._4_4_;
    auVar8._8_4_ = auVar7._8_4_ & 1 ^ auVar3._8_4_;
    auVar8._12_4_ = auVar7._12_4_ & 1 ^ auVar3._12_4_;
    auVar9._16_16_ = auVar5;
    auVar9._0_16_ = auVar4;
    auVar4 = vpsrad_avx(auVar6,0x1f);
    vpshufd_avx(auVar4,0x93);
    vpslld_avx(auVar6,1);
    auVar4 = vpsrad_avx(auVar8,0x1f);
    vpshufd_avx(auVar4,0x93);
    vpslld_avx(auVar8,1);
    vpsrldq_avx2(auVar9,0xf);
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  SymCryptXtsAesEncryptDataUnitXmm(param_1,(uint *)param_2,param_3,param_4,param_5,uVar1);
  return;
}



===== SymCryptAesEcbEncryptAsm @ 1800122e8 =====

void SymCryptAesEcbEncryptAsm(uint *param_1,longlong param_2,undefined4 *param_3,ulonglong param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  
  if (0xf < param_4) {
    lVar1 = param_2 - (longlong)param_3;
    uVar2 = param_4 >> 4;
    do {
      SymCryptAesEncryptAsm(param_1,lVar1 + (longlong)param_3,param_3);
      param_3 = param_3 + 4;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}



===== _guard_check_icall @ 180012360 =====

void _guard_check_icall(void)

{
  return;
}



===== __GSHandlerCheck @ 180012378 =====

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



===== __GSHandlerCheckCommon @ 18001239c =====

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



===== __chkstk @ 180012402 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void __chkstk(void)

{
                    /* WARNING: Could not recover jumptable at 0x000180012402. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  return;
}



===== __cpu_features_init @ 180012420 =====

/* WARNING: Removing unreachable block (ram,0x00018001248a) */
/* WARNING: Removing unreachable block (ram,0x000180012439) */
/* WARNING: Removing unreachable block (ram,0x00018001242a) */

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



===== __security_check_cookie @ 1800124f0 =====

/* WARNING: This is an inlined function */

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie != __security_cookie) || ((short)(_StackCookie >> 0x30) != 0)) {
                    /* WARNING: Subroutine does not return */
    __report_gsfailure(_StackCookie);
  }
  return;
}



===== _guard_dispatch_icall @ 180012530 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_dispatch_icall(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== _guard_dispatch_icall @ 180012560 =====

/* WARNING: This is an inlined function */

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    /* WARNING: Could not recover jumptable at 0x000180012560. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



===== _guard_xfg_dispatch_icall_nop @ 180012590 =====

/* WARNING: This is an inlined function */
/* WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall */

void _guard_xfg_dispatch_icall_nop(void)

{
  code *in_RAX;
  
  (*in_RAX)();
  return;
}



===== memcmp @ 1800125e0 =====

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
      if ((byte)*(ulonglong *)_Buf1 != *(byte *)((longlong)_Buf1 + lVar3)) goto LAB_180012623;
      _Size = _Size - 1;
    }
    if (_Size >> 3 != 0) {
      uVar4 = _Size >> 5;
      if (uVar4 != 0) {
        do {
          uVar2 = *(ulonglong *)_Buf1;
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3)) goto LAB_180012694;
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 8);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 8)) {
LAB_180012690:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_180012694;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x10);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x10)) {
LAB_18001268c:
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_180012690;
          }
          uVar2 = *(ulonglong *)((longlong)_Buf1 + 0x18);
          if (uVar2 != *(ulonglong *)((longlong)_Buf1 + lVar3 + 0x18)) {
            _Buf1 = (void *)((longlong)_Buf1 + 8);
            goto LAB_18001268c;
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
LAB_180012694:
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
LAB_180012623:
  return (1 - (uint)bVar5) - (uint)(bVar5 != 0);
}



===== memmove @ 180012700 =====

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



===== memset @ 180012a00 =====

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



===== __memset_repmovs @ 180012b40 =====

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



===== __memset_query @ 180012bc0 =====

undefined8 __memset_query(void)

{
  undefined8 in_RAX;
  
  __cpu_features_init();
  return in_RAX;
}



===== __memset_spec_ermsb @ 180012c40 =====

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



===== __memset_spec_ermsb_repmovsb @ 180012d80 =====

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



===== __memset_spec_plain @ 180012e00 =====

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



===== wil_details_EvaluateFeatureDependencies @ 18001d008 =====

void wil_details_EvaluateFeatureDependencies(void)

{
  longlong *plVar1;
  undefined **ppuVar2;
  
  wil_details_EvaluateFeatureDependencies_UpdateFeatureDesiredStates();
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



===== wil_details_EvaluateFeatureDependencies_UpdateFeatureDesiredStates @ 18001d048 =====

void wil_details_EvaluateFeatureDependencies_UpdateFeatureDesiredStates(void)

{
  longlong *plVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  bool bVar5;
  
  plVar1 = wil_details_FeatureDescriptors_SkipPadding((longlong *)&wil_details_featureDescriptors_a)
  ;
  if (plVar1 != (longlong *)0x0) {
    uVar3 = 0;
    uVar4 = 0x180;
    do {
      uVar2 = *(uint *)*plVar1;
      if ((uVar2 >> 9 & 1) != 0) {
        if (((uint)uVar4 & uVar2) == 0) {
          bVar5 = *(char *)((longlong)plVar1 + 0x1f) != '\0';
        }
        else {
          bVar5 = (uVar2 & (uint)uVar4) == 0x100;
        }
        uVar2 = uVar2 & 0x40 ^ (uint)bVar5 << 6 | (uint)uVar3 & 0xffffffbf;
        uVar3 = (ulonglong)uVar2;
        LOCK();
        *(uint *)*plVar1 = *(uint *)*plVar1 ^ uVar2;
        UNLOCK();
      }
      plVar1 = wil_details_FeatureDescriptors_SkipPadding(plVar1 + 7);
    } while (plVar1 != (longlong *)0x0);
  }
  return;
}



===== DumpGetKsrAllowedForVolume @ 18001d0d8 =====

int DumpGetKsrAllowedForVolume(longlong param_1,ulonglong param_2,undefined1 *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  ulonglong local_res10;
  
  iVar2 = 0;
  *param_3 = 0;
  local_res10 = param_2 & 0xffffffff00000000;
  iVar1 = DumpGroupPolicyGetDWordValue(param_1,param_2,(undefined4 *)&local_res10,param_4);
  if (iVar1 == -0x3fffffcc) {
    if ((*(uint *)(param_1 + 0xc) & 0x10) != 0) goto LAB_18001d123;
  }
  else {
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar2 = (int)local_res10;
  }
  if (1 < iVar2 - 1U) {
    return 0;
  }
LAB_18001d123:
  *param_3 = 1;
  return 0;
}



===== DumpGetRegistryValue @ 18001d140 =====

int DumpGetRegistryValue
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,void *param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  longlong lVar3;
  longlong local_res8;
  undefined4 local_res18 [2];
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  undefined8 uStack_20;
  
  local_2c = 0;
  local_res18[0] = 0;
  local_res8 = 0;
  local_40 = 0;
  local_48 = 0x30;
  local_28 = 0;
  uStack_20 = 0;
  local_30 = 0x240;
  local_38 = param_1;
  iVar2 = ZwOpenKey(&local_res8,0x20019,&local_48);
  if (-1 < iVar2) {
    iVar2 = ZwQueryValueKey(local_res8,param_2,2,0,0,local_res18);
    if (((iVar2 + 0x80000000U & 0x80000000) != 0) || (iVar2 == -0x3fffffdd)) {
      lVar3 = ExAllocatePool2(0x100,local_res18[0],0x45564664);
      if (lVar3 == 0) {
        iVar2 = -0x3fffff66;
      }
      else {
        iVar2 = ZwQueryValueKey(local_res8,param_2,2,lVar3,local_res18[0],local_res18);
        if (-1 < iVar2) {
          if (*(int *)(lVar3 + 4) == 4) {
            if ((param_4 == (void *)0x0) || (uVar1 = *(uint *)(lVar3 + 8), *param_5 < uVar1)) {
              iVar2 = -0x3fffffdd;
              *param_5 = *(uint *)(lVar3 + 8);
            }
            else {
              *param_5 = uVar1;
              memmove(param_4,(void *)(lVar3 + 0xc),(ulonglong)uVar1);
              iVar2 = 0;
            }
          }
          else {
            iVar2 = -0x3fffffdc;
          }
        }
        ExFreePoolWithTag(lVar3,0x45564664);
      }
    }
  }
  if (local_res8 != 0) {
    ZwClose();
  }
  return iVar2;
}



===== DumpGroupPolicyGetDWordValue @ 18001d2d8 =====

int DumpGroupPolicyGetDWordValue
              (undefined8 param_1,undefined8 param_2,undefined4 *param_3,uint param_4)

{
  int iVar1;
  undefined8 uVar2;
  uint local_res20 [2];
  undefined8 local_28;
  void *local_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
  local_28 = 0;
  local_18 = 0;
  uStack_10 = 0;
  local_res20[0] = param_4;
  local_20 = (void *)ExAllocatePool2(0x100,0x400,0x45564664);
  if (local_20 == (void *)0x0) {
    iVar1 = -0x3fffff66;
  }
  else {
    uVar2 = 0x400;
    memset(local_20,0,0x400);
    local_28._0_4_ = CONCAT22(0x400,(undefined2)local_28);
    iVar1 = RtlAppendUnicodeToString(&local_28,L"\\Registry\\Machine\\");
    if ((-1 < iVar1) &&
       (iVar1 = RtlAppendUnicodeToString
                          (&local_28,L"System\\CurrentControlSet\\Policies\\Microsoft\\FVE"),
       -1 < iVar1)) {
      RtlInitUnicodeString(&local_18,L"OsvKsrAllow");
      *param_3 = 0;
      local_res20[0] = 4;
      iVar1 = DumpGetRegistryValue(&local_28,&local_18,uVar2,param_3,local_res20);
    }
  }
  if (local_20 != (void *)0x0) {
    ExFreePoolWithTag(local_20,0x45564664);
  }
  return iVar1;
}



===== DumpKsrCancel @ 18001d3ec =====

void DumpKsrCancel(longlong param_1)

{
  if (*(undefined1 **)(param_1 + 0x28) != (undefined1 *)0x0) {
    FveDmpSecureZeroAndFlush(*(undefined1 **)(param_1 + 0x28),0x88);
    KsrFreePersistedMemory(&DAT_180015bc8,0);
  }
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffc7;
  return;
}



===== DumpKsrFinalize @ 18001d430 =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DumpKsrFinalize(longlong param_1,ulonglong param_2,undefined8 param_3,uint param_4)

{
  uint *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  int iVar4;
  char local_res8 [32];
  
  iVar4 = 0;
  local_res8[0] = '\0';
  if (*(longlong *)(param_1 + 0xe0) == 0) {
    iVar4 = -0x3fffff45;
  }
  else if ((((*(uint *)(param_1 + 0xc) & 0x20) == 0) && (*(int **)(param_1 + 0x28) != (int *)0x0))
          && (**(int **)(param_1 + 0x28) == 0x6b564644)) {
    if ((*(uint *)(param_1 + 0xc) & 8) == 0) {
      iVar4 = DumpGetKsrAllowedForVolume(param_1,param_2,local_res8,param_4);
      if (iVar4 < 0) {
        return iVar4;
      }
      if (local_res8[0] != '\0') {
        *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 8;
      }
    }
    *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x28) = *(undefined8 *)(param_1 + 0xb0);
    *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x20) = *(undefined8 *)(param_1 + 0xa8);
    *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x30) = **(undefined8 **)(param_1 + 0xe0);
    if ((*(longlong *)(param_1 + 0xd8) != 0) ||
       ((*(ulonglong *)(param_1 + 0x50) != 0 &&
        (*(ulonglong *)(param_1 + 0x50) < **(ulonglong **)(param_1 + 0xe0))))) {
      puVar1 = (uint *)(*(longlong *)(param_1 + 0x28) + 0xc);
      *puVar1 = *puVar1 | 4;
    }
    if (*(int *)(param_1 + 0x40) != 0) {
      if ((*(uint *)(param_1 + 0xc) & 8) == 0) {
        return -0x3fdeffc0;
      }
      puVar1 = (uint *)(*(longlong *)(param_1 + 0x28) + 0xc);
      *puVar1 = *puVar1 | 2;
      lVar2 = *(longlong *)(param_1 + 0x28);
      if ((*(uint *)(lVar2 + 0xc) & 4) == 0) {
        uVar3 = *(undefined8 *)(param_1 + 0x60);
        *(undefined8 *)(lVar2 + 0x38) = *(undefined8 *)(param_1 + 0x58);
        *(undefined8 *)(lVar2 + 0x40) = uVar3;
        uVar3 = *(undefined8 *)(param_1 + 0x70);
        *(undefined8 *)(lVar2 + 0x48) = *(undefined8 *)(param_1 + 0x68);
        *(undefined8 *)(lVar2 + 0x50) = uVar3;
        uVar3 = *(undefined8 *)(param_1 + 0x80);
        *(undefined8 *)(lVar2 + 0x58) = *(undefined8 *)(param_1 + 0x78);
        *(undefined8 *)(lVar2 + 0x60) = uVar3;
        uVar3 = *(undefined8 *)(param_1 + 0x90);
        *(undefined8 *)(lVar2 + 0x68) = *(undefined8 *)(param_1 + 0x88);
        *(undefined8 *)(lVar2 + 0x70) = uVar3;
        *(undefined8 *)(lVar2 + 0x78) = *(undefined8 *)(param_1 + 0x98);
        *(undefined4 *)(lVar2 + 0x80) = *(undefined4 *)(param_1 + 0xa0);
        *(undefined1 *)(lVar2 + 0x84) = *(undefined1 *)(param_1 + 0xa4);
      }
    }
    *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x18) = _DAT_fffff78000000014;
    puVar1 = (uint *)(*(longlong *)(param_1 + 0x28) + 0xc);
    *puVar1 = *puVar1 | 1;
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x20;
  }
  else {
    iVar4 = -0x3fffff1b;
  }
  return iVar4;
}



===== DumpKsrNotifyCallbackRoutine @ 18001d5b0 =====

void DumpKsrNotifyCallbackRoutine(longlong param_1,ulonglong param_2,int *param_3,uint param_4)

{
  int iVar1;
  
  iVar1 = (int)param_2;
  if (iVar1 == 0) {
    if ((param_3[3] & 1U) != 0) {
      *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x10;
    }
    iVar1 = DumpKsrPrepare(param_1,param_2,param_3,param_4);
LAB_18001d5fa:
    if ((iVar1 < 0) && (-1 < *param_3)) {
      param_3[2] = 0x6b564644;
      *param_3 = iVar1;
    }
  }
  else {
    if (iVar1 != 1) {
      if (iVar1 != 5) {
        if (iVar1 == 0x16) {
          DumpRecoveryPrepareShutdownHandler(param_1);
          return;
        }
        return;
      }
      if ((param_3[3] & 1U) != 0) {
        iVar1 = DumpKsrFinalize(param_1,0,param_3,param_4);
        goto LAB_18001d5fa;
      }
    }
    DumpKsrCancel(param_1);
  }
  return;
}



===== DumpKsrPrepare @ 18001d61c =====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int DumpKsrPrepare(longlong param_1,ulonglong param_2,undefined8 param_3,uint param_4)

{
  int iVar1;
  longlong lVar2;
  char local_res8 [8];
  undefined4 local_res10 [2];
  undefined8 local_res18;
  undefined8 local_res20;
  
  local_res8[0] = '\0';
  local_res10[0] = 0;
  local_res18 = 0;
  if ((*(uint *)(param_1 + 0xc) & 0x20) == 0) {
    if ((*(uint *)(param_1 + 0xc) & 8) == 0) {
      iVar1 = DumpGetKsrAllowedForVolume(param_1,param_2,local_res8,param_4);
      if (iVar1 < 0) {
        return iVar1;
      }
      if (local_res8[0] != '\0') {
        *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 8;
      }
    }
    if (*(longlong *)(param_1 + 0x28) == 0) {
      if (*(longlong *)(param_1 + 0x20) != 0) goto LAB_18001d63d;
      lVar2 = MmAllocatePagesForMdlEx(0,0xffffffffffffffff,0,0x1000,1,0x24);
      *(longlong *)(param_1 + 0x20) = lVar2;
      if (lVar2 == 0) {
        return -0x3fffff66;
      }
      lVar2 = MmMapLockedPagesSpecifyCache(lVar2,0,1,0,0,0x40000020);
      *(longlong *)(param_1 + 0x28) = lVar2;
      if (lVar2 == 0) {
        if (*(longlong *)(param_1 + 0x20) == 0) {
          return -0x3fffff66;
        }
        MmFreePagesFromMdl();
        ExFreePoolWithTag(*(undefined8 *)(param_1 + 0x20),0);
        *(undefined8 *)(param_1 + 0x20) = 0;
        return -0x3fffff66;
      }
    }
    iVar1 = KsrMdlToMemoryRuns(*(undefined8 *)(param_1 + 0x20),&local_res18,1,local_res10);
    if (-1 < iVar1) {
      local_res20 = 0;
      iVar1 = KsrPersistMemory(&DAT_180015bc8,&local_res18,local_res10[0],&local_res20);
      if (-1 < iVar1) {
        memset(*(void **)(param_1 + 0x28),0,0x88);
        **(undefined4 **)(param_1 + 0x28) = 0x6b564644;
        *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 4) = 0x88;
        *(undefined4 *)(*(longlong *)(param_1 + 0x28) + 8) = 0x88;
        *(undefined8 *)(*(longlong *)(param_1 + 0x28) + 0x10) = _DAT_fffff78000000014;
      }
    }
  }
  else {
LAB_18001d63d:
    iVar1 = -0x3fffff1b;
  }
  return iVar1;
}



===== wil_RtlStagingConfig_QueryFeatureState @ 18001d7c0 =====

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



===== wil_UninitializeFeatureStaging @ 18001d88c =====

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



===== wil_details_BuildFeatureStateCacheFromQueryResults @ 18001d8e4 =====

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
      goto LAB_18001d941;
    }
    if (param_1 == 0x117) {
      uVar1 = (*(uint *)(param_2 + 4) & 0x80) << 3 | 0x206;
      goto LAB_18001d941;
    }
  }
  uVar1 = 0x206;
LAB_18001d941:
  *param_3 = uVar1;
  return;
}



===== wil_details_EvaluateFeatureDependencies_GetCachedFeatureEnabledState @ 18001d94c =====

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



===== wil_details_EvaluateFeatureDependencies_ReevaluateCachedFeatureEnabledState @ 18001d984 =====

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
        if (puVar1 == (undefined8 *)0x0) goto LAB_18001da06;
        if ((*(char *)((longlong)puVar1 + 0x1e) == '\0') &&
           (*(char *)((longlong)puVar1 + 0x1d) == '\0')) break;
        if ((uVar5 == 0) || (*(char *)((longlong)puVar1 + 0x1f) == '\0')) {
          uVar5 = 0;
          goto LAB_18001da06;
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
LAB_18001da06:
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



===== wil_details_OnFeatureUsageProviderFlushNotification @ 18001da50 =====

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



===== wil_details_ReevaluateOnFeatureConfigurationChange @ 18001dab0 =====

void wil_details_ReevaluateOnFeatureConfigurationChange(void)

{
  wil_details_UpdateFeatureConfiguredStates();
  wil_details_EvaluateFeatureDependencies();
  return;
}



===== wil_details_UpdateFeatureConfiguredStates @ 18001dacc =====

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



===== SendDeviceIoControl @ 18001db80 =====

ulonglong SendDeviceIoControl(undefined4 param_1,undefined8 param_2,undefined8 param_3,
                             undefined8 param_4,undefined8 param_5)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong local_38 [6];
  
  local_38[4] = 0;
  local_38[0] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[1] = 0;
  KeInitializeEvent(local_38 + 2,0,0);
  lVar1 = IoBuildDeviceIoControlRequest(param_1,param_2,0,0,param_5,0x118,0,local_38 + 2,local_38);
  if (lVar1 == 0) {
    uVar2 = 0xc000009a;
  }
  else {
    uVar2 = IofCallDriver(param_2,lVar1);
    if ((int)uVar2 == 0x103) {
      KeWaitForSingleObject(local_38 + 2,0,0,0,0);
      uVar2 = local_38[0] & 0xffffffff;
    }
  }
  return uVar2;
}



===== DumpUpdateKeyMaterialCallback @ 18001e010 =====

void DumpUpdateKeyMaterialCallback(longlong param_1)

{
  if ((param_1 != 0) && (*(int **)(param_1 + 0x98) != (int *)0x0)) {
    FveInitCrypto(*(int **)(param_1 + 0x98));
  }
  return;
}



===== wil_details_PopulateInitialConfiguredFeatureStates @ 180020008 =====

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



===== entry @ 1800200f0 =====

void entry(uint *param_1,undefined4 *param_2,undefined8 param_3,uint param_4)

{
  __security_init_cookie();
  DriverEntry(param_1,param_2,param_3,param_4);
  return;
}



===== __security_init_cookie @ 180020124 =====

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



===== DumpKsrMemoryEnumerate @ 180020160 =====

undefined8 DumpKsrMemoryEnumerate(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  *param_3 = param_2;
  return 0;
}



===== GetFveContextFromKsrForEarlyCrashDump @ 180020170 =====

ulonglong GetFveContextFromKsrForEarlyCrashDump
                    (longlong param_1,longlong param_2,int param_3,byte param_4,uint *param_5,
                    longlong param_6)

{
  uint *puVar1;
  undefined8 uVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  ulonglong uVar6;
  
  if ((param_1 == 0) || (param_5 == (uint *)0x0)) {
    return 0xc000000d;
  }
  puVar1 = param_5 + 0xc;
  uVar4 = FveLibInitEx();
  uVar6 = uVar4 & 0xffffffff;
  if (-1 < (int)uVar4) {
    param_5[1] = *(uint *)(param_1 + 0x24);
    *(uint **)(param_5 + 0xe) = puVar1;
    *(uint **)puVar1 = puVar1;
    uVar4 = Feature_SteelixInlineNvmeCryptoEngine__private_IsEnabledDeviceUsageNoInline();
    if ((int)uVar4 != 0) {
      param_4 = (byte)(*(uint *)(param_2 + 0x34) >> 2) & 1;
      if ((*(uint *)(param_2 + 0x34) & 0x20) == 0) {
        uVar3 = param_5[0x30] & 0xffffffef;
      }
      else {
        uVar3 = param_5[0x30] | 0x10;
      }
      param_5[0x30] = uVar3;
    }
    param_5[0x11] = param_3 << 0xc;
    lVar5 = MmAllocateContiguousNodeMemory
                      (param_3 << 0xc,0,
                       (-(ulonglong)(param_4 != 0) & 0xffffffff00000000) + 0xffffffff,
                       -(ulonglong)(param_4 != 0) & 0x100000000,4,0x80000000);
    *(longlong *)(param_5 + 0x12) = lVar5;
    if (lVar5 == 0) {
      uVar6 = 0xc000009a;
    }
    else {
      uVar3 = *(uint *)(param_6 + 0xc);
      param_5[0x10] = (uint)((uVar3 >> 1 & 1) != 0);
      uVar2 = *(undefined8 *)(param_6 + 0x30);
      param_5[0x2e] = 0;
      param_5[0x2f] = 0;
      param_5[0x36] = 0;
      param_5[0x37] = 0;
      *(undefined8 *)(param_5 + 0x14) = uVar2;
      *(uint **)(param_5 + 0x38) = param_5 + 0x14;
      *(undefined8 *)(param_5 + 0x2a) = *(undefined8 *)(param_6 + 0x20);
      *(undefined8 *)(param_5 + 0x2c) = *(undefined8 *)(param_6 + 0x28);
      uVar2 = *(undefined8 *)(param_6 + 0x40);
      *(undefined8 *)(param_5 + 0x16) = *(undefined8 *)(param_6 + 0x38);
      *(undefined8 *)(param_5 + 0x18) = uVar2;
      uVar2 = *(undefined8 *)(param_6 + 0x50);
      *(undefined8 *)(param_5 + 0x1a) = *(undefined8 *)(param_6 + 0x48);
      *(undefined8 *)(param_5 + 0x1c) = uVar2;
      uVar2 = *(undefined8 *)(param_6 + 0x60);
      *(undefined8 *)(param_5 + 0x1e) = *(undefined8 *)(param_6 + 0x58);
      *(undefined8 *)(param_5 + 0x20) = uVar2;
      uVar2 = *(undefined8 *)(param_6 + 0x70);
      *(undefined8 *)(param_5 + 0x22) = *(undefined8 *)(param_6 + 0x68);
      *(undefined8 *)(param_5 + 0x24) = uVar2;
      *(undefined8 *)(param_5 + 0x26) = *(undefined8 *)(param_6 + 0x78);
      param_5[0x28] = *(uint *)(param_6 + 0x80);
      *(undefined1 *)(param_5 + 0x29) = *(undefined1 *)(param_6 + 0x84);
      if ((uVar3 >> 1 & 1) == 0) {
        return uVar6;
      }
      uVar4 = FveInitCrypto((int *)param_5);
      uVar6 = uVar4 & 0xffffffff;
      if (-1 < (int)uVar4) {
        return uVar6;
      }
    }
  }
  FveDmpSecureZeroAndFlush((undefined1 *)(param_5 + 0x52),0x4d);
  uVar4 = Feature_SteelixRemoveFvekFromMemory__private_IsEnabledDeviceUsageNoInline();
  if ((int)uVar4 != 0) {
    FveDmpSecureZeroAndFlush((undefined1 *)(param_5 + 0x72),0x4d);
  }
  if (0x23f < *param_5) {
    FveDmpSecureZeroAndFlush((undefined1 *)(param_5 + 0x90),*param_5 - 0x240);
  }
  if (*(undefined1 **)(param_5 + 0x12) != (undefined1 *)0x0) {
    FveDmpSecureZeroAndFlush(*(undefined1 **)(param_5 + 0x12),param_5[0x11]);
    MmFreeContiguousMemory(*(undefined8 *)(param_5 + 0x12));
  }
  FveDmpSecureZeroAndFlush((undefined1 *)puVar1,0x118);
  return uVar6;
}



===== wil_InitializeFeatureStaging @ 1800203ac =====

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


